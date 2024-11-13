# IGnssCallback


## 概述

声明获取定位结果回调、获取GNSS模块工作状态回调、获取nmea回调、获取GNSS能力回调、 获取卫星状态信息回调、批量获取缓存位置回调、请求上层注入参考信息回调、 请求上层注入PGNSS数据回调。

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ReportLocation](#reportlocation) ([in] struct [LocationInfo](_location_info.md) location) | 位置上报的回调函数。 | 
| [ReportGnssWorkingStatus](#reportgnssworkingstatus) ([in] enum GnssWorkingStatus status) | 上报GNSS工作状态的回调函数。 | 
| [ReportNmea](#reportnmea) ([in] long timestamp, [in] String nmea, [in] int length) | 上报NMEA数据的回调函数。 | 
| [ReportGnssCapabilities](#reportgnsscapabilities) ([in] enum GnssCapabilities capabilities) | 上报GNSS能力的回调函数。 | 
| [ReportSatelliteStatusInfo](#reportsatellitestatusinfo) ([in] struct [SatelliteStatusInfo](_satellite_status_info.md) info) | 上报卫星状态信息的回调函数。 | 
| [RequestGnssReferenceInfo](#requestgnssreferenceinfo) ([in] enum GnssRefInfoType type) | 请求上层注入GNSS参考信息。 | 
| [RequestPredictGnssData](#requestpredictgnssdata) () | 请求上层注入PGNSS数据。 | 
| [ReportCachedLocation](#reportcachedlocation) ([in] struct [LocationInfo](_location_info.md)[] gnssLocations) | 批量上报所有的缓存GNSS位置信息。 | 


## 成员函数说明


### ReportCachedLocation()

```
IGnssCallback::ReportCachedLocation ([in] struct LocationInfo[] gnssLocations)
```

**描述**


批量上报所有的缓存GNSS位置信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| gnssLocations | 表示GNSS芯片缓存的所有位置信息。详情参考[LocationInfo](_location_info.md)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### ReportGnssCapabilities()

```
IGnssCallback::ReportGnssCapabilities ([in] enum GnssCapabilities capabilities)
```

**描述**


上报GNSS能力的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capabilities | 表示GNSS的能力。详情参考[GnssCapabilities](_hdi_gnss.md#gnsscapabilities)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### ReportGnssWorkingStatus()

```
IGnssCallback::ReportGnssWorkingStatus ([in] enum GnssWorkingStatus status)
```

**描述**


上报GNSS工作状态的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 表示GNSS芯片的工作状态，详情参考[GnssWorkingStatus](_hdi_gnss.md#gnssworkingstatus)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### ReportLocation()

```
IGnssCallback::ReportLocation ([in] struct LocationInfo location)
```

**描述**


位置上报的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| location | 表示GNSS定位结果，详情参考[LocationInfo](_location_info.md)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### ReportNmea()

```
IGnssCallback::ReportNmea ([in] long timestamp, [in] String nmea, [in] int length )
```

**描述**


上报NMEA数据的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| timestamp | 表示NMEA上报的时刻。 | 
| nmea | 表示NMEA字符串。格式是NMEA 0183。 | 
| length | 表示NMEA字符串的长度。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### ReportSatelliteStatusInfo()

```
IGnssCallback::ReportSatelliteStatusInfo ([in] struct SatelliteStatusInfo info)
```

**描述**


上报卫星状态信息的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 表示卫星状态信息，详情参考[SatelliteStatusInfo](_satellite_status_info.md)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### RequestGnssReferenceInfo()

```
IGnssCallback::RequestGnssReferenceInfo ([in] enum GnssRefInfoType type)
```

**描述**


请求上层注入GNSS参考信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 表示GNSS参考信息类型，详情参考[GnssRefInfoType](_hdi_gnss.md#gnssrefinfotype)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### RequestPredictGnssData()

```
IGnssCallback::RequestPredictGnssData ()
```

**描述**


请求上层注入PGNSS数据。

**起始版本：** 3.2

**返回：**

返回0表示成功，返回负数表示失败。
