# ICellfenceCallback


## 概述

定义基站围栏模块的回调函数。

用户在开启基站围栏功能前，需要先注册该回调函数。当基站围栏状态发生变化时，会通过回调函数进行上报。 详情可参考[ICellfenceInterface](interface_i_cellfence_interface.md)。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceCellfence](_hdi_lpfence_cellfence.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnCellfenceChanged](#oncellfencechanged) ([in] struct [CellfenceStatus](_cellfence_status.md) fences) | 定义基站围栏状态变化通知的回调函数。 | 
| [OnGetCellfenceSizeCb](#ongetcellfencesizecb) ([in] struct [CellfenceSize](_cellfence_size.md) size) | 定义基站围栏使用信息的回调函数。 | 
| [OnCellfenceReset](#oncellfencereset) () | 定义低功耗围栏服务复位事件通知的回调函数。 | 


## 成员函数说明


### OnCellfenceChanged()

```
ICellfenceCallback::OnCellfenceChanged ([in] struct CellfenceStatus fences)
```

**描述**


定义基站围栏状态变化通知的回调函数。

设备与基站围栏的状态关系发生变化时，会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fences | 上报基站围栏变化的状态。详见[CellfenceStatus](_cellfence_status.md)定义。 | 

**返回：**

如果回调函数上报数据成功，则返回0。

如果回调函数上报数据失败，则返回负值。


### OnCellfenceReset()

```
ICellfenceCallback::OnCellfenceReset ()
```

**描述**


定义低功耗围栏服务复位事件通知的回调函数。

低功耗围栏服务发生复位时会通过该回调函数进行事件上报。

**起始版本：** 4.0

**返回：**

如果回调函数调用成功，则返回0。

如果回调函数调用失败，则返回负值。


### OnGetCellfenceSizeCb()

```
ICellfenceCallback::OnGetCellfenceSizeCb ([in] struct CellfenceSize size)
```

**描述**


定义基站围栏使用信息的回调函数。

获取基站围栏使用信息时，会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| size | 基站围栏使用信息。详见[CellfenceSize](_cellfence_size.md)定义。 | 

**返回：**

如果回调函数上报数据成功，则返回0。

如果回调函数上报数据失败，则返回负值。
