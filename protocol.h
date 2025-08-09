#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>

class Protocol {
public:
    enum MsgType {
        TEXT,
        IMAGE,
        SHAKE,
        Heart,
        FILE_HEADER,
        FILE_CHUNK,
        FILE_DONE
    };

    // 构建消息
    static QByteArray createTextMsg(int sender, int receiver, const QString& text);
    static QByteArray createImageMsg(int sender, int receiver, const QString& imagePath);
    static QByteArray createShakeMsg(int sender, int receiver);
    static QByteArray createHeartMsg(int sender, int receiver);
    static QByteArray createFileHeader(int sender, int receiver, const QString& filename, qint64 filesize);
    static QByteArray createFileChunk(int sender, int receiver, const QByteArray& chunkBase64);
    static QByteArray createFileDone(int sender, int receiver);

    // 解析消息(两个都需要保存，后者在初次解析使用，后者在二次解析使用)
    static QJsonObject parseMsg(const QByteArray& rawData); //旧版，解析单条
    static QList<QJsonObject> parseMultiMsg(const QByteArray& rawData); //新版，解析多条

    // 类型转字符串
    static QString typeToString(MsgType type);
};

#endif // PROTOCOL_H
