# uriPermissionManager

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Implements URI permission management.


## Modules to Import

  
```
import UriPermissionManager from '@ohos.application.uriPermissionManager';
```


## uriPermissionManager.verifyUriPermission

verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number, callback: AsyncCallback&lt;number&gt;): void

Checks whether an application has the permission specified by **flag** for an URI. This API uses a callback to return the result.

**System capability**:

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | uri | string | Yes| URI of a file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.| 
  | flag | wantConstant.Flags | Yes| Read or write permission on the file specified by the URI.| 
  | accessTokenId | number | Yes| Unique ID of an application, which is obtained through the **BundleManager** API.| 
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the check result. The value **0** means that the application has the specified permission, and **-1** means the opposite.| 

**Example**
    
  ```js
  import WantConstant from '@ohos.ability.wantConstant';
  let accessTokenId =1
  let uri = "fileshare:///com.samples.filesharetest.FileShare/person/10"
  UriPermissionManager.verifyUriPermission(uri, WantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, accessTokenId, (result) => {
      console.log("result.code = " + result.code)
  }) // accessTokenId is obtained through the **BundleManager** API.
  ```


## uriPermissionManager.verifyUriPermission

verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number): Promise&lt;number&gt;

Checks whether an application has the permission specified by **flag** for an URI. This API uses a callback to return the result.

**System capability**:

SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | uri | string | Yes| URI of a file, for example, **fileshare:///com.samples.filesharetest.FileShare/person/10**.| 
  | flag | wantConstant.Flags | Yes| Read or write permission on the file specified by the URI.| 
  | accessTokenId | number | Yes| Unique ID of an application, which is obtained through the **BundleManager** API.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the check result. The value **0** means that the application has the specified permission, and **-1** means the opposite.| 

**Example**
    
  ```js
  import WantConstant from '@ohos.ability.wantConstant';
  let accessTokenId =1
  let uri = "fileshare:///com.samples.filesharetest.FileShare/person/10"
  UriPermissionManager.verifyUriPermission(uri, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, accessTokenId)
  .then((data) => {
      console.log('Verification succeeded.' + data)
  }).catch((error) => {
      console.log('Verification failed.');
  })
  ```
