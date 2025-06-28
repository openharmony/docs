# DeviceInfo


## Overview

Provides APIs for querying device information.

**Since**: 10


## Summary


### File

| Name| Description|
| -------- | -------- |
| [deviceinfo.h](deviceinfo_8h.md) | Declares the APIs for querying device information.|


### Functions

| Name| Description|
| -------- | -------- |
| const char \* [OH_GetDeviceType](#oh_getdevicetype) (void) | Obtains the device type.|
| const char \* [OH_GetManufacture](#oh_getmanufacture) (void) | Obtains the device manufacturer.|
| const char \* [OH_GetBrand](#oh_getbrand) (void) | Obtains the device brand.|
| const char \* [OH_GetMarketName](#oh_getmarketname) (void) | Obtains the market name.|
| const char \* [OH_GetProductSeries](#oh_getproductseries) (void) | Obtains the product series.|
| const char \* [OH_GetProductModel](#oh_getproductmodel) (void) | Obtains the product model.|
| const char \* [OH_GetSoftwareModel](#oh_getsoftwaremodel) (void) | Obtains the software model.|
| const char \* [OH_GetHardwareModel](#oh_gethardwaremodel) (void) | Obtains the hardware model.|
| const char \* [OH_GetBootloaderVersion](#oh_getbootloaderversion) (void) | Obtains the Bootloader version.|
| const char \* [OH_GetAbiList](#oh_getabilist) (void) | Obtains the application binary interface (ABI) list.|
| const char \* [OH_GetSecurityPatchTag](#oh_getsecuritypatchtag) (void) | Obtains the security patch tag.|
| const char \* [OH_GetDisplayVersion](#oh_getdisplayversion) (void) | Obtains the display version.|
| const char \* [OH_GetIncrementalVersion](#oh_getincrementalversion) (void) | Obtains the incremental version.|
| const char \* [OH_GetOsReleaseType](#oh_getosreleasetype) (void) | Obtains the OS release type.|
| const char \* [OH_GetOSFullName](#oh_getosfullname) (void) | Obtains the OS full name.|
| int [OH_GetSdkApiVersion](#oh_getsdkapiversion) (void) | Obtains the SDK API version.|
| int [OH_GetFirstApiVersion](#oh_getfirstapiversion) (void) | Obtains the first API version.|
| const char \* [OH_GetVersionId](#oh_getversionid) (void) | Obtains the version ID.|
| const char \* [OH_GetBuildType](#oh_getbuildtype) (void) | Obtains the build type.|
| const char \* [OH_GetBuildUser](#oh_getbuilduser) (void) | Obtains the build user.|
| const char \* [OH_GetBuildHost](#oh_getbuildhost) (void) | Obtains the build host.|
| const char \* [OH_GetBuildTime](#oh_getbuildtime) (void) | Obtains the build time.|
| const char \* [OH_GetBuildRootHash](#oh_getbuildroothash) (void) | Obtains the build root hash.|
| const char \* [OH_GetDistributionOSName](#oh_getdistributionosname) (void) | Obtains the ISV distribution OS name. Independent software vendors (ISVs) can use their own OS names.|
| const char \* [OH_GetDistributionOSVersion](#oh_getdistributionosversion) (void) | Obtains the ISV distribution OS version.|
| int [OH_GetDistributionOSApiVersion](#oh_getdistributionosapiversion) (void) | Obtains the ISV distribution OS API version.|
| const char \* [OH_GetDistributionOSReleaseType](#oh_getdistributionosreleasetype) (void) | Obtains the ISV distribution OS release type.|


## Function Description


### OH_GetAbiList()

```
const char* OH_GetAbiList (void)
```

**Description**

Obtains the application binary interface (ABI) list.

**Since**: 10

**Returns**

Returns ABIs of the string type.


### OH_GetBootloaderVersion()

```
const char* OH_GetBootloaderVersion (void)
```

**Description**

Obtains the Bootloader version.

**Since**: 10

**Returns**

Returns a Bootloader version of the string type.


### OH_GetBrand()

```
const char* OH_GetBrand (void)
```

**Description**

Obtains the device brand.

**Since**: 10

**Returns**

Returns a device brand of the string type.


### OH_GetBuildHost()

```
const char* OH_GetBuildHost (void)
```

**Description**

Obtains the build host.

**Since**: 10

**Returns**

Returns a build host of the string type.


### OH_GetBuildRootHash()

```
const char* OH_GetBuildRootHash (void)
```

**Description**

Obtains the build root hash.

**Since**: 10

**Returns**

Returns build root hash of the string type.


### OH_GetBuildTime()

```
const char* OH_GetBuildTime (void)
```

**Description**

Obtains the build time.

**Since**: 10

**Returns**

Returns the build time of the string type.


### OH_GetBuildType()

```
const char* OH_GetBuildType (void)
```

**Description**

Obtains the build type.

**Since**: 10

**Returns**

Returns a build type of the string type.


### OH_GetBuildUser()

```
const char* OH_GetBuildUser (void)
```

**Description**

Obtains the build user.

**Since**: 10

**Returns**

Returns a build user of the string type.


### OH_GetDeviceType()

```
const char* OH_GetDeviceType (void)
```

**Description**

Obtains the device type.

**Since**: 10

**Returns**

Returns one of the following values:

**phone** (or **default**)

**wearable**

**liteWearable**

**tablet**

**tv**

**car**

**smartVision**


### OH_GetDisplayVersion()

```
const char* OH_GetDisplayVersion (void)
```

**Description**

Obtains the display version.

**Since**: 10

**Returns**

Returns display version of the string type.


### OH_GetDistributionOSApiVersion()

```
int OH_GetDistributionOSApiVersion (void)
```

**Description**

Obtains the ISV distribution OS API version.

**Since**: 10

**Returns**

Returns an API version of the ISV distribution OS. If no ISV is specified, the value of **OH_GetSdkApiVersion** is returned.


### OH_GetDistributionOSName()

```
const char* OH_GetDistributionOSName (void)
```

**Description**

Obtains the ISV distribution OS name. Independent software vendors (ISVs) can use their own OS names.

**Since**: 10

**Returns**

Returns an ISV distribution OS name. If no ISV is specified, an empty string is returned.


### OH_GetDistributionOSReleaseType()

```
const char* OH_GetDistributionOSReleaseType (void)
```

**Description**

Obtains the ISV distribution OS release type.

**Since**: 10

**Returns**

Returns an ISV distribution OS release type. If no ISV is specified, the value of **OH_GetOsReleaseType** is returned.


### OH_GetDistributionOSVersion()

```
const char* OH_GetDistributionOSVersion (void)
```

**Description**

Obtains the ISV distribution OS version.

**Since**: 10

**Returns**

Returns an ISV distribution OS version. If no ISV is specified, the value of **OH_GetOSFullName** is returned.


### OH_GetFirstApiVersion()

```
int OH_GetFirstApiVersion (void)
```

**Description**

Obtains the first API version.

**Since**: 10

**Returns**

Returns the first API version.


### OH_GetHardwareModel()

```
const char* OH_GetHardwareModel (void)
```

**Description**

Obtains the hardware model.

**Since**: 10

**Returns**

Returns a hardware model of the string type.


### OH_GetIncrementalVersion()

```
const char* OH_GetIncrementalVersion (void)
```

**Description**

Obtains the incremental version.

**Since**: 10

**Returns**

Returns an incremental version of the string type.


### OH_GetManufacture()

```
const char* OH_GetManufacture (void)
```

**Description**

Obtains the device manufacturer.

**Since**: 10

**Returns**

Returns a device manufacturer of the string type.


### OH_GetMarketName()

```
const char* OH_GetMarketName (void)
```

**Description**

Obtains the market name.

**Since**: 10

**Returns**

Returns a market name of the string type.


### OH_GetOSFullName()

```
const char* OH_GetOSFullName (void)
```

**Description**

Obtains the OS full name.

**Since**: 10

**Returns**

Returns an OS full name of the string type.


### OH_GetOsReleaseType()

```
const char* OH_GetOsReleaseType (void)
```

**Description**

Obtains the OS release type.

**Since**: 10

**Returns**

The OS release types include **release**, **Beta**, and **Canary**. A specific release type may be **release**, **Beta1**, or another similar type.


### OH_GetProductModel()

```
const char* OH_GetProductModel (void)
```

**Description**

Obtains the product model.

**Since**: 10

**Returns**

Returns a product model of the string type.


### OH_GetProductSeries()

```
const char* OH_GetProductSeries (void)
```

**Description**

Obtains the product series.

**Since**: 10

**Returns**

Returns the product series of the string type.


### OH_GetSdkApiVersion()

```
int OH_GetSdkApiVersion (void)
```

**Description**

Obtains the SDK API version.

**Since**: 10

**Returns**

Returns an SDK API version.


### OH_GetSecurityPatchTag()

```
const char* OH_GetSecurityPatchTag (void)
```

**Description**

Obtains the security patch tag.

**Since**: 10

**Returns**

Returns a security patch tag of the string type.


### OH_GetSoftwareModel()

```
const char* OH_GetSoftwareModel (void)
```

**Description**

Obtains the software model.

**Since**: 10

**Returns**

Returns a software model of the string type.


### OH_GetVersionId()

```
const char* OH_GetVersionId (void)
```

**Description**

Obtains the version ID.

**Since**: 10

**Returns**

Returns a version ID of the string type.
