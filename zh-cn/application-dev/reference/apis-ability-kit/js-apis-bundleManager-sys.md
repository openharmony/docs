# @ohos.bundle.bundleManager (bundleManager模块)(系统接口)

本模块提供应用信息查询能力，支持[BundleInfo](js-apis-bundleManager-bundleInfo.md)、[ApplicationInfo](js-apis-bundleManager-ApplicationInfo-sys.md)、[AbilityInfo](js-apis-bundleManager-abilityInfo.md)、[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)等信息的查询。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[`@ohos.bundle.bundleManager`](js-apis-bundleManager.md)。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## BundleFlag

包信息标志，指示需要获取的包信息的内容，当前页面仅包含本模块的系统接口，其他公开类型参见[BundleFlag](./js-apis-bundleManager.md#bundleflag)。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 名称                                          | 值         | 说明                                                         |
| --------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_BUNDLE_INFO_ONLY_WITH_LAUNCHER_ABILITY<sup>12+</sup> | 0x00001000 | 用于获取仅包含有桌面图标的应用的bundleInfo。它仅在[getAllBundleInfo](#bundlemanagergetallbundleinfo)接口中生效。 <br/>**系统API：** 该标记仅支持在系统API中使用。|
| GET_BUNDLE_INFO_OF_ANY_USER<sup>12+</sup>      | 0x00002000 | 用于获取任意用户安装的bundleInfo。它不能单独使用，需要与GET_BUNDLE_INFO_WITH_APPLICATION一起使用。它仅在[getBundleInfo](#bundlemanagergetbundleinfo14)、[getAllBundleInfo](#bundlemanagergetallbundleinfo)接口生效。<br/>**系统API：** 该标记仅支持在系统API中使用。 |
| GET_BUNDLE_INFO_EXCLUDE_CLONE<sup>12+</sup> | 0x00004000 | 用于获取去除分身应用而仅包含主应用的bundleInfo。它仅在[getAllBundleInfo](#bundlemanagergetallbundleinfo)接口中生效。 <br/>**系统API：** 该标记仅支持在系统API中使用。|

## ApplicationFlag

应用信息标志，指示需要获取的应用信息的内容。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称                                 | 值         | 说明                                                         |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| GET_APPLICATION_INFO_DEFAULT         | 0x00000000 | 用于获取默认的applicationInfo，获取的applicationInfo不包含permission和metadata信息。 |
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000001 | 用于获取包含permission的applicationInfo。                    |
| GET_APPLICATION_INFO_WITH_METADATA   | 0x00000002 | 用于获取包含metadata的applicationInfo。                      |
| GET_APPLICATION_INFO_WITH_DISABLE    | 0x00000004 | 用于获取包含禁用应用程序的applicationInfo。                  |

## AbilityFlag

Ability组件信息标志，指示需要获取的Ability组件信息的内容。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称                              | 值         | 说明                                                         |
| --------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_ABILITY_INFO_DEFAULT          | 0x00000000 | 用于获取默认abilityInfo，获取的abilityInfo不包含permission、metadata和禁用的abilityInfo。 |
| GET_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | 用于获取包含permission的abilityInfo。                          |
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | 用于获取包含applicationInfo的abilityInfo。                     |
| GET_ABILITY_INFO_WITH_METADATA    | 0x00000004 | 用于获取包含metadata的abilityInfo。                            |
| GET_ABILITY_INFO_WITH_DISABLE     | 0x00000008 | 用于获取包含禁用的abilityInfo的abilityInfo。                   |
| GET_ABILITY_INFO_ONLY_SYSTEM_APP  | 0x00000010 | 用于仅为系统应用程序获取abilityInfo。                         |
| GET_ABILITY_INFO_WITH_APP_LINKING<sup>12+</sup>  | 0x00000040 | 用于获取通过域名校验筛选的abilityInfo。                         |
| GET_ABILITY_INFO_WITH_SKILL<sup>12+</sup>   | 0x00000080 | 用于获取包含skills的abilityInfo。                         |

## ExtensionAbilityFlag

扩展组件信息标志，指示需要获取的扩展组件信息的内容。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称                                        | 值         | 说明                                                         |
| ------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_EXTENSION_ABILITY_INFO_DEFAULT          | 0x00000000 | 用于获取默认extensionAbilityInfo。获取的extensionAbilityInfo不包含permission、metadata 和禁用的abilityInfo。 |
| GET_EXTENSION_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | 用于获取包含permission的extensionAbilityInfo。               |
| GET_EXTENSION_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | 用于获取包含applicationInfo的extensionAbilityInfo。         |
| GET_EXTENSION_ABILITY_INFO_WITH_METADATA    | 0x00000004 | 用于获取包含metadata的extensionAbilityInfo。                 |
| GET_EXTENSION_ABILITY_INFO_WITH_SKILL<sup>12+</sup>     | 0x00000010 | 用于获取包含skills的extensionAbilityInfo。                 |

## ProfileType<sup>11+</sup>

标识配置文件类型。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称           | 值   | 说明            |
| -------------- | ---- | --------------- |
| INTENT_PROFILE  | 1    | 意图框架配置文件。    |

## AppDistributionType<sup>12+</sup>

标识应用[分发类型](../../security/app-provision-structure.md)。

 **系统能力：** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：** 此接口为系统接口。

| 名称              | 值   | 说明            |
| ----------------- | ---- | --------------- |
| APP_GALLERY       | 1    | 应用市场分发的应用。    |
| ENTERPRISE        | 2    | 企业应用，可以安装到个人设备上。    |
| ENTERPRISE_NORMAL | 3    | 普通企业应用，只能通过企业MDM应用安装在企业设备上。无需设备管理特权。    |
| ENTERPRISE_MDM    | 4    | 企业MDM应用，只能安装在企业设备上。需要设备管理特权，比如远程锁定，安装普通企业应用等。    |
| OS_INTEGRATION    | 5    | 系统预置应用。    |
| CROWDTESTING      | 6    | 众包测试应用。    |
| NONE              | 7    | 其他。           |

## ApplicationInfoFlag<sup>12+</sup>
标识应用和用户之间的各种状态类型。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称 | 值 | 说明 |
|----------------|---|---|
| FLAG_INSTALLED|  0x00000001 | 表示指定用户安装应用的状态为已安装状态。 |
| FLAG_OTHER_INSTALLED<sup>15+</sup>|  0x00000010 | 表示除指定用户外，其他用户的应用安装状态为已安装。|
| FLAG_PREINSTALLED_APP<sup>15+</sup>|  0x00000020 | 表示应用的预置属性为预置应用。|
| FLAG_PREINSTALLED_APP_UPDATE<sup>15+</sup>|  0x00000040 | 表示该预置应用的更新状态为已更新。|

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void

根据给定的bundleName、bundleFlags和userId获取BundleInfo，使用callback异步回调。

获取调用方自身的信息时不需要权限。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 表示要查询的应用Bundle名称。 |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 指定返回的BundleInfo所包含的信息。|
| userId      | number | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。  |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的bundleInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
// 额外获取AbilityInfo
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_ABILITY;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

```ts
// 额外获取ApplicationInfo中的metadata
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

根据给定的bundleName和bundleFlags获取BundleInfo，使用callback异步回调。

获取调用方自身的信息时不需要权限。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 表示要查询的应用Bundle名称。 |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 指定返回的BundleInfo所包含的信息。|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的BundleInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
// 额外获取extensionAbility
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<BundleInfo>

根据给定的bundleName、bundleFlags和userId获取BundleInfo，使用Promise异步回调。

获取调用方自身的信息时不需要权限。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 表示要查询的应用Bundle名称。 |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 指定返回的BundleInfo所包含的信息。       |
| userId      | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。  |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise对象，返回BundleInfo。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
// 额外获取ApplicationInfo和SignatureInfo
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);
}

```

## bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void

根据给定的bundleName、appFlags和userId获取ApplicationInfo，使用callback异步回调。

获取调用方自身的信息时不需要权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | 是   | 表示要查询的应用Bundle名称。 |
| appFlags   | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。    |
| userId     | number | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。  |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的ApplicationInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: number, callback: AsyncCallback\<ApplicationInfo>): void

根据给定的bundleName和appFlags获取ApplicationInfo，使用callback异步回调。

获取调用方自身的信息时不需要权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | 是   | 表示要查询的应用Bundle名称。 |
| appFlags   | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。    |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的ApplicationInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: number, userId?: number): Promise\<ApplicationInfo>

根据给定的bundleName、appFlags和userId获取ApplicationInfo，使用Promise异步回调。

获取调用方自身的信息时不需要权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | 是   | 表示要查询的应用Bundle名称。 |
| appFlags   | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。    |
| userId     | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                                                         | 说明                             |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Promise对象，返回ApplicationInfo。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getApplicationInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, userId: number, callback: AsyncCallback<Array\<BundleInfo>>): void

根据给定的bundleFlags和userId获取系统中所有的BundleInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                             |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 指定返回的BundleInfo所包含的信息。                    |
| userId      | number | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。                      |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Array\<BundleInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                         |
| -------- | --------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    bundleManager.getAllBundleInfo(bundleFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, callback: AsyncCallback<Array\<BundleInfo>>): void

根据给定的bundleFlags获取系统中所有的BundleInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                             |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 指定返回的BundleInfo所包含的信息。   |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Array\<BundleInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getAllBundleInfo(bundleFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, userId?: number): Promise<Array\<BundleInfo>>

根据给定的bundleFlags和userId获取系统中所有的BundleInfo，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                             |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 指定返回的BundleInfo所包含的信息。                   |
| userId      | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。                      |

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Promise对象，返回Array\<BundleInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                         |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getAllBundleInfo(bundleFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, userId: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

根据给定的appFlags和userId获取系统中所有的ApplicationInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                      |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。                       |
| userId   | number | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。         |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Array\<ApplicationInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                         |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    bundleManager.getAllApplicationInfo(appFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

根据给定的appFlags获取系统中所有的ApplicationInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                      |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。                       |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Array\<ApplicationInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    bundleManager.getAllApplicationInfo(appFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, userId?: number): Promise<Array\<ApplicationInfo>>

根据给定的appFlags和userId获取系统中所有的ApplicationInfo，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                      |
| -------- | ------ | ---- | ---------------------------------------------------------- |
| appFlags | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。                       |
| userId   | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。                        |

**返回值：**

| 类型                                                         | 说明                                     |
| ------------------------------------------------------------ | ---------------------------------------- |
| Promise<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Promise对象，返回Array\<ApplicationInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                         |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    bundleManager.getAllApplicationInfo(appFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllApplicationInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed. Cause: %{public}s', message);
}

```

## bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, userId: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

根据给定的want、abilityFlags和userId获取多个AbilityInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                  |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | 是   | 表示包含要查询的应用Bundle名称的Want。                 |
| abilityFlags | [number](#abilityflag) | 是   | 指定返回的AbilityInfo所包含的信息。                       |
| userId       | number | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。                               |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Array\<AbilityInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', message);
}
```

## bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

根据给定的want和abilityFlags获取一个或多个AbilityInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                  |
| ------------ | ------ | ---- | -------------------------------------------------------|
| want         | Want   | 是   | 表示包含要查询的应用Bundle名称的Want。                 |
| abilityFlags | [number](#abilityflag) | 是   | 指定返回的AbilityInfo所包含的信息。       |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Array\<AbilityInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', message);
}
```

## bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

根据给定的want、abilityFlags和userId获取一个或多个AbilityInfo，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                  |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | 是   | 表示包含要查询的应用Bundle名称的Want。                 |
| abilityFlags | [number](#abilityflag) | 是   | 表示指定返回的AbilityInfo所包含的信息。 |
| userId       | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。                       |

**返回值：**

| 类型                                                         | 说明                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Promise对象，返回Array\<AbilityInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.queryAbilityInfoSync<sup>10+</sup>

queryAbilityInfoSync(want: Want, abilityFlags: number, userId?: number): Array\<AbilityInfo>

以同步方法根据给定的want、abilityFlags和userId获取一个或多个AbilityInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                  |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | 是   | 表示包含要查询的应用Bundle名称的Want。                 |
| abilityFlags | [number](#abilityflag) | 是   | 表示指定返回的AbilityInfo所包含的信息。 |
| userId       | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。                       |

**返回值：**

| 类型                                                         | 说明                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)> | Array\<AbilityInfo>信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {

    let infos = bundleManager.queryAbilityInfoSync(want, abilityFlags, userId);
    hilog.info(0x0000, 'testTag', 'queryAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(infos));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfoSync failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let infos = bundleManager.queryAbilityInfoSync(want, abilityFlags);
    hilog.info(0x0000, 'testTag', 'queryAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(infos));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfoSync failed. Cause: %{public}s', message);
}
```

## bundleManager.queryAbilityInfo<sup>12+</sup>

queryAbilityInfo(wants: Array\<Want>, abilityFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

根据给定的want列表、abilityFlags和userId获取一个或多个AbilityInfo，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                  |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Array\<Want>   | 是   | 表示包含要查询的应用Bundle名称的Want集合。                 |
| abilityFlags | [number](#abilityflag) | 是   | 表示指定返回的AbilityInfo所包含的信息。 |
| userId       | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。                       |

**返回值：**

| 类型                                                         | 说明                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Promise对象，返回Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication1",
    abilityName : "EntryAbility"
};
let want1: Want = {
    bundleName : "com.example.myapplication2",
    abilityName : "EntryAbility"
};
let wants: Array<Want> = [ want, want1 ];
 try {
        bundleManager.queryAbilityInfo(wants, abilityFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
      }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
      })
    } catch (err) {
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
    }
```

## bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void

根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取一个或多个ExtensionAbilityInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                                                         | 必填 | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | 是   | 表示包含要查询的应用Bundle名称的Want。                       |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype)                | 是   | 标识extensionAbility的类型。                                 |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | 是   | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。    |
| userId                | number                                                       | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。                                                 |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到Array\<ExtensionAbilityInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', message);
}
```

## bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void

根据给定的want、extensionAbilityType和extensionAbilityFlags获取一个或多个ExtensionAbilityInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                                                         | 必填 | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | 是   | 表示包含要查询的应用Bundle名称的Want。                       |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype)                | 是   | 标识extensionAbility的类型。                                 |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | 是   | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。    |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到Array\<ExtensionAbilityInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700026 | The specified bundle is disabled.            |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', message);
}
```

## bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId?: number): Promise<Array\<ExtensionAbilityInfo>>

根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取ExtensionAbilityInfo，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                                          | 必填 | 说明                                                      |
| --------------------- | --------------------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                                          | 是   | 表示包含要查询的应用Bundle名称的Want。                    |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | 是   | 标识extensionAbility的类型。                              |
| extensionAbilityFlags | [number](#extensionabilityflag)               | 是   | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。 |
| userId                | number                                        | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。                                              |

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Promise对象，返回Array\<ExtensionAbilityInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';

let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.queryExtensionAbilityInfoSync<sup>10+</sup>

queryExtensionAbilityInfoSync(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

以同步方法根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取ExtensionAbilityInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                                          | 必填 | 说明                                                      |
| --------------------- | --------------------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                                          | 是   | 表示包含要查询的应用Bundle名称的Want。                    |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | 是   | 标识extensionAbility的类型。                              |
| extensionAbilityFlags | [number](#extensionabilityflag)               | 是   | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。 |
| userId                | number                                        | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。                                              |

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | Array\<ExtensionAbilityInfo>信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';

let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let extenInfos = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags, userId);
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(extenInfos));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let extenInfos = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags);
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(extenInfos));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleNameByUid<sup>14+</sup>

getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void

根据给定的uid获取对应的bundleName，使用callback异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                 | 是   | 表示应用程序的UID。                                            |
| callback | AsyncCallback\<string> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的BundleName；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息            |
| -------- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', message);
}
```

## bundleManager.getBundleNameByUid<sup>14+</sup>

getBundleNameByUid(uid: number): Promise\<string>

根据给定的uid获取对应的bundleName，使用Promise异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ---- | ------ | ---- | ------------------ |
| uid  | number | 是   | 表示应用程序的UID。 |

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| Promise\<string> | Promise对象，返回bundleName。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息            |
| -------- | ---------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleNameByUidSync<sup>14+</sup>

getBundleNameByUidSync(uid: number): string

以同步方法根据给定的uid获取对应的bundleName。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ---- | ------ | ---- | ------------------ |
| uid  | number | 是   | 表示应用程序的UID。 |

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| string | 返回获取到的bundleName。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息            |
| -------- | ---------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let uid = 20010005;
try {
    let data = bundleManager.getBundleNameByUidSync(uid);
    hilog.info(0x0000, 'testTag', 'getBundleNameByUidSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUidSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

根据给定的hapFilePath和bundleFlags获取BundleInfo，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ----------------------------------------------------------- |
| hapFilePath | string | 是   | 表示存储HAP的路径，路径应该是当前应用程序数据目录的相对路径。 |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 表示用于指定要返回的BundleInfo对象中包含的信息的标志。       |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的BundleInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                  |
| -------- | --------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleArchiveInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string,  bundleFlags: number): Promise\<BundleInfo>

根据给定的hapFilePath和bundleFlags获取BundleInfo，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | 是   | 表示存储HAP的路径，路径应该是当前应用程序数据目录的相对路径。 |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 表示用于指定要返回的BundleInfo对象中包含的信息的标志。       |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise对象，返回BundleInfo。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleArchiveInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleArchiveInfoSync<sup>10+</sup>

getBundleArchiveInfoSync(hapFilePath: string, bundleFlags: number): BundleInfo

以同步方法根据给定的hapFilePath和bundleFlags获取BundleInfo对象。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | 是   | 表示存储HAP的路径，路径应该是当前应用程序数据目录的相对路径。 |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 表示用于指定要返回的BundleInfo对象中包含的信息的标志。       |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | 返回BundleInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    let data = bundleManager.getBundleArchiveInfoSync(hapFilePath, bundleFlags)
    hilog.info(0x0000, 'testTag', 'getBundleArchiveInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfoSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllBundleCacheSize<sup>15+</sup>

getAllBundleCacheSize(): Promise\<number>

获取全局缓存大小，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<number> | Promise对象。返回全局缓存大小，以字节为单位。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getAllBundleCacheSize().then((data) => {
        hilog.info(0x0000, 'testTag','getAllBundleCacheSize successful. Data: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllBundleCacheSize failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleCacheSize failed: %{public}s', message);
}
```

## bundleManager.cleanAllBundleCache<sup>15+</sup>

cleanAllBundleCache(): Promise\<void>

清理全局缓存，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REMOVE_CACHE_FILES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.cleanAllBundleCache().then((data) => {
        hilog.info(0x0000, 'testTag','cleanAllBundleCache successful.');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'cleanAllBundleCache failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'cleanAllBundleCache failed: %{public}s', message);
}
```

## bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void

根据给定的bundleName清理BundleCache，使用callback异步回调。

调用方清理自身缓存数据时不需要权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REMOVE_CACHE_FILES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                                                         |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | 是   | 表示要清理其缓存数据的应用程序的bundleName。                   |
| callback   | AsyncCallback\<void> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当清理应用缓存目录数据成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.                        |
| 17700030 | The specified bundle does not support clearing of cache files. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.cleanBundleCacheFiles(bundleName, err => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'cleanBundleCacheFiles successfully.');
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', message);
}
```

## bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string): Promise\<void>

根据给定的bundleName清理BundleCache，使用Promise异步回调。

调用方清理自身缓存数据时不需要权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REMOVE_CACHE_FILES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                       |
| ---------- | ------ | ---- | ------------------------------------------ |
| bundleName | string | 是   | 表示要清理其缓存数据的应用程序的bundleName。 |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。当清理应用缓存目录数据失败会抛出错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.                      |
| 17700030 | The specified bundle does not support clearing of cache files. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.cleanBundleCacheFiles(bundleName).then(() => {
        hilog.info(0x0000, 'testTag', 'cleanBundleCacheFiles successfully.');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', message);
}
```

## bundleManager.cleanBundleCacheFiles<sup>15+</sup>

cleanBundleCacheFiles(bundleName: string, appIndex: number): Promise\<void>

根据给定的bundleName和appIndex清理BundleCache，使用Promise异步回调。

调用方清理自身缓存数据时不需要权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REMOVE_CACHE_FILES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                       |
| ---------- | ------ | ---- | ------------------------------------------ |
| bundleName | string | 是   | 表示要清理其缓存数据的应用程序的bundleName。 |
| appIndex | number | 是   | 表示要清理其缓存数据的应用程序的分身应用索引。<br>appIndex为0时，表示清理主应用缓存数据。appIndex大于0时，表示清理指定分身应用缓存数据。 |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。当清理应用缓存目录数据失败会抛出错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.                      |
| 17700030 | The specified bundle does not support clearing of cache files. |
| 17700061 | AppIndex is not in the valid range. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";
let appIndex = 1;

try {
    bundleManager.cleanBundleCacheFiles(bundleName, appIndex).then(() => {
        hilog.info(0x0000, 'testTag', 'cleanBundleCacheFiles successfully.');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', message);
}
```

## bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void

设置指定应用的禁用或使能状态，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                  |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | 是   | 指定应用的bundleName。                |
| isEnabled  | boolean | 是   | 值为true表示使能，值为false表示禁用。 |
| callback | AsyncCallback\<void> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当设置应用禁用或使能状态成功时，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, false, err => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'setApplicationEnabled successfully.');
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', message);
}
```

## bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean): Promise\<void>

设置指定应用的禁用或使能状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                  |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | 是   | 表示应用程序的bundleName。            |
| isEnabled  | boolean | 是   | 值为true表示使能，值为false表示禁用。 |

**返回值：**

| 类型           | 说明                                 |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, false).then(() => {
        hilog.info(0x0000, "testTag", "setApplicationEnabled successfully.");
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', message);
}
```

## bundleManager.setApplicationEnabled<sup>12+</sup>

setApplicationEnabled(bundleName: string, appIndex: number, isEnabled: boolean): Promise\<void>

设置指定应用或分身应用的禁用或使能状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                  |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | 是   | 表示应用程序的bundleName。            |
| appIndex   | number  | 是   | 表示分身应用的索引。<br> appIndex为0时，表示设置主应用的禁用或使能状态。appIndex大于0时，表示设置指定分身应用的禁用或使能状态。              |
| isEnabled  | boolean | 是   | 值为true表示使能，值为false表示禁用。 |

**返回值：**

| 类型           | 说明                                 |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex is not in the valid range. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, 1, false).then(() => {
        hilog.info(0x0000, "testTag", "setApplicationEnabled successfully.");
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', message);
}
```

## bundleManager.setApplicationEnabledSync<sup>10+</sup>

setApplicationEnabledSync(bundleName: string, isEnabled: boolean): void

以同步方法设置指定应用的禁用或使能状态。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                  |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | 是   | 指定应用的bundleName。                |
| isEnabled  | boolean | 是   | 值为true表示使能，值为false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabledSync(bundleName, false);
    hilog.info(0x0000, 'testTag', 'setApplicationEnabledSync successfully.');
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabledSync failed: %{public}s', message);
}
```

## bundleManager.setAbilityEnabled

setAbilityEnabled(info: AbilityInfo, isEnabled: boolean, callback: AsyncCallback\<void>): void

设置指定组件的禁用或使能状态，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型        | 必填 | 说明                                  |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 需要被设置的组件。              |
| isEnabled| boolean     | 是   | 值为true表示使能，值为false表示禁用。 |
| callback | AsyncCallback\<void> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当设置组件禁用或使能状态成功时，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ---------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, false, err => {
            if (err) {
                hilog.error(0x0000, 'testTag', 'setAbilityEnabled failed: %{public}s', err.message);
            } else {
                hilog.info(0x0000, "testTag", "setAbilityEnabled successfully.");
            }
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.setAbilityEnabled

setAbilityEnabled(info: AbilityInfo, isEnabled: boolean): Promise\<void>

设置指定组件的禁用或使能状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型        | 必填 | 说明                                  |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 需要被设置的组件。                   |
| isEnabled| boolean     | 是   | 值为true表示使能，值为false表示禁用。 |

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, false).then(() => {
            hilog.info(0x0000, "testTag", "setAbilityEnabled successfully.");
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'setAbilityEnabled failed: %{public}s', err.message);
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.setAbilityEnabled<sup>12+</sup>

setAbilityEnabled(info: AbilityInfo, appIndex: number, isEnabled: boolean): Promise\<void>

设置指定应用或分身应用组件的禁用或使能状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型        | 必填 | 说明                                  |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 需要被设置的组件。                   |
| appIndex   | number    | 是   | 表示分身应用的索引。<br> appIndex为0时，表示设置主应用组件的禁用或使能状态。appIndex大于0时，表示设置指定分身应用组件的禁用或使能状态。            |
| isEnabled| boolean     | 是   | 值为true表示使能，值为false表示禁用。 |

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |
| 17700061 | AppIndex is not in the valid range. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, 1, false).then(() => {
            hilog.info(0x0000, "testTag", "setAbilityEnabled successfully.");
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'setAbilityEnabled failed: %{public}s', err.message);
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.setAbilityEnabledSync<sup>10+</sup>

setAbilityEnabledSync(info: AbilityInfo, isEnabled: boolean): void

以同步方法设置指定组件的禁用或使能状态。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型        | 必填 | 说明                                  |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 需要被设置的组件。              |
| isEnabled| boolean     | 是   | 值为true表示使能，值为false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ---------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        try {
            bundleManager.setAbilityEnabledSync(info, false);
            hilog.info(0x0000, "testTag", "setAbilityEnabledSync successfully.");
        } catch (err) {
            let message = (err as BusinessError).message;
            hilog.error(0x0000, 'testTag', 'setAbilityEnabledSync failed: %{public}s', message);
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void

获取指定应用的禁用或使能状态，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。 |
| callback | AsyncCallback\<boolean> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，返回true表示当前应用为使能状态，返回false表示应用为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'isApplicationEnabled successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed: %{public}s', message);
}
```

## bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string): Promise\<boolean>

获取指定应用的禁用或使能状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。  |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise对象，返回true表示当前应用为使能状态，返回false表示当前应用为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'isApplicationEnabled successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', message);
}
```

## bundleManager.isApplicationEnabled<sup>12+</sup>

isApplicationEnabled(bundleName: string, appIndex: number): Promise\<boolean>

获取指定应用或分身应用的禁用或使能状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。  |
| appIndex   | number  | 是   | 表示分身应用的索引。<br> appIndex为0时，表示获取主应用的禁用或使能状态。appIndex大于0时，表示获取指定分身应用的禁用或使能状态。            |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise对象，返回true表示当前应用为使能状态，返回false表示当前应用为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex is not in the valid range. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName, 1).then((data) => {
        hilog.info(0x0000, 'testTag', 'isApplicationEnabled successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', message);
}
```

## bundleManager.isApplicationEnabledSync<sup>10+</sup>

isApplicationEnabledSync(bundleName: string): boolean

以同步方法获取指定应用的禁用或使能状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示当前应用为使能状态，返回false表示当前应用为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    let data = bundleManager.isApplicationEnabledSync(bundleName);
    hilog.info(0x0000, 'testTag', 'isApplicationEnabledSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabledSync failed: %{public}s', message);
}
```

## bundleManager.isAbilityEnabled

isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void

获取指定组件的禁用或使能状态，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                        |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 表示关于检查ability的信息。 |
| callback | AsyncCallback\<boolean> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，返回true表示当前应用组件为使能状态，返回false表示应用组件为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info, (err, data) => {
            if (err) {
                hilog.error(0x0000, 'testTag', 'isAbilityEnabled failed: %{public}s', err.message);
            } else {
                hilog.info(0x0000, 'testTag', 'isAbilityEnabled successfully: %{public}s', JSON.stringify(data));
            }
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.isAbilityEnabled

isAbilityEnabled(info: AbilityInfo): Promise\<boolean>

获取指定组件的禁用或使能状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                        |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 表示关于检查ability的信息。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise对象，返回true表示当前应用组件为使能状态，返回false表示当前应用组件为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info).then((data) => {
            hilog.info(0x0000, 'testTag', 'isAbilityEnabled successfully. Data: %{public}s', JSON.stringify(data));
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'isAbilityEnabled failed. Cause: %{public}s', err.message);
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.isAbilityEnabled<sup>12+</sup>

isAbilityEnabled(info: AbilityInfo, appIndex: number): Promise\<boolean>

获取应用或指定分身应用组件的禁用或使能状态，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                        |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 表示关于检查ability的信息。 |
| appIndex   | number  | 是   | 表示分身应用的索引。 <br> appIndex为0时，表示获取主应用组件的禁用或使能状态。appIndex大于0时，表示获取指定分身应用组件的禁用或使能状态。           |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise对象，返回true表示当前应用组件为使能状态，返回false表示当前应用组件为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700061 | AppIndex is not in the valid range. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info, 1).then((data) => {
            hilog.info(0x0000, 'testTag', 'isAbilityEnabled successfully. Data: %{public}s', JSON.stringify(data));
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'isAbilityEnabled failed. Cause: %{public}s', err.message);
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.isAbilityEnabledSync<sup>10+</sup>

isAbilityEnabledSync(info: AbilityInfo): boolean

以同步方法获取指定组件的禁用或使能状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                        |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 表示关于检查ability的信息。 |

**返回值：**

| 类型    | 说明                                                                 |
| ------- | ------------------------------------------------------------------- |
| boolean | 返回true表示当前应用组件为使能状态，返回false表示当前应用组件为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        try {
            let data = bundleManager.isAbilityEnabledSync(info);
            hilog.info(0x0000, 'testTag', 'isAbilityEnabledSync successfully: %{public}s', JSON.stringify(data));
        } catch (err) {
            let message = (err as BusinessError).message;
            hilog.error(0x0000, 'testTag', 'isAbilityEnabledSync failed: %{public}s', message);
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId: number, callback: AsyncCallback\<Want>): void

根据给定的bundleName和userId获取用于启动应用程序的Want参数，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                                                         |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | 是   | 表示应用程序的bundleName。                                     |
| userId     | number               | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。                                                   |
| callback   | AsyncCallback\<Want> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Want；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 201 | Calling interface without permission 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED'. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    bundleManager.getLaunchWantForBundle(bundleName, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getLaunchWantForBundle successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', message);
}
```

## bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void

根据给定的bundleName获取用于启动应用程序的Want参数，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                                                         |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | 是   | 表示应用程序的bundleName。                                     |
| callback   | AsyncCallback\<Want> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Want；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 201 | Calling interface without permission 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED'. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    bundleManager.getLaunchWantForBundle(bundleName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getLaunchWantForBundle successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', message);
}
```

## bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId?: number): Promise\<Want>

根据给定的bundleName和userId获取用于启动应用程序的Want参数，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。 |
| userId     | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。  |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<Want> | Promise对象，返回Want对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 201 | Calling interface without permission 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED'. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    bundleManager.getLaunchWantForBundle(bundleName, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getLaunchWantForBundle successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed. Cause: %{public}s', message);
}
```


## bundleManager.getLaunchWantForBundleSync<sup>10+</sup>

getLaunchWantForBundleSync(bundleName: string, userId?: number): Want

以同步方法根据给定的bundleName和userId获取用于启动应用程序的Want参数。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。 |
| userId     | number | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。  |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Want | Want对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 201 | Calling interface without permission 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED'. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    let want: Want = bundleManager.getLaunchWantForBundleSync(bundleName, userId);
    hilog.info(0x0000, 'testTag', 'getLaunchWantForBundleSync successfully. Data: %{public}s', JSON.stringify(want));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundleSync failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    let want: Want = bundleManager.getLaunchWantForBundleSync(bundleName);
    hilog.info(0x0000, 'testTag', 'getLaunchWantForBundleSync successfully. Data: %{public}s', JSON.stringify(want));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundleSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getPermissionDef

getPermissionDef(permissionName: string, callback: AsyncCallback\<PermissionDef>): void

根据给定的permissionName获取权限定义结构体PermissionDef信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                                                         | 必填 | 说明                                                         |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| permissionName | string                                                       | 是   | 表示权限名称。                                               |
| callback       | AsyncCallback\<[PermissionDef](js-apis-bundleManager-permissionDef-sys.md)> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的Array\<PermissionDef>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let permission = "ohos.permission.GET_BUNDLE_INFO";
try {
    bundleManager.getPermissionDef(permission, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getPermissionDef failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getPermissionDef successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getPermissionDef failed: %{public}s', message);
}
```

## bundleManager.getPermissionDef

getPermissionDef(permissionName: string): Promise\<PermissionDef>

根据给定的permissionName获取权限定义结构体PermissionDef信息，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型   | 必填 | 说明           |
| -------------- | ------ | ---- | -------------- |
| permissionName | string | 是   | 表示权限参数名。 |

**返回值：**

| 类型                                                         | 说明                                       |
| ------------------------------------------------------------ | ------------------------------------------ |
| Promise\<[PermissionDef](js-apis-bundleManager-permissionDef-sys.md)> | Promise对象，返回Array\<PermissionDef>对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let permissionName = "ohos.permission.GET_BUNDLE_INFO";
try {
    bundleManager.getPermissionDef(permissionName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getPermissionDef successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getPermissionDef failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getPermissionDef failed. Cause: %{public}s', message);
}
```

## bundleManager.getPermissionDefSync<sup>10+</sup>

getPermissionDefSync(permissionName: string): PermissionDef;

以同步方法根据给定的permissionName获取权限定义结构体PermissionDef信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型   | 必填 | 说明           |
| -------------- | ------ | ---- | -------------- |
| permissionName | string | 是   | 表示权限参数名。 |

**返回值：**

| 类型                                                         | 说明                                       |
| ------------------------------------------------------------ | ------------------------------------------ |
|[PermissionDef](js-apis-bundleManager-permissionDef-sys.md) | PermissionDef对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let permissionName = "ohos.permission.GET_BUNDLE_INFO";
try {
    let PermissionDef = bundleManager.getPermissionDefSync(permissionName);
    hilog.info(0x0000, 'testTag', 'getPermissionDefSync successfully. Data: %{public}s', JSON.stringify(PermissionDef));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getPermissionDefSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<string>): void

获取指定bundleName、moduleName和abilityName的label，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名      | 类型                   | 必填 | 说明                                                         |
| ----------- | ---------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                 | 是   | 表示应用程序的bundleName。                                     |
| moduleName  | string                 | 是   | 表示Module名称。                                     |
| abilityName | string                 | 是   | 表示UIAbility组件的名称。                                    |
| callback    | AsyncCallback\<string> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获指定组件的Label值；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAbilityLabel failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAbilityLabel successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAbilityLabel failed: %{public}s', message);
}
```

## bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>

获取指定bundleName、moduleName和abilityName的label，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名      | 类型   | 必填 | 说明                      |
| ----------- | ------ | ---- | ------------------------- |
| bundleName  | string | 是   | 表示应用程序的bundleName。  |
| moduleName  | string | 是   | 表示Module名称。  |
| abilityName | string | 是   | 表示UIAbility组件的名称。 |

**返回值：**

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise对象，返回指定组件的Lablel值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAbilityLabel successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAbilityLabel failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAbilityLabel failed. Cause: %{public}s', message);
}
```

## bundleManager.getAbilityLabelSync<sup>10+</sup>

getAbilityLabelSync(bundleName: string, moduleName: string, abilityName: string): string

以同步的方法获取指定bundleName、moduleName和abilityName的label。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名      | 类型   | 必填 | 说明                      |
| ----------- | ------ | ---- | ------------------------- |
| bundleName  | string | 是   | 表示应用程序的bundleName。  |
| moduleName  | string | 是   | 表示Module名称。  |
| abilityName | string | 是   | 表示UIAbility组件的名称。 |

**返回值：**

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| string | 指定组件的Lablel值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
    let abilityLabel = bundleManager.getAbilityLabelSync(bundleName, moduleName, abilityName);
    hilog.info(0x0000, 'testTag', 'getAbilityLabelSync successfully. Data: %{public}s', abilityLabel);
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAbilityLabelSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number, userId: number) : ApplicationInfo

以同步方法根据给定的bundleName、applicationFlags和userId获取ApplicationInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                       |
| ----------- | ------ | ---- | ----------------------------------------------------------|
| bundleName  | string | 是   | 表示应用程序的bundleName。                                  |
| applicationFlags | [number](#applicationflag) | 是   | 表示用于指定将返回的ApplicationInfo对象中包含的信息。       |
| userId      | number | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。                                         |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | 返回ApplicationInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags, userId);
    hilog.info(0x0000, 'testTag', 'getApplicationInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfoSync failed: %{public}s', message);
}
```

## bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number) : ApplicationInfo

以同步方法根据给定的bundleName、applicationFlags获取ApplicationInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名           | 类型                       | 必填 | 说明                                                  |
| ---------------- | -------------------------- | ---- | ----------------------------------------------------- |
| bundleName       | string                     | 是   | 表示应用程序的bundleName。                            |
| applicationFlags | [number](#applicationflag) | 是   | 表示用于指定将返回的ApplicationInfo对象中包含的信息。 |

**返回值：**

| 类型                                                        | 说明                      |
| ----------------------------------------------------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | 返回ApplicationInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags);
    hilog.info(0x0000, 'testTag', 'getApplicationInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfoSync failed: %{public}s', message);
}
```

## bundleManager.getBundleInfoSync<sup>14+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number, userId: number): BundleInfo

以同步方法根据给定的bundleName、bundleFlags和userId获取BundleInfo。

获取调用方自身的信息时不需要权限。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | 是   | 表示应用程序的bundleName。                                 |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 表示用于指定将返回的BundleInfo对象中包含的信息的标志。 |
| userId      | number | 是   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。                                             |

**返回值：**

| 类型       | 说明                 |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | 返回BundleInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);
}
```

## bundleManager.getBundleInfoSync<sup>14+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo

以同步方法根据给定的bundleName、bundleFlags获取BundleInfo。

获取调用方自身的信息时不需要权限。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                                   |
| ----------- | --------------------- | ---- | ------------------------------------------------------ |
| bundleName  | string                | 是   | 表示应用程序的bundleName。                             |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | 是   | 表示用于指定将返回的BundleInfo对象中包含的信息的标志。 |

**返回值：**

| 类型                                              | 说明                 |
| ------------------------------------------------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | 返回BundleInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);
}
```

## bundleManager.getSharedBundleInfo<sup>10+</sup>

getSharedBundleInfo(bundleName: string,  moduleName: string, callback: AsyncCallback\<Array\<SharedBundleInfo\>\>): void

获取指定的共享包信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string                                                       | 是   | 表示应用程序的bundleName。                                   |
| moduleName | string                                                       | 是   | 表示被查询的module的name。                                   |
| callback   | AsyncCallback\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取的指定共享包信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'library';

try {
    bundleManager.getSharedBundleInfo(bundleName, moduleName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getSharedBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getSharedBundleInfo<sup>10+</sup>

getSharedBundleInfo(bundleName: string, moduleName: string): Promise\<Array\<SharedBundleInfo\>\>

获取指定的共享包信息，使用Promise异步回调。

**系统接口：** 此接口为系统接口

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。 |
| moduleName | string | 是   | 表示被查询的module的name。 |

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Promise对象，返回指定的共享包信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'library';

try {
    bundleManager.getSharedBundleInfo(bundleName, moduleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getSharedBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllSharedBundleInfo<sup>10+</sup>

getAllSharedBundleInfo(callback: AsyncCallback\<Array\<SharedBundleInfo\>\>): void

获取所有的共享包信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获所有的共享包信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getAllSharedBundleInfo((err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllSharedBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getAllSharedBundleInfo<sup>10+</sup>

getAllSharedBundleInfo(): Promise\<Array\<SharedBundleInfo\>\>

获取所有的共享包信息，使用Promise异步回调。

**系统接口：** 此接口为系统接口

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Promise对象，返回所有的共享包信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getAllSharedBundleInfo().then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllSharedBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, callback: AsyncCallback\<AppProvisionInfo\>): void

获取指定bundleName的provision配置文件信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | 是   | 指定应用的bundleName。 |
| callback | AsyncCallback\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为指定bundleName的provision配置文件信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.getAppProvisionInfo(bundleName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', message);
}
```

## bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, userId: number, callback: AsyncCallback\<AppProvisionInfo\>): void

获取指定bundleName和userId的provision配置文件信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | 是   | 指定应用的bundleName。 |
| userId | number | 是 | 指定用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取。 |
| callback | AsyncCallback\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为指定bundleName的provision配置文件信息。 |


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";
let userId = 100;

try {
    bundleManager.getAppProvisionInfo(bundleName, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', message);
}
```

## bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, userId?: number): Promise\<AppProvisionInfo\>

根据bundleName和userId获取应用的provision配置文件信息，使用Promise异步回调。

**系统接口：** 此接口为系统接口

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型         | 必填 | 说明          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | 是 | 指定的bundleName。 |
| userId | number | 否 | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。 |


**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | Promise对象，返回应用的provision配置文件信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";
let userId = 100;

try {
    bundleManager.getAppProvisionInfo(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', message);
}

try {
    bundleManager.getAppProvisionInfo(bundleName, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppProvisionInfoSync<sup>10+</sup>

getAppProvisionInfoSync(bundleName: string, userId?: number): AppProvisionInfo

以同步方法根据bundleName和userId获取应用的provision配置文件信息并返回结果。

**系统接口：** 此接口为系统接口

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型         | 必填 | 说明          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | 是 | 指定的bundleName。 |
| userId | number | 否 | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。 |


**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| [AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md) | AppProvisionInfo对象，返回应用的provision配置文件信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";
let userId = 100;

try {
    let data = bundleManager.getAppProvisionInfoSync(bundleName);
    hilog.info(0x0000, 'testTag', 'getAppProvisionInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfoSync failed. Cause: %{public}s', message);
}

try {
    let data = bundleManager.getAppProvisionInfoSync(bundleName, userId);
    hilog.info(0x0000, 'testTag', 'getAppProvisionInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfoSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getSpecifiedDistributionType<sup>10+</sup>
getSpecifiedDistributionType(bundleName: string): string

以同步的方法查询指定bundleName的[分发类型](../../security/app-provision-structure.md)，该返回值是在调用install接口时传入的[InstallParam](./js-apis-installer-sys.md#installparam)中的specifiedDistributionType字段。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名         | 类型                                | 必填 | 说明                         |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| bundleName | string | 是   | 指定的bundleName。 |

**返回值：**

| 类型          | 说明                                   |
| ------------- | -------------------------------------- |
| string | 返回指定bundleName的[分发类型](../../security/app-provision-structure.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**示例：**
```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication";

try {
    let type = bundleManager.getSpecifiedDistributionType(bundleName);
    console.info('getSpecifiedDistributionType successfully, type:' + type);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getSpecifiedDistributionType failed. Cause: ' + message);
}
```


## bundleManager.getAdditionalInfo<sup>10+</sup>

getAdditionalInfo(bundleName: string): string

以同步接口查询指定bundleName的额外信息。该返回值是在调用install接口时传入的[InstallParam](./js-apis-installer-sys.md#installparam)中的additionalInfo字段。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名         | 类型                                | 必填 | 说明                         |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| bundleName | string | 是   | 指定的bundleName。 |

**返回值：**

| 类型          | 说明                                   |
| ------------- | -------------------------------------- |
| string | 返回指定bundleName的额外信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication";

try {
    let info = bundleManager.getAdditionalInfo(bundleName);
    console.info('getAdditionalInfo successfully, additionInfo:' + info);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getAdditionalInfo failed. Cause: ' + message);
}
```

## bundleManager.queryExtensionAbilityInfoSync<sup>11+</sup>

queryExtensionAbilityInfoSync(want: Want, extensionAbilityType: string, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取ExtensionAbilityInfo，使用同步方式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                            | 必填 | 说明                                                      |
| --------------------- | ------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                            | 是   | 表示包含要查询的应用Bundle名称的Want。                    |
| extensionAbilityType  | string                          | 是   | 表示自定义extensionAbility的类型。                        |
| extensionAbilityFlags | [number](#extensionabilityflag) | 是   | 表示返回的ExtensionInfo对象中需要包含的信息标志。 |
| userId                | number                          | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。 |

**返回值：**

| 类型                                                         | 说明                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | 同步返回Array\<ExtensionAbilityInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**示例：**

```ts
// 示例接口带userId参数查询
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let extensionAbilityType = "form";
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let data = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags, userId)
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed: %{public}s', message);
}
```

```ts
// 示例接口不带userId参数查询
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let extensionAbilityType = "form";
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let data = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags);
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed: %{public}s', message);
}
```

## bundleManager.getJsonProfile<sup>11+</sup>

getJsonProfile(profileType: ProfileType, bundleName: string, moduleName?: string, userId?: number): string

以同步的方法根据给定的profileType、bundleName和moduleName查询相应配置文件的JSON字符串。

获取调用方自己的配置文件时不需要权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                            | 必填 | 说明                                                      |
| --------------------- | ------------------------------- | ---- | --------------------------------------------------------- |
| profileType           | [ProfileType](#profiletype11)     | 是   | 表示要查询的配置文件类型。                                   |
| bundleName            | string                          | 是   | 表示要查询应用程序的bundleName。                                  |
| moduleName            | string                          | 否   | 表示要查询应用程序的module的名称，缺省时在入口模块中查找。            |
| userId<sup>12+</sup>  | number                          | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。  |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------ |
| string | 返回配置文件的JSON字符串。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.       |
| 17700002 | The specified moduleName is not found.       |
| 17700004 | The specified user ID is not found.      |
| 17700024 | Failed to get the profile because the specified profile is not found in the HAP. |
| 17700026 | The specified bundle is disabled.            |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let profileType = bundleManager.ProfileType.INTENT_PROFILE;

try {
    let data = bundleManager.getJsonProfile(profileType, bundleName, moduleName)
    hilog.info(0x0000, 'testTag', 'getJsonProfile successfully. Data: %{public}s', data);
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getJsonProfile failed: %{public}s', message);
}
```

## bundleManager.getRecoverableApplicationInfo<sup>11+</sup>

getRecoverableApplicationInfo(callback: AsyncCallback\<Array\<RecoverableApplicationInfo\>\>): void

获取所有可恢复的预置应用信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[RecoverableApplicationInfo](js-apis-bundleManager-recoverableApplicationInfo-sys.md)\>\> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的所有可恢复的预置应用信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getRecoverableApplicationInfo((err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getRecoverableApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getRecoverableApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getRecoverableApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getRecoverableApplicationInfo<sup>11+</sup>

getRecoverableApplicationInfo(): Promise\<Array\<RecoverableApplicationInfo\>\>

获取所有可恢复的预置应用信息，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<Array\<[RecoverableApplicationInfo](js-apis-bundleManager-recoverableApplicationInfo-sys.md)\>\> | Promise对象，返回所有可恢复的预置应用信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getRecoverableApplicationInfo().then((data) => {
        hilog.info(0x0000, 'testTag', 'getRecoverableApplicationInfo successfully: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getRecoverableApplicationInfo failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getRecoverableApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.setAdditionalInfo<sup>11+</sup>

setAdditionalInfo(bundleName: string, additionalInfo: string): void

设置指定应用的额外信息。此接口仅供应用市场调用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                             | 必填 | 说明                                               |
| --------------------- | ------------------------------- | ---- | -------------------------------------------------- |
| bundleName            | string                          | 是   | 指定应用的包名。                                    |
| additionalInfo        | string                          | 是   | 需要设置的应用的额外信息。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                                    |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found.                     |
| 17700053 | The caller is not AppGallery.                                     |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = "com.example.myapplication";
let additionalInfo = "xxxxxxxxx,formUpdateLevel:4";

try {
    bundleManager.setAdditionalInfo(bundleName, additionalInfo);
    hilog.info(0x0000, 'testTag', 'setAdditionalInfo successfully.');
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setAdditionalInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllPreinstalledApplicationInfo<sup>12+</sup>

getAllPreinstalledApplicationInfo(): Promise\<Array\<PreinstalledApplicationInfo\>\>

获取所有预置应用信息，使用promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[PreinstalledApplicationInfo](js-apis-bundleManager-ApplicationInfo-sys.md)>> | Promise对象，返回Array\<PreinstalledApplicationInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                    |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getAllPreinstalledApplicationInfo().then((data)=>{
        hilog.info(0x0000, 'testTag', 'getAllPreinstalledApplicationInfo success, Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllPreinstalledApplicationInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllPreinstalledApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.queryExtensionAbilityInfoSync<sup>11+</sup>

queryExtensionAbilityInfoSync(extensionAbilityType: string, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

根据给定的extensionAbilityType、extensionAbilityFlags和userId获取ExtensionAbilityInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                            | 必填 | 说明                                                      |
| --------------------- | ------------------------------- | ---- | --------------------------------------------------------- |
| extensionAbilityType  | string                          | 是   | 表示自定义extensionAbility的类型。                        |
| extensionAbilityFlags | [number](#extensionabilityflag) | 是   | 表示返回的ExtensionInfo对象中需要包含的信息标志。 |
| userId                | number                          | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户ID。取值范围：大于等于0。 |

**返回值：**

| 类型                                                         | 说明                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | 同步返回Array\<ExtensionAbilityInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter extensionAbilityType is empty. |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |

**示例：**

```ts
// 示例接口带userId参数查询
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let extensionAbilityType = "form";
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;

try {
    let data = bundleManager.queryExtensionAbilityInfoSync(extensionAbilityType, extensionFlags, userId)
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed: %{public}s', message);
}
```

```ts
// 示例接口不带userId参数查询
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let extensionAbilityType = "form";
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;

try {
    let data = bundleManager.queryExtensionAbilityInfoSync(extensionAbilityType, extensionFlags);
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed: %{public}s', message);
}
```

## bundleManager.getAllBundleInfoByDeveloperId<sup>12+</sup>

getAllBundleInfoByDeveloperId(developerId: string): Array\<BundleInfo>

根据给定的developerId获取当前用户下的包信息列表。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型      | 必填 | 说明                     |
| --------------------- | ---------| ---- | --------------------- |
| developerId           | string   | 是   | 表示应用的开发者ID。       |

**返回值：**

| 类型                                                         | 说明                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>    | 同步返回Array\<BundleInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter developerId is empty. |
| 17700059 | The specified developerId is invalid.       |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let developerId = "123456.789";

try {
    let data = bundleManager.getAllBundleInfoByDeveloperId(developerId);
    hilog.info(0x0000, 'testTag', 'getAllBundleInfoByDeveloperId successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfoByDeveloperId failed: %{public}s', message);
}
```

## bundleManager.getDeveloperIds<sup>12+</sup>

getDeveloperIds(appDistributionType?: number): Array\<String>

根据给定的应用[分发类型](#appdistributiontype12)获取当前用户下的所有的开发者ID列表。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型      | 必填 | 说明                     |
| --------------------- | ---------| ---- | --------------------- |
| [appDistributionType](#appdistributiontype12)  | number   | 否   | 表示应用的分发类型，当该参数缺省时，会返回所有应用的开发者ID列表。       |

**返回值：**

| 类型                                                         | 说明                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<String>    | 同步返回Array\<String>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appDistributionType = bundleManager.AppDistributionType.ENTERPRISE;

try {
    let data = bundleManager.getDeveloperIds(appDistributionType);
    hilog.info(0x0000, 'testTag', 'getDeveloperIds successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getDeveloperIds failed: %{public}s', message);
}
```

## bundleManager.switchUninstallState<sup>12+</sup>

switchUninstallState(bundleName: string, state: boolean): void

切换指定应用的可卸载状态，此接口与EDM应用拦截管控机制不互相影响。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_BUNDLE_UNINSTALL_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | 是   | 表示指定应用的bundleName。 |
| state | boolean | 是   | 表示应用的可卸载状态，值为true表示应用可以被卸载，值为false表示应用不可以被卸载。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700060 | The specified application cannot be uninstalled.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    bundleManager.switchUninstallState('com.example.myapplication', false);
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'switchUninstallState failed: %{public}s', message);
}
```

## bundleManager.getAllPluginInfo<sup>19+</sup>

getAllPluginInfo(hostBundleName: string, userId?: number): Promise<Array\<PluginBundleInfo>>

根据给定的hostBundleName和userId获取所有的PluginBundleInfo，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| hostBundleName | string | 是   | 表示安装插件的应用包名。 |
| userId         | number   | 否   | 表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户ID。取值范围：大于等于0。 |

**返回值：**

| 类型                                                         | 说明                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| Promise<Array\<[PluginBundleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md)>> | Promise对象，返回Array\<PluginBundleInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found.  |
| 17700004 | The specified user ID is not found.      |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hostBundleName = 'com.ohos.demo';
let userId = 100;

try {
    bundleManager.getAllPluginInfo(hostBundleName, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllPluginInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllPluginInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllPluginInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hostBundleName = 'com.ohos.demo';

try {
    bundleManager.getAllPluginInfo(hostBundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllPluginInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllPluginInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllPluginInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getExtResource<sup>12+</sup>

getExtResource(bundleName: string): Promise\<Array\<string>>;

根据给定的bundleName获得扩展资源对应的moduleNames。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 要查询扩展资源的应用名称。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array\<string>> | 以Promise方式返回接口运行结果及扩展资源对应的moduleNames。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700303 | Failed to obtain extended resources. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.getExtResource(bundleName).then((modules : Array<string>) => {
        for (let i = 0; i < modules.length; i++) {
            hilog.info(0x0000, 'testTag', 'getExtResource item: %s', modules[i]);
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getExtResource failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getExtResource failed. Cause: %{public}s', message);
}
```

## bundleManager.enableDynamicIcon<sup>12+</sup>

enableDynamicIcon(bundleName: string, moduleName: string): Promise\<void>;

根据给定的bundleName、moduleName使能动态图标。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DYNAMIC_ICON

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 要使能动态图标的应用名称。 |
| moduleName  | string | 是   | 要使能动态图标的模块名称。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |
| 17700304 | Failed to enable the dynamic icon. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName : string = 'com.ohos.demo';
let moduleName : string = 'moduleTest';

try {
    bundleManager.enableDynamicIcon(bundleName, moduleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'enableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.enableDynamicIcon<sup>20+</sup>

enableDynamicIcon(bundleName: string, moduleName: string, option?: BundleOptions): Promise\<void>

根据给定的bundleName、moduleName和option使能动态图标。使用Promise异步回调。

使能当前用户下的动态图标信息时需要申请权限ohos.permission.ACCESS_DYNAMIC_ICON。

使能其他用户下的动态图标信息时需要申请权限ohos.permission.ACCESS_DYNAMIC_ICON 和 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DYNAMIC_ICON or (ohos.permission.ACCESS_DYNAMIC_ICON and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS)


**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 要使能动态图标的应用包名。 |
| moduleName  | string | 是   | 要使能动态图标的模块名。 |
| option  | [BundleOptions](js-apis-bundleManager-BundleInfo-sys.md#bundleoptions) | 否   | 指定需要使能动态图标的用户和分身索引。缺省时使能应用所有用户和所有分身的动态图标。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |
| 17700004 | The specified user ID is not found. |
| 17700061 | AppIndex not in valid range. |
| 17700304 | Failed to enable the dynamic icon. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName: string = 'com.ohos.demo';
let moduleName: string = 'moduleTest';
let option: bundleManager.BundleOptions = {'userId':100, 'appIndex':0};

try {
    bundleManager.enableDynamicIcon(bundleName, moduleName, option).then(() => {
        hilog.info(0x0000, 'testTag', 'enableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.disableDynamicIcon<sup>12+</sup>

disableDynamicIcon(bundleName: string): Promise\<void>;

根据给定的bundleName禁用动态图标。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DYNAMIC_ICON

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 要禁用动态图标的应用名称。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700305 | Failed to disable the dynamic icon. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.disableDynamicIcon(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'disableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.disableDynamicIcon<sup>20+</sup>

disableDynamicIcon(bundleName: string, option?: BundleOptions): Promise\<void>

根据给定的bundleName和option禁用动态图标。使用Promise异步回调。

禁用当前用户下的动态图标信息时需要申请权限ohos.permission.ACCESS_DYNAMIC_ICON。

禁用其他用户下的动态图标信息时需要申请权限ohos.permission.ACCESS_DYNAMIC_ICON 和 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DYNAMIC_ICON or (ohos.permission.ACCESS_DYNAMIC_ICON and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS)


**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 要禁用动态图标的应用包名。 |
| option  | [BundleOptions](js-apis-bundleManager-BundleInfo-sys.md#bundleoptions) | 否   | 指定需要禁用动态图标的用户和分身索引。缺省时禁用应用所有用户和所有分身的动态图标。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |
| 17700061 | AppIndex not in valid range. |
| 17700305 | Failed to disable the dynamic icon. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName: string = 'com.ohos.demo';
let option: bundleManager.BundleOptions = {'userId':100, 'appIndex':0};

try {
    bundleManager.disableDynamicIcon(bundleName, option).then(() => {
        hilog.info(0x0000, 'testTag', 'disableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.getDynamicIcon<sup>12+</sup>

getDynamicIcon(bundleName: string): Promise\<string>;

根据给定的bundleName获得动态图标对应的moduleName。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 要查询扩展资源的应用名称。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<string> | 以Promise方式返回接口运行结果及动态图标对应的moduleName。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700306 | Failed to obtain the dynamic icon. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.getDynamicIcon(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getDynamicIcon successfully %s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppCloneIdentity<sup>14+</sup>

getAppCloneIdentity(uid: number): Promise\<AppCloneIdentity>;

根据uid查询分身应用的bundleName和appIndex。使用Promise异步回调。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------|
|    uid     | number |  是  |     表示应用程序的UID。      |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<AppCloneIdentity> | 以Promise方式返回\<AppCloneIdentity>。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let uid = 20010005;

try {
    bundleManager.getAppCloneIdentity(uid).then((res: bundleManager.AppCloneIdentity) => {
        hilog.info(0x0000, 'testTag', 'getAppCloneIdentity res = %{public}s', JSON.stringify(res));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppCloneIdentity failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppCloneIdentity failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppCloneIdentityBySandboxDataDir<sup>20+</sup>

getAppCloneIdentityBySandboxDataDir(sandboxDataDir: string): AppCloneIdentity

根据应用的沙箱目录获取应用的身份信息，包括应用包名和分身索引信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------|
| sandboxDataDir | string |  是  |     表示[应用的沙箱目录](../../file-management/app-sandbox-directory.md)。      |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| [AppCloneIdentity](js-apis-bundleManager-bundleInfo.md#appcloneidentity14) | 返回应用包名和分身索引信息。 |


**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

//主应用
let dataDir = 'com.example.myapplication';
try {
    let res = bundleManager.getAppCloneIdentityBySandboxDataDir(dataDir);
    console.info('getAppCloneIdentityBySandboxDataDir successfully. res = ' + JSON.stringify(res));
} catch (err) {
    let message = (err as BusinessError).message;
    console.error('getAppCloneIdentityBySandboxDataDir failed. Cause = ' + message);
}

//分身应用
let cloneDataDir = '+clone-1+com.example.myapplication';
try {
    let res = bundleManager.getAppCloneIdentityBySandboxDataDir(cloneDataDir);
    console.info('getAppCloneIdentityBySandboxDataDir successfully. res = ' + JSON.stringify(res));
} catch (err) {
    let message = (err as BusinessError).message;
    console.error('getAppCloneIdentityBySandboxDataDir failed. Cause = ' + message);
}

//元服务
let atomicDataDir = '+auid-20000000+com.example.myapplication';
try {
    let res = bundleManager.getAppCloneIdentityBySandboxDataDir(atomicDataDir);
    console.info('getAppCloneIdentityBySandboxDataDir successfully. res = ' + JSON.stringify(res));
} catch (err) {
    let message = (err as BusinessError).message;
    console.error('getAppCloneIdentityBySandboxDataDir failed. Cause = ' + message);
}
```

## bundleManager.getSandboxDataDir<sup>20+</sup>

getSandboxDataDir(bundleName: string, appIndex: number): string

根据应用包名和分身索引获取对应的沙箱目录。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------|
| bundleName | string |  是  |   表示要查询的应用包名。当前用户下有此应用或者分身才可查询，否则返回错误码17700001。   |
| appIndex | number |  是  |   表示分身索引。取值范围0~5，取值为0表示主应用。   |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| string | 返回应用的沙箱目录。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700061 | The appIndex is invalid. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';
let appIndex = 1;

try {
    let dataDir = bundleManager.getSandboxDataDir(bundleName, appIndex);
    console.info('getSandboxDataDir successfully. dataDir = ' + dataDir);
} catch (err) {
    let message = (err as BusinessError).message;
    console.error('getSandboxDataDir failed. Cause = ' + message);
}
```

## bundleManager.getAppCloneBundleInfo<sup>12+</sup>

getAppCloneBundleInfo(bundleName: string, appIndex: number, bundleFlags: number, userId?: number): Promise\<BundleInfo>;

根据bundleName、分身索引、[bundleFlags](js-apis-bundleManager.md#bundleflag)以及用户ID查询主应用或分身应用的BundleInfo。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------|
|    bundleName     | string |  是  |       表示要查询的应用Bundle名称。      |
|    appIndex     | number |  是  |       表示要查询的分身应用索引。<br>appIndex为0时，表示查询主应用信息。appIndex大于0时，表示查询指定分身应用信息。      |
|    [bundleFlags](js-apis-bundleManager.md#bundleflag)     | number |  是  |       表示用于指定要返回的BundleInfo对象中包含的信息的标志。    |
|    userId     | number |  否  |       表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。      |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<BundleInfo> | 以Promise方式返回应用包信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is invalid. |
| 17700026 | The specified bundle is disabled. |
| 17700061 | The appIndex is invalid. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let appIndex = 1;
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getAppCloneBundleInfo(bundleName, appIndex, bundleFlags).then((res: bundleManager.BundleInfo) => {
        hilog.info(0x0000, 'testTag', 'getAppCloneBundleInfo res: BundleInfo = %{public}s', JSON.stringify(res));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppCloneBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppCloneBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllAppCloneBundleInfo<sup>12+</sup>

getAllAppCloneBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<Array\<BundleInfo>>;

根据bundleName、[bundleFlags](js-apis-bundleManager.md#bundleflag)以及用户ID查询主应用和分身应用的BundleInfo列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------|
|    bundleName     | string |  是  |       表示要查询的应用Bundle名称。      |
|    [bundleFlags](js-apis-bundleManager.md#bundleflag)     | number |  是  |       表示用于指定要返回的BundleInfo对象中包含的信息的标志。    |
|    userId     | number |  否  |       表示用户ID，可以通过[getOsAccountLocalId接口](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)获取，默认值：调用方所在用户，取值范围：大于等于0。      |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array\<BundleInfo>> | 以Promise方式返回应用包信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is invalid. |
| 17700026 | The specified bundle and clone apps are all disabled. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getAllAppCloneBundleInfo(bundleName, bundleFlags).then((res: Array<bundleManager.BundleInfo>) => {
        let index = 0;
        for (let item of res) {
            hilog.info(0x0000, 'testTag', 'getAllAppCloneBundleInfo res: BundleInfo[%{public}d] = %{public}s', index++, JSON.stringify(item));
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllAppCloneBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllAppCloneBundleInfo failed. Cause: %{public}s', message);
}
```
## bundleManager.verifyAbc<sup>11+</sup>

verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean, callback: AsyncCallback\<void>): void

根据给定的abcPaths和deleteOriginalFiles校验.abc文件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.RUN_DYN_CODE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| abcPaths  | Array\<string> | 是   | .abc文件路径。 |
| deleteOriginalFiles | boolean | 是   | 是否删除.abc文件，true删除，false不删除。|
| callback | AsyncCallback\<void> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700201 | Failed to verify the abc file. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let abcPaths: Array<string> = ['/data/storage/el2/base/a.abc'];

try {
  bundleManager.verifyAbc(abcPaths, true, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'verifyAbc failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'verifyAbc successfully');
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'verifyAbc failed: %{public}s', message);
}
```

## bundleManager.migrateData<sup>18+</sup>

migrateData(sourcePaths: Array&lt;string&gt;, destinationPath: string): Promise&lt;void&gt;

拷贝文件，将文件从源路径拷贝到目标路径。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MIGRATE_DATA

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| sourcePaths | Array&lt;string&gt; | 是 | 需要迁移的源路径数组，支持传入如/example1/test.txt的单文件路径，或/example2/test的目录路径。 |
| destinationPath | string | 是 | 目标路径，仅支持传入一个目录路径，例如：/example2/test。 |

**返回值：**

| 类型       | 说明                 |
| ---------- | -------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700080 | The source paths are invalid. |
| 17700081 | The destination path is invalid. |
| 17700082 | User authentication failed. |
| 17700083 | Waiting for user authentication timeout. |
| 17700084 | There are inaccessible path in the source paths. |
| 17700085 | The destination path cannot be accessed. |
| 17700086 | System error occurred during copy execution. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 开发者需将source1、source2、dest内容更新为实际文件路径或目录路径。
  let source1: string = "/data/app/el2/100/base/com.example.myapplication/";
  let source2: string = "/data/app/el2/101/base/com.example.myapplication/log.txt";
  let dest: string = "/data/local/tmp";
  let sourcePaths: Array<string> = [source1, source2];

  bundleManager.migrateData(sourcePaths, dest)
    .then(() => {
      console.info(`migrateData succeed`);
    })
    .catch((err: BusinessError) => {
      console.error(`migrateData err : `, JSON.stringify(err));
    })
} catch(err) {
  console.error(`migrateData call err : `, JSON.stringify(err));
}
```

## bundleManager.verifyAbc<sup>11+</sup>

verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean): Promise\<void>

根据给定的abcPaths和deleteOriginalFiles校验.abc文件。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.RUN_DYN_CODE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| abcPaths  | Array\<string> | 是   | .abc文件路径。 |
| deleteOriginalFiles | boolean | 是   | 是否删除.abc文件，true删除，false不删除。       |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700201 | Failed to verify the abc file. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let abcPaths: Array<string> = ['/data/storage/el2/base/a.abc'];

try {
  bundleManager.verifyAbc(abcPaths, true).then((data) => {
    hilog.info(0x0000, 'testTag', 'verifyAbc successfully');
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'verifyAbc failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'verifyAbc failed. Cause: %{public}s', message);
}
```

## bundleManager.deleteAbc<sup>11+</sup>

deleteAbc(abcPath: string): Promise\<void>

根据给定的abcPath删除.abc文件。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.RUN_DYN_CODE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| abcPath  | string | 是   | .abc文件路径。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700202 | Failed to delete the abc file. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let abcPath: string = '/data/storage/el2/base/a.abc';

try {
  bundleManager.deleteAbc(abcPath).then((data) => {
    hilog.info(0x0000, 'testTag', 'deleteAbc successfully');
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'deleteAbc failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'deleteAbc failed. Cause: %{public}s', message);
}
```

## PluginBundleInfo<sup>19+</sup>

type PluginBundleInfo = _PluginBundleInfo

插件信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PluginBundleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md#pluginbundleinfo) |插件信息。 |

## PluginModuleInfo<sup>19+</sup>

type PluginModuleInfo = _PluginModuleInfo

插件的模块信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PluginModuleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md#pluginmoduleinfo) |插件的模块信息。 |

## bundleManager.getDynamicIconInfo<sup>20+</sup>

getDynamicIconInfo(bundleName: string): Promise\<Array\<DynamicIconInfo>>

根据指定的bundleName获取所有用户和所有分身下的动态图标信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 要查询动态图标的应用包名。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array<[DynamicIconInfo](js-apis-bundleManager-BundleInfo-sys.md#dynamiciconinfo)>> | Promise对象，返回查询到的动态图标信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700306 | Failed to obtain the dynamic icon. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName: string = 'com.ohos.demo';

try {
    bundleManager.getDynamicIconInfo(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getDynamicIconInfo successfully %s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getDynamicIconInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getDynamicIconInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllDynamicIconInfo<sup>20+</sup>

getAllDynamicIconInfo(userId?: number): Promise\<Array\<DynamicIconInfo>>

查询指定用户下所有应用和所有分身的动态图标信息。使用Promise异步回调。

查询当前用户下所有应用和所有分身的动态图标信息时需要申请权限ohos.permission.GET_BUNDLE_INFO_PRIVILEGED。

查询其他用户或者所有用户下所有应用和所有分身的动态图标信息时需要申请权限ohos.permission.GET_BUNDLE_INFO_PRIVILEGED 和 ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| userId  | number | 否   | 标识用户ID。缺省时查询所有用户下所有应用和所有分身的动态图标信息。 |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array\<[DynamicIconInfo](js-apis-bundleManager-BundleInfo-sys.md#dynamiciconinfo)>> | Promise对象，返回查询到的动态图标信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700004 |  The specified user ID is not found. |
| 17700306  | Failed to obtain the dynamic icon. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let userId: number = 100;

try {
    bundleManager.getAllDynamicIconInfo(userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllDynamicIconInfo successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllDynamicIconInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllDynamicIconInfo failed. Cause: %{public}s', message);
}
```