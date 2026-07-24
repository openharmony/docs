# @ohos.bundle (Bundle模块)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->

本模块提供应用信息查询能力，支持[BundleInfo](js-apis-bundle-BundleInfo.md)、[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)、[AbilityInfo](js-apis-bundle-AbilityInfo.md)等信息的查询，以及应用禁用状态的查询、设置等。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 从API version 9开始，该模块不再维护，系统接口建议使用[应用程序包管理模块](js-apis-bundleManager-sys.md)替代。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[Bundle模块](js-apis-Bundle.md)。

## 导入模块

```ts
import bundle from '@ohos.bundle';
```

## 权限列表

| 权限                                         | 权限等级         | 描述            |
|--------------------------------------------|--------------|---------------|
| ohos.permission.CHANGE_ABILITY_ENABLED_STATE | system_basic | 设置禁用使能所需的权限。 |
| ohos.permission.GET_BUNDLE_INFO | normal | 查询指定应用信息。 |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 可查询所有应用信息。     |
| ohos.permission.INSTALL_BUNDLE             | system_core  | 可安装、卸载应用。      |
| ohos.permission.REMOVE_CACHE_FILES | system_basic | 清理应用缓存。 |

权限等级参考[权限APL等级说明](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)。

## bundle.getBundleInstaller<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[installer.getBundleInstaller](js-apis-installer-sys.md#bundleinstallergetbundleinstaller)替代。

getBundleInstaller(): Promise&lt;BundleInstaller&gt;

获取用于安装包的接口，使用Promise异步回调，返回安装接口对象。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**返回值：**

| 类型                                                         | 说明                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| Promise<[BundleInstaller](js-apis-bundle-BundleInstaller-sys.md)> | Promise对象，返回安装接口对象。 |

**示例：**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

bundle.getBundleInstaller().then((data) => {
  console.info('getBundleInstaller successfully.');
}).catch((error: BusinessError) => {
  console.error('getBundleInstaller failed.');
});
```

## bundle.getBundleInstaller<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[installer.getBundleInstaller](js-apis-installer-sys.md#bundleinstallergetbundleinstaller)替代。

getBundleInstaller(callback: AsyncCallback&lt;BundleInstaller&gt;): void

获取用于安装包的接口，使用callback异步回调。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明             |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| callback | AsyncCallback<[BundleInstaller](js-apis-bundle-BundleInstaller-sys.md)> | 是   | 回调函数，返回安装接口对象。 |

**示例：**

```ts
import bundle from '@ohos.bundle';

bundle.getBundleInstaller((err, data) => {
  if (err.code == 0) {
    console.error('getBundleInstaller successfully.');
  } else {
    console.info('getBundleInstaller failed.');
  }
});
```
## bundle.cleanBundleCacheFiles<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[cleanBundleCacheFiles](js-apis-bundleManager-sys.md#bundlemanagercleanbundlecachefiles)替代。

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback&lt;void&gt;): void

清除指定应用程序的缓存数据，使用callback异步回调。

**需要权限：**

ohos.permission.REMOVE_CACHE_FILES

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名      | 类型                | 必填 | 说明                                  |
| ---------- | ------------------- | ---- | ------------------------------------- |
| bundleName | string              | 是   | 指示要清除其缓存数据的应用Bundle名称。 |
| callback   | AsyncCallback\<void> | 是   | 回调函数。          |

**示例：**

```ts
import bundle from '@ohos.bundle';

let bundleName: string = "com.example.myapplication";

bundle.cleanBundleCacheFiles(bundleName, err => {
  if (err) {
    console.error('cleanBundleCacheFiles failed.');
  } else {
    console.info('cleanBundleCacheFiles successfully.');
  }
});
```

## bundle.cleanBundleCacheFiles<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[cleanBundleCacheFiles](js-apis-bundleManager-sys.md#bundlemanagercleanbundlecachefiles)替代。

cleanBundleCacheFiles(bundleName: string): Promise&lt;void&gt;

清除指定应用程序的缓存数据，使用Promise异步回调。

**需要权限：**

ohos.permission.REMOVE_CACHE_FILES

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名     | 类型   | 必填 | 说明                                  |
| ---------- | ------ | ---- | ------------------------------------- |
| bundleName | string | 是   | 指示要清除其缓存数据的应用Bundle名称。 |

**返回值：**

| 类型          | 说明                                 |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise对象，无返回结果的Promise对象。 |

**示例：**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let bundleName: string = "com.example.myapplication";

bundle.cleanBundleCacheFiles(bundleName).then(() => {
  console.info('cleanBundleCacheFiles successfully.');
}).catch((error: BusinessError) => {
  console.error('cleanBundleCacheFiles failed.');
});
```

## bundle.setApplicationEnabled<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[setApplicationEnabled](js-apis-bundleManager-sys.md#bundlemanagersetapplicationenabled)替代。

setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置是否启用指定的应用程序，使用callback异步回调。

**需要权限：**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名      | 类型                | 必填 | 说明                             |
| ---------- | ------------------- | ---- |--------------------------------|
| bundleName | string              | 是   | 指示需要启用或禁用的应用Bundle名称。          |
| isEnable   | boolean             | 是   | 指定是否启用应用程序。true表示启用，false表示禁用。 |
| callback   | AsyncCallback\<void> | 是   | 回调函数。                          |

**示例：**

```ts
import bundle from '@ohos.bundle';

let bundleName: string = "com.example.myapplication";

bundle.setApplicationEnabled(bundleName, false, err => {
  if (err) {
    console.error('setApplicationEnabled failed.');
  } else {
    console.info('setApplicationEnabled successfully.');
  }
});
```

## bundle.setApplicationEnabled<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[setApplicationEnabled](js-apis-bundleManager-sys.md#bundlemanagersetapplicationenabled)替代。

setApplicationEnabled(bundleName: string, isEnable: boolean): Promise&lt;void&gt;

设置是否启用指定的应用程序，使用Promise异步回调。

**需要权限：**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名     | 类型    | 必填 | 说明                                            |
| ---------- | ------- | ---- | ----------------------------------------------- |
| bundleName | string  | 是   | 指示需要启用或禁用的应用Bundle名称。            |
| isEnable   | boolean | 是   | 指定是否启用应用程序。true表示启用，false禁用。 |

**返回值：**

| 类型          | 说明                                 |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise对象，无返回结果的Promise对象。 |

**示例：**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let bundleName: string = "com.example.myapplication";

bundle.setApplicationEnabled(bundleName, false).then(() => {
  console.info('setApplicationEnabled successfully.');
}).catch((error: BusinessError) => {
  console.error('setApplicationEnabled failed.');
});
```

## bundle.setAbilityEnabled<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[setAbilityEnabled](js-apis-bundleManager-sys.md#bundlemanagersetabilityenabled)替代。

setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置是否启用指定的Ability组件，使用callback异步回调。

**需要权限：**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                            |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | 是   | Ability信息，指示需要设置启用状态的Ability。                                   |
| isEnable | boolean                                      | 是   | 指定是否启用应用程序。true表示启用，false禁用。 |
| callback | AsyncCallback\<void>                         | 是   | 为返回操作结果而调用的回调。                    |

## bundle.setAbilityEnabled<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[setAbilityEnabled](js-apis-bundleManager-sys.md#bundlemanagersetabilityenabled)替代。

setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise&lt;void&gt;

设置是否启用指定的Ability组件，使用Promise异步回调。

**需要权限：**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                            |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | 是   | Ability信息，指示需要设置启用状态的Ability。                                   |
| isEnable | boolean                                      | 是   | 指定是否启用应用程序。true表示启用，false禁用。 |

**返回值：**

| 类型          | 说明                                 |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise对象，无返回结果的Promise对象。 |

**示例：**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let bundleName: string = "com.example.myapplication";
let abilityName: string = "EntryAbility";

bundle.getAbilityInfo(bundleName, abilityName).then((abilityInfo) => {
  console.info('getAbilityInfo successfully. Data: ' + JSON.stringify(abilityInfo));

  bundle.setAbilityEnabled(abilityInfo, false).then(data => {
    console.info('setAbilityEnabled successfully.');
  }).catch((error: BusinessError) => {
    console.error('setAbilityEnabled failed:' + JSON.stringify(error));
  })
}).catch((error: BusinessError) => {
  console.error('getAbilityInfo failed. Cause: ' + JSON.stringify(error));
});
```
## bundle.getPermissionDef<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getPermissionDef](js-apis-bundleManager-sys.md#bundlemanagergetpermissiondef)替代。

getPermissionDef(permissionName: string, callback: AsyncCallback&lt;PermissionDef&gt;): void

按权限名称获取权限的详细信息，使用callback异步回调。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名         | 类型                                                         | 必填 | 说明                                             |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| permissionName | string                                                       | 是   | 需要查询的权限的名称。                                 |
| callback       | AsyncCallback<[PermissionDef](js-apis-bundle-PermissionDef-sys.md)> | 是   | 程序启动作为入参的回调函数，返回定义的权限信息。 |

**示例：**

```ts
import bundle from '@ohos.bundle';

let permission: string = "ohos.permission.GET_BUNDLE_INFO";
bundle.getPermissionDef(permission, (err, data) => {
  if (err) {
    console.error('getPermissionDef failed:' + err.message);
  } else {
    console.info('getPermissionDef successfully:' + JSON.stringify(data));
  }
});
```

## bundle.getPermissionDef<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getPermissionDef](js-apis-bundleManager-sys.md#bundlemanagergetpermissiondef)替代。

getPermissionDef(permissionName: string): Promise&lt;PermissionDef&gt;

按权限名称获取权限的详细信息，使用Promise异步回调。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名         | 类型   | 必填 | 说明             |
| -------------- | ------ | ---- | ---------------- |
| permissionName | string | 是   | 需要查询的权限的名称。 |

**返回值：**

| 类型                                                   | 说明                                                   |
| ------------------------------------------------------ | ------------------------------------------------------ |
| Promise<[PermissionDef](js-apis-bundle-PermissionDef-sys.md)> | Promise对象，获取成功时返回权限详细信息。 |

**示例：**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let permissionName: string = "ohos.permission.GET_BUNDLE_INFO";
bundle.getPermissionDef(permissionName).then((data) => {
  console.info('getPermissionDef successfully. Data: ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error('getPermissionDef failed. Cause: ' + error.message);
});
```

## bundle.getBundleInfos<sup>deprecated</sup>

getBundleInfos(bundleFlag: BundleFlag, userId?: number): Promise\<Array\<BundleInfo\>\>

获取指定用户所有的[BundleInfo](js-apis-bundle-BundleInfo.md)，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[bundleManager.getAllBundleInfo](js-apis-bundleManager-sys.md#bundlemanagergetallbundleinfo-2)替代。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型       | 必填 | 说明                                                         |
| ---------- | ---------- | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag | 是   | 用于指定返回的包信息对象中包含信息的标记。取值范围：参考[BundleFlag](js-apis-Bundle.md#bundleflagdeprecated)中包信息相关flag。 |
| userId     | number     | 否   | 用户ID。<br/>默认值：调用方所在用户，取值范围：大于等于0。        |

**返回值：**

| 类型                          | 说明                         |
| --------------------------- | -------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | Promise对象，返回所有可用的[BundleInfo](js-apis-bundle-BundleInfo.md)。 |

**示例：**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let bundleFlag: number = bundle.BundleFlag.GET_BUNDLE_DEFAULT;
let userId: number = 100;

bundle.getBundleInfos(bundleFlag, userId)
  .then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
  }).catch((error: BusinessError) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
  })
```

## bundle.getBundleInfos<sup>deprecated</sup>

getBundleInfos(bundleFlag: BundleFlag, callback: AsyncCallback\<Array\<BundleInfo\>\>): void

获取当前用户所有的[BundleInfo](js-apis-bundle-BundleInfo.md)，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[bundleManager.getAllBundleInfo](js-apis-bundleManager-sys.md#bundlemanagergetallbundleinfo-1)替代。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                                                   | 是   | 用于指定返回的包信息对象中包含信息的标记。取值范围：参考[BundleFlag](js-apis-Bundle.md#bundleflagdeprecated)中包信息相关flag。 |
| callback   | AsyncCallback<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | 是   | 回调函数，返回所有可用的[BundleInfo](js-apis-bundle-BundleInfo.md)，作为程序启动时的入参。      |

**示例：**

```ts
import bundle from '@ohos.bundle';

let bundleFlag: number = bundle.BundleFlag.GET_BUNDLE_DEFAULT;

bundle.getBundleInfos(bundleFlag, (err, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getBundleInfos<sup>deprecated</sup>

getBundleInfos(bundleFlag: BundleFlag, userId: number, callback: AsyncCallback\<Array\<BundleInfo\>\>): void

获取系统中指定用户下所有的[BundleInfo](js-apis-bundle-BundleInfo.md)，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[bundleManager.getAllBundleInfo](js-apis-bundleManager-sys.md#bundlemanagergetallbundleinfo)替代。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名        | 类型                                                                | 必填  | 说明                                                                  |
|------------|-------------------------------------------------------------------|-----|---------------------------------------------------------------------|
| bundleFlag | BundleFlag                                                        | 是   | 用于指定返回的包信息对象中包含信息的标记。取值范围：参考[BundleFlag](js-apis-Bundle.md#bundleflagdeprecated)中包信息相关flag。 |
| userId     | number                                                            | 是   | 用户ID。<br/>取值范围：大于等于0。                           |
| callback   | AsyncCallback<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | 是   | 回调函数，返回指定用户下所有包的[BundleInfo](js-apis-bundle-BundleInfo.md)，作为程序启动时的入参。                  |

**示例：**

```ts
import bundle from '@ohos.bundle';

let bundleFlag: number = bundle.BundleFlag.GET_BUNDLE_DEFAULT;
let userId: number = 100;

bundle.getBundleInfos(bundleFlag, userId, (err, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getApplicationInfos<sup>deprecated</sup>

getApplicationInfos(bundleFlags: number, userId?: number): Promise\<Array\<ApplicationInfo\>\>

获取指定用户下所有已安装的应用信息，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[bundleManager.getAllApplicationInfo](js-apis-bundleManager-sys.md#bundlemanagergetallapplicationinfo-2)替代。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleFlags | number | 是   | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag](js-apis-Bundle.md#bundleflagdeprecated)中应用信息相关flag。 |
| userId      | number | 否   | 用户ID。<br/>默认值：调用方所在用户，取值范围：大于等于0。        |

**返回值：**

| 类型                               | 说明                              |
| -------------------------------- | ------------------------------- |
| Promise<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | Promise对象，获取成功时返回应用信息列表。 |

**示例：**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let bundleFlags: number = bundle.BundleFlag.GET_APPLICATION_INFO_WITH_PERMISSION;
let userId: number = 100;

bundle.getApplicationInfos(bundleFlags, userId)
  .then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
  }).catch((error: BusinessError) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
  })
```

## bundle.getApplicationInfos<sup>deprecated</sup>

getApplicationInfos(bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<ApplicationInfo\>\>): void

获取指定用户下所有已安装的应用信息，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[bundleManager.getAllApplicationInfo](js-apis-bundleManager-sys.md#bundlemanagergetallapplicationinfo)替代。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFlags | number                                                       | 是   | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag](js-apis-Bundle.md#bundleflagdeprecated)中应用信息相关flag。 |
| userId      | number                                                       | 是   | 用户ID。<br/>取值范围：大于等于0。        |
| callback    | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | 是   | 回调函数，返回应用信息列表，作为程序启动时的入参。               |

**示例：**

```ts
import bundle from '@ohos.bundle';

let bundleFlags: number = bundle.BundleFlag.GET_APPLICATION_INFO_WITH_PERMISSION;
let userId: number = 100;

bundle.getApplicationInfos(bundleFlags, userId, (err, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getApplicationInfos<sup>deprecated</sup>

getApplicationInfos(bundleFlags: number, callback: AsyncCallback\<Array\<ApplicationInfo\>\>): void

获取调用方所在用户下已安装的应用信息，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[bundleManager.getAllApplicationInfo](js-apis-bundleManager-sys.md#bundlemanagergetallapplicationinfo-1)替代。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFlags | number                                                       | 是   | 用于指定返回的应用信息对象中包含信息的标记。取值范围：参考[BundleFlag](js-apis-Bundle.md#bundleflagdeprecated)中应用信息相关flag。 |
| callback    | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | 是   | 回调函数，返回应用信息列表，作为程序启动时的入参。               |

**示例：**

```ts
import bundle from '@ohos.bundle';

let bundleFlags: number = bundle.BundleFlag.GET_APPLICATION_INFO_WITH_PERMISSION;

bundle.getApplicationInfos(bundleFlags, (err, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## ModuleRemoveFlag<sup>deprecated</sup>

模块移除时与卡片、快捷方式是否有关联的标志。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，暂无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework

| 名称 | 值 | 说明 |
| ---------- | ---- | -------- |
| FLAG_MODULE_NOT_USED_BY_FORM | 0 | 未被卡片使用。 |
| FLAG_MODULE_USED_BY_FORM | 1 | 已被卡片使用。 |
| FLAG_MODULE_NOT_USED_BY_SHORTCUT | 2 | 未被快捷方式使用。 |
| FLAG_MODULE_USED_BY_SHORTCUT | 3 | 已被快捷方式使用。 |

## SignatureCompareResult<sup>deprecated</sup>

签名校验结果。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，暂无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework

| 名称 | 值 | 说明 |
| ---------- | ---- | -------- |
| SIGNATURE_MATCHED | 0 | 签名一致。 |
| SIGNATURE_NOT_MATCHED | 1 | 签名不一致。 |
| SIGNATURE_UNKNOWN_BUNDLE | 2 | 签名对应的包未知。 |

## ShortcutExistence<sup>deprecated</sup>

查询快捷方式是否存在时返回的结果。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，暂无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework

| 名称 | 值 | 说明 |
| ---------- | ---- | -------- |
| SHORTCUT_EXISTENCE_EXISTS | 0 | 存在。 |
| SHORTCUT_EXISTENCE_NOT_EXISTS | 1 | 不存在。 |
| SHORTCUT_EXISTENCE_UNKNOW | 2 | 未知。 |

## QueryShortCutFlag<sup>deprecated</sup>

用于指定快捷方式查询范围的标志。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，暂无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework

| 名称 | 值 | 说明 |
| ---------- | ---- | -------- |
| QUERY_SHORTCUT_HOME | 0 | 查询桌面快捷方式。|