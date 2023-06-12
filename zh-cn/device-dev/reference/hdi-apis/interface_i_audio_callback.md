# IAudioCallback


## 概述

Audio回调接口。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[Audio](_audio.md)


## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [RenderCallback](#rendercallback)&nbsp;([in]&nbsp;enum&nbsp;[AudioCallbackType](_audio.md#audiocallbacktype)&nbsp;type,&nbsp;[out]&nbsp;byte&nbsp;reserved,&nbsp;[out]&nbsp;byte&nbsp;cookie) | 放音回调函数。 | 
| [ParamCallback](#paramcallback)&nbsp;([in]&nbsp;enum&nbsp;[AudioExtParamKey](_audio.md#audioextparamkey)&nbsp;key,&nbsp;[in]&nbsp;byte&nbsp;condition,&nbsp;[in]&nbsp;byte&nbsp;value,&nbsp;[out]&nbsp;byte&nbsp;reserved,&nbsp;[out]&nbsp;byte&nbsp;cookie) | 音频扩展参数回调函数。 | 


## 成员函数说明


### ParamCallback()

  
```
IAudioCallback::ParamCallback ([in] enum AudioExtParamKey key, [in] byte condition, [in] byte value, [out] byte reserved, [out] byte cookie )
```

**描述:**

音频扩展参数回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| key | 扩展参数键类型，详请参考[AudioExtParamKey](_audio.md#audioextparamkey)。 | 
| condition | 扩展参数条件。 | 
| value | 扩展参数条件的值 | 
| reserved | 保留字段。 | 
| cookie | 用于传递数据。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

[ParamCallback](#paramcallback)


### RenderCallback()

  
```
IAudioCallback::RenderCallback ([in] enum AudioCallbackType type, [out] byte reserved, [out] byte cookie )
```

**描述:**

放音回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| type | 回调函数通知事件类型，详请参考[AudioExtParamKey](_audio.md#audioextparamkey)。 | 
| reserved | 保留字段。 | 
| cookie | 用于传递数据。 | 

**返回:**

成功返回值0，失败返回负值。

**参见:**

RegCallback
