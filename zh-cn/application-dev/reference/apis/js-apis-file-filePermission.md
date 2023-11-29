# @ohos.file.filePermission (文件权限)

该模块提供通过授权方法给予应用对uri访问权限，后续可通过使用[@ohos.file.fs](js-apis-file-fs.md)进行相关open、read、write等操作，实现文件分享。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import filePermission from "@ohos.file.filePermission";
```

## OperateMode<sup>11+</sup>

枚举，授予或使能权限的URI访问模式。

**系统能力：** SystemCapability.FileManagement.AppFileService

| 名称  | 值   | 说明  |
| ----- |-----|-----|
| READ_MODE  | 0b1 | 读权限 |
| WRITE_MODE  | 0b10 | 写权限 |

## PolicyFlag<sup>11+</sup>

枚举，授予或使能权限的URI策略。

**系统能力：** SystemCapability.FileManagement.AppFileService

| 名称  | 值   | 说明      |
| ----- |-----|---------|
| ALLOW_PERSISTENCE  | 0b1 | 允许应用持久化 |
| FORBID_PERSISTENCE  | 0b10 | 禁止应用持久化 |

## PolicyErrorCode<sup>11+</sup>

枚举，授予或使能权限策略失败的URI对应的错误码。

**系统能力：** SystemCapability.FileManagement.AppFileService

| 名称  | 值   | 说明        |
| ----- |-----|-----------|
| FORBIDDEN_TO_BE_PERSISTED  | 1   | URI禁止被持久化 |
| INVALID_MODE  | 2   | 无效的模式     |
| INVALID_PATH  | 3   | 无效的路径     |

## PolicyErrorResult<sup>11+</sup>

**系统能力**：SystemCapability.FileManagement.AppFileService

授予或使能权限失败的URI策略结果，支持persistPermission、desistPersistedPermission、activateAccessingUri、deactivateAccessingUri接口抛出错误时使用。

| 名称      | 类型                                  | 说明                |
|---------|-------------------------------------|-------------------|
| uri     | string                              | 授予或使能权限失败的URI。         |
| code    | [PolicyErrorCode](#policyErrorCode) | 授权策略失败的URI对应的错误码。 |
| message | string                              | 授权策略失败的URI对应的原因。  |

## PolicyInfo<sup>11+</sup>

**系统能力**：SystemCapability.FileManagement.AppFileService

需要授予或使能权限URI的策略信息。

| 名称        | 类型       | 说明          |
| ----------- | --------------- |-------------|
| uri | string     | 需要授予或使能权限的URI。   |
| operateMode    | number     | 授予或使能权限的URI访问模式。 |

## grantPolicy<sup>11+</sup>

grantPolicy(tokenId: number, policies: Array&lt;PolicyInfo>, policyFlag: number): Promise&lt;void&gt;

异步方法对所选择的文件或目录URI临时授权，以promise形式返回结果。

**系统能力：** SystemCapability.FileManagement.AppFileService

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                      |
|---------|-------------------------------------| -------- |-------------------------|
| tokenId | number                              | 是 | 拉起filePicker应用的tokenId。 |
| policies| Array&lt;[PolicyInfo](#policyInfo)> | 是 | 需要授权URI的策略信息。           |
| policyFlag    | number                              | 是 | 授权的URI策略。                |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID    | 错误信息                                   |
|----------|----------------------------------------|
| 201      | Permission denied.|
| 202      | The caller is not a system application |
| 401      | The input parameter is invalid         |
| 801      | Capability not supported               |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |


**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
import bundleManager from '@ohos.bundle.bundleManager';

async function grantPolicyExample01() {
  try {
    let uri = "file://docs/storage/Users/username/1.txt";//uri为filepicker应用获取的选择路径
    let bundleName = 'com.example.myapplication';
    let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;
    let applicationInfo = await bundleManager.getApplicationInfo(bundleName, appFlags);
    let tokenId = applicationInfo.accessTokenId;//tokenId为拉起filepicker应用的tokenid
    let policyInfo: filePermission.PolicyInfo = {
      uri: uri, 
      operateMode: filePermission.OperateMode.READ_MODE,
    };
    let policies: Array<filepermission.PolicyInfo> = [policyInfo];
    filePermission.grantPolicy(tokenId, policies, filePermission.PolicyFlag.ALLOWED_PERSIST).then(() => {
      console.info("grantPolicy successfully");
    }).catch((err: BusinessError) => {
      console.info("grantPolicy failed with error message: " + err.message + ", error code: " + err.code);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('grantPolicy failed with err: ' + JSON.stringify(err));
  }
}
```

## persistPermission<sup>11+</sup>

persistPermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

异步方法对所选择的文件或目录URI持久化授权，以promise形式返回结果。

**需要权限**：ohos.permission.FILE_ACCESS_PERSIST

**系统能力：** SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型                 | 必填 | 说明                      |
| -------- |--------------------| -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyInfo)> | 是 | 需要授权URI的策略信息。           |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
如果只有部分URI持久化授权失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](#policyErrorResult)>形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied.|
| 401      | The input parameter is invalid |
| 801      | Capability not supported |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |


**示例：**

  ```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';

async function persistPermissionExample01() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    let uris = await documentPicker.select(DocumentSelectOptions);
    let policyInfo: filePermission.PolicyInfo = {
      uri: uri, 
      operateMode: filePermission.OperateMode.READ_MODE,
    };
    let policies: Array<filePermission.PolicyInfo> = [policyInfo];
    filePermission.persistPermission(policies).then(() => {
      console.info("persistPermission successfully");
    }).catch((err: BusinessError) => {
      console.info("persistPermission failed with error message: " + err.message + ", error code: " + err.code);
      if(err.code == 13900001){
        console.log("error code : " + JSON.stringify(err.data[0].code));
        console.log("error uri : " + JSON.stringify(err.data[0].uri));
        console.log("error reason : " + JSON.stringify(err.data[0].message));
      }
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('persistPermission failed with err: ' + JSON.stringify(err));
  }
}
  ```

## desistPersistPermission<sup>11+</sup>

desistPersistPermission(policies: Array&lt;PolicyInfo&gt;): Promise&lt;void&gt;

异步方法对所选择的文件或目录uri取消持久化授权，以promise形式返回结果。

**需要权限**：ohos.permission.FILE_ACCESS_PERSIST

**系统能力：** SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型                 | 必填 | 说明                      |
| -------- |--------------------| -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyInfo)> | 是 | 需要授权URI的策略信息。           |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
如果只有部分URI持久化授权失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](#policyErrorResult)>形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied.|
| 401      | The input parameter is invalid |
| 801      | Capability not supported |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |


**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';

async function desistPersistPermissionExample01() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    let uris = await documentPicker.select(DocumentSelectOptions);
    let policyInfo: filePermission.PolicyInfo = {
      uri: uri,
      operateMode: filePermission.OperateMode.READ_MODE,
    };
    let policies: Array<filePermission.PolicyInfo> = [policyInfo];
    filePermission.desistPersistPermission(policies).then(() => {
      console.info("desistPersistPermission successfully");
    }).catch((err: BusinessError) => {
      console.info("desistPersistPermission failed with error message: " + err.message + ", error code: " + err.code);
      if(err.code == 13900001){
        console.log("error code : " + JSON.stringify(err.data[0].code));
        console.log("error uri : " + JSON.stringify(err.data[0].uri));
        console.log("error reason : " + JSON.stringify(err.data[0].message));
      }
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('desistPersistPermission failed with err: ' + JSON.stringify(err));
  }
}
```

## activateAccessingUri<sup>11+</sup>

activateAccessingUri(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

异步方法使能某个已经永久授权过的文件或目录，以promise形式返回结果。

**系统能力：** SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型 | 必填 | 说明                      |
| -------- | -------- | -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyInfo)> | 是 | 需要授权URI的策略信息。           |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
如果只有部分URI持久化授权失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](#policyErrorResult)>形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied.|
| 401      | The input parameter is invalid |
| 801      | Capability not supported |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |


**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';

async function activateAccessingUriExample01() {
  try {
    let uri = "file://docs/storage/Users/username/tmp.txt";//uri为应用重启后读取的最近使用文件
    let policyInfo: filePermission.PolicyInfo = {
      uri: uri,
      operateMode: filePermission.OperateMode.READ_MODE,
    };
    let policies: Array<filePermission.PolicyInfo> = [policyInfo];
    filePermission.activateAccessingUri(policies).then(() => {
      console.info("activateAccessingUri successfully");
    }).catch((err: BusinessError) => {
      console.info("activateAccessingUri failed with error message: " + err.message + ", error code: " + err.code);
      if(err.code == 13900001){
      console.log("error code : " + JSON.stringify(err.data[0].code));
      console.log("error uri : " + JSON.stringify(err.data[0].uri));
      console.log("error reason : " + JSON.stringify(err.data[0].message));
      }
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('activateAccessingUri failed with err: ' + JSON.stringify(err));
  }
}
```

## deactivateAccessingUri<sup>11+</sup>

deactivateAccessingUri(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

异步方法取消使能授权过的文件或目录，以promise形式返回结果。

**系统能力：** SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型 | 必填 | 说明                      |
| -------- | -------- | -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyInfo)> | 是 | 需要授权URI的策略信息。           |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
如果只有部分URI持久化授权失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](#policyErrorResult)>形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied.|
| 401      | The input parameter is invalid |
| 801      | Capability not supported |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';

async function deactivateAccessingUriExample01() {
  try {
    let uri = "file://docs/storage/Users/username/tmp.txt";//uri为应用重启后读取的最近使用文件
    let policyInfo: filePermission.PolicyInfo = {
      uri: uri,
      operateMode: filePermission.OperateMode.READ_MODE,
    };
    let policies: Array<filePermission.PolicyInfo> = [policyInfo];
    filePermission.deactivateAccessingUri(policies).then(() => {
      console.info("deactivateAccessingUri successfully");
    }).catch((err: BusinessError) => {
      console.info("deactivateAccessingUri failed with error message: " + err.message + ", error code: " + err.code);
      if(err.code == 13900001){
        console.log("error code : " + JSON.stringify(err.data[0].code));
        console.log("error uri : " + JSON.stringify(err.data[0].uri));
        console.log("error reason : " + JSON.stringify(err.data[0].message));
      }
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('deactivateAccessingUri failed with err: ' + JSON.stringify(err));
  }
}
```