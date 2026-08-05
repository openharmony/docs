# deviceinfo.h
<!--Kit: Basic Services Kit-->
<!--Subsystem: Startup-->
<!--Owner: @chenjinxiang3-->
<!--Designer: @chenjinxiang3-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @fang-jinxu-->

## 概述

声明用于查询终端设备信息的API。该模块提供了获取设备类型、制造商、品牌、型号、版本信息等设备基础信息的能力，适用于需要根据设备特性进行适配、统计设备信息或进行设备管理的场景。这些API通过读取系统属性获取设备信息，返回值为指向常量字符串的指针。该指针指向系统内部存储的数据，调用者无需释放内存。

**引用文件：** <deviceinfo.h>

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
| [const char *OH_GetMarketName(void)](#oh_getmarketname) | 获取外部产品系列，即外部产品名称。 |
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
| [const char *OH_GetDistributionOSName(void)](#oh_getdistributionosname) | 获取ISV发行版系统名称。独立软件供应商（ISV）可以使用自定义的系统名称。 |
| [const char *OH_GetDistributionOSVersion(void)](#oh_getdistributionosversion) | 获取ISV发行版系统版本号。 |
| [int OH_GetDistributionOSApiVersion(void)](#oh_getdistributionosapiversion) | 获取ISV发行版系统API版本。 |
| [const char *OH_GetDistributionOSReleaseType(void)](#oh_getdistributionosreleasetype) | 获取ISV发行版系统类型。 |

## 函数说明

### OH_GetDeviceType()

```c
const char *OH_GetDeviceType(void)
```

**描述**

获取设备类型。返回预定义的设备类型字符串。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 返回设备类型字符串。可能的值包括：<br>• "phone"<br>• "default"（设备类型无法识别时的默认返回值）<br>• "wearable"<br>• "liteWearable"<br>• "tablet"<br>• "tv"<br>• "car"<br>• "smartVision" |

### OH_GetManufacture()

```c
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

```c
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

```c
const char *OH_GetMarketName(void)
```

**描述**

获取外部产品系列，即外部产品名称。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的外部产品系列。 |

### OH_GetProductSeries()

```c
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

```c
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

```c
const char *OH_GetSoftwareModel(void)
```

**描述**

获取内部软件子型号，当多个硬件型号共用同一软件版本时，该字段用于区分不同的软件分支。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的内部软件子型号。 |

### OH_GetHardwareModel()

```c
const char *OH_GetHardwareModel(void)
```

**描述**

获取硬件版本号。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的硬件版本号。常见的取值包括："HL1CYBM"等。 |

### OH_GetBootloaderVersion()

```c
const char *OH_GetBootloaderVersion(void)
```

**描述**

获取Bootloader版本号。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的Bootloader版本号。常见的取值包括："bootloader"等。 |

### OH_GetAbiList()

```c
const char *OH_GetAbiList(void)
```

**描述**

获取应用二进制接口（Abi）。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的应用二进制接口（Abi）。返回支持的ABI列表，多个取值以英文逗号分隔。常见的取值包括："arm64-v8a"，"armeabi-v7a"等。 |

### OH_GetSecurityPatchTag()

```c
const char *OH_GetSecurityPatchTag(void)
```

**描述**

获取安全补丁级别。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的安全补丁级别。格式通常为"YYYY/MM/DD"，表示安全补丁的发布日期，例如"2023/10/05"。 |

### OH_GetDisplayVersion()

```c
const char *OH_GetDisplayVersion(void)
```

**描述**

获取产品版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 产品版本号，返回设备产品版本的字符串标识。 |

### OH_GetIncrementalVersion()

```c
const char *OH_GetIncrementalVersion(void)
```

**描述**

获取差异版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的差异版本。常见的取值包括："26.0.0.31"，"26.0.0.32"等。 |

### OH_GetOsReleaseType()

```c
const char *OH_GetOsReleaseType(void)
```

**描述**

获取系统的发布类型。返回预定义的发布类型字符串。

**起始版本：** 10

**返回：**

| 类型 | 说明                                                                                      |
| -- |-----------------------------------------------------------------------------------------|
| const char* | 操作系统发布类别包括"Release"、"Beta"和"Canary"。<br> 具体的发布类型可能是"release"，"Beta1"，或其他类似的。<br>-&nbsp;Canary：面向特定开发者发布的早期预览版本，不承诺API稳定性。<br>-&nbsp;Beta：面向开发者公开发布的Beta版本，不承诺API稳定性。<br>-&nbsp;Release：面向开发者公开发布的正式版本，承诺API稳定性。 |

### OH_GetOSFullName()

```c
const char *OH_GetOSFullName(void)
```

**描述**

获取完整的系统版本名。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的完整的系统版本名。版本格式 OpenHarmony-x.x.x.x。 |

### OH_GetSdkApiVersion()

```c
int OH_GetSdkApiVersion(void)
```

**描述**

获取系统软件API版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 系统软件API版本，取值范围为整数。常见的取值包括：26，6等。 |

### OH_GetFirstApiVersion()

```c
int OH_GetFirstApiVersion(void)
```

**描述**

获取首个版本系统软件API版本。指设备首次发布时所支持的系统软件API版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 首个版本系统软件API版本。指设备首次发布时所支持的系统软件API版本，取值范围为整数。 常见的取值包括：1等。|

### OH_GetVersionId()

```c
const char *OH_GetVersionId(void)
```

**描述**

获取版本ID。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的版本ID。默认值为：default。 |

### OH_GetBuildType()

```c
const char *OH_GetBuildType(void)
```

**描述**

获取系统的构建类型。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建类型。默认值为：default。 |

### OH_GetBuildUser()

```c
const char *OH_GetBuildUser(void)
```

**描述**

获取系统的构建用户。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建用户。默认值为：default。 |

### OH_GetBuildHost()

```c
const char *OH_GetBuildHost(void)
```

**描述**

获取系统的构建主机。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建主机。默认值为：default。 |

### OH_GetBuildTime()

```c
const char *OH_GetBuildTime(void)
```

**描述**

获取系统的构建时间。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建时间，表示系统版本构建的时间戳。常见的取值包括："1783430505910"等。 |

### OH_GetBuildRootHash()

```c
const char *OH_GetBuildRootHash(void)
```

**描述**

获取系统的构建版本Hash。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 字符串类型的系统的构建版本Hash。默认值为：default。 |

### OH_GetDistributionOSName()

```c
const char *OH_GetDistributionOSName(void)
```

**描述**

获取ISV发行版系统名称。独立软件供应商（ISV）可以使用自定义的系统名称。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | ISV发行版系统名称。<br> 如果没有指定ISV，它将返回一个空字符串。 |

### OH_GetDistributionOSVersion()

```c
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

```c
int OH_GetDistributionOSApiVersion(void)
```

**描述**

获取ISV发行版系统API版本。

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | ISV发行版系统API版本。<br> 如果没有指定ISV，它将返回与[OH_GetSdkApiVersion](#oh_getsdkapiversion)相同的值。 |

### OH_GetDistributionOSReleaseType()

```c
const char *OH_GetDistributionOSReleaseType(void)
```

**描述**

获取ISV发行版系统类型。

**起始版本：** 10

**返回：**

| 类型 | 说明                                                                              |
| -- |---------------------------------------------------------------------------------|
| const char* | ISV发行版系统类型。<br> 如果没有指定ISV，它将返回与[OH_GetOsReleaseType](#oh_getosreleasetype)相同的值。 |

