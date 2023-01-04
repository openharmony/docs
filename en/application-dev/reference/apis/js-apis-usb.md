# USB

The USB module provides USB device management functions, including USB device list query, bulk data transfer, control transfer, and permission control on the host side as well as port management, and function switch and query on the device side.

>  **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import usb from "@ohos.usbV9";
```

## usb.getDevices

getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;

Obtains the list of USB devices connected to the host. If no device is connected, an empty list is returned.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                                                  | Description     |
| ---------------------------------------------------- | ------- |
| Array&lt;Readonly&lt;[USBDevice](#usbdevice)&gt;&gt; | USB device list.|

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

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and device information, and then call [usb.requestRight](#usbrequestright) to request the device access permission.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| device | [USBDevice](#usbdevice) | Yes| USB device information.|

**Return value**

| Type| Description|
| -------- | -------- |
| Readonly&lt;[USBDevicePipe](#usbdevicepipe)&gt; | USB device pipe for data transfer.|

**Error codes**

For details about the error codes, see [USB Error Codes](../errorcodes/errorcode-usb.md).

| ID| Error Message|
| -------- | -------- |
| 14400001 |Permission denied. Need call requestRight to get permission. |

**Example**

```js
let devicesList = usb.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
  return;
}

let device = devicesList[0];
usb.requestRight(device.name);
let devicepipe = usb.connectDevice(device);
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
| boolean | Returns **true** if the application has the permission to access the device; returns **false** otherwise.|

**Example**

```js
let devicesName="1-1";
let bool = usb.hasRight(devicesName);
console.log(bool);
```

## usb.requestRight

requestRight(deviceName: string): Promise&lt;boolean&gt;

Requests the temporary permission for the application to access a USB device. This API uses a promise to return the result.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Yes| Device name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the temporary device access permissions are granted; and the value **false** indicates the opposite.|

**Example**

```js
let devicesName="1-1";
usb.requestRight(devicesName).then((ret) => {
  console.log(`requestRight = ${JSON.stringify(ret)}`);
});
```

## usb.removeRight

removeRight(deviceName: string): boolean;

Removes the permission for the application to access a USB device.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Yes| Device name.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Permission removal result. The value **true** indicates that the access permission is removed successfully; and the value **false** indicates the opposite.|

**Example**

```js
let devicesName="1-1";
if (usb.removeRight(devicesName) {
  console.log(`Succeed in removing right`);
}
```

## usb.addRight

addRight(bundleName: string, deviceName: string): boolean;

Adds the permission for the application to access a USB device.

[requestRight](#usbrequestright) triggers a dialog box to request for user authorization, whereas **addRight** adds the access permission directly without displaying a dialog box. 

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Yes| Device name.|
| bundleName | string | Yes| Bundle name of the application.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Permission addition result. The value **true** indicates that the access permission is added successfully; and the value **false** indicates the opposite.|

**Example**

```js
let devicesName = "1-1";
let bundleName = "com.example.hello";
if (usb.addRight(bundleName, devicesName) {
  console.log(`Succeed in adding right`);
}
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
| number | Returns **0** if the USB interface is successfully claimed; returns an error code otherwise.|

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
| number | Returns **0** if the USB interface is successfully released; returns an error code otherwise.|

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
| number | Returns **0** if the USB configuration is successfully set; returns an error code otherwise.|

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
| number | Returns **0** if the USB interface is successfully set; returns an error code otherwise.|

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
| Uint8Array | Returns the raw USB descriptor if the operation is successful; returns **undefined** otherwise.|

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
| number | Returns the file descriptor of the USB device if the operation is successful; returns **-1** otherwise.|

**Example**

```js
let ret = usb.getFileDescriptor(devicepipe);
```

## usb.controlTransfer

controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise&lt;number&gt;

Performs control transfer.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the USB device.|
| controlparam | [USBControlParams](#usbcontrolparams) | Yes| Control transfer parameters.|
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
| number | Returns **0** if the USB device pipe is closed successfully; returns an error code otherwise.|

**Example**

```js
let ret = usb.closePipe(devicepipe);
console.log(`closePipe = ${ret}`);
```

## usb.usbFunctionsFromString

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

## usb.usbFunctionsToString

usbFunctionsToString(funcs: FunctionType): string

Converts the USB function list in the numeric mask format to a string in Device mode.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                          | Mandatory| Description             |
| ------ | ------------------------------ | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| string | Function list in string format.|

**Example**

```js
let funcs = ACM | ECM;
let ret = usb.usbFunctionsToString(funcs);
```

## usb.setCurrentFunctions

setCurrentFunctions(funcs: FunctionType): Promise\<boolean\>

Sets the current USB function list in Device mode.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                          | Mandatory| Description             |
| ------ | ------------------------------ | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Example**

```js
let funcs = HDC;
let ret = usb.setCurrentFunctions(funcs);
```

## usb.getCurrentFunctions

getCurrentFunctions(): FunctionType

Obtains the numeric mask combination for the USB function list in Device mode.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                          | Description                             |
| ------------------------------ | --------------------------------- |
| [FunctionType](#functiontype) | Numeric mask combination for the USB function list.|

**Example**

```js
let ret = usb.getCurrentFunctions();
```

## usb.getPorts

getPorts(): Array\<USBPort\>

Obtains the list of all physical USB ports.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                         | Description                 |
| ----------------------------- | --------------------- |
| [Array\<USBPort\>](#usbport) | List of physical USB ports.|

**Example**

```js
let ret = usb.getPorts();
```

## usb.getSupportedModes

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
| [PortModeType](#portmodetype) | Mask combination for the supported mode list.|

**Example**

```js
let ret = usb.getSupportedModes(0);
```

## usb.setPortRoles

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean\>

Sets the role types supported by a specified port, which can be **powerRole** (for charging) and **dataRole** (for data transfer).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type                            | Mandatory| Description            |
| --------- | -------------------------------- | ---- | ---------------- |
| portId    | number                           | Yes  | Port number.        |
| powerRole | [PowerRoleType](#powerroletype) | Yes  | Role for charging.    |
| dataRole  | [DataRoleType](#dataroletype)   | Yes  | Role for data transfer.|

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

| Name           | Type                                       | Mandatory           |Description           |
| ------------- | ------------------------------------------- | ------------- |------------- |
| address       | number                                      | Yes | Endpoint address.        |
| attributes    | number                                      | Yes | Endpoint attributes.        |
| interval      | number                                      | Yes | Endpoint interval.        |
| maxPacketSize | number                                      | Yes | Maximum size of data packets on the endpoint.   |
| direction     | [USBRequestDirection](#usbrequestdirection) | Yes | Endpoint direction.       |
| number        | number                                      | Yes | Endpoint number.         |
| type          | number                                      | Yes | Endpoint type.        |
| interfaceId   | number                                      | Yes | Unique ID of the interface to which the endpoint belongs.|

## USBInterface

Represents a USB interface. One [USBConfig](#usbconfig) can contain multiple **USBInterface** instances, each providing a specific function.

**System capability**: SystemCapability.USB.USBManager

| Name              | Type                                    | Mandatory           |Description                   |
| ---------------- | ---------------------------------------- | ------------- |--------------------- |
| id               | number                                   | Yes | Unique ID of the USB interface.             |
| protocol         | number                                   | Yes | Interface protocol.               |
| clazz            | number                                   | Yes | Device type.                |
| subClass         | number                                   | Yes | Device subclass.                |
| alternateSetting | number                                   | Yes | Settings for alternating between descriptors of the same USB interface.|
| name             | string                                   | Yes | Interface name.                |
| endpoints        | Array&lt;[USBEndpoint](#usbendpoint)&gt; | Yes | Endpoints that belong to the USB interface.          |

## USBConfig

Represents the USB configuration. One [USBDevice](#usbdevice) can contain multiple **USBConfig** instances.

**System capability**: SystemCapability.USB.USBManager

| Name            | Type                                            | Mandatory |Description             |
| -------------- | ------------------------------------------------ | --------------- |--------------- |
| id             | number                                           | Yes | Unique ID of the USB configuration.       |
| attributes     | number                                           | Yes | Configuration attributes.         |
| maxPower       | number                                           | Yes | Maximum power consumption, in mA.   |
| name           | string                                           | Yes | Configuration name, which can be left empty.    |
| isRemoteWakeup | boolean                                          | Yes | Support for remote wakeup.|
| isSelfPowered  | boolean                                          | Yes | Support for independent power supplies.|
| interfaces     | Array&nbsp;&lt;[USBInterface](#usbinterface)&gt; | Yes | Supported interface attributes.     |

## USBDevice

Represents the USB device information.

**System capability**: SystemCapability.USB.USBManager

| Name              | Type                                | Mandatory        |Description        |
| ---------------- | ------------------------------------ | ---------- |---------- |
| busNum           | number                               | Yes | Bus address.     |
| devAddress       | number                               | Yes | Device address.     |
| serial           | string                               | Yes | Sequence number.      |
| name             | string                               | Yes | Device name.     |
| manufacturerName | string                               | Yes | Device manufacturer.     |
| productName      | string                               | Yes | Product name.     |
| version          | string                               | Yes | Version number.       |
| vendorId         | number                               | Yes | Vendor ID.     |
| productId        | number                               | Yes | Product ID.     |
| clazz            | number                               | Yes | Device class.      |
| subClass         | number                               | Yes | Device subclass.     |
| protocol         | number                               | Yes | Device protocol code.    |
| configs          | Array&lt;[USBConfig](#usbconfig)&gt; | Yes | Device configuration descriptor information.|

## USBDevicePipe

Represents a USB device pipe, which is used to determine a USB device.

**System capability**: SystemCapability.USB.USBManager

| Name        | Type  | Mandatory   |Description   |
| ---------- | ------ | ----- |----- |
| busNum     | number |Yes| Bus address.|
| devAddress | number |Yes| Device address.|

## USBControlParams

Represents control transfer parameters.

**System capability**: SystemCapability.USB.USBManager

| Name     | Type                                           | Mandatory              |Description              |
| ------- | ----------------------------------------------- | ---------------- |---------------- |
| request | number                                          | Yes  | Request type.           |
| target  | [USBRequestTargetType](#usbrequesttargettype)   | Yes  | Request target type.         |
| reqType | [USBControlRequestType](#usbcontrolrequesttype) | Yes  | Control request type.         |
| value   | number                                          | Yes  | Request parameter value.           |
| index   | number                                          | Yes  | Index of the request parameter value.|
| data    | Uint8Array                                      | Yes  | Buffer for writing or reading data.    |

## USBPort

Represents a USB port.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name          | Type                        | Mandatory     |Description                               |
| -------------- | ------------------------------- | ------------------- |------------------------ |
| id             | number                          | Yes  | Unique identifier of a USB port.                  |
| supportedModes | [PortModeType](#portmodetype)   | Yes  | Numeric mask combination for the supported mode list.|
| status         | [USBPortStatus](#usbportstatus) | Yes  | USB port role.                      |

## USBPortStatus

Enumerates USB port roles.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name            | Type| Mandatory     |Description                  |
| ---------------- | -------- | ---------------- |---------------------- |
| currentMode      | number   | Yes  | Current USB mode.       |
| currentPowerRole | number   | Yes  | Current power role.    |
| currentDataRole  | number   | Yes  | Current data role.|

## USBRequestTargetType

Enumerates request target types.

**System capability**: SystemCapability.USB.USBManager

| Name                         | Value | Description |
| ---------------------------- | ----- | ----------- |
| USB_REQUEST_TARGET_DEVICE    | 0     | Device      |
| USB_REQUEST_TARGET_INTERFACE | 1     | Interface   |
| USB_REQUEST_TARGET_ENDPOINT  | 2     | Endpoint    |
| USB_REQUEST_TARGET_OTHER     | 3     | Other       |

## USBControlRequestType

Enumerates control request types.

**System capability**: SystemCapability.USB.USBManager

| Name                     | Value  | Description  |
| ------------------------- | ---- | ------ |
| USB_REQUEST_TYPE_STANDARD | 0    | Standard|
| USB_REQUEST_TYPE_CLASS    | 1    | Class  |
| USB_REQUEST_TYPE_VENDOR   | 2    | Vendor|

## USBRequestDirection

Enumerates request directions.

**System capability**: SystemCapability.USB.USBManager

| Name                       | Value  | Description                    |
| --------------------------- | ---- | ------------------------ |
| USB_REQUEST_DIR_TO_DEVICE   | 0    | Request for writing data from the host to the device.|
| USB_REQUEST_DIR_FROM_DEVICE | 0x80 | Request for reading data from the device to the host.|

## FunctionType

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

## PortModeType

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

## PowerRoleType

Enumerates power role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value  | Description      |
| ------ | ---- | ---------- |
| NONE   | 0    | None.      |
| SOURCE | 1    | External power supply.|
| SINK   | 2    | Internal power supply.|

## DataRoleType

Enumerates data role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value  | Description        |
| ------ | ---- | ------------ |
| NONE   | 0    | None.        |
| HOST   | 1    | USB host.|
| DEVICE | 2    | USB device.|
