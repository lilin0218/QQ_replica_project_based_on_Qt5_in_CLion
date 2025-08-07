#ifndef CHATPAGE_H
#define CHATPAGE_H

#include <QTcpSocket>
#include <QWidget>
#include "databasemanager.h"
#include "MyClient.h"
#include "MyServer.h"
#include "protocol.h"

namespace Ui {
class ChatPage;
}

class ChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChatPage(DatabaseManager& db,
        const int& curId,const int& friendId,QWidget *parent = nullptr);
    ~ChatPage();

private:
    Ui::ChatPage *ui;
    DatabaseManager& m_db;
    int m_curId;//当前id
    int m_friendId;//好友id
    QString m_curNickname;  // 当前用户昵称
    QString m_friendNickname;  // 好友昵称
    QString m_curAvatar;    //当前用户头像
    QString m_friendAvatar;    //好友头像

    //  网络成员变量
    MyClient *m_client;
    QTcpSocket *m_socket;

    //  文件接收成员变量
    QFile* m_recvFile=nullptr;  //文件对象
    QString m_recvFileName;     //文件名
    qint64 m_recvFileSize=0;    //总大小
    qint64 m_recvReceived=0;    //已接收大小

    void init();//初始化
    void initMember();//初始化成员
    void initButton();//初始化所有按钮
    void initClient(int friendId);//网络初始化（即开始监听）
    void initHistory();//初始化历史聊天

    // 1. 添加文字消息
    void addTextMsg(const QString& avatarPath, const QDateTime& time, bool isMine,
                    const QString& text);
    // 2. 添加图片消息
    void addImageMsg(const QString& avatarPath, const QDateTime& time, bool isMine,
                     const QString& imagePath);
    // 3. 添加窗口抖动消息
    void addShakeMsg(const QString& avatarPath, const QDateTime& time, bool isMine);
    // 4. 添加文件消息
    void addFileMsg(const QString& avatarPath, const QDateTime& time, bool isMine,
                    const QString& fileName, const QString& filePath, const qint64& fileSize);

    // 添加/更新数据库
    void updateDB(int senderId, int receiverId, const QString &content, int contentType,
                  const QDateTime &sendTime, int status, bool isRecalled) ;

    //窗口抖动
    void shakeWindow(QWidget *targetWindow);
    //如果Msg类型是File需要额外处理
    void handleFileMsg(const Protocol &msg);
    //文件大小格式化
    QString formatFileSize(qint64 bytes);
    //圆形头像生成
    QPixmap createCircularPix(const QPixmap &source);

public slots:
    //监听消息接收
    void onMsgFromMainPage(const QByteArray &data, int curId, int senderId);

private slots:
    void onSendText();//点击发送文本消息
    void onSendImg();//点击发送图片消息
    void onSendShake();//点击发送窗口晃动
    void onSendFile();//点击发送文件

    void onScreenShot();//点击截图并保存

    void onConnectToHost();//点击网络连接按钮
    //网络连接结果处理
    void onConnected(int friendId);
    void onConnectFailed(int friendId);

protected:
    //重写拦截关闭事件
    void closeEvent(QCloseEvent *event)override;
};

#endif // CHATPAGE_H
