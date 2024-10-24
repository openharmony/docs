# HdfWifiScanResult


## 概述

定义Wi-Fi扫描结果.

**起始版本：** 3.2

**相关模块：**[WLAN](_w_l_a_n_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [flags](#flags) | BSS/IBSS的标志位  | 
| unsigned char[] [bssid](#bssid) | BSSID信息  | 
| unsigned short [caps](#caps) | Capability信息字段（主机字节序排列）  | 
| unsigned int [freq](#freq) | 信道频率  | 
| unsigned short [beaconInt](#beaconint) | Beacon帧间隔  | 
| int [qual](#qual) | 信号质量  | 
| int [level](#level) | 信号强度  | 
| unsigned int [age](#age) | 收到最新的Beacon或者探测响应帧数据的时间长度，单位为毫秒。  | 
| unsigned char[] [variable](#variable) | 扫描结果中的变量值  | 
| unsigned char[] [ie](#ie) | 紧跟的Probe Response中IE字段  | 
| unsigned char[] [beaconIe](#beaconie) | 紧跟的Beacon中IE字段  | 


## 类成员变量说明


### age

```
unsigned int HdfWifiScanResult::age
```
**描述**

收到最新的Beacon或者探测响应帧数据的时间长度，单位为毫秒。


### beaconIe

```
unsigned char [] HdfWifiScanResult::beaconIe
```
**描述**

紧跟的Beacon中IE字段


### beaconInt

```
unsigned short HdfWifiScanResult::beaconInt
```
**描述**

Beacon帧间隔


### bssid

```
unsigned char [] HdfWifiScanResult::bssid
```
**描述**

BSSID信息


### caps

```
unsigned short HdfWifiScanResult::caps
```
**描述**

Capability信息字段（主机字节序排列）


### flags

```
unsigned int HdfWifiScanResult::flags
```
**描述**

BSS/IBSS的标志位


### freq

```
unsigned int HdfWifiScanResult::freq
```
**描述**

信道频率


### ie

```
unsigned char [] HdfWifiScanResult::ie
```
**描述**

紧跟的Probe Response中IE字段


### level

```
int HdfWifiScanResult::level
```
**描述**

信号强度


### qual

```
int HdfWifiScanResult::qual
```
**描述**

信号质量


### variable

```
unsigned char [] HdfWifiScanResult::variable
```
**描述**

扫描结果中的变量值
