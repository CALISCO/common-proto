/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.5 */

#ifndef PB_TELEMETRY_TELEMETRY_PB_H_INCLUDED
#define PB_TELEMETRY_TELEMETRY_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE { 
    DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_VOLTAGE = 1, 
    DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_CURRENT = 2, 
    DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_TEMPERATURE = 3, 
    DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_MCC = 4, 
    DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_DRIVER_CONTROL = 5 
} DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE;

typedef enum _InfoMessage_MESSAGE_TYPE { 
    InfoMessage_MESSAGE_TYPE_INFO = 1, 
    InfoMessage_MESSAGE_TYPE_DEBUG = 2, 
    InfoMessage_MESSAGE_TYPE_WARNING = 3, 
    InfoMessage_MESSAGE_TYPE_ERROR = 4 
} InfoMessage_MESSAGE_TYPE;

/* Struct definitions */
typedef struct _DeviceInfoMessage_DeviceDelayInfo { 
    bool has_expectedSampleDelay;
    uint32_t expectedSampleDelay; 
    bool has_longestAcceptedSampleDelay;
    uint32_t longestAcceptedSampleDelay; /* statistics on the times between samples */
} DeviceInfoMessage_DeviceDelayInfo;

typedef struct _DeviceInfoMessage_DeviceMeasurementInfo { 
    bool has_readingType;
    DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE readingType; 
    bool has_units;
    char units[4]; 
    bool has_minSensorLimit;
    uint32_t minSensorLimit; 
    bool has_maxSensorLimit;
    uint32_t maxSensorLimit; 
    bool has_minErrorBound;
    uint32_t minErrorBound; 
    bool has_maxErrorBound;
    uint32_t maxErrorBound; 
    bool has_resolution;
    uint32_t resolution; 
    bool has_accuracy;
    uint32_t accuracy; 
} DeviceInfoMessage_DeviceMeasurementInfo;

typedef struct _InfoMessage { 
    bool has_messageType;
    InfoMessage_MESSAGE_TYPE messageType; 
    bool has_message;
    char message[64]; 
} InfoMessage;

typedef struct _StatisticalAggregate { 
    bool has_numSamples;
    uint32_t numSamples; 
    bool has_min;
    uint32_t min; 
    bool has_max;
    uint32_t max; 
    bool has_mean;
    uint32_t mean; 
    bool has_stdev;
    uint32_t stdev; 
} StatisticalAggregate;

/* A DeviceInfoMessage should only be sent if a request is received from the telemetry viewer (ex. if the
      viewer sees a device it hasn't registered yet)
Otherwise, the viewer will just reference its config files (stored offline) for this information
TODO: Make a better model for determining anomalies (a machine learning algorithm perhaps?) */
typedef struct _DeviceInfoMessage { /* send the device ID with its corresponding information */
    bool has_id;
    uint32_t id; 
    bool has_name;
    char name[32]; 
    bool has_measurementInfo;
    DeviceInfoMessage_DeviceMeasurementInfo measurementInfo; 
    bool has_delayInfo;
    DeviceInfoMessage_DeviceDelayInfo delayInfo; 
} DeviceInfoMessage;

typedef struct _MeasurementAggregate { 
    bool has_reading;
    StatisticalAggregate reading; /* id of the device sending this message */
    bool has_sampleDelay;
    StatisticalAggregate sampleDelay; /* time the message is sent */
} MeasurementAggregate;

typedef struct _TelemetryMessage { 
    bool has_id;
    uint32_t id; 
    bool has_timestamp_ms;
    uint32_t timestamp_ms; 
    bool has_timestamp_variability;
    uint32_t timestamp_variability; 
    pb_size_t which_value;
    union {
        MeasurementAggregate sensorReading;
        InfoMessage infoMessage;
        DeviceInfoMessage deviceInfo;
    } value; 
} TelemetryMessage;


/* Helper constants for enums */
#define _DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_MIN DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_VOLTAGE
#define _DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_MAX DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_DRIVER_CONTROL
#define _DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_ARRAYSIZE ((DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE)(DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_DRIVER_CONTROL+1))

#define _InfoMessage_MESSAGE_TYPE_MIN InfoMessage_MESSAGE_TYPE_INFO
#define _InfoMessage_MESSAGE_TYPE_MAX InfoMessage_MESSAGE_TYPE_ERROR
#define _InfoMessage_MESSAGE_TYPE_ARRAYSIZE ((InfoMessage_MESSAGE_TYPE)(InfoMessage_MESSAGE_TYPE_ERROR+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define DeviceInfoMessage_init_default           {false, 0, false, "", false, DeviceInfoMessage_DeviceMeasurementInfo_init_default, false, DeviceInfoMessage_DeviceDelayInfo_init_default}
#define DeviceInfoMessage_DeviceMeasurementInfo_init_default {false, _DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_MIN, false, "", false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define DeviceInfoMessage_DeviceDelayInfo_init_default {false, 0, false, 0}
#define StatisticalAggregate_init_default        {false, 0, false, 0, false, 0, false, 0, false, 0}
#define MeasurementAggregate_init_default        {false, StatisticalAggregate_init_default, false, StatisticalAggregate_init_default}
#define InfoMessage_init_default                 {false, InfoMessage_MESSAGE_TYPE_INFO, false, ""}
#define TelemetryMessage_init_default            {false, 0, false, 0, false, 0, 0, {MeasurementAggregate_init_default}}
#define DeviceInfoMessage_init_zero              {false, 0, false, "", false, DeviceInfoMessage_DeviceMeasurementInfo_init_zero, false, DeviceInfoMessage_DeviceDelayInfo_init_zero}
#define DeviceInfoMessage_DeviceMeasurementInfo_init_zero {false, _DeviceInfoMessage_DeviceMeasurementInfo_READING_TYPE_MIN, false, "", false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define DeviceInfoMessage_DeviceDelayInfo_init_zero {false, 0, false, 0}
#define StatisticalAggregate_init_zero           {false, 0, false, 0, false, 0, false, 0, false, 0}
#define MeasurementAggregate_init_zero           {false, StatisticalAggregate_init_zero, false, StatisticalAggregate_init_zero}
#define InfoMessage_init_zero                    {false, _InfoMessage_MESSAGE_TYPE_MIN, false, ""}
#define TelemetryMessage_init_zero               {false, 0, false, 0, false, 0, 0, {MeasurementAggregate_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define DeviceInfoMessage_DeviceDelayInfo_expectedSampleDelay_tag 1
#define DeviceInfoMessage_DeviceDelayInfo_longestAcceptedSampleDelay_tag 2
#define DeviceInfoMessage_DeviceMeasurementInfo_readingType_tag 1
#define DeviceInfoMessage_DeviceMeasurementInfo_units_tag 2
#define DeviceInfoMessage_DeviceMeasurementInfo_minSensorLimit_tag 3
#define DeviceInfoMessage_DeviceMeasurementInfo_maxSensorLimit_tag 4
#define DeviceInfoMessage_DeviceMeasurementInfo_minErrorBound_tag 5
#define DeviceInfoMessage_DeviceMeasurementInfo_maxErrorBound_tag 6
#define DeviceInfoMessage_DeviceMeasurementInfo_resolution_tag 7
#define DeviceInfoMessage_DeviceMeasurementInfo_accuracy_tag 8
#define InfoMessage_messageType_tag              1
#define InfoMessage_message_tag                  2
#define StatisticalAggregate_numSamples_tag      1
#define StatisticalAggregate_min_tag             2
#define StatisticalAggregate_max_tag             3
#define StatisticalAggregate_mean_tag            4
#define StatisticalAggregate_stdev_tag           5
#define DeviceInfoMessage_id_tag                 1
#define DeviceInfoMessage_name_tag               2
#define DeviceInfoMessage_measurementInfo_tag    3
#define DeviceInfoMessage_delayInfo_tag          4
#define MeasurementAggregate_reading_tag         1
#define MeasurementAggregate_sampleDelay_tag     2
#define TelemetryMessage_id_tag                  1
#define TelemetryMessage_timestamp_ms_tag        2
#define TelemetryMessage_timestamp_variability_tag 3
#define TelemetryMessage_sensorReading_tag       4
#define TelemetryMessage_infoMessage_tag         5
#define TelemetryMessage_deviceInfo_tag          6

/* Struct field encoding specification for nanopb */
#define DeviceInfoMessage_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT32,   id,                1) \
X(a, STATIC,   OPTIONAL, STRING,   name,              2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  measurementInfo,   3) \
X(a, STATIC,   OPTIONAL, MESSAGE,  delayInfo,         4)
#define DeviceInfoMessage_CALLBACK NULL
#define DeviceInfoMessage_DEFAULT NULL
#define DeviceInfoMessage_measurementInfo_MSGTYPE DeviceInfoMessage_DeviceMeasurementInfo
#define DeviceInfoMessage_delayInfo_MSGTYPE DeviceInfoMessage_DeviceDelayInfo

#define DeviceInfoMessage_DeviceMeasurementInfo_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UENUM,    readingType,       1) \
X(a, STATIC,   OPTIONAL, STRING,   units,             2) \
X(a, STATIC,   OPTIONAL, UINT32,   minSensorLimit,    3) \
X(a, STATIC,   OPTIONAL, UINT32,   maxSensorLimit,    4) \
X(a, STATIC,   OPTIONAL, UINT32,   minErrorBound,     5) \
X(a, STATIC,   OPTIONAL, UINT32,   maxErrorBound,     6) \
X(a, STATIC,   OPTIONAL, UINT32,   resolution,        7) \
X(a, STATIC,   OPTIONAL, UINT32,   accuracy,          8)
#define DeviceInfoMessage_DeviceMeasurementInfo_CALLBACK NULL
#define DeviceInfoMessage_DeviceMeasurementInfo_DEFAULT (const pb_byte_t*)"\x08\x01\x00"

#define DeviceInfoMessage_DeviceDelayInfo_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT32,   expectedSampleDelay,   1) \
X(a, STATIC,   OPTIONAL, UINT32,   longestAcceptedSampleDelay,   2)
#define DeviceInfoMessage_DeviceDelayInfo_CALLBACK NULL
#define DeviceInfoMessage_DeviceDelayInfo_DEFAULT NULL

#define StatisticalAggregate_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT32,   numSamples,        1) \
X(a, STATIC,   OPTIONAL, UINT32,   min,               2) \
X(a, STATIC,   OPTIONAL, UINT32,   max,               3) \
X(a, STATIC,   OPTIONAL, UINT32,   mean,              4) \
X(a, STATIC,   OPTIONAL, UINT32,   stdev,             5)
#define StatisticalAggregate_CALLBACK NULL
#define StatisticalAggregate_DEFAULT NULL

#define MeasurementAggregate_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  reading,           1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sampleDelay,       2)
#define MeasurementAggregate_CALLBACK NULL
#define MeasurementAggregate_DEFAULT NULL
#define MeasurementAggregate_reading_MSGTYPE StatisticalAggregate
#define MeasurementAggregate_sampleDelay_MSGTYPE StatisticalAggregate

#define InfoMessage_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UENUM,    messageType,       1) \
X(a, STATIC,   OPTIONAL, STRING,   message,           2)
#define InfoMessage_CALLBACK NULL
#define InfoMessage_DEFAULT (const pb_byte_t*)"\x08\x01\x00"

#define TelemetryMessage_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, UINT32,   id,                1) \
X(a, STATIC,   OPTIONAL, UINT32,   timestamp_ms,      2) \
X(a, STATIC,   OPTIONAL, UINT32,   timestamp_variability,   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,sensorReading,value.sensorReading),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,infoMessage,value.infoMessage),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (value,deviceInfo,value.deviceInfo),   6)
#define TelemetryMessage_CALLBACK NULL
#define TelemetryMessage_DEFAULT NULL
#define TelemetryMessage_value_sensorReading_MSGTYPE MeasurementAggregate
#define TelemetryMessage_value_infoMessage_MSGTYPE InfoMessage
#define TelemetryMessage_value_deviceInfo_MSGTYPE DeviceInfoMessage

extern const pb_msgdesc_t DeviceInfoMessage_msg;
extern const pb_msgdesc_t DeviceInfoMessage_DeviceMeasurementInfo_msg;
extern const pb_msgdesc_t DeviceInfoMessage_DeviceDelayInfo_msg;
extern const pb_msgdesc_t StatisticalAggregate_msg;
extern const pb_msgdesc_t MeasurementAggregate_msg;
extern const pb_msgdesc_t InfoMessage_msg;
extern const pb_msgdesc_t TelemetryMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define DeviceInfoMessage_fields &DeviceInfoMessage_msg
#define DeviceInfoMessage_DeviceMeasurementInfo_fields &DeviceInfoMessage_DeviceMeasurementInfo_msg
#define DeviceInfoMessage_DeviceDelayInfo_fields &DeviceInfoMessage_DeviceDelayInfo_msg
#define StatisticalAggregate_fields &StatisticalAggregate_msg
#define MeasurementAggregate_fields &MeasurementAggregate_msg
#define InfoMessage_fields &InfoMessage_msg
#define TelemetryMessage_fields &TelemetryMessage_msg

/* Maximum encoded size of messages (where known) */
#define DeviceInfoMessage_DeviceDelayInfo_size   12
#define DeviceInfoMessage_DeviceMeasurementInfo_size 43
#define DeviceInfoMessage_size                   98
#define InfoMessage_size                         67
#define MeasurementAggregate_size                64
#define StatisticalAggregate_size                30
#define TelemetryMessage_size                    118

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
