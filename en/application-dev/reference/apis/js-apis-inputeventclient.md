# Key Injection

The Key Injection module implements injection of key events.

> **NOTE**<br>
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import


```js
import inputEventClient from '@ohos.multimodalInput.inputEventClient';
```


## inputEventClient.injectEvent

injectEvent({KeyEvent: KeyEvent}): void

Injects a key event.

This is a system API.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| KeyEvent | [KeyEvent](#keyevent) | Yes   | Information about the key event to inject.|

**Example**

```js
try {
  var keyEvent = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }
  inputEventClient.injectKeyEvent({ KeyEvent: keyEvent });
  var keyEvent1 = {
    isPressed: false,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  };
  inputEventClient.injectKeyEvent({ KeyEvent: keyEvent1 });
} catch (error) {
  console.info("injectKeyEvent " + error.code + " " + error.message);
}
```


## KeyEvent

Defines the information about the key event to inject.

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

**Parameters**

| Name             | Type     | Mandatory  | Description       |
| --------------- | ------- | ---- | --------- |
| isPressed       | boolean | Yes   | Whether the key is pressed.   |
| keyCode         | number  | Yes   | Key code.     |
| keyDownDuration | number  | Yes   | Duration within which the key is pressed. |
| isIntercepted   | boolean | Yes   | Whether the key can be intercepted.|
