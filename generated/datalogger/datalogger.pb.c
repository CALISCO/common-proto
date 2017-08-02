/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9-dev */

#include "datalogger.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t StatisticalAggregate_fields[6] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, StatisticalAggregate, samples, samples, 0),
    PB_FIELD(  2, INT32   , SINGULAR, STATIC  , OTHER, StatisticalAggregate, min, samples, 0),
    PB_FIELD(  3, INT32   , SINGULAR, STATIC  , OTHER, StatisticalAggregate, max, min, 0),
    PB_FIELD(  4, INT32   , SINGULAR, STATIC  , OTHER, StatisticalAggregate, avg, max, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, StatisticalAggregate, stdev, avg, 0),
    PB_LAST_FIELD
};

const pb_field_t IntHistogram_fields[3] = {
    PB_FIELD(  1, INT32   , REPEATED, STATIC  , FIRST, IntHistogram, buckets, buckets, 0),
    PB_FIELD(  2, UINT32  , REPEATED, STATIC  , OTHER, IntHistogram, counts, buckets, 0),
    PB_LAST_FIELD
};

const pb_field_t DataloggerRecord_fields[13] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, DataloggerRecord, timestamp_ms, timestamp_ms, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, DataloggerRecord, timestamp_variability, timestamp_ms, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, DataloggerRecord, sourceId, timestamp_variability, 0),
    PB_ONEOF_FIELD(payload,   4, MESSAGE , ONEOF, STATIC  , OTHER, DataloggerRecord, legacy_payload, sourceId, &LegacyPayload_fields),
    PB_ONEOF_FIELD(payload,   5, MESSAGE , ONEOF, STATIC  , UNION, DataloggerRecord, sourceDef, sourceId, &SourceDef_fields),
    PB_ONEOF_FIELD(payload,   6, MESSAGE , ONEOF, STATIC  , UNION, DataloggerRecord, info, sourceId, &InfoString_fields),
    PB_ONEOF_FIELD(payload,   7, MESSAGE , ONEOF, STATIC  , UNION, DataloggerRecord, receivedCanMessage, sourceId, &CanMessage_fields),
    PB_ONEOF_FIELD(payload,   8, MESSAGE , ONEOF, STATIC  , UNION, DataloggerRecord, transmittedCanMessage, sourceId, &CanMessage_fields),
    PB_ONEOF_FIELD(payload,   9, MESSAGE , ONEOF, STATIC  , UNION, DataloggerRecord, canError, sourceId, &CanError_fields),
    PB_ONEOF_FIELD(payload,  10, MESSAGE , ONEOF, STATIC  , UNION, DataloggerRecord, rtcTime, sourceId, &google_protobuf_Timestamp_fields),
    PB_ONEOF_FIELD(payload,  11, MESSAGE , ONEOF, STATIC  , UNION, DataloggerRecord, sensorReading, sourceId, &StatisticalAggregate_fields),
    PB_ONEOF_FIELD(payload,  12, MESSAGE , ONEOF, STATIC  , UNION, DataloggerRecord, sensorDistribution, sourceId, &IntHistogram_fields),
    PB_LAST_FIELD
};

const pb_field_t LegacyPayload_fields[14] = {
    PB_ONEOF_FIELD(value,   1, MESSAGE , ONEOF, STATIC  , FIRST, LegacyPayload, sourceDef, sourceDef, &SourceDef_fields),
    PB_ONEOF_FIELD(value,   2, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, info, info, &InfoString_fields),
    PB_ONEOF_FIELD(value,   3, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, receivedCanMessage, receivedCanMessage, &CanMessage_fields),
    PB_ONEOF_FIELD(value,   4, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, transmittedCanMessage, transmittedCanMessage, &CanMessage_fields),
    PB_ONEOF_FIELD(value,   5, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, canError, canError, &CanError_fields),
    PB_ONEOF_FIELD(value,   6, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, canErrorCount, canErrorCount, &CanErrorCounter_fields),
    PB_ONEOF_FIELD(value,   7, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, voltageReading, voltageReading, &StatisticalAggregate_fields),
    PB_ONEOF_FIELD(value,   8, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, temperatureReading, temperatureReading, &StatisticalAggregate_fields),
    PB_ONEOF_FIELD(value,   9, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, loopTimer, loopTimer, &StatisticalAggregate_fields),
    PB_ONEOF_FIELD(value,  10, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, rtcTime, rtcTime, &google_protobuf_Timestamp_fields),
    PB_ONEOF_FIELD(value,  11, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, loopTimerDistribution, loopTimerDistribution, &IntHistogram_fields),
    PB_ONEOF_FIELD(value,  12, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, sensorReading, sensorReading, &StatisticalAggregate_fields),
    PB_ONEOF_FIELD(value,  13, MESSAGE , ONEOF, STATIC  , UNION, LegacyPayload, sensorDistribution, sensorDistribution, &IntHistogram_fields),
    PB_LAST_FIELD
};

const pb_field_t SourceDef_fields[3] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, SourceDef, sourceType, sourceType, 0),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, SourceDef, name, sourceType, 0),
    PB_LAST_FIELD
};

const pb_field_t InfoString_fields[2] = {
    PB_FIELD(  1, STRING  , SINGULAR, STATIC  , FIRST, InfoString, info, info, 0),
    PB_LAST_FIELD
};

const pb_field_t CanMessage_fields[5] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, CanMessage, id, id, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, CanMessage, length, id, 0),
    PB_FIELD(  3, UENUM   , SINGULAR, STATIC  , OTHER, CanMessage, rtr, length, 0),
    PB_FIELD(  4, BYTES   , SINGULAR, STATIC  , OTHER, CanMessage, data, rtr, 0),
    PB_LAST_FIELD
};

const pb_field_t CanError_fields[2] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, CanError, source, source, 0),
    PB_LAST_FIELD
};

const pb_field_t CanErrorCounter_fields[3] = {
    PB_FIELD(  1, UENUM   , SINGULAR, STATIC  , FIRST, CanErrorCounter, source, source, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, CanErrorCounter, count, source, 0),
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
PB_STATIC_ASSERT((pb_membersize(DataloggerRecord, payload.legacy_payload) < 65536 && pb_membersize(DataloggerRecord, payload.sourceDef) < 65536 && pb_membersize(DataloggerRecord, payload.info) < 65536 && pb_membersize(DataloggerRecord, payload.receivedCanMessage) < 65536 && pb_membersize(DataloggerRecord, payload.transmittedCanMessage) < 65536 && pb_membersize(DataloggerRecord, payload.canError) < 65536 && pb_membersize(DataloggerRecord, payload.rtcTime) < 65536 && pb_membersize(DataloggerRecord, payload.sensorReading) < 65536 && pb_membersize(DataloggerRecord, payload.sensorDistribution) < 65536 && pb_membersize(LegacyPayload, value.sourceDef) < 65536 && pb_membersize(LegacyPayload, value.info) < 65536 && pb_membersize(LegacyPayload, value.receivedCanMessage) < 65536 && pb_membersize(LegacyPayload, value.transmittedCanMessage) < 65536 && pb_membersize(LegacyPayload, value.canError) < 65536 && pb_membersize(LegacyPayload, value.canErrorCount) < 65536 && pb_membersize(LegacyPayload, value.voltageReading) < 65536 && pb_membersize(LegacyPayload, value.temperatureReading) < 65536 && pb_membersize(LegacyPayload, value.loopTimer) < 65536 && pb_membersize(LegacyPayload, value.rtcTime) < 65536 && pb_membersize(LegacyPayload, value.loopTimerDistribution) < 65536 && pb_membersize(LegacyPayload, value.sensorReading) < 65536 && pb_membersize(LegacyPayload, value.sensorDistribution) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_StatisticalAggregate_IntHistogram_DataloggerRecord_LegacyPayload_SourceDef_InfoString_CanMessage_CanError_CanErrorCounter)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(DataloggerRecord, payload.legacy_payload) < 256 && pb_membersize(DataloggerRecord, payload.sourceDef) < 256 && pb_membersize(DataloggerRecord, payload.info) < 256 && pb_membersize(DataloggerRecord, payload.receivedCanMessage) < 256 && pb_membersize(DataloggerRecord, payload.transmittedCanMessage) < 256 && pb_membersize(DataloggerRecord, payload.canError) < 256 && pb_membersize(DataloggerRecord, payload.rtcTime) < 256 && pb_membersize(DataloggerRecord, payload.sensorReading) < 256 && pb_membersize(DataloggerRecord, payload.sensorDistribution) < 256 && pb_membersize(LegacyPayload, value.sourceDef) < 256 && pb_membersize(LegacyPayload, value.info) < 256 && pb_membersize(LegacyPayload, value.receivedCanMessage) < 256 && pb_membersize(LegacyPayload, value.transmittedCanMessage) < 256 && pb_membersize(LegacyPayload, value.canError) < 256 && pb_membersize(LegacyPayload, value.canErrorCount) < 256 && pb_membersize(LegacyPayload, value.voltageReading) < 256 && pb_membersize(LegacyPayload, value.temperatureReading) < 256 && pb_membersize(LegacyPayload, value.loopTimer) < 256 && pb_membersize(LegacyPayload, value.rtcTime) < 256 && pb_membersize(LegacyPayload, value.loopTimerDistribution) < 256 && pb_membersize(LegacyPayload, value.sensorReading) < 256 && pb_membersize(LegacyPayload, value.sensorDistribution) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_StatisticalAggregate_IntHistogram_DataloggerRecord_LegacyPayload_SourceDef_InfoString_CanMessage_CanError_CanErrorCounter)
#endif


/* @@protoc_insertion_point(eof) */
