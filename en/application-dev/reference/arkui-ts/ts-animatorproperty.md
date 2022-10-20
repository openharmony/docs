# Property Animator

You can create a property animator to animate certain universal attributes of a component, including **width**, **height**, **backgroundColor**, **opacity**, **scale**, **rotate**, and **translate**.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

animation(value: {duration?: number, tempo?: number, curve?: string | Curve, delay?:number, iterations: number, playMode?: PlayMode, onFinish?: () => void})

Applies a property animator to the component to animate its attributes over time.

**Parameters**


| Name        | Type                                      | Mandatory   | Description                                                        |
| ---------- | ------------------------------------------| ---- | ------------------------------------------------------------ |
| duration   | number                                    | No   | Animation duration, in ms.<br>Default value: **1000**|
| tempo      | number                                    | No   | Animation playback speed. A greater value indicates a higher animation playback speed.<br>The value **0** indicates that no animation is applied.<br>Default value: **1**|
| curve      | string&nbsp;\|&nbsp;[Curve](ts-appendix-enums.md#curve) | No  | Animation curve.<br>Default value: **Curve.Linear**  |
| delay      | number                                    | No   | Delay of animation playback, in ms. The value **0** indicates that the playback is not delayed.<br>Default value: **0**  |
| iterations | number                                    | No   | Number of times that the animation is played. The value **-1** indicates that the animation is played for an unlimited number of times.<br>Default value: **1**|
| playMode   | [PlayMode](ts-appendix-enums.md#playmode) | No   | Animation playback mode. By default, the animation is played from the beginning after the playback is complete.<br>Default value: **PlayMode.Normal**|
| onFinish   | () => void                                | No   | Callback invoked when the animation playback is complete.                       |


## Example

```ts
// xxx.ets
@Entry
@Component
struct AttrAnimationExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  @State flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .onClick((event: ClickEvent) => {
          if (this.flag) {
            this.widthSize = 100
            this.heightSize = 50
          } else {
            this.widthSize = 200
            this.heightSize = 100
          }
          this.flag = !this.flag
        })
        .width(this.widthSize).height(this.heightSize).backgroundColor(0x317aff)
        .animation({
          duration: 2000, // Animation duration
          curve: Curve.EaseOut, // Animation curve
          delay: 500, // Animation delay
          iterations: 1, // Number of playback times
          playMode: PlayMode.Normal // Animation playback mode
        }) // Animation configuration for the width and height attributes of the <Button> component
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212378444](figures/en-us_image_0000001212378444.gif)
