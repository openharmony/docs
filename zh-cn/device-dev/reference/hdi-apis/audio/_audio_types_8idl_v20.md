# AudioTypes.idl


## 概述

Audio模块接口定义中使用的数据类型。

Audio模块接口定义中使用的数据类型，包括音频端口、适配器描述符、设备描述符、场景描述符、采样属性、时间戳等。

模块包路径：ohos.hdi.audio.v2_0

**起始版本：** 4.1

**相关模块：**[HdiAudio](_hdi_audio_v20.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[AudioDeviceStatus](_audio_device_status_v20.md) | 音频设备状态。 | 
| union&nbsp;&nbsp;[SceneDesc](union_scene_desc_v20.md) | 音频场景描述。 | 
| struct&nbsp;&nbsp;[AudioPort](_audio_port_v20.md) | 音频端口。 | 
| struct&nbsp;&nbsp;[AudioAdapterDescriptor](_audio_adapter_descriptor_v20.md) | 音频适配器描述符。 | 
| struct&nbsp;&nbsp;[AudioDeviceDescriptor](_audio_device_descriptor_v20.md) | 音频设备描述符。 | 
| struct&nbsp;&nbsp;[AudioSceneDescriptor](_audio_scene_descriptor_v20.md) | 音频场景描述符。 | 
| struct&nbsp;&nbsp;[AudioOffloadInfo](_audio_offload_info_v20.md) | 音频低功耗属性 | 
| struct&nbsp;&nbsp;[AudioSampleAttributes](_audio_sample_attributes_v20.md) | 音频采样属性。 | 
| struct&nbsp;&nbsp;[AudioTimeStamp](_audio_time_stamp_v20.md) | 音频时间戳。 | 
| struct&nbsp;&nbsp;[AudioSubPortCapability](_audio_sub_port_capability_v20.md) | 音频子端口的支持能力。 | 
| struct&nbsp;&nbsp;[AudioPortCapability](_audio_port_capability_v20.md) | 音频端口的支持能力。 | 
| struct&nbsp;&nbsp;[AudioMmapBufferDescripter](_audio_mmap_buffer_descripter_v20.md) | mmap缓冲区描述符。 | 
| struct&nbsp;&nbsp;[AudioDevExtInfo](_audio_dev_ext_info_v20.md) | 音频设备拓展信息。 | 
| struct&nbsp;&nbsp;[AudioMixExtInfo](_audio_mix_ext_info_v20.md) | 音轨拓展信息。 | 
| struct&nbsp;&nbsp;[AudioSessionExtInfo](_audio_session_ext_info_v20.md) | 会话拓展信息。 | 
| struct&nbsp;&nbsp;[AudioInfo](_audio_info_v20.md) | 音频端口特定信息。 | 
| struct&nbsp;&nbsp;[AudioRouteNode](_audio_route_node_v20.md) | 音频路由节点。 | 
| struct&nbsp;&nbsp;[AudioRoute](_audio_route_v20.md) | 音频路由信息。 | 
| struct&nbsp;&nbsp;[AudioEvent](_audio_event_v20.md) | 音频事件。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AudioPortDirection](_hdi_audio_v20.md#audioportdirection) { PORT_OUT = 1 , PORT_IN = 2 , PORT_OUT_IN = 3 } | 音频端口的类型。 | 
| [AudioPortPin](_hdi_audio_v20.md#audioportpin) {<br/>PIN_NONE = 0 , PIN_OUT_SPEAKER = 1 &lt;&lt; 0 , PIN_OUT_HEADSET = 1 &lt;&lt; 1 , PIN_OUT_LINEOUT = 1 &lt;&lt; 2 ,<br/>PIN_OUT_HDMI&nbsp;&nbsp;= 1 &lt;&lt; 3 , PIN_OUT_USB = 1 &lt;&lt; 4 , PIN_OUT_USB_EXT = 1 &lt;&lt; 5 , PIN_OUT_EARPIECE = 1 &lt;&lt; 5 \| 1 &lt;&lt; 4 ,<br/>PIN_OUT_BLUETOOTH_SCO = 1 &lt;&lt; 6 , PIN_OUT_DAUDIO_DEFAULT = 1 &lt;&lt; 7 , PIN_OUT_HEADPHONE = 1 &lt;&lt; 8 , PIN_OUT_USB_HEADSET = 1 &lt;&lt; 9 ,<br/>PIN_OUT_BLUETOOTH_A2DP = 1 &lt;&lt; 10 , PIN_IN_MIC = 1 &lt;&lt; 27 \| 1 &lt;&lt; 0 , PIN_IN_HS_MIC = 1 &lt;&lt; 27 \| 1 &lt;&lt; 1 , PIN_IN_LINEIN = 1 &lt;&lt; 27 \| 1 &lt;&lt; 2 ,<br/>PIN_IN_USB_EXT = 1 &lt;&lt; 27 \| 1 &lt;&lt; 3 , PIN_IN_BLUETOOTH_SCO_HEADSET = 1 &lt;&lt; 27 \| 1 &lt;&lt; 4 , PIN_IN_DAUDIO_DEFAULT = 1 &lt;&lt; 27 \| 1 &lt;&lt; 5 , PIN_IN_USB_HEADSET = 1 &lt;&lt; 27 \| 1 &lt;&lt; 6<br/>} | 音频端口上的Pin脚。 | 
| [AudioCategory](_hdi_audio_v20.md#audiocategory) {<br/>AUDIO_IN_MEDIA = 0 , AUDIO_IN_COMMUNICATION = 1 , AUDIO_IN_RINGTONE = 2 , AUDIO_IN_CALL = 3 ,<br/>AUDIO_MMAP_NOIRQ = 4 , AUDIO_OFFLOAD = 5 , AUDIO_MULTI_CHANNEL = 6<br/>} | 音频类型（场景）。 | 
| [AudioFormat](_hdi_audio_v20.md#audioformat) {<br/>AUDIO_FORMAT_TYPE_PCM_8_BIT = 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_PCM_16_BIT = 1 &lt;&lt; 1 , AUDIO_FORMAT_TYPE_PCM_24_BIT = 1 &lt;&lt; 1 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_PCM_32_BIT = 1 &lt;&lt; 2 ,<br/>AUDIO_FORMAT_TYPE_PCM_FLOAT = 1 &lt;&lt; 2 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_MP3 = 1 &lt;&lt; 24 , AUDIO_FORMAT_TYPE_AAC_MAIN = 1 &lt;&lt; 24 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_AAC_LC = 1 &lt;&lt; 24 \| 1 &lt;&lt; 1 ,<br/>AUDIO_FORMAT_TYPE_AAC_LD = 1 &lt;&lt; 24 \| 1 &lt;&lt; 1 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_AAC_ELD = 1 &lt;&lt; 24 \| 1 &lt;&lt; 2 , AUDIO_FORMAT_TYPE_AAC_HE_V1 = 1 &lt;&lt; 24 \| 1 &lt;&lt; 2 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_AAC_HE_V2 = 1 &lt;&lt; 24 \| 1 &lt;&lt; 2 \| 1 &lt;&lt; 1 ,<br/>AUDIO_FORMAT_TYPE_G711A = 1 &lt;&lt; 25 \| 1 &lt;&lt; 0 , AUDIO_FORMAT_TYPE_G711U = 1 &lt;&lt; 25 \| 1 &lt;&lt; 1 , AUDIO_FORMAT_TYPE_G726 = 1 &lt;&lt; 25 \| 1 &lt;&lt; 1 \| 1 &lt;&lt; 0<br/>} | 音频格式。 | 
| [AudioChannelMask](_hdi_audio_v20.md#audiochannelmask) { AUDIO_CHANNEL_FRONT_LEFT = 1 , AUDIO_CHANNEL_FRONT_RIGHT = 2 , AUDIO_CHANNEL_MONO = 1 , AUDIO_CHANNEL_STEREO = 3 } | 音频通道掩码。 | 
| [AudioSampleRatesMask](_hdi_audio_v20.md#audiosampleratesmask) {<br/>AUDIO_SAMPLE_RATE_MASK_8000 = 1 &lt;&lt; 0 , AUDIO_SAMPLE_RATE_MASK_12000 = 1 &lt;&lt; 1 , AUDIO_SAMPLE_RATE_MASK_11025 = 1 &lt;&lt; 2 , AUDIO_SAMPLE_RATE_MASK_16000 = 1 &lt;&lt; 3 ,<br/>AUDIO_SAMPLE_RATE_MASK_22050 = 1 &lt;&lt; 4 , AUDIO_SAMPLE_RATE_MASK_24000 = 1 &lt;&lt; 5 , AUDIO_SAMPLE_RATE_MASK_32000 = 1 &lt;&lt; 6 , AUDIO_SAMPLE_RATE_MASK_44100 = 1 &lt;&lt; 7 ,<br/>AUDIO_SAMPLE_RATE_MASK_48000 = 1 &lt;&lt; 8 , AUDIO_SAMPLE_RATE_MASK_64000 = 1 &lt;&lt; 9 , AUDIO_SAMPLE_RATE_MASK_96000 = 1 &lt;&lt; 10 , AUDIO_SAMPLE_RATE_MASK_INVALID = 4294967295<br/>} | 音频采样频率掩码。 | 
| [AudioPortPassthroughMode](_hdi_audio_v20.md#audioportpassthroughmode) { PORT_PASSTHROUGH_LPCM = 1 &lt;&lt; 0 , PORT_PASSTHROUGH_RAW = 1 &lt;&lt; 1 , PORT_PASSTHROUGH_HBR2LBR = 1 &lt;&lt; 2 , PORT_PASSTHROUGH_AUTO = 1 &lt;&lt; 3 } | 音频端口的数据透传模式。 | 
| [AudioSampleFormat](_hdi_audio_v20.md#audiosampleformat) {<br/>AUDIO_SAMPLE_FORMAT_S8 = 0 , AUDIO_SAMPLE_FORMAT_S8P = 1 , AUDIO_SAMPLE_FORMAT_U8 = 2 , AUDIO_SAMPLE_FORMAT_U8P = 3 ,<br/>AUDIO_SAMPLE_FORMAT_S16 = 4 , AUDIO_SAMPLE_FORMAT_S16P = 5 , AUDIO_SAMPLE_FORMAT_U16 = 6 , AUDIO_SAMPLE_FORMAT_U16P = 7 ,<br/>AUDIO_SAMPLE_FORMAT_S24 = 8 , AUDIO_SAMPLE_FORMAT_S24P = 9 , AUDIO_SAMPLE_FORMAT_U24 = 10 , AUDIO_SAMPLE_FORMAT_U24P = 11 ,<br/>AUDIO_SAMPLE_FORMAT_S32 = 12 , AUDIO_SAMPLE_FORMAT_S32P = 13 , AUDIO_SAMPLE_FORMAT_U32 = 14 , AUDIO_SAMPLE_FORMAT_U32P = 15 ,<br/>AUDIO_SAMPLE_FORMAT_S64 = 16 , AUDIO_SAMPLE_FORMAT_S64P = 17 , AUDIO_SAMPLE_FORMAT_U64 = 18 , AUDIO_SAMPLE_FORMAT_U64P = 19 ,<br/>AUDIO_SAMPLE_FORMAT_F32 = 20 , AUDIO_SAMPLE_FORMAT_F32P = 21 , AUDIO_SAMPLE_FORMAT_F64 = 22 , AUDIO_SAMPLE_FORMAT_F64P = 23<br/>} | 原始音频样本格式。 | 
| [AudioChannelMode](_hdi_audio_v20.md#audiochannelmode) {<br/>AUDIO_CHANNEL_NORMAL = 0 , AUDIO_CHANNEL_BOTH_LEFT = 1 , AUDIO_CHANNEL_BOTH_RIGHT = 2 , AUDIO_CHANNEL_EXCHANGE = 3 , AUDIO_CHANNEL_MIX = 4 , AUDIO_CHANNEL_LEFT_MUTE = 5 , AUDIO_CHANNEL_RIGHT_MUTE = 6 , AUDIO_CHANNEL_BOTH_MUTE = 7<br/>} | 音频播放的通道模式。 | 
| [AudioDrainNotifyType](_hdi_audio_v20.md#audiodrainnotifytype) { AUDIO_DRAIN_NORMAL_MODE = 0 , AUDIO_DRAIN_EARLY_MODE = 1 } | 音频数据结束类型。 | 
| [AudioCallbackType](_hdi_audio_v20.md#audiocallbacktype) {<br/>AUDIO_NONBLOCK_WRITE_COMPELETED = 0 , AUDIO_DRAIN_COMPELETED = 1 , AUDIO_FLUSH_COMPLETED = 2 , AUDIO_RENDER_FULL = 3 ,<br/>AUDIO_ERROR_OCCUR = 4<br/>} | 回调函数通知事件类型。 | 
| [AudioPortRole](_hdi_audio_v20.md#audioportrole) { AUDIO_PORT_UNASSIGNED_ROLE = 0 , AUDIO_PORT_SOURCE_ROLE = 1 , AUDIO_PORT_SINK_ROLE = 2 } | 音频端口角色。 | 
| [AudioPortType](_hdi_audio_v20.md#audioporttype) { AUDIO_PORT_UNASSIGNED_TYPE = 0 , AUDIO_PORT_DEVICE_TYPE = 1 , AUDIO_PORT_MIX_TYPE = 2 , AUDIO_PORT_SESSION_TYPE = 3 } | 音频端口类型。 | 
| [AudioSessionType](_hdi_audio_v20.md#audiosessiontype) { AUDIO_OUTPUT_STAGE_SESSION = 0 , AUDIO_OUTPUT_MIX_SESSION = 1 , AUDIO_ALLOCATE_SESSION = 2 , AUDIO_INVALID_SESSION = 3 } | 端口会话类型。 | 
| [AudioDeviceType](_hdi_audio_v20.md#audiodevicetype) {<br/>AUDIO_LINEOUT = 1 &lt;&lt; 0 , AUDIO_HEADPHONE = 1 &lt;&lt; 1 , AUDIO_HEADSET = 1 &lt;&lt; 2 , AUDIO_USB_HEADSET = 1 &lt;&lt; 3 ,<br/>AUDIO_USB_HEADPHONE = 1 &lt;&lt; 4 , AUDIO_USBA_HEADSET = 1 &lt;&lt; 5 , AUDIO_USBA_HEADPHONE = 1 &lt;&lt; 6 , AUDIO_PRIMARY_DEVICE = 1 &lt;&lt; 7 , AUDIO_USB_DEVICE = 1 &lt;&lt; 8 , AUDIO_A2DP_DEVICE = 1 &lt;&lt; 9 ,&nbsp;&nbsp;AUDIO_HDMI_DEVICE = 1 &lt;&lt; 10 , AUDIO_ADAPTER_DEVICE = 1 &lt;&lt; 11 , AUDIO_DEVICE_UNKOWN<br/>} | 音频设备类型。 | 
| [AudioEventType](_hdi_audio_v20.md#audioeventtype) {<br/>AUDIO_DEVICE_ADD = 1 , AUDIO_DEVICE_REMOVE = 2 , AUDIO_LOAD_SUCCESS = 3 , AUDIO_LOAD_FAILURE = 4 ,<br/>AUDIO_UNLOAD = 5 , AUDIO_SERVICE_VALID = 7 , AUDIO_SERVICE_INVALID = 8 , AUDIO_CAPTURE_THRESHOLD = 9 , AUDIO_EVENT_UNKOWN = 10<br/>} | 音频事件类型。 | 
| [AudioExtParamKey](_hdi_audio_v20.md#audioextparamkey) {<br/>AUDIO_EXT_PARAM_KEY_NONE = 0 , AUDIO_EXT_PARAM_KEY_VOLUME = 1 , AUDIO_EXT_PARAM_KEY_FOCUS = 2 , AUDIO_EXT_PARAM_KEY_BUTTON = 3 ,<br/>AUDIO_EXT_PARAM_KEY_EFFECT = 4 , AUDIO_EXT_PARAM_KEY_STATUS = 5 ,&nbsp;&nbsp;AUDIO_EXT_PARAM_KEY_USB_DEVICE = 101 , AUDIO_EXT_PARAM_KEY_PERF_INFO = 201 ,<br/>AUDIO_EXT_PARAM_KEY_MMI = 301 , AUDIO_EXT_PARAM_KEY_LOWPOWER = 1000<br/>} | 音频扩展参数键类型。 | 
| [AudioInputType](_hdi_audio_v20.md#audioinputtype) {<br/>AUDIO_INPUT_DEFAULT_TYPE = 0 , AUDIO_INPUT_MIC_TYPE = 1 &lt;&lt; 0 , AUDIO_INPUT_SPEECH_WAKEUP_TYPE = 1 &lt;&lt; 1 , AUDIO_INPUT_VOICE_COMMUNICATION_TYPE = 1 &lt;&lt; 2 ,<br/>AUDIO_INPUT_VOICE_RECOGNITION_TYPE = 1 &lt;&lt; 3 , AUDIO_INPUT_VOICE_UPLINK_TYPE = 1 &lt;&lt; 4 , AUDIO_INPUT_VOICE_DOWNLINK_TYPE = 1 &lt;&lt; 5 , AUDIO_INPUT_VOICE_CALL_TYPE = 1 &lt;&lt; 6 ,<br/>AUDIO_INPUT_CAMCORDER_TYPE = 1 &lt;&lt; 7<br/>} | 音频输入类型. | 
