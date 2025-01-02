# InputDeviceInfo


## 概述

Input设备基础设备信息。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [devIndex](#devindex) | 设备索引  | 
| uint32_t [devType](#devtype) | 设备类型  | 
| char [chipInfo](#chipinfo) [[CHIP_INFO_LEN](_input.md#chip_info_len)] | 驱动芯片编码信息  | 
| char [vendorName](#vendorname) [[VENDOR_NAME_LEN](_input.md#vendor_name_len)] | 模组厂商名  | 
| char [chipName](#chipname) [[CHIP_NAME_LEN](_input.md#chip_name_len)] | 驱动芯片型号  | 
| [InputDevAttr](_input_dev_attr.md)[attrSet](#attrset) | 设备属性  | 
| [InputDevAbility](_input_dev_ability.md)[abilitySet](#abilityset) | 设备能力属性  | 


## 类成员变量说明


### abilitySet

```
InputDevAbility InputDeviceInfo::abilitySet
```
**描述**

设备能力属性


### attrSet

```
InputDevAttr InputDeviceInfo::attrSet
```
**描述**

设备属性


### chipInfo

```
char InputDeviceInfo::chipInfo[CHIP_INFO_LEN]
```
**描述**

驱动芯片编码信息


### chipName

```
char InputDeviceInfo::chipName[CHIP_NAME_LEN]
```
**描述**

驱动芯片型号


### devIndex

```
uint32_t InputDeviceInfo::devIndex
```
**描述**

设备索引


### devType

```
uint32_t InputDeviceInfo::devType
```
**描述**

设备类型


### vendorName

```
char InputDeviceInfo::vendorName[VENDOR_NAME_LEN]
```
**描述**

模组厂商名
