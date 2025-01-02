# HdfWifiScan


## 概述

定义Wi-Fi扫描参数.

**起始版本：** 3.2

**相关模块：**[WLAN](_w_l_a_n_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| struct [HdfWifiDriverScanSsid](_hdf_wifi_driver_scan_ssid_v11.md)[] [ssids](#ssids) | WiFi扫描的SSID集合  | 
| int[] [freqs](#freqs) | WiFi扫描的频率集合  | 
| unsigned char[] [extraIes](#extraies) | WiFi扫描请求中携带的扩展IE  | 
| unsigned char[] [bssid](#bssid) | WiFi扫描的BSSID  | 
| unsigned char [prefixSsidScanFlag](#prefixssidscanflag) | SSID扫描的前缀标志  | 
| unsigned char [fastConnectFlag](#fastconnectflag) | 快速连接标志  | 


## 类成员变量说明


### bssid

```
unsigned char [] HdfWifiScan::bssid
```
**描述**

WiFi扫描的BSSID


### extraIes

```
unsigned char [] HdfWifiScan::extraIes
```
**描述**

WiFi扫描请求中携带的扩展IE


### fastConnectFlag

```
unsigned char HdfWifiScan::fastConnectFlag
```
**描述**

快速连接标志


### freqs

```
int [] HdfWifiScan::freqs
```
**描述**

WiFi扫描的频率集合


### prefixSsidScanFlag

```
unsigned char HdfWifiScan::prefixSsidScanFlag
```
**描述**

SSID扫描的前缀标志


### ssids

```
struct HdfWifiDriverScanSsid [] HdfWifiScan::ssids
```
**描述**

WiFi扫描的SSID集合
