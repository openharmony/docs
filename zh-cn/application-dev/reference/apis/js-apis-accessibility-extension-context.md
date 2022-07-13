# AccessibilityExtensionContext

AccessibilityExtensionContext是AccessibilityExtensionAbility上下文环境，继承自ExtensionContext。

AccessibilityExtensionContext模块提供扩展的上下文的能力，包括允许配置辅助应用关注信息类型、查询节点信息、手势注入等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```js
import AccessibilityExtensionAbility from './@ohos.application.AccessibilityExtensionAbility'
```

## FocusDirection

表示查询下一焦点元素的方向。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| up | 表示向上查询。 |
| down | 表示向上查询。 |
| left | 表示向左查询。 |
| right | 表示向右查询。 |
| forward | 表示向前查询。 |
| backward | 表示向后查询。 |

## FocusType

表示查询焦点元素的类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| accessibility | 表示无障碍的焦点类型。 |
| normal | 表示普通的焦点类型。 |

## Rect

表示矩形区域。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

### 参数

| 名称   | 参数类型 | 可读 | 可写 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | 是   | 否   | 矩形区域的左边界。 |
| top    | number   | 是   | 否   | 矩形区域的上边界。 |
| width  | number   | 是   | 否   | 矩形区域的宽度。   |
| height | number   | 是   | 否   | 矩形区域的高度。   |

## WindowType

表示窗口的类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| application | 表示应用窗口类型。 |
| system | 表示系统窗口类型。 |

## AccessibilityExtensionContext.setEventTypeFilter

setEventTypeFilter(type: Array<accessibility.EventType>): Promise\<boolean>;

设置关注的事件类型。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| type | Array&lt;[EventType](js-apis-accessibility.md#EventType)&gt; | 是 | 关注的事件类型。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回当前设置是否成功。 |

**示例：**

```ts
this.context.setEventTypeFilter(['click', 'longClick']);
```

## AccessibilityExtensionContext.setTargetBundleName

setTargetBundleName(targetNames: Array\<string>): Promise\<boolean>;

设置关注的事件类型。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| targetNames | Array&lt;string&gt; | 是 | 关注的目标包名。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回当前设置是否成功。 |

**示例：**

```ts
this.context.setTargetBundleName(['com.ohos.mms']);
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;

获取焦点元素。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| isAccessibilityFocus | boolean | 否 | 获取的是否是无障碍焦点元素，默认为否。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;AccessibilityElement&gt; | Promise对象。返回当前对应的焦点元素。 |

**示例：**

```ts
this.context.getFocusElement().then(focusElement => {
    console.log("AxExtensionAbility getFocusElement success");
})
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>;

获取窗口的根节点元素。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| windowId | number | 否 | 指定获取根节点元素的窗口，未指定则从当前活跃窗口获取。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;AccessibilityElement&gt; | Promise对象。返回当前对应的根节点元素。 |

**示例：**

```ts
this.context.getWindowRootElement().then(rootElement => {
    console.log("AxExtensionAbility getWindowRootElement success");
})
```

## AccessibilityExtensionContext.getWindows

getWindows(displayId?: number): Promise<Array\<AccessibilityElement>>;

获取用户可见的窗口列表。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| displayId | number | 否 | 指定获取窗口信息的屏幕，未指定则从默认主屏幕获取。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;Array&lt;AccessibilityElement&gt;&gt; | Promise对象。返回当前对应的窗口列表信息。 |

**示例：**

```ts
this.context.getWindows().then(windows => {
    console.log("AxExtensionAbility getWindows success");
})
```

## AccessibilityExtensionContext.gestureInject

gestureInject(gesturePath: GesturePath, listener: Callback\<boolean>): Promise\<boolean

注入手势。

**系统能力：**  SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 参数类型 | 必填 | 说明 |
| ----- | ------ | ------ | ------ |
| gesturePath | [GesturePath](js-apis-application-AccessibilityExtensionAbility.md#GesturePath) | 是 | 表示手势的路径信息。 |
| listener | Callback&lt;boolean&gt; | 是 | 表示注入手势执行结果的回调。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回注入手势的调用结果。 |

**示例：**

```ts
let gesturePath = new GesturePath(100);
for (let i = 0; i < 10; i++) {
    let gesturePoint = new GesturePosition(100, i * 200);
    gesturePath.positions.push(gesturePoint);
}
this.context.gestureInject(gesturePath, (result) => {
    console.info('gestureInject result: ' + result);
})
```
