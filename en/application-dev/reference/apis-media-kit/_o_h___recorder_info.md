# OH_RecorderInfo


## Overview

The OH_RecorderInfo struct describes the recording file information.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)

**Header file**: [native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [url](#url) | URL of the recording file.| 
| uint32_t [urlLen](#urllen) | URL length.| 
| [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype) [fileFormat](#fileformat) | Format of the recording file.| 


## Member Variable Description


### fileFormat

```
OH_ContainerFormatType OH_RecorderInfo::fileFormat
```

**Description**

Format of the recording file.


### url

```
char* OH_RecorderInfo::url
```

**Description**

URL of the recording file.


### urlLen

```
uint32_t OH_RecorderInfo::urlLen
```

**Description**

URL length.
