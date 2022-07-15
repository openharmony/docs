# IWiFiSta


## **概述**

**所属模块:**

[WLAN](_w_l_a_n.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [baseFeature](#basefeature) | 基本特性。 | 
| (&nbsp;[setScanningMacAddress](#setscanningmacaddress)&nbsp;)(const&nbsp;struct&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414208.xml#xref1079443811083932,link:zh-cn_topic_0000001295414208.xml](zh-cn_topic_0000001295414208.xml)&nbsp;\*staFeature,&nbsp;unsigned&nbsp;char&nbsp;\*scanMac,&nbsp;uint8_t&nbsp;len) | 设置扫描单个MAC地址。&nbsp;[更多...](#setscanningmacaddress) | 
| (&nbsp;[startScan](#startscan)&nbsp;)(const&nbsp;char&nbsp;\*ifName,&nbsp;WifiScan&nbsp;\*scan) | 启动扫描。&nbsp;[更多...](#startscan) | 


## **详细描述**

继承了[IWiFiBaseFeature](_i_wi_fi_base_feature.md)基本特性，额外包含设置扫描单个MAC地址功能。

**Since：**

1.0

**Version：**

1.0


## **类成员变量说明**


### baseFeature

  
```
struct IWiFiBaseFeature IWiFiSta::baseFeature
```

**描述：**

基本特性。


### setScanningMacAddress

  
```
int32_t(* IWiFiSta::setScanningMacAddress) (const struct IWiFiSta *staFeature, unsigned char *scanMac, uint8_t len)
```

**描述：**

设置扫描单个MAC地址。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| staFeature | 输入参数，STA特性[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414208.xml#xref557822862083932,link:zh-cn_topic_0000001295414208.xml](zh-cn_topic_0000001295414208.xml)。 | 
| scanMac | 输入参数，设置STA扫描的MAC地址。 | 
| len | 输入参数，MAC地址的长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### startScan

  
```
int32_t(* IWiFiSta::startScan) (const char *ifName, WifiScan *scan)
```

**描述：**

启动扫描。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| ifName | 输入参数，网卡名称。 | 
| scan | 输入参数，扫描参数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
