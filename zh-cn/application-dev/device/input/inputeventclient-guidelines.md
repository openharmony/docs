# 事件注入开发指导

## 场景介绍

事件注入提供注入输入事件功能，比如注入鼠标点击事件、键盘组合键等。使用场景例如：当用户需要验证应用的组合键功能时，开发者可以通过注入组合键事件判断功能是否生效。

## 导入模块

```js
import { inputEventClient } from '@kit.InputKit';
```

## 接口说明

事件注入常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.inputEventClient文档](../../reference/apis-input-kit/js-apis-inputeventclient-sys.md)。

| 接口名称  | 描述 |
| -------------------------------------------- | -------------------------- |
| injectEvent({KeyEvent: KeyEvent}): void |按键（包括单个按键和组合键）注入。 |
| injectMouseEvent(mouseEvent: MouseEventData): void |鼠标/触摸板事件注入。 |
| injectTouchEvent(touchEvent: TouchEventData): void |触摸屏事件注入。|

## 开发步骤

应用调用Home键返回桌面，调用[injectEvent](../../reference/apis-input-kit/js-apis-inputeventclient-sys.md#inputeventclientinjectevent)注入Home按键，查看应用中Home按键功能是否生效。

```js
import { inputEventClient } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let backKeyDown: inputEventClient.KeyEvent = {
              isPressed: true,
              keyCode: 2,
              keyDownDuration: 0,
              isIntercepted: false
            }//Home按键按下事件

            class EventDown {
              KeyEvent: inputEventClient.KeyEvent | null = null
            }

            let eventDown: EventDown = { KeyEvent: backKeyDown }
            inputEventClient.injectEvent(eventDown);//注入Home按键按下事件

            let backKeyUp: inputEventClient.KeyEvent = {
              isPressed: false,
              keyCode: 2,
              keyDownDuration: 0,
              isIntercepted: false
            };//Home按键抬起事件

            class EventUp {
              KeyEvent: inputEventClient.KeyEvent | null = null
            }

            let eventUp: EventUp = { KeyEvent: backKeyUp }
            inputEventClient.injectEvent(eventUp);//注入Home按键抬起事件,查看Home键功能是否生效，应用是否返回桌面
          } catch (error) {
            console.error(`Failed to inject KeyEvent, error: ${JSON.stringify(error, ["code", "message"])}`);
          }
        })
    }
  }
}
```

