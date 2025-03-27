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

## DeviceManager

Provides APIs to obtain information about trusted devices and local devices. Before calling any API in **DeviceManager**, you must use **createDeviceManager** to create a **DeviceManager** instance, for example, **dmInstance**.

### replyUiAction

replyUiAction(action: number, actionResult: string): void;

Replies to the user's UI operation. This API can be used only by the PIN HAP of the **deviceManager**.

**Required permissions**: ohos.permission.ACCESS_SERVICE_DM

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**System API**: This is a system API.

**Parameters**

  | Name      | Type           | Mandatory | Description               |
  | ------------- | --------------- | ---- | ------------------- |
  | action        | number          | Yes   | User operation.<br>- 0: Grant authorization.<br>- 1. Cancel authorization.<br>- 2: Wait until the authorization dialog times out.<br>- 3: Cancel the display of the PIN box.<br>- 4: Cancel the display of the PIN input box.<br>- 5: Confirm the input in the PIN input box.    |
  | actionResult        | string          | Yes   | User operation result. The value contains a maximum of 256 characters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified actionResult is greater than 255. |

**Example**

For details about how to initialize `dmInstance` in the example, see [Creating a DeviceManager Instance](js-apis-distributedDeviceManager.md#distributeddevicemanagercreatedevicemanager).
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

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
    dmInstance.replyUiAction(operation, 'extra');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyUiAction errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('replyResult')

on(type: 'replyResult', callback: Callback&lt;{ param: string;}&gt;): void;

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

For details about how to initialize `dmInstance` in the example, see [Creating a DeviceManager Instance](js-apis-distributedDeviceManager.md#distributeddevicemanagercreatedevicemanager).
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    param: string = '';
  }

  interface TmpStr {
    verifyFailed: boolean;
  }

  try {
    dmInstance.on('replyResult', (data: Data) => {
      console.log('replyResult executed, dialog closed' + JSON.stringify(data));
      let tmpStr: TmpStr = JSON.parse(data.param);
      let isShow = tmpStr.verifyFailed;
      console.log('replyResult executed, dialog closed' + isShow);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyResult errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('replyResult')

off(type: 'replyResult', callback?: Callback&lt;{ param: string;}&gt;): void;

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

For details about how to initialize `dmInstance` in the example, see [Creating a DeviceManager Instance](js-apis-distributedDeviceManager.md#distributeddevicemanagercreatedevicemanager).
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    dmInstance.off('replyResult');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyResult errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### setHeartbeatPolicy<sup>15+</sup>

setHeartbeatPolicy(policy: StrategyForHeartbeat, delayTime: number): void;

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

For details about how to initialize `dmInstance` in the example, see [Creating a DeviceManager Instance](js-apis-distributedDeviceManager.md#distributeddevicemanagercreatedevicemanager).
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let policy = distributedDeviceManager.StrategyForHeartbeat.TEMP_STOP_HEARTBEAT;
    let delayTime = 1000;
    dmInstance.setHeartbeatPolicy(policy, delayTime);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('setHeartbeatPolicy errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```
