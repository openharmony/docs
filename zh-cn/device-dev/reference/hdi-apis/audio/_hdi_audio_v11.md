# HdiAudio (V1_0)


## 概述

Audio模块接口定义。

音频接口涉及数据类型、驱动加载接口、驱动适配器接口、音频播放接口、音频录音接口等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [AudioTypes.idl](_audio_types_8idl_v10.md) | Audio模块接口定义中使用的数据类型。 | 
| [IAudioAdapter.idl](_i_audio_adapter_8idl_v10.md) | Audio适配器的接口定义文件。 | 
| [IAudioCallback.idl](_i_audio_callback_8idl_v10.md) | Audio播放的回调函数定义文件。 | 
| [IAudioCapture.idl](_i_audio_capture_8idl_v10.md) | Audio录音的接口定义文件。 | 
| [IAudioManager.idl](_i_audio_manager_8idl_v10.md) | Audio适配器管理及加载的接口定义文件。 | 
| [IAudioRender.idl](_i_audio_render_8idl_v10.md) | Audio播放的接口定义文件。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[AudioDeviceStatus](_audio_device_status_v10.md) | 音频设备状态。 | 
| union&nbsp;&nbsp;[SceneDesc](union_scene_desc_v11.md) | 音频场景描述。 | 
| struct&nbsp;&nbsp;[AudioPort](_audio_port_v10.md) | 音频端口。 | 
| struct&nbsp;&nbsp;[AudioAdapterDescriptor](_audio_adapter_descriptor_v10.md) | 音频适配器描述符。 | 
| struct&nbsp;&nbsp;[AudioDeviceDescriptor](_audio_device_descriptor_v10.md) | 音频设备描述符。 | 
| struct&nbsp;&nbsp;[AudioSceneDescriptor](_audio_scene_descriptor_v10.md) | 音频场景描述符。 | 
| struct&nbsp;&nbsp;[AudioOffloadInfo](_audio_offload_info_v10.md) | 音频低功耗属性。 | 
| struct&nbsp;&nbsp;[AudioSampleAttributes](_audio_sample_attributes_v10.md) | 音频采样属性。 | 
| struct&nbsp;&nbsp;[AudioTimeStamp](_audio_time_stamp_v10.md) | 音频时间戳。 | 
| struct&nbsp;&nbsp;[AudioSubPortCapability](_audio_sub_port_capability_v10.md) | 音频子端口的支持能力。 | 
| struct&nbsp;&nbsp;[AudioPortCapability](_audio_port_capability_v10.md) | 音频端口的支持能力。 | 
| struct&nbsp;&nbsp;[AudioMmapBufferDescripter](_audio_mmap_buffer_descripter_v10.md) | mmap缓冲区描述符。 | 
| struct&nbsp;&nbsp;[AudioDevExtInfo](_audio_dev_ext_info_v10.md) | 音频设备拓展信息。 | 
| struct&nbsp;&nbsp;[AudioMixExtInfo](_audio_mix_ext_info_v10.md) | 音轨拓展信息。 | 
| struct&nbsp;&nbsp;[AudioSessionExtInfo](_audio_session_ext_info_v10.md) | 会话拓展信息。 | 
| struct&nbsp;&nbsp;[AudioInfo](_audio_info_v10.md) | 音频端口特定信息。 | 
| struct&nbsp;&nbsp;[AudioRouteNode](_audio_route_node_v10.md) | 音频路由节点。 | 
| struct&nbsp;&nbsp;[AudioRoute](_audio_route_v10.md) | 音频路由信息。 | 
| struct&nbsp;&nbsp;[AudioEvent](_audio_event_v10.md) | 音频事件。 | 
| interface&nbsp;&nbsp;[IAudioAdapter](interface_i_audio_adapter_v10.md) | AudioAdapter音频适配器接口。 | 
| interface&nbsp;&nbsp;[IAudioCallback](interface_i_audio_callback_v10.md) | Audio回调接口。 | 
| interface&nbsp;&nbsp;[IAudioCapture](interface_i_audio_capture_v10.md) | AudioCapture音频录制接口。 | 
| interface&nbsp;&nbsp;[IAudioManager](interface_i_audio_manager_v10.md) | AudioManager音频适配器管理接口。 | 
| interface&nbsp;&nbsp;[IAudioRender](interface_i_audio_render_v10.md) | AudioRender音频播放接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AudioPortDirection](#audioportdirection) { PORT_OUT = 1 , PORT_IN = 2 , PORT_OUT_IN = 3 } | 音频端口的类型。 | 
| [AudioPortPin](#audioportpin) {<br/>PIN_NONE = 0 , PIN_OUT_SPEAKER = 1 &lt;&lt; 0 , PIN_OUT_HEADSET = 1 &lt;&lt; 1 , PIN_OUT_LINEOUT = 1 &lt;&lt; 2 ,<br/>PIN_OUT_HDMI&nbsp;&nbsp;= 1 &lt;&lt; 3 , PIN_OUT_USB = 1 &lt;&lt; 4 , PIN_OUT_USB_EXT = 1 &lt;&lt; 5 , PIN_OUT_EARPIECE = 1 &lt;&lt; 5 \| 1 &lt;&lt; 4 ,<br/>PIN_OUT_BLUETOOTH_SCO = 1 &lt;&lt; 6 , PIN_OUT_DAUDIO_DEFAULT = 1 &lt;&lt; 7 , PIN_OUT_HEADPHONE = 1 &lt;&lt; 8 , PIN_OUT_USB_HEADSET = 1 &lt;&lt; 9 ,<br/>PIN_OUT_BLUETOOTH_A2DP = 1 &lt;&lt; 10 , PIN_IN_MIC = 1 &lt;&lt; 27 \| 1 &lt;&lt; 0 , PIN_IN_HS_MIC = 1 &lt;&lt; 27 \| 1 &lt;&lt; 1 , PIN_IN_LINEIN = 1 &lt;&lt; 27 \| 1 &lt;&lt; 2 ,<br/>PIN_IN_USB_EXT = 1 &lt;&lt; 27 \| 1 &lt;&lt; 3 , PIN_IN_BLUETOOTH_SCO_HEADSET = 1 &lt;&lt; 27 \| 1 &lt;&lt; 4 , PIN_IN_DAUDIO_DEFAULT = 1 &lt;&lt; 27 \| 1 &lt;&lt; 5 , PIN_IN_USB_HEADSET = 1 &lt;&lt; 27 \| 1 &lt;&lt; 6<br/>} | 音频端口上的Pin脚。 | 
| [AudioCategory](#audiocategory) {<br/>AUDIO_IN_MEDIA = 0 , AUDIO_IN_COMMUNICATION = 1 , AUDIO_IN_RINGTONE = 2 , AUDIO_IN_CALL = 3 ,<br/>AUDIO_MMAP_NOIRQ = 4 , AUDIO_OFFLOAD = 5 , AUDIO_MULTI_CHANNEL = 6<br/>} | 音频类型（场景）。 | 
| [AudioFormat](#audioformat) {<br/>AUDIO_FORMAT_TYPE_PCM_8_BIT = 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_PCM_16_BIT = 1 &lt;&lt; 1 , AUDIO_FORMAT_TYPE_PCM_24_BIT = 1 &lt;&lt; 1 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_PCM_32_BIT = 1 &lt;&lt; 2 ,<br/>AUDIO_FORMAT_TYPE_PCM_FLOAT = 1 &lt;&lt; 2 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_MP3 = 1 &lt;&lt; 24 , AUDIO_FORMAT_TYPE_AAC_MAIN = 1 &lt;&lt; 24 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_AAC_LC = 1 &lt;&lt; 24 \| 1 &lt;&lt; 1 ,<br/>AUDIO_FORMAT_TYPE_AAC_LD = 1 &lt;&lt; 24 \| 1 &lt;&lt; 1 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_AAC_ELD = 1 &lt;&lt; 24 \| 1 &lt;&lt; 2 , AUDIO_FORMAT_TYPE_AAC_HE_V1 = 1 &lt;&lt; 24 \| 1 &lt;&lt; 2 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_AAC_HE_V2 = 1 &lt;&lt; 24 \| 1 &lt;&lt; 2 \| 1 &lt;&lt; 1 ,<br/>AUDIO_FORMAT_TYPE_G711A = 1 &lt;&lt; 25 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_G711U = 1 &lt;&lt; 25 \| 1 &lt;&lt; 1 , AUDIO_FORMAT_TYPE_G726 = 1 &lt;&lt; 25 \| 1 &lt;&lt; 1 \| 1 &lt;&lt; 0<br/>} | 音频格式。 | 
| [AudioChannelMask](#audiochannelmask) { AUDIO_CHANNEL_FRONT_LEFT = 1 , AUDIO_CHANNEL_FRONT_RIGHT = 2 , AUDIO_CHANNEL_MONO = 1 , AUDIO_CHANNEL_STEREO = 3 } | 音频通道掩码。 | 
| [AudioSampleRatesMask](#audiosampleratesmask) {<br/>AUDIO_SAMPLE_RATE_MASK_8000 = 1 &lt;&lt; 0 , AUDIO_SAMPLE_RATE_MASK_12000 = 1 &lt;&lt; 1 , AUDIO_SAMPLE_RATE_MASK_11025 = 1 &lt;&lt; 2 , AUDIO_SAMPLE_RATE_MASK_16000 = 1 &lt;&lt; 3 ,<br/>AUDIO_SAMPLE_RATE_MASK_22050 = 1 &lt;&lt; 4 , AUDIO_SAMPLE_RATE_MASK_24000 = 1 &lt;&lt; 5 , AUDIO_SAMPLE_RATE_MASK_32000 = 1 &lt;&lt; 6 , AUDIO_SAMPLE_RATE_MASK_44100 = 1 &lt;&lt; 7 ,<br/>AUDIO_SAMPLE_RATE_MASK_48000 = 1 &lt;&lt; 8 , AUDIO_SAMPLE_RATE_MASK_64000 = 1 &lt;&lt; 9 , AUDIO_SAMPLE_RATE_MASK_96000 = 1 &lt;&lt; 10 , AUDIO_SAMPLE_RATE_MASK_INVALID = 4294967295<br/>} | 音频采样频率掩码。 | 
| [AudioPortPassthroughMode](#audioportpassthroughmode) { PORT_PASSTHROUGH_LPCM = 1 &lt;&lt; 0 , PORT_PASSTHROUGH_RAW = 1 &lt;&lt; 1 , PORT_PASSTHROUGH_HBR2LBR = 1 &lt;&lt; 2 , PORT_PASSTHROUGH_AUTO = 1 &lt;&lt; 3 } | 音频端口的数据透传模式。 | 
| [AudioSampleFormat](#audiosampleformat) {<br/>AUDIO_SAMPLE_FORMAT_S8 = 0 , AUDIO_SAMPLE_FORMAT_S8P = 1 , AUDIO_SAMPLE_FORMAT_U8 = 2 , AUDIO_SAMPLE_FORMAT_U8P = 3 ,<br/>AUDIO_SAMPLE_FORMAT_S16 = 4 , AUDIO_SAMPLE_FORMAT_S16P = 5 , AUDIO_SAMPLE_FORMAT_U16 = 6 , AUDIO_SAMPLE_FORMAT_U16P = 7 ,<br/>AUDIO_SAMPLE_FORMAT_S24 = 8 , AUDIO_SAMPLE_FORMAT_S24P = 9 , AUDIO_SAMPLE_FORMAT_U24 = 10 , AUDIO_SAMPLE_FORMAT_U24P = 11 ,<br/>AUDIO_SAMPLE_FORMAT_S32 = 12 , AUDIO_SAMPLE_FORMAT_S32P = 13 , AUDIO_SAMPLE_FORMAT_U32 = 14 , AUDIO_SAMPLE_FORMAT_U32P = 15 ,<br/>AUDIO_SAMPLE_FORMAT_S64 = 16 , AUDIO_SAMPLE_FORMAT_S64P = 17 , AUDIO_SAMPLE_FORMAT_U64 = 18 , AUDIO_SAMPLE_FORMAT_U64P = 19 ,<br/>AUDIO_SAMPLE_FORMAT_F32 = 20 , AUDIO_SAMPLE_FORMAT_F32P = 21 , AUDIO_SAMPLE_FORMAT_F64 = 22 , AUDIO_SAMPLE_FORMAT_F64P = 23<br/>} | 原始音频样本格式。 | 
| [AudioChannelMode](#audiochannelmode) {<br/>AUDIO_CHANNEL_NORMAL = 0 , AUDIO_CHANNEL_BOTH_LEFT = 1 , AUDIO_CHANNEL_BOTH_RIGHT = 2 , AUDIO_CHANNEL_EXCHANGE = 3 , AUDIO_CHANNEL_MIX = 4 , AUDIO_CHANNEL_LEFT_MUTE = 5 , AUDIO_CHANNEL_RIGHT_MUTE = 6 , AUDIO_CHANNEL_BOTH_MUTE = 7<br/>} | 音频播放的通道模式。 | 
| [AudioDrainNotifyType](#audiodrainnotifytype) { AUDIO_DRAIN_NORMAL_MODE = 0 , AUDIO_DRAIN_EARLY_MODE = 1 } | 音频数据结束类型。 | 
| [AudioCallbackType](#audiocallbacktype) {<br/>AUDIO_NONBLOCK_WRITE_COMPELETED = 0 , AUDIO_DRAIN_COMPELETED = 1 , AUDIO_FLUSH_COMPLETED = 2 , AUDIO_RENDER_FULL = 3 ,<br/>AUDIO_ERROR_OCCUR = 4<br/>} | 回调函数通知事件类型。 | 
| [AudioPortRole](#audioportrole) { AUDIO_PORT_UNASSIGNED_ROLE = 0 , AUDIO_PORT_SOURCE_ROLE = 1 , AUDIO_PORT_SINK_ROLE = 2 } | 音频端口角色。 | 
| [AudioPortType](#audioporttype) { AUDIO_PORT_UNASSIGNED_TYPE = 0 , AUDIO_PORT_DEVICE_TYPE = 1 , AUDIO_PORT_MIX_TYPE = 2 , AUDIO_PORT_SESSION_TYPE = 3 } | 音频端口类型。 | 
| [AudioSessionType](#audiosessiontype) { AUDIO_OUTPUT_STAGE_SESSION = 0 , AUDIO_OUTPUT_MIX_SESSION = 1 , AUDIO_ALLOCATE_SESSION = 2 , AUDIO_INVALID_SESSION = 3 } | 端口会话类型。 | 
| [AudioDeviceType](#audiodevicetype) {<br/>AUDIO_LINEOUT = 1 &lt;&lt; 0 , AUDIO_HEADPHONE = 1 &lt;&lt; 1 , AUDIO_HEADSET = 1 &lt;&lt; 2 , AUDIO_USB_HEADSET = 1 &lt;&lt; 3 ,<br/>AUDIO_USB_HEADPHONE = 1 &lt;&lt; 4 , AUDIO_USBA_HEADSET = 1 &lt;&lt; 5 , AUDIO_USBA_HEADPHONE = 1 &lt;&lt; 6 , AUDIO_PRIMARY_DEVICE = 1 &lt;&lt; 7 ,<br/>AUDIO_USB_DEVICE = 1 &lt;&lt; 8 , AUDIO_A2DP_DEVICE = 1 &lt;&lt; 9 , AUDIO_HDMI_DEVICE = 1 &lt;&lt; 10 , AUDIO_ADAPTER_DEVICE = 1 &lt;&lt; 11 ,<br/>AUDIO_DEVICE_UNKOWN<br/>} | 音频设备类型。 | 
| [AudioEventType](#audioeventtype) {<br/>AUDIO_DEVICE_ADD = 1 , AUDIO_DEVICE_REMOVE = 2 , AUDIO_LOAD_SUCCESS = 3 , AUDIO_LOAD_FAILURE = 4 ,<br/>AUDIO_UNLOAD = 5 , AUDIO_SERVICE_VALID = 7 , AUDIO_SERVICE_INVALID = 8 , AUDIO_CAPTURE_THRESHOLD = 9 ,<br/>AUDIO_EVENT_UNKOWN = 10<br/>} | 音频事件类型。 | 
| [AudioExtParamKey](#audioextparamkey) {<br/>AUDIO_EXT_PARAM_KEY_NONE = 0 , AUDIO_EXT_PARAM_KEY_VOLUME = 1 , AUDIO_EXT_PARAM_KEY_FOCUS = 2 , AUDIO_EXT_PARAM_KEY_BUTTON = 3 ,<br/>AUDIO_EXT_PARAM_KEY_EFFECT = 4 , AUDIO_EXT_PARAM_KEY_STATUS = 5 ,&nbsp;&nbsp;AUDIO_EXT_PARAM_KEY_USB_DEVICE = 101 , AUDIO_EXT_PARAM_KEY_PERF_INFO = 201 ,<br/>AUDIO_EXT_PARAM_KEY_MMI = 301 , AUDIO_EXT_PARAM_KEY_LOWPOWER = 1000<br/>} | 音频扩展参数键类型。 | 
| [AudioInputType](#audioinputtype) {<br/>AUDIO_INPUT_DEFAULT_TYPE = 0 , AUDIO_INPUT_MIC_TYPE = 1 &lt;&lt; 0 , AUDIO_INPUT_SPEECH_WAKEUP_TYPE = 1 &lt;&lt; 1 , AUDIO_INPUT_VOICE_COMMUNICATION_TYPE = 1 &lt;&lt; 2 ,<br/>AUDIO_INPUT_VOICE_RECOGNITION_TYPE = 1 &lt;&lt; 3 ,<br/>} | 音频输入类型。 | 


## 枚举类型说明


### AudioCallbackType

```
enum AudioCallbackType
```

**描述**

回调函数通知事件类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_NONBLOCK_WRITE_COMPELETED | 非阻塞式写完成。 | 
| AUDIO_DRAIN_COMPELETED | DrainBuffer完成，详情参考[DrainBuffer](interface_i_audio_render_v10.md#drainbuffer)。 | 
| AUDIO_FLUSH_COMPLETED | Flush完成，详情参考[Flush](interface_i_audio_capture_v10.md#flush)。 | 
| AUDIO_RENDER_FULL | 录音缓冲区已满。 | 
| AUDIO_ERROR_OCCUR | 发生了错误。 | 


### AudioCategory

```
enum AudioCategory
```

**描述**

音频类型（场景）。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_IN_MEDIA | 媒体。 | 
| AUDIO_IN_COMMUNICATION | 通信。 | 
| AUDIO_IN_RINGTONE | 电话铃声。 | 
| AUDIO_IN_CALL | 呼叫。 | 
| AUDIO_MMAP_NOIRQ | Mmap模式。 | 
| AUDIO_OFFLOAD | 低功耗。 | 


### AudioChannelMask

```
enum AudioChannelMask
```

**描述**

音频通道掩码。

定义音频声道的位置掩码。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_CHANNEL_FRONT_LEFT | 声道布局前左。 | 
| AUDIO_CHANNEL_FRONT_RIGHT | 声道布局前右。 | 
| AUDIO_CHANNEL_MONO | 单声道。 | 
| AUDIO_CHANNEL_STEREO | 立体声，由左右声道组成。 | 


### AudioChannelMode

```
enum AudioChannelMode
```

**描述**

音频播放的通道模式。

**起始版本：** 4.0

**注意：**

下面的模式是针对双通道立体声的音频播放而设置，其他不支持。

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_CHANNEL_NORMAL | 正常模式，不做处理。 | 
| AUDIO_CHANNEL_BOTH_LEFT | 两个声道全部为左声道声音。 | 
| AUDIO_CHANNEL_BOTH_RIGHT | 两个声道全部为右声道声音。 | 
| AUDIO_CHANNEL_EXCHANGE | 左右声道数据互换，左声道为右声道声音，右声道为左声道声音。 | 
| AUDIO_CHANNEL_MIX | 左右两个声道输出为左右声道相加（混音）。 | 
| AUDIO_CHANNEL_LEFT_MUTE | 左声道静音，右声道播放原右声道声音。 | 
| AUDIO_CHANNEL_RIGHT_MUTE | 右声道静音，左声道播放原左声道声音。 | 
| AUDIO_CHANNEL_BOTH_MUTE | 左右声道均静音。 | 


### AudioDeviceType

```
enum AudioDeviceType
```

**描述**

音频设备类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_LINEOUT | LINEOUT设备。 | 
| AUDIO_HEADPHONE | 耳机。 | 
| AUDIO_HEADSET | 头戴式耳机。 | 
| AUDIO_USB_HEADSET | USB头戴式耳机。 | 
| AUDIO_USB_HEADPHONE | USB耳机。 | 
| AUDIO_USBA_HEADSET | USB模拟头戴式耳机。 | 
| AUDIO_USBA_HEADPHONE | USB模拟耳机。 | 
| AUDIO_PRIMARY_DEVICE | 主音频设备。 | 
| AUDIO_USB_DEVICE | USB音频设备。 | 
| AUDIO_A2DP_DEVICE | 蓝牙音频设备。 | 
| AUDIO_HDMI_DEVICE | HDMI音频设备。 | 
| AUDIO_ADAPTER_DEVICE | 声卡设备。 | 
| AUDIO_DEVICE_UNKNOWN | 未知设备。 | 


### AudioDrainNotifyType

```
enum AudioDrainNotifyType
```

**描述**

音频数据结束类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DRAIN_NORMAL_MODE | 曲目的所有数据播放完就结束。 | 
| AUDIO_DRAIN_EARLY_MODE | 曲目的所有数据未播放完就结束，以便给音频服务做连续性曲目切换留出时间。 | 


### AudioEventType

```
enum AudioEventType
```

**描述**

音频事件类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_DEVICE_ADD | 音频设备添加。 | 
| AUDIO_DEVICE_REMOVE | 音频设备移除。 | 
| AUDIO_LOAD_SUCCESS | 声卡加载成功。 | 
| AUDIO_LOAD_FAILURE | 声卡加载失败。 | 
| AUDIO_UNLOAD | 声卡卸载。 | 
| AUDIO_SERVICE_VALID | 音频服务可用。 | 
| AUDIO_SERVICE_INVALID | 音频服务不可用。 | 
| AUDIO_CAPTURE_THRESHOLD | 录音阈值上报。 | 
| AUDIO_EVENT_UNKNOWN | 未知事件。 | 


### AudioExtParamKey

```
enum AudioExtParamKey
```

**描述**

音频扩展参数键类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_EXT_PARAM_KEY_NONE | 分布式音频-无效事件。 | 
| AUDIO_EXT_PARAM_KEY_VOLUME | 分布式音频-音量事件。 | 
| AUDIO_EXT_PARAM_KEY_FOCUS | 分布式音频-焦点事件。 | 
| AUDIO_EXT_PARAM_KEY_BUTTON | 分布式音频-媒体按钮事件。 | 
| AUDIO_EXT_PARAM_KEY_EFFECT | 分布式音频-音频效果事件。 | 
| AUDIO_EXT_PARAM_KEY_STATUS | 分布式音频-设备状态事件。 | 
| AUDIO_EXT_PARAM_KEY_USB_DEVICE | USB设备类型（ ARM 或 HIFI）。 | 
| AUDIO_EXT_PARAM_KEY_PERF_INFO | 分布式音频-dsp加载事件。 | 
| AUDIO_EXT_PARAM_KEY_LOWPOWER | 低电量事件。 | 


### AudioFormat

```
enum AudioFormat
```

**描述**

音频格式。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_FORMAT_TYPE_PCM_8_BIT | 8bit位宽PCM（Pulse Code Modulation）格式。 | 
| AUDIO_FORMAT_TYPE_PCM_16_BIT | 16bit位宽PCM格式。 | 
| AUDIO_FORMAT_TYPE_PCM_24_BIT | 24bit位宽PCM格式。 | 
| AUDIO_FORMAT_TYPE_PCM_32_BIT | 32bit位宽PCM格式。 | 
| AUDIO_FORMAT_TYPE_PCM_FLOAT | PCM浮点格式 | 
| AUDIO_FORMAT_TYPE_MP3 | MP3格式 | 
| AUDIO_FORMAT_TYPE_AAC_MAIN | AAC main格式 | 
| AUDIO_FORMAT_TYPE_AAC_LC | AAC LC格式 | 
| AUDIO_FORMAT_TYPE_AAC_LD | AAC LD格式 | 
| AUDIO_FORMAT_TYPE_AAC_ELD | AAC ELD格式 | 
| AUDIO_FORMAT_TYPE_AAC_HE_V1 | AAC HE_V1格式 | 
| AUDIO_FORMAT_TYPE_AAC_HE_V2 | AAC HE_V2格式 | 
| AUDIO_FORMAT_TYPE_G711A | PCM G711A格式 | 
| AUDIO_FORMAT_TYPE_G711U | PCM G711u格式 | 
| AUDIO_FORMAT_TYPE_G726 | PCM G726格式 | 


### AudioInputType

```
enum AudioInputType
```

**描述**

音频输入类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_INPUT_DEFAULT_TYPE | 默认输入 | 
| AUDIO_INPUT_MIC_TYPE | 麦克风输入 | 
| AUDIO_INPUT_SPEECH_WAKEUP_TYPE | 语音唤醒输入 | 
| AUDIO_INPUT_VOICE_COMMUNICATION_TYPE | 通话 | 
| AUDIO_INPUT_VOICE_RECOGNITION_TYPE | 声音识别 | 


### AudioPortDirection

```
enum AudioPortDirection
```

**描述**

音频端口的类型。

package ohos.hdi.audio.v1_0;

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| PORT_OUT | 音频输出端口。 | 
| PORT_IN | 音频输入端口。 | 
| PORT_OUT_IN | 音频输出输入端口。 | 


### AudioPortPassthroughMode

```
enum AudioPortPassthroughMode
```

**描述**

音频端口的数据透传模式。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| PORT_PASSTHROUGH_LPCM | 立体声PCM。 | 
| PORT_PASSTHROUGH_RAW | HDMI透传。 | 
| PORT_PASSTHROUGH_HBR2LBR | 蓝光次世代音频降规格输出。 | 
| PORT_PASSTHROUGH_AUTO | 根据HDMI EDID能力自动匹配。 | 


### AudioPortPin

```
enum AudioPortPin
```

**描述**

音频端口上的Pin脚。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| PIN_NONE | 无效端口。 | 
| PIN_OUT_SPEAKER | 喇叭输出。 | 
| PIN_OUT_HEADSET | 有线耳机输出。 | 
| PIN_OUT_LINEOUT | Lineout输出。 | 
| PIN_OUT_HDMI | HDMI输出。 | 
| PIN_OUT_USB | USB输出。 | 
| PIN_OUT_USB_EXT | USB外部声卡输出。 | 
| PIN_OUT_EARPIECE | 有线耳机输出。 | 
| PIN_OUT_BLUETOOTH_SCO | 蓝牙SCO输出 | 
| PIN_OUT_DAUDIO_DEFAULT | 音频默认输出 | 
| PIN_OUT_HEADPHONE | 有线耳机输出。 | 
| PIN_OUT_USB_HEADSET | ARM USB输出 | 
| PIN_IN_MIC | 麦克风输入 | 
| PIN_IN_HS_MIC | 耳机麦克风输入 | 
| PIN_IN_LINEIN | Linein输入。 | 
| PIN_IN_USB_EXT | USB外部声卡输入。 | 
| PIN_IN_BLUETOOTH_SCO_HEADSET | 蓝牙SCO耳机输入 | 
| PIN_IN_DAUDIO_DEFAULT | 音频默认输入 | 
| PIN_IN_USB_HEADSET | ARM USB输入 | 


### AudioPortRole

```
enum AudioPortRole
```

**描述**

音频端口角色。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_PORT_UNASSIGNED_ROLE | 未指定端口角色。 | 
| AUDIO_PORT_SOURCE_ROLE | 指定端口为发送端角色。 | 
| AUDIO_PORT_SINK_ROLE | 指定端口为接受端角色。 | 


### AudioPortType

```
enum AudioPortType
```

**描述**

音频端口类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_PORT_UNASSIGNED_TYPE | 未指定端口类型。 | 
| AUDIO_PORT_DEVICE_TYPE | 指定端口为设备类型。 | 
| AUDIO_PORT_MIX_TYPE | 指定端口为复合类型。 | 
| AUDIO_PORT_SESSION_TYPE | 指定端口为会话类型。 | 


### AudioSampleFormat

```
enum AudioSampleFormat
```

**描述**

原始音频样本格式。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_FORMAT_S8 | 8bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S8P | 8bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U8 | 8bit位宽无符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U8P | 8bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S16 | 16bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S16P | 16bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U16 | 16bit位宽无符号符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U16P | 16bit位宽无符号符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S24 | 24bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S24P | 24bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U24 | 24bit位宽无符号符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U24P | 24bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S32 | 32bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S32P | 32bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U32 | 32bit位宽无符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U32P | 32bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S64 | 64bit位宽有符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_S64P | 64bit位宽有符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U64 | 64bit位宽无符号交织样本。 | 
| AUDIO_SAMPLE_FORMAT_U64P | 64bit位宽无符号非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_F32 | 32bit位宽浮点型交织样本。 | 
| AUDIO_SAMPLE_FORMAT_F32P | 32bit位宽浮点型非交织样本。 | 
| AUDIO_SAMPLE_FORMAT_F64 | 64bit位宽双精度浮点型交织样本。 | 
| AUDIO_SAMPLE_FORMAT_F64P | 64bit位宽双精度浮点型非交织样本。 | 


### AudioSampleRatesMask

```
enum AudioSampleRatesMask
```

**描述**

音频采样频率掩码。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_SAMPLE_RATE_MASK_8000 | 8K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_12000 | 12K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_11025 | 11.025K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_16000 | 16K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_22050 | 22.050K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_24000 | 24K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_32000 | 32K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_44100 | 44.1K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_48000 | 48K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_64000 | 64K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_96000 | 96K 采样频率。 | 
| AUDIO_SAMPLE_RATE_MASK_INVALID | 无效的采样频率。 | 


### AudioSessionType

```
enum AudioSessionType
```

**描述**

端口会话类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_OUTPUT_STAGE_SESSION | 会话绑定到指定输出流。 | 
| AUDIO_OUTPUT_MIX_SESSION | 会话绑定到特定音轨。 | 
| AUDIO_ALLOCATE_SESSION | 会话ID需重新申请。 | 
| AUDIO_INVALID_SESSION | 无效会话类型。 | 
