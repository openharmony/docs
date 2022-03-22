# 注入按键


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口均为系统接口，三方应用不支持调用。


## 导入模块


```
import inputEventClient from '@ohos.multimodalInput.inputEventClient';
```


## inputEventClient.injectEvent

injectEvent({KeyEvent: KeyEvent}): void

注入按键，KeyEvent为注入按键的描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**参数：**

| 参数 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| KeyEvent | [KeyEvent](#keyevent) | 是 | 注入按键的描述信息 |

**示例：**

```
let keyEvent = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
}
res = inputEventClient.injectEvent({KeyEvent: keyEvent});
```


## KeyEvent

注入按键的描述信息

**系统能力：** 以下各项对应的系统能力均为SystemCapability.MultimodalInput.Input.InputSimulator

| 参数 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isPressed | boolean | 是 | 按键是否按下 |
| keyCode | Number | 是 | 按键键值 |
| keyDownDuration | boolean | 是 | 按键按下持续时间 |
| isIntercepted | Number | 是 | 按键是否可以被拦截 |
