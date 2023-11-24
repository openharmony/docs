# @ohos.cooperate (键鼠穿越)

键鼠穿越功能模块，提供两台或多台设备组网协同后键鼠共享能力，实现键鼠输入设备的跨设备协同操作。

> **说明**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口均为系统接口。

## 导入模块

```ts
import cooperate from '@ohos.cooperate'
```

## cooperate.prepareCooperate

prepareCooperate(callback: AsyncCallback&lt;void&gt;): void;

准备键鼠穿越，使用Callback异步回调。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，准备键鼠穿越成功时，err为undefined，否则为错误对象。 |

示例：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.prepareCooperate((error: BusinessError) => {
    if (error) {
      console.log(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing prepareCooperate success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.prepareCooperate

prepareCooperate(): Promise&lt;void&gt;;

准备键鼠穿越，使用Promise异步方式返回结果。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值：**

| 参数                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.prepareCooperate().then(() => {
    console.log(`Keyboard mouse crossing prepareCooperate success.`);
  }, (error: BusinessError) => {
    console.log(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.unprepareCooperate

unprepareCooperate(callback: AsyncCallback&lt;void&gt;): void;

取消键鼠穿越准备，使用Callback异步回调。

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，取消键鼠穿越准备成功时，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.unprepareCooperate((error: BusinessError) => {
    if (error) {
      console.log(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Keyboard mouse crossing unprepareCooperate success.`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.unprepareCooperate

unprepareCooperate(): Promise&lt;void&gt;;

取消键鼠穿越准备，使用Promise异步回调。

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值：**

| 参数                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.unprepareCooperate().then(() => {
    console.log(`Keyboard mouse crossing unprepareCooperate success.`);
  }, (error: BusinessError) => {
    console.log(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepareCooperate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.activateCooperate

activateCooperate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void;

启动键鼠穿越，使用Callback异步回调。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名          | 类型                      | 必填 | 说明                                                         |
| --------------- | ------------------------- | ---- | ------------------------------------------------------------ |
| targetNetworkId | string                    | 是   | 键鼠穿越目标设备描述符。                                     |
| inputDeviceId   | number                    | 是   |                                                              |
| callback        | AsyncCallback&lt;void&gt; | 是   | 回调函数，键鼠穿越启动成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/errorcodes/errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 20900001 | Operation failed. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activateCooperate(targetNetworkId, inputDeviceId, (error: BusinessError) => {
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

## cooperate.activateCooperate

activateCooperate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;;

启动键鼠穿越，使用Promise异步回调。

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名          | 类型   | 必填 | 说明                     |
| --------------- | ------ | ---- | ------------------------ |
| targetNetworkId | string | 是   | 键鼠穿越目标设备描述符。 |
| inputDeviceId   | number | 是   | 待穿越输入设备标识符。   |

**返回值：**

| 参数名              | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/errorcodes/errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 20900001 | Operation failed. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
 cooperate.activateCooperate(targetNetworkId, inputDeviceId).then(() => {
    console.log(`Start Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.deactivateCooperate

deactivateCooperate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void;

停止键鼠穿越，使用Callback异步回调。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名      | 类型                      | 必填 | 说明                                                         |
| ----------- | ------------------------- | ---- | ------------------------------------------------------------ |
| isUnchained | boolean                   | 是   | 是否关闭跨设备链路。 ture表示关闭跨设备链路，false表示不关闭。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数，键鼠穿越停止成功时，err为undefined，否则为错误对象。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.deactivateCooperate(false, (error: BusinessError) => {
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

## cooperate.deactivateCooperate

deactivateCooperate(isUnchained: boolean): Promise&lt;void&gt;;

停止键鼠穿越，使用Promise异步回调。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| isUnchained | boolean | 是   | 是否关闭跨设备链路。 ture表示关闭跨设备链路，false表示不关闭。 |

**返回值：**

| 参数名              | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.deactivateCooperate(false).then(() => {
    console.log(`Stop Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.getCooperateSwitchState

getCooperateSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void;

获取目标设备键鼠穿越开关的状态，使用Callback异步回调。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名    | 类型                         | 必填 | 说明                                                         |
| --------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| networkId | string                       | 是   | 键鼠穿越目标设备描述符。                                     |
| callback  | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
let deviceDescriptor = "networkId";
try {
  cooperate.getCooperateSwitchState(deviceDescriptor, (error: BusinessError, data: boolean) => {
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

## cooperate.getCooperateSwitchState

getCooperateSwitchState(networkId: string): Promise&lt;boolean&gt;;

获取目标设备键鼠穿越开关的状态，使用Promise异步方式返回结果。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名    | 类型   | 必填 | 说明                     |
| --------- | ------ | ---- | ------------------------ |
| networkId | string | 是   | 键鼠穿越目标设备描述符。 |

**返回值**：

| 参数                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
let deviceDescriptor = "networkId";
try {
  cooperate.getCooperateSwitchState(deviceDescriptor).then((data: boolean) => {
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error: BusinessError) => {
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## on('cooperateMessage')

on(type: 'cooperateMessage', callback: Callback&lt;CooperateMessage&gt;): void;

注册监听键鼠穿越状态。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                | 是   | 监听类型，取值为'cooperateMessage'   |
| callback | Callback&lt;[CooperateMessage](#cooperatemessage)&gt; | 是   | 回调函数，异步返回键鼠穿越状态消息。 |

**示例**：

```ts
function callback(msg: cooperate.CooperateMessage) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(msg)}`);
  return false;
}
try {
  cooperate.on('cooperateMessage', callback);
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## off('cooperateMessage')

off(type: 'cooperateMessage', callback?: Callback&lt;CooperateMessage&gt;): void;

取消监听键鼠穿越状态。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听类型，取值为'cooperate'。                                |
| callback | Callback&lt;[CooperateMessage](#cooperatemessage)&gt; | 否   | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |

**示例**：

```ts
// 取消注册单个回调函数
function callbackOn(msgOn: cooperate.CooperateMessage) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(msgOn)}`);
  return false;
}
function callbackOff(msgOff: cooperate.CooperateMessage) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(msgOff)}`);
  return false;
}
try {
  cooperate.on('cooperateMessage', callbackOn);
  cooperate.off('cooperateMessage', callbackOff);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```ts
// 取消注册所有回调函数
function callbackOn(msg: cooperate.CooperateMessage) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(msg)}`);
  return false;
}
try {
  cooperate.on('cooperateMessage', callbackOn);
  cooperate.off('cooperateMessage');
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## CooperateMessage

键鼠穿越的消息。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

| 参数名    | 类型           | 说明                     |
| --------- | -------------- | ------------------------ |
| networkId | string         | 键鼠穿越目标设备描述符。 |
| state     | CooperateState | 键鼠穿越的状态。         |



## CooperateState

键鼠穿越的状态。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

| 名称                           | 值   | 说明                   |
| ------------------------------ | ---- | ---------------------- |
| COOPERATE_PREPARE              | 0    | 表示准备键鼠穿越。     |
| COOPERATE_UNPREPARE            | 1    | 表示取消键鼠穿越准备。 |
| COOPERATE_ACTIVATE             | 2    | 表示启动键鼠穿越。     |
| COOPERATE_ACTIVATE_SUCCESS     | 3    | 表示键鼠穿越启动成功。 |
| COOPERATE_ACTIVATE_FAILURE     | 4    | 表示键鼠穿越启动失败。 |
| COOPERATE_DEACTIVATE_SUCCESS   | 5    | 表示键鼠穿越停止成功。 |
| COOPERATE_DEACTIVATE_FAILURE   | 6    | 表示键鼠穿越停止失败。 |
| COOPERATE_SESSION_DISCONNECTED | 7    | 表示键鼠穿越会话断开。 |



## cooperate.prepare<sup>(deprecated)</sup>

prepare(callback: AsyncCallback&lt;void&gt;): void;

准备键鼠穿越，使用Callback异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.prepareCooperate](#cooperatepreparecooperate)替代

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名    | 类型      | 必填  | 说明    |
| -------- | ------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;void&gt;  | 是 |回调函数，准备键鼠穿越成功时，err为undefined，否则为错误对象。   |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.prepare((error: BusinessError) => {
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

## cooperate.prepare<sup>(deprecated)</sup>

prepare(): Promise&lt;void&gt;;

准备键鼠穿越，使用Promise异步方式返回结果。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.prepareCooperate](#cooperatepreparecooperate-1)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值**：

| 参数                 | 说明                     |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | 无返回结果的Promise对象。 |



**示例**：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.prepare().then(() => {
    console.log(`Keyboard mouse crossing prepare success.`);
  }, (error: BusinessError) => {
    console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.unprepare<sup>(deprecated)</sup>

unprepare(callback: AsyncCallback&lt;void&gt;): void;

取消键鼠穿越准备，使用Callback异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.unprepareCooperate](#cooperateunpreparecooperate)替代

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

| 参数名   | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，取消键鼠穿越准备成功时，err为undefined，否则为错误对象。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.unprepare((error: BusinessError) => {
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

## cooperate.unprepare<sup>(deprecated)</sup>

unprepare(): Promise&lt;void&gt;;

取消键鼠穿越准备，使用Promise异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.unprepareCooperate](#cooperateunpreparecooperate-1)替代

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值**：

| 参数                | 说明                                          |
| ------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.unprepare().then(() => {
    console.log(`Keyboard mouse crossing unprepare success.`);
  }, (error: BusinessError) => {
    console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.activate<sup>(deprecated)</sup>

activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void;

启动键鼠穿越，使用Callback异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.activateCooperate](#cooperateactivatecooperate)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  是   | 键鼠穿越目标设备描述符。             |
| inputDeviceId | number                       |  是   | 待穿越输入设备标识符。 |
| callback             | AsyncCallback&lt;void&gt; |  是    | 回调函数，键鼠穿越启动成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](../errorcodes/errorcode-devicestatus.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 20900001 | Operation failed.|

**示例**：

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
  cooperate.activate(targetNetworkId, inputDeviceId, (error: BusinessError) => {
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

## cooperate.activate<sup>(deprecated)</sup>

activate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;;

启动键鼠穿越，使用Promise异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.activateCooperate](#cooperateactivatecooperate-1)替代

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  是   | 键鼠穿越目标设备描述符。             |
| inputDeviceId | number                       |  是   | 待穿越输入设备标识符。 |



**返回值**：

| 参数名                  | 说明                             |
| ---------------------- | ------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](../errorcodes/errorcode-devicestatus.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 20900001 | Operation failed.   |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
 cooperate.activate(targetNetworkId, inputDeviceId).then(() => {
    console.log(`Start Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.deactivate<sup>(deprecated)</sup>

deactivate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void;

停止键鼠穿越，使用Callback异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.deactivateCooperate](#cooperatedeactivatecooperate)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| isUnchained | boolean | 是 | 是否关闭跨设备链路。<br> ture表示关闭跨设备链路，false表示不关闭。 |
| callback     | AsyncCallback&lt;void&gt; |  是   | 回调函数，键鼠穿越停止成功时，err为undefined，否则为错误对象。|



**示例**：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.deactivate(false, (error: BusinessError) => {
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

## cooperate.deactivate<sup>(deprecated)</sup>

deactivate(isUnchained: boolean): Promise&lt;void&gt;;

停止键鼠穿越，使用Promise异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.deactivateCooperate](#cooperatedeactivatecooperate-1)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名      | 类型    | 必填 | 说明               |
| ----------- | ------- | ---- | ------------------ |
| isUnchained | boolean | 是   | 是否关闭跨设备链路。<br> ture表示关闭跨设备链路，false表示不关闭。 |



**返回值**：

| 参数名                | 说明                            |
| --------             | ----------------------------   |
| Promise&lt;void&gt; |  无返回结果的Promise对象。      |



**示例**：

```ts
import { BusinessError } from '@ohos.base';
try {
  cooperate.deactivate(false).then(() => {
    console.log(`Stop Keyboard mouse crossing success.`);
  }, (error: BusinessError) => {
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## cooperate.getCrossingSwitchState<sup>(deprecated)</sup>

getCrossingSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void;

获取目标设备键鼠穿越开关的状态，使用Callback异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.getCooperateSwitchState](#cooperategetcooperateswitchstate)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填   | 说明                            |
| --------             | ---------                    | ----  | ----------------------------    |
| networkId | string                       |  是    | 键鼠穿越目标设备描述符。             |
| callback             | AsyncCallback&lt;boolean&gt; |  是    | 回调函数，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
let deviceDescriptor = "networkId";
try {
  cooperate.getCrossingSwitchState(deviceDescriptor, (error: BusinessError, data: boolean) => {
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

## cooperate.getCrossingSwitchState<sup>(deprecated)</sup>

getCrossingSwitchState(networkId: string): Promise&lt;boolean&gt;;

获取目标设备键鼠穿越开关的状态，使用Promise异步方式返回结果。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.getCooperateSwitchState](#cooperategetcooperateswitchstate-1)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名    | 类型   | 必填   | 说明                            |
| --------   | ---------  | ----  | ----------------------------    |
| networkId | string     |  是    | 键鼠穿越目标设备描述符。            |



**返回值**：

| 参数                        | 说明                     |
| -------------------        | ------------------------------- |
| Promise&lt;boolean&gt; | Promise对象，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |



**示例**：

```ts
import { BusinessError } from '@ohos.base';
let deviceDescriptor = "networkId";
try {
  cooperate.getCrossingSwitchState(deviceDescriptor).then((data: boolean) => {
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);
  }, (error: BusinessError) => {
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## on('cooperate')<sup>(deprecated)</sup>

on(type: 'cooperate', callback: Callback&lt;{ networkId: string, msg: CooperateMsg }&gt;): void;

注册监听键鼠穿越状态。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[on('cooperateMessage')](#oncooperatemessage)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                                                             | 必填 | 说明                            |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  是  | 监听类型，取值为'cooperate' |
| callback             | Callback&lt;{ networkId: string, msg: [CooperateMsg](#cooperatemsg) }&gt; |  是  | 回调函数，异步返回键鼠穿越状态消息。 |



**示例**：

```ts
function callback(networkId: string, msg: cooperate.CooperateMsg) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);
  return false;
}
try {
  cooperate.on('cooperate', callback);
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## off('cooperate')<sup>(deprecated)</sup>

off(type: 'cooperate', callback?: Callback&lt;void&gt;): void;

取消监听键鼠穿越状态。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[off('cooperateMessage')](#offcooperatemessage)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                                                              | 必填    | 说明                           |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  是    | 监听类型，取值为'cooperate'。 |
| callback             | AsyncCallback&lt;void&gt; |  否  | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |



**示例**：

```ts
// 取消注册单个回调函数
function callbackOn(networkId: string, msg: cooperate.CooperateMsg) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);
  return false;
}
function callbackOff() {
  console.log(`Keyboard mouse crossing event`);
  return false;
}
try {
  cooperate.on('cooperate', callbackOn);
  cooperate.off('cooperate', callbackOff);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
```ts
// 取消注册所有回调函数
function callbackOn(networkId: string, msg: cooperate.CooperateMsg) {
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);
  return false;
}
try {
  cooperate.on('cooperate', callbackOn);
  cooperate.off('cooperate');
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



##  CooperateMsg<sup>(deprecated)</sup>

键鼠穿越的消息通知。 

> **说明：**
>
> 从API version 10开始不在维护。建议使用[CooperateMessage ](#cooperatestate )替代

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
| COOPERATE_SESSION_DISCONNECTED | 7 | 表示键鼠穿越会话断开。 |
