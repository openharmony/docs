# 输入监听

输入监听模块，提供了监听输入设备事件（当前支持触摸屏和鼠标）的能力。
>  **说明：**
>
>  - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 本模块接口均为系统接口。


## 导入模块


```js
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
```


## inputMonitor.on

on(type: "touch", receiver: TouchEventReceiver): void

开始监听全局触屏事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**
| 参数       | 类型                                       | 必填   | 说明                  |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | 是    | 输入设备事件类型，取值“touch”。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 是    | 回调函数，异步上报触摸屏输入事件。 |

  **示例：**

```js
try {
  inputMonitor.on("touch", (touchEvent) => {
    console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


on(type: "mouse", receiver: Callback&lt;MouseEvent&gt;): void

开始监听全局鼠标事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：** 

| 参数       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值“mouse”。 |
| receiver | Callback&lt;MouseEvent&gt; | 是    | 回调函数，异步上报鼠标输入事件。  |

  **示例：**

```js
try {
  inputMonitor.on("mouse", (mouseEvent) => {
    console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
    return false;
  });
} catch (error) {
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## inputMonitor.off

off(type: "touch", receiver?: TouchEventReceiver): void

停止监听全局触屏事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**
| 参数       | 类型                                       | 必填   | 说明                  |
| -------- | ---------------------------------------- | ---- | ------------------- |
| type     | string                                   | 是    | 输入设备事件类型，取值“touch”。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 否    | 需要取消监听的回调函数，若无此参数，则取消当前应用监听的所有回调函数。  |

  **示例：**

```js
// 取消监听单个回调函数
callback: function(touchEvent) {
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
  return false;
},
try {
  inputMonitor.on("touch", this.callback);
  inputMonitor.off("touch", this.callback);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// 取消监听所有回调函数
callback: function(touchEvent) {
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);
  return false;
},
try {
  inputMonitor.on("touch", this.callback);
  inputMonitor.off("touch");
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

off(type: "mouse", receiver?: Callback&lt;MouseEvent&gt;): void

停止监听全局鼠标事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**

| 参数       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 输入设备事件类型，取值“mouse”。 |
| receiver | Callback&lt;MouseEvent&gt; | 否    | 需要取消监听的回调函数，若无此参数，则取消当前应用监听的所有回调函数。 |

**示例：**

```js
// 取消监听单个回调函数
callback: function(mouseEvent) {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
},
try {
  inputMonitor.on("mouse", this.callback);
  inputMonitor.off("mouse", this.callback);
} catch (error) {
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

```js
// 取消监听所有回调函数
callback: function(mouseEvent) {
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);
},
try {
  inputMonitor.on("mouse", this.callback);
  inputMonitor.off("mouse");
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
  inputMonitor.on("touch", touchEvent => {
    if (touchEvent.touches.size() == 3) { // 当前有三个手指按下
      return true;
    } else {
      return false;
    }
  });
} catch (error) {
    console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
