# @ohos.usbManager.serial (Serial Port Management)

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

This module provides the serial port management functions, including enabling and disabling the serial port of the device, writing and reading data, setting and obtaining the configuration parameters of the serial port, and managing permissions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 19. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { serialManager } from '@kit.BasicServicesKit';
```

## serialManager.getPortList

getPortList(): Readonly&lt;SerialPort&gt;[]

Obtains the serial port device list, including the device name and port number.

**System capability**: SystemCapability.USB.USBManager.Serial

**Returns**

| Type                                       | Description         |
|-------------------------------------------|-------------|
| Readonly&lt;[SerialPort](#serialport)&gt;[] | Serial port information list.|

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **getPortList** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port device list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;
```

## serialManager.hasSerialRight

hasSerialRight(portId: number): boolean

Checks whether the application has the permission to access the serial port device. When an application is restarted after exits, you need to request the permission from the user again.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name   | Type    | Mandatory| Description                                 |
|--------|--------|----|-------------------------------------|
| portId | number | Yes | Port number.|

**Returns**

| Type     | Description              |
|---------|------------------|
| boolean | The value **true** indicates that the permission is authorized, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14400005 | Database operation exception. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **hasSerialRight** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('portList: ', JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (serialManager.hasSerialRight(portId)) {
  console.info('The serial port is accessible');
} else {
  console.info('No permission to access the serial port');
}
```

## serialManager.requestSerialRight

requestSerialRight(portId: number): Promise&lt;boolean&gt;

Requests the permission for the application to access the serial port device. After the application exits, the access permission on the serial port device is automatically removed. After the application is restarted, you need to request the permission again.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name   | Type    | Mandatory| Description                                 |
|--------|--------|----|-------------------------------------|
| portId | number | Yes | Port number.|

**Returns**

| Type                    | Description           |
|------------------------|---------------|
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the permission is successfully requested, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14400005 | Database operation exception. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **requestSerialRight** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}
```

## serialManager.open

open(portId: number): void

Opens a serial port device.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name   | Type    | Mandatory| Description         |
|--------|--------|----|-------------|
| portId | number | Yes | Port number.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 31400001 | Serial port management exception. |
| 31400002 | Access denied. Call requestSerialRight to request user authorization first. |
| 31400003 | PortId does not exist. |
| 31400004 | The serial port device is occupied. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **open** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Open a serial port device.
try {
  serialManager.open(portId)
  console.info('open usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('open usbSerial error, ' + JSON.stringify(error));
}
```

## serialManager.getAttribute

getAttribute(portId: number): Readonly&lt;[SerialAttribute](#serialattribute)&gt;

Obtains the configuration parameters of a specified serial port.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name   | Type    | Mandatory| Description         |
|--------|--------|----|-------------|
| portId | number | Yes | Port number.|

**Returns**

| Type    | Description         |
|--------|-------------|
| Readonly&lt;[SerialAttribute](#serialattribute)&gt; | Configuration parameters of the serial port.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |
| 31400005 | The serial port device is not opened. Call the open API first. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **getAttribute** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Open a serial port device.
try {
  serialManager.open(portId)
  console.info('open usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('open usbSerial error, ' + JSON.stringify(error));
  return;
}

// Obtain the serial port configuration.
try {
  let attribute: serialManager.SerialAttribute = serialManager.getAttribute(portId);
  if (attribute === undefined) {
    console.error('getAttribute usbSerial error, attribute is undefined');
  } else {
    console.info('getAttribute usbSerial success, attribute: ' + JSON.stringify(attribute));
  }
} catch (error) {
  console.error('getAttribute usbSerial error, ' + JSON.stringify(error));
}
```

## serialManager.setAttribute

setAttribute(portId: number, attribute: [SerialAttribute](#serialattribute)): void

Sets the parameters of the serial port. If this method is not called, the default configuration parameters are used (baud rate: 9600 bit/s; data bit: 8; parity bit: 0; stop bit: 1).

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name      | Type                                 | Mandatory| Description         |
|-----------|-------------------------------------|----|-------------|
| portId    | number                              | Yes | Port number.|
| attribute | [SerialAttribute](#serialattribute) | Yes | Configuration parameters of the serial port.    |

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |
| 31400005 | The serial port device is not opened. Call the open API first. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **setAttribute** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Open a serial port device.
try {
  serialManager.open(portId)
  console.info('open usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('open usbSerial error, ' + JSON.stringify(error));
  return;
}

// Set the serial port configuration.
try {
  let attribute: serialManager.SerialAttribute = {
    baudRate: serialManager.BaudRates.BAUDRATE_9600,
    dataBits: serialManager.DataBits.DATABIT_8,
    parity: serialManager.Parity.PARITY_NONE,
    stopBits: serialManager.StopBits.STOPBIT_1
  }
  serialManager.setAttribute(portId, attribute);
  console.info('setAttribute usbSerial success, attribute: ' + JSON.stringify(attribute));
} catch (error) {
  console.error('setAttribute usbSerial error, ' + JSON.stringify(error));
}
```

## serialManager.read

read(portId: number, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt;

Reads data from the serial port device asynchronously.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name    | Type        | Mandatory| Description              |
|---------|------------|----|------------------|
| portId  | number     | Yes | Port number.     |
| buffer  | Uint8Array | Yes | Buffer for reading data.|
| timeout | number     | No | (Optional) Timeout duration, in ms. The default value is **0**, indicating no timeout. You can set this parameter as required.|

**Returns**

| Type                   | Description            |
|-----------------------|----------------|
| Promise&lt;number&gt; | Promise used to return the length of the data read.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |
| 31400005 | The serial port device is not opened. Call the open API first. |
| 31400006 | Data transfer timed out. |
| 31400007 | I/O exception. Possible causes: 1. The transfer was canceled. 2. The device offered more data than allowed. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **read** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Open a serial port device.
try {
  serialManager.open(portId)
  console.info('open usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('open usbSerial error, ' + JSON.stringify(error));
}

// Read data asynchronously.
let readBuffer: Uint8Array = new Uint8Array(64);
serialManager.read(portId, readBuffer, 2000).then((size: number) => {
  console.info('read usbSerial success, readBuffer: ' + readBuffer.toString());
}).catch((error: Error) => {
  console.error('read usbSerial error, ' + JSON.stringify(error));
})
```

## serialManager.readSync

readSync(portId: number, buffer: Uint8Array, timeout?: number): number

Reads data from the serial port device synchronously.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name    | Type        | Mandatory| Description              |
|---------|------------|----|------------------|
| portId  | number     | Yes | Port number.|
| buffer  | Uint8Array | Yes | Buffer for reading data.|
| timeout | number     | No | (Optional) Timeout duration, in ms. The default value is **0**, indicating no timeout. You can set this parameter as required.|

**Returns**

| Type    | Description         |
|--------|-------------|
| number | Length of the data read.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |
| 31400005 | The serial port device is not opened. Call the open API first. |
| 31400006 | Data transfer timed out. |
| 31400007 | I/O exception. Possible causes: 1. The transfer was canceled. 2. The device offered more data than allowed. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **readSync** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Open a serial port device.
try {
  serialManager.open(portId)
  console.info('open usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('open usbSerial error, ' + JSON.stringify(error));
}

// Read data synchronously.
let readSyncBuffer: Uint8Array = new Uint8Array(64);
try {
  serialManager.readSync(portId, readSyncBuffer, 2000);
  console.info('readSync usbSerial success, readSyncBuffer: ' + readSyncBuffer.toString());
} catch (error) {
  console.error('readSync usbSerial error, ' + JSON.stringify(error));
}
```

## serialManager.write

write(portId: number, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt;

Writes data to the serial port device asynchronously.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name    | Type        | Mandatory| Description              |
|---------|------------|----|------------------|
| portId  | number     | Yes | Port number.     |
| buffer  | Uint8Array | Yes | Buffer for writing data.|
| timeout | number     | No | (Optional) Timeout duration, in ms. The default value is **0**, indicating no timeout. You can set this parameter as required.|

**Returns**

| Type                   | Description         |
|-----------------------|-------------|
| Promise&lt;number&gt; | Promise used to return the length of the data written.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |
| 31400005 | The serial port device is not opened. Call the open API first. |
| 31400006 | Data transfer timed out. |
| 31400007 | I/O exception. Possible causes: 1. The transfer was canceled. 2. The device offered more data than allowed. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **addSerialRight** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Open a serial port device.
try {
  serialManager.open(portId)
  console.info('open usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('open usbSerial error, ' + JSON.stringify(error));
}

// Write data asynchronously.
let writeBuffer: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer)
serialManager.write(portId, writeBuffer, 2000).then((size: number) => {
  console.info('write usbSerial success, writeBuffer: ' + writeBuffer.toString());
}).catch((error: Error) => {
  console.error('write usbSerial error, ' + JSON.stringify(error));
})
```

## serialManager.writeSync

writeSync(portId: number, buffer: Uint8Array, timeout?: number): number

Writes data to the serial port device synchronously.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name    | Type        | Mandatory| Description              |
|---------|------------|----|------------------|
| portId  | number     | Yes | Port number.    |
| buffer  | Uint8Array | Yes | Destination buffer for writing data.|
| timeout | number     | No | (Optional) Timeout duration, in ms. The default value is **0**, indicating no timeout. You can set this parameter as required.|

**Returns**

| Type    | Description         |
|--------|-------------|
| number | Length of the data written.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |
| 31400005 | The serial port device is not opened. Call the open API first. |
| 31400006 | Data transfer timed out. |
| 31400007 | I/O exception. Possible causes: 1. The transfer was canceled. 2. The device offered more data than allowed. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **writeSync** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Open a serial port device.
try {
  serialManager.open(portId)
  console.info('open usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('open usbSerial error, ' + JSON.stringify(error));
}

// Write data synchronously.
let writeSyncBuffer: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer)
try {
  serialManager.writeSync(portId, writeSyncBuffer, 2000);
  console.info('writeSync usbSerial success, writeSyncBuffer: ' + writeSyncBuffer.toString());
} catch (error) {
  console.error('writeSync usbSerial error, ' + JSON.stringify(error));
}
```

## serialManager.close

close(portId: number): void

Closes the serial port device.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name   | Type    | Mandatory| Description         |
|--------|--------|----|-------------|
| portId | number | Yes | Port number.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 31400001 | Serial port management exception. |
| 31400003 | PortId does not exist. |
| 31400005 | The serial port device is not opened. Call the open API first. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **close** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Open a serial port device.
try {
  serialManager.open(portId)
  console.info('open usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('open usbSerial error, ' + JSON.stringify(error));
  return;
}

// Close the serial port device.
try {
  serialManager.close(portId);
  console.info('close usbSerial success, portId: ' + portId);
} catch (error) {
  console.error('close usbSerial error, ' + JSON.stringify(error));
}
```

## serialManager.cancelSerialRight

cancelSerialRight(portId: number): void

Cancels the permission to access the serial port device when the application is running. This API is used to close the enabled serial port device.

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name   | Type    | Mandatory| Description                                 |
|--------|--------|----|-------------------------------------|
| portId | number | Yes | Port number.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14400005 | Database operation exception.                                |
| 31400001 | Serial port management exception. |
| 31400002 | Access denied. Call requestSerialRight to request user authorization first. |
| 31400003 | PortId does not exist. |

**Example**

> **NOTE**
>
> The following sample code shows the basic process for calling the **cancelSerialRight** API and it needs to be executed in a specific method. In actual calling, you must comply with the device-related protocols.

<!--code_no_check-->
```ts
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// Obtain the serial port list.
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('usbSerial portList: ' + JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('usbSerial portList is empty');
  return;
}
let portId: number = portList[0].portId;

// Check whether the device can be accessed by the application.
if (!serialManager.hasSerialRight(portId)) {
  serialManager.requestSerialRight(portId).then(result => {
    if (!result) {
      // If the application does not have the access permission and is not granted by the user, the application exits.
      console.info('user is not granted the operation  permission');
      return;
    } else {
      console.info('grant permission successfully');
    }
  });
}

// Cancel the granted permission.
try {
  serialManager.cancelSerialRight(portId);
  console.info('cancelSerialRight success, portId: ', portId);
} catch (error) {
  console.error('cancelSerialRight error, ', JSON.stringify(error));
}
```

## SerialAttribute

Represents the configuration parameters of a serial port.

**System capability**: SystemCapability.USB.USBManager.Serial

| Name      |          Type       |  Read-Only  |  Optional| Description       |
|----------|--------|----------|-----------|----------------------|
| baudRate | [BaudRates](#baudrates) |   No  | No | Baud rate. |
| dataBits | [DataBits](#databits)   |   No  | Yes | Data bits. The default value is **8**. |
| parity   | [Parity](#parity)       |   No  | Yes | Parity check. The default value is **None**, indicating that no parity check is performed.|
| stopBits | [StopBits](#stopbits)   |   No  | Yes | Stop bits. The default value is **1**. |

## SerialPort

Represents the parameters of a serial port.

**System capability**: SystemCapability.USB.USBManager.Serial

| Name    | Type |  Read-Only| Optional| Description   |
|--------|--------|------|-------|--------|
| portId | number | No |  No| Port number.|
| deviceName | string | No |  No| Serial port device name.|

## BaudRates

Enumerates the baud rates.

**System capability**: SystemCapability.USB.USBManager.Serial

| Name    | Value    | Description   |
|-----------|-----------|-----------|
| BAUDRATE_50  | 50  | The baud rate is 50 bit/s. |
| BAUDRATE_75  | 75  | The baud rate is 75 bit/s. |
| BAUDRATE_110  | 110  | The baud rate is 110 bit/s. |
| BAUDRATE_134  | 134  | The baud rate is 134 bit/s. |
| BAUDRATE_150  | 150  | The baud rate is 150 bit/s. |
| BAUDRATE_200  | 200  | The baud rate is 200 bit/s. |
| BAUDRATE_300  | 300  | The baud rate is 300 bit/s. |
| BAUDRATE_600  | 600  | The baud rate is 600 bit/s. |
| BAUDRATE_1200  | 1200  | The baud rate is 1200 bit/s. |
| BAUDRATE_1800  | 1800  | The baud rate is 1800 bit/s. |
| BAUDRATE_2400  | 2400  | The baud rate is 2400 bit/s. |
| BAUDRATE_4800  | 4800  | The baud rate is 4800 bit/s. |
| BAUDRATE_9600  | 9600  | The baud rate is 9600 bit/s. |
| BAUDRATE_19200  | 19200  | The baud rate is 19200 bit/s. |
| BAUDRATE_38400  | 38400  | The baud rate is 38400 bit/s. |
| BAUDRATE_57600  | 57600  | The baud rate is 57600 bit/s. |
| BAUDRATE_115200  | 115200  | The baud rate is 115200 bit/s. |
| BAUDRATE_230400  | 230400  | The baud rate is 230400 bit/s. |
| BAUDRATE_460800  | 460800  | The baud rate is 460800 bit/s. |
| BAUDRATE_500000  | 500000  | The baud rate is 500000 bit/s. |
| BAUDRATE_576000  | 576000  | The baud rate is 576000 bit/s. |
| BAUDRATE_921600  | 921600  | The baud rate is 921600 bit/s. |
| BAUDRATE_1000000  | 1000000  | The baud rate is 1000000 bit/s. |
| BAUDRATE_1152000  | 1152000  | The baud rate is 1152000 bit/s. |
| BAUDRATE_1500000  | 1500000  | The baud rate is 1500000 bit/s. |
| BAUDRATE_2000000  | 2000000  | The baud rate is 2000000 bit/s. |
| BAUDRATE_2500000  | 2500000  | The baud rate is 2500000 bit/s. |
| BAUDRATE_3000000  | 3000000  | The baud rate is 3000000 bit/s. |
| BAUDRATE_3500000  | 3500000  | The baud rate is 3500000 bit/s. |
| BAUDRATE_4000000  | 4000000  | The baud rate is 4000000 bit/s. |

## DataBits

Enumerates the number of data bits.

**System capability**: SystemCapability.USB.USBManager.Serial

| Name    | Value    | Description   |
|-----------|-----------|-----------|
| DATABIT_8 | 8 | The number of data bits is 8.|
| DATABIT_7 | 7 | The number of data bits is 7.|
| DATABIT_6 | 6 | The number of data bits is 6.|
| DATABIT_5 | 5 | The number of data bits is 5.|

## Parity

Enumerates the parity check modes.

**System capability**: SystemCapability.USB.USBManager.Serial

| Name    | Value    | Description   |
|-----------|-----------|-----------|
| PARITY_NONE | 0 | No parity.|
| PARITY_ODD | 1 | Odd parity.|
| PARITY_EVEN | 2 | Even parity.|
| PARITY_MARK | 3 | Mark parity, whose parity bit is fixed at **1**.|
| PARITY_SPACE | 4 | Space parity, whose parity bit is fixed at **0**.|

## StopBits

Enumerates of the number of stop bits.

**System capability**: SystemCapability.USB.USBManager.Serial

| Name    | Value    | Description   |
|-----------|-----------|-----------|
| STOPBIT_1 | 0 | The number of stop bits is 1.|
| STOPBIT_2 | 1 | The number of stop bits is 2.|
