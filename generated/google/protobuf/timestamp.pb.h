/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.5 */

#ifndef PB_GOOGLE_PROTOBUF_GOOGLE_PROTOBUF_TIMESTAMP_PB_H_INCLUDED
#define PB_GOOGLE_PROTOBUF_GOOGLE_PROTOBUF_TIMESTAMP_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* A Timestamp represents a point in time independent of any time zone
 or calendar, represented as seconds and fractions of seconds at
 nanosecond resolution in UTC Epoch time. It is encoded using the
 Proleptic Gregorian Calendar which extends the Gregorian calendar
 backwards to year one. It is encoded assuming all minutes are 60
 seconds long, i.e. leap seconds are "smeared" so that no leap second
 table is needed for interpretation. Range is from
 0001-01-01T00:00:00Z to 9999-12-31T23:59:59.999999999Z.
 By restricting to that range, we ensure that we can convert to
 and from  RFC 3339 date strings.
 See [https://www.ietf.org/rfc/rfc3339.txt](https://www.ietf.org/rfc/rfc3339.txt).

 Example 1: Compute Timestamp from POSIX `time()`.

     Timestamp timestamp;
     timestamp.set_seconds(time(NULL));
     timestamp.set_nanos(0);

 Example 2: Compute Timestamp from POSIX `gettimeofday()`.

     struct timeval tv;
     gettimeofday(&tv, NULL);

     Timestamp timestamp;
     timestamp.set_seconds(tv.tv_sec);
     timestamp.set_nanos(tv.tv_usec * 1000);

 Example 3: Compute Timestamp from Win32 `GetSystemTimeAsFileTime()`.

     FILETIME ft;
     GetSystemTimeAsFileTime(&ft);
     UINT64 ticks = (((UINT64)ft.dwHighDateTime) << 32) | ft.dwLowDateTime;

     // A Windows tick is 100 nanoseconds. Windows epoch 1601-01-01T00:00:00Z
     // is 11644473600 seconds before Unix epoch 1970-01-01T00:00:00Z.
     Timestamp timestamp;
     timestamp.set_seconds((INT64) ((ticks / 10000000) - 11644473600LL));
     timestamp.set_nanos((INT32) ((ticks % 10000000) * 100));

 Example 4: Compute Timestamp from Java `System.currentTimeMillis()`.

     long millis = System.currentTimeMillis();

     Timestamp timestamp = Timestamp.newBuilder().setSeconds(millis / 1000)
         .setNanos((int) ((millis % 1000) * 1000000)).build();


 Example 5: Compute Timestamp from current time in Python.

     timestamp = Timestamp()
     timestamp.GetCurrentTime() */
typedef struct _google_protobuf_Timestamp { 
    /* Represents seconds of UTC time since Unix epoch
 1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
 9999-12-31T23:59:59Z inclusive. */
    int64_t seconds; 
    /* Non-negative fractions of a second at nanosecond resolution. Negative
 second values with fractions must still have non-negative nanos values
 that count forward in time. Must be from 0 to 999,999,999
 inclusive. */
    int32_t nanos; 
} google_protobuf_Timestamp;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define google_protobuf_Timestamp_init_default   {0, 0}
#define google_protobuf_Timestamp_init_zero      {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define google_protobuf_Timestamp_seconds_tag    1
#define google_protobuf_Timestamp_nanos_tag      2

/* Struct field encoding specification for nanopb */
#define google_protobuf_Timestamp_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT64,    seconds,           1) \
X(a, STATIC,   SINGULAR, INT32,    nanos,             2)
#define google_protobuf_Timestamp_CALLBACK NULL
#define google_protobuf_Timestamp_DEFAULT NULL

extern const pb_msgdesc_t google_protobuf_Timestamp_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define google_protobuf_Timestamp_fields &google_protobuf_Timestamp_msg

/* Maximum encoded size of messages (where known) */
#define google_protobuf_Timestamp_size           22

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
