# OH_AudioCapturer_Callbacks_Struct


## 概述

声明输入音频流的回调函数指针。

为了避免不可预期的行为，在设置音频回调函数时，请确保该结构体的每一个成员变量都被自定义的回调方法或空指针初始化。可参考[使用OHAudio开发音频录制功能](../../media/audio/using-ohaudio-for-recording.md)。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t (\*[OH_AudioCapturer_OnReadData](#oh_audiocapturer_onreaddata))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, void \*buffer, int32_t length) | 该函数指针将指向用于读取音频数据的回调函数。  | 
| int32_t (\*[OH_AudioCapturer_OnStreamEvent](#oh_audiocapturer_onstreamevent))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event) | 该函数指针将指向用于处理音频录制流事件的回调函数。  | 
| int32_t (\*[OH_AudioCapturer_OnInterruptEvent](#oh_audiocapturer_oninterruptevent))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | 该函数指针将指向用于处理音频录制中断事件的回调函数。  | 
| int32_t (\*[OH_AudioCapturer_OnError](#oh_audiocapturer_onerror))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error) | 该函数指针将指向用于处理音频录制错误结果的回调函数。  | 


## 结构体成员变量说明

> **说明：**
> 以下回调接口的返回值没有枚举定义，当前版本实现并不按返回值区分处理，但为保证后续版本可扩展，默认使用0。


### OH_AudioCapturer_OnError

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnError)(OH_AudioCapturer *capturer, void *userData, OH_AudioStream_Result error)
```
**描述**
该函数指针将指向用于处理音频录制错误结果的回调函数。
**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| userData | 指向应用自定义的数据存储区域。 |
| error | 音频录制错误结果[OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result)，AUDIOSTREAM_ERROR_INVALID_PARAM、AUDIOSTREAM_ERROR_ILLEGAL_STATE或者AUDIOSTREAM_ERROR_SYSTEM。 |


### OH_AudioCapturer_OnInterruptEvent

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnInterruptEvent)(OH_AudioCapturer *capturer, void *userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```
**描述**
该函数指针将指向用于处理音频录制中断事件的回调函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| userData | 指向应用自定义的数据存储区域。 |
| type | 音频中断类型[OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype)。 |
| hint | 音频中断提示类型[OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint)。 |


### OH_AudioCapturer_OnReadData

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnReadData)(OH_AudioCapturer *capturer, void *userData, void *buffer, int32_t length)
```
**描述**
该函数指针将指向用于读取音频数据的回调函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| userData | 指向应用自定义的数据存储区域。 |
| buffer | 指向播放数据存储区域，用于应用填充播放数据。 |
| length | buffer的长度。 |


### OH_AudioCapturer_OnStreamEvent

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnStreamEvent)(OH_AudioCapturer *capturer, void *userData, OH_AudioStream_Event event)
```
**描述**
该函数指针将指向用于处理音频录制流事件的回调函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| userData | 指向应用自定义的数据存储区域。 |
| event | 音频事件[OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event)。 |