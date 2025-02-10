# Graphics

自定义节点相关属性定义的详细信息。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { DrawContext, Size, Offset, Position, Pivot, Scale, Translation, Matrix4, Rotation, Frame, LengthMetricsUnit } from "@kit.ArkUI";
```

## Size

用于返回组件布局大小的宽和高。默认单位为vp，不同的接口使用Size类型时会再定义单位，以接口定义的单位为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 可读 | 可写 | 说明                   |
| ------ | ------ | ---- | ---- | ---------------------- |
| width  | number | 是   | 是   | 组件大小的宽度。<br/>单位：vp |
| height | number | 是   | 是   | 组件大小的高度。<br/>单位：vp |

## Position

type Position = Vector2

用于设置或返回组件的位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                | 说明                                |
| ------------------- | ----------------------------------- |
| [Vector2](#vector2) | 包含x和y两个值的向量。<br/>单位：vp |

## PositionT<sup>12+</sup>

type PositionT\<T> = Vector2T\<T>

用于设置或返回组件的位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                         | 说明                                |
| ---------------------------- | ----------------------------------- |
| [Vector2T\<T>](#vector2tt12) | 包含x和y两个值的向量。<br/>单位：vp |

## Frame

用于设置或返回组件的布局大小和位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 只读 | 可选 | 说明                        |
| ------ | ------ | ---- | ---- | --------------------------- |
| x      | number | 是   | 是   | 水平方向位置。<br/>单位：vp |
| y      | number | 是   | 是   | 垂直方向位置。<br/>单位：vp |
| width  | number | 是   | 是   | 组件的宽度。<br/>单位：vp   |
| height | number | 是   | 是   | 组件的高度。<br/>单位：vp   |

## Pivot

type Pivot = Vector2

用于设置组件的轴心坐标，轴心会作为组件的旋转/缩放中心点，影响旋转和缩放效果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| [Vector2](#vector2) | 轴心的x和y轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。 |

## Scale

type Scale = Vector2

用于设置组件的缩放比例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                | 说明                                            |
| ------------------- | ----------------------------------------------- |
| [Vector2](#vector2) | x和y轴的缩放参数。该参数为浮点数，默认值为1.0。 |

## Translation

type Translation = Vector2

用于设置组件的平移量。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| [Vector2](#vector2) | x和y轴的平移量。<br/>单位：px |

## Rotation

type Rotation = Vector3

用于设置组件的旋转角度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| [Vector3](#vector3) | x、y、z轴方向的旋转角度。<br/>单位：度 |

## Offset

type Offset = Vector2

用于设置组件或效果的偏移。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| [Vector2](#vector2) | x和y轴方向的偏移量。<br/>单位：vp |

## Matrix4

type Matrix4 = [number,number,number,number,number,number,number,number,number,number,number,number,number,number,number,number]

设置四阶矩阵。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| [number,number,number,number,<br/>number,number,number,number,<br/>number,number,number,number,<br/>number,number,number,number] | 参数为长度为16（4\*4）的number数组。 |

用于设置组件的变换信息，该类型为一个 4x4 矩阵，使用一个长度为16的`number[]`进行表示，例如：
```ts
const transform: Matrix4 = [
  1, 0, 45, 0,
  0, 1,  0, 0,
  0, 0,  1, 0,
  0, 0,  0, 1
]
```

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## Vector2

用于表示包含x和y两个值的向量。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 只读 | 可选 | 说明              |
| ---- | ------ | ---- | ---- | ----------------- |
| x    | number | 否   | 否   | 向量x轴方向的值。 |
| y    | number | 否   | 否   | 向量y轴方向的值。 |

## Vector3

用于表示包含x、y、z三个值的向量。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 只读 | 可选 | 说明                |
| ---- | ------ | ---- | ---- | ------------------- |
| x    | number | 否   | 否   | x轴方向的旋转角度。 |
| y    | number | 否   | 否   | y轴方向的旋转角度。 |
| z    | number | 否   | 否   | z轴方向的旋转角度。 |

## Vector2T\<T><sup>12+</sup>

用于表示T类型的包含x和y两个值的向量。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 只读 | 可选 | 说明              |
| ---- | ------ | ---- | ---- | ----------------- |
| x    | T | 否  | 否  | 向量x轴方向的值。 |
| y    | T | 否  | 否  | 向量y轴方向的值。 |

## DrawContext

图形绘制上下文，提供绘制所需的画布宽度和高度。

### size

get size(): Size

获取画布的宽度和高度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [Size](#size) | 画布的宽度和高度。 |

### sizeInPixel<sup>12+</sup>

get sizeInPixel(): Size

获取以px为单位的画布的宽度和高度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [Size](#size) | 画布的宽度和高度，以px为单位。 |

### canvas

get canvas(): drawing.Canvas

获取用于绘制的画布。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [drawing.Canvas](../apis-arkgraphics2d/js-apis-graphics-drawing.md#canvas) | 用于绘制的画布。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, DrawContext } from "@kit.ArkUI";

class MyRenderNode extends RenderNode {
  flag: boolean = false;

  draw(context: DrawContext) {
    const size = context.size;
    const canvas = context.canvas;
    const sizeInPixel = context.sizeInPixel;
  }
}

const renderNode = new MyRenderNode();
renderNode.frame = { x: 0, y: 0, width: 100, height: 100 };
renderNode.backgroundColor = 0xffff0000;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

## Edges\<T><sup>12+</sup>

用于设置边框的属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 | 可读 | 可写 | 说明             |
| ------ | ---- | ---- | ---- | ---------------- |
| left   | T    | 是   | 是   | 左侧边框的属性。 |
| top    | T    | 是   | 是   | 顶部边框的属性。 |
| right  | T    | 是   | 是   | 右侧边框的属性。 |
| bottom | T    | 是   | 是   | 底部边框的属性。 |

## LengthUnit<sup>12+</sup>

长度属性单位枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| [PX](arkui-ts/ts-types.md#px10) | 0 | 长度类型，用于描述以px像素单位为单位的长度。 |
| [VP](arkui-ts/ts-types.md#vp10) | 1 | 长度类型，用于描述以vp像素单位为单位的长度。 |
| [FP](arkui-ts/ts-types.md#fp10) | 2 | 长度类型，用于描述以fp像素单位为单位的长度。 |
| [PERCENT](arkui-ts/ts-types.md#percentage10) | 3 | 长度类型，用于描述以%像素单位为单位的长度。 |
| [LPX](arkui-ts/ts-types.md#lpx10) | 4 | 长度类型，用于描述以lpx像素单位为单位的长度。 |

## SizeT\<T><sup>12+</sup>

用于设置宽高的属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 | 可读 | 可写 | 说明             |
| ------ | ---- | ---- | ---- | ---------------- |
| width   | T    | 是   | 是   | 宽度的属性。 |
| height    | T    | 是   | 是   | 高度的属性。 |

## LengthMetricsUnit<sup>12+</sup>

长度属性单位枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DEFAULT | 0 | 长度类型，用于描述以默认的vp像素单位为单位的长度。 |
| PX | 1 | 长度类型，用于描述以px像素单位为单位的长度。 |

## LengthMetrics<sup>12+</sup>

用于设置长度属性，当长度单位为[PERCENT](arkui-ts/ts-types.md#percentage10)时，值为1表示100%。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 | 可读 | 可写 | 说明             |
| ------------ | ---------------------------------------- | ---- | ---- | ------ |
| value       | number | 是   | 是   | 长度属性的值。   |
| unit | [LengthUnit](#lengthunit12)                                   | 是   | 是   | 长度属性的单位，默认为VP。|

### constructor<sup>12+</sup>

constructor(value: number, unit?: LengthUnit)

LengthMetrics的构造函数。若参数unit不传入值或传入undefined，返回值使用默认单位VP；若unit传入非LengthUnit类型的值，返回默认值0VP。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| value   | number | 是   | 长度属性的值。 |
| unit   | [LengthUnit](#lengthunit12) | 否   | 长度属性的单位。 |

### px<sup>12+</sup>

static px(value: number): LengthMetrics

用于生成单位为PX的长度属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| value   | number | 是   | 长度属性的值。 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [LengthMetrics](#lengthmetrics12) | LengthMetrics 类的实例。 |

### vp<sup>12+</sup>

static vp(value: number): LengthMetrics

用于生成单位为VP的长度属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| value   | number | 是   | 长度属性的值。 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [LengthMetrics](#lengthmetrics12) | LengthMetrics 类的实例。 |

### fp<sup>12+</sup>

static fp(value: number): LengthMetrics

用于生成单位为FP的长度属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| value   | number | 是   | 长度属性的值。 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [LengthMetrics](#lengthmetrics12) | LengthMetrics 类的实例。 |

### percent<sup>12+</sup>

static percent(value: number): LengthMetrics

用于生成单位为PERCENT的长度属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| value   | number | 是   | 长度属性的值。 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [LengthMetrics](#lengthmetrics12) | LengthMetrics 类的实例。 |

### lpx<sup>12+</sup>

static lpx(value: number): LengthMetrics

用于生成单位为LPX的长度属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| value   | number | 是   | 长度属性的值。 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [LengthMetrics](#lengthmetrics12) | LengthMetrics 类的实例。 |

### resource<sup>12+</sup>

static resource(value: Resource): LengthMetrics

用于生成Resource类型资源的长度属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| value   | Resource | 是   | 长度属性的值。 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [LengthMetrics](#lengthmetrics12) | LengthMetrics 类的实例。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[系统资源错误码](errorcode-system-resource.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 180001   | System resources does not exist.           |
| 180002   | The type of system resources is incorrect. |

## ColorMetrics<sup>12+</sup>

用于混合颜色。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### numeric<sup>12+</sup>

static numeric(value: number): ColorMetrics

使用HEX格式颜色实例化 ColorMetrics 类。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| value   | number | 是   | HEX格式颜色，支持rgb或者argb。 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [ColorMetrics](#colormetrics12) | ColorMetrics 类的实例。 |

### rgba<sup>12+</sup>

static rgba(red: number, green: number, blue: number, alpha?: number): ColorMetrics

使用rgb或者rgba格式颜色实例化 ColorMetrics 类。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| red   | number | 是   | 颜色的R分量（红色），值是0~255的整数。 |
| green | number | 是   | 颜色的G分量（绿色），值是0~255的整数。 |
| blue  | number | 是   | 颜色的B分量（蓝色），值是0~255的整数。 |
| alpha | number | 否   | 颜色的A分量（透明度），值是0~1.0的浮点数。 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [ColorMetrics](#colormetrics12) | ColorMetrics 类的实例。 |

### resourceColor<sup>12+</sup>

static resourceColor(color: ResourceColor): ColorMetrics

使用资源格式颜色实例化 ColorMetrics 类。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| color | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 是 | 资源格式颜色 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [ColorMetrics](#colormetrics12) | ColorMetrics 类的实例。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[系统资源错误码](errorcode-system-resource.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401   | Parameter error. Possible cause:1.The type of the input color parameter is not ResourceColor;2.The format of the input color string is not RGB or RGBA.             |
| 180003   | Failed to obtain the color resource.         |

### blendColor<sup>12+</sup>

blendColor(overlayColor: ColorMetrics): ColorMetrics

颜色混合。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| overlayColor | [ColorMetrics](#colormetrics12) | 是 | 叠加颜色的 ColorMetrics 类的实例 |

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [ColorMetrics](#colormetrics12) | 混合后的ColorMetrics 类的实例。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401   | Parameter error. The type of the input parameter is not ColorMetrics.                |

### color<sup>12+</sup>

get color(): string

获取ColorMetrics的颜色，返回的是rgba字符串的格式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| string | rgba字符串格式的颜色。 示例：'rgba(255, 100, 255, 0.5)'|

### red<sup>12+</sup>

get red(): number

获取ColorMetrics颜色的R分量（红色）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| number | 颜色的R分量（红色），值是0~255的整数。|

### green<sup>12+</sup>

get green(): number

获取ColorMetrics颜色的G分量（绿色）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| number | 颜色的G分量（绿色），值是0~255的整数。|

### blue<sup>12+</sup>

get blue(): number

获取ColorMetrics颜色的B分量（蓝色）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| number | 颜色的B分量（蓝色），值是0~255的整数。|

### alpha<sup>12+</sup>

get alpha(): number

获取ColorMetrics颜色的A分量（透明度）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| number | 颜色的A分量（透明度），值是0~255的整数。|

**示例：**

```ts
import { ColorMetrics } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

function getBlendColor(baseColor: ResourceColor): ColorMetrics {
  let sourceColor: ColorMetrics;
  try {
    //在使用ColorMetrics的resourceColor和blendColor需要追加捕获异常处理
    //可能返回的arkui子系统错误码有401和180003
    sourceColor = ColorMetrics.resourceColor(baseColor).blendColor(ColorMetrics.resourceColor("#19000000"));
  } catch (error) {
    console.log("getBlendColor failed, code = " + (error as BusinessError).code + ", message = " +
    (error as BusinessError).message);
    sourceColor = ColorMetrics.resourceColor("#19000000");
  }
  return sourceColor;
}

@Entry
@Component
struct ColorMetricsSample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button("ColorMetrics")
        .width('80%')
        .align(Alignment.Center)
        .height(50)
        .backgroundColor(getBlendColor(Color.Red).color)
    }
    .width('100%')
    .height('100%')
  }
}
```
## Corners\<T><sup>12+</sup>

用于设置四个角的圆角度数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型 | 可读 | 可写 | 说明                   |
| ----------- | ---- | ---- | ---- | ---------------------- |
| topLeft     | T    | 是   | 是   | 左上边框的圆角属性。   |
| topRight    | T    | 是   | 是   | 右上上边框的圆角属性。 |
| bottomLeft  | T    | 是   | 是   | 左下边框的圆角属性。   |
| bottomRight | T    | 是   | 是   | 右下边框的圆角属性。   |

## CornerRadius<sup>12+</sup>

type CornerRadius = Corners\<Vector2>

设置四个角的圆角度数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                         | 说明               |
| -------------------------------------------- | ------------------ |
| [Corners](#cornerst12)[\<Vector2>](#vector2) | 四个角的圆角度数。 |

## BorderRadiuses<sup>12+</sup>

type BorderRadiuses = Corners\<number>

设置四个角的圆角度数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                            | 说明               |
| ------------------------------- | ------------------ |
| [Corners\<number>](#cornerst12) | 四个角的圆角度数。 |

## Rect<sup>12+</sup>

type Rect = common2D.Rect

用于设置矩形的形状。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                                         | 说明       |
| ------------------------------------------------------------ | ---------- |
| [common2D.Rect](../apis-arkgraphics2d/js-apis-graphics-common2D.md#rect) | 矩形区域。 |

## RoundRect<sup>12+</sup>

用于设置带有圆角的矩形。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                          | 可读 | 可写 | 说明             |
| ------- | ----------------------------- | ---- | ---- | ---------------- |
| rect    | [Rect](#rect12)                 | 是   | 是   | 设置矩形的属性。 |
| corners | [CornerRadius](#cornerradius12) | 是   | 是   | 设置圆角的属性。 |

## Circle<sup>12+</sup>

用于设置圆形的属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型   | 可读 | 可写 | 说明                      |
| ------- | ------ | ---- | ---- | ------------------------- |
| centerX | number | 是   | 是   | 圆心x轴的位置，单位为px。 |
| centerY | number | 是   | 是   | 圆心y轴的位置，单位为px。 |
| radius  | number | 是   | 是   | 圆形的半径，单位为px。    |

## CommandPath<sup>12+</sup>

用于设置路径绘制的指令。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                                         | 类型   | 可读 | 可写 | 说明                                                         |
| ------------------------------------------------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| [commands](./arkui-ts/ts-drawing-components-path.md#commands-1) | string | 是   | 是   | 路径绘制的指令字符串。像素单位的转换方法请参考[像素单位转换](./arkui-ts/ts-pixel-units.md#像素单位转换)。<br/>单位：px |

## ShapeMask<sup>12+</sup>

用于设置图形遮罩。

### constructor<sup>12+</sup>

constructor()

ShapeMask的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### setRectShape<sup>12+</sup>

setRectShape(rect: Rect): void

用于设置矩形遮罩。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| rect   | [Rect](#rect12) | 是   | 矩形的形状。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask } from '@kit.ArkUI';

const mask = new ShapeMask();
mask.setRectShape({ left: 0, right: vp2px(150), top: 0, bottom: vp2px(150) });
mask.fillColor = 0X55FF0000;

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeMask = mask;


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

### setRoundRectShape<sup>12+</sup>

setRoundRectShape(roundRect: RoundRect): void

用于设置圆角矩形遮罩。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| roundRect | [RoundRect](#roundrect12) | 是   | 圆角矩形的形状。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask,RoundRect} from '@kit.ArkUI';

const mask = new ShapeMask();
const roundRect: RoundRect = {
  rect: { left: 0, top: 0, right: vp2px(150), bottom: vp2px(150) },
  corners: {
    topLeft: { x: 32, y: 32 },
    topRight: { x: 32, y: 32 },
    bottomLeft: { x: 32, y: 32 },
    bottomRight: { x: 32, y: 32 }
  }
}
mask.setRoundRectShape(roundRect);
mask.fillColor = 0X55FF0000;

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeMask = mask;


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

### setCircleShape<sup>12+</sup>

setCircleShape(circle: Circle): void

用于设置圆形遮罩。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型              | 必填 | 说明         |
| ------ | ----------------- | ---- | ------------ |
| circle | [Circle](#circle12) | 是   | 圆形的形状。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask } from '@kit.ArkUI';

const mask = new ShapeMask();
mask.setCircleShape({ centerY: vp2px(75), centerX: vp2px(75), radius: vp2px(75) });
mask.fillColor = 0X55FF0000;

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeMask = mask;


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

### setOvalShape<sup>12+</sup>

setOvalShape(oval: Rect): void

用于设置椭圆形遮罩。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型          | 必填 | 说明           |
| ------ | ------------- | ---- | -------------- |
| oval   | [Rect](#rect12) | 是   | 椭圆形的形状。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask } from '@kit.ArkUI';

const mask = new ShapeMask();
mask.setOvalShape({ left: 0, right: vp2px(150), top: 0, bottom: vp2px(100) });
mask.fillColor = 0X55FF0000;

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeMask = mask;


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

### setCommandPath<sup>12+</sup>

setCommandPath(path: CommandPath): void

用于设置路径绘制指令。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                        | 必填 | 说明           |
| ------ | --------------------------- | ---- | -------------- |
| path   | [CommandPath](#commandpath12) | 是   | 路径绘制指令。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask } from '@kit.ArkUI';

const mask = new ShapeMask();
mask.setCommandPath({ commands: "M100 0 L0 100 L50 200 L150 200 L200 100 Z" });
mask.fillColor = 0X55FF0000;

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeMask = mask;


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

### fillColor<sup>12+</sup>

fillColor: number

遮罩的填充颜色，使用ARGB格式。默认值为`0XFF000000`。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask } from '@kit.ArkUI';

const mask = new ShapeMask();
mask.setRectShape({ left: 0, right: 150, top: 0, bottom: 150 });
mask.fillColor = 0X55FF0000;

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeMask = mask;


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

### strokeColor<sup>12+</sup>

strokeColor: number

遮罩的边框颜色，使用ARGB格式。默认值为`0XFF000000`。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask } from '@kit.ArkUI';

const mask = new ShapeMask();
mask.setRectShape({ left: 0, right: 150, top: 0, bottom: 150 });
mask.strokeColor = 0XFFFF0000;
mask.strokeWidth = 24;

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeMask = mask;


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

### strokeWidth<sup>12+</sup>

strokeWidth: number

遮罩的边框宽度，单位为px。默认值为0。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask } from '@kit.ArkUI';

const mask = new ShapeMask();
mask.setRectShape({ left: 0, right: 150, top: 0, bottom: 150 });
mask.strokeColor = 0XFFFF0000;
mask.strokeWidth = 24;

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeMask = mask;


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

## ShapeClip<sup>12+</sup>

用于设置图形裁剪。

### constructor<sup>12+</sup>

constructor()

ShapeClip的构造函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

### setRectShape<sup>12+</sup>

setRectShape(rect: Rect): void

用于裁剪矩形。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| rect   | [Rect](#rect12) | 是   | 矩形的形状。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeClip } from '@kit.ArkUI';

const clip = new ShapeClip();
clip.setCommandPath({ commands: "M100 0 L0 100 L50 200 L150 200 L200 100 Z" });

const renderNode = new RenderNode();
renderNode.frame = {
  x: 0,
  y: 0,
  width: 150,
  height: 150
};
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeClip = clip;
const shapeClip = renderNode.shapeClip;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.myNodeController)
        .borderWidth(1)
      Button("setRectShape")
        .onClick(() => {
          shapeClip.setRectShape({
            left: 0,
            right: 150,
            top: 0,
            bottom: 150
          });
          renderNode.shapeClip = shapeClip;
        })
    }
  }
}
```

### setRoundRectShape<sup>12+</sup>

setRoundRectShape(roundRect: RoundRect): void

用于裁剪圆角矩形。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| roundRect | [RoundRect](#roundrect12) | 是   | 圆角矩形的形状。 |

**示例：**
```ts
import { RenderNode, FrameNode, NodeController, ShapeClip } from '@kit.ArkUI';

const clip = new ShapeClip();
clip.setCommandPath({ commands: "M100 0 L0 100 L50 200 L150 200 L200 100 Z" });

const renderNode = new RenderNode();
renderNode.frame = {
  x: 0,
  y: 0,
  width: 150,
  height: 150
};
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeClip = clip;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.myNodeController)
        .borderWidth(1)
      Button("setRoundRectShape")
        .onClick(() => {
          renderNode.shapeClip.setRoundRectShape({
            rect: {
              left: 0,
              top: 0,
              right: vp2px(150),
              bottom: vp2px(150)
            },
            corners: {
              topLeft: { x: 32, y: 32 },
              topRight: { x: 32, y: 32 },
              bottomLeft: { x: 32, y: 32 },
              bottomRight: { x: 32, y: 32 }
            }
          });
          renderNode.shapeClip = renderNode.shapeClip;
        })
    }
  }
}
```

### setCircleShape<sup>12+</sup>

setCircleShape(circle: Circle): void

用于裁剪圆形。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型              | 必填 | 说明         |
| ------ | ----------------- | ---- | ------------ |
| circle | [Circle](#circle12) | 是   | 圆形的形状。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeClip } from '@kit.ArkUI';

const clip = new ShapeClip();
clip.setCommandPath({ commands: "M100 0 L0 100 L50 200 L150 200 L200 100 Z" });

const renderNode = new RenderNode();
renderNode.frame = {
  x: 0,
  y: 0,
  width: 150,
  height: 150
};
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeClip = clip;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.myNodeController)
        .borderWidth(1)
      Button("setCircleShape")
        .onClick(() => {
          renderNode.shapeClip.setCircleShape({ centerY: 75, centerX: 75, radius: 75 });
          renderNode.shapeClip = renderNode.shapeClip;

        })
    }
  }
}
```

### setOvalShape<sup>12+</sup>

setOvalShape(oval: Rect): void

用于裁剪椭圆形。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型          | 必填 | 说明           |
| ------ | ------------- | ---- | -------------- |
| oval   | [Rect](#rect12) | 是   | 椭圆形的形状。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeClip } from '@kit.ArkUI';

const clip = new ShapeClip();
clip.setCommandPath({ commands: "M100 0 L0 100 L50 200 L150 200 L200 100 Z" });

const renderNode = new RenderNode();
renderNode.frame = {
  x: 0,
  y: 0,
  width: 150,
  height: 150
};
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeClip = clip;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.myNodeController)
        .borderWidth(1)
      Button("setOvalShape")
        .onClick(() => {
          renderNode.shapeClip.setOvalShape({
            left: 0,
            right: vp2px(150),
            top: 0,
            bottom: vp2px(100)
          });
          renderNode.shapeClip = renderNode.shapeClip;
        })
    }
  }
}
```

### setCommandPath<sup>12+</sup>

setCommandPath(path: CommandPath): void

用于裁剪路径绘制指令。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                        | 必填 | 说明           |
| ------ | --------------------------- | ---- | -------------- |
| path   | [CommandPath](#commandpath12) | 是   | 路径绘制指令。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, ShapeClip } from '@kit.ArkUI';

const clip = new ShapeClip();
clip.setCommandPath({ commands: "M100 0 L0 100 L50 200 L150 200 L200 100 Z" });

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.shapeClip = clip;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.myNodeController)
        .borderWidth(1)
      Button("setCommandPath")
        .onClick(()=>{
          renderNode.shapeClip.setCommandPath({ commands: "M100 0 L0 100 L50 200 L150 200 L200 100 Z" });
          renderNode.shapeClip = renderNode.shapeClip;
        })
    }
  }
}
```

## edgeColors<sup>12+</sup>

edgeColors(all: number): Edges\<number>

用于生成边框颜色均设置为传入值的边框颜色对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| all    | number | 是   | 边框颜色，ARGB格式。 |

**返回值：**

| 类型                     | 说明                                   |
| ------------------------ | -------------------------------------- |
| [Edges\<number>](#edgest12) | 边框颜色均设置为传入值的边框颜色对象。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, edgeColors } from '@kit.ArkUI';

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.borderWidth = { left: 8, top: 8, right: 8, bottom: 8 };
renderNode.borderColor = edgeColors(0xFF0000FF);


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

## edgeWidths<sup>12+</sup>

edgeWidths(all: number): Edges\<number>

用于生成边框宽度均设置为传入值的边框宽度对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| all    | number | 是   | 边框宽度，单位为vp。 |

**返回值：**

| 类型                     | 说明                                   |
| ------------------------ | -------------------------------------- |
| [Edges\<number>](#edgest12) | 边框宽度均设置为传入值的边框宽度对象。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, edgeWidths } from '@kit.ArkUI';

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.borderWidth = edgeWidths(8);
renderNode.borderColor = { left: 0xFF0000FF, top: 0xFF0000FF, right: 0xFF0000FF, bottom: 0xFF0000FF };


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

## borderStyles<sup>12+</sup>

borderStyles(all: BorderStyle): Edges\<BorderStyle>

用于生成边框样式均设置为传入值的边框样式对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                       | 必填 | 说明       |
| ------ | ---------------------------------------------------------- | ---- | ---------- |
| all    | [BorderStyle](./arkui-ts/ts-appendix-enums.md#borderstyle) | 是   | 边框样式。 |

**返回值：**

| 类型                                                                        | 说明                                   |
| --------------------------------------------------------------------------- | -------------------------------------- |
| [Edges](#edgest12)<[BorderStyle](./arkui-ts/ts-appendix-enums.md#borderstyle)> | 边框样式均设置为传入值的边框样式对象。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, borderStyles } from '@kit.ArkUI';

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.borderWidth = { left: 8, top: 8, right: 8, bottom: 8 };
renderNode.borderColor = { left: 0xFF0000FF, top: 0xFF0000FF, right: 0xFF0000FF, bottom: 0xFF0000FF };
renderNode.borderStyle = borderStyles(BorderStyle.Dotted);


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```

## borderRadiuses<sup>12+</sup>

borderRadiuses(all: number): BorderRadiuses

用于生成边框圆角均设置为传入值的边框圆角对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| all    | number | 是   | 边框圆角。 |

**返回值：**

| 类型                              | 说明                                   |
| --------------------------------- | -------------------------------------- |
| [BorderRadiuses](#borderradiuses12) | 边框圆角均设置为传入值的边框圆角对象。 |

**示例：**

```ts
import { RenderNode, FrameNode, NodeController, borderRadiuses }  from '@kit.ArkUI';

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 150, height: 150 };
renderNode.backgroundColor = 0XFF00FF00;
renderNode.borderRadius = borderRadiuses(32);


class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```
