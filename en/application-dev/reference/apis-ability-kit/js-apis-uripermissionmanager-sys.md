# @ohos.application.uriPermissionManager (URI Permission Management) (System API)

The **uriPermissionManager** module provides APIs for granting permissions on a file or revoking the granted permission from an application. The file is identified by a uniform resource identifier (URI).

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

Grants the permission on a URI to an application. This API uses an asynchronous callback to return the result.

An application can grant its own URIs to another application. If it has the ohos.permission.PROXY_AUTHORIZATION_URI permission, it can also grant the any accessible URI of another application.
**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.|
| flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags) | Yes| Read or write permission on the file to grant.|
| targetBundleName | string | Yes| Bundle name of the application, to which the permission is granted.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.|

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
| 16000060 | Sandbox application can not grant URI permission. |


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

Grants the permission on a URI to an application. This API uses a promise to return the result.

An application can grant its own URIs to another application. If it has the ohos.permission.PROXY_AUTHORIZATION_URI permission, it can also grant the any accessible URI of another application.
**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.|
| flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags) | Yes| Read or write permission on the file to grant.|
| targetBundleName | string | Yes| Bundle name of the application, to which the permission is granted.|

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
| 16000060 | Sandbox application can not grant URI permission. |

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

## uriPermissionManager.revokeUriPermission

revokeUriPermission(uri: string, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void

Revokes the URI permission from an application. This API uses an asynchronous callback to return the result.

This API can be used to revoke the URI permission of another application obtained by this application or URI permission granted by this application.
**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.|
| targetBundleName | string | Yes| Bundle name of the application, from which the permission is revoked.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.|

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


This API can be used to revoke the URI permission of another application obtained by this application or URI permission granted by this application.
**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.|
| targetBundleName | string | Yes| Bundle name of the application, from which the permission is revoked.|

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
