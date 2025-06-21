# @ohos.arkui.shape (形状)

在 clipShape 和 maskShape 接口中可以传入对应的形状。


> **说明：**
>
> 从API version 12开始支持。后续版本的新增形状，采用上角标单独标记形状的起始版本。
>
> 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## 导入模块

```ts
import { CircleShape, EllipseShape, PathShape, RectShape } from "@kit.ArkUI";
```

## CircleShape

用于 clipShape 和 maskShape 接口的圆形形状。

继承自[BaseShape](#baseshape)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: ShapeSize)

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [ShapeSize](#shapesize) | 否 | 形状的大小。 |

## EllipseShape

用于 clipShape 和 maskShape 接口的椭圆形状。

继承自[BaseShape](#baseshape)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: ShapeSize)

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [ShapeSize](#shapesize) | 否 | 形状的大小。 |

## PathShape

用于 clipShape 和 maskShape 接口的路径。

继承自[CommonShapeMethod](#commonshapemethod)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: PathShapeOptions)

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [PathShapeOptions](#pathshapeoptions) | 否 | 路径参数。 |

### commands

commands(commands: string): PathShape

设置路径的绘制指令。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| commands | string | 是 | 路径的绘制指令。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| PathShape | 返回PathShape对象。 |

## RectShape

用于 clipShape 和 maskShape 接口的矩形形状。

继承自[BaseShape](#baseshape)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: RectShapeOptions | RoundRectShapeOptions)

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [RectShapeOptions](#rectshapeoptions) &nbsp;\|&nbsp; [RoundRectShapeOptions](#roundrectshapeoptions) | 否 | 矩形形状参数。 |

### radiusWidth

radiusWidth(rWidth: number | string): RectShape

设置矩形形状圆角半径的宽度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| rWidth | number &nbsp;\|&nbsp; string | 是 | 矩形形状圆角半径的宽度。<br/> 类型为number时取值范围是[0, +∞)，string时是length。 | 

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| RectShape | 返回RectShape对象。 |

### radiusHeight

radiusHeight(rHeight: number | string): RectShape

设置矩形形状圆角半径的高度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| rHeight | number &nbsp;\|&nbsp; string | 是 | 矩形形状圆角半径的高度。 <br/> 类型为number时取值范围是[0, +∞)，string时是length。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| RectShape | 返回RectShape对象。 |

### radius

radius(radius: number | string | Array<number &nbsp;\|&nbsp; string>): RectShape

设置矩形形状的圆角半径。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| radius | number &nbsp;\|&nbsp; string &nbsp;\|&nbsp; Array<number &nbsp;\|&nbsp; string> | 是 | 矩形形状的圆角半径。仅接受数组的前四个元素，分别为矩形左上，右上，左下，右下的圆角半径。<br/> 类型为number时取值范围是[0, +∞)，string时是length。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| RectShape | 返回RectShape对象。 |


## ShapeSize

形状的尺寸参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填                                             | 说明                                         |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| width | number &nbsp;\|&nbsp; string | 否 | 形状的宽度。<br/> 类型为number时取值范围是[0, +∞)，string时是length。 |<br/>单位：vp |
| height | number &nbsp;\|&nbsp; string | 否 | 形状的高度。 <br/> 类型为number时取值范围是[0, +∞)，string时是length。 |<br/>单位：vp|

## PathShapeOptions

PathShape 的构造函数参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填                                             | 说明                                         |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| commands | string | 否 | 绘制路径的指令。更多说明请参考commands支持的[绘制命令](./arkui-ts/ts-drawing-components-path.md#commands)。 |

## RectShapeOptions

RectShape 的构造函数参数。

继承自[ShapeSize](#shapesize)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填                                             | 说明                                         |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| radius | number &nbsp;\|&nbsp; string &nbsp;\|&nbsp; Array<number &nbsp;\|&nbsp; string> | 否 | 矩形形状的圆角半径。<br/> 类型为number时取值范围是[0, +∞)，string时是length。 |

## RoundRectShapeOptions

RectShape 带有半径的构造函数参数。

继承自[ShapeSize](#shapesize)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 必填                                             | 说明                                         |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| radiusWidth | number &nbsp;\|&nbsp; string | 否 | 矩形形状圆角半径的宽度。<br/> 类型为number时取值范围是[0, +∞)，string时是length。 |
| radiusHeight | number &nbsp;\|&nbsp; string | 否 | 矩形形状圆角半径的高度。<br/> 类型为number时取值范围是[0, +∞)，string时是length。 |

## BaseShape

继承自[CommonShapeMethod](#commonshapemethod)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### width

width(width: Length): T

设置形状的宽度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| width | [Length](arkui-ts/ts-types.md#length) | 是 | 形状的宽度。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象。 |

### height

height(height: Length): T

设置形状的高度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| height | [Length](arkui-ts/ts-types.md#length) | 是 | 形状的高度。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象。 |

### size

size(size: SizeOptions): T

设置形状的大小。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| size | [SizeOptions](arkui-ts/ts-types.md#sizeoptions) | 是 | 形状的大小。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象。 |

## CommonShapeMethod

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### offset

offset(offset: Position): T

设置相对于组件布局位置的坐标偏移。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| offset | [Position](arkui-ts/ts-types.md#position) | 是 | 相对于组件布局位置的坐标偏移。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象。 |


### fill

fill(color: ResourceColor): T

设置形状的填充区域的透明度，黑色表示完全透明，白色表示完全不透明。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| color | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 是 | 形状的填充区域的透明度，黑色表示完全透明，白色表示完全不透明。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象。 |


### position

position(position: Position): T

设置形状的位置。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| position | [Position](arkui-ts/ts-types.md#position) | 是 | 设置形状的位置。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象。 |

## **示例**

```ts
import { CircleShape, EllipseShape, PathShape, RectShape } from "@kit.ArkUI";

@Entry
@Component
struct ShapeExample {
  build() {
    Column({ space: 15 }) {
      Text('CircleShape, position').fontSize(20).width('75%').fontColor('#DCDCDC')
      Image($r('app.media.startIcon'))
        .clipShape(new CircleShape({ width: '280px', height: '280px' }).position({ x: '20px', y: '20px' }))
        .width('500px').height('280px')

      Text('EllipseShape, offset').fontSize(20).width('75%').fontColor('#DCDCDC')
      Image($r('app.media.startIcon'))
        .clipShape(new EllipseShape({ width: '350px', height: '280px' }).offset({ x: '10px', y: '10px' }))
        .width('500px').height('280px')

      Text('PathShape, fill').fontSize(20).width('75%').fontColor('#DCDCDC')
      Image($r('app.media.startIcon'))
        .maskShape(new PathShape().commands('M100 0 L200 240 L0 240 Z').fill(Color.Red))
        .width('500px').height('280px')
    
      Text('RectShape, width, height, fill').fontSize(20).width('75%').fontColor('#DCDCDC')
      Image($r('app.media.startIcon'))
        .maskShape(new RectShape().width('350px').height('280px').fill(Color.Red))
        .width('500px').height('280px')
    }
    .width('100%')
    .margin({ top: 15 })
  }
}
```
