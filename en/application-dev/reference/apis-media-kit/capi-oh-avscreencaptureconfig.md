# OH_AVScreenCaptureConfig

## Overview

The OH_AVScreenCaptureConfig struct describes the screen capture configuration.

**Since**: 10

**Related module**: [AVScreenCapture](capi-avscreencapture.md)

**Header file**: [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_CaptureMode](capi-native-avscreen-capture-base-h.md#oh_capturemode) captureMode | Screen capture mode.|
| [OH_DataType](capi-native-avscreen-capture-base-h.md#oh_datatype) dataType | Data type of the screen capture stream.|
| [OH_AudioInfo](capi-oh-audioinfo.md) audioInfo | Audio capture information.|
| [OH_VideoInfo](capi-oh-videoinfo.md) videoInfo | Video capture information.|
| [OH_RecorderInfo](capi-oh-recorderinfo.md) recorderInfo | Recording file information. This member variable is mandatory when the data type is **OH_CAPTURE_FILE**.|
