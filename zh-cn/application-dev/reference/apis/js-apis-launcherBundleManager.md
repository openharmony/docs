# @ohos.bundle.launcherBundleManager (launcherBundleManager模块)

本模块支持launcher应用所需的查询能力，支持[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)、[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)信息的查询。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
```


## launcherBundlemanager.getLauncherAbilityInfo<sup>9+</sup>

getLauncherAbilityInfo(bundleName: string, userId: number, callback: AsyncCallback<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>>) : void;

查询指定bundleName及用户的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |
| userId     | number | 是   | 被查询的用户id。|

**返回值：**

| 类型                                | 说明                                                |
| ----------------------------------- | --------------------------------------------------- |
| AsyncCallback\<Array<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>> | callback形式返回bundle包含的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified userId is not found.      |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getLauncherAbilityInfo('com.example.demo', 100, (errData, data) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.log("data is " + JSON.stringify(data));
        }
    })
} catch (errData) {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## launcherBundlemanager.getLauncherAbilityInfo<sup>9+</sup>

getLauncherAbilityInfo(bundleName: string, userId: number) : Promise<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>>;

查询指定bundleName及用户的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |
| userId     | number | 是   | 被查询的用户id。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | -------------------------------------------------- |
| Promise\<Array<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>> | Promise形式返回bundle包含的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified userId is not found.       |

**示例：**

```typescript
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getLauncherAbilityInfo("com.example.demo", 100).then(data => {
        console.log("data is " + JSON.stringify(data));
    }).catch (errData => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
} catch (errData) {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## launcherBundlemanager.getAllLauncherAbilityInfo<sup>9+</sup>

getAllLauncherAbilityInfo(userId: number, callback: AsyncCallback<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>>) : void;

查询指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | -------------- |
| userId | number | 是   | 被查询的用户id。 |

**返回值：**

| 类型                                | 说明                                                    |
| ----------------------------------- | ------------------------------------------------------- |
| AsyncCallback\<Array<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>> | callback形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 17700004 | The specified userId is not found.      |

示例：

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getAllLauncherAbilityInfo(100, (errData, data) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.log("data is " + JSON.stringify(data));
        }
    });
} catch (errData) {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```
## launcherBundlemanager.getAllLauncherAbilityInfo<sup>9+</sup>

getAllLauncherAbilityInfo(userId: number) : Promise<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>>;

查询指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | -------------- |
| userId | number | 是   | 被查询的用户id。 |

**返回值：**

| 类型                          | 说明                                                   |
| ----------------------------- | ------------------------------------------------------ |
| Promise\<Array<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)>> | Promise形式返回指定用户下所有应用的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 17700004 | The specified userId is not found.      |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getAllLauncherAbilityInfo(100).then(data => {
        console.log("data is " + JSON.stringify(data));
    }).catch (errData => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    });
} catch (errData) {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## launcherBundlemanager.getShortcutInfo<sup>9+</sup>

getShortcutInfo(bundleName :string, callback: AsyncCallback<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>>) : void;

查询当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| AsyncCallback\<Array<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>> | callback形式返回当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 17700001 | The specified bundle name is not found.  |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getShortcutInfo("com.example.demo", (errData, data) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.log("data is " + JSON.stringify(data));
        }
    });
} catch (errData) {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```

## launcherBundlemanager.getShortcutInfo<sup>9+</sup>

getShortcutInfo(bundleName : string) : Promise<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>>;

查询当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |

**返回值：**

| 类型                   | 说明                                            |
| ---------------------- | ----------------------------------------------- |
| Promise\<Array<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>> | Promise形式返回当前用户下指定应用的[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                |
| -------- | ---------------------------------------- |
| 17700001 | The specified bundle name is not found.  |

**示例：**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';

try {
    launcherBundleManager.getShortcutInfo("com.example.demo").then(data => {
        console.log("data is " + JSON.stringify(data));
    }).catch (errData => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    });
} catch (errData) {
    console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
}
```
