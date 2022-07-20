# wifi_hal_base_feature.h


## **概述**

**所属模块:**

[WLAN](_w_l_a_n.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [IWiFiBaseFeature](_i_wi_fi_base_feature.md) | WLAN基本特性操作接口，包括获取网卡名称，设置MAC地址，设置发射功率等公共能力接口。&nbsp;[更多...](_i_wi_fi_base_feature.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| [IFNAME_MAX_LEN](_w_l_a_n.md#ga63637ece87095ff8d153f650434ecf97)&nbsp;&nbsp;&nbsp;16 | 网卡名称最大长度。 | 
| [WIFI_MAC_ADDR_LENGTH](_w_l_a_n.md#ga27ea7645cf89c113dae48346e19a676f)&nbsp;&nbsp;&nbsp;6 | WLAN的MAC地址长度。 | 
| [ERR_UNAUTH_ACCESS](_w_l_a_n.md#gadfe9ac5a374d348cd8f77a84cd5ab94e)&nbsp;&nbsp;&nbsp;(-6) | 定义访问失败错误码。 | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [FeatureType](_w_l_a_n.md#featuretype)&nbsp;{&nbsp;&nbsp;&nbsp;PROTOCOL_80211_IFTYPE_UNSPECIFIED,&nbsp;PROTOCOL_80211_IFTYPE_ADHOC,&nbsp;PROTOCOL_80211_IFTYPE_STATION,&nbsp;PROTOCOL_80211_IFTYPE_AP,&nbsp;&nbsp;&nbsp;PROTOCOL_80211_IFTYPE_AP_VLAN,&nbsp;PROTOCOL_80211_IFTYPE_WDS,&nbsp;PROTOCOL_80211_IFTYPE_MONITOR,&nbsp;PROTOCOL_80211_IFTYPE_MESH_POINT,&nbsp;&nbsp;&nbsp;PROTOCOL_80211_IFTYPE_P2P_CLIENT,&nbsp;PROTOCOL_80211_IFTYPE_P2P_GO,&nbsp;PROTOCOL_80211_IFTYPE_P2P_DEVICE,&nbsp;PROTOCOL_80211_IFTYPE_NUM&nbsp;} | 枚举WLAN相关特性的类型[FeatureType](_w_l_a_n.md#featuretype)。&nbsp;[更多...](_w_l_a_n.md#featuretype) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [InitBaseFeature](_w_l_a_n.md#initbasefeature)&nbsp;(struct&nbsp;[IWiFiBaseFeature](_i_wi_fi_base_feature.md)&nbsp;\*\*fe) | WLAN服务创建任何类型的特性{\@Link&nbsp;FeatureType}时，都需要调用此函数。&nbsp;[更多...](_w_l_a_n.md#initbasefeature) | 


## **详细描述**

提供WLAN基本特性能力。

**Since：**

1.0

**Version：**

1.0
