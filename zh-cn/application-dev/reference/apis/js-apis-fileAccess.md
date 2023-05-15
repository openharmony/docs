# @ohos.file.fileAccess (公共文件访问与管理)

fileAccess模块是基于extension机制实现的一个对公共文件访问和操作的框架。该模块一方面对接各类文件管理服务，如媒体库、外置存储管理服务等，另一方面为系统应用提供一套统一的文件访问管理接口。其中，媒体库服务提供本地设备、分布式设备等公共文件访问服务；外置存储管理服务可以提供共享盘、U盘、SD卡等设备的公共文件访问服务。

>**说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口，三方应用不支持调用，当前只支持FilePicker、文件管理器调用。

## 导入模块

```js
import fileAccess from '@ohos.file.fileAccess';
```

## fileAccess.getFileAccessAbilityInfo

getFileAccessAbilityInfo() : Promise&lt;Array&lt;Want&gt;&gt;

以异步方法获取系统内extension配置为fileAccess类型的所有Want信息。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER 和 ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | Promise&lt;Array&lt;[Want](js-apis-app-ability-want.md)&gt;&gt; | 表示当前系统配置fileAccess的所有文件管理类服务 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  async getFileAccessAbilityInfo() {
    let wantInfos = [];
    try {
      wantInfos = await fileAccess.getFileAccessAbilityInfo();
      console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));
    } catch (error) {
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
  | callback | AsyncCallback&lt;Array&lt;[Want](js-apis-app-ability-want.md)&gt;&gt; | 是 | 表示当前系统配置fileAccess的所有文件管理类服务 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  async getFileAccessAbilityInfo() {
    try {
      fileAccess.getFileAccessAbilityInfo(function (err, wantInfos) {
        if (err) {
          console.error("Failed to getFileAccessAbilityInfo in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));
      });
    } catch (error) {
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
  | context | [Context](js-apis-inner-application-context.md) | 是 | 代表ability的上下文的能力 |
  | wants | Array&lt;[Want](js-apis-app-ability-want.md)&gt; | 是 | Want是一种基本通信组件，主要用于服务拉起 |

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | [FileAccessHelper](#fileaccesshelper) | 提供文件访问和操作能力的helper对象 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  createFileAccessHelper() {
    let fileAccessHelper = null;
    // wantInfos 从getFileAccessAbilityInfo()获取
    // 创建只连接媒体库服务的helper对象
    let wantInfos = [
      {
        "bundleName": "com.ohos.medialibrary.medialibrarydata",
        "abilityName": "FileExtensionAbility",
      },
    ]
    try {
      // this.context 是EntryAbility 传过来的context
      fileAccessHelper = fileAccess.createFileAccessHelper(this.context, wantInfos);
      if (!fileAccessHelper)
        console.error("createFileAccessHelper interface returns an undefined object");
    } catch (error) {
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
  | context | [Context](js-apis-inner-application-context.md) | 是 | ability的上下文的能力 |

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | [FileAccessHelper](#fileaccesshelper) | 提供文件访问和操作的能力的helper对象 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  createFileAccessHelper() {
    let fileAccessHelperAllServer = null;
    // 创建连接系统内所有配置fileAccess的文件管理类服务的helper对象
    try {
      // this.context 是EntryAbility 传过来的context
      fileAccessHelperAllServer = fileAccess.createFileAccessHelper(this.context);
      if (!fileAccessHelperAllServer)
        console.error("createFileAccessHelper interface returns an undefined object");
    } catch (error) {
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

| 名称 | 类型   | 可读 | 可写 | 说明     |
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // fileInfoDir 表示某个目录信息
  // let filter = { suffix : [".txt", ".jpg", ".xlsx"] };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // fileInfoDir 表示某个目录信息
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
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
      console.log("next result = " + JSON.stringify(result));
      isDone = result.done;
      if (!isDone)
        subfileInfos.push(result.value);
    }
  } catch (error) {
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

## RootInfo

表示设备的根属性信息和接口能力。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### 属性

| 名称 | 类型   | 可读 | 可写 | 说明     |
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // rootinfos 从getRoots()获取
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // rootInfos 从 getRoots()获取
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo = rootInfos[0];
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  async getRoots() {
    let rootIterator = null;
    let rootinfos = [];
    let isDone = false;
    try {
      // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  async getRoots() {
    let rootinfos = [];
    let isDone = false;
    try {
      // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
      fileAccessHelper.getRoots(function (err, rootIterator) {
        if (err) {
          console.error("Failed to getRoots in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        while (!isDone) {
          let result = rootIterator.next();
          console.log("next result = " + JSON.stringify(result));
          isDone = result.done;
          if (!isDone)
            rootinfos.push(result.value);
        }
      });
    } catch (error) {
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri = "file://media/file/6";
  let displayName = "file1"
  let fileUri = null;
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileUri = await fileAccessHelper.createFile(sourceUri, displayName)
    if (!fileUri) {
      console.error("createFile return undefined object");
      return;
    }
    console.log("createFile sucess, fileUri: " + JSON.stringify(fileUri));
  } catch (error) {
    console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri = "file://media/file/6";
  let displayName = "file1"
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.createFile(sourceUri, displayName, function (err, fileUri) {
      if (err) {
        console.error("Failed to createFile in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      console.log("createFile sucess, fileUri: " + JSON.stringify(fileUri));
    });
  } catch (error) {
    console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri = "file://media/file/6";
  let dirName = "dirTest"
  let dirUri = null;
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    dirUri = await fileAccessHelper.mkDir(sourceUri, dirName)
    if (!dirUri) {
      console.error("mkDir return undefined object");
      return;
    }
    console.log("mkDir sucess, dirUri: " + JSON.stringify(dirUri));
  } catch (error) {
    console.error("mkDir failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri = "file://media/file/6";
  let dirName = "dirTest"
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.mkDir(sourceUri, dirName, function (err, dirUri) {
      if (err) {
        console.error("Failed to mkDir in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      console.log("mkDir sucess, dirUri: " + JSON.stringify(dirUri));
    });
  } catch (error) {
    console.error("mkDir failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let targetUri  = "file://media/file/100";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fd = await fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ);
  } catch (error) {
    console.error("openFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let targetUri  = "file://media/file/100";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ, function (err, fd) {
      if (err) {
        console.error("Failed to openFile in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      console.log("openFile sucess, fd: " + fd);
    });
  } catch (error) {
    console.error("openFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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
| Promise&lt;number&gt | 删除操作的错误码 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let targetUri = "file://media/file/100";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let code = await fileAccessHelper.delete(targetUri);
    if (code != 0)
      console.error("delete failed, code " + code);
  } catch (error) {
    console.error("delete failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码targetUri表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let targetUri = "file://media/file/100";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.delete(targetUri, function (err, code) {
      if (err) {
        console.error("Failed to delete in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      console.log("delete sucess, code: " + code);
    });
  } catch (error) {
    console.error("delete failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceFile destFile表示Download目录下文件或文件夹，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceFile = "file://media/file/102";
  let destFile = "file://media/file/101";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileUri = await fileAccessHelper.move(sourceFile, destFile);
    console.log("move sucess, fileUri: " + JSON.stringify(fileUri));
  } catch (error) {
    console.error("move failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceFile destFile表示Download目录下文件或文件夹，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceFile = "file://media/file/102";
  let destFile = "file://media/file/101";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.move(sourceFile, destFile, function (err, fileUri) {
      if (err) {
        console.error("Failed to move in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      console.log("move sucess, fileUri: " + JSON.stringify(fileUri));
    });
  } catch (error) {
    console.error("move failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceDir = "file://media/file/100";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let DestDir = await fileAccessHelper.rename(sourceDir, "testDir");
    console.log("rename sucess, DestDir: " + JSON.stringify(DestDir));
  } catch (error) {
    console.error("rename failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceDir = "file://media/file/100";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.rename(sourceDir, "testDir", function (err, DestDir) {
      if (err) {
        console.error("Failed to rename in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      console.log("rename sucess, DestDir: " + JSON.stringify(DestDir));
    });
  } catch (error) {
    console.error("rename failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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
| Promise&lt;boolean&gt; | 文件(夹)是否存在 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceDir = "file://media/file/100";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let existJudgment = await fileAccessHelper.access(sourceDir);
    if (existJudgment)
      console.log("sourceDir exists");
    else
      console.log("sourceDir does not exist");
  } catch (error) {
    console.error("access failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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
| callback | AsyncCallback&lt;boolean&gt; | 是 | 文件(夹)是否存在 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  // 以媒体库uri为例
  // 示例代码sourceDir表示Download目录下文件，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceDir = "file://media/file/100";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.access(sourceDir, function (err, existJudgment) {
      if (err) {
        console.error("Failed to access in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      if (existJudgment)
        console.log("sourceDir exists");
      else
        console.log("sourceDir does not exist");
    });
  } catch (error) {
    console.error("access failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

  ```js
  // 以媒体库uri为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri = "file://media/file/6";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileInfo = await fileAccessHelper.getFileInfoFromUri(sourceUri);
  } catch (error) {
    console.error("getFileInfoFromUri failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

  ```js
  // 以媒体库uri为例
  // 示例代码sourceUri表示Download目录，该uri是对应的fileInfo中uri
  // 开发者应根据自己实际获取的uri进行开发
  let sourceUri = "file://media/file/6";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.getFileInfoFromUri(sourceUri, function (err, fileInfo) {
      if (err) {
        console.error("Failed to getFileInfoFromUri in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      console.log("getFileInfoFromUri success, fileInfo: " + JSON.stringify(fileInfo));
    });
  } catch (error) {
    console.error("getFileInfoFromUri failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

  ```js
  // 以媒体库relativePath为例
  // 示例代码relativePath表示Download目录，该relativePath是对应的fileInfo中relativePath
  // 开发者应根据自己实际获取的relativePath进行开发
  let relativePath = "Download/";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(relativePath);
  } catch (error) {
    console.error("getFileInfoFromRelativePath failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
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

  ```js
  // 以媒体库relativePath为例
  // 示例代码relativePath表示Download目录，该relativePath是对应的fileInfo中relativePath
  // 开发者应根据自己实际获取的relativePath进行开发
  let relativePath = "Download/";
  try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.getFileInfoFromRelativePath(relativePath, function (err, fileInfo) {
      if (err) {
        console.error("Failed to getFileInfoFromRelativePath in async, errCode:" + err.code + ", errMessage:" + err.message);
        return;
      }
      console.log("getFileInfoFromRelativePath success, fileInfo: " + JSON.stringify(fileInfo));
    });
  } catch (error) {
    console.error("getFileInfoFromRelativePath failed, errCode:" + error.code + ", errMessage:" + error.message);
  };
  ```

### getThumbnail<sup>10+</sup>

getThumbnail(uri: string, size: image.Size) : Promise&lt;image.PixelMap&gt;

通过指定uri和尺寸获取媒体文件的Pixelmap对象，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型                                | 必填 | 说明        |
| ------ | ----------------------------------- | ---- | ----------- |
| uri    | string                              | 是   | 媒体文件uri |
| size   | [image.Size](js-apis-image.md#size) | 是   | 缩略图尺寸  |

**返回值：**

| 类型                          | 说明               |
| :---------------------------- | :----------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 返回的Pixelmap对象 |

**示例：**

```js
// 以媒体库uri为例
// 示例代码targetUri表示Download目录下某个媒体文件(图片、音频、视频)，该uri是对应的fileInfo中uri
// 开发者应根据自己实际获取的uri进行开发
let targetUri = "file://media/image/100";
let size = { width: 128, height: 128 };
try {
  // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
  let pixelMap = await fileAccessHelper.getThumbnail(targetUri, size);
  let imageInfo = await pixelMap.getImageInfo();    
  console.log("getThumbnail sucess, pixelMap.width: " + imageInfo.size.width);
  console.log("getThumbnail sucess, pixelMap.height: " + imageInfo.size.height);
} catch (error) {
  console.error("getThumbnail failed, errCode:" + error.code + ", errMessage:" + error.message);
};
```

### getThumbnail<sup>10+</sup>

 getThumbnail(uri: string, size: image.Size, callback: AsyncCallback&lt;image.PixelMap&gt;) : void

通过指定uri和尺寸获取媒体文件的Pixelmap对象，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名   | 类型                                | 必填 | 说明               |
| -------- | ----------------------------------- | ---- | ------------------ |
| uri      | string                              | 是   | 媒体文件uri        |
| size     | [image.Size](js-apis-image.md#size) | 是   | 缩略图尺寸         |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 是   | 返回的Pixelmap对象 |

**示例：**

```js
// 以媒体库uri为例
// 示例代码targetUri表示Download目录下某个媒体文件(图片、音频、视频)，该uri是对应的fileInfo中uri
// 开发者应根据自己实际获取的uri进行开发
let targetUri = "file://media/image/100";
let size = { width: 128, height: 128 };
try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.getThumbnail(targetUri, size, async(err, pixelMap) => {
        if (err) {
            console.error("Failed to getThumbnail in async, errCode:" + err.code + ", errMessage:" + err.message);
            return;
        }
        let imageInfo = await pixelMap.getImageInfo();
        console.log("getThumbnail sucess, pixelMap.width: " + imageInfo.size.width);
        console.log("getThumbnail sucess, pixelMap.height: " + imageInfo.size.height);
    });
} catch (error) {
    console.error("getThumbnail failed, errCode:" + error.code + ", errMessage:" + error.message);
};
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

```js
var imageFileRelativePath = "Download/queryTest/image/01.jpg";
var jsonStrSingleRelativepath = JSON.stringify({ [fileAccess.FileKey.RELATIVE_PATH]: "" });
try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    var fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(imageFileRelativePath);
    let queryResult = await fileAccessHelper.query(fileInfo.uri, jsonStrSingleRelativepath);
    console.log("query_file_single faf query, queryResult.relative_path: " + JSON.parse(queryResult).relative_path);
} catch (error) {
     console.error("query_file_single faf query failed, error.code :" + error.code + ", errorMessage :" + error.message);
};
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

```js
var imageFileRelativePath = "Download/queryTest/image/01.jpg";
var jsonStrSingleRelativepath = JSON.stringify({ [fileAccess.FileKey.RELATIVE_PATH]: "" });
try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    var fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(imageFileRelativePath);
    fileAccessHelper.query(fileInfo.uri, jsonStrSingleRelativepath, (err, queryResult)=>{
        if (err) {
            console.log("query_file_single faf query Failed, errCode:" + err.code + ", errMessage:" + err.message);
            return;
        }
        console.log("query_file_single faf query, queryResult.relative_path: " + JSON.parse(queryResult).relative_path);
    })
} catch (error) {
   console.error("query_file_single faf query failed, error.code :" + error.code + ", errorMessage :" + error.message);
};
```

### copy<sup>10+</sup>

copy(sourceUri: string, destUri: string, force?: boolean) : Promise&lt;Array&lt;CopyResult&gt;&gt;

复制文件或目录，使用 Promise 异步回调。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名    | 类型    | 必填 | 说明                                                         |
| --------- | ------- | ---- | ------------------------------------------------------------ |
| sourceUri | string  | 是   | 待拷贝的源文件(夹)的 uri，例如：file://media/file/102  |
| destUri   | string  | 是   | 目标文件夹的 uri，例如：file://media/file/101          |
| force     | boolean | 否   | 含有同名文件时是否强制覆盖文件，force 为 true 时强制覆盖文件，force 为空或 false 时不强制覆盖文件 |

**返回值：**

| 类型                                                    | 说明                                                         |
| :------------------------------------------------------ | :----------------------------------------------------------- |
| Promise&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | 返回 copyresult 数组，copyResult 为复制操作失败的返回信息，复制成功无返回信息 |

**示例 1：force 为空**

```js
// 以媒体库uri为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceFile = "file://media/file/102";
let destFile = "file://media/file/101";
try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
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
} catch (error) {
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

**示例 2：force 为 true**

```js
// 以媒体库uri为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceFile = "file://media/file/102";
let destFile = "file://media/file/101";
try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
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
} catch (error) {
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
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
| sourceUri | string                                           | 是   | 待拷贝的源文件(夹)的 uri，例如：file://media/file/102  |
| destUri   | string                                           | 是   | 目标文件夹的 uri，例如：file://media/file/101          |
| callback  | AsyncCallback&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | 是   | 返回 copyresult 数组，copyResult 为复制操作失败的返回信息，复制成功无返回信息 |

**示例：**

```js
// 以媒体库uri为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceFile = "file://media/file/102";
let destFile = "file://media/file/101";
try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.copy(sourceFile, destFile, async (err, copyResult) => {
        if (err) {
            console.error("copy failed, errCode:" + err.code + ", errMessage:" + err.message);
            return;
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
} catch (error) {
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
| sourceUri | string                                           | 是   | 待拷贝的源文件(夹)的 uri，例如：file://media/file/102  |
| destUri   | string                                           | 是   | 目标文件夹的 uri，例如：file://media/file/101          |
| force     | boolean                                          | 是   | 含有同名文件时是否强制覆盖文件，force 为 true 时强制覆盖文件，force 为空或 false 时不强制覆盖文件 |
| callback  | AsyncCallback&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | 是   | 返回 copyresult 数组，copyResult 为复制操作失败的返回信息，复制成功无返回信息 |

**示例：**

```js
// 以媒体库uri为例
// 示例代码中的sourceFile表示Download目录下的源文件(夹)，destFile表示Download目录下的目标文件夹，该uri对应fileInfo中的uri
// 开发者应根据自己实际获取的uri进行开发
let sourceFile = "file://media/file/102";
let destFile = "file://media/file/101";
try {
    // fileAccessHelper 参考 fileAccess.createFileAccessHelper 示例代码获取
    fileAccessHelper.copy(sourceFile, destFile, true, async (err, copyResult) => {
        if (err) {
            console.error("copy failed, errCode:" + err.code + ", errMessage:" + err.message);
            return;
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
} catch (error) {
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

## CopyResult<sup>10+</sup>

表示复制操作失败时的返回信息，复制成功时则没有返回信息。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

| 名称      | 类型   | 可读 | 可写 | 说明                |
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
| WIDTH         | 'width'         | 图像文件的宽度（单位：像素）        |
| HEIGHT        | 'height'        | 图像文件的高度（单位：像素）        |
| DURATION      | 'duration'      | 音频和视频文件的时长（单位：毫秒）  |
