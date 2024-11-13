# HdfLightInfo


## 概述

定义灯的基本信息。

参数包括灯类型ID、逻辑灯的名称、逻辑控制器中物理灯的数量和自定义扩展信息。

**起始版本：** 3.1

**相关模块：**[Light](_light.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [lightName](#lightname) | 逻辑灯的名称。  | 
| int [lightId](#lightid) | 灯类型ID。详见[HdfLightId](_light.md#hdflightid)。  | 
| int [lightNumber](#lightnumber) | 逻辑控制器中物理灯的数量。  | 
| int [reserved](#reserved) | 自定义扩展信息。  | 


## 类成员变量说明


### lightId

```
int HdfLightInfo::lightId
```
**描述**

灯类型ID。详见[HdfLightId](_light.md#hdflightid)。


### lightName

```
String HdfLightInfo::lightName
```
**描述**

逻辑灯的名称。


### lightNumber

```
int HdfLightInfo::lightNumber
```
**描述**

逻辑控制器中物理灯的数量。


### reserved

```
int HdfLightInfo::reserved
```
**描述**

自定义扩展信息。
