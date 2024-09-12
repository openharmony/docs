# IEffectControl


## 概述

音效控制器接口。

提供音效控制器支持的驱动能力，包括音效数据处理、音效命令发送、获取当前音效描述符等。

**起始版本：** 4.0

**相关模块：**[HdiEffect](_hdi_effect.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [EffectProcess](#effectprocess) ([in] struct [AudioEffectBuffer](_audio_effect_buffer.md) input, [out] struct [AudioEffectBuffer](_audio_effect_buffer.md) output) | 处理音频原始数据。 | 
| [SendCommand](#sendcommand) ([in] unsigned int cmdId, [in] byte[] cmdData, [out] byte[] replyData) | 发送音效处理命令 | 
| [GetEffectDescriptor](#geteffectdescriptor) ([out] struct [EffectControllerDescriptor](_effect_controller_descriptor.md) desc) | 获取音效的描述符 | 
| [EffectReverse](#effectreverse) ([in] struct [AudioEffectBuffer](_audio_effect_buffer.md) input, [out] struct [AudioEffectBuffer](_audio_effect_buffer.md) output) | 反转音频处理后的数据。 | 


## 成员函数说明


### EffectProcess()

```
IEffectControl::EffectProcess ([in] struct AudioEffectBuffer input, [out] struct AudioEffectBuffer output )
```

**描述**

处理音频原始数据。

必须指定输入和输出buffer，如果未指定，则进程必须使用命令提供的数据处理功能。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| control | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| input | 输入数据的buffer。 | 
| output | 输出数据的buffer。 | 

**返回：**

执行成功返回0，执行失败返回其他值。


### EffectReverse()

```
IEffectControl::EffectReverse ([in] struct AudioEffectBuffer input, [out] struct AudioEffectBuffer output )
```

**描述**

反转音频处理后的数据。

必须指定输入和输出缓冲区，如果未指定，则反转必须使用命令提供的数据反转功能。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| control | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| input | 输入数据buffer。 | 
| output | 输出数据buffer。 | 

**返回：**

执行成功返回0，执行失败返回其他值。


### GetEffectDescriptor()

```
IEffectControl::GetEffectDescriptor ([out] struct EffectControllerDescriptor desc)
```

**描述**

获取音效的描述符。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| control | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| desc | 指定的音效描述符。 | 

**返回：**

执行成功返回0，执行失败返回其他值。


### SendCommand()

```
IEffectControl::SendCommand ([in] unsigned int cmdId, [in] byte[] cmdData, [out] byte[] replyData )
```

**描述**

发送音效处理命令。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| control | 指向要调用该接口的音效控件，该指针参数在编译为C接口后产生。 | 
| cmdId | 用于匹配命令表中的命令选项的命令索引。 | 
| cmdData | 系统服务的数据。 | 
| cmdDataLen | 数据长度，该参数在编译为C接口后产生。 | 
| replyData | 返回的数据。 | 
| replyDataLen | 数据长度，该参数在编译为C接口后产生。 | 

**返回：**

执行成功返回0，执行失败返回其他值。
