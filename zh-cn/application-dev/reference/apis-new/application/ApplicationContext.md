# ApplicationContext    
ApplicationContext模块提供开发者应用级别的的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import common from '@ohos.app.ability.common';  
    
```  
    
## ApplicationContext    
ApplicationContext模块提供开发者应用级别的的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### on('abilityLifecycle')    
注册监听应用内生命周期  
 **调用形式：**     
    
- on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback): number    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调方法，返回注册监听事件的ID。 |  
| number | 返回的此次注册监听生命周期的ID（每次注册该ID会自增+1，当超过监听上限数量2^63-1时，返回-1）。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例 （callback）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let lifecycleId: number;  
  
export default class EntryAbility extends UIAbility {  
    onCreate() {  
        console.log('MyAbility onCreate');  
        let AbilityLifecycleCallback: AbilityLifecycleCallback = {  
            onAbilityCreate(ability) {  
                console.log(`AbilityLifecycleCallback onAbilityCreate ability: ${ability}`);  
            },  
            onWindowStageCreate(ability, windowStage) {  
                console.log(`AbilityLifecycleCallback onWindowStageCreate ability: ${ability}`);  
                console.log(`AbilityLifecycleCallback onWindowStageCreate windowStage: ${windowStage}`);  
            },  
            onWindowStageActive(ability, windowStage) {  
                console.log(`AbilityLifecycleCallback onWindowStageActive ability: ${ability}`);  
                console.log(`AbilityLifecycleCallback onWindowStageActive windowStage: ${windowStage}`);  
            },  
            onWindowStageInactive(ability, windowStage) {  
                console.log(`AbilityLifecycleCallback onWindowStageInactive ability: ${ability}`);  
                console.log(`AbilityLifecycleCallback onWindowStageInactive windowStage: ${windowStage}`);  
            },  
            onWindowStageDestroy(ability, windowStage) {  
                console.log(`AbilityLifecycleCallback onWindowStageDestroy ability: ${ability}`);  
                console.log(`AbilityLifecycleCallback onWindowStageDestroy windowStage: ${windowStage}`);  
            },  
            onAbilityDestroy(ability) {  
                console.log(`AbilityLifecycleCallback onAbilityDestroy ability: ${ability}`);  
            },  
            onAbilityForeground(ability) {  
                console.log(`AbilityLifecycleCallback onAbilityForeground ability: ${ability}`);  
            },  
            onAbilityBackground(ability) {  
                console.log(`AbilityLifecycleCallback onAbilityBackground ability: ${ability}`);  
            },  
            onAbilityContinue(ability) {  
                console.log(`AbilityLifecycleCallback onAbilityContinue ability: ${ability}`);  
            }  
        }  
        // 1.通过context属性获取applicationContext  
        let applicationContext = this.context.getApplicationContext();  
        // 2.通过applicationContext注册监听应用内生命周期  
        lifecycleId = applicationContext.on('abilityLifecycle', AbilityLifecycleCallback);  
        console.log(`registerAbilityLifecycleCallback lifecycleId: ${lifecycleId}`);  
    }  
}  
    
```    
  
    
### off('abilityLifecycle')    
取消监听应用内生命周期  
 **调用形式：**     
    
- off(type: 'abilityLifecycle', callbackId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- off(type: 'abilityLifecycle', callbackId: number): Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
| callbackId | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例 （callback）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
let lifecycleId: number;  
  
export default class EntryAbility extends UIAbility {  
    onDestroy() {  
        let applicationContext = this.context.getApplicationContext();  
        console.log(`stage applicationContext: ${applicationContext}`);  
        applicationContext.off('abilityLifecycle', lifecycleId, (error, data) => {  
            if (error) {  
                console.error(`unregisterAbilityLifecycleCallback fail, err: ${JSON.stringify(error)}`);      
            } else {  
                console.log(`unregisterAbilityLifecycleCallback success, data: ${JSON.stringify(data)}`);  
            }  
        });  
    }  
}  
    
```    
  
    
### on('environment')    
注册对系统环境变化的监听。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'environment', callback: EnvironmentCallback): number    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调方法，返回注册监听事件的ID。 |  
| number | 返回的此次注册监听系统环境变化的ID（每次注册该ID会自增+1，当超过监听上限数量2^63-1时，返回-1）。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例 （callback）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import EnvironmentCallback from '@ohos.app.ability.EnvironmentCallback';  
  
let callbackId: number;  
  
export default class EntryAbility extends UIAbility {  
    onCreate() {  
        console.log('MyAbility onCreate')  
        let environmentCallback: EnvironmentCallback = {  
            onConfigurationUpdated(config){  
                console.log(`onConfigurationUpdated config: ${JSON.stringify(config)}`);  
            },  
            onMemoryLevel(level){  
                console.log('onMemoryLevel level: ${level}');  
            }  
        };  
        // 1.获取applicationContext  
        let applicationContext = this.context.getApplicationContext();  
        // 2.通过applicationContext注册监听系统环境变化  
        callbackId = applicationContext.on('environment', environmentCallback);  
        console.log(`registerEnvironmentCallback callbackId: ${callbackId}`);  
    }  
}  
    
```    
  
    
### off('environment')    
取消对系统环境变化的监听。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'environment', callbackId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- off(type: 'environment', callbackId: number): Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听事件的类型。 |  
| callbackId | number | true | 注册监听系统环境变化的ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调方法。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
let callbackId: number;  
  
export default class EntryAbility extends UIAbility {  
    onDestroy() {  
        let applicationContext = this.context.getApplicationContext();  
        applicationContext.off('environment', callbackId, (error, data) => {  
            if (error) {  
                console.error(`unregisterEnvironmentCallback fail, err: ${JSON.stringify(error)}`);  
            } else {  
                console.log(`unregisterEnvironmentCallback success, data: ${JSON.stringify(data)}`);  
            }  
        });  
    }  
}  
    
```    
  
    
### on('applicationStateChange')<sup>(10+)</sup>    
注册对当前应用前后台变化的监听。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'applicationStateChange', callback: ApplicationStateChangeCallback): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听事件的类型,必须为'applicationStateChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 对于该事件监听的回调方法，可以对应用从后台切换到前台，以及前台切换到后台分别定义回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';  
  
export default class MyAbility extends UIAbility {  
    onCreate() {  
        console.log('MyAbility onCreate');  
        let applicationStateChangeCallback: ApplicationStateChangeCallback = {  
            onApplicationForeground() {  
                console.info('applicationStateChangeCallback onApplicationForeground');  
            },  
            onApplicationBackground() {  
                console.info('applicationStateChangeCallback onApplicationBackground');  
            }  
        }  
  
        // 1.获取applicationContext  
        let applicationContext = this.context.getApplicationContext();  
        // 2.通过applicationContext注册应用前后台状态监听  
        applicationContext.on('applicationStateChange', applicationStateChangeCallback);  
        console.log('Resgiter applicationStateChangeCallback');  
    }  
}  
    
```    
  
    
### off('applicationStateChange')<sup>(10+)</sup>    
取消当前应用注册的前后台变化的全部监听。  
 **调用形式：**     
    
- off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听事件的类型,必须为'applicationStateChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 对于该事件监听的回调方法，可以对应用从后台切换到前台，以及前台切换到后台分别定义回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class MyAbility extends UIAbility {  
    onDestroy() {  
        let applicationContext = this.context.getApplicationContext();  
        applicationContext.off('applicationStateChange');  
    }  
}  
    
```    
  
    
### getRunningProcessInformation    
获取有关运行进程的信息。  
 **调用形式：**     
    
- getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>    
起始版本： 9    
- getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |  
| Promise<Array<ProcessInformation>> | 以Promise方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例 （promise）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
export default class MyAbility extends UIAbility {  
    onForeground() {  
        let applicationContext = this.context.getApplicationContext();  
        applicationContext.getRunningProcessInformation().then((data) => {  
            console.log(`The process running information is: ${JSON.stringify(data)}`);  
        }).catch((error: BusinessError) => {  
            console.error(`error: ${JSON.stringify(error)}`);  
        });  
    }  
}  
    
```    
  
    
 **示例代码2：**   
示例 （asynccallback）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class MyAbility extends UIAbility {  
    onForeground() {  
        let applicationContext = this.context.getApplicationContext();  
        applicationContext.getRunningProcessInformation((err, data) => {  
            if (err) {  
                console.error(`getRunningProcessInformation faile, err: ${JSON.stringify(err)}`);  
            } else {  
                console.log(`The process running information is: ${JSON.stringify(data)}`);  
            }  
        })  
    }  
}  
    
```    
  
    
### killAllProcesses    
杀死应用所在的进程。  
 **调用形式：**     
    
- killAllProcesses(): Promise\<void>    
起始版本： 9    
- killAllProcesses(callback: AsyncCallback\<void>)    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback方式返回杀死应用所在的进程结果。 |  
| Promise<void> | 以Promise方式返回杀死应用所在的进程结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000011 | The context does not exist. |  
    
 **示例代码1：**   
示例 （promise）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class MyAbility extends UIAbility {  
    onBackground() {  
        let applicationContext = this.context.getApplicationContext();  
        applicationContext.killAllProcesses();  
    }  
}  
    
```    
  
    
 **示例代码2：**   
示例 （asynccallback）：  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class MyAbility extends UIAbility {  
    onBackground() {  
        let applicationContext = this.context.getApplicationContext();  
        applicationContext.killAllProcesses(error => {  
            if (error) {  
                console.error(`killAllProcesses fail, error: ${JSON.stringify(error)}`);  
            }  
        });  
    }  
}  
    
```    
  
    
### setColorMode<sup>(11+)</sup>    
设置应用的颜色模式。  
 **调用形式：**     
- setColorMode(colorMode: ConfigurationConstant.ColorMode): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| colorMode | ConfigurationConstant.ColorMode | true | 设置颜色模式，包括：深色模式、浅色模式、不设置（跟随系统） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000011 | The context does not exist. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import ConfigurationConstant from '@ohos.app.ability.ConfigurationConstant';  
  
export default class MyAbility extends UIAbility {  
  onCreate() {  
    let applicationContext = this.context.getApplicationContext();  
    applicationContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);  
  }  
}  
    
```    
  
    
### setLanguage<sup>(11+)</sup>    
设置应用的语言。  
 **调用形式：**     
- setLanguage(language: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| language | string | true | 设置语言，当前支持的语言列表可以通过tic getSystemLanguage(): Array<string>;获取 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000011 | The context does not exist. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class MyAbility extends UIAbility {  
  onCreate() {  
    let applicationContext = this.context.getApplicationContext();  
    applicationContext.setLanguage('zh-cn');  
  }  
}  
    
```    
  
