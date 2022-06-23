# Ability Context

> **NOTE**
> The initial APIs of this module are supported since API version 9. API version 9 is a canary version for trial use. The APIs of this version may be unstable.

Implements the ability context. This module is inherited from **Context**.

# Modules to Import

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

| Name                 | Type       | Readable   | Writable   | Description                                |
| --------------------- | --------------- | ------ | ------- | ----------------------------------- |
| config                | Configuration   | Yes    | No     | Configuration.                     |
| abilityInfo           | AbilityInfo   | Yes    | No     | Ability information.                 |
| currentHapModuleInfo  | HapModuleInfo   | Yes    | No     | Information about the current HAP.                   |


## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
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

## startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability with **options** specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want)  | Yes| Information about the **Want** used for starting an ability.|
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


## startAbility

startAbility(want: Want, options: StartOptions): Promise&lt;void&gt;

Starts an ability with **options** specified. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| options | StartOptions | Yes| Parameters used for starting the ability.|

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

## startAbilityByCall

startAbilityByCall(want: Want): Promise&lt;Caller&gt;

Obtains the caller interface of the specified ability, and if the specified ability is not started, starts the ability in the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the ability to start, including the ability name, bundle name, and device ID. If the device ID is left blank or the default value is used, the local ability will be started.|

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
            console.log('Caller GetCaller Get ' + call);
        }).catch((e) => {
            console.log('Caller GetCaller error ' + e);
        });
    }
}
```

## startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void

Starts an ability with **accountId** specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number                   | Yes| Account ID.                  |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
};
var accountId = 11;
this.context.startAbility(want, accountId, (error) => {
    console.log("error.code = " + error.code)
})
```

## startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void

Starts an ability with **accountId** and **options** specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want)  | Yes| Information about the **Want** used for starting an ability.|
| accountId | number                   | Yes| Account ID.                  |
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
var accountId = 11;
this.context.startAbility(want, accountId, options, (error) => {
    console.log("error.code = " + error.code)
})
```


## startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<void>

Starts an ability with **accountId** and **options** specified. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number                   | Yes| Account ID.                  |
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
var accountId = 11;
this.context.startAbility(want, accountId, options)
.then((data) => {
    console.log('Operation successful.')
}).catch((error) => {
    console.log('Operation failed.');
})
```

## startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | Yes| Callback used to return the result.|

**Example**

```js
this.context.startAbilityForResult(
    {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"},
    (error, result) => {
      console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
      console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
    }
);
```

## startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void

Starts an ability with **options** specified. This API uses an asynchronous callback to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| options | StartOptions | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | Yes| Callback used to return the result.|

**Example**

```js
var options = {
  windowMode: 0,
};
this.context.startAbilityForResult(
    {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, options,
    (error, result) => {
      console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
      console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
    }
);
```


## startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions): Promise&lt;AbilityResult&gt;;

Starts an ability with **options** specified. This API uses a promise to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| options | StartOptions | Yes| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | Promise used to return the result.|

**Example**
```js
var options = {
  windowMode: 0,
};
this.context.startAbilityForResult({bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, options).then((result) => {
    console.log("startAbilityForResult Promise.resolve is called, result.resultCode = " + result.resultCode)
}, (error) => {
    console.log("startAbilityForResult Promise.Reject is called, error.code = " + error.code)
})
```

## startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>): void

Starts an ability with **accountId** specified. This API uses an asynchronous callback to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number                   | Yes| Account ID.                  |
| callback | AsyncCallback&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | Yes| Callback used to return the result.|

**Example**

```js
var accountId = 111;
this.context.startAbilityForResult(
    {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"},
    accountId, 
    (error, result) => {
      console.log("startAbilityForResult AsyncCallback is called, error.code = " + error.code)
      console.log("startAbilityForResult AsyncCallback is called, result.resultCode = " + result.resultCode)
    }
);
```

## startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>): void

Starts an ability with **accountId** and **options** specified. This API uses an asynchronous callback to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number                   | Yes| Account ID.                  |
| options | StartOptions | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```js
var options = {
  windowMode: 0,
};
var accountId = 111;
this.context.startAbilityForResult(
    {bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, 
    accountId, 
    options,
    () => {
      console.log("startAbilityForResult AsyncCallback is called")
    }
);
```

## startAbilityForResultWithAccount

startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise\<AbilityResult>;

Starts an ability with **accountId** and **options** specified. This API uses a promise to return the result when the ability is terminated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number                   | Yes| Account ID.                  |
| options | StartOptions | Yes| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-featureAbility.md#AbilityResult)&gt; | Promise used to return the result.|

**Example**

```js
var accountId = 111;
var options = {
  windowMode: 0,
};
this.context.startAbilityForResult({bundleName: "com.extreme.myapplication", abilityName: "MainAbilityDemo2"}, accountId, options).then((result) => {
    console.log("startAbilityForResult Promise.resolve is called, result.resultCode = " + result.resultCode)
}, (error) => {
    console.log("startAbilityForResult Promise.Reject is called, error.code = " + error.code)
})
```

## terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

Terminates this ability. This API uses an asynchronous callback to return the result.

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

## terminateSelf

terminateSelf(): Promise&lt;void&gt;

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

## terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void

Terminates this ability. This API uses an asynchronous callback to return the information to the caller of **startAbilityForResult**.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-featureAbility.md#AbilityResult) | Yes| Information returned to the caller.|
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


## terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;

Terminates this ability. This API uses a promise to return information to the caller of **startAbilityForResult**.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-featureAbility.md#AbilityResult) | Yes| Information returned to the caller.|

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
})
```

## connectAbility

connectAbility(want: Want, options: ConnectOptions): number

Uses the **AbilityInfo.AbilityType.SERVICE** template to connect this ability to another ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| options | ConnectOptions | Yes| Connection channel.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | ID of the connection between the two abilities.|

**Example**
```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
}
var options = {
  onConnect: (elementName, remote) => {
    console.log('connectAbility onConnect, elementName: ' + elementName + ', remote: ' remote)
  },
  onDisconnect: (elementName) => {
    console.log('connectAbility onDisconnect, elementName: ' + elementName)
  },
  onFailed: (code) => {
    console.log('connectAbility onFailed, code: ' + code)
  }
}
this.context.connectAbility(want, options) {
  console.log('code: ' + code)
}
```

## connectAbilityWithAccount

connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number

Uses the **AbilityInfo.AbilityType.SERVICE** template to connect this ability to another ability based on an account.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
| accountId | number | Yes| Account ID.|
| options | ConnectOptions | Yes| Connection channel.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | ID of the connection between the two abilities.|

**Example**
```js
var want = {
  "deviceId": "",
  "bundleName": "com.extreme.test",
  "abilityName": "com.extreme.test.MainAbility"
}
var accountId = 111;
var options = {
  onConnect: (elementName, remote) => {
    console.log('connectAbility onConnect, elementName: ' + elementName + ', remote: ' remote)
  },
  onDisconnect: (elementName) => {
    console.log('connectAbility onDisconnect, elementName: ' + elementName)
  },
  onFailed: (code) => {
    console.log('connectAbility onFailed, code: ' + code)
  }
}
this.context.connectAbility(want, accountId, options) {
  console.log('code: ' + code)
}
```

## disconnectAbility

disconnectAbility(connection: number, callback:AsyncCallback\<void>): void

Disconnects this ability from another ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| ID of the connection to be disconnected.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```js
var connection = 111;
this.context.disconnectAbility(connection, () => {
  console.log('disconnection')
})
```

## disconnectAbility

disconnectAbility(connection: number): Promise\<void>

Disconnects this ability from another ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| connection | number | Yes| ID of the connection to be disconnected.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
var connection = 111;
this.context.disconnectAbility(connection).then(() => {
  console.log('disconnect success')
}).catch((err) => {
  console.log('disconnect failed')
})
```

## setMissionLabel

setMissionLabel(label: string, callback:AsyncCallback&lt;void&gt;): void

Sets the label of the ability in the mission. This API uses an asynchronous callback to return the result.

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


## setMissionLabel

setMissionLabel(label: string): Promise\<void>

Sets the label of the ability in the mission. This API uses a promise to return the result.

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

## requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void

Requests permissions from end users in the form of a dialog box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| Permissions to request.|
| callback | AsyncCallback&lt;PermissionRequestResult&gt; | Yes| Callback used to return the result indicating whether the API is successfully called.|

**Example**
    
```js
this.context.requestPermissionsFromUser(permissions,(result) => {
    console.log('requestPermissionsFromUserresult:' + JSON.stringify(result));
});
```


## requestPermissionsFromUser

requestPermissionsFromUser(permissions: Array&lt;string&gt;) : Promise&lt;PermissionRequestResult&gt;

Requests permissions from end users in the form of a dialog box. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| Permissions to request.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;PermissionRequestResult&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**
    
```js
this.context.requestPermissionsFromUser(permissions).then((data) => {
    console.log('success:' + JSON.stringify(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringify(error));
});
```

## restoreWindowStage

restoreWindowStage(contentStorage: ContentStorage) : void

Restores the window stage data during ability continuation.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| contentStorage | ContentStorage | Yes| Window stage data to restore.|

**Example**

```js
var contentStorage = {
  "link": 'link',
};
this.context.restoreWindowStage(contentStorage);
```
