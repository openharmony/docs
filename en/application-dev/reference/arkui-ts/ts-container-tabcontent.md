# TabContent

The **\<TabContent>** component is used only in the **\<Tabs>** component. It corresponds to the content view of a switched tab page.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component supports only one child component.

>  **NOTE**
>
>  System components and custom components can be built in, and rendering control types ([if/else](../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)) are supported.


## APIs

TabContent()


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| tabBar | string \| Resource \| {<br>icon?: string \| Resource,<br>text?: string \| Resource<br>}<br>\| [CustomBuilder](ts-types.md)<sup>8+</sup> | Content displayed on the tab bar.<br>**CustomBuilder**: builder, to which components can be passed (applicable to API version 8 and later versions).<br>**NOTE**<br>If an icon uses an SVG image, the width and height attributes of the SVG image must be deleted. Otherwise, the icon size will be determined by the width and height attributes of the SVG image.<br>If the content set exceeds the space provided by the tab bar, it will be clipped.|
| tabBar<sup>9+</sup> | [SubTabBarStyle](#subtabbarstyle9) \| [BottomTabBarStyle](#bottomtabbarstyle9) | Content displayed on the tab bar.<br>**SubTabBarStyle**: subtab style. It takes text as its input parameter.<br>**BottomTabBarStyle**: bottom and side tab style. It takes text and images as its input parameters.<br>**NOTE**<br>The bottom tab style does not include an underline.<br>When an icon display error occurs, a gray blank block is displayed.|

>  **NOTE**
>
>  - The **\<TabContent>** component does not support setting of the common width attribute. By default, its width is the same as that of the parent **\<Tabs>** component.
>  - The **\<TabContent>** component does not support setting of the common height attribute. Its height is determined by the height of the parent **\<Tabs>** component and the **\<TabBar>** component.
>  - If the **vertical** attribute is **false**, the width and height descriptions are swapped in the preceding two restrictions.
>  - **\<TabContent>** does not support page scrolling. If page scrolling is required, consider nesting a list.

## SubTabBarStyle<sup>9+</sup>

Implements the subtab style.

### constructor

constructor(content: string | Resource)

Constructor used to create a **SubTabBarStyle** instance.

**Parameters**

| Name| Type        | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| content | string \| [Resource](ts-types.md#resource) | Yes| Text for the tab. Since API version 10, the type of **content** is **ResourceStr**.|

### of<sup>10+</sup>

static of(content: ResourceStr)

Static constructor used to create a **SubTabBarStyle** instance.

**Parameters**

| Name | Type                                  | Mandatory| Description          |
| ------- | ------------------------------------------ | ---- | ------------------ |
| content | [ResourceStr](ts-types.md#resourcestr) | Yes  | Text for the tab.|

### Attributes

The following attributes are supported.

| Name        | Type                                                    | Description                                                        |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| indicator<sup>10+</sup> | [IndicatorStyle](#indicatorstyle10)| Underline indicator style of the selected subtab. It is valid only in the horizontal layout.<br>               |
| selectedMode<sup>10+</sup> | [SelectedMode](#selectedmode10)   | Display mode of the selected subtab.<br>Default value: **SelectedMode.INDICATOR**|
| board<sup>10+</sup> | [BoardStyle](#boardstyle10)   | Board style of the selected subtab.|
| labelStyle<sup>10+</sup> | [LabelStyle](#labelstyle10) | Label text and font style of the selected subtab.|

## IndicatorStyle<sup>10+</sup>

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------------------------------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | No| Underline indicator color and board color.<br>Default value: **#FF007DFF**|
| height | [Length](ts-types.md#length) | No| Height of the underline indicator.<br>Default value: **2.0**<br>Unit: vp|
| width | [Length](ts-types.md#length) | No| Width of the underline indicator.<br>Default value: **0.0**<br>Unit: vp|
| borderRadius | [Length](ts-types.md#length) | No| Radius of the rounded corner of the underline indicator.<br>Default value: **0.0**<br>Unit: vp|
| marginTop | [Length](ts-types.md#length) | No| Spacing between the underline indicator and text.<br>Default value: **8.0**<br>Unit: vp|

## SelectedMode<sup>10+</sup>
| Name      | Description                    |
| ---------- | ------------------------ |
| INDICATOR | Underline indicator mode.    |
| BOARD   | Board mode.    |

## BoardStyle<sup>10+</sup>

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | ------------------------------------ |
| borderRadius | [Length](ts-types.md#length) | No| Radius of the rounded corner of the underline indicator.<br>Default value: **8.0**<br>Unit: vp|

## LabelStyle<sup>10+</sup>

| Name                | Type                                                    | Mandatory| Description                                                        |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| overflow             | [TextOverflow](ts-appendix-enums.md#textoverflow)            | No  | Display mode when the label text is too long. By default, an ellipsis (...) is used to represent text overflow.|
| maxLines             | number                                                       | No  | Maximum number of lines in the label text. If this attribute is specified, the text will not exceed the specified number of lines. You can use **textOverflow** to specify how to represent text overflow. Default value: **1**|
| minFontSize          | number \| [ResourceStr](ts-types.md#resourcestr)             | No  | Minimum font size of the label text. For the setting to take effect, this attribute must be used together with **maxFontSize**, **maxLines**, or layout constraint settings. When the adaptive text size is set, **font.size** does not take effect. Default value: **0.0fp**|
| maxFontSize          | number \| [ResourceStr](ts-types.md#resourcestr)             | No  | Maximum font size of the label text. For the setting to take effect, this attribute must be used together with **minFontSize**, **maxLines**, or layout constraint settings. When the adaptive text size is set, **font.size** does not take effect. Default value: **0.0fp**|
| heightAdaptivePolicy | [TextHeightAdaptivePolicy](ts-appendix-enums.md#textheightadaptivepolicy10) | No  | How the adaptive height is determined for the label text. By default, the **maxLines** settings are prioritized.                             |
| font                 | [Font](ts-types.md#font)                                     | No  | Font of the label text. By default, the font size is 16.0fp, the font type is HarmonyOS Sans, the font style is normal, and the font weight is normal.     |

## BottomTabBarStyle<sup>9+</sup>

Implements the bottom and side tab style.

### constructor

constructor(icon: string | Resource, content: string | Resource)

A constructor used to create a **BottomTabBarStyle** instance.

**Parameters**

| Name| Type        | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | string \| [Resource](ts-types.md#resource) | Yes| Image for the tab. Since API version 10, the type of **icon** is **ResourceStr**.|
| text | string \| [Resource](ts-types.md#resource) | Yes| Text for the tab. Since API version 10, the type of **text** is **ResourceStr**.|

### of<sup>10+</sup>

static of(icon: ResourceStr, text: ResourceStr)
Static constructor used to create a **BottomTabBarStyle** instance.

**Parameters**

| Name| Type        | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | [ResourceStr](ts-types.md#resourcestr) | Yes| Image for the tab.|
| text | [ResourceStr](ts-types.md#resourcestr) | Yes| Text for the tab.|

## Example

Example 1:

```ts
// xxx.ets
@Entry
@Component
struct TabContentExample {
  @State fontColor: string = '#182431'
  @State selectedFontColor: string = '#007DFF'
  @State currentIndex: number = 0
  private controller: TabsController = new TabsController()

  @Builder TabBuilder(index: number) {
    Column() {
      Image(this.currentIndex === index ? '/common/public_icon_on.svg' : '/common/public_icon_off.svg')
        .width(24)
        .height(24)
        .margin({ bottom: 4 })
        .objectFit(ImageFit.Contain)
      Text(`Tab${index + 1}`)
        .fontColor(this.currentIndex === index ? this.selectedFontColor : this.fontColor)
        .fontSize(10)
        .fontWeight(500)
        .lineHeight(14)
    }.width('100%')
  }

  build() {
    Column() {
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {
        TabContent() {
          Column() {
            Text('Tab1')
              .fontSize(36)
              .fontColor('#182431')
              .fontWeight(500)
              .opacity(0.4)
              .margin({ top: 30, bottom: 56.5 })
            Divider()
              .strokeWidth(0.5)
              .color('#182431')
              .opacity(0.05)
          }.width('100%')
        }.tabBar(this.TabBuilder(0))

        TabContent() {
          Column() {
            Text('Tab2')
              .fontSize(36)
              .fontColor('#182431')
              .fontWeight(500)
              .opacity(0.4)
              .margin({ top: 30, bottom: 56.5 })
            Divider()
              .strokeWidth(0.5)
              .color('#182431')
              .opacity(0.05)
          }.width('100%')
        }.tabBar(this.TabBuilder(1))

        TabContent() {
          Column() {
            Text('Tab3')
              .fontSize(36)
              .fontColor('#182431')
              .fontWeight(500)
              .opacity(0.4)
              .margin({ top: 30, bottom: 56.5 })
            Divider()
              .strokeWidth(0.5)
              .color('#182431')
              .opacity(0.05)
          }.width('100%')
        }.tabBar(this.TabBuilder(2))

        TabContent() {
          Column() {
            Text('Tab4')
              .fontSize(36)
              .fontColor('#182431')
              .fontWeight(500)
              .opacity(0.4)
              .margin({ top: 30, bottom: 56.5 })
            Divider()
              .strokeWidth(0.5)
              .color('#182431')
              .opacity(0.05)
          }.width('100%')
        }.tabBar(this.TabBuilder(3))
      }
      .vertical(false)
      .barHeight(56)
      .onChange((index: number) => {
        this.currentIndex = index
      })
      .width(360)
      .height(190)
      .backgroundColor('#F1F3F5')
      .margin({ top: 38 })
    }.width('100%')
  }
}
```

![tabContent](figures/tabContent1.gif)

Example 2:

```ts
// xxx.ets
@Entry
@Component
struct TabContentExample {
  @State fontColor: string = '#182431'
  @State selectedFontColor: string = '#007DFF'
  @State currentIndex: number = 0
  private controller: TabsController = new TabsController()

  @Builder TabBuilder(index: number) {
    Column() {
      Image(this.currentIndex === index ? '/common/public_icon_on.svg' : '/common/public_icon_off.svg')
        .width(24)
        .height(24)
        .margin({ bottom: 4 })
        .objectFit(ImageFit.Contain)
      Text('Tab')
        .fontColor(this.currentIndex === index ? this.selectedFontColor : this.fontColor)
        .fontSize(10)
        .fontWeight(500)
        .lineHeight(14)
    }.width('100%').height('100%').justifyContent(FlexAlign.Center)
  }

  build() {
    Column() {
      Tabs({ barPosition: BarPosition.Start, controller: this.controller }) {
        TabContent()
          .tabBar(this.TabBuilder(0))
        TabContent()
          .tabBar(this.TabBuilder(1))
        TabContent()
          .tabBar(this.TabBuilder(2))
        TabContent()
          .tabBar(this.TabBuilder(3))
      }
      .vertical(true)
      .barWidth(96)
      .barHeight(414)
      .onChange((index: number) => {
        this.currentIndex = index
      })
      .width(96)
      .height(414)
      .backgroundColor('#F1F3F5')
      .margin({ top: 52 })
    }.width('100%')
  }
}
```

![tabContent](figures/tabContent2.gif)

Example 3:

```ts
// xxx.ets
@Entry
@Component
struct TabBarStyleExample {
  build() {
    Column({ space: 5 }) {
      Text ("Subtab Style")
      Column() {
        Tabs({ barPosition: BarPosition.Start }) {
          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Pink)
          }.tabBar(new SubTabBarStyle('Pink'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Yellow)
          }.tabBar(new SubTabBarStyle('Yellow'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Blue)
          }.tabBar(new SubTabBarStyle('Blue'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Green)
          }.tabBar(new SubTabBarStyle('Green'))
        }
        .vertical(false)
        .scrollable(true)
        .barMode(BarMode.Fixed)
        .onChange((index: number) => {
          console.info(index.toString())
        })
        .width('100%')
        .backgroundColor(0xF1F3F5)
      }.width('100%').height(200)
      Text ("Bottom Tab Style")
      Column() {
        Tabs({ barPosition: BarPosition.End }) {
          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Pink)
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'pink'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Yellow)
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Yellow'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Blue)
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Blue'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Green)
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Green'))
        }
        .vertical(false)
        .scrollable(true)
        .barMode(BarMode.Fixed)
        .onChange((index: number) => {
          console.info(index.toString())
        })
        .width('100%')
        .backgroundColor(0xF1F3F5)
      }.width('100%').height(200)
      Text ("Side Tab Style")
      Column() {
        Tabs({ barPosition: BarPosition.Start }) {
          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Pink)
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'pink'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Yellow)
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Yellow'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Blue)
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Blue'))

          TabContent() {
            Column().width('100%').height('100%').backgroundColor(Color.Green)
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Green'))
        }
        .vertical(true).scrollable(true).barMode(BarMode.Fixed)
        .onChange((index: number) => {
          console.info(index.toString())
        })
        .width('100%')
        .backgroundColor(0xF1F3F5)
      }.width('100%').height(400)
    }
  }
}
```

![tabbarStyle](figures/TabBarStyle.jpeg)
