# Input Monitor

The Input Monitor module implements listening for events of input devices (namely, touchscreen and mouse). 

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs provided by this module are system APIs.


## Modules to Import


```js
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
```


## inputMonitor.on

on(type: "touch", receiver: TouchEventReceiver): void

Enables listening for global touch events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                                      | Mandatory  | Description                 |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | Yes   | Type of the input device event. The value is **touch**.|
| receiver | [TouchEventReceiver](#toucheventreceiver) | Yes   | Callback used to return the touch event.|

**Example**

```js
try {
  inputMonitor.on("touch", (touchEvent) => {
    console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on<sup>9+</sup>

on(type: "mouse", receiver: Callback&lt;MouseEvent&gt;): void

Enables listening for global mouse events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Type of the input device event. The value is **mouse**.|
| receiver | Callback&lt;MouseEvent&gt; | Yes   | Callback used to return the mouse event. |

  **Example**

```js
try {
  inputMonitor.on("mouse", (mouseEvent) => {
    console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## inputMonitor.off

off(type: "touch", receiver?: TouchEventReceiver): void

Disables listening for global touch events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                                      | Mandatory  | Description                 |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | Yes   | Type of the input device event. The value is **touch**.|
| receiver | [TouchEventReceiver](#toucheventreceiver) | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application. |

**Example**

```js
// Disable listening for a single callback function.
function callback(touchEvent) {
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
  return false;
};
try {
  inputMonitor.on("touch", callback);
  inputMonitor.off("touch", callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callback functions.
function callback(touchEvent) {
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
  return false;
};
try {
  inputMonitor.on("touch", callback);
  inputMonitor.off("touch");
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off<sup>9+</sup>

off(type: "mouse", receiver?: Callback&lt;MouseEvent&gt;): void

Stops listening for global mouse events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Type of the input device event. The value is **mouse**.|
| receiver | Callback&lt;MouseEvent&gt; | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Example**

```js
// Disable listening for a single callback.
function callback(mouseEvent) {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
  return false;
};
try {
  inputMonitor.on("mouse", callback);
  inputMonitor.off("mouse", callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Disable listening for all callback functions.
function callback(mouseEvent) {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
  return false;
};
try {
  inputMonitor.on("mouse", callback);
  inputMonitor.off("mouse");
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## TouchEventReceiver

Represents the callback used to return the touch event.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name        | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](../arkui-js/js-components-common-events.md) | Yes   | Touch event.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| Boolean | Result indicating whether the touch event will be dispatched to the window. The value **true** indicates that the touch event will be dispatched to the window, and the value **false** indicates the opposite.|

**Example**

```js
try {
  inputMonitor.on("touch", touchEvent => {
    if (touchEvent.touches.length == 3) {// Three fingers are pressed.
      return true;
    } else {
      return false;
    }
  });
} catch (error) {
    console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
