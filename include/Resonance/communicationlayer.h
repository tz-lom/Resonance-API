#pragma once

#include "common.h"
#include <QObject>
#include "outputstream.h"
#include "Parameters/all.h"
#include <QJsonValue>
#include <QHostAddress>

namespace Resonance {

class CommunicationLayerPrivate;
/*!
 * \brief The CommunicationLayer class
 *
 * Responsible for all communication in system
 */
class RESONANCE_API CommunicationLayer : public QObject
{
    Q_OBJECT
public:
    explicit CommunicationLayer(const QString &serviceName, QObject *parent = 0);
    ~CommunicationLayer();

    void registerStream(OutputStream *stream);
    QVector<OutputStream*> streams();

    void addParameter(Parameters::Parameter *param);

    bool applyParameters(const QJsonArray &list);

    void setState(QString state, QJsonValue metaInfo = QJsonValue());
    void setTransitions(QStringList transitions);

signals:
    void performTransition(QString name);

    void parseBroadcast(QByteArray datagram, QHostAddress host);

private slots:
    void broadcastMessage();
    void clientRequest(DataBlock block);
    void streamDestroyed();

    void parameterDestroyed();
    void startServiceDiscovery();

private:
    CommunicationLayerPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(CommunicationLayer)

    void sendDescription();
};

}

