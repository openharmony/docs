# @ohos.bundle.defaultAppManager (Default Application Management)

The **DefaultAppManager** module provides APIs to query whether the current application is the default application of a specific type.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
```

## defaultAppMgr.ApplicationType

Enumerates the default application types.

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

| Name  | Value| Description                                  |
| -------- | -------------------------------------- | -------------------------------------- |
| BROWSER  | 'Web Browser' | Default browser.                           |
| IMAGE    | 'Image Gallery' | Default image viewer.                        |
| AUDIO    | 'Audio Player' | Default audio player.                        |
| VIDEO    | 'Video Player' | Default video player.                        |
| PDF      | 'PDF Viewer' | Default PDF reader.                     |
| WORD     | 'Word Viewer' | Default Word viewer.                    |
| EXCEL    | 'Excel Viewer' | Default Excel viewer.                   |
| PPT      | 'PPT Viewer' | Default PowerPoint viewer.                     |
| EMAIL<sup>12+</sup>    | 'Email' | Default email.                     |

## defaultAppMgr.isDefaultApplication

isDefaultApplication(type: string): Promise\<boolean>

Checks whether this application is the default application of a system-defined application type. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](#defaultappmgrapplicationtype).                          |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<boolean> | Promise used to return the result. If the application is the default application, `true` is returned; otherwise, `false` is returned.|


**Example**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
import { BusinessError } from '@ohos.base';

defaultAppMgr.isDefaultApplication(defaultAppMgr.ApplicationType.BROWSER)
  .then((data) => {
    console.info('Operation successful. IsDefaultApplication ? ' + JSON.stringify(data));
  }).catch((error: BusinessError) => {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
});
```

## defaultAppMgr.isDefaultApplication

isDefaultApplication(type: string, callback: AsyncCallback\<boolean>): void

Checks whether this application is the default application of a system-defined application type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**Parameters**

| Name        | Type                             | Mandatory  | Description                                     |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| type  | string                          | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](#defaultappmgrapplicationtype).                           |
| callback    | AsyncCallback\<boolean> | Yes   | Callback used to return the result. If the application is the default application, `true` is returned; otherwise, `false` is returned.|

**Example**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
import { BusinessError } from '@ohos.base';

defaultAppMgr.isDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. IsDefaultApplication ? ' + JSON.stringify(data));
});
```

## defaultAppMgr.isDefaultApplicationSync<sup>10+</sup>

isDefaultApplicationSync(type: string): boolean

Checks whether this application is the default application of a system-defined application type. This API is a synchronous API.

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| -------| ------ | ---- | --------------------------------------- |
|  type  | string | Yes  | Type of the target application. It must be set to a value defined by [ApplicationType](#defaultappmgrapplicationtype).  |

**Return value**

| Type   | Description                |
| ------- | -------------------- |
| boolean | Returns **true** if the application is the default application; returns **false** otherwise.|


**Example**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
try {
  let data = defaultAppMgr.isDefaultApplicationSync(defaultAppMgr.ApplicationType.BROWSER)
  console.info('Operation successful. IsDefaultApplicationSync ? ' + JSON.stringify(data));
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};
```
