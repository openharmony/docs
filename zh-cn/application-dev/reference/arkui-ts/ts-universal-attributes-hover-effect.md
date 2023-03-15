# 悬浮态效果

设置组件的鼠标悬浮态显示效果。

>  **说明：**
>
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性

| 名称          | 参数类型                                               | 描述                                                |
| ----------- | --------------------------------------------------| ------------------------------------------------ |
| hoverEffect | [HoverEffect](ts-appendix-enums.md#hovereffect8)  | 设置当前组件悬停态下的悬浮效果。<br>默认值：HoverEffect.Auto |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct HoverExample {
  @State isHoverVal: boolean = false

  build() {
    Column({ space: 5 }) {
      Column({ space: 5 }) {
        Text('Scale').fontSize(20).fontColor(Color.Gray).width('90%').position({ x: 0, y: 80 })
        Column()
          .width('80%').height(200).backgroundColor(Color.Gray)
          .position({ x: 40, y: 120 })
          .hoverEffect(HoverEffect.Scale)
          .onHover((isHover: boolean) => {
            console.info('Scale isHover: ' + isHover)
            this.isHoverVal = isHover
          })

        Text('Board').fontSize(20).fontColor(Color.Gray).width('90%').position({ x: 0, y: 380 })
        Column()
          .width('80%').height(200).backgroundColor(Color.Gray)
          .hoverEffect(HoverEffect.Highlight)
          .position({ x: 40, y: 420 })
          .onHover((isHover: boolean) => {
            console.info('Highlight isHover: ' +isHover )
            this.isHoverVal = isHover
          })
      }
      .hoverEffect(HoverEffect.None)
      .width('100%').height('100%').border({ width: 1 })
      .onHover((isHover: boolean) => {
        console.info('HoverEffect.None')
        this.isHoverVal = isHover
      })
    }
  }
}
```
