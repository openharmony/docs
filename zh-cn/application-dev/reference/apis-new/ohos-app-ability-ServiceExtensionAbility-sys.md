# @ohos.app.ability.ServiceExtensionAbility    
ServiceExtensionAbility模块提供后台服务相关扩展能力，提供后台服务创建、销毁、连接、断开等生命周期回调。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ServiceExtensionAbility  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | ServiceExtensionContext | false | true | ServiceExtension的上下文环境，继承自ExtensionContext。 |  
    
### onCreate    
Extension生命周期回调，在创建时回调，执行初始化业务逻辑操作。  
 **调用形式：**     
- onCreate(want: Want): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |  
    
 **示例代码：**   
```ts    
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
  import Want from '@ohos.app.ability.Want';  
  
  class ServiceExt extends ServiceExtension {  
    onCreate(want: Want) {  
      console.log('onCreate, want: ${want.abilityName}');  
    }  
  }  
    
```    
  
    
### onDestroy    
Extension生命周期回调，在销毁时回调，执行资源清理等操作。  
 **调用形式：**     
- onDestroy(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **示例代码：**   
```ts    
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
  
  class ServiceExt extends ServiceExtension {  
    onDestroy() {  
      console.log('onDestroy');  
    }  
  }  
    
```    
  
    
### onRequest    
Extension生命周期回调，如果是startAbility或者startServiceExtensionAbility拉起的服务，会在onCreate之后回调。每次拉起服务都会回调，startId会递增。  
 **调用形式：**     
- onRequest(want: Want, startId: number): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |  
| startId | number | true | 返回拉起次数。首次拉起初始值返回1，多次之后自动递增。 |  
    
 **示例代码：**   
```ts    
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
  import Want from '@ohos.app.ability.Want';  
  
  class ServiceExt extends ServiceExtension {  
    onRequest(want: Want, startId: number) {  
      console.log('onRequest, want: ${want.abilityName}');  
    }  
  }  
    
```    
  
    
### onConnect    
Extension生命周期回调，如果是connectAbility拉起的服务，会在onCreate之后回调。返回一个RemoteObject对象，用于客户端和服务端进行通信。  
 **调用形式：**     
    
- onConnect(want: Want): rpc.RemoteObject | Promise\<rpc.RemoteObject>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| rpc.RemoteObject | Promise<rpc.RemoteObject> | 一个RemoteObject对象，用于客户端和服务端进行通信。 |  
    
 **示例代码1：**   
```ts    
import rpc from '@ohos.rpc';  
  import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
  import Want from '@ohos.app.ability.Want';  
  
  class StubTest extends rpc.RemoteObject{  
      constructor(des: string) {  
          super(des);  
      }  
      onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {  
      }  
  }  
  class ServiceExt extends ServiceExtension {  
    onConnect(want: Want) {  
      console.log('onConnect , want: ${want.abilityName}');  
      return new StubTest('test');  
    }  
  }  
    
```    
  
    
 **示例代码2：**   
如果生成返回值RemoteObject依赖一个异步接口，可以使用异步生命周期：  
```ts    
import rpc from '@ohos.rpc';  
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
  
class StubTest extends rpc.RemoteObject{  
    constructor(des: string) {  
        super(des);  
    }  
    onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {  
    }  
}  
async function getDescriptor() {  
    // 调用异步函数...  
    return "asyncTest"  
}  
class ServiceExt extends ServiceExtension {  
  async onConnect(want: Want) {  
    console.log(`onConnect , want: ${want.abilityName}`);  
    let descriptor = await getDescriptor();  
    return new StubTest(descriptor);  
  }  
}  
    
```    
  
    
### onDisconnect    
Extension的生命周期回调，客户端执行断开连接服务时回调。  
 **调用形式：**     
    
- onDisconnect(want: Want): void | Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
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
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
  import Want from '@ohos.app.ability.Want';  
  
  class ServiceExt extends ServiceExtension {  
    onDisconnect(want: Want) {  
      console.log('onDisconnect, want: ${want.abilityName}');  
    }  
  }  
    
```    
  
    
 **示例代码2：**   
在执行完onDisconnect生命周期回调后，应用可能会退出，从而可能导致onDisconnect中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDisconnect完成后再继续后续的生命周期。  
```ts    
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
  
class ServiceExt extends ServiceExtension {  
  async onDisconnect(want: Want) {  
    console.log('onDisconnect, want: ${want.abilityName}');  
    // 调用异步函数...  
  }  
}  
    
```    
  
    
### onReconnect    
Extension的生命周期回调，当所有以前的客户端都断开连接之后，新客户端尝试连接到服务时调用。预留能力，当前暂未支持。  
 **调用形式：**     
- onReconnect(want: Want): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |  
    
 **示例代码：**   
```ts    
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
  import Want from '@ohos.app.ability.Want';  
  
  class ServiceExt extends ServiceExtension {  
    onReconnect(want: Want) {  
      console.log('onReconnect, want: ${want.abilityName}');  
    }  
  }  
    
```    
  
    
### onConfigurationUpdate    
当Extension更新配置信息时调用。  
 **调用形式：**     
- onConfigurationUpdate(newConfig: Configuration): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newConfig | Configuration | true | 表示需要更新的配置信息。 |  
    
### onDump    
转储客户端信息时调用。  
 **调用形式：**     
- onDump(params: Array\<string>): Array\<string>  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| params | Array<string> | true | 表示命令形式的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> |  |  
    
 **示例代码：**   
```ts    
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';  
  
  class ServiceExt extends ServiceExtension {  
      onDump(params: Array<string>) {  
          console.log(`dump, params: ${JSON.stringify(params)}`);  
          return ['params'];  
      }  
  }  
    
```    
  
