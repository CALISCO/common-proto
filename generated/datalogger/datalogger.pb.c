/* Automatically generated nanopb constant definitions */

#include "datalogger.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t StatisticalAggregate_fields[6] = {
    PB_FIELD(  1, UINT32  , OPTIONAL, STATIC  , FIRST, StatisticalAggregate, samples, samples, 0),
    PB_FIELD(  2, INT32   , OPTIONAL, STATIC  , OTHER, StatisticalAggregate, min, samples, 0),
    PB_FIELD(  3, INT32   , OPTIONAL, STATIC  , OTHER, StatisticalAggregate, max, min, 0),
    PB_FIELD(  4, INT32   , OPTIONAL, STATIC  , OTHER, StatisticalAggregate, avg, max, 0),
    PB_FIELD(  5, UINT32  , OPTIONAL, STATIC  , OTHER, StatisticalAggregate, stdev, avg, 0),
    PB_LAST_FIELD
};

const pb_field_t DataloggerRecord_fields[5] = {
    PB_FIELD(  1, UINT32  , OPTIONAL, STATIC  , FIRST, DataloggerRecord, timestamp_ms, timestamp_ms, 0),
    PB_FIELD(  2, UINT32  , OPTIONAL, STATIC  , OTHER, DataloggerRecord, timestamp_variability, timestamp_ms, 0),
    PB_FIELD(  3, UINT32  , OPTIONAL, STATIC  , OTHER, DataloggerRecord, sourceId, timestamp_variability, 0),
    PB_FIELD(  4, MESSAGE , OPTIONAL, STATIC  , OTHER, DataloggerRecord, payload, sourceId, &DataloggerPayload_fields),
    PB_LAST_FIELD
};

const pb_field_t DataloggerPayload_fields[11] = {
    PB_ONEOF_FIELD(value,   1, MESSAGE , ONEOF, STATIC  , FIRST, DataloggerPayload, sourceDef, sourceDef, &SourceDef_fields),
    PB_ONEOF_FIELD(value,   2, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, info, info, &InfoString_fields),
    PB_ONEOF_FIELD(value,   3, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, receivedCanMessage, receivedCanMessage, &CanMessage_fields),
    PB_ONEOF_FIELD(value,   4, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, transmittedCanMessage, transmittedCanMessage, &CanMessage_fields),
    PB_ONEOF_FIELD(value,   5, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, canError, canError, &CanError_fields),
    PB_ONEOF_FIELD(value,   6, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, canErrorCount, canErrorCount, &CanErrorCounter_fields),
    PB_ONEOF_FIELD(value,   7, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, voltageReading, voltageReading, &StatisticalAggregate_fields),
    PB_ONEOF_FIELD(value,   8, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, temperatureReading, temperatureReading, &StatisticalAggregate_fields),
    PB_ONEOF_FIELD(value,   9, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, loopTimer, loopTimer, &StatisticalAggregate_fields),
    PB_ONEOF_FIELD(value,  10, MESSAGE , ONEOF, STATIC  , UNION, DataloggerPayload, rtcTime, rtcTime, &google_protobuf_Timestamp_fields),
    PB_LAST_FIELD
};

const pb_field_t SourceDef_fields[3] = {
    PB_FIELD(  1, UENUM   , OPTIONAL, STATIC  , FIRST, SourceDef, sourceType, sourceType, 0),
    PB_FIELD(  2, STRING  , OPTIONAL, STATIC  , OTHER, SourceDef, name, sourceType, 0),
    PB_LAST_FIELD
};

const pb_field_t InfoString_fields[2] = {
    PB_FIELD(  1, STRING  , OPTIONAL, STATIC  , FIRST, InfoString, info, info, 0),
    PB_LAST_FIELD
};

const pb_field_t CanMessage_fields[5] = {
    PB_FIELD(  1, UINT32  , OPTIONAL, STATIC  , FIRST, CanMessage, id, id, 0),
    PB_FIELD(  2, UENUM   , OPTIONAL, STATIC  , OTHER, CanMessage, length, id, 0),
    PB_FIELD(  3, UENUM   , OPTIONAL, STATIC  , OTHER, CanMessage, rtr, length, 0),
    PB_FIELD(  4, BYTES   , OPTIONAL, STATIC  , OTHER, CanMessage, data, rtr, 0),
    PB_LAST_FIELD
};

const pb_field_t CanError_fields[2] = {
    PB_FIELD(  1, UENUM   , OPTIONAL, STATIC  , FIRST, CanError, source, source, 0),
    PB_LAST_FIELD
};

const pb_field_t CanErrorCounter_fields[3] = {
    PB_FIELD(  1, UENUM   , OPTIONAL, STATIC  , FIRST, CanErrorCounter, source, source, 0),
    PB_FIELD(  2, UINT32  , OPTIONAL, STATIC  , OTHER, CanErrorCounter, count, source, 0),
    PB_LAST_FIELD
};







/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(DataloggerRecord, payload) < 65536 && pb_membersize(DataloggerPayload, value.sourceDef) < 65536 && pb_membersize(DataloggerPayload, value.info) < 65536 && pb_membersize(DataloggerPayload, value.receivedCanMessage) < 65536 && pb_membersize(DataloggerPayload, value.transmittedCanMessage) < 65536 && pb_membersize(DataloggerPayload, value.canError) < 65536 && pb_membersize(DataloggerPayload, value.canErrorCount) < 65536 && pb_membersize(DataloggerPayload, value.voltageReading) < 65536 && pb_membersize(DataloggerPayload, value.temperatureReading) < 65536 && pb_membersize(DataloggerPayload, value.loopTimer) < 65536 && pb_membersize(DataloggerPayload, value.rtcTime) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_StatisticalAggregate_DataloggerRecord_DataloggerPayload_SourceDef_InfoString_CanMessage_CanError_CanErrorCounter)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(DataloggerRecord, payload) < 256 && pb_membersize(DataloggerPayload, value.sourceDef) < 256 && pb_membersize(DataloggerPayload, value.info) < 256 && pb_membersize(DataloggerPayload, value.receivedCanMessage) < 256 && pb_membersize(DataloggerPayload, value.transmittedCanMessage) < 256 && pb_membersize(DataloggerPayload, value.canError) < 256 && pb_membersize(DataloggerPayload, value.canErrorCount) < 256 && pb_membersize(DataloggerPayload, value.voltageReading) < 256 && pb_membersize(DataloggerPayload, value.temperatureReading) < 256 && pb_membersize(DataloggerPayload, value.loopTimer) < 256 && pb_membersize(DataloggerPayload, value.rtcTime) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_StatisticalAggregate_DataloggerRecord_DataloggerPayload_SourceDef_InfoString_CanMessage_CanError_CanErrorCounter)
#endif


/* @@protoc_insertion_point(eof) */
