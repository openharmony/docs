# Motion (V1_1)


## 概述

手势识别设备驱动对硬件服务提供通用的接口能力。

模块提供硬件服务对手势识别驱动模块访问统一接口，服务获取驱动对象或者代理后，通过其提供的各类方法，实现使能手势识别/ 去使能手势识别、订阅/取消订阅手势识别数据。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IMotionInterface.idl](_i_motion_interface_8idl_v11.md) | 定义使能/去使能手势识别、订阅/取消订阅手势识别数据的接口。 | 
| [MotionTypes.idl](_motion_types_8idl_v11.md) | 定义手势识别模块用到的数据结构，包括手势识别类型、上报的手势识别数据结构。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IMotionInterface](interface_i_motion_interface_v11.md) | 提供Motion设备基本控制操作接口。 | 
| struct&nbsp;&nbsp;[WaveParam](_wave_param_v11.md) | 定义运动波配置参数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HdfMotionTypeTag](#hdfmotiontypetag) {<br/>HDF_MOTION_TYPE_PICKUP = 0, HDF_MOTION_TYPE_FLIP, HDF_MOTION_CLOSE_TO_EAR, HDF_MOTION_TYPE_SHAKE,&nbsp;&nbsp;&nbsp;HDF_MOTION_TYPE_ROTATION, HDF_MOTION_TYPE_POCKET_MODE, HDF_MOTION_TYPE_LEAVE_EAR, HDF_MOTION_TYPE_WRIST_UP , HDF_MOTION_TYPE_WRIST_DOWN , HDF_MOTION_TYPE_WAVE , HDF_MOTION_TYPE_STEP_COUNTER , HDF_MOTION_TYPE_TOUCH_LINK , HDF_MOTION_TYPE_RESERVED , HDF_MOTION_TYPE_MAX<br/>} | 枚举运动类型。 | 


## 枚举类型说明


### HdfMotionTypeTag

```
enum HdfMotionTypeTag
```

**描述**


枚举运动类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_MOTION_TYPE_PICKUP | 拾取 | 
| HDF_MOTION_TYPE_FLIP | 翻转 | 
| HDF_MOTION_CLOSE_TO_EAR | 贴近耳朵 | 
| HDF_MOTION_TYPE_SHAKE | 抖动 | 
| HDF_MOTION_TYPE_ROTATION | 屏幕旋转 | 
| HDF_MOTION_TYPE_POCKET_MODE | 口袋模式 | 
| HDF_MOTION_TYPE_LEAVE_EAR | 远离耳朵 | 
| HDF_MOTION_TYPE_WRIST_UP | 手腕向上 | 
| HDF_MOTION_TYPE_WRIST_DOWN | 手腕向下 | 
| HDF_MOTION_TYPE_WAVE | 波浪 | 
| HDF_MOTION_TYPE_STEP_COUNTER | 步进计数器 | 
| HDF_MOTION_TYPE_TOUCH_LINK | 设备之间的接触 | 
| HDF_MOTION_TYPE_RESERVED | 预留字段 | 
| HDF_MOTION_TYPE_MAX | 最大运动类型 | 
