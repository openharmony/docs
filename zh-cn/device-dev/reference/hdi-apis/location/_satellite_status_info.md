# SatelliteStatusInfo


## 概述

定义卫星状态信息结构体。

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [satellitesNumber](#satellitesnumber) | 卫星个数 | 
| short[] [satelliteIds](#satelliteids) | 卫星编号 | 
| enum GnssConstellationType[] [constellation](#constellation) | 星座类型 | 
| float[] [carrierToNoiseDensitys](#carriertonoisedensitys) | 信噪比 | 
| float[] [elevation](#elevation) | 卫星仰角 | 
| float[] [azimuths](#azimuths) | 方位角 | 
| float[] [carrierFrequencies](#carrierfrequencies) | 跟踪信号的载波频率 | 
| enum SatellitesStatusFlag [flags](#flags) | 卫星状态中的附加信息 | 


## 类成员变量说明


### flags

```
enum SatellitesStatusFlag SatelliteStatusInfo::flags
```

**描述**


卫星状态中的附加信息


### carrierFrequencies

float [] carrierFrequencies

**描述**


跟踪信号的载波频率


### azimuths

float [] azimuths

**描述**


方位角


### elevation

float [] elevation

**描述**


卫星仰角


### carrierToNoiseDensitys

float [] carrierToNoiseDensitys

**描述**


信噪比


### constellation

enum [GnssConstellationType](_hdi_gnss.md#gnssconstellationtype) [] constellation

**描述**


星座类型


### satelliteIds

```
short [] SatelliteStatusInfo::satelliteIds
```

**描述**


卫星编号


### satellitesNumber

```
unsigned int SatelliteStatusInfo::satellitesNumber
```

**描述**


卫星个数
