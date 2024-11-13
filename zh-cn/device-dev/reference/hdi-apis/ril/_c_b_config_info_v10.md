# CBConfigInfo


## 概述

GSM小区广播配置信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [mode](#mode) | 是否激活  | 
| int [indicationType](#indicationtype) | 响应类型 | 
| String [mids](#mids) | 消息标识符组合  | 
| String [dcss](#dcss) | 数据编码方案组合  | 


## 类成员变量说明


### dcss

```
String CBConfigInfo::dcss
```
**描述**

数据编码方案组合


### indicationType

```
int CBConfigInfo::indicationType
```
**描述**

响应类型

- 0：查询上报

- 1：主动上报 


### mids

```
String CBConfigInfo::mids
```
**描述**

消息标识符组合


### mode

```
int CBConfigInfo::mode
```
**描述**

是否激活


### serial

```
int CBConfigInfo::serial
```
**描述**

请求的序列号
