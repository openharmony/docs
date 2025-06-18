# Obtaining a Canvas and Displaying Drawing Results (ArkTS)


## When to Use

Canvas provides the capability of drawing basic graphics on the screen. You can use Canvas to customize drawing effects to enhance user experience.


Canvas is the core of graphics drawing. All drawing operations (including basic graphics drawing, text drawing, image drawing, and image transformation) mentioned in this chapter are based on Canvas.


Currently, ArkTS can obtain the canvas in either of the following ways: [Obtaining the Canvas That Can Be Directly Displayed](#obtaining-the-canvas-that-can-be-directly-displayed) and [Obtaining and Displaying the Off-Screen Canvas](#obtaining-and-displaying-the-off-screen-canvas). The former can display the drawing result on the screen without additional operations after the drawing API is called, while the latter can display the drawing result using existing display methods.


## Obtaining the Canvas That Can Be Directly Displayed

Use [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md) to obtain the canvas that can be directly displayed on the screen.

1. Add a customized RenderNode.

2. Add a customized [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md).

3. Rewrite the [draw()](../reference//apis-arkui/js-apis-arkui-renderNode.md#draw) function of the customized RenderNode to obtain the Canvas for customized drawing.

4. Display the customized NodeController.

```ts
import { UIContext, NodeController, FrameNode, RenderNode, DrawContext } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

// 1. Customize a RenderNode.
export class MyRenderNode extends RenderNode {
  async draw(context: DrawContext) {
    const canvas = context.canvas
    // 3. Custom drawing operations
    const brush = new drawing.Brush()
    brush.setColor({red: 255, blue: 0, green: 0, alpha: 255})
    canvas.attachBrush(brush)
    canvas.drawRect({left: 0, right: 300, top: 0, bottom: 300})
  }
}

// 2. Customize a NodeController.
export class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  myRenderNode = new MyRenderNode();

  makeNode(uiContext: UIContext): FrameNode {
    this.rootNode = new FrameNode(uiContext);
    if (this.rootNode === null) {
      return this.rootNode
    }

    const renderNode = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      this.myRenderNode.backgroundColor = 0xffffffff;
      this.myRenderNode.frame = { x: 0, y: 0, width: 4800, height: 4800 };
      this.myRenderNode.pivot = { x: 0.2, y: 0.8 }
      this.myRenderNode.scale = { x: 1, y: 1 }
      renderNode.appendChild(this.myRenderNode);
      renderNode.clipToFrame = true
    }
    return this.rootNode;
  }
}

@Entry
@Component
struct RenderTest {
  @State message: string = 'hello'
  build() {
    Row() {
      Column() {
        // 4. Display the custom NodeController.
        NodeContainer(new MyNodeController())
          .width('100%')
      }
      .width('100%')
      .height('80%')
    }
    .height('100%')
  }
}
```


## Obtaining and Displaying the Off-Screen Canvas

1. Add a customized RenderNode.

2. Add a customized [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md).

3. Create a PixeMap in the aboutToAppear() function of MyNodeController.

4. Rewrite the [draw()](../reference//apis-arkui/js-apis-arkui-renderNode.md#draw) function of the custom RenderNode to obtain the off-screen Canvas for drawing.

   1. Use the pixel map created in step 3 to construct an off-screen canvas.
   2. Perform customized drawing operations on the off-screen Canvas.
   3. Send the drawing result of the off-screen Canvas to the RenderNode.

5. Display the customized NodeController.

```ts
import { UIContext, NodeController, FrameNode, RenderNode, DrawContext } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';
import { taskpool } from '@kit.ArkTS';
import { drawing } from '@kit.ArkGraphics2D';

// 1. Customize a RenderNode.
export class MyRenderNode extends RenderNode {
  pixelMap: image.PixelMap | null = null;
  setPixelMap(pixelMap: image.PixelMap) {
    this.pixelMap = pixelMap
  }

  async draw(context: DrawContext) {
    const canvas = context.canvas
    if (this.pixelMap != null) {
      // 4.1 Use the pixel map created in step 3 to construct an off-screen canvas.
      const canvas_ = new drawing.Canvas(this.pixelMap);

      // 4.2 Off-screen drawing
      const brush = new drawing.Brush();
      brush.setColor({ alpha: 255, red: 255, green: 0, blue: 0 });
      canvas_.attachBrush(brush);
      canvas_.drawRect({left:0,right:100,top:0,bottom:100});

      // 4.3 Send the drawing result of the off-screen Canvas to RenderNode.
      canvas.drawImage(this.pixelMap, 0, 0);
    }
  }
}

@Concurrent
async function CreatePixelMapAsync() {
  const color : ArrayBuffer = new ArrayBuffer(40000);  // 40000 is the size of the pixel buffer to create. The value is calculated as follows: height * width *4.
  let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 100, width: 100 } }
  const pixel = await image.createPixelMap(color, opts);
  return pixel;
}

// 2. Customize a NodeController.
export class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  myRenderNode = new MyRenderNode();

  // 3. Create a PixeMap in aboutToAppear of MyNodeController.
  aboutToAppear(): void {
    let task = new taskpool.Task(CreatePixelMapAsync);
    taskpool.execute(task).then((pixel:Object)=>{
      this.myRenderNode.setPixelMap(pixel as image.PixelMap)
      this.myRenderNode.invalidate()
    })
  }

  makeNode(uiContext: UIContext): FrameNode {
    this.rootNode = new FrameNode(uiContext);
    if (this.rootNode === null) {
      return this.rootNode
    }

    const renderNode = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      this.myRenderNode.backgroundColor = 0xffffffff;
      this.myRenderNode.frame = { x: 0, y: 0, width: 4800, height: 4800 };
      this.myRenderNode.pivot = { x: 0.2, y: 0.8 }
      this.myRenderNode.scale = { x: 1, y: 1 }
      renderNode.appendChild(this.myRenderNode);
      renderNode.clipToFrame = true
    }
    return this.rootNode;
  }
}


@Entry
@Component
struct RenderTest {
  @State message: string = 'hello'
  nodeController = new MyNodeController()

  build() {
    Row() {
      Column() {
        // 5. Display the custom NodeController.
        NodeContainer(this.nodeController)
          .width('100%')
      }
      .width('100%')
      .height('80%')
    }
    .height('100%')
  }
}
```
