# Touch Target

You can set the touch target for components that support universal click events, touch events, and gestures.


>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## responseRegion

responseRegion(value: Array&lt;Rectangle&gt; | Rectangle)

Sets one or more touch targets.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | Array&lt;[Rectangle](#rectangle)&gt; \| [Rectangle](#rectangle) | Yes  | One or more touch targets, including their location and size.<br>The default touch target is the entire component. Default value:<br>{<br>x: 0,<br>y: 0,<br>width: '100%',<br>height: '100%'<br>}<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.|


## Rectangle

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name       | Type                      | Mandatory  | Description                            |
| ------ | ----------------------------- | -----| -------------------------------- |
| x      | [Length](ts-types.md#length)  | No  | X coordinate of the touch point relative to the upper left corner of the component.<br>Default value: **0vp**|
| y      | [Length](ts-types.md#length)  | No  | Y coordinate of the touch point relative to the upper left corner of the component.<br>Default value: **0vp**|
| width  | [Length](ts-types.md#length)  | No  | Width of the touch target.<br>Default value: **'100%'**|
| height | [Length](ts-types.md#length) | No  | Height of the touch target.<br>Default value: **'100%'**|

  >  **NOTE**
  >
  >  **x** and **y** can be set to a positive or negative percentage value. For example, when **x** is set to **'100%'**, the touch target is the offset from the right edge of the component by the component's width. When **x** is set to **'-100%'**, the touch target is the offset from the left edge of the component by the component's width. When **y** is set to **'100%'**, the touch target is the offset from the bottom edge of the component by the component's height. When **y** is set to **'-100%'**, the touch target is the offset from the top edge of the component by the component's height.
  >
  >  **width** and **height** can only be set to positive percentage values. When **width** is set to **'100%'**, the width of the touch target is equal to that of the component. For example, if the width of a component is 100 vp, **'100%'** indicates that the width of the touch target is also 100 vp. when **height** is set to **'100%'**, the height of the touch target is equal to that of the component.
  >
  >  The percentage is measured relative to the component itself.


## Example

This example demonstrates how to set a touch target for a button using **responseRegion** to respond to click events.

```ts
// xxx.ets
@Entry
@Component
struct TouchTargetExample {
  @State text: string = ""

  build() {
    Column({ space: 20 }) {
      Text("{x:0,y:0,width:'50%',height:'100%'}")
      // The width of the touch target is half of that of the button. The user will get no response if they touch the right of the button.
      Button("button1")
        .responseRegion({ x: 0, y: 0, width: '50%', height: '100%' })
        .onClick(() => {
          this.text = 'button1 clicked'
        })

      // Add multiple touch targets for a component.
      Text("[{x:'100%',y:0,width:'50%',height:'100%'}," +
      "\n{ x: 0, y: 0, width: '50%', height: '100%' }]")
      Button("button2")
        .responseRegion([
          { x: '100%', y: 0, width: '50%', height: '100%' }, // The width of the first touch target is half of that of the button. The touch event is triggered if the half width area on the right of the button is touched.
          { x: 0, y: 0, width: '50%', height: '100%' } // The width of the second touch target is half of the button width. The touch event is triggered if the left half of button2 is touched.
        ])
        .onClick(() => {
          this.text = 'button2 clicked'
        })
      // The touch target is located downward by one button height, with its size equal to the button size. The touch event is triggered if the lower part of button3 is touched.
      Text("{x:0,y:'100%',width:'100%',height:'100%'}")
      Button("button3")
        .responseRegion({ x: 0, y: '100%', width: '100%', height: '100%' })
        .onClick(() => {
          this.text = 'button3 clicked'
        })

      Text(this.text).margin({ top: 50 })
    }.width('100%').margin({ top: 10 })
  }
}
```

![touchtarget.gif](figures/touchtarget.gif)
