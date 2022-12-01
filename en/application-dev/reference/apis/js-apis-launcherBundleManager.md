# Bundle.launcherBundleManager

The **Bundle.launcherBundleManager** module providers APIs for the **Home Screen** application to obtain the launcher ability information and shortcut information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
```


## launcherBundlemanager.getLauncherAbilityInfo<sup>9+</sup>

getLauncherAbilityInfo(bundleName: string, userId: number, callback: AsyncCallback<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>>) : void;

Obtains the launcher ability information based on the given bundle name and user ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description          |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name of the application.|
| userId     | number | Yes  | User ID.|

**Return value**

| Type                               | Description                                               |
| ----------------------------------- | --------------------------------------------------- |
| AsyncCallback\<Array<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>> | Callback used to return the **LauncherAbilityInfo** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified userId is not found.      |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getLauncherAbilityInfo('com.example.demo', 100, (errData, data) => {
        if (errData !== null) {
            console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
        }
        console.log("data is " + JSON.stringify(data));
    })
} catch (errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## launcherBundlemanager.getLauncherAbilityInfo<sup>9+</sup>

getLauncherAbilityInfo(bundleName: string, userId: number) : Promise<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>>;

Obtains the launcher ability information based on the given bundle name and user ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description          |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name of the application.|
| userId     | number | Yes  | User ID.|

**Return value**

| Type                         | Description                                              |
| ----------------------------- | -------------------------------------------------- |
| Promise\<Array<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>> | Promise used to return the **LauncherAbilityInfo** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified userId is not found.       |

**Example**

```typescript
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getLauncherAbilityInfo("com.example.demo", 100).then(data => {
        console.log("data is " + JSON.stringify(data));
    }).catch (errData => {
        console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
} catch (errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## launcherBundlemanager.getAllLauncherAbilityInfo<sup>9+</sup>

getAllLauncherAbilityInfo(userId: number, callback: AsyncCallback<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>>) : void;

Obtains the launcher ability information of all applications based on the given user ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| userId | number | Yes  | User ID.|

**Return value**

| Type                               | Description                                                   |
| ----------------------------------- | ------------------------------------------------------- |
| AsyncCallback\<Array<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>> | Callback used to return the array of **LauncherAbilityInfo** objects obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 17700004 | The specified userId is not found.      |

Example

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getAllLauncherAbilityInfo(100, (errData, data) => {
        if (errData !== null) {
            console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
        }
        console.log("data is " + JSON.stringify(data));
    });
} catch (errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```
## launcherBundlemanager.getAllLauncherAbilityInfo<sup>9+</sup>

getAllLauncherAbilityInfo(userId: number) : Promise<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>>;

Obtains the launcher ability information of all applications based on the given user ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| userId | number | Yes  | User ID.|

**Return value**

| Type                         | Description                                                  |
| ----------------------------- | ------------------------------------------------------ |
| Promise\<Array<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>> | Promise used to return the array of **LauncherAbilityInfo** objects obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 17700004 | The specified userId is not found.      |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getAllLauncherAbilityInfo(100).then(data => {
        console.log("data is " + JSON.stringify(data));
    }).catch (errData => {
        console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
    });
} catch (errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## launcherBundlemanager.getShortcutInfo<sup>9+</sup>

getShortcutInfo(bundleName :string, callback: AsyncCallback<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>>) : void;

Obtains the shortcut information of the current user based on the given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Name    | Type  | Mandatory| Description          |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name of the application.|

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| AsyncCallback\<Array<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>> | Callback used to return the **ShortcutInfo** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 17700001 | The specified bundle name is not found.  |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getShortcutInfo("com.example.demo", (errData, data) => {
        if (errData !== null) {
            console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
        }
        console.log("data is " + JSON.stringify(data));
    });
} catch (errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## launcherBundlemanager.getShortcutInfo<sup>9+</sup>

getShortcutInfo(bundleName : string) : Promise<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>>;

Obtains the shortcut information of the current user based on the given bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Name    | Type  | Mandatory| Description          |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name of the application.|

**Return value**

| Template                  | Description                                           |
| ---------------------- | ----------------------------------------------- |
| Promise\<Array<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>> | Promise used to return the **ShortcutInfo** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 17700001 | The specified bundle name is not found.  |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getShortcutInfo("com.example.demo").then(data => {
        console.log("data is " + JSON.stringify(data));
    }).catch (errData => {
        console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
    });
} catch (errData) {
    console.log(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```
