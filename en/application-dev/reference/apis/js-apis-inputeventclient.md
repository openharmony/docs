# @ohos.multimodalInput.inputEventClient (Device Injection)

The **inputEventClient** module provides the device injection capability.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import inputEventClient from '@ohos.multimodalInput.inputEventClient';
```

## inputEventClient.injectEvent

injectEvent({KeyEvent: KeyEvent}): void

Injects keys (including single keys and combination keys).

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| KeyEvent | [KeyEvent](#keyevent) | Yes   | Information about the key event to inject.|

**Example**

```js
try {
  let backKeyDown: inputEventClient.KeyEvent = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }
  inputEventClient.injectEvent({ KeyEvent: backKeyDown });

  let backKeyUp: inputEventClient.KeyEvent = {
    isPressed: false,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  };
  inputEventClient.injectEvent({ KeyEvent: backKeyUp });
} catch (error) {
  console.log(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
## inputEventClient.injectMouseEvent<sup>11+</sup>

injectMouseEvent({mouseEvent: MouseEvent}): void;

Injects a mouse/touchpad event.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| mouseEvent | [MouseEvent](../apis/js-apis-mouseevent.md) | Yes   | Mouse/touchpad event to inject.|

**Example**

```js
try {
  let mouseButtonUp = {
      action: 2,
      screenX: 200,
      screenY: 620,
      button: 0,
      toolType: 1,
  }
  inputEventClient.injectMouseEvent({ mouseEvent: mouseButtonUp });

  let mouseButtonDown = {
      action: 3,
      screenX: 200,
      screenY: 620,
      button: 0,
      toolType: 1,
  };
  inputEventClient.injectMouseEvent({ mouseEvent: mouseButtonDown });
} catch (error) {
  console.log(`Failed to inject MouseEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputEventClient.injectTouchEvent<sup>11+</sup>

injectTouchEvent({touchEvent: TouchEvent}): void;

Injects a touchscreen event.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| touchEvent | [TouchEvent](../apis/js-apis-touchevent.md) | Yes   | Touchscreen event to inject.|

**Example**

```js
try {
  let touchEventUp = {
      action: 1,
      sourceType: 0,
      screenX: 200,
      screenY: 620,
      pressedTime: 0,
  };
  inputEventClient.injectTouchEvent({ touchEvent: touchEventUp });

  let touchEventDown = {
      action: 3,
      sourceType: 0,
      screenX: 200,
      screenY: 620,
      pressedTime: 0,
  };
    inputEventClient.injectTouchEvent({ touchEvent: touchEventDown });
} catch (error) {
    console.log(`Failed to inject touchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## KeyEvent

Represents the key event to inject.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| isPressed       | boolean | Yes   |  No| Whether the key is pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.  |
| keyCode         | number  | Yes   |  No| Keycode value. Currently, only the **KEYCODE_BACK** key is supported.|
| keyDownDuration | number  | Yes   |  No| Duration for pressing a key, in μs.          |
| isIntercepted   | boolean | Yes   |  No| Whether the key event can be intercepted.<br>The value **true** indicates that the key event can be intercepted, and the value **false** indicates the opposite.|
