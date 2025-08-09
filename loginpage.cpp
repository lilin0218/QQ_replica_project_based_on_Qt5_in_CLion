#include "loginpage.h"
#include <QFileDialog>
#include <ui_DeveloperPage.h>
#include "DeveloperPage.h"
#include "ui_loginpage.h"
#include "dynamicgradientbg.h"

LoginPage::LoginPage(DatabaseManager &dbManager, QWidget *parent):QWidget(parent),m_dbManager(dbManager),ui(new Ui::LoginPage) {
    ui->setupUi(this);
    init();
    initDeveloper();
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::init() {
    this->setWindowTitle("loginPage");
    //取消默认的顶部窗口
    this->setWindowFlag(Qt::FramelessWindowHint);
    //重写拖拽窗口的逻辑
    this->installEventFilter(new DragWidgetFilter(this));
    QVector<QString> icos = AppConfig::getIcoPath();
    this->setWindowIcon(QIcon(icos[1]));
    ui->lineEdit_password_login->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password_register->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password_cancel->setEchoMode(QLineEdit::Password);
    radioButtonAllSet();
    setButtonAllSet();
    closeButtonAllSet();
    okButtonAllSet();
    richTextLabelAllSet();
    generateTestUsers(m_dbManager);
    DatabaseManager::printAllUsers(m_dbManager);
    DynamicGradientBG::installDynamicGradientBG(this);
    connect(ui->toolButton_avatarSelect,&QToolButton::clicked,this,&LoginPage::avatarSelect);
}

void LoginPage::initDeveloper() {
    connect(ui->pushButton_sure,&QPushButton::clicked,this,[=] {
       QString password = ui->lineEdit_openDeveloper->text();
        if (password=="199108") {
            QMessageBox::information(this,"登录开发者界面","密码正确");
            auto *page = new DeveloperPage(&m_dbManager);
            page->show();
            ui->lineEdit_openDeveloper->clear();
        }else {
            QMessageBox::warning(this,"登录开发者界面","密码错误");
            ui->lineEdit_openDeveloper->clear();
            ui->lineEdit_openDeveloper->setFocus();
        }
    });
}

void LoginPage::radioButtonAllSet() {
    connect(ui->radioButton_makesure_login,&QRadioButton::clicked,this,[=]() {
        if (ui->radioButton_makesure_login->isChecked()) {
            ui->pushButton_ok_login->setStyleSheet("background-color: rgb(0, 141, 235);");
            ui->pushButton_ok_login->setEnabled(true);
        }else {
            ui->pushButton_ok_login->setStyleSheet("background-color: rgb(158, 218, 255);");
            ui->pushButton_ok_login->setEnabled(false);
        }
    });
    connect(ui->radioButton_makesure_register,&QRadioButton::clicked,this,[=]() {
        if (ui->radioButton_makesure_register->isChecked()) {
            ui->pushButton_ok_register->setStyleSheet("background-color: rgb(50,205,50);");
            ui->pushButton_ok_register->setEnabled(true);
        }else {
            ui->pushButton_ok_register->setStyleSheet("background-color: rgb(144,238,144);");
            ui->pushButton_ok_register->setEnabled(false);
        }
    });
    connect(ui->radioButton_makesure_cancel,&QRadioButton::clicked,this,[=]() {
        if (ui->radioButton_makesure_cancel->isChecked()) {
            ui->pushButton_ok_cancel->setStyleSheet("background-color: rgb(220,20,60);");
            ui->pushButton_ok_cancel->setEnabled(true);
        }else {
            ui->pushButton_ok_cancel->setStyleSheet("background-color: rgb(255,192,203);");
            ui->pushButton_ok_cancel->setEnabled(false);
        }
    });
}

void LoginPage::setButtonAllSet() {
    connect(ui->toolButton_set_login,&QToolButton::clicked,this,&LoginPage::openSettings);
    connect(ui->toolButton_set_register,&QToolButton::clicked,this,&LoginPage::openSettings);
    connect(ui->toolButton_set_cancel,&QToolButton::clicked,this,&LoginPage::openSettings);
}

void LoginPage::closeButtonAllSet() {
    connect(ui->toolButton_close_login,&QToolButton::clicked,this,&LoginPage::closePage);
    connect(ui->toolButton_close_register,&QToolButton::clicked,this,&LoginPage::closePage);
    connect(ui->toolButton_close_cancel,&QToolButton::clicked,this,&LoginPage::closePage);
}

void LoginPage::okButtonAllSet() {
    connect(ui->pushButton_ok_login,&QPushButton::clicked,this,[=] {
        this->checkLogin(m_dbManager);
    });
    connect(ui->pushButton_ok_register,&QPushButton::clicked,this,[=] {
        this->checkRegister(m_dbManager);
    });
    connect(ui->pushButton_ok_cancel,&QPushButton::clicked,this,[=] {
        this->checkCancel(m_dbManager);
    });
}

void LoginPage::richTextLabelAllSet() {
    richTextMakesureSet(ui->label_makesure_login);
    richTextMakesureSet(ui->label_makesure_register);
    richTextMakesureSet(ui->label_makesure_cancel);
    richTextExSet(ui->label_ex1_login,1);
    richTextExSet(ui->label_ex2_login,2);
    richTextExSet(ui->label_ex1_register,1);
    richTextExSet(ui->label_ex2_register,2);
    richTextExSet(ui->label_ex1_cancel,1);
    richTextExSet(ui->label_ex2_cancel,2);
}

void LoginPage::richTextMakesureSet(QLabel *label) {
    QString str_makesure=R"(<span>我已阅读并同意</span>
       <a href="user">《用户协议》</a>
       <span>和</span>
       <a href="privacy">《隐私政策》</a>)";
    label->setText(str_makesure);
    label->setTextFormat(Qt::RichText);//支持富文本
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);//支持点击
    label->setOpenExternalLinks(false);//禁止自动跳转
    //捕捉超链接点击事件
    connect(label,&QLabel::linkActivated,this,[=](const QString &link) {
        if (link=="user") {
            QMessageBox::information(this,link,"这里是用户协议的具体内容...");
        }else if (link=="privacy") {
            QMessageBox::information(this,link,"这里是隐私协议的具体内容...");
        }
    });
}

void LoginPage::richTextExSet(QLabel *label, int id) {
    QString str_ex1=R"(
       <a href="ex1">扫码登录</a>)";
    QString str_ex2=R"(
       <a href="ex2">更多选项</a>)";
    if (id==1) {
        label->setText(str_ex1);
    }else if (id==2) {
        label->setText(str_ex2);
    }
    label->setTextFormat(Qt::RichText);//支持富文本
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);//支持点击
    label->setOpenExternalLinks(false);//禁止自动跳转
    //捕捉超链接点击事件
    connect(label,&QLabel::linkActivated,this,[=](const QString &link) {
        if (id==1) {
            QMessageBox::information(this,link,"这里是扫码登录的具体内容...");
        }else if (id==2) {
            QMessageBox::information(this,link,"这里是更多选项的具体内容...");
        }
    });
}

void LoginPage::generateTestUsers(DatabaseManager& db) {
    const int userCount = 30;
    QVector<int> userIds;
    int successCount = 0;

    for (int i = 1; i <= userCount; ++i) {
        QString nickname = QString("测试用户%1").arg(i);
        QString account = QString("000%1").arg(i, 3, 10, QChar('0'));
        QString password = QString("Pwd%1%2").arg(i).arg(QRandomGenerator::global()->bounded(100, 999));
        QString avatar = QString(":/avatar/P (%1).jpg").arg(i);
        int status = QRandomGenerator::global()->bounded(0, 2);
        QString lastOnline = QDateTime::currentDateTime().addSecs(-QRandomGenerator::global()->bounded(3600)).toString(Qt::ISODate);
        QString signature = QString("个性签名%1").arg(i);
        int gender = QRandomGenerator::global()->bounded(0, 3);
        QString birthDate = QDate(1990 + QRandomGenerator::global()->bounded(0, 20),
                                  QRandomGenerator::global()->bounded(1, 13),
                                  QRandomGenerator::global()->bounded(1, 28)).toString("yyyy-MM-dd");

        if (db.addUserDetails(nickname, account, password, avatar, status, lastOnline, signature, gender, birthDate)) {
            // 获取新用户ID
            QSqlQuery query(db.getThreadLocalConnection());
            query.prepare("SELECT id FROM users WHERE account = ?");
            query.addBindValue(account);
            if (query.exec() && query.next()) {
                int userId = query.value(0).toInt();
                userIds.append(userId);

                // 添加若干好友
                int friendCount = QRandomGenerator::global()->bounded(3, 10);
                for (int j = 0; j < friendCount && userIds.size() > 1; ++j) {
                    int randomIndex = QRandomGenerator::global()->bounded(0, userIds.size());
                    int friendId = userIds[randomIndex];
                    if (friendId != userId) {
                        //先检查好友关系是否存在
                        if (!db.friendRelationExists(userId, friendId)) {
                            db.addFriendBoth(userId, friendId); // 双向添加好友关系

                            // 构造两条测试消息
                            QString msg1 = QString("你好编号%1，我是编号%2，收到消息请回应").arg(friendId).arg(userId);
                            QString msg2 = QString("你好编号%1，我是编号%2，这是我对你消息的回应").arg(userId).arg(friendId);

                            QDateTime time1 = QDateTime::currentDateTime();
                            QDateTime time2 = QDateTime::currentDateTime().addSecs(1);

                            // 插入两条消息（单向插入，仅从 userId -> friendId）
                            db.addConversation(userId, friendId, msg1, 0, time1, 1, false);
                            db.addConversation(friendId, userId, msg2, 0, time2, 1, false);

                            // 更新 lastMessages（只保留最后一条）
                            db.upsertLastMessageBoth(userId, friendId, msg2, time2,
                                                     QRandomGenerator::global()->bounded(0, 5), false);
                        }
                    }
                }

                successCount++;
            }
        }
    }

    qDebug() << "成功生成" << successCount << "/" << userCount << "个测试用户，好友+聊天+最近消息已同步生成";
}



bool LoginPage::checkLogin(DatabaseManager& db) {
    //1.获取字符串
    QString strAccount =ui->lineEdit_account_login->text().trimmed();
    QString strPassword =ui->lineEdit_password_login->text().trimmed();
    //2.本地校验
    QRegExp regAccount("^\\d{5,12}$");
    if (!regAccount.exactMatch(strAccount)) {
        QMessageBox::warning(this,"不合法的账号！","合法的账号应是由5~12位的纯数字构成");
        return false;
    }
    QRegExp regPassword("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{6,20}$");
    if (!regPassword.exactMatch(strPassword)) {
        QMessageBox::warning(this,"不合法的密码！","合法的密码应是由6~20位的数字或字母构成");
        return false;
    }
    //3.异步验证流程
    m_dbManager.userExistsAsync(strAccount,[=](bool exists) {
        if (!exists) {
            QMetaObject::invokeMethod(this,[=] {
                QMessageBox::warning(this,"登录失败","该账号不存在");
            });
            return;
        }
        m_dbManager.verifyLoginAsync(strAccount,strPassword,[=](bool success) {
            if (!success) {
                QMetaObject::invokeMethod(this,[=] {
                    QMessageBox::warning(this,"登录失败","输入的密码不对应此账号");
                });
                return;
            }
            m_dbManager.getUserNicknameAsync(strAccount,[=](const QString& strNickname) {
                QMetaObject::invokeMethod(this,[=] {
                    QString infoText=QString("登录的账号信息：【昵称：%1】【账号：%2】").arg(strNickname, strAccount);
                        QMessageBox::information(this,"登录账号成功",infoText);
                        int curId=m_dbManager.getUserId(strAccount);
                        MainPage *m=new MainPage(m_dbManager,curId);
                        m->show();
                });
            });
        });
    });
    ui->lineEdit_account_login->clear();
    ui->lineEdit_password_login->clear();
    ui->radioButton_makesure_login->setChecked(false);
    return true;
}

bool LoginPage::checkRegister(DatabaseManager& db) {
    //1.获取字符串
    QString strAccount =ui->lineEdit_account_register->text().trimmed();
    QString strPassword =ui->lineEdit_password_register->text().trimmed();
    QString strNickname=ui->lineEdit_nickname_register->text();
    //2.本地校验
    // 校验账号：5~12位纯数字
    QRegExp regAccount("^\\d{5,12}$");
    if (!regAccount.exactMatch(strAccount)) {
        QMessageBox::warning(this, "不合法的账号！", "合法的账号应是由5~12位的纯数字构成");
        return false;
    }
    // 校验密码：6~20位字母和数字的组合，必须包含字母和数字
    QRegExp regPassword("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{6,20}$");
    if (!regPassword.exactMatch(strPassword)) {
        QMessageBox::warning(this, "不合法的密码！", "合法的密码应是由6~20位的数字或字母构成，且必须包含字母和数字");
        return false;
    }
    // 校验昵称：长度1~20，只允许中英文和数字
    if (strNickname=="") {
        QMessageBox::warning(this, "不合法的昵称！", "昵称不可以为空");
        return false;
    }
    // 校验头像路径是否已选择
    if (m_avatar.isEmpty()) {
        QMessageBox::warning(this, "未选择头像！", "请点击头像区域选择一张图片");
        return false;
    }
    //3.异步验证流程
    m_dbManager.userExistsAsync(strAccount,[=](bool exists) {
        if (exists) {
            QMetaObject::invokeMethod(this,[=] {
                QMessageBox::warning(this,"注册失败","该账号已存在");
            });
            return;
        }
        m_dbManager.addUserAsync(strNickname,strAccount,strPassword,m_avatar,[=](bool success) {
            if (!success) {
                QMetaObject::invokeMethod(this,[=] {
                    QMessageBox::warning(this,"注册失败","添加用户时发生错误");
                });
                return;
            }
            QMetaObject::invokeMethod(this,[=] {
                QString infoText=QString("你的新账号信息：【昵称：%1】【账号：%2】【密码：%3】"
                    ).arg(strNickname, strAccount, strPassword);
                QMessageBox::information(this,"注册新账号成功",infoText);
            });
        });
    });
    ui->radioButton_makesure_register->setChecked(false);
    QIcon icon(AppConfig::getDefaultAvatar());
    ui->toolButton_avatarSelect->setIcon(icon);
    ui->lineEdit_nickname_register->clear();
    ui->lineEdit_account_register->clear();
    ui->lineEdit_password_register->clear();
    return true;
}

bool LoginPage::checkCancel(DatabaseManager& db) {
    //1.获取字符串
    QString strAccount =ui->lineEdit_account_cancel->text().trimmed();
    QString strPassword =ui->lineEdit_password_cancel->text().trimmed();
    //2.本地校验
    QRegExp regAccount("^\\d{5,12}$");
    if (!regAccount.exactMatch(strAccount)) {
        QMessageBox::warning(this,"不合法的账号！","合法的账号应是由5~12位的纯数字构成");
        return false;
    }
    QRegExp regPassword("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{6,20}$");
    if (!regPassword.exactMatch(strPassword)) {
        QMessageBox::warning(this,"不合法的密码！","合法的密码应是由6~20位的数字或字母构成");
        return false;
    }
    //3.异步验证流程
    m_dbManager.userExistsAsync(strAccount,[=](bool exists) {
       if (!exists) {
           QMetaObject::invokeMethod(this,[=] {
               QMessageBox::warning(this,"登录失败","该账号不存在");
           });
           return;
       }
       m_dbManager.verifyLoginAsync(strAccount,strPassword,[=](bool success) {
           if (!success) {
               QMetaObject::invokeMethod(this,[=] {
                   QMessageBox::warning(this,"登录失败","输入的密码不对应此账号");
               });
               return;
           }
           m_dbManager.deleteUserAsync(strAccount,[=](bool successful) {
               if (!successful) {
                    QMetaObject::invokeMethod(this,[=] {
                        QMessageBox::warning(this,"注销失败","删除用户时发生错误");
                    });
                   return;
               }
               m_dbManager.getUserNicknameAsync(strAccount,[=](const QString& strNickname) {
                   QMetaObject::invokeMethod(this,[=] {
                       QString infoText=QString("注销的账号信息：【昵称：%1】【账号：%2】").arg(strNickname, strAccount);
                       QMessageBox::information(this,"注销账号成功",infoText);
                   });
               });
           });
       });
    });
    ui->radioButton_makesure_cancel->setChecked(false);
    ui->lineEdit_account_cancel->clear();
    ui->lineEdit_password_cancel->clear();
    return true;
}

void LoginPage::openSettings() {
    QMessageBox::information(this,"设置","这是设置页面的内容");
}

void LoginPage::closePage() {
    this->close();
}

void LoginPage::avatarSelect() {
    QString avatar=QFileDialog::getOpenFileName(this, "选择头像"
        , "", "Images (*.png *.jpg *.bmp)");
    if (!avatar.isEmpty()) {
        m_avatar=avatar;
        QPixmap pixmap=QPixmap(avatar);
        ui->toolButton_avatarSelect->setIcon(pixmap.scaled(
            ui->toolButton_avatarSelect->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}
