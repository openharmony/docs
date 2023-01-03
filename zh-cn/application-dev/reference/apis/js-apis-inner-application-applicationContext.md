# ApplicationContext

ApplicationContext模块提供开发者应用级别的的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 使用说明

在使用ApplicationContext的功能前，需要通过context的实例获取。

```ts
let applicationContext = this.context.getApplicationContext();
```

## ApplicationContext.registerAbilityLifecycleCallback

registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): **number**;

注册监听应用内生命周期

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| callback | [AbilityLifecycleCallback](js-apis-app-ability-abilityLifecycleCallback.md) | 是   | 回调方法，返回注册监听事件的ID。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| number | 返回的此次注册监听生命周期的ID（每次注册该ID会自增+1，当超过监听上限数量2^63-1时，返回-1）。|

**示例：**

```ts
import Ability from "@ohos.application.Ability";

var lifecycleId;

export default class MyAbility extends Ability {
    onCreate() {
        console.log("MyAbility onCreate")
        let AbilityLifecycleCallback = {
            onAbilityCreate(ability) {
                console.log("AbilityLifecycleCallback onAbilityCreate ability:" + JSON.stringify(ability));
            },
            onWindowStageCreate(ability, windowStage) {
                console.log("AbilityLifecycleCallback onWindowStageCreate ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageCreate windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageActive(ability, windowStage) {
                console.log("AbilityLifecycleCallback onWindowStageActive ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageActive windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageInactive(ability, windowStage) {
                console.log("AbilityLifecycleCallback onWindowStageInactive ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageInactive windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageDestroy(ability, windowStage) {
                console.log("AbilityLifecycleCallback onWindowStageDestroy ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageDestroy windowStage:" + JSON.stringify(windowStage));
            },
            onAbilityDestroy(ability) {
                console.log("AbilityLifecycleCallback onAbilityDestroy ability:" + JSON.stringify(ability));
            },
            onAbilityForeground(ability) {
                console.log("AbilityLifecycleCallback onAbilityForeground ability:" + JSON.stringify(ability));
            },
            onAbilityBackground(ability) {
                console.log("AbilityLifecycleCallback onAbilityBackground ability:" + JSON.stringify(ability));
            },
            onAbilityContinue(ability) {
                console.log("AbilityLifecycleCallback onAbilityContinue ability:" + JSON.stringify(ability));
            }
        }
        // 1.通过context属性获取applicationContext
        let applicationContext = this.context.getApplicationContext();
        // 2.通过applicationContext注册监听应用内生命周期
        lifecycleId = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
        console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleId));
    }
}
```

## ApplicationContext.unregisterAbilityLifecycleCallback

unregisterAbilityLifecycleCallback(callbackId: **number**,  callback: AsyncCallback<**void**>): **void**;

取消监听应用内生命周期

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | 是   | 注册监听应用内生命周期的ID。 |
| callback | AsyncCallback\<void> | 是   | 回调方法。                   |

**示例：**

```ts
import Ability from "@ohos.application.Ability";

var lifecycleId;

export default class MyAbility extends Ability {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        console.log("stage applicationContext: " + JSON.stringify(applicationContext));
        applicationContext.unregisterAbilityLifecycleCallback(lifecycleId, (error, data) => {
            console.log("unregisterAbilityLifecycleCallback success, err: " + JSON.stringify(error));
        });
    }
}
```

## ApplicationContext.registerEnvironmentCallback

registerEnvironmentCallback(callback: EnvironmentCallback): **number**;

注册对系统环境变化的监听。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| callback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | 是   | 回调方法，返回注册监听事件的ID。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| number | 返回的此次注册监听系统环境变化的ID（每次注册该ID会自增+1，当超过监听上限数量2^63-1时，返回-1）。|

**示例：**

```ts
import Ability from "@ohos.application.Ability";

var callbackId;

export default class MyAbility extends Ability {
    onCreate() {
        console.log("MyAbility onCreate")
        globalThis.applicationContext = this.context.getApplicationContext();
        let EnvironmentCallback = {
            onConfigurationUpdated(config){
                console.log("onConfigurationUpdated config:" + JSON.stringify(config));
            },
            onMemoryLevel(level){
                console.log("onMemoryLevel level:" + level);
            }
        }
        // 1.获取applicationContext
        let applicationContext = globalThis.applicationContext;
        // 2.通过applicationContext注册监听应用内生命周期
        callbackId = applicationContext.registerEnvironmentCallback(EnvironmentCallback);
        console.log("registerEnvironmentCallback number: " + JSON.stringify(callbackId));
    }
}
```

## ApplicationContext.unregisterEnvironmentCallback

unregisterEnvironmentCallback(callbackId: **number**,  callback: AsyncCallback<**void**>): **void**;

取消对系统环境变化的监听。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | 是   | 注册监听系统环境变化的ID。   |
| callback | AsyncCallback\<void> | 是   | 回调方法。                  |

**示例：**

```ts
import Ability from "@ohos.application.Ability";

var callbackId;

export default class MyAbility extends Ability {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.unregisterEnvironmentCallback(callbackId, (error, data) => {
            console.log("unregisterEnvironmentCallback success, err: " + JSON.stringify(error));
        });
    }
}
```