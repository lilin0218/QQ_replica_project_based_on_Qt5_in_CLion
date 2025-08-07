#include <QApplication>
#include "loginpage.h"
#include "databasemanager.h"
#include "addpage.h"
#include "appconfig.h"
#include "chatmanager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AppConfig::loadConfig();
    //测试对象
    // DatabaseManager temporary_db;
    // temporary_db.destroyDB();
    //初始化ChatManager
    ChatManager::instance();
    //主数据库对象
    DatabaseManager g_db;
    if (!g_db.isValid()) {  // 添加显式检查
     qFatal("Database initialization failed!");
     return -1;
    }
    // g_db.resetDB();
    LoginPage l(g_db);
    l.show();

    return QApplication::exec();
}
