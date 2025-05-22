# DevAbility


## 概述

Input设备的能力属性，存储支持事件的位图。

用位的方式来表示该Input设备能够上报的事件类型。

**起始版本：** 3.2

**相关模块：**[HdiInput](_hdi_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long[] [devProp](#devprop) | 设备属性  | 
| unsigned long[] [eventType](#eventtype) | 用于记录支持的事件类型的位图  | 
| unsigned long[] [absCode](#abscode) | 记录支持的绝对坐标的位图  | 
| unsigned long[] [relCode](#relcode) | 记录支持的相对坐标的位图  | 
| unsigned long[] [keyCode](#keycode) | 记录支持的按键值的位图  | 
| unsigned long[] [ledCode](#ledcode) | 记录设备支持的指示灯的位图  | 
| unsigned long[] [miscCode](#misccode) | 记录设备支持的其他功能的位图  | 
| unsigned long[] [soundCode](#soundcode) | 记录设备支持的声音或警报的位图  | 
| unsigned long[] [forceCode](#forcecode) | 记录设备支持的作用力功能的位图  | 
| unsigned long[] [switchCode](#switchcode) | 记录设备支持的开关功能的位图  | 
| unsigned long[] [keyType](#keytype) | 按键类型的位图  | 
| unsigned long[] [ledType](#ledtype) | LED类型的位图  | 
| unsigned long[] [soundType](#soundtype) | 声音类型的位图  | 
| unsigned long[] [switchType](#switchtype) | 开关类型的位图  | 


## 类成员变量说明


### absCode

```
unsigned long [] DevAbility::absCode
```
**描述**

记录支持的绝对坐标的位图


### devProp

```
unsigned long [] DevAbility::devProp
```
**描述**

设备属性


### eventType

```
unsigned long [] DevAbility::eventType
```
**描述**

用于记录支持的事件类型的位图


### forceCode

```
unsigned long [] DevAbility::forceCode
```
**描述**

记录设备支持的作用力功能的位图


### keyCode

```
unsigned long [] DevAbility::keyCode
```
**描述**

记录支持的按键值的位图


### keyType

```
unsigned long [] DevAbility::keyType
```
**描述**

按键类型的位图


### ledCode

```
unsigned long [] DevAbility::ledCode
```
**描述**

记录设备支持的指示灯的位图


### ledType

```
unsigned long [] DevAbility::ledType
```
**描述**

LED类型的位图


### miscCode

```
unsigned long [] DevAbility::miscCode
```
**描述**

记录设备支持的其他功能的位图


### relCode

```
unsigned long [] DevAbility::relCode
```
**描述**

记录支持的相对坐标的位图


### soundCode

```
unsigned long [] DevAbility::soundCode
```
**描述**

记录设备支持的声音或警报的位图


### soundType

```
unsigned long [] DevAbility::soundType
```
**描述**

声音类型的位图


### switchCode

```
unsigned long [] DevAbility::switchCode
```
**描述**

记录设备支持的开关功能的位图


### switchType

```
unsigned long [] DevAbility::switchType
```
**描述**

开关类型的位图
