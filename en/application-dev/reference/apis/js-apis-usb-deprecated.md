# USB

The USB module provides USB device management functions, including USB device list query, bulk data transfer, control transfer, and permission control.

>  **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import usb from "@ohos.usb";
```

## usb.getDevices

getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;

Obtains the USB device list.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                                                  | Description     |
| ---------------------------------------------------- | ------- |
| Array&lt;Readonly&lt;[USBDevice](#usbdevice)&gt;&gt; | Device information list.|

**Example**

```js
let devicesList = usb.getDevices();
console.log(`devicesList = ${JSON.stringify(devicesList)}`);
// devicesList is a list of USB devices.
// A simple example of devicesList is provided as follows:
[
  {
    name: "1-1",
    serial: "",
    manufacturerName: "",
    productName: "",
    version: "",
    vendorId: 7531,
    productId: 2,
    clazz: 9,
    subclass: 0,
    protocol: 1,
    devAddress: 1,
    busNum: 1,
    configs: [
      {
        id: 1,
        attributes: 224,
        isRemoteWakeup: true,
        isSelfPowered: true,
        maxPower: 0,
        name: "1-1",
        interfaces: [
          {
            id: 0,
            protocol: 0,
            clazz: 9,
            subclass: 0,
            alternateSetting: 0,
            name: "1-1",
            endpoints: [
              {
                address: 129,
                attributes: 3,
                interval: 12,
                maxPacketSize: 4,
                direction: 128,
                number: 1,
                type: 3,
                interfaceId: 0,
              },
            ],
          },
        ],
      },
    ],
  },
]
```

## usb.connectDevice

connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt;

Connects to a USB device.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, and then call [usb.requestRight](#usbrequestright) to request the device access permission.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| device | [USBDevice](#usbdevice) | Yes| USB device information.|

**Return value**

| Type| Description|
| -------- | -------- |
| Readonly&lt;[USBDevicePipe](#usbdevicepipe)&gt; | USB device pipe for data transfer.|

**Example**

```js
let devicepipe= usb.connectDevice(device);
console.log(`devicepipe = ${JSON.stringify(devicepipe)}`);
```

## usb.hasRight

hasRight(deviceName: string): boolean

Checks whether the application has the permission to access the device.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Yes| Device name.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | The value **true** indicates that the application has the permission to access the device, and the value **false** indicates the opposite.|

**Example**

```js
let devicesName="1-1";
let bool = usb.hasRight(devicesName);
console.log(bool);
```

## usb.requestRight

requestRight(deviceName: string): Promise&lt;boolean&gt;

Requests the temporary permission for the application to access the USB device. This API uses a promise to return the result.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Yes| Device name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the temporary device access permissions are granted, and the value **false** indicates the opposite.|

**Example**

```js
let devicesName="1-1";
usb.requestRight(devicesName).then((ret) => {
  console.log(`requestRight = ${JSON.stringify(ret)}`);
});
```

## usb.claimInterface

claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number

Claims a USB interface.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and USB interfaces, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address.|
| iface | [USBInterface](#usbinterface) | Yes| USB interface, which is used to determine the index of the interface to claim.|
| force | boolean | No| Whether to forcibly claim the USB interface. The default value is **false**, indicating not to forcibly claim the USB interface.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | The value **0** indicates that the USB interface is successfully claimed, and an error code indicates the opposite.|

**Example**

```js
let ret = usb.claimInterface(devicepipe, interfaces);
console.log(`claimInterface = ${ret}`);
```

## usb.releaseInterface

releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number

Releases a USB interface.

Before you do this, ensure that you have claimed the interface by calling [usb.claimInterface](#usbclaiminterface).

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address.|
| iface | [USBInterface](#usbinterface) | Yes| USB interface, which is used to determine the index of the interface to release.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | The value **0** indicates that the USB interface is successfully released, and an error code indicates the opposite.|

**Example**

```js
let ret = usb.releaseInterface(devicepipe, interfaces);
console.log(`releaseInterface = ${ret}`);
```

## usb.setConfiguration

setConfiguration(pipe: USBDevicePipe, config: USBConfig): number

Sets the device configuration.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and device configuration, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address.|
| config | [USBConfig](#usbconfig) | Yes| USB configuration to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | The value **0** indicates that the USB configuration is successfully set, and an error code indicates the opposite.|

**Example**

```js
let ret = usb.setConfiguration(devicepipe, config);
console.log(`setConfiguration = ${ret}`);
```

## usb.setInterface

setInterface(pipe: USBDevicePipe, iface: USBInterface): number

Sets a USB interface.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and interfaces, call [usb.requestRight](#usbrequestright) to request the device access permission, call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter, and call [usb.claimInterface](#usbclaiminterface) to claim the USB interface.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name  | Type                             | Mandatory | Description           |
| ----- | ------------------------------- | --- | ------------- |
| pipe  | [USBDevicePipe](#usbdevicepipe) | Yes  | Device pipe, which is used to determine the bus number and device address.|
| iface | [USBInterface](#usbinterface)   | Yes  | USB interface to set. |

**Return value**

| Type| Description|
| -------- | -------- |
| number | The value **0** indicates that the USB interface is successfully set, and an error code indicates the opposite.|

**Example**

```js
let ret = usb.setInterface(devicepipe, interfaces);
console.log(`setInterface = ${ret}`);
```

## usb.getRawDescriptor

getRawDescriptor(pipe: USBDevicePipe): Uint8Array

Obtains the raw USB descriptor.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address.|

**Return value**

| Type| Description|
| -------- | -------- |
| Uint8Array | The return value is the raw USB descriptor if the operation is successful, or **undefined** if the operation has failed.|

**Example**

```js
let ret = usb.getRawDescriptor(devicepipe);
```

## usb.getFileDescriptor

getFileDescriptor(pipe: USBDevicePipe): number

Obtains the file descriptor.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address.|

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | The return value is the file descriptor of the USB device if the operation is successful, or **-1** if the operation has failed.|

**Example**

```js
let ret = usb.getFileDescriptor(devicepipe);
```

## usb.controlTransfer

controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise&lt;number&gt;

Performs control transfer.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the USB device.|
| contrlparam | [USBControlParams](#usbcontrolparams) | Yes| Control transfer parameters.|
| timeout | number | No| Timeout duration in ms. This parameter is optional. The default value is **0**, indicating no timeout.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result, which is the size of the transmitted or received data block if the transfer is successful, or **-1** if an exception has occurred.|

**Example**

```js
usb.controlTransfer(devicepipe, USBControlParams).then((ret) => {
 console.log(`controlTransfer = ${JSON.stringify(ret)}`);
})
```

## usb.bulkTransfer

bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt;

Performs bulk transfer.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and endpoints, call [usb.requestRight](#usbrequestright) to request the device access permission, call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter, and call [usb.claimInterface](#usbclaiminterface) to claim the USB interface.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the USB device.|
| endpoint | [USBEndpoint](#usbendpoint) | Yes| USB endpoint, which is used to determine the USB port for data transfer.|
| buffer | Uint8Array | Yes| Buffer for writing or reading data.|
| timeout | number | No| Timeout duration in ms. This parameter is optional. The default value is **0**, indicating no timeout.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result, which is the size of the transmitted or received data block if the transfer is successful, or **-1** if an exception has occurred.|

**Example**

```js
// Call usb.getDevices to obtain a data set. Then, obtain a USB device and its access permission.
// Pass the obtained USB device as a parameter to usb.connectDevice. Then, call usb.connectDevice to connect the USB device.
// Call usb.claimInterface to claim the USB interface. After that, call usb.bulkTransfer to start bulk transfer.
usb.bulkTransfer(devicepipe, endpoint, buffer).then((ret) => {
 console.log(`bulkTransfer = ${JSON.stringify(ret)}`);
});
```

## usb.closePipe

closePipe(pipe: USBDevicePipe): number

Closes a USB device pipe.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | The value **0** indicates that the USB device pipe is closed successfully, and an error code indicates the opposite.|

**Example**

```js
let ret = usb.closePipe(devicepipe);
console.log(`closePipe = ${ret}`);
```

## usb.usbFunctionsFromString<sup>9+</sup>

usbFunctionsFromString(funcs: string): number

Converts the USB function list in the string format to a numeric mask in Device mode.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| funcs  | string | Yes  | Function list in string format.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Function list in numeric mask format.|

**Example**

```js
let funcs = "acm";
let ret = usb.usbFunctionsFromString(funcs);
```

## usb.usbFunctionsToString<sup>9+</sup>

usbFunctionsToString(funcs: FunctionType): string

Converts the USB function list in the numeric mask format to a string in Device mode.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                          | Mandatory| Description             |
| ------ | ------------------------------ | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype9) | Yes  | USB function list in numeric mask format.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| string | Function list in string format.|

**Example**

```js
let funcs = ACM | ECM;
let ret = usb.usbFunctionsToString(funcs);
```

## usb.setCurrentFunctions<sup>9+</sup>

setCurrentFunctions(funcs: FunctionType): Promise\<boolean\>

Sets the current USB function list in Device mode.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                          | Mandatory| Description             |
| ------ | ------------------------------ | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype9) | Yes  | USB function list in numeric mask format.|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Example**

```js
let funcs = HDC;
let ret = usb.setCurrentFunctions(funcs);
```

## usb.getCurrentFunctions<sup>9+</sup>

getCurrentFunctions(): FunctionType

Obtains the numeric mask combination for the USB function list in Device mode.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                          | Description                             |
| ------------------------------ | --------------------------------- |
| [FunctionType](#functiontype9) | Numeric mask combination for the USB function list.|

**Example**

```js
let ret = usb.getCurrentFunctions();
```

## usb.getPorts<sup>9+</sup>

getPorts(): Array\<USBPort\>

Obtains the list of all physical USB ports.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                         | Description                 |
| ----------------------------- | --------------------- |
| [Array\<USBPort\>](#usbport9) | List of physical USB ports.|

**Example**

```js
let ret = usb.getPorts();
```

## usb.getSupportedModes<sup>9+</sup>

getSupportedModes(portId: number): PortModeType

Obtains the mask combination for the supported mode list of a given USB port.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| portId | number | Yes  | Port number.|

**Return value**

| Type                          | Description                      |
| ------------------------------ | -------------------------- |
| [PortModeType](#portmodetype9) | Mask combination for the supported mode list.|

**Example**

```js
let ret = usb.getSupportedModes(0);
```

## usb.setPortRoles<sup>9+</sup>

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean\>

Sets the role types supported by a specified port, which can be **powerRole** (for charging) and **dataRole** (for data transfer).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type                            | Mandatory| Description            |
| --------- | -------------------------------- | ---- | ---------------- |
| portId    | number                           | Yes  | Port number.        |
| powerRole | [PowerRoleType](#powerroletype9) | Yes  | Role for charging.    |
| dataRole  | [DataRoleType](#dataroletype9)   | Yes  | Role for data transfer.|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Example**

```js
let ret = usb.getSupportedModes(0);
```

## USBEndpoint

Represents the USB endpoint from which data is sent or received. You can obtain the USB endpoint through [USBInterface](#usbinterface).

**System capability**: SystemCapability.USB.USBManager

| Name           | Type                                       | Description           |
| ------------- | ------------------------------------------- | ------------- |
| address       | number                                      | Endpoint address.        |
| attributes    | number                                      | Endpoint attributes.        |
| interval      | number                                      | Endpoint interval.        |
| maxPacketSize | number                                      | Maximum size of data packets on the endpoint.   |
| direction     | [USBRequestDirection](#usbrequestdirection) | Endpoint direction.       |
| number        | number                                      | Endpoint number.         |
| type          | number                                      | Endpoint type.        |
| interfaceId   | number                                      | Unique ID of the interface to which the endpoint belongs.|

## USBInterface

Represents a USB interface. One [USBConfig](#usbconfig) can contain multiple **USBInterface** instances, each providing a specific function.

**System capability**: SystemCapability.USB.USBManager

| Name              | Type                                    | Description                   |
| ---------------- | ---------------------------------------- | --------------------- |
| id               | number                                   | Unique ID of the USB interface.             |
| protocol         | number                                   | Interface protocol.               |
| clazz            | number                                   | Device type.                |
| subClass         | number                                   | Device subclass.                |
| alternateSetting | number                                   | Settings for alternating between descriptors of the same USB interface.|
| name             | string                                   | Interface name.                |
| endpoints        | Array&lt;[USBEndpoint](#usbendpoint)&gt; | Endpoints that belong to the USB interface.          |

## USBConfig

Represents the USB configuration. One [USBDevice](#usbdevice) can contain multiple **USBConfig** instances.

**System capability**: SystemCapability.USB.USBManager

| Name            | Type                                            | Description             |
| -------------- | ------------------------------------------------ | --------------- |
| id             | number                                           | Unique ID of the USB configuration.       |
| attributes     | number                                           | Configuration attributes.         |
| maxPower       | number                                           | Maximum power consumption, in mA.   |
| name           | string                                           | Configuration name, which can be left empty.    |
| isRemoteWakeup | boolean                                          | Support for remote wakeup.|
| isSelfPowered  | boolean                                          | Support for independent power supplies.|
| interfaces     | Array&nbsp;&lt;[USBInterface](#usbinterface)&gt; | Supported interface attributes.     |

## USBDevice

Represents the USB device information.

**System capability**: SystemCapability.USB.USBManager

| Name              | Type                                | Description        |
| ---------------- | ------------------------------------ | ---------- |
| busNum           | number                               | Bus address.     |
| devAddress       | number                               | Device address.     |
| serial           | string                               | Sequence number.      |
| name             | string                               | Device name.     |
| manufacturerName | string                               | Device manufacturer.     |
| productName      | string                               | Product name.     |
| version          | string                               | Version number.       |
| vendorId         | number                               | Vendor ID.     |
| productId        | number                               | Product ID.     |
| clazz            | number                               | Device class.      |
| subClass         | number                               | Device subclass.     |
| protocol         | number                               | Device protocol code.    |
| configs          | Array&lt;[USBConfig](#usbconfig)&gt; | Device configuration descriptor information.|

## USBDevicePipe

Represents a USB device pipe, which is used to determine a USB device.

**System capability**: SystemCapability.USB.USBManager

| Name        | Type  | Description   |
| ---------- | ------ | ----- |
| busNum     | number | Bus address.|
| devAddress | number | Device address.|

## USBControlParams

Represents control transfer parameters.

**System capability**: SystemCapability.USB.USBManager

| Name     | Type                                           | Description              |
| ------- | ----------------------------------------------- | ---------------- |
| request | number                                          | Request type.           |
| target  | [USBRequestTargetType](#usbrequesttargettype)   | Request target type.         |
| reqType | [USBControlRequestType](#usbcontrolrequesttype) | Control request type.         |
| value   | number                                          | Request parameter value.           |
| index   | number                                          | Index of the request parameter value.|
| data    | Uint8Array                                      | Buffer for writing or reading data.    |

## USBPort<sup>9+</sup>

Represents a USB port.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name          | Type                        | Description                               |
| -------------- | -------------------------------- | ----------------------------------- |
| id             | number                           | Unique identifier of a USB port.                  |
| supportedModes | [PortModeType](#portmodetype9)   | Numeric mask combination for the supported mode list.|
| status         | [USBPortStatus](#usbportstatus9) | USB port role.                      |

## USBPortStatus<sup>9+</sup>

Enumerates USB port roles.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name            | Type| Description                  |
| ---------------- | -------- | ---------------------- |
| currentMode      | number   | Current USB mode.       |
| currentPowerRole | number   | Current power role.    |
| currentDataRole  | number   | Current data role.|

## USBRequestTargetType

Enumerates request target types.

**System capability**: SystemCapability.USB.USBManager

| Name                        | Value  | Description  |
| ---------------------------- | ---- | ------ |
| USB_REQUEST_TARGET_DEVICE    | 0    | Device.|
| USB_REQUEST_TARGET_INTERFACE | 1    | Interface.|
| USB_REQUEST_TARGET_ENDPOINT  | 2    | Endpoint.|
| USB_REQUEST_TARGET_OTHER     | 3    | Other.|

## USBControlRequestType

Enumerates control request types.

**System capability**: SystemCapability.USB.USBManager

| Name                     | Value  | Description  |
| ------------------------- | ---- | ------ |
| USB_REQUEST_TYPE_STANDARD | 0    | Standard.|
| USB_REQUEST_TYPE_CLASS    | 1    | Class.  |
| USB_REQUEST_TYPE_VENDOR   | 2    | Vendor.|

## USBRequestDirection

Enumerates request directions.

**System capability**: SystemCapability.USB.USBManager

| Name                       | Value  | Description                    |
| --------------------------- | ---- | ------------------------ |
| USB_REQUEST_DIR_TO_DEVICE   | 0    | Request for writing data from the host to the device.|
| USB_REQUEST_DIR_FROM_DEVICE | 0x80 | Request for reading data from the device to the host.|

## FunctionType<sup>9+</sup>

Enumerates USB device function types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name        | Value  | Description      |
| ------------ | ---- | ---------- |
| NONE         | 0    | No function.|
| ACM          | 1    | ACM function. |
| ECM          | 2    | ECM function. |
| HDC          | 4    | HDC function. |
| MTP          | 8    | Not supported currently.|
| PTP          | 16   | Not supported currently.|
| RNDIS        | 32   | Not supported currently.|
| MIDI         | 64   | Not supported currently.|
| AUDIO_SOURCE | 128  | Not supported currently.|
| NCM          | 256  | Not supported currently.|

## PortModeType<sup>9+</sup>

Enumerates USB port mode types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name     | Value  | Description                                                |
| --------- | ---- | ---------------------------------------------------- |
| NONE      | 0    | None.                                                |
| UFP       | 1    | Upstream facing port, which functions as the sink of power supply.                            |
| DFP       | 2    | Downstream facing port, which functions as the source of power supply.                            |
| DRP       | 3    | Dynamic reconfiguration port (DRP), which can function as the DFP (host) or UFP (device). It is not supported currently.|
| NUM_MODES | 4    | Not supported currently.                                        |

## PowerRoleType<sup>9+</sup>

Enumerates power role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value  | Description      |
| ------ | ---- | ---------- |
| NONE   | 0    | None.      |
| SOURCE | 1    | External power supply.|
| SINK   | 2    | Internal power supply.|

## DataRoleType<sup>9+</sup>

Enumerates data role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value  | Description        |
| ------ | ---- | ------------ |
| NONE   | 0    | None.        |
| HOST   | 1    | USB host.|
| DEVICE | 2    | USB device.|
