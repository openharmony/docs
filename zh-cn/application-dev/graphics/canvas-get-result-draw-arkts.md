# 画布的获取与绘制结果的显示（ArkTS）


## 场景介绍

Canvas即画布，提供绘制基本图形的能力，用于在屏幕上绘制图形和处理图形。开发者可以通过Canvas实现自定义的绘图效果，增强应用的用户体验。


Canvas是图形绘制的核心，本章中提到的所有绘制操作（包括基本图形的绘制、文字的绘制、图片的绘制、图形变换等）都是基于Canvas的。


目前ArkTS有两种获取Canvas的方式：[获取可直接显示的Canvas画布](#获取可直接显示的canvas画布)、[获取离屏的Canvas](#离屏canvas画布的获取与显示)，前者在调用绘制接口之后无需进行额外的操作即可完成绘制结果的上屏显示，而后者需要依靠已有的显示手段来显示绘制结果。


## 获取可直接显示的Canvas画布

通过[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md)获取可直接上屏显示的Canvas画布。

1. 添加自定义RenderNode。

2. 添加自定义[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)。

3. 重写自定义RenderNode的[draw()](../reference//apis-arkui/js-apis-arkui-renderNode.md#draw)函数，获取Canvas进行自定义的绘制操作，即本章下文中的内容。

4. 将自定义NodeController进行显示。

```ts
import { UIContext, NodeController, FrameNode, RenderNode, DrawContext } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

// 1. 自定义RenderNode
export class MyRenderNode extends RenderNode {
  async draw(context: DrawContext) {
    const canvas = context.canvas;
    // 3. 自定义的绘制相关操作
    const brush = new drawing.Brush();
    brush.setColor({red: 255, blue: 0, green: 0, alpha: 255});
    canvas.attachBrush(brush);
    canvas.drawRect({left: 0, right: 300, top: 0, bottom: 300});
  }
}

// 2. 自定义NodeController
export class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  myRenderNode = new MyRenderNode();

  makeNode(uiContext: UIContext): FrameNode {
    this.rootNode = new FrameNode(uiContext);
    if (this.rootNode === null) {
      return this.rootNode;
    }

    const renderNode = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      this.myRenderNode.backgroundColor = 0xffffffff;
      this.myRenderNode.frame = { x: 0, y: 0, width: 4800, height: 4800 };
      this.myRenderNode.pivot = { x: 0.2, y: 0.8 };
      this.myRenderNode.scale = { x: 1, y: 1 };
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
        // 4. 将自定义NodeController进行显示
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


## 离屏Canvas画布的获取与显示

1. 添加自定义RenderNode。

2. 添加自定义[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)。

3. 在MyNodeController的aboutToAppear()函数中创建PixeMap。

4. 重写自定义RenderNode的[draw()](../reference//apis-arkui/js-apis-arkui-renderNode.md#draw)函数，在其中获取离屏Canvas进行绘制：

   1. 利用3中创建的PixelMap构造离屏Canvas。
   2. 对离屏Canvas进行自定义的绘制操作。
   3. 将离屏Canvas的绘制结果交给RenderNode。

5. 将自定义NodeController进行显示。

```ts
import { UIContext, NodeController, FrameNode, RenderNode, DrawContext } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';
import { taskpool } from '@kit.ArkTS';
import { drawing } from '@kit.ArkGraphics2D';

// 1. 自定义RenderNode
export class MyRenderNode extends RenderNode {
  pixelMap: image.PixelMap | null = null;
  setPixelMap(pixelMap: image.PixelMap) {
    this.pixelMap = pixelMap;
  }

  async draw(context: DrawContext) {
    const canvas = context.canvas
    if (this.pixelMap != null) {
      // 4.1 利用3中创建的PixelMap构造离屏Canvas
      const canvas_ = new drawing.Canvas(this.pixelMap);

      // 4.2 离屏绘制
      const brush = new drawing.Brush();
      brush.setColor({ alpha: 255, red: 255, green: 0, blue: 0 });
      canvas_.attachBrush(brush);
      canvas_.drawRect({left:0,right:100,top:0,bottom:100});

      // 4.3 将离屏Canvas的绘制结果交给RenderNode
      canvas.drawImage(this.pixelMap, 0, 0);
    }
  }
}

@Concurrent
async function CreatePixelMapAsync() {
  const color : ArrayBuffer = new ArrayBuffer(40000);  // 40000为需要创建的像素buffer大小，取值为：height * width *4
  let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 100, width: 100 } };
  const pixel = await image.createPixelMap(color, opts);
  return pixel;
}

// 2. 自定义NodeController
export class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  myRenderNode = new MyRenderNode();

  // 3. 在MyNodeController的aboutToAppear中创建PixeMap
  aboutToAppear(): void {
    let task = new taskpool.Task(CreatePixelMapAsync);
    taskpool.execute(task).then((pixel:Object)=>{
      this.myRenderNode.setPixelMap(pixel as image.PixelMap);
      this.myRenderNode.invalidate();
    })
  }

  makeNode(uiContext: UIContext): FrameNode {
    this.rootNode = new FrameNode(uiContext);
    if (this.rootNode === null) {
      return this.rootNode;
    }

    const renderNode = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      this.myRenderNode.backgroundColor = 0xffffffff;
      this.myRenderNode.frame = { x: 0, y: 0, width: 4800, height: 4800 };
      this.myRenderNode.pivot = { x: 0.2, y: 0.8 };
      this.myRenderNode.scale = { x: 1, y: 1 };
      renderNode.appendChild(this.myRenderNode);
      renderNode.clipToFrame = true;
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
        // 5. 将自定义NodeController进行显示
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

<!--RP1-->
## 相关实例

针对Drawing(ArkTS)的开发，有以下相关实例可供参考：

- [ArkTSGraphicsDraw (API14)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/ArkTSGraphicsDraw)
<!--RP1End-->