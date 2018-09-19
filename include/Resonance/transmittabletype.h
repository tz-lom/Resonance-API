#pragma once

#include "common.h"
#include <QJsonObject>
#include <functional>
#include "protocol.h"

namespace Resonance {

namespace R3 {
class SerializedData;
}

class RESONANCE_API TransmittableType
{
public:
    virtual SD asConnectionHeader() { return nullptr; }
    virtual quint16 typeId() const { return 0; }
    virtual ~TransmittableType() {}
    virtual void updateReceivedTime(SD data, quint64 now) { Q_UNUSED(data); Q_UNUSED(now); }
    virtual bool checkConnectionHeader(SD header) { Q_UNUSED(header); return false; }

    //virtual bool compareConnectionHeader(SD header) = 0;
    //virtual QJsonObject asJSON() = 0;

    //TransmittableType fromJSON() = 0;

    static TransmittableType* constructType(const SD &data);
    static int registerType(std::function<TransmittableType*(const SD&)> constructor);
};

template <class T>
inline T* transmittable_type_cast(const TransmittableType *type)
{
    if(type->typeId() != T::staticTypeId() )
    {
        return 0;
    }
    return static_cast<T*>(const_cast<TransmittableType*>(type));
}

}

