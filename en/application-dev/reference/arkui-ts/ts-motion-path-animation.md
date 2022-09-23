# Motion Path Animation

The motion path animation is used to animate a component along a custom path.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes

| Parameter| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| motionPath | {<br>path: string,<br>from?: number,<br>to?: number,<br>rotatable?: boolean<br>}<br>**NOTE**<br>In a path, **start** and **end** can be used to replace the start point and end point. Example:<br>'Mstart.x start.y L50 50 Lend.x end.y Z'| {<br>"",<br>0.0,<br>1.0,<br>false<br>} | Motion path of the component. The input parameters are described as follows:<br>- **path**: motion path of the translation animation. The value is an SVG path string.<br>- **from**: start point of the motion path. The default value is **0.0**.<br>- **to**: end point of the motion path. The default value is **1.0**.<br>- **rotatable**: whether to rotate along the path.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct MotionPathExample {
  @State toggle: boolean = true

  build() {
    Column() {
      Button('click me')
        .motionPath({ path: 'Mstart.x start.y L300 200 L300 500 Lend.x end.y', from: 0.0, to: 1.0, rotatable: true })
        .onClick((event: ClickEvent) => {
          animateTo({ duration: 4000, curve: Curve.Linear }, () => {
            this.toggle = !this.toggle;
          })
        }).backgroundColor(0x317aff)
    }.width('100%').height('100%').alignItems(this.toggle ? HorizontalAlign.Start : HorizontalAlign.Center)
  }
}
```

![en-us_image_0000001212378420](figures/en-us_image_0000001212378420.gif)
