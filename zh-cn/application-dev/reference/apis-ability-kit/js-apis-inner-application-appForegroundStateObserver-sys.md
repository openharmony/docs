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

## 属性

**系统接口**: 此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                             | 类型                    | 可读 | 可写 | 说明   |
| -------------------------------- | ---------------------- | ---- | ---- | ------------------ |
| onAppStateChanged   | AsyncCallback\<void>   | 是   | 否   | 应用启动和退出状态发生变化时执行的回调函数。传入参数类型是[AppStateData](js-apis-inner-application-appStateData-sys.md)。 |

**示例：**
```ts
import { appManager } from '@kit.AbilityKit';

let observer: appManager.AppForegroundStateObserver = {
  onAppStateChanged(appStateData) {
    console.log(`onAppStateChanged appStateData: ${JSON.stringify(appStateData)}`);
  },
};
appManager.on('appForegroundState', observer);
```