# @ohos.application.uriPermissionManager(URI权限管理)(系统接口)

URI权限管理模块。用于应用A授权/撤销授权URI给应用B。

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

授权URI给指定应用，授权成功后目标应用将获得该URI的文件访问权限，目标应用退出后权限将被回收。目标应用使用该URI的方法可以参考[应用文件分享](../../file-management/share-app-file.md)。使用callback异步回调。

> **说明：**
>
> 当应用拥有ohos.permission.PROXY_AUTHORIZATION_URI权限时, 可以授权不属于自身但具有访问权限的URI。如果不具备该权限，则仅支持授权属于自身的URI。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限**：ohos.permission.PROXY_AUTHORIZATION_URI

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，scheme固定为"file"，参考[FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10)。 | 
  | flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#flags) | 是 | URI的读权限或写权限。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名。 | 
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
  uriPermissionManager.grantUriPermission(uri, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION, targetBundleName, (error) => {
    if (error && error.code !== 0) {
      console.error("grantUriPermission failed, error.code = " + error.code);
      return;
    }
    console.info("grantUriPermission success");
  });
  ```


## uriPermissionManager.grantUriPermission

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string): Promise&lt;number&gt;

授权URI给指定应用，授权成功后目标应用将获得该URI的文件访问权限，目标应用退出后权限将被回收。目标应用使用该URI的方法可以参考[应用文件分享](../../file-management/share-app-file.md)。使用Promise异步回调。

> **说明：**
>
> 当应用拥有ohos.permission.PROXY_AUTHORIZATION_URI权限时, 可以授权不属于自身但具有访问权限的URI。如果不具备该权限，则仅支持授权属于自身的URI。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限**：ohos.permission.PROXY_AUTHORIZATION_URI

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，scheme固定为"file"，参考[FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10)。 | 
  | flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#flags) | 是 | URI的读权限或写权限。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名。 |  

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

## uriPermissionManager.grantUriPermission<sup>14+</sup>

grantUriPermission(uri: string, flag: wantConstant.Flags, targetBundleName: string, appCloneIndex: number): Promise&lt;void&gt;

授权URI给指定应用，授权成功后目标应用将获得该URI的文件访问权限，目标应用退出后权限将被回收。目标应用使用该URI的方法可以参考[应用文件分享](../../file-management/share-app-file.md)。使用Promise异步回调。

> **说明：**
> 
>- 当应用拥有ohos.permission.PROXY_AUTHORIZATION_URI权限时, 可以授权不属于自身但具有访问权限的URI。如果不具备该权限，则仅支持授权属于自身的URI。
>- 该接口支持给分身应用授权，需要指定目标应用的应用包名和分身索引。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**需要权限**：ohos.permission.PROXY_AUTHORIZATION_URI

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，scheme固定为"file"，参考[FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10)。 | 
  | flag | [wantConstant.Flags](js-apis-app-ability-wantConstant.md#flags) | 是 | URI的读权限或写权限。 | 
  | targetBundleName | string | 是 | 被授权应用的应用包名。 |
  | appCloneIndex | number | 是 | 被授权应用的分身索引，有效范围为[0, 1000], 取值为0时表示主应用。|

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。| 

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
  | 16000081 | Get target application info failed. |

**示例：**

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

撤销授权指定应用的URI。使用callback异步回调。

> **说明：**
> 
> 允许应用撤销自身获得的其他应用URI权限，或授权给其他应用的URI权限。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，scheme固定为"file"，参考[FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10)。 | 
  | targetBundleName | string | 是 | 被撤销授权uri的应用包名。 | 
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

  uriPermissionManager.revokeUriPermission(uri, targetBundleName, (error) => {
    if (error && error.code !== 0) {
      console.error("revokeUriPermission failed, error.code = " + error.code);
      return;
    }
    console.info("revokeUriPermission success");
  });
  ```


## uriPermissionManager.revokeUriPermission

revokeUriPermission(uri: string, targetBundleName: string): Promise&lt;number&gt;

撤销授权指定应用的URI。使用Promise异步回调。

> **说明：**
> 
> 允许应用撤销自身获得的其他应用URI权限，或授权给其他应用的URI权限。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，scheme固定为"file"，参考[FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10)。 | 
  | targetBundleName | string | 是 | 被授权URI的应用包名。 |  

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
## uriPermissionManager.revokeUriPermission<sup>14+</sup>

revokeUriPermission(uri: string, targetBundleName: string, appCloneIndex: number): Promise&lt;void&gt;

撤销授权指定应用的URI。使用Promise异步回调。

> **说明：**
> 
>- 允许应用撤销自身获得的其他应用URI权限，或授权给其他应用的URI权限。
>- 该接口支持撤销授权给分身应用的URI权限，需要指定目标应用的应用包名和分身索引。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | uri | string | 是 | 指向文件的URI，scheme固定为"file"，参考[FileUri](../apis-core-file-kit/js-apis-file-fileuri.md#constructor10)。 | 
  | targetBundleName | string | 是 | 被授权应用的应用包名。 |
  | appCloneIndex | number | 是 | 被授权应用的分身索引，有效范围为[0, 1000], 取值为0时表示主应用。|

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。| 

**错误码：**

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

  | 错误码ID | 错误信息 |
  | ------- | -------------------------------- |
  | 202 | Not System App. Interface caller is not a system app. |
  | 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
  | 16000050 | Internal error. |
  | 16000059 | Invalid URI type. |
  | 16000081 | Get target application info failed. |

**示例：**

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