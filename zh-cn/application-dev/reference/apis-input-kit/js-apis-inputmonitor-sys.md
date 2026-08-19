# @ohos.multimodalInput.inputMonitor (输入监听)(系统接口)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->

输入监听模块，提供了监听输入设备事件的能力。输入设备事件当前包括触屏输入事件、鼠标输入事件和触控板输入事件。

>**说明：**
>
>- 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>- 文档中“全局”表示整个触控屏或触控板。如监听全局触屏输入事件，表示触摸触控板任何位置时，整个触控板的触屏输入事件均被监听。
>
>- 本模块接口均为系统接口。

## 导入模块

```js
import { inputMonitor } from '@kit.InputKit';
```

## inputMonitor.on('touch')

on(type: 'touch', receiver: TouchEventReceiver): void

监听全局触屏输入事件，使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                  |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | 是    | 输入设备事件类型，取值'touch'。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 是    | 回调函数，返回触摸屏输入事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | Permission denied, non-system app called system api.<br/>适用版本：12+ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 订阅触摸事件
            inputMonitor.on('touch', (touchEvent: TouchEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(touchEvent)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor the touch screen event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('mouse')<sup>9+</sup>

on(type: 'mouse', receiver: Callback&lt;MouseEvent&gt;): void

监听全局鼠标事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：** 

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'mouse'。 |
| receiver | Callback&lt;[MouseEvent](js-apis-mouseevent.md#mouseevent)&gt; | 是    | 回调函数，返回鼠标输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | Permission denied, non-system app called system api.<br/>适用版本：12+ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 订阅鼠标事件
            inputMonitor.on('mouse', (mouseEvent: MouseEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(mouseEvent)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor the mouse event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('mouse')<sup>11+</sup>

on(type: 'mouse', rect: display.Rect[], receiver: Callback&lt;MouseEvent&gt;): void

监听鼠标事件，当鼠标移动至指定矩形区域内时，触发回调任务。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：** 

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'mouse'。 |
| rect     | [display.Rect](../apis-arkui/js-apis-display.md#rect9)[]             | 是    | 可以触发回调任务的矩形区域，可传入1至2个。 |
| receiver | Callback&lt;[MouseEvent](js-apis-mouseevent.md#mouseevent)&gt; | 是    | 回调函数，返回鼠标输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.<br/>适用版本：12+ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';
import { display } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
            console.info(`Succeeded in monitoring on ${JSON.stringify(mouseEvent)}.`);
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
            // 订阅鼠标事件
            inputMonitor.on('mouse', rect, callback);
          } catch (error) {
            console.error(`Failed to monitor the mouse event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('touch')

off(type: 'touch', receiver?: TouchEventReceiver): void

取消监听全局触屏输入事件，使用callback异步回调。

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
| 202  | Permission denied, non-system app called system api.<br/>适用版本：12+ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (touchEvent: TouchEvent) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(touchEvent)}.`);
            return false;
          };
          try {
            // 订阅触摸事件
            inputMonitor.on('touch', callback);
            // 取消订阅触摸事件
            inputMonitor.off('touch', callback);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to monitor the touch screen event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (touchEvent: TouchEvent) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(touchEvent)}.`);
            return false;
          };
          try {
            // 订阅触摸事件
            inputMonitor.on('touch', callback);
            // 取消订阅触摸事件
            inputMonitor.off('touch');
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to monitor the touch screen event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('mouse')<sup>9+</sup>

off(type: 'mouse', receiver?: Callback&lt;MouseEvent&gt;): void

取消监听全局鼠标事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'mouse'。 |
| receiver | Callback&lt;[MouseEvent](js-apis-mouseevent.md#mouseevent)&gt; | 否    | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | Permission denied, non-system app called system api.<br/>适用版本：12+ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (mouseEvent: MouseEvent) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(mouseEvent)}.`);
            return false;
          };
          try {
            // 订阅鼠标事件
            inputMonitor.on('mouse', callback);
            // 取消订阅鼠标事件
            inputMonitor.off('mouse', callback);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to monitor the mouse event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { MouseEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (mouseEvent: MouseEvent) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(mouseEvent)}.`);
            return false;
          };
          try {
            // 订阅鼠标事件
            inputMonitor.on('mouse', callback);
            // 取消订阅鼠标事件
            inputMonitor.off('mouse');
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to monitor the mouse event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## TouchEventReceiver

type TouchEventReceiver = (touchEvent: TouchEvent) => boolean

触屏输入事件的回调函数。

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](js-apis-touchevent.md#touchevent) | 是    | 触屏输入事件。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 若返回true，本次触屏后续产生的事件不再分发到窗口；若返回false，本次触屏后续产生的事件还会分发到窗口。 |

## inputMonitor.on('pinch')<sup>10+</sup>

on(type: 'pinch', receiver: Callback&lt;Pinch&gt;): void

监听全局触控板的捏合事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'pinch'。 |
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | 是    | 回调函数，返回捏合输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 订阅捏合事件
            inputMonitor.on('pinch', (pinchEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(pinchEvent)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor the pinch event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('pinch')<sup>10+</sup>

off(type: 'pinch', receiver?: Callback&lt;Pinch&gt;): void

取消监听全局触控板的捏合事件。使用callback异步回调。

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
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (pinchEvent: Pinch) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(pinchEvent)}.`);
            return false;
          };
          try {
            // 订阅捏合事件
            inputMonitor.on('pinch', callback);
            // 取消订阅捏合事件
            inputMonitor.off('pinch', callback);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor pinch event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (pinchEvent: Pinch) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(pinchEvent)}.`);
            return false;
          };
          try {
            // 订阅捏合事件
            inputMonitor.on('pinch', callback);
            // 取消订阅捏合事件
            inputMonitor.off('pinch');
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor pinch event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('threeFingersSwipe')<sup>10+</sup>

on(type: 'threeFingersSwipe', receiver: Callback&lt;ThreeFingersSwipe&gt;): void

监听全局触控板的三指滑动事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'threeFingersSwipe'。 |
| receiver | Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt; | 是    | 回调函数，返回三指滑动输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 订阅三指滑动事件
            inputMonitor.on('threeFingersSwipe', (threeFingersSwipe) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(threeFingersSwipe)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor three fingers swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('threeFingersSwipe')<sup>10+</sup>

off(type: 'threeFingersSwipe', receiver?: Callback&lt;ThreeFingersSwipe&gt;): void

取消监听全局触控板的三指滑动事件。使用callback异步回调。

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
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { ThreeFingersSwipe } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (threeFingersSwipe: ThreeFingersSwipe) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(threeFingersSwipe)}.`);
            return false;
          };
          try {
            // 订阅三指滑动事件
            inputMonitor.on('threeFingersSwipe', callback);
            // 取消订阅三指滑动事件
            inputMonitor.off('threeFingersSwipe', callback);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor three fingers swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { ThreeFingersSwipe } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (threeFingersSwipe: ThreeFingersSwipe) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(threeFingersSwipe)}.`);
            return false;
          };
          try {
            // 订阅三指滑动事件
            inputMonitor.on('threeFingersSwipe', callback);
            // 取消订阅三指滑动事件
            inputMonitor.off('threeFingersSwipe');
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor three fingers swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('fourFingersSwipe')<sup>10+</sup>

on(type: 'fourFingersSwipe', receiver: Callback&lt;FourFingersSwipe&gt;): void

监听全局触控板的四指滑动事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'fourFingersSwipe'。 |
| receiver | Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt; | 是    | 回调函数，返回四指滑动输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 订阅四指滑动事件
            inputMonitor.on('fourFingersSwipe', (fourFingersSwipe) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(fourFingersSwipe)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor four fingers swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('fourFingersSwipe')<sup>10+</sup>

off(type: 'fourFingersSwipe', receiver?: Callback&lt;FourFingersSwipe&gt;): void

取消监听全局触控板的四指滑动事件。使用callback异步回调。

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
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { FourFingersSwipe } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (fourFingersSwipe: FourFingersSwipe) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(fourFingersSwipe)}.`);
            return false;
          };
          try {
            // 订阅四指滑动事件
            inputMonitor.on('fourFingersSwipe', callback);
            // 取消订阅四指滑动事件
            inputMonitor.off('fourFingersSwipe', callback);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitoring four fingers swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { FourFingersSwipe } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (fourFingersSwipe: FourFingersSwipe) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(fourFingersSwipe)}.`);
            return false;
          };
          try {
            // 订阅四指滑动事件
            inputMonitor.on('fourFingersSwipe', callback);
            // 取消订阅四指滑动事件
            inputMonitor.off('fourFingersSwipe');
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitoring four fingers swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('rotate')<sup>11+</sup>

on(type: 'rotate', fingers: number, receiver: Callback&lt;Rotate&gt;): void

监听全局触控板的旋转事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'rotate'。 |
| fingers     | number                     | 是    | 旋转的手指数，目前支持监听手指数是2。 |
| receiver | Callback&lt;[Rotate](js-apis-multimodalinput-gestureevent.md#rotate11)&gt; | 是    | 回调函数，返回旋转输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Rotate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 旋转手势监听手指数2
            inputMonitor.on('rotate', 2, (rotateEvent: Rotate) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(rotateEvent)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor rotate event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('rotate')<sup>11+</sup>

off(type: 'rotate', fingers: number, receiver?: Callback&lt;Rotate&gt;): void

取消监听全局触控板的旋转事件。使用callback异步回调。

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
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Rotate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (rotateEvent: Rotate) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(rotateEvent)}.`);
            return false;
          };
          try {
            // 旋转手势监听手指数2
            inputMonitor.on('rotate', 2, callback);
            // 取消订阅旋转事件
            inputMonitor.off('rotate', 2, callback);
            console.info(`Succeeded in turning off monitor.`); 
          } catch (error) {
            console.error(`Failed to cancel monitor rotate event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { Rotate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (rotateEvent: Rotate) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(rotateEvent)}.`);
            return false;
          };
          try {
            // 旋转手势监听手指数2
            inputMonitor.on('rotate', 2, callback);
            // 取消订阅旋转事件
            inputMonitor.off('rotate', 2);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor rotate event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('pinch')<sup>11+</sup>

on(type: 'pinch', fingers: number, receiver: Callback&lt;Pinch&gt;): void

监听全局触控板的捏合事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值'pinch'。 |
| fingers     | number                     | 是    | 捏合的手指数，取值范围：大于等于2。 |
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | 是    | 回调函数，返回捏合输入事件。  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 捏合手势监听手指数2
            inputMonitor.on('pinch', 2, (pinchEvent: Pinch) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(pinchEvent)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor pinch event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('pinch')<sup>11+</sup>

off(type: 'pinch', fingers: number, receiver?: Callback&lt;Pinch&gt;): void

取消监听全局触控板的捏合事件。使用callback异步回调。

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
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (pinchEvent: Pinch) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(pinchEvent)}.`);
            return false;
          };
          try {
            // 订阅捏合事件
            inputMonitor.on('pinch', 2, callback);
            // 取消订阅捏合事件
            inputMonitor.off('pinch', 2, callback);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor pinch event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { Pinch } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (pinchEvent: Pinch) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(pinchEvent)}.`);
            return false;
          };
          try {
            // 捏合手势监听手指数2
            inputMonitor.on('pinch', 2, callback);
            // 取消订阅捏合事件
            inputMonitor.off('pinch', 2);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor pinch event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('threeFingersTap')<sup>11+</sup>

on(type: 'threeFingersTap', receiver: Callback&lt;ThreeFingersTap&gt;): void

监听全局触控板的三指轻点事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 输入设备事件类型，取值'threeFingersTap'。 |
| receiver | Callback&lt;[ThreeFingersTap](js-apis-multimodalinput-gestureevent.md#threefingerstap11)&gt; | 是   | 回调函数，返回三指轻点输入事件。      |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 订阅三指点击事件
            inputMonitor.on('threeFingersTap', (threeFingersTap) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(threeFingersTap)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor three fingers tap, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('threeFingersTap')<sup>11+</sup>

off(type: 'threeFingersTap', receiver?: Callback&lt;ThreeFingersTap&gt;): void

取消监听全局触控板的三指轻点事件。使用callback异步回调。

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
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { ThreeFingersTap } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (threeFingersTap: ThreeFingersTap) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(threeFingersTap)}.`);
            return false;
          };
          try {
            // 订阅三指点击事件
            inputMonitor.on('threeFingersTap', callback);
            // 取消订阅三指点击事件
            inputMonitor.off('threeFingersTap', callback);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor three fingers tap, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { ThreeFingersTap } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (threeFingersTap: ThreeFingersTap) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(threeFingersTap)}.`);
            return false;
          };
          try {
            // 订阅三指点击事件
            inputMonitor.on('threeFingersTap', callback);
            // 取消订阅三指点击事件
            inputMonitor.off('threeFingersTap');
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor three fingers tap, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('touchscreenSwipe')<sup>18+</sup>

on(type: 'touchscreenSwipe', fingers: number, receiver: Callback&lt;TouchGestureEvent&gt;): void

监听触摸屏滑动手势事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'touchscreenSwipe'。                    |
| fingers  | number                                                       | 是   | 滑动手势的手指数，取值范围：[3,5]。 |
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent18)&gt; | 是   | 回调函数，返回触摸屏滑动手势事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | Caller is not a system application.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let fingers: number = 4;
          try {
            // 订阅触摸屏滑动事件
            inputMonitor.on('touchscreenSwipe', fingers, (event: TouchGestureEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
            });
          } catch (error) {
            console.error(`Failed to monitor touch screen swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('touchscreenSwipe')<sup>18+</sup>

off(type: 'touchscreenSwipe', fingers: number, receiver?: Callback&lt;TouchGestureEvent&gt;): void

取消监听触摸屏滑动手势事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'touchscreenSwipe'。                    |
| fingers  | number                                                       | 是   | 滑动手势的手指数，取值范围：[3,5]。 |
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent18)&gt; | 否   | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | Caller is not a system application.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (event: TouchGestureEvent) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
          };
          let fingers: number = 4;
          try {
            // 订阅触摸屏滑动事件
            inputMonitor.on('touchscreenSwipe', fingers, callback);
            // 取消订阅触摸屏滑动事件
            inputMonitor.off('touchscreenSwipe', fingers, callback);
          } catch (error) {
            console.error(`Failed to cancel monitor touch screen swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
            // 订阅触摸屏滑动事件
            inputMonitor.on('touchscreenSwipe', fingers, (event: TouchGestureEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
            });
            // 取消订阅触摸屏滑动事件
            inputMonitor.off('touchscreenSwipe', fingers);
          } catch (error) {
            console.error(`Failed to monitor touch screen swipe, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('touchscreenPinch')<sup>18+</sup>

on(type: 'touchscreenPinch', fingers: number, receiver: Callback&lt;TouchGestureEvent&gt;): void

监听触摸屏捏合手势事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'touchscreenPinch'。                    |
| fingers  | number                                                       | 是   | 捏合手势的手指数，取值范围：[4,5]。 |
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent18)&gt; | 是   | 回调函数，返回触摸屏捏合手势事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | Caller is not a system application.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let fingers: number = 4;
          try {
            // 订阅触摸屏捏合事件
            inputMonitor.on('touchscreenPinch', fingers, (event: TouchGestureEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
            });
          } catch (error) {
            console.error(`Failed to monitor touch screen pinch, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('touchscreenPinch')<sup>18+</sup>

off(type: 'touchscreenPinch', fingers: number, receiver?: Callback&lt;TouchGestureEvent&gt;): void

取消监听触摸屏捏合手势事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入设备事件类型，取值'touchscreenPinch'。                    |
| fingers  | number                                                       | 是   | 捏合手势的手指数，取值范围：[4,5]。 |
| receiver | Callback&lt;[TouchGestureEvent](js-apis-multimodalinput-gestureevent-sys.md#touchgestureevent18)&gt; | 否   | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | Caller is not a system application.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (event: TouchGestureEvent) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
          };
          let fingers: number = 4;
          try {
            // 订阅触摸屏捏合事件
            inputMonitor.on('touchscreenPinch', fingers, callback);
            // 取消订阅触摸屏捏合事件
            inputMonitor.off('touchscreenPinch', fingers, callback);
          } catch (error) {
            console.error(`Failed to cancel monitor touch screen pinch, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { TouchGestureEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
            // 订阅触摸屏捏合事件
            inputMonitor.on('touchscreenPinch', fingers, (event: TouchGestureEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
            });
            // 取消订阅触摸屏捏合事件
            inputMonitor.off('touchscreenPinch', fingers);
          } catch (error) {
            console.error(`Failed to cancel monitor touch screen pinch, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.on('keyPressed')<sup>15+</sup>

on(type: 'keyPressed', keys: Array&lt;KeyCode&gt;, receiver: Callback&lt;KeyEvent&gt;): void

监听指定按键的按下抬起事件，支持监听META_LEFT键、META_RIGHT键、电源键、音量键。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                 |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                      | 是   | 按键事件类型，取唯一值'keyPressed'。 |
| keys     | Array<[KeyCode](js-apis-keycode.md#keycode)> | 是   | 键值，支持如下键值：KEYCODE_META_LEFT、KEYCODE_META_RIGHT、KEYCODE_POWER、KEYCODE_VOLUME_DOWN、KEYCODE_VOLUME_UP。                      |
| receiver | Callback&lt;[KeyEvent](js-apis-keyevent.md#keyevent)&gt;    | 是   | 回调函数，返回按键输入事件。         |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[按键前置监听错误码](./errorcode-inputmonitor.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied, non-system app called system api.         |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 4100001  | Event listening not supported for the key.                   |

**示例：**

```js
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let keys: Array<KeyCode> = [KeyCode.KEYCODE_VOLUME_UP];
            // 订阅按键按下事件
            inputMonitor.on('keyPressed', keys, (event: KeyEvent ) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
            });
          } catch (error) {
            console.error(`Failed to monitor key pressed, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('keyPressed')<sup>15+</sup>

off(type: 'keyPressed', receiver?: Callback&lt;KeyEvent&gt;): void

取消监听按键按下抬起事件。支持取消监听META_LEFT键、META_RIGHT键、电源键、音量键。需和inputMonitor.on('keyPressed')配套使用。使用callback异步回调。

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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
              console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
            };
            let keys: Array<KeyCode> = [KeyCode.KEYCODE_VOLUME_UP];
            // 订阅按键按下事件
            inputMonitor.on('keyPressed', keys, callback);
            // 取消订阅按键按下事件
            inputMonitor.off('keyPressed', callback);
          } catch (error) {
            console.error(`Failed to cancel monitor key pressed, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor, KeyEvent, KeyCode } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
            // 订阅按键按下事件
            inputMonitor.on('keyPressed', keys, (event: KeyEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(event)}.`);
            });
            // 取消订阅按键按下事件
            inputMonitor.off('keyPressed');
          } catch (error) {
            console.error(`Failed to cancel monitor key pressed, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.queryTouchEvents()<sup>20+</sup>

queryTouchEvents(count: number): Promise&lt;Array&lt;TouchEvent&gt;&gt;

查询最近的触屏输入事件，最多支持查询100条事件，从API版本26.0.0开始，最多支持查询60条事件，使用Promise异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| count     | number                                                    | 是   | 需要查询的触屏输入事件数量，取值范围为[0, 100]的整数。小于0时取值为0、大于100时取值为100。从API版本26.0.0开始，大于60时取值为60。如果实际触屏输入事件只有30个，但该参数取值为50 ，则仅支持查询到30个触屏输入事件。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[TouchEvent](js-apis-touchevent-sys.md#touchevent)&gt;&gt; | Promise对象，返回查询到的触屏输入事件。包含以下有效信息，其余均为无效信息：<br/>- actionTime：触屏输入事件发生的时间，表示系统启动运行至今逝去的微秒数，单位为微秒（μs）。<br/>- [SourceType](js-apis-touchevent.md#sourcetype)：触摸来源的设备类型。<br/>- [isInject](js-apis-touchevent-sys.md#touchevent)：表示该触屏输入事件是否为注入事件。<br/>- pressure：压力值，取值范围是[0.0, 1.0]，0.0表示不支持。<br/>- tiltX：相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。<br/>- tiltY：相对XZ平面的角度，取值的范围[-90, 90]，其中正值是向下倾斜。<br/>从API version 23开始，可以额外获取以下有效信息：<br/>- [Action](js-apis-touchevent.md#action)：触屏输入事件类型。<br/>- screenX：相对于屏幕左上角的X轴坐标，单位为像素，取值范围[0, 屏幕宽度]，向右递增。仅限指定应用获取。<br/>- screenY：相对于屏幕左上角的Y轴坐标，单位为像素，取值范围[0, 屏幕高度]，向下递增。仅限指定应用获取。<br/>从API版本26.0.0开始，最多支持查询60条事件，且不会返回MOVE和PULL_MOVE类型的事件。screenX和screenY不再限制指定应用获取，所有系统应用均可获取。同时可以额外获取以下有效信息：<br/>- screenId：目标屏幕ID。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Permission denied, non-system app called system api.         |

**示例：**

```js
import { inputMonitor, TouchEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 查询触屏事件数量
  inputMonitor.queryTouchEvents(10).then((events: Array<TouchEvent>) => {
    events.forEach((event, index) => {
      console.info(`Succeeded in querying touch event ${index}, actionTime=${event.actionTime}, sourceType=${event.sourceType}.`);
    });
  }).catch((error: BusinessError) => {
    console.error(`Failed to query touch events promise, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
  });
} catch (error) {
  const code = (error as BusinessError).code;
  const message = (error as BusinessError).message;
  console.error(`Failed to query touch events, Code: ${code}, message: ${message}.`);
}
```

## inputMonitor.on('swipeInward')<sup>12+</sup>

on(type: 'swipeInward', receiver: Callback&lt;SwipeInward&gt;): void

监听向内滑动事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                 |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                      | 是   | 输入事件类型，取唯一值'swipeInward'。 |
| receiver | Callback&lt;[SwipeInward](js-apis-multimodalinput-gestureevent-sys.md#swipeinward)&gt;    | 是   | 回调函数，返回向内滑动事件。         |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | SystemAPI permit error.         |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 订阅向内滑动事件
            inputMonitor.on('swipeInward', (SwipeInward) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(SwipeInward)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor swipe inward, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('swipeInward')<sup>12+</sup>

off(type: 'swipeInward', receiver?: Callback&lt;SwipeInward&gt;): void

取消监听向内滑动事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入事件类型，取值'swipeInward'。                    |
| receiver | Callback&lt;[SwipeInward](js-apis-multimodalinput-gestureevent-sys.md#swipeinward)&gt; | 否   | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor, SwipeInward } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
build() {
  RelativeContainer() {
    Text()
      .onClick(() => {
        // 取消监听单个回调函数
        let callback = (swipeInward: SwipeInward) => {
          console.info(`Succeeded in monitoring on ${JSON.stringify(swipeInward)}.`);
          return false;
        };
        try {
          // 订阅向内滑动事件
          inputMonitor.on('swipeInward', callback);
          // 取消订阅向内滑动事件
          inputMonitor.off('swipeInward', callback);
          console.info(`Succeeded in turning off monitor.`);
        } catch (error) {
          console.error(`Failed to cancel monitor swipe inward, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
        }
      })
  }
}
}
```

```js
import { inputMonitor, SwipeInward } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
build() {
  RelativeContainer() {
    Text()
      .onClick(() => {
        // 取消监听所有回调函数
        let callback = (swipeInward: SwipeInward) => {
          console.info(`Succeeded in monitoring on ${JSON.stringify(swipeInward)}.`);
          return false;
        };
        try {
          // 订阅向内滑动事件
          inputMonitor.on('swipeInward', callback);
          // 取消订阅向内滑动事件
          inputMonitor.off('swipeInward');
          console.info(`Succeeded in turning off monitor.`);
        } catch (error) {
          console.error(`Failed to cancel monitor swipe inward, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
        }
      })
  }
}
}
```

## inputMonitor.on('fingerprint')<sup>12+</sup>

on(type: 'fingerprint', receiver: Callback&lt;FingerprintEvent&gt;): void

监听指纹手势输入事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                 |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------ |
| type     | string                                                      | 是   | 输入事件类型，取唯一值'fingerprint'。 |
| receiver | Callback&lt;[FingerprintEvent](js-apis-shortKey-sys.md#fingerprintevent12)&gt;    | 是   | 回调函数，返回指纹器件手势输入事件。         |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | SystemAPI permit error.         |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 订阅指纹事件
            inputMonitor.on('fingerprint', (FingerprintEvent) => {
              console.info(`Succeeded in monitoring on ${JSON.stringify(FingerprintEvent)}.`);
              return false;
            });
          } catch (error) {
            console.error(`Failed to monitor finger print event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputMonitor.off('fingerprint')<sup>12+</sup>

off(type: 'fingerprint', receiver?: Callback&lt;FingerprintEvent&gt;): void

取消监听指纹手势输入事件。使用callback异步回调。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 输入事件类型，取值'fingerprint'。                    |
| receiver | Callback&lt;[FingerprintEvent](js-apis-shortKey-sys.md#fingerprintevent12)&gt; | 否   | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201  | Permission denied.   |
| 202  | SystemAPI permit error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```js
import { inputMonitor } from '@kit.InputKit';
import { FingerprintEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听单个回调函数
          let callback = (fingerprintEvent: FingerprintEvent) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(fingerprintEvent)}.`);
            return false;
          };
          try {
            // 订阅指纹事件
            inputMonitor.on('fingerprint', callback);
            // 取消订阅指纹事件
            inputMonitor.off('fingerprint', callback);
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor finger print event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```js
import { inputMonitor } from '@kit.InputKit';
import { FingerprintEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // 取消监听所有回调函数
          let callback = (fingerprintEvent: FingerprintEvent) => {
            console.info(`Succeeded in monitoring on ${JSON.stringify(fingerprintEvent)}.`);
            return false;
          };
          try {
            // 订阅指纹事件
            inputMonitor.on('fingerprint', callback);
            // 取消订阅指纹事件
            inputMonitor.off('fingerprint');
            console.info(`Succeeded in turning off monitor.`);
          } catch (error) {
            console.error(`Failed to cancel monitor finger print event, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```