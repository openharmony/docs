# video_processing.h


## Overview

The **video_processing.h** file declares the video processing functions.

It provides video processing capabilities, including color space conversion, metadata generation, and video scaling.

**Library**: libvideo_processing.so

**File to include**: <multimedia/video_processing_engine/video_processing.h>

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Since**: 12

**Related module**: [VideoProcessing](_video_processing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_InitializeEnvironment](_video_processing.md#oh_videoprocessing_initializeenvironment) (void) | Initializes the global video processing environment.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_DeinitializeEnvironment](_video_processing.md#oh_videoprocessing_deinitializeenvironment) (void) | Releases the global video processing environment.| 
| bool [OH_VideoProcessing_IsColorSpaceConversionSupported](_video_processing.md#oh_videoprocessing_iscolorspaceconversionsupported) (const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*sourceVideoInfo, const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*destinationVideoInfo) | Checks whether color space conversion is supported during video processing.| 
| bool [OH_VideoProcessing_IsMetadataGenerationSupported](_video_processing.md#oh_videoprocessing_ismetadatagenerationsupported) (const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*sourceVideoInfo) | Checks whether metadata generation is supported during video processing.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_Create](_video_processing.md#oh_videoprocessing_create) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*\*videoProcessor, int type) | Creates a video processing instance.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_Destroy](_video_processing.md#oh_videoprocessing_destroy) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor) | Destroys a video processing instance.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_RegisterCallback](_video_processing.md#oh_videoprocessing_registercallback) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, const [VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback, void \*userData) | Registers a callback for video processing.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_SetSurface](_video_processing.md#oh_videoprocessing_setsurface) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, const [OHNativeWindow](_video_processing.md#ohnativewindow) \*window) | Sets an output surface for video processing.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_GetSurface](_video_processing.md#oh_videoprocessing_getsurface) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, [OHNativeWindow](_video_processing.md#ohnativewindow) \*\*window) | Creates a surface for video processing.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_SetParameter](_video_processing.md#oh_videoprocessing_setparameter) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, const [OH_AVFormat](_video_processing.md#oh_avformat) \*parameter) | Sets video processing parameters.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_GetParameter](_video_processing.md#oh_videoprocessing_getparameter) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, [OH_AVFormat](_video_processing.md#oh_avformat) \*parameter) | Obtains video processing parameters.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_Start](_video_processing.md#oh_videoprocessing_start) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor) | Starts video processing.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_Stop](_video_processing.md#oh_videoprocessing_stop) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor) | Stops video processing.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_RenderOutputBuffer](_video_processing.md#oh_videoprocessing_renderoutputbuffer) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, uint32_t index) | Renders and processes the buffer, and then outputs it.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_Create](_video_processing.md#oh_videoprocessingcallback_create) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*\*callback) | Creates a video processing callback object.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_Destroy](_video_processing.md#oh_videoprocessingcallback_destroy) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback) | Destroys a video processing callback object.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnError](_video_processing.md#oh_videoprocessingcallback_bindonerror) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnError](_video_processing.md#oh_videoprocessingcallback_onerror) onError) | Binds the callback function [OH_VideoProcessingCallback_OnError](_video_processing.md#oh_videoprocessingcallback_onerror) to a video processing callback object.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnState](_video_processing.md#oh_videoprocessingcallback_bindonstate) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnState](_video_processing.md#oh_videoprocessingcallback_onstate) onState) | Binds the callback function [OH_VideoProcessingCallback_OnState](_video_processing.md#oh_videoprocessingcallback_onstate) to a video processing callback object.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnNewOutputBuffer](_video_processing.md#oh_videoprocessingcallback_bindonnewoutputbuffer) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnNewOutputBuffer](_video_processing.md#oh_videoprocessingcallback_onnewoutputbuffer) onNewOutputBuffer) | Binds the callback function [OH_VideoProcessingCallback_OnNewOutputBuffer](_video_processing.md#oh_videoprocessingcallback_onnewoutputbuffer) to a video processing callback object.| 
