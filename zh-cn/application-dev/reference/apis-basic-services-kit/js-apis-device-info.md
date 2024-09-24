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
| deviceType | string | 是 | 否 | 设备类型。详细请参考[deviceTypes标签](../../quick-start/module-configuration-file.md#devicetypes标签)。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br/>示例：wearable|
| manufacture | string | 是 | 否 | 设备厂家名称。<br/>示例：HUAWEI |
| brand | string | 是 | 否 | 设备品牌名称。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br/>示例：HUAWEI |
| marketName | string | 是 | 否 | 外部产品系列。<br/>示例：Mate XX |
| productSeries | string | 是 | 否 | 产品系列。<br/>示例：TAS |
| productModel | string | 是 | 否 | 认证型号。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br/>示例：TAS-AL00 |
| softwareModel | string | 是 | 否 | 内部软件子型号。<br/>示例：TAS-AL00 |
| hardwareModel | string | 是 | 否 | 硬件版本号。<br/>示例：TASA00CVN1 |
| hardwareProfile<sup>(deprecated) </sup> | string | 是 | 否 | 硬件Profile。<br/>**说明**：<br/>从API version 6 开始支持，从API version 9 开始废弃。 |
| serial | string | 是 | 否 | 设备序列号,仅限系统应用使用。<br/>**说明**：可作为设备唯一识别码。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID <br/>示例：序列号随设备差异 |
| bootloaderVersion | string | 是 | 否 | Bootloader版本号。<br/>示例：bootloater |
| abiList | string | 是 | 否 | 应用二进制接口（Abi）。<br/>示例：arm64-v8a |
| securityPatchTag | string | 是 | 否 | 安全补丁级别。<br/>示例：2021-01-01 |
| displayVersion | string | 是 | 否 | 产品版本。<br/>示例：XXX X.X.X.X |
| incrementalVersion | string | 是 | 否 | 差异版本号。 |
| osReleaseType | string | 是 | 否 | 系统的发布类型，取值为：<br/>-&nbsp;Canary：面向特定开发者发布的早期预览版本，不承诺API稳定性。<br/>-&nbsp;Beta：面向开发者公开发布的Beta版本，不承诺API稳定性。<br/>-&nbsp;Release：面向开发者公开发布的正式版本，承诺API稳定性。<br/>示例：Canary\\Beta\\Release |
| osFullName | string | 是 | 否 | 系统版本，版本格式OpenHarmony-x.x.x.x,x为数值。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br/>示例：Openharmony-5.0.0.1 |
| majorVersion | number | 是 | 否 | Major版本号，随主版本更新增加，值为osFullName中的第一位数值，建议直接使用deviceInfo.majorVersion获取，不建议开发者解析osFullName获取。<br/>示例：5 |
| seniorVersion | number | 是 | 否 | Senior版本号，随局部架构、重大特性增加，值为osFullName中的第二位数值，建议直接使用deviceInfo.seniorVersion获取，不建议开发者自主解析osFullName获取。<br/>示例：0 |
| featureVersion | number | 是 | 否 | Feature版本号，标识规划的新特性版本，值为osFullName中的第三位数值，建议直接使用deviceInfo.featureVersion获取，不建议开发者自主解析osFullName获取。<br/>示例：0 |
| buildVersion | number | 是 | 否 | Build版本号，标识编译构建的版本号，值为osFullName中的第四位数值，建议直接使用deviceInfo.buildVersion获取，不建议开发者自主解析osFullName获取。<br/>示例：1 |
| sdkApiVersion | number | 是 | 否 | 系统软件API版本。<br/>示例：12 |
| firstApiVersion | number | 是 | 否 | 首个版本系统软件API版本。<br/>示例：3 |
| versionId | string | 是 | 否 | 版本ID。由deviceType、manufacture、brand、productSeries、osFullName、productModel、softwareModel、sdkApiVersion、incrementalVersion、buildType拼接组成。 |
| buildType | string | 是 | 否 | 构建类型。<br/>示例：release:nolog |
| buildUser | string | 是 | 否 | 构建用户。 |
| buildHost | string | 是 | 否 | 构建主机。 |
| buildTime | string | 是 | 否 | 构建时间。 |
| buildRootHash | string | 是 | 否 | 构建版本Hash。 |
| udid<sup>7+</sup> | string | 是 | 否 | 设备Udid,仅限系统应用使用。<br/>**说明**：数据长度为65字节。可作为设备唯一识别码。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID  |
| distributionOSName<sup>10+</sup> | String | 是 | 否 | 发行版系统名称<!--Del-->，由发行方定义<!--DelEnd-->。 |
| distributionOSVersion<sup>10+</sup> | String | 是 | 否 | 发行版系统版本号<!--Del-->，由发行方定义<!--DelEnd-->。<!--RP1--><!--RP1End-->  |
| distributionOSApiVersion<sup>10+</sup> | number| 是 | 否 | 发行版系统api版本<!--Del-->，由发行方定义<!--DelEnd-->。 |
| distributionOSApiName<sup>13+</sup> | String | 是 | 否 | 发行版系统api版本名称<!--Del-->，由发行方定义<!--DelEnd-->。 |
| distributionOSReleaseType<sup>10+</sup> | String | 是 | 否 | 发行版系统类型<!--Del-->，由发行方定义<!--DelEnd-->。 |
| ODID<sup>12+</sup> | String | 是 | 否 |开发者匿名设备标识符。<br/>**ODID值会在以下场景重新生成**：<br/>手机恢复出厂设置。<br/>同一设备上同一个开发者的应用全部卸载后重新安装时。<br/>**ODID生成规则**：<br/>同一设备上运行的同一个开发者的应用，ODID相同。<br/>同一个设备上不同开发者的应用，ODID不同。<br/>不同设备上同一个开发者的应用，ODID不同。<br/>不同设备上不同开发者的应用，ODID不同。<br/>**说明**：数据长度为37字节。 |

**示例**

```ts
    import { deviceInfo } from '@kit.BasicServicesKit';

    let deviceTypeInfo: string = deviceInfo.deviceType;
    console.info('the value of the deviceType is :' + deviceTypeInfo);

    let manufactureInfo: string = deviceInfo.manufacture;
    console.info('the value of the manufactureInfo is :' + manufactureInfo);

    let brandInfo: string = deviceInfo.brand;
    console.info('the value of the device brand is :' + brandInfo);

    let marketNameInfo: string = deviceInfo.marketName;
    console.info('the value of the deviceInfo marketName is :' + marketNameInfo);

    let productSeriesInfo: string = deviceInfo.productSeries;
    console.info('the value of the deviceInfo productSeries is :' + productSeriesInfo);

    let productModelInfo: string = deviceInfo.productModel;
    console.info('the value of the deviceInfo productModel is :' + productModelInfo);

    let softwareModelInfo: string = deviceInfo.softwareModel;
    console.info('the value of the deviceInfo softwareModel is :' + softwareModelInfo);

    let hardwareModelInfo: string = deviceInfo.hardwareModel;
    console.info('the value of the deviceInfo hardwareModel is :' + hardwareModelInfo);

    let serialInfo: string = deviceInfo.serial;
    console.info('the value of the deviceInfo serial is :' + serialInfo);

    let bootloaderVersionInfo: string = deviceInfo.bootloaderVersion;
    console.info('the value of the deviceInfo bootloaderVersion is :' + bootloaderVersionInfo);

    let abiListInfo: string = deviceInfo.abiList;
    console.info('the value of the deviceInfo abiList is :' + abiListInfo);

    let securityPatchTagInfo: string = deviceInfo.securityPatchTag;
    console.info('the value of the deviceInfo securityPatchTag is :' + securityPatchTagInfo);

    let displayVersionInfo: string = deviceInfo.displayVersion;
    console.info('the value of the deviceInfo displayVersion is :' + displayVersionInfo);

    let incrementalVersionInfo: string = deviceInfo.incrementalVersion;
    console.info('the value of the deviceInfo incrementalVersion is :' + incrementalVersionInfo);

    let osReleaseTypeInfo: string = deviceInfo.osReleaseType;
    console.info('the value of the deviceInfo osReleaseType is :' + osReleaseTypeInfo);

    let osFullNameInfo: string = deviceInfo.osFullName;
    console.info('the value of the deviceInfo osFullName is :' + osFullNameInfo);

    let majorVersionInfo: number = deviceInfo.majorVersion;
    console.info('the value of the deviceInfo majorVersion is :' + majorVersionInfo);

    let seniorVersionInfo: number = deviceInfo.seniorVersion;
    console.info('the value of the deviceInfo seniorVersion is :' + seniorVersionInfo);

    let featureVersionInfo: number = deviceInfo.featureVersion;
    console.info('the value of the deviceInfo featureVersion is :' + featureVersionInfo);

    let buildVersionInfo: number = deviceInfo.buildVersion;
    console.info('the value of the deviceInfo buildVersion is :' + buildVersionInfo);

    let sdkApiVersionInfo: number = deviceInfo.sdkApiVersion;
    console.info('the value of the deviceInfo sdkApiVersion is :' + sdkApiVersionInfo);

    let firstApiVersionInfo: number = deviceInfo.firstApiVersion;
    console.info('the value of the deviceInfo firstApiVersion is :' + firstApiVersionInfo);

    let versionIdInfo: string = deviceInfo.versionId;
    console.info('the value of the deviceInfo versionId is :' + versionIdInfo);

    let buildTypeInfo: string = deviceInfo.buildType;
    console.info('the value of the deviceInfo buildType is :' + buildTypeInfo);

    let buildUserInfo: string = deviceInfo.buildUser;
    console.info('the value of the deviceInfo buildUser is :' + buildUserInfo);

    let buildHostInfo: string = deviceInfo.buildHost;
    console.info('the value of the deviceInfo buildHost is :' + buildHostInfo);

    let buildTimeInfo: string = deviceInfo.buildTime;
    console.info('the value of the deviceInfo buildTime is :' + buildTimeInfo);

    let buildRootHashInfo: string = deviceInfo.buildRootHash;
    console.info('the value of the deviceInfo buildRootHash is :' + buildRootHashInfo);

    let udid: string = deviceInfo.udid;
    console.info('the value of the deviceInfo udid is :' + udid);

    let distributionOSName: string = deviceInfo.distributionOSName
    console.info('the value of the deviceInfo distributionOSName is :' + distributionOSName);

    let distributionOSVersion: string = deviceInfo.distributionOSVersion
    console.info('the value of the deviceInfo distributionOSVersion is :' + distributionOSVersion);

    let distributionOSApiVersion: number = deviceInfo.distributionOSApiVersion
    console.info('the value of the deviceInfo distributionOSApiVersion is :' + distributionOSApiVersion);

    let distributionOSApiName: number = deviceInfo.distributionOSApiName
    console.info('the value of the deviceInfo distributionOSApiName is :' + distributionOSApiName);

    let distributionOSReleaseType: string = deviceInfo.distributionOSReleaseType
    console.info('the value of the deviceInfo distributionOSReleaseType is :' + distributionOSReleaseType);

    let odid: string = deviceInfo.ODID;
    console.info('the value of the deviceInfo odid is :' + odid);

```
