# HdiLpfenceWififence


## 概述

为低功耗围栏服务提供Wi-Fi围栏的API。

本模块接口提供添加Wi-Fi围栏，删除Wi-Fi围栏，获取Wi-Fi围栏状态，获取Wi-Fi围栏使用信息的功能。

应用场景：一般用于判断设备是否在室内特定位置，如居所内或商场的某个店铺内。

**Since:**

4.0

**Version:**

1.0


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
| [IWififenceCallback](interface_i_wififence_callback.md) | interface<br/>导入Wi-Fi围栏模块的数据类型。 | 
| [IWififenceInterface](interface_i_wififence_interface.md) | interface<br/>导入Wi-Fi围栏模块的数据类型。 | 
| [WififenceRequest](_wififence_request.md) | struct<br/>定义添加Wi-Fi围栏的数据结构。 | 
| [WififenceSize](_wififence_size.md) | struct<br/>定义Wi-Fi围栏使用信息的数据结构。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [WififenceTransition](#wififencetransition)&nbsp;{&nbsp;WIFIFENCE_TRANSITION_ENTERED&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0)&nbsp;,&nbsp;WIFIFENCE_TRANSITION_EXITED&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1)&nbsp;} | 枚举Wi-Fi围栏状态事件。 | 
| [WififenceAlgoType](#wififencealgotype)&nbsp;{&nbsp;TYPE_ONE_BSSID&nbsp;=&nbsp;1&nbsp;,&nbsp;TYPE_FP_MATCH&nbsp;=&nbsp;2&nbsp;} | 枚举Wi-Fi围栏的匹配算法。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.location.lpfence.wififence.v1_0 | Wi-Fi围栏模块接口的包路径。 | 


## 枚举类型说明


### WififenceAlgoType

  
```
enum WififenceAlgoType
```

**描述:**

枚举Wi-Fi围栏的匹配算法。

  | 枚举值 | 描述 | 
| -------- | -------- |
| TYPE_ONE_BSSID | Wi-Fi围栏中MAC地址与设备扫描的MAC地址有交集时，即认为设备在围栏内。 | 
| TYPE_FP_MATCH | Wi-Fi围栏中MAC地址和RSSI值与设备扫描的MAC地址和RSSI值相似度达到一定阈值时，即认为设备在围栏内。 | 


### WififenceTransition

  
```
enum WififenceTransition
```

**描述:**

枚举Wi-Fi围栏状态事件。

  | 枚举值 | 描述 | 
| -------- | -------- |
| WIFIFENCE_TRANSITION_ENTERED | 设备在Wi-Fi围栏范围内。 | 
| WIFIFENCE_TRANSITION_EXITED | 设备在Wi-Fi围栏范围外。 | 
