# DisplayCapability


## 概述

定义输出性能。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [name](#name) | 显示设备名称  | 
| enum [InterfaceType](_display_v10.md#interfacetype)[type](#type) | 显示屏接口类型  | 
| unsigned int [phyWidth](#phywidth) | 物理宽度  | 
| unsigned int [phyHeight](#phyheight) | 物理高度  | 
| unsigned int [supportLayers](#supportlayers) | 支持的图层数  | 
| unsigned int [virtualDispCount](#virtualdispcount) | 支持的虚拟屏数  | 
| boolean [supportWriteBack](#supportwriteback) | 是否支持回写  | 
| unsigned int [propertyCount](#propertycount) | 属性数组大小  | 
| struct [PropertyObject](_property_object_v10.md)[] [props](#props) | 属性数组  | 


## 类成员变量说明


### name

```
String DisplayCapability::name
```
**描述**

显示设备名称


### phyHeight

```
unsigned int DisplayCapability::phyHeight
```
**描述**

物理高度


### phyWidth

```
unsigned int DisplayCapability::phyWidth
```
**描述**

物理宽度


### propertyCount

```
unsigned int DisplayCapability::propertyCount
```
**描述**

属性数组大小


### props

```
struct PropertyObject [] DisplayCapability::props
```
**描述**

属性数组


### supportLayers

```
unsigned int DisplayCapability::supportLayers
```
**描述**

支持的图层数


### supportWriteBack

```
boolean DisplayCapability::supportWriteBack
```
**描述**

是否支持回写


### type

```
enum InterfaceType DisplayCapability::type
```
**描述**

显示屏接口类型


### virtualDispCount

```
unsigned int DisplayCapability::virtualDispCount
```
**描述**

支持的虚拟屏数
