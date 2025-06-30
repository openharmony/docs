# AppForegroundStateObserver (系统接口)

定义应用启动和退出的状态监听，可以作为[on](js-apis-app-ability-appManager-sys.md#appmanageronappforegroundstate11)的入参监听所有应用的启动和退出的变化。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## AppForegroundStateObserver

### onAppStateChanged

onAppStateChanged(appStateData: AppStateData): void

应用启动和退出状态发生变化时，系统会触发该回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名  | 类型 | 必填 | 说明   |
| ------ | ---- | ---- | ---- -|
| appStateData   | [AppStateData](js-apis-inner-application-appStateData.md)   | 是  | 应用状态信息。 |

**示例：**
```ts
import { appManager } from '@kit.AbilityKit';

let observer: appManager.AppForegroundStateObserver = {
  onAppStateChanged(appStateData) {
    console.info(`onAppStateChanged appStateData: ${JSON.stringify(appStateData)}`);
  },
};
appManager.on('appForegroundState', observer);
```