# @ohos.distributedDeviceManager (Device Management)

The **distributedDeviceManager** module provides APIs for distributed device management.

Applications can call the APIs to:

- Subscribe to or unsubscribe from device state changes.
- Discover devices nearby.
- Authenticate or deauthenticate a device.
- Query the trusted device list.
- Query local device information, including the device name, type, and ID.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
```

## distributedDeviceManager.createDeviceManager

createDeviceManager(bundleName: string): DeviceManager

Creates a **DeviceManager** instance. The **DeviceManager** instance is the entry for invoking the APIs for distributed device management. It can be used to obtain information about trusted devices and local devices.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name    | Type                                                | Mandatory| Description                                                       |
| ---------- | ---------------------------------------------------- | ---- | ----------------------------------------------------------- |
| bundleName | string                                               | Yes  | Bundle name of the application. The value is a string of 1 to 255 characters. |

**Return value**

  | Type                                       | Description       |
  | ------------------------------------------- | --------- |
  | [DeviceManager](#devicemanager) | **DeviceManager** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
  } catch(err) {
    let e: BusinessError = err as BusinessError;
    console.error('createDeviceManager errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

## distributedDeviceManager.releaseDeviceManager

releaseDeviceManager(deviceManager: DeviceManager): void

Releases a **DeviceManager** instance that is no longer used.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name    | Type                                                | Mandatory| Description                               |
| ---------- | ---------------------------------------------------- | ---- | --------------------------------- |
| deviceManager | [DeviceManager](#devicemanager)    | Yes  | **DeviceManager** instance to release.                                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    distributedDeviceManager.releaseDeviceManager(dmInstance);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('release device manager errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

## DeviceBasicInfo

Represents the basic information about a distributed device.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                    | Type                       | Mandatory  | Description      |
| ---------------------- | ------------------------- | ---- | -------- |
| deviceId               | string                    | Yes   | Device ID. The value is the result of obfuscating the udid-hash (hash value of the UDID), **appid**, and salt using the SHA-256 algorithm.|
| deviceName             | string                    | Yes   | Device name.   |
| deviceType             | string                    | Yes   | [Device type](#getdevicetype).   |
| networkId              | string                    | No   | Network ID of the device. |

## DeviceStateChange

Enumerates the device states.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| UNKNOWN     | 0    | The device state is unknown after the device goes online. Before the device state changes to available, distributed services cannot be used.          |
| AVAILABLE   | 1    | The information between devices has been synchronized in the Distributed Data Service (DDS) module, and the device is ready for running distributed services.|
| UNAVAILABLE | 2    | The device goes offline, and the device state is unknown.          |

## DeviceManager

Provides APIs to obtain information about trusted devices and local devices. Before calling any API in **DeviceManager**, you must use **createDeviceManager** to create a **DeviceManager** instance, for example, **dmInstance**.

### getAvailableDeviceListSync

getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;

Obtains all trusted devices synchronously.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                                       | Description       |
  | ------------------------------------------- | --------- |
  | Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt; | List of trusted devices obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getAvailableDeviceListSync errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getAvailableDeviceList

getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void

Obtains all trusted devices. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                   |
  | -------- | ---------------------------------------- | ---- | --------------------- |
  | callback | AsyncCallback&lt;Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt;&gt; | Yes   | Callback used to return the list of trusted devices.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.getAvailableDeviceList((err: BusinessError, data: Array<distributedDeviceManager.DeviceBasicInfo>) => {
      if (err) {
        console.error('getAvailableDeviceList errCode:' + err.code + ',errMessage:' + err.message);
        return;
      }
      console.log('get available device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getAvailableDeviceList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getAvailableDeviceList

getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;

Obtains all trusted devices. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                                                      | Description                              |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Promise&lt;Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
  dmInstance.getAvailableDeviceList().then((data: Array<distributedDeviceManager.DeviceBasicInfo>) => {
    console.log('get available device info: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error('getAvailableDeviceList errCode:' + err.code + ',errMessage:' + err.message);
  });
  ```

### getLocalDeviceNetworkId

getLocalDeviceNetworkId(): string

Obtains the network ID of the local device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                     | Description             |
  | ------------------------- | ---------------- |
  | string | Network ID of the local device obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceNetworkId: string = dmInstance.getLocalDeviceNetworkId();
    console.log('local device networkId: ' + JSON.stringify(deviceNetworkId));
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getLocalDeviceNetworkId errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getLocalDeviceName

getLocalDeviceName(): string

Obtains the local device name.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                     | Description             |
  | ------------------------- | ---------------- |
  | string                    | Name of the local device obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceName: string = dmInstance.getLocalDeviceName();
    console.log('local device name: ' + JSON.stringify(deviceName));
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getLocalDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getLocalDeviceType

getLocalDeviceType(): number

Obtains the local device type.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                     | Description             |
  | ------------------------- | ---------------- |
  | number                    | <!--RP1-->Local device type obtained.<!--RP1End--> |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceType: number = dmInstance.getLocalDeviceType();
    console.log('local device type: ' + JSON.stringify(deviceType));
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getLocalDeviceType errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getLocalDeviceId

getLocalDeviceId(): string

Obtains the local device ID. The value is the result of obfuscating the udid-hash (hash value of the UDID), **appid**, and salt using the SHA-256 algorithm.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                     | Description             |
  | ------------------------- | ---------------- |
  | string                    | Local device ID obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceId: string = dmInstance.getLocalDeviceId();
    console.log('local device id: ' + JSON.stringify(deviceId));
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getLocalDeviceId errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceName

getDeviceName(networkId: string): string

Obtains the device name based on the network ID of the specified device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description       |
  | -------- | ---------------------------------------- | ---- | --------- |
  | networkId| string                                   | Yes  | Network ID of the device. The value is a string of 1 to 255 characters.|

**Return value**

  | Type                     | Description             |
  | ------------------------- | ---------------- |
  | string                    | Device name obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified networkId is greater than 255. |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Network ID of the device, which can be obtained from the trusted device list.
    let networkId = 'xxxxxxx';
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceName: string = dmInstance.getDeviceName(networkId);
    console.log('device name: ' + JSON.stringify(deviceName)); 
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceType

getDeviceType(networkId: string): number

Obtains the device type based on the network ID of the specified device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description       |
  | -------- | ---------------------------------------- | ---- | --------- |
  | networkId| string                                   | Yes  | Network ID of the device. The value is a string of 1 to 255 characters.|

**Return value**

  | Type                     | Description             |
  | ------------------------- | ---------------- |
  | number                    | <!--RP2-->Device type obtained.<!--RP2End--> |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified networkId is greater than 255. |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // Network ID of the device, which can be obtained from the trusted device list.
    let networkId = 'xxxxxxx';
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceType: number = dmInstance.getDeviceType(networkId);
    console.log('device type: ' + JSON.stringify(deviceType)); 
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceType errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### startDiscovering

startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object;} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object;} ): void

Starts to discover devices nearby. The discovery process takes 2 minutes. A maximum of 99 devices can be discovered. In Wi-Fi scenarios, only the devices in the same LAN can be discovered.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name           | Type                       | Mandatory  | Description   |
  | ------------- | ------------------------------- | ---- | -----  |
  | discoverParam  | {[key:&nbsp;string]:&nbsp;Object;}      | Yes  | Identifier of the device to discover. It specifies the type of the target to discover.<br>**discoverTargetType**: The default discovery target is device. The value is **1**.|
  | filterOptions | {[key:&nbsp;string]:&nbsp;Object;}          | No  | Options for filtering the devices to discover. The default value is **undefined**, which means to discover offline devices. The options include the following:<br>- **availableStatus(0-1)**: status of the device to discover. The value **0** means the device is untrusted.<br>- **0**: The device is offline. The client needs to call **bindTarget** to bind the device.<br>- **1**: The device is online and can be connected.<br>**discoverDistance(0-100)**: distance of the device to discover, in cm. This parameter is not used in Wi-Fi scenarios.<br>**authenticationStatus(0-1)**: authentication status of the device to discover.<br>- **0**: The device is not authenticated.<br>The value **1** means the device has been authenticated.<br>- **authorizationType(0-2)**: authorization type of the device to discover.<br>- **0**: The device is authenticated by a temporarily agreed session key.<br>- **1**: The device is authenticated by a key of the same account.<br>- **2**: The device is authenticated by a credential key of different accounts.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery unavailable.                                          |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  interface DiscoverParam {
    discoverTargetType: number;
  }

  interface FilterOptions {
    availableStatus: number;
    discoverDistance: number;
    authenticationStatus: number;
    authorizationType: number;
  }

  let discoverParam: Record<string, number> = {
    'discoverTargetType': 1
  };
  let filterOptions: Record<string, number> = {
    'availableStatus': 0
  };

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.startDiscovering(discoverParam, filterOptions); // When devices are discovered, discoverSuccess is called to notify the application.
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('startDiscovering errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### stopDiscovering

stopDiscovering(): void

Stops device discovery.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.stopDiscovering();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('stopDiscovering errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### bindTarget

bindTarget(deviceId: string, bindParam: {[key:&nbsp;string]:&nbsp;Object;} , callback: AsyncCallback&lt;{deviceId: string;}>): void

Binds a device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                               | Mandatory | Description        |
  | ---------- | --------------------------------------------------- | ----- | ------------ |
  | deviceId   | string                                              | Yes   | Device ID. The value is a string of 1 to 255 characters.  |
  | bindParam  | {[key:&nbsp;string]:&nbsp;Object;}                             | Yes   | Authentication parameters. You can determine the key-value pair to be passed in. By default, the following keys are carried:<br>**bindType**: binding type, which is mandatory.<br>The value **1** means PIN authentication.<br>**targetPkgName**: bundle name of the target to bind.<br>**appName**: application that attempts to bind the target.<br>**appOperation**: reason for the application to bind the target.<br>**customDescription**: detailed description of the operation.  |
  | callback   | AsyncCallback&lt;{deviceId:&nbsp;string;&nbsp;}&gt; | Yes   | Callback used to return the authentication result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified deviceId is greater than 255.  |
| 11600101 | Failed to execute the function.                                 |
| 11600103 | Authentication unavailable.                                     |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    deviceId: string = '';
  }

  // Information about the device to authenticate. The information can be obtained from the device discovery result.
  let deviceId = 'XXXXXXXX';
  let bindParam: Record<string, string | number> = {
    'bindType': 1, // Authentication type. The value 1 means PIN authentication.
    'targetPkgName': 'xxxx',
    'appName': 'xxxx',
    'appOperation': 'xxxx',
    'customDescription': 'xxxx'
  };

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.bindTarget(deviceId, bindParam, (err: BusinessError, data: Data) => {
      if (err) {
        console.error('bindTarget errCode:' + err.code + ',errMessage:' + err.message);
        return;
      }
      console.info('bindTarget result:' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('bindTarget errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### unbindTarget

unbindTarget(deviceId: string): void

Unbinds a device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name  | Type                     | Mandatory| Description      |
  | -------- | ------------------------- | ---- | ---------- |
  | deviceId | string                    | Yes  | Device ID. The value is a string of 1 to 255 characters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified deviceId is greater than 255.  |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let deviceId = 'XXXXXXXX';
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.unbindTarget(deviceId);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('unbindTarget errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('deviceStateChange')

on(type: 'deviceStateChange', callback: Callback&lt;{ action: DeviceStateChange; device: DeviceBasicInfo; }&gt;): void

Subscribes to the device state changes. The application (identified by the bundle name) will be notified when the device state changes.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type. The value **'deviceStateChange'** indicates device state changes.|
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChange](#devicestatechange);&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo);&nbsp;}&gt; | Yes   | Callback used to return the device information and state.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    action: distributedDeviceManager.DeviceStateChange = 0;
    device: distributedDeviceManager.DeviceBasicInfo = {
      deviceId: '',
      deviceName: '',
      deviceType: '',
      networkId: ''
    };
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.on('deviceStateChange', (data: Data) => {
      console.info('deviceStateChange on:' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('deviceStateChange errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('deviceStateChange')

off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChange; device: DeviceBasicInfo; }&gt;): void

Unsubscribes from the device state changes.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes   | Event type. The value **'deviceStateChange'** indicates device state changes.       |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChange](#devicestatechange);&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo);&nbsp;}&gt; | No   | Callback to unregister.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    action: distributedDeviceManager.DeviceStateChange = 0;
    device: distributedDeviceManager.DeviceBasicInfo = {
      deviceId: '',
      deviceName: '',
      deviceType: '',
      networkId: ''
    };
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.off('deviceStateChange', (data: Data) => {
      console.info('deviceStateChange' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('deviceStateChange errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('discoverSuccess')

on(type: 'discoverSuccess', callback: Callback&lt;{ device: DeviceBasicInfo; }&gt;): void

Subscribes to the **'discoverSuccess'** event. The application will be notified when a device is successfully discovered.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                        |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **'discoverSuccess'**.|
  | callback | Callback&lt;{&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo);&nbsp;}&gt; | Yes   | Callback invoked when a device is successfully discovered.              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    device: distributedDeviceManager.DeviceBasicInfo = {
      deviceId: '',
      deviceName: '',
      deviceType: '',
      networkId: ''
    };
  }
  
  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.on('discoverSuccess', (data: Data) => {
      console.info('discoverSuccess:' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('discoverSuccess errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('discoverSuccess')

off(type: 'discoverSuccess', callback?: Callback&lt;{ device: DeviceBasicInfo; }&gt;): void

Unsubscribes from the **'discoverSuccess'** event.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **'discoverSuccess'**.                |
  | callback | Callback&lt;{&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo);&nbsp;}&gt; | No   | Callback to unregister.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    device: distributedDeviceManager.DeviceBasicInfo = {
      deviceId: '',
      deviceName: '',
      deviceType: '',
      networkId: ''
    };
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.off('discoverSuccess', (data: Data) => {
      console.info('discoverSuccess' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('discoverSuccess errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('deviceNameChange')

on(type: 'deviceNameChange', callback: Callback&lt;{ deviceName: string; }&gt;): void

Subscribes to device name changes. The application will be notified when the name of a device is changed.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **deviceNameChange**.|
  | callback | Callback&lt;{&nbsp;deviceName:&nbsp;string;}&gt; | Yes   | Callback used to return the device name change.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    deviceName: string = '';
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.on('deviceNameChange', (data: Data) => {
      console.info('deviceNameChange on:' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('deviceNameChange errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('deviceNameChange')

off(type: 'deviceNameChange', callback?: Callback&lt;{ deviceName: string; }&gt;): void

Unsubscribes from the device name changes.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **deviceNameChange**.|
  | callback | Callback&lt;{&nbsp;deviceName:&nbsp;string;}&gt; | No   | Callback to unregister.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    deviceName: string = '';
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.off('deviceNameChange', (data: Data) => {
      console.info('deviceNameChange' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('deviceNameChange errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('discoverFailure')

on(type: 'discoverFailure', callback: Callback&lt;{ reason: number; }&gt;): void

Subscribes to the **'discoverFailure'** event. The application will be notified when a device fails to be discovered. 

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **'discoverFailure'**.|
  | callback | Callback&lt;{&nbsp;reason:&nbsp;number;&nbsp;}&gt; | Yes   | Callback invoked when a device fails to be discovered.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    reason: number = 0;
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.on('discoverFailure', (data: Data) => {
      console.info('discoverFailure on:' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('discoverFailure errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('discoverFailure')

off(type: 'discoverFailure', callback?: Callback&lt;{ reason: number; }&gt;): void

Unsubscribes from the **'discoverFailure'** event.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description               |
  | -------- | ---------------------------------------- | ---- | ----------------- |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **'discoverFailure'**.    |
  | callback | Callback&lt;{&nbsp;reason:&nbsp;number;&nbsp;}&gt; | No   | Callback to unregister.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    reason: number = 0;
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.off('discoverFailure', (data: Data) => {
      console.info('discoverFailure' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('discoverFailure errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('serviceDie')

on(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void

Subscribes to the dead events of the **DeviceManager** service. The application will be notified when the **DeviceManager** service is terminated unexpectedly. 

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                   | Mandatory  | Description                                      |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | Yes   | Event type, which has a fixed value of **'serviceDie'**.|
  | callback | Callback&lt;{}&gt; | No   | Callback invoked when the **DeviceManager** service is terminated unexpectedly.                       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.on('serviceDie', () => {
      console.info('serviceDie on');
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('serviceDie errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('serviceDie')

off(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void

Unsubscribes from the dead events of the **DeviceManager** service.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                   | Mandatory  | Description                                      |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | Yes   | Event type, which has a fixed value of **'serviceDie'**.|
  | callback | Callback&lt;{}&gt; | No   | Callback to unregister.                    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.off('serviceDie', () => {
      console.info('serviceDie off');
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('serviceDie errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```
