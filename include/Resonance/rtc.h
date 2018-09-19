#pragma once

#include "common.h"


namespace Resonance {

#ifdef QT_VERSION
typedef quint64 TimestampType;
#else
typedef unsigned long long TimestampType;
#endif

class RESONANCE_API RTC
{
protected:
    RTC();
public:
    static TimestampType now();
};

}

