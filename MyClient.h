#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTimer>

class MyClient : public QObject {
    Q_OBJECT

public:
    explicit MyClient(int curId, int friendId, QObject* parent = nullptr);  // 当前用户要连接的好友 ID

    void connectToHost();//主动连接到服务器

    //数据的发送与接收
    void sendMsg(const QByteArray& data);   //发送数据

    //工具方法
    int getCurId()const;
    int getFriendId()const;
    QTcpSocket *getSocket();
    bool isConnected()const;//判断是否连接

signals:
    void connected();
    void disconnected();
    void msgReceived(QByteArray data);

private slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void sendHeartMsg();//时间到，该发送一次心跳包到服务器

private:
    QTcpSocket *m_socket;//每个socket由创建它的MyClient管理
    int m_curId;
    int m_friendId;
    QTimer *m_heartTimer;
};

#endif //MYCLIENT_H
