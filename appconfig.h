#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QIcon>
#include <QString>
#include <QVector>
class AppConfig
{
public:
    AppConfig();
    static QVector<QString> m_icoPath;
    static QVector<QString> m_avatarPath;
    static QVector<QString> m_chatIconsPath;
    static QString m_serverIp;
    static int m_serverPort;
    static void loadConfig();
    static QVector<QString> getIcoPath();
    static QVector<QString> getAvatarPath();
    static QVector<QString> getChatIconsPath();
    static QString getIconPathById(int index);
    static QString getAvatarPathById(int index);
    static QString getServerIp();
    static int getServerPort();
    //根据文件类型选择图标
    static QIcon getFileTypeIcon(const QString& fileName);
    static QString getDownloadPath();
    static QString getDefaultAvatar();
};

#endif // APPCONFIG_H
