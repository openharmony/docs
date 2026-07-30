# @ohos.multimodalAwareness.motion (动作感知能力)(系统接口)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @saga2025-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

本模块提供对用户动作的感知能力，包括用户的手势、动作等。

**起始版本**：26.0.0

> **说明：**
>
> 本模块为系统接口。

## 导入模块

```ts
import { motion } from '@kit.MultimodalAwarenessKit';
```

## PickupEvent

拾取事件枚举。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：该接口为系统接口。

| 名称       | 值   | 说明                     |
| ---------- | ---- | ------------------------ |
| PICKED_UP  | 0    | 表示检测到拾取动作（设备正被抬起）。 |

## RotateEvent

旋转事件枚举。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：该接口为系统接口。

| 名称      | 值   | 说明                                                         |
| --------- | ---- | ------------------------------------------------------------ |
| UNCHANGED | -1   | 表示设备已旋转，但移动幅度不足以改变当前方向，方向保持与之前一致。 |
| UPRIGHT   | 0    | 表示设备竖直放置。                                           |
| LEFT      | 1    | 表示设备向左旋转。                                           |
| INVERTED  | 2    | 表示设备倒置。                                               |
| RIGHT     | 3    | 表示设备向右旋转。                                           |

## PhysicalOrientation

传感器检测到的物理方向枚举。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：该接口为系统接口。

| 名称      | 值   | 说明                   |
| --------- | ---- | ---------------------- |
| UPRIGHT   | 0    | 表示竖直。             |
| LEFT      | 1    | 表示向左。             |
| INVERTED  | 2    | 表示物理方向倒置。     |
| RIGHT     | 3    | 表示向右。             |
| FACE_UP   | 4    | 表示正面朝上。         |
| FACE_DOWN | 5    | 表示正面朝下。         |

## LogicalOrientation

由智能算法计算出的逻辑方向枚举。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：该接口为系统接口。

| 名称      | 值   | 说明                                     |
| --------- | ---- | ---------------------------------------- |
| UNKNOWN   | -1   | 表示方向未知或无法确定（例如非握持状态）。 |
| UPRIGHT   | 0    | 表示竖直。                               |
| LEFT      | 1    | 表示向左。                               |
| INVERTED  | 2    | 表示逻辑方向倒置。                       |
| RIGHT     | 3    | 表示向右。                               |

## HoverHandAction

悬浮手动作枚举。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：该接口为系统接口。

| 名称 | 值   | 说明                     |
| ---- | ---- | ------------------------ |
| DOWN | 0    | 表示悬浮手进入检测区域。 |
| UP   | 1    | 表示悬浮手离开检测区域。 |

## SmartRotateEvent

智能旋转传感器事件的基本数据结构。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：该接口为系统接口。

| 名称               | 类型                   | 只读      | 可选       | 说明     |
| -------------------| ----------------------| ----------|----------|--------|
| physicalOrientation       | [PhysicalOrientation](#physicalorientation)   | 否        | 否         | 重力传感器报告的物理方向。|
| logicalOrientation        | [LogicalOrientation](#logicalorientation)     | 否        | 是          | 智能算法调整后的逻辑方向。|

## HoverHandDetectionArea

悬浮手矩形检测区域的基本数据结构。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：该接口为系统接口。

| 名称   | 类型   | 只读 | 可选 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| left   | number | 否   | 否   | 矩形区域的左边界，单位为px，该参数应为整数，取值范围为：[-2147483648,2147483647]。 |
| top    | number | 否   | 否   | 矩形区域的上边界，单位为px，该参数应为整数，取值范围为：[-2147483648,2147483647]。 |
| width  | number | 否   | 否   | 矩形区域的宽度，单位为px，该参数应为整数，取值范围为：[1,2147483647]。 |
| height | number | 否   | 否   | 矩形区域的高度，单位为px，该参数应为整数，取值范围为：[1,2147483647]。 |

## motion.onPickupChange

onPickupChange(callback: Callback&lt;PickupEvent&gt;): void

订阅拾取传感器事件。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名   | 类型                                             | 必填 | 说明                           |
| -------- | ------------------------------------------------ | ---- | ------------------------------ |
| callback | Callback&lt;[PickupEvent](#pickupevent)&gt;     | 是   | 回调函数，用于接收拾取状态。   |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API.                                      |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities.                                    |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status.                                           |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    motion.onPickupChange((data: motion.PickupEvent) => {
        console.info('callback succeeded: ' + data);
    });
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed onPickupChange and err code is " + error.code);
}
```

## motion.onRotateChange

onRotateChange(callback: Callback&lt;RotateEvent&gt;): void

订阅旋转传感器事件。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名   | 类型                                             | 必填 | 说明                               |
| -------- | ------------------------------------------------ | ---- | ---------------------------------- |
| callback | Callback&lt;[RotateEvent](#rotateevent)&gt;     | 是   | 回调函数，用于接收旋转方向。       |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API.                                      |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities.                                    |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status.                                           |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    motion.onRotateChange((data: motion.RotateEvent) => {
        console.info('callback succeeded: ' + data);
    });
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed onRotateChange and err code is " + error.code);
}
```

## motion.onSmartRotateChange

onSmartRotateChange(callback: Callback&lt;SmartRotateEvent&gt;): void

订阅智能旋转传感器事件。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名   | 类型                                                     | 必填 | 说明                                   |
| -------- | -------------------------------------------------------- | ---- | -------------------------------------- |
| callback | Callback&lt;[SmartRotateEvent](#smartrotateevent)&gt;   | 是   | 回调函数，用于接收智能旋转方向信息。   |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API.                                      |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities.                                    |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status.                                           |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    motion.onSmartRotateChange((data: motion.SmartRotateEvent) => {
        console.info('callback succeeded: physicalOrientation=' + data.physicalOrientation);
    });
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed onSmartRotateChange and err code is " + error.code);
}
```

## motion.onHoverHandChange

onHoverHandChange(detectionArea: HoverHandDetectionArea, callback: Callback&lt;HoverHandAction&gt;): void

订阅悬浮手事件，并立即开启悬浮手事件检测，检测时长为五秒。需与offHoverHandChange配对使用，使用完毕后应调用offHoverHandChange取消订阅以释放系统资源。

> **说明：**
>
> 检测时长到期后，悬浮手事件检测将自动终止，不再上报悬浮手事件，需要开发者再次调用订阅此接口以重新开启检测。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名        | 类型                                                | 必填 | 说明                                                         |
| ------------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| detectionArea | [HoverHandDetectionArea](#hoverhanddetectionarea)   | 是   | 悬浮手检测矩形区域，用于指定设备屏幕中检测悬浮手事件的区域。<br/>若重复调用此接口，会覆盖上一次传入的检测区域。<br/>若矩形区域超出屏幕，则默认检测该矩形区域与屏幕的重合部分。 |
| callback      | Callback&lt;[HoverHandAction](#hoverhandaction)&gt; | 是   | 回调函数，用于接收悬浮手动作信息。                           |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500002 | Subscription failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    let area: motion.HoverHandDetectionArea = {
      left: 0,
      top: 0,
      width: 100,
      height: 100
    };
    motion.onHoverHandChange(area, (data: motion.HoverHandAction) => {
        console.info('callback succeeded: hoverHandAction=' + data);
    });
} catch (err) {
    let error = err as BusinessError;
    console.error(`Failed onHoverHandChange. Code: ${error.code}, message: ${error.message}`);
}
```

## motion.onHoverHandChange

onHoverHandChange(detectionArea: HoverHandDetectionArea, duration: int, callback: Callback&lt;HoverHandAction&gt;): void

订阅悬浮手事件，并立即开启悬浮手事件检测，支持指定检测时长。需与offHoverHandChange配对使用，使用完毕后应调用offHoverHandChange取消订阅以释放系统资源。

> **说明：**
>
> 检测时长到期后，悬浮手事件检测将自动终止，不再上报悬浮手事件，需要开发者再次调用订阅此接口以重新开启检测。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名        | 类型                                                | 必填 | 说明                                                         |
| ------------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| detectionArea | [HoverHandDetectionArea](#hoverhanddetectionarea)   | 是   | 目标检测矩形区域，用于指定设备屏幕中检测悬浮手事件的区域。<br/>若重复调用此接口，会覆盖上一次传入的检测区域。<br/>若矩形区域超出屏幕，则默认检测该矩形区域与屏幕的重合部分。 |
| duration      | number                                              | 是   | 目标检测时长，单位为秒，该参数应为整数，取值范围为：[1,10]。<br/>悬浮手检测为高功耗检测，建议开发者按需设置检测时长。 |
| callback      | Callback&lt;[HoverHandAction](#hoverhandaction)&gt; | 是   | 回调函数，用于接收悬浮手动作信息。                           |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500002 | Subscription failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    let area: motion.HoverHandDetectionArea = {
      left: 0,
      top: 0,
      width: 100,
      height: 100
    };
    let duration: number = 6;
    motion.onHoverHandChange(area, duration, (data: motion.HoverHandAction) => {
        console.info('callback succeeded: hoverHandAction=' + data);
    });
} catch (err) {
    let error = err as BusinessError;
    console.error(`Failed onHoverHandChange. Code: ${error.code}, message: ${error.message}`);
}
```

## motion.offPickupChange

offPickupChange(callback?: Callback&lt;PickupEvent&gt;): void

取消订阅拾取传感器事件。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名   | 类型                                             | 必填 | 说明                                   |
| -------- | ------------------------------------------------ | ---- | -------------------------------------- |
| callback | Callback&lt;[PickupEvent](#pickupevent)&gt;     | 否   | 需取消的拾取事件回调函数，若无此参数，则取消订阅拾取事件的所有回调函数。             |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API.                                      |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status.                                           |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    motion.offPickupChange();
    console.info("offPickupChange succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed offPickupChange and err code is " + error.code);
}
```

## motion.offRotateChange

offRotateChange(callback?: Callback&lt;RotateEvent&gt;): void

取消订阅旋转传感器事件。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名   | 类型                                             | 必填 | 说明                                   |
| -------- | ------------------------------------------------ | ---- | -------------------------------------- |
| callback | Callback&lt;[RotateEvent](#rotateevent)&gt;     | 否   | 需取消的旋转事件回调函数，若无此参数，则取消订阅旋转事件的所有回调函数。             |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API.                                      |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status.                                           |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    motion.offRotateChange();
    console.info("offRotateChange succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed offRotateChange and err code is " + error.code);
}
```

## motion.offSmartRotateChange

offSmartRotateChange(callback?: Callback&lt;SmartRotateEvent&gt;): void

取消订阅智能旋转传感器事件。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名   | 类型                                                     | 必填 | 说明                                       |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------ |
| callback | Callback&lt;[SmartRotateEvent](#smartrotateevent)&gt;   | 否   | 需取消的智能旋转事件回调函数，若无此参数，则取消订阅智能旋转事件的所有回调函数。             |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API.                                      |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status.                                           |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    motion.offSmartRotateChange();
    console.info("offSmartRotateChange succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed offSmartRotateChange and err code is " + error.code);
}
```

## motion.offHoverHandChange

offHoverHandChange(callback?: Callback&lt;HoverHandAction&gt;): void

取消订阅悬浮手事件。当应用不再需要监听悬浮手事件时使用，应调用此接口取消订阅以释放系统资源。

**起始版本**：26.0.0

**系统能力**：SystemCapability.MultimodalAwareness.Motion

**系统接口**：此接口为系统接口，仅系统应用可调用。

**参数**：

| 参数名   | 类型                                                | 必填 | 说明                                                         |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | Callback&lt;[HoverHandAction](#hoverhandaction)&gt; | 否   | 需取消的悬浮手事件回调函数，若无此参数，则取消订阅悬浮手事件的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 31500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 31500003 | Unsubscription failed. Possible causes: 1. Callback failure; 2. N-API invocation exception, invalid N-API status; 3. IPC request exception. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    const callback = (data: motion.HoverHandAction) => {
        console.info('callback succeeded: ' + data);
    };
    let area: motion.HoverHandDetectionArea = {
      left: 0,
      top: 0,
      width: 100,
      height: 100
    };
    motion.onHoverHandChange(area, callback);
    motion.offHoverHandChange(callback); // 取消指定回调
    console.info('offHoverHandChange succeeded');
} catch (err) {
    let error = err as BusinessError;
    console.error(`Failed offHoverHandChange. Code: ${error.code}, message: ${error.message}`);
}
```

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { motion } from '@kit.MultimodalAwarenessKit';

try {
    motion.offHoverHandChange(); // 取消所有回调
    console.info('offHoverHandChange succeeded');
} catch (err) {
    let error = err as BusinessError;
    console.error(`Failed offHoverHandChange. Code: ${error.code}, message: ${error.message}`);
}
```
