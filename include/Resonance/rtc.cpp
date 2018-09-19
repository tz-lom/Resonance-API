#include "rtc.h"

using namespace Resonance;

#ifdef __APPLE__
#include <mach/mach_time.h>
RTC::TimestampType RTC::now()
{
    auto now = mach_absolute_time();

    static mach_timebase_info_data_t mt = {0,0};
    if(!mt.numer)
    {
        mach_timebase_info( &mt );
    }
    return now*mt.numer/mt.denom;
}

#elif defined _WIN32 || defined _WIN64
#include <windows.h>
RTC::TimestampType RTC::now()
{
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);

    static LARGE_INTEGER timeBase = {0,0};
    if(timeBase.QuadPart == 0)
    {
        QueryPerformanceFrequency(&timeBase); //@todo: change to exception
    }

    return (RTC::TimestampType)time.QuadPart * 1E9 / timeBase.QuadPart;
}

#else
#include <time.h>
RTC::TimestampType RTC::now() // returns NanoSeconds
{
    struct timespec t;
    ::clock_gettime( CLOCK_REALTIME, &t );
    return static_cast<RTC::TimestampType>(t.tv_sec)*1000000000 + static_cast<RTC::TimestampType>(t.tv_nsec);
}

#endif
