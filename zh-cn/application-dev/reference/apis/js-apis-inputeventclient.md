# @ohos.multimodalInput.inputEventClient (设备注入)

设备注入模块，提供设备注入能力。

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

按键(包括单个按键和组合键)注入。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**参数：**

| 参数名       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| KeyEvent | [KeyEvent](#keyevent) | 是    | 按键注入描述信息。 |

**示例：**

```js
try {
  let backKeyDown: inputEventClient.KeyEvent = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }

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
  };

  class EventUp {
    KeyEvent: inputEventClient.KeyEvent | null = null
  }

  let eventUp: EventUp = { KeyEvent: backKeyUp }
  inputEventClient.injectEvent(eventUp);
} catch (error) {
  console.log(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
## inputEventClient.injectMouseEvent<sup>11+</sup>

injectMouseEvent(mouseEvent: MouseEventData): void;

鼠标/触摸板事件注入。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**参数：**

| 参数名       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| mouseEvent | [MouseEventData](#mouseeventdata11) | 是    | 鼠标/触摸板事件注入描述信息。 |

**示例：**

```js
try {
  let mouseButtonUpData = {
    isPressed: true,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }
  let mouseButtonUp: inputEventClient.MouseEventData = {
    mouseEvent: mouseButtonUpData
  }
  inputEventClient.injectMouseEvent(mouseButtonUp);

  let mouseButtonDownData = {
    isPressed: false,
    keyCode: 2,
    keyDownDuration: 0,
    isIntercepted: false
  }
  let mouseButtonDown: inputEventClient.MouseEventData = {
    mouseEvent: mouseButtonDownData
  };
  inputEventClient.injectMouseEvent(mouseButtonDown);
} catch (error) {
  console.log(`Failed to inject MouseEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputEventClient.injectTouchEvent<sup>11+</sup>

injectTouchEvent(touchEvent: TouchEventData): void;

触摸屏事件注入。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**参数：**

| 参数名       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| touchEvent | [TouchEventData](#toucheventdata11) | 是    | 触摸屏事件注入描述信息。 |

**示例：**

```js
try {
  let touchEvent = {
    screenX: 200,
    screenY: 620,
    pressedTime: 0,
  }
  let touchEventUpData = {
    action: 1,
    sourceType: 0,
    touch: touchEvent
  };
  let touchEventUp: inputEventClient.MouseEventData = {
    touchEvent: touchEventUpData
  }
  inputEventClient.injectTouchEvent(touchEventUp);

  let touchEventDownData = {
    action: 3,
    sourceType: 0,
    touch: touchEvent
  };
  let touchEventDown: inputEventClient.MouseEventData = {
    touchEvent: touchEventDownData
  }
    inputEventClient.injectTouchEvent(touchEventDown);
} catch (error) {
    console.log(`Failed to inject touchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## KeyEvent

按键注入描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 可读   | 可写   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| isPressed       | boolean | 是    |  否 | 按键是否按下。<br>ture表示按键按下，false表示按键抬起。   |
| keyCode         | number  | 是    |  否 | 按键键码值。当前仅支持返回键/KEYCODE_BACK键。 |
| keyDownDuration | number  | 是    |  否 | 按键按下持续时间，单位为微秒（μs）。           |
| isIntercepted   | boolean | 是    |  否 | 按键是否可以被拦截。<br>ture表示可以被拦截，false表示不可被拦截。 |

## MouseEventData<sup>11+</sup>

鼠标注入描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 可读   | 可写   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| mouseEvent | [MouseEvent](../apis/js-apis-mouseevent.md) | 是    |  否 | 鼠标注入描述信息。   |

## TouchEventData<sup>11+</sup>

触摸屏注入描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 可读   | 可写   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| touchEvent | [TouchEvent](../apis/js-apis-touchevent.md) | 是    |  否 | 触摸屏注入描述信息。   |

