# ChargingLimit


## 概述

定义电池充电电流或电压的限制。

**起始版本：** 3.2

**相关模块：**[Battery](battery_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [ChargingLimitType](battery_v20.md#charginglimittype)[type](#type) | 定义电池充电限制类型  | 
| String [protocol](#protocol) | 限制协议描述  | 
| int [value](#value) | 选择限制类型，0-电流，1-电压  | 


## 类成员变量说明


### protocol

```
String ChargingLimit::protocol
```
**描述**

限制协议描述


### type

```
enum ChargingLimitType ChargingLimit::type
```
**描述**

定义电池充电限制类型


### value

```
int ChargingLimit::value
```
**描述**

选择限制类型，0-电流，1-电压
