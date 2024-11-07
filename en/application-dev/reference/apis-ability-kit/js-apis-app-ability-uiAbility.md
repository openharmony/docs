# @ohos.app.ability.UIAbility (UIAbility)

UIAbility is an application component that has the UI. The UIAbility module, inherited from [Ability](js-apis-app-ability-ability.md), provides lifecycle callbacks such as component creation, destruction, and foreground/background switching. It also provides the following capabilities related to component collaboration:

- [Caller](#caller): an object returned by [startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybycall). The CallerAbility (caller) uses this object to communicate with the CalleeAbility (callee).
- [Callee](#callee): an internal object of UIAbility. The CalleeAbility (callee) uses this object to communicate with the CallerAbility (caller).

For details about the inheritance relationship of each ability, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { UIAbility } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | No| No| Context of the UIAbility.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| launchWant | [Want](js-apis-app-ability-want.md) | No| No| Parameters for starting the UIAbility.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| lastRequestWant | [Want](js-apis-app-ability-want.md) | No| No| Parameters carried in the last request.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| callee | [Callee](#callee) | No| No| Object that invokes the stub service.|

## UIAbility.onCreate

onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void

Called to initialize the service logic when a UIAbility instance in the completely closed state is created. In other words, a UIAbility instance enters this lifecycle callback from a [cold start](../../application-models/uiability-intra-device-interaction.md#cold-starting-uiability). This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information, including the ability name and bundle name.|
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#launchparam) | Yes| Parameters for starting the UIAbility, and the reason for the last abnormal exit.|

**Example**

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

Called when a **WindowStage** is created for this UIAbility.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | Yes| **WindowStage** information.|

**Example**

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

Called when the **WindowStage** is about to be destroyed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | Yes| **WindowStage** information.|

**Example**

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

Called when the **WindowStage** is destroyed for this UIAbility.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

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

Called when the **WindowStage** is restored during the migration of this UIAbility, which is a multi-instance ability.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | Yes| **WindowStage** information.|

**Example**

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

Called to clear resources when this UIAbility is destroyed. This API returns the result synchronously or uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -------- | -------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | No return value or a Promise object that returns no result.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onDestroy() {
    console.log('onDestroy');
  }
}
```

After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. You can use the asynchronous lifecycle to ensure that the subsequent lifecycle continues only after the asynchronous function in **onDestroy()** finishes the execution.

```ts
import { UIAbility } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  async onDestroy() {
    console.log('onDestroy');
    // Call the asynchronous function.
  }
}
```

## UIAbility.onForeground

onForeground(): void

Called when this UIAbility is switched from the background to the foreground. This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

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

Called when this UIAbility is switched from the foreground to the background. This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

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

Called to save data during the UIAbility migration preparation process.

**NOTE**
> 
> Since API version 12, **UIAbility.onContinue** supports the return value in the form of Promise\<[AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)\>.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| **want** parameter.|

**Return value**

| Type| Description|
| -------- | -------- |
| [AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)&nbsp;\|&nbsp;Promise&lt;[AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)&gt;  | Continuation result or Promise used to return the continuation result.|

**Example**

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

An asynchronous API can be used to save data during ability continuation.

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

Called when a UIAbility instance that has undergone the following states is started again: started in the foreground, running in the foreground, and switched to the background. In other words, a UIAbility instance enters this lifecycle callback from a [hot start](../../application-models/uiability-intra-device-interaction.md#hot-starting-uiability).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information, such as the ability name and bundle name.|
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#launchparam) | Yes| Reason for the UIAbility startup and the last abnormal exit.|

**Example**

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

Called to dump the client information. This API can be used to dump non-sensitive information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| params | Array\<string> | Yes| Parameters in the form of a command.|

**Return value**

| Type| Description|
| -------- | -------- |
| Array\<string> | Dumped information array.|

**Example**

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

Called when the framework automatically saves the UIAbility state in the case of an application fault. This API is used together with [appRecovery](js-apis-app-ability-appRecovery.md). If automatic state saving is enabled, **onSaveState** is called to save the state of this UIAbility.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reason | [AbilityConstant.StateType](js-apis-app-ability-abilityConstant.md#statetype) | Yes| Reason for triggering the callback to save the UIAbility state.|
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| **want** parameter.|

**Return value**

| Type| Description|
| -------- | -------- |
| [AbilityConstant.OnSaveResult](js-apis-app-ability-abilityConstant.md#onsaveresult) | Whether the UIAbility state is saved.|

**Example**

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

Called by this UIAbility to set data to share in the cross-device sharing scenario.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Data to share.|

**Example**

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

Called when this UIAbility is about to terminate in case that the system parameter **persist.sys.prepare_terminate** is set to **true**. You can define an operation in this callback to determine whether to continue terminating the UIAbility. If a confirmation from the user is required, you can define a pre-termination operation in the callback and use it together with [terminateSelf](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself), for example, displaying a dialog box to ask the user whether to terminate the UIAbility. The UIAbility termination process is canceled when **persist.sys.prepare_terminate** is set to **true**.

**Required permissions**: ohos.permission.PREPARE_APP_TERMINATE

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -- | -- |
| boolean | Whether to terminate the UIAbility. The value **true** means that the termination process is canceled and the UIAbility is not terminated. The value **false** means to continue terminating the UIAbility.|

**Example**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onPrepareToTerminate() {
    // Define a pre-termination operation,
    // for example, starting another UIAbility and performing asynchronous termination based on the startup result.
    let want: Want = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      abilityName: "SecondAbility"
    }
    this.context.startAbilityForResult(want)
      .then((result)=>{
        // Obtain the startup result and terminate the current UIAbility when resultCode in the return value is 0.
        console.log('startAbilityForResult success, resultCode is ' + result.resultCode);
        if (result.resultCode === 0) {
          this.context.terminateSelf();
        }
      }).catch((err: BusinessError)=>{
      // Exception handling.
      console.error('startAbilityForResult failed, err:' + JSON.stringify(err));
      this.context.terminateSelf();
    })

    return true; // The pre-termination operation is defined. The value true means that the UIAbility termination process is canceled.
  }
}
```

## UIAbility.onBackPressed<sup>10+</sup>

onBackPressed(): boolean

Called when an operation of going back to the previous page is triggered on this UIAbility. The return value determines whether to destroy the UIAbility instance.

- When the target SDK version is earlier than 12, the default return value is **false**, indicating that the UIAbility will be destroyed.
- When the target SDK version is 12 or later, the default return value is **true**, indicating that the UIAbility will be moved to the background and will not be destroyed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -- | -- |
| boolean | The value **true** means that the UIAbility instance will be moved to the background and will not be destroyed, and **false** means that the UIAbility instance will be destroyed.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onBackPressed() {
    return true;
  }
}
```

## Caller

Implements sending of parcelable data to the target UIAbility when the CallerAbility invokes the target UIAbility (CalleeAbility).

### Caller.call

call(method: string, data: rpc.Parcelable): Promise&lt;void&gt;

Sends parcelable data to the target UIAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two UIAbilities. The message is used to instruct the callee to register a function to receive the parcelable data.|
| data | [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Yes| Parcelable data. You need to customize the data.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyMessageAble implements rpc.Parcelable { // Custom parcelable data structure.
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
let method = 'call_Function'; // Notification message string negotiated by the two UIAbilities.
let caller: Caller;

export default class MainUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: ''
    }).then((obj) => {
      caller = obj;
      let msg = new MyMessageAble('msg', 'world'); // See the definition of Parcelable.
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

Sends parcelable data to the target UIAbility and obtains the parcelable data returned by the target UIAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two UIAbilities. The message is used to instruct the callee to register a function to receive the parcelable data.|
| data | [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Yes| Parcelable data. You need to customize the data.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)&gt; | Promise used to return the parcelable data from the target UIAbility.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal error. |

**Example**

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

Releases the caller interface of the target UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |

**Example**

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

Called when the stub on the target UIAbility is disconnected. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | Caller released. The caller has been released. |

**Example**

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

Called when the remote UIAbility state changes in the collaboration scenario. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [OnRemoteStateChangeCallback](#onremotestatechangecallback10) | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | Caller released. The caller has been released. |

**Example**

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

Called when the stub on the target UIAbility is disconnected. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200001 | Caller released. The caller has been released. |

**Example**

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

Deregisters a callback that is invoked when the stub on the target UIAbility is disconnected. This capability is reserved. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Deregisters a callback that is invoked when the stub on the target UIAbility is disconnected. This capability is reserved.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Implements callbacks for caller notification registration and deregistration.

### Callee.on

on(method: string, callback: CalleeCallback): void

Registers a caller notification callback, which is invoked when the target UIAbility registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two UIAbilities.|
| callback | [CalleeCallback](#calleecallback) | Yes| JS notification synchronization callback of the [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) type. The callback must return at least one empty [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) object. Otherwise, the function execution fails.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200004 | Method registered. The method has registered. |
| 16000050 | Internal error. |

**Example**

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

Deregisters a caller notification callback, which is invoked when the target UIAbility registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Registered notification message string.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200005 | Method not registered. The method has not registered. |
| 16000050 | Internal error. |

**Example**

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

Defines the callback that is invoked when the stub on the target UIAbility is disconnected.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| msg | string | Yes| Message used for disconnection.| 
 
## OnRemoteStateChangeCallback<sup>10+</sup>

### (msg: string)

(msg: string): void

Defines the callback that is invoked when the remote UIAbility state changes in the collaboration scenario.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| msg | string | Yes| Message used for disconnection.| 
 
## CalleeCallback

### (indata: rpc.MessageSequence)

(indata: rpc.MessageSequence): rpc.Parcelable

Defines the callback of the registration message notification of the UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| indata | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes| Data to be transferred.|

**Return value**

| Type  | Description                                 |
| ------------ | ------------------------------------- |
| [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Returned data object.|
