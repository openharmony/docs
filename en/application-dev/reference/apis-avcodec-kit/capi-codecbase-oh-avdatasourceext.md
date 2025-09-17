# OH_AVDataSourceExt

## Overview

The struct describes a user-defined data source. User-defined data can be passed to its callback functions through the **userData** parameter.

**Since**: 20

**Related module**: [CodecBase](capi-codecbase.md)

**Header file**: [native_avcodec_base.h](capi-native-avcodec-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int64_t size | Size of the data source.|
| [OH_AVDataSourceReadAtExt](capi-native-avcodec-base-h.md#oh_avdatasourcereadatext) readAt | Callback of the data source.|
