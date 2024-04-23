# OH_AVScreenCaptureConfig


## Overview

The **OH_AVScreenCaptureConfig** struct defines the screen capture configuration.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [captureMode](#capturemode) | [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode)<br>Defines the screen capture mode.| 
| [dataType](#datatype) | [OH_DataType](_a_v_screen_capture.md#oh_datatype)<br>Defines the data type of the screen capture stream.| 
| [audioInfo](#audioinfo) | [OH_AudioInfo](_o_h___audio_info.md)<br>Defines audio capture parameters.| 
| [videoInfo](#videoinfo) | [OH_VideoInfo](_o_h___video_info.md)<br>Defines video capture parameters.| 
| [recorderInfo](#recorderinfo) | [OH_RecorderInfo](_o_h___recorder_info.md)<br>Defines recording file parameters. This member variable is mandatory when the data type is **OH_CAPTURE_FILE**.<br>**NOTE**: This member variable is reserved and will be provided in later versions.| 


## Member Variable Description


### audioInfo

```
OH_AudioInfo OH_AVScreenCaptureConfig::audioInfo
```

**Description**

Defines audio capture parameters.


### captureMode

```
OH_CaptureMode OH_AVScreenCaptureConfig::captureMode
```

**Description**

Defines the screen capture mode.


### dataType

```
OH_DataType OH_AVScreenCaptureConfig::dataType
```

**Description**

Defines the data type of the screen capture stream.


### recorderInfo

```
OH_RecorderInfo OH_AVScreenCaptureConfig::recorderInfo
```

**Description**

Defines recording file parameters. This member variable is mandatory when the data type is **OH_CAPTURE_FILE**.

> **NOTE**
> 
> This member variable is reserved and will be provided in later versions.


### videoInfo

```
OH_VideoInfo OH_AVScreenCaptureConfig::videoInfo
```

**Description**

Defines video capture parameters.
