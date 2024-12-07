# @ohos.application.uriPermissionManager(URI权限管理)(系统接口)

URI权限管理模块。用于应用A授权/撤销授权URI给应用B

> **说明：**
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口均为系统接口，三方应用不支持调用。


## 导入模块

  
```ts
import { uriPermissionManager } from '@kit.AbilityKit';
```


## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string, callback: AsyncCallback&lt;number&gt;): void

授权URI给指定应用，目标应用退出后权限将被回收。使用callback异步回调。

允许应用授权属于自身的URI, 若应用拥有ohos.permission.PROXY_AUTHORIZATION_URI权限, 则还允许授权不属于自身但具有访问权限的URI。
**系统API**：该接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限:** ohos.permission.PROXY_AUTHORIZATION_URI

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#flags) | 是 | URI的读权限或写权限。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名 | 
  | callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。返回0表示有权限，返回-1表示无权限。 | 

**错误码：**

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 16000050 | Internal error. |
| 16000058 | Invalid URI flag. |
| 16000059 | Invalid URI type. |
| 16000060 | A sandbox application cannot grant URI permission. |


**示例：**
    
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

授权URI给指定应用，目标应用退出后权限将被回收。使用Promise异步回调。

允许应用授权属于自身的URI, 若应用拥有ohos.permission.PROXY_AUTHORIZATION_URI权限, 则还允许授权不属于自身但具有访问权限的URI。
**系统API**：该接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限:** ohos.permission.PROXY_AUTHORIZATION_URI

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#flags) | 是 | URI的读权限或写权限。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名 |  

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise对象。返回0表示有权限，返回-1表示无权限。 | 

**错误码：**

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

  | 错误码ID | 错误信息 |
  | ------- | -------------------------------- |
  | 201 | Permission denied. |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
  | 16000050 | Internal error. |
  | 16000058 | Invalid URI flag. |
  | 16000059 | Invalid URI type. |
  | 16000060 | A sandbox application cannot grant URI permission. |

**示例：**
    
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

撤销授权指定应用的URI。使用callback异步回调。

允许应用撤销自身获得的其他应用URI权限，或授权给其他应用的URI权限。
**系统API**：该接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | targetBundleName | string | 是 | 被撤销授权uri的应用包名 | 
  | callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。返回0表示有权限，返回-1表示无权限。 | 

**错误码：**

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

  | 错误码ID | 错误信息 |
  | ------- | -------------------------------- |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
  | 16000050 | Internal error. |
  | 16000059 | Invalid URI type. |

**示例：**
    
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

撤销授权指定应用的URI。使用Promise异步回调。


允许应用撤销自身获得的其他应用URI权限，或授权给其他应用的URI权限。
**系统API**：该接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，例如fileshare:///com.samples.filesharetest.FileShare/person/10。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名 |  

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise对象。返回0表示有权限，返回-1表示无权限。 | 

**错误码：**

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

  | 错误码ID | 错误信息 |
  | ------- | -------------------------------- |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
  | 16000050 | Internal error. |
  | 16000059 | Invalid URI type. |


**示例：**
    
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
