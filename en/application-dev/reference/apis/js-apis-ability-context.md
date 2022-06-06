# AbilityContext

> **NOTE**<br/>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Implements the ability context. This module is inherited from **Context**.

## Modules to Import

```js
import Ability from '@ohos.application.Ability'
```
## Usage

Before using the **AbilityContext** module, you must define a child class that inherits from **Ability**.

```js
import Ability from '@ohos.application.Ability'
class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let context = this.context;
    }
}
```


## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | AbilityInfo | Yes| No| Ability information.| 
| currentHapModuleInfo | HapModuleInfo | Yes| No| Information about the current HAP.| 


## AbilityContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.| 
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.| 

**Example**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "com.extreme.test.MainAbility"
  };
  this.context.startAbility(want, (error) => {
      console.log("error.code = " + error.code)
  })
  ```


## AbilityContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md)  | Yes| Information about the **Want** used for starting an ability.| 
  | options | StartOptions | Yes| Parameters used for starting the ability.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.| 

**Example**
    
  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "com.extreme.test.MainAbility"
  };
  var options = {
  	windowMode: 0,
  };
  this.context.startAbility(want, options, (error) => {
      console.log("error.code = " + error.code)
  })
  ```


## AbilityContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.| 
  | options | StartOptions | No| Parameters used for starting the ability.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 

**Example**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "com.extreme.test.MainAbility"
  };
  var options = {
  	windowMode: 0,
  };
  this.context.startAbility(want, options)
  .then((data) => {
      console.log('Operation successful.')
  }).catch((error) => {
      console.log('Operation failed.');
  })
  ```


## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability. This API uses a callback to return the execution result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | want |[Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.|
  | callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | Yes| Callback used to return the result.|


**Example**

  ```js
  this.context.startAbilityForResult(
      {deviceId: "", bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"},
      (error, result) => {
          console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
          console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
       }
  );
  ```

## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability. This API uses a callback to return the execution result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | want |[Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.|
  | options | StartOptions | Yes| Parameters used for starting the ability.|
  | callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | Yes| Callback used to return the result.|


**Example**

  ```js
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityForResult(
      {deviceId: "", bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, options,
      (error, result) => {
          console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
          console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
       }
  );
  ```


## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

Starts an ability. This API uses a promise to return the execution result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.|
  | options | StartOptions | No| Parameters used for starting the ability.|


**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | Promise used to return the result.|

**Example**

  ```js
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityForResult({deviceId: "", bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, options).then((result) => {
      console.log("startAbilityForResult Promise.resolve is called, result.resultCode = " + result.resultCode)
  }, (error) => {
      console.log("startAbilityForResult Promise.Reject is called, error.code = " + error.code)
  })
  ```


## AbilityContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result indicating whether the API is successfully called.| 

**Example**

  ```js
  this.context.terminateSelf((err) => {
      console.log('terminateSelf result:' + JSON.stringify(err));
  });
  ```


## AbilityContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.| 

**Example**

  ```js
  this.context.terminateSelf(want).then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```


## AbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses a callback to return the information to the caller of **startAbilityForResult**.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | Yes| Information returned to the caller.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  this.context.terminateSelfWithResult(
     {
          want: {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo"},
          resultCode: 100
      }, (error) => {
          console.log("terminateSelfWithResult is called = " + error.code)
      }
  );
  ```


## AbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return information to the caller of **startAbilityForResult**.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | Yes| Information returned to the caller.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 

**Example**

  ```js
  this.context.terminateSelfWithResult(
  {
      want: {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo"},
      resultCode: 100
  }).then((result) => {
      console.log("terminateSelfWithResult")
  }
  )
  ```


## AbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

Obtains the caller interface of the specified ability, and if the specified ability is not started, starts the ability in the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md) | Yes| Information about the ability to start, including the ability name, bundle name, and device ID. If the device ID is left blank or the default value is used, the local ability will be started.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;Caller&gt; | Promise used to return the caller object to communicate with.| 

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
              console.log('Caller GetCaller Get ' + caller);
          }).catch((e) => {
              console.log('Caller GetCaller error ' + e);
          });
      }
  }
  ```


## AbilityContext.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void;

Requests permissions from the user by displaying a pop-up window. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | permissions | Array&lt;string&gt; | Yes| Permissions to request.| 
  | callback | AsyncCallback&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | Yes| Callback used to return the result indicating whether the API is successfully called.| 

**Example**
    
  ```js
       var permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions,(result) => {
       console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });
  
  ```


## AbilityContext.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;) : Promise&lt;PermissionRequestResult&gt;;

Requests permissions from the user by displaying a pop-up window. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | permissions | Array&lt;string&gt; | Yes| Permissions to request.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | Promise used to return the result indicating whether the API is successfully called.| 

**Example**
    
  ```js
   var permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions).then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });

  ```


## AbilityContext.setMissionLabel

setMissionLabel(label: string, callback:AsyncCallback&lt;void&gt;): void;

Sets the label of the ability displayed in the task. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | label | string | Yes| Label of the ability to set.| 
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result indicating whether the API is successfully called.| 

**Example**
    
  ```js
  this.context.setMissionLabel("test",(result) => {
      console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });
  ```


## AbilityContext.setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;

Sets the label of the ability displayed in the task. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | label | string | Yes| Label of the ability to set.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.| 

**Example**
    
  ```js
  this.context.setMissionLabel("test").then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```
