#pragma once

#include <Resonance/transmittabletype.h>
#include <Resonance/datablock.h>

namespace Resonance {

class RESONANCE_API Message: public TransmittableType {
public:
    Message();

    SD asConnectionHeader();

    quint16 typeId() const;
    static quint16 staticTypeId();

    void updateReceivedTime(SD data, quint64 now);
    bool checkConnectionHeader(SD header);
    static TransmittableType* construct(const SD &header);

    DataBlock createMessage(QString text, quint64 time = 0);
    QString message(const DataBlock &block) const;

    quint64 created(const DataBlock &block) const;
};

}

