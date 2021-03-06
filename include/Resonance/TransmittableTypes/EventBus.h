#pragma once

#include <Resonance/outputstream.h>
#include <Resonance/transmittabletype.h>
#include <Resonance/datablock.h>
#include <QVector>
#include <QJsonObject>
#include <QJsonArray>

namespace Resonance {

class RESONANCE_API EventBus: public TransmittableType {
public:
    virtual ~EventBus();
    SD asConnectionHeader();

    quint16 typeId() const;
    static quint16 staticTypeId();

    void updateReceivedTime(SD data, quint64 now);
    bool checkConnectionHeader(SD header);

    static TransmittableType* construct(const SD &header);

    DataBlock description(QUuid uid, const QVector<OutputStream *> &streams, const QJsonObject &parameters) const;
    DataBlock describeRequest() const;
    DataBlock applyParameters(const QJsonArray &params) const;
    DataBlock transition(QString name) const;

    bool isDescribeRequest(const DataBlock &block) const;
    bool isDescription(const DataBlock &block) const;
    bool isApplyParameters(const DataBlock &block) const;
    bool isTransition(const DataBlock &block) const;

    QJsonArray paramsToApply(const DataBlock &block) const;

    QUuid describedUid(const DataBlock &block) const;
    QJsonObject describedParams(const DataBlock &block) const;
    QVector<StreamInfo> describedStreams(const DataBlock &block) const;
    QString transitionName(const DataBlock &block) const;


};

}

