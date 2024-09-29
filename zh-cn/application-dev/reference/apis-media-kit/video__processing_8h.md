# video_processing.h


## 概述

声明视频处理函数。

提供视频处理能力，包括颜色空间转换、元数据生成和视频缩放。

**库：** libvideo_processing.so

**引用文件：** <multimedia/video_processing_engine/video_processing.h>

**系统能力：** SystemCapability.Multimedia.VideoProcessingEngine

**起始版本：** 12

**相关模块：**[VideoProcessing](_video_processing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_InitializeEnvironment](_video_processing.md#oh_videoprocessing_initializeenvironment) (void) | 初始化视频处理全局环境。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_DeinitializeEnvironment](_video_processing.md#oh_videoprocessing_deinitializeenvironment) (void) | 释放视频处理全局环境。 | 
| bool [OH_VideoProcessing_IsColorSpaceConversionSupported](_video_processing.md#oh_videoprocessing_iscolorspaceconversionsupported) (const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*sourceVideoInfo, const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*destinationVideoInfo) | 查询是否支持视频颜色空间转换。 | 
| bool [OH_VideoProcessing_IsMetadataGenerationSupported](_video_processing.md#oh_videoprocessing_ismetadatagenerationsupported) (const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*sourceVideoInfo) | 查询是否支持视频元数据生成。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_Create](_video_processing.md#oh_videoprocessing_create) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*\*videoProcessor, int type) | 创建视频处理实例。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_Destroy](_video_processing.md#oh_videoprocessing_destroy) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor) | 销毁视频处理实例。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_RegisterCallback](_video_processing.md#oh_videoprocessing_registercallback) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, const [VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback, void \*userData) | 注册回调函数。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_SetSurface](_video_processing.md#oh_videoprocessing_setsurface) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, const [OHNativeWindow](_video_processing.md#ohnativewindow) \*window) | 设置视频处理输出surface。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_GetSurface](_video_processing.md#oh_videoprocessing_getsurface) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, [OHNativeWindow](_video_processing.md#ohnativewindow) \*\*window) | 创建surface。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_SetParameter](_video_processing.md#oh_videoprocessing_setparameter) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, const [OH_AVFormat](_video_processing.md#oh_avformat) \*parameter) | 设置视频处理输出参数。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_GetParameter](_video_processing.md#oh_videoprocessing_getparameter) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, [OH_AVFormat](_video_processing.md#oh_avformat) \*parameter) | 获取视频处理参数。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_Start](_video_processing.md#oh_videoprocessing_start) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor) | 启动视频处理。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_Stop](_video_processing.md#oh_videoprocessing_stop) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor) | 停止视频处理。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessing_RenderOutputBuffer](_video_processing.md#oh_videoprocessing_renderoutputbuffer) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, uint32_t index) | 渲染处理并输出buffer。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_Create](_video_processing.md#oh_videoprocessingcallback_create) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*\*callback) | 创建视频处理回调函数对象。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_Destroy](_video_processing.md#oh_videoprocessingcallback_destroy) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback) | 销毁回调对象。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnError](_video_processing.md#oh_videoprocessingcallback_bindonerror) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnError](_video_processing.md#oh_videoprocessingcallback_onerror) onError) | 绑定回调函数[OH_VideoProcessingCallback_OnError](_video_processing.md#oh_videoprocessingcallback_onerror)到回调对象。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnState](_video_processing.md#oh_videoprocessingcallback_bindonstate) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnState](_video_processing.md#oh_videoprocessingcallback_onstate) onState) | 绑定回调函数[OH_VideoProcessingCallback_OnState](_video_processing.md#oh_videoprocessingcallback_onstate)到回调对象。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnNewOutputBuffer](_video_processing.md#oh_videoprocessingcallback_bindonnewoutputbuffer) ([VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnNewOutputBuffer](_video_processing.md#oh_videoprocessingcallback_onnewoutputbuffer) onNewOutputBuffer) | 绑定回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](_video_processing.md#oh_videoprocessingcallback_onnewoutputbuffer)到回调对象。 | 
