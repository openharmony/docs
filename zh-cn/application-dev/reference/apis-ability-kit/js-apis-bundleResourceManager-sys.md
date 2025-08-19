# @ohos.bundle.bundleResourceManager (bundleResourceManager模块)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供应用资源数据查询能力，支持[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)和[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)等信息的查询。

> **说明：**
>
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块从API version 12 开始支持查询被禁用应用和设备上已安装应用(不区用户)的图标和名称资源。
>
> 本模块为系统接口。

## 导入模块

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
```

## 枚举

### ResourceFlag

资源信息标志，指示需要获取的资源信息的内容。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource。

| 名称                                                     | 值         | 说明                                                         |
| -------------------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_RESOURCE_INFO_ALL                                    | 0x00000001 | 用于同时获取icon和label信息。                                |
| GET_RESOURCE_INFO_WITH_LABEL                             | 0x00000002 | 用于获取仅包含label信息，icon信息为空。                      |
| GET_RESOURCE_INFO_WITH_ICON                              | 0x00000004 | 用于获取仅包含icon信息，label信息为空。                      |
| GET_RESOURCE_INFO_WITH_SORTED_BY_LABEL                   | 0x00000008 | 用于获取根据label排序后的信息。它不能单独使用需要与GET_RESOURCE_INFO_ALL 或 GET_RESOURCE_INFO_WITH_LABEL一起使用。 |
| GET_RESOURCE_INFO_WITH_DRAWABLE_DESCRIPTOR<sup>12+</sup> | 0x00000010 | 用于获取应用图标的[drawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor-sys.md)对象。 |
| GET_RESOURCE_INFO_ONLY_WITH_MAIN_ABILITY<sup>20+</sup>   | 0x00000020 | 用于获取仅在桌面上展示图标的Ability资源，它仅在[getLauncherAbilityResourceInfo](#bundleresourcemanagergetlauncherabilityresourceinfo)和[getAllLauncherAbilityResourceInfo](#bundleresourcemanagergetalllauncherabilityresourceinfo)接口中生效。 |


## 接口

### bundleResourceManager.getBundleResourceInfo

getBundleResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag)): [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)

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
| [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md) | 返回指定应用的BundleResourceInfo。|


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |


**示例：**

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, resourceFlag);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getLauncherAbilityResourceInfo

getLauncherAbilityResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag)): Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>

以同步方法根据给定的bundleName和resourceFlags获取当前应用的LauncherAbilityResourceInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | 是   | 指定查询应用的包名。 |
| resourceFlags | [number](#resourceflag) | 否   | 指定返回的LauncherAbilityResourceInfo所包含的信息，默认值为[ResourceFlag](#resourceflag).GET_RESOURCE_INFO_ALL。 |

**返回值：**

| 类型                                                        | 说明                                  |
| ----------------------------------------------------------- | ------------------------------------- |
| Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)> | 返回指定应用的LauncherAbilityResourceInfo。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |


**示例：**

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    let resourceInfo = bundleResourceManager.getLauncherAbilityResourceInfo(bundleName, resourceFlag);
    hilog.info(0x0000, 'testTag', 'getLauncherAbilityResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo[0].label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLauncherAbilityResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllBundleResourceInfo

getAllBundleResourceInfo(resourceFlags: [number](#resourceflag), callback: AsyncCallback<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)>>): void

根据给定的resourceFlags获取所有应用的BundleResourceInfo。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST 和 ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | 是   | 指定返回的BundleResourceInfo所包含的信息。 |
| callback | AsyncCallback\<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)>> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的BundleResourceInfo数值；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllBundleResourceInfo(resourceFlag, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllBundleResourceInfo failed. err: %{public}s', err.message);
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

getAllBundleResourceInfo(resourceFlags: [number](#resourceflag)): Promise<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)>>;

根据给定的resourceFlags获取所有应用的BundleResourceInfo。使用Promise异步回调。

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
| Promise\<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)>> | Promise对象，返回BundleResourceInfo数值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllBundleResourceInfo(resourceFlag).then(data=> {
        hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllBundleResourceInfo failed. err: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllLauncherAbilityResourceInfo

getAllLauncherAbilityResourceInfo(resourceFlags: [number](#resourceflag), callback: AsyncCallback<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>>): void

根据给定的resourceFlags获取当前所有应用的LauncherAbilityResourceInfo。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_INSTALLED_BUNDLE_LIST 和 ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | 是   | 指定返回的LauncherAbilityResourceInfo所包含的信息。 |
| callback | AsyncCallback\<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>> | 是 | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)，当获取成功时，err为null，data为获取到的LauncherAbilityResourceInfo数值；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllLauncherAbilityResourceInfo(resourceFlag, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed. err: %{public}s', err.message);
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

getAllLauncherAbilityResourceInfo(resourceFlags: [number](#resourceflag)): Promise<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>>

根据给定的resourceFlags获取当前所有应用的LauncherAbilityResourceInfo。使用Promise异步回调。

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
| Promise\<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>> | Promise对象，返回LauncherAbilityResourceInfo数值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**示例：**
```ts
import { bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllLauncherAbilityResourceInfo(resourceFlag).then(data=> {
        hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed. err: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getBundleResourceInfo<sup>12+</sup>

getBundleResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag), appIndex?: number): [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)

以同步方法根据给定的bundleName、resourceFlags和appIndex获取当前应用的BundleResourceInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | 是   | 指定查询应用的包名。 |
| resourceFlags | [number](#resourceflag) | 否   | 指定返回的BundleResourceInfo所包含的信息。 |
| appIndex | number | 否   | 指定查询应用分身的ID，默认值为0。 |

**返回值：**

| 类型                                                        | 说明                                  |
| ----------------------------------------------------------- | ------------------------------------- |
| [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md) | 返回指定应用的BundleResourceInfo。|


**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex not in valid range or not found. |


**示例：**

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
let appIndex = 1;
try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, resourceFlag, appIndex);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getLauncherAbilityResourceInfo<sup>12+</sup>

getLauncherAbilityResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag), appIndex?: number): Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>

以同步方法根据给定的bundleName、resourceFlags和appIndex获取当前应用的LauncherAbilityResourceInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | 是   | 指定查询应用的包名。 |
| resourceFlags | [number](#resourceflag) | 否   | 指定返回的LauncherAbilityResourceInfo所包含的信息，默认值为[ResourceFlag](#resourceflag).GET_RESOURCE_INFO_ALL。 |
| appIndex | number | 否   | 指定查询应用分身的ID，默认值为0。 |

**返回值：**

| 类型                                                        | 说明                                  |
| ----------------------------------------------------------- | ------------------------------------- |
| Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)> | 返回指定应用的LauncherAbilityResourceInfo。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex not in valid range or not found. |

**示例：**

```ts
import { bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
let appIndex = 1;
try {
    let resourceInfo = bundleResourceManager.getLauncherAbilityResourceInfo(bundleName, resourceFlag, appIndex);
    hilog.info(0x0000, 'testTag', 'getLauncherAbilityResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo[0].label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLauncherAbilityResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getExtensionAbilityResourceInfo<sup>20+</sup>

getExtensionAbilityResourceInfo(bundleName: string, extensionAbilityType: bundleManager.ExtensionAbilityType, resourceFlags: number, appIndex?: number): Array\<LauncherAbilityResourceInfo>

根据应用包名、扩展组件类型、资源信息标志、应用分身ID获取应用的扩展组件资源。使用同步方式返回。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_RESOURCES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | 是   | 应用包名。 |
| extensionAbilityType | [bundleManager.ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | 是   | 应用的扩展组件类型，仅支持ExtensionAbilityType.INPUT_METHOD、ExtensionAbilityType.SHARE、ExtensionAbilityType.ACTION。 |
| [resourceFlags](#resourceflag) | number | 是   | 资源信息标志，指示需要获取的资源信息的内容。 |
| appIndex | number | 否   | 应用分身的ID，默认值是0。取值范围0~5，取值为0表示主应用。 |

**返回值：**

| 类型                                                        | 说明                                  |
| ----------------------------------------------------------- | ------------------------------------- |
| Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)> | 返回指定应用的配置入口图标和名称信息。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[包管理子系统通用错误码](errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied，non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex not in valid range or not found. |

**示例：**

```ts
import { bundleManager, bundleResourceManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = "com.example.myapplication";
let extensionAbilityType = bundleManager.ExtensionAbilityType.INPUT_METHOD;
let resourceFlag = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    let resourceInfo = bundleResourceManager.getExtensionAbilityResourceInfo(bundleName, extensionAbilityType, resourceFlag);
    console.info('getExtensionAbilityResourceInfo successfully. Data label: ' + JSON.stringify(resourceInfo[0].label));
} catch (err) {
    let message = (err as BusinessError).message;
    let code = (err as BusinessError).code;
    console.error(`getExtensionAbilityResourceInfo failed, err code:${code}, err msg: ${message}`);
}
```

## BundleResourceInfo

type BundleResourceInfo = _BundleResourceInfo

应用配置的图标和名称信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md#bundleresourceinfo) |应用配置的图标和名称信息。 |

## LauncherAbilityResourceInfo

type LauncherAbilityResourceInfo = _LauncherAbilityResourceInfo

应用配置的入口图标和名称信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md#launcherabilityresourceinfo) |应用配置的入口图标和名称信息。 |