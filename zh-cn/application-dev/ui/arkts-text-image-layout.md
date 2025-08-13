# 图文混排
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiangyuan6-->
<!--SE: @pssea-->
<!--TSE: @jiaoaozihao-->

图文混排是指图片与文字混合排列，文字可展示于图片四周。此排列方式能够直观呈现页面信息，增强视觉冲击力，使页面展示效果更加多样化。

## 使用Span和ImageSpan实现图文混排

通过Text组件设置[textVerticalAlign](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md#textverticalalign20)属性和ImageSpan设置verticalAlign为ImageSpanAlignment.FOLLOW_PARAGRAPH，实现商品价格优惠信息展示的应用场景。

```ts
Text() {
  ImageSpan($r('app.media.hot_sale'))
    .width(50)
    .height(30)
    .borderRadius(5)
    .verticalAlign(ImageSpanAlignment.FOLLOW_PARAGRAPH)
  Span('惊喜价 ￥1299')
    .fontSize(25)
    .fontColor(Color.Red)
  Span('1599')
    .decoration({
    type: TextDecorationType.LineThrough,
    color: Color.Grey,
    style: TextDecorationStyle.SOLID
    })
    .fontSize(16)
}.textVerticalAlign(TextVerticalAlign.CENTER)
```

![span_imagespan_composition](figures/span_imagespan_composition.png)

## 使用属性字符串实现图文混排

通过[ImageAttachment](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#imageattachment)添加图片，[TextStyle](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#textstyle)设置多种文本样式，实现商品详情信息展示的应用场景。

```ts
// xxx.ets
import { image } from '@kit.ImageKit';
import { LengthMetrics } from '@kit.ArkUI';

@Entry
@Component
struct styled_string_demo {
  @State message: string = 'Hello World';
  imagePixelMap: image.PixelMap | undefined = undefined;
  @State imagePixelMap3: image.PixelMap | undefined = undefined;
  mutableStr: MutableStyledString = new MutableStyledString('123');
  controller: TextController = new TextController();
  mutableStr2: MutableStyledString = new MutableStyledString('This is set decoration line style to the mutableStr2', [{
    start: 0,
    length: 15,
    styledKey: StyledStringKey.DECORATION,
    styledValue: new DecorationStyle({
      type: TextDecorationType.Overline,
      color: Color.Orange,
      style: TextDecorationStyle.DOUBLE
    })
  }]);

  async aboutToAppear() {
    console.info("aboutToAppear initial imagePixelMap");
    this.imagePixelMap = await this.getPixmapFromMedia($r('app.media.sky'));
  }

  private async getPixmapFromMedia(resource: Resource) {
    let unit8Array = await this.getUIContext().getHostContext()?.resourceManager?.getMediaContent(resource.id);
    let imageSource = image.createImageSource(unit8Array?.buffer?.slice(0, unit8Array?.buffer?.byteLength));
    let createPixelMap: image.PixelMap = await imageSource.createPixelMap({
      desiredPixelFormat: image.PixelMapFormat.RGBA_8888
    });
    await imageSource.release();
    return createPixelMap;
  }

  leadingMarginValue: ParagraphStyle = new ParagraphStyle({
    leadingMargin: LengthMetrics.vp(5),
    maxLines: 2,
    overflow: TextOverflow.Ellipsis,
    textVerticalAlign: TextVerticalAlign.BASELINE
  });
  //行高样式对象
  lineHeightStyle1: LineHeightStyle = new LineHeightStyle(new LengthMetrics(24));
  //Bold样式
  boldTextStyle: TextStyle = new TextStyle({ fontWeight: FontWeight.Bold });
  //创建含段落样式的对象paragraphStyledString1
  paragraphStyledString1: MutableStyledString =
    new MutableStyledString("\n高质量冲洗照片，高清冲印3/4/5/6寸包邮塑封，品质保证，", [
      {
        start: 0,
        length: 28,
        styledKey: StyledStringKey.PARAGRAPH_STYLE,
        styledValue: this.leadingMarginValue
      },
      {
        start: 11,
        length: 4,
        styledKey: StyledStringKey.LINE_HEIGHT,
        styledValue: this.lineHeightStyle1
      }
    ]);
  paragraphStyledString2: MutableStyledString = new MutableStyledString("\n限时直降5.15元 限量增送", [
    {
      start: 0,
      length: 5,
      styledKey: StyledStringKey.PARAGRAPH_STYLE,
      styledValue: this.leadingMarginValue
    },
    {
      start: 0,
      length: 4,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: new LineHeightStyle(new LengthMetrics(40))
    },
    {
      start: 0,
      length: 9,
      styledKey: StyledStringKey.FONT,
      styledValue: this.boldTextStyle
    },
    {
      start: 1,
      length: 9,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.vp(20), fontColor: Color.Red })
    },
    {
      start: 11,
      length: 4,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: Color.Grey, fontSize: LengthMetrics.vp(14) })
    }
  ]);
  paragraphStyledString3: MutableStyledString = new MutableStyledString("\n￥22.50 销量400万+", [
    {
      start: 0,
      length: 15,
      styledKey: StyledStringKey.PARAGRAPH_STYLE,
      styledValue: this.leadingMarginValue
    },
    {
      start: 0,
      length: 7,
      styledKey: StyledStringKey.LINE_HEIGHT,
      styledValue: new LineHeightStyle(new LengthMetrics(40))
    },
    {
      start: 0,
      length: 7,
      styledKey: StyledStringKey.FONT,
      styledValue: this.boldTextStyle
    },
    {
      start: 1,
      length: 1,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.vp(18), fontColor: Color.Red })
    },
    {
      start: 2,
      length: 2,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.vp(36), fontColor: Color.Red })
    },
    {
      start: 4,
      length: 3,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.vp(20), fontColor: Color.Red })
    },
    {
      start: 7,
      length: 9,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: Color.Grey, fontSize: LengthMetrics.vp(14) })
    }
  ]);

  build() {
    Row() {
      Column({ space: 10 }) {
        Text(undefined, { controller: this.controller })
          .copyOption(CopyOptions.InApp)
          .draggable(true)
          .backgroundColor('#FFFFFF')
          .borderRadius(5)
          .width(210)

        Button('点击查看商品详情')
          .onClick(() => {
            if (this.imagePixelMap !== undefined) {
              this.mutableStr = new MutableStyledString(new ImageAttachment({
                value: this.imagePixelMap,
                size: { width: 210, height: 190 },
                verticalAlign: ImageSpanAlignment.BASELINE,
                objectFit: ImageFit.Fill,
                layoutStyle: {
                  borderRadius: LengthMetrics.vp(5)
                }
              }));
              this.paragraphStyledString1.appendStyledString(this.paragraphStyledString2);
              this.paragraphStyledString1.appendStyledString(this.paragraphStyledString3);
              this.mutableStr.appendStyledString(this.paragraphStyledString1);
              this.controller.setStyledString(this.mutableStr);
            }
          })
      }
      .width('100%')
    }
    .height('100%')
    .backgroundColor('#F8F8FF')
  }
}
```

![styledstring_composition](./figures/styledstring_composition.png)