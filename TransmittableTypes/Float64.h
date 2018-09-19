#pragma once

#include <Resonance/transmittabletype.h>
#include <Resonance/datablock.h>

namespace Resonance {

class RESONANCE_API Float64: public TransmittableType {
public:
    Float64(quint32 channels, double samplingRate);

    R3::SerializedData *asConnectionHeader();

    quint16 typeId() const;
    static quint16 staticTypeId();

    void updateReceivedTime(R3::SerializedData *data, quint64 now);
    bool checkConnectionHeader(R3::SerializedData *header);
    static TransmittableType* construct(const R3::SerializedData &header);

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

