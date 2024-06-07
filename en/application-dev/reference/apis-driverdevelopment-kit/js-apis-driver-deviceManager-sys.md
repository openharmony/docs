# @ohos.driver.deviceManager (Peripheral Management) (System API)

The **deviceManager** module provides the functions of managing peripheral devices, including querying information about peripherals and their drivers.

>  **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.driver.deviceManager (Peripheral Management)](js-apis-driver-deviceManager.md).

## Modules to Import

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
```

## deviceManager.queryDeviceInfo

queryDeviceInfo(deviceId?: number): Array&lt;Readonly&lt;DeviceInfo&gt;&gt;

Obtains the list of detailed information about peripherals.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name     | Type    | Mandatory | Description                    |
|----------|--------|-----|------------------------|
| deviceId | number | No  | Device ID, which can be obtained by **queryDevices**.|

**Return value**

| Type                                                    | Description         |
|--------------------------------------------------------|-------------|
| Array&lt;Readonly&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | List of detailed information about peripherals.|

**Error codes**

| ID   | Error Message                                                                 |
|----------|-----------------------------------------------------------------------|
| 201      | The permission check failed.                                          |
| 202      | Permission denied. A non-system application cannot call a system API. |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types.        |
| 26300001 | ExternalDeviceManager service exception.                              |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  let deviceInfos : Array<deviceManager.DeviceInfo> = deviceManager.queryDeviceInfo(12345678);
  for (let item of deviceInfos) {
    console.info(`Device id is ${item.deviceId}`)
  }
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to query device info. Code is ${err.code}, message is ${err.message}`);
}
```
## deviceManager.queryDriverInfo

queryDriverInfo(driverUid?: string): Array&lt;Readonly&lt;DriverInfo&gt;&gt;

Obtains the list of detailed information about peripheral drivers.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name      | Type    | Mandatory | Description                        |
|-----------|--------|-----|----------------------------|
| driverUid | string | No  | Driver UID, which can be obtained by using **queryDeviceInfo**.|

**Return value**

| Type                                                    | Description           |
|--------------------------------------------------------|---------------|
| Array&lt;Readonly&lt;[DriverInfo](#driverinfo)&gt;&gt; | List of detailed information about peripheral drivers.|

**Error codes**

| ID   | Error Message                                                                 |
|----------|-----------------------------------------------------------------------|
| 201      | The permission check failed.                                          |
| 202      | Permission denied. A non-system application cannot call a system API. |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types.        |
| 26300001 | ExternalDeviceManager service exception.                              |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // In this example, driver-12345 is the driver UID. During application development, you can use queryDeviceInfo to query the driver UID and use it as the input parameter.
  let driverInfos : Array<deviceManager.DriverInfo> = deviceManager.queryDriverInfo("driver-12345");
  for (let item of driverInfos) {
    console.info(`driver name is ${item.driverName}`)
  }
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to query driver info. Code is ${err.code}, message is ${err.message}`);
}
```

## DeviceInfo

Defines the detailed information about a device.

**System capability**: SystemCapability.Driver.ExternalDevice

| Name             | Type     | Mandatory | Description         |
|-----------------|---------|-----|-------------|
| deviceId        | number  | Yes  | Device ID.      |
| isDriverMatched | boolean | Yes  | Whether the device matches the driver. |
| driverUid       | string  | No  | UID of the driver matching the device.|

## USBDeviceInfo

Defines detailed information about the USB device. It is inherited from [DeviceInfo](#deviceinfo).

**System capability**: SystemCapability.Driver.ExternalDevice

| Name               | Type                                                                | Mandatory | Description              |
|-------------------|--------------------------------------------------------------------|-----|------------------|
| vendorId          | number                                                             | Yes  | Vendor ID of the USB device. |
| productId         | number                                                             | Yes  | Product ID of the USB device.|
| interfaceDescList | Array&lt;Readonly&lt;[USBInterfaceDesc](#usbinterfacedesc)&gt;&gt; | Yes  | List of interface descriptors of the USB device.   |

## USBInterfaceDesc

Defines the interface descriptor of a USB device.

**System capability**: SystemCapability.Driver.ExternalDevice

| Name              | Type    | Mandatory | Description    |
|------------------|--------|-----|--------|
| bInterfaceNumber | number | Yes  | Interface ID. |
| bClass           | number | Yes  | Interface class. |
| bSubClass        | number | Yes  | Interface subclass.|
| bProtocol        | number | Yes  | Interface protocol. |

## DriverInfo

Defines detailed information about a driver.

**System capability**: SystemCapability.Driver.ExternalDevice

| Name           | Type                                                | Mandatory | Description            |
|---------------|----------------------------------------------------|-----|----------------|
| busType       | [BusType](js-apis-driver-deviceManager.md#bustype) | Yes  | Bus type.         |
| driverUid     | string                                             | Yes  | Driver UID.        |
| driverName    | string                                             | Yes  | Driver name.         |
| driverVersion | string                                             | Yes  | Driver version.         |
| driverSize    | string                                             | Yes  | Driver size, in bytes.|
| description   | string                                             | Yes  | Driver description.         |

## USBDriverInfo

Defines detailed information about the USB device driver. It is inherited from [DriverInfo](#driverinfo).

**System capability**: SystemCapability.Driver.ExternalDevice

| Name           | Type                 | Mandatory | Description                     |
|---------------|---------------------|-----|-------------------------|
| productIdList | Array&lt;number&gt; | Yes  | Product ID list of the USB devices supported by the driver.|
| vendorIdList  | Array&lt;number&gt; | Yes  | Vendor ID list of the USB devices supported by the driver. |
