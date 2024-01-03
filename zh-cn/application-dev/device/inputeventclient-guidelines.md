# 注入事件开发指导

## 场景介绍

注入事件提供注入输入事件功能，比如注入鼠标点击事件，键盘组合键等。使用场景例如：当用户需要验证应用的组合键功能时，开发者可以通过注入组合键事件判断功能是否生效。

## 导入模块

```js
import inputEventClient from '@ohos.multimodalInput.inputEventClient';
```

## 接口说明
事件注入常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.inputEventClient文档](../reference/apis/js-apis-inputeventclient.md)。

| 接口名称  | 描述 |
| -------------------------------------------- | -------------------------- |
| injectEvent({KeyEvent: KeyEvent}): void |按键(包括单个按键和组合键)注入。 |
| injectMouseEvent(mouseEvent: MouseEventData): void |鼠标/触摸板事件注入。 |
| injectTouchEvent(touchEvent: TouchEventData): void |触摸屏事件注入。|

## 开发步骤

调用[injectEvent](../reference/apis/js-apis-inputeventclient.md#inputeventclientinjectevent)注入Home按键，查看Home按键功能是否生效。

```js
try {
  let backKeyDown: inputEventClient.KeyEvent = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }//注入Home按键按下事件

  class EventDown {
    KeyEvent: inputEventClient.KeyEvent | null = null
  }

  let eventDown: EventDown = { KeyEvent: backKeyDown }
  inputEventClient.injectEvent(eventDown);

  let backKeyUp: inputEventClient.KeyEvent = {
    isPressed: false,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  };//注入Home按键抬起事件

  class EventUp {
    KeyEvent: inputEventClient.KeyEvent | null = null
  }

  let eventUp: EventUp = { KeyEvent: backKeyUp }
  inputEventClient.injectEvent(eventUp);
} catch (error) {
  console.log(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

