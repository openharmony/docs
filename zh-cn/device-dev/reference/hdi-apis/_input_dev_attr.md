# InputDevAttr


## **概述**

Input设备属性。

**相关模块:**

[Input](input.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [devName](#devname)&nbsp;[DEV_NAME_LEN] | 设备名 | 
| [id](#id) | 设备识别信息 | 
| [axisInfo](#axisinfo)&nbsp;[ABS_CNT] | 设备维度信息 | 


## **类成员变量说明**


### axisInfo

  
```
InputDimensionInfo InputDevAttr::axisInfo[ABS_CNT]
```

**描述：**

设备维度信息


### devName

  
```
char InputDevAttr::devName[DEV_NAME_LEN]
```

**描述：**

设备名


### id

  
```
InputDevIdentify InputDevAttr::id
```

**描述：**

设备识别信息
