# 按键拦截监听开发指导

## 场景介绍

按键拦截监听支持应用在前台状态下监听物理按键的按下事件，当前按键仅支持音量加和音量减。该接口不仅可以订阅用户按键行为，还可屏蔽按键的系统默认响应，如音量调节。

使用场景例如：开发者可在阅读类应用中监听音量键实现翻页，或在相机类应用中监听音量键实现拍照功能，从而提升用户体验。当前仅支持手机和平板设备。

## 导入模块

```js
import { inputConsumer, KeyEvent } from '@kit.InputKit';
```

## 接口说明

按键按下事件常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.inputConsumer文档](../../reference/apis-input-kit/js-apis-inputconsumer.md)。

| 接口名称  | 描述 |
| ------------------------------------------------------------ | -------------------------- |
| on(type: "keyPressed", options: KeyPressedConfig, callback: Callback\<KeyEvent>): void |订阅指定按键按下事件，拦截系统默认响应。  |
| off(type: "keyPressed", callback?: Callback\<KeyEvent>): void |取消按键事件订阅，恢复系统默认响应。  |

## 开发步骤

应用开启时调用[on](../../reference/apis-input-kit/js-apis-inputconsumer.md#inputconsumeronkeypressed16)方法订阅按键按下事件，应用关闭时再用[off](../../reference/apis-input-kit/js-apis-inputconsumer.md#inputconsumeroffkeypressed16)方法取消订阅按键按下事件。

### 音量键翻页和应用内拍照

在电子书或新闻阅读应用中，用户希望通过音量键控制翻页（例如：音量加键向下翻页，音量减键向上翻页）；在相机或扫码类应用中，用户按音量键可直接拍照，而不跳转系统相机应用。

```js
import { inputConsumer, KeyEvent } from '@kit.InputKit';
import { KeyCode } from '@kit.InputKit';

@Entry
@Component
struct TestDemo14 {
  private volumeUpCallBackFunc: (event: KeyEvent) => void = () => {
  }
  private volumeDownCallBackFunc: (event: KeyEvent) => void = () => {
  }

  aboutToAppear(): void {
    try {
      let options1: inputConsumer.KeyPressedConfig = {
        key: KeyCode.KEYCODE_VOLUME_UP,
        action: 1, // 按下按键的行为
        isRepeat: false, // 优先消费掉按键事件，不上报
      }
      let options2: inputConsumer.KeyPressedConfig = {
        key: KeyCode.KEYCODE_VOLUME_DOWN,
        action: 1, // 按下按键的行为
        isRepeat: false, // 优先消费掉按键事件，不上报
      }

      // 点击了音量按键上事件回调
      this.volumeUpCallBackFunc = (event: KeyEvent) => {
        this.getUIContext().getPromptAction().showToast({ message: '点击了音量按键上' })
        // do something
      }

      // 点击了音量按键下事件回调
      this.volumeDownCallBackFunc = (event: KeyEvent) => {
        this.getUIContext().getPromptAction().showToast({ message: '点击了音量按键下' })
        // do something
      }
      // 注册监听事件
      inputConsumer.on('keyPressed', options1, this.volumeUpCallBackFunc);
      inputConsumer.on('keyPressed', options2, this.volumeDownCallBackFunc);
    } catch (error) {
      console.error(`Subscribe execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
    }
  }

  build() {
    Column() {
      Row() {
        Button('取消监听音量按键上的监听')
          .onClick(() => {
            try {
              // 取消指定回调函数
              inputConsumer.off('keyPressed', this.volumeUpCallBackFunc);
              this.getUIContext().getPromptAction().showToast({ message: '取消监听音量按键上的监听事件成功！' })
            } catch (error) {
              console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
            }
          })
      }.width('100%')
      .justifyContent(FlexAlign.Center)
      .margin({ top: 20, bottom: 50 })

      Row() {
        Button('取消监听音量按键下的监听')
          .onClick(() => {
            try {
              // 取消指定回调函数
              inputConsumer.off('keyPressed', this.volumeDownCallBackFunc);
              this.getUIContext().getPromptAction().showToast({ message: '取消监听音量按键下的监听事件成功！' })
            } catch (error) {
              console.error(`Unsubscribe execute failed, error: ${JSON.stringify(error, ["code", "message"])}`);
            }
          })
      }.width('100%')
      .justifyContent(FlexAlign.Center)
      .margin({ top: 20, bottom: 50 })
      Row(){
        Text('已默认添加监听音量按键上和下的监听')
      }
      .width('100%')
      .justifyContent(FlexAlign.Center)
    }.width('100%').height('100%')
  }
}
```
