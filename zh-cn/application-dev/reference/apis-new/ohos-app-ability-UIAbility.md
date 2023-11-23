# @ohos.app.ability.UIAbility    
UIAbility是包含UI界面的应用组件，提供组件创建、销毁、前后台切换等生命周期回调，同时也具备组件协同的能力，组件协同主要提供如下常用功能：。UIAbility是包含UI界面的应用组件，提供组件创建、销毁、前后台切换等生命周期回调，同时也具备组件协同的能力，组件协同主要提供如下常用功能：。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## OnReleaseCallback    
注册协同场景下跨设备组件状态变化监听通知。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### null  
 **调用形式：**     
- (msg: string): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| msg | string | true |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  
  let caller: Caller;  
  export default class MainUIAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage) {  
      this.context.startAbilityByCall({  
        bundleName: 'com.example.myservice',  
        abilityName: 'MainUIAbility',  
        deviceId: ''  
      }).then((obj) => {  
          caller = obj;  
          try {  
            caller.onRelease((str) => {  
                console.log(' Caller OnRelease CallBack is called ${str}');  
            });  
          } catch (error) {  
            console.log('Caller.onRelease catch error, error.code: $error.code}, error.message: ${error.message}');  
          }  
      }).catch((err: BusinessError) => {  
        console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');  
      });  
    }  
  }  
    
```    
  
    
## OnRemoteStateChangeCallback<sup>(10+)</sup>  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### null  
 **调用形式：**     
- (msg: string): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| msg | string | true |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  
  let caller: Caller;  
  let dstDeviceId: string;  
  export default class MainAbility extends UIAbility {  
      onWindowStageCreate(windowStage: window.WindowStage) {  
          this.context.startAbilityByCall({  
              bundleName: 'com.example.myservice',  
              abilityName: 'MainUIAbility',  
              deviceId: dstDeviceId  
          }).then((obj) => {  
              caller = obj;  
              try {  
                  caller.onRemoteStateChange((str) => {  
                      console.log('Remote state changed ' + str);  
                  });  
              } catch (error) {  
                  console.log(`Caller.onRemoteStateChange catch error, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);  
              }  
          }).catch((err: BusinessError) => {  
              console.log(`Caller GetCaller error, error.code: ${JSON.stringify(err.code)}, error.message: ${JSON.stringify(err.message)}`);  
          })  
      }  
  }  
    
```    
  
    
## CalleeCallback    
通用组件服务端注册和解除客户端caller通知送信的callback接口。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### null    
与客户端约定的通知消息字符串。  
 **调用形式：**     
- (indata: rpc.MessageSequence): rpc.Parcelable  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| indata | rpc.MessageSequence | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| rpc.Parcelable |  |  
    
## Caller    
通用组件Caller通信客户端调用接口, 用来向通用组件服务端发送约定数据。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### call    
向通用组件服务端发送约定序列化数据。  
 **调用形式：**     
    
- call(method: string, data: rpc.Parcelable): Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| method | string | true | 约定的服务端注册事件字符串。 |  
| data | rpc.Parcelable | true | 由开发者实现的Parcelable可序列化数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16200001 | Caller released. The caller has been released. |  
| 16200002 | Callee invalid. The callee does not exist. |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  import rpc from '@ohos.rpc';  
  
  class MyMessageAble implements rpc.Parcelable { // 自定义的Parcelable数据结构  
    name: string  
    str: string  
    num: number = 1  
    constructor(name: string, str: string) {  
      this.name = name;  
      this.str = str;  
    }  
    marshalling(messageSequence: rpc.MessageSequence) {  
      messageSequence.writeInt(this.num);  
      messageSequence.writeString(this.str);  
      console.log('MyMessageAble marshalling num[${this.num}] str[${this.str}]');  
      return true;  
    }  
    unmarshalling(messageSequence: rpc.MessageSequence) {  
      this.num = messageSequence.readInt();  
      this.str = messageSequence.readString();  
      console.log('MyMessageAble unmarshalling num[${this.num}] str[${this.str}]');  
      return true;  
    }  
  };  
  let method = 'call_Function'; // 约定的通知消息字符串  
  let caller: Caller;  
  export default class MainUIAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage) {  
      this.context.startAbilityByCall({  
        bundleName: 'com.example.myservice',  
        abilityName: 'MainUIAbility',  
        deviceId: ''  
      }).then((obj) => {  
        caller = obj;  
        let msg = new MyMessageAble('msg', 'world'); // 参考Parcelable数据定义  
        caller.call(method, msg)  
          .then(() => {  
            console.log('Caller call() called');  
          })  
          .catch((callErr: BusinessError) => {  
            console.log('Caller.call catch error, error.code: ${callErr.code}, error.message: ${callErr.message}');  
          });  
      }).catch((err: BusinessError) => {  
        console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');  
      });  
    }  
  }  
    
```    
  
    
### callWithResult    
向通用组件服务端发送约定序列化数据, 并将服务端返回的约定序列化数据带回。  
 **调用形式：**     
    
- callWithResult(method: string, data: rpc.Parcelable): Promise\<rpc.MessageSequence>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| method | string | true | 约定的服务端注册事件字符串。 |  
| data | rpc.Parcelable | true | 由开发者实现的Parcelable可序列化数据 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<rpc.MessageSequence> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16200001 | Caller released. The caller has been released. |  
| 16200002 | Callee invalid. The callee does not exist. |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import { Caller } from '@ohos.app.ability.UIAbility';  
import { BusinessError } from '@ohos.base';  
import window from '@ohos.window';  
import rpc from '@ohos.rpc';  
  
class MyMessageAble implements rpc.Parcelable {  
  name: string  
  str: string  
  num: number = 1  
  constructor(name: string, str: string) {  
    this.name = name;  
    this.str = str;  
  }  
  marshalling(messageSequence: rpc.MessageSequence) {  
    messageSequence.writeInt(this.num);  
    messageSequence.writeString(this.str);  
    console.log('MyMessageAble marshalling num[${this.num}] str[${this.str}]');  
    return true;  
  }  
  unmarshalling(messageSequence: rpc.MessageSequence) {  
    this.num = messageSequence.readInt();  
    this.str = messageSequence.readString();  
    console.log('MyMessageAble unmarshalling num[${this.num] str[${this.str}]');  
    return true;  
  }  
};  
let method = 'call_Function';  
let caller: Caller;  
export default class MainUIAbility extends UIAbility {  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    this.context.startAbilityByCall({  
      bundleName: 'com.example.myservice',  
      abilityName: 'MainUIAbility',  
      deviceId: ''  
    }).then((obj) => {  
      caller = obj;  
      let msg = new MyMessageAble('msg', 'world');  
      caller.callWithResult(method, msg)  
        .then((data) => {  
          console.log('Caller callWithResult() called');  
          let retmsg = new MyMessageAble('msg', 'world');  
          data.readParcelable(retmsg);  
        })  
        .catch((callErr: BusinessError) => {  
          console.log('Caller.callWithResult catch error, error.code: ${callErr.code}, error.message: ${callErr.message}');  
        });  
    }).catch((err: BusinessError) => {  
      console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');  
    });  
  }  
}  
    
```    
  
    
### release    
主动释放通用组件服务端的通信接口。  
 **调用形式：**     
- release(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 16200001 | Caller released. The caller has been released. |  
| 16200002 | Callee invalid. The callee does not exist. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  import rpc from '@ohos.rpc';  
  
  class MyMessageAble implements rpc.Parcelable {  
    name: string  
    str: string  
    num: number = 1  
    constructor(name: string, str: string) {  
      this.name = name;  
      this.str = str;  
    }  
    marshalling(messageSequence: rpc.MessageSequence) {  
      messageSequence.writeInt(this.num);  
      messageSequence.writeString(this.str);  
      console.log('MyMessageAble marshalling num[${this.num}] str[${this.str}]');  
      return true;  
    }  
    unmarshalling(messageSequence: rpc.MessageSequence) {  
      this.num = messageSequence.readInt();  
      this.str = messageSequence.readString();  
      console.log('MyMessageAble unmarshalling num[${this.num] str[${this.str}]');  
      return true;  
    }  
  };  
  let method = 'call_Function';  
  let caller: Caller;  
  export default class MainUIAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage) {  
      this.context.startAbilityByCall({  
        bundleName: 'com.example.myservice',  
        abilityName: 'MainUIAbility',  
        deviceId: ''  
      }).then((obj) => {  
        caller = obj;  
        let msg = new MyMessageAble('msg', 'world');  
        caller.callWithResult(method, msg)  
          .then((data) => {  
            console.log('Caller callWithResult() called');  
            let retmsg = new MyMessageAble('msg', 'world');  
            data.readParcelable(retmsg);  
          })  
          .catch((callErr: BusinessError) => {  
            console.log('Caller.callWithResult catch error, error.code: ${callErr.code}, error.message: ${callErr.message}');  
          });  
      }).catch((err: BusinessError) => {  
        console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');  
      });  
    }  
  }  
    
```    
  
    
### onRelease    
注册通用组件服务端Stub（桩）断开监听通知。  
 **调用形式：**     
    
- onRelease(callback: OnReleaseCallback): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回onRelease回调结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16200001 | Caller released. The caller has been released. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  
  let caller: Caller;  
  export default class MainUIAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage) {  
      this.context.startAbilityByCall({  
        bundleName: 'com.example.myservice',  
        abilityName: 'MainUIAbility',  
        deviceId: ''  
      }).then((obj) => {  
          caller = obj;  
          try {  
            caller.onRelease((str) => {  
                console.log(' Caller OnRelease CallBack is called ${str}');  
            });  
          } catch (error) {  
            console.log('Caller.onRelease catch error, error.code: $error.code}, error.message: ${error.message}');  
          }  
      }).catch((err: BusinessError) => {  
        console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');  
      });  
    }  
  }  
    
```    
  
    
### onRemoteStateChange<sup>(10+)</sup>    
注册协同场景下跨设备组件状态变化监听通知。  
 **调用形式：**     
    
- onRemoteStateChange(callback: OnRemoteStateChangeCallback): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回onRemoteStateChange回调结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16200001 | Caller released. The caller has been released. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  
  let caller: Caller;  
  let dstDeviceId: string;  
  export default class MainAbility extends UIAbility {  
      onWindowStageCreate(windowStage: window.WindowStage) {  
          this.context.startAbilityByCall({  
              bundleName: 'com.example.myservice',  
              abilityName: 'MainUIAbility',  
              deviceId: dstDeviceId  
          }).then((obj) => {  
              caller = obj;  
              try {  
                  caller.onRemoteStateChange((str) => {  
                      console.log('Remote state changed ' + str);  
                  });  
              } catch (error) {  
                  console.log(`Caller.onRemoteStateChange catch error, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);  
              }  
          }).catch((err: BusinessError) => {  
              console.log(`Caller GetCaller error, error.code: ${JSON.stringify(err.code)}, error.message: ${JSON.stringify(err.message)}`);  
          })  
      }  
  }  
    
```    
  
    
### on('release')    
注册通用组件服务端Stub（桩）断开监听通知。  
 **调用形式：**     
    
- on(type: 'release', callback: OnReleaseCallback): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听releaseCall事件，固定为'release'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回onRelease回调结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16200001 | Caller released. The caller has been released. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  
  let caller: Caller;  
  export default class MainUIAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage) {  
      this.context.startAbilityByCall({  
        bundleName: 'com.example.myservice',  
        abilityName: 'MainUIAbility',  
        deviceId: ''  
      }).then((obj) => {  
          caller = obj;  
          try {  
            caller.on('release', (str) => {  
                console.log(' Caller OnRelease CallBack is called ${str}');  
            });  
          } catch (error) {  
            console.log('Caller.on catch error, error.code: ${error.code}, error.message: ${error.message}');  
          }  
      }).catch((err: BusinessError) => {  
        console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');  
      });  
    }  
  }  
    
```    
  
    
### off('release')    
取消注册通用组件服务端Stub（桩）断开监听通知。预留能力，当前暂未支持。  
 **调用形式：**     
    
- off(type: 'release', callback: OnReleaseCallback): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听releaseCall事件，固定为'release'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回off回调结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
    
 **示例代码：**   
```ts    
import UIAbility, { OnReleaseCallback } from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  
  let caller: Caller;  
  export default class MainUIAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage) {  
      this.context.startAbilityByCall({  
        bundleName: 'com.example.myservice',  
        abilityName: 'MainUIAbility',  
        deviceId: ''  
      }).then((obj) => {  
          caller = obj;  
          try {  
            let onReleaseCallBack: OnReleaseCallback = (str) => {  
                console.log(' Caller OnRelease CallBack is called ${str}');  
            };  
            caller.on('release', onReleaseCallBack);  
            caller.off('release', onReleaseCallBack);  
          } catch (error) {  
            console.log('Caller.on or Caller.off catch error, error.code: ${error.code}, error.message: ${error.message}');  
          }  
      }).catch((err: BusinessError) => {  
        console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');  
      });  
    }  
  }  
    
```    
  
    
### off('release')    
取消注册通用组件服务端Stub（桩）断开监听通知。预留能力，当前暂未支持。  
 **调用形式：**     
- off(type: 'release'): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听releaseCall事件，固定为'release'。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import UIAbility, { OnReleaseCallback } from '@ohos.app.ability.UIAbility';  
  import { Caller } from '@ohos.app.ability.UIAbility';  
  import { BusinessError } from '@ohos.base';  
  import window from '@ohos.window';  
  
  let caller: Caller;  
  export default class MainUIAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage) {  
      this.context.startAbilityByCall({  
        bundleName: 'com.example.myservice',  
        abilityName: 'MainUIAbility',  
        deviceId: ''  
      }).then((obj) => {  
          caller = obj;  
          try {  
            let onReleaseCallBack: OnReleaseCallback = (str) => {  
                console.log(' Caller OnRelease CallBack is called ${str}');  
            };  
            caller.on('release', onReleaseCallBack);  
            caller.off('release');  
          } catch (error) {  
            console.error('Caller.on or Caller.off catch error, error.code: ${error.code}, error.message: ${error.message}');  
          }  
      }).catch((err: BusinessError) => {  
        console.error('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');  
      });  
    }  
    
```    
  
    
## Callee    
通用组件服务端注册和解除客户端caller通知送信的callback接口。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### on    
通用组件服务端注册消息通知callback。  
 **调用形式：**     
    
- on(method: string, callback: CalleeCallback): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| method | string | true | 与客户端约定的通知消息字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 一个[rpc.MessageSequence](js-apis-rpc.md#messagesequence9)类型入参的js通知同步回调函数,回调函数至少要返回一个空的[rpc.Parcelable](js-apis-rpc.md#parcelable9)数据对象,其他视为函数执行错误。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16200004 | Method registered. The method has registered. |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import UIAbility, { CalleeCallback } from '@ohos.app.ability.UIAbility';  
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  import Want from '@ohos.app.ability.Want';  
  import rpc from '@ohos.rpc';  
  
  class MyMessageAble implements rpc.Parcelable {  
      name: string  
      str: string  
      num: number = 1  
      constructor(name: string, str: string) {  
        this.name = name;  
        this.str = str;  
      }  
      marshalling(messageSequence: rpc.MessageSequence) {  
          messageSequence.writeInt(this.num);  
          messageSequence.writeString(this.str);  
          console.log('MyMessageAble marshalling num[${this.num}] str[${this.str}]');  
          return true;  
      }  
      unmarshalling(messageSequence: rpc.MessageSequence) {  
          this.num = messageSequence.readInt();  
          this.str = messageSequence.readString();  
          console.log('MyMessageAble unmarshalling num[${this.num}] str[${this.str}]');  
          return true;  
      }  
  };  
  let method = 'call_Function';  
  function funcCallBack(pdata: rpc.MessageSequence) {  
      console.log('Callee funcCallBack is called ${pdata}');  
      let msg = new MyMessageAble('test', '');  
      pdata.readParcelable(msg);  
      return new MyMessageAble('test1', 'Callee test');  
  }  
  export default class MainUIAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
      console.log('Callee onCreate is called');  
      try {  
        this.callee.on(method, funcCallBack);  
      } catch (error) {  
        console.log('Callee.on catch error, error.code: ${error.code}, error.message: ${error.message}');  
      }  
    }  
  }  
    
```    
  
    
### off    
解除通用组件服务端注册消息通知callback。  
 **调用形式：**     
- off(method: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| method | string | true | 已注册的通知事件字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16200005 | Method not registered. The method has not registered. |  
| 16000050 | Internal error. |  
    
## UIAbility    
UIAbility是包含UI界面的应用组件，提供组件创建、销毁、前后台切换等生命周期回调，同时也具备组件协同的能力，组件协同主要提供如下常用功能：  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | UIAbilityContext | false | true | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) |  
| launchWant | Want | false | true | [Want](js-apis-app-ability-want.md) |  
| lastRequestWant | Want | false | true | [Want](js-apis-app-ability-want.md) |  
| callee | Callee | false | true | 调用Stub（桩）服务对象。 |  
    
### onCreate    
UIAbility实例处于完全关闭状态下被创建完成后进入该生命周期回调，执行初始化业务逻辑操作。即UIAbility实例[冷启动](../../application-models/uiability-intra-device-interaction.md#目标uiability冷启动)时进入该生命周期回调。  
 **调用形式：**     
- onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前UIAbility的Want类型信息，包括ability名称、bundle名称等。 |  
| launchParam | AbilityConstant.LaunchParam | true | 创建ability、上次异常退出的原因信息。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  import Want from '@ohos.app.ability.Want';  
  
  class MyUIAbility extends UIAbility {  
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
          console.log('onCreate, want: ${want.abilityName}');  
      }  
  }  
    
```    
  
    
### onWindowStageCreate    
当WindowStage创建后调用。  
 **调用形式：**     
- onWindowStageCreate(windowStage: window.WindowStage): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| windowStage | window.WindowStage | true | WindowStage相关信息。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import window from '@ohos.window';  
  
  class MyUIAbility extends UIAbility {  
      onWindowStageCreate(windowStage: window.WindowStage) {  
          console.log('onWindowStageCreate');  
      }  
  }  
    
```    
  
    
### onWindowStageDestroy    
当WindowStage销毁后调用。  
 **调用形式：**     
- onWindowStageDestroy(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
  class MyUIAbility extends UIAbility {  
      onWindowStageDestroy() {  
          console.log('onWindowStageDestroy');  
      }  
  }  
    
```    
  
    
### onWindowStageRestore    
当迁移多实例ability时，恢复WindowStage后调用。  
 **调用形式：**     
- onWindowStageRestore(windowStage: window.WindowStage): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| windowStage | window.WindowStage | true | WindowStage相关信息。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import window from '@ohos.window';  
  
  class MyUIAbility extends UIAbility {  
      onWindowStageRestore(windowStage: window.WindowStage) {  
          console.log('onWindowStageRestore');  
      }  
  }  
    
```    
  
    
### onDestroy    
UIAbility生命周期回调，在销毁时回调，执行资源清理等操作。  
 **调用形式：**     
    
- onDestroy(): void | Promise\<void>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| void | Promise<void> |  |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
  class MyUIAbility extends UIAbility {  
      onDestroy() {  
          console.log('onDestroy');  
      }  
  }  
    
```    
  
    
### onForeground    
UIAbility生命周期回调，当应用从后台转到前台时触发。  
 **调用形式：**     
- onForeground(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
  class MyUIAbility extends UIAbility {  
      onForeground() {  
          console.log('onForeground');  
      }  
  }  
    
```    
  
    
### onBackground    
UIAbility生命周期回调，当应用从前台转到后台时触发。  
 **调用形式：**     
- onBackground(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
  class MyUIAbility extends UIAbility {  
      onBackground() {  
          console.log('onBackground');  
      }  
  }  
    
```    
  
    
### onContinue    
当ability迁移准备迁移时触发，保存数据。  
 **调用形式：**     
- onContinue(wantParam: { [key: string]: Object }): AbilityConstant.OnContinueResult  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wantParam | { [key: string]: Object } | true | want相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AbilityConstant.OnContinueResult | 继续的结果。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
  class MyUIAbility extends UIAbility {  
      onContinue(wantParams: Record<string, Object>) {  
          console.log('onContinue');  
          wantParams['myData'] = 'my1234567';  
          return AbilityConstant.OnContinueResult.AGREE;  
      }  
  }  
    
```    
  
    
### onNewWant    
UIAbility实例已经启动并在前台运行过，由于某些原因切换到后台，再次启动该UIAbility实例时会回调执行该方法。即UIAbility实例[热启动](../../application-models/uiability-intra-device-interaction.md#目标uiability热启动)时进入该生命周期回调。  
 **调用形式：**     
- onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | Want类型参数，如ability名称，包名等。 |  
| launchParam | AbilityConstant.LaunchParam | true | UIAbility启动的原因、上次异常退出的原因信息 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  import Want from '@ohos.app.ability.Want';  
  
  class MyUIAbility extends UIAbility {  
      onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam) {  
          console.log(`onNewWant, want: ${want.abilityName}`);  
          console.log(`onNewWant, launchParam: ${JSON.stringify(launchParam)}`);  
      }  
  }  
    
```    
  
    
### onDump    
转储客户端信息时调用。  
 **调用形式：**     
- onDump(params: Array\<string>): Array\<string>  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
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
import UIAbility from '@ohos.app.ability.UIAbility';  
  
  class MyUIAbility extends UIAbility {  
      onDump(params: Array<string>) {  
          console.log(`dump, params: ${JSON.stringify(params)}`);  
          return ['params'];  
      }  
  }  
    
```    
  
    
### onSaveState    
该API配合[appRecovery](js-apis-app-ability-appRecovery.md)使用。在应用故障时，如果使能了自动保存状态，框架将回调onSaveState保存UIAbility状态。  
 **调用形式：**     
- onSaveState(reason: AbilityConstant.StateType, wantParam: { [key: string]: Object }): AbilityConstant.OnSaveResult  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reason | AbilityConstant.StateType | true | 回调保存状态的原因。 |  
| wantParam | { [key: string]: Object } | true | want相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AbilityConstant.OnSaveResult | 是否同意保存当前UIAbility的状态。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
class MyUIAbility extends UIAbility {  
    onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {  
        console.log('onSaveState');  
        wantParam['myData'] = 'my1234567';  
        return AbilityConstant.OnSaveResult.RECOVERY_AGREE;  
    }  
}  
    
```    
  
    
### onShare<sup>(10+)</sup>    
在跨端分享场景下，在UIAbility中设置分享方设备要分享的数据。  
 **调用形式：**     
- onShare(wantParam: { [key: string]: Object }): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wantParam | { [key: string]: Object } | true | 待分享的数据。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
class MyUIAbility extends UIAbility {  
    onShare(wantParams: Record<string, Object>) {  
        console.log('onShare');  
        wantParams['ohos.extra.param.key.shareUrl'] = 'example.com';  
    }  
}  
    
```    
  
    
### onPrepareToTerminate<sup>(10+)</sup>    
UIAbility生命周期回调，当系统预关闭开关打开后（配置系统参数persist.sys.prepare_terminate为true打开），在UIAbility关闭时触发，可在回调中定义操作来决定是否继续执行关闭UIAbility的操作。如果UIAbility在退出时需要与用户交互确认是否关闭UIAbility，可在此生命周期回调中定义预关闭操作配合[terminateSelf](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)接口退出，如弹窗确认是否关闭，并配置预关闭生命周期返回true取消正常关闭。  
 **调用形式：**     
- onPrepareToTerminate(): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore  
 **需要权限：** ohos.permission.PREPARE_APP_TERMINATE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否执行UIAbility关闭操作，返回true表示本次UIAbility关闭流程取消，不再退出，返回false表示UIAbility继续正常关闭。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  import Want from '@ohos.app.ability.Want';  
  import { BusinessError } from '@ohos.base';  
  
  export default class EntryAbility extends UIAbility {  
    onPrepareToTerminate() {  
      // 开发者定义预关闭动作  
      // 例如拉起另一个ability，根据ability处理结果执行异步关闭  
      let want: Want = {  
        bundleName: "com.example.myapplication",  
        moduleName: "entry",  
        abilityName: "SecondAbility"  
      }  
      this.context.startAbilityForResult(want)  
        .then((result)=>{  
          // 获取ability处理结果，当返回结果的resultCode为0关闭当前UIAbility  
          console.log('startAbilityForResult success, resultCode is ' + result.resultCode);  
          if (result.resultCode === 0) {  
            this.context.terminateSelf();  
          }  
        }).catch((err: BusinessError)=>{  
          // 异常处理  
          console.log('startAbilityForResult failed, err:' + JSON.stringify(err));  
          this.context.terminateSelf();  
        })  
  
      return true; // 已定义预关闭操作后，返回true表示UIAbility取消关闭  
    }  
  }  
    
```    
  
    
### onBackPressed<sup>(10+)</sup>    
UIAbility生命周期回调，当UIAbility侧滑返回时触发。根据返回值决定是否销毁UIAbility，默认为销毁UIAbility。  
 **调用形式：**     
- onBackPressed(): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示UIAbility将会被移到后台不销毁，返回false表示UIAbility将正常销毁。 |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
  export default class EntryAbility extends UIAbility {  
    onBackPressed() {  
      return true;  
    }  
  }  
    
```    
  
