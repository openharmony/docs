# @ohos.file.fileuri (文件URI)

该模块提供通过PATH获取文件统一资源标志符（Uniform Resource Identifier，URI），后续可通过使用[@ohos.file.fs](js-apis-file-fs.md)进行相关open、read、write等操作，实现文件分享。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import fileuri from "@ohos.file.fileuri";
```

使用该功能模块前，需要先获取其应用沙箱路径，开发示例如下：

**Stage模型**

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

**FA模型**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
 
  let context = featureAbility.getContext();
  context.getFilesDir().then((data) => {
    let pathDir = data;
  })
  ```

FA模型context的具体获取方法参见[FA模型](js-apis-inner-app-context.md#Context模块)。

## FileUri<sup>10+</sup>

### 属性

**系统能力**：SystemCapability.FileManagement.AppFileService

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |    
| path<sup>10+</sup> | string | 是 | 否 | 获取FileUri对应路径名 |
| name<sup>10+</sup> | string | 是 | 否 | 获取FileUri对应文件名 |

### constructor<sup>10+</sup>

constructor(uriOrPath: string)

constructor是FileUri的构造函数。

**系统能力：** SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uriOrPath | string | 是 | uri或路径。uri类型：<br/>-&nbsp; 应用沙箱URI：file://\<bundleName>/\<sandboxPath> <br/>-&nbsp; 公共目录文件类URI：file://docs/storage/Users/currentUser/\<publicPath> <br/>-&nbsp; 公共目录媒体类URI：file://media/\<mediaType>/IMG_DATATIME_ID/\<displayName> |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 13900005 | I/O error |
| 13900042 | Unknown error |

**示例：**

  ```ts
  let path = pathDir + '/test';
  let uri = fileuri.getUriFromPath(path);  // file://<packageName>/data/storage/el2/base/haps/entry/files/test
  let fileUriObject = new fileuri.FileUri(uri);
  console.info("The name of FileUri is " + fileUriObject.name);
  ```

### toString<sup>10+</sup>

toString(): string

**系统能力：** SystemCapability.FileManagement.AppFileService

返回字符串类型uri。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回字符串类型uri |

**示例：**

  ```ts
  let path = pathDir + '/test';
  let fileUriObject = new fileuri.FileUri(path);
  console.info("The uri of FileUri is " + fileUriObject.toString());
  ```

## fileuri.getUriFromPath

getUriFromPath(path: string): string

以同步方法获取文件URI。

**系统能力**：SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 文件的沙箱路径 |

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | string | 返回文件URI |

**错误码：**  

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid |

**示例：**

  ```ts
  let filePath = pathDir + "/test";
  let uri = fileuri.getUriFromPath(filePath);
  ```
