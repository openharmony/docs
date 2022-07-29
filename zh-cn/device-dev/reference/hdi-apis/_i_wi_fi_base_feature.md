# IWiFiBaseFeature


## **概述**

**所属模块:**

[WLAN](_w_l_a_n.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [ifName](#ifname)&nbsp;[[IFNAME_MAX_LEN](_w_l_a_n.md#ga63637ece87095ff8d153f650434ecf97)] | 网卡名称。 | 
| **type** | 特性的类型，参考[FeatureType](_w_l_a_n.md#featuretype)。 | 
| (&nbsp;[getNetworkIfaceName](#getnetworkifacename)&nbsp;)(const&nbsp;struct&nbsp;IWiFiBaseFeature&nbsp;\*baseFeature) | 根据基本特性获取网卡名称。&nbsp;[更多...](#getnetworkifacename) | 
| (&nbsp;[getFeatureType](#getfeaturetype)&nbsp;)(const&nbsp;struct&nbsp;IWiFiBaseFeature&nbsp;\*baseFeature) | 获取基本特性的类型[FeatureType](_w_l_a_n.md#featuretype)。&nbsp;[更多...](#getfeaturetype) | 
| (&nbsp;[setMacAddress](#setmacaddress)&nbsp;)(const&nbsp;struct&nbsp;IWiFiBaseFeature&nbsp;\*baseFeature,&nbsp;unsigned&nbsp;char&nbsp;\*mac,&nbsp;uint8_t&nbsp;len) | 根据传入参数设置对应网卡的MAC地址。&nbsp;[更多...](#setmacaddress) | 
| (&nbsp;[getDeviceMacAddress](#getdevicemacaddress)&nbsp;)(const&nbsp;struct&nbsp;IWiFiBaseFeature&nbsp;\*baseFeature,&nbsp;unsigned&nbsp;char&nbsp;\*mac,&nbsp;uint8_t&nbsp;len) | 获取设备的MAC地址。&nbsp;[更多...](#getdevicemacaddress) | 
| (&nbsp;[getValidFreqsWithBand](#getvalidfreqswithband)&nbsp;)(const&nbsp;struct&nbsp;IWiFiBaseFeature&nbsp;\*baseFeature,&nbsp;int32_t&nbsp;band,&nbsp;int32_t&nbsp;\*freqs,&nbsp;uint32_t&nbsp;count,&nbsp;uint32_t&nbsp;\*num) | 获取指定频段（2.4G或者5G）下支持的频率。&nbsp;[更多...](#getvalidfreqswithband) | 
| (&nbsp;[setTxPower](#settxpower)&nbsp;)(const&nbsp;struct&nbsp;IWiFiBaseFeature&nbsp;\*baseFeature,&nbsp;int32_t&nbsp;power) | 设置发射功率。&nbsp;[更多...](#settxpower) | 
| (&nbsp;[getChipId](#getchipid)&nbsp;)(const&nbsp;struct&nbsp;IWiFiBaseFeature&nbsp;\*baseFeature,&nbsp;uint8_t&nbsp;\*chipId) | 获得当前驱动的芯片ID。&nbsp;[更多...](#getchipid) | 
| (&nbsp;[getIfNamesByChipId](#getifnamesbychipid)&nbsp;)(const&nbsp;uint8_t&nbsp;chipId,&nbsp;char&nbsp;\*\*ifNames,&nbsp;uint32_t&nbsp;\*num) | 通过芯片ID获得当前芯片所有的网卡名称。&nbsp;[更多...](#getifnamesbychipid) | 


## **详细描述**

WLAN基本特性操作接口，包括获取网卡名称，设置MAC地址，设置发射功率等公共能力接口。

**Since：**

1.0

**Version：**

1.0


## **类成员变量说明**


### getChipId

  
```
int32_t(* IWiFiBaseFeature::getChipId) (const struct IWiFiBaseFeature *baseFeature, uint8_t *chipId)
```

**描述：**

获得当前驱动的芯片ID。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| baseFeature | 输入参数，基本特性。 | 
| chipId | 输出参数，获得的芯片ID。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### getDeviceMacAddress

  
```
int32_t(* IWiFiBaseFeature::getDeviceMacAddress) (const struct IWiFiBaseFeature *baseFeature, unsigned char *mac, uint8_t len)
```

**描述：**

获取设备的MAC地址。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| baseFeature | 输入参数，基本特性。 | 
| mac | 输出参数，获得的MAC地址。 | 
| len | 输入参数，获得的MAC地址长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### getFeatureType

  
```
int32_t(*IWiFiBaseFeature::getFeatureType) (const struct IWiFiBaseFeature *baseFeature)
```

**描述：**

获取基本特性的类型[FeatureType](_w_l_a_n.md#featuretype)。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| baseFeature | 输入参数，基本特性。 | 

**返回：**

如果操作成功，则返回特性类型。

如果操作失败，则返回负值。


### getIfNamesByChipId

  
```
int32_t(* IWiFiBaseFeature::getIfNamesByChipId) (const uint8_t chipId, char **ifNames, uint32_t *num)
```

**描述：**

通过芯片ID获得当前芯片所有的网卡名称。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| chipId | 输入参数，需要获取网卡名称的芯片ID。 | 
| ifNames | 输出参数，网卡名称。 | 
| num | 输出参数，网卡的数量。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### getNetworkIfaceName

  
```
const char*(* IWiFiBaseFeature::getNetworkIfaceName) (const struct IWiFiBaseFeature *baseFeature)
```

**描述：**

根据基本特性获取网卡名称。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| baseFeature | 输入参数，基本特性。 | 

**返回：**

如果操作成功，则返回网卡名称。

如果操作失败，则返回NULL。


### getValidFreqsWithBand

  
```
int32_t(* IWiFiBaseFeature::getValidFreqsWithBand) (const struct IWiFiBaseFeature *baseFeature, int32_t band, int32_t *freqs, uint32_t count, uint32_t *num)
```

**描述：**

获取指定频段（2.4G或者5G）下支持的频率。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| baseFeature | 输入参数，基本特性。 | 
| band | 输入参数，指定的一个频段。 | 
| freqs | 输出参数，保存支持的频率。 | 
| count | 输入参数，频率数组的元素个数。 | 
| num | 输出参数，实际支持的频率个数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### ifName

  
```
char IWiFiBaseFeature::ifName[IFNAME_MAX_LEN]
```

**描述：**

网卡名称。


### setMacAddress

  
```
int32_t(* IWiFiBaseFeature::setMacAddress) (const struct IWiFiBaseFeature *baseFeature, unsigned char *mac, uint8_t len)
```

**描述：**

根据传入参数设置对应网卡的MAC地址。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| baseFeature | 输入参数，基本特性。 | 
| mac | 输入参数，设置的MAC地址。 | 
| len | 输入参数，设置的MAC地址长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### setTxPower

  
```
int32_t(* IWiFiBaseFeature::setTxPower) (const struct IWiFiBaseFeature *baseFeature, int32_t power)
```

**描述：**

设置发射功率。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| baseFeature | 输入参数，基本特性。 | 
| power | 输入参数，设置的发射功率。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
