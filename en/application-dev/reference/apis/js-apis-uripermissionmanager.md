# @ohos.application.uriPermissionManager (URI Permission Management)
> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


The **uriPermissionManager** module provides APIs for granting permissions on a file to or revoking the granted permission from an application. The file is identified by a uniform resource identifier (URI).

## Modules to Import

  
```js
import uriPermissionManager from '@ohos.application.uriPermissionManager';
```

## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void;

Grants permission on the file of the specified URI to an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | uri | string | Yes| URI of the file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.| 
  | flag | [wantConstant.Flags](js-apis-ability-wantConstant.md#wantconstantflags) | Yes| Read or write permission on the file to grant.| 
  | targetBundleName | string | Yes| Bundle name of the application, to which the permission is granted.| 
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.| 

**Error codes**

  | ID| Error Message|
  | -------- | -------- |
  | 201 | Permissions denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | The parameter check failed. |
  | 16500050 | Internal error. |
  | 16500058 | Invalid URI flag. |
  | 16500059 | Invalid URI type. |
  | 16500060 | Sandbox application can not grant URI permission. |

**Example**
    
  ```js
  import WantConstant from '@ohos.ability.wantConstant';
  let targetBundleName = 'com.example.test_case1'
  let uri = "fileshare:///com.samples.filesharetest.FileShare/person/10"
  uriPermissionManager.grantUriPermission(uri, WantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName, (result) => {
      console.log("result.code = " + result.code)
  }) 
  ```


## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string): Promise&lt;number&gt;

Grants permission on the file of the specified URI to an application. This API uses a promise to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PROXY_AUTHORIZATION_URI

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | uri | string | Yes| URI of the file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.| 
  | flag | [wantConstant.Flags](js-apis-ability-wantConstant.md#wantconstantflags) | Yes| Read or write permission on the file to grant.| 
  | targetBundleName | string | Yes| Bundle name of the application, to which the permission is granted.|  

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, **0** is returned; otherwise, **-1** is returned.| 

**Error codes**

  | ID| Error Message|
  | -------- | -------- |
  | 201 | Permissions denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | The parameter check failed. |
  | 16500050 | Internal error. |
  | 16500058 | Invalid URI flag. |
  | 16500059 | Invalid URI type. |
  | 16500060 | Sandbox application can not grant URI permission. |

**Example**
    
  ```js
  import WantConstant from '@ohos.ability.wantConstant';
  let targetBundleName = 'com.example.test_case1'
  let uri = "fileshare:///com.samples.filesharetest.FileShare/person/10"
  uriPermissionManager.grantUriPermission(uri, WantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName)
  .then((data) => {
      console.log('Verification succeeded.' + data)
  }).catch((error) => {
      console.log('Verification failed.');
  })
  ```
## uriPermissionManager.revokeUriPermission

revokeUriPermission(uri: string, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void;

Revokes the permission on the file of the specified URI from an application. This API uses an asynchronous callback to return the result.

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
  | -------- | -------- |
  | 201 | Permissions denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | The parameter check failed. |
  | 16500059 | Invalid URI type. |

**Example**
    
  ```js
  import WantConstant from '@ohos.ability.wantConstant';
  let targetBundleName = 'com.example.test_case1'
  let URI = "fileshare:///com.samples.filesharetest.FileShare/person/10"
  uriPermissionManager.revokeUriPermission(URI, targetBundleName, (result) => {
      console.log("result.code = " + result.code)
  }) 
  ```


## uriPermissionManager.revokeUriPermission

revokeUriPermission(uri: string, targetBundleName: string): Promise&lt;number&gt;

Revokes the permission on the file of the specified URI from an application. This API uses a promise to return the result.

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
  | -------- | -------- |
  | 201 | Permissions denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | The parameter check failed. |
  | 16500059 | Invalid URI type. |

**Example**
    
  ```js
  import WantConstant from '@ohos.ability.wantConstant';
  let targetBundleName = 'com.example.test_case1'
  let uri = "fileshare:///com.samples.filesharetest.FileShare/person/10"
  uriPermissionManager.revokeUriPermission(uri, targetBundleName)
  .then((data) => {
      console.log('Verification succeeded.' + data)
  }).catch((error) => {
      console.log('Verification failed.');
  })
  ```
