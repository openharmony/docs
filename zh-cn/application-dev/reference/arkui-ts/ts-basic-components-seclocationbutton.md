# SecLocationButton

安全控件的位置按钮，用户通过点击该位置按钮，可以临时获取精准定位权限，而不需要权限弹框授权确认。

> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

不支持。

## 接口

**方法1：** SecLocationButton()

默认创建带有图标、文本、背景的位置按钮。

**方法2：** SecLocationButton(option:{icon?: LocationIconStyle, text?: LocationDescription, background?: BackgroundButtonType})

创建包含指定元素的位置按钮。

**参数：**
| 参数名 | 参数类型                            | 必填 | 参数描述       |
| ------ | ----------------------------------- | ---- | -------------- |
| icon  | [LocationIconStyle](#locationiconstyle枚举说明) |否   | 设置位置按钮的图标风格<br/>不传入该参数表示没有图标，icon和text至少存在一个。 |
| text   | [LocationDescription](#locationdescription枚举说明) | 否   | 设置位置按钮的文本描述<br/>不传入该参数表示没有文字描述，icon和text至少存在一个。 |
| background   | [BackgroundButtonType](#backgroundbuttontype枚举说明) | 否   | 设置位置按钮的背景样式<br/>不传入该参数表示没有背景。 |

## LocationIconStyle枚举说明

| 名称                | 描述               |
| ------------------- | ------------------ |
| FULL_FILLED   | 位置按钮展示填充样式图标。 |
| LINES | 位置按钮展示线条样式图标。 |

## LocationDescription枚举说明

| 名称                | 描述               |
| ------------------- | ------------------ |
| CURRENT_LOCATION | 位置按钮的文字描述为“当前位置”。 |
| ADD_LOCATION | 位置按钮的文字描述为“添加位置”。 |
| SELECT_LOCATION | 位置按钮的文字描述为“选择位置”。 |
| SHARE_LOCATION | 位置按钮的文字描述为“共享位置”。 |
| SEND_LOCATION | 位置按钮的文字描述为“发送位置”。 |
| LOCATING | 位置按钮的文字描述为“定位”。 |
| LOCATION | 位置按钮的文字描述为“位置”。 |
| SEND_CURRENT_LOCATION | 位置按钮的文字描述为“发送实时位置”。 |
| RELOCATION | 位置按钮的文字描述为“重定位”。 |
| PUNCH_IN | 位置按钮的文字描述为“打卡定位”。 |
| CURRENT_POSITION | 位置按钮的文字描述为“所在位置”。 |

## BackgroundButtonType枚举说明
| 名称                | 描述               |
| ------------------- | ------------------ |
| CAPSULE_BACKGROUND | 位置按钮的背景样式为胶囊状。 |
| CIRCLE_BACKGROUND | 位置按钮的背景样式为圆状。 |
| NORMAL_BACKGROUND | 位置按钮的背景样式为矩形。 |

## SecLocationButtonLayoutOrder枚举说明

| 名称                | 描述               |
| ------------------- | ------------------ |
| ICON_FIRST   | 图标的排列顺序先于文字。 |
| TEXT_FIRST | 文字的排列顺序先于图标。 |

## SecLocationButtonLayoutDirection枚举说明

| 名称                | 描述               |
| ------------------- | ------------------ |
| HORIZONTAL   | 位置按钮上图标和文字分布的方向为水平排列。 |
| VERTICAL | 位置按钮上图标和文字分布的方向为垂直排列。 |

## SecLocationButtonOnClickResult枚举说明

| 名称                | 描述               |
| ------------------- | ------------------ |
| LOCATION_BUTTON_CLICK_SUCCESS   | 位置按钮点击成功。 |
| LOCATION_BUTTON_CLICK_GRANT_FAILED | 位置按钮点击后位置权限授权失败。 |

## 属性

不支持通用属性，仅支持以下属性：

| 名称          | 参数类型   | 必填   | 描述                                       |
| ----------- | ------ | ---- | ---------------------------------------- |
| iconSize          | [Length](ts-types.md#length) | 否 | 设置位置按钮上图标的尺寸。<br/> 默认值：16vp         |
| layoutDirection        | [SecLocationButtonLayoutDirection](#seclocationbuttonlayoutdirection枚举说明) | 否 | 设置位置按钮上图标和文字分布的方向。 <br/> 默认值：SecLocationButtonLayoutDirection.HORIZONTAL|
| layoutOrder | [SecLocationButtonLayoutOrder](#seclocationbuttonlayoutorder枚举说明) | 否 | 设置位置按钮上图标和文字分布的顺序。 <br/> 默认值：SecLocationButtonLayoutOrder.ICON_FIRST|
| position | [Position](ts-types.md#position8) | 否    | 设置绝对定位，设置位置按钮的左上角相对于父容器左上角的偏移位置。<br/> 默认值：<br/>{ <br/>x: 0,<br/>y: 0<br/>}|
| markAnchor | [Position](ts-types.md#position8) | 否    | 设置绝对定位的锚点，以位置按钮的左上角作为基准点进行偏移。 <br/> 默认值：<br/>{ <br/>x: 0,<br/>y: 0<br/>}||
| offset | [Position](ts-types.md#position8) | 否    | 设置相对定位，位置按钮相对于自身的偏移量。 <br/> 默认值：<br/>{ <br/>x: 0,<br/>y: 0<br/>}||
| fontSize | [Length](ts-types.md#length) | 否    | 设置位置按钮上文字的尺寸。<br/> 默认值：16fp |
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle) | 否    | 设置位置按钮上文字的样式。<br/> 默认值：FontStyle.Normal |
| fontWeight | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string | 否   | 设置位置按钮上文字粗细。 <br/> 默认值：FontWeight.Medium |
| fontFamily | string \| [Resource](ts-types.md#resource类型) | 否    | 设置位置按钮上文字的字体。 <br/> 默认字体：'HarmonyOS Sans' |
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 否    | 设置位置按钮上文字的颜色。<br/> 默认值：#ffffffff |
| iconColor | [ResourceColor](ts-types.md#resourcecolor) | 否    | 设置位置按钮上图标的颜色。<br/> 默认值：#ffffffff |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 否    | 设置位置按钮的背景颜色。 <br/> 默认值：#007dff  |
| borderStyle | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 设置位置按钮的边框的样式。   <br/> 默认不设置边框样式   |
| borderWidth | [Length](ts-types.md#length) | 否    | 设置位置按钮的边框的宽度。 <br/> 默认不设置边框宽度  |
| borderColor | [ResourceColor](ts-types.md#resourcecolor) | 否    | 设置位置按钮的边框的颜色。  <br/> 默认不设置边框颜色  |
| borderRadius | [Length](ts-types.md#length) | 否    | 设置位置按钮的边框圆角半径。<br/> 默认值：1/2 按钮整高       |
| backgroundPadding | [Padding](ts-types.md#padding) \| [Length](ts-types.md#length) | 否    | 设置位置按钮的内边距。 <br/> 默认值：上下8vp, 左右24vp |
| textIconPadding | [Length](ts-types.md#length) | 否    | 设置位置按钮中图标和文字的间距。  <br/> 默认值：4vp      |


## 事件

不支持通用事件，仅支持以下事件：

| 名称                                                         | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onClick((result: [SecLocationButtonOnClickResult](#seclocationbuttononclickresult枚举说明), event?: [ClickEvent](ts-universal-events-click.md#clickevent对象说明)) => void) | 点击动作触发该回调。<br/>result：位置权限的授权结果。<br/>event：见ClickEvent对象说明。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Row() {
      Column({space:10}) {
        // 默认位置按钮
        SecLocationButton()
        // 生成默认位置按钮，包含图标+文字+背景
        SecLocationButton()
          .fontSize(35)
          .fontColor(Color.White)
          .iconSize(30)
          .layoutDirection(SecLocationButtonLayoutDirection.HORIZONTAL)
          .layoutOrder(SecLocationButtonLayoutOrder.TEXT_FIRST)
          .borderWidth(1)
          .borderStyle(BorderStyle.Dashed)
          .borderColor(Color.Blue)
          .borderRadius(20)
          .fontWeight(100)
          .iconColor(Color.White)
          .backgroundPadding({ left: 50, top: 50, bottom: 50, right: 50 })
          .textIconPadding(20)
          .backgroundColor(0x3282f6)
          .onClick((result: SecLocationButtonOnClickResult) => {
            console.error("result " + result)
          })
        // 生成定制图标、文字、背景的位置按钮
        SecLocationButton({icon:LocationIconStyle.LINES, text:LocationDescription.CURRENT_POSITION, background:BackgroundButtonType.NORMAL_BACKGROUND})
          .fontSize(35)
          .fontColor(0x3282f6)
          .iconSize(30)
          .layoutDirection(SecLocationButtonLayoutDirection.VERTICAL)
          .layoutOrder(SecLocationButtonLayoutOrder.ICON_FIRST)
          .borderWidth(1)
          .borderStyle(BorderStyle.Dashed)
          .borderColor(0x9ffcfd)
          .borderRadius(20)
          .fontWeight(100)
          .iconColor(0x3282f6)
          .backgroundPadding({left:50, top:50, bottom:50, right:50})
          .textIconPadding(20)
          .backgroundColor(0x9ffcfd)
          .onClick((result: SecLocationButtonOnClickResult)=>{
            console.error("result " + result)
          })
      }.width('100%')
    }.height('100%')
  }
}
```

![seclocatonbutton1](figures/seclocationbutton1.png)
