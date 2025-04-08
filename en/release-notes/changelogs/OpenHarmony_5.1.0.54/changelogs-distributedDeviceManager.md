# Distributed Device Management Changelog

## cl.distributedDeviceManager.1 Error Code Changes of Distributed Device Management APIs

**Access Level**

Public API

**Reason for Change**

- The possible causes of error code 401 are as follows: 1. Mandatory parameters not specified. 2. Incorrect parameter type. 3. Parameter verification failed.

  The** getAvailableDeviceListSync** and **stopDiscovering** APIs do not have any input parameters. Therefore, error code 401 needs to be deleted.

- Error code 11600104 may occur if the previous discovery has not ended.

  Since **stopDiscovering** API will never trigger this error, error code 11600104 needs to be deleted.

- Error code 201 is possibly due to permission verification failure.

  The **releaseDeviceManager** and **createDeviceManager** APIs are used in pairs, and their permission verification logic is consistent. Since **createDeviceManager** does not involve permission verification, error code 201 needs to be deleted.

**Change Impact**

This change does not require application adaptation.

- Before change: The @ohos.distributedDeviceManager module includes error code 201 in the **releaseDeviceManager** function declaration.

  **After change**: The @ohos.distributedDeviceManager module does not include error code 201 in the **releaseDeviceManager** function declaration.

- Before change: The @ohos.distributedDeviceManager module includes the error code 401 in the **getAvailableDeviceListSync** function declaration.

  After change: The @ohos.distributedDeviceManager module does not include error code 401 in the **getAvailableDeviceListSync** function declaration.

- Before change: The @ohos.distributedDeviceManager module includes the error codes 401 and 11600104 in the **stopDiscovering** function declaration.

  After change: The @ohos.distributedDeviceManager module does not include error codes 401 and 11600104 in the **stopDiscovering** function declaration.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.1.0.54

**Key API/Component Changes**

This change involves the update of the comments of the following modules:

| Module                               | Class               | API Declaration                                                  |Change Description   |
| ------------------------------------ | ------------------- | ------------------------------------------------------------ | -------------- |
| @ohos.distributedDeviceManager       | function             | **function** releaseDeviceManager(deviceManager: DeviceManager): void; | Deleted error code 201.|
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;; | Deleted error code 401.|
| @ohos.distributedDeviceManager       | DeviceManager        | **function** stopDiscovering(): void; | Deleted error codes 401 and 11600104.  |

**Adaptation Guide**

No adaptation is required.
