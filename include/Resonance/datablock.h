#pragma once

#include "common.h"
#include "streaminfo.h"
#include <memory>


namespace Resonance {
namespace R3 {
namespace Thir {
class SerializedData;
}
typedef ::std::shared_ptr<SerializedData> SD;
}


class RESONANCE_API DataBlock
{
public:
    DataBlock();
    DataBlock(std::shared_ptr<R3::Thir::SerializedData> data);
    DataBlock(const DataBlock &block);
    DataBlock &operator=(const DataBlock &block);

    StreamInfo info() const;
    void setInfo(StreamInfo info);

    bool isNull() const;
    std::shared_ptr<R3::Thir::SerializedData> serialized() const;

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

    std::shared_ptr<R3::Thir::SerializedData> data;
    StreamInfo m_info;
};


}

Q_DECLARE_METATYPE(Resonance::DataBlock)
