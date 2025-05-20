# @ohos.multimodalInput.inputDevice (Input Device)


The inputDevice module implements input device management functions such as listening for the connection and disconnection of input devices and querying input device information such as the device name.


> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import { inputDevice } from '@kit.InputKit';
```

## inputDevice.getDeviceList<sup>9+</sup>

getDeviceList(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the IDs of all input devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type                                    | Mandatory| Description                                    |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the IDs of all input devices. **id** is the unique ID of an input device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputDevice.getDeviceList((error: Error, ids: Array<Number>) => {
    if (error) {
      console.error(`Failed to get device id list, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Device id list: ${JSON.stringify(ids)}`);
  });
} catch (error) {
  console.error(`Failed to get device id list, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getDeviceList<sup>9+</sup>

getDeviceList(): Promise&lt;Array&lt;number&gt;&gt;

Obtains the IDs of all input devices. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Return value**

| Type                              | Description                                       |
| ---------------------------------- | ------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the IDs of all input devices.|

**Example**

```js
try {
  inputDevice.getDeviceList().then((ids: Array<Number>) => {
    console.log(`Device id list: ${JSON.stringify(ids)}`);
  });
} catch (error) {
  console.error(`Failed to get device id list, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getDeviceInfo<sup>9+</sup>

getDeviceInfo(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void

Obtains the information about the input device with the specified ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type                                                    | Mandatory| Description                                   |
| -------- | -------------------------------------------------------- | ---- | --------------------------------------- |
| deviceId | number                                                   | Yes  | ID of the input device.                 |
| callback | AsyncCallback&lt;[InputDeviceData](#inputdevicedata)&gt; | Yes  | Callback used to return the information about the input device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Obtain the name of the device whose ID is 1.
try {
  inputDevice.getDeviceInfo(1, (error: Error, deviceData: inputDevice.InputDeviceData) => {
    if (error) {
      console.error(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Device info: ${JSON.stringify(deviceData)}`);
  });
} catch (error) {
  console.error(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getDeviceInfo<sup>9+</sup>

getDeviceInfo(deviceId: number): Promise&lt;InputDeviceData&gt;

Obtains the information about the input device with the specified ID. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| deviceId | number | Yes  | ID of the input device.|

**Return value**

| Type                                              | Description                           |
| -------------------------------------------------- | ------------------------------- |
| Promise&lt;[InputDeviceData](#inputdevicedata)&gt; | Promise used to return the information about the input device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Obtain the name of the device whose ID is 1.
try {
  inputDevice.getDeviceInfo(1).then((deviceData: inputDevice.InputDeviceData) => {
    console.log(`Device info: ${JSON.stringify(deviceData)}`);
  });
} catch (error) {
  console.error(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getDeviceInfoSync<sup>10+</sup>

getDeviceInfoSync(deviceId: number): InputDeviceData

Obtains information about the specified input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| deviceId | number | Yes  | ID of the input device.|

**Return value**

| Type                                              | Description                           |
| -------------------------------------------------- | ------------------------------- |
| [InputDeviceData](#inputdevicedata) | Information about the input device, including device ID, name, supported source, physical address, version information, and product information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Obtain the name of the device whose ID is 1.
try {
  let deviceData: inputDevice.InputDeviceData = inputDevice.getDeviceInfoSync(1);
  console.log(`Device info: ${JSON.stringify(deviceData)}`);
} catch (error) {
  console.error(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.on<sup>9+</sup>

on(type: "change", listener: Callback&lt;DeviceListener&gt;): void

Enables listening for device hot swap events. When performing this operation, you need to connect to external devices such as a mouse, keyboard, and touchscreen.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| type     | string                                   | Yes   | Event type. This field has a fixed value of **change**. |
| listener | Callback&lt;[DeviceListener](#devicelistener9)&gt; | Yes   | Listener for events of the input device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
let isPhysicalKeyboardExist = true;
try {
  inputDevice.on("change", (data: inputDevice.DeviceListener) => {
    console.log(`Device event info: ${JSON.stringify(data)}`);
    inputDevice.getKeyboardType(data.deviceId, (err: Error, type: inputDevice.KeyboardType) => {
      console.log("The keyboard type is: " + type);
      if (type == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD && data.type == 'add') {
        // The physical keyboard is connected.
        isPhysicalKeyboardExist = true;
      } else if (type == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD && data.type == 'remove') {
        // The physical keyboard is disconnected.
        isPhysicalKeyboardExist = false;
      }
    });
  });
  // Check whether the soft keyboard is open based on the value of isPhysicalKeyboardExist.
} catch (error) {
  console.error(`Get device info failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.off<sup>9+</sup>

off(type: "change", listener?: Callback&lt;DeviceListener&gt;): void

Disables listening for device hot swap events. This API is called before the application exits.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| type     | string                                   | Yes   | Event type. This field has a fixed value of **change**. |
| listener | Callback&lt;[DeviceListener](#devicelistener9)&gt; | No   | Listener for events of the input device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
let callback = (data: inputDevice.DeviceListener) => {
  console.log(`Report device event info: ${JSON.stringify(data, [`type`, `deviceId`])}`);
};

try {
  inputDevice.on("change", callback);
} catch (error) {
  console.error(`Listen device event failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}

// Disable this listener.
try {
  inputDevice.off("change", callback);
} catch (error) {
  console.error(`Cancel listening device event failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}

// Disable all listeners.
try {
  inputDevice.off("change");
} catch (error) {
  console.error(`Cancel all listening device event failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getDeviceIds<sup>(deprecated)</sup>

getDeviceIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the IDs of all input devices. This API uses an asynchronous callback to return the result.

> This API is deprecated since API version 9. You are advised to use [inputDevice.getDeviceList](#inputdevicegetdevicelist9) instead.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type                                    | Mandatory| Description                                    |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the IDs of all input devices.|

**Example**

```js
inputDevice.getDeviceIds((error: Error, ids: Array<Number>) => {
  if (error) {
    console.error(`Failed to get device id list, error: ${JSON.stringify(error, [`code`, `message`])}`);
    return;
  }
  console.log(`Device id list: ${JSON.stringify(ids)}`);
});
```

## inputDevice.getDeviceIds<sup>(deprecated)</sup>

getDeviceIds(): Promise&lt;Array&lt;number&gt;&gt;

Obtains the IDs of all input devices. This API uses a promise to return the result.

> This API is deprecated since API version 9. You are advised to use [inputDevice.getDeviceList](#inputdevicegetdevicelist9) instead.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Return value**

| Type                              | Description                                       |
| ---------------------------------- | ------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the IDs of all input devices.|

**Example**

```js
inputDevice.getDeviceIds().then((ids: Array<Number>) => {
  console.log(`Device id list: ${JSON.stringify(ids)}`);
});
```

## inputDevice.getDevice<sup>(deprecated)</sup>

getDevice(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void

Obtains the information about the input device with the specified ID. This API uses an asynchronous callback to return the result.

> This API is deprecated since API version 9. You are advised to use [inputDevice.getDeviceInfo](#inputdevicegetdeviceinfo9) instead.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type                                                    | Mandatory| Description                            |
| -------- | -------------------------------------------------------- | ---- | -------------------------------- |
| deviceId | number                                                   | Yes  | ID of the input device.                    |
| callback | AsyncCallback&lt;[InputDeviceData](#inputdevicedata)&gt; | Yes  | Callback used to return the information about the input device.|

**Example**

```js
// Obtain the name of the device whose ID is 1.
inputDevice.getDevice(1, (error: Error, deviceData: inputDevice.InputDeviceData) => {
  if (error) {
    console.error(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);
    return;
  }
  console.log(`Device info: ${JSON.stringify(deviceData)}`);
});
```

## inputDevice.getDevice<sup>(deprecated)</sup>

getDevice(deviceId: number): Promise&lt;InputDeviceData&gt;

Obtains the information about the input device with the specified ID. This API uses a promise to return the result.

> This API is deprecated since API version 9. You are advised to use [inputDevice.getDeviceInfo](#inputdevicegetdeviceinfo9) instead.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type  | Mandatory| Description        |
| -------- | ------ | ---- | ------------ |
| deviceId | number | Yes  | ID of the input device.|

**Return value**

| Type                                              | Description                               |
| -------------------------------------------------- | ----------------------------------- |
| Promise&lt;[InputDeviceData](#inputdevicedata)&gt; | Promise used to return the information about the input device.|

**Example**

```js
// Obtain the name of the device whose ID is 1.
inputDevice.getDevice(1).then((deviceData: inputDevice.InputDeviceData) => {
  console.log(`Device info: ${JSON.stringify(deviceData)}`);
});
```

## inputDevice.supportKeys<sup>9+</sup>

supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: AsyncCallback &lt;Array&lt;boolean&gt;&gt;): void

Checks whether the input device supports the specified keys. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type                                     | Mandatory| Description                                                  |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------ |
| deviceId | number                                    | Yes  | ID of the input device. The device ID changes if the same physical device is repeatedly removed and inserted.|
| keys     | Array[&lt;KeyCode&gt;](js-apis-keycode.md#keycode)  | Yes  | Keycodes to be queried. A maximum of five keycodes can be specified.               |
| callback | AsyncCallback&lt;Array&lt;boolean&gt;&gt; | Yes  | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Check whether the input device whose ID is 1 supports keycodes 17, 22, and 2055.
try {
  inputDevice.supportKeys(1, [17, 22, 2055], (error: Error, supportResult: Array<Boolean>) => {
    console.log(`Query result: ${JSON.stringify(supportResult)}`);
  });
} catch (error) {
  console.error(`Query failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.supportKeys<sup>9+</sup>

supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;): Promise&lt;Array&lt;boolean&gt;&gt;

Checks whether the input device supports the specified keys. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type                | Mandatory| Description                                                  |
| -------- | -------------------- | ---- | ------------------------------------------------------ |
| deviceId | number               | Yes  | ID of the input device. The device ID changes if the same physical device is repeatedly removed and inserted.|
| keys     | Array[&lt;KeyCode&gt;](js-apis-keycode.md#keycode) | Yes  | Keycodes to be queried. A maximum of five keycodes can be specified.               |

**Return value**

| Type                               | Description                           |
| ----------------------------------- | ------------------------------- |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise used to return the result. The value **true** indicates that the keycodes are supported, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Check whether the input device whose ID is 1 supports keycodes 17, 22, and 2055.
try {
  inputDevice.supportKeys(1, [17, 22, 2055]).then((supportResult: Array<Boolean>) => {
    console.log(`Query result: ${JSON.stringify(supportResult)}`);
  });
} catch (error) {
  console.error(`Query failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.supportKeysSync<sup>10+</sup>

supportKeysSync(deviceId: number, keys: Array&lt;KeyCode&gt;): Array&lt;boolean&gt;

Checks whether the input device supports the specified keys.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type                | Mandatory| Description                                                  |
| -------- | -------------------- | ---- | ------------------------------------------------------ |
| deviceId | number               | Yes  | ID of the input device. The device ID changes if the same physical device is repeatedly removed and inserted.|
| keys     | Array[&lt;KeyCode&gt;](js-apis-keycode.md#keycode) | Yes  | Keycodes to be queried. A maximum of five keycodes can be specified.               |

**Return value**

| Type                               | Description                           |
| ----------------------------------- | ------------------------------- |
| Array&lt;boolean&gt; | Result indicating whether the input device supports the keycode value. The value **true** indicates yes, and the value **false** indicates no.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Check whether the input device whose ID is 1 supports keycodes 17, 22, and 2055.
try {
  let supportResult: Array<Boolean> = inputDevice.supportKeysSync(1, [17, 22, 2055])
  console.log(`Query result: ${JSON.stringify(supportResult)}`)
} catch (error) {
  console.error(`Query failed, error: ${JSON.stringify(error, [`code`, `message`])}`)
}
```

## inputDevice.getKeyboardType<sup>9+</sup>

getKeyboardType(deviceId: number, callback: AsyncCallback&lt;KeyboardType&gt;): void

Obtains the keyboard type of an input device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type                                               | Mandatory| Description                                                        |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| deviceId | number                                              | Yes  | Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|
| callback | AsyncCallback&lt;[KeyboardType](#keyboardtype9)&gt; | Yes  | Callback used to return the result.                                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Query the keyboard type of the input device whose ID is 1.
try {
  inputDevice.getKeyboardType(1, (error: Error, type: Number) => {
    if (error) {
      console.error(`Failed to get keyboard type, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard type: ${JSON.stringify(type)}`);
  });
} catch (error) {
  console.error(`Failed to get keyboard type, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getKeyboardType<sup>9+</sup>

getKeyboardType(deviceId: number): Promise&lt;KeyboardType&gt;

Obtains the keyboard type of an input device. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| deviceId | number | Yes  | Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|

**Return value**

| Type                                         | Description                           |
| --------------------------------------------- | ------------------------------- |
| Promise&lt;[KeyboardType](#keyboardtype9)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Query the keyboard type of the input device whose ID is 1.
try {
  inputDevice.getKeyboardType(1).then((type: Number) => {
    console.log(`Keyboard type: ${JSON.stringify(type)}`);
  });
} catch (error) {
  console.error(`Failed to get keyboard type, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.getKeyboardTypeSync<sup>10+</sup>

getKeyboardTypeSync(deviceId: number): KeyboardType

Obtains the keyboard type of the input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| deviceId | number | Yes  | Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|

**Return value**

| Type                                         | Description                           |
| --------------------------------------------- | ------------------------------- |
| [KeyboardType](#keyboardtype9) | Keyboard type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Query the keyboard type of the input device whose ID is 1.
try {
  let type: number = inputDevice.getKeyboardTypeSync(1)
  console.log(`Keyboard type: ${JSON.stringify(type)}`)
} catch (error) {
  console.error(`Failed to get keyboard type, error: ${JSON.stringify(error, [`code`, `message`])}`)
}
```

## inputDevice.isFunctionKeyEnabled<sup>15+</sup>

isFunctionKeyEnabled(functionKey: FunctionKey): Promise&lt;boolean&gt;

Checks whether the function key is enabled. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| functionKey | [FunctionKey](#functionkey15) | Yes  | Type of the function key.|

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the function key is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Input Device Error Codes](errorcode-inputdevice.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 3900002      | There is currently no keyboard device connected. |

**Example**

```js
import { inputDevice } from '@kit.InputKit';

try {
  inputDevice.isFunctionKeyEnabled(inputDevice.FunctionKey.CAPS_LOCK).then((state: boolean) => {
    console.log(`capslock state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`Failed to get capslock state, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDevice.setFunctionKeyEnabled<sup>15+</sup>

setFunctionKeyEnabled(functionKey: FunctionKey, enabled: boolean): Promise&lt;void&gt;

Sets the status of the function key . This API uses a promise to return the result.

**Required permissions**: ohos.permission.INPUT_KEYBOARD_CONTROLLER

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name  | Type   | Mandatory| Description                     |
| -------- | ------- | ---- | ------------------------- |
| functionKey | [FunctionKey](#functionkey15) | Yes  | Type of the function key.|
| enabled  | boolean | Yes  | Status of the function key. The value **true** indicates that the function key is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Input Device Error Codes](errorcode-inputdevice.md).


| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 3900002      | There is currently no keyboard device connected. |
| 3900003      | It is prohibited for non-input applications. |

**Example**

```js
import { inputDevice } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputDevice.setFunctionKeyEnabled(inputDevice.FunctionKey.CAPS_LOCK, true).then(() => {
    console.info(`Set capslock state success`);
  }).catch((error: BusinessError) => {
    console.error(`Set capslock state failed, error=${JSON.stringify(error)}`);
  });
} catch (error) {
    console.error(`Set capslock enable error`);
}
```

## inputDevice.getIntervalSinceLastInput<sup>14+</sup>

getIntervalSinceLastInput(): Promise&lt;number&gt;

Obtains the interval since the last system input event. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Return value**

| Parameters                                         | Description                           |
| --------------------------------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the interval since the last system input event, in μs.|

**Example**

```js
  inputDevice.getIntervalSinceLastInput().then((timeInterval: number) => {
    console.log(`Interval since last input: ${JSON.stringify(timeInterval)}`);
  });
```

## DeviceListener<sup>9+</sup>

Provides hot swap information about an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| type     | [ChangedType](#changedtype9)| Yes| No| Device change type, which indicates whether an input device is inserted or removed.|
| deviceId | number                      | Yes| No| Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|

## InputDeviceData

Provides information about an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| id                   | number                                 | Yes| No| Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|
| name                 | string                                 | Yes| No| Name of the input device.                                            |
| sources              | Array&lt;[SourceType](#sourcetype9)&gt; | Yes| No| Source type of the input device. For example, if a keyboard is attached with a touchpad, the device has two input sources: keyboard and touchpad.|
| axisRanges           | Array&lt;[AxisRange](#axisrange)&gt;  | Yes| No| Axis information of the input device.                                          |
| bus<sup>9+</sup>     | number                                 | Yes| No| Bus type of the input device. By default, the bus type reported by the input device prevails.            |
| product<sup>9+</sup> | number                                 | Yes| No| Product information of the input device.                                        |
| vendor<sup>9+</sup>  | number                                 | Yes| No| Vendor information of the input device.                                        |
| version<sup>9+</sup> | number                                 | Yes| No| Version information of the input device.                                        |
| phys<sup>9+</sup>    | string                                 | Yes| No| Physical address of the input device.                                        |
| uniq<sup>9+</sup>    | string                                 | Yes| No| Unique ID of the input device.                                        |

## AxisType<sup>9+</sup>

type AxisType = 'touchmajor' | 'touchminor' | 'orientation' | 'x' | 'y' | 'pressure' | 'toolminor' | 'toolmajor' | 'null'

Defines the axis type of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Type     |Description     |
| --------- | ------- |
| 'touchmajor'  | Major axis of the elliptical touching area.|
| 'touchminor'  | Minor axis of the elliptical touching area.|
| 'toolminor'   | Minor axis of the tool area.|
| 'toolmajor'   | Major axis of the tool area.|
| 'orientation' | Orientation axis.|
|'pressure'    | Pressure axis. |
| 'x'          | Horizontal axis.        |
| 'y'           | Vertical axis.        |
|'null'        |  None.            |

## AxisRange

Defines the axis range of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| source                  | [SourceType](#sourcetype9) | Yes| No| Input source type of the axis.|
| axis                    | [AxisType](#axistype9)    | Yes| No| Axis type.   |
| max                     | number                    | Yes| No| Maximum value of the axis.  |
| min                     | number                    | Yes| No| Minimum value of the axis.  |
| fuzz<sup>9+</sup>       | number                    | Yes| No| Fuzzy value of the axis.  |
| flat<sup>9+</sup>       | number                    | Yes| No| Benchmark value of the axis.  |
| resolution<sup>9+</sup> | number                    | Yes| No| Resolution of the axis.  |

## SourceType<sup>9+</sup>

type SourceType = 'keyboard' | 'mouse' | 'touchpad' | 'touchscreen' | 'joystick' | 'trackball'

Enumerates input source types of the axis. For example, if a mouse reports an x-axis event, the input source of the x-axis is the mouse.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Type      |Description     |
| --------- |  ------- |
| 'keyboard'    | The input device is a keyboard. |
| 'touchscreen' | The input device is a touchscreen.|
| 'mouse'       | The input device is a mouse. |
| 'trackball'   | The input device is a trackball.|
| 'touchpad'    | The input device is a touchpad.|
| 'joystick'   | The input device is a joystick.|

## ChangedType<sup>9+</sup>

type ChangedType = 'add' | 'remove'

Enumerates hot swap events.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Type       | Description     |
| --------- | ------- |
| 'add'    | Device insertion.|
| 'remove' | Device removal.|

## KeyboardType<sup>9+</sup>

Enumerates keyboard types.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name                 | Value   | Description       |
| ------------------- | ---- | --------- |
| NONE                | 0    | Keyboard without keys. |
| UNKNOWN             | 1    | Keyboard with unknown keys.|
| ALPHABETIC_KEYBOARD | 2    | Full keyboard. |
| DIGITAL_KEYBOARD    | 3    | Keypad. |
| HANDWRITING_PEN     | 4    | Stylus. |
| REMOTE_CONTROL      | 5    | Remote control. |

## FunctionKey<sup>15+</sup>

Enumerates function key types.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name                 | Value   | Description       |
| ------------------- | ---- | --------- |
| CAPS_LOCK                | 1    | CapsLock key. This key can be enabled or disabled only for the input keyboard extension.|
