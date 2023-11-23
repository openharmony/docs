# FormExtensionContext    
FormExtensionContext模块是FormExtensionAbility的上下文环境，继承自ExtensionContext。FormExtensionContext模块提供FormExtensionAbility具有的接口和能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## FormExtensionContext  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
### startAbility    
拉起一个卡片所属应用的Ability。  
 **调用形式：**     
    
- startAbility(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startAbility(want: Want): Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 包含bundleName，abilityName以及用户自定参数用于拉起Ability。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当拉起一个卡片所属应用的Ability成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | The application is not a system application. |  
| 401 | If the input parameter is not valid parameter. |  
| 16500050 | An IPC connection error happened. |  
| 16500100 | Failed to obtain the configuration information. |  
| 16500101 |  |  
| 16501000 | An internal functional error occurred. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import Base from '@ohos.base';  
  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onFormEvent(formId: string, message: string) {  
    // 当触发卡片message事件时，执行startAbility  
    console.log(`FormExtensionAbility onFormEvent, formId: ${formId}, message:${message}`);  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.formstartability',  
      abilityName: 'EntryAbility',  
      parameters: {  
        'message': message  
      }  
    };  
    this.context.startAbility(want, (error: Base.BusinessError) => {  
      if (error) {  
        console.error(`FormExtensionContext startAbility, error:${JSON.stringify(error)}`);  
      } else {  
        console.log('FormExtensionContext startAbility success');  
      }  
    });  
  }  
};  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import Base from '@ohos.base';  
  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onFormEvent(formId: string, message: string) {  
    // 当触发卡片message事件时，执行startAbility  
    console.log(`FormExtensionAbility onFormEvent, formId:${formId}, message:${message}`);  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.formstartability',  
      abilityName: 'EntryAbility',  
      parameters: {  
        'message': message  
      }  
    };  
    this.context.startAbility(want).then(() => {  
      console.info('StartAbility Success');  
    }).catch((error: Base.BusinessError) => {  
      console.error('StartAbility failed');  
    });  
  }  
};  
    
```    
  
    
### connectServiceExtensionAbility<sup>(10+)</sup>    
将一个Ability与服务类型的Ability绑定。  
 **调用形式：**     
- connectServiceExtensionAbility(want: Want, options: ConnectOptions): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |  
| options | ConnectOptions | true | ConnectOptions类型的回调函数，返回服务连接成功、断开或连接失败后的信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回一个connectId，后续根据此connectId断开连接。 |  
    
    
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
    
 **示例代码：**   
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
import Want from '@ohos.app.ability.Want';  
import rpc from '@ohos.rpc';  
import Base from '@ohos.base';  
  
let commRemote: rpc.IRemoteObject | null = null;  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onFormEvent(formId: string, message: string) {  
    // 当触发卡片message事件时，执行connectServiceExtensionAbility  
    console.log(`FormExtensionAbility onFormEvent, formId:${formId}, message:${message}`);  
    let want: Want = {  
      deviceId: '',  
      bundleName: 'com.example.formstartability',  
      abilityName: 'EntryAbility',  
      parameters: {  
        'message': message  
      }  
    };  
    let options: common.ConnectOptions = {  
      onConnect(elementName, remote) {   
        commRemote = remote; // remote 用于与ServiceExtensionAbility进行通信  
        console.log('----------- onConnect -----------');   
      },  
      onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },  
      onFailed(code) { console.error('----------- onFailed -----------') }  
    };  
  
    let connection: number | null = null;  
    try {  
      connection = this.context.connectServiceExtensionAbility(want, options);  
    } catch (paramError) {  
      // 处理入参错误异常  
      console.error(`error.code: ${(paramError as Base.BusinessError).code}, error.message: ${(paramError as Base.BusinessError).message}`);  
    }  
  }  
};  
    
```    
  
    
### disconnectServiceExtensionAbility<sup>(10+)</sup>    
将一个Ability与绑定的服务类型的Ability解绑，断开连接之后需要将连接成功时返回的remote对象置空。  
 **调用形式：**     
    
- disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- disconnectServiceExtensionAbility(connection: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
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
示例（callback）:  
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
import rpc from '@ohos.rpc';  
import Base from '@ohos.base';  
  
// commRemote为onConnect回调内返回的remote对象，此处定义为null无任何实际意义，仅作示例  
let commRemote: rpc.IRemoteObject | null = null;  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onFormEvent(formId: string, message: string) {  
    // 实际使用时，connection为connectServiceExtensionAbility中的返回值，此处定义为1无任何实际意义，仅作示例  
    let connection: number = 1;  
  
    try {  
      this.context.disconnectServiceExtensionAbility(connection, (error: Base.BusinessError) => {  
        commRemote = null;  
        if (error.code) {  
          // 处理业务逻辑错误  
          console.error(  
            `disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);  
          return;  
        }  
        // 执行正常业务  
        console.log('disconnectServiceExtensionAbility succeed');  
      });  
    } catch (paramError) {  
      commRemote = null;  
      // 处理入参错误异常  
      console.error(`error.code: ${(paramError as Base.BusinessError).code}, error.message: ${(paramError as Base.BusinessError).message}`);  
    }  
  }  
};  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
import rpc from '@ohos.rpc';  
import Base from '@ohos.base';  
  
// commRemote为onConnect回调内返回的remote对象，此处定义为null无任何实际意义，仅作示例  
let commRemote: rpc.IRemoteObject | null = null;  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onFormEvent(formId: string, message: string) {  
    // 实际使用时，connection为connectServiceExtensionAbility中的返回值，此处定义为1无任何实际意义，仅作示例  
    let connection: number = 1;  
  
    try {  
      this.context.disconnectServiceExtensionAbility(connection)  
        .then(() => {  
          commRemote = null;  
          // 执行正常业务  
          console.log('disconnectServiceExtensionAbility succeed');  
        })  
        .catch((error: Base.BusinessError) => {  
          commRemote = null;  
          // 处理业务逻辑错误  
          console.error(  
            `disconnectServiceExtensionAbility failed, error.code: ${error.code}, error.message: ${error.message}`);  
        });  
    } catch (paramError) {  
      commRemote = null;  
      // 处理入参错误异常  
      console.error(`error.code: ${(paramError as Base.BusinessError).code}, error.message: ${(paramError as Base.BusinessError).message}`);  
    }  
  }  
};  
    
```    
  
