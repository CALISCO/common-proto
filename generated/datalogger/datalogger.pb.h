/* Automatically generated nanopb header */

#ifndef PB_DATALOGGER_PB_H_INCLUDED
#define PB_DATALOGGER_PB_H_INCLUDED
#include <pb.h>

#include "google/protobuf/timestamp.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _SourceDef_SourceType {
    SourceDef_SourceType_UNKNOWN = 0,
    SourceDef_SourceType_CAN = 1,
    SourceDef_SourceType_TIME = 2,
    SourceDef_SourceType_VOLTAGE = 3,
    SourceDef_SourceType_TEMPERATURE = 4
} SourceDef_SourceType;
#define _SourceDef_SourceType_MIN SourceDef_SourceType_UNKNOWN
#define _SourceDef_SourceType_MAX SourceDef_SourceType_TEMPERATURE
#define _SourceDef_SourceType_ARRAYSIZE ((SourceDef_SourceType)(SourceDef_SourceType_TEMPERATURE+1))

typedef enum _CanMessage_FrameType {
    CanMessage_FrameType_STANDARD_FRAME = 0,
    CanMessage_FrameType_EXTENDED_FRAME = 1
} CanMessage_FrameType;
#define _CanMessage_FrameType_MIN CanMessage_FrameType_STANDARD_FRAME
#define _CanMessage_FrameType_MAX CanMessage_FrameType_EXTENDED_FRAME
#define _CanMessage_FrameType_ARRAYSIZE ((CanMessage_FrameType)(CanMessage_FrameType_EXTENDED_FRAME+1))

typedef enum _CanMessage_RtrType {
    CanMessage_RtrType_DATA_FRAME = 0,
    CanMessage_RtrType_REMOTE_FRAME = 1
} CanMessage_RtrType;
#define _CanMessage_RtrType_MIN CanMessage_RtrType_DATA_FRAME
#define _CanMessage_RtrType_MAX CanMessage_RtrType_REMOTE_FRAME
#define _CanMessage_RtrType_ARRAYSIZE ((CanMessage_RtrType)(CanMessage_RtrType_REMOTE_FRAME+1))

typedef enum _CanError_ErrorSource {
    CanError_ErrorSource_UNKNOWN = 0,
    CanError_ErrorSource_ERROR_WARNING = 1,
    CanError_ErrorSource_ERROR_PASSIVE = 2,
    CanError_ErrorSource_BUS_OFF = 3,
    CanError_ErrorSource_DATA_OVERRUN = 4,
    CanError_ErrorSource_ARBITRATION_LOST = 5,
    CanError_ErrorSource_OTHER = 127
} CanError_ErrorSource;
#define _CanError_ErrorSource_MIN CanError_ErrorSource_UNKNOWN
#define _CanError_ErrorSource_MAX CanError_ErrorSource_OTHER
#define _CanError_ErrorSource_ARRAYSIZE ((CanError_ErrorSource)(CanError_ErrorSource_OTHER+1))

typedef enum _CanErrorCounter_ErrorCounterSource {
    CanErrorCounter_ErrorCounterSource_TRANSMIT_COUNTER = 0,
    CanErrorCounter_ErrorCounterSource_RECEIVE_COUNTER = 1
} CanErrorCounter_ErrorCounterSource;
#define _CanErrorCounter_ErrorCounterSource_MIN CanErrorCounter_ErrorCounterSource_TRANSMIT_COUNTER
#define _CanErrorCounter_ErrorCounterSource_MAX CanErrorCounter_ErrorCounterSource_RECEIVE_COUNTER
#define _CanErrorCounter_ErrorCounterSource_ARRAYSIZE ((CanErrorCounter_ErrorCounterSource)(CanErrorCounter_ErrorCounterSource_RECEIVE_COUNTER+1))

/* Struct definitions */
typedef struct _CanError {
    bool has_source;
    CanError_ErrorSource source;
/* @@protoc_insertion_point(struct:CanError) */
} CanError;

typedef struct _CanErrorCounter {
    bool has_source;
    CanErrorCounter_ErrorCounterSource source;
    bool has_count;
    uint32_t count;
/* @@protoc_insertion_point(struct:CanErrorCounter) */
} CanErrorCounter;

typedef PB_BYTES_ARRAY_T(8) CanMessage_data_t;
typedef struct _CanMessage {
    bool has_id;
    uint32_t id;
    bool has_length;
    CanMessage_FrameType length;
    bool has_rtr;
    CanMessage_RtrType rtr;
    bool has_data;
    CanMessage_data_t data;
/* @@protoc_insertion_point(struct:CanMessage) */
} CanMessage;

typedef struct _InfoString {
    bool has_info;
    char info[128];
/* @@protoc_insertion_point(struct:InfoString) */
} InfoString;

typedef struct _SourceDef {
    bool has_sourceType;
    SourceDef_SourceType sourceType;
    bool has_name;
    char name[32];
/* @@protoc_insertion_point(struct:SourceDef) */
} SourceDef;

typedef struct _StatisticalAggregate {
    bool has_samples;
    uint32_t samples;
    bool has_min;
    int32_t min;
    bool has_max;
    int32_t max;
    bool has_avg;
    int32_t avg;
    bool has_stdev;
    uint32_t stdev;
/* @@protoc_insertion_point(struct:StatisticalAggregate) */
} StatisticalAggregate;

typedef struct _DataloggerPayload {
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
    } value;
/* @@protoc_insertion_point(struct:DataloggerPayload) */
} DataloggerPayload;

typedef struct _DataloggerRecord {
    bool has_timestamp_ms;
    uint32_t timestamp_ms;
    bool has_timestamp_variability;
    uint32_t timestamp_variability;
    bool has_sourceId;
    uint32_t sourceId;
    bool has_payload;
    DataloggerPayload payload;
/* @@protoc_insertion_point(struct:DataloggerRecord) */
} DataloggerRecord;

/* Default values for struct fields */

/* Initializer values for message structs */
#define StatisticalAggregate_init_default        {false, 0, false, 0, false, 0, false, 0, false, 0}
#define DataloggerRecord_init_default            {false, 0, false, 0, false, 0, false, DataloggerPayload_init_default}
#define DataloggerPayload_init_default           {0, {SourceDef_init_default}}
#define SourceDef_init_default                   {false, (SourceDef_SourceType)0, false, ""}
#define InfoString_init_default                  {false, ""}
#define CanMessage_init_default                  {false, 0, false, (CanMessage_FrameType)0, false, (CanMessage_RtrType)0, false, {0, {0}}}
#define CanError_init_default                    {false, (CanError_ErrorSource)0}
#define CanErrorCounter_init_default             {false, (CanErrorCounter_ErrorCounterSource)0, false, 0}
#define StatisticalAggregate_init_zero           {false, 0, false, 0, false, 0, false, 0, false, 0}
#define DataloggerRecord_init_zero               {false, 0, false, 0, false, 0, false, DataloggerPayload_init_zero}
#define DataloggerPayload_init_zero              {0, {SourceDef_init_zero}}
#define SourceDef_init_zero                      {false, (SourceDef_SourceType)0, false, ""}
#define InfoString_init_zero                     {false, ""}
#define CanMessage_init_zero                     {false, 0, false, (CanMessage_FrameType)0, false, (CanMessage_RtrType)0, false, {0, {0}}}
#define CanError_init_zero                       {false, (CanError_ErrorSource)0}
#define CanErrorCounter_init_zero                {false, (CanErrorCounter_ErrorCounterSource)0, false, 0}

/* Field tags (for use in manual encoding/decoding) */
#define CanError_source_tag                      1
#define CanErrorCounter_source_tag               1
#define CanErrorCounter_count_tag                2
#define CanMessage_id_tag                        1
#define CanMessage_length_tag                    2
#define CanMessage_rtr_tag                       3
#define CanMessage_data_tag                      4
#define InfoString_info_tag                      1
#define SourceDef_sourceType_tag                 1
#define SourceDef_name_tag                       2
#define StatisticalAggregate_samples_tag         1
#define StatisticalAggregate_min_tag             2
#define StatisticalAggregate_max_tag             3
#define StatisticalAggregate_avg_tag             4
#define StatisticalAggregate_stdev_tag           5
#define DataloggerPayload_sourceDef_tag          1
#define DataloggerPayload_info_tag               2
#define DataloggerPayload_receivedCanMessage_tag 3
#define DataloggerPayload_transmittedCanMessage_tag 4
#define DataloggerPayload_canError_tag           5
#define DataloggerPayload_canErrorCount_tag      6
#define DataloggerPayload_voltageReading_tag     7
#define DataloggerPayload_temperatureReading_tag 8
#define DataloggerPayload_loopTimer_tag          9
#define DataloggerPayload_rtcTime_tag            10
#define DataloggerRecord_timestamp_ms_tag        1
#define DataloggerRecord_timestamp_variability_tag 2
#define DataloggerRecord_sourceId_tag            3
#define DataloggerRecord_payload_tag             4

/* Struct field encoding specification for nanopb */
extern const pb_field_t StatisticalAggregate_fields[6];
extern const pb_field_t DataloggerRecord_fields[5];
extern const pb_field_t DataloggerPayload_fields[11];
extern const pb_field_t SourceDef_fields[3];
extern const pb_field_t InfoString_fields[2];
extern const pb_field_t CanMessage_fields[5];
extern const pb_field_t CanError_fields[2];
extern const pb_field_t CanErrorCounter_fields[3];

/* Maximum encoded size of messages (where known) */
#define StatisticalAggregate_size                45
#define DataloggerRecord_size                    155
#define DataloggerPayload_size                   134
#define SourceDef_size                           36
#define InfoString_size                          131
#define CanMessage_size                          20
#define CanError_size                            2
#define CanErrorCounter_size                     8

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DATALOGGER_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
