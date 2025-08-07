#include "MyServer.h"
#include <QDataStream>
#include <QDebug>

#include "ChatManager.h"

MyServer::MyServer(int curId, QObject* parent) : QTcpServer(parent) {
    // : QTcpServer(parent)此处要写成直接父类
    m_curId = curId;
    qDebug() << "创建MyServer对象，用户ID为："<<m_curId;
}

bool MyServer::startListening() {
    quint16 port = 8000 + m_curId;
    if (this->listen(QHostAddress::Any, port)) {
        qDebug() << QString("【主用户%1】开始监听端口 %2").arg(m_curId).arg(port);
        return true;
    } else {
        qWarning() << "监听失败：" << this->errorString();
        return false;
    }
}


void MyServer::incomingConnection(qintptr socketDescriptor) {
    //1.获取连接的新套接字
    QTcpServer::incomingConnection(socketDescriptor);
    //这个socket是属于server的，MyClient中的是发射端，此处是接收端
    QTcpSocket *socket=new QTcpSocket(this);
    if (!socket->setSocketDescriptor(socketDescriptor)) {
        socket->deleteLater();
        return;
    }
    //2.添加到成员
    m_clients.append(socket);
    //3.统一连接到 MyServer 的槽
    connect(socket, &QTcpSocket::readyRead, this, &MyServer::handleReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &MyServer::handleDisconnected);
}

void MyServer::handleReadyRead() {
    //1.将发出信号的对象安全转换为QTcpSocket*类型
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;
    //2.读取数据
    QByteArray data = socket->readAll();
    qDebug() << "收到数据：" << data;
    //3.发出信号(提醒MainPage收到了新消息)
    emit msgReceived(data, socket);
}

void MyServer::handleDisconnected() {
    //将发出信号的对象安全转换为QTcpSocket*类型
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;
    m_clients.removeOne(socket);
    socket->deleteLater();
}

int MyServer::getCurId() const {
    return m_curId;
}

QVector<QTcpSocket *> MyServer::getClients() const {
    return m_clients;
}
