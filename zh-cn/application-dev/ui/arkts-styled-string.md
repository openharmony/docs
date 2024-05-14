# 属性字符串（StyledString/MutableStyledString）
## 概述

属性字符串StyledString/MutableStyledString（MutableStyledString继承于StyledString，以下统一简称StyledString）是功能强大的标记对象，可用于字符或段落级别设置文本样式。通过将StyledString附加到文本组件，您可以通过多种方式更改文本，包括修改字号、添加字体颜色、使文本可点击以及自定义方式绘制文本等。具体用法可参考[StyledString](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#属性字符串)。

Arkts提供多种类型样式对象，涵盖各种常见的文本样式格式。您也可以创建自己的CustomSpan, 以应用自定义样式。 

- 创建并应用StyledString和MutableStyledString

  从示例可见，您可以通过TextController提供的setStyledString(StyledString)方法将属性字符串附加到文本组件，并推荐您在onPageShow中触发绑定，在aboutToAppear中调用setStyledString无法实现页面初始即可见属性字符串文本内容，因为aboutToAppear运行时组件还没有完成创建并成功挂载节点树。

  ```ts
  @Entry
  @Component
  struct styled_string_demo1 {
    styledString1: StyledString = new StyledString("运动45分钟");
    mutableStyledString1: MutableStyledString = new MutableStyledString("运动35分钟");
    controller1: TextController = new TextController();
    controller2: TextController = new TextController();

    async onPageShow() {
      this.controller1.setStyledString(this.styledString1)
      this.controller2.setStyledString(this.mutableStyledString1)
    }

    build() {
      Column() {
        // 显示属性字符串
        Text(undefined, { controller: this.controller1 })
        Text(undefined, { controller: this.controller2 })
      }
      .width('100%')
    }
  }
  ```
  ![StyledString_Init](figures/span_string_init.png)

## 设置文本样式

Arkts目前提供了TextStyle、TextShadowStyle、DecorationStyle、BaselineOffsetStyle、LineHeightStyle、LetterSpacingStyle各种Style对象来实现设置文本的各类样式。

- 创建及应用TextStyle

  ```ts
  @Entry
  @Component
  struct styled_string_demo2 {
    textStyleAttrs: TextStyle = new TextStyle({ fontWeight: FontWeight.Bolder, fontSize: LengthMetrics.vp(24), fontStyle: FontStyle.Italic })
    mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟 目标达成", [
      {
        start: 2,
        length: 2,
        styledKey: StyledStringKey.FONT,
        styledValue: this.textStyleAttrs
      },
      {
        start: 7,
        length: 4,
        styledKey: StyledStringKey.FONT,
        styledValue: new TextStyle({ fontColor: Color.Orange, fontSize: LengthMetrics.vp(12)})
      }
    ]);
    controller: TextController = new TextController();

    async onPageShow() {
      this.controller.setStyledString(this.mutableStyledString)
    }

    build() {
      Column() {
        // 显示属性字符串
        Text(undefined, { controller: this.controller })
          .margin({ top: 10 })
      }
      .width('100%')
    }
  }
  ```
  ![StyledString_TextStyle](figures/StyledString_TextStyle.png)

- 创建及应用TextShadowStyle

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct styled_string_demo3 {
    mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
    {
      start: 0,
      length: 3,
      styledKey: StyledStringKey.TEXT_SHADOW,
      styledValue: new TextShadowStyle({
        radius: 5,
        type: ShadowType.COLOR,
        color: Color.Red,
        offsetX: 10,
        offsetY: 10
      })
    }
    ]);
    controller: TextController = new TextController();

    async onPageShow() {
      this.controller.setStyledString(this.mutableStyledString)
    }

    build() {
      Column() {
        // 显示属性字符串
        Text(undefined, { controller: this.controller })
      }
      .width('100%')
    }
  }
  ```
  ![StyledString_TextShadow](figures/styled_string_text_shadow.png)

- 创建及应用DecorationStyle

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct styled_string_demo4 {
    mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
    {
      start: 0,
      length: 3,
      styledKey: StyledStringKey.DECORATION,
      styledValue: new DecorationStyle({type: TextDecorationType.LineThrough, color: Color.Red})
    }
    ]);
    controller: TextController = new TextController();

    async onPageShow() {
      this.controller.setStyledString(this.mutableStyledString)
    }

    build() {
      Column() {
        // 显示属性字符串
        Text(undefined, { controller: this.controller })
      }
      .width('100%')
    }
  }
  ```
  ![StyledString_Decoration](figures/styled_string_decoration.png)

- 创建及应用BaselineOffsetStyle

  ```ts
  import { LengthMetrics, LengthUnit } from '@ohos.arkui.node'
  // xxx.ets
  @Entry
  @Component
  struct styled_string_demo5 {
    mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
      {
        start: 0,
        length: 3,
        styledKey: StyledStringKey.BASELINE_OFFSET,
        styledValue: new BaselineOffsetStyle(LengthMetrics.px(20))
      }
    ]);
    controller: TextController = new TextController();

    async onPageShow() {
      this.controller.setStyledString(this.mutableStyledString)
    }

    build() {
      Column() {
        // 显示属性字符串
        Text(undefined, { controller: this.controller })
      }
      .width('100%')
    }
  }
  ```
  ![StyledString_Baseline](figures/styled_string_baselineoffset.png)

- 创建及应用LineHeightStyle

  ```ts
  import { LengthMetrics, LengthUnit } from '@ohos.arkui.node'
  // xxx.ets
  @Entry
  @Component
  struct styled_string_demo6 {
    mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟\n顶顶顶\n得到", [
      {
        start: 8,
        length: 3,
        styledKey: StyledStringKey.LINE_HEIGHT,
        styledValue: new LineHeightStyle(LengthMetrics.vp(50))
      }
    ]);
    controller: TextController = new TextController();

    async onPageShow() {
      this.controller.setStyledString(this.mutableStyledString)
    }

    build() {
      Column() {
        // 显示属性字符串
        Text(undefined, { controller: this.controller })
      }
      .width('100%')
      .margin({ top: 10 })
    }
  }
  ```
  ![StyledString_lineHeight](figures/styled_string_lineHeight.png)

- 创建及应用LetterSpacingStyle

  ```ts
  import { LengthMetrics, LengthUnit } from '@ohos.arkui.node'
  // xxx.ets
  @Entry
  @Component
  struct styled_string_demo7 {
    mutableStyledString: MutableStyledString = new MutableStyledString("运动35分钟", [
      {
        start: 0,
        length: 2,
        styledKey: StyledStringKey.LETTER_SPACING,
        styledValue: new LetterSpacingStyle(new LengthMetrics(20, LengthUnit.VP))
      }
    ]);
    controller: TextController = new TextController();

    async onPageShow() {
      this.controller.setStyledString(this.mutableStyledString)
    }

    build() {
      Column() {
        // 显示属性字符串
        Text(undefined, { controller: this.controller })
      }
      .width('100%')
    }
  }
  ```
  ![StyledString_letterSpacing](figures/styled_string_letterspacing.png)

## 设置段落样式

可通过ParagraphStyle设置段落样式布局。下图显示了Arkts如何分割文本中的段落，段落以换行符 \n 结尾。

![paragraphs](figures/styledstring-paragraphs.png)

以下代码示例展示了如何创建 ParagraphStyle 并应用。请注意，如果您将 ParagraphStyle 附加到段落开头末尾或之间的任何位置均会应用样式，非段落区间内则不会应用样式。

  ```ts
  import { LengthMetrics } from '@ohos.arkui.node'
  titleParagraphStyleAttr: ParagraphStyle = new ParagraphStyle({ textAlign: TextAlign.Center });
  //段落首行缩进15vp
  paragraphStyleAttr1: ParagraphStyle = new ParagraphStyle({ textIndent: LengthMetrics.vp(15) });
  //创建含段落样式的对象paragraphStyledString1
  paragraphStyledString1: MutableStyledString = new MutableStyledString("段落标题\n正文第一段落开始0123456789正文第一段落结束。", [
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.PARAGRAPH_STYLE,
      styledValue: this.titleParagraphStyleAttr
    },
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: new LineHeightStyle(new LengthMetrics(50))
    },{
    start: 0,
    length: 4,
    styledKey: StyledStringKey.FONT,
    styledValue: new TextStyle({ fontSize: LengthMetrics.vp(24), fontWeight: FontWeight.Bolder })
  },
    {
      start: 5,
      length: 3,
      styledKey: StyledStringKey.PARAGRAPH_STYLE,
      styledValue: this.paragraphStyleAttr1
    },
    {
      start: 5,
      length: 20,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: this.lineHeightStyle1
    }
  ]);
  ```

  您除了可以在创建属性字符串时就预设样式，也可以后续通过[replaceStyle](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#replaceStyle)更新样式, 同时需要在附件的文本组件controller上主动触发更新绑定的属性字符串。

  ```ts
  import { LengthMetrics } from '@ohos.arkui.node'
  //段落不设置缩进配置最大行数及超长显示方式
  paragraphStyleAttr3: ParagraphStyle = new ParagraphStyle({ textAlign: TextAlign.End, maxLines: 1, wordBreak: WordBreak.BREAK_ALL, overflow: TextOverflow.Ellipsis});
  // 后续某个节点触发更新段落样式
  controller: TextController = new TextController();
  this.paragraphStyledString1.replaceStyle({
    start: 5,
    length: 3,
    styledKey: StyledStringKey.PARAGRAPH_STYLE,
    styledValue: this.paragraphStyleAttr3
  })
  this.controller.setStyledString(this.mutableStyledString3)
  ```



## 使用事件

可通过GestureStyle设置onClick、onLongPress事件来使文本响应点击长按事件。

- 创建并应用GestureStyle

  除了初始化属性字符串对象即初始样式对象，亦可通过[setStyle](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#setStyle)接口再设置样式，同时需要在附件的文本组件controller上主动触发更新绑定的属性字符串。

  ```ts
  import promptAction from '@ohos.promptAction';
  gestureStyleAttr: GestureStyle = new GestureStyle({
    onClick: () => {
      promptAction.showToast({ message: 'gestureStyleAttr object trigger click event' })
    },
    onLongPress: () => {
      promptAction.showToast({ message: 'gestureStyleAttr object trigger long press event' })
    }
  });
  // 创建对象mutableStyledString3
  mutableStyledString3: MutableStyledString = new MutableStyledString("#属性字符串");
  // 后续某个节点触发设置事件
  controller: TextController = new TextController();
  this.mutableStyledString3.setStyle({
    start: 0,
    length: 5,
    styledKey: StyledStringKey.GESTURE,
    styledValue: this.gestureStyleAttr
  })
  this.controller.setStyledString(this.mutableStyledString3)
  ```

## 使用自定义绘制

可通过CustomSpan来实现自定义绘制。

以下示例展示了如何创建自定义Span。您可以通过继承[CustomSpan](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#customspan)定义一个自己的Span，在自定义Span中重写onDraw和onMeasure来实现自定义绘制的效果。

```ts
import drawing from '@ohos.graphics.drawing';

class MyCustomSpan extends CustomSpan {
  constructor(word: string, width: number, height: number) {
    super();
    this.word = word;
    this.width = width
    this.height = height
  }

  onMeasure(measureInfo: CustomSpanMeasureInfo): CustomSpanMetrics {
    return { width: this.width, height: this.height }
  }

  onDraw(context: DrawContext, options: CustomSpanDrawInfo) {
    let canvas = context.canvas;

    const brush = new drawing.Brush();
    brush.setColor({ alpha: 255, red: 0, green: 0, blue: 0 })
    const font = new drawing.Font()
    font.setSize(px2fp(60))
    const textBlob = drawing.TextBlob.makeFromString(this.word.substr(0, 5), font, drawing.TextEncoding.TEXT_ENCODING_UTF8)
    canvas.attachBrush(brush)

    this.onDrawRectByRadius(context, options.x, options.x + vp2px(this.width), options.lineTop, options.lineBottom, 20)
    brush.setColor({ alpha: 255, red: 255, green: 255, blue: 255 })
    canvas.attachBrush(brush)
    canvas.drawTextBlob(textBlob, options.x, options.lineBottom - 15)
    brush.setColor({ alpha: 255, red: 255, green: 228 , blue: 196 })
    canvas.attachBrush(brush)
    const textBlob1 = drawing.TextBlob.makeFromString(this.word.substr(6), font, drawing.TextEncoding.TEXT_ENCODING_UTF8)
    canvas.drawTextBlob(textBlob1, options.x + 130, options.lineBottom - 15)

    canvas.detachBrush()
  }
  onDrawRectByRadius(context: DrawContext, left: number, right: number, top: number, bottom: number, radius: number) {
    let canvas = context.canvas
    let path = new drawing.Path()

    // 画带radius的rect
    path.moveTo(left  + radius, top)
    path.lineTo(right - radius, top)
    path.arcTo(right - 2 * radius, top, right, top + 2 * radius, 270, 90)
    path.lineTo(right, bottom - radius)
    path.arcTo(right - 2 * radius, bottom - 2 * radius, right, bottom, 0, 90)

    path.lineTo(left + 2 * radius, bottom)
    path.arcTo(left, bottom - 2 * radius, left + 2 * radius, bottom, 90, 90)
    path.lineTo(left, top + 2 * radius)
    path.arcTo(left, top, left + 2 * radius, top + 2 * radius, 180, 90)

    canvas.drawPath(path)
  }
  setWord(word: string) {
    this.word = word;
  }

  width: number = 160
  word: string = "drawing"
  height: number = 10
}

@Entry
@Component
struct styled_string_demo6 {
  customSpan3: MyCustomSpan = new MyCustomSpan("88VIP 9.5折", 150, 40)
  textStyle: MutableStyledString = new MutableStyledString("123");
  textController: TextController = new TextController()
  isPageShow: boolean = true
  
  async onPageShow() {
    if (!this.isPageShow) {
      return
    }
    this.isPageShow = false
    this.textController.setStyledString(new StyledString(this.customSpan3))
  }

  build() {
    Row() {
      Column() {
        Text(undefined, { controller: this.textController })
          .copyOption(CopyOptions.InApp)
          .fontSize(30)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![CustomSpanDemo](figures/StyledString_CustomSpan.png)

## 场景示例

```ts
import { LengthMetrics } from '@ohos.arkui.node';

@Entry
@Component
struct Index {
  alignCenterParagraphStyleAttr: ParagraphStyle = new ParagraphStyle({ textAlign: TextAlign.Center });
  //行高样式对象
  lineHeightStyle1: LineHeightStyle= new LineHeightStyle(new LengthMetrics(24));
  //Bold样式
  boldTextStyle: TextStyle = new TextStyle({ fontWeight: FontWeight.Bold });
  //创建含段落样式的对象paragraphStyledString1
  paragraphStyledString1: MutableStyledString = new MutableStyledString("您的豪华钻石已过期1天\n续费可继续享受会员专属权益", [
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.PARAGRAPH_STYLE,
      styledValue: this.alignCenterParagraphStyleAttr
    },
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: new LineHeightStyle(new LengthMetrics(40))
    },
    {
    start: 11,
    length: 14,
    styledKey: StyledStringKey.FONT,
    styledValue: new TextStyle({ fontSize: LengthMetrics.vp(14), fontColor: Color.Grey })
  },
    {
      start: 11,
      length: 4,
      styledKey: StyledStringKey.PARAGRAPH_STYLE,
      styledValue: this.alignCenterParagraphStyleAttr
    },
    {
      start: 11,
      length: 4,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: this.lineHeightStyle1
    }
  ]);
  paragraphStyledString2: MutableStyledString = new MutableStyledString("\n￥4.88￥15", [
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.PARAGRAPH_STYLE,
      styledValue: this.alignCenterParagraphStyleAttr
    },
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: new LineHeightStyle(new LengthMetrics(60))
    },
    {
      start: 0,
      length: 6,
      styledKey: StyledStringKey.FONT,
      styledValue: this.boldTextStyle
    },
    {
      start: 1,
      length: 1,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.vp(18)})
    },
    {
      start: 2,
      length: 4,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.vp(40)})
    },
    {
      start: 6,
      length: 3,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: Color.Grey, fontSize: LengthMetrics.vp(14)})
    },
    {
      start: 6,
      length: 3,
      styledKey: StyledStringKey.DECORATION,
      styledValue: new DecorationStyle({ type: TextDecorationType.LineThrough, color: Color.Grey })
    }
  ])
  paragraphStyledString3: MutableStyledString = new MutableStyledString("\n02时06分后将失去该优惠", [
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.PARAGRAPH_STYLE,
      styledValue: this.alignCenterParagraphStyleAttr
    },
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: new LineHeightStyle(new LengthMetrics(30))
    },
    {
      start: 1,
      length: 2,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: '#FFD700', fontWeight: FontWeight.Bold })
    },
    {
      start: 4,
      length: 2,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: '#FFD700', fontWeight: FontWeight.Bold })
    }
  ])
  controller: TextController = new TextController();
  async onPageShow() {
    this.paragraphStyledString2.appendStyledString(this.paragraphStyledString3)
    this.paragraphStyledString1.appendStyledString(this.paragraphStyledString2)
    this.controller.setStyledString(this.paragraphStyledString1)
  }

  build() {
    Row() {
      Column( { space : 5 }) {
        Text(undefined, { controller: this.controller })
          .width(240)
          .copyOption(CopyOptions.InApp)
          .draggable(true)

        Button("限时4.88元 立即续费")
          .width(200)
          .fontColor(Color.White)
          .fontSize(18)
          .backgroundColor('#3CB371')
          .margin({ bottom: 10 })
      }
      .borderWidth(1).borderColor('#FFDEAD')
      .margin({ left: 10 })
    }
    .height('60%')
  }
}
```
![StyledString_SceneDemo](figures/styledString_sceneDemo.png)
