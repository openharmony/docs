# @ohos.file.hash (文件哈希处理)

该模块提供文件哈希处理能力，对文件内容进行哈希处理。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import Hash from '@ohos.file.hash';
```

## 使用说明

使用该功能模块对文件/目录进行操作前，需要先获取其应用沙箱路径，获取方式及其接口用法请参考：

**Stage模型**

 ```js
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
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

## Hash.hash

hash(path: string, algorithm: string): Promise&lt;string&gt;

计算文件的哈希值，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型   | 必填 | 说明                                                         |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| path      | string | 是   | 待计算哈希值文件的应用沙箱路径。                             |
| algorithm | string | 是   | 哈希计算采用的算法。可选&nbsp;"md5"、"sha1"&nbsp;或&nbsp;"sha256"。建议采用安全强度更高的&nbsp;"sha256"。 |

**返回值：**

  | 类型                    | 说明                         |
  | --------------------- | -------------------------- |
  | Promise&lt;string&gt; | Promise对象。返回文件的哈希值。表示为十六进制数字串，所有字母均大写。 |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](../errorcodes/errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  Hash.hash(filePath, "sha256").then((str) => {
    console.info("calculate file hash succeed:" + str);
  }).catch((err) => {
    console.info("calculate file hash failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## Hash.hash

hash(path: string, algorithm: string, callback: AsyncCallback&lt;string&gt;): void

计算文件的哈希值，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型                        | 必填 | 说明                                                         |
| --------- | --------------------------- | ---- | ------------------------------------------------------------ |
| path      | string                      | 是   | 待计算哈希值文件的应用沙箱路径。                             |
| algorithm | string                      | 是   | 哈希计算采用的算法。可选&nbsp;"md5"、"sha1"&nbsp;或&nbsp;"sha256"。建议采用安全强度更高的&nbsp;"sha256"。 |
| callback  | AsyncCallback&lt;string&gt; | 是   | 异步计算文件哈希操作之后的回调函数（其中给定文件哈希值表示为十六进制数字串，所有字母均大写）。 |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](../errorcodes/errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  Hash.hash(filePath, "sha256", (err, str) => {
    if (err) {
      console.info("calculate file hash failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("calculate file hash succeed:" + str);
    }
  });
  ```
