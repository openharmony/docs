# 按键开发指导

## 场景介绍

按键事件监听能力支持应用在前台状态下订阅物理按键的按下事件，常用于音量键等。该接口不仅可以订阅用户按键行为，还会屏蔽系统默认对该按键的响应，适用于需要拦截并重定义按键功能的场景。当前仅支持手机和平板设备。

使用场景例如：开发者可在阅读类应用中订阅音量键实现翻页，或在相机类应用中订阅音量键实现拍照功能，从而提升用户体验。

## 导入模块

```js
import { inputConsumer } from '@kit.InputKit';
```

## 接口说明

按键事件常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.inputConsumer文档](../../reference/apis-input-kit/js-apis-inputconsumer.md)。

| 接口名称  | 描述 |
| ------------------------------------------------------------ | -------------------------- |
| on(type: "keyPressed", options: KeyPressedConfig, callback: Callback\<KeyEvent>): void |订阅指定按键按下事件，拦截系统默认响应。  |
| off(type: "keyPressed", callback?: Callback\<KeyEvent>): void |取消按键事件订阅，恢复系统默认响应。  |

## 开发步骤

应用开启时调用[on](../../reference/apis-input-kit/js-apis-inputconsumer.md#inputConsumer.on('keyPressed'))方法订阅全局快捷键，应用关闭时再用[off](../../reference/apis-input-kit/js-apis-inputconsumer.md#inputConsumer.off('keyPressed'))方法取消订阅全局快捷键。

### 音量键翻页

在电子书或新闻阅读应用中，用户希望通过音量键控制翻页（例如：音量加键向下翻页，音量减键向上翻页）。

```js
//应用开启
try {
  let options: inputConsumer.KeyPressedConfig = {
    key: 16,
    action: 1,
    isRepeat: false,
  }
  inputConsumer.on('keyPressed', options, (event: KeyEvent) => {
    console.log(`Subscribe success ${JSON.stringify(event)}`);
  });
} catch (error) {
  console.error(`Subscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
//应用关闭
try {
  // 取消指定回调函数
  inputConsumer.off('keyPressed', (event: KeyEvent) => {
    console.log(`Unsubscribe success ${JSON.stringify(event)}`);
  });
  // 取消当前已订阅的所有回调函数
  inputConsumer.off("keyPressed");
} catch (error) {
  console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

### 应用内拍照

在相机或扫码类应用中，用户按拍照键（KEYCODE_CAMERA = 19）可直接拍照，而不跳转系统相机应用。

```js
//应用开启
try {
  let options: inputConsumer.KeyPressedConfig = {
    key: 19,
    action: 1,
    isRepeat: false,
  }
  inputConsumer.on('keyPressed', options, (event: KeyEvent) => {
    console.log(`Subscribe success ${JSON.stringify(event)}`);
  });
} catch (error) {
  console.error(`Subscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
//应用关闭
try {
  // 取消指定回调函数
  inputConsumer.off('keyPressed', (event: KeyEvent) => {
    console.log(`Unsubscribe success ${JSON.stringify(event)}`);
  });
  // 取消当前已订阅的所有回调函数
  inputConsumer.off("keyPressed");
} catch (error) {
  console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
