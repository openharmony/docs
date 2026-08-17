# @ohos.multimodalAwareness.motion (动作感知能力)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @saga2025-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

本模块提供对用户动作的感知能力，支持识别用户的手势和动作状态，适用于需要根据用户手势或动作进行响应的交互场景，如手势识别、动作触发等，帮助应用提供更自然的交互体验和精准的场景感知。

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
| UNKNOWN_STATUS      | 0    | 表示未识别。 |
| LEFT_HAND_OPERATED  | 1    | 表示触控操作手是左手。 |
| RIGHT_HAND_OPERATED | 2    | 表示触控操作手是右手。 |

## HoldingHandStatus<sup>20+</sup>

握持手状态信息，表示握持手状态变化感知事件的结果。订阅事件后，返回当前握持手状态信息。

**系统能力**：SystemCapability.MultimodalAwareness.Motion

| 名称            | 值   | 说明           |
| --------------- | ---- | -------------- |
| NOT_HELD        | 0    | 表示未握持。   |
| LEFT_HAND_HELD  | 1    | 表示左手握持。 |
| RIGHT_HAND_HELD | 2    | 表示右手握持。 |
| BOTH_HANDS_HELD | 3    | 表示双手握持。 |
| UNKNOWN_STATUS  | 16   | 表示未识别。   |

## motion.on('operatingHandChanged')

on(type: 'operatingHandChanged', callback: Callback&lt;OperatingHandStatus&gt;): void

订阅触控操作手感知事件。系统通过触控屏传感器采集用户触控数据，结合手势识别算法判断当前操作手是左手还是右手。适用于手势交付、单双手操作适配等场景，通过识别用户的触控操作手状态优化界面布局和交互方式。建议在使用完毕后调用off()取消订阅以释放资源，避免多余的性能功耗开销。相关方法：off('operatingHandChanged')：取消订阅触控操作手感知事件。

如果设备不支持此功能，将返回801错误码。

**需要权限**：
- API版本20+：ohos.permission.ACTIVITY_MOTION 或 ohos.permission.DETECT_GESTURE
- API版本15-19：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。固定传入'operatingHandChanged'，表示操作手状态变化。 |
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | 是   | 回调函数，返回操作手状态信息。 |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to subscribe operatingHandChanged event forbidden by permission: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500002 | Subscription failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**示例**：

```ts
import { BusinessError, Callback } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

let callback:Callback<motion.OperatingHandStatus> = (data:motion.OperatingHandStatus) => {
    console.info('operatingHandStatus: ' + data);
};

try {
    motion.on('operatingHandChanged', callback);  
    console.info('on succeeded');
} catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to subscribe operatingHandChanged. Code: ${error.code}, message: ${error.message}`);
}
```

## motion.off('operatingHandChanged')

off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void

取消订阅触控操作手感知事件。若未调用on()就调用off()，该方法会抛出异常。相关方法：on('operatingHandChanged')：订阅触控操作手感知事件。

**需要权限**：
- API版本20+：ohos.permission.ACTIVITY_MOTION 或 ohos.permission.DETECT_GESTURE
- API版本15-19：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。固定传入'operatingHandChanged'，表示操作手状态变化。 |
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | 否   | 回调函数，返回操作手状态信息。需要取消监听的回调函数，需与订阅时传入的回调函数一致。若不填，则取消当前监听该事件的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to unsubscribe operatingHandChanged event forbidden by permission: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500003 | Unsubscription failed. Possible causes: 1. Callback failure; 2. N-API invocation exception, invalid N-API status; 3. IPC request exception. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    motion.off('operatingHandChanged');
    console.info('off succeeded');
} catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to unsubscribe operatingHandChanged. Code: ${error.code}, message: ${error.message}`);
}
```

## motion.getRecentOperatingHandStatus()

getRecentOperatingHandStatus(): OperatingHandStatus

获取最新触控操作手状态。该方法直接返回最新的操作手状态，无需订阅事件即可调用。

**需要权限**：
- API版本20+：ohos.permission.ACTIVITY_MOTION 或 ohos.permission.DETECT_GESTURE
- API版本15-19：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| [OperatingHandStatus](#operatinghandstatus) | 返回触控操作手状态信息。 |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to get the recent operating hand status forbidden by permission: ohos.permission.ACTIVITY_MOTION or ohos.permission.DETECT_GESTURE. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
    console.info('get succeeded: ' + data);
} catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to get recent operating hand status. Code: ${error.code}, message: ${error.message}`);
}
```

## motion.on('holdingHandChanged') <sup>20+</sup>

on(type: 'holdingHandChanged', callback: Callback&lt;HoldingHandStatus&gt;): void

订阅握持手状态变化感知事件。系统通过传感器数据，结合识别算法判断当前握持手是左手还是右手。适用于阅读应用、视频播放等需要根据用户握持手状态调整界面布局或功能的场景。建议在使用完毕后调用off()取消订阅以释放资源，避免多余的性能功耗开销。相关方法：off('holdingHandChanged')：取消订阅握持手状态变化感知事件。

**需要权限**：ohos.permission.DETECT_GESTURE

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                                   |
| -------- | ------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                            | 是   | 事件类型，固定传入'holdingHandChanged'，表示握持手状态变化。 |
| callback | Callback&lt;[HoldingHandStatus](#holdinghandstatus20)&gt; | 是   | 回调函数，返回握持手状态信息。 |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to subscribe holdingHandChanged event forbidden by permission: ohos.permission.DETECT_GESTURE. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500002 | Subscription failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**示例**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callback:Callback<motion.HoldingHandStatus> = (data:motion.HoldingHandStatus) => {
  console.info('holdingHandStatus: ' + data);
};

try {
  motion.on('holdingHandChanged', callback);
  console.info('on succeeded');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to subscribe holdingHandChanged. Code: ${error.code}, message: ${error.message}`);
}
```

## motion.off('holdingHandChanged') <sup>20+</sup>

off(type: 'holdingHandChanged', callback?: Callback&lt;HoldingHandStatus&gt;): void

取消订阅握持手状态变化感知事件。若未调用on()就调用off()，该方法会抛出异常。相关方法：on('holdingHandChanged')：订阅握持手状态变化感知事件。

**需要权限**：ohos.permission.DETECT_GESTURE

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                                           |
| -------- | ------------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                            | 是   | 事件类型，固定传入'holdingHandChanged'，表示握持手状态变化。         |
| callback | Callback&lt;[HoldingHandStatus](#holdinghandstatus20)&gt; | 否   | 回调函数，返回握持手状态信息。需要取消监听的回调函数，需与订阅时传入的回调函数一致。若不填，则取消当前监听该事件的所有回调函数。 |

**错误码**

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to unsubscribe holdingHandChanged event forbidden by permission: ohos.permission.DETECT_GESTURE. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500003 | Unsubscription failed. Possible causes: 1. Callback failure; 2. N-API invocation exception, invalid N-API status; 3. IPC request exception. |

**示例**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  motion.off('holdingHandChanged'); // 移除所有同类订阅
  console.info('off succeeded');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to unsubscribe holdingHandChanged. Code: ${error.code}, message: ${error.message}`);
}
```
