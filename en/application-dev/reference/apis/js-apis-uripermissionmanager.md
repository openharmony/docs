# @ohos.application.uriPermissionManager (URI Permission Management)

The **uriPermissionManager** module provides APIs for granting permissions on a file or revoking the granted permission from an application. The file is identified by a uniform resource identifier (URI).

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import


```ts
import uriPermissionManager from '@ohos.application.uriPermissionManager';
```


## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void

Grants permission on the file of the specified URI to an application. This API uses an asynchronous callback to return the result.

By default, an application can authorize its own URIs to another application. If the application has the **ohos.permission.PROXY_AUTHORIZATION_URI** permission, there is no such restriction.
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

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |
| 16000058 | Invalid URI flag. |
| 16000059 | Invalid URI type. |
| 16000060 | Sandbox application can not grant URI permission. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
    
  ```ts
  import uriPermissionManager from '@ohos.application.uriPermissionManager';
  import WantConstant from '@ohos.app.ability.wantConstant';
  import fs from '@ohos.file.fs';
  import fileUri from '@ohos.file.fileuri';

  let targetBundleName = 'com.example.test_case1'
  let path = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir";
  fs.mkdir(path, (err) => {
    if (err) {
      console.log("mkdir error"+err.message)
    } else {
      console.log("mkdir succeed")
    }
  });
  let uri = fileUri.getUriFromPath(path);
  uriPermissionManager.grantUriPermission(uri, WantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName, (result) => {
    console.log("result.code = " + result.code)
  })
  ```


## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string): Promise&lt;number&gt;

Grants permission on the file of the specified URI to an application. This API uses a promise to return the result.

By default, an application can authorize its own URIs to another application. If the application has the **ohos.permission.PROXY_AUTHORIZATION_URI** permission, there is no such restriction.
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

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |
| 16000058 | Invalid URI flag. |
| 16000059 | Invalid URI type. |
| 16000060 | Sandbox application can not grant URI permission. |

  For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
    
  ```ts
  import uriPermissionManager from '@ohos.application.uriPermissionManager';
  import WantConstant from '@ohos.app.ability.wantConstant';
  import fs from '@ohos.file.fs';
  import fileUri from '@ohos.file.fileuri';
  import { BusinessError } from '@ohos.base';

  let targetBundleName = 'com.example.test_case1'
  let path = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir";

  fs.mkdir(path, (err) => {
    if (err) {
      console.log("mkdir error"+err.message)
    } else {
      console.log("mkdir succeed")
    }
  });
  let uri = fileUri.getUriFromPath(path);
  uriPermissionManager.grantUriPermission(uri, WantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName)
    .then((data) => {
      console.log('Verification succeeded.' + data)
    }).catch((error: BusinessError) => {
    console.log('Verification failed.');
  })
  ```
## uriPermissionManager.revokeUriPermission

revokeUriPermission(uri: string, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void

Revokes the permission on the file of the specified URI from an application. This API uses an asynchronous callback to return the result.

By default, only the URIs obtained by the application itself or the URIs authorized by the application to other applications can be revoked. If the application has the **ohos.permission.PROXY_AUTHORIZATION_URI** permission, there is no such restriction.
**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.|
| targetBundleName | string | Yes| Bundle name of the application, from which the permission is revoked.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |
| 16000059 | Invalid URI type. |

  For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
    
  ```ts
  import uriPermissionManager from '@ohos.application.uriPermissionManager';

  let targetBundleName = 'com.example.test_case2'
  let uri = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir"
  uriPermissionManager.revokeUriPermission(uri, targetBundleName, (result) => {
      console.log("result.code = " + result.code)
  }) 
  ```


## uriPermissionManager.revokeUriPermission

revokeUriPermission(uri: string, targetBundleName: string): Promise&lt;number&gt;

Revokes the permission on the file of the specified URI from an application. This API uses a promise to return the result.


By default, only the URIs obtained by the application itself or the URIs authorized by the application to other applications can be revoked. If the application has the **ohos.permission.PROXY_AUTHORIZATION_URI** permission, there is no such restriction.
**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI


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

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |
| 16000059 | Invalid URI type. |

  For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
    
  ```ts
  import uriPermissionManager from '@ohos.application.uriPermissionManager';
  import { BusinessError } from '@ohos.base';

  let targetBundleName = 'com.example.test_case2'
  let uri = "file://com.example.test_case1/data/storage/el2/base/haps/entry_test/files/newDir"
  uriPermissionManager.revokeUriPermission(uri, targetBundleName)
  .then((data) => {
      console.log('Verification succeeded.' + data)
  }).catch((error: BusinessError) => {
      console.log('Verification failed.');
  })
  ```
