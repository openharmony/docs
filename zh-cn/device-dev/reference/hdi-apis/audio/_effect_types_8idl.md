# EffectTypes.idl


## 概述

Effect模块接口定义中使用的数据类型。

Effect模块接口定义中使用的控制器参数、控制器描述符、音效输入输出buffer参数、控制命令等。

模块包路径：ohos.hdi.audio.effect.v1_0

**起始版本：** 4.0

**相关模块：**[HdiEffect](_hdi_effect.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[EffectInfo](_effect_info.md) | 定义effect加载的音效信息。 | 
| struct&nbsp;&nbsp;[ControllerId](_controller_id.md) | 定义效果控制器信息，包括其所属的库及其effectId。 | 
| struct&nbsp;&nbsp;[EffectControllerDescriptor](_effect_controller_descriptor.md) | 定义音效控制器描述。 | 
| struct&nbsp;&nbsp;[AudioEffectBuffer](_audio_effect_buffer.md) | 定义音效进程输入输出buffer。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AudioEffectBufferTag](_hdi_effect.md#audioeffectbuffertag) {<br/>EFFECT_BUFFER_VOID_TYPE = 0 , EFFECT_BUFFER_FLOAT_SIGNED_32 = 1 &lt;&lt; 0 , EFFECT_BUFFER_SINGED_32 = 1 &lt;&lt; 1 , EFFECT_BUFFER_SIGNED_16 = 1 &lt;&lt; 2 , EFFECT_BUFFER_UNSIGNED_8 = 1 &lt;&lt; 3<br/>} | 数据点类型标记，该类型正在按需使用。 | 
| [EffectCommandTableIndex](_hdi_effect.md#effectcommandtableindex) {<br/>AUDIO_EFFECT_COMMAND_INIT_CONTOLLER , AUDIO_EFFECT_COMMAND_SET_CONFIG , AUDIO_EFFECT_COMMAND_GET_CONFIG , AUDIO_EFFECT_COMMAND_RESET , AUDIO_EFFECT_COMMAND_ENABLE , AUDIO_EFFECT_COMMAND_DISABLE , AUDIO_EFFECT_COMMAND_SET_PARAM , AUDIO_EFFECT_COMMAND_GET_PARAM<br/>} | 定义音效控制器命令索引。 | 
