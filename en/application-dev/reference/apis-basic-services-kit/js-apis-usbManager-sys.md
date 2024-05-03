# @ohos.usbManager (USB Manager) (System API)

The **usbManager** module provides USB device management functions, including USB device list query, bulk data transfer, control transfer, and permission control on the host side as well as port management, and function switch and query on the device side.

>  **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.usbManager (USB Manager)](js-apis-usbManager.md).

## Modules to Import

```ts
import usb from "@ohos.usbManager";
```

## usb.addRight

addRight(bundleName: string, deviceName: string): boolean

Adds the device access permission for the application. System applications are granted the device access permission by default, and calling this API will not revoke the permission.

[usb.requestRight](#usbrequestright) triggers a dialog box to request for user authorization, whereas **addRight** adds the access permission directly without displaying a dialog box. 

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

```ts
let devicesName: string = "1-1";
let bundleName: string = "com.example.hello";
if (usb.addRight(bundleName, devicesName)) {
  console.log(`Succeed in adding right`);
}
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

```ts
let funcs: string = "acm";
let ret: number = usb.usbFunctionsFromString(funcs);
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

```ts
let funcs: number = usb.FunctionType.ACM | usb.FunctionType.ECM;
let ret: string = usb.usbFunctionsToString(funcs);
```

## usb.setCurrentFunctions

setCurrentFunctions(funcs: FunctionType): Promise\<void\>

Sets the current USB function list in Device mode.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                          | Mandatory| Description             |
| ------ | ------------------------------ | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                          |
| -------- | ---------------------------------------------------- |
| 14400002 | Permission denied.The HDC is disabled by the system. |

**Return value**

| Type           | Description         |
| --------------- | ------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
let funcs: number = usb.FunctionType.HDC;
usb.setCurrentFunctions(funcs).then(() => {
    console.info('usb setCurrentFunctions successfully.');
}).catch((err: BusinessError) => {
    console.error('usb setCurrentFunctions failed: ' + err.code + ' message: ' + err.message);
});
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

```ts
let ret: number = usb.getCurrentFunctions();
```

## usb.getPorts

getPorts(): Array\<USBPort\>

Obtains the list of all physical USB ports.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                         | Description                 |
| ----------------------------- | --------------------- |
| Array&lt;[USBPort](#usbport)&gt; | List of physical USB ports.|

**Example**

```ts
let ret: Array<usb.USBPort> = usb.getPorts();
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

```ts
let ret: number = usb.getSupportedModes(0);
```

## usb.setPortRoles

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

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

| Type           | Description         |
| --------------- | ------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@ohos.base';
let portId: number = 1;
usb.setPortRoles(portId, usb.PowerRoleType.SOURCE, usb.DataRoleType.HOST).then(() => {
    console.info('usb setPortRoles successfully.');
}).catch((err: BusinessError) => {
    console.error('usb setPortRoles failed: ' + err.code + ' message: ' + err.message);
});
```

## USBPort

Represents a USB port.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name          | Type                        | Mandatory     |Description                               |
| -------------- | ------------------------------- | ------------------- |------------------------ |
| id             | number                          | Yes  |Unique identifier of a USB port.                  |
| supportedModes | [PortModeType](#portmodetype)   | Yes  |Numeric mask combination for the supported mode list.|
| status         | [USBPortStatus](#usbportstatus) | Yes  |USB port role.                      |

## USBPortStatus

Enumerates USB port roles.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name            | Type| Mandatory     |Description                  |
| ---------------- | -------- | ---------------- |---------------------- |
| currentMode      | number   | Yes|Current USB mode.       |
| currentPowerRole | number   | Yes  |Current power role.    |
| currentDataRole  | number   | Yes  |Current data role.|

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
| NONE      | 0    | None                                                |
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
| NONE   | 0    | None      |
| SOURCE | 1    | External power supply.|
| SINK   | 2    | Internal power supply.|

## DataRoleType

Enumerates data role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value  | Description        |
| ------ | ---- | ------------ |
| NONE   | 0    | None        |
| HOST   | 1    | USB host.|
| DEVICE | 2    | USB device.|
