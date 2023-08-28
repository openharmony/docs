# Tabs

通过页签进行内容视图切换的容器组件，每个页签对应一个内容视图。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

仅可包含子组件[TabContent](ts-container-tabcontent.md)。


## 接口

Tabs(value?: {barPosition?: BarPosition, index?: number, controller?: [TabsController](#tabscontroller)})

**参数：**

| 参数名         | 参数类型                              | 必填   | 参数描述                                     |
| ----------- | --------------------------------- | ---- | ---------------------------------------- |
| barPosition | [BarPosition](#barposition枚举说明)| 否    | 设置Tabs的页签位置。<br/>默认值：BarPosition.Start   |
| index       | number                            | 否    | 设置初始页签索引。<br/>默认值：0<br/>**说明：** <br/>设置为小于0的值时按默认值显示。<br/>可选值为[0, TabContent子节点数量-1]。<br/>设置不同值时，默认生效切换动效，可以设置animationDuration为0关闭动画。 |
| controller  | [TabsController](#tabscontroller) | 否    | 设置Tabs控制器。                               |

## BarPosition枚举说明

| 名称    | 描述                                       |
| ----- | ---------------------------------------- |
| Start | vertical属性方法设置为true时，页签位于容器左侧；vertical属性方法设置为false时，页签位于容器顶部。 |
| End   | vertical属性方法设置为true时，页签位于容器右侧；vertical属性方法设置为false时，页签位于容器底部。 |


## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称                | 参数类型                                    | 描述                                       |
| ----------------- | --------------------------------------- | ---------------------------------------- |
| vertical          | boolean                                 | 设置为false是为横向Tabs，设置为true时为纵向Tabs。<br/>默认值：false |
| scrollable        | boolean                                 | 设置为true时可以通过滑动页面进行页面切换，为false时不可滑动切换页面。<br/>默认值：true |
| barMode           | BarMode                                 | TabBar布局模式，具体描述见BarMode枚举说明。<br/>默认值：BarMode.Fixed |
| barWidth                 | number&nbsp;\|&nbsp;Length<sup>8+</sup>  | TabBar的宽度值。<br/>默认值：<br/>未设置带样式的TabBar且vertical属性为false时，默认值为Tabs的宽度。<br/>未设置带样式的TabBar且vertical属性为true时，默认值为56vp。<br/>设置SubTabbarStyle样式且vertical属性为false时，默认值为Tabs的宽度。<br/>设置SubTabbarStyle样式且vertical属性为true时，默认值为56vp。<br/>设置BottomTabbarStyle样式且vertical属性为true时，默认值为96vp。<br/>设置BottomTabbarStyle样式且vertical属性为false时，默认值为Tabs的宽度。<br/>**说明：** <br/>设置为小于0或大于Tabs宽度值时，按默认值显示。 |
| barHeight                | number&nbsp;\|&nbsp;Length<sup>8+</sup>  | TabBar的高度值。<br/>默认值：<br/>未设置带样式的TabBar且vertical属性为false时，默认值为56vp。<br/>未设置带样式的TabBar且vertical属性为true时，默认值为Tabs的高度。<br/>设置SubTabbarStyle样式且vertical属性为false时，默认值为56vp。<br/>设置SubTabbarStyle样式且vertical属性为true时，默认值为Tabs的高度。<br/>设置BottomTabbarStyle样式且vertical属性为true时，默认值为Tabs的高度。<br/>设置BottomTabbarStyle样式且vertical属性为false时，默认值为56vp。<br/>**说明：** <br/>设置为小于0或大于Tabs高度值时，按默认值显示。|
| animationDuration | number                                  | TabContent滑动动画时长。不设置时，点击切换页签无动画，滑动切换有动画；设置时，点击切换和滑动切换都有动画。<br/>默认值：300<br/>**说明：** <br/>设置为小于0或百分比时，按默认值显示。 |

## BarMode枚举说明

| 名称         | 描述                                       |
| ---------- | ---------------------------------------- |
| Scrollable | 每一个TabBar均使用实际布局宽度，超过总长度（横向Tabs的barWidth，纵向Tabs的barHeight）后可滑动。 |
| Fixed      | 所有TabBar平均分配barWidth宽度（纵向时平均分配barHeight高度）。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onChange(event:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;void) | Tab页签切换后触发的事件。<br>-&nbsp;index：当前显示的index索引，索引从0开始计算。<br/>触发该事件的条件：<br/>1、TabContent支持滑动时，组件触发滑动时触发。<br/>2、通过[控制器](#tabscontroller)API接口调用。<br/>3、通过[状态变量](../../quick-start/arkts-state.md)构造的属性值进行修改。<br/>4、通过页签处点击触发。 |

## TabsController

Tabs组件的控制器，用于控制Tabs组件进行页签切换。不支持一个TabsController控制多个Tabs组件。

### 导入对象

```ts
controller: TabsController = new TabsController()
```

### changeIndex

changeIndex(value: number): void

控制Tabs切换到指定页签。

**参数：**

| 参数名   | 参数类型   | 必填   | 参数描述                                     |
| ----- | ------ | ---- | ---------------------------------------- |
| value | number | 是    | 页签在Tabs里的索引值，索引值从0开始。<br/>**说明：** <br/>设置小于0或大于最大数量的值时，该事件失效。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct TabsExample {
  @State fontColor: string = '#182431'
  @State selectedFontColor: string = '#007DFF'
  @State currentIndex: number = 0
  private controller: TabsController = new TabsController()

  @Builder TabBuilder(index: number, name: string) {
    Column() {
      Text(name)
        .fontColor(this.currentIndex === index ? this.selectedFontColor : this.fontColor)
        .fontSize(16)
        .fontWeight(this.currentIndex === index ? 500 : 400)
        .lineHeight(22)
        .margin({ top: 17, bottom: 7 })
      Divider()
        .strokeWidth(2)
        .color('#007DFF')
        .opacity(this.currentIndex === index ? 1 : 0)
    }.width('100%')
  }

  build() {
    Column() {
      Tabs({ barPosition: BarPosition.Start, controller: this.controller }) {
        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#00CB87')
        }.tabBar(this.TabBuilder(0, 'green'))

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#007DFF')
        }.tabBar(this.TabBuilder(1, 'blue'))

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#FFBF00')
        }.tabBar(this.TabBuilder(2, 'yellow'))

        TabContent() {
          Column().width('100%').height('100%').backgroundColor('#E67C92')
        }.tabBar(this.TabBuilder(3, 'pink'))
      }
      .vertical(false)
      .barMode(BarMode.Fixed)
      .barWidth(360)
      .barHeight(56)
      .animationDuration(400)
      .onChange((index: number) => {
        this.currentIndex = index
      })
      .width(360)
      .height(296)
      .margin({ top: 52 })
      .backgroundColor('#F1F3F5')
    }.width('100%')
  }
}
```

![tabs2](figures/tabs2.gif)