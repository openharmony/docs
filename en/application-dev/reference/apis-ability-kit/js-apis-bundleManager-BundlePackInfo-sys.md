# BundlePackInfo (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides information in the **pack.info** file. The information can be obtained using [freeInstall.getBundlePackInfo](js-apis-freeInstall-sys.md#getbundlepackinfo).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import { freeInstall } from '@kit.AbilityKit';
```

## BundlePackInfo

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name    | Type                                   | Read-Only| Optional| Description                     |
| -------- | --------------------------------------- | ---- | ---- | ------------------------- |
| packages | Array\<[PackageConfig](#packageconfig)> | Yes  | No  | Package configuration information in the **pack.info** file.      |
| summary  | [PackageSummary](#packagesummary)       | Yes  | No  | Package summary information in the **pack.info** file.|

## PackageConfig

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name               | Type          | Read-Only| Optional| Description                                                        |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| deviceTypes          | Array\<string> | Yes  | No  | Device types supported by the bundle.                                      |
| name                | string         | Yes  | No  | Bundle name.                                                  |
| moduleType          | string         | Yes  | No  | Module type of the bundle.                                            |
| deliveryWithInstall | boolean        | Yes  | No  | Whether it should be installed together with the application. **true** if it should be installed together with the application, **false** otherwise.|

## PackageSummary

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name   | Type                                         | Read-Only| Optional| Description                |
| ------- | --------------------------------------------- | ---- | ---- | -------------------- |
| app     | [BundleConfigInfo](#bundleconfiginfo)         | Yes  | No  | Bundle configuration information.      |
| modules | Array\<[ModuleConfigInfo](#moduleconfiginfo)> | Yes  | No  | Module configuration information of the bundle.|

## BundleConfigInfo

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name      | Type               | Read-Only| Optional| Description                                  |
| ---------- | ------------------- | ---- | ---- | -------------------------------------- |
| bundleName | string              | Yes  | No  | Bundle name. It uniquely identifies an application.|
| version    | [Version](#version) | Yes  | No  | Bundle version.                            |

## ModuleConfigInfo

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name              | Type                                             | Read-Only| Optional| Description                              |
| ------------------ | ------------------------------------------------- | ---- | ---- | ---------------------------------- |
| mainAbility | string | Yes| No| Name of the main ability.|
| apiVersion         | [ApiVersion](#apiversion)                         | Yes  | No  | API version of the module.                 |
| deviceTypes         | Array\<string>                                    | Yes  | No  | Device types supported by the module.                |
| distro             | [ModuleDistroInfo](#moduledistroinfo)             | Yes  | No  | Distribution information of the module.                |
| abilities          | Array\<[ModuleAbilityInfo](#moduleabilityinfo)>   | Yes  | No  | Ability information of the module.              |
| extensionAbilities | Array\<[ExtensionAbility](#extensionability)> | Yes  | No  | ExtensionAbility information of the module.|

## ModuleDistroInfo

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name               | Type   | Read-Only| Optional| Description                                                        |
| ------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| deliveryWithInstall | boolean | Yes  | No  | Whether it should be installed together with the application. **true** if it should be installed together with the application, **false** otherwise.|
| installationFree    | boolean | Yes  | No  | Whether the HAP file supports the installation-free feature. **true** if the HAP file supports the installation-free feature and meets installation-free constraints, **false** otherwise.|
| moduleName          | string  | Yes  | No  | Module name.                                                |
| moduleType          | string  | Yes  | No  | Module type.                                                |

## ModuleAbilityInfo

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name   | Type                                       | Read-Only| Optional| Description                                                        |
| ------- | ------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| name    | string                                      | Yes  | No  | Name of the ability. The name must be unique in the bundle.           |
| label   | string                                      | Yes  | No  | Name of the ability displayed to users. The value is a resource index to names in multiple languages.|
| exported | boolean                                     | Yes  | No  | Whether the ability can be invoked by other applications. **true** if it can be invoked by other applications, **false** otherwise.|
| forms   | Array\<[AbilityFormInfo](#abilityforminfo)> | Yes  | No  | Widget information.                                                  |

## ExtensionAbility

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name | Type                                       | Read-Only| Optional| Description                                                        |
| ----- | ------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| name | string | Yes| No| Name of the ExtensionAbility.|
| forms | Array\<[AbilityFormInfo](#abilityforminfo)> | Yes  | No  | Widget information.|

## AbilityFormInfo

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name               | Type          | Read-Only| Optional| Description                                                        |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| name                | string         | Yes  | No  | Widget name.                                           |
| type                | string         | Yes  | No  | Widget type.                                           |
| updateEnabled       | boolean        | Yes  | No  | Whether the widget supports periodic update. **true** if the widget supports periodic update, **false** otherwise.|
| scheduledUpdateTime | string         | Yes  | No  | Scheduled time to update the widget. The value is in 24-hour format and accurate to the minute.        |
| updateDuration      | number         | Yes  | No  | Interval to update the widget. The unit is 30 minutes. The value is a multiple of 30. A widget can be updated at a specified interval (**updateDuration**) or at the scheduled time (**scheduledUpdateTime**). If both are configured, **updateDuration** takes precedence.|
| supportDimensions   | Array\<string> | Yes  | No  | Dimensions of the widget. The value can be **1\*2**, **2\*2**, **2\*4**, **4\*4**, or a combination of these options. At least one option must be specified when defining the widget.|
| defaultDimension    | string         | Yes  | No  | Default dimensions of the widget. The value must be available in the **supportDimensions** array of the widget.|

## ApiVersion

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name       | Type  | Read-Only| Optional| Description                |
| ----------- | ------ | ---- | ---- | -------------------- |
| releaseType | string | Yes  | No  | Name of the API version.        |
| compatible  | number | Yes  | No  | Minimum API version.|
| target      | number | Yes  | No  | Target API version.        |

## Version

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name                    | Type  | Read-Only| Optional| Description                                                        |
| ------------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| minCompatibleVersionCode | number | Yes  | No  | Minimum compatible version of the bundle. It is used to check whether the bundle is compatible with a version on other devices in the cross-device scenario. The value is a 32-bit non-negative integer.|
| name                     | string | Yes  | No  | Version number of the bundle visible to users.                      |
| code                     | number | Yes  | No  | Version number of the bundle used only for bundle management. The value is a 32-bit non-negative integer. It is used only to determine whether a version is later than another version. A larger value indicates a later version.|
