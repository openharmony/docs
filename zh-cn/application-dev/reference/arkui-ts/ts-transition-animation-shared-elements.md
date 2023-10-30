# 共享元素转场

当路由进行切换时，可以通过设置组件的 sharedTransition 属性将该元素标记为共享元素并设置对应的共享元素转场动效。

> **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称             | 参数                                                         | 参数描述                                                     |
| ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| sharedTransition | id:&nbsp;string,<br/>{<br/>&nbsp;duration?: number,<br/>&nbsp;curve?: [Curve](ts-appendix-enums.md#curve)&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[ICurve](../apis/js-apis-curve.md#icurve)<sup>10+</sup>,<br/>&nbsp;delay?: number,<br/>&nbsp;motionPath?: <br/>{<br/>&nbsp;path: string,<br/>&nbsp;form?: number,<br/>&nbsp;to?: number,<br/>&nbsp;rotatable?: boolean<br/>},<br/>zIndex?: number,<br/>type?: [SharedTransitionEffectType](ts-appendix-enums.md#sharedtransitioneffecttype)<br/>} | 两个页面中id值相同且不为空字符串的组件即为共享元素，在页面转场时可显示共享元素转场动效。<br/>-&nbsp;id：设置组件的id。<br/>-&nbsp;duration：描述共享元素转场动效播放时长。<br/>默认值：1000<br/>单位：毫秒<br/>取值范围：[0, +∞)<br/>值为0时表示无动画。设置小于0的值时，按默认值1000处理。<br/>-&nbsp;curve：默认曲线为Curve.Linear。<br/>-&nbsp;delay：用来描述共享元素转场动效延迟播放的时长。<br/>默认值：0<br/>单位：毫秒<br/>取值范围：[0, +∞)<br/>设置小于0的值时，按值为0处理。<br/>-&nbsp;motionPath：运动路径信息，详细说明请参考[路径动画](ts-motion-path-animation.md)。<br/>{<br/>-&nbsp;path：设置路径。<br/>-&nbsp;from：设置起始值。<br/>-&nbsp;to：设置终止值。<br/>-&nbsp;rotatable：是否旋转。<br/>默认值：false<br/> }<br/>-&nbsp;zIndex：设置Z轴。<br/>默认值：0<br/>-&nbsp;type：动画类型。<br/>默认值：SharedTransitionEffectType.Exchange |

> **说明：**
>
> type为SharedTransitionEffectType.Exchange时motionPath才会生效。

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