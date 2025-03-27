# OH_AVRecorder_Profile


## Overview

The OH_AVRecorder_Profile struct describes the parameters used for audio and video recording.

You can choose to record only audio or only video by setting the parameters. When **audioBitrate** or **audioChannels** is set to **0**, audio recording is disabled. When **videoFrameWidth** or **videoFrameHeight** is set to **0**, video recording is disabled.

For details about the value range of each parameter, see [AVRecorderProfile](js-apis-media.md#avrecorderprofile9).

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Related module**: [AVRecorder](_a_v_recorder.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [audioBitrate](#audiobitrate) | Audio bit rate.| 
| int32_t [audioChannels](#audiochannels) | Number of channels.| 
| [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype) [audioCodec](#audiocodec) | Audio encoding format.| 
| int32_t [audioSampleRate](#audiosamplerate) | Audio sampling rate.| 
| [OH_AVRecorder_ContainerFormatType](_a_v_recorder.md#oh_avrecorder_containerformattype) [fileFormat](#fileformat) | Output file format.| 
| int32_t [videoBitrate](#videobitrate) | Video bit rate.| 
| [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype) [videoCodec](#videocodec) | Video encoding format.| 
| int32_t [videoFrameWidth](#videoframewidth) | Video width.| 
| int32_t [videoFrameHeight](#videoframeheight) | Video height.| 
| int32_t [videoFrameRate](#videoframerate) | Video frame rate.| 
| bool [isHdr](#ishdr) | Whether to record HDR videos.| 
| bool [enableTemporalScale](#enabletemporalscale) | Whether to enable temporal scaling encoding mode.| 


## Member Variable Description


### audioBitrate

```
int32_t audioBitrate
```

**Description**

Audio bit rate.


### audioChannels

```
int32_t audioChannels
```

**Description**

Number of channels.


### audioCodec

```
OH_AVRecorder_CodecMimeType audioCodec
```

**Description**

Audio encoding format.


### audioSampleRate

```
int32_t audioSampleRate
```

**Description**

Audio sampling rate.


### fileFormat

```
OH_AVRecorder_ContainerFormatType fileFormat
```

**Description**

Output file format.


### videoBitrate

```
int32_t videoBitrate
```

**Description**

Video bit rate.


### videoCodec

```
OH_AVRecorder_CodecMimeType videoCodec
```

**Description**

Video encoding format.


### videoFrameWidth

```
int32_t videoFrameWidth
```

**Description**

Video width.


### videoFrameHeight

```
int32_t videoFrameHeight
```

**Description**

Video height.


### videoFrameRate

```
int32_t videoFrameRate
```

**Description**

Video frame rate.


### isHdr

```
bool isHdr
```

**Description**

Whether to record HDR videos.


### enableTemporalScale

```
bool enableTemporalScale
```

**Description**

Whether to enable temporal scaling encoding mode.
