# Navigation

Navigation组件一般作为Page页面的根容器，通过属性设置来展示页面的标题栏、工具栏、导航栏等。

> **说明：**
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含子组件。从API Version 9开始，推荐与[NavRouter](ts-basic-components-navrouter.md)组件搭配使用。


## 接口

Navigation()


## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称             | 参数类型                                     | 描述                                       |
| -------------- | ---------------------------------------- | ---------------------------------------- |
| title          | string&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup>&nbsp;\|&nbsp;[NavigationCommonTitle](#navigationcommontitle类型说明)<sup>9+</sup>&nbsp;\|&nbsp;[NavigationCustomTitle](#navigationcustomtitle类型说明)<sup>9+</sup> | 页面标题。                                    |
| subTitle<sup>deprecated</sup>       | string                                   | 页面副标题。从API Version 9开始废弃，建议使用title代替。                                   |
| menus          | Array<[NavigationMenuItem](#navigationmenuitem类型说明)&gt;&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> | 页面右上角菜单。使用Array<[NavigationMenuItem](#navigationmenuitem类型说明)&gt;&nbsp;写法时，竖屏最多支持显示3个图标，横屏最多支持显示5个图标，多余的图标会被放入自动生成的更多图标。      |
| titleMode      | [NavigationTitleMode](#navigationtitlemode枚举说明)                      | 页面标题栏显示模式。<br/>默认值：NavigationTitleMode.Free |
| toolBar        | [object](#object类型说明)&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8)<sup>8+</sup> | 设置工具栏内容。<br/>items:&nbsp;工具栏所有项。     |
| hideToolBar    | boolean                                  | 隐藏工具栏。<br/>默认值：false<br/>true:&nbsp;隐藏工具栏。<br/>false:&nbsp;显示工具栏。 |
| hideTitleBar   | boolean                                  | 隐藏标题栏。<br/>默认值：false<br/>true:&nbsp;隐藏标题栏。<br/>false:&nbsp;显示标题栏。 |
| hideBackButton | boolean                                  | 隐藏返回键。<br/>默认值：false<br/>true:&nbsp;隐藏返回键。<br/>false:&nbsp;显示返回键。 |
| navBarWidth<sup>9+</sup> | [Length](ts-types.md#length)                         | 导航栏宽度。<br/>默认值：200vp |
| navBarPosition<sup>9+</sup> | [NavBarPosition](#navbarposition枚举说明)             | 导航栏位置。<br/>默认值：NavBarPosition.Start |
| mode<sup>9+</sup> | [NavigationMode](#navigationmode枚举说明)                       | 导航栏的显示模式。<br/>默认值：NavigationMode.Auto |
| backButtonIcon<sup>9+</sup> | string&nbsp;\|&nbsp;[PixelMap](../apis/js-apis-image.md#pixelmap7)&nbsp;\|&nbsp;[Resource](ts-types.md#resource)   | 设置导航栏返回图标。 |
| hideNavBar<sup>9+</sup> | boolean                         | 是否显示导航栏（仅在mode为NavigationMode.Split时生效）。 |


## NavigationMenuItem类型说明

| 名称   | 类型                    | 必填 | 描述                           |
| ------ | ----------------------- | ---- | ------------------------------ |
| value  | string                  | 是   | 菜单栏单个选项的显示文本。     |
| icon   | string                  | 否   | 菜单栏单个选项的图标资源路径。 |
| action | ()&nbsp;=&gt;&nbsp;void | 否   | 当前选项被选中的事件回调。     |

## object类型说明

| 名称   | 类型                    | 必填 | 描述                           |
| ------ | ----------------------- | ---- | ------------------------------ |
| value  | string                  | 是   | 工具栏单个选项的显示文本。     |
| icon   | string                  | 否   | 工具栏单个选项的图标资源路径。 |
| action | ()&nbsp;=&gt;&nbsp;void | 否   | 当前选项被选中的事件回调。     |

## NavigationTitleMode枚举说明

| 名称   | 描述                                       |
| ---- | ---------------------------------------- |
| Free | 当内容为可滚动组件时，标题随着内容向上滚动而缩小（子标题的大小不变、淡出）。向下滚动内容到顶时则恢复原样。 |
| Mini | 固定为小标题模式。                       |
| Full | 固定为大标题模式。                          |

## NavigationCommonTitle类型说明

| 名称   | 类型       | 必填 | 描述      |
| ------ | --------- | ---- | -------- |
| main | string | 是 | 设置主标题。 |
| sub | string | 是 | 设置副标题。 |

## NavigationCustomTitle类型说明

| 名称   | 类型                    | 必填 | 描述                           |
| ------ | ----------------------- | ---- | ------------------------------ |
| builder | [CustomBuilder](ts-types.md#custombuilder8) | 是 | 设置标题栏内容。 |
| height | [TitleHeight](#titleheight枚举说明)&nbsp;\|&nbsp;[Length](ts-types.md#length) | 是 | 设置标题栏高度。 |

## NavBarPosition枚举说明

| 名称 | 描述                                       |
| ---- | ---------------------------------------- |
| Start | 双栏显示时，主列在主轴方向首部。 |
| End   | 双栏显示时，主列在主轴方向尾部。  |

## NavigationMode枚举说明

| 名称 | 描述                                       |
| ---- | ---------------------------------------- |
| Stack | 导航栏与内容区独立显示，相当于两个页面。 |
| Split | 导航栏与内容区分两栏显示。 |
| Auto | 窗口宽度>=520vp时，采用Split模式显示；窗口宽度<520vp时，采用Stack模式显示。 |

## TitleHeight枚举说明

| 名称 | 描述                                       |
| ---- | ---------------------------------------- |
| MainOnly | 只有主标题时标题栏的推荐高度（56vp）。 |
| MainWithSub | 同时有主标题和副标题时标题栏的推荐高度（82vp）。 |


>  **说明：**
> 目前可滚动组件只支持List。


## 事件

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onTitleModeChange(callback:&nbsp;(titleMode:&nbsp;NavigationTitleMode)&nbsp;=&gt;&nbsp;void) | 当titleMode为NavigationTitleMode.Free时，随着可滚动组件的滑动标题栏模式发生变化时触发此回调。 |
| onNavBarStateChange(callback:&nbsp;(isVisible:&nbsp;boolean)&nbsp;=&gt;&nbsp;void) | 导航栏显示状态切换时触发该回调。返回值isVisible为true时表示显示，为false时表示隐藏。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct NavigationExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State hideBar: boolean = true

  @Builder NavigationTitle() {
    Column() {
      Text('title')
        .width(80)
        .height(60)
        .fontColor(Color.Blue)
        .fontSize(30)
    }
    .onClick(() => {
      console.log("title")
    })
  }

  @Builder NavigationMenus() {
    Row() {
      Image('images/add.png')
        .width(25)
        .height(25)
      Image('comment/more.png')
        .width(25)
        .height(25)
        .margin({ left: 30 })
    }.width(100)
  }

  build() {
    Column() {
      Navigation() {
        Search({ value: '', placeholder: "" }).width('85%').margin(26)
        List({ space: 5, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('90%')
                .height(80)
                .backgroundColor('#3366CC')
                .borderRadius(15)
                .fontSize(16)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical)
        .height(300)
        .margin({ top: 10, left: 18 })
        .width('100%')

        Button(this.hideBar ? "tool bar" : "hide bar")
          .onClick(() => {
            this.hideBar = !this.hideBar
          })
          .margin({ left: 135, top: 60 })
      }
      .title(this.NavigationTitle)
      .subTitle('subtitle')
      .menus(this.NavigationMenus)
      .titleMode(NavigationTitleMode.Free)
      .hideTitleBar(false)
      .hideBackButton(false)
      .onTitleModeChange((titleModel: NavigationTitleMode) => {
        console.log('titleMode')
      })
      .toolBar({ items: [
        { value: 'app', icon: 'images/grid.svg', action: () => {
          console.log("app")
        } },
        { value: 'add', icon: 'images/add.svg', action: () => {
          console.log("add")
        } },
        { value: 'collect', icon: 'images/collect.svg', action: () => {
          console.log("collect")
        } }] })
      .hideToolBar(this.hideBar)
    }
  }
}
```

![zh-cn_image_0000001237616085](figures/zh-cn_image_0000001237616085.gif)

```ts
// xxx.ets
@Entry
@Component
struct ToolbarBuilderExample {
  @State currentIndex: number = 0
  @State Build: Array<Object> = [
    {
      icon: $r('app.media.ic_public_add'),
      icon_after: $r('app.media.ic_public_addcolor'),
      text: 'add',
      num: 0
    },
    {
      icon: $r('app.media.ic_public_app'),
      icon_after: $r('app.media.ic_public_appcolor'),
      text: 'app',
      num: 1
    },
    {
      icon: $r('app.media.ic_public_collect'),
      icon_after: $r('app.media.ic_public_collectcolor'),
      text: 'collect',
      num: 2
    }
  ]

  @Builder NavigationToolbar() {
    Row() {
      ForEach(this.Build, item => {
        Column() {
          Image(this.currentIndex == item.num ? item.icon_after : item.icon)
            .width(25)
            .height(25)
          Text(item.text)
            .fontColor(this.currentIndex == item.num ? "#ff7500" : "#000000")
        }
        .onClick(() => {
          this.currentIndex = item.num
        })
        .margin({ left: 70 })
      })
    }
  }

  build() {
    Column() {
      Navigation() {
        Flex() {
        }
      }
      .toolBar(this.NavigationToolbar)
    }
  }
}
```

![zh-cn_image_0000001192655288](figures/zh-cn_image_0000001192655288.gif)
