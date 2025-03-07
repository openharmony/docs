# IRilCallback


## 概述

Ril模块的回调接口。

回调接口提供打电话、发短彩信、激活SIM卡、上网等回调函数，回调函数由调用者实现。

**起始版本：** 4.1

**相关模块：**[Ril](_ril_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ResidentNetworkUpdated](#residentnetworkupdated) ([in] struct RilRadioResponseInfo responseInfo, [in] String plmn) | 常驻网络上报。 | 
| [SendSimMatchedOperatorInfoResponse](#sendsimmatchedoperatorinforesponse) ([in] struct RilRadioResponseInfo responseInfo) | 下发随卡信息响应。 | 
| [CleanAllConnectionsResponse](#cleanallconnectionsresponse) ([in] struct RilRadioResponseInfo responseInfo) | 清除所有数据连接响应。 | 


## 成员函数说明


### CleanAllConnectionsResponse()

```
IRilCallback::CleanAllConnectionsResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


清除所有数据连接响应。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### ResidentNetworkUpdated()

```
IRilCallback::ResidentNetworkUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] String plmn )
```

**描述**


常驻网络上报。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| plmn | 表示常驻网络 | 


### SendSimMatchedOperatorInfoResponse()

```
IRilCallback::SendSimMatchedOperatorInfoResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


下发随卡信息响应。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
