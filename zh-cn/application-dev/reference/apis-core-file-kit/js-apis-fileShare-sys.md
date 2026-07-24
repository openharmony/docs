# @ohos.fileshare (文件分享)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @leiyuqian; @zsyztt; @yue-ye2-->
<!--Adviser: @jinqiuheng-->

该模块提供文件分享能力，支持系统应用将公共目录文件统一资源标识符（Uniform Resource Identifier，URI）授权给其他应用，并提供授权状态校验、临时授权和持久化授权管理能力。授权后应用可通过[@ohos.file.fs](js-apis-file-fs.md)的相关接口进行open、read、write等操作，实现系统应用间文件共享和公共目录文件访问控制。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.fileshare (文件分享)](js-apis-fileShare.md)。

## 导入模块

```ts
import { fileShare } from '@kit.CoreFileKit';
```

## SharedDirectoryInfo

应用捐献给系统的目录信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。  

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

| 名称  | 类型  | 只读 | 可选 | 说明                                                   |
|------|-------|------|-----|------------------------------------------------------|
| bundleName | string | 是   | 否 | 应用程序的包名。                                       |
| path | string | 是   | 否 | 应用程序捐献的目录。 |
| permissionMode | number | 是   | 否 | 应用程序捐献目录的权限，可填入[OperationMode](./js-apis-fileShare.md#operationmode11)中对应的枚举值，如需授予多个权限，可以组合使用，例如使用READ_MODE \| WRITE_MODE授予读写权限。  |

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback&lt;void&gt;): void

对公共目录文件URI进行临时授权操作，使用callback异步回调。

**需要权限：** ohos.permission.WRITE_MEDIA  

**系统接口：** 此接口为系统接口。  

**系统能力：** SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型| 必填 | 说明|
| ------ |---------| ---- |-----------|
| uri   | string| 是   | 公共目录文件URI。 |
| bundleName   | string| 是   | 分享目标的包名。   |
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) | 是   | 授权的权限。     |
| callback | AsyncCallback&lt;void&gt;| 是    | 异步授权之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID| 错误信息|
| ------ | ------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14300001 | IPC error. |

**示例：**

  ```ts
  import { wantConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileShare } from '@kit.CoreFileKit';

  let uri: string =
    'file://docs/storage/Users/currentUser/Document/1.txt'; // 推荐使用系统接口生成URI。fileUri.getUriFromPath('沙箱路径');
  let bundleName: string = 'com.demo.test';
  try {
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION, (err: BusinessError) => {
      if (err) {
        console.error(`grantUriPermission failed with error: ${JSON.stringify(err)}`);
        return;
      }
      console.info('grantUriPermission success!');
    });
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error(`grantUriPermission failed with error: ${JSON.stringify(error)}`);
  }
  ```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise&lt;void&gt;

对公共目录文件URI进行临时授权操作，使用Promise异步回调。

**需要权限：** ohos.permission.WRITE_MEDIA  

**系统接口：** 此接口为系统接口。  

**系统能力：** SystemCapability.FileManagement.AppFileService  

**参数：**

| 参数名 | 类型| 必填 | 说明        |
| ------ |-------| ---- |-----------|
| uri   | string| 是   | 公共目录文件URI。 |
| bundleName   | string| 是   | 分享目标的包名。   |
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) | 是   | 授权的权限。     |

**返回值：**

  | 类型                           | 说明         |
  | ---------- | ---------- |
  | Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID| 错误信息|
| ------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14300001 | IPC error. |

**示例：**

  ```ts
  import { wantConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileShare } from '@kit.CoreFileKit';

  let uri: string =
    'file://docs/storage/Users/currentUser/Document/1.txt'; // 推荐使用系统接口生成URI。fileUri.getUriFromPath('沙箱路径');
  let bundleName: string = 'com.demo.test';
  try {
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION).then(() => {
      console.info('grantUriPermission success!');
    }).catch((error: BusinessError) => {
      console.error(`grantUriPermission failed with error: ${JSON.stringify(error)}`);
    });
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error(`grantUriPermission failed with error: ${JSON.stringify(error)}`);
  }
  ```

## fileShare.checkPathPermission<sup>15+</sup>

checkPathPermission(tokenID: number, policies: Array&lt;PathPolicyInfo&gt;, policyType: PolicyType): Promise&lt;Array&lt;boolean&gt;&gt;

异步方法校验所选择的多个文件或目录是否有临时或持久化授权，使用Promise异步回调。

**需要权限：** ohos.permission.CHECK_SANDBOX_POLICY

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型| 必填 | 说明|
| -------- |-------| -------- |----------|
| tokenID| number | 是 | 目标应用的访问令牌标识。可通过应用的[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| policies| Array&lt;[PathPolicyInfo](js-apis-fileShare.md#pathpolicyinfo15)> | 是 | 需要查询授权状态的路径策略信息数组，数组元素与返回结果一一对应，policies数组大小上限为500。|
| policyType| [PolicyType](js-apis-fileShare.md#policytype15) | 是 | 要查询的授权类型。使用TEMPORARY_TYPE查询临时授权，使用PERSISTENT_TYPE查询持久化授权。 |

**返回值：**

|类型|说明|
| ------ | ------ |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise对象，返回授权状态校验结果数组，数组元素与policies数组元素一一对应。返回true表示授权类型匹配policyType的查询类型，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900042 | Out of memory.|

**示例：**

  ```ts
  import { fileShare } from '@kit.CoreFileKit';
  
  async function checkPersistentPermissionExample() {
    try {
      let pathPolicyInfo1: fileShare.PathPolicyInfo = {
        path: '/storage/Users/currentUser/Documents/1.txt',
        operationMode: fileShare.OperationMode.READ_MODE,
      }
      let pathPolicyInfo2: fileShare.PathPolicyInfo = {
        path: '/storage/Users/currentUser/Desktop/2.txt',
        operationMode: fileShare.OperationMode.READ_MODE,
      }

      let policies: Array<fileShare.PathPolicyInfo> = [pathPolicyInfo1, pathPolicyInfo2];
      let policyType: fileShare.PolicyType = fileShare.PolicyType.PERSISTENT_TYPE;
      let tokenID = 537688848; // 系统应用可以通过bundleManager.getApplicationInfo获取，普通应用可以通过bundleManager.getBundleInfoForSelf获取。

      fileShare.checkPathPermission(tokenID, policies, policyType).then((result: Array<boolean>) => {
        for (let hasPermission of result) {
          console.info('check permission result is', hasPermission);
        }
      });
      console.info('checkPathPermission finish');
    } catch (error) {
      console.info(`checkPathPermission error, Code: ${error.code}, message: ${error.message}`);
    }
  }
  ```

## fileShare.grantUriPermission<sup>20+</sup>

grantUriPermission(policies: Array&lt;PolicyInfo&gt;, targetBundleName: string, appCloneIndex: number): Promise&lt;void&gt;

给应用授予目标文件临时权限，使用Promise异步回调。临时权限可在不需要时通过revokePermission撤销。

**需要权限：** ohos.permission.FILE_ACCESS_MANAGER

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型| 必填 | 说明|
| -------- |-------| -------- |----------|
| policies| Array&lt;[PolicyInfo](js-apis-fileShare.md#policyinfo11)> | 是 | 需要授权URI的策略信息数组，数组元素为PolicyInfo对象，policies数组大小上限为500。|
| targetBundleName| string | 是 | 被授权应用的应用包名。 |
| appCloneIndex| number | 是 | 被授权应用的分身索引，取值为0时表示主应用，非0值表示对应分身应用。 |

**返回值：**

|类型|说明|
| ------ | ------ |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed.|
| 202      | The caller is not a system application.|
| 801      | Capability not supported. |
| 13900001      | Operation not permitted. |
| 13900011      | Out of memory. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileShare } from '@kit.CoreFileKit';
  
  async function grantUriPermissionExample() {
    try {
      let uri = 'file://docs/storage/Users/currentUser/Documents/1.txt';
      let policyInfo: fileShare.PolicyInfo = {
        uri: uri,
        operationMode: fileShare.OperationMode.CREATE_MODE | fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];

      fileShare.grantUriPermission(policies, 'com.example.myapplicationtest', 0).then(() => {
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error(`grantUriPermission failed. Code: ${err.code}, message: ${err.message}`);
      });
    } catch (error) {
      console.info(`grantUriPermission error, Code: ${error.code}, message: ${error.message}`);
    }
  }
  ```

## fileShare.getSharedDirectoryInfo

getSharedDirectoryInfo(): Promise&lt;Array&lt;SharedDirectoryInfo&gt;&gt;

获取所有应用捐献的沙箱目录。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_SHARED_FILE

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**返回值：**

|类型|说明|
| ------ | ------ |
| Promise&lt;Array&lt;[SharedDirectoryInfo](#shareddirectoryinfo)&gt;&gt; | Promise对象，返回所有应用捐献的沙箱目录数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 801      | Capability not supported. |
| 13900001      | Operation not permitted. |
| 13900011      | Out of memory. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileShare } from '@kit.CoreFileKit';

async function getSharedDirectoryInfo() {
  try {
    fileShare.getSharedDirectoryInfo().then((infos: Array<fileShare.SharedDirectoryInfo>) => {
      infos.forEach((info: fileShare.SharedDirectoryInfo) => {
        console.info(`bundleName=${info.bundleName} path=${info.path} mode=${info.permissionMode}`);
      });
    }).catch((err: BusinessError) => {
      console.error(`getSharedDirectoryInfo err: ${JSON.stringify(err)}`);
    });
  } catch (error) {
    console.error(`getSharedDirectoryInfo error, Code: ${error.code}, message: ${error.message}`);
  }
}
```


## fileShare.grantSharedDirectoryPermission

grantSharedDirectoryPermission(): Promise&lt;void&gt;

授予应用捐献目录的临时访问权限。使用Promise异步回调。临时访问权限可通过revokeSharedDirectoryPermission撤销。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_SHARED_FILE

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**返回值：**

|类型|说明|
| ------ | ------ |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 801      | Capability not supported. |
| 13900001      | Operation not permitted. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileShare } from '@kit.CoreFileKit';

async function grantSharedDirectoryPermission() {
  try {
    fileShare.grantSharedDirectoryPermission().then(() => {
      console.info('grantSharedDirectoryPermission success');
    }).catch((err: BusinessError) => {
      console.error(`grantSharedDirectoryPermission err: ${JSON.stringify(err)}`);
    });
  } catch (error) {
    console.error(`grantSharedDirectoryPermission error, Code: ${error.code}, message: ${error.message}`);
  }
}
```

## fileShare.revokeSharedDirectoryPermission

revokeSharedDirectoryPermission(): Promise&lt;void&gt;

撤销应用的捐献目录临时访问权限。使用Promise异步回调。该接口用于撤销grantSharedDirectoryPermission授予的临时访问权限。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_SHARED_FILE

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**返回值：**

|类型|说明|
| ------ | ------ |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 801      | Capability not supported. |
| 13900001      | Operation not permitted. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileShare } from '@kit.CoreFileKit';

async function revokeSharedDirectoryPermission() {
  try {
    fileShare.revokeSharedDirectoryPermission().then(() => {
      console.info('revokeSharedDirectoryPermission success');
    }).catch((err: BusinessError) => {
      console.error(`revokeSharedDirectoryPermission err: ${JSON.stringify(err)}`);
    });
  } catch (error) {
    console.error(`revokeSharedDirectoryPermission error, Code: ${error.code}, message: ${error.message}`);
  }
}
```

## fileShare.revokePermission

revokePermission(tokenID: number): Promise&lt;void&gt;

撤销指定应用的全部持久化文件授权，使用Promise异步回调。如需仅撤销指定URI的持久化授权，请使用revokePermission(tokenID, policies)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REVOKE_FILE_ACCESS_PERSIST

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型| 必填 | 说明|
| -------- |-------| -------- |----------|
| tokenID| number | 是 | 目标应用的访问令牌标识，可通过应用[BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获取。|

**返回值：**

|类型|说明|
| ------ | ------ |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 801      | Capability not supported. |
| 13900001 | Operation not permitted. |
| 13900020 | Invalid tokenID. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileShare } from '@kit.CoreFileKit';

async function revokeAllPermissionExample() {
  try {
    let tokenID = 537688848; // 系统应用可以通过bundleManager.getApplicationInfo获取，普通应用可以通过bundleManager.getBundleInfoForSelf获取。
    fileShare.revokePermission(tokenID).then(() => {
      console.info('revoke persist permission successfully.');
    }).catch((err: BusinessError) => {
      console.error(`revoke persist permission failed, Code: ${err.code}, message: ${err.message}`);
    });
  } catch (error) {
    console.error(`revoke persist permission failed error, Code: ${error.code}, message: ${error.message}`);
  }
}
```

## fileShare.revokePermission

revokePermission(tokenID: number, policies: Array&lt;PolicyInfo&gt;): Promise&lt;void&gt;

撤销指定应用对URI的持久化授权，使用Promise异步回调。该重载仅撤销policies指定的URI授权；如需撤销指定应用的全部持久化授权，请使用revokePermission(tokenID)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.REVOKE_FILE_ACCESS_PERSIST

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型| 必填 | 说明|
| -------- |-------| -------- |----------|
| tokenID| number | 是 | 目标应用的访问令牌标识，可通过应用[BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获取。|
| policies| Array&lt;[PolicyInfo](js-apis-fileShare.md#policyinfo11)&gt; | 是 | 需要撤销持久化授权的策略信息数组，policies数组大小上限为500。 |

**返回值：**

|类型|说明|
| ------ | ------ |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

如果存在URI取消授权失败，则抛出13900001错误码，且失败URI信息将在抛出异常data属性中以Array&lt;[PolicyErrorResult](js-apis-fileShare.md#policyerrorresult11)&gt;形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Invalid policy size.|
| 801      | Capability not supported. |
| 13900001 | Operation not permitted. |
| 13900011 | Out of memory. |
| 13900020 | Invalid tokenID. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileShare } from '@kit.CoreFileKit';

async function revokeSpecificPermissionExample() {
  try {
    let tokenID = 537688848; // 系统应用可以通过bundleManager.getApplicationInfo获取，普通应用可以通过bundleManager.getBundleInfoForSelf获取。
    let policyInfo: fileShare.PolicyInfo = {
      uri: 'file://docs/storage/Users/currentUser/Documents/1.txt',
      operationMode: fileShare.OperationMode.READ_MODE | fileShare.OperationMode.WRITE_MODE,
    };
    let policies: Array<fileShare.PolicyInfo> = [policyInfo];
    fileShare.revokePermission(tokenID, policies).then(() => {
      console.info('revoke persist permission successfully.');
    }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
      console.error(`revoke persist permission failed. Code: ${err.code}, message: ${err.message}`);
      if (err.code === 13900001 && err.data) {
        for (let i = 0; i < err.data.length; i++) {
          console.error(`error code: ${JSON.stringify(err.data[i].code)}`);
          console.error(`error URI: ${JSON.stringify(err.data[i].uri)}`);
          console.error(`error reason: ${JSON.stringify(err.data[i].message)}`);
        }
      }
    });
  } catch (error) {
    console.error(`revokePermission error, Code: ${error.code}, message: ${error.message}`);
  }
}
```

## fileShare.getPersistentPolicy

getPersistentPolicy(tokenID: number): Promise&lt;Array&lt;PolicyInfo&gt;&gt;

获取应用程序的持久化授权策略，使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.GET_FILE_ACCESS_PERSIST

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型| 必填 | 说明|
| -------- |-------| -------- |----------|
| tokenID| number | 是 | 目标应用的访问令牌标识，可通过应用[BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获取。|

**返回值：**

|类型|说明|
| ------ | ------ |
| Promise&lt;Array&lt;[PolicyInfo](js-apis-fileShare.md#policyinfo11)&gt;&gt; | Promise对象，返回应用的持久化策略信息数组。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 801      | Capability not supported. |
| 13900001 | Operation not permitted. |
| 13900011 | Out of memory. |
| 13900020 | Invalid tokenID. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileShare } from '@kit.CoreFileKit';

async function getPersistentPolicyExample() {
  try {
    let tokenID = 537688848; // 系统应用可以通过bundleManager.getApplicationInfo获取，普通应用可以通过bundleManager.getBundleInfoForSelf获取。
    fileShare.getPersistentPolicy(tokenID).then((result: Array<fileShare.PolicyInfo>) => {
      for (let policy of result) {
        console.info(`get persist policy URI: ${policy.uri}, operationMode: ${policy.operationMode}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`get persist policy failed with error, Code: ${err.code}, message: ${err.message}`);
    });
  } catch (error) {
    console.error(`get persist policy failed with error, Code: ${error.code}, message: ${error.message}`);
  }
}
```
