# @ohos.bundle.defaultAppManager (默认应用管理)

本模块提供查询默认应用的能力，支持查询当前应用是否是默认应用。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
```

## 权限列表

| 权限                                    | 权限等级    | 描述             |
| --------------------------------------- | ----------- | ---------------- |
| ohos.permission.GET_DEFAULT_APPLICATION | system_core | 默认应用相关权限。 |

权限等级参考[权限等级说明](../../security/accesstoken-overview.md#权限等级说明)


## defaultAppMgr.ApplicationType

默认应用的应用类型。

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

| 名称   | 值 | 说明                                   |
| -------- | -------------------------------------- | -------------------------------------- |
| BROWSER  | "Web Browser" | 默认浏览器。                            |
| IMAGE    | "Image Gallery" | 默认图片查看器。                         |
| AUDIO    | "Audio Player" | 默认音频播放器。                         |
| VIDEO    | "Video Player" | 默认视频播放器。                         |
| PDF      | "PDF Viewer" | 默认PDF文档查看器。                      |
| WORD     | "Word Viewer" | 默认WORD文档查看器。                     |
| EXCEL    | "Excel Viewer" | 默认EXCEL文档查看器。                    |
| PPT      | "PPT Viewer" | 默认PPT文档查看器。                      |

## defaultAppMgr.isDefaultApplication

isDefaultApplication(type: string): Promise\<boolean>

以异步方法根据系统已定义的应用类型判断当前应用是否是该应用类型的默认应用，使用Promise形式返回结果。

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要查询的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值。                           |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<boolean> | Promise形式返回当前应用是否是默认应用，true表示是默认应用，false表示不是默认应用。 |


**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
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

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**参数：**

| 参数名         | 类型                              | 必填   | 说明                                      |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| type  | string                          | 是    | 要查询的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值。                            |
| callback    | AsyncCallback\<boolean> | 是    | 程序启动作为入参的回调函数，返回当前应用是否是默认应用，true表示是默认应用，false表示不是默认应用。 |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
defaultAppMgr.isDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. IsDefaultApplication ? ' + JSON.stringify(data));
 });
```

## defaultAppMgr.getDefaultApplication

getDefaultApplication(type: string, userId?: number): Promise\<BundleInfo>

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型获取默认应用信息，使用Promise形式返回结果。

**需要权限：** ohos.permission.GET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要查询的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| userId  | number | 否    | 用户ID。默认值：调用方所在用户。                        |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Promise形式返回默认应用包信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 17700004 | The specified user ID is not found.       |
| 17700023 | The specified default app does not exist. |
| 17700025 | The specified type is invalid.            |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
defaultAppMgr.getDefaultApplication(defaultAppMgr.ApplicationType.BROWSER)
.then((data) => {
    console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));
})
.catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
});

defaultAppMgr.getDefaultApplication("image/png")
.then((data) => {
    console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));
})
.catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
});
```

## defaultAppMgr.getDefaultApplication

getDefaultApplication(type: string, userId: number, callback: AsyncCallback\<BundleInfo>) : void

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型获取默认应用信息，使用callback形式返回结果。

**需要权限：** ohos.permission.GET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要查询的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| userId  | number | 是    | 用户ID。                           |
| callback    | AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | 是    | 程序启动作为入参的回调函数，返回包信息。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 17700004 | The specified user ID is not found.       |
| 17700023 | The specified default app does not exist. |
| 17700025 | The specified type is invalid.            |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
let userId = 100;
defaultAppMgr.getDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});

defaultAppMgr.getDefaultApplication("image/png", userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});
```

## defaultAppMgr.getDefaultApplication

getDefaultApplication(type: string, callback: AsyncCallback\<BundleInfo>) : void

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型获取默认应用信息，使用callback形式返回结果。

**需要权限：** ohos.permission.GET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要查询的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| callback    | AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | 是    | 程序启动作为入参的回调函数，返回包信息。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 17700004 | The specified user ID is not found.       |
| 17700023 | The specified default app does not exist. |
| 17700025 | The specified type is invalid.            |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
defaultAppMgr.getDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});
defaultAppMgr.getDefaultApplication("image/png", (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});
```

## defaultAppMgr.setDefaultApplication

setDefaultApplication(type: string, elementName: ElementName, userId?: number): Promise\<void>

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型设置默认应用，使用Promise形式返回结果。

**需要权限：** ohos.permission.SET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要设置的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| elementName  | [ElementName](js-apis-bundle-ElementName.md) | 是    | 要设置为默认应用的组件信息。                           |
| userId  | number | 否    | 用户ID。默认值：调用方所在用户。                           |

**返回值：**

| 类型           | 说明                               |
| -------------- | ---------------------------------- |
| Promise\<void> | Promise对象，无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 17700004 | The specified user ID is not found.            |
| 17700025 | The specified type is invalid.                 |
| 17700028 | The specified ability does not match the type. |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
defaultAppMgr.setDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, {
    bundleName: "com.test.app",
    moduleName: "module01",
    abilityName: "MainAbility"
}).then((data) => {
    console.info('Operation successful.');
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
});

let userId = 100;
defaultAppMgr.setDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, {
    bundleName: "com.test.app",
    moduleName: "module01",
    abilityName: "MainAbility"
}, userId).then((data) => {
    console.info('Operation successful.');
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
});

defaultAppMgr.setDefaultApplication("image/png", {
    bundleName: "com.test.app",
    moduleName: "module01",
    abilityName: "MainAbility"
}, userId).then((data) => {
    console.info('Operation successful.');
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
});
```

## defaultAppMgr.setDefaultApplication

setDefaultApplication(type: string, elementName: ElementName, userId: number, callback: AsyncCallback\<void>) : void;

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型设置默认应用，使用callback形式返回结果。

**需要权限：** ohos.permission.SET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要设置的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| elementName  | [ElementName](js-apis-bundle-ElementName.md) | 是    | 要设置为默认应用的组件信息。                           |
| userId  | number | 是    | 用户ID。                           |
| callback    | AsyncCallback\<void> | 是    | 程序启动作为入参的回调函数。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 17700004 | The specified user ID is not found.            |
| 17700025 | The specified type is invalid.                 |
| 17700028 | The specified ability does not match the type. |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
let userId = 100;
defaultAppMgr.setDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, {
    bundleName: "com.test.app",
    moduleName: "module01",
    abilityName: "MainAbility"
}, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful.');
 });

defaultAppMgr.setDefaultApplication("image/png", {
    bundleName: "com.test.app",
    moduleName: "module01",
    abilityName: "MainAbility"
}, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful.');
 });
```

## defaultAppMgr.setDefaultApplication

setDefaultApplication(type: string, elementName: ElementName, callback: AsyncCallback\<void>) : void;

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型设置默认应用，使用callback形式返回结果。

**需要权限：** ohos.permission.SET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要设置的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| elementName  | [ElementName](js-apis-bundle-ElementName.md) | 是    | 要设置为默认应用的组件信息。                           |
| callback    | AsyncCallback\<void> | 是    | 程序启动作为入参的回调函数。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 17700004 | The specified user ID is not found.            |
| 17700025 | The specified type is invalid.                 |
| 17700028 | The specified ability does not match the type. |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
defaultAppMgr.setDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, {
    bundleName: "com.test.app",
    moduleName: "module01",
    abilityName: "MainAbility"
}, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful.');
 });

defaultAppMgr.setDefaultApplication("image/png", {
    bundleName: "com.test.app",
    moduleName: "module01",
    abilityName: "MainAbility"
}, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful.');
 });
```

## defaultAppMgr.resetDefaultApplication

resetDefaultApplication(type: string, userId?: number): Promise\<void>

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型重置默认应用，使用Promise形式返回结果。

**需要权限：** ohos.permission.SET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要重置的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| userId  | number | 否    | 用户ID。默认值：调用方所在用户。                           |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 17700004 | The specified user ID is not found. |
| 17700025 | The specified type is invalid.      |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
let userId = 100;
defaultAppMgr.resetDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, userId)
.then((data) => {
    console.info('Operation successful.');
})
.catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
});

defaultAppMgr.resetDefaultApplication("image/png", userId)
.then((data) => {
    console.info('Operation successful.');
})
.catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
});
```

## defaultAppMgr.resetDefaultApplication

resetDefaultApplication(type: string, userId: number, callback: AsyncCallback\<void>) : void;

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型重置默认应用，使用callback形式返回结果。

**需要权限：** ohos.permission.SET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要重置的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| userId  | number | 是    | 用户ID。                          |
| callback    | AsyncCallback\<void> | 是    | 程序启动作为入参的回调函数。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 17700004 | The specified user ID is not found. |
| 17700025 | The specified type is invalid.      |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
let userId = 100;
defaultAppMgr.resetDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful.');
});

defaultAppMgr.resetDefaultApplication("image/png", userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful.');
});
```

## defaultAppMgr.resetDefaultApplication

resetDefaultApplication(type: string, callback: AsyncCallback\<void>) : void;

以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型重置默认应用，使用callback形式返回结果。

**需要权限：** ohos.permission.SET_DEFAULT_APPLICATION

**系统能力：** SystemCapability.BundleManager.BundleFramework.DefaultApp

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名         | 类型     | 必填   | 说明                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | 是    | 要重置的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。       |
| callback    | AsyncCallback\<void> | 是    | 程序启动作为入参的回调函数。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 17700004 | The specified user ID is not found. |
| 17700025 | The specified type is invalid.      |

**示例：**

```ts
import defaultAppMgr from '@ohos.bundle.defaultAppManager';
defaultAppMgr.resetDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful.');
});

defaultAppMgr.resetDefaultApplication("image/png", (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful.');
});
```