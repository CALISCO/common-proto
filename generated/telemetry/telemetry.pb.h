/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9-dev at Sun Mar 19 22:29:30 2017. */

#ifndef PB_TELEMETRY_PB_H_INCLUDED
#define PB_TELEMETRY_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _Telemetry {
    int32_t timestamp_ms;
/* @@protoc_insertion_point(struct:Telemetry) */
} Telemetry;

/* Default values for struct fields */

/* Initializer values for message structs */
#define Telemetry_init_default                   {0}
#define Telemetry_init_zero                      {0}

/* Field tags (for use in manual encoding/decoding) */
#define Telemetry_timestamp_ms_tag               1

/* Struct field encoding specification for nanopb */
extern const pb_field_t Telemetry_fields[2];

/* Maximum encoded size of messages (where known) */
#define Telemetry_size                           11

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TELEMETRY_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
