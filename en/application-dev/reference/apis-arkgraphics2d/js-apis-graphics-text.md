# @ohos.graphics.text (Text)

The Text module allows you to create complex text paragraphs, with various text styles, paragraph styles, and line break rules. It then converts the information into layout data that can be efficiently rendered on the screen.

This module provides the following classes:

- [TextStyle](#textstyle): text style, which controls the font type, size, and spacing of the text.
- [FontCollection](#fontcollection): font manager, which controls various fonts.
- [ParagraphStyle](#paragraphstyle): paragraph style, which controls the display style of a paragraph.
- [Paragraph](#paragraph): paragraph, which is constructed by calling [build()](#build) in the **ParagraphBuilder** class.
- [ParagraphBuilder](#paragraphbuilder): paragraph builder, which controls the generation of different paragraph objects.
- [TextLine](#textline): carrier of the paragraph text in lines. It is obtained by calling [getTextLines()](#gettextlines) in the **Paragraph** class.
- [Run](#run): rendering unit used for text typesetting. It is obtained by calling [getGlyphRuns()](#getglyphruns) in the **TextLine** class.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D'
```

## TextAlign

Enumerates the text alignment modes.

**System capability**: SystemCapability.Graphics.Drawing

| Name       | Value  | Description                                         |
| --------- | ---- | ---------------------------------------------- |
| LEFT      | 0    | Left-aligned.                                 |
| RIGHT     | 1    | Right-aligned.                                 |
| CENTER    | 2    | Center-aligned.                                 |
| JUSTIFY   | 3    | Justified, which means that each line (except the last line) is stretched so that every line has equal width, and the left and right margins are straight.                   |
| START     | 4    | Aligned with the start position, which depends on [TextDirection](#textdirection).|
| END       | 5    | Aligned with the end position, which depends on [TextDirection](#textdirection).|

## TextDirection

Enumerates the text directions.

**System capability**: SystemCapability.Graphics.Drawing

| Name    | Value  | Description             |
| -------- | ---- | ---------------- |
| RTL      | 0    | Right to left (RTL).|
| LTR      | 1    | Left to right (LTR).|

## BreakStrategy

Enumerates the text break strategies.

**System capability**: SystemCapability.Graphics.Drawing

| Name         | Value  | Description                                           |
| ------------- | ---- | ---------------------------------------------- |
| GREEDY        | 0    | Each line is filled as much as possible during line break. No hyphen is automatically added.          |
| HIGH_QUALITY  | 1    | Text continuity is preferentially considered during line break. If necessary, hyphens are automatically added.               |
| BALANCED      | 2    | Each line of a paragraph has the same width. If necessary, hyphens are automatically added.|

## WordBreak

Enumerates the word break types.

**System capability**: SystemCapability.Graphics.Drawing

| Name       | Value  | Description                                                                                                                 |
| ----------- | ---- | -------------------------------------------------------------------------------------------------------------------- |
| NORMAL      | 0    | Default mode. Word breaks are allowed between words as appropriate to the relevant language writing systems.                                                                 |
| BREAK_ALL   | 1    | Word breaks are allowed between any characters for non-CJK text. (CJK means Chinese, Japanese, and Korean.) This value is suitable for Asian text that contains some non-Asian text. For example, it can be used to break consecutive English characters.|
| BREAK_WORD  | 2    | Works in the same way as **BREAK_ALL**, except that it does not break unbreakable words.                                  |

## Decoration

Describes a text decoration.

**System capability**: SystemCapability.Graphics.Drawing

| Name                     | Type                                                 | Read Only| Mandatory| Description                                        |
| ------------------------- | --------------------------------------------------- | ---- | ---- | -------------------------------------------- |
| textDecoration            | [TextDecorationType](#textdecorationtype)           | Yes  | No  | Type of the decoration. The default value is **NONE**.                      |
| color                     | [common2D.Color](js-apis-graphics-common2D.md#color)| Yes  | No  | Color of the decoration. The default value is transparent.                      |
| decorationStyle           | [TextDecorationStyle](#textdecorationstyle)         | Yes  | No  | Style of the decoration. The default value is **SOLID**.                     |
| decorationThicknessScale  | number                                              | Yes  | No  | Ratio of the decoration thickness to the default value. The value is a floating point number. The default value is 1.0.|

## TextDecorationType

Enumerates the text decoration types.

**System capability**: SystemCapability.Graphics.Drawing

| Name          | Value| Description       |
| -------------- | - | ----------- |
| NONE           | 0 | No decoration is used.|
| UNDERLINE      | 1 | An underline is used for decoration.     |
| OVERLINE       | 2 | An overline is used for decoration.    |
| LINE_THROUGH   | 3 | A strikethrough is used for decoration.     |

## TextDecorationStyle

Enumerates the text decoration styles.

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Value| Description  |
| ------ | - | ------ |
| SOLID  | 0 | Solid style. |
| DOUBLE | 1 | Double style.|
| DOTTED | 2 | Dotted style.|
| DASHED | 3 | Dashed style. |
| WAVY   | 4 | Wavy style.|

## FontWeight

Enumerates the font weights.

**System capability**: SystemCapability.Graphics.Drawing

| Name | Value| Description  |
| ----- | - | ------- |
| W100  | 0 | Font weight W100.|
| W200  | 1 | Font weight W200.|
| W300  | 2 | Font weight W300.|
| W400  | 3 | Font weight W400.|
| W500  | 4 | Font weight W500.|
| W600  | 5 | Font weight W600.|
| W700  | 6 | Font weight W700.|
| W800  | 7 | Font weight W800.|
| W900  | 8 | Font weight W900.|

## FontStyle

Enumerates the font styles.

**System capability**: SystemCapability.Graphics.Drawing

| Name   | Value| Description                                                |
| ------- | - | ---------------------------------------------------- |
| NORMAL  | 0 | Normal style.                                           |
| ITALIC  | 1 | Italic. If no italic version is available for the current font, the oblique version will be used instead. |
| OBLIQUE | 2 | Oblique. If no oblique version is available for the current font, the italic version will be used instead.|

## TextBaseline

Enumerates the text baseline types.

**System capability**: SystemCapability.Graphics.Drawing

| Name       | Value| Description|
| ----------- | - | ---- |
| ALPHABETIC  | 0 | Alphabetic baseline, where the letters in Latin alphabets sit on.|
| IDEOGRAPHIC | 1 | Ideographic baseline, where the baseline is at the bottom of the text area. It is usually used for CJK text.|

## EllipsisMode

Enumerates the ellipsis styles.

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Value| Description     |
| ------ | - | --------- |
| START  | 0 | Places the ellipsis in the text header.|
| MIDDLE | 1 | Places the ellipsis in the middle of the text.|
| END    | 2 | Places the ellipsis at the end of the text.|

## TextStyle

Describes a text style.

**System capability**: SystemCapability.Graphics.Drawing

| Name                     | Type                                    | Read Only| Mandatory| Description                                                  |
| ------------- | ---------------------------------------------------- | -- | -- | --------------------------------------------------------- |
| decoration    | [Decoration](#decoration)                            | Yes| No| Text decoration. The default value is the initial decoration.            |
| color         | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes| No| Font color. The default color is white.                        |
| fontWeight    | [FontWeight](#fontweight)                            | Yes| No| Font weight. The default value is **W400**.                         |
| fontStyle     | [FontStyle](#fontstyle)                              | Yes| No| Font style. The default value is **NORMAL**.                         |
| baseline      | [TextBaseline](#textbaseline)                        | Yes| No| Text baseline type. The default value is **ALPHABETIC**.              |
| fontFamilies  | Array\<string>                                       | Yes| No| Font families. The default value is the system fonts.                   |
| fontSize      | number                                               | Yes| No| Font size, in units of logical pixels. The value is a floating point number. The default value is **14.0**.  |
| letterSpacing | number                                               | Yes| No| Letter spacing, in units of logical pixels. The value is a floating point number. The default value is **0.0**. A positive value causes characters to spread farther apart, and a negative value bring characters closer together.|
| wordSpacing   | number                                               | Yes| No| Word spacing, in units of logical pixels. The value is a floating point number. The default value is **0.0**.                |
| heightScale   | number                                               | Yes| No| Scale factor of the line height. The value is a floating point number. The default value is **1.0**.             |
| halfLeading   | boolean                                              | Yes| No| Whether half leading is enabled. Half leading is the leading split in half and applied equally to the top and bottom edges. The value **true** means that half leading is enabled, and **false** means the opposite. The default value is **false**.|
| heightOnly    | boolean                                              | Yes| No| How the height of the text box is calculated. The value **true** means that the height of the text box is calculated based on the font size, and **false** means that the height is calculated based on the line height and line spacing. The default value is **false**.|
| ellipsis      | string                                               | Yes| No| Ellipsis content, which will be used to replace the extra content.      |
| ellipsisMode  | [EllipsisMode](#ellipsismode)                        | Yes| No| Ellipsis type. The default value is **END**.                       |
| locale        | string                                               | Yes| No| Locale, for example, **'en'**. For details, see the ISO 639-1 specifications. The default value is a null string.|

## FontCollection

Implements a font manager.

### loadFontSync

loadFontSync(name: string, path: string | Resource): void

Loads a font. This API returns the result synchronously.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type              | Mandatory| Description                             |
| ----- | ------------------ | ---- | --------------------------------------------------------------------------------- |
| name  | string             | Yes  | Name of the font.                                               |
| path  | string \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource) | Yes  | Path of the font file to import. The value must be **File://***absolute path of the font file* or **rawfile/***directory or file name*.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let fontCollection = new text.FontCollection;
  fontCollection.loadFontSync('test', 'File://');
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

## ParagraphStyle

Describes a paragraph style.

**System capability**: SystemCapability.Graphics.Drawing

| Name         | Type              | Read Only| Mandatory| Description                                 |
| ------------- | ----------------- | ---- | ---- | ------------------------------------ |
| textStyle     | [TextStyle](#textstyle)         | Yes  | No  | Text style applied to the paragraph. The default value is the initial text style.|
| textDirection | [TextDirection](#textdirection) | Yes  | No  | Text direction. The default value is **LTR**.              |
| align         | [TextAlign](#textalign)         | Yes  | No  | Text alignment mode. The default value is **START**.          |
| wordBreak     | [WordBreak](#wordbreak)         | Yes  | No  | Word break type. The default value is **BREAK_WORD**.              |
| maxLines      | number                          | Yes  | No  | Maximum number of lines. The value is an integer. The default value is **1e9**.          |
| breakStrategy | [BreakStrategy](#breakstrategy) | Yes  | No  | Text break strategy. The default value is **GREEDY**.              |

## PlaceholderAlignment

Enumerates the vertical alignment modes of a placeholder relative to the surrounding text.

**System capability**: SystemCapability.Graphics.Drawing

| Name               | Value| Description                  |
| ------------------- | - | ---------------------- |
| OFFSET_AT_BASELINE  | 0 | Aligns the baseline of the placeholder to the baseline of the text.    |
| ABOVE_BASELINE      | 1 | Aligns the bottom edge of the placeholder to the baseline of the text.  |
| BELOW_BASELINE      | 2 | Aligns the top edge of the placeholder to the baseline of the text.  |
| TOP_OF_ROW_BOX      | 3 | Aligns the top edge of the placeholder to the bottom edge of the text.  |
| BOTTOM_OF_ROW_BOX   | 4 | Aligns the bottom edge of the placeholder to the bottom edge of the text.  |
| CENTER_OF_ROW_BOX   | 5 | Aligns the middle of the placeholder to the middle of the text.|

![image_PlaceholderAlignment.png](figures/image_PlaceholderAlignment.png)

> **NOTE**
>
> The preceding figure shows only the last three alignment modes. The first three alignment modes are similar. The only difference is that the comparison position changes to the text baseline, which is the green line shown below.
>
>![image_Baseline.png](figures/image_Baseline.png)

## PlaceholderSpan

Describes the carrier of a placeholder style.

**System capability**: SystemCapability.Graphics.Drawing

| Name          | Type                                          | Read Only| Mandatory| Description                        |
| -------------- | --------------------------------------------- | ---- | --- | --------------------------- |
| width          | number                                        | Yes  | Yes  | Width of the placeholder, in units of logical pixels. The value is a floating point number.|
| height         | number                                        | Yes  | Yes  | Height of the placeholder, in units of logical pixels. The value is a floating point number.|
| align          | [PlaceholderAlignment](#placeholderalignment) | Yes  | Yes  | Vertical alignment of the placeholder relative to the surrounding text.|
| baseline       | [TextBaseline](#textbaseline)                 | Yes  | Yes  | Type of the text baseline.                  |
| baselineOffset | number                                        | Yes  | Yes  | Offset to the text baseline, in units of logical pixels. The value is a floating point number. |

## Range

Describes a left-closed and right-open interval.

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Type  | Read Only| Mandatory| Description           |
| ----- | ------ | ---- | --- | --------------- |
| start | number | Yes  | Yes  | Index of the leftmost point of the interval. The value is an integer.|
| end   | number | Yes  | Yes  | Index of the rightmost point of the interval. The value is an integer.|

## Paragraph

Implements a carrier that stores the text content and style. You can perform operations such as typography and drawing.

Before calling any of the following APIs, you must use [build()](#build) of the [ParagraphBuilder](#paragraphbuilder) class to create a **Paragraph** object.

### layoutSync

layoutSync(width: number): void

Performs typography and calculates the positions of all glyphs.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description          |
| ----- | ------ | ---- | -------------- |
| width | number | Yes  | Maximum width of a single line, in units of logical pixels. The value is a floating point number.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  paragraph.layoutSync(100);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### paint

paint(canvas: drawing.Canvas, x: number, y: number): void

Paints the text on the canvas with the coordinate point (x, y) as the upper left corner.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                 | Mandatory| Description                   |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | Yes  | Target canvas.        |
|    x   | number                                               | Yes  | X coordinate of the upper left corner. The value is a floating point number.|
|    y   | number                                               | Yes  | Y coordinate of the upper left corner. The value is a floating point number.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function Text() {
  const color: ArrayBuffer = new ArrayBuffer(160000);
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 200, width: 200 } }
  let pixelMap: image.PixelMap = image.createPixelMapSync(color, opts);
  let canvas = new drawing.Canvas(pixelMap);
  paragraph.paint(canvas, 0, 0);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getMaxWidth

getMaxWidth(): number

Obtains the maximum width of the line in the text.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description      |
| ------ | --------- |
| number | Maximum line width, in units of logical pixels. The value is a floating point number.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let maxWidth = paragraph.getMaxWidth();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getHeight

getHeight(): number

Obtains the total height of the text.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description  |
| ------ | ----- |
| number | Total height, in units of logical pixels. The value is a floating point number.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let height = paragraph.getHeight();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getLongestLine

getLongestLine(): number

Obtains the longest line in the text.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description          |
| ------ | ------------- |
| number | Longest line, in units of logical pixels. The value is a floating point number.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let longestLine = paragraph.getLongestLine();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getMinIntrinsicWidth

getMinIntrinsicWidth(): number

Obtains the minimum intrinsic width of the paragraph.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description                          |
| ------ | ----------------------------- |
| number | Minimum intrinsic width, in units of logical pixels. The value is a floating point number.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let minIntrinsicWidth = paragraph.getMinIntrinsicWidth();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getMaxIntrinsicWidth

getMaxIntrinsicWidth(): number

Obtains the maximum intrinsic width of the paragraph.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description                          |
| ------ | ----------------------------- |
| number | Maximum intrinsic width, in units of logical pixels. The value is a floating point number.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let maxIntrinsicWidth = paragraph.getMaxIntrinsicWidth();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getAlphabeticBaseline

getAlphabeticBaseline(): number

Obtains the alphabetic baseline.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description               |
| ------ | ------------------ |
| number | Alphabetic baseline, in units of logical pixels. The value is a floating point number.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let alphabeticBaseline = paragraph.getAlphabeticBaseline();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getIdeographicBaseline

getIdeographicBaseline(): number

Obtains the ideographic baseline.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description                 |
| ------ | -------------------- |
| number | Ideographic baseline, in units of logical pixels. The value is a floating point number.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let ideographicBaseline = paragraph.getIdeographicBaseline();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getRectsForRange

getRectsForRange(range: Range, widthStyle: RectWidthStyle, heightStyle: RectHeightStyle): Array\<TextBox>

Obtains the rectangles occupied by the characters in the range of the text under the given rectangle width and height.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name     | Type                                | Mandatory| Description                    |
| ----------- | ----------------------------------- | ---- | ------------------------ |
| range       | [Range](#range)                     | Yes  | Range of the text. |
| widthStyle  | [RectWidthStyle](#rectwidthstyle)   | Yes  | Width of the rectangle.|
| heightStyle | [RectHeightStyle](#rectheightstyle) | Yes  | Height of the rectangle.|

**Return value**

| Type                        | Description       |
| --------------------------- | ----------- |
| Array\<[TextBox](#textbox)> | Array holding the rectangles obtained.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let range: text.Range = { start: 0, end: 1};
  let rects = paragraph.getRectsForRange(range, text.RectWidthStyle.TIGHT, text.RectHeightStyle.TIGHT);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getRectsForPlaceholders

getRectsForPlaceholders(): Array\<TextBox>

Obtains the rectangles occupied by all placeholders in the text.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                        | Description       |
| --------------------------- | ----------- |
| Array\<[TextBox](#textbox)> | Array holding the rectangles obtained.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let placeholderRects = paragraph.getRectsForPlaceholders();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getGlyphPositionAtCoordinate

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

Obtains the position of a glyph close to a given coordinate.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description  |
| ----- | ------ | ---- | ------ |
| x     | number | Yes  | X coordinate. The value is a floating point number.|
| y     | number | Yes  | Y coordinate. The value is a floating point number.|

**Return value**

| Type                                         | Description       |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity) | Position of the glyph.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let positionWithAffinity = paragraph.getGlyphPositionAtCoordinate(0, 0);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getWordBoundary

getWordBoundary(offset: number): Range

Obtains the range of the word where the glyph with a given offset is located.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description       |
| ------ | ------ | ---- | ----------- |
| offset | number | Yes  | Offset of the glyph. The value is an integer.|

**Return value**

| Type           | Description           |
| --------------- | -------------- |
| [Range](#range) | Range of the word.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let wordRange = paragraph.getWordBoundary(0);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getLineCount

getLineCount(): number

Obtains the number of text lines.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description      |
| ------ | --------- |
| number | Number of text lines. The value is an integer.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let lineCount = paragraph.getLineCount();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getLineHeight

getLineHeight(line: number): number

Obtains the height of a given line.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description     |
| ----- | ------ | ---- | --------- |
| line  | number | Yes  | Index of the line. The value is an integer.|

**Return value**

| Type  | Description |
| ------ | ---- |
| number | Line height.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let lineHeight = paragraph.getLineHeight(0);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getLineWidth

getLineWidth(line: number): number

Obtains the width of a given line.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description     |
| ----- | ------ | ---- | --------- |
| line  | number | Yes  | Index of the line. The value is an integer.|

**Return value**

| Type  | Description |
| ------ | ---- |
| number | Line width.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let lineWidth = paragraph.getLineWidth(0);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### didExceedMaxLines

didExceedMaxLines(): boolean

Checks whether the number of lines in the paragraph exceeds the maximum.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type   | Description                                                     |
| ------- | -------------------------------------------------------- |
| boolean | **true**: The number of lines exceeds the maximum.<br>**false**: The number of lines does not exceed the maximum.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let didExceed = paragraph.didExceedMaxLines();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getTextLines

getTextLines(): Array\<TextLine>

Obtains all the text lines.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                         | Description         |
| ----------------------------- | ------------- |
| Array\<[TextLine](#textline)> | Array of text lines.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let lines = paragraph.getTextLines();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

## TextBox

Describes the rectangle that holds the text.

**System capability**: SystemCapability.Graphics.Drawing

| Name     | Type                                               | Read Only| Mandatory| Description       |
| --------- | -------------------------------------------------- | ---- | ---- | ----------- |
| rect      | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Yes  | Information about the rectangle.|
| direction | [TextDirection](#textdirection)                    | Yes  | Yes  | Text direction.   |

## PositionWithAffinity

Describes the position and affinity of a glyph.

**System capability**: SystemCapability.Graphics.Drawing

| Name     | Type                  | Read Only| Mandatory| Description                     |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | Yes  | Yes  | Index of the glyph relative to the paragraph. The value is an integer. |
| affinity  | [Affinity](#affinity) | Yes  | Yes  | Affinity of the position.              |

## RectWidthStyle

Enumerates the rectangle width styles.

**System capability**: SystemCapability.Graphics.Drawing

| Name | Value| Description                                  |
| ----- | - | -------------------------------------- |
| TIGHT | 0 | Tight style.                           |
| MAX   | 1 | Extends the width to match the widest rectangle in all lines.  |

## RectHeightStyle

Enumerates the rectangle height styles.

**System capability**: SystemCapability.Graphics.Drawing

| Name                     | Value| Description                                          |
| ------------------------- | - | ---------------------------------------------- |
| TIGHT                     | 0 | Tight style.                                   |
| MAX                       | 1 | Extends the height to match the highest rectangle in all lines.          |
| INCLUDE_LINE_SPACE_MIDDLE | 2 | Includes half of the line spacing to both the top and bottom of the rectangle.|
| INCLUDE_LINE_SPACE_TOP    | 3 | Includes the line spacing to the top of the rectangle.                     |
| INCLUDE_LINE_SPACE_BOTTOM | 4 | Includes the line spacing to the bottom of the rectangle.                     |
| STRUT                     | 5 | Sets the height according to the strut style.                         |

## Affinity

Enumerates the affinity modes.

**System capability**: SystemCapability.Graphics.Drawing

| Name      | Value| Description                         |
| ---------- | - | ----------------------------- |
| UPSTREAM   | 0 | The position has affinity for the upstream side of the text position.|
| DOWNSTREAM | 1 | The position has affinity for the downstream side of the text position.|

## ParagraphBuilder

Implements a paragraph builder.

### constructor

constructor(paragraphStyle: ParagraphStyle, fontCollection: FontCollection)

A constructor used to create a **ParagraphBuilder** object.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name        | Type                              | Mandatory| Description       |
| -------------- | --------------------------------- | ---- | ----------- |
| paragraphStyle | [ParagraphStyle](#paragraphstyle) | Yes  | Paragraph style.  |
| fontCollection | [FontCollection](#fontcollection) | Yes  | Font manager.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: 3,
  };
  let fontCollection = new text.FontCollection();
  let ParagraphGraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### pushStyle

 pushStyle(textStyle: TextStyle): void

Pushes a text style.

> **NOTE**
>
> This API pushes the style of the current text blob until [popStyle](#popstyle), which restores to the previous text style, is called.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name   | Type      | Mandatory| Description                                                                                                  |
| --------- | --------- | ---- | ------------------------------------------------------------------------------------------------------ |
| textStyle | [TextStyle](textstyle) | Yes  | Text style, which describes various visual attributes of text, such as font, font size, color, font weight, word spacing, line spacing, decoration (such as underline and strikethrough), and text shadow.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function Text() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: 3,
  };
  let fontCollection = new text.FontCollection();
  let ParagraphGraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  ParagraphGraphBuilder.pushStyle(myTextStyle);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### popStyle

popStyle(): void

Restores to the previous text style.

**System capability**: SystemCapability.Graphics.Drawing

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function Text() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: 3,
  };
  let fontCollection = new text.FontCollection();
  let ParagraphGraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  ParagraphGraphBuilder.pushStyle(myTextStyle);
  ParagraphGraphBuilder.popStyle();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### addText

addText(text: string): void

Inserts a text string into the paragraph being built.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| text    | string  | Yes  | Text string to insert.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function Text() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: 3,
  };
  let fontCollection = new text.FontCollection();
  let ParagraphGraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  ParagraphGraphBuilder.addText("123666");
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### addPlaceholder

addPlaceholder(placeholderSpan: PlaceholderSpan): void

Inserts a placeholder into the paragraph being built.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type                                | Mandatory| Description                                               |
| --------------- | ----------------------------------- | ---- | --------------------------------------------------- |
| placeholderSpan | [PlaceholderSpan](#placeholderspan) | Yes  | Placeholder span, which describes the size, alignment, baseline type, and baseline offset of the placeholder. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function Text() {
  let myParagraphStyle: text.ParagraphStyle = {
    align: 3,
  };
  let myPlaceholderSpan: text.PlaceholderSpan = {
    width: 10000,
    height: 10000000,
    align: text.PlaceholderAlignment.ABOVE_BASELINE,
    baseline: text.TextBaseline.ALPHABETIC,
    baselineOffset: 100000
  };
  let fontCollection = new text.FontCollection();
  let ParagraphGraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  ParagraphGraphBuilder.addPlaceholder(myPlaceholderSpan);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### build

build(): Paragraph

Creates a paragraph object that can be used for subsequent typography and rendering.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                    | Description                          |
| ------------------------ | ------------------------------ |
| [Paragraph](#paragraph)  | **Paragraph** object that can be used for subsequent typography and rendering.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function Text() {
  let myParagraphStyle: text.ParagraphStyle = {
    align: 3,
  };
  let fontCollection = new text.FontCollection();
  let ParagraphGraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  let paragraph = ParagraphGraphBuilder.build();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

## TextLine

Implements a carrier that describes the basic text line structure of a paragraph.

Before calling any of the following APIs, you must use [getTextLines()](#gettextlines) of the [Paragraph](#paragraph) class to create a **TextLine** object.

### getGlyphCount

getGlyphCount(): number

Obtains the number of glyphs in this text line.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type   | Description              |
| ------- | ------------------ |
| number  | Number of glyphs. The value is an integer.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let GlyphCount = lines[0].getGlyphCount();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getTextRange

getTextRange(): Range

Obtains the range of the text in this text line in the entire paragraph.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type            | Description                                             |
| ---------------- | ------------------------------------------------ |
| [Range](#range)  | Range of the text in this text line in the entire paragraph.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let textRange = lines[0].getTextRange();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getGlyphRuns

getGlyphRuns(): Array\<Run>

Obtains the glyph runs in this text line.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type        | Description                        |
| ------------ | --------------------------- |
| Array\<[Run](#run)>  | Array of the glyph runs obtained.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let runs = lines[0].getGlyphRuns();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### paint

paint(canvas: drawing.Canvas, x: number, y: number): void

Paints this text line on the canvas with the coordinate point (x, y) as the upper left corner.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                 | Mandatory| Description                   |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | Yes  | Target canvas.     |
|    x   | number                                               | Yes  | X coordinate of the upper left corner. The value is a floating point number.|
|    y   | number                                               | Yes  | Y coordinate of the upper left corner. The value is a floating point number.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function Text() {
  const color: ArrayBuffer = new ArrayBuffer(160000);
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 200, width: 200 } }
  let pixelMap: image.PixelMap = image.createPixelMapSync(color, opts);
  let canvas = new drawing.Canvas(pixelMap);
  lines[0].paint(canvas, 0, 0);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

## Run

Implements a rendering unit for text typesetting.

Before calling any of the following APIs, you must use [getGlyphRuns()](#getglyphruns) of the [TextLine](#textline) class to create a **Run** object.

### getGlyphCount

getGlyphCount(): number

Obtains the number of glyphs in this glyph run.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type    | Description               |
| ------- | -------------------- |
| number  | Number of glyphs. The value is an integer.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let glyphs = runs[0].getGlyphCount();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getGlyphs

getGlyphs(): Array\<number>

Obtains the index of each glyph in this glyph run.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type           | Description                            |
| --------------- | -------------------------------- |
| Array\<number>  | Array holding the index of each glyph in this glyph run.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let glyph = runs[0].getGlyphs();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getPositions

getPositions(): Array<common2D.Point>

Obtains the index of each glyph relative to the respective line in this glyph run.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                  | Description                                  |
| ---------------------- | ------------------------------------- |
| Array<[common2D.Point](js-apis-graphics-common2D.md#point12)>  | Array holding the index of each glyph relative to the respective line in this glyph run.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let positions = runs[0].getPositions();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getOffsets

getOffsets(): Array<common2D.Point>

Obtains the offset of each glyph in this glyph run relative to its index.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                  | Description          |
| ---------------------- | -------------- |
| Array<[common2D.Point](js-apis-graphics-common2D.md#point12)>  | Array holding the offset of each glyph in this glyph run relative to its index.|

**Example**

```ts
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let offsets = runs[0].getOffsets();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### getFont

getFont(): drawing.Font

Obtains the **Font** object of this glyph run.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                  | Description          |
| ------------------------------------------------- | -------------------------- |
| [drawing.Font](js-apis-graphics-drawing.md#font)  | **Font** object of this glyph run.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D";

function Text() {
  let font = runs[0].getFont();
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### paint

paint(canvas: drawing.Canvas, x: number, y: number): void

Paints this glyph run on the canvas with the coordinate point (x, y) as the upper left corner.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                 | Mandatory| Description                   |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | Yes  | Target canvas.     |
|    x   | number                                               | Yes  | X coordinate of the upper left corner. The value is a floating point number.|
|    y   | number                                               | Yes  | Y coordinate of the upper left corner. The value is a floating point number.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function Text() {
  const color: ArrayBuffer = new ArrayBuffer(160000);
  let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 200, width: 200 } }
  let pixelMap: image.PixelMap = image.createPixelMapSync(color, opts);
  let canvas = new drawing.Canvas(pixelMap);
  runs[0].paint(canvas, 0, 0);
}

@Entry
@Component
struct Index {
  @State fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```
