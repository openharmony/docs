# 共享元素转场 (sharedTransition)

当路由进行切换时，可以通过设置组件的 sharedTransition 属性将该元素标记为共享元素并设置对应的共享元素转场动效。

> **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称             | 参数类型          | 是否必填                                    | 参数描述                                                     |
| ---------------- | -----------------|------------------------------------------- | ------------------------------------------------------------ |
|      id          |  string         | 是                                         |    两个页面中id值相同且不为空字符串的组件即为共享元素，在页面转场时可显示共享元素转场动效。|
|     options          |  [sharedTransitionOptions](#sharedtransitionoptions)       | 否     |  共享元素转场动画参数。 |

> **说明：**
>
> type为SharedTransitionEffectType.Exchange时motionPath才会生效。

## sharedTransitionOptions

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称              | 参数类型      | 是否必填       | 参数描述                                                      |
| ----------------- | -------------|-------------- | --------------------------------------------------------------|
| duration          |     number   |  否           | 描述共享元素转场动效播放时长。<br>默认值：1000。 <br>单位：毫秒。 |
| curve             |      [Curve](ts-appendix-enums.md#curve)&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[ICurve](../js-apis-curve.md#icurve)<sup>10+</sup>  | 否 | 动画曲线。<br/>默认值：Curve.Linear |
| delay          |     number   |  否           | 延迟播放时间。<br>默认值：0。 <br>单位：毫秒。 |
| motionPath          | [MotionPathOptions](./ts-motion-path-animation.md)  |  否           | 运动路径信息。 |
| zIndex          |     number   |  否              | 设置Z轴。 |
| type           |     [SharedTransitionEffectType](ts-appendix-enums.md#sharedtransitioneffecttype)   |  否   | 动画类型。<br>默认值：SharedTransitionEffectType.Exchange。 |


## 示例

  示例代码为点击图片跳转页面时，显示共享元素图片的自定义转场动效。 

```ts
// xxx.ets
@Entry
@Component
struct SharedTransitionExample {
  @State active: boolean = false

  build() {
    Column() {
      Navigator({ target: 'pages/PageB', type: NavigationType.Push }) {
        Image($r('app.media.ic_health_heart')).width(50).height(50)
          .sharedTransition('sharedImage', { duration: 800, curve: Curve.Linear, delay: 100 })
      }.padding({ left: 20, top: 20 })
      .onClick(() => {
        this.active = true
      })
    }
  }
}
```

```ts
// PageB.ets
@Entry
@Component
struct pageBExample {
  build() {
    Stack() {
      Image($r('app.media.ic_health_heart')).width(150).height(150)
        .sharedTransition('sharedImage', { duration: 800, curve: Curve.Linear, delay: 100 })
    }.width('100%').height('100%')
  }
}
```

![shared](figures/shared.gif)