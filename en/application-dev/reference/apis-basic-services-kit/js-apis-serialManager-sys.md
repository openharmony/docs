# @ohos.usbManager.serial (Serial Port Management) (system API)

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

This module provides the serial port management features, including enabling and disabling the serial port of the device, writing and reading data, setting and obtaining the configuration parameters of the serial port, and managing permissions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 19. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.usbManager.serial (USB Manager)](js-apis-serialManager.md).

## Modules to Import

```ts
import { serialManager } from '@kit.BasicServicesKit';
```

## serialManager.addSerialRight

addSerialRight(tokenId: number, portId: number): void

Adds the permission to an application for accessing the serial port device.

**serialManager.requestSerialRight** triggers a dialog box to request user authorization. **addSerialRight** does not trigger a dialog box but directly adds the device access permission for the application. After the application exits, the access permission on the serial port device is automatically removed. After the application is restarted, you need to request the permission again.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USB_CONFIG

**System capability**: SystemCapability.USB.USBManager.Serial

**Parameters**

| Name    | Type    | Mandatory| Description                                 |
|---------|--------|----|-------------------------------------|
| tokenId | number | Yes | ID of the token that requires the access permission.                 |
| portId  | number | Yes | Port number.|

**Error codes**

For details about the error codes, see [USB Service Error Codes](errorcode-usb.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14400005 | Database operation exception. |
| 31400001 | Serial port management exception. |
| 31400003 | Device does not exist. |

**Example**
```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
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
// Add permissions to the serial port.
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo) => {
  console.info('getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(bundleInfo));
  let tokenId = bundleInfo.appInfo.accessTokenId;
  try {
    serialManager.addSerialRight(tokenId, portId);
    console.info('addSerialRight success, portId: ' + portId);
  } catch (error) {
    console.error('addSerialRight error, ' + JSON.stringify(error));
  }
}).catch((err : BusinessError) => {
  console.error('getBundleInfoForSelf failed');
});
```
