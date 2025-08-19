# Panel

The **Panel** component is a slidable panel that presents lightweight content with flexible sizes.

>  **NOTE**
>
>  This component is deprecated since API version 12. You are advised to use the universal attribute [bindSheet](ts-universal-attributes-sheet-transition.md) instead.
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported

>  **NOTE**
>
>  Built-in components and custom components are allowed, with support for ([if/else](../../../ui/state-management/arkts-rendering-control-ifelse.md), [ForEach](../../../ui/state-management/arkts-rendering-control-foreach.md), and [LazyForEach](../../../ui/state-management/arkts-rendering-control-lazyforeach.md)) rendering control.


## APIs

Panel(show: boolean)

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| show | boolean | Yes| Whether the panel is shown.<br>**NOTE**<br>The panel is hidden and does not take up space in the layout if this parameter is set to **false** or [Visible.None](ts-universal-attributes-visibility.md) is set.|

## Attributes

In addition to the [universal attributes](ts-component-general-attributes.md), the following attributes are supported.

### type

type(value: PanelType)

Sets the type of the panel.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [PanelType](#paneltype)| Yes  | Type of the panel.<br>Default value: **PanelType.Foldable**|

### mode

mode(value: PanelMode)

Sets the initial mode of the panel.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [PanelMode](#panelmode) | Yes  | Initial mode of the panel.<br>Default value for the Minibar type: PanelMode.Mini; default value for other types: PanelMode.Half<br>Since API version 10, this attribute supports two-way binding through [$$](../../../ui/state-management/arkts-two-way-sync.md).|

### dragBar

dragBar(value: boolean)

Sets whether to enable a drag bar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | boolean | Yes  | Whether to enable a drag bar. The value **true** means that the drag bar will be displayed, and **false** means the opposite.<br>Default value: **true**|

### customHeight<sup>10+</sup>

customHeight(value: Dimension | PanelHeight)

Sets the height of the panel in the **PanelType.CUSTOM** type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [Dimension](ts-types.md#dimension10) \| [PanelHeight](#panelheight10) | Yes  | Height of the panel in the **PanelType.CUSTOM** type.<br>Default value: **0**<br>**NOTE**<br>This attribute cannot be set in percentage.|

### fullHeight

fullHeight(value: number | string)

Sets the height of the panel in the **PanelType.Full** type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                                                        |
| ------ | -------------------------- | ---- | ------------------------------------------------------------ |
| value  | number \| string | Yes  | Height of the panel in **PanelMode.Full** mode.<br>Default value: main axis height of the panel minus 8 vp<br>**NOTE**<br>This attribute cannot be set in percentage.|

### halfHeight

halfHeight(value: number | string)

Sets the height of the panel in **PanelMode.Half** mode.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                                                        |
| ------ | -------------------------- | ---- | ------------------------------------------------------------ |
| value  | number \| string | Yes  | Height of the panel in **PanelMode.Half** mode.<br>Default value: half of the main axis height of the panel<br>**NOTE**<br>This attribute cannot be set in percentage.|

### miniHeight

miniHeight(value: number | string)

Panel height in the **PanelMode.Mini** mode.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                                                        |
| ------ | -------------------------- | ---- | ------------------------------------------------------------ |
| value  | number \| string | Yes  | Panel height in the **PanelMode.Mini** mode.<br>Default value: **48**<br>Unit: vp<br>**NOTE**<br>This attribute cannot be set in percentage.|

### show

show(value: boolean)

Sets whether the panel is shown.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | boolean | Yes  | Whether the panel is shown. The value **true** means to show the panel, and **false** means the opposite.<br>Default value: **true**<br>**NOTE**<br>The priority of this attribute is higher than that of the **show** parameter.|

### backgroundMask<sup>9+</sup>

backgroundMask(color: ResourceColor)

Background mask of the panel.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| color   | [ResourceColor](ts-types.md#resourcecolor) | Yes  | Background mask of the panel.<br>Default value: **'#08182431'**|

### showCloseIcon<sup>10+</sup>

showCloseIcon(value: boolean)

Sets whether to display the close icon.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | boolean | Yes  | Whether to display the close icon. The value **true** means to display the close icon, and **false** means the opposite.<br>Default value: **false**|

## PanelType

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Description|
| -------- | -------- |
| Minibar | A minibar panel that displays content in the minibar area or a large (fullscreen-like) area.|
| Foldable | A foldable panel that displays permanent content in a large (fullscreen-like), medium-sized (halfscreen-like), or small area.|
| Temporary | A temporary panel that displays content in a large (fullscreen-like) or medium-sized (halfscreen-like) area.|
| CUSTOM<sup>10+</sup> | A custom panel that automatically adapts its height to the content, but does not support manual resizing.|

## PanelMode

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| Mini |0| Displays a **minibar** or **foldable** panel in its minimum size. This attribute does not take effect for **temporary** panels.|
| Half | 1 | Displays a **foldable** or **temporary** panel in a medium-sized (halfscreen-like) area. This attribute does not take effect for **minibar** panels.|
| Full |2  | Displays a panel in a large (fullscreen-like) area.|

## PanelHeight<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Description|
| -------- | -------- |
| WRAP_CONTENT | When the type is **CUSTOM**, the panel automatically adapts its height to the content.|
## Events

In addition to the [universal events](ts-component-general-events.md), the following events are supported.

### onChange

onChange(event: (width: number, height: number, mode: PanelMode) =&gt; void)

Triggered when the status of the panel changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type       | Mandatory| Description                                                                                 |
| --------- | ---------  | ---- | ------------------------------------------------------------------------------------ |
| width     | number     | Yes  | Width of the content area.                                                                      |
| height    | number     | Yes  | Height of the content area.<br>When the value of **dragBar** is **true**, the panel height is the sum of the drag bar height and content area height.|
| mode      | PanelMode  | Yes  | Mode of the panel.                                                                          |

### onHeightChange<sup>9+</sup>

onHeightChange(callback: (value: number) => void)

Triggered when the height of the panel changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                               | Mandatory| Description      |
| --------- | --------------------------------------------------- | ---- | ---------- |
| value     | number  | Yes  | Height of the content area. The default unit is px.<br>When the value of **dragBar** is **true**, the panel height is the sum of the drag bar height and content area height.<br>For user experience purposes, the panel can be slid to only this height: **fullHeight** - 8 vp.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct PanelExample {
  @State show: boolean = false

  build() {
    Column() {
      Text('2021-09-30    Today Calendar: 1.afternoon......Click for details')
        .width('90%')
        .height(50)
        .borderRadius(10)
        .backgroundColor(0xFFFFFF)
        .padding({ left: 20 })
        .onClick(() => {
          this.show = !this.show
        })
      Panel(this.show) { // Display calendar events.
        Column() {
          Text('Today Calendar')
          Divider()
          Text('1. afternoon 4:00 The project meeting')
        }
      }
      .type(PanelType.Foldable)
      .mode(PanelMode.Half)
      .dragBar(true) // The drag bar is enabled by default.
      .halfHeight(500) // The panel height is half of the screen height by default.
      .showCloseIcon(true) // Display the close icon.
      .onChange((width: number, height: number, mode: PanelMode) => {
        console.info(`width:${width},height:${height},mode:${mode}`)
      })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![en-us_image_0000001174422896](figures/en-us_image_0000001174422896.gif)
