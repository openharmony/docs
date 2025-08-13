# @ohos.continuation.continuationManager (Continuation/Collaboration Management)

The continuationManager module provides the continuation/collaboration management entry. You can use the APIs of this module to connect to and cancel the continuation/collaboration management service, subscribe to and unsubscribe from device connection events, start the device selection module, and update the device connection state.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { continuationManager } from '@kit.AbilityKit';
```

## continuationManager.register<sup>(deprecated)</sup>

register(callback: AsyncCallback\<number>): void

Registers the continuation management service and obtains a token. This API does not involve any filter parameters and uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [registerContinuation](#continuationmanagerregistercontinuation9) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback\<number> | Yes| Callback used to return the token generated after the continuation management service is connected.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = -1;
  continuationManager.register((err, data) => {
    if (err.code != 0) {
      console.error('register failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('register finished, ' + JSON.stringify(data));
    token = data;
  });
  ```

## continuationManager.register<sup>(deprecated)</sup>

register(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void

Registers the continuation management service and obtains a token. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [registerContinuation](#continuationmanagerregistercontinuation9-1) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | Yes| Extra parameters used to filter the list of available devices.|
  | callback | AsyncCallback\<number> | Yes| Callback used to return the token generated after the continuation management service is connected.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = -1;
  continuationManager.register(
    {
      deviceType: ["00E"]
    },
    (err, data) => {
      if (err.code != 0) {
        console.error('register failed, cause: ' + JSON.stringify(err));
        return;
      }
      console.info('register finished, ' + JSON.stringify(data));
      token = data;
  });
  ```

## continuationManager.register<sup>(deprecated)</sup>

register(options?: ContinuationExtraParams): Promise\<number>

Registers the continuation management service and obtains a token. This API uses a promise to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [registerContinuation](#continuationmanagerregistercontinuation9-2) instead.

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

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let token: number = -1;
  continuationManager.register(
    { deviceType: ["00E"] }).then((data) => {
      console.info('register finished, ' + JSON.stringify(data));
      token = data;
    }).catch((err: BusinessError) => {
      console.error('register failed, cause: ' + JSON.stringify(err));
  });
  ```

## continuationManager.registerContinuation<sup>9+</sup>

registerContinuation(callback: AsyncCallback\<number>): void

Registers the continuation management service and obtains a token. This API does not involve any filter parameters and uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback\<number> | Yes| Callback used to return the token generated after the continuation management service is connected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600003 | The number of token registration times has reached the upper limit. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  
  let token: number = -1;
  try {
    continuationManager.registerContinuation((err, data) => {
      if (err.code != 0) {
        console.error('registerContinuation failed, cause: ' + JSON.stringify(err));
        return;
      }
      console.info('registerContinuation finished, ' + JSON.stringify(data));
      token = data;
    });
  } catch (err) {
    console.error('registerContinuation failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.registerContinuation<sup>9+</sup>

registerContinuation(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void

Registers the continuation management service and obtains a token. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | Yes| Extra parameters used to filter the list of available devices.|
  | callback | AsyncCallback\<number> | Yes| Callback used to return the token generated after the continuation management service is connected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600003 | The number of token registration times has reached the upper limit. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = -1;
  try {
    continuationManager.registerContinuation(
      {
        deviceType: ["00E"]
      },
      (err, data) => {
        if (err.code != 0) {
          console.error('registerContinuation failed, cause: ' + JSON.stringify(err));
          return;
        }
        console.info('registerContinuation finished, ' + JSON.stringify(data));
        token = data;
    });
  } catch (err) {
    console.error('registerContinuation failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.registerContinuation<sup>9+</sup>

registerContinuation(options?: ContinuationExtraParams): Promise\<number>

Registers the continuation management service and obtains a token. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | No| Extra parameters used to filter the list of available devices. This parameter can be null.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<number> | Promise used to return the token generated after the continuation management service is connected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600003 | The number of token registration times has reached the upper limit. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let token: number = -1;
  try {
    continuationManager.registerContinuation(
      {
        deviceType: ["00E"]
      }).then((data) => {
        console.info('registerContinuation finished, ' + JSON.stringify(data));
        token = data;
      }).catch((err: BusinessError) => {
        console.error('registerContinuation failed, cause: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('registerContinuation failed, cause: ' + JSON.stringify(err));
  }
  ```


## continuationManager.on('deviceConnect')<sup>(deprecated)</sup>

on(type: 'deviceConnect', callback: Callback\<ContinuationResult>): void

Subscribes to device connection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [on](#continuationmanagerondeviceselected9) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceConnect**.|
  | callback | Callback\<[ContinuationResult](js-apis-continuation-continuationResult.md)> | Yes| Callback invoked when a device is selected from the device list provided by the device selection module. This callback returns the device ID, type, and name.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  continuationManager.on("deviceConnect", (data) => {
    console.info('onDeviceConnect deviceId: ' + JSON.stringify(data.id));
    console.info('onDeviceConnect deviceType: ' + JSON.stringify(data.type));
    console.info('onDeviceConnect deviceName: ' + JSON.stringify(data.name));
  });
  ```

## continuationManager.on('deviceDisconnect')<sup>(deprecated)</sup>

on(type: 'deviceDisconnect', callback: Callback\<string>): void

Subscribes to device disconnection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [on](#continuationmanagerondeviceunselected9) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceDisconnect**.|
  | callback | Callback\<string> | Yes| Callback invoked when a device is unselected from the device list provided by the device selection module. This callback returns the device ID.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  continuationManager.on("deviceDisconnect", (data) => {
    console.info('onDeviceDisconnect deviceId: ' + JSON.stringify(data));
  });
  ```

## continuationManager.off('deviceConnect')<sup>(deprecated)</sup>

off(type: 'deviceConnect', callback?: Callback\<ContinuationResult>): void

Unsubscribes from device connection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [off](#continuationmanageroffdeviceselected9) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceConnect**.|
  | callback | Callback\<[ContinuationResult](js-apis-continuation-continuationResult.md)> | No| Callback invoked when a device is selected from the device list provided by the device selection module. This callback returns the device ID, type, and name.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  continuationManager.off("deviceConnect", (data) => {
    console.info('onDeviceConnect deviceId: ' + JSON.stringify(data.id));
    console.info('onDeviceConnect deviceType: ' + JSON.stringify(data.type));
    console.info('onDeviceConnect deviceName: ' + JSON.stringify(data.name));
  });
  ```

## continuationManager.off('deviceDisconnect')<sup>(deprecated)</sup>

off(type: 'deviceDisconnect', callback?: Callback\<string>): void

Unsubscribes from device disconnection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [off](#continuationmanageroffdeviceunselected9) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceDisconnect**.|
  | callback | Callback\<string> | No| Callback invoked when a device is unselected from the device list provided by the device selection module. This callback returns the device ID.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  continuationManager.off("deviceDisconnect", (data) => {
    console.info('onDeviceDisconnect deviceId: ' + JSON.stringify(data));
  });
  ```

## continuationManager.on('deviceSelected')<sup>9+</sup>

on(type: 'deviceSelected', token: number, callback: Callback\<Array\<ContinuationResult>>): void

Subscribes to device connection events. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceSelected**.|
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | Callback\<Array\<[ContinuationResult](js-apis-continuation-continuationResult.md)>> | Yes| Callback invoked when a device is selected from the device list provided by the device selection module. This callback returns the device ID, type, and name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |
| 16600004 | The specified callback has been registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  try {
    continuationManager.on("deviceSelected", token, (data) => {
      console.info('onDeviceSelected len: ' + data.length);
      for (let i = 0; i < data.length; i++) {
        console.info('onDeviceSelected deviceId: ' + JSON.stringify(data[i].id));
        console.info('onDeviceSelected deviceType: ' + JSON.stringify(data[i].type));
        console.info('onDeviceSelected deviceName: ' + JSON.stringify(data[i].name));
      }
    });
  } catch (err) {
    console.error('on failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.on('deviceUnselected')<sup>9+</sup>

on(type: 'deviceUnselected', token: number, callback: Callback\<Array\<ContinuationResult>>): void

Subscribes to device disconnection events. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceUnselected**.|
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | Callback\<Array\<[ContinuationResult](js-apis-continuation-continuationResult.md)>> | Yes| Callback invoked when a device is unselected from the device list provided by the device selection module. This callback returns the device ID, type, and name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |
| 16600004 | The specified callback has been registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  try {
    continuationManager.on("deviceUnselected", token, (data) => {
      console.info('onDeviceUnselected len: ' + data.length);
      for (let i = 0; i < data.length; i++) {
        console.info('onDeviceUnselected deviceId: ' + JSON.stringify(data[i].id));
        console.info('onDeviceUnselected deviceType: ' + JSON.stringify(data[i].type));
        console.info('onDeviceUnselected deviceName: ' + JSON.stringify(data[i].name));
      }
      console.info('onDeviceUnselected finished.');
    });
  } catch (err) {
    console.error('on failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.off('deviceSelected')<sup>9+</sup>

off(type: 'deviceSelected', token: number): void

Unsubscribes from device connection events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceSelected**.|
  | token | number | Yes| Token obtained after the registration of the continuation management service.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |
| 16600004 | The specified callback has been registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  try {
    continuationManager.off("deviceSelected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.off('deviceUnselected')<sup>9+</sup>

off(type: 'deviceUnselected', token: number): void

Unsubscribes from device disconnection events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is fixed at **deviceUnselected**.|
  | token | number | Yes| Token obtained after the registration of the continuation management service.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |
| 16600004 | The specified callback has been registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  try {
    continuationManager.off("deviceUnselected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.startDeviceManager<sup>(deprecated)</sup>

startDeviceManager(token: number, callback: AsyncCallback\<void>): void

Starts the device selection module to show the list of available devices on the network. This API does not involve any filter parameters and uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [startContinuationDeviceManager](#continuationmanagerstartcontinuationdevicemanager9) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the module is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  continuationManager.startDeviceManager(token, (err) => {
    if (err.code != 0) {
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('startDeviceManager finished. ');
  });
  ```

## continuationManager.startDeviceManager<sup>(deprecated)</sup>

startDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void

Starts the device selection module to show the list of available devices on the network. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [startContinuationDeviceManager](#continuationmanagerstartcontinuationdevicemanager9-1) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | Yes| Extra parameters used to filter the list of available devices.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the module is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  continuationManager.startDeviceManager(
    token,
    {
      deviceType: ["00E"]
    },
    (err) => {
      if (err.code != 0) {
        console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
        return;
      }
      console.info('startDeviceManager finished. ');
  });
  ```

## continuationManager.startDeviceManager<sup>(deprecated)</sup>

startDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>

Starts the device selection module to show the list of available devices on the network. This API uses a promise to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [startContinuationDeviceManager](#continuationmanagerstartcontinuationdevicemanager9-2) instead.

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

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let token: number = -1;
  continuationManager.startDeviceManager(
    token,
    {
      deviceType: ["00E"]
    }).then(() => {
      console.info('startDeviceManager finished. ');
    }).catch((err: BusinessError) => {
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
  });
  ```

## continuationManager.startContinuationDeviceManager<sup>9+</sup>

startContinuationDeviceManager(token: number, callback: AsyncCallback\<void>): void

Starts the device selection module to show the list of available devices on the network. This API does not involve any filter parameters and uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the module is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = -1;
  try {
    continuationManager.startContinuationDeviceManager(token, (err) => {
      if (err.code != 0) {
        console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
        return;
      }
      console.info('startContinuationDeviceManager finished. ');
    });
  } catch (err) {
    console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.startContinuationDeviceManager<sup>9+</sup>

startContinuationDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void

Starts the device selection module to show the list of available devices on the network. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | Yes| Extra parameters used to filter the list of available devices.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the module is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = -1;
  try {
    continuationManager.startContinuationDeviceManager(
      token,
      {
        deviceType: ["00E"]
      },
      (err) => {
        if (err.code != 0) {
          console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
          return;
        }
        console.info('startContinuationDeviceManager finished. ');
    });
  } catch (err) {
    console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.startContinuationDeviceManager<sup>9+</sup>

startContinuationDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>

Starts the device selection module to show the list of available devices on the network. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let token: number = -1;
  try {
    continuationManager.startContinuationDeviceManager(
      token,
      {
        deviceType: ["00E"]
      }).then(() => {
        console.info('startContinuationDeviceManager finished. ');
      }).catch((err: BusinessError) => {
        console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
      });
  } catch (err) {
    console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.updateConnectStatus<sup>(deprecated)</sup>

updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void

Instructs the device selection module to update the device connection state. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [updateContinuationState](#continuationmanagerupdatecontinuationstate9) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | deviceId | string | Yes| Device ID.|
  | status | [DeviceConnectState](#deviceconnectstate) | Yes| Device connection state.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the state is updated, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = -1;
  let deviceId: string = "test deviceId";
  continuationManager.updateConnectStatus(token, deviceId, continuationManager.DeviceConnectState.CONNECTED, (err) => {
    if (err.code != 0) {
      console.error('updateConnectStatus failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('updateConnectStatus finished. ');
  });
  ```

## continuationManager.updateConnectStatus<sup>(deprecated)</sup>

updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>

Instructs the device selection module to update the device connection state. This API uses a promise to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [updateContinuationState](#continuationmanagerupdatecontinuationstate9-1) instead.

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

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let token: number = 1;
  let deviceId: string = "test deviceId";
  continuationManager.updateConnectStatus(token, deviceId, continuationManager.DeviceConnectState.CONNECTED)
    .then(() => {
      console.info('updateConnectStatus finished. ');
    })
    .catch((err: BusinessError) => {
      console.error('updateConnectStatus failed, cause: ' + JSON.stringify(err));
  });
  ```

## continuationManager.updateContinuationState<sup>9+</sup>

updateContinuationState(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void

Instructs the device selection module to update the device connection state. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | deviceId | string | Yes| Device ID.|
  | status | [DeviceConnectState](#deviceconnectstate) | Yes| Device connection state.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the state is updated, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  let deviceId: string = "test deviceId";
  try {
    continuationManager.updateContinuationState(token, deviceId, continuationManager.DeviceConnectState.CONNECTED, (err) => {
      if (err.code != 0) {
        console.error('updateContinuationState failed, cause: ' + JSON.stringify(err));
        return;
      }
      console.info('updateContinuationState finished. ');
    });
  } catch (err) {
    console.error('updateContinuationState failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.updateContinuationState<sup>9+</sup>

updateContinuationState(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>

Instructs the device selection module to update the device connection state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let token: number = 1;
  let deviceId: string = "test deviceId";
  try {
    continuationManager.updateContinuationState(token, deviceId, continuationManager.DeviceConnectState.CONNECTED)
      .then(() => {
        console.info('updateContinuationState finished. ');
      })
      .catch((err: BusinessError) => {
        console.error('updateContinuationState failed, cause: ' + JSON.stringify(err));
      });
  } catch (err) {
    console.error('updateContinuationState failed, cause: ' + JSON.stringify(err));
  }
  ```


## continuationManager.unregister<sup>(deprecated)</sup>

unregister(token: number, callback: AsyncCallback\<void>): void

Unregisters the continuation management service. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [unregisterContinuation](#continuationmanagerunregistercontinuation9) instead.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the unregistration is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  continuationManager.unregister(token, (err) => {
    if (err.code != 0) {
      console.error('unregister failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('unregister finished. ');
  });
  ```

## continuationManager.unregister<sup>(deprecated)</sup>

unregister(token: number): Promise\<void>

Unregisters the continuation management service. This API uses a promise to return the result.

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [unregisterContinuation](#continuationmanagerunregistercontinuation9-1) instead.

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

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let token: number = 1;
  continuationManager.unregister(token)
    .then(() => {
      console.info('unregister finished. ');
    }).catch((err: BusinessError) => {
      console.error('unregister failed, cause: ' + JSON.stringify(err));
  });
  ```

## continuationManager.unregisterContinuation<sup>9+</sup>

unregisterContinuation(token: number, callback: AsyncCallback\<void>): void

Unregisters the continuation management service. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|
  | callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the unregistration is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';

  let token: number = 1;
  try {
    continuationManager.unregisterContinuation(token, (err) => {
      if (err.code != 0) {
        console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));
        return;
      }
      console.info('unregisterContinuation finished. ');
    });
  } catch (err) {
    console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.unregisterContinuation<sup>9+</sup>

unregisterContinuation(token: number): Promise\<void>

Unregisters the continuation management service. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.DistributedAbilityManager

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | number | Yes| Token obtained after the registration of the continuation management service.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**Example**

  ```ts
  import { continuationManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let token: number = -1;
  try {
    continuationManager.unregisterContinuation(token).then(() => {
        console.info('unregisterContinuation finished. ');
      }).catch((err: BusinessError) => {
        console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));
  }
  ```


## DeviceConnectState

Enumerates the device connection states.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

| Name| Value| Description|
| -------- | -------- | -------- |
| IDLE | 0 | The device is in the initial state.|
| CONNECTING | 1 | The device is being connected.|
| CONNECTED | 2 | The device is connected.|
| DISCONNECTING | 3 | The device is being disconnected.|

## ContinuationMode

Enumerates the continuation modes provided by the device selection module.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

| Name| Value| Description|
| -------- | -------- | -------- |
| COLLABORATION_SINGLE | 0 | Single-choice mode.|
| COLLABORATION_MULTIPLE | 1 | Multi-choice mode.|

## ContinuationResult<sup>10+</sup>

type ContinuationResult = _ContinuationResult

Defines the device information returned by the continuation management entry.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

| Type| Description|
| --- | --- |
| [_ContinuationResult](js-apis-continuation-continuationResult.md) | Device information returned by the continuation management entry.|

## ContinuationExtraParams<sup>10+</sup>

type ContinuationExtraParams = _ContinuationExtraParams

Defines the extra parameters required by the device selection module in the continuation management entry.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.DistributedAbilityManager

| Type| Description|
| --- | --- |
| [_ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | Extra parameters required by the device selection module in the continuation management entry.|
