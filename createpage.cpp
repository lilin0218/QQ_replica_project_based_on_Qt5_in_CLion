#include "createpage.h"
#include "ui_createpage.h"
#include "dynamicgradientbg.h"
#include <QDebug>

CreatePage::CreatePage(DatabaseManager& db, const int &curId,QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::CreatePage), m_db(db),m_curId(curId) {
    ui->setupUi(this);
    init();
}

CreatePage::~CreatePage()
{
    delete ui;
}

void CreatePage::init() {
    this->setWindowTitle("createGroupPage");
    qDebug()<<"打开新的createGroupPage成功，当前页的id为：";
    DynamicGradientBG::installDynamicGradientBG(this);

}
