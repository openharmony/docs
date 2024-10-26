# @ohos.multimodalInput.keyEvent (Key Event)

The **keyEvent** module provides key events reported by a device. It is inherited from [InputEvent](js-apis-inputevent.md).

>  **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { Action, Key, KeyEvent } from '@kit.InputKit';
```

## Action

Key event type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name  | Value | Description    |
| ------ | ------- | -------- |
| CANCEL | 0    | Cancellation of a key action.|
| DOWN   | 1    | Pressing of a key.|
| UP     | 2    | Release of a key.|

## Key

Defines a key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name       | Type| Readable| Writable| Description          |
| ----------- | -------- | ---- | ---- | -------------- |
| code        | [KeyCode](js-apis-keycode.md#keycode)  | Yes  | No  | Keycode.        |
| pressedTime | number   | Yes  | No  | Duration for pressing a key, in μs.|
| deviceId    | number   | Yes  | No  | ID of the device to which the key belongs.  |

## KeyEvent

Key event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name       | Type| Readable| Writable| Description                          |
| ----------- | -------- | ---- | ---- | ------------------------------ |
| action      | [Action](#action)   | Yes  | No  | Key action.                      |
| key         | [Key](#key)      | Yes  | No  | Key for which the event is reported.            |
| unicodeChar | number   | Yes  | No  | Unicode character corresponding to the key.         |
| keys        | [Key](#key) []    | Yes  | No  | List of pressed keys.    |
| ctrlKey     | boolean  | Yes  | No  | Whether ctrlKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.|
| altKey      | boolean  | Yes  | No  | Whether altKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.    |
| shiftKey    | boolean  | Yes  | No  | Whether shiftKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.  |
| logoKey     | boolean  | Yes  | No  | Whether logoKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.   |
| fnKey       | boolean  | Yes  | No  | Whether fnKey is being pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.     |
| capsLock    | boolean  | Yes  | No  | Whether capsLock is active.<br>The value **true** indicates that capsLock is active, and the value **false** indicates the opposite.  |
| numLock     | boolean  | Yes  | No  | Whether numLock is active.<br>The value **true** indicates that capsLock is active, and the value **false** indicates the opposite.   |
| scrollLock  | boolean  | Yes  | No  | Whether scrollLock is active.<br>The value **true** indicates that capsLock is active, and the value **false** indicates the opposite.|
