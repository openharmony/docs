# WLAN (V1_0)


## 概述

WLAN模块向上层WLAN服务提供了统一接口。

上层WLAN服务开发人员可根据WLAN模块提供的向上统一接口获取如下能力：建立/关闭WLAN热点，扫描/关联WLAN热点，WLAN平台芯片管理，网络数据缓冲的申请、释放、移动等操作，网络设备管理，电源管理等。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IWlanCallback.idl](_i_wlan_callback_8idl_v10.md) | WLAN模块为WLAN服务提供的重启驱动、扫描结果、Netlink消息处理的回调。 | 
| [IWlanInterface.idl](_i_wlan_interface_8idl_v10.md) | 建立/关闭WLAN热点，扫描/关联/去关联WLAN热点，设置国家码，管理网络设备等操作的接口。 | 
| [WlanTypes.idl](_wlan_types_8idl_v10.md) | WLAN模块相关的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IWlanCallback](interface_i_wlan_callback_v10.md) | 定义WLAN模块的回调函数。 | 
| interface&nbsp;&nbsp;[IWlanInterface](interface_i_wlan_interface_v10.md) | WLAN模块向上层WLAN服务提供了统一接口。 | 
| struct&nbsp;&nbsp;[HdfFeatureInfo](_hdf_feature_info_v10.md) | feature对象信息。 | 
| struct&nbsp;&nbsp;[HdfStaInfo](_hdf_sta_info_v10.md) | STA的信息。 | 
| struct&nbsp;&nbsp;[HdfWifiDriverScanSsid](_hdf_wifi_driver_scan_ssid_v10.md) | WiFi扫描参数SSID信息。 | 
| struct&nbsp;&nbsp;[HdfWifiScan](_hdf_wifi_scan_v10.md) | WiFi扫描参数。 | 
| struct&nbsp;&nbsp;[HdfNetDeviceInfo](_hdf_net_device_info_v10.md) | 网络设备信息。 | 
| struct&nbsp;&nbsp;[HdfNetDeviceInfoResult](_hdf_net_device_info_result_v10.md) | 网络设备信息集合。 | 
| struct&nbsp;&nbsp;[HdfWifiScanResult](_hdf_wifi_scan_result_v10.md) | WiFi扫描结果。 | 
| struct&nbsp;&nbsp;[HdfWifiInfo](_hdf_wifi_info_v10.md) | WiFi频段信息。 | 
| struct&nbsp;&nbsp;[MeasChannelParam](_meas_channel_param_v10.md) | 信道测量参数。 | 
| struct&nbsp;&nbsp;[MeasChannelResult](_meas_channel_result_v10.md) | 信道测量结果。 | 
| struct&nbsp;&nbsp;[ProjectionScreenCmdParam](_projection_screen_cmd_param_v10.md) | 投屏参数。 | 
| struct&nbsp;&nbsp;[WifiStationInfo](_wifi_station_info_v10.md) | STA的信息。 | 
