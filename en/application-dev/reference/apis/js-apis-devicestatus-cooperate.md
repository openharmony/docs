# @ohos.cooperate (Screen Hopping)

The **cooperate** module implements screen hopping for two or more networked devices to share the keyboard and mouse for collaborative operations.

> **NOTE**
>
>   - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import cooperate from '@ohos.cooperate'
```

## cooperate.prepare

prepare(callback: AsyncCallback&lt;void&gt;): void;

Prepares for screen hopping. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name   | Type     | Mandatory | Description   |
| -------- | ------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;void&gt;  | Yes|Callback used to return the result.  |

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

## cooperate.prepare

prepare(): Promise&lt;void&gt;

Prepares for screen hopping. This API uses a promise to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Parameters                | Description                    |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | Promise used to return the result.|



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



## cooperate.unprepare

unprepare(callback: AsyncCallback&lt;void&gt;): void;

Cancels the preparation for screen hopping. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

| Name  | Type                     | Mandatory| Description                                      |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

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



## cooperate.unprepare

unprepare(): Promise&lt;void&gt;;

Cancels the preparation for screen hopping. This API uses a promise to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Return value**

| Parameters               | Description                                         |
| ------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

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



## cooperate.activate

activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void;

Starts screen hopping. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  Yes  | Descriptor of the target device for screen hopping.            |
| inputDeviceId | number                       |  Yes  | Identifier of the input device for screen hopping.|
| callback             | AsyncCallback&lt;void&gt; |  Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](../errorcodes/errorcode-devicestatus.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 20900001 | Operation failed.  |

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

## cooperate.activate

activate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;;

Starts screen hopping. This API uses a promise to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  Yes  | Descriptor of the target device for screen hopping.            |
| inputDeviceId | number                       |  Yes  | Identifier of the input device for screen hopping.|



**Return value**

| Name                 | Description                            |
| ---------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.    |

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](../errorcodes/errorcode-devicestatus.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 20900001 | Operation failed.    |

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

## cooperate.deactivate

deactivate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void;

Stops screen hopping. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| isUnchained | boolean | Yes| Whether to disable the cross-device link.|
| callback             | AsyncCallback&lt;void&gt; |  Yes  | Callback used to return the result.      |



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

## cooperate.deactivate

deactivate(isUnchained: boolean): Promise&lt;void&gt;;

Stops screen hopping. This API uses a promise to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name     | Type   | Mandatory| Description              |
| ----------- | ------- | ---- | ------------------ |
| isUnchained | boolean | Yes  | Whether to disable the cross-device link.|



**Return value**

| Name               | Description                           |
| --------             | ----------------------------   |
| Promise&lt;void&gt; |  Promise used to return the result.     |



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

## cooperate.getCrossingSwitchState

getCrossingSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void;

Obtains the screen hopping status of the target device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory  | Description                           |
| --------             | ---------                    | ----  | ----------------------------    |
| networkId | string                       |  Yes   | Descriptor of the target device for screen hopping.            |
| callback             | AsyncCallback&lt;boolean&gt; |  Yes   | Callback used to return the result.|

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

## cooperate.getCrossingSwitchState

getCrossingSwitchState(networkId: string): Promise&lt;boolean&gt;;

Obtains the screen hopping status of the target device. This API uses a promise to return the result.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                         | Mandatory  | Description                           |
| --------             | ---------                    | ----  | ----------------------------    |
| networkId | string                       |  Yes   | Descriptor of the target device for screen hopping.           |



**Return value**

| Parameters                       | Description                    |
| -------------------        | ------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|



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

## on('cooperate')

on(type: 'cooperate', callback: Callback&lt;{ networkId: string, msg: CooperateMsg }&gt;): void;

Enables listening for screen hopping status change events.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                                                            | Mandatory| Description                           |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  Yes | Event type. The value is **cooperate**.|
| callback             | Callback&lt;{ networkId: string, msg: [CooperateMsg](#cooperatemsg) }&gt; |  Yes | Callback used to return the result.|



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

## off('cooperate')

off(type: 'cooperate', callback?: Callback&lt;void&gt;): void;

Disables listening for screen hopping status change events.

**System capability**: SystemCapability.Msdp.DeviceStatus.Cooperate

**Parameters**

| Name               | Type                                                             | Mandatory   | Description                          |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  Yes   | Event type. The value is **cooperate**.|
| callback             | AsyncCallback&lt;void&gt; |  No | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|



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

##  CooperateMsg

Represents a screen hopping message notification.

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
