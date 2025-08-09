#include "MyClient.h"
#include <QHostAddress>
#include <QDataStream>
#include <QDebug>
#include "protocol.h"
#include "appconfig.h"

MyClient::MyClient(int curId, int friendId, QObject* parent): QObject(parent) {
    //1.日志
    m_socket=new QTcpSocket(this);
    m_curId=curId;
    m_friendId=friendId;
    m_heartTimer=new QTimer(this);
    qDebug() << "创建MyClient对象，用户ID为："<<m_curId<<"好友ID为："<<m_friendId;
    //2.连接槽函数
    connect(m_socket, &QTcpSocket::connected, this, &MyClient::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &MyClient::onDisconnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &MyClient::onReadyRead);
    connect(m_heartTimer,&QTimer::timeout,this,&MyClient::sendHeartMsg);
    //3. 启动心跳计时器
    m_heartTimer->start(5000);
}

void MyClient::connectToHost() {
    quint16 port = 8000+m_friendId;
    QString ip=AppConfig::getServerIp();
    m_socket->connectToHost(QHostAddress(ip), port);
    qDebug() << QString("【用户%1】尝试连接好友【%2】端口【%3】"
        ).arg(m_curId).arg(m_friendId).arg(port);
}

void MyClient::sendMsg(const QByteArray &data) {
    if (m_socket && m_socket->state() == QAbstractSocket::ConnectedState) {
        m_socket->write(data);
        m_socket->flush();
        qDebug() << QString("【用户%1】向好友【%2】发送消息【%3】"
            ).arg(m_curId).arg(m_friendId).arg(QString(data));
    }
}

int MyClient::getCurId() const {
    return m_curId;
}

int MyClient::getFriendId() const {
    return m_friendId;
}

QTcpSocket * MyClient::getSocket() {
    return m_socket;
}

bool MyClient::isConnected() const {
}

void MyClient::onConnected() {
    qDebug() << QString("【用户%1】成功连接到【好友%2】").arg(m_curId).arg(m_friendId);
    emit connected();
}

void MyClient::onDisconnected() {
    qDebug() << QString("【用户%1】与【好友%2】断开连接").arg(m_curId).arg(m_friendId);
    emit disconnected();
}

void MyClient::onReadyRead() {
    QByteArray data=m_socket->readAll();
    emit msgReceived(data);
}

void MyClient::sendHeartMsg() {
    QByteArray data=Protocol::createHeartMsg(m_curId,m_friendId);
    m_socket->write(data);
    qDebug() << QString("【客户端%1】向【服务端%2】发送了一次心跳包").arg(m_curId).arg(m_friendId);
}
