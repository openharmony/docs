# video_processing_types.h

## 概述

视频处理类型定义。

**库：** libvideo_processing.so

**系统能力：** SystemCapability.Multimedia.VideoProcessingEngine

**起始版本：** 12

**相关模块：** [VideoProcessing](capi-videoprocessing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [VideoProcessing_ColorSpaceInfo](capi-videoprocessing-videoprocessing-colorspaceinfo.md) | VideoProcessing_ColorSpaceInfo | 视频颜色空间信息数据结构。 |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md) | OH_VideoProcessing | 定义视频处理对象。<br>定义一个OH_VideoProcessing空指针，调用[OH_VideoProcessing_Create](capi-video-processing-h.md#oh_videoprocessing_create)创建视频处理实例，该指针在创建实例之前必须为空。用户可以对不同的处理类型创建不同的视频处理实例。 |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md) | VideoProcessing_Callback | 视频处理回调对象类型。<br>定义一个VideoProcessing_Callback空指针，调用[OH_VideoProcessingCallback_Create](capi-video-processing-h.md#oh_videoprocessingcallback_create)来创建一个回调对象。创建之前该指针必须为空。通过调用[OH_VideoProcessing_RegisterCallback](capi-video-processing-h.md#oh_videoprocessing_registercallback)来向视频处理实例注册回调对象。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel) | VideoDetailEnhancer_QualityLevel | 用于细节增强的质量等级。 |
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) | VideoProcessing_ErrorCode | 视频处理错误码。 |
| [VideoProcessing_State](#videoprocessing_state) | VideoProcessing_State | 视频处理状态。<br>视频处理状态通过回调函数[OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)进行报告。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_VideoProcessingCallback_OnError)(OH_VideoProcessing* videoProcessor,VideoProcessing_ErrorCode error, void* userData)](#oh_videoprocessingcallback_onerror) | OH_VideoProcessingCallback_OnError | 视频处理过程中报告错误的回调函数指针。 |
| [typedef void (\*OH_VideoProcessingCallback_OnState)(OH_VideoProcessing* videoProcessor, VideoProcessing_State state,void* userData)](#oh_videoprocessingcallback_onstate) | OH_VideoProcessingCallback_OnState | 报告视频处理状态的回调函数指针。<br>[OH_VideoProcessing_Start](capi-video-processing-h.md#oh_videoprocessing_start)成功调用之后状态会变为[VideoProcessing_State](#videoprocessing_state).VIDEO_PROCESSING_STATE_RUNNING。调用[OH_VideoProcessing_Stop](capi-video-processing-h.md#oh_videoprocessing_stop)，所有的缓存buffer处理完成后，状态会变为[VideoProcessing_State](#videoprocessing_state).VIDEO_PROCESSING_STATE_STOPPED。 |
| [typedef void (\*OH_VideoProcessingCallback_OnNewOutputBuffer)(OH_VideoProcessing* videoProcessor, uint32_t index,void* userData)](#oh_videoprocessingcallback_onnewoutputbuffer) | OH_VideoProcessingCallback_OnNewOutputBuffer | 报告输出buffer已填充好数据的回调函数指针。<br>每个新输出buffer填充好数据之后该buffer的索引就会报告给用户。调用[OH_VideoProcessing_RenderOutputBuffer](capi-video-processing-h.md#oh_videoprocessing_renderoutputbuffer)根据索引来处理渲染并输出该buffer。如果未注册该函数，则输出buffer填充好数据后不会报告用户，而是直接进行处理渲染并输出。 |

### 变量

| 名称 | 描述 |
| -- | -- |
| const int32_t VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION | 表示创建颜色空间转换视频处理实例。<br>调用[OH_VideoProcessing_Create](capi-video-processing-h.md#oh_videoprocessing_create)创建颜色空间转换视频处理实例，如果不支持该能力返回[VideoProcessing_ErrorCode](#videoprocessing_errorcode).VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。<br>**起始版本：** 12 |
| const int32_t VIDEO_PROCESSING_TYPE_METADATA_GENERATION | 表示创建元数据生成视频处理实例。<br>调用[OH_VideoProcessing_Create](capi-video-processing-h.md#oh_videoprocessing_create)创建元数据生成视频处理实例，如果不支持该能力返回[VideoProcessing_ErrorCode](#videoprocessing_errorcode).VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。<br>**起始版本：** 12 |
| const int32_t VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER | 表示创建细节增强视频处理实例。<br>调用[OH_VideoProcessing_Create](capi-video-processing-h.md#oh_videoprocessing_create)创建细节增强视频处理实例，如果不支持该能力返回[VideoProcessing_ErrorCode](#videoprocessing_errorcode).VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。<br>**起始版本：** 12 |
| const char* VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL | 指定视频细节增强的质量等级，参考[VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel)查看具体取值。<br>调用[OH_VideoProcessing_SetParameter](capi-video-processing-h.md#oh_videoprocessing_setparameter)设置质量等级。<br>调用[OH_VideoProcessing_GetParameter](capi-video-processing-h.md#oh_videoprocessing_getparameter)获取当前质量等级。<br>**起始版本：** 12 |

## 枚举类型说明

### VideoDetailEnhancer_QualityLevel

```
enum VideoDetailEnhancer_QualityLevel
```

**描述**

用于细节增强的质量等级。参数VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL的具体取值，设置方法详见开发指南。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_NONE | 无细节增强。 |
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_LOW | 低质量等级细节增强，速度较快，默认设置。 |
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM | 中等质量等级细节增强，速度适中。 |
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH | 高质量等级细节增强，速度相对较慢。 |

**参考：**

[OH_VideoProcessing_SetParameter](capi-video-processing-h.md#oh_videoprocessing_setparameter)

[OH_VideoProcessing_GetParameter](capi-video-processing-h.md#oh_videoprocessing_getparameter)

### VideoProcessing_ErrorCode

```
enum VideoProcessing_ErrorCode
```

**描述**

视频处理错误码。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| VIDEO_PROCESSING_SUCCESS | 处理成功。 |
| VIDEO_PROCESSING_ERROR_INVALID_PARAMETER = 401 | 输入参数无效。以下情况都会返回该错误码：<br>1. 无效的输入或输出视频buffer，视频buffer为空。<br>2. 无效的参数，参数为空。<br>3. 无效的处理类型。 |
| VIDEO_PROCESSING_ERROR_UNKNOWN = 29210001 | 未知错误，比如GPU计算失败或memcpy失败。 |
| VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED | 视频处理全局环境初始化失败，比如初始化GPU环境失败。 |
| VIDEO_PROCESSING_ERROR_CREATE_FAILED | 创建视频处理实例失败，比如实例总数超出上限。 |
| VIDEO_PROCESSING_ERROR_PROCESS_FAILED | 处理过程失败，比如处理时间超时。 |
| VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING | 不支持的处理类型，可以调用OH_VideoProcessing_IsXXXSupported来检查是否支持这种处理。 |
| VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED | 不允许的操作，比如不满足调用接口所需的运行状态下调用该接口。 |
| VIDEO_PROCESSING_ERROR_NO_MEMORY | 内存不足。 |
| VIDEO_PROCESSING_ERROR_INVALID_INSTANCE | 视频处理实例无效，比如视频处理实例为空实例。 |
| VIDEO_PROCESSING_ERROR_INVALID_VALUE | 输入值无效，以下情况都会造成这种错误：<br>1. 视频buffer宽高太大或者颜色空间错误。<br>2. 参数包含无效的值，比如细节增强的质量等级错误。 |

### VideoProcessing_State

```
enum VideoProcessing_State
```

**描述**

视频处理状态。

视频处理状态通过回调函数[OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)进行报告。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| VIDEO_PROCESSING_STATE_RUNNING | 视频处理进行中。 |
| VIDEO_PROCESSING_STATE_STOPPED | 视频处理已停止。 |


## 函数说明

### OH_VideoProcessingCallback_OnError()

```
typedef void (*OH_VideoProcessingCallback_OnError)(OH_VideoProcessing* videoProcessor,VideoProcessing_ErrorCode error, void* userData)
```

**描述**

视频处理过程中报告错误的回调函数指针。

错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode)：

VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING，不支持的处理，比如不支持输入输出的颜色空间类型转换。

VIDEO_PROCESSING_ERROR_INVALID_VALUE，无效的视频属性，比如视频的颜色空间无效。

VIDEO_PROCESSING_ERROR_NO_MEMORY，内存不足。

VIDEO_PROCESSING_ERROR_PROCESS_FAILED，处理过程中出错。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 视频处理实例。 |
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) error | 报告给用户的错误码。 |
|  void* userData | 用户的自定义数据。 |

### OH_VideoProcessingCallback_OnState()

```
typedef void (*OH_VideoProcessingCallback_OnState)(OH_VideoProcessing* videoProcessor, VideoProcessing_State state,void* userData)
```

**描述**

报告视频处理状态的回调函数指针。

[OH_VideoProcessing_Start](capi-video-processing-h.md#oh_videoprocessing_start)成功调用之后状态会变为[VideoProcessing_State](#videoprocessing_state).VIDEO_PROCESSING_STATE_RUNNING。调用[OH_VideoProcessing_Stop](capi-video-processing-h.md#oh_videoprocessing_stop)，所有的缓存buffer处理完成后，状态会变为[VideoProcessing_State](#videoprocessing_state).VIDEO_PROCESSING_STATE_STOPPED。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 视频处理实例。 |
|  [VideoProcessing_State](#videoprocessing_state) state | 视频处理状态。 |
| void* userData | 用户的自定义数据。 |

### OH_VideoProcessingCallback_OnNewOutputBuffer()

```
typedef void (*OH_VideoProcessingCallback_OnNewOutputBuffer)(OH_VideoProcessing* videoProcessor, uint32_t index,void* userData)
```

**描述**

报告输出buffer已填充好数据的回调函数指针。

每个新输出buffer填充好数据之后该buffer的索引就会报告给用户。调用[OH_VideoProcessing_RenderOutputBuffer](capi-video-processing-h.md#oh_videoprocessing_renderoutputbuffer)根据索引来处理渲染并输出该buffer。如果未注册该函数，则输出buffer填充好数据后不会报告用户，而是直接进行处理渲染并输出。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 视频处理实例。 |
|  uint32_t index | 新输出buffer的索引。 |
| void* userData | 用户自定义的数据。 |


