# @ohos.deviceInfo (Device Information)

The **deviceInfo** module provides product information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import deviceInfo from '@ohos.deviceInfo'
```

## Attributes

**System capability**: SystemCapability.Startup.SystemInfo

 

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceType | string | Yes| No| Device type.|
| manufacture | string | Yes| No| Device manufacturer.|
| brand | string | Yes| No| Device brand.|
| marketName | string | Yes| No| Marketing name.|
| productSeries | string | Yes| No| Product series.|
| productModel | string | Yes| No| Product model.|
| softwareModel | string | Yes| No| Software model.|
| hardwareModel | string | Yes| No| Hardware model.|
| hardwareProfile | string | Yes| No| Hardware profile.|
| serial | string | Yes| No| Device serial number.<br>**Required permissions**: ohos.permission.sec.ACCESS_UDID|
| bootloaderVersion | string | Yes| No| Bootloader version.|
| abiList | string | Yes| No| Application binary interface (Abi) list.|
| securityPatchTag | string | Yes| No| Security patch tag.|
| displayVersion | string | Yes| No| Product version.|
| incrementalVersion | string | Yes| No| Incremental version.|
| osReleaseType | string | Yes| No| OS release type. The options are as follows:<br>- **Canary**: Preliminary release open only to specific developers. This release does not promise API stability and may require tolerance of instability.<br>- **Beta**: Release open to all developers. This release does not promise API stability and may require tolerance of instability.<br>- **Release**: Official release open to all developers. This release promises that all APIs are stable.|
| osFullName | string | Yes| No| OS version.|
| majorVersion | number | Yes| No| Major version, incrementing along with OS version updates.|
| seniorVersion | number | Yes| No| Senior version, incrementing along with architecture and feature updates.|
| featureVersion | number | Yes| No| Feature version.|
| buildVersion | number | Yes| No| Build version.|
| sdkApiVersion | number | Yes| No| SDK API version.|
| firstApiVersion | number | Yes| No| First API version.|
| versionId | string | Yes| No| Version ID.|
| buildType | string | Yes| No| Build type.|
| buildUser | string | Yes| No| Build user.|
| buildHost | string | Yes| No| Build host.|
| buildTime | string | Yes| No| Build time.|
| buildRootHash | string | Yes| No| Build root hash.|
| udid<sup>7+</sup> | string | Yes| No| Device UDID.<br>**Required permissions**: ohos.permission.sec.ACCESS_UDID|
| distributionOSName<sup>10+</sup> | String | Yes| No| Name of the distribution OS.|
| distributionOSVersion<sup>10+</sup> | String | Yes| No| Version number of the distribution OS.|
| distributionOSApiVersion<sup>10+</sup> | number| Yes| No| API version of the distribution OS.|
| distributionOSReleaseType<sup>10+</sup> | String | Yes| No| Type of the distribution OS.|

**Example**

```ts
    import deviceinfo from '@ohos.deviceInfo'

    let deviceTypeInfo: string = deviceinfo.deviceType;
    console.info('the value of the deviceType is :' + deviceTypeInfo);

    let manufactureInfo: string = deviceinfo.manufacture;
    console.info('the value of the manufactureInfo is :' + manufactureInfo);

    let brandInfo: string = deviceinfo.brand;
    console.info('the value of the device brand is :' + brandInfo);

    let marketNameInfo: string = deviceinfo.marketName;
    console.info('the value of the deviceinfo marketName is :' + marketNameInfo);

    let productSeriesInfo: string = deviceinfo.productSeries;
    console.info('the value of the deviceinfo productSeries is :' + productSeriesInfo);

    let productModelInfo: string = deviceinfo.productModel;
    console.info('the value of the deviceinfo productModel is :' + productModelInfo);

    let softwareModelInfo: string = deviceinfo.softwareModel;
    console.info('the value of the deviceinfo softwareModel is :' + softwareModelInfo);

    let hardwareModelInfo: string = deviceinfo.hardwareModel;
    console.info('the value of the deviceinfo hardwareModel is :' + hardwareModelInfo);

    let hardwareProfileInfo: string = deviceinfo.hardwareProfile;
    console.info('the value of the deviceinfo hardwareProfile is :' + hardwareProfileInfo);

    let serialInfo: string = deviceinfo.serial;
    console.info('the value of the deviceinfo serial is :' + serialInfo);

    let bootloaderVersionInfo: string = deviceinfo.bootloaderVersion;
    console.info('the value of the deviceinfo bootloaderVersion is :' + bootloaderVersionInfo);

    let abiListInfo: string = deviceinfo.abiList;
    console.info('the value of the deviceinfo abiList is :' + abiListInfo);

    let securityPatchTagInfo: string = deviceinfo.securityPatchTag;
    console.info('the value of the deviceinfo securityPatchTag is :' + securityPatchTagInfo);

    let displayVersionInfo: string = deviceinfo.displayVersion;
    console.info('the value of the deviceinfo displayVersion is :' + displayVersionInfo);

    let incrementalVersionInfo: string = deviceinfo.incrementalVersion;
    console.info('the value of the deviceinfo incrementalVersion is :' + incrementalVersionInfo);

    let osReleaseTypeInfo: string = deviceinfo.osReleaseType;
    console.info('the value of the deviceinfo osReleaseType is :' + osReleaseTypeInfo);

    let osFullNameInfo: string = deviceinfo.osFullName;
    console.info('the value of the deviceinfo osFullName is :' + osFullNameInfo);

    let majorVersionInfo: number = deviceinfo.majorVersion;
    console.info('the value of the deviceinfo majorVersion is :' + majorVersionInfo);

    let seniorVersionInfo: number = deviceinfo.seniorVersion;
    console.info('the value of the deviceinfo seniorVersion is :' + seniorVersionInfo);

    let featureVersionInfo: number = deviceinfo.featureVersion;
    console.info('the value of the deviceinfo featureVersion is :' + featureVersionInfo);

    let buildVersionInfo: number = deviceinfo.buildVersion;
    console.info('the value of the deviceinfo buildVersion is :' + buildVersionInfo);

    let sdkApiVersionInfo: number = deviceinfo.sdkApiVersion;
    console.info('the value of the deviceinfo sdkApiVersion is :' + sdkApiVersionInfo);

    let firstApiVersionInfo: number = deviceinfo.firstApiVersion;
    console.info('the value of the deviceinfo firstApiVersion is :' + firstApiVersionInfo);

    let versionIdInfo: string = deviceinfo.versionId;
    console.info('the value of the deviceinfo versionId is :' + versionIdInfo);

    let buildTypeInfo: string = deviceinfo.buildType;
    console.info('the value of the deviceinfo buildType is :' + buildTypeInfo);

    let buildUserInfo: string = deviceinfo.buildUser;
    console.info('the value of the deviceinfo buildUser is :' + buildUserInfo);

    let buildHostInfo: string = deviceinfo.buildHost;
    console.info('the value of the deviceinfo buildHost is :' + buildHostInfo);

    let buildTimeInfo: string = deviceinfo.buildTime;
    console.info('the value of the deviceinfo buildTime is :' + buildTimeInfo);

    let buildRootHashInfo: string = deviceinfo.buildRootHash;
    console.info('the value of the deviceinfo buildRootHash is :' + buildRootHashInfo);

    let udid: string = deviceinfo.udid;
    console.info('the value of the deviceinfo udid is :' + udid);

    let distributionOSName: string = deviceinfo.distributionOSName
    console.info('the value of the deviceinfo distributionOSName is :' + distributionOSName);

    let distributionOSVersion: string = deviceinfo.distributionOSVersion
    console.info('the value of the deviceinfo distributionOSVersion is :' + distributionOSVersion);

    let distributionOSApiVersion: number = deviceinfo.distributionOSApiVersion
    console.info('the value of the deviceinfo distributionOSApiVersion is :' + distributionOSApiVersion);

    let distributionOSReleaseType: string = deviceinfo.distributionOSReleaseType
    console.info('the value of the deviceinfo distributionOSReleaseType is :' + distributionOSReleaseType);

```
