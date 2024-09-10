# WififenceTypes.idl


## 概述

定义Wi-Fi围栏使用的数据类型。

模块包路径：ohos.hdi.location.lpfence.wififence.v1_0

**起始版本：** 4.0

**相关模块：**[HdiLpfenceWififence](_hdi_lpfence_wififence.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[WififenceRequest](_wififence_request.md) | 定义添加Wi-Fi围栏的数据结构。 | 
| struct&nbsp;&nbsp;[WififenceSize](_wififence_size.md) | 定义Wi-Fi围栏使用信息的数据结构。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [WififenceTransition](_hdi_lpfence_wififence.md#wififencetransition) { WIFIFENCE_TRANSITION_ENTERED = (1 &lt;&lt; 0) , WIFIFENCE_TRANSITION_EXITED = (1 &lt;&lt; 1) } | 枚举Wi-Fi围栏状态事件。 | 
| [WififenceAlgoType](_hdi_lpfence_wififence.md#wififencealgotype) { TYPE_ONE_BSSID = 1 , TYPE_FP_MATCH = 2 } | 枚举Wi-Fi围栏的匹配算法。 | 
