# InputDevAttr


## 概述

Input设备属性。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| char [devName](#devname) [[DEV_NAME_LEN](_input.md#dev_name_len)] | 设备名  | 
| [InputDevIdentify](_input_dev_identify.md) [id](#id) | 设备识别信息  | 
| [InputDimensionInfo](_input_dimension_info.md) [axisInfo](#axisinfo) [ABS_CNT] | 设备维度信息  | 


## 类成员变量说明


### axisInfo

```
InputDimensionInfo InputDevAttr::axisInfo[ABS_CNT]
```
**描述**

设备维度信息


### devName

```
char InputDevAttr::devName[DEV_NAME_LEN]
```
**描述**

设备名


### id

```
InputDevIdentify InputDevAttr::id
```
**描述**

设备识别信息
