# ApplicationStateObserver

定义应用状态监听。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| onForegroundApplicationChanged<sup>8+</sup>         | AsyncCallback\<void>   | 是   | 否   | 应用前后台状态发生变化时执行的回调函数。                    |
| onAbilityStateChanged<sup>8+</sup>  | AsyncCallback\<void>   | 是   | 否  | ability状态发生变化时执行的回调函数。                  |
| onProcessCreated<sup>8+</sup>         | AsyncCallback\<void>   | 是   | 否   | 进程创建时执行的回调函数。                  |
| onProcessDied<sup>8+</sup>         | AsyncCallback\<void>   | 是   | 否   | 进程销毁时执行的回调函数。                  |
| onProcessStateChanged<sup>8+</sup>         | AsyncCallback\<void>   | 是   | 否   | 进程状态更新时执行的回调函数。                  |

**示例：**
```ts
import appManager from "@ohos.application.appManager"

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
        console.log('onProcessStateChanged onProcessStateChanged: ' +  JSON.stringify(processData));
    }
}
let observerCode = appManager.registerApplicationStateObserver(applicationStateObserver);
```