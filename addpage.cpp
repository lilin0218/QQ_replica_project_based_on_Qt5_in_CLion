#include "addpage.h"
#include "ui_addpage.h"
#include <QButtonGroup>
#include <QPropertyAnimation>
#include "dynamicgradientbg.h"
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QPainter>
#include <QPainterPath>

#include "ChatManager.h"
#include "mainpage.h"

AddPage::AddPage(DatabaseManager& db, const int &curId,QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::AddPage), m_db(db),m_curId(curId) {
    ui->setupUi(this);
    //注册
    ChatManager::instance()->registerAddPage(m_curId,this);
    //初始化
    init();
    initUnderLine();
    initListSelect();
    initSearch();
    initClickAdd();

    connect(this,&AddPage::refreshMainPageList
        ,ChatManager::instance()->getMainPage(m_curId)
        ,&MainPage::refresh,Qt::UniqueConnection);
}

AddPage::~AddPage()
{
    delete ui;
}

void AddPage::init() {
    this->setWindowTitle("AddPage:"+QString::number(m_curId));
    qDebug()<<"打开新的addPage成功，当前页的id为："<<m_curId;

    DynamicGradientBG::installDynamicGradientBG(this);
}

void AddPage::initUnderLine() {
    //将四个按钮添加到group
    categoryGroup = new QButtonGroup(this);
    categoryGroup->addButton(ui->pushButton_stranger, 0);
    categoryGroup->addButton(ui->pushButton_friend, 1);
    categoryGroup->addButton(ui->pushButton_group, 2);
    categoryGroup->addButton(ui->pushButton_robot, 3);
    //创建下划线
    lineIndicator = new QWidget(ui->groupBox);
    lineIndicator->setFixedHeight(5);
    lineIndicator->setStyleSheet("background-color: #9489cd; border-radius: 1px;");
    lineIndicator->move(ui->pushButton_stranger->x()+25, ui->pushButton_stranger->y()+7
        + ui->pushButton_stranger->height()); // 初始位置
    lineIndicator->resize(ui->pushButton_stranger->width()-50, 5);
    lineIndicator->show();
    //下划线移动动画
    //函数重载器（因为idClicked有一个int型和一个指针型的）
    connect(categoryGroup, QOverload<int>::of(&QButtonGroup::idClicked), this, [=](int id){
        QPushButton* btn = qobject_cast<QPushButton*>(categoryGroup->button(id)); //  正确获取按钮
        if (btn) {
            QRect endRect(btn->x()+25, btn->y()+7 + btn->height(), btn->width()-50, 5);
            QPropertyAnimation* anim = new QPropertyAnimation(lineIndicator, "geometry");
            anim->setDuration(200);
            anim->setStartValue(lineIndicator->geometry());
            anim->setEndValue(endRect);
            anim->setEasingCurve(QEasingCurve::OutCubic);
            anim->start(QAbstractAnimation::DeleteWhenStopped);
        }
    });
}

void AddPage::initListSelect() {
    connect(categoryGroup, QOverload<int>::of(&QButtonGroup::idClicked), this, [=](int id){
        m_state=id;
        ui->lineEdit_search->setText(QString::number(m_state));
        ui->lineEdit_search->clear();
        ui->lineEdit_search->setFocus();
    });
}

void AddPage::initSearch() {
    connect(ui->lineEdit_search,&QLineEdit::textChanged,this,&AddPage::search);
}

void AddPage::initClickAdd() {
    connect(ui->listWidget_main,&QListWidget::itemClicked,this,&AddPage::addStranger);
    connect(ui->listWidget_main,&QListWidget::itemClicked,this,&AddPage::removeFriend);
}

void AddPage::createItemWidget(QVariantMap info) {
    //解析传入的info
    int strangerId=info["id"].toInt();
    QString strangerNickname=info["nickname"].toString();
    QString strangerAccount=info["account"].toString();
    QString strangerAvatar=info["avatar"].toString();
    //组件widget
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget_main);
    //这里将传入的好友id绑定到这个item，便于后续触发点击信号时传入槽函数
    item->setData(Qt::UserRole,strangerId);
    item->setSizeHint(QSize(0,70));
    QWidget *itemWidget = new QWidget();
    QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);
    itemLayout->setContentsMargins(10, 5, 10, 5);
    //圆形头像
    QPixmap avatarPixmap(strangerAvatar);
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
    QLabel *title = new QLabel(strangerNickname);
    QFont titleFont = title->font();
    titleFont.setPointSize(10);
    titleFont.setBold(true);
    title->setFont(titleFont);
    //账号
    QLabel *account = new QLabel(strangerAccount);
    QLabel *note = nullptr;
    if (m_state==0) {
        note = new QLabel("陌生人(左击以添加为好友)");
    }else if (m_state==1) {
        note = new QLabel("好友（左击以删除该好友）");
    }else if (m_state==2) {
        note = new QLabel("未实现功能");
    }else if (m_state==3) {
        note = new QLabel("未实现功能");
    }
    //添加到文本布局
    QVBoxLayout *textLayout = new QVBoxLayout();
    textLayout->addWidget(title);
    textLayout->addWidget(account);
    //添加到组件布局
    itemLayout->addWidget(avatar);
    itemLayout->addLayout(textLayout);
    itemLayout->addStretch();
    itemLayout->addWidget(note);
    //添加到list
    title->setStyleSheet("background: transparent;");
    account->setStyleSheet("background: transparent;");
    ui->listWidget_main->setItemWidget(item,itemWidget);
    itemWidget->setAttribute(Qt::WA_TranslucentBackground);
    itemWidget->setStyleSheet("background: transparent;");
}

void AddPage::search(const QString &partAccount) {
    //1.清空list
    ui->listWidget_main->clear();
    //2.判断当前选择的list类型
    if (m_state==0) {
        qDebug()<<"模式切换:【添加陌生人】";
        //3.1.获取搜寻结果
        QList<QVariantMap> strangerInfos=m_db.searchStrangersByAccount(
            m_curId,partAccount,{"id","nickname","account","avatar"});
        //3.2.遍历所有搜索结果，为每个人创建item并加入list
        for (const auto& info:strangerInfos) {
            createItemWidget(info);
        }
    }else if(m_state==1) {
        qDebug()<<"模式切换:【删除已有好友】";
        //3.1 获取全部好友id
        QVector<int> friendIds=m_db.getFriendIds(m_curId);
        //3.2 遍历获取全部好友info
        for (const auto& id:friendIds) {
            auto info=m_db.getUserInfo(id
                ,{"id","nickname","account","avatar"});
            createItemWidget(info);
        }
    }else if(m_state==2) {
        qDebug()<<"模式切换:【功能未实现】";
    }else if(m_state==3) {
        qDebug()<<"模式切换:【功能未实现】";
    }else return;
}

void AddPage::addStranger(QListWidgetItem *item) {
    //1.判断是否为添加陌生人模式
    if (m_state!=0)return;
    //2.读取要添加的id
    int strangerId=item->data(Qt::UserRole).toInt();
    //3.弹出询问框
    QString question=QString("确定要添加编号为%1的陌生人为好友吗?").arg(strangerId);
    QMessageBox::StandardButton relay=QMessageBox::question(
        this,"添加好友",question,QMessageBox::Yes|QMessageBox::No);
    //4.判断结果
    if (relay==QMessageBox::Yes) {
        //5.更新数据库
        m_db.addFriendBoth(m_curId,strangerId);
        //6.清空搜索框与结果
        ui->lineEdit_search->clear();
        ui->listWidget_main->clear();
        //7.弹出提示
        QMessageBox::information(this,"添加好友"
            ,QString("成功添加编号为%1的陌生人为好友").arg(strangerId));
        //8.发出信号提醒MainPage更新list
        emit refreshMainPageList();
    }
}

void AddPage::removeFriend(QListWidgetItem *item) {
    //1.判断是否为删除好友模式
    if (m_state!=1)return;
    //2.读取要删除的id
    int friendId=item->data(Qt::UserRole).toInt();
    //3.弹出询问框
    QString question=QString("确定要删除编号为%1的好友吗?").arg(friendId);
    QMessageBox::StandardButton relay=QMessageBox::question(
        this,"删除好友",question,QMessageBox::Yes|QMessageBox::No);
    //4.判断结果
    if (relay==QMessageBox::Yes) {
        //5.更新数据库
        m_db.removeFriendBoth(m_curId,friendId);
        //6.清空搜索框与结果
        ui->lineEdit_search->clear();
        ui->listWidget_main->clear();
        //7.弹出提示
        QMessageBox::information(this,"删除好友"
            ,QString("成功删除编号为%1的好友").arg(friendId));
        //8.发出信号提醒MainPage更新list
        emit refreshMainPageList();
    }
}

void AddPage::closeEvent(QCloseEvent *event) {
    ChatManager::instance()->removeAddPage(m_curId);
    qDebug() << "已完成 AddPage 的清理";
    QWidget::closeEvent(event);
}
