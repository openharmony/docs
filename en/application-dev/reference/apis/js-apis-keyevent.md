# Key Event

The Key Event module provides key events reported by an input device.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import {Action,Key,KeyEvent} from '@ohos.multimodalInput.keyEvent';
```

## Action

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| CANCEL | number | Yes| No| Cancellation of a key action.|
| DOWN | number | Yes| No| Pressing of a key.|
| UP | number | Yes| No| Release of a key.|

## Key

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| code | KeyCode | Yes| No| Keycode.|
| pressedTime | number | Yes| No| Time when the key is pressed.|
| deviceId | number | Yes| No| Device to which the key belongs.|

## KeyEvent

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| action | Action | Yes| No| Key action.|
| key | Key | Yes| No| Key that has changed.|
| unicodeChar | number | Yes| No| Unicode character corresponding to the key.|
| keys | Key[] | Yes| No| List of pressed keys.|
| ctrlKey | boolean | Yes| No| Whether ctrlKey is being pressed.|
| altKey | boolean | Yes| No| Whether altKey is being pressed.|
| shiftKey | boolean | Yes| No| Whether shiftKey is being pressed.|
| logoKey | boolean | Yes| No| Whether logoKey is being pressed.|
| fnKey | boolean | Yes| No| Whether fnKey is being pressed.|
| capsLock | boolean | Yes| No| Whether capsLock is active.|
| numLock | boolean | Yes| No| Whether numLock is active.|
| scrollLock | boolean | Yes| No| Whether scrollLock is active.|
