# WififenceRequest


## 概述

定义添加Wi-Fi围栏的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceWififence](_hdi_lpfence_wififence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [wififenceId](#wififenceid) | Wi-Fi围栏的ID号，用于标识某个Wi-Fi围栏，不可重复添加相同ID号的围栏。 | 
| int [algoType](#algotype) | Wi-Fi围栏的匹配算法。详见[WififenceAlgoType](_hdi_lpfence_wififence.md#wififencealgotype)。 | 
| unsigned char[] [bssid](#bssid) | 若使用TYPE_ONE_BSSID类型算法，则是多组Wi-Fi MAC地址。<br/>若使用TYPE_FP_MATCH类型算法，则是多组的Wi-Fi MAC地址和对应RSSI值。 | 


## 类成员变量说明


### algoType

```
int WififenceRequest::algoType
```

**描述**


Wi-Fi围栏的匹配算法。详见[WififenceAlgoType](_hdi_lpfence_wififence.md#wififencealgotype)。


### bssid

```
unsigned char [] WififenceRequest::bssid
```

**描述**


若使用TYPE_ONE_BSSID类型算法，则是多组Wi-Fi MAC地址。若使用TYPE_FP_MATCH类型算法，则是多组的Wi-Fi MAC地址和对应RSSI值。


### wififenceId

```
int WififenceRequest::wififenceId
```

**描述**


Wi-Fi围栏的ID号，用于标识某个Wi-Fi围栏，不可重复添加相同ID号的围栏。
