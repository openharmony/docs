# @ohos.multimodalawareness.motion (动作感知)

本模块，提供对用户行为、动作的感知能力，包括用户的手势、动作等。

> **说明：**
>
> 本模块首批接口从API version 15开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { motion } from '@kit.MultimodalAwarenessKit';
```

## OperatingHandStatus

触控操作手状态信息。

**系统能力**：SystemCapability.MultimodalAwareness.Motion

| 名称                | 值   | 说明                   |
| ------------------- | ---- | ---------------------- |
| UNKNOWN_STATUS  | 0    | 表示未识别。 |
| LEFT_HAND_OPERATED  | 1    | 表示触控操作手是左手。 |
| RIGHT_HAND_OPERATED | 2    | 表示触控操作手是右手。 |




## motion.on('operatingHandChanged')

 on(type: 'operatingHandChanged', callback: Callback&lt;OperatingHandStatus&gt;): void;

订阅触控操作手感知事件。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。type为“operatingHandChanged”，表示操作手状态变化。 |
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | 是   | 回调函数，返回操作手结果。                                   |

**错误码**：

以下错误码的详细介绍请参见[行为动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to subscribe operatingHandChanged event forbidden by permission: ohos.permission.ACTIVITY_MOTION. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500002 | Subscribe Failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

callback(data:motion.OperatingHandStatus) {
    console.info('callback success' + data);
};

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

取消订阅触控操作手感知事件。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。type为“operatingHandChanged”，表示操作手状态变化。 |
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | 否   | 回调函数，返回操作手结果。                                   |

**错误码**：

以下错误码的详细介绍请参见[行为动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to unsubscribe operatingHandChanged event forbidden by permission: ohos.permission.ACTIVITY_MOTION. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500003 | Unsubscribe Failed. Possible causes: 1. Callback removal failure; 2. N-API invocation exception, invalid N-API status; 3. IPC request exception. |

**示例**：

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

获取最新触控操作手状态。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| [OperatingHandStatus](#operatinghandstatus) | 返回触控操作手状态信息。 |

**错误码**：

以下错误码的详细介绍请参见[行为动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get the recent operating hand status forbidden by permission: ohos.permission.ACTIVITY_MOTION. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |

**示例**：

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

