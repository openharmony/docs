# PnoSettings


## 概述

定义Pno扫描参数

**起始版本：** 4.0

**相关模块：**[WLAN](_w_l_a_n_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [min2gRssi](#min2grssi) | 要扫描的最小2G Rssi  | 
| int [min5gRssi](#min5grssi) | 要扫描的最小5G Rssi  | 
| int [scanIntervalMs](#scanintervalms) | 扫描间隔  | 
| int [scanIterations](#scaniterations) | 扫描迭代  | 
| struct [PnoNetwork](_pno_network_v11.md)[] [pnoNetworks](#pnonetworks) | 扫描网络列表  | 


## 类成员变量说明


### min2gRssi

```
int PnoSettings::min2gRssi
```
**描述**

要扫描的最小2G Rssi


### min5gRssi

```
int PnoSettings::min5gRssi
```
**描述**

要扫描的最小5G Rssi


### pnoNetworks

```
struct PnoNetwork [] PnoSettings::pnoNetworks
```
**描述**

扫描网络列表


### scanIntervalMs

```
int PnoSettings::scanIntervalMs
```
**描述**

扫描间隔


### scanIterations

```
int PnoSettings::scanIterations
```
**描述**

扫描迭代
