/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *toolButton_set_login;
    QToolButton *toolButton_close_login;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_qqlogo_login;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_account_login;
    QLineEdit *lineEdit_password_login;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButton_makesure_login;
    QLabel *label_makesure_login;
    QPushButton *pushButton_ok_login;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_ex1_login;
    QFrame *line_2;
    QLabel *label_ex2_login;
    QSpacerItem *horizontalSpacer_10;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_set_register;
    QToolButton *toolButton_close_register;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_qqlogo_register;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_account_register;
    QLineEdit *lineEdit_password_register;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_makesure_register;
    QLabel *label_makesure_register;
    QPushButton *pushButton_ok_register;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_ex1_register;
    QFrame *line;
    QLabel *label_ex2_register;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_11;
    QToolButton *toolButton_set_cancel;
    QToolButton *toolButton_close_cancel;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_qqlogo_cancel;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget_13;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_account_cancel;
    QLineEdit *lineEdit_password_cancel;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_11;
    QRadioButton *radioButton_makesure_cancel;
    QLabel *label_makesure_cancel;
    QPushButton *pushButton_ok_cancel;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_ex1_cancel;
    QFrame *line_3;
    QLabel *label_ex2_cancel;
    QSpacerItem *horizontalSpacer_15;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QString::fromUtf8("LoginPage"));
        LoginPage->resize(454, 593);
        LoginPage->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	border: none;\n"
"}\n"
"\n"
"QToolButton#toolButton_close_login:hover{	\n"
"	background-color: rgb(255, 0, 0);\n"
"}\n"
"QToolButton#toolButton_close_register:hover{	\n"
"	background-color: rgb(255, 0, 0);\n"
"}\n"
"QToolButton#toolButton_close_cancel:hover{	\n"
"	background-color: rgb(255, 0, 0);\n"
"}\n"
"\n"
"QToolButton#toolButton_set_login:hover{	\n"
"	background-color: rgb(0, 0, 255);\n"
"}\n"
"QToolButton#toolButton_set_register:hover{	\n"
"	background-color: rgb(0, 0, 255);\n"
"}\n"
"QToolButton#toolButton_set_cancel:hover{\n"
"	background-color: rgb(0, 0, 255);\n"
"}\n"
"\n"
"QLabel#label_qqlogo_login{	\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:30px;\n"
"}\n"
"QLabel#label_qqlogo_register{	\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:30px;\n"
"}\n"
"QLabel#label_qqlogo_cancel{	\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:30px;\n"
"}\n"
"\n"
"QLineEdit#lineEdit_account_login{\n"
"	border:n"
                        "one;\n"
"	border-radius:15px;\n"
"}\n"
"QLineEdit#lineEdit_password_login{\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"QLineEdit#lineEdit_account_register{\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"QLineEdit#lineEdit_password_register{\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"QLineEdit#lineEdit_account_cancel{\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"QLineEdit#lineEdit_password_cancel{\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	border:none;	\n"
"	border-radius:15px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_ok_login{	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(158, 218, 255);\n"
"}\n"
"QPushButton#pushButton_ok_register{	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(144,238,144);\n"
"}\n"
"QPushButton#pushButton_ok_cancel{	\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(255,192,203);\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(LoginPage);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 10);
        tabWidget = new QTabWidget(LoginPage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_4 = new QWidget(tab);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_6 = new QSpacerItem(305, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        toolButton_set_login = new QToolButton(widget_4);
        toolButton_set_login->setObjectName(QString::fromUtf8("toolButton_set_login"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_set_login->setIcon(icon);
        toolButton_set_login->setAutoRaise(false);

        horizontalLayout_5->addWidget(toolButton_set_login);

        toolButton_close_login = new QToolButton(widget_4);
        toolButton_close_login->setObjectName(QString::fromUtf8("toolButton_close_login"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_close_login->setIcon(icon1);

        horizontalLayout_5->addWidget(toolButton_close_login);


        verticalLayout_4->addWidget(widget_4);

        widget_7 = new QWidget(tab);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        label_qqlogo_login = new QLabel(widget_7);
        label_qqlogo_login->setObjectName(QString::fromUtf8("label_qqlogo_login"));
        label_qqlogo_login->setPixmap(QPixmap(QString::fromUtf8(":/ico/qqlogo.png")));
        label_qqlogo_login->setScaledContents(false);
        label_qqlogo_login->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_qqlogo_login);

        horizontalSpacer_8 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_4->addWidget(widget_7);

        widget_8 = new QWidget(tab);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_2 = new QVBoxLayout(widget_8);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(30, -1, 30, -1);
        lineEdit_account_login = new QLineEdit(widget_8);
        lineEdit_account_login->setObjectName(QString::fromUtf8("lineEdit_account_login"));
        lineEdit_account_login->setMinimumSize(QSize(0, 40));
        lineEdit_account_login->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_account_login);

        lineEdit_password_login = new QLineEdit(widget_8);
        lineEdit_password_login->setObjectName(QString::fromUtf8("lineEdit_password_login"));
        lineEdit_password_login->setMinimumSize(QSize(0, 40));
        lineEdit_password_login->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_password_login);

        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_7 = new QHBoxLayout(widget_9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        radioButton_makesure_login = new QRadioButton(widget_9);
        radioButton_makesure_login->setObjectName(QString::fromUtf8("radioButton_makesure_login"));

        horizontalLayout_7->addWidget(radioButton_makesure_login);

        label_makesure_login = new QLabel(widget_9);
        label_makesure_login->setObjectName(QString::fromUtf8("label_makesure_login"));
        label_makesure_login->setCursor(QCursor(Qt::PointingHandCursor));
        label_makesure_login->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_makesure_login);


        verticalLayout_2->addWidget(widget_9);

        pushButton_ok_login = new QPushButton(widget_8);
        pushButton_ok_login->setObjectName(QString::fromUtf8("pushButton_ok_login"));
        pushButton_ok_login->setEnabled(false);
        pushButton_ok_login->setMinimumSize(QSize(0, 40));

        verticalLayout_2->addWidget(pushButton_ok_login);


        verticalLayout_4->addWidget(widget_8);

        widget_10 = new QWidget(tab);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_8 = new QHBoxLayout(widget_10);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        label_ex1_login = new QLabel(widget_10);
        label_ex1_login->setObjectName(QString::fromUtf8("label_ex1_login"));
        label_ex1_login->setCursor(QCursor(Qt::PointingHandCursor));
        label_ex1_login->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_ex1_login);

        line_2 = new QFrame(widget_10);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_2);

        label_ex2_login = new QLabel(widget_10);
        label_ex2_login->setObjectName(QString::fromUtf8("label_ex2_login"));
        label_ex2_login->setCursor(QCursor(Qt::PointingHandCursor));
        label_ex2_login->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_ex2_login);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout_4->addWidget(widget_10);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_6 = new QVBoxLayout(tab_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget = new QWidget(tab_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(305, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_set_register = new QToolButton(widget);
        toolButton_set_register->setObjectName(QString::fromUtf8("toolButton_set_register"));
        toolButton_set_register->setIcon(icon);
        toolButton_set_register->setAutoRaise(false);

        horizontalLayout->addWidget(toolButton_set_register);

        toolButton_close_register = new QToolButton(widget);
        toolButton_close_register->setObjectName(QString::fromUtf8("toolButton_close_register"));
        toolButton_close_register->setIcon(icon1);

        horizontalLayout->addWidget(toolButton_close_register);


        verticalLayout_6->addWidget(widget);

        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_qqlogo_register = new QLabel(widget_3);
        label_qqlogo_register->setObjectName(QString::fromUtf8("label_qqlogo_register"));
        label_qqlogo_register->setPixmap(QPixmap(QString::fromUtf8(":/ico/qqlogo.png")));
        label_qqlogo_register->setScaledContents(false);
        label_qqlogo_register->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_qqlogo_register);

        horizontalSpacer_3 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_6->addWidget(widget_3);

        widget_6 = new QWidget(tab_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout = new QVBoxLayout(widget_6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, -1, 30, -1);
        lineEdit_account_register = new QLineEdit(widget_6);
        lineEdit_account_register->setObjectName(QString::fromUtf8("lineEdit_account_register"));
        lineEdit_account_register->setMinimumSize(QSize(0, 40));
        lineEdit_account_register->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit_account_register);

        lineEdit_password_register = new QLineEdit(widget_6);
        lineEdit_password_register->setObjectName(QString::fromUtf8("lineEdit_password_register"));
        lineEdit_password_register->setMinimumSize(QSize(0, 40));
        lineEdit_password_register->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit_password_register);

        widget_2 = new QWidget(widget_6);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_makesure_register = new QRadioButton(widget_2);
        radioButton_makesure_register->setObjectName(QString::fromUtf8("radioButton_makesure_register"));

        horizontalLayout_2->addWidget(radioButton_makesure_register);

        label_makesure_register = new QLabel(widget_2);
        label_makesure_register->setObjectName(QString::fromUtf8("label_makesure_register"));
        label_makesure_register->setCursor(QCursor(Qt::PointingHandCursor));
        label_makesure_register->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_makesure_register);


        verticalLayout->addWidget(widget_2);

        pushButton_ok_register = new QPushButton(widget_6);
        pushButton_ok_register->setObjectName(QString::fromUtf8("pushButton_ok_register"));
        pushButton_ok_register->setEnabled(false);
        pushButton_ok_register->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_ok_register);


        verticalLayout_6->addWidget(widget_6);

        widget_5 = new QWidget(tab_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_ex1_register = new QLabel(widget_5);
        label_ex1_register->setObjectName(QString::fromUtf8("label_ex1_register"));
        label_ex1_register->setCursor(QCursor(Qt::PointingHandCursor));
        label_ex1_register->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_ex1_register);

        line = new QFrame(widget_5);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        label_ex2_register = new QLabel(widget_5);
        label_ex2_register->setObjectName(QString::fromUtf8("label_ex2_register"));
        label_ex2_register->setCursor(QCursor(Qt::PointingHandCursor));
        label_ex2_register->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_ex2_register);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_6->addWidget(widget_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget_11 = new QWidget(tab_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_9 = new QHBoxLayout(widget_11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_11 = new QSpacerItem(305, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);

        toolButton_set_cancel = new QToolButton(widget_11);
        toolButton_set_cancel->setObjectName(QString::fromUtf8("toolButton_set_cancel"));
        toolButton_set_cancel->setIcon(icon);
        toolButton_set_cancel->setAutoRaise(false);

        horizontalLayout_9->addWidget(toolButton_set_cancel);

        toolButton_close_cancel = new QToolButton(widget_11);
        toolButton_close_cancel->setObjectName(QString::fromUtf8("toolButton_close_cancel"));
        toolButton_close_cancel->setIcon(icon1);

        horizontalLayout_9->addWidget(toolButton_close_cancel);


        verticalLayout_7->addWidget(widget_11);

        widget_12 = new QWidget(tab_3);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_10 = new QHBoxLayout(widget_12);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_12 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);

        label_qqlogo_cancel = new QLabel(widget_12);
        label_qqlogo_cancel->setObjectName(QString::fromUtf8("label_qqlogo_cancel"));
        label_qqlogo_cancel->setPixmap(QPixmap(QString::fromUtf8(":/ico/qqlogo.png")));
        label_qqlogo_cancel->setScaledContents(false);
        label_qqlogo_cancel->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_qqlogo_cancel);

        horizontalSpacer_13 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_13);


        verticalLayout_7->addWidget(widget_12);

        widget_13 = new QWidget(tab_3);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        verticalLayout_3 = new QVBoxLayout(widget_13);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(30, -1, 30, -1);
        lineEdit_account_cancel = new QLineEdit(widget_13);
        lineEdit_account_cancel->setObjectName(QString::fromUtf8("lineEdit_account_cancel"));
        lineEdit_account_cancel->setMinimumSize(QSize(0, 40));
        lineEdit_account_cancel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_account_cancel);

        lineEdit_password_cancel = new QLineEdit(widget_13);
        lineEdit_password_cancel->setObjectName(QString::fromUtf8("lineEdit_password_cancel"));
        lineEdit_password_cancel->setMinimumSize(QSize(0, 40));
        lineEdit_password_cancel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_password_cancel);

        widget_14 = new QWidget(widget_13);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        horizontalLayout_11 = new QHBoxLayout(widget_14);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        radioButton_makesure_cancel = new QRadioButton(widget_14);
        radioButton_makesure_cancel->setObjectName(QString::fromUtf8("radioButton_makesure_cancel"));

        horizontalLayout_11->addWidget(radioButton_makesure_cancel);

        label_makesure_cancel = new QLabel(widget_14);
        label_makesure_cancel->setObjectName(QString::fromUtf8("label_makesure_cancel"));
        label_makesure_cancel->setCursor(QCursor(Qt::PointingHandCursor));
        label_makesure_cancel->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_makesure_cancel);


        verticalLayout_3->addWidget(widget_14);

        pushButton_ok_cancel = new QPushButton(widget_13);
        pushButton_ok_cancel->setObjectName(QString::fromUtf8("pushButton_ok_cancel"));
        pushButton_ok_cancel->setEnabled(false);
        pushButton_ok_cancel->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(pushButton_ok_cancel);


        verticalLayout_7->addWidget(widget_13);

        widget_15 = new QWidget(tab_3);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        horizontalLayout_12 = new QHBoxLayout(widget_15);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_14);

        label_ex1_cancel = new QLabel(widget_15);
        label_ex1_cancel->setObjectName(QString::fromUtf8("label_ex1_cancel"));
        label_ex1_cancel->setCursor(QCursor(Qt::PointingHandCursor));
        label_ex1_cancel->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_ex1_cancel);

        line_3 = new QFrame(widget_15);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_3);

        label_ex2_cancel = new QLabel(widget_15);
        label_ex2_cancel->setObjectName(QString::fromUtf8("label_ex2_cancel"));
        label_ex2_cancel->setCursor(QCursor(Qt::PointingHandCursor));
        label_ex2_cancel->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_ex2_cancel);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_15);


        verticalLayout_7->addWidget(widget_15);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_5->addWidget(tabWidget);


        retranslateUi(LoginPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        toolButton_set_login->setText(QString());
        toolButton_close_login->setText(QString());
        label_qqlogo_login->setText(QString());
        lineEdit_account_login->setPlaceholderText(QCoreApplication::translate("LoginPage", "\350\276\223\345\205\245QQ\345\217\267", nullptr));
        lineEdit_password_login->setPlaceholderText(QCoreApplication::translate("LoginPage", "\350\276\223\345\205\245QQ\345\257\206\347\240\201", nullptr));
        radioButton_makesure_login->setText(QString());
        label_makesure_login->setText(QCoreApplication::translate("LoginPage", "\345\267\262\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\343\200\212\346\234\215\345\212\241\345\215\217\350\256\256\343\200\213\345\222\214QQ\351\232\220\347\247\201\344\277\235\346\212\244\346\214\207\345\274\225", nullptr));
        pushButton_ok_login->setText(QCoreApplication::translate("LoginPage", "\347\231\273\345\205\245", nullptr));
        label_ex1_login->setText(QCoreApplication::translate("LoginPage", "\346\211\253\347\240\201\347\231\273\345\275\225", nullptr));
        label_ex2_login->setText(QCoreApplication::translate("LoginPage", "\346\233\264\345\244\232\351\200\211\351\241\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginPage", "\347\231\273\345\275\225", nullptr));
        toolButton_set_register->setText(QString());
        toolButton_close_register->setText(QString());
        label_qqlogo_register->setText(QString());
        lineEdit_account_register->setPlaceholderText(QCoreApplication::translate("LoginPage", "\350\276\223\345\205\245QQ\345\217\267", nullptr));
        lineEdit_password_register->setPlaceholderText(QCoreApplication::translate("LoginPage", "\350\276\223\345\205\245QQ\345\257\206\347\240\201", nullptr));
        radioButton_makesure_register->setText(QString());
        label_makesure_register->setText(QCoreApplication::translate("LoginPage", "\345\267\262\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\343\200\212\346\234\215\345\212\241\345\215\217\350\256\256\343\200\213\345\222\214QQ\351\232\220\347\247\201\344\277\235\346\212\244\346\214\207\345\274\225", nullptr));
        pushButton_ok_register->setText(QCoreApplication::translate("LoginPage", "\346\263\250\345\206\214", nullptr));
        label_ex1_register->setText(QCoreApplication::translate("LoginPage", "\346\263\250\345\206\214\351\241\273\347\237\245", nullptr));
        label_ex2_register->setText(QCoreApplication::translate("LoginPage", "\346\233\264\345\244\232\351\200\211\351\241\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("LoginPage", "\346\263\250\345\206\214", nullptr));
        toolButton_set_cancel->setText(QString());
        toolButton_close_cancel->setText(QString());
        label_qqlogo_cancel->setText(QString());
        lineEdit_account_cancel->setPlaceholderText(QCoreApplication::translate("LoginPage", "\350\276\223\345\205\245QQ\345\217\267", nullptr));
        lineEdit_password_cancel->setPlaceholderText(QCoreApplication::translate("LoginPage", "\350\276\223\345\205\245QQ\345\257\206\347\240\201", nullptr));
        radioButton_makesure_cancel->setText(QString());
        label_makesure_cancel->setText(QCoreApplication::translate("LoginPage", "\345\267\262\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\343\200\212\346\234\215\345\212\241\345\215\217\350\256\256\343\200\213\345\222\214QQ\351\232\220\347\247\201\344\277\235\346\212\244\346\214\207\345\274\225", nullptr));
        pushButton_ok_cancel->setText(QCoreApplication::translate("LoginPage", "\346\263\250\351\224\200", nullptr));
        label_ex1_cancel->setText(QCoreApplication::translate("LoginPage", "\346\263\250\351\224\200\351\241\273\347\237\245", nullptr));
        label_ex2_cancel->setText(QCoreApplication::translate("LoginPage", "\346\233\264\345\244\232\351\200\211\351\241\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("LoginPage", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
