#pragma once

#include "common.h"
#include "protocol.h"
#include <QJsonObject>
#include <QJsonValue>

namespace Resonance {

class Q_DECL_EXPORT JSONprotocol
{
public:
    static SD serializeObject(const QJsonObject &obj);

    static void constructObject(R3::JSON_Object::recursive rec, const QJsonObject &obj);
    static void constructArray(R3::JSON_Array::recursive rec, const QJsonArray &obj);

    static QJsonValue toValue(const R3::Thir::SerializedData &data);

    struct ConversionException{};
};

}

