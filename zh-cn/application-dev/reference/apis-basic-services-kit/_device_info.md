# DeviceInfo


## 概述

提供查询终端设备信息的API。

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [deviceinfo.h](deviceinfo_8h.md) | 声明用于查询终端设备信息的API。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OH_GetDeviceType](#oh_getdevicetype) (void) | 获取设备类型。 | 
| const char \* [OH_GetManufacture](#oh_getmanufacture) (void) | 获取设备制造商。 | 
| const char \* [OH_GetBrand](#oh_getbrand) (void) | 获取设备品牌。 | 
| const char \* [OH_GetMarketName](#oh_getmarketname) (void) | 获取外部产品系列。 | 
| const char \* [OH_GetProductSeries](#oh_getproductseries) (void) | 获取产品系列。 | 
| const char \* [OH_GetProductModel](#oh_getproductmodel) (void) | 获取认证型号。 | 
| const char \* [OH_GetSoftwareModel](#oh_getsoftwaremodel) (void) | 获取内部软件子型号。 | 
| const char \* [OH_GetHardwareModel](#oh_gethardwaremodel) (void) | 获取硬件版本号。 | 
| const char \* [OH_GetBootloaderVersion](#oh_getbootloaderversion) (void) | 获取Bootloader版本号。 | 
| const char \* [OH_GetAbiList](#oh_getabilist) (void) | 获取应用二进制接口（Abi）。 | 
| const char \* [OH_GetSecurityPatchTag](#oh_getsecuritypatchtag) (void) | 获取安全补丁级别。 | 
| const char \* [OH_GetDisplayVersion](#oh_getdisplayversion) (void) | 获取产品版本。 | 
| const char \* [OH_GetIncrementalVersion](#oh_getincrementalversion) (void) | 获取差异版本。 | 
| const char \* [OH_GetOsReleaseType](#oh_getosreleasetype) (void) | 获取系统的发布类型。 | 
| const char \* [OH_GetOSFullName](#oh_getosfullname) (void) | 获取完整的系统版本名。 | 
| int [OH_GetSdkApiVersion](#oh_getsdkapiversion) (void) | 获取系统软件API版本。 | 
| int [OH_GetFirstApiVersion](#oh_getfirstapiversion) (void) | 获取首个版本系统软件API版本。 | 
| const char \* [OH_GetVersionId](#oh_getversionid) (void) | 获取版本ID。 | 
| const char \* [OH_GetBuildType](#oh_getbuildtype) (void) | 获取系统的构建类型。 | 
| const char \* [OH_GetBuildUser](#oh_getbuilduser) (void) | 获取系统的构建用户。 | 
| const char \* [OH_GetBuildHost](#oh_getbuildhost) (void) | 获取系统的构建主机。 | 
| const char \* [OH_GetBuildTime](#oh_getbuildtime) (void) | 获取系统的构建时间。 | 
| const char \* [OH_GetBuildRootHash](#oh_getbuildroothash) (void) | 获取系统的构建版本Hash。 | 
| const char \* [OH_GetDistributionOSName](#oh_getdistributionosname) (void) | 获取ISV发行系统版本名称。 独立软件供应商（ISV）可以使用自己定义的系统名称。 | 
| const char \* [OH_GetDistributionOSVersion](#oh_getdistributionosversion) (void) | 获取ISV发行版系统版本号。 | 
| int [OH_GetDistributionOSApiVersion](#oh_getdistributionosapiversion) (void) | 获取ISV发行版系统api版本。 | 
| const char \* [OH_GetDistributionOSReleaseType](#oh_getdistributionosreleasetype) (void) | 获取ISV发行版系统类型。 | 


## 函数说明


### OH_GetAbiList()

```
const char* OH_GetAbiList (void)
```

**描述**

获取应用二进制接口（Abi）。

**起始版本：** 10

**返回：**

字符串类型的应用二进制接口（Abi）。


### OH_GetBootloaderVersion()

```
const char* OH_GetBootloaderVersion (void)
```

**描述**

获取Bootloader版本号。

**起始版本：** 10

**返回：**

字符串类型的Bootloader版本号。


### OH_GetBrand()

```
const char* OH_GetBrand (void)
```

**描述**

获取设备品牌。

**起始版本：** 10

**返回：**

字符串类型的设备品牌。


### OH_GetBuildHost()

```
const char* OH_GetBuildHost (void)
```

**描述**

获取系统的构建主机。

**起始版本：** 10

**返回：**

字符串类型的系统的构建主机。


### OH_GetBuildRootHash()

```
const char* OH_GetBuildRootHash (void)
```

**描述**

获取系统的构建版本Hash。

**起始版本：** 10

**返回：**

字符串类型的系统的构建版本Hash。


### OH_GetBuildTime()

```
const char* OH_GetBuildTime (void)
```

**描述**

获取系统的构建时间。

**起始版本：** 10

**返回：**

字符串类型的系统的构建时间。


### OH_GetBuildType()

```
const char* OH_GetBuildType (void)
```

**描述**

获取系统的构建类型。

**起始版本：** 10

**返回：**

字符串类型的系统的构建类型。


### OH_GetBuildUser()

```
const char* OH_GetBuildUser (void)
```

**描述**

获取系统的构建用户。

**起始版本：** 10

**返回：**

字符串类型的系统的构建用户。


### OH_GetDeviceType()

```
const char* OH_GetDeviceType (void)
```

**描述**

获取设备类型。

**起始版本：** 10

**返回：**

phone(或default)

wearable

liteWearable

tablet

tv

car

smartVision


### OH_GetDisplayVersion()

```
const char* OH_GetDisplayVersion (void)
```

**描述**

获取产品版本。

**起始版本：** 10

**返回：**

字符串类型的产品版本。


### OH_GetDistributionOSApiVersion()

```
int OH_GetDistributionOSApiVersion (void)
```

**描述**

获取ISV发行版系统api版本。

**起始版本：** 10

**返回：**

ISV发行版系统api版本。如果没有指定ISV，它将返回与OH_GetSdkApiVersion相同的值。


### OH_GetDistributionOSName()

```
const char* OH_GetDistributionOSName (void)
```

**描述**

获取ISV发行系统版本名称。 独立软件供应商（ISV）可以使用自己定义的系统名称。

**起始版本：** 10

**返回：**

ISV发行系统版本名称。 如果没有指定ISV，它将返回一个空字符串。


### OH_GetDistributionOSReleaseType()

```
const char* OH_GetDistributionOSReleaseType (void)
```

**描述**

获取ISV发行版系统类型。

**起始版本：** 10

**返回：**

ISV发行版系统类型。 如果没有指定ISV，它将返回与OH_GetOsReleaseType相同的值。


### OH_GetDistributionOSVersion()

```
const char* OH_GetDistributionOSVersion (void)
```

**描述**

获取ISV发行版系统版本号。

**起始版本：** 10

**返回：**

ISV发行版系统版本号。如果没有指定ISV，它将返回与OH_GetOSFullName相同的值。


### OH_GetFirstApiVersion()

```
int OH_GetFirstApiVersion (void)
```

**描述**

获取首个版本系统软件API版本。

**起始版本：** 10

**返回：**

首个版本系统软件API版本。


### OH_GetHardwareModel()

```
const char* OH_GetHardwareModel (void)
```

**描述**

获取硬件版本号。

**起始版本：** 10

**返回：**

字符串类型的硬件版本号。


### OH_GetIncrementalVersion()

```
const char* OH_GetIncrementalVersion (void)
```

**描述**

获取差异版本。

**起始版本：** 10

**返回：**

字符串类型的获取差异版本。


### OH_GetManufacture()

```
const char* OH_GetManufacture (void)
```

**描述**

获取设备制造商。

**起始版本：** 10

**返回：**

字符串类型的设备制造商。


### OH_GetMarketName()

```
const char* OH_GetMarketName (void)
```

**描述**

获取外部产品系列。

**起始版本：** 10

**返回：**

字符串类型的外部产品系列。


### OH_GetOSFullName()

```
const char* OH_GetOSFullName (void)
```

**描述**

获取完整的系统版本名。

**起始版本：** 10

**返回：**

字符串类型的完整的系统版本名。


### OH_GetOsReleaseType()

```
const char* OH_GetOsReleaseType (void)
```

**描述**

获取系统的发布类型。

**起始版本：** 10

**返回：**

操作系统发布类别包括release、Beta和Canary。具体的发布类型可能是release、Beta1，或其他类似的。


### OH_GetProductModel()

```
const char* OH_GetProductModel (void)
```

**描述**

获取认证型号。

**起始版本：** 10

**返回：**

字符串类型的认证型号。


### OH_GetProductSeries()

```
const char* OH_GetProductSeries (void)
```

**描述**

获取产品系列。

**起始版本：** 10

**返回：**

字符串类型的产品系列。


### OH_GetSdkApiVersion()

```
int OH_GetSdkApiVersion (void)
```

**描述**

获取系统软件API版本。

**起始版本：** 10

**返回：**

系统软件API版本。


### OH_GetSecurityPatchTag()

```
const char* OH_GetSecurityPatchTag (void)
```

**描述**

获取安全补丁级别。

**起始版本：** 10

**返回：**

字符串类型的安全补丁级别。


### OH_GetSoftwareModel()

```
const char* OH_GetSoftwareModel (void)
```

**描述**

获取内部软件子型号。

**起始版本：** 10

**返回：**

字符串类型的内部软件子型号。


### OH_GetVersionId()

```
const char* OH_GetVersionId (void)
```

**描述**

获取版本ID。

**起始版本：** 10

**返回：**

字符串类型的版本ID。
