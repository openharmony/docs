# @ohos.app.ability.DriverExtensionAbility    
DriverExtensionAbility模块提供驱动相关扩展能力，提供驱动创建、销毁、连接、断开等生命周期回调。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## DriverExtensionAbility  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
### 属性    
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | DriverExtensionContext | false | true | DriverExtension的上下文环境，继承自ExtensionContext。 |  
    
### onInit    
Extension生命周期回调，在创建时回调，执行初始化业务逻辑操作。  
 **调用形式：**     
- onInit(want: Want): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |  
    
 **示例代码：**   
```ts    
import DriverExtension from '@ohos.app.ability.DriverExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
class DriverExt extends DriverExtension {  
  onInit(want : Want) {  
    console.log('onInit, want: ${want.abilityName}');  
  }  
}  
    
```    
  
    
### onRelease    
Extension生命周期回调，在销毁时回调，执行资源清理等操作。  
 **调用形式：**     
- onRelease(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
 **示例代码：**   
```ts    
class DriverExt extends DriverExtension {  
  onRelease() {  
    console.log('onRelease');  
  }  
}  
    
```    
  
    
### onConnect    
Extension生命周期回调，如果是connectAbility拉起的服务，会在onCreate之后回调。返回一个RemoteObject对象，用于客户端和服务端进行通信。  
 **调用形式：**     
    
- onConnect(want: Want): rpc.RemoteObject | Promise\<rpc.RemoteObject>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| rpc.RemoteObject | Promise<rpc.RemoteObject> | 一个RemoteObject对象，用于客户端和服务端进行通信。 |  
    
 **示例代码：**   
```ts    
import DriverExtension from '@ohos.app.ability.DriverExtensionAbility';  
import rpc from '@ohos.rpc';  
import Want from '@ohos.app.ability.Want';  
class StubTest extends rpc.RemoteObject{  
    constructor(des : string) {  
        super(des);  
    }  
    onRemoteMessageRequest(code : number, data : rpc.MessageSequence, reply : rpc.MessageSequence, option : rpc.MessageOption) {  
      //必须重写此接口  
      return true;  
    }  
}  
class DriverExt extends DriverExtension {  
  onConnect(want : Want) {  
    console.log('onConnect , want: ${want.abilityName}');  
    return new StubTest('test');  
  }  
}  
    
```    
  
    
### onDisconnect    
Extension的生命周期回调，客户端执行断开连接服务时回调。  
 **调用形式：**     
    
- onDisconnect(want: Want): void | Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| void | Promise<void> |  |  
    
 **示例代码1：**   
```ts    
import DriverExtension from '@ohos.app.ability.DriverExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
class DriverExt extends DriverExtension {  
  onDisconnect(want : Want) {  
    console.log('onDisconnect, want: ${want.abilityName}');  
  }  
}<b></b><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
 **示例代码2：**   
在执行完onDisconnect生命周期回调后，应用可能会退出，从而可能导致onDisconnect中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDisconnect完成后再继续后续的生命周期。  
  
```ts    
import DriverExtension from '@ohos.app.ability.DriverExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
class DriverExt extends DriverExtension {  
async onDisconnect(want : Want) {  
  console.log('onDisconnect, want: ${want.abilityName}');  
  // 调用异步函数...  
}  
}  
    
```    
  
    
### onDump    
转储客户端信息时调用。  
 **调用形式：**     
- onDump(params: Array\<string>): Array\<string>  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| params | Array<string> | true |  表示命令形式的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> |  |  
    
 **示例代码：**   
```ts    
class DriverExt extends DriverExtension {  
    onDump(params : Array<string>) {  
        console.log(`dump, params: ${JSON.stringify(params)}`);  
        return ['params'];  
    }  
}  
    
```    
  
