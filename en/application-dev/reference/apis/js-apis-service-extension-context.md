# ServiceExtensionContext

The **ServiceExtensionContext** module, inherited from **ExtensionContext**, provides context for Service Extension abilities.

You can use the APIs of this module to start, terminate, connection, and disconnect abilities.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                 | Type                                                         | Readable | Writable | Description                    |
| -------------------- | ------------------------------------------------------------ | -------- | -------- | ------------------------------ |
| extensionAbilityInfo | [ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md) | Yes      | No       | Extension ability information. |

## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | Yes| Information about the ability to start, such as the ability name and bundle name.|
| callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
  class MainAbility extends ExtensionContext {
      onWindowStageCreate(windowStage) {
          let want = {
              "bundleName": "com.example.myapp",
              "abilityName": "MyAbility"};
          this.context.startAbility(want, (err) => {
          console.log('startAbility result:' + JSON.stringify(err));
          });
      }
  }

  ```

## startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>;

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | Yes| Information about the ability to start, such as the ability name and bundle name.|
| options | [StartOptions](js-apis-application-StartOptions.md) | Yes| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
    import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
    class MainAbility extends ExtensionContext {
        onWindowStageCreate(windowStage) {
            let want = {
            "bundleName": "com.example.myapp",
            "abilityName": "MyAbility"
            };
        this.context.startAbility(want).then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(error));
        });
        }
    }
  ```

## startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | Yes| Information about the **Want** used for starting an ability.|
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

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void\>): void;

Starts an ability with the account ID specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number | Yes| ID of the account.|
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
| want | [Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number | Yes| ID of the account.|
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

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void\>;

Starts an ability with the account ID specified. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number | Yes| ID of the account.|
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
    .then((data) => {
        console.log('---------- startAbilityWithAccount success, data:  -----------', data);
    })
    .catch((err) => {
        console.log('---------- startAbilityWithAccount fail, err:  -----------', err);
    })
  ```


## ServiceExtensionContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
    import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
        class MainAbility extends ExtensionContext {
            onWindowStageCreate(windowStage) {
            this.context.terminateSelf((err) => {
              console.log('terminateSelf result:' + JSON.stringify(err));
            });
            }
        }
  

  ```

## ServiceExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
    import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
    class MainAbility extends ExtensionContext {
    onWindowStageCreate(windowStage) {
      this.context.terminateSelf().then((data) => {
        console.log('success:' + JSON.stringify(data));
      }).catch((error) => {
        console.log('failed:' + JSON.stringify(error));
      });
    }
}

  ```

## ServiceExtensionContext.connectAbility

connectAbility(want: Want, options: ConnectOptions): number;

Connects this ability to a Service ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | Yes| Information about the ability to connect to, such as the ability name and bundle name.|
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
      onConnect: function(elementName, proxy) {},
      onDisConnect: function(elementName) {},
      onFailed: function(code) {}
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
| want | [Want](js-apis-application-Want.md) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number | Yes| ID of the account.|
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

Disconnects this ability from the Service ability. This API uses a callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| Number returned after **connectAbility** is called.|
| callback | AsyncCallback&lt;void&gt; | No| Callback used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
    class MainAbility extends ExtensionContext {
    onWindowStageCreate(windowStage) {
      let connection=1
      this.context.disconnectAbility(connection, (err) => { 
        // connection is the return value of connectAbility.
        console.log('terminateSelf result:' + JSON.stringify(err));
      });
    }
  }

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
| Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
  class MainAbility extends ExtensionContext {
    onWindowStageCreate(windowStage) {
      let connection=1
      this.context.disconnectAbility(connection).then((data) => { // connection is the return value of connectAbility.
      console.log('success:' + JSON.stringify(data));
      }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
      });
    }
  }

  ```
