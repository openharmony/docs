# HdfWifiScan


## 概述

WiFi扫描参数。

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
| [ssids](#ssids) | struct&nbsp;[HdfWifiDriverScanSsid](_hdf_wifi_driver_scan_ssid.md)[]<br/>WiFi扫描的SSID集合。&nbsp; | 
| [freqs](#freqs) | int[]<br/>WiFi扫描的频率集合。&nbsp; | 
| [extraIes](#extraies) | unsigned&nbsp;char[]<br/>WiFi扫描请求中携带的扩展IE。&nbsp; | 
| [bssid](#bssid) | unsigned&nbsp;char[]<br/>WiFi扫描的BSSID。&nbsp; | 
| [prefixSsidScanFlag](#prefixssidscanflag) | unsigned&nbsp;char<br/>SSID扫描的前缀标志。&nbsp; | 
| [fastConnectFlag](#fastconnectflag) | unsigned&nbsp;char<br/>快速连接标志。&nbsp; | 


## 类成员变量说明


### bssid

  
```
unsigned char [] HdfWifiScan::bssid
```
**描述:**
WiFi扫描的BSSID。


### extraIes

  
```
unsigned char [] HdfWifiScan::extraIes
```
**描述:**
WiFi扫描请求中携带的扩展IE。


### fastConnectFlag

  
```
unsigned char HdfWifiScan::fastConnectFlag
```
**描述:**
快速连接标志。


### freqs

  
```
int [] HdfWifiScan::freqs
```
**描述:**
WiFi扫描的频率集合。


### prefixSsidScanFlag

  
```
unsigned char HdfWifiScan::prefixSsidScanFlag
```
**描述:**
SSID扫描的前缀标志。


### ssids

  
```
struct HdfWifiDriverScanSsid [] HdfWifiScan::ssids
```
**描述:**
WiFi扫描的SSID集合。
