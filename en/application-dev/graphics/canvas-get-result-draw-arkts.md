# Obtaining a Canvas and Displaying Drawing Results (ArkTS)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=379459ed39b4b4ff1b499df9523039b8689cb0ba translatedAt=2026-08-15T01:50:29.985Z pushedAt=2026-08-15T08:19:41.828Z -->

## Overview

Canvas provides the capability of drawing and processing basic graphics on the screen. You can use Canvas to implement custom drawing effects to enhance user experience.

Canvas is the core of graphics drawing. All drawing operations mentioned in this topic (including drawing basic graphics, text, and images, and performing graphic transformation) are based on Canvas.

In ArkTS, you can obtain a canvas in either of the following ways: [obtaining a canvas that can be directly displayed](#obtaining-a-canvas-that-can-be-directly-displayed) and [obtaining an off-screen canvas](#obtaining-and-displaying-an-offscreen-canvas). The former does not require additional operations after the drawing API is called, and the latter requires existing display approaches to display the drawing result.

## Obtaining a Canvas That Can Be Directly Displayed

Obtain the canvas that can be directly displayed through [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md).

1. Import the required files.

   <!-- @[arkts_graphics_draw_import_ui](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   import { UIContext, NodeController, FrameNode, RenderNode, DrawContext} from '@kit.ArkUI';
   ```

   <!-- @[arkts_graphics_draw_import_graphics2d](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   import { drawing } from '@kit.ArkGraphics2D';
   ```

2. Add a custom **RenderNode**.

   <!-- @[arkts_graphics_draw_direct_canvas_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   // Customize a RenderNode.
   class MyRenderNodeDirectDisplay extends RenderNode {
     async draw(context: DrawContext) {
       const canvas = context.canvas;
       if (canvas === null) {
         console.error('Canvas is null.');
         return;
       }
       // Customize drawing operations.
       const brush = new drawing.Brush();
       if (brush === null) {
         console.error('Brush is null.');
         return;
       } else {
         brush.setColor({red: 255, blue: 0, green: 0, alpha: 255});
         canvas.attachBrush(brush);
         canvas.drawRect({left: 0, right: 300, top: 0, bottom: 300});
       }
     }
   }
   ```

3. Add a custom [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md).

   <!-- @[arkts_graphics_draw_direct_canvas_api_node_control](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   // Customize a NodeController.
   class MyNodeControllerDirectDisplay extends NodeController {
     private rootNode: FrameNode | null = null;
     private myRenderNode = new MyRenderNodeDirectDisplay();
   
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
   ```

4. Override the [draw()](../reference//apis-arkui/js-apis-arkui-renderNode.md#draw) function of the custom **RenderNode** to obtain the canvas for custom drawing operations.

   <!-- @[arkts_graphics_draw_direct_canvas_api_rewrite](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   async draw(context: DrawContext) {
     const canvas = context.canvas;
     if (canvas === null) {
       console.error('Canvas is null.');
       return;
     }
     // Customize drawing operations.
     const brush = new drawing.Brush();
     if (brush === null) {
       console.error('Brush is null.');
       return;
     } else {
       brush.setColor({red: 255, blue: 0, green: 0, alpha: 255});
       canvas.attachBrush(brush);
       canvas.drawRect({left: 0, right: 300, top: 0, bottom: 300});
     }
   }
   ```

5. Display the custom **NodeController**.

   <!-- @[arkts_graphics_draw_direct_and_indirect_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   @Entry
   @Component
   struct RenderTest {
     @State message: string = 'hello';
     myNodeController_1 = new MyNodeControllerDirectDisplay();
     myNodeController_2 = new MyNodeControllerIndirectDisplay();
   
     build() {
       Row() {
         Column() {
           Column(){
             Text($r('app.string.DirectCanvas'))
             // Display the canvas on the screen.
             NodeContainer(this.myNodeController_1)
               .width('100%')
               .height('40%')
           }
           Column(){
             Text($r('app.string.OffScreenCanvas'))
             // Offscreen canvas.
             NodeContainer(this.myNodeController_2)
               .width('100%')
               .height('40%')
               .margin({ top: 20 })
           }
         }
       }
     }
   }
   ```

## Obtaining and Displaying an Offscreen Canvas

1. Import the required files.

   <!-- @[arkts_graphics_draw_import_ui_and_graphics2d](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   import { UIContext, NodeController, FrameNode, RenderNode, DrawContext} from '@kit.ArkUI';
   import { image } from '@kit.ImageKit';
   import { taskpool } from '@kit.ArkTS';
   import { drawing } from '@kit.ArkGraphics2D';
   ```

2. Add a custom **RenderNode**.

3. Add a custom [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md).

4. Create a **PixelMap** in the **aboutToAppear()** function of **MyNodeController**.

5. Override the [draw()](../reference//apis-arkui/js-apis-arkui-renderNode.md#draw) function of the custom **RenderNode** to obtain the offscreen canvas for drawing.

   1. Use the **PixelMap** created in Step 4 to construct the offscreen canvas.

   2. Perform custom drawing operations on the offscreen canvas.

   3. Pass the drawing result of the offscreen canvas to the **RenderNode**.

   <!-- @[arkts_graphics_draw_indirect_canvas_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   // Customize a RenderNode.
   export class MyRenderNodeIndirectDisplay extends RenderNode {
     private pixelMap: image.PixelMap | null = null;
     setPixelMap(pixelMap: image.PixelMap) {
       this.pixelMap = pixelMap;
     }
   
     async draw(context: DrawContext) {
       const canvas = context.canvas;
       if (this.pixelMap != null) {
         // Use the PixelMap created in Step 4 to construct the offscreen canvas.
         const canvas_ = new drawing.Canvas(this.pixelMap);
   
         // Perform offscreen drawing.
         const brush = new drawing.Brush();
         brush.setColor({ alpha: 255, red: 0, green: 0, blue: 255 });
         canvas_.attachBrush(brush);
         canvas_.drawRect({ left: 150, right: 575, top: 0, bottom: 600 });
   
         // Pass the drawing result of the offscreen canvas to the RenderNode.
         canvas.drawImage(this.pixelMap, 0, 0);
       }
     }
   }
   
   @Concurrent
   async function createPixelMapAsync() {
     // 4000000 indicates the size of the pixel buffer to be created. The value is height x width x 4.
     const color : ArrayBuffer = new ArrayBuffer(4000000);
     let opts : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 1000, width: 1000 } };
     const pixel = await image.createPixelMap(color, opts);
     return pixel;
   }
   
   // Customize a NodeController.
   export class MyNodeControllerIndirectDisplay extends NodeController {
     private rootNode: FrameNode | null = null;
     private myRenderNode = new MyRenderNodeIndirectDisplay();
   
     // 4. Create a PixelMap in the aboutToAppear of MyNodeController.
     aboutToAppear(): void {
       let task = new taskpool.Task(createPixelMapAsync);
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
   ```

6. Display the custom **NodeController**.

   <!-- @[arkts_graphics_draw_direct_and_indirect_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw/entry/src/main/ets/drawing/pages/CanvasGetResult.ets) -->

   ``` TypeScript
   @Entry
   @Component
   struct RenderTest {
     @State message: string = 'hello';
     myNodeController_1 = new MyNodeControllerDirectDisplay();
     myNodeController_2 = new MyNodeControllerIndirectDisplay();
   
     build() {
       Row() {
         Column() {
           Column(){
             Text($r('app.string.DirectCanvas'))
             // Display the canvas on the screen.
             NodeContainer(this.myNodeController_1)
               .width('100%')
               .height('40%')
           }
           Column(){
             Text($r('app.string.OffScreenCanvas'))
             // Offscreen canvas.
             NodeContainer(this.myNodeController_2)
               .width('100%')
               .height('40%')
               .margin({ top: 20 })
           }
         }
       }
     }
   }
   ```

<!--RP1-->

## Samples

The following samples are provided to help you better understand how to use the **Drawing** APIs (ArkTS) for development:

- [ArkTSGraphicsDraw (API20)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/Drawing/ArkTSGraphicsDraw)

<!--RP1End-->