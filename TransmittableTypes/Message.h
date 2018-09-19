#pragma once

#include <Resonance/transmittabletype.h>
#include <Resonance/datablock.h>

namespace Resonance {

class RESONANCE_API Message: public TransmittableType {
public:
    Message();

    R3::SerializedData *asConnectionHeader();

    quint16 typeId() const;
    static quint16 staticTypeId();

    void updateReceivedTime(R3::SerializedData *data, quint64 now);
    bool checkConnectionHeader(R3::SerializedData *header);
    static TransmittableType* construct(const R3::SerializedData &header);

    DataBlock createMessage(QString text, quint64 time = 0);
    QString message(const DataBlock &block) const;

    quint64 created(const DataBlock &block) const;
};

}

