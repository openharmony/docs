# 全量挂载设备文件授权访问

全量挂载设备文件授权访问支持目录授权、文件管理APP访问应用沙箱能力，如下接口仅支持特定设备使用，下文介绍具体方法。

## 接口说明
开发者通过获取目录环境能力接口（[ohos.file.environment](../reference/apis/js-apis-file-environment.md)）实现获取环境路径能力，
通过文件URI接口（[ohos.file.fileshare](../reference/apis/js-apis-file-fileShare.md)）实现文件授予和使能权限能力，主要功能如下表所示。

**表1** 获取用户目录环境能力接口

| 接口名 | 功能              | 接口类型 | 支持同步 | 支持异步 | 
| -------- |-----------------| -------- | -------- |------|
| getUserDownloadDir | 获取当前用户预授权下载目录路径 | 方法 | √ | -    | 
| getUserDesktopDir | 获取当前用户预授权桌面目录路径 | 方法 | √ | -    |
| getUserDocumentsDir | 获取当前用户预授权文档目录路径 | 方法 | √ | -    |
| getUserHomeDir | 获取当前用户下应用沙箱路径的内卡目录 | 方法 | √ | -    | 
| getExternalUsbDir | 获取外卡根目录路径    | 方法 | √ | -    | 

**表2** 文件权限接口

| 接口名                       | 功能                   | 接口类型 | 支持同步 | 支持异步 | 
|---------------------------|----------------------| -------- |------|------|
| grantPermission               | 对所选择的文件或目录uri临时授权    | 方法 | -    | √    | 
| persistPermission         | 对所选择的文件或目录uri持久化授权   | 方法 | -    | √    | 
| revokePermission | 对所选择的文件或目录uri取消持久化授权 | 方法 | -    | √    | 
| activatePermission      | 使能某个已经永久授权过的文件或目录    | 方法 | -    | √    | 
| deactivatePermission    | 取消使能某个已经永久授权过的文件或目录  | 方法 | -    | √    |


**表3** 文件URI接口

| 接口名                 | 功能                                | 接口类型 | 支持同步 | 支持异步 | 
|---------------------|-----------------------------------| -------- | -------- |------|
| getFullDirectoryUri | 获取所在路径URI,文件获取所在路劲URI，目录获取当前路径URI | 方法 | √ | -    |

## 开发示例

在对应用文件开始访问前，开发者需要[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)。以从UIAbilityContext获取HAP级别的文件路径为例进行说明，UIAbilityContext的获取方式请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

下面介绍几种常用操作示例。

### 通过预授权的方式申请下载目录权限和获取对应路径

第一步：配置下载目录预授权权限

    “requestPermissions” : [
        "name": "ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY"
    ]

第二步：应用安装时，默认配置默认的公共目录Download。
第三步：文件下载、打开fs接口
```ts
import { BusinessError } from '@ohos.base';
import environment from '@ohos.file.environment';
import fs from '@ohos.file.fs';
async function getUserDownloadDirExample(){
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

### FilePicker选择目录设置永久授权，以及应用重启后的使能过程

第一步：应用按需持久化授权，取消持久化授权同理
```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
import fileshare from '@ohos.fileshare';

async function persistPermissionExample(): void {
    try {
        let DocumentSelectOptions = new picker.DocumentSelectOptions();
        let documentPicker = new picker.DocumentViewPicker();
        let uris = await documentPicker.select(DocumentSelectOptions);
        let policyInfo: fileshare.PolicyInfo = {
            uri: uris[0],
            operationMode: fileshare.OperationMode.READ_MODE,
        };
        let policies: Array<fileshare.PolicyInfo> = [policyInfo];
        fileshare.persistPermission(policies).then(() => {
            console.info("persistPermission successfully");
        }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
            console.info("persistPermission failed with error message: " + err.message + ", error code: " + err.code);
            if(err.code == 13900001){
                console.log("error code : " + JSON.stringify(err.data[0].code));
                console.log("error uri : " + JSON.stringify(err.data[0].uri));
                console.log("error reason : " + JSON.stringify(err.data[0].message));
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

第二步：应用再次启动后，提前使能自己保存的永久URI，取消使能同理，uri为应用重启后读取的最近使用文件。
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

### FilePicker开发者使能临时访问权限

以下示例代码演示了FilePicker开发者如何使能临时访问权限：
uri为filepicker应用获取的选择路径，tokenId为拉起filepicker应用的tokenid。

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
import bundleManager from '@ohos.bundle.bundleManager';
import fileshare from '@ohos.fileshare';

async function grantPermissionExample01() {
    try {
        let uri = "file://docs/storage/Users/username/1.txt";
        let bundleName = 'com.example.myapplication';
        let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;
        let applicationInfo = await bundleManager.getApplicationInfo(bundleName, appFlags);
        let tokenId = applicationInfo.accessTokenId;
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

### 文件管理器通过接口获取文件父目录

如果当前FileUri指向文件，将返回文件所在路径URI,如果当前FileUri指向目录，将返回当前路径URI。
以下示例代码演示了文件管理器通过接口获取文件父目录：
```ts
import { BusinessError } from '@ohos.base';
import fileuri from '@ohos.file.fileuri';

async function getFullDirectoryUriExample01() {
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

### 文件管理器通过接口获取公共目录、外卡目录

以下示例代码演示了文件管理器通过接口获取公共目录、外卡目录：
```ts
import { BusinessError } from '@ohos.base';
import environment from '@ohos.file.environment';

async function getDirectoryExample01() {
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
}
```