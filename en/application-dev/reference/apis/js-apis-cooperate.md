# Screen Hopping

The Screen Hopping module enables two or more networked devices to share the keyboard and mouse for collaborative operations.

> **Description**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'
```

## inputDeviceCooperate.enable

enable(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Specifies whether to enable screen hopping. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name   | Type     | Mandatory | Description   |
| -------- | ------------------------- | ---- | --------------------------- |
| enable   | boolean                   | Yes  | Whether to enable screen hopping.|
| callback | AsyncCallback&lt;void&gt;  | Yes |Callback used to return the result.  |



**Example**

```js
try {
  inputDeviceCooperate.enable(true, (error) => {
    if (error) {
      console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing enable success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.enable

enable(enable: boolean): Promise&lt;void&gt;

Specifies whether to enable screen hopping. This API uses a promise to return the result.


**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name    | Type    | Mandatory | Description                                                                                |
| --------- | ------- | ---- | -------------------------------------------------------------------                 |
| enable    | boolean | Yes  | Whether to enable screen hopping.                  |



**Return value**

| Name                | Description                    |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | Promise used to return the result.       |



**Example**

```js
try {
  inputDeviceCooperate.enable(true).then(() => {
    console.log(`Keyboard mouse crossing enable success.`);
  }, (error) => {
    console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.start

start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback\<void>): void

Starts screen hopping. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| sinkDeviceDescriptor | string                       |  Yes  | Descriptor of the target device for screen hopping.            |
| srcInputDeviceId     | number                       |  Yes  | ID of the target device for screen hopping.          |
| callback             | AsyncCallback\<void>         |  Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](../errorcodes/errorcode-multimodalinput.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 4400001  | This error code is reported if an invalid device descriptor is passed to the screen hopping API.               |
| 4400002  | This error code is reported if the screen hopping status is abnormal when the screen hopping API is called.               |

**Example**

```js
let sinkDeviceDescriptor = "descriptor";
let srcInputDeviceId = 0;
try {
  inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId, (error) => {
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

## inputDeviceCooperate.start

start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise\<void>

Starts screen hopping. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| sinkDeviceDescriptor | string                       |  Yes  | Descriptor of the target device for screen hopping.            |
| srcInputDeviceId     | number                       |  Yes  | ID of the target device for screen hopping.          |



**Return value**

| Name                 | Description                            |
| ---------------------- | ------------------------------- |
| Promise\<void>         | Promise used to return the result.      |

**Error codes**

For details about the error codes, see [Screen Hopping Error Codes](../errorcodes/errorcode-multimodalinput.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 4400001  | This error code is reported if an invalid device descriptor is passed to the screen hopping API.                |
| 4400002  | This error code is reported if the screen hopping status is abnormal when the screen hopping API is called.              |

**Example**

```js
let sinkDeviceDescriptor = "descriptor";
let srcInputDeviceId = 0;
try {
  inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId).then(() => {
    console.log(`Start Keyboard mouse crossing success.`);
  }, (error) => {
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.stop

stop(callback: AsyncCallback\<void>): void

Stops screen hopping. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| callback             | AsyncCallback\<void>         |  Yes  | Callback used to return the result.       |



**Example**

```js
try {
  inputDeviceCooperate.stop((error) => {
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

## inputDeviceCooperate.stop

stop(): Promise\<void>

Stops screen hopping. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name               | Description                           |
| --------             | ----------------------------   |
| Promise\<void>       |  Promise used to return the result.     | 

**Example**

```js
try {
  inputDeviceCooperate.stop().then(() => {
    console.log(`Stop Keyboard mouse crossing success.`);
  }, (error) => {
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.getState

getState(deviceDescriptor: string, callback: AsyncCallback<{ state: boolean }>): void

Checks whether screen hopping is enabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name               | Type                         | Mandatory  | Description                           |
| --------             | ---------                    | ----  | ----------------------------    |
| deviceDescriptor     | string                       |  Yes   | Descriptor of the target device for screen hopping.            |
| callback             | AsyncCallback<{ state: boolean }> |  Yes   | Callback used to return the result.       |

**Example**

```js
let deviceDescriptor = "descriptor";
try {
  inputDeviceCooperate.getState(deviceDescriptor, (error, data) => {
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

## inputDeviceCooperate.getState

getState(deviceDescriptor: string): Promise<{ state: boolean }>

Checks whether screen hopping is enabled. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name               | Type                         | Mandatory  | Description                           |
| --------             | ---------                    | ----  | ----------------------------    |
| deviceDescriptor     | string                       |  Yes   | Descriptor of the target device for screen hopping.           |



**Return value**

| Name                       | Description                    |
| -------------------        | ------------------------------- |
| Promise<{ state: boolean }>| Promise used to return the result.       |



**Example**

```js
try {
  inputDeviceCooperate.getState(deviceDescriptor).then((data) => {
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error) => {
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## on('cooperation')

on(type: 'cooperation', callback: AsyncCallback<{ deviceDescriptor: string, eventMsg: EventMsg }>): void

Enables listening for screen hopping events.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name               | Type                                                            | Mandatory| Description                           |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  Yes | Event type. The value is **cooperation**.        |
| callback             | AsyncCallback<{ deviceDescriptor: string, eventMsg: [EventMsg](#eventmsg) }> |  Yes | Callback used to return the result.   |



**Example**

```js
try {
  inputDeviceCooperate.on('cooperation', (data) => {
    console.log(`Keyboard mouse crossing event: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## off('cooperation')

off(type: 'cooperation', callback?: AsyncCallback\<void>): void

Disables listening for screen hopping events.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**Parameters**

| Name               | Type                                                             | Mandatory   | Description                          |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  Yes   | Event type. The value is **cooperation**.        |
| callback             | AsyncCallback<void> |  No | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|



**Example**

```js
// Unregister a single callback.
function callback(event) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(event)}`);
  return false;
}
try {
  inputDeviceCooperate.on('cooperation', callback);
  inputDeviceCooperate.off("cooperation", callback);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
```js
// Unregister all callbacks.
function callback(event) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(event)}`);
  return false;
}
try {
  inputDeviceCooperate.on('cooperation', callback);
  inputDeviceCooperate.off("cooperation");
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## EventMsg

Enumerates screen hopping event.

**System capability**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

| Name                       | Value       | Description                             |
| --------                     | --------- |  -----------------               |
| MSG_COOPERATE_INFO_START     | 200       |  Screen hopping starts.      |
| MSG_COOPERATE_INFO_SUCCESS   | 201       |  Screen hopping succeeds.     |
| MSG_COOPERATE_INFO_FAIL      | 202       |  Screen hopping fails.     |
| MSG_COOPERATE_STATE_ON       | 500       |  Screen hopping is enabled.  |
| MSG_COOPERATE_STATE_OFF      | 501       |  Screen hopping is disabled.  |
