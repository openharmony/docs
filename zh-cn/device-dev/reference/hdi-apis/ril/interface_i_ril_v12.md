# IRil


## 概述

Ril模块的请求接口。

请求接口包括打电话、发短信彩信、激活SIM卡、上网等。

**起始版本：** 4.1

**相关模块：**[Ril](_ril_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetCallback1_2](#setcallback1_2) ([in] [IRilCallback](interface_i_ril_callback_v12.md) rilCallback) | 设置IRil回调接口，回调函数参考[IRilCallback](interface_i_ril_callback_v12.md)。  | 
| [SendSimMatchedOperatorInfo](#sendsimmatchedoperatorinfo) ([in] int slotId, [in] int serialId, [in] struct [NcfgOperatorInfo](_ncfg_operator_info_v12.md) ncfgOperatorInfo) | 下发随卡信息接口。  | 
| [CleanAllConnections](#cleanallconnections) ([in] int slotId, [in] int serialId) | 清除所有数据连接。  | 


## 成员函数说明


### CleanAllConnections()

```
IRil::CleanAllConnections ([in] int slotId, [in] int serialId )
```
**描述**

清除所有数据连接。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendSimMatchedOperatorInfo()

```
IRil::SendSimMatchedOperatorInfo ([in] int slotId, [in] int serialId, [in] struct NcfgOperatorInfo ncfgOperatorInfo )
```
**描述**

下发随卡信息接口。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| ncfgOperatorInfo | 要下发的随卡信息，参考[NcfgOperatorInfo](_ncfg_operator_info_v12.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetCallback1_2()

```
IRil::SetCallback1_2 ([in] IRilCallback rilCallback)
```
**描述**

设置IRil回调接口，回调函数参考[IRilCallback](interface_i_ril_callback_v12.md)。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rilCallback | 要设置的回调函数。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。
