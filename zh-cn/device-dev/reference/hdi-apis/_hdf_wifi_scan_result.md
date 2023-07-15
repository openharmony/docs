# HdfWifiScanResult


## 概述

WiFi扫描结果。

**Since:**
3.2
**Version:**
1.0
**相关模块:**

[WLAN](_w_l_a_n.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [flags](#flags) | int<br/>BSS/IBSS的标志位。&nbsp; | 
| [bssid](#bssid) | unsigned&nbsp;char[]<br/>BSSID信息。&nbsp; | 
| [caps](#caps) | short<br/>Capability信息字段（主机字节序排列）。&nbsp; | 
| [freq](#freq) | int<br/>信道频率。&nbsp; | 
| [beaconInt](#beaconint) | short<br/>Beacon帧间隔。&nbsp; | 
| [qual](#qual) | int<br/>信号质量。&nbsp; | 
| [level](#level) | int<br/>信号强度。&nbsp; | 
| [age](#age) | unsigned&nbsp;int<br/>收到最新的Beacon或者探测响应帧数据的时间长度，单位为毫秒。&nbsp; | 
| [variable](#variable) | unsigned&nbsp;char[]<br/>扫描结果中的变量值。&nbsp; | 
| [ie](#ie) | unsigned&nbsp;char[]<br/>紧跟的Probe&nbsp;Response中IE字段。&nbsp; | 
| [beaconIe](#beaconie) | unsigned&nbsp;char[]<br/>紧跟的Beacon中IE字段。&nbsp; | 


## 类成员变量说明


### age

  
```
unsigned int HdfWifiScanResult::age
```
**描述:**
收到最新的Beacon或者探测响应帧数据的时间长度，单位为毫秒。


### beaconIe

  
```
unsigned char [] HdfWifiScanResult::beaconIe
```
**描述:**
紧跟的Beacon中IE字段。


### beaconInt

  
```
short HdfWifiScanResult::beaconInt
```
**描述:**
Beacon帧间隔。


### bssid

  
```
unsigned char [] HdfWifiScanResult::bssid
```
**描述:**
BSSID信息。


### caps

  
```
short HdfWifiScanResult::caps
```
**描述:**
Capability信息字段（主机字节序排列）。


### flags

  
```
int HdfWifiScanResult::flags
```
**描述:**
BSS/IBSS的标志位。


### freq

  
```
int HdfWifiScanResult::freq
```
**描述:**
信道频率。


### ie

  
```
unsigned char [] HdfWifiScanResult::ie
```
**描述:**
紧跟的Probe Response中IE字段。


### level

  
```
int HdfWifiScanResult::level
```
**描述:**
信号强度。


### qual

  
```
int HdfWifiScanResult::qual
```
**描述:**
信号质量。


### variable

  
```
unsigned char [] HdfWifiScanResult::variable
```
**描述:**
扫描结果中的变量值。
