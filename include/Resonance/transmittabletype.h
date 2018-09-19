#pragma once

#include "common.h"
#include <QJsonObject>
#include <functional>

namespace Resonance {

namespace R3 {
class SerializedData;
}

class RESONANCE_API TransmittableType
{
public:
    virtual R3::SerializedData* asConnectionHeader() { return nullptr; }
    virtual quint16 typeId() const { return 0; }
    virtual ~TransmittableType() {}
    virtual void updateReceivedTime(R3::SerializedData *data, quint64 now) { Q_UNUSED(data); Q_UNUSED(now); }
    virtual bool checkConnectionHeader(R3::SerializedData *header) { Q_UNUSED(header); return false; }

    //virtual bool compareConnectionHeader(R3::SerializedData *header) = 0;
    //virtual QJsonObject asJSON() = 0;

    //TransmittableType fromJSON() = 0;

    static TransmittableType* constructType(const R3::SerializedData &data);
    static int registerType(std::function<TransmittableType*(const R3::SerializedData&)> constructor);
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

