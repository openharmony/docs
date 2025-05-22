# @ohos.fileshare (File Sharing)

The **fileShare** module provides APIs for granting permissions on a user file to another application based on the file Uniform Resource Identifier (URI). Then, the authorized application can call [@ohos.file.fs](js-apis-file-fs.md) APIs to access the file.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import fileShare from '@ohos.fileshare';
```

## OperationMode<sup>11+</sup>

Enumerates the modes for accessing a URI.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name | Value  | Description |
| ----- |-----|-----|
| READ_MODE  | 0b1 | Read.|
| WRITE_MODE  | 0b10 | Write.|

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

Represents the detailed permission policy error information, which can be used when **persistPermission**, **revokePermission**, **activatePermission**, or **deactivatePermission** throws an error.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name| Type| Mandatory| Description|
|--------|--------|--------|---------|
| uri     | string| Yes | URI of the file, on which the permission fails to be granted or activated.|
| code    | [PolicyErrorCode](#policyerrorcode11) | Yes | Error code.|
| message | string| Yes  | Cause of the error. |

## PolicyInfo<sup>11+</sup>

Represents a permission policy, that is, a policy for granting or activating the permission on a file.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name | Type | Mandatory | Description                                                  |
|------|-------|------|------------------------------------------------------|
| uri| string | Yes  | URI of the file, on which the permission is to be granted or activated.                                      |
| operationMode | number | Yes  | Permission on the URI. For details, see [OperationMode](#operationmode11).|

## PathPolicyInfo<sup>15+</sup>

Information about the file or directory to be queried.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name| Type | Mandatory | Description |
|------|-------|-----|--------|
| path          | string        | Yes  | Path to be queried.|
| operationMode | OperationMode | Yes  | Access mode of the path to be queried. For details, see [OperationMode](#operationmode11).|

## PolicyType<sup>15+</sup>

Enumerates the authorization modes corresponding to the queried policy information.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

| Name | Value  | Description       |
| ----- |-----|-----------|
| TEMPORARY_TYPE  | 0   | Temporary permission.|
| PERSISTENT_TYPE  | 1   | Persistent permission.    |

## fileShare.persistPermission<sup>11+</sup>

persistPermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

Checks persistent permissions. This API uses a promise to return the result. This API is available only to the devices with the required system capability. (This API does not support persistent permissions for media URIs and remote URIs.)

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type | Mandatory| Description |
| -------- |---------| -------- |--------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Array of permission policies. The maximum number of policies is 500.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).\n
If the permission persistence of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Unknown error.|

**Example**

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

Revokes permissions from multiple files or folders. This API uses a promise to return the result. This API is available only to the devices with the required system capability. (This API does not support persistent permissions for media URIs and remote URIs.)

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type | Mandatory| Description |
| -------- |----------| -------- |----------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Array of permission policies. The maximum number of policies is 500.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).\n
If the permission revocation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID| Error Message|
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Unknown error.|

**Example**

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

Activates the permissions that have been persisted on multiple files or folders. This API uses a promise to return the result. This API is available only to the devices with the required system capability. (This API does not support persistent permissions for media URIs and remote URIs.)

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- |---------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Array of permission policies. The maximum number of policies is 500.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).\n
If the permission activation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Unknown error.|

**Example**

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

Deactivates the permissions on multiple files or folders. This API uses a promise to return the result. This API is available only to the devices with the required system capability. (This API does not support persistent permissions for media URIs and remote URIs.)

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type| Mandatory| Description |
| -------- | -------- | -------- |---------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Array of permission policies. The maximum number of policies is 500.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).\n
If the permission deactivation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.|
| 13900042 | Unknown error.|

**Example**

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

Checks persistent permissions. This API uses a promise to return the result.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type                                   | Mandatory| Description                     |
| -------- |---------------------------------------| -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)&gt; | Yes| Array of permission policies. The maximum number of policies is 500.|

**Return value**

|   Type  |  Description  |
| ------- | ------- |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise used to return the result. The value **true** means the permission is persistent; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900042 | Unknown error.|

**Example**

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
  
