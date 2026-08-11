# @ohos.arkui.shape (形状)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

@ohos.arkui.shape模块提供了CircleShape、EllipseShape、PathShape、RectShape等多种形状定义，用于在[clipShape](arkui-ts/ts-universal-attributes-sharp-clipping.md#clipshape12)和[maskShape](arkui-ts/ts-universal-attributes-sharp-clipping.md#maskshape12)接口中传入对应的形状，实现对组件的裁剪和遮罩效果。适用于需要将组件裁剪为圆形、椭圆、矩形等特定形状，或通过形状遮罩实现视觉效果的场景，如头像裁剪、图标遮罩等。


> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { CircleShape, EllipseShape, PathShape, RectShape } from '@kit.ArkUI';
```

## CircleShape

用于clipShape和maskShape接口的圆形形状。

继承自[BaseShape](#baseshape)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: ShapeSize)

创建CircleShape对象。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [ShapeSize](#shapesize) | 否 | 形状的大小，包含width（宽度）和height（高度）属性，用于设置形状的尺寸。不传入时使用默认尺寸，默认宽度0vp，默认高度0vp。 |

## EllipseShape

用于clipShape和maskShape接口的椭圆形状。

继承自[BaseShape](#baseshape)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: ShapeSize)

创建EllipseShape对象。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [ShapeSize](#shapesize) | 否 | 形状的大小，用于自定义椭圆的宽高尺寸。不传入时width和height默认值为0vp。 |

## PathShape

用于clipShape和maskShape接口的路径形状，继承自[CommonShapeMethod](#commonshapemethod)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: PathShapeOptions)

创建PathShape对象。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [PathShapeOptions](#pathshapeoptions) | 否 | 路径参数。不传入时，路径绘制指令默认为空字符串，不绘制路径。 |

### commands

commands(commands: string): PathShape

设置路径的绘制指令，用于定义PathShape的绘制路径。指令遵循SVG路径数据格式，具体支持的绘制命令请参考[commands](arkui-ts/ts-drawing-components-path.md#commands)。

> **说明：**
> - 必须设置commands（可通过构造函数PathShapeOptions.commands或本方法设置），PathShape才能在clipShape/maskShape接口中产生可见的裁剪或遮罩效果。
> - 未设置commands的PathShape为空路径，不会产生任何裁剪或遮罩效果。
> - 本方法与构造函数PathShapeOptions.commands设置的是同一属性，后调用的设置会覆盖先前的设置。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| commands | string | 是 | 路径的绘制指令，格式要求请参考[commands](arkui-ts/ts-drawing-components-path.md#commands)支持的绘制命令。传入无效指令时不产生可见路径。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| [PathShape](#pathshape) | 返回设置路径绘制指令后的PathShape对象，可用于链式调用继续配置路径形状。 |

## RectShape

用于clipShape和maskShape接口的矩形形状。

继承自[BaseShape](#baseshape)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: RectShapeOptions \| RoundRectShapeOptions)

创建RectShape对象。

> **说明：**
> - 构造函数参数中的radius/radiusWidth/radiusHeight与radius()/radiusWidth()/radiusHeight()方法设置的是同一属性。
> - 方法调用会覆盖构造函数中设置的对应属性值。
> - 建议优先通过构造函数设置初始参数，再通过方法进行额外配置或覆盖。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [RectShapeOptions](#rectshapeoptions) &nbsp;\|&nbsp; [RoundRectShapeOptions](#roundrectshapeoptions) | 否 | 矩形形状参数。不传入时使用默认尺寸，默认宽度0vp，默认高度0vp，圆角半径默认值0vp。 |

### radiusWidth

radiusWidth(rWidth: number \| string): RectShape

设置矩形形状圆角半径的宽度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| rWidth | number &nbsp;\|&nbsp; string | 是 | 矩形形状圆角半径的宽度。<br> 类型为number时取值范围是[0, +∞)，string时是[Length](arkui-ts/ts-types.md#length)。<br>单位：vp<br>取值为异常值时按照0vp处理。 | 

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| [RectShape](#rectshape) | 返回设置圆角半径后的RectShape对象，可用于链式调用继续配置矩形形状。 |

### radiusHeight

radiusHeight(rHeight: number \| string): RectShape

设置矩形形状圆角半径的高度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| rHeight | number &nbsp;\|&nbsp; string | 是 | 矩形形状圆角半径的高度。 <br> 类型为number时取值范围是[0, +∞)，string时是[Length](arkui-ts/ts-types.md#length)。<br>单位：vp<br>取值为异常值时按照0vp处理。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| [RectShape](#rectshape) | 返回设置圆角半径高度后的RectShape对象，可用于链式调用继续配置矩形形状。 |

### radius

radius(radius: number | string | Array\<number &nbsp;\|&nbsp; string\>): RectShape

设置矩形形状的圆角半径，设置后各角圆弧宽高相等（圆形弧）。与radiusWidth/radiusHeight分别设置圆弧宽高（允许椭圆弧）不同，radius可通过数组分别指定四个角的圆角半径值；需要圆形圆角时使用radius，需要椭圆形圆角时使用radiusWidth和radiusHeight。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| radius | number &nbsp;\|&nbsp; string &nbsp;\|&nbsp; Array<number &nbsp;\|&nbsp; string> | 是 | 矩形形状的圆角半径。仅接受数组的前四个元素，分别为矩形左上、右上、左下、右下的圆角半径。<br> 类型为number时取值范围是[0, +∞)，string时是[Length](arkui-ts/ts-types.md#length)。<br>单位：vp<br>取值为异常值时按照0vp处理。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| [RectShape](#rectshape) | 返回设置圆角半径宽度后的RectShape对象，可用于链式调用继续配置矩形形状。 |


## ShapeSize

形状的大小参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 只读                                             | 可选                                             | 说明                                         |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| width | number &nbsp;\|&nbsp; string | 否 | 是 | 形状的宽度。<br> 类型为number时取值范围是[0, +∞)，string时是[Length](arkui-ts/ts-types.md#length)。 <br>单位：vp<br>默认值：0vp<br>取值为异常值时按照0vp处理。<br>不设置时默认值为0vp。 |
| height | number &nbsp;\|&nbsp; string | 否 | 是 | 形状的高度。 <br> 类型为number时取值范围是[0, +∞)，string时是[Length](arkui-ts/ts-types.md#length)。 <br>单位：vp<br>默认值：0vp<br>取值为异常值时按照0vp处理。<br>不设置时默认值为0vp。 |

## PathShapeOptions

PathShape的构造函数参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 只读                                             | 可选                                             | 说明                                         |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| commands | string | 否 | 是 | 绘制路径的指令。默认值为空字符串，不设置时不绘制路径。|

## RectShapeOptions

RectShape 的构造函数参数。

继承自[ShapeSize](#shapesize)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 只读                                             | 可选                                             | 说明                                         |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| radius | number &nbsp;\|&nbsp; string &nbsp;\|&nbsp; Array<number &nbsp;\|&nbsp; string> | 否 | 是 | 矩形形状的圆角半径。<br> 类型为number时取值范围是[0, +∞)，string时是[Length](arkui-ts/ts-types.md#length)。<br>单位：vp<br>取值为异常值时按照0vp处理。 |

## RoundRectShapeOptions

RectShape 带有圆角半径的构造函数参数。

继承自[ShapeSize](#shapesize)。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                                               | 只读                                             | 可选                                             | 说明                                         |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| radiusWidth | number &nbsp;\|&nbsp; string | 否 | 是 | 矩形形状圆角半径的宽度。<br> 类型为number时取值范围是[0, +∞)，string时是[Length](arkui-ts/ts-types.md#length)。<br>单位：vp<br>默认值：0vp<br>取值为异常值时按照0vp处理。 |
| radiusHeight | number &nbsp;\|&nbsp; string | 否 | 是 | 矩形形状圆角半径的高度。<br> 类型为number时取值范围是[0, +∞)，string时是[Length](arkui-ts/ts-types.md#length)。<br>单位：vp<br>默认值：0vp<br>取值为异常值时按照0vp处理。 |

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
| width | [Length](arkui-ts/ts-types.md#length) | 是 | 形状的宽度。<br>单位：vp<br>取值为异常值时按照0vp处理。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象，用于链式调用。 |

### height

height(height: Length): T

设置形状的高度。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| height | [Length](arkui-ts/ts-types.md#length) | 是 | 形状的高度。<br>单位：vp<br>取值为异常值时按照0vp处理。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象，用于链式调用。 |

### size

size(size: SizeOptions): T

设置形状的大小，同时设置宽度和高度。

> **说明：**
> - size()等同于同时调用width()和height()设置宽高。
> - 后调用的方法会覆盖先前方法设置的对应属性。例如先调用size({width:100, height:200})再调用width(50)，最终宽度为50，高度保持200。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| size | [SizeOptions](arkui-ts/ts-types.md#sizeoptions) | 是 | 形状的大小。<br>width和height类型为number时取值范围是[0, +∞)，string类型时参考[Length](arkui-ts/ts-types.md#length)。<br>单位：vp<br>取值为异常值时按照0vp处理。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象，用于链式调用。 |

## CommonShapeMethod

提供形状的偏移、填充和位置设置等通用方法的基类。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### offset

offset(offset: Position): T

设置相对于组件布局位置的坐标偏移。

> **说明：**
> - offset()设置相对偏移，position()设置绝对位置，两者定位机制不同。
> - 建议根据场景选择使用其中一种定位方式，避免同时设置导致定位结果难以预测。

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
| T | 返回当前对象，用于链式调用。 |


### fill

fill(color: ResourceColor): T

设置形状的填充颜色。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| color | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | 是 | 形状的填充区域的透明度，黑色表示完全透明，白色表示完全不透明。在maskShape场景下，填充颜色决定了遮罩的透明度效果。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象，用于链式调用。 |


### position

position(position: Position): T

设置形状的绝对位置。与offset（相对偏移）不同，position设置的是绝对坐标；需要精确定位形状时使用position，需要在现有布局位置上微调时使用offset。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型                                               | 必填 | 说明                                         |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| position | [Position](arkui-ts/ts-types.md#position) | 是 | 形状的位置。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前对象，用于链式调用。 |

## 示例

该示例主要演示通过[clipShape](arkui-ts/ts-universal-attributes-sharp-clipping.md#clipshape12)和[maskShape](arkui-ts/ts-universal-attributes-sharp-clipping.md#maskshape12)将图片裁剪和遮罩成不同形状。

```ts
import { CircleShape, EllipseShape, PathShape, RectShape } from '@kit.ArkUI';

@Entry
@Component
struct ShapeExample {
  build() {
    Column({ space: 15 }) {
      Text('CircleShape, position').fontSize(20).width('75%').fontColor('#DCDCDC')
      // $r('app.media.startIcon')需替换为开发者所需的资源文件
      Image($r('app.media.startIcon'))
        .clipShape(new CircleShape({ width: '280px', height: '280px' }).position({ x: '20px', y: '20px' }))
        .width('500px').height('280px')

      Text('EllipseShape, offset').fontSize(20).width('75%').fontColor('#DCDCDC')
      // $r('app.media.startIcon')需替换为开发者所需的资源文件
      Image($r('app.media.startIcon'))
        .clipShape(new EllipseShape({ width: '350px', height: '280px' }).offset({ x: '10px', y: '10px' }))
        .width('500px').height('280px')

      Text('PathShape, fill').fontSize(20).width('75%').fontColor('#DCDCDC')
      // $r('app.media.startIcon')需替换为开发者所需的资源文件
      Image($r('app.media.startIcon'))
        // 使用SVG路径指令绘制三角形作为遮罩形状
        .maskShape(new PathShape().commands('M100 0 L200 240 L0 240 Z').fill(Color.Red))
        .width('500px').height('280px')
    
      Text('RectShape, width, height, fill').fontSize(20).width('75%').fontColor('#DCDCDC')
      // $r('app.media.startIcon')需替换为开发者所需的资源文件
      Image($r('app.media.startIcon'))
        .maskShape(new RectShape().width('350px').height('280px').fill(Color.Red))
        .width('500px').height('280px')
    }
    .width('100%')
    .margin({ top: 15 })
  }
}
```

![shape](figures/shape.png)