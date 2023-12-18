# @ohos.bundle.overlay (overlay模块)

本模块提供[overlay特征应用](#overlay特征应用介绍)的安装，overlay特征应用的[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)信息的查询以及overlay特征应用的禁用使能的能力。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

``` ts
import overlay from '@ohos.bundle.overlay';
```

## overlay.setOverlayEnabled

setOverlayEnabled(moduleName:string, isEnabled: boolean): Promise\<void>

以异步方法设置当前应用中overlay特征module的禁用使能状态。使用Promise异步回调。成功返回null，失败返回对应错误信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName  | string | 是    | overlay特征module的HAP名称。               |
| isEnabled   | boolean  | 是  | 值为true表示使能，值为false表示禁用。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700033 | The specified module is not an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let moduleName = "feature";
let isEnabled = false;

try {
    overlay.setOverlayEnabled(moduleName, isEnabled)
        .then(() => {
            console.info('setOverlayEnabled success');
        }).catch((err: BusinessError) => {
            console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.info('setOverlayEnabled failed due to err code: ' + code + ' ' + 'message:' + message);
}
```

## overlay.setOverlayEnabled

setOverlayEnabled(moduleName:string, isEnabled: boolean, callback: AsyncCallback\<void>): void

以异步方法设置当前应用中overlay module的禁用使能状态。使用callback异步回调。成功返回null，失败返回对应错误信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName  | string | 是    | overlay特征module的HAP名称。               |
| isEnabled   | boolean  | 是  | 值为true表示使能，值为false表示禁用。|
| callback    | AsyncCallback\<void> | 是    | 回调函数，当设置指定module的overlay禁用使能状态成功时，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700033 | The specified module is not an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let moduleName = "feature";
let isEnabled = false;

try {
    overlay.setOverlayEnabled(moduleName, isEnabled, (err, data) => {
        if (err) {
            console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
            return;
        }
        console.info('setOverlayEnabled success');
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.info('setOverlayEnabled failed due to err code: ' + code + ' ' + 'message:' + message);
}
```

## overlay.setOverlayEnabledByBundleName

setOverlayEnabledByBundleName(bundleName:string, moduleName:string, isEnabled: boolean): Promise\<void>

以异步方法设置指定应用的overlay module的禁用使能状态。使用Promise异步回调，成功返回应用的处置状态，失败返回对应错误信息。

**需要权限：** ohos.permission.CHANGE_OVERLAY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**系统API：**  此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | 是    | 指定应用的bundle名称。                 |
| moduleName  | string | 是    | 指定应用的overlay module的HAP名称。    |
| isEnabled   | boolean  | 是  | 值为true表示使能，值为false表示禁用。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let bundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";
let isEnabled = false;

try {
    overlay.setOverlayEnabledByBundleName(bundleName, moduleName, isEnabled)
        .then((data) => {
            console.info('setOverlayEnabledByBundleName successfully');
        }).catch((err: BusinessError) => {
            console.info('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.info('setOverlayEnabledByBundleName failed due to err code: ' + code + ' ' + 'message:' + message);
}
```

## overlay.setOverlayEnabledByBundleName

setOverlayEnabledByBundleName(bundleName:string, moduleName:string, isEnabled: boolean, callback: AsyncCallback\<void>): void

以异步方法设置指定应用的overlay module的禁用使能状态。使用callback异步回调，成功返回应用的处置状态，失败返回对应错误信息。

**需要权限：** ohos.permission.CHANGE_OVERLAY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**系统API：**  此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                  |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | 是    | 指定应用的bundle名称。                 |
| moduleName  | string | 是    | 指定应用的overlay特征module的HAP名称。    |
| isEnabled   | boolean  | 是  | 值为true表示使能，值为false表示禁用。 |
| callback    | AsyncCallback\<void> | 是    | 回调函数。当设置指定应用的overlay module的禁用使能状态成功时，err为null，否则为错误对象。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let bundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";
let isEnabled = false;

try {
    overlay.setOverlayEnabledByBundleName(bundleName, moduleName, isEnabled, (err, data) => {
        if (err) {
            console.info('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
            return;
        }
        console.info('setOverlayEnabledByBundleName successfully');
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.info('setOverlayEnabledByBundleName failed due to err code: ' + code + ' ' + 'message:' + message);
}
```

## overlay.getOverlayModuleInfo

getOverlayModuleInfo(moduleName: string): Promise\<OverlayModuleInfo>

以异步方法获取当前应用中指定的module的overlayModuleInfo信息。使用promise异步回调，成功返回null，失败返回对应错误信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | ------------------------------------------ |
| moduleName | string | 是    | 指定当前应用中的overlay module的HAP名称。     |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)> | Promise对象，返回[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)。|

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let moduleName = "feature";

(async() => {
    try {
        let overlayModuleInfo = await overlay.getOverlayModuleInfo(moduleName);
        console.log('overlayModuleInfo is ' + JSON.stringify(overlayModuleInfo));
    } catch(err) {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.log('getOverlayModuleInfo failed due to err code : ' + code + ' ' + 'message :' + message);
    }
})();
```

## overlay.getOverlayModuleInfo

getOverlayModuleInfo(moduleName: string, callback: AsyncCallback\<OverlayModuleInfo>): void

以异步方法获取当前应用中指定的module的overlayModuleInfo信息。使用callback异步回调，成功返回null，失败返回对应错误信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName | string | 是    | 指定当前应用中的overlay特征module的HAP名称。     |
| callback    | AsyncCallback\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)> | 是    | 回调函数，当获取当前应用中指定的module的[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)信息成功时，err返回null。否则回调函数返回具体错误对象。                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let moduleName = "feature";
try {
    overlay.getOverlayModuleInfo(moduleName, (err, data) => {
        if (err) {
            console.log('getOverlayModuleInfo failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log('getOverlayModuleInfo failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getTargetOverlayModuleInfos

getTargetOverlayModuleInfos(targetModuleName: string): Promise\<Array\<OverlayModuleInfo>>

以异步方法获取指定的目标module的OverlayModuleInfo。使用promise异步回调，成功返回null，失败返回对应错误信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| targetModuleName | string | 是    | 指定当前应用中的目标module的HAP名称。     |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Promise对象，返回\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>>。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let targetModuleName = "feature";

(async() => {
    try {
        let overlayModuleInfos = await overlay.getTargetOverlayModuleInfos(targetModuleName);
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
    } catch(err) {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.log('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);
    }
})();
```

## overlay.getTargetOverlayModuleInfos

getTargetOverlayModuleInfos(targetModuleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void

以异步方法获取指定的目标module的OverlayModuleInfo。使用callback异步回调，成功返回null，失败返回对应错误信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| targetModuleName | string | 是    | 指定当前应用中的目标module的HAP名称。     |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | 是    | 回调函数，当获取指定的目标module的[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)成功时，err返回null。否则回调函数返回具体错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found.  |
| 17700034 | The specified module is an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let targetModuleName = "feature";
try {
    overlay.getTargetOverlayModuleInfos(targetModuleName, (err, data) => {
        if (err) {
            console.log('getTargetOverlayModuleInfos failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, moduleName?: string): Promise\<Array\<OverlayModuleInfo>>

以异步方法获取指定应用中指定module的OverlayModuleInfo信息。使用promise异步回调，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**系统API：**  此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | 是    | 指定应用的bundle名称。                    |
| moduleName | string | 否    | 指定应用中的overlay module的HAP名称。默认值：缺省该字段时，查询接口将查询指定应用中所有module的OverlayModuleInfo信息。     |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Promise对象，返回\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>>。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let bundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";

(async() => {
    try {
        let overlayModuleInfos = await overlay.getOverlayModuleInfoByBundleName(bundleName, moduleName);
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
    } catch(err) {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.log('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);
    }
})();
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, moduleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void

以异步方法获取指定应用中指定module的OverlayModuleInfo信息。使用callback异步回调，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**系统API：**  此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | 是    | 指定应用的bundle名称。                    |
| moduleName | string | 是    | 指定应用中的overlay module的HAP名称。缺省该字段时，查询接口将查询指定应用中所有module的OverlayModuleInfo信息。     |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | 是    | 回调函数，当获取指定应用中指定module的[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)信息成功时，err返回null。否则回调函数返回具体错误对象。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let bundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";

try {
    overlay.getOverlayModuleInfoByBundleName(bundleName, moduleName, (err, data) => {
        if (err) {
            console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void

以异步方法获取指定应用中所有module的OverlayModuleInfo信息。使用callback异步回调，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**系统API：**  此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | 是    | 指定应用的bundle名称。                    |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | 是    | 回调函数，当获取指定应用中所有module的[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)信息成功时，err返回null。否则回调函数返回具体错误对象。                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let bundleName = "com.example.myapplication_xxxxx";

try {
    overlay.getOverlayModuleInfoByBundleName(bundleName, (err, data) => {
        if (err) {
            console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, moduleName?: string): Promise\<Array\<OverlayModuleInfo>>

以异步方法获取指定应用中指定module关联的所有OverlayModuleInfo信息。使用promise异步回调，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**系统API：**  此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | 是    | 指定目标应用的bundle名称。                    |
| moduleName | string | 否    | 指定应用中的目标module的HAP名称。默认值：缺省该字段时，查询接口将查询指定应用中所有module所关联的OverlayModuleInfo信息。     |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Promise对象，返回\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>>。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |
| 17700035 | The specified bundle is an overlay bundle. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let targetBundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";

(async() => {
    try {
        let overlayModuleInfos = await overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, moduleName);
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
    } catch(err) {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
    }
})();
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;OverlayModuleInfo&gt;&gt;): void

以异步方法获取指定应用中指定module关联的所有OverlayModuleInfo信息。使用callback异步回调，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**系统API：**  此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | 是    | 指定目标应用的bundle名称。                    |
| moduleName | string | 是    | 指定应用中的目标module的HAP名称。缺省该字段时，查询接口将查询指定应用中所有module所关联的OverlayModuleInfo信息。     |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | 是    | 回调函数，当获取指定应用中指定module关联的所有[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)信息成功时，err返回null。否则回调函数返回具体错误对象。                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |
| 17700035 | The specified bundle is an overlay bundle. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let targetBundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";

try {
    overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, moduleName, (err, data) => {
        if (err) {
            console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, callback: AsyncCallback&lt;Array&lt;OverlayModuleInfo&gt;&gt;): void

以异步方法获取指定应用中所有module关联的所有OverlayModuleInfo信息。使用callback异步回调，成功返回null，失败返回对应错误信息。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Overlay

**系统API：**  此接口为系统接口。

**参数：**

| 参数名       | 类型     | 必填   | 说明                                    |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | 是    | 指定目标应用的bundle名称。                    |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | 是    | 回调函数，当获取指定应用中所有module关联的所有[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)信息成功时，err返回null。否则回调函数返回具体错误对象。                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700035 | The specified bundle is an overlay bundle. |

**示例：**

```ts
import overlay from '@ohos.bundle.overlay';
import { BusinessError } from '@ohos.base';
let targetBundleName = "com.example.myapplication_xxxxx";

try {
    overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, (err, data) => {
        if (err) {
            console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay特征应用介绍

**概念**
overlay特征应用指的是应用中包含有overlay特征的module。该特征module一般是为设备上存在的非overlay特征的module提供额外的资源文件，以便于目标module在运行阶段可以使用这些额外的资源文件来展示不同的颜色，标签，主题等等。overlay特征仅适用与stage模型。

**如何识别overlay特征的module**
在IDE中创建应用工程时, module的配置文件module.json5中包含targetModuleName和targetPriority字段时，该module将会在安装阶段被识别为overlay特征的module。
