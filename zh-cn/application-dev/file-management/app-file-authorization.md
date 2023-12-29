# 文件授权访问

提供给应用的文件授权访问场景主要分为：
1.权限申明授权方式获取公共目录访问权限；
2.通过FilePicker选择文件或目录授权并支持授权持久化；
3.通过接口获取文件或文件夹当前所在路径的URI；
4.通过接口获取公共目录、外卡目录的能力。

文件授权访问的场景仅支持部分设备。

## 开发示例

下面介绍几种常用操作示例。

### 通过授权的方式申请Download目录权限和获取对应路径

1.配置Download目录授权权限。

    “requestPermissions” : [
        "name": "ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY"
    ]

2.应用获取公共Download目录后可以访问操作目录，通过获取目录环境能力接口（[ohos.file.environment](../reference/apis/js-apis-file-environment.md)）获取环境路径。
  ```ts
  import { BusinessError } from '@ohos.base';
  import environment from '@ohos.file.environment';
  import fs from '@ohos.file.fs';
  
  async function getUserDownloadDirExample() {
    try {
      let path = environment.getUserDownloadDir();
      console.log(`success to getUserDownloadDir: ${JSON.stringify(path)}`);
      await fs.mkdir(path + "/brower");
      let fd = await fs.open(path + "/brower/1.txt", fs.OpenMode.CREATE);
      await fs.close(fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`failed to getUserDownloadDir because: ${JSON.stringify(err)}`);
    }
  }
  ```

### 通过FilePicker设置永久授权

通过FilePicker选择文件或文件夹后设置永久授权，以及应用重启后的激活权限过程如下所示，通过文件分享接口（[ohos.fileshare](../reference/apis/js-apis-fileShare.md)）实现文件授权能力。

1.应用调用picker的select接口，通过FilePicker选择和保存路径URI，此时应用获得该路径的临时访问权限。以下示例代码演示了获取文件夹URI的过程：

  ```ts
  import { BusinessError } from '@ohos.base';
  import picker from '@ohos.file.picker';
  
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

2.应用按需对路径设置持久化授权，参数uri为第一步FilePicker应用获取的选择路径。以下示例代码演示了持久化授权过程：
  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  import fs from '@ohos.file.fs';
  
  async function persistPermissionExample() {
    try {
      let uri = "file://docs/storage/Users/username/1.txt";
      let policyInfo: fileshare.PolicyInfo = {
        uri: uri,
        operationMode: fileshare.OperationMode.READ_MODE,
      };
      let policies: Array<fileshare.PolicyInfo> = [policyInfo];
      fileshare.persistPermission(policies).then(() => {
        console.info("persistPermission successfully");
      }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
        console.info("persistPermission failed with error message: " + err.message + ", error code: " + err.code);
        if (err.code == 13900001) {
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

3.应用按需对持久化授权后的路径取消授权，参数URI为第一步通过FilePicker选择的路径。以下示例代码演示了去除持久化授权URI的过程：
  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  import fs from '@ohos.file.fs';
  
  async function revokePermissionExample() {
    try {
      let uri = "file://docs/storage/Users/username/1.txt";
      let policyInfo: fileshare.PolicyInfo = {
        uri: uri,
        operationMode: fileshare.OperationMode.READ_MODE,
      };
      let policies: Array<fileshare.PolicyInfo> = [policyInfo];
      fileshare.revokePermission(policies).then(() => {
        console.info("revokePermission successfully");
      }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
        console.info("revokePermission failed with error message: " + err.message + ", error code: " + err.code);
        if (err.code == 13900001) {
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

4.应用支持的持久化能力需要在重启时激活已经持久化授权URI，持久化授权的接口需要与激活持久化权限的接口配套使用。

以下示例代码演示了应用重启时激活持久化授权的URI，其中参数URI为应用重启后读取的最近使用文件：
  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  import fs from '@ohos.file.fs';
  
  async function activatePermissionExample01() {
    try {
      let uri = "file://docs/storage/Users/username/tmp.txt";
      let policyInfo: fileshare.PolicyInfo = {
        uri: uri,
        operationMode: fileshare.OperationMode.READ_MODE,
      };
      let policies: Array<fileshare.PolicyInfo> = [policyInfo];
      fileshare.activatePermission(policies).then(() => {
        console.info("activatePermission successfully");
      }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
        console.info("activatePermission failed with error message: " + err.message + ", error code: " + err.code);
      });
      let fd = await fs.open(uri);
      await fs.close(fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('activatePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

5.应用可以按需取消激活的持久化权限能力，参数URI为应用重启后读取的最近使用文件。以下示例代码演示了取消激活持久化权限的过程：
  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  import fs from '@ohos.file.fs';
  
  async function deactivatePermissionExample01() {
    try {
      let uri = "file://docs/storage/Users/username/tmp.txt";
      let policyInfo: fileshare.PolicyInfo = {
        uri: uri,
        operationMode: fileshare.OperationMode.READ_MODE,
      };
      let policies: Array<fileshare.PolicyInfo> = [policyInfo];
      fileshare.deactivatePermission(policies).then(() => {
        console.info("deactivatePermission successfully");
      }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
        console.info("deactivatePermission failed with error message: " + err.message + ", error code: " + err.code);
      });
      let fd = await fs.open(uri);
      await fs.close(fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('deactivatePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

### 获取文件或文件夹当前所在路径的URI

如果当前FileUri指向文件，将返回文件所在路径URI，如果当前FileUri指向目录，将返回当前路径URI。通过文件URI接口（[ohos.file.fileuri](../reference/apis/js-apis-file-fileuri.md)）获取文件或文件夹当前所在路径的URI。
以下示例代码演示了获取文件父目录过程：
  ```ts
  import { BusinessError } from '@ohos.base';
  import fileUri from '@ohos.file.fileuri';
  
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

### 获取公共目录、外卡目录、内卡目录

应用可以获得公共目录中的下载目录、桌面目录和文档目录，但获取外卡根目录和当前用户下应用沙箱路径的内卡目录仅对文件管理器应用开放，通过获取目录环境能力接口（[ohos.file.environment](../reference/apis/js-apis-file-environment.md)）获取环境路径。
以下示例代码演示了文件管理器通过接口获取公共目录、外卡目录：
  ```ts
  import { BusinessError } from '@ohos.base';
  import environment from '@ohos.file.environment';
  
  function getDirectoryExample01() {
    try {
      //获取公共下载目录
      let downloadPath = environment.getUserDownloadDir();
      //获取公共桌面目录
      let desktopPath = environment.getUserDesktopDir();
      //获取公共文档目录
      let documentPath = environment.getUserDocumentDir();
      //获取外卡根目录
      let externalStoragePath = environment.getExternalStorageDir();
      //获取当前用户下应用沙箱路径的内卡目录
      let userHomePath = environment.getUserHomeDir();
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getDirectory failed with err: ' + JSON.stringify(err));
    }
  }
  ```