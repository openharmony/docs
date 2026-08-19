# @ohos.multimodalInput.inputEventClient (输入事件注入)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->

输入事件注入模块，提供输入按键、鼠标/触控板、触屏输入事件注入能力。

**起始版本：** 26.0.0

## 导入模块

```js
import { inputEventClient } from '@kit.InputKit';
```

## inputEventClient.createKeyboardController

createKeyboardController(): Promise&lt;KeyboardController&gt;

创建键盘控制器，用于模拟按键操作。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上返回801错误码。

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;[KeyboardController](#keyboardcontroller)&gt; | Promise对象，返回键盘控制器实例。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 801  | Capability not supported.  |
| 3800001  | Input service exception.  |

**示例：**

```js
import { inputEventClient } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputEventClient.createKeyboardController()
            .then(keyboardController => {
              console.info('Succeeded in creating keyboard controller');
            })
            .catch((error: BusinessError) => {
              console.error(`Failed to create keyboard controller. Code: ${error.code}, message: ${error.message}.`);
            });
        })
    }
  }
}
```

## inputEventClient.createMouseController

createMouseController(): Promise&lt;MouseController&gt;

创建鼠标控制器，用于模拟鼠标操作。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上返回801错误码。

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;[MouseController](#mousecontroller)&gt; | Promise对象，返回鼠标控制器实例。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 801  | Capability not supported.  |
| 3800001  | Input service exception.  |

**示例：**

```js
import { inputEventClient } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputEventClient.createMouseController()
            .then(mouseController => {
              console.info('Succeeded in creating mouse controller');
            })
            .catch((error: BusinessError) => {
              console.error(`Failed to create mouse controller. Code: ${error.code}, message: ${error.message}.`);
            });
        })
    }
  }
}
```

## inputEventClient.createTouchController

createTouchController(): Promise&lt;TouchController&gt;

创建触控控制器，用于模拟触控操作。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上返回801错误码。

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;[TouchController](#touchcontroller)&gt; | Promise对象，返回触控控制器实例。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 801  | Capability not supported.  |
| 3800001  | Input service exception.  |

**示例：**

```js
import { inputEventClient } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputEventClient.createTouchController()
            .then(touchController => {
              console.info('Succeeded in creating touch controller');
            })
            .catch((error: BusinessError) => {
              console.error(`Failed to create touch controller. Code: ${error.code}, message: ${error.message}.`);
            });
        })
    }
  }
}
```

## KeyboardController

提供模拟按键操作的功能。模拟按键操作序列必须满足以下要求：

1. 按键只能在抬起状态下被按下，或者在该按键是最近按下的按键且未抬起的情况下被按下。
2. 按键只能在被按下后才能抬起。
3. 最多可以同时按下并保持五个按键。

### pressKey

pressKey(keyCode: KeyCode): Promise&lt;void&gt;

按下按键。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名      | 类型                   | 必填  | 说明       |
| -------- | --------------------- | ---- | --------- |
| keyCode | [KeyCode](js-apis-keycode.md#keycode) | 是   | 要按下的按键键码。|

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 3800001  | Input service exception.  |
| 4300001  | The key is already pressed and is not the most recently pressed key.  |

**示例：**

```js
import { inputEventClient, KeyCode } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputEventClient.createKeyboardController()
            .then((keyboardController: inputEventClient.KeyboardController) => {
              keyboardController.pressKey(KeyCode.KEYCODE_A);
              return keyboardController;
            })
            .then((keyboardController: inputEventClient.KeyboardController) => {
              keyboardController.releaseKey(KeyCode.KEYCODE_A);
            })
            .then(() => {
              console.info('Succeeded in releasing key');
            })
            .catch((error: BusinessError) => {
              console.error(`Failed to release key. Code: ${error.code}, message: ${error.message}.`);
            });
        })
    }
  }
}
```

### releaseKey

releaseKey(keyCode: KeyCode): Promise&lt;void&gt;

抬起按键。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名      | 类型                   | 必填  | 说明       |
| -------- | --------------------- | ---- | --------- |
| keyCode | [KeyCode](js-apis-keycode.md#keycode) | 是   | 要抬起的按键键码。|

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 3800001  | Input service exception.  |
| 4300001  | The key is not pressed.  |

**示例：**

参见[pressKey](#presskey)示例。

## MouseController

提供模拟鼠标操作的功能。模拟鼠标操作序列必须满足以下要求：

1. 鼠标按键只能在抬起状态下被按下。
2. 鼠标按键只能在被按下后才能抬起。
3. 有效的轴事件序列必须先调用beginAxis开始事件，然后调用零次或多次updateAxis更新事件，最后调用endAxis结束事件。
4. 同一时间只能有一个进行中的轴事件序列。

### moveTo

moveTo(displayId: number, displayX: number, displayY: number): Promise&lt;void&gt;

将鼠标光标移动到指定的显示器坐标。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名      | 类型                   | 必填  | 说明       |
| -------- | --------------------- | ---- | --------- |
| displayId | number | 是   | 目标显示器ID。|
| displayX | number | 是   | 目标位置相对于显示器左边缘的X坐标，单位为像素（px）。若超出显示器有效范围，则实际坐标值会规约到有效范围[0, 显示器宽度-1]。|
| displayY | number | 是   | 目标位置相对于显示器上边缘的Y坐标，单位为像素（px）。若超出显示器有效范围，则实际坐标值会规约到有效范围[0, 显示器高度-1]。|

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 3800001  | Input service exception.  |
| 4300002  | The display does not exist.  |

**示例：**

```js
import { inputEventClient } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputEventClient.createMouseController()
            .then(mouseController => {
              return mouseController.moveTo(0, 100, 200);
            })
            .then(() => {
              console.info('Succeeded in moving mouse');
            })
            .catch((error: BusinessError) => {
              console.error(`Failed to move mouse. Code: ${error.code}, message: ${error.message}.`);
            });
        })
    }
  }
}
```

### pressButton

pressButton(button: Button): Promise&lt;void&gt;

按下鼠标按键。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名      | 类型                   | 必填  | 说明       |
| -------- | --------------------- | ---- | --------- |
| button | [Button](js-apis-mouseevent.md#button) | 是   | 要按下的鼠标按键。|

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 3800001  | Input service exception.  |
| 4300001  | The mouse button is already pressed.  |

**示例：**

```js
import { inputEventClient, Button } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputEventClient.createMouseController()
            .then((mouseController: inputEventClient.MouseController) => {
              mouseController.pressButton(Button.LEFT);
              return mouseController;
            })
            .then((mouseController: inputEventClient.MouseController) => {
              mouseController.releaseButton(Button.LEFT);
            })
            .then(() => {
              console.info('Succeeded in releasing mouse button');
            })
            .catch((error: BusinessError) => {
              console.error(`Failed to release mouse button. Code: ${error.code}, message: ${error.message}.`);
            });
        })
    }
  }
}
```

### releaseButton

releaseButton(button: Button): Promise&lt;void&gt;

抬起鼠标按键。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名      | 类型                   | 必填  | 说明       |
| -------- | --------------------- | ---- | --------- |
| button | [Button](js-apis-mouseevent.md#button) | 是   | 要抬起的鼠标按键。|

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 3800001  | Input service exception.  |
| 4300001  | The mouse button is not pressed.  |

**示例：**

参见[pressButton](#pressbutton)示例。

### beginAxis

beginAxis(axis: Axis, value: number): Promise&lt;void&gt;

开始轴事件。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名      | 类型                   | 必填  | 说明       |
| -------- | --------------------- | ---- | --------- |
| axis | [Axis](js-apis-mouseevent.md#axis) | 是   | 轴类型。|
| value | number | 是   | 轴值。|

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 3800001  | Input service exception.  |
| 4300001  | The axis event is in progress.  |

**示例：**

```js
import { inputEventClient, Axis } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputEventClient.createMouseController()
            .then((mouseController: inputEventClient.MouseController) => {
              mouseController.beginAxis(Axis.SCROLL_VERTICAL, 10);
              return mouseController;
            })
            .then((mouseController: inputEventClient.MouseController) => {
              mouseController.updateAxis(Axis.SCROLL_VERTICAL, 20);
              return mouseController;
            })
            .then((mouseController: inputEventClient.MouseController) => {
              mouseController.endAxis(Axis.SCROLL_VERTICAL);
            })
            .then(() => {
              console.info('Succeeded in ending axis event');
            })
            .catch((error: BusinessError) => {
              console.error(`Failed to end axis event. Code: ${error.code}, message: ${error.message}.`);
            });
        })
    }
  }
}
```

### updateAxis

updateAxis(axis: Axis, value: number): Promise&lt;void&gt;

更新轴事件。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名      | 类型                   | 必填  | 说明       |
| -------- | --------------------- | ---- | --------- |
| axis | [Axis](js-apis-mouseevent.md#axis) | 是   | 轴类型。|
| value | number | 是   | 轴值。|

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 3800001  | Input service exception.  |
| 4300001  | The axis event is not in progress.  |

**示例：**

参见[beginAxis](#beginaxis)示例。

### endAxis

endAxis(axis: Axis): Promise&lt;void&gt;

结束轴事件。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名      | 类型                   | 必填  | 说明       |
| -------- | --------------------- | ---- | --------- |
| axis | [Axis](js-apis-mouseevent.md#axis) | 是   | 轴类型。|

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 3800001  | Input service exception.  |
| 4300001  | The axis event is not in progress.  |

**示例：**

参见[beginAxis](#beginaxis)示例。

## TouchPoint

表示屏幕上的单个触点信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

| 名称        | 类型   | 只读   | 可选   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| id | number | 否 | 否 | 触点唯一标识。取值范围为[0, 9]，且必须为整数。 |
| displayId | number | 否 | 否 | 触点所在屏幕的唯一标识，必须为整数。 |
| displayX | number | 否 | 否 | 触点相对于屏幕左边缘的X坐标，单位为像素（px），必须为整数。 |
| displayY | number | 否 | 否 | 触点相对于屏幕上边缘的Y坐标，单位为像素（px），必须为整数。 |

## TouchController

提供模拟触控操作的功能。模拟触控操作序列必须满足以下要求：

1. 所有触点的displayId必须相同。
2. 每个触点都必须以`touchDown()`开始，以`touchUp()`结束，中间可包含多个`touchMove()`。

### touchDown

touchDown(touch: TouchPoint): Promise&lt;void&gt;

触点按下。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| touch | [TouchPoint](#touchpoint) | 是 | 与屏幕接触的触点信息。 |

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 4300001 | Invalid input event sequence. Possible causes: 1. The touch point is touching the display; 2. The touch point ID is not within the valid range [0,9]. |
| 4300002 | The display does not exist. |
| 3800001 | Input service exception. |

**示例：**

```js
import { inputEventClient } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputEventClient.createTouchController()
            .then((touchController: inputEventClient.TouchController) => {
              const touchPoint: inputEventClient.TouchPoint = {
                id: 0,
                displayId: 0,
                displayX: 600,
                displayY: 1200
              };
              touchController.touchDown(touchPoint);
              return touchController;
            })
            .then((touchController: inputEventClient.TouchController) => {
              touchController.touchMove({
                id: 0,
                displayId: 0,
                displayX: 720,
                displayY: 1200
              });
              return touchController;
            })
            .then((touchController: inputEventClient.TouchController) => {
              touchController.touchUp({
                id: 0,
                displayId: 0,
                displayX: 720,
                displayY: 1200
              });
            })
            .then(() => {
              console.info('Succeeded in touch up');
            })
            .catch((error: BusinessError) => {
              console.error(`Failed to simulate touch. Code: ${error.code}, message: ${error.message}.`);
            });
        })
    }
  }
}
```

### touchMove

touchMove(touch: TouchPoint): Promise&lt;void&gt;

触点移动。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| touch | [TouchPoint](#touchpoint) | 是 | 需要移动的触点信息。 |

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 4300001 | Invalid input event sequence. Possible causes: 1. The touch point is not touching the display; 2. The touch point ID is not within the valid range [0,9]. |
| 3800001 | Input service exception. |

**示例：**

参见[touchDown](#touchdown)示例。

### touchUp

touchUp(touch: TouchPoint): Promise&lt;void&gt;

触点抬起。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MultimodalInput.Input.InputSimulator

**需要权限：** ohos.permission.CONTROL_DEVICE

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用，在其他设备上调用不生效。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| touch | [TouchPoint](#touchpoint) | 是 | 即将离开屏幕的触点信息。 |

**返回值：**

| 类型                   | 说明       |
| --------------------- | --------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码**：

以下错误码的详细介绍请参见[输入事件注入错误码](errorcode-inputeventclient.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 4300001 | Invalid input event sequence. Possible causes: 1. The touch point is not touching the display; 2. The touch point ID is not within the valid range [0,9]. |
| 3800001 | Input service exception. |

**示例：**

参见[touchDown](#touchdown)示例。
