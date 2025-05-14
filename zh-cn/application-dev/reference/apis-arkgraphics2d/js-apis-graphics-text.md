# @ohos.graphics.text (文本模块)

本模块提供一系列用于文本布局和字体管理的编程接口。文本布局相关的接口旨在提供高质量的排版，包括字符到字形的转换、字距调整、换行、对齐、文本测量等。字体管理接口提供字体注册、字体描述符、字体集管理等功能。

该模块提供以下创建复杂样式的文本段落的常用类：

- [TextStyle](#textstyle)：文本样式，控制文本的字体类型、大小、间距等属性。
- [FontCollection](#fontcollection)：字体集，控制各种不同的字体。
- [FontDescriptor](#fontdescriptor14)：字体描述符信息。
- [ParagraphStyle](#paragraphstyle)：段落样式，控制整个段落的断行策略、断词策略等属性。
- [ParagraphBuilder](#paragraphbuilder)：段落生成器，控制生成不同的段落对象。
- [Paragraph](#paragraph)：段落，由ParagraphBuilder类调用[build()](#build)接口构建而成。
- [TextLine](#textline)：以行为单位的段落文本的载体，由Paragraph类调用[getTextLines()](#gettextlines)接口获取。
- [Run](#run)：文本排版单元，由TextLine类调用[getGlyphRuns()](#getglyphruns)接口获取。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { text } from '@kit.ArkGraphics2D';
```

## text.getSystemFontFullNamesByType<sup>14+</sup>

getSystemFontFullNamesByType(fontType: SystemFontType): Promise&lt;Array&lt;string&gt;&gt;

根据字体类型返回该类型对应的所有字体的字体名称，使用Promise异步回调。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| - | - | - | - |
| fontType | [SystemFontType](#systemfonttype14) | 是 | 指定的字体类型。 |

**返回值：**

| 类型 | 说明 |
| - | - |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回相应字体类型的所有字体的fullName。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { text } from "@kit.ArkGraphics2D"
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("get font list")
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .width(300)
          .height(80)
          .onClick(() => {
            let fontType:text.SystemFontType = text.SystemFontType.GENERIC
            let promise = text.getSystemFontFullNamesByType(fontType)
            promise.then((data) => {
              console.info(`then font list size: ${data.length}`)
              data.forEach((fontItem) => {
                console.info(fontItem)
              })
            }).catch((error: BusinessError) => {
              console.error(`Failed to get font fullNames by type, error: ${JSON.stringify(error)}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## text.getFontDescriptorByFullName<sup>14+</sup>

getFontDescriptorByFullName(fullName: string, fontType: SystemFontType): Promise&lt;FontDescriptor&gt;

根据字体名称和类型获取字体描述符，使用Promise异步回调。

字体描述符是描述字体特征的数据结构，包含字体外观和属性的详细信息。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| - | - | - | - |
| fullName | string | 是 | 指定的字体名称。对应字体文件的name表中的fullName。可以使用[getSystemFontFullNamesByType](#textgetsystemfontfullnamesbytype14)获取。 |
| fontType | [SystemFontType](#systemfonttype14) | 是 | 指定的字体类型。 |

**返回值：**

| 类型 | 说明 |
| - | - |
| Promise&lt;[FontDescriptor](#fontdescriptor14)&gt; | Promise对象，返回指定的字体描述符。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { text } from "@kit.ArkGraphics2D"
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("get fontDesciptor")
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .width(300)
          .height(80)
          .onClick(() => {
            let fontType:text.SystemFontType = text.SystemFontType.GENERIC
            let promise = text.getFontDescriptorByFullName("HarmonyOS Sans", fontType)
            promise.then((fontdecriptor) => {
              console.info(`desc: ${JSON.stringify(fontdecriptor)}`)
            }).catch((error: BusinessError) => {
              console.error(`Failed to get fontDescriptor by fullName, error: ${JSON.stringify(error)}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
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

| 名称                          | 值   | 说明                                                                                                                  |
|-----------------------------| ---- | -------------------------------------------------------------------------------------------------------------------- |
| NORMAL                      | 0    | 默认的换行规则。依据各自语言的规则，允许在字间发生换行。                                                                  |
| BREAK_ALL                   | 1    | 对于Non-CJK（非中文，日文，韩文）文本允许在任意字符内发生换行。该值适合包含一些非亚洲文本的亚洲文本，比如使连续的英文字符断行。|
| BREAK_WORD                  | 2    | 对于Non-CJK的文本可在任意2个字符间断行，一行文本中有断行破发点（如空白符）时，优先按破发点换行，保障单词优先完整显示。若整一行文本均无断行破发点时，则在任意2个字符间断行。对于CJK与NORMAL效果一致。|

## Decoration

文本装饰线。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                      | 类型                                                  | 只读 | 可选 | 说明                                         |
| ------------------------- | --------------------------------------------------- | ---- | ---- | -------------------------------------------- |
| textDecoration            | [TextDecorationType](#textdecorationtype)           | 是   | 是   | 装饰线类型，默认为NONE。                       |
| color                     | [common2D.Color](js-apis-graphics-common2D.md#color)| 是   | 是   | 装饰线颜色，默认为透明。                       |
| decorationStyle           | [TextDecorationStyle](#textdecorationstyle)         | 是   | 是   | 装饰线样式，默认为SOLID。                      |
| decorationThicknessScale  | number                                              | 是   | 是   | 装饰线粗细系数，浮点数，默认为1.0。|

## TextDecorationType

装饰线类型枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称           | 值 | 说明        |
| -------------- | - | ----------- |
| NONE           | 0 | 无装饰线。|
| UNDERLINE      | 1 | 下划线。      |
| OVERLINE       | 2 | 上划线。     |
| LINE_THROUGH   | 4 | 删除线。      |

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

## FontWidth

字体宽度的枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称             | 值 | 说明       |
| ---------------- | - | ---------- |
| ULTRA_CONDENSED  | 1 | 超窄字宽。  |
| EXTRA_CONDENSED  | 2 | 特窄字宽。  |
| CONDENSED        | 3 | 窄的字宽。  |
| SEMI_CONDENSED   | 4 | 半窄字宽。  |
| NORMAL           | 5 | 常规字宽。  |
| SEMI_EXPANDED    | 6 | 半宽字宽。  |
| EXPANDED         | 7 | 宽的字宽。  |
| EXTRA_EXPANDED   | 8 | 特宽字宽。  |
| ULTRA_EXPANDED   | 9 | 超宽的字宽。|

## FontStyle

字体样式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称    | 值 | 说明                                                 |
| ------- | - | ---------------------------------------------------- |
| NORMAL  | 0 | 常规样式。                                            |
| ITALIC  | 1 | 斜体。如果当前字体没有可用的斜体版本，会选用倾斜体替代。  |
| OBLIQUE | 2 | 倾斜体。如果当前字体没有可用的倾斜体版本，会选用斜体替代。|

## TextHeightBehavior

文本高度修饰符模式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                  |  值 | 说明                                                  |
| --------------------- | --- | ---------------------------------------------------- |
| ALL                   | 0x0 | 高度修饰符设置为段落中第一行上升、最后一行下降。            |
| DISABLE_FIRST_ASCENT  | 0x1 | 高度修饰符设置为禁止段落中第一行上升。                   |
| DISABLE_LAST_ASCENT   | 0x2 | 高度修饰符设置为禁止段落中最后一行下降。                 |
| DISABLE_ALL           | 0x1 \| 0x2 | 高度修饰符设置为禁止段落中第一行上升、最后一行下降。          |

## TextBaseline

文本基线类型枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称        | 值 | 说明 |
| ----------- | - | ---- |
| ALPHABETIC  | 0 | 用于拉丁字母的文本基线对齐。|
| IDEOGRAPHIC | 1 | 用于CJK（中文，日文，韩文）的文本基线对齐。|

## EllipsisMode

省略号类型枚举。

EllipsisMode.START和EllipsisMode.MIDDLE仅在单行超长文本生效。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 值 | 说明      |
| ------ | - | --------- |
| START  | 0 | 开头省略号，只在[ParagraphStyle](#paragraphstyle)中设置maxLines为1时生效。|
| MIDDLE | 1 | 中间省略号，只在[ParagraphStyle](#paragraphstyle)中设置maxLines为1时生效。|
| END    | 2 | 末尾省略号。|

## TextShadow

字体阴影。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称          | 类型                                                 | 只读 | 可选 | 说明                               |
| ------------- | ---------------------------------------------------- | --  | ---  | --------------------------------- |
| color         | [common2D.Color](js-apis-graphics-common2D.md#color) | 是  |  是   | 字体阴影的颜色，默认为黑色Color(255, 0, 0, 0)。        |
| point         | [common2D.Point](js-apis-graphics-common2D.md#point12) | 是  |  是   | 字体阴影基于当前文本的偏移位置，横、纵坐标要大于等于零。    |
| blurRadius    | number                                               | 是  |  是   | 模糊半径，浮点数，默认为0.0px。       |

## RectStyle

矩形框样式。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称               | 类型                                                 | 只读 | 可选 | 说明                                      |
| -----------------  | ---------------------------------------------------- | --  | ---  | ---------------------------------------- |
| color              | [common2D.Color](js-apis-graphics-common2D.md#color) | 是  |  否   | 矩形框的颜色。                 |
| leftTopRadius      | number                                               | 是  |  否   | 矩形框的左上半径。       |
| rightTopRadius     | number                                               | 是  |  否   | 矩形框的右上半径。       |
| rightBottomRadius  | number                                               | 是  |  否   | 矩形框的右下半径。       |
| leftBottomRadius   | number                                               | 是  |  否   | 矩形框的左下半径。       |

## FontFeature

文本字体特征。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称      | 类型                                                 | 只读 | 可选 | 说明                                       |
| --------- | ---------------------------------------------------- | --  | ---  | ----------------------------------------- |
| name      | string                                               | 是  |  否   | 字体特征键值对中的关键字标识的字符串。       |
| value     | number                                               | 是  |  否   | 字体特征键值对的值。                        |

## FontVariation

可变字体属性。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称      | 类型                                                 | 只读 | 可选 | 说明                                       |
| --------- | ---------------------------------------------------- | --  | ---  | ----------------------------------------- |
| axis      | string                                               | 是  |  否   | 可变字体属性键值对中的关键字标识的字符串。       |
| value     | number                                               | 是  |  否   | 可变字体属性键值对的值。                        |

## TextStyle

文本样式。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                      | 类型                                     | 只读 | 可选 | 说明                                                   |
| ------------- | ---------------------------------------------------- | -- | -- | --------------------------------------------------------- |
| decoration    | [Decoration](#decoration)                            | 是 | 是 | 装饰线设置，默认不使用装饰线。             |
| color         | [common2D.Color](js-apis-graphics-common2D.md#color) | 是 | 是 | 文字颜色，默认为白色。                         |
| fontWeight    | [FontWeight](#fontweight)                            | 是 | 是 | 字重，默认为W400。 目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold（即W600）时字体粗细无变化，当设置字重值大于等于semi-bold（即W600）时可能会触发伪加粗效果。                         |
| fontStyle     | [FontStyle](#fontstyle)                              | 是 | 是 | 字体样式，默认为常规样式。                          |
| baseline      | [TextBaseline](#textbaseline)                        | 是 | 是 | 文本基线型，默认为ALPHABETIC。               |
| fontFamilies  | Array\<string>                                       | 是 | 是 | 字体家族名称列表，默认为空，匹配系统字体。                    |
| fontSize      | number                                               | 是 | 是 | 字体大小，浮点数，默认为14.0，单位为px。  |
| letterSpacing | number                                               | 是 | 是 | 字符间距，正数拉开字符距离，若是负数则拉近字符距离，浮点数，默认为0.0，单位为物理像素px。|
| wordSpacing   | number                                               | 是 | 是 | 单词间距，浮点数，默认为0.0，单位为px。                 |
| heightScale   | number                                               | 是 | 是 | 行高缩放倍数，浮点数，默认为1.0，heightOnly为true时生效。              |
| heightOnly    | boolean                                              | 是 | 是 | true表示根据字体大小和heightScale设置文本框的高度，false表示根据行高和行距，默认为false。|
| halfLeading   | boolean                                              | 是 | 是 | true表示将行间距平分至行的顶部与底部，false则不平分，默认为false。|
| ellipsis      | string                                               | 是 | 是 | 省略号文本，表示省略号生效后使用该字段值替换省略号部分。       |
| ellipsisMode  | [EllipsisMode](#ellipsismode)                        | 是 | 是 | 省略号类型，默认为END，行尾省略号。                       |
| locale        | string                                               | 是 | 是 | 语言类型，如字段为'en'代表英文，'zh-Hans'代表简体中文，'zh-Hant'代表繁体中文。具体请参照ISO 639-1规范，默认为空字符串。|
| baselineShift | number                                               | 是 | 是 | 文本下划线的偏移距离，浮点数，默认为0.0px。                 |
| fontFeatures  | Array\<[FontFeature](#fontfeature)>                  | 是 | 是 | 文本字体特征数组。|
| fontVariations| Array\<[FontVariation](#fontvariation)>              | 是 | 是 | 可变字体属性数组。|
| textShadows   | Array\<[TextShadow](#textshadow)>                    | 是 | 是 | 文本阴影数组。|
| backgroundRect| [RectStyle](#rectstyle)                              | 是 | 是 | 文本矩形框样式。|

## StrutStyle

支柱样式，用于控制绘制文本的行间距、基线对齐方式以及其他与行高相关的属性，默认不开启。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                      | 类型                                       | 只读 | 可选 | 说明                                                                 |
| -------------  | ---------------------------------------------------- | ---- | -- | --------------------------------------------------------------------- |
| fontFamilies   | Array\<string>                                       | 是   | 是 | 字体族名称列表，默认为空，匹配系统字体。                                               |
| fontStyle      | [FontStyle](#fontstyle)                              | 是   | 是 | 字体样式，默认为常规样式。                                               |
| fontWidth      | [FontWidth](#fontwidth)                              | 是   | 是 | 字体宽度，默认为NORMAL。                                                |
| fontWeight     | [FontWeight](#fontweight)                            | 是   | 是 | 字重，默认为W400。系统默认字体支持字重调节，其他字体设置字重值小于W600时无变化，大于等于W600时可能触发伪加粗效果。                             |
| fontSize       | number                                               | 是   | 是 | 字体大小，浮点数，默认14.0，单位物理像素px。                             |
| height         | number                                               | 是   | 是 | 行高缩放倍数，浮点数，默认为1.0。                                         |
| leading        | number                                               | 是   | 是 | 以自定义行距应用于支柱的行距，浮点数，默认为-1.0。                          |
| forceHeight    | boolean                                              | 是   | 是 | 是否所有行都将使用支柱的高度，true表示使用，false表示不使用，默认为false。     |
| enabled        | boolean                                              | 是   | 是 | 是否启用支柱样式，true表示使用，false表示不使用，默认为false。              |
| heightOverride | boolean                                              | 是   | 是 | 是否覆盖高度，true表示覆盖，false表示不覆盖，默认为false。                  |
| halfLeading    | boolean                                              | 是   | 是 | true表示将行间距平分至行的顶部与底部，false则不平分，默认为false。           |

## FontDescriptor<sup>14+</sup>

字体描述符信息。

**系统能力**：SystemCapability.Graphics.Drawing

| 名称 | 类型 | 只读 | 可选 | 说明 |
| - | - | -  | - | - |
| path | string | 否 | 是 | 字体绝对路径，可取遵循系统限制的任意字符串，默认为空字符串。 |
| postScriptName | string | 否 | 是 | 字体唯一标识名称，可取任意字符串，默认为空字符串。 |
| fullName | string | 否 | 是 | 字体名称，可取任意字符串，默认为空字符串。 |
| fontFamily | string | 否 | 是 | 字体家族，可取任意字符串，默认为空字符串。 |
| fontSubfamily | string | 否 | 是 | 子字体家族，可取任意字符串，默认为空字符串。 |
| weight | [FontWeight](#fontweight) | 否 | 是 | 字体字重，默认值为0。 |
| width | number | 否 | 是 | 字体宽度，取值范围1-9整数，默认值为0。 |
| italic | number | 否 | 是 | 是否是斜体字体，0表示非斜体，1表示斜体，默认值为0。 |
| monoSpace | boolean | 否 | 是 | 是否是等宽字体，true表示等宽，false表示非等宽，默认值为false。 |
| symbolic | boolean | 否 | 是 | 是否支持符号，true表示支持，false表示不支持，默认值为false。 |

## FontCollection

字体集。

### getGlobalInstance

static getGlobalInstance(): FontCollection

获取应用全局FontCollection实例。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                |
| ------ | ------------------ |
| [FontCollection](#fontcollection) | FontCollection对象。|

**示例：**

```ts
import { text } from "@kit.ArkGraphics2D"

function textFunc() {
  let fontCollection = text.FontCollection.getGlobalInstance();
}

@Entry
@Component
struct Index {
  fun: Function = textFunc;
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

同步接口，加载自定义字体。其中参数name对应的值需要在[TextStyle](#textstyle)中的fontFamilies属性配置，才能显示自定义字体效果。支持的字体文件格式包含：ttf、otf。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型               | 必填 | 说明                              |
| ----- | ------------------ | ---- | --------------------------------------------------------------------------------- |
| name  | string             | 是   | 加载成字体后，调用该字体所使用的名称。                                                |
| path  | string \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource) | 是   | 需要导入的字体文件的路径，应为 "file:// + 字体文件绝对路径" 或 "rawfile/目录or文件名"。 |

**示例：**

```ts
import { text } from "@kit.ArkGraphics2D"

let fontCollection: text.FontCollection = new text.FontCollection();

@Entry
@Component
struct RenderTest {
  LoadFontSyncTest() {
    fontCollection.loadFontSync('Clock_01', 'file:///system/fonts/HarmonyClock_01.ttf')
    let fontFamilies: Array<string> = ["Clock_01"]
    let myTextStyle: text.TextStyle = {
      fontFamilies: fontFamilies
    };
    let myParagraphStyle: text.ParagraphStyle = {
      textStyle: myTextStyle,
    }
    let paragraphBuilder: text.ParagraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);

    let textData = "测试 loadFontSync 加载字体HarmonyClock_01.ttf";
    paragraphBuilder.addText(textData);
    let paragraph: text.Paragraph = paragraphBuilder.build();
    paragraph.layoutSync(600);
  }

  aboutToAppear() {
    this.LoadFontSyncTest();
  }

  build() {
  }
}
```

### clearCaches

clearCaches(): void

清理字体排版缓存（字体排版缓存本身设有内存上限和清理机制，所占内存有限，如无内存要求，不建议清理）。

**系统能力**：SystemCapability.Graphics.Drawing

**示例：**

```ts
import { text } from "@kit.ArkGraphics2D"

@Entry
@Component
struct Index {
  build() {
    Column() {
      Button().onClick(() => {
        text.FontCollection.getGlobalInstance().clearCaches();
      })
    }
  }
}
```

## ParagraphStyle

段落样式。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                 | 类型                                        | 只读 | 可选 | 说明                                          |
| -------------------- | ------------------------------------------ | ---- | ---- | -------------------------------------------- |
| textStyle            | [TextStyle](#textstyle)                    | 是   | 是   | 作用于整个段落的文本样式，默认为初始的文本样式。|
| textDirection        | [TextDirection](#textdirection)            | 是   | 是   | 文本方向，默认为LTR。                          |
| align                | [TextAlign](#textalign)                    | 是   | 是   | 文本对齐方式，默认为START。若同时配置tab属性，制表符对齐方式将失效。|
| wordBreak            | [WordBreak](#wordbreak)                    | 是   | 是   | 断词类型，默认为BREAK_WORD。                    |
| maxLines             | number                                     | 是   | 是   | 最大行数限制，整数，默认为1e9。                  |
| breakStrategy        | [BreakStrategy](#breakstrategy)            | 是   | 是   | 断行策略，默认为GREEDY。                        |
| strutStyle           | [StrutStyle](#strutstyle)                  | 是   | 是   | 支柱样式，默认为初始的StrutStyle。               |
| textHeightBehavior   | [TextHeightBehavior](#textheightbehavior)  | 是   | 是   | 文本高度修饰符模式，默认为ALL。                              |


## PlaceholderAlignment

占位符相对于周围文本的纵向对齐方式。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                | 值 | 说明                   |
| ------------------- | - | ---------------------- |
| OFFSET_AT_BASELINE  | 0 | 基线与文本基线对齐。     |
| ABOVE_BASELINE      | 1 | 底部与文本基线对齐。   |
| BELOW_BASELINE      | 2 | 顶部与文本基线对齐。   |
| TOP_OF_ROW_BOX      | 3 | 顶部与文本顶部对齐。   |
| BOTTOM_OF_ROW_BOX   | 4 | 底部与文本底部对齐。   |
| CENTER_OF_ROW_BOX   | 5 | 居中对齐。|

![zh-ch_image_PlaceholderAlignment.png](figures/zh-ch_image_PlaceholderAlignment.png)

> **说明：**
>
> 示意图展示了后三种对齐方式，前三种对齐方式类似，比较位置是文本基线，即绿色线条部分。
>
>![zh-ch_image_Baseline.png](figures/zh-ch_image_Baseline.png)

## PlaceholderSpan

描述占位符样式。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称           | 类型                                           | 只读 | 可选 | 说明                         |
| -------------- | --------------------------------------------- | ---- | --- | --------------------------- |
| width          | number                                        | 是   | 否   | 占位符的宽度，浮点数，单位为物理像素px。|
| height         | number                                        | 是   | 否   | 占位符的高度，浮点数，单位为物理像素px。|
| align          | [PlaceholderAlignment](#placeholderalignment) | 是   | 否   | 相对于周围文本的纵向对齐方式。|
| baseline       | [TextBaseline](#textbaseline)                 | 是   | 否   | 基线类型。                   |
| baselineOffset | number                                        | 是   | 否   | 基线偏移量，浮点数，单位为物理像素px。  |

## Range

描述左闭右开区间。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 类型   | 只读 | 可选 | 说明            |
| ----- | ------ | ---- | --- | --------------- |
| start | number | 是   | 否   | 区间左侧端点索引，整数。|
| end   | number | 是   | 否   | 区间右侧端点索引，整数。|

## Paragraph

保存文本内容及样式的载体，支持排版与绘制操作。

下列API示例中都需先使用[ParagraphBuilder](#paragraphbuilder)类的[build()](#build)接口获取到Paragraph对象实例，再通过此实例调用对应方法。

### layoutSync

layoutSync(width: number): void

进行排版并计算所有字形位置。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ----- | ------ | ---- | -------------- |
| width | number | 是   | 单行的最大宽度，浮点数，单位为物理像素px。|

**示例：**

```ts
paragraph.layoutSync(100);
```

### paint

paint(canvas: drawing.Canvas, x: number, y: number): void

在画布上以 (x, y) 为左上角绘制文本。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                    |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | 是   | 绘制的目标画布。         |
|    x   | number                                               | 是   | 绘制的左上角位置的横坐标，浮点数。|
|    y   | number                                               | 是   | 绘制的左上角位置的纵坐标，浮点数。|

**示例：**

```ts
const color: ArrayBuffer = new ArrayBuffer(160000);
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 200, width: 200 } }
let pixelMap: image.PixelMap = image.createPixelMapSync(color, opts);
let canvas = new drawing.Canvas(pixelMap);
paragraph.paint(canvas, 0, 0);
```

### paintOnPath

paintOnPath(canvas: drawing.Canvas, path: drawing.Path, hOffset: number, vOffset: number): void

在画布上沿路径绘制文本。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                    |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | 是   | 绘制的目标画布。         |
| path | [drawing.Path](js-apis-graphics-drawing.md#path) | 是   | 确认文字位置的路径。         |
|    hOffset   | number                                               | 是   | 沿路径方向偏置，从路径起点向前为正，向后为负。|
|    vOffset   | number                                               | 是   | 沿路径垂直方向偏置，沿路径方向左侧为负，右侧为正。|

**示例：**

```ts
const color: ArrayBuffer = new ArrayBuffer(160000);
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 200, width: 200 } }
let pixelMap: image.PixelMap = image.createPixelMapSync(color, opts);
let canvas = new drawing.Canvas(pixelMap);
let path = new drawing.Path();
path.arcTo(20, 20, 180, 180, 180, 90);
paragraph.paintOnPath(canvas, path, 0, 0);
```

### getMaxWidth

getMaxWidth(): number

获取文本最大行宽。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明       |
| ------ | --------- |
| number | 最大的行宽，浮点数，单位为物理像素px。|

**示例：**

```ts
let maxWidth = paragraph.getMaxWidth();
```

### getHeight

getHeight(): number

获取文本总高度。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明   |
| ------ | ----- |
| number | 总高度，浮点数，单位为物理像素px。|

**示例：**

```ts
let height = paragraph.getHeight();
```

### getLongestLine

getLongestLine(): number

获取文本最长行宽。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明           |
| ------ | ------------- |
| number | 最长一行的宽度，浮点数，单位为物理像素px。|

**示例：**

```ts
let longestLine = paragraph.getLongestLine();
```

### getLongestLineWithIndent<sup>13+</sup>

getLongestLineWithIndent(): number

获取文本最长一行的宽度（包含缩进），建议向上取整。文本内容为空时返回0。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明           |
| ------ | ------------- |
| number | 最长一行的宽度（该宽度包含当前行缩进的宽度），浮点数，单位为物理像素px。|

**示例：**

```ts
let longestLineWithIndent = paragraph.getLongestLineWithIndent();
```

### getMinIntrinsicWidth

getMinIntrinsicWidth(): number

获取段落最小固有宽度。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                           |
| ------ | ----------------------------- |
| number | 该段落所占水平空间的最小固有宽度，浮点数，单位为物理像素px。|

**示例：**

```ts
let minIntrinsicWidth = paragraph.getMinIntrinsicWidth();
```

### getMaxIntrinsicWidth

getMaxIntrinsicWidth(): number

获取段落最大固有宽度。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                           |
| ------ | ----------------------------- |
| number | 该段落所占水平空间的最大固有宽度，浮点数，单位为物理像素px。|

**示例：**

```ts
let maxIntrinsicWidth = paragraph.getMaxIntrinsicWidth();
```

### getAlphabeticBaseline

getAlphabeticBaseline(): number

获取拉丁字母基线位置。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                |
| ------ | ------------------ |
| number | 拉丁字母下的基线位置，浮点数，单位为物理像素px。|

**示例：**

```ts
let alphabeticBaseline = paragraph.getAlphabeticBaseline();
```

### getIdeographicBaseline

getIdeographicBaseline(): number

获取表意字（如CJK（中文，日文，韩文））下的基线位置。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                  |
| ------ | -------------------- |
| number | 获取表意字下的基线位置，浮点数，单位为物理像素px。|

**示例：**

```ts
let ideographicBaseline = paragraph.getIdeographicBaseline();
```

### getRectsForRange

getRectsForRange(range: Range, widthStyle: RectWidthStyle, heightStyle: RectHeightStyle): Array\<TextBox>

获取给定的矩形区域宽度以及矩形区域高度的规格下，文本中该区间范围内的字符所占的矩形区域。

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
let range: text.Range = { start: 0, end: 1};
let rects = paragraph.getRectsForRange(range, text.RectWidthStyle.TIGHT, text.RectHeightStyle.TIGHT);
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
let placeholderRects = paragraph.getRectsForPlaceholders();
```

### getGlyphPositionAtCoordinate

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

获取与给定坐标最接近的字形位置信息。

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
let positionWithAffinity = paragraph.getGlyphPositionAtCoordinate(0, 0);
```

### getWordBoundary

getWordBoundary(offset: number): Range

返回给定offset的字形所在单词的索引区间。

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
let wordRange = paragraph.getWordBoundary(0);
```

### getLineCount

getLineCount(): number

返回文本行数。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明       |
| ------ | --------- |
| number | 文本行数量，整数。|

**示例：**

```ts
let lineCount = paragraph.getLineCount();
```

### getLineHeight

getLineHeight(line: number): number

返回指定行的行高。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ----- | ------ | ---- | --------- |
| line  | number | 是   | 文本行索引，整数，范围为0~getLineCount()-1。|

**返回值：**

| 类型   | 说明  |
| ------ | ---- |
| number | 行高。|

**示例：**

```ts
let lineHeight = paragraph.getLineHeight(0);
```

### getLineWidth

getLineWidth(line: number): number

返回指定行的行宽。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ----- | ------ | ---- | --------- |
| line  | number | 是   | 文本行索引，整数，范围为0~getLineCount()-1。|

**返回值：**

| 类型   | 说明  |
| ------ | ---- |
| number | 行宽。|

**示例：**

```ts
let lineWidth = paragraph.getLineWidth(0);
```

### didExceedMaxLines

didExceedMaxLines(): boolean

返回段落是否超过最大行数。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型    | 说明                                                      |
| ------- | -------------------------------------------------------- |
| boolean | true表示段落超出了最大行限制，false则表示没有超出最大行限制。 |

**示例：**

```ts
let didExceed = paragraph.didExceedMaxLines();
```

### getTextLines

getTextLines(): Array\<TextLine>

返回所有的文本行。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                          | 说明          |
| ----------------------------- | ------------- |
| Array\<[TextLine](#textline)> | 文本行载体数组。|

**示例：**

```ts
let lines = paragraph.getTextLines();
```

### getActualTextRange

getActualTextRange(lineNumber: number, includeSpaces: boolean): Range

获取指定行的实际可见文本范围，不包括溢出的省略号。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ----- | ------ | ---- | --------- |
| lineNumber  | number | 是   | 要获取文本范围的行索引，行索引从0开始。该接口只能获取已有行的边界，即输入行索引从0开始。最大行索引为文本行数量-1，文本行数量可通过[getLineCount](#getlinecount)接口获取。|
| includeSpaces  | boolean | 是   | 指示是否应包含空白字符。true表示包含空白字符，false表示不包含空白字符。|

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------ |
| [Range](#range)  | 返回对应行数的实际文本范围。如果行索引非法，返回的start和end均为0。 |

**示例：**

```ts
let rang = paragraph.getActualTextRange(0, true);
```


### getLineMetrics

getLineMetrics(): Array\<LineMetrics>

获取文本行的行度量数组。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                          | 说明          |
| ----------------------------- | ------------- |
| Array\<[LineMetrics](#linemetrics)> | 文本行的行度量数组。|

**示例：**

```ts
let arrLineMetrc =  paragraph.getLineMetrics();
```

### getLineMetrics

getLineMetrics(lineNumber: number): LineMetrics | undefined

获取特定行号的行度量信息。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ----- | ------ | ---- | --------- |
| lineNumber  | number | 是   | 要查询度量信息的行的编号，行号从0开始。|

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------ |
| [LineMetrics](#linemetrics) | 如果指定的行号有效且度量信息存在，则返回一个包含该行度量数据的LineMetrics对象；如果行号无效或无法获取度量信息，则返回undefined。                  |

**示例：**

```ts
let lineMetrics =  paragraph.getLineMetrics(0);
```

## RunMetrics

描述文本行中连续文本块的布局信息和度量数据。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称      | 类型                                                | 只读 | 可选 | 说明        |
| --------- | -------------------------------------------------- | ---- | ---- | ----------- |
| textStyle | [TextStyle](#textstyle)                             | 是   | 否   | 字体的样式信息。|
| fontMetrics | [drawing.FontMetrics](js-apis-graphics-drawing.md#fontmetrics)| 是   | 否   | 字体度量信息。    |

## LineMetrics

描述文本布局中单行文字的度量信息。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称      | 类型                                                | 只读 | 可选 | 说明        |
| --------- | -------------------------------------------------- | ---- | ---- | ----------- |
| startIndex | number                                            | 是   | 否   | 文本缓冲区中该行开始的索引位置。|
| endIndex   | number                                            | 是   | 否   | 文本缓冲区中该行结束的索引位置。|
| ascent     | number                                            | 是   | 否   | 文字上升高度，即从基线到字符顶部的距离。|
| descent    | number                                            | 是   | 否   | 文字下降高度，即从基线到字符底部的距离。|
| height     | number                                            | 是   | 否   | 当前行的高度，计算方式为 `Math.round(ascent + descent)`|
| width      | number                                            | 是   | 否   | 行的宽度。                      |
| left       | number                        | 是   | 否   | 行的左边缘位置。右边缘可通过 `left+width` 计算得出。|
| baseline   | number                        | 是   | 否   | 该行基线相对于段落顶部的 Y 坐标位置。|
| lineNumber   | number                        | 是   | 否   | 行号，从0开始计数。|
| topHeight   | number                        | 是   | 否   | 从顶部到当前行的高度。|
| runMetrics   | Map<number, [RunMetrics](#runmetrics)>                        | 是   | 否   | 文本索引范围与关联的字体度量信息之间的映射。|

## TextBox

文本矩形区域。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称      | 类型                                                | 只读 | 可选 | 说明        |
| --------- | -------------------------------------------------- | ---- | ---- | ----------- |
| rect      | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是   | 否   | 矩形区域信息。|
| direction | [TextDirection](#textdirection)                    | 是   | 否   | 文本方向。    |

## PositionWithAffinity

位置和亲和度。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称      | 类型                   | 只读 | 可选 | 说明                      |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | 是   | 否   | 字形相对于段落的索引，整数。  |
| affinity  | [Affinity](#affinity) | 是   | 否   | 位置亲和度。               |

## RectWidthStyle

矩形区域宽度规格枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称  | 值 | 说明                                   |
| ----- | - | -------------------------------------- |
| TIGHT | 0 | 不设置letterSpacing时，与字形紧贴，否则包含letterSpacing的宽度。|
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
| fontCollection | [FontCollection](#fontcollection) | 是   | 字体集。 |

**示例：**

```ts
import { text } from "@kit.ArkGraphics2D";

function textFunc() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: text.TextAlign.END,
  };
  let fontCollection = new text.FontCollection();
  let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
}

@Entry
@Component
struct Index {
  fun: Function = textFunc;
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

更新当前文本块的样式。

> **说明：**
>
> 更新当前文本块的样式，之后添加文字均采用该样式。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名    | 类型       | 必填 | 说明                                                                                                   |
| --------- | --------- | ---- | ------------------------------------------------------------------------------------------------------ |
| textStyle | [TextStyle](#textstyle) | 是   | 包含了对文本的各种视觉属性的定义，如字体、字号、颜色、字重、字间距、行距、装饰（如下划线、删除线）、文本阴影等。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function textFunc() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: text.TextAlign.CENTER,
  };
  let fontCollection = new text.FontCollection();
  let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  paragraphBuilder.pushStyle(myTextStyle);
}

@Entry
@Component
struct Index {
  fun: Function = textFunc;
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

弹出当前文本样式。

**系统能力**：SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function textFunc() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: text.TextAlign.END,
  };
  let fontCollection = new text.FontCollection();
  let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  paragraphBuilder.pushStyle(myTextStyle);
  paragraphBuilder.popStyle();
}

@Entry
@Component
struct Index {
  fun: Function = textFunc;
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

向正在构建的文本段落中插入具体的文本字符串。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| text    | string  | 是   | 段落中插入的具体文本字符串，传入非法Unicode时会显示�。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function textFunc() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: text.TextAlign.END,
  };
  let fontCollection = new text.FontCollection();
  let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  paragraphBuilder.addText("123666");
}

@Entry
@Component
struct Index {
  fun: Function = textFunc;
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

用于构建文本段落时插入占位符。

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

function textFunc() {
  let myParagraphStyle: text.ParagraphStyle = {
    align: text.TextAlign.END,
  };
  let myPlaceholderSpan: text.PlaceholderSpan = {
    width: 10000,
    height: 10000000,
    align: text.PlaceholderAlignment.ABOVE_BASELINE,
    baseline: text.TextBaseline.ALPHABETIC,
    baselineOffset: 100000
  };
  let fontCollection = new text.FontCollection();
  let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  paragraphBuilder.addPlaceholder(myPlaceholderSpan);
}

@Entry
@Component
struct Index {
  fun: Function = textFunc;
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

用于构建段落，生成可用于后续排版渲染的段落对象。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                     | 说明                           |
| ------------------------ | ------------------------------ |
| [Paragraph](#paragraph)  | 可用于后续渲染的 Paragraph 对象。|

**示例：**

```ts
import { drawing, text, common2D } from '@kit.ArkGraphics2D'
import { image } from '@kit.ImageKit';

function textFunc() {
  let myTextStyle: text.TextStyle = {
    color : {alpha: 255, red: 255, green: 0, blue: 0},
    fontSize : 20,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle : myTextStyle,
  };
  let fontCollection = new text.FontCollection();
  let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  paragraphBuilder.addText("123456789");
  let paragraph = paragraphBuilder.build();
  paragraph.layoutSync(200);
}

@Entry
@Component
struct Index {
  fun: Function = textFunc;
  build() {
    Column() {
      Button().onClick(() => {
        this.fun();
      })
    }
  }
}
```

### addSymbol

addSymbol(symbolId: number): void

向正在构建的文本段落中插入具体符号。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名    | 类型    | 必填 | 说明                                                        |
| -------- | ------- | ---- | ----------------------------------------------------------- |
| symbolId | number  | 是   | 要设置的symbol码位，十六进制，当前支持的取值范围为：0xF0000-0xF0C97。可设置的symbol码位（即列表视图下的unicode值）请见[主题图标库](https://developer.huawei.com/consumer/cn/design/harmonyos-symbol/)。|

**示例：**

```ts
import { text } from "@kit.ArkGraphics2D";

function textFunc() {
  let myTextStyle: text.TextStyle = {
    color: { alpha: 255, red: 255, green: 0, blue: 0 },
    fontSize: 33,
  };
  let myParagraphStyle: text.ParagraphStyle = {
    textStyle: myTextStyle,
    align: text.TextAlign.END,
  };
  let fontCollection = new text.FontCollection();
  let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
  paragraphBuilder.addSymbol(0xF0000);
  let paragraph = paragraphBuilder.build();
}

@Entry
@Component
struct Index {
  fun: Function = textFunc;
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

获取文本行中字形的数量。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型    | 说明               |
| ------- | ------------------ |
| number  | 该文本行中字形数量，整数。 |

**示例：**

```ts
let glyphCount = lines[0].getGlyphCount();
```

### getTextRange

getTextRange(): Range

获取该行文本在整个段落文本中的索引区间。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------ |
| [Range](#range)  | 该行文本在整个段落文本中的索引区间。|

**示例：**

```ts
let textRange = lines[0].getTextRange();
```

### getGlyphRuns

getGlyphRuns(): Array\<Run>

获取文本行的排版单元数组。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型         | 说明                         |
| ------------ | --------------------------- |
| Array\<[Run](#run)>  | 该文本行中的文本排版单元数组。|

**示例：**

```ts
let runs = lines[0].getGlyphRuns();
```

### paint

paint(canvas: drawing.Canvas, x: number, y: number): void

在画布上以坐标点(x, y)为左上角位置绘制该文本行。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                    |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | 是   | 绘制的目标canvas。      |
|    x   | number                                               | 是   | 绘制的左上角位置的横坐标，浮点数。|
|    y   | number                                               | 是   | 绘制的左上角位置的纵坐标，浮点数。|

**示例：**

<!--code_no_check-->
```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function textFunc(pixelmap: PixelMap) {
  let canvas = new drawing.Canvas(pixelmap);
  lines[0].paint(canvas, 0, 0);
}

@Entry
@Component
struct Index {
  @State pixelmap?: PixelMap = undefined;
  fun: Function = textFunc;
  build() {
    Column() {
      Image(this.pixelmap).width(200).height(200);
      Button().onClick(() => {
        if (this.pixelmap == undefined) {
          const color: ArrayBuffer = new ArrayBuffer(160000);
          let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 200, width: 200 } }
          this.pixelmap = image.createPixelMapSync(color, opts);
        }
        this.fun(this.pixelmap);
      })
    }
  }
}
```

## Run

文本排版单元。

下列API示例中都需先使用[TextLine](#textline)类的[getGlyphRuns()](#getglyphruns)接口获取Run对象实例，再通过此实例调用对应方法。

### getGlyphCount

getGlyphCount(): number

获取该排版单元中字形的数量。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型     | 说明                |
| ------- | -------------------- |
| number  | 该排版单元中字形数量，整数。 |

**示例：**

```ts
let glyphs = runs[0].getGlyphCount();
```

### getGlyphs

getGlyphs(): Array\<number>

获取该排版单元中每个字符的字形序号。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型            | 说明                             |
| --------------- | -------------------------------- |
| Array\<number>  | 该排版单元中每个字符对应的字形序号。|

**示例：**

```ts
let glyph = runs[0].getGlyphs();
```

### getPositions

getPositions(): Array<common2D.Point>

获取该排版单元中每个字形相对于每行的字形位置。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                   | 说明                                   |
| ---------------------- | ------------------------------------- |
| Array<[common2D.Point](js-apis-graphics-common2D.md#point12)>  | 该排版单元中每个字形相对于每行的字形位置。 |

**示例：**

```ts
let positions = runs[0].getPositions();
```

### getOffsets

getOffsets(): Array<common2D.Point>

获取该排版单元中每个字形的索引偏移量。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Array<[common2D.Point](js-apis-graphics-common2D.md#point12)>  | 该排版单元中每个字形相对于其索引的偏移量。|

**示例：**

```ts
let offsets = runs[0].getOffsets();
```

### getFont

getFont(): drawing.Font

获取排版单元的字体属性对象。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                   | 说明           |
| ------------------------------------------------- | -------------------------- |
| [drawing.Font](js-apis-graphics-drawing.md#font)  | 该排版单元的字体属性对象实例。|

**示例：**

```ts
let font = runs[0].getFont();
```

### paint

paint(canvas: drawing.Canvas, x: number, y: number): void

在画布上以(x, y)为左上角位置绘制排版单元。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                    |
| ------ | ---------------------------------------------------- | ---- | ---------------------- |
| canvas | [drawing.Canvas](js-apis-graphics-drawing.md#canvas) | 是   | 绘制的目标 canvas。      |
|    x   | number                                               | 是   | 绘制的左上角位置的横坐标，浮点数。|
|    y   | number                                               | 是   | 绘制的左上角位置的纵坐标。浮点数。|

**示例：**

<!--code_no_check-->
```ts
import { drawing } from '@kit.ArkGraphics2D'
import { text } from "@kit.ArkGraphics2D"
import { common2D } from "@kit.ArkGraphics2D"
import { image } from '@kit.ImageKit';

function textFunc(pixelmap: PixelMap) {
  let canvas = new drawing.Canvas(pixelmap);
  runs[0].paint(canvas, 0, 0);
}

@Entry
@Component
struct Index {
  @State pixelmap?: PixelMap = undefined;
  fun: Function = textFunc;
  build() {
    Column() {
      Image(this.pixelmap).width(200).height(200);
      Button().onClick(() => {
        if (this.pixelmap == undefined) {
          const color: ArrayBuffer = new ArrayBuffer(160000);
          let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 200, width: 200 } }
          this.pixelmap = image.createPixelMapSync(color, opts);
        }
        this.fun(this.pixelmap);
      })
    }
  }
}
```

## SystemFontType<sup>14+</sup>

字体类型枚举，通过位或运算可实现组合类型。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称 | 值 | 说明 |
| - | - | - |
| ALL | 1 << 0 | 所有字体类型，包括系统字体类型、风格字体类型和用户已安装字体类型。 |
| GENERIC  | 1 << 1 | 系统字体类型。 |
| STYLISH  | 1 << 2 | 风格字体类型。风格字体类型是专为2in1设备设计的字体类型。 |
| INSTALLED  | 1 << 3 | 用户已安装的字体类型。 |
