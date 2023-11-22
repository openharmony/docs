# AbilityDelegator    
AbilityDelegator提供添加用于监视指定ability的生命周期状态更改的AbilityMonitor对象的能力，包括对AbilityMonitor实例的添加、删除、等待ability到达OnCreate生命周期、设置等待时间等、获取指定ability的生命周期状态、获取当前应用顶部ability、启动指定ability等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import AbilityDelegator from 'AbilityDelegator'    
```  
    
## AbilityDelegator    
AbilityDelegator提供添加用于监视指定ability的生命周期状态更改的AbilityMonitor对象的能力，包括对AbilityMonitor实例的添加、删除、等待ability到达OnCreate生命周期、设置等待时间等、获取指定ability的生命周期状态、获取当前应用顶部ability、启动指定ability等。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### addAbilityMonitor    
添加AbilityMonitor实例  
 **调用形式：**     
    
- addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void    
起始版本： 9    
- addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityMonitor | true | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor)实例 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<void> | 以Promise形式返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | AddAbilityMonitor failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
  
function onAbilityCreateCallback(data: UIAbility) {  
    console.info(`onAbilityCreateCallback, data: ${JSON.stringify(data)}`);  
}  
  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  
    abilityName: 'abilityname',  
    onAbilityCreate: onAbilityCreateCallback  
};  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.addAbilityMonitor(monitor, (error: BusinessError) => {  
    console.error(`addAbilityMonitor fail, error: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import UIAbility from '@ohos.app.ability.UIAbility';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
function onAbilityCreateCallback(data: UIAbility) {  console.info('onAbilityCreateCallback');}  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  abilityName: 'abilityname',  onAbilityCreate: onAbilityCreateCallback};abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.addAbilityMonitor(monitor).then(() => {  console.info('addAbilityMonitor promise');});    
```    
  
    
### addAbilityMonitorSync<sup>(10+)</sup>    
同步添加AbilityMonitor实例。  
 **调用形式：**     
- addAbilityMonitorSync(monitor: AbilityMonitor): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityMonitor | true | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor)实例 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16000100 | AddAbilityMonitorSync failed. |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import UIAbility from '@ohos.app.ability.UIAbility';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
function onAbilityCreateCallback(data: UIAbility) {  console.info('onAbilityCreateCallback');}  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  abilityName: 'abilityname',  onAbilityCreate: onAbilityCreateCallback};abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.addAbilityMonitorSync(monitor);    
```    
  
    
### addAbilityStageMonitor    
添加一个AbilityStageMonitor对象，用于监视指定abilityStage的生命周期状态更改。（callback形式）  
 **调用形式：**     
    
- addAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void    
起始版本： 9    
- addAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityStageMonitor | true | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) 实例 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<void> | 以Promise形式返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | AddAbilityStageMonitor failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.addAbilityStageMonitor({  
    moduleName: 'moduleName',  
    srcEntrance: 'srcEntrance',  
}, (err : BusinessError) => {  
    console.info('addAbilityStageMonitor callback');  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.addAbilityStageMonitor({  moduleName: 'moduleName',  srcEntrance: 'srcEntrance',}).then(() => {  console.info('addAbilityStageMonitor promise');});    
```    
  
    
### addAbilityStageMonitorSync<sup>(10+)</sup>    
添加一个AbilityStageMonitor对象，用于监视指定abilityStage的生命周期状态更改。  
 **调用形式：**     
- addAbilityStageMonitorSync(monitor: AbilityStageMonitor): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityStageMonitor | true | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) 实例 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | AddAbilityStageMonitor failed. |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.addAbilityStageMonitor({  
    moduleName: 'moduleName',  
    srcEntrance: 'srcEntrance',  
}, (err : BusinessError) => {  
    console.info('addAbilityStageMonitor callback');  
});  
    
```    
  
    
### removeAbilityMonitor    
删除已经添加的AbilityMonitor实例  
 **调用形式：**     
    
- removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void    
起始版本： 9    
- removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityMonitor | true | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor)实例 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<void> | 以Promise形式返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16000100 | RemoveAbilityMonitor failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
  
function onAbilityCreateCallback(data: UIAbility) {  
    console.info('onAbilityCreateCallback');  
}  
  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  
    abilityName: 'abilityname',  
    onAbilityCreate: onAbilityCreateCallback  
};  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.removeAbilityMonitor(monitor, (error: BusinessError) => {  
    console.error(`removeAbilityMonitor fail, error: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import UIAbility from '@ohos.app.ability.UIAbility';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
function onAbilityCreateCallback(data: UIAbility) {  console.info('onAbilityCreateCallback');}  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  abilityName: 'abilityname',  onAbilityCreate: onAbilityCreateCallback};  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.removeAbilityMonitor(monitor).then(() => {  console.info('removeAbilityMonitor promise');});    
```    
  
    
### removeAbilityMonitorSync<sup>(10+)</sup>    
同步删除已经添加的AbilityMonitor实例。  
 **调用形式：**     
- removeAbilityMonitorSync(monitor: AbilityMonitor): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityMonitor | true | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor)实例 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16000100 | RemoveAbilityMonitorSync failed. |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import UIAbility from '@ohos.app.ability.UIAbility';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
function onAbilityCreateCallback(data: UIAbility) {  console.info('onAbilityCreateCallback');}  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  abilityName: 'abilityname',  onAbilityCreate: onAbilityCreateCallback};  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.removeAbilityMonitorSync(monitor);    
```    
  
    
### removeAbilityStageMonitor    
从应用程序内存中删除指定的AbilityStageMonitor对象。  
 **调用形式：**     
    
- removeAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void    
起始版本： 9    
- removeAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityStageMonitor | true | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) 实例 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<void> | 以Promise形式返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16000100 | RemoveAbilityStageMonitor failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.removeAbilityStageMonitor({  
    moduleName: 'moduleName',  
    srcEntrance: 'srcEntrance',  
}, (err : BusinessError) => {  
    console.info('removeAbilityStageMonitor callback');  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.removeAbilityStageMonitor({  moduleName: 'moduleName',  srcEntrance: 'srcEntrance',}).then(() => {  console.info('removeAbilityStageMonitor promise');});    
```    
  
    
### removeAbilityStageMonitorSync<sup>(10+)</sup>    
同步从应用程序内存中删除指定的AbilityStageMonitor对象。  
 **调用形式：**     
- removeAbilityStageMonitorSync(monitor: AbilityStageMonitor): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityStageMonitor | true | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) 实例 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16000100 | removeAbilityStageMonitorSync failed. |  
    
 **示例代码：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.removeAbilityStageMonitorSync({  moduleName: 'moduleName',  srcEntrance: 'srcEntrance',});    
```    
  
    
### waitAbilityMonitor    
等待与AbilityMonitor实例匹配的ability到达OnCreate生命周期，并返回ability实例  
 **调用形式：**     
    
- waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<UIAbility>): void    
起始版本： 9    
- waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<UIAbility>): void    
起始版本： 9    
- waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<UIAbility>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityMonitor | true | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor)实例 |  
| timeout | number | true | 最大等待时间，单位毫秒（ms） |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<UIAbility> | 以Promise形式返回Ability。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | WaitAbilityMonitor failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
  
function onAbilityCreateCallback(data: UIAbility) {  
    console.info('onAbilityCreateCallback');  
}  
  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  
    abilityName: 'abilityname',  
    onAbilityCreate: onAbilityCreateCallback  
};  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.waitAbilityMonitor(monitor, (error : BusinessError, data : UIAbility) => {  
    if (error) {  
        console.error(`waitAbilityMonitor fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`waitAbilityMonitor success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import UIAbility from '@ohos.app.ability.UIAbility';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
function onAbilityCreateCallback(data: UIAbility) {  console.info('onAbilityCreateCallback');}  
let monitor: AbilityDelegatorRegistry.AbilityMonitor = {  abilityName: 'abilityname',  onAbilityCreate: onAbilityCreateCallback};  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.waitAbilityMonitor(monitor).then((data : UIAbility) => {  console.info('waitAbilityMonitor promise');});    
```    
  
    
### waitAbilityStageMonitor    
等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象。  
 **调用形式：**     
    
- waitAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<AbilityStage>): void    
起始版本： 9    
- waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout: number, callback: AsyncCallback\<AbilityStage>): void    
起始版本： 9    
- waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout?: number): Promise\<AbilityStage>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| monitor | AbilityStageMonitor | true | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) 实例 |  
| timeout | number | true | 超时最大等待时间，以毫秒为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 成功返回AbilityStage对象，失败返回空。 |  
| Promise<AbilityStage> | 成功返回AbilityStage对象，失败返回空。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | WaitAbilityStageMonitor failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import AbilityStage from '@ohos.app.ability.AbilityStage';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.waitAbilityStageMonitor({  moduleName: 'moduleName',  srcEntrance: 'srcEntrance',}, (err : BusinessError, data : AbilityStage) => {  console.info('waitAbilityStageMonitor callback');});    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import AbilityStage from '@ohos.app.ability.AbilityStage';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.waitAbilityStageMonitor({  moduleName: 'moduleName',  srcEntrance: 'srcEntrance',}).then((data : AbilityStage) => {  console.info('waitAbilityStageMonitor promise');});    
```    
  
    
### getAppContext    
获取应用Context。  
 **调用形式：**     
- getAppContext(): Context  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Context | 应用[Context](js-apis-inner-application-context.md)。 |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
let context = abilityDelegator.getAppContext();    
```    
  
    
### getAbilityState    
获取指定ability的生命周期状态。  
 **调用形式：**     
- getAbilityState(ability: UIAbility): number  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 指定Ability对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 指定ability的生命周期状态。状态枚举值使用[AbilityLifecycleState](js-apis-application-abilityDelegatorRegistry.md#AbilityLifecycleState)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let ability: UIAbility;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.getCurrentTopAbility((err : BusinessError, data : UIAbility) => {  
    console.info('getCurrentTopAbility callback');  
    ability = data;  
    let state = abilityDelegator.getAbilityState(ability);  
    console.info('getAbilityState ${state}');  
});  
    
```    
  
    
### getCurrentTopAbility    
获取当前应用顶部ability  
 **调用形式：**     
    
- getCurrentTopAbility(callback: AsyncCallback\<UIAbility>): void    
起始版本： 9    
- getCurrentTopAbility(): Promise\<UIAbility>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<UIAbility> | 以Promise形式返回当前应用顶部ability。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | GetCurrentTopAbility failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let ability: UIAbility;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.getCurrentTopAbility((err : BusinessError, data : UIAbility) => {  
    console.info('getCurrentTopAbility callback');  
    ability = data;  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import UIAbility from '@ohos.app.ability.UIAbility';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;let ability: UIAbility;  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.getCurrentTopAbility().then((data : UIAbility) => {  console.info('getCurrentTopAbility promise');  ability = data;});    
```    
  
    
### startAbility    
启动指定ability  
 **调用形式：**     
    
- startAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbility(want: Want): Promise\<void>    
起始版本： 9    
- startAbility(want: Want): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability参数 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<void> | 以Promise形式返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000009 | An ability cannot be started or stopped in Wukong mode. |  
| 16000010 | The call with the continuation flag is forbidden. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
| 16200001 | The caller has been released. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let want: Want = {  
    bundleName: 'bundleName',  
    abilityName: 'abilityName'  
};  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.startAbility(want, (err : BusinessError, data : void) => {  
    console.info('startAbility callback');  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';import UIAbility from '@ohos.app.ability.UIAbility';import Want from '@ohos.app.ability.Want';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;let want: Want = {  bundleName: 'bundleName',  abilityName: 'abilityName'};  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.startAbility(want).then((data: void) => {  console.info('startAbility promise');});    
```    
  
    
### doAbilityForeground    
调度指定ability生命周期状态到Foreground状态  
 **调用形式：**     
    
- doAbilityForeground(ability: UIAbility, callback: AsyncCallback\<void>): void    
起始版本： 9    
- doAbilityForeground(ability: UIAbility): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 指定Ability对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法<br/>\- true：成功<br/>\- false：失败 |  
| Promise<void> | 以Promise形式返回执行结果。<br/>\- true：成功<br/>\- false：失败 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | DoAbilityForeground failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let ability: UIAbility;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.getCurrentTopAbility((err : BusinessError, data : UIAbility) => {  
    console.info('getCurrentTopAbility callback');  
    ability = data;  
    abilityDelegator.doAbilityForeground(ability, (err : BusinessError) => {  
        console.info("doAbilityForeground callback");  
    });  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let ability: UIAbility;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.getCurrentTopAbility((err : BusinessError, data : UIAbility) => {  
    console.info('getCurrentTopAbility callback');  
    ability = data;  
    abilityDelegator.doAbilityForeground(ability).then(() => {  
        console.info("doAbilityForeground promise");  
    });  
});  
    
```    
  
    
### doAbilityBackground    
调度指定ability生命周期状态到Background状态  
 **调用形式：**     
    
- doAbilityBackground(ability: UIAbility, callback: AsyncCallback\<void>): void    
起始版本： 9    
- doAbilityBackground(ability: UIAbility): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 指定Ability对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法<br/>\- true：成功<br/>\- false：失败 |  
| Promise<void> | 以Promise形式返回执行结果。<br/>\- true：成功<br/>\- false：失败 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | DoAbilityBackground failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let ability: UIAbility;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.getCurrentTopAbility((err : BusinessError, data : UIAbility) => {  
    console.info('getCurrentTopAbility callback');  
    ability = data;  
    abilityDelegator.doAbilityBackground(ability, (err : BusinessError) => {  
        console.info("doAbilityBackground callback");  
    });  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let ability: UIAbility;  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.getCurrentTopAbility((err : BusinessError, data : UIAbility) => {  
    console.info('getCurrentTopAbility callback');  
    ability = data;  
    abilityDelegator.doAbilityBackground(ability).then(() => {  
        console.info("doAbilityBackground promise");  
    });  
});  
    
```    
  
    
### print<sup>(10+)</sup>    
打印日志信息到单元测试终端控制台  
 **调用形式：**     
    
- print(msg: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- print(msg: string): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| msg | string | true | 日志字符串 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<void> | 以Promise形式返回。 |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
<span style="font-size: 14px; letter-spacing: 0px;">import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';</span>  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let msg = 'msg';  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.print(msg, (err : BusinessError) => {  
    console.info('print callback');  
});    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;let msg = 'msg';  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.print(msg).then(() => {  console.info('print promise');});    
```    
  
    
### printSync    
打印日志信息到单元测试终端控制台。  
 **调用形式：**     
- printSync(msg: string): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| msg | string | true | 日志字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;let msg = 'msg';  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.printSync(msg);    
```    
  
    
### finishTest    
结束测试并打印日志信息到单元测试终端控制台  
 **调用形式：**     
    
- finishTest(msg: string, code: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- finishTest(msg: string, code: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| msg | string | true | 日志字符串 |  
| code | number | true | 日志码 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法 |  
| Promise<void> | 以Promise形式返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000100 | FinishTest failed. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
import { BusinessError } from '@ohos.base';  
  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;  
let msg = 'msg';  
  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();  
abilityDelegator.finishTest(msg, 0, (err : BusinessError) => {  
    console.info('finishTest callback');  
});  
    
```    
  
    
 **示例代码2：**   
示例 （promise）：  
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;let msg = 'msg';  
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.finishTest(msg, 0).then(() => {  console.info('finishTest promise');});    
```    
  
    
### setMockList<sup>(11+)</sup>    
设置模块的mock替换关系。  
 **调用形式：**     
- setMockList(mockList: { [key: string]: string }): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mockList | { [key: string]: string } | true | 模块mock替换关系的键值对象，其中key为待替换的目标路径，value为用于替换的mock实现文件的路径。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';  
let mockList: Record<string, string> = {  '@ohos.router': 'src/main/mock/ohos/router.mock',  'common.time': 'src/main/mock/common/time.mock',};let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();abilityDelegator.setMockList(mockList);    
```    
  
