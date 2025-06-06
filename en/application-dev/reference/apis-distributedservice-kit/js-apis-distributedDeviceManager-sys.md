# @ohos.distributedDeviceManager (Device Management) (System API)

The **distributedDeviceManager** module provides APIs for distributed device management.

Applications can call the APIs to:

- Subscribe to or unsubscribe from device state changes.
- Discover devices nearby.
- Authenticate or deauthenticate a device.
- Query the trusted device list.
- Query local device information, including the device name, type, and ID.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version. This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.distributedDeviceManager](js-apis-distributedDeviceManager.md).

## Modules to Import

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
```

## StrategyForHeartbeat<sup>15+</sup>

Defines the heartbeat broadcast policy.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| TEMP_STOP_HEARTBEAT      | 100    | Stops the heartbeat broadcast temporarily, and resumes it upon timeout expiration.            |
| START_HEARTBEAT          | 101    | Starts heartbeat broadcast.                              |

## DeviceProfileInfoFilterOptions<sup>15+</sup>

Defines device profile information filter options.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

| Name        | Type | Read-Only| Optional            |  Description   |
| ----------- | ---- | -- | --- |--------------- | 
| isCloud      | boolean    |  No| No          | Whether to obtain the device list from the cloud in real time.<br>- **false**: Obtain the device list from the device.<br>- **true**: Obtain the device list from the cloud.      |
| deviceIdList  | Array&lt;string&gt;  | No| Yes   | Device ID. The device ID is usually the UDID of the device. If the device does not have a UDID, the MAC address or SN of the device is used as the device ID. This parameter is left unspecified by default.      |


## ServiceProfileInfo<sup>15+</sup>

Defines the service profile information. It is populated based on the data returned from the cloud.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

| Name          | Type | Read Only| Optional             |  Description   |
| -------------- | ---- | --------| ------- | --------|
| deviceId       | string  | No| No  |  Device ID.         |
| serviceId       | string  | No|No  | Service ID.          |
| serviceType     | string   | No| No  | Service type.          |
| data       | string  | No| Yes  |  Service data. The value is a string of up to 1000 characters. This parameter is left unspecified by default.         |

## DeviceProfileInfo<sup>15+</sup>

Defines the device profile information.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

| Name          | Type | Read-Only  |Optional             |  Description   |
| -------------- | ---- | ---| --------------- | --------|
|  deviceId      | string  |  No   | No  |  Device ID.         |
|  deviceSn      | string  |  No   | No  |  Device SN.     |
|  mac           | string  |  No   | No  |  MAC address.        |
|  model         | string  |  No   | No  |  Device model.        |
|  deviceType    | string  |  No   | No  |  Device type.        |
|  manufacturer  | string  |  No   | No  |  Manufacturer.          |
|  deviceName    | string  |  No   | No  |  Device name.        |
|  productId     | string  |  No   | No  |  Product ID.   |
|  subProductId  | string  |  No   | Yes  |  Sub-product ID. This parameter is left unspecified by default.        |
|  sdkVersion    | string  |  No   | No  |  SDK version.         |
|  bleMac        | string  |  No   | No  |  Bluetooth BLE MAC address. |
|  brMac         | string  |  No   | No  |  Bluetooth BR MAC address. |
|  sleMac        | string  |  No   | No  |  Starflash MAC address.|
|  firmwareVersion | string |  No  | No |  Firmware version.         |
|  hardwareVersion | string |  No  | No |  Hardware version.         |
|  softwareVersion | string |  No | No |  Software version.         |
|  protocolType    | number |  No  | No |  Protocol type.         |
|  setupType       | number |  No  | No |  Device type.         |
|  wiseDeviceId    | string |  No  | No |  Registered device ID.       |
|  wiseUserId      | string |  No  | No |  Registered user ID.       |
|  registerTime    | string |  No  | No |  Registration time.         |
|  modifyTime      | string |  No  | No |  Modification time.         |
|  shareTime       | string |  No  | No |  Share time.         |
|  isLocalDevice   | boolean | No  | No|  Whether the device is a local device.<br>- **false**: non-local device.<br>- **true**: local device.    |
|  services        | Array&lt;[ServiceProfileInfo](#serviceprofileinfo15)&gt; | No | Yes | Service list. This parameter is left unspecified by default.|
|  productName<sup>18+</sup>     | string  | No  | Yes|  Product name. This parameter is left unspecified by default.   |
|  internalModel<sup>18+</sup>   | string  | No  | Yes|  Internal product model. This parameter is left unspecified by default.|


## DeviceIconInfoFilterOptions<sup>18+</sup> 

Defines the device icon information filter options.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

| Name          | Type | Read-Only| Optional             |  Description   |
| -------------- | ---- | -------| -------- | --------|
|  productId      | string  | No| No  |  Product ID.         |
|  subProductId   | string  | No| Yes  |  Sub-product ID. This parameter is left unspecified by default.     |
|  imageType      | string  | No| No  |  Image type. This parameter has a fixed value of **ID**, indicating the product's physical image.|
|  specName       | string  | No| No  |  Image specification name. Value:<br>- **lg**: large image (size: 1016064 pixels)<br>- **sm**: small image (size: 65536 pixels)        |
|  internalModel  | string  | No| Yes  |  Internal product model. This parameter is left unspecified by default.       |

## DeviceIconInfo<sup>18+</sup>

Defines the device icon information.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

| Name          | Type | Read-Only |Optional             |  Description   |
| -------------- | ---- | ------| --------- | --------|
|  productId      | string  | No| No  |  Product ID.         |
|  subProductId   | string  | No| Yes  |  Sub-product ID. This parameter is left unspecified by default.    |
|  imageType      | string  | No| No  |  Image type. This parameter has a fixed value of **ID**, indicating the product's physical image.       |
|  specName       | string  | No| No  |  Image specification name. Value:<br>- **lg**: large image (size: 1016 x 64 pixels)<br>- **sm**: small image (size: 655 x 36 pixels)        |
|  url            | string  | No| No  |  URL.         |
|  icon           | ArrayBuffer | No| No| Icon.        |
|  internalModel  | string  | No| Yes  |  Internal product model. This parameter is left unspecified by default.        |

## NetworkIdQueryFilter<sup>18+</sup>

Defines the network ID filter options.

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

| Name          | Type | Read-Only| Optional             |  Description   |
| -------------- | ---- | ------ | --------- | --------|
|  wiseDeviceId       | string  | No| No  |  Registered device ID.         |
|  onlineStatus    | number  | No| No  |  Device online status.<br>- **0**: The device is offline.<br>- **1**: The device is online.     |

## DeviceManager

Provides APIs to obtain information about trusted devices and local devices. Before calling any API in **DeviceManager**, you must use **createDeviceManager** to create a **DeviceManager** instance, for example, **dmInstance**.

### replyUiAction

replyUiAction(action: number, actionResult: string): void

Replies to the user's UI operation. This API can be used only by the PIN HAP of the **deviceManager**.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | action        | number          | Yes   | User operation.<br>- **0**: Grant the permission.<br>- **1**. Remove the permission.<br>- **2**: Time out the user operation in the permission request dialog.<br>- **3**: Cancel the display of the PIN box.<br>- **4**: Cancel the display of the PIN input box.<br>- **5**: Confirm the input in the PIN input box.    |
  | actionResult        | string          | Yes   | User operation result. The value is a string of 1 to 255 characters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified actionResult is greater than 255. |

**Example**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

 try {
    /*
      action = 0 - Grant the permission.
      action = 1 - Revoke the permission.
      action = 2 - Time out the user operation in the permission request dialog.
      action = 3 - Cancel the display of the PIN box.
      action = 4 - Cancel the display of the PIN input box.
      action = 5 - Confirm the input in the PIN input box.
    */
    let operation = 0;
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.replyUiAction(operation, 'extra');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyUiAction errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('replyResult')

on(type: 'replyResult', callback: Callback&lt;{ param: string;}&gt;): void

Subscribes to the reply to the UI operation result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name     | Type                            | Mandatory| Description                           |
  | -------- | ------------------------------------ | ---- | ------------------------------ |
  | type     | string                                | Yes | Event type, which has a fixed value of **replyResult**.|
  | callback | Callback&lt;{&nbsp;param:&nbsp;string;}&gt; | Yes | Callback invoked to return the UI status change.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255. |

**Example**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    param: string = '';
  }

  interface TmpStr {
    verifyFailed: boolean;
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.on('replyResult', (data: Data) => {
      console.info('replyResult executed, dialog closed' + JSON.stringify(data));
      let tmpStr: TmpStr = JSON.parse(data.param);
      let isShow = tmpStr.verifyFailed;
      console.info('replyResult executed, dialog closed' + isShow);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyResult errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('replyResult')

off(type: 'replyResult', callback?: Callback&lt;{ param: string;}&gt;): void

Unsubscribes from the reply to the UI operation result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name     | Type                             | Mandatory| Description                           |
  | -------- | ------------------------------------- | ---- | ------------------------------ |
  | type     | string                                | Yes  | Event type, which has a fixed value of **replyResult**.|
  | callback | Callback&lt;{&nbsp;param:&nbsp;string;}&gt; | No  | Callback to unregister.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255. |

**Example**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.off('replyResult');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyResult errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### setHeartbeatPolicy<sup>15+</sup>

setHeartbeatPolicy(policy: StrategyForHeartbeat, delayTime: number): void

Sets the heartbeat broadcast policy.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | policy        |  &nbsp;[StrategyForHeartbeat](#strategyforheartbeat15)&nbsp;         | Yes   | Heartbeat broadcast policy.      |
  | delayTime     | number          | Yes   | Duration for temporarily disabling heartbeat broadcast. The value ranges from 1000 to 15000, in milliseconds.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 11600102 | Failed to obtain service.                                 |

**Example**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let policy = distributedDeviceManager.StrategyForHeartbeat.TEMP_STOP_HEARTBEAT;
    let delayTime = 1000;
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.setHeartbeatPolicy(policy, delayTime);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('setHeartbeatPolicy errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceProfileInfoList<sup>15+</sup>

getDeviceProfileInfoList(filterOptions: DeviceProfileInfoFilterOptions): Promise&lt;Array&lt;DeviceProfileInfo&gt;&gt;

Obtains the list of devices under the same account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | filterOptions        |  &nbsp;[DeviceProfileInfoFilterOptions](#deviceprofileinfofilteroptions15)&nbsp;         | Yes   | Filter options.    |

**Returns**

  | Type                                                      | Description                              |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Promise&lt;Array&lt;[DeviceProfileInfo](#deviceprofileinfo15)&gt;&gt; | Promise used to return the device list.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 500. |
| 11600102 | Failed to obtain service.                                 |
| 11600106 | Get data from cloud fail. |
| 11600107 | A login account is required.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.getDeviceProfileInfoList({"isCloud": false}).then((data: Array<distributedDeviceManager.DeviceProfileInfo>) => {
      console.info('getDeviceProfileInfoList' + JSON.stringify(data));
    }).catch((e: BusinessError) => {
      console.error('getDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### putDeviceProfileInfoList<sup>18+</sup>

putDeviceProfileInfoList(deviceProfileInfoList: Array&lt;DeviceProfileInfo&gt;): Promise&lt;number&gt;

Updates the device list. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceProfileInfoList       |  Array&lt;[DeviceProfileInfo](#deviceprofileinfo15)&gt;        |  Yes  |  Device list.   |

**Returns**

  | Type                                                      | Description                              |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | Operation result. The value **0** indicates that the operation is successful. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 500. |
| 11600102 | Failed to obtain service.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceProfileInfoList:Array<distributedDeviceManager.DeviceProfileInfo> = [];
    dmInstance.putDeviceProfileInfoList(deviceProfileInfoList).then((data:number) => {
      console.info('put device profile info:' + JSON.stringify(data));
    }).catch((e: BusinessError) => {
      console.error('putDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('putDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceIconInfo<sup>18+</sup>

getDeviceIconInfo(filterOptions: DeviceIconInfoFilterOptions): Promise&lt;DeviceIconInfo&gt;

Obtains the device icon. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  |  filterOptions       | [DeviceIconInfoFilterOptions](#deviceiconinfofilteroptions18)         | Yes   |  Filter options.   |

**Returns**

  | Type                                                      | Description                              |
  | ---------------------------------------------------------- | ---------------------------------- |
  |  Promise&lt;[DeviceIconInfo](#deviceiconinfo18)&gt; | Promise used to return the device icon information.                                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600106 | Get data from cloud fail. |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let productIds:Array<string> = ['M0D2', 'M0D3', 'M0D5', 'M0AB', 'M0BD', 'M0E9', 'M0BC', 'M0EA'];
    let options:distributedDeviceManager.DeviceIconInfoFilterOptions = {
      productId: 'P14U',
      imageType: 'ID',
      specName: 'lg',
    };
    if (productIds.indexOf(options.productId) != -1) {
      options.internalModel = '';
    } else {
      options.subProductId = '';
    }
    dmInstance.getDeviceIconInfo(options).then((data: distributedDeviceManager.DeviceIconInfo) => {
      console.info('getDeviceIconInfo' + JSON.stringify(data));
    }).catch((e : BusinessError) => {
      console.error('getDeviceIconInfo errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceIconInfo errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getLocalDisplayDeviceName<sup>18+</sup>

getLocalDisplayDeviceName(maxNameLength: number): Promise&lt;string&gt;

Obtains the local device's display name with the specified length. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  |  maxNameLength       |  number        |  Yes | Length of the local device's display name, in bytes. The value range is [18, 100]. If the value is **0**, the length is not limited.    |

**Returns**

  | Type                                                      | Description                              |
  | ---------------------------------------------------------- | ---------------------------------- |
  | string | Maximum number of bytes in the local device's display name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let maxNameLength:number = 21;
    dmInstance.getLocalDisplayDeviceName(maxNameLength).then((data:string)=>{
      console.info('getLocalDisplayDeviceName name:' + JSON.stringify(data));
    }).catch((e: BusinessError)=>{
      console.error('getLocalDisplayDeviceName errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getLocalDisplayDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### setLocalDeviceName<sup>18+</sup>

setLocalDeviceName(deviceName: string): Promise&lt;number&gt;

Sets the local device name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceName       | string         |  Yes  | Device name to set. The value is a string of 1 to 255 characters.    |

**Returns**

  | Type                                                      | Description                              |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | Operation result. The value **0** indicates that the operation is successful.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600106 | Failed to get data from the cloud. |
| 11600107 | A login account is required.  |
| 11600108 | The device name contains non-compliant content. |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceName:string = 'xxx';
    dmInstance.setLocalDeviceName(deviceName).then((data:number)=>{
      console.info('setLocalDeviceName name:' + JSON.stringify(data));
    }).catch((e: BusinessError)=>{
      console.error('setLocalDeviceName errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('setLocalDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### setRemoteDeviceName<sup>18+</sup>

setRemoteDeviceName(deviceId: string, deviceName: string): Promise&lt;number&gt;

Sets the remote device name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceId       | string         | Yes   | UDID of the  remote device. If the device does not have a UDID, the MAC address or SN of the device is used as the device ID. The SN is used preferentially.    |
  |  deviceName       | string         | Yes   | Device name to set. The value is a string of 1 to 255 characters.   |

**Returns**

  | Type                                                      | Description                              |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | Operation result. The value **0** indicates that the operation is successful.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600106 | Failed to get data from the cloud. |
| 11600107 | A login account is required.  |
| 11600108 | The device name contains non-compliant content. |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceId:string = 'xxx';
    let deviceName:string = 'xxx';
    dmInstance.setRemoteDeviceName(deviceId, deviceName).then((data:number)=>{
      console.info('setRemoteDeviceName name:' + JSON.stringify(data));
    }).catch((e: BusinessError)=>{
      console.error('setRemoteDeviceName errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('setRemoteDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### restoreLocalDeivceName<sup>18+</sup>

restoreLocalDeivceName(): void

Restores the local device name by resetting the network settings.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600102 | Failed to obtain the service.                                 |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.restoreLocalDeivceName();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('restoreLocalDeivceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceNetworkIdList<sup>18+</sup>

getDeviceNetworkIdList(filterOptions: NetworkIdQueryFilter): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of network devices according to the specified filter options.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  |   filterOptions      | [NetworkIdQueryFilter](#networkidqueryfilter18)         |  Yes  |   Filter options.  |

**Returns**

  | Type                                                      | Description                              |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Promise&lt;Array&lt;string&gt;&gt; |  Promise used to return the device list.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](errorcode-device-manager.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600107 | A login account is required.  |

**Example**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let queryFiler: distributedDeviceManager.NetworkIdQueryFilter = {
      wiseDeviceId: '',
      onlineStatus: 1,
    }
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.getDeviceNetworkIdList(queryFiler).then((data:Array<string>) => {
      console.info('getDeviceNetworkIdList name:' + JSON.stringify(data));
    }).catch((e: BusinessError) => {
      console.error('getDeviceNetworkIdList errCode:' + e.code + ',errMessage:' + e.message);
    })
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceNetworkIdList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```
