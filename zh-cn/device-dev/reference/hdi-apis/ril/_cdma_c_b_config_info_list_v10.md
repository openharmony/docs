# CdmaCBConfigInfoList


## 概述

CDMA小区广播配置信息列表。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [size](#size) | 总数  | 
| List&lt; struct [CdmaCBConfigInfo](_cdma_c_b_config_info_v10.md) &gt; [list](#list) | CDMA小区广播配置信息列表  | 


## 类成员变量说明


### list

```
List<struct CdmaCBConfigInfo> CdmaCBConfigInfoList::list
```
**描述**

CDMA小区广播配置信息列表


### serial

```
int CdmaCBConfigInfoList::serial
```
**描述**

请求的序列号


### size

```
int CdmaCBConfigInfoList::size
```
**描述**

总数
