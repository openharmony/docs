# @ohos.cooperate (Screen Hopping) (System API)

The **cooperate** module implements screen hopping for two or more networked devices to share the keyboard and mouse for collaborative operations.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import cooperate from '@ohos.cooperate';
```

## cooperate.prepareCooperate<sup>11+</sup>

prepareCooperate(callback: AsyncCallback&lt;void&gt;): void;

Prepares for screen hopping. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.prepareCooperate((error: BusinessError) => {
    if (error) {
      console.log(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing prepareCooperate success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.prepareCooperate<sup>11+</sup>

prepareCooperate(): Promise&lt;void&gt;;

Prepares for screen hopping. This API uses a promise to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Parameters               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.prepareCooperate().then(() => {
    console.log(`Keyboard mouse crossing prepareCooperate success.`);
  }, (error: BusinessError) => {
    console.log(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.unprepareCooperate<sup>11+</sup>

unprepareCooperate(callback: AsyncCallback&lt;void&gt;): void;

Cancels the preparation for screen hopping. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.unprepareCooperate((error: BusinessError) => {
    if (error) {
      console.log(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing unprepareCooperate success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.unprepareCooperate<sup>11+</sup>

unprepareCooperate(): Promise&lt;void&gt;;

Cancels the preparation for screen hopping. This API uses a promise to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Parameters               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.unprepareCooperate().then(() => {
    console.log(`Keyboard mouse crossing unprepareCooperate success.`);
  }, (error: BusinessError) => {
    console.log(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.activateCooperate<sup>11+</sup>

activateCooperate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void;

Starts screen hopping. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name         | Type                     | Mandatory| Description                                                        |
| --------------- | ------------------------- | ---- | ------------------------------------------------------------ |
| targetNetworkId | string                    | Yes  | Descriptor of the target device for screen hopping.                                    |
| inputDeviceId   | number                    | Yes  | Identifier of the input device for screen hopping.                                      |
| callback        | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 20900001 | Service Exception. Possible causes:  1. A system error, such as null pointer, container-related exception, IPC exception. 2. N-API invocation exception, invalid N-API status. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activateCooperate(targetNetworkId, inputDeviceId, (error: BusinessError) => {
    if (error) {
      console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Start Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.activateCooperate<sup>11+</sup>

activateCooperate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;;

Starts screen hopping. This API uses a promise to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name         | Type  | Mandatory| Description                    |
| --------------- | ------ | ---- | ------------------------ |
| targetNetworkId | string | Yes  | Descriptor of the target device for screen hopping.|
| inputDeviceId   | number | Yes  | Identifier of the input device for screen hopping.  |

**Return value**

| Name             | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 20900001 | Service Exception. Possible causes:  1. A system error, such as null pointer, container-related exception, IPC exception. 2. N-API invocation exception, invalid N-API status. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
 cooperate.activateCooperate(targetNetworkId, inputDeviceId).then(() => {
    console.log(`Start Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.deactivateCooperate<sup>11+</sup>

deactivateCooperate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void;

Stops screen hopping. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name     | Type                     | Mandatory| Description                                                        |
| ----------- | ------------------------- | ---- | ------------------------------------------------------------ |
| isUnchained | boolean                   | Yes  | Whether to disable the cross-device link. The value **true** means to disable the cross-device link, and the value **false** means the opposite.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.deactivateCooperate(false, (error: BusinessError) => {
    if (error) {
      console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Stop Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.deactivateCooperate<sup>11+</sup>

deactivateCooperate(isUnchained: boolean): Promise&lt;void&gt;;

Stops screen hopping. This API uses a promise to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name     | Type   | Mandatory| Description                                                        |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| isUnchained | boolean | Yes  | Whether to disable the cross-device link. The value **true** means to disable the cross-device link, and the value **false** means the opposite.|

**Return value**

| Name             | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.deactivateCooperate(false).then(() => {
    console.log(`Stop Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.getCooperateSwitchState<sup>11+</sup>

getCooperateSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void;

Obtains the screen hopping status of the target device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name   | Type                        | Mandatory| Description                                                        |
| --------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| networkId | string                       | Yes  | Descriptor of the target device for screen hopping.                                    |
| callback  | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** indicates that screen hopping is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
let deviceDescriptor = "networkId";
try {
  cooperate.getCooperateSwitchState(deviceDescriptor, (error: BusinessError, data: boolean) => {
    if (error) {
      console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.getCooperateSwitchState<sup>11+</sup>

getCooperateSwitchState(networkId: string): Promise&lt;boolean&gt;;

Obtains the screen hopping status of the target device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name   | Type  | Mandatory| Description                    |
| --------- | ------ | ---- | ------------------------ |
| networkId | string | Yes  | Descriptor of the target device for screen hopping.|

**Return value**

| Parameters                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that screen hopping is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
let deviceDescriptor = "networkId";
try {
  cooperate.getCooperateSwitchState(deviceDescriptor).then((data: boolean) => {
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error: BusinessError) => {
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## on('cooperateMessage')<sup>11+</sup>

on(type: 'cooperateMessage', callback: Callback&lt;CooperateMessage&gt;): void;

Enables listening for screen hopping status change events.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                | Yes  | Event type. The value is **cooperateMessage**.  |
| callback | Callback&lt;[CooperateMessage](#cooperatemessage11)&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
function callback(msg: cooperate.CooperateMessage) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(msg)}`);
  return false;
}
try {
  cooperate.on('cooperateMessage', callback);
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## off('cooperateMessage')<sup>11+</sup>

off(type: 'cooperateMessage', callback?: Callback&lt;CooperateMessage&gt;): void;

Disables listening for screen hopping status change events.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value is **cooperate**.                               |
| callback | Callback&lt;[CooperateMessage](#cooperatemessage11)&gt; | No  | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
// Unregister a single callback.
function callbackOn(msgOn: cooperate.CooperateMessage) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(msgOn)}`);
  return false;
}
function callbackOff(msgOff: cooperate.CooperateMessage) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(msgOff)}`);
  return false;
}
try {
  cooperate.on('cooperateMessage', callbackOn);
  cooperate.off('cooperateMessage', callbackOff);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```ts
// Unregister all callbacks.
function callbackOn(msg: cooperate.CooperateMessage) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(msg)}`);
  return false;
}
try {
  cooperate.on('cooperateMessage', callbackOn);
  cooperate.off('cooperateMessage');
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


## on('cooperateMouse')<sup>12+</sup>

on(type: 'cooperateMouse', networkId: string, callback: Callback&lt;MouseLocation&gt;): void;

Registers a listener for the mouse cursor position of a device.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                | Yes  | Event type, which is **'cooperateMouse'**.  |
| networkId| string                                                | Yes  | Descriptor of the target device.  |
| callback | Callback&lt;[MouseLocation](#mouselocation12)&gt; | Yes  | Callback used to return the mouse cursor position of the device.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
function callback(data: cooperate.MouseLocation) {
  console.log('displayX:' + data.displayX + 'displayY:' + data.displayX + 'displayWidth:' +
    data.displayWidth + 'displayHeight:' + data.displayHeight );
}
try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callback);
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## off('cooperateMouse')<sup>12+</sup>

off(type: 'cooperateMouse', networkId: string, callback?: Callback&lt;MouseLocation&gt;): void;

Unregisters the listener for the mouse cursor position of a device.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type, which is **'cooperateMouse'**.                               |
| networkId| string                                                | Yes  | Descriptor of the target device.  |
| callback | Callback&lt;[MouseLocation](#mouselocation12)&gt; | No  | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
// Unregister a single callback.
function callbackOn(data: cooperate.MouseLocation) {
  console.log('Register mouse location listener');
  return false;
}
function callbackOff(data: cooperate.MouseLocation) {
  console.log('Unregister mouse location listener');
  return false;
}
try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callbackOn);
  cooperate.off('cooperateMouse', networkId, callbackOff);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```ts
// Unregister all callbacks.
function callbackOn(data: cooperate.MouseLocation) {
  console.log('Register mouse location listener');
}
try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callbackOn);
  cooperate.off('cooperateMouse', networkId);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## CooperateMessage<sup>11+</sup>

Defines a screen hopping status change event.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name     | Type          | Readable| Writable| Description                    |
| --------- | -------------- | ---- | ---- | ------------------------ |
| networkId | string         | Yes  | No  | Descriptor of the target device for screen hopping.|
| state     | CooperateState | Yes  | No  | Screen hopping status.        |


## MouseLocation<sup>12+</sup>

Defines the mouse pointer position for screen hopping.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name          | Type           | Readable| Writable| Description                          |
| ---------      | -------------- | ---- | ---- | ------------------------       |
| displayX       | number         | Yes  | No  | Position of the mouse pointer on the X coordinate of the screen.|
| displayY       | number         | Yes  | No  | Position of the mouse pointer on the Y coordinate of the screen.|
| displayWidth   | number         | Yes  | No  | Screen width, in pixels.                     |
| displayHeight  | number         | Yes  | No  | Screen height, in pixels.                     |

## CooperateState<sup>11+</sup>

Screen hopping status.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name                          | Type   | Readable| Writable| Description                  |
| ------------------------------ | ------ | ---- | ---- | ---------------------- |
| COOPERATE_PREPARE              | number | Yes  | No  | The preparation for screen hopping is finished.    |
| COOPERATE_UNPREPARE            | number | Yes  | No  | The preparation for screen hopping is cancelled.|
| COOPERATE_ACTIVATE             | number | Yes  | No  | Screen hopping starts.    |
| COOPERATE_ACTIVATE_SUCCESS     | number | Yes  | No  | Starting screen hopping succeeds.|
| COOPERATE_ACTIVATE_FAIL        | number | Yes  | No  | Starting screen hopping fails.|
| COOPERATE_DEACTIVATE_SUCCESS   | number | Yes  | No  | Stopping screen hopping succeeds.|
| COOPERATE_DEACTIVATE_FAIL      | number | Yes  | No  | Stopping screen hopping fails.|
| COOPERATE_SESSION_DISCONNECTED | number | Yes  | No  | The screen hopping session is disconnected.|
| COOPERATE_ACTIVATE_FAILURE     | number | Yes  | No  | Screen hopping fails to start.|
| COOPERATE_DEACTIVATE_FAILURE   | number | Yes  | No  | Screen hopping fails to stop.|


## MouseLocation<sup>12+</sup>

Represents the mouse cursor position.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name          | Type          | Readable| Writable| Description                    |
| ---------     | -------------- | ---- | ---- | ------------------------ |
| displayX      | number         | Yes  | No  | X coordinate of the mouse cursor.|
| displayY      | number         | Yes  | No  | Y coordinate of the mouse cursor.|
| displayWidth  | number         | Yes  | No  | Width of the screen where the mouse cursor is located, in pixels.|
| displayHeight | number         | Yes  | No  | Height of the screen where the mouse cursor is located, in pixels.|


## cooperate.prepare<sup>(deprecated)</sup>

prepare(callback: AsyncCallback&lt;void&gt;): void;

Prepares for screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.prepareCooperate](#cooperatepreparecooperate11).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name   | Type     | Mandatory | Description   |
| -------- | ------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;void&gt;  | Yes|Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.prepare((error: BusinessError) => {
    if (error) {
      console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing prepare success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.prepare<sup>(deprecated)</sup>

prepare(): Promise&lt;void&gt;;

Prepares for screen hopping. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.prepareCooperate](#cooperatepreparecooperate11-1).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Parameters                | Description                    |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.prepare().then(() => {
    console.log(`Keyboard mouse crossing prepare success.`);
  }, (error: BusinessError) => {
    console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.unprepare<sup>(deprecated)</sup>

unprepare(callback: AsyncCallback&lt;void&gt;): void;

Cancels the preparation for screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.unprepareCooperate](#cooperateunpreparecooperate11).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name  | Type                     | Mandatory| Description                                      |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.unprepare((error: BusinessError) => {
    if (error) {
      console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing unprepare success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.unprepare<sup>(deprecated)</sup>

unprepare(): Promise&lt;void&gt;;

Cancels the preparation for screen hopping. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.unprepareCooperate](#cooperateunpreparecooperate11-1).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Parameters               | Description                                         |
| ------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.unprepare().then(() => {
    console.log(`Keyboard mouse crossing unprepare success.`);
  }, (error: BusinessError) => {
    console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.activate<sup>(deprecated)</sup>

activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void;

Starts screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.activateCooperate](#cooperateactivatecooperate11).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  Yes  | Descriptor of the target device for screen hopping.            |
| inputDeviceId | number                       |  Yes  | Identifier of the input device for screen hopping.|
| callback             | AsyncCallback&lt;void&gt; |  Yes   | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 20900001 | Service Exception. Possible causes:  1. A system error, such as null pointer, container-related exception, IPC exception. 2. N-API invocation exception, invalid N-API status. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activate(targetNetworkId, inputDeviceId, (error: BusinessError) => {
    if (error) {
      console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Start Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.activate<sup>(deprecated)</sup>

activate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;;

Starts screen hopping. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.activateCooperate](#cooperateactivatecooperate11-1).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  Yes  | Descriptor of the target device for screen hopping.            |
| inputDeviceId | number                       |  Yes  | Identifier of the input device for screen hopping.|



**Return value**

| Name                 | Description                            |
| ---------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.    |

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 20900001 | Service Exception. Possible causes:  1. A system error, such as null pointer, container-related exception, IPC exception. 2. N-API invocation exception, invalid N-API status. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
 cooperate.activate(targetNetworkId, inputDeviceId).then(() => {
    console.log(`Start Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.deactivate<sup>(deprecated)</sup>

deactivate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void;

Stops screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.deactivateCooperate](#cooperatedeactivatecooperate11).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| isUnchained | boolean | Yes| Whether to disable the cross-device link.<br> The value **true** means to disable the cross-device link, and the value **false** means the opposite.|
| callback     | AsyncCallback&lt;void&gt; |  Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.deactivate(false, (error: BusinessError) => {
    if (error) {
      console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Stop Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.deactivate<sup>(deprecated)</sup>

deactivate(isUnchained: boolean): Promise&lt;void&gt;;

Stops screen hopping. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.deactivateCooperate](#cooperatedeactivatecooperate11-1).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name     | Type   | Mandatory| Description              |
| ----------- | ------- | ---- | ------------------ |
| isUnchained | boolean | Yes  | Whether to disable the cross-device link.<br> The value **true** means to disable the cross-device link, and the value **false** means the opposite.|



**Return value**

| Name               | Description                           |
| --------             | ----------------------------   |
| Promise&lt;void&gt; |  Promise that returns no value.     |

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.deactivate(false).then(() => {
    console.log(`Stop Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.getCrossingSwitchState<sup>(deprecated)</sup>

getCrossingSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void;

Obtains the screen hopping status of the target device. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.deactivateCooperate](#cooperategetcooperateswitchstate11).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory  | Description                           |
| --------             | ---------                    | ----  | ----------------------------    |
| networkId | string                       |  Yes   | Descriptor of the target device for screen hopping.            |
| callback             | AsyncCallback&lt;boolean&gt; |  Yes   | Callback used to return the result. The value **true** indicates that screen hopping is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@ohos.base';
let deviceDescriptor = "networkId";
try {
  cooperate.getCrossingSwitchState(deviceDescriptor, (error: BusinessError, data: boolean) => {
    if (error) {
      console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.getCrossingSwitchState<sup>(deprecated)</sup>

getCrossingSwitchState(networkId: string): Promise&lt;boolean&gt;;

Obtains the screen hopping status of the target device. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [cooperate.getCooperateSwitchState](#cooperategetcooperateswitchstate11-1).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name   | Type  | Mandatory  | Description                           |
| --------   | ---------  | ----  | ----------------------------    |
| networkId | string     |  Yes   | Descriptor of the target device for screen hopping.           |

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Return value**

| Parameters                       | Description                    |
| -------------------        | ------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that screen hopping is enabled, and the value **false** indicates the opposite.|



**Example**

```ts
import { BusinessError } from '@ohos.base';
let deviceDescriptor = "networkId";
try {
  cooperate.getCrossingSwitchState(deviceDescriptor).then((data: boolean) => {
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error: BusinessError) => {
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## on('cooperate')<sup>(deprecated)</sup>

on(type: 'cooperate', callback: Callback&lt;{ networkId: string, msg: CooperateMsg }&gt;): void;

Enables listening for screen hopping status change events.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [on('cooperateMessage')](#oncooperatemessage11).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                                                            | Mandatory| Description                           |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  Yes | Event type. The value is **cooperate**.|
| callback             | Callback&lt;{ networkId: string, msg: [CooperateMsg](#cooperatemsgdeprecated) }&gt; |  Yes | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
function callback(networkId: string, msg: cooperate.CooperateMsg) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);
  return false;
}
try {
  cooperate.on('cooperate', callback);
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## off('cooperate')<sup>(deprecated)</sup>

off(type: 'cooperate', callback?: Callback&lt;void&gt;): void;

Disables listening for screen hopping status change events.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [off('cooperateMessage')](#offcooperatemessage11).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                                                             | Mandatory   | Description                          |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  Yes   | Event type. The value is **cooperate**.|
| callback             | AsyncCallback&lt;void&gt; |  No | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
// Unregister a single callback.
function callbackOn(networkId: string, msg: cooperate.CooperateMsg) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);
  return false;
}
function callbackOff() {
  console.log(`Keyboard mouse crossing event`);
  return false;
}
try {
  cooperate.on('cooperate', callbackOn);
  cooperate.off('cooperate', callbackOff);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
```ts
// Unregister all callbacks.
function callbackOn(networkId: string, msg: cooperate.CooperateMsg) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);
  return false;
}
try {
  cooperate.on('cooperate', callbackOn);
  cooperate.off('cooperate');
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



##  CooperateMsg<sup>(deprecated)</sup>

Represents a screen hopping message notification.

> **NOTE**
>
> This API is deprecated since API version 10. You are advised to use [CooperateMessage](#cooperatemessage11).

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name                      | Value                            | Description                             |
| --------                     |  -----------------               |  -----------------               |
| COOPERATE_PREPARE |  0    |  The preparation for screen hopping is finished.  |
| COOPERATE_UNPREPARE |  1  |  The preparation for screen hopping is cancelled. |
| COOPERATE_ACTIVATE |  2   |  Screen hopping starts. |
| COOPERATE_ACTIVATE_SUCCESS | 3 | Starting screen hopping succeeds.|
| COOPERATE_ACTIVATE_FAIL | 4 | Starting screen hopping fails.|
| COOPERATE_DEACTIVATE_SUCCESS | 5 | Stopping screen hopping succeeds.|
| COOPERATE_DEACTIVATE_FAIL | 6 | Stopping screen hopping fails.|
| COOPERATE_SESSION_DISCONNECTED | 7 | The screen hopping session is disconnected.|
