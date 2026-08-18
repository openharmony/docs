# @ohos.fileshare (File Sharing)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @leiyuqian; @zsyztt; @yue-ye2-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=b2b40ad27b0a04a8c75aa3540e06525fdca8ac20 translatedAt=2026-08-17T08:52:24.723Z pushedAt=2026-08-18T05:46:24.270Z -->

This module provides APIs for sharing files, which allows a system app to grant the access permissions on a file in the public directory in the specified access mode to another app based on the file Uniform Resource Identifier (URI). It also provides APIs for managing persistent authorization, activating permissions, and querying the authorization status. The authorized app can perform operations such as open, read, and write on the file by calling the [@ohos.file.fs](js-apis-file-fs.md) APIs, implementing file sharing between apps, cross-app file editing, and document collaboration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { fileShare } from '@kit.CoreFileKit';
```

## OperationMode<sup>11+</sup>

Enumerates the URI access modes for granting or activating permissions.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name | Value  | Description |
| ----- |-----|-----|
| READ_MODE  | 0b1 | Read.|
| WRITE_MODE  | 0b10 | Write.|
| CREATE_MODE<sup>20+</sup>  | 0b100 | Create. If no write permission is granted on the parent directory, the create permission of the target file or folder can be granted to create the file or folder. If the write permission is granted on the parent directory, no permission needs to be granted separately. |
| DELETE_MODE<sup>20+</sup>  | 0b1000 | Delete. If no write permission is granted on the parent directory, the delete permission of the target file or folder can be granted to delete the file or folder. If the write permission is granted on the parent directory, no permission needs to be granted separately. |
| RENAME_MODE<sup>20+</sup>  | 0b10000 | Rename. If no write permission is granted on the parent directory, the rename permission of the target file or folder can be granted to rename the file or folder. If the write permission is granted on the parent directory, no permission needs to be granted separately. |

## PolicyErrorCode<sup>11+</sup>

Enumerates the error codes for a permission policy.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name | Value  | Description       |
| ----- |-----|-----------|
| PERSISTENCE_FORBIDDEN  | 1   | The permission on the URI cannot be persisted.|
| INVALID_MODE  | 2   | Invalid mode.    |
| INVALID_PATH  | 3   | Invalid path.    |
| PERMISSION_NOT_PERSISTED<sup>12+</sup>  | 4   | The permission is not persisted.|

## PolicyErrorResult<sup>11+</sup>

Represents the permission policy error result, which can be used when **persistPermission**, **revokePermission**, **activatePermission**, or **deactivatePermission** throws an error.

> **NOTE**
>
> Since API version 23, the type of **PolicyErrorResult** is changed from **type** to **interface**.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name| Type| Read-Only| Optional| Description|
|--------|--------|--------|--------|---------|
| uri     | string| No  | No | URI of the file, on which the permission fails to be granted or activated.|
| code    | [PolicyErrorCode](#policyerrorcode11) | No | No| Error code.|
| message | string| No  | No| Error message. |

## PolicyInfo<sup>11+</sup>

Represents the permission policy information.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name | Type | Read-Only| Optional| Description                                                  |
|------|-------|------|-----|------------------------------------------------------|
| uri| string | No  | No | URI whose access permission needs to be granted or activated. The URI must comply with the URI format specifications. |
| operationMode | number | No  | No | URI operation mode. For details, see [OperationMode](#operationmode11). The value can be **READ_MODE**, **WRITE_MODE**, **CREATE_MODE**, **DELETE_MODE**, or **RENAME_MODE**. **CREATE_MODE**, **DELETE_MODE**, and **RENAME_MODE** support only temporary authorization. To grant multiple permissions, you can combine them, for example, use **READ_MODE \| WRITE_MODE** to grant the read and write permissions. |

## PathPolicyInfo<sup>15+</sup>

Represents the information about the file or directory to be queried.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name| Type | Read-Only| Optional| Description |
|------|-------|-----|-----|--------|
| path          | string        | No  | No   | Path of the file or directory to be queried.|
| operationMode | OperationMode | No  | No   | Operation mode of the file or directory to be queried. For details, see [OperationMode](#operationmode11). The value can be **READ_MODE**, **WRITE_MODE**, **CREATE_MODE**, **DELETE_MODE**, or **RENAME_MODE**. To query multiple permissions, you can combine them, for example, use **READ_MODE \| WRITE_MODE** to query the read and write permissions. |

## PolicyType<sup>15+</sup>

Enumerates the authorization modes corresponding to the queried policy information. Temporary permissions are used to grant short-term access, while persistent permissions are granted to access files or directories on a long-term basis.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name | Value  | Description       |
| ----- |-----|-----------|
| TEMPORARY_TYPE  | 0   | Temporary permission.|
| PERSISTENT_TYPE  | 1   | Persistent permission.    |

## fileShare.persistPermission<sup>11+</sup>

persistPermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

Checks persistent permissions. This API uses a promise to return the result. Persistent permissions are used to save obtained temporary permissions as long-term permissions. This API is available only to the devices with the required system capability. This API does not support persistent permissions for remote URIs.
> **NOTE**
>
> Starting from API version 22, this API supports persistent permissions for media URIs.
>
> Multiple permissions can be granted in combination. Only obtained temporary permissions can be granted persistently. Otherwise, an error is reported.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type | Mandatory| Description |
| -------- |---------| -------- |--------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes | Array of URI policies for granting persistent permissions. The maximum number of policies is 500. Only obtained temporary permissions can be granted persistently. Remote URIs are not supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

If the permission persistence of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Out of memory.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { picker } from '@kit.CoreFileKit';
  
  async function persistPermissionExample() {
    try {
      let documentSelectOptions = new picker.DocumentSelectOptions();
      let documentPicker = new picker.DocumentViewPicker();
      let uris = await documentPicker.select(documentSelectOptions);
      if (uris.length === 0) {
        console.error('No file selected');
        return;
      }
      let policyInfo: fileShare.PolicyInfo = {
        uri: uris[0], 
        // Multiple permissions can be granted in combination. For example, the read and write permissions can be granted using fileShare.OperationMode.READ_MODE \| fileShare.OperationMode.WRITE_MODE.
        operationMode: fileShare.OperationMode.READ_MODE
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.persistPermission(policies).then(() => {
        console.info('persistPermission successfully');
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error(`persistPermission failed with error message: ${err.message}, error code: ${err.code}`);
        if (err.code === 13900001 && err.data) {
          for (let i = 0; i < err.data.length; i++) {
            console.error(`error code: ${JSON.stringify(err.data[i].code)}`);
            console.error(`error URI: ${JSON.stringify(err.data[i].uri)}`);
            console.error(`error reason: ${JSON.stringify(err.data[i].message)}`);
          }
        }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`persistPermission failed with err: ${JSON.stringify(err)}`);
    }
  }
  ```

## fileShare.revokePermission<sup>11+</sup>

revokePermission(policies: Array&lt;PolicyInfo&gt;): Promise&lt;void&gt;

Checks revocation of persistent permissions. This API uses a promise to return the result. After persistent permissions are revoked, you need to obtain temporary permissions again before you can be granted with persistent permissions. This API is available only to the devices with the required system capability. This API does not support persistent permissions for remote URIs.
> **NOTE**
>
> Starting from API version 22, this API supports persistent permissions for media URIs.
>
> Multiple permissions can be revoked in combination. Only persistent permissions can be revoked. Otherwise, an error is reported.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type | Mandatory| Description |
| -------- |----------| -------- |----------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes | Array of URI policies for revoking persistent permissions. The maximum number of policies is 500. Only persistent permissions can be revoked. Remote URIs are not supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md). 

If the permission revocation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID| Error Message|
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Out of memory.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { picker } from '@kit.CoreFileKit';
  
  async function revokePermissionExample() {
    try {
      let documentSelectOptions = new picker.DocumentSelectOptions();
      let documentPicker = new picker.DocumentViewPicker();
      let uris = await documentPicker.select(documentSelectOptions);
      if (uris.length === 0) {
        console.error('No file selected');
        return;
      }
      let policyInfo: fileShare.PolicyInfo = {
        uri: uris[0], 
        // Multiple permissions can be revoked in combination. For example, the read and write permissions can be revoked using fileShare.OperationMode.READ_MODE \| fileShare.OperationMode.WRITE_MODE.
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.revokePermission(policies).then(() => {
        console.info('revokePermission successfully');
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error(`revokePermission failed with error message: ${err.message}, error code: ${err.code}`);
        if (err.code === 13900001 && err.data) {
          for (let i = 0; i < err.data.length; i++) {
            console.error(`error code: ${JSON.stringify(err.data[i].code)}`);
            console.error(`error URI: ${JSON.stringify(err.data[i].uri)}`);
            console.error(`error reason: ${JSON.stringify(err.data[i].message)}`);
          }
        }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`revokePermission failed with err: ${JSON.stringify(err)}`);
    }
  }
  ```

## fileShare.activatePermission<sup>11+</sup>

activatePermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

Activates the permissions that have been persisted on multiple files or directories. This API uses a promise to return the result. Persistent permissions are the prerequisite for activation. After the permissions are activated, you can call **deactivatePermission** to deactivate them. This API is available only to the devices with the required system capability. This API does not support persistent permissions for remote URIs.
> **NOTE**
>
> Starting from API version 22, this API supports persistent permissions for media URIs.
>
> Multiple permissions can be activated in combination. You need to call **persistPermission** to complete persistent permissions before activating the permissions. Otherwise, an error is reported.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- |---------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes | Array of URI policies for activating permissions. The maximum number of policies is 500. Only persistent permissions can be activated. Remote URIs are not supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

If the permission activation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Out of memory.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  async function activatePermissionExample() {
    try {
      let uri = 'file://docs/storage/Users/username/tmp.txt';
      let policyInfo: fileShare.PolicyInfo = {
        uri: uri,
        // Multiple permissions can be activated in combination. For example, the read and write permissions can be checked using fileShare.OperationMode.READ_MODE \| fileShare.OperationMode.WRITE_MODE.
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.activatePermission(policies).then(() => {
        console.info('activatePermission successfully');
      }).catch(async (err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error(`activatePermission failed with error message: ${err.message}, error code: ${err.code}`);
        if (err.code === 13900001 && err.data) {
          for (let i = 0; i < err.data.length; i++) {
            console.error(`error code: ${JSON.stringify(err.data[i].code)}`);
            console.error(`error URI: ${JSON.stringify(err.data[i].uri)}`);
            console.error(`error reason: ${JSON.stringify(err.data[i].message)}`);
            if (err.data[i].code === fileShare.PolicyErrorCode.PERMISSION_NOT_PERSISTED) {
              await fileShare.persistPermission(policies);
            }
          }
        }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`activatePermission failed with err: ${JSON.stringify(err)}`);
    }
  }
  ```

## fileShare.deactivatePermission<sup>11+</sup>

deactivatePermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

Deactivates the permissions on multiple files or directories. This API uses a promise to return the result. After the permissions are deactivated, the persistent permissions are still retained and can be activated again using the **activatePermission** API. This API is available only to the devices with the required system capability. This API does not support persistent permissions for remote URIs.
> **NOTE**
>
> Starting from API version 22, this API supports persistent permissions for media URIs.
>
> Multiple permissions can be deactivated in combination. Only persistent permissions can be deactivated. You need to call **activatePermission** to activate the permission first. Otherwise, an error is reported.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type| Mandatory| Description |
| -------- | -------- | -------- |---------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Mandatory | Array of URI policies for deactivating permissions. The maximum number of policies is 500. Only persistent permissions can be deactivated. Remote URIs are not supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

If the permission deactivation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Out of memory.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  async function deactivatePermissionExample() {
    try {
      let uri = 'file://docs/storage/Users/username/tmp.txt';
      let policyInfo: fileShare.PolicyInfo = {
        uri: uri,
        // Multiple permissions can be deactivated in combination. For example, the read and write permissions can be checked using fileShare.OperationMode.READ_MODE \| fileShare.OperationMode.WRITE_MODE.
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.deactivatePermission(policies).then(() => {
        console.info('deactivatePermission successfully');
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error(`deactivatePermission failed with error message: ${err.message}, error code: ${err.code}`);
        if (err.code === 13900001 && err.data) {
          for (let i = 0; i < err.data.length; i++) {
            console.error(`error code: ${JSON.stringify(err.data[i].code)}`);
            console.error(`error URI: ${JSON.stringify(err.data[i].uri)}`);
            console.error(`error reason: ${JSON.stringify(err.data[i].message)}`);
          }
        }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`deactivatePermission failed with err: ${JSON.stringify(err)}`);
    }
  }
  ```

## fileShare.checkPersistentPermission<sup>12+</sup>

checkPersistentPermission(policies: Array&lt;PolicyInfo>): Promise&lt;Array&lt;boolean&gt;&gt;

Checks persistent permissions. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type                                   | Mandatory| Description                     |
| -------- |---------------------------------------| -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)&gt; | Yes | Array of URI policies for checking persistent permissions. The maximum number of policies is 500.|

**Return value**

|   Type  |  Description  |
| ------- | ------- |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise used to return the persistent permission verification result array. Elements in the array correspond to the policy elements. The value **true** means the permission is persistent; the value **false** means the opposite. |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message      |
|----------| --------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900042 | Out of memory.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { picker } from '@kit.CoreFileKit';
  
  async function checkPersistentPermissionExample() {
    try {
      let documentSelectOptions = new picker.DocumentSelectOptions();
      let documentPicker = new picker.DocumentViewPicker();
      let uris = await documentPicker.select(documentSelectOptions);
      if (uris.length === 0) {
        console.error('No file selected');
        return;
      }
      let policyInfo: fileShare.PolicyInfo = {
        uri: uris[0], 
        // Multiple permissions can be checked in combination. For example, the read and write permissions can be checked using fileShare.OperationMode.READ_MODE \| fileShare.OperationMode.WRITE_MODE.
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.checkPersistentPermission(policies).then(async (data) => {
        let result: Array<boolean> = data;
        for (let i = 0; i < result.length; i++) {
          console.info(`checkPersistentPermission result: ${JSON.stringify(result[i])}`);
          if (!result[i]) {
            let info: fileShare.PolicyInfo = {
              uri: policies[i].uri, 
              operationMode: policies[i].operationMode,
            };
            let policy: Array<fileShare.PolicyInfo> = [info];
            await fileShare.persistPermission(policy);
          }
        }
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.error(`checkPersistentPermission failed with error message: ${err.message}, error code: ${err.code}`);
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`checkPersistentPermission failed with err: ${JSON.stringify(err)}`);
    }
  }
  ```