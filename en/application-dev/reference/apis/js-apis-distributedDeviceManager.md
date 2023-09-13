# @ohos.distributedDeviceManager (Device Management)

The **deviceManager** module provides APIs for distributed device management.

Applications can call the APIs to:

- Subscribe to or unsubscribe from device state changes.
- Discover untrusted devices nearby.
- Authenticate or deauthenticate a device.
- Query the trusted device list.
- Query local device information, including the device name, type, and ID.


> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import deviceManager from '@ohos.distributedDeviceManager';
```


## deviceManager.createDeviceManager

createDeviceManager(bundleName: string): DeviceManager;

Creates a **DeviceManager** instance. The **DeviceManager** instance is the entry for invoking the APIs for distributed device management. It can be used to obtain information about trusted devices and local devices.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name    | Type                                                | Mandatory| Description                                                       |
| ---------- | ---------------------------------------------------- | ---- | ----------------------------------------------------------- |
| bundleName | string                                               | Yes  | Bundle name of the application.                                 |

**Return value**

| Name                                       | Description       |
| ------------------------------------------- | --------- |
| [DeviceManager](#devicemanager) | **DeviceManager** instance created.|

**Example**

  ```js
  try {
    let dmInstance = deviceManager.createDeviceManager("ohos.samples.jshelloworld");
  } catch(err) {
    console.error("createDeviceManager errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## deviceManager.releaseDeviceManager

releaseDeviceManager(deviceManager: DeviceManager): void;

Releases a **DeviceManager** instance that is no longer used.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name    | Type                                                | Mandatory| Description                               |
| ---------- | ---------------------------------------------------- | ---- | --------------------------------- |
| deviceManager | [DeviceManager](#devicemanager)    | Yes  | **DeviceManager** instance to release.                                 |

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    deviceManager.releaseDeviceManager(dmInstance);
  } catch (err) {
    console.error("release device manager errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## DeviceBasicInfo

Represents the basic information about a distributed device.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

| Name                    | Type                       | Mandatory  | Description      |
| ---------------------- | ------------------------- | ---- | -------- |
| deviceId               | string                    | Yes   | Unique ID of the device. The value is the udid-hash (hash value of the UDID) and appid encrypted using SHA-256.|
| deviceName             | string                    | Yes   | Device name.   |
| deviceType             | string                    | Yes   | Device type.   |
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

getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;;

Obtains all trusted devices synchronously.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

| Name                                       | Description       |
| ------------------------------------------- | --------- |
| Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt; | List of trusted devices obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    var deviceInfoList = dmInstance.getAvailableDeviceListSync();
  } catch (err) {
    console.error("getAvailableDeviceListSync errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getAvailableDeviceList

getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void;

Obtains all trusted devices. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description                   |
| -------- | ---------------------------------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt;&gt; | Yes   | Callback invoked to return the list of trusted devices.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    dmInstance.getAvailableDeviceList((err, data) => {
      if (err) {
        console.error("getAvailableDeviceList errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get available device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("getAvailableDeviceList errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getAvailableDeviceList

getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;;

Obtains all trusted devices. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

| Type                                                      | Description                              |
| ---------------------------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  dmInstance.getAvailableDeviceList().then((data) => {
    console.log('get available device info: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error("getAvailableDeviceList errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### getLocalDeviceNetworkId

getLocalDeviceNetworkId(): string;

Obtains the network ID of the local device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

| Name                     | Description             |
| ------------------------- | ---------------- |
| string | Network ID of the local device obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    var deviceNetworkId = dmInstance.getLocalDeviceNetworkId();
    console.log('local device networkId: ' + JSON.stringify(deviceNetworkId));
  } catch (err) {
    console.error("getLocalDeviceNetworkId errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getLocalDeviceName

getLocalDeviceName(): string;

Obtains the local device name.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

| Name                     | Description             |
| ------------------------- | ---------------- |
| string                    | Name of the local device obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    var deviceName = dmInstance.getLocalDeviceName();
    console.log('local device name: ' + JSON.stringify(deviceName));
  } catch (err) {
    console.error("getLocalDeviceName errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getLocalDeviceType

getLocalDeviceType(): number;

Obtains the local device type.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

| Name                     | Description             |
| ------------------------- | ---------------- |
| number                    | Local device type obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    var deviceType = dmInstance.getLocalDeviceType();
    console.log('local device type: ' + JSON.stringify(deviceType));
  } catch (err) {
    console.error("getLocalDeviceType errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getLocalDeviceId

getLocalDeviceId(): string;

Obtains the local device ID.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Return value**

| Name                     | Description             |
| ------------------------- | ---------------- |
| string                    | Local device ID obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    var deviceId = dmInstance.getLocalDeviceId();
    console.log('local device id: ' + JSON.stringify(deviceId));
  } catch (err) {
    console.error("getLocalDeviceId errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getDeviceName

getDeviceName(networkId: string): string;

Obtains the device name based on the network ID of the specified device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| networkId| string                                   | Yes  | Network ID of the device.|

**Return value**

| Name                     | Description             |
| ------------------------- | ---------------- |
| string                    | Device name obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    // Network ID of the device, which can be obtained from the trusted device list.
    let networkId = "xxxxxxx"
    var deviceName = dmInstance.getDeviceName(networkId);
    console.log('device name: ' + JSON.stringify(deviceName)); 
  } catch (err) {
    console.error("getDeviceName errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getDeviceType

getDeviceType(networkId: string): number;

Obtains the device type based on the network ID of the specified device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| networkId| string                                   | Yes  | Network ID of the device.|

**Return value**

| Name                     | Description             |
| ------------------------- | ---------------- |
| number                    | Device type obtained.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    // Network ID of the device, which can be obtained from the trusted device list.
    let networkId = "xxxxxxx"
    var deviceType = dmInstance.getDeviceType(networkId);
    console.log('device type: ' + JSON.stringify(deviceType)); 
  } catch (err) {
    console.error("getDeviceType errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### startDiscovering

startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object} ): void;

Starts to discover devices nearby. The discovery process automatically stops when 2 minutes have elapsed. A maximum of 99 devices can be discovered.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name           | Type                       | Mandatory  | Description   |
| ------------- | ------------------------------- | ---- | -----  |
| discoverParam  | {[key:&nbsp;string]:&nbsp;Object}      | Yes  | Identifier of the device to discover. It specifies the type of the target to discover.<br>**discoverTargetType**: The default discovery target is device. The value is **1**.|
| filterOptions | {[key:&nbsp;string]:&nbsp;Object}          | No  | Options for filtering discovered devices. The default value is **undefined**, which means to discover offline devices. The following **key** values are carried:<br>**availableStatus(0-1)**: Discover trusted devices only. The value **0** indicates that the device is untrusted.<br>- **0**: The device is offline. The client needs to call **bindTarget** to bind the device.<br>- **1**: The device is online and can be connected.<br>**discoverDistance(0-100)**: Discover devices within a certain distance (in cm) from the local device.<br>**authenticationStatus(0-1)**: Discover devices based on the authentication status.<br>- **0**: The device is not authenticated.<br>- **1**: The device has been authenticated.<br>**authorizationType(0-2)**: Discover devices based on the authorization type.<br>- **0**: device authenticated by a temporarily agreed session key.<br>- **1**: device authenticated by a key of the same account.<br>- **2**: devices authenticated by a credential key of different accounts.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery repeats.                                              |

**Example**

  ```js
  var discoverParam = {
    'discoverTargetType': 1
  };
  var filterOptions = {
    'availableStatus': 1,
    'discoverDistance': 50,
    'authenticationStatus': 0,
    'authorizationType': 0
  };
  try {
    dmInstance.startDiscovering(discoverParam, filterOptions); // When devices are discovered, discoverSuccess is called to notify the application.
  } catch (err) {
    console.error("startDiscovering errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### stopDiscovering

stopDiscovering(): void;

Stops device discovery.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Stop discovery repeats.                                         |

**Example**

  ```js
  try {
    dmInstance.stopDiscovering();
  } catch (err) {
    console.error("stopDiscovering errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### bindTarget

bindTarget(deviceId: string, bindParam: {[key:&nbsp;string]:&nbsp;Object} , callback: AsyncCallback&lt;{deviceId: string}>): void;

Binds a device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name    | Type                                               | Mandatory | Description        |
| ---------- | --------------------------------------------------- | ----- | ------------ |
| deviceId   | string                                              | Yes   | Device ID.  |
| bindParam  | {[key:&nbsp;string]:&nbsp;Object}                             | Yes   | Authentication parameters. You can determine the key-value pair to be passed in. By default, the following **key** values are carried:<br>**bindType**: binding type.<br>- **1**: PIN.<br>- **2**: QR code.<br>- 3: NFC.<br>- 4: No interaction.<br>**targetPkgName**: bundle name of the target to bind.<br>**appName**: application that attempts to bind the target.<br>**appOperation**: reason for the application to bind the target.<br>**customDescription**: detailed description of the operation.  |
| callback   | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;}&gt; | Yes   | Callback invoked to return the authentication result.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600103 | Bind invalid.                                                   |

**Example**

  ```js
  // Information about the device to authenticate. The information can be obtained from the device discovery result.
  var deviceId ="XXXXXXXX";
  let bindParam = {
          'authType': 1, // Authentication type. The value 1 means PIN authentication without the account.
          'targetPkgName': 'xxxx',
          'appName': 'xxxx',
          'appOperation': 'xxxx',
          'customDescription': 'xxxx'
  }
  try {
    dmInstance.bindTarget(deviceId, bindParam, (err, data) => {
      if (err) {
          console.error("bindTarget errCode:" + err.code + ",errMessage:" + err.message);
          return;
      }
      console.info("bindTarget result:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("bindTarget errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### unbindTarget

unbindTarget(deviceId: string): void;

Unbinds a device.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| deviceId | string                    | Yes  | Device ID.|

**Error codes**

For details about the error codes, see [Device Management Error Codes](../errorcodes/errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**Example**

  ```js
  try {
    var deviceId ="XXXXXXXX";
    dmInstance.unbindTarget(deviceId);
  } catch (err) {
    console.error("unbindTarget errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### replyUiAction

replyUiAction(action: number, actionResult: string): void;

Replies to the user's UI operation. This API can be used only by the PIN HAP of the **deviceManager**.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

| Name      | Type           | Mandatory | Description               |
| ------------- | --------------- | ---- | ------------------- |
| action        | number          | Yes   | User operation.      |
| actionResult        | string          | Yes   | Operation result.|

**Example**

  ```js
 try {
    /*
      action = 0 - Grant the permission.
      action = 1 - Revoke the permission.
      action = 2 - The user operation in the permission request dialog box times out.
      action = 3 - Cancel the display of the PIN box.
      action = 4 - Cancel the display of the PIN input box.
      action = 5 - Confirm the input in the PIN input box.
    */
    let operation = 0;
    dmInstance.replyUiAction(operation, "extra")
    } catch (err) {
      console.error("replyUiAction errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('replyResult')

on(type: 'replyResult', callback: Callback&lt;{ param: string}&gt;): void;

Subscribes to the UI operation reply result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                            | Mandatory| Description                           |
| -------- | ------------------------------------ | ---- | ------------------------------ |
| type     | string                                | Yes | Event type to subscribe to. The value **replyResult** indicates the reply result of the UI operation.|
| callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | Yes | Callback invoked to return the UI status.       |

**Example**

  ```js
  try {
    dmInstance.on('replyResult', (data) => {
    console.log("replyResult executed, dialog closed" + JSON.stringify(data))
    var tmpStr = JSON.parse(data.param)
    var isShow = tmpStr.verifyFailed
    console.log("replyResult executed, dialog closed" + isShow)
  });
  } catch (err) {
    console.error("replyResult errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('replyResult')

off(type: 'replyResult', callback?: Callback&lt;{ param: string}&gt;): void;

Unsubscribes from the UI operation reply result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                             | Mandatory| Description                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| type     | string                                | Yes  | Event type to unsubscribe from. The value **replyResult** indicates the reply result of the UI operation.|
| callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | No  | Callback for the UI status.|

**Example**

  ```js
  try {
    dmInstance.off('replyResult');
  } catch (err) {
    console.error("replyResult errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('deviceStateChange')

on(type: 'deviceStateChange', callback: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void;

Subscribes to changes in the device state.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | string                                   | Yes   | Event type. The value **'deviceStateChange'** indicates a device state change event.|
| callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChange](#devicestatechange),&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | Yes   | Callback invoked to return the device information and state.     |

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

off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void;

Unsubscribes from changes in the device state.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description                         |
| -------- | ---------------------------------------- | ---- | --------------------------- |
| type     | string                                   | Yes   | Event type. The value **'deviceStateChange'** indicates a device state change event.       |
| callback | Callback&lt;{&nbsp;action:&nbsp;[deviceStateChange](#devicestatechange),&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | No   | Callback for the device information and state.|

**Example**

  ```js
  try {
    dmInstance.off('deviceStatusChange', (data) => {
      console.info('deviceStatusChange' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceStatusChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('discoverSuccess')

on(type: 'discoverSuccess', callback: Callback&lt;{ device: DeviceBasicInfo }&gt;): void;

Subscribes to device discovery events.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description                        |
| -------- | ---------------------------------------- | ---- | -------------------------- |
| type     | string                                   | Yes   | Event type. The value **'discoverSuccess'** indicates an event of successful device discovery.|
| callback | Callback&lt;{&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | Yes   | Callback invoked to return a device discovery event.              |

**Example**

  ```js
  try {
    dmInstance.on('discoverSuccess', (data) => {
      console.info("discoverSuccess:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverSuccess errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('discoverSuccess')

off(type: 'discoverSuccess', callback?: Callback&lt;{ device: DeviceBasicInfo }&gt;): void;

Unsubscribes from device discovery events.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description                         |
| -------- | ---------------------------------------- | ---- | --------------------------- |
| type     | string                                   | Yes   | Event type. The value **'discoverSuccess'** indicates a device discovery event.                |
| callback | Callback&lt;{&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | No   | Callback for the device discovery event.|

**Example**

  ```js
  try {
    dmInstance.off('discoverSuccess', (data) => {
      console.info('discoverSuccess' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverSuccess errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('deviceNameChange')

on(type: 'deviceNameChange', callback: Callback&lt;{ deviceName: string }&gt;): void;

Subscribes to device name changes.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | string                                   | Yes   | Event type. The value **'deviceNameChange'** indicates a device name change event.|
| callback | Callback&lt;{&nbsp;deviceName:&nbsp;string}&gt; | Yes   | Callback invoked to return the device name change.                |

**Example**

  ```js
  try {
    dmInstance.on('deviceNameChange', (data) => {
        console.info("deviceNameChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceNameChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('deviceNameChange')

off(type: 'deviceNameChange', callback?: Callback&lt;{ deviceName: string }&gt;): void;

Unsubscribes from device name changes.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | string                                   | Yes   | Event type. The value **'deviceNameChange'** indicates a device name change event.|
| callback | Callback&lt;{&nbsp;deviceName:&nbsp;string}&gt; | No   | Callback for the device name change.                |

**Example**

  ```js
  try {
    dmInstance.off('deviceNameChange', (data) => {
      console.info('deviceNameChange' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceNameChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('discoverFailure')

on(type: 'discoverFailure', callback: Callback&lt;{ reason: number }&gt;): void;

Subscribes to device discovery failures.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | string                                   | Yes   | Event type. The value **'discoverFailure'** indicates an event reported when device discovery fails.|
| callback | Callback&lt;{&nbsp;reason:&nbsp;number&nbsp;}&gt; | Yes   | Callback invoked to return a device discovery failure.                |

**Example**

  ```js
  try {
    dmInstance.on('discoverFailure', (data) => {
        console.info("discoverFailure on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverFailure errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('discoverFailure')

off(type: 'discoverFailure', callback?: Callback&lt;{ reason: number }&gt;): void;

Unsubscribes from device discovery failures.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                                    | Mandatory  | Description               |
| -------- | ---------------------------------------- | ---- | ----------------- |
| type     | string                                   | Yes   | Event type. The value **'discoverFailure'** indicates an event reported when device discovery fails.    |
| callback | Callback&lt;{&nbsp;reason:&nbsp;number&nbsp;}&gt; | No   | Callback for the device discovery failure.|

**Example**

  ```js
  try {
    dmInstance.off('discoverFailure', (data) => {
      console.info('discoverFailure' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverFailure errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('serviceDie')

on(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void;

Subscribes to dead events of the **DeviceManager** service.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                   | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Event type. The value **'serviceDie'** indicates an event reported when the **DeviceManager** service is terminated unexpectedly.|
| callback | Callback&lt;{}&gt; | No   | Callback invoked when a dead event of the **DeviceManager** service occurs.                      |

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

off(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void;

Unsubscribes from dead events of the **DeviceManager** service.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Parameters**

| Name      | Type                   | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Event type. The value **'serviceDie'** indicates an event reported when the **DeviceManager** service is terminated unexpectedly.|
| callback | Callback&lt;{}&gt; | No   | Callback for the dead event of the **DeviceManager** service.                    |

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

