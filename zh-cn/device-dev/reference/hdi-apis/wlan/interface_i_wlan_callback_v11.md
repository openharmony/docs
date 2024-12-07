# IWlanCallback


## 概述

定义WLAN模块的回调。

当WLAN模块发生重启，扫描热点结束，收到Netlink消息后，调用回调函数，处理对应的结果信息。

**起始版本：** 3.2

**相关模块：**[WLAN](_w_l_a_n_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ResetDriverResult](#resetdriverresult) ([in] unsigned int event, [in] int code, [in] String ifName) | 调用此方法，处理WLAN驱动重启时，返回的结果。  | 
| [ScanResult](#scanresult) ([in] unsigned int event, [in] struct [HdfWifiScanResult](_hdf_wifi_scan_result_v11.md) scanResult, [in] String ifName) | 调用此方法，处理扫描结束时，返回的扫描结果。  | 
| [WifiNetlinkMessage](#wifinetlinkmessage) ([in] unsigned char[] recvMsg) | 调用此方法以处理收到的Netlink消息。  | 
| [ScanResults](#scanresults) ([in] unsigned int event, [in] struct [HdfWifiScanResults](_hdf_wifi_scan_results_v11.md) scanResults, [in] String ifName) | 调用此方法，以处理扫描完成时，返回的扫描结果。  | 


## 成员函数说明


### ResetDriverResult()

```
IWlanCallback::ResetDriverResult ([in] unsigned int event, [in] int code, [in] String ifName )
```
**描述**

调用此方法，处理WLAN驱动重启时，返回的结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示驱动重启事件ID  | 
| code | 表示重启驱动时的返回结果  | 
| ifName | 表示网卡(NIC)名称 | 


### ScanResult()

```
IWlanCallback::ScanResult ([in] unsigned int event, [in] struct HdfWifiScanResult scanResult, [in] String ifName )
```
**描述**

调用此方法，处理扫描结束时，返回的扫描结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示扫描结果事件的ID  | 
| scanResult | 表示扫描结果  | 
| ifName | 表示网卡(NIC)名称 | 


### ScanResults()

```
IWlanCallback::ScanResults ([in] unsigned int event, [in] struct HdfWifiScanResults scanResults, [in] String ifName )
```
**描述**

调用此方法，以处理扫描完成时，返回的扫描结果。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示扫描结果事件的ID  | 
| scanResults | 表示扫描结果(多个)  | 
| ifName | 表示网卡(NIC)名称 | 


### WifiNetlinkMessage()

```
IWlanCallback::WifiNetlinkMessage ([in] unsigned char[] recvMsg)
```
**描述**

调用此方法以处理收到的Netlink消息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recvMsg | 表示收到的Netlink消息 | 
