# @ohos.application.uriPermissionManager(URI权限管理)
> **说明：**
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


URI权限管理模块。用于应用A授权/撤销授权URI给应用B


## 导入模块

  
```js
import uriPermissionManager from '@ohos.application.uriPermissionManager';
```


## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void;

授权URI给指定应用，通过callback返回结果。

**系统API**：该接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限:** ohos.permission.PROXY_AUTHORIZATION_URI

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | flag | [wantConstant.Flags](js-apis-ability-wantConstant.md#wantconstantflags) | 是 | URI的读权限或写权限。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名 | 
  | callback | AsyncCallback&lt;number&gt; | 是 | callback形式返回检验结果，返回0表示有权限，返回-1表示无权限。 | 

**错误码：**

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permissions denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | The parameter check failed. |
  | 16500050 | Internal error. |
  | 16500058 | Invalid URI flag. |
  | 16500059 | Invalid URI type. |
  | 16500060 | Sandbox application can not grant URI permission. |

**示例：**
    
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

授权URI给指定应用，通过返回值返回结果。

**系统API**：该接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限:** ohos.permission.PROXY_AUTHORIZATION_URI

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | flag | [wantConstant.Flags](js-apis-ability-wantConstant.md#wantconstantflags) | 是 | URI的读权限或写权限。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名 |  

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | 返回0表示有权限，返回-1表示无权限。 | 

**错误码：**

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permissions denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | The parameter check failed. |
  | 16500050 | Internal error. |
  | 16500058 | Invalid URI flag. |
  | 16500059 | Invalid URI type. |
  | 16500060 | Sandbox application can not grant URI permission. |

**示例：**
    
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

撤销授权指定应用的URI，通过callback返回结果。

**系统API**：该接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限:** ohos.permission.PROXY_AUTHORIZATION_URI

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | targetBundleName | string | 是 | 被撤销授权uri的应用包名 | 
  | callback | AsyncCallback&lt;number&gt; | 是 | callback形式返回检验结果，返回0表示有权限，返回-1表示无权限。 | 

**错误码：**

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permissions denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | The parameter check failed. |
  | 16500059 | Invalid URI type. |

**示例：**
    
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

撤销授权指定应用的URI，通过返回值返回结果。

**系统API**：该接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限:** ohos.permission.PROXY_AUTHORIZATION_URI


**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名 |  

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | 返回0表示有权限，返回-1表示无权限。 | 

**错误码：**

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 201 | Permissions denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | The parameter check failed. |
  | 16500059 | Invalid URI type. |

**示例：**
    
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
