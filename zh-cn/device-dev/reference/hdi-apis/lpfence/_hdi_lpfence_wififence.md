# HdiLpfenceWififence


## 概述

为低功耗围栏服务提供Wi-Fi围栏的API

本模块接口提供添加Wi-Fi围栏，删除Wi-Fi围栏，获取Wi-Fi围栏状态，获取Wi-Fi围栏使用信息的功能。 应用场景：一般用于判断设备是否在室内特定位置，如居所内或商场的某个店铺内。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IWififenceCallback.idl](_i_wififence_callback_8idl.md) | 定义Wi-Fi围栏模块回调接口。 | 
| [IWififenceInterface.idl](_i_wififence_interface_8idl.md) | 定义Wi-Fi围栏模块回调接口。 | 
| [WififenceTypes.idl](_wififence_types_8idl.md) | 定义Wi-Fi围栏使用的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IWififenceCallback](interface_i_wififence_callback.md) | 定义Wi-Fi围栏模块的回调函数 | 
| interface&nbsp;&nbsp;[IWififenceInterface](interface_i_wififence_interface.md) | 定义对Wi-Fi围栏模块进行基本操作的接口。 | 
| struct&nbsp;&nbsp;[WififenceRequest](_wififence_request.md) | 定义添加Wi-Fi围栏的数据结构。 | 
| struct&nbsp;&nbsp;[WififenceSize](_wififence_size.md) | 定义Wi-Fi围栏使用信息的数据结构。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [WififenceTransition](#wififencetransition) { WIFIFENCE_TRANSITION_ENTERED = (1 &lt;&lt; 0) , WIFIFENCE_TRANSITION_EXITED = (1 &lt;&lt; 1) } | 枚举Wi-Fi围栏状态事件。 | 
| [WififenceAlgoType](#wififencealgotype) { TYPE_ONE_BSSID = 1 , TYPE_FP_MATCH = 2 } | 枚举Wi-Fi围栏的匹配算法。 | 


## 枚举类型说明


### WififenceAlgoType

```
enum WififenceAlgoType
```

**描述**


枚举Wi-Fi围栏的匹配算法。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| TYPE_ONE_BSSID | Wi-Fi围栏中MAC地址与设备扫描的MAC地址有交集时，即认为设备在围栏内。 | 
| TYPE_FP_MATCH | Wi-Fi围栏中MAC地址和RSSI值与设备扫描的MAC地址和RSSI值相似度达到一定阈值时，即认为设备在围栏内。 | 


### WififenceTransition

```
enum WififenceTransition
```

**描述**


枚举Wi-Fi围栏状态事件。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| WIFIFENCE_TRANSITION_ENTERED | 设备在Wi-Fi围栏范围内。 | 
| WIFIFENCE_TRANSITION_EXITED | 设备在Wi-Fi围栏范围外。 | 
