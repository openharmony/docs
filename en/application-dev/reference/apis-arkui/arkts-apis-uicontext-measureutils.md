# Class (MeasureUtils)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

Provides APIs for measuring text metrics, such as text height and width.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - In the following API examples, you must first use [getMeasureUtils()](arkts-apis-uicontext-uicontext.md#getmeasureutils12) in **UIContext** to obtain a **MeasureUtils** instance, and then call the APIs using the obtained instance.
>
> To perform more complex text measurements, use the [Paragraph](../apis-arkgraphics2d/js-apis-graphics-text.md#paragraph) API.
>
> Avoid using [ApplicationContext.setFontSizeScale](../apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetfontsizescale13) during text measurement API calls. To ensure timing correctness and the accuracy of measurement results, manually listen for font scale changes.
>
> For measuring text after truncation, direct use of the string length for truncation may lead to inaccuracies. This is because certain Unicode characters (for example, emojis) have code points with a length greater than 1, and truncating by string length can split these multi-code-point characters, resulting in incorrect text display or measurement errors. As such, you are advised to perform iterative processing based on Unicode code points during truncation.

## measureText<sup>12+</sup>

measureText(options: MeasureOptions): number

Measures the width of the given single-line text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](js-apis-measure.md#measureoptions) | Yes   | Options of the target text.|

**Return value**

| Type         | Description      |
| ------------  | --------- |
| number        | Text width.<br>**NOTE**<br>Floating-point results are rounded up.<br>Unit: px.|


**Example**

This example uses the **measureText** API of **MeasureUtils** to obtain the width of the **"Hello World"** text.

```ts
import { MeasureUtils } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State uiContext: UIContext = this.getUIContext();
  @State uiContextMeasure: MeasureUtils = this.uiContext.getMeasureUtils();
  @State textWidth: number = this.uiContextMeasure.measureText({
    textContent: "Hello World",
    fontSize: '50px'
  });

  build() {
    Row() {
      Column() {
        Text(`The width of 'Hello World': ${this.textWidth}`)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## measureTextSize<sup>12+</sup>

measureTextSize(options: MeasureOptions): SizeOptions

Measures the width and height of the given single-line text.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](js-apis-measure.md#measureoptions) | Yes   | Options of the target text.|

**Return value**

| Type         | Description      |
| ------------  | --------- |
| [SizeOptions](arkui-ts/ts-types.md#sizeoptions)   | Width and height of the text.<br>**NOTE**<br>If **constraintWidth** is not specified, the floating-point value of the text width will be rounded up.<br>The return values for text width and height are both in px.|


**Example**

This example uses the **measureTextSize** API of **MeasureUtils** to obtain the width and height of the **"Hello World"** text.

```ts
import { MeasureUtils } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State uiContext: UIContext = this.getUIContext();
  @State uiContextMeasure: MeasureUtils = this.uiContext.getMeasureUtils();
  textSize: SizeOptions = this.uiContextMeasure.measureTextSize({
    textContent: "Hello World",
    fontSize: '50px'
  });
  build() {
    Row() {
      Column() {
        Text(`The width of 'Hello World': ${this.textSize.width}`)
        Text(`The height of 'Hello World': ${this.textSize.height}`)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


## getParagraphs<sup>20+</sup>

getParagraphs(styledString: StyledString, options?: TextLayoutOptions): Array\<Paragraph\>

Converts a styled string into an array of corresponding [Paragraph](../apis-arkgraphics2d/js-apis-graphics-text.md#paragraph) objects based on text layout options.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description          |
| ----- | ------ | ---- | -------------- |
| styledString | [StyledString](arkui-ts/ts-universal-styled-string.md#styledstring) | Yes  | Styled string to be converted.|
| options | [TextLayoutOptions](arkui-ts/ts-text-common.md#textlayoutoptions20) | No| Text layout options.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| Array<[Paragraph](../apis-arkgraphics2d/js-apis-graphics-text.md#paragraph)> | Array of [Paragraph](../apis-arkgraphics2d/js-apis-graphics-text.md#paragraph) objects.|

**Example**

The following example demonstrates how to use the **getParagraphs** API from **MeasureUtils** to measure text. When the content exceeds the maximum number of display lines, the text is truncated and displays a "... Full Text" indicator.

``` typescript
import { LengthMetrics } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class MyCustomSpan extends CustomSpan {
  constructor(word: string, width: number, height: number, context: UIContext) {
    super();
    this.word = word;
    this.width = width;
    this.height = height;
    this.context = context;
  }

  onMeasure(measureInfo: CustomSpanMeasureInfo): CustomSpanMetrics {
    return { width: this.width, height: this.height };
  }

  onDraw(context: DrawContext, options: CustomSpanDrawInfo) {
    let canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({
      alpha: 255,
      red: 0,
      green: 74,
      blue: 175
    });
    const font = new drawing.Font();
    font.setSize(25);
    const textBlob = drawing.TextBlob.makeFromString(this.word, font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.attachBrush(brush);
    canvas.drawRect({
      left: options.x + 10,
      right: options.x + this.context.vp2px(this.width) - 10,
      top: options.lineTop + 10,
      bottom: options.lineBottom - 10
    });
    brush.setColor({
      alpha: 255,
      red: 23,
      green: 169,
      blue: 141
    });
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, options.x + 20, options.lineBottom - 15);
    canvas.detachBrush();
  }

  setWord(word: string) {
    this.word = word;
  }

  width: number = 160;
  word: string = "drawing";
  height: number = 10;
  context: UIContext;
}

@Entry
@Component
struct Index {
  str: string =
    "Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.";
  mutableStr2 = new MutableStyledString(this.str, [
    {
      start: 0,
      length: 3,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.px(20) })
    },
    {
      start: 3,
      length: 3,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: Color.Brown })
    }
  ]);

  // Measure the number of lines a styled string can display within a specified width.
  getLineNum(styledString: StyledString, width: LengthMetrics) {
    let paragraphArr = this.getUIContext().getMeasureUtils().getParagraphs(styledString, { constraintWidth: width });
    let res = 0;
    for (let i = 0; i < paragraphArr.length; ++i) {
      res += paragraphArr[i].getLineCount();
    }
    return res;
  }

  // Determine the maximum character count that can be displayed in maxLines for a styled string.
  getCorrectIndex(styledString: MutableStyledString, maxLines: number, width: LengthMetrics) {
    let low = 0;
    let high = styledString.length - 1;
    // Use binary search.
    while (low <= high) {
      let mid = (low + high) >> 1;
      console.info("demo: get " + low + " " + high + " " + mid);
      let moreStyledString = new MutableStyledString("... Full Text", [{
        start: 4,
        length: 2,
        styledKey: StyledStringKey.FONT,
        styledValue: new TextStyle({ fontColor: Color.Blue })
      }]);
      moreStyledString.insertStyledString(0, styledString.subStyledString(0, mid));
      let lineNum = this.getLineNum(moreStyledString, LengthMetrics.px(500));
      if (lineNum <= maxLines) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return high;
  }

  mutableStrAllContent = new MutableStyledString(this.str, [
    {
      start: 0,
      length: 3,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.px(40) })
    },
    {
      start: 3,
      length: 3,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: Color.Brown })
    }
  ]);
  customSpan1: MyCustomSpan = new MyCustomSpan("Hello", 120, 10, this.getUIContext());
  mutableStrAllContent2 = new MutableStyledString(this.str, [
    {
      start: 0,
      length: 3,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontSize: LengthMetrics.px(100) })
    },
    {
      start: 3,
      length: 3,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: Color.Brown })
    }
  ]);
  controller: TextController = new TextController();
  controller2: TextController = new TextController();
  textController: TextController = new TextController();
  textController2: TextController = new TextController();

  aboutToAppear() {
    this.mutableStrAllContent2.insertStyledString(0, new StyledString(this.customSpan1));
    this.mutableStr2.insertStyledString(0, new StyledString(this.customSpan1));
  }

  build() {
    Scroll() {
      Column() {
        Text('Original text')
        Text(undefined, { controller: this.controller }).width('500px').onAppear(() => {
          this.controller.setStyledString(this.mutableStrAllContent);
        })
        Divider().strokeWidth(8).color('#F1F3F5')
        Text('After layout')
        Text(undefined, { controller: this.textController }).onAppear(() => {
          let now = this.getCorrectIndex(this.mutableStrAllContent, 3, LengthMetrics.px(500));
          if (now != this.mutableStrAllContent.length - 1) {
            let moreStyledString = new MutableStyledString("... Full Text", [{
              start: 4,
              length: 2,
              styledKey: StyledStringKey.FONT,
              styledValue: new TextStyle({ fontColor: Color.Blue })
            }]);
            moreStyledString.insertStyledString(0, this.mutableStrAllContent.subStyledString(0, now));
            this.textController.setStyledString(moreStyledString);
          } else {
            this.textController.setStyledString(this.mutableStrAllContent);
          }
        })
          .width('500px')
        Divider().strokeWidth(8).color('#F1F3F5')
        Text('Original text')
        Text(undefined, { controller: this.controller2 }).width('500px').onAppear(() => {
          this.controller2.setStyledString(this.mutableStrAllContent2);
        })
        Divider().strokeWidth(8).color('#F1F3F5')
        Text('After layout')
        Text(undefined, { controller: this.textController2 }).onAppear(() => {
          let now = this.getCorrectIndex(this.mutableStrAllContent2, 3, LengthMetrics.px(500));
          let moreStyledString = new MutableStyledString("... Full Text", [{
            start: 4,
            length: 2,
            styledKey: StyledStringKey.FONT,
            styledValue: new TextStyle({ fontColor: Color.Blue })
          }]);
          moreStyledString.insertStyledString(0, this.mutableStrAllContent2.subStyledString(0, now));
          this.textController2.setStyledString(moreStyledString);
        })
          .width('500px')
      }.width('100%')
    }
  }
}
```

