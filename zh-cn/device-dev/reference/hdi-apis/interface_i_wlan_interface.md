# IWlanInterface


## **概述**

WLAN模块向上层WLAN服务提供了统一接口。

上层服务调用相关的接口，可以建立/关闭WLAN热点，扫描/关联/去关联WLAN热点，设置国家码，管理网络设备等。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[WLAN](wlan.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Start](#start)&nbsp;() | 创建HAL和驱动之间的通道及获取驱动网卡信息，该函数调用在创建IWiFi实体后进行。 | 
| [Stop](#stop)&nbsp;() | 销毁HAL和驱动之间的通道，该函数调用在销毁IWiFi实体前进行。 | 
| [CreateFeature](#createfeature)&nbsp;([in]&nbsp;int&nbsp;type,&nbsp;[out]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature) | 根据输入类型创建对应的feature对象。 | 
| [DestroyFeature](#destroyfeature)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature) | 销毁feature对象。 | 
| [GetAsscociatedStas](#getasscociatedstas)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[out]&nbsp;struct&nbsp;[HdfStaInfo](_hdf_sta_info.md)[]&nbsp;staInfo,&nbsp;[out]&nbsp;unsigned&nbsp;int&nbsp;num) | 获取与AP连接的所有STA的信息（目前只包含MAC地址）。 | 
| [GetChipId](#getchipid)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[out]&nbsp;unsigned&nbsp;char&nbsp;chipId) | 获得当前驱动的芯片ID。 | 
| [GetDeviceMacAddress](#getdevicemacaddress)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[out]&nbsp;unsigned&nbsp;char[]&nbsp;mac,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;len) | 获取设备的MAC地址。 | 
| [GetFeatureByIfName](#getfeaturebyifname)&nbsp;([in]&nbsp;String&nbsp;ifName,&nbsp;[out]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature) | 通过网卡名称获取对应的feature对象。 | 
| [GetFeatureType](#getfeaturetype)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[out]&nbsp;int&nbsp;featureType) | 获取feature对象的类型。 | 
| [GetFreqsWithBand](#getfreqswithband)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[in]&nbsp;struct&nbsp;[HdfWifiInfo](_hdf_wifi_info.md)&nbsp;wifiInfo,&nbsp;[out]&nbsp;int[]&nbsp;freq) | 获取指定频段（2.4G或者5G）下支持的频率。 | 
| [GetIfNamesByChipId](#getifnamesbychipid)&nbsp;([in]&nbsp;unsigned&nbsp;char&nbsp;chipId,&nbsp;[out]&nbsp;String&nbsp;ifName,&nbsp;[out]&nbsp;unsigned&nbsp;int&nbsp;num) | 通过芯片ID获得当前芯片所有的网卡名称。 | 
| [GetNetworkIfaceName](#getnetworkifacename)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[out]&nbsp;String&nbsp;ifName) | 根据feature对象获取网卡名称。 | 
| [GetSupportCombo](#getsupportcombo)&nbsp;([out]&nbsp;unsigned&nbsp;long&nbsp;combo) | 获取多网卡共存情况。 | 
| [GetSupportFeature](#getsupportfeature)&nbsp;([out]&nbsp;unsigned&nbsp;char[]&nbsp;supType) | 获取该设备支持的WLAN特性（不考虑当前的使用状态）。 | 
| [RegisterEventCallback](#registereventcallback)&nbsp;([in]&nbsp;[IWlanCallback](interface_i_wlan_callback.md)&nbsp;cbFunc,&nbsp;[in]&nbsp;String&nbsp;ifName) | 注册IWiFi的回调函数，监听异步事件。 | 
| [UnregisterEventCallback](#unregistereventcallback)&nbsp;([in]&nbsp;[IWlanCallback](interface_i_wlan_callback.md)&nbsp;cbFunc,&nbsp;[in]&nbsp;String&nbsp;ifName) | 去注册IWiFi的回调函数。 | 
| [ResetDriver](#resetdriver)&nbsp;([in]&nbsp;unsigned&nbsp;char&nbsp;chipId,&nbsp;[in]&nbsp;String&nbsp;ifName) | 重启指定芯片ID的WLAN驱动程序。 | 
| [SetCountryCode](#setcountrycode)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[in]&nbsp;String&nbsp;code,&nbsp;[in]&nbsp;unsigned&nbsp;int&nbsp;len) | 设置国家码（表示AP射频所在的国家，规定了AP射频特性，包括AP的发送功率、支持的信道等。其目的是为了使AP的射频特性符合不同国家或区域的法律法规要求）。 | 
| [SetMacAddress](#setmacaddress)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;mac) | 根据传入参数设置对应网卡的MAC地址。 | 
| [SetScanningMacAddress](#setscanningmacaddress)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;scanMac) | 设置扫描单个MAC地址。 | 
| [SetTxPower](#settxpower)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[in]&nbsp;int&nbsp;power) | 设置发射功率。 | 
| [GetNetDevInfo](#getnetdevinfo)&nbsp;([out]&nbsp;struct&nbsp;[HdfNetDeviceInfoResult](_hdf_net_device_info_result.md)&nbsp;netDeviceInfoResult) | 获取网络设备信息（设备索引、网卡名字、MAC等信息）。 | 
| [StartScan](#startscan)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[in]&nbsp;struct&nbsp;[HdfWifiScan](_hdf_wifi_scan.md)&nbsp;scan) | 启动扫描。 | 
| [GetPowerMode](#getpowermode)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[out]&nbsp;unsigned&nbsp;char&nbsp;mode) | 获取正在使用的功率模式。 | 
| [SetPowerMode](#setpowermode)&nbsp;([in]&nbsp;struct&nbsp;[HdfFeatureInfo](_hdf_feature_info.md)&nbsp;ifeature,&nbsp;[in]&nbsp;unsigned&nbsp;char&nbsp;mode) | 设置功率模式。 | 
| [StartChannelMeas](#startchannelmeas)&nbsp;([in]&nbsp;String&nbsp;ifName,&nbsp;[in]&nbsp;struct&nbsp;[MeasChannelParam](_meas_channel_param.md)&nbsp;measChannelParam) | 启动信道测量。 | 
| [GetChannelMeasResult](#getchannelmeasresult)&nbsp;([in]&nbsp;String&nbsp;ifName,&nbsp;[out]&nbsp;struct&nbsp;[MeasChannelResult](_meas_channel_result.md)&nbsp;measChannelResult) | 获取信道测量结果。 | 
| [SetProjectionScreenParam](#setprojectionscreenparam)&nbsp;([in]&nbsp;String&nbsp;ifName,&nbsp;[in]&nbsp;struct&nbsp;[ProjectionScreenCmdParam](_projection_screen_cmd_param.md)&nbsp;param) | 设置投屏参数。 | 
| [WifiSendCmdIoctl](#wifisendcmdioctl)&nbsp;([in]&nbsp;String&nbsp;ifName,&nbsp;[in]&nbsp;int&nbsp;cmdId,&nbsp;[in]&nbsp;byte[]&nbsp;paramBuf) | 向驱动发送IO控制命令。 | 
| [GetStaInfo](#getstainfo)&nbsp;([in]&nbsp;String&nbsp;ifName,&nbsp;[out]&nbsp;struct&nbsp;[WifiStationInfo](_wifi_station_info.md)&nbsp;info,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;mac) | 获取指定网卡的STA的信息。 | 


## **成员函数说明**


### CreateFeature()

  
```
IWlanInterface::CreateFeature ([in] int type, [out] struct HdfFeatureInfo ifeature )
```

**描述：**

根据输入类型创建对应的feature对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| type | 创建的feature类型。 | 
| ifeature | 获取创建的feature对象。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### DestroyFeature()

  
```
IWlanInterface::DestroyFeature ([in] struct HdfFeatureInfo ifeature)
```

**描述：**

销毁feature对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | 销毁的feature对象。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetAsscociatedStas()

  
```
IWlanInterface::GetAsscociatedStas ([in] struct HdfFeatureInfo ifeature, [out] struct HdfStaInfo[] staInfo, [out] unsigned int num )
```

**描述：**

获取与AP连接的所有STA的信息（目前只包含MAC地址）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| staInfo | 保存与AP连接的STA的基本信息。 | 
| num | 实际连接的STA的个数。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetChannelMeasResult()

  
```
IWlanInterface::GetChannelMeasResult ([in] String ifName, [out] struct MeasChannelResult measChannelResult )
```

**描述：**

获取信道测量结果。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。 | 
| measChannelResult | 信道测量结果（信道号、信道负载、信道噪声）。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetChipId()

  
```
IWlanInterface::GetChipId ([in] struct HdfFeatureInfo ifeature, [out] unsigned char chipId )
```

**描述：**

获得当前驱动的芯片ID。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| chipId | 获得的芯片ID。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetDeviceMacAddress()

  
```
IWlanInterface::GetDeviceMacAddress ([in] struct HdfFeatureInfo ifeature, [out] unsigned char[] mac, [in] unsigned char len )
```

**描述：**

获取设备的MAC地址。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| mac | 获得的MAC地址。 | 
| len | mac数组的长度。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetFeatureByIfName()

  
```
IWlanInterface::GetFeatureByIfName ([in] String ifName, [out] struct HdfFeatureInfo ifeature )
```

**描述：**

通过网卡名称获取对应的feature对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。 | 
| ifeature | 获取该网卡的feature对象。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetFeatureType()

  
```
IWlanInterface::GetFeatureType ([in] struct HdfFeatureInfo ifeature, [out] int featureType )
```

**描述：**

获取feature对象的类型。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| featureType | feature对象的类型。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetFreqsWithBand()

  
```
IWlanInterface::GetFreqsWithBand ([in] struct HdfFeatureInfo ifeature, [in] struct HdfWifiInfo wifiInfo, [out] int[] freq )
```

**描述：**

获取指定频段（2.4G或者5G）下支持的频率。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| wifiInfo | 频段信息。 | 
| freq | 保存支持的频率。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetIfNamesByChipId()

  
```
IWlanInterface::GetIfNamesByChipId ([in] unsigned char chipId, [out] String ifName, [out] unsigned int num )
```

**描述：**

通过芯片ID获得当前芯片所有的网卡名称。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| chipId | 需要获取网卡名称的芯片ID。 | 
| ifNames | 网卡名称。 | 
| num | 网卡的数量。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetNetDevInfo()

  
```
IWlanInterface::GetNetDevInfo ([out] struct HdfNetDeviceInfoResult netDeviceInfoResult)
```

**描述：**

获取网络设备信息（设备索引、网卡名字、MAC等信息）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| netDeviceInfoResult | 输出参数，得到的网络设备信息。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetNetworkIfaceName()

  
```
IWlanInterface::GetNetworkIfaceName ([in] struct HdfFeatureInfo ifeature, [out] String ifName )
```

**描述：**

根据feature对象获取网卡名称。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| ifName | 网卡名称。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetPowerMode()

  
```
IWlanInterface::GetPowerMode ([in] struct HdfFeatureInfo ifeature, [out] unsigned char mode )
```

**描述：**

获取正在使用的功率模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| mode | 功率模式，包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetStaInfo()

  
```
IWlanInterface::GetStaInfo ([in] String ifName, [out] struct WifiStationInfo info, [in] unsigned char[] mac )
```

**描述：**

获取指定网卡的STA的信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。 | 
| info | 获取的STA的信息，详情请参考[WifiStationInfo](_wifi_station_info.md)。 | 
| mac | STA的MAC地址。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetSupportCombo()

  
```
IWlanInterface::GetSupportCombo ([out] unsigned long combo)
```

**描述：**

获取多网卡共存情况。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| combo | 基于芯片的能力保存当前所有支持的多网卡共存情况（比如支持AP、STA、P2P等不同组合的共存）。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetSupportFeature()

  
```
IWlanInterface::GetSupportFeature ([out] unsigned char[] supType)
```

**描述：**

获取该设备支持的WLAN特性（不考虑当前的使用状态）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| supType | 保存当前设备支持的特性。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### RegisterEventCallback()

  
```
IWlanInterface::RegisterEventCallback ([in] IWlanCallback cbFunc, [in] String ifName )
```

**描述：**

注册IWiFi的回调函数，监听异步事件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 注册的回调函数。 | 
| ifName | 网卡名称。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### ResetDriver()

  
```
IWlanInterface::ResetDriver ([in] unsigned char chipId, [in] String ifName )
```

**描述：**

重启指定芯片ID的WLAN驱动程序。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| chipId | 需要进行重启驱动的芯片ID。 | 
| ifName | 网卡名称。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetCountryCode()

  
```
IWlanInterface::SetCountryCode ([in] struct HdfFeatureInfo ifeature, [in] String code, [in] unsigned int len )
```

**描述：**

设置国家码（表示AP射频所在的国家，规定了AP射频特性，包括AP的发送功率、支持的信道等。其目的是为了使AP的射频特性符合不同国家或区域的法律法规要求）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| code | 设置的国家码。 | 
| len | 国家码长度。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetMacAddress()

  
```
IWlanInterface::SetMacAddress ([in] struct HdfFeatureInfo ifeature, [in] unsigned char[] mac )
```

**描述：**

根据传入参数设置对应网卡的MAC地址。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| mac | 设置的MAC地址。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetPowerMode()

  
```
IWlanInterface::SetPowerMode ([in] struct HdfFeatureInfo ifeature, [in] unsigned char mode )
```

**描述：**

设置功率模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| mode | 功率模式，包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetProjectionScreenParam()

  
```
IWlanInterface::SetProjectionScreenParam ([in] String ifName, [in] struct ProjectionScreenCmdParam param )
```

**描述：**

设置投屏参数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。 | 
| param | 投屏参数。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetScanningMacAddress()

  
```
IWlanInterface::SetScanningMacAddress ([in] struct HdfFeatureInfo ifeature, [in] unsigned char[] scanMac )
```

**描述：**

设置扫描单个MAC地址。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| scanMac | 设置STA扫描的MAC地址。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetTxPower()

  
```
IWlanInterface::SetTxPower ([in] struct HdfFeatureInfo ifeature, [in] int power )
```

**描述：**

设置发射功率。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| power | 设置的发射功率。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Start()

  
```
IWlanInterface::Start ()
```

**描述：**

创建HAL和驱动之间的通道及获取驱动网卡信息，该函数调用在创建IWiFi实体后进行。

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### StartChannelMeas()

  
```
IWlanInterface::StartChannelMeas ([in] String ifName, [in] struct MeasChannelParam measChannelParam )
```

**描述：**

启动信道测量。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。 | 
| measChannelParam | 信道测量参数（信道号、测量时间）。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### StartScan()

  
```
IWlanInterface::StartScan ([in] struct HdfFeatureInfo ifeature, [in] struct HdfWifiScan scan )
```

**描述：**

启动扫描。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | feature对象。 | 
| scan | 扫描参数。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Stop()

  
```
IWlanInterface::Stop ()
```

**描述：**

销毁HAL和驱动之间的通道，该函数调用在销毁IWiFi实体前进行。

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### UnregisterEventCallback()

  
```
IWlanInterface::UnregisterEventCallback ([in] IWlanCallback cbFunc, [in] String ifName )
```

**描述：**

去注册IWiFi的回调函数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 去注册的回调函数。 | 
| ifName | 网卡名称。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### WifiSendCmdIoctl()

  
```
IWlanInterface::WifiSendCmdIoctl ([in] String ifName, [in] int cmdId, [in] byte[] paramBuf )
```

**描述：**

向驱动发送IO控制命令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 网卡名称。 | 
| cmdId | 命令ID。 | 
| paramBuf | 命令内容。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。
