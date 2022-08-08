# 浮层

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性


| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| overlay | title:&nbsp;string,<br/>options:&nbsp;{<br/>align?:&nbsp;[Alignment](ts-appendix-enums.md#alignment枚举说明),<br/>offset?:&nbsp;{x:&nbsp;number,&nbsp;y:&nbsp;number}<br/>} | {<br/>align:&nbsp;Alignment.Center,<br/>offset:&nbsp;{0,&nbsp;0}<br/>} | 在当前组件上，增加遮罩文本，布局与当前组件相同。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct OverlayExample {
  build() {
    Column() {
      Column() {
        Text('floating layer')
          .fontSize(12).fontColor(0xCCCCCC).maxLines(1)
        Column() {
          Image($r('app.media.img'))
            .width(240).height(240)
            .overlay("Winter is a beautiful season, especially when it snows.", { align: Alignment.Bottom, offset: { x: 0, y: -15 } })
        }.border({ color: Color.Black, width: 2 })
      }.width('100%')
    }.padding({ top: 20 })
  }
}
```

![zh-cn_image_0000001205769446](figures/zh-cn_image_0000001205769446.png)
