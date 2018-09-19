#pragma once

#include <QObject>
#include <QCoreApplication>
#include "communicationlayer.h"
#include "servicediscovery.h"
#include "Parameters/all.h"
#include <QDir>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "recorder.h"

namespace Resonance {

class ResonanceAppPrivate;
class RESONANCE_API ResonanceApp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString serviceName READ serviceName)
public:
    explicit ResonanceApp(int &argc, char **argv, QString serviceName, const QList<QCommandLineOption> &commandLineOptions = QList<QCommandLineOption>(), bool isMain = true);
    explicit ResonanceApp(int &argc, char **argv, QString serviceName, bool isMain);
    static ResonanceApp* instance();

    const QCommandLineParser* commandLineParser();


    CommunicationLayer *comLayer() const;
    ServiceDiscovery *serviceDiscovery();

    int exec();

    QString serviceName() const;
    QUuid serviceUid() const;

    void setServiceName(QString name);

    quint16 portRangeBegin() const;
    quint16 portRangeEnd() const;

    QStringList tcpHostNames() const;
    QVector<QHostAddress> hostIPs() const;

public slots:
    void quit();
    void startRecord(QString fileName);
    void stopRecord();

    void __streamOpened(AbstractStream *stream);
    void __streamDestroyed(QObject *stream);

signals:
    void started();

private slots:
    void afterExec();

private:
    Q_DISABLE_COPY(ResonanceApp)
    ResonanceAppPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(ResonanceApp)
    static ResonanceApp *self;
};

}
