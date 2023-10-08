# ApplicationStateObserver

定义应用状态监听，可以作为[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)的入参监听当前应用的生命周期变化。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```ts
import appManager from '@ohos.app.ability.appManager';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称                             | 类型                    | 可读 | 可写 | 说明   |
| -------------------------------- | ---------------------- | ---- | ---- | ------------------ |
| onForegroundApplicationChanged   | AsyncCallback\<void>   | 是   | 否   | 应用前后台状态发生变化时执行的回调函数。传入参数类型是[AppStateData](js-apis-inner-application-appStateData.md)。 |
| onAbilityStateChanged            | AsyncCallback\<void>   | 是   | 否  | ability状态发生变化时执行的回调函数。传入参数类型是[AppStateData](js-apis-inner-application-appStateData.md)。   |
| onProcessCreated                 | AsyncCallback\<void>   | 是   | 否   | 进程创建时执行的回调函数。传入参数类型是[ProcessData](js-apis-inner-application-processData.md)。          |
| onProcessDied                     | AsyncCallback\<void>   | 是   | 否   | 进程销毁时执行的回调函数。传入参数类型是[ProcessData](js-apis-inner-application-processData.md)。          |
| onProcessStateChanged<sup>9+</sup> | AsyncCallback\<void>   | 是   | 否   | 进程状态更新时执行的回调函数。传入参数类型是[ProcessData](js-apis-inner-application-processData.md)。        |

**示例：**
```ts
import appManager from '@ohos.app.ability.appManager';

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
    }
};
let observerCode = appManager.on('applicationState', applicationStateObserver);
```