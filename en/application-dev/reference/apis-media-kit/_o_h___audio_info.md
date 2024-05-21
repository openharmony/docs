# OH_AudioInfo


## Overview

The OH_AudioInfo struct describes the audio information.

To perform both external capture (using microphones) and internal capture, **audioSampleRate** and **audioChannels** must be the same for both audio channels.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [micCapInfo](#miccapinfo) | External audio capture information.| 
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [innerCapInfo](#innercapinfo) | Internal audio capture information.| 
| [OH_AudioEncInfo](_o_h___audio_enc_info.md) [audioEncInfo](#audioencinfo) | Audio encoding information, which is not required for raw streams.| 


## Member Variable Description


### audioEncInfo

```
OH_AudioEncInfo OH_AudioInfo::audioEncInfo
```

**Description**

Audio encoding information, which is not required for raw streams.



### innerCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::innerCapInfo
```

**Description**

Internal audio capture information.


### micCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::micCapInfo
```

**Description**

External audio capture information.
