# CdmaRssi


## 概述

CDMA信号强度。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [absoluteRssi](#absoluterssi) | 信号强度的绝对值, 该值是实际信号强度值乘以-1  | 
| int [ecno](#ecno) | PN码（Pseudo-Noise Code）片的接收能量与总接收功率谱密度之比  | 


## 类成员变量说明


### absoluteRssi

```
int CdmaRssi::absoluteRssi
```
**描述**

信号强度的绝对值, 该值是实际信号强度值乘以-1


### ecno

```
int CdmaRssi::ecno
```
**描述**

PN码（Pseudo-Noise Code）片的接收能量与总接收功率谱密度之比
