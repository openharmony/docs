# WififenceTypes.idl


## 概述

定义Wi-Fi围栏使用的数据类型。

**Since:**

4.0

**Version:**

1.0

**相关模块:**

[HdiLpfenceWififence](_hdi_lpfence_wififence.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [WififenceRequest](_wififence_request.md) | struct<br/>定义添加Wi-Fi围栏的数据结构。 | 
| [WififenceSize](_wififence_size.md) | struct<br/>定义Wi-Fi围栏使用信息的数据结构。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [WififenceTransition](_hdi_lpfence_wififence.md#wififencetransition)&nbsp;{&nbsp;WIFIFENCE_TRANSITION_ENTERED&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0)&nbsp;,&nbsp;WIFIFENCE_TRANSITION_EXITED&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1)&nbsp;} | 枚举Wi-Fi围栏状态事件。 | 
| [WififenceAlgoType](_hdi_lpfence_wififence.md#wififencealgotype)&nbsp;{&nbsp;TYPE_ONE_BSSID&nbsp;=&nbsp;1&nbsp;,&nbsp;TYPE_FP_MATCH&nbsp;=&nbsp;2&nbsp;} | 枚举Wi-Fi围栏的匹配算法。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.location.lpfence.wififence.v1_0 | Wi-Fi围栏模块接口的包路径。 | 
