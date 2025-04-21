# OH_AVRecorder_EncoderInfo


## Overview

The OH_AVRecorder_EncoderInfo struct describes the encoder information.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Related module**: [AVRecorder](_a_v_recorder.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_AVRecorder_CodecMimeType](_a_v_recorder.md#oh_avrecorder_codecmimetype) [mimeType](#mimetype) | MIME type of the encoder.| 
| char \*[type](#type) | Encoder type. The value **audio** means an audio encoder, and **video** means a video encoder.| 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [bitRate](#bitrate) | Bit rate range of the encoder, with the minimum and maximum bit rates specified.| 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [frameRate](#framerate) | Video frame rate range, with the minimum and maximum frame rates specified. This parameter is available only for video encoders.| 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [width](#width) | Video frame width range, with the minimum and maximum widths specified. This parameter is available only for video encoders.| 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [height](#height) | Video frame height range, with the minimum and maximum heights specified. This parameter is available only for video encoders.| 
| [OH_AVRecorder_Range](_o_h___a_v_recorder___range.md) [channels](#channels) | Number of audio channels for the audio capturer, with the minimum and maximum numbers of audio channels specified. This parameter is available only for audio encoders.| 
| int32_t \*[sampleRate](#samplerate) | List of audio sampling rates, including all available audio sampling rates. This parameter is available only for audio encoders.| 
| int32_t [sampleRateLen](#sampleratelen) | Length of the audio sampling rate list.| 


## Member Variable Description


### mimeType

```
OH_AVRecorder_CodecMimeType mimeType
```

**Description**

MIME type of the encoder.


### type

```
char *type
```

**Description**

Encoder type. The value **audio** means an audio encoder, and **video** means a video encoder.


### bitRate

```
OH_AVRecorder_Range bitRate
```

**Description**

Bit rate range of the encoder, with the minimum and maximum bit rates specified.


### frameRate

```
OH_AVRecorder_Range frameRate
```

**Description**

Video frame rate range, with the minimum and maximum frame rates specified. This parameter is available only for video encoders.


### width

```
OH_AVRecorder_Range width
```

**Description**

Video frame width range, with the minimum and maximum widths specified. This parameter is available only for video encoders.


### height

```
OH_AVRecorder_Range height
```

**Description**

Video frame height range, with the minimum and maximum heights specified. This parameter is available only for video encoders.


### channels

```
OH_AVRecorder_Range channels
```

**Description**

Number of audio channels for the audio capturer, with the minimum and maximum numbers of audio channels specified. This parameter is available only for audio encoders.


### sampleRate

```
int32_t *sampleRate
```

**Description**

List of audio sampling rates, including all available audio sampling rates. This parameter is available only for audio encoders.


### sampleRateLen

```
int32_t sampleRateLen
```

**Description**

Length of the audio sampling rate list.
