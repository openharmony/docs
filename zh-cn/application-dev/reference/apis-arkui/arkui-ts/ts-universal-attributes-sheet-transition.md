# 半模态转场

通过bindSheet属性为组件绑定半模态页面，在组件插入时可通过设置自定义或默认的内置高度确定半模态大小。

>  **说明：**
>
>  从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  不支持路由跳转。

## bindSheet

bindSheet(isShow: boolean, builder: CustomBuilder, options?: SheetOptions)

给组件绑定半模态页面，点击后显示模态页面。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                        | 必填 | 说明                                                         |
| ------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| isShow  | boolean                                     | 是   | 是否显示半模态页面。<br/>从API version 10开始，该参数支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |
| builder | [CustomBuilder](ts-types.md#custombuilder8) | 是   | 配置半模态页面内容。                                         |
| options | [SheetOptions](#sheetoptions)               | 否   | 配置半模态页面的可选属性。                                   |

> **说明：**
>
> 在非双向绑定情况下，以拖拽方式关闭半模态页面不会改变isShow参数的值。
>
> 为了使isShow参数值与半模态界面的状态同步，建议使用[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定isShow参数。
## SheetOptions

继承自[BindOptions](#bindoptions)。

| 名称              | 类型                                       | 必填   | 描述              |
| --------------- | ---------------------------------------- | ---- | --------------- |
| height          | [SheetSize](#sheetsize枚举说明)&nbsp;\|&nbsp;[Length](ts-types.md#length) | 否    | 半模态高度，默认是LARGE。<br/>**说明：**<br/>底部弹窗竖屏时，当设置detents时，该属性设置无效。<br/>底部弹窗竖屏时，最大高度为距离信号栏8vp。<br />底部弹窗横屏时，该属性设置无效，高度为距离屏幕顶部8vp。<br/>居中弹窗和跟手弹窗设置类型为SheetSize.LARGE和SheetSize.MUDIUM无效，显示默认高度560vp。居中弹窗和跟手弹窗最小高度为320vp，最大高度为窗口短边的90%。当使用Length设置的高度和使用SheetSize.FIT_CONTENT自适应的高度大于最大高度，则显示最大高度，小于最小高度，则显示最小高度。<br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| detents<sup>11+</sup> | [([SheetSize](#sheetsize枚举说明) \| [Length](ts-types.md#length)), ( [SheetSize](#sheetsize枚举说明) \| [Length](ts-types.md#length))?, ([SheetSize](#sheetsize枚举说明) \| [Length](ts-types.md#length))?] | 否 | 半模态页面的切换高度档位。<br/>**说明：**<br/>底部弹窗竖屏生效，元组中第一个高度为初始高度。<br />面板可跟手滑动切换档位，松手后是否滑动至目标档位有两个判断条件：速度和距离。速度超过阈值，则执行滑动至与手速方向一致的目标档位；速度小于阈值，则引入距离判断条件，当位移距离>当前位置与目标位置的1/2，滑动至与手速方向一致的目标档位，位移距离当前位置与目标位置的1/2，返回至当前档位。速度阈值：1000，距离阈值：50%。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| preferType<sup>11+</sup> | [SheetType.CENTER](#sheettype11枚举说明) \|  [SheetType.POPUP](#sheettype11枚举说明) | 否 | 半模态页面的样式。<br/>**说明：**<br/>preferType不可设置为SheetType.BOTTOM。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| showClose<sup>11+</sup> | boolean \| [Resource](ts-types.md#resource) | 否 | 是否显示关闭图标，默认显示。<br/>**说明：**<br/>Resource需要为boolean类型。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| dragBar         | boolean                                  | 否    | 是否显示控制条。<br/>**说明：**<br/>半模态面板的dentents属性设置多个不同高度并且设置生效时，默认显示控制条。否则不显示控制条。<br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| blurStyle<sup>11+</sup> | [BlurStyle](ts-appendix-enums.md#blurstyle9) | 否 | 半模态面板的模糊背景。默认无模糊背景。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| maskColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 半模态页面的背景蒙层颜色。<br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| title<sup>11+</sup> | [SheetTitleOptions](#sheettitleoptions11) \| [CustomBuilder](ts-types.md#custombuilder8) | 否 | 半模态面板的标题。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| enableOutsideInteractive<sup>11+</sup> | boolean | 否 | 半模态所在页面是否允许交互。<br/>**说明：**<br/>设置为true时允许交互，不显示蒙层；设置为false时不允许交互，显示蒙层；若不进行设置，默认底部弹窗与居中弹窗不允许交互，跟手弹窗允许交互。当设置为true时，maskColor设置无效。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| shouldDismiss<sup>11+</sup> | (sheetDismiss: [SheetDismiss](#sheetdismiss11)) => void | 否 | 半模态页面交互式关闭回调函数。<br/>**说明：**<br/>当用户执行下拉关闭/back事件/点击蒙层关闭/关闭按钮关闭交互操作时，如果注册该回调函数，则不会立刻关闭。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| onHeightDidChange<sup>12+</sup> | Callback&lt;number&gt; | 否 | 半模态页面高度变化回调函数。<br/>**说明：**<br/>底部弹窗时，只有档位变化和拖拽跟手才返回每一帧高度，拉起半模态和避让软键盘只返回最后的高度，其他弹窗只在半模态拉起返回最后高度。<br/>返回值为px。 |
| onDetentsDidChange<sup>12+</sup> | Callback&lt;number&gt; | 否 | 半模态页面档位变化回调函数。<br/>**说明：**<br/>底部弹窗时，档位变化返回最后的高度。<br/>返回值为px。 |
| borderWidth<sup>12+</sup> | [Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;[EdgeWidths](ts-types.md#edgewidths9)&nbsp;\|&nbsp;[LocalizedEdgeWidths](ts-types.md#localizededgewidths12)<sup>12+</sup>  | 否 | 设置半模态页面的边框宽度。<br />可分别设置4个边框宽度。<br />默认值：0。<br /> 百分比参数方式：以父元素半模态页面宽的百分比来设置半模态页面的边框宽度。<br />当半模态页面左边框和右边框大于半模态页面宽度，半模态页面上边框和下边框大于半模态页面高度，显示可能不符合预期。<br />**说明：**<br />底部弹窗时，底部边框宽度设置无效。 |
| borderColor<sup>12+</sup> | [ResourceColor](ts-types.md#resourcecolor)&nbsp;\|&nbsp;[EdgeColors](ts-types.md#edgecolors9)&nbsp;\|&nbsp;[LocalizedEdgeColors](ts-types.md#localizededgecolors12)<sup>12+</sup>  | 否 | 设置半模态页面的边框颜色。<br/>默认值：Color.Black。<br/> 如果使用borderColor属性，需要和borderWidth属性一起使用。 <br />**说明：**<br />底部弹窗时，底部边框颜色设置无效。 |
| borderStyle<sup>12+</sup> | [BorderStyle](ts-appendix-enums.md#borderstyle)&nbsp;\|&nbsp;[EdgeStyles](ts-types.md#edgestyles9)  | 否 | 设置半模态页面的边框样式。<br/>默认值：BorderStyle.Solid。<br/> 如果使用borderStyle属性，需要和borderWidth属性一起使用。 <br />**说明：**<br />底部弹窗时，底部边框样式设置无效。 |
| width<sup>12+</sup> | [Dimension](ts-types.md#dimension10)   | 否 | 设置半模态页面的宽度。<br /> 百分比参数方式：以父元素宽的百分比来设置半模态页面的宽度。|
| shadow<sup>12+</sup> | [ShadowOptions](ts-universal-attributes-image-effect.md#shadowoptions对象说明)&nbsp;\|&nbsp;[ShadowStyle](ts-universal-attributes-image-effect.md#shadowstyle10枚举说明)   | 否 | 设置半模态页面的阴影。 |
| uiContext<sup>12+</sup> | [UIContext](../js-apis-arkui-UIContext.md#uicontext)   | 否 | 在UIContext实例对应的窗口中显示半模态。|
| mode<sup>12+</sup> | [SheetMode](#sheetmode12)   | 否 | 设置半模态页面的显示层级。<br/>默认值：SheetMode.OVERLAY。|

## SheetSize枚举说明

| 名称                      | 值    | 参数描述                         |
| ------------------------- | ---- | -------------------------------- |
| MEDIUM                    | 0    | 指定半模态高度为屏幕高度一半。<br />**元服务API：** 从API version 11开始，该接口支持在元服务中使用。   |
| LARGE                     | 1    | 指定半模态高度几乎为屏幕高度。<br />**元服务API：** 从API version 11开始，该接口支持在元服务中使用。   |
| FIT_CONTENT<sup>11+</sup> | 2    | 指定半模态高度为适应内容的高度。<br />**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |

## BindOptions

| 名称            | 类型                                       | 必填 | 说明                     |
| --------------- | ------------------------------------------ | ---- | ------------------------ |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 否   | 半模态页面的背板颜色。<br />**元服务API：** 从API version 11开始，该接口支持在元服务中使用。   |
| onWillAppear<sup>12+</sup>        | () => void                                 | 否   | 半模态页面显示（动画开始前）回调函数。 |
| onAppear        | () => void                                 | 否   | 半模态页面显示（动画结束后）回调函数。<br />**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| onWillDisappear<sup>12+</sup>     | () => void                                 | 否   | 半模态页面回退（动画开始前）回调函数。<br />**说明：**<br />不允许在onWillDisappear函数中修改状态变量，可能会导致组件行为不稳定。 |
| onDisappear     | () => void                                 | 否   | 半模态页面回退（动画结束后）回调函数。<br />**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |

## SheetType<sup>11+</sup>枚举说明

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称   | 值    | 参数描述                                               |
| ------ | ---- | ------------------------------------------------------- |
| BOTTOM | 0    | 底部弹窗。                                             |
| CENTER | 1    | 居中弹窗。                                             |
| POPUP  | 2    | 跟手弹窗。跟手弹窗面板不支持跟手滑动，下滑面板不关闭。 |

## SheetDismiss<sup>11+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称    | 类型       | 必填 | 描述                                                         |
| ------- | ---------- | ---- | ------------------------------------------------------------ |
| dismiss | () => void | 是   | 半模态面板关闭回调函数。开发者需要退出时调用，不需要退出时无需调用。 |

## SheetTitleOptions<sup>11+</sup>

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称     | 类型                                   | 必填 | 描述                 |
| -------- | -------------------------------------- | ---- | -------------------- |
| title    | [ResourceStr](ts-types.md#resourcestr) | 是   | 半模态面板的主标题。 |
| subtitle | [ResourceStr](ts-types.md#resourcestr) | 否   | 半模态面板的副标题。 |

## SheetMode<sup>12+</sup>
| 名称                      | 值    | 参数描述                         |
| ------------------------- | ---- | -------------------------------- |
| OVERLAY                   | 0    | 设置半模态面板在当前UIContext内顶层显示，在所有页面之上。和弹窗类组件显示在一个层级。   |
| EMBEDDED                  | 1    | 设置半模态面板在当前页面内的顶层显示。 <br />**说明：**<br />目前只支持挂载在Page节点上，只支持在Page页面内顶层显示。<br /> 该模式下新起的页面可以覆盖在半模态弹窗上，页面返回后该半模态依旧存在，半模态面板内容不丢失。 <br /> 该模式下需确保页面节点如Page节点已挂树，再拉起半模态，否则半模态无法挂载到对应的页面节点内。|

## 示例
### 示例1

```ts
// xxx.ets
@Entry
@Component
struct SheetTransitionExample {
  @State isShow:boolean = false
  @State isShow2:boolean = false
  @State sheetHeight:number = 300;

  @Builder myBuilder() {
    Column() {
      Button("change height")
        .margin(10)
        .fontSize(20)
        .onClick(()=>{
          this.sheetHeight = 500;
        })

      Button("Set Illegal height")
        .margin(10)
        .fontSize(20)
        .onClick(()=>{
          this.sheetHeight = -1;
        })

      Button("close modal 1")
        .margin(10)
        .fontSize(20)
        .onClick(()=>{
          this.isShow = false;
        })
    }
    .width('100%')
    .height('100%')
  }

  build() {
    Column() {
      Button("transition modal 1")
        .onClick(() => {
          this.isShow = true
        })
        .fontSize(20)
        .margin(10)
        .bindSheet($$this.isShow, this.myBuilder(), {
          height: this.sheetHeight, 
          backgroundColor: Color.Green,
          onWillAppear: () => {console.log("BindSheet onWillAppear.")}, 
          onAppear: () => {console.log("BindSheet onAppear.")}, 
          onWillDisappear: () => {console.log("BindSheet onWillDisappear.")}, 
          onDisappear: () => {console.log("BindSheet onDisappear.")}
        })
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
  }
}
```

![zh-cn_sheet](figures/zh-cn_sheet1.gif)

### 示例2

```ts
// xxx.ets
@Entry
@Component
struct SheetTransitionExample {
  @State isShow:boolean = false
  @Builder myBuilder() {
    Column() {
      Button("content1")
        .margin(10)
        .fontSize(20)

      Button("content2")
        .margin(10)
        .fontSize(20)
    }
    .width('100%')
  }

  build() {
    Column() {
      Button("transition modal 1")
        .onClick(() => {
          this.isShow = true
        })
        .fontSize(20)
        .margin(10)
        .bindSheet($$this.isShow, this.myBuilder(),{
          detents:[SheetSize.MEDIUM,SheetSize.LARGE,200],
          backgroundColor:Color.Gray,
          blurStyle:BlurStyle.Thick,
          showClose:true,
          title:{title:"title", subtitle:"subtitle"},
          preferType: SheetType.CENTER,
          shouldDismiss:((sheetDismiss: SheetDismiss)=> {
            console.log("bind sheet shouldDismiss")
            sheetDismiss.dismiss()
          })
        })
    }
    .justifyContent(FlexAlign.Start)
    .width('100%')
    .height('100%')
  }
}
```

![zh-cn_sheet](figures/zh-cn_sheet2.gif)

### 示例3

```ts
// xxx.ets
// bindSheet属性的borderWidth、borderColor属性值使用LocalizedEdgeWidths类型和LocalizedEdgeColors类型

import { LengthMetrics } from '@ohos.arkui.node'

@Entry
@Component
struct SheetTransitionExample {
  @State isShow: boolean = false

  @Builder
  myBuilder() {
    Column() {
      Button("content1")
        .margin(10)
        .fontSize(20)

      Button("content2")
        .margin(10)
        .fontSize(20)
    }
    .width('100%')
  }

  build() {
    Column() {
      Button("transition modal 1")
        .onClick(() => {
          this.isShow = true
        })
        .fontSize(20)
        .margin(10)
        .bindSheet($$this.isShow, this.myBuilder(), {
          detents: [SheetSize.MEDIUM, SheetSize.LARGE, 200],
          backgroundColor: Color.Gray,
          blurStyle: BlurStyle.Thick,
          showClose: true,
          title: { title: "title", subtitle: "subtitle" },
          preferType: SheetType.CENTER,
          borderWidth: { top: LengthMetrics.vp(10), start: LengthMetrics.vp(10), end: LengthMetrics.vp(20) },
          borderColor: { top: Color.Pink, start: Color.Blue, end: Color.Yellow },
          shouldDismiss: ((sheetDismiss: SheetDismiss) => {
            console.log("bind sheet shouldDismiss")
            sheetDismiss.dismiss()
          })
        })
    }
    .justifyContent(FlexAlign.Start)
    .width('100%')
    .height('100%')
  }
}
```

从左至右显示语言模式示例图

![zh-cn_sheet](figures/zh-cn_sheet3_ltr.png)

从右至左显示语言模式示例图

![zh-cn_sheet](figures/zh-cn_sheet3_rtl.png)