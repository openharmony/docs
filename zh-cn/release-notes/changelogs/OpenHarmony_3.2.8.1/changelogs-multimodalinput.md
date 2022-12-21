# 多模输入changeLog

## cl.multimodalinput.1 API错误信息返回方式变更

下列模块内部接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。在API9进行变更。
 - 输入设备管理模块：三方接口，@ohos.multimodalInput.inputDevice.d.ts

 - 组合按键订阅模块：系统接口，@ohos.multimodalInput.inputConsumer.d.ts

 - 键鼠穿越功能模块：系统接口，@ohos.multimodalInput.inputDeviceCooperate.d.ts

 - 按键注入模块：系统接口，@ohos.multimodalInput.inputEventClient.d.ts

 - 输入监听模块：系统接口，@ohos.multimodalInput.inputMonitor.d.ts

 - 鼠标指针管理模块：系统接口和三方接口，@ohos.multimodalInput.pointer.d.ts

以上模块中的异步接口变更为参数检查错误同步抛出，业务逻辑错误通过AsyncCallback或Promise的error对象抛出，同步接口不作变更。

**变更影响**

基于此前版本开发的应用，需适配接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

  -  supportKeys(deviceId: **number**, keys: Array<KeyCode>, callback: AsyncCallback<Array<boolean>>): **void**; 
  -  supportKeys(deviceId: **number**, keys: Array<KeyCode>): Promise<Array<boolean>>; 
  -  getKeyboardType(deviceId: **number**, callback: AsyncCallback<KeyboardType>): **void**; &gt;
  -  getKeyboardType(deviceId: **number**): Promise<KeyboardType>; 
  -  setPointerSpeed(speed: **number**, callback: AsyncCallback<**void**>): **void**; 
  -  setPointerSpeed(speed: **number**): Promise<**void**>; 
  -  getPointerSpeed(callback: AsyncCallback<**number**>): **void**; 
  -  getPointerSpeed(): Promise<**number**>; 
  -  setPointerStyle(windowId: **number**, pointerStyle: PointerStyle, callback: AsyncCallback<**void**>): **void**; 
  -  setPointerStyle(windowId: **number**, pointerStyle: PointerStyle): Promise<**void**>; 
  -  getPointerStyle(windowId: **number**, callback: AsyncCallback<PointerStyle>): **void**; 
  -  getPointerStyle(windowId: **number**): Promise<PointerStyle>; 
  -  setPointerVisible(visible: boolean, callback: AsyncCallback<**void**>): **void**; 
  -  setPointerVisible(visible: boolean): Promise<**void**>; 
  -  isPointerVisible(callback: AsyncCallback<boolean>): **void**; 
  -  isPointerVisible(): Promise<boolean>; 
  -  on(**type**:"touch", receiver:TouchEventReceiver):**void**; 
  -  on(**type**:"mouse", receiver:Callback<MouseEvent>):**void**; 
  -  off(**type**:"touch", receiver?:TouchEventReceiver):**void**; 
  -  off(**type**:"mouse", receiver?:Callback<MouseEvent>):**void**; 
  -  injectEvent({KeyEvent: KeyEvent}): **void**; 
  -  enable(enable: boolean, callback: AsyncCallback<**void**>): **void**; 
  -  enable(enable: boolean): Promise<**void**>; 
  -  start(sinkDeviceDescriptor: **string**, srcInputDeviceId: **number**, callback: AsyncCallback<**void**>): **void**; 
  -  start(sinkDeviceDescriptor: **string**, srcInputDeviceId: **number**): Promise<**void**>; 
  -  stop(callback: AsyncCallback<**void**>): **void**; 
  -  stop(): Promise<**void**>; 
  -  getState(deviceDescriptor: **string**, callback: AsyncCallback<{ state: boolean }>): **void**; 
  -  getState(deviceDescriptor: **string**): Promise<{ state: boolean }>; 
  -  on(**type**: 'cooperation', callback: AsyncCallback<{ deviceDescriptor: **string**, eventMsg: EventMsg }>): **void**; 
  -  off(**type**: 'cooperation', callback?: AsyncCallback<**void**>): **void**; 
  -  on(**type**: "key", keyOptions: KeyOptions, callback: Callback<KeyOptions>): **void**; 
  -  off(**type**: "key", keyOptions: KeyOptions, callback?: Callback<KeyOptions>): **void**; 

以下接口标记废除：
   - getDeviceIds(callback: AsyncCallback<Array<**number**>>): **void**; 
   - getDeviceIds(): Promise<Array<**number**>>; 
   - getDevice(deviceId: **number**, callback: AsyncCallback<InputDeviceData>): **void**; 
   - getDevice(deviceId: **number**): Promise<InputDeviceData>; 

替代接口如下:
   - getDeviceList(callback: AsyncCallback<Array<**number**>>): **void**; 
   - getDeviceList(): Promise<Array<**number**>>; 
   - getDeviceInfo(deviceId: **number**, callback: AsyncCallback<InputDeviceData>): **void**; 
  - getDeviceInfo(deviceId: **number**): Promise<InputDeviceData>; 

以下接口发生变更

变更前：
 - supportKeys(deviceId: **number**, keys: Array<KeyCode>, callback: Callback<Array<boolean>>): **void**; 
 - getKeyboardType(deviceId: **number**, callback: Callback<KeyboardType>): **void**; 

变更后：
- supportKeys(deviceId: **number**, keys: Array<KeyCode>, callback: AsyncCallback<Array<boolean>>): **void**; 
 - getKeyboardType(deviceId: **number**, callback: AsyncCallback<KeyboardType>): **void**; 

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

