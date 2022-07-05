# continuationManager


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

continuationManager模块提供了流转/协同入口管理服务能力，包括连接/取消流转管理服务，注册/解注册设备连接变化监听，拉起互联面板，更新连接状态。

## 导入模块

```js
import continuationManager from '@ohos.continuation.continuationManager'
```

## continuationManager.register

register(callback: AsyncCallback\<number>): void;

注册流转管理服务，并获取对应的注册token，无过滤条件，使用AsyncCallback方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback\<number> | 是 | AsyncCallback形式返回流转管理服务连接后生成的token。 |

**示例：**

  ```js
  let token = -1;
  continuationManager.register((err, data) => {
    if (err.code != 0) {
      console.error('register failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('register finished, ' + JSON.stringify(data));
    token = data;
  });
  ```

## continuationManager.register

register(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void;

连接流转管理服务，并获取对应的注册token，使用AsyncCallback方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | 是 | 过滤可选择设备列表的额外参数。 |
  | callback | AsyncCallback\<number> | 是 | AsyncCallback形式返回流转管理服务连接后生成的token。 |

**示例：**

  ```js
  let token = -1;
  let continuationExtraParams = {
    deviceType: ["00E"]
  };
  continuationManager.register(continuationExtraParams, (err, data) => {
    if (err.code != 0) {
      console.error('register failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('register finished, ' + JSON.stringify(data));
    token = data;
  });
  ```

## continuationManager.register

register(options?: ContinuationExtraParams): Promise\<number>;

连接流转管理服务，并获取对应的注册token，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | 否 | 过滤可选择设备列表的额外参数，该参数可缺省|

**示例：**

  ```js
  let continuationExtraParams = {
    deviceType: ["00E"]
  };
  continuationManager.register(continuationExtraParams)
    .then((data) => {
      console.info('register finished, ' + JSON.stringify(data));
      token = data;
    })
    .catch((err) => {
      console.error('register failed, cause: ' + JSON.stringify(err));
    });
  ```

## continuationManager.on("deviceConnect")<sup>(deprecated)</sup>
> 从API Version 9开始不再维护，建议使用[on](#continuationmanagerondeviceconnect)替代。

on(type: "deviceConnect", callback: Callback\<ContinuationResult>): void;

异步方法，监听设备连接状态，使用Callback形式返回连接的设备信息。

## continuationManager.on("deviceDisconnect")<sup>(deprecated)</sup>
> 从API Version 9开始不再维护，建议使用[on](#continuationmanagerondevicedisconnect)替代。

on(type: "deviceDisconnect", callback: Callback\<string>): void;

异步方法，监听设备断开状态，使用Callback形式返回断开的设备信息。

## continuationManager.off("deviceConnect")<sup>(deprecated)</sup>
> 从API Version 9开始不再维护，建议使用[off](#continuationmanageroffdeviceconnect)替代。

off(type: "deviceConnect", callback?: Callback\<ContinuationResult>): void;

异步方法，取消监听设备连接状态，使用Callback形式返回连接的设备信息。

## continuationManager.off("deviceDisconnect")<sup>(deprecated)</sup>
> 从API Version 9开始不再维护，建议使用[off](#continuationmanageroffdevicedisconnect)替代。

off(type: "deviceDisconnect", callback?: Callback\<string>): void;

异步方法，取消监听设备断开状态，使用Callback形式返回连接的设备信息。

## continuationManager.on("deviceConnect")

on(type: "deviceConnect", token: number, callback: Callback\<Array\<ContinuationResult>>): void;

异步方法，监听设备连接状态，使用Callback形式返回连接的设备信息。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 监听的事件类型，固定值"deviceConnect"。 |
  | token | number | 是 | 注册后的token。 |
  | callback | Callback\<Array\<[ContinuationResult](js-apis-continuation-continuationResult.md)>> | 是 | 当用户从互联面板中选择设备时调用，返回设备ID、设备类型和设备名称供开发者使用。 |

**示例：**

  ```js
  continuationManager.on("deviceConnect", token, (data) => {
    console.info('onDeviceConnect len: ' + data.length);
    for (let i = 0; i < data.length; i++) {
      console.info('onDeviceConnect deviceId: ' + JSON.stringify(data[i].id));
      console.info('onDeviceConnect deviceType: ' + JSON.stringify(data[i].type));
      console.info('onDeviceConnect deviceName: ' + JSON.stringify(data[i].name));
    }
  });
  ```

## continuationManager.on("deviceDisconnect")

on(type: "deviceDisconnect", token: number, callback: Callback\<Array\<string>>): void;

异步方法，监听设备断开状态，使用Callback形式返回断开的设备信息。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 监听的事件类型，固定值"deviceDisconnect"。 |
  | token | number | 是 | 注册后的token。 |
  | callback | Callback\<Array\<string>> | 是 | 当用户从互联面板中断开设备时调用，返回设备ID供开发者使用。 |

**示例：**

  ```js
  continuationManager.on("deviceDisconnect", token, (data) => {
    console.info('onDeviceDisconnect len: ' + data.length);
    for (let i = 0; i < data.length; i++) {
      console.info('onDeviceDisconnect deviceId: ' + JSON.stringify(data[i]));
    }
    console.info('onDeviceDisconnect finished.');
  });
  ```

## continuationManager.off("deviceConnect")

off(type: "deviceConnect", token: number): void;

取消监听设备连接状态。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消监听的事件类型，固定值"deviceConnect"。 |
  | token | number | 是 | 注册后的token。 |

**示例：**

  ```js
  continuationManager.off("deviceConnect", token);
  ```

## continuationManager.off("deviceDisconnect")

off(type: "deviceDisconnect", token: number): void;

取消监听设备断开状态。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消监听的事件类型，固定值"deviceDisconnect"。 |
  | token | number | 是 | 注册后的token。 |

**示例：**

  ```js
  continuationManager.off("deviceDisconnect", token);
  ```

## continuationManager.startDeviceManager

startDeviceManager(token: number, callback: AsyncCallback\<void>): void;

拉起互联面板，可显示组网内可选择设备列表信息，无过滤条件，使用AsyncCallback方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | callback | AsyncCallback\<void> | 是 | AsyncCallback形式返回接口调用结果。 |

**示例：**

  ```js
  continuationManager.startDeviceManager(token, (err, data) => {
    if (err.code != 0) {
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('startDeviceManager finished, ' + JSON.stringify(data));
  });
  ```

## continuationManager.startDeviceManager

startDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void;

拉起互联面板，可显示组网内可选择设备列表信息，使用AsyncCallback方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | 是 | 过滤可选择设备列表的额外参数。 |
  | callback | AsyncCallback\<void> | 是 | AsyncCallback形式返回接口调用结果。 |

**示例：**

  ```js
  let continuationExtraParams = {
    deviceType: ["00E"]
  };
  continuationManager.startDeviceManager(token, continuationExtraParams, (err, data) => {
    if (err.code != 0) {
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('startDeviceManager finished, ' + JSON.stringify(data));
  });
  ```

## continuationManager.startDeviceManager

startDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>;

拉起互联面板，可显示组网内可选择设备列表信息，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | 否 | 过滤可选择设备列表的额外参数，该参数可缺省|

**示例：**

  ```js
  let continuationExtraParams = {
    deviceType: ["00E"]
  };
  continuationManager.startDeviceManager(token, continuationExtraParams)
    .then((data) => {
      console.info('startDeviceManager finished, ' + JSON.stringify(data));
    })
    .catch((err) => {
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));
    });
  ```

## continuationManager.updateConnectStatus

updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void;

通知互联面板，更新当前的连接状态，使用AsyncCallback方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | deviceId | string | 是 | 设备ID。 |
  | status | [DeviceConnectState](#deviceconnectstate) | 是 | 设备连接状态。 |
  | callback | AsyncCallback\<void> | 是 | AsyncCallback形式返回接口调用结果。 |

**示例：**

  ```js
  let deviceId: string = "test deviceId";
  continuationManager.updateConnectStatus(token, deviceId, continuationManager.DeviceConnectState.CONNECTED, (err, data) => {
    if (err.code != 0) {
      console.error('updateConnectStatus failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('updateConnectStatus finished, ' + JSON.stringify(data));
  });
  ```

## continuationManager.updateConnectStatus

updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>;

通知互联面板，更新当前的连接状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | deviceId | string | 是 | 设备ID。 |
  | status | [DeviceConnectState](#deviceconnectstate) | 是 | 设备连接状态。 |

**示例：**

  ```js
  let deviceId: string = "test deviceId";
  continuationManager.updateConnectStatus(token, deviceId, continuationManager.DeviceConnectState.CONNECTED)
    .then((data) => {
      console.info('updateConnectStatus finished, ' + JSON.stringify(data));
    })
    .catch((err) => {
      console.error('updateConnectStatus failed, cause: ' + JSON.stringify(err));
    });
  ```

## continuationManager.unregister

unregister(token: number, callback: AsyncCallback\<void>): void;

解注册流转管理服务，传入注册时获取的token进行解注册，使用AsyncCallback方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | callback | AsyncCallback\<void> | 是 | AsyncCallback形式返回接口调用结果。 |

**示例：**

  ```js
  continuationManager.unregister(token, (err, data) => {
    if (err.code != 0) {
      console.error('unregister failed, cause: ' + JSON.stringify(err));
      return;
    }
    console.info('unregister finished, ' + JSON.stringify(data));
  });
  ```

## continuationManager.unregister

unregister(token: number): Promise\<void>;

解注册流转管理服务，传入注册时获取的token进行解注册，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |

**示例：**

  ```js
  continuationManager.unregister(token)
    .then((data) => {
      console.info('unregister finished, ' + JSON.stringify(data));
    })
    .catch((err) => {
      console.error('unregister failed, cause: ' + JSON.stringify(err));
    });
  ```

## DeviceConnectState

设备连接状态。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 值 | 说明 |
  | -------- | -------- | -------- | -------- |
  | IDLE | number | 0 | 设备连接初始状态。 |
  | CONNECTING | number | 1 | 设备连接中状态。 |
  | CONNECTED | number | 2 | 设备已连接状态。 |
  | DISCONNECTING | number | 3 | 设备断开连接状态。 |

## ContinuationMode

互联面板连接模式。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 值 | 说明 |
  | -------- | -------- | -------- | -------- |
  | COLLABORATION_SINGLE | number | 0 | 互联面板单选模式。 |
  | COLLABORATION_MULTIPLE | number | 1 | 互联面板多选模式。 |