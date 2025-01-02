# @ohos.deviceInfo (设备信息)

本模块提供终端设备信息查询，开发者不可配置。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 部分参数返回值为default的，会在正式发布的版本中配置。
> 本模块接口返回设备常量信息，建议应用只调用一次，不需要频繁调用。

## 导入模块

```ts
import { deviceInfo } from '@kit.BasicServicesKit';
```

## 属性
> **说明：**
> 未特殊说明的字段，数据长度最大值为96字节。

**系统能力**：SystemCapability.Startup.SystemInfo。

**权限**：以下各项所需要的权限有所不同，详见下表。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceType | string | 是 | 否 | 设备类型。详细请参考[deviceTypes标签](../../quick-start/module-configuration-file.md#devicetypes标签)。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br/>示例：<!--RP1-->wearable<!--RP1End-->|
| manufacture | string | 是 | 否 | 设备厂家名称。<br/>示例：HUAWEI |
| brand | string | 是 | 否 | 设备品牌名称。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br/>示例：HUAWEI |
| marketName | string | 是 | 否 | 外部产品系列。<br/>示例：<!--RP2-->Mate XX<!--RP2End--> |
| productSeries | string | 是 | 否 | 产品系列。<br/>示例：<!--RP3-->TAS<!--RP3End--> |
| productModel | string | 是 | 否 | 认证型号。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br/>示例：<!--RP4-->TAS-AL00<!--RP4End--> |
| productModelAlias<sup>14+</sup> | string | 是 | 否 | 认证型号别名。<br/>**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。<br/>示例：TAS-AL00 |
| softwareModel | string | 是 | 否 | 内部软件子型号。<br/>示例：<!--RP5-->TAS-AL00<!--RP5End--> |
| hardwareModel | string | 是 | 否 | 硬件版本号。<br/>示例：<!--RP6-->TASA00CVN1<!--RP6End--> |
| hardwareProfile<sup>(deprecated) </sup> | string | 是 | 否 | 硬件Profile。<br/>**说明**：<br/>从API version 6 开始支持，从API version 9 开始废弃。<br/>示例：default |
| serial | string | 是 | 否 | 设备序列号。<br/>**说明**：可作为设备唯一识别码。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID <br/>示例：序列号随设备差异 |
| bootloaderVersion | string | 是 | 否 | Bootloader版本号。<br/>示例：bootloader |
| abiList | string | 是 | 否 | 应用二进制接口（Abi）。<br/>示例：arm64-v8a |
| securityPatchTag | string | 是 | 否 | 安全补丁级别。<br/>示例：<!--RP7-->2021-01-01<!--RP7End--> |
| displayVersion | string | 是 | 否 | 产品版本。<br/>示例：<!--RP8-->XXX X.X.X.X<!--RP8End--> |
| incrementalVersion | string | 是 | 否 | 差异版本号。<br/>示例：default |
| osReleaseType | string | 是 | 否 | 系统的发布类型，取值为：<br/>-&nbsp;Canary：面向特定开发者发布的早期预览版本，不承诺API稳定性。<br/>-&nbsp;Beta：面向开发者公开发布的Beta版本，不承诺API稳定性。<br/>-&nbsp;Release：面向开发者公开发布的正式版本，承诺API稳定性。<br/>示例：<!--RP9-->Canary/Beta/Release<!--RP9End--> |
| osFullName | string | 是 | 否 | 系统版本，版本格式OpenHarmony-x.x.x.x,x为数值。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br/>示例：<!--RP10-->Openharmony-5.0.0.1<!--RP10End--> |
| majorVersion | number | 是 | 否 | Major版本号，随主版本更新增加，值为osFullName中的第一位数值，建议直接使用deviceInfo.majorVersion获取，可提升效率，不建议开发者解析osFullName获取。<br/>示例：5 |
| seniorVersion | number | 是 | 否 | Senior版本号，随局部架构、重大特性增加，值为osFullName中的第二位数值，建议直接使用deviceInfo.seniorVersion获取，可提升效率，不建议开发者自主解析osFullName获取。<br/>示例：0 |
| featureVersion | number | 是 | 否 | Feature版本号，标识规划的新特性版本，值为osFullName中的第三位数值，建议直接使用deviceInfo.featureVersion获取，可提升效率，不建议开发者自主解析osFullName获取。<br/>示例：0 |
| buildVersion | number | 是 | 否 | Build版本号，标识编译构建的版本号，值为osFullName中的第四位数值，建议直接使用deviceInfo.buildVersion获取，可提升效率，不建议开发者自主解析osFullName获取。<br/>示例：1 |
| sdkApiVersion | number | 是 | 否 | 系统软件API版本。<br/>**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。<br/>示例：12 |
| firstApiVersion | number | 是 | 否 | 首个版本系统软件API版本。<br/>示例：3 |
| versionId | string | 是 | 否 | 版本ID。由deviceType、manufacture、brand、productSeries、osFullName、productModel、softwareModel、sdkApiVersion、incrementalVersion、buildType拼接组成。<br/>示例：wearable/HUAWEI/HUAWEI/TAS/OpenHarmony-5.0.0.1/TAS-AL00/TAS-AL00/12/default/release:nolog |
| buildType | string | 是 | 否 | 构建类型。<br/>示例：release:nolog |
| buildUser | string | 是 | 否 | 构建用户。<br/>示例：default |
| buildHost | string | 是 | 否 | 构建主机。<br/>示例：default |
| buildTime | string | 是 | 否 | 构建时间。<br/>示例：default |
| buildRootHash | string | 是 | 否 | 构建版本Hash。<br/>示例：default |
| udid<sup>7+</sup> | string | 是 | 否 | 设备Udid。<br/>**说明**：数据长度为65字节。可作为设备唯一识别码。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID<br/>示例：9D6AABD147XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXE5536412  |
| distributionOSName<sup>10+</sup> | string | 是 | 否 | 发行版系统名称<!--Del-->，由发行方定义<!--DelEnd-->。<br/>示例：OpenHarmony |
| distributionOSVersion<sup>10+</sup> | string | 是 | 否 | 发行版系统版本号<!--Del-->，由发行方定义<!--DelEnd-->。<!--RP11--><!--RP11End--><br/>示例：5.0.0.1  |
| distributionOSApiVersion<sup>10+</sup> | number| 是 | 否 | 发行版系统api版本<!--Del-->，由发行方定义<!--DelEnd-->。<br/>示例：50001 |
| distributionOSApiName<sup>13+</sup> | string | 是 | 否 | 发行版系统api版本名称<!--Del-->，由发行方定义<!--DelEnd-->。 |
| distributionOSReleaseType<sup>10+</sup> | string | 是 | 否 | 发行版系统类型<!--Del-->，由发行方定义<!--DelEnd-->。<br/>示例：Release |
| ODID<sup>12+</sup> | string | 是 | 否 |开发者匿名设备标识符。<br/>**ODID值会在以下场景重新生成**：<br/>手机恢复出厂设置。<br/>同一设备上同一个开发者(developerId相同)的应用全部卸载后重新安装时。<br/>**ODID生成规则**：<br/>根据签名信息里developerId解析出的groupId生成，developerId规则为groupId.developerId，若无groupId则取整个developerId作为groupId。<br/>同一设备上运行的同一个开发者(developerId相同)的应用，ODID相同。<br/>同一个设备上不同开发者(developerId不同)的应用，ODID不同。<br/>不同设备上同一个开发者(developerId相同)的应用，ODID不同。<br/>不同设备上不同开发者(developerId不同)的应用，ODID不同。<br/>**说明**：数据长度为37字节。<br/>示例：1234a567-XXXX-XXXX-XXXX-XXXXXXXXXXXX |

**示例**

```ts
    import { deviceInfo } from '@kit.BasicServicesKit';

    let deviceTypeInfo: string = deviceInfo.deviceType;
    // 输出结果：the value of the deviceType is :wearable
    console.info('the value of the deviceType is :' + deviceTypeInfo);

    let manufactureInfo: string = deviceInfo.manufacture;
    // 输出结果：the value of the manufacture is :HUAWEI
    console.info('the value of the manufactureInfo is :' + manufactureInfo);

    let brandInfo: string = deviceInfo.brand;
    // 输出结果：the value of the brand is :HUAWEI
    console.info('the value of the device brand is :' + brandInfo);

    let marketNameInfo: string = deviceInfo.marketName;
    // 输出结果：the value of the marketName is :Mate XX
    console.info('the value of the deviceInfo marketName is :' + marketNameInfo);

    let productSeriesInfo: string = deviceInfo.productSeries;
    // 输出结果：the value of the productSeries is :TAS
    console.info('the value of the deviceInfo productSeries is :' + productSeriesInfo);

    let productModelInfo: string = deviceInfo.productModel;
    // 输出结果：the value of the productModel is :TAS-AL00
    console.info('the value of the deviceInfo productModel is :' + productModelInfo);

    let productModelAliasInfo: string = deviceInfo.productModelAlias;
    console.info('the value of the deviceInfo productModelAlias is :' + productModelAliasInfo);

    let softwareModelInfo: string = deviceInfo.softwareModel;
    // 输出结果：the value of the softwareModel is :TAS-AL00
    console.info('the value of the deviceInfo softwareModel is :' + softwareModelInfo);

    let hardwareModelInfo: string = deviceInfo.hardwareModel;
    // 输出结果：the value of the hardwareModel is :TASA00CVN1
    console.info('the value of the deviceInfo hardwareModel is :' + hardwareModelInfo);

    let serialInfo: string = deviceInfo.serial;
    // 输出结果：the value of the serial is :ABC123456789
    console.info('the value of the deviceInfo serial is :' + serialInfo);

    let bootloaderVersionInfo: string = deviceInfo.bootloaderVersion;
    // 输出结果：the value of the bootloaderVersion is :bootloader
    console.info('the value of the deviceInfo bootloaderVersion is :' + bootloaderVersionInfo);

    let abiListInfo: string = deviceInfo.abiList;
    // 输出结果：the value of the abiList is :arm64-v8a
    console.info('the value of the deviceInfo abiList is :' + abiListInfo);

    let securityPatchTagInfo: string = deviceInfo.securityPatchTag;
    // 输出结果：the value of the securityPatchTag is :2021-01-01
    console.info('the value of the deviceInfo securityPatchTag is :' + securityPatchTagInfo);

    let displayVersionInfo: string = deviceInfo.displayVersion;
    // 输出结果：the value of the displayVersion is :XXX X.X.X.X
    console.info('the value of the deviceInfo displayVersion is :' + displayVersionInfo);

    let incrementalVersionInfo: string = deviceInfo.incrementalVersion;
    // 输出结果：the value of the incrementalVersion is :default
    console.info('the value of the deviceInfo incrementalVersion is :' + incrementalVersionInfo);

    let osReleaseTypeInfo: string = deviceInfo.osReleaseType;
    // 输出结果：the value of the osReleaseType is :Release
    console.info('the value of the deviceInfo osReleaseType is :' + osReleaseTypeInfo);

    let osFullNameInfo: string = deviceInfo.osFullName;
    // 输出结果：the value of the osFullName is :OpenHarmony-5.0.0.1
    console.info('the value of the deviceInfo osFullName is :' + osFullNameInfo);

    let majorVersionInfo: number = deviceInfo.majorVersion;
    // 输出结果：the value of the majorVersion is :5
    console.info('the value of the deviceInfo majorVersion is :' + majorVersionInfo);

    let seniorVersionInfo: number = deviceInfo.seniorVersion;
    // 输出结果：the value of the seniorVersion is :0
    console.info('the value of the deviceInfo seniorVersion is :' + seniorVersionInfo);

    let featureVersionInfo: number = deviceInfo.featureVersion;
    // 输出结果：the value of the featureVersion is :0
    console.info('the value of the deviceInfo featureVersion is :' + featureVersionInfo);

    let buildVersionInfo: number = deviceInfo.buildVersion;
    // 输出结果：the value of the buildVersion is :1
    console.info('the value of the deviceInfo buildVersion is :' + buildVersionInfo);

    let sdkApiVersionInfo: number = deviceInfo.sdkApiVersion;
    // 输出结果：the value of the sdkApiVersion is :12
    console.info('the value of the deviceInfo sdkApiVersion is :' + sdkApiVersionInfo);

    let firstApiVersionInfo: number = deviceInfo.firstApiVersion;
    // 输出结果：the value of the firstApiVersion is :3
    console.info('the value of the deviceInfo firstApiVersion is :' + firstApiVersionInfo);

    let versionIdInfo: string = deviceInfo.versionId;
    // 输出结果：the value of the versionId is :wearable/HUAWEI/HUAWEI/TAS/OpenHarmony-5.0.0.1/TAS-AL00/TAS-AL00/12/default/release:nolog
    console.info('the value of the deviceInfo versionId is :' + versionIdInfo);

    let buildTypeInfo: string = deviceInfo.buildType;
    // 输出结果：the value of the buildType is :release:nolog
    console.info('the value of the deviceInfo buildType is :' + buildTypeInfo);

    let buildUserInfo: string = deviceInfo.buildUser;
    // 输出结果：the value of the buildUser is :default
    console.info('the value of the deviceInfo buildUser is :' + buildUserInfo);

    let buildHostInfo: string = deviceInfo.buildHost;
    // 输出结果：the value of the buildHost is :default
    console.info('the value of the deviceInfo buildHost is :' + buildHostInfo);

    let buildTimeInfo: string = deviceInfo.buildTime;
    // 输出结果：the value of the buildTime is :default
    console.info('the value of the deviceInfo buildTime is :' + buildTimeInfo);

    let buildRootHashInfo: string = deviceInfo.buildRootHash;
    // 输出结果：the value of the buildRootHash is :default
    console.info('the value of the deviceInfo buildRootHash is :' + buildRootHashInfo);

    let udid: string = deviceInfo.udid;
    // 输出结果：the value of the udid is :1234567890
    console.info('the value of the deviceInfo udid is :' + udid);

    let distributionOSName: string = deviceInfo.distributionOSName
    // 输出结果：the value of the distributionOSName is :OpenHarmony
    console.info('the value of the deviceInfo distributionOSName is :' + distributionOSName);

    let distributionOSVersion: string = deviceInfo.distributionOSVersion
    // 输出结果：the value of the distributionOSVersion is :5.0.0
    console.info('the value of the deviceInfo distributionOSVersion is :' + distributionOSVersion);

    let distributionOSApiVersion: number = deviceInfo.distributionOSApiVersion
    // 输出结果：the value of the distributionOSApiVersion is :500001
    console.info('the value of the deviceInfo distributionOSApiVersion is :' + distributionOSApiVersion);

    let distributionOSApiName: number = deviceInfo.distributionOSApiName
    console.info('the value of the deviceInfo distributionOSApiName is :' + distributionOSApiName);

    let distributionOSReleaseType: string = deviceInfo.distributionOSReleaseType
    // 输出结果：the value of the distributionOSReleaseType is :Release
    console.info('the value of the deviceInfo distributionOSReleaseType is :' + distributionOSReleaseType);

    let odid: string = deviceInfo.ODID;
    // 输出结果：the value of the ODID is :1234a567-XXXX-XXXX-XXXX-XXXXXXXXXXXX
    console.info('the value of the deviceInfo odid is :' + odid);

```
