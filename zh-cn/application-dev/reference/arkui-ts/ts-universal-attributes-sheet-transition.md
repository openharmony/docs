# 半模态转场

通过bindSheet属性为组件绑定半模态页面，在组件插入时可通过设置自定义或默认的内置高度确定半模态大小。

>  **说明： **
>
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> 不支持横竖屏切换。

## 属性

| 名称 | 参数   | 参数描述 |
| -------- | -------- | -------- |
| bindSheet | isShow: boolean,<br>builder: [CustomBuilder](ts-types.md#custombuilder8),<br>sheetStyle?: [SheetStyle](#sheetstyle10) | 给组件绑定半模态页面，点击后显示模态页面。isShow: 必填，是否显示半模态页面。<br/>builder: 必填，配置半模态页面内容。<br/> sheetStyle: 非必填，配置半模态页面高度和是否显示控制条，默认高度是Large，默认显示控制条。 |

## SheetStyle<sup>10+</sup>

| 名称               | 类型                                   | 必填 | 描述                   |
| ------------------ | -------------------------------------- | ---- | ---------------------- |
| height             | [SheetSize](#sheetsize10)&nbsp;\|&nbsp;[Length](ts-types.md#length) | 否 | 半模态高度。          |
| dragBar            | boolean                                | 否   | 是否显示控制条。          |

## SheetSize<sup>10+</sup>

| 名称 | 参数描述 |
| -------- | -------- |
| MEDIUM   | 指定半模态高度为屏幕高度一半。 |
| LARGE    | 指定半模态高度几乎为屏幕高度。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct SheetTransitionExample {
  @State isShow:boolean = false
  @State isShow2:boolean = false
  @State sheetHeight:number = 300;
  @State showDragBar:boolean = true;

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
          this.sheetHeight = null;
        })

      Button("close dragBar")
        .margin(10)
        .fontSize(20)
        .onClick(()=>{
          this.showDragBar = false;
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
        .bindSheet($$this.isShow, this.myBuilder(), {height: this.sheetHeight, dragBar: this.showDragBar})
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
  }
}
```

![zh-cn_sheet](figures/zh-cn_sheet.gif)