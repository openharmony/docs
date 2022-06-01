# 输入监听


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口均为系统接口，三方应用不支持调用。


## 导入模块


```js
import inputMonitor from '@ohos.multimodalInput.inputMonitor';
```


## 权限

ohos.permission.INPUT_MONITORING


## inputMonitor.on

on(type: "touch", receiver: TouchEventReceiver): void

开始监听全局触屏事件。

**需要权限：**ohos.permission.INPUT_MONITORING

**系统能力：**SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**
| 参数     | 类型                                      | 必填 | 说明                            |
| -------- | ----------------------------------------- | ---- | ------------------------------- |
| type     | string                                    | 是   | 监听输入事件类型，取值“touch”。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 是   | 触摸输入事件回调函数。          |

  **示例：**

```js
inputMonitor.off("touch", (event) => {
  // 消费触屏事件
  return false;
});
```

on(type: "mouse", receiver:Callback<MouseEvent>):void

开始监听全局鼠标事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：** 

| 参数     | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| type     | string               | 是   | 监听输入事件类型，取值“mouse”。 |
| receiver | Callback<MouseEvent> | 是   | 鼠标输入事件回调函数。          |

  **示例：**

```js
inputMonitor.off("mouse", (event) => {
  // 消费鼠标事件
});
```



## inputMonitor.off

off(type: "touch", receiver?:TouchEventReceiver):void

开始监听全局触屏事件。

**需要权限：**ohos.permission.INPUT_MONITORING

**系统能力：**SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**
| 参数     | 类型                                      | 必填 | 说明                            |
| -------- | ----------------------------------------- | ---- | ------------------------------- |
| type     | string                                    | 是   | 监听输入事件类型，取值“touch”。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 否   | 触摸输入事件回调函数。          |

  **示例：**

```js
inputMonitor.off("touch");
```

off(type: "mouse", receiver?:Callback<MouseEvent>):void

停止监听全局鼠标事件。

**需要权限：**ohos.permission.INPUT_MONITORING

**系统能力：**SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**

| 参数     | 类型                 | 必填 | 说明                            |
| -------- | -------------------- | ---- | ------------------------------- |
| type     | string               | 是   | 监听输入事件类型，取值“mouse”。 |
| receiver | Callback<MouseEvent> | 否   | 鼠标输入事件回调函数。          |

**示例：**

```js
inputMonitor.off("mouse");
```



## TouchEventReceiver

触摸输入事件的回调函数，如果返回true，则触摸输入将被监听器消耗（系统执行关闭动作）。


### (touchEvent: TouchEvent): Boolean

触摸输入事件的回调函数。函数名由使用者定义，这里是函数调用时必须符合的格式，传入参数必须为TouchEvent类型，返回值为Boolean类型。

**系统能力：**SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**
| 参数         | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](../arkui-js/js-components-common-events.md) | 是    | 触摸输入事件回调函数，返回true表示输触事件被监听器消费，false表示输触事件未被监听器消费。 |

  **返回值：**
| 类型      | 说明                                     |
| ------- | -------------------------------------- |
| Boolean | 返回true表示输触事件被监听器消费，false表示输触事件未被监听器消费。 |

  **示例：**

```js
inputMonitor.on("touch", (event) => {
  // 消费触屏事件
  return false;
});
inputMonitor.off("touch");
```
