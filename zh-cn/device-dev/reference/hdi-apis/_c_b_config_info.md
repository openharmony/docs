# CBConfigInfo


## 概述

GSM小区广播配置信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [mode](#mode) | int<br/>是否激活&nbsp; | 
| [indicationType](#indicationtype) | int<br/>响应类型 | 
| [mids](#mids) | String<br/>消息标识符组合&nbsp; | 
| [dcss](#dcss) | String<br/>数据编码方案组合&nbsp; | 


## 类成员变量说明


### dcss

  
```
String CBConfigInfo::dcss
```
**描述:**
数据编码方案组合


### indicationType

  
```
int CBConfigInfo::indicationType
```
**描述:**
响应类型

- 0：查询上报

- 1：主动上报 


### mids

  
```
String CBConfigInfo::mids
```
**描述:**
消息标识符组合


### mode

  
```
int CBConfigInfo::mode
```
**描述:**
是否激活


### serial

  
```
int CBConfigInfo::serial
```
**描述:**
请求的序列号
