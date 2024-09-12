# IActivityChangedCallback


## 概述

定义上报行为事件的回调函数。

用户在获得订阅的行为事件或获取设备缓存的行为事件前，需要先注册该回调函数。只有当订阅的行为发生时，行为数据才会通过回调函数进行上报。 详情可参考[IActivityInterface](interface_i_activity_interface.md)。

**起始版本：** 3.2

**相关模块：**[HdiActivityRecognition](_hdi_activity_recognition.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnActivityChanged](#onactivitychanged) ([in] struct [ActRecognitionEvent](_act_recognition_event.md)[] event) | 定义上报行为事件的回调函数。 | 


## 成员函数说明


### OnActivityChanged()

```
IActivityChangedCallback::OnActivityChanged ([in] struct ActRecognitionEvent[] event)
```

**描述**

定义上报行为事件的回调函数。

数据会通过该回调函数进行上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 上报的数据。详见[ActRecognitionEvent](_act_recognition_event.md)定义。 | 

**返回：**

如果回调函数上报数据成功，则返回0。

如果回调函数上报数据失败，则返回负值。
