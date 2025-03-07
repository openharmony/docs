# IVibratorInterface


## 概述

Vibrator模块向上层服务提供统一的接口。

上层服务开发人员可根据Vibrator模块提供的统一接口，用于控制马达执行单次或周期性振动。

**起始版本：** 2.2

**相关模块：**[Vibrator](_vibrator_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [StartOnce](#startonce) ([in] unsigned int duration) | 控制马达以执行给定持续时间的单次振动。  | 
| [Start](#start) ([in] String effectType) | 控制马达以预置效果执行周期性振动。  | 
| [Stop](#stop) ([in] enum [HdfVibratorMode](_vibrator_v10.md#hdfvibratormode) mode) | 停止马达振动。  | 


## 成员函数说明


### Start()

```
IVibratorInterface::Start ([in] String effectType)
```
**描述**

控制马达以预置效果执行周期性振动。

单次振动与周期振动相互排斥。在执行周期性振动之前，需退出单次振动。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| effectType | 表示单次振动的预设效果。建议最大长度为64字节。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### StartOnce()

```
IVibratorInterface::StartOnce ([in] unsigned int duration)
```
**描述**

控制马达以执行给定持续时间的单次振动。

单次振动与周期振动相互排斥。在执行单次振动之前，需退出周期性振动。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| duration | 表示单次振动的持续时间，以毫秒为单位。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Stop()

```
IVibratorInterface::Stop ([in] enum HdfVibratorMode mode)
```
**描述**

停止马达振动。

马达启动前，必须在任何模式下停止振动。此功能用在振动过程之后。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 表示振动模式，可以是单次或周期性的，详见[HdfVibratorMode](_vibrator_v10.md#hdfvibratormode)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
