# IAGnssInterface


## 概述

定义AGNSS接口，用于设置AGNSS回调、AGNSS服务器地址、AGNSS参考信息和SetId。

**起始版本：** 3.2

**相关模块：**[HdiAGnss](_hdi_a_gnss.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetAgnssCallback](#setagnsscallback) ([in] [IAGnssCallback](interface_i_a_gnss_callback.md) callbackObj) | 设置回调函数。  | 
| [SetAgnssServer](#setagnssserver) ([in] struct [AGnssServerInfo](_a_gnss_server_info.md) server) | 设置AGNSS服务器信息。  | 
| [SetAgnssRefInfo](#setagnssrefinfo) ([in] struct [AGnssRefInfo](_a_gnss_ref_info.md) refInfo) | 注入参考信息。  | 
| [SetSubscriberSetId](#setsubscribersetid) ([in] struct [SubscriberSetId](_subscriber_set_id.md) id) | 设置SetId。  | 


## 成员函数说明


### SetAgnssCallback()

```
IAGnssInterface::SetAgnssCallback ([in] IAGnssCallback callbackObj)
```
**描述**

设置回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 表示上层传入的回调函数，包含请求上层建立或释放数据业务连接，请求上层下发SetId， 请求上层下发AGNSS参考信息等回调，详情参考[IAGnssCallback](interface_i_a_gnss_callback.md)。  | 

**返回：**

返回0表示成功，返回负数表示失败。


### SetAgnssRefInfo()

```
IAGnssInterface::SetAgnssRefInfo ([in] struct AGnssRefInfo refInfo)
```
**描述**

注入参考信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| refInfo | 表示AGNSS参考信息。详情参考[AGnssRefInfo](_a_gnss_ref_info.md)。  | 

**返回：**

返回0表示成功，返回负数表示失败。


### SetAgnssServer()

```
IAGnssInterface::SetAgnssServer ([in] struct AGnssServerInfo server)
```
**描述**

设置AGNSS服务器信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| server | 表示AGNSS服务器信息。详情参考[AGnssServerInfo](_a_gnss_server_info.md)。  | 

**返回：**

返回0表示成功，返回负数表示失败。


### SetSubscriberSetId()

```
IAGnssInterface::SetSubscriberSetId ([in] struct SubscriberSetId id)
```
**描述**

设置setId。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 表示SetId，详情参考[SubscriberSetId](_subscriber_set_id.md)。  | 

**返回：**

返回0表示成功，返回负数表示失败。
