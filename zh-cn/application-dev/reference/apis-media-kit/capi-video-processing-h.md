# video_processing.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--SE: @HmQQQ-->
<!--TSE: @xchaosioda-->

## 概述

声明视频处理函数。

提供视频处理能力，包括颜色空间转换、元数据生成和视频缩放。

**库：** libvideo_processing.so

**系统能力：** SystemCapability.Multimedia.VideoProcessingEngine

**起始版本：** 12

**相关模块：** [VideoProcessing](capi-videoprocessing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [VideoProcessing_ErrorCode OH_VideoProcessing_InitializeEnvironment(void)](#oh_videoprocessing_initializeenvironment) | 初始化视频处理全局环境。<br>该函数是可选的。<br>该函数只在主进程启动时被调用一次，用于初始化视频处理全局环境，这样可以减少[OH_VideoProcessing_Create](#oh_videoprocessing_create)的时间。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_DeinitializeEnvironment(void)](#oh_videoprocessing_deinitializeenvironment) | 释放视频处理全局环境。<br>调用前，必须调用[OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment)初始化。<br>通常在主进程即将退出时调用该函数来释放通过调用[OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment)函数初始化的全局环境。<br>如果仍有视频处理的实例运行中，就不能调用该函数。 |
| [bool OH_VideoProcessing_IsColorSpaceConversionSupported(const VideoProcessing_ColorSpaceInfo* sourceVideoInfo,const VideoProcessing_ColorSpaceInfo* destinationVideoInfo)](#oh_videoprocessing_iscolorspaceconversionsupported) | 查询是否支持视频颜色空间转换。 |
| [bool OH_VideoProcessing_IsMetadataGenerationSupported(const VideoProcessing_ColorSpaceInfo* sourceVideoInfo)](#oh_videoprocessing_ismetadatagenerationsupported) | 查询是否支持视频元数据生成。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_Create(OH_VideoProcessing** videoProcessor, int type)](#oh_videoprocessing_create) | 创建视频处理实例。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_Destroy(OH_VideoProcessing* videoProcessor)](#oh_videoprocessing_destroy) | 销毁视频处理实例。<br>销毁之前先停止实例，参阅[OH_VideoProcessing_Stop](#oh_videoprocessing_stop)。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_RegisterCallback(OH_VideoProcessing* videoProcessor,const VideoProcessing_Callback* callback, void* userData)](#oh_videoprocessing_registercallback) | 注册回调函数。<br>在开始视频处理之前注册回调函数，视频处理过程中无法注册回调函数。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_SetSurface(OH_VideoProcessing* videoProcessor,const OHNativeWindow* window)](#oh_videoprocessing_setsurface) | 设置视频处理输出surface。<br>在视频处理启动之前设置输出surface。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_GetSurface(OH_VideoProcessing* videoProcessor, OHNativeWindow** window)](#oh_videoprocessing_getsurface) | 创建surface。<br>在视频处理启动之前创建输入surface。调用[OH_NativeWindow_DestroyNativeWindow](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_destroynativewindow)销毁输入surface。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_SetParameter(OH_VideoProcessing* videoProcessor,const OH_AVFormat* parameter)](#oh_videoprocessing_setparameter) | 设置视频处理输出参数。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_GetParameter(OH_VideoProcessing* videoProcessor, OH_AVFormat* parameter)](#oh_videoprocessing_getparameter) | 获取视频处理参数。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_Start(OH_VideoProcessing* videoProcessor)](#oh_videoprocessing_start) | 启动视频处理。<br>成功启动后，回调函数[OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate)会报告[VIDEO_PROCESSING_STATE_RUNNING](capi-video-processing-types-h.md#videoprocessing_state)状态。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_Stop(OH_VideoProcessing* videoProcessor)](#oh_videoprocessing_stop) | 停止视频处理。<br>成功停止后，回调函数[OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate)会报告[VIDEO_PROCESSING_STATE_STOPPED](capi-video-processing-types-h.md#videoprocessing_state)状态。 |
| [VideoProcessing_ErrorCode OH_VideoProcessing_RenderOutputBuffer(OH_VideoProcessing* videoProcessor, uint32_t index)](#oh_videoprocessing_renderoutputbuffer) | 渲染处理并输出buffer。<br>如果设置了回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer)，当输出buffer准备好之后会通过回调函数把buffer的索引返回给用户。 |
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_Create(VideoProcessing_Callback** callback)](#oh_videoprocessingcallback_create) | 创建视频处理回调函数对象。 |
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_Destroy(VideoProcessing_Callback* callback)](#oh_videoprocessingcallback_destroy) | 销毁回调对象。回调对象在注册之后就可以销毁。 |
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnError(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnError onError)](#oh_videoprocessingcallback_bindonerror) | 绑定回调函数[OH_VideoProcessingCallback_OnError](capi-video-processing-types-h.md#oh_videoprocessingcallback_onerror)到回调对象。 |
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnState(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnState onState)](#oh_videoprocessingcallback_bindonstate) | 绑定回调函数[OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate)到回调对象。 |
| [VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnNewOutputBuffer(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnNewOutputBuffer onNewOutputBuffer)](#oh_videoprocessingcallback_bindonnewoutputbuffer) | 绑定回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer)到回调对象。 |

## 函数说明

### OH_VideoProcessing_InitializeEnvironment()

```
VideoProcessing_ErrorCode OH_VideoProcessing_InitializeEnvironment(void)
```

**描述**

初始化视频处理全局环境。

该函数是可选的。

该函数只在主进程启动时被调用一次，用于初始化视频处理全局环境，这样可以减少[OH_VideoProcessing_Create](#oh_videoprocessing_create)的时间。

调用[OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment)释放视频处理全局环境。

初始化后，必须释放视频处理全局环境，释放方式及时机详见[OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment)。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果初始化成功，返回VIDEO_PROCESSING_SUCCESS，否则返回VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED。<br> 如果失败，应用需要检查GPU是否正常工作。 |

### OH_VideoProcessing_DeinitializeEnvironment()

```
VideoProcessing_ErrorCode OH_VideoProcessing_DeinitializeEnvironment(void)
```

**描述**

释放视频处理全局环境。

调用前，必须调用[OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment)初始化。

通常在主进程即将退出时调用该函数来释放通过调用[OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment)函数初始化的全局环境。

如果仍有视频处理的实例运行中，就不能调用该函数。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果还有视频处理的实例没有销毁或者没有调用[OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment)，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。 |

### OH_VideoProcessing_IsColorSpaceConversionSupported()

```
bool OH_VideoProcessing_IsColorSpaceConversionSupported(const VideoProcessing_ColorSpaceInfo* sourceVideoInfo,const VideoProcessing_ColorSpaceInfo* destinationVideoInfo)
```

**描述**

查询是否支持视频颜色空间转换。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [VideoProcessing_ColorSpaceInfo](capi-videoprocessing-videoprocessing-colorspaceinfo.md)* sourceVideoInfo | 输入视频颜色空间信息。 |
| const [VideoProcessing_ColorSpaceInfo](capi-videoprocessing-videoprocessing-colorspaceinfo.md)* destinationVideoInfo | 输出视频颜色空间信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持视频颜色空间转换返回true，否则返回false。 |

### OH_VideoProcessing_IsMetadataGenerationSupported()

```
bool OH_VideoProcessing_IsMetadataGenerationSupported(const VideoProcessing_ColorSpaceInfo* sourceVideoInfo)
```

**描述**

查询是否支持视频元数据生成。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [VideoProcessing_ColorSpaceInfo](capi-videoprocessing-videoprocessing-colorspaceinfo.md)* sourceVideoInfo | 输入视频颜色空间信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持视频元数据生成返回true，否则返回false。 |

### OH_VideoProcessing_Create()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Create(OH_VideoProcessing** videoProcessor, int type)
```

**描述**

创建视频处理实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)** videoProcessor | 输出参数。指向视频处理对象的指针的指针。输入前\*videoProcessor必须是空指针。 |
| int type | 使用VIDEO_PROCESSING_TYPE_XXX来指定处理类型。实例的处理类型不能改变。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果视频处理实例创建成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果处理类型不支持，返回VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING，例如，不支持元数据生成。<br> 如果创建视频处理实例失败，返回VIDEO_PROCESSING_ERROR_CREATE_FAILED。<br> 如果实例为空或实例的指针非空，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果处理类型无效，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。 |

### OH_VideoProcessing_Destroy()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Destroy(OH_VideoProcessing* videoProcessor)
```

**描述**

销毁视频处理实例。

销毁之前先停止实例，参阅[OH_VideoProcessing_Stop](#oh_videoprocessing_stop)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针，建议在实例销毁之后将其设置为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果实例销毁成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果实例仍在运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。 |

### OH_VideoProcessing_RegisterCallback()

```
VideoProcessing_ErrorCode OH_VideoProcessing_RegisterCallback(OH_VideoProcessing* videoProcessor,const VideoProcessing_Callback* callback, void* userData)
```

**描述**

注册回调函数。

在开始视频处理之前注册回调函数，视频处理过程中无法注册回调函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针。 |
| const [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | 回调函数指针。 |
| void* userData | 指向用户特定数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果回调函数注册成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果回调函数指针为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。<br> 如果实例仍在运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。 |

### OH_VideoProcessing_SetSurface()

```
VideoProcessing_ErrorCode OH_VideoProcessing_SetSurface(OH_VideoProcessing* videoProcessor,const OHNativeWindow* window)
```

**描述**

设置视频处理输出surface。

在视频处理启动之前设置输出surface。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针。 |
| const [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md)* window | 指向输出surface的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果输出surface设置成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果window为空指针，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。 |

### OH_VideoProcessing_GetSurface()

```
VideoProcessing_ErrorCode OH_VideoProcessing_GetSurface(OH_VideoProcessing* videoProcessor, OHNativeWindow** window)
```

**描述**

创建surface。

在视频处理启动之前创建输入surface。调用[OH_NativeWindow_DestroyNativeWindow](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_destroynativewindow)销毁输入surface。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针。 |
| [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md)** window | 指向输入surface的指针。例如，此输入surface指针可以指向视频解码器输出surface。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果window为空指针或指向window的指针不为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。<br> 如果创建surface失败，或者输入surface已经创建，或者视频处理实例还在运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。 |

### OH_VideoProcessing_SetParameter()

```
VideoProcessing_ErrorCode OH_VideoProcessing_SetParameter(OH_VideoProcessing* videoProcessor,const OH_AVFormat* parameter)
```

**描述**

设置视频处理输出参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针。 |
| const [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* parameter | 指向视频处理参数实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果参数设置成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果参数为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。<br> 如果参数的某些属性无效，返回VIDEO_PROCESSING_ERROR_INVALID_VALUE，例如，包含不支持的参数值。<br> 如果内存分配失败，返回VIDEO_PROCESSING_ERROR_NO_MEMORY。 |

### OH_VideoProcessing_GetParameter()

```
VideoProcessing_ErrorCode OH_VideoProcessing_GetParameter(OH_VideoProcessing* videoProcessor, OH_AVFormat* parameter)
```

**描述**

获取视频处理参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针。 |
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* parameter | 指向视频处理参数实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果参数获取成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果参数为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。 |

### OH_VideoProcessing_Start()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Start(OH_VideoProcessing* videoProcessor)
```

**描述**

启动视频处理。

成功启动后，回调函数[OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate)会报告[VideoProcessing_State](capi-video-processing-types-h.md#videoprocessing_state).VIDEO_PROCESSING_STATE_RUNNING状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果没有设置输出surface，或者没有创建输入surface，或者实例已经运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。 |

### OH_VideoProcessing_Stop()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Stop(OH_VideoProcessing* videoProcessor)
```

**描述**

停止视频处理。

成功停止后，回调函数[OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate)会报告[VideoProcessing_State](capi-video-processing-types-h.md#videoprocessing_state).VIDEO_PROCESSING_STATE_STOPPED状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果实例已经停止，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。 |

### OH_VideoProcessing_RenderOutputBuffer()

```
VideoProcessing_ErrorCode OH_VideoProcessing_RenderOutputBuffer(OH_VideoProcessing* videoProcessor, uint32_t index)
```

**描述**

渲染处理并输出buffer。

如果设置了回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer)，当输出buffer准备好之后会通过回调函数把buffer的索引返回给用户。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_VideoProcessing](capi-videoprocessing-oh-videoprocessing.md)* videoProcessor | 指向视频处理实例的指针。 |
| uint32_t index | 输出buffer的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。<br> 如果索引值无效，输出VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。<br> 如果没有设置回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer)或者实例已经停止运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。 |

### OH_VideoProcessingCallback_Create()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Create(VideoProcessing_Callback** callback)
```

**描述**

创建视频处理回调函数对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)** callback | 输出参数。\*callback是指向回调函数对象的指针。在创建回调函数对象之前\*callback必须为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果回调函数对象创建成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果callback为空或者callback不为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。<br> 如果内存不足，返回VIDEO_PROCESSING_ERROR_NO_MEMORY。 |

### OH_VideoProcessingCallback_Destroy()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Destroy(VideoProcessing_Callback* callback)
```

**描述**

销毁回调对象。回调对象在注册之后就可以销毁。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | 指向回调对象的指针，建议在回调对象销毁之后将其设置为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果回调对象销毁成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果callback为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。 |

### OH_VideoProcessingCallback_BindOnError()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnError(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnError onError)
```

**描述**

绑定回调函数[OH_VideoProcessingCallback_OnError](capi-video-processing-types-h.md#oh_videoprocessingcallback_onerror)到回调对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | 指向回调对象的指针。 |
| [OH_VideoProcessingCallback_OnError](capi-video-processing-types-h.md#oh_videoprocessingcallback_onerror) onError | 回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果函数绑定成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果callback为空或者onError为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。 |

### OH_VideoProcessingCallback_BindOnState()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnState(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnState onState)
```

**描述**

绑定回调函数[OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate)到回调对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | 指向回调对象的指针。 |
| [OH_VideoProcessingCallback_OnState](capi-video-processing-types-h.md#oh_videoprocessingcallback_onstate) onState | 回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果函数绑定成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果callback为空或者onState为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。 |

### OH_VideoProcessingCallback_BindOnNewOutputBuffer()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnNewOutputBuffer(VideoProcessing_Callback* callback,OH_VideoProcessingCallback_OnNewOutputBuffer onNewOutputBuffer)
```

**描述**

绑定回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer)到回调对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [VideoProcessing_Callback](capi-videoprocessing-videoprocessing-callback.md)* callback | 指向回调对象的指针。 |
| [OH_VideoProcessingCallback_OnNewOutputBuffer](capi-video-processing-types-h.md#oh_videoprocessingcallback_onnewoutputbuffer) onNewOutputBuffer | 回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [VideoProcessing_ErrorCode](capi-video-processing-types-h.md#videoprocessing_errorcode) | 如果函数绑定成功，返回VIDEO_PROCESSING_SUCCESS。<br> 如果callback为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。 |


