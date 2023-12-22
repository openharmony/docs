# FolderStack

FolderStack继承于Stack(层叠布局)控件，新增了折叠屏悬停能力，通过识别upperItems自动避让折叠屏折痕区后移到上半屏

>  **说明：**
>
>  该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含多个子组件。


## 接口

FolderStack(value?: { upperItems?:  Array<string\>})

从API version 11开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名       | 参数类型                                    | 必填 | 参数描述                                                                 |
| ------------ | ------------------------------------------- | ---- |----------------------------------------------------------------------|
| upperItems |  Array<string\> | 否   | 定义悬停态会被移到上半屏的子组件的id，组件id在此数组中的子组件悬停触发时自动避让折叠屏折痕区后移到上半屏，其它组件堆叠在下半屏区域。 |



## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称              | 参数类型                                        | 描述                                                                                                                            |
|-----------------|---------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|
| alignContent    | [Alignment](ts-appendix-enums.md#alignment) | 设置子组件在容器内的对齐方式。<br/>默认值：Alignment.Center<br/>**说明：** <br/>该属性与[通用属性align](ts-universal-attributes-location.md)同时设置时，后设置的属性生效。 |
| enableAnimation | boolean                                     | 设置是否使用默认动效。<br/>默认值：true。                                                                                                     |
| autoHalfFold    | boolean                                     | 是否开启自动旋转。<br/>默认值：true。                                                                                                            |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称                                                                | 功能描述                                           |
|-------------------------------------------------------------------|------------------------------------------------|
| onFolderStateChange (callback: (foldStatus: [FoldStatus](ts-appendix-enums.md#foldstatus11) => void) | 当折叠状态改变的时候回调，<br/>-&nbsp;foldStatus:当前设备的折叠状态。 |

## 示例

```ts
@Entry
@Component
struct Index {
  @State len_wid: number = 480
  @State w: string = "40%"
  build() {
    Column() {
      // upperItems将所需要的悬停到上半屏的id放入upperItems传入，其余组件会堆叠在下半屏区域
      FolderStack({ upperItems: ["upperitemsId"] }) {
        // 此Column会自动上移到上半屏
        Column() {
          Text("vedio zone").height("100%").width("100%").textAlign(TextAlign.Center).fontSize(25)
        }.backgroundColor(Color.Pink).width("100%").height("100%").id("upperitemsId")

        // 下列两个Column堆叠在下半屏区域
        Column() {
          Text("vedio title")
            .width("100%")
            .height(50)
            .textAlign(TextAlign.Center)
            .backgroundColor(Color.Red)
            .fontSize(25)
        }.width("100%").height("100%").justifyContent(FlexAlign.Start)

        Column() {
          Text("vedie bar ")
            .width("100%")
            .height(50)
            .textAlign(TextAlign.Center)
            .backgroundColor(Color.Red)
            .fontSize(25)
        }.width("100%").height("100%").justifyContent(FlexAlign.End)
      }
      .backgroundColor(Color.Yellow)
      // 是否启动动效
      .enableAnimation(true)
      // 是否自动旋转
      .autoHalfFold(true)
      // folderStack回调 当折叠状态改变时回调
      .onFolderStateChange((msg) => {
        if (msg.foldStatus === FoldStatus.FOLD_STATUS_EXPANDED) {
          console.info("The device is currently in the expanded state")
        } else if (msg.foldStatus === FoldStatus.FOLD_STATUS_HALF_FOLDED) {
          console.info("The device is currently in the half folded state")
        } else {
          // .............
        }
      })
      // folderStack如果不撑满页面全屏，作为普通Stack使用
      .alignContent(Alignment.Bottom)
      .height("100%")
      .width("100%")
      .borderWidth(1)
      .backgroundColor(Color.Yellow)

    }
    .height("100%")
    .width("100%")
    .borderWidth(1)
    .backgroundColor(Color.Pink)
    .expandSafeArea([SafeAreaType.SYSTEM], [SafeAreaEdge.BOTTOM])

  }
}
```