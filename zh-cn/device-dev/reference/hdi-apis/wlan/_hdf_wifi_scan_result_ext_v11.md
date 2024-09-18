# HdfWifiScanResultExt


## 概述

定义Wi-Fi扫描扩展结果

**起始版本：** 4.0

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
| unsigned long [tsf](#tsf) | 时间戳  | 
| unsigned char[] [variable](#variable) | 扫描结果中的变量值  | 
| unsigned char[] [ie](#ie) | 紧跟的Probe Response中IE字段  | 
| unsigned char[] [beaconIe](#beaconie) | 紧跟的Beacon中IE字段  | 


## 类成员变量说明


### age

```
unsigned int HdfWifiScanResultExt::age
```
**描述**

收到最新的Beacon或者探测响应帧数据的时间长度，单位为毫秒。


### beaconIe

```
unsigned char [] HdfWifiScanResultExt::beaconIe
```
**描述**

紧跟的Beacon中IE字段


### beaconInt

```
unsigned short HdfWifiScanResultExt::beaconInt
```
**描述**

Beacon帧间隔


### bssid

```
unsigned char [] HdfWifiScanResultExt::bssid
```
**描述**

BSSID信息


### caps

```
unsigned short HdfWifiScanResultExt::caps
```
**描述**

Capability信息字段（主机字节序排列）


### flags

```
unsigned int HdfWifiScanResultExt::flags
```
**描述**

BSS/IBSS的标志位


### freq

```
unsigned int HdfWifiScanResultExt::freq
```
**描述**

信道频率


### ie

```
unsigned char [] HdfWifiScanResultExt::ie
```
**描述**

紧跟的Probe Response中IE字段


### level

```
int HdfWifiScanResultExt::level
```
**描述**

信号强度


### qual

```
int HdfWifiScanResultExt::qual
```
**描述**

信号质量


### tsf

```
unsigned long HdfWifiScanResultExt::tsf
```
**描述**

时间戳


### variable

```
unsigned char [] HdfWifiScanResultExt::variable
```
**描述**

扫描结果中的变量值
