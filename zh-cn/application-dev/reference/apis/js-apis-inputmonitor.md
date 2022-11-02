# 输入监听

InputMonitor模块提供了监听全局触摸事件的功能。

>  **说明：**
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口均为系统接口。


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
| type     | string                                   | 是    | 监听输入事件类型，取值“touch”。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 是    | 触摸输入事件回调函数。         |

  **示例：**

```js
try {
    inputMonitor.on("touch", (data)=> {
        console.log(`Monitor on TouchEvent success ${JSON.stringify(data)}`);
        return false;
    });
} catch (error) {
    console.log(`Failed to monitor on TouchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```


on(type: "mouse", receiver: Callback&lt;MouseEvent&gt;): void

开始监听全局鼠标事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：** 

| 参数       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 监听输入事件类型，取值“mouse”。 |
| receiver | Callback&lt;MouseEvent&gt; | 是    | 鼠标输入事件回调函数。         |

  **示例：**

```js
try {
    inputMonitor.on("mouse", (data)=> {
        console.log(`Monitor on MouseEvent success ${JSON.stringify(data)}`);
        return false;
    });
} catch (error) {
    console.log(`Failed to monitor on MouseEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
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
| type     | string                                   | 是    | 监听输入事件类型，取值“touch”。 |
| receiver | [TouchEventReceiver](#toucheventreceiver) | 否    | 触摸输入事件回调函数。         |

  **示例：**

```js
// 取消监听全局触屏事件
try {
    inputMonitor.off("touch");
} catch (error) {
    console.log(`Failed to monitor off TouchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
// 单独取消receiver的监听。
callback:function(data) {
    console.log(`call success ${JSON.stringify(data)}`);
},
try {
    inputMonitor.on("touch", this.callback);
} catch (error) {
    console.log(`Failed to monitor on TouchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
},
try {
    inputMonitor.off("touch",this.callback);
} catch (error) {
    console.log(`Failed to monitor off TouchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

off(type: "mouse", receiver?: Callback&lt;MouseEvent&gt;): void

停止监听全局鼠标事件。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**

| 参数       | 类型                         | 必填   | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| type     | string                     | 是    | 监听输入事件类型，取值“mouse”。 |
| receiver | Callback&lt;MouseEvent&gt; | 否    | 鼠标输入事件回调函数。         |

**示例：**

```js
// 取消监听全局鼠标事件
try {
    inputMonitor.off("mouse");
} catch (error) {
     console.log(`Failed to monitor off MouseEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
// 单独取消receiver的监听。
callback:function(data) {
    console.log(`call success ${JSON.stringify(data)}`);
},
try {
    inputMonitor.on("mouse", this.callback);
} catch (error) {
    console.log(`Failed to monitor on MouseEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
},
try {
    inputMonitor.off("mouse", this.callback);
} catch (error) {
    console.log(`Failed to monitor off MouseEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```



## TouchEventReceiver

触摸输入事件的回调函数。如果返回true，则触摸输入被监听器消耗，系统将执行关闭动作。

**需要权限：** ohos.permission.INPUT_MONITORING

**系统能力：** SystemCapability.MultimodalInput.Input.InputMonitor

  **参数：**
| 参数         | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| touchEvent | [TouchEvent](../arkui-js/js-components-common-events.md) | 是    | 触摸输入事件回调函数，返回true表示输触事件被监听器消费，false表示输触事件未被监听器消费。 |

  **返回值：**
| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| Boolean | 返回true表示触摸输入事件被监听器消费，false表示触摸输入事件未被监听器消费。 |

  **示例：**

```js
try {
  inputMonitor.on("touch", (event) => {
    // 若返回true，表示本次操作后续所有事件不再分发到窗口，事件都由监听者消费。
    return false;
  });
  inputMonitor.off("touch");
} catch (error) {
    console.log(`Failed to monitor off TouchEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
