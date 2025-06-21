# @ohos.bundle.freeInstall (freeInstall模块)(系统接口)

本模块提供免安装相关的设置和查询能力，支持BundlePackInfo、DispatchInfo等信息的查询。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```js
import { freeInstall } from '@kit.AbilityKit';
```

## 权限列表

| 权限                                       | 权限等级     | 描述               |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 可查询所有应用信息。 |
| ohos.permission.INSTALL_BUNDLE             | system_core  | 允许应用安装、卸载其他应用（除了企业相关应用，目前有企业InHouse应用，企业MDM应用和企业normal应用）。   |

权限等级参考[权限APL等级说明](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)。
## UpgradeFlag

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称             | 值   | 说明             |
| ---------------- | ---- | ---------------- |
| NOT_UPGRADE      | 0    | 模块无需升级。     |
| SINGLE_UPGRADE   | 1    | 单个模块需要升级。 |
| RELATION_UPGRADE | 2    | 关系模块需要升级。 |

## BundlePackFlag

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 名称               | 值         | 说明                               |
| ------------------ | ---------- | ---------------------------------- |
| GET_PACK_INFO_ALL  | 0x00000000 | 获取应用包pack.info的所有信息。    |
| GET_PACKAGES       | 0x00000001 | 获取应用包pack.info的package信息。 |
| GET_BUNDLE_SUMMARY | 0x00000002 | 获取应用包pack.info的bundle摘要信息。  |
| GET_MODULE_SUMMARY | 0x00000004 | 获取应用包pack.info的module摘要信息。  |

## setHapModuleUpgradeFlag

setHapModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag, callback: AsyncCallback\<void>):void

设置指定模块是否升级。使用callback异步回调。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

**参数：**

| 参数名     | 类型                        | 必填 | 说明                       |
| ----------- | --------------------------- | ---- | ---------------------------- |
| bundleName  | string                      | 是   | 应用Bundle名称。     |
| moduleName  | string                      | 是   | 应用程序模块名称。           |
| upgradeFlag | [UpgradeFlag](#upgradeflag) | 是   | 仅供内部系统使用标志位。       |
| callback    | AsyncCallback\<void>        | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)。当函数调用成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                            |
|----------|---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700002 | The specified module name is not found. |

**示例：**

```js
import { freeInstall } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let upgradeFlag = freeInstall.UpgradeFlag.SINGLE_UPGRADE;
try {
    freeInstall.setHapModuleUpgradeFlag(bundleName, moduleName, upgradeFlag, err => {
        if (err) {
            console.error('Operation failed:' + JSON.stringify(err));
        } else {
            console.info('Operation succeed');
        }
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## setHapModuleUpgradeFlag

setHapModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag): Promise\<void>

设置指定模块是否升级。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.INSTALL_BUNDLE

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

**参数：**

| 参数名      | 类型                        | 必填 | 说明                   |
| ----------- | --------------------------- | ---- | ---------------------- |
| bundleName  | string                      | 是   | 应用Bundle名称。 |
| moduleName  | string                      | 是   | 应用程序模块名称。     |
| upgradeFlag | [UpgradeFlag](#upgradeflag) | 是   | 仅供内部系统使用标志位。|

**返回值：**

| 类型          | 说明                                 |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                            |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700002 | The specified module name is not found. |

**示例：**

```js
import { freeInstall } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let upgradeFlag = freeInstall.UpgradeFlag.SINGLE_UPGRADE;
try {
    freeInstall.setHapModuleUpgradeFlag(bundleName, moduleName, upgradeFlag).then(() => {
        console.info('Operation succeed')
    }).catch((err: BusinessError) => {
        console.error('Operation failed:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## isHapModuleRemovable

isHapModuleRemovable(bundleName: string, moduleName: string, callback: AsyncCallback\<boolean>): void

查询指定模块是否可以被移除。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

**参数：**

| 参数名      | 类型                   | 必填 | 说明                                          |
| ---------- | ---------------------- | ---- | --------------------------------------------- |
| bundleName | string                 | 是   | 应用Bundle名称。                      |
| moduleName | string                 | 是   | 应用程序模块名称。                            |
| callback   | AsyncCallback\<boolean> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)。返回true表示可以移除；返回false表示不可移除。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                            |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700002 | The specified module name is not found. |

**示例：**

```js
import { freeInstall } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
try {
    freeInstall.isHapModuleRemovable(bundleName, moduleName, (err, data) => {
        if (err) {
            console.error('Operation failed:' + JSON.stringify(err));
        } else {
            console.info('Operation succeed:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## isHapModuleRemovable

isHapModuleRemovable(bundleName: string, moduleName: string): Promise\<boolean>

查询指定模块是否可以被移除。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

**参数：**

| 参数名     | 类型   | 必填 | 说明               |
| ---------- | ------ | ---- | ------------------ |
| bundleName | string | 是   | 应用Bundle名称。   |
| moduleName | string | 是   | 应用程序模块名称。 |

**返回值：**

| 类型             | 说明                         |
| ---------------- | ---------------------------- |
| Promise\<boolean> | Promise对象。返回true表示可以移除；返回false表示不可移除。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                            |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700002 | The specified module name is not found. |

**示例：**

```js
import { freeInstall } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
try {
    freeInstall.isHapModuleRemovable(bundleName, moduleName).then(data => {
        console.info('Operation succeed:' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.error('Operation failed:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## getBundlePackInfo

getBundlePackInfo(bundleName: string, bundlePackFlag : BundlePackFlag, callback: AsyncCallback\<BundlePackInfo>): void

基于bundleName和bundlePackFlag来获取bundlePackInfo。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

**参数：**

| 参数名         | 类型                                                         | 必填 | 说明                                                         |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName     | string                                                       | 是   | 应用Bundle名称。                                             |
| bundlePackFlag | [BundlePackFlag](#bundlepackflag)                            | 是   | 指示要查询的应用包标志。                                     |
| callback       | AsyncCallback<[BundlePackInfo](js-apis-bundleManager-BundlePackInfo-sys.md)> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)。当函数调用成功，err为null，data为获取到的BundlePackInfo信息。否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                            |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |

**示例：**

```js
import { freeInstall } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let bundlePackFlag = freeInstall.BundlePackFlag.GET_PACK_INFO_ALL;
try {
    freeInstall.getBundlePackInfo(bundleName, bundlePackFlag, (err, data) => {
        if (err) {
            console.error('Operation failed:' + JSON.stringify(err));
        } else {
            console.info('Operation succeed:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```
## getBundlePackInfo

getBundlePackInfo(bundleName: string, bundlePackFlag : BundlePackFlag): Promise\<BundlePackInfo>

基于bundleName和BundlePackFlag来获取bundlePackInfo。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

**参数：**

| 参数名         | 类型                              | 必填 | 说明                   |
| -------------- | --------------------------------- | ---- | ---------------------- |
| bundleName     | string                            | 是   | 应用程序Bundle名称。 |
| bundlePackFlag | [BundlePackFlag](#bundlepackflag) | 是   | 指示要查询的应用包标志。|

**返回值：**

| 类型                                                       | 说明                                |
| ---------------------------------------------------------- | ----------------------------------- |
| Promise<[BundlePackInfo](js-apis-bundleManager-BundlePackInfo-sys.md)> | Promise对象，返回BundlePackInfo信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.bundle错误码](errorcode-bundle.md)。

| 错误码ID |    错误信息                            |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |

**示例：**

```js
import { freeInstall } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
let bundleName = 'com.example.myapplication';
let bundlePackFlag = freeInstall.BundlePackFlag.GET_PACK_INFO_ALL;
try {
    freeInstall.getBundlePackInfo(bundleName, bundlePackFlag).then(data => {
        console.info('Operation succeed:' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.error('Operation failed:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## getDispatchInfo

getDispatchInfo(callback: AsyncCallback\<DispatchInfo>): void

获取有关dispatch版本的信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md)> | 是   | [回调函数](../apis-basic-services-kit/js-apis-base.md#asynccallback)。当函数调用成功，err为null，data为获取到的[DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md)信息。否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID |    错误信息                            |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 801 | Capability not supported. |

**示例：**

```js
import { freeInstall } from '@kit.AbilityKit';
try {
    freeInstall.getDispatchInfo((err, data) => {
        if (err) {
            console.error('Operation failed:' + JSON.stringify(err));
        } else {
            console.info('Operation succeed:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## getDispatchInfo

getDispatchInfo(): Promise\<DispatchInfo>

获取有关dispatch版本的信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

**返回值：**

| 类型                                             | 说明                                                         |
| ------------------------------------------------ | ------------------------------------------------------------ |
| Promise<[DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md)> | Promise对象，返回[DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md)信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID |    错误信息                            |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 801 | Capability not supported. |

**示例：**

```js
import { freeInstall } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
try {
    freeInstall.getDispatchInfo().then(data => {
        console.info('Operation succeed:' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.error('Operation failed:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## DispatchInfo

type DispatchInfo = _DispatchInfo

免安装结构体和接口版本信息类。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md#dispatchinfo) |免安装结构体和接口版本信息类。 |

## BundlePackInfo

type BundlePackInfo = _PackInfo.BundlePackInfo

应用包信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.BundlePackInfo](js-apis-bundleManager-BundlePackInfo-sys.md#bundlepackinfo) |应用包信息。 |

## PackageConfig

type PackageConfig = _PackInfo.PackageConfig

pack.info的包信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.PackageConfig](js-apis-bundleManager-BundlePackInfo-sys.md#packageconfig) |pack.info的包信息。 |

## PackageSummary

type PackageSummary = _PackInfo.PackageSummary

pack.info中的包摘要信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.PackageSummary](js-apis-bundleManager-BundlePackInfo-sys.md#packagesummary) |pack.info中的包摘要信息。 |

## BundleConfigInfo

type BundleConfigInfo = _PackInfo.BundleConfigInfo

包的配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.BundleConfigInfo](js-apis-bundleManager-BundlePackInfo-sys.md#bundleconfiginfo) |包的配置信息。 |

## ExtensionAbility

type ExtensionAbility = _PackInfo.ExtensionAbility

extensionAbilities的配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ExtensionAbility](js-apis-bundleManager-BundlePackInfo-sys.md#extensionability) |extensionAbilities的配置信息。 |

## ModuleConfigInfo

type ModuleConfigInfo = _PackInfo.ModuleConfigInfo

包的module配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ModuleConfigInfo](js-apis-bundleManager-BundlePackInfo-sys.md#moduleconfiginfo) |包的module配置信息。 |

## ModuleDistroInfo

type ModuleDistroInfo = _PackInfo.ModuleDistroInfo

module发行版信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ModuleDistroInfo](js-apis-bundleManager-BundlePackInfo-sys.md#moduledistroinfo) |module发行版信息。 |

## ModuleAbilityInfo

type ModuleAbilityInfo = _PackInfo.ModuleAbilityInfo

module包含的ability组件信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ModuleAbilityInfo](js-apis-bundleManager-BundlePackInfo-sys.md#moduleabilityinfo) |module包含的ability组件信息。 |

## AbilityFormInfo

type AbilityFormInfo = _PackInfo.AbilityFormInfo

卡片信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.AbilityFormInfo](js-apis-bundleManager-BundlePackInfo-sys.md#abilityforminfo) |卡片信息。 |

## Version

type Version = _PackInfo.Version

包的版本。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.Version](js-apis-bundleManager-BundlePackInfo-sys.md#version) |包的版本。 |

## ApiVersion

type ApiVersion = _PackInfo.ApiVersion

module的api版本。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.FreeInstall

| 类型                                                         | 说明           |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ApiVersion](js-apis-bundleManager-BundlePackInfo-sys.md#apiversion) |module的api版本。 |
