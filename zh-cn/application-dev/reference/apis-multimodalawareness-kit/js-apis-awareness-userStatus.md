# @ohos.multimodalawareness.userStatus (动作感知)

本模块，提供对用户状态感知能力，包括未成年检测等。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { userStatus } from '@kit.MultimodalAwarenessKit';
```

## IdentificationStatus

未成年人检测状态信息。

**系统能力**：SystemCapability.MultimodalAwareness.UserStatus

| 名称                | 值   | 说明                   |
| ------------------- | ---- | ---------------------- |
| ADULT  | 0    | 表示是成年人。 |
| MINOR  | 1    | 表示是未成年。 |


## userStatus.on('MinorIdentification')

 on(type: 'MinorIdentification', callback: Callback&lt;IdentificationStatus&gt;): void;

订阅未成年人检测功能。

**需要权限**：ohos.permission.ACCELEROMETER

**系统能力**：SystemCapability.MultimodalAwareness.UserStatus

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。type为“MinorIdentification”，表示未成年检测功能。 |
| callback | Callback&lt;[IdentificationStatus](#IdentificationStatus)&gt; | 是   | 回调函数，返回未成年检测结果。|

**错误码**：

以下错误码的详细介绍请参见[用户状态感知错误码](errorcode-userStatus.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to subscribe MinorIdentification feature forbidden by permission: ohos.permission.ACCELEROMETER. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 33500002 | Subscription failed. Possible causes: 1. Callback registration failure; 2. Failed to bind native object to js wrapper; 3. N-API invocation exception, invalid N-API status; 4. IPC request exception. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

callback(data:userStatus.IdentificationStatus) {
    console.info('callback success' + data);
};

try {
    userStatus.on('MinorIdentification', this.callback);  
    console.info("on succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed on and err code is " + error.code);
}
```



## userStatus.off('MinorIdentification')

off(type: 'MinorIdentification', callback?: Callback&lt;IdentificationStatus&gt;): void;

取消订阅未成年人检测功能。

**需要权限**：ohos.permission.ACCELEROMETER

**系统能力**：SystemCapability.MultimodalAwareness.UserStatus

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件类型。type为“MinorIdentification”，表示未成年检测功能。 |
| callback | Callback&lt;[IdentificationStatus](#IdentificationStatus)&gt; | 否   | 回调函数，返回未成年检测结果。 |

**错误码**：

以下错误码的详细介绍请参见[用户状态感知错误码](errorcode-userStatus.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied. An attempt was made to unsubscribe MinorIdentification feature forbidden by permission: ohos.permission.ACCELEROMETER. |
| 401      | Parameter error. Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 33500001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception; 2. N-API invocation exception, invalid N-API status. |
| 33500003 | Unsubscription failed. Possible causes: 1. Callback failure; 2. N-API invocation exception, invalid N-API status; 3. IPC request exception. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    userStatus.off('MinorIdentification');
    console.info("off succeeded");
} catch (err) {
    let error = err as BusinessError;
    console.error("Failed off and err code is " + error.code);
}
```
