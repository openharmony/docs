# @ohos.inputMethodEngine (输入法服务)(系统接口)

本模块为系统输入法应用提供管理能力，包括创建软键盘窗口、插入/删除字符、选中文本、监听物理键盘按键事件等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { inputMethodEngine } from '@kit.IMEKit';
```

## SizeUpdateCallback<sup>14+</sup>

type SizeUpdateCallback = (size: window.Size, keyboardArea: KeyboardArea) => void

当输入法面板大小变化时触发的回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

| 参数名       | 类型                                                 | 必填 | 说明                             |
| ------------ | ---------------------------------------------------- | ---- | -------------------------------- |
| size         | [window.Size](../apis-arkui/js-apis-window.md#size7) | 是   | 当前面板大小。                   |
| keyboardArea | [KeyboardArea](./js-apis-inputmethodengine.md#keyboardarea15)    | 是   | 当前面板中可作为键盘区域的大小。 |

## Panel<sup>10+</sup>

下列API均需使用[createPanel](./js-apis-inputmethodengine.md#createpanel10)获取到Panel实例后，通过实例调用。

### on('sizeUpdate')<sup>14+</sup>

on(type: 'sizeUpdate', callback: SizeUpdateCallback): void

监听当前面板大小变化。使用callback异步回调。

> **说明:**
>
> 仅用于SOFT_KEYBOARD类型，状态为FLG_FIXED或FLG_FLOATING的面板。输入法通过[adjustPanelRect](./js-apis-inputmethodengine.md#adjustpanelrect15)等接口对面板大小进行调节时，系统会根据一定规则校验计算出最终的数值（例如：超出屏幕等场景）。输入法应用可通过该回调获取的真实面板大小，完成最终的面板布局刷新。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                   |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                      | 是   | 监听当前面板的大小是否产生变化，固定值为'sizeUpdate'。 |
| callback | [SizeUpdateCallback](#sizeupdatecallback14) | 是   | 回调函数。返回当前软键盘面板的大小，包含宽度和高度值。 |

**示例：**

```ts
import { window } from '@kit.ArkUI';

try {
  panel.on('sizeUpdate', (windowSize: window.Size, keyboardArea: inputMethodEngine.KeyboardArea) => {
    console.info(`panel size changed, windowSize: ${JSON.stringify(windowSize)}, keyboardArea: ${JSON.stringify(keyboardArea)}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sizeUpdate: ${JSON.stringify(err)}`);
}
```

### off('sizeUpdate')<sup>14+</sup>

off(type: 'sizeUpdate', callback?: SizeUpdateCallback): void

取消监听当前面板大小变化。使用callback异步回调。

> **说明:**
>
> 仅用于SOFT_KEYBOARD类型，状态为FLG_FIXED或FLG_FLOATING的面板。输入法通过[adjustPanelRect](./js-apis-inputmethodengine.md#adjustpanelrect15)等接口对面板大小进行调节时，系统会根据一定规则校验计算出最终的数值（例如：超出屏幕等场景）。输入法应用可通过该回调获取的真实面板大小，完成最终的面板布局刷新。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                     |
| -------- | ------------------------------------------- | ---- | -------------------------------------------------------- |
| type     | string                                      | 是   | 监听当前面板的大小是否产生变化，固定取值为'sizeUpdate'。 |
| callback | [SizeUpdateCallback](#sizeupdatecallback14) | 否   | 回调函数。返回当前软键盘面板的大小，包含宽度和高度值。   |

**示例：**

```ts
import { window } from '@kit.ArkUI';

try {
  panel.off('sizeUpdate', (windowSize: window.Size, keyboardArea: inputMethodEngine.KeyboardArea) => {
    console.info(`panel size changed, width: ${windowSize.width}, height: ${windowSize.height}`);
  });
} catch(err) {
    console.error(`Failed to subscribe sizeUpdate: ${JSON.stringify(err)}`);
}
```
<!--no_check-->