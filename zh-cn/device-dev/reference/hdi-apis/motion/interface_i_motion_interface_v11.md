# IMotionInterface


## 概述

提供Motion设备基本控制操作接口。

接口提供使能/去使能手势识别、订阅/取消订阅手势识别数据功能。

**起始版本：** 4.0

**相关模块：**[Motion](_motion_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetMotionConfig](#setmotionconfig) ([in] int motionType, [in] unsigned char[] data) | 设置运动配置信息。  | 


## 成员函数说明


### SetMotionConfig()

```
IMotionInterface::SetMotionConfig ([in] int motionType, [in] unsigned char[] data )
```
**描述**

设置运动配置信息。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| motionType | 运动类型。有关详细信息，请参阅[HdfMotionTypeTag](_motion_v11.md#hdfmotiontypetag)。  | 
| data | 一个技巧的运动波配置参数。有关详细信息，请参阅[WaveParam](_wave_param_v11.md)。  | 
| len | 数据长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
