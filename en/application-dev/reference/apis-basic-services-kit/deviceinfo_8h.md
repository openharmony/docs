# deviceinfo.h


## Overview

Declares the APIs for querying device information.

\@kit BasicServicesKit

**Library**: libdeviceinfo_ndk.z.so

**System capability**: SystemCapability.Startup.SystemInfo

**Since**: 10

**Related module**: [DeviceInfo](_device_info.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| const char \* [OH_GetDeviceType](_device_info.md#oh_getdevicetype) (void) | Obtains the device type.|
| const char \* [OH_GetManufacture](_device_info.md#oh_getmanufacture) (void) | Obtains the device manufacturer.|
| const char \* [OH_GetBrand](_device_info.md#oh_getbrand) (void) | Obtains the device brand.|
| const char \* [OH_GetMarketName](_device_info.md#oh_getmarketname) (void) | Obtains the market name.|
| const char \* [OH_GetProductSeries](_device_info.md#oh_getproductseries) (void) | Obtains the product series.|
| const char \* [OH_GetProductModel](_device_info.md#oh_getproductmodel) (void) | Obtains the product model.|
| const char \* [OH_GetSoftwareModel](_device_info.md#oh_getsoftwaremodel) (void) | Obtains the software model.|
| const char \* [OH_GetHardwareModel](_device_info.md#oh_gethardwaremodel) (void) | Obtains the hardware model.|
| const char \* [OH_GetBootloaderVersion](_device_info.md#oh_getbootloaderversion) (void) | Obtains the Bootloader version.|
| const char \* [OH_GetAbiList](_device_info.md#oh_getabilist) (void) | Obtains the application binary interface (ABI) list. |
| const char \* [OH_GetSecurityPatchTag](_device_info.md#oh_getsecuritypatchtag) (void) | Obtains the security patch tag.|
| const char \* [OH_GetDisplayVersion](_device_info.md#oh_getdisplayversion) (void) | Obtains the display version.|
| const char \* [OH_GetIncrementalVersion](_device_info.md#oh_getincrementalversion) (void) | Obtains the incremental version.|
| const char \* [OH_GetOsReleaseType](_device_info.md#oh_getosreleasetype) (void) | Obtains the OS release type.|
| const char \* [OH_GetOSFullName](_device_info.md#oh_getosfullname) (void) | Obtains the OS full name.|
| int [OH_GetSdkApiVersion](_device_info.md#oh_getsdkapiversion) (void) | Obtains the SDK API version.|
| int [OH_GetFirstApiVersion](_device_info.md#oh_getfirstapiversion) (void) | Obtains the first API version.|
| const char \* [OH_GetVersionId](_device_info.md#oh_getversionid) (void) | Obtains the version ID.|
| const char \* [OH_GetBuildType](_device_info.md#oh_getbuildtype) (void) | Obtains the build type.|
| const char \* [OH_GetBuildUser](_device_info.md#oh_getbuilduser) (void) | Obtains the build user. |
| const char \* [OH_GetBuildHost](_device_info.md#oh_getbuildhost) (void) | Obtains the build host. |
| const char \* [OH_GetBuildTime](_device_info.md#oh_getbuildtime) (void) | Obtains the build time.|
| const char \* [OH_GetBuildRootHash](_device_info.md#oh_getbuildroothash) (void) | Obtains the build root hash.|
| const char \* [OH_GetDistributionOSName](_device_info.md#oh_getdistributionosname) (void) | Obtains the ISV distribution OS name. Independent software vendors (ISVs) can use their own OS names.|
| const char \* [OH_GetDistributionOSVersion](_device_info.md#oh_getdistributionosversion) (void) | Obtains the ISV distribution OS version.|
| int [OH_GetDistributionOSApiVersion](_device_info.md#oh_getdistributionosapiversion) (void) | Obtains the ISV distribution OS API version. |
| const char \* [OH_GetDistributionOSReleaseType](_device_info.md#oh_getdistributionosreleasetype) (void) | Obtains the ISV distribution OS release type.|
