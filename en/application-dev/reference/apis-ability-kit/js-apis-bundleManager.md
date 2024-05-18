# @ohos.bundle.bundleManager (bundleManager)

The **bundleManager** module provides APIs for querying information about bundles, applications, abilities, ExtensionAbilities, and more.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import bundleManager from '@ohos.bundle.bundleManager';
```

## Enums

### BundleFlag

Enumerates the bundle flags, which indicate the type of bundle information to obtain.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                                     | Value        | Description                                                        |
| ----------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_BUNDLE_INFO_DEFAULT                   | 0x00000000 | Used to obtain the default bundle information. The obtained information does not contain information about the signature, application, HAP module, ability, ExtensionAbility, or permission.|
| GET_BUNDLE_INFO_WITH_APPLICATION          | 0x00000001 | Used to obtain the bundle information with application information. The obtained information does not contain information about the signature, HAP module, ability, ExtensionAbility, or permission.|
| GET_BUNDLE_INFO_WITH_HAP_MODULE           | 0x00000002 | Used to obtain the bundle information with HAP module information. The obtained information does not contain information about the signature, application, ability, ExtensionAbility, or permission.|
| GET_BUNDLE_INFO_WITH_ABILITY              | 0x00000004 | Used to obtain the bundle information with ability information. The obtained information does not contain information about the signature, application, ExtensionAbility, or permission. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.|
| GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY    | 0x00000008 | Used to obtain the bundle information with ExtensionAbility information. The obtained information does not contain information about the signature, application, ability, or permission. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.|
| GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION | 0x00000010 | Used to obtain the bundle information with permission information. The obtained information does not contain information about the signature, application, HAP module, ability, or ExtensionAbility.|
| GET_BUNDLE_INFO_WITH_METADATA             | 0x00000020 | Used to obtain the metadata contained in the application, HAP module, ability, or ExtensionAbility information. It must be used together with **GET_BUNDLE_INFO_WITH_APPLICATION**, **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**.|
| GET_BUNDLE_INFO_WITH_DISABLE              | 0x00000040 | Used to obtain the information about disabled bundles and abilities of a bundle. The obtained information does not contain information about the signature, application, HAP module, ability, ExtensionAbility, or permission.|
| GET_BUNDLE_INFO_WITH_SIGNATURE_INFO       | 0x00000080 | Used to obtain the bundle information with signature information. The obtained information does not contain information about the application, HAP module, ability, ExtensionAbility, or permission.|
| GET_BUNDLE_INFO_WITH_MENU<sup>11+</sup>   | 0x00000100 | Used to obtain the bundle information with the file context menu configuration. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.|
| GET_BUNDLE_INFO_WITH_ROUTER_MAP<sup>12+</sup>   | 0x00000200 | Used to obtain the bundle information with the router map. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.|
| GET_BUNDLE_INFO_WITH_SKILL<sup>12+</sup>   | 0x00000800 | Used to obtain the bundle information with the skills. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**.|

### ExtensionAbilityType

Enumerates the types of ExtensionAbilities.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|-----|
| FORM             | 0   | [FormExtensionAbility](../apis-form-kit/js-apis-app-form-formExtensionAbility.md): provides APIs for widget development.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| WORK_SCHEDULER   | 1   | [WorkSchedulerExtensionAbility](../apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md): enables applications to execute non-real-time tasks when the system is idle.|
| INPUT_METHOD     | 2   | [InputMethodExtensionAbility](../apis-ime-kit/js-apis-inputmethod-extension-ability.md): provides APIs for developing input method applications.|
| SERVICE          | 3   | [ServiceExtensionAbility](js-apis-app-ability-serviceExtensionAbility-sys.md): enables applications to run in the background and provide services.|
| ACCESSIBILITY    | 4   | [AccessibilityExtensionAbility](../apis-accessibility-kit/js-apis-application-accessibilityExtensionAbility.md): provides accessibility for access to and operations on the UI.|
| DATA_SHARE       | 5   | [DataShareExtensionAbility](../apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md): enables applications to read and write data.|
| FILE_SHARE       | 6   | FileShareExtensionAbility: enables file sharing between applications. This ability is reserved.|
| STATIC_SUBSCRIBER| 7   | [StaticSubscriberExtensionAbility](../apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md): provides APIs for processing static events, such as the startup event.|
| WALLPAPER        | 8   | WallpaperExtensionAbility: provides APIs to implement the home screen wallpaper. This ability is reserved.|
| BACKUP           |  9  | [BackupExtensionAbility](../apis-core-file-kit/js-apis-application-backupExtensionAbility.md): provides APIs to implement application data backup and restore.|
| WINDOW           |  10 | [WindowExtensionAbility](../apis-arkui/js-apis-application-windowExtensionAbility-sys.md): allows system applications to display UIs of other applications.|
| ENTERPRISE_ADMIN |  11 | [EnterpriseAdminExtensionAbility](../apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility-sys.md): provides APIs for processing enterprise management events, such as application installation events on devices and events indicating too many incorrect screen-lock password attempts.|
| THUMBNAIL        | 13  | ThumbnailExtensionAbility: provides thumbnails for files. This ability is reserved.|
| PREVIEW          | 14  | PreviewExtensionAbility: provides APIs for file preview so that other applications can be embedded and displayed in the current application. This ability is reserved.|
| PRINT<sup>10+</sup> | 15 | PrintExtensionAbility: provides APIs for printing images. Printing documents is not supported yet.|
| SHARE<sup>10+</sup> | 16 | [ShareExtensionAbility](js-apis-app-ability-shareExtensionAbility.md): provides sharing service templates based on UIExtensionAbilities.|
| PUSH<sup>10+</sup> | 17 | PushExtensionAbility: provides APIs for pushing scenario-specific messages. This ability is reserved.|
| DRIVER<sup>10+</sup> | 18 | [DriverExtensionAbility](../apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md): provides APIs for the peripheral driver. This type of ability is not supported yet.|
| ACTION<sup>10+</sup> | 19 | [ActionExtensionAbility](js-apis-app-ability-actionExtensionAbility.md): provides custom action service templates based on UIExtensionAbilities.|
| ADS_SERVICE<sup>11+</sup> | 20 | AdsServiceExtensionAbility: provides background customized ad services for external systems. This type of ability is not supported yet.|
| EMBEDDED_UI<sup>12+</sup> | 21 | [EmbeddedUIExtensionAbility](js-apis-app-ability-embeddedUIExtensionAbility.md): provides ExtensionAbilities for the embeddable UI across process.|
| UNSPECIFIED      | 255 | No type is specified. It is used together with **queryExtensionAbilityInfo** to query all types of ExtensionAbilities.|


### PermissionGrantState

Enumerates the permission grant states.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| PERMISSION_DENIED|  -1 | Permission denied.|
| PERMISSION_GRANTED |  0  |  Permission granted. |

### SupportWindowMode

Enumerates the window modes supported by the ability.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| FULL_SCREEN      | 0   | A window in full-screen mode is supported.|
| SPLIT            | 1   | A window in split-screen mode is supported.|
| FLOATING         | 2   | A floating window is supported.  |

### LaunchType

Enumerates the launch types of the ability.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| SINGLETON        | 0   | The ability can have only one instance.|
| MULTITON         | 1   | The ability can have multiple instances.|
| SPECIFIED        | 2   | The ability can have one or multiple instances, depending on the internal service of the ability.|

### AbilityType

Enumerates the types of abilities.

 **Model restriction**: This API can be used only in the FA model.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

|  Name  | Value  |                            Description                           |
| :-----: | ---- | :--------------------------------------------------------: |
| PAGE    | 1    | Ability that has the UI. FA developed using the Page template to provide the capability of interacting with users.       |
| SERVICE | 2    | Ability of the background service type, without the UI. PA developed using the Service template to provide the capability of running tasks in the background. |
|  DATA   | 3    | PA developed using the Data template to provide unified data access for external systems.|

### DisplayOrientation

Enumerates the display orientations of the ability. This attribute applies only to the ability using the Page template.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                              |Value|Description|
|:----------------------------------|---|---|
| UNSPECIFIED                        |0 |Unspecified. The orientation is determined by the system.|
| LANDSCAPE                          |1 |Landscape.|
| PORTRAIT                           |2 |Portrait.|
| FOLLOW_RECENT                      |3 |The last display orientation is used.|
| LANDSCAPE_INVERTED                 |4 |Reverse landscape.|
| PORTRAIT_INVERTED                  |5 |Reverse portrait.|
| AUTO_ROTATION                      |6 |Auto rotation.|
| AUTO_ROTATION_LANDSCAPE            |7 |Auto rotation in the horizontal direction.|
| AUTO_ROTATION_PORTRAIT             |8 |Auto rotation in the vertical direction.|
| AUTO_ROTATION_RESTRICTED           |9 |Switched-determined auto rotation.|
| AUTO_ROTATION_LANDSCAPE_RESTRICTED |10|Switched-determined auto rotation in the horizontal direction.|
| AUTO_ROTATION_PORTRAIT_RESTRICTED  |11|Switched-determined auto rotation in the vertical direction.|
| LOCKED                             |12|Locked.|

### CompatiblePolicy<sup>10+</sup>

Defines the version compatibility type of the shared library.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                  | Value  | Description                            |
| ---------------------- | ---- | -------------------------------- |
| BACKWARD_COMPATIBILITY | 1    | The shared library is backward compatible.|

### ModuleType

Enumerates the module types.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name   | Value  | Description                |
| ------- | ---- | -------------------- |
| ENTRY   | 1    | Main module of the application.  |
| FEATURE | 2    | Dynamic feature module of the application.|
| SHARED  | 3    | Dynamic shared library module of the application. |

### BundleType

Enumerates the bundle types.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name          | Value  | Description           |
| -------------- | ---- | --------------- |
| APP            | 0    | The bundle is an application.   |
| ATOMIC_SERVICE | 1    | The bundle is an atomic service.|

## APIs

### bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: number): Promise\<BundleInfo>

Obtains the bundle information of this bundle based on the given bundle flags. This API uses a promise to return the result.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
// Obtain application info with metadataArray.
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information of this bundle based on the given bundle flags. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
// Obtain ability info with permissions.
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string\>\>): void

Obtains the JSON string array of the current application's configuration file in the [metadata](../../quick-start/module-configuration-file.md#metadata) based on a given module name, ability name, and metadata name. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the resource management module.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName   | string                        | Yes  | Module name.                                    |
| abilityName  | string                        | Yes  | Name of the UIAbility component.                                   |
| metadataName | string                        | Yes  | Metadata name of the UIAbility component, that is, **name** of the **metadata** tag under **abilities** in the **module.json5** file.                                 |
| callback     | AsyncCallback<Array\<string>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of JSON strings obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise\<Array\<string\>\>

Obtains the JSON string array of the current application's configuration file in the [metadata](../../quick-start/module-configuration-file.md#metadata) based on a given module name, ability name, and metadata name. This API uses a promise to return the result.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the resource management module.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let moduleName = 'entry';
let abilityName = 'EntryAbility';
let metadataName = 'ability_metadata';
try {
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

### bundleManager.getProfileByAbilitySync<sup>10+</sup>

getProfileByAbilitySync(moduleName: string, abilityName: string, metadataName?: string): Array\<string\>

Obtains the JSON string array of the current application's configuration file in the [metadata](../../quick-start/module-configuration-file.md#metadata) based on a given module name, ability name, and metadata name. This API returns the result synchronously. The result value is a string array.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the resource management module.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
    let data = bundleManager.getProfileByAbilitySync(moduleName, abilityName);
    hilog.info(0x0000, 'testTag', 'getProfileByAbilitySync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getProfileByAbilitySync failed. Cause: %{public}s', message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let moduleName: string = 'entry';
let abilityName: string = 'EntryAbility';
let metadataName: string = 'ability_metadata';
try {
    let data = bundleManager.getProfileByAbilitySync(moduleName, abilityName, metadataName);
    hilog.info(0x0000, 'testTag', 'getProfileByAbilitySync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getProfileByAbilitySync failed. Cause: %{public}s', message);
}
```

### bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string\>\>): void

Obtains the JSON string array of the current application's configuration file in the [metadata](../../quick-start/module-configuration-file.md#metadata) based on a given module name, ExtensionAbility name, and metadata name. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the resource management module.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type                         | Mandatory| Description                                                        |
| -------------------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName           | string                        | Yes  | Module name.                                  |
| extensionAbilityName | string                        | Yes  | Name of the ExtensionAbility component.                        |
| metadataName         | string                        | Yes  |  Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under **extensionAbilities** in the **module.json5** file.                                |
| callback             | AsyncCallback<Array\<string>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of JSON strings obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise\<Array\<string\>\>

Obtains the JSON string array of the current application's configuration file in the [metadata](../../quick-start/module-configuration-file.md#metadata) based on a given module name, ExtensionAbility name, and metadata name. This API uses a promise to return the result.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the resource management module.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type  | Mandatory| Description                              |
| -------------------- | ------ | ---- | ---------------------------------- |
| moduleName           | string | Yes  | Module name.          |
| extensionAbilityName | string | Yes  | Name of the ExtensionAbility component.|
| metadataName         | string | No  |  Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under **extensionAbilities** in the **module.json5** file. The default value is null.        |

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Promise<Array\<string>> | Promise used to return the array of JSON strings obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getProfileByExtensionAbilitySync<sup>10+</sup>

getProfileByExtensionAbilitySync(moduleName: string, extensionAbilityName: string, metadataName?: string): Array\<string\>

Obtains the JSON string array of the current application's configuration file in the [metadata](../../quick-start/module-configuration-file.md#metadata) based on a given module name, ExtensionAbility name, and metadata name. This API returns the result synchronously. The result value is a string array.

> **NOTE**
> 
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the resource management module.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type  | Mandatory| Description                              |
| -------------------- | ------ | ---- | ---------------------------------- |
| moduleName           | string | Yes  | Module name.          |
| extensionAbilityName | string | Yes  | Name of the ExtensionAbility component.|
| metadataName         | string | No  |  Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under **extensionAbilities** in the **module.json5** file. The default value is null.        |

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Array\<string> | An array of JSON strings.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleInfoForSelfSync<sup>10+</sup>

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
try {
    let data = bundleManager.getBundleInfoForSelfSync(bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleInfoForSelfSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfoForSelfSync failed: %{public}s', message);
}
```

### bundleManager.verifyAbc<sup>11+</sup>

verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean, callback: AsyncCallback\<void>): void

Verifies an .abc file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.RUN_DYN_CODE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| abcPaths  | Array\<string> | Yes  | Path of the .abc file.|
| deleteOriginalFiles | boolean | Yes  | Whether to delete the .abc file. The value **true** means to delete the file, and **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the verification is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700201 | verifyAbc failed. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let abcPaths : Array<string> = ['/data/storage/el2/base/a.abc'];

try {
    bundleManager.verifyAbc(abcPaths, true, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'verifyAbc failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'verifyAbc successfully');
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'verifyAbc failed: %{public}s', message);
}
```

### bundleManager.verifyAbc<sup>11+</sup>

verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean): Promise\<void>

Verifies an .abc file. This API uses a promise to return the result.

**Required permissions**: ohos.permission.RUN_DYN_CODE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| abcPaths  | Array\<string> | Yes  | Path of the .abc file.|
| deleteOriginalFiles | boolean | Yes  | Whether to delete the .abc file. The value **true** means to delete the file, and **false** means the opposite.      |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700201 | verifyAbc failed. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let abcPaths : Array<string> = ['/data/storage/el2/base/a.abc'];

try {
    bundleManager.verifyAbc(abcPaths, true).then((data) => {
        hilog.info(0x0000, 'testTag', 'verifyAbc successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'verifyAbc failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'verifyAbc failed. Cause: %{public}s', message);
}
```

### bundleManager.deleteAbc<sup>11+</sup>

deleteAbc(abcPath: string): Promise\<void>

Deletes an .abc file based on the specified file path. This API uses a promise to return the result.

**Required permissions**: ohos.permission.RUN_DYN_CODE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| abcPath  | string | Yes  | Path of the .abc file.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700202 | deleteAbc failed. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let abcPath : string = '/data/storage/el2/base/a.abc';

try {
    bundleManager.deleteAbc(abcPath).then((data) => {
        hilog.info(0x0000, 'testTag', 'deleteAbc successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'deleteAbc failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'deleteAbc failed. Cause: %{public}s', message);
}
```

### bundleManager.getExtResource<sup>12+</sup>

getExtResource(bundleName: string): Promise\<Array\<string>>;

Obtains the module names corresponding to the extended resources based on the given bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the extended resources are to be queried.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array\<string>> | Promise used to return the API call result and the module names corresponding to the extended resources.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700303 | GetExtResource failed due to no extend resource. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.getExtResource(bundleName).then((modules : Array<string>) => {
        for (let i = 0; i < modules.length; i++) {
            hilog.info(0x0000, 'testTag', 'getExtResource item: %s', modules[i]);
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getExtResource failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getExtResource failed. Cause: %{public}s', message);
}
```

### bundleManager.enableDynamicIcon<sup>12+</sup>

enableDynamicIcon(bundleName: string, moduleName: string): Promise\<void>;

Enables the dynamic icon based on the given bundle name and module name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_DYNAMIC_ICON

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the dynamic icon is to be enabled.|
| moduleName  | string | Yes  | Module name based on which the dynamic icon is to be enabled.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |
| 17700304 | EnableDynamicIcon failed due to parse dynamic icon failed. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName : string = 'com.ohos.demo';
let moduleName : string = 'moduleTest';

try {
    bundleManager.enableDynamicIcon(bundleName, moduleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'enableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', message);
}
```

### bundleManager.disableDynamicIcon<sup>12+</sup>

disableDynamicIcon(bundleName: string): Promise\<void>;

Disables the dynamic icon based on the given bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_DYNAMIC_ICON

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the dynamic icon is to be disabled.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700305 | DisableDynamicIcon failed due to no dynamic icon. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.disableDynamicIcon(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'disableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', message);
}
```

### bundleManager.getDynamicIcon<sup>12+</sup>

getDynamicIcon(bundleName: string): Promise\<string>;

Obtains the module name corresponding to the dynamic icon based on the specified bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the dynamic icon is to be queried.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<string> | Promise used to return the API call result and module name corresponding to the dynamic icon.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700306 | No dynamic icon. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.getDynamicIcon(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getDynamicIcon successfully %s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getDynamicIcon failed. Cause: %{public}s', message);
}
```

### bundleManager.canOpenLink<sup>12+</sup>

canOpenLink(link: string): boolean

Checks whether a link can be opened. The scheme of the specified link must be configured in the **querySchemes** field of the **module.json** file.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700055 | The specified link is invalid.                      |
| 17700056 | The scheme of the specified link is not in the querySchemes.        |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
try {
    let link = 'welink://';
    let data = bundleManager.canOpenLink(link);
    hilog.info(0x0000, 'testTag', 'canOpenLink successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'canOpenLink failed: %{public}s', message);
}
```
