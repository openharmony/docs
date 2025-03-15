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

| Name| Type| Mandatory| Description|
| ------ |---------| ---- |-----------|
| uri   | string| Yes  | URI of the file under user directory.|
| bundleName   | string| Yes  | Application to be granted with the permissions.  |
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) | Yes  | Permissions to grant.    |
 | callback | AsyncCallback&lt;void&gt;| Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| ------ | ------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types |
| 143000001 | IPC error |

**Example**

  ```ts
  import { wantConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let uri: string = 'file://docs/storage/Users/currentUser/Document/1.txt';  // You are advised to use the system API to generate a URI using fileUri.getUriFromPath("Sandbox path");
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

| Name| Type| Mandatory| Description       |
| ------ |-------| ---- |-----------|
| uri   | string| Yes  | URI of the file under user directory.|
| bundleName   | string| Yes  | Application to be granted with the permissions.  |
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) | Yes  | Permissions to grant.    |

**Return value**

  | Type                          | Description        |
  | ---------- | ---------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| ------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types |
| 143000001 | IPC error |

**Example**

  ```ts
  import { wantConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let uri: string = 'file://docs/storage/Users/currentUser/Document/1.txt'; // You are advised to use the system API fileUri.getUriFromPath("Sandbox path") to generate a URI.;
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

## fileShare.checkPathPermission<sup>15+</sup>

checkPathPermission(tokenID: number, policies: Array&lt;PathPolicyInfo&gt;, policyType: PolicyType): Promise&lt;Array&lt;boolean&gt;&gt;

Checks whether the selected files or folders have temporary or persistent permissions. This API uses a promise to return the result.

**Required permission**: ohos.permission.CHECK_SANDBOX_POLICY

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.AppFileService.FolderAuthorization

**Parameters**

| Name| Type| Mandatory| Description|
| -------- |-------| -------- |----------|
| tokenID| number | Yes| Application token ID, which is the value of **accessTokenId** in [ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md).|
| policies| Array&lt;[PathPolicyInfo](js-apis-fileShare.md#pathpolicyinfo15)> | Yes| Array of permission policies. The maximum number of policies is 500.|
| policyType| [PolicyType](js-apis-fileShare.md#policytype15) | Yes| Policy type to check, which can be a temporary or persistent permission.|

**Return value**

|Type|Description|
| ------ | ------ |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise used to return the result. The value **true** means that a policy type is used. Otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  
  async function checkPersistentPermissionExample() {
    try {
      let pathPolicyInfo1: fileshare.PathPolicyInfo = {
        path: "/storage/Users/currentUser/Documents/1.txt",
        operationMode: fileshare.OperationMode.READ_MODE,
      }
      let pathPolicyInfo2: fileshare.PathPolicyInfo = {
        path: "/storage/Users/currentUser/Desktop/2.txt",
        operationMode: fileshare.OperationMode.READ_MODE,
      }

      let policies: Array<fileshare.PathPolicyInfo> = [pathPolicyInfo1, pathPolicyInfo2];
      let policyType: fileshare.PolicyType = fileshare.PolicyType.PERSISTENT_TYPE;
      let tokenid = 537688848; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a non-system application.
      
      fileshare.checkPathPermission(tokenid, policies, policyType).then((result:Array<boolean>) => {
        for (let x of result) {
          console.info('check permission result is', x);
        }
      })
      console.info("checkPathPermission finish");
    }
    catch (error) {
      console.info(error.code + 'checkPathPermission error' + error.message);
    }
  }
  ```
