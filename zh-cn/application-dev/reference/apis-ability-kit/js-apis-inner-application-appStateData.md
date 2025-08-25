# AppStateData
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

定义应用状态信息，可以通过[appManager.on('applicationState')](./js-apis-app-ability-appManager.md#appmanageronapplicationstate14)获取当前应用的相关信息。

> **说明：**
> 
> 本模块首批接口从API version 14 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 类型   | 必填  | 说明       |
| ------------------------- | ------ | ---- | --------- |
| bundleName  | string | 是   | Bundle名称。 |
| uid          | number | 是   | 应用程序的uid。   |
| state        | number | 是   | 应用状态。<br>0：初始化状态，应用正在初始化<br>1：就绪状态，应用已初始化完毕<br>2：前台状态，应用位于前台<br>3：获焦状态。（预留状态，当前暂不支持）<br>4：后台状态，应用位于后台<br>5：退出状态，应用已退出 |
| isSplitScreenMode | boolean | 是 | 判断应用是否进入分屏模式。<br>true:应用处于分屏模式。<br>false:应用不处于分屏模式。 |
| isFloatingWindowMode | boolean | 是 | 判断应用是否进入悬浮窗模式。<br>true:应用处于浮窗模式。<br>false:应用不处于浮窗模式。 |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let applicationStateObserver: appManager.ApplicationStateObserver = {
  onForegroundApplicationChanged(appStateData) {
    console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);
    console.log(`appStateData.bundleName: ${appStateData.bundleName}`);
    console.log(`appStateData.uid: ${appStateData.uid}`);
    console.log(`appStateData.state: ${appStateData.state}`);
    console.log(`appStateData.isSplitScreenMode: ${appStateData.isSplitScreenMode}`);
    console.log(`appStateData.isFloatingWindowMode: ${appStateData.isFloatingWindowMode}`);
  },
  onAbilityStateChanged(abilityStateData) {
    console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
  onProcessCreated(processData) {
    console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);
  },
  onProcessDied(processData) {
    console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);
  },
  onProcessStateChanged(processData) {
    console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);
  },
  onAppStarted(appStateData) {
    console.log(`[appManager] onAppStarted: ${JSON.stringify(appStateData)}`);
  },
  onAppStopped(appStateData) {
    console.log(`[appManager] onAppStopped: ${JSON.stringify(appStateData)}`);
  }
};

try {
  const observerId = appManager.on('applicationState', applicationStateObserver);
  console.log(`[appManager] observerCode: ${observerId}`);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```
