/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *Sidebar;
    QVBoxLayout *verticalLayout;
    QLabel *label_QQ9;
    QToolButton *toolButton_curAvatar;
    QLabel *label_curNickname;
    QToolButton *toolButton_msg;
    QToolButton *toolButton_contractPerson;
    QToolButton *toolButton_QQZone;
    QToolButton *toolButton_tencentChannel;
    QToolButton *toolButton_nineGrid;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButton_envelope;
    QToolButton *toolButton_folder;
    QToolButton *toolButton_collect;
    QToolButton *toolButton_threeBars;
    QWidget *MainArea;
    QVBoxLayout *verticalLayout_2;
    QWidget *TopBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_search;
    QLineEdit *lineEdit_search;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_more;
    QSpacerItem *horizontalSpacer_3;
    QListWidget *listWidget_main;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName(QString::fromUtf8("MainPage"));
        MainPage->resize(480, 720);
        MainPage->setMinimumSize(QSize(480, 720));
        MainPage->setStyleSheet(QString::fromUtf8("QWidget#Sidebar {\n"
"            background: qlineargradient(\n"
"                x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #fbb5e1, stop:1 #b4bdf7\n"
"            );\n"
"        }\n"
"\n"
"        QWidget#MainArea {\n"
"            background: qlineargradient(\n"
"                x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #fbc2e2, stop:1 #c1eac6\n"
"            );\n"
"        }\n"
"\n"
"        QToolButton {\n"
"            background: transparent;\n"
"            border-radius: 10px;\n"
"        }\n"
"        QToolButton:hover {\n"
"            background-color: rgba(255, 255, 255, 0.2);\n"
"        }\n"
"\n"
"        QLineEdit {\n"
"            background: #f1f1f1;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 12px;\n"
"            padding: 4px 10px;\n"
"        }\n"
"\n"
"        QPushButton {\n"
"            background: #fafafa;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 10px;\n"
"        }\n"
"\n"
"        QListWidget#listWidget_main "
                        "{\n"
"            background-color: transparent;\n"
"			background: qlineargradient(\n"
"                x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #e9a0c4, stop:1 #c1f0c0\n"
"            );\n"
"        }\n"
"\n"
"        /* \350\201\212\345\244\251\351\241\271 hover/pressed \346\225\210\346\236\234 */\n"
"        QWidget#ChatItem:hover {\n"
"            background-color: rgba(64,169,255,0.15); /* \346\265\205\350\223\235 */\n"
"        }\n"
"\n"
"        QWidget#ChatItem:pressed {\n"
"            background-color: rgba(64,169,255,0.25); /* \346\267\261\350\223\235 */\n"
"        }\n"
"\n"
"        QScrollBar:vertical {\n"
"            background: transparent;\n"
"            width: 6px;\n"
"        }\n"
"\n"
"        QScrollBar::handle:vertical {\n"
"            background: #c1c1c1;\n"
"            border-radius: 3px;\n"
"        }\n"
"\n"
"        QScrollBar::add-line, QScrollBar::sub-line {\n"
"            height: 0px;\n"
"        }"));
        horizontalLayout_2 = new QHBoxLayout(MainPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Sidebar = new QWidget(MainPage);
        Sidebar->setObjectName(QString::fromUtf8("Sidebar"));
        verticalLayout = new QVBoxLayout(Sidebar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_QQ9 = new QLabel(Sidebar);
        label_QQ9->setObjectName(QString::fromUtf8("label_QQ9"));
        label_QQ9->setMinimumSize(QSize(60, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Terminal"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_QQ9->setFont(font);
        label_QQ9->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_QQ9);

        toolButton_curAvatar = new QToolButton(Sidebar);
        toolButton_curAvatar->setObjectName(QString::fromUtf8("toolButton_curAvatar"));
        toolButton_curAvatar->setMinimumSize(QSize(70, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/ikunlogo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_curAvatar->setIcon(icon);
        toolButton_curAvatar->setIconSize(QSize(55, 55));

        verticalLayout->addWidget(toolButton_curAvatar);

        label_curNickname = new QLabel(Sidebar);
        label_curNickname->setObjectName(QString::fromUtf8("label_curNickname"));
        label_curNickname->setMinimumSize(QSize(50, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Terminal"));
        font1.setPointSize(7);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        font1.setKerning(true);
        label_curNickname->setFont(font1);
        label_curNickname->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_curNickname);

        toolButton_msg = new QToolButton(Sidebar);
        toolButton_msg->setObjectName(QString::fromUtf8("toolButton_msg"));
        toolButton_msg->setMinimumSize(QSize(70, 50));
        QFont font2;
        font2.setPointSize(12);
        toolButton_msg->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/msg.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_msg->setIcon(icon1);
        toolButton_msg->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_msg);

        toolButton_contractPerson = new QToolButton(Sidebar);
        toolButton_contractPerson->setObjectName(QString::fromUtf8("toolButton_contractPerson"));
        toolButton_contractPerson->setMinimumSize(QSize(70, 50));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/ContractPerson.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_contractPerson->setIcon(icon2);
        toolButton_contractPerson->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_contractPerson);

        toolButton_QQZone = new QToolButton(Sidebar);
        toolButton_QQZone->setObjectName(QString::fromUtf8("toolButton_QQZone"));
        toolButton_QQZone->setMinimumSize(QSize(70, 50));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ico/QQZone.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_QQZone->setIcon(icon3);
        toolButton_QQZone->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_QQZone);

        toolButton_tencentChannel = new QToolButton(Sidebar);
        toolButton_tencentChannel->setObjectName(QString::fromUtf8("toolButton_tencentChannel"));
        toolButton_tencentChannel->setMinimumSize(QSize(70, 50));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ico/TencentChannel.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_tencentChannel->setIcon(icon4);
        toolButton_tencentChannel->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_tencentChannel);

        toolButton_nineGrid = new QToolButton(Sidebar);
        toolButton_nineGrid->setObjectName(QString::fromUtf8("toolButton_nineGrid"));
        toolButton_nineGrid->setMinimumSize(QSize(70, 50));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ico/NineGrid.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_nineGrid->setIcon(icon5);
        toolButton_nineGrid->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_nineGrid);

        verticalSpacer = new QSpacerItem(20, 217, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        toolButton_envelope = new QToolButton(Sidebar);
        toolButton_envelope->setObjectName(QString::fromUtf8("toolButton_envelope"));
        toolButton_envelope->setMinimumSize(QSize(70, 50));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ico/Envelope.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_envelope->setIcon(icon6);
        toolButton_envelope->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_envelope);

        toolButton_folder = new QToolButton(Sidebar);
        toolButton_folder->setObjectName(QString::fromUtf8("toolButton_folder"));
        toolButton_folder->setMinimumSize(QSize(70, 50));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ico/Folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_folder->setIcon(icon7);
        toolButton_folder->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_folder);

        toolButton_collect = new QToolButton(Sidebar);
        toolButton_collect->setObjectName(QString::fromUtf8("toolButton_collect"));
        toolButton_collect->setMinimumSize(QSize(70, 50));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ico/Collect.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_collect->setIcon(icon8);
        toolButton_collect->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_collect);

        toolButton_threeBars = new QToolButton(Sidebar);
        toolButton_threeBars->setObjectName(QString::fromUtf8("toolButton_threeBars"));
        toolButton_threeBars->setMinimumSize(QSize(70, 50));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/ico/ThreeBars.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_threeBars->setIcon(icon9);
        toolButton_threeBars->setIconSize(QSize(30, 30));

        verticalLayout->addWidget(toolButton_threeBars);


        horizontalLayout_2->addWidget(Sidebar);

        MainArea = new QWidget(MainPage);
        MainArea->setObjectName(QString::fromUtf8("MainArea"));
        verticalLayout_2 = new QVBoxLayout(MainArea);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        TopBar = new QWidget(MainArea);
        TopBar->setObjectName(QString::fromUtf8("TopBar"));
        horizontalLayout = new QHBoxLayout(TopBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        toolButton_search = new QToolButton(TopBar);
        toolButton_search->setObjectName(QString::fromUtf8("toolButton_search"));
        toolButton_search->setMinimumSize(QSize(30, 30));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/ico/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_search->setIcon(icon10);

        horizontalLayout->addWidget(toolButton_search);

        lineEdit_search = new QLineEdit(TopBar);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));
        lineEdit_search->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(lineEdit_search);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_more = new QToolButton(TopBar);
        toolButton_more->setObjectName(QString::fromUtf8("toolButton_more"));
        toolButton_more->setMinimumSize(QSize(30, 30));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/ico/PlusSign.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_more->setIcon(icon11);
        toolButton_more->setAutoRaise(false);

        horizontalLayout->addWidget(toolButton_more);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(TopBar);

        listWidget_main = new QListWidget(MainArea);
        listWidget_main->setObjectName(QString::fromUtf8("listWidget_main"));

        verticalLayout_2->addWidget(listWidget_main);


        horizontalLayout_2->addWidget(MainArea);


        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Form", nullptr));
        label_QQ9->setText(QCoreApplication::translate("MainPage", "QQ9", nullptr));
        toolButton_curAvatar->setText(QString());
        label_curNickname->setText(QCoreApplication::translate("MainPage", "TextLabel", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_msg->setToolTip(QCoreApplication::translate("MainPage", "\350\201\212\345\244\251\345\210\227\350\241\250", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_msg->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_contractPerson->setToolTip(QCoreApplication::translate("MainPage", "\350\201\224\347\263\273\344\272\272", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_contractPerson->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_QQZone->setToolTip(QCoreApplication::translate("MainPage", "QQ\347\251\272\351\227\264", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_QQZone->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_tencentChannel->setToolTip(QCoreApplication::translate("MainPage", "\350\205\276\350\256\257\351\242\221\351\201\223", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_tencentChannel->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_nineGrid->setToolTip(QCoreApplication::translate("MainPage", "\344\271\235\345\256\253\346\240\274\357\274\237", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_nineGrid->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_envelope->setToolTip(QCoreApplication::translate("MainPage", "QQ\351\202\256\347\256\261", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_envelope->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_folder->setToolTip(QCoreApplication::translate("MainPage", "\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_folder->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_collect->setToolTip(QCoreApplication::translate("MainPage", "\346\224\266\350\227\217", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_collect->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_threeBars->setToolTip(QCoreApplication::translate("MainPage", "\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_threeBars->setText(QString());
        toolButton_search->setText(QString());
        lineEdit_search->setText(QString());
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("MainPage", "\351\224\256\345\205\245\345\205\263\351\224\256\350\257\215\344\273\245\347\255\233\351\200\211", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_more->setToolTip(QCoreApplication::translate("MainPage", "\346\226\260\345\242\236\350\201\224\347\263\273\344\272\272", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_more->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
