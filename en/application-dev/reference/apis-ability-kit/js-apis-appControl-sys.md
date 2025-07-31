# @ohos.bundle.appControl (appControl) (System API)

The module provides APIs for setting, obtaining, and deleting the disposed status of an application. An application in the disposed status is forbidden to run. When a user clicks the application icon on the home screen, the corresponding page is displayed based on the disposal intent.  

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

``` ts
import appControl from '@ohos.bundle.appControl';
```

## appControl.setDisposedStatus

setDisposedStatus(appId: string, disposedWant: Want): Promise\<void>

Sets the disposed status for an application. This API uses a promise to return the result. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).              |
| disposedWant | Want  | Yes| Disposal intent of the application.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';
import appControl from '@ohos.bundle.appControl';

let appId = "com.example.myapplication_xxxxx";
let want:Want = {bundleName: 'com.example.myapplication'};

try {
    appControl.setDisposedStatus(appId, want)
        .then(() => {
            console.info('setDisposedStatus success');
        }).catch((error: BusinessError) => {
            let message = (error as BusinessError).message;
            console.error('setDisposedStatus failed ' + message);
        });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('setDisposedStatus failed ' + message);
}
```

## appControl.setDisposedStatus

setDisposedStatus(appId: string, disposedWant: Want, callback: AsyncCallback\<void>): void;

Sets the disposed status for an application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type                             | Mandatory  | Description                                   |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).                     |
| disposedWant | Want  | Yes| Disposal intent of the application.|
| callback    | AsyncCallback\<void> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';

let appId = "com.example.myapplication_xxxxx";
let want: Want = {bundleName: 'com.example.myapplication'};

try {
  appControl.setDisposedStatus(appId, want, (error: BusinessError, data) => {
    if (error) {
      let message = (error as BusinessError).message;
      console.error('setDisposedStatus failed ' + message);
      return;
    }
    console.info('setDisposedStatus success');
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('setDisposedStatus failed ' + message);
}
```

## appControl.setDisposedStatusSync<sup>10+</sup>

setDisposedStatusSync(appId: string, disposedWant: Want): void;

Sets the disposed status for an application. This API returns the result synchronously. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl


**Parameters**

| Name      | Type                             | Mandatory  | Description                                   |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).                     |
| disposedWant | Want  | Yes| Disposal intent of the application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';

let appId: string = "com.example.myapplication_xxxxx";
let want: Want = {bundleName: 'com.example.myapplication'};

try {
  appControl.setDisposedStatusSync(appId, want);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('setDisposedStatusSync failed ' + message);
}
```

## appControl.getDisposedStatus

getDisposedStatus(appId: string): Promise\<Want>;

Obtains the disposed status of an application. This API uses a promise to return the result. If the operation is successful, the disposed status of the application is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application). |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<Want> | Promise used to return the disposed status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';

let appId = "com.example.myapplication_xxxxx";

try {
  appControl.getDisposedStatus(appId)
    .then((data) => {
      console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
    }).catch((error: BusinessError) => {
    let message = (error as BusinessError).message;
    console.error('getDisposedStatus failed ' + message);
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getDisposedStatus failed ' + message);
}
```

## appControl.getDisposedStatus

getDisposedStatus(appId: string, callback: AsyncCallback\<Want>): void;

Obtains the disposed status of an application. This API uses an asynchronous callback to return the result. If the operation is successful, the disposed status of the application is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                 |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application). |
| callback    | AsyncCallback\<Want> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the disposed status obtained; otherwise, **err** is an error object.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';

let appId = "com.example.myapplication_xxxxx";

try {
  appControl.getDisposedStatus(appId, (error, data) => {
    if (error) {
      let message = (error as BusinessError).message;
      console.error('getDisposedStatus failed ' + message);
      return;
    }
    console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getDisposedStatus failed ' + message);
}
```

## appControl.getDisposedStatusSync<sup>10+</sup>

getDisposedStatusSync(appId: string): Want;

Obtains the disposed status of an application. This API returns the result synchronously. If the operation is successful, the disposed status of the application is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | ID of the target application.<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application). |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Want | Disposed status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';

let appId: string = "com.example.myapplication_xxxxx";
let want: Want;

try {
    want = appControl.getDisposedStatusSync(appId);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getDisposedStatusSync failed ' + message);
}
```

## appControl.deleteDisposedStatus

deleteDisposedStatus(appId: string): Promise\<void>

Deletes the disposed status for an application. This API uses a promise to return the result. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | appId or appIdentifier of the target application. If a rule is set using appId, it must be deleted using appId; the same principle applies to appIdentifier.<br>**NOTE**<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).<br>[appIdentifier](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) is also the unique identifier of an application. It is a random string allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers. For details about how to obtain the value, see [Obtaining appIdentifier of an Application](#obtaining-appid-and-appidentifier-of-an-application). |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';

let appId = "com.example.myapplication_xxxxx";

try {
  appControl.deleteDisposedStatus(appId)
    .then(() => {
      console.info('deleteDisposedStatus success');
    }).catch((error: BusinessError) => {
      let message = (error as BusinessError).message;
      console.error('deleteDisposedStatus failed ' + message);
  });
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('deleteDisposedStatus failed ' + message);
}
```

## appControl.deleteDisposedStatus

deleteDisposedStatus(appId: string, callback: AsyncCallback\<void>) : void

Deletes the disposed status for an application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | appId or appIdentifier of the target application. If a rule is set using appId, it must be deleted using appId; the same principle applies to appIdentifier.<br>**NOTE**<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).<br>[appIdentifier](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) is also the unique identifier of an application. It is a random string allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers. For details about how to obtain the value, see [Obtaining appIdentifier of an Application](#obtaining-appid-and-appidentifier-of-an-application). |
| callback    | AsyncCallback\<void> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**. otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';

let appId = "com.example.myapplication_xxxxx";
try {
  appControl.deleteDisposedStatus(appId, (error: BusinessError, data) => {
    if (error) {
      console.error('deleteDisposedStatus failed ' + error.message);
      return;
    }
    console.info('deleteDisposedStatus success');
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('deleteDisposedStatus failed ' + message);
}
```

## appControl.deleteDisposedStatusSync<sup>10+</sup>

deleteDisposedStatusSync(appId: string, appIndex:? number) : void

Deletes the disposed status for an application or an application clone. This API returns the result synchronously. If the operation is successful, **null** is returned. If the operation fails, an error message is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | appId or appIdentifier of the target application. If a rule is set using appId, it must be deleted using appId; the same principle applies to appIdentifier.<br>**NOTE**<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).<br>[appIdentifier](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) is also the unique identifier of an application. It is a random string allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers. For details about how to obtain the value, see [Obtaining appIdentifier of an Application](#obtaining-appid-and-appidentifier-of-an-application). |
| appIndex<sup>12+</sup>   | number  | No  | Index of the application clone. The default value is **0**.<br>The value **0** means to delete the disposed status of the main application. A value greater than 0 means to delete the disposed status of the application clone. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |
| 17700061 | AppIndex is not in the valid range. |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';

let appId: string = "com.example.myapplication_xxxxx";

try {
    appControl.deleteDisposedStatusSync(appId, 1);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('deleteDisposedStatusSync failed ' + message);
}
```

## Obtaining appId and appIdentifier of an Application

**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. It can be obtained by calling [getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo14).<br>
[appIdentifier](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) is also the unique identifier of an application. It is a random string allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers.

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'com.example.myapplication';
let appId: string;
let appIdentifier: string;
try {
  bundleManager.getBundleInfo(bundleName, bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO)
    .then((data) => {
      appId = data.signatureInfo.appId;
      appIdentifier = data.signatureInfo.appIdentifier;
      console.info("appId is " + appId);
      console.info("appIdentifier is " + appIdentifier);
    }).catch((error: BusinessError) => {
      let message = (error as BusinessError).message;
      console.error("getBundleInfo failed " + message);
  });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error("getBundleInfo failed " + message);
}
```

## appControl.getDisposedRule<sup>11+</sup>

getDisposedRule(appId: string, appIndex:? number): DisposedRule

Obtains the disposed rule of an application or an application clone.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | appId or appIdentifier of the target application. If a rule is set using appId, it must be obtained using appId; the same principle applies to appIdentifier.<br>**NOTE**<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).<br>[appIdentifier](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) is also the unique identifier of an application. It is a random string allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers. For details about how to obtain the value, see [Obtaining appIdentifier of an Application](#obtaining-appid-and-appidentifier-of-an-application). |
| appIndex<sup>12+</sup>   | number  | No  | Index of the application clone. The default value is **0**.<br>The value **0** means to obtain the disposed rule of the main application. A value greater than 0 means to obtain the disposed rule of the application clone with the specified index.   |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| [DisposedRule](#disposedrule11) | Disposed rule of the application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |
| 17700061 | AppIndex is not in the valid range. |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';

let appId = "com.example.myapplication_xxxxx";

try {
  let data = appControl.getDisposedRule(appId, 1);
  console.info('getDisposedRule successfully. Data: ' + JSON.stringify(data));
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('getDisposedRule failed ' + message);
}
```

## appControl.setDisposedRule<sup>11+</sup>

setDisposedRule(appId: string, rule: DisposedRule, appIndex:? number): void

Sets the disposed rule for an application or an application clone.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | Yes   | appId or appIdentifier of the target application. If a rule is set using appId, it overwrites the one set with appIdentifier, and the reverse is also true.<br>**NOTE**<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).<br>[appIdentifier](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) is also the unique identifier of an application. It is a random string allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers. For details about how to obtain the value, see [Obtaining appIdentifier of an Application](#obtaining-appid-and-appidentifier-of-an-application). |
| rule | [DisposedRule](#disposedrule11) | Yes| Disposed rule to set.|
| appIndex<sup>12+</sup>   | number  | No  | Index of the application clone. The default value is **0**.<br>The value **0** means to set the disposed rule for the main application. A value greater than 0 means to set the disposed rule for the application clone with the specified index.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700005 |  The specified app ID is an empty string.  |
| 17700061 | AppIndex is not in the valid range. |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';
import bundleManager from '@ohos.bundle.bundleManager';

let appId = "com.example.myapplication_xxxxx";
let want: Want = {
  bundleName: "com.example.myapplication",
  moduleName: "entry",
  abilityName: "EntryAbility"
};
let elementName: bundleManager.ElementName = {
  bundleName: "com.example.myapplication",
  moduleName: "entry",
  abilityName: "EntryAbility"
};
let rule: appControl.DisposedRule = {
  want: want,
  componentType: appControl.ComponentType.UI_ABILITY,
  disposedType: appControl.DisposedType.BLOCK_APPLICATION,
  controlType: appControl.ControlType.ALLOWED_LIST,
  elementList: [
    elementName
  ],
  priority: 100
};

try {
  appControl.setDisposedRule(appId, rule, 1);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('setDisposedRule failed ' + message);
}
```

## appControl.setDisposedRules<sup>20+</sup>

setDisposedRules(disposedRuleConfigurations: Array\<DisposedRuleConfiguration\>): void

Sets disposed rules in batches for an application or an application clone.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name                    | Type                                                        | Mandatory| Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| disposedRuleConfigurations | Array<[DisposedRuleConfiguration](#disposedruleconfiguration20)> | Yes  | Configuration for the disposed rules in batches, including the appId of the target application, the index of the application clone, and the rules themselves. The maximum number of disposed rules in an array is 1000.<br>**NOTE**<br>1. If multiple **DisposedRuleConfiguration** entries in the array have the same appId and appIndex, the later entry will overwrite the earlier one.<br>2. If an application already has set disposed rules, re-setting the rules will replace the existing ones. Identical appId and appIndex values indicate the same application instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied. A non-system application is not allowed to call a system API. |
| 801      | Capability not supported.                                    |
| 17700005 | The specified app ID is invalid.                             |
| 17700061 | AppIndex is not in the valid range.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { appControl, Want, bundleManager } from '@kit.AbilityKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  moduleName: 'entry',
  abilityName: 'EntryAbility'
};
let elementName: bundleManager.ElementName = {
  bundleName: 'com.example.myapplication',
  moduleName: 'entry',
  abilityName: 'EntryAbility'
};
let rule: appControl.DisposedRule = {
  want: want,
  componentType: appControl.ComponentType.UI_ABILITY,
  disposedType: appControl.DisposedType.BLOCK_APPLICATION,
  controlType: appControl.ControlType.ALLOWED_LIST,
  elementList: [
    elementName
  ],
  priority: 100
};

let disposedRuleConfiguration: appControl.DisposedRuleConfiguration = {
  appId: 'com.example.myapplication_BInGTMPMdc6v55s/UFIJHL5NLREXjOuxm/DsyMhlFmLAZC9/Gk+ruqS9OZr/dvFuaIaQQL1pKolvzK/zYNHvJ/I=',
  appIndex: 0,
  disposedRule: rule,
};

let disposedRuleConfigurations: Array<appControl.DisposedRuleConfiguration> = [];
disposedRuleConfigurations.push(disposedRuleConfiguration);
@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('setDisposedRules', { type: ButtonType.Normal })
          .onClick(() => {
            try {
              appControl.setDisposedRules(disposedRuleConfigurations);
              console.info('setDisposedRules success');
            } catch (error) {
              let err: BusinessError = error as BusinessError;
              console.error(`setDisposedRules failed, errCode:${err.code}, message:${err.message}`);
            }
          });
      }
    }
  }
}
```

## appControl.setUninstallDisposedRule<sup>15+</sup>

setUninstallDisposedRule(appIdentifier: string, rule: UninstallDisposedRule, appIndex:? number): void

Sets an uninstallation disposed rule for an application or an application clone.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appIdentifier  | string | Yes   | appIdentifier of the target application.<br>If the application does not have an appIdentifier, use its appId instead. **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application). |
| rule | [UninstallDisposedRule](#uninstalldisposedrule15) | Yes| Uninstallation disposed rule.|
| appIndex   | number  | No  | Index of the application clone. The default value is **0**.<br>The value **0** means to set the uninstallation disposed rule for the main application. A value greater than 0 means to set the uninstallation disposed rule for the application clone.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied. A non-system application is not allowed to call a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. |
| 17700061 | AppIndex is not in the valid range. |
| 17700074 | The specified appIdentifier is invalid. |
| 17700075 | The specified bundleName of want is not the same with caller. |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';
import Want from '@ohos.app.ability.Want';

let appIdentifier = "com.example.myapplication_xxxxx";
let want: Want = {
  bundleName: "com.example.myapplication",
  moduleName: "entry",
  abilityName: "EntryAbility"
};
let rule: appControl.UninstallDisposedRule = {
  want: want,
  uninstallComponentType: appControl.UninstallComponentType.EXTENSION,
  priority: 100
};

try {
  appControl.setUninstallDisposedRule(appIdentifier, rule, 1);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('setUninstallDisposedRule failed ' + message);
}
```

## appControl.getUninstallDisposedRule<sup>15+</sup>

getUninstallDisposedRule(appIdentifier: string, appIndex:? number): UninstallDisposedRule

Obtains the uninstallation disposed rule of an application or an application clone.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS or ohos.permission.GET_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appIdentifier  | string | Yes   | appIdentifier of the target application.<br>If the application does not have an appIdentifier, use its appId instead. **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application). |
| appIndex   | number  | No  | Index of the application clone. The default value is **0**.<br>The value **0** means to obtain the uninstallation disposed rule of the main application. A value greater than 0 means to obtain the uninstallation disposed rule of the application clone.             |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| [UninstallDisposedRule](#uninstalldisposedrule15) | Uninstallation disposed rule.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied. A non-system application is not allowed to call a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. |
| 17700061 | AppIndex is not in the valid range. |
| 17700074 | The specified appIdentifier is invalid. |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';

let appIdentifier = "com.example.myapplication_xxxxx";

try {
  let data = appControl.getUninstallDisposedRule(appIdentifier, 1);
  console.info('getUninstallDisposedRule successfully. Data: ' + JSON.stringify(data));
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('getUninstallDisposedRule failed ' + message);
}
```

## appControl.deleteUninstallDisposedRule<sup>15+</sup>

deleteUninstallDisposedRule(appIdentifier: string, appIndex:? number): void

Deletes an uninstallation disposed rule for an application or an application clone.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| appIdentifier  | string | Yes   | appIdentifier of the target application.<br>If the application does not have an appIdentifier, use its appId instead. **appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain **appId**, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application). |
| appIndex   | number  | No  | Index of the application clone. The default value is **0**.<br>The value **0** means to delete the uninstallation disposed rule of the main application. A value greater than 0 means to delete the uninstallation disposed rule of the application clone.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied. A non-system application is not allowed to call a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. |
| 17700061 | AppIndex is not in the valid range. |
| 17700074 | The specified appIdentifier is invalid. |

**Example**

```ts
import appControl from '@ohos.bundle.appControl';
import { BusinessError } from '@ohos.base';

let appIdentifier = "com.example.myapplication_xxxxx";

try {
  appControl.deleteUninstallDisposedRule(appIdentifier, 1);
} catch (error) {
  let message = (error as BusinessError).message;
  console.error('deleteUninstallDisposedRule failed ' + message);
}
```

## DisposedRule<sup>11+</sup>

Defines a disposed rule.

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API.

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| want | [Want](js-apis-app-ability-want.md)     | No  | No  | Page displayed when the application is disposed of.|
| componentType | [ComponentType](#componenttype11)  | No  | No  | Type of application component that functions as the displayed page.|
| disposedType | [DisposedType](#disposedrule11) | No  | No| Type of application disposal.|
| controlType | [ControlType](#controltype11) | No  | No| Control type of application disposal.|
| elementList | Array\<[ElementName](js-apis-bundleManager-elementName.md)> | No  | No| List of application components to be disposed of or exempted.|
| priority | number | No  | No| Priority of the disposed rule, which is used to sort the query results of the rule list. The value is an integer. A smaller value indicates a higher priority.|

### ComponentType<sup>11+</sup>

Enumerates the types of application components that function as the displayed page.

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API.

| Name   | Value  | Description                |
| ------- | ---- | -------------------- |
| UI_ABILITY | 1    | UIAbility component.|
| UI_EXTENSION | 2    | UIExtensionAbility component.|

### DisposedType<sup>11+</sup>

Enumerates the types of application disposals.

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API.

| Name   | Value  | Description                |
| ------- | ---- | -------------------- |
| BLOCK_APPLICATION | 1    | All abilities of the application are blocked. That is, the entire application is blocked.|
| BLOCK_ABILITY | 2    | A specific ability of the application is blocked.|
| NON_BLOCK | 3 | The application is not blocked.|

### ControlType<sup>11+</sup>

Enumerates the control type of application disposal.

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

**System API**: This is a system API.

| Name   | Value  | Description                |
| ------- | ---- | -------------------- |
| ALLOWED_LIST | 1    | A trustlist is used, which means that the application components in the list are allowed to run.|
| DISALLOWED_LIST | 2    | A blocklist is used, which means that the application components in the list are forbidden to run.|

## UninstallDisposedRule<sup>15+</sup>

Describes an uninstallation disposed rule.

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

 **System API**: This is a system API.

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| want | [Want](js-apis-app-ability-want.md)     | No  | No  | Page displayed when the application is disposed of.|
| UninstallComponentType | [UninstallComponentType](#uninstallcomponenttype15)  | No  | No  | Type of the ability to start during interception.|
| priority | number | No| No| Priority of the disposed rule, which is used to sort the query results of the rule list. The value is an integer. A smaller value indicates a higher priority.|

### UninstallComponentType<sup>15+</sup>

Enumerates the types of abilities during uninstallation.

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

 **System API**: This is a system API.

| Name   | Value  | Description                |
| ------- | ---- | -------------------- |
| EXTENSION | 1    | Extension ability.|

## DisposedRuleConfiguration<sup>20+</sup>

Describes the configurations for setting disposed rules in batches.

**System capability**: SystemCapability.BundleManager.BundleFramework.AppControl

 **System API**: This is a system API.

| Name        | Type                           | Read-Only| Optional| Description                                                        |
| ------------ | ------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| appId        | string                          | No  | No  | appId or appIdentifier of the target application. Identical appId and appIndex values indicate the same application instance. If a rule is set using appId, it overwrites the one set with appIdentifier, and the reverse is also true.<br>**NOTE**<br>**appId** is the unique identifier of an application and is determined by the bundle name and signature information of the application. For details about how to obtain appId, see [Obtaining appId of an Application](#obtaining-appid-and-appidentifier-of-an-application).<br>appIdentifier is the unique ID of the application. It is the [app ID](https://developer.huawei.com/consumer/en/doc/app/agc-help-createharmonyapp-0000001945392297), which is a random string, allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers. For details about how to obtain appIdentifier, see [Obtaining appIdentifier of an application](#obtaining-appid-and-appidentifier-of-an-application).|
| appIndex     | number                          | No  | No  | Index of the application clone. The default value is **0**.<br>The value **0** means to set the disposed rules for the main application. A value greater than 0 means to set the disposed rules for the application clone with the specified index.|
| disposedRule | [DisposedRule](#disposedrule11) | No  | No  | Disposal rule of the application, including the type of the ability to be started during disposal.        |
