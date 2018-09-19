#pragma once

#include "common.h"
#include "streaminfo.h"
#include <QSharedPointer>


namespace Resonance {

namespace R3 {
class SerializedData;
}

class RESONANCE_API DataBlock
{
public:
    DataBlock();
    DataBlock(R3::SerializedData *data);
    DataBlock(const DataBlock &block);
    DataBlock &operator=(const DataBlock &block);

    StreamInfo info() const;
    void setInfo(StreamInfo info);

    bool isNull() const;
    R3::SerializedData* serialized() const;

    template<class T>
    inline T* type() const
    {
        return transmittable_type_cast<T>(m_info.type());
    }

private:
    friend class StreamReceiver;
    friend class StreamSender;
    friend class BlockStreaming;
    friend class RecorderThread;
    friend class Recorder;

    QSharedPointer<R3::SerializedData> data;
    StreamInfo m_info;

    DataBlock(QSharedPointer<R3::SerializedData> data);
};


}

Q_DECLARE_METATYPE(Resonance::DataBlock)
