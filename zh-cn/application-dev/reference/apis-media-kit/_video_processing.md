# VideoProcessing


## 概述

提供用于视频处理的API函数。

提供视频处理能力，包括颜色空间转换、元数据生成和视频缩放。

<!--RP1--><!--RP1End-->

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [video_processing.h](video__processing_8h.md) | 声明视频处理函数。 | 
| [video_processing_types.h](video__processing__types_8h.md) | 视频处理类型定义。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) | 视频颜色空间信息数据结构。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_VideoProcessing](#oh_videoprocessing-1) [OH_VideoProcessing](#oh_videoprocessing) | 定义视频处理对象。 | 
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | 定义NativeWindow对象。 | 
| typedef struct [OH_AVFormat](#oh_avformat-1) [OH_AVFormat](#oh_avformat) | 定义OH_AVFormat对象。 | 
| typedef struct [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) [VideoProcessing_ColorSpaceInfo](#videoprocessing_colorspaceinfo) | 视频颜色空间信息数据结构。 | 
| typedef enum [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel-1) [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel) | 用于细节增强的质量等级。 | 
| typedef enum [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) [VideoProcessing_ErrorCode](#videoprocessing_errorcode) | 视频处理错误码。 | 
| typedef enum [VideoProcessing_State](#videoprocessing_state-1) [VideoProcessing_State](#videoprocessing_state) | 视频处理状态。 | 
| typedef struct [VideoProcessing_Callback](#videoprocessing_callback) [VideoProcessing_Callback](#videoprocessing_callback) | 视频处理回调对象类型。 | 
| typedef void(\* [OH_VideoProcessingCallback_OnError](#oh_videoprocessingcallback_onerror)) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, [VideoProcessing_ErrorCode](#videoprocessing_errorcode) error, void \*userData) | 视频处理过程中报告错误的回调函数指针。 | 
| typedef void(\* [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, [VideoProcessing_State](#videoprocessing_state) state, void \*userData) | 报告视频处理状态的回调函数指针。 | 
| typedef void(\* [OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer)) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, uint32_t index, void \*userData) | 报告输出buffer已填充好数据的回调函数指针。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel-1) {<br/>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_NONE,<br/>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_LOW,<br/>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM,<br/>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH } | 用于细节增强的质量等级。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) {<br/>VIDEO_PROCESSING_SUCCESS,<br/>VIDEO_PROCESSING_ERROR_INVALID_PARAMETER = 401,<br/>VIDEO_PROCESSING_ERROR_UNKNOWN = 29210001,<br/>VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED,<br/>VIDEO_PROCESSING_ERROR_CREATE_FAILED,<br/>VIDEO_PROCESSING_ERROR_PROCESS_FAILED,<br/>VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,<br/>VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,<br/>VIDEO_PROCESSING_ERROR_NO_MEMORY,<br/>VIDEO_PROCESSING_ERROR_INVALID_INSTANCE,<br/>VIDEO_PROCESSING_ERROR_INVALID_VALUE<br/>} | 视频处理错误码。 | 
| [VideoProcessing_State](#videoprocessing_state-1) {<br/>VIDEO_PROCESSING_STATE_RUNNING,<br/>VIDEO_PROCESSING_STATE_STOPPED } | 视频处理状态。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment) (void) | 初始化视频处理全局环境。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment) (void) | 释放视频处理全局环境。 | 
| bool [OH_VideoProcessing_IsColorSpaceConversionSupported](#oh_videoprocessing_iscolorspaceconversionsupported) (const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*sourceVideoInfo, const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*destinationVideoInfo) | 查询是否支持视频颜色空间转换。 | 
| bool [OH_VideoProcessing_IsMetadataGenerationSupported](#oh_videoprocessing_ismetadatagenerationsupported) (const [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) \*sourceVideoInfo) | 查询是否支持视频元数据生成。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_Create](#oh_videoprocessing_create) ([OH_VideoProcessing](#oh_videoprocessing) \*\*videoProcessor, int type) | 创建视频处理实例。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_Destroy](#oh_videoprocessing_destroy) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor) | 销毁视频处理实例。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_RegisterCallback](#oh_videoprocessing_registercallback) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, const [VideoProcessing_Callback](#videoprocessing_callback) \*callback, void \*userData) | 注册回调函数。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_SetSurface](#oh_videoprocessing_setsurface) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, const [OHNativeWindow](#ohnativewindow) \*window) | 设置视频处理输出surface。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_GetSurface](#oh_videoprocessing_getsurface) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, [OHNativeWindow](#ohnativewindow) \*\*window) | 创建surface。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_SetParameter](#oh_videoprocessing_setparameter) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, const [OH_AVFormat](#oh_avformat) \*parameter) | 设置视频处理输出参数。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_GetParameter](#oh_videoprocessing_getparameter) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, [OH_AVFormat](#oh_avformat) \*parameter) | 获取视频处理参数。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_Start](#oh_videoprocessing_start) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor) | 启动视频处理。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_Stop](#oh_videoprocessing_stop) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor) | 停止视频处理。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessing_RenderOutputBuffer](#oh_videoprocessing_renderoutputbuffer) ([OH_VideoProcessing](#oh_videoprocessing) \*videoProcessor, uint32_t index) | 渲染处理并输出buffer。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_Create](#oh_videoprocessingcallback_create) ([VideoProcessing_Callback](#videoprocessing_callback) \*\*callback) | 创建视频处理回调函数对象。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_Destroy](#oh_videoprocessingcallback_destroy) ([VideoProcessing_Callback](#videoprocessing_callback) \*callback) | 销毁回调对象。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnError](#oh_videoprocessingcallback_bindonerror) ([VideoProcessing_Callback](#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnError](#oh_videoprocessingcallback_onerror) onError) | 绑定回调函数[OH_VideoProcessingCallback_OnError](#oh_videoprocessingcallback_onerror)到回调对象。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnState](#oh_videoprocessingcallback_bindonstate) ([VideoProcessing_Callback](#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate) onState) | 绑定回调函数[OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)到回调对象。 | 
| [VideoProcessing_ErrorCode](#videoprocessing_errorcode) [OH_VideoProcessingCallback_BindOnNewOutputBuffer](#oh_videoprocessingcallback_bindonnewoutputbuffer) ([VideoProcessing_Callback](#videoprocessing_callback) \*callback, [OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer) onNewOutputBuffer) | 绑定回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer)到回调对象。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const int32_t [VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](#video_processing_type_color_space_conversion) | 表示创建颜色空间转换视频处理实例。 | 
| const int32_t [VIDEO_PROCESSING_TYPE_METADATA_GENERATION](#video_processing_type_metadata_generation) | 表示创建元数据生成视频处理实例。 | 
| const int32_t [VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER](#video_processing_type_detail_enhancer) | 表示创建细节增强视频处理实例。 | 
| const char \* [VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#video_detail_enhancer_parameter_key_quality_level) | 指定视频细节增强的质量等级。 | 


## 类型定义说明


### OH_AVFormat

```
typedef struct OH_AVFormatOH_AVFormat
```

**描述**

定义OH_AVFormat对象。

**起始版本：** 12


### OH_VideoProcessing

```
typedef struct OH_VideoProcessingOH_VideoProcessing
```

**描述**

定义视频处理对象。

定义一个OH_VideoProcessing空指针，调用[OH_VideoProcessing_Create](#oh_videoprocessing_create)创建视频处理实例，该指针在创建实例之前必须为空。 用户可以对不同的处理类型创建不同的视频处理实例。

**起始版本：** 12


### OH_VideoProcessingCallback_OnError

```
typedef void(* OH_VideoProcessingCallback_OnError) (OH_VideoProcessing *videoProcessor, VideoProcessing_ErrorCode error, void *userData)
```

**描述**

视频处理过程中报告错误的回调函数指针。

错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING，不支持的处理，比如不支持输入输出的颜色空间类型转换。

- VIDEO_PROCESSING_ERROR_INVALID_VALUE，无效的视频属性，比如视频的颜色空间无效。

- VIDEO_PROCESSING_ERROR_NO_MEMORY, 内存不足。

- VIDEO_PROCESSING_ERROR_PROCESS_FAILED，处理过程中出错。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 视频处理实例。 | 
| error | 报告给用户的错误码。 | 
| userData | 用户的自定义数据。 | 


### OH_VideoProcessingCallback_OnNewOutputBuffer

```
typedef void(* OH_VideoProcessingCallback_OnNewOutputBuffer) (OH_VideoProcessing *videoProcessor, uint32_t index, void *userData)
```

**描述**

报告输出buffer已填充好数据的回调函数指针。

每个新输出buffer填充好数据之后该buffer的索引就会报告给用户。调用[OH_VideoProcessing_RenderOutputBuffer](#oh_videoprocessing_renderoutputbuffer)根据索引来处理渲染并输出该buffer。 如果未注册该函数，则输出buffer填充好数据后不会报告用户，而是直接进行处理渲染并输出。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 视频处理实例。 | 
| index | 新输出buffer的索引。 | 
| userData | 用户自定义的数据。 | 


### OH_VideoProcessingCallback_OnState

```
typedef void(* OH_VideoProcessingCallback_OnState) (OH_VideoProcessing *videoProcessor, VideoProcessing_State state, void *userData)
```

**描述**

报告视频处理状态的回调函数指针。

[OH_VideoProcessing_Start](#oh_videoprocessing_start)成功调用之后状态会变为VIDEO_PROCESSING_STATE_RUNNING。 调用[OH_VideoProcessing_Stop](#oh_videoprocessing_stop)，所有的缓存buffer处理完成后，状态会变为VIDEO_PROCESSING_STATE_STOPPED。状态说明参阅[VideoProcessing_State](#videoprocessing_state)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 视频处理实例。 | 
| state | 参阅 [VideoProcessing_State](#videoprocessing_state)。 | 
| userData | 用户的自定义数据。 | 


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```

**描述**

定义NativeWindow对象。

**起始版本：** 12


### VideoDetailEnhancer_QualityLevel

```
typedef enum VideoDetailEnhancer_QualityLevelVideoDetailEnhancer_QualityLevel
```

**描述**

用于细节增强的质量等级。

参数[VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#video_detail_enhancer_parameter_key_quality_level)的具体取值，设置方法详见开发指南。

**参见：**[OH_VideoProcessing_SetParameter](#oh_videoprocessing_setparameter)、[OH_VideoProcessing_GetParameter](#oh_videoprocessing_getparameter)

**起始版本：** 12


### VideoProcessing_Callback

```
typedef struct VideoProcessing_CallbackVideoProcessing_Callback
```

**描述**

视频处理回调对象类型。

定义一个VideoProcessing_Callback空指针，调用[OH_VideoProcessingCallback_Create](#oh_videoprocessingcallback_create)来创建一个回调对象。创建之前该指针必须为空。 通过调用[OH_VideoProcessing_RegisterCallback](#oh_videoprocessing_registercallback)来向视频处理实例注册回调对象。

**起始版本：** 12


### VideoProcessing_ColorSpaceInfo

```
typedef struct VideoProcessing_ColorSpaceInfoVideoProcessing_ColorSpaceInfo
```

**描述**

视频颜色空间信息数据结构。

**参见：**[OH_VideoProcessing_IsColorSpaceConversionSupported](#oh_videoprocessing_iscolorspaceconversionsupported)

**起始版本：** 12


### VideoProcessing_ErrorCode

```
typedef enum VideoProcessing_ErrorCodeVideoProcessing_ErrorCode
```

**描述**

视频处理错误码。

**起始版本：** 12


### VideoProcessing_State

```
typedef enum VideoProcessing_StateVideoProcessing_State
```

**描述**

视频处理状态。

视频处理状态通过回调函数[OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)进行报告。

**起始版本：** 12


## 枚举类型说明


### VideoDetailEnhancer_QualityLevel

```
enum VideoDetailEnhancer_QualityLevel
```

**描述**

用于细节增强的质量等级。

参数[VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#video_detail_enhancer_parameter_key_quality_level)的具体取值，设置方法详见开发指南。

**参见：**[OH_VideoProcessing_SetParameter](#oh_videoprocessing_setparameter)、[OH_VideoProcessing_GetParameter](#oh_videoprocessing_getparameter)

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_NONE | 无细节增强。 | 
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_LOW | 低质量等级细节增强，速度较快，默认设置。 | 
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM | 中等质量等级细节增强，速度适中。 | 
| VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH | 高质量等级细节增强，速度相对较慢。 | 


### VideoProcessing_ErrorCode

```
enum VideoProcessing_ErrorCode
```

**描述**

视频处理错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| VIDEO_PROCESSING_SUCCESS | 处理成功。 | 
| VIDEO_PROCESSING_ERROR_INVALID_PARAMETER | 输入参数无效。以下情况都会返回该错误码：<br/>1 - 无效的输入或输出视频buffer，视频buffer为空。<br/>2 - 无效的参数，参数为空。<br/>3 - 无效的处理类型。 | 
| VIDEO_PROCESSING_ERROR_UNKNOWN | 未知错误，比如GPU计算失败或memcpy失败。 | 
| VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED | 视频处理全局环境初始化失败，比如初始化GPU环境失败。 | 
| VIDEO_PROCESSING_ERROR_CREATE_FAILED | 创建视频处理实例失败，比如实例总数超出上限。 | 
| VIDEO_PROCESSING_ERROR_PROCESS_FAILED | 处理过程失败，比如处理时间超时。 | 
| VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING | 不支持的处理类型，可以调用 OH_VideoProcessing_IsXXXSupported来检查是否支持这种处理。 | 
| VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED | 不允许的操作，比如不满足调用接口所需的运行状态下调用该接口。 | 
| VIDEO_PROCESSING_ERROR_NO_MEMORY | 内存不足。 | 
| VIDEO_PROCESSING_ERROR_INVALID_INSTANCE | 视频处理实例无效，比如视频处理实例为空实例。 | 
| VIDEO_PROCESSING_ERROR_INVALID_VALUE | 输入值无效，以下情况都会造成这种错误：<br/>1 - 视频buffer宽高太大或者颜色空间错误。<br/>2 - 参数包含无效的值，比如细节增强的质量等级错误。 | 


### VideoProcessing_State

```
enum VideoProcessing_State
```

**描述**

视频处理状态。

视频处理状态通过回调函数[OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)进行报告。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| VIDEO_PROCESSING_STATE_RUNNING | 视频处理进行中。 | 
| VIDEO_PROCESSING_STATE_STOPPED | 视频处理已停止。 | 


## 函数说明


### OH_VideoProcessing_Create()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Create (OH_VideoProcessing ** videoProcessor, int type )
```

**描述**

创建视频处理实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 输出参数。指向视频处理对象的指针的指针。 输入前\*videoProcessor必须是空指针。 | 
| type | 使用VIDEO_PROCESSING_TYPE_XXX来指定处理类型。实例的处理类型不能改变。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果视频处理实例创建成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果处理类型不支持，返回VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING，
  例如，如果不支持元数据生成就返回VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。

- 如果创建视频处理实例失败，返回VIDEO_PROCESSING_ERROR_CREATE_FAILED。

- 如果实例为空或实例的指针非空，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果处理类型无效，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。


### OH_VideoProcessing_DeinitializeEnvironment()

```
VideoProcessing_ErrorCode OH_VideoProcessing_DeinitializeEnvironment (void )
```

**描述**

释放视频处理全局环境。

调用前，必须调用[OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment)初始化。 通常在主进程即将退出时调用该函数来释放通过调用[OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment)函数初始化的全局环境。 如果仍有视频处理的实例运行中，就不能调用该函数。

**起始版本：** 12

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果还有视频处理的实例没有销毁或者没有调用[OH_VideoProcessing_InitializeEnvironment](#oh_videoprocessing_initializeenvironment)，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。


### OH_VideoProcessing_Destroy()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Destroy (OH_VideoProcessing * videoProcessor)
```

**描述**

销毁视频处理实例。

销毁之前先停止实例，参阅[OH_VideoProcessing_Stop](#oh_videoprocessing_stop)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针，建议在实例销毁之后将其设置为空指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果实例销毁成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果实例仍在运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。


### OH_VideoProcessing_GetParameter()

```
VideoProcessing_ErrorCode OH_VideoProcessing_GetParameter (OH_VideoProcessing * videoProcessor, OH_AVFormat * parameter )
```

**描述**

获取视频处理参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针。 | 
| parameter | 指向视频处理参数实例的指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果参数获取成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果参数为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。


### OH_VideoProcessing_GetSurface()

```
VideoProcessing_ErrorCode OH_VideoProcessing_GetSurface (OH_VideoProcessing * videoProcessor, OHNativeWindow ** window )
```

**描述**

创建surface。

在视频处理启动之前创建输入surface。调用[OH_NativeWindow_DestroyNativeWindow](../apis-arkgraphics2d/_native_window.md#oh_nativewindow_destroynativewindow)销毁输入surface。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针。 | 
| window | 指向输入surface的指针。例如，此输入surface指针可以指向视频解码器输出surface。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果window为空指针或指向window的指针不为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。

- 如果创建surface失败，或者输入surface已经创建，或者视频处理实例还在运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。


### OH_VideoProcessing_InitializeEnvironment()

```
VideoProcessing_ErrorCode OH_VideoProcessing_InitializeEnvironment (void )
```

**描述**

初始化视频处理全局环境。

该函数是可选的。 该函数只在主进程启动时被调用一次，用于初始化视频处理全局环境，这样可以减少[OH_VideoProcessing_Create](#oh_videoprocessing_create)的时间。 调用[OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment)释放视频处理全局环境。 初始化后，必须释放视频处理全局环境，释放方式及时机详见[OH_VideoProcessing_DeinitializeEnvironment](#oh_videoprocessing_deinitializeenvironment)。

**起始版本：** 12

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

如果初始化成功，返回VIDEO_PROCESSING_SUCCESS，否则返回VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED。

如果失败，应用需要检查GPU是否正常工作。


### OH_VideoProcessing_IsColorSpaceConversionSupported()

```
bool OH_VideoProcessing_IsColorSpaceConversionSupported (const VideoProcessing_ColorSpaceInfo * sourceVideoInfo, const VideoProcessing_ColorSpaceInfo * destinationVideoInfo )
```

**描述**

查询是否支持视频颜色空间转换。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sourceVideoInfo | 输入视频颜色空间信息。 | 
| destinationVideoInfo | 输出视频颜色空间信息。 | 

**返回：**

如果支持视频颜色空间转换返回**true**，否则返回**false**。


### OH_VideoProcessing_IsMetadataGenerationSupported()

```
bool OH_VideoProcessing_IsMetadataGenerationSupported (const VideoProcessing_ColorSpaceInfo * sourceVideoInfo)
```

**描述**

查询是否支持视频元数据生成。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sourceVideoInfo | 输入视频颜色空间信息。 | 

**返回：**

如果支持视频元数据生成返回**true**，否则返回**false**。


### OH_VideoProcessing_RegisterCallback()

```
VideoProcessing_ErrorCode OH_VideoProcessing_RegisterCallback (OH_VideoProcessing * videoProcessor, const VideoProcessing_Callback * callback, void * userData )
```

**描述**

注册回调函数。

在开始视频处理之前注册回调函数，视频处理过程中无法注册回调函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针。 | 
| callback | 回调函数指针。 | 
| userData | 指向用户特定数据的指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果回调函数注册成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果回调函数指针为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。

- 如果实例仍在运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。


### OH_VideoProcessing_RenderOutputBuffer()

```
VideoProcessing_ErrorCode OH_VideoProcessing_RenderOutputBuffer (OH_VideoProcessing * videoProcessor, uint32_t index )
```

**描述**

渲染处理并输出buffer。

如果设置了回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer)，当输出buffer准备好之后会通过回调函数把buffer的索引返回给用户。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针。 | 
| index | 输出buffer的索引。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果索引值无效，输出VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。

- 如果没有设置回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer)或者实例已经停止运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。


### OH_VideoProcessing_SetParameter()

```
VideoProcessing_ErrorCode OH_VideoProcessing_SetParameter (OH_VideoProcessing * videoProcessor, const OH_AVFormat * parameter )
```

**描述**

设置视频处理输出参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针。 | 
| parameter | 指向视频处理参数实例的指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果参数设置成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果参数为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。

- 如果参数的某些属性无效，返回VIDEO_PROCESSING_ERROR_INVALID_VALUE，例如，包含不支持的参数值。

- 如果内存分配失败，返回VIDEO_PROCESSING_ERROR_NO_MEMORY。


### OH_VideoProcessing_SetSurface()

```
VideoProcessing_ErrorCode OH_VideoProcessing_SetSurface (OH_VideoProcessing * videoProcessor, const OHNativeWindow * window )
```

**描述**

设置视频处理输出surface。

在视频处理启动之前设置输出surface。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针。 | 
| window | 指向输出surface的指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果输出surface设置成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果window为空指针，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。


### OH_VideoProcessing_Start()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Start (OH_VideoProcessing * videoProcessor)
```

**描述**

启动视频处理。

成功启动后，回调函数[OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)会报告VIDEO_PROCESSING_STATE_RUNNING状态，状态说明参阅[VideoProcessing_State](#videoprocessing_state)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果没有设置输出surface，或者没有创建输入surface，或者实例已经运行，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。


### OH_VideoProcessing_Stop()

```
VideoProcessing_ErrorCode OH_VideoProcessing_Stop (OH_VideoProcessing * videoProcessor)
```

**描述**

停止视频处理。

成功停止后，回调函数[OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)会报告VIDEO_PROCESSING_STATE_STOPPED状态，状态说明参阅[VideoProcessing_State](#videoprocessing_state)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoProcessor | 指向视频处理实例的指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果执行成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果实例为空或者不是一个视频处理实例，返回VIDEO_PROCESSING_ERROR_INVALID_INSTANCE。

- 如果实例已经停止，返回VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。


### OH_VideoProcessingCallback_BindOnError()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnError (VideoProcessing_Callback * callback, OH_VideoProcessingCallback_OnError onError )
```

**描述**

绑定回调函数[OH_VideoProcessingCallback_OnError](#oh_videoprocessingcallback_onerror)到回调对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 指向回调对象的指针。 | 
| onError | 回调函数。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果函数绑定成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果callback为空或者onError为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。


### OH_VideoProcessingCallback_BindOnNewOutputBuffer()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnNewOutputBuffer (VideoProcessing_Callback * callback, OH_VideoProcessingCallback_OnNewOutputBuffer onNewOutputBuffer )
```

**描述**

绑定回调函数[OH_VideoProcessingCallback_OnNewOutputBuffer](#oh_videoprocessingcallback_onnewoutputbuffer)到回调对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 指向回调对象的指针。 | 
| onNewOutputBuffer | 回调函数。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果函数绑定成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果callback为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。


### OH_VideoProcessingCallback_BindOnState()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_BindOnState (VideoProcessing_Callback * callback, OH_VideoProcessingCallback_OnState onState )
```

**描述**

绑定回调函数[OH_VideoProcessingCallback_OnState](#oh_videoprocessingcallback_onstate)到回调对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 指向回调对象的指针。 | 
| onState | 回调函数。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果函数绑定成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果callback为空或者onState为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。


### OH_VideoProcessingCallback_Create()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Create (VideoProcessing_Callback ** callback)
```

**描述**

创建视频处理回调函数对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 输出参数。\*callback是指向回调函数对象的指针。在创建回调函数对象之前\*callback必须为空指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果回调函数对象创建成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果callback为空或者\*callback不为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。

- 如果内存不足，返回VIDEO_PROCESSING_ERROR_NO_MEMORY。


### OH_VideoProcessingCallback_Destroy()

```
VideoProcessing_ErrorCode OH_VideoProcessingCallback_Destroy (VideoProcessing_Callback * callback)
```

**描述**

销毁回调对象。

回调对象在注册之后就可以销毁。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 指向回调对象的指针，建议在回调对象销毁之后将其设置为空指针。 | 

**返回：**

视频处理错误码[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1)：

- 如果回调对象销毁成功，返回VIDEO_PROCESSING_SUCCESS。

- 如果callback为空，返回VIDEO_PROCESSING_ERROR_INVALID_PARAMETER。


## 变量说明


### VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL

```
const char* VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL
```

**描述**

指定视频细节增强的质量等级。

参阅 [VideoDetailEnhancer_QualityLevel](#videodetailenhancer_qualitylevel)查看具体取值。 调用 [OH_VideoProcessing_SetParameter](#oh_videoprocessing_setparameter)设置质量等级。 调用 [OH_VideoProcessing_GetParameter](#oh_videoprocessing_getparameter)获取当前质量等级。

**起始版本：** 12


### VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION

```
const int32_t VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION
```

**描述**

表示创建颜色空间转换视频处理实例。

调用[OH_VideoProcessing_Create](#oh_videoprocessing_create)创建颜色空间转换视频处理实例，如果不支持该能力返回[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。

**起始版本：** 12


### VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER

```
const int32_t VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER
```

**描述**

表示创建细节增强视频处理实例。

调用[OH_VideoProcessing_Create](#oh_videoprocessing_create)创建细节增强视频处理实例，如果不支持该能力返回[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。

**起始版本：** 12


### VIDEO_PROCESSING_TYPE_METADATA_GENERATION

```
const int32_t VIDEO_PROCESSING_TYPE_METADATA_GENERATION
```

**描述**

表示创建元数据生成视频处理实例。

调用[OH_VideoProcessing_Create](#oh_videoprocessing_create)创建元数据生成视频处理实例，如果不支持该能力返回[VideoProcessing_ErrorCode](#videoprocessing_errorcode-1) VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。

**起始版本：** 12
