# connectOptions    
在连接指定的后台服务时作为入参，用于接收连接过程中的状态变化，如作为[connectServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability)的入参，连接指定的ServiceExtensionAbility。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ConnectOptions  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### onConnect    
建立连接时的回调函数。  
 **调用形式：**     
- onConnect(elementName: ElementName, remote: rpc.IRemoteObject): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementName | ElementName | true |  |  
| remote | rpc.IRemoteObject | true |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import bundleManager from '@ohos.bundle.bundleManager';  
import rpc from '@ohos.rpc';  
  
let connectWant: Want = {  
  bundleName: 'com.example.myapp',  
  abilityName: 'MyAbility'  
};  
  
let connectOptions: common.ConnectOptions = {  
  onConnect(elementName: bundleManager.ElementName, remote: rpc.IRemoteObject) {  
    console.log(`onConnect elementName: ${elementName}`);  
  },  
  onDisconnect(elementName: bundleManager.ElementName) {  
    console.log(`onDisconnect elementName: ${elementName}`);  
  },  
  onFailed(code: number) {  
    console.error(`onFailed code: ${code}`);  
  }  
};  
  
  
class EntryAbility extends UIAbility {  
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
    let connection: number = this.context.connectServiceExtensionAbility(connectWant, connectOptions);  
  }  
}  
    
```    
  
    
### onDisconnect    
断开连接时的回调函数。  
 **调用形式：**     
- onDisconnect(elementName: ElementName): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementName | ElementName | true |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import bundleManager from '@ohos.bundle.bundleManager';  
import rpc from '@ohos.rpc';  
  
let connectWant: Want = {  
  bundleName: 'com.example.myapp',  
  abilityName: 'MyAbility'  
};  
  
let connectOptions: common.ConnectOptions = {  
  onConnect(elementName: bundleManager.ElementName, remote: rpc.IRemoteObject) {  
    console.log(`onConnect elementName: ${elementName}`);  
  },  
  onDisconnect(elementName: bundleManager.ElementName) {  
    console.log(`onDisconnect elementName: ${elementName}`);  
  },  
  onFailed(code: number) {  
    console.error(`onFailed code: ${code}`);  
  }  
};  
  
  
class EntryAbility extends UIAbility {  
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
    let connection: number = this.context.connectServiceExtensionAbility(connectWant, connectOptions);  
  }  
}  
    
```    
  
    
### onFailed    
连接失败时的回调函数。  
 **调用形式：**     
- onFailed(code: number): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code | number | true |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import bundleManager from '@ohos.bundle.bundleManager';  
import rpc from '@ohos.rpc';  
  
let connectWant: Want = {  
  bundleName: 'com.example.myapp',  
  abilityName: 'MyAbility'  
};  
  
let connectOptions: common.ConnectOptions = {  
  onConnect(elementName: bundleManager.ElementName, remote: rpc.IRemoteObject) {  
    console.log(`onConnect elementName: ${elementName}`);  
  },  
  onDisconnect(elementName: bundleManager.ElementName) {  
    console.log(`onDisconnect elementName: ${elementName}`);  
  },  
  onFailed(code: number) {  
    console.error(`onFailed code: ${code}`);  
  }  
};  
  
  
class EntryAbility extends UIAbility {  
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
    let connection: number = this.context.connectServiceExtensionAbility(connectWant, connectOptions);  
  }  
}  
    
```    
  
