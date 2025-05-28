# @ohos.bundle.bundleManager (bundleManager)

The bundleManager module provides APIs for obtaining application information, including [bundle information](js-apis-bundleManager-bundleInfo.md), [application information](js-apis-bundleManager-applicationInfo.md), [ability information](js-apis-bundleManager-abilityInfo.md), and [ExtensionAbility information](js-apis-bundleManager-extensionAbilityInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## Required Permissions

| Permission                                      | APL    | Description           |
| ------------------------------------------ | ------------ | ------------------|
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | Permission to obtain basic information and other sensitive information about a bundle.|
| ohos.permission.GET_SIGNATURE_INFO | system_basic | Allows an application to obtain the application package signature information.|

For details about the APL, see [Basic Concepts in the Permission Mechanism](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

## BundleFlag

Enumerates the bundle flags, which indicate the type of bundle information to obtain.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                                         | Value        | Description                                                        |
| --------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_BUNDLE_INFO_DEFAULT                       | 0x00000000 | Used to obtain the default bundle information. The obtained information does not contain information about the signature, application, HAP module, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_APPLICATION              | 0x00000001 | Used to obtain the bundle information with application information. The obtained information does not contain information about the signature, HAP module, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_HAP_MODULE               | 0x00000002 | Used to obtain the bundle information with HAP module information. The obtained information does not contain information about the signature, application, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_ABILITY                  | 0x00000004 | Used to obtain the bundle information with ability information. The obtained information does not contain information about the signature, application, ExtensionAbility, or permission. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY        | 0x00000008 | Used to obtain the bundle information with ExtensionAbility information. The obtained information does not contain information about the signature, application, ability, or permission. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION     | 0x00000010 | Used to obtain the bundle information with permission information. The obtained information does not contain information about the signature, application, HAP module, ability, or ExtensionAbility.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_METADATA                 | 0x00000020 | Used to obtain the metadata contained in the application, HAP module, ability, or ExtensionAbility information. It must be used together with **GET_BUNDLE_INFO_WITH_APPLICATION**, **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_DISABLE                  | 0x00000040 | Used to obtain the information about disabled bundles and abilities of a bundle. The obtained information does not contain information about the signature, application, HAP module, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_SIGNATURE_INFO           | 0x00000080 | Used to obtain the bundle information with signature information. The obtained information does not contain information about the application, HAP module, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_MENU<sup>11+</sup>       | 0x00000100 | Used to obtain the bundle information with the file context menu configuration. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_ROUTER_MAP<sup>12+</sup> | 0x00000200 | Used to obtain the bundle information with the router map. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| GET_BUNDLE_INFO_WITH_SKILL<sup>12+</sup>      | 0x00000800 | Used to obtain the bundle information with the skills. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## ExtensionAbilityType

Enumerates the types of ExtensionAbilities.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|-----|
| FORM             | 0   | [FormExtensionAbility](../apis-form-kit/js-apis-app-form-formExtensionAbility.md): provides APIs for widget development.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| WORK_SCHEDULER   | 1   | [WorkSchedulerExtensionAbility](../apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md): enables applications to execute non-real-time tasks when the system is idle.|
| INPUT_METHOD     | 2   | [InputMethodExtensionAbility](../apis-ime-kit/js-apis-inputmethod-extension-ability.md): provides APIs for developing input method applications.|
|<!--DelRow--> SERVICE          | 3   | [ServiceExtensionAbility](js-apis-app-ability-serviceExtensionAbility-sys.md): enables applications to run in the background and provide services.|
| ACCESSIBILITY    | 4   | <!--RP1-->[AccessibilityExtensionAbility](../apis-accessibility-kit/js-apis-application-accessibilityExtensionAbility.md)<!--RP1End-->: provides accessibility for access to and operations on the UI.|
|<!--DelRow--> DATA_SHARE       | 5   | [DataShareExtensionAbility](../apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md): enables applications to read and write data.|
|<!--DelRow--> FILE_SHARE       | 6   | FileShareExtensionAbility: enables file sharing between applications. This ability is reserved and supported only by system applications.|
|<!--DelRow--> STATIC_SUBSCRIBER| 7   | [StaticSubscriberExtensionAbility](../apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md): provides APIs for processing static events, such as the startup event.|
|<!--DelRow--> WALLPAPER        | 8   | WallpaperExtensionAbility: provides APIs to implement the home screen wallpaper. This ability is reserved and supported only by system applications.|
| BACKUP           |  9  | [BackupExtensionAbility](../apis-core-file-kit/js-apis-application-backupExtensionAbility.md): provides APIs to implement application data backup and restore.|
|<!--DelRow--> WINDOW     |  10 | [WindowExtensionAbility](../apis-arkui/js-apis-application-windowExtensionAbility-sys.md): allows system applications to display UIs of other applications.|
| ENTERPRISE_ADMIN |  11 | [EnterpriseAdminExtensionAbility](../apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md): provides APIs for processing enterprise management events, such as application installation events on devices and events indicating too many incorrect screen-lock password attempts.|
|<!--DelRow--> THUMBNAIL        | 13  | ThumbnailExtensionAbility: provides thumbnails for files. This ability is reserved and supported only by system applications.|
|<!--DelRow--> PREVIEW          | 14  | PreviewExtensionAbility: provides APIs for file preview so that other applications can be embedded and displayed in the current application. This ability is reserved and supported only by system applications.|
|<!--DelRow--> PRINT<sup>10+</sup> | 15 | PrintExtensionAbility: provides APIs for printing images. This ability is supported only by system applications.|
| SHARE<sup>10+</sup> | 16 | [ShareExtensionAbility](js-apis-app-ability-shareExtensionAbility.md): provides sharing service templates based on UIExtensionAbilities.|
|<!--DelRow--> PUSH<sup>10+</sup> | 17 | PushExtensionAbility: provides APIs for pushing scenario-specific messages. This ability is reserved and supported only by system applications.|
|<!--DelRow--> DRIVER<sup>10+</sup> | 18 | [DriverExtensionAbility](../apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md): provides APIs for the peripheral driver. This ability is supported only by system applications.|
| ACTION<sup>10+</sup> | 19 | [ActionExtensionAbility](js-apis-app-ability-actionExtensionAbility.md): provides custom action service templates based on UIExtensionAbilities.|
|<!--DelRow--> ADS_SERVICE<sup>11+</sup> | 20 | AdsServiceExtensionAbility: provides background customized ad services for external systems. This ability is supported only by system applications.|
| EMBEDDED_UI<sup>12+</sup> | 21 | [EmbeddedUIExtensionAbility](js-apis-app-ability-embeddedUIExtensionAbility.md): provides ExtensionAbilities for the embeddable UI across process.|
| INSIGHT_INTENT_UI<sup>12+</sup> | 22 | **InsightIntentUIExtensionAbility**: provides APIs that enable applications to be called by Celia intents so as to be displayed in windows.|
| FENCE<sup>18+</sup> | 24 | [FenceExtensionAbility](../apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md): provides geofence-related capabilities. It inherits from **ExtensionAbility**.|
| ASSET_ACCELERATION<sup>18+</sup> | 26 | **AssetAccelerationExtensionAbility**: provides the capability of pre-downloading background resources when the device is idle.|
| DISTRIBUTED<sup>18+</sup> | 28 | [DistributedExtensionAbility](../apis-distributedservice-kit/js-apis-distributedExtensionAbility.md): provides DistributedExtensionAbility capabilities and lifecycle callbacks for creation, destruction, and connection of DistributedExtensionAbilities.|
| UNSPECIFIED      | 255 | The ability type is not specified. <!--Del-->It can be used in [queryExtensionAbilityInfo](js-apis-bundleManager-sys.md#bundlemanagerqueryextensionabilityinfo) to obtain ExtensionAbilities of all types.<!--DelEnd-->|


## PermissionGrantState

Enumerates the permission grant states.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| PERMISSION_DENIED|  -1 | Permission denied.|
| PERMISSION_GRANTED |  0  |  Permission granted. |

## SupportWindowMode

Enumerates the window modes supported by the ability.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| FULL_SCREEN      | 0   | A window in full-screen mode is supported.|
| SPLIT            | 1   | A window in split-screen mode is supported.|
| FLOATING         | 2   | A floating window is supported.  |

## LaunchType

Enumerates the launch types of the ability.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| SINGLETON        | 0   | The ability can have only one instance.|
| MULTITON         | 1   | The ability can have multiple instances.|
| SPECIFIED        | 2   | The ability can have one or multiple instances, depending on the internal service of the ability.|

## AbilityType

Enumerates the types of abilities.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

|  Name  | Value  |                            Description                           |
| :-----: | ---- | :--------------------------------------------------------: |
| PAGE    | 1    | Ability that has the UI. FA developed using the Page template to provide the capability of interacting with users.       |
| SERVICE | 2    | Ability of the background service type, without the UI. PA developed using the Service template to provide the capability of running tasks in the background. |
|  DATA   | 3    | PA developed using the Data template to provide unified data access for external systems.|

## DisplayOrientation

Enumerates the display orientations of the ability. This enum applies only to the ability using the Page template.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                              |Value|Description|
|:----------------------------------|---|---|
| UNSPECIFIED                        |0 |Unspecified. The orientation is determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LANDSCAPE                          |1 |Landscape.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PORTRAIT                           |2 |Portrait.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| FOLLOW_RECENT                      |3 |The last display orientation is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LANDSCAPE_INVERTED                 |4 |Reverse landscape.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PORTRAIT_INVERTED                  |5 |Reverse portrait.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION                      |6 |Automatically rotates when the sensor changes to landscape or portrait mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_LANDSCAPE            |7 |Automatically rotates when the sensor changes to landscape mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_PORTRAIT             |8 |Automatically rotates when the sensor changes to portrait mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_RESTRICTED           |9 |Switched-determined auto rotation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_LANDSCAPE_RESTRICTED |10|Switched-determined auto rotation in the horizontal direction.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_PORTRAIT_RESTRICTED  |11|Switched-determined auto rotation in the vertical direction.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LOCKED                             |12|Locked.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_UNSPECIFIED<sup>12+</sup> |13|Auto rotation controlled by the switch and determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FOLLOW_DESKTOP<sup>12+</sup> |14|Following the orientation of the home screen.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## CompatiblePolicy<sup>10+</sup>

Defines the version compatibility type of the shared library.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                  | Value  | Description                            |
| ---------------------- | ---- | -------------------------------- |
| BACKWARD_COMPATIBILITY | 1    | The shared library is backward compatible.|

## ModuleType

Enumerates the module types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name   | Value  | Description                |
| ------- | ---- | -------------------- |
| ENTRY   | 1    | Main module of and entry to the application, providing the basic application functionality.  |
| FEATURE | 2    | Dynamic feature module of the application, extending the application functionality. This type of HAP can be installed based on user needs and device types.|
| SHARED  | 3    | [Dynamic shared library](../../quick-start/in-app-hsp.md) of the application. |

## BundleType

Enumerates the bundle types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name          | Value  | Description           |
| -------------- | ---- | --------------- |
| APP            | 0    | The bundle is an application.   |
| ATOMIC_SERVICE | 1    | The bundle is an atomic service.|

## MultiAppModeType<sup>12+</sup>
Enumerates the types of the multi-app mode.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| UNSPECIFIED|  0 | Unspecified. It is the default value of [multiAppMode](../../quick-start/app-configuration-file.md#multiappmode).|
| MULTI_INSTANCE |  1  | [Multi-instance mode](../../quick-start/multiInstance.md). A resident process does not support this value. |
| APP_CLONE |  2  |  [App clone mode](../../quick-start/app-clone.md) |

## bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: number): Promise\<BundleInfo>

Obtains the bundle information based on the given bundle flags. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
// Obtain the bundle information, which contains the application information including a metadata array.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;

try {
  bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
    hilog.info(0x0000, 'testTag', 'getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getBundleInfoForSelf failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfoForSelf failed: %{public}s', message);
}
```

## bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given bundle flags. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the information is successfully obtained, **err** is **null** and **data** is the bundle information of the current application. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
// Obtain the bundle information, which contains the application information including permissions.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_ABILITY | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;

try {
  bundleManager.getBundleInfoForSelf(bundleFlags, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getBundleInfoForSelf failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getBundleInfoForSelf successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfoForSelf failed: %{public}s', message);
}
```

## bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string\>\>): void

Obtains the JSON string array of the current application's configuration file based on the given module name, ability name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager module](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName   | string                        | Yes  | Module name.                                    |
| abilityName  | string                        | Yes  | Name of the UIAbility component.                                   |
| metadataName | string                        | Yes  | [Metadata name](../../quick-start/module-configuration-file.md#metadata) of the UIAbility component, that is, **name** of the **metadata** tag under **abilities** in the **module.json5** file.                                 |
| callback     | AsyncCallback<Array\<string>> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the information is successfully obtained, **err** is **null** and **data** is **Array\<string>**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                            |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let abilityName = 'EntryAbility';
let metadataName = 'ability_metadata';

try {
  bundleManager.getProfileByAbility(moduleName, abilityName, metadataName, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getProfileByAbility successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', message);
}
```

## bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise\<Array\<string\>\>

Obtains the JSON string array of the current application's configuration file based on the given module name, ability name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API uses a promise to return the result.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager module](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                      |
| ------------ | ------ | ---- | -------------------------- |
| moduleName   | string | Yes  | Module name.  |
| abilityName  | string | Yes  | Name of the UIAbility component. |
| metadataName | string | No  | Metadata name of the UIAbility component, that is, **name** of the **metadata** tag under **abilities** in the **module.json5** file. The default value is null.|

**Return value**

| Type                   | Description                           |
| ----------------------- | ------------------------------- |
| Promise<Array\<string>> | Promise used to return the array of JSON strings obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                            |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
  // Obtain the JSON string array of the configuration file based on the module name and ability name.
  bundleManager.getProfileByAbility(moduleName, abilityName).then((data) => {
    hilog.info(0x0000, 'testTag', 'getProfileByAbility successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let abilityName = 'EntryAbility';
let metadataName = 'ability_metadata';

try {
  // Obtain the JSON string array of the current application's configuration file based on the module name, ability name, and metadata name.
  bundleManager.getProfileByAbility(moduleName, abilityName, metadataName).then((data) => {
    hilog.info(0x0000, 'testTag', 'getProfileByAbility successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', message);
}
```

## bundleManager.getProfileByAbilitySync<sup>10+</sup>

getProfileByAbilitySync(moduleName: string, abilityName: string, metadataName?: string): Array\<string\>

Obtains the JSON string array of the current application's configuration file based on the given module name, ability name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API returns the result synchronously. The result value is a string array.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager module](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                      |
| ------------ | ------ | ---- | -------------------------- |
| moduleName   | string | Yes  | Module name.  |
| abilityName  | string | Yes  | Name of the UIAbility component. |
| metadataName | string | No  | Metadata name of the UIAbility component, that is, **name** of the **metadata** tag under **abilities** in the **module.json5** file. The default value is null.|

**Return value**

| Type                   | Description                           |
| ----------------------- | ------------------------------- |
| Array\<string> | An array of JSON strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                            |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
  // Obtain the JSON string array of the configuration file based on the module name and ability name.
  let data = bundleManager.getProfileByAbilitySync(moduleName, abilityName);
  hilog.info(0x0000, 'testTag', 'getProfileByAbilitySync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbilitySync failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName: string = 'entry';
let abilityName: string = 'EntryAbility';
let metadataName: string = 'ability_metadata';

try {
  // Obtain the JSON string array of the configuration file based on the module name, ability name, and metadata name.
  let data = bundleManager.getProfileByAbilitySync(moduleName, abilityName, metadataName);
  hilog.info(0x0000, 'testTag', 'getProfileByAbilitySync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbilitySync failed. Cause: %{public}s', message);
}
```

## bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string\>\>): void

Obtains the JSON string array of the current application's configuration file based on the given module name, ExtensionAbility name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager module](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type                         | Mandatory| Description                                                        |
| -------------------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName           | string                        | Yes  | Module name.                                  |
| extensionAbilityName | string                        | Yes  | Name of the ExtensionAbility component.                        |
| metadataName         | string                        | Yes  | Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under **extensionAbilities** in the **module.json5** file.                                |
| callback             | AsyncCallback<Array\<string>> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the information is successfully obtained, **err** is **null** and **data** is **Array\<string>**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'ability_metadata';

try {
  bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbility successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed: %{public}s', message);
}
```

## bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise\<Array\<string\>\>

Obtains the JSON string array of the current application's configuration file based on the given module name, ExtensionAbility name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API uses a promise to return the result.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager module](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type  | Mandatory| Description                              |
| -------------------- | ------ | ---- | ---------------------------------- |
| moduleName           | string | Yes  | Module name.          |
| extensionAbilityName | string | Yes  | Name of the ExtensionAbility component.|
| metadataName         | string | No  | Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under **abilities** in the **module.json5** file. The default value is null.        |

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Promise<Array\<string>> | Promise used to return the array of JSON strings obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'ability_metadata';

try {
  bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName).then((data) => {
    hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbility successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed. Cause: %{public}s', message);
}

try {
  bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName).then((data) => {
    hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbility successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed. Cause: %{public}s', message);
}
```

## bundleManager.getProfileByExtensionAbilitySync<sup>10+</sup>

getProfileByExtensionAbilitySync(moduleName: string, extensionAbilityName: string, metadataName?: string): Array\<string\>

Obtains the JSON string array of the current application's configuration file based on the given module name, ExtensionAbility name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API returns the result synchronously. The result value is a string array.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager module](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type  | Mandatory| Description                              |
| -------------------- | ------ | ---- | ---------------------------------- |
| moduleName           | string | Yes  | Module name.          |
| extensionAbilityName | string | Yes  | Name of the ExtensionAbility component.|
| metadataName         | string | No  | Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under **extensionAbilities** in the **module.json5** file. The default value is null.|

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Array\<string> | An array of JSON strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'ability_metadata';

try {
  let data = bundleManager.getProfileByExtensionAbilitySync(moduleName, extensionAbilityName);
  hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbilitySync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbilitySync failed. Cause: %{public}s', message);
}

try {
  let data = bundleManager.getProfileByExtensionAbilitySync(moduleName, extensionAbilityName, metadataName);
  hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbilitySync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbilitySync failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleInfoForSelfSync<sup>10+</sup>

getBundleInfoForSelfSync(bundleFlags: number): BundleInfo

Obtains the bundle information of this bundle based on the given bundle flags. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type                                             | Description                |
| ------------------------------------------------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;

try {
  let data = bundleManager.getBundleInfoForSelfSync(bundleFlags);
  hilog.info(0x0000, 'testTag', 'getBundleInfoForSelfSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfoForSelfSync failed: %{public}s', message);
}
```

## bundleManager.canOpenLink<sup>12+</sup>

canOpenLink(link: string): boolean

Checks whether a link can be opened. The scheme of the specified link must be configured in the **querySchemes** field of the [module.json5 file](../../quick-start/module-configuration-file.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| link | string | Yes  | Link to check.|

**Return value**

| Type                                             | Description                |
| ------------------------------------------------- | -------------------- |
| boolean | **true**: The link can be opened.<br>**false**: The link cannot be opened.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700055 | The specified link is invalid.                      |
| 17700056 | The scheme of the specified link is not in the querySchemes.        |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  let link = 'welink://';
  let data = bundleManager.canOpenLink(link);
  hilog.info(0x0000, 'testTag', 'canOpenLink successfully: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'canOpenLink failed: %{public}s', message);
}
```

## bundleManager.getLaunchWant<sup>13+</sup>

getLaunchWant(): Want

Obtains the **Want** parameter used to start this application.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                               | Description                                       |
| ----------------------------------- | ------------------------------------------- |
| [Want](js-apis-app-ability-want.md) | **Want** object that contains the bundle name and ability name.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 17700072 | The launch want is not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  let want = bundleManager.getLaunchWant();
  hilog.info(0x0000, 'testTag', 'getLaunchWant ability name: %{public}s', want.abilityName);
  hilog.info(0x0000, 'testTag', 'getLaunchWant bundle name: %{public}s', want.bundleName);
} catch (error) {
  let message = (error as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getLaunchWant failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the information is successfully obtained, **err** is **null** and **data** is the bundle information. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
// Obtain the bundle information, which contains the ability information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_ABILITY;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

```ts
// Obtain the bundle information, which contains the application information including metadata.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given bundle name and bundle flags. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the information is successfully obtained, **err** is **null** and **data** is the bundle information. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
// Obtain the bundle information with the ExtensionAbility information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<BundleInfo>

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.      |
| userId      | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
// Obtain the bundle information with the application and signature information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);
}

```

## bundleManager.getBundleInfoSync<sup>14+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number, userId: number): BundleInfo

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | Yes  | Bundle name.                                |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).             |

**Return value**

| Type      | Description                |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);
}
```

## bundleManager.getBundleInfoSync<sup>14+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo

Obtains the bundle information based on the given bundle name and bundle flags. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                                  |
| ----------- | --------------------- | ---- | ------------------------------------------------------ |
| bundleName  | string                | Yes  | Bundle name.                            |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type                                             | Description                |
| ------------------------------------------------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);
}
```

## bundleManager.getBundleNameByUid<sup>14+</sup>

getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void

Obtains the bundle name based on the given UID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                 | Yes  | UID of the application.                                           |
| callback | AsyncCallback\<string> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the information is successfully obtained, **err** is **null** and **data** is the bundle name. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', message);
}
```

## bundleManager.getBundleNameByUid<sup>14+</sup>

getBundleNameByUid(uid: number): Promise\<string>

Obtains the bundle name based on the given UID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------ |
| uid  | number | Yes  | UID of the application.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| Promise\<string> | Promise used to return the bundle name obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleNameByUidSync<sup>14+</sup>

getBundleNameByUidSync(uid: number): string

Obtains the bundle name based on the given UID. This API returns the result synchronously.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------ |
| uid  | number | Yes  | UID of the application.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| string | Bundle name obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005;
try {
    let data = bundleManager.getBundleNameByUidSync(uid);
    hilog.info(0x0000, 'testTag', 'getBundleNameByUidSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUidSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppCloneIdentity<sup>14+</sup>

getAppCloneIdentity(uid: number): Promise\<AppCloneIdentity>;

Obtains the bundle name and clone index of a cloned application based on the given UID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------|
|    uid     | number |  Yes |     UID of the application.     |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[AppCloneIdentity](js-apis-bundleManager-bundleInfo.md#appcloneidentity14)> | Promise used to return \<AppCloneIdentity>.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005;

try {
    bundleManager.getAppCloneIdentity(uid).then((res) => {
        hilog.info(0x0000, 'testTag', 'getAppCloneIdentity res = %{public}s', JSON.stringify(res));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppCloneIdentity failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppCloneIdentity failed. Cause: %{public}s', message);
}
```

## bundleManager.getSignatureInfo<sup>18+</sup>

getSignatureInfo(uid: number): SignatureInfo

Obtains the [signature information](./js-apis-bundleManager-bundleInfo.md#signatureinfo) of an application based on the given UID.

**Required permissions**: ohos.permission.GET_SIGNATURE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------ |
| uid  | number | Yes  | UID of the application.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| [SignatureInfo](./js-apis-bundleManager-bundleInfo.md#signatureinfo) | **SignatureInfo** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005; // Replace uid with the UID of the corresponding application.
try {
    let data = bundleManager.getSignatureInfo(uid);
    hilog.info(0x0000, 'testTag', 'getSignatureInfo successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getSignatureInfo failed. Cause: %{public}s', message);
}
```

## ApplicationInfo

type ApplicationInfo = _ApplicationInfo

Defines the application information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1) | Application information.|

## ModuleMetadata<sup>10+</sup>

type ModuleMetadata = _ModuleMetadata

Defines the metadata of a module.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ModuleMetadata](js-apis-bundleManager-applicationInfo.md#ModuleMetadata10) | Metadata of the module.|

## Metadata

type Metadata = _Metadata

Defines the metadata.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_Metadata](js-apis-bundleManager-metadata.md#metadata) | Metadata.|

## BundleInfo

type BundleInfo = _BundleInfo.BundleInfo

Defines the bundle information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo) | Bundle information.|


## UsedScene

type UsedScene = _BundleInfo.UsedScene

Defines the use scenario and timing for using the permission.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.UsedScene](js-apis-bundleManager-bundleInfo.md#usedscene) | Use scenario and timing for using the permission.|

## ReqPermissionDetail

type ReqPermissionDetail = _BundleInfo.ReqPermissionDetail

Defines the detailed information of the permissions to request from the system.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.ReqPermissionDetail](js-apis-bundleManager-bundleInfo.md#reqpermissiondetail) | Detailed information of the permissions to request from the system.|

## SignatureInfo

type SignatureInfo = _BundleInfo.SignatureInfo

Defines the signature information of the bundle.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.SignatureInfo](js-apis-bundleManager-bundleInfo.md#signatureinfo) | Signature information of the bundle.|

## HapModuleInfo

type HapModuleInfo = _HapModuleInfo.HapModuleInfo

Defines the module information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md#hapmoduleinfo-1) | Module information.|

## PreloadItem

type PreloadItem = _HapModuleInfo.PreloadItem

Defines the preloaded module information in the atomic service.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.PreloadItem](js-apis-bundleManager-hapModuleInfo.md#preloaditem) | Preloaded module information in the atomic service.|

## Dependency

type Dependency = _HapModuleInfo.Dependency

Defines the information about the dynamic shared libraries on which the module depends.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.Dependency](js-apis-bundleManager-hapModuleInfo.md#dependency) | Information about the dynamic shared libraries on which the module depends.|

## RouterItem<sup>12+</sup>

type RouterItem = _HapModuleInfo.RouterItem

Defines the router table configuration of the module.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.RouterItem](js-apis-bundleManager-hapModuleInfo.md#routeritem12) | Router table configuration of the module.|

## DataItem<sup>12+</sup>

type DataItem = _HapModuleInfo.DataItem

Defines the user-defined data in the routing table configuration of the module.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.DataItem](js-apis-bundleManager-hapModuleInfo.md#dataitem12) | User-defined data in the routing table configuration of the module.|

## AbilityInfo

type AbilityInfo = _AbilityInfo.AbilityInfo

Defines the ability information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_AbilityInfo.AbilityInfo](js-apis-bundleManager-abilityInfo.md#abilityinfo-1) |Ability information.|

## WindowSize

type WindowSize = _AbilityInfo.WindowSize

Defines the window size.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_AbilityInfo.WindowSize](js-apis-bundleManager-abilityInfo.md#windowsize) |Window size.|


## ExtensionAbilityInfo

type ExtensionAbilityInfo = _ExtensionAbilityInfo.ExtensionAbilityInfo

Defines the ExtensionAbility information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ExtensionAbilityInfo.ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md#extensionabilityinfo-1) |ExtensionAbility information.|

## ElementName

type ElementName = _ElementName

Defines the element name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ElementName](js-apis-bundleManager-elementName.md#elementname-1) |Element name.|

## Skill<sup>12+</sup>

type Skill = _Skill.Skill

Defines the skill information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_Skill.Skill](js-apis-bundleManager-skill.md#skill-1) |Skill information.|

## SkillUrl<sup>12+</sup>

type SkillUrl = _Skill.SkillUri

Defines the SkillUri information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_Skill.SkillUri](js-apis-bundleManager-skill.md#skilluri) |SkillUri information.|

## AppCloneIdentity<sup>15+</sup>

type AppCloneIdentity = _BundleInfo.AppCloneIdentity

Describes the identity information of an application clone.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.AppCloneIdentity](js-apis-bundleManager-bundleInfo.md#appcloneidentity14) |Identity information of an application clone.|
