# @ohos.multimodalInput.inputDevice (Input Device) (System API)


The **inputDevice** module implements input device management functions such as querying input device information.


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
| 202 | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.setKeyboardRepeatDelay(350, (error: Error) => {
    if (error) {
      console.error(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set keyboard repeat delay success`);
  });
} catch (error) {
  console.error(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | A promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202 | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.setKeyboardRepeatDelay(350).then(() => {
    console.log(`Set keyboard repeat delay success`);
  });
} catch (error) {
  console.error(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
| callback   | AsyncCallback&lt;number&gt;                    | Yes   | Callback used to return the keyboard repeat delay.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getKeyboardRepeatDelay((error: Error, delay: Number) => {
    if (error) {
      console.error(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get keyboard repeat delay success`);
  });
} catch (error) {
  console.error(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getKeyboardRepeatDelay<sup>10+</sup>

getKeyboardRepeatDelay(): Promise&lt;number&gt;

Obtains the keyboard repeat delay. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Return value**

| Type                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the keyboard repeat delay.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getKeyboardRepeatDelay().then((delay: Number) => {
    console.log(`Get keyboard repeat delay success`);
  });
} catch (error) {
  console.error(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
| 202  | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.setKeyboardRepeatRate(60, (error: Error) => {
    if (error) {
      console.error(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set keyboard repeat rate success`);
  });
} catch (error) {
  console.error(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | A promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.setKeyboardRepeatRate(60).then(() => {
    console.log(`Set keyboard repeat rate success`);
  });
} catch (error) {
  console.error(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the keyboard repeat rate.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getKeyboardRepeatRate((error: Error, rate: Number) => {
    if (error) {
      console.error(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get keyboard repeat rate success`);
  });
} catch (error) {
  console.error(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getKeyboardRepeatRate<sup>10+</sup>

getKeyboardRepeatRate(): Promise&lt;number&gt;

Obtains the keyboard repeat rate. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Return value**

| Type                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the keyboard repeat rate.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getKeyboardRepeatRate().then((rate: Number) => {
    console.log(`Get keyboard repeat rate success`);
  });
} catch (error) {
  console.error(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.setInputDeviceEnabled<sup>18+</sup>

setInputDeviceEnabled(deviceId: number, enabled: boolean): Promise&lt;void&gt;

Sets the input switch status of an input device. Take the touchscreen as an example. If the input switch is off, the touchscreen does not respond when being touched. If the input switch is on, the touchscreen wakes up when being touched.

**Required permissions**: ohos.permission.INPUT_DEVICE_CONTROLLER

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**System API**: This is a system API.

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | ------------------------- |
| deviceId | number  | Yes  | Device ID.             |
| enabled  | boolean | Yes  | Switch status of the input device. The value **true** indicates that the input device is enabled, and the value **false** indicates the opposite.|

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
  });
} catch (error) {
    console.error(`Set input device enable error`);
}
```
