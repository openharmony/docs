# IWlanCallback


## 概述

定义WLAN模块的回调函数。

当WLAN模块发生重启，扫描热点结束，收到Netlink消息后，调用回调函数，处理对应的结果信息。

**起始版本：** 3.2

**相关模块：**[WLAN](_w_l_a_n_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ResetDriverResult](#resetdriverresult) ([in] unsigned int event, [in] int code, [in] String ifName) | 重启WLAN驱动的结果处理回调方法。  | 
| [ScanResult](#scanresult) ([in] unsigned int event, [in] struct [HdfWifiScanResult](_hdf_wifi_scan_result_v10.md) scanResult, [in] String ifName) | 扫描结果的回调方法。  | 
| [WifiNetlinkMessage](#wifinetlinkmessage) ([in] unsigned char[] recvMsg) | Netlink消息的回调方法。  | 


## 成员函数说明


### ResetDriverResult()

```
IWlanCallback::ResetDriverResult ([in] unsigned int event, [in] int code, [in] String ifName )
```
**描述**

重启WLAN驱动的结果处理回调方法。

当重启WLAN驱动后，调用此接口处理驱动重启后的返回结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 重启驱动的事件ID。  | 
| code | 重启驱动后返回的结果数据。  | 
| ifName | 网卡名称。 | 


### ScanResult()

```
IWlanCallback::ScanResult ([in] unsigned int event, [in] struct HdfWifiScanResult scanResult, [in] String ifName )
```
**描述**

扫描结果的回调方法。

当扫描结束后，将通过此方法处理返回的扫描结果数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 扫描结果的事件ID。  | 
| scanResult | 扫描结果数据。  | 
| ifName | 网卡名称。 | 


### WifiNetlinkMessage()

```
IWlanCallback::WifiNetlinkMessage ([in] unsigned char[] recvMsg)
```
**描述**

Netlink消息的回调方法。

当收到Netlink消息后，将通过此方法处理收到的消息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recvMsg | 收到的Netlink消息。 | 
