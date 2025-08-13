# video_processing.h

## Overview

The file declares the video processing functions.

It provides video processing capabilities, including color space conversion, metadata generation, and video scaling.

**Library**: libvideo_processing.so

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Since**: 12

**Related module**: [VideoProcessing](capi-videoprocessing.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [VideoProcessing_ErrorCode OH_VideoProcessing_InitializeEnvironment(void)](#oh_videoprocessing_initializeenvironment) | Initializes the global video processing environment.<br>This function is optional.<br>It is called only once when the main process is started to initialize the global video processing environment. This reduces the duration for running [OH_VideoProcessing_Create](#oh_videoprocessing_create).|
| [VideoProcessing_ErrorCode OH_VideoProcessing_DeinitializeEnvironment(void)](#oh_videoprocessing_deinitializeenvironment) | Releases the global video processing environment.<br>Before calling this API, you must call [OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment) to initialize the environment.<br>Generally, this function is called when the main process is about to exit.<br>Do not call this function when a video processing instance is running.|
| [bool OH_VideoProcessing_IsColorSpaceConversionSupported(const VideoProcessing_ColorSpaceInfo* sourceVideoInfo,const VideoProcessing_ColorSpaceInfo* destinationVideoInfo)](#oh_videoprocessing_iscolorspaceconversionsupported) | Checks whether color space conversion is supported during video processing.|
| [bool OH_VideoProcessing_IsMetadataGenerationSupported(const VideoProcessing_ColorSpaceInfo* sourceVideoInfo)](#oh_videoprocessing_ismetadatagenerationsupported) | Checks whether metadata generation is supported during video processing.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_Create(OH_VideoProcessing** videoProcessor, int type)](#oh_videoprocessing_create) | Creates a video processing instance.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_Destroy(OH_VideoProcessing* videoProcessor)](#oh_videoprocessing_destroy) | Destroys a video processing instance.<br>Before destroying the instance, call [OH_VideoProcessing_Stop](#oh_videoprocessing_stop) to stop it.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_RegisterCallback(OH_VideoProcessing* videoProcessor,const VideoProcessing_Callback* callback, void* userData)](#oh_videoprocessing_registercallback) | Registers a callback for video processing.<br>The callback function should be registered before video processing starts. During video processing, it cannot be registered.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_SetSurface(OH_VideoProcessing* videoProcessor,const OHNativeWindow* window)](#oh_videoprocessing_setsurface) | Sets an output surface for video processing.<br>An output surface must be set before video processing starts.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_GetSurface(OH_VideoProcessing* videoProcessor, OHNativeWindow** window)](#oh_videoprocessing_getsurface) | Obtains a surface for video processing.<br>An input surface must be created before video processing starts, it must be destroyed by calling [OH_NativeWindow_DestroyNativeWindow](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_destroynativewindow) when it is no longer needed.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_SetParameter(OH_VideoProcessing* videoProcessor,const OH_AVFormat* parameter)](#oh_videoprocessing_setparameter) | Sets video processing parameters.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_GetParameter(OH_VideoProcessing* videoProcessor, OH_AVFormat* parameter)](#oh_videoprocessing_getparameter) | Obtains video processing parameters.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_Start(OH_VideoProcessing* videoProcessor)](#oh_videoprocessing_start) | Starts video processing.<br>After video processing starts, the callback [OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate) reports the [VIDEO_PROCESSING_STATE_RUNNING](capi-video-processing-types-h.md#videoprocessing_state) state.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_Stop(OH_VideoProcessing* videoProcessor)](#oh_videoprocessing_stop) | Stops video processing.<br>After video processing stops, the callback [OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate) reports the [VIDEO_PROCESSING_STATE_STOPPED](capi-video-processing-types-h.md#videoprocessing_state) state.|
| [VideoProcessing_ErrorCode OH_VideoProcessing_RenderOutputBuffer(OH_VideoProcessing* videoProcessor, uint32_t index)](#oh_videoprocessing_renderoutputbuffer) | Renders and processes the buffer, and then outputs it.<br>If the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer) is set, the buffer index is returned through the callback function after the output buffer is ready.|
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_Create(VideoProcessing_Callback** callback)](#oh_videoprocessingcallback_create) | Creates a video processing callback object.|
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_Destroy(VideoProcessing_Callback* callback)](#oh_videoprocessingcallback_destroy) | Destroys a video processing callback object. The video processing callback object can be destroyed after the callback function is registered.|
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnError(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnError onError)](#oh_videoprocessingcallback_bindonerror) | Binds the callback function [OH_VideoProcessingCallback_OnError](capi-video-processing-types-h.md#oh_videoprocessingcallback_onerror) to a video processing callback object.|
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnState(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnState onState)](#oh_videoprocessingcallback_bindonstate) | Binds the callback function [OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate) to a video processing callback object.|
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnNewOutputBuffer(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnNewOutputBuffer onNewOutputBuffer)](#oh_videoprocessingcallback_bindonnewoutputbuffer) | Binds the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer) to a video processing callback object.|

## Function Description

### OH_VideoProcessing_InitializeEnvironment()

```
VideoProcessing_ErrorCode OH_VideoProcessing_InitializeEnvironment(void)
```

**Description**

Initializes the global video processing environment.

This function is optional.

It is called only once when the main process is started to initialize the global video processing environment. This reduces the duration for running [OH_VideoProcessing_Create](#oh_videoprocessing_create).

The global video processing environment must be released by calling [OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment).

For details about how and when to release the environment, see [OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment).

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The initialization is successful.<br>**VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED**: The initialization fails.<br> If the operation fails, check whether the GPU works properly.|

### OH_VideoProcessing_DeinitializeEnvironment()

```
VideoProcessing_ErrorCode OH_VideoProcessing_DeinitializeEnvironment(void)
```

**Description**

Releases the global video processing environment.

Before calling this API, you must call [OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment) to initialize the environment.

Generally, this function is called when the main process is about to exit.

Do not call this function when a video processing instance is running.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The processing is successful.<br> **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED**: A video processing instance is not destroyed or [OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment) is not called to initialize the environment.|

### OH_VideoProcessing_IsColorSpaceConversionSupported()

```
bool OH_VideoProcessing_IsColorSpaceConversionSupported(const VideoProcessing_ColorSpaceInfo* sourceVideoInfo,const VideoProcessing_ColorSpaceInfo* destinationVideoInfo)
```

**Description**

Checks whether color space conversion is supported during video processing.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [VideoProcessing_ColorSpaceInfo](capi-videoprocessing-videoprocessing-colorspaceinfo.md)* sourceVideoInfo | Pointer to the color space information of the input video.|
| const [VideoProcessing_ColorSpaceInfo](capi-videoprocessing-videoprocessing-colorspaceinfo.md)* destinationVideoInfo | Pointer to the color space information of the output video.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** means that color space conversion is supported, and **false** means the opposite.|

### OH_VideoProcessing_IsMetadataGenerationSupported()

```
bool OH_VideoProcessing_IsMetadataGenerationSupported(const VideoProcessing_ColorSpaceInfo* sourceVideoInfo)
```

**Description**

Checks whether metadata generation is supported during video processing.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [VideoProcessing_ColorSpaceInfo](capi-videoprocessing-videoprocessing-colorspaceinfo.md)* sourceVideoInfo | Pointer to the color space information of the input video.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** means that metadata generation is supported; **false** means the opposite.|

### OH_VideoProcessing_Create()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Create(OH_VideoProcessing** videoProcessor, int type)
```

**Description**

Creates a video processing instance.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)** videoProcessor |  Double pointer to the video processing instance created. Before any input, **\*videoProcessor** must be nullptr.|
| int type | Video processing type. The processing type of an instance cannot be changed.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The video processing instance is created successfully.<br> **VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: The processing type is not supported. For example, metadata generation is not supported.<br> **VIDEO_PROCESSING_ERROR_CREATE_FAILED**: The video processing instance fails to be created.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or the pointer to the instance is not null.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: The video processing type is invalid.|

### OH_VideoProcessing_Destroy()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Destroy(OH_VideoProcessing* videoProcessor)
```

**Description**

Destroys a video processing instance.

Before destroying the instance, call [OH_VideoProcessing_Stop](#oh_videoprocessing_stop) to stop it.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance. You are advised to set the pointer to nullptr after the instance is destroyed.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The instance is destroyed.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED**: The instance is still running.|

### OH_VideoProcessing_RegisterCallback()

```
VideoProcessing_ErrorCode OH_VideoProcessing_RegisterCallback(OH_VideoProcessing* videoProcessor,const VideoProcessing_Callback* callback, void* userData)
```

**Description**

Registers a callback for video processing.

The callback function should be registered before video processing starts. During video processing, it cannot be registered.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
| const [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | Pointer to the callback function.|
| void* userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The callback function is registered.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: The callback function pointer is null.<br> **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED**: The instance is still running.|

### OH_VideoProcessing_SetSurface()

```
VideoProcessing_ErrorCode OH_VideoProcessing_SetSurface(OH_VideoProcessing* videoProcessor,const OHNativeWindow* window)
```

**Description**

Sets an output surface for video processing.

An output surface must be set before video processing starts.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
| const [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md)* window | Pointer to the output surface.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The output surface is successfully set.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: The window is nullptr.|

### OH_VideoProcessing_GetSurface()

```
VideoProcessing_ErrorCode OH_VideoProcessing_GetSurface(OH_VideoProcessing* videoProcessor, OHNativeWindow** window)
```

**Description**

Obtains a surface for video processing.

An input surface must be created before video processing starts, and it must be destroyed by calling [OH_NativeWindow_DestroyNativeWindow](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_destroynativewindow) when it is no longer needed.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
| [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md)** window | Double pointer to the input surface. For example, the input surface pointer can point to an output surface of the video decoder.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The processing is successful.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: The window is nullptr or the pointer to the window is not null.<br> **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED**: The surface fails to be created, an input surface has been created, or the video processing instance is running.|

### OH_VideoProcessing_SetParameter()

```
VideoProcessing_ErrorCode OH_VideoProcessing_SetParameter(OH_VideoProcessing* videoProcessor,const OH_AVFormat* parameter)
```

**Description**

Sets video processing parameters.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
| const [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* parameter | Pointer to the video processing parameter instance.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The parameters are successfully set.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: The parameter is empty.<br> **VIDEO_PROCESSING_ERROR_INVALID_VALUE**: Some properties of a parameter are invalid, for example, unsupported parameter value.<br> **VIDEO_PROCESSING_ERROR_NO_MEMORY**: Memory allocation fails.|

### OH_VideoProcessing_GetParameter()

```
VideoProcessing_ErrorCode OH_VideoProcessing_GetParameter(OH_VideoProcessing* videoProcessor, OH_AVFormat* parameter)
```

**Description**

Obtains video processing parameters.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* parameter | Pointer to the video processing parameter instance.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The parameters are obtained.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: The parameter is empty.|

### OH_VideoProcessing_Start()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Start(OH_VideoProcessing* videoProcessor)
```

**Description**

Starts video processing.

After video processing starts, the callback [OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate) reports the [VideoProcessing_State](capi-video-processing-types-h.md#videoprocessing_state).VIDEO_PROCESSING_STATE_RUNNING state.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The processing is successful.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED**: No output surface is set, no input surface is created, or the instance is running.|

### OH_VideoProcessing_Stop()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Stop(OH_VideoProcessing* videoProcessor)
```

**Description**

Stops video processing.

After video processing stops, the callback [OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate) reports the [VideoProcessing_State](capi-video-processing-types-h.md#videoprocessing_state).VIDEO_PROCESSING_STATE_STOPPED state.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The processing is successful.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED**: The instance is stopped.|

### OH_VideoProcessing_RenderOutputBuffer()

```
VideoProcessing_ErrorCode OH_VideoProcessing_RenderOutputBuffer(OH_VideoProcessing* videoProcessor, uint32_t index)
```

**Description**

Renders and processes the buffer, and then outputs it.

If the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer) is set, the buffer index is returned through the callback function after the output buffer is ready.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | Pointer to the video processing instance.|
| uint32_t index | Index of the output buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The processing is successful.<br> **VIDEO_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not a video processing instance.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: The index is invalid.<br> **VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED**: The callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer) is not set or the instance is stopped.|

### OH_VideoProcessingCallback_Create()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Create(VideoProcessing_Callback** callback)
```

**Description**

Creates a video processing callback object.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)** callback |  Double pointer to the video processing callback object. Before creating a callback object, **\*callback** must be nullptr.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The callback object is created.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: **callback** is null or **callback** is not null.<br> **VIDEO_PROCESSING_ERROR_NO_MEMORY**: The memory is insufficient.|

### OH_VideoProcessingCallback_Destroy()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Destroy(VideoProcessing_Callback* callback)
```

**Description**

Destroys a video processing callback object. The video processing callback object can be destroyed after the callback function is registered.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | Pointer to the callback object. You are advised to set the pointer to nullptr after the callback object is destroyed.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The callback object is destroyed.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: **callback** is null.|

### OH_VideoProcessingCallback_BindOnError()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnError(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnError onError)
```

**Description**

Binds the callback function [OH_VideoProcessingCallback_OnError](capi-video-processing-types-h.md#oh_videoprocessingcallback_onerror) to a video processing callback object.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | Pointer to the callback object.|
| [OH_VideoProcessingCallback_OnError](capi-video-processing-types-h.md#oh_videoprocessingcallback_onerror) onError | Callback function to bind.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The binding is successful.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: **callback** or **onError** is null.|

### OH_VideoProcessingCallback_BindOnState()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnState(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnState onState)
```

**Description**

Binds the callback function [OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate) to a video processing callback object.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | Pointer to the callback object.|
| [OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate) onState | Callback function to bind.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The binding is successful.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: **callback** or **onState** is null.|

### OH_VideoProcessingCallback_BindOnNewOutputBuffer()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnNewOutputBuffer(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnNewOutputBuffer onNewOutputBuffer)
```

**Description**

Binds the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer) to a video processing callback object.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | Pointer to the callback object.|
| [OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer) onNewOutputBuffer | Callback function to bind.|

**Returns**

| Type| Description|
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | **VIDEO_PROCESSING_SUCCESS**: The binding is successful.<br> **VIDEO_PROCESSING_ERROR_INVALID_PARAMETER**: **callback** is null.|
<!--no_check-->