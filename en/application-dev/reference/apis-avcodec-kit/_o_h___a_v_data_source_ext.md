# OH_AVDataSourceExt


## Overview

The struct describes a user-defined data source. User-defined data can be passed to its callback functions through the **userData** parameter.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 20

**Related module**: [CodecBase](_codec_base.md)

**Header file**: [native_avcodec_base.h](native__avcodec__base_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int64_t [size](#size) | Size of the data source. | 
| [OH_AVDataSourceReadAtExt](_codec_base.md#oh_avdatasourcereadatext) [readAt](#readat) | Callback of the data source. | 


## Member Variable Description


### size

```
int64_t OH_AVDataSourceExt::size
```

**Description**

Size of the data source.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 20


### readAt

```
OH_AVDataSourceReadAtExt OH_AVDataSourceExt::readAt
```

**Description**

Callback of the data source.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 20
