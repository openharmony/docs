# AbilityContext

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Implements the ability context. This module is inherited from **Context**.


## Attributes

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| abilityInfo | AbilityInfo | Yes| No| Ability information.| 
| currentHapModuleInfo | HapModuleInfo | Yes| No| Information about the current HAP.| 


## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.| 
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.| 

- Example
  ```
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "com.extreme.test.MainAbility"
  };
  this.context.startAbility(want, (error) => {
      console.log("error.code = " + error.code)
  })
  ```


## startAbility

startAbility(want: Want): Promise&lt;void&gt;;

Starts an ability. This method uses a promise to return the result.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.| 

- Return value
  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 

- Example
  ```
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "com.extreme.test.MainAbility"
  };
  this.context.startAbility(want)
  .then((data) => {
      console.log('Operation successful.')
  }).catch((error) => {
      console.log('Operation failed.');
  })
  ```


## startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability. This method uses a callback to return the execution result when the ability is terminated.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | want |[Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.|
  | callback | Callback&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | Yes| Callback used to return the result.|


- Example
  ```
  this.context.startAbilityForResult(
      {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"},
      (error, result) => {
          console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
          console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
       }
  );
  ```


## startAbilityForResult

startAbilityForResult(want: Want): Promise&lt;AbilityResult&gt;;

Starts an ability. This method uses a promise to return the execution result when the ability is terminated.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.| 

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[AbilityResult](js-apis-featureAbility.md#abilityresult)&gt; | Promise used to return the result.|

- Example
  ```
  this.context.startAbilityForResult({bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}).then((result) => {
      console.log("startAbilityForResult Promise.resolve is called, result.resultCode = " + result.resultCode)
  }, (error) => {
      console.log("startAbilityForResult Promise.Reject is called, error.code = " + error.code)
  })
  ```


## terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result indicating whether the method is successfully called.| 

- Example
  ```
  this.context.terminateSelf((err) => {
      console.log('terminateSelf result:' + JSON.stringfy(err);
  }
  ```


## terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this ability. This method uses a promise to return the result.

- Return value
  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the method is successfully called.| 

- Example
  ```
  this.context.terminateSelf(want).then((data) => {
      console.log('success:' + JSON.stringfy(data));
  )).catch((error) => {
      console.log('failed:' + JSON.stringfy(error));
  });
  ```


## terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This method uses a callback to return the information to the caller of **startAbilityForResult**.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | Yes| Information returned to the caller.|
  | callback | Callback&lt;void&gt; | No| Callback used to return the information.|

- Example
  ```
  this.context.terminateSelfWithResult(
     {
          want: {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo"},
          resultCode: 100
      }, (error) => {
          console.log("terminateSelfWithResult is called = " + error.code)
      }
  );
  ```


## terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

Terminates this ability. This method uses a promise to return information to the caller of **startAbilityForResult**.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | Yes| Information returned to the caller.|

- Return value
  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 

- Example
  ```
  this.context.terminateSelfWithResult(
  {
      want: {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo"},
      resultCode: 100
  }).then((result) => {
      console.log("terminateSelfWithResult")
  }
  )
  ```
