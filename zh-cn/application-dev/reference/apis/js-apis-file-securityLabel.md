# @ohos.file.securityLabel (数据标签)

该模块提供文件数据安全等级的相关功能：向应用程序提供查询、设置文件数据安全等级的JS接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import securityLabel from '@ohos.file.securityLabel';
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

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:DataLevel):Promise&lt;void&gt;

以异步方法设置数据标签，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型       | 必填 | 说明                                         |
| --------- | ------    | ---- | -------------------------------------------- |
| path      | string    | 是   | 文件路径                                     |
| type      | DataLevel | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |

**返回值：**

  | 类型                | 说明             |
  | ------------------- | ---------------- |
  | Promise&lt;void&gt; | Promise实例，用于异步获取结果。本调用将返回空值。|

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](../errorcodes/errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**示例：**

  ```js
  let filePath = pathDir + '/test.txt';
  securityLabel.setSecurityLabel(filePath, "s0").then(() => {
      console.info("setSecurityLabel successfully");
  }).catch((err) => {
      console.info("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:DataLevel, callback: AsyncCallback&lt;void&gt;):void

以异步方法设置数据标签，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                         |
| --------- | ------------------------- | ---- | -------------------------------------------- |
| path      | string                    | 是   | 文件路径                                     |
| type      | DataLevel                 | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |
| callback  | AsyncCallback&lt;void&gt; | 是   | 是否设置数据标签之后的回调                   |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](../errorcodes/errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**示例：**

  ```js
  let filePath = pathDir + '/test.txt';
  securityLabel.setSecurityLabel(filePath, "s0", (err) => {
    if (err) {
      console.info("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("setSecurityLabel successfully.");
    }
  });
  ```

## securityLabel.setSecurityLabelSync

setSecurityLabelSync(path:string, type:DataLevel):void

以同步方法设置数据标签。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型   | 必填 | 说明                                         |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | 是   | 文件路径                                     |
| type      | DataLevel | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](../errorcodes/errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**示例：**

```js
let filePath = pathDir + '/test.txt';
securityLabel.setSecurityLabelSync(filePath, "s0");
```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string):Promise&lt;string&gt;

异步方法获取数据标签，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名 | 类型   | 必填 | 说明     |
  | ------ | ------ | ---- | -------- |
  | path   | string | 是   | 文件路径 |

**返回值：**

  | 类型                  | 说明         |
  | --------------------- | ------------ |
  | Promise&lt;string&gt; | 返回数据标签 |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](../errorcodes/errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**示例：**

  ```js
  let filePath = pathDir + '/test.txt';
  securityLabel.getSecurityLabel(filePath).then((type) => {
      console.log("getSecurityLabel successfully, Label: " + type);
  }).catch((err) => {
      console.log("getSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string, callback:AsyncCallback&lt;string&gt;): void

异步方法获取数据标签，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名   | 类型                        | 必填 | 说明                       |
  | -------- | --------------------------- | ---- | -------------------------- |
  | path     | string                      | 是   | 文件路径                   |
  | callback | AsyncCallback&lt;string&gt; | 是   | 异步获取数据标签之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](../errorcodes/errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**示例：**

  ```js
  let filePath = pathDir + '/test.txt';
  securityLabel.getSecurityLabel(filePath, (err, type) => {
    if (err) {
      console.log("getSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.log("getSecurityLabel successfully, Label: " + type);
    }
  });
  ```

## securityLabel.getSecurityLabelSync

getSecurityLabelSync(path:string):string

以同步方法获取数据标签。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| path   | string | 是   | 文件路径 |

**返回值：**

| 类型   | 说明         |
| ------ | ------------ |
| string | 返回数据标签 |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](../errorcodes/errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**示例：**

```js
let filePath = pathDir + '/test.txt';
let type = securityLabel.getSecurityLabelSync(filePath);
console.log("getSecurityLabel successfully, Label: " + type);
```
