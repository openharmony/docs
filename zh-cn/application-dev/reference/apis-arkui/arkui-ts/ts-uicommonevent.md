# 设置事件回调

>**说明：**
>
>本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## UICommonEvent
用于设置基础事件回调。方法入参为undefined的时候，重置对应的事件回调。
### setOnClick

setOnClick(callback: Callback\<ClickEvent> | undefined): void

设置[点击事件](./ts-universal-events-click.md#点击事件)的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)<[ClickEvent](./ts-universal-events-click.md#clickevent对象说明)> \| undefined | 是   | 点击事件的回调函数。 |

### setOnTouch

setOnTouch(callback: Callback\<TouchEvent> | undefined): void

设置[触摸事件](./ts-universal-events-touch.md#触摸事件)的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)<[TouchEvent](./ts-universal-events-touch.md#touchevent对象说明)> \| undefined | 是   | 触摸事件的回调函数。 |


### setOnAppear

setOnAppear(callback: Callback\<void> | undefined): void

设置[onAppear](./ts-universal-events-show-hide.md#onappear)事件的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)\<void> \| undefined | 是   | onAppear事件的回调函数。 |


### setOnDisappear

setOnDisappear(callback: Callback\<void> | undefined): void

设置[onDisappear](./ts-universal-events-show-hide.md#ondisappear)事件的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)\<void> \| undefined | 是   | onDisappear事件的回调。 |

### setOnKeyEvent

setOnKeyEvent(callback: Callback\<KeyEvent> | undefined): void

设置[按键事件](./ts-universal-events-key.md#按键事件)的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)<[KeyEvent](./ts-universal-events-key.md#keyevent对象说明)>  \| undefined | 是   | 按键事件的回调函数。 |

### setOnFocus

setOnFocus(callback:  Callback\<void> | undefined): void

设置[onFocus](./ts-universal-focus-event.md#onfocus)事件的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)\<void> \| undefined | 是   | onFocus事件的回调。 |

### setOnBlur

setOnBlur(callback: Callback\<void> | undefined): void

设置[onBlur](./ts-universal-focus-event.md#onblur)事件的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)\<void> \| undefined | 是   | onBlur事件的回调。 |

### setOnHover

setOnHover(callback: HoverCallback | undefined): void

设置[onHover](./ts-universal-mouse-key.md#onhover)事件的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [HoverCallback](./ts-types.md#hovercallback12)  \| undefined | 是   | onHover事件的回调函数。 |

### setOnMouse

setOnMouse(callback: Callback\<MouseEvent> | undefined): void

设置[onMouse](./ts-universal-mouse-key.md#onmouse)事件的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  |  [Callback](./ts-types.md#callback12)<[MouseEvent](./ts-universal-mouse-key.md#mouseevent对象说明)>   \| undefined | 是   | onMouse事件的回调函数。 |

### setOnSizeChange

setOnSizeChange(callback: SizeChangeCallback | undefined): void

设置[onSizeChange](./ts-universal-component-size-change-event.md#onsizechange)事件的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [SizeChangeCallback](./ts-universal-component-size-change-event.md#sizechangecallback)   \| undefined | 是   | onSizeChange事件的回调函数。 |

### setOnVisibleAreaApproximateChange

setOnVisibleAreaApproximateChange(options: VisibleAreaEventOptions, event: VisibleAreaChangeCallback | undefined): void

设置限制回调间隔的[onVisibleAreaChange](./ts-universal-component-visible-area-change-event.md#onvisibleareachange)事件的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| options  | [VisibleAreaEventOptions](./ts-types.md#visibleareaeventoptions12) | 是   | 可见区域变化相关的参数。 |
| event  | [VisibleAreaChangeCallback](./ts-types.md#visibleareachangecallback12)   \| undefined | 是   | onVisibleAreaChange事件的回调函数。当组件可见面积与自身面积的比值接近options中设置的阈值时触发该回调。 |

>**说明：**
>
> 非实时回调，实际回调与预期间隔可能存在差别。
> 两次可见区域回调的时间间隔不小于预期更新间隔。当开发者设置的预期间隔过小时，由系统负载决定实际回调间隔时间。
