# OH_AudioRenderer_Callbacks_Struct


## 概述

声明输出音频流的回调函数指针。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| (\*[OH_AudioRenderer_OnWriteData](_o_h_audio.md#oh_audiorenderer_onwritedata) )([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*buffer, int32_t lenth) | 该函数指针将指向用于写入音频数据的回调函数。 | 
| (\*OH_AudioRenderer_Callbacks::OH_AudioRenderer_OnStreamEvent )([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event); | 该函数指针将指向用于处理音频播放流事件的回调函数。 | 
| (\*OH_AudioRenderer_Callbacks::OH_AudioRenderer_OnInterruptEvent )([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | 该函数指针将指向用于处理音频播放中断事件的回调函数。 | 
| (\*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnError)( [OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error) | 该函数指针将指向用于处理音频播放错误结果的回调函数。 | 