# IWlanInterface


## 概述

定义上层WLAN服务的接口。

**起始版本：** 3.2

**相关模块：**[WLAN](_w_l_a_n_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Start](#start) () | 在HAL和WLAN驱动程序之间创建一个通道，并获取驱动程序网络接口卡（NIC）信息，此函数必须在创建IWiFi实例后调用。 | 
| [Stop](#stop) () | 销毁HAL和WLAN驱动程序之间的通道，此函数必须在IWiFi实例被销毁之前调用。 | 
| [CreateFeature](#createfeature) ([in] int type, [out] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature) | 基于指定的类型创建Feature对象。 | 
| [DestroyFeature](#destroyfeature) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature) | 销毁Feature对象。 | 
| [GetAssociatedStas](#getassociatedstas) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [out] struct [HdfStaInfo](_hdf_sta_info_v11.md)[] staInfo, [out] unsigned int num) | 获取连接到此AP的所有STA的信息。目前，STA信息仅包含MAC地址。 | 
| [GetChipId](#getchipid) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [out] unsigned char chipId) | 获取当前驱动程序的芯片ID。 | 
| [GetDeviceMacAddress](#getdevicemacaddress) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [out] unsigned char[] mac, [in] unsigned char len) | 获取设备MAC地址。 | 
| [GetFeatureByIfName](#getfeaturebyifname) ([in] String ifName, [out] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature) | 基于指定的NIC名称获取Feature对象。 | 
| [GetFeatureType](#getfeaturetype) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [out] int featureType) | 获取Feature对象的类型。 | 
| [GetFreqsWithBand](#getfreqswithband) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [in] struct [HdfWifiInfo](_hdf_wifi_info_v11.md) wifiInfo, [out] int[] freq) | 获得指定频段支持的频率。 | 
| [GetIfNamesByChipId](#getifnamesbychipid) ([in] unsigned char chipId, [out] String ifName, [out] unsigned int num) | 获取芯片的所有NIC名称。 | 
| [GetNetworkIfaceName](#getnetworkifacename) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [out] String ifName) | 获取基于Feature对象的NIC名称。 | 
| [GetSupportCombo](#getsupportcombo) ([out] unsigned long combo) | 获取多个NIC共存的信息。 | 
| [GetSupportFeature](#getsupportfeature) ([out] unsigned char[] supType) | 获得设备支持的WLAN功能（不考虑当前的使用状态）。 | 
| [RegisterEventCallback](#registereventcallback) ([in] [IWlanCallback](interface_i_wlan_callback_v11.md) cbFunc, [in] String ifName) | 注册回调以侦听异步事件。 | 
| [UnregisterEventCallback](#unregistereventcallback) ([in] [IWlanCallback](interface_i_wlan_callback_v11.md) cbFunc, [in] String ifName) | 注销回调。 | 
| [ResetDriver](#resetdriver) ([in] unsigned char chipId, [in] String ifName) | 根据指定的芯片ID重新启动WLAN驱动程序。 | 
| [SetCountryCode](#setcountrycode) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [in] String code, [in] unsigned int len) | 设置国家码。 | 
| [SetMacAddress](#setmacaddress) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [in] unsigned char[] mac) | 设置NIC的MAC地址。 | 
| [SetScanningMacAddress](#setscanningmacaddress) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [in] unsigned char[] scanMac) | 扫描单个MAC地址。 | 
| [SetTxPower](#settxpower) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [in] int power) | 设置发射功率。 | 
| [GetNetDevInfo](#getnetdevinfo) ([out] struct [HdfNetDeviceInfoResult](_hdf_net_device_info_result_v11.md) netDeviceInfoResult) | 获取网络设备信息，如设备索引、NIC名称和MAC地址。 | 
| [StartScan](#startscan) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [in] struct [HdfWifiScan](_hdf_wifi_scan_v11.md) scan) | 开始扫描。 | 
| [GetPowerMode](#getpowermode) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [out] unsigned char mode) | 获得使用中的电源模式。 | 
| [SetPowerMode](#setpowermode) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v11.md) ifeature, [in] unsigned char mode) | 设置电源模式。 | 
| [StartChannelMeas](#startchannelmeas) ([in] String ifName, [in] struct [MeasChannelParam](_meas_channel_param_v11.md) measChannelParam) | 开始通道测量。 | 
| [GetChannelMeasResult](#getchannelmeasresult) ([in] String ifName, [out] struct [MeasChannelResult](_meas_channel_result_v11.md) measChannelResult) | 获得通道测量结果。 | 
| [SetProjectionScreenParam](#setprojectionscreenparam) ([in] String ifName, [in] struct [ProjectionScreenCmdParam](_projection_screen_cmd_param_v11.md) param) | 设置投影参数。 | 
| [WifiSendCmdIoctl](#wifisendcmdioctl) ([in] String ifName, [in] int cmdId, [in] byte[] paramBuf) | 向驱动程序发送I/O控制命令。 | 
| [GetStaInfo](#getstainfo) ([in] String ifName, [out] struct [WifiStationInfo](_wifi_station_info_v11.md) info, [in] unsigned char[] mac) | 获取指定NIC的STA信息。 | 
| [StartPnoScan](#startpnoscan) ([in] String interfaceName, [in] struct [PnoSettings](_pno_settings_v11.md) pnoSettings) | 启动Pno扫描。 | 
| [StopPnoScan](#stoppnoscan) ([in] String interfaceName) | 关闭Pno扫描。 | 
| [GetSignalPollInfo](#getsignalpollinfo) ([in] String ifName, [out] struct [SignalPollResult](_signal_poll_result_v11.md) signalResult) | 获取相关链路的信号信息，此函数必须在STA模式下调用。 | 


## 成员函数说明


### CreateFeature()

```
IWlanInterface::CreateFeature ([in] int type, [out] struct HdfFeatureInfo ifeature )
```

**描述**


基于指定的类型创建Feature对象

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 表示要创建的Feature对象的类型。<br/>- 2：Station<br/>- 3：AP | 
| ifeature | 表示创建feature对象。| 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### DestroyFeature()

```
IWlanInterface::DestroyFeature ([in] struct HdfFeatureInfo ifeature)
```

**描述**


销毁Feature对象。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示要销毁的Feature对象。| 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetAssociatedStas()

```
IWlanInterface::GetAssociatedStas ([in] struct HdfFeatureInfo ifeature, [out] struct HdfStaInfo[] staInfo, [out] unsigned int num )
```

**描述**


获取连接到此AP的所有STA的信息。目前，STA信息仅包含MAC地址。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| staInfo | 表示所有连接到AP的STA的基本信息。 | 
| num | 表示连接的STA的数量。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetChannelMeasResult()

```
IWlanInterface::GetChannelMeasResult ([in] String ifName, [out] struct MeasChannelResult measChannelResult )
```

**描述**


获得通道测量结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称。 | 
| measChannelResult | 指示通道测量结果(包括通道ID、负载和噪声)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetChipId()

```
IWlanInterface::GetChipId ([in] struct HdfFeatureInfo ifeature, [out] unsigned char chipId )
```

**描述**


获取当前驱动程序的芯片ID

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| chipId | 表示获得的芯片ID。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetDeviceMacAddress()

```
IWlanInterface::GetDeviceMacAddress ([in] struct HdfFeatureInfo ifeature, [out] unsigned char[] mac, [in] unsigned char len )
```

**描述**


获取设备MAC地址

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。| 
| mac | 表示获得的MAC地址。| 
| len | 表示MAC地址的长度，该值固定为6。| 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetFeatureByIfName()

```
IWlanInterface::GetFeatureByIfName ([in] String ifName, [out] struct HdfFeatureInfo ifeature )
```

**描述**


基于指定的NIC名称获取Feature对象

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称。 | 
| ifeature | 表示获得的Feature对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetFeatureType()

```
IWlanInterface::GetFeatureType ([in] struct HdfFeatureInfo ifeature, [out] int featureType )
```

**描述**


获取Feature对象的类型

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| featureType | 表示获取的Feature对象的类型。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetFreqsWithBand()

```
IWlanInterface::GetFreqsWithBand ([in] struct HdfFeatureInfo ifeature, [in] struct HdfWifiInfo wifiInfo, [out] int[] freq )
```

**描述**


获得指定频段支持的频率

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| wifiInfo | 表示频率信息。<br/>- wifiInfo.band：<br/>&nbsp;&nbsp;- 0：2.4 GHz<br/>&nbsp;&nbsp;- 1：5 GHz<br/>- wifiInfo.size，最小为14 | 
| freq | 保存支持的频率。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetIfNamesByChipId()

```
IWlanInterface::GetIfNamesByChipId ([in] unsigned char chipId, [out] String ifName, [out] unsigned int num )
```

**描述**


获取芯片的所有NIC名称

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| chipId | 表示目标芯片的ID。 | 
| ifNames | 表示获得的NIC名称。 | 
| num | 表示NIC的数量。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetNetDevInfo()

```
IWlanInterface::GetNetDevInfo ([out] struct HdfNetDeviceInfoResult netDeviceInfoResult)
```

**描述**


获取网络设备信息，如设备索引、NIC名称和MAC地址

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| netDeviceInfoResult | 表示获得的网络设备信息。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetNetworkIfaceName()

```
IWlanInterface::GetNetworkIfaceName ([in] struct HdfFeatureInfo ifeature, [out] String ifName )
```

**描述**


获取基于Feature对象的NIC名称

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| ifName | 表示网卡(NIC)名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetPowerMode()

```
IWlanInterface::GetPowerMode ([in] struct HdfFeatureInfo ifeature, [out] unsigned char mode )
```

**描述**


获得使用中的电源模式

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。| 
| mode | 表示电源模式，包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetSignalPollInfo()

```
IWlanInterface::GetSignalPollInfo ([in] String ifName, [out] struct SignalPollResult signalResult )
```

**描述**


获取相关链路的信号信息。此函数必须在STA模式下调用。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称。 | 
| signalResult | 表示信号信息。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetStaInfo()

```
IWlanInterface::GetStaInfo ([in] String ifName, [out] struct WifiStationInfo info, [in] unsigned char[] mac )
```

**描述**


获取指定NIC的STA信息

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称。 | 
| info | 表示所获得的STA信息。有关详细信息，请参阅[WifiStationInfo](_wifi_station_info_v11.md)。 | 
| mac | 表示STA的MAC地址。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetSupportCombo()

```
IWlanInterface::GetSupportCombo ([out] unsigned long combo)
```

**描述**


获取多个NIC共存的信息

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| combo | 表示获得的信息，例如，AP、STA和P2P的不同组合。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetSupportFeature()

```
IWlanInterface::GetSupportFeature ([out] unsigned char[] supType)
```

**描述**


获得设备支持的WLAN功能（不考虑当前的使用状态）

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| supType | 表示获得的功能。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### RegisterEventCallback()

```
IWlanInterface::RegisterEventCallback ([in] IWlanCallback cbFunc, [in] String ifName )
```

**描述**


注册回调以侦听异步事件

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 表示要注册的回调。 | 
| ifName | 表示网卡(NIC)名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### ResetDriver()

```
IWlanInterface::ResetDriver ([in] unsigned char chipId, [in] String ifName )
```

**描述**


根据指定的芯片ID重新启动WLAN驱动程序

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| chipId | 表示要重新启动其驱动程序的芯片的ID。 | 
| ifName | 表示网卡(NIC)名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetCountryCode()

```
IWlanInterface::SetCountryCode ([in] struct HdfFeatureInfo ifeature, [in] String code, [in] unsigned int len )
```

**描述**


设置国家码

国家/地区代码表示AP射频所在的国家/地区。描述AP射频特性， 包括AP的发射功率和支持的信道，确保AP的射频属性符合当地法律法规。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| code | 表示设置的国家码。 | 
| len | 表示国家码的长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetMacAddress()

```
IWlanInterface::SetMacAddress ([in] struct HdfFeatureInfo ifeature, [in] unsigned char[] mac )
```

**描述**


设置NIC的MAC地址

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| mac | 表示要设置的MAC地址。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetPowerMode()

```
IWlanInterface::SetPowerMode ([in] struct HdfFeatureInfo ifeature, [in] unsigned char mode )
```

**描述**


设置电源模式

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| mode | 表示设置电源模式。电源模式可以是睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetProjectionScreenParam()

```
IWlanInterface::SetProjectionScreenParam ([in] String ifName, [in] struct ProjectionScreenCmdParam param )
```

**描述**


设置投影参数

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称。 | 
| param | 表示要设置的投影参数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetScanningMacAddress()

```
IWlanInterface::SetScanningMacAddress ([in] struct HdfFeatureInfo ifeature, [in] unsigned char[] scanMac )
```

**描述**


扫描单个MAC地址

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| scanMac | 表示STA要扫描的MAC地址。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetTxPower()

```
IWlanInterface::SetTxPower ([in] struct HdfFeatureInfo ifeature, [in] int power )
```

**描述**


设置发射功率

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| power | 表示要设置的发射功率。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### Start()

```
IWlanInterface::Start ()
```

**描述**


在HAL和WLAN驱动程序之间创建一个通道，并获取驱动程序网络接口卡（NIC）信息，此函数必须在创建IWiFi实例后调用。

**起始版本：** 3.2

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### StartChannelMeas()

```
IWlanInterface::StartChannelMeas ([in] String ifName, [in] struct MeasChannelParam measChannelParam )
```

**描述**


开始通道测量

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称。 | 
| measChannelParam | 表示通道测量参数（通道ID和测量时间）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### StartPnoScan()

```
IWlanInterface::StartPnoScan ([in] String interfaceName, [in] struct PnoSettings pnoSettings )
```

**描述**


启动Pno扫描

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| interfaceName | 表示网卡(NIC)名称。 | 
| pnoSettings | 表示pno扫描参数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### StartScan()

```
IWlanInterface::StartScan ([in] struct HdfFeatureInfo ifeature, [in] struct HdfWifiScan scan )
```

**描述**


开始扫描

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 表示Feature对象。 | 
| scan | 表示扫描参数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### Stop()

```
IWlanInterface::Stop ()
```

**描述**


销毁HAL和WLAN驱动程序之间的通道。此函数必须在IWiFi实例被销毁之前调用。

**起始版本：** 3.2

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### StopPnoScan()

```
IWlanInterface::StopPnoScan ([in] String interfaceName)
```

**描述**


关闭Pno扫描

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| interfaceName | 表示网卡(NIC)名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### UnregisterEventCallback()

```
IWlanInterface::UnregisterEventCallback ([in] IWlanCallback cbFunc, [in] String ifName )
```

**描述**


注销回调

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 表示要注销的回调。 | 
| ifName | 表示网卡(NIC)名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### WifiSendCmdIoctl()

```
IWlanInterface::WifiSendCmdIoctl ([in] String ifName, [in] int cmdId, [in] byte[] paramBuf )
```

**描述**


向驱动程序发送I/O控制命令

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称。 | 
| cmdId | 表示要发送的命令的ID。 | 
| paramBuf | 表示命令内容。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。
