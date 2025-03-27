# ProcessData

进程数据的对象定义。使用接口[on](js-apis-app-ability-appManager.md#appmanageronapplicationstate)注册生命周期变化监听后，当应用或组件的生命周期变化时，系统通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onProcessCreated等方法回调给开发者。

> **说明：**
> 
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                     | 类型     | 必填 | 说明                       |
| ----------------------- | ---------| ---- | ------------------------- |
| pid         | number   | 是   | 进程ID。                    |
| bundleName  | string   | 是   | 应用包名。                  |
| uid         | number   | 是   | 应用的uid。                  |
| isContinuousTask | boolean   | 是   | 是否为长时任务，true表示是，false表示不是。                 |
| isKeepAlive      | boolean   | 是   | 是否为常驻进程，true表示是，false表示不是                   |
| state       | number   | 是   | 应用的状态，取值及对应的状态为：<br>0 - 刚创建，<br>1 - 准备就绪，<br>2 - 前台，<br>4 - 后台，<br>5 - 已终止。     |

**示例：**
```ts
import { appManager } from '@kit.AbilityKit';

let observerCode = appManager.on('applicationState', {
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
    console.log(`onProcessStateChanged processData.pid : ${JSON.stringify(processData.pid)}`);
    console.log(`onProcessStateChanged processData.bundleName : ${JSON.stringify(processData.bundleName)}`);
    console.log(`onProcessStateChanged processData.uid : ${JSON.stringify(processData.uid)}`);
    console.log(`onProcessStateChanged processData.isContinuousTask : ${JSON.stringify(processData.isContinuousTask)}`);
    console.log(`onProcessStateChanged processData.isKeepAlive : ${JSON.stringify(processData.isKeepAlive)}`);
  },
  onAppStarted(appStateData) {
    console.log(`onAppStarted appStateData: ${JSON.stringify(appStateData)}`);
  },
  onAppStopped(appStateData) {
    console.log(`onAppStopped appStateData: ${JSON.stringify(appStateData)}`);
  }
});
```