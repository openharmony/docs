# Common Event Callbacks

>**NOTE**
>
>The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## UICommonEvent
Implements a common event callback. If the input parameter of an API is **undefined**, the corresponding event callback is reset.
### setOnClick

setOnClick(callback: Callback\<ClickEvent> | undefined): void

Set the callback for the [click event](./ts-universal-events-click.md#click-event).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)<[ClickEvent](./ts-universal-events-click.md#clickevent)> \| undefined | Yes  | Callback for the click event. |

### setOnTouch

setOnTouch(callback: Callback\<TouchEvent> | undefined): void

Sets the callback for the [touch event](./ts-universal-events-touch.md#touch-event).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)<[TouchEvent](./ts-universal-events-touch.md#touchevent)> \| undefined | Yes  | Callback for the touch event. |


### setOnAppear

setOnAppear(callback: Callback\<void> | undefined): void

Sets the callback for the [onAppear](./ts-universal-events-show-hide.md#onappear) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)\<void> \| undefined | Yes  | Callback for the **onAppear** event. |


### setOnDisappear

setOnDisappear(callback: Callback\<void> | undefined): void

Sets the callback for the [onDisappear](./ts-universal-events-show-hide.md#ondisappear) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)\<void> \| undefined | Yes  | Callback for the **onDisappear** event. |

### setOnKeyEvent

setOnKeyEvent(callback: Callback\<KeyEvent> | undefined): void

Sets the callback for the [key event](./ts-universal-events-key.md#key-event).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)<[KeyEvent](./ts-universal-events-key.md#keyevent)> \| undefined | Yes  | Callback for the key event. |

### setOnFocus

setOnFocus(callback:  Callback\<void> | undefined): void

Sets the callback for the [onFocus](./ts-universal-focus-event.md#onfocus) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)\<void> \| undefined | Yes  | Callback for the **onFocus** event. |

### setOnBlur

setOnBlur(callback: Callback\<void> | undefined): void

Sets the callback for the [onBlur](./ts-universal-focus-event.md#onblur) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [Callback](./ts-types.md#callback12)\<void> \| undefined | Yes  | Callback for the **onBlur** event. |

### setOnHover

setOnHover(callback: HoverCallback | undefined): void

Sets the callback for the [onHover](./ts-universal-mouse-key.md) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [HoverCallback](./ts-types.md#hovercallback12)  \| undefined | Yes  | Callback for the **onHover** event. |

### setOnMouse

setOnMouse(callback: Callback\<MouseEvent> | undefined): void

Sets the callback for the [onMouse](./ts-universal-mouse-key.md#onmouse) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  |  [Callback](./ts-types.md#callback12)<[MouseEvent](./ts-universal-mouse-key.md#mouseevent)> \| undefined | Yes  | Callback for the **onMouse** event. |

### setOnSizeChange

setOnSizeChange(callback: SizeChangeCallback | undefined): void

Sets the callback for the [onSizeChange](./ts-universal-component-size-change-event.md#onsizechange) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [SizeChangeCallback](./ts-universal-component-size-change-event.md#sizechangecallback)   \| undefined | Yes  | Callback for the **onSizeChange** event. |

### setOnVisibleAreaApproximateChange

setOnVisibleAreaApproximateChange(options: VisibleAreaEventOptions, event: VisibleAreaChangeCallback | undefined): void

Sets the [onVisibleAreaChange](./ts-universal-component-visible-area-change-event.md#onvisibleareachange) callback that limits the callback interval.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| options  | [VisibleAreaEventOptions](./ts-types.md#visibleareaeventoptions12) | Yes  | Options of visible area changes. |
| event  | [VisibleAreaChangeCallback](./ts-types.md#visibleareachangecallback12)   \| undefined | Yes  | Callback for the **onVisibleAreaChange** event. Called when the ratio of the component's visible area to its total area is greater than or less than the threshold. |

>**NOTE**
>
> This callback is not a real-time callback. The actual callback interval may be different from the expected interval.
> The interval between **onVisibleAreaChange** callbacks is greater than or equal to the expected update interval. If the expected interval set is too short, the actual callback interval is subject to the system load.
