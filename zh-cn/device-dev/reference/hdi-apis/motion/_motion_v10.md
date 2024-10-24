# Motion (V1_0)


## 概述

手势识别设备驱动对硬件服务提供通用的接口能力。

模块提供硬件服务对手势识别驱动模块访问统一接口，服务获取驱动对象或者代理后，通过其提供的各类方法，实现使能手势识别/ 去使能手势识别、订阅/取消订阅手势识别数据。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IMotionCallback.idl](_i_motion_callback_8idl_v10.md) | 定义上报手势识别数据回调函数接口。 | 
| [IMotionInterface.idl](_i_motion_interface_8idl_v10.md) | 定义使能/去使能手势识别、订阅/取消订阅手势识别数据的接口。 | 
| [MotionTypes.idl](_motion_types_8idl_v10.md) | 定义手势识别模块用到的数据结构，包括手势识别类型、上报的手势识别数据结构。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IMotionCallback](interface_i_motion_callback_v10.md) | 手势识别模块接口的包路径。 | 
| interface&nbsp;&nbsp;[IMotionInterface](interface_i_motion_interface_v10.md) | 手势识别模块接口的包路径。 | 
| struct&nbsp;&nbsp;[HdfMotionEvent](_hdf_motion_event_v10.md) | 上报手势识别数据结构。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HdfMotionTypeTag](#hdfmotiontypetag) {<br/>HDF_MOTION_TYPE_PICKUP = 0, HDF_MOTION_TYPE_FLIP, HDF_MOTION_CLOSE_TO_EAR, HDF_MOTION_TYPE_SHAKE,&nbsp;&nbsp;&nbsp;HDF_MOTION_TYPE_ROTATION, HDF_MOTION_TYPE_POCKET_MODE, HDF_MOTION_TYPE_LEAVE_EAR, HDF_MOTION_TYPE_WRIST_UP,&nbsp;&nbsp;&nbsp;HDF_MOTION_TYPE_WRIST_DOWN, HDF_MOTION_TYPE_MAX<br/>} | 手势识别模块接口的包路径。 | 


## 枚举类型说明


### HdfMotionTypeTag

```
enum HdfMotionTypeTag
```

**描述**


枚举手势识别类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_MOTION_TYPE_PICKUP | 拿起类型。 | 
| HDF_MOTION_TYPE_FLIP | 翻转类型。 | 
| HDF_MOTION_CLOSE_TO_EAR | 靠近耳朵类型。 | 
| HDF_MOTION_TYPE_SHAKE | 摇一摇类型。 | 
| HDF_MOTION_TYPE_ROTATION | 旋转屏类型。 | 
| HDF_MOTION_TYPE_POCKET_MODE | 口袋模式类型。 | 
| HDF_MOTION_TYPE_LEAVE_EAR | 拿离耳朵类型。 | 
| HDF_MOTION_TYPE_WRIST_UP | 腕朝上类型。 | 
| HDF_MOTION_TYPE_WRIST_DOWN | 腕朝下类型。 | 
| HDF_MOTION_TYPE_MAX | 最大手势识别类型。 | 
