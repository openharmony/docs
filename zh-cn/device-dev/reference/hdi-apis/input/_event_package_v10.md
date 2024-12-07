# EventPackage


## 概述

Input事件数据包结构。

**起始版本：** 3.2

**相关模块：**[HdiInput](_hdi_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [type](#type) | 输入事件的属性  | 
| unsigned int [code](#code) | 输入事件的特定编码项  | 
| int [value](#value) | 输入事件编码项对应的值  | 
| unsigned long [timestamp](#timestamp) | 输入事件对应的时间戳  | 


## 类成员变量说明


### code

```
unsigned int EventPackage::code
```
**描述**

输入事件的特定编码项


### timestamp

```
unsigned long EventPackage::timestamp
```
**描述**

输入事件对应的时间戳


### type

```
unsigned int EventPackage::type
```
**描述**

输入事件的属性


### value

```
int EventPackage::value
```
**描述**

输入事件编码项对应的值
