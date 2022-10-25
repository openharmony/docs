# PackInfo

The **PackInfo** module provides the bundle package information, which can be obtained using [bundle.getBundlePackInfo](js-apis-Bundle.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundlePackFlag

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name              | Value        | Description                              |
| ------------------ | ---------- | ---------------------------------- |
| GET_PACK_INFO_ALL  | 0x00000000 | All information about the package.   |
| GET_PACKAGES       | 0x00000001 | Package information about the package.|
| GET_BUNDLE_SUMMARY | 0x00000002 | Bundle summary of the package. |
| GET_MODULE_SUMMARY | 0x00000004 | Module summary of the package. |

## BundlePackInfo

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name    | Type                                   | Readable| Writable| Description                         |
| -------- | --------------------------------------- | ---- | ---- | ----------------------------- |
| packages | Array\<[PackageConfig](#packageconfig)> | Yes  | No  | Package configuration information.      |
| summary  | [PackageSummary](#packagesummary)       | Yes  | No  | Package summary.|

## PackageConfig

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name               | Type          | Readable| Writable| Description                                                        |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| deviceType          | Array\<string> | Yes  | No  | Device types supported.                                          |
| name                | string         | Yes  | No  | Package name.                                                  |
| moduleType          | string         | Yes  | No  | Module type.                                            |
| deliveryWithInstall | boolean        | Yes  | No  | Whether the HAP file will be installed when the user installs the application. The value **true** means that the HAP file will be automatically installed when the user installs the application, and **false** means the opposite.|

## PackageSummary 

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name   | Type                                         | Readable| Writable| Description                |
| ------- | --------------------------------------------- | ---- | ---- | -------------------- |
| app     | [BundleConfigInfo](#bundleconfiginfo)         | Yes  | No  | Bundle configuration information.      |
| modules | Array\<[ModuleConfigInfo](#moduleconfiginfo)> | Yes  | No  | Module configuration information.|

## BundleConfigInfo

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name      | Type               | Readable| Writable| Description                              |
| ---------- | ------------------- | ---- | ---- | ---------------------------------- |
| bundleName | string              | Yes  | No  | Bundle name of an application. It uniquely identifies the application.|
| version    | [Version](#version) | Yes  | No  | Bundle version.                        |

## ModuleConfigInfo

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name              | Type                                             | Readable| Writable| Description                              |
| ------------------ | ------------------------------------------------- | ---- | ---- | ---------------------------------- |
| apiVersion         | [ApiVersion](#apiversion)                         | Yes  | No  | API version of the module.                 |
| deviceType         | Array\<string>                                    | Yes  | No  | Device type of the module.                |
| distro             | [ModuleDistroInfo](#moduledistroinfo)             | Yes  | No  | Distribution information of the module.                |
| abilities          | Array\<[ModuleAbilityInfo](#moduleabilityinfo)>   | Yes  | No  | Ability information of the module.              |
| extensionAbilities | Array\<[ExtensionAbilities](#extensionabilities)> | Yes  | No  | Extension ability information of the module.|

## ModuleDistroInfo 

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name               | Type   | Readable| Writable| Description                                                        |
| ------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| mainAbility         | string  | Yes  | No  | Name of the main ability.                                            |
| deliveryWithInstall | boolean | Yes  | No  | Whether the HAP file will be installed when the user installs the application. The value **true** means that the HAP file will be automatically installed when the user installs the application, and **false** means the opposite.|
| installationFree    | boolean | Yes  | No  | Whether the HAP file supports the installation-free feature. The value **true** means that the HAP file supports the installation-free feature and meets installation-free constraints, and **false** means the opposite.|
| moduleName          | string  | Yes  | No  | Module name.                                                |
| moduleType          | string  | Yes  | No  | Module type.                                                |

## ModuleAbilityInfo 

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name   | Type                                       | Readable| Writable| Description                                                        |
| ------- | ------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| name    | string                                      | Yes  | No  | Logical name of the ability. The name must be unique in the application.           |
| label   | string                                      | Yes  | No  | Name of the ability displayed to users. The value is a resource index to names in multiple languages.|
| visible | boolean                                     | Yes  | No  | Whether the ability can be called by other applications. The value **true** means that the ability can be called by other applications, and **false** means the opposite.|
| forms   | Array\<[AbilityFormInfo](#abilityforminfo)> | Yes  | No  | Widget information.                                                  |

## ExtensionAbilities

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name | Type                                       | Readable| Writable| Description                                                        |
| ----- | ------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| forms | Array\<[AbilityFormInfo](#abilityforminfo)> | Yes  | No  | Specification of the widget. A widget is a brief view of an application that is embedded on the home screen to receive periodical updates.|

## AbilityFormInfo

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name               | Type          | Readable| Writable| Description                                                        |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| name                | string         | Yes  | No  | Widget name.                                           |
| type                | string         | Yes  | No  | Widget type.                                           |
| updateEnabled       | boolean        | Yes  | No  | Whether the widget supports periodical update. The value **true** means that the widget supports periodical update, and **false** means the opposite.|
| scheduledUpdateTime | string         | Yes  | No  | Scheduled time to update the widget. The value is in 24-hour format and accurate to the minute.        |
| updateDuration      | number         | Yes  | No  | Interval to update the widget. The unit is 30 minutes. The value is a multiple of 30. A widget can be updated periodically, either at a specified interval (**updateDuration**) or at the scheduled time (**scheduledUpdateTime**). If both are configured, **updateDuration** takes precedence.|
| supportDimensions   | Array\<number> | Yes  | No  | Dimensions of the widget. The value can be **1\*2**, **2\*2**, **2\*4**, **4\*4**, or a combination of these options. At least one option must be specified when defining the widget.|
| defaultDimension    | number         | Yes  | No  | Default dimensions of the widget. The value must be available in the **supportDimensions** array of the widget.|

## ApiVersion

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name       | Type  | Readable| Writable| Description                |
| ----------- | ------ | ---- | ---- | -------------------- |
| releaseType | string | Yes  | No  | Name of the API version.        |
| compatible  | number | Yes  | No  | Minimum API version.|
| target      | numbe  | Yes  | No  | Target API version.        |

## Version

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                    | Type  | Readable| Writable| Description                                                        |
| ------------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| minCompatibleVersionCode | number | Yes  | No  | Minimum compatible version of the application. It is used to check whether the application is compatible with a version on other devices in the cross-device scenario. The value is a 32-bit non-negative integer.|
| name                     | string | Yes  | No  | Application version number visible to users.                      |
| code                     | number | Yes  | No  | Application version number used only for application management. The value is a 32-bit non-negative integer. It is used only to determine whether a version is later than another version. A larger value indicates a later version.|
