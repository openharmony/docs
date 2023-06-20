# RilRadioResponseInfo


## 概述

响应通用信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [slotId](#slotid) | int<br/>卡槽ID&nbsp; | 
| [flag](#flag) | int<br/>响应标识&nbsp; | 
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [error](#error) | enum&nbsp;[RilErrType](_ril.md#rilerrtype)<br/>错误码&nbsp; | 
| [type](#type) | enum&nbsp;[RilResponseTypes](_ril.md#rilresponsetypes)<br/>响应类型，具体查看[RilResponseTypes](_ril.md#rilresponsetypes) | 


## 类成员变量说明


### error

  
```
enum RilErrType RilRadioResponseInfo::error
```
**描述:**
错误码


### flag

  
```
int RilRadioResponseInfo::flag
```
**描述:**
响应标识


### serial

  
```
int RilRadioResponseInfo::serial
```
**描述:**
请求的序列号


### slotId

  
```
int RilRadioResponseInfo::slotId
```
**描述:**
卡槽ID


### type

  
```
enum RilResponseTypes RilRadioResponseInfo::type
```
**描述:**
响应类型，具体查看[RilResponseTypes](_ril.md#rilresponsetypes)
