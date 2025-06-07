# OH_AVScreenCaptureConfig


## Overview

The OH_AVScreenCaptureConfig struct describes the screen capture configuration.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)

**Header file**: [native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode) [captureMode](#capturemode) | Screen capture mode.| 
| [OH_DataType](_a_v_screen_capture.md#oh_datatype) [dataType](#datatype) | Data type of the screen capture stream.| 
| [OH_AudioInfo](_o_h___audio_info.md) [audioInfo](#audioinfo) | Audio capture information.| 
| [OH_VideoInfo](_o_h___video_info.md) [videoInfo](#videoinfo) | Video capture information.| 
| [OH_RecorderInfo](_o_h___recorder_info.md) [recorderInfo](#recorderinfo) | Recording file information. This member variable is mandatory when the data type is **OH_CAPTURE_FILE**.| 


## Member Variable Description


### audioInfo

```
OH_AudioInfo OH_AVScreenCaptureConfig::audioInfo
```

**Description**

Audio capture information.


### captureMode

```
OH_CaptureMode OH_AVScreenCaptureConfig::captureMode
```

**Description**

Screen capture mode.


### dataType

```
OH_DataType OH_AVScreenCaptureConfig::dataType
```

**Description**

Data type of the screen capture stream.


### recorderInfo

```
OH_RecorderInfo OH_AVScreenCaptureConfig::recorderInfo
```

**Description**

Recording file information. This member variable is mandatory when the data type is **OH_CAPTURE_FILE**.


### videoInfo

```
OH_VideoInfo OH_AVScreenCaptureConfig::videoInfo
```

**Description**

Video capture information.
