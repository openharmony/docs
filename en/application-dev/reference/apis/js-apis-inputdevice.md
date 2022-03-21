# Input Device


The input device management module is used to listen for the connection, disconnection, and updates of input devices and display information about input devices. For example, it can be used to listen for mouse insertion and removal and obtain information such as the ID, name, and pointer speed of the mouse.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import inputDevice from '@ohos.multimodalInput.inputDevice';
```


## inputDevice.getDeviceIds

getDeviceIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the IDs of all input devices. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

  **Parameters**
  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes | Callback used to return the result. | 

  **Example**

```
data: {
    deviceIds: Array,
},
callback: function(ids) {
    this.deviceIds = ids;
},
testGetDeviceIds: function () {
    console.info("InputDeviceJsTest---start---testGetDeviceIds");
    inputDevice.getDeviceIds(this.callback);
    console.info("InputDeviceJsTest---end---testGetDeviceIds");
}
```


## inputDevice.getDevice

getDevice(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void

Obtains the information about an input device. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

  **Parameters**
  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| deviceId | number | Yes | ID of the input device whose information is to be obtained. | 
| callback | AsyncCallback&lt;[InputDeviceData](#inputdevicedata)&gt; | Yes | Callback used to return the **InputDeviceData** object. | 

  **Example**

```
InputDeviceData {
    deviceId : 0,
    name : "NA",
    sources : Array,
    axisRanges : Array,
},
callback: function(deviceData) {
    this.InputDeviceData = deviceData;
},
testGetDevice: function () {
    // The example is used to obtain the information about the device whose ID is 1.
    console.info("InputDeviceJsTest---start---testGetDevice");
    inputDevice.getDevice(1, this.callback);
    console.info("InputDeviceJsTest---end---testGetDevice");
}
```


## InputDeviceData

Defines the information about an input device.

  **System capability**: SystemCapability.MultimodalInput.Input.InputDevice
  | Name | Type | Description | 
| -------- | -------- | -------- |
| id | number | Unique identifier of an input device. If the same physical device is repeatedly inserted and removed, its ID changes. | 
| name | string | Name of the input device. | 
| sources | Array&lt;[SourceType](#sourcetype)&gt; | Source types of the input device. For example, if a keyboard is attached with a touchpad, the device has two input sources: keyboard and touchpad. |


## SourceType

Enumerates the input source types.

**System capability**: SystemCapability.MultimodalInput.Input.InputDevice

  | Name | Type | Description | 
| -------- | -------- | -------- |
| keyboard | string | The input device is a keyboard. |
| touchscreen | string | The input device is a touchscreen. | 
| mouse | string | The input device is a mouse. |
| trackball | string | The input device is a trackball. |
| touchpad | string | The input device is a touchpad. |
| joystick | string | The input device is a joystick. |
