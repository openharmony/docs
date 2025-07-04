# @ohos.selectionInput.selectionManager (划词管理)

本模块提供划词管理能力，包括创建窗口、显示窗口、移动窗口、隐藏窗口、销毁窗口、监听鼠标划词事件、获取选中文本等。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 仅支持集成了划词扩展的应用调用。

## 导入模块

```ts
import { selectionManager } from '@kit.BasicServicesKit';
```

##

## on('selectionCompleted')

on(type: 'selectionCompleted', callback: Callback\<SelectionInfo>): void

订阅划词完成事件。使用callback异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                           |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | 是   | 设置监听类型，固定取值为'selectionCompleted'。 |
| callback | Callback\<[SelectionInfo](#selectioninfo)> | 是   | 回调函数，返回当前划词信息。       |

**错误码：**

以下错误码的详细介绍请参见[划词服务错误码](errorcode-selection.md)。

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 33600003   | Invalid operation. The selection app is not valid. |

**示例：**

```ts
import { selectionManager } from '@kit.BasicServicesKit';

try {
  selectionManager.on('selectionCompleted', (info: selectionManager.SelectionInfo) => {
    console.info(`SelectionInfo text: ${info.text}`);
  });
} catch (err) {
  console.error(`Failed to register selectionCompleted callback: ${JSON.stringify(err)}`);
}
```

## off('selectionCompleted')

off(type: 'selectionCompleted', callback?: Callback\<SelectionInfo>): void

取消订阅划词完成事件。使用callback异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | 是   | 设置监听类型，固定取值为'selectionCompleted'。               |
| callback | Callback\<[SelectionInfo](#selectioninfo)> | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
import { selectionManager } from '@kit.BasicServicesKit';

let selectionChangeCallback = (selectionInfo: selectionManager.SelectionInfo) => {
  console.info(`SelectionInfo text: ${info.text}`);
};

selectionManager.on('selectionCompleted', selectionChangeCallback);
try {
  selectionManager.off('selectionCompleted', selectionChangeCallback);
} catch (err) {
  console.error(`Failed to unregister selectionCompleted: ${JSON.stringify(err)}`);
}
```

## createPanel

createPanel(ctx: Context, info: PanelInfo): Promise\<Panel>

创建划词面板。使用Promise异步回调。

单个划词应用仅允许创建一个[主面板类型](./js-apis-selectionInput-selectionPanel.md)和一个[菜单面板类型](./js-apis-selectionInput-selectionPanel.md)的窗口。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | 当前划词面板依赖的上下文信息。 |
| info    | [PanelInfo](./js-apis-selectionInput-selectionPanel.md)   | 是   | 划词面板信息。 |

**返回值：**
| 类型   | 说明                                                                 |
| ------- | ------------------------------------------------------------------ |
| Promise\<[Panel](#panel)> | Promise对象，返回当前创建的划词面板对象。  |

**错误码：**

以下错误码的详细介绍请参见[划词服务错误码](errorcode-selection.md)。

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600003   | Invalid operation. The selection app is not valid. |

**示例：**

```ts
import { selectionManager, panelInfo, PanelType, BusinessError } from '@kit.BasicServicesKit';

let panelInfo: PanelInfo = {
  panelType: PanelType.MENU_PANEL,
  x: 0,
  y: 0,
  width: 500,
  height: 200
}
selectionManager.createPanel(this.context, panelInfo)
  .then((panel: selectionManager.Panel) => {
    console.info('Succeed in creating panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create panel: ${JSON.stringify(err)}`);
  });
```

## destroyPanel

destroyPanel(panel: Panel): Promise\<void>

销毁划词面板。使用Promise异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ---------| ----------- | ---- | ------------------------ |
| panel    | [Panel](#panel)       | 是   | 要销毁的面板对象。      |

**返回值：**
| 类型    | 说明                                                                 |
| ------- | -------------------------------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[划词服务错误码](errorcode-selection.md)。

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |

**示例：**

```ts
import { selectionManager, panelInfo, PanelType, BusinessError } from '@kit.BasicServicesKit';

let panelInfo: PanelInfo = {
  panelType: PanelType.MENU_PANEL,
  x: 0,
  y: 0,
  width: 500,
  height: 200
}
let selectionPanel: selectionManager.Panel | undefined = undefined;

selectionManager.createPanel(this.context, panelInfo)
  .then((panel: selectionManager.Panel) => {
    console.info('Succeed in creating panel.');
    selectionPanel = panel;
    try {
      if (selectionPanel) {
        selectionManager.destroyPanel(selectionPanel).then(() => {
          console.info('Succeed in destroying panel.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
        });
      }
    } catch (err) {
      console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to create panel: ${JSON.stringify(err)}`);
  });
```

## SelectionInfo

划词事件信息。

**系统能力：** SystemCapability.SelectionInput.Selection

| 名称      | 类型 | 只读 | 可选 | 说明         |
| --------- | -------- | ---- | ---- | ------------ |
| text   	| string   | 否   | 否   | 划词文本。 |
| selectionType	    | [SelectionType](#selectiontype)   | 否   | 否   | 触发划词类型。 |
| startDisplayX   	| number   | 否   | 否   | 划词起始位置的屏幕x轴坐标，单位为px。 |
| startDisplayY   	| number   | 否   | 否   | 划词起始位置的屏幕y轴坐标，单位为px。 |
| endDisplayX   	| number   | 否   | 否   | 划词结束位置的屏幕x轴坐标，单位为px。 |
| endDisplayY   	| number   | 否   | 否   | 划词结束位置的屏幕y轴坐标，单位为px。 |
| startWindowX   	| number   | 否   | 否   | 划词起始位置的窗口x轴坐标，单位为px。 |
| startWindowY   	| number   | 否   | 否   | 划词起始位置的窗口y轴坐标，单位为px。 |
| endWindowX   	| number   | 否   | 否   | 划词结束位置的窗口x轴坐标，单位为px。 |
| endWindowY   	| number   | 否   | 否   | 划词结束位置的窗口y轴坐标，单位为px。 |
| displayID   	| number   | 否   | 否   | 被划词应用窗口的屏幕ID。 |
| windowID   	| number   | 否   | 否   | 被划词应用的窗口ID。 |
| bundleName   	| string   | 否   | 否   | 划词应用的bundleName。 |

## Panel

下列API均需使用[createPanel](#createpanel)获取到Panel实例后，通过实例调用。

### setUiContent

setUiContent(path: string): Promise\<void>

为当前的划词面板加载具体页面内容。使用Promise异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| path | string | 是   |  要加载到面板中的页面内容的路径，Stage模型下该路径需添加到工程的resources/base/profile/main_pages.json文件中，不支持FA模型。 |

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | Promise对象，无返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[划词服务错误码](errorcode-selection.md)。

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.setUiContent('pages/Index').then(() => {
    console.info('Succeeded in setting the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### show

show(): Promise\<void>

显示划词面板。使用Promise异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | Promise对象，无返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[划词服务错误码](errorcode-selection.md)。

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

selectionPanel.show().then(() => {
  console.info('Succeeded in showing the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show panel: ${JSON.stringify(err)}`);
});
```

### hide

hide(): Promise\<void>

隐藏当前划词面板。使用Promise异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | Promise对象，无返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[划词服务错误码](errorcode-selection.md)。

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

selectionPanel.hide().then(() => {
  console.info('Succeeded in hiding the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide panel: ${JSON.stringify(err)}`);
});
```

### startMoving

startMoving(): Promise\<void>

使当前划词面板可以随鼠标拖动位置。使用Promise异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | Promise对象，无返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[划词服务错误码](errorcode-selection.md)。

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

RelativeContainer() {
}
.onTouch((event: TouchEvent) => {
  if (event.type === TouchType.Down) {
    if (selectionPanel !== undefined) {
      selectionPanel.startMoving().then(() => {
        console.info('Succeeded in startMoving the panel.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to startMoving panel: ${JSON.stringify(err)}`);
      });
    }
  }
})
```

### moveTo

moveTo(x: number, y: number): Promise\<void>

移动划词面板至屏幕指定位置。使用Promise异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| x | number | 是   |x轴方向移动的值，单位为px。|
| y | number | 是   |y轴方向移动的值，单位为px。|

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | Promise对象，无返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[划词服务错误码](errorcode-selection.md)。

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 33600001   | Selection service exception. |
| 33600002   | This selection window has been destroyed. |

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.moveTo(200, 200).then(() => {
    console.info('Succeeded in moving the panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to move panel: ${JSON.stringify(err)}`);
}
```

### on('destroyed')

on(type: 'destroyed', callback: Callback\<void>): void

订阅划词窗口销毁事件。使用callback异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                           |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | 是   | 设置监听类型，固定取值为'destroyed'。 |
| callback | Callback\<void> | 是   | 回调函数。       |

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.on('destroyed', () => {
    console.info('Panel has destroyed.');
  });
} catch (err) {
  console.error(`Failed to register destroyed callback: ${JSON.stringify(err)}`);
}
```

### off('destroyed')

off(type: 'destroyed', callback?: Callback\<void>): void

取消订阅划词窗口销毁事件。使用callback异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | 是   | 设置监听类型，固定取值为'destroyed'。               |
| callback | Callback\<void> | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.off('destroyed');
} catch (err) {
  console.error(`Failed to unregister destroyed: ${JSON.stringify(err)}`);
}
```

### on('hidden')

on(type: 'hidden', callback: Callback\<void>): void

订阅划词窗口隐藏事件。使用callback异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                           |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | 是   | 设置监听类型，固定取值为'hidden'。 |
| callback | Callback\<void> | 是   | 回调函数，返回当前划词服务的信息。       |

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.on('hidden', () => {
    console.info('Panel has hidden.');
  });
} catch (err) {
  console.error(`Failed to register hidden callback: ${JSON.stringify(err)}`);
}
```

### off('hidden')

off(type: 'hidden', callback?: Callback\<void>): void

取消订阅划词窗口隐藏事件。使用callback异步回调。

**系统能力：** SystemCapability.SelectionInput.Selection

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | 是   | 设置监听类型，固定取值为'hidden'。               |
| callback | Callback\<void> | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
import { selectionManager, BusinessError } from '@kit.BasicServicesKit';

try {
  selectionPanel.off('hidden');
} catch (err) {
  console.error(`Failed to unregister hidden: ${JSON.stringify(err)}`);
}
```

## SelectionType

定义触发划词的类型枚举。

**系统能力：** SystemCapability.SelectionInput.Selection

| 名称         | 值 | 说明               |
| ------------ | -- | ------------------ |
| MOUSE_MOVE | 1 | 滑动选词类型。 |
| DOUBLE_CLICK   | 2 | 双击选词类型。 |
| TRIPLE_CLICK   | 3 | 三击选词类型。 |
