# Motion Path Animation

The motion path animation is used to animate a component along a custom path.

>  **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| motionPath | {<br>path:&nbsp;string,<br>from?:&nbsp;number,<br>to?:&nbsp;number,<br>rotatable?:&nbsp;boolean<br>}<br>**NOTE**<br>In a path, **start** and **end** can be used to replace the start point and end point. Example:<br>'Mstart.x&nbsp;start.y&nbsp;L50&nbsp;50&nbsp;Lend.x&nbsp;end.y&nbsp;Z'<br>For more information, see [Path Drawing](../../ui/ui-js-components-svg-path.md).| {<br>'',<br>0.0,<br>1.0,<br>false<br>} | Motion path of the component.<br>- **path**: motion path of the translation animation. The value is an SVG path string.<br>- **from**: start point of the motion path.<br>Default value: **0.0**<br>Value range: [0, 1]<br>A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**.<br>- **to**: end point of the motion path.<br>Default value: **1.0**<br>Value range: [0, 1]<br>A value less than 0 evaluates to the value **0**. A value larger than 1 evaluates to the value **1**.<br>- **rotatable**: whether to rotate along the path. |


## Example

```ts
// xxx.ets
@Entry
@Component
struct MotionPathExample {
  @State toggle: boolean = true

  build() {
    Column() {
      Button('click me').margin(50)
        // Execute the animation: Move from the start point to (300,200), then to (300,500), and finally to the end point.
        .motionPath({ path: 'Mstart.x start.y L300 200 L300 500 Lend.x end.y', from: 0.0, to: 1.0, rotatable: true })
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
