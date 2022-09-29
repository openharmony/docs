# RemoteWindow

**\<RemoteWindow>** is a component used to control the application window, providing the component animator and application window linkage animator during application startup and exit.

>  **NOTE**
>  
>  This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The APIs provided by this component are system APIs.

## Child Components

Not supported

## APIs

RemoteWindow(target: WindowAnimationTarget)

Creates a **\<RemoteWindow>** through a window animation object.

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | target | [WindowAnimationTarget](#windowanimationtarget) | Yes| - | Description of the animation window to control.|

## WindowAnimationTarget
Implements a target window, which is used to remotely control the animation.

| Name     | Type    | Description|
| ------- | ------ | ----------------------- |
| bundleName  | string | Process corresponding to the animation window.|
| abilityName | string | Ability corresponding to the animation window.|
| windowBounds | [RRect](#rrect) | Actual size of the animation window.|
| missionId  | number | Mission ID.|

## RRect
Implements a rounded rectangle.

| Name     | Type    | Description|
| ------- | ------ | ----------------------- |
| left  | number | Horizontal coordinate of the upper left corner of the animation window relative to the screen.|
| top | number | Vertical coordinate of the upper left corner of the animation window relative to the screen.|
| width | number | Width of the animation window.|
| height | number | Height of the animation window.|
| radius | number | Radius of the rounded corner of the animation window.|

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are supported.

## Events

The [universal events](ts-universal-events-click.md) are supported.

## Example

```ts
// xxx.ets
@Entry
@Component
struct RemoteWindowExample {
  @State target: WindowAnimationTarget = undefined // Obtained through windowAnimationManager

  build() {
    Column() {
      RemoteWindow(this.target)
      	.translate({ x: 100, y: 200 })
      	.scale({ x: 0.5, y: 0.5 })
        .opacity(0.8)
      	.position({ x: px2vp(this.target?.windowBounds.left), y: px2vp(this.target?.windowBounds.top) })
      	.width(px2vp(this.target?.windowBounds.width))
      	.height(px2vp(this.target?.windowBounds.height))
     }
  }
}
```
