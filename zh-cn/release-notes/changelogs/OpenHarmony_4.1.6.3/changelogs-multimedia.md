# multimedia子系统变更说明

## cl.multimedia.1 Core模块接口废弃

**访问级别**

公开接口

**变更原因**

媒体数据结构AVMemory废弃，支持AVBuffer。

**变更影响**

该变更为兼容性变更，需要开发者进行适配。


**API Level**

|         接口声明         |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AVMemory_Create | 10 |
| OH_AVMemory_GetAddr | 9 |
| OH_AVMemory_GetSize  | 9 |
| OH_AVMemory_Destroy  | 10 |

**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

|         接口声明         |          废弃说明                | 替代接口                      |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AVMemory_Create | AVMemory实例创建接口废弃，支持AVBuffer |OH_AVBuffer_Create|
| OH_AVMemory_GetAddr | 获取内存虚拟地址接口废弃，支持AVBuffer |OH_AVBuffer_GetAddr|
| OH_AVMemory_GetSize  | 获取内存长度接口废弃，支持AVBuffer |OH_AVBuffer_GetCapacity |
| OH_AVMemory_Destroy  | 销毁AVMemory实例接口废弃，支持AVBuffer |OH_AVBuffer_Destroy |


**适配指导**

变更前：

在媒体编解码/封装/解封装等功能实现时，使用AVMemory相应的创建/获取内存地址/内存长度/销毁接口操作数据内存

变更后：

在媒体编解码/封装/解封装等功能实现时，使用AVBuffer相应的创建/获取内存地址/内存长度/销毁接口操作数据内存

## cl.multimedia.2 CodecBase模块接口废弃

**访问级别**

公开接口

**变更原因**

接口数据流转废弃AVMemory，支持AVBuffer，删除不支持的规格。

**变更影响**

该变更为兼容性变更，需要开发者进行适配。

**API Level**

|         接口声明         |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AVCodecOnNeedInputData | 9 |
| OH_AVCodecOnNewOutputData | 9 |
| OH_AVCodecAsyncCallback  | 9 |
| const char *OH_AVCODEC_MIMETYPE_VIDEO_MPEG4  | 10 |
| AudioChannelSet | 10 |
| AudioChanelLayout | 10 |

**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

|         接口声明         |          废弃说明                | 替代接口                      |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AVCodecOnNeedInputData | 编解码输入数据回调由AVMemory增强为AVBuffer |OH_AVCodecOnNeedInputBuffer|
| OH_AVCodecOnNewOutputData | 编解码输出数据回调由AVMemory增强为AVBuffer |OH_AVCodecOnNewOutputBuffer|
| OH_AVCodecAsyncCallback  | 注册回调函数指针集合，由AVMemory增强为AVBuffer |OH_AVCodecCallback |
| const char *OH_AVCODEC_MIMETYPE_VIDEO_MPEG4  | 封装不支持该规格 |无 |
| AudioChannelSet | 接口变更 | OH_AudioChannelSet |
| AudioChanelLayout | 接口变更 | OH_AudioChannelLayout |

**适配指导**

变更前：

音视频编解码器，注册回调函数指针集合OH_AVCodecAsyncCallback，其中：

编解码输入回调实现OH_AVCodecOnNeedInputData

编解码输出回调实现OH_AVCodecOnNewOutputData

封装格式指定为OH_AVCODEC_MIMETYPE_VIDEO_MPEG4进行封装

使用 AudioChannelSet 枚举定义音频声道设置

使用 AudioChanelLayout 枚举定义音频声道布局

变更后：

音视频编解码器，注册回调函数指针集合OH_AVCodecCallback，其中：

编解码输入回调实现OH_AVCodecOnNeedInputBuffer

编解码输出回调实现OH_AVCodecOnNewOutputBuffer

封装格式不支持OH_AVCODEC_MIMETYPE_VIDEO_MPEG4

使用 OH_AudioChannelSet 枚举定义音频声道设置

使用 OH_AudioChannelLayout 枚举定义音频声道布局

## cl.multimedia.3 VideoDecoder模块接口废弃

**访问级别**

公开接口

**变更原因**

接口数据流转废弃AVMemory，支持AVBuffer

**变更影响**

该变更为兼容性变更，需要开发者进行适配。

**API Level**

|         接口声明         |          API Level                |
| ----------------------- | :--------------------------------|
| OH_VideoDecoder_SetCallback | 9 |
| OH_VideoDecoder_PushInputData | 9 |
| OH_VideoDecoder_RenderOutputData  | 9 |
| OH_VideoDecoder_FreeOutputData  | 9 |

**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

|         接口声明         |          废弃说明                | 替代接口                      |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_VideoDecoder_SetCallback | 回调注册函数支持数据结构AVBuffer |OH_VideoDecoder_RegisterCallback|
| OH_VideoDecoder_PushInputData | 解码输入码流数据结构支持AVBuffer |OH_VideoDecoder_PushInputBuffer|
| OH_VideoDecoder_RenderOutputData  | 解码输出渲染控制支持AVBuffer |OH_VideoDecoder_RenderOutputBuffer |
| OH_VideoDecoder_FreeOutputData  | 解码输出释放控制支持AVBuffer |OH_VideoDecoder_FreeOutputBuffer |

**适配指导**

变更前：

调用OH_VideoDecoder_SetCallback()设置回调函数

当收到输入回调通知，调用OH_VideoDecoder_PushInputData填入码流数据

当收到输出回调通知，调用OH_VideoDecoder_FreeOutputData释放输出图像或调用OH_VideoDecoder_RenderOutputData渲染图像

变更后：

调用OH_VideoDecoder_RegisterCallback()设置回调函数

当收到输入回调通知，调用OH_VideoDecoder_PushInputBuffer填入码流数据

当收到输出回调通知，调用OH_VideoDecoder_FreeOutputBuffer释放输出图像或调用OH_VideoDecoder_RenderOutputBuffer渲染图像


## cl.multimedia.4 VideoEncoder模块接口废弃

**访问级别**

公开接口

**变更原因**

接口数据流转废弃AVMemory，支持AVBuffer

**变更影响**

该变更为兼容性变更，需要开发者进行适配。

**API Level**

|         接口声明         |          API Level                |
| ----------------------- | :--------------------------------|
| OH_VideoEncoder_SetCallback | 9 |
| OH_VideoEncoder_PushInputData | 9 |
| OH_VideoEncoder_FreeOutputData  | 9 |

**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

|         接口声明         |          废弃说明                | 替代接口                      |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_VideoEncoder_SetCallback | 回调注册函数支持数据结构AVBuffer |OH_VideoEncoder_RegisterCallback|
| OH_VideoEncoder_PushInputData | 解码输入码流数据结构支持AVBuffer |OH_VideoEncoder_PushInputBuffer|
| OH_VideoEncoder_FreeOutputData  | 解码输出释放控制支持AVBuffer |OH_VideoEncoder_FreeOutputBuffer |

**适配指导**

变更前：

调用OH_VideoEncoder_SetCallback()设置回调函数

当收到输入回调通知，调用OH_VideoEncoder_PushInputData填入待编码数据

当收到输出回调通知，调用OH_VideoEncoder_FreeOutputData释放输出数据

变更后：

调用OH_VideoEncoder_RegisterCallback()设置回调函数

当收到输入回调通知，调用OH_VideoEncoder_PushInputBuffer填入待编码数据

当收到输出回调通知，调用OH_VideoEncoder_FreeOutputBuffer释放输出数据


## cl.multimedia.5 AVDemuxer模块接口废弃

**访问级别**

公开接口

**变更原因**

接口数据流转废弃AVMemory，支持AVBuffer

**变更影响**

该变更为兼容性变更，需要开发者进行适配。

**API Level**

|         接口声明         |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AVDemuxer_ReadSample | 10 |

**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

|         接口声明         |          废弃说明                | 替代接口                      |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AVDemuxer_ReadSample | 解封装获取帧函数支持数据结构AVBuffer |OH_AVDemuxer_ReadSampleBuffer|

**适配指导**

变更前：

调用OH_AVDemuxer_ReadSample()获取压缩帧及相关信息

变更后：

调用OH_AVDemuxer_ReadSampleBuffer()获取压缩帧及相关信息

## cl.multimedia.6 AVMuxer模块接口废弃

**访问级别**

公开接口

**变更原因**

接口数据流转废弃AVMemory，支持AVBuffer

**变更影响**

该变更为兼容性变更，需要开发者进行适配。

**API Level**

|         接口声明         |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AVMuxer_WriteSample | 10 |

**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

|         接口声明         |          废弃说明                | 替代接口                      |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AVMuxer_WriteSample | 封装写入帧函数支持数据结构AVBuffer |OH_AVMuxer_WriteSampleBuffer|

**适配指导**

变更前：

调用OH_AVMuxer_WriteSample()写入压缩帧及相关信息

变更后：

调用OH_AVMuxer_WriteSampleBuffer()写入压缩帧及相关信息

## cl.multimedia.7 AudioDecoder模块接口废弃

**访问级别**

公开接口

**变更原因**

接口数据流转废弃AVMemory，支持AVBuffer，原音频解码模块变更为音频编解码模块。

**变更影响**

该变更为兼容性变更，需要开发者进行适配。

**API Level**

|         接口声明         |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AudioDecoder_CreateByName | 9 |
| OH_AudioDecoder_CreateByMime | 9 |
| OH_AudioDecoder_SetCallback | 9 |
| OH_AudioDecoder_Configure | 9 |
| OH_AudioDecoder_Prepare | 9 |
| OH_AudioDecoder_Start | 9 |
| OH_AudioDecoder_PushInputData | 9 |
| OH_AudioDecoder_FreeOutputData | 9 |
| OH_AudioDecoder_Flush | 9 |
| OH_AudioDecoder_IsValid | 10 |
| OH_AudioDecoder_Reset | 9 |
| OH_AudioDecoder_Stop | 9 |
| OH_AudioDecoder_Destroy | 9 |


**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

|         接口声明         |          废弃说明                | 替代接口                      |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AudioDecoder_CreateByName | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_CreateByName |
| OH_AudioDecoder_CreateByMime | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_CreateByMime |
| OH_AudioDecoder_SetCallback | 原音频解码模块变更为音频编解码模块，回调注册函数支持数据结构AVBuffer | OH_AudioCodec_RegisterCallback |
| OH_AudioDecoder_Configure | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_Configure |
| OH_AudioDecoder_Prepare | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_Prepare |
| OH_AudioDecoder_Start | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_Start |
| OH_AudioDecoder_PushInputData | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_PushInputBuffer |
| OH_AudioDecoder_FreeOutputData | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_FreeOutputBuffer |
| OH_AudioDecoder_Flush | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_Flush |
| OH_AudioDecoder_IsValid | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_IsValid |
| OH_AudioDecoder_Reset | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_Reset |
| OH_AudioDecoder_Stop | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_Stop |
| OH_AudioDecoder_Destroy | 原音频解码模块变更为音频编解码模块 | OH_AudioCodec_Destroy |

**适配指导**

变更前：

调用OH_AudioDecoder_CreateByName()或OH_AudioDecoder_CreateByMime()，创建解码器。

调用OH_AudioDecoder_SetCallback()，设置回调函数。

调用OH_AudioDecoder_Configure()，配置解码器。

调用OH_AudioDecoder_Prepare()，解码器就绪。

调用OH_AudioDecoder_Start()，启动解码器，进入运行态。

调用OH_AudioDecoder_PushInputData()，写入待解码的数据。

调用OH_AudioDecoder_FreeOutputData()，输出解码后的PCM码流。

（可选）调用OH_AudioDecoder_Flush()，刷新解码器。

（可选）调用OH_AudioDecoder_IsValid()，可以判断在执行过程中是否可以继续执行。

（可选）调用OH_AudioDecoder_Reset()，重置解码器。

调用OH_AudioDecoder_Stop()，停止解码器。

调用OH_AudioDecoder_Destroy()，销毁解码器实例，释放资源。

变更后：

调用OH_AudioCodec_CreateByName()或OH_AudioCodec_CreateByMime，创建编解码器。

调用OH_AudioCodec_SetCallback()，设置回调函数。

调用OH_AudioCodec_Configure()，配置编解码器。

调用OH_AudioCodec_Prepare()，编解码器就绪。

调用OH_AudioCodec_Start()，启动编解码器，进入运行态。

调用OH_AudioCodec_PushInputData()，写入待编解码的数据。

调用OH_AudioCodec_FreeOutputData()，输出编解码格式码流。

（可选）调用OH_AudioCodec_Flush()，刷新编解码器。

（可选）调用OH_AudioCodec_IsValid()，可以判断在执行过程中是否可以继续执行。

（可选）调用OH_AudioCodec_Reset()，重置编解码器。

调用OH_AudioCodec_Stop()，停止编解码器。

调用OH_AudioCodec_Destroy()，销毁编解码器实例，释放资源。

## cl.multimedia.8 AudioEncoder模块接口废弃

**访问级别**

公开接口

**变更原因**

接口数据流转废弃AVMemory，支持AVBuffer，原音频编码模块变更为音频编解码模块。

**变更影响**

该变更为兼容性变更，需要开发者进行适配。

**API Level**

|         接口声明         |          API Level                |
| ----------------------- | :--------------------------------|
| OH_AudioEncoder_CreateByName | 9 |
| OH_AudioEncoder_CreateByMime | 9 |
| OH_AudioEncoder_SetCallback | 9 |
| OH_AudioEncoder_Configure | 9 |
| OH_AudioEncoder_Prepare | 9 |
| OH_AudioEncoder_Start | 9 |
| OH_AudioEncoder_PushInputData | 9 |
| OH_AudioEncoder_FreeOutputData | 9 |
| OH_AudioEncoder_Flush | 9 |
| OH_AudioEncoder_IsValid | 10 |
| OH_AudioEncoder_Reset | 9 |
| OH_AudioEncoder_Stop | 9 |
| OH_AudioEncoder_Destroy | 9 |


**变更发生版本**

从OpenHarmony SDK 4.1.6.3 开始。

**变更的接口/组件**

|         接口声明         |          废弃说明                | 替代接口                      |
| ----------------------- | :--------------------------------| :----------------------------|
| OH_AudioEncoder_CreateByName | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_CreateByName |
| OH_AudioEncoder_CreateByMime | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_CreateByMime |
| OH_AudioEncoder_SetCallback | 原音频编码模块变更为音频编解码模块，回调注册函数支持数据结构AVBuffer | OH_AudioCodec_RegisterCallback |
| OH_AudioEncoder_Configure | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_Configure |
| OH_AudioEncoder_Prepare | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_Prepare |
| OH_AudioEncoder_Start | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_Start |
| OH_AudioEncoder_PushInputData | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_PushInputBuffer |
| OH_AudioEncoder_FreeOutputData | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_FreeOutputBuffer |
| OH_AudioEncoder_Flush | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_Flush |
| OH_AudioEncoder_IsValid | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_IsValid |
| OH_AudioEncoder_Reset | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_Reset |
| OH_AudioEncoder_Stop | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_Stop |
| OH_AudioEncoder_Destroy | 原音频编码模块变更为音频编解码模块 | OH_AudioCodec_Destroy |

**适配指导**

变更前：

调用OH_AudioEncoder_CreateByName()或OH_AudioEncoder_CreateByMime，创建编码器。

调用OH_AudioEncoder_SetCallback()，设置回调函数。

调用OH_AudioEncoder_Configure()，配置编码器。

调用OH_AudioEncoder_Prepare()，编码器就绪。

调用OH_AudioEncoder_Start()，启动编码器，进入运行态。

调用OH_AudioEncoder_PushInputData()，写入待编码的数据。

调用OH_AudioEncoder_FreeOutputData()，输出编码格式码流。

（可选）调用OH_AudioEncoder_Flush()，刷新编码器。

（可选）调用OH_AudioEncoder_IsValid()，可以判断在执行过程中是否可以继续执行。

（可选）调用OH_AudioEncoder_Reset()，重置编码器。

调用OH_AudioEncoder_Stop()，停止编码器。

调用OH_AudioEncoder_Destroy() 销毁编码器实例，释放资源。

变更后：

调用OH_AudioCodec_CreateByName() 或 OH_AudioCodec_CreateByMime，创建编解码器。

调用OH_AudioCodec_SetCallback()，设置回调函数。

调用OH_AudioCodec_Configure()，配置编解码器。

调用OH_AudioCodec_Prepare()，编解码器就绪。

调用OH_AudioCodec_Start()，启动编解码器，进入运行态。

调用OH_AudioCodec_PushInputData()，写入待编解码的数据。

调用OH_AudioCodec_FreeOutputData()，输出编解码格式码流。

（可选）调用OH_AudioCodec_Flush()，刷新编解码器。

（可选）调用OH_AudioCodec_IsValid()，可以判断在执行过程中是否可以继续执行。

（可选）调用OH_AudioCodec_Reset()，重置编解码器。

调用OH_AudioCodec_Stop()，停止编解码器。

调用OH_AudioCodec_Destroy()，销毁编解码器实例，释放资源。

## cl.multimedia.9 AVPlayer/AVRecorder支持的格式规格变更

**访问级别**

公开接口

**变更原因**

使用AVCodec进行解封装、编解码。

**变更影响**

不支持以下格式：
解封装格式：WebM
视频解码：H.263, MPEG2, MPEG4, VP8
视频编码：MPEG4

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3开始。

**变更的接口/组件**
AVPlayer组件，AVRecorder组件

**适配指导**
1. 视频编码使用 AVC 代替MPEG4。
2. 音视频播放资源涉及封装格式 WebM，或视频解码格式 H.263/MPEG2/MPEG4/VP8，会播放失败，尽量使用封装格式 MP4，视频解码格式 AVC 的资源代替。