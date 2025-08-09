//
// Created by 30496 on 25-8-6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DeveloperPage.h" resolved

#include "DeveloperPage.h"
#include <QMessageBox>
#include "ui_DeveloperPage.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

using namespace QtCharts;

DeveloperPage::DeveloperPage(DatabaseManager *db,QWidget *parent) :
    QWidget(parent), ui(new Ui::DeveloperPage) {
    ui->setupUi(this);
    m_db=db;

    init();
}

DeveloperPage::~DeveloperPage() {
    delete ui;
}

void DeveloperPage::init() {
    connect(ui->pushButton_destroyDB,&QPushButton::clicked,this,[=] {
        qDebug()<<"摧毁数据库";
        m_db->destroyDB();
    });
    connect(ui->pushButton_resetDB,&QPushButton::clicked,this,[=] {
        qDebug()<<"重置数据库";
        m_db->resetDB();
    });
    connect(ui->pushButton_pillarDiagram,&QPushButton::clicked,this,&DeveloperPage::generateBarChart);
    connect(ui->pushButton_pieChart,&QPushButton::clicked,this,&DeveloperPage::generatePieChart);
}

void DeveloperPage::generateBarChart() {
    qDebug()<<"生成柱图";
    QList<QVector<QString>> data = m_db->getUserFriendCountWithNick();
    if (data.isEmpty()) {
        QMessageBox::warning(this, "提示", "暂无数据可生成柱状图");
        return;
    }

    // 创建柱状图的系列
    QBarSeries *series = new QBarSeries();
    QBarSet *barSet = new QBarSet("好友数量");

    QStringList categories;
    for (const QVector<QString> &row : data) {
        categories << row[1];              // 昵称
        *barSet << row[2].toInt();         // 好友数
    }
    series->append(barSet);

    // 创建图表并添加系列
    auto *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("用户好友数量柱状图");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 设置 X 轴（用户昵称）
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setLabelsAngle(-90);  // 倾斜角度，防止遮挡
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 设置 Y 轴
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("好友数量");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 额外边距防止底部被遮挡
    chart->setMargins(QMargins(10, 10, 10, 40));

    // 显示图表窗口
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->setWindowTitle("柱状图");
    chartView->show();
}

void DeveloperPage::generatePieChart() {
    qDebug()<<"生成饼图";
    QList<QVector<QString>> data = m_db->getUserFriendCountWithNick();
    if (data.isEmpty()) {
        QMessageBox::warning(this, "提示", "暂无数据可生成饼图");
        return;
    }

    QPieSeries *series = new QPieSeries();

    for (const QVector<QString> &row : data) {
        QString nickname = row[1];
        int count = row[2].toInt();
        series->append(nickname, count);
    }

    // 设置爆炸效果
    for (QPieSlice *slice : series->slices()) {
        if (slice->percentage() > 0.1) {
            slice->setExploded(true);
            slice->setLabelVisible(true);
        }
    }

    // 创建图表并添加系列
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("用户好友数量饼图");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    // 显示图表窗口
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->setWindowTitle("饼图");
    chartView->show();
}
