# @ohos.driver.deviceManager (Peripheral Management)

The **deviceManager** module provides APIs for managing peripheral devices, including querying the peripheral device list and binding or unbinding a peripheral device.

>  **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
```

## deviceManager.queryDevices

queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;

Queries the list of peripheral devices. If the device has no peripheral device connected, an empty list is returned.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name | Type  | Mandatory| Description                                |
| ------- | ------ | ---- | ------------------------------------ |
| busType | number | No  | Bus type of the peripheral device to query. If this parameter is left blank, all types of peripheral devices are queried.|

**Return value**

| Type                                          | Description          |
| ---------------------------------------------- | -------------- |
| Array&lt;Readonly&lt;[Device](#device)&gt;&gt; | List of peripheral devices obtained.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.             |
| 22900001 | ExternalDeviceManager service exception or busType parameter error. |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';

try {
  let devices : Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);
  for (let item of devices) {
    let device : deviceManager.USBDevice = item as deviceManager.USBDevice;
    console.info(`Device id is ${device.deviceId}`)
  }
} catch (error) {
  console.error(`Failed to query device. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.bindDevice<sup>(deprecated)</sup>

bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;,
  callback: AsyncCallback&lt;{deviceId: number; remote: rpc.IRemoteObject;}&gt;): void

Binds a peripheral device based on the device information returned by **queryDevices()**. This API uses an asynchronous callback to return the result.

You can use [deviceManager.queryDevices](#devicemanagerquerydevices) to obtain the peripheral device information first.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 18. You are advised to use [deviceManager.bindDriverWithDeviceId](#devicemanagerbinddriverwithdeviceid18) instead.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name      | Type                                                                                                | Mandatory| Description                                  |
| ------------ | ---------------------------------------------------------------------------------------------------- | ---- | -------------------------------------- |
| deviceId     | number                                                                                               | Yes  | ID of the device to unbind. It can be obtained by **queryDevices()**.          |
| onDisconnect | AsyncCallback&lt;number&gt;                                                                          | Yes  | Callback to be invoked when the bound peripheral device is disconnected.                    |
| callback     | AsyncCallback&lt;{deviceId: number; remote: [rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject);}&gt; | Yes  | Callback invoked to return the communication object of the peripheral device bound.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.              |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 22900001 | ExternalDeviceManager service exception. |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';

interface DataType {
  deviceId : number;
  remote : rpc.IRemoteObject;
}

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  deviceManager.bindDevice(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }, (error : BusinessError, data : DataType) => {
    if (error) {
      console.error(`bindDevice async fail. Code is ${error.code}, message is ${error.message}`);
      return;
    }
    console.info(`bindDevice success`);
  });
} catch (error) {
  console.error(`bindDevice fail. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.bindDeviceDriver<sup>(deprecated)</sup>
bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;,
  callback: AsyncCallback&lt;RemoteDeviceDriver&gt;): void

Binds a peripheral device based on the device information returned by **queryDevices()**. This API uses an asynchronous callback to return the result.

You can use [deviceManager.queryDevices](#devicemanagerquerydevices) to obtain the peripheral device information first.

> **Description**
> This API is supported since API version 11 and deprecated since API version 18. You are advised to use [deviceManager.bindDriverWithDeviceId](#devicemanagerbinddriverwithdeviceid18) instead.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name      | Type                       | Mandatory| Description                        |
| ------------ | --------------------------- | ---- | ---------------------------- |
| deviceId     | number                      | Yes  | ID of the device to unbind. It can be obtained by **queryDevices()**.|
| onDisconnect | AsyncCallback&lt;number&gt; | Yes  | Callback to be invoked when the bound peripheral device is disconnected.          |
| callback     | AsyncCallback&lt;RemoteDeviceDriver&gt;| Yes| Binding result, including the device ID and remote object.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 22900001 | ExternalDeviceManager service exception. |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  deviceManager.bindDeviceDriver(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }, (error : BusinessError, data : deviceManager.RemoteDeviceDriver) => {
    if (error) {
      console.error(`bindDeviceDriver async fail. Code is ${error.code}, message is ${error.message}`);
      return;
    }
    console.info(`bindDeviceDriver success`);
  });
} catch (error) {
  console.error(`bindDeviceDriver fail. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.bindDevice<sup>(deprecated)</sup>

bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number;
  remote: rpc.IRemoteObject;}&gt;;

Binds a peripheral device based on the device information returned by **queryDevices()**. This API uses an asynchronous callback to return the result.

You need to use [deviceManager.queryDevices](#devicemanagerquerydevices) to obtain the peripheral device information first.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 18. You are advised to use [deviceManager.bindDriverWithDeviceId](#devicemanagerbinddriverwithdeviceid18) instead.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name      | Type                       | Mandatory| Description                        |
| ------------ | --------------------------- | ---- | ---------------------------- |
| deviceId     | number                      | Yes  | ID of the device to unbind. It can be obtained by **queryDevices()**.|
| onDisconnect | AsyncCallback&lt;number&gt; | Yes  | Callback to be invoked when the bound peripheral device is disconnected.          |

**Return value**

| Type                                                                                          | Description                                        |
| ---------------------------------------------------------------------------------------------- | -------------------------------------------- |
| Promise&lt;{deviceId: number; remote: [rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject);}&gt; | Promise used to return the device ID and **IRemoteObject** object.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 22900001 | ExternalDeviceManager service exception. |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  deviceManager.bindDevice(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }).then(data => {
    console.info(`bindDevice success, Device_Id is ${data.deviceId}.
    remote is ${data.remote != null ? data.remote.getDescriptor() : "null"}`);
  }, (error: BusinessError) => {
    console.error(`bindDevice async fail. Code is ${error.code}, message is ${error.message}`);
  });
} catch (error) {
  console.error(`bindDevice fail. Code is ${error.code}, message is ${error.message}`);
}
```
## deviceManager.bindDeviceDriver<sup>(deprecated)</sup>

bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;RemoteDeviceDriver&gt;;

Binds a peripheral device based on the device information returned by **queryDevices()**. This API uses a promise to return the result.

You need to use [deviceManager.queryDevices](#devicemanagerquerydevices) to obtain the peripheral device information first.

> **NOTE**
> This API is supported since API version 11 and deprecated since API version 18. You are advised to use [deviceManager.bindDriverWithDeviceId](#devicemanagerbinddriverwithdeviceid18) instead.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name      | Type                       | Mandatory| Description                        |
| ------------ | --------------------------- | ---- | ---------------------------- |
| deviceId     | number                      | Yes  | ID of the device to unbind. It can be obtained by **queryDevices()**.|
| onDisconnect | AsyncCallback&lt;number&gt; | Yes  | Callback to be invoked when the bound peripheral device is disconnected.          |

**Return value**

| Type                             | Description                                     |
| --------------------------------- | -----------------------------------------|
| Promise&lt;RemoteDeviceDriver&gt; | Promise used to return a **RemoteDeviceDriver** object.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 22900001 | ExternalDeviceManager service exception. |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  deviceManager.bindDeviceDriver(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }).then((data: deviceManager.RemoteDeviceDriver) => {
    console.info(`bindDeviceDriver success, Device_Id is ${data.deviceId}.
    remote is ${data.remote != null ? data.remote.getDescriptor() : "null"}`);
  }, (error: BusinessError) => {
    console.error(`bindDeviceDriver async fail. Code is ${error.code}, message is ${error.message}`);
  });
} catch (error) {
  console.error(`bindDeviceDriver fail. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.unbindDevice<sup>(deprecated)</sup>

unbindDevice(deviceId: number, callback: AsyncCallback&lt;number&gt;): void

Unbinds a peripheral device. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 18. You are advised to use [deviceManager.unbindDriverWithDeviceId](#devicemanagerunbinddriverwithdeviceid18) instead.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name  | Type                       | Mandatory| Description                          |
| -------- | --------------------------- | ---- | ------------------------------ |
| deviceId | number                      | Yes  | ID of the device to unbind. It can be obtained by **queryDevices()**.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result.              |

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 22900001 | ExternalDeviceManager service exception. |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  deviceManager.unbindDevice(12345678, (error : BusinessError, data : number) => {
    if (error) {
      console.error(`unbindDevice async fail. Code is ${error.code}, message is ${error.message}`);
      return;
    }
    console.info(`unbindDevice success`);
  });
} catch (error) {
  console.error(`unbindDevice fail. Code is ${error.code}, message is ${error.message}`);
}
```
## deviceManager.unbindDevice<sup>(deprecated)</sup>

unbindDevice(deviceId: number): Promise&lt;number&gt;

Unbinds a peripheral device. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 18. You are advised to use [deviceManager.unbindDriverWithDeviceId](#devicemanagerunbinddriverwithdeviceid18) instead.

**Required permissions**: ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name  | Type  | Mandatory| Description                          |
| -------- | ------ | ---- | ------------------------------ |
| deviceId | number | Yes  | ID of the device to unbind. It can be obtained by **queryDevices()**.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 22900001 | ExternalDeviceManager service exception. |

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the device ID.|

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  deviceManager.unbindDevice(12345678).then((data : number) => {
    console.info(`unbindDevice success, Device_Id is ${data}.`);
  }, (error : BusinessError) => {
    console.error(`unbindDevice async fail. Code is ${error.code}, message is ${error.message}`);
  });
} catch (error) {
  console.error(`unbindDevice fail. Code is ${error.code}, message is ${error.message}`);
}
```
## deviceManager.bindDriverWithDeviceId<sup>18+</sup>

bindDriverWithDeviceId(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;RemoteDeviceDriver&gt;;

Binds a peripheral device based on the device information returned by **queryDevices()**. This API uses an asynchronous callback to return the result.

You need to call [deviceManager.queryDevices](#devicemanagerquerydevices) to obtain the device list.

**Required permissions**: ohos.permission.ACCESS_DDK_DRIVERS

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name      | Type                       | Mandatory| Description                        |
| ------------ | --------------------------- | ---- | ---------------------------- |
| deviceId     | number                      | Yes  | ID of the device to unbind. It can be obtained by **queryDevices()**.|
| onDisconnect | AsyncCallback&lt;number&gt; | Yes  | Callback to be invoked when the bound peripheral device is disconnected.          |

**Return value**

| Type                             | Description                                     |
| --------------------------------- | -----------------------------------------|
| Promise&lt;RemoteDeviceDriver&gt; | Promise used to return the [RemoteDeviceDriver](#remotedevicedriver11) object.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 26300001  | ExternalDeviceManager service exception. |
| 26300002  | Service not allowed. |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  deviceManager.bindDriverWithDeviceId(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }).then((data: deviceManager.RemoteDeviceDriver) => {
    console.info(`bindDriverWithDeviceId success, Device_Id is ${data.deviceId}.
    remote is ${data.remote != null ? data.remote.getDescriptor() : "null"}`);
  }, (error: BusinessError) => {
    console.error(`bindDriverWithDeviceId async fail. Code is ${error.code}, message is ${error.message}`);
  });
} catch (error) {
  console.error(`bindDriverWithDeviceId fail. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.unbindDriverWithDeviceId<sup>18+</sup>

unbindDriverWithDeviceId(deviceId: number): Promise&lt;number&gt;

Unbinds a peripheral device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_DDK_DRIVERS

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name  | Type  | Mandatory| Description                          |
| -------- | ------ | ---- | ------------------------------ |
| deviceId | number | Yes  | ID of the device to unbind. It can be obtained by **queryDevices()**.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the device ID.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | The permission check failed.             |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 26300001 | ExternalDeviceManager service exception. |
| 26300003 | There is no binding relationship. |

**Example**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
  deviceManager.unbindDriverWithDeviceId(12345678).then((data : number) => {
    console.info(`unbindDriverWithDeviceId success, Device_Id is ${data}.`);
  }, (error : BusinessError) => {
    console.error(`unbindDriverWithDeviceId async fail. Code is ${error.code}, message is ${error.message}`);
  });
} catch (error) {
  console.error(`unbindDriverWithDeviceId fail. Code is ${error.code}, message is ${error.message}`);
}
```

## Device

Represents the peripheral device information.

**System capability**: SystemCapability.Driver.ExternalDevice

| Name       | Type               | Mandatory| Description      |
| ----------- | ------------------- | ---- | ---------- |
| busType     | [BusType](#bustype) | Yes  | Bus type.|
| deviceId    | number              | Yes  | ID of the peripheral device.  |
| description | string              | Yes  | Description of the peripheral device.|

## USBDevice

USB device information, which is inherited from [Device](#device).

**System capability**: SystemCapability.Driver.ExternalDevice

| Name     | Type  | Mandatory| Description               |
| --------- | ------ | ---- | ------------------- |
| vendorId  | number | Yes  | Vendor ID of the USB device. |
| productId | number | Yes  | Product ID of the USB device.|

## BusType

Enumerates the device bus types.

**System capability**: SystemCapability.Driver.ExternalDevice

| Name| Value | Description         |
| ---- | --- | ------------- |
| USB  | 1   | USB bus.|

## RemoteDeviceDriver<sup>11+</sup>

Represents information about a remote device driver.

**System capability**: SystemCapability.Driver.ExternalDevice

| Name     | Type  | Mandatory| Description               |
| --------- | ------ | ---- | ------------------- |
| deviceId<sup>11+</sup>  | number | Yes  | ID of the peripheral device. |
| remote<sup>11+</sup> | [rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject) | Yes  | Remote driver object.|
