# AppProvisionInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

应用[HarmonyAppProvision配置文件](../../security/app-provision-structure.md)中的信息，可以通过[getAppProvisionInfo](./js-apis-bundleManager-sys.md#bundlemanagergetappprovisioninfo10)获取。

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## AppProvisionInfo

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称                      | 类型   | 只读 | 可选 | 说明                 |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| versionCode              | number | 是   | 否   | 配置文件的版本号。 |
| versionName              | string | 是   | 否   | 配置文件的版本名称。  |
| uuid                     | string | 是   | 否   | 配置文件中的uuid。 |
| type                     | string | 是   | 否   | 配置文件的类型，为debug或者release。 |
| appDistributionType      | string | 是   | 否   | 配置文件中的[分发类型](../../security/app-provision-structure.md)。 |
| validity                 | [Validity](#validity) | 是   | 否   | 配置文件中的有效期。 |
| developerId              | string | 是   | 否   | 配置文件中的开发者ID。 |
| certificate              | string | 是   | 否   | 配置文件中的证书公钥。 |
| apl                      | string | 是   | 否   | 配置文件中的apl字段，为normal、system_basic和system_core其中之一。 |
| issuer                      | string | 是   | 否   | 配置文件中的发行者名称。 |
|appIdentifier<sup>11+</sup>| string         | 是   | 否   | 应用的唯一标识，是AppGallery Connect创建应用时分配的[APP ID](https://developer.huawei.com/consumer/cn/doc/app/agc-help-createharmonyapp-0000001945392297)，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。当需要进行跨设备调试、跨应用交互调试等场景，必须使用手动签名，签名方式的选择具体请参考[使用场景说明](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-signing#section54361623194519)。      |
| organization<sup>12+</sup> | string | 是   | 否   | 应用的组织信息。 |

## Validity

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称                      | 类型   | 只读 | 可选 | 说明                 |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| notBefore                 | number | 是   | 否   | 配置文件的最早有效日期的时间戳。 |
| notAfter                  | number | 是   | 否   | 配置文件的最晚有效日期的时间戳。 |