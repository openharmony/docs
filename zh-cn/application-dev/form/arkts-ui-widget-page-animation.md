# 卡片使用动效能力


ArkTS卡片开放了使用动画效果的能力，支持[显式动画](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md)、[属性动画](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md)、[组件内转场](../reference/apis-arkui/arkui-ts/ts-transition-animation-component.md)能力。需要注意的是，ArkTS卡片使用动画效果时具有以下限制：

**表1** 动效参数限制

| 名称 | 参数说明 | 限制描述 |
| -------- | -------- | -------- |
| duration | 动画播放时长 | 限制最长的动效播放时长为1秒，当设置大于1秒的时间时，动效时长仍为1秒。 |
| tempo | 动画播放速度 | 卡片中禁止设置此参数，使用默认值1。 |
| delay | 动画延迟执行的时长 | 卡片中禁止设置此参数，使用默认值0。 |
| iterations | 动画播放次数 | 卡片中禁止设置此参数，使用默认值1。 |

>**说明：**
>
>静态卡片不支持使用动效能力。

以下示例代码实现了按钮旋转的动画效果：  
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
