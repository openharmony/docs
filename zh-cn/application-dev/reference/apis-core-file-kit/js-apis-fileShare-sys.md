# @ohos.fileshare (文件分享)(系统接口)

该模块提供文件分享能力，提供系统应用将公共目录文件统一资源标志符（Uniform Resource Identifier，URI）以读写权限授权给其他应用的接口，授权后应用可通过[@ohos.file.fs](js-apis-file-fs.md)的相关接口进行相关open、read、write等操作，实现文件分享。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.fileshare (文件分享)](js-apis-fileShare-sys.md)。

## 导入模块

```ts
import  { fileShare } from '@kit.CoreFileKit';
```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback&lt;void&gt;): void

对公共目录文件URI进行授权操作，使用callback异步回调。  

**需要权限**：ohos.permission.WRITE_MEDIA  

**系统接口**：此接口为系统接口  

**系统能力**：SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 公共目录文件URI |
| bundleName   | string | 是   | 分享目标的包名 |
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) | 是   | 授权的权限。<br/>wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION：读授权<br/>wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION：写授权|
 | callback | AsyncCallback&lt;void&gt;  | 是    | 异步授权之后的回调                             |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types |
| 143000001 | IPC error |

**示例：**

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

将公共目录文件URI进行授权操作，使用Promise异步回调。  

**需要权限**：ohos.permission.WRITE_MEDIA  

**系统接口**：此接口为系统接口  

**系统能力**：SystemCapability.FileManagement.AppFileService  

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 公共目录文件URI |
| bundleName   | string | 是   | 分享目标的包名 |
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) | 是   | 授权的权限。<br/>wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION：读授权<br/>wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION：写授权|

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;void&gt; | Promise对象，无返回值 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types |
| 143000001 | IPC error |

**示例：**

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

异步方法取消使能授权过的多个文件或目录，以promise形式返回结果，该接口仅对具有该系统能力的设备开放。

**需要权限**：ohos.permission.FILE_ACCESS_PERSIST

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型 | 必填 | 说明                      |
| -------- | -------- | -------- |-------------------------|
| policies| Array&lt;[PolicyInfo](js-apis-fileShare.md#policyinfo11)> | 是 | 需要授权URI的策略信息。           |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。
如果存在URI取消使能权限失败，则抛出13900001错误码，且失败URI信息将抛出异常data属性中以Array<[PolicyErrorResult](js-apis-fileShare.md#policyerrorresult11)>形式提供错误信息。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |
| 13900001 | Operation not permitted.            |
| 13900042 | Unknown error                          |

**示例：**

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

## fileShare.checkPathPermission<sup>15+</sup>

checkPathPermission(tokenID: number, policies: Array&lt;PathPolicyInfo&gt;, policyType: PolicyType): Promise&lt;Array&lt;boolean&gt;&gt;

异步方法校验所选择的多个文件或目录是否有临时或持久化授权，以promise形式返回结果。

**需要权限**：ohos.permission.CHECK_SANDBOX_POLICY

**系统接口**：此接口为系统接口

**系统能力：** SystemCapability.FileManagement.AppFileService.FolderAuthorization

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                      |
| -------- |---------------------------------------| -------- |-------------------------|
| tokenID| number | 是 | 目标应用的身份标识。可通过应用的[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| policies| Array&lt;[PathPolicyInfo](js-apis-fileShare.md#pathpolicyinfo15)> | 是 | 需要授权路径的策略信息，policies数组大小上限为500。|
| policyType| [PolicyType](js-apis-fileShare.md#policytype15) | 是 | 要查询的授权类型，具体是临时授权或持久化授权。 |

**返回值：**

|              类型                   |               说明                    |
| ----------------------------------- | ------------------------------------- |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise对象，返回true表示授权类型匹配policyType的查询类型，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.|
| 202      | The caller is not a system application.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported. |                         |

**示例：**

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
      let tokenid = 537688848; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取
      
      fileshare.checkPathPermission(tokenid, policies, policyType).then((result:Array<boolean>) => {
        for (let x of result) {
          console.info('check permission result is', x);
        }
      })
      this.message = "checkPathPermission finish";
    }
    catch (error) {
      this.message = error.message;
      console.info(error.code + 'checkPathPermission error' + error.message);
    }
  }
  ```