# @ohos.multimodalInput.inputEventClient (Input Event Injection) (System API)

The **inputEventClient** module implements the input event injection capability.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import { inputEventClient } from '@kit.InputKit';
```

## inputEventClient.injectEvent

injectEvent({KeyEvent: KeyEvent}): void

Injects keys (including single keys and combination keys).

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

Permission required: ohos.permission.INJECT_INPUT_EVENT

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| KeyEvent | [KeyEvent](#keyevent) | Yes   | Key event to inject.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  let backKeyDown: inputEventClient.KeyEvent = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }

  class EventDown {
    KeyEvent: inputEventClient.KeyEvent | null = null
  }

  let eventDown: EventDown = { KeyEvent: backKeyDown }
  inputEventClient.injectEvent(eventDown);

  let backKeyUp: inputEventClient.KeyEvent = {
    isPressed: false,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  };

  class EventUp {
    KeyEvent: inputEventClient.KeyEvent | null = null
  }

  let eventUp: EventUp = { KeyEvent: backKeyUp }
  inputEventClient.injectEvent(eventUp);
} catch (error) {
  console.log(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputEventClient.injectKeyEvent<sup>11+</sup>

injectKeyEvent(keyEvent: KeyEventData): void

Injects key events (for both single keys and combination keys).

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

Permission required: ohos.permission.INJECT_INPUT_EVENT

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| keyEvent | [KeyEventData](#keyeventdata11) | Yes   | Key event to inject.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  let backKeyDown: inputEventClient.KeyEvent = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }

  class EventDown {
    keyEvent: inputEventClient.KeyEvent | null = null
  }

  let eventDown: EventDown = { keyEvent: backKeyDown }
  inputEventClient.injectKeyEvent(eventDown);

  let backKeyUp: inputEventClient.KeyEvent = {
    isPressed: false,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  };

  class EventUp {
    keyEvent: inputEventClient.KeyEvent | null = null
  }

  let eventUp: EventUp = { keyEvent: backKeyUp }
  inputEventClient.injectKeyEvent(eventUp);
} catch (error) {
  console.log(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
## inputEventClient.injectMouseEvent<sup>11+</sup>

injectMouseEvent(mouseEvent: MouseEventData): void

Injects a mouse/touchpad event.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

Permission required: ohos.permission.INJECT_INPUT_EVENT

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| mouseEvent | [MouseEventData](#mouseeventdata11) | Yes   | Mouse/touchpad event to inject.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { MouseEvent } from '@kit.InputKit';

try {
  let mouseButtonUpData: MouseEvent = {
    id: 0,
    deviceId: 1,
    actionTime: 2,
    screenId: 1,
    windowId: 0,
    action: 3,
    screenX: 100,
    screenY: 200,
    windowX: 100,
    windowY: 200,
    rawDeltaX: 200,
    rawDeltaY: 200,
    button: 2,
    pressedButtons: [2],
    axes: [],
    pressedKeys: [0],
    ctrlKey: false,
    altKey: false,
    shiftKey: false,
    logoKey: false,
    fnKey: false,
    capsLock: false,
    numLock: false,
    scrollLock: false,
    toolType: 1,
  }
  let mouseButtonUp: inputEventClient.MouseEventData = {
    mouseEvent: mouseButtonUpData
  }
  inputEventClient.injectMouseEvent(mouseButtonUp);

  let mouseButtonDownData: MouseEvent = {
    id: 0,
    deviceId: 1,
    actionTime: 2,
    screenId: 1,
    windowId: 0,
    action: 2,
    screenX: 100,
    screenY: 200,
    windowX: 100,
    windowY: 200,
    rawDeltaX: 200,
    rawDeltaY: 200,
    button: 2,
    pressedButtons: [2],
    axes: [],
    pressedKeys: [0],
    ctrlKey: false,
    altKey: false,
    shiftKey: false,
    logoKey: false,
    fnKey: false,
    capsLock: false,
    numLock: false,
    scrollLock: false,
    toolType: 1,
  }
  let mouseButtonDown: inputEventClient.MouseEventData = {
    mouseEvent: mouseButtonDownData
  };
  inputEventClient.injectMouseEvent(mouseButtonDown);
}

catch (error) {
  console.log(`Failed to inject MouseEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}

```

## inputEventClient.injectTouchEvent<sup>11+</sup>

injectTouchEvent(touchEvent: TouchEventData): void

Injects a touchscreen event.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

Permission required: ohos.permission.INJECT_INPUT_EVENT

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| touchEvent | [TouchEventData](#toucheventdata11) | Yes   | Touchscreen event to inject.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { Touch, TouchEvent } from '@kit.InputKit';

try {
  let touchEvent: Touch = {
    id: 1,
    pressedTime: 1,
    screenX: 0,
    screenY: 0,
    windowX: 0,
    windowY: 0,
    pressure: 0,
    width: 0,
    height: 0,
    tiltX: 0,
    tiltY: 0,
    toolX: 0,
    toolY: 0,
    toolWidth: 0,
    toolHeight: 0,
    rawX: 0,
    rawY: 0,
    toolType: 0,
  }

  let touchEventUpData: TouchEvent = {
    action: 1,
    sourceType: 0,
    touch: touchEvent,
    touches: [],
    id: 0,
    deviceId: 0,
    actionTime: 0,
    screenId: 0,
    windowId: 0
  }
  ;
  let touchEventUp: inputEventClient.TouchEventData = {
    touchEvent: touchEventUpData
  }
  inputEventClient.injectTouchEvent(touchEventUp);

  let touchEventDownData: TouchEvent = {
    action: 1,
    sourceType: 0,
    touch: touchEvent,
    touches: [],
    id: 0,
    deviceId: 0,
    actionTime: 0,
    screenId: 0,
    windowId: 0
  }
  ;
  let touchEventDown: inputEventClient.TouchEventData = {
    touchEvent: touchEventDownData
  }
  inputEventClient.injectTouchEvent(touchEventDown);
} catch (error) {
  console.log(`Failed to inject touchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputEventClient.permitInjection<sup>12+</sup>

permitInjection(result: boolean): void

Specifies whether to authorize event injection.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

Permission required: ohos.permission.INJECT_INPUT_EVENT

**Parameters**

| Name   | Type   | Mandatory  | Description       |
| -------- | ------  | ----   | --------- |
| result   | boolean | Yes    | Authorization result. The value **true** indicates that event injection is allowed, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |


```ts
import { inputEventClient } from '@kit.InputKit';

try {
  let result = true;
  inputEventClient.permitInjection(result);
}catch(error){
  console.error("failed:" + JSON.stringify(error));
}
```

## KeyEvent

Defines the key event to inject.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| isPressed       | boolean | Yes   |  No| Whether the key is pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.  |
| keyCode         | number  | Yes   |  No| Keycode value. Currently, only the **KEYCODE_BACK** key is supported.|
| keyDownDuration | number  | Yes   |  No| Duration for pressing a key, in μs.          |
| isIntercepted   | boolean | Yes   |  No| Whether the key event can be intercepted.<br>The value **true** indicates that the key event can be intercepted, and the value **false** indicates the opposite.|

## KeyEventData<sup>11+</sup>

Defines the key event to inject.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

| Name       | Type  | Mandatory  | Description     |
| --------- | ------ | ---- |  ------- |
| keyEvent | [KeyEvent](#keyevent) | Yes   | Key event to inject.  |

## MouseEventData<sup>11+</sup>

Defines the mouse event data.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| mouseEvent | [MouseEvent](js-apis-mouseevent.md#mouseevent) | Yes   |  No| Mouse event data.  |

## TouchEventData<sup>11+</sup>

Defines the touchscreen event data.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| touchEvent | [TouchEvent](js-apis-touchevent.md#touchevent) | Yes   |  No| Touchscreen event data  |
