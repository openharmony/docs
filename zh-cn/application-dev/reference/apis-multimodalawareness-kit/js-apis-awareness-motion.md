# @ohos.mulitmodalawareness.motion (动作感知)

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

**系统能力**：SystemCapability.MultimodalAwarness.Motion

| 名称                | 值   | 说明                   |
| ------------------- | ---- | ---------------------- |
| LEFT_HAND_OPERATED  | 1    | 表示触控操作手是左手。 |
| RIGHT_HAND_OPERATED | 2    | 表示触控操作手是右手。 |




## motion.on('operatingHandChanged')

 on(type: 'operatingHandChanged', callback: Callback&lt;OperatingHandStatus&gt;): void;

订阅触控操作手感知事件。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwarness.Motion

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。type为“operatingHandChanged”，表示操作手状态变化。 |
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | 是   | 回调函数，返回操作手状态。                                   |

**错误码**：

以下错误码的详细介绍请参见[行为动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported.Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception.                                           |
| 31500002 | Subscribe Failed.                                            |

**示例**：

```ts
motion.on('operatingHandChanged', (data:motion.OperatingHandStatus) => {
    console.info('on success' + data);
})
```



## motion.off('operatingHandChanged')

off(type: 'operatingHandChanged', callback?: Callback&lt;OperatingHandStatus&gt;): void;

取消订阅触控操作手感知事件。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwarness.Motion

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。type为“operatingHandChanged”，表示操作手状态变化。 |
| callback | Callback&lt;[OperatingHandStatus](#operatinghandstatus)&gt; | 否   | 回调函数，返回操作手状态。                                   |

**错误码**：

以下错误码的详细介绍请参见[行为动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported.Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception.                                           |
| 31500003 | UnSubscribe Failed.                                          |

**示例**：

```ts
motion.off('operatingHandChanged', (data:motion.OperatingHandStatus) => {
    console.info('off success' + data);
})
```



## motion.getRecentOperatingHandStatus()

getRecentOperatingHandStatus(): OperatingHandStatus;

获取最新触控操作手状态。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.MultimodalAwarness.Motion

**错误码**：

以下错误码的详细介绍请参见[行为动作感知错误码](errorcode-motion.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 801      | Capability not supported.Function can not work correctly due to limited device capabilities. |
| 31500001 | Service exception.                                           |

**示例**：

```ts
let data:motion.OperatingHandStatus = motion.getRecentOperatingHandStatus();
console.info('get success' + data);
```

