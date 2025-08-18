# USB Subsystem Changelog

## cl.usbManager.1 Change of Error Code from 202 to 201 for Calling a System API When the ohos.permission.MANAGE_USB_CONFIG Permission Is Missing

**Access Level**

System API

**Reason for the Change**

When the system API is called, the **ohos.permission.MANAGE_USB_CONFIG** permission must be added to the **permission** field in the system application configuration file. If the permission is not configured, error code 201 is returned.

**Change Impact**

This change is a non-compatible change.

The following is an example:

```ts
import { usbManager } from '@kit.BasicServicesKit';
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

Before change: When the system application calls a system API, if the **ohos.permission.MANAGE_USB_CONFIG** permission is not configured in the **permission** field in the configuration file, error code 202 is returned.

After change: When the system application calls a system API, if the **ohos.permission.MANAGE_USB_CONFIG** permission is not configured in the **permission** field in the configuration file, error code 201 is returned.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.1.0.45 and later versions

**Key API/Component Changes**

|            API           |               Description              |
| :----------------------------: | :----------------------------------: |
| addDeviceAccessRight(tokenId: string, deviceName: string): boolean | Added error code 201.| 
| getFunctionsFromString(funcs: string): number | Added error code 201.|
| getStringFromFunctions(funcs: FunctionType): string | Added error code 201.|
| setDeviceFunctions(funcs: FunctionType): Promise\<void> | Added error code 201.|
| getDeviceFunctions(): FunctionType | Added error code 201.|
| getPortList(): Array\<USBPort> | Added error code 201.|
| getPortSupportModes(portId: number): PortModeType | Added error code 201.|
| setPortRoleTypes(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void> | Added error code 201.|


**Adaptation Guide**

Add error code 201 for the system application to call system APIs when the **ohos.permission.MANAGE_USB_CONFIG** permission is not configured in the **permission** field in the system application configuration file.
