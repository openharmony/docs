# @ohos.file.fileAccess (公共文件访问与管理)(系统接口)

fileAccess模块是基于[extension](../../application-models/extensionability-overview.md)机制实现的一个对公共文件访问和操作的框架。该模块一方面对接各类文件管理服务，如存储管理服务等，另一方面为系统应用提供一套统一的文件访问管理接口。存储管理服务可以管理内置存储部分目录，以及共享盘、U盘、SD卡等设备上的资源。

>**说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。
> - 当前只支持FilePicker、文件管理器调用。

## 导入模块

```ts
import fileAccess from '@ohos.file.fileAccess';
```

## 常量

表示用于监听设备上线和下线通知的URI，用作注册监听的URI。

**模型约束**：仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

| 名称 | 类型                        | 只读 | 可写 | 说明                                                      |
| ---- | --------------------------- | ---- | ---- | --------------------------------------------------------- |
| DEVICES_URI<sup>11+</sup>  | string | 是   | 否   | 监听设备上线，下线通知，作为注册监听的URI                    |

## fileAccess.getFileAccessAbilityInfo

getFileAccessAbilityInfo() : Promise&lt;Array&lt;Want&gt;&gt;

以异步方法获取系统内extension配置为fileAccess类型的所有Want信息。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;Array&lt;[Want](../apis-ability-kit/js-apis-app-ability-want.md)&gt;&gt; | 表示当前系统配置fileAccess的所有文件管理类服务 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import Want from '@ohos.app.ability.Want';
  async function getFileAccessAbilityInfo() {
    let wantInfos: Array<Want> = [];
    try {
      wantInfos = await fileAccess.getFileAccessAbilityInfo();
      console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getFileAccessAbilityInfo failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

## fileAccess.getFileAccessAbilityInfo

getFileAccessAbilityInfo(callback: AsyncCallback&lt;Array&lt;Want&gt;&gt;): void

以异步方法获取系统内extension配置为fileAccess类型的所有Want信息。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| callback | AsyncCallback&lt;Array&lt;[Want](../apis-ability-kit/js-apis-app-ability-want.md)&gt;&gt; | 是 | 表示当前系统配置fileAccess的所有文件管理类服务 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import Want from '@ohos.app.ability.Want';
  async function getFileAccessAbilityInfo() {
    try {
      fileAccess.getFileAccessAbilityInfo((err: BusinessError, wantInfos: Array<Want>) => {
        if (err) {
          console.error("Failed to getFileAccessAbilityInfo in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));
      });
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getFileAccessAbilityInfo failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context, wants: Array&lt;Want&gt;) : FileAccessHelper

以同步方法创建连接指定wants的helper对象。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是 | 代表ability的上下文的能力 |
| wants | Array&lt;[Want](../apis-ability-kit/js-apis-app-ability-want.md)&gt; | 是 | Want是一种基本通信组件，主要用于服务拉起 |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| [FileAccessHelper](#fileaccesshelper) | 提供文件访问和操作能力的helper对象 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import Want from '@ohos.app.ability.Want';
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext;
  function createFileAccessHelper01() {
    let fileAccessHelper: fileAccess.FileAccessHelper;
    // wantInfos 从getFileAccessAbilityInfo()获取
    let wantInfos: Array<Want> = [
      {
        bundleName: "com.ohos.UserFile.ExternalFileManager",
        abilityName: "FileExtensionAbility",
      },
    ]
    try {
      // context 是EntryAbility 传过来的context
      fileAccessHelper = fileAccess.createFileAccessHelper(context, wantInfos);
      if (!fileAccessHelper) {
        console.error("createFileAccessHelper interface returns an undefined object");
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context) : FileAccessHelper

以同步方法创建连接当前系统内所有文件管理服务的helper对象。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是 | ability的上下文的能力 |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| [FileAccessHelper](#fileaccesshelper) | 提供文件访问和操作的能力的helper对象 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext;
  function createFileAccessHelper02() {
    let fileAccessHelperAllServer: fileAccess.FileAccessHelper;
    // 创建连接系统内所有配置fileAccess的文件管理类服务的helper对象
    try {
      // context 是EntryAbility 传过来的context
      fileAccessHelperAllServer = fileAccess.createFileAccessHelper(context);
      if (!fileAccessHelperAllServer) {
        console.error("createFileAccessHelper interface returns an undefined object");
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

## FileInfo

表示文件(夹)属性信息和接口能力。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### 属性

| 名称 | 类型   | 只读 | 可写 | 说明     |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | 是 | 否 | 文件(夹)的uri |
| relativePath<sup>10+</sup> | string | 是 | 否 | 文件(夹)的相对路径 |
| fileName | string | 是 | 否 | 文件(夹)的名称 |
| mode | number | 是 | 否 | 文件(夹)的权限信息 |
| size | number | 是 | 否 |  文件(夹)的大小 |
| mtime | number | 是 | 否 |  文件(夹)的修改时间 |
| mimeType | string | 是 | 否 |  文件(夹)的媒体资源类型 |

### listFile

listFile(filter?: Filter) : FileIterator

以同步方法从某个目录，基于过滤器，获取下一级符合条件的文件(夹)信息的迭代器对象FileIterator，然后通过[next](#next)方法返回[FileInfo](#fileinfo)。目前仅支持内置存储设备过滤，外置存储设备不支持过滤。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | -- | -- |
| filter | [Filter](js-apis-file-fs.md#filter) | 否 | 过滤器对象  |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| [FileIterator](#fileiterator) | 文件(夹)信息的迭代器对象FileIterator |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // fileInfoDir 表示某个目录信息
  // let filter = { suffix : [".txt", ".jpg", ".xlsx"] };
  let fileInfoDir :Array<fileAccess.FileInfo> = [];
  let subfileInfos: Array<fileAccess.FileInfo> = [];
  let isDone: boolean = false;
  try {
    for (let i = 0; i < fileInfoDir.length; ++i) {
      let fileIterator = fileInfoDir[i].listFile();
      // 含过滤器实现的listFile
      // let fileIterator = fileInfoDir.listFile(filter);
      if (!fileIterator) {
        console.error("listFile interface returns an undefined object");
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          subfileInfos.push(result.value);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### scanFile

scanFile(filter?: Filter) : FileIterator;

以同步方法从某个目录，基于过滤器，递归获取符合条件的文件信息的迭代器对象FileIterator，然后通过[next](#next)方法返回[FileInfo](#fileinfo)。目前仅支持内置存储设备。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | -- | -- |
| filter | [Filter](js-apis-file-fs.md#filter) | 否 | 过滤器对象  |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| [FileIterator](#fileiterator) | 文件信息的迭代器对象FileIterator |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // fileInfoDir 表示某个目录信息
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let fileInfoDir: Array<fileAccess.FileInfo> = [];
  let subfileInfos: Array<fileAccess.FileInfo> = [];
  let isDone: boolean = false;
  try {
    for (let i = 0; i < fileInfoDir.length; ++i) {
      let fileIterator = fileInfoDir[i].scanFile();
      // 含过滤器实现的scanFile
      // let fileIterator = fileInfoDir.scanFile(filter);
      if (!fileIterator) {
        console.error("scanFile interface returns an undefined object");
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          subfileInfos.push(result.value);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("scanFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

## FileIterator

表示文件夹的迭代器对象。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### next

next() : { value: FileInfo, done: boolean }

可以通过next同步方法获取下一级文件(夹)信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**返回值：**

| 类型 | 说明 |
| --- | -- |
| {value: [FileInfo](#fileinfo), done: boolean} | 通过next遍历文件夹，直到done返回true结束；value字段返回fileInfo。|

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

## RootInfo

表示设备的根属性信息和接口能力。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### 属性

| 名称 | 类型   | 只读 | 可写 | 说明     |
| ------ | ------ | -------- | ------ | -------- |
| deviceType | number | 是 | 否 |设备类型 |
| uri | string | 是 | 否 | 设备根目录Uri |
| relativePath<sup>10+</sup> | string | 是 | 否 | 根目录的相对路径 |
| displayName | string | 是 | 否 | 设备名称 |
| deviceFlags | number | 是 | 否 | 设备支持的能力 |

### listFile

listFile(filter?: Filter) : FileIterator

以同步方法从某设备根节点开始，基于过滤器，获取第一级符合条件的文件(夹)信息的迭代器对象FileIterator，然后通过[next](#next)方法返回[FileInfo](#fileinfo)。目前仅支持内置存储设备过滤，外置存储设备不支持过滤。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | -- | -- |
| filter | [Filter](js-apis-file-fs.md#filter) | 否 | 过滤器对象  |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| [FileIterator](#fileiterator) | 文件(夹)信息的迭代器对象FileIterator |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // rootInfo 从getRoots()获取
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo: Array<fileAccess.FileInfo> = [];
  let fileInfos: Array<fileAccess.FileInfo> = [];
  let isDone: boolean = false;
  try {
    for (let i = 0; i < rootInfo.length; ++i) {
      let fileIterator = rootInfo[i].listFile();
      // 含过滤器实现的listFile
      // let fileIterator = rootInfo.listFile(filter);
      if (!fileIterator) {
        console.error("listFile interface returns an undefined object");
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          fileInfos.push(result.value);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### scanFile

scanFile(filter?: Filter) : FileIterator

以同步方法从某设备根节点开始，基于过滤器，递归获取符合条件的文件信息的迭代器对象FileIterator，然后通过[next](#next)方法返回[FileInfo](#fileinfo)。目前仅支持内置存储设备。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | -- | -- |
| filter | [Filter](js-apis-file-fs.md#filter) | 否 | 过滤器对象  |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| [FileIterator](#fileiterator) | 文件信息的迭代器对象FileIterator |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // rootInfo 从 getRoots()获取
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo: Array<fileAccess.FileInfo> = [];
  let fileInfos: Array<fileAccess.FileInfo> = [];
  let isDone: boolean = false;
  try {
    for (let i = 0; i < rootInfo.length; ++i) {
      let fileIterator = rootInfo[i].scanFile();
      // 含过滤器实现的scanFile
      // let fileIterator = rootInfo.scanFile(filter);
      if (!fileIterator) {
        console.error("scanFile interface returns undefined object");
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          fileInfos.push(result.value);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("scanFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

## RootIterator

表示设备根目录的迭代器对象。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### next

next() : { value: RootInfo, done: boolean }

通过next同步方法获取下一级设备根目录。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**返回值：**

| 类型 | 说明 |
| --- | -- |
| {value: [RootInfo](#rootinfo), done: boolean} | 通过next遍历文件夹，直到done返回true结束；value字段返回rootInfo。|

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

## FileAccessHelper

FileAccessHelper对象。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### getRoots

getRoots() : Promise&lt;RootIterator&gt;

以异步方法获取helper对象连接的文件管理服务类的设备根节点信息。使用Promise异步回调。
该方法返回迭代器对象RootIterator，然后通过[next](#next-1)方法返回[RootInfo](#rootinfo)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;[RootIterator](#rootiterator)&gt; | 根设备目录信息组成迭代器对象 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
async function getRoots() {
  let rootIterator: fileAccess.RootIterator;
  let rootinfos: Array<fileAccess.RootInfo> = [];
  let isDone: boolean = false;
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      rootIterator = await fileAccessHelper.getRoots();
      if (!rootIterator) {
        console.error("getRoots interface returns an undefined object");
      }
      while (!isDone) {
        let result = rootIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          rootinfos.push(result.value);
        }
      }     
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
  ```

### getRoots

getRoots(callback:AsyncCallback&lt;RootIterator&gt;) : void

以异步方法获取helper对象连接的文件管理服务类的设备根节点信息。使用callback异步回调。
callback带回迭代器对象RootIterator，然后通过[next](#next-1)方法返回[RootInfo](#rootinfo)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| callback | AsyncCallback&lt;[RootIterator](#rootiterator)&gt; | 是 | 根设备目录信息组成迭代器对象 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function getRoots() {
    let rootinfos: Array<fileAccess.RootInfo> = [];
    let isDone: boolean = false;
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        fileAccessHelper.getRoots((err: BusinessError, rootIterator: fileAccess.RootIterator) => {
          if (err) {
            console.error("Failed to getRoots in async, errCode:" + err.code + ", errMessage:" + err.message);
          }
          while (!isDone) {
            let result = rootIterator.next();
            console.log("next result = " + JSON.stringify(result));
            isDone = result.done;
            if (!isDone) {
              rootinfos.push(result.value);
            }
          }
        });       
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### createFile

createFile(uri: string, displayName: string) : Promise&lt;string&gt;

以异步方法创建文件到指定目录，返回新文件uri。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 表示需要创建文件的父目录的Uri |
| displayName | string | 是 | 待创建文件的名称，默认本地文件需要添加后缀 |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;string&gt; | 新创建的文件的uri |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function createFile() {
    // 以内置存储目录为例
    // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
    // 开发者应根据自己实际获取的uri进行开发
    let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
    let displayName: string = "file1";
    let fileUri: string;
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
        if (fileAccessHelper != undefined) {
        fileUri = await fileAccessHelper.createFile(sourceUri, displayName);
        if (!fileUri) {
          console.error("createFile return undefined object");
          return;
        }
        console.log("createFile sucess, fileUri: " + JSON.stringify(fileUri));       
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### createFile

createFile(uri: string, displayName: string, callback: AsyncCallback&lt;string&gt;) : void

以异步方法创建文件到指定目录，返回新文件uri。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 表示需要创建文件的父目录的Uri |
| displayName | string | 是 | 待创建文件的名称，默认本地文件需要添加后缀 |
| callback | AsyncCallback&lt;string&gt; | 是 | 新创建的文件的uri |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
  let displayName: string = "file1";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.createFile(sourceUri, displayName, (err: BusinessError, fileUri: string) => {
        if (err) {
          console.error("Failed to createFile in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("createFile sucess, fileUri: " + JSON.stringify(fileUri));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### mkDir

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

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  async function createDirectory() {
    let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
    let dirName: string = "dirTest";
    let dirUri: string;
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        dirUri = await fileAccessHelper.mkDir(sourceUri, dirName);
        if (!dirUri) {
          console.error("mkDir return undefined object");
        } else {
          console.log("mkDir success, dirUri: " + JSON.stringify(dirUri));
        }
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("mkDir failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### mkDir

mkDir(parentUri: string, displayName: string, callback: AsyncCallback&lt;string&gt;) : void

以异步方法创建文件夹到指定目录，返回文件夹uri。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| parentUri | string | 是 | 表示需要创建文件夹的父目录的Uri |
| displayName | string | 是 | 待创建文件夹的名称|
| callback | AsyncCallback&lt;string&gt; | 是 | 新创建的文件夹的uri |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
  let dirName: string = "dirTest";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.mkDir(sourceUri, dirName, (err: BusinessError, dirUri: string) => {
        if (err) {
          console.error("Failed to mkDir in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("mkDir sucess, dirUri: " + JSON.stringify(dirUri));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("mkDir failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### openFile

openFile(uri: string, flags: OPENFLAGS) : Promise&lt;number&gt;

以异步方法打开文件，返回文件描述符。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 待打开文件的uri |
| flags | [OPENFLAGS](#openflags) | 是 | 文件打开的标志 |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;number&gt; | 文件描述符 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function openFile01() {
    // 以内置存储目录为例
    // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
    // 开发者应根据自己实际获取的uri进行开发
    let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let fd = await fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ);
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("openFile failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### openFile

openFile(uri: string, flags: OPENFLAGS, callback: AsyncCallback&lt;number&gt;) : void

以异步方法打开文件，返回文件描述符。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 待打开文件的uri |
| flags | [OPENFLAGS](#openflags) | 是 | 文件打开的标志 |
| callback | AsyncCallback&lt;number&gt; | 是 | 文件描述符 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ, (err: BusinessError, fd: number) => {
        if (err) {
          console.error("Failed to openFile in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("openFile sucess, fd: " + fd);
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("openFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### delete

delete(uri: string) : Promise&lt;number&gt;

以异步方法删除文件(夹)，返回错误码。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 待删除文件(夹)的uri |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;number&gt; | 删除操作的错误码 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function deleteFile01() {
    // 以内置存储目录为例
    // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
    // 开发者应根据自己实际获取的uri进行开发
    let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let code = await fileAccessHelper.delete(targetUri);
        if (code != 0)
          console.error("delete failed, code " + code);
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("delete failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### delete

delete(uri: string, callback: AsyncCallback&lt;number&gt;) : void

以异步方法删除文件(夹)，返回错误码。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 待删除文件(夹)的uri |
| callback | AsyncCallback&lt;number&gt; | 是 | 删除操作的错误码 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.delete(targetUri, (err: BusinessError, code: number) => {
        if (err) {
          console.error("Failed to delete in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("delete sucess, code: " + code);
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("delete failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### move

move(sourceFile: string, destFile: string) : Promise&lt;string&gt;

以异步方法移动文件(夹)，返回移动后文件(夹)的uri。使用Promise异步回调。目前仅支持设备内移动，跨设备不支持移动。

**系统能力**：SystemCapability.FileManagement.UserFileService

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

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function moveFile01() {
    // 以内置存储目录为例
    // 示例代码sourceFile destFile表示Download目录下文件和文件夹，该uri是对应的fileInfo中uri
    // 开发者应根据自己实际获取的uri进行开发
    let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let fileUri = await fileAccessHelper.move(sourceFile, destFile);
        console.log("move sucess, fileUri: " + JSON.stringify(fileUri));
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("move failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### move

move(sourceFile: string, destFile: string, callback: AsyncCallback&lt;string&gt;) : void

以异步方法移动文件(夹)，返回移动后文件(夹)的uri。使用callback异步回调。目前仅支持设备内移动，跨设备不支持移动。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| sourceFile | string | 是 | 待移动的源文件(夹)的uri |
| destFile | string | 是 | 目标文件夹的uri |
| callback | AsyncCallback&lt;string&gt; | 是 | 新路径下的文件(夹)的uri |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceFile destFile表示Download目录下文件和文件夹，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.move(sourceFile, destFile, (err: BusinessError, fileUri: string) => {
        if (err) {
          console.error("Failed to move in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("move sucess, fileUri: " + JSON.stringify(fileUri));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("move failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### rename

rename(uri: string, displayName: string) : Promise&lt;string&gt;

以异步方法重命名文件(夹)，返回重命名后的文件(夹)的Uri。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

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

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function renameFile01() {
    // 以内置存储目录为例
    // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
    // 开发者应根据自己实际获取的uri进行开发
    let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let DestDir = await fileAccessHelper.rename(sourceDir, "testDir");
        console.log("rename sucess, DestDir: " + JSON.stringify(DestDir));
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("rename failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### rename

rename(uri: string, displayName: string, callback: AsyncCallback&lt;string&gt;) : void

以异步方法重命名文件(夹)，返回重命名后的文件(夹)的Uri。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 源文件(夹)的uri |
| displayName | string | 是 | 文件(夹)名，支持带后缀 |
| callback | AsyncCallback&lt;string&gt; | 是 | 重命名后的文件(夹)的uri |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.rename(sourceDir, "testDir", (err: BusinessError, DestDir: string) => {
        if (err) {
          console.error("Failed to rename in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("rename sucess, DestDir: " + JSON.stringify(DestDir));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("rename failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### access

access(sourceFileUri: string) : Promise&lt;boolean&gt;

以异步方法判断文件(夹)是否存在。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| sourceFileUri | string | 是 | 文件(夹)的uri |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;boolean&gt; | 文件(夹)是否存在，true为存在，false为不存在。|

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  async function accessFunc() {
    let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let existJudgment = await fileAccessHelper.access(sourceDir);
        if (existJudgment) {
          console.log("sourceDir exists");
        } else {
          console.log("sourceDir does not exist");
        }
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("access failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### access

access(sourceFileUri: string, callback: AsyncCallback&lt;boolean&gt;) : void

以异步方法判断文件(夹)是否存在。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| sourceFileUri | string | 是 | 文件(夹)的uri |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 文件(夹)是否存在，true为存在，false为不存在。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceDir表示Download目录下文件夹，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceDir: string = "file://docs/storage/Users/currentUser/Download/test";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.access(sourceDir, (err: BusinessError, existJudgment: boolean) => {
        if (err) {
          console.error("Failed to access in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        if (existJudgment)
          console.log("sourceDir exists");
        else
          console.log("sourceDir does not exist");
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("access failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### getFileInfoFromUri<sup>10+</sup>

getFileInfoFromUri(uri: string) : Promise\<FileInfo>

以异步方法获取uri对应的FileInfo对象。使用promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 文件(夹)的Uri |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise\<[FileInfo](#fileinfo)> | FileInfo对象 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  async function getUri() {
    let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let fileInfo = await fileAccessHelper.getFileInfoFromUri(sourceUri);
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getFileInfoFromUri failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### getFileInfoFromUri<sup>10+</sup>

getFileInfoFromUri(uri: string, callback: AsyncCallback\<FileInfo>) : void

以异步方法获取uri对应的FileInfo对象。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| uri | string | 是 | 文件(夹)的Uri |
| callback | AsyncCallback&lt;[FileInfo](#fileinfo)&gt; | 是 | uri对应的FileInfo对象 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.getFileInfoFromUri(sourceUri, (err: BusinessError, fileInfo: fileAccess.FileInfo) => {
        if (err) {
          console.error("Failed to getFileInfoFromUri in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        console.log("getFileInfoFromUri success, fileInfo: " + JSON.stringify(fileInfo));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("getFileInfoFromUri failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```


### getFileInfoFromRelativePath<sup>10+</sup>

getFileInfoFromRelativePath(relativePath: string) : Promise\<FileInfo>

以异步方法获取relativePath对应的FileInfo对象。使用promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| relativePath | string | 是 | 文件(夹)的相对路径 |

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise\<[FileInfo](#fileinfo)> | FileInfo对象 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 示例代码relativePath表示Download目录，该relativePath是对应的fileInfo中relativePath
  // 开发者应根据自己实际获取的relativePath进行开发
  async function getRelativePath() {
    let relativePath: string = "Download/";
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(relativePath);
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getFileInfoFromRelativePath failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### getFileInfoFromRelativePath<sup>10+</sup>

getFileInfoFromRelativePath(relativePath: string, callback: AsyncCallback\<FileInfo>) : void

以异步方法获取relativePath对应的FileInfo对象。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | -- |
| relativePath | string | 是 | 文件(夹)的相对路径 |
| callback | AsyncCallback&lt;[FileInfo](#fileinfo)&gt; | 是 | relativePath对应的FileInfo对象 |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 示例代码relativePath表示Download目录，该relativePath是对应的fileInfo中relativePath
  // 开发者应根据自己实际获取的relativePath进行开发
  let relativePath: string = "Download/";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.getFileInfoFromRelativePath(relativePath, (err: BusinessError, fileInfo: fileAccess.FileInfo) => {
        if (err) {
          console.error("Failed to getFileInfoFromRelativePath in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        console.log("getFileInfoFromRelativePath success, fileInfo: " + JSON.stringify(fileInfo));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("getFileInfoFromRelativePath failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### query<sup>10+</sup>

query(uri:string, metaJson: string) : Promise&lt;string&gt;

通过uri查询文件或目录的相关信息，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                 |
| -------- | ------ | ---- | ---------------------------------------------------- |
| uri      | string | 是   | 所选文件或目录的uri（从[FileInfo](#fileinfo)中获取） |
| metaJson | string | 是   | json字符串，包含查询属性[FILEKEY](#filekey10)        |

**返回值：**

| 类型                  | 说明                             |
| :-------------------- | :------------------------------- |
| Promise&lt;string&gt; | 返回json字符串，包括查询属性和值 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
async function getQuery01() {
  let imageFileRelativePath: string = "/storage/Users/currentUser/Download/queryTest/image/01.jpg";
  let jsonStrSingleRelativepath: string = JSON.stringify({ [fileAccess.FileKey.RELATIVE_PATH]: "" });
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(imageFileRelativePath);
      let queryResult = await fileAccessHelper.query(fileInfo.uri, jsonStrSingleRelativepath);
      console.log("query_file_single faf query, queryResult.relative_path: " + JSON.parse(queryResult).relative_path);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("query_file_single faf query failed, error.code :" + error.code + ", errorMessage :" + error.message);
  }
}
```

### query<sup>10+</sup>

query(uri:string, metaJson: string, callback: AsyncCallback&lt;string&gt;) : void

通过uri查询文件或目录的相关信息，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                 |
| -------- | --------------------------- | ---- | ---------------------------------------------------- |
| uri      | string | 是   | 所选文件或目录的uri（从[FileInfo](#fileinfo)中获取） |
| metaJson | string | 是   | json字符串，包含查询属性[FILEKEY](#filekey10)        |
| callback | AsyncCallback&lt;string&gt; | 是   | 返回json字符串，包括查询属性和值                     |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
async function getQuery02() {
  let imageFileRelativePath: string = "/storage/Users/currentUser/Download/queryTest/image/01.jpg";
  let jsonStrSingleRelativepath: string = JSON.stringify({ [fileAccess.FileKey.RELATIVE_PATH]: "" });
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(imageFileRelativePath);
      fileAccessHelper.query(fileInfo.uri, jsonStrSingleRelativepath, (err: BusinessError, queryResult: string) => {
        if (err) {
          console.log("query_file_single faf query Failed, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        console.log("query_file_single faf query, queryResult.relative_path: " + JSON.parse(queryResult).relative_path);
      })
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("query_file_single faf query failed, error.code :" + error.code + ", errorMessage :" + error.message);
  }
}
```

### copy<sup>10+</sup>

copy(sourceUri: string, destUri: string, force?: boolean) : Promise&lt;Array&lt;CopyResult&gt;&gt;

复制文件或目录，使用 Promise 异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型    | 必填 | 说明                                                         |
| --------- | ------- | ---- | ------------------------------------------------------------ |
| sourceUri | string  | 是   | 待拷贝的源文件(夹)的 uri，例如：file://docs/storage/Users/currentUser/Download/1.txt  |
| destUri   | string  | 是   | 目标文件夹的 uri，例如：file://docs/storage/Users/currentUser/Download/test        |
| force     | boolean | 否   | 含有同名文件时是否强制覆盖文件，force 为 true 时强制覆盖文件，force 为空或 false 时不强制覆盖文件 |

**返回值：**

| 类型                                                    | 说明                                                         |
| :------------------------------------------------------ | :----------------------------------------------------------- |
| Promise&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | 返回 copyresult 数组，copyResult 为复制操作失败的返回信息，复制成功无返回信息 |

**示例 1：force 为空**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
async function copyFunc01() {
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let copyResult = await fileAccessHelper.copy(sourceFile, destFile);
      if (copyResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < copyResult.length; i++) {
          console.error("errCode" + copyResult[i].errCode);
          console.error("errMsg" + copyResult[i].errMsg);
          console.error("sourceUri" + copyResult[i].sourceUri);
          console.error("destUri" + copyResult[i].destUri);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

**示例 2：force 为 true**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
async function copyFunc02() {
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let copyResult = await fileAccessHelper.copy(sourceFile, destFile, true);
      if (copyResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < copyResult.length; i++) {
          console.error("errCode" + copyResult[i].errCode);
          console.error("errMsg" + copyResult[i].errMsg);
          console.error("sourceUri" + copyResult[i].sourceUri);
          console.error("destUri" + copyResult[i].destUri);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### copy<sup>10+</sup>

copy(sourceUri: string, destUri: string, callback: AsyncCallback&lt;Array&lt;CopyResult&gt;&gt;) : void

复制文件或目录，使用 callback 异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型                                             | 必填 | 说明                                                         |
| --------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                           | 是   | 待拷贝的源文件(夹)的 uri，例如：file://docs/storage/Users/currentUser/Download/1.txt  |
| destUri   | string                                           | 是   | 目标文件夹的 uri，例如：file://docs/storage/Users/currentUser/Download/test         |
| callback  | AsyncCallback&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | 是   | 返回 copyresult 数组，copyResult 为复制操作失败的返回信息，复制成功无返回信息 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
// fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.copy(sourceFile, destFile, async (err: BusinessError, copyResult: Array<fileAccess.CopyResult>) => {
      if (err) {
        console.error("copy failed, errCode:" + err.code + ", errMessage:" + err.message);
      }
      if (copyResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < copyResult.length; i++) {
          console.error("errCode" + copyResult[i].errCode);
          console.error("errMsg" + copyResult[i].errMsg);
          console.error("sourceUri" + copyResult[i].sourceUri);
          console.error("destUri" + copyResult[i].destUri);
        }
      }
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### copy<sup>10+</sup>

copy(sourceUri: string, destUri: string, force: boolean, callback: AsyncCallback&lt;Array&lt;CopyResult&gt;&gt;) : void

复制文件或目录，使用 callback 异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型                                             | 必填 | 说明                                                         |
| --------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                           | 是   | 待拷贝的源文件(夹)的 uri，例如：file://docs/storage/Users/currentUser/Download/1.txt  |
| destUri   | string                                           | 是   | 目标文件夹的 uri，例如：file://docs/storage/Users/currentUser/Download/test         |
| force     | boolean                                          | 是   | 含有同名文件时是否强制覆盖文件，force 为 true 时强制覆盖文件，force 为空或 false 时不强制覆盖文件 |
| callback  | AsyncCallback&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | 是   | 返回 copyresult 数组，copyResult 为复制操作失败的返回信息，复制成功无返回信息 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
// fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.copy(sourceFile, destFile, true, async (err: BusinessError, copyResult: Array<fileAccess.CopyResult>) => {
      if (err) {
        console.error("copy failed, errCode:" + err.code + ", errMessage:" + err.message);
      }
      if (copyResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < copyResult.length; i++) {
          console.error("errCode" + copyResult[i].errCode);
          console.error("errMsg" + copyResult[i].errMsg);
          console.error("sourceUri" + copyResult[i].sourceUri);
          console.error("destUri" + copyResult[i].destUri);
        }
      }
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### copyFile<sup>11+</sup>

copyFile(sourceUri: string, destUri: string, fileName: string): Promise&lt;string&gt;

复制文件并传入备用文件名，使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型    | 必填 | 说明                                                         |
| --------- | ------- | ---- | ------------------------------------------------------------ |
| sourceUri | string  | 是   | 待拷贝的源文件(夹)的 uri，例如：file://docs/storage/Users/currentUser/Download/1.txt  |
| destUri   | string  | 是   | 目标文件夹的 uri，例如：file://docs/storage/Users/currentUser/Download/test        |
| fileName  | string  | 是   | 如果目标目录中有1.txt文件，就是用fileName 作为文件名进行复制 |

**返回值：**

| 类型                                                    | 说明                                                         |
| :------------------------------------------------------ | :----------------------------------------------------------- |
| Promise&lt;string&gt; | 返回一个复制成功的文件的uri |

**示例 1**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
async function copyFunc01() {
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
  let fileName: string = "2.txt";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let copyResult = await fileAccessHelper.copyFile(sourceFile, destFile, fileName);
      console.log("copyResult uri: " + copyResult);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### copyFile<sup>11+</sup>

copyFile(sourceUri: string, destUri: string, fileName: string, callback: AsyncCallback&lt;string&gt;) : void

复制文件并传入备用文件名，使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型                                             | 必填 | 说明                                                         |
| --------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                           | 是   | 待拷贝的源文件(夹)的 uri，例如：file://docs/storage/Users/currentUser/Download/1.txt  |
| destUri   | string                                           | 是   | 目标文件夹的 uri，例如：file://docs/storage/Users/currentUser/Download/test         |
| fileName  | string                                           | 是   | 如果目标目录中有1.txt文件，就是用fileName 作为文件名进行复制 |
| callback  | AsyncCallback&lt;string&gt; | 是   | 返回一个复制成功的文件的uri |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
let fileName: string = "2.txt";
// fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.copyFile(sourceFile, destFile, fileName, async (copyResult: string) => {
          console.log("copyResult uri: " + copyResult);
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### registerObserver<sup>10+</sup>

registerObserver(uri: string, notifyForDescendants: boolean, callback: Callback&lt;NotifyMessage&gt;): void

注册指定uri的callback。uri与callback可以为多对多的关系，推荐使用一个callback监听一个uri。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名               | 类型                                              | 必填 | 说明                           |
| -------------------- | ------------------------------------------------- | ---- | ------------------------------ |
| uri                  | string                                            | 是   | 文件或目录的uri                |
| notifyForDescendants | boolean                                           | 是   | 监听目录时，是否监听子文件变化。true为监听，false为不监听 |
| callback             | Callback&lt;[NotifyMessage](#notifymessage10)&gt; | 是   | 返回通知信息                   |

**示例1：注册一个callback对一个uri的监听**

```ts
import { BusinessError } from '@ohos.base';
async function registerObserver01() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri1 = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR1');
      let dirUri2 = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR2');
      // 因注册时notifyForDescendants参数为true所以期待收到两次通知
      // uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'，事件类型为NOTIFY_MOVED_FROM
      // uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'，事件类型为NOTIFY_MOVE_SELF
      const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR2/SUB_FILE'，事件类型为NOTIFY_MOVED_TO
      const callbackDir2 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'，事件类型为NOTIFY_MOVE_SELF
      // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'，事件类型为NOTIFY_MOVED_FROM
      const callbackFile = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      let fileUri = await fileAccessHelper.createFile(dirUri1, 'SUB_FILE');
      fileAccessHelper.registerObserver(dirUri1, true, callbackDir1);
      fileAccessHelper.registerObserver(dirUri2, true, callbackDir2);
      // 如果不监听被移动文件本身，将不会触发NOTIFY_MOVE_SELF事件
      fileAccessHelper.registerObserver(fileUri, true, callbackFile);
      let moveFileUri = await fileAccessHelper.move(fileUri, dirUri2);
      // 注册完不应立即解注册，可能存在解注册先于通知返回的情景，这将收不到通知事件
      fileAccessHelper.unregisterObserver(dirUri1, callbackDir1);
      fileAccessHelper.unregisterObserver(dirUri2, callbackDir2);
      fileAccessHelper.unregisterObserver(fileUri, callbackFile);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("registerObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

**示例2：使用相同uri、notifyForDescendants、callback重复注册**

```ts
import { BusinessError } from '@ohos.base';
async function registerObserver02() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR/SUB_DIR'，事件类型为NOTIFY_ADD
      const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      // 返回注册成功，仅在log中提示重复注册
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      let subDirUri = await fileAccessHelper.mkDir(dirUri, 'SUB_DIR');
      // 注册完不应立即解注册，可能存在解注册先于通知返回的情景，这将收不到通知事件
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("registerObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

**示例3：使用相同uri、callback及不同notifyForDescendants重复注册会重置notifyForDescendants**

```ts
import { BusinessError } from '@ohos.base';
async function registerObserver03() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // 期待第一次收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR/SUB_FILE_1'，事件类型为NOTIFY_ADD
      // 期待无第二次返回
      const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      let subFile1 = await fileAccessHelper.createFile(dirUri, 'SUB_FILE_1');
      // 注册成功修改notifyForDescendants为false,不感知子文件的变化
      fileAccessHelper.registerObserver(dirUri, false, callbackDir);
      let subFile2 = await fileAccessHelper.createFile(dirUri, 'SUB_FILE_2');
      // 注册完不应立即解注册，可能存在解注册先于通知返回的情景，这将收不到通知事件
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("registerObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

**示例4：注册监听设备上下线**

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver03() {
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
      if (NotifyMessageDir != undefined) {
        console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
      } else {
        console.error("NotifyMessageDir is undefined");
      }
    }
    if (fileAccessHelper != undefined) {
      // 监听设备的上下线
      fileAccessHelper.registerObserver(fileAccess.DEVICES_URI, true, callbackDir1);
      // 取消监听设备的上下线
      fileAccessHelper.unregisterObserver(fileAccess.DEVICES_URI);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### unregisterObserver<sup>10+</sup>

 unregisterObserver(uri: string, callback?: Callback&lt;NotifyMessage&gt;): void

取消注册指定的uri和callback。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                      |
| -------- | ------------------------------------------------- | ---- | ------------------------- |
| uri      | string                                            | 是   | 文件或目录的uri           |
| callback | Callback&lt;[NotifyMessage](#notifymessage10)&gt; | 否   | 解注册uri下对应的callback。如果该参数不填，则解注册对应的所有callbackback |

**示例1: 解注册监听uri的一个callback**

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver01() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR'，事件类型为NOTIFY_DELETE
      const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      await fileAccessHelper.delete(dirUri);
      // 注册完不应立即解注册，可能存在解注册先于通知返回的情景，这将收不到通知事件
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

**示例2：对监听uri的某一callback重复解注册**

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver02() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
      if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR'，事件类型为NOTIFY_DELETE
      const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      await fileAccessHelper.delete(dirUri);
      // 注册完不应立即解注册，可能存在解注册先于通知返回的情景，这将收不到通知事件
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
      // 解注册失败，抛出错误码 E_CAN_NOT_FIND_URI
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
      }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

**示例3：解注册监听uri的所有callback**

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver03() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR/SUB_FILE'，事件类型为NOTIFY_MOVED_FROM
      // 期待收到uri为'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR/RENAME_FILE'，事件类型为NOTIFY_MOVED_TO
      const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      // 期待收不到任何事件
      const callbackDir2 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      let fileUri = await fileAccessHelper.createFile(dirUri, 'SUB_FILE');
      fileAccessHelper.registerObserver(dirUri, true, callbackDir1);
      // 此处注册为不关注下一级，将收不到关于下一级的事件
      fileAccessHelper.registerObserver(dirUri, false, callbackDir2);
      let renameUri = await fileAccessHelper.rename(fileUri, 'RENAME_FILE');
      // 取消注册监听dirUri的所有callback(callbackDir1、callbackDir2)
      // 注册完不应立即解注册，可能存在解注册先于通知返回的情景，这将收不到通知事件
      fileAccessHelper.unregisterObserver(dirUri);
      await fileAccessHelper.delete(dirUri);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

**示例4：解注册监听设备的上下线**

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver03() {
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
      if (NotifyMessageDir != undefined) {
        console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
      } else {
        console.error("NotifyMessageDir is undefined");
      }
    }
    if (fileAccessHelper != undefined) {
      // 监听设备的上下线
      fileAccessHelper.registerObserver(fileAccess.DEVICES_URI, true, callbackDir1);
      // 取消监听设备的上下线
      fileAccessHelper.unregisterObserver(fileAccess.DEVICES_URI);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### moveItem<sup>11+</sup>

moveItem(sourceUri: string, destUri: string, force?: boolean) : Promise&lt;Array&lt;MoveResult&gt;&gt;

以异步方法移动文件(夹)，返回移动后文件(夹)的uri。使用Promise异步回调。

当存在同名文件时，可以选择强制覆盖文件。

目前仅支持设备内移动，跨设备不支持移动。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型    | 必填 | 说明                                                         |
| --------- | ------- | ---- | ------------------------------------------------------------ |
| sourceUri | string  | 是   | 待移动的源文件(夹)的uri。                                    |
| destUri   | string  | 是   | 目标文件夹的uri。                                            |
| force     | boolean | 否   | 选择当存在同名文件时，是否强制覆盖文件。当force为true时，强制覆盖文件；为false时不强制覆盖文件。该参数不填，默认为false。 |

**返回值：**

| 类型                                                    | 说明                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[MoveResult](#moveresult11)&gt;&gt; | 返回 moveresult 数组，moveResult 为移动操作失败的返回信息，复制成功无返回信息。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例 1：force 为空**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
async function moveItemFunc01() {
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let moveResult = await fileAccessHelper.moveItem(sourceUri, destUri);
      if (moveResult.length === 0) {
        console.log("moveItem success");
      } else {
        for (let i = 0; i < moveResult.length; i++) {
          console.error("errCode" + moveResult[i].errCode);
          console.error("errMsg" + moveResult[i].errMsg);
          console.error("sourceUri" + moveResult[i].sourceUri);
          console.error("destUri" + moveResult[i].destUri);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("moveItem failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

**示例 2：force 为 true**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
async function moveItemFunc02() {
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let moveResult = await fileAccessHelper.moveItem(sourceUri, destUri, true);
      if (moveResult.length === 0) {
        console.log("moveItem success");
      } else {
        for (let i = 0; i < moveResult.length; i++) {
          console.error("errCode" + moveResult[i].errCode);
          console.error("errMsg" + moveResult[i].errMsg);
          console.error("sourceUri" + moveResult[i].sourceUri);
          console.error("destUri" + moveResult[i].destUri);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("moveItem failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### moveItem<sup>11+</sup>

moveItem(sourceUri: string, destUri: string, callback: AsyncCallback&lt;Array&lt;MoveResult&gt;&gt;) : void

以异步方法移动文件(夹)，返回移动后文件(夹)的uri。使用callback异步回调。

当前仅支持设备内移动，不支持跨设备移动。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                                       | 是   | 待移动的源文件(夹)的uri。                                    |
| destUri   | string                                                       | 是   | 目标文件夹的uri。                                            |
| callback  | AsyncCallback&lt;Array&lt;[MoveResult](#moveresult11)&gt;&gt; | 是   | 回调返回MoveResult数组。MoveResult为移动操作失败的返回信息，移动成功无返回信息。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
// fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.moveItem(sourceUri, destUri, async (err: BusinessError, copyResult: Array<fileAccess.MoveResult>) => {
      if (err) {
        console.error("moveItem failed, errCode:" + err.code + ", errMessage:" + err.message);
      }
      if (moveResult.length === 0) {
        console.log("moveItem success");
      } else {
        for (let i = 0; i < moveResult.length; i++) {
          console.error("errCode" + moveResult[i].errCode);
          console.error("errMsg" + moveResult[i].errMsg);
          console.error("sourceUri" + moveResult[i].sourceUri);
          console.error("destUri" + moveResult[i].destUri);
        }
      }
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("moveItem failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### moveItem<sup>11+</sup>

moveItem(sourceUri: string, destUri: string, force: boolean, callback: AsyncCallback&lt;Array&lt;MoveResult&gt;&gt;) : void

以异步方法移动文件(夹)，返回移动后文件(夹)的uri。使用callback异步回调。

当存在同名文件时，可以选择强制覆盖文件。

当前仅支持设备内移动，不支持跨设备移动。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                                       | 是   | 待移动的源文件(夹)的uri。                                    |
| destUri   | string                                                       | 是   | 目标文件夹的uri。                                            |
| force     | boolean                                                      | 是   | 选择当存在同名文件时，是否强制覆盖文件。当force为true时，强制覆盖文件；为false时不强制覆盖文件。该参数不填，默认为false。 |
| callback  | AsyncCallback&lt;Array&lt;[MoveResult](#moveresult11)&gt;&gt; | 是   | 回调返回MoveResult数组。MoveResult为移动操作失败的返回信息，移动成功无返回信息。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
// 以内置存储目录为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
// fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.moveItem(sourceUri, destUri, true, async (err: BusinessError, moveResult: Array<fileAccess.MoveResult>) => {
      if (err) {
        console.error("moveItem failed, errCode:" + err.code + ", errMessage:" + err.message);
      }
      if (moveResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < moveResult.length; i++) {
          console.error("errCode" + moveResult[i].errCode);
          console.error("errMsg" + moveResult[i].errMsg);
          console.error("sourceUri" + moveResult[i].sourceUri);
          console.error("destUri" + moveResult[i].destUri);
        }
      }
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("moveItem failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### moveFile<sup>11+</sup>

moveFile(sourceUri: string, destUri: string, fileName: string) : Promise&lt;string&gt;

以异步方法移动文件，返回移动后文件的uri。使用Promise异步回调。

当存在同名文件时（即发生文件移动冲突时），可以重命名待移动的文件，再保存到目标文件夹。

目前仅支持设备内移动，跨设备不支持移动。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ---------- | ------ | ---- | ------------------- |
| sourceFile | string | 是   | 待移动源文件的uri。 |
| destFile   | string | 是   | 目标文件夹的uri。   |
| fileName   | string | 是   | 冲突文件的新名称。  |

**返回值：**

| 类型                  | 说明                |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | 新路径下的文件uri。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function moveFile01() {
    // 以内置存储目录为例
    // 示例代码sourceUri destUri表示Download目录下文件和文件夹，该uri是对应的fileInfo中uri
    // 开发者应根据自己实际获取的uri进行开发
    let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
    let fileName: string;
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
    if (fileAccessHelper != undefined) {
        let fileUri = await fileAccessHelper.moveFile(sourceUri, destUri, fileName);
        console.log("moveFile sucess, fileUri: " + JSON.stringify(fileUri));
    }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("moveFile failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### moveFile<sup>11+</sup>

moveFile(sourceUri: string, destUri: string,  fileName: string, callback: AsyncCallback&lt;string&gt;) : void

以异步方法移动文件，返回移动后文件的uri。使用callback异步回调。

当存在同名文件时（即发生文件移动冲突时），可以重命名待移动的文件，再保存到目标文件夹。

当前仅支持设备内移动，不支持跨设备移动。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名     | 类型                        | 必填 | 说明                  |
| ---------- | --------------------------- | ---- | --------------------- |
| sourceFile | string                      | 是   | 待移动的源文件的uri。 |
| destFile   | string                      | 是   | 目标文件夹的uri。     |
| fileName   | string                      | 是   | 冲突文件的新名称。    |
| callback   | AsyncCallback&lt;string&gt; | 是   | 新路径下的文件uri。   |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  // 以内置存储目录为例
  // 示例代码sourceUri destUri表示Download目录下文件和文件夹，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
  let fileName: string;
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.moveFile(sourceUri, destUri, fileName, (err: BusinessError, fileUri: string) => {
        if (err) {
          console.error("Failed to moveFile in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("moveFile sucess, fileUri: " + JSON.stringify(fileUri));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("moveFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

## CopyResult<sup>10+</sup>

表示复制操作失败时的返回信息，复制成功时则没有返回信息。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

| 名称      | 类型   | 只读 | 可写 | 说明                |
| --------- | ------ | ---- | ---- | ----------------- |
| sourceUri | string | 是   | 否   | 源文件(夹) uri                                         |
| destUri   | string | 是   | 否   | 产生冲突的目标文件的 uri。如果非冲突导致的错误，则为空 |
| errCode   | number | 是   | 否   | 错误码                                                 |
| errMsg    | string | 是   | 否   | 错误信息                                               |

## OPENFLAGS

枚举，目前支持的文件打开的标志位。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称 | 值 | 说明 |
| ----- | ------ | ------ |
| READ | 0o0 | 读模式。 |
| WRITE | 0o1 | 写模式。 |
| WRITE_READ | 0o2 | 读写模式。 |

## FILEKEY<sup>10+</sup>

枚举，支持查询的键。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称          | 值            | 说明                                |
| ------------- | ------------- | ----------------------------------- |
| DISPLAY_NAME  | 'display_name'  | 文件名                              |
| DATE_ADDED    | 'date_added'   | 文件创建的日期，例如1501925454      |
| DATE_MODIFIED | 'date_modified' | 文件的修改日期，例如1665310670      |
| RELATIVE_PATH | 'relative_path' | 相对路径，例如Pictures/Screenshots/ |
| FILE_SIZE     | 'size'          | 文件（夹）大小（单位：字节）        |

## NotifyType<sup>10+</sup>

枚举，通知类型。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

| 名称              | 值   | 说明                                                         |
| ----------------- | ---- | ------------------------------------------------------------ |
| NOTIFY_ADD        | 0    | 表示新增文件（详见registerObserver接口的示例2、示例3）                                                 |
| NOTIFY_DELETE     | 1    | 表示删除文件（详见unregisterObserver(uri: string, callback: Callback&lt;NotifyMessage&gt;)接口的示例1、示例2）                                               |
| NOTIFY_MOVED_TO   | 2    | 表示移动至该文件（对目录下子文件或目录执行rename操作，或外部文件或目录执行move操作到本文件，详见registerObserver接口的示例1，及unregisterObserver(uri: string)接口的示例1）|
| NOTIFY_MOVED_FROM | 3    | 表示自该文件移出（对目录下子文件或目录执行rename操作，或子文件（夹）执行move操作从该文件夹内移出，详见registerObserver接口的示例1，及unregisterObserver(uri: string)接口的示例1） |
| NOTIFY_MOVE_SELF  | 4    | 表示本文件被移动（如对文件或文件夹执行rename或move操作时，监听该文件（夹）的callback收到该事件，详见registerObserver接口的示例1）     |
| NOTIFY_DEVICE_ONLINE<sup>11+</sup>   | 5    | 表示设备上线     |
| NOTIFY_DEVICE_OFFLINE<sup>11+</sup>   | 6    | 表示设备下线     |

## NotifyMessage<sup>10+</sup>

通知回调函数的值。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

| 名称 | 类型                        | 只读 | 可写 | 说明                                                      |
| ---- | --------------------------- | ---- | ---- | --------------------------------------------------------- |
| type | [NotifyType](#notifytype10) | 是   | 否   | 变更的通知类型                                            |
| uris | Array&lt;string&gt;         | 是   | 否   | 所变更文件的uri集合，目前仅支持单条通知，后序支持多条通知 |

## MoveResult<sup>11+</sup>

表示移动操作失败时的返回信息，移动成功时则没有返回信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

| 名称      | 类型   | 只读 | 可写 | 说明                                                         |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| sourceUri | string | 是   | 否   | 源文件(夹) uri                                               |
| destUri   | string | 是   | 否   | 产生冲突的目标文件的 uri。如果非冲突导致的错误，则为空。     |
| errCode   | number | 是   | 否   | 错误码。接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。 |
| errMsg    | string | 是   | 否   | 错误信息。                                                   |
