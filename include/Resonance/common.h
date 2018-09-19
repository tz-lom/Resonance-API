#pragma once

#ifdef RESONANCE_EXPORTS
    #define RESONANCE_API Q_DECL_EXPORT
#else
    #define RESONANCE_API Q_DECL_IMPORT
#endif
#define RESONANCE_API

#ifdef __MSVCRT__
    #define RESONANCE_API_COND
#else
    #define RESONANCE_API_COND
#endif

#if defined(__WIN32)||defined(__WIN64)
#define TARGET_OS_WINDOWS
#endif

