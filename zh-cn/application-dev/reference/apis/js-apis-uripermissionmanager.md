# uriPermissionManager

uriPermissionManager模块提供了Uri权限管理的能力。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

  
```
import UriPermissionManager from '@ohos.application.uriPermissionManager';
```


## uriPermissionManager.verifyUriPermission

verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number, callback: AsyncCallback&lt;number&gt;): void

检验某个应用是否对指定的uri有flag指定的权限。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的uri，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | flag | wantConstant.Flags | 是 | uri的读权限或写权限。 | 
  | accessTokenId | number | 是 | 每个应用的唯一标识ID，开发者通过包管理接口自行获取。 | 
  | callback | AsyncCallback&lt;number&gt; | 是 | callback形式返回检验结果，返回0表示有权限，返回-1表示无权限。 | 

**示例：**
    
  ```js
  import WantConstant from '@ohos.ability.wantConstant';
  let accessTokenId =1
  let uri = "fileshare:///com.samples.filesharetest.FileShare/person/10"
  UriPermissionManager.verifyUriPermission(uri, WantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, accessTokenId, (result) => {
      console.log("result.code = " + result.code)
  }) // accessTokenId开发者通过包管理接口自行获取
  ```


## uriPermissionManager.verifyUriPermission

verifyUriPermission(uri: string, flag: wantConstant.Flags, accessTokenId: number): Promise&lt;number&gt;

检验某个应用是否对指定的uri有flag指定的权限。

**系统能力:**

SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的uri，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | flag | wantConstant.Flags | 是 | uri的读权限或写权限。 | 
  | accessTokenId | number | 是 | 每个应用的唯一标识ID，开发者通过包管理接口自行获取。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | 返回0表示有权限，返回-1表示无权限。 | 

**示例：**
    
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

