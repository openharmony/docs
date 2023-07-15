# InputDevAttr


## 概述

Input设备属性。

**相关模块:**

[Input](_input.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [devName](#devname)&nbsp;[[DEV_NAME_LEN](_input.md#dev_name_len)] | char<br/>设备名&nbsp; | 
| [id](#id) | [InputDevIdentify](_input_dev_identify.md)<br/>设备识别信息&nbsp; | 
| [axisInfo](#axisinfo)&nbsp;[ABS_CNT] | [InputDimensionInfo](_input_dimension_info.md)<br/>设备维度信息&nbsp; | 


## 类成员变量说明


### axisInfo

  
```
InputDimensionInfo InputDevAttr::axisInfo[ABS_CNT]
```
**描述:**
设备维度信息


### devName

  
```
char InputDevAttr::devName[DEV_NAME_LEN]
```
**描述:**
设备名


### id

  
```
InputDevIdentify InputDevAttr::id
```
**描述:**
设备识别信息
