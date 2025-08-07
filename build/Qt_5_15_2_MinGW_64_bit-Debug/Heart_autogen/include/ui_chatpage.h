/********************************************************************************
** Form generated from reading UI file 'chatpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGE_H
#define UI_CHATPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_titleBar;
    QHBoxLayout *horizontalLayout;
    QLabel *label_friendName;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_voiceCall;
    QToolButton *toolButton_videoCall;
    QToolButton *toolButton_screenShare;
    QToolButton *toolButton_remoteAssistance;
    QToolButton *toolButton_groupChat;
    QToolButton *toolButton_more;
    QFrame *line;
    QWidget *widget_chatList;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_msg;
    QWidget *widget_bottomInputArea;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_inputToolBar;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_expression;
    QToolButton *toolButton_screenShot;
    QToolButton *toolButton_file;
    QToolButton *toolButton_img;
    QToolButton *toolButton_windowShake;
    QToolButton *toolButton_redEnvelope;
    QToolButton *toolButton_voice;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_BrowseHistory;
    QWidget *widget_input;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_input;
    QWidget *widget_buttonArea;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_connect;
    QLabel *label_network;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_close;
    QPushButton *pushButton_send;

    void setupUi(QWidget *ChatPage)
    {
        if (ChatPage->objectName().isEmpty())
            ChatPage->setObjectName(QString::fromUtf8("ChatPage"));
        ChatPage->resize(730, 887);
        ChatPage->setStyleSheet(QString::fromUtf8("/* \346\240\207\351\242\230\346\240\217\345\255\227\344\275\223\344\270\216\346\214\211\351\222\256 */\n"
"#widget_titleBar QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"#widget_titleBar QToolButton {\n"
"    background: transparent;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"#widget_titleBar QToolButton:hover {\n"
"    background-color: rgba(0, 0, 0, 20%);\n"
"}\n"
"\n"
"/* \350\201\212\345\244\251\350\256\260\345\275\225\345\214\272\345\237\237\357\274\210listWidget\357\274\211 */\n"
"QListWidget#listWidget_msg {\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* \350\201\212\345\244\251\350\276\223\345\205\245\346\241\206\347\233\270\345\205\263 */\n"
"#widget_bottomInputArea {\n"
"    background-color: rgba(255, 255, 255, 160);\n"
"    border-top: 1px solid #d0d0d0;\n"
"}\n"
"\n"
"/* \350\276\223\345\205\245\345\267\245\345\205\267\346\240\217\346\214\211\351\222\256\347\273\237\344\270\200"
                        "\351\243\216\346\240\274 */\n"
"#widget_inputToolBar QToolButton,\n"
"#widget_titleBar QToolButton {\n"
"    background: transparent;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"#widget_inputToolBar QToolButton:hover {\n"
"    background-color: rgba(0, 0, 0, 15%);\n"
"}\n"
"#widget_inputToolBar QToolButton:pressed {\n"
"    background-color: rgba(0, 0, 0, 20%);\n"
"}\n"
"\n"
"#widget_titleBar QToolButton:hover {\n"
"    background-color: rgba(0, 0, 0, 15%);\n"
"}\n"
"#widget_titleBar QToolButton:pressed {\n"
"    background-color: rgba(0, 0, 0, 20%);\n"
"}\n"
"\n"
"\n"
"/* \350\276\223\345\205\245\346\241\206\357\274\210lineEdit\357\274\211\346\240\267\345\274\217 */\n"
"QTextEdit#textEdit_input {\n"
"    background: transparent;\n"
"    border: 1px solid #c0c0c0;\n"
"    padding: 8px;\n"
"    font-size: 14px;\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* \345\272\225\351\203\250\346\214\211\351\222\256\345\214\272\345\237\237 */\n"
"#widget_buttonArea QPushButton {\n"
"    border: none;\n"
" "
                        "   padding: 6px 18px;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"#widget_buttonArea QPushButton:hover {\n"
"}\n"
"\n"
"/* \346\211\200\346\234\211 QToolButton \345\233\276\346\240\207\347\273\237\344\270\200\345\234\206\345\275\242\345\214\226 */\n"
"QToolButton {\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    padding: 4px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\345\233\276\346\240\207\345\234\206\345\272\225\350\211\262 */\n"
"QToolButton:hover {\n"
"    background-color: rgba(100, 100, 100, 10%);\n"
"}\n"
"\n"
"/* \345\205\263\351\227\255\346\214\211\351\222\256 */\n"
"#pushButton_close {\n"
"    background-color: transparent;\n"
"    border-radius: 6px;\n"
"}\n"
"#pushButton_close:hover {\n"
"    background-color: rgba(0, 0, 0, 25%);\n"
"}\n"
"#pushButton_close:pressed {\n"
"    background-color: rgba(0, 0, 0, 50%);\n"
"}\n"
"\n"
"/* \345\217\221\351\200\201\346\214\211\351\222\256 */\n"
"#pushButton_send"
                        " {\n"
"    background-color: #d3a4ff; /* \346\265\205\347\264\253 */\n"
"    color: white;\n"
"    padding: 6px 18px;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"}\n"
"#pushButton_send:hover {\n"
"    background-color: #b678ff;\n"
"}\n"
"#pushButton_send:pressed {\n"
"    background-color: #944dff;\n"
"}\n"
"\n"
"/* \350\277\236\346\216\245\346\214\211\351\222\256 */\n"
"/* \345\217\221\351\200\201\346\214\211\351\222\256 */\n"
"#pushButton_connect {\n"
"    background-color: #BCF6A6; /* \346\265\205\347\273\277 */\n"
"    color: white;\n"
"    padding: 6px 18px;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"}\n"
"#pushButton_connect:hover {\n"
"    background-color: #7BB963;\n"
"}\n"
"#pushButton_connect:pressed {\n"
"    background-color: #42B316;\n"
"}\n"
"\n"
""));
        verticalLayout_4 = new QVBoxLayout(ChatPage);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_titleBar = new QWidget(ChatPage);
        widget_titleBar->setObjectName(QString::fromUtf8("widget_titleBar"));
        horizontalLayout = new QHBoxLayout(widget_titleBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_friendName = new QLabel(widget_titleBar);
        label_friendName->setObjectName(QString::fromUtf8("label_friendName"));

        horizontalLayout->addWidget(label_friendName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_voiceCall = new QToolButton(widget_titleBar);
        toolButton_voiceCall->setObjectName(QString::fromUtf8("toolButton_voiceCall"));
        toolButton_voiceCall->setMinimumSize(QSize(40, 40));
        QFont font;
        font.setPointSize(12);
        toolButton_voiceCall->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/chat_icons/VoiceCall.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_voiceCall->setIcon(icon);
        toolButton_voiceCall->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(toolButton_voiceCall);

        toolButton_videoCall = new QToolButton(widget_titleBar);
        toolButton_videoCall->setObjectName(QString::fromUtf8("toolButton_videoCall"));
        toolButton_videoCall->setMinimumSize(QSize(40, 40));
        toolButton_videoCall->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/chat_icons/VideoCall.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_videoCall->setIcon(icon1);
        toolButton_videoCall->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(toolButton_videoCall);

        toolButton_screenShare = new QToolButton(widget_titleBar);
        toolButton_screenShare->setObjectName(QString::fromUtf8("toolButton_screenShare"));
        toolButton_screenShare->setMinimumSize(QSize(40, 40));
        toolButton_screenShare->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/chat_icons/ScreenSharing.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_screenShare->setIcon(icon2);
        toolButton_screenShare->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(toolButton_screenShare);

        toolButton_remoteAssistance = new QToolButton(widget_titleBar);
        toolButton_remoteAssistance->setObjectName(QString::fromUtf8("toolButton_remoteAssistance"));
        toolButton_remoteAssistance->setMinimumSize(QSize(40, 40));
        toolButton_remoteAssistance->setFont(font);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/chat_icons/RemoteAssistance.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_remoteAssistance->setIcon(icon3);
        toolButton_remoteAssistance->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(toolButton_remoteAssistance);

        toolButton_groupChat = new QToolButton(widget_titleBar);
        toolButton_groupChat->setObjectName(QString::fromUtf8("toolButton_groupChat"));
        toolButton_groupChat->setMinimumSize(QSize(40, 40));
        toolButton_groupChat->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/chat_icons/StartAGroupChat.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_groupChat->setIcon(icon4);
        toolButton_groupChat->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(toolButton_groupChat);

        toolButton_more = new QToolButton(widget_titleBar);
        toolButton_more->setObjectName(QString::fromUtf8("toolButton_more"));
        toolButton_more->setMinimumSize(QSize(40, 40));
        toolButton_more->setFont(font);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/chat_icons/More.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_more->setIcon(icon5);
        toolButton_more->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(toolButton_more);


        verticalLayout_4->addWidget(widget_titleBar);

        line = new QFrame(ChatPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        widget_chatList = new QWidget(ChatPage);
        widget_chatList->setObjectName(QString::fromUtf8("widget_chatList"));
        verticalLayout = new QVBoxLayout(widget_chatList);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_msg = new QListWidget(widget_chatList);
        listWidget_msg->setObjectName(QString::fromUtf8("listWidget_msg"));

        verticalLayout->addWidget(listWidget_msg);


        verticalLayout_4->addWidget(widget_chatList);

        widget_bottomInputArea = new QWidget(ChatPage);
        widget_bottomInputArea->setObjectName(QString::fromUtf8("widget_bottomInputArea"));
        widget_bottomInputArea->setMaximumSize(QSize(16777215, 300));
        verticalLayout_3 = new QVBoxLayout(widget_bottomInputArea);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 20);
        widget_inputToolBar = new QWidget(widget_bottomInputArea);
        widget_inputToolBar->setObjectName(QString::fromUtf8("widget_inputToolBar"));
        horizontalLayout_2 = new QHBoxLayout(widget_inputToolBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_expression = new QToolButton(widget_inputToolBar);
        toolButton_expression->setObjectName(QString::fromUtf8("toolButton_expression"));
        toolButton_expression->setMinimumSize(QSize(40, 40));
        toolButton_expression->setFont(font);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/chat_icons/Expression.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_expression->setIcon(icon6);
        toolButton_expression->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_expression);

        toolButton_screenShot = new QToolButton(widget_inputToolBar);
        toolButton_screenShot->setObjectName(QString::fromUtf8("toolButton_screenShot"));
        toolButton_screenShot->setMinimumSize(QSize(40, 40));
        toolButton_screenShot->setFont(font);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/chat_icons/Screenshots.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_screenShot->setIcon(icon7);
        toolButton_screenShot->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_screenShot);

        toolButton_file = new QToolButton(widget_inputToolBar);
        toolButton_file->setObjectName(QString::fromUtf8("toolButton_file"));
        toolButton_file->setMinimumSize(QSize(40, 40));
        toolButton_file->setFont(font);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/chat_icons/File.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_file->setIcon(icon8);
        toolButton_file->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_file);

        toolButton_img = new QToolButton(widget_inputToolBar);
        toolButton_img->setObjectName(QString::fromUtf8("toolButton_img"));
        toolButton_img->setMinimumSize(QSize(40, 40));
        toolButton_img->setFont(font);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/chat_icons/Picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_img->setIcon(icon9);
        toolButton_img->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_img);

        toolButton_windowShake = new QToolButton(widget_inputToolBar);
        toolButton_windowShake->setObjectName(QString::fromUtf8("toolButton_windowShake"));
        toolButton_windowShake->setMinimumSize(QSize(40, 40));
        toolButton_windowShake->setFont(font);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/chat_icons/WindowShaking.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_windowShake->setIcon(icon10);
        toolButton_windowShake->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_windowShake);

        toolButton_redEnvelope = new QToolButton(widget_inputToolBar);
        toolButton_redEnvelope->setObjectName(QString::fromUtf8("toolButton_redEnvelope"));
        toolButton_redEnvelope->setMinimumSize(QSize(40, 40));
        toolButton_redEnvelope->setFont(font);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/chat_icons/RedEnvelope.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_redEnvelope->setIcon(icon11);
        toolButton_redEnvelope->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_redEnvelope);

        toolButton_voice = new QToolButton(widget_inputToolBar);
        toolButton_voice->setObjectName(QString::fromUtf8("toolButton_voice"));
        toolButton_voice->setMinimumSize(QSize(40, 40));
        toolButton_voice->setFont(font);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/chat_icons/Voice.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_voice->setIcon(icon12);
        toolButton_voice->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_voice);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolButton_BrowseHistory = new QToolButton(widget_inputToolBar);
        toolButton_BrowseHistory->setObjectName(QString::fromUtf8("toolButton_BrowseHistory"));
        toolButton_BrowseHistory->setMinimumSize(QSize(40, 40));
        toolButton_BrowseHistory->setFont(font);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/chat_icons/BrowsingHistory.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_BrowseHistory->setIcon(icon13);
        toolButton_BrowseHistory->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_BrowseHistory);


        verticalLayout_3->addWidget(widget_inputToolBar);

        widget_input = new QWidget(widget_bottomInputArea);
        widget_input->setObjectName(QString::fromUtf8("widget_input"));
        verticalLayout_2 = new QVBoxLayout(widget_input);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit_input = new QTextEdit(widget_input);
        textEdit_input->setObjectName(QString::fromUtf8("textEdit_input"));
        textEdit_input->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(textEdit_input);


        verticalLayout_3->addWidget(widget_input);

        widget_buttonArea = new QWidget(widget_bottomInputArea);
        widget_buttonArea->setObjectName(QString::fromUtf8("widget_buttonArea"));
        horizontalLayout_3 = new QHBoxLayout(widget_buttonArea);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_connect = new QPushButton(widget_buttonArea);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setMinimumSize(QSize(120, 40));

        horizontalLayout_3->addWidget(pushButton_connect);

        label_network = new QLabel(widget_buttonArea);
        label_network->setObjectName(QString::fromUtf8("label_network"));

        horizontalLayout_3->addWidget(label_network);

        horizontalSpacer_3 = new QSpacerItem(519, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_close = new QPushButton(widget_buttonArea);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(80, 40));

        horizontalLayout_3->addWidget(pushButton_close);

        pushButton_send = new QPushButton(widget_buttonArea);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setMinimumSize(QSize(80, 40));

        horizontalLayout_3->addWidget(pushButton_send);


        verticalLayout_3->addWidget(widget_buttonArea);


        verticalLayout_4->addWidget(widget_bottomInputArea);


        retranslateUi(ChatPage);

        QMetaObject::connectSlotsByName(ChatPage);
    } // setupUi

    void retranslateUi(QWidget *ChatPage)
    {
        ChatPage->setWindowTitle(QCoreApplication::translate("ChatPage", "Form", nullptr));
        label_friendName->setText(QCoreApplication::translate("ChatPage", "\345\275\223\345\211\215\350\201\224\347\263\273\344\272\272\346\230\265\347\247\260", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_voiceCall->setToolTip(QCoreApplication::translate("ChatPage", "\350\257\255\351\237\263\351\200\232\350\257\235", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_voiceCall->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_videoCall->setToolTip(QCoreApplication::translate("ChatPage", "\350\247\206\351\242\221\351\200\232\350\257\235", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_videoCall->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_screenShare->setToolTip(QCoreApplication::translate("ChatPage", "\345\210\206\344\272\253\345\261\217\345\271\225", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_screenShare->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_remoteAssistance->setToolTip(QCoreApplication::translate("ChatPage", "\350\277\234\347\250\213\345\215\217\345\212\251", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_remoteAssistance->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_groupChat->setToolTip(QCoreApplication::translate("ChatPage", "\345\217\221\350\265\267\347\276\244\350\201\212", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_groupChat->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_more->setToolTip(QCoreApplication::translate("ChatPage", "\346\233\264\345\244\232", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_more->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_expression->setToolTip(QCoreApplication::translate("ChatPage", "\350\241\250\346\203\205", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_expression->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_screenShot->setToolTip(QCoreApplication::translate("ChatPage", "\346\210\252\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_screenShot->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_file->setToolTip(QCoreApplication::translate("ChatPage", "\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_file->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_img->setToolTip(QCoreApplication::translate("ChatPage", "\345\233\276\347\211\207", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_img->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_windowShake->setToolTip(QCoreApplication::translate("ChatPage", "\347\252\227\345\217\243\346\212\226\345\212\250", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_windowShake->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_redEnvelope->setToolTip(QCoreApplication::translate("ChatPage", "\347\272\242\345\214\205", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_redEnvelope->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_voice->setToolTip(QCoreApplication::translate("ChatPage", "\350\257\255\351\237\263", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_voice->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_BrowseHistory->setToolTip(QCoreApplication::translate("ChatPage", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_BrowseHistory->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_connect->setToolTip(QCoreApplication::translate("ChatPage", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_connect->setText(QCoreApplication::translate("ChatPage", "\345\217\221\350\265\267TCP\350\277\236\346\216\245", nullptr));
        label_network->setText(QCoreApplication::translate("ChatPage", "\347\275\221\347\273\234\347\212\266\346\200\201", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_close->setToolTip(QCoreApplication::translate("ChatPage", "\345\205\263\351\227\255\345\275\223\345\211\215\350\201\212\345\244\251", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_close->setText(QCoreApplication::translate("ChatPage", "\345\205\263\351\227\255", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_send->setToolTip(QCoreApplication::translate("ChatPage", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_send->setText(QCoreApplication::translate("ChatPage", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatPage: public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
