# IWiFi


## **概述**

**所属模块:**

[WLAN](_w_l_a_n.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| (&nbsp;[start](#start)&nbsp;)(struct&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293957.xml#xref459063066083932,link:zh-cn_topic_0000001348293957.xml](zh-cn_topic_0000001348293957.xml)&nbsp;\*iwifi) | 创建HAL和驱动之间的通道及获取驱动网卡信息，该函数调用在创建IWiFi实体后进行。&nbsp;[更多...](#start) | 
| (&nbsp;[stop](#stop)&nbsp;)(struct&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001348293957.xml#xref1577893620083932,link:zh-cn_topic_0000001348293957.xml](zh-cn_topic_0000001348293957.xml)&nbsp;\*iwifi) | 销毁HAL和驱动之间的通道，该函数调用在销毁IWiFi实体前进行。&nbsp;[更多...](#stop) | 
| (&nbsp;[getSupportFeature](#getsupportfeature)&nbsp;)(uint8_t&nbsp;\*supType,&nbsp;uint32_t&nbsp;size) | 获取该设备支持的WLAN特性（不考虑当前的使用状态）。&nbsp;[更多...](#getsupportfeature) | 
| (&nbsp;[getSupportCombo](#getsupportcombo)&nbsp;)(uint64_t&nbsp;\*combo,&nbsp;uint32_t&nbsp;size) | 获取多网卡共存情况。&nbsp;[更多...](#getsupportcombo) | 
| (&nbsp;[createFeature](#createfeature)&nbsp;)(int32_t&nbsp;type,&nbsp;struct&nbsp;[IWiFiBaseFeature](_i_wi_fi_base_feature.md)&nbsp;\*\*ifeature) | 根据输入类型创建对应的特性[IWiFiBaseFeature](_i_wi_fi_base_feature.md)。&nbsp;[更多...](#createfeature) | 
| (&nbsp;[getFeatureByIfName](#getfeaturebyifname)&nbsp;)(const&nbsp;char&nbsp;\*ifName,&nbsp;struct&nbsp;[IWiFiBaseFeature](_i_wi_fi_base_feature.md)&nbsp;\*\*ifeature) | 通过网络接口名字获取对应的特性。&nbsp;[更多...](#getfeaturebyifname) | 
| (&nbsp;[registerEventCallback](#registereventcallback)&nbsp;)([CallbackFunc](_w_l_a_n.md#callbackfunc)&nbsp;cbFunc,&nbsp;const&nbsp;char&nbsp;\*ifName) | 注册IWiFi的回调函数，监听异步事件。&nbsp;[更多...](#registereventcallback) | 
| (&nbsp;[unregisterEventCallback](#unregistereventcallback)&nbsp;)([CallbackFunc](_w_l_a_n.md#callbackfunc)&nbsp;cbFunc,&nbsp;const&nbsp;char&nbsp;\*ifName) | 去注册IWiFi的回调函数。&nbsp;[更多...](#unregistereventcallback) | 
| (&nbsp;[destroyFeature](#destroyfeature)&nbsp;)(struct&nbsp;[IWiFiBaseFeature](_i_wi_fi_base_feature.md)&nbsp;\*ifeature) | 根据输入类型销毁对应的特性[IWiFiBaseFeature](_i_wi_fi_base_feature.md)。&nbsp;[更多...](#destroyfeature) | 
| (&nbsp;[resetDriver](#resetdriver)&nbsp;)(const&nbsp;uint8_t&nbsp;chipId,&nbsp;const&nbsp;char&nbsp;\*ifName) | 重置具有指定芯片ID的WLAN驱动程序。&nbsp;[更多...](#resetdriver) | 
| (&nbsp;[getNetDevInfo](#getnetdevinfo)&nbsp;)(struct&nbsp;NetDeviceInfoResult&nbsp;\*netDeviceInfoResult) | 获取网络设备信息（设备索引、网卡名字、MAC等信息）。&nbsp;[更多...](#getnetdevinfo) | 
| (&nbsp;[getPowerMode](#getpowermode)&nbsp;)(const&nbsp;char&nbsp;\*ifName,&nbsp;uint8_t&nbsp;\*mode) | 获取正在使用的功率模式。&nbsp;[更多...](#getpowermode) | 
| (&nbsp;[setPowerMode](#setpowermode)&nbsp;)(const&nbsp;char&nbsp;\*ifName,&nbsp;uint8_t&nbsp;mode) | 设置功率模式&nbsp;[更多...](#setpowermode) | 


## **详细描述**

HAL对WLAN服务提供的基本能力。

用于创建HAL与驱动的通道，创建/获取/销毁WLAN特性等。

**Since：**

1.0

**Version：**

1.0


## **类成员变量说明**


### createFeature

  
```
int32_t(* IWiFi::createFeature) (int32_t type, struct IWiFiBaseFeature **ifeature)
```

**描述：**

根据输入类型创建对应的特性[IWiFiBaseFeature](_i_wi_fi_base_feature.md)。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| type | 输入参数，创建的feature类型。 | 
| ifeature | 输出参数，获取创建的feature对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### destroyFeature

  
```
int32_t(* IWiFi::destroyFeature) (struct IWiFiBaseFeature *ifeature)
```

**描述：**

根据输入类型销毁对应的特性[IWiFiBaseFeature](_i_wi_fi_base_feature.md)。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| ifeature | 输入参数，销毁的feature对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### getFeatureByIfName

  
```
int32_t(* IWiFi::getFeatureByIfName) (const char *ifName, struct IWiFiBaseFeature **ifeature)
```

**描述：**

通过网络接口名字获取对应的特性。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 输入参数，网卡名称。 | 
| ifeature | 输出参数，获取该网络接口名字的feature对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### getNetDevInfo

  
```
int32_t(* IWiFi::getNetDevInfo) (struct NetDeviceInfoResult *netDeviceInfoResult)
```

**描述：**

获取网络设备信息（设备索引、网卡名字、MAC等信息）。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| netDeviceInfoResult | 输出参数，得到的网络设备信息。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### getPowerMode

  
```
int32_t(* IWiFi::getPowerMode) (const char *ifName, uint8_t *mode)
```

**描述：**

获取正在使用的功率模式。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 输入参数，网卡名称。 | 
| mode | 输出参数，功率模式，包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### getSupportCombo

  
```
int32_t(* IWiFi::getSupportCombo) (uint64_t *combo, uint32_t size)
```

**描述：**

获取多网卡共存情况。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| combo | 输出参数，基于芯片的能力保存当前所有支持的多网卡共存情况（比如支持AP，STA，P2P等不同组合的共存）。 | 
| size | 输入参数，combo数组的长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### getSupportFeature

  
```
int32_t(* IWiFi::getSupportFeature) (uint8_t *supType, uint32_t size)
```

**描述：**

获取该设备支持的WLAN特性（不考虑当前的使用状态）。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| supType | 输出参数，保存当前设备支持的特性。 | 
| size | 输入参数，supType数组的长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### registerEventCallback

  
```
int32_t(* IWiFi::registerEventCallback) (CallbackFunc cbFunc, const char *ifName)
```

**描述：**

注册IWiFi的回调函数，监听异步事件。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 输入参数，注册的回调函数。 | 
| ifName | 输入参数，网卡名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### resetDriver

  
```
int32_t(* IWiFi::resetDriver) (const uint8_t chipId, const char *ifName)
```

**描述：**

重置具有指定芯片ID的WLAN驱动程序。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| chipId | 输入参数，需要进行重置驱动的对应芯片ID。 | 
| ifName | 输入参数，网卡名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### setPowerMode

  
```
int32_t(* IWiFi::setPowerMode) (const char *ifName, uint8_t mode)
```

**描述：**

设置功率模式

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 输入参数，网卡名称。 | 
| mode | 输入参数，功率模式,包括睡眠模式（待机状态运行）、一般模式（正常额定功率运行）、穿墙模式（最大功率运行，提高信号强度和覆盖面积）。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### start

  
```
int32_t(* IWiFi::start) (struct IWiFi *iwifi)
```

**描述：**

创建HAL和驱动之间的通道及获取驱动网卡信息，该函数调用在创建IWiFi实体后进行。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| iwifi | 输入参数，IWiFi对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### stop

  
```
int32_t(* IWiFi::stop) (struct IWiFi *iwifi)
```

**描述：**

销毁HAL和驱动之间的通道，该函数调用在销毁IWiFi实体前进行。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| iwifi | 输入参数，IWiFi对象。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### unregisterEventCallback

  
```
int32_t(* IWiFi::unregisterEventCallback) (CallbackFunc cbFunc, const char *ifName)
```

**描述：**

去注册IWiFi的回调函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 输入参数，去注册的回调函数。 | 
| ifName | 输入参数，网卡名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
