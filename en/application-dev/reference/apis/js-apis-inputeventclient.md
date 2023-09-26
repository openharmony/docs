# @ohos.multimodalInput.inputEventClient (Key Injection)

The **inputEventClient** module implements injection of key events.

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

Injects a key event. Currently, this API applies only to the **/KEYCODE_BACK** key (key value 2).

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

## KeyEvent

Represents information about the key event to inject.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

| Name       | Type  | Readable  | Writable  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| isPressed       | boolean | Yes   |  No| Whether the key is pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.  |
| keyCode         | number  | Yes   |  No| Keycode value. Currently, only the **KEYCODE_BACK** key is supported.|
| keyDownDuration | number  | Yes   |  No| Duration for pressing a key, in μs.          |
| isIntercepted   | boolean | Yes   |  No| Whether the key event can be intercepted.<br>The value **true** indicates that the key event can be intercepted, and the value **false** indicates the opposite.|
