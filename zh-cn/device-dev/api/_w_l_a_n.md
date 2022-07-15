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
| [FeatureType](#featuretype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref2005757439083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012a6b209b916aabd18f2a950a82e68b6a4c](#ggad2b28a6ade408676d1371ea941824012a6b209b916aabd18f2a950a82e68b6a4c),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref356941748083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012a0926a98ddc2ceec4ba58ebfc01c5fe35](#ggad2b28a6ade408676d1371ea941824012a0926a98ddc2ceec4ba58ebfc01c5fe35),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref2034104077083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012acd26f8cefbd658e9ea02feecefd054fb](#ggad2b28a6ade408676d1371ea941824012acd26f8cefbd658e9ea02feecefd054fb),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref1210444972083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012a9e92654b9ab6ed6eb62868f1e0e4ea8f](#ggad2b28a6ade408676d1371ea941824012a9e92654b9ab6ed6eb62868f1e0e4ea8f),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref85888507083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012a991ad1a3f8c43b06c4eeb9dc88acdb1e](#ggad2b28a6ade408676d1371ea941824012a991ad1a3f8c43b06c4eeb9dc88acdb1e),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref2011035674083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012aa25631c32cd6c996a7c96ba4f61299e2](#ggad2b28a6ade408676d1371ea941824012aa25631c32cd6c996a7c96ba4f61299e2),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref1547927522083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012a3ff1c1358af5a0c50b64e0ef0e96a970](#ggad2b28a6ade408676d1371ea941824012a3ff1c1358af5a0c50b64e0ef0e96a970),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref959999069083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012a382756b8a71015cd536cdbc113c4f483](#ggad2b28a6ade408676d1371ea941824012a382756b8a71015cd536cdbc113c4f483),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref769421272083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012acfd81d6e484c6f7a3b863327af112cfc](#ggad2b28a6ade408676d1371ea941824012acfd81d6e484c6f7a3b863327af112cfc),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref2012633117083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012abca0ccb5cf4c14af9b6ff0bd9eeb4173](#ggad2b28a6ade408676d1371ea941824012abca0ccb5cf4c14af9b6ff0bd9eeb4173),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref1649808399083931,link:zh-cn_topic_0000001295573780.xml#ggad2b28a6ade408676d1371ea941824012ad63ad4a5a66892e842e4d75cc82b0755](#ggad2b28a6ade408676d1371ea941824012ad63ad4a5a66892e842e4d75cc82b0755),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573780.xml#xref2156186164917,link:#p3611518433](#p3611518433)&nbsp;} | 枚举WLAN相关特性的类型[FeatureType](#featuretype)。&nbsp;[更多...](#featuretype) | 


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
