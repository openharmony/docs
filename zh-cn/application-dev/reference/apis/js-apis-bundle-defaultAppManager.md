# Bundle模块(JS端SDK接口)

本模块提供默认应用能力，支持查询当前应用是否是默认应用。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import defaultAppMgr from '@ohos.bundle.defaultAppManager'
```

## defaultAppMgr.isDefaultApplication

isDefaultApplication(type: string): Promise\<boolean>

以异步方法根据给定的type判断当前应用是否是默认应用，使用Promise形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要查询的默认应用名称。                            |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<boolean> | Promise形式返回当前应用是否是默认应用。 |

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

以异步方法根据给定的type判断当前应用是否是默认应用，使用callback形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                              | 必填   | 描述                                      |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| type  | string                          | 是    | 要查询的默认应用名称。                            |
| callback    | AsyncCallback<boolean> | 是    | 程序启动作为入参的回调函数，返回当前应用是否是默认应用。    |

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

