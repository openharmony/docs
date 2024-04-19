# 属性字符串

作为[Text](./ts-basic-components-text.md)组件的入参对象，方便灵活应用文本样式。

>  **说明：**
>
>  从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 规则说明

* 当组件样式和属性字符串中的样式冲突时，冲突部分以属性字符串设置的样式为准，未冲突部分则生效组件的样式。
* 当属性字符串和[Text](./ts-basic-components-text.md)子组件冲突时，属性字符串优先级高，即当Text组件中绑定了属性字符串，忽略[Text](./ts-basic-components-text.md)组件下包含[Span](./ts-basic-components-span.md)等子组件的情况。
* 属性字符串不支持和其他类型文本入参动态切换。
* 不支持@State修饰。

## StyledString

StyledString(value: string , styles?: Array\<StyleOptions>)

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| value | string | 是 | 属性字符串文本内容。|
| styles | Array<[StyleOptions](#styleoptions对象说明)> | 否 | 属性字符串初始化选项。<br/>**说明：** <br/>start为异常值时，按默认值0处理。<br/>当start的值合法且length为异常值时，length的值为属性字符串长度与start的值的差值。<br/>StyledStringKey与StyledStringValue不匹配时，不生效。<br/>styledKey参数无默认值。<br/>styledValue入参合法时，styledKey传入undefined时，此时样式不生效。 |

### getString

getString(): string

获取字符串信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型              |说明       |
| ------- | --------------------------------- | 
| string | 属性字符串文本内容。 |

### length

readonly length: number

获取属性字符串字符的长度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型              |说明       |
| ------- | --------------------------------- | 
| number | 属性字符串字符的长度。 |

### equals

equals(other: StyledString): boolean

判断两个属性字符串是否相等。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| other | [StyledString](#styledstring) | 是   | StyledString类型的比较对象。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- | 
| boolean | 两个属性字符串是否相等。<br/>**说明：** <br/>当属性字符串的文本及样式均一致，视为相等。<br/>不比较GestureStyle，当属性字符串配置了不同事件，文本和其他样式相同时，亦视为相等。 |

### subStyledString

获取属性字符串的子字符串。

subStyledString(start: number , length?: number): StyledString

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 子属性字符串开始位置的下标。 |
| length | number | 否   | 子属性字符串的长度。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- | 
| [StyledString](#styledstring) | 子属性字符串。<br/>**说明：** <br/>当start为合法入参时，length的默认值是被查询属性字符串对象的长度与start的值的差。<br/>当start和length越界或者必填传入undefined时，会抛出异常。|

### getStyles

获取指定范围属性字符串的样式集合。

getStyles(start: number , length: number , styledKey?: StyledStringKey): Array\<SpanStyle>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 指定范围属性字符串的下标。 |
| length | number | 是   | 指定范围属性字符串的长度。 |
| styledKey | [StyledStringKey](ts-appendix-enums.md#styledstringkey12) | 否   | 指定范围属性字符串样式的枚举值。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- | 
| Array<[SpanStyle](#spanstyle对象说明)> | 各样式对象的数组。<br/>**说明：** <br/>当指定范围属性字符串未设置任何样式，则返回空数组。<br/>当start和length越界或者必填传入undefined时，会抛出异常；<br/>当styledKey传入异常值或undefined时，会抛出异常。 |

## MutableStyledString

继承于[StyledString](#styledstring)类。

>  **以下接口异常入参处理统一说明：**
>
> 当start和length越界或者必填传入undefined时，会抛出异常；
>
> 当styledKey和styledValue传入异常值或者两者对应关系不匹配时，会抛出异常。
> 

### replaceString

替换指定范围的字符串。

replaceString(start: number , length: number , other: string): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 指定范围的下标。 |
| length | number | 是   | 指定范围的长度。 |
| other | string | 是   | 替换的新文本内容。<br/>**说明：** <br/>替换的字符串使用的是start位置字符的样式。 |

### insertString

插入字符串。

insertString(start: number , other: string): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 插入位置的下标。 |
| other | string | 是   | 插入的新文本内容。<br/>**说明：** <br/>插入的字符串使用的是start-1位置字符的样式。若start-1位置字符未设置样式，则使用start位置字符样式。 |

### removeString

移除指定范围的字符串。

removeString(start: number , length: number): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 指定范围的下标。 |
| length | number | 是   | 指定范围的长度。 |

### replaceStyle

替换指定范围内容为指定类型新样式。

replaceStyle(spanStyle: SpanStyle): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| spanStyle | [SpanStyle](#spanstyle对象说明) | 是   | 样式对象。<br/>**说明：** <br/>默认清空原有样式，替换为新样式。 |

### setStyle

为指定范围内容设置指定类型新样式。

setStyle(spanStyle: SpanStyle): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| spanStyle | [SpanStyle](#spanstyle对象说明) | 是   | 样式对象。<br/>**说明：** <br/>默认不清空原有样式，叠加新样式。若是已有样式，则更新。 |

### removeStyle

清除指定范围内容的指定类型样式。

被清空样式类型对象属性使用的是对应[Text](./ts-basic-components-text.md)组件属性的设置值，若Text组件未设置值，则使用对应Text组件属性的默认值。

removeStyle(start: number , length: number , styledKey: StyledStringKey): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 指定范围开始位置的下标。 |
| length | number | 是   | 指定范围的长度。 |
| styledKey | [StyledStringKey](ts-appendix-enums.md#styledstringkey12) | 是   | 样式类型枚举值。 |

### removeStyles

清除指定范围内容的所有样式。

被清空样式类型对象属性使用的是对应[Text](./ts-basic-components-text.md)组件属性的设置值，若Text组件未设置值，则使用对应Text组件属性的默认值。

removeStyles(start: number , length: number): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 指定范围开始位置的下标。 |
| length | number | 是   | 指定范围的长度。 |

### clearStyles

清除属性字符串对象的所有样式。

被清空样式类型对象属性使用的是对应[Text](./ts-basic-components-text.md)组件属性的设置值，若Text组件未设置值，则使用对应Text组件属性的默认值。

clearStyles(): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### replaceStyledString

替换指定范围为新的属性字符串。

replaceStyledString(start: number , length: number , other: StyledString): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 指定范围开始位置的下标。 |
| length | number | 是   | 指定范围的长度。 |
| other | [StyledString](#styledstring) | 是   | 新的属性字符串对象。 |

### insertStyledString

在指定位置插入新的属性字符串。

insertStyledString(start: number , other: StyledString): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| start | number | 是   | 开始插入位置的下标。 |
| other | [StyledString](#styledstring) | 是   | 新的属性字符串对象。|

### appendStyledString

在末尾位置追加新的属性字符串。

appendStyledString(other: StyledString): void

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| other | [StyledString](#styledstring) | 是   | 新的属性字符串对象。|

## StyleOptions对象说明

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| start | number | 否   | 设置属性字符串样式的开始位置。 |
| length | number | 否   | 设置属性字符串样式的长度。 |
| styledKey | [StyledStringKey](ts-appendix-enums.md#styledstringkey12) | 是   | 样式类型的枚举值。 |
| styledValue | [StyledStringValue](ts-types.md#styledstringvalue12) | 是   | 样式对象。 |

## SpanStyle对象说明

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| start | number | 是   | 匹配属性字符串样式的开始位置。 |
| length | number | 是   | 匹配属性字符串样式的长度。 |
| styledKey | [StyledStringKey](ts-appendix-enums.md#styledstringkey12) | 是   | 样式类型的枚举值。 |
| styledValue | [StyledStringValue](ts-types.md#styledstringvalue12) | 是   | 样式对象。 |

## TextStyle

文本字体样式对象说明。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型              | 只读   | 必填   | 说明     |
| ------------ |---------------------| ---- | ---- | ------ |
| fontColor  | [ResourceColor](ts-types.md#resourcecolor) |  是  |  否  | 获取属性字符串的文本颜色。 |
| fontFamily | string   | 是    | 否    | 获取属性字符串的文本字体。 |
| fontSize   | number   | 是    | 否    | 获取属性字符串的文本字体大小。 |
| fontWeight   | number   | 是    | 否    | 获取属性字符串的文本字体粗细。 |
| fontStyle   | [FontStyle](ts-appendix-enums.md#fontstyle) | 是    | 否    | 获取属性字符串的文本字体样式。 |

### constructor

constructor(value?: TextStyleInterface)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| value | [TextStyleInterface](#textstyleinterface对象说明) | 否   | 字体样式设置项。 |

## TextStyleInterface对象说明

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 否   | 字体颜色。 |
| fontFamily | [ResourceStr](ts-types.md#resourcestr) | 否   | 文本字体。 |
| fontSize | [LengthMetric](../js-apis-arkui-graphics.md#lengthmetric12) | 否   | 字体大小。如果LengthMetric的unit值是percent，当前设置不生效，处理为0vp。 |
| fontWeight | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string | 否   | 字体粗细。 |
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle) | 否   | 字体样式。 |

## GestureStyle

事件手势对象说明。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(value?: GestureStyleInterface)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| value | [GestureStyleInterface](#gesturestyleinterface对象说明) | 否   | 事件设置项。 |

## GestureStyleInterface对象说明

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| onClick | CallBack\<[ClickEvent](ts-universal-events-click.md#clickevent对象说明)> | 否   | 设置点击事件。 |
| onLongPress | CallBack\<[GestureEvent](./ts-gesture-settings.md#gestureevent对象说明)> | 否   | 设置长按事件。 |

## DecorationStyle

文本装饰线样式对象说明。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型              | 只读   | 必填   | 说明     |
| ------------ |---------------------| ---- | ---- | ------ |
| type  | [TextDecorationType](ts-appendix-enums.md#textdecorationtype) |  是  |  是  | 获取属性字符串的文本下划线类型。 |
| color | [ResourceColor](ts-types.md#resourcecolor)   | 是    | 否    | 获取属性字符串的文本下划线颜色。 |

### constructor

constructor(value: DecorationStyleInterface)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| value | [DecorationStyleInterface](#decorationstyleinterface对象说明) | 是   | 事件设置项。 |

## DecorationStyleInterface对象说明

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| type | [TextDecorationType](ts-appendix-enums.md#textdecorationtype) | 是   | 下划线类型。 |
| color | [ResourceColor](ts-types.md#resourcecolor) | 否   | 下划线颜色。 |

## BaselineOffsetStyle

文本基线偏移量对象说明。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型              | 只读   | 必填   | 说明     |
| ------------ |---------------------| ---- | ---- | ------ |
| baselineOffset  | number |  是  |  是  | 获取属性字符串的文本基线偏移量。 |

### constructor

constructor(value: LengthMetric)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| value | [LengthMetric](../js-apis-arkui-graphics.md#lengthmetric12) | 是   | 文本基线偏移量设置项。如果LengthMetric的unit值是percent，该设置不生效。 |

## LetterSpacingStyle

文本字符间距对象说明。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型              | 只读   | 必填   | 说明     |
| ------------ |---------------------| ---- | ---- | ------ |
| letterSpacing  | number |  是  |  是  | 获取属性字符串的文本字符间距。 |

### constructor

constructor(value: LengthMetric)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| value | [LengthMetric](../js-apis-arkui-graphics.md#lengthmetric12) | 是   | 文本字符间距设置项。如果LengthMetric的unit值是percent，该设置不生效。 |

## TextShadowStyle

文本阴影对象说明。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型              | 只读   | 必填   | 说明     |
| ------------ |---------------------| ---- | ---- | ------ |
| textShadow  | Array\<[ShadowOptions](ts-universal-attributes-image-effect.md#shadowoptions对象说明)> |  是  |  是  | 获取属性字符串的文本阴影。 |

### constructor

constructor(value: ShadowOptions | Array\<ShadowOptions>)

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| value | [ShadowOptions](ts-universal-attributes-image-effect.md#shadowoptions对象说明) \| Array\<[ShadowOptions](ts-universal-attributes-image-effect.md#shadowoptions对象说明)>  | 是   | 文本阴影设置项。 |

## 示例

### 示例1

属性字符串接口基本使用示例

```ts
// xxx.ets
@Entry
@Component
struct styled_string_demo1 {
  @State height1:number = 450;
  @State fontSize1:number = 16;
  @State fontWeight1:number = 400;
  @State color1:Color = Color.Blue;

  scroll: Scroller = new Scroller();
  fontStyleAttr1:TextStyle = new TextStyle({fontColor:Color.Blue});
  fontStyleAttr2:StyledStringValue = new TextStyle({fontColor:Color.Orange});
  // 创建可读写属性字符串的对象mutableStyledString1
  mutableStyledString1: MutableStyledString = new MutableStyledString("运动45分钟");
  // 创建构造入参有字符串和样式的对象mutableStyledString2
  mutableStyledString2: MutableStyledString = new MutableStyledString("test hello world", [{start:0, length:5, styledKey:StyledStringKey.FONT, styledValue: this.fontStyleAttr1}]);
  // 创建只读属性字符串对象styledString2
  styledString2: StyledString = new StyledString("运动45分钟");
  spanStyle1:SpanStyle = {start:0, length:5, styledKey:StyledStringKey.FONT, styledValue: new TextStyle({ fontColor:Color.Pink})};
  spanStyle2:SpanStyle = { start:0, length:2, styledKey:StyledStringKey.FONT, styledValue: new TextStyle({fontColor:Color.Red})};
  @State string1:string = '';
  @State fontColor1:ResourceColor = Color.Red;

  build(){
    Column(){
      Scroll(this.scroll){
        Column(){
          // 显示属性字符串
          Text(this.styledString2)
          Text(this.mutableStyledString1).key('mutableStyledString1')
          Text(this.mutableStyledString2).key('mutableStyledString2')
          Button('修改string1的值')
            .onClick(() => {
              let result = this.mutableStyledString1.equals(this.styledString2);
              if (result) {
                this.string1 = this.mutableStyledString1.getString();
                console.info("mutableStyledString1 content:", this.mutableStyledString1.getString());
                console.info("mutableStyledString1 length:", this.mutableStyledString1.length);
              }
            })

          // 属性字符串与Span冲突时忽略Span,以及样式与Text组件属性未冲突部分生效Text设置的属性
          Text(this.mutableStyledString1){
            Span("span and styledString test")
              .fontColor(Color.Yellow)
              .decoration({type:TextDecorationType.LineThrough})
            ImageSpan($r('app.media.icon'))
          }.key('styledString2')
          .fontColor(this.fontColor1)
          .letterSpacing(10)
          .fontSize(32)
          .fontWeight(600)
          .fontStyle(FontStyle.Italic)
          .lineHeight(30)
          .textShadow({radius:5, color:Color.Blue, offsetX: 5, offsetY:5})
          .textCase(TextCase.UpperCase)
          .decoration({type:TextDecorationType.LineThrough, color: Color.Yellow})
          .baselineOffset(2)
          .copyOption(CopyOptions.InApp)
          .margin({top: 10})
          .draggable(true)

          // 以上冲突测试对照组
          Text(){
            Span(this.string1)
              .fontColor(this.color1)
              .decoration({type:TextDecorationType.LineThrough})
            ImageSpan($r('app.media.icon'))
              .width(50).height(50)
          }
          .letterSpacing(10)
          .fontSize(32)
          .fontWeight(600)
          .fontStyle(FontStyle.Italic)
          .lineHeight(30)
          .textShadow({radius:5, color:Color.Blue, offsetX: 5, offsetY:5})
          .textCase(TextCase.UpperCase)
          .decoration({type:TextDecorationType.LineThrough, color: Color.Yellow})
          .baselineOffset(2)

          Button('设置样式及替换文本')
            .onClick(() => {
              this.mutableStyledString1.replaceStyle({start:2, length: 2, styledKey:StyledStringKey.FONT, styledValue:this.fontStyleAttr1})
              this.mutableStyledString1.insertString(0,"压力85偏高，")
              this.mutableStyledString1.setStyle({start:2, length:2, styledKey:StyledStringKey.FONT, styledValue:this.fontStyleAttr2})
            })
            .margin({top: 10})

          Button('查询样式及清空样式')
            .onClick(() => {
              let styles = this.mutableStyledString1.getStyles(0,this.mutableStyledString1.length)
              if ( styles.length == 2 ) {
                for (let i = 0; i < styles.length; i++) {
                  console.info('StyledString style object start:' + styles[i].start)
                  console.info('StyledString style object length:' + styles[i].length)
                  console.info('StyledString style object key:' + styles[i].styledKey)
                  if (styles[i].styledKey === 0) {
                    let fontAttr = styles[i].styledValue as TextStyle;
                    console.info('StyledString fontColor:' + fontAttr.fontColor)
                  }
                }
              }
              this.mutableStyledString2.setStyle(styles[0]);
              this.mutableStyledString1.removeStyles(2, 3);
            })
            .margin({top: 10})
        }.width('100%')

      }.expandSafeArea([SafeAreaType.KEYBOARD])
      .scrollable(ScrollDirection.Vertical)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Gray)
      .scrollBarWidth(10)
      .edgeEffect(EdgeEffect.None)
    }
    .width('100%')
  }
}
```

![](figures/styledstring_1.jpeg)

### 示例2

属性字符串支持事件接口示例

```ts
// xxx.ets
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct styled_string_demo2 {
  scroll: Scroller = new Scroller();
  fontStyleAttr1: TextStyle = new TextStyle({ fontColor: Color.Blue });
  clickGestureAttr: GestureStyle = new GestureStyle({
    onClick: () => {
      promptAction.showToast({ message: 'clickGestureAttr object trigger click event' })
      this.backgroundColor1 = Color.Yellow
    }
  })
  gestureStyleAttr: GestureStyle = new GestureStyle({
    onClick: () => {
      promptAction.showToast({ message: 'gestureStyleAttr object trigger click event' })
      this.backgroundColor1 = Color.Green
    },
    onLongPress: () => {
      promptAction.showToast({ message: 'gestureStyleAttr object trigger long press event' })
      this.backgroundColor1 = Color.Orange
    }
  });
  // 创建事件的对象mutableStyledString3
  mutableStyledString3: MutableStyledString = new MutableStyledString("hello world", [{
    start: 0,
    length: 5,
    styledKey: StyledStringKey.GESTURE,
    styledValue: this.clickGestureAttr
  },
    {
      start: 0,
      length: 5,
      styledKey: StyledStringKey.FONT,
      styledValue: this.fontStyleAttr1
    },
    {
      start: 6,
      length: 5,
      styledKey: StyledStringKey.GESTURE,
      styledValue: this.gestureStyleAttr
    },
    {
      start: 6,
      length: 5,
      styledKey: StyledStringKey.FONT,
      styledValue: new TextStyle({ fontColor: Color.Pink })
    }]);
  @State fontColor1: ResourceColor = Color.Red;
  @State backgroundColor1: ResourceColor | undefined = undefined;

  build() {
    Column() {
      Scroll(this.scroll) {
        Column({ space: 30 }) {
          Button("响应属性字符串事件改变背景色").backgroundColor(this.backgroundColor1).width('80%')
          // 包含事件的属性字符串
          Text(this.mutableStyledString3).fontSize(30)
            .copyOption(CopyOptions.InApp)
            .draggable(true)
            .clip(true)
        }.width('100%')
      }
      .expandSafeArea([SafeAreaType.KEYBOARD])
      .scrollable(ScrollDirection.Vertical)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Gray)
      .scrollBarWidth(10)
      .edgeEffect(EdgeEffect.None)
    }
    .width('100%')
  }
}
```

![](figures/styledstring_2.png)

### 示例3

属性字符串支持文本样式接口示例

```ts
// xxx.ets
import { LengthMetrics, LengthUnit } from '@ohos.arkui.node'

@Entry
@Component
struct styled_string_demo3 {
  fontStyleAttr1: TextStyle = new TextStyle({ fontColor: Color.Blue });
  fontStyleAttr2: StyledStringValue = new TextStyle({
    fontColor: Color.Orange,
    fontSize: LengthMetrics.vp(20),
    fontWeight: FontWeight.Bolder,
    fontStyle: FontStyle.Italic,
    fontFamily: "Arial"
  });
  fontStyleAttr3: StyledStringValue = new TextStyle({
    fontColor: Color.Orange,
    fontSize: LengthMetrics.vp(20),
    fontWeight: FontWeight.Lighter,
    fontStyle: FontStyle.Italic,
    fontFamily: "Arial"
  });
  // 创建多重TextStyle样式的对象mutableStyledString1
  mutableStyledString1: MutableStyledString = new MutableStyledString("运动45分钟", [{
    start: 0,
    length: 2,
    styledKey: StyledStringKey.FONT,
    styledValue: this.fontStyleAttr3
  }, {
    start: 2,
    length: 2,
    styledKey: StyledStringKey.FONT,
    styledValue: this.fontStyleAttr2
  }
  ]);
  // 创建有多种样式组合对象mutableStyledString2
  mutableStyledString2: MutableStyledString = new MutableStyledString("test hello world", [{
    start: 0,
    length: 5,
    styledKey: StyledStringKey.FONT,
    styledValue: this.fontStyleAttr1
  }, {
    start: 0,
    length: 5,
    styledKey: StyledStringKey.DECORATION,
    styledValue: new DecorationStyle({ type: TextDecorationType.LineThrough, color: Color.Blue })
  }, {
    start: 0,
    length: 5,
    styledKey: StyledStringKey.TEXT_SHADOW,
    styledValue: new TextShadowStyle({
      radius: 5,
      type: ShadowType.COLOR,
      color: Color.Yellow,
      offsetX: 10,
      offsetY: -10
    })
  }, {
    start: 0,
    length: 5,
    styledKey: StyledStringKey.BASELINE_OFFSET,
    styledValue: new BaselineOffsetStyle(LengthMetrics.px(20))
  }, {
    start: 0,
    length: 5,
    styledKey: StyledStringKey.LETTER_SPACING,
    styledValue: new LetterSpacingStyle(new LengthMetrics(10, LengthUnit.VP))
  }, {
    start: 6,
    length: 5,
    styledKey: StyledStringKey.BASELINE_OFFSET,
    styledValue: new BaselineOffsetStyle(LengthMetrics.fp(10))
  }
  ]);
  @State fontColor1: ResourceColor = Color.Red;
  controller: TextController = new TextController();
  options: TextOptions = { controller: this.controller };
  controller2: TextController = new TextController();
  spanStyle1: SpanStyle = {
    start: 0,
    length: 5,
    styledKey: StyledStringKey.FONT,
    styledValue: new TextStyle({ fontColor: Color.Pink })
  };

  async onPageShow() {
    this.controller.setStyledString(this.mutableStyledString1)
    this.controller2.setStyledString(this.mutableStyledString2)
  }

  build() {
    Column() {
      Column({ space: 10 }) {
        // 显示配了字体各种样式的属性字符串，Text组件亦配置冲突部分生效属性字符串配置，未冲突区间生效Text组件属性设置值
        Text(undefined, this.options)
          .fontColor(this.fontColor1)
          .font({ size: 20, weight: 500, style: FontStyle.Normal })
        // 显示配置了文本阴影、划线、字符间距、基线偏移量的属性字符串，Text组件亦配置生效属性字符串配置
        Text(undefined, { controller: this.controller2 })
          .fontSize(30)
          .copyOption(CopyOptions.InApp)
          .draggable(true)
          .decoration({ type: TextDecorationType.Overline, color: Color.Pink })
          .textShadow({
            radius: 10,
            type: ShadowType.COLOR,
            color: Color.Green,
            offsetX: -10,
            offsetY: 10
          })
        Button('查询字体样式')
          .onClick(() => {
            let styles = this.mutableStyledString1.getStyles(0, this.mutableStyledString1.length)
            if (styles.length !== 0) {
              for (let i = 0; i < styles.length; i++) {
                console.info('mutableStyledString1 style object start:' + styles[i].start)
                console.info('mutableStyledString1 style object length:' + styles[i].length)
                console.info('mutableStyledString1 style object key:' + styles[i].styledKey)
                if (styles[i].styledKey === 0) {
                  let fontAttr = styles[i].styledValue as TextStyle;
                  console.info('mutableStyledString1 fontColor:' + fontAttr.fontColor)
                  console.info('mutableStyledString1 fontSize:' + fontAttr.fontSize)
                  console.info('mutableStyledString1 fontWeight:' + fontAttr.fontWeight)
                  console.info('mutableStyledString1 fontStyle:' + fontAttr.fontStyle)
                  console.info('mutableStyledString1 fontStyle:' + fontAttr.fontFamily)
                }
              }
            }
          })
          .margin({ top: 10 })
        Button('查询其他文本样式')
          .onClick(() => {
            let styles = this.mutableStyledString2.getStyles(0, this.mutableStyledString2.length)
            if (styles.length !== 0) {
              for (let i = 0; i < styles.length; i++) {
                console.info('mutableStyledString2 style object start:' + styles[i].start)
                console.info('mutableStyledString2 style object length:' + styles[i].length)
                console.info('mutableStyledString2 style object key:' + styles[i].styledKey)
                if (styles[i].styledKey === 1) {
                  let decoAttr = styles[i].styledValue as DecorationStyle;
                  console.info('mutableStyledString2 decoration type:' + decoAttr.type)
                  console.info('mutableStyledString2 decoration color:' + decoAttr.color)
                }
                if (styles[i].styledKey === 2) {
                  let baselineAttr = styles[i].styledValue as BaselineOffsetStyle;
                  console.info('mutableStyledString2 baselineOffset:' + baselineAttr.baselineOffset)
                }
                if (styles[i].styledKey === 3) {
                  let letterAttr = styles[i].styledValue as LetterSpacingStyle;
                  console.info('mutableStyledString2 letterSpacing:' + letterAttr.letterSpacing)
                }
                if (styles[i].styledKey === 4) {
                  let textShadowAttr = styles[i].styledValue as TextShadowStyle;
                  let shadowValues = textShadowAttr.textShadow;
                  if (shadowValues.length > 0) {
                    for (let j = 0; j < shadowValues.length; j++) {
                      console.info('mutableStyledString2 textShadow type:' + shadowValues[j].type);
                      console.info('mutableStyledString2 textShadow radius:' + shadowValues[j].radius);
                      console.info('mutableStyledString2 textShadow color:' + shadowValues[j].color);
                      console.info('mutableStyledString2 textShadow offsetX:' + shadowValues[j].offsetX);
                      console.info('mutableStyledString2 textShadow offsetY:' + shadowValues[j].offsetY);
                    }
                  }
                }
              }
            }
          })
          .margin({ top: 10 })
        Button('更新mutableStyledString1样式')
          .onClick(() => {
            this.mutableStyledString1.setStyle(this.spanStyle1)
            this.controller.setStyledString(this.mutableStyledString1)
          })
          .margin({ top: 10 })
      }.width('100%')
    }
    .width('100%')
  }
}
```
![](figures/styledstring_3.png)

















