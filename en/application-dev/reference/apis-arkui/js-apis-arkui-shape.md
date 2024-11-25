# @ohos.arkui.shape (Shape)

The **shape** module provides **clipShape** and **maskShape** APIs to allow you to pass in various shapes.


> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Modules to Import

```ts
import { CircleShape, EllipseShape, PathShape, RectShape } from "@kit.ArkUI";
```

## CircleShape

Represents a circle shape used in the **clipShape** and **maskShape** APIs.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: ShapeSize)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [ShapeSize](#shapesize) | No| Size of the shape.|

This API inherits from [BaseShape](#baseshape).

## EllipseShape

Represents an ellipse shape used in the **clipShape** and **maskShape** APIs.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: ShapeSize)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [ShapeSize](#shapesize) | No| Size of the shape.|

This API inherits from [BaseShape](#baseshape).

## PathShape

Represents a path used in the **clipShape** and **maskShape** APIs.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: PathShapeOptions)

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 12.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [PathShapeOptions](#pathshapeoptions) | No| Path parameters.|

This API inherits from [CommonShapeMethod](#commonshapemethod).

### commands

commands(commands: string): PathShape

Sets the path drawing commands.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| commands | string | Yes| Path drawing commands.|

## RectShape

Represents a rectangle shape used in the **clipShape** and **maskShape** APIs.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(options?: RectShapeOptions | RoundRectShapeOptions)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| options | [RectShapeOptions](#rectshapeoptions)  \|  [RoundRectShapeOptions](#roundrectshapeoptions) | No| Rectangle parameters.|

This API inherits from [BaseShape](#baseshape).

### radiusWidth

radiusWidth(rWidth: number | string): RectShape

Sets the radius width of the rectangle border corners.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| rWidth | number  \|  string | Yes| Radius width of the rectangle border corners.|

### radiusHeight

radiusHeight(rHeight: number | string): RectShape

Sets the radius height of the rectangle border corners.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| rHeight | number  \|  string | Yes| Radius height of the rectangle border corners.|

### radius

radius(radius: number | string | Array<number  \|  string>): RectShape

Sets the radius of the rectangle border corners.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| radius | number  \|  string  \|  Array<number  \|  string> | Yes| Radius of the rectangle border corners. When an array is provided, it should contain exactly four elements, corresponding to the radius of the upper left, upper right, lower left, and lower right corners of the rectangle, respectively. If more than four elements are contained, only the first four are accepted.|


## ShapeSize

Describes the size of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory                                            | Description                                        |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| width | number  \|  string | No| Width of the shape.|
| height | number  \|  string | No| Height of the shape.|

## PathShapeOptions

Represents the parameter of the constructor used to create a **PathShape** object.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory                                            | Description                                        |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| commands | string | No| Path drawing commands. For details, see [commands](./arkui-ts/ts-drawing-components-path.md#commands-1).|

## RectShapeOptions

Represents the parameter of the constructor used to create a **RectShape** object.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

This API inherits from [ShapeSize](#shapesize).

| Name        | Type                                              | Mandatory                                            | Description                                        |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| radius | number  \|  string  \|  Array<number  \|  string> | No| Radius of the rectangle border corners.|

## RoundRectShapeOptions

Represents the parameter of the constructor used to create a **RectShape** object with rounded corners.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

This API inherits from [ShapeSize](#shapesize).

| Name        | Type                                              | Mandatory                                            | Description                                        |
| ----------- | -------------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
| radiusWidth | number  \|  string | No| Radius width of the rectangle border corners.|
| radiusHeight | number  \|  string | No| Radius height of the rectangle border corners.|

## BaseShape

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

This API inherits from [CommonShapeMethod](#commonshapemethod).

### width

width(width: Length): T

Sets the width of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| width | [Length](arkui-ts/ts-types.md#length) | Yes| Width of the shape.|

### height

height(height: Length): T

Sets the height of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| height | [Length](arkui-ts/ts-types.md#length) | Yes| Height of the shape.|

### size

size(size: SizeOptions): T

Sets the size of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| size | [SizeOptions](arkui-ts/ts-types.md#sizeoptions) | Yes| Size of the shape.|

## CommonShapeMethod

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### offset

offset(offset: Position): T

Sets the coordinate offset relative to the component's layout position.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| offset | [Position](arkui-ts/ts-types.md#position) | Yes| Coordinate offset relative to the component's layout position.|

### fill

fill(color: ResourceColor): T

Sets the fill color of this shape, which determines its opacity, with black representing full transparency and white representing full opacity.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| color | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | Yes| Fill color of the shape, which represents the opacity of the fill area. The black color indicates full transparency, while white indicates full opacity.|

### position

position(position: Position): T

Sets the position of a shape.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                              | Mandatory| Description                                        |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| position | [Position](arkui-ts/ts-types.md#position) | Yes| Position of the shape.|

## **Example**

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
