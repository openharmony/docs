# 属性动画

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


组件的通用属性发生变化时，可以创建属性动画进行渐变，提升用户体验。


| 名称         | 参数类型                                     | 默认值             | 描述                      |
| ---------- | ---------------------------------------- | --------------- | ----------------------- |
| duration   | number                                   | 1000            | 单位为毫秒，默认动画时长为1000毫秒。    |
| curve      | Curve                                    | Curve.Linear    | 默认曲线为线性。                |
| delay      | number                                   | 0               | 单位为毫秒，默认不延时播放。          |
| iterations | number                                   | 1               | 默认播放一次，设置为-1时表示无限次播放。   |
| playMode   | [PlayMode](ts-appendix-enums.md#playmode枚举值说明) | PlayMode.Normal | 设置动画播放模式，默认播放完成后重头开始播放。 |


- Curve枚举说明
  | 名称                  | 描述                                       |
  | ------------------- | ---------------------------------------- |
  | Linear              | 表示动画从头到尾的速度都是相同的。                        |
  | Ease                | 表示动画以低速开始，然后加快，在结束前变慢，CubicBezier(0.25,&nbsp;0.1,&nbsp;0.25,&nbsp;1.0)。 |
  | EaseIn              | 表示动画以低速开始，CubicBezier(0.42,&nbsp;0.0,&nbsp;1.0,&nbsp;1.0)。 |
  | EaseOut             | 表示动画以低速结束，CubicBezier(0.0,&nbsp;0.0,&nbsp;0.58,&nbsp;1.0)。 |
  | EaseInOut           | 表示动画以低速开始和结束，CubicBezier(0.42,&nbsp;0.0,&nbsp;0.58,&nbsp;1.0)。 |
  | FastOutSlowIn       | 标准曲线，cubic-bezier(0.4,&nbsp;0.0,&nbsp;0.2,&nbsp;1.0)。 |
  | LinearOutSlowIn     | 减速曲线，cubic-bezier(0.0,&nbsp;0.0,&nbsp;0.2,&nbsp;1.0)。 |
  | FastOutLinearIn     | 加速曲线，cubic-bezier(0.4,&nbsp;0.0,&nbsp;1.0,&nbsp;1.0)。 |
  | ExtremeDeceleration | 急缓曲线，cubic-bezier(0.0,&nbsp;0.0,&nbsp;0.0,&nbsp;1.0)。 |
  | Sharp               | 锐利曲线，cubic-bezier(0.33,&nbsp;0.0,&nbsp;0.67,&nbsp;1.0)。 |
  | Rhythm              | 节奏曲线，cubic-bezier(0.7,&nbsp;0.0,&nbsp;0.2,&nbsp;1.0)。 |
  | Smooth              | 平滑曲线，cubic-bezier(0.4,&nbsp;0.0,&nbsp;0.4,&nbsp;1.0)。 |
  | Friction            | 阻尼曲线，CubicBezier(0.2,&nbsp;0.0,&nbsp;0.2,&nbsp;1.0)。 |


## 示例

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
          duration: 2000, // 动画时长
          curve: Curve.EaseOut, // 动画曲线
          delay: 500, // 动画延迟
          iterations: 1, // 播放次数
          playMode: PlayMode.Normal // 动画模式
        }) // 对Button组件的宽高属性进行动画配置
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001174264358](figures/zh-cn_image_0000001174264358.gif)
