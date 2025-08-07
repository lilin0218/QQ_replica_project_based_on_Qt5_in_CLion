#include "ChatManager.h"
#include "MyServer.h"
#include "MyClient.h"
#include "ChatPage.h"
#include <QTcpSocket>

ChatManager::ChatManager(QObject* parent) : QObject(parent) {}

ChatManager * ChatManager::instance() {
    static ChatManager manager;
    return &manager;
}

void ChatManager::registerServer(int curId, MyServer* server) {
    if (serversMap.contains(curId)) delete serversMap[curId];
    serversMap[curId] = server;
}

void ChatManager::registerClient(int curId, int friendId, MyClient* client) {
    if (clientsMap[curId].contains(friendId)) delete clientsMap[curId][friendId];
    clientsMap[curId][friendId] = client;
}

void ChatManager::registerChatPage(int curId, int friendId, ChatPage* page) {
    if (chatPageMap[curId].contains(friendId)) delete chatPageMap[curId][friendId];
    chatPageMap[curId][friendId] = page;
}

void ChatManager::registerAddPage(int curId, AddPage *page) {
    if (addPageMap.contains(curId)) delete addPageMap[curId];
    addPageMap[curId] = page;
}

void ChatManager::registerMainPage(int curId, MainPage *page) {
    if (mainPageMap.contains(curId)) delete mainPageMap[curId];
    mainPageMap[curId] = page;
}

void ChatManager::registerSocket(int curId, int friendId, QTcpSocket* socket) {
    if (socketMap[curId].contains(friendId)) delete socketMap[curId][friendId];
    socketMap[curId][friendId] = socket;
}

MyServer* ChatManager::getServer(int curId) {
    if (serversMap.contains(curId))
        return serversMap.value(curId, nullptr);
    return nullptr;
}

MyClient* ChatManager::getClient(int curId, int friendId) {
    if (clientsMap[curId].contains(friendId))
        return clientsMap.value(curId).value(friendId, nullptr);
    return nullptr;
}

ChatPage* ChatManager::getChatPage(int curId, int friendId) {
    if (chatPageMap[curId].contains(friendId))
        return chatPageMap.value(curId).value(friendId, nullptr);
    return nullptr;

}

AddPage * ChatManager::getAddPage(int curId) {
    if (addPageMap.contains(curId))
        return addPageMap.value(curId, nullptr);
    return nullptr;

}

MainPage * ChatManager::getMainPage(int curId) {
    if (mainPageMap.contains(curId))
        return mainPageMap.value(curId, nullptr);
    return nullptr;

}

QTcpSocket* ChatManager::getSocket(int curId, int friendId) {
    if (socketMap[curId].contains(friendId))
        return socketMap.value(curId).value(friendId, nullptr);
    return nullptr;
}

void ChatManager::removeServer(int curId) {
    // 清理 server
    if (serversMap.contains(curId)) {
        QObject* server = serversMap[curId];
        serversMap.remove(curId);
        if (server) server->deleteLater();  // 延迟销毁
    }
}

void ChatManager::removeClient(int curId, int friendId) {
    // 清理 client
    if (clientsMap.contains(curId)) {
        if (clientsMap[curId].contains(friendId)) {
            MyClient* client = clientsMap[curId][friendId];
            clientsMap[curId].remove(friendId);
            if (client)client->deleteLater();//延迟销毁
        }
    }
}

void ChatManager::removeChatPage(int curId, int friendId) {
    // 清理 chatpage
    if (chatPageMap.contains(curId)) {
        if (chatPageMap[curId].contains(friendId)) {
            //不直接delete
            chatPageMap[curId][friendId] = nullptr;
            chatPageMap[curId].remove(friendId);
        }
    }
}

void ChatManager::removeAddPage(int curId) {
    // 清理 addpage
    if (addPageMap.contains(curId)) {
        QWidget* page = addPageMap[curId];
        addPageMap.remove(curId);
        if (page) page->deleteLater();  // 延迟销毁
    }
}

void ChatManager::removeMainPage(int curId) {
    // 清理 mainpage
    if (mainPageMap.contains(curId)) {
        QWidget* page = mainPageMap[curId];
        mainPageMap.remove(curId);
        if (page) page->deleteLater();  // 延迟销毁
    }
}

void ChatManager::removeSocket(int curId, int friendId) {
    // 清理 socket
    if (socketMap.contains(curId)) {
        if (socketMap[curId].contains(friendId)) {
            QTcpSocket* sock = socketMap[curId][friendId];
            socketMap[curId].remove(friendId);
            if (sock) sock->deleteLater();
        }
    }
}
