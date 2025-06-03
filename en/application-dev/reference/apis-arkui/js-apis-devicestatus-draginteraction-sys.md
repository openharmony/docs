# @ohos.deviceStatus.dragInteraction (Drag Interaction) (System API)

The **dragInteraction** module provides the APIs to enable and disable listening for dragging status changes.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import { dragInteraction } from '@kit.ArkUI';
```

## DragState

Enumerates dragging states.

**System API**: This is a system API.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

| Name                 | Value  | Description          |
| --------------------- | ---- | -------------- |
| MSG_DRAG_STATE_START  | 1    | Dragging starts. |
| MSG_DRAG_STATE_STOP   | 2    | Dragging is ended. |
| MSG_DRAG_STATE_CANCEL | 3    | Dragging is canceled. |

## Summary<sup>11+</sup>

Defines the data summary of the dragged object.

**System API**: This is a system API.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

| Name      | Type    | Mandatory | Description              |
| ---------- | -------- | ---- | ------------------ |
| dataType   | string   | Yes  | Type of the dragged object.    |
| dataSize   | number   | Yes  | Data length of the dragged object. |

## dragInteraction.on('drag')

on(type: 'drag', callback: Callback\<DragState>): void

Enables listening for dragging status changes.

**System API**: This is a system API.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

**Parameters**

| Name  | Type                              | Mandatory | Description                            |
| -------- | ---------------------------------- | ---- | -------------------------------- |
| type     | string                             | Yes  | Event type. This field has a fixed value of **drag**.   |
| callback | Callback\<[DragState](#dragstate)> | Yes  | Callback used to return the dragging status. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
try {
  dragInteraction.on('drag', (data: dragInteraction.DragState) => {
    console.log(`Drag interaction event: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## dragInteraction.off('drag')

off(type: 'drag', callback?: Callback\<DragState>): void

Disables listening for dragging status changes.

**System API**: This is a system API.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

**Parameters**

| Name  | Type                              | Mandatory | Description                                                                  |
| -------- | ---------------------------------- | ---- | ---------------------------------------------------------------------- |
| type     | string                             | Yes  | Event type. This field has a fixed value of **drag**.                                         |
| callback | Callback\<[DragState](#dragstate)> | No  | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
// Unregister a single callback.
function single_callback(event: dragInteraction.DragState) {
  console.log(`Drag interaction event: ${JSON.stringify(event)}`);
  return false;
}
try {
  dragInteraction.on('drag', single_callback);
  dragInteraction.off("drag", single_callback);
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```ts
// Unregister all callbacks.
function all_callback(event: dragInteraction.DragState) {
  console.log(`Drag interaction event: ${JSON.stringify(event)}`);
  return false;
}
try {
  dragInteraction.on('drag', all_callback);
  dragInteraction.off("drag");
} catch (error) {
  console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## dragInteraction.getDataSummary<sup>11+</sup>

getDataSummary(): Array\<Summary>

Obtains the data summary of all dragged objects.

**System API**: This is a system API.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

**Return value**

| Type                         | Description                                                |
| ----------------------------- | ---------------------------------------------------- |
| Array\<[Summary](#summary11)> | Data summary of all dragged objects, including their type and data length. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |

**Example**

```ts
let summarys: Array<dragInteraction.Summary> = dragInteraction.getDataSummary();
console.log(`Drag interaction summarys: ${JSON.stringify(summarys)}`);
```

## dragInteraction.setDragSwitchState<sup>18+</sup>

setDragSwitchState(enabled: boolean): void

Sets the global drag-and-drop switch.

**System API**: This is a system API.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

**Parameters**

| Name  | Type                              | Mandatory| Description                                                                  |
| -------- | ---------------------------------- | ---- | ---------------------------------------------------------------------- |
| enabled  | boolean                            | Yes  | State of the drag-and-drop switch.<br>**false**: disabled; **true**: enabled.                                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |

**Example**

```ts
dragInteraction.setDragSwitchState(false);
```

## dragInteraction.setAppDragSwitchState<sup>18+</sup>

setAppDragSwitchState(enabled: boolean, bundleName: string): void

Sets the drag-and-drop switch for a specific application.

**System API**: This is a system API.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

**Parameters**

| Name     | Type                              | Mandatory| Description                                                                  |
| --------   | ---------------------------------- | ---- | ---------------------------------------------------------------------- |
| enabled    | boolean                            | Yes  | State of the drag-and-drop switch.<br>**false**: disabled; **true**: enabled.                                             |
| bundleName | string                             | Yes  | Bundle name of the target application.                                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```ts
dragInteraction.setAppDragSwitchState(true, "com.app.bundleName");
```
