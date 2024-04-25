# OH_AVDataSource


## Overview

The OH_AVDataSource struct describes a user-defined data source.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12

**Related module**: [CodecBase](_codec_base.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int64_t [size](#size) | Size of the data source. | 
| [OH_AVDataSourceReadAt](_codec_base.md#oh_avdatasourcereadat) [readAt](#readat) | Callback of the data source. | 


## Member Variable Description


### readAt

```
OH_AVDataSourceReadAt OH_AVDataSource::readAt
```

**Description**

Callback of the data source.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12


### size

```
int64_t OH_AVDataSource::size
```

**Description**

Size of the data source.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 12
