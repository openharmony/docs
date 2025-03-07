# WLAN (V1_1)


## 概述

WLAN模块向上层WLAN服务提供了统一接口。

上层WLAN服务开发人员可根据WLAN模块提供的向上统一接口获取如下能力：建立/关闭WLAN热点，扫描/关联WLAN热点，WLAN平台芯片管理，网络数据缓冲的申请、释放、移动等操作，网络设备管理，电源管理等。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IWlanCallback.idl](_i_wlan_callback_8idl_v11.md) | 提供回调函数，当WLAN驱动重启、扫描结果返回时调用，接收到Netlink消息。 | 
| [IWlanInterface.idl](_i_wlan_interface_8idl_v11.md) | 提供API以启用或禁用WLAN热点、扫描热点、连接到WLAN热点或断开与WLAN热点的连接，设置国家代码，并管理网络设备。 | 
| [WlanTypes.idl](_wlan_types_8idl_v11.md) | 定义与WLAN模块相关的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IWlanCallback](interface_i_wlan_callback_v11.md) | 定义WLAN模块的回调。 | 
| interface&nbsp;&nbsp;[IWlanInterface](interface_i_wlan_interface_v11.md) | 定义上层WLAN服务的接口。 | 
| struct&nbsp;&nbsp;[HdfFeatureInfo](_hdf_feature_info_v11.md) | 定义Feature对象信息。 | 
| struct&nbsp;&nbsp;[HdfStaInfo](_hdf_sta_info_v11.md) | 定义STA信息。 | 
| struct&nbsp;&nbsp;[HdfWifiDriverScanSsid](_hdf_wifi_driver_scan_ssid_v11.md) | 定义Wi-Fi扫描的服务集标识符（SSID）信息。 | 
| struct&nbsp;&nbsp;[HdfWifiScan](_hdf_wifi_scan_v11.md) | 定义Wi-Fi扫描参数。 | 
| struct&nbsp;&nbsp;[HdfNetDeviceInfo](_hdf_net_device_info_v11.md) | 定义网络设备信息。 | 
| struct&nbsp;&nbsp;[HdfNetDeviceInfoResult](_hdf_net_device_info_result_v11.md) | 定义网络设备信息集。 | 
| struct&nbsp;&nbsp;[HdfWifiScanResult](_hdf_wifi_scan_result_v11.md) | 定义Wi-Fi扫描结果。 | 
| struct&nbsp;&nbsp;[HdfWifiScanResultExt](_hdf_wifi_scan_result_ext_v11.md) | 定义Wi-Fi扫描扩展结果。 | 
| struct&nbsp;&nbsp;[HdfWifiScanResults](_hdf_wifi_scan_results_v11.md) | 定义Wi-Fi扫描结果。 | 
| struct&nbsp;&nbsp;[HdfWifiInfo](_hdf_wifi_info_v11.md) | 定义Wi-Fi频段信息。 | 
| struct&nbsp;&nbsp;[MeasChannelParam](_meas_channel_param_v11.md) | 定义通道测量参数。 | 
| struct&nbsp;&nbsp;[MeasChannelResult](_meas_channel_result_v11.md) | 定义通道测量结果。 | 
| struct&nbsp;&nbsp;[ProjectionScreenCmdParam](_projection_screen_cmd_param_v11.md) | 定义投影参数。 | 
| struct&nbsp;&nbsp;[WifiStationInfo](_wifi_station_info_v11.md) | 定义STA信息。 | 
| struct&nbsp;&nbsp;[PnoNetwork](_pno_network_v11.md) | 定义Pno扫描网络信息。 | 
| struct&nbsp;&nbsp;[PnoSettings](_pno_settings_v11.md) | 定义Pno扫描参数。 | 
| struct&nbsp;&nbsp;[SignalPollResult](_signal_poll_result_v11.md) | 定义信号轮询信息。 | 
