# @ohos.multimodalInput.inputMonitor (输入监听)

输入监听模块，提供了监听输入设备事件（当前支持触屏、鼠标和触控板手势）的能力。

>  **说明：**
>
>  - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 本模块接口均为系统接口。


## 导入模块


```js
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
```


## inputMonitor.on('touch')

on(type: 'touch', receiver: TouchEventReceiver): void

监听全局触屏事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                  |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | 是    | 输入设备事件类型，取值“touch”。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 是    | 回调函数，异步上报触摸屏输入事件。 |

**示例：**

```js
try {
  inputMonitor.on('touch', (touchEvent) => {
    console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
| type     | string                     | 是    | 输入设备事件类型，取值“mouse”。 |
| receiver | Callback&lt;MouseEvent&gt; | 是    | 回调函数，异步上报鼠标输入事件。  |

  **示例：**

```js
try {
  inputMonitor.on('mouse', (mouseEvent) => {
    console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
| type     | string                                   | 是    | 输入设备事件类型，取值“touch”。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 否    | 需要取消监听的回调函数，若无此参数，则取消当前应用监听的所有回调函数。  |

**示例：**

```js
// 取消监听单个回调函数
function callback(touchEvent) {
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
  return false;
};
try {
  inputMonitor.on('touch', callback);
  inputMonitor.off('touch', callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// 取消监听所有回调函数
function callback(touchEvent) {
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
  return false;
};
try {
  inputMonitor.on('touch', callback);
  inputMonitor.off('touch');
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
| type     | string                     | 是    | 输入设备事件类型，取值“mouse”。 |
| receiver | Callback&lt;MouseEvent&gt; | 否    | 需要取消监听的回调函数，若无此参数，则取消当前应用监听的所有回调函数。 |

**示例：**

```js
// 取消监听单个回调函数
function callback(mouseEvent) {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
  return false;
};
try {
  inputMonitor.on('mouse', callback);
  inputMonitor.off('mouse', callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// 取消监听所有回调函数
function callback(mouseEvent) {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
  return false;
};
try {
  inputMonitor.on('mouse', callback);
  inputMonitor.off('mouse');
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## TouchEventReceiver

触摸输入事件的回调函数。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数         | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](../arkui-js/js-components-common-events.md) | 是    | 触摸输入事件。 |

**返回值：**

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| Boolean | 若返回true，本次触摸后续产生的事件不再分发到窗口；若返回false，本次触摸后续产生的事件还会分发到窗口。 |

**示例：**

```js
try {
  inputMonitor.on('touch', touchEvent => {
    if (touchEvent.touches.length == 3) { // 当前有三个手指按下
      return true;
    }
    return false;
  });
} catch (error) {
    console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('pinch')<sup>10+</sup>

on(type: 'pinch', receiver: Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt;): void

监听全局的触控板捏合事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值“pinch”。 |
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | 是    | 回调函数，异步上报捏合输入事件。  |

  **示例：**

```js
try {
  inputMonitor.on('pinch', (pinchEvent) => {
    console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('pinch')<sup>10+</sup>

off(type: 'pinch', receiver?: Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt;): void

取消监听全局的触控板捏合事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值“pinch”。 |
| receiver | Callback&lt;[Pinch](js-apis-multimodalinput-gestureevent.md#pinch)&gt; | 否    | 需要取消监听的回调函数，若无此参数，则取消当前应用监听的所有回调函数。 |

**示例：**

```js
// 取消监听单个回调函数
function callback(pinchEvent) {
  console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
  return false;
};
try {
  inputMonitor.on('pinch', callback);
  inputMonitor.off('pinch', callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// 取消监听所有回调函数
function callback(pinchEvent) {
  console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);
  return false;
};
try {
  inputMonitor.on('pinch', callback);
  inputMonitor.off('pinch');
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('threeFingersSwipe')<sup>10+</sup>

on(type: 'threeFingersSwipe', receiver: Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt;): void

监听全局的触控板三指滑动事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值“threeFingersSwipe”。 |
| receiver | Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt; | 是    | 回调函数，异步上报三指滑动输入事件。  |

  **示例：**

```js
try {
  inputMonitor.on('threeFingersSwipe', (threeFingersSwipe) => {
    console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('threeFingersSwipe')<sup>10+</sup>

off(type: 'threeFingersSwipe', receiver?: Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt;): void

取消监听全局的触控板三指滑动事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值“threeFingersSwipe”。 |
| receiver | Callback&lt;[ThreeFingersSwipe](js-apis-multimodalinput-gestureevent.md#threefingersswipe)&gt; | 否    | 需要取消监听的回调函数，若无此参数，则取消当前应用监听的所有回调函数。 |

**示例：**

```js
// 取消监听单个回调函数
function callback(threeFingersSwipe) {
  console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
  return false;
};
try {
  inputMonitor.on('threeFingersSwipe', callback);
  inputMonitor.off("threeFingersSwipe", callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// 取消监听所有回调函数
function callback(threeFingersSwipe) {
  console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);
  return false;
};
try {
  inputMonitor.on("threeFingersSwipe", callback);
  inputMonitor.off("threeFingersSwipe");
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.on('fourFingersSwipe')<sup>10+</sup>

on(type: 'fourFingersSwipe', receiver: Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt;): void

监听全局的触控板四指滑动事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值“fourFingersSwipe”。 |
| receiver | Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt; | 是    | 回调函数，异步上报四指滑动输入事件。  |

  **示例：**

```js
try {
  inputMonitor.on('fourFingersSwipe', (fourFingersSwipe) => {
    console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## inputMonitor.off('fourFingersSwipe')<sup>10+</sup>

off(type: 'fourFingersSwipe', receiver?: Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt;): void

取消监听全局的触控板四指滑动事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

**参数：**

| 参数名       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值“fourFingersSwipe”。 |
| receiver | Callback&lt;[FourFingersSwipe](js-apis-multimodalinput-gestureevent.md#fourfingersswipe)&gt; | 否    | 需要取消监听的回调函数，若无此参数，则取消当前应用监听的所有回调函数。 |

**示例：**

```js
// 取消监听单个回调函数
function callback(fourFingersSwipe) {
  console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
  return false;
};
try {
  inputMonitor.on('fourFingersSwipe', callback);
  inputMonitor.off('fourFingersSwipe', callback);
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// 取消监听所有回调函数
function callback(fourFingersSwipe) {
  console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);
  return false;
};
try {
  inputMonitor.on('fourFingersSwipe', callback);
  inputMonitor.off('fourFingersSwipe');
  console.log(`Monitor off success`);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
