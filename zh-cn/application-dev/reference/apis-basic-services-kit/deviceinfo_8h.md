# deviceinfo.h


## 概述

声明用于查询终端设备信息的API。

\@kit BasicServicesKit

**库：** libdeviceinfo_ndk.z.so

**系统能力：** SystemCapability.Startup.SystemInfo

**起始版本：** 10

**相关模块：**[DeviceInfo](_device_info.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OH_GetDeviceType](_device_info.md#oh_getdevicetype) (void) | 获取设备类型。 | 
| const char \* [OH_GetManufacture](_device_info.md#oh_getmanufacture) (void) | 获取设备制造商。 | 
| const char \* [OH_GetBrand](_device_info.md#oh_getbrand) (void) | 获取设备品牌。 | 
| const char \* [OH_GetMarketName](_device_info.md#oh_getmarketname) (void) | 获取外部产品系列。 | 
| const char \* [OH_GetProductSeries](_device_info.md#oh_getproductseries) (void) | 获取产品系列。 | 
| const char \* [OH_GetProductModel](_device_info.md#oh_getproductmodel) (void) | 获取认证型号。 | 
| const char \* [OH_GetSoftwareModel](_device_info.md#oh_getsoftwaremodel) (void) | 获取内部软件子型号。 | 
| const char \* [OH_GetHardwareModel](_device_info.md#oh_gethardwaremodel) (void) | 获取硬件版本号。 | 
| const char \* [OH_GetBootloaderVersion](_device_info.md#oh_getbootloaderversion) (void) | 获取Bootloader版本号。 | 
| const char \* [OH_GetAbiList](_device_info.md#oh_getabilist) (void) | 获取应用二进制接口（Abi）。 | 
| const char \* [OH_GetSecurityPatchTag](_device_info.md#oh_getsecuritypatchtag) (void) | 获取安全补丁级别。 | 
| const char \* [OH_GetDisplayVersion](_device_info.md#oh_getdisplayversion) (void) | 获取产品版本。 | 
| const char \* [OH_GetIncrementalVersion](_device_info.md#oh_getincrementalversion) (void) | 获取差异版本。 | 
| const char \* [OH_GetOsReleaseType](_device_info.md#oh_getosreleasetype) (void) | 获取系统的发布类型。 | 
| const char \* [OH_GetOSFullName](_device_info.md#oh_getosfullname) (void) | 获取完整的系统版本名。 | 
| int [OH_GetSdkApiVersion](_device_info.md#oh_getsdkapiversion) (void) | 获取系统软件API版本。 | 
| int [OH_GetFirstApiVersion](_device_info.md#oh_getfirstapiversion) (void) | 获取首个版本系统软件API版本。 | 
| const char \* [OH_GetVersionId](_device_info.md#oh_getversionid) (void) | 获取版本ID。 | 
| const char \* [OH_GetBuildType](_device_info.md#oh_getbuildtype) (void) | 获取系统的构建类型。 | 
| const char \* [OH_GetBuildUser](_device_info.md#oh_getbuilduser) (void) | 获取系统的构建用户。 | 
| const char \* [OH_GetBuildHost](_device_info.md#oh_getbuildhost) (void) | 获取系统的构建主机。 | 
| const char \* [OH_GetBuildTime](_device_info.md#oh_getbuildtime) (void) | 获取系统的构建时间。 | 
| const char \* [OH_GetBuildRootHash](_device_info.md#oh_getbuildroothash) (void) | 获取系统的构建版本Hash。 | 
| const char \* [OH_GetDistributionOSName](_device_info.md#oh_getdistributionosname) (void) | 获取ISV发行系统版本名称。独立软件供应商（ISV）可以使用自己定义的系统名称。 | 
| const char \* [OH_GetDistributionOSVersion](_device_info.md#oh_getdistributionosversion) (void) | 获取ISV发行版系统版本号。 | 
| int [OH_GetDistributionOSApiVersion](_device_info.md#oh_getdistributionosapiversion) (void) | 获取ISV发行版系统api版本。 | 
| const char \* [OH_GetDistributionOSReleaseType](_device_info.md#oh_getdistributionosreleasetype) (void) | 获取ISV发行版系统类型。 | 
