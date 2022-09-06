# ListItemGroup

该组件用来展示列表item分组，宽度默认充满[List](ts-container-list.md)组件，必须配合List组件来使用。

> **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

包含[ListItem](ts-container-listitem.md)子组件。


## 接口

ListItemGroup(options?: {header?: CustomBuilder, footer?: CustomBuilder, space?: number | string})

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| header | [CustomBuilder](../../ui/ts-types.md#custombuilder8) | 否 |  设置ListItemGroup头部组件。 |
| footer | [CustomBuilder](../../ui/ts-types.md#custombuilder8) | 否 |  设置ListItemGroup尾部组件。 |
| space | number&nbsp;\|&nbsp;string | 否 | 列表项间距。 |

## 属性

| 名称 | 参数类型 |  描述 |
| -------- | -------- | -------- |
| divider | {<br/>strokeWidth:&nbsp;[Length](../../ui/ts-types.md#length),<br/>color?:&nbsp;[ResourceColor](../../ui/ts-types.md#resourcecolor8),<br/>startMargin?:&nbsp;[Length](../../ui/ts-types.md#length),<br/>endMargin?:&nbsp;[Length](../../ui/ts-types.md#length)<br/>}&nbsp;\|&nbsp;null | 用于设置ListItem分割线样式，默认无分割线。<br/>strokeWidth:&nbsp;分割线的线宽。<br/>color:&nbsp;分割线的颜色。<br/>startMargin：&nbsp;分割线距离列表侧边起始端的距离。<br/>endMargin:&nbsp;分割线距离列表侧边结束端的距离。 |


## 示例

```ts
// xxx.ets
function itemHeadBuilder(text: string) {
  @Builder function itemHead() {
    Text(text)
      .fontSize(20)
      .backgroundColor(0xAABBCC)
      .width("100%")
      .padding(10)
  }
  return itemHead
}

function itemFootBuilder(num: number) {
  @Builder function itemFoot() {
    Text('共' + num + "节课")
      .fontSize(16)
      .backgroundColor(0xAABBCC)
      .width("100%")
      .padding(5)
  }
  return itemFoot
}

@Entry
@Component
struct ListItemGroupExample {
  private timetable: any = [
    {
      title:'星期一',
      projects:['语文', '数学', '英语']
    },
    {
      title:'星期二',
      projects:['物理', '化学', '生物']
    },
    {
      title:'星期三',
      projects:['历史', '地理', '政治']
    },
    {
      title:'星期四',
      projects:['美术', '音乐', '体育']
    }
  ]

  build() {
    Column() {
      List({ space: 20 }) {
        ForEach(this.timetable, (item) => {
          ListItemGroup({ header:itemHeadBuilder(item.title), footer:itemFootBuilder(item.projects.length) }) {
            ForEach(item.projects, (project) => {
              ListItem() {
                Text(project)
                  .width("100%").height(100).fontSize(20)
                  .textAlign(TextAlign.Center).backgroundColor(0xFFFFFF)
              }
            }, item => item)
          }
          .borderRadius(20)
          .divider({ strokeWidth: 1, color: 0xDCDCDC }) // 每行之间的分界线
        })
      }
      .width('90%')
      .sticky(StickyStyle.Header|StickyStyle.Footer)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001219864159](figures/zh-cn_image_listitemgroup.gif)
