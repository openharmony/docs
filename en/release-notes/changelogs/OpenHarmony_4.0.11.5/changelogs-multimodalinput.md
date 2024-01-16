#  Multimodal Input Subsystem Changelog

##  cl.multimodalinput.1 Implementation Error of inputMonitor Corrected

When **inputMonitor** is used to listen for **TouchEvent**, **TouchEvent** in the callback originally references the common **TouchEvent** of arkui-js, which is not exposed externally (that is, not exported). However, **TouchEvent** of arkui-ts is used by default in IDE. Therefore, the original API becomes invalid after the ArtTS syntax update. To solve this problem, you need to change the **TouchEvent** reference in **inputMonitor** to **TouchEvent** of the multimodal input.

**Change Impact**

The field name is changed. The value of the original field is **undefined**.

**Key API/Component Changes**

If you want to use **inputMonitor** to listen for **TouchEvent** of the multimodal input, you need to import the **touchEvent** class of the multimodal input separately.

```ts
import touchEvent from '@ohos.multimodalInput.touchEvent';
try {
  inputMonitor.on('touch', (touchEvent: touchEvent.TouchEvent) => {
    console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

**Adaptation Guide**

Since OpenHarmony 4.0.11.5, change the field names of **TouchEvent** to those of the multimodal input.

| Before Change        | After Change    |
| -------------- | ---------- |
| type           | action     |
| timestamp      | actionTime |
| deviceId       | deviceId   |
| globalX        | screenX    |
| globalY        | screenY    |
| localX         | windowX    |
| localY         | windowY    |
| force          | pressure   |
| touches        | touches    |
| changedTouches | touches    |
