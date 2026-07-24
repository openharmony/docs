# 自定义渲染节点 (RenderNode)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sunbees-->
<!--Designer: @sunbees-->
<!--Tester: @khq-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

对于不具备自己的渲染环境的三方框架，尽管已实现前端解析、布局及事件处理等功能，但仍需依赖系统的基础渲染和动画能力。[FrameNode](./arkts-user-defined-arktsNode-frameNode.md)上的通用属性与通用事件对这类框架而言是冗余的，会导致多次不必要的操作，涵盖布局、事件处理等逻辑。

自定义渲染节点 ([RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md))是更加轻量的渲染节点，仅具备与渲染相关的功能。它提供了设置基础渲染属性的能力，以及节点的动态添加、删除和自定义绘制的能力。RenderNode能够为第三方框架提供基础的渲染和动画支持。

## 创建和删除节点

RenderNode提供了节点创建和删除的能力。可以通过RenderNode的构造函数创建自定义的RenderNode节点。通过构造函数创建的节点对应一个实体的节点。同时，可以通过RenderNode中的[dispose](../reference/apis-arkui/js-apis-arkui-renderNode.md#dispose12)接口来实现与实体节点的绑定关系的解除。

## 操作节点树

RenderNode提供了节点的增、删、查、改的能力，能够修改节点的子树结构；可以对所有RenderNode的节点的父子节点做出查询操作，并返回查询结果。

> **说明：**
>
> - RenderNode中获取的子树结构由开发者通过RenderNode的[appendChild](../reference/apis-arkui/js-apis-arkui-renderNode.md#appendchild)接口传入的参数构建。
>
> - RenderNode如果要与系统直接结合显示，需通过FrameNode中获取的RenderNode进行挂载上树。

<!-- @[operation_node_tree](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/ets/pages/OperationNodeTree.ets) --> 

``` TypeScript
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

const TEST_TAG: string = 'RenderNode';
const renderNode = new RenderNode();
renderNode.frame = {
  x: 0,
  y: 0,
  width: 200,
  height: 350
};
renderNode.backgroundColor = 0xfff5f5f5;
for (let i = 0; i < 5; i++) {
  const node = new RenderNode();
  // 设置node节点的Frame大小
  node.frame = {
    x: 10,
    y: 10 + 60 * i,
    width: 50,
    height: 50
  };
  // 设置node节点的背景颜色
  node.backgroundColor = 0xff00bfff;
  // 将新增节点挂载在renderNode上
  renderNode.appendChild(node);
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode?.getRenderNode();
    if (rootRenderNode) {
      rootRenderNode.appendChild(renderNode);
    }
    return this.rootNode;
  }
}

@Entry
@Component
export struct OperationNodeTree {
  private myNodeController: MyNodeController = new MyNodeController();
  @State myLog: string = '';

  build() {
    // ...
      Column() {
        NodeContainer(this.myNodeController)
          .width(200)
          .height(350);
        Text(this.myLog).width(300).height(40).margin({ top: 20, left: 20, bottom: 20 });
        Button('getNextSibling')
          .onClick(() => {
            const child = renderNode.getChild(1);
            if (child === null) {
              hilog.info(DOMAIN, TEST_TAG, ' the child is null');
              this.myLog = 'the child is null';
            } else{
              const nextSibling = child!.getNextSibling()
              if (nextSibling === null) {
                hilog.info(DOMAIN, TEST_TAG, ' the nextSibling is null');
                this.myLog = 'the nextSibling is null';
              } else {
                // 获取子节点的位置信息
                hilog.info(DOMAIN, TEST_TAG, `the position of child is x: ${child.position.x}, y: ${child.position.y}, ` +
                  `the position of nextSibling is x: ${nextSibling.position.x}, y: ${nextSibling.position.y}`);
                this.myLog = `the position of child is x: ${child.position.x}, y: ${child.position.y}, ` +
                  `the position of nextSibling is x: ${nextSibling.position.x}, y: ${nextSibling.position.y}`;
              }
            }
          });
      }.width(300).margin({ left: 20 });

      // ...
  }
}
```
![](figures/operation_node_tree.png)

## 设置和获取渲染相关属性

RenderNode中可以设置渲染相关的属性，包括：[backgroundColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#backgroundcolor)，[clipToFrame](../reference/apis-arkui/js-apis-arkui-renderNode.md#cliptoframe)，[opacity](../reference/apis-arkui/js-apis-arkui-renderNode.md#opacity)，[size](../reference/apis-arkui/js-apis-arkui-renderNode.md#size)，[position](../reference/apis-arkui/js-apis-arkui-renderNode.md#position)，[frame](../reference/apis-arkui/js-apis-arkui-renderNode.md#frame)，[pivot](../reference/apis-arkui/js-apis-arkui-renderNode.md#pivot)，[scale](../reference/apis-arkui/js-apis-arkui-renderNode.md#scale)，[translation](../reference/apis-arkui/js-apis-arkui-renderNode.md#translation)，[rotation](../reference/apis-arkui/js-apis-arkui-renderNode.md#rotation)，[transform](../reference/apis-arkui/js-apis-arkui-renderNode.md#transform)，[shadowColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowcolor)，[shadowOffset](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowoffset)，[shadowAlpha](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowalpha)，[shadowElevation](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowelevation)，[shadowRadius](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowradius)，[borderStyle](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderstyle12)，[borderWidth](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderwidth12)，[borderColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#bordercolor12)，[borderRadius](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderradius12)，[shapeMask](../reference/apis-arkui/js-apis-arkui-renderNode.md#shapemask12)，[shapeClip](../reference/apis-arkui/js-apis-arkui-renderNode.md#shapeclip12)，[markNodeGroup](../reference/apis-arkui/js-apis-arkui-renderNode.md#marknodegroup12)等。具体属性支持范围参考[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md)接口说明。

> **说明：**
> 
> - RenderNode中获取的属性为设置的属性值。
> 
> - 若未传入参数或者传入参数为非法值则查询获得的为默认值。
>
> - 不建议对[BuilderNode](./arkts-user-defined-arktsNode-builderNode.md)中的RenderNode进行修改操作。BuilderNode中具体属性设置是由状态管理实现的，属性更新的时序开发者不可控，BuilderNode和FrameNode中同时设置RenderNode属性可能会导致RenderNode属性设置与预期不相符。

<!-- @[rendering_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/ets/pages/RenderingProperties.ets) -->

``` TypeScript
import { RenderNode, FrameNode, NodeController, ShapeMask, ShapeClip } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

const TEST_TAG: string = 'RenderNode';
const mask = new ShapeMask();
mask.setRectShape({
  left: 0,
  right: 150,
  top: 0,
  bottom: 150
});
mask.fillColor = 0X55FF0000;
mask.strokeColor = 0XFFFF0000;
mask.strokeWidth = 24;

const clip = new ShapeClip();
clip.setCommandPath({ commands: 'M100 0 L0 100 L50 200 L150 200 L200 100 Z' });

const renderNode = new RenderNode();
renderNode.backgroundColor = 0xff519db4;
renderNode.size = { width: 100, height: 100 };

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
export struct RenderingProperties {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    // ...
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Column() {
        NodeContainer(this.myNodeController).height(260);
      };

      Flex() {
        // 设置RenderNode的位置
        Button('position')
          .width(300)
          .onClick(() => {
            renderNode.position = { x: 10, y: 10 };
            hilog.info(DOMAIN, TEST_TAG, ' position:' + JSON.stringify(renderNode.position));
          });
        Column().width(20);
        // 设置RenderNode的轴心
        Button('pivot')
          .width(300)
          .onClick(() => {
            renderNode.pivot = { x: 0.5, y: 0.6 };
            hilog.info(DOMAIN, TEST_TAG, ' pivot:' + JSON.stringify(renderNode.pivot));
          });
      }

      Flex() {
        // 修改RenderNode的缩放比例
        Button('scale')
          .width(300)
          .onClick(() => {
            renderNode.scale = { x: 0.5, y: 1 };
            hilog.info(DOMAIN, TEST_TAG, ' scale:' + JSON.stringify(renderNode.scale));
          });
        Column().width(20);
        // 设置RenderNode的平移量
        Button('translation')
          .width(300)
          .onClick(() => {
            renderNode.translation = { x: 100, y: 0 };
            hilog.info(DOMAIN, TEST_TAG, ' translation:' + JSON.stringify(renderNode.translation));
          });
      }

      Flex() {
        // 设置RenderNode的旋转角度
        Button('rotation')
          .width(300)
          .onClick(() => {
            renderNode.rotation = { x: 45, y: 0, z: 0 };
            hilog.info(DOMAIN, TEST_TAG, ' rotation:' + JSON.stringify(renderNode.rotation));
          });
        Column().width(20);
        // 设置RenderNode的变换矩阵
        Button('transform')
          .width(300)
          .onClick(() => {
            renderNode.transform = [
              1, 0, 0, 0,
              0, 2, 0, 0,
              0, 0, 1, 0,
              0, 0, 0, 1
            ];
            hilog.info(DOMAIN, TEST_TAG, ' transform:' + JSON.stringify(renderNode.transform));
          });
      }

      Flex() {
        // 设置RenderNode的阴影属性
        Button('shadow')
          .width(300)
          .onClick(() => {
            renderNode.shadowElevation = 10; // 设置阴影的光照高度
            renderNode.shadowColor = 0xff2787d9;
            renderNode.shadowOffset = { x: 10, y: 10 };
            renderNode.shadowAlpha = 0.1;
            hilog.info(DOMAIN, TEST_TAG, ' shadowElevation:' + JSON.stringify(renderNode.shadowElevation));
            hilog.info(DOMAIN, TEST_TAG, ' shadowColor:' + JSON.stringify(renderNode.shadowColor));
            hilog.info(DOMAIN, TEST_TAG, ' shadowOffset:' + JSON.stringify(renderNode.shadowOffset));
            hilog.info(DOMAIN, TEST_TAG, ' shadowAlpha:' + JSON.stringify(renderNode.shadowAlpha));
          });
        Column().width(20);
        // 设置RenderNode的阴影模糊半径
        Button('shadowRadius')
          .width(300)
          .onClick(() => {
            renderNode.shadowOffset = { x: 10, y: 10 };
            renderNode.shadowAlpha = 0.7;
            renderNode.shadowRadius = 30;
            hilog.info(DOMAIN, TEST_TAG, ' shadowOffset:' + JSON.stringify(renderNode.shadowOffset));
            hilog.info(DOMAIN, TEST_TAG, ' shadowAlpha:' + JSON.stringify(renderNode.shadowAlpha));
            hilog.info(DOMAIN, TEST_TAG, ' shadowRadius:' + JSON.stringify(renderNode.shadowRadius));
          });
      }

      Flex() {
        // 设置RenderNode的边框样式
        Button('border')
          .width(300)
          .onClick(() => {
            renderNode.borderWidth = {
              left: 8,
              top: 8,
              right: 8,
              bottom: 8
            };
            renderNode.borderStyle = {
              left: BorderStyle.Solid,
              top: BorderStyle.Dotted,
              right: BorderStyle.Dashed,
              bottom: BorderStyle.Solid
            }
            renderNode.borderColor = {
              left: 0xffd5d5d5,
              top: 0xffd5d5d5,
              right: 0xffd5d5d5,
              bottom: 0xffd5d5d5
            };
            renderNode.borderRadius = {
              topLeft: 32,
              topRight: 32,
              bottomLeft: 32,
              bottomRight: 32
            };
            hilog.info(DOMAIN, TEST_TAG, ' borderWidth:' + JSON.stringify(renderNode.borderWidth));
            hilog.info(DOMAIN, TEST_TAG, ' borderStyle:' + JSON.stringify(renderNode.borderStyle));
            hilog.info(DOMAIN, TEST_TAG, ' borderColor:' + JSON.stringify(renderNode.borderColor));
            hilog.info(DOMAIN, TEST_TAG, ' borderRadius:' + JSON.stringify(renderNode.borderRadius));
          })
        Column().width(20);
        // 设置RenderNode的遮罩
        Button('shapeMask')
          .width(300)
          .onClick(() => {
            renderNode.shapeMask = mask;
            hilog.info(DOMAIN, TEST_TAG, ' shapeMask:' + JSON.stringify(renderNode.shapeMask));
          });
      }

        // 设置RenderNode的剪裁形状
        Button('shapeClip')
          .width(300)
          .onClick(() => {
            renderNode.shapeClip = clip;
            hilog.info(DOMAIN, TEST_TAG, ' shapeClip:' + JSON.stringify(renderNode.shapeClip));
          });
      }
      .padding({
        left: 35,
        right: 35,
        top: 35,
        bottom: 35
      })
      .width('100%')
      .height('100%');

      // ...
  }
}
```
![](figures/rendering_properties.gif)

## 自定义绘制

通过重写RenderNode中的[draw](../reference/apis-arkui/js-apis-arkui-renderNode.md#draw)方法，可以自定义RenderNode的绘制内容，通过[invalidate](../reference/apis-arkui/js-apis-arkui-renderNode.md#invalidate)接口可以主动触发节点的重新绘制。

> **说明：**
> 
> - 同时同步触发多个invalidate仅会触发一次重新绘制。
> 
> - 自定义绘制有两种绘制方式：通过ArkTS接口进行调用和通过Node-API进行调用。

**ArkTS接口调用示例：**

<!-- @[custom_draw](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/ets/pages/CustomDraw.ets) -->

``` TypeScript
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

class MyRenderNode extends RenderNode {
  public width: number = 200;

  draw(context: DrawContext) {
    // 获取canvas对象
    const canvas = context.canvas;
    // 创建笔刷
    const brush = new drawing.Brush();
    // 设置笔刷颜色
    brush.setColor({
      alpha: 255,
      red: 81,
      green: 157,
      blue: 180
    });
    canvas.attachBrush(brush);
    // 绘制矩形
    canvas.drawRect({
      left: 0,
      right: this.width,
      top: 0,
      bottom: 200
    });
    canvas.detachBrush();
    hilog.info(DOMAIN, 'testTag', `RenderNode draw width = ${this.width}`);
  }
}

const renderNode = new MyRenderNode();
renderNode.frame = {
  x: 0,
  y: 0,
  width: 300,
  height: 300
};
renderNode.backgroundColor = 0xffd5d5d5;
renderNode.opacity = 0.5;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode?.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.frame = {
        x: 0,
        y: 0,
        width: 500,
        height: 500
      };
      rootRenderNode.appendChild(renderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
export struct CustomDraw {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    // ...
      Column() {
        NodeContainer(this.myNodeController)
          .width('100%').height(320);
        Button('Invalidate')
          .onClick(() => {
            // 同步调用多次，仅触发一次重绘，draw回调中的日志仅打印一次
            renderNode.width += 10;
            renderNode.invalidate();
            renderNode.invalidate();
          }).margin({left: -80});
      };

      // ...
  }
}
```
![](figures/custom_draw.gif)

## 调整自定义绘制Canvas的变换矩阵

从API version 12开始，通过重写RenderNode中的[draw](../reference/apis-arkui/js-apis-arkui-renderNode.md#draw)方法，可以自定义RenderNode的绘制内容。

通过[concatMatrix](../../application-dev/reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-Canvas.md#concatmatrix12)可以调整自定义绘制Canvas的变换矩阵。

> **说明：**
> 
> - [getTotalMatrix](../../application-dev/reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-Canvas.md#gettotalmatrix12)获取的是用来记录绘制指令的临时canvas的变换矩阵。
> 
> - 如果开发者希望对画布进行预期的变换，应使用[concatMatrix](../../application-dev/reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-Canvas.md#concatmatrix12)而不是[setMatrix](../../application-dev/reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-Canvas.md#setmatrix12)，因为setMatrix会覆盖原本真实canvas上存在的变换矩阵。

**ArkTS接口调用示例：**

<!-- @[custom_draw_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/ets/pages/CustomDrawCanvas.ets) -->

``` TypeScript
import { NodeController, UIContext, RenderNode, DrawContext, FrameNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

function drawImage(canvas: DrawingCanvas) {
  let matrix = new drawing.Matrix();
  matrix.setTranslation(100, 100);
  canvas.concatMatrix(matrix);
  const pen = new drawing.Pen();
  pen.setStrokeWidth(5);
  pen.setColor({
    alpha: 255,
    red: 0,
    green: 74,
    blue: 175
  });
  canvas.attachPen(pen);
  const brush = new drawing.Brush();
  brush.setColor({
    alpha: 255,
    red: 0,
    green: 74,
    blue: 175
  });
  canvas.attachBrush(brush);
  canvas.drawRect({
    left: 10,
    top: 10,
    right: 110,
    bottom: 60
  });
  canvas.detachPen();
}

function drawImage1(canvas: DrawingCanvas) {
  let matrix = new drawing.Matrix();
  matrix.setTranslation(100, 100);
  // 1. getTotalMatrix获取的是用来记录绘制指令的临时canvas的变换矩阵
  // 2. 如果开发者希望这个画布进行一个预期的变换，应该使用concatMatrix而不是setMatrix，因为setMatrix会覆盖原本真实canvas上存在的变换矩阵
  canvas.getTotalMatrix();
  canvas.setMatrix(matrix);
  const pen = new drawing.Pen();
  pen.setStrokeWidth(5);
  pen.setColor({
    alpha: 255,
    red: 0,
    green: 74,
    blue: 175
  });
  canvas.attachPen(pen);
  const brush = new drawing.Brush();
  brush.setColor({
    alpha: 255,
    red: 0,
    green: 74,
    blue: 175
  });
  canvas.attachBrush(brush);
  canvas.drawRect({
    left: 10,
    top: 10,
    right: 110,
    bottom: 60
  });
  canvas.detachPen();
}

class MyRenderNode extends RenderNode {
  draw(context: DrawContext): void {
    drawImage(context.canvas);
  }
}

class MyRenderNode1 extends RenderNode {
  draw(context: DrawContext): void {
    drawImage1(context.canvas);
  }
}

class MyNodeController extends NodeController {
  makeNode(uiContext: UIContext): FrameNode | null {
    const rootNode: FrameNode = new FrameNode(uiContext);
    rootNode.commonAttribute.width(300).height(300);
    const theRenderNode: MyRenderNode = new MyRenderNode();
    theRenderNode.frame = {
      x: 10,
      y: 100,
      width: 100,
      height: 50
    };
    theRenderNode.backgroundColor = 0xFF2787D9;
    rootNode.getRenderNode()?.appendChild(theRenderNode);
    return rootNode;
  }
}

class MyNodeController1 extends NodeController {
  makeNode(uiContext: UIContext): FrameNode | null {
    const rootNode: FrameNode = new FrameNode(uiContext);
    rootNode.commonAttribute.width(300).height(300);
    const theRenderNode: MyRenderNode1 = new MyRenderNode1();
    theRenderNode.frame = {
      x: 10,
      y: 100,
      width: 100,
      height: 50
    };
    theRenderNode.backgroundColor = 0xFF2787D9;
    rootNode.getRenderNode()?.appendChild(theRenderNode);
    return rootNode;
  }
}

@Entry
@Component
export struct CustomDrawCanvas {
  myNodeController: MyNodeController = new MyNodeController();
  myNodeController1: MyNodeController1 = new MyNodeController1();

  build() {
    // ...
      Row() {
        Column() {
          NodeContainer(this.myNodeController)
        }
        .height('100%')
        .width('45%');

        Column() {
          NodeContainer(this.myNodeController1)
        }
        .height('100%')
        .width('45%');
      };

      // ...
  }
}
```

![RenderNode-canvas](./figures/renderNode-canvas.png)

**Node-API调用示例：**

C++侧可通过Node-API来获取[Canvas](../reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md)，并进行后续的自定义绘制操作。

<!-- @[native_bridge](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/cpp/NativeBridge.cpp) -->

``` C++
// native_bridge.cpp
#include "napi/native_api.h"
#include <native_drawing/drawing_canvas.h>
#include <native_drawing/drawing_color.h>
#include <native_drawing/drawing_path.h>
#include <native_drawing/drawing_pen.h>

namespace {
    const int32_t ARG_NUM0 = 0;
    const int32_t ARG_NUM1 = 1;
    const int32_t ARG_NUM2 = 2;
    const int32_t ARG_NUM3 = 3;
    const int32_t ARG_NUM4 = 4;
}

static napi_value OnDraw(napi_env env, napi_callback_info info)
{
    size_t argc = ARG_NUM4;
    napi_value args[ARG_NUM4] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int32_t id;
    napi_get_value_int32(env, args[ARG_NUM0], &id);

    // 获取 Canvas 指针
    void *temp = nullptr;
    napi_unwrap(env, args[ARG_NUM1], &temp);
    OH_Drawing_Canvas *canvas = reinterpret_cast<OH_Drawing_Canvas *>(temp);

    // 获取 Canvas 宽度
    int32_t width;
    napi_get_value_int32(env, args[ARG_NUM2], &width);

    // 获取 Canvas 高度
    int32_t height;
    napi_get_value_int32(env, args[ARG_NUM3], &height);

    const float kQuarter = 0.25f;
    const float kThreeQuarters  = 0.75f;
    // 传入canvas、height、width等信息至绘制函数中进行自定义绘制
    auto path = OH_Drawing_PathCreate();
    OH_Drawing_PathMoveTo(path, width * kQuarter, height * kQuarter);
    OH_Drawing_PathLineTo(path, width * kThreeQuarters, height * kQuarter);
    OH_Drawing_PathLineTo(path, width * kThreeQuarters, height * kThreeQuarters);
    OH_Drawing_PathLineTo(path, width * kQuarter, height * kThreeQuarters);
    OH_Drawing_PathLineTo(path, width * kQuarter, height * kQuarter);
    OH_Drawing_PathClose(path);

    auto pen = OH_Drawing_PenCreate();
    const int lineWidth = 10;
    OH_Drawing_PenSetWidth(pen, lineWidth);
    OH_Drawing_PenSetColor(pen, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
    OH_Drawing_CanvasAttachPen(canvas, pen);

    OH_Drawing_CanvasDrawPath(canvas, path);
    OH_Drawing_CanvasDetachPen(canvas);
    OH_Drawing_PenDestroy(pen);
    OH_Drawing_PathDestroy(path);

    return nullptr;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"nativeOnDraw", nullptr, OnDraw, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
```

修改工程中的`src/main/cpp/CMakeLists.txt`文件，添加如下内容：
```cmake
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)
project(NapiTest)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED NativeBridge.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so)
target_link_libraries(entry PUBLIC libace_ndk.z.so)
target_link_libraries(entry PUBLIC libnative_drawing.so)
```

同时在工程中的`src/main/cpp/types/libentry/index.d.ts`文件中，添加自定义绘制函数在ArkTS侧的定义，如：
<!-- @[index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
import { DrawContext } from '@kit.ArkUI'

export const nativeOnDraw: (id: number, context: DrawContext, width: number, height: number) => number;
```

ArkTS侧代码：

<!-- @[custom_draw_canvas_native](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/ets/pages/CustomDrawCanvasNative.ets) --> 

``` TypeScript
import bridge from 'libentry.so'; // 该 so 由 Node-API 编写并生成
import { DrawContext, FrameNode, NodeController, RenderNode } from '@kit.ArkUI';

class MyRenderNode extends RenderNode {
  private uiContext: UIContext;

  constructor(uiContext: UIContext) {
    super();
    this.uiContext = uiContext;
  }

  draw(context: DrawContext) {
    // 需要将 context 中的宽度和高度从vp转换为px
    bridge.nativeOnDraw(0, context, this.uiContext.vp2px(context.size.width),
      this.uiContext.vp2px(context.size.height));
  }
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      const renderNode = new MyRenderNode(uiContext);
      renderNode.size = { width: 100, height: 100 };
      rootRenderNode.appendChild(renderNode);
    }
    return this.rootNode;
  }
}

@Entry
@Component
export struct CustomDrawCanvasNative {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    // ...
      Row() {
        NodeContainer(this.myNodeController);
      };

      // ...
  }
}
```

![RenderNode-NodeAPI](./figures/renderNode-NodeAPI.png)

## 设置标签

开发者可利用[label](../reference/apis-arkui/js-apis-arkui-renderNode.md#label12)接口向RenderNode设置标签信息，有助于在使用inspector[检查页面布局](./arkts-inspector-overview.md)时更清晰区分各节点。

<!-- @[set_label](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/ets/pages/SetLabel.ets) -->

``` TypeScript
import { RenderNode, FrameNode, NodeController, UIContext } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    const renderNode: RenderNode | null = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      const renderChildNode: RenderNode = new RenderNode();
      renderChildNode.frame = {
        x: 0,
        y: 0,
        width: 100,
        height: 100
      };
      renderChildNode.backgroundColor = 0xff519db4;
      renderChildNode.label = 'customRenderChildNode';
      hilog.info(DOMAIN, 'label:', renderChildNode.label);
      renderNode.appendChild(renderChildNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
export struct SetLabel {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    // ...
      Column() {
        NodeContainer(this.myNodeController)
          .width(300)
          .height(700)
          .backgroundColor(0xffd5d5d5);
      };

      // ...
  }
}
```
![](figures/set_label.png)

## 查询当前RenderNode是否解除引用

前端节点均绑定有相应的后端实体节点，当节点调用dispose接口解除绑定后，再次调用接口可能会出现crash、返回默认值的情况。在ArkUI框架中，前端节点是在ArkTS代码层面创建的节点，负责与开发者交互；后端节点是在ArkUI框架底层维护的实体节点，负责具体逻辑的处理。

从API version 20开始，使用[isDisposed](../reference/apis-arkui/js-apis-arkui-renderNode.md#isdisposed20)接口查询当前RenderNode对象是否已解除与后端实体节点的引用关系，从而可以在操作节点前检查其有效性，避免潜在风险。

<!-- @[check_render_node_disposed](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/CustomRenderNode/entry/src/main/ets/pages/CheckRenderNodeDisposed.ets) -->

``` TypeScript
import { NodeController, FrameNode, RenderNode } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private renderNode: RenderNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.renderNode = new RenderNode();
    this.renderNode.size = { width: 300, height: 300 };
    this.renderNode.backgroundColor = 0xffd5d5d5;

    // 挂载RenderNode
    this.rootNode.getRenderNode()?.appendChild(this.renderNode);
    return this.rootNode;
  }

  disposeRenderNode() {
    // 解除RenderNode与后端实体节点的引用关系
    this.renderNode?.dispose();
  }

  isDisposed(): string {
    if (this.renderNode !== null) {
      // 查询RenderNode是否解除引用
      if (this.renderNode.isDisposed()) {
        return 'renderNode isDisposed is true';
      } else {
        return 'renderNode isDisposed is false';
      }
    }
    return 'renderNode is null';
  }
}

@Entry
@Component
export struct CheckRenderNodeDisposed {
  @State text: string = '';
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    // ...
      Column({ space: 4 }) {
        NodeContainer(this.myNodeController);
        Button('RenderNode dispose')
          .onClick(() => {
            this.myNodeController.disposeRenderNode();
            this.text = '';
          })
          .width(200)
          .height(50);
        Button('RenderNode isDisposed')
          .onClick(() => {
            this.text = this.myNodeController.isDisposed();
          })
          .width(200)
          .height(50);
        Text(this.text)
          .fontSize(25);
      }
      .width('100%')
      .height('100%');

      // ...
  }
}
```

![](figures/check_render_node_disposed.gif)
