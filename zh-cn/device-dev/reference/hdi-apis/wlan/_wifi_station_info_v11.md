# WifiStationInfo


## 概述

定义STA信息

**起始版本：** 3.2

**相关模块：**[WLAN](_w_l_a_n_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [rxRate](#rxrate) | 接收速率。  | 
| unsigned int [txRate](#txrate) | 发送速率。  | 
| unsigned int [flags](#flags) | 速率传输类型。  | 
| unsigned char [rxVhtmcs](#rxvhtmcs) | 接收VHT-MCS（Very High Throughput Modulation and Coding Scheme）配置。  | 
| unsigned char [txVhtmcs](#txvhtmcs) | 发送VHT-MCS（Very High Throughput Modulation and Coding Scheme）配置。  | 
| unsigned char [rxMcs](#rxmcs) | 接收MCS（Modulation and Coding Scheme）索引。  | 
| unsigned char [txMcs](#txmcs) | 发送MCS（Modulation and Coding Scheme）索引。  | 
| unsigned char [rxVhtNss](#rxvhtnss) | 接收VHT-NSS（Very High Throughput Number of Spatial Streams）配置。  | 
| unsigned char [txVhtNss](#txvhtnss) | 发送VHT-NSS（Very High Throughput Number of Spatial Streams）配置。  | 


## 类成员变量说明


### flags

```
unsigned int WifiStationInfo::flags
```
**描述**

速率传输类型。


### rxMcs

```
unsigned char WifiStationInfo::rxMcs
```
**描述**

接收MCS（Modulation and Coding Scheme）索引。


### rxRate

```
unsigned int WifiStationInfo::rxRate
```
**描述**

接收速率。


### rxVhtmcs

```
unsigned char WifiStationInfo::rxVhtmcs
```
**描述**

接收VHT-MCS（Very High Throughput Modulation and Coding Scheme）配置。


### rxVhtNss

```
unsigned char WifiStationInfo::rxVhtNss
```
**描述**

接收VHT-NSS（Very High Throughput Number of Spatial Streams）配置。


### txMcs

```
unsigned char WifiStationInfo::txMcs
```
**描述**

发送MCS（Modulation and Coding Scheme）索引。


### txRate

```
unsigned int WifiStationInfo::txRate
```
**描述**

发送速率。


### txVhtmcs

```
unsigned char WifiStationInfo::txVhtmcs
```
**描述**

发送VHT-MCS（Very High Throughput Modulation and Coding Scheme）配置。


### txVhtNss

```
unsigned char WifiStationInfo::txVhtNss
```
**描述**

发送VHT-NSS（Very High Throughput Number of Spatial Streams）配置。
