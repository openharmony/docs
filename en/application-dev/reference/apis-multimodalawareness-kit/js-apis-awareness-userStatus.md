# @ohos.multimodalawareness.userStatus (User Status Awareness)

The UserStatus module, designed for user state awareness, empowers the system to perceive specific conditions of users, such as determining their age group.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { userStatus } from '@kit.MultimodalAwarenessKit';
```

## UserAgeGroup

Enumerates the user age groups, for example, child or adult.

**System capability**: SystemCapability.MultimodalAwareness.UserStatus

| Name               | Value | Description                  |
| ------------------- | ---- | ---------------------- |
| OTHERS  | 0    | Adult.|
| CHILD  | 1    | Child.|

## UserClassification

Defines the user age group detection result.

**System capability**: SystemCapability.MultimodalAwareness.UserStatus

| Name               | Type  |Readable|Writable| Description                  |
| ------------------- | ---- |----|----| ---------------------- |
| ageGroup  | [UserAgeGroup](#useragegroup)   |Yes|No| User age group, for example, child or adult.|
| confidence  | float    |Yes|No| Confidence of the detection result. The value is a floating point number ranging from 0 to 1. A larger value indicates a higher confidence.|


## userStatus.on('userAgeGroupDetected')

 on(type: 'userAgeGroupDetected', callback: Callback&lt;userclassification&gt;): void;

Enables the age group detection function.

When the function is enabled, the application can recommend content based on the age group detection result.

**System capability**: SystemCapability.MultimodalAwareness.UserStatus

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- |------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. The value **userAgeGroupDetected** indicates the event of enabling age group detection.|
| callback | Callback&lt;[UserClassification](#userclassification)&gt; | Yes  | Callback used to return the detection result.|

**Error codes**

For details about the error codes, see [User Status Awareness Error Codes](errorcode-userStatus.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33900001 | Service exception. Possible causes: <br>1. System error, such as a null pointer and container-related exception. <br>2. Node-API invocation exception, such as invalid Node-API status.|
| 33900002 | Subscription failed. Possible causes: <br>1. Callback registration failed. <br>2. Failed to bind the native object to the JS wrapper. <br>3. Node-API invocation exception, such as invalid Node-API status. <br>4. IPC request exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    userStatus.on('userAgeGroupDetected', (data: userStatus.UserClassification) => {
        console.info('callback success, ageGroup:' + data.ageGroup + ", confidence:" + data.confidence);
    });
    console.info("on succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed on and err code is " + error.code);
}
```



## userStatus.off('userAgeGroupDetected')

off(type: 'userAgeGroupDetected', callback?: Callback&lt;UserClassification&gt;): void;

Disables the age group detection function.

**System capability**: SystemCapability.MultimodalAwareness.UserStatus

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. The value **userAgeGroupDetected** indicates the event of enabling age group detection.|
| callback | Callback&lt;[UserClassification](#userclassification)&gt; | No  | Callback used to return the detection result.|

**Error codes**

For details about the error codes, see [User Status Awareness Error Codes](errorcode-userStatus.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33900001 | Service exception. Possible causes: <br>1. System error, such as a null pointer and container-related exception. <br>2. Node-API invocation exception, such as invalid Node-API status. |
| 33900003 | Unsubscription failed. Possible causes: <br>1. Callback failure. <br>2. Node-API invocation exception, such as invalid Node-API status. <br>3. IPC request exception.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    userStatus.off('userAgeGroupDetected');
    console.info("off succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed off and err code is " + error.code);
}
```
