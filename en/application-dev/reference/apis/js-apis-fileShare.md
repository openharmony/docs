# @ohos.fileshare (File Sharing)

The **fileShare** module provides APIs for granting the access permissions on a user file to another application by the file Uniform Resource Identifier (URI). Then, the authorized application can access the file by using the [@ohos.file.fs](js-apis-file-fs.md) APIs.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import fileShare from '@ohos.fileshare';
```

## OperationMode<sup>11+</sup>

Enumerates the modes for accessing a URI.

**System capability**: SystemCapability.FileManagement.AppFileService

| Name | Value  | Description |
| ----- |-----|-----|
| READ_MODE  | 0b1 | Read.|
| WRITE_MODE  | 0b10 | Write.|

## PolicyFlag<sup>11+</sup>

Enumerates the policies for the URI that is granted or enabled with permissions.

**System capability**: SystemCapability.FileManagement.AppFileService

| Name | Value  | Description     |
| ----- |-----|---------|
| ALLOW_PERSISTENCE  | 0b1 | The application is allowed to persist file data.|
| FORBID_PERSISTENCE  | 0b10 | The application is not allowed to persist file data.|

## PolicyErrorCode<sup>11+</sup>

Enumerates the error codes for a permission policy.

**System capability**: SystemCapability.FileManagement.AppFileService

| Name | Value  | Description       |
| ----- |-----|-----------|
| PERSISTENCE_FORBIDDEN  | 1   | The permission on the URI cannot be persisted.|
| INVALID_MODE  | 2   | Invalid mode.    |
| INVALID_PATH  | 3   | Invalid path.    |

## PolicyErrorResult<sup>11+</sup>

Represents the detailed permission policy error information, which can be used when **persistPermission**, **revokePermission**, **activatePermission**, or **deactivatePermission** throws an error.

**System capability**: SystemCapability.FileManagement.AppFileService

| Name     | Type                                  | Description               |
|---------|--------------------------------------|-------------------|
| uri     | string                               | URI of the file, on which the permission fails to be granted or activated.        |
| code    | [PolicyErrorCode](#policyerrorcode11) | Error code.|
| message | string                               | Cause of the error. |

## PolicyInfo<sup>11+</sup>

Represents a permission policy, that is, a policy for granting or activating the permission on a file.

**System capability**: SystemCapability.FileManagement.AppFileService

| Name           | Type      | Mandatory | Description                                                                                                                                               |
|---------------| ---------|-----|---------------------------------------------------------------------------------------------------------------------------------------------------|
| uri           | string     | Yes  | URI of the file, on which the permission is to be granted or activated.                                                                                                                                   |
| operationMode | number  | Yes  | Mode for accessing the URI. For details, see [OperationMode](#operationmode11).<br>  For example, **fileShare.OperationMode.READ_MODE** indicates the read permission on the file.<br>  <br>**fileShare.OperationMode.READ_MODE\|fileShare.OperationMode.WRITE_MODE**| indicates the read and write permissions on the file.|


## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback&lt;void&gt;): void

Grants permissions on a user file by the URI to an application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_MEDIA 

**System API**: This is a system API. 

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of the file.|
| bundleName   | string | Yes  | Application to be grated with the permissions.|
| flag   | wantConstant.Flags | Yes  | Permissions to grant. For details, see [wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags).<br>**wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION**: permission to read the file. <br>**wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION**: permission to write the file.|
 | callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked to return the result.                            |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid |
| 143000001 | IPC error |

**Example**

  ```ts
  import wantConstant from '@ohos.app.ability.wantConstant';
  import { BusinessError } from '@ohos.base';
  let uri: string = 'file://media/image/8';
  let bundleName: string = 'com.demo.test';
  try {
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION, (err: BusinessError) => {
      if (err) {
        console.error("grantUriPermission failed with error: " + JSON.stringify(err));
        return;
      }
      console.info("grantUriPermission success!");
    });
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("grantUriPermission failed with error:" + JSON.stringify(error));
  }
  ```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise&lt;void&gt;

Grants permissions on a user file by the URI to an application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_MEDIA 

**System API**: This is a system API. 

**System capability**: SystemCapability.FileManagement.AppFileService 

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of the file.|
| bundleName   | string | Yes  | Application to be grated with the permissions.|
| flag   | wantConstant.Flags | Yes  | Permissions to grant. For details, see [wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags).<br>**wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION**: permission to read the file. <br>**wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION**: permission to write the file.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid |
| 143000001 | IPC error |

**Example**

  ```ts
  import wantConstant from '@ohos.app.ability.wantConstant';
  import { BusinessError } from '@ohos.base';
  let uri: string = 'file://media/image/8';
  let bundleName: string = 'com.demo.test';
  try {
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION).then(() => {
      console.info("grantUriPermission success!");
    }).catch((error: BusinessError) => {
      console.error("grantUriPermission failed with error:" + JSON.stringify(error));
    });
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("grantUriPermission failed with error:" + JSON.stringify(error));
  }
  ```

## fileShare.grantPermission<sup>11+</sup>

grantPermission(tokenId: number, policies: Array&lt;PolicyInfo>, policyFlag: number): Promise&lt;void&gt;

Temporarily grants permissions for a URI. This API uses a promise to return the result. This API is available only to specific devices.

**Required permissions**: ohos.permission.SET_SANDBOX_POLICY

**System capability**: SystemCapability.FileManagement.AppFileService

**System API**: This is a system API.

**Parameters**

| Name    | Type                                  | Mandatory| Description                                                                                          |
|---------|--------------------------------------| -------- |----------------------------------------------------------------------------------------------|
| tokenId | number                               | Yes| Token ID of the application that starts filePicker.                                                                     |
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Information about the permission to be granted.                                                                               |
| policyFlag    | number                               | Yes| Policy for the URI. For details, see [PolicyFlag](#policyflag11).<br>  For example, **fileShare.PolicyFlag.ALLOW_PERSISTENCE** allows the file data to be persisted.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID   | Error Message                                  |
|----------|----------------------------------------|
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error.         |
| 801      | Capability not supported.               |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |


**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  
  async function grantPermissionExample() {
    try {
      let uri = "file://docs/storage/Users/username/1.txt";
      let tokenId = 1000;
      let policyInfo: fileShare.PolicyInfo = {
        uri: uri, 
        operationMode: fileShare.OperationMode.READ_MODE,
      };
      let policies: Array<fileShare.PolicyInfo> = [policyInfo];
      fileShare.grantPermission(tokenId, policies, fileShare.PolicyFlag.ALLOW_PERSISTENCE).then(() => {
        console.info("grantPermission successfully");
      }).catch((err: BusinessError) => {
        console.info("grantPermission failed with error message: " + err.message + ", error code: " + err.code);
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('grantPermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## fileShare.persistPermission<sup>11+</sup>

persistPermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

Persists the permissions granted to multiple files or folders. This API uses a promise to return the result.<br>This API is available only to certain devices.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type                                   | Mandatory| Description                     |
| -------- |---------------------------------------| -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Permissions to persist.          |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
If the permission persistence of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |


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
        console.info("persistPermission failed with error message: " + err.message + ", error code: " + err.code);
        if (err.code == 13900001 && err.data) {
          for (let i = 0; i < err.data.length; i++) {
            console.log("error code : " + JSON.stringify(err.data[i].code));
            console.log("error uri : " + JSON.stringify(err.data[i].uri));
            console.log("error reason : " + JSON.stringify(err.data[i].message));
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

Revokes permissions from multiple files or folders. This API uses a promise to return the result.<br>This API is available only to certain devices.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type                | Mandatory| Description                     |
| -------- |--------------------| -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Permissions to persist.          |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
If the permission revocation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |


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
        console.info("revokePermission failed with error message: " + err.message + ", error code: " + err.code);
          if (err.code == 13900001 && err.data) {
            for (let i = 0; i < err.data.length; i++) {
              console.log("error code : " + JSON.stringify(err.data[i].code));
              console.log("error uri : " + JSON.stringify(err.data[i].uri));
              console.log("error reason : " + JSON.stringify(err.data[i].message));
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

Activates the permissions that have been persisted on multiple files or folders. This API uses a promise to return the result. <br>This API is available only to certain devices.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type| Mandatory| Description                     |
| -------- | -------- | -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Permissions to persist.          |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
If the permission activation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |


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
      }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
        console.info("activatePermission failed with error message: " + err.message + ", error code: " + err.code);
          if (err.code == 13900001 && err.data) {
            for (let i = 0; i < err.data.length; i++) {
              console.log("error code : " + JSON.stringify(err.data[i].code));
              console.log("error uri : " + JSON.stringify(err.data[i].uri));
              console.log("error reason : " + JSON.stringify(err.data[i].message));
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

Deactivates the permissions on multiple files or folders. This API uses a promise to return the result. <br>This API is available only to certain devices.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type| Mandatory| Description                     |
| -------- | -------- | -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](#policyinfo11)> | Yes| Permissions to persist.          |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
If the permission deactivation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |

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
        console.info("deactivatePermission failed with error message: " + err.message + ", error code: " + err.code);
          if (err.code == 13900001 && err.data) {
            for (let i = 0; i < err.data.length; i++) {
              console.log("error code : " + JSON.stringify(err.data[i].code));
              console.log("error uri : " + JSON.stringify(err.data[i].uri));
              console.log("error reason : " + JSON.stringify(err.data[i].message));
            }
          }
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('deactivatePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```
