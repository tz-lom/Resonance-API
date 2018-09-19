#pragma once

#include "common.h"
#include "streaminfo.h"
#include "inputstream.h"
#include <QHash>
#include <QFile>
#include <QVariantList>

namespace Resonance
{

class RESONANCE_API Recorder: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName)
    Q_PROPERTY(bool isOpen READ isOpen NOTIFY isOpenChanged)
    Q_PROPERTY(QVariantList recording READ recording NOTIFY streamsChanged)
public:
    explicit Recorder(QObject *parent =0);
    explicit Recorder(QString fileName, QVector<AbstractStream*> recordStreams, QObject *parent=0);

    QString fileName() const;

    bool isOpen() const;

    QVariantList recording() const;

public slots:
    void openFile(QString fileName);
    void closeFile();

    void addStream(StreamInfo info, QString name="");
    void addStream(AbstractStream *stream, QString name="");
    void addStream(QString url, QString name="");

    void blockReceived(DataBlock block);
    void streamDestroyed();

signals:
    void isOpenChanged();
    void streamsChanged();

protected slots:
    void streamReady();
    void streamNotFound(QObject *stream);

private:
    QFile file;
    QHash<AbstractStream*, int> streams;
    QHash<AbstractStream*, QString> waitingStreams;
    int streamId;
    bool m_isOpened;
};

}
