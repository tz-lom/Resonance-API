#include "protocol.switch.h"

#include <thir/generate.h>

#include <thir/classes.imp.h>

#ifdef PROTOCOL_PREBUILD
    #include "protocol.generated.cpp.h"
#else
    #include "protocol.generator.cpp.h"
#endif
