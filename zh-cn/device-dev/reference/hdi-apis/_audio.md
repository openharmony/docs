# Audio


## **概述**

Audio模块接口定义。

音频接口涉及自定义类型、驱动加载接口、驱动适配器接口、音频播放（Render）接口、音频录音（Capture）接口等。

**Since**:

1.0

**Version**:

1.0


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [audio_adapter.h](audio__adapter_8h.md) | Audio适配器的接口定义文件 | 
| [audio_attribute.h](audio__attribute_8h.md) | Audio属性的接口定义文件 | 
| [audio_capture.h](audio__capture_8h.md) | Audio录音的接口定义文件 | 
| [audio_control.h](audio__control_8h.md) | Audio控制的接口定义文件 | 
| [audio_manager.h](audio__manager_8h.md) | Audio适配器管理及加载的接口定义文件 | 
| [audio_render.h](audio__render_8h.md) | Audio播放的接口定义文件 | 
| [audio_scene.h](audio__scene_8h.md) | Audio场景的接口定义文件 | 
| [audio_types.h](audio__types_8h.md) | Audio模块接口定义中使用的自定义数据类型 | 
| [audio_volume.h](audio__volume_8h.md) | Audio音量的接口定义文件 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [AudioAdapter](_audio_adapter.md) | AudioAdapter音频适配器接口 | 
| [AudioAttribute](_audio_attribute.md) | AudioAttribute音频属性接口 | 
| [AudioCapture](_audio_capture.md) | AudioCapture音频录音接口 | 
| [AudioControl](_audio_control.md) | AudioControl音频控制接口 | 
| [AudioManager](_audio_manager.md) | AudioManager音频适配器管理接口 | 
| [AudioRender](_audio_render.md) | AudioRender音频播放接口 | 
| [AudioScene](_audio_scene.md) | AudioScene音频场景接口 | 
| [AudioPort](_audio_port.md) | 音频端口 | 
| [AudioAdapterDescriptor](_audio_adapter_descriptor.md) | 音频适配器描述符 | 
| [AudioDeviceDescriptor](_audio_device_descriptor.md) | 音频设备描述符 | 
| [AudioSceneDescriptor](_audio_scene_descriptor.md) | 音频场景描述符 | 
| [AudioSceneDescriptor::SceneDesc](union_audio_scene_descriptor_1_1_scene_desc.md) | 音频场景描述 | 
| [AudioSampleAttributes](_audio_sample_attributes.md) | 音频采样属性 | 
| [AudioTimeStamp](_audio_time_stamp.md) | 音频时间戳 | 
| [AudioSubPortCapability](_audio_sub_port_capability.md) | 音频子端口的支持能力 | 
| [AudioPortCapability](_audio_port_capability.md) | 音频端口的支持能力 | 
| [AudioMmapBufferDescriptor](_audio_mmap_buffer_descriptor.md) | mmap缓冲区描述符 | 
| [AudioDevExtInfo](_audio_dev_ext_info.md) | 音频设备拓展信息 | 
| [AudioMixExtInfo](_audio_mix_ext_info.md) | 音轨拓展信息 | 
| [AudioSessionExtInfo](_audio_session_ext_info.md) | 会话拓展信息 | 
| [AudioRouteNode](_audio_route_node.md) | 音频路由节点 | 
| [AudioRoute](_audio_route.md) | 音频路由信息 | 
| [AudioVolume](_audio_volume.md) | AudioVolume音频音量接口 | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| AudioHandle | 音频句柄 | 
| ([RenderCallback](#rendercallback))&nbsp;(enum&nbsp;AudioCallbackType,&nbsp;void&nbsp;\*reserved,&nbsp;void&nbsp;\*cookie) | 回调函数指针 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AudioPortDirection](#audioportdirection)&nbsp;{&nbsp;PORT_OUT&nbsp;=&nbsp;0x1u,&nbsp;PORT_IN&nbsp;=&nbsp;0x2u,&nbsp;PORT_OUT_IN&nbsp;=&nbsp;0x3u&nbsp;} | 音频端口的类型 | 
| [AudioPortPin](#audioportpin)&nbsp;{&nbsp;PIN_NONE&nbsp;=&nbsp;0x0u,&nbsp;PIN_OUT_SPEAKER&nbsp;=&nbsp;0x1u,&nbsp;PIN_OUT_HEADSET&nbsp;=&nbsp;0x2u,&nbsp;PIN_OUT_LINEOUT&nbsp;=&nbsp;0x4u,&nbsp;&nbsp;&nbsp;PIN_OUT_HDMI&nbsp;=&nbsp;0x8u,&nbsp;PIN_OUT_USB&nbsp;=&nbsp;0x10u,&nbsp;PIN_OUT_USB_EXT&nbsp;=&nbsp;0x20u,&nbsp;PIN_IN_MIC&nbsp;=&nbsp;0x8000001u,&nbsp;&nbsp;&nbsp;PIN_IN_HS_MIC&nbsp;=&nbsp;0x8000002u,&nbsp;PIN_IN_LINEIN&nbsp;=&nbsp;0x8000004u,&nbsp;PIN_IN_USB_EXT&nbsp;=&nbsp;0x8000008u&nbsp;} | 音频适配器端口的PIN脚 | 
| [AudioCategory](#audiocategory)&nbsp;{&nbsp;AUDIO_IN_MEDIA&nbsp;=&nbsp;0,&nbsp;AUDIO_IN_COMMUNICATION,&nbsp;AUDIO_IN_RINGTONE,&nbsp;AUDIO_IN_CALL&nbsp;} | 音频类型（category） | 
| [AudioFormat](#audioformat){&nbsp;AUDIO_FORMAT_PCM_8_BIT&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_FORMAT_PCM_16_BIT&nbsp;=&nbsp;0x2u,&nbsp;AUDIO_FORMAT_PCM_24_BIT&nbsp;=&nbsp;0x3u,&nbsp;AUDIO_FORMAT_PCM_32_BIT&nbsp;=&nbsp;0x4u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_AAC_MAIN&nbsp;=&nbsp;0x1000001u,&nbsp;AUDIO_FORMAT_AAC_LC&nbsp;=&nbsp;0x1000002u,&nbsp;AUDIO_FORMAT_AAC_LD&nbsp;=&nbsp;0x1000003u,&nbsp;AUDIO_FORMAT_AAC_ELD&nbsp;=&nbsp;0x1000004u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_AAC_HE_V1&nbsp;=&nbsp;0x1000005u,&nbsp;AUDIO_FORMAT_AAC_HE_V2&nbsp;=&nbsp;0x1000006u,&nbsp;AUDIO_FORMAT_G711A&nbsp;=&nbsp;0x2000001u,&nbsp;AUDIO_FORMAT_G711U&nbsp;=&nbsp;0x2000002u,&nbsp;&nbsp;&nbsp;AUDIO_FORMAT_G726&nbsp;=&nbsp;0x2000003u&nbsp;} | 音频格式 | 
| [AudioChannelMask](#audiochannelmask){&nbsp;AUDIO_CHANNEL_FRONT_LEFT&nbsp;=&nbsp;0x1,&nbsp;AUDIO_CHANNEL_FRONT_RIGHT&nbsp;=&nbsp;0x2,&nbsp;AUDIO_CHANNEL_MONO&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_CHANNEL_STEREO&nbsp;=&nbsp;0x3u&nbsp;} | 音频通道掩码（mask） | 
| [AudioSampleRatesMask](#audiosampleratesmask){&nbsp;AUDIO_SAMPLE_RATE_MASK_8000&nbsp;=&nbsp;0x1u,&nbsp;AUDIO_SAMPLE_RATE_MASK_12000&nbsp;=&nbsp;0x2u,&nbsp;AUDIO_SAMPLE_RATE_MASK_11025&nbsp;=&nbsp;0x4u,&nbsp;AUDIO_SAMPLE_RATE_MASK_16000&nbsp;=&nbsp;0x8u,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_RATE_MASK_22050&nbsp;=&nbsp;0x10u,&nbsp;AUDIO_SAMPLE_RATE_MASK_24000&nbsp;=&nbsp;0x20u,&nbsp;AUDIO_SAMPLE_RATE_MASK_32000&nbsp;=&nbsp;0x40u,&nbsp;AUDIO_SAMPLE_RATE_MASK_44100&nbsp;=&nbsp;0x80u,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_RATE_MASK_48000&nbsp;=&nbsp;0x100u,&nbsp;AUDIO_SAMPLE_RATE_MASK_64000&nbsp;=&nbsp;0x200u,&nbsp;AUDIO_SAMPLE_RATE_MASK_96000&nbsp;=&nbsp;0x400u,&nbsp;AUDIO_SAMPLE_RATE_MASK_INVALID&nbsp;=&nbsp;0xFFFFFFFFu&nbsp;} | 音频采样频率MASK | 
| [AudioPortPassthroughMode](#audioportpassthroughmode){&nbsp;PORT_PASSTHROUGH_LPCM&nbsp;=&nbsp;0x1,&nbsp;PORT_PASSTHROUGH_RAW&nbsp;=&nbsp;0x2,&nbsp;PORT_PASSTHROUGH_HBR2LBR&nbsp;=&nbsp;0x4,&nbsp;PORT_PASSTHROUGH_AUTO&nbsp;=&nbsp;0x8&nbsp;} | 音频端口的数据透传模式 | 
| [AudioSampleFormat](#audiosampleformat){&nbsp;AUDIO_SAMPLE_FORMAT_S8,&nbsp;AUDIO_SAMPLE_FORMAT_S8P,&nbsp;AUDIO_SAMPLE_FORMAT_U8,&nbsp;AUDIO_SAMPLE_FORMAT_U8P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S16,&nbsp;AUDIO_SAMPLE_FORMAT_S16P,&nbsp;AUDIO_SAMPLE_FORMAT_U16,&nbsp;AUDIO_SAMPLE_FORMAT_U16P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S24,&nbsp;AUDIO_SAMPLE_FORMAT_S24P,&nbsp;AUDIO_SAMPLE_FORMAT_U24,&nbsp;AUDIO_SAMPLE_FORMAT_U24P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S32,&nbsp;AUDIO_SAMPLE_FORMAT_S32P,&nbsp;AUDIO_SAMPLE_FORMAT_U32,&nbsp;AUDIO_SAMPLE_FORMAT_U32P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_S64,&nbsp;AUDIO_SAMPLE_FORMAT_S64P,&nbsp;AUDIO_SAMPLE_FORMAT_U64,&nbsp;AUDIO_SAMPLE_FORMAT_U64P,&nbsp;&nbsp;&nbsp;AUDIO_SAMPLE_FORMAT_F32,&nbsp;AUDIO_SAMPLE_FORMAT_F32P,&nbsp;AUDIO_SAMPLE_FORMAT_F64,&nbsp;AUDIO_SAMPLE_FORMAT_F64P&nbsp;} | 原始音频样本格式 | 
| [AudioChannelMode](#audiochannelmode){&nbsp;&nbsp;AUDIO_CHANNEL_NORMAL&nbsp;=&nbsp;0,&nbsp;AUDIO_CHANNEL_BOTH_LEFT,&nbsp;AUDIO_CHANNEL_BOTH_RIGHT,&nbsp;AUDIO_CHANNEL_EXCHANGE,&nbsp;&nbsp;&nbsp;AUDIO_CHANNEL_MIX,&nbsp;AUDIO_CHANNEL_LEFT_MUTE,&nbsp;AUDIO_CHANNEL_RIGHT_MUTE,&nbsp;AUDIO_CHANNEL_BOTH_MUTE&nbsp;} | 音频播放的通道模式 | 
| [AudioDrainNotifyType](#audiodrainnotifytype){&nbsp;AUDIO_DRAIN_NORMAL_MODE,&nbsp;AUDIO_DRAIN_EARLY_MODE&nbsp;} | DrainBuffer函数结束类型 | 
| [AudioCallbackType](#audiocallbacktype){&nbsp;AUDIO_NONBLOCK_WRITE_COMPLETED,&nbsp;AUDIO_DRAIN_COMPLETED,&nbsp;AUDIO_FLUSH_COMPLETED,&nbsp;AUDIO_RENDER_FULL,&nbsp;&nbsp;&nbsp;AUDIO_ERROR_OCCUR&nbsp;} | 回调函数通知事件类型 | 
| [AudioPortRole](#audioportrole){&nbsp;AUDIO_PORT_UNASSIGNED_ROLE&nbsp;=&nbsp;0,&nbsp;AUDIO_PORT_SOURCE_ROLE&nbsp;=&nbsp;1,&nbsp;AUDIO_PORT_SINK_ROLE&nbsp;=&nbsp;2&nbsp;} | 音频端口角色 | 
| [AudioPortType](#audioporttype){&nbsp;AUDIO_PORT_UNASSIGNED_TYPE&nbsp;=&nbsp;0,&nbsp;AUDIO_PORT_DEVICE_TYPE&nbsp;=&nbsp;1,&nbsp;AUDIO_PORT_MIX_TYPE&nbsp;=&nbsp;2,&nbsp;AUDIO_PORT_SESSION_TYPE&nbsp;=&nbsp;3&nbsp;} | 音频端口类型. | 
| [AudioSessionType](#audiosessiontype){&nbsp;AUDIO_OUTPUT_STAGE_SESSION&nbsp;=&nbsp;0,&nbsp;AUDIO_OUTPUT_MIX_SESSION,&nbsp;AUDIO_ALLOCATE_SESSION,&nbsp;AUDIO_INVALID_SESSION&nbsp;} | 端口会话类型 | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GetAudioManagerFuncs](#getaudiomanagerfuncs)(void) | 获取音频适配器管理接口的操作函数列表，详情参考[AudioManager](_audio_manager.md)。 | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| [AudioPort::dir](#dir) | 音频端口的类型。 | 
| [AudioPort::portId](#portid-14) | 音频端口的ID。 | 
| [AudioPort::portName](#portname) | 音频端口的名称。 | 
| [AudioAdapterDescriptor::adapterName](#adaptername) | 音频适配器的名称。 | 
| [AudioAdapterDescriptor::portNum](#portnum) | 一个音频适配器支持的端口数目。 | 
| [AudioAdapterDescriptor::ports](#ports) | 一个音频适配器支持的端口列表。 | 
| [AudioDeviceDescriptor::portId](#portid-24) | 音频端口ID。 | 
| [AudioDeviceDescriptor::pins](#pins) | 音频端口上的PIN脚（输出、输入）。 | 
| [AudioDeviceDescriptor::desc](#desc-15) | 以字符串命名的音频设备。 | 
| [AudioSceneDescriptor::SceneDesc::id](#id) | 音频场景的ID。 | 
| [AudioSceneDescriptor::SceneDesc::desc](#desc-35) | 以字符串命名的音频场景。 | 
| [AudioSceneDescriptor::scene](#scene) | 音频场景的名称。 | 
| [AudioSceneDescriptor::desc](#desc-25) | 音频设备描述符。 | 
| [AudioSampleAttributes::type](#type-13) | 音频类型。 | 
| [AudioSampleAttributes::interleaved](#interleaved) | 音频数据交织的标记。 | 
| [AudioSampleAttributes::format](#format) | 音频数据格式。 | 
| [AudioSampleAttributes::sampleRate](#samplerate) | 音频采样频率。 | 
| [AudioSampleAttributes::channelCount](#channelcount-12) | 音频通道数目，如单通道（mono）为1、立体声（stereo）为2。 | 
| [AudioSampleAttributes::period](#period) | 音频采样周期。 | 
| [AudioSampleAttributes::frameSize](#framesize) | 音频数据的帧大小。 | 
| [AudioSampleAttributes::isBigEndian](#isbigendian) | 音频数据的大端标志。 | 
| [AudioSampleAttributes::isSignedData](#issigneddata) | 音频数据的有符号或无符号标志。 | 
| [AudioSampleAttributes::startThreshold](#startthreshold) | 音频渲染开始阈值。 | 
| [AudioSampleAttributes::stopThreshold](#stopthreshold) | 音频渲染停止阈值。 | 
| [AudioSampleAttributes::silenceThreshold](#silencethreshold) | 音频捕获缓冲区阈值。 | 
| [AudioSampleAttributes::streamId](#streamid-12) | 渲染或捕获的音频标识符。 | 
| [AudioTimeStamp::tvSec](#tvsec) | tvSec时间，单位：秒。 | 
| [AudioTimeStamp::tvNSec](#tvnsec) | tvNSec时间，单位：纳秒。 | 
| [AudioSubPortCapability::portId](#portid-34) | 子端口ID。 | 
| [AudioSubPortCapability::desc](#desc-45) | 以字符串命名的子端口。 | 
| [AudioSubPortCapability::mask](#mask) | 数据透传模式。 | 
| [AudioPortCapability::deviceType](#devicetype) | 设备输出、输入类型。 | 
| [AudioPortCapability::deviceId](#deviceid) | 绑定（bind）设备ID，唯一的设备识别符。 | 
| [AudioPortCapability::hardwareMode](#hardwaremode) | 是否支持设备绑定处理。 | 
| [AudioPortCapability::formatNum](#formatnum) | 支持的音频格式数目。 | 
| [AudioPortCapability::formats](#formats) | 支持的音频格式。 | 
| [AudioPortCapability::sampleRateMasks](#sampleratemasks) | 支持的音频采样频率（8k、16k、32k、48k）。 | 
| [AudioPortCapability::channelMasks](#channelmasks) | 设备的声道布局掩码（mask）。 | 
| [AudioPortCapability::channelCount](#channelcount-22) | 支持的最大声道总数。 | 
| [AudioPortCapability::subPortsNum](#subportsnum) | 支持的子端口数目（仅用于输出设备）。 | 
| [AudioPortCapability::subPorts](#subports) | 支持的子端口列表。 | 
| [AudioPortCapability::supportSampleFormatNum](#supportsampleformatnum) | 支持的音频样本格式数量。 | 
| [AudioPortCapability::supportSampleFormats](#supportsampleformats) | 支持的音频样本格式。 | 
| [AudioMmapBufferDescriptor::memoryAddress](#memoryaddress) | 指向mmap缓冲区的指针。 | 
| [AudioMmapBufferDescriptor::memoryFd](#memoryfd) | mmap缓冲区的文件描述符。 | 
| [AudioMmapBufferDescriptor::totalBufferFrames](#totalbufferframes) | 缓冲区总大小，单位：帧。 | 
| [AudioMmapBufferDescriptor::transferFrameSize](#transferframesize) | 传输大小，单位：帧。 | 
| [AudioMmapBufferDescriptor::isShareable](#isshareable) | mmap缓冲区是否可以在进程间共享。 | 
| [AudioDevExtInfo::moduleId](#moduleid-12) | 音频流绑定的模块ID。 | 
| [AudioDevExtInfo::type](#type-23) | 音频端口上的PIN脚（输出、输入）。 | 
| [AudioDevExtInfo::desc](#desc-55) | 地址描述。 | 
| [AudioMixExtInfo::moduleId](#moduleid-22) | 流所属模块标识符。 | 
| [AudioMixExtInfo::streamId](#streamid-22) | 由调用者传递的Render或Capture标识符。 | 
| [AudioSessionExtInfo::sessionType](#sessiontype) | 音频会话类型。 | 
| [AudioRouteNode::portId](#portid-44) | 音频端口ID。 | 
| [AudioRouteNode::role](#role) | 指定端口角色为sink或source。 | 
| [AudioRouteNode::type](#type-33) | 指定端口类型。 | 
| [AudioRouteNode::device](#device) | 设备特定信息。 | 
| [AudioRouteNode::mix](#mix) | 音轨特定信息。 | 
| [AudioRouteNode::session](#session) | 会话特定信息。 | 
| [AudioRoute::sourcesNum](#sourcesnum) | 发送端节点数量。 | 
| [AudioRoute::sources](#sources) | 发送端列表。 | 
| [AudioRoute::sinksNum](#sinksnum) | 接受端节点数量。 | 
| [AudioRoute::sinks](#sinks) | 接受端列表。 | 


## **类型定义说明**


### RenderCallback

  
```
typedef int32_t(* RenderCallback) (enum AudioCallbackType, void *reserved, void *cookie)
```

**描述:**

回调函数指针。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| AudioCallbackType | 回调函数响应类型 | 
| reserved | 保留字段 | 
| cookie | 用于传递数据 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[RegCallback](_audio_render.md#regcallback)


## **枚举类型说明**


### AudioCallbackType

  
```
enum AudioCallbackType
```

**描述:**

回调函数通知事件类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_NONBLOCK_WRITE_COMPLETED | 非阻塞式写完成 | 
| AUDIO_DRAIN_COMPLETED | DrainBuffer完成 | 
| AUDIO_FLUSH_COMPLETED | Flush完成 | 
| AUDIO_RENDER_FULL | Render缓冲区已满 | 
| AUDIO_ERROR_OCCUR | 发生了错误 | 


### AudioCategory

  
```
enum AudioCategory
```

**描述:**

音频类型（category）。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_IN_MEDIA | 媒体 | 
| AUDIO_IN_COMMUNICATION | 通信 | 
| AUDIO_IN_RINGTONE | 铃声 | 
| AUDIO_IN_CALL | 呼叫 | 


### AudioChannelMask

  
```
enum AudioChannelMask
```

**描述:**

音频通道掩码（mask）。

定义音频声道的位置。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_CHANNEL_FRONT_LEFT | 声道布局前左 | 
| AUDIO_CHANNEL_FRONT_RIGHT | 声道布局前右 | 
| AUDIO_CHANNEL_MONO | 单声道 | 
| AUDIO_CHANNEL_STEREO | 立体声，由左右声道组成（FRONT_LEFT&nbsp;\|&nbsp;FRONT_RIGHT） | 


### AudioChannelMode

  
```
enum AudioChannelMode
```

**描述:**

音频播放的通道模式。

**注意:**

下面的模式是针对双通道立体声的音频播放而设置，其他不支持。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_CHANNEL_NORMAL | 正常模式，不做处理 | 
| AUDIO_CHANNEL_BOTH_LEFT | 两个声道全部为左声道声音 | 
| AUDIO_CHANNEL_BOTH_RIGHT | 两个声道全部为右声道声音 | 
| AUDIO_CHANNEL_EXCHANGE | 左右声道数据互换，左声道为右声道声音，右声道为左声道声音 | 
| AUDIO_CHANNEL_MIX | 左右两个声道输出为左右声道相加（混音） | 
| AUDIO_CHANNEL_LEFT_MUTE | 左声道静音，右声道播放原右声道声音 | 
| AUDIO_CHANNEL_RIGHT_MUTE | 右声道静音，左声道播放原左声道声音 | 
| AUDIO_CHANNEL_BOTH_MUTE | 左右声道均静音 | 


### AudioDrainNotifyType

  
```
enum AudioDrainNotifyType
```

**描述:**

DrainBuffer函数结束类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DRAIN_NORMAL_MODE | DrainBuffer在所有数据播放结束后返回 | 
| AUDIO_DRAIN_EARLY_MODE | DrainBuffer()在当前曲目的所有数据播放完之前返回，以便留出时间给音频服务做连续性曲目切换 | 


### AudioFormat

  
```
enum AudioFormat
```

**描述:**

音频格式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_FORMAT_PCM_8_BIT | 8bit位宽pcm格式 | 
| AUDIO_FORMAT_PCM_16_BIT | 16bit位宽pcm格式 | 
| AUDIO_FORMAT_PCM_24_BIT | 24bit位宽pcm格式 | 
| AUDIO_FORMAT_PCM_32_BIT | 32bit位宽pcm格式 | 
| AUDIO_FORMAT_AAC_MAIN | AAC&nbsp;MAIN格式 | 
| AUDIO_FORMAT_AAC_LC | AAC&nbsp;LC格式 | 
| AUDIO_FORMAT_AAC_LD | AAC&nbsp;LD格式 | 
| AUDIO_FORMAT_AAC_ELD | AAC&nbsp;ELD格式 | 
| AUDIO_FORMAT_AAC_HE_V1 | AAC&nbsp;HE_V1格式 | 
| AUDIO_FORMAT_AAC_HE_V2 | AAC&nbsp;HE_V2格式 | 
| AUDIO_FORMAT_G711A | G711A格式 | 
| AUDIO_FORMAT_G711U | G711u格式 | 
| AUDIO_FORMAT_G726 | G726格式 | 


### AudioPortDirection

  
```
enum AudioPortDirection
```

**描述:**

音频端口的类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PORT_OUT | 音频输出端口 | 
| PORT_IN | 音频输入端口 | 
| PORT_OUT_IN | 音频输出/入端口,&nbsp;同时支持输出和输入能力（OUT&nbsp;\|&nbsp;IN） | 


### AudioPortPassthroughMode

  
```
enum AudioPortPassthroughMode
```

**描述:**

音频端口的数据透传模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PORT_PASSTHROUGH_LPCM | 立体声pcm | 
| PORT_PASSTHROUGH_RAW | HDMI透传 | 
| PORT_PASSTHROUGH_HBR2LBR | 蓝光次世代音频降规格输出 | 
| PORT_PASSTHROUGH_AUTO | 根据HDMI&nbsp;EDID能力自动匹配 | 


### AudioPortPin

  
```
enum AudioPortPin
```

**描述:**

音频适配器端口的PIN脚。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PIN_NONE | 无效PIN | 
| PIN_OUT_SPEAKER | 喇叭输出 | 
| PIN_OUT_HEADSET | 有线耳机输出 | 
| PIN_OUT_LINEOUT | Lineout输出 | 
| PIN_OUT_HDMI | HDMI输出 | 
| PIN_OUT_USB | USB设备输出 | 
| PIN_OUT_USB_EXT | 扩展&nbsp;USB&nbsp;设备输出 | 
| PIN_IN_MIC | Mic输入 | 
| PIN_IN_HS_MIC | 有线耳机Mic输入 | 
| PIN_IN_LINEIN | Linein输入 | 
| PIN_IN_USB_EXT | 扩展&nbsp;USB&nbsp;设备输入 | 


### AudioPortRole

  
```
enum AudioPortRole
```

**描述:**

音频端口角色。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_PORT_UNASSIGNED_ROLE | 未指定端口角色 | 
| AUDIO_PORT_SOURCE_ROLE | 指定端口为发送端角色 | 
| AUDIO_PORT_SINK_ROLE | 指定端口为接受端角色 | 


### AudioPortType

  
```
enum AudioPortType
```

**描述:**

音频端口类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_PORT_UNASSIGNED_TYPE | 未指定端口类型 | 
| AUDIO_PORT_DEVICE_TYPE | 指定端口为设备类型 | 
| AUDIO_PORT_MIX_TYPE | 指定端口类型为复合类型 | 
| AUDIO_PORT_SESSION_TYPE | 指定端口为会话类型 | 


### AudioSampleFormat

  
```
enum AudioSampleFormat
```

**描述:**

原始音频样本格式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_FORMAT_S8 | 8bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S8P | 8bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U8 | 8bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U8P | 8bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_S16 | 16bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S16P | 16bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U16 | 16bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U16P | 16bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_S24 | 24bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S24P | 24bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U24 | 24bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U24P | 24bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_S32 | 32bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S32P | 32bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U32 | 32bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U32P | 32bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_S64 | 64bit位宽有符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_S64P | 64bit位宽有符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_U64 | 64bit位宽无符号交织样本 | 
| AUDIO_SAMPLE_FORMAT_U64P | 64bit位宽无符号非交织样本 | 
| AUDIO_SAMPLE_FORMAT_F32 | 32bit位宽浮点型交织样本 | 
| AUDIO_SAMPLE_FORMAT_F32P | 64bit位宽浮点型非交织样本 | 
| AUDIO_SAMPLE_FORMAT_F64 | 64bit位宽双精度浮点型交织样本 | 
| AUDIO_SAMPLE_FORMAT_F64P | 64bit位宽双精度浮点型非交织样本 | 


### AudioSampleRatesMask

  
```
enum AudioSampleRatesMask
```

**描述:**

音频采样频率MASK。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_RATE_MASK_8000 | 8K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_12000 | 12K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_11025 | 11.025K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_16000 | 16K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_22050 | 22.050K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_24000 | 24K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_32000 | 32K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_44100 | 44.1K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_48000 | 48K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_64000 | 64K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_96000 | 96K&nbsp;采样频率 | 
| AUDIO_SAMPLE_RATE_MASK_INVALID | 无效的采样频率 | 


### AudioSessionType

  
```
enum AudioSessionType
```

**描述:**

端口会话类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_OUTPUT_STAGE_SESSION | 会话绑定到指定输出流 | 
| AUDIO_OUTPUT_MIX_SESSION | 会话绑定到特定音轨 | 
| AUDIO_ALLOCATE_SESSION | 会话ID需重新申请 | 
| AUDIO_INVALID_SESSION | 无效会话类型 | 


## **函数说明**


### GetAudioManagerFuncs()

  
```
struct AudioManager* GetAudioManagerFuncs (void )
```

**描述:**

获取音频适配器管理接口的操作函数列表，详情参考[AudioManager](_audio_manager.md)。

**返回:**

成功返回一个音频适配器管理接口的对象，失败返回NULL。


## **变量说明**


### adapterName

  
```
const char* AudioAdapterDescriptor::adapterName
```

**描述:**

音频适配器的名称


### channelCount [1/2]

  
```
uint32_t AudioSampleAttributes::channelCount
```

**描述:**

音频通道数目，如单通道（mono）为1、立体声（stereo）为2。


### channelCount [2/2]

  
```
unsigned int AudioPortCapability::channelCount
```

**描述:**

支持的最大声道总数


### channelMasks

  
```
enum AudioChannelMask AudioPortCapability::channelMasks
```

**描述:**

设备的声道布局掩码（mask），详情参考[AudioChannelMask](#audiochannelmask)。


### desc [1/5]

  
```
const char* AudioDeviceDescriptor::desc
```

**描述:**

以字符串命名的音频设备


### desc [2/5]

  
```
struct AudioDeviceDescriptor AudioSceneDescriptor::desc
```

**描述:**

音频设备描述符


### desc [3/5]

  
```
const char* AudioSceneDescriptor::SceneDesc::desc
```

**描述:**

以字符串命名的音频场景


### desc [4/5]

  
```
const char* AudioSubPortCapability::desc
```

**描述:**

以字符串命名的子端口


### desc [5/5]

  
```
const char* AudioDevExtInfo::desc
```

**描述:**

地址描述


### device

  
```
struct AudioDevExtInfo AudioRouteNode::ext::device
```

**描述:**

设备特定信息。


### deviceId

  
```
unsigned int AudioPortCapability::deviceId
```

**描述:**

绑定（bind）设备ID，唯一的设备识别符。


### deviceType

  
```
unsigned int AudioPortCapability::deviceType
```

**描述:**

设备输出、输入类型。


### dir

  
```
enum AudioPortDirection AudioPort::dir
```

**描述:**

音频端口的类型，详情参考[AudioPortDirection](#audioportdirection)。


### format

  
```
enum AudioFormat AudioSampleAttributes::format
```

**描述:**

音频数据格式，详情参考[AudioFormat](#audioformat)。


### formatNum

  
```
unsigned int AudioPortCapability::formatNum
```

**描述:**

支持的音频格式数目


### formats

  
```
enum AudioFormat* AudioPortCapability::formats
```

**描述:**

支持的音频格式，详情参考[AudioFormat](#audioformat)。


### frameSize

  
```
uint32_t AudioSampleAttributes::frameSize
```

**描述:**

音频数据的帧大小


### hardwareMode

  
```
bool AudioPortCapability::hardwareMode
```

**描述:**

是否支持设备绑定处理


### id

  
```
unsigned int AudioSceneDescriptor::SceneDesc::id
```

**描述:**

音频场景的ID


### interleaved

  
```
bool AudioSampleAttributes::interleaved
```

**描述:**

音频数据交织的标记


### isBigEndian

  
```
bool AudioSampleAttributes::isBigEndian
```

**描述:**

音频数据的大端标志


### isShareable

  
```
int32_t AudioMmapBufferDescriptor::isShareable
```

**描述:**

mmap缓冲区是否可以在进程间共享


### isSignedData

  
```
bool AudioSampleAttributes::isSignedData
```

**描述:**

音频数据的有符号或无符号标志


### mask

  
```
enum AudioPortPassthroughMode AudioSubPortCapability::mask
```

**描述:**

数据透传模式，详情参考[AudioPortPassthroughMode](#audioportpassthroughmode)。


### memoryAddress

  
```
void* AudioMmapBufferDescriptor::memoryAddress
```

**描述:**

指向mmap缓冲区的指针


### memoryFd

  
```
int32_t AudioMmapBufferDescriptor::memoryFd
```

**描述:**

mmap缓冲区的文件描述符


### mix

  
```
struct AudioMixExtInfo AudioRouteNode::ext::mix
```

**描述:**

音轨特定信息。


### moduleId [1/2]

  
```
int32_t AudioDevExtInfo::moduleId
```

**描述:**

音频流绑定的模块ID


### moduleId [2/2]

  
```
int32_t AudioMixExtInfo::moduleId
```

**描述:**

流所属模块标识符


### period

  
```
uint32_t AudioSampleAttributes::period
```

**描述:**

音频采样周期


### pins

  
```
enum AudioPortPin AudioDeviceDescriptor::pins
```

**描述:**

音频端口上的PIN脚（输出、输入），详情参考[AudioPortPin](#audioportpin)。


### portId [1/4]

  
```
unsigned int AudioPort::portId
```

**描述:**

音频端口的ID


### portId [2/4]

  
```
unsigned int AudioDeviceDescriptor::portId
```

**描述:**

音频端口ID


### portId [3/4]

  
```
unsigned int AudioSubPortCapability::portId
```

**描述:**

子端口ID


### portId [4/4]

  
```
int32_t AudioRouteNode::portId
```

**描述:**

音频端口ID


### portName

  
```
const char* AudioPort::portName
```

**描述:**

音频端口的名称


### portNum

  
```
unsigned int AudioAdapterDescriptor::portNum
```

**描述:**

一个音频适配器支持的端口数目


### ports

  
```
struct AudioPort* AudioAdapterDescriptor::ports
```

**描述:**

一个音频适配器支持的端口列表


### role

  
```
enum AudioPortRole AudioRouteNode::role
```

**描述:**

指定端口角色为sink或source


### sampleRate

  
```
unsigned int AudioSampleAttributes::sampleRate
```

**描述:**

音频采样频率


### sampleRateMasks

  
```
unsigned int AudioPortCapability::sampleRateMasks
```

**描述:**

支持的音频采样频率（8k、16k、32k、48k）


### scene

  
```
union AudioSceneDescriptor::SceneDesc AudioSceneDescriptor::scene
```

**描述:**

音频场景的名称


### session

  
```
struct AudioSessionExtInfo AudioRouteNode::ext::session
```

**描述:**

会话特定信息。


### sessionType

  
```
enum AudioSessionType AudioSessionExtInfo::sessionType
```

**描述:**

音频会话类型


### silenceThreshold

  
```
uint32_t AudioSampleAttributes::silenceThreshold
```

**描述:**

音频捕获缓冲区阈值


### sinks

  
```
const struct AudioRouteNode* AudioRoute::sinks
```

**描述:**

接受端列表


### sinksNum

  
```
uint32_t AudioRoute::sinksNum
```

**描述:**

接受端节点数量


### sources

  
```
const struct AudioRouteNode* AudioRoute::sources
```

**描述:**

发送端列表


### sourcesNum

  
```
uint32_t AudioRoute::sourcesNum
```

**描述:**

发送端节点数量


### startThreshold

  
```
uint32_t AudioSampleAttributes::startThreshold
```

**描述:**

音频渲染开始阈值


### stopThreshold

  
```
uint32_t AudioSampleAttributes::stopThreshold
```

**描述:**

音频渲染停止阈值


### streamId [1/2]

  
```
int32_t AudioSampleAttributes::streamId
```

**描述:**

渲染或捕获的音频标识符


### streamId [2/2]

  
```
int32_t AudioMixExtInfo::streamId
```

**描述:**

由调用者传递的Render或Capture标识符


### subPorts

  
```
struct AudioSubPortCapability* AudioPortCapability::subPorts
```

**描述:**

支持的子端口列表


### subPortsNum

  
```
unsigned int AudioPortCapability::subPortsNum
```

**描述:**

支持的子端口数目（仅用于输出设备）


### supportSampleFormatNum

  
```
uint32_t AudioPortCapability::supportSampleFormatNum
```

**描述:**

支持的音频样本格式数量


### supportSampleFormats

  
```
enum AudioSampleFormat* AudioPortCapability::supportSampleFormats
```

**描述:**

支持的音频样本格式，详请参考[AudioSampleFormat](#audiosampleformat)。


### totalBufferFrames

  
```
int32_t AudioMmapBufferDescriptor::totalBufferFrames
```

**描述:**

缓冲区总大小，单位：帧。


### transferFrameSize

  
```
int32_t AudioMmapBufferDescriptor::transferFrameSize
```

**描述:**

传输大小，单位：帧。


### tvNSec

  
```
int64_t AudioTimeStamp::tvNSec
```

**描述:**

tvNSec时间，单位：纳秒。


### tvSec

  
```
int64_t AudioTimeStamp::tvSec
```

**描述:**

tvSec时间，单位：秒。


### type [1/3]

  
```
enum AudioCategory AudioSampleAttributes::type
```

**描述:**

音频类型，详情参考[AudioCategory](#audiocategory)。


### type [2/3]

  
```
enum AudioPortPin AudioDevExtInfo::type
```

**描述:**

音频端口上的PIN脚（输出、输入），详情参考[AudioPortPin](#audioportpin)。


### type [3/3]

  
```
enum AudioPortType AudioRouteNode::type
```

**描述:**

指定端口类型为device, mix等。
