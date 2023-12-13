# @ohos.bundle.bundleResourceManager (bundleResourceManager模块)

本模块提供应用资源数据查询能力，支持[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)和[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)等信息的查询。

> **说明：**
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
```

## 权限列表

| 权限                                       | 权限等级     | 描述            |
| ------------------------------------------ | ------------ | ------------------|
|ohos.permission.GET_BUNDLE_RESOURCES| system_basic | 允许查询应用的资源信息。 |
| ohos.permission.GET_INSTALLED_BUNDLE_LIST | system_basic | 读取已安装应用列表。 |

权限等级参考[权限等级说明](../../security/accesstoken-overview.md#权限等级说明)。

## 枚举

### ResourceFlag

资源信息标志，指示需要获取的资源信息的内容。

**系统接口：** 此接口为系统接口。

 **系统能力：** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Resource。

| 名称                                      | 值         | 说明                                                         |
| ----------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_RESOURCE_INFO_ALL                   | 0x00000001 | 用于同时获取icon和label信息。|
| GET_RESOURCE_INFO_WITH_LABEL          | 0x00000002 | 用于获取仅包含label信息，iocn信息为空。 |
| GET_RESOURCE_INFO_WITH_ICON           | 0x00000004 | 用于获取仅包含icon信息，label信息为空。 |
| GET_RESOURCE_INFO_WITH_SORTED_BY_LABEL| 0x00000008 | 用于获取根据label排序后的信息。它不能单独使用需要与GET_RESOURCE_INFO_ALL 或 GET_RESOURCE_INFO_WITH_LABEL一起使用。 |


## 接口

### bundleResourceManager.getBundleResourceInfo

getBundleResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag)): [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md);

以同步方法根据给定的bundleName和resourceFlags获取当前应用的BundleResourceInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | 是   | 指定查询应用的包名。 |
| resourceFlags | [number](#resourceflag) | 否   | 指定返回的BundleResourceInfo所包含的信息。 |

**返回值：**

| 类型                                                        | 说明                                  |
| ----------------------------------------------------------- | ------------------------------------- |
| [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md) | 返回指定应用的BundleResourceInfo。|


**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |


**示例：**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getLauncherAbilityResourceInfo

getLauncherAbilityResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag)): Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>;

以同步方法根据给定的bundleName和resourceFlags获取当前应用的LauncherAbilityResourceInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | 是   | 指定查询应用的包名。 |
| resourceFlags | [number](#resourceflag) | 否   | 指定返回的LauncherAbilityResourceInfo所包含的信息。 |

**返回值：**

| 类型                                                        | 说明                                  |
| ----------------------------------------------------------- | ------------------------------------- |
| Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)> | 返回指定应用的LauncherAbilityResourceInfo。|

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |


**示例：**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    let resourceInfo = bundleResourceManager.getLauncherAbilityResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getLauncherAbilityResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo[0].label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLauncherAbilityResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllBundleResourceInfo

getAllBundleResourceInfo(resourceFlags: [number](#resourceflag), callback: AsyncCallback<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)>>): void;

以异步方法根据给定的resourceFlags获取所有应用的BundleResourceInfo。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST 和 ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | 是   | 指定返回的BundleResourceInfo所包含的信息。 |
| callback | AsyncCallback\<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)>> | 是 | 回调函数，当获取成功时，err为null，data为获取到的BundleResourceInfo数值；否则为错误对象。 |

**示例：**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllBundleResourceInfo(bundleFlags, (err, data) => {
        if (err) {
            hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo failed. err: %{public}s', err.message);
            return;
        }
        hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllBundleResourceInfo

getAllBundleResourceInfo(resourceFlags: [number](#resourceflag)): Promise<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)>>;

以异步方法根据给定的resourceFlags获取所有应用的BundleResourceInfo。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST 和 ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | 是   | 指定返回的BundleResourceInfo所包含的信息。 |

**返回值：**

| 类型                                                         | 说明                             |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)>> | Promise对象，返回BundleResourceInfo数值。 |

**示例：**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllBundleResourceInfo(bundleFlags).then(data=> {
        hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    }).catch((err: BusinessError) => {
        hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo failed. err: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllLauncherAbilityResourceInfo

getAllLauncherAbilityResourceInfo(resourceFlags: [number](#resourceflag), callback: AsyncCallback<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>>): void;

以异步方法根据给定的resourceFlags获取当前所有应用的LauncherAbilityResourceInfo。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST 和 ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | 是   | 指定返回的LauncherAbilityResourceInfo所包含的信息。 |
| callback | AsyncCallback\<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>> | 是 | 回调函数，当获取成功时，err为null，data为获取到的LauncherAbilityResourceInfo数值；否则为错误对象。 |


**示例：**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllLauncherAbilityResourceInfo(bundleFlags, (err, data) => {
        if (err) {
            hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed. err: %{public}s', err.message);
            return;
        }
        hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllLauncherAbilityResourceInfo

getAllLauncherAbilityResourceInfo(resourceFlags: [number](#resourceflag)) : Promise<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>>;

以异步方法根据给定的resourceFlags获取当前所有应用的LauncherAbilityResourceInfo。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST 和 ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | 是   | 指定返回的LauncherAbilityResourceInfo所包含的信息。 |

**返回值：**

| 类型                                                         | 说明                             |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>> | Promise对象，返回LauncherAbilityResourceInfo数值。 |

**示例：**
```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllLauncherAbilityResourceInfo(bundleFlags).then(data=> {
        hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    }).catch((err: BusinessError) => {
        hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed. err: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed: %{public}s', message);
}
```