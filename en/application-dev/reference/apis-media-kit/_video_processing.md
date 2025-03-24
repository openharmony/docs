# VideoProcessing


## Overview

The VideoProcessing module provides the APIs for video processing. It provides video processing capabilities, including color space conversion, metadata generation, and video scaling.

<!--RP1--><!--RP1End-->

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [video_processing.h](video__processing_8h.md) | Declares the video processing functions.| 
| [video_processing_types.h](video__processing__types_8h.md) | Declares the video processing types.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) | Describes the color space information of video processing.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_VideoProcessing](#oh_videoprocessing-1) [OH_VideoProcessing](#oh_videoprocessing) | Defines a struct for the video processing object.| 
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | Defines a struct for the NativeWindow object.| 
| typedef struct [OH_AVFormat](#oh_avformat-1) [OH_AVFormat](#oh_avformat) | Defines a struct for the OH_AVFormat object.| 
| typedef struct [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) [VideoProcessing_ColorSpaceInfo](#videoprocessing_colorspaceinfo) | Defines a struct for the color space information of video processing.| 
| typedef enum [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel-1) [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel) | Defines an enum for the quality levels for detail enhancement.| 
| typedef enum [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) [VideoProcessing_ErrorCode](#videoprocessing_errorcode) | Defines an enum for the video processing error codes.| 
| typedef enum [VideoProcessing_State](#videoprocessing_state-1) [VideoProcessing_State](#videoprocessing_state) | Defines an enum for the video processing states.| 
| typedef struct [VideoProcessing_Callback](#videoprocessing_callback) [VideoProcessing_Callback](#videoprocessing_callback) | Defines a struct for the video processing callback object.| 
| typedef void(\* [OH_VideoProcessingCallback_OnError](#oh_videoprocessingcallback_onerror)) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, [VideoProcessing_ErrorCode](#videoprocessing_errorcode) error, void \*userData) | Defines a pointer to the callback function for reporting an error during video processing.| 
| typedef void(\* [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, [VideoProcessing_State](#videoprocessing_state) state, void \*userData) | Defines a pointer to the callback function for reporting the video processing state.| 
| typedef void(\* [OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer)) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, uint32_t index, void \*userData) | Defines a pointer to the callback function for reporting the data filled in the output buffer.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel-1) {<br>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_NONE,<br>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_LOW,<br>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM,<br>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH } | Enumerates the quality levels for detail enhancement.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) {<br>VIDEO_PROCESSING_SUCCESS,<br>VIDEO_PROCESSING_ERROR_INVALID_PARAMETER = 401,<br>VIDEO_PROCESSING_ERROR_UNKNOWN = 29210001,<br>VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED,<br>VIDEO_PROCESSING_ERROR_CREATE_FAILED,<br>VIDEO_PROCESSING_ERROR_PROCESS_FAILED,<br>VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,<br>VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,<br>VIDEO_PROCESSING_ERROR_NO_MEMORY,<br>VIDEO_PROCESSING_ERROR_INVALID_INSTANCE,<br>VIDEO_PROCESSING_ERROR_INVALID_VALUE<br>} | Enumerates the video processing error codes.| 
| [VideoProcessing_State](#videoprocessing_state-1) {<br>VIDEO_PROCESSING_STATE_RUNNING,<br>VIDEO_PROCESSING_STATE_STOPPED } | Enumerates the video processing states.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment) (void) | Initializes the global video processing environment.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment) (void) | Releases the global video processing environment.| 
| bool [OH_VideoProcessing_IsColorSpaceConversionSupported](#oh_videoprocessing_iscolorspaceconversionsupported) (const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*sourceVideoInfo, const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*destinationVideoInfo) | Checks whether color space conversion is supported during video processing.| 
| bool [OH_VideoProcessing_IsMetadataGenerationSupported](#oh_videoprocessing_ismetadatagenerationsupported) (const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*sourceVideoInfo) | Checks whether metadata generation is supported during video processing.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_Create](#oh_videoprocessing_create) ([OH_VideoProcessing](#oh_videoprocessing) \*\*videoProcessor, int type) | Creates a video processing instance.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_Destroy](#oh_videoprocessing_destroy) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor) | Destroys a video processing instance.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_RegisterCallback](#oh_videoprocessing_registercallback) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, const [VideoProcessing_Callback](#videoprocessing_callback) \*callback, void \*userData) | Registers a callback for video processing.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_SetSurface](#oh_videoprocessing_setsurface) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, const [OHNativeWindow](#ohnativewindow) \*window) | Sets an output surface for video processing.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_GetSurface](#oh_videoprocessing_getsurface) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, [OHNativeWindow](#ohnativewindow) \*\*window) | Obtains a surface for video processing.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_SetParameter](#oh_videoprocessing_setparameter) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, const [OH_AVFormat](#oh_avformat) \*parameter) | Sets video processing parameters.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_GetParameter](#oh_videoprocessing_getparameter) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, [OH_AVFormat](#oh_avformat) \*parameter) | Obtains video processing parameters.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_Start](#oh_videoprocessing_start) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor) | Starts video processing.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_Stop](#oh_videoprocessing_stop) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor) | Stops video processing.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_RenderOutputBuffer](#oh_videoprocessing_renderoutputbuffer) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, uint32_t index) | Renders and processes the buffer, and then outputs it.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_Create](#oh_videoprocessingcallback_create) ([VideoProcessing_Callback](#videoprocessing_callback) \*\*callback) | Creates a video processing callback object.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_Destroy](#oh_videoprocessingcallback_destroy) ([VideoProcessing_Callback](#videoprocessing_callback) \*callback) | Destroys a video processing callback object.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnError](#oh_videoprocessingcallback_bindonerror) ([VideoProcessing_Callback](#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnError](#oh_videoprocessingcallback_onerror) onError) | Binds the callback function [OH_VideoProcessingCallback_OnError](#oh_videoprocessingcallback_onerror) to a video processing callback object.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnState](#oh_videoprocessingcallback_bindonstate) ([VideoProcessing_Callback](#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate) onState) | Binds the callback function [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate) to a video processing callback object.| 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnNewOutputBuffer](#oh_videoprocessingcallback_bindonnewoutputbuffer) ([VideoProcessing_Callback](#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer) onNewOutputBuffer) | Binds the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer) to a video processing callback object.| 


### Variables

| Name| Description| 
| -------- | -------- |
| const int32_t [VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](#video_processing_type_color_space_conversion) | Instance created for color space conversion during video processing.| 
| const int32_t [VIDEO_PROCESSING_TYPE_METADATA_GENERATION](#video_processing_type_metadata_generation) | Instance created for metadata generation during video processing.| 
| const int32_t [VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER](#video_processing_type_detail_enhancer) | Instance for detail enhancement during video processing.| 
| const char \* [VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#video_detail_enhancer_parameter_key_quality_level) | Pointer to the quality level of video detail enhancement.| 


## Type Description


### OH_AVFormat

```
typedef struct OH_AVFormatOH_AVFormat
```

**Description**

Defines a struct for the OH_AVFormat object.

**Since**: 12


### OH_VideoProcessing

```
typedef struct OH_VideoProcessingOH_VideoProcessing
```

**Description**

Defines a struct for the video processing object.

Define a null pointer to **OH_VideoProcessing**. Before [OH_VideoProcessing_Create](#oh_videoprocessing_create) is called to create a video processing instance, the pointer must be null. You can create different video processing instances with different processing types.

**Since**: 12


### OH_VideoProcessingCallback_OnError

```
typedef void(* OH_VideoProcessingCallback_OnError) (OH_VideoProcessing *videoProcessor, VideoProcessing_ErrorCode error, void *userData)
```

**Description**

Defines a pointer to the callback function for reporting an error during video processing.

The following error codes are defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: unsupported processing. For example, conversion between the color space types for input and output is not supported.

- **VIDEO_PROCESSING_ERROR_INVALID_VALUE**: invalid video attribute. For example, the video color space is invalid.

- **VIDEO_PROCESSING_ERROR_NO_MEMORY**: out of memory.

- **VIDEO_PROCESSING_ERROR_PROCESS_FAILED**: An error occurs during the processing.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to the video processing instance.| 
| error | Error code reported.| 
| userData | Pointer to user-defined data.| 


### OH_VideoProcessingCallback_OnNewOutputBuffer

```
typedef void(* OH_VideoProcessingCallback_OnNewOutputBuffer) (OH_VideoProcessing *videoProcessor, uint32_t index, void *userData)
```

**Description**

Defines a pointer to the callback function for reporting the data filled in the output buffer.

After data is filled in each new output buffer, the index of the buffer is reported. Call [OH_VideoProcessing_RenderOutputBuffer](#oh_videoprocessing_renderoutputbuffer) to process rendering based on the index and output the buffer. If this callback function is not registered, the data filled in the output buffer is not reported. Instead, the data is directly processed, rendered, and output.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to the video processing instance.| 
| index | Index of the output buffer.| 
| userData | Pointer to user-defined data.| 


### OH_VideoProcessingCallback_OnState

```
typedef void(* OH_VideoProcessingCallback_OnState) (OH_VideoProcessing *videoProcessor, VideoProcessing_State state, void *userData)
```

**Description**

Defines a pointer to the callback function for reporting the video processing state.

After [OH_VideoProcessing_Start](#oh_videoprocessing_start) is called, the video processing state changes to VIDEO_PROCESSING_STATE_RUNNING. After [OH_VideoProcessing_Stop](#oh_videoprocessing_stop) is called and all buffers finishes processing, the state changes to VIDEO_PROCESSING_STATE_STOPPED. For details, see [VideoProcessing_State](#videoprocessing_state).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to the video processing instance.| 
| state | Video processing state. For details, see [VideoProcessing_State](#videoprocessing_state).| 
| userData | Pointer to user-defined data.| 


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```

**Description**

Defines a struct for the NativeWindow object.

**Since**: 12


### VideoDetailEnhancer_QualityLevel

```
typedef enum VideoDetailEnhancer_QualityLevelVideoDetailEnhancer_QualityLevel
```

**Description**

Defines an enum for the quality levels for detail enhancement.

For details about the enumerated values, see [VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#video_detail_enhancer_parameter_key_quality_level). For details about how to set the quality level, see the development guide.

**See also**: [OH_VideoProcessing_SetParameter](#oh_videoprocessing_setparameter) and [OH_VideoProcessing_GetParameter](#oh_videoprocessing_getparameter)

**Since**: 12


### VideoProcessing_Callback

```
typedef struct VideoProcessing_CallbackVideoProcessing_Callback
```

**Description**

Defines a struct for the video processing callback object.

Define a null pointer to **VideoProcessing_Callback**. Before [OH_VideoProcessingCallback_Create](#oh_videoprocessingcallback_create) is called to create a video processing callback object, the pointer must be null. The callback object is registered by calling [OH_VideoProcessing_RegisterCallback](#oh_videoprocessing_registercallback).

**Since**: 12


### VideoProcessing_ColorSpaceInfo

```
typedef struct VideoProcessing_ColorSpaceInfoVideoProcessing_ColorSpaceInfo
```

**Description**

Defines a struct for the color space information of video processing.

**See also**: [OH_VideoProcessing_IsColorSpaceConversionSupported](#oh_videoprocessing_iscolorspaceconversionsupported)

**Since**: 12


### VideoProcessing_ErrorCode

```
typedef enum VideoProcessing_ErrorCodeVideoProcessing_ErrorCode
```

**Description**

Defines an enum for the video processing error codes.

**Since**: 12


### VideoProcessing_State

```
typedef enum VideoProcessing_StateVideoProcessing_State
```

**Description**

Defines an enum for the video processing states.

The video processing state is reported through the callback function [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate).

**Since**: 12


## Enum Description


### VideoDetailEnhancer_QualityLevel

```
enum VideoDetailEnhancer_QualityLevel
```

**Description**

Enumerates the quality levels for detail enhancement.

For details about the enumerated values, see [VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#video_detail_enhancer_parameter_key_quality_level). For details about how to set the quality level, see the development guide.

**See also**: [OH_VideoProcessing_SetParameter](#oh_videoprocessing_setparameter) and [OH_VideoProcessing_GetParameter](#oh_videoprocessing_getparameter)

**Since**: 12

| Value| Description| 
| -------- | -------- |
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_NONE | No detail enhancement.| 
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_LOW | Low-quality detail enhancement, which features fast speed. This is the default value.| 
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM | Medium-quality detail enhancement, which features moderate speed.| 
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH | High-quality detail enhancement, which features slow speed.| 


### VideoProcessing_ErrorCode

```
enum VideoProcessing_ErrorCode
```

**Description**

Enumerates the video processing error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| VIDEO_PROCESSING_SUCCESS | The processing is successful.| 
| VIDEO_PROCESSING_ERROR_INVALID_PARAMETER | An input parameter is invalid. This error code is returned in the following cases:<br>1 - The input or output video buffer is either invalid or empty.<br>2 - The provided parameter is invalid or missing.<br>3 - The requested processing type is invalid.| 
| VIDEO_PROCESSING_ERROR_UNKNOWN | An unknown error occurs. For example, the GPU computing or memcpy fails.| 
| VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED | The global video processing environment, for example, the GPU environment, fails to be initialized.| 
| VIDEO_PROCESSING_ERROR_CREATE_FAILED | Creating the video processing instance fails. For example, the total number of instances exceeds the upper limit.| 
| VIDEO_PROCESSING_ERROR_PROCESS_FAILED | The processing fails. For example, the processing times out.| 
| VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING | The processing type is not supported. You can call OH_VideoProcessing_Is*XXX*Supported to check whether a specific processing type is supported.| 
| VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED | The operation is not allowed. For example, the function is called in an incorrect running state.| 
| VIDEO_PROCESSING_ERROR_NO_MEMORY | Insufficient memory.| 
| VIDEO_PROCESSING_ERROR_INVALID_INSTANCE | The video processing instance is invalid, for example, a null instance.| 
| VIDEO_PROCESSING_ERROR_INVALID_VALUE | The input value is invalid. This error code is returned in the following cases:<br>1 - The width and height of the video buffer are inappropriate or the color space is incorrect.<br>2 - The parameter contains an invalid value. For example, the quality level of detail enhancement is incorrect.| 


### VideoProcessing_State

```
enum VideoProcessing_State
```

**Description**

Enumerates the video processing states.

The video processing state is reported through the callback function [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate).

**Since**: 12

| Value| Description| 
| -------- | -------- |
| VIDEO_PROCESSING_STATE_RUNNING | Video processing is in progress.| 
| VIDEO_PROCESSING_STATE_STOPPED | Video processing stopped.| 


## Function Description


### OH_VideoProcessing_Create()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Create (OH_VideoProcessing ** videoProcessor, int type )
```

**Description**

Creates a video processing instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor |  Double pointer to the video processing instance created. Before any input, **\*videoProcessor** must be a null pointer.| 
| type | Video processing type. The processing type of an instance cannot be changed.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the video processing instance is created successfully.

- **VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** if the video processing type is not supported.
  For example, if metadata generation is not supported, **VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** is returned.

- **VIDEO_PROCESSING_ERROR_CREATE_FAILED** if the video processing instance fails to be created.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or the pointer to the instance is not null.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if the video processing type is invalid.


### OH_VideoProcessing_DeinitializeEnvironment()

```
VideoProcessing_ErrorCode OH_VideoProcessing_DeinitializeEnvironment (void )
```

**Description**

Releases the global video processing environment.

Before calling this API, you must call [OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment) to initialize the environment. Generally, this function is called when the main process is about to exit. Do not call this function when a video processing instance is running.

**Since**: 12

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the processing is successful.

- **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED** if a video processing instance is not destroyed or [OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment) is not called to initialize the environment.


### OH_VideoProcessing_Destroy()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Destroy (OH_VideoProcessing * videoProcessor)
```

**Description**

Destroys a video processing instance.

Before destroying the instance, call [OH_VideoProcessing_Stop](#oh_videoprocessing_stop) to stop it.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to the video processing instance. You are advised to set the pointer to a null pointer after the instance is destroyed.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the instance is destroyed.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED** if the instance is still running.


### OH_VideoProcessing_GetParameter()

```
VideoProcessing_ErrorCode OH_VideoProcessing_GetParameter (OH_VideoProcessing * videoProcessor, OH_AVFormat * parameter )
```

**Description**

Obtains video processing parameters.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to a video processing instance.| 
| parameter | Pointer to a video processing parameter instance.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the parameters are obtained.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if the parameter is empty.


### OH_VideoProcessing_GetSurface()

```
VideoProcessing_ErrorCode OH_VideoProcessing_GetSurface (OH_VideoProcessing * videoProcessor, OHNativeWindow ** window )
```

**Description**

Obtains a surface for video processing.

An input surface must be created before video processing starts, and it must be destroyed by calling [OH_NativeWindow_DestroyNativeWindow](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_destroynativewindow) when it is no longer needed.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to a video processing instance.| 
| window | Double pointer to the input surface. For example, the input surface pointer can point to an output surface of the video decoder.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the processing is successful.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if the window is a null pointer or the pointer to the window is not null.

- **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED** if the surface fails to be created, an input surface has been created, or the video processing instance is running.


### OH_VideoProcessing_InitializeEnvironment()

```
VideoProcessing_ErrorCode OH_VideoProcessing_InitializeEnvironment (void )
```

**Description**

Initializes the global video processing environment.

This function is optional. It is called only once when the main process is started to initialize the global video processing environment. This reduces the duration for running [OH_VideoProcessing_Create](#oh_videoprocessing_create). The global video processing environment must be released by calling [OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment). For details about how and when to release the environment, see [OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment).

**Since**: 12

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the initialization is successful.
- **VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED** if the initialization fails.

If the operation fails, check whether the GPU works properly.


### OH_VideoProcessing_IsColorSpaceConversionSupported()

```
bool OH_VideoProcessing_IsColorSpaceConversionSupported (const VideoProcessing_ColorSpaceInfo * sourceVideoInfo, const VideoProcessing_ColorSpaceInfo * destinationVideoInfo )
```

**Description**

Checks whether color space conversion is supported during video processing.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| sourceVideoInfo | Pointer to the color space information of the input video.| 
| destinationVideoInfo | Pointer to the color space information of the output video.| 

**Returns**

Returns **true** if color space conversion is supported; returns **false** otherwise.


### OH_VideoProcessing_IsMetadataGenerationSupported()

```
bool OH_VideoProcessing_IsMetadataGenerationSupported (const VideoProcessing_ColorSpaceInfo * sourceVideoInfo)
```

**Description**

Checks whether metadata generation is supported during video processing.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| sourceVideoInfo | Pointer to the color space information of the input video.| 

**Returns**

Returns **true** if metadata generation is supported; returns **false** otherwise.


### OH_VideoProcessing_RegisterCallback()

```
VideoProcessing_ErrorCode OH_VideoProcessing_RegisterCallback (OH_VideoProcessing * videoProcessor, const VideoProcessing_Callback * callback, void * userData )
```

**Description**

Registers a callback for video processing.

The callback function should be registered before video processing starts. During video processing, it cannot be registered.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to a video processing instance.| 
| callback | Pointer to the callback function.| 
| userData | Pointer to user-defined data.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the callback function is registered.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if the callback function pointer is null.

- **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED** if the instance is still running.


### OH_VideoProcessing_RenderOutputBuffer()

```
VideoProcessing_ErrorCode OH_VideoProcessing_RenderOutputBuffer (OH_VideoProcessing * videoProcessor, uint32_t index )
```

**Description**

Renders and processes the buffer, and then outputs it.

If the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer) is set, the buffer index is returned through the callback function after the output buffer is ready.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to a video processing instance.| 
| index | Index of the output buffer.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the processing is successful.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if the index is invalid.

- **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED** if the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer) is not set or the instance is stopped.


### OH_VideoProcessing_SetParameter()

```
VideoProcessing_ErrorCode OH_VideoProcessing_SetParameter (OH_VideoProcessing * videoProcessor, const OH_AVFormat * parameter )
```

**Description**

Sets video processing parameters.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to a video processing instance.| 
| parameter | Pointer to a video processing parameter instance.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the parameters are successfully set.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if the parameter is empty.

- **VIDEO_PROCESSING_ERROR_INVALID_VALUE** if some attributes of a parameter are invalid, for example, unsupported parameter value.

- **VIDEO_PROCESSING_ERROR_NO_MEMORY** if memory allocation fails.


### OH_VideoProcessing_SetSurface()

```
VideoProcessing_ErrorCode OH_VideoProcessing_SetSurface (OH_VideoProcessing * videoProcessor, const OHNativeWindow * window )
```

**Description**

Sets an output surface for video processing.

An output surface must be set before video processing starts.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to a video processing instance.| 
| window | Pointer to the output surface.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the output surface is successfully set.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if the window is a null pointer.


### OH_VideoProcessing_Start()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Start (OH_VideoProcessing * videoProcessor)
```

**Description**

Starts video processing.

After video processing starts, the callback [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate) reports the **VIDEO_PROCESSING_STATE_RUNNING** state. For details, see [VideoProcessing_State](#videoprocessing_state).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to a video processing instance.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the processing is successful.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED** if no output surface is set, no input surface is created, or the instance is running.


### OH_VideoProcessing_Stop()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Stop (OH_VideoProcessing * videoProcessor)
```

**Description**

Stops video processing.

After video processing stops, the callback [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate) reports the **VIDEO_PROCESSING_STATE_STOPPED** state. For details, see [VideoProcessing_State](#videoprocessing_state).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoProcessor | Pointer to a video processing instance.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the processing is successful.

- **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not a video processing instance.

- **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED** if the instance is stopped.


### OH_VideoProcessingCallback_BindOnError()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnError (VideoProcessing_Callback * callback, OH_VideoProcessingCallback_OnError onError )
```

**Description**

Binds the callback function [OH_VideoProcessingCallback_OnError](#oh_videoprocessingcallback_onerror) to a video processing callback object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Pointer to a callback object.| 
| onError | Callback function to bind.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the binding is successful.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if **callback** or **onError** is null.


### OH_VideoProcessingCallback_BindOnNewOutputBuffer()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnNewOutputBuffer (VideoProcessing_Callback * callback, OH_VideoProcessingCallback_OnNewOutputBuffer onNewOutputBuffer )
```

**Description**

Binds the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer) to a video processing callback object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Pointer to a callback object.| 
| onNewOutputBuffer | Callback function to bind.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the binding is successful.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if **callback** is null.


### OH_VideoProcessingCallback_BindOnState()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnState (VideoProcessing_Callback * callback, OH_VideoProcessingCallback_OnState onState )
```

**Description**

Binds the callback function [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate) to a video processing callback object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Pointer to a callback object.| 
| onState | Callback function to bind.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the binding is successful.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if **callback** or **onState** is null.


### OH_VideoProcessingCallback_Create()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Create (VideoProcessing_Callback ** callback)
```

**Description**

Creates a video processing callback object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback |  Double pointer to the video processing callback object. Before creating a callback object, **\*callback** must be a null pointer.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the callback object is created.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if **callback** is null or **\*callback** is not null.

- **VIDEO_PROCESSING_ERROR_NO_MEMORY** if the memory is insufficient.


### OH_VideoProcessingCallback_Destroy()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Destroy (VideoProcessing_Callback * callback)
```

**Description**

Destroys a video processing callback object.

The video processing callback object can be destroyed after the callback function is registered.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Pointer to the callback object. You are advised to set the pointer to a null pointer after the callback object is destroyed.| 

**Returns**

Returns one of the following error codes defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1):

- **VIDEO_PROCESSING_SUCCESS** if the callback object is destroyed.

- **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER** if **callback** is null.


## Variable Description


### VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL

```
const char* VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL
```

**Description**

Pointer to the quality level of video detail enhancement.

For details about the available options, see [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel). You can call [OH_VideoProcessing_SetParameter](#oh_videoprocessing_setparameter) to set the quality level, and call [OH_VideoProcessing_GetParameter](#oh_videoprocessing_getparameter) to obtain the quality level.

**Since**: 12


### VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION

```
const int32_t VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION
```

**Description**

Instance created for color space conversion during video processing.

Call [OH_VideoProcessing_Create](#oh_videoprocessing_create) to create such an instance for color space conversion. If color space conversion is not supported, **VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) is returned.

**Since**: 12


### VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER

```
const int32_t VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER
```

**Description**

Instance for detail enhancement during video processing.

Call [OH_VideoProcessing_Create](#oh_videoprocessing_create) to create such an instance for detail enhancement. If detail enhancement is not supported, **VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) is returned.

**Since**: 12


### VIDEO_PROCESSING_TYPE_METADATA_GENERATION

```
const int32_t VIDEO_PROCESSING_TYPE_METADATA_GENERATION
```

**Description**

Instance created for metadata generation during video processing.

Call [OH_VideoProcessing_Create](#oh_videoprocessing_create) to create such an instance for metadata generation. If metadata generation is not supported, **VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** defined in [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) is returned.

**Since**: 12
