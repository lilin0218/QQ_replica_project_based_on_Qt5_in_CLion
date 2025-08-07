#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include "loginpage.h"
#include "databasemanager.h"
#include "appconfig.h"
#include <QPainter>
#include <QMessageBox>
#include <QRegularExpression>
#include <QInputDialog>
#include "mainpage.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QLabel>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    // 通过构造函数注入DatabaseManager依赖
    explicit LoginPage(DatabaseManager& dbManager, QWidget *parent = nullptr);
    ~LoginPage();

private:
    void init();
    void initDeveloper();//初始化开发者界面跳转逻辑
    DatabaseManager& m_dbManager;
    Ui::LoginPage *ui;
    QString m_avatar="";
    void radioButtonAllSet();
    void setButtonAllSet();
    void closeButtonAllSet();
    void okButtonAllSet();
    void richTextLabelAllSet();
    void richTextMakesureSet(QLabel *label);
    void richTextExSet(QLabel *label,int id);
    //生成20个测试用户数据，并初始化四个表的内容
    static void generateTestUsers(DatabaseManager& db);

private slots:
    bool checkLogin(DatabaseManager& db);
    bool checkRegister(DatabaseManager& db);
    bool checkCancel(DatabaseManager& db);
    void openSettings();
    void closePage();
    void avatarSelect();
};

//重写拖拽窗口的逻辑
class DragWidgetFilter : public QObject {
public:
    DragWidgetFilter(QObject *parent):QObject(parent){}
    bool eventFilter(QObject *obj, QEvent *e){
        auto w=dynamic_cast<QWidget*>(obj);
        if (!w) {
            return false;
        }
        if (e->type() == QEvent::MouseButtonPress) {
            auto ev=dynamic_cast<QMouseEvent*>(e);
            if (!ev) {
                return false;
            }
            pos=ev->pos();
        }else if (e->type() == QEvent::MouseMove) {
            auto ev=dynamic_cast<QMouseEvent*>(e);
            if (!ev) {
                return false;
            }
            if (ev->buttons()&Qt::MouseButton::LeftButton) {
                w->move(ev->globalPos()-pos);
            }
        }
        return QObject::eventFilter(obj,e);
    }
private:
    QPoint pos;
};

#endif // LOGINPAGE_H
