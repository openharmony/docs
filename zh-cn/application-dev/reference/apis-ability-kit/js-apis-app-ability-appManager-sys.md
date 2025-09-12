# @ohos.app.ability.appManager (appManager)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.appManager (appManager)](js-apis-app-ability-appManager.md)。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## appManager.PreloadMode<sup>12+</sup>

表示预加载应用进程模式的枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

| 名称        | 值  | 说明                         |
| ----------- | --- | --------------------------- |
| PRESS_DOWN  | 0 | 按下应用图标时进行应用进程预加载。 |

## KeepAliveAppType<sup>14+</sup>

表示被保活应用的应用类型。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 值  | 说明 |
| -------- | ---------- | -------- |
| ALL  | 0 | 三方应用和系统应用。此选项只能作为[getKeepAliveBundles](#appmanagergetkeepalivebundles14)接口的入参被调用。  |
| THIRD_PARTY | 1  | 三方应用。  |
| SYSTEM | 2 | 系统应用。 |

## KeepAliveSetter<sup>14+</sup>

表示应用保活的设置方类型。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 值  | 说明 |
| -------- | ---------- | -------- |
| SYSTEM | 0 | 应用保活设置方为系统。 |
| USER  | 1 | 应用保活设置方为用户。  |

## KeepAliveBundleInfo<sup>14+</sup>

定义应用保活信息，可以通过[getKeepAliveBundles](#appmanagergetkeepalivebundles14)或[getKeepAliveAppServiceExtensions](#appmanagergetkeepaliveappserviceextensions20)获取。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------------------------- | ------ | ---- | ---- | --------- |
| bundleName   | string | 否 | 否  | Bundle名称。 |
| type       | [KeepAliveAppType](#keepaliveapptype14) | 否 | 否 | 表示被保活应用的应用类型。   |
| setter       | [KeepAliveSetter](#keepalivesetter14) | 否 | 否 | 表示应用保活设置者类型。   |
| setterUserId<sup>20+</sup>   | number | 否 | 是  | 应用保活设置者的用户ID。 |
| allowUserToCancel<sup>20+</sup>   | boolean | 否 | 是  | 表示是否允许用户取消保活。true表示允许，false表示不允许。 |

## appManager.isSharedBundleRunning<sup>10+</sup>

isSharedBundleRunning(bundleName: string, versionCode: number): Promise\<boolean>

检查共享库是否正在使用。使用Promise异步回调。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| bundleName    | string   | 是    | 表示要查询的共享库包名。 |
| versionCode   | number   | 是    | 表示要查询的共享库版本号。      |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<boolean> | Promise对象。返回true表示共享库正在使用，返回false表示共享库不在使用。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const bundleName = "this is a bundleName";
const versionCode = 1;

appManager.isSharedBundleRunning(bundleName, versionCode).then((data) => {
  console.info(`The shared bundle running is: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
  console.error(`error: ${JSON.stringify(error)}`);
});
```

## appManager.isSharedBundleRunning<sup>10+</sup>

isSharedBundleRunning(bundleName: string, versionCode: number, callback: AsyncCallback\<boolean>): void

检查共享库是否正在使用。使用callback异步回调。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| bundleName    | string   | 是    | 表示要查询的共享库包名。 |
| versionCode   | number   | 是    | 表示要查询的共享库版本号。      |
| callback    | AsyncCallback\<boolean>> | 是    | 回调函数。返回true表示共享库正在使用，返回false表示共享库不在使用。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';

const bundleName = "this is a bundleName";
const versionCode = 1;

appManager.isSharedBundleRunning(bundleName, versionCode, (err, data) => {
  if (err) {
    console.error(`err: ${JSON.stringify(err)}`);
  } else {
    console.info(`The shared bundle running is: ${JSON.stringify(data)}`);
  }
});
```

## appManager.on('appForegroundState')<sup>11+</sup>

on(type: 'appForegroundState', observer: AppForegroundStateObserver): void

注册应用启动和退出的观测器，可用于系统应用观测所有应用的启动和退出。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型，固定填'appForegroundState'字符串。 |
| observer | [AppForegroundStateObserver](js-apis-inner-application-appForegroundStateObserver-sys.md) | 是 | 应用状态观测器，用于观测应用的启动和退出。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: appManager.AppForegroundStateObserver = {
  onAppStateChanged(appStateData) {
    console.info(`[appManager] onAppStateChanged: ${JSON.stringify(appStateData)}`);
  },
};

try {
  appManager.on('appForegroundState', observer);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.on('abilityFirstFrameState')<sup>12+</sup>

on(type: 'abilityFirstFrameState', observer: AbilityFirstFrameStateObserver, bundleName?: string): void

注册监听Ability首帧绘制完成事件观察者对象，可用于系统应用监听Ability首帧绘制事件。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | 是   | 调用接口类型，固定填'abilityFirstFrameState'字符串。         |
| observer   | [AbilityFirstFrameStateObserver](js-apis-inner-application-abilityFirstFrameStateObserver-sys.md) | 是   | 表示待注册的Ability首帧绘制完成事件观察者对象。              |
| bundleName | string                                                       | 否   | 表示待监听的Ability的应用bundleName，不填表示注册监听所有应用ability首帧绘制完成事件。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityFirstFrameStateObserverForAll: appManager.AbilityFirstFrameStateObserver = {
  onAbilityFirstFrameDrawn(abilityStateData: appManager.AbilityFirstFrameStateData) {
    console.info("abilityFirstFrame: ", JSON.stringify(abilityStateData));
  }
};

try {
  appManager.on('abilityFirstFrameState', abilityFirstFrameStateObserverForAll);
} catch (e) {
  let code = (e as BusinessError).code;
  let message = (e as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.off('appForegroundState')<sup>11+</sup>

off(type: 'appForegroundState', observer?: AppForegroundStateObserver): void

取消注册应用启动和退出的观测器。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型，固定填'appForegroundState'字符串。|
| observer | [AppForegroundStateObserver](js-apis-inner-application-appForegroundStateObserver-sys.md) | 否 | 取消注册的应用启动和退出观测器。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer_: appManager.AppForegroundStateObserver | undefined;
// 1.注册应用启动和退出的监听器
let observer: appManager.AppForegroundStateObserver = {
  onAppStateChanged(appStateData: appManager.AppStateData) {
    console.info(`[appManager] onAppStateChanged: ${JSON.stringify(appStateData)}`);
  },
};

try {
  appManager.on('appForegroundState', observer);
  // 保存observer对象，用于注销
  observer_ = observer;
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}

// 2.注销监听器
try {
  appManager.off('appForegroundState',  observer_);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.off('abilityFirstFrameState')<sup>12+</sup>

off(type: 'abilityFirstFrameState', observer?: AbilityFirstFrameStateObserver): void

取消注册监听Ability首帧绘制完成事件观察者对象。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 调用接口类型，固定填'abilityFirstFrameState'字符串。         |
| observer | [AbilityFirstFrameStateObserver](js-apis-inner-application-abilityFirstFrameStateObserver-sys.md) | 否   | 表示待取消的Ability首帧绘制完成事件观察者对象，不填表示取消所有监听对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityFirstFrameStateObserverForAll: appManager.AbilityFirstFrameStateObserver = {
  onAbilityFirstFrameDrawn(abilityStateData: appManager.AbilityFirstFrameStateData) {
    console.info("abilityFirstFrame: ", JSON.stringify(abilityStateData));
  }
};

try {
  appManager.on('abilityFirstFrameState', abilityFirstFrameStateObserverForAll);
} catch (e) {
  let code = (e as BusinessError).code;
  let message = (e as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}

try {
  appManager.off('abilityFirstFrameState', abilityFirstFrameStateObserverForAll);
} catch (e) {
  let code = (e as BusinessError).code;
  let message = (e as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.getForegroundApplications

getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void

获取当前所有前台应用的信息。该应用信息由[AppStateData](js-apis-inner-application-appStateData.md)定义。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | 是 | 以回调方式方式返回接口运行结果及应用状态数据数组，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function getForegroundApplicationsCallback(err: BusinessError, data: Array<appManager.AppStateData>) {
  if (err) {
    console.error(`getForegroundApplicationsCallback fail, err: ${JSON.stringify(err)}`);
  } else {
    console.info(`getForegroundApplicationsCallback success, data: ${JSON.stringify(data)}`);
  }
}

try {
  appManager.getForegroundApplications(getForegroundApplicationsCallback);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.getForegroundApplications

getForegroundApplications(): Promise\<Array\<AppStateData>>

获取当前所有前台应用的信息。该应用信息由[AppStateData](js-apis-inner-application-appStateData.md)定义。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | 返回前台进程应用程序的数组。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

appManager.getForegroundApplications().then((data) => {
  console.info(`getForegroundApplications success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getForegroundApplications fail, err: ${JSON.stringify(err)}`);
});
```

## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number): Promise\<void\>

终止account进程。使用Promise异步回调。

> **说明：**
>
> 当accountId为当前用户时，不需要校验ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS, ohos.permission.KILL_APP_PROCESSES or ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | Bundle名称。 |
| accountId | number | 是 | 系统账号的账号ID，详情参考[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)。 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'bundleName';
let accountId = 0;

try {
  appManager.killProcessWithAccount(bundleName, accountId).then(() => {
    console.info('killProcessWithAccount success');
  }).catch((err: BusinessError) => {
    console.error(`killProcessWithAccount fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.killProcessWithAccount<sup>14+</sup>

killProcessWithAccount(bundleName: string, accountId: number, clearPageStack: boolean, appIndex?: number): Promise\<void\>

终止account进程。使用Promise异步回调。

> **说明：**
>
> 当accountId为当前用户时，不需要校验ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS, ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | Bundle名称。 |
| accountId | number | 是 | 系统账号的账号ID，详情参考[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)。 |
| clearPageStack | boolean | 是 | 表示是否清除页面堆栈。true表示清除，false表示不清除。 |
| appIndex | number | 否 | 应用分身ID。 |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'bundleName';
let accountId = 0;
let isClearPageStack = false;
let appIndex = 1;

try {
  appManager.killProcessWithAccount(bundleName, accountId, isClearPageStack, appIndex).then(() => {
    console.info('killProcessWithAccount success');
  }).catch((err: BusinessError) => {
    console.error(`killProcessWithAccount fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void\>): void

终止account进程。使用callback异步回调。

> **说明：**
>
> 当accountId为当前用户时，不需要校验ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS, ohos.permission.KILL_APP_PROCESSES or ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用Bundle名称。 |
  | accountId | number | 是 | 系统账号的账号ID，详情参考[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9)。 |
  | callback | AsyncCallback\<void\> | 是 | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'bundleName';
let accountId = 0;

function killProcessWithAccountCallback(err: BusinessError) {
  if (err) {
    console.error(`killProcessWithAccountCallback fail, err: ${JSON.stringify(err)}`);
  } else {
    console.info('killProcessWithAccountCallback success.');
  }
}

appManager.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);
```

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>)

通过Bundle名称终止进程。

**需要权限**：ohos.permission.KILL_APP_PROCESSES or ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |
| callback | AsyncCallback\<void> | 是 | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'bundleName';

function killProcessesByBundleNameCallback(err: BusinessError) {
  if (err) {
    console.error(`killProcessesByBundleNameCallback fail, err: ${JSON.stringify(err)}`);
  } else {
    console.info('killProcessesByBundleNameCallback success.');
  }
}

try {
  appManager.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string): Promise\<void>

通过Bundle名称终止进程。

**需要权限**：ohos.permission.KILL_APP_PROCESSES or ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'bundleName';

try {
  appManager.killProcessesByBundleName(bundleName).then((data) => {
    console.info('killProcessesByBundleName success.');
  }).catch((err: BusinessError) => {
    console.error(`killProcessesByBundleName fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>)

通过Bundle名称清除应用数据。

**需要权限**：ohos.permission.CLEAN_APPLICATION_DATA

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | Bundle名称。 |
| callback | AsyncCallback\<void> | 是 | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'bundleName';

function clearUpApplicationDataCallback(err: BusinessError) {
  if (err) {
    console.error(`clearUpApplicationDataCallback fail, err: ${JSON.stringify(err)}`);
  } else {
    console.info('clearUpApplicationDataCallback success.');
  }
}

try {
  appManager.clearUpApplicationData(bundleName, clearUpApplicationDataCallback);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string): Promise\<void>

通过Bundle名称清除应用数据。

**需要权限**：ohos.permission.CLEAN_APPLICATION_DATA

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 以Promise方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'bundleName';

try {
  appManager.clearUpApplicationData(bundleName).then((data) => {
    console.info('clearUpApplicationData success.');
  }).catch((err: BusinessError) => {
    console.error(`clearUpApplicationData fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.getProcessMemoryByPid<sup>10+</sup>

getProcessMemoryByPid(pid: number, callback: AsyncCallback\<number>): void

通过pid查询对应进程占用的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pid | number | 是 | 表示进程id，详情参考[getRunningProcessInfoByBundleName](#appmanagergetrunningprocessinfobybundlename10)。 |
| callback | AsyncCallback\<number> | 是 | 以回调方式返回接口运行结果及进程占用的内存大小（单位KB），可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let pid = 0;
function getProcessMemoryByPidCallback(err: BusinessError, data: number) {
  if (err) {
    console.error(`getProcessMemoryByPidCallback fail, err: ${JSON.stringify(err)}`);
  } else {
    console.info('getProcessMemoryByPidCallback success.');
  }
}

try {
  appManager.getProcessMemoryByPid(pid, getProcessMemoryByPidCallback);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.getProcessMemoryByPid<sup>10+</sup>

getProcessMemoryByPid(pid: number): Promise\<number>

通过pid查询对应进程占用的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pid | number | 是 | 表示进程id，详情参考[getRunningProcessInfoByBundleName](#appmanagergetrunningprocessinfobybundlename10)。  |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise方式返回接口运行结果及进程占用的内存大小（单位KB），可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let pid = 0;

try {
  appManager.getProcessMemoryByPid(pid).then((data) => {
    console.info('getProcessMemoryByPid success.');
  }).catch((err: BusinessError) => {
    console.error(`getProcessMemoryByPid fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.getRunningProcessInfoByBundleName<sup>10+</sup>

getRunningProcessInfoByBundleName(bundleName: string, callback: AsyncCallback\<Array\<ProcessInformation>>): void

通过bundleName获取有关运行进程的信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |
| callback | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | 是 | 以回调方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = "bundleName";
function getRunningProcessInfoByBundleNameCallback(err: BusinessError, data: Array<appManager.ProcessInformation>) {
  if (err) {
    console.error(`getRunningProcessInfoByBundleNameCallback fail, err: ${JSON.stringify(err)}`);
  } else {
    console.info('getRunningProcessInfoByBundleNameCallback success.');
  }
}

try {
  appManager.getRunningProcessInfoByBundleName(bundleName, getRunningProcessInfoByBundleNameCallback);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.getRunningProcessInfoByBundleName<sup>10+</sup>

getRunningProcessInfoByBundleName(bundleName: string): Promise\<Array\<ProcessInformation>>

通过bundleName获取有关运行进程的信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | 以Promise方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = "bundleName";

try {
  appManager.getRunningProcessInfoByBundleName(bundleName).then((data) => {
    console.info('getRunningProcessInfoByBundleName success.');
  }).catch((err: BusinessError) => {
    console.error(`getRunningProcessInfoByBundleName fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.getRunningProcessInfoByBundleName<sup>10+</sup>

getRunningProcessInfoByBundleName(bundleName: string, userId: number, callback: AsyncCallback\<Array\<ProcessInformation>>): void

通过bundleName和userId获取有关运行进程的信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |
| userId | number | 是 | 表示用户Id。 |
| callback | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | 是 | 以回调方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = "bundleName";
let userId = 0;
function getRunningProcessInfoByBundleNameCallback(err: BusinessError, data: Array<appManager.ProcessInformation>) {
  if (err) {
    console.error(`getRunningProcessInfoByBundleNameCallback fail, err: ${JSON.stringify(err)}`);
  } else {
    console.info('getRunningProcessInfoByBundleNameCallback success.');
  }
}

try {
  appManager.getRunningProcessInfoByBundleName(bundleName, userId, getRunningProcessInfoByBundleNameCallback);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.getRunningProcessInfoByBundleName<sup>10+</sup>

getRunningProcessInfoByBundleName(bundleName: string, userId: number): Promise\<Array\<ProcessInformation>>

通过bundleName和userId获取有关运行进程的信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |
| userId | number | 是 | 表示用户Id。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | 以Promise方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = "bundleName";
let userId = 0;

try {
  appManager.getRunningProcessInfoByBundleName(bundleName, userId).then((data) => {
    console.info('getRunningProcessInfoByBundleName success.');
  }).catch((err: BusinessError) => {
    console.error(`getRunningProcessInfoByBundleName fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.isApplicationRunning<sup>11+</sup>

isApplicationRunning(bundleName: string): Promise\<boolean>

查询单个应用是否正在运行。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| bundleName    | string   | 是    | 表示要查询的应用的包名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<boolean> | Promise对象。返回true表示查询的应用正在运行，返回false表示查询的应用没有运行。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = "com.example.myapplication";

appManager.isApplicationRunning(bundleName).then((data) => {
  console.info(`The application running is: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
  console.error(`error: ${JSON.stringify(error)}`);
});
```

## appManager.isApplicationRunning<sup>11+</sup>

isApplicationRunning(bundleName: string, callback: AsyncCallback\<boolean>): void

查询单个应用是否正在运行。使用callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| bundleName    | string   | 是    | 表示要查询的共享库包名。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示查询的应用正在运行，返回false表示查询的应用没有运行。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = "com.example.myapplication";

try {
  appManager.isApplicationRunning(bundleName, (err, data) => {
    if (err) {
      console.error(`err: ${JSON.stringify(err)}`);
    } else {
      console.info(`The application running is: ${JSON.stringify(data)}`);
    }
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## ApplicationState

应用状态，该类型为枚举，可配合[AbilityStateData](js-apis-inner-application-abilityStateData.md)返回相应的应用状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 0   |   应用处于创建状态。         |
| STATE_FOREGROUND          | 2   |      应用处于前台状态。            |
| STATE_ACTIVE  | 3   |     应用处于获焦状态。     |
| STATE_BACKGROUND        | 4   |    应用处于后台不可见状态。           |
| STATE_DESTROY        | 5   |    应用处于销毁状态。       |


## appManager.getRunningProcessInformationByBundleType<sup>12+</sup>

getRunningProcessInformationByBundleType(bundleType: bundleManager.BundleType): Promise\<Array\<ProcessInformation>>

根据包类型获取当前运行进程的有关信息。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| bundleType    | [bundleManager.BundleType](js-apis-bundleManager.md#bundletype)  | 是    | 表示要查询的包类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise对象，返回特定包类型的运行进程的信息。 |

**错误码**：
以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |


**示例：**

```ts
import { appManager, bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  appManager.getRunningProcessInformationByBundleType(bundleManager.BundleType.ATOMIC_SERVICE)
    .then((data) => {
      console.info(`The running process information is: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.preloadApplication<sup>12+</sup>

preloadApplication(bundleName: string, userId: number, mode: PreloadMode, appIndex?: number): Promise\<void>

预加载应用进程。接口返回成功并不代表预加载成功，具体结果以目标应用进程是否创建成功为准。使用Promise异步回调。

**需要权限**：ohos.permission.PRELOAD_APPLICATION

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 预加载的应用包名。 |
| userId | number | 是 | 预加载的用户Id。 |
| mode | [PreloadMode](#appmanagerpreloadmode12) | 是 | 预加载模式。 |
| appIndex | number | 否 | 预加载应用分身的appIndex。 |

**返回值：**

| 类型           | 说明              |
| -------------- | ---------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | The application does not have permission to call the interface. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000050 | Internal error. |
| 16300005 | The target bundle does not exist. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  let bundleName = "ohos.samples.etsclock";
  let userId = 100;
  let mode = appManager.PreloadMode.PRESS_DOWN;
  let appIndex = 0;
  appManager.preloadApplication(bundleName, userId, mode, appIndex)
    .then(() => {
      hilog.info(0x0000, 'testTag', `preloadApplication success`);
    })
    .catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `preloadApplication error, code: ${err.code}, msg:${err.message}`);
    })
} catch (err) {
  hilog.error(0x0000, 'testTag', `preloadApplication error, code: ${(err as BusinessError).code}, msg:${(err as BusinessError).message}`);
}
```

## appManager.getRunningMultiAppInfo<sup>12+</sup>

getRunningMultiAppInfo(bundleName: string): Promise\<RunningMultiAppInfo>

根据应用包名获取系统中运行态的应用多开（即在一个设备上运行多个相同的应用）的相关信息，使用Promise异步回调。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 查询的应用包名。 |

**返回值：**

| 类型           | 说明              |
| -------------- | ---------------- |
| Promise\<[RunningMultiAppInfo](js-apis-inner-application-runningMultiAppInfo-sys.md)> | Promise对象。返回特定包名的运行态应用多开信息。 |

**错误码**：

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | The application does not have permission to call the interface. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000072 | App clone or multi-instance is not supported. |
| 18500001 | The bundle does not exist or no patch has been applied. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName = "ohos.samples.etsclock";
  appManager.getRunningMultiAppInfo(bundleName).then((info: appManager.RunningMultiAppInfo) => {
      hilog.info(0x0000, 'testTag', `getRunningMultiAppInfo success`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `getRunningMultiAppInfo error, code: ${err.code}, msg:${err.message}`);
    })
} catch (err) {
  hilog.error(0x0000, 'testTag', `getRunningMultiAppInfo error, code: ${err.code}, msg:${err.message}`);
}
```

## appManager.terminateMission<sup>13+</sup>

terminateMission(missionId: number): Promise\<void>

关闭指定的任务。使用Promise异步回调。

**需要权限**：ohos.permission.KILL_APP_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| missionId | number | 是 | 任务ID，可通过[getMissionInfos](js-apis-app-ability-missionManager-sys.md#missionmanagergetmissioninfos)获取。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**示例：**
```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Button('start link', { type: ButtonType.Capsule, stateEffect: true })
      .width('87%')
      .height('5%')
      .margin({ bottom: '12vp' })
      .onClick(() => {
        let missionId: number = 0;
        try {
          appManager.terminateMission(missionId).then(()=>{
              console.info('terminateMission success.');
            }).catch((err: BusinessError)=>{
              console.error('terminateMission failed. err: ' + JSON.stringify(err));
            })
        } catch (paramError) {
          let code = (paramError as BusinessError).code;
          let message = (paramError as BusinessError).message;
          console.error(`[appManager] error: ${code}, ${message}`);
        }
      })
  }
}
```

## appManager.getSupportedProcessCachePids<sup>14+</sup>

getSupportedProcessCachePids(bundleName : string): Promise\<Array\<number>>

查询当前应用中支持缓存后快速启动的进程PID。

> **说明：**
>
> 本接口仅支持获取调用者所在系统账号下的进程PID。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName    | string   | 是    | 表示要查询的应用包名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<number>> | Promise对象。返回一个数组，包含当前应用中支持缓存后快速启动的所有进程PID。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName = "ohos.samples.processcache";
  appManager.getSupportedProcessCachePids(bundleName).then((pids: Array<number>) => {
      hilog.info(0x0000, 'testTag', `pids: ${JSON.stringify(pids)}`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `get pids error, code: ${err.code}, msg:${err.message}`);
    })
} catch (err) {
  hilog.error(0x0000, 'testTag', `get pids error, code: ${err.code}, msg:${err.message}`);
}
```

## appManager.clearUpAppData<sup>13+</sup>

clearUpAppData(bundleName: string, appCloneIndex?: number): Promise\<void>

根据Bundle名称和应用分身索引，清除指定应用的数据。

**需要权限**：ohos.permission.CLEAN_APPLICATION_DATA

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |
| appCloneIndex | number | 否 | 表示应用分身索引。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |
| 16000073 | The app clone index is invalid. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName: string = 'com.ohos.demo';
let appCloneIndex: number = 0;

try {
  appManager.clearUpAppData(bundleName, appCloneIndex).then(() => {
    console.info(`clearUpAppData success.`);
  }).catch((err: BusinessError) => {
    console.error(`clearUpAppData fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```

## appManager.setKeepAliveForBundle<sup>14+</sup>

setKeepAliveForBundle(bundleName: string, userId: number, enable: boolean): Promise\<void>

为指定用户下的应用设置或取消保活。使用Promise异步回调。

> **说明：**
>
>- 应用如果需要支持保活，其[module.json5配置文件](../../quick-start/module-configuration-file.md)中的mainElement必须是UIAbility。只有当mainElement启动后，系统才会执行应用保活操作。
>- 在2in1设备上，被保活的应用需要在启动后5秒内添加至状态栏。否则，系统将取消该应用的保活设置，并杀死保活重启的进程。
>- 当被保活的应用进程退出时，系统将尝试重启该进程，连续3次重启失败后将不再继续重启。

**需要权限**：ohos.permission.MANAGE_APP_KEEP_ALIVE

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：从API version 18开始，该接口仅在2in1和Wearable设备上生效。对于API version 18之前版本，该接口仅在2in1设备上生效。其他情况下调用该接口将返回错误码801。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName    | string   | 是    | 表示要设置保活的应用包名。 |
| userId    | number   | 是    | 表示要设置保活应用所属的用户ID。 |
| enable    | boolean   | 是    | 表示对应用保活或者取消保活。true表示对应用保活，false表示对应用取消保活。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。|

**错误码**:

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |
| 16300005 | The target bundle does not exist. |
| 16300008 | The target bundle has no MainAbility. |
| 16300009 | The target bundle has no status-bar ability. |
| 16300010 | The target application is not attached to the status bar. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName = "ohos.samples.keepaliveapp";
  let userId = 100;
  appManager.setKeepAliveForBundle(bundleName, userId, true).then(() => {
    console.info(`setKeepAliveForBundle success`);
  }).catch((err: BusinessError) => {
    console.error(`setKeepAliveForBundle fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] setKeepAliveForBundle error: ${code}, ${message}`);
}
```

## appManager.getKeepAliveBundles<sup>14+</sup>

getKeepAliveBundles(type: KeepAliveAppType, userId?: number): Promise\<Array\<KeepAliveBundleInfo>>

获取指定用户下指定类型的保活应用信息。该应用信息由[KeepAliveBundleInfo](#keepalivebundleinfo14)定义。
使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_APP_KEEP_ALIVE

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口在PC/2in1中可正常调用，在其他设备类型中返回801错误码。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type    | [KeepAliveAppType](#keepaliveapptype14)   | 是    | 表示要查询的保活应用类型。 |
| userId    | number   | 否    | 表示要设置保活应用所属的用户ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[KeepAliveBundleInfo](#keepalivebundleinfo14)>> | Promise对象，返回用户保活应用信息的数组。|

**错误码**:

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let userId = 100;
let type: appManager.KeepAliveAppType = appManager.KeepAliveAppType.THIRD_PARTY;
try {
  appManager.getKeepAliveBundles(type, userId).then((data) => {
    console.info(`getKeepAliveBundles success, data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`getKeepAliveBundles fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] getKeepAliveBundles error: ${code}, ${message}`);
}
```


## appManager.killProcessesInBatch<sup>14+</sup>

killProcessesInBatch(pids: Array\<number>): Promise\<void>

批量查杀进程。

**需要权限**：ohos.permission.KILL_APP_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口在PC/2in1中可正常调用，在其他设备类型中返回801错误码。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pids    | Array\<number>   | 是    | 要查杀的进程ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**:

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let pids: Array<number> = [100, 101, 102];
  appManager.killProcessesInBatch(pids).then(() => {
    console.info(`killProcessesInBatch success`);
  }).catch((err: BusinessError) => {
    console.error(`killProcessesInBatch fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] killProcessesInBatch error: ${code}, ${message}`);
}
```

## appManager.setKeepAliveForAppServiceExtension<sup>20+</sup>

setKeepAliveForAppServiceExtension(bundleName: string, enabled: boolean): Promise\<void>

为AppServiceExtensionAbility设置保活或取消保活。使用Promise异步回调。
> **说明：**
>
> - 仅当应用安装在userId为1的用户下，且应用中entry类型的HAP的module.json5配置文件中的mainElement字段配置为AppServiceExtensionAbility时，该接口才生效。

**需要权限**：ohos.permission.MANAGE_APP_KEEP_ALIVE

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口在PC/2in1中可正常调用，在其他设备类型中返回801错误码。

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName    | string   | 是    | 表示要设置保活的应用包名。 |
| enabled    | boolean   | 是    | 表示是否进行应用保活。true表示保活，false表示不保活。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。|

**错误码**:

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |
| 16000081 | Failed to obtain the target application information. |
| 16000202 | Invalid main element type. |
| 16000203 | Cannot change the keep-alive status. |
| 16000204 | The target bundle is not in u1. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName = "ohos.samples.keepaliveapp";
  appManager.setKeepAliveForAppServiceExtension(bundleName, true).then(() => {
    console.info(`setKeepAliveForAppServiceExtension success`);
  }).catch((err: BusinessError) => {
    console.error(`setKeepAliveForAppServiceExtension fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] setKeepAliveForAppServiceExtension error: ${code}, ${message}`);
}
```

## appManager.getKeepAliveAppServiceExtensions<sup>20+</sup>

getKeepAliveAppServiceExtensions(): Promise\<Array\<KeepAliveBundleInfo>>

获取所有保活的AppServiceExtensionAbility应用信息，此信息由[KeepAliveBundleInfo](#keepalivebundleinfo14)定义。使用Promise异步回调。


**需要权限**：ohos.permission.MANAGE_APP_KEEP_ALIVE

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口在PC/2in1中可正常调用，在其他设备类型中返回801错误码。

**系统接口**：此接口为系统接口。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[KeepAliveBundleInfo](#keepalivebundleinfo14)>> | Promise对象，返回用户保活应用信息的数组。|

**错误码**:

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  appManager.getKeepAliveAppServiceExtensions().then((data) => {
    console.info(`getKeepAliveAppServiceExtensions success, data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`getKeepAliveAppServiceExtensions fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] getKeepAliveAppServiceExtensions error: ${code}, ${message}`);
}
```

## AppForegroundStateObserver<sup>11+</sup>

type AppForegroundStateObserver = _AppForegroundStateObserver

应用启动和退出的状态监听。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AppForegroundStateObserver](js-apis-inner-application-appForegroundStateObserver-sys.md) | 应用启动和退出的状态监听。 |

## AbilityFirstFrameStateObserver<sup>12+</sup>

type AbilityFirstFrameStateObserver = _AbilityFirstFrameStateObserver

UIAbility首帧绘制完成事件监听对象。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityFirstFrameStateObserver](js-apis-inner-application-abilityFirstFrameStateData-sys.md) | UIAbility首帧绘制完成事件监听对象。 |

## AbilityFirstFrameStateData<sup>12+</sup>

type AbilityFirstFrameStateData = _AbilityFirstFrameStateData

UIAbility首帧绘制完成回调上报数据结构。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityFirstFrameStateData](js-apis-inner-application-abilityFirstFrameStateData-sys.md) | UIAbility首帧绘制完成回调上报数据结构。 |

## RunningMultiAppInfo<sup>12+</sup>

type RunningMultiAppInfo = _RunningMultiAppInfo

应用多开在运行态的结构信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_RunningMultiAppInfo](js-apis-inner-application-runningMultiAppInfo-sys.md) | 应用多开在运行态的结构信息。 |
