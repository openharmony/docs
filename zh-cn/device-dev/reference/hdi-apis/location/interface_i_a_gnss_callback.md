# IAGnssCallback


## 概述

定义AGNSS回调，用于请求上层建立或释放数据业务连接、请求上层下发setId、请求上层下发AGNSS参考信息。

**起始版本：** 3.2

**相关模块：**[HdiAGnss](_hdi_a_gnss.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RequestSetUpAgnssDataLink](#requestsetupagnssdatalink) ([in] struct [AGnssDataLinkRequest](_a_gnss_data_link_request.md) request) | 该接口用于请求上层建立或者释放数据业务连接。 | 
| [RequestSubscriberSetId](#requestsubscribersetid) ([in] enum SubscriberSetIdType type) | 请求上层注入setId。 | 
| [RequestAgnssRefInfo](#requestagnssrefinfo) () | 请求上层注入AGNSS参考信息。 | 


## 成员函数说明


### RequestAgnssRefInfo()

```
IAGnssCallback::RequestAgnssRefInfo ()
```

**描述**


请求上层注入AGNSS参考信息。

**起始版本：** 3.2

**返回：**

返回0表示成功，返回负数表示失败。


### RequestSetUpAgnssDataLink()

```
IAGnssCallback::RequestSetUpAgnssDataLink ([in] struct AGnssDataLinkRequest request)
```

**描述**


该接口用于请求上层建立或者释放数据业务连接。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| request | 表示请求参数信息，详情参考[AGnssDataLinkRequest](_a_gnss_data_link_request.md)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### RequestSubscriberSetId()

```
IAGnssCallback::RequestSubscriberSetId ([in] enum SubscriberSetIdType type)
```

**描述**


请求上层注入setId。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 表示setId类型，详情参考[SubscriberSetIdType](_hdi_a_gnss.md#subscribersetidtype)。 | 

**返回：**

返回0表示成功，返回负数表示失败。
