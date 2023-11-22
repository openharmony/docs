# @ohos.application.StaticSubscriberExtensionContext    
StaticSubscriberExtensionContext模块是StaticSubscriberExtensionAbility的上下文环境，继承自ExtensionContext。  
  
StaticSubscriberExtensionContext模块提供StaticSubscriberExtensionAbility具有的接口和能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import StaticSubscriberExtensionContext from '@ohos.application.StaticSubscriberExtensionContext';  
    
```  
    
## StaticSubscriberExtensionContext  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### startAbility    
拉起一个静态订阅所属的同应用的Ability。使用callback异步回调。  使用规则：  - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限  - 跨应用场景下，目标Ability的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限  
 **调用形式：**     
    
- startAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbility(want: Want): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.START_ABILITIES_FROM_BACKGROUND    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回启动结果。 |  
| Promise<void> | Promise形式返回启动结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000009 | An ability cannot be started or stopped in Wukong mode. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
| 16200001 | The caller has been released. |  
| 16300003 | The target application is not self application. |  
    
 **示例代码1：**   
示例 （callback）：  
```ts    
import CommonEventManager from '@ohos.commonEventManager';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
let want: Want = {  
  bundleName: "com.example.myapp",  
  abilityName: "MyAbility"  
};  
  
class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {  
  onReceiveEvent(event: CommonEventManager.CommonEventData) {  
    console.log(`onReceiveEvent, event: ${JSON.stringify(event)}`);  
  
    try {  
      this.context.startAbility(want, (error: BusinessError) => {  
        if (error) {  
          // 处理业务逻辑错误  
          console.log('startAbility failed, error.code: ' + JSON.stringify(error.code) +  
            ' error.message: ' + JSON.stringify(error.message));  
          return;  
        }  
        // 执行正常业务  
        console.log('startAbility succeed');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      let code = (paramError as BusinessError).code;  
      let message = (paramError as BusinessError).message;  
      console.log('startAbility failed, error.code: ' + JSON.stringify(code) +  
        ' error.message: ' + JSON.stringify(message));  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例 （callback）：  
```ts    
import CommonEventManager from '@ohos.commonEventManager';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
let want: Want = {  
  bundleName: "com.example.myapp",  
  abilityName: "MyAbility"  
};  
  
class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {  
  onReceiveEvent(event: CommonEventManager.CommonEventData) {  
    console.log(`onReceiveEvent, event: ${JSON.stringify(event)}`);  
    try {  
      this.context.startAbility(want)  
        .then(() => {  
          // 执行正常业务  
          console.log('startAbility succeed');  
        })  
        .catch((error: BusinessError) => {  
          // 处理业务逻辑错误  
          console.log('startAbility failed, error.code: ' + JSON.stringify(error.code) +  
            ' error.message: ' + JSON.stringify(error.message));  
        });  
    } catch (paramError) {  
      // 处理入参错误异常  
      let code = (paramError as BusinessError).code;  
      let message = (paramError as BusinessError).message;  
      console.log('startAbility failed, error.code: ' + JSON.stringify(code) +  
        ' error.message: ' + JSON.stringify(message));  
    }  
  }  
}  
    
```    
  
