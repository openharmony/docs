# 输入监听

InputMonitor模块提供了监听全局触摸事件的功能。

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

此接口为系统接口。

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

## inputMonitor.off

off(type: "touch", receiver?: TouchEventReceiver): void

停止监听全局触屏事件。

此接口为系统接口。

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


## TouchEventReceiver

触摸输入事件的回调函数。如果返回true，则触摸输入被监听器消耗，系统将执行关闭动作。

此接口为系统接口。

**系统能力：**SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**
| 参数         | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](../arkui-js/js-components-common-events.md) | 是    | 触摸输入事件回调函数，返回true表示输触事件被监听器消费，false表示输触事件未被监听器消费。 |

  **返回值：**
| 类型    | 说明                                    |
| ------- | -------------------------------------- |
| Boolean | 返回true表示触摸输入事件被监听器消费，false表示触摸输入事件未被监听器消费。 |

  **示例：**

```js
inputMonitor.on("touch", (event) => {
  // 消费触摸输入事件
  return false;
});
inputMonitor.off("touch");
```
