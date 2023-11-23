# ServiceExtensionContext    
ServiceExtensionContext模块是ServiceExtensionAbility的上下文环境，继承自ExtensionContext。  
ServiceExtensionContext模块提供ServiceExtensionAbility具有的能力，包括启动、停止、绑定、解绑Ability。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ServiceExtensionContext  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### startAbility    
启动Ability。  
 **调用形式：**     
    
- startAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbility(want: Want, options?: StartOptions): Promise\<void>    
起始版本： 9    
- startAbility(want: Want, options?: StartOptions): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |  
| options | StartOptions | true | 回调函数，返回接口调用是否成功的结果。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回接口调用是否成功的结果。 |  
| Promise<void> | 返回一个Promise，包含启动的结果。 |  
    
    
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
| 201 |  |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let options: StartOptions = {  
      windowMode: 0  
    };  
  
    try {  
      this.context.startAbility(want, options, (error: BusinessError) => {  
        if (error.code) {  
          // 处理业务逻辑错误  
          console.error('startAbility failed, error.code: ${error.code}, error.message: ${error.message}');  
          return;  
        }  
        // 执行正常业务  
        console.log('startAbility succeed');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      bundleName: 'com.example.myapp',  
      abilityName: 'MyAbility'  
    };  
    let options: StartOptions = {  
      windowMode: 0,  
    };  
  
    try {  
      this.context.startAbility(want, options)  
        .then((data: void) => {  
          // 执行正常业务  
          console.log('startAbility succeed');  
        })  
        .catch((error: BusinessError) => {  
          // 处理业务逻辑错误  
          console.error('startAbility failed, error.code: ${error.code}, error.message: ${error.message}');  
        });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### startAbilityAsCaller<sup>(10+)</sup>    
使用设置的caller信息启动一个Ability，caller信息由want携带，在系统服务层识别，Ability可以在onCreate生命周期的want参数中获取到caller信息。使用该接口启动一个Ability时，want的caller信息不会被当前自身的应用信息覆盖，系统服务层可获取到初始caller的信息。    使用规则：  - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限  - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限  - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)  
 **调用形式：**     
    
- startAbilityAsCaller(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbilityAsCaller(want: Want, options?: StartOptions): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
| options | StartOptions | true | 启动Ability所携带的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
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
| 16000010 | The call with the continuation flag is forbidden. |  
| 16000011 | The context does not exist. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
| 16200001 | The caller has been released. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import extension from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
  
export default class EntryAbility extends extension {  
  onCreate(want: Want) {  
    // want包含启动该应用的Caller信息  
    let localWant: Want = want;  
    localWant.bundleName = 'com.example.demo';  
    localWant.moduleName = 'entry';  
    localWant.abilityName = 'TestAbility';  
  
    let option: StartOptions = {  
      displayId: 0  
    }  
  
    // 使用启动方的Caller身份信息启动新Ability  
    this.context.startAbilityAsCaller(localWant, option, (err) => {  
      if (err  err.code != 0) {  
        console.error('startAbilityAsCaller failed, err:' + JSON.stringify(err));  
      } else {  
        console.log('startAbilityAsCaller success.');  
      }  
    })  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import extension from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends extension {  
  onCreate(want: Want) {  
    // want包含启动该应用的Caller信息  
    let localWant: Want = want;  
    localWant.bundleName = 'com.example.demo';  
    localWant.moduleName = 'entry';  
    localWant.abilityName = 'TestAbility';  
  
    let option: StartOptions = {  
      displayId: 0  
    }  
  
    // 使用启动方的Caller身份信息启动新Ability  
    this.context.startAbilityAsCaller(localWant, option)  
      .then(() => {  
        console.log('startAbilityAsCaller success.');  
      })  
      .catch((err: BusinessError) => {  
        console.error('startAbilityAsCaller failed, err:' + JSON.stringify(err));  
      })  
  }  
}  
    
```    
  
    
### startAbilityWithAccount    
根据account启动Ability。  
 **调用形式：**     
    
- startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
| accountId | number | true | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |  
| options | StartOptions | true | 启动Ability所携带的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 启动Ability的回调函数。 |  
| Promise<void> | 返回一个Promise，包含接口的结果。 |  
    
    
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
| 16000010 | The call with the continuation flag is forbidden. |  
| 16000011 | The context does not exist. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
| 16200001 | The caller has been released. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let accountId = 100;  
    let options: StartOptions = {  
      windowMode: 0  
    };  
  
    try {  
      this.context.startAbilityWithAccount(want, accountId, options, (error: BusinessError) => {  
        if (error.code) {  
          // 处理业务逻辑错误  
          console.error('startAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');  
          return;  
        }  
        // 执行正常业务  
        console.log('startAbilityWithAccount succeed');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let accountId = 100;  
    let options: StartOptions = {  
      windowMode: 0  
    };  
  
    try {  
      this.context.startAbilityWithAccount(want, accountId, options)  
        .then((data: void) => {  
          // 执行正常业务  
          console.log('startAbilityWithAccount succeed');  
        })  
        .catch((error: BusinessError) => {  
          // 处理业务逻辑错误  
          console.error('startAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');  
        });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### startServiceExtensionAbility    
启动一个新的ServiceExtensionAbility。  
 **调用形式：**     
    
- startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startServiceExtensionAbility(want: Want): Promise\<void>    
起始版本： 9    
- startServiceExtensionAbility(want: Want): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 启动Ability的回调函数。 |  
| Promise<void> | 返回一个Promise，包含接口的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16200001 | The caller has been released. |  
| 16000004 | Can not start invisible component. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
  
    try {  
      this.context.startServiceExtensionAbility(want, (error: BusinessError) => {  
        if (error.code) {  
          // 处理业务逻辑错误  
          console.error('startServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');  
          return;  
        }  
        // 执行正常业务  
        console.log('startServiceExtensionAbility succeed');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
  
    try {  
      this.context.startServiceExtensionAbility(want)  
        .then((data: void) => {  
          // 执行正常业务  
          console.log('startServiceExtensionAbility succeed');  
        })  
        .catch((error: BusinessError) => {  
          // 处理业务逻辑错误  
          console.error('startServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');  
        });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### startServiceExtensionAbilityWithAccount    
启动一个新的ServiceExtensionAbility。  
 **调用形式：**     
    
- startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>    
起始版本： 9    
- startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
| accountId | number | true | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 启动Ability的回调函数。 |  
| Promise<void> | 返回一个Promise，包含接口的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16200001 | The caller has been released. |  
| 16000004 | Can not start invisible component. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let accountId = 100;  
  
    try {  
      this.context.startServiceExtensionAbilityWithAccount(want, accountId, (error: BusinessError) => {  
        if (error.code) {  
          // 处理业务逻辑错误  
          console.error('startServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');  
          return;  
        }  
        // 执行正常业务  
        console.log('startServiceExtensionAbilityWithAccount succeed');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let accountId = 100;  
  
    try {  
      this.context.startServiceExtensionAbilityWithAccount(want, accountId)  
        .then((data: void) => {  
          // 执行正常业务  
          console.log('startServiceExtensionAbilityWithAccount succeed');  
        })  
        .catch((error: BusinessError) => {  
          // 处理业务逻辑错误  
          console.error('startServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');  
        });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### stopServiceExtensionAbility    
停止同一应用程序内的服务。  
 **调用形式：**     
    
- stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 9    
- stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopServiceExtensionAbility(want: Want): Promise\<void>    
起始版本： 9    
- stopServiceExtensionAbility(want: Want): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 停止Ability的want信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 停止Ability的回调函数。 |  
| Promise<void> | 返回一个Promise，包含接口的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16200001 | The caller has been released. |  
| 201 |  |  
| 16000004 | Can not start invisible component. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
  
    try {  
      this.context.stopServiceExtensionAbility(want, (error: BusinessError) => {  
        if (error.code) {  
          // 处理业务逻辑错误  
          console.error('stopServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');  
          return;  
        }  
        // 执行正常业务  
        console.log('stopServiceExtensionAbility succeed');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
  
    try {  
      this.context.stopServiceExtensionAbility(want)  
        .then(() => {  
          // 执行正常业务  
          console.log('stopServiceExtensionAbility succeed');  
        })  
        .catch((error: BusinessError) => {  
          // 处理业务逻辑错误  
          console.error('stopServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');  
        });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### stopServiceExtensionAbilityWithAccount    
使用帐户停止同一应用程序内的服务。  
 **调用形式：**     
    
- stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>    
起始版本： 9    
- stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 停止Ability的want信息。 |  
| accountId | number | true | 需要停止的系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 停止Ability的回调函数。 |  
| Promise<void> | 返回一个Promise，包含接口的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16200001 | The caller has been released. |  
| 16000004 | Can not start invisible component. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let accountId = 100;  
  
    try {  
      this.context.stopServiceExtensionAbilityWithAccount(want, accountId, (error: BusinessError) => {  
        if (error.code) {  
          // 处理业务逻辑错误  
          console.error('stopServiceExtensionAbilityWithAccount failed, error.code: ${error.code, error.message: ${error.message}');  
          return;  
        }  
        // 执行正常业务  
        console.log('stopServiceExtensionAbilityWithAccount succeed');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let accountId = 100;  
  
    try {  
      this.context.stopServiceExtensionAbilityWithAccount(want, accountId)  
        .then(() => {  
          // 执行正常业务  
          console.log('stopServiceExtensionAbilityWithAccount succeed');  
        })  
        .catch((error: BusinessError) => {  
          // 处理业务逻辑错误  
          console.error('stopServiceExtensionAbilityWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');  
        });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### terminateSelf    
停止Ability自身。  
 **调用形式：**     
    
- terminateSelf(callback: AsyncCallback\<void>): void    
起始版本： 9    
- terminateSelf(callback: AsyncCallback\<void>): void    
起始版本： 10    
- terminateSelf(): Promise\<void>    
起始版本： 9    
- terminateSelf(): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回接口调用是否成功的结果。 |  
| Promise<void> | 返回一个Promise，包含接口的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000009 | An ability cannot be started or stopped in Wukong mode. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    this.context.terminateSelf((error: BusinessError) => {  
      if (error.code) {  
        // 处理业务逻辑错误  
        console.error('terminateSelf failed, error.code: ${error.code}, error.message: ${error.message}');  
        return;  
      }  
      // 执行正常业务  
      console.log('terminateSelf succeed');  
    });  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    this.context.terminateSelf().then(() => {  
      // 执行正常业务  
      console.log('terminateSelf succeed');  
    }).catch((error: BusinessError) => {  
      // 处理业务逻辑错误  
      console.error('terminateSelf failed, error.code: ${error.code}, error.message: ${error.message}');  
    });  
  }  
}  
    
```    
  
    
### connectServiceExtensionAbility    
将一个Ability与服务类型的Ability绑定。  
 **调用形式：**     
- connectServiceExtensionAbility(want: Want, options: ConnectOptions): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |  
| options | ConnectOptions | true | ConnectOptions类型的回调函数，返回服务连接成功、断开或连接失败后的信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回一个number，后续根据这个number去断开连接。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000005 | The specified process does not have the permission. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import rpc from '@ohos.rpc';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
let commRemote: rpc.IRemoteObject; // 断开连接时需要释放  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      bundleName: 'com.example.myapp',  
      abilityName: 'MyAbility'  
    };  
    let options: common.ConnectOptions = {  
      onConnect(elementName, remote) {  
        commRemote = remote;  
        console.log('----------- onConnect -----------');  
      },  
      onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },  
      onFailed(code) { console.error('----------- onFailed -----------') }  
    };  
    let connection: number;  
    try {  
      connection = this.context.connectServiceExtensionAbility(want, options);  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### connectServiceExtensionAbility<sup>(10+)</sup>  
 **调用形式：**     
- connectServiceExtensionAbility(want: Want, options: ConnectOptions): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true |  |  
| options | ConnectOptions | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
    
### connectServiceExtensionAbilityWithAccount    
使用AbilityInfo.AbilityType.SERVICE模板和account将当前能力连接到一个能力。  
 **调用形式：**     
- connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 启动Ability的want信息。 |  
| accountId | number | true | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |  
| options | ConnectOptions | true | 远端对象实例。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回Ability连接的结果code。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000005 | The specified process does not have the permission. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import rpc from '@ohos.rpc';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
let commRemote: rpc.IRemoteObject; // 断开连接时需要释放  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let accountId = 100;  
    let options: common.ConnectOptions = {  
      onConnect(elementName, remote) {  
        commRemote = remote;  
        console.log('----------- onConnect -----------');  
      },  
      onDisconnect(elementName) { console.log('----------- onDisconnect -----------'); },  
      onFailed(code) { console.log('----------- onFailed -----------'); }  
    };  
    let connection: number;  
    try {  
      connection = this.context.connectServiceExtensionAbilityWithAccount(want, accountId, options);  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### connectServiceExtensionAbilityWithAccount<sup>(10+)</sup>  
 **调用形式：**     
- connectServiceExtensionAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true |  |  
| accountId | number | true |  |  
| options | ConnectOptions | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
    
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
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16000053 | The ability is not on the top of the UI. |  
| 16000055 | Installation-free timed out. |  
    
### disconnectServiceExtensionAbility    
将一个Ability与绑定的服务类型的Ability解绑，断开连接之后需要将连接成功时返回的remote对象置空。  
 **调用形式：**     
    
- disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- disconnectServiceExtensionAbility(connection: number): Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| connection | number | true | 在connectServiceExtensionAbility中返回的number。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回接口调用是否成功的结果。 |  
| Promise<void> | 返回一个Promise，包含接口的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import rpc from '@ohos.rpc';  
import { BusinessError } from '@ohos.base';  
  
let commRemote: rpc.IRemoteObject; // 断开连接时需要释放  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    // connection为connectServiceExtensionAbility中的返回值  
    let connection = 1;  
    try {  
      this.context.disconnectServiceExtensionAbility(connection, (error: BusinessError) => {  
        commRemote = null;  
        if (error.code) {  
          // 处理业务逻辑错误  
          console.error('disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');  
          return;  
        }  
        // 执行正常业务  
        console.log('disconnectServiceExtensionAbility succeed');  
      });  
    } catch (paramError) {  
      commRemote = null;  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import rpc from '@ohos.rpc';  
import { BusinessError } from '@ohos.base';  
  
let commRemote: rpc.IRemoteObject; // 断开连接时需要释放  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    // connection为connectServiceExtensionAbility中的返回值  
    let connection = 1;  
    try {  
      this.context.disconnectServiceExtensionAbility(connection)  
        .then(() => {  
          commRemote = null;  
          // 执行正常业务  
          console.log('disconnectServiceExtensionAbility succeed');  
        })  
        .catch((error: BusinessError) => {  
          commRemote = null;  
          // 处理业务逻辑错误  
          console.error('disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}');  
        });  
    } catch (paramError) {  
      commRemote = null;  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### startAbilityByCall    
启动指定Ability至前台或后台，同时获取其Caller通信接口，调用方可使用Caller与被启动的Ability进行通信。  使用规则：  - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限  - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限  - 同设备与跨设备场景下，该接口的使用规则存在差异，详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)  
 **调用形式：**     
    
- startAbilityByCall(want: Want): Promise\<Caller>    
起始版本： 9    
- startAbilityByCall(want: Want): Promise\<Caller>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.ABILITY_BACKGROUND_COMMUNICATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 传入需要启动的Ability的信息，包含abilityName、moduleName、bundleName、deviceId(可选)、parameters(可选)，其中deviceId缺省或为空表示启动本地Ability，parameters缺省或为空表示后台启动Ability。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Caller> | 获取要通讯的caller对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16000001 | The specified ability does not exist. |  
| 16000002 | Incorrect ability type. |  
| 16000004 | Can not start invisible component. |  
| 16000005 | The specified process does not have the permission. |  
| 16000006 | Cross-user operations are not allowed. |  
| 16000008 | The crowdtesting application expires. |  
| 16000011 | The context does not exist. |  
| 16000050 | Internal error. |  
| 16200001 | The caller has been released. |  
    
 **示例代码1：**   
示例（Promise）：  
后台启动：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import { Caller } from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let caller: Caller;  
  
    // 后台启动Ability，不配置parameters  
    let wantBackground: Want = {  
      bundleName: 'com.example.myservice',  
      moduleName: 'entry',  
      abilityName: 'EntryAbility',  
      deviceId: ''  
    };  
  
    try {  
      this.context.startAbilityByCall(wantBackground)  
        .then((obj: Caller) => {  
          // 执行正常业务  
          caller = obj;  
          console.log('startAbilityByCall succeed');  
        }).catch((error: BusinessError) => {  
        // 处理业务逻辑错误  
        console.error('startAbilityByCall failed, error.code: ${error.code}, error.message: ${error.message}');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
前台启动：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import { Caller } from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let caller: Caller;  
  
    // 前台启动Ability，将parameters中的'ohos.aafwk.param.callAbilityToForeground'配置为true  
    let wantForeground: Want = {  
      bundleName: 'com.example.myservice',  
      moduleName: 'entry',  
      abilityName: 'EntryAbility',  
      deviceId: '',  
      parameters: {  
        'ohos.aafwk.param.callAbilityToForeground': true  
      }  
    };  
  
    try {  
      this.context.startAbilityByCall(wantForeground)  
        .then((obj: Caller) => {  
          // 执行正常业务  
          caller = obj;  
          console.log('startAbilityByCall succeed');  
        }).catch((error: BusinessError) => {  
        // 处理业务逻辑错误  
        console.error('startAbilityByCall failed, error.code: ${error.code}, error.message: ${error.message}');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### startAbilityByCallWithAccount<sup>(10+)</sup>    
根据accountId对指定的Ability进行call调用，并且可以使用返回的Caller通信接口与被调用方进行通信。  使用规则：  - 跨用户场景下，Call调用目标Ability时，调用方应用需同时申请`ohos.permission.ABILITY_BACKGROUND_COMMUNICATION`与`ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS`权限  - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限  - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限  - 同设备与跨设备场景下，该接口的使用规则存在差异，详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)  
 **调用形式：**     
    
- startAbilityByCallWithAccount(want: Want, accountId: number): Promise\<Caller>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.ABILITY_BACKGROUND_COMMUNICATION and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 传入需要启动的Ability的信息，包含abilityName、moduleName、bundleName、deviceId(可选)、parameters(可选)，其中deviceId缺省或为空表示启动本地Ability，parameters缺省或为空表示后台启动Ability。 |  
| accountId | number | true | 系统帐号的帐号ID，-1表示当前活动用户，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Caller> | 获取要通讯的caller对象。 |  
    
    
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
| 16000011 | The context does not exist. |  
| 16000012 | The application is controlled. |  
| 16000013 | The application is controlled by EDM. |  
| 16000050 | Internal error. |  
| 16200001 | The caller has been released. |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import { Caller } from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let caller: Caller;  
    // 系统账号的账号ID, -1表示当前激活用户  
    let accountId = -1;  
    // 指定启动的Ability  
    let want: Want = {  
      bundleName: 'com.acts.actscalleeabilityrely',  
      moduleName: 'entry',  
      abilityName: 'EntryAbility',  
      deviceId: '',  
      parameters: {  
        // 'ohos.aafwk.param.callAbilityToForeground' 值设置为true时为前台启动, 设置false或不设置为后台启动  
        'ohos.aafwk.param.callAbilityToForeground': true  
      }  
    };  
  
    try {  
      this.context.startAbilityByCallWithAccount(want, accountId)  
        .then((obj: Caller) => {  
          // 执行正常业务  
          caller = obj;  
          console.log('startAbilityByCallWithAccount succeed');  
        }).catch((error: BusinessError) => {  
        // 处理业务逻辑错误  
        console.error('startAbilityByCallWithAccount failed, error.code: ${error.code}, error.message: ${error.message}');  
      });  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
    }  
  }  
}  
    
```    
  
    
### startRecentAbility    
启动一个指定的Ability，如果这个Ability有多个实例，将拉起最近启动的那个实例。使用规则：  - 调用方应用位于后台时，使用该接口启动Ability需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限  - 跨应用场景下，目标Ability的exported属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限  - 组件启动规则详见：[组件启动规则（Stage模型）](../../application-models/component-startup-rules.md)  
 **调用形式：**     
    
- startRecentAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startRecentAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- startRecentAbility(want: Want, options?: StartOptions): Promise\<void>    
起始版本： 9    
- startRecentAbility(want: Want, options?: StartOptions): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 需要启动Ability的want信息。 |  
| options | StartOptions | true | 启动Ability所携带的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定的回调函数的结果。 |  
| Promise<void> |  |  
    
    
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
| 201 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let options: StartOptions = {  
      windowMode: 0  
    };  
  
    try {  
      this.context.startRecentAbility(want, options, (err: BusinessError) => {  
        if (err.code) {  
          // 处理业务逻辑错误  
          console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);  
          return;  
        }  
        // 执行正常业务  
        console.info('startRecentAbility succeed');  
      });  
    } catch (err) {  
      // 处理入参错误异常  
      let code = (err as BusinessError).code;  
      let message = (err as BusinessError).message;  
      console.error(`startRecentAbility failed, code is ${code}, message is ${message}`);  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import StartOptions from '@ohos.app.ability.StartOptions';  
import { BusinessError } from '@ohos.base';  
  
class EntryAbility extends ServiceExtensionAbility {  
  onCreate() {  
    let want: Want = {  
      bundleName: 'com.example.myapplication',  
      abilityName: 'EntryAbility'  
    };  
    let options: StartOptions = {  
      windowMode: 0,  
    };  
  
    try {  
      this.context.startRecentAbility(want, options)  
        .then(() => {  
          // 执行正常业务  
          console.info('startRecentAbility succeed');  
        })  
        .catch((err: BusinessError) => {  
          // 处理业务逻辑错误  
          console.error(`startRecentAbility failed, code is ${err.code}, message is ${err.message}`);  
        });  
    } catch (err) {  
      // 处理入参错误异常  
      let code = (err as BusinessError).code;  
      let message = (err as BusinessError).message;  
      console.error(`startRecentAbility failed, code is ${code}, message is ${message}`);  
    }  
  }  
}  
    
```    
  
