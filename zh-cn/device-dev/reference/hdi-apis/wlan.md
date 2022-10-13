# WLAN


## **概述**

WLAN模块向上层WLAN服务提供了统一接口。

上层WLAN服务开发人员可根据WLAN模块提供的向上统一接口获取如下能力：建立/关闭WLAN热点，扫描/关联WLAN热点，WLAN平台芯片管理，网络数据缓冲的申请、释放、移动等操作，网络设备管理，电源管理等。

**Since**:

3.2

**Version**:

1.0


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [IWlanCallback.idl](_i_wlan_callback_8idl.md) | WLAN模块为WLAN服务提供的重启驱动、扫描结果、Netlink消息处理的回调。 | 
| [IWlanInterface.idl](_i_wlan_interface_8idl.md) | 建立/关闭WLAN热点，扫描/关联/去关联WLAN热点，设置国家码，管理网络设备等操作的接口。 | 
| [WlanTypes.idl](_wlan_types_8idl.md) | WLAN模块相关的数据类型。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [IWlanCallback](interface_i_wlan_callback.md) | 定义WLAN模块的回调函数。 | 
| [IWlanInterface](interface_i_wlan_interface.md) | WLAN模块向上层WLAN服务提供了统一接口。 | 
| [HdfFeatureInfo](_hdf_feature_info.md) | feature对象信息。 | 
| [HdfStaInfo](_hdf_sta_info.md) | STA的信息。 | 
| [HdfWifiDriverScanSsid](_hdf_wifi_driver_scan_ssid.md) | WiFi扫描参数SSID信息。 | 
| [HdfWifiScan](_hdf_wifi_scan.md) | WiFi扫描参数。 | 
| [HdfNetDeviceInfo](_hdf_net_device_info.md) | 网络设备信息。 | 
| [HdfNetDeviceInfoResult](_hdf_net_device_info_result.md) | 网络设备信息集合。 | 
| [HdfWifiScanResult](_hdf_wifi_scan_result.md) | WiFi扫描结果。 | 
| [HdfWifiInfo](_hdf_wifi_info.md) | WiFi频段信息。 | 
| [MeasChannelParam](_meas_channel_param.md) | 信道测量参数。 | 
| [MeasChannelResult](_meas_channel_result.md) | 信道测量结果。 | 
| [ProjectionScreenCmdParam](_projection_screen_cmd_param.md) | 投屏参数。 | 
| [WifiStationInfo](_wifi_station_info.md) | STA的信息。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.wlan.v1_0 | WLAN模块接口的包路径。 | 
