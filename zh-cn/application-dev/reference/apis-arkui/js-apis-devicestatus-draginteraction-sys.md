# @ohos.deviceStatus.dragInteraction（拖拽)(系统接口)

拖拽功能模块，提供注册和取消拖拽状态监听的能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口均为系统接口。

## 导入模块

```js
import { dragInteraction } from '@kit.ArkUI'
```

## DragState

拖拽状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Msdp.DeviceStatus.Drag

| 名称                  | 值   | 说明           |
| --------------------- | ---- | -------------- |
| MSG_DRAG_STATE_START  | 1    | 表示开始拖拽。 |
| MSG_DRAG_STATE_STOP   | 2    | 表示结束拖拽。 |
| MSG_DRAG_STATE_CANCEL | 3    | 表示取消拖拽。 |

## Summary<sup>11+</sup>

拖拽对象的数据摘要。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Msdp.DeviceStatus.Drag

| 名称       | 类型     | 必填 | 说明               |
| ---------- | -------- | ---- | ------------------ |
| dataType   | string   | 是   | 拖拽对象类型。     |
| dataSize   | number   | 是   | 拖拽对象数据长度。 |

## dragInteraction.on('drag')

on(type: 'drag', callback: Callback\<DragState>): void

注册监听拖拽状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Msdp.DeviceStatus.Drag

**参数：**

| 参数名   | 类型                               | 必填 | 说明                             |
| -------- | ---------------------------------- | ---- | -------------------------------- |
| type     | string                             | 是   | 监听类型，固定取值为 'drag'。    |
| callback | Callback\<[DragState](#dragstate)> | 是   | 回调函数，异步返回拖拽状态消息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**示例：**

```ts
try {
  dragInteraction.on('drag', (data: dragInteraction.DragState) => {
    console.log(`Drag interaction event: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## dragInteraction.off('drag')

off(type: 'drag', callback?: Callback\<DragState>): void

取消监听拖拽状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Msdp.DeviceStatus.Drag

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                                   |
| -------- | ---------------------------------- | ---- | ---------------------------------------------------------------------- |
| type     | string                             | 是   | 监听类型，固定取值为 'drag'。                                          |
| callback | Callback\<[DragState](#dragstate)> | 否   | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**示例：**

```ts
// 取消注册单个回调函数
function single_callback(event: dragInteraction.DragState) {
  console.log(`Drag interaction event: ${JSON.stringify(event)}`);
  return false;
}
try {
  dragInteraction.on('drag', single_callback);
  dragInteraction.off("drag", single_callback);
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```ts
// 取消注册所有回调函数
function all_callback(event: dragInteraction.DragState) {
  console.log(`Drag interaction event: ${JSON.stringify(event)}`);
  return false;
}
try {
  dragInteraction.on('drag', all_callback);
  dragInteraction.off("drag");
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## dragInteraction.getDataSummary<sup>11+</sup>

getDataSummary(): Array\<Summary>

获取所有拖拽对象的摘要。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Msdp.DeviceStatus.Drag

**返回值：**

| 类型                          | 说明                                                 |
| ----------------------------- | ---------------------------------------------------- |
| Array\<[Summary](#summary11)> | 所有拖拽对象的数据摘要，包含拖拽对象的类型和数据长度。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |

**示例：**

```ts
let summarys: Array<dragInteraction.Summary> = dragInteraction.getDataSummary();
console.log(`Drag interaction summarys: ${JSON.stringify(summarys)}`);
```

## dragInteraction.setDragSwitchState<sup>14+</sup>

setDragSwitchState(enabled: boolean): void

控制统一拖拽功能总开关。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Msdp.DeviceStatus.Drag

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                                   |
| -------- | ---------------------------------- | ---- | ---------------------------------------------------------------------- |
| enabled  | boolean                            | 是   | 设置开关状态。<br>false：关闭，true：开启。                                              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**示例：**

```ts
dragInteraction.setDragSwitchState(false);
```

## dragInteraction.setAppDragSwitchState<sup>14+</sup>

setAppDragSwitchState(enabled: boolean, bundleName: string): void

控制统一拖拽适配应用开关。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Msdp.DeviceStatus.Drag

**参数：**

| 参数名      | 类型                               | 必填 | 说明                                                                   |
| --------   | ---------------------------------- | ---- | ---------------------------------------------------------------------- |
| enabled    | boolean                            | 是   | 设置开关状态。<br>false：关闭，true：开启。                                              |
| bundleName | string                             | 是   | 设置指定应用包名开关状态。                                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**示例：**

```ts
dragInteraction.setAppDragSwitchState(true, "com.app.bundleName");
```