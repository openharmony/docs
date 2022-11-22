# AbilityContext

The **AbilityContext** module, inherited from **Context**, implements the context for abilities.

This module provides APIs for accessing ability-specific resources. You can use the APIs to start and terminate an ability, obtain the caller interface, and request permissions from users by displaying a dialog box.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Usage

Before using the **AbilityContext** module, you must define a child class that inherits from **Ability**.

```js
import Ability from '@ohos.application.Ability';
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
| config | [Configuration](js-apis-configuration.md) | Yes| No| Configuration information.|

## AbilityContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "MainAbility"
  };
  this.context.startAbility(want, (error) => {
      console.log("error.code = " + error.code)
  })
  ```


## AbilityContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability with the start options specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | Yes| Information about the target ability.|
| options | [StartOptions](js-apis-application-StartOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "MainAbility"
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
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| options | [StartOptions](js-apis-application-StartOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "MainAbility"
  };
  var options = {
  	windowMode: 0,
  };
  this.context.startAbility(want, options)
  .then(() => {
      console.log('Operation successful.')
  }).catch((error) => {
      console.log('Operation failed.');
  })
  ```


## AbilityContext.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
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

Starts an ability with start options specified. This API uses an asynchronous callback to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| options | [StartOptions](js-apis-application-StartOptions.md) | Yes| Parameters used for starting the ability.|
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

Starts an ability. This API uses a promise to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| options | [StartOptions](js-apis-application-StartOptions.md) | No| Parameters used for starting the ability.|


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

## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void;

Starts an ability. This API uses an asynchronous callback to return the result when the account of the ability is destroyed.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<AbilityResult\> | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startAbilityWithAccount(want, accountId, (err, data) => {
    console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
    console.log('---------- startAbilityWithAccount success, data:  -----------', data);
  });
  ```


## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with start options specified. This API uses an asynchronous callback to return the result when the account of the ability is destroyed.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-application-StartOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityForResultWithAccount(want, accountId, options, (err) => {
    console.log('---------- startAbilityForResultWithAccount fail, err:  -----------', err);
  });
  ```


## AbilityContext.startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult\>;

Starts an ability with start options specified. This API uses a promise to return the result when the account of the ability is destroyed.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-application-StartOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;AbilityResult&gt; | Promise used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityForResultWithAccount(want, accountId, options)
    .then((data) => {
        console.log('---------- startAbilityForResultWithAccount success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- startAbilityForResultWithAccount fail, err:  -----------', err);
    })
  ```
## AbilityContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

Starts a new Service Extension ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  this.context.startServiceExtensionAbility(want, (err) => {
    console.log('---------- startServiceExtensionAbility fail, err:  -----------', err);
  });
  ```

## AbilityContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want): Promise\<void>;

Starts a new Service Extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  this.context.startServiceExtensionAbility(want)
    .then(() => {
        console.log('---------- startServiceExtensionAbility success -----------');
    })
    .catch((err) => {
        console.log('---------- startServiceExtensionAbility fail, err:  -----------', err);
    })
  ```
## AbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Starts a new Service Extension ability with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startServiceExtensionAbilityWithAccount(want,accountId, (err) => {
    console.log('---------- startServiceExtensionAbilityWithAccount fail, err:  -----------', err);
  });
  ```

## AbilityContext.startServiceExtensionAbilityWithAccount

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Starts a new Service Extension ability with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startServiceExtensionAbilityWithAccount(want,accountId)
    .then(() => {
        console.log('---------- startServiceExtensionAbilityWithAccount success -----------');
    })
    .catch((err) => {
        console.log('---------- startServiceExtensionAbilityWithAccount fail, err:  -----------', err);
    })
  ```
## AbilityContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want, callback: AsyncCallback\<void>): void;

Stops a Service Extension ability in the same application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  this.context.stopServiceExtensionAbility(want, (err) => {
    console.log('---------- stopServiceExtensionAbility fail, err:  -----------', err);
  });
  ```

## AbilityContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want): Promise\<void>;

Stops a Service Extension ability in the same application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  this.context.stopServiceExtensionAbility(want)
    .then(() => {
        console.log('---------- stopServiceExtensionAbility success -----------');
    })
    .catch((err) => {
        console.log('---------- stopServiceExtensionAbility fail, err:  -----------', err);
    })
  ```

## AbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Stops a Service Extension ability in the same application with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.stopServiceExtensionAbilityWithAccount(want,accountId, (err) => {
    console.log('---------- stopServiceExtensionAbilityWithAccount fail, err:  -----------', err);
  });
  ```

## AbilityContext.stopServiceExtensionAbilityWithAccount

stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>;

Stops a Service Extension ability in the same application with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.stopServiceExtensionAbilityWithAccount(want,accountId)
    .then(() => {
        console.log('---------- stopServiceExtensionAbilityWithAccount success -----------');
    })
    .catch((err) => {
        console.log('---------- stopServiceExtensionAbilityWithAccount fail, err:  -----------', err);
    })
  ```

## AbilityContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

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
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  this.context.terminateSelf().then(() => {
      console.log('success');
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```


## AbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses an asynchronous callback to return the ability result information. It is used together with **startAbilityForResult**.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-featureAbility.md#abilityresult) | Yes| Information returned to the caller.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "bundleName": "com.extreme.myapplication",
    "abilityName": "SecondAbility"
  }
  var resultCode = 100;
  // AbilityResult information returned to the caller.
  var abilityResult = {
    want,
    resultCode
  }
  this.context.terminateSelfWithResult(abilityResult, (error) => {
          console.log("terminateSelfWithResult is called = " + error.code)
      }
  );
  ```


## AbilityContext.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return the ability result information. It is used together with **startAbilityForResult**.

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
  var want = {
    "bundleName": "com.extreme.myapplication",
    "abilityName": "SecondAbility"
  }
  var resultCode = 100;
  // AbilityResult information returned to the caller.
  var abilityResult = {
    want,
    resultCode
  }
  this.context.terminateSelfWithResult(abilityResult).then((result) => {
      console.log("terminateSelfWithResult")
  }
  )
  ```

## AbilityContext.connectAbility

connectAbility(want: Want, options: ConnectOptions): number;

Uses the **AbilityInfo.AbilityType.SERVICE** template to connect this ability to another ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| options | [ConnectOptions](js-apis-featureAbility.md#connectoptions) | No| Parameters for the connection.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the ability connection.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }
  const result = this.context.connectAbility(want, options);
  console.log('----------- connectAbilityResult: ------------', result);
  ```


## AbilityContext.connectAbilityWithAccount

connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

Uses the **AbilityInfo.AbilityType.SERVICE** template and account ID to connect this ability to another ability with the account ID specified.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [ConnectOptions](js-apis-featureAbility.md#connectoptions) | No| Parameters for the connection.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Result code of the ability connection.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }
  const result = this.context.connectAbilityWithAccount(want, accountId, options);
  console.log('----------- connectAbilityResult: ------------', result);
  ```

## AbilityContext.disconnectAbility

disconnectAbility(connection: number): Promise\<void>;

Disconnects a connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Result code of the ability connection.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Example**

  ```js
  var connectionNumber = 0;
  this.context.disconnectAbility(connectionNumber).then(() => {
       console.log('disconnectAbility success');
  }).catch((err) => {
       console.log('disconnectAbility fail, err: ', err);
  });
  ```

## AbilityContext.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void;

Disconnects a connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Result code of the ability connection.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

  ```js
    var connectionNumber = 0;
    this.context.disconnectAbility(connectionNumber, (err) => {
       console.log('---------- disconnectAbility fail, err: -----------', err);
    });
  ```

## AbilityContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

Starts an ability in the foreground or background and obtains the caller object for communicating with the ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the ability to start, including **abilityName**, **moduleName**, **bundleName**, **deviceId** (optional), and **parameters** (optional). If **deviceId** is left blank or null, the local ability is started. If **parameters** is left blank or null, the ability is started in the background.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Caller&gt; | Promise used to return the caller object to communicate with.|

**Example**

  ```js
  let caller = undefined;

  // Start an ability in the background by not passing parameters.
  var wantBackground = {
      bundleName: "com.example.myservice",
      moduleName: "entry",
      abilityName: "MainAbility",
      deviceId: ""
  };
  this.context.startAbilityByCall(wantBackground)
    .then((obj) => {
        caller = obj;
        console.log('GetCaller success');
    }).catch((error) => {
        console.log(`GetCaller failed with ${error}`);
    });

  // Start an ability in the foreground with ohos.aafwk.param.callAbilityToForeground in parameters set to true.
  var wantForeground = {
      bundleName: "com.example.myservice",
      moduleName: "entry",
      abilityName: "MainAbility",
      deviceId: "",
      parameters: {
        "ohos.aafwk.param.callAbilityToForeground": true
      }
  };
  this.context.startAbilityByCall(wantForeground)
    .then((obj) => {
        caller = obj;
        console.log('GetCaller success');
    }).catch((error) => {
        console.log(`GetCaller failed with ${error}`);
    });
  ```

## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  this.context.startAbilityWithAccount(want, accountId, (err) => {
    console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
  });
  ```


## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID and start options specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-application-StartOptions.md) | No| Parameters used for starting the ability.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityWithAccount(want, accountId, options, (err) => {
    console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
  });
  ```


## AbilityContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void\>;

Starts an ability with the account ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | [StartOptions](js-apis-application-StartOptions.md) | No| Parameters used for starting the ability.|

**Example**

  ```js
  var want = {
    "deviceId": "",
    "bundleName": "com.extreme.test",
    "abilityName": "MainAbility"
  };
  var accountId = 100;
  var options = {
    windowMode: 0,
  };
  this.context.startAbilityWithAccount(want, accountId, options)
    .then(() => {
        console.log('---------- startAbilityWithAccount success -----------');
    })
    .catch((err) => {
        console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
    })
  ```

## AbilityContext.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void;

Requests permissions from the user by displaying a dialog box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| Permissions to request.|
| callback | AsyncCallback&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
       var permissions=['com.example.permission']
       this.context.requestPermissionsFromUser(permissions,(result) => {
       console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });

  ```


## AbilityContext.requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;) : Promise&lt;PermissionRequestResult&gt;;

Requests permissions from the user by displaying a dialog box. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| Permissions to request.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | Promise used to return the result.|

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

Sets a label for this ability in the mission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Label of the ability to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  this.context.setMissionLabel("test",(result) => {
      console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
  });
  ```


## AbilityContext.setMissionLabel

setMissionLabel(label: string): Promise&lt;void&gt;;

Sets a label for this ability in the mission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| label | string | Yes| Label of the ability to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  this.context.setMissionLabel("test").then(() => {
      console.log('success');
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```
## AbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap, callback:AsyncCallback\<void>): void;

Sets an icon for this ability in the mission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | Yes| Icon of the ability to set.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

  ```js
    import image from '@ohos.multimedia.image';
    var imagePixelMap;
    var color = new ArrayBuffer(0);
    var initializationOptions = {
       size: {
           height: 100,
           width: 100
       }
    };
    image.createPixelMap(color, initializationOptions)
       .then((data) => {
           imagePixelMap = data;
       })
       .catch((err) => {
           console.log('--------- createPixelMap fail, err: ---------', err)
       });
    this.context.setMissionIcon(imagePixelMap, (err) => {
       console.log('---------- setMissionIcon fail, err: -----------', err);
    })
  ```


## AbilityContext.setMissionIcon

setMissionIcon(icon: image.PixelMap): Promise\<void>;

Sets an icon for this ability in the mission. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | image.PixelMap | Yes| Icon of the ability to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
    import image from '@ohos.multimedia.image';
    var imagePixelMap;
    var color = new ArrayBuffer(0);
    var initializationOptions = {
      size: {
          height: 100,
          width: 100
      }
    };
    image.createPixelMap(color, initializationOptions)
      .then((data) => {
          imagePixelMap = data;
      })
      .catch((err) => {
          console.log('--------- createPixelMap fail, err: ---------', err)
      });
    this.context.setMissionIcon(imagePixelMap)
      .then(() => {
          console.log('-------------- setMissionIcon success -------------');
      })
      .catch((err) => {
          console.log('-------------- setMissionIcon fail, err: -------------', err);
      });
  ```
## AbilityContext.restoreWindowStage

restoreWindowStage(localStorage: LocalStorage) : void;

Restores the window stage data for this ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| localStorage | image.LocalStorage | Yes| Storage used to store the restored window stage.|

**Example**

  ```js
    var storage = new LocalStorage();
    this.context.restoreWindowStage(storage);
  ```

## AbilityContext.isTerminating

isTerminating(): boolean;

Checks whether this ability is in the terminating state.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| boolean| The value **true** means that the ability is in the terminating state, and **false** means the opposite.|

**Example**

  ```js
  var isTerminating = this.context.isTerminating();
  console.log('ability state :' + isTerminating);
  ```
