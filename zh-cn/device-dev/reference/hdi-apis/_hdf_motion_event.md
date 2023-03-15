# HdfMotionEvent


## **概述**

上报手势识别数据结构。

上报手势识别数据事件信息包括手势识别类型、手势识别结果、手势识别状态、手势识别数据长度、手势识别数据。

**相关模块:**

[Motion](motion.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [motion](#motion) | 手势识别类型。 | 
| [result](#result) | 手势识别结果。 | 
| [status](#status) | 手势识别状态。 | 
| [datalen](#datalen) | 手势识别数据长度。 | 
| [data](#data) | 手势识别数据。 | 


## **类成员变量说明**


### data

  
```
int [] HdfMotionEvent::data
```

**描述：**

手势识别数据。


### datalen

  
```
int HdfMotionEvent::datalen
```

**描述：**

手势识别数据长度。


### motion

  
```
int HdfMotionEvent::motion
```

**描述：**

手势识别类型。


### result

  
```
int HdfMotionEvent::result
```

**描述：**

手势识别结果。


### status

  
```
int HdfMotionEvent::status
```

**描述：**

手势识别状态。
