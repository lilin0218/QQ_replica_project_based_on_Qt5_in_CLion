#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QDebug>
#include <qlistwidget.h>

#include "databasemanager.h"
#include "MyServer.h"

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(DatabaseManager& db, const int& curId, QWidget *parent = nullptr);
    ~MainPage();

private:
    void init();//初始化全部
    void initServer();//初始化服务器，监听port=8000+m_curId

    void createFriendItemWidget(QVariantMap friendInfo);//根据这个好友的信息创建item添加到list
    void initListWidget();//初始化联系人表
    void initSearch();//初始化搜索功能
    void initMore();//初始化更多功能
    void initOpenChat();//初始化点击list打开对应的聊天窗口

    DatabaseManager& m_db;  // 数据库引用
    int m_curId;  // 当前用户id
    QString m_curAccount;  // 当前用户账号
    QString m_curNickname;  // 当前用户昵称
    QString m_curAvatar;    //当前用户头像
    QVector<int> m_curFriendIds;    //当前用户所有的好友id
    QVector<QVariantMap> m_curFriendInfos;//当前用户所有好友的信息
    MyServer* m_server;//MyServer对象

    Ui::MainPage *ui;

signals:
    void msgToChatPage(const QByteArray &data,int sender,int receiver);//二次分发消息
public slots:
    void refresh();//刷新list

private slots:
    void Search(const QString &text );//更据名字搜索
    void openCreatePage();//more-》建群
    void openAddPage();//more-》加好友
    void openChatPage(QListWidgetItem *item);//当点击item时，打开与这名联系人的新聊天窗口

    void parseMsg(const QByteArray &data);//解析接收到的消息

protected:
    //重写拦截关闭事件
    void closeEvent(QCloseEvent *event)override;
};

#endif // MAINPAGE_H
