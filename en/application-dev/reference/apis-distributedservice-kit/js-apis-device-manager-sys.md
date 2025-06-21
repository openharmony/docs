# @ohos.distributedHardware.deviceManager (Device Management) (System API)

The APIs of this module are deprecated. You are advised to use [@ohos.distributedDeviceManager](js-apis-distributedDeviceManager.md).

The **deviceManager** module provides APIs for distributed device management.

System applications can call the APIs to do the following:

- Subscribe to or unsubscribe from device state changes.
- Discover devices nearby.
- Authenticate or deauthenticate a device.
- Query the trusted device list.
- Query local device information, including the device name, type, and ID.
- Publishes device information for discovery purposes.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import

```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';
```


## deviceManager.createDeviceManager

createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void

Creates a **DeviceManager** instance.

> **NOTE**<br>This API is deprecated since API version 11. Use [deviceManager.createDeviceManager](js-apis-distributedDeviceManager.md#devicemanagercreatedevicemanager) instead.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Parameters**

| Name    | Type                                                | Mandatory| Description                                                       |
| ---------- | ---------------------------------------------------- | ---- | ----------------------------------------------------------- |
| bundleName | string                                               | Yes  | Bundle name of the application. The value is a string of 1 to 255 characters.                                 |
| callback   | AsyncCallback&lt;[DeviceManager](#devicemanager)&gt; | Yes  | Callback used to return the **DeviceManager** instance created.|

**Example**

  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  let dmInstance: deviceManager.DeviceManager | null = null;
  try {
    deviceManager.createDeviceManager("ohos.samples.jshelloworld", (err: BusinessError, data: deviceManager.DeviceManager) => {
      if (err) { 
        console.error("createDeviceManager errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.info("createDeviceManager success");
      dmInstance = data;
    });
  } catch(err) {
    let e: BusinessError = err as BusinessError;
    console.error("createDeviceManager errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

## DeviceInfo

Defines device information.

> **NOTE**<br>This API is deprecated since API version 11. Use [DeviceBasicInfo](js-apis-distributedDeviceManager.md#devicebasicinfo) instead.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                    | Type                       | Mandatory  | Description      |
| ---------------------- | ------------------------- | ---- | -------- |
| deviceId               | string                    | Yes   | Unique identifier of the device.|
| deviceName             | string                    | Yes   | Device name.   |
| deviceType             | [DeviceType](#devicetype) | Yes   | Device type.   |
| networkId<sup>8+</sup> | string                    | Yes   | Network ID of the device. |
| range<sup>9+</sup>     | number                    | Yes   | Distance between the discovered device and the device that initiates device discovery. |
| authForm<sup>10+</sup> | [AuthForm](#authform10)     | Yes   | Authentication type of the device. |

## DeviceType

Enumerates the device types.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name          | Value | Description  |
| ------------ | ---- | ---- |
| SPEAKER      | 0x0A | Smart speaker.|
| PHONE        | 0x0E | Phone.  |
| TABLET       | 0x11 | Tablet  |
| WEARABLE     | 0x6D | Wearable|
| TV           | 0x9C | Smart TV |
| CAR          | 0x83 | Car.   |
| UNKNOWN_TYPE | 0    | Unknown device type.|

## AuthForm<sup>10+</sup>

Enumerates the device authentication types.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                | Value | Description            |
| ------------------- | ---- | --------------- |
| INVALID_TYPE        | -1   | No authentication.|
| PEER_TO_PEER        | 0    | Point-to-point authentication for devices without accounts.  |
| IDENTICAL_ACCOUNT   | 1    | Authentication for devices using the same account.  |
| ACROSS_ACCOUNT      | 2    | Authentication for devices using different accounts.|

## DeviceStateChangeAction

Enumerates the device states.

> **NOTE**<br>This API is deprecated since API version 11. Use [DeviceStateChange](js-apis-distributedDeviceManager.md#devicestatechange) instead.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name     | Value | Description             |
| ------- | ---- | --------------- |
| ONLINE  | 0    | The device is physically online.          |
| READY   | 1    | The information between devices has been synchronized in the Distributed Data Service (DDS) module, and the device is ready for running distributed services.|
| OFFLINE | 2    | The device is physically offline.          |
| CHANGE  | 3    | The device information is changed.        |

## SubscribeInfo

Defines subscription information.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name           | Type                               | Mandatory  | Description               |
| ------------- | --------------------------------- | ---- | ----------------- |
| subscribeId   | number                            | Yes   | Subscription ID, used to identify a device discovery period. The value ranges from 1 to 65535.|
| mode          | [DiscoverMode ](#discovermode)    | Yes   | Device discovery mode.            |
| medium        | [ExchangeMedium](#exchangemedium) | Yes   | Medium used for device discovery.            |
| freq          | [ExchangeFreq](#exchangefreq)     | Yes   | Frequency of device discovery.            |
| isSameAccount | boolean                           | No   | Whether the account is the same as the current account. The value **true** indicates the same account and the value **false** indicates a different account.           |
| isWakeRemote  | boolean                           | No   | Whether to wake up the device. The value **true** means to wake up the device and the value **false** means the opposite.          |
| capability    | [SubscribeCap](#subscribecap)     | Yes   | Discovery capability.            |

## DiscoverMode

Enumerates the device discovery modes.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                   | Value | Description   |
| --------------------- | ---- | ----- |
| DISCOVER_MODE_PASSIVE | 0x55 | Passive discovery.|
| DISCOVER_MODE_ACTIVE  | 0xAA | Active discovery.|


## ExchangeMedium 

Enumerates the media used for device discovery.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name  | Value | Description       |
| ---- | ---- | --------- |
| AUTO | 0    | Automatic.  |
| BLE  | 1    | Bluetooth.  |
| COAP | 2    | Wi-Fi.|
| USB  | 3    | USB. |

## ExchangeFreq 

Enumerates the device discovery frequencies.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name        | Value | Description   |
| ---------- | ---- | ----- |
| LOW        | 0    | Low frequency. |
| MID        | 1    | Medium frequency. |
| HIGH       | 2    | High frequency. |
| SUPER_HIGH | 3    | Ultra-high frequency.|


## SubscribeCap 

Enumerates the discovery capabilities.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                       | Value | Description            |
| ------------------------- | ---- | -------------- |
| SUBSCRIBE_CAPABILITY_DDMP | 0    | DDMP capability. This will be deprecated later.|
| SUBSCRIBE_CAPABILITY_OSD  | 1    | OSD capability.        |


## AuthParam

Defines the authentication parameters.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name       | Type                  | Mandatory  | Description        |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | Yes   | Authentication type.     |
| extraInfo | {[key:string]&nbsp;:&nbsp;any} | No   | Extended field. Optional. The default value is **undefined**.|

## AuthInfo

Defines authentication information.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name       | Type                  | Mandatory  | Description        |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | Yes   | Authentication type.     |
| token     | number               | Yes   | Authentication token.  |
| extraInfo | {[key:string]&nbsp;:&nbsp;any} | No   | Extended field. Optional. The default value is **undefined**.|

## PublishInfo<sup>9+</sup>

Defines published device information.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name         | Type                             | Mandatory  | Description               |
| ------------- | --------------------------------- | ---- | ----------------- |
| publishId     | number                            | Yes   | ID used to identify a publication period.|
| mode          | [DiscoverMode ](#discovermode)    | Yes   | Device discovery mode.            |
| freq          | [ExchangeFreq](#exchangefreq)     | Yes   | Frequency of device discovery.            |
| ranging       | boolean                           | Yes   | Whether the device supports ranging. The value **true** indicates that the device supports ranging and the value **false** indicates the opposite.            |

## DeviceManager

Provides APIs to obtain information about trusted devices and local devices. Before calling any API in **DeviceManager**, you must use **createDeviceManager** to create a **DeviceManager** instance, for example, **dmInstance**.

### release

release(): void

Releases this **DeviceManager** instance when it is no longer used.

> **NOTE**<br>This API is deprecated since API version 11. Use [deviceManager.releaseDeviceManager](js-apis-distributedDeviceManager.md#devicemanagerreleasedevicemanager) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600101 | Failed to execute the function.                                 |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.release();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("release errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getTrustedDeviceListSync

getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;

Obtains all trusted devices synchronously.

> **NOTE**<br>This API is deprecated since API version 11. Use [getAvailableDeviceListSync](js-apis-distributedDeviceManager.md#getavailabledevicelistsync) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Name                                    | Description       |
  | -------------------------------------- | --------- |
  | Array&lt;[DeviceInfo](#deviceinfo)&gt; | List of trusted devices obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600101 | Failed to execute the function.                                 |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    let deviceInfoList: Array<deviceManager.DeviceInfo> = dmInstance.getTrustedDeviceListSync();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getTrustedDeviceListSync errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getTrustedDeviceListSync<sup>10+</sup>

getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;

Enables the DSoftBus heartbeat mode to quickly bring offline trusted devices online and updates the list of online trusted devices.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name       | Type                              | Mandatory| Description                               |
| ------------- | --------------------------------- | ---- | ---------------------------------- |
|   isRefresh   | boolean                           | Yes  | Whether to enable the heartbeat mode and update the list of online trusted devices. The value **true** means to enable the heartbeat mode and update the list of online trusted devices and the value **false** means the opposite.     |

**Return value**

| Name                                    | Description           |
| -------------------------------------- | ---------------- |
| Array&lt;[DeviceInfo](#deviceinfo)&gt; | List of trusted devices obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    let deviceInfoList: Array<deviceManager.DeviceInfo> = dmInstance.getTrustedDeviceListSync(true);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getTrustedDeviceListSync errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void

Obtains all trusted devices. This API uses an asynchronous callback to return the result.

> **NOTE**<br>This API is deprecated since API version 11. Use [getAvailableDeviceList](js-apis-distributedDeviceManager.md#getavailabledevicelist) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                   |
  | -------- | ---------------------------------------- | ---- | --------------------- |
  | callback | AsyncCallback&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | Yes   | Callback used to return the list of trusted devices.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.getTrustedDeviceList((err: BusinessError, data: Array<deviceManager.DeviceInfo>) => {
      if (err) {
        console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get trusted device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getTrustedDeviceList errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;

Obtains all trusted devices. This API uses a promise to return the result.

> **NOTE**<br>This API is deprecated since API version 11. Use [getAvailableDeviceList](js-apis-distributedDeviceManager.md#getavailabledevicelist-1) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                                      | Description                   |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  dmInstance.getTrustedDeviceList().then((data: Array<deviceManager.DeviceInfo>) => {
    console.log('get trusted device info: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### getLocalDeviceInfoSync<sup>8+</sup>

getLocalDeviceInfoSync(): [DeviceInfo](#deviceinfo)

Obtains local device information synchronously.

> **NOTE**<br>This API is deprecated since API version 11. Use [getLocalDeviceNetworkId](js-apis-distributedDeviceManager.md#getlocaldevicenetworkid), [getLocalDeviceName](js-apis-distributedDeviceManager.md#getlocaldevicename), [getLocalDeviceType](js-apis-distributedDeviceManager.md#getlocaldevicetype), or [getLocalDeviceId](js-apis-distributedDeviceManager.md#getlocaldeviceid) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Name                     | Description             |
  | ------------------------- | ---------------- |
  | [DeviceInfo](#deviceinfo) | List of local devices obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600101 | Failed to execute the function.                                 |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    let deviceInfo: deviceManager.DeviceInfo = dmInstance.getLocalDeviceInfoSync();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getLocalDeviceInfoSync errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void

Obtains local device information. This API uses an asynchronous callback to return the result.

> **NOTE**<br>This API is deprecated since API version 11. Use [getLocalDeviceNetworkId](js-apis-distributedDeviceManager.md#getlocaldevicenetworkid), [getLocalDeviceName](js-apis-distributedDeviceManager.md#getlocaldevicename), [getLocalDeviceType](js-apis-distributedDeviceManager.md#getlocaldevicetype), or [getLocalDeviceId](js-apis-distributedDeviceManager.md#getlocaldeviceid) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description       |
  | -------- | ---------------------------------------- | ---- | --------- |
  | callback | AsyncCallback&lt;[DeviceInfo](#deviceinfo)&gt; | Yes   | Callback used to return the local device information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';


  try {
    dmInstance.getLocalDeviceInfo((err: BusinessError, data: deviceManager.DeviceInfo) => {
      if (err) {
        console.error("getLocalDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get local device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getLocalDeviceInfo errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;

Obtains local device information. This API uses a promise to return the result.

> **NOTE**<br>This API is deprecated since API version 11. Use [getLocalDeviceNetworkId](js-apis-distributedDeviceManager.md#getlocaldevicenetworkid), [getLocalDeviceName](js-apis-distributedDeviceManager.md#getlocaldevicename), [getLocalDeviceType](js-apis-distributedDeviceManager.md#getlocaldevicetype), or [getLocalDeviceId](js-apis-distributedDeviceManager.md#getlocaldeviceid) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                                      | Description                   |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;[DeviceInfo](#deviceinfo)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  dmInstance.getLocalDeviceInfo().then((data: deviceManager.DeviceInfo) => {
    console.log('get local device info: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error("getLocalDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### getDeviceInfo<sup>10+</sup>

getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void

Obtains the information about a specific device based on the network ID. This API uses an asynchronous callback to return the result.

> **NOTE**<br>This API is deprecated since API version 11. Use [getDeviceName](js-apis-distributedDeviceManager.md#getdevicename) and [getDeviceType](js-apis-distributedDeviceManager.md#getdevicetype) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description       |
  | -------- | ---------------------------------------- | ---- | --------- |
  | networkId| string                                   | Yes  | Network ID of the device. The value is a string of 1 to 255 characters.|
  | callback | AsyncCallback&lt;[DeviceInfo](#deviceinfo)&gt; | Yes   | Callback used to return the information about the specified device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    // Network ID of the device, which can be obtained from the trusted device list
    let networkId = "xxxxxxx";
    dmInstance.getDeviceInfo(networkId, (err: BusinessError, data: deviceManager.DeviceInfo) => {
      if (err) {
        console.error("getDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getDeviceInfo errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getDeviceInfo<sup>10+</sup>

getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt;

Obtains the information about a specific device based on the network ID. This API uses a promise to return the result.

> **NOTE**<br>This API is deprecated since API version 11. Use [getDeviceName](js-apis-distributedDeviceManager.md#getdevicename) and [getDeviceType](js-apis-distributedDeviceManager.md#getdevicetype) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name  | Type                                    | Mandatory| Description       |
  | -------- | ---------------------------------------- | ---- | --------- |
  | networkId| string                                   | Yes  | Network ID of the device. The value is a string of 1 to 255 characters.|
  
**Return value**

  | Type                                      | Description                   |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;[DeviceInfo](#deviceinfo)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  // Network ID of the device, which can be obtained from the trusted device list
  let networkId = "xxxxxxx";
  dmInstance.getDeviceInfo(networkId).then((data: deviceManager.DeviceInfo) => {
    console.log('get device info: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error("getDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### startDeviceDiscovery<sup>8+</sup>

startDeviceDiscovery(subscribeInfo: SubscribeInfo): void

Starts to discover peripheral devices. The discovery process lasts 2 minutes. A maximum of 99 devices can be discovered.

> **NOTE**<br>This API is deprecated since API version 11. Use [startDiscovering](js-apis-distributedDeviceManager.md#startdiscovering) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name           | Type                      | Mandatory| Description   |
  | ------------- | ------------------------------- | ---- | ----- |
  | subscribeInfo | [SubscribeInfo](#subscribeinfo) | Yes  | Subscription information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery unavailable.                                              |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  interface SubscribeInfo {
    subscribeId: number;
    mode: number, // Active discovery
    medium: number,  // Automatic. Multiple media can be used for device discovery.
    freq: number,    // High frequency
    isSameAccount: boolean;
    isWakeRemote: boolean;
    capability: number;
  }

  // Automatically generate a unique subscription ID.
  let subscribeId = Math.floor(Math.random() * 10000 + 1000);
  let subscribeInfo: SubscribeInfo = {
    subscribeId: subscribeId,
    mode: 0xAA, // Active discovery
    medium: 0,  // Automatic. Multiple media can be used for device discovery.
    freq: 2,    // High frequency
    isSameAccount: false,
    isWakeRemote: false,
    capability: 1
  };
  try {
    dmInstance.startDeviceDiscovery(subscribeInfo); // The deviceFound callback is called to notify the application when a device is discovered.
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("startDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### startDeviceDiscovery<sup>9+</sup>

startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void

Starts to discover peripheral devices. The discovery process lasts 2 minutes. A maximum of 99 devices can be discovered.

> **NOTE**<br>This API is deprecated since API version 11. Use [startDiscovering](js-apis-distributedDeviceManager.md#startdiscovering) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name           | Type                      | Mandatory  | Description   |
  | ------------- | ------------------------------- | ---- | -----  |
  | subscribeInfo | [SubscribeInfo](#subscribeinfo) | Yes  | Subscription information.|
  | filterOptions | string                          | No  | Options for filtering discovered devices. Optional. The default value is **undefined**, indicating that discovery of offline devices. The value is a string of 1 to 255 characters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery unavailable.                                              |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  interface Filters {
    type: string;
    value: number;
  }

  interface FilterOptions {
    filter_op: string, // Optional. The default value is OR.
    filters: Filters[];
  }

  interface SubscribeInfo {
    subscribeId: number;
    mode: number, // Active discovery
    medium: number,  // Automatic. Multiple media can be used for device discovery.
    freq: number,    // High frequency
    isSameAccount: boolean;
    isWakeRemote: boolean;
    capability: number;
  }

  // Automatically generate a unique subscription ID.
  let subscribeId = Math.floor(Math.random() * 10000 + 1000);
  let subscribeInfo: SubscribeInfo = {
    subscribeId: subscribeId,
    mode: 0xAA, // Active discovery
    medium: 0,  // Automatic. Multiple media can be used for device discovery.
    freq: 2,    // High frequency
    isSameAccount: false,
    isWakeRemote: false,
    capability: 1
  };

  let filters: Filters[] = [
    {
        type: "range",
        value: 50 // Filter discovered devices based on the distance (in cm).
    }
  ];

  let filterOptions: FilterOptions = {
    filter_op: "OR", // Optional. The default value is OR.
    filters: filters
  };
  try {
    dmInstance.startDeviceDiscovery(subscribeInfo, JSON.stringify(filterOptions)); // The deviceFound callback is invoked to notify the application when a device is discovered.
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("startDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### stopDeviceDiscovery

stopDeviceDiscovery(subscribeId: number): void

Stops device discovery.

> **NOTE**<br>This API is deprecated since API version 11. Use [stopDiscovering](js-apis-distributedDeviceManager.md#stopdiscovering) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name         | Type  | Mandatory  | Description   |
  | ----------- | ------ | ---- | ----- |
  | subscribeId | number | Yes   | Subscription ID. The value ranges from 1 to 65535.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |
| 11600101 | Failed to execute the function.                                 |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    // stopDeviceDiscovery and startDeviceDiscovery must be used in pairs, and the input parameter **subscribeId** passed in them must be the same.
    let subscribeId = 12345;
    dmInstance.stopDeviceDiscovery(subscribeId);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("stopDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### publishDeviceDiscovery<sup>9+</sup>

publishDeviceDiscovery(publishInfo: PublishInfo): void

Publishes device information for discovery purposes. The publish process lasts 2 minutes.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name         | Type                       | Mandatory| Description   |
  | ------------- | ------------------------------- | ---- | ----- |
  | publishInfo   | [PublishInfo](#publishinfo9)     | Yes  | Device information to publish.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |
| 11600105 | Publish unavailable.                                                |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  interface PublishInfo {
    publishId: number;
    mode: number, // Active discovery
    freq: number,    // High frequency
    ranging: boolean // Whether the device supports reporting the distance to the discovery initiator.
  };

  // Automatically generate a unique subscription ID.
  let publishId = Math.floor(Math.random() * 10000 + 1000);
  let publishInfo: PublishInfo = {
    publishId: publishId,
    mode: 0xAA, // Active discovery
    freq: 2,    // High frequency
    ranging: true  // The device supports reporting the distance to the discovery initiator.
  };

  try {
    dmInstance.publishDeviceDiscovery(publishInfo); // A callback is invoked to notify the application when the device information is published.
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### unPublishDeviceDiscovery<sup>9+</sup>

unPublishDeviceDiscovery(publishId: number): void

Stops publishing device information.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name       | Type| Mandatory| Description |
  | ----------- | -------- | ---- | ----- |
  | publishId   | number   | Yes  | Publish ID. The value ranges from 1 to 2147483647.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    // unPublishDeviceDiscovery and publishDeviceDiscovery must be used in pairs, and the input parameter **publishId** passed in them must be the same.
    let publishId = 12345;
    dmInstance.unPublishDeviceDiscovery(publishId);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("unPublishDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### authenticateDevice

authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void

Authenticates a device.

> **NOTE**<br>This API is deprecated since API version 11. Use [bindTarget](js-apis-distributedDeviceManager.md#bindtarget) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name        | Type                                    | Mandatory  | Description     |
  | ---------- | ---------------------------------------- | ---- | ------- |
  | deviceInfo | [DeviceInfo](#deviceinfo)                | Yes   | Device information.  |
  | authParam  | [AuthParam](#authparam)                  | Yes   | Authentication parameter.  |
  | callback   | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;pinToken&nbsp;?:&nbsp;number}&gt; | Yes   | Callback used to return the authentication result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    deviceId: string = "";
    pinToken?: number = 0;
  }

  interface DeviceInfo {
    deviceId: string;
    deviceName: string;
    deviceType: number;
    networkId: string;
    range: number;
  };

  interface ExtraInfo {
    targetPkgName: string;
    appName: string;
    appDescription: string;
    business: string;
  }

  interface AuthParam {
    authType: number; // Authentication type. The value 1 means no account PIN authentication.
    extraInfo: ExtraInfo;
  }

  // Information about the device to authenticate. The information can be obtained from the device discovery result.
  let deviceInfo: deviceManager.DeviceInfo = {
    deviceId: "XXXXXXXX",
    deviceName: "",
    deviceType: 0x0E,
    networkId: "xxxxxxx",
    range: 0,
    authForm: 0
  };
  let extraInfo: ExtraInfo = {
    targetPkgName: 'ohos.samples.xxx',
    appName: 'xxx',
    appDescription: 'xxx',
    business: '0'
  };
  let authParam: AuthParam = {
    authType: 1, // Authentication type. The value 1 means no account PIN authentication.
    extraInfo: extraInfo
  };

  try {
    dmInstance.authenticateDevice(deviceInfo, authParam, (err: BusinessError, data: Data) => {
      if (err) {
        console.error("authenticateDevice errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.info("authenticateDevice result:" + JSON.stringify(data));
      let token = data.pinToken;
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("authenticateDevice errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### unAuthenticateDevice<sup>8+</sup>

unAuthenticateDevice(deviceInfo: DeviceInfo): void

Deauthenticates a device.

> **NOTE**<br>This API is deprecated since API version 11. Use [unbindTarget](js-apis-distributedDeviceManager.md#unbindtarget) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name        | Type                     | Mandatory  | Description   |
  | ---------- | ------------------------- | ---- | ----- |
  | deviceInfo | [DeviceInfo](#deviceinfo) | Yes   | Device information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  interface DeviceInfo {
    deviceId: string;
    deviceName: string;
    deviceType: number;
    networkId: string;
    range: number;
  }

  try {
    let deviceInfo: deviceManager.DeviceInfo = {
      deviceId: "XXXXXXXX",
      deviceName: "",
      deviceType: 0x0E,
      networkId: "xxxxxxx",
      range: 0,
      authForm: 0
    };
    dmInstance.unAuthenticateDevice(deviceInfo);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("unAuthenticateDevice errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### verifyAuthInfo

verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void

Verifies authentication information.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description     |
  | -------- | ---------------------------------------- | ---- | ------- |
  | authInfo | [AuthInfo](#authinfo)                    | Yes   | Authentication information.  |
  | callback | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;level:&nbsp;number}&gt; | Yes   | Callback used to return the verification result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  interface ExtraInfo {
    authType: number;
    token: number;
  }

  interface AuthInfo {
    authType: number;
    token: number;
    extraInfo: ExtraInfo;
  }

  class Data {
    deviceId: string = "";
    level: number = 0;
  }

  let extraInfo: ExtraInfo = {
    authType: 0,
    token: 0
  };

  let authInfo: AuthInfo = {
    authType: 1,
    token: 123456,
    extraInfo: extraInfo
  };
  try {
    dmInstance.verifyAuthInfo(authInfo, (err: BusinessError, data: Data) => {
      if (err) {
        console.error("verifyAuthInfo errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
    console.info("verifyAuthInfo result:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("verifyAuthInfo errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### setUserOperation<sup>9+</sup>

setUserOperation(operateAction: number, params: string): void

Sets a user operation.

> **NOTE**<br>This API is deprecated since API version 11. Use [replyUiAction](js-apis-distributedDeviceManager-sys.md#replyuiaction) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | operateAction | number          | Yes   | User operation. The value ranges from 0 to 5.      |
  | params        | string          | Yes   | Input parameters of the user. The value is a string of 1 to 255 characters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.    |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified params is greater than 255.    |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

 try {
    /*
      operateAction = 0 - Grant the permission.
      operateAction = 1 - Revoke the permission.
      operateAction = 2 - The user operation in the permission request dialog box times out.
      operateAction = 3 - Cancel the display of the PIN box.
      operateAction = 4 - Cancel the display of the PIN input box.
      operateAction = 5 - Confirm the input in the PIN input box.
    */
    let operation = 0;
    dmInstance.setUserOperation(operation, "extra");
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("setUserOperation errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### requestCredentialRegisterInfo<sup>10+</sup>

requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback<{registerInfo: string}>): void

Obtains the registration information of the credential.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | requestInfo   | string          | Yes   | Request credential information. The value contains a maximum of 255 characters.      |
  | callback      | AsyncCallback<{registerInfo: string}>         | Yes   | Callback used to return the credential registration information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified params is greater than 255.    |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  interface CredentialInfo {
    version: string;
    userId: string;
  }

  class Data {
    registerInfo: string = "";
  }

  let credentialInfo: CredentialInfo = {
    version: "1.2.3",
    userId: "123"
  };
  try {
    let jsonCredentialInfo = JSON.stringify(credentialInfo);
    dmInstance.requestCredentialRegisterInfo(jsonCredentialInfo, (err: BusinessError, data: Data) => {
      if (data) {
        console.info("requestCredentialRegisterInfo result:" + JSON.stringify(data));
      } else {
        console.info("requestCredentialRegisterInfo result: data is null");
      }
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("requestCredentialRegisterInfo err:" + e.code + "," + e.message);
  }
  ```

### importCredential<sup>10+</sup>

importCredential(credentialInfo: string, callback: AsyncCallback<{resultInfo: string}>): void

Imports credential information.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | credentialInfo| string          | Yes   | Credential information to import. The value is a string of 1 to 64000 characters.      |
  | callback      | AsyncCallback<{resultInfo: string}>           | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified credentialInfo is greater than 5999. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    resultInfo: string = "";
  }

  interface CredentialData {
    credentialType: number;
    credentialId: string;
    serverPk: string;
    pkInfoSignature : string;
    pkInfo: string;
    authCode: string;
    peerDeviceId: string;
  }

  interface CredentialInfo {
    processType: number;
    authType: number;
    userId: string;
    deviceId: string;
    version: string;
    devicePk : string;
    credentialData : CredentialData;
  }

  let credentialData: CredentialData = {
    credentialType: 2,
    credentialId: "102",
    serverPk: "3059301306072A8648CE3D020106082A8648CE3D03",
    pkInfoSignature : "30440220490BCB4F822004C9A76AB8D97F80041FC0E",
    pkInfo: "",
    authCode: "",
    peerDeviceId: ""
  };


  let credentialInfo: CredentialInfo = {
    processType: 1,
    authType: 1,
    userId: "123",
    deviceId: "aaa",
    version: "1.2.3",
    devicePk : "0000",
    credentialData : credentialData
  };

  try {
    let jsonCredentialInfo = JSON.stringify(credentialInfo);
    dmInstance.importCredential(jsonCredentialInfo, (err: BusinessError, data: Data) => {
      if (data) {
        console.info("importCredential result:" + JSON.stringify(data));
      } else {
        console.info("importCredential result: data is null");
      }
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("importCredential err:" + e.code + "," + e.message);
  }
  ```

### deleteCredential<sup>10+</sup>

deleteCredential(queryInfo: string, callback: AsyncCallback<{resultInfo: string}>): void

Deletes credential information.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | queryInfo     | string          | Yes   | Credential information to delete. The value is a string of 1 to 64000 characters.      |
  | callback      | AsyncCallback<{resultInfo: string}>           | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified credentialInfo is greater than 5999. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    resultInfo: string = "";
  }

  interface QueryInfo {
    processType: number;
    authType: number;
    userId: string;
  }

  let queryInfo: QueryInfo = {
    processType: 1,
    authType: 1,
    userId: "123"
  };

  try {
    let jsonQueryInfo = JSON.stringify(queryInfo);
    dmInstance.deleteCredential(jsonQueryInfo, (err: BusinessError, data: Data) => {
      if (data) {
        console.info("deleteCredential result:" + JSON.stringify(data));
      } else {
        console.info("deleteCredential result: data is null");
      }
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deleteCredential err:" + e.code + "," + e.message);
  }
  ```

### on('uiStateChange')<sup>9+</sup>

on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void

Subscribes to UI status changes.

> **NOTE**<br>This API is deprecated since API version 11. Use [on('replyResult')](js-apis-distributedDeviceManager-sys.md#onreplyresult) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name     | Type                            | Mandatory| Description                           |
  | -------- | ------------------------------------ | ---- | ------------------------------ |
  | type     | string                                | Yes | Event type, which has a fixed value of **uiStateChange**.|
  | callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | Yes | Callback used to return the UI status.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    param: string = "";
  }

  interface TmpStr {
    verifyFailed: boolean;
  }

  try {
    dmInstance.on('uiStateChange', (data: Data) => {
      console.log("uiStateChange executed, dialog closed" + JSON.stringify(data));
      let tmpStr: TmpStr = JSON.parse(data.param);
      let isShow = tmpStr.verifyFailed;
      console.log("uiStateChange executed, dialog closed" + isShow);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("uiStateChange errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('uiStateChange')<sup>9+</sup>

off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void

Unsubscribes from UI status changes.

> **NOTE**<br>This API is deprecated since API version 11. Use [off('replyResult')](js-apis-distributedDeviceManager-sys.md#offreplyresult) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name     | Type                             | Mandatory| Description                           |
  | -------- | ------------------------------------- | ---- | ------------------------------ |
  | type     | string                                | Yes  | Event type, which has a fixed value of **uiStateChange**.|
  | callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | No  | Callback used to return the UI status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.off('uiStateChange');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("uiStateChange errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('deviceStateChange')

on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

Subscribes to changes in the device state.

> **NOTE**<br>This API is deprecated since API version 11. Use [on('deviceStateChange')](js-apis-distributedDeviceManager.md#ondevicestatechange) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type. The value is **deviceStateChange**, which indicates a device state change event.|
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChangeAction](#devicestatechangeaction),&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | Yes   | Callback used to return the device information and state.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  class Data {
    action: deviceManager.DeviceStateChangeAction = 0;
    device: deviceManager.DeviceInfo = {
      deviceId: "",
      deviceName: "",
      deviceType: 0,
      networkId: "",
      range: 0,
      authForm:0
    };
  }

  try {
    dmInstance.on('deviceStateChange', (data: Data) => {
      console.info("deviceStateChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deviceStateChange errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('deviceStateChange')

off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

Unsubscribes from changes in the device state.

> **NOTE**<br>This API is deprecated since API version 11. Use [off('deviceStateChange')](js-apis-distributedDeviceManager.md#offdevicestatechange) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **deviceStateChange**.       |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChangeAction](#devicestatechangeaction),&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | No   | Callback used to return the device information and state.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  class Data {
    action: deviceManager.DeviceStateChangeAction = 0;
    device: deviceManager.DeviceInfo = {
      deviceId: "",
      deviceName: "",
      deviceType: 0,
      networkId: "",
      range: 0,
      authForm:0
    };
  }

  try {
    dmInstance.off('deviceStateChange', (data: Data) => {
      console.info('deviceStateChange' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deviceStateChange errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('deviceFound')

on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void

Subscribes to device discovery events.

> **NOTE**<br>This API is deprecated since API version 11. Use [on('discoverSuccess')](js-apis-distributedDeviceManager.md#ondiscoversuccess) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                        |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **deviceFound**.|
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | Yes   | Callback used for device discovery.              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  class Data {
    subscribeId: number = 0;
    device: deviceManager.DeviceInfo = {
      deviceId: "",
      deviceName: "",
      deviceType: 0,
      networkId: "",
      range: 0,
      authForm:0
    };
  }

  try {
    dmInstance.on('deviceFound', (data: Data) => {
      console.info("deviceFound:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deviceFound errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('deviceFound')

off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void

Unsubscribes from device discovery events.

> **NOTE**<br>This API is deprecated since API version 11. Use [off('discoverSuccess')](js-apis-distributedDeviceManager.md#offdiscoversuccess) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **deviceFound**.               |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | No   | Callback used to return the device information and state.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  class Data {
    subscribeId: number = 0;
    device: deviceManager.DeviceInfo = {
      deviceId: "",
      deviceName: "",
      deviceType: 0,
      networkId: "",
      range: 0,
      authForm:0
    };
  }

  try {
    dmInstance.off('deviceFound', (data: Data) => {
      console.info('deviceFound' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deviceFound errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('discoverFail')

on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

Subscribes to device discovery failures.

> **NOTE**<br>This API is deprecated since API version 11. Use [on('discoverFailure')](js-apis-distributedDeviceManager.md#ondiscoverfailure) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **discoverFail**.|
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | Yes   | Callback used for the device discovery failure.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    subscribeId: number = 0;
    reason: number = 0;
  }

  try {
    dmInstance.on('discoverFail', (data: Data) => {
      console.info("discoverFail on:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("discoverFail errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('discoverFail')

off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

Unsubscribes from device discovery failures.

> **NOTE**<br>This API is deprecated since API version 11. Use [off('discoverFailure')](js-apis-distributedDeviceManager.md#offdiscoverfailure) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description               |
  | -------- | ---------------------------------------- | ---- | ----------------- |
  | type     | string                                   | Yes   | Event type, which has a fixed value of **discoverFail**.    |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | No   | Callback used for the device discovery failure.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    subscribeId: number = 0;
    reason: number = 0;
  }

  try {
    dmInstance.off('discoverFail', (data: Data) => {
      console.info('discoverFail' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("discoverFail errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('publishSuccess')<sup>9+</sup>

on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void

Subscribes to device information publication success events.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | Yes  | Event type, which has a fixed value of **publishSuccess**.|
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;    | Yes  | Callback used to return the publish ID.              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    publishId: number = 0;
  }

  try {
    dmInstance.on('publishSuccess', (data: Data) => {
      console.info("publishSuccess:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishSuccess errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('publishSuccess')<sup>9+</sup>

off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void

Unsubscribes from device information publication success events.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                | Mandatory| Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes  | Event type, which has a fixed value of **publishSuccess**.                |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;    | No  | Callback used to return the publish ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    publishId: number = 0;
  }

  try {
    dmInstance.off('publishSuccess', (data: Data) => {
      console.info('publishSuccess' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishSuccess errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('publishFail')<sup>9+</sup>

on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void

Subscribes to device information publication failures.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                             | Mandatory| Description                            |
  | -------- | ----------------------------------------------------- | ---- | ------------------------------ |
  | type     | string                                                | Yes  | Event type, which has a fixed value of **publishFail**.|
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | Yes  | Callback used for the publication failure.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    publishId: number = 0;
    reason: number = 0;
  }

  try {
    dmInstance.on('publishFail', (data: Data) => {
      console.info("publishFail on:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishFail errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('publishFail')<sup>9+</sup>

off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void

Unsubscribes from device information publication failures.

> **NOTE**<br>This API is deprecated since API version 11. There is no substitute API.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                             | Mandatory| Description               |
  | -------- | ----------------------------------------------------- | ---- | ----------------- |
  | type     | string                                                | Yes  | Event type, which has a fixed value of **publishFail**.    |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | No  | Callback used for the device discovery failure.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    publishId: number = 0;
    reason: number = 0;
  }

  try {
    dmInstance.off('publishFail', (data: Data) => {
      console.info('publishFail' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishFail errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('serviceDie')

on(type: 'serviceDie', callback: () =&gt; void): void

Subscribes to dead events of the **DeviceManager** service.

> **NOTE**<br>This API is deprecated since API version 11. Use [on('serviceDie')](js-apis-distributedDeviceManager.md#onservicedie) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                   | Mandatory  | Description                                      |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | Yes   | Event type, which has a fixed value of **serviceDie**.|
  | callback | ()&nbsp;=&gt;&nbsp;void | Yes   | Callback invoked when a dead event of the **DeviceManager** service occurs.                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.on("serviceDie", () => {
      console.info("serviceDie on");
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("serviceDie errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('serviceDie')

off(type: 'serviceDie', callback?: () =&gt; void): void

Unsubscribes from dead events of the **DeviceManager** service.

> **NOTE**<br>This API is deprecated since API version 11. Use [off('serviceDie')](js-apis-distributedDeviceManager.md#offservicedie) instead.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                   | Mandatory  | Description                                      |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | Yes   | Event type, which has a fixed value of **serviceDie**.|
  | callback | ()&nbsp;=&gt;&nbsp;void | No   | Callback used to return the dead event of the **DeviceManager** service.                    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [deviceManager.createDeviceManager](#devicemanagercreatedevicemanager).
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.off("serviceDie", () => {
      console.info("serviceDie off");
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("serviceDie errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```
