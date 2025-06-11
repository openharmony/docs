# @ohos.multimodalawareness.motion (Motion Awareness)

The **motion** module provides the user motion awareness capabilities, including user gestures and actions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 15. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { motion } from '@kit.MultimodalAwarenessKit';
```

## OperatingHandStatus

Defines the status of the operating hand.

**System capability**: SystemCapability.MultimodalAwareness.Motion

| Name               | Value  | Description                  |
| ------------------- | ---- | ---------------------- |
| UNKNOWN_STATUS  | 0    | Unknown status.|
| LEFT_HAND_OPERATED  | 1    | Left hand in use.|
| RIGHT_HAND_OPERATED | 2    | Right hand in use.|




## motion.on('operatingHandChanged')

 on(type: 'operatingHandChanged', callback: Callback&lt;OperatingHandStatus&gt;): void;

Subscribes to operating hand change events.

**Required permissions**: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE

**System capability**: SystemCapability.MultimodalAwareness.Motion

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. Event type. This parameter has a fixed value of **operatingHandChanged**.|
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | Yes  | Callback used to return the result.                                  |

**Error codes**

For details about the error codes, see [Motion Awareness Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to subscribe operatingHandChanged event forbidden by permission: ohos.permission.ACTIVITY_MOTION. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500002 | Subscription failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

callback(data:motion.OperatingHandStatus) {
    console.info('callback success' + data);
}

try {
    motion.on('operatingHandChanged', this.callback);  
    console.info("on succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed on and err code is " + error.code);
}
```



## motion.off('operatingHandChanged')

off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void;

Unsubscribes from operating hand change events.

**Required permissions**: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE

**System capability**: SystemCapability.MultimodalAwareness.Motion

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. Event type. This parameter has a fixed value of **operatingHandChanged**.|
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | No  | Callback used to return the result.                                  |

**Error codes**

For details about the error codes, see [Motion Awareness Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to unsubscribe operatingHandChanged event forbidden by permission: ohos.permission.ACTIVITY_MOTION. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500003 | Unsubscription failed. Possible causes: 1. Callback failure; 2. N-API invocation exception, invalid N-API status; 3. IPC request exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    motion.off('operatingHandChanged');
    console.info("off succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed off and err code is " + error.code);
}
```



## motion.getRecentOperatingHandStatus()

getRecentOperatingHandStatus(): OperatingHandStatus;

Obtains the latest operating hand status.

**Required permissions**: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE

**System capability**: SystemCapability.MultimodalAwareness.Motion

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| [OperatingHandStatus](#operatinghandstatus) | Status of the operating hand.|

**Error codes**

For details about the error codes, see [Motion Awareness Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get the recent operating hand status forbidden by permission: ohos.permission.ACTIVITY_MOTION. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
    console.info('get success' + data);
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed get and err code is " + error.code);
}
```
