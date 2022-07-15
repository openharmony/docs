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
| [FeatureType](_w_l_a_n.md#featuretype)&nbsp;{&nbsp;&nbsp;&nbsp;[PROTOCOL_80211_IFTYPE_UNSPECIFIED](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a6b209b916aabd18f2a950a82e68b6a4c),&nbsp;[PROTOCOL_80211_IFTYPE_ADHOC](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a0926a98ddc2ceec4ba58ebfc01c5fe35),&nbsp;[PROTOCOL_80211_IFTYPE_STATION](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012acd26f8cefbd658e9ea02feecefd054fb),&nbsp;[PROTOCOL_80211_IFTYPE_AP](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a9e92654b9ab6ed6eb62868f1e0e4ea8f),&nbsp;&nbsp;&nbsp;[PROTOCOL_80211_IFTYPE_AP_VLAN](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a991ad1a3f8c43b06c4eeb9dc88acdb1e),&nbsp;[PROTOCOL_80211_IFTYPE_WDS](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012aa25631c32cd6c996a7c96ba4f61299e2),&nbsp;[PROTOCOL_80211_IFTYPE_MONITOR](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a3ff1c1358af5a0c50b64e0ef0e96a970),&nbsp;[PROTOCOL_80211_IFTYPE_MESH_POINT](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012a382756b8a71015cd536cdbc113c4f483),&nbsp;&nbsp;&nbsp;[PROTOCOL_80211_IFTYPE_P2P_CLIENT](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012acfd81d6e484c6f7a3b863327af112cfc),&nbsp;[PROTOCOL_80211_IFTYPE_P2P_GO](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012abca0ccb5cf4c14af9b6ff0bd9eeb4173),&nbsp;[PROTOCOL_80211_IFTYPE_P2P_DEVICE](_w_l_a_n.md#ggad2b28a6ade408676d1371ea941824012ad63ad4a5a66892e842e4d75cc82b0755),&nbsp;[PROTOCOL_80211_IFTYPE_NUM](_w_l_a_n.md#p3611518433)&nbsp;} | 枚举WLAN相关特性的类型[FeatureType](_w_l_a_n.md#featuretype)。&nbsp;[更多...](_w_l_a_n.md#featuretype) | 


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
