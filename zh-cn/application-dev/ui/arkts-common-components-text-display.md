# 文本显示 (Text/Span)


Text是文本组件，通常用于展示用户视图，如显示文章的文字。具体用法请参考[Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md)。


## 创建文本

Text可通过以下两种方式来创建：


- string字符串。

  ```ts
  Text('我是一段文本')
  ```


![zh-cn_image_0000001563060685](figures/zh-cn_image_0000001563060685.png)


- 引用Resource资源。

  资源引用类型可以通过$r创建Resource类型对象，文件位置为/resources/base/element/string.json。


  ```ts
  Text($r('app.string.module_desc'))
    .baselineOffset(0)
    .fontSize(30)
    .border({ width: 1 })
    .padding(10)
    .width(300)
  ```

  ![zh-cn_image_0000001511580872](figures/zh-cn_image_0000001511580872.png)


## 添加子组件

[Span](../reference/apis-arkui/arkui-ts/ts-basic-components-span.md)只能作为[Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md)和[RichEditor](../reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md)组件的子组件显示文本内容。可以在一个Text内添加多个Span来显示一段信息，例如产品说明书、承诺书等。

- 创建Span。

  Span组件需要写到Text组件内，单独写Span组件不会显示信息，Text与Span同时配置文本内容时，Span内容覆盖Text内容。


  ```ts
  Text('我是Text') {
    Span('我是Span')
  }
  .padding(10)
  .borderWidth(1)
  ```

  ![zh-cn_image_0000001562700441](figures/zh-cn_image_0000001562700441.png)

- 设置文本装饰线及颜色。

  通过decoration设置文本装饰线及颜色。


  ```ts
  Text() {
    Span('我是Span1，').fontSize(16).fontColor(Color.Grey)
      .decoration({ type: TextDecorationType.LineThrough, color: Color.Red })
    Span('我是Span2').fontColor(Color.Blue).fontSize(16)
      .fontStyle(FontStyle.Italic)
      .decoration({ type: TextDecorationType.Underline, color: Color.Black })
    Span('，我是Span3').fontSize(16).fontColor(Color.Grey)
      .decoration({ type: TextDecorationType.Overline, color: Color.Green })
  }
  .borderWidth(1)
  .padding(10)
  ```

  ![zh-cn_image_0000001562700437](figures/zh-cn_image_0000001562700437.png)

- 通过textCase设置文字一直保持大写或者小写状态。

  ```ts
  Text() {
    Span('I am Upper-span').fontSize(12)
      .textCase(TextCase.UpperCase)
  }
  .borderWidth(1)
  .padding(10)
  ```

  ![zh-cn_image_0000001562940525](figures/zh-cn_image_0000001562940525.png)

- 添加事件。

  由于Span组件无尺寸信息，事件仅支持添加点击事件onClick。


  ```ts
  Text() {
    Span('I am Upper-span').fontSize(12)
      .textCase(TextCase.UpperCase)
      .onClick(()=>{
        console.info('我是Span——onClick')
      })
  }
  ```


## 自定义文本样式

- 通过textAlign属性设置文本对齐样式。

  ```ts
  Text('左对齐')
    .width(300)
    .textAlign(TextAlign.Start)
    .border({ width: 1 })
    .padding(10)
  Text('中间对齐')
    .width(300)
    .textAlign(TextAlign.Center)
    .border({ width: 1 })
    .padding(10)
  Text('右对齐')
    .width(300)
    .textAlign(TextAlign.End)
    .border({ width: 1 })
    .padding(10)
  ```

  ![zh-cn_image_0000001511421260](figures/zh-cn_image_0000001511421260.png)

- 通过textOverflow属性控制文本超长处理，textOverflow需配合maxLines一起使用（默认情况下文本自动折行）。

  ```ts
  Text('This is the setting of textOverflow to Clip text content This is the setting of textOverflow to None text content. This is the setting of textOverflow to Clip text content This is the setting of textOverflow to None text content.')
    .width(250)
    .textOverflow({ overflow: TextOverflow.None })
    .maxLines(1)
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)
  Text('我是超长文本，超出的部分显示省略号。I am an extra long text, with ellipses displayed for any excess。')
    .width(250)
    .textOverflow({ overflow: TextOverflow.Ellipsis })
    .maxLines(1)
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)
  Text('当文本溢出其尺寸时，文本将滚动显示。When the text overflows its dimensions, the text will scroll for displaying.')       
    .width(250)
    .textOverflow({ overflow: TextOverflow.MARQUEE })                 
    .maxLines(1)       
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)                       
  ```

  ![zh-cn_image_0000001563060701](figures/zh-cn_image_0000001563060701.gif)

- 通过lineHeight属性设置文本行高。

  ```ts
  Text('This is the text with the line height set. This is the text with the line height set.')
    .width(300).fontSize(12).border({ width: 1 }).padding(10)
  Text('This is the text with the line height set. This is the text with the line height set.')
    .width(300).fontSize(12).border({ width: 1 }).padding(10)
    .lineHeight(20)
  ```

  ![zh-cn_image_0000001511740480](figures/zh-cn_image_0000001511740480.png)

- 通过decoration属性设置文本装饰线样式及其颜色。

  ```ts
  Text('This is the text')
    .decoration({
      type: TextDecorationType.LineThrough,
      color: Color.Red
    })
    .borderWidth(1).padding(10).margin(5)
  Text('This is the text')
    .decoration({
      type: TextDecorationType.Overline,
      color: Color.Red
    })
    .borderWidth(1).padding(10).margin(5)
  Text('This is the text')
    .decoration({
      type: TextDecorationType.Underline,
      color: Color.Red
    })
    .borderWidth(1).padding(10).margin(5)
  ```

  ![zh-cn_image_0000001511580888](figures/zh-cn_image_0000001511580888.png)

- 通过baselineOffset属性设置文本基线的偏移量。

  ```ts
  Text('This is the text content with baselineOffset 0.')
    .baselineOffset(0)
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)
    .width('100%')
    .margin(5)
  Text('This is the text content with baselineOffset 30.')
    .baselineOffset(30)
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)
    .width('100%')
    .margin(5)

  Text('This is the text content with baselineOffset -20.')
    .baselineOffset(-20)
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)
    .width('100%')
    .margin(5)
  ```

  ![zh-cn_image_0000001562820789](figures/zh-cn_image_0000001562820789.png)

- 通过letterSpacing属性设置文本字符间距。

  ```ts
  Text('This is the text content with letterSpacing 0.')
    .letterSpacing(0)
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)
    .width('100%')
    .margin(5)
  Text('This is the text content with letterSpacing 3.')
    .letterSpacing(3)
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)
    .width('100%')
    .margin(5)
  Text('This is the text content with letterSpacing -1.')
    .letterSpacing(-1)
    .fontSize(12)
    .border({ width: 1 })
    .padding(10)
    .width('100%')
    .margin(5)
  ```

  ![zh-cn_image_0000001562940513](figures/zh-cn_image_0000001562940513.png)

- 通过minFontSize与maxFontSize自适应字体大小，minFontSize设置文本最小显示字号，maxFontSize设置文本最大显示字号，minFontSize与maxFontSize必须搭配同时使用，以及需配合maxline或布局大小限制一起使用，单独设置不生效。

  ```ts
  Text('我的最大字号为30，最小字号为5，宽度为250，maxLines为1')
    .width(250)
    .maxLines(1)
    .maxFontSize(30)
    .minFontSize(5)
    .border({ width: 1 })
    .padding(10)
    .margin(5)
  Text('我的最大字号为30，最小字号为5，宽度为250，maxLines为2')
    .width(250)
    .maxLines(2)
    .maxFontSize(30)
    .minFontSize(5)
    .border({ width: 1 })
    .padding(10)
    .margin(5)
  Text('我的最大字号为30，最小字号为15，宽度为250,高度为50')
    .width(250)
    .height(50)
    .maxFontSize(30)
    .minFontSize(15)
    .border({ width: 1 })
    .padding(10)
    .margin(5)
  Text('我的最大字号为30，最小字号为15，宽度为250,高度为100')
    .width(250)
    .height(100)
    .maxFontSize(30)
    .minFontSize(15)
    .border({ width: 1 })
    .padding(10)
    .margin(5)
  ```

  ![zh-cn_image_0000001511740472](figures/zh-cn_image_0000001511740472.png)

- 通过textCase属性设置文本大小写。

  ```ts
  Text('This is the text content with textCase set to Normal.')
    .textCase(TextCase.Normal)
    .padding(10)
    .border({ width: 1 })
    .padding(10)
    .margin(5)

  // 文本全小写展示
  Text('This is the text content with textCase set to LowerCase.')
    .textCase(TextCase.LowerCase)
    .border({ width: 1 })
    .padding(10)
    .margin(5)

  // 文本全大写展示
  Text('This is the text content with textCase set to UpperCase.')
    .textCase(TextCase.UpperCase)
    .border({ width: 1 })
    .padding(10)
    .margin(5)
  ```

  ![zh-cn_image_0000001562940529](figures/zh-cn_image_0000001562940529.png)

- 通过copyOption属性设置文本是否可复制粘贴。

  ```ts
  Text("这是一段可复制文本")
    .fontSize(30)
    .copyOption(CopyOptions.InApp)
  ```

  ![zh-cn_image_0000001511580868](figures/zh-cn_image_0000001511580868.png)


## 添加事件

Text组件可以添加通用事件，可以绑定onClick、onTouch等事件来响应操作。


```ts
Text('点我')
  .onClick(()=>{
      console.info('我是Text的点击响应事件');
   })
```


## 场景示例


```ts
// xxx.ets
@Entry
@Component
struct TextExample {
  build() {
    Column() {
      Row() {
        Text("1").fontSize(14).fontColor(Color.Red).margin({ left: 10, right: 10 })
        Text("我是热搜词条1")
          .fontSize(12)
          .fontColor(Color.Blue)
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
          .fontWeight(300)
        Text("爆")
          .margin({ left: 6 })
          .textAlign(TextAlign.Center)
          .fontSize(10)
          .fontColor(Color.White)
          .fontWeight(600)
          .backgroundColor(0x770100)
          .borderRadius(5)
          .width(15)
          .height(14)
      }.width('100%').margin(5)

      Row() {
        Text("2").fontSize(14).fontColor(Color.Red).margin({ left: 10, right: 10 })
        Text("我是热搜词条2 我是热搜词条2 我是热搜词条2 我是热搜词条2 我是热搜词条2")
          .fontSize(12)
          .fontColor(Color.Blue)
          .fontWeight(300)
          .constraintSize({ maxWidth: 200 })
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
        Text("热")
          .margin({ left: 6 })
          .textAlign(TextAlign.Center)
          .fontSize(10)
          .fontColor(Color.White)
          .fontWeight(600)
          .backgroundColor(0xCC5500)
          .borderRadius(5)
          .width(15)
          .height(14)
      }.width('100%').margin(5)

      Row() {
        Text("3").fontSize(14).fontColor(Color.Orange).margin({ left: 10, right: 10 })
        Text("我是热搜词条3")
          .fontSize(12)
          .fontColor(Color.Blue)
          .fontWeight(300)
          .maxLines(1)
          .constraintSize({ maxWidth: 200 })
          .textOverflow({ overflow: TextOverflow.Ellipsis })
        Text("热")
          .margin({ left: 6 })
          .textAlign(TextAlign.Center)
          .fontSize(10)
          .fontColor(Color.White)
          .fontWeight(600)
          .backgroundColor(0xCC5500)
          .borderRadius(5)
          .width(15)
          .height(14)
      }.width('100%').margin(5)

      Row() {
        Text("4").fontSize(14).fontColor(Color.Grey).margin({ left: 10, right: 10 })
        Text("我是热搜词条4 我是热搜词条4 我是热搜词条4 我是热搜词条4 我是热搜词条4")
          .fontSize(12)
          .fontColor(Color.Blue)
          .fontWeight(300)
          .constraintSize({ maxWidth: 200 })
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
      }.width('100%').margin(5)
    }.width('100%')
  }
}

```

![zh-cn_image_0000001562820805](figures/zh-cn_image_0000001562820805.png)
<!--RP1--><!--RP1End-->
