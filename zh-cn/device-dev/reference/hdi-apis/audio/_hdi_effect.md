# HdiEffect


## 概述

Effect模块接口定义。

音效接口涉及数据类型、音效模型接口、音效控制器接口等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [EffectTypes.idl](_effect_types_8idl.md) | Effect模块接口定义中使用的数据类型。 | 
| [IEffectControl.idl](_i_effect_control_8idl.md) | 音效控制器的接口定义文件。 | 
| [IEffectModel.idl](_i_effect_model_8idl.md) | 音效模型的接口定义文件。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[EffectInfo](_effect_info.md) | 定义effect加载的音效信息。 | 
| struct&nbsp;&nbsp;[ControllerId](_controller_id.md) | 定义效果控制器信息，包括其所属的库及其effectId。 | 
| struct&nbsp;&nbsp;[EffectControllerDescriptor](_effect_controller_descriptor.md) | 定义音效控制器描述 | 
| struct&nbsp;&nbsp;[AudioEffectBuffer](_audio_effect_buffer.md) | 定义音效进程输入输出buffer。 | 
| interface&nbsp;&nbsp;[IEffectControl](interface_i_effect_control.md) | 音效控制器接口。 | 
| interface&nbsp;&nbsp;[IEffectModel](interface_i_effect_model.md) | 音效模型接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AudioEffectBufferTag](#audioeffectbuffertag) {<br/>EFFECT_BUFFER_VOID_TYPE = 0 , EFFECT_BUFFER_FLOAT_SIGNED_32 = 1 &lt;&lt; 0 , EFFECT_BUFFER_SINGED_32 = 1 &lt;&lt; 1 , EFFECT_BUFFER_SIGNED_16 = 1 &lt;&lt; 2 , EFFECT_BUFFER_UNSIGNED_8 = 1 &lt;&lt; 3<br/>} | 数据点类型标记，该类型正在按需使用。 | 
| [EffectCommandTableIndex](#effectcommandtableindex) {<br/>AUDIO_EFFECT_COMMAND_INIT_CONTOLLER , AUDIO_EFFECT_COMMAND_SET_CONFIG , AUDIO_EFFECT_COMMAND_GET_CONFIG , AUDIO_EFFECT_COMMAND_RESET , AUDIO_EFFECT_COMMAND_ENABLE , AUDIO_EFFECT_COMMAND_DISABLE , AUDIO_EFFECT_COMMAND_SET_PARAM , AUDIO_EFFECT_COMMAND_GET_PARAM<br/>} | 定义音效控制器命令索引。 | 


## 枚举类型说明


### AudioEffectBufferTag

```
enum AudioEffectBufferTag
```

**描述**

数据点类型标记，该类型正在按需使用。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| EFFECT_BUFFER_VOID_TYPE | raw模式音频数据指向缓冲区的起点 | 
| EFFECT_BUFFER_FLOAT_SIGNED_32 | 32bit浮点型音频数据指向缓冲区的起点 | 
| EFFECT_BUFFER_SINGED_32 | 32bit整型音频数据指向缓冲区的起点 | 
| EFFECT_BUFFER_SIGNED_16 | 16bit整型音频数据指向缓冲区的起点 | 
| EFFECT_BUFFER_UNSIGNED_8 | 8bit无符号整型音频数据指向缓冲区的起点 | 


### EffectCommandTableIndex

```
enum EffectCommandTableIndex
```

**描述**

定义音效控制器命令索引。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUDIO_EFFECT_COMMAND_INIT_CONTOLLER | 初始化音效控制器 | 
| AUDIO_EFFECT_COMMAND_SET_CONFIG | 设置配置参数 | 
| AUDIO_EFFECT_COMMAND_GET_CONFIG | 获取配置参数 | 
| AUDIO_EFFECT_COMMAND_RESET | 重启音效控制器 | 
| AUDIO_EFFECT_COMMAND_ENABLE | 使能音效 | 
| AUDIO_EFFECT_COMMAND_DISABLE | 禁用音效 | 
| AUDIO_EFFECT_COMMAND_SET_PARAM | 设置参数 | 
| AUDIO_EFFECT_COMMAND_GET_PARAM | 获取参数 | 
