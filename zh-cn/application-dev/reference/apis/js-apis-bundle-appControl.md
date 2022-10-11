# 应用拦截管理

本模块提供应用拦截能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import appControl from '@ohos.bundle.appControl'
```

## appControl.setDisposedStatus

**function** setDisposedStatus(appId: **string**, disposedWant: **Want**): Promise\<**void**>

以异步方法设置应用的处置，使用Promise形式返回结果，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 需要设置处置的应用的appId                           |
| disposedWant | Want(js-apis-application-Want.md) | 是 | 对应用的处置 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise形式返回设置的结果，成功返回null，失败返回对应错误信息 |

**相关错误码**

| 错误码 | 错误信息                                |
| ------ | -------------------------------------- |
| 201    | Permission denied.                     |
| 401 | The parameter check failed.               |
| 801 | Capacity not supported.                   |
| 17700005 |  The specified appId was not found.  |

**示例：**

```js
import appControl from '@ohos.bundle.appControl'

var addId = "xxx";
var want = {bundleName: "xxxx"};

try {
    appControl.setDisposedStatus(appId, want)
        .then( () => {
            console.log("setDisposedStatus success");
        }, error => {
            console.error("setDisposedStatus failed" + error.code + " " + error.message);
    });
} catch (error) {
    console.error("param check failed" + error.code + " " + error.message);
}
```

## appControl.setDisposedStatus

**function** setDisposedStatus(appId: **string**, disposedWant: **Want**, callback: AsyncCallback\<**void**>): **void**;

以异步方法设置应用的处置，使用callback形式返回结果，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 名称          | 类型                              | 必填   | 描述                                      |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| appId  | string | 是    | 需要设置处置的应用的appId                           |
| disposedWant | Want(js-apis-application-Want.md) | 是 | 对应用的处置 |
| callback    | AsyncCallback\<void> | 是    | 程序启动作为入参的回调函数 |

**相关错误码**

| 错误码 | 错误信息                                |
| ------ | -------------------------------------- |
| 201    | Permission denied.                     |
| 401 | The parameter check failed.               |
| 801 | Capacity not supported.                   |
| 17700005 |  The specified appId was not found.  |

**示例：**

```js
import appControl from '@ohos.bundle.appControl'

var addId = "xxx";

try {
    appControl.setDisposedStatus(appId, want, (err, data) => {
        if (err) {
            console.error("setDisposedStatus failed" + error.code + " " + error.message);
            return;
        }
        console.log("setDisposedStatus success");
    });
} catch (error) {
    console.error("param check error" + error.code + " " + error.message);
}
```

## appControl.getDisposedStatus

**function** getDisposedStatus(appId: **string**): Promise\<**Want**>;

以异步方法获取指定应用已设置的处置，使用Promise形式返回结果，成功返回对应用的处置，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId       |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<[Want](js-apis-application-Want.md)> | Promise形式返回对应用的处置。 |

**相关错误码**

| 错误码 | 错误信息                                |
| ------ | -------------------------------------- |
| 201    | Permission denied.                     |
| 401 | The parameter check failed.               |
| 801 | Capacity not supported.                   |
| 17700005 |  The specified appId was not found.  |

**示例：**

```js
import appControl from '@ohos.bundle.appControl'

var addId = "xxx";

try {
    appControl.getDisposedStatus(appId)
    .then((data) => {
        console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
    })
    .catch((error) => {
        console.error('getDisposedStatus failed' + error.code + " " + error.message);
    });
} catch (error) {
    console.error("param check error" + error.code + " " + error.message)
}
```

## appControl.getDisposedStatus

**function** getDisposedStatus(appId: **string**, callback: AsyncCallback\<**Want**>): **void**;

以异步方法获取指定应用已设置的处置，使用Promise形式返回结果，成功返回对应用的处置，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId        |
| callback    | AsyncCallback\<[Want](js-apis-application-Want.md)> | 是    | 程序启动作为入参的回调函数                    |

**相关错误码**

| 错误码 | 错误信息                                |
| ------ | -------------------------------------- |
| 201    | Permission denied.                     |
| 401 | The parameter check failed.               |
| 801 | Capacity not supported.                   |
| 17700005 |  The specified appId was not found.  |

**示例：**

```js
import appControl from '@ohos.bundle.appControl'

var addId = "xxx";

try {
    appControl.getDisposedStatus(appId, (err, data) => {
        if (err) {
            console.error('getDisposedStatus failed' + error.code + " " + error.message);
            return;
        }
        console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
    });
} catch (error) {
    console.error("param check error" + error.code + " " + error.message)
}
```

## appControl.deleteDisposedStatus

**function** deleteDisposedStatus(appId: **string**, callback: AsyncCallback\<**void**>) : **void**

以异步方法删除对应用的处置，使用callback形式返回结果，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId。       |
| callback    | AsyncCallback\<[void]> | 是    | 程序启动作为入参的回调函数，返回删除结果。                    |

**相关错误码**

| 错误码 | 错误信息                                |
| ------ | -------------------------------------- |
| 201    | Permission denied.                     |
| 401 | The parameter check failed.               |
| 801 | Capacity not supported.                   |
| 17700005 |  The specified appId was not found.  |

**示例：**

```js
import appControl from '@ohos.bundle.appControl'

var addId = "xxx";

try {
    appControl.deleteDisposedStatus(appId, (err, data) => {
        if (err) {
            console.error("deleteDisposedStatus failed" + error.code + " " + error.message);
            return;
        }
        console.log("deleteDisposedStatus success");
    });
} catch (error) {
    console.error("param check error" + error.code + " " + error.message);
}

```

## appControl.deleteDisposedStatus

**function** deleteDisposedStatus(appId: **string**): Promise\<**void**>

以异步方法删除对应用的处置，以promise的形式返回结果，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要删除处置的应用的appId       |                        |

**相关错误码**

| 错误码 | 错误信息                                |
| ------ | -------------------------------------- |
| 201    | Permission denied.                     |
| 401 | The parameter check failed.               |
| 801 | Capacity not supported.                   |
| 17700005 |  The specified appId was not found.  |

**示例：**

```js
import appControl from '@ohos.bundle.appControl'

var addId = "xxx";

try {
    appControl.deleteDisposedStatus(appId)
        .then( () => {
            console.log("deleteDisposedStatus success");
        }, error => {
            console.error("deleteDisposedStatus failed" + error.code + " " + error.message);
    });
} catch (error) {
    console.error("param check error" + error.code + " " + error.message);
}
```