#ifndef CHATMANAGER_H
#define CHATMANAGER_H

#include <QObject>
#include <QMap>

#include "addpage.h"
#include "mainpage.h"

class MyServer;
class MyClient;
class ChatPage;
class QTcpSocket;

class ChatManager : public QObject {
    Q_OBJECT
public:
    explicit ChatManager(QObject* parent = nullptr);

    static ChatManager* instance();

    // 注册接口
    void registerServer(int curId, MyServer* server);
    void registerClient(int curId, int friendId, MyClient* client);
    void registerChatPage(int curId, int friendId, ChatPage* page);
    void registerAddPage(int curId, AddPage* page);
    void registerMainPage(int curId, MainPage* page);
    void registerSocket(int curId, int friendId, QTcpSocket* socket);

    // Getter 接口
    MyServer* getServer(int curId);
    MyClient* getClient(int curId, int friendId);
    ChatPage* getChatPage(int curId, int friendId);
    AddPage* getAddPage(int curId);
    MainPage* getMainPage(int curId);
    QTcpSocket* getSocket(int curId, int friendId);

    // 释放指定用户的所有资源（退出登录时）
    void removeServer(int curId);
    void removeClient(int curId, int friendId);
    void removeChatPage(int curId, int friendId);
    void removeAddPage(int curId);
    void removeMainPage(int curId);
    void removeSocket(int curId, int friendId);

private:
    // 网络与界面资源映射表
    QMap<int, MyServer*> serversMap;                          // curId -> server
    QMap<int, QMap<int, MyClient*>> clientsMap;              // curId -> (friendId -> client)
    QMap<int, QMap<int, ChatPage*>> chatPageMap;             // curId -> (friendId -> page)
    QMap<int, AddPage*> addPageMap;
    QMap<int, MainPage*> mainPageMap;
    QMap<int, QMap<int, QTcpSocket*>> socketMap;             // curId -> (friendId -> socket)
};

#endif // CHATMANAGER_H
