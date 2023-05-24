# @ohos.app.ability.UIAbility (UIAbility)

The **UIAbility** module manages the UIAbility lifecycle and context, such as creating and destroying a UIAbility, and dumping client information.

This module provides the following common UIAbility-related functions:

- [Caller](#caller): Implements sending of parcelable data to the target UIAbility when the CallerAbility invokes the target UIAbility (CalleeAbility).
- [Callee](#callee): Implements callbacks for caller notification registration and deregistration.

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

onCreate(want: Want, param: AbilityConstant.LaunchParam): void;

Called to initialize the service logic when a UIAbility is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-app-ability-want.md) | Yes| Information related to this UIAbility, including the ability name and bundle name.| 
  | param | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | Yes| Parameters for starting the UIAbility, and the reason for the last abnormal exit.|

**Example**

  ```ts
  class myUIAbility extends UIAbility {
      onCreate(want, param) {
          console.log('onCreate, want:' + want.abilityName);
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
  class myUIAbility extends UIAbility {
      onWindowStageCreate(windowStage) {
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
  class myUIAbility extends UIAbility {
      onWindowStageDestroy() {
          console.log('onWindowStageDestroy');
      }
  }
  ```


## UIAbility.onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

Called when the **WindowStage** is restored during the migration of this UIAbility, which is a multi-instance UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** information.|

**Example**
    
  ```ts
  class myUIAbility extends UIAbility {
      onWindowStageRestore(windowStage) {
          console.log('onWindowStageRestore');
      }
  }
  ```


## UIAbility.onDestroy

onDestroy(): void;

Called when this UIAbility is destroyed to clear resources.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**
    
  ```ts
  class myUIAbility extends UIAbility {
      onDestroy() {
          console.log('onDestroy');
      }
  }
  ```


## UIAbility.onForeground

onForeground(): void;

Called when this UIAbility is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**
    
  ```ts
  class myUIAbility extends UIAbility {
      onForeground() {
          console.log('onForeground');
      }
  }
  ```


## UIAbility.onBackground

onBackground(): void;

Called when this UIAbility is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**
    
  ```ts
  class myUIAbility extends UIAbility {
      onBackground() {
          console.log('onBackground');
      }
  }
  ```


## UIAbility.onContinue

onContinue(wantParam : {[key: string]: any}): AbilityConstant.OnContinueResult;

Called to save data during the UIAbility migration preparation process.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | wantParam | {[key:&nbsp;string]:&nbsp;any} | Yes| **want** parameter.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | [AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#abilityconstantoncontinueresult) | Continuation result.|

**Example**
    
  ```ts
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  class MyUIAbility extends UIAbility {
      onContinue(wantParams) {
          console.log('onContinue');
          wantParams['myData'] = 'my1234567';
          return AbilityConstant.OnContinueResult.AGREE;
      }
  }
  ```


## UIAbility.onNewWant

onNewWant(want: Want, launchParams: AbilityConstant.LaunchParam): void;

Called when a new Want is passed in and this UIAbility is started again.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-app-ability-want.md) | Yes| Want information, such as the ability name and bundle name.|
  | launchParams | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | Yes| Reason for the UIAbility startup and the last abnormal exit.|

**Example**
    
  ```ts
   class MyUIAbility extends UIAbility {
      onNewWant(want, launchParams) {
          console.log('onNewWant, want:' + want.abilityName);
          console.log('onNewWant, launchParams:' + JSON.stringify(launchParams));
       }
   }
  ```

## UIAbility.onDump

onDump(params: Array\<string>): Array\<string>;

Dumps client information.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | params | Array\<string> | Yes| Parameters in the form of a command.| 

**Example**
    
  ```ts
  class myUIAbility extends UIAbility {
      onDump(params) {
          console.log('dump, params:' + JSON.stringify(params));
          return ['params'];
      }
  }
  ```


## UIAbility.onSaveState

onSaveState(reason: AbilityConstant.StateType, wantParam : {[key: string]: any}): AbilityConstant.OnSaveResult;

Called when the framework automatically saves the UIAbility state in the case of an application fault. This API is used together with [appRecovery](js-apis-app-ability-appRecovery.md). If automatic state saving is enabled, **onSaveState** is called to save the state of this UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reason | [AbilityConstant.StateType](js-apis-application-abilityConstant.md#abilityconstantstatetype) | Yes| Reason for triggering the callback to save the UIAbility state.|
  | wantParam | {[key:&nbsp;string]:&nbsp;any} | Yes| **want** parameter.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | AbilityConstant.OnSaveResult | Whether the UIAbility state is saved.|

**Example**

  ```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';

class MyUIAbility extends UIAbility {
    onSaveState(reason, wantParam) {
        console.log('onSaveState');
        wantParam['myData'] = 'my1234567';
        return AbilityConstant.OnSaveResult.RECOVERY_AGREE;
    }
}
  ```



## Caller

Implements sending of parcelable data to the target UIAbility when the CallerAbility invokes the target UIAbility (CalleeAbility).

## Caller.call

call(method: string, data: rpc.Sequenceable): Promise&lt;void&gt;;

Sends parcelable data to the target UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two UIAbilities. The message is used to instruct the callee to register a function to receive the parcelable data.| 
  | data | [rpc.Parcelable](js-apis-rpc.md#parcelable9) | Yes| Parcelable data. You need to customize the data.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return a response.| 

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
    
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  class MyMessageAble{ // Custom parcelable data structure.
    name:''
    str:''
    num: 1
    constructor(name, str) {
      this.name = name;
      this.str = str;
    }
    marshalling(messageSequence) {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      console.log('MyMessageAble marshalling num[' + this.num + '] str[' + this.str + ']');
      return true;
    }
    unmarshalling(messageSequence) {
      this.num = messageSequence.readInt();
      this.str = messageSequence.readString();
      console.log('MyMessageAble unmarshalling num[' + this.num + '] str[' + this.str + ']');
      return true;
    }
  };
  let method = 'call_Function'; // Notification message string negotiated by the two UIAbilities.
  let caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainAbility',
        deviceId: ''
      }).then((obj) => {
        caller = obj;
        let msg = new MyMessageAble('msg', 'world'); // See the definition of Parcelable.
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

callWithResult(method: string, data: rpc.Parcelable): Promise&lt;rpc.MessageSequence&gt;;

Sends parcelable data to the target UIAbility and obtains the parcelable data returned by the target UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two UIAbilities. The message is used to instruct the callee to register a function to receive the parcelable data.| 
  | data | [rpc.Parcelable](js-apis-rpc.md#parcelable9) | Yes| Parcelable data. You need to customize the data.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;[rpc.MessageSequence](js-apis-rpc.md#messagesequence9)&gt; | Promise used to return the parcelable data from the target UIAbility.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  class MyMessageAble{
    name:''
    str:''
    num: 1
    constructor(name, str) {
      this.name = name;
      this.str = str;
    }
    marshalling(messageSequence) {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      console.log('MyMessageAble marshalling num[' + this.num + '] str[' + this.str + ']');
      return true;
    }
    unmarshalling(messageSequence) {
      this.num = messageSequence.readInt();
      this.str = messageSequence.readString();
      console.log('MyMessageAble unmarshalling num[' + this.num + '] str[' + this.str + ']');
      return true;
    }
  };
  let method = 'call_Function';
  let caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainAbility',
        deviceId: ''
      }).then((obj) => {
        caller = obj;
        let msg = new MyMessageAble(1, 'world');
        caller.callWithResult(method, msg)
          .then((data) => {
            console.log('Caller callWithResult() called');
            let retmsg = new MyMessageAble(0, '');
            data.readParcelable(retmsg);
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

Releases the caller interface of the target UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Invalid input parameter. |
| 16200001 | Caller released. The caller has been released. |
| 16200002 | Callee invalid. The callee does not exist. |
| 16000050 | Internal Error. |

**Example**
    
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  let caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainAbility',
        deviceId: ''
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

Registers a callback that is invoked when the stub on the target UIAbility is disconnected.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | [OnReleaseCallBack](#onreleasecallback) | Yes| Callback used to return the result.| 

**Example**
    
  ```ts
  import UIAbility from '@ohos.application.Ability';
  let caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainAbility',
        deviceId: ''
      }).then((obj) => {
          caller = obj;
          try {
            caller.onRelease((str) => {
                console.log(' Caller OnRelease CallBack is called ' + str);
            });
          } catch (error) {
            console.log('Caller.onRelease catch error, error.code: ' + JSON.stringify(error.code) +
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

 on(type: 'release', callback: OnReleaseCallback): void;

Registers a callback that is invoked when the stub on the target UIAbility is disconnected.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **release**.| 
  | callback | [OnReleaseCallBack](#onreleasecallback) | Yes| Callback used to return the result.| 

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
    
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  let caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainAbility',
        deviceId: ''
      }).then((obj) => {
          caller = obj;
          try {
            caller.on('release', (str) => {
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

## Caller.off

off(type: 'release', callback: OnReleaseCallback): void;

Deregisters a callback that is invoked when the stub on the target UIAbility is disconnected. This capability is reserved.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **release**.|
| callback | [OnReleaseCallBack](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
    
  ```ts
  let caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainUIAbility',
        deviceId: ''
      }).then((obj) => {
          caller = obj;
          try {
            let onReleaseCallBack = (str) => {
                console.log(' Caller OnRelease CallBack is called ' + str);
            };
            caller.on('release', onReleaseCallBack);
            caller.off('release', onReleaseCallBack);
          } catch (error) {
            console.log('Caller.on or Caller.off catch error, error.code: ' + JSON.stringify(error.code) +
              ' error.message: ' + JSON.stringify(error.message));
          }
      }).catch((err) => {
        console.log('Caller GetCaller error, error.code: ' + JSON.stringify(err.code) +
          ' error.message: ' + JSON.stringify(err.message));
      });
    }
  }
  ```

## Caller.off

off(type: 'release'): void;

Deregisters a callback that is invoked when the stub on the target UIAbility is disconnected. This capability is reserved.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **release**.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**
    
  ```ts
  let caller;
  export default class MainUIAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      this.context.startAbilityByCall({
        bundleName: 'com.example.myservice',
        abilityName: 'MainUIAbility',
        deviceId: ''
      }).then((obj) => {
          caller = obj;
          try {
            let onReleaseCallBack = (str) => {
                console.log(' Caller OnRelease CallBack is called ' + str);
            };
            caller.on('release', onReleaseCallBack);
            caller.off('release');
          } catch (error) {  
            console.error('Caller.on or Caller.off catch error, error.code: ' + JSON.stringify(error.code) +
              ' error.message: ' + JSON.stringify(error.message));
          }
      }).catch((err) => {
        console.error('Caller GetCaller error, error.code: ' + JSON.stringify(err.code) +
          ' error.message: ' + JSON.stringify(err.message));
      });
    }
  }
  ```

## Callee

Implements callbacks for caller notification registration and deregistration.

## Callee.on

on(method: string, callback: CalleeCallback): void;

Registers a caller notification callback, which is invoked when the target UIAbility registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two UIAbilities.| 
  | callback | [CalleeCallback](#calleecallback) | Yes| JS notification synchronization callback of the [rpc.MessageSequence](js-apis-rpc.md#messagesequence9) type. The callback must return at least one empty [rpc.Parcelable](js-apis-rpc.md#parcelable9) object. Otherwise, the function execution fails.|
 
**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  class MyMessageAble{
      name:''
      str:''
      num: 1
      constructor(name, str) {
        this.name = name;
        this.str = str;
      }
      marshalling(messageSequence) {
          messageSequence.writeInt(this.num);
          messageSequence.writeString(this.str);
          console.log('MyMessageAble marshalling num[' + this.num + '] str[' + this.str + ']');
          return true;
      }
      unmarshalling(messageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          console.log('MyMessageAble unmarshalling num[' + this.num + '] str[' + this.str + ']');
          return true;
      }
  };
  let method = 'call_Function';
  function funcCallBack(pdata) {
      console.log('Callee funcCallBack is called ' + pdata);
      let msg = new MyMessageAble('test', '');
      pdata.readParcelable(msg);
      return new MyMessageAble('test1', 'Callee test');
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

Deregisters a caller notification callback, which is invoked when the target UIAbility registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Registered notification message string.| 

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).


**Example**
    
  ```ts
  import Ability from '@ohos.app.ability.UIAbility';
  let method = 'call_Function';
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

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Readable| Writable| Type| Description| 
| -------- | -------- | -------- | -------- | -------- |
| (msg: string) | Yes| No| function | Prototype of the listener function registered by the caller.| 

## CalleeCallback

(indata: rpc.MessageSequence): rpc.Parcelable;

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Readable| Writable| Type| Description| 
| -------- | -------- | -------- | -------- | -------- |
| (indata: [rpc.MessageSequence](js-apis-rpc.md#messagesequence9)) | Yes| No| [rpc.Parcelable](js-apis-rpc.md#parcelable9) | Prototype of the listener function registered by the callee.|
