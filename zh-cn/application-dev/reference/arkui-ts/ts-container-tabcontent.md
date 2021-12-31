# TabContent<a name="ZH-CN_TOPIC_0000001237355051"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

仅在Tabs中使用，对应一个切换页签的内容视图。

## 权限列表<a name="section988262631714"></a>

无

## 子组件<a name="section5989144051714"></a>

支持单个子组件。

## 接口<a name="section97451749121712"></a>

TabContent\(\)

## 属性<a name="section1738516911810"></a>

不支持触摸热区设置。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="8.84%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="24.82%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.88%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="54.459999999999994%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="8.84%" headers="mcps1.1.5.1.1 "><p>tabBar</p>
</td>
<td class="cellrowborder" valign="top" width="24.82%" headers="mcps1.1.5.1.2 "><p>string | {</p>
<p>icon?: string,</p>
<p>text?: string</p>
<p>}</p>
<p>| <a href="../../toctopics/zh-cn_topic_0000001237475069.md#section2538145016250">CustomBuilder</a><sup><span>8+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.88%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.1.5.1.4 "><p>设置TabBar上显示内容。</p>
<p>CustomBuilder: 构造器，内部可以传入组件（API8版本以上适用）。</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>如果icon采用svg格式图源，则要求svg图源删除其自有宽高属性值。如采用带有自有宽高属性的svg图源，icon大小则是svg本身内置的宽高属性值大小。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   TabContent组件不支持设置通用宽度属性，其宽度默认撑满Tabs父组件。
>-   TabContent组件不支持设置通用高度属性，其高度由Tabs父组件高度与TabBar组件高度决定。

## 示例<a name="section1131255321814"></a>

```
@Entry
@Component
struct TabContentExample  {
  @State fontColor: string = 'rgba(0, 0, 0, 0.4)'
  @State selectedFontColor: string = 'rgba(10, 30, 255, 1)'
  @State currentIndex: number = 0
  private controller: TabsController = new TabsController()
  @Builder Tab1Builder() {
    Column() {
      Image(this.currentIndex === 0 ? '/resources/ic_public_contacts_filled_selected.png' : '/resources/ic_public_contacts_filled.png')
        .width(24)
        .height(24)
        .opacity(this.currentIndex === 0 ? 1 : 0.4)
        .objectFit(ImageFit.Contain)
      Text("Tab1")
        .fontColor(this.currentIndex === 0 ? this.selectedFontColor : this.fontColor)
        .fontSize(10)
        .margin({top: 2})
    }
  }

  @Builder Tab2Builder() {
    Column() {
      Image(this.currentIndex === 1 ? '/resources/ic_public_contacts_filled_selected.png' : '/resources/ic_public_contacts_filled.png')
        .width(24)
        .height(24)
        .opacity(this.currentIndex === 1 ? 1 : 0.4)
        .objectFit(ImageFit.Contain)
      Text("Tab2")
        .fontColor(this.currentIndex === 1 ? this.selectedFontColor : this.fontColor)
        .fontSize(10)
        .margin({top: 2})
    }
  }

  @Builder Tab3Builder() {
    Column() {
      Image(this.currentIndex === 3 ? '/resources/ic_public_contacts_filled_selected.png' : '/resources/ic_public_contacts_filled.png')
        .width(24)
        .height(24)
        .opacity(this.currentIndex === 3 ? 1 : 0.4)
        .objectFit(ImageFit.Contain)
      Text("Tab3")
        .fontColor(this.currentIndex === 3 ? this.selectedFontColor : this.fontColor)
        .fontSize(10)
        .margin({top: 2})
    }
  }

  @Builder Tab4Builder() {
    Column() {
      Image(this.currentIndex === 4 ? '/resources/ic_public_contacts_filled_selected.png' : '/resources/ic_public_contacts_filled.png')
        .width(24)
        .height(24)
        .opacity(this.currentIndex === 4 ? 1 : 0.4)
        .objectFit(ImageFit.Contain)
      Text("Tab4")
        .fontColor(this.currentIndex === 4 ? this.selectedFontColor : this.fontColor)
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
      Tabs({ barPosition: BarPosition.End, index: 0, controller: this.controller }) {
        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Tab1').fontSize(32)
          }
        }.tabBar(this.Tab1Builder)

        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Tab2').fontSize(32)
          }
        }.tabBar(this.Tab2Builder)

        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Add').fontSize(32)
          }
        }.tabBar(this.AddBuilder)

        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Tab3').fontSize(32)
          }
        }.tabBar(this.Tab3Builder)

        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Tab4').fontSize(32)
          }
        }.tabBar(this.Tab4Builder)
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

![](figures/zh-cn_image_0000001193075122.gif)

