# @ohos.deviceInfo (Device Information)

The **deviceInfo** module provides terminal device information query, which cannot be configured by developers.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> Some parameters whose return value is the default value are not yet available.
> The APIs of this module return information about device constants. You are not expected to call these APIs frequently.

## Modules to Import

```ts
import { deviceInfo } from '@kit.BasicServicesKit';
```

## Constants
> **NOTE**
> Unless otherwise specified, the maximum data length is 96 bytes.

**System capability**: SystemCapability.Startup.SystemInfo

**Required permissions**: The items in the table below require different system capabilities.

| Name| Type| Read-Only| Description|
| -------- | -------- | -------- | -------- |
| deviceType | string | Yes| Device type. For details, see [deviceTypes tag](../../quick-start/module-configuration-file.md#devicetypes).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>Example: <!--RP1-->wearable<!--RP1End-->|
| manufacture | string | Yes| Device manufacturer.<br>Example: HUAWEI|
| brand | string | Yes| Device brand.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>Example: HUAWEI|
| marketName | string | Yes| Marketing name.<br>Example: <!--RP2-->Mate XX<!--RP2End--> |
| productSeries | string | Yes| Product series.<br>Example: <!--RP3-->TAS<!--RP3End--> |
| productModel | string | Yes| Product model.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>Example: <!--RP4-->TAS-AL00<!--RP4End--> |
| productModelAlias<sup>14+</sup> | string | Yes| Product model alias.<br>**Atomic service API**: This API can be used in atomic services since API version 14.<br>Example: TAS-AL00|
| softwareModel | string | Yes| Software model.<br>Example: <!--RP5-->TAS-AL00<!--RP5End--> |
| hardwareModel | string | Yes| Hardware model.<br>Example: <!--RP6-->TASA00CVN1<!--RP6End--> |
| hardwareProfile<sup>(deprecated) </sup> | string | Yes| Hardware profile.<br>**NOTE**<br>This API is supported since API version 6 and deprecated since API version 9.<br>Example: default|
| serial | string | Yes| Device serial number (SN).<br>**NOTE**<br>The device SN can be used as the unique identifier of a device.<br>**Required permission**: ohos.permission.sec.ACCESS_UDID (for system applications and enterprise applications only)<br>Example: The SN varies with the device.|
| bootloaderVersion | string | Yes| Bootloader version.<br>Example: bootloader|
| abiList | string | Yes| Application binary interface (Abi) list.<br>Example: arm64-v8a|
| securityPatchTag | string | Yes| Security patch tag.<br>Example: <!--RP7-->2021/01/01<!--RP7End--> |
| displayVersion | string | Yes| Product version.<br>Example: <!--RP8-->XXX X.X.X.X<!--RP8End--> |
| incrementalVersion | string | Yes| Incremental version.<br>Example: default|
| osReleaseType | string | Yes| OS release type. The options are as follows:<br>- **Canary**: Preliminary release open only to specific developers. This release does not promise API stability and may require tolerance of instability.<br>- **Beta**: Release open to all developers. This release does not promise API stability and may require tolerance of instability.<br>- **Release**: Official release open to all developers. This release promises that all APIs are stable.<br>Example: <!--RP9-->Canary/Beta/Release<!--RP9End--> |
| osFullName | string | Yes| System version. The version number is in the format of **OpenHarmony-x.x.x.x**, where **x** is a digit.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>Example: <!--RP10-->Openharmony-5.0.0.1<!--RP10End--> |
| majorVersion | number | Yes| Major version number, which increments with the main version. The value is the first digit in **osFullName**. You are advised to use **deviceInfo.majorVersion** instead of parsing **osFullName** to obtain the value, facilitating efficiency improvement.<br>Example: 5|
| seniorVersion | number | Yes| Senior version number, which increments with architecture and feature updates. The value is the second digit in **osFullName**. You are advised to use **deviceInfo.seniorVersion** instead of parsing **osFullName** to obtain the value, facilitating efficiency improvement.<br>Example: 0|
| featureVersion | number | Yes| Feature version number. The value is the third digit in **osFullName**. You are advised to use **deviceInfo.featureVersion** instead of parsing **osFullName** to obtain the value, facilitating efficiency improvement.<br>Example: 0|
| buildVersion | number | Yes| Build version number. The value is the fourth digit in **osFullName**. You are advised to use **deviceInfo.buildVersion** instead of parsing **osFullName** to obtain the value, facilitating efficiency improvement.<br>Example: 1|
| sdkApiVersion | number | Yes| SDK API version.<br>**Atomic service API**: This API can be used in atomic services since API version 14.<br>Example: 12|
| firstApiVersion | number | Yes| First API version.<br>Example: 3|
| versionId | string | Yes| Version ID. It consists of the following fields: **deviceType**, **manufacture**, **brand**, **productSeries**, **osFullName**, **productModel**, **softwareModel**, **sdkApiVersion**, **incrementalVersion**, and **buildType**.<br>Example: wearable/HUAWEI/HUAWEI/TAS/OpenHarmony-5.0.0.1/TAS-AL00/TAS-AL00/12/default/release:nolog|
| buildType | string | Yes| Build type.<br>Example: default|
| buildUser | string | Yes| Build user.<br>Example: default|
| buildHost | string | Yes| Build host.<br>Example: default|
| buildTime | string | Yes| Build time.<br>Example: default|
| buildRootHash | string | Yes| Build root hash.<br>Example: default|
| udid<sup>7+</sup> | string | Yes| Device UDID.<br>**NOTE**<br>The data length is 65 bytes. The UDID can be used as the unique identifier of a device.<br>**Required permission**: ohos.permission.sec.ACCESS_UDID (for system applications and enterprise applications only)<br>Example: 9D6AABD147XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXE5536412 |
| distributionOSName<sup>10+</sup> | string | Yes| Distribution OS name.<!--Del--> It is defined by the issuer.<!--DelEnd--><br>Example: OpenHarmony|
| distributionOSVersion<sup>10+</sup> | string | Yes| Distribution OS version.<!--Del--> It is defined by the issuer.<!--DelEnd--><!--RP11--><!--RP11End--><br>Example: 5.0.0 |
| distributionOSApiVersion<sup>10+</sup> | number| Yes| Distribution OS API version.<!--Del--> It is defined by the issuer.<!--DelEnd--><br>Example: 50001|
| distributionOSApiName<sup>13+</sup> | string | Yes| Distribution OS API name.<!--Del--> It is defined by the issuer.<!--DelEnd-->|
| distributionOSReleaseType<sup>10+</sup> | string | Yes| Distribution OS release type.<!--Del--> It is defined by the issuer.<!--DelEnd--><br>Example: Release|
| ODID<sup>12+</sup> | string | Yes|Open device identifier.<br>An ODID will be regenerated in the following scenarios:<br>Restore a phone to its factory settings.<br>Uninstall and reinstall all applications with the same **developerId** on one device.<br>An ODID is generated based on the following rules:<br>The value is generated based on the **groupId** parsed from the **developerId** in the signature information. As **groupId.developerId** is the rule, if no **groupId** exists, the **developerId** is used as the **groupId**.<br>Applications with the same **developerId** use the same ODID on one device.<br>Applications with different **developerId**s use different ODIDs on one device.<br>Applications with the same **developerId** use different ODIDs on different devices.<br>Applications with different **developerId**s use different ODIDs on different devices.<br>**NOTE**<br>The data length is 37 bytes.<br>Example: 1234a567-XXXX-XXXX-XXXX-XXXXXXXXXXXX|
| diskSN<sup>15+</sup> | string | Yes| Disk SN.<br>**NOTE**<br>This field can be queried only on the 2-in-1 device. For other devices, the query result is empty.<br>**Required permissions**: ohos.permission.ACCESS_DISK_PHY_INFO<br>Example: 2502EM400567 |
| performanceClass<sup>19+</sup> | [PerformanceClassLevel](#performanceclasslevel19) | Yes| Device capability level.|

**Example**

```ts
    import { deviceInfo } from '@kit.BasicServicesKit';

    let deviceTypeInfo: string = deviceInfo.deviceType;
    // Output: the value of the deviceType is :wearable
    console.info('the value of the deviceType is :' + deviceTypeInfo);

    let manufactureInfo: string = deviceInfo.manufacture;
    // Output: the value of the manufacture is :HUAWEI
    console.info('the value of the manufactureInfo is :' + manufactureInfo);

    let brandInfo: string = deviceInfo.brand;
    // Output: the value of the brand is :HUAWEI
    console.info('the value of the device brand is :' + brandInfo);

    let marketNameInfo: string = deviceInfo.marketName;
    // Output: the value of the marketName is :Mate XX
    console.info('the value of the deviceInfo marketName is :' + marketNameInfo);

    let productSeriesInfo: string = deviceInfo.productSeries;
    // Output: the value of the productSeries is :TAS
    console.info('the value of the deviceInfo productSeries is :' + productSeriesInfo);

    let productModelInfo: string = deviceInfo.productModel;
    // Output: the value of the productModel is :TAS-AL00
    console.info('the value of the deviceInfo productModel is :' + productModelInfo);

    let productModelAliasInfo: string = deviceInfo.productModelAlias;
    console.info('the value of the deviceInfo productModelAlias is :' + productModelAliasInfo);

    let softwareModelInfo: string = deviceInfo.softwareModel;
    // Output: the value of the softwareModel is :TAS-AL00
    console.info('the value of the deviceInfo softwareModel is :' + softwareModelInfo);

    let hardwareModelInfo: string = deviceInfo.hardwareModel;
    // Output: the value of the hardwareModel is :TASA00CVN1
    console.info('the value of the deviceInfo hardwareModel is :' + hardwareModelInfo);

    let serialInfo: string = deviceInfo.serial;
    // Output: the value of the serial is :The SN varies with the device.
    console.info('the value of the deviceInfo serial is :' + serialInfo);

    let bootloaderVersionInfo: string = deviceInfo.bootloaderVersion;
    // Output: the value of the bootloaderVersion is :bootloader
    console.info('the value of the deviceInfo bootloaderVersion is :' + bootloaderVersionInfo);

    let abiListInfo: string = deviceInfo.abiList;
    // Output: the value of the abiList is :arm64-v8a
    console.info('the value of the deviceInfo abiList is :' + abiListInfo);

    let securityPatchTagInfo: string = deviceInfo.securityPatchTag;
    // Output: the value of the securityPatchTag is :2021/01/01
    console.info('the value of the deviceInfo securityPatchTag is :' + securityPatchTagInfo);

    let displayVersionInfo: string = deviceInfo.displayVersion;
    // Output: the value of the displayVersion is :XXX X.X.X.X
    console.info('the value of the deviceInfo displayVersion is :' + displayVersionInfo);

    let incrementalVersionInfo: string = deviceInfo.incrementalVersion;
    // Output: the value of the incrementalVersion is :default
    console.info('the value of the deviceInfo incrementalVersion is :' + incrementalVersionInfo);

    let osReleaseTypeInfo: string = deviceInfo.osReleaseType;
    // Output: the value of the osReleaseType is :Release
    console.info('the value of the deviceInfo osReleaseType is :' + osReleaseTypeInfo);

    let osFullNameInfo: string = deviceInfo.osFullName;
    // Output: the value of the osFullName is :OpenHarmony-5.0.0.1
    console.info('the value of the deviceInfo osFullName is :' + osFullNameInfo);

    let majorVersionInfo: number = deviceInfo.majorVersion;
    // Output: the value of the majorVersion is :5
    console.info('the value of the deviceInfo majorVersion is :' + majorVersionInfo);

    let seniorVersionInfo: number = deviceInfo.seniorVersion;
    // Output: the value of the seniorVersion is :0
    console.info('the value of the deviceInfo seniorVersion is :' + seniorVersionInfo);

    let featureVersionInfo: number = deviceInfo.featureVersion;
    // Output: the value of the featureVersion is :0
    console.info('the value of the deviceInfo featureVersion is :' + featureVersionInfo);

    let buildVersionInfo: number = deviceInfo.buildVersion;
    // Output: the value of the buildVersion is :1
    console.info('the value of the deviceInfo buildVersion is :' + buildVersionInfo);

    let sdkApiVersionInfo: number = deviceInfo.sdkApiVersion;
    // Output: the value of the sdkApiVersion is :12
    console.info('the value of the deviceInfo sdkApiVersion is :' + sdkApiVersionInfo);

    let firstApiVersionInfo: number = deviceInfo.firstApiVersion;
    // Output: the value of the firstApiVersion is :3
    console.info('the value of the deviceInfo firstApiVersion is :' + firstApiVersionInfo);

    let versionIdInfo: string = deviceInfo.versionId;
    // Output: the value of the versionId is :wearable/HUAWEI/HUAWEI/TAS/OpenHarmony-5.0.0.1/TAS-AL00/TAS-AL00/12/default/release:nolog
    console.info('the value of the deviceInfo versionId is :' + versionIdInfo);

    let buildTypeInfo: string = deviceInfo.buildType;
    // Output: the value of the buildType is :default
    console.info('the value of the deviceInfo buildType is :' + buildTypeInfo);

    let buildUserInfo: string = deviceInfo.buildUser;
    // Output: the value of the buildUser is :default
    console.info('the value of the deviceInfo buildUser is :' + buildUserInfo);

    let buildHostInfo: string = deviceInfo.buildHost;
    // Output: the value of the buildHost is :default
    console.info('the value of the deviceInfo buildHost is :' + buildHostInfo);

    let buildTimeInfo: string = deviceInfo.buildTime;
    // Output: the value of the buildTime is :default
    console.info('the value of the deviceInfo buildTime is :' + buildTimeInfo);

    let buildRootHashInfo: string = deviceInfo.buildRootHash;
    // Output: the value of the buildRootHash is :default
    console.info('the value of the deviceInfo buildRootHash is :' + buildRootHashInfo);

    let udid: string = deviceInfo.udid;
    // Output: the value of the udid is :9D6AABD147XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXE5536412
    console.info('the value of the deviceInfo udid is :' + udid);

    let distributionOSName: string = deviceInfo.distributionOSName
    // Output: the value of the distributionOSName is :OpenHarmony
    console.info('the value of the deviceInfo distributionOSName is :' + distributionOSName);

    let distributionOSVersion: string = deviceInfo.distributionOSVersion
    // Output: the value of the distributionOSVersion is :5.0.0
    console.info('the value of the deviceInfo distributionOSVersion is :' + distributionOSVersion);

    let distributionOSApiVersion: number = deviceInfo.distributionOSApiVersion
    // Output: the value of the distributionOSApiVersion is :500001
    console.info('the value of the deviceInfo distributionOSApiVersion is :' + distributionOSApiVersion);

    let distributionOSApiName: string = deviceInfo.distributionOSApiName
    console.info('the value of the deviceInfo distributionOSApiName is :' + distributionOSApiName);

    let distributionOSReleaseType: string = deviceInfo.distributionOSReleaseType
    // Output: the value of the distributionOSReleaseType is :Release
    console.info('the value of the deviceInfo distributionOSReleaseType is :' + distributionOSReleaseType);

    let odid: string = deviceInfo.ODID;
    // Output: the value of the ODID is :1234a567-XXXX-XXXX-XXXX-XXXXXXXXXXXX
    console.info('the value of the deviceInfo odid is :' + odid);

    let diskSN: string = deviceInfo.diskSN;
    // Output: the value of the deviceInfo diskSN is :2502EM400567
    console.info('the value of the deviceInfo diskSN is :' + diskSN);

    let performanceClass = deviceInfo.performanceClass;
    // Output: the value of the deviceInfo performanceClass is :0
    console.info('the value of the deviceInfo performanceClass is :' + performanceClass);

```

## PerformanceClassLevel<sup>19+</sup>

Enumerates the device capability levels.

**System capability**: SystemCapability.Startup.SystemInfo

| Name                 | Value | Description          |
| ---------------------| ---- | -------------- |
| CLASS_LEVEL_HIGH     | 0    | High    |
| CLASS_LEVEL_MEDIUM   | 1    | Medium  |
| CLASS_LEVEL_LOW      | 2    | Low  |

## DeviceTypes<sup>20+</sup>

Enumerates device types, which can be used to verify the return value of **deviceType**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Startup.SystemInfo

| Name| Value  | Description                      |
| ---- | ---- | -------------------------- |
| TYPE_DEFAULT | 'default' | Default device|
| TYPE_PHONE | 'phone' | Smartphone|
| TYPE_TABLET | 'tablet' | Tablet|
| TYPE_2IN1 | '2in1' | PC/2-in-1 device|
| TYPE_TV | 'tv' | Smart TV|
| TYPE_WEARABLE | 'wearable' | Wearable|
| TYPE_CAR | 'car' | Head unit|

**Example**

```ts
    let deviceTypesInfo: string = deviceInfo.DeviceTypes.TYPE_DEFAULT;
    // Output: the value of the DeviceTypes is :default
    console.info('the value of the DeviceTypes is :' + deviceTypesInfo);

    let deviceTypesInfo: string = deviceInfo.DeviceTypes.TYPE_PHONE;
    // Output: the value of the DeviceTypes is :phone-type 
    console.info('the value of the DeviceTypes is :' + deviceTypesInfo);

    let deviceTypesInfo: string = deviceInfo.DeviceTypes.TYPE_TABLET;
    //Output: the value of the DeviceTypes is :tablet
    console.info('the value of the DeviceTypes is :' + deviceTypesInfo);

    let deviceTypesInfo: string = deviceInfo.DeviceTypes.TYPE_2IN1;
    //Output: the value of the DeviceTypes is :2in1
    console.info('the value of the DeviceTypes is :' + deviceTypesInfo);

    let deviceTypesInfo: string = deviceInfo.DeviceTypes.TYPE_TV;
    //Output: the value of the DeviceTypes is :tv
    console.info('the value of the DeviceTypes is :' + deviceTypesInfo);

    let deviceTypesInfo: string = deviceInfo.DeviceTypes.TYPE_WEARABLE;
    // Output: the value of the DeviceTypes is :wearable
    console.info('the value of the DeviceTypes is :' + deviceTypesInfo);

    let deviceTypesInfo: string = deviceInfo.DeviceTypes.TYPE_CAR;
    //Output: the value of the DeviceTypes is :car
    console.info('the value of the DeviceTypes is :' + deviceTypesInfo);
```
