# TabContent

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


仅在Tabs中使用，对应一个切换页签的内容视图。


## 权限列表

无


## 子组件

支持单个子组件。


## 接口

TabContent()


## 属性

不支持触摸热区设置。

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| tabBar | string&nbsp;\|&nbsp;{<br/>icon?:&nbsp;string,<br/>text?:&nbsp;string<br/>}<br/>\|&nbsp;[CustomBuilder](../../ui/ts-types.md)<sup>8+</sup> | - | 设置TabBar上显示内容。<br/>CustomBuilder:&nbsp;构造器，内部可以传入组件（API8版本以上适用）。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;如果icon采用svg格式图源，则要求svg图源删除其自有宽高属性值。如采用带有自有宽高属性的svg图源，icon大小则是svg本身内置的宽高属性值大小。 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - TabContent组件不支持设置通用宽度属性，其宽度默认撑满Tabs父组件。
> 
> - TabContent组件不支持设置通用高度属性，其高度由Tabs父组件高度与TabBar组件高度决定。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct TabContentExample  {
  @State fontColor: string = 'rgba(0, 0, 0, 0.4)'
  @State selectedFontColor: string = 'rgba(10, 30, 255, 1)'
  @State currentIndex: number = 0
  private controller: TabsController = new TabsController()
  @Builder TabBuilder(index: number) {
    Column() {
      Image(this.currentIndex === index ? '/resources/ic_public_contacts_filled_selected.png' : '/resources/ic_public_contacts_filled.png')
        .width(10)
        .height(10)
        .opacity(this.currentIndex === index ? 1 : 0.4)
        .objectFit(ImageFit.Contain)
      Text(`Tab${(index > 2 ? (index - 1) : index) + 1}`)
        .fontColor(this.currentIndex === index ? this.selectedFontColor : this.fontColor)
        .fontSize(10)
        .margin({top: 2})
    }
  }

  @Builder AddBuilder() {
    Column() {
      Image(this.currentIndex === 2 ? '/resources/ic_public_add_norm_filled_selected.png' : '/resources/ic_public_add_norm_filled.png')
        .width(this.currentIndex === 2 ? 26 : 24)
        .height(this.currentIndex === 2 ? 26 : 24)
        .opacity(this.currentIndex === 2 ? 1 : 0.4)
        .objectFit(ImageFit.Contain)
        .animation({duration: 200})
    }
  }

  build() {
    Column() {
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {
        TabContent() {
          Flex({justifyContent: FlexAlign.Center}) {
            Text('Tab1').fontSize(32)
          }
        }.tabBar(this.TabBuilder(0))

        TabContent() {
          Flex({justifyContent: FlexAlign.Center}) {
            Text('Tab2').fontSize(32)
          }
        }.tabBar(this.TabBuilder(1))

        TabContent() {
          Flex({justifyContent: FlexAlign.Center}) {
            Text('Add').fontSize(32)
          }
        }.tabBar(this.AddBuilder())

        TabContent() {
          Flex({justifyContent: FlexAlign.Center}) {
            Text('Tab3').fontSize(32)
          }
        }.tabBar(this.TabBuilder(3))

        TabContent() {
          Flex({justifyContent: FlexAlign.Center}) {
            Text('Tab4').fontSize(32)
          }
        }.tabBar(this.TabBuilder(4))
      }
      .vertical(false)
      .barWidth(300).barHeight(56)
      .onChange((index: number) => {
        this.currentIndex = index
      })
      .width('90%').backgroundColor('rgba(241, 243, 245, 0.95)')
    }.width('100%').height(200).margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001186585726](figures/zh-cn_image_0000001186585726.gif)
