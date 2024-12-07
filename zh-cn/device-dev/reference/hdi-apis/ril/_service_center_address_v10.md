# ServiceCenterAddress


## 概述

短信中心地址信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [tosca](#tosca) | 短信中心地址类型，参考3GPP TS 24.011 [6]  | 
| String [address](#address) | 短信中心地址，参考3GPP TS 24.011 [6]  | 


## 类成员变量说明


### address

```
String ServiceCenterAddress::address
```
**描述**

短信中心地址，参考3GPP TS 24.011 [6]


### serial

```
int ServiceCenterAddress::serial
```
**描述**

请求的序列号


### tosca

```
int ServiceCenterAddress::tosca
```
**描述**

短信中心地址类型，参考3GPP TS 24.011 [6]
