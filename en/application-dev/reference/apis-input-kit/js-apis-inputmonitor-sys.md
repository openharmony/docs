# @ohos.multimodalInput.inputMonitor (Input Monitor) (System API)

The **inputMonitor** module implements listening for events of input devices, including the touchscreen, mouse, touchpad, etc.

>**NOTE**
>
>- The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>- In this document, **global** indicates the entire touchscreen or touchpad. For example, listening for global touch events means to listen for touch events of the entire touchpad when a user touches at any position on the touchpad.
>
>- The APIs provided by this module are system APIs.

## Modules to Import

```js
import { inputMonitor } from '@kit.InputKit';
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
| receiver | [TouchEventReceiver](#toucheventreceiver) | Yes   | Callback used to return touch events asynchronously.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { TouchEvent } from '@kit.InputKit';
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
| receiver | Callback&lt;[MouseEvent](js-apis-mouseevent.md#mouseevent)&gt; | Yes   | Callback used to return mouse events asynchronously. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { MouseEvent } from '@kit.InputKit';

try {
  inputMonitor.on('mouse', (mouseEvent: MouseEvent) => {
    console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('mouse')<sup>11+</sup>

on(type: 'mouse', rect: display.Rect[], receiver: Callback&lt;MouseEvent&gt;): void

Enables listening for mouse events. When the mouse pointer moves to the specified rectangular area, a callback is triggered.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **mouse**.|
| rect     | display.Rect[]             | Yes   | Rectangular area where a callback is triggered. One or two rectangular areas can be specified.|
| receiver | Callback&lt;[MouseEvent](js-apis-mouseevent.md#mouseevent)&gt; | Yes   | Callback used to return mouse events asynchronously. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { MouseEvent } from '@kit.InputKit';
import { promptAction } from '@kit.ArkUI';
import { display } from '@kit.ArkUI';

/**
 * Callback triggered when the mouse pointer moves to the specified rectangular area.
 */
function callback(mouseEvent : MouseEvent) {
  promptAction.showToast({
    message: `Monitor on success: ${JSON.stringify(mouseEvent)}`
  })
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
  return false;
};

/**
 * Rectangular area where a callback is triggered.
 */
let rect: display.Rect[] = [{
  left: 100,
  top: 100,
  width: 100,
  height: 100
}, {
  left: 600,
  top: 100,
  width: 100,
  height: 100
}];

try {
  inputMonitor.on('mouse', rect, callback);
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { TouchEvent } from '@kit.InputKit';
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
import { TouchEvent } from '@kit.InputKit';
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { MouseEvent } from '@kit.InputKit';
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
import { MouseEvent } from '@kit.InputKit';
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

(touchEvent: TouchEvent): Boolean

Defines the callback for touch (touchscreen) events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name        | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](js-apis-touchevent.md#touchevent) | Yes   | Touch event.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| Boolean | Result indicating whether the touch event will be dispatched to the window. The value **true** indicates that the touch event will be dispatched to the window, and the value **false** indicates the opposite.|

**Example**

```js
import { TouchEvent } from '@kit.InputKit';
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
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | Yes   | Callback used to return pinch events asynchronously. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import type { Pinch } from '@kit.InputKit';
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import { Pinch } from '@kit.InputKit';

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
import { Pinch } from '@kit.InputKit';

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
| receiver | Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt; | Yes   | Callback used to return three-finger swipe events asynchronously. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import { ThreeFingersSwipe } from '@kit.InputKit';

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
import { ThreeFingersSwipe } from '@kit.InputKit';

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
| receiver | Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt; | Yes   | Callback used to return four-finger swipe events asynchronously. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import { FourFingersSwipe } from '@kit.InputKit';

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
import { FourFingersSwipe } from '@kit.InputKit';

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

## inputMonitor.on('rotate')<sup>11+</sup>

on(type: 'rotate', fingers: number, receiver: Callback&lt;Rotate&gt;): void

Enables listening for rotation events of the touchpad.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **rotate**.|
| fingers     | number                     | Yes   | Number of fingers that trigger a rotation. The value must not be greater than **2**.|
| receiver | Callback&lt;[Rotate](js-apis-multimodalinput-gestureevent.md#rotate)&gt; | Yes   | Callback used to return rotation events asynchronously. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import type { Rotate } from '@kit.InputKit';
try {
  inputMonitor.on('rotate', 2, (rotateEvent: Rotate) => {
    console.log(`Monitor on success ${JSON.stringify(rotateEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('rotate')<sup>11+</sup>

off(type: 'rotate', fingers: number, receiver?: Callback&lt;Rotate&gt;): void

Disables listening for rotation events of the touchpad.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **rotate**.|
| fingers     | number                     | Yes   | Number of fingers that trigger a rotation. The value must not be greater than **2**.|
| receiver | Callback&lt;[Rotate](js-apis-multimodalinput-gestureevent.md#rotate)&gt; | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import { Rotate } from '@kit.InputKit';

let callback = (rotateEvent: Rotate) => {
  console.log(`Monitor on success ${JSON.stringify(rotateEvent)}`);
  return false;
};
try {
  inputMonitor.on('rotate', 2, callback);
  inputMonitor.off('rotate', 2, callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import { Rotate } from '@kit.InputKit';

let callback = (rotateEvent: Rotate) => {
  console.log(`Monitor on success ${JSON.stringify(rotateEvent)}`);
  return false;
};
try {
  inputMonitor.on('rotate', 2, callback);
  inputMonitor.off('rotate', 2);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('pinch')<sup>11+</sup>

on(type: 'pinch', fingers: number, receiver: Callback&lt;Pinch&gt;): void

Enables listening for global touchpad pinch events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **pinch**.|
| fingers     | number                     | Yes   | Number of fingers that trigger the pinch. The value must be greater than or equal to **2**.|
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | Yes   | Callback used to return pinch events asynchronously. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import type { Pinch } from '@kit.InputKit';
try {
  inputMonitor.on('pinch', 2, (pinchEvent: Pinch) => {
    console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('pinch')<sup>11+</sup>

off(type: 'pinch', fingers: number, receiver?: Callback&lt;Pinch&gt;): void

Disables listening for global touchpad pinch events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name      | Type                        | Mandatory  | Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | Yes   | Event type. This field has a fixed value of **pinch**.|
| fingers     | number                     | Yes   | Number of fingers that trigger the pinch. The value must be greater than or equal to **2**.|
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | No   | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import { Pinch } from '@kit.InputKit';

let callback = (pinchEvent: Pinch) => {
  console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
  return false;
};
try {
  inputMonitor.on('pinch', 2, callback);
  inputMonitor.off('pinch', 2, callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import { Pinch } from '@kit.InputKit';

let callback = (pinchEvent: Pinch) => {
  console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
  return false;
};
try {
  inputMonitor.on('pinch', 2, callback);
  inputMonitor.off('pinch', 2);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('threeFingersTap')<sup>11+</sup>

on(type: 'threeFingersTap', receiver: Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap)&gt;): void

Enables listening for three-finger tap events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type. This field has a fixed value of **threeFingersTap**.|
| receiver | Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap)&gt; | Yes  | Callback used to return three-finger tap events asynchronously.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  inputMonitor.on('threeFingersTap', (threeFingersTap) => {
    console.log(`Monitor on success ${JSON.stringify(threeFingersTap)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('threeFingersTap')<sup>11+</sup>

off(type: 'threeFingersTap', receiver?: Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap)&gt;): void

Disables listening for three-finger tap events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. This field has a fixed value of **threeFingersTap**.                   |
| receiver | Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap)&gt; | No  | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import { ThreeFingersTap } from '@kit.InputKit';

let callback = (threeFingersTap: ThreeFingersTap) => {
  console.log(`Monitor on success ${JSON.stringify(threeFingersTap)}`);
  return false;
};
try {
  inputMonitor.on('threeFingersTap', callback);
  inputMonitor.off("threeFingersTap", callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import { ThreeFingersTap } from '@kit.InputKit';

let callback = (threeFingersTap: ThreeFingersTap) => {
  console.log(`Monitor on success ${JSON.stringify(threeFingersTap)}`);
  return false;
};
try {
  inputMonitor.on('threeFingersTap', callback);
  inputMonitor.off("threeFingersTap");
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('touchscreenSwipe')<sup>14+</sup>

on(type: 'touchscreenSwipe', fingers: number, receiver: Callback&lt;TouchGestureEvent&gt;): void

Enables listening for touchscreen swipe events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. This field has a fixed value of **touchscreenSwipe**.                   |
| fingers  | number                                                       | Yes  | Number of fingers that trigger the swipe. The value range is [3, 5].|
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent)&gt; | Yes  | Callback used to return touchscreen swipe events asynchronously.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

let fingers: number = 4;
try {
  inputMonitor.on('touchscreenSwipe', fingers, (event: TouchGestureEvent) => {
    console.log(`Monitor on success ${JSON.stringify(event)}`);
  });
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('touchscreenSwipe')<sup>14+</sup>

off(type: 'touchscreenSwipe', fingers: number, receiver?: Callback&lt;TouchGestureEvent&gt;): void

Disables listening for touchscreen swipe events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. This field has a fixed value of **touchscreenSwipe**.                   |
| fingers  | number                                                       | Yes  | Number of fingers that trigger the swipe. The value range is [3, 5].|
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent)&gt; | No  | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

let callback = (event: TouchGestureEvent) => {
  console.log(`Monitor on success ${JSON.stringify(event)}`);
};
let fingers: number = 4;
try {
  inputMonitor.on('touchscreenSwipe', fingers, callback);
  inputMonitor.off('touchscreenSwipe', fingers, callback);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

let fingers: number = 4;
try {
  inputMonitor.on('touchscreenSwipe', fingers, (event: TouchGestureEvent) => {
    console.log(`Monitor on success ${JSON.stringify(event)}`);
  });
  inputMonitor.off('touchscreenSwipe', fingers);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('touchscreenPinch')<sup>14+</sup>

on(type: 'touchscreenPinch', fingers: number, receiver: Callback&lt;TouchGestureEvent&gt;): void

Enables listening for touchscreen pinch events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. This field has a fixed value of **touchscreenPinch**.                   |
| fingers  | number                                                       | Yes  | Number of fingers that trigger the pinch. The value range is [4, 5].|
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent)&gt; | Yes  | Callback used to return touchscreen pinch events asynchronously.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

let fingers: number = 4;
try {
  inputMonitor.on('touchscreenPinch', fingers, (event: TouchGestureEvent) => {
    console.log(`Monitor on success ${JSON.stringify(event)}`);
  });
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('touchscreenPinch')<sup>14+</sup>

off(type: 'touchscreenPinch', fingers: number, receiver?: Callback&lt;TouchGestureEvent&gt;): void

Disables listening for touchscreen pinch events.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. This field has a fixed value of **touchscreenPinch**.                   |
| fingers  | number                                                       | Yes  | Number of fingers that trigger the pinch. The value range is [4, 5].|
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent)&gt; | No  | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

let callback = (event: TouchGestureEvent) => {
  console.log(`Monitor on success ${JSON.stringify(event)}`);
};
let fingers: number = 4;
try {
  inputMonitor.on('touchscreenPinch', fingers, callback);
  inputMonitor.off("touchscreenPinch", fingers, callback);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

let fingers: number = 4;
try {
  inputMonitor.on('touchscreenPinch', fingers, (event: TouchGestureEvent) => {
    console.log(`Monitor on success ${JSON.stringify(event)}`);
  });
  inputMonitor.off("touchscreenPinch", fingers);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('keyPressed')<sup>16+</sup>

on(type: 'keyPressed', keys: Array&lt;KeyCode&gt;, receiver: Callback&lt;KeyEvent&gt;): void

Listens for the press and release events of the specified key, which can be the **META_LEFT**, **META_RIGHT**, power, or volume key.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                      | Yes  | Event type. This parameter has a fixed value of **keyPressed**.|
| keys     | Array<[KeyCode](js-apis-keycode.md#keycode)> | Yes  | Key code list. The options are **KEYCODE_META_LEFT**, **KEYCODE_META_RIGHT**, **KEYCODE_POWER**, **KEYCODE_VOLUME_DOWN**, and **KEYCODE_VOLUME_UP**.                     |
| receiver | Callback&lt;[KeyEvent](js-apis-keyevent.md#keyevent)&gt;    | Yes  | Callback used to receive reported data.        |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Input Key Monitor Error Codes](errorcode-inputkeymonitor.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied, non-system app called system api.         |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 4100001  | Event listening not supported for the key.                   |

**Example**

```js
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';

let keys: Array<KeyCode> = [KeyCode.KEYCODE_VOLUME_UP];
try {
  inputMonitor.on('keyPressed', keys, (event: KeyEvent ) => {
    console.log(`Monitor on success ${JSON.stringify(event)}`);
  });
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('keyPressed')<sup>16+</sup>

off(type: 'keyPressed', receiver?: Callback&lt;KeyEvent&gt;): void

Cancels listening for the press and release events of the specified key, which can be the **META_LEFT**, **META_RIGHT**, power, or volume key. This API must be used together with **inputMonitor.on ('keyPressed')**.

**Required permissions**: ohos.permission.INPUT_MONITORING

**System capability**: SystemCapability.MultimodalInput.Input.InputMonitor

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | Yes  | Event type. This parameter has a fixed value of **keyPressed**.                        |
| receiver | Callback&lt;[KeyEvent](js-apis-keyevent.md#keyevent)&gt; | No  | Callback for which listening is disabled. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied, non-system app called system api.         |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
// Disable listening for a single callback.
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';

let callback = (event: KeyEvent) => {
  console.log(`Monitor on success ${JSON.stringify(event)}`);
};
let keys: Array<KeyCode> = [KeyCode.KEYCODE_VOLUME_UP];
try {
  inputMonitor.on('keyPressed', keys, callback);
  inputMonitor.off("keyPressed", callback);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// Cancel listening for all callbacks.
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';

let keys: Array<KeyCode> = [KeyCode.KEYCODE_VOLUME_UP];
try {
  inputMonitor.on('keyPressed', keys, (event: KeyEvent) => {
    console.log(`Monitor on success ${JSON.stringify(event)}`);
  });
  inputMonitor.off("keyPressed");
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
