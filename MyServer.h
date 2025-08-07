#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>


class MyServer : public QTcpServer{
    Q_OBJECT

public:
    explicit MyServer(int curId, QObject* parent = nullptr);  // 绑定当前用户 ID;
    bool startListening();//启动监听(绑定端口)

    //连接管理
    void incomingConnection(qintptr socketDescriptor) override;

    void handleReadyRead();

    void handleDisconnected();

    //工具方法
    int getCurId()const;//获取当前用户ID
    QVector<QTcpSocket*> getClients()const;//获取所有客户端连接

signals:
    void msgReceived(const QByteArray &data,QTcpSocket *socket);
private:
    int m_curId;
    QVector<QTcpSocket*> m_clients;
};


#endif //MYSERVER_H
