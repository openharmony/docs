# @ohos.usbManager (USB Manager)

The **usbManager** module provides USB device management functions, including USB device list query, bulk data transfer, control transfer, and permission control on the host side as well as USB interface management, and function switch and query on the device side.

>  **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { usbManager } from '@kit.BasicServicesKit';
```

## usbManager.getDevices

getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;

Obtains the list of USB devices connected to the host. If no device is connected, an empty list is returned.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                                                  | Description     |
| ---------------------------------------------------- | ------- |
| Array&lt;Readonly&lt;[USBDevice](#usbdevice)&gt;&gt; | USB device list.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
console.log(`devicesList = ${devicesList}`);
/*
The following is a simple example of the data structure for devicesList:
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
    subClass: 0,
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
            subClass: 0,
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
*/
```

## usbManager.connectDevice

connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt;

Connects to the USB device based on the device information returned by **getDevices()**.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list and device information, and then call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | ---------------- |
| device | [USBDevice](#usbdevice) | Yes| USB device. The **busNum** and **devAddress** parameters obtained by **getDevices** are used to determine a USB device. Other parameters are passed transparently.|

**Return value**

| Type| Description|
| -------- | -------- |
| Readonly&lt;[USBDevicePipe](#usbdevicepipe)&gt; | USB device pipe for data transfer.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14400001 | Permission denied. Call requestRight to get the permission first. |

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
usbManager.requestRight(device.name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(device);
console.log(`devicepipe = ${devicepipe}`);
```

## usbManager.hasRight

hasRight(deviceName: string): boolean

Checks whether the application has the permission to access the device.

Checks whether the user, for example, the application or system, has the device access permissions. The value **true** is returned if the user has the device access permissions; the value **false** is returned otherwise.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Yes| Device name, which can be obtained from the device list returned by **getDevices**.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the application has the permission to access the device; returns **false** otherwise.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
usbManager.requestRight(device.name);
let right: boolean = usbManager.hasRight(device.name);
console.log(`${right}`);
```

## usbManager.requestRight

requestRight(deviceName: string): Promise&lt;boolean&gt;

Requests the temporary device access permission for the application. This API uses a promise to return the result. System applications are granted the device access permission by default, and you do not need to apply for the permission separately.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Yes| Device name, which can be obtained from the device list returned by **getDevices**.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the temporary device access permissions are granted; and the value **false** indicates the opposite.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
usbManager.requestRight(device.name).then(ret => {
  console.log(`requestRight = ${ret}`);
});
```

## usbManager.removeRight

removeRight(deviceName: string): boolean

Removes the device access permission for the application. System applications are granted the device access permission by default, and calling this API will not revoke the permission.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Yes| Device name, which can be obtained from the device list returned by **getDevices**.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Permission removal result. The value **true** indicates that the access permission is removed successfully; and the value **false** indicates the opposite.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
if (usbManager.removeRight(device.name)) {
  console.log(`Succeed in removing right`);
}
```

## usbManager.claimInterface

claimInterface(pipe: USBDevicePipe, iface: USBInterface, force ?: boolean): number

Claims a USB interface.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list and USB interfaces, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, and call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the bus number and device address. You need to call **connectDevice** to obtain its value.|
| iface | [USBInterface](#usbinterface) | Yes| USB interface. You can use **getDevices** to obtain device information and identify the USB interface based on its ID.|
| force | boolean | No| Whether to forcibly claim the USB interface. Whether to forcibly claim a USB interface. The default value is **false**, which means not to forcibly claim a USB interface. You can set the value as required.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns **0** if the USB interface is successfully claimed; returns an error code otherwise.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
usbManager.requestRight(device.name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(device);
let interfaces: usbManager.USBInterface = device.configs[0].interfaces[0];
let ret: number= usbManager.claimInterface(devicepipe, interfaces);
console.log(`claimInterface = ${ret}`);
```

## usbManager.releaseInterface

releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number

Releases a USB interface.

Before you do this, ensure that you have claimed the interface by calling [usbManager.claimInterface](#usbmanagerclaiminterface).

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the bus number and device address. You need to call **connectDevice** to obtain its value.|
| iface | [USBInterface](#usbinterface) | Yes| USB interface. You can use **getDevices** to obtain device information and identify the USB interface based on its ID.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns **0** if the USB interface is successfully released; returns an error code otherwise.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
usbManager.requestRight(device.name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(device);
let interfaces: usbManager.USBInterface = device.configs[0].interfaces[0];
let ret: number = usbManager.claimInterface(devicepipe, interfaces);
ret = usbManager.releaseInterface(devicepipe, interfaces);
console.log(`releaseInterface = ${ret}`);
```

## usbManager.setConfiguration

setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number

Sets the device configuration.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list and device configuration, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, and call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the bus number and device address. You need to call **connectDevice** to obtain its value.|
| config | [USBConfiguration](#usbconfiguration) | Yes| USB configuration. You can use **getDevices** to obtain device information and identify the USB configuration based on the ID.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns **0** if the USB configuration is successfully set; returns an error code otherwise.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
usbManager.requestRight(device.name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(device);
let config: usbManager.USBConfiguration = device.configs[0];
let ret: number= usbManager.setConfiguration(devicepipe, config);
console.log(`setConfiguration = ${ret}`);
```

## usbManager.setInterface

setInterface(pipe: USBDevicePipe, iface: USBInterface): number

Sets a USB interface.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list and interfaces, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter, and call [usbManager.claimInterface](#usbmanagerclaiminterface) to claim a USB interface.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the bus number and device address. You need to call **connectDevice** to obtain its value.|
| iface | [USBInterface](#usbinterface)   | Yes| USB interface. You can use **getDevices** to obtain device information and identify the USB interface based on its **id** and **alternateSetting**.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns **0** if the USB interface is successfully set; returns an error code otherwise.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
usbManager.requestRight(device.name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(device);
let interfaces: usbManager.USBInterface = device.configs[0].interfaces[0];
let ret: number = usbManager.claimInterface(devicepipe, interfaces);
ret = usbManager.setInterface(devicepipe, interfaces);
console.log(`setInterface = ${ret}`);
```

## usbManager.getRawDescriptor

getRawDescriptor(pipe: USBDevicePipe): Uint8Array

Obtains the raw USB descriptor.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, and call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the bus number and device address. You need to call **connectDevice** to obtain its value.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| Uint8Array | Returns the raw USB descriptor if the operation is successful; returns **undefined** otherwise.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

usbManager.requestRight(devicesList[0].name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(devicesList[0]);
let ret: Uint8Array = usbManager.getRawDescriptor(devicepipe);
```

## usbManager.getFileDescriptor

getFileDescriptor(pipe: USBDevicePipe): number

Obtains the file descriptor.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, and call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the bus number and device address. You need to call **connectDevice** to obtain its value.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | Returns the file descriptor of the USB device if the operation is successful; returns **-1** otherwise.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

usbManager.requestRight(devicesList[0].name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(devicesList[0]);
let ret: number = usbManager.getFileDescriptor(devicepipe);
```

## usbManager.controlTransfer<sup>(deprecated)</sup>

controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout ?: number): Promise&lt;number&gt;

Performs control transfer.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, and call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [usbControlTransfer](#usbmanagerusbcontroltransfer12).

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe. You need to call **connectDevice** to obtain its value.|
| controlparam | [USBControlParams](#usbcontrolparamsdeprecated) | Yes| Control transfer parameters. Set the parameters as required. For details, see the USB protocol.|
| timeout | number | No| Timeout period, in ms. This parameter is optional. The default value is **0**. You can set this parameter as required.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result, which is the size of the transmitted or received data block if the transfer is successful, or **-1** if an exception has occurred.|

**Example**

```ts
class PARA {
  request: number = 0
  reqType: usbManager.USBControlRequestType = 0
  target: usbManager.USBRequestTargetType = 0
  value: number = 0
  index: number = 0
  data: Uint8Array = new Uint8Array()
}

let param: PARA = {
  request: 0x06,
  reqType: 0x80,
  target:0,
  value: 0x01 << 8 | 0,
  index: 0,
  data: new Uint8Array(18)
};

let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

usbManager.requestRight(devicesList[0].name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(devicesList[0]);
usbManager.controlTransfer(devicepipe, param).then((ret: number) => {
console.log(`controlTransfer = ${ret}`);
})
```

## usbManager.usbControlTransfer<sup>12+</sup>

usbControlTransfer(pipe: USBDevicePipe, requestparam: USBDeviceRequestParams, timeout ?: number): Promise&lt;number&gt;

Performs control transfer.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, and call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the USB device.|
| requestparam | [USBDeviceRequestParams](#usbdevicerequestparams12) | Yes| Control transfer parameters. Set the parameters as required. For details, see the USB protocol.|
| timeout | number | No| Timeout duration in ms. This parameter is optional. The default value is **0**, indicating no timeout.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1.Mandatory parameters are left unspecified.2.Incorrect parameter types |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result, which is the size of the transmitted or received data block if the transfer is successful, or **-1** if an exception has occurred.|

**Example**

```ts
class PARA {
  bmRequestType: number = 0
  bRequest: number = 0
  wValue: number = 0
  wIndex: number = 0
  wLength: number = 0
  data: Uint8Array = new Uint8Array()
}

let param: PARA = {
  bmRequestType: 0x80,
  bRequest: 0x06,

  wValue:0x01 << 8 | 0,
  wIndex: 0,
  wLength: 18,
  data: new Uint8Array(18)
};

let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

usbManager.requestRight(devicesList[0].name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(devicesList[0]);
usbManager.usbControlTransfer(devicepipe, param).then((ret: number) => {
console.log(`usbControlTransfer = ${ret}`);
})
```

## usbManager.bulkTransfer

bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout ?: number): Promise&lt;number&gt;

Performs bulk transfer.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list and endpoints, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter, and call **usb.bulkTransfer** to claim a USB interface.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe. You need to call **connectDevice** to obtain its value.|
| endpoint | [USBEndpoint](#usbendpoint) | Yes| USB endpoint, which is used to determine the USB interface for data transfer. You need to call **getDevices** to obtain the device information list and endpoint. Wherein, **address** is used to determine the endpoint address, **direction** is used to determine the endpoint direction, and **interfaceId** is used to determine the USB interface to which the endpoint belongs. Other parameters are passed transparently.|
| buffer | Uint8Array | Yes| Buffer used to write or read data.|
| timeout | number | No| Timeout period, in ms. This parameter is optional. The default value is **0**. You can set this parameter as required.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result, which is the size of the transmitted or received data block if the transfer is successful, or **-1** if an exception has occurred.|

**Example**

> **NOTE**
>
> The following sample code is only a basic process for calling the **bulkTransfer** API. In actual calling, you must comply with the device-related protocols to ensure correct data transmission and device compatibility.

```ts
// Call usbManager.getDevices to obtain a data set. Then, obtain a USB device and its access permission.
// Pass the obtained USB device as a parameter to usbManager.connectDevice. Then, call usbManager.connectDevice to connect the USB device.
// Call usbManager.claimInterface to claim a USB interface. After that, call usbManager.bulkTransfer to start bulk transfer.
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

let device: usbManager.USBDevice = devicesList[0];
usbManager.requestRight(device.name);

let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(device);
for (let i = 0; i < device.configs[0].interfaces.length; i++) {
  if (device.configs[0].interfaces[i].endpoints[0].attributes == 2) {
    let endpoint: usbManager.USBEndpoint = device.configs[0].interfaces[i].endpoints[0];
    let interfaces: usbManager.USBInterface = device.configs[0].interfaces[i];
    let ret: number = usbManager.claimInterface(devicepipe, interfaces);
    let buffer =  new Uint8Array(128);
    usbManager.bulkTransfer(devicepipe, endpoint, buffer).then((ret: number) => {
      console.log(`bulkTransfer = ${ret}`);
    });
  }
}
```

## usbManager.closePipe

closePipe(pipe: USBDevicePipe): number

Closes a USB device pipe.

Before you do this, call [usbManager.getDevices](#usbmanagergetdevices) to obtain the USB device list, call [usbManager.requestRight](#usbmanagerrequestright) to request the device access permission, and call [usbManager.connectDevice](#usbmanagerconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the message control channel. You need to call **connectDevice** to obtain its value.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns **0** if the USB device pipe is closed successfully; returns an error code otherwise.|

**Example**

```ts
let devicesList: Array<usbManager.USBDevice> = usbManager.getDevices();
if (devicesList.length == 0) {
  console.log(`device list is empty`);
}

usbManager.requestRight(devicesList[0].name);
let devicepipe: usbManager.USBDevicePipe = usbManager.connectDevice(devicesList[0]);
let ret: number = usbManager.closePipe(devicepipe);
console.log(`closePipe = ${ret}`);
```

## usbManager.hasAccessoryRight<sup>14+</sup>

hasAccessoryRight(accessory: USBAccessory): boolean

Checks whether the application has the permission to access the USB accessory.

You need to call [usbManager.getAccessoryList](#usbmanagergetaccessorylist14) to obtain the accessory list and use [USBAccessory](#usbaccessory14) as a parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type        | Mandatory| Description                                 |
| --------- | ------------ | ---- | ------------------------------------- |
| accessory | [USBAccessory](#usbaccessory14) | Yes  | USB accessory.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. |
| 14400005 | Database operation exception.                                |
| 14401001 | The target USBAccessory not matched.                         |

**Return value**

| Type   | Description                         |
| ------- | ----------------------------- |
| boolean | The value **true** indicates that the application has the permission to access the USB accessory; **false** indicates the opposite.|

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
try {
  let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList()
  let flag = usbManager.hasAccessoryRight(accList[0])
  hilog.info(0, 'testTag ui', `hasAccessoryRight success, ret:${flag}`)
} catch (error) {
  hilog.info(0, 'testTag ui', `hasAccessoryRight error ${error.code}, message is ${error.message}`)
}
```

## usbManager.requestAccessoryRight<sup>14+</sup>

requestAccessoryRight(accessory: USBAccessory): Promise&lt;boolean&gt;

Requests the permission to access a USB accessory for a specified application.

You need to call [usbManager.getAccessoryList](#usbmanagergetaccessorylist14) to obtain the accessory list and use [USBAccessory](#usbaccessory14) as a parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type        | Mandatory| Description                                 |
| --------- | ------------ | ---- | ------------------------------------- |
| accessory | [USBAccessory](#usbaccessory14) | Yes  | USB accessory.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. |
| 14400005 | Database operation exception.                                |
| 14401001 | The target USBAccessory not matched.                         |

**Return value**

| Type            | Description                         |
| ---------------- | ----------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the application result. The value **true** indicates that the permission application is successful; **false** indicates the opposite.|

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
try {
  let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList()
  let flag = await usbManager.requestAccessoryRight(accList[0])
  hilog.info(0, 'testTag ui', `requestAccessoryRight success, ret:${flag}`)
} catch (error) {
  hilog.info(0, 'testTag ui', `requestAccessoryRight error ${error.code}, message is ${error.message}`)
}
```

## usbManager.cancelAccessoryRight<sup>14+</sup>

cancelAccessoryRight(accessory: USBAccessory): void;

Cancels the permission of the current application to access USB accessories.

You need to call [usbManager.getAccessoryList](#usbmanagergetaccessorylist14) to obtain the accessory list and use [USBAccessory](#usbaccessory14) as a parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type        | Mandatory| Description                                 |
| --------- | ------------ | ---- | ------------------------------------- |
| accessory | [USBAccessory](#usbaccessory14) | Yes  | USB accessory.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. |
| 14400005 | Database operation exception.                                |
| 14401001 | The target USBAccessory not matched.                         |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
try {
  let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList()
  let flag = await usbManager.requestAccessoryRight(accList[0])
  usbManager.cancelAccessoryRight(accList[0])
  hilog.info(0, 'testTag ui', `cancelAccessoryRight success`)
} catch (error) {
  hilog.info(0, 'testTag ui', `cancelAccessoryRight error ${error.code}, message is ${error.message}`)
}
```

## usbManager.getAccessoryList<sup>14+</sup>

getAccessoryList(): Array<Readonly&lt;USBAccessory&gt;>

Obtains the list of USB accessories connected to the host.

**System capability**: SystemCapability.USB.USBManager

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. |

**Return value**

| Type                         | Description                                              |
| ----------------------------- | -------------------------------------------------- |
| Array<Readonly&lt;USBAccessory&gt;> | List of USB accessories (read-only). Currently, only one USB accessory is contained in the list.|

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
try {
  let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList()
  hilog.info(0, 'testTag ui', `getAccessoryList success, accList: ${JSON.stringify(accList)}`)
} catch (error) {
  hilog.info(0, 'testTag ui', `getAccessoryList error ${error.code}, message is ${error.message}`)
}
```

## usbManager.openAccessory<sup>14+</sup>

openAccessory(accessory: USBAccessory): USBAccessoryHandle;

Obtains the accessory handle and opens the accessory file descriptor.

You need to call [usbManager.getAccessoryList](#usbmanagergetaccessorylist14) to obtain the accessory list and use [USBAccessory](#usbaccessory14) as a parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type        | Mandatory| Description                                 |
| --------- | ------------ | ---- | ------------------------------------- |
| accessory | [USBAccessory](#usbaccessory14) | Yes  | USB accessory.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14400001 | Permission denied. Call requestAccessoryRight to get the right first. |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. |
| 14401001 | The target USBAccessory not matched.                         |
| 14401002 | Failed to open the native accessory node.                    |
| 14401003 | Cannot reopen the accessory.                                 |

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| [USBAccessoryHandle](#usbaccessoryhandle14) | USB accessory handle.|

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
try {
  let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList()
  let flag = await usbManager.requestAccessoryRight(accList[0])
  let handle = usbManager.openAccessory(accList[0])
  hilog.info(0, 'testTag ui', `openAccessory success`)
} catch (error) {
  hilog.info(0, 'testTag ui', `openAccessory error ${error.code}, message is ${error.message}`)
}
```

## usbManager.closeAccessory<sup>14+</sup>

closeAccessory(accessoryHandle: USBAccessoryHandle): void;

Closes the accessory file descriptor.

You need to call [usbManager.openAccessory](#usbmanageropenaccessory14) to obtain the accessory list and use [USBAccessoryHandle](#usbaccessoryhandle14) as a parameter.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name         | Type              | Mandatory| Description                                  |
| --------------- | ------------------ | ---- | -------------------------------------- |
| accessoryHandle | [USBAccessoryHandle](#usbaccessoryhandle14) | Yes  | USB accessory handle.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
try {
  let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList()
  let flag = await usbManager.requestAccessoryRight(accList[0])
  let handle = usbManager.openAccessory(accList[0])
  usbManager.closeAccessory(handle)
  hilog.info(0, 'testTag ui', `closeAccessory success`)
} catch (error) {
  hilog.info(0, 'testTag ui', `closeAccessory error ${error.code}, message is ${error.message}`)
}
```

## USBEndpoint

Represents the USB endpoint from which data is sent or received. You can obtain the USB endpoint through [USBInterface](#usbinterface).

**System capability**: SystemCapability.USB.USBManager

| Name           | Type                                       | Mandatory           |Description           |
| ------------- | ------------------------------------------- | ------------- |------------- |
| address       | number                                      | Yes|Endpoint address.        |
| attributes    | number                                      | Yes|Endpoint attributes.        |
| interval      | number                                      | Yes|Endpoint interval.        |
| maxPacketSize | number                                      | Yes|Maximum size of data packets on the endpoint.   |
| direction     | [USBRequestDirection](#usbrequestdirection) | Yes|Endpoint direction.       |
| number        | number                                      | Yes|Endpoint number.         |
| type          | number                                      | Yes|Endpoint type.        |
| interfaceId   | number                                      | Yes|Unique ID of the interface to which the endpoint belongs.|

## USBInterface

Represents a USB interface. One [USBConfiguration](#usbconfiguration) object can contain multiple **USBInterface** instances, each providing a specific function.

**System capability**: SystemCapability.USB.USBManager

| Name              | Type                                    | Mandatory           |Description                   |
| ---------------- | ---------------------------------------- | ------------- |--------------------- |
| id               | number                                   | Yes|Unique ID of the USB interface.             |
| protocol         | number                                   | Yes|Interface protocol.               |
| clazz            | number                                   | Yes|Device type.                |
| subClass         | number                                   | Yes|Device subclass.                |
| alternateSetting | number                                   | Yes|Settings for alternating between descriptors of the same USB interface.|
| name             | string                                   | Yes|Interface name.                |
| endpoints        | Array&lt;[USBEndpoint](#usbendpoint)&gt; | Yes|Endpoints that belong to the USB interface.          |

## USBConfiguration

Represents the USB configuration. One [USBDevice](#usbdevice) can contain multiple **USBConfig** instances.

**System capability**: SystemCapability.USB.USBManager

| Name            | Type                                            | Mandatory |Description             |
| -------------- | ------------------------------------------------ | --------------- |--------------- |
| id             | number                                           | Yes|Unique ID of the USB configuration.       |
| attributes     | number                                           | Yes|Configuration attributes.         |
| maxPower       | number                                           | Yes|Maximum power consumption, in mA.   |
| name           | string                                           | Yes|Configuration name, which can be left empty.    |
| isRemoteWakeup | boolean                                          | Yes|Support for remote wakeup.|
| isSelfPowered  | boolean                                          | Yes| Support for independent power supplies.|
| interfaces     | Array&nbsp;&lt;[USBInterface](#usbinterface)&gt; | Yes|Supported interface attributes.     |

## USBDevice

Represents the USB device information.

**System capability**: SystemCapability.USB.USBManager

| Name              | Type                                | Mandatory        |Description        |
| ---------------- | ------------------------------------ | ---------- |---------- |
| busNum           | number                               | Yes|Bus address.     |
| devAddress       | number                               | Yes|Device address.     |
| serial           | string                               | Yes|Sequence number.      |
| name             | string                               | Yes|Device name.     |
| manufacturerName | string                               | Yes| Device manufacturer.     |
| productName      | string                               | Yes|Product name.     |
| version          | string                               | Yes|Version number.       |
| vendorId         | number                               | Yes|Vendor ID.     |
| productId        | number                               | Yes|Product ID.     |
| clazz            | number                               | Yes|Device class.      |
| subClass         | number                               | Yes|Device subclass.     |
| protocol         | number                               | Yes|Device protocol code.    |
| configs          | Array&lt;[USBConfiguration](#usbconfiguration)&gt; | Yes|Device configuration descriptor information.|

## USBDevicePipe

Represents a USB device pipe, which is used to determine a USB device.

**System capability**: SystemCapability.USB.USBManager

| Name        | Type  | Mandatory   |Description   |
| ---------- | ------ | ----- |----- |
| busNum     | number |Yes| Bus address.|
| devAddress | number |Yes| Device address.|

## USBControlParams<sup>(deprecated)</sup>

Represents control transfer parameters.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 16. You are advised to use [USBDeviceRequestParams](#usbdevicerequestparams12) instead.

**System capability**: SystemCapability.USB.USBManager

| Name     | Type                                           | Mandatory              |Description              |
| ------- | ----------------------------------------------- | ---------------- |---------------- |
| request | number                                          | Yes  |Request type.           |
| target  | [USBRequestTargetType](#usbrequesttargettype)   | Yes  |Request target type.         |
| reqType | [USBControlRequestType](#usbcontrolrequesttype) | Yes  |Control request type.         |
| value   | number                                          | Yes  |Request parameter value.           |
| index   | number                                          | Yes  |Index of the request parameter value.|
| data    | Uint8Array                                      | Yes  |Buffer for writing or reading data.    |

## USBDeviceRequestParams<sup>12+</sup>

Represents control transfer parameters.

**System capability**: SystemCapability.USB.USBManager

| Name     | Type                                           | Mandatory              |Description              |
| ------- | ----------------------------------------------- | ---------------- |---------------- |
| bmRequestType | number                                    | Yes  |Control request type.           |
| bRequest  | number                                        | Yes  |Request type.         |
| wValue | number                                           | Yes  |Request parameter value.         |
| wIndex   | number                                         | Yes  |Index of the request parameter value.           |
| wLength   | number                                        | Yes  |Length of the requested data.|
| data    | Uint8Array                                      | Yes  |Buffer for writing or reading data.    |

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

## USBAccessory<sup>14+</sup>

Describes the USB accessory information.

**System capability**: SystemCapability.USB.USBManager

| Name        | Type  | Mandatory| Description            |
| ------------ | ------ | ---- | ---------------- |
| manufacturer | string | Yes  | Manufacturer of an accessory.|
| product      | string | Yes  | Product type of an accessory.|
| description  | string | Yes  | Description of an accessory.    |
| version      | string | Yes  | Version of an accessory.    |
| serialNumber | string | Yes  | SN of an accessory.    |

## USBAccessoryHandle<sup>14+</sup>

USB accessory handle.

**System capability**: SystemCapability.USB.USBManager

| Name       | Type  | Mandatory| Description                                     |
| ----------- | ------ | ---- | ----------------------------------------- |
| accessoryFd | number | Yes  | Accessory file descriptor. A valid **accessoryFd** is a positive integer.|
