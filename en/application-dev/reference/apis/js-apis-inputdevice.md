# Input Device


The Input Device module implements listening for connection, disconnection, and update events of input devices and displays information about input devices. For example, it can be used to listen for mouse insertion and removal and obtain information such as the ID, name, and pointer speed of the mouse.


> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import inputDevice from '@ohos.multimodalInput.inputDevice';
```

## inputDevice.on<sup>9+</sup>

on(type: "change", listener: Callback&lt;DeviceListener&gt;): void

Enables listening for hot swap events of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| type     | string                                   | Yes   | Event type of the input device. |
| listener | Callback&lt;[DeviceListener](#devicelistener9)&gt; | Yes   | Listener for events of the input device.|

**Example**

```js
let isPhysicalKeyboardExist = true;
inputDevice.on("change", (data) => {
    console.log("type: " + data.type + ", deviceId: " + data.deviceId);
    inputDevice.getKeyboardType(data.deviceId, (err, ret) => {
        console.log("The keyboard type of the device is: " + ret);
        if (ret == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD && data.type == 'add') {
            // The physical keyboard is connected.
            isPhysicalKeyboardExist = true;
        } else if (ret == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD && data.type == 'remove') {
            // The physical keyboard is disconnected.
            isPhysicalKeyboardExist = false;
        }
    });
});
// Check whether the soft keyboard is open based on the value of isPhysicalKeyboardExist.
```

## inputDevice.off<sup>9+</sup>

off(type: "change", listener?: Callback&lt;DeviceListener&gt;): void

Disables listening for hot swap events of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| type     | string                                   | Yes   | Event type of the input device. |
| listener | Callback&lt;[DeviceListener](#devicelistener9)&gt; | No   | Listener for events of the input device.|

**Example**

```js
function listener(data) {
    console.log("type: " + data.type + ", deviceId: " + data.deviceId);
}

// Enable listening for hot swap events of an input device.
inputDevice.on("change", listener);

// Disable this listener.
inputDevice.off("change", listener);

// Disable all listeners.
inputDevice.off("change");
// By default, the soft keyboard is closed when listening is disabled.
```

## inputDevice.getDeviceIds

getDeviceIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the IDs of all input devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                                      | Mandatory  | Description   |
| -------- | ---------------------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes   | Callback used to return the result.|

**Example**

```js
inputDevice.getDeviceIds((ids)=>{
    console.log("The device ID list is: " + ids);
});
```

## inputDevice.getDeviceIds

getDeviceIds(): Promise&lt;Array&lt;number&gt;&gt;

Obtains the IDs of all input devices. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Return value**

| Parameter                                | Description                 |
| ---------------------------------- | ------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the result.|

**Example**

```js
inputDevice.getDeviceIds().then((ids)=>{
    console.log("The device ID list is: " + ids);
});
```

## inputDevice.getDevice

getDevice(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void

Obtains information about an input device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                                      | Mandatory  | Description                         |
| -------- | ---------------------------------------- | ---- | --------------------------- |
| deviceId | number                                   | Yes   | ID of the input device.               |
| callback | AsyncCallback&lt;[InputDeviceData](#inputdevicedata)&gt; | Yes   | Callback used to return the result, which is an **InputDeviceData** object.|

**Example**

```js
// Obtain the name of the device whose ID is 1.
inputDevice.getDevice(1, (inputDevice)=>{
    console.log("The device name is: " + inputDevice.name);
});
```

## inputDevice.getDevice

getDevice(deviceId: number): Promise&lt;InputDeviceData&gt;

Obtains information about an input device. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type    | Mandatory  | Description          |
| -------- | ------ | ---- | ------------ |
| deviceId | number | Yes   | ID of the input device.|

**Return value**

| Parameter                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[InputDeviceData](#inputdevicedata)&gt; | Promise used to return the result.|

**Example**

```js
// Obtain the name of the device whose ID is 1.
inputDevice.getDevice(1).then((inputDevice)=>{
    console.log("The device name is: " + inputDevice.name);
});
```

## inputDevice.supportKeys<sup>9+</sup>

supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: Callback&lt;Array&lt;boolean&gt;&gt;): void

Obtains the key codes supported by the input device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                                  | Mandatory  | Description                               |
| -------- | ------------------------------------ | ---- | --------------------------------- |
| deviceId | number                               | Yes   | Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|
| keys     | Array&lt;KeyCode&gt;                 | Yes   | Key codes to be queried. A maximum of five key codes can be specified.             |
| callback | Callback&lt;Array&lt;boolean&gt;&gt; | Yes   | Callback used to return the result.                   |

**Example**

```js
// Check whether the input device whose ID is 1 supports key codes 17, 22, and 2055.
inputDevice.supportKeys(1, [17, 22, 2055], (ret)=>{
    console.log("The query result is as follows: " + ret);
});
```

## inputDevice.supportKeys<sup>9+</sup>

supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;): Promise&lt;Array&lt;boolean&gt;&gt;

Obtains the key codes supported by the input device. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                  | Mandatory  | Description                               |
| -------- | -------------------- | ---- | --------------------------------- |
| deviceId | number               | Yes   | Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|
| keys     | Array&lt;KeyCode&gt; | Yes   | Key codes to be queried. A maximum of five key codes can be specified.             |

**Return value**

| Parameter                                 | Description                 |
| ----------------------------------- | ------------------- |
| Promise&lt;Array&lt;boolean&gt;&gt; | Promise used to return the result.|

**Example**

```js
// Check whether the input device whose ID is 1 supports key codes 17, 22, and 2055.
inputDevice.supportKeys(1, [17, 22, 2055]).then((ret)=>{
    console.log("The query result is as follows: " + ret);
})
```

## inputDevice.getKeyboardType<sup>9+</sup>

getKeyboardType(deviceId: number, callback: AsyncCallback&lt;KeyboardType&gt;): void

Obtains the keyboard type of an input device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Parameters**

| Name      | Type                                      | Mandatory  | Description                               |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| deviceId | number                                   | Yes   | Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|
| callback | AsyncCallback&lt;[KeyboardType](#keyboardtype9)&gt; | Yes   | Callback used to return the result.                   |

**Example**

```js
// Query the keyboard type of the input device whose ID is 1.
inputDevice.getKeyboardType(1, (ret)=>{
    console.log("The keyboard type of the device is: " + ret);
});
```

## inputDevice.getKeyboardType<sup>9+</sup>

getKeyboardType(deviceId: number,): Promise&lt;KeyboardType&gt;

Obtains the keyboard type of an input device. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

**Return value**

| Parameter                                      | Description                 |
| ---------------------------------------- | ------------------- |
| Promise&lt;[KeyboardType](#keyboardtype9)&gt; | Promise used to return the result.|

**Example**

```js
// Query the keyboard type of the input device whose ID is 1.
inputDevice.getKeyboardType(1).then((ret)=>{
    console.log("The keyboard type of the device is: " + ret);
})
```

## DeviceListener<sup>9+</sup>

Defines the information about an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name      | Type                     | Description                               |
| -------- | ------------------------- | --------------------------------- |
| type     | [ChangedType](#changedtype) | Device change type, which indicates whether an input device is inserted or removed.                    |
| deviceId | number                    | Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.|

## InputDeviceData

Defines the information about an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name                  | Type                                  | Description                                      |
| -------------------- | -------------------------------------- | ---------------------------------------- |
| id                   | number                                 | Unique ID of the input device. If the same physical device is repeatedly inserted and removed, its ID changes.       |
| name                 | string                                 | Name of the input device.                                |
| sources              | Array&lt;[SourceType](#sourcetype)&gt; | Source type of the input device. For example, if a keyboard is attached with a touchpad, the device has two input sources: keyboard and touchpad.|
| axisRanges           | Array&lt;[axisRanges](#axisrange)&gt;  | Axis information of the input device.                               |
| bus<sup>9+</sup>     | number                                 | Bus type of the input device.                              |
| product<sup>9+</sup> | number                                 | Product information of the input device.                              |
| vendor<sup>9+</sup>  | number                                 | Vendor information of the input device.                              |
| version<sup>9+</sup> | number                                 | Version information of the input device.                              |
| phys<sup>9+</sup>    | string                                 | Physical address of the input device.                              |
| uniq<sup>9+</sup>    | string                                 | Unique ID of the input device.                              |

## AxisType<sup>9+</sup>

Defines the axis type of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name         | Type  | Description             |
| ----------- | ------ | --------------- |
| touchMajor  | string | touchMajor axis. |
| touchMinor  | string | touchMinor axis. |
| toolMinor   | string | toolMinor axis.  |
| toolMajor   | string | toolMajor axis.  |
| orientation | string | Orientation axis.|
| pressure    | string | Pressure axis.   |
| x           | string | X axis.          |
| y           | string | Y axis.          |
| NULL        | string | None.             |

## AxisRange

Defines the axis range of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name                     | Type                     | Description      |
| ----------------------- | ------------------------- | -------- |
| source                  | [SourceType](#sourcetype) | Input source type of the axis.|
| axis                    | [AxisType](#axistype9)      | Axis type.   |
| max                     | number                    | Maximum value of the axis.  |
| min                     | number                    | Minimum value of the axis.  |
| fuzz<sup>9+</sup>       | number                    | Fuzzy value of the axis.  |
| flat<sup>9+</sup>       | number                    | Benchmark value of the axis.  |
| resolution<sup>9+</sup> | number                    | Resolution of the axis.  |

## SourceType

Enumerates the input source types. For example, if a mouse reports an x-axis event, the source of the x-axis is the mouse.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name         | Type  | Description         |
| ----------- | ------ | ----------- |
| keyboard    | string | The input device is a keyboard. |
| touchscreen | string | The input device is a touchscreen.|
| mouse       | string | The input device is a mouse. |
| trackball   | string | The input device is a trackball.|
| touchpad    | string | The input device is a touchpad.|
| joystick    | string | The input device is a joystick.|

## ChangedType

Defines the change type for the hot swap event of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name    | Type  | Description       |
| ------ | ------ | --------- |
| add    | string | An input device is inserted.|
| remove | string | An input device is removed.|

## KeyboardType<sup>9+</sup>

Enumerates the keyboard types.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

| Name                 | Type  | Value   | Description       |
| ------------------- | ------ | ---- | --------- |
| NONE                | number | 0    | Keyboard without keys. |
| UNKNOWN             | number | 1    | Keyboard with unknown keys.|
| ALPHABETIC_KEYBOARD | number | 2    | Full keyboard. |
| DIGITAL_KEYBOARD    | number | 3    | Keypad. |
| HANDWRITING_PEN     | number | 4    | Stylus. |
| REMOTE_CONTROL      | number | 5    | Remote control. |
