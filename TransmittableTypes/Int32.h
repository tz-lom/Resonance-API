#pragma once

#include <Resonance/outputstream.h>
#include <Resonance/transmittabletype.h>
#include <Resonance/datablock.h>
#include <QVector>

namespace Resonance {

class RESONANCE_API Int32: public TransmittableType {
public:
    Int32(quint32 channels, double samplingRate, double multiplier=1);
    virtual ~Int32();
    R3::SerializedData *asConnectionHeader();

    quint16 typeId() const;
    static quint16 staticTypeId();

    void updateReceivedTime(R3::SerializedData *data, quint64 now);
    bool checkConnectionHeader(R3::SerializedData *header);

    static TransmittableType* construct(const R3::SerializedData &header);

    //DataBlock from(qint32 *data);

protected:
    quint32 channels;
    double samplingRate;
    double multiplier;
};

}

