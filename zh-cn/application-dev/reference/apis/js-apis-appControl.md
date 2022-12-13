# @ohos.bundle.appControl(appControl模块)

本模块提供应用拦截能力。对应用设置处置状态后，应用会被禁止运行；用户点击桌面图标时，会根据应用的处置状态，跳转到对应的页面。本模块支持对应用的处置状态进行设置、获取、删除。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

本模块接口为系统接口。

## 导入模块

``` ts
import appControl from '@ohos.bundle.appControl'
```

## appControl.setDisposedStatus

setDisposedStatus(appId: string, disposedWant: Want): Promise\<void>

以异步方法设置应用的处置状态。使用Promise异步回调。成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 需要设置处置状态的应用的appId。<br> appId是应用的唯一标识，由应用的包名和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid)。                    |
| disposedWant | Want  | 是 | 对应用的处置意图。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**示例：**

```ts
var appId = "com.example.myapplication_xxxxx";
var want = {bundleName: 'com.example.myapplication'};

try {
    appControl.setDisposedStatus(appId, want)
        .then(() => {
            console.info('setDisposedStatus success');
        }).catch((error) => {
            console.error('setDisposedStatus failed ' + error.message);
        });
} catch (error) {
    console.error('setDisposedStatus failed ' + error.message);
}
```

## appControl.setDisposedStatus

setDisposedStatus(appId: string, disposedWant: Want, callback: AsyncCallback\<void>): void;

以异步方法设置应用的处置状态。使用callback异步回调。成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名       | 类型                              | 必填   | 说明                                    |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| appId  | string | 是    | 需要设置处置的应用的appId<br> appId是应用的唯一标识，由应用的包名和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid)。                           |
| disposedWant | Want  | 是 | 对应用的处置意图。 |
| callback    | AsyncCallback\<void> | 是    | 回调函数，当设置处置状态成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**示例：**

```ts
var appId = "com.example.myapplication_xxxxx";
var want = {bundleName: 'com.example.myapplication'};

try {
    appControl.setDisposedStatus(appId, want, (error, data) => {
        if (error) {
            console.error('setDisposedStatus failed ' + error.message);
            return;
        }
        console.info('setDisposedStatus success');
    });
} catch (error) {
    console.error('setDisposedStatus failed ' + error.message);
}
```

## appControl.getDisposedStatus

getDisposedStatus(appId: string): Promise\<Want>;

以异步方法获取指定应用已设置的处置状态。使用Promise异步回调，成功返回应用的处置状态，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId<br> appId是应用的唯一标识，由应用的包名和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid)。       |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<Want> | Promise对象，返回应用的处置状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**示例：**

```ts
var appId = "com.example.myapplication_xxxxx";

try {
    appControl.getDisposedStatus(appId)
        .then((data) => {
            console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
        }).catch((error) => {
            console.error('getDisposedStatus failed ' + error.message);
        });
} catch (error) {
    console.error('getDisposedStatus failed ' + error.message);
}
```

## appControl.getDisposedStatus

getDisposedStatus(appId: string, callback: AsyncCallback\<Want>): void;

以异步方法获取指定应用的处置状态。使用callback异步回调，成功返回应用的处置状态，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名       | 类型     | 必填   | 说明                                  |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId<br> appId是应用的唯一标识，由应用的包名和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid)。       |
| callback    | AsyncCallback\<Want> | 是    | 回调函数。当获取应用的处置状态成功时，err为undefined，data为获取到的处置状态；否则为错误对象。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**示例：**

```ts
var appId = "com.example.myapplication_xxxxx";

try {
    appControl.getDisposedStatus(appId, (error, data) => {
        if (error) {
            console.error('getDisposedStatus failed ' + error.message);
            return;
        }
        console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));
    });
} catch (error) {
    console.error('getDisposedStatus failed ' + error.message);
}
```

## appControl.deleteDisposedStatus

deleteDisposedStatus(appId: string): Promise\<void>

以异步方法删除应用的处置状态。使用promise异步回调，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要删除处置状态的应用的appId<br> appId是应用的唯一标识，由应用的包名和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid)。       |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象，无返回结果的Promise对象 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**示例：**

```ts
var appId = "com.example.myapplication_xxxxx";

try {
    appControl.deleteDisposedStatus(appId)
        .then(() => {
            console.info('deleteDisposedStatus success');
        }).catch((error) => {
            console.error('deleteDisposedStatus failed ' + error.message);
        });
} catch (error) {
    console.error('deleteDisposedStatus failed ' + error.message);
}
```

## appControl.deleteDisposedStatus

deleteDisposedStatus(appId: string, callback: AsyncCallback\<void>) : void

以异步方法删除应用的处置状态。使用callback异步回调，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS

**系统能力：** SystemCapability.BundleManager.BundleFramework.AppControl

**系统API：**  此接口为系统接口，三方应用不支持调用

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| appId  | string | 是    | 要查询的应用的appId。<br> appId是应用的唯一标识，由应用的包名和签名信息决定，获取方法参见[获取应用的appId](#获取应用的appid)。       |
| callback    | AsyncCallback\<void> | 是    | 回调函数，当设置处置状态成功时，err返回undefined。否则回调函数返回具体错误对象。                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700005 |  The specified app ID is not found.  |

**示例：**

```ts
var appId = "com.example.myapplication_xxxxx";
try {
    appControl.deleteDisposedStatus(appId, (error, data) => {
        if (error) {
            console.error('deleteDisposedStatus failed ' + error.message);
            return;
        }
        console.info('deleteDisposedStatus success');
    });
} catch (error) {
    console.error('deleteDisposedStatus failed ' + error.message);
}
```

## 获取应用的appId

appId是应用的唯一标识，由应用的包名和签名信息决定，可以通过[getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo)接口获取。

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager';

var bundleName = 'com.example.myapplication';
var appId;
try {
    bundleManager.getBundleInfo(bundleName, bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO)
        .then((data) => {
            appId = data.signatureInfo.appId;
            console.info("appId is " + appId);
        }).catch((error) => {
            console.error("getBundleInfo failed " + error.message);
        });
} catch (error) {
    console.error("getBundleInfo failed " + error.message);
}
```