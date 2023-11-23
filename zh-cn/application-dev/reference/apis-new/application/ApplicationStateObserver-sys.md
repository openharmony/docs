# ApplicationStateObserver    
定义应用状态监听，可以作为[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)的入参监听当前应用的生命周期变化。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import appManager from '@ohos.app.ability.appManager';  
    
```  
    
## ApplicationStateObserver    
定义应用状态监听，可以作为[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)的入参监听当前应用的生命周期变化。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### onForegroundApplicationChanged    
应用前后台状态发生变化时执行的回调函数。传入参数类型是[AppStateData](js-apis-inner-application-appStateData.md)。  
 **调用形式：**     
- onForegroundApplicationChanged(appStateData: AppStateData): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appStateData | AppStateData | true |  |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.app.ability.appManager';  
let applicationStateObserver: appManager.ApplicationStateObserver = {  onForegroundApplicationChanged(appStateData) {    console.log(`onForegroundApplicationChanged appStateData: ${JSON.stringify(appStateData)}`);  },  onAbilityStateChanged(abilityStateData) {    console.log(`onAbilityStateChanged onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);  },  onProcessCreated(processData) {    console.log(`onProcessCreated onProcessCreated: ${JSON.stringify(processData)}`);  },  onProcessDied(processData) {    console.log(`onProcessDied onProcessDied: ${JSON.stringify(processData)}`);  },  onProcessStateChanged(processData) {    console.log(`onProcessStateChanged onProcessStateChanged: ${JSON.stringify(processData)}`);  }};let observerCode = appManager.on('applicationState', applicationStateObserver);    
```    
  
    
### onAbilityStateChanged    
ability状态发生变化时执行的回调函数。传入参数类型是[AppStateData](js-apis-inner-application-appStateData.md)。  
 **调用形式：**     
- onAbilityStateChanged(abilityStateData: AbilityStateData): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| abilityStateData | AbilityStateData | true |  |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.app.ability.appManager';  
let applicationStateObserver: appManager.ApplicationStateObserver = {  onForegroundApplicationChanged(appStateData) {    console.log(`onForegroundApplicationChanged appStateData: ${JSON.stringify(appStateData)}`);  },  onAbilityStateChanged(abilityStateData) {    console.log(`onAbilityStateChanged onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);  },  onProcessCreated(processData) {    console.log(`onProcessCreated onProcessCreated: ${JSON.stringify(processData)}`);  },  onProcessDied(processData) {    console.log(`onProcessDied onProcessDied: ${JSON.stringify(processData)}`);  },  onProcessStateChanged(processData) {    console.log(`onProcessStateChanged onProcessStateChanged: ${JSON.stringify(processData)}`);  }};let observerCode = appManager.on('applicationState', applicationStateObserver);    
```    
  
    
### onProcessCreated    
进程创建时执行的回调函数。传入参数类型是[ProcessData](js-apis-inner-application-processData.md)。。<span style="letter-spacing: 0px;">import appManager from '@ohos.app.ability.appManager';</span>  
let applicationStateObserver: appManager.ApplicationStateObserver = {  onForegroundApplicationChanged(appStateData) {    console.log(`onForegroundApplicationChanged appStateData: ${JSON.stringify(appStateData)}`);  },  onAbilityStateChanged(abilityStateData) {    console.log(`onAbilityStateChanged onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);  },  onProcessCreated(processData) {    console.log(`onProcessCreated onProcessCreated: ${JSON.stringify(processData)}`);  },  onProcessDied(processData) {    console.log(`onProcessDied onProcessDied: ${JSON.stringify(processData)}`);  },  onProcessStateChanged(processData) {    console.log(`onProcessStateChanged onProcessStateChanged: ${JSON.stringify(processData)}`);  }};let observerCode = appManager.on('applicationState', applicationStateObserver);  
 **调用形式：**     
- onProcessCreated(processData: ProcessData): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| processData | ProcessData | true |  |  
    
### onProcessDied    
进程销毁时执行的回调函数。传入参数类型是[ProcessData](js-apis-inner-application-processData.md)。  
 **调用形式：**     
- onProcessDied(processData: ProcessData): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| processData | ProcessData | true |  |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.app.ability.appManager';  
let applicationStateObserver: appManager.ApplicationStateObserver = {  onForegroundApplicationChanged(appStateData) {    console.log(`onForegroundApplicationChanged appStateData: ${JSON.stringify(appStateData)}`);  },  onAbilityStateChanged(abilityStateData) {    console.log(`onAbilityStateChanged onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);  },  onProcessCreated(processData) {    console.log(`onProcessCreated onProcessCreated: ${JSON.stringify(processData)}`);  },  onProcessDied(processData) {    console.log(`onProcessDied onProcessDied: ${JSON.stringify(processData)}`);  },  onProcessStateChanged(processData) {    console.log(`onProcessStateChanged onProcessStateChanged: ${JSON.stringify(processData)}`);  }};let observerCode = appManager.on('applicationState', applicationStateObserver);    
```    
  
    
### onProcessStateChanged<sup>(9+)</sup>    
进程状态更新时执行的回调函数。传入参数类型是[ProcessData](js-apis-inner-application-processData.md)。  
 **调用形式：**     
- onProcessStateChanged(processData: ProcessData): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| processData | ProcessData | true |  |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.app.ability.appManager';  
let applicationStateObserver: appManager.ApplicationStateObserver = {  onForegroundApplicationChanged(appStateData) {    console.log(`onForegroundApplicationChanged appStateData: ${JSON.stringify(appStateData)}`);  },  onAbilityStateChanged(abilityStateData) {    console.log(`onAbilityStateChanged onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);  },  onProcessCreated(processData) {    console.log(`onProcessCreated onProcessCreated: ${JSON.stringify(processData)}`);  },  onProcessDied(processData) {    console.log(`onProcessDied onProcessDied: ${JSON.stringify(processData)}`);  },  onProcessStateChanged(processData) {    console.log(`onProcessStateChanged onProcessStateChanged: ${JSON.stringify(processData)}`);  }};let observerCode = appManager.on('applicationState', applicationStateObserver);    
```    
  
