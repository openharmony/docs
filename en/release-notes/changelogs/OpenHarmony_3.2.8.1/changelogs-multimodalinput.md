# Multimodal Input ChangeLog

## cl.multimodalinput.1 Error Information Return Method Change of APIs

The internal APIs of the following modules used service logic return values to indicate error information, which did not comply with the error code specifications of OpenHarmony. Therefore, they are modified in API version 9 and later.
 - Input device management module (**@ohos.multimodalInput.inputDevice.d.ts**): third-party APIs

 - Input consumer module (**@ohos.multimodalInput.inputConsumer.d.ts**): system APIs

 - Screen hopping module (**@ohos.multimodalInput.inputDeviceCooperate.d.ts**): system APIs

 - Key injection module (**@ohos.multimodalInput.inputEventClient.d.ts**): system APIs

 - Input listening module (**@ohos.multimodalInput.inputMonitor.d.ts**): system APIs

 - Mouse pointer module (**@ohos.multimodalInput.pointer.d.ts**): system APIs and third-party APIs

Asynchronous APIs in the preceding modules have the following changes: A parameter check error is returned synchronously; a service logic error is returned via **AsyncCallback** or the **error** object of **Promise**. No change is made to synchronous APIs.

**Change Impacts**

The application developed based on earlier versions needs to adapt the method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

  - supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: AsyncCallback&lt;Array&lt;boolean&gt;&gt;): void; 
  - supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;): Promise&lt;Array&lt;boolean&gt;&gt;; 
  - getKeyboardType(deviceId: number, callback: AsyncCallback&lt;KeyboardType&gt;): void; &gt;
  - getKeyboardType(deviceId: number): Promise&lt;KeyboardType&gt;; 
  - setPointerSpeed(speed: number, callback: AsyncCallback&lt;void&gt;): void; 
  - setPointerSpeed(speed: number): Promise&lt;void&gt;; 
  - getPointerSpeed(callback: AsyncCallback&lt;number&gt;): void; 
  - getPointerSpeed(): Promise&lt;number&gt;; 
  - setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback&lt;void&gt;): void; 
  - setPointerStyle(windowId: number, pointerStyle: PointerStyle): Promise&lt;void&gt;; 
  - getPointerStyle(windowId: number, callback: AsyncCallback&lt;PointerStyle&gt;): void; 
  - getPointerStyle(windowId: number): Promise&lt;PointerStyle&gt;; 
  - setPointerVisible(visible: boolean, callback: AsyncCallback&lt;void&gt;): void; 
  - setPointerVisible(visible: boolean): Promise&lt;void&gt;; 
  - isPointerVisible(callback: AsyncCallback&lt;boolean&gt;): void; 
  - isPointerVisible(): Promise&lt;boolean&gt;; 
  - on(type:"touch", receiver:TouchEventReceiver):void; 
  - on(type:"mouse", receiver:Callback&lt;MouseEvent&gt;):void; 
  - off(type:"touch", receiver?:TouchEventReceiver):void; 
  - off(type:"mouse", receiver?:Callback&lt;MouseEvent&gt;):void; 
  - injectEvent({KeyEvent: KeyEvent}): void; 
  - enable(enable: boolean, callback: AsyncCallback&lt;void&gt;): void; 
  - enable(enable: boolean): Promise&lt;void&gt;; 
  - start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void; 
  - start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise&lt;void&gt;; 
  - stop(callback: AsyncCallback&lt;void&gt;): void; 
  - stop(): Promise&lt;void&gt;; 
  - getState(deviceDescriptor: string, callback: AsyncCallback&lt;{ state: boolean }&gt;): void; 
  - getState(deviceDescriptor: string): Promise&lt;{ state: boolean }&gt;; 
  - on(type: 'cooperation', callback: AsyncCallback&lt;{ deviceDescriptor: string, eventMsg: EventMsg }&gt;): void; 
  - off(type: 'cooperation', callback?: AsyncCallback&lt;void&gt;): void; 
  - on(type: "key", keyOptions: KeyOptions, callback: Callback&lt;KeyOptions&gt;): void; 
  - off(type: "key", keyOptions: KeyOptions, callback?: Callback&lt;KeyOptions&gt;): void; 

Deprecated APIs:
   - getDeviceIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void; 
   - getDeviceIds(): Promise&lt;Array&lt;number&gt;&gt;; 
   - getDevice(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void; 
   - getDevice(deviceId: number): Promise&lt;InputDeviceData&gt;; 

Substitute APIs:
   - getDeviceList(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void; 
   - getDeviceList(): Promise&lt;Array&lt;number&gt;&gt;; 
   - getDeviceInfo(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void; 
   - getDeviceInfo(deviceId: number): Promise&lt;InputDeviceData&gt;; 

Changed APIs:

Before change:
 - supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: Callback&lt;Array&lt;boolean&gt;&gt;): void; 
 - getKeyboardType(deviceId: number, callback: Callback&lt;KeyboardType&gt;): void; 

After change:
 - supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: AsyncCallback&lt;Array&lt;boolean&gt;&gt;): void; 
 - getKeyboardType(deviceId: number, callback: AsyncCallback&lt;KeyboardType&gt;): void; 

**Adaptation Guide**

The following uses **setPointerVisible** as an example:

```ts
import pointer from '@ohos.multimodalInput.pointer';
pointer.setPointerVisible(true, (error) => {
    console.log(`Set pointer visible success`);
  });

try {
  pointer.setPointerVisible(true, (error) => {
    if (error) {
      console.log(`Set pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set pointer visible success`);
  });
} catch (error) {
  console.log(`Set pointer visible failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
