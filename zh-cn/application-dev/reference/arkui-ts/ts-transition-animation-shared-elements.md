# 共享元素转场

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


共享元素转场支持页面间的转场，如当前页面的图片转场至下一页面中。


## 属性

| 名称 | 参数 | 默认值 | 参数描述 |
| -------- | -------- | -------- | -------- |
| sharedTransition | id:&nbsp;string,<br/>options?:&nbsp;Object | - | 两个页面的组件配置为同一个id，则转场过程中会进行共享元素转场，配置为空字符串时不会有共享元素转场效果。 |

- options参数说明
  | 参数名称 | 参数类型 | 默认值 | 必填 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | duration | number | 1000 | 否 | 单位为毫秒，默认动画时长为1000毫秒。 | 
  | curve | Curve&nbsp;\|&nbsp;Curves | Linear | 否 | 默认曲线为线性，有效值参见Curve说明。 | 
  | delay | number | 0 | 否 | 单位为毫秒，默认不延时播放。 |


## 示例

示例功能为两个页面，共享元素转场页面图片点击后转场至页面B的图片。

```
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
