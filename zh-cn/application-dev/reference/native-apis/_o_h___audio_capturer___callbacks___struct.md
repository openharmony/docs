# OH_AudioCapturer_Callbacks_Struct


## 概述

声明输入音频流的回调函数指针。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| (\*[OH_AudioCapturer_OnReadData](_o_h_audio.md#oh_audiocapturer_onreaddata) )([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, void \*buffer, int32_t lenth) | 该函数指针将指向用于读取音频数据的回调函数。 | 
| OH_AudioCapturer_OnStreamEvent ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event) | 这个函数指针将指向用于处理音频录制流事件的回调函数。 | 
| OH_AudioCapturer_OnInterruptEvent ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | 这个函数指针将指向用于处理音频录制中断事件的回调函数。 | 
| OH_AudioCapturer_OnError ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error) | 这个函数指针将指向用于处理音频录制错误结果的回调函数。 | 