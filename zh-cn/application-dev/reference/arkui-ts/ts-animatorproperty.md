# 属性动画

> **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

组件的通用属性发生变化时，可以创建属性动画进行渐变，提升用户体验。

| 接口名称                       | 功能描述                                                     |
| ------------------------------ | ------------------------------------------------------------ |
| animation(value: AnimateParam) | 为组件添加动画属性，控制调用此属性的组件从一种状态到另一种状态的过渡效果。 |

## AnimateParam对象说明

- 属性


| 名称         | 参数类型                                     | 默认值             | 描述                      |
| ---------- | ---------------------------------------- | --------------- | ----------------------- |
| duration   | number                                   | 1000            | 单位为毫秒，默认动画时长为1000毫秒。    |
| curve      | [Curve](ts-appendix-enums.md#curve)        | Curve.Linear    | 默认曲线为线性。                |
| delay      | number                                   | 0               | 单位为毫秒，默认不延时播放。          |
| iterations | number                                   | 1               | 默认播放一次，设置为-1时表示无限次播放。   |
| playMode   | [PlayMode](ts-appendix-enums.md#playmode) | PlayMode.Normal | 设置动画播放模式，默认播放完成后重头开始播放。 |


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
