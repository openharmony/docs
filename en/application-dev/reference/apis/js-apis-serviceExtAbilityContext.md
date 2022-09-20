# ServiceExtAbilityContext


> **NOTE**
>
> The initial APIs of this module are supported since API version 9. API version 9 is a canary version for trial use. The APIs of this version may be unstable.


## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| extensionAbilityInfo | ExtensionAbilityInfo | Yes| No| Extension ability information. |


## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.|
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
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
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
| want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.|
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

## startAbilityWithAccount

startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>): void

Starts an ability based on an account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.|
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

Starts an ability based on an account and **options**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want) | Yes| Information about the **Want** used for starting an ability.|
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

Starts an ability based on an account and **options**. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.|
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

## terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

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

## terminateSelf

terminateSelf(): Promise&lt;void&gt;

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
this.context.terminateSelf(want).then((data) => {
    console.log('success:' + JSON.stringify(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringify(error));
});
```


## connectAbility

connectAbility(want: Want, options: ConnectOptions): number

Uses the **AbilityInfo.AbilityType.SERVICE** template to connect this ability to another ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.|
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
| want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the **Want** used for starting an ability.|
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
  console.log('disconnected successfully')
}).catch((err) => {
  console.log('disconnected failed')
})
```
