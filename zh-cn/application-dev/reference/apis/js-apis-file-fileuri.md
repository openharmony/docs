# @ohos.file.fileuri (文件URI)

该模块提供通过PATH获取文件统一资源标志符（Uniform Resource Identifier，URI），后续可通过使用[@ohos.file.fs](js-apis-file-fs.md)进行相关open、read、write等操作，实现文件分享。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import fileUri from "@ohos.file.fileuri";
```

使用该功能模块前，需要先获取其应用沙箱路径，开发示例如下：

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import window from '@ohos.window';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      let context = this.context;
      let pathDir = context.filesDir;
    }
  }
  ```

## FileUri<sup>10+</sup>

### 属性

**系统能力**：SystemCapability.FileManagement.AppFileService

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |    
| path<sup>10+</sup> | string | 是 | 否 | 获取FileUri对应路径名。 |
| name<sup>10+</sup> | string | 是 | 否 | 获取FileUri对应文件名。 |

### constructor<sup>10+</sup>

constructor(uriOrPath: string)

constructor是FileUri的构造函数。

**系统能力：** SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uriOrPath | string | 是 | URI或路径。URI类型：<br/>-&nbsp; 应用沙箱URI：file://\<bundleName>/\<sandboxPath> <br/>-&nbsp; 公共目录文件类URI：file://docs/storage/Users/currentUser/\<publicPath> <br/>-&nbsp; 公共目录媒体类URI：file://media/\<mediaType>/IMG_DATATIME_ID/\<displayName> |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 13900005 | I/O error |
| 13900042 | Unknown error |

**示例：**

  ```ts
  let path = pathDir + '/test';
  let uri = fileUri.getUriFromPath(path);  // file://<packageName>/data/storage/el2/base/haps/entry/files/test
  let fileUriObject = new fileUri.FileUri(uri);
  console.info("The name of FileUri is " + fileUriObject.name);
  ```

### toString<sup>10+</sup>

toString(): string

**系统能力：** SystemCapability.FileManagement.AppFileService

返回字符串类型URI。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回字符串类型URI。 |

**示例：**

  ```ts
  let path = pathDir + '/test';
  let fileUriObject = new fileUri.FileUri(path);
  console.info("The uri of FileUri is " + fileUriObject.toString());
  ```

### getFullDirectoryUri<sup>11+</sup>

getFullDirectoryUri(): string

通过文件或文件夹URI获取当前所在路径的URI。

如果当前FileUri指向文件，将返回文件所在路径URI。如`xxx/example.txt`，将返回`xxx`。

如果当前FileUri指向目录，将返回当前路径URI。

**系统能力**：SystemCapability.FileManagement.AppFileService

**返回值：**

| 类型                  | 说明                                |
| --------------------- |-----------------------------------|
| string | 获取所在路径URI，文件获取所在路径URI，目录获取当前路径URI。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息                      |
| ---------------------------- |---------------------------|
| 13900002 | No such file or directory |
| 13900012 | Permission denied         |
| 13900042 | Unknown error             |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  try {
    let path = pathDir + '/test.txt';
    let fileUriObject = new fileUri.FileUri(path);
    let directoryUri = fileUriObject.getFullDirectoryUri();
    console.log(`success to getFullDirectoryUri: ${JSON.stringify(directoryUri)}`);
  } catch (error) {
    console.error(`failed to getFullDirectoryUri because: ${JSON.stringify(error)}`);
  }
  ```

## fileUri.getUriFromPath

getUriFromPath(path: string): string

以同步方法获取文件URI。

**系统能力**：SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 文件的沙箱路径。 |

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | string | 返回文件URI。 |

**错误码：**  

以下错误码的详细介绍请参见[通用错误码](../errorcodes/errorcode-universal.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid |

**示例：**

  ```ts
  let filePath = pathDir + "/test";
  let uri = fileUri.getUriFromPath(filePath);
  ```
