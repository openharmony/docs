# 共享元素转场

 设置页面间转场时共享元素的转场动效。 

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性

| 名称               | 参数                                       | 参数描述                                     |
| ---------------- | ---------------------------------------- | ---------------------------------------- |
| sharedTransition | id:&nbsp;string,<br/>{<br/>duration?: number,<br/>curve?: Curve&nbsp;\|&nbsp;string,<br/>delay?: number,<br/>motionPath?: <br/>{<br/>path: string,<br/>form?: number,<br/>to?: number,<br/>rotatable?: boolean<br/>},<br/>zIndex?: number,<br/>type?: [SharedTransitionEffectType](ts-appendix-enums.md#sharedtransitioneffecttype)<br/>} | 两个页面中id值相同且不为空字符串的组件即为共享元素，在页面转场时可显示共享元素转场动效。<br/>-&nbsp; id：设置组件的id。<br/>-&nbsp; duration：单位为毫秒，默认动画时长为1000毫秒。<br/>-&nbsp;curve：默认曲线为Linear，有效值参见[Curve](ts-appendix-enums.md#curve)&nbsp;说明。<br/>-&nbsp;delay：单位为毫秒，默认不延时播放。<br/>-&nbsp;motionPath：运动路径信息。<br/>-&nbsp;path：设置路径。<br/>-&nbsp;from：设置起始值。<br/>-&nbsp;to：设置终止值。<br/>-&nbsp;rotatable：是否旋转。<br/>-&nbsp;zIndex：设置Z轴。<br/>-&nbsp;type：动画类型。 |


## 示例

示例代码为点击图片跳转页面时，显示共享元素图片的自定义转场动效。 

```ts
// xxx.ets
@Entry
@Component
struct SharedTransitionExample {
  @State active: boolean = false

  build() {
    List() {
      ListItem() {
        Row() {
          Navigator({ target: 'pages/common/Animation/transAnimation/PageB', type: NavigationType.Push }) {
            Image($r('app.media.ic_health_heart')).width(50).height(50)
              .sharedTransition('sharedImage1', { duration: 800, curve: Curve.Linear, delay: 100 })
          }.padding({ left: 10 })
          .onClick(() => {
            this.active = true
          })

          Text('SharedTransition').width(80).height(80).textAlign(TextAlign.Center)
        }
      }
    }
  }
}
```

```
// PageB
@Entry
@Component
struct BExample {
  build() {
    Stack() {
      Image($r('app.media.ic_health_heart')).width(150).height(150).sharedTransition('sharedImage1')
    }.width('100%').height(400)
  }
}
```

![zh-cn_image_0000001219744195](figures/zh-cn_image_0000001219744195.gif)
