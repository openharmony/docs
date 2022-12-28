# @ohos.distributedHardware.deviceManager (Device Management)

The **DeviceManager** module provides APIs for distributed device management.

System applications can call the APIs to do the following:

- Subscribe to or unsubscribe from device state changes.
- Discover peripheral untrusted devices.
- Authenticate or deauthenticate a device.
- Query the trusted device list.
- Query local device information, including the device name, type, and ID.
- Publish device information for discovery purposes.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import

```js
import deviceManager from '@ohos.distributedHardware.deviceManager';
```


## deviceManager.createDeviceManager

createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void

Creates a **DeviceManager** instance.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name    | Type                                                | Mandatory| Description                                                       |
| ---------- | ---------------------------------------------------- | ---- | ----------------------------------------------------------- |
| bundleName | string                                               | Yes  | Bundle name of the application.                                 |
| callback   | AsyncCallback&lt;[DeviceManager](#devicemanager)&gt; | Yes  | Callback used to return the **DeviceManager** instance created.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600102 | Failed to obtain the service.                                   |

**Example**

  ```js
  try {
    deviceManager.createDeviceManager("ohos.samples.jshelloworld", (err, data) => {
      if (err) { 
        console.error("createDeviceManager errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.info("createDeviceManager success");
      let dmInstance = data;
    });
  } catch(err) {
    console.error("createDeviceManager errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## DeviceInfo

Defines device information.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                    | Type                       | Mandatory  | Description      |
| ---------------------- | ------------------------- | ---- | -------- |
| deviceId               | string                    | Yes   | Unique identifier of a device.|
| deviceName             | string                    | Yes   | Device name.   |
| deviceType             | [DeviceType](#devicetype) | Yes   | Device type.   |
| networkId<sup>8+</sup> | string                    | Yes   | Network ID of the device. |
| range<sup>9+</sup>     | number                    | Yes   | Distance between the device (discovered device) and the device that initiates device discovery. |

## DeviceType

Enumerates the device types.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name          | Value | Description  |
| ------------ | ---- | ---- |
| SPEAKER      | 0x0A | Smart speaker.|
| PHONE        | 0x0E | Phone.  |
| TABLET       | 0x11 | Tablet.  |
| WEARABLE     | 0x6D | Wearable.|
| TV           | 0x9C | Smart TV. |
| CAR          | 0x83 | Car.   |
| UNKNOWN_TYPE | 0    | Unknown device type.|


## DeviceStateChangeAction

Enumerates the device states.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name     | Value | Description             |
| ------- | ---- | --------------- |
| ONLINE  | 0    | The device is physically online.          |
| READY   | 1    | The information between devices has been synchronized in the Distributed Data Service (DDS) module, and the device is ready for running distributed services.|
| OFFLINE | 2    | The device is physically offline.          |
| CHANGE  | 3    | The device information is changed.        |

## SubscribeInfo

Defines subscription information.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name           | Type                               | Mandatory  | Description               |
| ------------- | --------------------------------- | ---- | ----------------- |
| subscribeId   | number                            | Yes   | Subscription ID, used to identify a device discovery period.|
| mode          | [DiscoverMode ](#discovermode)    | No   | Device discovery mode.            |
| medium        | [ExchangeMedium](#exchangemedium) | No   | Medium used for device discovery.            |
| freq          | [ExchangeFreq](#exchangefreq)     | No   | Frequency of device discovery.            |
| isSameAccount | boolean                           | No   | Whether the same account is used on the discovered device.           |
| isWakeRemote  | boolean                           | No   | Whether to wake up the discovered device.          |
| capability    | [SubscribeCap](#subscribecap)     | No   | Discovery capability.            |


## DiscoverMode 

Enumerates the device discovery modes.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                   | Value | Description   |
| --------------------- | ---- | ----- |
| DISCOVER_MODE_PASSIVE | 0x55 | Passive discovery.|
| DISCOVER_MODE_ACTIVE  | 0xAA | Active discovery.|


## ExchangeMedium 

Enumerates the media used for device discovery.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name  | Value | Description       |
| ---- | ---- | --------- |
| AUTO | 0    | Automatic.  |
| BLE  | 1    | Bluetooth.  |
| COAP | 2    | Wi-Fi.|
| USB  | 3    | USB. |

## ExchangeFreq 

Enumerates the device discovery frequencies.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name        | Value | Description   |
| ---------- | ---- | ----- |
| LOW        | 0    | Low frequency. |
| MID        | 1    | Medium frequency. |
| HIGH       | 2    | High frequency. |
| SUPER_HIGH | 3    | Ultra-high frequency.|


## SubscribeCap 

Enumerates the discovery capabilities.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                       | Value | Description            |
| ------------------------- | ---- | -------------- |
| SUBSCRIBE_CAPABILITY_DDMP | 0    | DDMP capability. This will be deprecated later.|
| SUBSCRIBE_CAPABILITY_OSD  | 1    | OSD capability.        |


## AuthParam

Defines the authentication parameters.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name       | Type                  | Mandatory  | Description        |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | Yes   | Authentication type.     |
| extraInfo | {[key:string]&nbsp;:&nbsp;any} | No   | Extended field.|

## AuthInfo

Defines authentication information.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name       | Type                  | Mandatory  | Description        |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | Yes   | Authentication type.     |
| token     | number               | Yes   | Authentication token.  |
| extraInfo | {[key:string]&nbsp;:&nbsp;any} | No   | Extended field.|

## PublishInfo<sup>9+</sup>

Defines published device information.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name         | Type                             | Mandatory  | Description               |
| ------------- | --------------------------------- | ---- | ----------------- |
| publishId     | number                            | Yes   | ID used to identify a publication period.|
| mode          | [DiscoverMode ](#discovermode)    | Yes   | Device discovery mode.            |
| freq          | [ExchangeFreq](#exchangefreq)     | Yes   | Frequency of device discovery.            |
| ranging       | boolean                           | Yes   | Whether the device supports distance reporting.            |

## DeviceManager

Provides APIs to obtain information about trusted devices and local devices. Before calling any API in **DeviceManager**, you must use **createDeviceManager** to create a **DeviceManager** instance, for example, **dmInstance**.

### release

release(): void

Releases this **DeviceManager** instance when it is no longer used.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    dmInstance.release();
  } catch (err) {
    console.error("release errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getTrustedDeviceListSync

getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;

Obtains all trusted devices synchronously.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Name                                    | Description       |
  | -------------------------------------- | --------- |
  | Array&lt;[DeviceInfo](#deviceinfo)&gt; | List of trusted devices obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    var deviceInfoList = dmInstance.getTrustedDeviceListSync();
  } catch (err) {
    console.error("getTrustedDeviceListSync errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void

Obtains all trusted devices. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                   |
  | -------- | ---------------------------------------- | ---- | --------------------- |
  | callback | AsyncCallback&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | Yes   | Callback used to return the list of trusted devices.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    dmInstance.getTrustedDeviceList((err, data) => {
      if (err) {
        console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get trusted device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;

Obtains all trusted devices. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                                      | Description                   |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | Promise used to return the list of trusted devices.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  dmInstance.getTrustedDeviceList().then((data) => {
    console.log('get trusted device info: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### getLocalDeviceInfoSync<sup>8+</sup>

getLocalDeviceInfoSync(): [DeviceInfo](#deviceinfo)

Obtains local device information synchronously.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Name                     | Description             |
  | ------------------------- | ---------------- |
  | [DeviceInfo](#deviceinfo) | List of local devices obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    var deviceInfo = dmInstance.getLocalDeviceInfoSync();
  } catch (err) {
    console.error("getLocalDeviceInfoSync errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void

Obtains local device information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description       |
  | -------- | ---------------------------------------- | ---- | --------- |
  | callback | AsyncCallback&lt;[DeviceInfo](#deviceinfo)&gt; | Yes   | Callback used to return the local device information.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    dmInstance.getLocalDeviceInfo((err, data) => {
    if (err) {
      console.error("getLocalDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
      return;
    }
      console.log('get local device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("getLocalDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;

Obtains local device information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

  | Type                                      | Description                   |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;[DeviceInfo](#deviceinfo)&gt; | Promise used to return the local device information.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| ------- | --------------------------------------------------------------- |
| 11600101| Failed to execute the function.                                 |

**Example**

  ```js
  dmInstance.getLocalDeviceInfo().then((data) => {
    console.log('get local device info: ' + JSON.stringify(data));
  }).catch((err) => {
    console.error("getLocalDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### startDeviceDiscovery<sup>8+</sup>

startDeviceDiscovery(subscribeInfo: SubscribeInfo): void

Starts to discover peripheral devices.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name           | Type                      | Mandatory| Description   |
  | ------------- | ------------------------------- | ---- | ----- |
  | subscribeInfo | [SubscribeInfo](#subscribeinfo) | Yes  | Subscription information.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery invalid.                                              |

**Example**

  ```js
  // Automatically generate a unique subscription ID.
  var subscribeId = Math.floor(Math.random() * 10000 + 1000);
  var subscribeInfo = {
      "subscribeId": subscribeId,
      "mode": 0xAA, // Active discovery
      "medium": 0, // Automatic. Multiple media can be used for device discovery.
      "freq": 2, // High frequency
      "isSameAccount": false,
      "isWakeRemote": false,
      "capability": 1
  };
  try {
    dmInstance.startDeviceDiscovery(subscribeInfo); // The deviceFound callback is invoked to notify the application when a device is discovered.
  } catch (err) {
    console.error("startDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### startDeviceDiscovery<sup>9+</sup>

startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void

Starts to discover peripheral devices and filters discovered devices.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name           | Type                      | Mandatory  | Description   |
  | ------------- | ------------------------------- | ---- | -----  |
  | subscribeInfo | [SubscribeInfo](#subscribeinfo) | Yes  | Subscription information.|
  | filterOptions | string                          | No  | Options for filtering discovered devices.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery invalid.                                              |

**Example**

  ```js
  // Automatically generate a unique subscription ID.
  var subscribeId = Math.floor(Math.random() * 10000 + 1000);
  var subscribeInfo = {
      "subscribeId": subscribeId,
      "mode": 0xAA, // Active discovery
      "medium": 0, // Automatic. Multiple media can be used for device discovery.
      "freq": 2, // High frequency
      "isSameAccount": false,
      "isWakeRemote": false,
      "capability": 1
  };
  var filterOptions = {
    "filter_op": "OR", // Optional. The default value is OR.
    "filters": [
        {
            "type": "range",
            "value": 50 // Filter discovered devices based on the distance (in cm).
        }
    ]
  };
  try {
    dmInstance.startDeviceDiscovery(subscribeInfo, JSON.stringify(filterOptions)); // The deviceFound callback is invoked to notify the application when a device is discovered.
  } catch (err) {
    console.error("startDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### stopDeviceDiscovery

stopDeviceDiscovery(subscribeId: number): void

Stops device discovery.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name         | Type  | Mandatory  | Description   |
  | ----------- | ------ | ---- | ----- |
  | subscribeId | number | Yes   | Subscription ID.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  // The subscribeId input must be the same as that automatically generated in startDeviceDiscovery.
  try {
    dmInstance.stopDeviceDiscovery(subscribeId);
  } catch (err) {
    console.error("stopDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### publishDeviceDiscovery<sup>9+</sup>

publishDeviceDiscovery(publishInfo: PublishInfo): void

Publishes device information for discovery purposes.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name         | Type                       | Mandatory| Description   |
  | ------------- | ------------------------------- | ---- | ----- |
  | publishInfo   | [PublishInfo](#publishinfo)     | Yes  | Device information to publish.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600105 | Publish invalid.                                                |

**Example**

  ```js
  // Automatically generate a unique subscription ID.
  var publishId = Math.floor(Math.random() * 10000 + 1000);
  var publishInfo = {
      "publishId": publishId,
      "mode": 0xAA, // Active discovery
      "freq": 2, // High frequency
      "ranging": 1 // The device supports reporting the distance to the discovery initiator.
  };
  try {
    dmInstance.publishDeviceDiscovery(publishInfo); // A callback is invoked to notify the application when the device information is published.
  } catch (err) {
    console.error("publishDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### unPublishDeviceDiscovery<sup>9+</sup>

unPublishDeviceDiscovery(publishId: number): void

Stops publishing device information.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name       | Type| Mandatory| Description |
  | ----------- | -------- | ---- | ----- |
  | publishId   | number   | Yes  | Publish ID.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  // The publishId input must be the same as that automatically generated in publishDeviceDiscovery.
  try {
    dmInstance.unPublishDeviceDiscovery(publishId);
  } catch (err) {
    console.error("unPublishDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### authenticateDevice

authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void

Authenticates a device.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name        | Type                                    | Mandatory  | Description     |
  | ---------- | ---------------------------------------- | ---- | ------- |
  | deviceInfo | [DeviceInfo](#deviceinfo)                | Yes   | Device information.  |
  | authParam  | [AuthParam](#authparam)                  | Yes   | Authentication parameter.  |
  | callback   | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;pinToken&nbsp;?:&nbsp;number}&gt; | Yes   | Callback used to return the authentication result.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600103 | Authentication invalid.                                         |

**Example**

  ```js
  // Information about the device to authenticate. The information can be obtained from the device discovery result.
  var deviceInfo ={
      "deviceId": "XXXXXXXX",
      "deviceName": "",
      deviceType: 0x0E
  };
  let authParam = {
      "authType": 1, // Authentication type. The value 1 means no account PIN authentication.
      "extraInfo": {} 
  }
  try {
    dmInstance.authenticateDevice(deviceInfo, authParam, (err, data) => {
      if (err) {
          console.error("authenticateDevice errCode:" + err.code + ",errMessage:" + err.message);
          return;
      }
      console.info("authenticateDevice result:" + JSON.stringify(data));
      let token = data.pinToken;
    });
  } catch (err) {
    console.error("authenticateDevice errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### unAuthenticateDevice<sup>8+</sup>

unAuthenticateDevice(deviceInfo: DeviceInfo): void

Deauthenticates a device.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name        | Type                     | Mandatory  | Description   |
  | ---------- | ------------------------- | ---- | ----- |
  | deviceInfo | [DeviceInfo](#deviceinfo) | Yes   | Device information.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    dmInstance.unAuthenticateDevice(deviceInfo);
  } catch (err) {
    console.error("unAuthenticateDevice errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### verifyAuthInfo

verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void

Verifies authentication information.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description     |
  | -------- | ---------------------------------------- | ---- | ------- |
  | authInfo | [AuthInfo](#authinfo)                    | Yes   | Authentication information.  |
  | callback | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;level:&nbsp;number}&gt; | Yes   | Callback used to return the verification result.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  let authInfo = {
    "authType": 1,
    "token": xxxxxx,
    "extraInfo": {}
  }
  try {
    dmInstance.verifyAuthInfo(authInfo, (err, data) => {
    if (err) {
        console.error("verifyAuthInfo errCode:" + err.code + ",errMessage:" + err.message);
        return;
    }
    console.info("verifyAuthInfo result:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("verifyAuthInfo errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### setUserOperation<sup>9+</sup>

setUserOperation(operateAction: number, params: string): void;

Sets a user operation.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | operateAction | number          | Yes   | User operation.      |
  | params        | string          | Yes   | Input parameters of the user.|

**Example**

  ```js
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
    this.dmInstance.setUserOperation(operation, "extra")
    } catch (err) {
      console.error("setUserOperation errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('uiStateChange')<sup>9+</sup>

on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void;

Subscribes to UI status changes.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name     | Type                            | Mandatory| Description                           |
  | -------- | ------------------------------------ | ---- | ------------------------------ |
  | type     | string                                | Yes | Event type. The value **'uiStateChange'** indicates a UI status change event.|
  | callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | Yes | Callback used to return the UI status.       |

**Example**

  ```js
  try {
    dmInstance.on('uiStateChange', (data) => {
    console.log("uiStateChange executed, dialog closed" + JSON.stringify(data))
    var tmpStr = JSON.parse(data.param)
    this.isShow = tmpStr.verifyFailed
    console.log("uiStateChange executed, dialog closed" + this.isShow)
    if (!this.isShow) {
        this.destruction()
    }
  });
  } catch (err) {
    console.error("uiStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('uiStateChange')<sup>9+</sup>

off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void;

Unsubscribes from UI status changes.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name     | Type                             | Mandatory| Description                           |
  | -------- | ------------------------------------- | ---- | ------------------------------ |
  | type     | string                                | Yes  | Event type. The value **'uiStateChange'** indicates a UI status change event.|
  | callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | No  | Callback used to return the UI status.|

**Example**

  ```js
  try {
    dmInstance.off('uiStateChange');
  } catch (err) {
    console.error("uiStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('deviceStateChange')

on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

Subscribes to changes in the device state.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type. The value **'deviceStateChange'** indicates a device state change event.|
  | callback | Callback&lt;{ action: [DeviceStateChangeAction](#devicestatechangeaction), device: [DeviceInfo](#deviceinfo) }&gt; | Yes   | Callback used to return the device information and state.     |

**Example**

  ```js
  try {
    dmInstance.on('deviceStateChange', (data) => {
      console.info("deviceStateChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('deviceStateChange')

off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

Unsubscribes from changes in the device state.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes   | Event type. The value **'deviceStateChange'** indicates a device state change event.       |
  | callback | Callback&lt;{ action: [DeviceStateChangeAction](#devicestatechangeaction), device: [DeviceInfo](#deviceinfo) }&gt; | No   | Callback used to return the device information and state.|

**Example**

  ```js
  try {
    dmInstance.off('deviceStateChange', (data) => {
      console.info('deviceStateChange' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('deviceFound')

on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void

Subscribes to device discovery events.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                        |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | Yes   | Event type. The value **'deviceFound'** indicates an event reported when a device is discovered.|
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | Yes   | Callback used for device discovery.              |

**Example**

  ```js
  try {
    dmInstance.on('deviceFound', (data) => {
      console.info("deviceFound:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceFound errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('deviceFound')

off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void

Unsubscribes from device discovery events.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes   | Event type. The value **'deviceFound'** indicates an event reported when a device is discovered.                |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | No   | Callback used to return the device information and state.|

**Example**

  ```js
  try {
    dmInstance.off('deviceFound', (data) => {
      console.info('deviceFound' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceFound errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('discoverFail')

on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

Subscribes to device discovery failures.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type. The event **'discoverFail'** indicates an event reported when device discovery fails.|
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | Yes   | Callback used for the device discovery failure.                |

**Example**

  ```js
  try {
    dmInstance.on('discoverFail', (data) => {
        console.info("discoverFail on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverFail errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('discoverFail')

off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

Unsubscribes from device discovery failures.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                                    | Mandatory  | Description               |
  | -------- | ---------------------------------------- | ---- | ----------------- |
  | type     | string                                   | Yes   | Event type. The event **'discoverFail'** indicates an event reported when device discovery fails.    |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | No   | Callback used for the device discovery failure.|

**Example**

  ```js
  try {
    dmInstance.off('discoverFail', (data) => {
      console.info('discoverFail' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverFail errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('publishSuccess')<sup>9+</sup>

on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void

Subscribes to device information publication success events.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | Yes  | Event type. The value **'publishSuccess'** indicates an event reported when device information is published.|
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;    | Yes  | Callback used to return the publish ID.              |


**Example**

  ```js
  try {
    dmInstance.on('publishSuccess', (data) => {
      console.info("publishSuccess:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("publishSuccess errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('publishSuccess')<sup>9+</sup>

off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void

Unsubscribes from device information publication success events.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                | Mandatory| Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes  | Event type. The value **'publishSuccess'** indicates an event reported when device information is published.                |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;    | No  | Callback used to return the publish ID.|

**Example**

  ```js
  try {
    dmInstance.off('publishSuccess', (data) => {
      console.info('publishSuccess' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("publishSuccess errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('publishFail')<sup>9+</sup>

on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void

Subscribes to device information publication failures.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                             | Mandatory| Description                            |
  | -------- | ----------------------------------------------------- | ---- | ------------------------------ |
  | type     | string                                                | Yes  | Event type. The event **'publishFail'** indicates an event reported when publishing device information fails.|
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | Yes  | Callback used for the publication failure.                |

**Example**

  ```js
  try {
    dmInstance.on('publishFail', (data) => {
      console.info("publishFail on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("publishFail errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('publishFail')<sup>9+</sup>

off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void

Unsubscribes from device information publication failures.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name    | Type                                             | Mandatory| Description               |
  | -------- | ----------------------------------------------------- | ---- | ----------------- |
  | type     | string                                                | Yes  | Event type. The event **'publishFail'** indicates an event reported when publishing device information fails.    |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | No  | Callback used for the device discovery failure.|

**Example**

  ```js
  try {
    dmInstance.off('publishFail', (data) => {
      console.info('publishFail' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("publishFail errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('serviceDie')

on(type: 'serviceDie', callback: () =&gt; void): void

Subscribes to dead events of the **DeviceManager** service.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                   | Mandatory  | Description                                      |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | Yes   | Event type. The value **'serviceDie'** indicates an event reported when the **DeviceManager** service is terminated unexpectedly.|
  | callback | ()&nbsp;=&gt;&nbsp;void | Yes   | Callback invoked when a dead event of the **DeviceManager** service occurs.                      |

**Example**

  ```js
  try {
    dmInstance.on("serviceDie", () => {
      console.info("serviceDie on");
    });
  } catch (err) {
    console.error("serviceDie errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('serviceDie')

off(type: 'serviceDie', callback?: () =&gt; void): void

Unsubscribes from dead events of the **DeviceManager** service.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM (available only to system applications)

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

  | Name      | Type                   | Mandatory  | Description                                      |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | Yes   | Event type. The value **'serviceDie'** indicates an event reported when the **DeviceManager** service is terminated unexpectedly.|
  | callback | ()&nbsp;=&gt;&nbsp;void | No   | Callback used to return the dead event of the **DeviceManager** service.                    |

**Example**

  ```js
  try {
    dmInstance.off("serviceDie", () => {
      console.info("serviceDie off");
    });
  } catch (err) {
    console.error("serviceDie errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```
