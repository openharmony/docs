# InputDeviceInfo


## 概述

Input设备基础设备信息。

**相关模块:**

[Input](_input.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [devIndex](#devindex) | uint32_t<br/>设备索引&nbsp; | 
| [devType](#devtype) | uint32_t<br/>设备类型&nbsp; | 
| [chipInfo](#chipinfo)&nbsp;[[CHIP_INFO_LEN](_input.md#chip_info_len)] | char<br/>驱动芯片编码信息&nbsp; | 
| [vendorName](#vendorname)&nbsp;[[VENDOR_NAME_LEN](_input.md#vendor_name_len)] | char<br/>模组厂商名&nbsp; | 
| [chipName](#chipname)&nbsp;[[CHIP_NAME_LEN](_input.md#chip_name_len)] | char<br/>驱动芯片型号&nbsp; | 
| [attrSet](#attrset) | [InputDevAttr](_input_dev_attr.md)<br/>设备属性&nbsp; | 
| [abilitySet](#abilityset) | [InputDevAbility](_input_dev_ability.md)<br/>设备能力属性&nbsp; | 


## 类成员变量说明


### abilitySet

  
```
InputDevAbility InputDeviceInfo::abilitySet
```
**描述:**
设备能力属性


### attrSet

  
```
InputDevAttr InputDeviceInfo::attrSet
```
**描述:**
设备属性


### chipInfo

  
```
char InputDeviceInfo::chipInfo[CHIP_INFO_LEN]
```
**描述:**
驱动芯片编码信息


### chipName

  
```
char InputDeviceInfo::chipName[CHIP_NAME_LEN]
```
**描述:**
驱动芯片型号


### devIndex

  
```
uint32_t InputDeviceInfo::devIndex
```
**描述:**
设备索引


### devType

  
```
uint32_t InputDeviceInfo::devType
```
**描述:**
设备类型


### vendorName

  
```
char InputDeviceInfo::vendorName[VENDOR_NAME_LEN]
```
**描述:**
模组厂商名
