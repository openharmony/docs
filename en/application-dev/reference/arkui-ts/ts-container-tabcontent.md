# TabContent<a name="EN-US_TOPIC_0000001237355051"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<TabContent\>**  component is used only in the  **<Tabs\>**  component. It corresponds to the content view of a switched tab page.

## Required Permissions<a name="section988262631714"></a>

None

## Child Component<a name="section5989144051714"></a>

This component supports only one child component.

## APIs<a name="section97451749121712"></a>

TabContent\(\)

## Attributes<a name="section1738516911810"></a>

Touch target configuration is not supported.

<a name="table1854mcpsimp"></a>
<table><thead align="left"><tr id="row1861mcpsimp"><th class="cellrowborder" valign="top" width="8.84%" id="mcps1.1.5.1.1"><p id="p1863mcpsimp"><a name="p1863mcpsimp"></a><a name="p1863mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="24.82%" id="mcps1.1.5.1.2"><p id="p1865mcpsimp"><a name="p1865mcpsimp"></a><a name="p1865mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.88%" id="mcps1.1.5.1.3"><p id="p1867mcpsimp"><a name="p1867mcpsimp"></a><a name="p1867mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="54.459999999999994%" id="mcps1.1.5.1.4"><p id="p1869mcpsimp"><a name="p1869mcpsimp"></a><a name="p1869mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1870mcpsimp"><td class="cellrowborder" valign="top" width="8.84%" headers="mcps1.1.5.1.1 "><p id="p10682mcpsimp"><a name="p10682mcpsimp"></a><a name="p10682mcpsimp"></a>tabBar</p>
</td>
<td class="cellrowborder" valign="top" width="24.82%" headers="mcps1.1.5.1.2 "><p id="p183331827143515"><a name="p183331827143515"></a><a name="p183331827143515"></a>string | {</p>
<p id="p6774182313515"><a name="p6774182313515"></a><a name="p6774182313515"></a>icon?: string,</p>
<p id="p7318830153513"><a name="p7318830153513"></a><a name="p7318830153513"></a>text?: string</p>
<p id="p19256175413408"><a name="p19256175413408"></a><a name="p19256175413408"></a>}</p>
<p id="p10684mcpsimp"><a name="p10684mcpsimp"></a><a name="p10684mcpsimp"></a>| <a href="../../toctopics/en-us_topic_0000001237475069.md#section2538145016250">CustomBuilder</a><sup id="sup0854523143811"><a name="sup0854523143811"></a><a name="sup0854523143811"></a>8+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="11.88%" headers="mcps1.1.5.1.3 "><p id="p10686mcpsimp"><a name="p10686mcpsimp"></a><a name="p10686mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="54.459999999999994%" headers="mcps1.1.5.1.4 "><p id="p10688mcpsimp"><a name="p10688mcpsimp"></a><a name="p10688mcpsimp"></a>Content displayed on the tab bar.</p>
<p id="p2832182695713"><a name="p2832182695713"></a><a name="p2832182695713"></a>CustomBuilder: builder, which can be passed to components (applicable to API 8 or later versions).</p>
<div class="note" id="note66251557181812"><a name="note66251557181812"></a><a name="note66251557181812"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p6625125761813"><a name="p6625125761813"></a><a name="p6625125761813"></a>If an icon uses an SVG image, the width and height attributes of the SVG image must be deleted. Otherwise, the icon size will be determined by the width and height attributes of the SVG image.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **<TabContent\>**  component does not support setting of the common width attribute. By default, its width is the same as that of the parent  **<Tabs\>**  component.
>-   The  **<TabContent\>**  component does not support setting of the common height attribute. Its height is determined by the height of the parent  **<Tabs\>**  component and the  **<TabBar\>**  component.

## Example<a name="section1131255321814"></a>

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

![](figures/en-us_image_0000001193075122.gif)
