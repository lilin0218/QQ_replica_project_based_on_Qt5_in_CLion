#include "appconfig.h"

#include <QFileInfo>

QVector<QString> AppConfig::m_icoPath;
QVector<QString> AppConfig::m_avatarPath;
QVector<QString> AppConfig::m_chatIconsPath;
QString AppConfig::m_serverIp;
int AppConfig::m_serverPort;

AppConfig::AppConfig() {}

void AppConfig::loadConfig() {
    //加载MainPage的ico
    m_icoPath.push_back(":/ico/close.png");
    m_icoPath.push_back(":/ico/ikunlogo.png");
    m_icoPath.push_back(":/ico/qqlogo.png");
    m_icoPath.push_back(":/ico/set.png");
    //加载30个测试头像
    for (int i=0;i<30;i++) {
        QString strPath=QString(":/avatar/P (%1).jpg").arg(i+1);
        m_avatarPath.push_back(strPath);
    }
    //加载ChatPage界面的ico
    m_chatIconsPath.push_back(":/chat_icons/BrowsingHistory.png");
    m_chatIconsPath.push_back(":/chat_icons/Expression.png");
    m_chatIconsPath.push_back(":/chat_icons/File.png");
    m_chatIconsPath.push_back(":/chat_icons/More.png");
    m_chatIconsPath.push_back(":/chat_icons/Picture.png");
    m_chatIconsPath.push_back(":/chat_icons/RedEnvelope.png");
    m_chatIconsPath.push_back(":/chat_icons/ScreenSharing.png");
    m_chatIconsPath.push_back(":/chat_icons/Screenshots.png");
    m_chatIconsPath.push_back(":/chat_icons/StartAGroupChat.png");
    m_chatIconsPath.push_back(":/chat_icons/VideoCall.png");
    m_chatIconsPath.push_back(":/chat_icons/Voice.png");
    m_chatIconsPath.push_back(":/chat_icons/VoiceCall.png");
    m_chatIconsPath.push_back(":/chat_icons/WindowShaking.png");
    //加载网络配置
    m_serverIp.push_back("127.0.0.1");
    m_serverPort = 8848;
}

QVector<QString> AppConfig::getIcoPath() {
    return m_icoPath;
}

QVector<QString> AppConfig::getAvatarPath() {
    return m_avatarPath;
}

QVector<QString> AppConfig::getChatIconsPath() {
    return m_chatIconsPath;
}

QString AppConfig::getIconPathById(int index) {
    if (index >= 0 && index < m_icoPath.size()) {
        return m_icoPath[index];
    }
    return "";
}

QString AppConfig::getAvatarPathById(int index) {
    if (index >= 0 && index < m_avatarPath.size()) {
        return m_avatarPath[index];
    }
    return "";
}

int AppConfig::getServerPort(){
    return m_serverPort;
}

QIcon AppConfig::getFileTypeIcon(const QString &fileName) {
    // 获取文件扩展名（转换为小写）
    QString pureName = fileName.split('|').first();
    QString ext = QFileInfo(pureName).suffix().toLower();
    // 音频类型
    if (ext == "mp3" || ext == "wav" || ext == "flac" || ext == "aac") {
        return QIcon(":/file_icons/audio.png");
    }
    // 视频类型
    else if (ext == "mp4" || ext == "avi" || ext == "mov" || ext == "mkv") {
        return QIcon(":/file_icons/video.png");
    }
    // 图片类型
    else if (ext == "jpg" || ext == "jpeg" || ext == "png" ||
             ext == "gif" || ext == "bmp" || ext == "webp") {
        return QIcon(":/file_icons/image.png");
             }
    // 文档类型
    else if (ext == "pdf") {
        return QIcon(":/file_icons/pdf.png");
    }
    else if (ext == "doc" || ext == "docx") {
        return QIcon(":/file_icons/word.png");
    }
    else if (ext == "xls" || ext == "xlsx" || ext == "csv") {
        return QIcon(":/file_icons/excel.png");
    }
    else if (ext == "ppt" || ext == "pptx") {
        return QIcon(":/file_icons/ppt.png");
    }
    // 压缩包
    else if (ext == "zip" || ext == "rar" || ext == "7z" ||
             ext == "tar" || ext == "gz") {
        return QIcon(":/file_icons/compressedPackage.png");
             }
    // 代码文件
    else if (ext == "cpp" || ext == "h" || ext == "java" ||
             ext == "py" || ext == "js" || ext == "html" ||
             ext == "css" || ext == "xml" || ext == "json") {
        return QIcon(":/file_icons/code.png");
             }
    // 网页相关
    else if (ext == "html" || ext == "htm" || ext == "php") {
        return QIcon(":/file_icons/web.png");
    }
    // 文本文件
    else if (ext == "txt" || ext == "md" || ext == "log" || ext == "ini") {
        return QIcon(":/file_icons/text.png");
    }
    // 特殊类型
    else if (ext == "folder" || ext == "dir") { // 虚拟类型
        return QIcon(":/file_icons/folder.png");
    }
    // 未知类型
    return QIcon(":/file_icons/unknown.png");
}

QString AppConfig::getDownloadPath() {
    return {"C:/Users/30496/Downloads"};
}

QString AppConfig::getDefaultAvatar() {
    return ":/ico/SelectAvatar.png";
}

QString AppConfig::getServerIp(){
    return m_serverIp;
}

