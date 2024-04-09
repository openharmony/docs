# Multimedia Subsystem Changelog

## cl.multimedia.1 Core Module APIs Changed

**Access Level**

Public API

**Reason for Change**

The **AVMemory** struct is deprecated and replaced by **AVBuffer**.

**Change Impact**

The change is compatible with earlier versions. Use the new APIs in your code.


**API Level**

|         Deprecated API        |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AVMemory_Create | 10 |
| OH_AVMemory_GetAddr | 9 |
| OH_AVMemory_GetSize  | 9 |
| OH_AVMemory_Destroy  | 10 |

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

|         Deprecated API        |          Deprecated Description               | Substitute API                     |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AVMemory_Create | The API for creating an **AVMemory** instance is deprecated, and the API for creating an **AVBuffer** instance is supported.|OH_AVBuffer_Create|
| OH_AVMemory_GetAddr | The API for obtaining the virtual address of the memory is deprecated, and the API for obtaining the buffer address is supported.|OH_AVBuffer_GetAddr|
| OH_AVMemory_GetSize  | The API for obtaining the memory length is deprecated, and the API for obtaining the buffer length is supported.|OH_AVBuffer_GetCapacity |
| OH_AVMemory_Destroy  | The API for destroying an **AVMemory** instance is deprecated, and the API for destroying an **AVBuffer** instance is supported.|OH_AVBuffer_Destroy |


**Adaptation Guide**

Before change:

In the code for implementing media encoding/decoding and muxing/demuxing, use the **AVMemory** APIs to operate the data memory.

After change:

In the code for implementing media encoding/decoding and muxing/demuxing, use the **AVBuffer** APIs to operate the data memory.

## cl.multimedia.2 CodecBase Module APIs Changed

**Access Level**

Public API

**Reason for Change**

The **AVMemory** struct is deprecated and replaced by **AVBuffer**. Unsupported specifications are removed.

**Change Impact**

The change is compatible with earlier versions. Use the new APIs in your code.

**API Level**

|         API        |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AVCodecOnNeedInputData | 9 |
| OH_AVCodecOnNewOutputData | 9 |
| OH_AVCodecAsyncCallback  | 9 |
| const char *OH_AVCODEC_MIMETYPE_VIDEO_MPEG4  | 10 |
| AudioChannelSet | 10 |
| AudioChanelLayout | 10 |

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

|         Deprecated API        |          Deprecated Description               | Substitute API                     |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AVCodecOnNeedInputData | The callback function for codec input data is changed from **AVMemory** to **AVBuffer**.|OH_AVCodecOnNeedInputBuffer|
| OH_AVCodecOnNewOutputData | The callback function for codec output data is changed from **AVMemory** to **AVBuffer**.|OH_AVCodecOnNewOutputBuffer|
| OH_AVCodecAsyncCallback  | The pointer to the registered callback functions is changed from **AVMemory** to **AVBuffer**.|OH_AVCodecCallback |
| const char *OH_AVCODEC_MIMETYPE_VIDEO_MPEG4  | This specification is no longer supported.|None|
| AudioChannelSet | The API name is changed.| OH_AudioChannelSet |
| AudioChanelLayout | The API name is changed.| OH_AudioChannelLayout |

**Adaptation Guide**

Before change:

Pointer to the registered callback functions **OH_AVCodecAsyncCallback** for the audio and video codec:

Implementation of the codec input callback: **OH_AVCodecOnNeedInputData**

Implementation of the codec output callback: **OH_AVCodecOnNewOutputData**

Container format: **OH_AVCODEC_MIMETYPE_VIDEO_MPEG4**

Audio channel settings: **AudioChannelSet**

Audio channel layouts: **AudioChanelLayout**

After change:

Pointer to the registered callback functions **OH_AVCodecCallback** for the audio and video codec:

Implementation of the codec input callback: **OH_AVCodecOnNeedInputBuffer**

Implementation of the codec output callback: **OH_AVCodecOnNewOutputBuffer**

Container format **OH_AVCODEC_MIMETYPE_VIDEO_MPEG4**: no longer supported

Audio channel settings: **OH_AudioChannelSet**

Audio channel layouts: **OH_AudioChannelLayout**

## cl.multimedia.3 VideoDecoder Module APIs Changed

**Access Level**

Public API

**Reason for Change**

The **AVMemory** struct is deprecated and replaced by **AVBuffer**.

**Change Impact**

The change is compatible with earlier versions. Use the new APIs in your code.

**API Level**

|         API        |          API Level                |
| ----------------------- | :--------------------------------|
| OH_VideoDecoder_SetCallback | 9 |
| OH_VideoDecoder_PushInputData | 9 |
| OH_VideoDecoder_RenderOutputData  | 9 |
| OH_VideoDecoder_FreeOutputData  | 9 |

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

|         Deprecated API        |          Deprecated Description               | Substitute API                     |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_VideoDecoder_SetCallback | The **AVBuffer** struct is used in the callback function registration.|OH_VideoDecoder_RegisterCallback|
| OH_VideoDecoder_PushInputData | The **AVBuffer** struct is used in the decoder's input stream data.|OH_VideoDecoder_PushInputBuffer|
| OH_VideoDecoder_RenderOutputData  | The **AVBuffer** struct is used in the decoder's output rendering control.|OH_VideoDecoder_RenderOutputBuffer |
| OH_VideoDecoder_FreeOutputData  | The **AVBuffer** struct is used in the decoder's output rendering release.|OH_VideoDecoder_FreeOutputBuffer |

**Adaptation Guide**

Before change:

Call **OH_VideoDecoder_SetCallback()** to set callback functions.

Call **OH_VideoDecoder_PushInputData** to fill in stream data when an input callback is received.

Call **OH_VideoDecoder_FreeOutputData** to release the output image or **OH_VideoDecoder_RenderOutputData** to render the image when an output callback is received.

After change:

Call **OH_VideoDecoder_RegisterCallback()** to set callback functions.

Call **OH_VideoDecoder_PushInputBuffer** to fill in stream data when an input callback is received.

Call **OH_VideoDecoder_FreeOutputBuffer** to release the output image or **OH_VideoDecoder_RenderOutputBuffer** to render the image when an output callback is received.


## cl.multimedia.4 VideoEncoder Module APIs Changed

**Access Level**

Public API

**Reason for Change**

The **AVMemory** struct is deprecated and replaced by **AVBuffer**.

**Change Impact**

The change is compatible with earlier versions. Use the new APIs in your code.

**API Level**

|         API        |          API Level                |
| ----------------------- | :--------------------------------|
| OH_VideoEncoder_SetCallback | 9 |
| OH_VideoEncoder_PushInputData | 9 |
| OH_VideoEncoder_FreeOutputData  | 9 |

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

|         Deprecated API        |          Deprecated Description               | Substitute API                     |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_VideoEncoder_SetCallback | The **AVBuffer** struct is used in the callback function registration.|OH_VideoEncoder_RegisterCallback|
| OH_VideoEncoder_PushInputData | The **AVBuffer** struct is used in the encoder's input stream data.|OH_VideoEncoder_PushInputBuffer|
| OH_VideoEncoder_FreeOutputData  | The **AVBuffer** struct is used in the encoder's output rendering release.|OH_VideoEncoder_FreeOutputBuffer |

**Adaptation Guide**

Before change:

Call **OH_VideoEncoder_SetCallback()** to set callback functions.

Call **OH_VideoEncoder_PushInputData** to fill in data to encode when an input callback is received.

Call **OH_VideoEncoder_FreeOutputData** to release output data when an output callback is received.

After change:

Call **OH_VideoEncoder_RegisterCallback()** to set callback functions.

Call **OH_VideoEncoder_PushInputBuffer** to fill in data to encode when an input callback is received.

Call **OH_VideoEncoder_FreeOutputBuffer** to release output data when an output callback is received.


## cl.multimedia.5 AVDemuxer Module APIs Changed

**Access Level**

Public API

**Reason for Change**

The **AVMemory** struct is deprecated and replaced by **AVBuffer**.

**Change Impact**

The change is compatible with earlier versions. Use the new API in your code.

**API Level**

|         API        |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AVDemuxer_ReadSample | 10 |

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

|         Deprecated API        |          Deprecated Description               | Substitute API                     |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AVDemuxer_ReadSample | The **AVBuffer** struct is used when the demuxer reads frames.|OH_AVDemuxer_ReadSampleBuffer|

**Adaptation Guide**

Before change:

**OH_AVDemuxer_ReadSample()** is used to read compressed frames and related information.

After change:

Call **OH_AVDemuxer_ReadSampleBuffer()** to read compressed frames and related information.

## cl.multimedia.6 AVMuxer Module APIs Changed

**Access Level**

Public API

**Reason for Change**

The **AVMemory** struct is deprecated and replaced by **AVBuffer**.

**Change Impact**

The change is compatible with earlier versions. Use the new API in your code.

**API Level**

|         API        |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AVMuxer_WriteSample | 10 |

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

|         Deprecated API        |          Deprecated Description               | Substitute API                     |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AVMuxer_WriteSample | The **AVBuffer** struct is used when the muxer writes frames.|OH_AVMuxer_WriteSampleBuffer|

**Adaptation Guide**

Before change:

Call **OH_AVMuxer_WriteSample()** to write compressed frames and related information.

After change:

Call **OH_AVMuxer_WriteSampleBuffer()** to write compressed frames and related information.

## cl.multimedia.7 AudioDecoder Module APIs Changed

**Access Level**

Public API

**Reason for Change**

The **AVMemory** struct is deprecated and replaced by **AVBuffer**. The **AudioDecoder** module is changed to the **AudioCodec** module.

**Change Impact**

The change is compatible with earlier versions. Use the new APIs in your code.

**API Level**

|         API        |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AudioDecoder_CreateByName | 9 |
| OH_AudioDecoder_CreateByMime | 9 |
| OH_AudioDecoder_SetCallback | 9 |
| OH_AudioDecoder_Configure | 9 |
| OH_AudioDecoder_Prepare | 9 |
| OH_AudioDecoder_Start | 9 |
| OH_AudioDecoder_PushInputData | 9 |
| OH_AudioDecoder_FreeOutputData | 9 |
| OH_AudioDecoder_Flush | 9 |
| OH_AudioDecoder_IsValid | 10 |
| OH_AudioDecoder_Reset | 9 |
| OH_AudioDecoder_Stop | 9 |
| OH_AudioDecoder_Destroy | 9 |


**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

|         Deprecated API        |          Deprecated Description               | Substitute API                     |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AudioDecoder_CreateByName | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_CreateByName |
| OH_AudioDecoder_CreateByMime | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_CreateByMime |
| OH_AudioDecoder_SetCallback | The **AudioDecoder** module is changed to the **AudioCodec** module. The **AVBuffer** struct is used in the callback function registration.| OH_AudioCodec_RegisterCallback |
| OH_AudioDecoder_Configure | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Configure |
| OH_AudioDecoder_Prepare | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Prepare |
| OH_AudioDecoder_Start | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Start |
| OH_AudioDecoder_PushInputData | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_PushInputBuffer |
| OH_AudioDecoder_FreeOutputData | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_FreeOutputBuffer |
| OH_AudioDecoder_Flush | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Flush |
| OH_AudioDecoder_IsValid | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_IsValid |
| OH_AudioDecoder_Reset | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Reset |
| OH_AudioDecoder_Stop | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Stop |
| OH_AudioDecoder_Destroy | The **AudioDecoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Destroy |

**Adaptation Guide**

Before change:

Call **OH_AudioDecoder_CreateByName()** or **OH_AudioDecoder_CreateByMime()** to create a decoder.

Call **OH_AudioDecoder_SetCallback()** to set callback functions.

Call **OH_AudioDecoder_Configure()** to configure the decoder.

Call **OH_AudioDecoder_Prepare()** to prepare internal resources for the decoder.

Call **OH_AudioDecoder_Start()** to start the decoder.

Call **OH_AudioDecoder_PushInputData()** to write the data to decode.

Call **OH_AudioDecoder_FreeOutputData()** to output decoded PCM streams.

(Optional) Call **OH_AudioDecoder_Flush()** to refresh the decoder.

(Optional) Call **OH_AudioDecoder_IsValid()** to determine whether the execution can be continued.

(Optional) Call **OH_AudioDecoder_Reset()** to reset the decoder.

Call **OH_AudioDecoder_Stop()** to stop the decoder.

Call **OH_AudioDecoder_Destroy()** to destroy the decoder instance and release resources.

After change:

Call **OH_AudioCodec_CreateByName()** or **OH_AudioCodec_CreateByMime** to create a codec.

Call **OH_AudioCodec_SetCallback()** to set callback functions.

Call **OH_AudioCodec_Configure()** to configure the codec.

Call **OH_AudioCodec_Prepare()** to prepare internal resources for the codec.

Call **OH_AudioCodec_Start()** to start the codec.

Call **OH_AudioCodec_PushInputData()** to write the data to decode.

Call **OH_AudioCodec_FreeOutputData()** to output the codec stream.

(Optional) Call **OH_AudioCodec_Flush()** to refresh the codec.

(Optional) Call **OH_AudioCodec_IsValid()** to determine whether the execution can be continued.

(Optional) Call **OH_AudioCodec_Reset()** to reset the codec.

Call **OH_AudioCodec_Stop()** to stop the codec.

Call **OH_AudioCodec_Destroy()** to destroy the codec instance and release resources.

## cl.multimedia.8 AudioEncoder Module APIs Changed

**Access Level**

Public API

**Reason for Change**

The **AVMemory** struct is deprecated and replaced by **AVBuffer**. The **AudioEncoder** module is changed to the **AudioCodec** module.

**Change Impact**

The change is compatible with earlier versions. Use the new APIs in your code.

**API Level**

|         API        |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AudioEncoder_CreateByName | 9 |
| OH_AudioEncoder_CreateByMime | 9 |
| OH_AudioEncoder_SetCallback | 9 |
| OH_AudioEncoder_Configure | 9 |
| OH_AudioEncoder_Prepare | 9 |
| OH_AudioEncoder_Start | 9 |
| OH_AudioEncoder_PushInputData | 9 |
| OH_AudioEncoder_FreeOutputData | 9 |
| OH_AudioEncoder_Flush | 9 |
| OH_AudioEncoder_IsValid | 10 |
| OH_AudioEncoder_Reset | 9 |
| OH_AudioEncoder_Stop | 9 |
| OH_AudioEncoder_Destroy | 9 |


**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

|         Deprecated API        |          Deprecated Description               | Substitute API                     |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AudioEncoder_CreateByName | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_CreateByName |
| OH_AudioEncoder_CreateByMime | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_CreateByMime |
| OH_AudioEncoder_SetCallback | The **AudioEncoder** module is changed to the **AudioCodec** module. The **AVBuffer** struct is used in the callback function registration.| OH_AudioCodec_RegisterCallback |
| OH_AudioEncoder_Configure | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Configure |
| OH_AudioEncoder_Prepare | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Prepare |
| OH_AudioEncoder_Start | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Start |
| OH_AudioEncoder_PushInputData | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_PushInputBuffer |
| OH_AudioEncoder_FreeOutputData | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_FreeOutputBuffer |
| OH_AudioEncoder_Flush | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Flush |
| OH_AudioEncoder_IsValid | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_IsValid |
| OH_AudioEncoder_Reset | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Reset |
| OH_AudioEncoder_Stop | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Stop |
| OH_AudioEncoder_Destroy | The **AudioEncoder** module is changed to the **AudioCodec** module.| OH_AudioCodec_Destroy |

**Adaptation Guide**

Before change:

Call **OH_AudioEncoder_CreateByName()** or **OH_AudioEncoder_CreateByMime** to create an encoder.

Call **OH_AudioEncoder_SetCallback()** to set callback functions.

Call **OH_AudioEncoder_Configure()** to configure the encoder.

Call **OH_AudioEncoder_Prepare()** to prepare internal resources for the encoder.

Call **OH_AudioEncoder_Start()** to start the encoder.

Call **OH_AudioEncoder_PushInputData()** to write the data to encode.

Call **OH_AudioEncoder_FreeOutputData()** to output the encoded stream.

(Optional) Call **OH_AudioEncoder_Flush()** to refresh the encoder.

(Optional) Call **OH_AudioEncoder_IsValid()** to determine whether the execution can be continued.

(Optional) Call **OH_AudioEncoder_Reset()** to reset the encoder.

Call **OH_AudioEncoder_Stop()** to stop the encoder.

Call **OH_AudioEncoder_Destroy()** to destroy the encoder instance and release resources.

After change:

Call **OH_AudioCodec_CreateByName()** or **OH_AudioCodec_CreateByMime** to create a codec.

Call **OH_AudioCodec_SetCallback()** to set callback functions.

Call **OH_AudioCodec_Configure()** to configure the codec.

Call **OH_AudioCodec_Prepare()** to prepare internal resources for the codec.

Call **OH_AudioCodec_Start()** to start the codec.

Call **OH_AudioCodec_PushInputData()** to write the data to decode.

Call **OH_AudioCodec_FreeOutputData()** to output the codec stream.

(Optional) Call **OH_AudioCodec_Flush()** to refresh the codec.

(Optional) Call **OH_AudioCodec_IsValid()** to determine whether the execution can be continued.

(Optional) Call **OH_AudioCodec_Reset()** to reset the codec.

Call **OH_AudioCodec_Stop()** to stop the codec.

Call **OH_AudioCodec_Destroy()** to destroy the codec instance and release resources.

## cl.multimedia.9 Format Specifications Supported by AVPlayer and AVRecorder Changed

**Access Level**

Public API

**Reason for Change**

The **AVCodec** struct is used for muxing/demuxing and encoding/decoding.

**Change Impact**

The following formats are not supported:
Container format: WebM
Video decoding formats: H.263, MPEG2, MPEG4, and VP8
Video encoding format: MPEG4

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**
**AVPlayer** and **AVRecorder**

**Adaptation Guide**
1. Use MPEG4 rather than AVC for video encoding.
2. If the container format WebM or video decoding format H.263/MPEG2/MPEG4/VP8 is used, the playback fails. In this case, you are advised to use the resources in the container format MP4 and video decoding format AVC.
