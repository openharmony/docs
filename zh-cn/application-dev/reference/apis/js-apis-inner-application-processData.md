# ProcessData

定义进程数据，可以通过[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)注册生命周期变化监听后，通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onProcessCreated生命周期回调获取。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid<sup>8+</sup>         | number   | 是   | 否   | 进程ID。                    |
| bundleName<sup>8+</sup>  | string   | 是   | 否  | 应用包名。                  |
| uid<sup>8+</sup>         | number   | 是   | 否   | 用户ID。                  |
| isContinuousTask<sup>9+</sup>         | boolean   | 是   | 否   | 判断过程是否为连续任务。                  |
| isKeepAlive<sup>9+</sup>         | boolean   | 是   | 否   | 判断该过程是否保持活跃。                  |

**示例：**
```ts
import appManager from '@ohos.application.appManager'

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
}
let observerCode = appManager.registerApplicationStateObserver(applicationStateObserver);
```