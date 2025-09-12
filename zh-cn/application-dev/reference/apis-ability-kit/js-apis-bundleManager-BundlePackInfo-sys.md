# BundlePackInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

应用包信息，通过接口[freeInstall.getBundlePackInfo](js-apis-freeInstall-sys.md#getbundlepackinfo)获取。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```js
import { freeInstall } from '@kit.AbilityKit';
```

## BundlePackInfo

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称     | 类型                                    | 只读 | 可选 | 说明                      |
| -------- | --------------------------------------- | ---- | ---- | ------------------------- |
| packages | Array\<[PackageConfig](#packageconfig)> | 是   | 否   | pack.info的包信息。       |
| summary  | [PackageSummary](#packagesummary)       | 是   | 否   | pack.info中的包摘要信息。 |

## PackageConfig

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称                | 类型           | 只读 | 可选 | 说明                                                         |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| deviceTypes          | Array\<string> | 是   | 否   | 包支持的设备类型。                                       |
| name                | string         | 是   | 否   | 包的名称。                                                   |
| moduleType          | string         | 是   | 否   | 包的module类型。                                             |
| deliveryWithInstall | boolean        | 是   | 否   | 是否跟随应用一起安装。true表示跟随应用一起安装，false表示不跟随应用一起安装。 |

## PackageSummary

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称    | 类型                                          | 只读 | 可选 | 说明                 |
| ------- | --------------------------------------------- | ---- | ---- | -------------------- |
| app     | [BundleConfigInfo](#bundleconfiginfo)         | 是   | 否   | 包的配置信息。       |
| modules | Array\<[ModuleConfigInfo](#moduleconfiginfo)> | 是   | 否   | 包的module配置信息。 |

## BundleConfigInfo

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称       | 类型                | 只读 | 可选 | 说明                                   |
| ---------- | ------------------- | ---- | ---- | -------------------------------------- |
| bundleName | string              | 是   | 否   | 应用Bundle名称，用于标识应用的唯一性。 |
| version    | [Version](#version) | 是   | 否   | 包的版本。                             |

## ModuleConfigInfo

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称               | 类型                                              | 只读 | 可选 | 说明                               |
| ------------------ | ------------------------------------------------- | ---- | ---- | ---------------------------------- |
| mainAbility | string | 是 | 否 | 应用主ability的名称。 |
| apiVersion         | [ApiVersion](#apiversion)                         | 是   | 否   | module的api版本。                  |
| deviceTypes         | Array\<string>                                    | 是   | 否   | module的设备类型。                 |
| distro             | [ModuleDistroInfo](#moduledistroinfo)             | 是   | 否   | module发行版信息。                 |
| abilities          | Array\<[ModuleAbilityInfo](#moduleabilityinfo)>   | 是   | 否   | module包含的ability组件信息。               |
| extensionAbilities | Array\<[ExtensionAbility](#extensionability)> | 是   | 否   | 描述extensionAbilities的配置信息。 |

## ModuleDistroInfo

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称                | 类型    | 只读 | 可选 | 说明                                                         |
| ------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| deliveryWithInstall | boolean | 是   | 否   | 是否跟随应用一起安装。true表示跟随应用一起安装，false表示不跟随应用一起安装。 |
| installationFree    | boolean | 是   | 否   | 表示当前HAP是否支持免安装特性。true表示支持免安装特性，且符合免安装约束，false表示不支持免安装特性。 |
| moduleName          | string  | 是   | 否   | module名称。                                                 |
| moduleType          | string  | 是   | 否   | module类型。                                                 |

## ModuleAbilityInfo

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称    | 类型                                        | 只读 | 可选 | 说明                                                         |
| ------- | ------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| name    | string                                      | 是   | 否   | 表示当前ability的名称，该名称在整个应用要唯一。            |
| label   | string                                      | 是   | 否   | 表示ability对用户显示的名称，标签值配置为该名称的资源索引以支持多语言。 |
| exported | boolean                                     | 是   | 否   | 表示ability是否可以被其它应用调用。true表示可以被其它应用调用，false表示不可以被其它应用调用。 |
| forms   | Array\<[AbilityFormInfo](#abilityforminfo)> | 是   | 否   | 卡片信息。                                                   |

## ExtensionAbility

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称  | 类型                                        | 只读 | 可选 | 说明                                                         |
| ----- | ------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| name | string | 是 | 否 | 表示该ExtensionAbility的名称。 |
| forms | Array\<[AbilityFormInfo](#abilityforminfo)> | 是   | 否   | 表示form卡片的规格，form卡片是可以嵌入桌面上并接收定时更新的应用简要视图。 |

## AbilityFormInfo

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称                | 类型           | 只读 | 可选 | 说明                                                         |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| name                | string         | 是   | 否   | 表示forms的名称。                                            |
| type                | string         | 是   | 否   | 表示forms的类型。                                            |
| updateEnabled       | boolean        | 是   | 否   | 表示该卡片是否支持定时刷新，true表示卡片支持定时刷新，false表示不支持。 |
| scheduledUpdateTime | string         | 是   | 否   | 表示卡片定点刷新的时间，采用24小时计数，精确到分钟。         |
| updateDuration      | number         | 是   | 否   | 表示卡片定时刷新的更新频率，单位为30分钟，取值为30的倍数值。卡片的最高频率为每30分钟刷新一次，和定点刷新二选一，二者都配置的情况下，定时优先。 |
| supportDimensions   | Array\<string> | 是   | 否   | 表示卡片外观规格，取值为“1\*2”，“2\*2”，“2\*4”，“4\*4”，定义卡片时至少要指定一个卡片规格。 |
| defaultDimension    | string         | 是   | 否   | 表示卡片默认外观规格，取值必须在supportDimensions配置的列表中。 |

## ApiVersion

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称        | 类型   | 只读 | 可选 | 说明                 |
| ----------- | ------ | ---- | ---- | -------------------- |
| releaseType | string | 是   | 否   | 版本的名称。         |
| compatible  | number | 是   | 否   | 版本的最小兼容代码。 |
| target      | number | 是   | 否   | 目标版本号。         |

## Version

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称                     | 类型   | 只读 | 可选 | 说明                                                         |
| ------------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| minCompatibleVersionCode | number | 是   | 否   | 能够兼容的最低历史版本号，用于跨设备兼容性判断。该值为32位整型数值，非负整数。 |
| name                     | string | 是   | 否   | 标识版本号的文字描述，用于向用户展示。                       |
| code                     | number | 是   | 否   | 标识应用的版本号，值为32位非负整数。此数字仅用于确定某个版本是否比另一个版本更新，数值越大表示版本越高。 |
