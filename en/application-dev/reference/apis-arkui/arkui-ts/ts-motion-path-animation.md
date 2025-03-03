# Motion Path Animation (motionPath)

The motion path animation is used to animate a component along a custom path.

>  **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## motionPath
motionPath(value: MotionPathOptions)

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type                               | Mandatory| Description                                   |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| value | [MotionPathOptions](#motionpathoptions) | Yes   | Motion path of the component.            |

## MotionPathOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Type| Mandatory| Description|
| -------- | -------- | ---- | -------- |
| path                         | string                     | Yes  | Motion path of the translation animation. The **svg** path string is used. In the value, **start** and **end** can be used in place of the start point and end point, for example, **'Mstart.x start.y L50 50 Lend.x end.y Z'**. For details, see [Path Drawing](../../../ui/ui-js-components-svg-path.md).<br>If this parameter is set to an empty string, the path animation is not set.      |
| from                         | number                     | No  | Start point of the motion path.<br>Default value: **0.0**<br>Value range: [0, 1]<br>A value less than 0 or greater than 1 evaluates to the default value **0**.  |
| to                           | number                     | No  | End point of the motion path.<br>Default value: **1.0**<br>Value range: [0, 1]<br>A value less than 0 or greater than 1 evaluates to the default value **1**, provided that the value of **to** is greater than or equal to the value of **from**.  |
| rotatable                     | boolean                    | No  | Whether to rotate along the path.<br>Default value: **false**  |


## Example

This example demonstrates how to animate a component along a custom path.

```ts
// xxx.ets
@Entry
@Component
struct MotionPathExample {
  @State toggle: boolean = true

  build() {
    Column() {
      Button('click me').margin(50)
        .motionPath({
          path: 'Mstart.x start.y L300 200 L300 500 Lend.x end.y',
          from: 0.0,
          to: 1.0,
          rotatable: true
        }) // Execute the animation: Move from the start point to (300,200), then to (300,500), and finally to the end point.
        .onClick(() => {
          animateTo({ duration: 4000, curve: Curve.Linear }, () => {
            this.toggle =! this.toggle // Use this.toggle to change the position of the component.
          })
        })
    }.width('100%').height('100%').alignItems(this.toggle ? HorizontalAlign.Start : HorizontalAlign.Center)
  }
}
```

![en-us_image_0000001174104400](figures/en-us_image_0000001174104400.gif)
