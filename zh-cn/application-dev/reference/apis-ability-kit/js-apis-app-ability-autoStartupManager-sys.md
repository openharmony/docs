# @ohos.app.ability.autoStartupManager(autoStartupManager)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

autoStartupManager模块提供注册、注销监听应用开机自启动状态变化的回调函数的能力。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块为系统接口。

## 导入模块

```ts
import { autoStartupManager } from '@kit.AbilityKit';
```

## on

on(type: 'systemAutoStartup', callback: AutoStartupCallback): void

注册监听应用组件开机自启动状态变化。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| type | string | 是    | 固定取值“systemAutoStartup”，表示为系统应用所调用。 |
| callback  | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md)   | 是    | 监听应用组件开机自启动状态变化的回调对象。      |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000050 | Internal error. |

**示例**：

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.on('systemAutoStartup', {
    onAutoStartupOn(data: common.AutoStartupInfo) {
      console.info(`autostartupmanager onAutoStartupOn, data: ${JSON.stringify(data)}.`);
    },
    onAutoStartupOff(data: common.AutoStartupInfo) {
      console.info(`autostartupmanager onAutoStartupOff, data: ${JSON.stringify(data)}.`);
    }
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`autostartupmanager on success, err code: ${code}, err msg: ${msg}.`);
}
```

## off

off(type: 'systemAutoStartup', callback?: AutoStartupCallback): void

注销监听应用组件开机自启动状态变化。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| type | string              | 是    | 固定取值“systemAutoStartup”，表示为系统应用所调用。 |
| callback | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md)   | 否 | 监听应用组件开机自启动状态变化的回调对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000050 | Internal error. |

**示例**：

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.off('systemAutoStartup', {
    onAutoStartupOn(data: common.AutoStartupInfo) {
      console.info(`autostartupmanager onAutoStartupOn, data: ${JSON.stringify(data)}.`);
    },
    onAutoStartupOff(data: common.AutoStartupInfo) {
      console.info(`autostartupmanager onAutoStartupOff, data: ${JSON.stringify(data)}.`);
    }
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`autostartupmanager on success, err code: ${code}, err msg: ${msg}.`);
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

设置应用组件开机自启动。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：
- 从API version 18开始，该接口仅在2in1和wearable设备中可正常调用，在其他设备上返回16000050错误码。
- 对于API version 18之前版本，该接口仅在2in1设备中可正常调用，在其他设备上返回16000050错误码。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | 是    | 要设置的开机自启动应用组件信息。 |
| callback | AsyncCallback\<void\> | 是 | 回调函数。当设置应用组件开机自启动成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000004 | Cannot start an invisible component.         |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }, (err: BusinessError) => {
    if (err) {
      console.error(`setApplicationAutoStartup failed, err code: ${err.code}, err msg: ${err.message}.`);
      return;
    }
    console.info(`setApplicationAutoStartup success.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`setApplicationAutoStartup failed, err code: ${code}, err msg: ${msg}.`);
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo): Promise\<void\>

设置应用组件开机自启动。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：
- 从API version 18开始，该接口仅在2in1和wearable设备中可正常调用，在其他设备上返回16000050错误码。
- 对于API version 18之前版本，该接口仅在2in1设备中可正常调用，在其他设备上返回16000050错误码。

**参数**：

| 参数名 | 类型            | 必填 | 说明                         |
| ------ | --------------- | ---- | ---------------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | 是   | 要设置的开机自启动应用组件信息。 |

**返回值：**

| 类型          | 说明                                                         |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000004 | Cannot start an invisible component.         |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then((data: void) => {
    console.info(`setApplicationAutoStartup success.`);
  }).catch((err: BusinessError) => {
    console.error(`setApplicationAutoStartup failed, err code: ${err.code}, err msg: ${err.message}.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`setApplicationAutoStartup failed, err code: ${code}, err msg: ${msg}.`);
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

取消应用组件开机自启动。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：
- 从API version 18开始，该接口仅在2in1和wearable设备中可正常调用，在其他设备上返回16000050错误码。
- 对于API version 18之前版本，该接口仅在2in1设备中可正常调用，在其他设备上返回16000050错误码。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | 是 | 要取消的开机自启动应用组件信息。 |
| callback | AsyncCallback\<void\> | 是    | 回调函数。当取消应用组件开机自启动成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000004 | Cannot start an invisible component.         |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }, (err: BusinessError) => {
    if (err) {
      console.error(`cancelApplicationAutoStartup failed, err code: ${err.code}, msg: ${err.message}.`);
      return;
    }
    console.info(`cancelApplicationAutoStartup success.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`cancelApplicationAutoStartup failed, err code: ${code}, err msg: ${msg}.`);
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo): Promise\<void\>

取消应用组件开机自启动。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：
- 从API version 18开始，该接口仅在2in1和wearable设备中可正常调用，在其他设备上返回16000050错误码。
- 对于API version 18之前版本，该接口仅在2in1设备中可正常调用，在其他设备上返回16000050错误码。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | 是 | 要取消的开机自启动应用组件信息。 |

**返回值：**

| 类型          | 说明                                                         |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000004 | Cannot start an invisible component.         |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then(() => {
    console.info(`cancelApplicationAutoStartup success.`);
  }).catch((err: BusinessError) => {
    console.error(`cancelApplicationAutoStartup failed, err code: ${err.code}, msg: ${err.message}.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`cancelApplicationAutoStartup failed, err code: ${code}, err msg: ${msg}.`);
}
```

## queryAllAutoStartupApplications

queryAllAutoStartupApplications(callback: AsyncCallback\<Array\<AutoStartupInfo\>\>): void

查询自启动应用组件信息。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：
- 从API version 18开始，该接口仅在2in1和wearable设备中可正常调用，在其他设备上返回16000050错误码。
- 对于API version 18之前版本，该接口仅在2in1设备中可正常调用，在其他设备上返回16000050错误码。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>\> | 是    | 回调函数。当查询自启动应用组件信息成功，err为undefined，data为获取到的Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>；否则为错误对象。      |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000050 | Internal error. |

**示例**：

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.queryAllAutoStartupApplications((err, data: common.AutoStartupInfo[]) => {
    if (err) {
      console.error(`queryAllAutoStartupApplications failed, err code: ${err.code}, err msg: ${err.message}.`);
      return;
    }
    console.info(`queryAllAutoStartupApplications success, data: ${JSON.stringify(data)}.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`queryAllAutoStartupApplications failed, err code: ${code}, err msg: ${msg}.`);
}
```

## queryAllAutoStartupApplications

 queryAllAutoStartupApplications(): Promise\<Array\<AutoStartupInfo\>\>

查询自启动应用组件信息。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：
- 从API version 18开始，该接口仅在2in1和wearable设备中可正常调用，在其他设备上返回16000050错误码。
- 对于API version 18之前版本，该接口仅在2in1设备中可正常调用，在其他设备上返回16000050错误码。

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>\> | Promise对象，返回自启动应用组件信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000050 | Internal error. |

**示例**：

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.queryAllAutoStartupApplications().then((data: common.AutoStartupInfo[]) => {
    console.info(`queryAllAutoStartupApplications success, data: ${JSON.stringify(data)}.`);
  }).catch((err: BusinessError) => {
    console.error(`queryAllAutoStartupApplications failed, err code: ${err.code}, err msg: ${err.message}.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`queryAllAutoStartupApplications failed, err code: ${code}, err msg: ${msg}.`);
}
```
