# @ohos.multimodalInput.inputMonitor (Input Monitor)

The **inputMonitor** module implements listening for events of input devices, including the touchscreen, mouse, touchpad, etc.

>**NOTE**
>
>- The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>- The APIs provided by this module are system APIs.
>
>- In this document, **global** indicates the entire touchscreen or touchpad. For example, listening for global touch events means to listen for touch events of the entire touchpad when a user touches at any position on the touchpad.

## Modules to Import

```js
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
```

## inputMonitor.on('touch')

on(type: 'touch', receiver: TouchEventReceiver): void

Enables listening for global touch (touchscreen) events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                                      | Mandatory  | Description                 |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | Yes   | Event type. This field has a fixed value of **touch**.|
| receiver | [TouchEventReceiver](#toucheventreceiver) | Yes   | Callback used to return the touch event asynchronously.|

**Example**

```js
try {
  inputMonitor.on('touch', (touchEvent: TouchEvent) => {
    console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('mouse')<sup>9+</sup>

on(type: 'mouse', receiver: Callback&lt;MouseEvent&gt;): void

Enables listening for global mouse events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **mouse**.|
| receiver | Callback&lt;MouseEvent&gt; | Yes   | Callback used to return the mouse event asynchronously. |

  **Example**

```js
import { MouseEvent } from '@ohos.multimodalInput.mouseEvent';

try {
  inputMonitor.on('mouse', (mouseEvent: MouseEvent) => {
    console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('touch')

off(type: 'touch', receiver?: TouchEventReceiver): void

Disables listening for global touch (touchscreen) events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                                      | Mandatory  | Description                 |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | Yes   | Event type. This field has a fixed value of **touch**.|
| receiver | [TouchEventReceiver](#toucheventreceiver) | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application. |

**Example**

```js
// Disable listening for a single callback.
let callback = (touchEvent: TouchEvent) => {
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
  return false;
};
try {
  inputMonitor.on('touch', callback);
  inputMonitor.off('touch', callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
let callback = (touchEvent: TouchEvent) => {
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
  return false;
};
try {
  inputMonitor.on('touch', callback);
  inputMonitor.off('touch');
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('mouse')<sup>9+</sup>

off(type: 'mouse', receiver?: Callback&lt;MouseEvent&gt;): void

Disables listening for global mouse events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **mouse**.|
| receiver | Callback&lt;MouseEvent&gt; | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Example**

```js
// Disable listening for a single callback.
let callback = (mouseEvent: MouseEvent) => {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
  return false;
};
try {
  inputMonitor.on('mouse', callback);
  inputMonitor.off('mouse', callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
let callback = (mouseEvent: MouseEvent) => {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
  return false;
};
try {
  inputMonitor.on('mouse', callback);
  inputMonitor.off('mouse');
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## TouchEventReceiver

Defines the callback for touch (touchscreen) events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name        | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](./js-apis-touchevent.md) | Yes   | Touch event.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| Boolean | Result indicating whether the touch event will be dispatched to the window. The value **true** indicates that the touch event will be dispatched to the window, and the value **false** indicates the opposite.|

**Example**

```js
try {
  inputMonitor.on('touch', touchEvent => {
    if (touchEvent.touches.length == 3) {// Three fingers are pressed.
      return true;
    }
    return false;
  });
} catch (error) {
    console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('pinch')<sup>10+</sup>

on(type: 'pinch', receiver: Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt;): void

Enables listening for global touchpad pinch events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **pinch**.|
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | Yes   | Callback used to return the pinch event asynchronously. |

  **Example**

```js
try {
  inputMonitor.on('pinch', (pinchEvent) => {
    console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('pinch')<sup>10+</sup>

off(type: 'pinch', receiver?: Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt;): void

Disables listening for global touchpad pinch events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **pinch**.|
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Example**

```js
// Disable listening for a single callback.
import { Pinch } from '@ohos.multimodalInput.gestureEvent';

let callback = (pinchEvent: Pinch) => {
  console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
  return false;
};
try {
  inputMonitor.on('pinch', callback);
  inputMonitor.off('pinch', callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import { Pinch } from '@ohos.multimodalInput.gestureEvent';

let callback = (pinchEvent: Pinch) => {
  console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
  return false;
};
try {
  inputMonitor.on('pinch', callback);
  inputMonitor.off('pinch');
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('threeFingersSwipe')<sup>10+</sup>

on(type: 'threeFingersSwipe', receiver: Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt;): void

Enables listening for three-finger swipe events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **threeFingersSwipe**.|
| receiver | Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt; | Yes   | Callback used to return the three-finger swipe event asynchronously. |

  **Example**

```js
try {
  inputMonitor.on('threeFingersSwipe', (threeFingersSwipe) => {
    console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('threeFingersSwipe')<sup>10+</sup>

off(type: 'threeFingersSwipe', receiver?: Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt;): void

Disables listening for three-finger swipe events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **threeFingersSwipe**.|
| receiver | Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt; | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Example**

```js
// Disable listening for a single callback.
import { ThreeFingersSwipe } from '@ohos.multimodalInput.gestureEvent';

let callback = (threeFingersSwipe: ThreeFingersSwipe) => {
  console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
  return false;
};
try {
  inputMonitor.on('threeFingersSwipe', callback);
  inputMonitor.off("threeFingersSwipe", callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import { ThreeFingersSwipe } from '@ohos.multimodalInput.gestureEvent';

let callback = (threeFingersSwipe: ThreeFingersSwipe) => {
  console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
  return false;
};
try {
  inputMonitor.on("threeFingersSwipe", callback);
  inputMonitor.off("threeFingersSwipe");
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('fourFingersSwipe')<sup>10+</sup>

on(type: 'fourFingersSwipe', receiver: Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt;): void

Enables listening for four-finger swipe events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **fourFingersSwipe**.|
| receiver | Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt; | Yes   | Callback used to return the four-finger swipe event asynchronously. |

  **Example**

```js
try {
  inputMonitor.on('fourFingersSwipe', (fourFingersSwipe) => {
    console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('fourFingersSwipe')<sup>10+</sup>

off(type: 'fourFingersSwipe', receiver?: Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt;): void

Disables listening for four-finger swipe events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **fourFingersSwipe**.|
| receiver | Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt; | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Example**

```js
// Disable listening for a single callback.
import { FourFingersSwipe } from '@ohos.multimodalInput.gestureEvent';

let callback = (fourFingersSwipe: FourFingersSwipe) => {
  console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
  return false;
};
try {
  inputMonitor.on('fourFingersSwipe', callback);
  inputMonitor.off('fourFingersSwipe', callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import { FourFingersSwipe } from '@ohos.multimodalInput.gestureEvent';

let callback = (fourFingersSwipe: FourFingersSwipe) => {
  console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
  return false;
};
try {
  inputMonitor.on('fourFingersSwipe', callback);
  inputMonitor.off('fourFingersSwipe');
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
