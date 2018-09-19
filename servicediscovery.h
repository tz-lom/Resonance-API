#pragma once

#include "common.h"
#include <QObject>
#include <QList>
#include "servicecontrol.h"
#include <QHostAddress>

namespace Resonance {

class ServiceDiscoveryPrivate;
class RESONANCE_API ServiceDiscovery: public QObject
{
    Q_OBJECT
public:
    explicit ServiceDiscovery(QObject *parent);
    ~ServiceDiscovery();
    QList<ServiceControl*> discovered() const;

Q_INVOKABLE ServiceControl *getService(QString name) const;

signals:
    void serviceLocated(Resonance::ServiceControl *sc);
    void serviceLost(int i);
    void startServiceDiscovery();

protected slots:
    void parceDatagram(QByteArray datagram, QHostAddress host);
    void serviceDestroyed(QObject *service);

private:
    ServiceDiscoveryPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(ServiceDiscovery)
};

}

