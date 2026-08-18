# @ohos.cooperate (Screen Hopping) (System API)

<!--Kit: Distributed Service Kit-->
<!--Subsystem: Msdp-->
<!--Owner: @wuliangdong-->
<!--Designer: @hanruofei-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=818d162e1e8707b8fcaca57800abc0fd70c16226 translatedAt=2026-08-17T09:43:53.586Z pushedAt=2026-08-18T08:14:15.400Z -->

The **cooperate** module implements screen hopping for two or more networked devices to share the keyboard and mouse for collaborative operations.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { cooperate } from '@kit.DistributedServiceKit';
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.prepareCooperate((error: BusinessError) => {
    if (error) {
      console.error(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error,
        [`code`, `message`])}`);
      return;
    }
    console.info(`Keyboard mouse crossing prepareCooperate success.`);
  });
} catch (error) {
  console.error(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error,
    [`code`, `message`])}`);
}
```

## cooperate.prepareCooperate<sup>11+</sup>

prepareCooperate(): Promise&lt;void&gt;;

Prepares for screen hopping. This API uses a promise to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.prepareCooperate().then(() => {
    console.info(`Keyboard mouse crossing prepareCooperate success.`);
  }, (error: BusinessError) => {
    console.error(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error,
      [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error,
    [`code`, `message`])}`);
}
```

## cooperate.unprepareCooperate<sup>11+</sup>

unprepareCooperate(callback: AsyncCallback&lt;void&gt;): void;

Cancels the preparation for screen hopping. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.unprepareCooperate((error: BusinessError) => {
    if (error) {
      console.error(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error,
        [`code`, `message`])}`);
      return;
    }
    console.info(`Keyboard mouse crossing unprepareCooperate success.`);
  });
} catch (error) {
  console.error(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error,
    [`code`, `message`])}`);
}
```

## cooperate.unprepareCooperate<sup>11+</sup>

unprepareCooperate(): Promise&lt;void&gt;;

Cancels the preparation for screen hopping. This API uses a promise to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.unprepareCooperate().then(() => {
    console.info(`Keyboard mouse crossing unprepareCooperate success.`);
  }, (error: BusinessError) => {
    console.error(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error,
      [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error,
    [`code`, `message`])}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activateCooperate(targetNetworkId, inputDeviceId, (error: BusinessError) => {
    if (error) {
      console.error(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Start Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.error(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activateCooperate(targetNetworkId, inputDeviceId).then(() => {
    console.info(`Start Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.error(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.deactivateCooperate(false, (error: BusinessError) => {
    if (error) {
      console.error(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Stop Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.error(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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

| Type              | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.deactivateCooperate(false).then(() => {
    console.info(`Stop Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.error(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor = "networkId";
try {
  cooperate.getCooperateSwitchState(deviceDescriptor, (error: BusinessError, data: boolean) => {
    if (error) {
      console.error(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Get the status success, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that screen hopping is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor = "networkId";
try {
  cooperate.getCooperateSwitchState(deviceDescriptor).then((data: boolean) => {
    console.info(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error: BusinessError) => {
    console.error(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.on('cooperateMessage')<sup>11+</sup>

on(type: 'cooperateMessage', callback: Callback&lt;CooperateMessage&gt;): void;

Enables listening for screen hopping status change events.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                | Mandatory   | Event type. The value is **'cooperateMessage'**.   |
| callback | Callback&lt;[CooperateMessage](#cooperatemessage11)&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
function callback(msg: cooperate.CooperateMessage) {
  console.info(`Keyboard mouse crossing event: ${JSON.stringify(msg)}`);
  return false;
}

try {
  cooperate.on('cooperateMessage', callback);
} catch (error) {
  console.error(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.off('cooperateMessage')<sup>11+</sup>

off(type: 'cooperateMessage', callback?: Callback&lt;CooperateMessage&gt;): void;

Disables listening for screen hopping status change events.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | Yes   | Event type. The value is **'cooperateMessage'**.                                |
| callback | Callback&lt;[CooperateMessage](#cooperatemessage11)&gt; | No  | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes:1.Incorrect parameter types.2.Parameter verification failed. |

**Example**

```ts
// Unregister a single callback.
function callbackOn(msgOn: cooperate.CooperateMessage) {
  console.info(`Keyboard mouse crossing event: ${JSON.stringify(msgOn)}`);
  return false;
}

function callbackOff(msgOff: cooperate.CooperateMessage) {
  console.info(`Keyboard mouse crossing event: ${JSON.stringify(msgOff)}`);
  return false;
}

try {
  cooperate.on('cooperateMessage', callbackOn);
  cooperate.off('cooperateMessage', callbackOff);
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```ts
// Unregister all callbacks.
import { cooperate } from '@kit.DistributedServiceKit';
function callbackOn(msg: cooperate.CooperateMessage) {
  console.info(`Keyboard mouse crossing event: ${JSON.stringify(msg)}`);
  return false;
}

try {
  cooperate.on('cooperateMessage', callbackOn);
  cooperate.off('cooperateMessage');
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.on('cooperateMouse')<sup>12+</sup>

on(type: 'cooperateMouse', networkId: string, callback: Callback&lt;MouseLocation&gt;): void;

Registers a listener for the mouse cursor position of a device.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                | Mandatory   | Event type. The value is **'cooperateMouse'**.   |
| networkId| string                                                | Mandatory   | Descriptor of the target device.   |
| callback | Callback&lt;[MouseLocation](#mouselocation12)&gt; | Yes  | Callback used to return the mouse cursor position of the device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
function callback(data: cooperate.MouseLocation) {
  console.info('displayX:' + data.displayX + 'displayY:' + data.displayY + 'displayWidth:' +
  data.displayWidth + 'displayHeight:' + data.displayHeight);
}

try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callback);
} catch (error) {
  console.error(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.off('cooperateMouse')<sup>12+</sup>

off(type: 'cooperateMouse', networkId: string, callback?: Callback&lt;MouseLocation&gt;): void;

Unregisters the listener for the mouse cursor position of a device.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type, which is **'cooperateMouse'**.                               |
| networkId| string                                                | Yes   | Descriptor of the target device.   |
| callback | Callback&lt;[MouseLocation](#mouselocation12)&gt; | No  | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
// Unregister a single callback.
function callbackOn(data: cooperate.MouseLocation) {
  console.info('Register mouse location listener');
  return false;
}

function callbackOff(data: cooperate.MouseLocation) {
  console.info('Unregister mouse location listener');
  return false;
}

try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callbackOn);
  cooperate.off('cooperateMouse', networkId, callbackOff);
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```ts
// Unregister all callbacks.
function callbackOn(data: cooperate.MouseLocation) {
  console.info('Register mouse location listener');
}

try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callbackOn);
  cooperate.off('cooperateMouse', networkId);
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.activateCooperateWithOptions<sup>20+</sup>

activateCooperateWithOptions(targetNetworkId: string, inputDeviceId: number, cooperateOptions?: CooperateOptions ): Promise&lt;void&gt;

Starts screen hopping based on the specified options. This API uses a promise to return the result.

**Required permissions**: ohos.permission.COOPERATE_MANAGER

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name   | Type  | Mandatory| Description                    |
| --------- | ------ | ---- | ------------------------ |
| targetNetworkId | string | Yes  | Descriptor of the target device for screen hopping.|
| inputDeviceId   | number | Yes  |  ID of the input device that initiates screen hopping.  |
|cooperateOptions | [CooperateOptions](#cooperateoptions20) | No  | Screen hopping options, such as the exit position. If this parameter is not set, this API works in the same way as [cooperate.activateCooperate](#cooperateactivatecooperate11-1).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activateCooperateWithOptions(targetNetworkId, inputDeviceId).then(() => {
    console.info(`activateCooperateWithOptions success.`);
  }, (error: BusinessError) => {
    console.error(`activateCooperateWithOptions, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`activateCooperateWithOptions, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## CooperateMessage<sup>11+</sup>

Defines a screen hopping status change event.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name     | Type          |Read-Only| Optional| Description                    |
| --------- | -------------- | ---- | ---- | ------------------------ |
| networkId | string         | No  | No  | Descriptor of the target device for screen hopping.|
| state     | CooperateState | No  | No  | Screen hopping status.        |

## MouseLocation<sup>12+</sup>

Defines the mouse pointer position for screen hopping.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name          | Type           | Read-Only| Optional| Description                          |
| ---------------- | -------------- | ---- | ---- | ------------------------------ |
| displayX       | number         | No   | No   | Position of the mouse pointer on the X coordinate of the screen, in px. |
| displayY       | number         | No   | No   | Position of the mouse pointer on the Y coordinate of the screen, in px. |
| displayWidth   | number         | No  | No  | Screen width, in pixels.                     |
| displayHeight  | number         | No  | No  | Screen height, in pixels.                     |

## CooperateState<sup>11+</sup>

Enumerates the screen hopping states.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name                          |  Value| Description                  |
| ------------------------------ | ---- | ---------------------- |
| COOPERATE_PREPARE              | 0 | The preparation for screen hopping is finished.    |
| COOPERATE_UNPREPARE            | 1  | The preparation for screen hopping is cancelled.|
| COOPERATE_ACTIVATE             | 2  | Screen hopping starts.    |
| COOPERATE_ACTIVATE_SUCCESS     | 3  | Starting screen hopping succeeds.|
| COOPERATE_ACTIVATE_FAILURE        | 4 | Screen hopping fails to start.|
| COOPERATE_DEACTIVATE_SUCCESS   | 5  | Stopping screen hopping succeeds.|
| COOPERATE_DEACTIVATE_FAILURE      | 6 | Screen hopping fails to stop.|
| COOPERATE_SESSION_DISCONNECTED | 7 | The screen hopping session is disconnected.|

## CooperateOptions<sup>20+</sup>

 Screen hopping options, such as the exit position.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name     | Type          | Read-Only| Optional| Description                    |
| --------- | -------------- | ---- | ---- | ------------------------ |
| displayX      | number         | No   | No   | X coordinate of the mouse cursor, in px. |
| displayY      | number         | No   | No   | Y coordinate of the mouse cursor, in px. |
| displayId     | number         | No  | No  | Screen ID of the peer device.|

## cooperate.prepare<sup>(deprecated)</sup>

prepare(callback: AsyncCallback&lt;void&gt;): void;

Prepares for screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.prepareCooperate](#cooperatepreparecooperate11) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name   | Type     | Mandatory | Description   |
| -------- | ------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;void&gt;  | Yes|Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.prepare((error: BusinessError) => {
    if (error) {
      console.error(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Keyboard mouse crossing prepare success.`);
  });
} catch (error) {
  console.error(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.prepare<sup>(deprecated)</sup>

prepare(): Promise&lt;void&gt;;

Prepares for screen hopping. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.prepareCooperate](#cooperatepreparecooperate11-1) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.prepare().then(() => {
    console.info(`Keyboard mouse crossing prepare success.`);
  }, (error: BusinessError) => {
    console.error(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.unprepare<sup>(deprecated)</sup>

unprepare(callback: AsyncCallback&lt;void&gt;): void;

Cancels the preparation for screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.unprepareCooperate](#cooperateunpreparecooperate11) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name  | Type                     | Mandatory| Description                                      |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.unprepare((error: BusinessError) => {
    if (error) {
      console.error(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Keyboard mouse crossing unprepare success.`);
  });
} catch (error) {
  console.error(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.unprepare<sup>(deprecated)</sup>

unprepare(): Promise&lt;void&gt;;

Cancels the preparation for screen hopping. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.unprepareCooperate](#cooperateunpreparecooperate11-1) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Type               | Description                                         |
| ------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.unprepare().then(() => {
    console.info(`Keyboard mouse crossing unprepare success.`);
  }, (error: BusinessError) => {
    console.error(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.activate<sup>(deprecated)</sup>

activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void;

Starts screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.activateCooperate](#cooperateactivatecooperate11) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  Yes  | Descriptor of the target device for screen hopping.|
| inputDeviceId | number                       |  Yes  | Identifier of the input device for screen hopping.|
| callback             | AsyncCallback&lt;void&gt; |  Yes   | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status. |
| 202 | Permission verification failed. A non-system application calls a system API.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activate(targetNetworkId, inputDeviceId, (error: BusinessError) => {
    if (error) {
      console.error(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Start Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.error(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.activate<sup>(deprecated)</sup>

activate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;;

Starts screen hopping. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.activateCooperate](#cooperateactivatecooperate11-1) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  Yes  | Descriptor of the target device for screen hopping.|
| inputDeviceId | number                       |  Yes  | Identifier of the input device for screen hopping.|

**Return value**

| Type                 | Description                            |
| ---------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Hopping Error Codes](errorcode-devicestatus.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status.|
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activate(targetNetworkId, inputDeviceId).then(() => {
    console.info(`Start Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.error(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.deactivate<sup>(deprecated)</sup>

deactivate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void;

Stops screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.deactivateCooperate](#cooperatedeactivatecooperate11) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| isUnchained | boolean | Yes| Whether to disable the cross-device link.<br> The value **true** means to disable the cross-device link, and the value **false** means the opposite.|
| callback     | AsyncCallback&lt;void&gt; |  Yes  | Callback used to return the operation result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 |Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.deactivate(false, (error: BusinessError) => {
    if (error) {
      console.error(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Stop Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.error(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.deactivate<sup>(deprecated)</sup>

deactivate(isUnchained: boolean): Promise&lt;void&gt;;

Stops screen hopping. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.deactivateCooperate](#cooperatedeactivatecooperate11-1) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name     | Type   | Mandatory| Description              |
| ----------- | ------- | ---- | ------------------ |
| isUnchained | boolean | Yes  | Whether to disable the cross-device link.<br> The value **true** means to disable the cross-device link, and the value **false** means the opposite.|

**Return value**

| Type               | Description                           |
| --------             | ----------------------------   |
| Promise&lt;void&gt; |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cooperate.deactivate(false).then(() => {
    console.info(`Stop Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.error(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.getCrossingSwitchState<sup>(deprecated)</sup>

getCrossingSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void;

Obtains the screen hopping status of the target device. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.getCooperateSwitchState](#cooperategetcooperateswitchstate11) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory  | Description                           |
| --------             | ---------                    | ----  | ----------------------------    |
| networkId | string                       |  Yes   | Descriptor of the target device for screen hopping.            |
| callback             | AsyncCallback&lt;boolean&gt; |  Yes   | Callback used to return the result. The value **true** indicates that screen hopping is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor = "networkId";
try {
  cooperate.getCrossingSwitchState(deviceDescriptor, (error: BusinessError, data: boolean) => {
    if (error) {
      console.error(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.info(`Get the status success, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.getCrossingSwitchState<sup>(deprecated)</sup>

getCrossingSwitchState(networkId: string): Promise&lt;boolean&gt;;

Obtains the screen hopping status of the target device. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.getCooperateSwitchState](#cooperategetcooperateswitchstate11-1) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name   | Type  | Mandatory  | Description                           |
| --------   | ---------  | ----  | ----------------------------    |
| networkId | string     |  Yes   | Descriptor of the target device for screen hopping.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Return value**

| Type                      | Description                    |
| -------------------        | ------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that screen hopping is enabled, and the value **false** indicates the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor = "networkId";
try {
  cooperate.getCrossingSwitchState(deviceDescriptor).then((data: boolean) => {
    console.info(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error: BusinessError) => {
    console.error(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.on('cooperate')<sup>(deprecated)</sup>

on(type: 'cooperate', callback: Callback&lt;{ networkId: string, msg: CooperateMsg }&gt;): void;

Enables listening for screen hopping status change events.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.on('cooperateMessage')](#cooperateoncooperatemessage11) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                                                            | Mandatory| Description                           |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  Mandatory  | Event type. The value is **'cooperate'**. |
| callback             | Callback&lt;{ networkId: string, msg: [CooperateMsg](#cooperatemsgdeprecated) }&gt; |  Yes | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
import { cooperate } from '@kit.DistributedServiceKit';
class Data {
  networkId: string = "networkId";
  msg: cooperate.CooperateMsg = 0;
}

try {
  cooperate.on('cooperate', (data: Data) => {
    console.info(`Keyboard mouse crossing event: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.off('cooperate')<sup>(deprecated)</sup>

off(type: 'cooperate', callback?: Callback&lt;void&gt;): void;

Disables listening for screen hopping status change events.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cooperate.off('cooperateMessage')](#cooperateoffcooperatemessage11) instead.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                                                             | Mandatory   | Description                          |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  Yes   | Event type. The value is **cooperate**.|
| callback             | AsyncCallback&lt;void&gt; |  No | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
// Unregister a single callback.
class Data {
  networkId: string = "networkId";
  msg: cooperate.CooperateMsg = 0;
}

function callbackOff() {
  console.info(`Keyboard mouse crossing event`);
  return false;
}

try {
  cooperate.on('cooperate', (data: Data) => {
    console.info(`Keyboard mouse crossing event: ${JSON.stringify(data)}`);
  });
  cooperate.off('cooperate', callbackOff);
} catch (error) {
  console.error(`Register failed, error: ${JSON.stringify(error)}`);
}
```

```ts
// Unregister all callbacks.
class Data {
  networkId: string = "networkId";
  msg: cooperate.CooperateMsg = 0;
}

try {
  cooperate.on('cooperate', (data: Data) => {
    console.info(`Keyboard mouse crossing event: ${JSON.stringify(data)}`);
  });
  cooperate.off('cooperate');
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

##  CooperateMsg<sup>(deprecated)</sup>

Represents a screen hopping message notification.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [CooperateState](#cooperatestate11) instead.

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