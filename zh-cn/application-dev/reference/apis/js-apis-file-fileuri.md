# @ohos.file.fileuri (文件URI)

该模块提供通过PATH获取文件统一资源标志符（Uniform Resource Identifier，URI），后续可通过使用[@ohos.file.fs](js-apis-file-fs.md)进行相关open、read、write等操作，实现文件分享。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import fileuri from "@ohos.file.fileuri";
```

使用该功能模块前，需要先获取其应用沙箱路径，开发示例如下：

 ```js
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
        let context = this.context;
        let pathDir = context.filesDir;
    }
}
 ```

## fileUri.getUriFromPath

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

  ```js
let filePath = pathDir + "test.txt";
let uri = fileuri.getUriFromPath(filePath);
  ```
