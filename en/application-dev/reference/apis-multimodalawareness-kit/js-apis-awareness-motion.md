# @ohos.multimodalAwareness.motion (Motion Awareness)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @zou_ye-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

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
| UNKNOWN_STATUS      | 0    | Unknown status.|
| LEFT_HAND_OPERATED  | 1    | Left hand in use.|
| RIGHT_HAND_OPERATED | 2    | Right hand in use.|

## HoldingHandStatus<sup>20+</sup>

Represents the holding hand status. The holding hand status is returned if listening for holding hand status changes is enabled.

**System capability**: SystemCapability.MultimodalAwareness.Motion

| Name           | Value  | Description          |
| --------------- | ---- | -------------- |
| NOT_HELD        | 0    | No holding.  |
| LEFT_HAND_HELD  | 1    | Holding with the left hand.|
| RIGHT_HAND_HELD | 2    | Holding with the right hand.|
| BOTH_HANDS_HELD | 3    | Holding with both hands.|
| UNKNOWN_STATUS  | 16   | Unknown status.  |

## motion.on('operatingHandChanged')

on(type: 'operatingHandChanged', callback: Callback&lt;OperatingHandStatus&gt;): void

Subscribes to operating hand change events.

If the device does not support the age group detection function, error code 801 is returned.

**Required permissions**: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE

**System capability**: SystemCapability.MultimodalAwareness.Motion

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. This parameter has a fixed value of **operatingHandChanged**.|
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | Yes  | Callback used to return the result.                                  |

**Error codes**

For details about the error codes, see [Motion Awareness Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to subscribe operatingHandChanged event forbidden by permission: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500002 | Subscription failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callback:Callback<motion.OperatingHandStatus> = (data:motion.OperatingHandStatus) => {
    console.info('callback succeeded' + data);
};

try {
    motion.on('operatingHandChanged', callback);  
    console.info("on succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed on and err code is " + error.code);
}
```

## motion.off('operatingHandChanged')

off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void

Unsubscribes from operating hand change events.

**Required permissions**: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE

**System capability**: SystemCapability.MultimodalAwareness.Motion

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. This parameter has a fixed value of **operatingHandChanged**.|
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | No  | Callback used to return the result.                                  |

**Error codes**

For details about the error codes, see [Motion Awareness Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to unsubscribe operatingHandChanged event forbidden by permission: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE. |
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

getRecentOperatingHandStatus(): OperatingHandStatus

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
| 201      | Permission denied. An attempt was made to get the recent operating hand status forbidden by permission: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
    console.info('get succeeded' + data);
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed get and err code is " + error.code);
}
```

## motion.on('holdingHandChanged') <sup>20+</sup>

on(type: 'holdingHandChanged', callback: Callback&lt;HoldingHandStatus&gt;): void

Enables listening for holding hand status changes.

**Required permissions**: ohos.permission.DETECT_GESTURE

**System capability**: SystemCapability.MultimodalAwareness.Motion

**Parameter**

| Name  | Type                                             | Mandatory| Description                                  |
| -------- | ------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                            | Yes  | Event type. The value **holdingHandChanged** indicates the holding hand status change event.|
| callback | Callback&lt;[HoldingHandStatus](#holdinghandstatus20)&gt; | Yes  | Callback used to return the holding hand status.        |

**Error Code**

For details about the error codes, see [Motion Awareness Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to subscribe holdingHandChanged event forbidden by permission: ohos.permission.DETECT_GESTURE. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500002 | Subscription failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';

let callback:Callback<motion.HoldingHandStatus> = (data:motion.HoldingHandStatus) => {
  console.info('callback succeeded: ' + data);
};

try {
  motion.on('holdingHandChanged', callback);
  console.info('on succeeded');
} catch (err) {
  let error = err as BusinessError;
  console.error('Failed on; err code = ' + error.code);
}
```

## motion.off('holdingHandChanged') <sup>20+</sup>

off(type: 'holdingHandChanged', callback?: Callback&lt;HoldingHandStatus&gt;): void

Disables listening for holding hand status changes.

**Required permissions**: ohos.permission.DETECT_GESTURE

**System capability**: SystemCapability.MultimodalAwareness.Motion

**Parameter**

| Name  | Type                                             | Mandatory| Description                                          |
| -------- | ------------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                            | Yes  | Event type. The value **holdingHandChanged** indicates the holding hand status change event.        |
| callback | Callback&lt;[HoldingHandStatus](#holdinghandstatus20)&gt; | No  | Callback to unregister. If this parameter is not passed, all callbacks for the holding hand status change event will be unregistered.|

**Error Code**

For details about the error codes, see [Motion Awareness Error Codes](errorcode-motion.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to unsubscribe holdingHandChanged event forbidden by permission: ohos.permission.DETECT_GESTURE. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500003 | Unsubscription failed. Possible causes: 1. Callback failure; 2. N-API invocation exception, invalid N-API status; 3. IPC request exception. |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';

try {
  motion.off('holdingHandChanged'); // Unregister all callbacks for the holding hand status change event.
  console.info('off succeeded');
} catch (err) {
  let error = err as BusinessError;
  console.error('Failed off; err code = ' + error.code);
}
```
