# GnssRefInfo


## 概述

定义GNSS参考信息结构体。

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum GnssRefInfoType [type](#type) | 参考信息类型 | 
| struct [GnssRefTime](_gnss_ref_time.md)[time](#time) | 参考时间 | 
| struct [GnssRefLocation](_gnss_ref_location.md)[location](#location) | 参考位置 | 
| struct [LocationInfo](_location_info.md)[best_location](#best_location) | 参考融合位置 | 


## 类成员变量说明


### best_location

```
struct LocationInfo GnssRefInfo::best_location
```

**描述**


参考融合位置


### location

```
struct GnssRefLocation GnssRefInfo::location
```

**描述**


参考位置


### time

```
struct GnssRefTime GnssRefInfo::time
```

**描述**


参考时间


### type

```
enum GnssRefInfoType GnssRefInfo::type
```

**描述**


参考信息类型
