# USB

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import usb from "@ohos.usb";
```

## usb.getDevices

getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;

Obtains the USB device list.

**System capability**: SystemCapability.USB.USBManager

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | Array&lt;Readonly&lt;[USBDevice](#usbdevice)&gt;&gt; | Device information list. |

- **Example**
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

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | device | [USBDevice](#usbdevice) | Yes| USB device information. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | Readonly&lt;[USBDevicePipe](#usbdevicepipe)&gt; | USB device pipe for data transfer. |

- **Example**
  ```js
  let devicepipe= usb.connectDevice(device);
  console.log(`devicepipe = ${JSON.stringify(devicepipe)}`);
  ```


## usb.hasRight

hasRight(deviceName: string): boolean

Checks whether the application has the permission to access the device.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceName | string | Yes| Device name. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the application has the permission to access the device; returns **false** otherwise. |

- **Example**
  ```js
  let divicesName="1-1";
  let bool = usb.hasRight(divicesName);
  console.log(bool);
  ```


## usb.requestRight

requestRight(deviceName: string): Promise&lt;boolean&gt;

Requests the temporary permission for the application to access the USB device.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | deviceName | string | Yes| Device name. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Returns **true** if the temporary device access permissions are granted; returns **false** otherwise. |

- **Example**
  ```js
  let divicesName="1-1";
  usb.requestRight(divicesName).then((ret) => {
    console.log(`requestRight = ${JSON.stringify(ret)}`);
  });
  ```

## usb.claimInterface

claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number

Claims a USB interface.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and USB interfaces, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address. |
  | iface | [USBInterface](#usbinterface) | Yes| USB interface, which is used to determine the index of the interface to claim. |
  | force | boolean | No| Whether to forcibly claim the USB interface. The default value is **false**, indicating not to forcibly claim the USB interface. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | number | Returns **0** if the USB interface is successfully claimed; returns an error code otherwise. |

- **Example**
  ```js
  let ret = usb.claimInterface(devicepipe, interfaces);
  console.log(`claimInterface = ${ret}`);
  ```


## usb.releaseInterface

releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number

Releases a USB interface.

Before you do this, ensure that you have claimed the interface by calling [usb.claimInterface](#usbclaiminterface).

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address. |
  | iface | [USBInterface](#usbinterface) | Yes| USB interface, which is used to determine the index of the interface to release. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | number | Returns **0** if the USB interface is successfully released; returns an error code otherwise. |

- **Example**
  ```js
  let ret = usb.releaseInterface(devicepipe, interfaces);
  console.log(`releaseInterface = ${ret}`);
  ```


## usb.setConfiguration

setConfiguration(pipe: USBDevicePipe, config: USBConfig): number

Sets the device configuration.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and device configuration, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address. |
  | config | [USBConfig](#usbconfig) | Yes| USB configuration to set. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | number | Returns **0** if the USB configuration is successfully set; returns an error code otherwise. |

- **Example**
  ```js
  let ret = usb.setConfiguration(devicepipe, config);
  console.log(`setConfiguration = ${ret}`);
  ```

## usb.setInterface

setInterface(pipe: USBDevicePipe, iface: USBInterface): number

Sets a USB interface.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and interfaces, call [usb.requestRight](#usbrequestright) to request the device access permission, call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter, and call [usb.claimInterface](#usbclaiminterface) to claim a USB interface..

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address. |
  | iface | [USBInterface](#usbinterface) | Yes| USB interface to set. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | number | Returns **0** if the USB interface is successfully set; returns an error code otherwise. |

- **Example**
  ```js
  let ret = usb.setInterface(devicepipe, interfaces);
  console.log(`setInterface = ${ret}`);
  ```


## usb.getRawDescriptor

getRawDescriptor(pipe: USBDevicePipe): Uint8Array

Obtains the raw USB descriptor.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | Uint8Array | Raw descriptor data. The value **undefined** indicates that the operation has failed. |

- **Example**
  ```js
  let ret = usb.getRawDescriptor(devicepipe);
  ```


## usb.getFileDescriptor

getFileDescriptor(pipe: USBDevicePipe): number

Obtains the file descriptor.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| Device pipe, which is used to determine the bus number and device address. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | number | File descriptor of the USB device. The value **-1** indicates that the operation has failed. |

- **Example**
  ```js
  let ret = usb.getFileDescriptor(devicepipe);
  ```


## usb.controlTransfer

controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise&lt;number&gt;

Performs control transfer.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the USB device. |
  | contrlparam | [USBControlParams](#usbcontrolparams) | Yes| Control transfer parameters. |
  | timeout | number | No| Timeout duration. The default value is **0**, indicating no timeout. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Returns the size of the transmitted or received data block if the control transfer is successful; returns **-1** if an exception occurs. |

- **Example**
  ```js
  usb.controlTransfer(devicepipe, USBControlParams).then((ret) => {
   console.log(`controlTransfer = ${JSON.stringify(ret)}`);
  })
  ```


## usb.bulkTransfer

bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt;

Performs bulk transfer.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list and endpoints, call [usb.requestRight](#usbrequestright) to request the device access permission, call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter, and call [usb.claimInterface](#usbclaiminterface) to claim a USB interface.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe, which is used to determine the USB device. |
  | endpoint | [USBEndpoint](#usbendpoint) | Yes| USB endpoint, which is used to determine the USB port for data transfer. |
  | buffer | Uint8Array | Yes| Buffer for writing or reading data. |
  | timeout | number | No| Timeout duration. The default value is **0**, indicating no timeout. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Returns the size of the transmitted or received data block if the control transfer is successful; returns **-1** if an exception occurs. |

- **Example**
  ```js
  // Call usb.getDevices to obtain a data set. Then, obtain a USB device and its access permission.
  // Pass the obtained USB device as a parameter to usb.connectDevice. Then, call usb.connectDevice to connect the USB device.
  // Call usb.claimInterface to claim a USB interface. After that, call usb.bulkTransfer to start bulk transfer.
  usb.bulkTransfer(devicepipe, endpoint, buffer).then((ret) => {
   console.log(`bulkTransfer = ${JSON.stringify(ret)}`);
  });
  ```


## usb.closePipe

closePipe(pipe: USBDevicePipe): number

Closes a USB device pipe.

Before you do this, call [usb.getDevices](#usbgetdevices) to obtain the USB device list, call [usb.requestRight](#usbrequestright) to request the device access permission, and call [usb.connectDevice](#usbconnectdevice) to obtain **devicepipe** as an input parameter.

**System capability**: SystemCapability.USB.USBManager

- **Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pipe | [USBDevicePipe](#usbdevicepipe) | Yes| USB device pipe. |

- **Return value**
  | Type| Description|
  | -------- | -------- |
  | number | Returns **0** if the USB device pipe is closed successfully; returns an error code otherwise. |

- **Example**
  ```js
  let ret = usb.closePipe(devicepipe);
  console.log(`closePipe = ${ret}`);
  ```


## USBEndpoint

Represents the USB endpoint from which data is sent or received. You can obtain the USB endpoint through [USBInterface](#usbinterface).

**System capability**: SystemCapability.USB.USBManager

| Name| Type| Description|
| -------- | -------- | -------- |
| address | number | Endpoint address. |
| attributes | number | Endpoint attributes. |
| interval | number | Endpoint interval. |
| maxPacketSize | number | Maximum size of data packets on the endpoint. |
| direction | [USBRequestDirection](#usbrequestdirection) | Endpoint direction. |
| number | number | Endpoint number. |
| type | number | Endpoint type. |
| interfaceId | number | Unique ID of the interface to which the endpoint belongs. |


## USBInterface

Represents a USB interface. One [USBConfig](#usbconfig) can contain multiple **USBInterface** instances, each providing a specific function.

**System capability**: SystemCapability.USB.USBManager

| Name| Type| Description|
| -------- | -------- | -------- |
| id | number | Unique ID of the USB interface. |
| protocol | number | Interface protocol. |
| clazz | number | Device type. |
| subClass | number | Device subclass. |
| alternateSetting | number | Settings for alternating between descriptors of the same USB interface. |
| name | string | Interface name. |
| endpoints | Array&lt;[USBEndpoint](#usbendpoint)&gt; | Endpoints that belong to the USB interface. |


## USBConfig

Represents the USB configuration. One [USBDevice](#usbdevice) can contain multiple **USBConfig** instances.

**System capability**: SystemCapability.USB.USBManager

| Name| Type| Description|
| -------- | -------- | -------- |
| id | number | Unique ID of the USB configuration. |
| attributes | number | Configuration attributes. |
| maxPower | number | Maximum power consumption, in mA. |
| name | string | Configuration name, which can be left empty. |
| isRemoteWakeup | boolean | Support for remote wakeup. |
| isSelfPowered | boolean | Support for independent power supplies. |
| interfaces | Array&nbsp;&lt;[USBInterface](#usbinterface)&gt; | Supported interface attributes. |


## USBDevice

Represents USB device information.

**System capability**: SystemCapability.USB.USBManager

| Name| Type| Description|
| -------- | -------- | -------- |
| busNum | number | Bus address. |
| devAddress | number | Device address. |
| serial | string | Device SN. |
| name | string | Device name. |
| manufacturerName | string | Device manufacturer. |
| productName | string | Product information. |
| version | string | Version. |
| vendorId | number | Vendor ID. |
| productId | number | Product ID. |
| clazz | number | Device class. |
| subClass | number | Device subclass. |
| protocol | number | Device protocol code. |
| configs | Array&lt;[USBConfig](#usbconfig)&gt; | Device configuration descriptor information. |


## USBDevicePipe

Represents a USB device pipe, which is used to determine a USB device.

**System capability**: SystemCapability.USB.USBManager

| Name| Type| Description|
| -------- | -------- | -------- |
| busNum | number | Bus address. |
| devAddress | number | Device address. |


## USBControlParams

Represents control transfer parameters.

**System capability**: SystemCapability.USB.USBManager

| Name| Type| Description|
| -------- | -------- | -------- |
| request | number | Request type. |
| target | [USBRequestTargetType](#usbrequesttargettype) | Type of the request target. |
| reqType | [USBControlRequestType](#usbcontrolrequesttype) | Request control type. |
| value | number | Request parameters|
| index | number | Index of the request parameter value. |
| data | Uint8Array | Buffer for writing or reading data. |


## USBRequestTargetType

Represents the request target type.

**System capability**: SystemCapability.USB.USBManager

| Name| Default Value | Description|
| -------- | -------- | -------- |
| USB_REQUEST_TARGET_DEVICE | 0 | Device. |
| USB_REQUEST_TARGET_INTERFACE | 1 | Interface. |
| USB_REQUEST_TARGET_ENDPOINT | 2 | Endpoint|
| USB_REQUEST_TARGET_OTHER | 3 | Others|


## USBControlRequestType

Enumerates control request types.

**System capability**: SystemCapability.USB.USBManager

| Name| Default Value | Description|
| -------- | -------- | -------- |
| USB_REQUEST_TYPE_STANDARD | 0 | Standard|
| USB_REQUEST_TYPE_CLASS | 1 | Class. |
| USB_REQUEST_TYPE_VENDOR | 2 | Vendor|


## USBRequestDirection

Enumerates request directions.

**System capability**: SystemCapability.USB.USBManager

| Name| Default Value | Description|
| -------- | -------- | -------- |
| USB_REQUEST_DIR_TO_DEVICE | 0 | Request for writing data from the host to the device. |
| USB_REQUEST_DIR_FROM_DEVICE | 0x80 | Request for reading data from the device to the host. |
