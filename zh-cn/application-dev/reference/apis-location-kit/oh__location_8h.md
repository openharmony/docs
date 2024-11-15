# oh_location.h


## 概述

定义查询位置开关状态、启动定位、停止定位的接口。

\@kit LocationKit

**库：** liblocation_ndk.so

**系统能力：** SystemCapability.Location.Location.Core

**起始版本：** 13

**相关模块：**[Location](_location.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Location_ResultCode](_location.md#location_resultcode)[OH_Location_IsLocatingEnabled](_location.md#oh_location_islocatingenabled) (bool \*enabled) | 查询位置开关是否开启。  | 
| [Location_ResultCode](_location.md#location_resultcode)[OH_Location_StartLocating](_location.md#oh_location_startlocating) (const [Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig) | 启动定位并订阅位置变化。  | 
| [Location_ResultCode](_location.md#location_resultcode)[OH_Location_StopLocating](_location.md#oh_location_stoplocating) (const [Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig) | 停止定位并取消订阅位置变化。  | 
