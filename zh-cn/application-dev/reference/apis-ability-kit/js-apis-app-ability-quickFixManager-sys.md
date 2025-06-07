# @ohos.app.ability.quickFixManager (quickFixManager)(系统接口)

quickFixManager模块提供快速修复的能力，快速修复是系统提供给开发者的一种技术手段，支持开发者以远快于（小时级、分钟级）应用升级的方式进行缺陷修复。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口均为系统接口，三方应用不支持调用。

## 导入模块

```ts
import { quickFixManager } from '@kit.AbilityKit';
```

## HapModuleQuickFixInfo

hap级别的快速修复信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.QuickFix

**系统接口**：此接口为系统接口。

| 名称        | 类型                 | 只读 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ---- | ------------------------------------------------------------ |
| moduleName    | string               | 是 |  是   | HAP的名称。                               |
| originHapHash    | string            | 是 | 是   | 指示hap的哈希值。                               |
| quickFixFilePath    | string         | 是 | 是   | 指示快速修复文件的安装路径。                               |

## ApplicationQuickFixInfo

应用级别的快速修复信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.QuickFix

**系统接口**：此接口为系统接口。

| 名称        | 类型                 | 只读 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName    | string               | 是 | 是   | 应用Bundle名称。                       |
| bundleVersionCode    | number        | 是 | 是   | 应用的版本号。                               |
| bundleVersionName    | string        | 是 | 是   | 应用版本号的文字描述。                               |
| quickFixVersionCode    | number      | 是 | 是   | 快速修复补丁包的版本号。                               |
| quickFixVersionName    | string      | 是 | 是   | 快速修复补丁包版本号的文字描述。                               |
| hapModuleQuickFixInfo    | Array\<[HapModuleQuickFixInfo](#hapmodulequickfixinfo)>   | 是 | 是   | hap级别的快速修复信息。     |

## quickFixManager.applyQuickFix

applyQuickFix(hapModuleQuickFixFiles: Array\<string>, callback: AsyncCallback\<void>): void;

快速修复的补丁安装接口。使用callback异步回调。

**需要权限**：ohos.permission.INSTALL_BUNDLE

**系统能力**：SystemCapability.Ability.AbilityRuntime.QuickFix

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | hapModuleQuickFixFiles | Array\<string> | 是 | 快速修复补丁文件（补丁文件需包含有效的文件路径）。 |
  | callback | AsyncCallback\<void> | 是 | 回调函数。当快速修复的补丁安装成功，err为undefined，否则为错误对象。 |

**错误码**：

在打补丁过程中发生的错误，其错误码及错误信息通过公共事件[COMMON_EVENT_QUICK_FIX_APPLY_RESULT](../apis-basic-services-kit/common_event/commonEvent-definitions.md#common_event_quick_fix_apply_result9)的参数返回给应用开发者。

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 18500002 | Invalid patch package. |
| 18500008 | Internal error. |

> 说明：调用applyQuickFix接口时，补丁文件所在路径为应用沙箱路径。沙箱路径的获取参考[获取应用的沙箱路径](js-apis-bundle-BundleInstaller-sys.md#获取应用的沙箱路径)，映射到设备上的路径为/proc/&lt;应用进程Id&gt;/root/沙箱路径。

**示例：**

```ts
import { quickFixManager } from '@kit.AbilityKit';

try {
  let hapModuleQuickFixFiles = ['/data/storage/el2/base/entry.hqf'];
  quickFixManager.applyQuickFix(hapModuleQuickFixFiles, (error) => {
    if (error) {
      console.error( `applyQuickFix failed with error: ${error}`);
    } else {
      console.info(`applyQuickFix success`);
    }
  });
} catch (paramError) {
  console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);
}
```

## quickFixManager.applyQuickFix

applyQuickFix(hapModuleQuickFixFiles: Array\<string>): Promise\<void>;

快速修复的补丁安装接口。使用Promise异步回调。

**需要权限**：ohos.permission.INSTALL_BUNDLE

**系统能力**：SystemCapability.Ability.AbilityRuntime.QuickFix

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | hapModuleQuickFixFiles | Array\<string> | 是 | 快速修复补丁文件（补丁文件需包含有效的文件路径）。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

在打补丁过程中发生的错误，其错误码及错误信息通过公共事件[COMMON_EVENT_QUICK_FIX_APPLY_RESULT](../apis-basic-services-kit/common_event/commonEvent-definitions.md#common_event_quick_fix_apply_result9)的参数返回给应用开发者。

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 18500002 | Invalid patch package. |
| 18500008 | Internal error. |

**示例：**

```ts
import { quickFixManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let hapModuleQuickFixFiles = ['/data/storage/el2/base/entry.hqf'];

try {
  quickFixManager.applyQuickFix(hapModuleQuickFixFiles).then(() => {
    console.info(`applyQuickFix success`);
  }).catch((error: BusinessError) => {
    console.error(`applyQuickFix err: ${error}`);
  });
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```

## quickFixManager.getApplicationQuickFixInfo

getApplicationQuickFixInfo(bundleName: string, callback: AsyncCallback\<ApplicationQuickFixInfo>): void;

获取应用的快速修复信息。使用callback异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.QuickFix

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 |应用Bundle名称。  |
| callback | AsyncCallback\<[ApplicationQuickFixInfo](#applicationquickfixinfo)> | 是 | 回调函数。返回应用的快速修复信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 18500001 | The bundle does not exist or no patch has been applied. |
| 18500008 | Internal error. |

**示例：**

```ts
import { quickFixManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName = 'bundleName';
  quickFixManager.getApplicationQuickFixInfo(bundleName, (error, data) => {
    if (error) {
      console.error(`getApplicationQuickFixInfo error: ${error}`);
    } else {
      console.info(`getApplicationQuickFixInfo success: ${data}`);
    }
  });
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```

## quickFixManager.getApplicationQuickFixInfo

getApplicationQuickFixInfo(bundleName: string): Promise\<ApplicationQuickFixInfo>;

获取应用的快速修复信息。使用Promise异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.QuickFix

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用Bundle名称。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise\<[ApplicationQuickFixInfo](#applicationquickfixinfo)> | Promise对象。返回应用的快速修复信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 18500001 | The bundle does not exist or no patch has been applied. |
| 18500008 | Internal error. |

**示例：**

```ts
import { quickFixManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName = 'bundleName';
  quickFixManager.getApplicationQuickFixInfo(bundleName).then((data) => {
    console.info(`getApplicationQuickFixInfo success: ${data}`);
  }).catch((error: BusinessError) => {
    console.error(`getApplicationQuickFixInfo err: ${error}`);
  });
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```

## quickFixManager.revokeQuickFix<sup>10+<sup>

revokeQuickFix(bundleName: string, callback: AsyncCallback\<void>): void;

撤销快速修复的接口，使用callback方式返回结果。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.INSTALL_BUNDLE

**系统能力**：SystemCapability.Ability.AbilityRuntime.QuickFix

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 需要撤销补丁的应用Bundle名称。 |
  | callback | AsyncCallback\<void> | 是 | 回调函数。当撤销快速修复成功时，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 18500001 | The bundle does not exist or no patch has been applied. |
| 18500009 | The application has an ongoing quick fix task. |

在撤销补丁过程中发生的错误，其错误码及错误信息通过公共事件[COMMON_EVENT_QUICK_FIX_REVOKE_RESULT](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_quick_fix_revoke_result10)的参数返回给应用开发者。

**示例：**

```ts
import { quickFixManager } from '@kit.AbilityKit';

let bundleName = 'com.example.myapplication';

quickFixManager.revokeQuickFix(bundleName, (err) => {
  if (err.code) {
    console.error(`revokeQuickFix ${bundleName} failed, err code: ${err.code}, err msg: ${err.message}.`);
  }
});
```

## quickFixManager.revokeQuickFix<sup>10+<sup>

revokeQuickFix(bundleName: string): Promise\<void>;

撤销快速修复的接口。使用Promise异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.INSTALL_BUNDLE

**系统能力**：SystemCapability.Ability.AbilityRuntime.QuickFix

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 需要撤销补丁的应用Bundle名称。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 18500001 | The bundle does not exist or no patch has been applied. |
| 18500009 | The application has an ongoing quick fix task. |

在撤销补丁过程中发生的错误，其错误码及错误信息通过公共事件[COMMON_EVENT_QUICK_FIX_REVOKE_RESULT](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_quick_fix_revoke_result10)的参数返回给应用开发者。这部分错误码及错误信息如下：

**示例：**

```ts
import { quickFixManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';

quickFixManager.revokeQuickFix(bundleName).then(() => {
  console.info(`revokeQuickFix ${bundleName} success.`);
}).catch((err: BusinessError) => {
  console.error(`revokeQuickFix ${bundleName} failed, err code: ${err.code}, err msg: ${err.message}.`);
});
```