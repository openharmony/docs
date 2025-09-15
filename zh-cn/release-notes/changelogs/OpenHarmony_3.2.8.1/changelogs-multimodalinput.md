# 多模输入changeLog

## cl.multimodalinput.1 API错误信息返回方式变更

下列模块内部接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。在API9进行变更。
 - 输入设备管理模块：三方接口，@ohos.multimodalInput.inputDevice.d.ts

 - 组合按键订阅模块：系统接口，@ohos.multimodalInput.inputConsumer.d.ts

 - 键鼠穿越功能模块：系统接口，@ohos.multimodalInput.inputDeviceCooperate.d.ts

 - 按键注入模块：系统接口，@ohos.multimodalInput.inputEventClient.d.ts

 - 输入监听模块：系统接口，@ohos.multimodalInput.inputMonitor.d.ts

 - 鼠标光标管理模块：系统接口和三方接口，@ohos.multimodalInput.pointer.d.ts

以上模块中的异步接口变更为参数检查错误同步抛出，业务逻辑错误通过AsyncCallback或Promise的error对象抛出，同步接口不作变更。

**变更影响**

基于此前版本开发的应用，需适配接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

  - supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: AsyncCallback&lt;Array&lt;boolean&gt;&gt;): void; 
  -  supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;): Promise&lt;Array&lt;boolean&gt;&gt;; 
  -  getKeyboardType(deviceId: number, callback: AsyncCallback&lt;KeyboardType&gt;): void; &gt;
  -  getKeyboardType(deviceId: number): Promise&lt;KeyboardType&gt;; 
  -  setPointerSpeed(speed: number, callback: AsyncCallback&lt;void&gt;): void; 
  -  setPointerSpeed(speed: number): Promise&lt;void&gt;; 
  -  getPointerSpeed(callback: AsyncCallback&lt;number&gt;): void; 
  -  getPointerSpeed(): Promise&lt;number&gt;; 
  -  setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback&lt;void&gt;): void; 
  -  setPointerStyle(windowId: number, pointerStyle: PointerStyle): Promise&lt;void&gt;; 
  -  getPointerStyle(windowId: number, callback: AsyncCallback&lt;PointerStyle&gt;): void; 
  -  getPointerStyle(windowId: number): Promise&lt;PointerStyle&gt;; 
  -  setPointerVisible(visible: boolean, callback: AsyncCallback&lt;void&gt;): void; 
  -  setPointerVisible(visible: boolean): Promise&lt;void&gt;; 
  -  isPointerVisible(callback: AsyncCallback&lt;boolean&gt;): void; 
  -  isPointerVisible(): Promise&lt;boolean&gt;; 
  -  on(type:"touch", receiver:TouchEventReceiver):void; 
  -  on(type:"mouse", receiver:Callback&lt;MouseEvent&gt;):void; 
  -  off(type:"touch", receiver?:TouchEventReceiver):void; 
  -  off(type:"mouse", receiver?:Callback&lt;MouseEvent&gt;):void; 
  -  injectEvent({KeyEvent: KeyEvent}): void; 
  -  enable(enable: boolean, callback: AsyncCallback&lt;void&gt;): void; 
  -  enable(enable: boolean): Promise&lt;void&gt;; 
  -  start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void; 
  -  start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise&lt;void&gt;; 
  -  stop(callback: AsyncCallback&lt;void&gt;): void; 
  -  stop(): Promise&lt;void&gt;; 
  -  getState(deviceDescriptor: string, callback: AsyncCallback&lt;{ state: boolean }&gt;): void; 
  -  getState(deviceDescriptor: string): Promise&lt;{ state: boolean }&gt;; 
  -  on(type: 'cooperation', callback: AsyncCallback&lt;{ deviceDescriptor: string, eventMsg: EventMsg }&gt;): void; 
  -  off(type: 'cooperation', callback?: AsyncCallback&lt;void&gt;): void; 
  -  on(type: "key", keyOptions: KeyOptions, callback: Callback&lt;KeyOptions&gt;): void; 
  -  off(type: "key", keyOptions: KeyOptions, callback?: Callback&lt;KeyOptions&gt;): void; 

以下接口标记废除：
   - getDeviceIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void; 
   - getDeviceIds(): Promise&lt;Array&lt;number&gt;&gt;; 
   - getDevice(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void; 
   - getDevice(deviceId: number): Promise&lt;InputDeviceData&gt;; 

替代接口如下:
   - getDeviceList(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void; 
   - getDeviceList(): Promise&lt;Array&lt;number&gt;&gt;; 
   - getDeviceInfo(deviceId: number, callback: AsyncCallback&lt;InputDeviceData&gt;): void; 
   - getDeviceInfo(deviceId: number): Promise&lt;InputDeviceData&gt;; 

以下接口发生变更

变更前：
 - supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: Callback&lt;Array&lt;boolean&gt;&gt;): void; 
 - getKeyboardType(deviceId: number, callback: Callback&lt;KeyboardType&gt;): void; 

变更后：
 - supportKeys(deviceId: number, keys: Array&lt;KeyCode&gt;, callback: AsyncCallback&lt;Array&lt;boolean&gt;&gt;): void; 
 - getKeyboardType(deviceId: number, callback: AsyncCallback&lt;KeyboardType&gt;): void; 

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

