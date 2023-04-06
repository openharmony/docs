# IMotionInterface


## **概述**

提供Motion设备基本控制操作接口。

接口提供使能/去使能手势识别、订阅/取消订阅手势识别数据功能。

**相关模块:**

[Motion](motion.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [EnableMotion](#enablemotion)&nbsp;([in]&nbsp;int&nbsp;motionType) | 使能手势识别。 | 
| [DisableMotion](#disablemotion)&nbsp;([in]&nbsp;int&nbsp;motionType) | 去使能手势识别。 | 
| [Register](#register)&nbsp;([in]&nbsp;[IMotionCallback](interface_i_motion_callback.md)&nbsp;callbackObj) | 订阅者注册手势识别数据回调函数，如果注册成功，系统会将获取到的手势识别数据上报给订阅者。 | 
| [Unregister](#unregister)&nbsp;([in]&nbsp;[IMotionCallback](interface_i_motion_callback.md)&nbsp;callbackObj) | 订阅者取消注册手势识别数据回调函数。 | 


## **成员函数说明**


### DisableMotion()

  
```
IMotionInterface::DisableMotion ([in] int motionType)
```

**描述：**

去使能手势识别。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| motionType | 手势识别类型，详见[HdfMotionTypeTag](motion.md#hdfmotiontypetag)。 | 


### EnableMotion()

  
```
IMotionInterface::EnableMotion ([in] int motionType)
```

**描述：**

使能手势识别。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| motionType | 手势识别类型，详见[HdfMotionTypeTag](motion.md#hdfmotiontypetag)。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Register()

  
```
IMotionInterface::Register ([in] IMotionCallback callbackObj)
```

**描述：**

订阅者注册手势识别数据回调函数，如果注册成功，系统会将获取到的手势识别数据上报给订阅者。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要注册的回调函数，只需成功订阅一次，无需重复订阅。详见[IMotionCallback](interface_i_motion_callback.md)。 | 

**返回:**

如果注册回调函数成功，则返回0。

如果注册回调函数失败，则返回负值。


### Unregister()

  
```
IMotionInterface::Unregister ([in] IMotionCallback callbackObj)
```

**描述：**

订阅者取消注册手势识别数据回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要取消注册的回调函数，只需成功取消订阅一次，无需重复取消订阅。详见[IMotionCallback](interface_i_motion_callback.md)。 | 

**返回:**

如果取消注册回调函数成功，则返回0。

如果取消注册回调函数失败，则返回负值。
