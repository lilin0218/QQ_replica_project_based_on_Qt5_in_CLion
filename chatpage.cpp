#include "chatpage.h"
#include "ui_chatpage.h"
#include "dynamicgradientbg.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>
#include <QPainterPath>
#include <QPropertyAnimation>
#include <QPoint>
#include <QEasingCurve>
#include <QDesktopServices>
#include "appconfig.h"
#include <QProcess>
#include <QCryptographicHash>

#include "ChatManager.h"
#include "MyClient.h"

ChatPage::ChatPage(DatabaseManager& db, const int &curId,
                   const int &friendId, QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::ChatPage), m_db(db),m_curId(curId),m_friendId(friendId) {
    ui->setupUi(this);

    //初始化
    init();
    initMember();
    initButton();
    initClient(m_friendId);
    initHistory();

    //ChatPage打开后注册
    ChatManager::instance()->registerChatPage(m_curId,m_friendId,this);
    ChatManager::instance()->registerClient(m_curId,m_friendId,m_client);//要等m_client初始化
    ChatManager::instance()->registerSocket(m_curId,m_friendId,m_socket);
}

ChatPage::~ChatPage()
{
    delete ui;
}

//初始化
void ChatPage::init() {
    //设置窗口基本信息
    this->setWindowTitle("ChatPage:"+QString::number(m_curId));
    qDebug()<<"打开新的chatPage成功，本人id为："<<m_curId<<"。聊天对方id为"<<m_friendId;
    //渐变背景
    DynamicGradientBG::installDynamicGradientBG(this);
}

void ChatPage::initMember() {
    //读取主用户和好友的信息到类成员
    QVariantMap curInfo=m_db.getUserInfo(m_curId,{"nickname","avatar"});
    QVariantMap friendInfo=m_db.getUserInfo(m_friendId,{"nickname","avatar"});
    m_curNickname=curInfo["nickname"].toString();
    m_curAvatar=curInfo["avatar"].toString();
    m_friendNickname=friendInfo["nickname"].toString();
    m_friendAvatar=friendInfo["avatar"].toString();
    ui->label_friendName->setText(m_friendNickname);
}

//连接功能区按钮
void ChatPage::initButton() {
    connect(ui->pushButton_send,&QPushButton::clicked,this,&ChatPage::onSendText);//1.发送文本
    connect(ui->toolButton_img,&QToolButton::clicked,this,&ChatPage::onSendImg);//2.发送图片
    connect(ui->toolButton_windowShake,&QToolButton::clicked,this,&ChatPage::onSendShake);//3.发送晃动
    connect(ui->toolButton_file,&QToolButton::clicked,this,&ChatPage::onSendFile);//4.发送文件
    connect(ui->pushButton_close,&QPushButton::clicked,this,[=] {
        this->close();
    });//关闭
    connect(ui->toolButton_screenShot,&QToolButton::clicked,this,&ChatPage::onScreenShot);//触发截图
    connect(ui->pushButton_connect,&QPushButton::clicked,this,&ChatPage::onConnectToHost);//触发主动连接
}

//网络初始化
void ChatPage::initClient(int friendId) {
    //初始化网络成员
    m_client = new MyClient(m_curId,m_friendId,this);
    m_socket=m_client->getSocket();
    //槽函数(为什么要写lamda表达式？因为connected信号不自带参数，需要由表达式传入)
    connect(m_client, &MyClient::connected, this, [=]() {
        onConnected(friendId);
    });
    connect(m_client, &MyClient::disconnected, this, [=]() {
        onConnectFailed(friendId);
    });
}

void ChatPage::initHistory() {
    //1.查询数据库，获取所有字段的聊天记录
    QStringList fields={"sender_id","receiver_id"
        ,"content","content_type","send_time"};
    QVector<QVariantMap> msgs=m_db.getAllMsg(m_curId,m_friendId,fields);
    //2.遍历每条消息
    for (const QVariantMap& msg:msgs) {
        int senderId=msg.value("sender_id").toInt();
        QString content=msg.value("content").toString();
        int type=msg.value("content_type").toInt();
        QDateTime time=msg.value("send_time").toDateTime();
        bool isMine=(senderId==m_curId);//判断是否自己为发送者

        QString log=QString("加载了一条历史记录:【发送者:%1】【类型:%2】【内容:%3】"
            ).arg(senderId).arg(type).arg(content);
        qDebug()<<log;

        //3.根据消息添加相应的气泡
        switch (type) {
            case 0:
                addTextMsg(isMine ? m_curAvatar:m_friendAvatar,time,isMine,content);
                break;
            case 1:
                addImageMsg(isMine ? m_curAvatar:m_friendAvatar,time,isMine,content);
                break;
            case 2:
                addShakeMsg(isMine ? m_curAvatar:m_friendAvatar,time,isMine);
                break;
            case 3: {
                //文件消息存的是文件名 + 路径 + 大小，中间用分隔符组合
                QStringList parts=content.split('|');
                if (parts.size()==3) {
                    QString fileName=parts[0];
                    QString filePath=parts[1];
                    qint64 fileSize=parts[2].toLongLong();
                    addFileMsg(isMine ? m_curAvatar : m_friendAvatar
                        , time, isMine, fileName, filePath, fileSize);
                }else {
                    qWarning() << "Invalid file content format:" << content;
                }
                break;
            }
            default:
                qWarning() << "Unknown content_type:" << type;
        }
    }

}


//1.添加一个文本气泡到窗口
void ChatPage::addTextMsg(const QString& avatarPath, const QDateTime& time, bool isMine,
                    const QString& text) {
    //1.创建widget
    QWidget *itemWidget=new QWidget(this);
    QHBoxLayout *layout=new QHBoxLayout(itemWidget);
    layout->setContentsMargins(5,5,5,5);
    //2.头像(圆形)
    QPixmap avatarPixmap=QPixmap(avatarPath);
    avatarPixmap=avatarPixmap.scaled(50,50,
        Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    QLabel *label_avatar=new QLabel(itemWidget);
    label_avatar->setFixedSize(50,50);
    label_avatar->setPixmap(createCircularPix(avatarPixmap));
    //3.文本
    QLabel *label_text=new QLabel(text,itemWidget);
    label_text->setWordWrap(true);
    label_text->setStyleSheet(QString(
        "QLabel{background-color:%1; border-radius:8px; padding:6px; "
        "max-width:300px}").arg(isMine ? "#9489cd" : "#fdf8ff"));
    //4.时间
    QLabel *label_time=new QLabel(time.toString(),itemWidget);
    label_time->setStyleSheet("color:gray;font-size:10px");
    label_time->setAlignment(Qt::AlignCenter);
    //5.创建时间+信息内容的组合
    QVBoxLayout *msgLayout=new QVBoxLayout();
    msgLayout->setSpacing(3);
    msgLayout->addWidget(label_time);
    msgLayout->addWidget(label_text);
    //6.位置
    if (isMine) {
        layout->addStretch();
        layout->addLayout(msgLayout);
        layout->addWidget(label_avatar);
    }else {
        layout->addWidget(label_avatar);
        layout->addLayout(msgLayout);
        layout->addStretch();
    }
    //7.添加到list
    QListWidgetItem *item=new QListWidgetItem(ui->listWidget_msg);
    item->setSizeHint(itemWidget->sizeHint());
    ui->listWidget_msg->addItem(item);
    ui->listWidget_msg->setItemWidget(item,itemWidget);
}

//2.添加一个图像气泡到窗口
void ChatPage::addImageMsg(const QString& avatarPath, const QDateTime& time, bool isMine,
                     const QString& imagePath) {
    //1.创建widget
    QWidget *itemWidget=new QWidget(this);
    QHBoxLayout *layout=new QHBoxLayout(itemWidget);
    layout->setContentsMargins(5,5,5,5);
    //2.头像(圆形)
    QPixmap avatarPixmap=QPixmap(avatarPath);
    avatarPixmap=avatarPixmap.scaled(50,50,
        Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    QLabel *label_avatar=new QLabel(itemWidget);
    label_avatar->setFixedSize(50,50);
    label_avatar->setPixmap(createCircularPix(avatarPixmap));
    //3.图片
    QLabel *label_img=new QLabel(itemWidget);
    QPixmap img(imagePath);
    label_img->setPixmap(img.scaled(120,120,
    Qt::KeepAspectRatio,Qt::SmoothTransformation));
    label_img->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    //4.时间
    QLabel *label_time=new QLabel(time.toString(),itemWidget);
    label_time->setStyleSheet("color:gray;font-size:10px");
    label_time->setAlignment(Qt::AlignCenter);
    //5.创建时间+信息内容的组合
    QVBoxLayout *msgLayout=new QVBoxLayout();
    msgLayout->setSpacing(3);
    msgLayout->addWidget(label_time,0,Qt::AlignCenter);
    msgLayout->addWidget(label_img,0,Qt::AlignLeft);
    //6.位置
    if (isMine) {
        layout->addStretch();
        layout->addLayout(msgLayout);
        layout->addWidget(label_avatar);
    }else {
        layout->addWidget(label_avatar);
        layout->addLayout(msgLayout);
        layout->addStretch();
    }
    //7.添加到list
    QListWidgetItem *item=new QListWidgetItem(ui->listWidget_msg);
    item->setSizeHint(itemWidget->sizeHint());
    ui->listWidget_msg->addItem(item);
    ui->listWidget_msg->setItemWidget(item,itemWidget);
}

//3.添加一个晃动窗口气泡到窗口
void ChatPage::addShakeMsg(const QString& avatarPath, const QDateTime& time, bool isMine) {
    //1.晃动自身窗口
    shakeWindow(this);
    //2.创建widget
    QWidget *itemWidget=new QWidget(this);
    QHBoxLayout *layout=new QHBoxLayout(itemWidget);
    layout->setContentsMargins(5,5,5,5);
    //3.头像(圆形)
    QPixmap avatarPixmap=QPixmap(avatarPath);
    avatarPixmap=avatarPixmap.scaled(50,50,
        Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    QLabel *label_avatar=new QLabel(itemWidget);
    label_avatar->setFixedSize(50,50);
    label_avatar->setPixmap(createCircularPix(avatarPixmap));
    //4.文本
    QLabel *label_text=new QLabel("[窗口抖动]",itemWidget);
    label_text->setWordWrap(true);
    label_text->setStyleSheet(QString(
        "QLabel{background-color:%1; border-radius:8px; padding:6px; font-style:italic"
        "max-width:300px}").arg(isMine ? "#9489cd" : "#fdf8ff"));
    //5.时间
    QLabel *label_time=new QLabel(time.toString(),itemWidget);
    label_time->setStyleSheet("color:gray;font-size:10px");
    label_time->setAlignment(Qt::AlignCenter);
    //6.创建时间+信息内容的组合
    QVBoxLayout *msgLayout=new QVBoxLayout();
    msgLayout->setSpacing(3);
    msgLayout->addWidget(label_time);
    msgLayout->addWidget(label_text);
    //7.位置
    if (isMine) {
        layout->addStretch();
        layout->addLayout(msgLayout);
        layout->addWidget(label_avatar);
    }else {
        layout->addWidget(label_avatar);
        layout->addLayout(msgLayout);
        layout->addStretch();
    }
    //8.添加到list
    QListWidgetItem *item=new QListWidgetItem(ui->listWidget_msg);
    item->setSizeHint(itemWidget->sizeHint());
    ui->listWidget_msg->addItem(item);
    ui->listWidget_msg->setItemWidget(item,itemWidget);
}

//4.添加一个文件气泡到窗口
void ChatPage::addFileMsg(const QString& avatarPath, const QDateTime& time, bool isMine,
                    const QString& fileName, const QString& filePath, const qint64& fileSize){
    // 1. 创建基础Widget和布局
    QWidget *itemWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(itemWidget);
    mainLayout->setContentsMargins(5, 5, 5, 5);
    // 2. 处理头像（复用原有圆形头像代码）
    QLabel *label_avatar = new QLabel(itemWidget);
    label_avatar->setFixedSize(50, 50);
    QPixmap avatarPixmap(avatarPath);
    avatarPixmap = avatarPixmap.scaled(50, 50, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    label_avatar->setPixmap(createCircularPix(avatarPixmap)); // 复用圆形处理
    // 3. 文件信息区域
    QWidget *fileInfoWidget = new QWidget(itemWidget);
    QVBoxLayout *fileLayout = new QVBoxLayout(fileInfoWidget);
    fileLayout->setContentsMargins(8, 8, 8, 8);
    fileLayout->setSpacing(4);
    // 3.1 文件类型图标（根据扩展名选择）
    QLabel *iconLabel = new QLabel();
    iconLabel->setPixmap(AppConfig::getFileTypeIcon(fileName).pixmap(32, 32));
    iconLabel->setAlignment(Qt::AlignLeft);
    // 3.2 文件名（带悬停效果）
    QLabel *nameLabel = new QLabel(QFileInfo(fileName).fileName());
    nameLabel->setStyleSheet(
        "QLabel {"
        "  font-weight: bold;"
        "  color: #333333;"
        "  padding-bottom: 2px;"
        "}"
        "QLabel:hover {"
        "  color: #0066cc;"
        "  text-decoration: underline;"
        "}"
    );
    // 3.3 文件大小和类型
    QLabel *metaLabel = new QLabel(QString("%1 • %2").
        arg(formatFileSize(fileSize),QFileInfo(fileName).suffix().toUpper()));
    metaLabel->setStyleSheet("color: #888888; font-size: 11px;");
    // 3.4 组装文件信息
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(iconLabel);
    topLayout->addWidget(nameLabel, 1);
    fileLayout->addLayout(topLayout);
    fileLayout->addWidget(metaLabel);
    // 4. 时间标签
    QLabel *timeLabel = new QLabel(time.toString("hh:mm"), itemWidget);
    timeLabel->setStyleSheet("color: #999999; font-size: 10px;");
    timeLabel->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    // 5. 主消息布局
    QVBoxLayout *msgLayout = new QVBoxLayout();
    msgLayout->addWidget(fileInfoWidget);
    msgLayout->addWidget(timeLabel, 0, Qt::AlignRight);
    // 6. 整体布局（根据发送方向调整）
    if (isMine) {
        mainLayout->addStretch();
        mainLayout->addLayout(msgLayout);
        mainLayout->addWidget(label_avatar);
    } else {
        mainLayout->addWidget(label_avatar);
        mainLayout->addLayout(msgLayout);
        mainLayout->addStretch();
    }
    // 7. 添加到消息列表
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget_msg);
    item->setSizeHint(itemWidget->sizeHint());
    // 存储原生路径（确保带反斜杠）
    item->setData(Qt::UserRole, filePath);
    // 调试输出
    qDebug() << "[UI添加] 存储路径:" << filePath
             << "\n文件是否存在:" << QFile::exists(filePath);
    ui->listWidget_msg->addItem(item);
    ui->listWidget_msg->setItemWidget(item, itemWidget);
    // 8. 点击事件处理
    connect(ui->listWidget_msg, &QListWidget::itemClicked, [](QListWidgetItem* item) {
        QString path = item->data(Qt::UserRole).toString();
        qDebug() << "[点击触发] 尝试打开:" << path
                 << "\n当前目录内容:" << QDir(AppConfig::getDownloadPath()).entryList();
        if (QFileInfo::exists(path)) {
            if (!QDesktopServices::openUrl(QUrl::fromLocalFile(path))) {
                qDebug() << "系统API打开失败，尝试直接启动...";
                QProcess::startDetached("explorer.exe", {"/select,", path});
            }
        } else {
            qDebug() << "文件不存在！检查路径是否正确";
            QMessageBox::warning(nullptr, "文件不存在",
                                 QString("文件路径无效：\n%1\n\n可能已经被移动或删除。").arg(path));
        }
    });
}

void ChatPage::updateDB(int senderId, int receiverId, const QString &content
, int contentType, const QDateTime &sendTime,int status, bool isRecalled) {
    m_db.addConversation(senderId,receiverId
        ,content,contentType,sendTime,status,false);
    m_db.upsertLastMessageBoth(senderId,receiverId,content
        ,sendTime,0,isRecalled);
}

//晃动指定的窗口
void ChatPage::shakeWindow(QWidget *targetWindow) {
    if (!targetWindow) return;
    const int shakeRange = 10;   // 左右偏移的最大距离
    const int duration = 300;    // 总动画时长（毫秒）
    const int shakeCount = 6;    // 抖动次数（应为偶数
    QPoint originalPos = targetWindow->pos();
    QPropertyAnimation *animation = new QPropertyAnimation(targetWindow, "pos");
    animation->setDuration(duration);
    animation->setEasingCurve(QEasingCurve::InOutQuad);  // 丝滑曲线
    for (int i = 0; i <= shakeCount; ++i) {
        double progress = static_cast<double>(i) / shakeCount;
        int offset = (i % 2 == 0) ? shakeRange : -shakeRange;
        animation->setKeyValueAt(progress, originalPos + QPoint(offset, 0));
    }
    animation->setKeyValueAt(1.0, originalPos); // 回到原位
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void ChatPage::handleFileMsg(const Protocol &msg) {
}

QString ChatPage::formatFileSize(qint64 bytes) {
    const qint64 KB = 1024;
    const qint64 MB = 1024 * 1024;
    const qint64 GB = 1024 * 1024 * 1024;
    const qint64 TB = 1024 * 1024 * 1024;
    if (bytes >= GB) return QString("%1 GB").arg(QString::
        number(bytes / (double)GB, 'f', 1));
    if (bytes >= MB) return QString("%1 MB").arg(QString::
        number(bytes / (double)MB, 'f', 1));
    if (bytes >= KB) return QString("%1 KB").arg(bytes / KB);
    return QString("%1 B").arg(bytes);
}

QPixmap ChatPage::createCircularPix(const QPixmap &source) {
    QPixmap circular(50,50);
    circular.fill(Qt::transparent);
    QPainter painter(&circular);
    painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
    QPainterPath path;
    path.addEllipse(0,0,50,50);//添加椭圆
    painter.setClipPath(path);
    painter.drawPixmap(0,0,source);
    return circular;
}

//1.按下发送文本的槽函数
void ChatPage::onSendText() {
    //1.获取输入文本
    QString text = ui->textEdit_input->toPlainText();
    if (text.isEmpty()) {
        QMessageBox::warning(this, "发送文本消息失败", "禁止发送空的文本消息");
        return;
    }
    //2.构造字节数组
    QByteArray data=Protocol::createTextMsg(m_curId,m_friendId,text);
    //3.日志
    QString log=QString("【发送者:%1】,【接收者:%2】,【类型:TEXT】,【内容:%3】"
        ).arg(m_curId).arg(m_friendId).arg(text);
    qDebug() << log;
    //4.发送
    m_socket->write(data);
    //5.添加己方气泡
    QDateTime now = QDateTime::currentDateTime();
    addTextMsg(m_curAvatar,now,true,text);
    //6.重置输入框状态
    ui->textEdit_input->clear();
    ui->textEdit_input->setFocus();
}

//2.按下发送图片的槽函数
void ChatPage::onSendImg() {
    //1.获取图片路径
    QString image=QFileDialog::getOpenFileName(this
        , "选择图片", "", "Images (*.png *.jpg *.jpeg *.bmp)");
    if (image.isEmpty()) {
        QMessageBox::warning(this, "发送图片消息失败", "图片路径禁止为空");
        return;
    }
    //2.构造字节数组
    QByteArray data=Protocol::createImageMsg(m_curId,m_friendId,image);
    //3.日志
    QString log=QString("【发送者:%1】,【接收者:%2】,【类型:IMAGE】,【内容:%3】"
        ).arg(m_curId).arg(m_friendId).arg(image);
    qDebug() << log;
    //4.发送
    m_socket->write(data);
    //5.添加己方气泡
    QDateTime now = QDateTime::currentDateTime();
    addImageMsg(m_curAvatar,now,true,image);
}

//3.按下发送窗口晃动的槽函数
void ChatPage::onSendShake() {
    //1.构造字节数组
    QByteArray data=Protocol::createShakeMsg(m_curId,m_friendId);
    //2.日志
    QString log=QString("【发送者:%1】,【接收者:%2】,【类型:SHAKE】"
        ).arg(m_curId).arg(m_friendId);
    qDebug() << log;
    //3.发送
    m_socket->write(data);
    //4.添加己方气泡
    QDateTime now = QDateTime::currentDateTime();
    addShakeMsg(m_curAvatar,now,true);
}

//4.按下发送文件的槽函数
void ChatPage::onSendFile() {
    //1.获取文件路径
    QString filePath=QFileDialog::getOpenFileName(this,
        "选择文件", "","所有文件 (*.*)");
    if (filePath.isEmpty()) return;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "错误", QString("文件打开失败: %1").arg(file.errorString()));
        return;
    }
    //2.打开并读取文件参数
    QFileInfo info(filePath);
    QString fileName=info.fileName();
    qint64 fileSize=file.size();
    //3.1 发送文件头
    QByteArray head=Protocol::createFileHeader(m_curId,m_friendId,fileName,fileSize);
    m_socket->write(head);
    QThread::msleep(100);//延时
    //3.2 分块读取并发送
    const int chunkSize=8192; //8KB
    while (!file.atEnd()) {
        QByteArray chunk=file.read(chunkSize);
        QByteArray chunkMsg=Protocol::createFileChunk(m_curId,m_friendId,chunk);
        m_socket->write(chunkMsg);
        QThread::msleep(20);//块之间延时
    }
    //3.2 发送文件结束
    QByteArray done=Protocol::createFileDone(m_curId,m_friendId);
    QThread::msleep(100); //防止最后一块没写完就done
    m_socket->write(done);
    file.close();
    //3.3 更新气泡
    QDateTime now = QDateTime::currentDateTime();
    addFileMsg(m_curAvatar, now, true, fileName, filePath, fileSize);
}

//按下截图的槽函数
void ChatPage::onScreenShot() {
    //1.截图当前窗口
    QPixmap screenShot=this->grab();
    //2.构造默认文件名和保存路径
    QString fileName=QString("【%1】与【%2】的聊天快照.png"
        ).arg(m_curNickname).arg(m_friendNickname);
    //3.选择路径
    QString path=QFileDialog::getSaveFileName(this,"选择聊天快照的保存地址",
        QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/"
        + fileName,"PNG 图像 (*.png);;JPEG 图像 (*.jpg *.jpeg);;所有文件 (*.*)"
    );
    if (path.isEmpty()) return;
    //4.弹出保存提示
    QMessageBox::StandardButton relay=QMessageBox::question(
        this,"保存截图",QString("是否保存截图为：\n%1")
        .arg(path),QMessageBox::Yes|QMessageBox::No);
    //5.判断选择结果并保存
    if (relay==QMessageBox::Yes) {
        if (screenShot.save(path)) {
            QMessageBox::information(this, "保存成功", "截图已保存到:\n" + path);
        } else {
            QMessageBox::warning(this, "保存失败", "无法保存截图。");
        }
    }
}

//按下主动连接的槽函数（作为client试图去连接好友的port）
void ChatPage::onConnectToHost() {
    m_client->connectToHost();
}

//对于主动连接做出的成功回应
void ChatPage::onConnected(int friendId) {
    qDebug()<<"有好友连接成功，id："<<friendId;
    ui->label_network->setText(QString(
        "网络:已作为client连接到【用户:%1】").arg(friendId));
}

//对于主动连接做出的失败回应
void ChatPage::onConnectFailed(int friendId) {
    qDebug()<<"有好友连接失败，id："<<friendId;
    ui->label_network->setText(QString(
        "网络:已从与【用户:%1】的网络连接中断开").arg(friendId));
}

void ChatPage::closeEvent(QCloseEvent *event) {
    //1.先移除注册（但不delete this）
    //2.清理Socket
    if (ChatManager::instance()->getSocket(m_curId,m_friendId)!=nullptr) {
        ChatManager::instance()->removeSocket(m_curId,m_friendId);
        qDebug()<<"已完成Socket的清理";
    }
    //3.清理Client
    if (ChatManager::instance()->getClient(m_curId,m_friendId)!=nullptr) {
        ChatManager::instance()->removeClient(m_curId,m_friendId);
        qDebug()<<"已完成Client的清理";
    }
    //4.延迟删除自身
    ChatManager::instance()->removeChatPage(m_curId,m_friendId);
    qDebug()<<"已完成ChatPage的标记清理";
    QWidget::closeEvent(event);
}

void ChatPage::onMsgFromMainPage(const QByteArray &data, int curId, int senderId) {
    //1.判断是否该本页面接收
    if (m_curId != curId || m_friendId != senderId) return;
    //2.解析消息
    QJsonObject obj=Protocol::parseMsg(data);
    //3.提取初步信息
    QString type=obj["type"].toString();
    int sender=obj["sender"].toInt();
    int receiver=obj["receiver"].toInt();
    //4.根据类型进行二次判断
    if (type == "text") {
        //4.1 日志
        QString text=obj["data"].toString();
        QString log_text=QString("二次解析：【发送者:%1】【接收者:%2】【类型:%3】【文本内容:%4】"
            ).arg(sender).arg(receiver).arg(type).arg(text);
        qDebug()<<log_text;
        //4.2 添加到气泡
        QDateTime now_text=QDateTime::currentDateTime();
        addTextMsg(m_friendAvatar,now_text,false,text);
        //4.3 数据库更新
        updateDB(senderId,curId,text,0,now_text,1,false);

    } else if (type == "image") {
        //4.1 日志
        QString image=obj["data"].toString();
        QString log_image=QString("二次解析：【发送者:%1】【接收者:%2】【类型:%3】【图片路径:%4】"
            ).arg(sender).arg(receiver).arg(type).arg(image);
        qDebug()<<log_image;
        //4.2 添加到气泡
        QDateTime now_image=QDateTime::currentDateTime();
        addImageMsg(m_friendAvatar,now_image,false,image);
        //4.3 数据库更新
        updateDB(senderId,curId,image,1,now_image,1,false);

    } else if (type == "shake") {
        //4.1 日志
        QString log_shake=QString("二次解析：【发送者:%1】【接收者:%2】【类型:%3】"
            ).arg(sender).arg(receiver).arg(type);
        qDebug()<<log_shake;
        //4.2 添加到气泡
        QDateTime now_shake=QDateTime::currentDateTime();
        addShakeMsg(m_friendAvatar,now_shake,false);
        //4.3 数据库更新
        updateDB(senderId,curId,"[窗口抖动]",2,now_shake,1,false);

    } else if (type == "fileHeader") {
        //4.1 解析文件参数
        QString fileName=obj["filename"].toString();
        qint64 fileSize=obj["filesize"].toString().toLongLong();
        //4.2 为成员变量赋值
        m_recvFileName=fileName;
        m_recvFileSize=fileSize;
        m_recvReceived=0;
        //4.3 日志
        QString log_fileHeader=QString(
            "二次解析：【发送者:%1】【接收者:%2】【类型:%3】【文件名:%4】【文件大小:%5】"
            ).arg(sender).arg(receiver).arg(type)
        .arg(m_recvFileName).arg(m_recvFileSize);
        qDebug()<<log_fileHeader;
        //4.4 构造保存位置
        QString savePath=AppConfig::getDownloadPath()+"/"+fileName;
        m_recvFile=new QFile(savePath);
        if (!m_recvFile->open(QIODevice::WriteOnly)) {
            qDebug()<<"文件保存失败:"<<m_recvFile->errorString();
            delete m_recvFile;
            m_recvFile= nullptr;
            return;
        }
        qDebug() << QString("开始接收文件：【%1】 大小：%2").arg(fileName).arg(fileSize);
    }else if (type == "fileChunk") {
        //4.1 检查待写入空文件是否已预备
        if (!m_recvFile)return;
        //4.2 读取并写入本次接收的字节数组块
        QByteArray chunk=QByteArray::fromBase64(obj["chunk"].toString().toUtf8());
        m_recvFile->write(chunk);
        m_recvReceived+=chunk.size();
        //4.3
        qDebug()<<QString("【已写入大小:%1/总大小:%2】");
    }else if (type == "fileDone") {
        //4.1 检查待写入空文件是否已预备
        if (!m_recvFile)return;
        //4.2 刷新并删除中间文件
        m_recvFile->flush();
        m_recvFile->close();
        delete m_recvFile;  // 由于是new，必须释放堆内存
        m_recvFile= nullptr;
        //4.3 日志
        qDebug() << QString("文件接收完成：【%1】 总大小：%2"
            ).arg(m_recvFileName).arg(m_recvFileSize);
        //4.4 更新气泡
        QDateTime now_file=QDateTime::currentDateTime();
        QString savePath=AppConfig::getDownloadPath()+"/"+m_recvFileName;
        addFileMsg(m_friendAvatar,now_file
            ,false,m_recvFileName,savePath,m_recvFileSize);
        //4.5 添加/更新数据库
        QString fileContent=m_recvFileName+"|"+savePath+"|"+QString::number(m_recvFileSize);
        updateDB(senderId,curId,fileContent,3,now_file,1,false);
    }
    else {
        qDebug()<<"未知的文件类型，放弃处理";
    }
}

