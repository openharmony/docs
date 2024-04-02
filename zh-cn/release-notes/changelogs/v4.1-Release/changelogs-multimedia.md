# 媒体变更说明

## cl.multimedia.1 ohos.multimedia.audio AudioRenderer接口setRenderRate/getRenderRate废弃

**访问级别**

公开接口

**废弃原因**

被功能更全面的新接口SetSpeed/GetSpeed替代，故废弃原接口

**废弃影响**

非兼容性变更，需要开发者进行适配。

**API Level**

setRenderRate(): 8

getRenderRate(): 8

getRenderRateSync(): 10

**废弃发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**废弃的接口**

接口属于AudioRenderer

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback<void>): void;

setRenderRate(rate: AudioRendererRate): Promise<void>;

getRenderRate(callback: AsyncCallback<AudioRendererRate>): void;

getRenderRate(): Promise<AudioRendererRate>;

getRenderRateSync(): AudioRendererRate;

**适配指导**

根据废弃接口提示，使用AudioRenderer内的新接口即可，新接口支持通过浮点数调节播放速度，而非固定倍数。

setSpeed(speed: number): void;

getSpeed(): number;

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划。

## cl.multimedia.2 Core模块接口废弃

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

## cl.multimedia.3 CodecBase模块接口废弃

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

## cl.multimedia.4 VideoDecoder模块接口废弃

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


## cl.multimedia.5 VideoEncoder模块接口废弃

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


## cl.multimedia.6 AVDemuxer模块接口废弃

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

## cl.multimedia.7 AVMuxer模块接口废弃

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

## cl.multimedia.8 AudioDecoder模块接口废弃

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

## cl.multimedia.9 AudioEncoder模块接口废弃

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

## cl.multimedia.10 AVPlayer/AVRecorder支持的格式规格变更

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

## c1.multimedia.11 ohos.multimedia.audio AudioManager接口setAudioParameter/getAudioParameter废弃

**访问级别**

公开接口

**废弃原因**

不再开放三方应用与音频芯片通过定制参数直接修改配置的通道，收归系统内部管控，通用功能由专有接口替代

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**废弃的接口**

接口属于AudioManager

setAudioParameter(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void;

setAudioParameter(key: string, value: string): Promise&lt;void&gt;;

getAudioParameter(key: string, callback: AsyncCallback&lt;string&gt;): void;

getAudioParameter(key: string): Promise&lt;string&gt;;

**适配指导**

对于系统应用，根据废弃接口提示，使用替代接口：

setExtraParameters(mainKey: string, kvpairs: Record&lt;string, string&gt;): Promise&lt;void&gt;;

getExtraParameters(mainKey: string, subKeys?: Array&lt;string&gt;): Promise&lt;Record&lt;string, string&gt;&gt;;

mainKey与原接口参数key保持一致，kvpairs是原有value字符串内多个key-value配对的拆分写法。

对于三方应用，本接口提供的功能本身不对三方开放，请按需使用系统在AudioManager模块中提供的公开音频管理接口。

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划。

## c1.multimedia.12 ohos.multimedia.audio AudioVolumeGroupManager接口setMicrophoneMute废弃

**访问级别**

公开接口

**废弃原因**

虽然本接口是公开接口，但使用本接口需要获取权限ohos.permission.MANAGE_AUDIO_CONFIG。
本权限未开放给三方应用申请，因此三方应用实际无法使用本接口提供的能力。根据SDK规范，进行废弃，调整为系统接口，不对外可见。

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**废弃的接口**

接口属于AudioVolumeGroupManager

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void;

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;;

**适配指导**

系统应用，根据废弃接口提示，使用替代接口，功能完全一致：

setMicMute(mute: boolean): Promise&lt;void&gt;;

三方应用，由于原本就无法获取ohos.permission.MANAGE_AUDIO_CONFIG权限授权，原接口处于无效状态，因此对三方应用无实际影响。

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划。

## c1.multimedia.13 ohos.multimedia.audio CaptureFilterOptions属性usages行为变更

**访问级别**

公开接口

**变更原因**

本属性用于在音频内录功能中，对录制的音频usage进行筛选，当筛选STREAM_USAGE_VOICE_COMMUNICATION作为录制目标时，
应用需要具备ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO权限。
但这个权限并不对三方应用开放授权，按照SDK规范，需要将权限剥离出公开接口。

**变更影响**

非兼容性变更，需要开发者进行适配。

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

变更前：
```
/**
 * Filter by stream usages. If you want to capture voice streams, additional permission is needed.
 * @permission ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO
 * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
 * @since 10
 */
 ```
接口允许调用者筛选STREAM_USAGE_VOICE_COMMUNICATION作为录制目标，但需要获取ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO权限。

变更后：
```
/**
 * Filter by stream usages. But not allow to capture voice streams.
 * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
 * @since 11
 */
 ```
接口不再允许调用者筛选STREAM_USAGE_VOICE_COMMUNICATION作为录制目标，权限声明删除。当无权限，但选择STREAM_USAGE_VOICE_COMMUNICATION作为录制目标时，无法创建AudioCapturer对象，返回ERROR_SYSTEM错误。

**适配指导**

三方应用，由于本身无法获取权限授权，此变更无任何影响，无需适配

系统应用，即使拥有ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO权限，也不再能够筛选STREAM_USAGE_VOICE_COMMUNICATION作为录制目标，需将此类型从筛选中删除。

## c1.multimedia.14 ohos.multimedia.audio AudioManager订阅事件interrupt接口废弃

**访问级别**

公开接口

**废弃原因**

SDK10时OpenHarmony已全面使用内置焦点模式，见开发指南中的[多音频播放的并发策略](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/media/audio-playback-concurrency.md)
本接口为历史遗留的外置焦点接口，与内置焦点独立，已经无法起到焦点抢占的作用，因此废弃，避免误导开发者。

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**废弃的接口**

接口属于AudioManager

on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback&lt;InterruptAction&gt;): void;

off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback&lt;InterruptAction&gt;): void;

**适配指导**

根据内置焦点模式实现多音频并发策略控制，参考[多音频播放的并发策略](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/media/audio-playback-concurrency.md)

## c1.multimedia.15 ohos.multimedia.audio AudioRenderer接口write/AudioCapturer接口read废弃

**访问级别**

公开接口

**废弃原因**

AudioRenderer/AudioCapturer新增了writeData, readData订阅接口，通过回调请求方式，省去开发者自行管理数据处理时机的工作。
并通过让系统管理数据请求时机，避免出现数据轮转时机不准确导致的underrun/overrun问题。

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**废弃的接口**

接口属于AudioRenderer

write(buffer: ArrayBuffer, callback: AsyncCallback&lt;number&gt;): void;

write(buffer: ArrayBuffer): Promise&lt;number&gt;;

接口属于AudioCapturer

read(size: number, isBlockingRead: boolean, callback: AsyncCallback&lt;ArrayBuffer&gt;): void;

read(size: number, isBlockingRead: boolean): Promise&lt;ArrayBuffer&gt;;

**适配指导**

根据废弃接口提示，使用新接口即可。

AudioRenderer新接口：

on(type: 'writeData', callback: Callback&lt;ArrayBuffer&gt;): void;

off(type: 'writeData', callback?: Callback&lt;ArrayBuffer&gt;): void;

通过订阅方式，收到Callback时，应用需要填写播放数据到ArrayBuffer内，Callback结束后，系统会自动从ArrayBuffer内取走数据进行输出。

AudioCapturer新接口：

on(type: 'readData', callback: Callback&lt;ArrayBuffer&gt;): void;

off(type: 'readData', callback?: Callback&lt;ArrayBuffer&gt;): void;

通过订阅方式，收到Callback时，应用需要从ArrayBuffer内取出录音数据，Callback结束后，系统会把后续录音数据填入ArrayBuffer，准备触发下次回调。

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划

## c1.multimedia.16 ohos.multimedia.audio 内录类型获取偏好录音设备行为变更

**访问级别**

公开接口

**变更原因**

在使用内录场景进行录音时，实际并不需要使用到麦克风录音设备，需要返回正确的设备类型

**变更影响**

兼容性变更，开发无需做任何适配

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

AudioRoutingManager接口:

getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo): Promise&lt;AudioDeviceDescriptors&gt;;

变更前：

当输入类型为SOURCE_TYPE_PLAYBACK_CAPTURE时，会返回设备类型为DeviceType.MIC的AudioDeviceDescriptor

变更后：

当输入类型为SOURCE_TYPE_PLAYBACK_CAPTURE时，会返回设备类型为DeviceType.INVALID的AudioDeviceDescriptor

**适配指导**

内录场景下的返回值结果修正，无需适配

## c1.multimedia.17 ohos.multimedia.audio AudioManager系列订阅接口行为变更

**访问级别**

公开接口

**变更原因**

历史版本的订阅接口，实现不符合通用的订阅接口规范，并且可能导致应用订阅的回调被覆盖问题，需要整改

**变更影响**

如应用使用了多次订阅，预期应为订阅事件发生时，所有订阅过的回调函数会被遍历依次调用，而非仅回调最后一次订阅的

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

AudioVolumeManager接口:

on(type: 'volumeChange', callback: Callback&lt;VolumeEvent&gt;): void;

AudioVolumeGroupManager接口:

on(type: 'ringerModeChange', callback: Callback&lt;AudioRingMode&gt;): void;

on(type: 'micStateChange', callback: Callback&lt;MicStateChangeEvent&gt;): void;

AudioRoutingManager接口:

on(type: 'deviceChange', deviceFlag: DeviceFlag, callback: Callback&lt;DeviceChangeAction&gt;): void;

AudioStreamManager接口:

on(type: 'audioRendererChange', callback: Callback&lt;AudioRendererChangeInfoArray&gt;): void;

on(type: 'audioCapturerChange', callback: Callback&lt;AudioCapturerChangeInfoArray&gt;): void;

变更前：

当同一个事件被重复订阅多次，仅最后订阅的回调函数能收到事件发生的通知

变更后：

当同一个事件被重复订阅多次，所有未去订阅的回调函数，都能收到事件发生的通知

**适配指导**

一个事件仅订阅一次，无需适配

一个事件被多次订阅，但预期是会被遍历回调，无需适配

一个事件被多次订阅，但预期是仅有最后一个被回调，需要添加off去订阅，将不需要的回调函数从订阅列表删除

## c1.multimedia.18 ohos.multimedia.audio availableDevice系统接口添加错误码

**访问级别**

系统接口

**变更原因**

系统接口添加相应错误码

**变更影响**

兼容性变更，开发无需做任何适配

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

AudioRoutingManager接口:

getAvailableDevices(deviceUsage: DeviceUsage): AudioDeviceDescriptors;

on(type: 'availableDeviceChange', deviceUsage: DeviceUsage, callback: Callback&lt;DeviceChangeAction&gt;): void;

off(type: 'availableDeviceChange', callback?: Callback&lt;DeviceChangeAction&gt;): void;

变更前：

三方应用调用系统接口时，返回默认结果，订阅不生效

变更后：

三方应用调用系统接口时，抛出通用错误码202

**适配指导**

系统应用使用，无需适配

三方应用，不应该使用系统接口

## c1.multimedia.19 ohos.multimedia.audioHaptic createPlayer权限声明

**访问级别**

公开接口

**变更原因**

AudioHapticPlayer内包含震动功能，这部分功能生效依赖ohos.permission.VIBRATE权限

**变更影响**

非兼容性变更，应用可按业务需要添加权限

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

AudioHapticManager接口:

createPlayer(id: number, options?: AudioHapticPlayerOptions): Promise&lt;AudioHapticPlayer&gt;;

变更前：

```
/**
 * Create an audio haptic player. This method uses a promise to return the result.
 * @param { number } id - Source id.
 * @param { AudioHapticPlayerOptions } options - Options when creating audio haptic player.
 * @returns { Promise&lt;AudioHapticPlayer&gt; } Promise used to return the result.
 * @throws { BusinessError } 401 - The parameter check failed.
 * @throws { BusinessError } 5400102 - Operation not allowed.
 * @throws { BusinessError } 5400103 - I/O error.
 * @throws { BusinessError } 5400106 - Unsupport format.
 * @syscap SystemCapability.Multimedia.AudioHaptic.Core
 * @since 11
 */
```

无权限声明，但若不申请权限，播放无法使能震动，仅音频播放

变更后：

```
/**
 * Create an audio haptic player. This method uses a promise to return the result. If haptics is needed, caller
 * should have the permission of ohos.permission.VIBRATE.
 * @permission ohos.permission.VIBRATE
 * @param { number } id - Source id.
 * @param { AudioHapticPlayerOptions } options - Options when creating audio haptic player.
 * @returns { Promise&lt;AudioHapticPlayer&gt; } Promise used to return the result.
 * @throws { BusinessError } 201 - Permission denied.
 * @throws { BusinessError } 401 - The parameter check failed.
 * @throws { BusinessError } 5400102 - Operation not allowed.
 * @throws { BusinessError } 5400103 - I/O error.
 * @throws { BusinessError } 5400106 - Unsupport format.
 * @syscap SystemCapability.Multimedia.AudioHaptic.Core
 * @since 11
 */
```

含ohos.permission.VIBRATE权限声明和权限用途注释说明

**适配指导**

接口行为与修改前一致，如果应用需要使用震动能力，需要申请ohos.permission.VIBRATE权限

## c1.multimedia.20 ohos.multimedia.audio AudioManager错误码实现错误修正

**访问级别**

公开接口

**变更原因**

公开接口，返回的错误码类型声明为number，但历史实现错误为string，实现修复

**变更影响**

声明无变更，遵循接口定义的开发者无需适配

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

AudioManager接口:

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;

getVolume(volumeType: AudioVolumeType): Promise<number>;

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback<number>): void;

getMaxVolume(volumeType: AudioVolumeType): Promise<number>;

isMute(volumeType: AudioVolumeType, callback: AsyncCallback<boolean>): void;

isMute(volumeType: AudioVolumeType): Promise<boolean>;

变更前：

接口通过异步返回的BusinessError.code值类型为string

变更后：

接口通过异步返回的BusinessError.code值类型为number

**适配指导**

声明无变更，错误码本来就声明的就是number类型。

如开发者根据历史接口实际返回结果主动发现返回的错误码不符合定义，而直接使用字符串校验，需要根据原有API定义适配，使用AudioErrors数字错误码。