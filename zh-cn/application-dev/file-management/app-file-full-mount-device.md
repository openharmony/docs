# 全量挂载设备文件授权访问

全量挂载设备下提供给应用基于权限申明预授权的方式获取公共目录访问权限，通过filePicker选择文件或目录授权并支持授权持久化，通过接口获取文件或文件夹当前所在路径的URI、公共目录、外卡目录的能力，如下接口仅支持特定设备使用，下文介绍具体方法。

## 接口说明
开发者通过获取目录环境能力接口（[ohos.file.environment](../reference/apis/js-apis-file-environment.md)）实现获取环境路径能力，
通过文件分享接口（[ohos.fileshare](../reference/apis/js-apis-fileShare.md)）实现文件授予和使能权限能力，
通过文件URI接口（[ohos.file.fileuri](../reference/apis/js-apis-file-fileuri.md)）获取文件或文件夹当前所在路径的URI，主要功能如下表所示。

**表1** 获取用户目录环境能力接口

| 接口名                  | 功能          | 接口类型 | 支持同步 | 支持异步 | 公开级别      |
|----------------------|-------------| -------- | -------- |------|-----------|
| getUserDownloadDir   | 获取预授权下载目录路径 | 方法 | √ | -    | publicAPI | 
| getUserDesktopDir    | 获取预授权桌面目录路径 | 方法 | √ | -    | publicAPI | 
| getUserDocumentDir   | 获取预授权文档目录路径 | 方法 | √ | -    | publicAPI | 
| getUserHomeDir       | 获取当前用户下应用沙箱路径的内卡目录 | 方法 | √ | -    | systemAPI | 
| getExternalStorageDir | 获取外卡目录    | 方法 | √ | -    |     systemAPI      | 

**表2** 文件权限接口

| 接口名                       | 功能                | 接口类型 | 支持同步 | 支持异步 | 公开级别       |
|---------------------------|-------------------| -------- |------|------|------------|
| grantPermission               | 对所选择的文件或目录uri临时授权 | 方法 | -    | √    | systemAPI  | 
| persistPermission         | 对所选择的文件或目录uri持久化授权 | 方法 | -    | √    | publicAPI  | 
| revokePermission | 对所选择的文件或目录uri取消持久化授权 | 方法 | -    | √    | publicAPI  | 
| activatePermission      | 使能已经永久授权过的文件或目录   | 方法 | -    | √    | publicAPI  | 
| deactivatePermission    | 取消使能已经永久授权过的文件或目录 | 方法 | -    | √    | publicAPI  | 


**表3** 文件URI接口

| 接口名                 | 功能                                | 接口类型 | 支持同步 | 支持异步 | 公开级别      |
|---------------------|-----------------------------------| -------- | -------- |------|-----------|
| getFullDirectoryUri | 获取所在路径URI,文件获取所在路劲URI，目录获取当前路径URI | 方法 | √ | -    | publicAPI | 

## 开发示例

下面介绍几种常用操作示例。

### 【三方应用】通过预授权的方式申请Download目录权限和获取对应路径

第一步：配置Download目录预授权权限。

    “requestPermissions” : [
        "name": "ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY"
    ]

第二步：应用通过接口获取公共Download目录后可以访问操作目录。
```ts
import { BusinessError } from '@ohos.base';
import environment from '@ohos.file.environment';
import fs from '@ohos.file.fs';

async function getUserDownloadDirExample() {
  try {
    let path = environment.getUserDownloadDir();
    console.log(`success to getUserPublicDir: ${JSON.stringify(path)}`);
    await fs.mkdir(path + "/brower");
    let fd = await fs.open(path + "/brower/1.txt", fs.OpenMode.Create);
    await fs.close(fd);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`failed to getUserPublicDir because: ${JSON.stringify(err)}`);
  }
}
```

### 【FilePicker应用】通过FilePicker的方式选择文件或文件夹使能临时访问权限场景

应用拉起FilePicker应用，通过FilePicker应用选择文件或文件夹使能临时访问权限，以下示例代码演示了FilePicker开发者如何使能临时访问权限：

第一步：通过FilePicker选择和保存路径uri。

第二步：FilePicker对目录设置临时访问权限。
参数uri为FilePicker获取的选择路径，tokenId为拉起FilePicker应用的tokenId，由FilePicker获取。

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
import fileshare from '@ohos.fileshare';

async function grantPermissionExample01() {
  try {
    let uri = "file://docs/storage/Users/username/1.txt";
    let tokenId = 1000;
    let policyInfo: fileshare.PolicyInfo = {
      uri: uri,
      operationMode: fileshare.OperationMode.READ_MODE,
    };
    let policies: Array<fileshare.PolicyInfo> = [policyInfo];
    fileshare.grantPermission(tokenId, policies, fileshare.PolicyFlag.ALLOW_PERSISTENCE).then(() => {
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

### 【三方应用】通过FilePicker选择路径后设置永久授权，以及应用重启后的使能过程

应用如果需要对选择的路径获取永久授权，需要自己进行持久化授权。

第一步：应该调用picker的select接口，通过FilePicker选择和保存路径URI。以下示例代码演示了获取文件夹URI的过程：

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';

async function selectExample() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    DocumentSelectOptions.selectMode = picker.SelectMode.FOLDER;
    let documentPicker = new picker.DocumentViewPicker();
    let uris = await documentPicker.select(DocumentSelectOptions);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('select failed with err: ' + JSON.stringify(err));
  }
}
```

第二步：应用按需对路径设置持久化授权，参数uri为第一步FilePicker应用获取的选择路径。以下示例代码演示了持久化授权过程：
```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
import fileshare from '@ohos.fileshare';

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
    let fd = await fs.open(uris[0]);
    await fs.close(fd);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('persistPermission failed with err: ' + JSON.stringify(err));
  }
}
```

第三步：应用按需对持久化授权后的路径取消授权，参数URI为第一步通过FilePicker选择的路径。以下示例代码演示了去除持久化授权URI的过程：
```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
import fileshare from '@ohos.fileshare';

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
    let fd = await fs.open(uris[0]);
    await fs.close(fd);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('revokePermission failed with err: ' + JSON.stringify(err));
  }
}
```

第四步：应用支持的持久化能力需要在重启时使能已经持久化授权URI，持久化授权的接口需要与使能持久化权限的接口配套使用。

以下示例代码演示了应用重启时使能持久化授权的URI，其中参数URI为应用重启后读取的最近使用文件：
```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
import fileshare from '@ohos.fileshare';

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

第五步：应用可以按需取消使能的持久化权限能力，参数URI为应用重启后读取的最近使用文件。以下示例代码演示了取消使能持久化权限的过程：
```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
import fileshare from '@ohos.fileshare';

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

### 【文件管理器】通过接口获取文件或文件夹当前所在路径的URI

如果当前FileUri指向文件，将返回文件所在路径URI，如果当前FileUri指向目录，将返回当前路径URI。
以下示例代码演示了文件管理器通过接口获取文件父目录：
```ts
import { BusinessError } from '@ohos.base';
import fileuri from '@ohos.file.fileuri';

function getFullDirectoryUriExample01() {
  try {
    let uri = "file://docs/storage/Users/100/tmp/1.txt";
    let fileObject = new fileuri.FileUri(uri);
    let directoryUri = fileObject.getFullDirectoryUri();
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getFullDirectoryUri failed with err: ' + JSON.stringify(err));
  }
}
```

### 【文件管理器】通过接口获取公共目录、外卡目录

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
    let doucmentPath = environment.getUserDoucmentDir();
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