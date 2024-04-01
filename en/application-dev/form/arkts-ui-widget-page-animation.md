# Using Animations in the Widget


To make your ArkTS widget more engaging, you can apply animations to it, including [explicit animation](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md), [property animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md), and [component transition](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md). Just note the following restrictions when using the animations in ArkTS widgets.

**Table 1** Restrictions on animation parameters

| Name| Description| Description|
| -------- | -------- | -------- |
| duration | Animation playback duration| The maximum value is 1 second. If a larger value is set, the animation is still played for 1 second.|
| tempo | Animation playback speed.| Do not set this parameter in the widget. Use the default value 1.|
| delay | Animation delay duration.| Do not set this parameter in the widget. Use the default value 0.|
| iterations | Number of times that the animation is played.| Do not set this parameter in the widget. Use the default value 1.|

>**NOTE**
>
>Static widgets do not support animations.

The following sample code implements the animation effect of button rotation.

![WidgetAnimation](figures/WidgetAnimation.gif)



```ts
@Entry
@Component
struct AnimationCard {
  @State rotateAngle: number = 0;

  build() {
    Row() {
      Button('change rotate angle')
        .height('20%')
        .width('90%')
        .margin('5%')
        .onClick(() => {
          this.rotateAngle = (this.rotateAngle === 0 ? 90 : 0);
        })
        .rotate({ angle: this.rotateAngle })
        .animation({
          curve: Curve.EaseOut,
          playMode: PlayMode.Normal,
        })
    }.height('100%').alignItems(VerticalAlign.Center)
  }
}
```
