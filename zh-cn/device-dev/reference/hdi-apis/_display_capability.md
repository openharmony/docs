# DisplayCapability


## 概述

定义输出性能。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [name](_display.md#name-22)&nbsp;[[PROPERTY_NAME_LEN](_display.md#property_name_len)] | char<br/>显示设备名称 | 
| [type](_display.md#type-27) | [InterfaceType](_display.md#interfacetype)<br/>显示屏接口类型 | 
| [phyWidth](_display.md#phywidth) | uint32_t<br/>物理宽度 | 
| [phyHeight](_display.md#phyheight) | uint32_t<br/>物理高度 | 
| [supportLayers](_display.md#supportlayers) | uint32_t<br/>支持的图层数 | 
| [virtualDispCount](_display.md#virtualdispcount) | uint32_t<br/>支持的虚拟屏数 | 
| [supportWriteBack](_display.md#supportwriteback) | bool<br/>是否支持回写 | 
| [propertyCount](_display.md#propertycount) | uint32_t<br/>属性数组大小 | 
| [props](_display.md#props) | [PropertyObject](_property_object.md)&nbsp;\*<br/>属性数组 | 
