# wifi_hal_ap_feature.h


## **概述**

**所属模块:**

[WLAN](_w_l_a_n.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [StaInfo](_sta_info.md) | 描述与AP连接的STA的基本信息&nbsp;[更多...](_sta_info.md) | 
| [IWiFiAp](_i_wi_fi_ap.md) | 继承了[IWiFiBaseFeature](_i_wi_fi_base_feature.md)基本特性，并包含AP模式下获取连接STA的信息和设置国家码的功能。&nbsp;[更多...](_i_wi_fi_ap.md) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [InitApFeature](_w_l_a_n.md#initapfeature)&nbsp;(struct&nbsp;[IWiFiAp](_i_wi_fi_ap.md)&nbsp;\*\*fe) | 初始化AP特性。WLAN服务在创建AP类型的特性[FeatureType](_w_l_a_n.md#featuretype)时调用。&nbsp;[更多...](_w_l_a_n.md#initapfeature) | 


## **详细描述**

提供WLAN的AP特性能力（获取与AP连接的STA的基本信息、设置国家码）。

**Since：**

1.0

**Version：**

1.0
