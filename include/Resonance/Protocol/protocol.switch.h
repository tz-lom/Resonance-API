#define THIR_NAMESPACE (Resonance)(R3)(Thir)
#ifndef RESONANCE_STANDALONE
#  define THIR_EXTENSIONS (Qt)
#endif

#include <thir/generate.h>
#include <thir/classes.h>
#include <thir/fields/all.h>

#ifdef PROTOCOL_PREBUILD
    #include "protocol.generated.h"
#else
    #include "protocol.generator.h"
#endif

namespace Resonance {
typedef R3::Thir::SD SD;
typedef R3::Thir::ValueSetter<R3::Thir::__Last, typename R3::Thir::ValueSetter<R3::Thir::__Last, R3::Thir::__Last>::N > LastRecursive;


}
#include <thir/undef.h>
