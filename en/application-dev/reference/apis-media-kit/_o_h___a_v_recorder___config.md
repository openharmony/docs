# OH_AVRecorder_Config


## Overview

The OH_AVRecorder_Config struct describes the AVRecorder configuration.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Related module**: [AVRecorder](_a_v_recorder.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_AVRecorder_AudioSourceType](_a_v_recorder.md#oh_avrecorder_audiosourcetype) [audioSourceType](#audiosourcetype) | Type of the audio source to record.| 
| [OH_AVRecorder_VideoSourceType](_a_v_recorder.md#oh_avrecorder_videosourcetype) [videoSourceType](#videosourcetype) | Type of the video source to record.| 
| [OH_AVRecorder_Profile](_o_h___a_v_recorder___profile.md) [profile](#profile) | Audio and video encoding configuration.| 
| char \*[url](#url) | URL of the recording output file, in the format of fd://xx.| 
| [OH_AVRecorder_FileGenerationMode](_a_v_recorder.md#oh_avrecorder_filegenerationmode) [fileGenerationMode](#filegenerationmode) | Mode for generating the recording output file.| 
| [OH_AVRecorder_Metadata](_o_h___a_v_recorder___metadata.md) [metadata](#metadata) | Metadata of the recorded media.| 


## Member Variable Description


### audioSourceType

```
OH_AVRecorder_AudioSourceType audioSourceType
```

**Description**

Type of the audio source to record.


### videoSourceType

```
OH_AVRecorder_VideoSourceType videoSourceType
```

**Description**

Type of the video source to record.


### profile

```
OH_AVRecorder_Profile profile
```

**Description**

Audio and video encoding configuration.


### url

```
char *url
```

**Description**

URL of the recording output file, in the format of fd://xx.


### fileGenerationMode

```
OH_AVRecorder_FileGenerationMode fileGenerationMode
```

**Description**

Mode for generating the recording output file.


### metadata

```
OH_AVRecorder_Metadata metadata
```

**Description**

Metadata of the recorded media.
