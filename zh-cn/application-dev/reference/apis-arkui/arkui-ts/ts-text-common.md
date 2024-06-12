# 文本组件公共接口

>**说明：**
>
>文本类组件公共接口。
>本模块首批接口从API version 10开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CaretStyle<sup>10+</sup>

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 组件内容的总行数。 |

### getGlyphPositionAtCoordinate

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

获取较为接近给定坐标的字形的位置信息。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

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

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**参数：**

| 参数名    | 类型   | 必填   | 说明                 |
| ------ | ------ | ---- | -------------------- |
| lineNumber | number | 是    | 行号。从0开始。 |

**返回值：**

| 类型                                       | 说明       |
| ---------------------------------------- | -------- |
| LineMetrics | 行信息、文本样式信息、以及字体属性信息。 |

## PositionWithAffinity

位置以及亲和度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                   | 只读 | 必填 | 说明                      |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | 是   | 是   | 字形相对于组件内容的索引，整数。  |
| affinity  | [Affinity](../../apis-arkgraphics2d/js-apis-graphics-text.md#affinity) | 是   | 是   | 位置亲和度。             |