# @ohos.data.fileAccess (公共文件访问与管理)

fileAccess模块是基于extension机制实现的一个对公共文件访问和操作的框架。该模块一方面对接各类文件管理服务，如媒体库、外置存储管理服务等，另一方面为系统应用提供一套统一的文件访问管理接口。其中，媒体库服务提供本地设备、分布式设备等公共文件访问服务；外置存储管理服务可以提供共享盘、U盘、SD卡等设备的公共文件访问服务。

>**说明：**
>
>- 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>- 本模块接口为系统接口，三方应用不支持调用，当前只支持filepicker、文件管理器调用。

## 导入模块

```js
import fileAccess from '@ohos.data.fileAccess';
```

## fileAccess.getFileAccessAbilityInfo

getFileAccessAbilityInfo( ) : Promise&lt;Array&lt;Want&gt;&gt;

以异步方法获取系统内extension配置为fileAcesss类型的所有Want信息。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | Promise&lt;Array&lt;Want&gt;&gt; | 表示当前系统配置fileAccess的所有文件管理类服务 |

**示例：**

  ```js
  async getFileAccessAbilityInfo() {
    let wantInfos = [];
    try {
      wantInfos = await fileAccess.getFileAccessAbilityInfo();
      console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));
    } catch (error) {
      console.error("getFileAccessAbilityInfo failed, error " + error);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context, wants: Array&lt;Want&gt;) : FileAccessHelper

以同步方法创建连接指定wants的helper对象。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | context | Context | 是 | 代表ability的上下文的能力 |
  | wants | Array&lt;Want&gt; | 是 | Want是一种基本通信组件，主要用于服务拉起 |

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | FileAccessHelper | 提供文件访问和操作能力的helper对象 |

**示例：**

  ```js
  createFileAccessHelper() {
    let fileAccesssHelper = null;
    // wantInfos 从getFileAccessAbilityInfo()获取
    // 创建只连接媒体库服务的helper对象
    let wantInfos = [
      {
        "bundleName": "com.ohos.medialibrary.medialibrarydata",
        "abilityName": "FileExtensionAbility",
      },
    ]
    try {
      // this.context 是MainAbility 传过来的context
      fileAccesssHelper = fileAccess.createFileAccessHelper(this.context, wantInfos);
      if (!fileAccesssHelper)
        console.error("createFileAccessHelper interface returns an undefined object");
    } catch (error) {
      console.error("createFileAccessHelper failed, error " + error);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context) : FileAccessHelper

以同步方法创建连接当前系统内所有文件管理服务的helper对象。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | context | Context | 是 | ability的上下文的能力 |

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | FileAccessHelper | 提供文件访问和操作的能力的helper对象 |

**示例：**

  ```js
  createFileAccessHelper() {
    let fileAccesssHelperAllServer = null;
    // 创建连接系统内所有配置fileAccess的文件管理类服务的helper对象
    try {
      // this.context 是MainAbility 传过来的context
      fileAccesssHelperAllServer = fileAccess.createFileAccessHelper(this.context);
      if (!fileAccesssHelperAllServer)
        console.error("createFileAccessHelper interface returns an undefined object");
    } catch (error) {
      console.error("createFileAccessHelper failed, error " + error);
    }
  }
  ```

## FileAccessHelper.getRoots

getRoots( ) : Promise&lt;RootIterator&gt;

以异步方法获取helper对象连接的文件管理服务类的设备根节点信息。使用Promise异步回调。
该方法返回迭代器对象RootIterator，然后通过[next](#rootiteratornext)方法返回[RootInfo](#rootinfo)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | Promise&lt;RootIterator&gt; | 根设备目录信息组成迭代器对象 |

**示例：**

  ```js
  async getRoots() {
    let rootIterator = null;
    let rootinfos = [];
    let isDone = false;
    try {
      rootIterator = await fileAccessHelper.getRoots();
      if (!rootIterator) {
        console.error("getRoots interface returns an undefined object");
        return;
      }
      while (!isDone) {
        let result = rootIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone)
          rootinfos.push(result.value);
      }
    } catch (error) {
      console.error("getRoots failed, error " + error);
    }
  }
  ```

## RootInfo.listfile

listFile(filter?: Filter) : FileIterator

以同步方法从某设备根节点开始，基于过滤器，获取第一级符合条件的文件(夹)信息的迭代器对象FileIterator，然后通过[next](#fileiteratornext)方法返回[FileInfo](#fileinfo)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | -- | -- |
  | filter | Filter | 否 | 过滤器对象  |


**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | FileIterator | 文件(夹)信息的迭代器对象FileIterator |

**示例：**

  ```js
  // rootinfos 从getRoots()获取
  // let filter = {suffix : [".txt"， ".jpg", ".xlsx"]};
  let rootInfo = rootinfos[0];
  let fileInfos = [];
  let isDone = false;
  try {
    let fileIterator = rootInfo.listFile();
    // 含过滤器实现的listFile
    // let fileIterator = rootInfo.listFile(filter);
    if (!fileIterator) {
      console.error("listFile interface returns an undefined object");
      return;
    }
    while (!isDone) {
      let result = fileIterator.next();
      console.log("next result = " + JSON.stringify(result));
      isDone = result.done;
      if (!isDone)
        fileInfos.push(result.value);
    }
  } catch (error) {
    console.log("listFile failed, error " + error);
  }
  ```

## RootInfo.scanFile

scanFile(filter?: Filter) : FileIterator

以同步方法从某设备根节点开始，基于过滤器，递归获取符合条件的文件信息的迭代器对象FileIterator，然后通过[next](#fileiteratornext)方法返回[FileInfo](#fileinfo)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | -- | -- |
  | filter | Filter | 否 | 过滤器对象  |

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | FileIterator | 文件信息的迭代器对象FileIterator |

**示例：**

  ```js
  // rootinfos 从 getRoots()获取
  // let filter = {suffix : [".txt"， ".jpg", ".xlsx"]};
  let rootInfo = rootinfos[0];
  let fileInfos = [];
  let isDone = false;
  try {
      let fileIterator = rootInfo.scanFile();
      // 含过滤器实现的scanFile
      // let fileIterator = rootInfo.scanFile(filter);
      if (!fileIterator) {
        console.error("scanFile interface returns undefined object");
        return;
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone)
          fileInfos.push(result.value);
      }
  } catch (error) {
    console.error("scanFile failed, error " + error);
  }
  ```

## FileInfo.listfile

listFile(filter?: Filter) : FileIterator

以同步方法从某个目录，基于过滤器，获取下一级符合条件的文件(夹)信息的迭代器对象FileIterator，然后通过[next](#fileiteratornext)方法返回[FileInfo](#fileinfo)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | -- | -- |
  | filter | Filter | 否 | 过滤器对象  |

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | FileIterator | 文件(夹)信息的迭代器对象FileIterator |

**示例：**

  ```js
  // fileInfoDir 表示某个目录信息
  // let filter = { suffix : [".txt"， ".jpg", ".xlsx"] };
  let fileInfoDir = fileInfos[0];
  let subfileInfos = [];
  let isDone = false;
  try {
    let fileIterator = fileInfoDir.listFile();
    // 含过滤器实现的listFile
    // let fileIterator = rootInfo.listFile(filter);
    if (!fileIterator) {
      console.error("listFile interface returns an undefined object");
      return;
    }
    while (!isDone) {
      let result = fileIterator.next();
      console.log("next result = " + JSON.stringify(result));
      isDone = result.done;
      if (!isDone)
        subfileInfos.push(result.value);
    }
  } catch (error) {
    console.error("listFile failed, error " + error);
  }
  ```

## FileInfo.scanfile

scanFile(filter?: Filter) : FileIterator;

以同步方法从某个目录，基于过滤器，递归获取符合条件的文件信息的迭代器对象FileIterator，然后通过[next](#fileiteratornext)方法返回[FileInfo](#fileinfo)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | -- | -- |
  | filter | Filter | 否 | 过滤器对象  |


**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | FileIterator | 文件信息的迭代器对象FileIterator |

**示例：**

  ```js
  // fileInfoDir 表示某个目录信息
  // let filter = {suffix : [".txt"， ".jpg", ".xlsx"]};
  let fileInfoDir = fileInfos[0];
  let subfileInfos = [];
  let isDone = false;
  try {
    let fileIterator = fileInfoDir.scanFile();
    // 含过滤器实现的scanFile
    // let fileIterator = rootInfo.scanFile(filter);
    if (!fileIterator) {
      console.error("scanFile interface returns an undefined object");
      return;
    }
    while (!isDone) {
      let result = fileIterator.next();
      console.error("next result = " + JSON.stringify(result));
      isDone = result.done;
      if (!isDone)
        subfileInfos.push(result.value);
    }
  } catch (error) {
    console.error("scanFile-filter failed, error " + error);
  }
  ```

## FileAccessHelper.createFile

createFile(uri: string, displayName: string) : Promise&lt;string&gt;

以异步方法创建文件到指定目录，返回新文件uri。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | uri | string | 是 | 表示需要创建文件的父目录的Uri |
  | displayName | string | 是 | 待创建文件的名称，本地文件需要添加后缀，共享盘不要求|

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;string&gt; | 新创建的文件的uri |

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri = "datashare:///media/file/6";
  let displayName = "file1"
  let fileUri = null;
  try {
    fileUri = await fileAccessHelper.createFile(sourceUri, displayName)
    if (!fileUri) {
      console.error("createFile return undefined object");
      return;
    }
    console.log("createFile sucess， fileUri: " + JSON.stringify(fileUri));
  } catch (error) {
    console.error("createFile failed, error " + error);
  };
  ```

## FileAccessHelper.mkDir

mkDir(parentUri: string, displayName: string) : Promise&lt;string&gt;

以异步方法创建文件夹到指定目录，返回文件夹uri。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | parentUri | string | 是 | 表示需要创建文件夹的父目录的Uri |
  | displayName | string | 是 | 待创建文件夹的名称|

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;string&gt; | 新创建的文件夹的uri |

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri = "datashare:///media/file/6";
  let dirName = "dirTest"
  let dirUri = null;
  try {
    dirUri = await fileAccessHelper.mkDir(sourceUri, dirName)
    if (!dirUri) {
      console.error("mkDir return undefined object");
      return;
    }
    console.log("mkDir sucess， dirUri: " + JSON.stringify(dirUri));
  } catch (error) {
    console.error("mkDir failed, error " + error);
  };
  ```

## FileAccessHelper.openFile

openFile(uri: string, flags: OPENFLAGS) : Promise&lt;number&gt;

以异步方法打开文件，返回文件句柄。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | uri | string | 是 | 待打开文件的uri |
  | flags | [OPENFLAGS](#openflags) | 是 | 文件打开的标志 |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;number&gt | 文件句柄 |

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let targetUri  = "datashare:///media/file/100";
  try {
    let fd = await fileAccessHelper.openFile(targetUri, OPENFLAGS.READ);
  } catch (error) {
    console.error("openFile failed, error " + error);
  };
  ```

## FileAccessHelper.delete

delete(uri: string) : Promise&lt;number&gt;

以异步方法删除文件(夹)，返回错误码。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | uri | string | 是 | 待删除文件(夹)的uri |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;number&gt | 删除操作的错误码 |

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let targetUri = "datashare:///media/file/100";
  try {
    let code = await fileAccessHelper.delete(targetUri);
    if (code != 0)
      console.error("delete failed, code " + code);
  } catch (error) {
    console.error("delete failed, error " + error);
  };
  ```

## FileAccessHelper.move

move(sourceFile: string, destFile: string) : Promise&lt;string&gt;

以异步方法移动文件(夹)，返回移动后文件(夹)的uri。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | sourceFile | string | 是 | 待移动的源文件(夹)的uri |
  | destFile | string | 是 | 目标文件夹的uri |

**返回值：**

| 类型 | 说明 |
| ----- | ------ |
| Promise&lt;string&gt; | 新路径下的文件(夹)的uri |

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceFile destFile表示Download目录下文件或文件夹，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceFile = "datashare:///media/file/102";
  let destFile = "datashare:///media/file/101";
  try {
    let fileUri = await fileAccessHelper.move(sourceFile, destFile);
    console.log("move sucess， fileUri: " + JSON.stringify(fileUri));
  } catch (error) {
    console.error("move failed, error " + error);
  };
  ```

## FileAccessHelper.rename

rename(uri: string, displayName: string) : Promise&lt;string&gt;

以异步方法重命名文件(夹)，返回重命名后的文件(夹)的Uri。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | uri | string | 是 | 源文件(夹)的uri |
  | displayName | string | 是 | 文件(夹)名，支持带后缀 |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;string&gt; | 重命名后的文件(夹)的uri |

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceDir = "datashare:///media/file/100";
  try {
    let DestDir = await fileAccessHelper.rename(sourceDir, "testDir");
    console.log("rename sucess， DestDir: " + JSON.stringify(DestDir));
  } catch (error) {
    console.error("rename failed, error " + error);
  };
  ```

## FileAccessHelper.access

access(sourceFileUri: string) : Promise&lt;boolean&gt;

以异步方法判断文件(夹)是否存在。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | sourceFileUri | string | 是 | 文件(夹)的uri |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;boolean&gt; | 文件(夹)是否存在 |

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceDir = "datashare:///media/file/100";
  try {
    let existJudgment = await fileAccessHelper.access(sourceDir);
    if (existJudgment)
      console.log("sourceDir exists");
    else
      console.log("sourceDir does not exist");
  } catch (error) {
    console.error("rename failed, error " + error);
  };
  ```

## RootIterator.next

next( ) : { value: RootInfo, done: boolean }

RootIterator表示设备根目录的迭代器对象，可以通过next同步方法获取下一级设备根目录。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**返回值：**

| 类型 | 说明 |
| --- | -- |
| {value: RootInfo, done: boolean} | 通过next遍历文件夹，直到done返回true结束；value字段返回rootInfo。|

## FileIterator.next

next( ) : { value: FileInfo, done: boolean }

FileIterator表示文件夹的迭代器对象，可以通过next同步方法获取下一级文件(夹)信息。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**返回值：**

| 类型 | 说明 |
| --- | -- |
| {value: FileInfo, done: boolean} | 通过next遍历文件夹，直到done返回true结束；value字段返回fileInfo。|

## RootInfo

表示设备的根属性信息和接口能力。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### 属性

| 名称 | 类型   | 可读 | 可写 | 说明     |
| ------ | ------ | -------- | ------ | -------- |
| deviceType | number | 是 | 否 |设备类型 |
| uri | string | 是 | 否 | 设备根目录Uri |
| displayName | string | 是 | 否 | 设备名称 |
| deviceFlags | number | 是 | 否 | 设备支持的能力 |

## FileInfo

表示文件(夹)属性信息和接口能力。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### 属性

| 名称 | 类型   | 可读 | 可写 | 说明     |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | 是 | 否 | 文件(夹)的uri |
| fileName | string | 是 | 否 | 文件(夹)的名称 |
| mode | number | 是 | 否 | 文件(夹)的权限信息 |
| size | number | 是 | 否 |  文件(夹)的大小 |
| mtime | number | 是 | 否 |  文件(夹)的修改时间 |
| mimeType | string | 是 | 否 |  文件(夹)的媒体资源类型 |

## OPENFLAGS

目前支持的文件打开的标志位。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称 | 值 | 说明 |
| ----- | ------ | ------ |
| READ | 0o0 | 读模式。 |
| WRITE | 0o1 | 写模式。 |
| WRITE_READ | 0o2 | 读写模式。 |
