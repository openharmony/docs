# @ohos.application.Ability (Ability)

Ability模块提供对Ability生命周期、上下文环境等调用管理的能力，包括Ability创建、销毁、转储客户端信息等。

该模块提供以下Ability相关的常用功能：

- [Caller](#caller)：通用组件Caller通信客户端调用接口, 用来向通用组件服务端发送约定数据。
- [Callee](#callee)：通用组件服务端注册和解除客户端caller通知送信的callback接口。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import Ability from '@ohos.application.Ability';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| context | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | 是 | 否 | 上下文。 | 
| launchWant | [Want](js-apis-app-ability-want.md) | 是 | 否 | Ability启动时的参数。 | 
| lastRequestWant | [Want](js-apis-app-ability-want.md) | 是 | 否 | Ability最后请求时的参数。| 
| callee | [Callee](#callee) | 是 | 否 | 调用Stub（桩）服务对象。| 

## Ability.onCreate

onCreate(want: Want, param: AbilityConstant.LaunchParam): void;

Ability创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-app-ability-want.md) | 是 | 当前Ability的Want类型信息，包括ability名称、bundle名称等。 | 
  | param | AbilityConstant.LaunchParam | 是 | 创建&nbsp;ability、上次异常退出的原因信息。 | 

**示例：**

  ```ts
  class myAbility extends Ability {
      onCreate(want, param) {
          console.log('onCreate, want:' + want.abilityName);
      }
  }
  ```


## Ability.onWindowStageCreate

onWindowStageCreate(windowStage: window.WindowStage): void

当WindowStage创建后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | WindowStage相关信息。 | 

**示例：**
    
  ```ts
  class myAbility extends Ability {
      onWindowStageCreate(windowStage) {
          console.log('onWindowStageCreate');
      }
  }
  ```


## Ability.onWindowStageDestroy

onWindowStageDestroy(): void

当WindowStage销毁后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**
    
  ```ts
  class myAbility extends Ability {
      onWindowStageDestroy() {
          console.log('onWindowStageDestroy');
      }
  }
  ```


## Ability.onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

当迁移多实例ability时，恢复WindowStage后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | WindowStage相关信息。 | 

**示例：**
    
  ```ts
  class myAbility extends Ability {
      onWindowStageRestore(windowStage) {
          console.log('onWindowStageRestore');
      }
  }
  ```


## Ability.onDestroy

onDestroy(): void;

Ability生命周期回调，在销毁时回调，执行资源清理等操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**
    
  ```ts
  class myAbility extends Ability {
      onDestroy() {
          console.log('onDestroy');
      }
  }
  ```


## Ability.onForeground

onForeground(): void;

Ability生命周期回调，当应用从后台转到前台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**
    
  ```ts
  class myAbility extends Ability {
      onForeground() {
          console.log('onForeground');
      }
  }
  ```


## Ability.onBackground

onBackground(): void;

Ability生命周期回调，当应用从前台转到后台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**
    
  ```ts
  class myAbility extends Ability {
      onBackground() {
          console.log('onBackground');
      }
  }
  ```


## Ability.onContinue

onContinue(wantParam : {[key: string]: any}): AbilityConstant.OnContinueResult;

当ability迁移准备迁移时触发，保存数据。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | wantParam | {[key:&nbsp;string]:&nbsp;any} | 是 | want相关参数。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | AbilityConstant.OnContinueResult | 继续的结果。 | 

**示例：**
    
  ```ts
  import AbilityConstant from "@ohos.application.AbilityConstant"
  class myAbility extends Ability {
      onContinue(wantParams) {
          console.log('onContinue');
          wantParams["myData"] = "my1234567";
          return AbilityConstant.OnContinueResult.AGREE;
      }
  }
  ```


## Ability.onNewWant

onNewWant(want: Want, launchParams: AbilityConstant.LaunchParam): void;

当传入新的Want，ability再次被拉起时会回调执行该方法。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | Want类型参数，如Ability名称，Bundle名称等。 |
| launchParams | AbilityConstant.LaunchParam | 是 | Ability启动的原因、上次异常退出的原因信息。 |

**示例：**
    
  ```ts
  class myAbility extends Ability {
      onNewWant(want, launchParams) {
          console.log('onNewWant, want:' + want.abilityName);
          console.log('onNewWant, launchParams:' + JSON.stringify(launchParams));
      }
  }
  ```

## Ability.onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

环境变化通知接口，发生全局配置变更时回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | config | [Configuration](js-apis-application-configuration.md) | 是 | 发生全局配置变更时触发回调，当前全局配置包括系统语言、深浅色模式。 | 

**示例：**
    
  ```ts
  class myAbility extends Ability {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, language:' + config.language);
      }
  }
  ```

## Ability.dump

dump(params: Array\<string>): Array\<string>;

转储客户端信息时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | params | Array\<string> | 是 | 表示命令形式的参数。| 

**示例：**
    
  ```ts
  class myAbility extends Ability {
      dump(params) {
          console.log('dump, params:' + JSON.stringify(params));
          return ["params"]
      }
  }
  ```

## Ability.onMemoryLevel

onMemoryLevel(level: AbilityConstant.MemoryLevel): void;

当系统已决定调整内存时调用。例如，当该功能在后台运行时，没有足够的内存来运行尽可能多的后台进程时可以使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-application-abilityConstant.md#abilityconstantmemorylevel) | 是 | 回调返回内存微调级别，显示当前内存使用状态。| 

**示例：**
    
  ```ts
  class myAbility extends Ability {
    onMemoryLevel(level) {
        console.log('onMemoryLevel, level:' + JSON.stringify(level));
    } 
  }
  ```

## Ability.onSaveState

onSaveState(reason: AbilityConstant.StateType, wantParam : {[key: string]: any}): AbilityConstant.OnSaveResult;

该API配合[appRecovery](js-apis-app-ability-appRecovery.md)使用。在应用故障时，如果使能了自动保存状态，框架将回调onSaveState保存Ability状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | reason | [AbilityConstant.StateType](js-apis-application-abilityConstant.md#abilityconstantstatetype) | 是 | 回调保存状态的原因。 |
  | wantParam | {[key:&nbsp;string]:&nbsp;any} | 是 | want相关参数。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | AbilityConstant.OnSaveResult | 是否同意保存当前Ability的状态。 |

**示例：**

  ```ts
import AbilityConstant from '@ohos.application.AbilityConstant'

class myAbility extends Ability {
    onSaveState(reason, wantParam) {
        console.log('onSaveState');
        wantParam["myData"] = "my1234567";
        return AbilityConstant.OnSaveResult.RECOVERY_AGREE;
    }
}
  ```



## Caller

通用组件Caller通信客户端调用接口, 用来向通用组件服务端发送约定数据。

## Caller.call

call(method: string, data: rpc.Sequenceable): Promise&lt;void&gt;;

向通用组件服务端发送约定序列化数据。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | method | string | 是 | 约定的服务端注册事件字符串。 | 
  | data | rpc.Sequenceable | 是 | 由开发者实现的Sequenceable可序列化数据。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise形式返回应答。 | 

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal Error. |

**示例：**
    
  ```ts
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{ // 自定义的Sequenceable数据结构
    name:""
    str:""
    num: 1
    constructor(name, str) {
      this.name = name;
      this.str = str;
    }
    marshalling(messageParcel) {
      messageParcel.writeInt(this.num);
      messageParcel.writeString(this.str);
      console.log('MyMessageAble marshalling num[' + this.num + '] str[' + this.str + ']');
      return true;
    }
    unmarshalling(messageParcel) {
      this.num = messageParcel.readInt();
      this.str = messageParcel.readString();
      console.log('MyMessageAble unmarshalling num[' + this.num + '] str[' + this.str + ']');
      return true;
    }
  };
  var method = 'call_Function'; // 约定的通知消息字符串
  var caller;
  export default class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainAbility",
        deviceId: ""
      }).then((obj) => {
        caller = obj;
        let msg = new MyMessageAble("msg", "world"); // 参考Sequenceable数据定义
        caller.call(method, msg)
          .then(() => {
            console.log('Caller call() called');
          })
          .catch((callErr) => {
            console.log('Caller.call catch error, error.code: ' + JSON.stringify(callErr.code) +
              ' error.message: ' + JSON.stringify(callErr.message));
          });
      }).catch((err) => {
        console.log('Caller GetCaller error, error.code: ' + JSON.stringify(err.code) +
          ' error.message: ' + JSON.stringify(err.message));
      });
    }
  }
  ```


## Caller.callWithResult

callWithResult(method: string, data: rpc.Sequenceable): Promise&lt;rpc.MessageParcel&gt;;

向通用组件服务端发送约定序列化数据, 并将服务端返回的约定序列化数据带回。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | method | string | 是 | 约定的服务端注册事件字符串。 | 
  | data | rpc.Sequenceable | 是 | 由开发者实现的Sequenceable可序列化数据。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;rpc.MessageParcel&gt; | Promise形式返回通用组件服务端应答数据。 | 

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | The application does not have permission to call the interface. |
| 401 | Invalid input parameter. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal Error. |

**示例：**

  ```ts
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{
    name:""
    str:""
    num: 1
    constructor(name, str) {
      this.name = name;
      this.str = str;
    }
    marshalling(messageParcel) {
      messageParcel.writeInt(this.num);
      messageParcel.writeString(this.str);
      console.log('MyMessageAble marshalling num[' + this.num + '] str[' + this.str + ']');
      return true;
    }
    unmarshalling(messageParcel) {
      this.num = messageParcel.readInt();
      this.str = messageParcel.readString();
      console.log('MyMessageAble unmarshalling num[' + this.num + '] str[' + this.str + ']');
      return true;
    }
  };
  var method = 'call_Function';
  var caller;
  export default class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainAbility",
        deviceId: ""
      }).then((obj) => {
        caller = obj;
        let msg = new MyMessageAble(1, "world");
        caller.callWithResult(method, msg)
          .then((data) => {
            console.log('Caller callWithResult() called');
            let retmsg = new MyMessageAble(0, "");
            data.readSequenceable(retmsg);
          })
          .catch((callErr) => {
            console.log('Caller.callWithResult catch error, error.code: ' + JSON.stringify(callErr.code) +
              ' error.message: ' + JSON.stringify(callErr.message));
          });
      }).catch((err) => {
        console.log('Caller GetCaller error, error.code: ' + JSON.stringify(err.code) +
          ' error.message: ' + JSON.stringify(err.message));
      });
    }
  }
  ```


## Caller.release

release(): void;

主动释放通用组件服务端的通信接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Invalid input parameter. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal Error. |

**示例：**
    
  ```ts
  import Ability from '@ohos.application.Ability';
  var caller;
  export default class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainAbility",
        deviceId: ""
      }).then((obj) => {
        caller = obj;
        try {
          caller.release();
        } catch (releaseErr) {
          console.log('Caller.release catch error, error.code: ' + JSON.stringify(releaseErr.code) +
            ' error.message: ' + JSON.stringify(releaseErr.message));
        }
      }).catch((err) => {
        console.log('Caller GetCaller error, error.code: ' + JSON.stringify(err.code) +
          ' error.message: ' + JSON.stringify(err.message));
      });
    }
  }
  ```

## Caller.onRelease

 onRelease(callback: OnReleaseCallBack): void;

注册通用组件服务端Stub（桩）断开监听通知。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | OnReleaseCallBack | 是 | 返回onRelease回调结果。 | 

**示例：**
    
  ```ts
  import Ability from '@ohos.application.Ability';
  var caller;
  export default class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainAbility",
        deviceId: ""
      }).then((obj) => {
          caller = obj;
          try {
            caller.onRelease((str) => {
                console.log(' Caller OnRelease CallBack is called ' + str);
            });
          } catch (error) {
            console.log('Caller.on catch error, error.code: ' + JSON.stringify(error.code) +
              ' error.message: ' + JSON.stringify(error.message));
          }
      }).catch((err) => {
        console.log('Caller GetCaller error, error.code: ' + JSON.stringify(err.code) +
          ' error.message: ' + JSON.stringify(err.message));
      });
    }
  }
  ```


## Callee

通用组件服务端注册和解除客户端caller通知送信的callback接口。

## Callee.on

on(method: string, callback: CalleeCallBack): void;

通用组件服务端注册消息通知callback。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | method | string | 是 | 与客户端约定的通知消息字符串。 | 
  | callback | CalleeCallBack | 是 | 一个rpc.MessageParcel类型入参的js通知同步回调函数,&nbsp;回调函数至少要返回一个空的rpc.Sequenceable数据对象,&nbsp;其他视为函数执行错误。 | 

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Invalid input parameter. |
| 16200004 | Method registered. The method has registered. |
| 16000050 | Internal Error. |

**示例：**

  ```ts
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{
      name:""
      str:""
      num: 1
      constructor(name, str) {
        this.name = name;
        this.str = str;
      }
      marshalling(messageParcel) {
          messageParcel.writeInt(this.num);
          messageParcel.writeString(this.str);
          console.log('MyMessageAble marshalling num[' + this.num + '] str[' + this.str + ']');
          return true;
      }
      unmarshalling(messageParcel) {
          this.num = messageParcel.readInt();
          this.str = messageParcel.readString();
          console.log('MyMessageAble unmarshalling num[' + this.num + '] str[' + this.str + ']');
          return true;
      }
  };
  var method = 'call_Function';
  function funcCallBack(pdata) {
      console.log('Callee funcCallBack is called ' + pdata);
      let msg = new MyMessageAble("test", "");
      pdata.readSequenceable(msg);
      return new MyMessageAble("test1", "Callee test");
  }
  export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
      console.log('Callee onCreate is called');
      try {
        this.callee.on(method, funcCallBack);
      } catch (error) {
        console.log('Callee.on catch error, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      }
    }
  }
  ```

## Callee.off

off(method: string): void;

解除通用组件服务端注册消息通知callback。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | method | string | 是 | 已注册的通知事件字符串。 | 

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Invalid input parameter. |
| 16200005 | Method not registered. The method has not registered. |
| 16000050 | Internal Error. |


**示例：**
    
  ```ts
  import Ability from '@ohos.application.Ability';
  var method = 'call_Function';
  export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
      console.log('Callee onCreate is called');
      try {
        this.callee.off(method);
      } catch (error) {
        console.log('Callee.off catch error, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      }
    }
  }
  ```

## OnReleaseCallBack

(msg: string): void;

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| (msg: string) | function | 是 | 否 | 调用者注册的侦听器函数接口的原型。 | 

## CalleeCallBack

(indata: rpc.MessageParcel): rpc.Sequenceable;

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| (indata: rpc.MessageParcel) | rpc.Sequenceable | 是 | 否 | 被调用方注册的消息侦听器函数接口的原型。 | 