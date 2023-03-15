# Panel

The **<Panel\>** component is a slidable panel that presents lightweight content with flexible sizes.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported


## APIs

Panel(show: boolean)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| show | boolean | Yes| Whether the panel is shown.|


## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| type | [PanelType](#paneltype)| Type of the panel.<br>Default value: **PanelType.Foldable**|
| mode | [PanelMode](#panelmode) | Initial status of the panel.|
| dragBar | boolean | Whether to enable a drag bar. The value **true** means that the drag bar will be displayed, and **false** means the opposite.<br>Default value: **true**|
| fullHeight | string \| number | Panel height in the **PanelMode.Full** mode.|
| halfHeight | string \| number | Panel height in the **PanelMode.Half** mode. The default value is half of the screen height.|
| miniHeight | string \| number | Panel height in the **PanelMode.Mini** mode.|
| show | boolean | Whether to show the panel.|
| backgroundMask<sup>9+</sup>|[ResourceColor](ts-types.md#resourcecolor)|Background mask of the panel.|

## PanelType

| Name| Description|
| -------- | -------- |
| Minibar | A minibar panel displays content in the minibar area or a large (fullscreen-like) area.|
| Foldable | A foldable panel displays permanent content in a large (fullscreen-like), medium-sized (halfscreen-like), or small area.|
| Temporary | A temporary panel displays content in a large (fullscreen-like) or medium-sized (halfscreen-like) area.|

## PanelMode

| Name| Description|
| -------- | -------- |
| Mini | Displays a **minibar** or **foldable** panel in its minimum size. This attribute does not take effect for **temporary** panels.|
| Half | Displays a **foldable** or **temporary** panel in a medium-sized (halfscreen-like) area. This attribute does not take effect for **minibar** panels.|
| Full | Displays a panel in a large (fullscreen-like) area.|


## Events

| Name| Description|
| -------- | -------- |
| onChange(event: (width: number, height: number, mode: PanelMode) =&gt; void) | Triggered when the status of the panel changes. The returned height value is the height of the content area. When the value of **dragBar** is **true**, the panel height is the sum of the drag bar height and content area height.|
| onHeightChange(callback: (value: number) => void)<sup>9+</sup> |Triggered when the height of the panel changes. The returned height value is the height of the content area, in px by default. When the value of **dragBar** is **true**, the panel height is the sum of the drag bar height and content area height. For user experience purposes, the panel can be slid to only this height: **fullHeight** - 8 vp.|

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
        .width('90%').height(50).borderRadius(10)
        .backgroundColor(0xFFFFFF).padding({ left: 20 })
        .onClick(() => {
          this.show = !this.show
        })
            Panel(this.show) { // Display the agenda.
        Column() {
          Text('Today Calendar')
          Divider()
          Text('1. afternoon 4:00 The project meeting')
        }
      }
      .type(PanelType.Foldable).mode(PanelMode.Half)
      .dragBar(true) // The drag bar is enabled by default.
      .halfHeight(500) // The panel height is half of the screen height by default.
      .onChange((width: number, height: number, mode: PanelMode) => {
        console.info(`width:${width},height:${height},mode:${mode}`)
      })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![en-us_image_0000001256978381](figures/en-us_image_0000001256978381.gif)
