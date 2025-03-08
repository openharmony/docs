# @ohos.app.ability.UIAbility (UIAbility)

UIAbility是包含UI界面的应用组件，继承自[Ability](js-apis-app-ability-ability.md)，提供组件创建、销毁、前后台切换等生命周期回调，同时也具备组件协同的能力，组件协同主要提供如下常用功能：

- [Caller](#caller)：由[startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybycall)接口返回，CallerAbility(调用者)可使用Caller与CalleeAbility(被调用者)进行通信。
- [Callee](#callee)：UIAbility的内部对象，CalleeAbility(被调用者)可以通过Callee与Caller进行通信。

各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { UIAbility } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | 否 | 否 | 上下文。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| launchWant | [Want](js-apis-app-ability-want.md) | 否 | 否 | UIAbility启动时的参数。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| lastRequestWant | [Want](js-apis-app-ability-want.md) | 否 | 否 | UIAbility最后请求时的参数。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。|
| callee | [Callee](#callee) | 否 | 否 | 调用Stub（桩）服务对象。|

## UIAbility.onCreate

onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void

UIAbility实例处于完全关闭状态下被创建完成后进入该生命周期回调，执行初始化业务逻辑操作。即UIAbility实例[冷启动](../../application-models/uiability-intra-device-interaction.md#目标uiability冷启动)时进入该生命周期回调。同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 当前UIAbility的Want类型信息，包括ability名称、bundle名称等。 |
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#launchparam) | 是 | 创建&nbsp;ability、上次异常退出的原因信息。 |

**示例：**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log(`onCreate, want: ${want.abilityName}`);
  }
}
```


## UIAbility.onWindowStageCreate

onWindowStageCreate(windowStage: window.WindowStage): void

当WindowStage创建后调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | 是 | WindowStage相关信息。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class MyUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
  }
}
```


## UIAbility.onWindowStageWillDestroy<sup>12+</sup>

onWindowStageWillDestroy(windowStage: window.WindowStage): void

当WindowStage即将销毁时调用。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | 是 | WindowStage相关信息。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class MyUIAbility extends UIAbility {
  onWindowStageWillDestroy(windowStage: window.WindowStage) {
    console.log('onWindowStageWillDestroy');
  }
}
```


## UIAbility.onWindowStageDestroy

onWindowStageDestroy(): void

当WindowStage销毁后调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onWindowStageDestroy() {
    console.log('onWindowStageDestroy');
  }
}
```


## UIAbility.onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

当迁移多实例ability时，恢复WindowStage后调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | 是 | WindowStage相关信息。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class MyUIAbility extends UIAbility {
  onWindowStageRestore(windowStage: window.WindowStage) {
    console.log('onWindowStageRestore');
  }
}
```


## UIAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

UIAbility生命周期回调，在销毁时回调，执行资源清理等操作。使用同步回调或Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | 无返回结果或无返回结果的Promise对象。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onDestroy() {
    console.log('onDestroy');
  }
}
```

在执行完onDestroy生命周期回调后，应用可能会退出，从而可能导致onDestroy中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDestroy完成后再继续后续的生命周期。

```ts
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  async onDestroy() {
    console.log('onDestroy');
    // 调用异步函数...
  }
}
```

## UIAbility.onForeground

onForeground(): void

UIAbility生命周期回调，当应用从后台转到前台时触发。同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onForeground() {
    console.log('onForeground');
  }
}
```


## UIAbility.onBackground

onBackground(): void

UIAbility生命周期回调，当应用从前台转到后台时触发。同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onBackground() {
    console.log('onBackground');
  }
}
```


## UIAbility.onContinue

onContinue(wantParam: Record&lt;string, Object&gt;): AbilityConstant.OnContinueResult | Promise&lt;AbilityConstant.OnContinueResult&gt;

当Ability准备迁移时触发，保存数据。

> **说明：**
> 
> 从API version 12 开始，UIAbility.onContinue生命周期新增支持返回值为Promise\<[AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)\>形式。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | want相关参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)&nbsp;\|&nbsp;Promise&lt;[AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)&gt;  | 接续的结果或带接续结果的Promise对象。 |

**示例：**

  ```ts
  import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

  class MyUIAbility extends UIAbility {
      onContinue(wantParams: Record<string, Object>) {
          console.log('onContinue');
          wantParams['myData'] = 'my1234567';
          return AbilityConstant.OnContinueResult.AGREE;
      }
  }
  ```

支持应用在迁移时，使用异步接口进行数据保存。

  ```ts
  import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

  class MyUIAbility extends UIAbility {
    async setWant(wantParams: Record<string, Object>) {
      console.log('setWant start');
      for (let time = 0; time < 1000; ++time) {
        wantParams[time] = time;
      }
      console.log('setWant end');
    }

    async onContinue(wantParams: Record<string, Object>) {
        console.log('onContinue');
        return this.setWant(wantParams).then(()=>{
          return AbilityConstant.OnContinueResult.AGREE;
        });
    }
  }
  ```


## UIAbility.onNewWant

onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void

UIAbility实例已经启动并在前台运行过，由于某些原因切换到后台，再次启动该UIAbility实例时会回调执行该方法。即UIAbility实例[热启动](../../application-models/uiability-intra-device-interaction.md#目标uiability热启动)时进入该生命周期回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，如ability名称，包名等。 |
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#launchparam) | 是 | UIAbility启动的原因、上次异常退出的原因信息。 |

**示例：**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.log(`onNewWant, want: ${want.abilityName}`);
    console.log(`onNewWant, launchParam: ${JSON.stringify(launchParam)}`);
  }
}
```

## UIAbility.onDump

onDump(params: Array\<string>): Array\<string>

转储客户端信息时调用，可用于转储非敏感信息。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

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
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onDump(params: Array<string>) {
    console.log(`dump, params: ${JSON.stringify(params)}`);
    return ['params'];
  }
}
```


## UIAbility.onSaveState

onSaveState(reason: AbilityConstant.StateType, wantParam: Record&lt;string, Object&gt;): AbilityConstant.OnSaveResult

该API配合[appRecovery](js-apis-app-ability-appRecovery.md)使用。在应用故障时，如果使能了自动保存状态，框架将回调onSaveState保存UIAbility状态。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reason | [AbilityConstant.StateType](js-apis-app-ability-abilityConstant.md#statetype) | 是 | 回调保存状态的原因。 |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | want相关参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [AbilityConstant.OnSaveResult](js-apis-app-ability-abilityConstant.md#onsaveresult) | 是否同意保存当前UIAbility的状态。 |

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {
    console.log('onSaveState');
    wantParam['myData'] = 'my1234567';
    return AbilityConstant.OnSaveResult.RECOVERY_AGREE;
  }
}
```

## UIAbility.onShare<sup>10+</sup>

onShare(wantParam: Record&lt;string, Object&gt;): void

在跨端分享场景下，在UIAbility中设置分享方设备要分享的数据。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是 | 待分享的数据。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onShare(wantParams: Record<string, Object>) {
    console.log('onShare');
    wantParams['ohos.extra.param.key.shareUrl'] = 'example.com';
  }
}
```

## UIAbility.onPrepareToTerminate<sup>10+</sup>

onPrepareToTerminate(): boolean

UIAbility生命周期回调，在UIAbility关闭时触发，用于在UIAbility正式关闭前执行其他操作。例如，询问用户是否确认关闭UIAbility。如果用户确认关闭UIAbility，可配合[terminateSelf](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)接口关闭。

当前仅在2in1设备上生效。

> **说明：**
>
> - 从API version 15开始，当[UIAbility.onPrepareToTerminateAsync](#uiabilityonpreparetoterminateasync15)实现时，本回调函数将不执行。当[AbilityStage.onPrepareTerminationAsync](js-apis-app-ability-abilityStage.md#abilitystageonprepareterminationasync15)或[AbilityStage.onPrepareTermination](js-apis-app-ability-abilityStage.md#abilitystageonpreparetermination15)实现时，在dock栏或系统托盘处右键点击关闭，本回调函数将不执行。

**需要权限**：ohos.permission.PREPARE_APP_TERMINATE

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**返回值：**

| 类型 | 说明 |
| -- | -- |
| boolean | 是否执行UIAbility关闭操作，返回true表示本次UIAbility关闭流程取消，返回false表示UIAbility继续正常关闭。 |

**示例：**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
      console.error('startAbilityForResult failed, err:' + JSON.stringify(err));
      this.context.terminateSelf();
    })

    return true; // 已定义预关闭操作后，返回true表示UIAbility取消关闭
  }
}
```

## UIAbility.onPrepareToTerminateAsync<sup>15+</sup>

onPrepareToTerminateAsync(): Promise\<boolean>

UIAbility生命周期异步回调，在UIAbility关闭时触发，通过使用Promise异步回调的方式，在UIAbility正式关闭前执行操作。例如，询问用户是否确认关闭UIAbility。如果用户确认关闭UIAbility，可配合[terminateSelf](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself)接口关闭。

当前仅在2in1设备上生效。

> **说明：**
>
> - 当[AbilityStage.onPrepareTerminationAsync](js-apis-app-ability-abilityStage.md#abilitystageonprepareterminationasync15)或[AbilityStage.onPrepareTermination](js-apis-app-ability-abilityStage.md#abilitystageonpreparetermination15)实现时，在dock栏或系统托盘处右键点击关闭，本回调函数将不执行。
>
> - 若异步回调内发生crash，按超时处理，执行等待超过10秒未响应，UIAbility将被强制关闭。

**需要权限**：ohos.permission.PREPARE_APP_TERMINATE

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**返回值：**

| 类型 | 说明 |
| -- | -- |
| Promise\<boolean> | Promise对象。表示是否执行UIAbility关闭操作，返回true表示本次UIAbility关闭流程取消，返回false表示UIAbility继续正常关闭。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  async onPrepareToTerminateAsync(): Promise<boolean> {
    await new Promise<boolean>((res, rej) => {
      setTimeout(res, 2000); // 延时2秒
    });
    return true; // 已定义预关闭操作后，返回true表示UIAbility取消关闭
  }
}
```

## UIAbility.onBackPressed<sup>10+</sup>

onBackPressed(): boolean

UIAbility生命周期回调，当UIAbility侧滑返回时触发，根据返回值决定是否销毁UIAbility。

- 当targetSdkVersion<12时，默认返回值为false，会销毁UIAbility。
- 当targetSdkVersion>=12时，默认返回值为true，会将UIAbility移动到后台不销毁。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**返回值：**

| 类型 | 说明 |
| -- | -- |
| boolean | 返回true表示UIAbility将会被移到后台不销毁，返回false表示UIAbility将正常销毁。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onBackPressed() {
    return true;
  }
}
```

## UIAbility.onCollaborate<sup>16+</sup>

onCollaborate(wantParam: Record&lt;string, Object&gt;): AbilityConstant.CollaborateResult

UIAbility生命周期回调，在多设备协同场景下，协同方应用在被拉起的过程中返回是否接受协同。

 **说明：**
- 该生命周期回调不支持specified启动模式。
- 通过startAbility()等方法拉起协同方应用时，需要在Want对象中设置协同标记[Flags](js-apis-ability-wantConstant.md#flags)为FLAG_ABILITY_ON_COLLABORATE。
- 冷启动时，该回调在[onForeground](#uiabilityonforeground)前或[onBackground](#uiabilityonbackground)后调用；热启动时，该回调在[onNewWant](#uiabilityonnewwant)前调用。


**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名    | 类型                              | 必填 | 说明                                                         |
| --------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| wantParam | Record&lt;string,&nbsp;Object&gt; | 是   | want相关参数，仅支持key值取"ohos.extra.param.key.supportCollaborateIndex"。通过该key值可以可以获取到调用方传输的数据并进行相应的处理。|

**返回值：**

| 名称     | 值   | 说明       |
| -------- | ---- | ---------- |
| [AbilityConstant.CollaborateResult](js-apis-app-ability-abilityConstant.md#collaborateresult16) | 协同方应用是否接受协同。 |

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onCollaborate(wantParam: Record<string, Object>) {
    return AbilityConstant.CollaborateResult.ACCEPT;
  }
}
```

## Caller

通用组件Caller通信客户端调用接口, 用来向通用组件服务端发送约定数据。

### Caller.call

call(method: string, data: rpc.Parcelable): Promise&lt;void&gt;

向通用组件服务端发送约定序列化数据。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| method | string | 是 | 约定的服务端注册事件字符串。 |
| data | [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | 是 | 由开发者实现的Parcelable可序列化数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | The callee does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
          console.error(`Caller.call catch error, error.code: ${callErr.code}, error.message: ${callErr.message}`);
        });
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```


### Caller.callWithResult

callWithResult(method: string, data: rpc.Parcelable): Promise&lt;rpc.MessageSequence&gt;

向通用组件服务端发送约定序列化数据, 并将服务端返回的约定序列化数据带回。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| method | string | 是 | 约定的服务端注册事件字符串。 |
| data | [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | 是 | 由开发者实现的Parcelable可序列化数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)&gt; | Promise对象，返回通用组件服务端应答数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | The callee does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
          console.error(`Caller.callWithResult catch error, error.code: ${callErr.code}, error.message: ${callErr.message}`);
        });
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```


### Caller.release

release(): void

主动释放通用组件服务端的通信接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | The callee does not exist. |

**示例：**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
        caller.release();
      } catch (releaseErr) {
        console.error(`Caller.release catch error, error.code: ${releaseErr.code}, error.message: ${releaseErr.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

### Caller.onRelease

 onRelease(callback: OnReleaseCallback): void

注册通用组件服务端Stub（桩）断开监听通知。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | [OnReleaseCallback](#onreleasecallback) | 是 | 回调函数，返回onRelease回调结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | Caller released. The caller has been released. |

**示例：**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
          console.log(`Caller OnRelease CallBack is called ${str}`);
        });
      } catch (error) {
        console.error(`Caller.onRelease catch error, error.code: $error.code}, error.message: ${error.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

### Caller.onRemoteStateChange<sup>10+</sup>

onRemoteStateChange(callback: OnRemoteStateChangeCallback): void

注册协同场景下跨设备组件状态变化监听通知。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | [OnRemoteStateChangeCallback](#onremotestatechangecallback10) | 是 | 回调函数，返回onRemoteStateChange回调结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | Caller released. The caller has been released. |

**示例：**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
        console.error(`Caller.onRemoteStateChange catch error, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${JSON.stringify(err.code)}, error.message: ${JSON.stringify(err.message)}`);
    })
  }
}
```

### Caller.on('release')

on(type: 'release', callback: OnReleaseCallback): void

注册通用组件服务端Stub（桩）断开监听通知。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听releaseCall事件，固定为'release'。 |
| callback | [OnReleaseCallback](#onreleasecallback) | 是 | 回调函数，返回on回调结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200001 | Caller released. The caller has been released. |

**示例：**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
          console.log(`Caller OnRelease CallBack is called ${str}`);
        });
      } catch (error) {
        console.error(`Caller.on catch error, error.code: ${error.code}, error.message: ${error.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

### Caller.off('release')

off(type: 'release', callback: OnReleaseCallback): void

取消注册通用组件服务端Stub（桩）断开监听通知。预留能力，当前暂未支持。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听releaseCall事件，固定为'release'。 |
| callback | [OnReleaseCallback](#onreleasecallback) | 是 | 回调函数，返回off回调结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { UIAbility, Caller, OnReleaseCallback } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
          console.log(`Caller OnRelease CallBack is called ${str}`);
        };
        caller.on('release', onReleaseCallBack);
        caller.off('release', onReleaseCallBack);
      } catch (error) {
        console.error(`Caller.on or Caller.off catch error, error.code: ${error.code}, error.message: ${error.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

### Caller.off('release')

off(type: 'release'): void

取消注册通用组件服务端Stub（桩）断开监听通知。预留能力，当前暂未支持。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听releaseCall事件，固定为'release'。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { UIAbility, Caller, OnReleaseCallback } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
          console.log(`Caller OnRelease CallBack is called ${str}`);
        };
        caller.on('release', onReleaseCallBack);
        caller.off('release');
      } catch (error) {
        console.error(`Caller.on or Caller.off catch error, error.code: ${error.code}, error.message: ${error.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200004 | The method has been registered. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

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
export default class MainUIAbility extends UIAbility {
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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200005 | The method has not been registered. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

let method = 'call_Function';

export default class MainUIAbility extends UIAbility {
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

### (msg: string)

(msg: string): void

注册通用组件服务端Stub（桩）断开监听通知的回调函数类型。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | ----- | --- | -------- |
| msg | string | 是 | 用于传递释放消息。 | 
 
## OnRemoteStateChangeCallback<sup>10+</sup>

### (msg: string)

(msg: string): void

注册协同场景下跨设备组件状态变化监听通知的回调函数类型。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | ----- | --- | -------- |
| msg | string | 是 | 用于传递释放消息。 | 
 
## CalleeCallback

### (indata: rpc.MessageSequence)

(indata: rpc.MessageSequence): rpc.Parcelable

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
