# @ohos.deviceStatus.dragInteraction (Drag Interaction)

 The **dragInteraction** module provides the APIs to enable and disable listening for dragging status changes.

> **NOTE**
>
>   - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import dragInteraction from '@ohos.deviceStatus.dragInteraction'
```

##  DragState

Enumerates dragging states.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

| Name                      | Value                            | Description                             |
| --------                     |  -----------------               |  -----------------               |
| MSG_DRAG_STATE_START |  1   | Dragging starts.|
| MSG_DRAG_STATE_STOP |  2  |  Dragging is ended. |
| MSG_DRAG_STATE_CANCEL |  3  |  Dragging is canceled. |

## dragInteraction.on('drag')

on(type: 'drag', callback: Callback&lt;DragState&gt;): void;

Enables listening for dragging status changes.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

**Parameters**

| Name               | Type                                                            | Mandatory| Description                           |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  Yes | Event type. This field has a fixed value of **drag**.|
| callback             | Callback&lt;[DragState](#dragstate)&gt; |  Yes | Callback used to return the dragging status.|

**Example**

```ts
enum DragState {
    MSG_DRAG_STATE_START = 1,
    MSG_DRAG_STATE_STOP = 2,
    MSG_DRAG_STATE_CANCEL = 3
}

try {
  dragInteraction.on('drag', (data : DragState) => {
    console.log(`Drag interaction event: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## dragInteraction.off('drag')

off(type: 'drag', callback?: Callback&lt;DragState&gt;): void;

Disables listening for dragging status changes.

**System capability**: SystemCapability.Msdp.DeviceStatus.Drag

**Parameters**

| Name               | Type                                                             | Mandatory   | Description                          |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  Yes   | Event type. This field has a fixed value of **drag**.|
| callback             | Callback&lt;[DragState](#dragstate)> |  No | Callback to be unregistered. If this parameter is not specified, all callbacks registered by the current application will be unregistered.|

**Example**

```ts
enum DragState {
    MSG_DRAG_STATE_START = 1,
    MSG_DRAG_STATE_STOP = 2,
    MSG_DRAG_STATE_CANCEL = 3
}

// Unregister a single callback.
function single_callback(event : DragState) {
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
enum DragState {
    MSG_DRAG_STATE_START = 1,
    MSG_DRAG_STATE_STOP = 2,
    MSG_DRAG_STATE_CANCEL = 3
}

// Unregister all callbacks.
function all_callback(event : DragState) {
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
