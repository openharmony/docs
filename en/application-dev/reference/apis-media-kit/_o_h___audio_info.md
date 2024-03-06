# OH_AudioInfo


## Overview

The **OH_AudioInfo** struct defines audio capture parameters.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [micCapInfo](#miccapinfo) | [OH_AudioCaptureInfo](_o_h___audio_capture_info.md)<br>Defines the audio parameters of the microphone.| 
| [innerCapInfo](#innercapinfo) | [OH_AudioCaptureInfo](_o_h___audio_capture_info.md)<br>Defines the audio parameters for internal capture.| 
| [audioEncInfo](#audioencinfo) | [OH_AudioEncInfo](_o_h___audio_enc_info.md)<br>Defines the audio encoding information. This member variable does not need to be set when **dataType** is set to **OH_ORIGINAL_STREAM**.<br>**NOTE**: This member variable is reserved and will be provided in later versions.| 


## Member Variable Description


### audioEncInfo

```
OH_AudioEncInfo OH_AudioInfo::audioEncInfo
```

**Description**

Defines the audio encoding information. This member variable does not need to be set when **dataType** is set to **OH_ORIGINAL_STREAM**.

> **NOTE**
> 
> This struct is reserved and will be provided in later versions.


### innerCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::innerCapInfo
```

**Description**

Defines the audio parameters for internal capture.


### micCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::micCapInfo
```

**Description**

Defines the audio parameters of the microphone.
