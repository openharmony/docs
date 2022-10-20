# Touch Target

You can set the touch target for components that support universal click events, touch events, and gestures.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes


| Name            | Type                                         | Description                                     |
| -------------- | --------------------------------------------- | ----------------------------------------- |
| responseRegion | Array&lt;Rectangle&gt; \| Rectangle | One or more touch targets, including their location and size.<br>Default value:<br>**{<br>x: 0,<br>y: 0,<br>width: '100%',<br>height: '100%'<br>}** |


### Rectangle
| Name       | Type                      | Mandatory  | Description                            |
| ------ | ----------------------------- | -----| -------------------------------- |
| x      | [Length](ts-types.md#length)  | No  | X coordinate of the touch point relative to the left edge of the component.<br>Default value: **0vp**|
| y      | [Length](ts-types.md#length)  | No  | Y coordinate of the touch point relative to the left edge of the component.<br>Default value: **0vp**|
| width  | [Length](ts-types.md#length)  | No  | Width of the touch target.<br>Default value: **100%**|
| height | [Length](ts-types.md#length) | No  | Height of the touch target.<br>Default value: **100%**|

  >  **NOTE**<br>
  >
  >  **x** and **y** can be set to a positive or negative percentage value. For example, when **x** is set to **'100%'**, the touch target is the offset from the right edge of the component by the component's width. When **x** is set to **'-100%'**, the touch target is the offset from the left edge of the component by the component's width. When **y** is set to **'100%'**, the touch target is the offset from the bottom edge of the component by the component's height. When **y** is set to **'-100%'**, the touch target is the offset from the top edge of the component by the component's height.
  >
  >  **width** and **height** can only be set to positive percentage values. When **width** is set to **'100%'**, the width of the touch target is equal to that of the component; when **height** is set to **'100%'**, the height of the touch target is equal to that of the component.
  >
  >  The percentage is measured relative to the component itself.


## Example

```ts
// xxx.ets
@Entry
@Component
struct ResponseRegionExample {
  build() {
    Column() {
        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .selectedColor(0x39a2db)
          .backgroundColor(0xAFEEEE)
          .responseRegion({ x: 1.0, y: 1.0, width: 400, height: 400 })
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218468](figures/en-us_image_0000001212218468.gif)
