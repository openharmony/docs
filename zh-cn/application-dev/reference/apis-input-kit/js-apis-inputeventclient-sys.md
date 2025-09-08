# @ohos.multimodalInput.inputEventClient (输入事件注入)(系统接口)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

输入事件注入模块，提供输入按键、鼠标/触控板、触屏输入事件注入能力。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```js
import { inputEventClient } from '@kit.InputKit';
```

## inputEventClient.injectEvent

injectEvent({KeyEvent: KeyEvent}): void

按键(包括单个按键和组合键)注入。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.INJECT_INPUT_EVENT

**参数：**

| 参数名       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| KeyEvent | [KeyEvent](#keyevent) | 是    | 按键注入描述信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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
            console.error(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputEventClient.injectKeyEvent<sup>11+</sup>

injectKeyEvent(keyEvent: KeyEventData): void

按键(包括单个按键和组合键)事件注入。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.INJECT_INPUT_EVENT

**参数：**

| 参数名       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| keyEvent | [KeyEventData](#keyeventdata11) | 是    | 按键事件注入描述信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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
            }

            class EventDown {
              keyEvent: inputEventClient.KeyEvent | null = null
            }

            let eventDown: EventDown = { keyEvent: backKeyDown }
            inputEventClient.injectKeyEvent(eventDown);

            let backKeyUp: inputEventClient.KeyEvent = {
              isPressed: false,
              keyCode: 2,
              keyDownDuration: 0,
              isIntercepted: false
            };

            class EventUp {
              keyEvent: inputEventClient.KeyEvent | null = null
            }

            let eventUp: EventUp = { keyEvent: backKeyUp }
            inputEventClient.injectKeyEvent(eventUp);
          } catch (error) {
            console.error(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```
## inputEventClient.injectMouseEvent<sup>11+</sup>

injectMouseEvent(mouseEvent: MouseEventData): void

鼠标/触控板事件注入。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.INJECT_INPUT_EVENT

**参数：**

| 参数名       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| mouseEvent | [MouseEventData](#mouseeventdata11) | 是    | 鼠标/触控板事件注入描述信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputEventClient } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let mouseButtonUpData: MouseEvent = {
              id: 0,
              deviceId: 1,
              actionTime: 2,
              screenId: 1,
              windowId: 0,
              action: 3,
              screenX: 100,
              screenY: 200,
              windowX: 100,
              windowY: 200,
              rawDeltaX: 200,
              rawDeltaY: 200,
              button: 2,
              pressedButtons: [2],
              axes: [],
              pressedKeys: [0],
              ctrlKey: false,
              altKey: false,
              shiftKey: false,
              logoKey: false,
              fnKey: false,
              capsLock: false,
              numLock: false,
              scrollLock: false,
              toolType: 1,
            }
            let mouseButtonUp: inputEventClient.MouseEventData = {
              mouseEvent: mouseButtonUpData
            }
            inputEventClient.injectMouseEvent(mouseButtonUp);

            let mouseButtonDownData: MouseEvent = {
              id: 0,
              deviceId: 1,
              actionTime: 2,
              screenId: 1,
              windowId: 0,
              action: 2,
              screenX: 100,
              screenY: 200,
              windowX: 100,
              windowY: 200,
              rawDeltaX: 200,
              rawDeltaY: 200,
              button: 2,
              pressedButtons: [2],
              axes: [],
              pressedKeys: [0],
              ctrlKey: false,
              altKey: false,
              shiftKey: false,
              logoKey: false,
              fnKey: false,
              capsLock: false,
              numLock: false,
              scrollLock: false,
              toolType: 1,
            }
            let mouseButtonDown: inputEventClient.MouseEventData = {
              mouseEvent: mouseButtonDownData
            };
            inputEventClient.injectMouseEvent(mouseButtonDown);
          }

          catch (error) {
            console.error(`Failed to inject MouseEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputEventClient.injectTouchEvent<sup>11+</sup>

injectTouchEvent(touchEvent: TouchEventData): void

触屏输入事件注入。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.INJECT_INPUT_EVENT

**参数：**

| 参数名       | 类型                    | 必填   | 说明        |
| -------- | --------------------- | ---- | --------- |
| touchEvent | [TouchEventData](#toucheventdata11) | 是    | 触屏注入描述信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputEventClient } from '@kit.InputKit';
import { Touch, TouchEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let touchEvent: Touch = {
              id: 1,
              pressedTime: 1,
              screenX: 0,
              screenY: 0,
              windowX: 0,
              windowY: 0,
              pressure: 0,
              width: 0,
              height: 0,
              tiltX: 0,
              tiltY: 0,
              toolX: 0,
              toolY: 0,
              toolWidth: 0,
              toolHeight: 0,
              rawX: 0,
              rawY: 0,
              toolType: 0,
            }

            let touchEventUpData: TouchEvent = {
              action: 1,
              sourceType: 0,
              touch: touchEvent,
              touches: [],
              id: 0,
              deviceId: 0,
              actionTime: 0,
              screenId: 0,
              windowId: 0
            }
            ;
            let touchEventUp: inputEventClient.TouchEventData = {
              touchEvent: touchEventUpData
            }
            inputEventClient.injectTouchEvent(touchEventUp);

            let touchEventDownData: TouchEvent = {
              action: 1,
              sourceType: 0,
              touch: touchEvent,
              touches: [],
              id: 0,
              deviceId: 0,
              actionTime: 0,
              screenId: 0,
              windowId: 0
            }
            ;
            let touchEventDown: inputEventClient.TouchEventData = {
              touchEvent: touchEventDownData
            }
            inputEventClient.injectTouchEvent(touchEventDown);
          } catch (error) {
            console.error(`Failed to inject touchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputEventClient.permitInjection<sup>12+</sup>

permitInjection(result: boolean): void

允许事件注入权限。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.INJECT_INPUT_EVENT

**参数：**

| 参数名    | 类型    | 必填   | 说明        |
| -------- | ------  | ----   | --------- |
| result   | boolean | 是     | 授权结果（true表示：允许事件注入，false表示：不允许事件注入）。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |


```ts
import { inputEventClient } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let result = true;
            inputEventClient.permitInjection(result);
          }catch(error){
            console.error("failed:" + JSON.stringify(error));
          }
        })
    }
  }
}
```

## KeyEvent

按键注入描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 只读   | 可选   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| isPressed       | boolean | 否    |  否 | 按键是否按下。<br>true表示按键按下，false表示按键抬起。   |
| keyCode         | number  | 否    |  否 | 按键键值。当前仅支持返回键/KEYCODE_BACK键。 |
| keyDownDuration | number  | 否    |  否 | 按键按下持续时间，单位：μs。           |
| isIntercepted   | boolean | 否    |  否 | 按键是否可以被拦截。<br>true表示可以被拦截，false表示不可被拦截。 |

## KeyEventData<sup>11+</sup>

按键注入描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 必填   | 说明      |
| --------- | ------ | ---- |  ------- |
| keyEvent | [KeyEvent](#keyevent) | 是    | 按键注入描述信息。   |

## MouseEventData<sup>11+</sup>

鼠标注入描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 只读   | 可选   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| mouseEvent | [MouseEvent](js-apis-mouseevent.md#mouseevent) | 否    |  否 | 鼠标事件。   |
| useGlobalCoordinate<sup>20+</sup> | boolean | 否    |  是 | 是否使用全局坐标来计算注入的鼠标事件。默认值为false，取值为false表示使用以指定屏幕左上角为原点的相对坐标系的坐标来计算注入的鼠标事件。取值为true表示使用以主屏左上角为原点的全局坐标系的坐标来计算注入的鼠标事件。  |

## TouchEventData<sup>11+</sup>

触屏注入描述信息。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 只读   | 可选   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| touchEvent | [TouchEvent](js-apis-touchevent.md#touchevent) | 否    |  否 | 触屏输入事件。   |
| useGlobalCoordinate<sup>20+</sup> | boolean | 否    |  是 | 是否使用全局坐标来计算注入的触屏输入事件。默认值为false，取值为false表示使用以指定屏幕左上角为原点的相对坐标系的坐标来计算注入的触屏输入事件。取值为true表示使用以主屏左上角为原点的全局坐标系的坐标来计算注入的触屏输入事件。   |