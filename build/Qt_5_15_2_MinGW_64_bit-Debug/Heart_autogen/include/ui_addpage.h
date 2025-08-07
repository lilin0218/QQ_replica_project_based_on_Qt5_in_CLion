/********************************************************************************
** Form generated from reading UI file 'addpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPAGE_H
#define UI_ADDPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPage
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *TopBar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_search;
    QLineEdit *lineEdit_search;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_all;
    QPushButton *pushButton_user;
    QPushButton *pushButton_group;
    QPushButton *pushButton_robot;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QWidget *widget_;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget_main;

    void setupUi(QWidget *AddPage)
    {
        if (AddPage->objectName().isEmpty())
            AddPage->setObjectName(QString::fromUtf8("AddPage"));
        AddPage->resize(796, 707);
        AddPage->setStyleSheet(QString::fromUtf8("/* \351\273\230\350\256\244\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"QPushButton {\n"
"    background: transparent;\n"
"    border: none;\n"
"    color: #7f8c8d;\n"
"    font-size: 16px;\n"
"    text-align: center;\n"
"}\n"
"QPushButton:hover {\n"
"    color: #9497dc;\n"
"}\n"
"\n"
"/* \351\200\211\344\270\255\346\214\211\351\222\256\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262\345\217\230\345\214\226 */\n"
"QPushButton:checked {\n"
"    color: #9497dc;\n"
"}\n"
"\n"
"/* \344\270\213\345\210\222\347\272\277\346\240\267\345\274\217 */\n"
"QPushButton::after {\n"
"    content: \"\";\n"
"    display: block;\n"
"    width: 0;\n"
"    height: 2px;\n"
"    background-color: #2980b9;\n"
"    transition: all 0.3s;\n"
"}\n"
"\n"
"/* \345\275\223\346\214\211\351\222\256\350\242\253\351\200\211\344\270\255\346\227\266\357\274\214\344\270\213\345\210\222\347\272\277\346\230\276\347\244\272 */\n"
"QPushButton:checked::after {\n"
"    width: 100%;\n"
"}\n"
"\n"
"/* \346\234\252\351\200\211\344\270"
                        "\255\346\227\266\344\270\213\345\210\222\347\272\277\351\232\220\350\227\217 */\n"
"QPushButton:not(:checked)::after {\n"
"    width: 0;\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(AddPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        TopBar = new QWidget(AddPage);
        TopBar->setObjectName(QString::fromUtf8("TopBar"));
        TopBar->setMinimumSize(QSize(0, 50));
        horizontalLayout_2 = new QHBoxLayout(TopBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolButton_search = new QToolButton(TopBar);
        toolButton_search->setObjectName(QString::fromUtf8("toolButton_search"));
        toolButton_search->setMinimumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_search->setIcon(icon);

        horizontalLayout_2->addWidget(toolButton_search);

        lineEdit_search = new QLineEdit(TopBar);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));
        lineEdit_search->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(lineEdit_search);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(TopBar);

        widget = new QWidget(AddPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_all = new QPushButton(groupBox);
        pushButton_all->setObjectName(QString::fromUtf8("pushButton_all"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_all->setFont(font);

        horizontalLayout->addWidget(pushButton_all);

        pushButton_user = new QPushButton(groupBox);
        pushButton_user->setObjectName(QString::fromUtf8("pushButton_user"));
        pushButton_user->setFont(font);

        horizontalLayout->addWidget(pushButton_user);

        pushButton_group = new QPushButton(groupBox);
        pushButton_group->setObjectName(QString::fromUtf8("pushButton_group"));
        pushButton_group->setFont(font);

        horizontalLayout->addWidget(pushButton_group);

        pushButton_robot = new QPushButton(groupBox);
        pushButton_robot->setObjectName(QString::fromUtf8("pushButton_robot"));
        pushButton_robot->setFont(font);

        horizontalLayout->addWidget(pushButton_robot);

        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(groupBox);


        verticalLayout_3->addWidget(widget);

        line = new QFrame(AddPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        widget_ = new QWidget(AddPage);
        widget_->setObjectName(QString::fromUtf8("widget_"));
        widget_->setMinimumSize(QSize(774, 500));
        widget_->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidget_main = new QListWidget(widget_);
        listWidget_main->setObjectName(QString::fromUtf8("listWidget_main"));

        verticalLayout_2->addWidget(listWidget_main);


        verticalLayout_3->addWidget(widget_);


        retranslateUi(AddPage);

        QMetaObject::connectSlotsByName(AddPage);
    } // setupUi

    void retranslateUi(QWidget *AddPage)
    {
        AddPage->setWindowTitle(QCoreApplication::translate("AddPage", "Form", nullptr));
        toolButton_search->setText(QString());
        lineEdit_search->setText(QString());
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("AddPage", "\351\224\256\345\205\245\345\205\263\351\224\256\350\257\215\344\273\245\347\255\233\351\200\211", nullptr));
        groupBox->setTitle(QString());
        pushButton_all->setText(QCoreApplication::translate("AddPage", "\345\205\250\351\203\250", nullptr));
        pushButton_user->setText(QCoreApplication::translate("AddPage", "\347\224\250\346\210\267", nullptr));
        pushButton_group->setText(QCoreApplication::translate("AddPage", "\347\276\244\350\201\212", nullptr));
        pushButton_robot->setText(QCoreApplication::translate("AddPage", "\346\234\272\345\231\250\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPage: public Ui_AddPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPAGE_H
