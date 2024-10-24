# IVibratorInterface


## 概述

Vibrator模块向上层服务提供统一的接口。

上层服务开发人员可根据Vibrator模块提供的统一接口，用于控制马达执行单次或周期性振动。

**起始版本：** 4.1

**相关模块：**[Vibrator](_vibrator_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [PlayHapticPattern](#playhapticpattern) ([in] struct [HapticPaket](_haptic_paket_v12.md) pkg) | 高清振动数据下发。  | 
| [GetHapticCapacity](#gethapticcapacity) ([out] struct [HapticCapacity](_haptic_capacity_v12.md)[HapticCapacity](_haptic_capacity_v12.md)) | 获取马达振动能力。  | 
| [GetHapticStartUpTime](#gethapticstartuptime) ([in] int mode, [out] int startUpTime) | 获取起振时间。  | 
| [StopV1_2](#stopv1_2) ([in] int mode) | 停止马达振动。  | 


## 成员函数说明


### GetHapticCapacity()

```
IVibratorInterface::GetHapticCapacity ([out] struct HapticCapacity HapticCapacity)
```
**描述**

获取马达振动能力。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| [HapticCapacity](_haptic_capacity_v12.md) | 表示振动能力数据包，属性包含是否高清振动，是否支持延时振动，是否支持预定义振动。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetHapticStartUpTime()

```
IVibratorInterface::GetHapticStartUpTime ([in] int mode, [out] int startUpTime )
```
**描述**

获取起振时间。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| startUpTime | 表示从下达振动振动命令到马达振动起来的时间，mode为振动模式，按照模式去获取。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### PlayHapticPattern()

```
IVibratorInterface::PlayHapticPattern ([in] struct HapticPaket pkg)
```
**描述**

高清振动数据下发。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pkg | 表示高清振动数据的数据包，是一个结构体，内部赋值具体振动参数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### StopV1_2()

```
IVibratorInterface::StopV1_2 ([in] int mode)
```
**描述**

停止马达振动。

马达启动前，必须在任何模式下停止振动。此功能用在振动过程之后。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 表示振动模式，可以是单次或周期性或者HD的，详见[HdfVibratorModeV1_2](_vibrator_v12.md#hdfvibratormodev1_2)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
