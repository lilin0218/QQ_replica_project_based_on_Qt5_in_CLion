#ifndef ADDPAGE_H
#define ADDPAGE_H

#include <QWidget>
#include <qbuttongroup.h>
#include <qlistwidget.h>

#include "databasemanager.h"

namespace Ui {
class AddPage;
}

class AddPage : public QWidget
{
    Q_OBJECT

public:
    explicit AddPage(DatabaseManager& db, const int &curId,QWidget *parent = nullptr);
    ~AddPage();

signals:
    void refreshMainPageList();

private:
    Ui::AddPage *ui;
    //成员
    DatabaseManager& m_db;
    int m_curId;
    QWidget *lineIndicator = nullptr;
    QButtonGroup* categoryGroup;
    int m_state=0;
    //初始化
    void init();//初始化
    void initUnderLine();//初始化按钮下面的移动下划线
    void initListSelect();//初始化list切换
    void initSearch();//初始化搜索框
    void initClickAdd();//初始化点击item添加功能
    //方法
    void createItemWidget(QVariantMap friendInfo);

private slots:
    void search(const QString &partAccount);//搜索框文本变更时执行搜索
    void addStranger(QListWidgetItem *item);
    void removeFriend(QListWidgetItem *item);

protected:
    //重写拦截关闭事件
    void closeEvent(QCloseEvent *event)override;
};

#endif // ADDPAGE_H
