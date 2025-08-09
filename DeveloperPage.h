//
// Created by 30496 on 25-8-6.
//

#ifndef DEVELOPERPAGE_H
#define DEVELOPERPAGE_H

#include <QWidget>
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DeveloperPage; }
QT_END_NAMESPACE

class DeveloperPage : public QWidget {
Q_OBJECT

public:
    explicit DeveloperPage(DatabaseManager *db,QWidget *parent = nullptr);
    ~DeveloperPage() override;

private:
    Ui::DeveloperPage *ui;
    DatabaseManager *m_db;

    void init();

private slots:
    void generateBarChart();
    void generatePieChart();
};


#endif //DEVELOPERPAGE_H
