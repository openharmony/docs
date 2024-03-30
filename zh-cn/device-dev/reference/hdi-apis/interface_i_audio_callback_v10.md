# IAudioCallback


## 概述

Audio回调接口。

**起始版本：** 4.0

**相关模块：**[HdiAudio](_hdi_audio_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RenderCallback](#rendercallback) ([in] enum [AudioCallbackType](_hdi_audio_v11.md#audiocallbacktype) type, [out] byte reserved, [out] byte cookie) | 放音回调函数。 | 
| [ParamCallback](#paramcallback) ([in] enum [AudioExtParamKey](_hdi_audio_v11.md#audioextparamkey) key, [in] byte condition, [in] byte value, [out] byte reserved, [out] byte cookie) | 音频扩展参数回调函数。 | 


## 成员函数说明


### ParamCallback()

```
IAudioCallback::ParamCallback ([in] enum AudioExtParamKey key, [in] byte condition, [in] byte value, [out] byte reserved, [out] byte cookie )
```

**描述**

音频扩展参数回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| key | 扩展参数键类型，详请参考[AudioExtParamKey](_hdi_audio_v11.md#audioextparamkey)。 | 
| condition | 扩展参数条件。 | 
| value | 扩展参数条件的值 | 
| reserved | 保留字段。 | 
| cookie | 用于传递数据。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[ParamCallback](#paramcallback)


### RenderCallback()

```
IAudioCallback::RenderCallback ([in] enum AudioCallbackType type, [out] byte reserved, [out] byte cookie )
```

**描述**

放音回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 回调函数通知事件类型，详请参考[AudioCallbackType](_hdi_audio_v11.md#audiocallbacktype)。 | 
| reserved | 保留字段。 | 
| cookie | 用于传递数据。 | 

**返回：**

成功返回值0，失败返回负值。

**参见：**

[RegCallback](interface_i_audio_render_v10.md#regcallback)
