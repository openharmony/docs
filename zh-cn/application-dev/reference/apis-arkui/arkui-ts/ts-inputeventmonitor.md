# 全局基础输入事件监听
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

监听基础输入事件，在[UIContext](../arkts-apis-uicontext-uicontext.md)进行事件分发前统一拦截和过滤输入事件，适用于全局快捷键处理、输入安全过滤、特定页面统一屏蔽鼠标、触摸或按键输入等需要在事件到达组件前进行统一管控的场景，使用示例请参考[addLocalInputEventMonitor](../arkts-apis-uicontext-uicontext.md#addlocalinputeventmonitor)。

**起始版本：** 26.0.0

## InputEventMonitor

输入事件监听器标识对象。

此对象由系统创建并返回，作为监听器的唯一标识。

> **说明：**
>
> - 对象为空对象，不包含任何可访问的成员。
> - 开发者无法主动构造此对象，只能通过[addLocalInputEventMonitor](../arkts-apis-uicontext-uicontext.md#addlocalinputeventmonitor)接口注册获取。
> - 用于后续解除注册时验证身份。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

## InputEventListener

type InputEventListener = (event: RawInputEventWrapper) => InputEventInterceptResult

输入事件监听器回调函数类型。

> **说明：**
>
> - RawInputEventWrapper是抽象类，开发者无法使用`new`运算符创建实例。
> - 系统会在事件触发时自动创建实例并通过此参数传递给回调函数。
> - 当前回调参数event仅会封装以下原始输入事件类型：[MouseEvent](ts-universal-mouse-key.md#mouseevent对象说明)、[TouchEvent](ts-universal-events-touch.md#touchevent对象说明)、[KeyEvent](ts-universal-events-key.md#keyevent对象说明)。开发者可通过[asMouseEvent](#asmouseevent)、[asTouchEvent](#astouchevent)、[asKeyEvent](#askeyevent)获取对应事件对象。
> - 请勿在回调中执行耗时操作（如复杂计算或网络请求），否则可能导致应用卡顿。
> - 监听器在UI线程中同步执行会直接阻塞事件处理流程。建议仅执行不会阻塞UI线程的本地条件判断和简单计算。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | ---- | ---- |
| event | [RawInputEventWrapper](#rawinputeventwrapper) | 是 | 输入事件包装器，系统自动创建和传递，开发者无需手动创建。 |

**返回值：**

| 类型 | 说明 |
| -------- | ---- |
| [InputEventInterceptResult](#inputeventinterceptresult) | 事件拦截结果。 |

## InputEventInterceptResult

输入事件拦截结果接口，用于监听器回调[InputEventListener](#inputeventlistener)返回是否阻止事件传递的决策。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | ---- | ---- | ---- |
| action | [InputEventInterceptAction](ts-appendix-enums.md#inputeventinterceptaction) | 否 | 否 | 输入事件拦截动作。<br>CONTINUE：允许事件继续传递到UI框架。<br>BLOCK：阻止事件传递到UI框架。 |

## RawInputEventWrapper

原始输入事件包装器类。

提供统一的接口来访问不同类型的输入事件，确保类型安全和向后兼容性。

此类封装了原始的MouseEvent、TouchEvent或KeyEvent对象，并通过类型安全的方法访问。

此类为抽象类，开发者无法自行创建实例。系统会在触发输入事件监听器时自动创建实例，并将实例传递给回调函数。

**起始版本：** 26.0.0

原始输入事件包装器类。

提供统一的接口来访问不同类型的输入事件，确保类型安全和向后兼容性。

此类封装了原始的MouseEvent、TouchEvent或KeyEvent对象，并通过类型安全的方法访问。

此类为抽象类，开发者无法自行创建实例。系统会在触发输入事件监听器时自动创建实例，并将实例传递给回调函数。

> **说明：**
>
> 由于监听器在事件派发给具体组件之前执行，事件中的以下字段和方法将无法提供有效值：触发对象[target](ts-universal-events-click.md#eventtarget8)、相对于组件的坐标（[x](ts-universal-mouse-key.md#属性)、[y](ts-universal-mouse-key.md#属性)）、[getCurrentLocalPosition](ts-universal-events-touch.md#getcurrentlocalposition)和[stopPropagation](ts-universal-events-touch.md#touchevent对象说明)方法、TouchEvent的[preventDefault](ts-universal-events-touch.md#touchevent对象说明)和[getHistoricalPoints](ts-universal-events-touch.md#gethistoricalpoints10)方法以及KeyEvent的[metaKey](ts-universal-events-key.md#keyevent对象说明)属性和[getModifierKeyState](ts-universal-events-click.md#getmodifierkeystate12)方法。

**示例：**

```ts
const listener: InputEventListener = (wrapper: RawInputEventWrapper) => {
  // 使用类型判断 + 获取事件对象
  if (wrapper.isMouseEvent()) {
    const mouseEvent = wrapper.asMouseEvent()!;
    console.info(`Mouse: (${mouseEvent.windowX}, ${mouseEvent.windowY})`);
    return { action: InputEventInterceptAction.CONTINUE };
  }
  if (wrapper.isTouchEvent()) {
    const touchEvent = wrapper.asTouchEvent()!;
    console.info(`Touch: ${touchEvent.touches.length} points`);
    return { action: InputEventInterceptAction.CONTINUE };
  }
  if (wrapper.isKeyEvent()) {
    const keyEvent = wrapper.asKeyEvent()!;
    console.info(`Key: ${keyEvent.keyText}`);
    return { action: InputEventInterceptAction.CONTINUE };
  }
  return { action: InputEventInterceptAction.CONTINUE };
};
```

### isMouseEvent

isMouseEvent(): boolean

判断是否为鼠标事件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型 | 说明 |
| -------- | ---- |
| boolean | 判断是否为鼠标事件，如果是鼠标事件则返回true，否则返回false。 |

### isTouchEvent

isTouchEvent(): boolean

判断是否为触摸事件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型 | 说明 |
| -------- | ---- |
| boolean | 判断是否为触摸事件，如果是触摸事件则返回true，否则返回false。 |

### isKeyEvent

isKeyEvent(): boolean

判断是否为按键事件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型 | 说明 |
| -------- | ---- |
| boolean | 判断是否为按键事件，如果是按键事件则返回true，否则返回false。 |

### asMouseEvent

asMouseEvent(): MouseEvent \| null

获取鼠标事件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型 | 说明 |
| -------- | ---- |
| [MouseEvent](ts-universal-mouse-key.md#mouseevent对象说明) \| null | 获取鼠标事件，如果是鼠标事件则返回事件对象，否则返回null。由于监听器在事件派发给具体组件之前执行，返回的MouseEvent中触发对象target、相对于组件的坐标x和y等字段无法提供有效值。 |

### asTouchEvent

asTouchEvent(): TouchEvent \| null

获取触摸事件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型 | 说明 |
| -------- | ---- |
| [TouchEvent](ts-universal-events-touch.md#touchevent对象说明) \| null | 获取触摸事件，如果是触摸事件则返回事件对象，否则返回null。由于监听器在事件派发给具体组件之前执行，返回的TouchEvent中getCurrentLocalPosition、stopPropagation、preventDefault和getHistoricalPoints等方法无法提供有效值。 |

### asKeyEvent

asKeyEvent(): KeyEvent \| null

获取按键事件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型 | 说明 |
| -------- | ---- |
| [KeyEvent](ts-universal-events-key.md#keyevent对象说明) \| null | 获取按键事件，如果是按键事件则返回事件对象，否则返回null。由于监听器在事件派发给具体组件之前执行，返回的KeyEvent中metaKey属性和getModifierKeyState方法无法提供有效值。 |
