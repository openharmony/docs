# DeviceInfo


## 概述

Input设备基础设备信息。

**起始版本：** 3.2

**相关模块：**[HdiInput](_hdi_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [devIndex](#devindex) | 设备索引  | 
| unsigned int [devType](#devtype) | 设备类型  | 
| String [chipInfo](#chipinfo) | 驱动芯片编码信息  | 
| String [vendorName](#vendorname) | 模组厂商名  | 
| String [chipName](#chipname) | 驱动芯片型号  | 
| struct [DevAttr](_dev_attr_v10.md)[attrSet](#attrset) | 设备属性  | 
| struct [DevAbility](_dev_ability_v10.md)[abilitySet](#abilityset) | 设备能力属性  | 


## 类成员变量说明


### abilitySet

```
struct DevAbility DeviceInfo::abilitySet
```
**描述**

设备能力属性


### attrSet

```
struct DevAttr DeviceInfo::attrSet
```
**描述**

设备属性


### chipInfo

```
String DeviceInfo::chipInfo
```
**描述**

驱动芯片编码信息


### chipName

```
String DeviceInfo::chipName
```
**描述**

驱动芯片型号


### devIndex

```
unsigned int DeviceInfo::devIndex
```
**描述**

设备索引


### devType

```
unsigned int DeviceInfo::devType
```
**描述**

设备类型


### vendorName

```
String DeviceInfo::vendorName
```
**描述**

模组厂商名
