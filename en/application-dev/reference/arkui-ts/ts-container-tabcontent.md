# TabContent


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;TabContent&gt;** component is used only in the **&lt;Tabs&gt;** component. It corresponds to the content view of a switched tab page.


## Required Permissions

None


## Child Component

This component supports only one child component.


## APIs

TabContent()


## Attributes

Touch target configuration is not supported.

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| tabBar | string&nbsp;\|&nbsp;{<br/>icon?:&nbsp;string,<br/>text?:&nbsp;string<br/>}<br/>\|[CustomBuilder](../../ui/ts-types.md) | - | Content&nbsp;displayed&nbsp;on&nbsp;the&nbsp;tab&nbsp;bar.<br/>**CustomBuilder**:&nbsp;builder,&nbsp;to&nbsp;which&nbsp;components&nbsp;can&nbsp;be&nbsp;passed&nbsp;(applicable&nbsp;to&nbsp;API&nbsp;version&nbsp;8&nbsp;and&nbsp;later&nbsp;versions).<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;If&nbsp;an&nbsp;icon&nbsp;uses&nbsp;an&nbsp;SVG&nbsp;image,&nbsp;the&nbsp;width&nbsp;and&nbsp;height&nbsp;attributes&nbsp;of&nbsp;the&nbsp;SVG&nbsp;image&nbsp;must&nbsp;be&nbsp;deleted.&nbsp;Otherwise,&nbsp;the&nbsp;icon&nbsp;size&nbsp;will&nbsp;be&nbsp;determined&nbsp;by&nbsp;the&nbsp;width&nbsp;and&nbsp;height&nbsp;attributes&nbsp;of&nbsp;the&nbsp;SVG&nbsp;image. |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> - The **&lt;TabContent&gt;** component does not support setting of the common width attribute. By default, its width is the same as that of the parent **&lt;Tabs&gt;** component.
> 
> - The **&lt;TabContent&gt;** component does not support setting of the common height attribute. Its height is determined by the height of the parent **&lt;Tabs&gt;** component and the **&lt;TabBar&gt;** component.


## Example


```
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
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Tab1').fontSize(32)
          }
        }.tabBar(this.TabBuilder(0))

        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Tab2').fontSize(32)
          }
        }.tabBar(this.TabBuilder(1))

        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Add').fontSize(32)
          }
        }.tabBar(this.AddBuilder())

        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
            Text('Tab3').fontSize(32)
          }
        }.tabBar(this.TabBuilder(3))

        TabContent() {
          Flex({justifyContent: FlexAlign.Center})) {
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

![en-us_image_0000001256978331](figures/en-us_image_0000001256978331.gif)
