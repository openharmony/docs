# @ohos.app.ability.EmbeddableUIAbility (可嵌入式UIAbility)

EmbeddableUIAbility是为元服务提供可以嵌入式启动的UIAbility，继承自[UIAbility](js-apis-app-ability-uiAbility.md)，同时具备跳转启动和嵌入式启动两种启动方式。

> **说明：**
>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
```

## 属性

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md) | 否 | 是 | 上下文。<br>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core<br>**元服务API**：从API version 12 开始，该接口支持在元服务中使用。 |
| launchWant | [Want](js-apis-app-ability-want.md) | 否 | 否 | EmbeddableUIAbility启动时的参数。当跳转启动EmbeddableUIAbility时具有该参数，嵌入式启动时不具有该参数。<br>**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore<br>**元服务API**：从API version 12 开始，该接口支持在元服务中使用。 |
| lastRequestWant | [Want](js-apis-app-ability-want.md) | 否 | 否 | EmbeddableUIAbility最后请求时的参数。当跳转启动EmbeddableUIAbility时具有该参数，嵌入式启动时不具有该参数。<br>**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore<br>**元服务API**：从API version 12 开始，该接口支持在元服务中使用。|
| callee | [Callee](#callee) | 否 | 否 | 调用Stub（桩）服务对象。当跳转启动EmbeddableUIAbility时具有该参数，嵌入式启动时不具有该参数。<br>**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore|

## EmbeddableUIAbility.onCreate

onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void

EmbeddableUIAbility实例处于完全关闭状态下被创建完成后进入该生命周期回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 当前EmbeddableUIAbility的Want类型信息，包括Ability名称、Bundle名称等。 |
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | 是 | 创建&nbsp;ability、上次异常退出的原因信息。当跳转启动EmbeddableUIAbility时具有该参数，嵌入式启动时不具有该参数。 |

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import Want from '@ohos.app.ability.Want';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
          console.log(`onCreate, want: ${want.abilityName}`);
      }
  }
  ```


## EmbeddableUIAbility.onWindowStageCreate

onWindowStageCreate(windowStage: window.WindowStage): void

当WindowStage创建后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | 是 | WindowStage相关信息。 |

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import window from '@ohos.window';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onWindowStageCreate(windowStage: window.WindowStage) {
          console.log('onWindowStageCreate');
      }
  }
  ```


## EmbeddableUIAbility.onWindowStageDestroy

onWindowStageDestroy(): void

当WindowStage销毁后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onWindowStageDestroy() {
          console.log('onWindowStageDestroy');
      }
  }
  ```


## EmbeddableUIAbility.onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

当迁移多实例ability时，恢复WindowStage后调用。该生命周期仅在跳转启动时生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | 是 | WindowStage相关信息。 |

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import window from '@ohos.window';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onWindowStageRestore(windowStage: window.WindowStage) {
          console.log('onWindowStageRestore');
      }
  }
  ```


## EmbeddableUIAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

EmbeddableUIAbility生命周期回调，在销毁时回调，执行资源清理等操作。使用同步回调或Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | 无返回结果或无返回结果的Promise对象。 |

**示例：**


  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onDestroy() {
          console.log('onDestroy');
      }
  }
  ```

在执行完onDestroy生命周期回调后，应用可能会退出，从而可能导致onDestroy中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDestroy完成后再继续后续的生命周期。

  ```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

class MyEmbeddableUIAbility extends EmbeddableUIAbility {
    async onDestroy() {
        console.log('onDestroy');
        // 调用异步函数...
    }
}
  ```

## EmbeddableUIAbility.onForeground

onForeground(): void

EmbeddableUIAbility生命周期回调，当应用从后台转到前台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onForeground() {
          console.log('onForeground');
      }
  }
  ```


## EmbeddableUIAbility.onBackground

onBackground(): void

EmbeddableUIAbility生命周期回调，当应用从前台转到后台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onBackground() {
          console.log('onBackground');
      }
  }
  ```


## EmbeddableUIAbility.onContinue

onContinue(wantParam: Record&lt;string, Object&gt;): AbilityConstant.OnContinueResult | Promise&lt;AbilityConstant.OnContinueResult&gt;

当Ability准备迁移时触发，保存数据。该生命周期仅在跳转启动时生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | want相关参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#abilityconstantoncontinueresult)&nbsp; \| &nbsp;Promise&lt;AbilityConstant.OnContinueResult&gt; | Ability迁移结果。 |

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onContinue(wantParams: Record<string, Object>) {
          console.log('onContinue');
          wantParams['myData'] = 'my1234567';
          return AbilityConstant.OnContinueResult.AGREE;
      }
  }
  ```


## EmbeddableUIAbility.onNewWant

onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void

EmbeddableUIAbility实例已经启动并在前台运行过，由于某些原因切换到后台，再次启动该EmbeddableUIAbility实例时会回调执行该方法。该生命周期仅在跳转启动时生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，如ability名称，包名等。 |
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | 是 | EmbeddableUIAbility启动的原因、上次异常退出的原因信息。 |

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import Want from '@ohos.app.ability.Want';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam) {
          console.log(`onNewWant, want: ${want.abilityName}`);
          console.log(`onNewWant, launchParam: ${JSON.stringify(launchParam)}`);
      }
  }
  ```

## EmbeddableUIAbility.onDump

onDump(params: Array\<string>): Array\<string>

转储客户端信息时调用，可用于转储非敏感信息。该生命周期仅在跳转启动时生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| params | Array\<string> | 是 | 表示命令形式的参数。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array\<string> | 转储信息数组。|

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onDump(params: Array<string>) {
          console.log(`dump, params: ${JSON.stringify(params)}`);
          return ['params'];
      }
  }
  ```


## EmbeddableUIAbility.onSaveState

onSaveState(reason: AbilityConstant.StateType, wantParam: Record&lt;string, Object&gt;): AbilityConstant.OnSaveResult

该API配合[appRecovery](js-apis-app-ability-appRecovery.md)使用。在应用故障时，如果使能了自动保存状态，框架将回调onSaveState保存EmbeddableUIAbility状态。该生命周期仅在跳转启动时生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reason | [AbilityConstant.StateType](js-apis-app-ability-abilityConstant.md#abilityconstantstatetype) | 是 | 回调保存状态的原因。 |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | want相关参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [AbilityConstant.OnSaveResult](js-apis-app-ability-abilityConstant.md#abilityconstantonsaveresult) | 是否同意保存当前EmbeddableUIAbility的状态。 |

**示例：**

  ```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';

class MyEmbeddableUIAbility extends EmbeddableUIAbility {
    onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {
        console.log('onSaveState');
        wantParam['myData'] = 'my1234567';
        return AbilityConstant.OnSaveResult.RECOVERY_AGREE;
    }
}
  ```

## EmbeddableUIAbility.onShare

onShare(wantParam: Record&lt;string, Object&gt;): void

在跨端分享场景下，在EmbeddableUIAbility中设置分享方设备要分享的数据。该生命周期仅在跳转启动时生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | 待分享的数据。 |

**示例：**

  ```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';

class MyEmbeddableUIAbility extends EmbeddableUIAbility {
    onShare(wantParams: Record<string, Object>) {
        console.log('onShare');
        wantParams['ohos.extra.param.key.shareUrl'] = 'example.com';
    }
}
  ```

## EmbeddableUIAbility.onPrepareToTerminate

onPrepareToTerminate(): boolean

EmbeddableUIAbility生命周期回调，当系统预关闭开关打开后（配置系统参数persist.sys.prepare_terminate为true打开），在EmbeddableUIAbility关闭时触发，可在回调中定义操作来决定是否继续执行关闭EmbeddableUIAbility的操作。该生命周期仅在跳转启动时生效。

**需要权限**：ohos.permission.PREPARE_APP_TERMINATE

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**返回值：**

| 类型 | 说明 |
| -- | -- |
| boolean | 是否执行EmbeddableUIAbility关闭操作，返回true表示本次EmbeddableUIAbility关闭流程取消，不再退出，返回false表示EmbeddableUIAbility继续正常关闭。 |

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import Want from '@ohos.app.ability.Want';
  import { BusinessError } from '@ohos.base';

  export default class EntryAbility extends EmbeddableUIAbility {
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
          // 获取ability处理结果，当返回结果的resultCode为0关闭当前EmbeddableUIAbility
          console.log('startAbilityForResult success, resultCode is ' + result.resultCode);
          if (result.resultCode === 0) {
            this.context.terminateSelf();
          }
        }).catch((err: BusinessError)=>{
          // 异常处理
          console.error('startAbilityForResult failed, err:' + JSON.stringify(err));
          this.context.terminateSelf();
        })

      return true; // 已定义预关闭操作后，返回true表示EmbeddableUIAbility取消关闭
    }
  }
  ```

## EmbeddableUIAbility.onBackPressed

onBackPressed(): boolean

EmbeddableUIAbility生命周期回调，当EmbeddableUIAbility侧滑返回时触发，根据返回值决定是否销毁EmbeddableUIAbility。默认返回值为true，会将EmbeddableUIAbility移动到后台不销毁。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**元服务API**：从API version 12 开始，该接口支持在元服务中使用。

**返回值：**

| 类型 | 说明 |
| -- | -- |
| boolean | 返回true表示EmbeddableUIAbility将会被移到后台不销毁，返回false表示EmbeddableUIAbility将正常销毁。 |

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

  export default class EntryAbility extends EmbeddableUIAbility {
    onBackPressed() {
      return true;
    }
  }
  ```

## Callee

通用组件服务端注册和解除客户端caller通知送信的callback接口。

### Callee.on

on(method: string, callback: CalleeCallback): void

通用组件服务端注册消息通知callback。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| method | string | 是 | 与客户端约定的通知消息字符串。 |
| callback | [CalleeCallback](#calleecallback) | 是 | 一个[rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)类型入参的js通知同步回调函数,&nbsp;回调函数至少要返回一个空的[rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9)数据对象,&nbsp;其他视为函数执行错误。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16200004 | Method registered. The method has registered. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
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
          console.log(`MyMessageAble marshalling num[${this.num}] str[${this.str}]`);
          return true;
      }
      unmarshalling(messageSequence: rpc.MessageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          console.log(`MyMessageAble unmarshalling num[${this.num}] str[${this.str}]`);
          return true;
      }
  };
  let method = 'call_Function';
  function funcCallBack(pdata: rpc.MessageSequence) {
      console.log(`Callee funcCallBack is called ${pdata}`);
      let msg = new MyMessageAble('test', '');
      pdata.readParcelable(msg);
      return new MyMessageAble('test1', 'Callee test');
  }
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
      console.log('Callee onCreate is called');
      try {
        this.callee.on(method, funcCallBack);
      } catch (error) {
        console.error(`Callee.on catch error, error.code: ${error.code}, error.message: ${error.message}`);
      }
    }
  }
  ```

### Callee.off

off(method: string): void

解除通用组件服务端注册消息通知callback。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| method | string | 是 | 已注册的通知事件字符串。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16200005 | Method not registered. The method has not registered. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。


**示例：**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import Want from '@ohos.app.ability.Want';

  let method = 'call_Function';
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
      console.log('Callee onCreate is called');
      try {
        this.callee.off(method);
      } catch (error) {
        console.error(`Callee.off catch error, error.code: ${error.code}, error.message: ${error.message}`);
      }
    }
  }
  ```

## OnReleaseCallback


注册通用组件服务端Stub（桩）断开监听通知的回调函数类型。


**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | ----- | --- | -------- |
| msg | string | 是 | 用于传递释放消息。 |


## OnRemoteStateChangeCallback


注册协同场景下跨设备组件状态变化监听通知的回调函数类型。


**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | ----- | --- | -------- |
| msg | string | 是 | 用于传递释放消息。 |


## CalleeCallback


通用组件服务端注册消息通知的回调函数类型。


**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | ----- | --- | -------- |
| indata | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | 是 | 发送需传递的数据。 |

**返回值：**

| 类型   | 说明                                  |
| ------------ | ------------------------------------- |
| [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | 返回的数据对象。 |
