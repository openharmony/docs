# OH_RecorderInfo


## Overview

The **OH_RecorderInfo** struct defines recording file information.

> **NOTE**
>
> This struct is reserved and will be provided in later versions.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [url](#url) | Defines the URL of the recording file.| 
| [urlLen](#urllen) | Defines the URL length.| 
| [fileFormat](#fileformat) | Defines the format of the recording file.| 


## Member Variable Description


### fileFormat

```
OH_ContainerFormatType OH_RecorderInfo::fileFormat
```

**Description**

Defines the format of the recording file.


### url

```
char* OH_RecorderInfo::url
```

**Description**

Defines the URL of the recording file.


### urlLen

```
uint32_t OH_RecorderInfo::urlLen
```

**Description**

Defines the URL length.
