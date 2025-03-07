# @ohos.app.ability.autoStartupManager(autoStartupManager)(系统接口)

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

**示例**：

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';

try {
  autoStartupManager.on('systemAutoStartup', {
    onAutoStartupOn(data: common.AutoStartupInfo) {
      console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
    },
    onAutoStartupOff(data: common.AutoStartupInfo) {
      console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
    }
  });
} catch (err) {
  console.info('===> autostartupmanager on throw err: ' + JSON.stringify(err));
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

**示例**：

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';

try {
  autoStartupManager.off('systemAutoStartup', {
    onAutoStartupOn(data: common.AutoStartupInfo) {
      console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
    },
    onAutoStartupOff(data: common.AutoStartupInfo) {
      console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
    }
  });
} catch (err) {
  console.info('===> autostartupmanager off throw err: ' + JSON.stringify(err));
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

设置应用组件开机自启动。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | 是    | 要设置的开机自启动应用组件信息。 |
| callback | AsyncCallback\<void\> | 是 | 回调函数。当设置应用组件开机自启动成功，err为undefined，否则为错误对象。 |

**错误码**：

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 16000004 | Failed to start the invisible ability.           |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

请参考[元能力子系统错误码](errorcode-ability.md)。

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';

try {
  autoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }, (err, data) => {
    console.info('====> setApplicationAutoStartup: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
  });
} catch (err) {
  console.info('====> setApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo): Promise\<void\>

设置应用组件开机自启动。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型            | 必填 | 说明                         |
| ------ | --------------- | ---- | ---------------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | 是   | 要设置的开机自启动应用组件信息。 |

**返回值：**

| 类型          | 说明                                                         |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 16000004 | Failed to start the invisible ability.           |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

请参考[元能力子系统错误码](errorcode-ability.md)。

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then((data: void) => {
    console.info('====> setApplicationAutoStartup data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.info('====> setApplicationAutoStartup err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> setApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

取消应用组件开机自启动。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | 是 | 要取消的开机自启动应用组件信息。 |
| callback | AsyncCallback\<void\> | 是    | 回调函数。当取消应用组件开机自启动成功，err为undefined，否则为错误对象。 |

**错误码**：

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 16000004 | Failed to start the invisible ability.           |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

请参考[元能力子系统错误码](errorcode-ability.md)。

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';

try {
  autoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }, (err, data) => {
    console.info('====> cancelApplicationAutoStartup err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
  });
} catch (err) {
  console.info('====> cancelApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo): Promise\<void\>

取消应用组件开机自启动。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | 是 | 要取消的开机自启动应用组件信息。 |

**返回值：**

| 类型          | 说明                                                         |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 16000004 | Failed to start the invisible ability.           |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

请参考[元能力子系统错误码](errorcode-ability.md)。

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then((data: void) => {
    console.info('====> cancelApplicationAutoStartup data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.info('====> cancelApplicationAutoStartup err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> cancelApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## queryAllAutoStartupApplications

queryAllAutoStartupApplications(callback: AsyncCallback\<Array\<AutoStartupInfo\>\>): void

查询自启动应用组件信息。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>\> | 是    | 回调函数。当查询自启动应用组件信息成功，err为undefined，data为获取到的Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>；否则为错误对象。      |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000050 | Internal error. |

请参考[元能力子系统错误码](errorcode-ability.md)。

**示例**：

```ts
import { autoStartupManager } from '@kit.AbilityKit';

try {
  autoStartupManager.queryAllAutoStartupApplications((err, data) => {
    console.info('====> queryAllAutoStartupApplications err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
  });
} catch (err) {
  console.info('====> queryAllAutoStartupApplications throw err: ' + JSON.stringify(err));
}
```

## queryAllAutoStartupApplications

 queryAllAutoStartupApplications(): Promise\<Array\<AutoStartupInfo\>\>

查询自启动应用组件信息。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_APP_BOOT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>\> | Promise对象，返回自启动应用组件信息。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000050 | Internal error. |

请参考[元能力子系统错误码](errorcode-ability.md)。

**示例**：

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.queryAllAutoStartupApplications().then((autoStartupInfo: common.AutoStartupInfo[]) => {
    console.info('====> queryAllAutoStartupApplications data: ' + JSON.stringify(autoStartupInfo));
  }).catch((err: BusinessError) => {
    console.info('====> queryAllAutoStartupApplications err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> queryAllAutoStartupApplications throw err: ' + JSON.stringify(err));
}
```
