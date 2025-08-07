#include <QMessageBox>
#include <QPainter>
#include "MainPage.h"
#include "ui_mainpage.h"
#include <QPainterPath>
#include <QMenu>
#include "addpage.h"
#include "ChatManager.h"
#include "createpage.h"
#include "chatpage.h"
#include "MyServer.h"

MainPage::MainPage(DatabaseManager& db,const int& curId,QWidget *parent)
    : QWidget(parent)
      , m_db(db),m_curId(curId),ui(new Ui::MainPage) {
    ui->setupUi(this);
    //注册
    ChatManager::instance()->registerMainPage(m_curId,this);
    //初始化基本信息
    init();
    //初始化各个组件
    initServer();
    initListWidget();
    initSearch();
    initMore();
    initOpenChat();
}

MainPage::~MainPage(){
    delete ui;
}

void MainPage::init() {
    //设置窗口基本信息
    this->setWindowTitle("MainPage:"+QString::number(m_curId));
    qDebug()<<"打开新的MainPage成功，当前页的id为："<<m_curId;
    //登录成功后，注册主用户对应的唯一MyServer对象
    m_server=new MyServer(m_curId,this);
    ChatManager::instance()->registerServer(m_curId,m_server);
    //根据传入id获取当前主用户信息
    QVariantMap curInfo=m_db.getUserInfo(m_curId,{
        "nickname","account","avatar"});
    m_curAccount=curInfo["account"].toString();
    m_curNickname=curInfo["nickname"].toString();
    m_curAvatar=curInfo["avatar"].toString();
    ui->label_curNickname->setText(m_curNickname);
    ui->toolButton_curAvatar->setIcon(QIcon(m_curAvatar));
    //根据主用户id获取所有好友id
    m_curFriendIds=m_db.getFriendIds(m_curId);
    // DynamicGradientBG::installDynamicGradientBG(this);

}

void MainPage::initServer() {
    //1.开始监听端口
    m_server->startListening();
    //2.监听MyServer发来的收到消息信号并做出反应
    connect(m_server,&MyServer::msgReceived,this,&MainPage::parseMsg);
}

void MainPage::createFriendItemWidget(QVariantMap friendInfo) {
    //解析传入的info
    int m_FriendId=friendInfo["id"].toInt();
    QString m_FriendNickname=friendInfo["nickname"].toString();
    QString m_FriendAccount=friendInfo["account"].toString();
    QString m_FriendAvatar=friendInfo["avatar"].toString();
    QString m_FriendLastMsg=friendInfo["last_message"].toString();
    QDateTime m_FriendOlTime=friendInfo["last_message_time"].toDateTime();
    //组件widget
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget_main);
    //这里将传入的好友id绑定到这个item，便于后续触发点击信号时传入槽函数
    item->setData(Qt::UserRole,m_FriendId);
    item->setSizeHint(QSize(0,70));
    QWidget *itemWidget = new QWidget();
    QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);
    itemLayout->setContentsMargins(10, 5, 10, 5);
    //圆形头像
    QPixmap avatarPixmap(m_FriendAvatar);
    avatarPixmap=avatarPixmap.scaled(40,40,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QPixmap circular(40,40);
    circular.fill(Qt::transparent);
    QPainter painter(&circular);
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addEllipse(0,0,40,40);
    painter.setClipPath(path);
    painter.drawPixmap(0,0,avatarPixmap);
    //头像
    QLabel *avatar = new QLabel;
    avatar->setPixmap(circular);
    avatar->installEventFilter(this);
    //标题
    QLabel *title = new QLabel(m_FriendNickname);
    QFont titleFont = title->font();
    titleFont.setPointSize(10);
    titleFont.setBold(true);
    title->setFont(titleFont);
    //时间与摘要
    QLabel *time = new QLabel(m_FriendOlTime.toString());
    QLabel *desc = new QLabel(m_FriendLastMsg);
    //添加到文本布局
    QVBoxLayout *textLayout = new QVBoxLayout();
    textLayout->addWidget(title);
    textLayout->addWidget(desc);
    //添加到组件布局
    itemLayout->addWidget(avatar);
    itemLayout->addLayout(textLayout);
    itemLayout->addStretch();
    itemLayout->addWidget(time);
    //添加到list
    title->setStyleSheet("background: transparent;");
    desc->setStyleSheet("background: transparent;");
    time->setStyleSheet("background: transparent;");
    ui->listWidget_main->setItemWidget(item,itemWidget);
    itemWidget->setAttribute(Qt::WA_TranslucentBackground);
    itemWidget->setStyleSheet("background: transparent;");
}

void MainPage::initListWidget() {
    //1.读取所有好友信息并储存到vector
    for (const int id:m_curFriendIds) {
        QVariantMap info=m_db.getUserInfo(id,{
            "nickname","account","avatar","status","last_online_time"});
        QVariantMap msgInfo=m_db.getLastMsg(
            m_curId,id,{"last_message","last_message_time"});
        //2.将用户表和最后一次聊天记录表的内容都转移到info中
        info["last_message"]=msgInfo["last_message"];
        info["last_message_time"]=msgInfo["last_message_time"];
        info["id"]=id;
        m_curFriendInfos.push_back(info);
    }
    //3.初始时为每个info创建item，即显示所有联系人
    for (QVariantMap info:m_curFriendInfos) {
        createFriendItemWidget(info);
    }
    //4.设置透明背景
    ui->listWidget_main->setStyleSheet("background-color: rgba(255, 255, 255, 20);"); // 半透明白色背景
}

void MainPage::initSearch() {
    //槽函数的新式写法：Search的位置不需要写入参
    connect(ui->lineEdit_search,&QLineEdit::textChanged,this,&MainPage::Search);
}

void MainPage::initMore() {
    QMenu *menu = new QMenu(this);
    menu->addAction("创建群聊(未完成)", this, &MainPage::openCreatePage);
    menu->addAction("添加陌生人/删除已有好友", this, &MainPage::openAddPage);
    ui->toolButton_more->setMenu(menu);
    ui->toolButton_more->setPopupMode(QToolButton::InstantPopup);
}

void MainPage::initOpenChat() {
    connect(ui->listWidget_main,&QListWidget::itemClicked,this,&MainPage::openChatPage);
}

void MainPage::Search(const QString &text ) {
    ui->listWidget_main->clear();
    for (const auto &info:m_curFriendInfos) {
        QString nickname=info["nickname"].toString();
        if (text.isEmpty() || nickname.contains(text,Qt::CaseInsensitive)) {
            createFriendItemWidget(info);
        }
    }
}

void MainPage::openCreatePage() {
    CreatePage *c=new CreatePage(m_db,m_curId);
    c->show();
}

void MainPage::openAddPage() {
    AddPage *a=new AddPage(m_db,m_curId);
    a->show();
}

void MainPage::openChatPage(QListWidgetItem *item) {
    int friendId=item->data(Qt::UserRole).toInt();
    ChatPage *c=new ChatPage(m_db,m_curId,friendId);
    c->show();//chat的注册在chat的init中
}

void MainPage::refresh() {
    ui->listWidget_main->clear();
    m_curFriendIds.clear();//注意这里要重新获取好友id数组，否则会造成刷新了但是没有变化
    m_curFriendIds=m_db.getFriendIds(m_curId);
    m_curFriendInfos.clear();//注意这里需要先清空成员
    initListWidget();
}

void MainPage::parseMsg(const QByteArray &data, QTcpSocket *socket) {
    //1.解析消息
    QList<QJsonObject> list=Protocol::parseMultiMsg(data);
    //2.提取初步信息
    for (const QJsonObject &obj:list) {
        QString type=obj["type"].toString();
        int sender=obj["sender"].toInt();
        int receiver=obj["receiver"].toInt();
        int size=obj.size();
        //3.日志
        QString log=QString("初步解析：【发送者:%1】【接收者:%2】【类型:%3】【原始大小:%4】"
            ).arg(sender).arg(receiver).arg(type).arg(size);
        qDebug()<<log;
        //4.获取对应chat页面
        ChatPage *chat=ChatManager::instance()->getChatPage(receiver,sender);
        //5.让chat页面监听msgToChatPage信号
        connect(this,&MainPage::msgToChatPage,chat,
            &ChatPage::onMsgFromMainPage, Qt::UniqueConnection);
        //6.将消息二次分发给ChatPage页面解析
        emit msgToChatPage(QJsonDocument(obj).toJson(),receiver,sender);
    }
}

void MainPage::closeEvent(QCloseEvent *event) {
    int curId = m_curId;
    // 1.关闭所有 ChatPage（自动在 closeEvent 中清理资源）
    auto friendIds = m_curFriendIds;
    for (int friendId : friendIds) {
        ChatPage *chatPage = ChatManager::instance()->getChatPage(curId, friendId);
        if (chatPage != nullptr) {
            chatPage->close(); // 内部会清理 client/socket
        }
    }
    // 2.关闭 AddPage
    AddPage *addPage = ChatManager::instance()->getAddPage(curId);
    if (addPage != nullptr) {
        addPage->close();
    }
    // 3.清理 Server
    if (ChatManager::instance()->getServer(curId) != nullptr) {
        ChatManager::instance()->removeServer(curId);
    }
    // 4.清理 MainPage 自身
    ChatManager::instance()->removeMainPage(curId);
    qDebug() << "MainPage 完成全部资源释放：" << curId;
    QWidget::closeEvent(event);
}
