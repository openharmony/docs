# IWififenceInterface


## 概述

定义对Wi-Fi围栏模块进行基本操作的接口。

接口包含注册回调函数，取消注册回调函数，添加Wi-Fi围栏，删除Wi-Fi围栏，获取Wi-Fi围栏状态，获取Wi-Fi围栏使用信息的功能。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceWififence](_hdi_lpfence_wififence.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterWififenceCallback](#registerwififencecallback) ([in] [IWififenceCallback](interface_i_wififence_callback.md) callbackObj) | 注册回调函数。 | 
| [UnregisterWififenceCallback](#unregisterwififencecallback) ([in] [IWififenceCallback](interface_i_wififence_callback.md) callbackObj) | 取消注册回调函数。 | 
| [AddWififences](#addwififences) ([in] struct [WififenceRequest](_wififence_request.md)[] wififence) | 添加Wi-Fi围栏。 | 
| [RemoveWififences](#removewififences) ([in] int[] wififenceId) | 删除Wi-Fi围栏。 | 
| [GetWififenceStatus](#getwififencestatus) ([in] int wififenceId) | 获取设备与一个Wi-Fi围栏的状态关系。 | 
| [GetWififenceSize](#getwififencesize) () | 获取Wi-Fi围栏使用信息 | 


## 成员函数说明


### AddWififences()

```
IWififenceInterface::AddWififences ([in] struct WififenceRequest[] wififence)
```

**描述**


添加Wi-Fi围栏。

支持一次添加多个Wi-Fi围栏，一个Wi-Fi围栏包含多组MAC地址信息。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| wififence | 添加的Wi-Fi围栏信息。详见[WififenceRequest](_wififence_request.md)。 | 

**返回：**

如果添加成功，则返回0。

如果添加失败，则返回负值。


### GetWififenceSize()

```
IWififenceInterface::GetWififenceSize ()
```

**描述**


获取Wi-Fi围栏使用信息

查看当前设备支持添加的Wi-Fi围栏最大个数和已添加的Wi-Fi围栏个数。通过回调函数上报通知，详见[OnGetWififenceSizeCb](interface_i_wififence_callback.md#ongetwififencesizecb)。

**起始版本：** 4.0

**返回：**

如果调用成功，则返回0。

如果调用失败，则返回负值。


### GetWififenceStatus()

```
IWififenceInterface::GetWififenceStatus ([in] int wififenceId)
```

**描述**


获取设备与一个Wi-Fi围栏的状态关系。

设备与Wi-Fi围栏的状态关系详见[WififenceTransition](_hdi_lpfence_wififence.md#wififencetransition)定义。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| wififenceId | Wi-Fi围栏ID号。 | 

**返回：**

返回位置关系。详见[WififenceTransition](_hdi_lpfence_wififence.md#wififencetransition)定义。

如果调用失败，则返回负值。


### RegisterWififenceCallback()

```
IWififenceInterface::RegisterWififenceCallback ([in] IWififenceCallback callbackObj)
```

**描述**


注册回调函数。

用户在开启Wi-Fi围栏功能前，需要先注册该回调函数。当Wi-Fi围栏状态发生变化时，会通过回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要注册的回调函数，只需成功订阅一次，无需重复订阅。详见[IWififenceCallback](interface_i_wififence_callback.md)。 | 

**返回：**

如果注册回调函数成功，则返回0。

如果注册回调函数失败，则返回负值。


### RemoveWififences()

```
IWififenceInterface::RemoveWififences ([in] int[] wififenceId)
```

**描述**


删除Wi-Fi围栏。

支持一次删除多个Wi-Fi围栏。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| wififenceId | Wi-Fi围栏ID号。详见[WififenceRequest](_wififence_request.md)。 | 

**返回：**

如果删除成功，则返回0。

如果删除失败，则返回负值。


### UnregisterWififenceCallback()

```
IWififenceInterface::UnregisterWififenceCallback ([in] IWififenceCallback callbackObj)
```

**描述**


取消注册回调函数。

取消之前注册的回调函数。当不需要使用Wi-Fi围栏功能，或需要更换回调函数时，需要取消注册回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要取消注册的回调函数，只需成功取消订阅一次，无需重复取消订阅。详见[IWififenceCallback](interface_i_wififence_callback.md)。 | 

**返回：**

如果取消注册回调函数成功，则返回0。

如果取消注册回调函数失败，则返回负值。
