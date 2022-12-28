# @ohos.bundle.bundleManager

The **bundleManager** module provides APIs for querying information about bundles, applications, abilities, Extension abilities, and more.

> **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import bundleManager from '@ohos.bundle.bundleManager'
```
## Required Permissions

| Required Permissions                                      | Permission Level    | Description           |
| ------------------------------------------ | ------------ | ------------------|
| ohos.permission.GET_BUNDLE_INFO            | normal       | Permission to query information about a specified bundle.  |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED| system_basic | Permission to query information about all bundles.|
| ohos.permission.REMOVE_CACHE_FILES         | system_basic | Permission to clear cache files of a bundle.      |
|ohos.permission.CHANGE_ABILITY_ENABLED_STATE| system_basic | Permission to enable or disable an application or ability. |

For details, see [Permission Levels](../../security/accesstoken-overview.md#permission-levels).

## Enums

### BundleFlag

Enumerates the bundle flags, which indicate the type of bundle information to obtain.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                                     | Value        | Description                                                        |
| ----------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_BUNDLE_INFO_DEFAULT                   | 0x00000000 | Used to obtain the default bundle information. The obtained information does not contain information about the signature, application, HAP module, ability, Extension ability, or permission.|
| GET_BUNDLE_INFO_WITH_APPLICATION          | 0x00000001 | Used to obtain the bundle information with application information. The obtained information does not contain information about the signature, HAP module, ability, Extension ability, or permission.|
| GET_BUNDLE_INFO_WITH_HAP_MODULE           | 0x00000002 | Used to obtain the bundle information with HAP module information. The obtained information does not contain information about the signature, application, ability, Extension ability, or permission.|
| GET_BUNDLE_INFO_WITH_ABILITY              | 0x00000004 | Used to obtain the bundle information with ability information. The obtained information does not contain information about the signature, application, Extension ability, or permission. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.|
| GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY    | 0x00000008 | Used to obtain the bundle information with Extension ability information. The obtained information does not contain information about the signature, application, ability, or permission. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.|
| GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION | 0x00000010 | Used to obtain the bundle information with permission information. The obtained information does not contain information about the signature, application, HAP module, ability, or Extension ability.|
| GET_BUNDLE_INFO_WITH_METADATA             | 0x00000020 | Used to obtain the metadata contained in the application, HAP module, ability, or Extension ability information. It must be used together with **GET_BUNDLE_INFO_WITH_APPLICATION**, **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**.|
| GET_BUNDLE_INFO_WITH_DISABLE              | 0x00000040 | Used to obtain the information about disabled bundles and abilities of a bundle. The obtained bundle information does not contain information about the signature, application, HAP module, ability, Extension ability, or permission.|
| GET_BUNDLE_INFO_WITH_SIGNATURE_INFO       | 0x00000080 | Used to obtain the bundle information with signature information. The obtained information does not contain information about the application, HAP module, ability, Extension ability, or permission.|

### ApplicationFlag

Enumerates the application flags, which indicate the type of application information to obtain.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API and cannot be called by third-party applications.

| Name                                | Value        | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| GET_APPLICATION_INFO_DEFAULT         | 0x00000000 | Used to obtain the default application information. The obtained information does not contain the permission information or metadata.|
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000001 | Used to obtain the application information with permission information.                   |
| GET_APPLICATION_INFO_WITH_METADATA   | 0x00000002 | Used to obtain the application information with metadata.                     |
| GET_APPLICATION_INFO_WITH_DISABLE    | 0x00000004 | Used to obtain the application information of disabled bundles.                 |

### AbilityFlag

Enumerates the ability flags, which indicate the type of ability information to obtain.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API and cannot be called by third-party applications.

| Name                             | Value        | Description                                                        |
| --------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_ABILITY_INFO_DEFAULT          | 0x00000000 | Used to obtain the default ability information. The obtained information does not contain the permission, metadata, or disabled ability information.|
| GET_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | Used to obtain the ability information with permission information.                         |
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | Used to obtain the ability information with application information.                    |
| GET_ABILITY_INFO_WITH_METADATA    | 0x00000004 | Used to obtain the ability information with metadata.                           |
| GET_ABILITY_INFO_WITH_DISABLE     | 0x00000008 | Used to obtain the ability information of disabled abilities.                  |
| GET_ABILITY_INFO_ONLY_SYSTEM_APP  | 0x00000010 | Used to obtain the ability information of system applications.                        |

### ExtensionAbilityFlag

Enumerates the Extension ability flags, which indicate the type of Extension ability information to obtain.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API and cannot be called by third-party applications.

| Name                                       | Value        | Description                                                        |
| ------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_EXTENSION_ABILITY_INFO_DEFAULT          | 0x00000000 | Used to obtain the default Extension ability information. The obtained information does not contain the permission, metadata, or disabled ability information.|
| GET_EXTENSION_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | Used to obtain the Extension ability information with permission information.              |
| GET_EXTENSION_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | Used to obtain the Extension ability information with application information.        |
| GET_EXTENSION_ABILITY_INFO_WITH_METADATA    | 0x00000004 | Used to obtain the Extension ability information with metadata.                |

### ExtensionAbilityType

Enumerates the types of Extension abilities.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|-----|
| FORM             | 0   | [FormExtensionAbility](../../application-models/widget-development-stage.md): provides APIs for widget development.|
| WORK_SCHEDULER   | 1   | [WorkSchedulerExtensionAbility](../../task-management/work-scheduler-dev-guide.md): enables applications to execute non-real-time tasks when the system is idle.|
| INPUT_METHOD     | 2   | [InputMethodExtensionAbility](js-apis-inputmethod-extension-ability.md): provides APIs for developing input method applications.|
| SERVICE          | 3   | [ServiceExtensionAbility](../../application-models/serviceextensionability.md): enables applications to run in the background and provide services.|
| ACCESSIBILITY    | 4   | [AccessibilityExtensionAbility](js-apis-application-accessibilityExtensionAbility.md): provides accessibility for access to and operations on the UI.|
| DATA_SHARE       | 5   | [DataShareExtensionAbility](../../database/database-datashare-guidelines.md): enables applications to read and write data.|
| FILE_SHARE       | 6   | FileShareExtensionAbility: enables file sharing between applications. This ability is reserved.|
| STATIC_SUBSCRIBER| 7   | [StaticSubscriberExtensionAbility](js-apis-application-staticSubscriberExtensionAbility.md): provides APIs for processing static events, such as the startup event.|
| WALLPAPER        | 8   | WallpaperExtensionAbility: provides APIs to implement the home screen wallpaper. This ability is reserved.|
| BACKUP           |  9  | BackupExtensionAbility: provides APIs for backing up and restoring application data and public data. This ability is reserved.|
| WINDOW           |  10 | [WindowExtensionAbility](js-apis-application-windowExtensionAbility.md): allows system applications to display UIs of other applications.|
| ENTERPRISE_ADMIN |  11 | [EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md): provides APIs for processing enterprise management events, such as application installation events on devices and events indicating too many incorrect screen-lock password attempts.|
| THUMBNAIL        | 13  | ThumbnailExtensionAbility: provides thumbnails for files. This ability is reserved.|
| PREVIEW          | 14  | PreviewExtensionAbility: provides APIs for file preview so that other applications can be embedded and displayed in the current application. This ability is reserved.|
| UNSPECIFIED      | 255 | No type is specified. It is used together with **queryExtensionAbilityInfo** to query all types of Extension abilities.|


### PermissionGrantState

Enumerates the permission grant states.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| PERMISSION_DENIED|  -1 | Permission denied.|
| PERMISSION_GRANTED |  0  |  Permission granted. |

### SupportWindowMode

Enumerates the window modes supported by the ability.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| FULL_SCREEN      | 0   | A window in full-screen mode is supported.|
| SPLIT            | 1   | A window in split-screen mode is supported.|
| FLOATING         | 2   | A floating window is supported.  |

### LaunchType

Enumerates the launch types of the ability.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| SINGLETON        | 0   | The ability can have only one instance.|
| STANDARD         | 1   | The ability can have multiple instances.|
| SPECIFIED        | 2   | The ability can have one or multiple instances, depending on the internal service of the ability.|

### AbilityType

Enumerates the types of abilities.

 **Model restriction**: This API can be used only in the FA model.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

|  Name  | Value  |                            Description                           |
| :-----: | ---- | :--------------------------------------------------------: |
|  PAGE   | 1    |     FA developed using the Page template to provide the capability of interacting with users.    |
| SERVICE | 2    |  PA developed using the Service template to provide the capability of running tasks in the background.  |
|  DATA   | 3    | PA developed using the Data template to provide unified data access for external systems.|

### DisplayOrientation

Enumerates the display orientations of the ability. This attribute applies only to the ability using the Page template.

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

## Methods

### bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: [number](#bundleflag)): Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>;

Obtains the bundle information of this bundle based on the given bundle flags. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information.|

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
try {
    bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
        console.info('getBundleInfoForSelf successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleInfoForSelf failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInfoForSelf failed:' + error.message);
}
```

### bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: [number](#bundleflag), callback: AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>): void;

Obtains the bundle information of this bundle based on the given bundle flags. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleInfoForSelf(bundleFlags, (err, data) => {
        if (err) {
            console.error('getBundleInfoForSelf failed:' + err.message);
        } else {
            console.info('getBundleInfoForSelf successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleInfoForSelf failed:' + err.message);
}
```

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void;

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.   |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes  | User ID. |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the ability information.
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_ABILITY;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            console.error('getBundleInfo failed:' + err.message);
        } else {
            console.info('getBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleInfo failed:' + err.message);
}
```

```ts
// Obtain the bundle information with the metadata in the application information.
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            console.error('getBundleInfo failed:' + err.message);
        } else {
            console.info('getBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleInfo failed:' + err.message);
}
```

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void;

Obtains the bundle information based on the given bundle name and bundle flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.   |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.    |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the Extension ability information.
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, (err, data) => {
        if (err) {
            console.error('getBundleInfo failed:' + err.message);
        } else {
            console.info('getBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleInfo failed:' + err.message);
}
```

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: [number](#bundleflag), userId?: number): Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>;

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.      |
| userId      | number | No  | User ID. |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the application and signature information.
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId).then((data) => {
        console.info('getBundleInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInfo failed. Cause: ' + error.message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags).then((data) => {
        console.info('getBundleInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInfo failed. Cause: ' + error.message);
}

```

### bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: [number](#applicationflag), userId: number, callback: AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>): void;

Obtains the application information based on the given bundle name, application flags, and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name.|
| appFlags   | [number](#applicationflag) | Yes  | Type of the application information to obtain.   |
| userId     | number | Yes  | User ID. |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId, (err, data) => {
        if (err) {
            console.error('getApplicationInfo failed:' + err.message);
        } else {
            console.info('getApplicationInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getApplicationInfo failed:' + err.message);
}
```

### bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: [number](#applicationflag), callback: AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>): void;

Obtains the application information based on the given bundle name and application flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name.|
| appFlags   | [number](#applicationflag) | Yes  | Type of the application information to obtain.   |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, (err, data) => {
        if (err) {
            console.error('getApplicationInfo failed:' + err.message);
        } else {
            console.info('getApplicationInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getApplicationInfo failed:' + err.message);
}
```

### bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: [number](#applicationflag), userId?: number): Promise\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>;

Obtains the application information based on the given bundle name, application flags, and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name.|
| appFlags   | [number](#applicationflag) | Yes  | Type of the application information to obtain.   |
| userId     | number | No  | User ID.|

**Return value**

| Type                                                        | Description                            |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Promise used to return the application information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId).then((data) => {
        console.info('getApplicationInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getApplicationInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getApplicationInfo failed. Cause: ' + error.message);
}
```

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: [number](#bundleflag), userId: number, callback: AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>>): void;

Obtains an array of bundle information based on the given bundle flags and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.                   |
| userId      | number | Yes  | User ID.                     |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                        |
| -------- | --------------------------------- |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    bundleManager.getAllBundleInfo(bundleFlags, userId, (err, data) => {
        if (err) {
            console.error('getAllBundleInfo failed:' + err.message);
        } else {
            console.info('getAllBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAllBundleInfo failed:' + err.message);
}
```

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: [number](#bundleflag), callback: AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>>): void;

Obtains an array of bundle information based on the given bundle flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.  |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getAllBundleInfo(bundleFlags, (err, data) => {
        if (err) {
            console.error('getAllBundleInfo failed:' + err.message);
        } else {
            console.info('getAllBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAllBundleInfo failed:' + err.message);
}
```

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: [number](#bundleflag), userId?: number): Promise<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>>;

Obtains an array of bundle information based on the given bundle flags and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.                  |
| userId      | number | No  | User ID.                        |

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Promise used to return the array of bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getAllBundleInfo(bundleFlags).then((data) => {
        console.info('getAllBundleInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getAllBundleInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getAllBundleInfo failed. Cause: ' + error.message);
}
```

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: [number](#applicationflag), userId: number, callback: AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>>): void;

Obtains an array of application information based on the given application flags and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| userId   | number | Yes  | User ID.        |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    bundleManager.getAllApplicationInfo(appFlags, userId, (err, data) => {
        if (err) {
            console.error('getAllApplicationInfo failed:' + err.message);
        } else {
            console.info('getAllApplicationInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAllApplicationInfo failed:' + err.message);
}
```

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: [number](#applicationflag), callback: AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>>): void;

Obtains an array of application information based on the given application flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    bundleManager.getAllApplicationInfo(appFlags, (err, data) => {
        if (err) {
            console.error('getAllApplicationInfo failed:' + err.message);
        } else {
            console.info('getAllApplicationInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAllApplicationInfo failed:' + err.message);
}
```

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: [number](#applicationflag), userId?: number): Promise<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>>;

Obtains an array of application information based on the given application flags and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ---------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| userId   | number | No  | User ID.                                 |

**Return value**

| Type                                                        | Description                                    |
| ------------------------------------------------------------ | ---------------------------------------- |
| Promise<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Promise used to return the array of application information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    bundleManager.getAllApplicationInfo(appFlags).then((data) => {
        console.info('getAllApplicationInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getAllApplicationInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getAllApplicationInfo failed. Cause: ' + error.message);
}

```

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: [number](#abilityflag), userId: number, callback: AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>>): void;

Obtains an array of ability information based on the given want, ability flags, and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | Yes  | Want containing the bundle name to query.                   |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.                      |
| userId       | number | Yes  | User ID.                              |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ability information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId, (err, data) => {
        if (err) {
            console.error('queryAbilityInfo failed:' + err.message);
        } else {
            console.info('queryAbilityInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('queryAbilityInfo failed:' + err.message);
}
```

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: [number](#abilityflag), callback: AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>>): void;

Obtains an array of ability information based on the given want and ability flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | -------------------------------------------------------|
| want         | Want   | Yes  | Want containing the bundle name to query.                   |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.      |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ability information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, (err, data) => {
        if (err) {
            console.error('queryAbilityInfo failed:' + err.message);
        } else {
            console.info('queryAbilityInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('queryAbilityInfo failed:' + err.message);
}
```

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: [number](#abilityflag), userId?: number): Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>>;

Obtains the ability information based on the given want, ability flags, and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | Yes  | Want containing the bundle name to query.                   |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.|
| userId       | number | No  | User ID.                              |

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Promise used to return the array of ability information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((data) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags).then((data) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    })
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: [ExtensionAbilityType](#extensionabilitytype), extensionAbilityFlags: [number](#extensionabilityflag), userId: number, callback: AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>>): void;

Obtains the Extension ability information based on the given want, Extension ability type, Extension ability flags, and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                                        | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | Yes  | Want containing the bundle name to query.                        |
| extensionAbilityType  | [ExtensionAbilityType](#extensionabilitytype)                | Yes  | Type of the Extension ability.                                  |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | Yes  | Type of the Extension ability information to obtain.     |
| userId                | number                                                       | Yes  | User ID.                                                  |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of Extension ability information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId, (err, data) => {
        if (err) {
            console.error('queryExtensionAbilityInfo failed:' + err.message);
        } else {
            console.info('queryExtensionAbilityInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('queryExtensionAbilityInfo failed:' + err.message);
}
```

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: [ExtensionAbilityType](#extensionabilitytype), extensionAbilityFlags: [number](#extensionabilityflag), callback: AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>>): void;

Obtains the Extension ability information based on the given want, Extension ability type, and Extension ability flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                                        | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | Yes  | Want containing the bundle name to query.                        |
| extensionAbilityType  | [ExtensionAbilityType](#extensionabilitytype)                | Yes  | Type of the Extension ability.                                  |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | Yes  | Type of the Extension ability information to obtain.     |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of Extension ability information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, (err, data) => {
        if (err) {
            console.error('queryExtensionAbilityInfo failed:' + err.message);
        } else {
            console.info('queryExtensionAbilityInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('queryExtensionAbilityInfo failed:' + err.message);
}
```

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: [ExtensionAbilityType](#extensionabilitytype), extensionAbilityFlags: [number](#extensionabilityflag), userId?: number): Promise<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>>;

Obtains the Extension ability information based on the given want, Extension ability type, Extension ability flags, and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                         | Mandatory| Description                                                   |
| --------------------- | --------------------------------------------- | ---- | ------------------------------------------------------- |
| want                  | Want                                          | Yes  | Want containing the bundle name to query.                   |
| extensionAbilityType  | [ExtensionAbilityType](#extensionabilitytype) | Yes  | Type of the Extension ability.                             |
| extensionAbilityFlags | [number](#extensionabilityflag)               | Yes  | Type of the Extension ability information to obtain.|
| userId                | number                                        | No  | User ID.                                             |

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Promise used to return the array of Extension ability information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'

let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId).then((data) => {
        console.info('queryExtensionAbilityInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('queryExtensionAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryExtensionAbilityInfo failed. Cause: ' + error.message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags).then((data) => {
        console.info('queryExtensionAbilityInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('queryExtensionAbilityInfo failed. Cause: ' + error.message);
    })
} catch (error) {
    console.error('queryExtensionAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.getBundleNameByUid

getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void;

Obtains the bundle name based on the given UID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                 | Yes  | UID of the application.                                           |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle name obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message           |
| -------- | --------------------- |
| 17700021 | The uid is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid, (err, data) => {
        if (err) {
            console.error('getBundleNameByUid failed:' + err.message);
        } else {
            console.info('getBundleNameByUid successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleNameByUid failed:' + err.message);
}
```

### bundleManager.getBundleNameByUid

getBundleNameByUid(uid: number): Promise\<string>;

Obtains the bundle name based on the given UID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

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

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 17700021 | The uid is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid).then((data) => {
        console.info('getBundleNameByUid successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleNameByUid failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleNameByUid failed. Cause: ' + error.message);
}
```

### bundleManager.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: [number](#bundleflag), callback: AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>): void;

Obtains the bundle information based on the given HAP file path and bundle flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ----------------------------------------------------------- |
| hapFilePath | string | Yes  | Path where the HAP file is stored. The path must be the relative path of the current bundle's data directory.|
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.      |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                 |
| -------- | --------------------------- |
| 17700022 | The hapFilePath is invalid. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags, (err, data) => {
        if (err) {
            console.error('getBundleArchiveInfo failed:' + err.message);
        } else {
            console.info('getBundleArchiveInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleArchiveInfo failed:' + err.message);
}
```

### bundleManager.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string,  bundleFlags: [number](#bundleflag)): Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>;

Obtains the bundle information based on the given HAP file path and bundle flags. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | Yes  | Path where the HAP file is stored. The path must be the relative path of the current bundle's data directory.|
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.      |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 17700022 | The hapFilePath is invalid. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags).then((data) => {
        console.info('getBundleArchiveInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleArchiveInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleArchiveInfo failed. Cause: ' + error.message);
}
```

### bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void;

Clears cache files of a bundle. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REMOVE_CACHE_FILES

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                  |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700001 | The specified bundleName is not found.                        |
| 17700030 | The specified bundle does not support clearing of cache files. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.cleanBundleCacheFiles(bundleName, err => {
        if (err) {
            console.error('cleanBundleCacheFiles failed:' + err.message);
        } else {
            console.info('cleanBundleCacheFiles successfully.');
        }
    });
} catch (err) {
    console.error('cleanBundleCacheFiles failed:' + err.message);
}
```

### bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string): Promise\<void>;

Clears cache files of a bundle. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REMOVE_CACHE_FILES

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                      |
| ---------- | ------ | ---- | ------------------------------------------ |
| bundleName | string | Yes  | Bundle name.|

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the operation is successful, **true** is returned. Otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 17700001 | The specified bundleName is not found.                      |
| 17700030 | The specified bundle does not support clearing of cache files. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.cleanBundleCacheFiles(bundleName).then(()=> {
        console.info('cleanBundleCacheFiles successfully.');
    }).catch(err=> {
        console.error('cleanBundleCacheFiles failed:' + err.message);
    });
} catch (err) {
    console.error('cleanBundleCacheFiles failed:' + err.message);
}
```

### bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void;

Enables or disables an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.               |
| isEnabled  | boolean | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means to disable the application.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, false, err => {
        if (err) {
            console.error('setApplicationEnabled failed:' + err.message);
        } else {
            console.info('setApplicationEnabled successfully.');
        }
    });
} catch (err) {
    console.error('setApplicationEnabled failed:' + err.message);
}
```

### bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean): Promise\<void>;

Enables or disables an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.           |
| isEnabled  | boolean | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means to disable the application.|

**Return value**

| Type          | Description                                |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, false).then(()=> {
        console.info('setApplicationEnabled successfully.');
    }).catch(err=> {
        console.error('setApplicationEnabled failed:' + err.message);
    });
} catch (err) {
    console.error('setApplicationEnabled failed:' + err.message);
}
```

### bundleManager.setAbilityEnabled

setAbilityEnabled(info: [AbilityInfo](js-apis-bundleManager-abilityInfo.md), isEnabled: boolean, callback: AsyncCallback\<void>): void;

Enables or disables an ability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.             |
| isEnabled| boolean     | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means to disable the application.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ---------------------------------------|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
var info;

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(abilitiesInfo));
        info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, false, err => {
            if (err) {
                console.error('setAbilityEnabled failed:' + err.message);
            } else {
                console.info('setAbilityEnabled successfully.');
            }
        });
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.setAbilityEnabled

setAbilityEnabled(info: [AbilityInfo](js-apis-bundleManager-abilityInfo.md), isEnabled: boolean): Promise\<void>;

Enables or disables an ability. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.                  |
| isEnabled| boolean     | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means to disable the application.|

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
var info;

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(abilitiesInfo));
        info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, false).then(()=> {
            console.info('setAbilityEnabled successfully.');
        }).catch(err=> {
            console.error('setAbilityEnabled failed:' + err.message);
        });
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void;

Checks whether an application is enabled. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name.|
| callback | AsyncCallback\<boolean> | Yes| Callback used to return the result. The value **true** means that the application is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName, (err, data) => {
        if (err) {
            console.error('isApplicationEnabled failed:' + err.message);
        } else {
            console.info('isApplicationEnabled successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('isApplicationEnabled failed:' + err.message);
}
```

### bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string): Promise\<boolean>;

Checks whether an application is enabled. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name. |

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the application is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName).then((data) => {
        console.info('isApplicationEnabled successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('isApplicationEnabled failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('isApplicationEnabled failed. Cause: ' + error.message);
}
```

### bundleManager.isAbilityEnabled

isAbilityEnabled(info: [AbilityInfo](js-apis-bundleManager-abilityInfo.md), callback: AsyncCallback\<boolean>): void;

Checks whether an ability is enabled. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type       | Mandatory| Description                       |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.|
| callback | AsyncCallback\<boolean> | Yes| Callback used to return the result. The value **true** means that the ability is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
var info;

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(abilitiesInfo));
        info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info, (err, data) => {
            if (err) {
                console.error('isAbilityEnabled failed:' + err.message);
            } else {
                console.info('isAbilityEnabled successfully:' + JSON.stringify(data));
            }
        });
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.isAbilityEnabled

isAbilityEnabled(info: [AbilityInfo](js-apis-bundleManager-abilityInfo.md)): Promise\<boolean>;

Checks whether an ability is enabled. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type       | Mandatory| Description                       |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the ability is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
var info;

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(abilitiesInfo));
        info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info).then((data) => {
            console.info('isAbilityEnabled successfully. Data: ' + JSON.stringify(data));
        }).catch(err => {
            console.error('isAbilityEnabled failed. Cause: ' + err.message);
        });
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId: number, callback: AsyncCallback\<Want>): void;

Obtains the want used to launch the bundle based on the given bundle name and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                                    |
| userId     | number               | Yes  | User ID.                                                  |
| callback   | AsyncCallback\<Want> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **Want** object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    bundleManager.getLaunchWantForBundle(bundleName, userId, (err, data) => {
        if (err) {
            console.error('getLaunchWantForBundle failed:' + err.message);
        } else {
            console.info('getLaunchWantForBundle successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getLaunchWantForBundle failed:' + err.message);
}
```

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void;

Obtains the want used to launch the bundle based on the given bundle name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                                    |
| callback   | AsyncCallback\<Want> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **Want** object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';

try {
    bundleManager.getLaunchWantForBundle(bundleName, (err, data) => {
        if (err) {
            console.error('getLaunchWantForBundle failed:' + err.message);
        } else {
            console.info('getLaunchWantForBundle successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getLaunchWantForBundle failed:' + err.message);
}
```

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId?: number): Promise\<Want>;

Obtains the want used to launch the bundle based on the given bundle name and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | No  | User ID.              |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<Want> | Promise used to return the **Want** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    bundleManager.getLaunchWantForBundle(bundleName, userId).then((data) => {
        console.info('getLaunchWantForBundle successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getLaunchWantForBundle failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getLaunchWantForBundle failed. Cause: ' + error.message);
}
```

### bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback<Array\<string>>): void;

Obtains the JSON strings of the configuration file based on the given module ame, ability name, and metadata name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName   | string                        | Yes  | Module name.                                    |
| abilityName  | string                        | Yes  | Ability name.                                   |
| metadataName | string                        | Yes  | Metadata name.                                 |
| callback     | AsyncCallback<Array\<string>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of JSON strings obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700002 | The specified moduleName does not exist.                      |
| 17700003 | The specified abilityName does not exist.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let abilityName = 'MainAbility';
let metadataName = 'com.example.myapplication.metadata';

try {
    bundleManager.getProfileByAbility(moduleName, abilityName, metadataName, (err, data) => {
        if (err) {
            console.error('getProfileByAbility failed:' + err.message);
        } else {
            console.info('getProfileByAbility successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getProfileByAbility failed:' + err.message);
}
```

### bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise<Array\<string>>;

Obtains the JSON strings of the configuration file based on the given module ame, ability name, and metadata name. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                      |
| ------------ | ------ | ---- | -------------------------- |
| moduleName   | string | Yes  | Module name.  |
| abilityName  | string | Yes  | Ability name. |
| metadataName | string | No  | Metadata name.|

**Return value**

| Type                   | Description                           |
| ----------------------- | ------------------------------- |
| Promise<Array\<string>> | Promise used to return the array of JSON strings obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700002 | The specified moduleName does not exist.                      |
| 17700003 | The specified abilityName does not exist.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getProfileByAbility(moduleName, abilityName).then((data) => {
        console.info('getProfileByAbility successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getProfileByAbility failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getProfileByAbility failed. Cause: ' + error.message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let abilityName = 'MainAbility';
let metadataName = 'com.example.myapplication.metadata';
try {
    bundleManager.getProfileByAbility(moduleName, abilityName, metadataName).then((data) => {
        console.info('getProfileByAbility successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getProfileByAbility failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getProfileByAbility failed. Cause: ' + error.message);
}
```

### bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback<Array\<string>>): void;

Obtains the JSON strings of the configuration file based on the given module ame, Extension ability name, and metadata name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type                         | Mandatory| Description                                                        |
| -------------------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName           | string                        | Yes  | Module name.                                  |
| extensionAbilityName | string                        | Yes  | Extension ability name.                        |
| metadataName         | string                        | Yes  | Metadata name.                                |
| callback             | AsyncCallback<Array\<string>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of JSON strings obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700002 | The specified moduleName does not exist.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'com.example.myapplication.metadata';

try {
    bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName, (err, data) => {
        if (err) {
            console.error('getProfileByExtensionAbility failed:' + err.message);
        } else {
            console.info('getProfileByExtensionAbility successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getProfileByExtensionAbility failed:' + err.message);
}
```

### bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise<Array\<string>>;

Obtains the JSON strings of the configuration file based on the given module ame, Extension ability name, and metadata name. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type  | Mandatory| Description                              |
| -------------------- | ------ | ---- | ---------------------------------- |
| moduleName           | string | Yes  | Module name.          |
| extensionAbilityName | string | Yes  | Extension ability name.|
| metadataName         | string | No  | Metadata name.        |

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Promise<Array\<string>> | Promise used to return the array of JSON strings obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 17700002 | The specified moduleName does not exist.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700026 | The specified bundle is disabled.                             |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'com.example.myapplication.metadata';

try {
    bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName).then((data) => {
        console.info('getProfileByExtensionAbility successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getProfileByExtensionAbility failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getProfileByExtensionAbility failed. Cause: ' + error.message);
}

try {
    bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName).then((data) => {
        console.info('getProfileByExtensionAbility successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getProfileByExtensionAbility failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getProfileByExtensionAbility failed. Cause: ' + error.message);
}
```

### bundleManager.getPermissionDef

getPermissionDef(permissionName: string, callback: AsyncCallback\<[PermissionDef](js-apis-bundleManager-permissionDef.md)>): void;

Obtains the details of a permission. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                        | Mandatory| Description                                                        |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| permissionName | string                                                       | Yes  | Name of the permission.                                              |
| callback       | AsyncCallback\<[PermissionDef](js-apis-bundleManager-permissionDef.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of **PermissionDef** objects obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17700006 | The specified permission is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let permission = "ohos.permission.GET_BUNDLE_INFO";
try {
    bundleManager.getPermissionDef(permission, (err, data) => {
        if (err) {
            console.error('getPermissionDef failed:' + err.message);
        } else {
            console.info('getPermissionDef successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getPermissionDef failed:' + err.message);
}
```

### bundleManager.getPermissionDef

getPermissionDef(permissionName: string): Promise\<[PermissionDef](js-apis-bundleManager-permissionDef.md)>;

Obtains the details of a permission. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type  | Mandatory| Description          |
| -------------- | ------ | ---- | -------------- |
| permissionName | string | Yes  | Name of the permission.|

**Return value**

| Type                                                        | Description                                      |
| ------------------------------------------------------------ | ------------------------------------------ |
| Promise\<[PermissionDef](js-apis-bundleManager-permissionDef.md)> | Promise used to return the array of **PermissionDef** objects obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17700006 | The specified permission is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let permissionName = "ohos.permission.GET_BUNDLE_INFO";
try {
    bundleManager.getPermissionDef(permissionName).then((data) => {
        console.info('getPermissionDef successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getPermissionDef failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getPermissionDef failed. Cause: ' + error.message);
}
```

### bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<string>): void;

Obtains the ability label based on the given bundle name, module name, and ability name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name     | Type                  | Mandatory| Description                                                        |
| ----------- | ---------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                 | Yes  | Bundle name.                                    |
| moduleName  | string                 | Yes  | Module name.                                    |
| abilityName | string                 | Yes  | Ability name.                                   |
| callback    | AsyncCallback\<string> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the label obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName, (err, data) => {
        if (err) {
            console.error('getAbilityLabel failed:' + err.message);
        } else {
            console.info('getAbilityLabel successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAbilityLabel failed:' + err.message);
}
```

### bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>;

Obtains the ability label based on the given bundle name, module name, and ability name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name     | Type  | Mandatory| Description                     |
| ----------- | ------ | ---- | ------------------------- |
| bundleName  | string | Yes  | Bundle name. |
| moduleName  | string | Yes  | Module name. |
| abilityName | string | Yes  | Ability name.|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the label.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName).then((data) => {
        console.info('getAbilityLabel successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getAbilityLabel failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getAbilityLabel failed. Cause: ' + error.message);
}
```

### bundleManager.getAbilityIcon

getAbilityIcon(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback<[image.PixelMap](js-apis-image.md#pixelmap7)>): void;

Obtains the ability icon based on the given bundle name, module name, and ability name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name     | Type                                                       | Mandatory| Description                                                        |
| ----------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                                                      | Yes  | Bundle name.                                    |
| moduleName  | string                                                      | Yes  | Module name.                                    |
| abilityName | string                                                      | Yes  | Ability name.                                   |
| callback    | AsyncCallback<[image.PixelMap](js-apis-image.md#pixelmap7)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **PixelMap** object of the icon. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getAbilityIcon(bundleName, moduleName, abilityName, (err, data) => {
        if (err) {
            console.error('getAbilityIcon failed:' + err.message);
        } else {
            console.info('getAbilityIcon successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAbilityIcon failed:' + err.message);
}
```

### bundleManager.getAbilityIcon

getAbilityIcon(bundleName: string, moduleName: string, abilityName: string): Promise<[image.PixelMap](js-apis-image.md#pixelmap7)>;

Obtains the ability icon based on the given bundle name, module name, and ability name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name     | Type  | Mandatory| Description                     |
| ----------- | ------ | ---- | ------------------------- |
| bundleName  | string | Yes  | Bundle name. |
| moduleName  | string | Yes  | Module name. |
| abilityName | string | Yes  | Ability name.|

**Return value**

| Type                                                 | Description                                       |
| ----------------------------------------------------- | ------------------------------------------- |
| Promise<[image.PixelMap](js-apis-image.md#pixelmap7)> | Promise used to return the **PixelMap** object of the icon.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getAbilityIcon(bundleName, moduleName, abilityName).then((data) => {
        console.info('getAbilityIcon successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getAbilityIcon failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getAbilityIcon failed. Cause: ' + error.message);
}
```

### bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number, userId: number) : [ApplicationInfo](js-apis-bundleManager-applicationInfo.md);

Synchronously obtains the application information based on the given bundle name, application flags, and user ID.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                      |
| ----------- | ------ | ---- | ----------------------------------------------------------|
| bundleName  | string | Yes  | Bundle name.                                 |
| applicationFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.      |
| userId      | number | Yes  | User ID.                                        |

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | Application information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags, userId);
    console.info("getApplicationInfoSync successfully:" + JSON.stringify(data));
} catch (err) {
    console.error('getApplicationInfoSync failed:' + err.message);
}
```

### bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number) : [ApplicationInfo](js-apis-bundleManager-applicationInfo.md);

Synchronously obtains the application information based on the given bundle name and application flags.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                      |
| ----------- | ------ | ---- | ----------------------------------------------------------|
| bundleName  | string | Yes  | Bundle name.                                 |
| applicationFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.      |

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | Application information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags);
    console.info("getApplicationInfoSync successfully:" + JSON.stringify(data));
} catch (err) {
    console.error('getApplicationInfoSync failed:' + err.message);
}
```

### bundleManager.getBundleInfoSync

getBundleInfoSync(bundleName: string, bundleFlags: [number](#bundleflag), userId: number): [BundleInfo](js-apis-bundleManager-bundleInfo.md);

Synchronously obtains the bundle information based on the given bundle name, bundle flags, and user ID.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | Yes  | Bundle name.                                |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes  | User ID.                                            |

**Return value**

| Type      | Description                |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    console.info("getBundleInfoSync successfully :" + JSON.stringify(data));
} catch (err) {
    console.error('getBundleInfoSync failed:' + err.message);
}
```

### bundleManager.getBundleInfoSync

getBundleInfoSync(bundleName: string, bundleFlags: [number](#bundleflag)): [BundleInfo](js-apis-bundleManager-bundleInfo.md);

Synchronously obtains the bundle information based on the given bundle name and bundle flags.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | Yes  | Bundle name.                                |
| bundleFlags | [number](#bundleflag) | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type      | Description                |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags);
    console.info("getBundleInfoSync successfully :" + JSON.stringify(data));
} catch (err) {
    console.error('getBundleInfoSync failed:' + err.message);
}
```

 <!--no_check--> 