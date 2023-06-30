# WififenceRequest


## 概述

定义添加Wi-Fi围栏的数据结构。

**Since:**

4.0

**相关模块:**

[HdiLpfenceWififence](_hdi_lpfence_wififence.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [wififenceId](#wififenceid) | int<br/>Wi-Fi围栏的ID号，用于标识某个Wi-Fi围栏，不可重复添加相同ID号的围栏。 | 
| [algoType](#algotype) | int<br/>Wi-Fi围栏的匹配算法。详见[WififenceAlgoType](_hdi_lpfence_wififence.md#wififencealgotype)。 | 
| [bssid](#bssid) | unsigned&nbsp;char[]<br/>若使用[TYPE_ONE_BSSID](_hdi_lpfence_wififence.md#wififencealgotype)类型算法，则是多组Wi-Fi&nbsp;MAC地址。&nbsp;若使用[TYPE_ONE_BSSID](_hdi_lpfence_wififence.md#wififencealgotype)类型算法，则是多组的Wi-Fi&nbsp;MAC地址和对应RSSI值。 | 


## 类成员变量说明


### algoType

  
```
int WififenceRequest::algoType
```

**描述:**

Wi-Fi围栏的匹配算法。详见[WififenceAlgoType](_hdi_lpfence_wififence.md#wififencealgotype)。


### bssid

  
```
unsigned char [] WififenceRequest::bssid
```

**描述:**

若使用[TYPE_ONE_BSSID](_hdi_lpfence_wififence.md#wififencealgotype)类型算法，则是多组Wi-Fi MAC地址。 若使用[TYPE_ONE_BSSID](_hdi_lpfence_wififence.md#wififencealgotype)类型算法，则是多组的Wi-Fi MAC地址和对应RSSI值。


### wififenceId

  
```
int WififenceRequest::wififenceId
```

**描述:**

Wi-Fi围栏的ID号，用于标识某个Wi-Fi围栏，不可重复添加相同ID号的围栏。
