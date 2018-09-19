#pragma once

#include <Resonance/transmittabletype.h>
#include <Resonance/datablock.h>

namespace Resonance {

class RESONANCE_API Float64: public TransmittableType {
public:
    Float64(quint32 channels, double samplingRate);

    SD asConnectionHeader();

    quint16 typeId() const;
    static quint16 staticTypeId();

    void updateReceivedTime(SD data, quint64 now);
    bool checkConnectionHeader(SD header);
    static TransmittableType* construct(const SD &header);

    DataBlock fromBinary(quint64 time, int samples, double *buffer);
    quint32 channels() const;
    double samplingRate() const;

    QVector<double> extractSamples(const DataBlock &block) const;
    int samples(const DataBlock &block) const;
    quint64 created(const DataBlock &block) const;
    quint64 received(const DataBlock &block) const;

private:
    quint32 m_channels;
    double m_samplingRate;
};

}

