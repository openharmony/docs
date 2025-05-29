# @ohos.usbManager (USB Manager) (System API)

The **usbManager** module provides USB device management functions, including USB device list query, bulk data transfer, control transfer, and permission control on the host side as well as port management, and function switch and query on the device side.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.usbManager (USB Manager)](js-apis-usbManager.md).

## Modules to Import

```ts
import { usbManager } from '@kit.BasicServicesKit';
```

## addRight <sup>(deprecated)</sup>

addRight(bundleName: string, deviceName: string): boolean

Adds the device access permission for the application. System applications are granted the device access permission by default, and calling this API will not revoke the permission.

**usbManager.requestRight** triggers a dialog box to request for user authorization, whereas **addRight** adds the access permission directly without displaying a dialog box.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [addDeviceAccessRight](#adddeviceaccessright12).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | ------------ |
| deviceName | string | Yes  | Device name.  |
| bundleName | string | Yes  | Bundle name of the application.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |

**Return value**

| Type   | Description                                                                     |
| ------- | ------------------------------------------------------------------------- |
| boolean | Permission addition result. The value **true** indicates that the access permission is added successfully; and the value **false** indicates the opposite.|

**Example**

```ts
let devicesName: string = "1-1";
let bundleName: string = "com.example.hello";
if (usbManager.addRight(bundleName, devicesName)) {
  console.log(`Succeed in adding right`);
}
```

## usbFunctionsFromString<sup>(deprecated)</sup>

usbFunctionsFromString(funcs: string): number

Converts the USB function list in the string format to a numeric mask in Device mode.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [getFunctionsFromString](#getfunctionsfromstring12).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| funcs  | string | Yes  | Function list in string format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Function list in numeric mask format.|

**Example**

```ts
let funcs: string = "acm";
let ret: number = usbManager.usbFunctionsFromString(funcs);
```

## usbFunctionsToString<sup>(deprecated)</sup>

usbFunctionsToString(funcs: FunctionType): string

Converts the USB function list in the numeric mask format to a string in Device mode.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [getStringFromFunctions](#getstringfromfunctions12).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                         | Mandatory| Description             |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| string | Function list in string format.|

**Example**

```ts
let funcs: number = usbManager.FunctionType.ACM | usb.FunctionType.ECM;
let ret: string = usbManager.usbFunctionsToString(funcs);
```

## setCurrentFunctions<sup>(deprecated)</sup>

setCurrentFunctions(funcs: FunctionType): Promise\<void\>

Sets the current USB function list in Device mode.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [setDeviceFunctions](#setdevicefunctions12).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                         | Mandatory| Description             |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 14400002 | Permission denied. The HDC is disabled by the system.                                                   |

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@kit.BasicServicesKit';
let funcs: number = usbManager.FunctionType.HDC;
usbManager.setCurrentFunctions(funcs).then(() => {
    console.info('usb setCurrentFunctions successfully.');
}).catch((err: BusinessError) => {
    console.error('usb setCurrentFunctions failed: ' + err.code + ' message: ' + err.message);
});
```

## getCurrentFunctions<sup>(deprecated)</sup>

getCurrentFunctions(): FunctionType

Obtains the numeric mask combination for the USB function list in Device mode. When the developer mode is disabled, **undefined** may be returned if no device is connected. Check whether the return value of the API is empty.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [getDeviceFunctions](#getdevicefunctions12).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                       |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. No parameters are required.                                    |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**Return value**

| Type                         | Description                             |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | Numeric mask combination for the USB function list.|

**Example**

```ts
let ret: number = usbManager.getCurrentFunctions();
```

## getPorts<sup>(deprecated)</sup>

getPorts(): Array\<USBPort\>

Obtains the list of all physical USB ports. When the developer mode is disabled, **undefined** may be returned if no device is connected. Check whether the return value of the API is empty.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [getPortList](#getportlist12).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                       |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. No parameters are required.                                    |
| 202      | Permission denied. Normal application do not have permission to use system api. |

**Return value**

| Type                      | Description                 |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | List of physical USB ports.|

**Example**

```ts
let ret: Array<usbManager.USBPort> = usbManager.getPorts();
```

## getSupportedModes(deprecated)

getSupportedModes(portId: number): PortModeType

Obtains the mask combination for the supported mode list of a given USB port.

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [getPortSupportModes](#getportsupportmodes12) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| portId | number | Yes  | Port number.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |

**Return value**

| Type                         | Description                      |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | Mask combination for the supported mode list.|

**Example**

```ts
let ret: number = usbManager.getSupportedModes(0);
```

## setPortRoles<sup>(deprecated)</sup>

setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

Sets the role types supported by a specified port, which can be **powerRole** (for charging) and **dataRole** (for data transfer).

**NOTE**

> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [setPortRoleTypes](#setportroletypes12).

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type                           | Mandatory| Description            |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | Yes  | Port number.        |
| powerRole | [PowerRoleType](#powerroletype) | Yes  | Role for charging.    |
| dataRole  | [DataRoleType](#dataroletype)   | Yes  | Role for data transfer.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import {BusinessError} from '@kit.BasicServicesKit';
let portId: number = 1;
usbManager.setPortRoles(portId, usbManager.PowerRoleType.SOURCE, ususbManagerb.DataRoleType.HOST).then(() => {
    console.info('usb setPortRoles successfully.');
}).catch((err: BusinessError) => {
    console.error('usb setPortRoles failed: ' + err.code + ' message: ' + err.message);
});
```

## addDeviceAccessRight<sup>12+</sup>

addDeviceAccessRight(tokenId: string, deviceName: string): boolean

Adds the device access permission for the application. System applications are granted the device access permission by default, and calling this API will not revoke the permission.

**usbManager.requestRight** triggers a dialog box to request for user authorization, whereas **addDeviceAccessRight** adds the access permission directly without displaying a dialog box.

**NOTE**

> This API is supported since API version 12.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name    | Type  | Mandatory| Description           |
| ---------- | ------ | ---- | --------------- |
| deviceName | string | Yes  | Device name.     |
| tokenId    | string | Yes  | Token ID of the software package.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |

**Return value**

| Type   | Description                                                                     |
| ------- | ------------------------------------------------------------------------- |
| boolean | Permission addition result. The value **true** indicates that the access permission is added successfully; and the value **false** indicates the opposite.|

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let devicesName: string = "1-1";
let tokenId: string = "";

  try {
    let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
    bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo) => {
      console.info('testTag', 'getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(bundleInfo));
      let token = bundleInfo.appInfo.accessTokenId;
      tokenId = token.toString();
      if (usbManager.addDeviceAccessRight(tokenId, devicesName)) {
        console.log(`Succeed in adding right`);
      }
    }).catch((err : BusinessError) => {
      console.error('testTag getBundleInfoForSelf failed' );
    });
  } catch (err) {
    console.error('testTag failed');
  }
```

## getFunctionsFromString<sup>12+</sup>

getFunctionsFromString(funcs: string): number

Converts the USB function list in the string format to a numeric mask in Device mode.

**NOTE**

> This API is supported since API version 12.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| funcs  | string | Yes  | Function list in string format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                       |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. |
| 801      | Capability not supported.                                    |

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Function list in numeric mask format.|

**Example**

```ts
let funcs: string = "acm";
let ret: number = usbManager.getFunctionsFromString(funcs);
```

## getStringFromFunctions<sup>12+</sup>

getStringFromFunctions(funcs: FunctionType): string

Converts the USB function list in the numeric mask format to a string in Device mode.

**NOTE**

> This API is supported since API version 12.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                         | Mandatory| Description             |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| string | Function list in string format.|

**Example**

```ts
let funcs: number = usbManager.FunctionType.ACM | usbManager.FunctionType.ECM;
let ret: string = usbManager.getStringFromFunctions(funcs);
```

## setDeviceFunctions<sup>12+</sup>

setDeviceFunctions(funcs: FunctionType): Promise\<void\>

Sets the current USB function list in Device mode.

**NOTE**

> This API is supported since API version 12.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type                         | Mandatory| Description             |
| ------ | ----------------------------- | ---- | ----------------- |
| funcs  | [FunctionType](#functiontype) | Yes  | USB function list in numeric mask format.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |
| 14400002 | Permission denied. The HDC is disabled by the system.                                                   |
| 14400006 | Unsupported operation. The function is not supported.                                                   |

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let funcs: number = usbManager.FunctionType.HDC;
usbManager.setDeviceFunctions(funcs).then(() => {
    console.info('usb setDeviceFunctions successfully.');
}).catch((err : BusinessError) => {
    console.error('usb setDeviceFunctions failed: ' + err.code + ' message: ' + err.message);
});
```

## getDeviceFunctions<sup>12+</sup>

getDeviceFunctions(): FunctionType

Obtains the numeric mask combination for the USB function list in Device mode. When the developer mode is disabled, **undefined** may be returned if no device is connected. Check whether the return value of the API is empty.

**NOTE**

> This API is supported since API version 12.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                       |
| -------- | ------------------------------------------------------------------------------- |
| 401      | Parameter error. No parameters are required.                                    |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api. |
| 801      | Capability not supported.                                    |

**Return value**

| Type                         | Description                             |
| ----------------------------- | --------------------------------- |
| [FunctionType](#functiontype) | Numeric mask combination for the USB function list.|

**Example**

```ts
let ret: number = usbManager.getDeviceFunctions();
```

## getPortList<sup>12+</sup>

getPortList(): Array\<USBPort\>

Obtains the list of all physical USB ports. When the developer mode is disabled, **undefined** may be returned if no device is connected. Check whether the return value of the API is empty.

**NOTE**

> This API is supported since API version 12.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |

**Return value**

| Type                      | Description                 |
| -------------------------- | --------------------- |
| Array<[USBPort](#usbport)> | List of physical USB ports.|

**Example**

```ts
let ret: Array<usbManager.USBPort> = usbManager.getPortList();
```

## getPortSupportModes<sup>12+</sup>

getPortSupportModes(portId: number): PortModeType

Obtains the mask combination for the supported mode list of a given USB port.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| portId | number | Yes  | Port number.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |

**Return value**

| Type                         | Description                      |
| ----------------------------- | -------------------------- |
| [PortModeType](#portmodetype) | Mask combination for the supported mode list.|

**Example**

```ts
let ret: number = usbManager.getPortSupportModes(0);
```

## setPortRoleTypes<sup>12+</sup>

setPortRoleTypes(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void\>

Sets the role types supported by a specified port, which can be **powerRole** (for charging) and **dataRole** (for data transfer).

**NOTE**

> This API is supported since API version 12.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type                           | Mandatory| Description            |
| --------- | ------------------------------- | ---- | ---------------- |
| portId    | number                          | Yes  | Port number.        |
| powerRole | [PowerRoleType](#powerroletype) | Yes  | Role for charging.    |
| dataRole  | [DataRoleType](#dataroletype)   | Yes  | Role for data transfer.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                                                               |
| -------- | ------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission denied. Normal application do not have permission to use system api.                         |
| 801      | Capability not supported.                                    |
| 14400003 | Unsupported operation. The current device does not support port role switching.                         |

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let portId: number = 1;
usbManager.setPortRoleTypes(portId, usbManager.PowerRoleType.SOURCE, usbManager.DataRoleType.HOST).then(() => {
  console.info('usb setPortRoleTypes successfully.');
}).catch((err : BusinessError) => {
  console.error('usb setPortRoleTypes failed: ' + err.code + ' message: ' + err.message);
});
```

## addAccessoryRight<sup>14+</sup>

addAccessoryRight(tokenId: number, accessory: USBAccessory): void

Adds the permission to applications for accessing USB accessories.

**usbManager.requestAccessoryRight** triggers a dialog box to request user authorization. **addAccessoryRight** does not trigger a dialog box but directly adds the device access permission for the application.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager

**Parameters**

| Name   | Type        | Mandatory| Description                    |
| --------- | ------------ | ---- | ------------------------ |
| tokenId   | number       | Yes  | Token ID of the application.|
| accessory | USBAccessory | Yes  | USB accessory.               |

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The permission check failed.                                 |
| 202      | Permission denied. Normal application do not have permission to use system api. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801      | Capability not supported.                                    |
| 14400004 | Service exception. Possible causes: 1. No accessory is plugged in. |
| 14400005 | Database operation exception.                                |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { bundleManager } from '@kit.AbilityKit';
try {
  let accList: usbManager.USBAccessory[] = usbManager.getAccessoryList()
  let flags = bundleManager.BundleFlah.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY
  let bundleInfo = await bundleManager.getBundleInfoForSelf(flags)
  let tokenId: number = bundleInfo.appInfo.accessTokenId
  usbManager.addAccessoryRight(tokenId, accList[0])
  hilog.info(0, 'testTag ui', `addAccessoryRight success`)
} catch (error) {
  hilog.info(0, 'testTag ui', `addAccessoryRight error ${error.code}, message is ${error.message}`)
}
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
| MTP          | 8   | Media transmission.|
| PTP          | 16  | Image transmission.|
| RNDIS        | 32  | Network sharing (not supported).|
| MIDI         | 64  | MIDI function (not supported).|
| AUDIO_SOURCE | 128 | Audio function (not supported).|
| NCM          | 256 | NCM transmission (not supported). |

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
| SOURCE | 1  | Power supply for external devices.|
| SINK   | 2  | External power supply.|

## DataRoleType

Enumerates data role types.

**System API**: This is a system API.

**System capability**: SystemCapability.USB.USBManager

| Name  | Value| Description        |
| ------ | -- | ------------ |
| NONE   | 0  | None        |
| HOST   | 1  | USB host.|
| DEVICE | 2  | USB device.|
