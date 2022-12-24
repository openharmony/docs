# @ohos.app.ability.UIAbility (UIAbility)

UIAbility是包含UI界面的应用组件，提供组件创建、销毁、前后台切换等生命周期回调，同时也具备组件协同的能力，组件协同主要提供如下常用功能：

- [Caller](#caller)：由[startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybycall)接口返回，CallerAbility(调用者)可使用Caller与CalleeAbility(被调用者)进行通信。
- [Callee](#callee)：UIAbility的内部对象，CalleeAbility(被调用者)可以通过Callee与Caller进行通信。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | 是 | 否 | 上下文。 |
| launchWant | [Want](js-apis-app-ability-want.md) | 是 | 否 | UIAbility启动时的参数。 |
| lastRequestWant | [Want](js-apis-app-ability-want.md) | 是 | 否 | UIAbility最后请求时的参数。|
| callee | [Callee](#callee) | 是 | 否 | 调用Stub（桩）服务对象。|

## UIAbility.onCreate

onCreate(want: Want, param: UIAbilityConstant.LaunchParam): void;

UIAbility创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 当前UIAbility的Want类型信息，包括ability名称、bundle名称等。 |
| param | UIAbilityConstant.LaunchParam | 是 | 创建&nbsp;ability、上次异常退出的原因信息。 |

**示例：**

  ```ts
  class MyUIAbility extends UIAbility {
      onCreate(want, param) {
          console.log('onCreate, want:' + want.abilityName);
      }
  }
  ```


## UIAbility.onWindowStageCreate

onWindowStageCreate(windowStage: window.WindowStage): void

当WindowStage创建后调用。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowStage | window.WindowStage | 是 | WindowStage相关信息。 |

**示例：**
    
  ```ts
  class MyUIAbility extends UIAbility {
      onWindowStageCreate(windowStage) {
          console.log('onWindowStageCreate');
      }
  }
  ```


## UIAbility.onWindowStageDestroy

onWindowStageDestroy(): void

当WindowStage销毁后调用。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**示例：**
    
  ```ts
  class MyUIAbility extends UIAbility {
      onWindowStageDestroy() {
          console.log('onWindowStageDestroy');
      }
  }
  ```


## UIAbility.onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

当迁移多实例ability时，恢复WindowStage后调用。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowStage | window.WindowStage | 是 | WindowStage相关信息。 |

**示例：**
    
  ```ts
  class MyUIAbility extends UIAbility {
      onWindowStageRestore(windowStage) {
          console.log('onWindowStageRestore');
      }
  }
  ```


## UIAbility.onDestroy

onDestroy(): void;

UIAbility生命周期回调，在销毁时回调，执行资源清理等操作。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**示例：**
    
  ```ts
  class MyUIAbility extends UIAbility {
      onDestroy() {
          console.log('onDestroy');
      }
  }
  ```


## UIAbility.onForeground

onForeground(): void;

UIAbility生命周期回调，当应用从后台转到前台时触发。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**示例：**
    
  ```ts
  class MyUIAbility extends UIAbility {
      onForeground() {
          console.log('onForeground');
      }
  }
  ```


## UIAbility.onBackground

onBackground(): void;

UIAbility生命周期回调，当应用从前台转到后台时触发。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**示例：**
    
  ```ts
  class MyUIAbility extends UIAbility {
      onBackground() {
          console.log('onBackground');
      }
  }
  ```


## UIAbility.onContinue

onContinue(wantParam : {[key: string]: any}): UIAbilityConstant.OnContinueResult;

当ability迁移准备迁移时触发，保存数据。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wantParam | {[key:&nbsp;string]:&nbsp;any} | 是 | want相关参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| UIAbilityConstant.OnContinueResult | 继续的结果。 |

**示例：**
    
  ```ts
  import UIAbilityConstant from "@ohos.app.ability.UIAbilityConstant"
  class MyUIAbility extends UIAbility {
      onContinue(wantParams) {
          console.log('onContinue');
          wantParams["myData"] = "my1234567";
          return UIAbilityConstant.OnContinueResult.AGREE;
      }
  }
  ```


## UIAbility.onNewWant

onNewWant(want: Want, launchParams: UIAbilityConstant.LaunchParam): void;

当ability的启动模式设置为单例时回调会被调用。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，如Ability名称，Bundle名称等。 |
| launchParams | UIAbilityConstant.LaunchParam | 是 | UIAbility启动的原因、上次异常退出的原因信息。 |

**示例：**
    
  ```ts
  class MyUIAbility extends UIAbility {
      onNewWant(want) {
          console.log('onNewWant, want:' + want.abilityName);
      }
  }
  ```

## UIAbility.onDump

onDump(params: Array\<string>): Array\<string>;

转储客户端信息时调用。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| params | Array\<string> | 是 | 表示命令形式的参数。|

**示例：**
    
  ```ts
  class MyUIAbility extends UIAbility {
      onDump(params) {
          console.log('dump, params:' + JSON.stringify(params));
          return ["params"]
      }
  }
  ```


## UIAbility.onSaveState

onSaveState(reason: UIAbilityConstant.StateType, wantParam : {[key: string]: any}): UIAbilityConstant.OnSaveResult;

该API配合[appRecovery](js-apis-app-ability-appRecovery.md)使用。在应用故障时，如果使能了自动保存状态，框架将回调onSaveState保存UIAbility状态。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reason | [UIAbilityConstant.StateType](js-apis-app-ability-abilityConstant.md#abilityconstantstatetype) | 是 | 回调保存状态的原因。 |
| wantParam | {[key:&nbsp;string]:&nbsp;any} | 是 | want相关参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| UIAbilityConstant.OnSaveResult | 是否同意保存当前UIAbility的状态。 |

**示例：**

  ```ts
import UIAbilityConstant from '@ohos.app.ability.UIAbilityConstant'

class MyUIAbility extends UIAbility {
    onSaveState(reason, wantParam) {
        console.log('onSaveState');
        wantParam["myData"] = "my1234567";
        return UIAbilityConstant.OnSaveResult.RECOVERY_AGREE;
    }
}
  ```



## Caller

通用组件Caller通信客户端调用接口, 用来向通用组件服务端发送约定数据。

## Caller.call

call(method: string, data: rpc.Sequenceable): Promise&lt;void&gt;;

向通用组件服务端发送约定序列化数据。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

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
| 401 | If the input parameter is not valid parameter. |
其他ID见[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**
    
  ```ts
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
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startUIAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainUIAbility",
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

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

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
| 401 | If the input parameter is not valid parameter. |
其他ID见[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

  ```ts
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
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startUIAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainUIAbility",
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

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Invalid input parameter. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal Error. |

**示例：**
    
  ```ts
  var caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startUIAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainUIAbility",
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

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | OnReleaseCallBack | 是 | 返回onRelease回调结果。 |

**示例：**
    
  ```ts
  var caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startUIAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainUIAbility",
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

## Caller.on

 on(type: "release", callback: OnReleaseCallback): void;

注册通用组件服务端Stub（桩）断开监听通知。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听releaseCall事件，固定为'release'。 |
| callback | OnReleaseCallback | 是 | 返回onRelease回调结果。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
其他ID见[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**
    
  ```ts
  var caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startUIAbilityByCall({
        bundleName: "com.example.myservice",
        abilityName: "MainUIAbility",
        deviceId: ""
      }).then((obj) => {
          caller = obj;
          try {
            caller.on("release", (str) => {
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

on(method: string, callback: CalleeCallback): void;

通用组件服务端注册消息通知callback。

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| method | string | 是 | 与客户端约定的通知消息字符串。 |
| callback | CalleeCallback | 是 | 一个rpc.MessageParcel类型入参的js通知同步回调函数,&nbsp;回调函数至少要返回一个空的rpc.Sequenceable数据对象,&nbsp;其他视为函数执行错误。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
其他ID见[元能力子系统错误码](../errorcodes/errorcode-ability.md)

**示例：**

  ```ts
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
  export default class MainUIAbility extends UIAbility {
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

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| method | string | 是 | 已注册的通知事件字符串。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
其他ID见[元能力子系统错误码](../errorcodes/errorcode-ability.md)


**示例：**
    
  ```ts
  var method = 'call_Function';
  export default class MainUIAbility extends UIAbility {
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

## OnReleaseCallback

(msg: string): void;

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

| 名称 | 可读 | 可写 | 类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| (msg: string) | 是 | 否 | function | 调用者注册的侦听器函数接口的原型。 |

## CalleeCallback

(indata: rpc.MessageParcel): rpc.Sequenceable;

**系统能力**：SystemCapability.UIAbility.UIAbilityRuntime.UIAbilityCore

| 名称 | 可读 | 可写 | 类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| (indata: rpc.MessageParcel) | 是 | 否 | rpc.Sequenceable | 被调用方注册的消息侦听器函数接口的原型。 |
