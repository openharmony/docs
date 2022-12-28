# Key Injection

The Key Injection module implements injection of key events.

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

Injects a key event. Currently, key injection is supported only for the **Back** key (key value 2).

**System capability**: SystemCapability.MultimodalInput.Input.InputSimulator

**Parameters**

| Name      | Type                   | Mandatory  | Description       |
| -------- | --------------------- | ---- | --------- |
| KeyEvent | [KeyEvent](#keyevent) | Yes   | Information about the key event to inject.|

**Example**

```js
try {
  let backKeyDown = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }
  inputEventClient.injectEvent({ KeyEvent: backKeyDown });

  let backKeyUp = {
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
| isPressed       | boolean | Yes   |  No| Whether the key is pressed.              |
| keyCode         | number  | Yes   |  No| Key value. Currently, only the **Back** key is supported.|
| keyDownDuration | number  | Yes   |  No| Duration within which the key is pressed.          |
| isIntercepted   | boolean | Yes   |  No| Whether the key can be intercepted.        |
