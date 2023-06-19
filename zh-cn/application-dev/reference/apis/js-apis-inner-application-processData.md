# ProcessData

定义进程数据，可以通过[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)注册生命周期变化监听后，通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onProcessCreated生命周期回调获取。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```ts
import appManager from '@ohos.application.appManager';
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid         | number   | 是   | 否   | 进程ID。                    |
| bundleName  | string   | 是   | 否  | 应用包名。                  |
| uid         | number   | 是   | 否   | 应用的uid。                  |
| isContinuousTask<sup>9+</sup>         | boolean   | 是   | 否   | 是否为长时任务，true表示是，false表示不是                 |
| isKeepAlive<sup>9+</sup>         | boolean   | 是   | 否   | 是否为常驻进程，true表示是，false表示不是                   |
| state<sup>9+</sup>       | number   | 是   | 否   | 应用的状态，取值及对应的状态为：0(刚创建)，2(前台)，4(后台)，5(已终止)。     |

**示例：**
```ts
import appManager from '@ohos.application.appManager';

let applicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log('onForegroundApplicationChanged appStateData: ' +  JSON.stringify(appStateData));
    },
    onAbilityStateChanged(abilityStateData) {
        console.log('onAbilityStateChanged onAbilityStateChanged: ' +  JSON.stringify(abilityStateData));
    },
    onProcessCreated(processData) {
        console.log('onProcessCreated onProcessCreated: '  +  JSON.stringify(processData));
    },
    onProcessDied(processData) {
        console.log('onProcessDied onProcessDied: '  +  JSON.stringify(processData));
    },
    onProcessStateChanged(processData) {
        console.log('onProcessStateChanged processData.pid : ' +  JSON.stringify(processData.pid));
        console.log('onProcessStateChanged processData.bundleName : ' +  JSON.stringify(processData.bundleName));
        console.log('onProcessStateChanged processData.uid : ' +  JSON.stringify(processData.uid));
        console.log('onProcessStateChanged processData.isContinuousTask : ' +  JSON.stringify(processData.isContinuousTask));
        console.log('onProcessStateChanged processData.isKeepAlive : ' +  JSON.stringify(processData.isKeepAlive));
    }
};
let observerCode = appManager.registerApplicationStateObserver(applicationStateObserver);
```