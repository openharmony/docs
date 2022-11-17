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
try {
    inputMonitor.on("touch", (data)=> {
        console.info(`monitorOnTouchEvent success ${JSON.stringify(data)}`);
        return false;
    });
} catch (error) {
    console.info("onMonitor " + error.code + " " + error.message)
}
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
try {
    inputMonitor.on("mouse", (data)=> {
        console.info(`monitorOnMouseEvent success ${JSON.stringify(data)}`);
        return false;
    });
} catch (error) {
    console.info("onMonitor " + error.code + " " + error.message)
}
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
// Disable listening globally.
try {
    inputMonitor.off("touch");
} catch (error) {
    console.info("offMonitor " + error.code + " " + error.message)
}
// Disable listening for this receiver.
callback:function(data) {
    console.info(`call success ${JSON.stringify(data)}`);
},
try {
    inputMonitor.on("touch", this.callback);
} catch (error) {
    console.info("onTouchMonitor " + error.code + " " + error.message)
},
try {
    inputMonitor.off("touch",this.callback);
} catch (error) {
    console.info("offTouchMonitor " + error.code + " " + error.message)
}
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
// Disable listening globally.
try {
    inputMonitor.off("mouse");
} catch (error) {
    console.info("offMonitor " + error.code + " " + error.message)
}
// Disable listening for this receiver.
callback:function(data) {
    console.info(`call success ${JSON.stringify(data)}`);
},
try {
    inputMonitor.on("mouse", this.callback);
} catch (error) {
    console.info("onMouseMonitor " + error.code + " " + error.message)
},
try {
    inputMonitor.off("mouse", this.callback);
} catch (error) {
    console.info("offMouseMonitor " + error.code + " " + error.message)
}
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
try {
  inputMonitor.on("touch", (event) => {
    // If true is returned, all subsequent events of this operation will be consumed by the listener, instead of being distributed to the window.
    return false;
  });
  inputMonitor.off("touch");
} catch (error) {
  console.info("offMonitor " + error.code + " " + error.message)
}
```
