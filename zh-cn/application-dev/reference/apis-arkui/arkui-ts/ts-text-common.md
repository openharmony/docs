# 文本组件公共接口

>**说明：**
>
>文本类组件公共接口。
>本模块首批接口从API version 10开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CaretStyle<sup>10+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 参数名 | 参数类型                                   | 必填 | 参数描述 |
| ------ | ------------------------------------------ | ---- | -------- |
| width  | [Length](ts-types.md#length)               | 否   | 光标尺寸，不支持百分比。 |
| color  | [ResourceColor](ts-types.md#resourcecolor) | 否   | 光标颜色。 |

## LayoutManager<sup>12+</sup>

布局管理器对象。

### 导入对象
以Text组件为例
```
controller: TextController = new TextController()
let layoutManager: LayoutManager = this.controller.getLayoutManager();
```

### getLineCount

getLineCount(): number

获取组件内容的总行数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 组件内容的总行数。 |

### getGlyphPositionAtCoordinate

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

获取较为接近给定坐标的字形的位置信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名    | 类型   | 必填   | 说明                 |
| ------ | ------ | ---- | -------------------- |
| x | number | 是    | 相对于组件的横坐标，单位px |
| y | number | 是    | 相对于组件的纵坐标，单位px |

**返回值：**

| 类型                                          | 说明        |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity) | 字形位置信息。|

### getLineMetrics

getLineMetrics(lineNumber: number): LineMetrics

获取指定行的行信息、文本样式信息、以及字体属性信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名    | 类型   | 必填   | 说明                 |
| ------ | ------ | ---- | -------------------- |
| lineNumber | number | 是    | 行号。从0开始。 |

**返回值：**

| 类型                                       | 说明       |
| ---------------------------------------- | -------- |
| [LineMetrics](../../apis-arkgraphics2d/js-apis-graphics-text.md#linemetrics) | 行信息、文本样式信息、以及字体属性信息。 |

### getRectsForRange<sup>13+</sup>

getRectsForRange(range: Range, widthStyle: RectWidthStyle, heightStyle: RectHeightStyle): Array\<TextBox>

获取给定的矩形区域宽度以及矩形区域高度的规格下，文本中任意区间范围内的字符或占位符所占的绘制区域信息。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                 | 必填 | 说明                     |
| ----------- | ----------------------------------- | ---- | ------------------------ |
| range       | [Range](../../apis-arkgraphics2d/js-apis-graphics-text.md#range)                     | 是   | 需要获取的区域的文本区间。  |
| widthStyle  | [RectWidthStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectwidthstyle)   | 是   | 返回的矩形区域的宽度的规格。|
| heightStyle | [RectHeightStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectheightstyle) | 是   | 返回的矩形区域的高度的规格。|

**返回值：**

| 类型                         | 说明        |
| --------------------------- | ----------- |
| Array\<[TextBox](../../apis-arkgraphics2d/js-apis-graphics-text.md#textbox)> | 矩形区域数组。|

## PositionWithAffinity

位置以及亲和度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                   | 只读 | 必填 | 说明                      |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | 是   | 是   | 字形相对于组件内容的索引，整数。  |
| affinity  | [Affinity](../../apis-arkgraphics2d/js-apis-graphics-text.md#affinity) | 是   | 是   | 位置亲和度。             |

## ExpandedMenuItemOptions<sup>12+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名 | 参数类型                                   | 必填 | 参数描述 |
| ------ | ------------------------------------------ | ---- | -------- |
| content   | [ResourceStr](ts-types.md#resourcestr)  | 是     | 显示内容。     |
| startIcon | [ResourceStr](ts-types.md#resourcestr)  | 否     | 显示图标，不支持引用SymbolSpan和网络图片。     |
| action    | Callback\<[TextRange](ts-universal-attributes-text-style.md#textrange12)>  | 是     | 选中的文本信息。|    