# ExtDataHandle


## 概述

扩展数据句柄结构体定义。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [fd](#fd) | 句柄 Fd, -1代表不支持  | 
| unsigned int [reserveInts](#reserveints) | Reserve数组的个数  | 
| int[] [reserve](#reserve) | Reserve数组  | 


## 类成员变量说明


### fd

```
int ExtDataHandle::fd
```
**描述**

句柄 Fd, -1代表不支持


### reserve

```
int [] ExtDataHandle::reserve
```
**描述**

Reserve数组


### reserveInts

```
unsigned int ExtDataHandle::reserveInts
```
**描述**

Reserve数组的个数
