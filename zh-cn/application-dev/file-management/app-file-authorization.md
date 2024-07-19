# 文件授权访问(ArkTS)

提供给应用的文件授权访问场景主要分为：

1. 获取并使用公共目录。
2. 通过FilePicker选择文件或目录授权并支持授权持久化。
3. 通过接口获取文件或文件夹当前所在路径的URI。
4. 通过接口获取外卡目录。

文件授权访问的场景仅支持部分设备。

下面介绍几种常用操作示例。

## 获取并使用公共目录

通过目录环境能力获取公共目录，通过弹窗授权方式向用户申请授予对应目录的权限后对相应目录进行访问，具体请参考([获取并使用公共目录](../file-management/request-dir-permission.md))。

## 通过FilePicker设置永久授权

通过FilePicker选择文件或文件夹后设置永久授权，以及应用重启后的激活权限过程如下所示，通过文件分享接口（[ohos.fileshare](../reference/apis-core-file-kit/js-apis-fileShare.md)）实现文件授权能力。

1. 应用调用picker的([select](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3))接口，通过FilePicker选择和保存路径URI，此时应用获得该路径的临时访问权限。

   以下示例代码演示了获取文件夹URI的过程：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { picker } from '@kit.CoreFileKit';

   async function selectExample() {
     try {
       let DocumentSelectOptions = new picker.DocumentSelectOptions();
       DocumentSelectOptions.selectMode = picker.DocumentSelectMode.FOLDER;
       let documentPicker = new picker.DocumentViewPicker();
       let uris = await documentPicker.select(DocumentSelectOptions);
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error('select failed with err: ' + JSON.stringify(err));
     }
   }
   ```

2. 应用按需对路径设置持久化授权，检查是否对URI有持久化权限，如果没有权限则进行第3步持久化权限，参数uri为第1步FilePicker应用获取的选择路径。

   以下示例代码演示了检查持久化权限过程：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { picker } from '@kit.CoreFileKit';
   import { fileShare } from '@kit.CoreFileKit';

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
         let results: Array<boolean> = data;
         for (let i = 0; i < results.length; i++) {
           console.log("checkPersistentPermission result: " + JSON.stringify(results[i]));
           if (!results[i]) {
             let info: fileShare.PolicyInfo = {
               uri: policies[i].uri,
               operationMode: policies[i].operationMode,
             };
             let policy: Array<fileShare.PolicyInfo> = [info];
             await fileShare.persistPermission(policy);
           }
         }
       }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
         console.info("checkPersistentPermission failed with error message: " + err.message + ", error code: " + err.code);
       });
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error('checkPersistentPermission failed with err: ' + JSON.stringify(err));
     }
   }
   ```

3. 应用按需对路径设置持久化授权，参数uri为第1步FilePicker应用获取的选择路径。

   以下示例代码演示了持久化授权过程：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileShare } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   async function persistPermissionExample() {
     try {
       let uri = "file://docs/storage/Users/username/1.txt";
       let policyInfo: fileShare.PolicyInfo = {
         uri: uri,
         operationMode: fileShare.OperationMode.READ_MODE,
       };
       let policies: Array<fileShare.PolicyInfo> = [policyInfo];
       fileShare.persistPermission(policies).then(() => {
         console.info("persistPermission successfully");
       }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
         console.info("persistPermission failed with error message: " + err.message + ", error code: " + err.code);
         if (err.code == 13900001 && err.data) {
           console.log("error data : " + JSON.stringify(err.data));
         }
       });
       let fd = await fs.open(uri);
       await fs.close(fd);
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error('persistPermission failed with err: ' + JSON.stringify(err));
     }
   }
   ```

4. 应用按需对持久化授权后的路径取消授权，参数URI为第1步通过FilePicker选择的路径。

   以下示例代码演示了去除持久化授权URI的过程：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileShare } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   async function revokePermissionExample() {
     try {
       let uri = "file://docs/storage/Users/username/1.txt";
       let policyInfo: fileShare.PolicyInfo = {
         uri: uri,
         operationMode: fileShare.OperationMode.READ_MODE,
       };
       let policies: Array<fileShare.PolicyInfo> = [policyInfo];
       await fileShare.persistPermission(policy);
       fileShare.revokePermission(policies).then(() => {
         console.info("revokePermission successfully");
       }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
         console.info("revokePermission failed with error message: " + err.message + ", error code: " + err.code);
         if (err.code == 13900001 && err.data) {
           console.log("error data : " + JSON.stringify(err.data));
         }
       });
       let fd = await fs.open(uri);
       await fs.close(fd);
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error('revokePermission failed with err: ' + JSON.stringify(err));
     }
   }
   ```

5. 应用获得的持久化权限需要在重启后进行激活，应用重启后及访问URI之前首先检查对URI是否有持久化权限，有权限则激活已经持久化的授权URI，持久化授权的接口需要与激活持久化权限的接口配套使用。

   以下示例代码演示了应用激活持久化授权的过程，其中参数URI为应用重启后需要激活权限的路径：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileShare } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   async function activatePermissionExample01() {
     try {
       let uri = "file://docs/storage/Users/username/tmp.txt";
       let policyInfo: fileShare.PolicyInfo = {
         uri: uri,
         operationMode: fileShare.OperationMode.READ_MODE,
       };
       let policies: Array<fileShare.PolicyInfo> = [policyInfo];
       let results = await fileShare.checkPersistentPermission(policies);
       for (let i = 0; i < results.length; i++) {
         console.log("checkPersistentPermission result: " + JSON.stringify(results[i]));
         if (results[i]) {
           let info: fileShare.PolicyInfo = {
             uri: policies[i].uri,
             operationMode: policies[i].operationMode,
           };
           let policy: Array<fileShare.PolicyInfo> = [info];
           await fileShare.activatePermission(policy);
           console.info("activatePermission successfully");
         }
       }
       let fd = await fs.open(uri);
       await fs.close(fd);
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error('activatePermission failed with err: ' + JSON.stringify(err));
     }
   }
   ```

6. 应用可以按需取消激活的持久化权限能力，参数URI为应用重启后需要激活权限的路径。

   以下示例代码演示了取消激活持久化权限的过程：

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileShare } from '@kit.CoreFileKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   async function deactivatePermissionExample01() {
     try {
       let uri = "file://docs/storage/Users/username/tmp.txt";
       let policyInfo: fileShare.PolicyInfo = {
         uri: uri,
         operationMode: fileShare.OperationMode.READ_MODE,
       };
       let policies: Array<fileShare.PolicyInfo> = [policyInfo];
       await fileShare.activatePermission(policies);
       fileShare.deactivatePermission(policies).then(() => {
         console.info("deactivatePermission successfully");
       }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
         console.info("deactivatePermission failed with error message: " + err.message + ", error code: " + err.code);
         if (err.code == 13900001 && err.data) {
           console.log("error data : " + JSON.stringify(err.data));
         }
       });
       let fd = await fs.open(uri);
       await fs.close(fd);
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error('deactivatePermission failed with err: ' + JSON.stringify(err));
     }
   }
   ```

## 通过接口获取文件或文件夹当前所在路径的URI

如果当前FileUri指向文件，将返回文件所在路径URI，如果当前FileUri指向目录，将返回当前路径URI。通过文件URI接口（[ohos.file.fileuri](../reference/apis-core-file-kit/js-apis-file-fileuri.md)）获取文件或文件夹当前所在路径的URI。

以下示例代码演示了获取文件父目录过程：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

function getFullDirectoryUriExample01() {
  try {
    let uri = "file://docs/storage/Users/100/tmp/1.txt";
    let fileObject = new fileUri.FileUri(uri);
    let directoryUri = fileObject.getFullDirectoryUri();
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getFullDirectoryUri failed with err: ' + JSON.stringify(err));
  }
}
```

<!--Del-->
## 通过接口获取外卡目录

应用可以获得公共目录中的下载目录、桌面目录和文档目录，但获取外卡根目录和当前用户下应用沙箱路径的内卡目录仅对文件管理器应用开放，通过获取目录环境能力接口（[ohos.file.environment](../reference/apis-core-file-kit/js-apis-file-environment.md)）获取环境路径。

以下示例代码演示了文件管理器通过接口获取外卡目录、内卡目录：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { Environment } from '@kit.CoreFileKit';

function getDirectoryExample01() {
  try {
    //获取外卡根目录
    let externalStoragePath = Environment.getExternalStorageDir();
    //获取当前用户下应用沙箱路径的内卡目录
    let userHomePath = Environment.getUserHomeDir();
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getDirectory failed with err: ' + JSON.stringify(err));
  }
}
```
<!--DelEnd-->