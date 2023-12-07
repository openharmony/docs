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
