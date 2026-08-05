# native_avcodec_videoencoder.h
<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the APIs used for video encoding.

**File to include**: <multimedia/player_framework/native_avcodec_videoencoder.h>

**Library**: libnative_media_venc.so

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Related module**: [VideoEncoder](capi-videoencoder.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

The support status of APIs for each version, mode, and state is described in the following table.

### API State Matrix

The following provides an overview of whether the API can be called in different states. A checkmark (√) indicates that the API can be called, and a cross (×) indicates that it cannot be called.

| API| Initialized | Configured | Prepared | Flushed | Running | EndOfStream | Error | Released |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| OH_VideoEncoder_CreateByMime<sup>9+</sup> | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| OH_VideoEncoder_CreateByName<sup>9+</sup> | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| OH_VideoEncoder_CreatePrimaryWithPreproc | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| OH_VideoEncoder_CreateSecondaryFromPrimary | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| OH_VideoEncoder_RegisterCallback<sup>11+</sup> | √ | √ | × | × | × | × | × | × |
| OH_VideoEncoder_RegisterParameterCallback<sup>12+</sup> | √ | × | × | × | × | × | × | × |
| OH_VideoEncoder_OnNeedInputParameter<sup>12+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_Configure<sup>9+</sup> | √ | × | × | × | × | × | × | × |
| OH_VideoEncoder_Prepare<sup>9+</sup> | × | √ | × | × | × | × | × | × |
| OH_VideoEncoder_SetParameter<sup>9+</sup> | × | × | × | √ | √ | √ | × | × |
| OH_VideoEncoder_GetSurface<sup>9+</sup> | × | √ | × | × | × | × | × | × |
| OH_VideoEncoder_GetInputDescription<sup>10+</sup> | × | √ | √ | √ | √ | √ | × | × |
| OH_VideoEncoder_PushInputBuffer<sup>11+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_PushInputParameter<sup>12+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_NotifyEndOfStream<sup>9+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_GetOutputDescription<sup>9+</sup> | √ | √ | √ | √ | √ | √ | × | × |
| OH_VideoEncoder_FreeOutputBuffer<sup>11+</sup> | × | × | × | × | √ | √ | × | × |
| OH_VideoEncoder_Start<sup>9+</sup> | × | × | √ | √ | × | × | × | × |
| OH_VideoEncoder_Stop<sup>9+</sup> | × | × | × | √ | √ | √ | × | × |
| OH_VideoEncoder_Flush<sup>9+</sup> | × | × | × | × | √ | √ | × | × |
| OH_VideoEncoder_Reset<sup>9+</sup> | √ | √ | √ | √ | √ | √ | √ | × |
| OH_VideoEncoder_Destroy<sup>9+</sup> | √ | √ | √ | √ | √ | √ | √ | × |
| OH_VideoEncoder_QueryInputBuffer<sup>20+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_GetInputBuffer<sup>20+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_QueryOutputBuffer<sup>20+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_GetOutputBuffer<sup>20+</sup> | × | × | × | × | √ | × | × | × |

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_VideoEncodeBitrateMode](#oh_videoencodebitratemode) | OH_VideoEncodeBitrateMode | Enumerates the bit rate modes of a video encoder. (It is deprecated from API version 14.)|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_VideoEncoder_OnNeedInputParameter)(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter, void *userData)](#oh_videoencoder_onneedinputparameter) | OH_VideoEncoder_OnNeedInputParameter | Defines the pointer to the function that is called when new input parameters are required for a frame with the specified index. This API takes effect only in surface mode.|
| [OH_AVCodec *OH_VideoEncoder_CreateByMime(const char *mime)](#oh_videoencoder_createbymime) | - | Creates a video encoder instance based on a MIME type. This function is recommended.|
| [OH_AVCodec *OH_VideoEncoder_CreateByName(const char *name)](#oh_videoencoder_createbyname) | - | Creates a video encoder instance based on an encoder name. To use this function, you must know the exact name of the encoder. The encoder name can be obtained through capability query.|
| [OH_AVErrCode OH_VideoEncoder_CreatePrimaryWithPreproc(const char *mime, OH_AVCodec **codec)](#oh_videoencoder_createprimarywithpreproc) | - | Creates a primary video encoder instance that supports pre-processing. It can be used to configure pre-processing parameters such as downsampling, cropping, and frame dropping. A secondary encoder can be derived from this primary encoder to enable dual-output encoding with one input.|
| [OH_AVErrCode OH_VideoEncoder_CreateSecondaryFromPrimary(OH_AVCodec *primary, OH_AVCodec **codec)](#oh_videoencoder_createsecondaryfromprimary) | - | Creates a secondary video encoder instance from the primary encoder. The secondary video encoder shares the input source with the primary encoder and allows independent configuration of encoding parameters and pre-processing parameters.|
| [OH_AVErrCode OH_VideoEncoder_Destroy(OH_AVCodec *codec)](#oh_videoencoder_destroy) | - | Clears the internal resources of a video encoder and destroys the encoder instance. You only need to call the function once.|
| [OH_AVErrCode OH_VideoEncoder_SetCallback(OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData)](#oh_videoencoder_setcallback) | - | Sets the OH_AVCodecAsyncCallback callback so that your application can respond to events generated by a video encoder. This function must be called prior to **OH_VideoEncoder_Prepare**. (It is deprecated from API version 11.)|
| [OH_AVErrCode OH_VideoEncoder_RegisterCallback(OH_AVCodec *codec, OH_AVCodecCallback callback, void *userData)](#oh_videoencoder_registercallback) | - | Registers an OH_AVCodecCallback callback so that your application can respond to events generated by a video encoder. This function must be called prior to **OH_VideoEncoder_Prepare**.|
| [OH_AVErrCode OH_VideoEncoder_RegisterParameterCallback(OH_AVCodec *codec, OH_VideoEncoder_OnNeedInputParameter onInputParameter, void *userData)](#oh_videoencoder_registerparametercallback) | - | Registers the OH_VideoEncoder_OnNeedInputParameter input parameter callback so that your application can respond to events generated by a video encoder. In surface encoding mode, this API must be called when frame-specific parameters need to be set.<br> and it must be called before [OH_VideoEncoder_Configure](#oh_videoencoder_configure).|
| [OH_AVErrCode OH_VideoEncoder_Configure(OH_AVCodec *codec, OH_AVFormat *format)](#oh_videoencoder_configure) | - | Configures encoding parameters for a video encoder. Typically, you need to configure the description information about the video frames, such as the frame width, height, and pixel format. This function must be called prior to **OH_VideoEncoder_Prepare**.|
| [OH_AVErrCode OH_VideoEncoder_Prepare(OH_AVCodec *codec)](#oh_videoencoder_prepare) | - | Prepares internal resources for a video encoder. This function must be called after **OH_VideoEncoder_Configure**.|
| [OH_AVErrCode OH_VideoEncoder_Start(OH_AVCodec *codec)](#oh_videoencoder_start) | - | Starts a video encoder. This function should be called after a successful call of [OH_VideoEncoder_Prepare](#oh_videoencoder_prepare). After being started, the encoder starts to report the registered event.|
| [OH_AVErrCode OH_VideoEncoder_Stop(OH_AVCodec *codec)](#oh_videoencoder_stop) | - | Stops a video encoder and releases the input and output buffers. After the video encoder is stopped, you can call **OH_VideoEncoder_Start** to enter the running state again.|
| [OH_AVErrCode OH_VideoEncoder_Flush(OH_AVCodec *codec)](#oh_videoencoder_flush) | - | Clears the input and output data and parameters, for example, H.264 PPS/SPS, cached in a video encoder.<br>This function invalidates the indexes of all buffers previously reported through the asynchronous callback. Therefore, before calling this function, ensure that the buffers with the specified indexes are no longer required. This function cannot be called consecutively.|
| [OH_AVErrCode OH_VideoEncoder_Reset(OH_AVCodec *codec)](#oh_videoencoder_reset) | - | Resets a video encoder. The encoder returns to the initial state. To continue encoding, you must call **OH_VideoEncoder_Configure** to configure the encoder again.|
| [OH_AVFormat *OH_VideoEncoder_GetOutputDescription(OH_AVCodec *codec)](#oh_videoencoder_getoutputdescription) | - | Obtains the OH_AVFormat information about the output data of a video encoder.<br> You must call [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) to release the OH_AVFormat instance in the return value.|
| [OH_AVErrCode OH_VideoEncoder_SetParameter(OH_AVCodec *codec, OH_AVFormat *format)](#oh_videoencoder_setparameter) | - | Sets the encoder parameter when a video encoder is running.<br> This function can be called only after the encoder is started. Incorrect parameter settings may cause encoding failure.|
| [OH_AVErrCode OH_VideoEncoder_GetSurface(OH_AVCodec *codec, OHNativeWindow **window)](#oh_videoencoder_getsurface) | - | Obtains the input surface from a video encoder. This function must be called after **OH_VideoEncoder_Configure** but before **OH_VideoEncoder_Prepare**.|
| [OH_AVErrCode OH_VideoEncoder_FreeOutputData(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_freeoutputdata) | - | Frees an output buffer of a video encoder. (It is deprecated from API version 11.)|
| [OH_AVErrCode OH_VideoEncoder_NotifyEndOfStream(OH_AVCodec *codec)](#oh_videoencoder_notifyendofstream) | - | Notifies a video encoder that input streams end. You are advised to use this function for notification. This function is used only in surface mode. In buffer mode, OH_AVBuffer is used to carry the EOS information to notify the end of the input stream.|
| [OH_AVErrCode OH_VideoEncoder_PushInputData(OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr)](#oh_videoencoder_pushinputdata) | - | Pushes the input buffer filled with data to a video encoder. (It is deprecated from API version 11.)|
| [OH_AVErrCode OH_VideoEncoder_PushInputBuffer(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_pushinputbuffer) | - | Pushes the OH_AVBuffer corresponding to the index to a video encoder in buffer mode.|
| [OH_AVErrCode OH_VideoEncoder_PushInputParameter(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_pushinputparameter) | - | Pushes the parameter configured for a frame with the given index to a video encoder in surface mode.|
| [OH_AVErrCode OH_VideoEncoder_FreeOutputBuffer(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_freeoutputbuffer) | - | Returns the processed OH_AVBuffer corresponding to the index to a video encoder. You need to call this function to release the output buffer in a timely manner. Otherwise, the encoding process is blocked.|
| [OH_AVFormat *OH_VideoEncoder_GetInputDescription(OH_AVCodec *codec)](#oh_videoencoder_getinputdescription) | - | Obtains the description of the image received by a video encoder. This function must be called after [OH_VideoEncoder_Configure](#oh_videoencoder_configure) is called.<br> You must call [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) to release the OH_AVFormat instance in the return value.|
| [OH_AVErrCode OH_VideoEncoder_IsValid(OH_AVCodec *codec, bool *isValid)](#oh_videoencoder_isvalid) | - | Checks whether the encoder service is valid when an encoder instance exists.|
| [OH_AVErrCode OH_VideoEncoder_QueryInputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)](#oh_videoencoder_queryinputbuffer) | - | Obtains the index of the next available input buffer.<br> After calling this function, you must call [OH_VideoEncoder_GetInputBuffer](#oh_videoencoder_getinputbuffer) to obtain the buffer instance and call [OH_VideoEncoder_PushInputBuffer](#oh_videoencoder_pushinputbuffer) to pass the buffer instance to the encoder.<br> Note that the preceding operations are supported only in synchronous mode.|
| [OH_AVBuffer *OH_VideoEncoder_GetInputBuffer(struct OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_getinputbuffer) | - | Obtains the instance of the available input buffer.<br> Note that this function works only in synchronous mode.|
| [OH_AVErrCode OH_VideoEncoder_QueryOutputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)](#oh_videoencoder_queryoutputbuffer) | - | Obtains the index of the next available output buffer. Through the buffer instance obtained via [OH_VideoEncoder_GetOutputBuffer](#oh_videoencoder_getoutputbuffer), you can return the processed output buffer to the encoder by calling [OH_VideoEncoder_FreeOutputBuffer](#oh_videoencoder_freeoutputbuffer).<br> Note that the preceding operations are supported only in synchronous mode.|
| [OH_AVBuffer *OH_VideoEncoder_GetOutputBuffer(struct OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_getoutputbuffer) | - | Obtains the instance of the available output buffer.<br> Note that this function works only in synchronous mode.|

## Enum Description

### OH_VideoEncodeBitrateMode

```c
enum OH_VideoEncodeBitrateMode
```

**Description**

Enumerates the bit rate modes of a video encoder.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Deprecated from**: 14

**Substitute**: [OH_BitrateMode](capi-native-avcodec-base-h.md#oh_bitratemode)

| Value| Description|
| -- | -- |
| CBR = 0 | Constant bit rate.<br>**Substitute**: [BITRATE_MODE_CBR](capi-native-avcodec-base-h.md#oh_bitratemode)|
| VBR = 1 | Variable bit rate.<br>**Substitute**: [BITRATE_MODE_VBR](capi-native-avcodec-base-h.md#oh_bitratemode)|
| CQ = 2 | Constant quality.<br>**Substitute**: [BITRATE_MODE_CQ](capi-native-avcodec-base-h.md#oh_bitratemode)|


## Function Description

### OH_VideoEncoder_OnNeedInputParameter()

```c
typedef void (*OH_VideoEncoder_OnNeedInputParameter)(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter, void *userData)
```

**Description**

Defines the pointer to the function that is called when new input parameters are required for a frame with the specified index.  <br> This callback can be used only in surface mode after it is registered by calling OH_VideoEncoder_RegisterParameterCallback.<br> In buffer mode, OH_AVBuffer can directly carry the encoding parameter associated with each frame. Currently, it can manage parameters, including **QPMin**, **QPMax**, and reference frames for Long Term Reference (LTR), on a per-frame basis.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
|  uint32_t index | Index of the frame to encode.|
|  [OH_AVFormat](capi-core-oh-avformat.md) *parameter |  Pointer to the encoding parameter|
|  void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_VideoEncoder_CreateByMime()

```c
OH_AVCodec *OH_VideoEncoder_CreateByMime(const char *mime)
```

**Description**

Creates a video encoder instance based on a MIME type. This function is recommended.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| const char *mime | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIME_TYPE variables](capi-native-avcodec-base-h.md#variables).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) * | Pointer to the video encoder instance created.<br> If the encoder type is not supported or the memory is insufficient, NULL is returned.|

### OH_VideoEncoder_CreateByName()

```c
OH_AVCodec *OH_VideoEncoder_CreateByName(const char *name)
```

**Description**

Creates a video encoder instance based on an encoder name. To use this function, you must know the exact name of the encoder. The encoder name can be obtained through capability query.<br>For details, see [Obtaining Supported Codecs](../../media/avcodec/obtain-supported-codecs.md#creating-a-codec-with-the-specified-name).

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Pointer to a video encoder name.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) * | Pointer to the video encoder instance created.<br> If the input encoder name is not supported or the memory resources are insufficient, NULL is returned.|

### OH_VideoEncoder_CreatePrimaryWithPreproc()

```c
OH_AVErrCode OH_VideoEncoder_CreatePrimaryWithPreproc(const char *mime, OH_AVCodec **codec)
```

**Description**

Creates a primary video encoder instance that supports pre-processing. The encoder provides the following capabilities:
1. Pre-processing features (downsampling, cropping, and frame dropping).
2. Creation of a secondary encoder from this primary encoder to enable dual-output encoding with one input.

The encoder created via this API supports only the surface mode, and does not support the buffer mode or synchronous mode. After the encoder is successfully created, it must be destroyed via [OH_VideoEncoder_Destroy](#oh_videoencoder_destroy).

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| const char *mime | MIME type string, which cannot be **NULL**. It must be a supported type.|
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) **codec | Double pointer used to receive the created codec instance. It cannot be **NULL**. Once successfully created, the instance must be destroyed via [OH_VideoEncoder_Destroy](#oh_videoencoder_destroy).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The **mime** parameter is **NULL**, the **codec** parameter is **NULL**, or the MIME type is not supported.<br>**AV_ERR_NO_MEMORY**: Memory allocation fails.|

### OH_VideoEncoder_CreateSecondaryFromPrimary()

```c
OH_AVErrCode OH_VideoEncoder_CreateSecondaryFromPrimary(OH_AVCodec *primary, OH_AVCodec **codec)
```

**Description**

Creates a secondary video encoder instance from the primary encoder. The secondary encoder:
1. Shares the input source with the primary encoder.
2. Can be configured with independent encoding parameters.
3. Supports different pre-processing parameters.
4. Can be started and stopped independently (not dependent on the start/stop state of the primary encoder).
5. Has a lifecycle shorter than that of the primary encoder.
6. A primary encoder can have only one secondary encoder at a time.

A secondary encoder must be created after the primary encoder is successfully created. Once a secondary encoder is successfully created, it must be destroyed via [OH_VideoEncoder_Destroy](#oh_videoencoder_destroy). You are advised to destroy the secondary encoder before destroying the primary encoder.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *primary | Handle to the primary encoder, which must be created via [OH_VideoEncoder_CreatePrimaryWithPreproc](#oh_videoencoder_createprimarywithpreproc) and cannot be **NULL**.|
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) **codec | Double pointer used to receive the created secondary encoder instance. It cannot be **NULL**. Once successfully created, the instance must be destroyed via [OH_VideoEncoder_Destroy](#oh_videoencoder_destroy).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The **primary** parameter is **NULL**, the **codec** parameter is **NULL**, or the encoder corresponding to **primary** is not a valid primary encoder.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The primary encoder already has an associated secondary encoder.<br>**AV_ERR_NO_MEMORY**: Memory allocation fails.|

### OH_VideoEncoder_Destroy()

```c
OH_AVErrCode OH_VideoEncoder_Destroy(OH_AVCodec *codec)
```

**Description**

Clears the internal resources of a video encoder and destroys the encoder instance. You only need to call the function once.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.|

### OH_VideoEncoder_SetCallback()

```c
OH_AVErrCode OH_VideoEncoder_SetCallback(OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData)
```

**Description**

Sets the OH_AVCodecAsyncCallback callback so that your application can respond to events generated by a video encoder. This function must be called prior to **OH_VideoEncoder_Prepare**.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_VideoEncoder_RegisterCallback](#oh_videoencoder_registercallback)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| [OH_AVCodecAsyncCallback](capi-codecbase-oh-avcodecasynccallback.md) callback | Callback function.|
| void *userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.|

### OH_VideoEncoder_RegisterCallback()

```c
OH_AVErrCode OH_VideoEncoder_RegisterCallback(OH_AVCodec *codec, OH_AVCodecCallback callback, void *userData)
```

**Description**

Registers an OH_AVCodecCallback callback so that your application can respond to events generated by a video encoder. This function must be called prior to **OH_VideoEncoder_Prepare**.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| [OH_AVCodecCallback](capi-codecbase-oh-avcodeccallback.md) callback | Callback function.|
| void *userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.|

### OH_VideoEncoder_RegisterParameterCallback()

```c
OH_AVErrCode OH_VideoEncoder_RegisterParameterCallback(OH_AVCodec *codec, OH_VideoEncoder_OnNeedInputParameter onInputParameter, void *userData)
```

**Description**

Registers the OH_VideoEncoder_OnNeedInputParameter input parameter callback so that your application can respond to events generated by a video encoder. In surface encoding mode, this API must be called when frame-specific parameters need to be set.<br> and it must be called before [OH_VideoEncoder_Configure](#oh_videoencoder_configure).

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| [OH_VideoEncoder_OnNeedInputParameter](#oh_videoencoder_onneedinputparameter) onInputParameter | Pointer to the input parameter callback.|
| void *userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: The function is not called prior to **OH_VideoEncoder_Configure**.|

### OH_VideoEncoder_Configure()

```c
OH_AVErrCode OH_VideoEncoder_Configure(OH_AVCodec *codec, OH_AVFormat *format)
```

**Description**

Configures encoding parameters for a video encoder. Typically, you need to configure the description information about the video frames, such as the frame width, height, and pixel format. This function must be called prior to **OH_VideoEncoder_Prepare**.<br> This function is used to verify the validity of configuration parameters. Some invalid parameters are not forcibly verified. The default values are used or discarded. Some invalid parameters are forcibly verified. The rules are as follows:<br> The value ranges of the following parameters can be obtained through [capability query](../../media/avcodec/obtain-supported-codecs.md). **OH_MD_KEY_I_FRAME_INTERVAL** does not support capability query currently.<br> When attempting to set the **OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY** or **OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT** parameter on an unsupported platform, this API will not return an error; instead, it will follow its normal execution path.

Parameter verification rules are as follows:

| Key     | Value Within the Range| Value Out of Range| No Value Configured|
| ------- | -------- | -------- | ------ |
| OH_MD_KEY_WIDTH  | AV_ERR_OK | AV_ERR_INVALID_VAL | AV_ERR_INVALID_VAL |
| OH_MD_KEY_HEIGHT | AV_ERR_OK | AV_ERR_INVALID_VAL | AV_ERR_INVALID_VAL |
| OH_MD_KEY_PIXEL_FORMAT [OH_AVPixelFormat](capi-native-avformat-h.md#oh_avpixelformat)| AV_ERR_OK | AV_ERR_UNSUPPORT | AV_ERR_OK    |
| OH_MD_KEY_FRAME_RATE | AV_ERR_OK | AV_ERR_INVALID_VAL | AV_ERR_OK |
| OH_MD_KEY_PROFILE [OH_MD_KEY_PROFILE](capi-native-avcodec-base-h.md#variables)   | AV_ERR_OK | AV_ERR_INVALID_VAL | AV_ERR_OK | 
| OH_MD_KEY_I_FRAME_INTERVAL | AV_ERR_OK |  \\       | AV_ERR_OK | 

| OH_MD_KEY_<br>BITRATE | OH_MD_KEY_<br>QUALITY | OH_MD_KEY_<br>VIDEO_ENCODER_BITRATE_MODE | Return Value| Description    |
| :-------- | :---------| :---------- | ---- | ---------- |
| \\      | \\      | \\           |  AV_ERR_OK    | The default value of the encoder is used.|
| Out of range   | Out of range   | Unsupported mode      | AV_ERR_INVALID_VAL   | An error is reported for all abnormal values.  |
| Normal value    | Normal value    | \\           | AV_ERR_INVALID_VAL   | The bit rate conflicts with the quality.  |
| Normal value    | \\      | \\           | AV_ERR_OK     | The default bit rate control mode is enabled.|
| Normal value    | \\      | BITRATE_MODE_VBR and BITRATE_MODE_CBR     | AV_ERR_OK     |    -     |
| Normal value    | \\      | BITRATE_MODE_CQ           | AV_ERR_INVALID_VAL   | The bit rate conflicts with the CQ mode.     |
| \\      | Normal value    | \\           | AV_ERR_OK     | The CQ mode is enabled.|
| \\      | Normal value    | BITRATE_MODE_CQ           | AV_ERR_OK     |   -      |
| \\      | Normal value    | BITRATE_MODE_VBR and BITRATE_MODE_CBR     | AV_ERR_INVALID_VAL   | The quality conflicts with the VBR or CBR mode.|
| \\      | \\      | BITRATE_MODE_VBR and BITRATE_MODE_CBR     | AV_ERR_OK     | The default bit rate of the encoder is used.|
| \\      | \\      | BITRATE_MODE_CQ           | AV_ERR_OK    | The default quality is used. |

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| [OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance, which provides the description information about the video track to be encoded.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: 1. The value of **codec** is nullptr or does not point to an encoder instance. 2. The format is not supported.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: The function is not called prior to **OH_VideoEncoder_Prepare**.<br>   **AV_ERR_UNSUPPORT**: The pixel format is not supported.|

### OH_VideoEncoder_Prepare()

```c
OH_AVErrCode OH_VideoEncoder_Prepare(OH_AVCodec *codec)
```

**Description**

Prepares internal resources for a video encoder. This function must be called after **OH_VideoEncoder_Configure**.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal error occurs in the input encoder instance.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_Start()

```c
OH_AVErrCode OH_VideoEncoder_Start(OH_AVCodec *codec)
```

**Description**

Starts a video encoder. This function should be called after a successful call of [OH_VideoEncoder_Prepare](#oh_videoencoder_prepare). After being started, the encoder starts to report the registered event.<br> In surface mode, when there is a correct input on the surface, **OnNewOutputBuffer** is triggered each time a frame is encoded.<br> In buffer mode, the encoder immediately triggers the input callback. Each time the caller completes an input, the encoder performs encoding. **OnNewOutputBuffer** is triggered each time a frame is encoded.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_Stop()

```c
OH_AVErrCode OH_VideoEncoder_Stop(OH_AVCodec *codec)
```

**Description**

Stops a video encoder and releases the input and output buffers. After the video encoder is stopped, you can call **OH_VideoEncoder_Start** to enter the running state again.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_Flush()

```c
OH_AVErrCode OH_VideoEncoder_Flush(OH_AVCodec *codec)
```

**Description**

Clears the input and output data and parameters, for example, H.264 PPS/SPS, cached in a video encoder.<br> This function invalidates the indexes of all buffers previously reported through the asynchronous callback. Therefore, before calling this function, ensure that the buffers with the specified indexes are no longer required. This function cannot be called consecutively.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_Reset()

```c
OH_AVErrCode OH_VideoEncoder_Reset(OH_AVCodec *codec)
```

**Description**

Resets a video encoder. The encoder returns to the initial state. To continue encoding, you must call **OH_VideoEncoder_Configure** to configure the encoder again.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.|

### OH_VideoEncoder_GetOutputDescription()

```c
OH_AVFormat *OH_VideoEncoder_GetOutputDescription(OH_AVCodec *codec)
```

**Description**

Obtains the OH_AVFormat information about the output data of a video encoder.<br> You must call [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) to release the OH_AVFormat instance in the return value.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | Pointer to an OH_AVFormat instance.<br> If the value of **codec** is nullptr or does not point to an encoder instance, NULL is returned.|

### OH_VideoEncoder_SetParameter()

```c
OH_AVErrCode OH_VideoEncoder_SetParameter(OH_AVCodec *codec, OH_AVFormat *format)
```

**Description**

Sets the encoder parameter when a video encoder is running.<br> This function can be called only after the encoder is started. Incorrect parameter settings may cause encoding failure.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| [OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: 1. The value of **codec** is nullptr or does not point to an encoder instance. 2. The format is not supported.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_GetSurface()

```c
OH_AVErrCode OH_VideoEncoder_GetSurface(OH_AVCodec *codec, OHNativeWindow **window)
```

**Description**

Obtains the input surface from a video encoder. This function must be called after **OH_VideoEncoder_Configure** but before **OH_VideoEncoder_Prepare**.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md) **window | Double pointer to an OHNativeWindow instance. The application manages the lifecycle of the window and calls [OH_NativeWindow_DestroyNativeWindow](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_destroynativewindow) to release the window when the lifecycle ends.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.|

### OH_VideoEncoder_FreeOutputData()

```c
OH_AVErrCode OH_VideoEncoder_FreeOutputData(OH_AVCodec *codec, uint32_t index)
```

**Description**

Frees an output buffer of a video encoder.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_VideoEncoder_FreeOutputBuffer](#oh_videoencoder_freeoutputbuffer)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t index | Index of the output buffer. The value is provided by [OH_AVCodecOnNewOutputData](capi-native-avcodec-base-h.md#oh_avcodeconnewoutputdata).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_NotifyEndOfStream()

```c
OH_AVErrCode OH_VideoEncoder_NotifyEndOfStream(OH_AVCodec *codec)
```

**Description**

Notifies a video encoder that input streams end. You are advised to use this function for notification. This function is used only in surface mode. In buffer mode, OH_AVBuffer is used to carry the EOS information to notify the end of the input stream.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_PushInputData()

```c
OH_AVErrCode OH_VideoEncoder_PushInputData(OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr)
```

**Description**

Pushes the input buffer filled with data to a video encoder.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_VideoEncoder_PushInputBuffer](#oh_videoencoder_pushinputbuffer)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t index | Index of the input buffer. The value is provided by [OH_AVCodecOnNeedInputData](capi-native-avcodec-base-h.md#oh_avcodeconneedinputdata).|
| [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) attr | Description of the data contained in the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**:<br>1. The value of **codec** is nullptr or does not point to an encoder instance.<br>2. Invalid **index**. This error does not affect the subsequent encoding process.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_PushInputBuffer()

```c
OH_AVErrCode OH_VideoEncoder_PushInputBuffer(OH_AVCodec *codec, uint32_t index)
```

**Description**

Pushes the OH_AVBuffer corresponding to the index to a video encoder in buffer mode.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t index | Index of the input buffer. The value is provided by [OH_AVCodecOnNeedInputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconneedinputbuffer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**:<br>1. The value of **codec** is nullptr or does not point to an encoder instance.<br>2. Invalid **index**. This error does not affect the subsequent encoding process.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_PushInputParameter()

```c
OH_AVErrCode OH_VideoEncoder_PushInputParameter(OH_AVCodec *codec, uint32_t index)
```

**Description**

Pushes the parameter configured for a frame with the given index to a video encoder in surface mode.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t index | Index of the input parameter buffer. The index is obtained from [OH_VideoEncoder_OnNeedInputParameter](#oh_videoencoder_onneedinputparameter).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**:<br>1. The value of **codec** is nullptr or does not point to an encoder instance.<br>2. Invalid **index**. This error does not affect the subsequent encoding process.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_FreeOutputBuffer()

```c
OH_AVErrCode OH_VideoEncoder_FreeOutputBuffer(OH_AVCodec *codec, uint32_t index)
```

**Description**

Returns the processed OH_AVBuffer corresponding to the index to a video encoder. You need to call this function to release the output buffer in a timely manner. Otherwise, the encoding process is blocked.<br>For details, see step 13 in surface mode or step 11 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md).

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t index | Index of the output buffer. The value is provided by [OH_AVCodecOnNewOutputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconnewoutputbuffer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: An internal exception occurs in the encoder instance, for example, an unexpected nullptr.<br>         **AV_ERR_INVALID_VAL**:<br>1. The value of **codec** is nullptr or does not point to an encoder instance.<br>2. Invalid **index**. This error does not affect the subsequent encoding process.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.|

### OH_VideoEncoder_GetInputDescription()

```c
OH_AVFormat *OH_VideoEncoder_GetInputDescription(OH_AVCodec *codec)
```

**Description**

Obtains the description of the image received by a video encoder. This function must be called after [OH_VideoEncoder_Configure](#oh_videoencoder_configure) is called.<br> You must call [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) to release the OH_AVFormat instance in the return value.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | Pointer to an OH_AVFormat instance.<br> If the value of **codec** is nullptr or does not point to an encoder instance, NULL is returned.|

### OH_VideoEncoder_IsValid()

```c
OH_AVErrCode OH_VideoEncoder_IsValid(OH_AVCodec *codec, bool *isValid)
```

**Description**

Checks whether the encoder service is valid when an encoder instance exists.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| bool *isValid | Pointer of the Boolean type. The value indicates the validity of the encoder service only when the function returns **AV_ERR_OK**. The value **true** means that the encoder service is valid, and **false** means the opposite. It is recommended that you initialize **isValid** to **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.|

### OH_VideoEncoder_QueryInputBuffer()

```c
OH_AVErrCode OH_VideoEncoder_QueryInputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)
```

**Description**

Obtains the index of the next available input buffer.<br> After calling this function, you must call [OH_VideoEncoder_GetInputBuffer](#oh_videoencoder_getinputbuffer) to obtain the buffer instance and call [OH_VideoEncoder_PushInputBuffer](#oh_videoencoder_pushinputbuffer) to pass the buffer instance to the encoder.<br> Note that the preceding operations are supported only in synchronous mode.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t *index | Pointer to the index of the input buffer.|
| int64_t timeoutUs | Timeout duration, in microseconds. A negative value means to wait infinitely. The value **0** means to return immediately. A positive value means to wait for the specified time before exiting.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: The encoder instance has been destroyed.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: This function is called in asynchronous mode.<br>         **AV_ERR_TRY_AGAIN_LATER**: The query fails. Try again after a short interval.|

### OH_VideoEncoder_GetInputBuffer()

```c
OH_AVBuffer *OH_VideoEncoder_GetInputBuffer(struct OH_AVCodec *codec, uint32_t index)
```

**Description**

Obtains the instance of the available input buffer.<br> Note that this function works only in synchronous mode.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t index | Index of the input buffer. It can be obtained by calling [OH_VideoEncoder_QueryInputBuffer](#oh_videoencoder_queryinputbuffer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) * | Pointer to the OH_AVBuffer instance created. If the operation fails, NULL is returned.|

### OH_VideoEncoder_QueryOutputBuffer()

```c
OH_AVErrCode OH_VideoEncoder_QueryOutputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)
```

**Description**

Obtains the index of the next available output buffer. Through the buffer instance obtained via [OH_VideoEncoder_GetOutputBuffer](#oh_videoencoder_getoutputbuffer), you can return the processed output buffer to the encoder by calling [OH_VideoEncoder_FreeOutputBuffer](#oh_videoencoder_freeoutputbuffer).<br> Note that the preceding operations are supported only in synchronous mode.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t *index | Pointer to the index of the output buffer.|
| int64_t timeoutUs | Timeout duration, in microseconds. A negative value means to wait infinitely. The value **0** means to return immediately. A positive value means to wait for the specified time before exiting.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_NO_MEMORY**: The encoder instance has been destroyed.<br>         **AV_ERR_INVALID_VAL**: The value of **codec** is nullptr or does not point to an encoder instance.<br>         **AV_ERR_UNKNOWN**: An unknown error occurs.<br>         **AV_ERR_INVALID_STATE**: This API cannot be called in the current encoder state.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: This function is called in asynchronous mode.<br>         **AV_ERR_STREAM_CHANGED**: The stream format has changed. You can call [OH_VideoEncoder_GetOutputDescription](#oh_videoencoder_getoutputdescription) to obtain the new stream information.<br>         **AV_ERR_TRY_AGAIN_LATER**: The query fails. Try again after a short interval.|

### OH_VideoEncoder_GetOutputBuffer()

```c
OH_AVBuffer *OH_VideoEncoder_GetOutputBuffer(struct OH_AVCodec *codec, uint32_t index)
```

**Description**

Obtains the instance of the available output buffer.<br> Note that this function works only in synchronous mode.

**System capability**: SystemCapability.Multimedia.Media.VideoEncoder

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | Pointer to a video encoder instance.|
| uint32_t index | Index of the output buffer. It can be obtained by calling [OH_VideoEncoder_QueryOutputBuffer](#oh_videoencoder_queryoutputbuffer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) * | If the operation is successful, a pointer to the available output buffer (OH_AVBuffer instance) is returned. Otherwise, NULL is returned.|
