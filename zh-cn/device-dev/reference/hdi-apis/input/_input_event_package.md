# InputEventPackage


## 概述

Input事件数据包结构。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [type](#type) | 输入事件的属性  | 
| uint32_t [code](#code) | 输入事件的特定编码项  | 
| int32_t [value](#value) | 输入事件编码项对应的值  | 
| uint64_t [timestamp](#timestamp) | 输入事件对应的时间戳  | 


## 类成员变量说明


### code

```
uint32_t InputEventPackage::code
```
**描述**

输入事件的特定编码项


### timestamp

```
uint64_t InputEventPackage::timestamp
```
**描述**

输入事件对应的时间戳


### type

```
uint32_t InputEventPackage::type
```
**描述**

输入事件的属性


### value

```
int32_t InputEventPackage::value
```
**描述**

输入事件编码项对应的值
