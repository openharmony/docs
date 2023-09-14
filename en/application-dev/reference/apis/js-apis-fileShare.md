# @ohos.fileshare (File Sharing)

The **fileShare** module provides APIs for granting the access permissions on a user file to another application by the Uniform Resource Identifier (URI). Then, the authorized application can access the file by using the APIs provided by [@ohos.file.fs](js-apis-file-fs.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import fileShare from '@ohos.fileshare';
```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback&lt;void&gt;): void

Grants permissions on a user file by the URI to an application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_MEDIA 

**System API**: This is a system API. 

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of a user file.|
| bundleName   | string | Yes  | Bundle name of the application to be grated with the permissions.|
| flag   | wantConstant.Flags | Yes  | Permissions to grant. For details, see [wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags).<br>**wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION**: permission to read the file. <br>**wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION**: permission to write the file.|
 | callback | AsyncCallback&lt;void&gt;  | Yes   | Callback invoked to return the result.                           |

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
| uri   | string | Yes  | URI of a user file.|
| bundleName   | string | Yes  | Bundle name of the application to be grated with the permissions.|
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
