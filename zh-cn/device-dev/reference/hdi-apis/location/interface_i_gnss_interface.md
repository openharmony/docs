# IGnssInterface


## 概述

声明GNSS模块提供的接口函数，包括启动GNSS芯片、启动导航、设置GNSS工作模式、注入参考信息、 删除辅助数据、注入PGNSS数据、获取GNSS缓存位置个数、获取所有缓存位置。

**起始版本：** 3.2

**相关模块：**[HdiGnss](_hdi_gnss.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetGnssConfigPara](#setgnssconfigpara) ([in] struct [GnssConfigPara](_gnss_config_para.md) para) | 设置GNSS配置参数。 | 
| [EnableGnss](#enablegnss) ([in] [IGnssCallback](interface_i_gnss_callback.md) callbackObj) | 使能GNSS功能，并设置回调函数。 | 
| [DisableGnss](#disablegnss) () | 去使能GNSS功能。 | 
| [StartGnss](#startgnss) ([in] enum GnssStartType type) | 启动导航功能。 | 
| [StopGnss](#stopgnss) ([in] enum GnssStartType type) | 停止导航功能。 | 
| [SetGnssReferenceInfo](#setgnssreferenceinfo) ([in] struct [GnssRefInfo](_gnss_ref_info.md) refInfo) | 注入GNSS参考信息。 | 
| [DeleteAuxiliaryData](#deleteauxiliarydata) ([in] enum GnssAuxiliaryData data) | 删除指定的辅助数据。 | 
| [SetPredictGnssData](#setpredictgnssdata) ([in] String data) | 注入PGNSS数据。 | 
| [GetCachedGnssLocationsSize](#getcachedgnsslocationssize) ([out] int size) | 获取GNSS缓存位置个数。 | 
| [GetCachedGnssLocations](#getcachedgnsslocations) () | 请求一次性获取GNSS缓存中的所有位置信息，并清空缓存buffer，缓存位置通过回调上报。 | 


## 成员函数说明


### DeleteAuxiliaryData()

```
IGnssInterface::DeleteAuxiliaryData ([in] enum GnssAuxiliaryData data)
```

**描述**


删除指定的辅助数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 表示辅助数据类型。详情参考[GnssAuxiliaryData](_hdi_gnss.md#gnssauxiliarydata)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### DisableGnss()

```
IGnssInterface::DisableGnss ()
```

**描述**


去使能GNSS功能。

**起始版本：** 3.2

**返回：**

返回0表示成功，返回负数表示失败。


### EnableGnss()

```
IGnssInterface::EnableGnss ([in] IGnssCallback callbackObj)
```

**描述**


使能GNSS功能，并设置回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 表示GNSS回调函数。GNSS驱动通过此回调函数上报定位结果和卫星状态信息等。 详情参考[IGnssCallback](interface_i_gnss_callback.md). | 

**返回：**

返回0表示成功，返回负数表示失败。


### GetCachedGnssLocations()

```
IGnssInterface::GetCachedGnssLocations ()
```

**描述**


请求一次性获取GNSS缓存中的所有位置信息，并清空缓存buffer，缓存位置通过回调上报。

**起始版本：** 3.2

**返回：**

返回0表示成功，返回负数表示失败。


### GetCachedGnssLocationsSize()

```
IGnssInterface::GetCachedGnssLocationsSize ([out] int size)
```

**描述**


获取GNSS缓存位置个数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| size | 表示GNSS缓存位置个数。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### SetGnssConfigPara()

```
IGnssInterface::SetGnssConfigPara ([in] struct GnssConfigPara para)
```

**描述**


设置GNSS配置参数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| para | 表示GNSS配置参数。包含基础的GNSS配置和GNSS缓存位置功能配置参数。详情参考[GnssConfigPara](_gnss_config_para.md)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### SetGnssReferenceInfo()

```
IGnssInterface::SetGnssReferenceInfo ([in] struct GnssRefInfo refInfo)
```

**描述**


注入GNSS参考信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| refInfo | 表示GNSS参考信息，包含参考时间和参考位置。详情参考[GnssRefInfo](_gnss_ref_info.md)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### SetPredictGnssData()

```
IGnssInterface::SetPredictGnssData ([in] String data)
```

**描述**


注入PGNSS数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 表示PGNSS数据。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### StartGnss()

```
IGnssInterface::StartGnss ([in] enum GnssStartType type)
```

**描述**


启动导航功能。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 表示GNSS启动类型，该参数是为了区分正常的GNSS定位功能和GNSS缓存功能。 详情参考[GnssStartType](_hdi_gnss.md#gnssstarttype)。 | 

**返回：**

返回0表示成功，返回负数表示失败。


### StopGnss()

```
IGnssInterface::StopGnss ([in] enum GnssStartType type)
```

**描述**


停止导航功能。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 表示GNSS启动类型，该参数为了区分正常的GNSS定位功能和GNSS缓存功能。 详情参考[GnssStartType](_hdi_gnss.md#gnssstarttype)。 | 

**返回：**

返回0表示成功，返回负数表示失败。
