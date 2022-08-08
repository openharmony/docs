# Device Management

The **DeviceManager** module provides APIs for distributed device management.

System applications can call the APIs to do the following:

- Subscribe to or unsubscribe from device state changes.
- Discover peripheral untrusted devices.
- Authenticate or deauthenticate a device.
- Query the trusted device list.
- Query local device information, including the device name, type, and ID.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import

```
import deviceManager from '@ohos.distributedHardware.deviceManager';
```


## deviceManager.createDeviceManager

createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void

Creates a **DeviceManager** instance.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name       | Type                                      | Mandatory  | Description                                  |
  | ---------- | ---------------------------------------- | ---- | ------------------------------------ |
  | bundleName | string                                   | Yes   | Bundle name of an application.                          |
  | callback   | AsyncCallback&lt;[DeviceManager](#devicemanager)&gt; | Yes   | Callback used to return the **DeviceManager** instance created.|

- Example
  ```
  deviceManager.createDeviceManager("ohos.samples.jshelloworld", (err, data) => {     
      if (err) { 
          console.info("createDeviceManager err:" + JSON.stringify(err));    
          return;
      }
      console.info("createDeviceManager success");
      let dmInstance = data;
  });
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


## DeviceType

Enumerates the device types.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name          | Default Value | Description  |
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

| Name     | Default Value | Description             |
| ------- | ---- | --------------- |
| ONLINE  | 0    | The device is online.          |
| READY   | 1    | The device is ready, and the device information has been synchronized.|
| OFFLINE | 2    | The device is offline.          |
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

| Name                   | Default Value | Description   |
| --------------------- | ---- | ----- |
| DISCOVER_MODE_PASSIVE | 0x55 | Passive discovery.|
| DISCOVER_MODE_ACTIVE  | 0xAA | Active discovery.|


## ExchangeMedium 

Enumerates the media used for device discovery.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name  | Default Value | Description       |
| ---- | ---- | --------- |
| AUTO | 0    | Automatic.  |
| BLE  | 1    | Bluetooth.  |
| COAP | 2    | Wi-Fi.|
| USB  | 3    | USB. |

## ExchangeFreq 

Enumerates the device discovery frequencies.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name        | Default Value | Description   |
| ---------- | ---- | ----- |
| LOW        | 0    | Low frequency. |
| MID        | 1    | Medium frequency. |
| HIGH       | 2    | High frequency. |
| SUPER_HIGH | 3    | Ultra-high frequency.|


## SubscribeCap 

Enumerates the discovery capabilities.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                       | Default Value | Description            |
| ------------------------- | ---- | -------------- |
| SUBSCRIBE_CAPABILITY_DDMP | 0    | DDMP capability. This will be deprecated later.|
| SUBSCRIBE_CAPABILITY_OSD  | 1    | OSD capability.        |


## AuthParam

Defines the authentication parameters.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name       | Type                  | Mandatory  | Description        |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | Yes   | Authentication type.     |
| extraInfo | {[key:string] : any} | No   | Extended field.|

## AuthInfo

Defines authentication information.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name       | Type                  | Mandatory  | Description        |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | Yes   | Authentication type.     |
| token     | number               | Yes   | Authentication token.  |
| extraInfo | {[key:string] : any} | No   | Extended field.|


## DeviceManager

Provides APIs to obtain information about trusted devices and local devices. Before calling any API in **DeviceManager**, you must use **createDeviceManager** to create a **DeviceManager** instance, for example, **dmInstance**.


### release

release(): void

Releases this **DeviceManager** instance when it is no longer used.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- Example
  ```js
  dmInstance.release();
  ```


### getTrustedDeviceListSync

getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;

Obtains all trusted devices synchronously.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- Return value
  | Name                                    | Description       |
  | -------------------------------------- | --------- |
  | Array&lt;[DeviceInfo](#deviceinfo)&gt; | List of trusted devices obtained.|

- Example
  ```js
  var deviceInfoList = dmInstance.getTrustedDeviceListSync();
  ```


### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void

Obtains all trusted devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description                   |
  | -------- | ---------------------------------------- | ---- | --------------------- |
  | callback | AsyncCallback&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | Yes   | Callback used to return the list of trusted devices.|

- Example
  ```js
  dmInstance.getTrustedDeviceList((err, data) => {
      console.log("getTrustedDeviceList err: " + JSON.stringify(err));
      console.log('get trusted device info: ' + JSON.stringify(data));
    }
  );
  ```

### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;

Obtains all trusted devices. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- Return value
  | Type                                      | Description                   |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | Promise used to return the list of trusted devices.|

- Example
  ```js
  dmInstance.getTrustedDeviceList().then((data) => { 
      console.log('get trusted device info: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getTrustedDeviceList err: " + JSON.stringify(err));
  });
  ```

### getLocalDeviceInfoSync<sup>8+</sup>

getLocalDeviceInfoSync(): [DeviceInfo](#deviceinfo)

Obtains local device information synchronously.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- Return value
  | Name                                    | Description       |
  | -------------------------------------- | --------- |
  | Array&lt;[DeviceInfo](#deviceinfo)&gt; | List of local devices obtained.|

- Example
  ```js
  var deviceInfo = dmInstance.getLocalDeviceInfoSync();
  ```


### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void

Obtains local device information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description       |
  | -------- | ---------------------------------------- | ---- | --------- |
  | callback | AsyncCallback&lt;[DeviceInfo](#deviceinfo)&gt; | Yes   | Callback used to return the local device information.|

- Example
  ```js
  dmInstance.getLocalDeviceInfo((err, data) => {
      console.log("getLocalDeviceInfo err: " + JSON.stringify(err));
      console.log('get local device info: ' + JSON.stringify(data));
    }
  );
  ```

### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;

Obtains local device information. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- Return value
  | Type                                      | Description                   |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;[DeviceInfo](#deviceinfo)&gt; | Promise used to return the local device information.|

- Example
  ```js
  dmInstance.getLocalDeviceInfo().then((data) => { 
      console.log('get local device info: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getLocalDeviceInfo err: " + JSON.stringify(err));
  });
  ```

### startDeviceDiscovery

startDeviceDiscovery(subscribeInfo: SubscribeInfo): void

Starts to discover peripheral devices.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name           | Type                           | Mandatory  | Description   |
  | ------------- | ------------------------------- | ---- | ----- |
  | subscribeInfo | [SubscribeInfo](#subscribeinfo) | Yes   | Subscription information.|

- Example
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
  dmInstance.startDeviceDiscovery(subscribeInfo); // The deviceFound callback is invoked to notify the application when a device is discovered.
  ```

### stopDeviceDiscovery

stopDeviceDiscovery(subscribeId: number): void

Stops device discovery.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name         | Type  | Mandatory  | Description   |
  | ----------- | ------ | ---- | ----- |
  | subscribeId | number | Yes   | Subscription ID.|

- Example
  ```js
  // The subscribeId input must be the same as that automatically generated in startDeviceDiscovery.
  dmInstance.stopDeviceDiscovery(subscribeId);
  ```

### authenticateDevice

authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback<{deviceId: string, pinToken ?: number}>): void

Authenticates a device.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name        | Type                                    | Mandatory  | Description     |
  | ---------- | ---------------------------------------- | ---- | ------- |
  | deviceInfo | [DeviceInfo](#deviceinfo)                | Yes   | Device information.  |
  | authParam  | [AuthParam](#authparam)                  | Yes   | Authentication parameter.  |
  | callback   | AsyncCallback<{ deviceId: string, pinToken ?: number }> | Yes   | Callback used to return the authentication result.|

- Example
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
  dmInstance.authenticateDevice(deviceInfo, authParam, (err, data) => {
      if (err) {
          console.info(TAG + "authenticateDevice err:" + JSON.stringify(err));
          return;
      }
      console.info(TAG + "authenticateDevice result:" + JSON.stringify(data));
      token = data.pinToken;
  });
  ```

### unAuthenticateDevice<sup>8+</sup>

unAuthenticateDevice(deviceInfo: DeviceInfo): void

Deauthenticates a device.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name        | Type                     | Mandatory  | Description   |
  | ---------- | ------------------------- | ---- | ----- |
  | deviceInfo | [DeviceInfo](#deviceinfo) | Yes   | Device information.|

- Example
  ```js
  dmInstance.unAuthenticateDevice(deviceInfo);
  ```


### verifyAuthInfo

verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback<{deviceId: string, level: number}>): void

Verifies authentication information.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description     |
  | -------- | ---------------------------------------- | ---- | ------- |
  | authInfo | [AuthInfo](#authinfo)                    | Yes   | Authentication information.  |
  | authInfo | AsyncCallback<{ deviceId: string, level: number }> | Yes   | Callback used to return the verification result.|

- Example
  ```js
  let authInfo = {
    "authType": 1,
    "token": xxxxxx,
    "extraInfo": {}
  }
  dmInstance.verifyAuthInfo(authInfo, (err, data) => {
    if (err) {
        console.info(TAG + "verifyAuthInfo err:" + JSON.stringify(err));
        return;
    }
    console.info(TAG + "verifyAuthInfo result:" + JSON.stringify(data));
  });
  ```


### on('deviceStateChange')

on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

Subscribes to changes in the device state.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type. The value **'deviceStateChange'** indicates a device state change event.|
  | callback | Callback&lt;{ action: [DeviceStateChangeAction](#devicestatechangeaction), device: [DeviceInfo](#deviceinfo) }&gt; | Yes   | Callback invoked to return the device information and state.     |

- Example
  ```js
  dmInstance.on('deviceStateChange', (data) => {      
        console.info("deviceStateChange on:" + JSON.stringify(data));
      }
  );
  ```


### off('deviceStateChange')

off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

Unsubscribes from changes in the device state.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes   | Event type. The value **'deviceStateChange'** indicates a device state change event.       |
  | callback | Callback&lt;{ action: [DeviceStateChangeAction](#devicestatechangeaction), device: [DeviceInfo](#deviceinfo) }&gt; | Yes   | Callback invoked to return the device information and state.|

- Example
  ```js
  dmInstance.off('deviceStateChange', (data) => {      
        console.info('deviceStateChange' + JSON.stringify(data));
     }
  );
  ```


### on('deviceFound')

on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void

Subscribes to device discovery events.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description                        |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | Yes   | Event type. The value **'deviceFound'** indicates an event reported when a device is discovered.|
  | callback | Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt; | Yes   | Callback used for device discovery.              |

- Example
  ```js
  dmInstance.on('deviceFound', (data) => {
        console.info("deviceFound:" + JSON.stringify(data));
      }
  );
  ```

### off('deviceFound')

off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void

Unsubscribes from device discovery events.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description                         |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | Yes   | Event type. The value **'deviceFound'** indicates an event reported when a device is discovered.                |
  | callback | Callback&lt;{ subscribeId: number, device: [DeviceInfo](#deviceinfo) }&gt; | Yes   | Callback used for device discovery, which is invoked to return the device information and state.|

- Example
  ```js
  dmInstance.off('deviceFound', (data) => {      
        console.info('deviceFound' + JSON.stringify(data));
      }
  );
  ```

### on('discoverFail')

on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

Subscribes to device discovery failures.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description                            |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | Yes   | Event type. The event **'discoverFail'** indicates an event reported when device discovery fails.|
  | callback | Callback&lt;{ subscribeId: number, reason: number }&gt; | Yes   | Callback used for the device discovery failure.                |

- Example
  ```js
  dmInstance.on('discoverFail', (data) => {
        this.log("discoverFail on:" + JSON.stringify(data));
      }
  );
  ```

### off('discoverFail')

off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

Unsubscribes from device discovery failures.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                                    | Mandatory  | Description               |
  | -------- | ---------------------------------------- | ---- | ----------------- |
  | type     | string                                   | Yes   | Event type. The event **'discoverFail'** indicates an event reported when device discovery fails.    |
  | callback | Callback&lt;{ subscribeId: number, reason: number }&gt; | Yes   | Callback used for the device discovery failure.|

- Example
  ```js
  dmInstance.off('deviceFound', (data) => {      
        console.info('deviceFound' + JSON.stringify(data));
      }
  );
  ```


### on('serviceDie')

on(type: 'serviceDie', callback: () =&gt; void): void

Subscribes to dead events of the **DeviceManager** service.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                   | Mandatory  | Description                                      |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | Yes   | Event type. The value **'serviceDie'** indicates an event reported when the **DeviceManager** service is terminated unexpectedly.|
  | callback | () =&gt; void | Yes   | Callback invoked when a dead event of the **DeviceManager** service occurs.                      |

- Example
  ```js
  dmInstance.on("serviceDie", () => {      
        console.info("serviceDie on");
     }
  );
  ```


### off('serviceDie')

off(type: 'serviceDie', callback?: () =&gt; void): void

Unsubscribes from dead events of the **DeviceManager** service.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

- **Parameters**
  | Name      | Type                   | Mandatory  | Description                                      |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | Yes   | Event type. The value **'serviceDie'** indicates an event reported when the **DeviceManager** service is terminated unexpectedly.|
  | callback | () =&gt; void | No   | Callback used to return the dead event of the **DeviceManager** service.                    |

- Example
  ```js
  dmInstance.off("serviceDie", () => {      
        console.info("serviceDie off");
    }
  );
  ```
