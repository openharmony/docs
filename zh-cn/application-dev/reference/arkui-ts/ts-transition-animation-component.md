# 组件内转场

组件转场主要通过transition属性进行配置转场参数，在组件插入和删除时进行过渡动效，主要用于容器组件子组件插入删除时提升用户体验（需要配合animateTo才能生效，动效时长、曲线、延时跟随animateTo中的配置）。

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称 | 参数类型 | 默认值 | 参数描述 |
| -------- | -------- | -------- | -------- |
| transition | Object | - | 所有参数均为可选参数，详细描述见transition入参说明。 |

- transition入参说明
  | 参数名称 | 参数类型 | 默认值 | 必填 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | type | [TransitionType](ts-appendix-enums.md#transitiontype)  | TransitionType.All | 否 | 默认包括组件新增和删除。<br/>>&nbsp;&nbsp;**说明：**<br/>>&nbsp;不指定Type时说明插入删除使用同一种效果。 |
  | opacity | number | 1 | 否 | 设置组件转场时的透明度效果，为插入时起点和删除时终点的值。 |
  | translate | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number<br/>} | - | 否 | 设置组件转场时的平移效果，为插入时起点和删除时终点的值。<br/>-x：横向的平移距离。<br/>-y：纵向的平移距离。<br/>-z：竖向的平移距离。 |
  | scale | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number,<br/>centerX?&nbsp;:&nbsp;number,<br/>centerY?&nbsp;:&nbsp;number<br/>} | - | 否 | 设置组件转场时的缩放效果，为插入时起点和删除时终点的值。<br/>-x：横向放大倍数（或缩小比例）。<br/>-y：纵向放大倍数（或缩小比例）。<br/>-z：竖向放大倍数（或缩小比例）。<br/>-&nbsp;centerX、centerY缩放中心点。<br/>-&nbsp;中心点为0时，默认的是组件的左上角。<br/> |
  | rotate | {<br/>x?:&nbsp;number,<br/>y?:&nbsp;number,<br/>z?:&nbsp;number,<br/>angle?:&nbsp;Angle,<br/>centerX?:&nbsp;Length,<br/>centerY?:&nbsp;Length<br/>} | - | 否 | 设置组件转场时的旋转效果，为插入时起点和删除时终点的值。<br/>-x：横向的旋转向量。<br/>-y：纵向的旋转向量。<br/>-z：竖向的旋转向量。<br/>-&nbsp;centerX,centerY指旋转中心点。<br/>-&nbsp;中心点为（0，0）时，默认的是组件的左上角。 |


## 示例

示例功能通过一个Button控制第二个Button的出现和消失，并通过transition配置第二个Button出现和消失的过场动画。

```ts
// xxx.ets
@Entry
@Component
struct TransitionExample {
  @State btn: boolean = false
  @State show: string = "show"

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center,}) {
      Button(this.show).width(80).height(30).backgroundColor(0x317aff).margin({bottom:50})
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            this.btn = !this.btn
            if(this.btn){
              this.show = "hide"
            }else{
              this.show = "show"
            }
          })
        })
      if (this.btn) {
        // 插入和删除配置为不同的过渡效果
        Button() {
          Image($r('app.media.bg1')).width("80%").height(300)
        }.transition({ type: TransitionType.Insert, scale : {x:0,y:1.0} })
        .transition({ type: TransitionType.Delete, scale: { x: 1.0, y: 0.0 } })
      }
    }.height(400).width("100%").padding({top:100})
  }
}
```

![zh-cn_image_0000001174582850](figures/zh-cn_image_0000001174582850.gif)
