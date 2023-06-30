# CBConfigReportInfo


## 概述

小区广播上报信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [indicationType](#indicationtype) | int<br/>响应类型 | 
| [sn](#sn) | int<br/>小区广播序列号&nbsp; | 
| [mid](#mid) | int<br/>消息标识符组合&nbsp; | 
| [page](#page) | int<br/>小区广播页序号&nbsp; | 
| [pages](#pages) | int<br/>小区广播总页数&nbsp; | 
| [length](#length) | int<br/>pdu字节数&nbsp; | 
| [data](#data) | String<br/>解码后的小区广播内容&nbsp; | 
| [dcs](#dcs) | String<br/>数据编码方案组合&nbsp; | 
| [pdu](#pdu) | String<br/>协议数据单元&nbsp; | 


## 类成员变量说明


### data

  
```
String CBConfigReportInfo::data
```
**描述:**
解码后的小区广播内容


### dcs

  
```
String CBConfigReportInfo::dcs
```
**描述:**
数据编码方案组合


### indicationType

  
```
int CBConfigReportInfo::indicationType
```
**描述:**
响应类型

- 0：查询上报

- 1：主动上报 


### length

  
```
int CBConfigReportInfo::length
```
**描述:**
pdu字节数


### mid

  
```
int CBConfigReportInfo::mid
```
**描述:**
消息标识符组合


### page

  
```
int CBConfigReportInfo::page
```
**描述:**
小区广播页序号


### pages

  
```
int CBConfigReportInfo::pages
```
**描述:**
小区广播总页数


### pdu

  
```
String CBConfigReportInfo::pdu
```
**描述:**
协议数据单元


### sn

  
```
int CBConfigReportInfo::sn
```
**描述:**
小区广播序列号
