# Graphics

The **Graphics** module provides APIs for defining attributes of a custom node.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { DrawContext, Size, Offset, Position, Pivot, Scale, Translation, Matrix4, Rotation, Frame } from "@ohos.arkui.node";
```

## Size

Returns the width and height of the component, in vp.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type  | Readable| Writable| Description                  |
| ------ | ------ | ---- | ---- | ---------------------- |
| width  | number | Yes  | Yes  | Width of the component, in vp.|
| height | number | Yes  | Yes  | Height of the component, in vp.|

## Position

Sets or returns the position of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Readable| Writable| Description                    |
| ---- | ------ | ---- | ---- | ------------------------ |
| x    | number | Yes  | Yes  | Horizontal position, in vp.|
| y    | number | Yes  | Yes  | Vertical position, in vp.|

## Frame

Sets or returns the size and position of the component, in vp.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type  | Readable| Writable| Description                    |
| ------ | ------ | ---- | ---- | ------------------------ |
| x      | number | Yes  | Yes  | Horizontal position, in vp.|
| y      | number | Yes  | Yes  | Vertical position, in vp.|
| width  | number | Yes  | Yes  | Width of the component, in vp.  |
| height | number | Yes  | Yes  | Height of the component, in vp.  |

## Pivot

Sets the pivot of the component. As the rotation or scaling center of the component, the pivot affects the rotation and scaling effects.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Readable| Writable| Description                                                        |
| ---- | ------ | ---- | ---- | ------------------------------------------------------------ |
| x    | number | Yes  | Yes  | X coordinate of the pivot. The value is a floating point number in the range [0.0, 1.0], and the default value is **0.5**.|
| y    | number | Yes  | Yes  | Y coordinate of the pivot. The value is a floating point number in the range [0.0, 1.0], and the default value is **0.5**.|

## Scale

Sets the scale factor of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Readable| Writable| Description                                        |
| ---- | ------ | ---- | ---- | -------------------------------------------- |
| x    | number | Yes  | Yes  | Scale factor along the x-axis. The value is a floating point number, and the default value is **1.0**.|
| y    | number | Yes  | Yes  | Scale factor along the y-axis. The value is a floating point number, and the default value is **1.0**.|

## Translation

Sets the translation amount of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Readable| Writable| Description                        |
| ---- | ------ | ---- | ---- | ---------------------------- |
| x    | number | Yes  | Yes  | Horizontal translation amount, in vp.|
| y    | number | Yes  | Yes  | Vertical translation amount, in vp.|

## Rotation

Sets the rotation angle of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Readable| Writable| Description                          |
| ---- | ------ | ---- | ---- | ------------------------------ |
| x    | number | Yes  | Yes  | Rotation angle along the x-axis, in vp.|
| y    | number | Yes  | Yes  | Rotation angle along the y-axis, in vp.|
| z    | number | Yes  | Yes  | Rotation angle along the z-axis, in vp.|

## Offset

Sets the offset of the component or effect.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Readable| Writable| Description                        |
| ---- | ------ | ---- | ---- | ---------------------------- |
| x    | number | Yes  | Yes  | Offset along the y-axis, in vp.|
| y    | number | Yes  | Yes  | Offset along the y-axis, in vp.|

## Matrix4

Sets the transformation information of the component, which is a 4 x 4 matrix represented by a 16-bit number[]. For example:
```ts
const transform: Matrix4 = [
  1, 0, 45, 0,
  0, 1,  0, 0,
  0, 0,  1, 0,
  0, 0,  0, 1
]
```

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## DrawContext

Graphics drawing context, which provides the canvas width and height required for drawing.

### size

get size(): Size

Obtains the width and height of the canvas.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type         | Description            |
| ------------- | ---------------- |
| [Size](#size) | Width and height of the canvas.|

### canvas

get canvas(): Canvas

Obtains the canvas used for drawing.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type         | Description            |
| ------------- | ---------------- |
| [Canvas](../apis-arkgraphics2d/js-apis-graphics-drawing.md#canvas) | Canvas for drawing.|

**Example**

```ts
import { RenderNode, FrameNode, NodeController, DrawContext } from "@ohos.arkui.node";

class MyRenderNode extends RenderNode {
  flag: boolean = false;

  draw(context: DrawContext) {
    const size = context.size;
    const canvas = context.canvas;
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
