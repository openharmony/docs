# @ohos.deviceInfo (设备信息)

本模块提供产品信息。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import deviceInfo from '@ohos.deviceInfo'
```

## 属性

**系统能力**：SystemCapability.Startup.SystemInfo。

**权限**：以下各项所需要的权限有所不同，详见下表。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceType | string | 是 | 否 | 设备类型。 |
| manufacture | string | 是 | 否 | 设备厂家名称。 |
| brand | string | 是 | 否 | 设备品牌名称。 |
| marketName | string | 是 | 否 | 外部产品系列。 |
| productSeries | string | 是 | 否 | 产品系列。 |
| productModel | string | 是 | 否 | 认证型号。 |
| softwareModel | string | 是 | 否 | 内部软件子型号。 |
| hardwareModel | string | 是 | 否 | 硬件版本号。 |
| hardwareProfile | string | 是 | 否 | 硬件Profile。 |
| serial | string | 是 | 否 | 设备序列号。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID |
| bootloaderVersion | string | 是 | 否 | Bootloader版本号。 |
| abiList | string | 是 | 否 | 应用二进制接口（Abi）列表。 |
| securityPatchTag | string | 是 | 否 | 安全补丁级别。 |
| displayVersion | string | 是 | 否 | 产品版本。 |
| incrementalVersion | string | 是 | 否 | 差异版本号。 |
| osReleaseType | string | 是 | 否 | 系统的发布类型，取值为：<br/>-&nbsp;Canary：面向特定开发者发布的早期预览版本，不承诺API稳定性。<br/>-&nbsp;Beta：面向开发者公开发布的Beta版本，不承诺API稳定性。<br/>-&nbsp;Release：面向开发者公开发布的正式版本，承诺API稳定性。 |
| osFullName | string | 是 | 否 | 系统版本。 |
| majorVersion | number | 是 | 否 | Major版本号，随主版本更新增加。 |
| seniorVersion | number | 是 | 否 | Senior版本号，随局部架构、重大特性增加。 |
| featureVersion | number | 是 | 否 | Feature版本号，标识规划的新特性版本。 |
| buildVersion | number | 是 | 否 | Build版本号，标识编译构建的版本号。 |
| sdkApiVersion | number | 是 | 否 | 系统软件API版本。 |
| firstApiVersion | number | 是 | 否 | 首个版本系统软件API版本。 |
| versionId | string | 是 | 否 | 版本ID。 |
| buildType | string | 是 | 否 | 构建类型。 |
| buildUser | string | 是 | 否 | 构建用户。 |
| buildHost | string | 是 | 否 | 构建主机。 |
| buildTime | string | 是 | 否 | 构建时间。 |
| buildRootHash | string | 是 | 否 | 构建版本Hash。 |
| udid<sup>7+</sup> | string | 是 | 否 | 设备Udid。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID|
| distributionOSName<sup>10+</sup> | String | 是 | 否 | 发行版系统名称。 |
| distributionOSVersion<sup>10+</sup> | String | 是 | 否 | 发行版系统版本号。 |
| distributionOSApiVersion<sup>10+</sup> | number| 是 | 否 | 发行版系统api版本。 |
| distributionOSReleaseType<sup>10+</sup> | String | 是 | 否 | 发行版系统类型。 |

**示例**

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
