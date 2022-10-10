# 注入按键

InputEventClient模块提供了注入按键能力。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。


## 导入模块


```js
import inputEventClient from '@ohos.multimodalInput.inputEventClient';
```


## inputEventClient.injectEvent

injectEvent({KeyEvent: KeyEvent}): void

注入按键，KeyEvent为注入按键的描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**参数：**

| 参数       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| KeyEvent | [KeyEvent](#keyevent) | 是    | 注入按键的描述信息 |

**示例：**

```js
try {
  var keyEvent = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }
  inputEventClient.injectKeyEvent({ KeyEvent: keyEvent });
  var keyEvent1 = {
    isPressed: false,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  };
  inputEventClient.injectKeyEvent({ KeyEvent: keyEvent1 });
} catch (error) {
  console.info("injectKeyEvent " + error.code + " " + error.message);
}
```


## KeyEvent

注入按键的描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 参数              | 类型      | 必填   | 说明        |
| --------------- | ------- | ---- | --------- |
| isPressed       | boolean | 是    | 按键是否按下    |
| keyCode         | number  | 是    | 按键键值      |
| keyDownDuration | number  | 是    | 按键按下持续时间  |
| isIntercepted   | boolean | 是    | 按键是否可以被拦截 |
