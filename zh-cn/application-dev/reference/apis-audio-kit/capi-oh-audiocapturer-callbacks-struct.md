# OH_AudioCapturer_Callbacks_Struct

## 概述

声明输入音频流的回调函数指针。

**起始版本：** 10

**废弃版本：** 18

**替代接口：** 请分别使用以下回调类型：

**相关模块：** [OHAudio](capi-ohaudio.md)

**所在头文件：** [native_audiostream_base.h](capi-native-audiostream-base-h.md)

## 汇总

### 成员函数

| 名称 | 描述 |
| -- | -- |
| [int32_t (\*OH_AudioCapturer_OnReadData)(OH_AudioCapturer* capturer,void* userData,void* buffer,int32_t length)](#oh_audiocapturer_onreaddata) | 这个函数指针将指向用于读取音频数据的回调函数。<br>**起始版本：** 10<br>**废弃版本：** 18<br>**替代接口：** OH_AudioCapturer_OnReadDataCallback |
| [int32_t (\*OH_AudioCapturer_OnStreamEvent)(OH_AudioCapturer* capturer,void* userData,OH_AudioStream_Event event)](#oh_audiocapturer_onstreamevent) | 这个函数指针将指向用于处理音频录制流事件的回调函数。<br>**起始版本：** 10<br>**废弃版本：** 18<br>**替代接口：** OH_AudioCapturer_OnDeviceChangeCallback |
| [int32_t (\*OH_AudioCapturer_OnInterruptEvent)(OH_AudioCapturer* capturer,void* userData,OH_AudioInterrupt_ForceType type,OH_AudioInterrupt_Hint hint)](#oh_audiocapturer_oninterruptevent) | 这个函数指针将指向用于处理音频录制中断事件的回调函数。<br>**起始版本：** 10<br>**废弃版本：** 18<br>**替代接口：** OH_AudioCapturer_OnInterruptCallback |

## 成员函数说明

### OH_AudioCapturer_OnReadData()

```
int32_t (*OH_AudioCapturer_OnReadData)(OH_AudioCapturer* capturer,void* userData,void* buffer,int32_t length)
```

**描述**

这个函数指针将指向用于读取音频数据的回调函数。

**起始版本：** 10

**废弃版本：** 18

**替代接口：** OH_AudioCapturer_OnReadDataCallback

**参数：**

| 参数项 | 描述                                                                                                                              |
| -- |---------------------------------------------------------------------------------------------------------------------------------|
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| void* userData | 指向应用自定义的数据存储区域。                                                                                                                 |
| void* buffer | 指向播放数据存储区域，用于应用填充播放数据。                                                                                                          |
| int32_t length | buffer的长度。                                                                                                                      |

### OH_AudioCapturer_OnStreamEvent()

```
int32_t (*OH_AudioCapturer_OnStreamEvent)(OH_AudioCapturer* capturer,void* userData,OH_AudioStream_Event event)
```

**描述**

这个函数指针将指向用于处理音频录制流事件的回调函数。

**起始版本：** 10

**废弃版本：** 18

**替代接口：** OH_AudioCapturer_OnDeviceChangeCallback

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioStream_Event](capi-native-audiostream-base-h#oh_audiostream_event) event | 音频事件[OH_AudioStream_Event](capi-native-audiostream-base-h.md#oh_audiostream_)。 |

### OH_AudioCapturer_OnInterruptEvent()

```
int32_t (*OH_AudioCapturer_OnInterruptEvent)(OH_AudioCapturer* capturer,void* userData,OH_AudioInterrupt_ForceType type,OH_AudioInterrupt_Hint hint)
```

**描述**

这个函数指针将指向用于处理音频录制中断事件的回调函数。

**起始版本：** 10

**废弃版本：** 18

**替代接口：** OH_AudioCapturer_OnInterruptCallback

**参数：**

| 参数项                                                                                               | 描述 |
|---------------------------------------------------------------------------------------------------| -- |
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer                                      | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| void* userData                                                                                    | 指向应用自定义的数据存储区域。 |
| [OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | 音频中断类型[OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_force)。 |
| [OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint           | 音频中断提示类型[OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_)。 |


