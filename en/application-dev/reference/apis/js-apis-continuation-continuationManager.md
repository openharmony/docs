# continuationManager

The **continuationManager** module provides the continuation management entry. You can use the APIs of this module to connect to and cancel the continuation management service, subscribe to and unsubscribe from device connection events, start the device selection module, and update the device connection state.

Currently, this module provides incomplete functions, and its APIs are mainly used to start the device selection module. **The continuation capability is not available for application development.**

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import continuationManager from '@ohos.continuation.continuationManager'
```

## continuationManager.register

register(callback: AsyncCallback\<number>): void;

Registers the continuation management service and obtains a token. This API does not involve any filter parameters and uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback\<number> | Yes| Callback used to return the token generated after the continuation management service is connected.|

**Example**

  ```js
  let token = -1;
  continuationManager.register((err, data) => {
    if (err.code != 0) {
      console.error('register failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('register finished, ' + JSON.stringify(data));
    token = data;
  });
  ```

## continuationManager.register

register(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void;

Registers the continuation management service and obtains a token. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | Yes| Extra parameters used to filter the list of available devices.|
  | callback | AsyncCallback\<number> | Yes| Callback used to return the token generated after the continuation management service is connected.|

**Example**

  ```js
  let token = -1;
  let continuationExtraParams = {
    deviceType: ["00E"]
  };
  continuationManager.register(continuationExtraParams, (err, data) => {
    if (err.code != 0) {
      console.error('register failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('register finished, ' + JSON.stringify(data));
    token = data;
  });
  ```

## continuationManager.register

register(options?: ContinuationExtraParams): Promise\<number>;

Registers the continuation management service and obtains a token. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | No| Extra parameters used to filter the list of available devices. This parameter can be null.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<number> | Promise used to return the token generated after the continuation management service is connected.|

**Example**

  ```js
  let token = -1;
  let continuationExtraParams = {
    deviceType: ["00E"]
  };
  continuationManager.register(continuationExtraParams)
    .then((data) => {
      console.info('register finished, ' + JSON.stringify(data));
      token = data;
    })
    .catch((err) => {
      console.error('register failed, cause: ' + JSON.stringify(err));
    });
  ```

## continuationManager.on("deviceConnect")<sup>(deprecated)</sup>

on(type: "deviceConnect", callback: Callback\<ContinuationResult>): void;

Subscribes to device connection events. This API uses an asynchronous callback to return the result.

> This API is deprecated since API version 9. You are advised to use [on](#continuationmanagerondeviceconnect9) instead.

## continuationManager.on("deviceDisconnect")<sup>(deprecated)</sup>

on(type: "deviceDisconnect", callback: Callback\<string>): void;

Subscribes to device disconnection events. This API uses an asynchronous callback to return the result.

> This API is deprecated since API version 9. You are advised to use [on](#continuationmanagerondevicedisconnect9) instead.

## continuationManager.off("deviceConnect")<sup>(deprecated)</sup>

off(type: "deviceConnect", callback?: Callback\<ContinuationResult>): void;

Unsubscribes from device connection events. This API uses an asynchronous callback to return the result.

> This API is deprecated since API version 9. You are advised to use [off](#continuationmanageroffdeviceconnect9) instead.

## continuationManager.off("deviceDisconnect")<sup>(deprecated)</sup>

off(type: "deviceDisconnect", callback?: Callback\<string>): void;

Unsubscribes from device disconnection events. This API uses an asynchronous callback to return the result.

> This API is deprecated since API version 9. You are advised to use [off](#continuationmanageroffdevicedisconnect9) instead.

## continuationManager.on("deviceConnect")<sup>9+</sup>

on(type: "deviceConnect", token: number, callback: Callback\<Array\<ContinuationResult>>): void;

Subscribes to device connection events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceConnect**.|
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | Callback\<Array\<[ContinuationResult](js-apis-continuation-continuationResult.md)>> | Yes| Callback invoked when a device is selected from the device list provided by the device selection module. This callback returns the device ID, type, and name.|

**Example**

  ```js
  let token = 1;
  continuationManager.on("deviceConnect", token, (data) => {
    console.info('onDeviceConnect len: ' + data.length);
    for (let i = 0; i < data.length; i++) {
      console.info('onDeviceConnect deviceId: ' + JSON.stringify(data[i].id));
      console.info('onDeviceConnect deviceType: ' + JSON.stringify(data[i].type));
      console.info('onDeviceConnect deviceName: ' + JSON.stringify(data[i].name));
    }
  });
  ```

## continuationManager.on("deviceDisconnect")<sup>9+</sup>

on(type: "deviceDisconnect", token: number, callback: Callback\<Array\<string>>): void;

Subscribes to device disconnection events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceDisconnect**.|
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | Callback\<Array\<string>> | Yes| Callback invoked when a device is disconnected in the device selection module. This callback returns the device ID.|

**Example**

  ```js
  let token = 1;
  continuationManager.on("deviceDisconnect", token, (data) => {
    console.info('onDeviceDisconnect len: ' + data.length);
    for (let i = 0; i < data.length; i++) {
      console.info('onDeviceDisconnect deviceId: ' + JSON.stringify(data[i]));
    }
    console.info('onDeviceDisconnect finished.');
  });
  ```

## continuationManager.off("deviceConnect")<sup>9+</sup>

off(type: "deviceConnect", token: number): void;

Unsubscribes from device connection events.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceConnect**.|
  | token | number | Yes| Token obtained after the registration of the continuation management service.|

**Example**

  ```js
  let token = 1;
  continuationManager.off("deviceConnect", token);
  ```

## continuationManager.off("deviceDisconnect")<sup>9+</sup>

off(type: "deviceDisconnect", token: number): void;

Unsubscribes from device disconnection events.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceDisconnect**.|
  | token | number | Yes| Token obtained after the registration of the continuation management service.|

**Example**

  ```js
  let token = 1;
  continuationManager.off("deviceDisconnect", token);
  ```

## continuationManager.startDeviceManager

startDeviceManager(token: number, callback: AsyncCallback\<void>): void;

Starts the device selection module to show the list of available devices on the network. This API does not involve any filter parameters and uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

  ```js
  let token = 1;
  continuationManager.startDeviceManager(token, (err, data) => {
    if (err.code != 0) {
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('startDeviceManager finished, ' + JSON.stringify(data));
  });
  ```

## continuationManager.startDeviceManager

startDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void;

Starts the device selection module to show the list of available devices on the network. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | Yes| Extra parameters used to filter the list of available devices.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

  ```js
  let token = 1;
  let continuationExtraParams = {
    deviceType: ["00E"]
  };
  continuationManager.startDeviceManager(token, continuationExtraParams, (err, data) => {
    if (err.code != 0) {
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('startDeviceManager finished, ' + JSON.stringify(data));
  });
  ```

## continuationManager.startDeviceManager

startDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>;

Starts the device selection module to show the list of available devices on the network. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | No| Extra parameters used to filter the list of available devices. This parameter can be null.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

  ```js
  let token = 1;
  let continuationExtraParams = {
    deviceType: ["00E"]
  };
  continuationManager.startDeviceManager(token, continuationExtraParams)
    .then((data) => {
      console.info('startDeviceManager finished, ' + JSON.stringify(data));
    })
    .catch((err) => {
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
    });
  ```

## continuationManager.updateConnectStatus

updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void;

Instructs the device selection module to update the device connection state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | deviceId | string | Yes| Device ID.|
  | status | [DeviceConnectState](#deviceconnectstate) | Yes| Device connection state.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

  ```js
  let token = 1;
  let deviceId: string = "test deviceId";
  continuationManager.updateConnectStatus(token, deviceId, continuationManager.DeviceConnectState.CONNECTED, (err, data) => {
    if (err.code != 0) {
      console.error('updateConnectStatus failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('updateConnectStatus finished, ' + JSON.stringify(data));
  });
  ```

## continuationManager.updateConnectStatus

updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>;

Instructs the device selection module to update the device connection state. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | deviceId | string | Yes| Device ID.|
  | status | [DeviceConnectState](#deviceconnectstate) | Yes| Device connection state.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

  ```js
  let token = 1;
  let deviceId: string = "test deviceId";
  continuationManager.updateConnectStatus(token, deviceId, continuationManager.DeviceConnectState.CONNECTED)
    .then((data) => {
      console.info('updateConnectStatus finished, ' + JSON.stringify(data));
    })
    .catch((err) => {
      console.error('updateConnectStatus failed, cause: ' + JSON.stringify(err));
    });
  ```

## continuationManager.unregister

unregister(token: number, callback: AsyncCallback\<void>): void;

Deregisters the continuation management service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

  ```js
  let token = 1;
  continuationManager.unregister(token, (err, data) => {
    if (err.code != 0) {
      console.error('unregister failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('unregister finished, ' + JSON.stringify(data));
  });
  ```

## continuationManager.unregister

unregister(token: number): Promise\<void>;

Deregisters the continuation management service. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

  ```js
  let token = 1;
  continuationManager.unregister(token)
    .then((data) => {
      console.info('unregister finished, ' + JSON.stringify(data));
    })
    .catch((err) => {
      console.error('unregister failed, cause: ' + JSON.stringify(err));
    });
  ```

## DeviceConnectState

Enumerates the device connection states.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Value| Description|
  | -------- | -------- | -------- | -------- |
  | IDLE | number | 0 | The device is in the initial state.|
  | CONNECTING | number | 1 | The device is being connected.|
  | CONNECTED | number | 2 | The device is connected.|
  | DISCONNECTING | number | 3 | The device is being disconnected.|

## ContinuationMode

Enumerates the continuation modes provided by the device selection module.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Value| Description|
  | -------- | -------- | -------- | -------- |
  | COLLABORATION_SINGLE | number | 0 | Single-choice mode.|
  | COLLABORATION_MULTIPLE | number | 1 | Multi-choice mode.|
