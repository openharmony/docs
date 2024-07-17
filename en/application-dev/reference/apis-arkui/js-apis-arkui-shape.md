# @ohos.arkui.shape (Shape)

The corresponding shape can be transferred in the clipShape and maskShape interfaces.


> **NOTE**
>
>  The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Import modules.

```ts
import { CircleShape, EllipseShape, PathShape, RectShape } from "@ohos.arkui.shape";
```

## CircleShape

Circle shape for the clipShape and maskShape interfaces.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: ShapeSize)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Note:                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [ShapeSize](#shapesize) | No | Size of a shape. |

This parameter is inherited from [BaseShape](#baseshape).

## EllipseShape

Oval shape for clipShape and maskShape interfaces.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: ShapeSize)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [ShapeSize](#shapesize) | No | Size of a shape. |

This parameter is inherited from [BaseShape](#baseshape).

## PathShape

Path for the clipShape and maskShape interfaces.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: PathShapeOptions)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

| Name        | Type                                              | Mandatory/Optional | Note:                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [PathShapeOptions](#pathshapeoptions) | No | Path parameters. |

This parameter is inherited from [CommonShapeMethod](#commonshapemethod).

### commands

commands(commands: string): PathShape

Sets the drawing command of the path.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| commands | string | M | Draws a path. |

## RectShape

Rectangle shape used for the clipShape and maskShape interfaces.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: RectShapeOptions | RoundRectShapeOptions)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Note:                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [RectShapeOptions](#rectshapeoptions) &nbsp;\|&nbsp; [RoundRectShapeOptions](#roundrectshapeoptions) | No | Rectangle shape parameter. |

This parameter is inherited from [BaseShape](#baseshape).

### radiusWidth

radiusWidth(rWidth: number | string): RectShape

Width of the rounded radius of a rectangle.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Description.                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| rWidth | number &nbsp;\|&nbsp; string | M | Width of the rounded radius of a rectangle. |

### radiusHeight

radiusHeight(rHeight: number | string): RectShape

Height of the rounded radius of a rectangle.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Note:                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| rHeight | number &nbsp;\|&nbsp; string | M | Height of the rounded radius of a rectangle. |

### radius

radius(radius: number | string | Array<number &nbsp;\|&nbsp; string>): RectShape

Sets the radius of rounded corners of a rectangle.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| radius | number &nbsp;\|&nbsp; string &nbsp;\|&nbsp; Array<number &nbsp;\|&nbsp; string> | M | Radius of the rounded corner of a rectangle. |


## ShapeSize

Size parameter of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Note:                                        |
| ----------- | -------------------------------------------------- | -------------------------------------------- |
| width | number &nbsp;\|&nbsp; string | Width of a shape. |
| height | number &nbsp;\|&nbsp; string | Height of a shape. |

## PathShapeOptions

Constructor parameter of PathShape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Description                                        |
| ----------- | -------------------------------------------------- | -------------------------------------------- |
| commands | string | Command for drawing a path. |

## RectShapeOptions

Constructor parameter of RectShape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

This parameter is inherited from [ShapeSize](#shapesize).

| Name        | Type                                              | Description                                        |
| ----------- | -------------------------------------------------- | -------------------------------------------- |
| radius | number &nbsp;\|&nbsp; string &nbsp;\|&nbsp; Array<number &nbsp;\|&nbsp; string> | Radius of the rounded corner of a rectangle. |

## RoundRectShapeOptions

RectShape construction function parameter with radius.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

This parameter is inherited from [ShapeSize](#shapesize).

| Name        | Type                                              | Description                                        |
| ----------- | -------------------------------------------------- | -------------------------------------------- |
| radiusWidth | number &nbsp;\|&nbsp; string | Width of the rounded radius of a rectangle. |
| radiusHeight | number &nbsp;\|&nbsp; string | Height of the rounded radius of a rectangle. |

## BaseShape

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

This parameter is inherited from [CommonShapeMethod](#commonshapemethod).

### width

width(width: Length): T

Sets the width of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| width | [Length](arkui-ts/ts-types.md#length) | M | Width of a shape. |

### height

height(height: Length): T

Sets the height of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| height | [Length](arkui-ts/ts-types.md#length) | Supported | Height of a shape. |

### size

size(size: SizeOptions): T

Sets the size of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Note:                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| size | [SizeOptions](arkui-ts/ts-types.md#sizeoptions) | M | Size of a shape. |

## CommonShapeMethod

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### offset

offset(offset: Position): T

Sets the coordinate offset relative to the widget layout position.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Note:                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| offset | [Position](arkui-ts/ts-types.md#position) | Supported | Coordinate offset relative to the widget layout position. |

### fill

fill(color: ResourceColor): T

Sets the fill color of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Note:                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| color | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | M | Fill color of a shape. |

### position

position(position: Position): T

Sets the position of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory/Optional | Note:                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| position | [Position](arkui-ts/ts-types.md#position) | M | Sets the position of a shape. |

## **Example**

```ts
import { CircleShape, EllipseShape, PathShape, RectShape } from "@ohos.arkui.shape"

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
