# 多模输入changeLog

## cl.multimodalinput.1 API错误信息返回方式变更

如下接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。从API9开始作以下变更，
 设备管理：三方接口，@ohos.multimodalInput.inputDevice.d.ts

按键订阅：系统接口，@ohos.multimodalInput.inputConsumer.d.ts

键鼠穿越：系统接口，@ohos.multimodalInput.inputDeviceCooperate.d.ts

按键注入：系统接口，@ohos.multimodalInput.inputEventClient.d.ts

事件监听：系统接口，@ohos.multimodalInput.inputMonitor.d.ts

指针事件：系统接口和三方接口，@ohos.multimodalInput.pointer.d.t

异步接口：通过AsyncCallback或Promise的error对象返回错误信息。

同步接口：不涉及。

**变更影响**

基于此前版本开发的应用，需适配接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

以下接口标记废除：

   -  **function** getDeviceIds(callback: AsyncCallback<Array<**number**>>): **void**; 

   -  **function** getDeviceIds(): Promise<Array<**number**>>; 

   -  **function** getDevice(deviceId: **number**, callback: AsyncCallback<InputDeviceData>): **void**; 

 **function** getDevice(deviceId: **number**): Promise<InputDeviceData>; 

替代接口如下:

   -  **function** getDeviceList(callback: AsyncCallback<Array<**number**>>): **void**; 

   -  **function** getDeviceList(): Promise<Array<**number**>>; 

   -  **function** getDeviceInfo(deviceId: **number**, callback: AsyncCallback<InputDeviceData>): **void**; 

  -  **function** getDeviceInfo(deviceId: **number**): Promise<InputDeviceData>; 

以下接口增加错误码处理：
  -  **function** supportKeys(deviceId: **number**, keys: Array<KeyCode>, callback: AsyncCallback<Array<boolean>>): **void**; 
  -  **function** supportKeys(deviceId: **number**, keys: Array<KeyCode>): Promise<Array<boolean>>; 
  -  **function** getKeyboardType(deviceId: **number**, callback: AsyncCallback<KeyboardType>): **void**; &gt;
  -  **function** getKeyboardType(deviceId: **number**): Promise<KeyboardType>; 
  -   **function** setPointerSpeed(speed: **number**, callback: AsyncCallback<**void**>): **void**; 
  -   **function** setPointerSpeed(speed: **number**): Promise<**void**>; 
  -   **function** getPointerSpeed(callback: AsyncCallback<**number**>): **void**; 
  -   **function** getPointerSpeed(): Promise<**number**>; 
  -   **function** setPointerStyle(windowId: **number**, pointerStyle: PointerStyle, callback: AsyncCallback<**void**>): **void**; 
  -   **function** setPointerStyle(windowId: **number**, pointerStyle: PointerStyle): Promise<**void**>; 
  -   **function** getPointerStyle(windowId: **number**, callback: AsyncCallback<PointerStyle>): **void**; 
  -   **function** getPointerStyle(windowId: **number**): Promise<PointerStyle>; 
  -   **function** setPointerVisible(visible: boolean, callback: AsyncCallback<**void**>): **void**; 
  -   **function** setPointerVisible(visible: boolean): Promise<**void**>; 
  -   **function** isPointerVisible(callback: AsyncCallback<boolean>): **void**; 
  -   **function** isPointerVisible(): Promise<boolean>; 
  -   **function** on(**type**:"touch", receiver:TouchEventReceiver):**void**; 
  -   **function** on(**type**:"mouse", receiver:Callback<MouseEvent>):**void**; 
  -   **function** off(**type**:"touch", receiver?:TouchEventReceiver):**void**; 
  -   **function** off(**type**:"mouse", receiver?:Callback<MouseEvent>):**void**; 
  -   **function** injectEvent({KeyEvent: KeyEvent}): **void**; 
  -   **function** enable(enable: boolean, callback: AsyncCallback<**void**>): **void**; 
  -   **function** enable(enable: boolean): Promise<**void**>; 
  -   **function** start(sinkDeviceDescriptor: **string**, srcInputDeviceId: **number**, callback: AsyncCallback<**void**>): **void**; 
  -   **function** start(sinkDeviceDescriptor: **string**, srcInputDeviceId: **number**): Promise<**void**>; 
  -   **function** stop(callback: AsyncCallback<**void**>): **void**; 
  -   **function** stop(): Promise<**void**>; 
  -   **function** getState(deviceDescriptor: **string**, callback: AsyncCallback<{ state: boolean }>): **void**; 
  -   **function** getState(deviceDescriptor: **string**): Promise<{ state: boolean }>; 
  -   **function** on(**type**: 'cooperation', callback: AsyncCallback<{ deviceDescriptor: **string**, eventMsg: EventMsg }>): **void**; 
  -   **function** off(**type**: 'cooperation', callback?: AsyncCallback<**void**>): **void**; 
  -   **function** on(**type**: "key", keyOptions: KeyOptions, callback: Callback<KeyOptions>): **void**; 
  -   **function** off(**type**: "key", keyOptions: KeyOptions, callback?: Callback<KeyOptions>): **void**; 

**以下接口发生变更**

变更前：

- **function** supportKeys(deviceId: **number**, keys: Array<KeyCode>, callback: Callback<Array<boolean>>): **void**; 

- **function** getKeyboardType(deviceId: **number**, callback: Callback<KeyboardType>): **void**; 

变更后：

-  **function** supportKeys(deviceId: **number**, keys: Array<KeyCode>, callback: AsyncCallback<Array<boolean>>): **void**; 

- **function** getKeyboardType(deviceId: **number**, callback: AsyncCallback<KeyboardType>): **void**; 

**适配指导**

以setPointerVisible为例，示例代码如下：

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

