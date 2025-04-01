# Input Monitor Development

## When to Use

The **inputMonitor** module provides capabilities such as listening for key events and touchpad gestures. For example, if your application needs to implement a dedicated function when a three-finger swipe-up gesture occurs on the touchpad, you can listen for three-finger swipe-up events to serve that purpose.

## Modules to Import

```js
import { inputMonitor } from '@kit.InputKit';
```

## Available APIs

The following table lists the common APIs provided by the **inputMonitor** module. For details, see [ohos.multimodalInput.inputMonitor](../../reference/apis-input-kit/js-apis-inputmonitor-sys.md).

| API | Description|
| ------------------------------------------------------------ | -------------------------- |
| on(type: 'mouse', receiver: Callback&lt;MouseEvent&gt;): void |Listens for mouse events.|
| on(type: 'touch', receiver: TouchEventReceiver): void | Listens for touchscreen events.|
| on(type: 'pinch', receiver: TouchEventReceiver): void | Listens for pinch events.|
| on(type: 'threeFingersSwipe', receiver: Callback&lt;ThreeFingersSwipe&gt;): void | Listens for three-finger swipe-up events.|
| on(type: 'threeFingersTap', receiver: Callback&lt;ThreeFingersSwipe&gt;): void | Listens for three-finger tap events.|
| on(type: 'fourFingersSwipe', receiver: Callback&lt;FourFingersSwipe&gt;): void | Listens for four-finger swipe events.|
| on(type: 'rotate', fingers: number, receiver: Callback&lt;Rotate&gt;): void | Listens for rotation events.|
| off(type: 'mouse', receiver: Callback&lt;MouseEvent&gt;): void |Cancels listening for mouse events.|
| off(type: 'touch', receiver: TouchEventReceiver): void | Cancels listening for touchscreen events.|
| off(type: 'pinch', receiver: TouchEventReceiver): void | Cancels listening for pinch events.|
| off(type: 'threeFingersSwipe', receiver: Callback&lt;ThreeFingersSwipe&gt;): void | Cancels listening for three-finger swipe-up events.|
| off(type: 'threeFingersTap', receiver: Callback&lt;ThreeFingersSwipe&gt;): void | Cancels listening for three-finger tap events.|
| off(type: 'fourFingersSwipe', receiver: Callback&lt;FourFingersSwipe&gt;): void | Cancels listening for four-finger swipe events.|
| off(type: 'rotate', fingers: number, receiver: Callback&lt;Rotate&gt;): void | Cancels listening for rotation events.|

## How to Develop

This example assumes that the application needs to change the style based on the mouse button pressing status. Specifically, listen for mouse button events by calling [on](../../reference/apis-input-kit/js-apis-inputmonitor-sys.md#inputmonitoronmouse9), and cancel listening for mouse button events by calling [off](../../reference/apis-input-kit/js-apis-inputmonitor-sys.md#inputmonitoroffmouse9).

```js
import { MouseEvent } from '@kit.InputKit';

let BUTTON_DOWN = 2;
let callback = (mouseEvent: MouseEvent) => {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    if(mouseEvent.action = BUTTON_DOWN){
      return true;// Callback triggered when the mouse button is pressed.
    }
    return false;
};

try {
  inputMonitor.on('mouse', (mouseEvent: MouseEvent) => {// Start to listen for mouse events.
    console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
// Callback triggered when the mouse button is pressed.
try {
  inputMonitor.off('mouse', callback);// Cancel listening for mouse events.
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor off failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
