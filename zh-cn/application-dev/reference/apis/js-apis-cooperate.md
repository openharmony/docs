# 键鼠穿越

键鼠穿越功能模块，提供两台或多台设备组网协同后键鼠共享能力，实现键鼠输入设备的跨设备协同操作。

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'
```

## inputDeviceCooperate.enable

enable(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

开启、关闭键鼠穿越，使用AsyncCallback异步方式返回结果。

**系统能力**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名    | 类型      | 必填  | 说明    |
| -------- | ------------------------- | ---- | --------------------------- |
| enable   | boolean                   | 是   | 键鼠穿越使能状态。 |
| callback | AsyncCallback&lt;void&gt;  | 是  |回调函数，异步返回键鼠穿越开启、关闭结果。   |



**示例**：

```js
try {
  inputDeviceCooperate.enable(true, (error) => {
    if (error) {
      console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing enable success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.enable

enable(enable: boolean): Promise&lt;void&gt;

开启、关闭键鼠穿越，使用Promise异步方式返回结果。


**系统能力**： SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名     | 类型     | 必填  | 说明                                                                                 |
| --------- | ------- | ---- | -------------------------------------------------------------------                 |
| enable    | boolean | 是   | 键鼠穿越使能状态。                   |



**返回值**：

| 参数                 | 说明                     |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | Promise对象，异步返回键鼠穿越开启、关闭结果。        |



**示例**：

```js
try {
  inputDeviceCooperate.enable(true).then(() => {
    console.log(`Keyboard mouse crossing enable success.`);
  }, (error) => {
    console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.start

start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback\<void>): void

启动键鼠穿越，使用AsyncCallback异步方式返回结果。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| sinkDeviceDescriptor | string                       |  是   | 键鼠穿越目标设备描述符。             |
| srcInputDeviceId     | number                       |  是   | 键鼠穿越待穿越外设标识符。           |
| callback             | AsyncCallback\<void>         |  是    | 回调函数，异步返回键鼠穿越启动、停止状态。|

**错误码：**

以下错误码的详细介绍请参见[ohos.multimodalinput错误码](../errorcodes/errorcode-multimodalinput.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 4400001  | 当调用键鼠穿越接口传入无效的设备描述符参数时，系统会产生此错误码。                |
| 4400002  | 当调用键鼠穿越接口时穿越状态异常，系统会产生此错误码。                |

**示例**：

```js
try {
  inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId, (error) => {
    if (error) {
      console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Start Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.start

start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise\<void>

启动键鼠穿越，使用Promise异步方式返回结果。

**系统能力**: SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| sinkDeviceDescriptor | string                       |  是   | 键鼠穿越目标设备描述符。             |
| srcInputDeviceId     | number                       |  是   | 键鼠穿越待穿越外设标识符。           |



**返回值**：

| 参数名                  | 说明                             |
| ---------------------- | ------------------------------- |
| Promise\<void>         | Promise对象，异步返回键鼠穿越启动、关闭结果。       |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimodalinput错误码](../errorcodes/errorcode-multimodalinput.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 4400001  | 当调用键鼠穿越接口传入无效的设备描述符参数时，系统会产生此错误码。                 |
| 4400002  | 当调用键鼠穿越接口时穿越状态异常，系统会产生此错误码。               |

**示例**：

```js
try {
  inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId).then(() => {
    console.log(`Start Keyboard mouse crossing success.`);
  }, (error) => {
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.stop

stop(callback: AsyncCallback\<void>): void

停止键鼠穿越，使用AsyncCallback异步方式返回结果。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| callback             | AsyncCallback\<void>         |  是   | 回调函数，异步返回停止键鼠穿越结果。        |



**示例**：

```js
try {
  inputDeviceCooperate.stop((error) => {
    if (error) {
      console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Stop Keyboard mouse crossing success.`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.stop

stop(): Promise\<void>

停止键鼠穿越，使用Promise异步方式返回结果。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 说明                            |
| --------             | ----------------------------   |
| Promise\<void>       |  Promise对象，异步返回停止键鼠穿越结果。      | 

**示例**：

```js
try {
  inputDeviceCooperate.stop().then(() => {
    console.log(`Stop Keyboard mouse crossing success.`);
  }, (error) => {
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.getState

getState(deviceDescriptor: string, callback: AsyncCallback<{ state: boolean }>): void

获取键鼠穿越开关的状态，使用AsyncCallback异步方式返回结果。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填   | 说明                            |
| --------             | ---------                    | ----  | ----------------------------    |
| deviceDescriptor     | string                       |  是    | 键鼠穿越目标设备描述符。             |
| callback             | AsyncCallback<{ state: boolean }> |  是    | 回调函数，异步返回键鼠穿越开关状态。        |

**示例**：

```js
try {
  inputDeviceCooperate.getState(deviceDescriptor, (error, data) => {
    if (error) {
      console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputDeviceCooperate.getState

getState(deviceDescriptor: string): Promise<{ state: boolean }>

获取键鼠穿越开关的状态，使用Promise异步方式返回结果。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                          | 必填   | 说明                            |
| --------             | ---------                    | ----  | ----------------------------    |
| deviceDescriptor     | string                       |  是    | 键鼠穿越目标设备描述符。            |



**返回值**：

| 参数                        | 说明                     |
| -------------------        | ------------------------------- |
| Promise<{ state: boolean }>| Promise对象，异步返回键鼠穿越开关状态。        |



**示例**：

```js
try {
  inputDeviceCooperate.getState(deviceDescriptor).then((data) => {
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error) => {
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## on('cooperation')

on(type: 'cooperation', callback: AsyncCallback<{ deviceDescriptor: string, eventMsg: EventMsg }>): void

注册监听键鼠穿越状态。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                                                             | 必填 | 说明                            |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  是  | 注册类型，取值”cooperation“。         |
| callback             | AsyncCallback<{ deviceDescriptor: string, eventMsg: [EventMsg](#eventmsg) }> |  是  | 回调函数，异步返回键鼠穿越事件。    |



**示例**：

```js
try {
  inputDeviceCooperate.on('cooperation', (data) => {
    console.log(`Keyboard mouse crossing event: ${JSON.stringify(data)}`);
  });
} catch (err) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## off('cooperation')

off(type: 'cooperation', callback?: AsyncCallback\<void>): void

关闭监听键鼠穿越状态。

**系统能力**：SystemCapability.MultimodalInput.Input.InputDeviceCooperate

**参数**：

| 参数名                | 类型                                                              | 必填    | 说明                           |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  是    | 注册类型，取值“cooperation”。         |
| callback             | AsyncCallback<void> |  否  | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |



**示例**：

```js
// 取消注册单个回调函数
callback: function(event) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(event)}`);
  return false;
},
try {
  inputDeviceCooperate.on('cooperation', this.callback);
  inputDeviceCooperate.off("cooperation", this.callback);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
```js
// 取消注册所有回调函数
callback: function(event) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(event)}`);
  return false;
},
try {
  inputDeviceCooperate.on('cooperation', this.callback);
  inputDeviceCooperate.off("cooperation");
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
