#pragma once

#include "common.h"

namespace Resonance {

class RESONANCE_API RTC
{
protected:
    RTC();
public:
#ifdef RESONANCE_STANDALONE
    typedef unsigned long long TimestampType; 
#else
    typedef quint64 TimestampType;
#endif
    static RESONANCE_API TimestampType now();
};

}

