# OH_AudioCaptureInfo


## Overview

The **OH_AudioCaptureInfo** struct defines audio capture information.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [audioSampleRate](#audiosamplerate) | int32_t<br>Defines the audio sampling rate. For details about the supported rates, see **OH_AudioCapturer_GetSamplingRate**.| 
| [audioChannels](#audiochannels) | int32_t<br>Defines the number of audio channels.| 
| [audioSource](#audiosource) | [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype)<br>Defines the audio source.| 


## Member Variable Description


### audioChannels

```
int32_t OH_AudioCaptureInfo::audioChannels
```

**Description**

Defines the number of audio channels.


### audioSampleRate

```
int32_t OH_AudioCaptureInfo::audioSampleRate
```

**Description**

Defines the audio sampling rate. For details about the supported rates, see **OH_AudioCapturer_GetSamplingRate**.


### audioSource

```
OH_AudioCaptureSourceType OH_AudioCaptureInfo::audioSource
```

**Description**

Defines the audio source.
