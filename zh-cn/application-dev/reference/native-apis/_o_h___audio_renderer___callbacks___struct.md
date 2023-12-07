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
