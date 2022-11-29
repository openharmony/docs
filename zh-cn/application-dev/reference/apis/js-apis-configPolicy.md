# 配置策略

配置策略提供按预先定义的定制配置层级获取对应定制配置目录和文件路径的能力。

>  **说明：**
>
>  本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  本模块接口均为系统接口。

## 导入模块

```js
import configPolicy from '@ohos.configPolicy';
```

## getOneCfgFile

getOneCfgFile(relPath: string, callback: AsyncCallback&lt;string&gt;)

使用callback形式返回指定文件名的最高优先级配置文件路径。
例如，config.xml在设备中存在以下路径（优先级从低到高）：/system/etc/config.xml、/sys_pod/etc/config.xml，最终返回/sys_pod/etc/config.xml。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：** 

| 参数名      | 类型                          | 必填   | 说明                    |
| -------- | --------------------------- | ---- | --------------------- |
| relPath  | string                      | 是    | 配置文件名                 |
| callback | AsyncCallback&lt;string&gt; | 是    | 异步回调，用于返回最高优先级配置文件的路径 |

**示例：** 
  ```js
  configPolicy.getOneCfgFile('etc/config.xml', (error, value) => {
      if (error == null) {
          console.log("value is " + value);
      } else {
          console.log("error occurs "+ error);
      }
  });
  ```


## getOneCfgFile

getOneCfgFile(relPath: string): Promise&lt;string&gt;

使用Promise形式返回指定文件名的最高优先级配置文件路径。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：** 

| 参数名     | 类型     | 必填   | 说明    |
| ------- | ------ | ---- | ----- |
| relPath | string | 是    | 配置文件名 |

**返回值：** 

| 类型                    | 说明           |
| --------------------- | ------------ |
| Promise&lt;string&gt; | 最高优先级配置文件的路径 |

**示例：** 
  ```js
  configPolicy.getOneCfgFile('etc/config.xml').then(value => {
      console.log("value is " + value);
  }).catch(error => {
      console.log("getOneCfgFile promise " + error);
  });
  ```


## getCfgFiles

getCfgFiles(relPath: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;)

按优先级从低到高，使用callback形式返回指定文件名所有的文件列表。
例如，config.xml在设备中存在以下路径（优先级从低到高）：/system/etc/config.xml、/sys_pod/etc/config.xml，最终返回/system/etc/config.xml, /sys_pod/etc/config.xml。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明            |
| -------- | ---------------------------------------- | ---- | ------------- |
| relPath  | string                                   | 是    | 配置文件名         |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 异步回调，用于返回文件列表 |

**示例：** 
  ```js
  configPolicy.getCfgFiles('etc/config.xml', (error, value) => {
      if (error == null) {
          console.log("value is " + value);
      } else {
          console.log("error occurs "+ error);
      }
  });
  ```


## getCfgFiles

getCfgFiles(relPath: string): Promise&lt;Array&lt;string&gt;&gt;

按优先级从低到高，使用Promise形式返回指定文件名所有的文件列表。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：** 

| 参数名     | 类型     | 必填   | 说明    |
| ------- | ------ | ---- | ----- |
| relPath | string | 是    | 配置文件名 |

**返回值：** 

| 类型                                 | 说明   |
| ---------------------------------- | ---- |
| Promise&lt;Array&lt;string&gt;&gt; | 文件列表 |

**示例：** 
  ```js
  configPolicy.getCfgFiles('etc/config.xml').then(value => {
      console.log("value is " + value);
  }).catch(error => {
      console.log("getCfgFiles promise " + error);
  });
  ```


## getCfgDirList

getCfgDirList(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;)

使用callback形式返回配置层级目录列表。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                |
| -------- | ---------------------------------------- | ---- | ----------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是    | 异步回调，用于返回配置层级目录列表 |

**示例：** 
  ```js
  configPolicy.getCfgDirList((error, value) => {
      if (error == null) {
          console.log("value is " + value);
      } else {
          console.log("error occurs "+ error);
      }
  });
  ```


## getCfgDirList

getCfgDirList(): Promise&lt;Array&lt;string&gt;&gt;

使用Promise形式返回配置层级目录列表。

**系统能力**：SystemCapability.Customization.ConfigPolicy

**返回值：** 

| 类型                                 | 说明       |
| ---------------------------------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | 配置层级目录列表 |

**示例：** 
  ```js
  configPolicy.getCfgDirList().then(value => {
      console.log("value is " + value);
  }).catch(error => {
      console.log("getCfgDirList promise " + error);
  });
  ```

