# EventHub    
EventHub模块提供了事件中心，提供订阅、取消订阅、触发事件的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## EventHub  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### on  
 **调用形式：**     
    
- on(event: string, callback: Function): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 事件名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 事件回调，事件触发后调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class EntryAbility extends UIAbility {  
    onForeground() {  
        this.context.eventHub.on('myEvent', this.eventFunc);  
        // 支持使用匿名函数订阅事件  
        this.context.eventHub.on('myEvent', () => {  
            console.log('call anonymous eventFunc');  
        });  
        // 结果：  
        // eventFunc is called  
        // call anonymous eventFunc  
        this.context.eventHub.emit('myEvent');   
    }  
  
    eventFunc() {  
        console.log('eventFunc is called');  
    }  
}  
    
```    
  
    
### off    
取消订阅指定事件。  - 传入callback：取消指定的callback对指定事件的订阅，当该事件触发后，将不会回调该callback。  - 不传callback：取消所有callback对指定事件的订阅。  
 **调用形式：**     
    
- off(event: string, callback?: Function): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 事件名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 事件回调。如果不传callback，则取消订阅该事件下所有callback。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class EntryAbility extends UIAbility {  
    onForeground() {  
        this.context.eventHub.on('myEvent', this.eventFunc1);  
        this.context.eventHub.off('myEvent', this.eventFunc1); // 取消eventFunc1对myEvent事件的订阅  
        this.context.eventHub.on('myEvent', this.eventFunc1);  
        this.context.eventHub.on('myEvent', this.eventFunc2);  
        this.context.eventHub.off('myEvent');  // 取消eventFunc1和eventFunc2对myEvent事件的订阅  
    }  
  
    eventFunc1() {  
        console.log('eventFunc1 is called');  
    }  
  
    eventFunc2() {  
        console.log('eventFunc2 is called');  
    }  
}  
    
```    
  
    
### emit    
触发指定事件。  
 **调用形式：**     
- emit(event: string, ...args: Object[]): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | string | true | 事件名称。 |  
| args | Object[] | true | 可变参数，事件触发时，传递给回调函数的参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class EntryAbility extends UIAbility {  
    onForeground() {  
        this.context.eventHub.on('myEvent', this.eventFunc);  
        // 结果：  
        // eventFunc is called,undefined,undefined  
        this.context.eventHub.emit('myEvent');  
        // 结果：  
        // eventFunc is called,1,undefined  
        this.context.eventHub.emit('myEvent', 1);  
        // 结果：  
        // eventFunc is called,1,2  
        this.context.eventHub.emit('myEvent', 1, 2);  
    }  
  
    eventFunc(argOne: number, argTwo: number) {  
        console.log(`eventFunc is called, ${argOne}, ${argTwo}`);  
    }  
}  
    
```    
  
