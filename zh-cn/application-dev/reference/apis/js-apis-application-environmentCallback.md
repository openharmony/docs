# @ohos.application.EnvironmentCallback (EnvironmentCallback)

EnvironmentCallback模块提供应用上下文ApplicationContext对系统环境变化监听回调的能力，包括onConfigurationUpdated、onMemoryLevel方法。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持，从API version 9后续版本废弃，替换模块为[@ohos.app.ability.EnvironmentCallback](js-apis-app-ability-environmentCallback.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。


## 导入模块

```ts
import EnvironmentCallback from "@ohos.application.EnvironmentCallback";
```


## EnvironmentCallback.onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

注册系统环境变化的监听后，在系统环境变化时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | config | [Configuration](js-apis-application-configuration.md) | 是 | 变化后的Configuration对象。 |

## EnvironmentCallback.onMemoryLevel

onMemoryLevel(level: number): void;

注册系统内存基线水平变化监听后，在系统内存基线水平变化时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | level  | [MemoryLevel](js-apis-application-abilityConstant.md#abilityconstantmemorylevel) | 是 | 表示当前内存的基线水平。 |

**示例：**

  ```ts
import Ability from "@ohos.application.Ability";

var callbackId;

export default class MyAbility extends Ability {
    onCreate() {
        console.log("MyAbility onCreate")
        globalThis.applicationContext = this.context.getApplicationContext();
        let EnvironmentCallback  =  {
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
    onDestroy() {
        let applicationContext = globalThis.applicationContext;
        applicationContext.unregisterEnvironmentCallback(callbackId, (error, data) => {
            console.log("unregisterEnvironmentCallback success, err: " + JSON.stringify(error));
        });
    }
}
  ```