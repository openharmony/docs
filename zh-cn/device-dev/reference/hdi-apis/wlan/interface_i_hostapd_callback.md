# IHostapdCallback


## 概述

Hostapd回调的接口。

当Hostapd启动、热点扫描结束，收到Netlink消息时，调用该回调，继续后续处理。

**起始版本：** 4.1

**相关模块：**[Hostapd](_hostapd.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnEventStaJoin](#oneventstajoin) ([in] struct [HdiApCbParm](_hdi_ap_cb_parm.md) apCbParm, [in] String ifName) | Wi-Fi Hal回调STA加入AP。 | 
| [OnEventApState](#oneventapstate) ([in] struct [HdiApCbParm](_hdi_ap_cb_parm.md) apCbParm, [in] String ifName) | Wi-Fi Hal回调AP状态。 | 
| [OnEventHostApdNotify](#oneventhostapdnotify) ([in] String notifyParam, [in] String ifName) | 用于处理Hostapd回调参数。 | 


## 成员函数说明


### OnEventApState()

```
IHostapdCallback::OnEventApState ([in] struct HdiApCbParm apCbParm, [in] String ifName )
```

**描述**


Wi-Fi Hal回调AP状态。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| apStateParm | 表示AP状态内容。 | 
| ifName | 表示网卡名称。 | 


### OnEventHostApdNotify()

```
IHostapdCallback::OnEventHostApdNotify ([in] String notifyParam, [in] String ifName )
```

**描述**


用于处理Hostapd回调参数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| notifyParam | 表示Hostapd的参数。 | 
| ifName | 表示网卡名称。 | 


### OnEventStaJoin()

```
IHostapdCallback::OnEventStaJoin ([in] struct HdiApCbParm apCbParm, [in] String ifName )
```

**描述**


Wi-Fi Hal回调STA加入AP。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| staJoinParm | 表示STA加入内容。 | 
| ifName | 表示网卡名称。 | 
