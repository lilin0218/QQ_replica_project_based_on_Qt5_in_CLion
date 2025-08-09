#include "Protocol.h"

QByteArray Protocol::createTextMsg(int sender, int receiver, const QString& text) {
    QJsonObject obj;
    obj["type"] = "text";
    obj["sender"] = sender;
    obj["receiver"] = receiver;
    obj["data"] = text;
    return QJsonDocument(obj).toJson();
}

QByteArray Protocol::createImageMsg(int sender, int receiver, const QString& imagePath) {
    QJsonObject obj;
    obj["type"] = "image";
    obj["sender"] = sender;
    obj["receiver"] = receiver;
    obj["data"] = imagePath;
    return QJsonDocument(obj).toJson();
}

QByteArray Protocol::createShakeMsg(int sender, int receiver) {
    QJsonObject obj;
    obj["type"] = "shake";
    obj["sender"] = sender;
    obj["receiver"] = receiver;
    obj["data"] = "shake";
    return QJsonDocument(obj).toJson();
}

QByteArray Protocol::createHeartMsg(int sender, int receiver) {
    QJsonObject obj;
    obj["type"] = "heart";
    obj["sender"] = sender;
    obj["receiver"] = receiver;
    obj["data"] = "heart";
    return QJsonDocument(obj).toJson();
}

QByteArray Protocol::createFileHeader(int sender, int receiver, const QString& filename, qint64 filesize) {
    QJsonObject obj;
    obj["type"] = "fileHeader";
    obj["sender"] = sender;
    obj["receiver"] = receiver;
    obj["filename"] = filename;
    obj["filesize"] = QString::number(filesize);
    return QJsonDocument(obj).toJson();
}

QByteArray Protocol::createFileChunk(int sender, int receiver, const QByteArray& chunkBase64) {
    QJsonObject obj;
    obj["type"] = "fileChunk";
    obj["sender"] = sender;
    obj["receiver"] = receiver;
    obj["chunk"] = QString::fromUtf8(chunkBase64.toBase64());
    return QJsonDocument(obj).toJson();
}

QByteArray Protocol::createFileDone(int sender, int receiver) {
    QJsonObject obj;
    obj["type"] = "fileDone";
    obj["sender"] = sender;
    obj["receiver"] = receiver;
    return QJsonDocument(obj).toJson();
}

QJsonObject Protocol::parseMsg(const QByteArray& rawData) {
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(rawData, &err);
    if (err.error != QJsonParseError::NoError || !doc.isObject()) {
        return QJsonObject(); // 返回空对象表示解析失败
    }
    return doc.object();
    qDebug() << "原始数据: " << rawData;

}

QList<QJsonObject> Protocol::parseMultiMsg(const QByteArray& rawData) {
    QList<QJsonObject> result;

    // 将原始字节数据转换为 UTF-8 字符串，方便用正则解析
    QString allData = QString::fromUtf8(rawData);

    // 用正则匹配所有 {} 括起来的 JSON 对象（非嵌套）
    QRegularExpression regex("\\{[^\\{\\}]*\\}");
    QRegularExpressionMatchIterator i = regex.globalMatch(allData);

    // 遍历所有匹配到的 JSON 子串
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();

        // 提取 JSON 字符串
        QString jsonStr = match.captured();

        // 尝试解析成 QJsonDocument
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &err);

        // 如果解析成功，且是一个 JSON 对象，就加入结果列表
        if (err.error == QJsonParseError::NoError && doc.isObject()) {
            result.append(doc.object());
        } else {
            qDebug() << "[parseMultiMsg] 解析失败：" << jsonStr;
        }
    }

    return result;
}



QString Protocol::typeToString(MsgType type) {
    switch (type) {
    case TEXT: return "text";
    case IMAGE: return "image";
    case SHAKE: return "shake";
    case Heart: return "heart";
    case FILE_HEADER: return "fileHeader";
    case FILE_CHUNK: return "fileChunk";
    case FILE_DONE: return "fileDone";
    default: return "unknown";
    }
}
