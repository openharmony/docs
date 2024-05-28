# @ohos.graphics.text (文本模块)

本模块允许开发者创建复杂的文本段落，包括多样的文本样式、段落样式、换行规则等，并最终将这些信息转换为能在屏幕上高效渲染的布局数据。

该模块提供以下创建复杂的文本段落的常用功能：

- [TextStyle](#textstyle)：文本样式，控制文本的字体类型、大小、间距等属性。
- [FontCollection](#fontcollection)：字体管理器，控制各种不同的字体。
- [ParagraphStyle](#paragraphstyle)：段落样式，控制整个段落的显示样式。
- [Paragraph](#paragraph)：段落，由段落生成器类调用[build()](#build)接口构建而成。
- [ParagraphBuilder](#paragraphbuilder)：段落生成器，控制生成不同的段落对象。
- [TextLine](#textline)：以行为单位的段落文本的载体，由段落类调用[getTextLines()](#gettextlines)接口获取。
- [Run](#run)：文本排版的渲染单元，由行文本类调用[getGlyphRuns()](#getglyphruns)接口获取。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { drawing } from '@kit.ArkGraphics2D'
```

## TextAlign

文本对齐方式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称        | 值   | 说明                                          |
| --------- | ---- | ---------------------------------------------- |
| LEFT      | 0    | 文本靠左对齐。                                  |
| RIGHT     | 1    | 文本靠右对齐。                                  |
| CENTER    | 2    | 文本居中对齐。                                  |
| JUSTIFY   | 3    | 文本两侧对齐，对最后一行无效。                    |
| START     | 4    | 基于文本的方向[TextDirection](#textdirection)，文本靠开头方向对齐。 |
| END       | 5    | 基于文本的方向[TextDirection](#textdirection)，文本以结束方向对齐。 |

## TextDirection

文本排版方向枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称     | 值   | 说明              |
| -------- | ---- | ---------------- |
| RTL      | 0    | 文本从右到左排版。 |
| LTR      | 1    | 文本从左到右排版。 |

## BreakStrategy

断行策略枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称          | 值   | 说明                                            |
| ------------- | ---- | ---------------------------------------------- |
| GREEDY        | 0    | 尽可能将当前行填满，不会自动添加连词符。           |
| HIGH_QUALITY  | 1    | 布局优化，必要时会自动添加连词符。                |
| BALANCED      | 2    | 保证一个段落的每一行的宽度相同，必要时会添加连词符。|

## WordBreak

断词策略枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称        | 值   | 说明                                                                                                                  |
| ----------- | ---- | -------------------------------------------------------------------------------------------------------------------- |
| NORMAL      | 0    | 默认的换行规则。依据各自语言的规则，允许在字间发生换行。                                                                  |
| BREAK_ALL   | 1    | 对于 Non-CJK（非中文，日文，韩文）文本允许在任意字符内发生换行。该值适合包含一些非亚洲文本的亚洲文本，比如使连续的英文字符断行。|
| BREAK_WORD  | 2    | 与`BREAK_ALL`基本相同，不同的地方在于它要求一个没有断行破发点的词必须保持为一个整体单位。                                   |

## Decoration

文本装饰线。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                      | 类型                                                  | 只读 | 必填 | 说明                                         |
| ------------------------- | --------------------------------------------------- | ---- | ---- | -------------------------------------------- |
| textDecoration            | [TextDecorationType](#textdecorationtype)           | 是   | 否   | 装饰线类型，默认为NONE。                       |
| color                     | [common2D.Color](js-apis-graphics-common2D.md#color)| 是   | 否   | 装饰线颜色，默认为透明。                       |
| decorationStyle           | [TextDecorationStyle](#textdecorationstyle)         | 是   | 否   | 装饰线样式，默认为SOLID。                      |
| decorationThicknessScale  | number                                              | 是   | 否   | 装饰线粗细相对于默认值的比例，浮点数，默认为1.0。|

## TextDecorationType

装饰线类型枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称           | 值 | 说明        |
| -------------- | - | ----------- |
| NONE           | 0 | 装饰线不生效。|
| UNDERLINE      | 1 | 下划线。      |
| OVERLINE       | 2 | 上划线。     |
| LINE_THROUGH   | 3 | 删除线。      |

## TextDecorationStyle

装饰线样式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 值 | 说明   |
| ------ | - | ------ |
| SOLID  | 0 | 实线。  |
| DOUBLE | 1 | 双层线。|
| DOTTED | 2 | 点状线。|
| DASHED | 3 | 虚线。  |
| WAVY   | 4 | 波浪线。|

## FontWeight

字重枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称  | 值 | 说明   |
| ----- | - | ------- |
| W100  | 0 | 100字重。|
| W200  | 1 | 200字重。|
| W300  | 2 | 300字重。|
| W400  | 3 | 400字重。|
| W500  | 4 | 500字重。|
| W600  | 5 | 600字重。|
| W700  | 6 | 700字重。|
| W800  | 7 | 800字重。|
| W900  | 8 | 900字重。|

## FontStyle

字体样式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称    | 值 | 说明                                                 |
| ------- | - | ---------------------------------------------------- |
| NORMAL  | 0 | 常规样式。                                            |
| ITALIC  | 1 | 斜体，如果当前字体没有可用的斜体版本，会选用倾斜体替代。  |
| OBLIQUE | 2 | 倾斜体，如果当前字体没有可用的倾斜体版本，会选用斜体替代。|

## TextBaseline

文本基线类型枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称        | 值 | 说明 |
| ----------- | - | ---- |
| ALPHABETIC  | 0 | 通常用于拉丁字母的文本基线对齐。|
| IDEOGRAPHIC | 1 | 通常用于CJK（中文，日文，韩文）的文本基线对齐。|

## EllipsisMode

省略号类型枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 值 | 说明      |
| ------ | - | --------- |
| START  | 0 | 开头省略号。|
| MIDDLE | 1 | 中间省略号。|
| END    | 2 | 末尾省略号。|

## TextStyle

文本样式。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                      | 类型                                     | 只读 | 必填 | 说明                                                   |
| ------------- | ---------------------------------------------------- | -- | -- | --------------------------------------------------------- |
| decoration    | [Decoration](#decoration)                            | 是 | 否 | 装饰线置，默认初始的Decoration。             |
| color         | [common2D.Color](js-apis-graphics-common2D.md#color) | 是 | 否 | 字体色，默认为白色。                         |
| fontWeight    | [FontWeight](#fontweight)                            | 是 | 否 | 字重，默认为W400。                          |
| fontStyle     | [FontStyle](#fontstyle)                              | 是 | 否 | 字体样式，默认为常规样式。                          |
| baseline      | [TextBaseline](#textbaseline)                        | 是 | 否 | 文本基线型，默认为ALPHABETIC。               |
| fontFamilies  | Array\<string>                                       | 是 | 否 | 字体类型，默认为系统字体。                    |
| fontSize      | number                                               | 是 | 否 | 字体大小，浮点数，默认为14.0，单位为逻辑像素。  |
| letterSpacing | number                                               | 是 | 否 | 字符间距，正数拉开字符距离，若是负数则拉近字符距离，浮点数，默认为0.0，单位为逻辑像素。|
| wordSpacing   | number                                               | 是 | 否 | 单词间距，浮点数，默认为0.0，单位为逻辑像素。                 |
| heightScale   | number                                               | 是 | 否 | 行高缩放倍数，浮点数，默认为1.0。              |
| halfLeading   | boolean                                              | 是 | 否 | true表示将行间距平分至行的顶部与底部，false则不平分，默认为false。|
| heightOnly    | boolean                                              | 是 | 否 | true表示根据字体大小计算文本框的高度，false表示根据行高和行距，默认为false。|
| ellipsis      | string                                               | 是 | 否 | 省略号样式，表示省略号生效后使用该字段值替换省略号部分。       |
| ellipsisMode  | [EllipsisMode](#ellipsismode)                        | 是 | 否 | 省略号类型，默认为END。                        |
| locale        | string                                               | 是 | 否 | 语言类型，如'en'，具体请参照ISO 639-1规范，默认为空字符串。|

## FontCollection

字体管理器。

### getGlobalInstance

static getGlobalInstance(): FontCollection

获取应用全局FontCollection的实例。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                |
| ------ | ------------------ |
| [FontCollection](#fontcollection) | FontCollection对象。|

**示例：**

```ts
import { text } from "@kit.ArkGraphics2D"

function Text() {
  let fontCollection = text.FontCollection.getGlobalInstance();
  fontCollection.loadFontSync('test', 'File://');
}

@Entry
@Component
struct Index {
  fun: Function = Text;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### loadFontSync

loadFontSync(name: string, path: string | Resource): void

同步接口，将路径的文件，以name作为使用的别名，加载成字体。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型               | 必填 | 说明                              |
| ----- | ------------------ | ---- | --------------------------------------------------------------------------------- |
| name  | string             | 是   | 加载成字体后，调用该字体所使用的命名。                                                |
| path  | string \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource) | 是   | 需要导入的字体文件的路径，应为 "File:// + 字体文件绝对路径" 或 "rawfile/目录or文件名"。 |

**示例：**

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

段落样式。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称          | 类型               | 只读 | 必填 | 说明                                  |
| ------------- | ----------------- | ---- | ---- | ------------------------------------ |
| textStyle     | [TextStyle](#textstyle)         | 是   | 否   | 作用于整个段落的文本样式，默认为初始的TextStyle。|
| textDirection | [TextDirection](#textdirection) | 是   | 否   | 文本方向，默认为LTR。               |
| align         | [TextAlign](#textalign)         | 是   | 否   | 文本对齐方式，默认为START。           |
| wordBreak     | [WordBreak](#wordbreak)         | 是   | 否   | 断词类型，默认为BREAK_WORD。               |
| maxLines      | number                          | 是   | 否   | 最大行数限制，整数，默认为1e9。           |
| breakStrategy | [BreakStrategy](#breakstrategy) | 是   | 否   | 断行策略，默认为GREEDY。               |

## PlaceholderAlignment

占位符相对于周围文本的纵向的对齐方式。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                | 值 | 说明                   |
| ------------------- | - | ---------------------- |
| OFFSET_AT_BASELINE  | 0 | 基线与文本基线对齐。     |
| ABOVE_BASELINE      | 1 | 将底部与文本基线对齐。   |
| BELOW_BASELINE      | 2 | 将顶部与文本基线对齐。   |
| TOP_OF_ROW_BOX      | 3 | 将顶部与文本顶部对齐。   |
| BOTTOM_OF_ROW_BOX   | 4 | 将底部与文本底部对齐。   |
| CENTER_OF_ROW_BOX   | 5 | 中线与文本的中线位置对齐。|

![zh-ch_image_PlaceholderAlignment.png](figures/zh-ch_image_PlaceholderAlignment.png)

> **说明：**
>
> 示意图只展示了后三种，前三种与其类似，只不过比较位置变成了文本基线位置，即绿色线条部分。
>
>![zh-ch_image_Baseline.png](figures/zh-ch_image_Baseline.png)

## PlaceholderSpan

描述占位符样式的载体。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称           | 类型                                           | 只读 | 必填 | 说明                         |
| -------------- | --------------------------------------------- | ---- | --- | --------------------------- |
| width          | number                                        | 是   | 是   | 占位符的宽度，浮点数，单位为逻辑像素。|
| height         | number                                        | 是   | 是   | 占位符的高度，浮点数，单位为逻辑像素。|
| align          | [PlaceholderAlignment](#placeholderalignment) | 是   | 是   | 相对于周围文本的纵向的对齐方式。|
| baseline       | [TextBaseline](#textbaseline)                 | 是   | 是   | 基线类型。                   |
| baselineOffset | number                                        | 是   | 是   | 基线偏移量，浮点数，单位为逻辑像素。  |

## Range

描述一个左闭右开的区间。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 类型   | 只读 | 必填 | 说明            |
| ----- | ------ | ---- | --- | --------------- |
| start | number | 是   | 是   | 区间左侧端点索引，整数。|
| end   | number | 是   | 是   | 区间右侧端点索引，整数。|

## Paragraph

保存着文本内容以及样式的载体，可以进行排版绘制等操作。

下列API示例中都需先使用[ParagraphBuilder](#paragraphbuilder)类的[build()](#build)接口获取到Paragraph对象实例，再通过此实例调用对应方法。

### layoutSync

layoutSync(width: number): void

进行排版，计算所有字形的位置。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ----- | ------ | ---- | -------------- |
| width | number | 是   | 单行的最大宽度，浮点数，单位为逻辑像素。|

**示例：**

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

在画布上以坐标点 (x, y) 为左上角位置绘制文本。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                    |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | 是   | 绘制的目标画布。         |
|    x   | number                                               | 是   | 绘制的左上角位置的横坐标，浮点数。|
|    y   | number                                               | 是   | 绘制的左上角位置的纵坐标，浮点数。|

**示例：**

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

获取文本最大的行宽。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明       |
| ------ | --------- |
| number | 最大的行宽，浮点数，单位为逻辑像素。|

**示例：**

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

获取文本总高度。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明   |
| ------ | ----- |
| number | 总高度，浮点数，单位为逻辑像素。|

**示例：**

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

获取文本最长一行的宽度。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明           |
| ------ | ------------- |
| number | 最长一行的宽度，浮点数，单位为逻辑像素。|

**示例：**

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

获取该段落所占水平空间的最小固有宽度。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                           |
| ------ | ----------------------------- |
| number | 该段落所占水平空间的最小固有宽度，浮点数，单位为逻辑像素。|

**示例：**

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

获取该段落所占水平空间的最大固有宽度。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                           |
| ------ | ----------------------------- |
| number | 该段落所占水平空间的最大固有宽度，浮点数，单位为逻辑像素。|

**示例：**

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

获取拉丁字母下的基线位置。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                |
| ------ | ------------------ |
| number | 拉丁字母下的基线位置，浮点数，单位为逻辑像素。|

**示例：**

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

获取表意字（如CJK（中文，日文，韩文））下的基线位置。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                  |
| ------ | -------------------- |
| number | 获取表意字下的基线位置，浮点数，单位为逻辑像素。|

**示例：**

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

获取给定的矩形区域宽度以及矩形区域高度的规格下，文本中该区间范围内的字符的所占的矩形区域。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名      | 类型                                 | 必填 | 说明                     |
| ----------- | ----------------------------------- | ---- | ------------------------ |
| range       | [Range](#range)                     | 是   | 需要获取的区域的文本区间。  |
| widthStyle  | [RectWidthStyle](#rectwidthstyle)   | 是   | 返回的矩形区域的宽度的规格。|
| heightStyle | [RectHeightStyle](#rectheightstyle) | 是   | 返回的矩形区域的高度的规格。|

**返回值：**

| 类型                         | 说明        |
| --------------------------- | ----------- |
| Array\<[TextBox](#textbox)> | 矩形区域数组。|

**示例：**

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

获取文本中所有占位符所占的矩形区域。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                         | 说明        |
| --------------------------- | ----------- |
| Array\<[TextBox](#textbox)> | 矩形区域数组。|

**示例：**

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

获取较为接近给定坐标的字形的位置信息。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明   |
| ----- | ------ | ---- | ------ |
| x     | number | 是   | 横坐标，浮点数。|
| y     | number | 是   | 纵坐标，浮点数。|

**返回值：**

| 类型                                          | 说明        |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity) | 字形位置信息。|

**示例：**

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

返回给定的 offset 的字形所处的单词的索引区间。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型    | 必填 | 说明        |
| ------ | ------ | ---- | ----------- |
| offset | number | 是   | 字形的偏移量，整数。|

**返回值：**

| 类型            | 说明            |
| --------------- | -------------- |
| [Range](#range) | 单词的索引区间。|

**示例：**

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

返回文本行数量。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明       |
| ------ | --------- |
| number | 文本行数量，整数。|

**示例：**

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

返回指定行索引的行高。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ----- | ------ | ---- | --------- |
| line  | number | 是   | 文本行索引，整数。|

**返回值：**

| 类型   | 说明  |
| ------ | ---- |
| number | 行高。|

**示例：**

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

返回指定行索引的行宽。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ----- | ------ | ---- | --------- |
| line  | number | 是   | 文本行索引，整数。|

**返回值：**

| 类型   | 说明  |
| ------ | ---- |
| number | 行宽。|

**示例：**

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

返回段落是否超过最大行限制。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型    | 说明                                                      |
| ------- | -------------------------------------------------------- |
| boolean | true表示段落超出了最大行限制，false则表示没有超出最大行限制。 |

**示例：**

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

返回所有的文本行载体。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                          | 说明          |
| ----------------------------- | ------------- |
| Array\<[TextLine](#textline)> | 文本行载体数组。|

**示例：**

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

文本矩形区域。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称      | 类型                                                | 只读 | 必填 | 说明        |
| --------- | -------------------------------------------------- | ---- | ---- | ----------- |
| rect      | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是   | 是   | 矩形区域信息。|
| direction | [TextDirection](#textdirection)                    | 是   | 是   | 文本方向。    |

## PositionWithAffinity

位置以及亲和度。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称      | 类型                   | 只读 | 必填 | 说明                      |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | 是   | 是   | 字形相对于段落的索引，整数。  |
| affinity  | [Affinity](#affinity) | 是   | 是   | 位置亲和度。               |

## RectWidthStyle

矩形区域宽度规格枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称  | 值 | 说明                                   |
| ----- | - | -------------------------------------- |
| TIGHT | 0 | 与字形紧贴。                            |
| MAX   | 1 | 扩展宽度，以匹配所有行上最宽矩形的位置。   |

## RectHeightStyle

矩形区域高度规格枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                      | 值 | 说明                                           |
| ------------------------- | - | ---------------------------------------------- |
| TIGHT                     | 0 | 与字形紧贴。                                    |
| MAX                       | 1 | 扩展高度，以匹配所有行上最高矩形的位置。           |
| INCLUDE_LINE_SPACE_MIDDLE | 2 | 每个矩形的顶部和底部将覆盖行上方和行下方的一半空间。|
| INCLUDE_LINE_SPACE_TOP    | 3 | 行间距将被添加到矩形的顶部。                      |
| INCLUDE_LINE_SPACE_BOTTOM | 4 | 行间距将被添加到矩形的底部。                      |
| STRUT                     | 5 | 高度按照文本的样式设置。                          |

## Affinity

位置亲和度枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称       | 值 | 说明                          |
| ---------- | - | ----------------------------- |
| UPSTREAM   | 0 | 该位置与文本位置的前一位有关联。 |
| DOWNSTREAM | 1 | 该位置与文本位置的后一位有关联。 |

## ParagraphBuilder

段落生成器。

### constructor

constructor(paragraphStyle: ParagraphStyle, fontCollection: FontCollection)

ParagraphBuilder对象的构造函数。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                               | 必填 | 说明        |
| -------------- | --------------------------------- | ---- | ----------- |
| paragraphStyle | [ParagraphStyle](#paragraphstyle) | 是   | 段落样式。   |
| fontCollection | [FontCollection](#fontcollection) | 是   | 字体管理器。 |

**示例：**

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

更新文本样式。

> **说明：**
>
> 更新当前文本块的样式 ，直到对应的 [popStyle](#popstyle) 操作被执行，会还原到上一个文本样式。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名    | 类型       | 必填 | 说明                                                                                                   |
| --------- | --------- | ---- | ------------------------------------------------------------------------------------------------------ |
| textStyle | [TextStyle](textstyle) | 是   | 包含了对文本的各种视觉属性的定义，如字体、字号、颜色、字重、字间距、行距、装饰（如下划线、删除线）、文本阴影等。 |

**示例：**

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

还原至上一个文本样式。

**系统能力**：SystemCapability.Graphics.Drawing

**示例：**

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

用于向正在构建的文本段落中插入具体的文本字符串。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| text    | string  | 是   | 段落中插入的具体文本字符串。 |

**示例：**

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

用于在构建文本段落时插入占位符。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名          | 类型                                 | 必填 | 说明                                                |
| --------------- | ----------------------------------- | ---- | --------------------------------------------------- |
| placeholderSpan | [PlaceholderSpan](#placeholderspan) | 是   | 定义了占位符的尺寸、对齐方式、基线类型以及基线偏移量。  |

**示例：**

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

用于完成段落的构建过程，生成一个可用于后续排版渲染的段落对象。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                     | 说明                           |
| ------------------------ | ------------------------------ |
| [Paragraph](#paragraph)  | 可用于后续渲染的 Paragraph 对象。|

**示例：**

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

描述段落基础文本行结构的载体。

下列API示例中都需先使用[Paragraph](#paragraph)类的[getTextLines()](#gettextlines)接口获取到TextLine对象实例，再通过此实例调用对应方法。

### getGlyphCount

getGlyphCount(): number

获取该文本行中字形的数量。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型    | 说明               |
| ------- | ------------------ |
| number  | 该文本行中字形数量，整数。 |

**示例：**

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

获取该文本行中的文本在整个段落文本中的索引区间。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------ |
| [Range](#range)  | 该文本行中的文本在整个段落文本中的索引区间。|

**示例：**

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

获取该文本行中的文本渲染单位数组。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型         | 说明                         |
| ------------ | --------------------------- |
| Array\<[Run](#run)>  | 该文本行中的文本渲染单位数组。|

**示例：**

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

在画布上以坐标点 (x, y) 为左上角位置绘制该文本行。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                    |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | 是   | 绘制的目标 canvas。      |
|    x   | number                                               | 是   | 绘制的左上角位置的横坐标，浮点数。|
|    y   | number                                               | 是   | 绘制的左上角位置的纵坐标，浮点数。|

**示例：**

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

文本排版的渲染单元。

下列API示例中都需先使用[TextLine](#textline)类的[getGlyphRuns()](#getglyphruns)接口获取到Run对象实例，再通过此实例调用对应方法。

### getGlyphCount

getGlyphCount(): number

获取该渲染单元中字形的数量。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型     | 说明                |
| ------- | -------------------- |
| number  | 该渲染单元中字形数量，整数。 |

**示例：**

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

获取该渲染单元中每个字符对应的字形序号。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型            | 说明                             |
| --------------- | -------------------------------- |
| Array\<number>  | 该渲染单元中每个字符对应的字形序号。|

**示例：**

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

获取该渲染单元中每个字形相对于每行的索引。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                   | 说明                                   |
| ---------------------- | ------------------------------------- |
| Array<[common2D.Point](js-apis-graphics-common2D.md#point12)>  | 该渲染单元中每个字形相对于每行的索引。 |

**示例：**

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

获取该渲染单元中每个字形相对于其索引的偏移量。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Array<[common2D.Point](js-apis-graphics-common2D.md#point12)>  | 该渲染单元中每个字形相对于其索引的偏移量。|

**示例：**

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

获取该渲染单元的字体属性对象实例。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                   | 说明           |
| ------------------------------------------------- | -------------------------- |
| [drawing.Font](js-apis-graphics-drawing.md#font)  | 该渲染单元的字体属性对象实例。|

**示例：**

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

在画布上以坐标点 (x, y) 为左上角位置绘制该渲染单元。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                    |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | 是   | 绘制的目标 canvas。      |
|    x   | number                                               | 是   | 绘制的左上角位置的横坐标，浮点数。|
|    y   | number                                               | 是   | 绘制的左上角位置的纵坐标。浮点数。|

**示例：**

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
