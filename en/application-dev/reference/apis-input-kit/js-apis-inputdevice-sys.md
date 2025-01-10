# @ohos.multimodalInput.inputDevice (Input Device) (System API)


The **inputDevice** module allows you to listen for hot swap events of input devices and query information about input devices.


> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.multimodalInput.inputDevice (Input Device)](js-apis-inputdevice.md).


## Modules to Import

```js
import { inputDevice } from '@kit.InputKit';
```

## inputDevice.setKeyboardRepeatDelay<sup>10+</sup>

setKeyboardRepeatDelay(delay: number, callback: AsyncCallback&lt;void&gt;): void

Sets the keyboard repeat delay. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| delay    | number                    | Yes   | Keyboard repeat delay, in ms. The value range is [300, 1000] and the default value is **500**.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.setKeyboardRepeatDelay(350, (error: Error) => {
    if (error) {
      console.log(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set keyboard repeat delay success`);
  });
} catch (error) {
  console.log(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.setKeyboardRepeatDelay<sup>10+</sup>

setKeyboardRepeatDelay(delay: number): Promise&lt;void&gt;

Sets the keyboard repeat delay. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| delay | number | Yes   | Keyboard repeat delay, in ms. The value range is [300, 1000] and the default value is **500**.|

**Return value**

| Parameters                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.setKeyboardRepeatDelay(350).then(() => {
    console.log(`Set keyboard repeat delay success`);
  });
} catch (error) {
  console.log(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getKeyboardRepeatDelay<sup>10+</sup>

getKeyboardRepeatDelay(callback: AsyncCallback&lt;number&gt;): void

Obtains the keyboard repeat delay. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| callback   | AsyncCallback&lt;number&gt;                    | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getKeyboardRepeatDelay((error: Error, delay: Number) => {
    if (error) {
      console.log(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get keyboard repeat delay success`);
  });
} catch (error) {
  console.log(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getKeyboardRepeatDelay<sup>10+</sup>

getKeyboardRepeatDelay(): Promise&lt;number&gt;

Obtains the keyboard repeat delay. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Return value**

| Parameters                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getKeyboardRepeatDelay().then((delay: Number) => {
    console.log(`Get keyboard repeat delay success`);
  });
} catch (error) {
  console.log(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.setKeyboardRepeatRate<sup>10+</sup>

setKeyboardRepeatRate(rate: number, callback: AsyncCallback&lt;void&gt;): void

Sets the keyboard repeat rate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| rate    | number                    | Yes   | Keyboard repeat rate, in ms/time. The value range is [36, 100] and the default value is 50.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.setKeyboardRepeatRate(60, (error: Error) => {
    if (error) {
      console.log(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set keyboard repeat rate success`);
  });
} catch (error) {
  console.log(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.setKeyboardRepeatRate<sup>10+</sup>

setKeyboardRepeatRate(rate: number): Promise&lt;void&gt;

Sets the keyboard repeat rate. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| rate | number | Yes   | Keyboard repeat rate, in ms/time. The value range is [36, 100] and the default value is 50.|

**Return value**

| Parameters                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.setKeyboardRepeatRate(60).then(() => {
    console.log(`Set keyboard repeat rate success`);
  });
} catch (error) {
  console.log(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getKeyboardRepeatRate<sup>10+</sup>

getKeyboardRepeatRate(callback: AsyncCallback&lt;number&gt;): void

Obtains the keyboard repeat rate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getKeyboardRepeatRate((error: Error, rate: Number) => {
    if (error) {
      console.log(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get keyboard repeat rate success`);
  });
} catch (error) {
  console.log(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getKeyboardRepeatRate<sup>10+</sup>

getKeyboardRepeatRate(): Promise&lt;number&gt;

Obtains the keyboard repeat rate. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Return value**

| Parameters                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getKeyboardRepeatRate().then((rate: Number) => {
    console.log(`Get keyboard repeat rate success`);
  });
} catch (error) {
  console.log(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.setInputDeviceEnabled<sup>16+</sup>

setInputDeviceEnabled(deviceId: number, enabled: boolean): Promise&lt;void&gt;

Sets the input switch status of an input device. Take the touchscreen as an example. If the input switch is off, the touchscreen does not respond when being touched. If the input switch is on, the touchscreen wakes up when being touched.

**Required permissions**: ohos.permission.INPUT_DEVICE_CONTROLLER

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | ------------------------- |
| deviceId | number  | Yes  | Device ID.             |
| enabled  | boolean | Yes  | Whether to enable input switch of the input device. The value true indicates that the input switch is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Input Device Error Codes](errorcode-inputdevice.md).


| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 3900001  | The specified device does not exist.                         |

**Example**

```js
try {
  inputDevice.setInputDeviceEnabled(0, true).then(() => {
    console.info(`Set input device enable success`);
  }).catch((error) => {
    console.info(`Set input device enable failed, error=${JSON.stringify(error)}`);
  });
} catch (error) {
    console.info(`Set input device enable error`);
}
```

## inputDevice.setFunctionKeyEnabled<sup>15+</sup>

setFunctionKeyEnabled(functionKey: FunctionKey, enabled: boolean): Promise&lt;void&gt;

Sets whether to enable the function key.

**System capability**：SystemCapability.MultimodalInput.Input.InputDevice

**System API**：This is a system API.

**Parameters**：

| Parameters   | Type     | Mandatory | Description                      |
| -------- | ------- | ---- | ------------------------- |
| functionKey | [FunctionKey](js-apis-inputdevice.md#functionkey15)  | Yes   | Function key id.              |
| enabled  | boolean | Yes   | Setting the function key status, true is enable, false is disable. |

**Error codes**：

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**：

```js
try {
  inputDevice.setInputDeviceEnabled(1, true).then(() => {
    console.info(`Set capslock state success`);
  }).catch((error) => {
    console.info(`Set capslock state failed, error=${JSON.stringify(error)}`);
  });
} catch (error) {
    console.info(`Set capslock enable error`);
}
```
## 
