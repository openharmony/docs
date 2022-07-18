# WLAN


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [wifi_hal.h](wifi__hal_8h.md) | 提供给WLAN服务的WLAN基本能力接口。 | 
| [wifi_hal_ap_feature.h](wifi__hal__ap__feature_8h.md) | 提供WLAN的AP特性能力（获取与AP连接的STA的基本信息、设置国家码）。 | 
| [wifi_hal_base_feature.h](wifi__hal__base__feature_8h.md) | 提供WLAN基本特性能力。 | 
| [wifi_hal_sta_feature.h](wifi__hal__sta__feature_8h.md) | 提供WLAN的STA特性能力。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [IWiFi](_i_wi_fi.md) | HAL对WLAN服务提供的基本能力。&nbsp;[更多...](_i_wi_fi.md) | 
| [StaInfo](_sta_info.md) | 描述与AP连接的STA的基本信息&nbsp;[更多...](_sta_info.md) | 
| [IWiFiAp](_i_wi_fi_ap.md) | 继承了[IWiFiBaseFeature](_i_wi_fi_base_feature.md)基本特性，并包含AP模式下获取连接STA的信息和设置国家码的功能。&nbsp;[更多...](_i_wi_fi_ap.md) | 
| [IWiFiBaseFeature](_i_wi_fi_base_feature.md) | WLAN基本特性操作接口，包括获取网卡名称，设置MAC地址，设置发射功率等公共能力接口。&nbsp;[更多...](_i_wi_fi_base_feature.md) | 
| [IWiFiSta](_i_wi_fi_sta.md) | 继承了[IWiFiBaseFeature](_i_wi_fi_base_feature.md)基本特性，额外包含设置扫描单个MAC地址功能。&nbsp;[更多...](_i_wi_fi_sta.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| IFNAME_MAX_LEN&nbsp;&nbsp;&nbsp;&nbsp;16 | 网卡名称最大长度。 | 
| WIFI_MAC_ADDR_LENGTH&nbsp;&nbsp;&nbsp;&nbsp;6 | WLAN的MAC地址长度。 | 
| ERR_UNAUTH_ACCESS&nbsp;&nbsp;&nbsp;&nbsp;(-6) | 定义访问失败错误码。 | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([CallbackFunc](#callbackfunc))&nbsp;(uint32_t&nbsp;event,&nbsp;void&nbsp;\*data,&nbsp;const&nbsp;char&nbsp;\*ifName) | 定义IWiFi回调函数的原型，监听异步事件。&nbsp;[更多...](#callbackfunc) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [FeatureType](#featuretype)&nbsp;{&nbsp;&nbsp;&nbsp;PROTOCOL_80211_IFTYPE_UNSPECIFIED,&nbsp;PROTOCOL_80211_IFTYPE_ADHOC,&nbsp;PROTOCOL_80211_IFTYPE_STATION,&nbsp;PROTOCOL_80211_IFTYPE_AP,&nbsp;&nbsp;&nbsp;PROTOCOL_80211_IFTYPE_AP_VLAN,&nbsp;PROTOCOL_80211_IFTYPE_WDS,&nbsp;PROTOCOL_80211_IFTYPE_MONITOR,&nbsp;PROTOCOL_80211_IFTYPE_MESH_POINT,&nbsp;&nbsp;&nbsp;PROTOCOL_80211_IFTYPE_P2P_CLIENT,&nbsp;PROTOCOL_80211_IFTYPE_P2P_GO,&nbsp;PROTOCOL_80211_IFTYPE_P2P_DEVICE,&nbsp;PROTOCOL_80211_IFTYPE_NUM&nbsp;} | 枚举WLAN相关特性的类型[FeatureType](#featuretype)。&nbsp;[更多...](#featuretype) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [WifiConstruct](#wificonstruct)&nbsp;(struct&nbsp;[IWiFi](_i_wi_fi.md)&nbsp;\*\*wifiInstance) | 创建IWiFi结构体，挂接[IWiFi](_i_wi_fi.md)中能力接口。&nbsp;[更多...](#wificonstruct) | 
| [WifiDestruct](#wifidestruct)&nbsp;(struct&nbsp;[IWiFi](_i_wi_fi.md)&nbsp;\*\*wifiInstance) | 销毁IWiFi结构体并释放相关资源。&nbsp;[更多...](#wifidestruct) | 
| [InitApFeature](#initapfeature)&nbsp;(struct&nbsp;[IWiFiAp](_i_wi_fi_ap.md)&nbsp;\*\*fe) | 初始化AP特性。WLAN服务在创建AP类型的特性[FeatureType](#featuretype)时调用。&nbsp;[更多...](#initapfeature) | 
| [InitBaseFeature](#initbasefeature)&nbsp;(struct&nbsp;[IWiFiBaseFeature](_i_wi_fi_base_feature.md)&nbsp;\*\*fe) | WLAN服务创建任何类型的特性{\@Link&nbsp;FeatureType}时，都需要调用此函数。&nbsp;[更多...](#initbasefeature) | 
| [InitStaFeature](#initstafeature)&nbsp;(struct&nbsp;[IWiFiSta](_i_wi_fi_sta.md)&nbsp;\*\*fe) | 初始化STA特性。WLAN服务在创建STA类型的特性[FeatureType](#featuretype)时调用。&nbsp;[更多...](#initstafeature) | 


## **详细描述**

WLAN模块向上层WLAN服务提供了统一接口。

HDI层开发人员可根据WLAN模块提供的向上统一接口获取如下能力：建立/关闭WLAN热点，扫描，关联WLAN热点，WLAN平台芯片管理，网络数据缓冲的申请、释放、移动等操作，网络设备管理，电源管理等。

**Since：**

1.0

**Version：**

1.0


## **类型定义说明**


### CallbackFunc

  
```
typedef int32_t(* CallbackFunc) (uint32_t event, void *data, const char *ifName)
```

**描述：**

定义IWiFi回调函数的原型，监听异步事件。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| event | 输入参数，回调传入的事件类型标识。 | 
| data | 输入参数，回调传入的数据。 | 
| ifName | 输入参数，网卡名称。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

1.0

**Version：**

1.0


## **枚举类型说明**


### FeatureType

  
```
enum FeatureType
```

**描述：**

枚举WLAN相关特性的类型[FeatureType](#featuretype)。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PROTOCOL_80211_IFTYPE_UNSPECIFIED | 未定义的类型 | 
| PROTOCOL_80211_IFTYPE_ADHOC | 特设型网络 | 
| PROTOCOL_80211_IFTYPE_STATION | 工作站 | 
| PROTOCOL_80211_IFTYPE_AP | 接入点 | 
| PROTOCOL_80211_IFTYPE_AP_VLAN | 虚拟接入点 | 
| PROTOCOL_80211_IFTYPE_WDS | 无线分布式系统 | 
| PROTOCOL_80211_IFTYPE_MONITOR | 网络监听器 | 
| PROTOCOL_80211_IFTYPE_MESH_POINT | 组网 | 
| PROTOCOL_80211_IFTYPE_P2P_CLIENT | 对等网络客户端 | 
| PROTOCOL_80211_IFTYPE_P2P_GO | 对等网络群组所有者 | 
| PROTOCOL_80211_IFTYPE_P2P_DEVICE | 对等网络设备 | 
| PROTOCOL_80211_IFTYPE_NUM | 网口的数目 | 


## **函数说明**


### InitApFeature()

  
```
int32_t InitApFeature (struct IWiFiAp **fe)
```

**描述：**

初始化AP特性。WLAN服务在创建AP类型的特性[FeatureType](#featuretype)时调用。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| fe | 输入参数，AP特性[IWiFiAp](_i_wi_fi_ap.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

1.0

**Version：**

1.0


### InitBaseFeature()

  
```
int32_t InitBaseFeature (struct IWiFiBaseFeature **fe)
```

**描述：**

WLAN服务创建任何类型的特性{\@Link FeatureType}时，都需要调用此函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| fe | 输入参数，基本特性[IWiFiBaseFeature](_i_wi_fi_base_feature.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

1.0

**Version：**

1.0


### InitStaFeature()

  
```
int32_t InitStaFeature (struct IWiFiSta **fe)
```

**描述：**

初始化STA特性。WLAN服务在创建STA类型的特性[FeatureType](#featuretype)时调用。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| fe | 输出参数，STA特性[IWiFiSta](_i_wi_fi_sta.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

1.0

**Version：**

1.0


### WifiConstruct()

  
```
int32_t WifiConstruct (struct IWiFi **wifiInstance)
```

**描述：**

创建IWiFi结构体，挂接[IWiFi](_i_wi_fi.md)中能力接口。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| wifiInstance | HAL服务对象[IWiFi](_i_wi_fi.md) | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

1.0

**Version：**

1.0


### WifiDestruct()

  
```
int32_t WifiDestruct (struct IWiFi **wifiInstance)
```

**描述：**

销毁IWiFi结构体并释放相关资源。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| wifiInstance | HAL服务对象[IWiFi](_i_wi_fi.md) | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

1.0

**Version：**

1.0
