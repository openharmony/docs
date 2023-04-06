# WifiStationInfo


## **概述**

STA的信息。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[WLAN](wlan.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [rxRate](#rxrate) | 接收速率。 | 
| [txRate](#txrate) | 发送速率。 | 
| [flags](#flags) | 速率传输类型。 | 
| [rxVhtmcs](#rxvhtmcs) | 接收VHT-MCS（Very&nbsp;High&nbsp;Throughput&nbsp;Modulation&nbsp;and&nbsp;Coding&nbsp;Scheme）配置。 | 
| [txVhtmcs](#txvhtmcs) | 发送VHT-MCS（Very&nbsp;High&nbsp;Throughput&nbsp;Modulation&nbsp;and&nbsp;Coding&nbsp;Scheme）配置。 | 
| [rxMcs](#rxmcs) | 接收MCS（Modulation&nbsp;and&nbsp;Coding&nbsp;Scheme）索引。 | 
| [txMcs](#txmcs) | 发送MCS（Modulation&nbsp;and&nbsp;Coding&nbsp;Scheme）索引。 | 
| [rxVhtNss](#rxvhtnss) | 接收VHT-NSS（Very&nbsp;High&nbsp;Throughput&nbsp;Number&nbsp;of&nbsp;Spatial&nbsp;Streams）配置。 | 
| [txVhtNss](#txvhtnss) | 发送VHT-NSS（Very&nbsp;High&nbsp;Throughput&nbsp;Number&nbsp;of&nbsp;Spatial&nbsp;Streams）配置。 | 


## **类成员变量说明**


### flags

  
```
unsigned int WifiStationInfo::flags
```

**描述：**

速率传输类型。


### rxMcs

  
```
unsigned char WifiStationInfo::rxMcs
```

**描述：**

接收MCS（Modulation and Coding Scheme）索引。


### rxRate

  
```
unsigned int WifiStationInfo::rxRate
```

**描述：**

接收速率。


### rxVhtmcs

  
```
unsigned char WifiStationInfo::rxVhtmcs
```

**描述：**

接收VHT-MCS（Very High Throughput Modulation and Coding Scheme）配置。


### rxVhtNss

  
```
unsigned char WifiStationInfo::rxVhtNss
```

**描述：**

接收VHT-NSS（Very High Throughput Number of Spatial Streams）配置。


### txMcs

  
```
unsigned char WifiStationInfo::txMcs
```

**描述：**

发送MCS（Modulation and Coding Scheme）索引。


### txRate

  
```
unsigned int WifiStationInfo::txRate
```

**描述：**

发送速率。


### txVhtmcs

  
```
unsigned char WifiStationInfo::txVhtmcs
```

**描述：**

发送VHT-MCS（Very High Throughput Modulation and Coding Scheme）配置。


### txVhtNss

  
```
unsigned char WifiStationInfo::txVhtNss
```

**描述：**

发送VHT-NSS（Very High Throughput Number of Spatial Streams）配置。
