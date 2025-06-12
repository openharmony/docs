# @ohos.cooperate (键鼠穿越)（系统接口）

键鼠穿越功能模块，提供两台或多台设备组网协同后键鼠共享能力，实现键鼠输入设备的跨设备协同操作。

> **说明**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口均为系统接口。

## 导入模块

```ts
import cooperate from '@ohos.cooperate';
```

## cooperate.prepareCooperate<sup>11+</sup>

prepareCooperate(callback: AsyncCallback&lt;void&gt;): void;

准备键鼠穿越，使用Callback异步回调。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，准备键鼠穿越成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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

## cooperate.prepareCooperate<sup>11+</sup>

prepareCooperate(): Promise&lt;void&gt;;

准备键鼠穿越，使用Promise异步方式返回结果。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值：**

| 参数                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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



## cooperate.unprepareCooperate<sup>11+</sup>

unprepareCooperate(callback: AsyncCallback&lt;void&gt;): void;

取消键鼠穿越准备，使用Callback异步回调。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，取消键鼠穿越准备成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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

## cooperate.unprepareCooperate<sup>11+</sup>

unprepareCooperate(): Promise&lt;void&gt;;

取消键鼠穿越准备，使用Promise异步回调。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值：**

| 参数                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |

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



## cooperate.activateCooperate<sup>11+</sup>

activateCooperate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void;

启动键鼠穿越，使用Callback异步回调。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名          | 类型                      | 必填 | 说明                                                         |
| --------------- | ------------------------- | ---- | ------------------------------------------------------------ |
| targetNetworkId | string                    | 是   | 键鼠穿越目标设备描述符。                                     |
| inputDeviceId   | number                    | 是   | 待穿越输入设备标识符。                                       |
| callback        | AsyncCallback&lt;void&gt; | 是   | 回调函数，键鼠穿越启动成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status. |

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

## cooperate.activateCooperate<sup>11+</sup>

activateCooperate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;;

启动键鼠穿越，使用Promise异步回调。

**需要权限**：ohos.permission.COOPERATE_MANAGER

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

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status. |

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



## cooperate.deactivateCooperate<sup>11+</sup>

deactivateCooperate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void;

停止键鼠穿越，使用Callback异步回调。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名      | 类型                      | 必填 | 说明                                                         |
| ----------- | ------------------------- | ---- | ------------------------------------------------------------ |
| isUnchained | boolean                   | 是   | 是否关闭跨设备链路。 ture表示关闭跨设备链路，false表示不关闭。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数，键鼠穿越停止成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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

## cooperate.deactivateCooperate<sup>11+</sup>

deactivateCooperate(isUnchained: boolean): Promise&lt;void&gt;;

停止键鼠穿越，使用Promise异步回调。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| isUnchained | boolean | 是   | 是否关闭跨设备链路。 ture表示关闭跨设备链路，false表示不关闭。 |

**返回值：**

| 参数名              | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |

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



## cooperate.getCooperateSwitchState<sup>11+</sup>

getCooperateSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void;

获取目标设备键鼠穿越开关的状态，使用Callback异步回调。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名    | 类型                         | 必填 | 说明                                                         |
| --------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| networkId | string                       | 是   | 键鼠穿越目标设备描述符。                                     |
| callback  | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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

## cooperate.getCooperateSwitchState<sup>11+</sup>

getCooperateSwitchState(networkId: string): Promise&lt;boolean&gt;;

获取目标设备键鼠穿越开关的状态，使用Promise异步方式返回结果。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名    | 类型   | 必填 | 说明                     |
| --------- | ------ | ---- | ------------------------ |
| networkId | string | 是   | 键鼠穿越目标设备描述符。 |

**返回值**：

| 参数                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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



## on('cooperateMessage')<sup>11+</sup>

on(type: 'cooperateMessage', callback: Callback&lt;CooperateMessage&gt;): void;

注册监听键鼠穿越状态。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                | 是   | 监听类型，取值为'cooperateMessage'   |
| callback | Callback&lt;[CooperateMessage](#cooperatemessage11)&gt; | 是   | 回调函数，异步返回键鼠穿越状态消息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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



## off('cooperateMessage')<sup>11+</sup>

off(type: 'cooperateMessage', callback?: Callback&lt;CooperateMessage&gt;): void;

取消监听键鼠穿越状态。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听类型，取值为'cooperate'。                                |
| callback | Callback&lt;[CooperateMessage](#cooperatemessage11)&gt; | 否   | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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


## on('cooperateMouse')<sup>12+</sup>

on(type: 'cooperateMouse', networkId: string, callback: Callback&lt;MouseLocation&gt;): void;

注册监听指定设备鼠标光标位置。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                | 是   | 监听类型，取值为'cooperateMouse'   |
| networkId| string                                                | 是   | 目标设备描述符   |
| callback | Callback&lt;[MouseLocation](#mouselocation12)&gt; | 是   | 回调函数，异步返回指定监听设备鼠标光标位置信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**示例**：

```ts
function callback(data: cooperate.MouseLocation) {
  console.log('displayX:' + data.displayX + 'displayY:' + data.displayX + 'displayWidth:' +
    data.displayWidth + 'displayHeight:' + data.displayHeight );
}
try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callback);
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## off('cooperateMouse')<sup>12+</sup>

off(type: 'cooperateMouse', networkId: string, callback?: Callback&lt;MouseLocation&gt;): void;

取消监听指定设备鼠标光标位置。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听类型，取值为'cooperateMouse'。                                |
| networkId| string                                                | 是   | 目标设备描述符   |
| callback | Callback&lt;[MouseLocation](#mouselocation12)&gt; | 否   | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**示例**：

```ts
// 取消注册单个回调函数
function callbackOn(data: cooperate.MouseLocation) {
  console.log('Register mouse location listener');
  return false;
}
function callbackOff(data: cooperate.MouseLocation) {
  console.log('Unregister mouse location listener');
  return false;
}
try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callbackOn);
  cooperate.off('cooperateMouse', networkId, callbackOff);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```ts
// 取消注册所有回调函数
function callbackOn(data: cooperate.MouseLocation) {
  console.log('Register mouse location listener');
}
try {
  let networkId: string = 'Default';
  cooperate.on('cooperateMouse', networkId, callbackOn);
  cooperate.off('cooperateMouse', networkId);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## cooperate.activateCooperateWithOptions<sup>20+</sup>

activateCooperateWithOptions(targetNetworkId: string, inputDeviceId: number,
    cooperateOptions?: CooperateOptions ): Promise&lt;void&gt;

启动键鼠穿越，使用选项开始屏幕跳转。

**需要权限**：ohos.permission.COOPERATE_MANAGER

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名    | 类型   | 必填 | 说明                     |
| --------- | ------ | ---- | ------------------------ |
| targetNetworkId | string | 是   | 键鼠穿越目标设备描述符。 |
| inputDeviceId   | number | 是   |  发起穿越操作的输入设备ID。   |
|cooperateOptions | [CooperateOptions](#cooperateoptions20) | 否   | 穿越可选控制参数，控制穿出点位置。 |

**返回值：**

| 参数                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status. |

**示例**：

```ts
import { BusinessError } from '@ohos.base';
let targetNetworkId = "networkId";
let inputDeviceId = 0;
try {
 cooperate.activateCooperateWithOptions(targetNetworkId, inputDeviceId).then(() => {
    console.info(`activateCooperateWithOptions success.`);
  }, (error: BusinessError) => {
    console.error(`activateCooperateWithOptions, error: ${JSON.stringify(error, [`code`, `message`])}`);
  });
} catch (error) {
  console.error(`activateCooperateWithOptions, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


## CooperateMessage<sup>11+</sup>

键鼠穿越的消息。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

| 名称      | 类型           | 可读 | 可写 | 说明                     |
| --------- | -------------- | ---- | ---- | ------------------------ |
| networkId | string         | 是   | 否   | 键鼠穿越目标设备描述符。 |
| state     | CooperateState | 是   | 否   | 键鼠穿越的状态。         |


## MouseLocation<sup>12+</sup>

键鼠穿越的位置。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

| 名称           | 类型            | 可读 | 可写 | 说明                           |
| ---------      | -------------- | ---- | ---- | ------------------------       |
| displayX       | number         | 是   | 否   | 鼠标指针位于屏幕的X坐标上的位置。 |
| displayY       | number         | 是   | 否   | 鼠标指针位于屏幕的y坐标上的位置。 |
| displayWidth   | number         | 是   | 否   | 屏幕宽度，单位：px。                      |
| displayHeight  | number         | 是   | 否   | 屏幕高度，单位：px。                      |

## CooperateState<sup>11+</sup>

键鼠穿越的状态。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

| 名称                           | 类型    | 可读 | 可写 | 说明                   |
| ------------------------------ | ------ | ---- | ---- | ---------------------- |
| COOPERATE_PREPARE              | number | 是   | 否   | 表示准备键鼠穿越。     |
| COOPERATE_UNPREPARE            | number | 是   | 否   | 表示取消键鼠穿越准备。 |
| COOPERATE_ACTIVATE             | number | 是   | 否   | 表示启动键鼠穿越。     |
| COOPERATE_ACTIVATE_SUCCESS     | number | 是   | 否   | 表示键鼠穿越启动成功。 |
| COOPERATE_ACTIVATE_FAIL        | number | 是   | 否   | 表示键鼠穿越启动失败。 |
| COOPERATE_DEACTIVATE_SUCCESS   | number | 是   | 否   | 表示键鼠穿越停止成功。 |
| COOPERATE_DEACTIVATE_FAIL      | number | 是   | 否   | 表示键鼠穿越停止失败。 |
| COOPERATE_SESSION_DISCONNECTED | number | 是   | 否   | 表示键鼠穿越会话断开。 |
| COOPERATE_ACTIVATE_FAILURE     | number | 是   | 否   | 表示键鼠穿越无法启动。 |
| COOPERATE_DEACTIVATE_FAILURE   | number | 是   | 否   | 表示键鼠穿越无法停止。 |


## MouseLocation<sup>12+</sup>

鼠标光标位置信息。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

| 名称           | 类型           | 可读 | 可写 | 说明                     |
| ---------     | -------------- | ---- | ---- | ------------------------ |
| displayX      | number         | 是   | 否   | 鼠标X坐标位置。 |
| displayY      | number         | 是   | 否   | 鼠标Y坐标位置。 |
| displayWidth  | number         | 是   | 否   | 鼠标所在屏幕宽度，单位：px。 |
| displayHeight | number         | 是   | 否   | 鼠标所在屏幕高度，单位：px。 |


## CooperateOptions<sup>20+</sup>

 键鼠穿越可选控制参数，控制穿出点位置。

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

| 名称      | 类型           | 只读 | 可选 | 说明                     |
| --------- | -------------- | ---- | ---- | ------------------------ |
| displayX      | number         | 否   | 否   | 鼠标X坐标位置。 |
| displayY      | number         | 否   | 否   | 鼠标Y坐标位置。 |
| displayId     | number         | 否   | 否   | 对端设备屏幕标识。 |

## cooperate.prepare<sup>(deprecated)</sup>

prepare(callback: AsyncCallback&lt;void&gt;): void;

准备键鼠穿越，使用Callback异步回调。

> **说明：**
>
> 从API version 10开始不在维护。建议使用[cooperate.prepareCooperate](#cooperatepreparecooperate11)替代

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名    | 类型      | 必填  | 说明    |
| -------- | ------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;void&gt;  | 是 |回调函数，准备键鼠穿越成功时，err为undefined，否则为错误对象。   |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[cooperate.prepareCooperate](#cooperatepreparecooperate11-1)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值**：

| 参数                 | 说明                     |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[cooperate.unprepareCooperate](#cooperateunpreparecooperate11)替代

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

| 参数名   | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，取消键鼠穿越准备成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[cooperate.unprepareCooperate](#cooperateunpreparecooperate11-1)替代

**系统能力**: SystemCapability.Msdp.DeviceStatus.Cooperate

**返回值**：

| 参数                | 说明                                          |
| ------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[cooperate.activateCooperate](#cooperateactivatecooperate11)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| targetNetworkId | string                       |  是   | 键鼠穿越目标设备描述符。             |
| inputDeviceId | number                       |  是   | 待穿越输入设备标识符。 |
| callback             | AsyncCallback&lt;void&gt; |  是    | 回调函数，键鼠穿越启动成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[cooperate.activateCooperate](#cooperateactivatecooperate11-1)替代

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

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 20900001 | Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status.|
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[cooperate.deactivateCooperate](#cooperatedeactivatecooperate11)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填  | 说明                            |
| --------             | ---------------------------- | ----  | ----------------------------   |
| isUnchained | boolean | 是 | 是否关闭跨设备链路。<br> ture表示关闭跨设备链路，false表示不关闭。 |
| callback     | AsyncCallback&lt;void&gt; |  是   | 回调函数，键鼠穿越停止成功时，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[cooperate.deactivateCooperate](#cooperatedeactivatecooperate11-1)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名      | 类型    | 必填 | 说明               |
| ----------- | ------- | ---- | ------------------ |
| isUnchained | boolean | 是   | 是否关闭跨设备链路。<br> ture表示关闭跨设备链路，false表示不关闭。 |



**返回值**：

| 参数名                | 说明                            |
| --------             | ----------------------------   |
| Promise&lt;void&gt; |  无返回结果的Promise对象。      |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |

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
> 从API version 10开始不在维护。建议使用[cooperate.getCooperateSwitchState](#cooperategetcooperateswitchstate11)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                          | 必填   | 说明                            |
| --------             | ---------                    | ----  | ----------------------------    |
| networkId | string                       |  是    | 键鼠穿越目标设备描述符。             |
| callback             | AsyncCallback&lt;boolean&gt; |  是    | 回调函数，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[cooperate.getCooperateSwitchState](#cooperategetcooperateswitchstate11-1)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名    | 类型   | 必填   | 说明                            |
| --------   | ---------  | ----  | ----------------------------    |
| networkId | string     |  是    | 键鼠穿越目标设备描述符。            |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[on('cooperateMessage')](#oncooperatemessage11)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                                                             | 必填 | 说明                            |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  是  | 监听类型，取值为'cooperate' |
| callback             | Callback&lt;{ networkId: string, msg: [CooperateMsg](#cooperatemsgdeprecated) }&gt; |  是  | 回调函数，异步返回键鼠穿越状态消息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[off('cooperateMessage')](#offcooperatemessage11)替代

**系统能力**：SystemCapability.Msdp.DeviceStatus.Cooperate

**参数**：

| 参数名                | 类型                                                              | 必填    | 说明                           |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  是    | 监听类型，取值为'cooperate'。 |
| callback             | AsyncCallback&lt;void&gt; |  否  | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.devicestatus错误码](errorcode-devicestatus.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

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
> 从API version 10开始不在维护。建议使用[CooperateMessage](#cooperatemessage11)替代

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
