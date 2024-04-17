# @ohos.usbManager (USB Manager) (System API)

The **usbManager** module provides USB device management functions, including USB device list query, bulk data transfer, control transfer, and permission control on the host side as well as port management, and function switch and query on the device side.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.usbManager (USB Manager)](js-apis-usbManager.md).

## Modules to Import

```ts
import usb from "@ohos.usbManager";
```

## usb.addRight (deprecated)

addRight(bundleName: string, deviceName: string): boolean

Adds the device access permission for the application. System applications are granted the device access permission by default, and calling this API will not revoke the permission.

[usb.requestRight](js-apis-usbManager.md#usbrequestright) triggers a dialog box to request for user authorization, whereas **addRight** adds the access permission directly without displaying a dialog box. 

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use **addDeviceAccessRight**.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | ------------ |
| deviceName | string | Yes  | Device name.  |
| bundleName | string | Yes  | Bundle name of the application.|

**Return value**

| Type   | Description                                                                     |
| ------- | ------------------------------------------------------------------------- |
| boolean | Permission addition result. The value **true** indicates that the access permission is added successfully; and the value **false** indicates the opposite.|

**Example**

```ts
let devicesName: string = "1-1";
let bundleName: string = "com.example.hello";
if (usb.addRight(bundleName, devicesName)) {
  console.log(`Succeed in adding right`);
}
```

## usb.usbFunctionsFromString(deprecated)

usbFunctionsFromString(funcs: string): number

Converts the USB function list in the string format to a numeric mask in Device mode.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use **getFunctionsFromString**.

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

## usb.usbFunctionsToString(deprecated)

usbFunctionsToString(funcs: FunctionType): string

Converts the USB function list in the numeric mask format to a string in Device mode.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use **getStringFromFunctions**.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                         | Mandatory| Description             |
| ------ | ----------------------------- | ---- | ----------------- |
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

## usb.setCurrentFunctions(deprecated)

setCurrentFunctions(funcs: FunctionType): Promise\<void\>

Sets the current USB function list in Device mode.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use **setDeviceFunctions**.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                         | Mandatory| Description             |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 14400002 | Permission denied.The HDC is disabled by the system. |

**Return value**

| Type    | Description         |
| -------- | ------------- |
| Promise\<**void**\> | Promise used to return the result.|

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

## usb.getCurrentFunctions(deprecated)

getCurrentFunctions(): FunctionType

Obtains the numeric mask combination for the USB function list in Device mode.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use **getDeviceFunctions**.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                         | Description                             |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | Numeric mask combination for the USB function list.|

**Example**

```ts
let ret: number = usb.getCurrentFunctions();
```

## usb.getPorts(deprecated)

getPorts(): Array\<USBPort\>

Obtains the list of all physical USB ports.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use **getPortList**.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                      | Description                 |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | List of physical USB ports.|

**Example**

```ts
let ret: Array<usb.USBPort> = usb.getPorts();
```

## usb.getSupportedModes(deprecated)

getSupportedModes(portId: number): PortModeType

Obtains the mask combination for the supported mode list of a given USB port.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use **getPortSupportModes**.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| portId | number | Yes  | Port number.|

**Return value**

| Type                         | Description                      |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | Mask combination for the supported mode list.|

**Example**

```ts
let ret: number = usb.getSupportedModes(0);
```

## usb.setPortRoles(deprecated)

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

Sets the role types supported by a specified port, which can be **powerRole** (for charging) and **dataRole** (for data transfer).

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use **setPortRoleTypes**.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type                           | Mandatory| Description            |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | Yes  | Port number.        |
| powerRole | [PowerRoleType](#powerroletype) | Yes  | Role for charging.    |
| dataRole  | [DataRoleType](#dataroletype)   | Yes  | Role for data transfer.|

**Return value**

| Type    | Description         |
| -------- | ------------- |
| Promise\<**void**\> | Promise used to return the result.|

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

## usb.addDeviceAccessRight

addDeviceAccessRight(tokenId: string, deviceName: string): boolean

Adds the device access permission for the application. System applications are granted the device access permission by default, and calling this API will not revoke the permission.

[usb.requestRight](js-apis-usbManager.md#usbrequestright) triggers a dialog box to request for user authorization, whereas **addDeviceAccessRight** adds the access permission directly without displaying a dialog box. 

**System API**: This is a system API.

**Required permissions**: ohos.permission.ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name    | Type  | Mandatory| Description           |
| ---------- | ------ | ---- | --------------- |
| deviceName | string | Yes  | Device name.     |
| tokenId    | string | Yes  | Token ID of the software package.|

**Return value**

| Type   | Description                                                                     |
| ------- | ------------------------------------------------------------------------- |
| boolean | Permission addition result. The value **true** indicates that the access permission is added successfully; and the value **false** indicates the opposite.|

**Example**

```ts
 import bundleManager from '@ohos.bundle.bundleManager';
 let devicesName: string = "1-1";
 let tokenId: string = "";

  try {
    let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
    bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo) => {
      console.info('testTag', 'getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(bundleInfo));
      let token = bundleInfo.appInfo.accessTokenId;
      tokenId = token.toString();
      if (usb.addDeviceAccessRight(tokenId, devicesName)) {
        console.log(`Succeed in adding right`);
      }
    }).catch(err => {
      console.error('testTag getBundleInfoForSelf failed' );
    });
  } catch (err) {
    console.error('testTag failed');
  }
```

## usb.getFunctionsFromString

getFunctionsFromString(funcs: string): number

Converts the USB function list in the string format to a numeric mask in Device mode.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ohos.permission.MANAGE_USB_CONFIG

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
let ret: number = usb.getFunctionsFromString(funcs);
```

## usb.getStringFromFunctions

getStringFromFunctions(funcs: FunctionType): string

Converts the USB function list in the numeric mask format to a string in Device mode.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                         | Mandatory| Description             |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| string | Function list in string format.|

**Example**

```ts
let funcs: number = usb.FunctionType.ACM | usb.FunctionType.ECM;
let ret: string = usb.getStringFromFunctions(funcs);
```

## usb.setDeviceFunctions

setDeviceFunctions(funcs: FunctionType): Promise\<void\>

Sets the current USB function list in Device mode.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                         | Mandatory| Description             |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.The HDC is disabled by the system. |

**Return value**

| Type    | Description         |
| -------- | ------------- |
| Promise\<**void**\> | Promise used to return the result.|

**Example**

```ts
let funcs: number = usb.FunctionType.HDC;
usb.setDeviceFunctions(funcs).then(() => {
    console.info('usb setDeviceFunctions successfully.');
}).catch((err) => {
    console.error('usb setDeviceFunctions failed: ' + err.code + ' message: ' + err.message);
});
```

## usb.getDeviceFunctions

getDeviceFunctions(): FunctionType

Obtains the numeric mask combination for the USB function list in Device mode.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                         | Description                             |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | Numeric mask combination for the USB function list.|

**Example**

```ts
let ret: number = usb.getDeviceFunctions();
```

## usb.getPortList

getPortList(): Array\<USBPort\>

Obtains the list of all physical USB ports.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Return value**

| Type                      | Description                 |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | List of physical USB ports.|

**Example**

```ts
let ret: Array<usb.USBPort> = usb.getPortList();
```

## usb.getPortSupportModes

getPortSupportModes(portId: number): PortModeType

Obtains the mask combination for the supported mode list of a given USB port.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| portId | number | Yes  | Port number.|

**Return value**

| Type                         | Description                      |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | Mask combination for the supported mode list.|

**Example**

```ts
let ret: number = usb.getSupportedModes(0);
```

## usb.setPortRoleTypes

setPortRoleTypes(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

Sets the role types supported by a specified port, which can be **powerRole** (for charging) and **dataRole** (for data transfer).

**System API**: This is a system API.

**Required permissions**: ohos.permission.ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type                           | Mandatory| Description            |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | Yes  | Port number.        |
| powerRole | [PowerRoleType](#powerroletype) | Yes  | Role for charging.    |
| dataRole  | [DataRoleType](#dataroletype)   | Yes  | Role for data transfer.|

**Return value**

| Type    | Description         |
| -------- | ------------- |
| Promise\<**void**\> | Promise used to return the result.|

**Example**

```ts
let portId: number = 1;
usb.setPortRoleTypes(portId, usb.PowerRoleType.SOURCE, usb.DataRoleType.HOST).then(() => {
  console.info('usb setPortRoleTypes successfully.');
}).catch((err) => {
  console.error('usb setPortRoleTypes failed: ' + err.code + ' message: ' + err.message);
});
```

## USBPort

Represents a USB port.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name          | Type                           | Mandatory| Description                               |
| -------------- | ------------------------------- | ---- | ----------------------------------- |
| id             | number                          | Yes  | Unique identifier of a USB port.                  |
| supportedModes | [PortModeType](#portmodetype)   | Yes  | Numeric mask combination for the supported mode list.|
| status         | [USBPortStatus](#usbportstatus) | Yes  | USB port role.                      |

## USBPortStatus

Enumerates USB port roles.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name            | Type  | Mandatory| Description                  |
| ---------------- | ------ | ---- | ---------------------- |
| currentMode      | number | Yes  | Current USB mode.       |
| currentPowerRole | number | Yes  | Current power role.    |
| currentDataRole  | number | Yes  | Current data role.|

## FunctionType

Enumerates USB device function types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name        | Value | Description      |
| ------------ | --- | ---------- |
| NONE         | 0   | No function.|
| ACM          | 1   | ACM function. |
| ECM          | 2   | ECM function. |
| HDC          | 4   | HDC function. |
| MTP          | 8   | Not supported currently.|
| PTP          | 16  | Not supported currently.|
| RNDIS        | 32  | Not supported currently.|
| MIDI         | 64  | Not supported currently.|
| AUDIO_SOURCE | 128 | Not supported currently.|
| NCM          | 256 | Not supported currently.|

## PortModeType

Enumerates USB port mode types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name     | Value| Description                                                |
| --------- | -- | ---------------------------------------------------- |
| NONE      | 0  | None                                                |
| UFP       | 1  | Upstream facing port, which functions as the sink of power supply.                            |
| DFP       | 2  | Downstream facing port, which functions as the source of power supply.                            |
| DRP       | 3  | Dynamic reconfiguration port (DRP), which can function as the DFP (host) or UFP (device). It is not supported currently.|
| NUM_MODES | 4  | Not supported currently.                                        |

## PowerRoleType

Enumerates power role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value| Description      |
| ------ | -- | ---------- |
| NONE   | 0  | None      |
| SOURCE | 1  | External power supply.|
| SINK   | 2  | Internal power supply.|

## DataRoleType

Enumerates data role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value| Description        |
| ------ | -- | ------------ |
| NONE   | 0  | None        |
| HOST   | 1  | USB host.|
| DEVICE | 2  | USB device.|
