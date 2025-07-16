# deviceinfo.h

## 概述

声明用于查询终端设备信息的API。

**库：** libdeviceinfo_ndk.z.so

**系统能力：** SystemCapability.Startup.SystemInfo

**起始版本：** 10

**相关模块：** [DeviceInfo](capi-deviceinfo.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [const char *OH_GetDeviceType(void)](#oh_getdevicetype) | 获取设备类型。 |
| [const char *OH_GetManufacture(void)](#oh_getmanufacture) | 获取设备制造商。 |
| [const char *OH_GetBrand(void)](#oh_getbrand) | 获取设备品牌。 |
| [const char *OH_GetMarketName(void)](#oh_getmarketname) | 获取外部产品系列。 |
| [const char *OH_GetProductSeries(void)](#oh_getproductseries) | 获取产品系列。 |
| [const char *OH_GetProductModel(void)](#oh_getproductmodel) | 获取认证型号。 |
| [const char *OH_GetSoftwareModel(void)](#oh_getsoftwaremodel) | 获取内部软件子型号。 |
| [const char *OH_GetHardwareModel(void)](#oh_gethardwaremodel) | 获取硬件版本号。 |
| [const char *OH_GetBootloaderVersion(void)](#oh_getbootloaderversion) | 获取Bootloader版本号。 |
| [const char *OH_GetAbiList(void)](#oh_getabilist) | 获取应用二进制接口（Abi）。 |
| [const char *OH_GetSecurityPatchTag(void)](#oh_getsecuritypatchtag) | 获取安全补丁级别。 |
| [const char *OH_GetDisplayVersion(void)](#oh_getdisplayversion) | 获取产品版本。 |
| [const char *OH_GetIncrementalVersion(void)](#oh_getincrementalversion) | 获取差异版本。 |
| [const char *OH_GetOsReleaseType(void)](#oh_getosreleasetype) | 获取系统的发布类型。 |
| [const char *OH_GetOSFullName(void)](#oh_getosfullname) | 获取完整的系统版本名。 |
| [int OH_GetSdkApiVersion(void)](#oh_getsdkapiversion) | 获取系统软件API版本。 |
| [int OH_GetFirstApiVersion(void)](#oh_getfirstapiversion) | 获取首个版本系统软件API版本。 |
| [const char *OH_GetVersionId(void)](#oh_getversionid) | 获取版本ID。 |
| [const char *OH_GetBuildType(void)](#oh_getbuildtype) | 获取系统的构建类型。 |
| [const char *OH_GetBuildUser(void)](#oh_getbuilduser) | 获取系统的构建用户。 |
| [const char *OH_GetBuildHost(void)](#oh_getbuildhost) | 获取系统的构建主机。 |
| [const char *OH_GetBuildTime(void)](#oh_getbuildtime) | 获取系统的构建时间。 |
| [const char *OH_GetBuildRootHash(void)](#oh_getbuildroothash) | 获取系统的构建版本Hash。 |
| [const char *OH_GetDistributionOSName(void)](#oh_getdistributionosname) | 获取ISV发行系统版本名称。独立软件供应商（ISV）可以使用自己定义的系统名称。 |
| [const char *OH_GetDistributionOSVersion(void)](#oh_getdistributionosversion) | 获取ISV发行版系统版本号。 |
| [int OH_GetDistributionOSApiVersion(void)](#oh_getdistributionosapiversion) | 获取ISV发行版系统api版本。 |
| [const char *OH_GetDistributionOSReleaseType(void)](#oh_getdistributionosreleasetype) | 获取ISV发行版系统类型。 |

## 函数说明

### OH_GetDeviceType()

```
const char *OH_GetDeviceType(void)
```

**描述**

获取设备类型。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char | "phone"(或"default")<br>         "wearable",<br>         "liteWearable",<br>         "tablet",<br>          "tv",<br>          "car",<br>          "smartVision"。 |

### OH_GetManufacture()

```
const char *OH_GetManufacture(void)
```

**描述**

获取设备制造商。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的设备制造商。 |

### OH_GetBrand()

```
const char *OH_GetBrand(void)
```

**描述**

获取设备品牌。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的设备品牌。 |

### OH_GetMarketName()

```
const char *OH_GetMarketName(void)
```

**描述**

获取外部产品系列。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的外部产品系列。 |

### OH_GetProductSeries()

```
const char *OH_GetProductSeries(void)
```

**描述**

获取产品系列。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的产品系列。 |

### OH_GetProductModel()

```
const char *OH_GetProductModel(void)
```

**描述**

获取认证型号。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的认证型号。 |

### OH_GetSoftwareModel()

```
const char *OH_GetSoftwareModel(void)
```

**描述**

获取内部软件子型号。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的内部软件子型号。 |

### OH_GetHardwareModel()

```
const char *OH_GetHardwareModel(void)
```

**描述**

获取硬件版本号。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的硬件版本号。 |

### OH_GetBootloaderVersion()

```
const char *OH_GetBootloaderVersion(void)
```

**描述**

获取Bootloader版本号。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的Bootloader版本号。 |

### OH_GetAbiList()

```
const char *OH_GetAbiList(void)
```

**描述**

获取应用二进制接口（Abi）。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的应用二进制接口（Abi）。 |

### OH_GetSecurityPatchTag()

```
const char *OH_GetSecurityPatchTag(void)
```

**描述**

获取安全补丁级别。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的安全补丁级别。 |

### OH_GetDisplayVersion()

```
const char *OH_GetDisplayVersion(void)
```

**描述**

获取产品版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的产品版本。 |

### OH_GetIncrementalVersion()

```
const char *OH_GetIncrementalVersion(void)
```

**描述**

获取差异版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的获取差异版本。 |

### OH_GetOsReleaseType()

```
const char *OH_GetOsReleaseType(void)
```

**描述**

获取系统的发布类型。

**起始版本：** 10

**返回：**

| 类型 | 说明                                                                                      |
| -- |-----------------------------------------------------------------------------------------|
| const char* | 操作系统发布类别包括"release"、"Beta"和"Canary"。<br> 具体的发布类型可能是"release"，"Beta1"，或其他类似的。 |

### OH_GetOSFullName()

```
const char *OH_GetOSFullName(void)
```

**描述**

获取完整的系统版本名。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的完整的系统版本名。 |

### OH_GetSdkApiVersion()

```
int OH_GetSdkApiVersion(void)
```

**描述**

获取系统软件API版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 系统软件API版本。 |

### OH_GetFirstApiVersion()

```
int OH_GetFirstApiVersion(void)
```

**描述**

获取首个版本系统软件API版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 首个版本系统软件API版本。 |

### OH_GetVersionId()

```
const char *OH_GetVersionId(void)
```

**描述**

获取版本ID。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的版本ID。 |

### OH_GetBuildType()

```
const char *OH_GetBuildType(void)
```

**描述**

获取系统的构建类型。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建类型。 |

### OH_GetBuildUser()

```
const char *OH_GetBuildUser(void)
```

**描述**

获取系统的构建用户。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建用户。 |

### OH_GetBuildHost()

```
const char *OH_GetBuildHost(void)
```

**描述**

获取系统的构建主机。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建主机。 |

### OH_GetBuildTime()

```
const char *OH_GetBuildTime(void)
```

**描述**

获取系统的构建时间。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建时间。 |

### OH_GetBuildRootHash()

```
const char *OH_GetBuildRootHash(void)
```

**描述**

获取系统的构建版本Hash。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建版本Hash。 |

### OH_GetDistributionOSName()

```
const char *OH_GetDistributionOSName(void)
```

**描述**

获取ISV发行系统版本名称。独立软件供应商（ISV）可以使用自己定义的系统名称。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | ISV发行系统版本名称。<br> 如果没有指定ISV，它将返回一个空字符串。 |

### OH_GetDistributionOSVersion()

```
const char *OH_GetDistributionOSVersion(void)
```

**描述**

获取ISV发行版系统版本号。

**起始版本：** 10

**返回：**

| 类型 | 说明                                                                         |
| -- |----------------------------------------------------------------------------|
| const char* | ISV发行版系统版本号。<br> 如果没有指定ISV，它将返回与[OH_GetOSFullName](#oh_getosfullname)相同的值。 |

### OH_GetDistributionOSApiVersion()

```
int OH_GetDistributionOSApiVersion(void)
```

**描述**

获取ISV发行版系统api版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | ISV发行版系统api版本。<br> 如果没有指定ISV，它将返回与[OH_GetOSFullName](#oh_getosfullname)相同的值。 |

### OH_GetDistributionOSReleaseType()

```
const char *OH_GetDistributionOSReleaseType(void)
```

**描述**

获取ISV发行版系统类型。

**起始版本：** 10

**返回：**

| 类型 | 说明                                                                              |
| -- |---------------------------------------------------------------------------------|
| const char | ISV发行版系统类型。<br> 如果没有指定ISV，它将返回与[OH_GetOsReleaseType](#oh_getosreleasetype)相同的值。 |


