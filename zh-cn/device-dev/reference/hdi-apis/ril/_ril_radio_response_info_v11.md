# RilRadioResponseInfo


## 概述

响应通用信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [slotId](#slotid) | 卡槽ID  | 
| int [flag](#flag) | 响应标识  | 
| int [serial](#serial) | 请求的序列号  | 
| enum [RilErrType](_ril_v11.md#rilerrtype)[error](#error) | 错误码  | 
| enum [RilResponseTypes](_ril_v11.md#rilresponsetypes)[type](#type) | 响应类型，具体查看[RilResponseTypes](_ril_v11.md#rilresponsetypes) | 


## 类成员变量说明


### error

```
enum RilErrType RilRadioResponseInfo::error
```
**描述**

错误码


### flag

```
int RilRadioResponseInfo::flag
```
**描述**

响应标识


### serial

```
int RilRadioResponseInfo::serial
```
**描述**

请求的序列号


### slotId

```
int RilRadioResponseInfo::slotId
```
**描述**

卡槽ID


### type

```
enum RilResponseTypes RilRadioResponseInfo::type
```
**描述**

响应类型，具体查看[RilResponseTypes](_ril_v11.md#rilresponsetypes)
