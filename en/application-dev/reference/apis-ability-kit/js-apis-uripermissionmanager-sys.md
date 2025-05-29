# @ohos.application.uriPermissionManager (URI Permission Management) (System API)

The **uriPermissionManager** module provides capabilities for granting the permission on a file to another application and revoking the granted permissions. The file is identified by a uniform resource identifier (URI).

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import


```ts
import { uriPermissionManager } from '@kit.AbilityKit';
```


## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void

Grants the URI permission to an application. If the call is successful, the application obtains the permission to access the file specified by the URI. Once the application exits, the permission will be automatically revoked. For details about how to access the file based on the URI, see [Sharing an Application File](../../file-management/share-app-file.md). This API uses an asynchronous callback to return the result.

> **NOTE**
>
> If an application has the ohos.permission.PROXY_AUTHORIZATION_URI permission, it can grant the accessible URIs of another application. If the application does not have this permission, it can grant only its own URI permissions.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file. The scheme has a fixed value of **file**. For details, see [FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10).|
| flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#flags) | Yes| Read or write permission on the file to grant.|
| targetBundleName | string | Yes| Bundle name of the target application.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 16000050 | Internal error. |
| 16000058 | Invalid URI flag. |
| 16000059 | Invalid URI type. |
| 16000060 | A sandbox application cannot grant URI permission. |


**Example**
    
  ```ts
  import { uriPermissionManager, wantConstant } from '@kit.AbilityKit';
  import { fileIo, fileUri } from '@kit.CoreFileKit';

  let targetBundleName = 'com.example.test_case1'
  let path = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir";
  fileIo.mkdir(path, (err) => {
    if (err) {
      console.log("mkdir error" + err.message);
    } else {
      console.log("mkdir succeed");
    }
  });
  let uri = fileUri.getUriFromPath(path);
  uriPermissionManager.grantUriPermission(uri, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName, (result) => {
    console.log("result.code = " + result.code);
  });
  ```


## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string): Promise&lt;number&gt;

Grants the URI permission to an application. If the call is successful, the application obtains the permission to access the file specified by the URI. Once the application exits, the permission will be automatically revoked. For details about how to access the file based on the URI, see [Sharing an Application File](../../file-management/share-app-file.md). This API uses a promise to return the result.

> **NOTE**
>
> If an application has the ohos.permission.PROXY_AUTHORIZATION_URI permission, it can grant the accessible URIs of another application. If the application does not have this permission, it can grant only its own URI permissions.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file. The scheme has a fixed value of **file**. For details, see [FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10).|
| flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#flags) | Yes| Read or write permission on the file to grant.|
| targetBundleName | string | Yes| Bundle name of the target application.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 16000050 | Internal error. |
| 16000058 | Invalid URI flag. |
| 16000059 | Invalid URI type. |
| 16000060 | A sandbox application cannot grant URI permission. |

**Example**
    
  ```ts
  import { uriPermissionManager, wantConstant } from '@kit.AbilityKit';
  import { fileIo, fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let targetBundleName = 'com.example.test_case1'
  let path = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir";

  fileIo.mkdir(path, (err) => {
    if (err) {
      console.log("mkdir error" + err.message);
    } else {
      console.log("mkdir succeed");
    }
  });
  let uri = fileUri.getUriFromPath(path);
  uriPermissionManager.grantUriPermission(uri, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName)
    .then((data) => {
      console.log('Verification succeeded.' + data);
    }).catch((error: BusinessError) => {
    console.log('Verification failed.');
  });
  ```

## uriPermissionManager.grantUriPermission<sup>14+</sup>

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string, appCloneIndex: number): Promise&lt;void&gt;

Grants the URI permission to an application. If the call is successful, the application obtains the permission to access the file specified by the URI. Once the application exits, the permission will be automatically revoked. For details about how to access the file based on the URI, see [Sharing an Application File](../../file-management/share-app-file.md). This API uses a promise to return the result.

> **NOTE**
> 
>- If an application has the ohos.permission.PROXY_AUTHORIZATION_URI permission, it can grant the accessible URIs of another application. If the application does not have this permission, it can grant only its own URI permissions.
>- This API can be used to grant URI access permission to a cloned application. You need to specify the application bundle name and index of the cloned application.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file. The scheme has a fixed value of **file**. For details, see [FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10).|
| flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#flags) | Yes| Read or write permission on the file to grant.|
| targetBundleName | string | Yes| Bundle name of the target application.|
| appCloneIndex | number | Yes| Index of the cloned application. The value range is [0, 1000]. The value **0** indicates the application itself.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 16000050 | Internal error. |
| 16000058 | Invalid URI flag. |
| 16000059 | Invalid URI type. |
| 16000060 | A sandbox application cannot grant URI permission. |
| 16000081 | Get target application info failed. |

**Example**

  ```ts
  import { AbilityConstant, UIAbility, Want, wantConstant, uriPermissionManager } from '@kit.AbilityKit';
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    }

    onForeground(): void {
      let targetBundleName: string = 'com.example.demo1';
      let filePath: string = this.context.filesDir + "/test.txt";
      let uri: string = fileUri.getUriFromPath(filePath);
      // grant uri permission to main application
      try {
        let appCloneIndex: number = 0;
        uriPermissionManager.grantUriPermission(uri, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName,
          appCloneIndex)
          .then(() => {
            console.log('grantUriPermission succeeded.');
          }).catch((error: BusinessError) => {
          console.error(`grantUriPermission failed. error: ${JSON.stringify(error)}.`);
        });
      } catch (error) {
        console.error(`grantUriPermission failed. error: ${JSON.stringify(error)}.`);
      }

      // grant uri permission to clone application
      try {
        let appCloneIndex: number = 1;
        uriPermissionManager.grantUriPermission(uri, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName,
          appCloneIndex)
          .then(() => {
            console.log('grantUriPermission succeeded.');
          }).catch((error: BusinessError) => {
          console.error(`grantUriPermission failed. error: ${JSON.stringify(error)}.`);
        });
      } catch (error) {
        console.error(`grantUriPermission failed. error: ${JSON.stringify(error)}.`);
      }
    }
  }

  ```

## uriPermissionManager.revokeUriPermission

revokeUriPermission(uri: string, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void

Revokes the URI permission from an application. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API can be used to revoke the URI permission of another application obtained by this application or URI permission granted by this application.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file. The scheme has a fixed value of **file**. For details, see [FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10).|
| targetBundleName | string | Yes| Bundle name of the application, from which the permission is revoked.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 16000050 | Internal error. |
| 16000059 | Invalid URI type. |

**Example**
    
  ```ts
  import { uriPermissionManager } from '@kit.AbilityKit';

  let targetBundleName = 'com.example.test_case2';
  let uri = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir";

  uriPermissionManager.revokeUriPermission(uri, targetBundleName, (result) => {
    console.log("result.code = " + result.code);
  });
  ```


## uriPermissionManager.revokeUriPermission

revokeUriPermission(uri: string, targetBundleName: string): Promise&lt;number&gt;

Revokes the URI permission from an application. This API uses a promise to return the result.

> **NOTE**
> 
> This API can be used to revoke the URI permission of another application obtained by this application or URI permission granted by this application.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file. The scheme has a fixed value of **file**. For details, see [FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10).|
| targetBundleName | string | Yes| Bundle name of the target application.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 16000050 | Internal error. |
| 16000059 | Invalid URI type. |


**Example**
    
  ```ts
  import { uriPermissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let targetBundleName = 'com.example.test_case2';
  let uri = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir";

  uriPermissionManager.revokeUriPermission(uri, targetBundleName)
    .then((data) => {
      console.log('Verification succeeded.' + data);
    }).catch((error: BusinessError) => {
    console.log('Verification failed.');
  });
  ```
## uriPermissionManager.revokeUriPermission<sup>14+</sup>

revokeUriPermission(uri: string, targetBundleName: string, appCloneIndex: number): Promise&lt;void&gt;

Revokes the URI permission from an application. This API uses a promise to return the result.

> **NOTE**
> 
>- This API can be used to revoke the URI permission of another application obtained by this application or URI permission granted by this application.
>- This API can be used to revoke the URI permissions granted to a cloned application. You need to specify the application bundle name and index of the cloned application.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file. The scheme has a fixed value of **file**. For details, see [FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10).|
| targetBundleName | string | Yes| Bundle name of the target application.|
| appCloneIndex | number | Yes| Index of the cloned application. The value range is [0, 1000]. The value **0** indicates the application itself.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 16000050 | Internal error. |
| 16000059 | Invalid URI type. |
| 16000081 | Get target application info failed. |

**Example**

  ```ts

  import { AbilityConstant, UIAbility, Want, wantConstant, uriPermissionManager } from '@kit.AbilityKit';
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    }

    onForeground(): void {
      let targetBundleName: string = 'com.example.demo1';
      let filePath: string = this.context.filesDir + "/test.txt";
      let uri: string = fileUri.getUriFromPath(filePath);
      // revoke uri permission of main application
      try {
        let appCloneIndex: number = 0;
        uriPermissionManager.revokeUriPermission(uri, targetBundleName, appCloneIndex)
          .then(() => {
            console.log('revokeUriPermission succeeded.');
          }).catch((error: BusinessError) => {
          console.error(`revokeUriPermission failed. error: ${JSON.stringify(error)}.`);
        });
      } catch (error) {
        console.error(`revokeUriPermission failed. error: ${JSON.stringify(error)}.`);
      }

      // revoke uri permission of clone application
      try {
        let appCloneIndex: number = 0;
        uriPermissionManager.revokeUriPermission(uri, targetBundleName, appCloneIndex)
          .then(() => {
            console.log('revokeUriPermission succeeded.');
          }).catch((error: BusinessError) => {
          console.error(`revokeUriPermission failed. error: ${JSON.stringify(error)}.`);
        });
      } catch (error) {
        console.error(`revokeUriPermission failed. error: ${JSON.stringify(error)}.`);
      }
    }
  }
  ```
