# Motion


## **概述**

手势识别设备驱动对硬件服务提供通用的接口能力。

模块提供硬件服务对手势识别驱动模块访问统一接口，服务获取驱动对象或者代理后，通过其提供的各类方法，实现使能手势识别/ 去使能手势识别、订阅/取消订阅手势识别数据。

**Since**:

3.2


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [IMotionCallback.idl](_i_motion_callback_8idl.md) | 定义上报手势识别数据回调函数接口。 | 
| [IMotionInterface.idl](_i_motion_interface_8idl.md) | 定义使能/去使能手势识别、订阅/取消订阅手势识别数据的接口。 | 
| [MotionTypes.idl](_motion_types_8idl.md) | 定义手势识别模块用到的数据结构，包括手势识别类型、上报的手势识别数据结构。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [IMotionCallback](interface_i_motion_callback.md) | 定义上报手势识别数据回调函数。 | 
| [IMotionInterface](interface_i_motion_interface.md) | 提供Motion设备基本控制操作接口。 | 
| [HdfMotionEvent](_hdf_motion_event.md) | 上报手势识别数据结构。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [HdfMotionTypeTag](#hdfmotiontypetag)&nbsp;{&nbsp;&nbsp;&nbsp;HDF_MOTION_TYPE_PICKUP&nbsp;=&nbsp;0,&nbsp;HDF_MOTION_TYPE_FLIP,&nbsp;HDF_MOTION_CLOSE_TO_EAR,&nbsp;HDF_MOTION_TYPE_SHAKE,&nbsp;&nbsp;&nbsp;HDF_MOTION_TYPE_ROTATION,&nbsp;HDF_MOTION_TYPE_POCKET_MODE,&nbsp;HDF_MOTION_TYPE_LEAVE_EAR,&nbsp;HDF_MOTION_TYPE_WRIST_UP,&nbsp;&nbsp;&nbsp;HDF_MOTION_TYPE_WRIST_DOWN,&nbsp;HDF_MOTION_TYPE_MAX&nbsp;} | 枚举手势识别类型。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.motion.v1_0 | 手势识别模块接口的包路径。 | 


## **枚举类型说明**


### HdfMotionTypeTag

  
```
enum HdfMotionTypeTag
```

**描述：**

枚举手势识别类型。

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
