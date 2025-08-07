/********************************************************************************
** Form generated from reading UI file 'createpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPAGE_H
#define UI_CREATEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatePage
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *TopBar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_search;
    QLineEdit *lineEdit_search;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_more;
    QFrame *line_2;
    QLabel *label_2;
    QFrame *line;
    QWidget *widget_menu;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *CreatePage)
    {
        if (CreatePage->objectName().isEmpty())
            CreatePage->setObjectName(QString::fromUtf8("CreatePage"));
        CreatePage->resize(406, 576);
        CreatePage->setStyleSheet(QString::fromUtf8("/* \351\241\266\351\203\250\346\220\234\347\264\242\346\240\217\350\203\214\346\231\257 */\n"
"QWidget#TopBar {\n"
"    background-color: rgba(255, 255, 255, 0.05);\n"
"    border-bottom: 1px solid rgba(255,255,255,0.2);\n"
"}\n"
"\n"
"/* QToolButton \346\220\234\347\264\242\345\233\276\346\240\207\346\214\211\351\222\256 */\n"
"QToolButton#toolButton_search {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    qproperty-iconSize: 18px;\n"
"}\n"
"QToolButton#toolButton_search:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"/* QLineEdit \346\220\234\347\264\242\346\241\206 */\n"
"QLineEdit#lineEdit_search {\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    border: 1px solid rgba(255, 255, 255, 0.3);\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    color: white;\n"
"}\n"
"QLineEdit#lineEdit_search:focus {\n"
"    border: 1px solid #1abc9c;\n"
"    background-color: rgba(255, 255, 255, 0.15);\n"
"}\n"
"\n"
"/* QLabel \346"
                        "\240\207\347\255\276 */\n"
"QLabel {\n"
"    font-weight: bold;\n"
"}\n"
"QLabel#label_more {\n"
"    color: #1abc9c;\n"
"    font-size: 13px;\n"
"}\n"
"QLabel#label_more:hover {\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"/* QPushButton \351\200\232\347\224\250\346\240\267\345\274\217 */\n"
"QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #3498db, stop:1 #2980b9);\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1abc9c;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #16a085;\n"
"}\n"
"\n"
"/* \345\217\226\346\266\210\346\214\211\351\222\256\347\211\271\345\214\226\346\240\267\345\274\217 */\n"
"QPushButton#pushButton_cancel {\n"
"    background-color: transparent;\n"
"    border: 1px solid #bdc3c7;\n"
"    color: #bdc3c7;\n"
"}\n"
"QPushButton#pushButton_cancel:hover {\n"
"    background-color: rgba(255,255,25"
                        "5,0.1);\n"
"    color: white;\n"
"    border: 1px solid white;\n"
"}\n"
"\n"
"/* \345\210\206\345\211\262\347\272\277 */\n"
"QFrame[orientation=\"Horizontal\"] {\n"
"    color: rgba(255, 255, 255, 0.2);\n"
"    background-color: rgba(255, 255, 255, 0.2);\n"
"    max-height: 1px;\n"
"}\n"
"\n"
"/* widget_menu \345\214\272\345\237\237\357\274\214\345\217\257\347\224\250\344\272\216\345\210\227\350\241\250\345\256\271\345\231\250\350\203\214\346\231\257 */\n"
"QWidget#widget_menu {\n"
"    background-color: rgba(255, 255, 255, 0.03);\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* QToolButton \345\212\250\346\225\210\357\274\214\345\216\273\351\231\244 transition */\n"
"QToolButton#toolButton_search:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"/* QLabel \351\274\240\346\240\207\346\202\254\346\265\256\346\225\210\346\236\234 */\n"
"QLabel#label_more:hover {\n"
"    color: #16a085; /* \346\233\264\346\224\271\344\270\272\346\202\254\346\265\256\346\227\266\351"
                        "\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* QLineEdit \345\222\214 QPushButton \351\274\240\346\240\207\346\202\254\346\265\256\346\225\210\346\236\234 */\n"
"QPushButton:hover, QLineEdit:hover {\n"
"    background-color: rgba(255, 255, 255, 0.15);\n"
"    border: 1px solid #1abc9c;\n"
"}\n"
"\n"
"/* QPushButton \351\200\211\344\270\255\346\227\266\347\232\204\346\225\210\346\236\234 */\n"
"QPushButton:checked {\n"
"    background-color: #16a085;\n"
"    border: none;\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(CreatePage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(CreatePage);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        TopBar = new QWidget(widget);
        TopBar->setObjectName(QString::fromUtf8("TopBar"));
        TopBar->setMinimumSize(QSize(362, 30));
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


        verticalLayout->addWidget(TopBar);

        line_3 = new QFrame(widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_more = new QLabel(widget);
        label_more->setObjectName(QString::fromUtf8("label_more"));

        horizontalLayout_3->addWidget(label_more);


        verticalLayout->addLayout(horizontalLayout_3);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widget_menu = new QWidget(widget);
        widget_menu->setObjectName(QString::fromUtf8("widget_menu"));
        widget_menu->setMinimumSize(QSize(0, 350));

        verticalLayout->addWidget(widget_menu);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(205, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(widget_2);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setEnabled(true);

        horizontalLayout->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(widget_2);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);


        verticalLayout->addWidget(widget_2);


        verticalLayout_2->addWidget(widget);


        retranslateUi(CreatePage);

        QMetaObject::connectSlotsByName(CreatePage);
    } // setupUi

    void retranslateUi(QWidget *CreatePage)
    {
        CreatePage->setWindowTitle(QCoreApplication::translate("CreatePage", "Form", nullptr));
        toolButton_search->setText(QString());
        lineEdit_search->setText(QString());
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("CreatePage", "\351\224\256\345\205\245\345\205\263\351\224\256\350\257\215\344\273\245\347\255\233\351\200\211", nullptr));
        label->setText(QCoreApplication::translate("CreatePage", "\346\214\211\345\210\206\347\261\273\345\210\233\345\273\272", nullptr));
        label_more->setText(QCoreApplication::translate("CreatePage", "\346\233\264\345\244\232  \357\274\236", nullptr));
        label_2->setText(QCoreApplication::translate("CreatePage", "\351\200\211\346\213\251\345\245\275\345\217\213\345\210\233\345\273\272", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("CreatePage", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("CreatePage", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatePage: public Ui_CreatePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPAGE_H
