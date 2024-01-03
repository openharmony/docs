# @ohos.app.ability.UIAbility (UIAbility)

UIAbility is an application component that has the UI. The **UIAbility** module, inherited from [Ability](js-apis-app-ability-ability.md), provides lifecycle callbacks such as component creation, destruction, and foreground/background switching. It also provides the following capabilities related to component collaboration:

- [Caller](#caller): an object returned by [startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybycall). The CallerAbility (caller) uses this object to communicate with the CalleeAbility (callee).
- [Callee](#callee): an internal object of UIAbility. The CalleeAbility (callee) uses this object to communicate with the CallerAbility (caller).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | Yes| No| Context of the UIAbility.|
| launchWant | [Want](js-apis-app-ability-want.md) | Yes| No| Parameters for starting the UIAbility.|
| lastRequestWant | [Want](js-apis-app-ability-want.md) | Yes| No| Parameters used when the UIAbility was started last time.|
| callee | [Callee](#callee) | Yes| No| Object that invokes the stub service.|

## UIAbility.onCreate

onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void

Called to initialize the service logic when a UIAbility instance in the completely closed state is created. In other words, a UIAbility instance enters this lifecycle callback from a [cold start](../../application-models/uiability-intra-device-interaction.md#cold-starting-uiability).

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Information related to this UIAbility, including the ability name and bundle name.|
| param | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | Yes| Parameters for starting the UIAbility, and the reason for the last abnormal exit.|

**Example**

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


## UIAbility.onWindowStageCreate

onWindowStageCreate(windowStage: window.WindowStage): void

Called when a **WindowStage** is created for this UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** information.|

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import window from '@ohos.window';

  class MyUIAbility extends UIAbility {
      onWindowStageCreate(windowStage: window.WindowStage) {
          console.log('onWindowStageCreate');
      }
  }
  ```


## UIAbility.onWindowStageDestroy

onWindowStageDestroy(): void

Called when the **WindowStage** is destroyed for this UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';

  class MyUIAbility extends UIAbility {
      onWindowStageDestroy() {
          console.log('onWindowStageDestroy');
      }
  }
  ```


## UIAbility.onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

Called when the **WindowStage** is restored during the migration of this UIAbility, which is a multi-instance ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** information.|

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import window from '@ohos.window';

  class MyUIAbility extends UIAbility {
      onWindowStageRestore(windowStage: window.WindowStage) {
          console.log('onWindowStageRestore');
      }
  }
  ```


## UIAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

Called when this UIAbility is destroyed to clear resources.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**


  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';

  class MyUIAbility extends UIAbility {
      onDestroy() {
          console.log('onDestroy');
      }
  }
  ```

After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. You can use the asynchronous lifecycle to ensure that the subsequent lifecycle continues only after the asynchronous function in **onDestroy()** finishes the execution.

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';

class MyUIAbility extends UIAbility {
    async onDestroy() {
        console.log('onDestroy');
        // Call the asynchronous function.
    }
}
  ```

## UIAbility.onForeground

onForeground(): void

Called when this UIAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';

  class MyUIAbility extends UIAbility {
      onForeground() {
          console.log('onForeground');
      }
  }
  ```


## UIAbility.onBackground

onBackground(): void

Called when this UIAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';

  class MyUIAbility extends UIAbility {
      onBackground() {
          console.log('onBackground');
      }
  }
  ```


## UIAbility.onContinue

onContinue(wantParam: Record&lt;string, Object&gt;): AbilityConstant.OnContinueResult

Called to save data during the UIAbility migration preparation process.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| **want** parameter.|

**Return value**

| Type| Description|
| -------- | -------- |
| [AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#abilityconstantoncontinueresult) | Continuation result.|

**Example**

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


## UIAbility.onNewWant

onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void

Called when a UIAbility instance that has undergone the following states is started again: started in the foreground, running in the foreground, and switched to the background. In other words, a UIAbility instance enters this lifecycle callback from a [hot start](../../application-models/uiability-intra-device-interaction.md#hot-starting-uiability).

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information, such as the ability name and bundle name.|
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | Yes| Reason for the UIAbility startup and the last abnormal exit.|

**Example**

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

## UIAbility.onDump

onDump(params: Array\<string>): Array\<string>

Called to dump the client information. This API can be used to dump non-sensitive information.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| params | Array\<string> | Yes| Parameters in the form of a command.|

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';

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

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reason | [AbilityConstant.StateType](js-apis-app-ability-abilityConstant.md#abilityconstantstatetype) | Yes| Reason for triggering the callback to save the UIAbility state.|
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| **want** parameter.|

**Return value**

| Type| Description|
| -------- | -------- |
| [AbilityConstant.OnSaveResult](js-apis-app-ability-abilityConstant.md#abilityconstantonsaveresult) | Whether the UIAbility state is saved.|

**Example**

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

## UIAbility.onShare<sup>10+</sup>

onShare(wantParam: Record&lt;string, Object&gt;): void

Called by this UIAbility to set data to share in the cross-device sharing scenario.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Data to share.|

**Example**

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

## UIAbility.onPrepareToTerminate<sup>10+</sup>

onPrepareToTerminate(): boolean

Called when this UIAbility is about to terminate in case that the system parameter **persist.sys.prepare_terminate** is set to **true**. You can define an operation in this callback to determine whether to continue terminating the UIAbility. If a confirmation from the user is required, you can define a pre-termination operation in the callback and use it together with [terminateSelf](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself), for example, displaying a dialog box to ask the user whether to terminate the UIAbility. The UIAbility termination process is canceled when **persist.sys.prepare_terminate** is set to **true**.

**Required permissions**: ohos.permission.PREPARE_APP_TERMINATE

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -- | -- |
| boolean | Whether to terminate the UIAbility. The value **true** means that the termination process is canceled and the UIAbility is not terminated. The value **false** means to continue terminating the UIAbility.|

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import Want from '@ohos.app.ability.Want';
  import { BusinessError } from '@ohos.base';

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
          console.log('startAbilityForResult failed, err:' + JSON.stringify(err));
          this.context.terminateSelf();
        })

      return true; // The pre-termination operation is defined. The value true means that the UIAbility termination process is canceled.
    }
  }
  ```

## UIAbility.onBackPressed<sup>10+</sup>

onBackPressed(): boolean

Called when an operation of going back to a previous page is triggered on this UIAbility. The return value determines whether to destroy the UIAbility instance. By default, the UIAbility instance is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -- | -- |
| boolean | The value **true** means that the UIAbility instance will be moved to the background and will not be destroyed, and **false** means that the UIAbility instance will be destroyed.|

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';

  export default class EntryAbility extends UIAbility {
    onBackPressed() {
      return true;
    }
  }
  ```

## Caller

Implements sending of sequenceable data to the target ability when the CallerAbility invokes the target ability (CalleeAbility).

## Caller.call

call(method: string, data: rpc.Parcelable): Promise&lt;void&gt;;

Sends sequenceable data to the target ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two abilities. The message is used to instruct the callee to register a function to receive the sequenceable data.|
| data | [rpc.Parcelable](js-apis-rpc.md#parcelable9) | Yes| Parcelable data. You need to customize the data.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return a response.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
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
            console.log('Caller.call catch error, error.code: ${callErr.code}, error.message: ${callErr.message}');
          });
      }).catch((err: BusinessError) => {
        console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');
      });
    }
  }
  ```


## Caller.callWithResult

callWithResult(method: string, data: rpc.Parcelable): Promise&lt;rpc.MessageSequence&gt;

Sends sequenceable data to the target ability and obtains the sequenceable data returned by the target ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two abilities. The message is used to instruct the callee to register a function to receive the sequenceable data.|
| data | [rpc.Parcelable](js-apis-rpc.md#parcelable9) | Yes| Parcelable data. You need to customize the data.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[rpc.MessageSequence](js-apis-rpc.md#messagesequence9)&gt; | Promise used to return the sequenceable data from the target ability.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

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


## Caller.release

release(): void

Releases the caller interface of the target ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

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
          caller.release();
        } catch (releaseErr) {
          console.log('Caller.release catch error, error.code: ${releaseErr.code}, error.message: ${releaseErr.message}');
        }
      }).catch((err: BusinessError) => {
        console.log('Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}');
      });
    }
  }
  ```

## Caller.onRelease

 onRelease(callback: OnReleaseCallback): void

Called when the stub on the target ability is disconnected.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Example**

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

## Caller.onRemoteStateChange<sup>10+</sup>

onRemoteStateChange(callback: OnRemoteStateChangeCallback): void

Called when the remote ability state changes in the collaboration scenario.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [OnRemoteStateChangeCallback](#onremotestatechangecallback10) | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | Caller released. The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

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

## Caller.on

on(type: 'release', callback: OnReleaseCallback): void

Called when the stub on the target ability is disconnected.

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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

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

## Caller.off

off(type: 'release', callback: OnReleaseCallback): void

Deregisters a callback that is invoked when the stub on the target ability is disconnected. This capability is reserved.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Example**

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

## Caller.off

off(type: 'release'): void

Deregisters a callback that is invoked when the stub on the target ability is disconnected. This capability is reserved.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|

**Example**

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
  }
  ```

## Callee

Implements callbacks for caller notification registration and deregistration.

## Callee.on

on(method: string, callback: CalleeCallback): void

Registers a caller notification callback, which is invoked when the target ability registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two abilities.|
| callback | [CalleeCallback](#calleecallback) | Yes| JS notification synchronization callback of the [rpc.MessageSequence](js-apis-rpc.md#messagesequence9) type. The callback must return at least one empty [rpc.Parcelable](js-apis-rpc.md#parcelable9) object. Otherwise, the function execution fails.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16200004 | Method registered. The method has registered. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

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

## Callee.off

off(method: string): void

Deregisters a caller notification callback, which is invoked when the target ability registers a function.

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

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).


**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import Want from '@ohos.app.ability.Want';

  let method = 'call_Function';
  export default class MainUIAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
      console.log('Callee onCreate is called');
      try {
        this.callee.off(method);
      } catch (error) {
        console.log('Callee.off catch error, error.code: ${error.code}, error.message: ${error.message}');
      }
    }
  }
  ```

## OnReleaseCallback


(msg: string): void

Defines the callback that is invoked when the stub on the target UIAbility is disconnected.


**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Readable| Writable| Type| Description|
| -------- | -------- | -------- | -------- | -------- |
| (msg: string) | Yes| No| function | Prototype of the listener function registered by the caller.|

## OnRemoteStateChangeCallback<sup>10+</sup>

(msg: string): void

Defines the callback that is invoked when the remote ability state changes in the collaboration scenario.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Readable| Writable| Type| Description|
| -------- | -------- | -------- | -------- | -------- |
| (msg: string) | Yes| No| function | Prototype of the ability state change listener function registered by the caller in the collaboration scenario.|

## CalleeCallback

(indata: rpc.MessageSequence): rpc.Parcelable;

Defines the callback of the registration message notification of the UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Readable| Writable| Type| Description|
| -------- | -------- | -------- | -------- | -------- |
| (indata: [rpc.MessageSequence](js-apis-rpc.md#messagesequence9)) | Yes| No| [rpc.Parcelable](js-apis-rpc.md#parcelable9) | Prototype of the listener function registered by the callee.|
