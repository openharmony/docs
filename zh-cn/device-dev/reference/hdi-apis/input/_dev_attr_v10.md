# DevAttr


## 概述

Input设备属性。

**起始版本：** 3.2

**相关模块：**[HdiInput](_hdi_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [devName](#devname) | 设备名  | 
| struct [DevIdentify](_dev_identify_v10.md)[id](#id) | 设备识别信息  | 
| struct [DimensionInfo](_dimension_info_v10.md)[] [axisInfo](#axisinfo) | 设备维度信息  | 


## 类成员变量说明


### axisInfo

```
struct DimensionInfo [] DevAttr::axisInfo
```
**描述**

设备维度信息


### devName

```
String DevAttr::devName
```
**描述**

设备名


### id

```
struct DevIdentify DevAttr::id
```
**描述**

设备识别信息
