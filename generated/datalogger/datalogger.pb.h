/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.5 */

#ifndef PB_DATALOGGER_DATALOGGER_PB_H_INCLUDED
#define PB_DATALOGGER_DATALOGGER_PB_H_INCLUDED
#include <pb.h>
#include "google/protobuf/timestamp.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _SourceDef_SourceType { 
    SourceDef_SourceType_UNKNOWN = 0, 
    SourceDef_SourceType_CAN = 1, 
    SourceDef_SourceType_TIME = 2, 
    SourceDef_SourceType_VOLTAGE = 3, 
    SourceDef_SourceType_TEMPERATURE = 4 
} SourceDef_SourceType;

typedef enum _CanMessage_FrameType { 
    CanMessage_FrameType_STANDARD_FRAME = 0, 
    CanMessage_FrameType_EXTENDED_FRAME = 1 
} CanMessage_FrameType;

typedef enum _CanMessage_RtrType { 
    CanMessage_RtrType_DATA_FRAME = 0, 
    CanMessage_RtrType_REMOTE_FRAME = 1 
} CanMessage_RtrType;

typedef enum _CanError_ErrorSource { 
    CanError_ErrorSource_UNKNOWN = 0, 
    CanError_ErrorSource_ERROR_WARNING = 1, 
    CanError_ErrorSource_ERROR_PASSIVE = 2, 
    CanError_ErrorSource_BUS_OFF = 3, 
    CanError_ErrorSource_DATA_OVERRUN = 4, 
    CanError_ErrorSource_ARBITRATION_LOST = 5, 
    CanError_ErrorSource_OTHER = 127 
} CanError_ErrorSource;

typedef enum _CanErrorCounter_ErrorCounterSource { 
    CanErrorCounter_ErrorCounterSource_TRANSMIT_COUNTER = 0, 
    CanErrorCounter_ErrorCounterSource_RECEIVE_COUNTER = 1 
} CanErrorCounter_ErrorCounterSource;

/* Struct definitions */
typedef struct _CanError { 
    CanError_ErrorSource source; 
} CanError;

typedef struct _CanErrorCounter { 
    CanErrorCounter_ErrorCounterSource source; 
    uint32_t count; 
} CanErrorCounter;

typedef PB_BYTES_ARRAY_T(8) CanMessage_data_t;
typedef struct _CanMessage { 
    uint32_t id; 
    CanMessage_FrameType length; 
    CanMessage_RtrType rtr; 
    CanMessage_data_t data; 
} CanMessage;

typedef struct _InfoString { 
    char info[128]; 
} InfoString;

/* Histogram with integer bucket boundaries and counts */
typedef struct _IntHistogram { 
    /* Parallel list of histogram bucket boundaries and counts.
 Bucket 0 is the range from [INT32_MIN, bucket[0])
 Bucket i is the range from [bucket[i-1], bucket[i])
 If there is one more count element than bucket, the last bucket's upper range is INT32_MAX */
    pb_size_t buckets_count;
    int32_t buckets[10]; /* exclusive upper limit */
    pb_size_t counts_count;
    uint32_t counts[11]; 
} IntHistogram;

typedef struct _SourceDef { 
    SourceDef_SourceType sourceType; 
    char name[32]; 
} SourceDef;

/* Helper messages */
typedef struct _StatisticalAggregate { 
    uint32_t samples; 
    int32_t min; 
    int32_t max; 
    int32_t avg; 
    uint32_t stdev; 
} StatisticalAggregate;

/* Not used anymore, payload placed directly in DataloggerRecord */
typedef struct _LegacyPayload { 
    pb_size_t which_value;
    union {
        SourceDef sourceDef;
        InfoString info;
        CanMessage receivedCanMessage;
        CanMessage transmittedCanMessage;
        CanError canError;
        CanErrorCounter canErrorCount;
        StatisticalAggregate voltageReading;
        StatisticalAggregate temperatureReading;
        StatisticalAggregate loopTimer;
        google_protobuf_Timestamp rtcTime;
        IntHistogram loopTimerDistribution;
        StatisticalAggregate sensorReading;
        IntHistogram sensorDistribution;
    } value; 
} LegacyPayload;

/* Actual messages */
typedef struct _DataloggerRecord { 
    uint32_t timestamp_ms; 
    uint32_t timestamp_variability; 
    uint32_t sourceId; 
    pb_size_t which_payload;
    union {
        LegacyPayload legacy_payload;
        SourceDef sourceDef;
        InfoString info;
        CanMessage receivedCanMessage;
        CanMessage transmittedCanMessage;
        CanError canError;
        google_protobuf_Timestamp rtcTime;
        StatisticalAggregate sensorReading;
        IntHistogram sensorDistribution;
    } payload; 
} DataloggerRecord;


/* Helper constants for enums */
#define _SourceDef_SourceType_MIN SourceDef_SourceType_UNKNOWN
#define _SourceDef_SourceType_MAX SourceDef_SourceType_TEMPERATURE
#define _SourceDef_SourceType_ARRAYSIZE ((SourceDef_SourceType)(SourceDef_SourceType_TEMPERATURE+1))

#define _CanMessage_FrameType_MIN CanMessage_FrameType_STANDARD_FRAME
#define _CanMessage_FrameType_MAX CanMessage_FrameType_EXTENDED_FRAME
#define _CanMessage_FrameType_ARRAYSIZE ((CanMessage_FrameType)(CanMessage_FrameType_EXTENDED_FRAME+1))

#define _CanMessage_RtrType_MIN CanMessage_RtrType_DATA_FRAME
#define _CanMessage_RtrType_MAX CanMessage_RtrType_REMOTE_FRAME
#define _CanMessage_RtrType_ARRAYSIZE ((CanMessage_RtrType)(CanMessage_RtrType_REMOTE_FRAME+1))

#define _CanError_ErrorSource_MIN CanError_ErrorSource_UNKNOWN
#define _CanError_ErrorSource_MAX CanError_ErrorSource_OTHER
#define _CanError_ErrorSource_ARRAYSIZE ((CanError_ErrorSource)(CanError_ErrorSource_OTHER+1))

#define _CanErrorCounter_ErrorCounterSource_MIN CanErrorCounter_ErrorCounterSource_TRANSMIT_COUNTER
#define _CanErrorCounter_ErrorCounterSource_MAX CanErrorCounter_ErrorCounterSource_RECEIVE_COUNTER
#define _CanErrorCounter_ErrorCounterSource_ARRAYSIZE ((CanErrorCounter_ErrorCounterSource)(CanErrorCounter_ErrorCounterSource_RECEIVE_COUNTER+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define StatisticalAggregate_init_default        {0, 0, 0, 0, 0}
#define IntHistogram_init_default                {0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}
#define LegacyPayload_init_default               {0, {SourceDef_init_default}}
#define SourceDef_init_default                   {_SourceDef_SourceType_MIN, ""}
#define InfoString_init_default                  {""}
#define CanMessage_init_default                  {0, _CanMessage_FrameType_MIN, _CanMessage_RtrType_MIN, {0, {0}}}
#define CanError_init_default                    {_CanError_ErrorSource_MIN}
#define CanErrorCounter_init_default             {_CanErrorCounter_ErrorCounterSource_MIN, 0}
#define DataloggerRecord_init_default            {0, 0, 0, 0, {LegacyPayload_init_default}}
#define StatisticalAggregate_init_zero           {0, 0, 0, 0, 0}
#define IntHistogram_init_zero                   {0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}
#define LegacyPayload_init_zero                  {0, {SourceDef_init_zero}}
#define SourceDef_init_zero                      {_SourceDef_SourceType_MIN, ""}
#define InfoString_init_zero                     {""}
#define CanMessage_init_zero                     {0, _CanMessage_FrameType_MIN, _CanMessage_RtrType_MIN, {0, {0}}}
#define CanError_init_zero                       {_CanError_ErrorSource_MIN}
#define CanErrorCounter_init_zero                {_CanErrorCounter_ErrorCounterSource_MIN, 0}
#define DataloggerRecord_init_zero               {0, 0, 0, 0, {LegacyPayload_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define CanError_source_tag                      1
#define CanErrorCounter_source_tag               1
#define CanErrorCounter_count_tag                2
#define CanMessage_id_tag                        1
#define CanMessage_length_tag                    2
#define CanMessage_rtr_tag                       3
#define CanMessage_data_tag                      4
#define InfoString_info_tag                      1
#define IntHistogram_buckets_tag                 1
#define IntHistogram_counts_tag                  2
#define SourceDef_sourceType_tag                 1
#define SourceDef_name_tag                       2
#define StatisticalAggregate_samples_tag         1
#define StatisticalAggregate_min_tag             2
#define StatisticalAggregate_max_tag             3
#define StatisticalAggregate_avg_tag             4
#define StatisticalAggregate_stdev_tag           5
#define LegacyPayload_sourceDef_tag              1
#define LegacyPayload_info_tag                   2
#define LegacyPayload_receivedCanMessage_tag     3
#define LegacyPayload_transmittedCanMessage_tag  4
#define LegacyPayload_canError_tag               5
#define LegacyPayload_canErrorCount_tag          6
#define LegacyPayload_voltageReading_tag         7
#define LegacyPayload_temperatureReading_tag     8
#define LegacyPayload_loopTimer_tag              9
#define LegacyPayload_rtcTime_tag                10
#define LegacyPayload_loopTimerDistribution_tag  11
#define LegacyPayload_sensorReading_tag          12
#define LegacyPayload_sensorDistribution_tag     13
#define DataloggerRecord_timestamp_ms_tag        1
#define DataloggerRecord_timestamp_variability_tag 2
#define DataloggerRecord_sourceId_tag            3
#define DataloggerRecord_legacy_payload_tag      4
#define DataloggerRecord_sourceDef_tag           5
#define DataloggerRecord_info_tag                6
#define DataloggerRecord_receivedCanMessage_tag  7
#define DataloggerRecord_transmittedCanMessage_tag 8
#define DataloggerRecord_canError_tag            9
#define DataloggerRecord_rtcTime_tag             10
#define DataloggerRecord_sensorReading_tag       11
#define DataloggerRecord_sensorDistribution_tag  12

/* Struct field encoding specification for nanopb */
#define StatisticalAggregate_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   samples,           1) \
X(a, STATIC,   SINGULAR, INT32,    min,               2) \
X(a, STATIC,   SINGULAR, INT32,    max,               3) \
X(a, STATIC,   SINGULAR, INT32,    avg,               4) \
X(a, STATIC,   SINGULAR, UINT32,   stdev,             5)
#define StatisticalAggregate_CALLBACK NULL
#define StatisticalAggregate_DEFAULT NULL

#define IntHistogram_FIELDLIST(X, a) \
X(a, STATIC,   REPEATED, INT32,    buckets,           1) \
X(a, STATIC,   REPEATED, UINT32,   counts,            2)
#define IntHistogram_CALLBACK NULL
#define IntHistogram_DEFAULT NULL

#define LegacyPayload_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,sourceDef,value.sourceDef),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,info,value.info),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,receivedCanMessage,value.receivedCanMessage),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,transmittedCanMessage,value.transmittedCanMessage),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,canError,value.canError),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,canErrorCount,value.canErrorCount),   6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,voltageReading,value.voltageReading),   7) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,temperatureReading,value.temperatureReading),   8) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,loopTimer,value.loopTimer),   9) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,rtcTime,value.rtcTime),  10) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,loopTimerDistribution,value.loopTimerDistribution),  11) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,sensorReading,value.sensorReading),  12) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,sensorDistribution,value.sensorDistribution),  13)
#define LegacyPayload_CALLBACK NULL
#define LegacyPayload_DEFAULT NULL
#define LegacyPayload_value_sourceDef_MSGTYPE SourceDef
#define LegacyPayload_value_info_MSGTYPE InfoString
#define LegacyPayload_value_receivedCanMessage_MSGTYPE CanMessage
#define LegacyPayload_value_transmittedCanMessage_MSGTYPE CanMessage
#define LegacyPayload_value_canError_MSGTYPE CanError
#define LegacyPayload_value_canErrorCount_MSGTYPE CanErrorCounter
#define LegacyPayload_value_voltageReading_MSGTYPE StatisticalAggregate
#define LegacyPayload_value_temperatureReading_MSGTYPE StatisticalAggregate
#define LegacyPayload_value_loopTimer_MSGTYPE StatisticalAggregate
#define LegacyPayload_value_rtcTime_MSGTYPE google_protobuf_Timestamp
#define LegacyPayload_value_loopTimerDistribution_MSGTYPE IntHistogram
#define LegacyPayload_value_sensorReading_MSGTYPE StatisticalAggregate
#define LegacyPayload_value_sensorDistribution_MSGTYPE IntHistogram

#define SourceDef_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    sourceType,        1) \
X(a, STATIC,   SINGULAR, STRING,   name,              2)
#define SourceDef_CALLBACK NULL
#define SourceDef_DEFAULT NULL

#define InfoString_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   info,              1)
#define InfoString_CALLBACK NULL
#define InfoString_DEFAULT NULL

#define CanMessage_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   id,                1) \
X(a, STATIC,   SINGULAR, UENUM,    length,            2) \
X(a, STATIC,   SINGULAR, UENUM,    rtr,               3) \
X(a, STATIC,   SINGULAR, BYTES,    data,              4)
#define CanMessage_CALLBACK NULL
#define CanMessage_DEFAULT NULL

#define CanError_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    source,            1)
#define CanError_CALLBACK NULL
#define CanError_DEFAULT NULL

#define CanErrorCounter_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    source,            1) \
X(a, STATIC,   SINGULAR, UINT32,   count,             2)
#define CanErrorCounter_CALLBACK NULL
#define CanErrorCounter_DEFAULT NULL

#define DataloggerRecord_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   timestamp_ms,      1) \
X(a, STATIC,   SINGULAR, UINT32,   timestamp_variability,   2) \
X(a, STATIC,   SINGULAR, UINT32,   sourceId,          3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,legacy_payload,payload.legacy_payload),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,sourceDef,payload.sourceDef),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,info,payload.info),   6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,receivedCanMessage,payload.receivedCanMessage),   7) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,transmittedCanMessage,payload.transmittedCanMessage),   8) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,canError,payload.canError),   9) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,rtcTime,payload.rtcTime),  10) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,sensorReading,payload.sensorReading),  11) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,sensorDistribution,payload.sensorDistribution),  12)
#define DataloggerRecord_CALLBACK NULL
#define DataloggerRecord_DEFAULT NULL
#define DataloggerRecord_payload_legacy_payload_MSGTYPE LegacyPayload
#define DataloggerRecord_payload_sourceDef_MSGTYPE SourceDef
#define DataloggerRecord_payload_info_MSGTYPE InfoString
#define DataloggerRecord_payload_receivedCanMessage_MSGTYPE CanMessage
#define DataloggerRecord_payload_transmittedCanMessage_MSGTYPE CanMessage
#define DataloggerRecord_payload_canError_MSGTYPE CanError
#define DataloggerRecord_payload_rtcTime_MSGTYPE google_protobuf_Timestamp
#define DataloggerRecord_payload_sensorReading_MSGTYPE StatisticalAggregate
#define DataloggerRecord_payload_sensorDistribution_MSGTYPE IntHistogram

extern const pb_msgdesc_t StatisticalAggregate_msg;
extern const pb_msgdesc_t IntHistogram_msg;
extern const pb_msgdesc_t LegacyPayload_msg;
extern const pb_msgdesc_t SourceDef_msg;
extern const pb_msgdesc_t InfoString_msg;
extern const pb_msgdesc_t CanMessage_msg;
extern const pb_msgdesc_t CanError_msg;
extern const pb_msgdesc_t CanErrorCounter_msg;
extern const pb_msgdesc_t DataloggerRecord_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define StatisticalAggregate_fields &StatisticalAggregate_msg
#define IntHistogram_fields &IntHistogram_msg
#define LegacyPayload_fields &LegacyPayload_msg
#define SourceDef_fields &SourceDef_msg
#define InfoString_fields &InfoString_msg
#define CanMessage_fields &CanMessage_msg
#define CanError_fields &CanError_msg
#define CanErrorCounter_fields &CanErrorCounter_msg
#define DataloggerRecord_fields &DataloggerRecord_msg

/* Maximum encoded size of messages (where known) */
#define CanErrorCounter_size                     8
#define CanError_size                            2
#define CanMessage_size                          20
#define InfoString_size                          130
#define IntHistogram_size                        176
#define SourceDef_size                           35
#define StatisticalAggregate_size                45
#if defined(google_protobuf_Timestamp_size)
#define LegacyPayload_size                       (0 + sizeof(union LegacyPayload_value_size_union))
union LegacyPayload_value_size_union {char f10[(6 + google_protobuf_Timestamp_size)]; char f0[179];};
#endif
#if defined(google_protobuf_Timestamp_size) && defined(google_protobuf_Timestamp_size)
#define DataloggerRecord_size                    (18 + sizeof(union DataloggerRecord_payload_size_union))
union DataloggerRecord_payload_size_union {char f4[(6 + sizeof(union LegacyPayload_value_size_union))]; char f10[(6 + google_protobuf_Timestamp_size)]; char f0[179];};
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
