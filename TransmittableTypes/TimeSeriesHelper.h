#pragma once

#include <Resonance/streaminfo.h>
#include <Resonance/datablock.h>

namespace Resonance {

struct RESONANCE_API TimeSeriesHelper
{
    static bool checkType(const StreamInfo &info);
    static int channels(const StreamInfo &info);
    static int channels(const DataBlock &block);

    static double samplingRate(const StreamInfo &info);
    static QVector<QVector<double> > extractSamples(const DataBlock &block);
    static QVector<double> extractSamplesRowByRow(const DataBlock &block);
    static quint64 created(const DataBlock &block);
};

}
