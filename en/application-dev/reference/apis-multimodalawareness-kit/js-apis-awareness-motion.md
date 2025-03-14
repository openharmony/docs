# @ohos.mulitmodalawareness.motion (Motion Sensing)

The **motion** module provides the capability of sensing user motions, including user gestures and actions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 15. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { motion } from '@kit.MultimodalAwarenessKit';
```

## OperatingHandStatus

Defines the status of the operating hand.

**System capability**: SystemCapability.MultimodalAwarness.Motion

| Name               | Value  | Description                  |
| ------------------- | ---- | ---------------------- |
| UNKNOWN_STATUS  | 0    | Unknown status.|
| LEFT_HAND_OPERATED  | 1    | Left hand in use.|
| RIGHT_HAND_OPERATED | 2    | Right hand in use.|




## motion.on('operatingHandChanged')

 on(type: 'operatingHandChanged', callback: Callback&lt;OperatingHandStatus&gt;): void;

Subscribes to operating hand change events.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.MultimodalAwarness.Motion

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. Event type. This parameter has a fixed value of **operatingHandChanged**.|
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | Yes  | Callback used to return the operating hand status.                                  |

**Error codes**

For details about the error codes, see [Motion Sensing Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported.Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception.                                           |
| 31500002 | Subscribe Failed.                                            |

**Example**

```ts
motion.on('operatingHandChanged', (data:motion.OperatingHandStatus) => {
    console.info('on success' + data);
})
```



## motion.off('operatingHandChanged')

off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void;

Unsubscribes from operating hand change events.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.MultimodalAwarness.Motion

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. Event type. This parameter has a fixed value of **operatingHandChanged**.|
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | No  | Callback used to return the operating hand status.                                  |

**Error codes**

For details about the error codes, see [Motion Sensing Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported.Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception.                                           |
| 31500003 | UnSubscribe Failed.                                          |

**Example**

```ts
motion.off('operatingHandChanged', (data:motion.OperatingHandStatus) => {
    console.info('off success' + data);
})
```



## motion.getRecentOperatingHandStatus()

getRecentOperatingHandStatus(): OperatingHandStatus;

Obtains the latest operating hand status.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.MultimodalAwarness.Motion

**Error codes**

For details about the error codes, see [Motion Sensing Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 801      | Capability not supported.Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception.                                           |

**Example**

```ts
let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
console.info('get success' + data);
```
