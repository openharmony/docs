# Bundle模块(JS端SDK接口)

本模块提供查询默认应用的能力，支持查询当前应用是否是默认应用。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import defaultAppMgr from '@ohos.bundle.defaultAppManager'
```
## defaultAppMgr.ApplicationType

应用类型

**系统能力：**

SystemCapability.BundleManager.BundleFramework

| 名称      | 类型     | 说明                                   |
| -------- | -------- | -------------------------------------- |
| BROWSER  | string   | 默认浏览器。                            |
| IMAGE    | string   | 默认图片查看器。                         |
| AUDIO    | string   | 默认音频播放器。                         |
| VIDEO    | string   | 默认视频播放器。                         |
| PDF      | string   | 默认PDF文档查看器。                      |
| WORD     | string   | 默认WORD文档查看器。                     |
| EXCEL    | string   | 默认EXCEL文档查看器。                    |
| PPT      | string   | 默认PPT文档查看器。                      |

## defaultAppMgr.isDefaultApplication

isDefaultApplication(type: string): Promise\<boolean>

以异步方法根据系统已定义的应用类型判断当前应用是否是该应用类型的默认应用，使用Promise形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要查询的默认应用名称，取[ApplicationType](#defaultappmgrapplicationtype)中的值。                           |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<boolean> | Promise形式返回当前应用是否是默认应用，true表示是默认应用，false表示不是默认应用。 |

**示例：**

```js
defaultAppMgr.isDefaultApplication(defaultAppMgr.ApplicationType.BROWSER)
.then((data) => {
    console.info('Operation successful. IsDefaultApplication ? ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
});
```

## defaultAppMgr.isDefaultApplication

isDefaultApplication(type: string, callback: AsyncCallback\<boolean>): void

以异步方法根据系统已定义的应用类型判断当前应用是否是该应用类型的默认应用，使用callback形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                              | 必填   | 描述                                      |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| type  | string                          | 是    | 要查询的默认应用名称，取[ApplicationType](#defaultappmgrapplicationtype)中的值。                            |
| callback    | AsyncCallback<boolean> | 是    | 程序启动作为入参的回调函数，返回当前应用是否是默认应用，true表示是默认应用，false表示不是默认应用。 |

**示例：**

```js
defaultAppMgr.isDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. IsDefaultApplication ? ' + JSON.stringify(data));
 });
```

