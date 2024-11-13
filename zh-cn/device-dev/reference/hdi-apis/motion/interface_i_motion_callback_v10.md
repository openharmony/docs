# IMotionCallback


## 概述

定义上报手势识别数据回调函数。

手势识别用户在订阅手势识别数据时需要注册这个回调函数，只有当使能手势识别后，手势识别数据用户才会收到手势识别数据。 详情可参考[IMotionInterface](interface_i_motion_interface_v10.md)。

**起始版本：** 3.2

**相关模块：**[Motion](_motion_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnDataEvent](#ondataevent) ([in] struct [HdfMotionEvent](_hdf_motion_event_v10.md) event) | 定义上报手势识别数据回调函数。 | 


## 成员函数说明


### OnDataEvent()

```
IMotionCallback::OnDataEvent ([in] struct HdfMotionEvent event)
```

**描述**


定义上报手势识别数据回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 回调函数上报的数据。详见[HdfMotionEvent](_hdf_motion_event_v10.md)。 | 

**返回：**

如果回调函数上报数据成功，则返回0。

如果回调函数上报数据失败，则返回负值。
