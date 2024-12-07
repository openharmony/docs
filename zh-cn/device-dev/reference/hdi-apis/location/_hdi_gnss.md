# HdiGnss


## 概述

定义GNSS模块的接口。

上层GNSS服务可以获取一个GNSS驱动对象或代理，然后调用该对象或代理提供的api来访问GNSS设备， 从而实现启动GNSS芯片，启动导航，设置GNSS工作模式，注入参考信息，获取定位结果，获取nmea， 获取卫星状态信息，批量获取缓存位置信息等。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [GnssTypes.idl](_gnss_types_8idl.md) | 定义GNSS模块接口中使用到的数据结构。 | 
| [IGnssCallback.idl](_i_gnss_callback_8idl.md) | 声明获取定位结果回调、获取GNSS模块工作状态回调、获取nmea回调、获取GNSS能力回调、 获取卫星状态信息回调、批量获取缓存位置回调、请求上层注入参考信息回调、 请求上层注入PGNSS数据回调。 | 
| [IGnssInterface.idl](_i_gnss_interface_8idl.md) | 声明GNSS模块提供的接口函数，包括启动GNSS芯片、启动导航、设置GNSS工作模式、注入参考信息、 删除辅助数据、注入PGNSS数据、获取GNSS缓存位置个数、获取所有缓存位置。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[SatelliteStatusInfo](_satellite_status_info.md) | 定义卫星状态信息结构体。 | 
| struct&nbsp;&nbsp;[GnssBasicConfig](_gnss_basic_config.md) | 定义基础的GNSS配置参数。 | 
| struct&nbsp;&nbsp;[GnssCachingConfig](_gnss_caching_config.md) | 定义GNSS缓存功能的配置参数。 | 
| struct&nbsp;&nbsp;[GnssConfigPara](_gnss_config_para.md) | 定义GNSS配置参数结构体。 | 
| struct&nbsp;&nbsp;[GnssRefTime](_gnss_ref_time.md) | 定义GNSS参考时间结构体。 | 
| struct&nbsp;&nbsp;[GnssRefLocation](_gnss_ref_location.md) | 定义GNSS参考位置结构体。 | 
| struct&nbsp;&nbsp;[LocationInfo](_location_info.md) | 定义GNSS定位结果结构体。 | 
| struct&nbsp;&nbsp;[GnssRefInfo](_gnss_ref_info.md) | 定义GNSS参考信息结构体。 | 
| interface&nbsp;&nbsp;[IGnssCallback](interface_i_gnss_callback.md) | 声明获取定位结果回调、获取GNSS模块工作状态回调、获取nmea回调、获取GNSS能力回调、 获取卫星状态信息回调、批量获取缓存位置回调、请求上层注入参考信息回调、 请求上层注入PGNSS数据回调。 | 
| interface&nbsp;&nbsp;[IGnssInterface](interface_i_gnss_interface.md) | 声明GNSS模块提供的接口函数，包括启动GNSS芯片、启动导航、设置GNSS工作模式、注入参考信息、 删除辅助数据、注入PGNSS数据、获取GNSS缓存位置个数、获取所有缓存位置。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GnssWorkingMode](#gnssworkingmode) { GNSS_WORKING_MODE_STANDALONE = 1 , GNSS_WORKING_MODE_MS_BASED = 2 , GNSS_WORKING_MODE_MS_ASSISTED = 3 } | 定义GNSS工作模式。 | 
| [GnssStartType](#gnssstarttype) { GNSS_START_TYPE_NORMAL = 1 , GNSS_START_TYPE_GNSS_CACHE = 2 } | 定义GNSS启动方式。 | 
| [GnssRefInfoType](#gnssrefinfotype) { GNSS_REF_INFO_TIME = 1 , GNSS_REF_INFO_LOCATION = 2 , GNSS_REF_INFO_BEST_LOCATION = 3 } | 定义GNSS参考信息类型。 | 
| [GnssAuxiliaryData](#gnssauxiliarydata) {<br/>GNSS_AUXILIARY_DATA_EPHEMERIS = 1 , GNSS_AUXILIARY_DATA_ALMANAC = 2 , GNSS_AUXILIARY_DATA_POSITION = 4 , GNSS_AUXILIARY_DATA_TIME = 8 , GNSS_AUXILIARY_DATA_IONO = 16 , GNSS_AUXILIARY_DATA_UTC = 32 , GNSS_AUXILIARY_DATA_HEALTH = 64 , GNSS_AUXILIARY_DATA_SVDIR = 128 , GNSS_AUXILIARY_DATA_SVSTEER = 256 , GNSS_AUXILIARY_DATA_SADATA = 512 , GNSS_AUXILIARY_DATA_RTI = 1024 , GNSS_AUXILIARY_DATA_CELLDB_INFO = 32768 ,<br/>GNSS_AUXILIARY_DATA_ALL = 65535<br/>} | 定义辅助数据类型。 | 
| [GnssWorkingStatus](#gnssworkingstatus) {<br/>GNSS_STATUS_NONE = 0 , GNSS_STATUS_SESSION_BEGIN = 1 , GNSS_STATUS_SESSION_END = 2 , GNSS_STATUS_ENGINE_ON = 3 , GNSS_STATUS_ENGINE_OFF = 4<br/>} | 定义GNSS的工作状态。 | 
| [GnssCapabilities](#gnsscapabilities) {<br/>GNSS_CAP_SUPPORT_MSB = 1 , GNSS_CAP_SUPPORT_MSA = 2 , GNSS_CAP_SUPPORT_GEOFENCING = 4 , GNSS_CAP_SUPPORT_MEASUREMENTS = 8 , GNSS_CAP_SUPPORT_NAV_MESSAGES = 16 , GNSS_CAP_SUPPORT_GNSS_CACHE = 32<br/>} | 定义GNSS能力 | 
| [GnssConstellationType](#gnssconstellationtype) {<br/>GNSS_CONSTELLATION_UNKNOWN = 0 , GNSS_CONSTELLATION_GPS = 1 , GNSS_CONSTELLATION_SBAS = 2 , GNSS_CONSTELLATION_GLONASS = 3 , GNSS_CONSTELLATION_QZSS = 4 , GNSS_CONSTELLATION_BEIDOU = 5 , GNSS_CONSTELLATION_GALILEO = 6 , GNSS_CONSTELLATION_IRNSS = 7<br/>} | 定义星座类型 | 
| [SatellitesStatusFlag](#satellitesstatusflag) {<br/>SATELLITES_STATUS_NONE = 0 , SATELLITES_STATUS_HAS_EPHEMERIS_DATA = 1 , SATELLITES_STATUS_HAS_ALMANAC_DATA = 2 , SATELLITES_STATUS_USED_IN_FIX = 4 , SATELLITES_STATUS_HAS_CARRIER_FREQUENCY = 8<br/>} | 定义卫星状态中的附加信息。 | 


## 枚举类型说明


### GnssAuxiliaryData

```
enum GnssAuxiliaryData
```

**描述**


定义辅助数据类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GNSS_AUXILIARY_DATA_EPHEMERIS | 星历 | 
| GNSS_AUXILIARY_DATA_ALMANAC | 历书 | 
| GNSS_AUXILIARY_DATA_POSITION | 位置 | 
| GNSS_AUXILIARY_DATA_TIME | 时间 | 
| GNSS_AUXILIARY_DATA_IONO | 电离层 | 
| GNSS_AUXILIARY_DATA_UTC | UTC时间 | 
| GNSS_AUXILIARY_DATA_HEALTH | 健康度 | 
| GNSS_AUXILIARY_DATA_SVDIR | 方向 | 
| GNSS_AUXILIARY_DATA_SVSTEER | 方向角 | 
| GNSS_AUXILIARY_DATA_SADATA | 辅助数据 | 
| GNSS_AUXILIARY_DATA_RTI | 差分数据 | 
| GNSS_AUXILIARY_DATA_CELLDB_INFO | cell数据库 | 
| GNSS_AUXILIARY_DATA_ALL | 所有辅助数据 | 


### GnssCapabilities

```
enum GnssCapabilities
```

**描述**


定义GNSS能力

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GNSS_CAP_SUPPORT_MSB | 支持MS-Based模式 | 
| GNSS_CAP_SUPPORT_MSA | 支持MS-Assisted模式 | 
| GNSS_CAP_SUPPORT_GEOFENCING | 支持地理围栏功能 | 
| GNSS_CAP_SUPPORT_MEASUREMENTS | 支持GNSS测量信息上报 | 
| GNSS_CAP_SUPPORT_NAV_MESSAGES | 支持GNSS导航电文上报 | 
| GNSS_CAP_SUPPORT_GNSS_CACHE | 支持GNSS缓存位置功能 | 


### GnssConstellationType

```
enum GnssConstellationType
```

**描述**


定义星座类型

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GNSS_CONSTELLATION_UNKNOWN | 未知 | 
| GNSS_CONSTELLATION_GPS | GPS | 
| GNSS_CONSTELLATION_SBAS | SBAS | 
| GNSS_CONSTELLATION_GLONASS | GLONASS | 
| GNSS_CONSTELLATION_QZSS | QZSS | 
| GNSS_CONSTELLATION_BEIDOU | 北斗 | 
| GNSS_CONSTELLATION_GALILEO | GALILEO | 
| GNSS_CONSTELLATION_IRNSS | IRNSS | 


### GnssRefInfoType

```
enum GnssRefInfoType
```

**描述**


定义GNSS参考信息类型。

参考信息包含参考时间、参考位置等。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GNSS_REF_INFO_TIME | 参考时间 | 
| GNSS_REF_INFO_LOCATION | 参考位置 | 
| GNSS_REF_INFO_BEST_LOCATION | 参考融合位置 | 


### GnssStartType

```
enum GnssStartType
```

**描述**


定义GNSS启动方式。

定义GNSS启动类型的枚举值，用于区分普通GNSS定位和GNSS缓存上报功能 （不立刻上报底层位置，仅当上层请求全部上报或者底层FIFO满后才上报位置）。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GNSS_START_TYPE_NORMAL | 普通的GNSS功能 | 
| GNSS_START_TYPE_GNSS_CACHE | GNSS缓存位置功能 | 


### GnssWorkingMode

```
enum GnssWorkingMode
```

**描述**


定义GNSS工作模式。

定义GNSS工作模式的枚举值。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GNSS_WORKING_MODE_STANDALONE | GNSS独立模式（无辅助） | 
| GNSS_WORKING_MODE_MS_BASED | 在移动设备端进行定位计算的模式 | 
| GNSS_WORKING_MODE_MS_ASSISTED | 移动设备辅助模式，在网络侧完成定位计算 | 


### GnssWorkingStatus

```
enum GnssWorkingStatus
```

**描述**


定义GNSS的工作状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GNSS_STATUS_NONE | 未知状态 | 
| GNSS_STATUS_SESSION_BEGIN | 导航启动 | 
| GNSS_STATUS_SESSION_END | 导航停止 | 
| GNSS_STATUS_ENGINE_ON | 芯片上电 | 
| GNSS_STATUS_ENGINE_OFF | 芯片下电 | 


### SatellitesStatusFlag

```
enum SatellitesStatusFlag
```

**描述**


定义卫星状态中的附加信息。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| SATELLITES_STATUS_NONE | 默认值 | 
| SATELLITES_STATUS_HAS_EPHEMERIS_DATA | 有星历表数据 | 
| SATELLITES_STATUS_HAS_ALMANAC_DATA | 有历书数据 | 
| SATELLITES_STATUS_USED_IN_FIX | 定位中有使用到 | 
| SATELLITES_STATUS_HAS_CARRIER_FREQUENCY | 有载波频率 | 
