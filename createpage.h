#ifndef CREATEPAGE_H
#define CREATEPAGE_H

#include <QWidget>
#include "databasemanager.h"

namespace Ui {
class CreatePage;
}

class CreatePage : public QWidget
{
    Q_OBJECT

public:
    explicit CreatePage(DatabaseManager& db, const int &curId,QWidget *parent = nullptr);
    ~CreatePage();

private:
    Ui::CreatePage *ui;
    DatabaseManager& m_db;
    int m_curId;
    void init();//初始化
};

#endif // CREATEPAGE_H
