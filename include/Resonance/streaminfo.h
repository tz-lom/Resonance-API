#pragma once

#include "common.h"
#include <QJsonObject>
#include <QSharedPointer>
#include <QUuid>
#include <QUrl>

#include "transmittabletype.h"

namespace Resonance {

namespace R3 {
class SerializedData;
}

class StreamInfoPrivate;
class RESONANCE_API StreamInfo
{
    Q_GADGET
    Q_PROPERTY(QUuid uid READ uid)
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QList<QUrl> connections READ connections)
    Q_PROPERTY(QByteArray typeSerialized READ typeSerialized)

public:
    StreamInfo();
    ~StreamInfo();
    StreamInfo(const StreamInfo &other);
    StreamInfo(const QUrl url);
    StreamInfo(const QString name, TransmittableType *type);
    StreamInfo(const QString name, const QUuid uid);
    StreamInfo(const QString name, const QUuid uid, TransmittableType *type, const QUrl url);

    static StreamInfo discoveredService(QUuid uid, QUrl url);
    static StreamInfo describedStream(QUuid uid, QString name, TransmittableType *type, QList<QUrl> urls);
    static StreamInfo fromJson(const QJsonObject &obj);

    StreamInfo& operator=( const StreamInfo &other);
    bool operator==(const StreamInfo &info);
    bool isNull() const;

    QUuid uid() const;
    QString name() const;

    QList<QUrl> connections();
    void addConnection(QUrl url);
    StreamInfo setConnection(QUrl url);

    quint16 tcpPort() const; // @todo: remove that method
    TransmittableType *type() const;

    QByteArray typeSerialized() const;
    R3::SerializedData* serialized() const;

    Q_INVOKABLE QJsonObject toJson() const;

private:

    StreamInfo(StreamInfoPrivate* info);
    QSharedPointer<StreamInfoPrivate> d;
};

}

inline QDebug &operator<<(QDebug debug, Resonance::StreamInfo &i)
{
    debug.nospace() << "StreamInfo("<< i.toJson() << ")";
    return debug.maybeSpace();
}

Q_DECLARE_METATYPE(Resonance::StreamInfo)
