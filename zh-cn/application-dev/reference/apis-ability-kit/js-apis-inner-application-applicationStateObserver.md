# ApplicationStateObserver

定义应用状态监听，可以作为[on](js-apis-app-ability-appManager.md#appmanageronapplicationstate)的入参监听当前应用的生命周期变化。

> **说明：**
> 
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## ApplicationStateObserver.onForegroundApplicationChanged

onForegroundApplicationChanged(appStateData: AppStateData): void

应用前后台状态发生变化时执行的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| appStateData | [AppStateData](js-apis-inner-application-appStateData.md) | 是 | 应用状态信息。 |

## ApplicationStateObserver.onAbilityStateChanged

onAbilityStateChanged(abilityStateData: AbilityStateData): void

ability状态发生变化时执行的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| abilityStateData | [AbilityStateData](js-apis-inner-application-abilityStateData.md) | 是 | Ability状态信息。 |

## ApplicationStateObserver.onProcessCreated

onProcessCreated(processData: ProcessData): void

进程创建时执行的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](js-apis-inner-application-processData.md) | 是 | 进程数据信息。 |

## ApplicationStateObserver.onProcessDied

onProcessDied(processData: ProcessData): void

进程销毁时执行的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](js-apis-inner-application-processData.md) | 是 | 进程数据信息。 |

## ApplicationStateObserver.onProcessStateChanged

onProcessStateChanged(processData: ProcessData): void

进程状态更新时执行的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](js-apis-inner-application-processData.md) | 是 | 进程数据信息。 |

## ApplicationStateObserver.onAppStarted

onAppStarted(appStateData: AppStateData): void

应用第一个进程创建时执行的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| appStateData | [AppStateData](js-apis-inner-application-appStateData.md) | 是 | 应用状态信息。 |

## ApplicationStateObserver.onAppStopped

onAppStopped(appStateData: AppStateData): void

应用最后一个进程销毁时执行的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| appStateData | [AppStateData](js-apis-inner-application-appStateData.md) | 是 | 应用状态信息。 |

## ProcessData

type ProcessData = _ProcessData.default

进程数据信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_ProcessData.default](js-apis-inner-application-processData.md) | 进程数据信息。 |

**示例：**
```ts
import { appManager } from '@kit.AbilityKit';

let applicationStateObserver: appManager.ApplicationStateObserver = {
  onForegroundApplicationChanged(appStateData) {
    console.log(`onForegroundApplicationChanged appStateData: ${JSON.stringify(appStateData)}`);
  },
  onAbilityStateChanged(abilityStateData) {
    console.log(`onAbilityStateChanged onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
  onProcessCreated(processData) {
    console.log(`onProcessCreated onProcessCreated: ${JSON.stringify(processData)}`);
  },
  onProcessDied(processData) {
    console.log(`onProcessDied onProcessDied: ${JSON.stringify(processData)}`);
  },
  onProcessStateChanged(processData) {
    console.log(`onProcessStateChanged onProcessStateChanged: ${JSON.stringify(processData)}`);
  },
  onAppStarted(appStateData) {
    console.log(`onAppStarted appStateData: ${JSON.stringify(appStateData)}`);
  },
  onAppStopped(appStateData) {
    console.log(`onAppStopped appStateData: ${JSON.stringify(appStateData)}`);
  }
};
let observerCode = appManager.on('applicationState', applicationStateObserver);
```