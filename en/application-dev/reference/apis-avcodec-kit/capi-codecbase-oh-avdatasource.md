# OH_AVDataSource

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=50836c62c0ce369a817bdec296deca1a95a5488d translatedAt=2026-08-01T07:17:27.092Z pushedAt=2026-08-01T07:29:03.023Z -->

```c
typedef struct OH_AVDataSource {...} OH_AVDataSource
```

## Overview

The struct describes a user-defined data source.

**Since**: 12

**Related module**: [CodecBase](capi-codecbase.md)

**Header file**: [native_avcodec_base.h](capi-native-avcodec-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int64_t size | Total size of the data source, in bytes. |
| [OH_AVDataSourceReadAt](capi-native-avcodec-base-h.md#oh_avdatasourcereadat) readAt | Callback for reading data from the data source. |