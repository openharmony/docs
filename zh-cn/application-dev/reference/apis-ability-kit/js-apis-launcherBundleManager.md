# @ohos.bundle.launcherBundleManager (launcherBundleManager模块)

本模块支持launcher应用所需的查询能力，支持[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)信息的查询。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { launcherBundleManager } from '@kit.AbilityKit';
```

## launcherBundleManager.getLauncherAbilityInfoSync<sup>18+</sup>

getLauncherAbilityInfoSync(bundleName: string, userId: number) : Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>

查询指定bundleName及用户的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

**参数：**

| 参数名     | 类型   | 必填 | 说明         |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是   | 应用Bundle名称。 |
| userId     | number | 是   | 被查询的用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | -------------------------------------------------- |
| Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\> | Array形式返回bundle包含的[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.       |

**示例：**

```ts
import { launcherBundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let data = launcherBundleManager.getLauncherAbilityInfoSync("com.example.demo", 100);
    console.log("data is " + JSON.stringify(data));
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## LauncherAbilityInfo<sup>18+</sup>

type LauncherAbilityInfo = _LauncherAbilityInfo

LauncherAbilityInfo信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Launcher

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md) | 桌面应用的Ability信息。 |