#ifndef SCRIPT_ENGINE_INTERFACE
#define SCRIPT_ENGINE_INTERFACE

#include <cstddef>

#if defined(_MSC_VER)
#  define EXPORT __declspec(dllexport)
#  define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#  define EXPORT __attribute__((visibility("default")))
#  define IMPORT
#else
#  define EXPORT
#  define IMPORT
#  pragma warning Unknown dynamic link import/export semantics.
#endif

#ifdef IMPORT_ENGINE
#  define RESONANCE_SCRIPT_ENGINE_INTERFACE(ret,name,args) typedef ret (*name##_t)args;
#else
#  define RESONANCE_SCRIPT_ENGINE_INTERFACE(ret,name,args) EXPORT ret name args;
#endif

extern "C" {

typedef struct {
    const char *data;
    size_t size;
} SerializedDataContainer;

typedef struct {
    int (*declareStream)(const char *name, const SerializedDataContainer type);
    bool (*sendBlock)(const int id, const SerializedDataContainer block);
} InterfacePointers;

RESONANCE_SCRIPT_ENGINE_INTERFACE(const char*, engineName, ())
RESONANCE_SCRIPT_ENGINE_INTERFACE(bool, initializeEngine, (
        InterfacePointers ip,
        const char *code,
        size_t codeLength))
RESONANCE_SCRIPT_ENGINE_INTERFACE(void, freeEngine,())
RESONANCE_SCRIPT_ENGINE_INTERFACE(bool, prepareEngine, (
        const char *code,
        size_t codeLength,
        const SerializedDataContainer* const streams,
        size_t streamCount))
RESONANCE_SCRIPT_ENGINE_INTERFACE(void, blockReceived, (const int id, const SerializedDataContainer block))
RESONANCE_SCRIPT_ENGINE_INTERFACE(void, startEngine, ())
RESONANCE_SCRIPT_ENGINE_INTERFACE(void, stopEngine, ())

}

#undef IMPORT
#undef EXPORT

#endif
