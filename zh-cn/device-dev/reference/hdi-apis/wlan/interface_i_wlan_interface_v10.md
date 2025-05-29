# IWlanInterface


## 概述

WLAN模块向上层WLAN服务提供了统一接口。

上层服务调用相关的接口，可以建立/关闭WLAN热点，扫描/关联/去关联WLAN热点，设置国家码，管理网络设备等。

**起始版本：** 3.2

**相关模块：**[WLAN](_w_l_a_n_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Start](#start) () | 创建HAL和驱动之间的通道及获取驱动网卡信息，该函数调用在创建IWiFi实体后进行。  | 
| [Stop](#stop) () | 销毁HAL和驱动之间的通道，该函数调用在销毁IWiFi实体前进行。  | 
| [CreateFeature](#createfeature) ([in] int type, [out] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature) | 根据输入类型创建对应的feature对象。  | 
| [DestroyFeature](#destroyfeature) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature) | 销毁feature对象。  | 
| [GetAsscociatedStas](#getasscociatedstas) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [out] struct [HdfStaInfo](_hdf_sta_info_v10.md)[] staInfo, [out] unsigned int num) | 获取与AP连接的所有STA的信息（目前只包含MAC地址）。  | 
| [GetChipId](#getchipid) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [out] unsigned char chipId) | 获得当前驱动的芯片ID。  | 
| [GetDeviceMacAddress](#getdevicemacaddress) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [out] unsigned char[] mac, [in] unsigned char len) | 获取设备的MAC地址。  | 
| [GetFeatureByIfName](#getfeaturebyifname) ([in] String ifName, [out] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature) | 通过网卡名称获取对应的feature对象。  | 
| [GetFeatureType](#getfeaturetype) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [out] int featureType) | 获取feature对象的类型。  | 
| [GetFreqsWithBand](#getfreqswithband) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [in] struct [HdfWifiInfo](_hdf_wifi_info_v10.md) wifiInfo, [out] int[] freq) | 获取指定频段（2.4G或者5G）下支持的频率。  | 
| [GetIfNamesByChipId](#getifnamesbychipid) ([in] unsigned char chipId, [out] String ifName, [out] unsigned int num) | 通过芯片ID获得当前芯片所有的网卡名称。  | 
| [GetNetworkIfaceName](#getnetworkifacename) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [out] String ifName) | 根据feature对象获取网卡名称。  | 
| [GetSupportCombo](#getsupportcombo) ([out] unsigned long combo) | 获取多网卡共存情况。  | 
| [GetSupportFeature](#getsupportfeature) ([out] unsigned char[] supType) | 获取该设备支持的WLAN特性（不考虑当前的使用状态）。  | 
| [RegisterEventCallback](#registereventcallback) ([in] [IWlanCallback](interface_i_wlan_callback_v10.md) cbFunc, [in] String ifName) | 注册IWiFi的回调函数，监听异步事件。  | 
| [UnregisterEventCallback](#unregistereventcallback) ([in] [IWlanCallback](interface_i_wlan_callback_v10.md) cbFunc, [in] String ifName) | 去注册IWiFi的回调函数。  | 
| [ResetDriver](#resetdriver) ([in] unsigned char chipId, [in] String ifName) | 重启指定芯片ID的WLAN驱动程序。  | 
| [SetCountryCode](#setcountrycode) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [in] String code, [in] unsigned int len) | 设置国家码（表示AP射频所在的国家，规定了AP射频特性，包括AP的发送功率、支持的信道等。其目的是为了使AP的射频特性符合不同国家或区域的法律法规要求）。  | 
| [SetMacAddress](#setmacaddress) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [in] unsigned char[] mac) | 根据传入参数设置对应网卡的MAC地址。  | 
| [SetScanningMacAddress](#setscanningmacaddress) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [in] unsigned char[] scanMac) | 设置扫描单个MAC地址。  | 
| [SetTxPower](#settxpower) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [in] int power) | 设置发射功率。  | 
| [GetNetDevInfo](#getnetdevinfo) ([out] struct [HdfNetDeviceInfoResult](_hdf_net_device_info_result_v10.md) netDeviceInfoResult) | 获取网络设备信息（设备索引、网卡名字、MAC等信息）。  | 
| [StartScan](#startscan) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [in] struct [HdfWifiScan](_hdf_wifi_scan_v10.md) scan) | 启动扫描。  | 
| [GetPowerMode](#getpowermode) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [out] unsigned char mode) | 获取正在使用的功率模式。  | 
| [SetPowerMode](#setpowermode) ([in] struct [HdfFeatureInfo](_hdf_feature_info_v10.md) ifeature, [in] unsigned char mode) | 设置功率模式。  | 
| [StartChannelMeas](#startchannelmeas) ([in] String ifName, [in] struct [MeasChannelParam](_meas_channel_param_v10.md) measChannelParam) | 启动信道测量。  | 
| [GetChannelMeasResult](#getchannelmeasresult) ([in] String ifName, [out] struct [MeasChannelResult](_meas_channel_result_v10.md) measChannelResult) | 获取信道测量结果。  | 
| [SetProjectionScreenParam](#setprojectionscreenparam) ([in] String ifName, [in] struct [ProjectionScreenCmdParam](_projection_screen_cmd_param_v10.md) param) | 设置投屏参数。  | 
| [WifiSendCmdIoctl](#wifisendcmdioctl) ([in] String ifName, [in] int cmdId, [in] byte[] paramBuf) | 向驱动发送IO控制命令。  | 
| [GetStaInfo](#getstainfo) ([in] String ifName, [out] struct [WifiStationInfo](_wifi_station_info_v10.md) info, [in] unsigned char[] mac) | 获取指定网卡的STA的信息。  | 


## 成员函数说明


### CreateFeature()

```
IWlanInterface::CreateFeature ([in] int type, [out] struct HdfFeatureInfo ifeature )
```
**描述**

根据输入类型创建对应的feature对象。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 创建的feature类型。  | 
| ifeature | 获取创建的feature对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### DestroyFeature()

```
IWlanInterface::DestroyFeature ([in] struct HdfFeatureInfo ifeature)
```
**描述**

销毁feature对象。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | 销毁的feature对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetAsscociatedStas()

```
IWlanInterface::GetAsscociatedStas ([in] struct HdfFeatureInfo ifeature, [out] struct HdfStaInfo[] staInfo, [out] unsigned int num )
```
**描述**

获取与AP连接的所有STA的信息（目前只包含MAC地址）。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| staInfo | 保存与AP连接的STA的基本信息。  | 
| num | 实际连接的STA的个数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetChannelMeasResult()

```
IWlanInterface::GetChannelMeasResult ([in] String ifName, [out] struct MeasChannelResult measChannelResult )
```
**描述**

获取信道测量结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。  | 
| measChannelResult | 信道测量结果（信道号、信道负载、信道噪声）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetChipId()

```
IWlanInterface::GetChipId ([in] struct HdfFeatureInfo ifeature, [out] unsigned char chipId )
```
**描述**

获得当前驱动的芯片ID。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| chipId | 获得的芯片ID。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetDeviceMacAddress()

```
IWlanInterface::GetDeviceMacAddress ([in] struct HdfFeatureInfo ifeature, [out] unsigned char[] mac, [in] unsigned char len )
```
**描述**

获取设备的MAC地址。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| mac | 获得的MAC地址。  | 
| len | mac数组的长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetFeatureByIfName()

```
IWlanInterface::GetFeatureByIfName ([in] String ifName, [out] struct HdfFeatureInfo ifeature )
```
**描述**

通过网卡名称获取对应的feature对象。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。  | 
| ifeature | 获取该网卡的feature对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetFeatureType()

```
IWlanInterface::GetFeatureType ([in] struct HdfFeatureInfo ifeature, [out] int featureType )
```
**描述**

获取feature对象的类型。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| featureType | feature对象的类型。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetFreqsWithBand()

```
IWlanInterface::GetFreqsWithBand ([in] struct HdfFeatureInfo ifeature, [in] struct HdfWifiInfo wifiInfo, [out] int[] freq )
```
**描述**

获取指定频段（2.4G或者5G）下支持的频率。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| wifiInfo | 频段信息。  | 
| freq | 保存支持的频率。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetIfNamesByChipId()

```
IWlanInterface::GetIfNamesByChipId ([in] unsigned char chipId, [out] String ifName, [out] unsigned int num )
```
**描述**

通过芯片ID获得当前芯片所有的网卡名称。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| chipId | 需要获取网卡名称的芯片ID。  | 
| ifName | 网卡名称。  | 
| num | 网卡的数量。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetNetDevInfo()

```
IWlanInterface::GetNetDevInfo ([out] struct HdfNetDeviceInfoResult netDeviceInfoResult)
```
**描述**

获取网络设备信息（设备索引、网卡名字、MAC等信息）。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| netDeviceInfoResult | 输出参数，得到的网络设备信息。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetNetworkIfaceName()

```
IWlanInterface::GetNetworkIfaceName ([in] struct HdfFeatureInfo ifeature, [out] String ifName )
```
**描述**

根据feature对象获取网卡名称。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| ifName | 网卡名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetPowerMode()

```
IWlanInterface::GetPowerMode ([in] struct HdfFeatureInfo ifeature, [out] unsigned char mode )
```
**描述**

获取正在使用的功率模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| mode | 功率模式，包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetStaInfo()

```
IWlanInterface::GetStaInfo ([in] String ifName, [out] struct WifiStationInfo info, [in] unsigned char[] mac )
```
**描述**

获取指定网卡的STA的信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。  | 
| info | 获取的STA的信息，详情请参考[WifiStationInfo](_wifi_station_info_v10.md)。  | 
| mac | STA的MAC地址。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetSupportCombo()

```
IWlanInterface::GetSupportCombo ([out] unsigned long combo)
```
**描述**

获取多网卡共存情况。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| combo | 基于芯片的能力保存当前所有支持的多网卡共存情况（比如支持AP、STA、P2P等不同组合的共存）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetSupportFeature()

```
IWlanInterface::GetSupportFeature ([out] unsigned char[] supType)
```
**描述**

获取该设备支持的WLAN特性（不考虑当前的使用状态）。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| supType | 保存当前设备支持的特性。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### RegisterEventCallback()

```
IWlanInterface::RegisterEventCallback ([in] IWlanCallback cbFunc, [in] String ifName )
```
**描述**

注册IWiFi的回调函数，监听异步事件。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 注册的回调函数。  | 
| ifName | 网卡名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### ResetDriver()

```
IWlanInterface::ResetDriver ([in] unsigned char chipId, [in] String ifName )
```
**描述**

重启指定芯片ID的WLAN驱动程序。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| chipId | 需要进行重启驱动的芯片ID。  | 
| ifName | 网卡名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetCountryCode()

```
IWlanInterface::SetCountryCode ([in] struct HdfFeatureInfo ifeature, [in] String code, [in] unsigned int len )
```
**描述**

设置国家码（表示AP射频所在的国家，规定了AP射频特性，包括AP的发送功率、支持的信道等。其目的是为了使AP的射频特性符合不同国家或区域的法律法规要求）。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| code | 设置的国家码。  | 
| len | 国家码长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetMacAddress()

```
IWlanInterface::SetMacAddress ([in] struct HdfFeatureInfo ifeature, [in] unsigned char[] mac )
```
**描述**

根据传入参数设置对应网卡的MAC地址。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| mac | 设置的MAC地址。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetPowerMode()

```
IWlanInterface::SetPowerMode ([in] struct HdfFeatureInfo ifeature, [in] unsigned char mode )
```
**描述**

设置功率模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| mode | 功率模式,包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetProjectionScreenParam()

```
IWlanInterface::SetProjectionScreenParam ([in] String ifName, [in] struct ProjectionScreenCmdParam param )
```
**描述**

设置投屏参数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。  | 
| param | 投屏参数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetScanningMacAddress()

```
IWlanInterface::SetScanningMacAddress ([in] struct HdfFeatureInfo ifeature, [in] unsigned char[] scanMac )
```
**描述**

设置扫描单个MAC地址。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| scanMac | 设置STA扫描的MAC地址。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetTxPower()

```
IWlanInterface::SetTxPower ([in] struct HdfFeatureInfo ifeature, [in] int power )
```
**描述**

设置发射功率。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| power | 设置的发射功率。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Start()

```
IWlanInterface::Start ()
```
**描述**

创建HAL和驱动之间的通道及获取驱动网卡信息，该函数调用在创建IWiFi实体后进行。

**起始版本：** 3.2

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### StartChannelMeas()

```
IWlanInterface::StartChannelMeas ([in] String ifName, [in] struct MeasChannelParam measChannelParam )
```
**描述**

启动信道测量。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。  | 
| measChannelParam | 信道测量参数（信道号、测量时间）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### StartScan()

```
IWlanInterface::StartScan ([in] struct HdfFeatureInfo ifeature, [in] struct HdfWifiScan scan )
```
**描述**

启动扫描。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。  | 
| scan | 扫描参数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Stop()

```
IWlanInterface::Stop ()
```
**描述**

销毁HAL和驱动之间的通道，该函数调用在销毁IWiFi实体前进行。

**起始版本：** 3.2

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### UnregisterEventCallback()

```
IWlanInterface::UnregisterEventCallback ([in] IWlanCallback cbFunc, [in] String ifName )
```
**描述**

去注册IWiFi的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 去注册的回调函数。  | 
| ifName | 网卡名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### WifiSendCmdIoctl()

```
IWlanInterface::WifiSendCmdIoctl ([in] String ifName, [in] int cmdId, [in] byte[] paramBuf )
```
**描述**

向驱动发送IO控制命令。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。  | 
| cmdId | 命令ID。  | 
| paramBuf | 命令内容。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
