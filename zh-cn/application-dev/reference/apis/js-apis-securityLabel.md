# 数据标签

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

该模块提供文件数据安全等级的相关功能：向应用程序提供查询、设置文件数据安全等级的JS接口。

## 导入模块

```js
import securityLabel from '@ohos.securityLabel';
```

## 使用说明

使用该功能模块对文件/目录进行操作前，需要先获取其应用沙箱路径，获取方式及其接口用法请参考：[Context模块的接口getOrCreateLocalDir](js-apis-Context.md)。

“文件/目录应用沙箱路径”=“应用目录路径”+“文件/目录名”

通过上述接口获取到应用目录路径dir，文件名为“xxx.txt”，文件所在的应用沙箱路径为：

```js
let path = dir + "/xxx.txt";
```

文件描述符fd：

```js
let fd = fileio.openSync(path, 0o102, 0o666);
```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, dataLevel:string):Promise&lt;void&gt;

以异步方法设置数据标签，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.DistributedFile

**参数：**

| 参数名    | 类型   | 必填 | 说明                                         |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | 是   | 文件路径                                     |
| dataLevel | string | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |

**返回值：**

  | 类型                | 说明             |
  | ------------------- | ---------------- |
  | Promise&lt;void&gt; | Promise实例，用于异步获取结果。本调用将返回空值。|

**示例：**

  ```js
  securityLabel.setSecurityLabel(path, dataLevel).then(function(){
      console.info("setSecurityLabel successfully");
  }).catch(function(error){
      console.info("setSecurityLabel failed with error:" + error);
  });
  ```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, dataLevel:string, callback: AsyncCallback&lt;void&gt;):void

以异步方法设置数据标签，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.DistributedFile

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                         |
| --------- | ------------------------- | ---- | -------------------------------------------- |
| path      | string                    | 是   | 文件路径                                     |
| dataLevel | string                    | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |
| callback  | AsyncCallback&lt;void&gt; | 是   | 是否设置数据标签之后的回调                   |

**示例：**

  ```js
  securityLabel.setSecurityLabel(path, dataLevel, function(error){
      console.info("setSecurityLabel:" + JSON.stringify(error));
  });
  ```
## securityLabel.setSecurityLabelSync

setSecurityLabelSync(path:string, dataLevel:string):void

以同步方法设置数据标签。

**系统能力**：SystemCapability.FileManagement.File.DistributedFile

**参数：**

| 参数名    | 类型   | 必填 | 说明                                         |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | 是   | 文件路径                                     |
| dataLevel | string | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |

**示例：**

```js
securityLabel.setSecurityLabelSync(path, dataLevel);
```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string):Promise&lt;string&gt;

异步方法获取数据标签，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.DistributedFile

**参数：**

  | 参数名 | 类型   | 必填 | 说明     |
  | ------ | ------ | ---- | -------- |
  | path   | string | 是   | 文件路径 |

**返回值：**

  | 类型                  | 说明         |
  | --------------------- | ------------ |
  | Promise&lt;string&gt; | 返回数据标签 |

**示例：**

  ```js
  securityLabel.getSecurityLabel(path).then(function(dataLevel){
      console.log("getSecurityLabel successfully:" + dataLevel);
  }).catch(function(error){
      console.log("getSecurityLabel failed with error:" + error);
  });
  ```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string, callback:AsyncCallback&lt;string&gt;): void

异步方法获取数据标签，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.DistributedFile

**参数：**

  | 参数名   | 类型                        | 必填 | 说明                       |
  | -------- | --------------------------- | ---- | -------------------------- |
  | path     | string                      | 是   | 文件路径                   |
  | callback | AsyncCallback&lt;string&gt; | 是   | 异步获取数据标签之后的回调 |

**示例：**

  ```js
  securityLabel.getSecurityLabel(function(error, dataLevel){
      console.log("getSecurityLabel successfully:" + dataLevel);
  });
  ```
## securityLabel.getSecurityLabelSync

getSecurityLabelSync(path:string):string

以同步方法获取数据标签。

**系统能力**：SystemCapability.FileManagement.File.DistributedFile

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| path   | string | 是   | 文件路径 |

**返回值：**

| 类型   | 说明         |
| ------ | ------------ |
| string | 返回数据标签 |

**示例：**

```js
let result = securityLabel.getSecurityLabelSync(path);
console.log("getSecurityLabel successfully:" + result);
```
