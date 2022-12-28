# appControl

The **appControl** module provides APIs for setting, obtaining, and deleting the disposed status of an application. An application in the disposed state is forbidden to run. When a user clicks the application icon on the home screen, the corresponding page is displayed based on the disposal intent.  

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

``` ts
import appControl from '@ohos.bundle.appControl'
```

## appControl.setDisposedStatus

setDisposedStatus(appId: string, disposedWant: Want): Promise\<void>

Sets the disposed status for an application. This API uses a promise to return the result. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br> **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-of-an-application).                   |
| disposedWant | Want  | Yes| Disposal intent of the application.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**Example**

```ts
var appId = "com.example.myapplication_xxxxx";
var want = {bundleName: 'com.example.myapplication'};

try {
    appControl.setDisposedStatus(appId, want)
        .then(() => {
            console.info('setDisposedStatus success');
        }).catch((error) => {
            console.error('setDisposedStatus failed ' + error.message);
        });
} catch (error) {
    console.error('setDisposedStatus failed ' + error.message);
}
```

## appControl.setDisposedStatus

setDisposedStatus(appId: string, disposedWant: Want, callback: AsyncCallback\<void>): void;

Sets the disposed status for an application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                             | Mandatory  | Description                                   |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br> **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-of-an-application).                          |
| disposedWant | Want  | Yes| Disposal intent of the application.|
| callback    | AsyncCallback\<void> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**Example**

```ts
var appId = "com.example.myapplication_xxxxx";
var want = {bundleName: 'com.example.myapplication'};

try {
    appControl.setDisposedStatus(appId, want, (error, data) => {
        if (error) {
            console.error('setDisposedStatus failed ' + error.message);
            return;
        }
        console.info('setDisposedStatus success');
    });
} catch (error) {
    console.error('setDisposedStatus failed ' + error.message);
}
```

## appControl.getDisposedStatus

getDisposedStatus(appId: string): Promise\<Want>;

Obtains the disposed status of an application. This API uses a promise to return the result. If the operation is successful, the disposed status of the application is returned. If the operation fails, an error message is returned.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br> **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-of-an-application).      |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<Want> | Promise used to return the disposed status.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**Example**

```ts
var appId = "com.example.myapplication_xxxxx";

try {
    appControl.getDisposedStatus(appId)
        .then((data) => {
            console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
        }).catch((error) => {
            console.error('getDisposedStatus failed ' + error.message);
        });
} catch (error) {
    console.error('getDisposedStatus failed ' + error.message);
}
```

## appControl.getDisposedStatus

getDisposedStatus(appId: string, callback: AsyncCallback\<Want>): void;

Obtains the disposed status of an application. This API uses an asynchronous callback to return the result. If the operation is successful, the disposed status of the application is returned. If the operation fails, an error message is returned.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type    | Mandatory  | Description                                 |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br> **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-of-an-application).      |
| callback    | AsyncCallback\<Want> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the disposed status obtained; otherwise, **err** is an error object.                   |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**Example**

```ts
var appId = "com.example.myapplication_xxxxx";

try {
    appControl.getDisposedStatus(appId, (error, data) => {
        if (error) {
            console.error('getDisposedStatus failed ' + error.message);
            return;
        }
        console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
    });
} catch (error) {
    console.error('getDisposedStatus failed ' + error.message);
}
```

## appControl.deleteDisposedStatus

deleteDisposedStatus(appId: string): Promise\<void>

Deletes the disposed status for an application. This API uses a promise to return the result. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br> **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-of-an-application).      |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**Example**

```ts
var appId = "com.example.myapplication_xxxxx";

try {
    appControl.deleteDisposedStatus(appId)
        .then(() => {
            console.info('deleteDisposedStatus success');
        }).catch((error) => {
            console.error('deleteDisposedStatus failed ' + error.message);
        });
} catch (error) {
    console.error('deleteDisposedStatus failed ' + error.message);
}
```

## appControl.deleteDisposedStatus

deleteDisposedStatus(appId: string, callback: AsyncCallback\<void>) : void

Deletes the disposed status for an application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br> **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-of-an-application).      |
| callback    | AsyncCallback\<void> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**Example**

```ts
var appId = "com.example.myapplication_xxxxx";
try {
    appControl.deleteDisposedStatus(appId, (error, data) => {
        if (error) {
            console.error('deleteDisposedStatus failed ' + error.message);
            return;
        }
        console.info('deleteDisposedStatus success');
    });
} catch (error) {
    console.error('deleteDisposedStatus failed ' + error.message);
}
```

## Obtaining appId of an Application

**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. It can be obtained by calling [getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo).

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';

var bundleName = 'com.example.myapplication';
var appId;
try {
    bundleManager.getBundleInfo(bundleName, bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO)
        .then((data) => {
            appId = data.signatureInfo.appId;
            console.info("appId is " + appId);
        }).catch((error) => {
            console.error("getBundleInfo failed " + error.message);
        });
} catch (error) {
    console.error("getBundleInfo failed " + error.message);
}
```
