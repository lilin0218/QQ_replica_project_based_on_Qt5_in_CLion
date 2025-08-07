#include "databasemanager.h"


DatabaseManager::DatabaseManager(QObject *parent):QObject(parent)
{
    //如果初始化就创建表结构
    if (initDB()) {
        createTable();
    }
}

DatabaseManager::~DatabaseManager() {
    for (const QString &name:QSqlDatabase::connectionNames()) {
        if (name.startsWith("conn_")) {
            QSqlDatabase::removeDatabase(name);
        }
    }
}

QSqlDatabase DatabaseManager::getThreadLocalConnection() {
    // 确保主连接已打开
    if (!m_mainConn.isOpen()) {
        qFatal("主连接未打开！请先调用 initDB()");
    }

    QString connName = QString("thread_%1").arg((quintptr)QThread::currentThreadId());

    if (!QSqlDatabase::contains(connName)) {
        QSqlDatabase conn = QSqlDatabase::cloneDatabase(m_mainConn, connName);

        // 添加详细的错误输出
        if (!conn.open()) {
            qCritical() << "线程连接打开失败:"
                       << "\n错误信息:" << conn.lastError().text()
                       << "\n主连接状态:" << m_mainConn.isOpen()
                       << "\n文件路径:" << m_mainConn.databaseName()
                       << "\n文件可写:" << QFileInfo(m_mainConn.databaseName()).isWritable();
            qFatal("无法创建线程局部连接");
        }
    }
    return QSqlDatabase::database(connName);
}

QVariantMap DatabaseManager::getUserInfo(int userId, const QStringList &fields) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    QString strField=fields.join(", ");
    query.prepare(QString("Select %1 FROM users WHERE id =?").arg(strField));
    query.addBindValue(userId);
    QVariantMap result;
    if (query.exec() && query.next()) {
        for (int i = 0; i < fields.size(); i++) {
            result[fields[i]]=query.value(i);
        }
    }else {
        qWarning()<<"getUserInfo failed:"<<query.lastError().text();
    }
    return result;
}

QVariantMap DatabaseManager::getFriendRelation(int userId, int friendId, const QStringList &fields) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    QString strField=fields.join(", ");
    query.prepare(QString("SELECT %1 FROM friends WHERE user_id = ? AND friend_id = ?").arg(strField));
    query.addBindValue(userId);
    query.addBindValue(friendId);
    QVariantMap result;
    if (query.exec() && query.next()) {
        for (int i = 0; i < fields.size(); i++) {
            result[fields[i]]=query.value(i);
        }
    }else {
        qWarning()<<"getFriendRelation failed:"<<query.lastError().text();
    }
    return result;
}

QVector<QVariantMap> DatabaseManager::getAllMsg(int userId, int friendId, const QStringList &fields) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);

    QString fieldStr = fields.join(", ");
    query.prepare(QString(R"(
        SELECT %1 FROM conversations
        WHERE (sender_id = ? AND receiver_id = ?) OR (sender_id = ? AND receiver_id = ?)
        ORDER BY send_time ASC
    )").arg(fieldStr));

    query.addBindValue(userId);
    query.addBindValue(friendId);
    query.addBindValue(friendId);
    query.addBindValue(userId);

    QVector<QVariantMap> resultList;//因为msg的查询结果会有多条符合
    if (!query.exec()) {
        qWarning() << "getAllMsg failed:" << query.lastError().text();
        return resultList;
    }
    while (query.next()) {
        QVariantMap row;
        for (int i = 0; i < fields.size(); ++i) {
            row[fields[i]] = query.value(i);
        }
        resultList.append(row);
    }

    return resultList;
}

QVariantMap DatabaseManager::getLastMsg(int userId, int friendId, const QStringList &fields) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);

    QString fieldStr = fields.join(", ");
    query.prepare(QString("SELECT %1 FROM lastMessages WHERE user_id = ? AND friend_id = ?").arg(fieldStr));
    query.addBindValue(userId);
    query.addBindValue(friendId);

    QVariantMap result;
    if (query.exec() && query.next()) {
        for (int i = 0; i < fields.size(); ++i) {
            result[fields[i]] = query.value(i);
        }
    } else {
        qWarning() << "getLastMessageInfo failed:" << query.lastError().text();
    }

    return result;
}

QList<QVariantMap> DatabaseManager::searchStrangersByAccount(int userId, const QString &partialAccount,
    const QStringList &fields) {
    //1.准备
    QList<QVariantMap> result;
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    //2.构造搜索语句
    QString strField=fields.join(", ");
    QString sql=QString(R"(SELECT %1 FROM users WHERE account LIKE ? AND id != ?
        AND id NOT IN (SELECT friend_id FROM friends WHERE user_id = ?))").arg(strField);
    query.prepare(sql);
    query.addBindValue("%"+partialAccount+"%");
    query.addBindValue(userId);
    query.addBindValue(userId);
    //3.读取搜索结果
    if (query.exec()) {
        while (query.next()) {
            QVariantMap row;
            for (int i = 0; i < fields.size(); ++i) {
                row[fields[i]] = query.value(i);
            }
            result.append(row);
        }
    }else {
        qWarning() << "searchStrangersByAccount failed:" << query.lastError().text();
    }
    return result;
}

QVector<int> DatabaseManager::getFriendIds(int userId) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    query.prepare(QString("SELECT friend_id FROM friends WHERE user_id = ?"));
    query.addBindValue(userId);
    QVector<int> result;
    if (query.exec()) {
        while (query.next()) {
            result.push_back(query.value(0).toInt());
        }
    } else {
        qWarning()<<"getFriendIds failed:"<<query.lastError().text();
    }
    return result;
}

bool DatabaseManager::addUser(const QString &nickname, const QString &account
    , const QString &password,const QString &avatar) {
    if (userExists(account)) {
        qWarning() << "User already exists:" << account;
        return false;
    }
    qDebug() << "当前线程:" << QThread::currentThread();
QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    query.prepare("INSERT INTO users(nickname,account,password,avatar)VALUES(?,?,?,?)");
    query.addBindValue(nickname);
    query.addBindValue(account);
    query.addBindValue(password);
    query.addBindValue(avatar);
    if (!query.exec()) {
        qWarning() << "Failed to add user to database:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::addUserDetails(const QString &nickname, const QString &account, const QString &password,
    const QString &avatar, int status, const QString &lastOnlineTime, const QString &signature, int gender,
    const QString &birthDate) {
    // 检查账号是否已存在
    if (userExists(account)) {
        qWarning() << "User already exists:" << account;
        return false;
    }
    qDebug() << "当前线程:" << QThread::currentThread();
QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    query.prepare(R"(
        INSERT INTO users(
            nickname,
            account,
            password,
            avatar,
            status,
            last_online_time,
            signature,
            gender,
            birth_date
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
    )");
    // 绑定参数
    query.addBindValue(nickname);
    query.addBindValue(account);
    query.addBindValue(password);
    query.addBindValue(avatar);
    query.addBindValue(status);
    query.addBindValue(lastOnlineTime);
    query.addBindValue(signature);
    query.addBindValue(gender);
    query.addBindValue(birthDate);
    if (!query.exec()) {
        qWarning() << "Failed to add user details to database:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::addFriendBoth(int userId, int friendId) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    db.transaction();  // 开启事务(保证不会出现失败时只插入了单边关系)
    query.prepare(R"(
        INSERT INTO friends(user_id, friend_id)
        VALUES (?, ?)
    )");
    // 插入 A → B
    query.addBindValue(userId);
    query.addBindValue(friendId);
    if (!query.exec()) {
        qWarning() << "Failed to add friend A→B:" << query.lastError().text();
        db.rollback();
        return false;
    }
    // 插入 B → A
    query.addBindValue(friendId);
    query.addBindValue(userId);
    if (!query.exec()) {
        qWarning() << "Failed to add friend B→A:" << query.lastError().text();
        db.rollback();
        return false;
    }
    db.commit();
    return true;
}

bool DatabaseManager::removeFriendBoth(int userId, int friendId) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    db.transaction();  // 开启事务
    query.prepare(R"(
        DELETE FROM friends
        WHERE (user_id = ? AND friend_id = ?)
           OR (user_id = ? AND friend_id = ?)
    )");
    query.addBindValue(userId);
    query.addBindValue(friendId);
    query.addBindValue(friendId);  // 双向删除
    query.addBindValue(userId);
    if (!query.exec()) {
        qWarning() << "Failed to delete friend:" << query.lastError().text();
        db.rollback();
        return false;
    }
    db.commit();
    return true;
}

bool DatabaseManager::addConversation(int senderId, int receiverId, const QString &content, int contentType,
                                      const QDateTime &sendTime, int status, bool isRecalled) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);

    query.prepare(R"(
        INSERT INTO conversations(
            sender_id, receiver_id, content, content_type,
            send_time, status, is_recalled
        ) VALUES (?, ?, ?, ?, ?, ?, ?)
    )");

    query.addBindValue(senderId);
    query.addBindValue(receiverId);
    query.addBindValue(content);
    query.addBindValue(contentType);
    query.addBindValue(sendTime);
    query.addBindValue(status);
    query.addBindValue(isRecalled);

    if (!query.exec()) {
        qWarning() << "Failed to add conversation:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::upsertLastMessageBoth(int userId, int friendId, const QString &lastMessage,
                                        const QDateTime &lastMessageTime, int unreadCount, bool isPinned) {
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    db.transaction();

    // userId 视角
    query.prepare(R"(
        INSERT INTO lastMessages(
            user_id, friend_id, last_message, last_message_time,
            unread_count, is_pinned
        ) VALUES (?, ?, ?, ?, ?, ?)
        ON CONFLICT(user_id, friend_id) DO UPDATE SET
            last_message = excluded.last_message,
            last_message_time = excluded.last_message_time,
            unread_count = excluded.unread_count,
            is_pinned = excluded.is_pinned
    )");
    query.addBindValue(userId);
    query.addBindValue(friendId);
    query.addBindValue(lastMessage);
    query.addBindValue(lastMessageTime);
    query.addBindValue(unreadCount);
    query.addBindValue(isPinned);
    if (!query.exec()) {
        qWarning() << "Failed to upsert lastMessage (user):" << query.lastError().text();
        db.rollback();
        return false;
    }

    // friendId 视角（通常 unreadCount = 0）
    query.prepare(R"(
        INSERT INTO lastMessages(
            user_id, friend_id, last_message, last_message_time,
            unread_count, is_pinned
        ) VALUES (?, ?, ?, ?, ?, ?)
        ON CONFLICT(user_id, friend_id) DO UPDATE SET
            last_message = excluded.last_message,
            last_message_time = excluded.last_message_time,
            unread_count = excluded.unread_count,
            is_pinned = excluded.is_pinned
    )");
    query.addBindValue(friendId);
    query.addBindValue(userId);
    query.addBindValue(lastMessage);
    query.addBindValue(lastMessageTime);
    query.addBindValue(0); // 好友视角一般默认 unreadCount = 0
    query.addBindValue(false); // 不置顶
    if (!query.exec()) {
        qWarning() << "Failed to upsert lastMessage (friend):" << query.lastError().text();
        db.rollback();
        return false;
    }

    return db.commit();
}

void DatabaseManager::addUserAsync(const QString &nickname, const QString &account, const QString &password
    ,const QString &avatar,std::function<void(bool)> callback) {

    PoolManager::submit([=]()->QVariant {
        return addUser(nickname,account,password,avatar);
    },[callback](QVariant result) {
        if (callback) {
            callback(result.toBool());
        }
    });
}

bool DatabaseManager::deleteUser(const QString &account) {
    if (!userExists(account)) {
        qWarning() << "User not exists:" << account;
        return false;
    }
    qDebug() << "当前线程:" << QThread::currentThread();
QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    query.prepare("DELETE FROM users WHERE account=?");
    query.addBindValue(account);
    if (!query.exec()) {
        qWarning() << "Failed to delete user from database:" << query.lastError().text();
        return false;
    }
    return true;
}

void DatabaseManager::deleteUserAsync(const QString &account, std::function<void(bool)> callback) {
    PoolManager::submit([=]()->QVariant {
        return deleteUser(account);
    },[callback](QVariant result) {
        if (callback) {
            callback(result.toBool());
        }
    });
}

bool DatabaseManager::userExists(const QString &account) {
    qDebug() << "当前线程:" << QThread::currentThread();
QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE account=?");
    query.addBindValue(account);
    if (query.exec() && query.next()) {
        return query.value(0).toInt()>0;
    }
    qWarning() << "Failed to check user existence:"<<query.lastError().text();
    return false;
}

bool DatabaseManager::friendRelationExists(int userId, int friendId) {
    QSqlQuery query(getThreadLocalConnection());
    query.prepare("SELECT 1 FROM friends WHERE user_id = ? AND friend_id = ?");
    query.addBindValue(userId);
    query.addBindValue(friendId);
    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}


void DatabaseManager::userExistsAsync(const QString &account, std::function<void(bool)> callback) {
    PoolManager::submit([=]()->QVariant {
        return userExists(account);
    },[callback](QVariant result) {
        if (callback) {
            callback(result.toBool());
        }
    });
}

int DatabaseManager::getUserId(const QString &account) {
    qDebug() << "当前线程:" << QThread::currentThread();
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    query.prepare("SELECT id FROM users WHERE account = ?");
    query.addBindValue(account);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    qWarning() << "Failed to get nickname:" << query.lastError().text();
    return -1; // 返回空字符串表示查询失败或无匹配项
}

QString DatabaseManager::getUserNickname(const QString &account) {
    qDebug() << "当前线程:" << QThread::currentThread();
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    query.prepare("SELECT nickname FROM users WHERE account = ?");
    query.addBindValue(account);
    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    qWarning() << "Failed to get nickname:" << query.lastError().text();
    return QString(); // 返回空字符串表示查询失败或无匹配项
}

void DatabaseManager::getUserNicknameAsync(const QString &account, std::function<void(QString)> callback) {
    PoolManager::submit([=]()->QVariant {
        return getUserNickname(account);
    },[callback](QVariant result) {
        if (callback) {
            callback(result.toString());
        }
    });
}

bool DatabaseManager::verifyLogin(const QString &account, const QString &password) {
    qDebug() << "当前线程:" << QThread::currentThread();
QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE account=? AND password=?");
    query.addBindValue(account);
    query.addBindValue(password);
    if (query.exec() && query.next()) {
        return query.value(0).toInt()>0;
    }
    qWarning() << "Failed to check user existence:" << query.lastError().text();
    return false;
}

void DatabaseManager::verifyLoginAsync(const QString &account, const QString &password,
std::function<void(bool)> callback) {
    PoolManager::submit([=]()->QVariant {
        return verifyLogin(account,password);
    },[callback](QVariant result) {
        if (callback) {
            callback(result.toBool());
        }
    });
}

bool DatabaseManager::resetDB() {
    if (!m_mainConn.isOpen()) {
        qWarning() << "Failed to open database:" << m_mainConn.lastError().text();
        return false;
    }
    QSqlQuery query(m_mainConn);
    if (!query.exec("DELETE FROM users")) {
        qWarning() << "Failed to delete user from database:" << query.lastError().text();
        return false;
    }
    return true;
}

void DatabaseManager::resetDBAsync(std::function<void(bool)> callback) {
    PoolManager::submit([=]()->QVariant {
        return resetDB();
    },[callback](QVariant result) {
        if (callback) {
            callback(result.toBool());
        }
    });
}

bool DatabaseManager::destroyDB() {
    if (m_mainConn.isOpen()) {
        m_mainConn.close();
    }
    QString dbPath=m_mainConn.databaseName();
    if (QFile::exists(dbPath)) {
        if (!QFile::remove(dbPath)) {
            qWarning() << "Failed to remove database file:" << dbPath;
            return false;
        }
    }
    return true;
}

void DatabaseManager::destroyDBAsync(std::function<void(bool)> callback) {
    PoolManager::submit([=]()->QVariant {
        return destroyDB();
    },[callback](QVariant result) {
        if (callback) {
            callback(result.toBool());
        }
    });
}

void DatabaseManager::printAllUsers(DatabaseManager &db) {
    qDebug() << "\n===== 数据库用户列表 =====";
    QSqlQuery query(db.getThreadLocalConnection());
    query.exec("SELECT * FROM users ORDER BY id");
    int count=0;
    while (query.next()) {
        count++;
        qDebug() << "----------------------------------------";
        qDebug() << "ID:" << query.value("id").toInt();
        qDebug() << "昵称:" << query.value("nickname").toString();
        qDebug() << "账号:" << query.value("account").toString();
        qDebug() << "密码:" << query.value("password").toString(); // 实际项目不建议输出密码
        qDebug() << "头像:" << query.value("avatar").toString();
        qDebug() << "状态:" << (query.value("status").toInt() ? "在线" : "离线");
        qDebug() << "最后在线:" << query.value("last_online_time").toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        qDebug() << "个性签名:" << query.value("signature").toString();
        qDebug() << "性别:" << [](int g){ return QStringList{"未知","男","女"}[g]; }(query.value("gender").toInt());
        qDebug() << "生日:" << query.value("birth_date").toDate().toString("yyyy-MM-dd");
        qDebug() << "注册时间:" << query.value("register_time").toDateTime().toString("yyyy-MM-dd hh:mm:ss");
    }
    qDebug() << "----------------------------------------";
    qDebug() << "总计:" << count << "个用户";
}

QList<QVector<QString>> DatabaseManager::getUserFriendCountWithNick() {
    QList<QVector<QString>> result;
    QSqlDatabase db = getThreadLocalConnection();
    QSqlQuery query(db);

    QString sql = R"(
        SELECT u.id, u.nickname, COUNT(f.friend_id) AS friend_count
        FROM users u
        LEFT JOIN friends f ON u.id = f.user_id
        GROUP BY u.id
        ORDER BY friend_count DESC
    )";

    if (!query.exec(sql)) {
        qDebug() << "联表获取好友数量失败：" << query.lastError().text();
        return result;
    }

    while (query.next()) {
        QVector<QString> row;
        row << query.value(0).toString()  // id
            << query.value(1).toString()  // nickname
            << query.value(2).toString(); // count
        result.append(row);
    }

    return result;
}

bool DatabaseManager::initDB() {
    // 只初始化主连接，不涉及线程局部连接
    if (QSqlDatabase::contains("connection")) {
        m_mainConn = QSqlDatabase::database("connection");
    } else {
        m_mainConn = QSqlDatabase::addDatabase("QSQLITE", "connection");
        m_mainConn.setDatabaseName("Heart_data.db");
    }
    // 调试信息
    qDebug() << "数据库文件是否存在:" << QFile::exists("Heart_data.db")
             << "绝对路径:" << QFileInfo("Heart_data.db").absoluteFilePath();
    if (!m_mainConn.open()) {
        qCritical() << "主连接打开失败:" << m_mainConn.lastError().text();
        return false;
    }
    return true;
}

void DatabaseManager::createTable() {
    QSqlQuery query(m_mainConn);
    // 用户表
    QString create_user_sql = R"(
        CREATE TABLE IF NOT EXISTS users(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nickname TEXT NOT NULL,
            account TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            avatar TEXT,
            status INTEGER DEFAULT 0,
            last_online_time DATETIME,
            signature TEXT,
            gender INTEGER DEFAULT 0,
            birth_date DATE,
            register_time DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    )";
    // 好友关系表
    QString create_friend_sql = R"(
        CREATE TABLE IF NOT EXISTS friends(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL,
            friend_id INTEGER NOT NULL,
            relation_status INTEGER DEFAULT 0,
            create_time DATETIME DEFAULT CURRENT_TIMESTAMP,
            remark TEXT,
            group_name TEXT DEFAULT '我的好友',
            UNIQUE(user_id, friend_id),
            FOREIGN KEY(user_id) REFERENCES users(id),
            FOREIGN KEY(friend_id) REFERENCES users(id)
        )
    )";
    // 所有聊天内容表
    QString create_conversation_sql = R"(
        CREATE TABLE IF NOT EXISTS conversations(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            sender_id INTEGER NOT NULL,
            receiver_id INTEGER NOT NULL,
            content TEXT NOT NULL,
            content_type INTEGER DEFAULT 0,
            send_time DATETIME DEFAULT CURRENT_TIMESTAMP,
            status INTEGER DEFAULT 0,
            is_recalled BOOLEAN DEFAULT 0,
            FOREIGN KEY(sender_id) REFERENCES users(id),
            FOREIGN KEY(receiver_id) REFERENCES users(id)
        )
    )";
    // 最后一次消息表
    QString create_lastMessage_sql = R"(
        CREATE TABLE IF NOT EXISTS lastMessages(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL,
            friend_id INTEGER NOT NULL,
            last_message TEXT,
            last_message_time DATETIME,
            unread_count INTEGER DEFAULT 0,
            is_pinned BOOLEAN DEFAULT 0,
            FOREIGN KEY(user_id) REFERENCES users(id),
            FOREIGN KEY(friend_id) REFERENCES users(id),
            UNIQUE(user_id, friend_id)
        )
    )";
    // 执行创建表
    if (!query.exec(create_user_sql)) {
        qWarning() << "Failed to create users table:" << query.lastError().text();
    }
    if (!query.exec(create_friend_sql)) {
        qWarning() << "Failed to create friends table:" << query.lastError().text();
    }
    if (!query.exec(create_conversation_sql)) {
        qWarning() << "Failed to create conversations table:" << query.lastError().text();
    }
    if (!query.exec(create_lastMessage_sql)) {
        qWarning() << "Failed to create messages table:" << query.lastError().text();
    }
}