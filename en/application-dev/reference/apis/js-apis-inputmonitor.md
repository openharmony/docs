# Input Monitor

The Input Monitor module implements listening for global touch events.

> **NOTE**<br>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import


```js
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
```


## Required Permissions

ohos.permission.INPUT_MONITORING


## inputMonitor.on

on(type: "touch", receiver: TouchEventReceiver): void

Enables listening for global touch events.

This is a system API.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name    | Type                                     | Mandatory| Description                           |
| -------- | ----------------------------------------- | ---- | ------------------------------- |
| type     | string                                    | Yes  | Type of the input event to listen for. The value is **touch**.|
| receiver | [TouchEventReceiver](#toucheventreceiver) | Yes  | Callback used to return the touch event.         |

  **Example**

```js
inputMonitor.off("touch", (event) => {
  // A touch event is consumed.
  return false;
});
```

on(type: "mouse", receiver: Callback&lt;MouseEvent&gt;): void

Enables listening for global mouse events.

This is a system API.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name    | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| type     | string               | Yes  | Type of the input event to listen for. The value is **mouse**.|
| receiver | Callback&lt;MouseEvent&gt; | Yes  | Callback used to return the mouse event.         |

  **Example**

```js
inputMonitor.off("mouse", (event) => {
  // A mouse event is consumed.
});
```



## inputMonitor.off

off(type: "touch", receiver?: TouchEventReceiver): void

Stops listening for global touch events.

This is a system API.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name    | Type                                     | Mandatory| Description                           |
| -------- | ----------------------------------------- | ---- | ------------------------------- |
| type     | string                                    | Yes  | Type of the input event to listen for. The value is **touch**.|
| receiver | [TouchEventReceiver](#toucheventreceiver) | No  | Callback used to return the touch event.         |

  **Example**

```js
inputMonitor.off("touch");
```

off(type: "mouse", receiver?:Callback\<MouseEvent>):void

Stops listening for global mouse events.

This is a system API.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name    | Type                | Mandatory| Description                           |
| -------- | -------------------- | ---- | ------------------------------- |
| type     | string               | Yes  | Type of the input event to listen for. The value is **mouse**.|
| receiver | Callback&lt;MouseEvent&gt; | No  | Callback used to return the mouse event.         |

**Example**

```js
inputMonitor.off("mouse");
```



## TouchEventReceiver

Provides the callback of touch events.

This is a system API.

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name        | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](../arkui-js/js-components-common-events.md) | Yes   | Callback used to return the touch event.|

**Return value**

| Type     | Description                                    |
| ------- | -------------------------------------- |
| Boolean | Result indicating whether the touch event has been consumed by the input monitor. The value **true** indicates that the touch event has been consumed, and the value **false** indicates the opposite.|

  **Example**

```js
inputMonitor.on("touch", (event) => {
  // A touch event is consumed.
  return false;
});
inputMonitor.off("touch");
```
