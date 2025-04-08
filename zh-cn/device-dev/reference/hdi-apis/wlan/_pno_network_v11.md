# PnoNetwork


## 概述

定义Pno扫描网络信息

**起始版本：** 4.0

**相关模块：**[WLAN](_w_l_a_n_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [isHidden](#ishidden) | isHidden为true支持扫描隐藏网络，反之为false则不支持扫描隐藏网络  | 
| int[] [freqs](#freqs) | 扫描频率  | 
| struct [HdfWifiDriverScanSsid](_hdf_wifi_driver_scan_ssid_v11.md)[ssid](#ssid) | 扫描SSID  | 


## 类成员变量说明


### freqs

```
int [] PnoNetwork::freqs
```
**描述**

扫描频率


### isHidden

```
boolean PnoNetwork::isHidden
```
**描述**

是否扫描隐藏网络


### ssid

```
struct HdfWifiDriverScanSsid PnoNetwork::ssid
```
**描述**

扫描SSID
