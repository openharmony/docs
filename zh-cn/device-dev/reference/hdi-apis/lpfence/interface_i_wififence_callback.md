# IWififenceCallback


## 概述

定义Wi-Fi围栏模块的回调函数

用户在开启Wi-Fi围栏功能前，需要先注册该回调函数。当Wi-Fi围栏状态发生变化时，会通过回调函数进行上报。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceWififence](_hdi_lpfence_wififence.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnWififenceChanged](#onwififencechanged) ([in] int wififenceId, [in] int transition, [in] long timeStamp) | 定义Wi-Fi围栏状态变化的回调函数。 | 
| [OnGetWififenceSizeCb](#ongetwififencesizecb) ([in] struct [WififenceSize](_wififence_size.md) size) | 定义Wi-Fi围栏使用信息的回调函数。 | 
| [OnWififenceReset](#onwififencereset) () | 定义低功耗围栏服务复位事件通知的回调函数。 | 


## 成员函数说明


### OnGetWififenceSizeCb()

```
IWififenceCallback::OnGetWififenceSizeCb ([in] struct WififenceSize size)
```

**描述**


定义Wi-Fi围栏使用信息的回调函数。

获取Wi-Fi围栏使用信息时，会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| size | 基站围栏使用信息。详见[WififenceSize](_wififence_size.md)定义。 | 

**返回：**

如果回调函数上报数据成功，则返回0。

如果回调函数上报数据失败，则返回负值。


### OnWififenceChanged()

```
IWififenceCallback::OnWififenceChanged ([in] int wififenceId, [in] int transition, [in] long timeStamp )
```

**描述**


定义Wi-Fi围栏状态变化的回调函数。

设备与Wi-Fi围栏的状态关系发生变化时，会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| wififenceId | Wi-Fi围栏ID号。 | 
| transition | Wi-Fi围栏变化的状态。详见[WififenceTransition](_hdi_lpfence_wififence.md#wififencetransition)定义。 | 
| timeStamp | 时间戳。 | 

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### OnWififenceReset()

```
IWififenceCallback::OnWififenceReset ()
```

**描述**


定义低功耗围栏服务复位事件通知的回调函数。

低功耗围栏服务发生复位时会通过该回调函数进行事件上报。

**起始版本：** 4.0

**返回：**

如果回调函数调用成功，则返回0。

如果回调函数调用失败，则返回负值。
