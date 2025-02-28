# @ohos.fileshare (文件分享)

该模块提供文件分享能力，提供系统应用将公共目录文件统一资源标志符（Uniform Resource Identifier，URI）以读写权限授权给其他应用的接口，授权后应用可通过[@ohos.file.fs](js-apis-file-fs.md)的相关接口进行相关open、read、write等操作，实现文件分享。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import fileShare from '@ohos.fileshare';
```

## OperationMode<sup>11+</sup>

枚举，授予或使能权限的URI访问模式。

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

| 名称  | 值   | 说明  |
| ----- |-----|-----|
| READ_MODE  | 0b1 | 读权限。 |
| WRITE_MODE  | 0b10 | 写权限。 |

## PolicyErrorCode<sup>11+</sup>

枚举，授予或使能权限策略失败的URI对应的错误码。

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

| 名称  | 值   | 说明        |
| ----- |-----|-----------|
| PERSISTENCE_FORBIDDEN  | 1   | URI禁止被持久化。 |
| INVALID_MODE  | 2   | 无效的模式。     |
| INVALID_PATH  | 3   | 无效的路径。     |
| PERMISSION_NOT_PERSISTED<sup>12+</sup>  | 4   | 权限没有被持久化。 |

## PolicyErrorResult<sup>11+</sup>

授予或使能权限失败的URI策略结果。支持persistPermission、revokePermission、activatePermission、deactivatePermission接口抛出错误时使用。

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

| 名称| 类型| 必填 | 说明|
|--------|--------|--------|---------|
| uri     | string| 是  | 授予或使能权限失败的URI。|
| code    | [PolicyErrorCode](#policyerrorcode11) | 是  | 授权策略失败的URI对应的错误码。 |
| message | string| 是   | 授权策略失败的URI对应的原因。  |

## PolicyInfo<sup>11+</sup>

需要授予或使能权限URI的策略信息。

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

| 名称  | 类型  | 必填  | 说明                                                   |
|------|-------|------|------------------------------------------------------|
| uri| string | 是   | 需要授予或使能权限的URI。                                       |
| operationMode | number | 是   | 授予或使能权限的URI访问模式，参考[OperationMode](#operationmode11)。 |

## PathPolicyInfo<sup>15+</sup>

需要查询的文件或目录的信息。

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

| 名称 | 类型  | 必填  | 说明  |
|------|-------|-----|--------|
| path          | string        | 是   | 需要查询的path。|
| operationMode | OperationMode | 是   | 需要查询的path的访问模式，参考[OperationMode](#operationmode11)。 |

## PolicyType<sup>15+</sup>

枚举，所查询策略信息对应的授权模式。

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

| 名称  | 值   | 说明        |
| ----- |-----|-----------|
| TEMPORARY_TYPE  | 0   | 临时授权。 |
| PERSISTENT_TYPE  | 1   | 持久化授权。     |

## fileShare.persistPermission<sup>11+</sup>

persistPermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

异步方法对所选择的多个文件或目录URI持久化授权，以promise形式返回结果。该接口仅对具有该系统能力的设备开放(此接口不支持媒体类URI及远端URI的持久化)。

**需要权限**：ohos.permission.FILE_ACCESS_PERSIST

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型  | 必填 | 说明  |
| -------- |---------| -------- |--------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | 是 | 需要授权URI的策略信息，policies数组大小上限为500。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。\n
如果存在URI授权失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](#policyerrorresult11)>形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Unknown error.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import picker from '@ohos.file.picker';
  
  async function persistPermissionExample() {
    try {
      let DocumentSelectOptions = new picker.DocumentSelectOptions();
      let documentPicker = new picker.DocumentViewPicker();
      let uris = await documentPicker.select(DocumentSelectOptions);
      let policyInfo: fileShare.PolicyInfo = {
        uri: uris[0], 
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.persistPermission(policies).then(() => {
        console.info("persistPermission successfully");
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error("persistPermission failed with error message: " + err.message + ", error code: " + err.code);
        if (err.code == 13900001 && err.data) {
          for (let i = 0; i < err.data.length; i++) {
            console.error("error code : " + JSON.stringify(err.data[i].code));
            console.error("error uri : " + JSON.stringify(err.data[i].uri));
            console.error("error reason : " + JSON.stringify(err.data[i].message));
          }
        }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('persistPermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## fileShare.revokePermission<sup>11+</sup>

revokePermission(policies: Array&lt;PolicyInfo&gt;): Promise&lt;void&gt;

异步方法对所选择的多个文件或目录uri取消持久化授权，以promise形式返回结果。该接口仅对具有该系统能力的设备开放(此接口不支持媒体类URI及远端URI的持久化)。

**需要权限**：ohos.permission.FILE_ACCESS_PERSIST

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型  | 必填 | 说明  |
| -------- |----------| -------- |----------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | 是 | 需要授权URI的策略信息，policies数组大小上限为500。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。\n
如果存在URI取消授权失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](#policyerrorresult11)>形式提供错误信息。

| 错误码ID | 错误信息 |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Unknown error.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import picker from '@ohos.file.picker';
  
  async function revokePermissionExample() {
    try {
      let DocumentSelectOptions = new picker.DocumentSelectOptions();
      let documentPicker = new picker.DocumentViewPicker();
      let uris = await documentPicker.select(DocumentSelectOptions);
      let policyInfo: fileShare.PolicyInfo = {
        uri: uris[0], 
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.revokePermission(policies).then(() => {
        console.info("revokePermission successfully");
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error("revokePermission failed with error message: " + err.message + ", error code: " + err.code);
          if (err.code == 13900001 && err.data) {
            for (let i = 0; i < err.data.length; i++) {
              console.error("error code : " + JSON.stringify(err.data[i].code));
              console.error("error uri : " + JSON.stringify(err.data[i].uri));
              console.error("error reason : " + JSON.stringify(err.data[i].message));
            }
          }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('revokePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## fileShare.activatePermission<sup>11+</sup>

activatePermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

异步方法使能多个已经永久授权过的文件或目录，以promise形式返回结果。该接口仅对具有该系统能力的设备开放(此接口不支持媒体类URI及远端URI的持久化)。

**需要权限**：ohos.permission.FILE_ACCESS_PERSIST

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- |---------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | 是 | 需要授权URI的策略信息，policies数组大小上限为500。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。\n
如果存在URI使能权限失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](#policyerrorresult11)>形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Unknown error.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import picker from '@ohos.file.picker';
  
  async function activatePermissionExample() {
    try {
      let uri = "file://docs/storage/Users/username/tmp.txt";
      let policyInfo: fileShare.PolicyInfo = {
        uri: uri,
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.activatePermission(policies).then(() => {
        console.info("activatePermission successfully");
      }).catch(async (err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error("activatePermission failed with error message: " + err.message + ", error code: " + err.code);
          if (err.code == 13900001 && err.data) {
            for (let i = 0; i < err.data.length; i++) {
              console.error("error code : " + JSON.stringify(err.data[i].code));
              console.error("error uri : " + JSON.stringify(err.data[i].uri));
              console.error("error reason : " + JSON.stringify(err.data[i].message));
              if(err.data[i].code == fileShare.PolicyErrorCode.PERMISSION_NOT_PERSISTED){
                await fileShare.persistPermission(policies);
              }
            }
          }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('activatePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## fileShare.deactivatePermission<sup>11+</sup>

deactivatePermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

异步方法取消使能授权过的多个文件或目录，以promise形式返回结果。该接口仅对具有该系统能力的设备开放(此接口不支持媒体类URI及远端URI的持久化)。

**需要权限**：ohos.permission.FILE_ACCESS_PERSIST

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| -------- | -------- | -------- |---------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | 是 | 需要授权URI的策略信息，policies数组大小上限为500。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。\n
如果存在URI取消使能权限失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](#policyerrorresult11)>形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Unknown error.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import picker from '@ohos.file.picker';
  
  async function deactivatePermissionExample() {
    try {
      let uri = "file://docs/storage/Users/username/tmp.txt";
      let policyInfo: fileShare.PolicyInfo = {
        uri: uri,
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.deactivatePermission(policies).then(() => {
        console.info("deactivatePermission successfully");
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error("deactivatePermission failed with error message: " + err.message + ", error code: " + err.code);
          if (err.code == 13900001 && err.data) {
            for (let i = 0; i < err.data.length; i++) {
              console.error("error code : " + JSON.stringify(err.data[i].code));
              console.error("error uri : " + JSON.stringify(err.data[i].uri));
              console.error("error reason : " + JSON.stringify(err.data[i].message));
            }
          }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('deactivatePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## fileShare.checkPersistentPermission<sup>12+</sup>

checkPersistentPermission(policies: Array&lt;PolicyInfo>): Promise&lt;Array&lt;boolean&gt;&gt;

异步方法校验所选择的多个文件或目录URI持久化授权，以promise形式返回结果。

**需要权限**：ohos.permission.FILE_ACCESS_PERSIST

**系统能力**：SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                      |
| -------- |---------------------------------------| -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)&gt; | 是 | 需要授权URI的策略信息，policies数组大小上限为500。|

**返回值：**

|   类型   |  说明   |
| ------- | ------- |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise对象。返回true表示有持久化授权；false表示不具有持久化授权。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900042 | Unknown error.|

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import picker from '@ohos.file.picker';
  
  async function checkPersistentPermissionExample() {
    try {
      let documentSelectOptions = new picker.DocumentSelectOptions();
      let documentPicker = new picker.DocumentViewPicker();
      let uris = await documentPicker.select(documentSelectOptions);
      let policyInfo: fileShare.PolicyInfo = {
        uri: uris[0], 
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.checkPersistentPermission(policies).then(async (data) => {
        let result: Array<boolean> = data;
        for (let i = 0; i < result.length; i++) {
          console.log("checkPersistentPermission result: " + JSON.stringify(result[i]));
          if(!result[i]){
            let info: fileShare.PolicyInfo = {
              uri: policies[i].uri, 
              operationMode: policies[i].operationMode,
            };
            let policy : Array<fileShare.PolicyInfo> = [info];
            await fileShare.persistPermission(policy);
          }
        }
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error("checkPersistentPermission failed with error message: " + err.message + ", error code: " + err.code);
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('checkPersistentPermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```
  