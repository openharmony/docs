# ServiceCenterAddress


## 概述

短信中心地址信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [tosca](#tosca) | int<br/>短信中心地址类型，参考3GPP&nbsp;TS&nbsp;24.011&nbsp;[6]&nbsp; | 
| [address](#address) | String<br/>短信中心地址，参考3GPP&nbsp;TS&nbsp;24.011&nbsp;[6]&nbsp; | 


## 类成员变量说明


### address

  
```
String ServiceCenterAddress::address
```
**描述:**
短信中心地址，参考3GPP TS 24.011 [6]


### serial

  
```
int ServiceCenterAddress::serial
```
**描述:**
请求的序列号


### tosca

  
```
int ServiceCenterAddress::tosca
```
**描述:**
短信中心地址类型，参考3GPP TS 24.011 [6]
