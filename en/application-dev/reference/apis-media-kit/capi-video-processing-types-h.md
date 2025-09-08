# video_processing_types.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the video processing types.

**File to include**: <multimedia/video_processing_engine/video_processing_types.h>

**Library**: libvideo_processing.so

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Since**: 12

**Related module**: [VideoProcessing](capi-videoprocessing.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [VideoProcessing_ColorSpaceInfo](capi-videoprocessing-videoprocessing-colorspaceinfo.md) | VideoProcessing_ColorSpaceInfo | Describes the color space information of video processing.|
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md) | OH_VideoProcessing | Describes an object for video processing.<br>You should define a null pointer for **OH_VideoProcessing** and use [OH_VideoProcessing_Create](capi-video-processing-h.md#oh_videoprocessing_create) to create a video processing instance. Before creation, ensure that the pointer is null. You can create different video processing instances with different processing types.|
| [NativeWindow](capi-videoprocessing-nativewindow.md) | OHNativeWindow | Describes the NativeWindow object.|
| [OH_AVFormat](capi-videoprocessing-oh-avformat.md) | OH_AVFormat | Describes the OH_AVFormat object.|
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md) | VideoProcessing_Callback | Describes a callback object for handling video processing events.<br>You should define a null pointer for **VideoProcessing_Callback** and use [OH_VideoProcessingCallback_Create](capi-video-processing-h.md#oh_videoprocessingcallback_create) to create a callback object. Before creation, ensure that the pointer is null. After creating the callback object, call [OH_VideoProcessing_RegisterCallback](capi-video-processing-h.md#oh_videoprocessing_registercallback) to register it with the video processing instance.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel) | VideoDetailEnhancer_QualityLevel | Enumerates the quality levels for detail enhancement.|
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) | VideoProcessing_ErrorCode | Enumerates the video processing error codes.|
| [VideoProcessing_State](#videoprocessing_state) | VideoProcessing_State | Enumerates the video processing states.<br>The video processing state is reported through the callback function [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate).|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_VideoProcessingCallback_OnError)(OH_VideoProcessing* videoProcessor,VideoProcessing_ErrorCode error, void* userData)](#oh_videoprocessingcallback_onerror) | OH_VideoProcessingCallback_OnError | Called when an error occurs during video processing.|
| [typedef void (\*OH_VideoProcessingCallback_OnState)(OH_VideoProcessing* videoProcessor, VideoProcessing_State state, void* userData)](#oh_videoprocessingcallback_onstate) | OH_VideoProcessingCallback_OnState | Called when the video processing state changes.<br>After [OH_VideoProcessing_Start](capi-video-processing-h.md#oh_videoprocessing_start) is called, the video processing state changes to [VideoProcessing_State](#videoprocessing_state).VIDEO_PROCESSING_STATE_RUNNING. After [OH_VideoProcessing_Stop](capi-video-processing-h.md#oh_videoprocessing_stop) is called, the video processing state changes to [VideoProcessing_State](#videoprocessing_state).VIDEO_PROCESSING_STATE_STOPPED after all buffers are processed.|
| [typedef void (\*OH_VideoProcessingCallback_OnNewOutputBuffer)(OH_VideoProcessing* videoProcessor, uint32_t index, void* userData)](#oh_videoprocessingcallback_onnewoutputbuffer) | OH_VideoProcessingCallback_OnNewOutputBuffer | Called when the output buffer is filled with data.<br>After data is filled in each new output buffer, the index of the buffer is reported. Call [OH_VideoProcessing_RenderOutputBuffer](capi-video-processing-h.md#oh_videoprocessing_renderoutputbuffer) to process rendering based on the index and output the buffer. If this callback function is not registered, the data filled in the output buffer is not reported. Instead, the data is directly processed, rendered, and output.|

### Variables

| Name| Description|
| -- | -- |
| const int32_t VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION | Instance created for color space conversion during video processing.<br>Call [OH_VideoProcessing_Create](capi-video-processing-h.md#oh_videoprocessing_create) to create such an instance for color space conversion. If color space conversion is not supported, [VideoProcessing_ErrorCode](#videoprocessing_errorcode).VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING is returned.<br>**Since**: 12|
| const int32_t VIDEO_PROCESSING_TYPE_METADATA_GENERATION | Instance created for metadata generation during video processing.<br>Call [OH_VideoProcessing_Create](capi-video-processing-h.md#oh_videoprocessing_create) to create such an instance for metadata generation. If metadata generation is not supported, [VideoProcessing_ErrorCode](#videoprocessing_errorcode).VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING is returned.<br>**Since**: 12|
| const int32_t VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER | Instance for detail enhancement during video processing.<br>Call [OH_VideoProcessing_Create](capi-video-processing-h.md#oh_videoprocessing_create) to create such an instance for detail enhancement. If detail enhancement is not supported, [VideoProcessing_ErrorCode](#videoprocessing_errorcode).VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING is returned.<br>**Since**: 12|
| const char* VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL | Pointer to the quality level of video detail enhancement. For details, see [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel).<br>You can call [OH_VideoProcessing_SetParameter](capi-video-processing-h.md#oh_videoprocessing_setparameter) to set the quality level,<br>and call [OH_VideoProcessing_GetParameter](capi-video-processing-h.md#oh_videoprocessing_getparameter) to obtain the quality level.<br>**Since**: 12|

## Enum Description

### VideoDetailEnhancer_QualityLevel

```
enum VideoDetailEnhancer_QualityLevel
```

**Description**

Enumerates the quality levels for detail enhancement. For details about the enumerated values, see **VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL**. For details about how to set the quality level, see the development guide.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_NONE | No detail enhancement.|
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_LOW | Low-quality detail enhancement, which features fast speed. This is the default value.|
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM | Medium-quality detail enhancement, which features moderate speed.|
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH | High-quality detail enhancement, which features slow speed.|

**See also**

[OH_VideoProcessing_SetParameter](capi-video-processing-h.md#oh_videoprocessing_setparameter)

[OH_VideoProcessing_GetParameter](capi-video-processing-h.md#oh_videoprocessing_getparameter)

### VideoProcessing_ErrorCode

```
enum VideoProcessing_ErrorCode
```

**Description**

Enumerates the video processing error codes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| VIDEO_PROCESSING_SUCCESS | The processing is successful.|
| VIDEO_PROCESSING_ERROR_INVALID_PARAMETER = 401 | An input parameter is invalid. This error code is returned in the following cases:<br>1. The input or output video buffer is either invalid or empty.<br>2. The provided parameter is invalid or missing.<br>3. The requested processing type is invalid.|
| VIDEO_PROCESSING_ERROR_UNKNOWN = 29210001 | An unknown error occurs. For example, the GPU computing or memcpy fails.|
| VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED | The global video processing environment, for example, the GPU environment, fails to be initialized.|
| VIDEO_PROCESSING_ERROR_CREATE_FAILED | Creating the video processing instance fails. For example, the total number of instances exceeds the upper limit.|
| VIDEO_PROCESSING_ERROR_PROCESS_FAILED | The processing fails. For example, the processing times out.|
| VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING | The processing type is not supported. You can call **OH_VideoProcessing_Is*XXX*Supported** to check whether a specific processing type is supported.|
| VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED | The operation is not allowed. For example, the function is called in an incorrect running state.|
| VIDEO_PROCESSING_ERROR_NO_MEMORY | Insufficient memory.|
| VIDEO_PROCESSING_ERROR_INVALID_INSTANCE | The video processing instance is invalid, for example, a null instance.|
| VIDEO_PROCESSING_ERROR_INVALID_VALUE | The input value is invalid. This error code is returned in the following cases:<br>1. The width and height of the video buffer are inappropriate or the color space is incorrect.<br>2. The parameter contains an invalid value. For example, the quality level of detail enhancement is incorrect.|

### VideoProcessing_State

```
enum VideoProcessing_State
```

**Description**

Enumerates the video processing states.

The video processing state is reported through the callback function [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate).

**Since**: 12

| Enum Item| Description|
| -- | -- |
| VIDEO_PROCESSING_STATE_RUNNING | Video processing is in progress.|
| VIDEO_PROCESSING_STATE_STOPPED | Video processing stopped.|


## Function Description

### OH_VideoProcessingCallback_OnError()

```
typedef void (*OH_VideoProcessingCallback_OnError)(OH_VideoProcessing* videoProcessor,VideoProcessing_ErrorCode error, void* userData)
```

**Description**

Called when an error occurs during video processing.

The following error codes are defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode):

**VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: unsupported processing. For example, conversion between the color space types for input and output is not supported.

**VIDEO_PROCESSING_ERROR_INVALID_VALUE**: invalid video property. For example, the video color space is invalid.

**VIDEO_PROCESSING_ERROR_NO_MEMORY**: out of memory.

**VIDEO_PROCESSING_ERROR_PROCESS_FAILED**: An error occurs during the processing.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) error | Error code reported.|
|  void* userData | Pointer to user-defined data.|

### OH_VideoProcessingCallback_OnState()

```
typedef void (*OH_VideoProcessingCallback_OnState)(OH_VideoProcessing* videoProcessor, VideoProcessing_State state,void* userData)
```

**Description**

Called when the video processing state changes.

After [OH_VideoProcessing_Start](capi-video-processing-h.md#oh_videoprocessing_start) is called, the video processing state changes to [VideoProcessing_State](#videoprocessing_state).VIDEO_PROCESSING_STATE_RUNNING. After [OH_VideoProcessing_Stop](capi-video-processing-h.md#oh_videoprocessing_stop) is called, the video processing state changes to [VideoProcessing_State](#videoprocessing_state).VIDEO_PROCESSING_STATE_STOPPED after all buffers are processed.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
|  [VideoProcessing_State](#videoprocessing_state) state | Video processing state.|
| void* userData | Pointer to user-defined data.|

### OH_VideoProcessingCallback_OnNewOutputBuffer()

```
typedef void (*OH_VideoProcessingCallback_OnNewOutputBuffer)(OH_VideoProcessing* videoProcessor, uint32_t index,void* userData)
```

**Description**

Called when the output buffer is filled with data.

After data is filled in each new output buffer, the index of the buffer is reported. Call [OH_VideoProcessing_RenderOutputBuffer](capi-video-processing-h.md#oh_videoprocessing_renderoutputbuffer) to process rendering based on the index and output the buffer. If this callback function is not registered, the data filled in the output buffer is not reported. Instead, the data is directly processed, rendered, and output.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
|  uint32_t index | Index of the output buffer.|
| void* userData | Pointer to user-defined data.|
