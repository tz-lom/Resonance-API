#ifdef THIR_NAMESPACE
#  undef THIR_NAMESPACE
#endif
#define THIR_NAMESPACE (Resonance)(R3)(Thir)
#ifdef THIR_EXTENSIONS
#  undef THIR_EXTENSIONS
#endif
#define THIR_EXTENSIONS (Qt)


#define PROTOCOL_DESCR \
    RECORD(JSON_Object, \
        VECTOR_ANY(keys) \
        VECTOR_ANY(values) \
    )\
    RECORD(JSON_Array, \
        VECTOR_ANY(values) \
    )\
    RECORD(JSON_Null, EMPTY() ) \
    RECORD(JSON_Number, FIELD(value, double) ) \
    RECORD(JSON_Bool, FIELD(value, bool) ) \
    RECORD(JSON_String, STRING(value) ) \
    \
    RECORD(ConnectionHeader_EventBus, EMPTY() )\
    \
    RECORD(EventBus_Description,\
        FIELD(created, uint64_t) \
        FIELD(received, uint64_t) \
        STRING(uid) \
        VECTOR_ANY(streams) \
        ANY(parameters)\
    )\
    \
    RECORD(EventBus_Description_Stream,\
        STRING(name) \
        ANY(type) \
        VECTOR_ANY(urls) \
    )\
    \
    RECORD(EventBus_Description_Url,\
        STRING(url) \
    )\
    \
    \
    RECORD(EventBus_DescribeRequest,\
        FIELD(created, uint64_t) \
        FIELD(received, uint64_t) \
    )\
\
    RECORD(EventBus_ApplyParameters, \
        FIELD(created, uint64_t) \
        FIELD(received, uint64_t) \
        ANY(parameters)\
    )\
    \
    RECORD(EventBus_Transition, \
        FIELD(created, uint64_t) \
        FIELD(received, uint64_t) \
        STRING(name) \
    )\
    \
    RECORD(ConnectionHeader_Message, EMPTY() )\
    \
    RECORD(Message, \
        FIELD(created, uint64_t) \
        FIELD(received, uint64_t) \
        STRING(message) \
    )\
    RECORD(File_Stream, \
        FIELD(id, uint16_t) \
        STRING(name) \
        ANY(info) \
    )\
    \
    RECORD(File_DataBlock, \
        FIELD(stream, uint16_t) \
        ANY(block) \
    )\
    \
    RECORD(FileHeader, \
        FIELD(versionMajor, uint16_t) \
        FIELD(versionMinor, uint16_t) \
        FIELD(packed, bool) \
        FIELD(timestamp, uint64_t) \
    )\
    \
    RECORD( Float64, \
        FIELD(created, uint64_t) \
        FIELD(received, uint64_t) \
        FIELD(samples, uint32_t) \
        VECTOR(data, double) \
    ) \
    \
    RECORD(ConnectionHeader_Int32, \
        FIELD(channels, uint32_t) \
        FIELD(samplingRate, double) \
        FIELD(multiplier, double) \
    )\
    RECORD( Int32, \
        FIELD(created, uint64_t) \
        FIELD(received, uint64_t) \
        FIELD(samples, uint32_t) \
        VECTOR(data, int32_t) \
    ) \
 \
    RECORD(ConnectionHeader_Int64, \
        FIELD(channels, uint32_t) \
        FIELD(samplingRate, double) \
        FIELD(multiplier, double) \
    )\
    \
    RECORD(ConnectionHeader_Float64, \
        FIELD(channels, uint32_t) \
        FIELD(samplingRate, double) \
    )\
    RECORD(Int64, \
        FIELD(created, uint64_t) \
        FIELD(received, uint64_t) \
        FIELD(samples, uint32_t) \
        VECTOR(data, int64_t) \
    )\
    RECORD(ConnectionHeaderContainer, \
        STRING(name) \
        STRING(serviceUid) \
        ANY(type) \
    )\
    RECORD(FileStreamSourceInfo, \
        FIELD(stream, uint16_t) \
        STRING(name) \
        STRING(uid) \
        VECTOR_ANY(urls) \
        FIELD(timestamp, uint64_t) \
    )\
    RECORD(FileStreamTerminated, \
        FIELD(stream, uint16_t) \
        FIELD(timestamp, uint64_t) \
    )

