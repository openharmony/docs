# HdiLpfenceCellfence


## 概述

为低功耗围栏服务提供基站围栏的API。

本模块接口提供添加基站围栏、删除基站围栏和获取基站围栏使用信息的功能。应用场景：判断用户设备是否达到某个较大范围的位置区域，从而进行一些后续服务，如景区服务介绍等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [CellfenceTypes.idl](_cellfence_types_8idl.md) | 定义基站围栏使用的数据类型。 | 
| [ICellfenceCallback.idl](_i_cellfence_callback_8idl.md) | 定义基站围栏模块回调接口。 | 
| [ICellfenceInterface.idl](_i_cellfence_interface_8idl.md) | 声明基站围栏模块提供的API，用于添加基站围栏，删除基站围栏和获取基站围栏使用信息。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[CellfenceInfo](_cellfence_info.md) | 定义基站基本信息的数据结构。 | 
| struct&nbsp;&nbsp;[CellfenceRequest](_cellfence_request.md) | 定义添加基站围栏的数据结构。 | 
| struct&nbsp;&nbsp;[CellfenceStatus](_cellfence_status.md) | 定义设备与基站围栏状态关系的数据结构。 | 
| struct&nbsp;&nbsp;[CellfenceSize](_cellfence_size.md) | 定义基站围栏使用信息的数据结构。 | 
| interface&nbsp;&nbsp;[ICellfenceCallback](interface_i_cellfence_callback.md) | 导入基站围栏模块的数据类型。 | 
| interface&nbsp;&nbsp;[ICellfenceInterface](interface_i_cellfence_interface.md) | 定义对基站围栏模块进行基本操作的接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CellfenceTransition](#cellfencetransition) { FENCE_ENTER = 0 , FENCE_EXIT = 3 } | 枚举设备与基站围栏的位置关系。 | 


## 枚举类型说明


### CellfenceTransition

```
enum CellfenceTransition
```

**描述**


枚举设备与基站围栏的位置关系。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| FENCE_ENTER | 设备在基站围栏范围内。 | 
| FENCE_EXIT | 设备不在基站围栏范围内。 | 
