# @ohos.bundle.launcherBundleManager (launcherBundleManager模块)(系统接口)

本模块支持launcher应用所需的查询能力，支持[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)、[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)信息的查询。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
```


## launcherBundleManager.getLauncherAbilityInfo<sup>9+</sup>

getLauncherAbilityInfo(bundleName: string, userId: number, callback: AsyncCallback\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>\>) : void

查询指定bundleName及用户的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |
| userId     | number | 是   | 被查询的用户id。|
| callback | AsyncCallback\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>\> | 是 | callback形式返回bundle包含的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.      |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getLauncherAbilityInfo('com.example.demo', 100,
        (errData: BusinessError, data: launcherBundleManager.LauncherAbilityInfo[]) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.log("data is " + JSON.stringify(data));
        }
    })
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getLauncherAbilityInfo<sup>9+</sup>

getLauncherAbilityInfo(bundleName: string, userId: number) : Promise\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>\>

查询指定bundleName及用户的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |
| userId     | number | 是   | 被查询的用户id。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | -------------------------------------------------- |
| Promise\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>\> | Promise形式返回bundle包含的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.       |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getLauncherAbilityInfo("com.example.demo", 100)
        .then((data: launcherBundleManager.LauncherAbilityInfo[]) => {
        console.log("data is " + JSON.stringify(data));
    }).catch ((errData: BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getLauncherAbilityInfoSync<sup>10+</sup>

getLauncherAbilityInfoSync(bundleName: string, userId: number) : Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>

查询指定bundleName及用户的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |
| userId     | number | 是   | 被查询的用户id。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | -------------------------------------------------- |
| Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\> | Array形式返回bundle包含的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.       |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    let data = launcherBundleManager.getLauncherAbilityInfoSync("com.example.demo", 100);
    console.log("data is " + JSON.stringify(data));
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getAllLauncherAbilityInfo<sup>9+</sup>

getAllLauncherAbilityInfo(userId: number, callback: AsyncCallback\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>\>) : void

查询指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | -------------- |
| userId | number | 是   | 被查询的用户id。 |
| callback | AsyncCallback\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>\> | 是 | callback形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700004 | The specified user ID is not found.      |

示例：

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getAllLauncherAbilityInfo(100,
        (errData: BusinessError, data: launcherBundleManager.LauncherAbilityInfo[]) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.log("data is " + JSON.stringify(data));
        }
    });
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```
## launcherBundleManager.getAllLauncherAbilityInfo<sup>9+</sup>

getAllLauncherAbilityInfo(userId: number) : Promise\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>\>

查询指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | -------------- |
| userId | number | 是   | 被查询的用户id。 |

**返回值：**

| 类型                          | 说明                                                   |
| ----------------------------- | ------------------------------------------------------ |
| Promise\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)\>\> | Promise形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo-sys.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700004 | The specified user ID is not found.      |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getAllLauncherAbilityInfo(100)
        .then((data: launcherBundleManager.LauncherAbilityInfo[]) => {
        console.log("data is " + JSON.stringify(data));
    }).catch ((errData: BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    });
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getShortcutInfo<sup>9+</sup>

getShortcutInfo(bundleName :string, callback: AsyncCallback\<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>\>) : void

查询当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |
| callback | AsyncCallback\<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>\> | 是 | callback形式返回当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getShortcutInfo("com.example.demo",
        (errData: BusinessError, data: launcherBundleManager.ShortcutInfo[]) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.log("data is " + JSON.stringify(data));
        }
    });
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getShortcutInfo<sup>9+</sup>

getShortcutInfo(bundleName : string) : Promise\<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>\>

查询当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |

**返回值：**

| 类型                   | 说明                                            |
| ---------------------- | ----------------------------------------------- |
| Promise\<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>\> | Promise形式返回当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getShortcutInfo("com.example.demo")
        .then((data: launcherBundleManager.ShortcutInfo[]) => {
        console.log("data is " + JSON.stringify(data));
    }).catch ((errData: BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    });
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getShortcutInfoSync<sup>10+</sup>

getShortcutInfoSync(bundleName : string) : Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>

查询当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |

**返回值：**

| 类型                   | 说明                                            |
| ---------------------- | ----------------------------------------------- |
| Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\> | Array形式返回当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    let data = launcherBundleManager.getShortcutInfoSync("com.example.demo");
    console.log("data is " + JSON.stringify(data));
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getShortcutInfoSync<sup>13+</sup>

getShortcutInfoSync(bundleName: string, userId: number) : Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>

查询指定用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |
| userId     | number | 是   | 表示用户ID。  |

**返回值：**

| 类型                   | 说明                                            |
| ---------------------- | ----------------------------------------------- |
| Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\> | Array形式返回指定用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.     |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    let data = launcherBundleManager.getShortcutInfoSync("com.example.demo", 100);
    console.log("data is " + JSON.stringify(data));
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.startShortcut<sup>12+</sup>

startShortcut(shortcutInfo: ShortcutInfo, options?: StartOptions): Promise\<void\>;

拉起指定[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)中的ability。

**需要权限：** ohos.permission.START_SHORTCUT

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名        | 类型   | 必填 | 说明         |
| ------------ | ------ | ---- | -------------- |
| shortcutInfo | [ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md) | 是   | 应用的快捷方式信息。 |
| options      | [StartOptions](js-apis-app-ability-startOptions-sys.md)   | 否   | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700065 | The ability specified by want in the ShortcutInfo struct cannot be started.  |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    let data : Array<launcherBundleManager.ShortcutInfo> = launcherBundleManager.getShortcutInfoSync("com.example.demo");
    console.log("data is " + JSON.stringify(data));
    if (data) {
        try {
            launcherBundleManager.startShortcut(data[0])
                .then(() => {
                console.log("startShortcut success");
            }).catch ((err: BusinessError) => {
                console.error(`errData is errCode:${err.code}  message:${err.message}`);
            });
        } catch (error) {
            let code = (error as BusinessError).code;
            let message = (error as BusinessError).message;
            console.error(`error is errCode:${code}  message:${message}`);
        }
    }
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```
