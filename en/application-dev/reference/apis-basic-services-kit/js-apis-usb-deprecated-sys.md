# @ohos.usb (USB Manager) (No Longer Maintained) (System API)

The **usb** module provides USB device management functions, including USB device list query, bulk data transfer, control transfer, and permission control.

>  **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are no longer maintained since API version 9. You are advised to use [`@ohos.usbManager`](js-apis-usbManager.md).
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.usb (USB Manager) (No Longer Maintained)](js-apis-usb-deprecated.md).

## Modules to Import

```js
import usb from "@ohos.usb";
import { BusinessError } from '@ohos.base';
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
let funcs = usb.FunctionType.ACM | usb.FunctionType.ECM;
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
let funcs : number = usb.FunctionType.HDC;
usb.setCurrentFunctions(funcs).then(() => {
    console.info('usb setCurrentFunctions successfully.');
}).catch((err : BusinessError) => {
    console.error('usb setCurrentFunctions failed: ' + err.code + ' message: ' + err.message);
});
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
let portId = 1;
usb.setPortRoles(portId, usb.PowerRoleType.SOURCE, usb.DataRoleType.HOST).then(() => {
    console.info('usb setPortRoles successfully.');
}).catch((err : BusinessError) => {
    console.error('usb setPortRoles failed: ' + err.code + ' message: ' + err.message);
});
```

## USBPort<sup>9+</sup>

Represents a USB port.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name          | Type                        | Mandatory|Description                               |
| -------------- | -------------------------------- | -------------- |----------------------------------- |
| id             | number                           | Yes  |Unique identifier of a USB port.                  |
| supportedModes | [PortModeType](#portmodetype9)   | Yes  |Numeric mask combination for the supported mode list.|
| status         | [USBPortStatus](#usbportstatus9) | Yes  |USB port role.                      |

## USBPortStatus<sup>9+</sup>

Enumerates USB port roles.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name            | Type| Mandatory|Description                  |
| ---------------- | -------- | ----------- |---------------------- |
| currentMode      | number   | Yes  |Current USB mode.       |
| currentPowerRole | number   | Yes  |Current power role.    |
| currentDataRole  | number   | Yes  |Current data role.|

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
| NONE      | 0    | None                                                |
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
| NONE   | 0    | None      |
| SOURCE | 1    | External power supply.|
| SINK   | 2    | Internal power supply.|

## DataRoleType<sup>9+</sup>

Enumerates data role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value  | Description        |
| ------ | ---- | ------------ |
| NONE   | 0    | None        |
| HOST   | 1    | USB host.|
| DEVICE | 2    | USB device.|
