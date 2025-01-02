# @ohos.fileshare (File Sharing) (System API)

The **fileShare** module provides APIs for granting the access permissions on a user file to another application based on the file Uniform Resource Identifier (URI). Then, the authorized application can access the file by using the [@ohos.file.fs](js-apis-file-fs.md) APIs.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.fileshare](js-apis-fileShare-sys.md).

## Modules to Import

```ts
import  { fileShare } from '@kit.CoreFileKit';
```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback&lt;void&gt;): void

Grants the permissions on a user file to an application. This API uses an asynchronous callback to return the result. 

**Required permissions**: ohos.permission.WRITE_MEDIA 

**System API**: This is a system API. 

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of the file.|
| bundleName   | string | Yes  | Application to be grated with the permissions.|
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#wantconstantflags) | Yes  | Permissions to grant.<br>**wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION**: permission to read the file. <br>**wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION**: permission to write the file.|
 | callback | AsyncCallback&lt;void&gt;  | Yes   | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types |
| 143000001 | IPC error |

**Example**

  ```ts
  import { wantConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
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

Grants the permissions on a user file to an application. This API uses a promise to return the result. 

**Required permissions**: ohos.permission.WRITE_MEDIA 

**System API**: This is a system API. 

**System capability**: SystemCapability.FileManagement.AppFileService 

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of the file.|
| bundleName   | string | Yes  | Application to be grated with the permissions.|
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#wantconstantflags) | Yes  | Permissions to grant.<br>**wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION**: permission to read the file. <br>**wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION**: permission to write the file.|

**Return value**

  | Type                          | Description        |
  | ---------------------------- | ---------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types |
| 143000001 | IPC error |

**Example**

  ```ts
  import { wantConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
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


deactivatePermission(policies: Array&lt;PolicyInfo>): Promise&lt;void&gt;

Deactivates the permissions on multiple files or folders. This API uses a promise to return the result. <br>This API is available only to the devices that have the required system capability.

**Required permissions**: ohos.permission.FILE_ACCESS_PERSIST

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type| Mandatory| Description                     |
| -------- | -------- | -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](js-apis-fileShare.md#policyinfo11)> | Yes| Permissions to persist.          |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).
If the permission deactivation of some URIs fails, error code 13900001 will be returned and the **data** field provides error information of these URIs in the Array<[PolicyErrorResult](js-apis-fileShare.md#policyerrorresult11)> format.

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |

**Example**

  ```ts
import { BusinessError } from '@kit.BasicServicesKit';
import  { picker } from '@kit.CoreFileKit';
  
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
