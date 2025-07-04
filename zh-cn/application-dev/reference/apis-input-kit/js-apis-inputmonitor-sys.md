# @ohos.multimodalInput.inputMonitor (输入监听)(系统接口)

输入监听模块，提供了监听输入设备事件的能力。输入设备事件当前包括触屏事件、鼠标输入事件和触控板输入事件。

>**说明：**
>
>- 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>- 文档中“全局”表示整个触控屏或触控板。如监听全局触屏事件，表示触摸触控板任何位置时，整个触控板的触屏事件均被监听。
>
>- 本模块接口均为系统接口。

## 导入模块

```js
import { inputMonitor } from '@kit.InputKit';
```

## inputMonitor.on('touch')

on(type: 'touch', receiver: TouchEventReceiver): void

监听全局触屏事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                  |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | 是    | 输入设备事件类型，取值'touch'。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 是    | 回调函数，异步上报触摸屏输入事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('touch', (touchEvent: TouchEvent) => {
              console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('mouse')<sup>9+</sup>

on(type: 'mouse', receiver: Callback&lt;MouseEvent&gt;): void

监听全局鼠标事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：** 

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'mouse'。 |
| receiver | Callback&lt;[MouseEvent](js-apis-mouseevent.md#mouseevent)&gt; | 是    | 回调函数，异步上报鼠标输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('mouse', (mouseEvent: MouseEvent) => {
              console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('mouse')<sup>11+</sup>

on(type: 'mouse', rect: display.Rect[], receiver: Callback&lt;MouseEvent&gt;): void

监听鼠标事件，当鼠标移动至指定矩形区域内时，触发回调任务。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：** 

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'mouse'。 |
| rect     | display.Rect[]             | 是    | 可以触发回调任务的矩形区域，可传入1至2个。 |
| receiver | Callback&lt;[MouseEvent](js-apis-mouseevent.md#mouseevent)&gt; | 是    | 回调函数，异步上报鼠标输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';
import { display } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          /**
           * 鼠标在矩形区域内时，触发的回调任务。
           */
          let callback = (mouseEvent : MouseEvent) => {
            this.getUIContext().getPromptAction().showToast({
              message: `监听成功：${JSON.stringify(mouseEvent)}`
            })
            console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
            return false;
          };

          /**
           * 触发回调事件矩形区域。
           */
          let rect: display.Rect[] = [{
            left: 100,
            top: 100,
            width: 100,
            height: 100
          }, {
            left: 600,
            top: 100,
            width: 100,
            height: 100
          }];

          try {
            inputMonitor.on('mouse', rect, callback);
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('touch')

off(type: 'touch', receiver?: TouchEventReceiver): void

取消监听全局触屏事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                  |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | 是    | 输入设备事件类型，取值'touch'。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 否    | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (touchEvent: TouchEvent) => {
            console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('touch', callback);
            inputMonitor.off('touch', callback);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (touchEvent: TouchEvent) => {
            console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('touch', callback);
            inputMonitor.off('touch');
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('mouse')<sup>9+</sup>

off(type: 'mouse', receiver?: Callback&lt;MouseEvent&gt;): void

取消监听全局鼠标事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'mouse'。 |
| receiver | Callback&lt;MouseEvent&gt; | 否    | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (mouseEvent: MouseEvent) => {
            console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('mouse', callback);
            inputMonitor.off('mouse', callback);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (mouseEvent: MouseEvent) => {
            console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('mouse', callback);
            inputMonitor.off('mouse');
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## TouchEventReceiver

(touchEvent: TouchEvent): Boolean

触屏输入事件的回调函数。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](js-apis-touchevent.md#touchevent) | 是    | 触屏输入事件。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| Boolean | 若返回true，本次触屏后续产生的事件不再分发到窗口；若返回false，本次触屏后续产生的事件还会分发到窗口。 |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchEvent } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('touch', touchEvent => {
              if (touchEvent.touches.length == 3) { // 当前有三个手指按下
                return true;
              }
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('pinch')<sup>10+</sup>

on(type: 'pinch', receiver: Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt;): void

监听全局触控板的捏合事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'pinch'。 |
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | 是    | 回调函数，异步上报捏合输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('pinch', (pinchEvent) => {
              console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('pinch')<sup>10+</sup>

off(type: 'pinch', receiver?: Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt;): void

取消监听全局触控板的捏合事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'pinch'。 |
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | 否    | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (pinchEvent: Pinch) => {
            console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('pinch', callback);
            inputMonitor.off('pinch', callback);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (pinchEvent: Pinch) => {
            console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('pinch', callback);
            inputMonitor.off('pinch');
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('threeFingersSwipe')<sup>10+</sup>

on(type: 'threeFingersSwipe', receiver: Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt;): void

监听全局触控板的三指滑动事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'threeFingersSwipe'。 |
| receiver | Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt; | 是    | 回调函数，异步上报三指滑动输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('threeFingersSwipe', (threeFingersSwipe) => {
              console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('threeFingersSwipe')<sup>10+</sup>

off(type: 'threeFingersSwipe', receiver?: Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt;): void

取消监听全局触控板的三指滑动事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'threeFingersSwipe'。 |
| receiver | Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt; | 否    | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { ThreeFingersSwipe } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (threeFingersSwipe: ThreeFingersSwipe) => {
            console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
            return false;
          };
          try {
            inputMonitor.on('threeFingersSwipe', callback);
            inputMonitor.off("threeFingersSwipe", callback);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { ThreeFingersSwipe } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (threeFingersSwipe: ThreeFingersSwipe) => {
            console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
            return false;
          };
          try {
            inputMonitor.on("threeFingersSwipe", callback);
            inputMonitor.off("threeFingersSwipe");
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('fourFingersSwipe')<sup>10+</sup>

on(type: 'fourFingersSwipe', receiver: Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt;): void

监听全局触控板的四指滑动事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'fourFingersSwipe'。 |
| receiver | Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt; | 是    | 回调函数，异步上报四指滑动输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('fourFingersSwipe', (fourFingersSwipe) => {
              console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('fourFingersSwipe')<sup>10+</sup>

off(type: 'fourFingersSwipe', receiver?: Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt;): void

取消监听全局触控板的四指滑动事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'fourFingersSwipe'。 |
| receiver | Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt; | 否    | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { FourFingersSwipe } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (fourFingersSwipe: FourFingersSwipe) => {
            console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
            return false;
          };
          try {
            inputMonitor.on('fourFingersSwipe', callback);
            inputMonitor.off('fourFingersSwipe', callback);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { FourFingersSwipe } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (fourFingersSwipe: FourFingersSwipe) => {
            console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
            return false;
          };
          try {
            inputMonitor.on('fourFingersSwipe', callback);
            inputMonitor.off('fourFingersSwipe');
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('rotate')<sup>11+</sup>

on(type: 'rotate', fingers: number, receiver: Callback&lt;Rotate&gt;): void

监听全局触控板的旋转事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'rotate'。 |
| fingers     | number                     | 是    | 旋转的手指数，目前支持监听手指数是2。 |
| receiver | Callback&lt;[Rotate](js-apis-multimodalinput-gestureevent.md#rotate11)&gt; | 是    | 回调函数，异步上报旋转输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Rotate } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('rotate', 2, (rotateEvent: Rotate) => {
              console.log(`Monitor on success ${JSON.stringify(rotateEvent)}`);
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('rotate')<sup>11+</sup>

off(type: 'rotate', fingers: number, receiver?: Callback&lt;Rotate&gt;): void

取消监听全局触控板的旋转事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'rotate'。 |
| fingers     | number                     | 是    | 旋转的手指数，目前支持监听手指数是2。 |
| receiver | Callback&lt;[Rotate](js-apis-multimodalinput-gestureevent.md#rotate11)&gt; | 否    | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Rotate } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (rotateEvent: Rotate) => {
            console.log(`Monitor on success ${JSON.stringify(rotateEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('rotate', 2, callback);
            inputMonitor.off('rotate', 2, callback);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { Rotate } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (rotateEvent: Rotate) => {
            console.log(`Monitor on success ${JSON.stringify(rotateEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('rotate', 2, callback);
            inputMonitor.off('rotate', 2);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('pinch')<sup>11+</sup>

on(type: 'pinch', fingers: number, receiver: Callback&lt;Pinch&gt;): void

监听全局触控板的捏合事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'pinch'。 |
| fingers     | number                     | 是    | 捏合的手指数，取值范围：大于等于2。 |
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | 是    | 回调函数，异步上报捏合输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('pinch', 2, (pinchEvent: Pinch) => {
              console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('pinch')<sup>11+</sup>

off(type: 'pinch', fingers: number, receiver?: Callback&lt;Pinch&gt;): void

取消监听全局触控板的捏合事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'pinch'。 |
| fingers     | number                     | 是    | 捏合的手指数，取值范围：大于等于2。 |
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | 否    | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (pinchEvent: Pinch) => {
            console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('pinch', 2, callback);
            inputMonitor.off('pinch', 2, callback);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (pinchEvent: Pinch) => {
            console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
            return false;
          };
          try {
            inputMonitor.on('pinch', 2, callback);
            inputMonitor.off('pinch', 2);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('threeFingersTap')<sup>11+</sup>

on(type: 'threeFingersTap', receiver: Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap11)&gt;): void

监听全局触控板的三指轻点事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 输入设备事件类型，取值'threeFingersTap'。 |
| receiver | Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap11)&gt; | 是   | 回调函数，异步上报三指轻点输入事件。      |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputMonitor.on('threeFingersTap', (threeFingersTap) => {
              console.log(`Monitor on success ${JSON.stringify(threeFingersTap)}`);
              return false;
            });
          } catch (error) {
            console.error(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('threeFingersTap')<sup>11+</sup>

off(type: 'threeFingersTap', receiver?: Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap11)&gt;): void

取消监听全局触控板的三指轻点事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'threeFingersTap'。                    |
| receiver | Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap11)&gt; | 否   | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { ThreeFingersTap } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (threeFingersTap: ThreeFingersTap) => {
            console.log(`Monitor on success ${JSON.stringify(threeFingersTap)}`);
            return false;
          };
          try {
            inputMonitor.on('threeFingersTap', callback);
            inputMonitor.off("threeFingersTap", callback);
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { ThreeFingersTap } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (threeFingersTap: ThreeFingersTap) => {
            console.log(`Monitor on success ${JSON.stringify(threeFingersTap)}`);
            return false;
          };
          try {
            inputMonitor.on('threeFingersTap', callback);
            inputMonitor.off("threeFingersTap");
            console.log(`Monitor off success`);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('touchscreenSwipe')<sup>18+</sup>

on(type: 'touchscreenSwipe', fingers: number, receiver: Callback&lt;TouchGestureEvent&gt;): void

监听触摸屏滑动手势事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'touchscreenSwipe'。                    |
| fingers  | number                                                       | 是   | 滑动手势的手指数，取值范围：[3,5]。 |
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent)&gt; | 是   | 回调函数，异步上报触摸屏滑动手势事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let fingers: number = 4;
          try {
            inputMonitor.on('touchscreenSwipe', fingers, (event: TouchGestureEvent) => {
              console.log(`Monitor on success ${JSON.stringify(event)}`);
            });
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('touchscreenSwipe')<sup>18+</sup>

off(type: 'touchscreenSwipe', fingers: number, receiver?: Callback&lt;TouchGestureEvent&gt;): void

取消监听触摸屏滑动手势事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'touchscreenSwipe'。                    |
| fingers  | number                                                       | 是   | 滑动手势的手指数，取值范围：[3,5]。 |
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent)&gt; | 否   | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (event: TouchGestureEvent) => {
            console.log(`Monitor on success ${JSON.stringify(event)}`);
          };
          let fingers: number = 4;
          try {
            inputMonitor.on('touchscreenSwipe', fingers, callback);
            inputMonitor.off('touchscreenSwipe', fingers, callback);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let fingers: number = 4;
          try {
            inputMonitor.on('touchscreenSwipe', fingers, (event: TouchGestureEvent) => {
              console.log(`Monitor on success ${JSON.stringify(event)}`);
            });
            inputMonitor.off('touchscreenSwipe', fingers);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('touchscreenPinch')<sup>18+</sup>

on(type: 'touchscreenPinch', fingers: number, receiver: Callback&lt;TouchGestureEvent&gt;): void

监听触摸屏捏合手势事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'touchscreenPinch'。                    |
| fingers  | number                                                       | 是   | 捏合手势的手指数，取值范围：[4,5]。 |
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent)&gt; | 是   | 回调函数，异步上报触摸屏捏合手势事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let fingers: number = 4;
          try {
            inputMonitor.on('touchscreenPinch', fingers, (event: TouchGestureEvent) => {
              console.log(`Monitor on success ${JSON.stringify(event)}`);
            });
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('touchscreenPinch')<sup>18+</sup>

off(type: 'touchscreenPinch', fingers: number, receiver?: Callback&lt;TouchGestureEvent&gt;): void

取消监听触摸屏捏合手势事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'touchscreenPinch'。                    |
| fingers  | number                                                       | 是   | 捏合手势的手指数，取值范围：[4,5]。 |
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent)&gt; | 否   | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (event: TouchGestureEvent) => {
            console.log(`Monitor on success ${JSON.stringify(event)}`);
          };
          let fingers: number = 4;
          try {
            inputMonitor.on('touchscreenPinch', fingers, callback);
            inputMonitor.off("touchscreenPinch", fingers, callback);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@ohos.multimodalInput.gestureEvent';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let fingers: number = 4;
          try {
            inputMonitor.on('touchscreenPinch', fingers, (event: TouchGestureEvent) => {
              console.log(`Monitor on success ${JSON.stringify(event)}`);
            });
            inputMonitor.off("touchscreenPinch", fingers);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.on('keyPressed')<sup>15+</sup>

on(type: 'keyPressed', keys: Array&lt;KeyCode&gt;, receiver: Callback&lt;KeyEvent&gt;): void

监听指定按键的按下抬起事件，支持监听META_LEFT键、META_RIGHT键、电源键、音量键。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                 |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                      | 是   | 按键事件类型，取唯一值'keyPressed'。 |
| keys     | Array<[KeyCode](js-apis-keycode.md#keycode)> | 是   | 按键码列表，支持如下取值：KEYCODE_META_LEFT、KEYCODE_META_RIGHT、KEYCODE_POWER、KEYCODE_VOLUME_DOWN、KEYCODE_VOLUME_UP。                      |
| receiver | Callback&lt;[KeyEvent](js-apis-keyevent.md#keyevent)&gt;    | 是   | 用于接收上报数据的回调函数。         |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[按键监听错误码](./errorcode-inputmonitor.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied, non-system app called system api.         |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 4100001  | Event listening not supported for the key.                   |

**示例：**

```js
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let keys: Array<KeyCode> = [KeyCode.KEYCODE_VOLUME_UP];
            inputMonitor.on('keyPressed', keys, (event: KeyEvent ) => {
              console.log(`Monitor on success ${JSON.stringify(event)}`);
            });
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.off('keyPressed')<sup>15+</sup>

off(type: 'keyPressed', receiver?: Callback&lt;KeyEvent&gt;): void

取消监听按键按下抬起事件。支持取消监听META_LEFT键、META_RIGHT键、电源键、音量键。需和inputMonitor.on('keyPressed')配套使用。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | 是   | 按键事件类型，取唯一值'keyPressed'。                         |
| receiver | Callback&lt;[KeyEvent](js-apis-keyevent.md#keyevent)&gt; | 否   | 需要取消监听的回调函数。若不填，取消应用所有按键监听的回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied, non-system app called system api.         |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          try {
            let callback = (event: KeyEvent) => {
              console.log(`Monitor on success ${JSON.stringify(event)}`);
            };
            let keys: Array<KeyCode> = [KeyCode.KEYCODE_VOLUME_UP];
            inputMonitor.on('keyPressed', keys, callback);
            inputMonitor.off("keyPressed", callback);
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          try {
            let keys: Array<KeyCode> = [KeyCode.KEYCODE_VOLUME_UP];
            inputMonitor.on('keyPressed', keys, (event: KeyEvent) => {
              console.log(`Monitor on success ${JSON.stringify(event)}`);
            });
            inputMonitor.off("keyPressed");
          } catch (error) {
            console.error(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputMonitor.queryTouchEvents()<sup>20+</sup>

queryTouchEvents(count: number): Promise&lt;Array&lt;TouchEvent&gt;&gt;

查询最近的触屏事件，最多支持查询 100 条事件，使用Promise异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| count     | number                                                    | 是   | 要查询的触屏事件数量。取值范围为1-100的整数。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[TouchEvent](js-apis-touchevent-sys.md#touchevent)&gt;&gt; | Promise对象，返回查询到的触屏事件。包含以下有效信息：<br/>- actionTime：触屏事件发生的时间，表示从1970.1.1 00:00:00 GMT逝去的微秒数。<br/>- [SourceType](js-apis-touchevent.md#sourcetype)：触摸来源的设备类型。<br/>- [isInject](js-apis-touchevent-sys.md#touchevent)：表示该触屏事件是否为注入事件。<br/>- pressure：压力值，取值范围是[0.0, 1.0]，0.0表示不支持。<br/>- tiltX：相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。<br/>- tiltY：相对XZ平面的角度，取值的范围[-90, 90]，其中正值是向下倾斜。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied, non-system app called system api.         |

**示例：**

```js
import { inputMonitor, TouchEvent } from '@kit.InputKit'
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMonitor.queryTouchEvents(10).then((events: Array<TouchEvent>) => {
    events.forEach((event, index) => {
      console.info(`Touch event ${index}: actionTime=${event.actionTime}, sourceType=${event.sourceType}`);
    });
  }).catch((error: BusinessError) => {
    console.error('queryTouchEvents promise error: ' + JSON.stringify(error));
  });
} catch (error) {
  const code = (error as BusinessError).code;
  const message = (error as BusinessError).message;
  console.error(`queryTouchEvents failed, error code: ${code}, message: ${message}.`);
}
```
