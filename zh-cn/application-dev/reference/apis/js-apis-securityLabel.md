# @ohos.securityLabel (数据标签)

该模块提供文件数据安全等级的相关功能：向应用程序提供查询、设置文件数据安全等级的JS接口。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import securityLabel from '@ohos.securityLabel';
```

## 使用说明

使用该功能模块对文件/目录进行操作前，需要先获取其应用沙箱路径，获取方式及其接口用法请参考：

```js
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();
let path = '';
context.getFilesDir().then((data) => {
    path = data;
})
```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:dataLevel):Promise&lt;void&gt;

以异步方法设置数据标签，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型       | 必填 | 说明                                         |
| --------- | ------    | ---- | -------------------------------------------- |
| path      | string    | 是   | 文件路径                                     |
| type      | dataLevel | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |

**返回值：**

  | 类型                | 说明             |
  | ------------------- | ---------------- |
  | Promise&lt;void&gt; | Promise实例，用于异步获取结果。本调用将返回空值。|

**示例：**

  ```js
  securityLabel.setSecurityLabel(path, "s0").then(function(){
      console.info("setSecurityLabel successfully");
  }).catch(function(error){
      console.info("setSecurityLabel failed with error:" + error);
  });
  ```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:dataLevel, callback: AsyncCallback&lt;void&gt;):void

以异步方法设置数据标签，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                         |
| --------- | ------------------------- | ---- | -------------------------------------------- |
| path      | string                    | 是   | 文件路径                                     |
| type      | dataLevel                 | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |
| callback  | AsyncCallback&lt;void&gt; | 是   | 是否设置数据标签之后的回调                   |

**示例：**

  ```js
  securityLabel.setSecurityLabel(path, "s0", function(error){
      console.info("setSecurityLabel:" + JSON.stringify(error));
  });
  ```
## securityLabel.setSecurityLabelSync

setSecurityLabelSync(path:string, type:dataLevel):void

以同步方法设置数据标签。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型   | 必填 | 说明                                         |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | 是   | 文件路径                                     |
| type      | dataLevel | 是   | 文件等级属性，只支持"s0","s1","s2","s3","s4" |

**示例：**

```js
securityLabel.setSecurityLabelSync(path, "s0");
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

**示例：**

  ```js
  securityLabel.getSecurityLabel(path).then(function(type){
      console.log("getSecurityLabel successfully:" + type);
  }).catch(function(err){
      console.log("getSecurityLabel failed with error:" + err);
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

**示例：**

  ```js
  securityLabel.getSecurityLabel(path, function(err, type){
      console.log("getSecurityLabel successfully:" + type);
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

**示例：**

```js
let result = securityLabel.getSecurityLabelSync(path);
console.log("getSecurityLabel successfully:" + result);
```
