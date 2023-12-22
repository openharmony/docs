# Navigation

Navigation组件是路由导航的根视图容器，一般作为Page页面的根容器使用，其内部默认包含了标题栏、内容区和工具栏，其中内容区默认首页显示导航内容（Navigation的子组件）或非首页显示（[NavDestination](ts-basic-components-navdestination.md)的子组件），首页和非首页通过路由进行切换。

> **说明：**
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含子组件。

从API Version 9开始，推荐与[NavRouter](ts-basic-components-navrouter.md)组件搭配使用。

从API Version 10开始，推荐使用[NavPathStack](#navpathstack10)配合navDestination属性进行页面路由。

## 接口

### Navigation

Navigation()

### Navigation<sup>10+</sup>

Navigation(pathInfos: NavPathStack)

绑定路由栈到Navigation组件。

**参数：**

| 参数名       | 参数类型                            | 必填   | 参数描述   |
| --------- | ------------------------------- | ---- | ------ |
| pathInfos | [NavPathStack](#navpathstack10) | 否    | 路由栈信息。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称                                 | 参数类型                                     | 描述                                       |
| ---------------------------------- | ---------------------------------------- | ---------------------------------------- |
| title                              | [ResourceStr](ts-types.md#resourcestr)<sup>10+</sup> \| [CustomBuilder](ts-types.md#custombuilder8) \| [NavigationCommonTitle](#navigationcommontitle类型说明)<sup>9+</sup> \| [NavigationCustomTitle](#navigationcustomtitle类型说明)<sup>9+</sup> | 页面标题。<br/>**说明：** <br/>使用NavigationCustomTitle类型设置height高度时，titleMode属性不会生效。<br/>字符串超长时，如果不设置副标题，先缩小再换行（2行）最后...截断。如果设置副标题，先缩小最后...截断。 |
| subTitle<sup>(deprecated)</sup>    | string                                   | 页面副标题。不设置时不显示副标题。从API Version 9开始废弃，建议使用title代替。 |
| menus                              | Array<[NavigationMenuItem](#navigationmenuitem类型说明)&gt; \| [CustomBuilder](ts-types.md#custombuilder8) | 页面右上角菜单。不设置时不显示菜单项。使用Array<[NavigationMenuItem](#navigationmenuitem类型说明)&gt; 写法时，竖屏最多支持显示3个图标，横屏最多支持显示5个图标，多余的图标会被放入自动生成的更多图标。 |
| titleMode                          | [NavigationTitleMode](#navigationtitlemode枚举说明) | 页面标题栏显示模式。<br/>默认值：NavigationTitleMode.Free |
| toolBar<sup>(deprecated)</sup>     | [object](#object类型说明) \| [CustomBuilder](ts-types.md#custombuilder8) | 设置工具栏内容。不设置时不显示工具栏。<br/>items: 工具栏所有项。<br/>**说明：** <br/>items均分底部工具栏，在每个均分内容区布局文本和图标，文本超长时，逐级缩小，缩小之后换行，最后...截断。<br/>从API version 10开始，该接口不再维护，推荐使用toolbarConfiguration代替。 |
| toolbarConfiguration<sup>10+</sup> | Array<[ToolbarItem](#toolbaritem10类型说明)&gt; \| [CustomBuilder](ts-types.md#custombuilder8) | 设置工具栏内容。不设置时不显示工具栏。<br/>**说明：** <br/>使用Array<[ToolbarItem](#ToolbarItem类型说明)>写法设置的工具栏有如下特性：<br/>工具栏所有选项均分底部工具栏，在每个均分内容区布局文本和图标。<br/>文本超长时，若工具栏选项个数小于5个，优先拓展选项的宽度，最大宽度与屏幕等宽，其次逐级缩小，缩小之后换行，最后...截断。<br/>竖屏最多支持显示5个图标，多余的图标会被放入自动生成的更多图标。横屏下必须配合menus属性的Array<[NavigationMenuItem](#navigationmenuitem类型说明)>使用，底部工具栏会自动隐藏，同时底部工具栏所有选项移动至页面右上角菜单。<br/>使用[CustomBuilder](ts-types.md#custombuilder8)写法为用户自定义工具栏选项，除均分底部工具栏外不具备以上功能。 |
| hideToolBar                        | boolean                                  | 隐藏工具栏。<br/>默认值：false<br/>true: 隐藏工具栏。<br/>false: 显示工具栏。 |
| hideTitleBar                       | boolean                                  | 隐藏标题栏。<br/>默认值：false<br/>true: 隐藏标题栏。<br/>false: 显示标题栏。 |
| hideBackButton                     | boolean                                  | 隐藏返回键。<br/>默认值：false<br/>true: 隐藏返回键。<br/>false: 显示返回键。 <br>不支持隐藏NavDestination组件标题栏中的返回图标。<br/>**说明：** <br/>返回键仅针对titleMode为NavigationTitleMode.Mini时才生效。 |
| navBarWidth<sup>9+</sup>           | [Length](ts-types.md#length)             | 导航栏宽度。<br/>默认值：240<br/>单位：vp<br/>**说明：** <br/>仅在Navigation组件分栏时生效。 |
| navBarPosition<sup>9+</sup>        | [NavBarPosition](#navbarposition枚举说明)    | 导航栏位置。<br/>默认值：NavBarPosition.Start<br/>**说明：** <br/>仅在Navigation组件分栏时生效。 |
| mode<sup>9+</sup>                  | [NavigationMode](#navigationmode枚举说明)    | 导航栏的显示模式。<br/>默认值：NavigationMode.Auto<br/>自适应：基于组件宽度自适应单栏和双栏。<br/>**说明：** <br/>支持Stack、Split与Auto模式。 |
| backButtonIcon<sup>9+</sup>        | string \| [PixelMap](../apis/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md#resource) | 设置导航栏返回图标。不支持隐藏NavDestination组件标题栏中的返回图标。 |
| hideNavBar<sup>9+</sup>            | boolean                                  | 是否显示导航栏。 |
| navDestination<sup>10+</sup>       | builder: (name: string, param: unknown) => void | 创建NavDestination组件。<br/>**说明：** <br/>使用builder函数，基于name和param构造NavDestination组件。builder中允许在NavDestination组件外包含一层自定义组件， 但自定义组件不允许设置属性和事件，否则仅显示空白。 |
| navBarWidthRange<sup>10+</sup>     | [[Dimension](ts-types.md#dimension10), [Dimension](ts-types.md#dimension10)] | 导航栏最小和最大宽度（双栏模式下生效）。<br/>默认值：最小默认值 240，最大默认值为组件宽度的40% ，且不大于 432。<br/>单位：vp<br/>规则：<br/>开发者设置优先级 > 默认值<br/>最小值优先级 > 最大值<br/>navBar 优先级 > content优先级<br/>开发者设置多个值冲突，以全局数值优先，局部最小值跟随容器大小。 |
| minContentWidth<sup>10+</sup>      | [Dimension](ts-types.md#dimension10)     | 导航栏内容区最小宽度（双栏模式下生效）。<br/>默认值：360<br/>单位：vp<br/>规则：<br/>开发者设置优先级 > 默认值<br/>最小值优先级 > 最大值<br/>navBar优先级 > content优先级<br/>开发者设置多个值冲突，以全局数值优先，局部最小值跟随容器大小。<br/>Auto模式断点计算：默认600vp，minNavBarWidth(240vp) + minContentWidth (360vp) |

## 事件

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onTitleModeChange(callback: (titleMode: NavigationTitleMode) =&gt; void) | 当titleMode为NavigationTitleMode.Free时，随着可滚动组件的滑动标题栏模式发生变化时触发此回调。 |
| onNavBarStateChange(callback: (isVisible: boolean) =&gt; void) | 导航栏显示状态切换时触发该回调。返回值isVisible为true时表示显示，为false时表示隐藏。 |

## NavPathStack<sup>10+</sup>

Navigation路由栈。

### pushPath<sup>10+</sup>

pushPath(info: NavPathInfo): void

将info指定的NavDestination页面信息入栈。

**参数：**

| 名称   | 类型                            | 必填   | 描述                   |
| ---- | ----------------------------- | ---- | -------------------- |
| info | [NavPathInfo](#navpathinfo10) | 是    | NavDestination页面的信息。 |

### pushPathByName<sup>10+</sup>

pushPathByName(name: string, param: unknown): void

将name指定的NavDestination页面信息入栈，传递的数据为param。

**参数：**

| 名称    | 类型      | 必填   | 描述                    |
| ----- | ------- | ---- | --------------------- |
| name  | string  | 是    | NavDestination页面名称。   |
| param | unknown | 是    | NavDestination页面详细参数。 |

### pop<sup>10+</sup>

pop(): NavPathInfo | undefined

弹出路由栈栈顶元素。

**返回值：**

| 类型          | 说明                       |
| ----------- | ------------------------ |
| NavPathInfo | 返回栈顶NavDestination页面的信息。 |
| undefined   | 当路由栈为空时返回undefined。      |

### popToName<sup>10+</sup>

popToName(name: string): number

回退路由栈到第一个名为name的NavDestination页面。

**参数：**

| 名称   | 类型     | 必填   | 描述                  |
| ---- | ------ | ---- | ------------------- |
| name | string | 是    | NavDestination页面名称。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 如果栈中存在名为name的NavDestination页面，则返回第一个名为name的NavDestination页面的索引，否则返回-1。 |

### popToIndex<sup>10+</sup>

popToIndex(index: number): void

回退路由栈到index指定的NavDestination页面。

**参数：**

| 名称    | 类型     | 必填   | 描述                     |
| ----- | ------ | ---- | ---------------------- |
| index | number | 是    | NavDestination页面的位置索引。 |

### moveToTop<sup>10+</sup>

moveToTop(name: string): number

将第一个名为name的NavDestination页面移到栈顶。

**参数：**

| 名称   | 类型     | 必填   | 描述                  |
| ---- | ------ | ---- | ------------------- |
| name | string | 是    | NavDestination页面名称。 |

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 如果栈中存在名为name的NavDestination页面，则返回第一个名为name的NavDestination页面的当前索引，否则返回-1。 |

### moveIndexToTop<sup>10+</sup>

moveIndexToTop(index: number): void

将index指定的NavDestination页面移到栈顶。

**参数：**

| 名称    | 类型     | 必填   | 描述                     |
| ----- | ------ | ---- | ---------------------- |
| index | number | 是    | NavDestination页面的位置索引。 |

### clear<sup>10+</sup>

clear(): void

清除栈中所有页面。

### getAllPathName<sup>10+</sup>

getAllPathName(): Array<string\>

获取栈中所有NavDestination页面的名称。

**返回值：**

| 类型             | 说明                         |
| -------------- | -------------------------- |
| Array<string\> | 返回栈中所有NavDestination页面的名称。 |

### getParamByIndex<sup>10+</sup>

getParamByIndex(index: number): unknown | undefined

获取index指定的NavDestination页面的参数信息。

**参数：**

| 名称    | 类型     | 必填   | 描述                     |
| ----- | ------ | ---- | ---------------------- |
| index | number | 是    | NavDestination页面的位置索引。 |

**返回值：**

| 类型        | 说明                         |
| --------- | -------------------------- |
| unknown   | 返回对应NavDestination页面的参数信息。 |
| undefined | 传入index无效时返回undefined。     |

### getParamByName<sup>10+</sup>

getParamByName(name: string): Array<unknown\>

获取全部名为name的NavDestination页面的参数信息。

**参数：**

| 名称   | 类型     | 必填   | 描述                  |
| ---- | ------ | ---- | ------------------- |
| name | string | 是    | NavDestination页面名称。 |

**返回值：**

| 类型              | 说明                                |
| --------------- | --------------------------------- |
| Array<unknown\> | 返回全部名为name的NavDestination页面的参数信息。 |

### getIndexByName<sup>10+</sup>

getIndexByName(name: string): Array<number\>

获取全部名为name的NavDestination页面的位置索引。

**参数：**

| 名称   | 类型     | 必填   | 描述                  |
| ---- | ------ | ---- | ------------------- |
| name | string | 是    | NavDestination页面名称。 |

**返回值：**

| 类型             | 说明                                |
| -------------- | --------------------------------- |
| Array<number\> | 返回全部名为name的NavDestination页面的位置索引。 |

### size<sup>10+</sup>

size(): number

获取栈大小。

**返回值：**

| 类型     | 说明     |
| ------ | ------ |
| number | 返回栈大小。 |

## NavPathInfo<sup>10+</sup>

路由页面信息。

### constructor

constructor(name: string, param: unknown)

**参数：**

| 名称    | 类型      | 必填   | 描述                    |
| ----- | ------- | ---- | --------------------- |
| name  | string  | 是    | NavDestination页面名称。   |
| param | unknown | 否    | NavDestination页面详细参数。 |

## NavigationMenuItem类型说明

| 名称     | 类型            | 必填   | 描述              |
| ------ | ------------- | ---- | --------------- |
| value  | string        | 是    | API Version 9: 显示菜单栏单个选项的文本。<br> API Version 10: 不显示菜单栏单个选项的文本。  |
| icon   | string        | 否    | 菜单栏单个选项的图标资源路径。 |
| action | () =&gt; void | 否    | 当前选项被选中的事件回调。   |

## object类型说明

| 名称     | 类型            | 必填   | 描述              |
| ------ | ------------- | ---- | --------------- |
| value  | string        | 是    | 工具栏单个选项的显示文本。   |
| icon   | string        | 否    | 工具栏单个选项的图标资源路径。 |
| action | () =&gt; void | 否    | 当前选项被选中的事件回调。   |

## ToolbarItem<sup>10+</sup>类型说明

| 名称         | 类型                                       | 必填   | 描述                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value      | ResourceStr                              | 是    | 工具栏单个选项的显示文本。                            |
| icon       | ResourceStr                              | 否    | 工具栏单个选项的图标资源路径。                          |
| action     | () =&gt; void                            | 否    | 当前选项被选中的事件回调。                            |
| status     | [ToolbarItemStatus](#toolbaritemstatus10枚举说明) | 否    | 工具栏单个选项的状态。<br/>默认值：ToolbarItemStatus.NORMAL |
| activeIcon | ResourceStr                              | 否    | 工具栏单个选项处于ACTIVE态时的图标资源路径。                |

## ToolbarItemStatus<sup>10+</sup>枚举说明

| 名称       | 描述                                       |
| -------- | ---------------------------------------- |
| NORMAL   | 设置工具栏单个选项为NORMAL态，该选项显示默认样式，可以触发Hover，Press，Focus事件并显示对应的多态样式。 |
| DISABLED | 设置工具栏单个选项为DISABLED态， 该选项显示DISABLED态样式，并且不可交互。 |
| ACTIVE   | 设置工具栏单个选项为ACTIVE态， 该选项通过点击事件可以将icon图标更新为activeIcon对应的图片资源。 |

## NavigationTitleMode枚举说明

| 名称   | 描述                                       |
| ---- | ---------------------------------------- |
| Free | 当内容为可滚动组件时，标题随着内容向上滚动而缩小（子标题的大小不变、淡出）。向下滚动内容到顶时则恢复原样。<br/>**说明：** <br/>标题随着内容滚动大小联动的动效在title设置为ResourceStr和NavigationCommonTitle时生效，设置成其余自定义节点类型时字体样式无法变化，下拉时只影响标题栏偏移。 |
| Mini | 固定为小标题模式。                                |
| Full | 固定为大标题模式。                                |

## NavigationCommonTitle类型说明

| 名称   | 类型     | 必填   | 描述     |
| ---- | ------ | ---- | ------ |
| main | string | 是    | 设置主标题。 |
| sub  | string | 是    | 设置副标题。 |

## NavigationCustomTitle类型说明

| 名称      | 类型                                       | 必填   | 描述       |
| ------- | ---------------------------------------- | ---- | -------- |
| builder | [CustomBuilder](ts-types.md#custombuilder8) | 是    | 设置标题栏内容。 |
| height  | [TitleHeight](#titleheight枚举说明) \| [Length](ts-types.md#length) | 是    | 设置标题栏高度。 |

## NavBarPosition枚举说明

| 名称    | 描述               |
| ----- | ---------------- |
| Start | 双栏显示时，主列在主轴方向首部。 |
| End   | 双栏显示时，主列在主轴方向尾部。 |

## NavigationMode枚举说明

| 名称  | 描述                                                         |
| ----- | ------------------------------------------------------------ |
| Stack | 导航栏与内容区独立显示，相当于两个页面。                     |
| Split | 导航栏与内容区分两栏显示。<br/>以下navBarWidthRange的值用[minNavBarWidth,maxNavBarWidth]表示<br/>1.当navBarWidth属性的值，在navBarWidthRange属性的值范围以外时，navBarWidth按如下规则显示：<br/>navBarWidth < minNavBarWidth时，navBarWidth修正为minNavBarWidth;<br/>navBarWidth > maxNavBarWidth，且组件宽度 - minContentWidth - 分割线宽度(1vp)大于maxNavBarWidth时，navBarWidth修正为maxNavBarWidth;<br/>navBarWidth > maxNavBarWidth，且组件宽度 - minContentWidth - 分割线宽度(1vp)小于minNavBarWidth时，navBarWidth修正为minNavBarWidth;<br/>navBarWidth > maxNavBarWidth，且组件宽度 - minContentWidth - 分割线宽度(1vp)在navBarWidthRange范围内，navBarWidth修正为组件宽度 - 分割线宽度(1vp) - minContentWidth。<br/>2.当navBarWidth属性的值，在navBarWidthRange属性的值范围以内时，navBarWidth按如下规则显示：<br/>minNavBarWidth + minContentWidth + 分割线宽度(1vp) >= 组件宽度时，navBarWidth修正为minNavBarWidth；<br/>minNavBarWidth + minContentWidth + 分割线宽度(1vp) < 组件宽度，且navBarWidth + minContentWidth + 分割线宽度(1vp) >= 组件宽度时，navBarWidth修正为组件宽度 - 分割线宽度(1vp) - minContentWidth;<br/>minNavBarWidth + minContentWidth + 分割线宽度(1vp) < 组件宽度，且navBarWidth + minContentWidth + 分割线宽度(1vp) < 组件宽度时，navBarWidth为设置的值。<br/>3.缩小组件尺寸时，先缩小内容区的尺寸至minContentWidth，然后再缩小导航栏的尺寸至minNavBarWidth。若继续缩小，先缩小内容区，内容区消失后再缩小导航栏。<br/>4.设置导航栏为固定尺寸时，若持续缩小组件尺寸，导航栏最后压缩显示。<br/>5.若只设置了navBarWidth属性，则导航栏宽度为navBarWidth，且分割线不可拖动。 |
| Auto  | API version 9之前：窗口宽度>=520vp时，采用Split模式显示；窗口宽度<520vp时，采用Stack模式显示。<br/>API version 10及以上：窗口宽度>=600vp时，采用Split模式显示；窗口宽度<600vp时，采用Stack模式显示，600vp等于minNavBarWidth(240vp) + minContentWidth (360vp)。 |

## TitleHeight枚举说明

| 名称          | 描述                         |
| ----------- | -------------------------- |
| MainOnly    | 只有主标题时标题栏的推荐高度（56vp）。      |
| MainWithSub | 同时有主标题和副标题时标题栏的推荐高度（82vp）。 |


>  **说明：**
>
>  目前可滚动组件只支持List。


## 示例

### 示例1

```ts
// xxx.ets
class A {
  text: string = ''
  num: number = 0
}

@Entry
@Component
struct NavigationExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State currentIndex: number = 0

  @Builder NavigationTitle() {
    Column() {
      Text('Title')
        .fontColor('#182431')
        .fontSize(30)
        .lineHeight(41)
        .fontWeight(700)
      Text('subtitle')
        .fontColor('#182431')
        .fontSize(14)
        .lineHeight(19)
        .opacity(0.4)
        .margin({ top: 2, bottom: 20 })
    }.alignItems(HorizontalAlign.Start)
  }

  @Builder NavigationMenus() {
    Row() {
      Image('common/ic_public_add.svg')
        .width(24)
        .height(24)
      Image('common/ic_public_add.svg')
        .width(24)
        .height(24)
        .margin({ left: 24 })
      Image('common/ic_public_more.svg')
        .width(24)
        .height(24)
        .margin({ left: 24 })
    }
  }

  build() {
    Column() {
      Navigation() {
        TextInput({ placeholder: 'search...' })
          .width('90%')
          .height(40)
          .backgroundColor('#FFFFFF')
          .margin({ top: 8 })

        List({ space: 12, initialIndex: 0 }) {
          ForEach(this.arr, (item: number) => {
            ListItem() {
              Text('' + item)
                .width('90%')
                .height(72)
                .backgroundColor('#FFFFFF')
                .borderRadius(24)
                .fontSize(16)
                .fontWeight(500)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, (item: number) => item.toString())
        }
        .height(324)
        .width('100%')
        .margin({ top: 12, left: '10%' })
      }
      .title(this.NavigationTitle)
      .menus(this.NavigationMenus)
      .titleMode(NavigationTitleMode.Full)
      .toolbarConfiguration([
        {
          value: $r("app.string.navigation_toolbar_add"),
          icon: $r("app.media.ic_public_highlightsed")
        },
        {
          value: $r("app.string.navigation_toolbar_app"),
          icon: $r("app.media.ic_public_highlights")
        },
        {
          value: $r("app.string.navigation_toolbar_collect"),
          icon: $r("app.media.ic_public_highlights")
        }
      ])
      .hideTitleBar(false)
      .hideToolBar(false)
      .onTitleModeChange((titleModel: NavigationTitleMode) => {
        console.info('titleMode' + titleModel)
      })
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![zh-cn_image_navigation](figures/zh-cn_image_navigation.png)



### 示例2
```ts
// Index.ets
import { pageOneTmp } from './pageOne'
import { pageTwoTmp } from './pageTwo'
import { pages }  from './pageTwo'

@Entry
@Component
struct NavigationExample {
  @Provide('pageInfos') pageInfos: NavPathStack = new NavPathStack()

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      pageOneTmp()
    } else if (name === 'pageTwo') {
      pageTwoTmp({ names: name, values: this.pageInfos } as pages)
    }
  }

  build() {
    Navigation(this.pageInfos) {
      Column() {
        Button('pushPath', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.pushPath({ name: 'pageOne' }) //将name指定的NavDestination页面信息入栈
          })
      }
    }.title('NavIndex').navDestination(this.PageMap)
  }
}
```
```ts
// pageOne.ets
class tmpClass{
  count:number=10
}
@Component
export struct pageOneTmp {
  @Consume('pageInfos') pageInfos: NavPathStack;

  build() {
    NavDestination() {
      Column() {
        Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            let tmp = new tmpClass()
            this.pageInfos.pushPathByName('pageTwo', tmp) //将name指定的NavDestination页面信息入栈，传递的数据为param
          })
        Button('popToname', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.popToName('pageTwo') //回退路由栈到第一个名为name的NavDestination页面
            console.log('popToName' + JSON.stringify(this.pageInfos), '返回值' + JSON.stringify(this.pageInfos.popToName('pageTwo')))
          })
        Button('popToIndex', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.popToIndex(1) // 回退路由栈到index指定的NavDestination页面
            console.log('popToIndex' + JSON.stringify(this.pageInfos))
          })
        Button('moveToTop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.moveToTop('pageTwo') // 将第一个名为name的NavDestination页面移到栈顶
            console.log('moveToTop' + JSON.stringify(this.pageInfos), '返回值' + JSON.stringify(this.pageInfos.moveToTop('pageTwo')))
          })
        Button('moveIndexToTop', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.moveIndexToTop(1) // 将index指定的NavDestination页面移到栈顶
            console.log('moveIndexToTop' + JSON.stringify(this.pageInfos))
          })
        Button('clear', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfos.clear() //清除栈中所有页面
          })
        Button('get', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            console.log('-------------------')
            console.log('获取栈中所有NavDestination页面的名称', JSON.stringify(this.pageInfos.getAllPathName()))
            console.log('获取index指定的NavDestination页面的参数信息', JSON.stringify(this.pageInfos.getParamByIndex(1)))
            console.log('获取全部名为name的NavDestination页面的参数信息', JSON.stringify(this.pageInfos.getParamByName('pageTwo')))
            console.log('获取全部名为name的NavDestination页面的位置索引', JSON.stringify(this.pageInfos.getIndexByName('pageOne')))
            console.log('获取栈大小', JSON.stringify(this.pageInfos.size()))
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfos.pop() // 弹出路由栈栈顶元素
      console.log('pop' + '返回值' + JSON.stringify(this.pageInfos.pop()))
      return true
    })
  }
}
```
```ts
// pageTwo.ets

export class pages {
  names: string = ""
  values: NavPathStack | null = null
}

@Builder
export function pageTwoTmp(info: pages) {
  NavDestination() {
    Column() {
      Button('pushPathByName', { stateEffect: true, type: ButtonType.Capsule })
        .width('80%')
        .height(40)
        .margin(20)
        .onClick(() => {
          (info.values as NavPathStack).pushPathByName('pageOne', null)
        })
    }.width('100%').height('100%')
  }.title('pageTwo')
  .onBackPressed(() => {
    (info.values as NavPathStack).pop()
    return true
  })
}
```
![navigation.gif](figures/navigation.gif)