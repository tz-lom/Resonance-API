#pragma once

#include "common.h"
#include <QObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QList>
#include "streaminfo.h"
#include "datablock.h"

namespace Resonance
{

class ServiceControlPrivate;
class RESONANCE_API ServiceControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QUuid uid READ uid)
    Q_PROPERTY(QJsonArray parameters READ parameters NOTIFY descriptionChanged)
    Q_PROPERTY(QString state READ state NOTIFY descriptionChanged)
    Q_PROPERTY(QJsonValue stateInfo READ stateInfo NOTIFY descriptionChanged)
    Q_PROPERTY(QStringList transitions READ transitions NOTIFY descriptionChanged)
public:
    explicit ServiceControl(QUuid uid, QString name, StreamInfo stream, QObject *parent=0);
    ~ServiceControl();

    QVector<StreamInfo> streams();
    QJsonArray parameters();

    QString state();
    QJsonValue stateInfo();
    QStringList transitions();

    bool isReady();

    QString name() const;
    QUuid uid() const;

public slots:
    void requestDescription();
    void sendParameter(const QJsonObject &parameter);
    void sendParameter(const QString name, QJsonValue value);
    void sendParameters(const QJsonArray &parameters);
    void sendTransition(QString name);

signals:
    void descriptionChanged();
    void ready();
    void nameChanged();

private slots:
    void blockReceived(DataBlock block);

private:
    ServiceControlPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(ServiceControl)
};

}

