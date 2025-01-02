# video_processing_types.h


## 概述

视频处理类型定义。

**库：** libvideo_processing.so

**引用文件：** <multimedia/video_processing_engine/video_processing_types.h>

**系统能力：** SystemCapability.Multimedia.VideoProcessingEngine

**起始版本：** 12

**相关模块：**[VideoProcessing](_video_processing.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) | 视频颜色空间信息数据结构。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_VideoProcessing](_video_processing.md#oh_videoprocessing ) [OH_VideoProcessing](_video_processing.md#oh_videoprocessing) | 定义视频处理对象。 | 
| typedef struct NativeWindow [OHNativeWindow](_video_processing.md#ohnativewindow) | 定义NativeWindow对象。 | 
| typedef struct [OH_AVFormat](_video_processing.md#oh_avformat-1) [OH_AVFormat](_video_processing.md#oh_avformat) | 定义OH_AVFormat对象。 | 
| typedef struct [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) [VideoProcessing_ColorSpaceInfo](_video_processing.md#videoprocessing_colorspaceinfo) | 视频颜色空间信息数据结构。 | 
| typedef enum [VideoDetailEnhancer_QualityLevel](_video_processing.md#videodetailenhancer_qualitylevel-1) [VideoDetailEnhancer_QualityLevel](_video_processing.md#videodetailenhancer_qualitylevel) | 用于细节增强的质量等级。 | 
| typedef enum [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode-1) [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) | 视频处理错误码。 | 
| typedef enum [VideoProcessing_State](_video_processing.md#videoprocessing_state-1) [VideoProcessing_State](_video_processing.md#videoprocessing_state) | 视频处理状态。 | 
| typedef struct [VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) [VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) | 视频处理回调对象类型。 | 
| typedef void(\* [OH_VideoProcessingCallback_OnError](_video_processing.md#oh_videoprocessingcallback_onerror)) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) error, void \*userData) | 视频处理过程中报告错误的回调函数指针。 | 
| typedef void(\* [OH_VideoProcessingCallback_OnState](_video_processing.md#oh_videoprocessingcallback_onstate)) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, [VideoProcessing_State](_video_processing.md#videoprocessing_state) state, void \*userData) | 报告视频处理状态的回调函数指针。 | 
| typedef void(\* [OH_VideoProcessingCallback_OnNewOutputBuffer](_video_processing.md#oh_videoprocessingcallback_onnewoutputbuffer)) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, uint32_t index, void \*userData) | 报告输出buffer已填充好数据的回调函数指针。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [VideoDetailEnhancer_QualityLevel](_video_processing.md#videodetailenhancer_qualitylevel-1) {<br/>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_NONE,<br/>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_LOW,<br/>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM,<br/>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH } | 用于细节增强的质量等级。 | 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode-1) {<br/>VIDEO_PROCESSING_SUCCESS,<br/>VIDEO_PROCESSING_ERROR_INVALID_PARAMETER = 401,<br/>VIDEO_PROCESSING_ERROR_UNKNOWN = 29210001,<br/>VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED,<br/>VIDEO_PROCESSING_ERROR_CREATE_FAILED,<br/>VIDEO_PROCESSING_ERROR_PROCESS_FAILED,<br/>VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,<br/>VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,<br/>VIDEO_PROCESSING_ERROR_NO_MEMORY,<br/>VIDEO_PROCESSING_ERROR_INVALID_INSTANCE,<br/>VIDEO_PROCESSING_ERROR_INVALID_VALUE<br/>} | 视频处理错误码。 | 
| [VideoProcessing_State](_video_processing.md#videoprocessing_state-1) {<br/>VIDEO_PROCESSING_STATE_RUNNING,<br/>VIDEO_PROCESSING_STATE_STOPPED } | 视频处理状态。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const int32_t [VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](_video_processing.md#video_processing_type_color_space_conversion) | 表示创建颜色空间转换视频处理实例。 | 
| const int32_t [VIDEO_PROCESSING_TYPE_METADATA_GENERATION](_video_processing.md#video_processing_type_metadata_generation) | 表示创建元数据生成视频处理实例。 | 
| const int32_t [VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER](_video_processing.md#video_processing_type_detail_enhancer) | 表示创建细节增强视频处理实例。 | 
| const char \* [VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](_video_processing.md#video_detail_enhancer_parameter_key_quality_level) | 指定视频细节增强的质量等级。 | 
