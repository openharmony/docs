# 按键注入

按键注入模块，提供按键注入能力。

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

按键注入，当前仅支持返回键（键值2）注入。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**参数：**

| 参数名       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| KeyEvent | [KeyEvent](#keyevent) | 是    | 按键注入描述信息。 |

**示例：**

```js
try {
  let backKeyDown = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }
  inputEventClient.injectEvent({ KeyEvent: backKeyDown });

  let backKeyUp = {
    isPressed: false,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  };
  inputEventClient.injectEvent({ KeyEvent: backKeyUp });
} catch (error) {
  console.log(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


## KeyEvent

按键注入描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 可读   | 可写   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| isPressed       | boolean | 是    |  否 | 按键是否按下。               |
| keyCode         | number  | 是    |  否 | 按键键值，当前只支持back键。 |
| keyDownDuration | number  | 是    |  否 | 按键按下持续时间。           |
| isIntercepted   | boolean | 是    |  否 | 按键是否可以被拦截。         |

