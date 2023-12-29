# @ohos.distributedHardware.hardwareManager (Distributed Hardware Management)

The **distributedHardwareManager** module provides the capability of controlling distributed hardware, including pausing, resuming, and stopping the distributed hardware service on the controlled device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import hardwareManager from '@ohos.distributedHardware.hardwareManager';
```

## HardwareDescriptor

Represents the distributed hardware information.

**System capability**: SystemCapability.DistributedHardware.DistributedHardwareFWK

| Name        | Type                                               | Mandatory| Description                                  |
| ------------ | --------------------------------------------------- | ---- | -------------------------------------- |
| type         | [DistributedHardwareType](#distributedhardwaretype) | Yes  | Type of the distributed hardware.                      |
| srcNetworkId | string                                              | No  | Source device. If this parameter is not specified, it indicates all source devices.|

## DistributedHardwareType

Enumerates the types of the distributed hardware.

**System capability**: SystemCapability.DistributedHardware.DistributedHardwareFWK

| Name         | Value  | Description                        |
| :------------ | ---- | ---------------------------- |
| ALL           | 0    | All distributed applications.        |
| CAMERA        | 1    | Distributed camera.            |
| SCREEN        | 8    | Distributed screen.            |
| MODEM_MIC     | 256  | Distributed microphone for mobile calls.|
| MODEM_SPEAKER | 512  | Distributed speaker for mobile calls.|
| MIC           | 1024 | Distributed microphone.          |
| SPEAKER       | 2048 | Distributed speaker.          |

## DistributedHardwareErrorCode

Enumerates the error codes used for the distributed hardware.

**System capability**: SystemCapability.DistributedHardware.DistributedHardwareFWK

| Name                                     | Value      | Description                  |
| ----------------------------------------- | -------- | ---------------------- |
| ERR_CODE_DISTRIBUTED_HARDWARE_NOT_STARTED | 24200101 | The distributed hardware is not started.|
| ERR_CODE_DEVICE_NOT_CONNECTED             | 24200102 | The source device is not connected.  |

## hardwareManager.pauseDistributedHardware

pauseDistributedHardware(description: HardwareDescriptor, callback: AsyncCallback<void>): void;

Pauses the distributed hardware service on the controlled device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**System capability**: SystemCapability.DistributedHardware.DistributedHardwareFWK

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| description | [HardwareDescriptor](#hardwaredescriptor) | Yes   | Hardware information.|
| callback  | AsyncCallback&lt;void&gt;               | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. If the operation fails, **err** is an error object.|

**Example**

  ```ts
  import hardwareManager from '@ohos.distributedHardware.hardwareManager'
  import { BusinessError } from '@ohos.base';
  
  try {
    let description: hardwareManager.HardwareDescriptor = {
      type: hardwareManager.DistributedHardwareType.CAMERA
    };
    hardwareManager.pauseDistributedHardware(description, (error:BusinessError) => {
      if (error.code) {
        console.error('pauseDistributedHardware failed, cause: ' + JSON.stringify(error));
      }
      console.log('pause distributed hardware successfully');
    })
  } catch (error) {
    console.error('pause distributed hardware failed: ' + JSON.stringify(error))
  }
  ```
## hardwareManager.pauseDistributedHardware

pauseDistributedHardware(description: HardwareDescriptor): Promise&lt;void&gt;

Pauses the distributed hardware service on the controlled device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**System capability**: SystemCapability.DistributedHardware.DistributedHardwareFWK

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| description | [HardwareDescriptor](#hardwaredescriptor) | Yes  | Hardware information.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  import hardwareManager from '@ohos.distributedHardware.hardwareManager'
  import { BusinessError } from '@ohos.base';
  
  try {
    let description: hardwareManager.HardwareDescriptor = {
      type: hardwareManager.DistributedHardwareType.CAMERA
    };
    hardwareManager.pauseDistributedHardware(description).then(()=>{
      console.log('pause distributed hardware successfully');
    }).catch((error: BusinessError) => {
      console.error('pause distributed hardware failed, cause:'+error);
    })
  } catch (error) {
    console.error('pause distributed hardware failed: ' + JSON.stringify(error))
  }
  ```

## hardwareManager.resumeDistributedHardware

resumeDistributedHardware(description: HardwareDescriptor, callback: AsyncCallback<void>): void;

Resumes the distributed hardware service on the controlled device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**System capability**: SystemCapability.DistributedHardware.DistributedHardwareFWK

**Parameters**

| Name     | Type                                     | Mandatory| Description                                                        |
| ----------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| description | [HardwareDescriptor](#hardwaredescriptor) | Yes  | Hardware information.                                              |
| callback    | AsyncCallback&lt;void&gt;                 | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. If the operation fails, **err** is an error object.|

**Example**

  ```ts
import hardwareManager from '@ohos.distributedHardware.hardwareManager'
import { BusinessError } from '@ohos.base';

try {
  let description: hardwareManager.HardwareDescriptor = {
    type: hardwareManager.DistributedHardwareType.CAMERA
  };
  hardwareManager.resumeDistributedHardware(description, (error:BusinessError) => {
    if (error.code) {
      console.error('resumeDistributedHardware failed, cause: ' + JSON.stringify(error));
    }
    console.log('resume distributed hardware successfully');
  })
} catch (error) {
  console.error('resume distributed hardware failed: ' + JSON.stringify(error));
}
  ```

## hardwareManager.resumeDistributedHardware

resumeDistributedHardware(description: HardwareDescriptor): Promise&lt;void&gt;

Resumes the distributed hardware service on the controlled device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**System capability**: SystemCapability.DistributedHardware.DistributedHardwareFWK

**Parameters**

| Name     | Type                                     | Mandatory| Description          |
| ----------- | ----------------------------------------- | ---- | -------------- |
| description | [HardwareDescriptor](#hardwaredescriptor) | Yes  | Hardware information.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
import hardwareManager from '@ohos.distributedHardware.hardwareManager'
import { BusinessError } from '@ohos.base';

try {
  let description: hardwareManager.HardwareDescriptor = {
    type: hardwareManager.DistributedHardwareType.CAMERA
  };
  hardwareManager.resumeDistributedHardware(description).then(()=>{
    console.log('resume distributed hardware successfully');
  }).catch((error: BusinessError) => {
    console.error('resume distributed hardware failed, cause:'+error);
  })
} catch (error) {
  console.error('resume distributed hardware failed: ' + JSON.stringify(error));
}
  ```

## hardwareManager.stopDistributedHardware

stopDistributedHardware(description: HardwareDescriptor, callback: AsyncCallback<void>): void;

Stops the distributed hardware service on the controlled device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**System capability**: SystemCapability.DistributedHardware.hardwareManager

**Parameters**

| Name     | Type                                     | Mandatory| Description                                                        |
| ----------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| description | [HardwareDescriptor](#hardwaredescriptor) | Yes  | Hardware information.                                              |
| callback    | AsyncCallback&lt;void&gt;                 | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. If the operation fails, **err** is an error object.|

**Example**

  ```ts
import hardwareManager from '@ohos.distributedHardware.hardwareManager'
import { BusinessError } from '@ohos.base';

try {
  let description: hardwareManager.HardwareDescriptor = {
    type: hardwareManager.DistributedHardwareType.CAMERA
  };
  hardwareManager.stopDistributedHardware(description, (error:BusinessError) => {
    if (error.code) {
      console.error('stopDistributedHardware failed, cause: ' + JSON.stringify(error));
    }
    console.log('stop distributed hardware successfully');
  })
} catch (error) {
  console.error('stop distributed hardware failed: ' + JSON.stringify(error));
}
  ```

## hardwareManager.stopDistributedHardware

stopDistributedHardware(description: HardwareDescriptor): Promise&lt;void&gt;

Stops the distributed hardware service on the controlled device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

**System capability**: SystemCapability.DistributedHardware.hardwareManager

**Parameters**

| Name     | Type                                     | Mandatory| Description          |
| ----------- | ----------------------------------------- | ---- | -------------- |
| description | [HardwareDescriptor](#hardwaredescriptor) | Yes  | Hardware information.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
import hardwareManager from '@ohos.distributedHardware.hardwareManager'
import { BusinessError } from '@ohos.base';

try {
  let description: hardwareManager.HardwareDescriptor = {
    type: hardwareManager.DistributedHardwareType.CAMERA
  };
  hardwareManager.stopDistributedHardware(description).then(()=>{
    console.log('stop distributed hardware successfully');
  }).catch((error: BusinessError) => {
    console.error('stop distributed hardware failed, cause:'+error);
  })
} catch (error) {
  console.error('stop distributed hardware failed: ' + JSON.stringify(error));
}
  ```
