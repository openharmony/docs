# OH_AVDataSourceExt

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=97963283502ff2ff5f7990ac58edac887f0764b9 translatedAt=2026-08-01T07:17:52.067Z pushedAt=2026-08-01T07:29:10.086Z -->

```c
typedef struct OH_AVDataSourceExt {...} OH_AVDataSourceExt
```

## Overview

The struct describes a user-defined data source. User-defined data can be passed to its callback functions through the **userData** parameter.

**Since**: 20

**Related module**: [CodecBase](capi-codecbase.md)

**Header file**: [native_avcodec_base.h](capi-native-avcodec-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int64_t size | Total size of the data source, in bytes. |
| [OH_AVDataSourceReadAtExt](capi-native-avcodec-base-h.md#oh_avdatasourcereadatext) readAt | Callback for reading data from the data source. |