# IActivityInterface


## 概述

定义对行为识别进行基本操作的接口。

接口包含注册回调函数，取消注册回调函数，获取设备支持的行为类型，获取当前设备的行为类型，订阅和取消订阅行为事件，获取设备缓存的行为事件。

**相关模块：**[HdiActivityRecognition](_hdi_activity_recognition.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterActRecognitionCallback](#registeractrecognitioncallback) ([in] [IActivityChangedCallback](interface_i_activity_changed_callback.md) callbackObj) | 注册回调函数。 | 
| [UnregisterActRecognitionCallback](#unregisteractrecognitioncallback) ([in] [IActivityChangedCallback](interface_i_activity_changed_callback.md) callbackObj) | 取消注册回调函数。 | 
| [GetSupportActivity](#getsupportactivity) ([out] String[] activity) | 获取设备支持的行为类型。 | 
| [GetCurrentActivity](#getcurrentactivity) ([out] struct [ActRecognitionEvent](_act_recognition_event.md)[] event) | 获取当前的行为事件。 | 
| [EnableActRecognitionEvent](#enableactrecognitionevent) ([in] int activity, [in] int eventType, [in] long maxReportLatencyNs, [in] int powerMode) | 订阅某个行为事件。 | 
| [DisableActRecognitionEvent](#disableactrecognitionevent) ([in] int activity, [in] int eventType) | 取消订阅某个行为事件。 | 
| [FlushActivity](#flushactivity) () | 数据刷新。 | 


## 成员函数说明


### DisableActRecognitionEvent()

```
IActivityInterface::DisableActRecognitionEvent ([in] int activity, [in] int eventType )
```

**描述**

取消订阅某个行为事件。

取消订阅某个之前订阅过的行为事件。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| activity | 取消订阅的行为，参考[EnableActRecognitionEvent](#enableactrecognitionevent)接口的activity参数。 | 
| eventType | 事件类型，参考[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)定义。可以填充1（进入）或2（退出），也可以填充3（同时订阅进入和退出）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### EnableActRecognitionEvent()

```
IActivityInterface::EnableActRecognitionEvent ([in] int activity, [in] int eventType, [in] long maxReportLatencyNs, [in] int powerMode )
```

**描述**

订阅某个行为事件。

订阅某个行为事件后，若该行为事件有发生，则会在一定时间内上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| activity | 订阅的行为，通过[GetSupportActivity](#getsupportactivity)得到设备支持的所有行为，然后将行为列表中需要订阅的行为下标作为参数填充。 | 
| eventType | 事件类型，参考[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)定义。可以填充1（进入）或2（退出），也可以填充3（同时订阅进入和退出）。 | 
| maxReportLatencyNs | 最大上报时间间隔，单位是纳秒。若该时间间隔内有订阅的行为事件发生，则会上报。若存在多个订阅的行为，取最小的时间间隔。 | 
| powerMode | 功耗模式。参考[ActRecognitionPowerMode](_hdi_activity_recognition.md#actrecognitionpowermode)定义。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### FlushActivity()

```
IActivityInterface::FlushActivity ()
```

**描述**

数据刷新。

刷新设备缓存的所有行为事件并上报。

**起始版本：** 3.2

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetCurrentActivity()

```
IActivityInterface::GetCurrentActivity ([out] struct ActRecognitionEvent[] event)
```

**描述**

获取当前的行为事件。

在调用该接口前，必须先要调用{\@Link EnableActRecognitionEvent}接口对行为进行使能。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 返回当前设备的行为事件，可能有多个行为共存，详见[ActRecognitionEvent](_act_recognition_event.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetSupportActivity()

```
IActivityInterface::GetSupportActivity ([out] String[] activity)
```

**描述**

获取设备支持的行为类型。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| activity | 参数类型为字符串，输出设备支持的行为类型。 包括："inVehicle" 、"onBicycle"、"walking"、"running"、"still"、"fast_walking"、"high_speed_rail" "unknown"、"elevator"、"relative_still"、"walking_handhold"、"lying_posture"、"plane"、"metro"等。对应[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)中的类型。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### RegisterActRecognitionCallback()

```
IActivityInterface::RegisterActRecognitionCallback ([in] IActivityChangedCallback callbackObj)
```

**描述**

注册回调函数。

用户在获得订阅的行为事件或获取设备缓存的行为事件前，需要先注册该回调函数。数据会通过回调函数进行上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要注册的回调函数，只需成功订阅一次，无需重复订阅。详见[IActivityChangedCallback](interface_i_activity_changed_callback.md)。 | 

**返回：**

如果注册回调函数成功，则返回0。

如果注册回调函数失败，则返回负值。


### UnregisterActRecognitionCallback()

```
IActivityInterface::UnregisterActRecognitionCallback ([in] IActivityChangedCallback callbackObj)
```

**描述**

取消注册回调函数。

取消之前注册的回调函数。当不需要使用行为识别功能，或需要更换回调函数时，需要取消注册回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要取消注册的回调函数，只需成功取消订阅一次，无需重复取消订阅。详见[IActivityChangedCallback](interface_i_activity_changed_callback.md)。 | 

**返回：**

如果取消注册回调函数成功，则返回0。

如果取消注册回调函数失败，则返回负值。
