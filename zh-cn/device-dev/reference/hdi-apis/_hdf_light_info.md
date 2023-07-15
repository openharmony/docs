# HdfLightInfo


## 概述

定义灯的基本信息。

参数包括灯类型ID、逻辑灯的名称、逻辑控制器中物理灯的数量和自定义扩展信息。

**Since:**
3.1
**Version:**
1.0
**相关模块:**

[Light](_light.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [lightName](#lightname) | String<br/>逻辑灯的名称。&nbsp; | 
| [lightId](#lightid) | int<br/>灯类型ID。详见[HdfLightId](_light.md#hdflightid)。&nbsp; | 
| [lightNumber](#lightnumber) | int<br/>逻辑控制器中物理灯的数量。&nbsp; | 
| [reserved](#reserved) | int<br/>自定义扩展信息。&nbsp; | 


## 类成员变量说明


### lightId

  
```
int HdfLightInfo::lightId
```
**描述:**
灯类型ID。详见[HdfLightId](_light.md#hdflightid)。


### lightName

  
```
String HdfLightInfo::lightName
```
**描述:**
逻辑灯的名称。


### lightNumber

  
```
int HdfLightInfo::lightNumber
```
**描述:**
逻辑控制器中物理灯的数量。


### reserved

  
```
int HdfLightInfo::reserved
```
**描述:**
自定义扩展信息。
