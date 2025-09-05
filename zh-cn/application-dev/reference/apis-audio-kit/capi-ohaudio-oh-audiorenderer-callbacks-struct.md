# OH_AudioRenderer_Callbacks_Struct
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## 概述

声明输出音频流的回调函数指针。

为了避免不可预期的行为，在设置音频回调函数时，请确保该结构体的每一个成员变量都被自定义的回调方法或空指针初始化。

可参考[使用OHAudio开发音频播放功能](../../media/audio/using-ohaudio-for-playback.md)。

**起始版本：** 10

**废弃版本：** 20

**替代接口：**

请分别使用以下回调类型替代：

[OH_AudioRenderer_OnWriteDataCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback)、 [OH_AudioRenderer_OutputDeviceChangeCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_outputdevicechangecallback)、 [OH_AudioRenderer_OnInterruptCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_oninterruptcallback) 以及 [OH_AudioRenderer_OnErrorCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_onerrorcallback)。

**相关模块：** [OHAudio](capi-ohaudio.md)

**所在头文件：** [native_audiostream_base.h](capi-native-audiostream-base-h.md)

## 汇总

### 成员函数

| 名称 | 描述 |
| -- | -- |
| [int32_t (\*OH_AudioRenderer_OnWriteData)(OH_AudioRenderer* renderer, void* userData, void* buffer, int32_t length)](#oh_audiorenderer_onwritedata) | 该函数指针将指向用于写入音频数据的回调函数。 |
| [int32_t (\*OH_AudioRenderer_OnStreamEvent)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_Event event)](#oh_audiorenderer_onstreamevent) | 该函数指针将指向用于处理音频播放流事件的回调函数。 |
| [int32_t (\*OH_AudioRenderer_OnInterruptEvent)(OH_AudioRenderer* renderer, void* userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)](#oh_audiorenderer_oninterruptevent) | 该函数指针将指向用于处理音频播放中断事件的回调函数。 |
| [int32_t (\*OH_AudioRenderer_OnError)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_Result error)](#oh_audiorenderer_onerror) | 该函数指针将指向用于处理音频播放错误结果的回调函数。 |

## 成员函数说明

> **说明：**
> 以下回调接口的返回值没有枚举定义，当前版本实现并不按返回值区分处理，但为保证后续版本可扩展，默认使用0。

### OH_AudioRenderer_OnWriteData()

```
int32_t (*OH_AudioRenderer_OnWriteData)(OH_AudioRenderer* renderer, void* userData, void* buffer, int32_t length)
```

**描述**

该函数指针将指向用于写入音频数据的回调函数。<br> 回调函数仅用来写入音频数据，请勿在回调函数中调用AudioRenderer相关接口。<br> 回调函数结束后，音频服务会把buffer指针数据放入队列里等待播放，因此请勿在回调外再次更改buffer指向的数据，且务必保证往buffer填满length长度的待播放数据，否则会导致音频服务播放杂音。

**起始版本：** 10

**废弃版本：** 20

**替代接口：** [OH_AudioRenderer_OnWriteDataCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| void* userData | 指向应用自定义的数据存储区域。 |
| void* buffer | 指向播放数据存储区域，用于应用填充播放数据。 |
| int32_t length | buffer的长度。 |

### OH_AudioRenderer_OnStreamEvent()

```
int32_t (*OH_AudioRenderer_OnStreamEvent)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_Event event)
```

**描述**

该函数指针将指向用于处理音频播放流事件的回调函数。

OH_AudioRenderer_OnStreamEvent无触发回调场景，为预留接口。从API 11开始，开发者如果需要监听设备变化，可直接使用[OH_AudioRenderer_OutputDeviceChangeCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_outputdevicechangecallback)替代。

**起始版本：** 10

**废弃版本：** 20

**替代接口：** [OH_AudioRenderer_OutputDeviceChangeCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_outputdevicechangecallback)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioStream_Event](capi-native-audiostream-base-h.md#oh_audiostream_event) event | 音频事件。 |

### OH_AudioRenderer_OnInterruptEvent()

```
int32_t (*OH_AudioRenderer_OnInterruptEvent)(OH_AudioRenderer* renderer, void* userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**描述**

该函数指针将指向用于处理音频播放中断事件的回调函数。

**起始版本：** 10

**废弃版本：** 20

**替代接口：** [OH_AudioRenderer_OnInterruptCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_oninterruptcallback)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | 音频中断类型。 |
| [OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint | 音频中断提示类型。 |

### OH_AudioRenderer_OnError()

```
int32_t (*OH_AudioRenderer_OnError)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_Result error)
```

**描述**

该函数指针将指向用于处理音频播放错误结果的回调函数。

**起始版本：** 10

**废弃版本：** 20

**替代接口：** [OH_AudioRenderer_OnErrorCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_onerrorcallback)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) error | 音频播放错误结果，可能为AUDIOSTREAM_ERROR_INVALID_PARAM、AUDIOSTREAM_ERROR_ILLEGAL_STATE或者AUDIOSTREAM_ERROR_SYSTEM。 |


