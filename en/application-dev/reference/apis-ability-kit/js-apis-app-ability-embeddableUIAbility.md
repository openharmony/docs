# @ohos.app.ability.EmbeddableUIAbility (Embeddable UIAbility)

The EmbeddableUIAbility module provides the UIAbility that can be started in embedded mode for atomic services. It inherits from [UIAbility](js-apis-app-ability-uiAbility.md) and supports two startup modes: redirection startup and embedded startup.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md) | No| Yes| Context of the UIAbility.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| launchWant | [Want](js-apis-app-ability-want.md) | No| No| Parameters for starting the EmbeddableUIAbility. This parameter is available only for the EmbeddableUIAbility in redirection startup mode.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| lastRequestWant | [Want](js-apis-app-ability-want.md) | No| No| Parameters carried in the last request. This parameter is available only for the EmbeddableUIAbility in redirection startup mode.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| callee | [Callee](#callee) | No| No| Object that invokes the stub service. This parameter is available only for the EmbeddableUIAbility in redirection startup mode.|

## EmbeddableUIAbility.onCreate

onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void

Called to initialize the service logic when an EmbeddableUIAbility instance in the completely closed state is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information of the EmbeddableUIAbility, including the ability name and bundle name.|
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | Yes| Parameters for starting the EmbeddableUIAbility, and the reason for the last abnormal exit. This parameter is available only for the EmbeddableUIAbility in redirection startup mode.|

**Example**

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

Called when a **WindowStage** is created for this EmbeddableUIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | Yes| **WindowStage** information.|

**Example**

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

Called when the **WindowStage** is destroyed for this EmbeddableUIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Example**

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

Called when the **WindowStage** is restored during the migration of this EmbeddableUIAbility, which is a multi-instance ability. This API is valid only when the EmbeddableUIAbility in started in redirection startup mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/js-apis-window.md#windowstage9) | Yes| **WindowStage** information.|

**Example**

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

Called to clear resources when this EmbeddableUIAbility is being destroyed. This API returns the result synchronously or uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Returns**

| Type| Description|
| -------- | -------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | No return value or a Promise object that returns no result.|

**Example**


  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

  class MyEmbeddableUIAbility extends EmbeddableUIAbility {
      onDestroy() {
          console.log('onDestroy');
      }
  }
  ```

After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. You can use the asynchronous lifecycle to ensure that the subsequent lifecycle continues only after the asynchronous function in **onDestroy()** finishes the execution.

  ```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

class MyEmbeddableUIAbility extends EmbeddableUIAbility {
    async onDestroy() {
        console.log('onDestroy');
        // Call the asynchronous function.
    }
}
  ```

## EmbeddableUIAbility.onForeground

onForeground(): void

Called when this EmbeddableUIAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Example**

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

Called when this EmbeddableUIAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Example**

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

Called to save data during the EmbeddableUIAbility migration preparation process. This API is valid only when the EmbeddableUIAbility in started in redirection startup mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| **want** parameter.|

**Returns**

| Type| Description|
| -------- | -------- |
| [AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#abilityconstantoncontinueresult)&nbsp; \| &nbsp;Promise&lt;AbilityConstant.OnContinueResult&gt; | Ability continuation result.|

**Example**

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

Called when an EmbeddableUIAbility instance that has undergone the following states is started again: started in the foreground, running in the foreground, and switched to the background. This API is valid only when the EmbeddableUIAbility in started in redirection startup mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information, such as the ability name and bundle name.|
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | Yes| Reason for the EmbeddableUIAbility startup and the last abnormal exit.|

**Example**

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

Called to dump the client information. This API can be used to dump non-sensitive information. This API is valid only when the EmbeddableUIAbility in started in redirection startup mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| params | Array\<string> | Yes| Parameters in the form of a command.|

**Returns**

| Type| Description|
| -------- | -------- |
| Array\<string> | Dumped information array.|

**Example**

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

Called when the framework automatically saves the EmbeddableUIAbility state in the case of an application fault. This API is used together with [appRecovery](js-apis-app-ability-appRecovery.md). If automatic state saving is enabled, **onSaveState** is called to save the state of this UIAbility. This API is valid only when the EmbeddableUIAbility in started in redirection startup mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reason | [AbilityConstant.StateType](js-apis-app-ability-abilityConstant.md#abilityconstantstatetype) | Yes| Reason for triggering the callback to save the EmbeddableUIAbility state.|
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| **want** parameter.|

**Returns**

| Type| Description|
| -------- | -------- |
| [AbilityConstant.OnSaveResult](js-apis-app-ability-abilityConstant.md#abilityconstantonsaveresult) | Whether the EmbeddableUIAbility state is saved.|

**Example**

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

Called by this EmbeddableUIAbility to set data to share in the cross-device sharing scenario. This API is valid only when the EmbeddableUIAbility in started in redirection startup mode.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Data to share.|

**Example**

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

Called when this EmbeddableUIAbility is about to terminate in case that the system parameter **persist.sys.prepare_terminate** is set to **true**. You can define an operation in this callback to determine whether to continue terminating the EmbeddableUIAbility. This API is valid only when the EmbeddableUIAbility in started in redirection startup mode.

**Required permissions**: ohos.permission.PREPARE_APP_TERMINATE

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Returns**

| Type| Description|
| -- | -- |
| boolean | Whether to terminate the EmbeddableUIAbility. The value **true** means that the termination process is canceled and the EmbeddableUIAbility is not terminated. The value **false** means to continue terminating the EmbeddableUIAbility.|

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import Want from '@ohos.app.ability.Want';
  import { BusinessError } from '@ohos.base';

  export default class EntryAbility extends EmbeddableUIAbility {
    onPrepareToTerminate() {
      // Define a pre-termination operation,
      // for example, starting another EmbeddableUIAbility and performing asynchronous termination based on the startup result.
      let want: Want = {
        bundleName: "com.example.myapplication",
        moduleName: "entry",
        abilityName: "SecondAbility"
      }
      this.context.startAbilityForResult(want)
        .then((result)=>{
          // Obtain the startup result and terminate the current EmbeddableUIAbility when resultCode in the return value is 0.
          console.log('startAbilityForResult success, resultCode is ' + result.resultCode);
          if (result.resultCode === 0) {
            this.context.terminateSelf();
          }
        }).catch((err: BusinessError)=>{
          // Exception handling.
          console.error('startAbilityForResult failed, err:' + JSON.stringify(err));
          this.context.terminateSelf();
        })

      return true; // The pre-termination operation is defined. The value true means that the EmbeddableUIAbility termination process is canceled.
    }
  }
  ```

## EmbeddableUIAbility.onBackPressed

onBackPressed(): boolean

Called when an operation of going back to the previous page is triggered on this EmbeddableUIAbility. The return value determines whether to destroy the EmbeddableUIAbility instance. The default return value is **true**, indicating that the EmbeddableUIAbility will be switched to the background and will not be destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 12.

**Returns**

| Type| Description|
| -- | -- |
| boolean | The value **true** means that the EmbeddableUIAbility instance will be switched to the background and will not be destroyed, and **false** means that the EmbeddableUIAbility instance will be destroyed.|

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';

  export default class EntryAbility extends EmbeddableUIAbility {
    onBackPressed() {
      return true;
    }
  }
  ```

## Caller

Implements sending of parcelable data to the target EmbeddableUIAbility when the CallerAbility invokes the target EmbeddableUIAbility (CalleeAbility).

### Caller.call

call(method: string, data: rpc.Parcelable): Promise&lt;void&gt;

Sends parcelable data to the target EmbeddableUIAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two UIAbilities. The message is used to instruct the callee to register a function to receive the parcelable data.|
| data | [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Yes| Parcelable data. You need to customize the data.|

**Returns**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import { Caller } from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import window from '@ohos.window';
  import rpc from '@ohos.rpc';

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
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainEmbeddableUIAbility',
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

Sends parcelable data to the target EmbeddableUIAbility and obtains the parcelable data returned by the target EmbeddableUIAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two UIAbilities. The message is used to instruct the callee to register a function to receive the parcelable data.|
| data | [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Yes| Parcelable data. You need to customize the data.|

**Returns**

| Type| Description|
| -------- | -------- |
| Promise&lt;[rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)&gt; | Promise used to return the parcelable data from the target EmbeddableUIAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
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
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainEmbeddableUIAbility',
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

Releases the caller interface of the target EmbeddableUIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import { Caller } from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import window from '@ohos.window';

  let caller: Caller;
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainEmbeddableUIAbility',
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

Called when the stub on the target EmbeddableUIAbility is disconnected. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import { Caller } from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import window from '@ohos.window';

  let caller: Caller;
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainEmbeddableUIAbility',
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

### Caller.onRemoteStateChange

onRemoteStateChange(callback: OnRemoteStateChangeCallback): void

Called when the remote EmbeddableUIAbility state changes in the collaboration scenario. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [OnRemoteStateChangeCallback](#onremotestatechangecallback) | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import { Caller } from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import window from '@ohos.window';

  let caller: Caller;
  let dstDeviceId: string;
  export default class MainAbility extends EmbeddableUIAbility {
      onWindowStageCreate(windowStage: window.WindowStage) {
          this.context.startAbilityByCall({
              bundleName: 'com.example.myservice',
              abilityName: 'MainEmbeddableUIAbility',
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

### Caller.on

on(type: 'release', callback: OnReleaseCallback): void

Called when the stub on the target EmbeddableUIAbility is disconnected. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import { Caller } from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import window from '@ohos.window';

  let caller: Caller;
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainEmbeddableUIAbility',
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

### Caller.off

off(type: 'release', callback: OnReleaseCallback): void

Deregisters a callback that is invoked when the stub on the target EmbeddableUIAbility is disconnected. This capability is reserved. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import { Caller, OnReleaseCallback } from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import window from '@ohos.window';

  let caller: Caller;
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainEmbeddableUIAbility',
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

### Caller.off

off(type: 'release'): void

Deregisters a callback that is invoked when the stub on the target EmbeddableUIAbility is disconnected. This capability is reserved.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|

**Example**

  ```ts
  import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
  import { Caller, OnReleaseCallback } from '@ohos.app.ability.UIAbility';
  import { BusinessError } from '@ohos.base';
  import window from '@ohos.window';

  let caller: Caller;
  export default class MainEmbeddableUIAbility extends EmbeddableUIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainEmbeddableUIAbility',
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

Registers a caller notification callback, which is invoked when the target EmbeddableUIAbility registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two UIAbilities.|
| callback | [CalleeCallback](#calleecallback) | Yes| JS notification synchronization callback of the [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) type. The callback must return at least one empty [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) object. Otherwise, the function execution fails.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200004 | Method registered. The method has registered. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

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

Deregisters a caller notification callback, which is invoked when the target EmbeddableUIAbility registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Registered notification message string.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200005 | Method not registered. The method has not registered. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).


**Example**

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


Defines the callback that is invoked when the stub on the target EmbeddableUIAbility is disconnected.


**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| msg | string | Yes| Message used for disconnection.|


## OnRemoteStateChangeCallback


Defines the callback that is invoked when the remote UIAbility state changes in the collaboration scenario.


**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| msg | string | Yes| Message used for disconnection.|


## CalleeCallback


Defines the callback of the registration message notification of the UIAbility.


**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| indata | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes| Data to be transferred.|

**Returns**

| Type  | Description                                 |
| ------------ | ------------------------------------- |
| [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Returned data object.|
