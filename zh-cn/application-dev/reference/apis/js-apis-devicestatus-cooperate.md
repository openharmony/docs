# @ohos.cooperate (键鼠穿越)

键鼠穿越功能模块，提供两台或多台设备组网协同后键鼠共享能力，实现键鼠输入设备的跨设备协同操作。

> **说明**
>
>   - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 本模块接口均为系统接口。

## 导入模块

```js
import cooperate from '@ohos.cooperate'
```

## cooperate.prepare

prepare(callback: AsyncCallback&lt;void&gt;): void;

准备键鼠穿越，使用AsyncCallback异步方式返回结果。

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名    | 类型      | 必填  | 说明    |
| -------- | ------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;void&gt;  | 是 |回调函数，异步返回准备键鼠穿越的结果。   |

**示例**：

```js
try {
  cooperate.prepare((error) => {
    if (error) {
      console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing prepare success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.prepare

prepare(): Promise&lt;void&gt;

准备键鼠穿越，使用Promise异步方式返回结果。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值**：

| 参数                 | 说明                     |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | Promise对象，异步返回准备键鼠穿越的结果。 |



**示例**：

```js
try {
  cooperate.prepare().then(() => {
    console.log(`Keyboard mouse crossing prepare success.`);
  }, (error) => {
    console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.unprepare

unprepare(callback: AsyncCallback&lt;void&gt;): void;

取消键鼠穿越准备，使用AsyncCallback异步方式返回结果。

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

| 参数名   | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，异步返回取消准备键鼠穿越的结果。 |

**示例**：

```js
try {
  cooperate.unprepare((error) => {
    if (error) {
      console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing unprepare success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.unprepare

unprepare(): Promise&lt;void&gt;;

取消键鼠穿越准备，使用Promise异步方式返回结果。

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值**：

| 参数                | 说明                                          |
| ------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | Promise对象，异步返回取消准备键鼠穿越的结果。 |

```js
try {
  cooperate.unprepare().then(() => {
    console.log(`Keyboard mouse crossing unprepare success.`);
  }, (error) => {
    console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.activate

activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void;

启动键鼠穿越，使用AsyncCallback异步方式返回结果。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  是   | 键鼠穿越目标设备描述符。             |
| inputDeviceId | number                       |  是   | 待穿越输入设备标识符。 |
| callback             | AsyncCallback&lt;void&gt; |  是    | 回调函数，异步返回启动键鼠穿越的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](../errorcodes/errorcode-devicestatus.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 20900001 | 当调用键鼠穿越接口时穿越状态异常，系统会产生此错误码。                |

**示例**：

```js
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activate(targetNetworkId, inputDeviceId, (error) => {
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

## cooperate.activate

activate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;;

启动键鼠穿越，使用Promise异步方式返回结果。

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  是   | 键鼠穿越目标设备描述符。             |
| inputDeviceId | number                       |  是   | 待穿越输入设备标识符。 |



**返回值**：

| 参数名                  | 说明                             |
| ---------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，异步返回启动键鼠穿越结果。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](../errorcodes/errorcode-devicestatus.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 20900001 | 当调用键鼠穿越接口时穿越状态异常，系统会产生此错误码。               |

**示例**：

```js
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
 cooperate.activate(targetNetworkId, inputDeviceId).then(() => {
    console.log(`Start Keyboard mouse crossing success.`);
  }, (error) => {
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.deactivate

deactivate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void;

停止键鼠穿越，使用AsyncCallback异步方式返回结果。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| isUnchained | boolean | 是 | 是否关闭跨设备链路。 |
| callback             | AsyncCallback&lt;void&gt; |  是   | 回调函数，异步返回停止键鼠穿越的结果。       |



**示例**：

```js
try {
  cooperate.deactivate(false, (error) => {
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

## cooperate.deactivate

deactivate(isUnchained: boolean): Promise&lt;void&gt;;

停止键鼠穿越，使用Promise异步方式返回结果。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名      | 类型    | 必填 | 说明               |
| ----------- | ------- | ---- | ------------------ |
| isUnchained | boolean | 是   | 是否关闭跨设备链路 |



**返回值**：

| 参数名                | 说明                            |
| --------             | ----------------------------   |
| Promise&lt;void&gt; |  Promise对象，异步返回停止键鼠穿越结果。      |



**示例**：

```js
try {
  cooperate.deactivate(false).then(() => {
    console.log(`Stop Keyboard mouse crossing success.`);
  }, (error) => {
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.getCrossingSwitchState

getCrossingSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void;

获取目标设备键鼠穿越开关的状态，使用AsyncCallback异步方式返回结果。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填   | 说明                            |
| --------             | ---------                    | ----  | ----------------------------    |
| networkId | string                       |  是    | 键鼠穿越目标设备描述符。             |
| callback             | AsyncCallback&lt;boolean&gt; |  是    | 回调函数，异步返回目标设备的键鼠穿越开关状态 |

**示例**：

```js
let deviceDescriptor = "networkId";
try {
  cooperate.getCrossingSwitchState(deviceDescriptor, (error, data) => {
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

## cooperate.getCrossingSwitchState

getCrossingSwitchState(networkId: string): Promise&lt;boolean&gt;;

获取目标设备键鼠穿越开关的状态，使用Promise异步方式返回结果。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填   | 说明                            |
| --------             | ---------                    | ----  | ----------------------------    |
| networkId | string                       |  是    | 键鼠穿越目标设备描述符。            |



**返回值**：

| 参数                        | 说明                     |
| -------------------        | ------------------------------- |
| Promise&lt;boolean&gt; | Promise对象，异步返回目标设备的键鼠穿越开关状态 |



**示例**：

```js
let deviceDescriptor = "networkId";
try {
  cooperate.getCrossingSwitchState(deviceDescriptor).then((data) => {
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error) => {
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## on('cooperate')

on(type: 'cooperate', callback: Callback&lt;{ networkId: string, msg: CooperateMsg }&gt;): void;

注册监听键鼠穿越状态。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                                                             | 必填 | 说明                            |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  是  | 监听类型，取值为”cooperate“ |
| callback             | Callback&lt;{ networkId: string, msg: [CooperateMsg](#cooperatemsg) }&gt; |  是  | 回调函数，异步返回键鼠穿越状态消息 |



**示例**：

```js
try {
  cooperate.on('cooperate', (data) => {
    console.log(`Keyboard mouse crossing event: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## off('cooperate')

off(type: 'cooperate', callback?: Callback&lt;void&gt;): void;

取消监听键鼠穿越状态。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                                                              | 必填    | 说明                           |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  是    | 监听类型，取值为“cooperate” |
| callback             | AsyncCallback&lt;void&gt; |  否  | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |



**示例**：

```js
// 取消注册单个回调函数
function callback(event) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(event)}`);
  return false;
}
try {
  cooperate.on('cooperate', callback);
  cooperate.off("cooperate", callback);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
```js
// 取消注册所有回调函数
function callback(event) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(event)}`);
  return false;
}
try {
  cooperate.on('cooperate', callback);
  cooperate.off("cooperate");
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

##  CooperateMsg

键鼠穿越的消息通知。 

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

| 名称                       | 值                             | 说明                              |
| --------                     |  -----------------               |  -----------------               |
| COOPERATE_PREPARE |  0    |  表示准备键鼠穿越。   |
| COOPERATE_UNPREPARE |  1  |  表示取消键鼠穿越准备。  |
| COOPERATE_ACTIVATE |  2   |  表示启动键鼠穿越。  |
| COOPERATE_ACTIVATE_SUCCESS | 3 | 表示键鼠穿越启动成功。 |
| COOPERATE_ACTIVATE_FAIL | 4 | 表示键鼠穿越启动失败。 |
| COOPERATE_DEACTIVATE_SUCCESS | 5 | 表示键鼠穿越停止成功。 |
| COOPERATE_DEACTIVATE_FAIL | 6 | 表示键鼠穿越停止失败。 |
