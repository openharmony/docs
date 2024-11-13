# Vibrator (V1_0)


## 概述

马达驱动对马达服务提供通用的接口能力。

模块提供马达服务对马达驱动访问的统一接口，服务获取驱动对象或者代理后，控制马达的单次振动、周期性振动、停止振动。

**起始版本：** 2.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IVibratorInterface.idl](_i_vibrator_interface_8idl_v10.md) | 定义马达的通用API，可用于控制马达执行单次或周期性振动。 | 
| [VibratorTypes.idl](_vibrator_types_8idl_v10.md) | 定义马达数据结构，包括马达振动模式。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IVibratorInterface](interface_i_vibrator_interface_v10.md) | Vibrator模块向上层服务提供统一的接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HdfVibratorMode](#hdfvibratormode) { HDF_VIBRATOR_MODE_ONCE , HDF_VIBRATOR_MODE_PRESET , HDF_VIBRATOR_MODE_BUTT } | 定义马达振动模式。 | 


## 枚举类型说明


### HdfVibratorMode

```
enum HdfVibratorMode
```

**描述**


定义马达振动模式。

**起始版本：** 2.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_VIBRATOR_MODE_ONCE | 表示给定持续时间内的单次振动。 | 
| HDF_VIBRATOR_MODE_PRESET | 表示具有预置效果的周期性振动。 | 
| HDF_VIBRATOR_MODE_BUTT | 表示效果模式无效。 | 
