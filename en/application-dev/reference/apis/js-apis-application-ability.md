# Ability

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Manages the ability lifecycle and context.


## Modules to Import

  
```
import Ability from '@ohos.application.Ability';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| context | [AbilityContext](js-apis-ability-context.md) | Yes| No| Context of an ability.| 
| launchWant | [Want](js-apis-featureAbility.md#Want)| Yes| No| Parameters for starting the ability.| 
| lastRequestWant | [Want](js-apis-featureAbility.md#Want)| Yes| No| Parameters used when the ability was started last time.| 


## Ability.onCreate

onCreate(want: Want, param: AbilityConstant.LaunchParam): void;

Called to initialize the service logic when an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information related to this ability, including the ability name and bundle name.| 
  | param | AbilityConstant.LaunchParam | Yes| Parameters for starting the ability, and the reason for the last abnormal exit.| 

**Example**
    
  ```js
  class myAbility extends Ability {
      onCreate(want, param) {
          console.log('onCreate, want:' + want.abilityName);
      }
  }
  ```


## Ability.onWindowStageCreate

onWindowStageCreate(windowStage: window.WindowStage): void

Called when a **WindowStage** is created for this ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | windowStage | window.WindowStage | Yes| **WindowStage** information.| 

**Example**
    
  ```js
  class myAbility extends Ability {
      onWindowStageCreate(windowStage) {
          console.log('onWindowStageCreate');
      }
  }
  ```


## Ability.onWindowStageDestroy

onWindowStageDestroy(): void

Called when the **WindowStage** is destroyed for this ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**
    
  ```js
  class myAbility extends Ability {
      onWindowStageDestroy() {
          console.log('onWindowStageDestroy');
      }
  }
  ```


## Ability.onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

Called when the **WindowStage** is restored during the migration of this ability, which is a multi-instance ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | windowStage | window.WindowStage | Yes| **WindowStage** information.| 

**Example**
    
  ```js
  class myAbility extends Ability {
      onWindowStageRestore(windowStage) {
          console.log('onWindowStageRestore');
      }
  }
  ```


## Ability.onDestroy

onDestroy(): void;

Called when this ability is destroyed to clear resources.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**
    
  ```js
  class myAbility extends Ability {
      onDestroy() {
          console.log('onDestroy');
      }
  }
  ```


## Ability.onForeground

onForeground(): void;

Called when this ability is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**
    
  ```js
  class myAbility extends Ability {
      onForeground() {
          console.log('onForeground');
      }
  }
  ```


## Ability.onBackground

onBackground(): void;

Called when this ability is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**
    
  ```js
  class myAbility extends Ability {
      onBackground() {
          console.log('onBackground');
      }
  }
  ```


## Ability.onContinue

onContinue(wantParam : {[key: string]: any}): AbilityConstant.OnContinueResult;

Called to save data during the ability migration preparation process.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | wantParam | {[key:&nbsp;string]:&nbsp;any} | Yes| **want** parameter.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | AbilityConstant.OnContinueResult | Continuation result.| 

**Example**
    
  ```js
  class myAbility extends Ability {
      onContinue(wantParams) {
          console.log('onContinue');
          wantParams["myData"] = "my1234567";
          return true;
      }
  }
  ```


## Ability.onNewWant

onNewWant(want: Want): void;

Called when the ability startup mode is set to singleton.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Want parameters, such as the ability name and bundle name.| 

**Example**
    
  ```js
  class myAbility extends Ability {
      onNewWant(want) {
          console.log('onNewWant, want:' + want.abilityName);
      }
  }
  ```


## Ability.onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

Called when the configuration of the environment where the ability is running is updated.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | config | [Configuration](js-apis-configuration.md) | Yes| New configuration.| 

**Example**
    
  ```js
  class myAbility extends Ability {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, config:' + JSON.stringify(config));
      }
  }
  ```


## Caller

Implements sending of sequenceable data to the target ability when an ability (caller) invokes the target ability (callee).


## Caller.call

call(method: string, data: rpc.Sequenceable): Promise&lt;void&gt;;

Sends sequenceable data to the target ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two abilities. The message is used to instruct the callee to register a function to receive the sequenceable data.| 
  | data | rpc.Sequenceable | Yes| Sequenceable data. You need to customize the data.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return a response.| 

**Example**
    
  ```js
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{ // Custom sequenceable data structure
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
  var method = 'call_Function'; // Notification message string negotiated by the two abilities
  var caller;
  export default class MainAbility extends Ability {
      onWindowStageCreate(windowStage) {
        this.context.startAbilityByCall({
            bundleName: "com.example.myservice",
            abilityName: "com.example.myservice.MainAbility",
            deviceId: ""
        }).then((obj) => {
            caller = obj;
            let msg = new MyMessageAble(1, "world"); // See the definition of Sequenceable.
            caller.call(method, msg)
                .then(() => {
                    console.log('Caller call() called');
                }).catch((e) => {
                console.log('Caller call() catch error ' + e);
            });
            console.log('Caller GetCaller Get ' + caller);
        }).catch((e) => {
            console.log('Caller GetCaller error ' + e);
        });
      }
      
  }
  ```


## Caller.callWithResult

callWithResult(method: string, data: rpc.Sequenceable): Promise&lt;rpc.MessageParcel&gt;;

Sends sequenceable data to the target ability and obtains the sequenceable data returned by the target ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two abilities. The message is used to instruct the callee to register a function to receive the sequenceable data.| 
  | data | rpc.Sequenceable | Yes| Sequenceable data. You need to customize the data.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;rpc.MessageParcel&gt; | Promise used to return the sequenceable data from the target ability.| 

**Example**
    
  ```js
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{
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
            abilityName: "com.example.myservice.MainAbility",
            deviceId: ""
        }).then((obj) => {
            caller = obj;
            let msg = new MyMessageAble(1, "world");
            caller.callWithResult(method, msg)
                .then((data) => {
                    console.log('Caller callWithResult() called');
                    let retmsg = new MyMessageAble(0, "");
                    data.readSequenceable(retmsg);
                }).catch((e) => {
                console.log('Caller callWithResult() catch error ' + e);
            });
            console.log('Caller GetCaller Get ' + caller);
        }).catch((e) => {
            console.log('Caller GetCaller error ' + e);
        });
      }
  }
  ```


## Caller.release

release(): void;

Releases the caller interface of the target ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**
    
  ```js
  import Ability from '@ohos.application.Ability';
  var caller;
  export default class MainAbility extends Ability {
      onWindowStageCreate(windowStage) {
        this.context.startAbilityByCall({
            bundleName: "com.example.myservice",
            abilityName: "com.example.myservice.MainAbility",
            deviceId: ""
        }).then((obj) => {
            caller = obj;
            try {
                caller.release();
            } catch (e) {
                console.log('Caller Release error ' + e);
            }
            console.log('Caller GetCaller Get ' + caller);
        }).catch((e) => {
            console.log('Caller GetCaller error ' + e);
        });
      }
  }
  ```


## Caller.onRelease

onRelease(callback: OnReleaseCallBack): void;

Registers a callback that is invoked when the Stub on the target ability is disconnected.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | OnReleaseCallBack | Yes| Callback used for the **onRelease** API.| 

**Example**
    
  ```js
  import Ability from '@ohos.application.Ability';
  var caller;
  export default class MainAbility extends Ability {
      onWindowStageCreate(windowStage) {
        this.context.startAbilityByCall({
            bundleName: "com.example.myservice",
            abilityName: "com.example.myservice.MainAbility",
            deviceId: ""
        }).then((obj) => {
            caller = obj;
            try {
                caller.onRelease((str) => {
                    console.log(' Caller OnRelease CallBack is called ' + str);
                });
            } catch (e) {
                console.log('Caller Release error ' + e);
            }
            console.log('Caller GetCaller Get ' + caller);
        }).catch((e) => {
            console.log('Caller GetCaller error ' + e);
        });
      }
  }
  ```


## Callee

Implements callbacks for caller notification registration and deregistration.


## Callee.on

on(method: string, callback: CaleeCallBack): void;

Registers a caller notification callback, which is invoked when the target ability registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two abilities.| 
  | callback | CaleeCallBack | Yes| JS notification synchronization callback of the **rpc.MessageParcel** type. The callback must return at least one empty **rpc.Sequenceable** object. Otherwise, the function execution fails.| 

**Example**
    
  ```js
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{
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
      let msg = new MyMessageAble(0, "");
      pdata.readSequenceable(msg);
      return new MyMessageAble(10, "Callee test");
  }
  export default class MainAbility extends Ability {
      onCreate(want, launchParam) {
          console.log('Callee onCreate is called');
          this.callee.on(method, funcCallBack);
      }
  }
  ```


## Callee.off

off(method: string): void;

Deregisters a caller notification callback, which is invoked when the target ability registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Registered notification message string.| 

**Example**
    
  ```js
  import Ability from '@ohos.application.Ability';
  var method = 'call_Function';
  export default class MainAbility extends Ability {
      onCreate(want, launchParam) {
          console.log('Callee onCreate is called');
          this.callee.off(method);
      }
  }
  ```

## OnReleaseCallBack

(msg: string): void;

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| (msg: string) | function | Yes| No| Prototype of the listener function interface registered by the caller.| 
 

 ## CaleeCallBack

(indata: rpc.MessageParcel): rpc.Sequenceable;

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| (indata: rpc.MessageParcel) | rpc.Sequenceable | Yes| No| Prototype of the message listener function interface registered by the callee.| 
