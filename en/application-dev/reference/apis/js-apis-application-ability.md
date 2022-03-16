# Ability

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Manages the ability lifecycle and context.


## Modules to Import

  
```
import Ability from '@ohos.application.Ability';
```


## Attributes

  | Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| context | [AbilityContext](js-apis-ability-context.md) | Yes| No| Context of an ability.| 
| launchWant | [Want](js-apis-featureAbility.md#Want)| Yes| No| Parameters for starting the ability.| 
| lastRequestWant | [Want](js-apis-featureAbility.md#Want)| Yes| No| Parameters used when the ability was started last time.| 


## onCreate

onCreate(want: Want, param: LaunchParam): void

Called to initialize the service logic when an ability is created.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information related to this ability, including the ability name and bundle name.| 
  | param | LaunchParam | Yes| Parameters for starting the ability, and the reason for the last abnormal exit.| 

- Example
    
  ```
  class myAbility extends Ability {
      onCreate(want, param) {
          console.log('onCreate, want:' + want.abilityName);
      }
  }
  ```


## onWindowStageCreate

onWindowStageCreate(windowStage: window.WindowStage): void

Called when a **WindowStage** is created for this ability.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | windowStage | window.WindowStage | Yes| **WindowStage** information.| 

- Example
    
  ```
  class myAbility extends Ability {
      onWindowStageCreate(windowStage) {
          console.log('onWindowStageCreate');
      }
  }
  ```


## onWindowStageDestroy

onWindowStageDestroy(): void

Called when the **WindowStage** is destroyed for this ability.

- Example
    
  ```
  class myAbility extends Ability {
      onWindowStageDestroy() {
          console.log('onWindowStageDestroy');
      }
  }
  ```


## onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

Called when the **WindowStage** is restored during the migration of this ability, which is a multi-instance ability.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | windowStage | window.WindowStage | Yes| **WindowStage** information.| 

- Example
    
  ```
  class myAbility extends Ability {
      onWindowStageRestore(windowStage) {
          console.log('onWindowStageRestore');
      }
  }
  ```


## onDestroy

onDestroy(): void;

Called when this ability is destroyed to clear resources.

- Example
    
  ```
  class myAbility extends Ability {
      onDestroy() {
          console.log('onDestroy');
      }
  }
  ```


## onForeground

onForeground(): void;

Called when this ability is running in the foreground.

- Example
    
  ```
  class myAbility extends Ability {
      onForeground() {
          console.log('onForeground');
      }
  }
  ```


## onBackground

onBackground(): void;

Callback when this ability is switched to the background.

- Example
    
  ```
  class myAbility extends Ability {
      onBackground() {
          console.log('onBackground');
      }
  }
  ```


## onContinue

onContinue(wantParam : {[key: string]: any}): boolean;

Called to save data during the ability migration preparation process.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | wantParam | {[key:&nbsp;string]:&nbsp;any} | Yes| **want** parameter.| 

- Return value
    | Type| Description| 
  | -------- | -------- |
  | boolean | Returns **true** if the migration is accepted; returns **false** otherwise.| 

- Example
    
  ```
  class myAbility extends Ability {
      onContinue(wantParams) {
          console.log('onContinue');
          wantParams["myData"] = "my1234567";
          return true;
      }
  }
  ```


## onNewWant

onNewWant(want: Want): void;

Called when the ability startup mode is set to singleton.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Want parameters, such as the ability name and bundle name.| 

- Example
    
  ```
  class myAbility extends Ability {
      onNewWant(want) {
          console.log('onNewWant, want:' + want.abilityName);
      }
  }
  ```


## onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

Called when the configuration of the environment where the ability is running is updated.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | config | [Configuration](#section188911144124715) | Yes| New configuration.| 

- Example
    
  ```
  class myAbility extends Ability {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, config:' + JSON.stringify(config));
      }
  }
  ```


## Caller

Implements sending of sequenceable data to the target ability when an ability (caller) invokes the target ability (callee).


### call

call(method, data: rpc.Sequenceable): Promise&lt;void&gt;;

Sends sequenceable data to the target ability.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two abilities. The message is used to instruct the callee to register a function to receive the sequenceable data.| 
  | data | rpc.Sequenceable | Yes| Sequenceable data. You need to customize the data.| 

- Return value
    | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return a response.| 

- Example
    
  ```
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{ // Custom sequenceable data structure
      num: 0
      str: ''
      constructor() {}
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
          caller = await this.context.startAbilityByCall({
              bundleName: "com.example.myservice",
              abilityName: "com.example.myservice.MainAbility",
              deviceId: ""
          });
          let msg = new MyMessageAble(1, "world"); // See the definition of Sequenceable.
          caller.call(method, msg)
          .then(() => {
              console.log('Caller call() called');
          }).catch((e) => {
              console.log('Caller call() catch error ' + e);
          });
      }
  }
  ```


### callWithResult

callWithResult(method, data: rpc.Sequenceable): Promise&lt;rpc.MessageParcel&gt;;

Sends sequenceable data to the target ability and obtains the sequenceable data returned by the target ability.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two abilities. The message is used to instruct the callee to register a function to receive the sequenceable data.| 
  | data | rpc.Sequenceable | Yes| Sequenceable data. You need to customize the data.| 

- Return value
    | Type| Description| 
  | -------- | -------- |
  | Promise&lt;rpc.MessageParcel&gt; | Promise used to return the sequenceable data from the target ability.| 

- Example
    
  ```
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{
      num: 0
      str: ''
      constructor() {}
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
          caller = await this.context.startAbilityByCall({
              bundleName: "com.example.myservice",
              abilityName: "com.example.myservice.MainAbility",
              deviceId: ""
           });
          let msg = new MyMessageAble(1, "world");
          caller.callWithResult(method, msg)
          .then((data) => {
              console.log('Caller call() called');
              let retmsg = new MyMessageAble(0, "");
              data.readSequenceable(retmsg);
          }).catch((e) => {
              console.log('Caller call() catch error ' + e);
          });
      }
  }
  ```


### release

release(): void;

Releases the caller interface of the target ability.

- Example
    
  ```
  import Ability from '@ohos.application.Ability';
  var caller;
  export default class MainAbility extends Ability {
      onWindowStageCreate(windowStage) {
          caller = await this.context.startAbilityByCall({
                  bundleName: "com.example.myservice",
                  abilityName: "com.example.myservice.MainAbility",
                  deviceId: ""
              });
          try {
              caller.release();
          } catch (e) {
              console.log('Caller Release error ' + e);
          }
      }
  }
  ```


### onRelease

onRelease(callback: function): void;

Registers a callback that is invoked when the Stub on the target ability is disconnected.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | function | Yes| Callback used for the **onRelease** method.| 

- Example
    
  ```
  import Ability from '@ohos.application.Ability';
  var caller;
  export default class MainAbility extends Ability {
      onWindowStageCreate(windowStage) {
          caller = await this.context.startAbilityByCall({
              bundleName: "com.example.myservice",
              abilityName: "com.example.myservice.MainAbility",
              deviceId: ""
          });
          try {
              caller.onRelease((str) => {
                  console.log(' Caller OnRelease CallBack is called ' + str);
              });
          } catch (e) {
              console.log('Caller Release error ' + e);
          }
      }
  }
  ```


## Callee

Implements callbacks for caller notification registration and unregistration.


### on

on(method: string, callback: function): void;

Registers a caller notification callback, which is invoked when the target ability registers a function.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Notification message string negotiated between the two abilities.| 
  | callback | function | Yes| JS notification synchronization callback of the **rpc.MessageParcel** type. The callback must return at least one empty **rpc.Sequenceable** object. Otherwise, the function execution fails.| 

- Example
    
  ```
  import Ability from '@ohos.application.Ability';
  class MyMessageAble{
      num: 0
      str: ''
      constructor() {}
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


### off

off(method: string): void;

Unregisters a caller notification callback, which is invoked when the target ability registers a function.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | method | string | Yes| Registered notification message string.| 

- Example
    
  ```
  import Ability from '@ohos.application.Ability';
  var method = 'call_Function';
  export default class MainAbility extends Ability {
      onCreate(want, launchParam) {
          console.log('Callee onCreate is called');
          this.callee.off(method);
      }
  }
  ```
