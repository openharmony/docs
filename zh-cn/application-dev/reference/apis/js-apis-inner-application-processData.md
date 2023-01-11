# ProcessData

进程数据的对象定义。使用接口[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)注册生命周期变化监听后，当应用或组件的生命周期变化时，系统通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onProcessCreated等方法回调给开发者。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid<sup>8+</sup>         | number   | 是   | 否   | 进程ID。                    |
| bundleName<sup>8+</sup>  | string   | 是   | 否  | 应用包名。                  |
| uid<sup>8+</sup>         | number   | 是   | 否   | 应用的uid。                  |
| isContinuousTask<sup>9+</sup>         | boolean   | 是   | 否   | 是否为长时任务，true表示是，false表示不是                 |
| isKeepAlive<sup>9+</sup>         | boolean   | 是   | 否   | 是否为常驻进程，true表示是，false表示不是                   |
| state<sup>9+</sup>       | number   | 是   | 否   | 应用的状态，取值及对应的状态为：0(刚创建)，2(前台)，4(后台)，5(已终止)。     |

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