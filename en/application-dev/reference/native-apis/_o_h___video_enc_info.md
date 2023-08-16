# OH_VideoEncInfo


## Overview

The **OH_VideoEncInfo** struct defines video encoding parameters.

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
| [videoCodec](#videocodec) | [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat)<br>Defines the video encoding format.| 
| [videoBitrate](#videobitrate) | int32_t<br>Defines the video bit rate.| 
| [videoFrameRate](#videoframerate) | int32_t<br>Defines the video frame rate.| 


## Member Variable Description


### videoBitrate

```
int32_t OH_VideoEncInfo::videoBitrate
```

**Description**

Defines the video bit rate.


### videoCodec

```
OH_VideoCodecFormat OH_VideoEncInfo::videoCodec
```

**Description**

Defines the video encoding format.


### videoFrameRate

```
int32_t OH_VideoEncInfo::videoFrameRate
```

**Description**

Defines the video frame rate.
