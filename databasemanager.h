#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <qfile.h>
#include "poolmanager.h"
#include <QDateTime>
#include <QFileInfo>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent=nullptr);
    ~DatabaseManager();

    bool isValid() const {
        return m_mainConn.isOpen();
    }
    //为每个线程创建单独的数据库连接
    QSqlDatabase getThreadLocalConnection();

    /*1. 查询 users 表通用字段（单主键）
    | 字段名                | 类型       | 含义         | 备注     |
    | ------------------ | -------- | ---------- | ------ |
    | `id`               | INTEGER  | 用户唯一标识     | 主键，自增  |
    | `nickname`         | TEXT     | 昵称         | 必填     |
    | `account`          | TEXT     | 登录账号       | 唯一     |
    | `password`         | TEXT     | 密码         | 加密存储   |
    | `avatar`           | TEXT     | 头像路径       | 可为空    |
    | `status`           | INTEGER  | 状态（在线/离线等） | 默认 0   |
    | `last_online_time` | DATETIME | 最后一次在线时间   | 可为空    |
    | `signature`        | TEXT     | 个性签名       | 可为空    |
    | `gender`           | INTEGER  | 性别（0/1/2）  | 默认 0   |
    | `birth_date`       | DATE     | 生日         | 可为空    |
    | `register_time`    | DATETIME | 注册时间       | 默认当前时间 |
     */
    QVariantMap getUserInfo(int userId, const QStringList &fields);

    /*2. 查询 friends 表通用字段（联合主键：user_id + friend_id）
    | 字段名               | 类型       | 含义            | 备注            |
    | ----------------- | -------- | ------------- | ------------- |
    | `id`              | INTEGER  | 主键            | 自增主键          |
    | `user_id`         | INTEGER  | 发起者 id        | 外键 → users.id |
    | `friend_id`       | INTEGER  | 好友 id         | 外键 → users.id |
    | `relation_status` | INTEGER  | 状态（0：正常，1：拉黑） | 默认 0          |
    | `create_time`     | DATETIME | 添加时间          | 默认当前时间        |
    | `remark`          | TEXT     | 对好友的备注名       | 可为空           |
    | `group_name`      | TEXT     | 所属分组名         | 默认 “我的好友”     |
     */
    QVariantMap getFriendRelation(int userId, int friendId, const QStringList &fields);

    /*3. 查询 conversations 表通用字段（联合主键：user_id + friend_id）
    | 字段名            | 类型       | 含义           | 备注            |
    | -------------- | -------- | ------------ | ------------- |
    | `id`           | INTEGER  | 消息唯一标识       | 自增主键          |
    | `sender_id`    | INTEGER  | 发送者 id       | 外键 → users.id |
    | `receiver_id`  | INTEGER  | 接收者 id       | 外键 → users.id |
    | `content`      | TEXT     | 消息内容         | 必填            |
    | `content_type` | INTEGER  | 消息类型（文本/图片等） | 默认 0          |
    | `send_time`    | DATETIME | 发送时间         | 默认当前时间        |
    | `status`       | INTEGER  | 状态（发送中/已读等）  | 默认 0          |
    | `is_recalled`  | BOOLEAN  | 是否撤回         | 默认 false（0）   |
     */
    QVector<QVariantMap> getAllMsg(int userId, int friendId, const QStringList &fields);

    /*4. 查询 lastMessages 表中用户与好友的最后一条消息
    | 字段名                 | 类型       | 含义       | 备注            |
    | ------------------- | -------- | -------- | ------------- |
    | `id`                | INTEGER  | 主键       | 自增主键          |
    | `user_id`           | INTEGER  | 当前用户 id  | 外键 → users.id |
    | `friend_id`         | INTEGER  | 对话对象 id  | 外键 → users.id |
    | `last_message`      | TEXT     | 最后一条消息内容 | 可为空           |
    | `last_message_time` | DATETIME | 最后一条消息时间 | 可为空           |
    | `unread_count`      | INTEGER  | 未读消息数    | 默认 0          |
    | `is_pinned`         | BOOLEAN  | 是否置顶     | 默认 false（0）   |
     */
    QVariantMap getLastMsg(int userId, int friendId, const QStringList &fields);

    //AddPage用，根据account模糊搜索非好友用户
    QList<QVariantMap> searchStrangersByAccount(int userId
        , const QString &partialAccount, const QStringList &fields);

    //添加用户
    bool addUser(const QString &nickname,const QString &account,const QString &password
                    ,const QString &avatar);
    //1. 添加用户users表（详细）
    bool addUserDetails(const QString &nickname,
                        const QString &account,
                        const QString &password,
                        const QString &avatar,
                        int status,
                        const QString &lastOnlineTime,
                        const QString &signature,
                        int gender,
                        const QString &birthDate);
    //2.1 添加好友friends表(双向)
    bool addFriendBoth(int userId, int friendId);
    //2.2 删除好友friends表(双向)
    bool removeFriendBoth(int userId, int friendId);
    //3. 添加聊天记录conversations表
    bool addConversation(int senderId, int receiverId, const QString &content, int contentType,
                                    const QDateTime &sendTime, int status, bool isRecalled);
    //4. 添加/更新最后一次消息lastMessages表
    bool upsertLastMessageBoth(int userId, int friendId, const QString &lastMessage,
                                    const QDateTime &lastMessageTime, int unreadCount, bool isPinned);

    //查询这个用户对应的所有好友id
    QVector<int> getFriendIds(int userId);
    //添加用户（异步）
    void addUserAsync(const QString &nickname,
                    const QString &account,
                    const QString &password,
                    const QString &avatar,
                    std::function<void(bool)> callback);
    //删除用户
    bool deleteUser(const QString &account);
    //删除用户（异步）
    void deleteUserAsync(const QString &account,
                    std::function<void(bool)> callback);
    //检查用户存在
    bool userExists(const QString &account);
    //检查好友关系存在
    bool friendRelationExists(int userId, int friendId);
    //检查用户存在（异步）
    void userExistsAsync(const QString &account,
                    std::function<void(bool)> callback);
    //查找用户的id
    int getUserId(const QString &account);
    //查找用户的昵称
    QString getUserNickname(const QString &account);
    //查找用户的昵称（异步）
    void getUserNicknameAsync(const QString &account,
                    std::function<void(QString)> callback);
    //验证登录信息
    bool verifyLogin(const QString &account,const QString &password);
    //验证登录信息（异步）
    void verifyLoginAsync(const QString &account,const QString &password,
                    std::function<void(bool)> callback);
    //清空数据保留表结构
    bool resetDB();
    //清空数据保留表结构(异步)
    void resetDBAsync(std::function<void(bool)> callback);
    //彻底删除数据库
    bool destroyDB();
    //彻底删除数据库（异步）
    void destroyDBAsync(std::function<void(bool)> callback);
    //打印全部数据库用户
    static void printAllUsers(DatabaseManager& db);
    //返回按好友数目排序的数组（用于图标生成）
    QList<QVector<QString>> getUserFriendCountWithNick(); // 返回：[[id, 昵称, 数量]]
private:
    //主线程连接（仅用于初始化）
    QSqlDatabase m_mainConn;
    bool initDB();
    void createTable();
};

#endif // DATABASEMANAGER_H
