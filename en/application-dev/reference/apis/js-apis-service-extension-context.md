# ServiceExtensionContext

The **ServiceExtensionContext** module, inherited from **ExtensionContext**, provides context for Service Extension abilities.

You can use the APIs of this module to start, terminate, connect, and disconnect abilities.

> **NOTE**
> 
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Usage

Before using the **ServiceExtensionContext** module, you must define a child class that inherits from **ServiceExtensionAbility**.

```js
  import ServiceExtensionAbility from '@ohos.application.ServiceExtensionAbility';
  class MainAbility extends ServiceExtensionAbility {
      onCreate() {
          let context = this.context;
      }
  }
```

## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md)  | Yes| Information about the target ability, such as the ability name and bundle name.| 
  | callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result.| 

**Example**

  ```js
    let want = {
      "bundleName": "com.example.myapp",
      "abilityName": "MyAbility"};
      this.context.startAbility(want, (err) => {
      console.log('startAbility result:' + JSON.stringify(err));
    });
  ```

## startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>;

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md)  | Yes| Information about the target ability, such as the ability name and bundle name.| 
  | options | [StartOptions](js-apis-application-StartOptions.md) | Yes| Parameters used for starting the ability.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 

**Example**

  ```js
    let want = {
        "bundleName": "com.example.myapp",
        "abilityName": "MyAbility"
    };
    this.context.startAbility(want).then((data) => {
        console.log('success:' + JSON.stringify(data));
    }).catch((error) => {
        console.log('failed:' + JSON.stringify(error));
    });

  ```

## startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

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

## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result.

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


## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result.

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


## ServiceExtensionContext.startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>;

Starts an ability with the account ID specified. This API uses a promise to return the result.

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
  | Promise&lt;void&gt; | Promise used to return the result.| 

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
    .then((data) => {
        console.log('---------- startAbilityWithAccount success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
    })
  ```

## ServiceExtensionContext.startServiceExtensionAbility

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

## ServiceExtensionContext.startServiceExtensionAbility

startServiceExtensionAbility(want: Want): Promise\<void>;

Starts a new Service Extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|

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
  this.context.startServiceExtensionAbility(want)
    .then((data) => {
        console.log('---------- startServiceExtensionAbility success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- startServiceExtensionAbility fail, err:  -----------', err);
    })
  ```

## ServiceExtensionContext.startServiceExtensionAbilityWithAccount

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

## ServiceExtensionContext.startServiceExtensionAbilityWithAccount

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
  var accountId = 100;
  this.context.startServiceExtensionAbilityWithAccount(want,accountId)
    .then((data) => {
        console.log('---------- startServiceExtensionAbilityWithAccount success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- startServiceExtensionAbilityWithAccount fail, err:  -----------', err);
    })
  ```

## ServiceExtensionContext.stopServiceExtensionAbility

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

## ServiceExtensionContext.stopServiceExtensionAbility

stopServiceExtensionAbility(want: Want): Promise\<void>;

Stops a Service Extension ability in the same application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|

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
  this.context.stopServiceExtensionAbility(want)
    .then((data) => {
        console.log('---------- stopServiceExtensionAbility success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- stopServiceExtensionAbility fail, err:  -----------', err);
    })
  ```

## ServiceExtensionContext.stopServiceExtensionAbilityWithAccount

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

## ServiceExtensionContext.stopServiceExtensionAbilityWithAccount

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
  var accountId = 100;
  this.context.stopServiceExtensionAbilityWithAccount(want,accountId)
    .then((data) => {
        console.log('---------- stopServiceExtensionAbilityWithAccount success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- stopServiceExtensionAbilityWithAccount fail, err:  -----------', err);
    })
  ```

## ServiceExtensionContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result.| 

**Example**

  ```js
  this.context.terminateSelf((err) => {
    console.log('terminateSelf result:' + JSON.stringify(err));
  });
  ```

## ServiceExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 

**Example**

  ```js
  this.context.terminateSelf().then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```

## ServiceExtensionContext.connectAbility

connectAbility(want: Want, options: ConnectOptions): number;

Connects this ability to a Service ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md)  | Yes| Information about the target ability, such as the ability name and bundle name.| 
  | options | [ConnectOptions](js-apis-featureAbility.md#connectoptions) | Yes| Callback used to return the information indicating that the connection is successful, interrupted, or failed.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | number | A number, based on which the connection will be interrupted.| 

**Example**

  ```js
  let want = {
    "bundleName": "com.example.myapp",
    "abilityName": "MyAbility"
  };
  let options = {
    onConnect(elementName, remote) { console.log('----------- onConnect -----------') },
    onDisconnect(elementName) { console.log('----------- onDisconnect -----------') },
    onFailed(code) { console.log('----------- onFailed -----------') }
  }
  let connection = this.context.connectAbility(want,options);
  ```

## ServiceExtensionContext.connectAbilityWithAccount

connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;

Uses the **AbilityInfo.AbilityType.SERVICE** template and account ID to connect this ability to another ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the target ability.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess).|
| options | ConnectOptions | No| Remote object instance.|

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

## ServiceExtensionContext.disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback&lt;void&gt;): void;

Disconnects this ability from the Service ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | connection | number | Yes| Number returned after **connectAbility** is called.| 
  | callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result.| 

**Example**

  ```js
    let connection=1
    this.context.disconnectAbility(connection, (err) => { 
        // connection is the return value of connectAbility.
        console.log('terminateSelf result:' + JSON.stringify(err));
    });
  ```

## ServiceExtensionContext.disconnectAbility

disconnectAbility(connection: number): Promise&lt;void&gt;;

Disconnects this ability from the Service ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | connection | number | Yes| Number returned after **connectAbility** is called.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 
 
**Example**

  ```js
  let connection=1
  this.context.disconnectAbility(connection).then((data) => { 
      // connection is the return value of connectAbility.
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```

## ServiceExtensionContext.startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;;

Starts an ability in the foreground or background and obtains the caller object for communicating with the ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

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
        console.log('GetCaller Success');
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
  
