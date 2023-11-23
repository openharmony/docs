# @ohos.application.WindowExtensionAbility    
WindowExtensionAbility基于ExtensionAbility。WindowExtensionAbility中展示的内容可作为一个控件(AbilityComponent)内容展示在其他应用窗口中。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## WindowExtensionAbility    
WindowExtensionAbility基于ExtensionAbility。WindowExtensionAbility中展示的内容可作为一个控件(AbilityComponent)内容展示在其他应用窗口中。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | WindowExtensionContext | false | true | 上下文。  |  
    
### onConnect    
当窗口扩展组件第一次连接ability时回调。  
 **调用形式：**     
- onConnect(want: Want): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前ability的Want类型信息，包括ability名称、bundle名称等。 |  
    
 **示例代码：**   
```ts    
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
  
export default class MyWindowExtensionAbility extends WindowExtensionAbility {  
  onConnect(want: Want) {  
    console.info('WindowExtAbility onConnect, abilityName: ${want.abilityName}');  
  }  
}  
    
```    
  
    
### onDisconnect    
当所有连接到窗口扩展组件的ability断开连接时回调。  
 **调用形式：**     
- onDisconnect(want: Want): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Ability的Want类型信息，包括ability名称、bundle名称等。 |  
    
 **示例代码：**   
```ts    
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
  
export default class MyWindowExtensionAbility extends WindowExtensionAbility {  
  onDisconnect(want: Want) {  
    console.info('WindowExtAbility onDisconnect, abilityName: ${want.abilityName}');  
  }  
}  
    
```    
  
    
### onWindowReady    
当窗口被创建时回调。  
 **调用形式：**     
- onWindowReady(window: window.Window): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| window | window.Window | true | 当前窗口实例 |  
    
 **示例代码：**   
```ts    
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';  
import window from '@ohos.window';  
  
export default class MyWindowExtensionAbility extends WindowExtensionAbility {  
  onWindowReady(window: window.Window) {  
    window.loadContent('WindowExtAbility/pages/index1').then(() => {  
      window.getProperties().then((pro: window.WindowProperties) => {  
        console.log('WindowExtension pro: ${JSON.stringify(pro)}');  
      });  
      window.show();  
    });  
  }  
}  
    
```    
  
