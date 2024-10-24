# GnssTypes.idl


## 概述

定义GNSS模块接口中使用到的数据结构。

模块包路径：ohos.hdi.location.gnss.v1_0

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


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


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GnssWorkingMode](_hdi_gnss.md#gnssworkingmode) { GNSS_WORKING_MODE_STANDALONE = 1 , GNSS_WORKING_MODE_MS_BASED = 2 , GNSS_WORKING_MODE_MS_ASSISTED = 3 } | 定义GNSS工作模式。 | 
| [GnssStartType](_hdi_gnss.md#gnssstarttype) { GNSS_START_TYPE_NORMAL = 1 , GNSS_START_TYPE_GNSS_CACHE = 2 } | 定义GNSS启动方式。 | 
| [GnssRefInfoType](_hdi_gnss.md#gnssrefinfotype) { GNSS_REF_INFO_TIME = 1 , GNSS_REF_INFO_LOCATION = 2 , GNSS_REF_INFO_BEST_LOCATION = 3 } | 定义GNSS参考信息类型。 | 
| [GnssAuxiliaryData](_hdi_gnss.md#gnssauxiliarydata) {<br/>GNSS_AUXILIARY_DATA_EPHEMERIS = 1 , GNSS_AUXILIARY_DATA_ALMANAC = 2 , GNSS_AUXILIARY_DATA_POSITION = 4 , GNSS_AUXILIARY_DATA_TIME = 8 , GNSS_AUXILIARY_DATA_IONO = 16 , GNSS_AUXILIARY_DATA_UTC = 32 , GNSS_AUXILIARY_DATA_HEALTH = 64 , GNSS_AUXILIARY_DATA_SVDIR = 128 , GNSS_AUXILIARY_DATA_SVSTEER = 256 , GNSS_AUXILIARY_DATA_SADATA = 512 , GNSS_AUXILIARY_DATA_RTI = 1024 , GNSS_AUXILIARY_DATA_CELLDB_INFO = 32768 ,<br/>GNSS_AUXILIARY_DATA_ALL = 65535<br/>} | 定义辅助数据类型。 | 
| [GnssWorkingStatus](_hdi_gnss.md#gnssworkingstatus) {<br/>GNSS_STATUS_NONE = 0 , GNSS_STATUS_SESSION_BEGIN = 1 , GNSS_STATUS_SESSION_END = 2 , GNSS_STATUS_ENGINE_ON = 3 , GNSS_STATUS_ENGINE_OFF = 4<br/>} | 定义GNSS的工作状态。 | 
| [GnssCapabilities](_hdi_gnss.md#gnsscapabilities) {<br/>GNSS_CAP_SUPPORT_MSB = 1 , GNSS_CAP_SUPPORT_MSA = 2 , GNSS_CAP_SUPPORT_GEOFENCING = 4 , GNSS_CAP_SUPPORT_MEASUREMENTS = 8 , GNSS_CAP_SUPPORT_NAV_MESSAGES = 16 , GNSS_CAP_SUPPORT_GNSS_CACHE = 32<br/>} | 定义GNSS能力 | 
| [GnssConstellationType](_hdi_gnss.md#gnssconstellationtype) {<br/>GNSS_CONSTELLATION_UNKNOWN = 0 , GNSS_CONSTELLATION_GPS = 1 , GNSS_CONSTELLATION_SBAS = 2 , GNSS_CONSTELLATION_GLONASS = 3 , GNSS_CONSTELLATION_QZSS = 4 , GNSS_CONSTELLATION_BEIDOU = 5 , GNSS_CONSTELLATION_GALILEO = 6 , GNSS_CONSTELLATION_IRNSS = 7<br/>} | 定义星座类型 | 
| [SatellitesStatusFlag](_hdi_gnss.md#satellitesstatusflag) {<br/>SATELLITES_STATUS_NONE = 0 , SATELLITES_STATUS_HAS_EPHEMERIS_DATA = 1 , SATELLITES_STATUS_HAS_ALMANAC_DATA = 2 , SATELLITES_STATUS_USED_IN_FIX = 4 , SATELLITES_STATUS_HAS_CARRIER_FREQUENCY = 8<br/>} | 定义卫星状态中的附加信息。 | 
