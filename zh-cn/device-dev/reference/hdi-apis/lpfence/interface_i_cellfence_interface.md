# ICellfenceInterface


## 概述

定义对基站围栏模块进行基本操作的接口。

接口包含注册回调函数，取消注册回调函数，添加基站围栏，删除基站围栏和获取基站围栏使用信息。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceCellfence](_hdi_lpfence_cellfence.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterCellfenceCallback](#registercellfencecallback) ([in] [ICellfenceCallback](interface_i_cellfence_callback.md) callbackObj) | 注册回调函数。 | 
| [UnregisterCellfenceCallback](#unregistercellfencecallback) ([in] [ICellfenceCallback](interface_i_cellfence_callback.md) callbackObj) | 取消注册回调函数。 | 
| [AddCellfences](#addcellfences) ([in] struct [CellfenceRequest](_cellfence_request.md)[] cellfence) | 添加基站围栏。 | 
| [RemoveCellfences](#removecellfences) ([in] int[] cellfenceId) | 删除基站围栏。 | 
| [GetCellfenceSize](#getcellfencesize) () | 获取基站围栏使用信息。 | 


## 成员函数说明


### AddCellfences()

```
ICellfenceInterface::AddCellfences ([in] struct CellfenceRequest[] cellfence)
```

**描述**


添加基站围栏。

支持一次添加多个基站围栏，一个基站围栏包含多个基站信息。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cellfence | 添加的基站围栏信息。详见[CellfenceRequest](_cellfence_request.md)。 | 

**返回：**

如果添加成功，则返回0。

如果添加失败，则返回负值。


### GetCellfenceSize()

```
ICellfenceInterface::GetCellfenceSize ()
```

**描述**


获取基站围栏使用信息

查看当前设备支持添加的基站围栏最大个数和已添加的基站围栏个数。通过回调函数上报通知，详见[OnGetCellfenceSizeCb](interface_i_cellfence_callback.md#ongetcellfencesizecb)。

**起始版本：** 4.0

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### RegisterCellfenceCallback()

```
ICellfenceInterface::RegisterCellfenceCallback ([in] ICellfenceCallback callbackObj)
```

**描述**


注册回调函数。

用户在开启基站围栏功能前，需要先注册该回调函数。当基站围栏状态发生变化时，会通过回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要注册的回调函数，只需成功订阅一次，无需重复订阅。详见[ICellfenceCallback](interface_i_cellfence_callback.md)。 | 

**返回：**

如果注册回调函数成功，则返回0。

如果注册回调函数失败，则返回负值。


### RemoveCellfences()

```
ICellfenceInterface::RemoveCellfences ([in] int[] cellfenceId)
```

**描述**


删除基站围栏。

支持一次删除多个基站围栏。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cellfenceId | 基站围栏ID号。详见[CellfenceRequest](_cellfence_request.md)。 | 

**返回：**

如果删除成功，则返回0。

如果删除失败，则返回负值。


### UnregisterCellfenceCallback()

```
ICellfenceInterface::UnregisterCellfenceCallback ([in] ICellfenceCallback callbackObj)
```

**描述**


取消注册回调函数。

取消之前注册的回调函数。当不需要使用基站围栏功能，或需要更换回调函数时，需要取消注册回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要取消注册的回调函数，只需成功取消订阅一次，无需重复取消订阅。详见[ICellfenceCallback](interface_i_cellfence_callback.md)。 | 

**返回：**

如果取消注册回调函数成功，则返回0。

如果取消注册回调函数失败，则返回负值。
