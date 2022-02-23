# SideBarContainer

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


侧边栏容器，分为侧边栏和内容区两部分，可单独添加子组件。


## 权限列表

无


## 子组件

可以包含两个子组件。
> ![](../../public_sys-resources/icon-note.gif) **说明：**
> 第一个子组件的类型必须为[Column](ts-container-column.md)，表示侧边栏，第二个子组件的类型必须为[RowSplit](ts-container-rowsplit.md)，表示内容区。



## 接口

SideBarContainer( type?: SideBarContainerType )

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | type | SideBarContainerType | 否 | SideBarContainerType.Embed | 设置侧边栏的显示类型。 | 

- SideBarContainerType枚举说明
  | 名称 | 描述 |
  | -------- | -------- |
  | Embed | 侧边栏嵌入到组件内，侧边栏和内容区并列显示。 |
  | Overlay | 侧边栏浮在内容区上面。 |

## 属性

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| showSideBar | boolean | true | 设置是否显示侧边栏。 |
| controlButton | ButtonStyle                                                | - | 设置侧边栏控制按钮的属性。 |
| showControlButton | boolean | true | 设置是否显示控制按钮。 |
| sidebarWidth | number | 200vp | 设置侧边栏的宽度。 |
| minSideBarWidth | number | 200vp | 设置侧边栏最小宽度。 |
| maxSideBarWidth | number | 280vp | 设置侧边栏最大宽度。 |

- ButtonStyle对象说明
  | 名称 | 参数类型 | 必填 | 默认值 | 描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | left | number | 否 | 16vp | 设置侧边栏控制按钮距离容器左界限的间距。 |
  | top | number | 否 | 48vp | 设置侧边栏控制按钮距离容器上界限的间距。 |
  | width | number | 否 | 32vp | 设置侧边栏控制按钮的宽度。 |
  | height | number | 否 | 32vp | 设置侧边栏控制按钮的高度。 |
  | icons | {<br/>shown:&nbsp;string \| PixelMap \| [Resource](../../ui/ts-types.md#resource类型) ,<br/>hidden:&nbsp;string \| PixelMap \| [Resource](../../ui/ts-types.md#resource类型) ,<br/>switching?:&nbsp;string \| PixelMap \| [Resource](../../ui/ts-types.md#resource类型) <br/>} | 否 | - | 设置侧边栏控制按钮的图标：<br/> </p> - shown: 设置侧边栏显示时控制按钮的图标。<br>- hidden: 设置侧边栏隐藏时控制按钮的图标。<br>- switching:设置侧边栏显示和隐藏状态切换时控制按钮的图标。 | 




## 事件

| 名称 | 功能描述 | 
| -------- | -------- |
| onChange(callback: (value: boolen) =&gt; void) | 当侧边栏的状态在显示和隐藏之间切换时触发回调。<p> value的true表示显示，false表示隐藏。|  


## 示例

```
@Entry
@Component
struct SideBarContainerExample {
  normalIcon : Resource = $r("app.media.user")
  selectedIcon: Resource = $r("app.media.userFull")
  @State arr: number[] = [1, 2, 3]
  @State current: number = 1

  build() {
    SideBarContainer({ type: SideBarContainerType.Embed })
    {
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
      RowSplit() {
        Column(){
          Text('Split page one').fontSize(30)
        }.justifyContent(FlexAlign.Center)
        Column(){
          Text('Split page two').fontSize(30)
        }.justifyContent(FlexAlign.Center)
      }.width('100%')
    }
    .sideBarWidth(240)
    .minSideBarWidth(210)
    .maxSideBarWidth(260)
    .onChange((value: boolean) => {
      console.info('status:' + value)
    })
  }
}
```
<img src="figures/sidebarcontainer.png" style="border: 1px solid black;" width="300" height="447" align="middle" />
