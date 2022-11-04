# 键鼠穿越管理

键鼠穿越功能，即两台或多台设备组网协同后可以共用一套键盘鼠标。
键鼠穿越管理模块，提供实现键盘、鼠标等外接输入设备的跨设备协同操作。在设备组网的情况下，提供多设备间共享键鼠的开关，设备穿越状态更新以及键鼠穿越光标自适应显示。

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'
```

## inputDeviceCooperate.enable

enable(enable: boolean, callback: AsyncCallback\<void>): void

键鼠穿越开关开启或关闭，使用callback异步回调。

**系统能力**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名    | 类型                       | 必填  | 说明                                                                |
| -------- | ------------------------- | ---- | ------------------------------------------------------------------- |
| enable   | boolean                   | 是   | 键鼠穿越开关开启或关闭状态。true: 键鼠穿越开关开启; false: 键鼠穿越开关关闭。
| callback | AsyncCallback\<void>       | 是   | 异步回调函数。当键鼠穿越开关开启或关闭成功，err为undefined，否则为错误对象。                                |



**示例**：

```js
try {
  inputDeviceCooperate.enable(true, (err) => {
    if (err) {
      console.log(`Turn on the key mouse crossing switch failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
      return;
    }
    console.log(`Turn on the key mouse crossing switch success.`);
  });
} catch (err) {
  console.log(`Turn on the key mouse crossing switch failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## inputDeviceCooperate.enable

enable(enable: boolean): Promise\<void>

键鼠穿越开关开启或关闭，使用Promise方式作为异步方法。

**系统能力**： SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名     | 类型     | 必填  | 说明                                                                                 |
| --------- | ------- | ---- | -------------------------------------------------------------------                 |
| enable    | boolean | 是   | 键鼠穿越开关开启或关闭状态。true: 键鼠穿越开关开启; false: 键鼠穿越开关关闭。                   |



**返回值**：

| 参数                 | 说明                     |
| ------------------- | ------------------------------- |
| Promise\<void>      | Promise实例，用于异步获取结果。        |



**示例**：

```js
try {
  inputDeviceCooperate.enable(false).then((err) => {
    console.log(`Turn on the key mouse crossing switch success`);
  }, (err) => {
    console.log(`Turn on the key mouse crossing switch failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
  });
} catch (err) {
  console.log(`Turn on the key mouse crossing switch failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## inputDeviceCooperate.start

start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback\<void>): void

启动键鼠穿越，使用callback异步回调。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| sinkDeviceDescriptor | string                       |  是   | 键鼠穿越目标设备描述符。             |
| srcInputDeviceId     | number                       |  是   | 键鼠穿越待穿越外设标识符。           |
| callback             | AsyncCallback\<void>         |  是    | 异步回调函数。当键鼠穿越启动成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[ohos.multimodalinput错误码](../errorcodes/errorcodes-multimodalinput.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 4400001  | Incorrect descriptor for the target device.                |
| 4400002  | Failed to operate the input device.                |

**示例**：

```js
try {
  inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId, (err) => {
    if (err) {
      console.log(`Start key mouse crossing failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
      return;
    }
    console.log(`Start key mouse crossing success.`);
  });
} catch (err) {
  console.log(`Start key mouse crossing failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## inputDeviceCooperate.start

start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise\<void>

启动键鼠穿越，使用Promise方式作为异步方法。

**系统能力**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| sinkDeviceDescriptor | string                       |  是   | 键鼠穿越目标设备描述符。             |
| srcInputDeviceId     | number                       |  是   | 键鼠穿越待穿越外设标识符。           |



**返回值**：

| 参数名                  | 说明                             |
| ---------------------- | ------------------------------- |
| Promise\<void>         | Promise实例，用于异步获取结果。       |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimodalinput错误码](../errorcodes/errorcodes-multimodalinput.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 4400001  | Incorrect descriptor for the target device.                |
| 4400002  | Failed to operate the input device.                |

**示例**：

```js
try {
  inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId).then((err) => {
    console.log(`Start key mouse crossing success.`);
  }, (err) => {
    console.log(`Start key mouse crossing failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
  });
} catch (err) {
  console.log(`Start key mouse crossing failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## inputDeviceCooperate.stop

stop(callback: AsyncCallback\<void>): void

停止键鼠穿越，使用callback异步回调。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| callback             | AsyncCallback\<void>         |  是   | 异步回调函数，返回查询结果。        |



**示例**：

```js
try {
  inputDeviceCooperate.stop((err) => {
    if (err) {
      console.log(`Stop key mouse crossing failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
      return;
    }
    console.log(`Stop key mouse crossing success.`);
  });
} catch (err) {
  console.log(`Stop key mouse crossing failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## inputDeviceCooperate.stop

stop(): Promise\<void>

停止键鼠穿越，使用Promise异步回调。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 说明                            |
| --------             | ----------------------------   |
| Promise\<void>       |  Promise实例，用于异步获取结果。      | 

**示例**：

```js
try {
  inputDeviceCooperate.stop().then((err) => {
    console.log(`Stop key mouse crossing success.`);
  }, (err) => {
    console.log(`Stop key mouse crossing failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
  });
} catch (err) {
  console.log(`Stop key mouse crossing failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## inputDeviceCooperate.getState

getState(deviceDescriptor: string, callback: AsyncCallback<{ state: boolean }>): void

获取键鼠穿越开关的状态，使用callback异步回调。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填   | 说明                            |
| --------             | ---------                    | ----  | ----------------------------    |
| deviceDescriptor     | string                       |  是    | 键鼠穿越目标设备描述符。             |
| callback             | AsyncCallback<{ state: boolean }> |  是    | 异步回调函数，接收键鼠穿越开关状态。        |

**示例**：

```js
try {
  inputDeviceCooperate.getState(deviceDescriptor, (err, data) => {
    if (err) {
      console.log(`Get the status failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
      return;
    }
    console.log(`Get the status success. data=${JSON.stringify(data)}`);
  });
} catch (err) {
  console.log(`Get the status failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## inputDeviceCooperate.getState

getState(deviceDescriptor: string): Promise<{ state: boolean }>

获取键鼠穿越开关的状态，使用Promise异步回调。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填   | 说明                            |
| --------             | ---------                    | ----  | ----------------------------    |
| deviceDescriptor     | string                       |  是    | 键鼠穿越目标设备描述符。            |



**返回值**：

| 参数                        | 说明                     |
| -------------------        | ------------------------------- |
| Promise<{ state: boolean }>| Promise实例，用于异步获取结果。        |



**示例**：

```js
try {
  inputDeviceCooperate.getState(deviceDescriptor).then((data) => {
    console.log(`Get the status success. data=${JSON.stringify(data)}`);
  }, (err) => {
    console.log(`Get the status failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
  });
} catch (err) {
  console.log(`Get the status failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## on('cooperation')

on(type: 'cooperation', callback: AsyncCallback<{ deviceDescriptor: string, eventMsg: EventMsg }>): void

注册监听键鼠穿越状态。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                                                             | 必填 | 说明                            |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  是  | 注册类型，'cooperation'。         |
| callback             | AsyncCallback<{ deviceDescriptor: string, eventMsg: [EventMsg](#eventmsg) }> |  是  | 异步回调函数，接收键鼠穿越事件消息。    |



**示例**：

```js
try {
  inputDeviceCooperate.on('cooperation', (data) => {
    if (data) {
      console.log(`error: ${JSON.stringify(data)}`);
    } else {
      console.log(`cooperation: ${JSON.stringify(data)}`);
    }
  });
} catch (err) {
  console.log(`Registered failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## off('cooperation')

off(type: 'cooperation', callback?: AsyncCallback\<void>): void

关闭监听键鼠穿越状态。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                                                              | 必填    | 说明                           |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  是    | 注册类型，'cooperation'。         |
| callback             | AsyncCallback<void> |  否  | 异步回调函数，用于返回结果。 |



**示例**：

```js
try {
  inputDeviceCooperate.off('cooperation', (err) => {
    if (err) {
      console.log(`error: ${JSON.stringify(err)}`);
    } else {
      console.log(`Unregistered succeed`);
    }
  });
} catch (err) {
  console.log(`Unregistered failed. error code=${JSON.stringify(err.code)} msg=${JSON.stringify(err.message)}`);
}
```

## EventMsg

键鼠穿越事件。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

| 参数名                        | 值        | 说明                              |
| --------                     | --------- |  -----------------               |
| MSG_COOPERATE_INFO_START     | 200       |  键鼠穿越消息，表示键鼠穿越开始。       |
| MSG_COOPERATE_INFO_SUCCESS   | 201       |  键鼠穿越消息，表示键鼠穿越成功。      |
| MSG_COOPERATE_INFO_FAIL      | 202       |  键鼠穿越消息，表示键鼠穿越失败。      |
| MSG_COOPERATE_STATE_ON       | 500       |  键鼠穿越状态，表示键鼠穿越状态开启。   |
| MSG_COOPERATE_STATE_OFF      | 501       |  键鼠穿越状态，表示键鼠穿越状态关闭。   |
