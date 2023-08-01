# SideBarContainer

提供侧边栏可以显示和隐藏的侧边栏容器，通过子组件定义侧边栏和内容区，第一个子组件表示侧边栏，第二个子组件表示内容区。

>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含子组件。

>  **说明：**
>
>  - 子组件类型：系统组件和自定义组件，不支持渲染控制类型（[if/else](../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../quick-start/arkts-rendering-control-foreach.md)和[LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)）。
>  - 子组件个数：必须且仅包含2个子组件。
>  - 子组件个数异常时：3个或以上子组件，显示第一个和第二个。1个子组件，显示侧边栏，内容区为空白。


## 接口

SideBarContainer( type?: SideBarContainerType )

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| type | SideBarContainerType | 否 | 设置侧边栏的显示类型。<br/>默认值：SideBarContainerType.Embed |

## SideBarContainerType枚举说明

| 名称 | 描述 |
| -------- | -------- |
| Embed | 侧边栏嵌入到组件内，和内容区并列显示。 |
| Overlay | 侧边栏浮在内容区上面。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| showSideBar | boolean | 设置是否显示侧边栏。<br/>默认值：true |
| controlButton | [ButtonStyle](#buttonstyle对象说明)                            | 设置侧边栏控制按钮的属性。 |
| showControlButton | boolean | 设置是否显示控制按钮。<br/>默认值：true |
| sideBarWidth | number&nbsp;\|&nbsp;Length<sup>9+</sup> | 设置侧边栏的宽度。<br/>默认值：200<br/>单位：vp<br/>**说明：** <br/>设置为小于0的值时按默认值显示。<br/>受最小宽度和最大宽度限制，不在限制区域内取最近的点。<br/>sideBarWidth优先于侧边栏子组件width，sideBarWidth未设置时默认值优先级高于侧边栏子组件width。 |
| minSideBarWidth | number&nbsp;\|&nbsp;Length<sup>9+</sup> | 设置侧边栏最小宽度。<br/>默认值：200，单位vp<br/>**说明：** <br/>设置为小于0的值时按默认值显示。<br/>值不能超过侧边栏容器本身宽度，超过使用侧边栏容器本身宽度。<br/>minSideBarWidth优先于侧边栏子组件minWidth，minSideBarWidth未设置时默认值优先级高于侧边栏子组件minWidth。 |
| maxSideBarWidth | number&nbsp;\|&nbsp;Length<sup>9+</sup> | 设置侧边栏最大宽度。<br/>默认值：280，单位vp<br/>**说明：** <br/>设置为小于0的值时按默认值显示。<br/>值不能超过侧边栏容器本身宽度，超过使用侧边栏容器本身宽度。<br/>maxSideBarWidth优先于侧边栏子组件maxWidth，maxSideBarWidth未设置时默认值优先级高于侧边栏子组件maxWidth。 |
| autoHide<sup>9+</sup> | boolean | 设置当侧边栏拖拽到小于最小宽度后，是否自动隐藏。<br/>默认值：true<br>**说明：** <br>受minSideBarWidth属性方法影响，minSideBarWidth属性方法未设置值使用默认值。<br/>拖拽过程中判断是否要自动隐藏。小于最小宽度时需要阻尼效果触发隐藏（越界一段距离） |
| sideBarPosition<sup>9+</sup> | SideBarPosition | 设置侧边栏显示位置。<br/>默认值：SideBarPosition.Start |

## ButtonStyle对象说明

| 名称 | 参数类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| left | number | 否 | 设置侧边栏控制按钮距离容器左界限的间距。<br/>默认值：16<br>单位：vp |
| top | number | 否 | 设置侧边栏控制按钮距离容器上界限的间距。<br/>默认值：48<br/>单位：vp |
| width | number | 否 | 设置侧边栏控制按钮的宽度。<br/>默认值：32<br/>单位：vp |
| height | number | 否 | 设置侧边栏控制按钮的高度。<br/>默认值：32<br/>单位：vp |
| icons | {<br/>shown:&nbsp;string \| PixelMap \| [Resource](ts-types.md) ,<br/>hidden:&nbsp;string \| PixelMap \| [Resource](ts-types.md) ,<br/>switching?:&nbsp;string \| PixelMap \| [Resource](ts-types.md) <br/>} | 否 | 设置侧边栏控制按钮的图标：<br/> </p> - shown: 设置侧边栏显示时控制按钮的图标。<br>**说明：** <br>资源获取错误时，使用默认图标。<br/>- hidden: 设置侧边栏隐藏时控制按钮的图标。<br>- switching:设置侧边栏显示和隐藏状态切换时控制按钮的图标。 |

## SideBarPosition<sup>9+</sup>枚举说明

| 名称 | 描述 |
| -------- | -------- |
| Start | 侧边栏位于容器左侧。 |
| End | 侧边栏位于容器右侧。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称 | 功能描述 |
| -------- | -------- |
| onChange(callback: (value: boolean) =&gt; void) | 当侧边栏的状态在显示和隐藏之间切换时触发回调。true表示显示，false表示隐藏。<br/>触发该事件的条件：<br>1、showSideBar属性值变换时；<br/>2、showSideBar属性自适应行为变化时；<br/>3、分割线拖拽触发autoHide时。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct SideBarContainerExample {
  normalIcon: Resource = $r("app.media.icon")
  selectedIcon: Resource = $r("app.media.icon")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1

  build() {
    SideBarContainer(SideBarContainerType.Embed) {
      Column() {
        ForEach(this.arr, (item, index) => {
          Column({ space: 5 }) {
            Image(this.current === item ? this.selectedIcon : this.normalIcon).width(64).height(64)
            Text("Index0" + item)
              .fontSize(25)
              .fontColor(this.current === item ? '#0A59F7' : '#999')
              .fontFamily('source-sans-pro,cursive,sans-serif')
          }
          .onClick(() => {
            this.current = item
          })
        }, item => item)
      }.width('100%')
      .justifyContent(FlexAlign.SpaceEvenly)
      .backgroundColor('#19000000')


      Column() {
        Text('SideBarContainer content text1').fontSize(25)
        Text('SideBarContainer content text2').fontSize(25)
      }
      .margin({ top: 50, left: 20, right: 30 })
    }
    .controlButton({
      icons: {
        hidden: $r('app.media.drawer'),
        shown: $r('app.media.drawer'),
        switching: $r('app.media.drawer')
      }
    })
    .sideBarWidth(150)
    .minSideBarWidth(50)
    .maxSideBarWidth(300)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
  }
}
```

![](figures/sidebarcontainer.png)
