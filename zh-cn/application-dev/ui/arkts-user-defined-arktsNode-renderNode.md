# 自定义渲染节点 (RenderNode)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

## 概述

对于不具备自己的渲染环境的三方框架，尽管已实现前端解析、布局及事件处理等功能，但仍需依赖系统的基础渲染和动画能力。[FrameNode](./arkts-user-defined-arktsNode-frameNode.md)上的通用属性与通用事件对这类框架而言是冗余的，会导致多次不必要的操作，涵盖布局、事件处理等逻辑。

自定义渲染节点 ([RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md))是更加轻量的渲染节点，仅具备与渲染相关的功能。它提供了设置基础渲染属性的能力，以及节点的动态添加、删除和自定义绘制的能力。RenderNode能够为第三方框架提供基础的渲染和动画支持。

## 创建和删除节点

RenderNode提供了节点创建和删除的能力。可以通过RenderNode的构造函数创建自定义的RenderNode节点。通过构造函数创建的节点对应一个实体的节点。同时，可以通过RenderNode中的[dispose](../reference/apis-arkui/js-apis-arkui-renderNode.md#dispose12)接口来实现与实体节点的绑定关系的解除。

## 操作节点树

RenderNode提供了节点的增、删、查、改的能力，能够修改节点的子树结构；可以对所有RenderNode的节点的父子节点做出查询操作，并返回查询结果。

> **说明：**
>
> - RenderNode中查询获取得到的子树结构按照开发通过RenderNode的接口传递的参数构建。
>
> - RenderNode如果要与系统直接结合显示，使用需要依赖FrameNode中获取的RenderNode进行挂载上树。

```ts
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';

const TEST_TAG: string = "RenderNode";
const renderNode = new RenderNode();
renderNode.frame = {
  x: 0,
  y: 0,
  width: 200,
  height: 350
};
renderNode.backgroundColor = 0xffff0000;
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
  node.backgroundColor = 0xff00ff00;
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
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
        .width(200)
        .height(350)
      Button('getNextSibling')
        .onClick(() => {
          const child = renderNode.getChild(1);
          const nextSibling = child!.getNextSibling()
          if (child === null || nextSibling === null) {
            console.info(TEST_TAG + ' the child or nextChild is null');
          } else {
            // 获取子节点的位置信息
            console.info(`${TEST_TAG} the position of child is x: ${child.position.x}, y: ${child.position.y}, ` +
            `the position of nextSibling is x: ${nextSibling.position.x}, y: ${nextSibling.position.y}`);
          }
        })
    }
  }
}
```

## 设置和获取渲染相关属性

RenderNode中可以设置渲染相关的属性，包括：[backgroundColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#backgroundcolor)，[clipToFrame](../reference/apis-arkui/js-apis-arkui-renderNode.md#cliptoframe)，[opacity](../reference/apis-arkui/js-apis-arkui-renderNode.md#opacity)，[size](../reference/apis-arkui/js-apis-arkui-renderNode.md#size)，[position](../reference/apis-arkui/js-apis-arkui-renderNode.md#position)，[frame](../reference/apis-arkui/js-apis-arkui-renderNode.md#frame)，[pivot](../reference/apis-arkui/js-apis-arkui-renderNode.md#pivot)，[scale](../reference/apis-arkui/js-apis-arkui-renderNode.md#scale)，[translation](../reference/apis-arkui/js-apis-arkui-renderNode.md#translation)，[rotation](../reference/apis-arkui/js-apis-arkui-renderNode.md#rotation)，[transform](../reference/apis-arkui/js-apis-arkui-renderNode.md#transform)，[shadowColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowcolor)，[shadowOffset](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowoffset)，[shadowAlpha](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowalpha)，[shadowElevation](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowelevation)，[shadowRadius](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowradius)，[borderStyle](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderstyle12)，[borderWidth](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderwidth12)，[borderColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#bordercolor12)，[borderRadius](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderradius12)，[shapeMask](../reference/apis-arkui/js-apis-arkui-renderNode.md#shapemask12)，[shapeClip](../reference/apis-arkui/js-apis-arkui-renderNode.md#shapeclip12)，[markNodeGroup](../reference/apis-arkui/js-apis-arkui-renderNode.md#marknodegroup12)等。具体属性支持范围参考[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md)接口说明。

> **说明：**
> 
> - RenderNode中查询获取得到的属性为设置的属性值。
> 
> - 若未传入参数或者传入参数为非法值则查询获得的为默认值。
>
> - 不建议对BuilderNode中的RenderNode进行修改操作。BuilderNode中具体属性设置是由状态管理实现的，属性更新的时序开发者不可控，BuilderNode和FrameNode中同时设置RenderNode属性可能会导致RenderNode属性设置与预期不相符。

```ts
import { RenderNode, FrameNode, NodeController, ShapeMask, ShapeClip } from '@kit.ArkUI';

const TEST_TAG: string = "RenderNode";
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
clip.setCommandPath({ commands: "M100 0 L0 100 L50 200 L150 200 L200 100 Z" });

const renderNode = new RenderNode();
renderNode.backgroundColor = 0xffff0000;
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
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Column() {
        NodeContainer(this.myNodeController)
      }

      Button("position")
        .width(300)
        .onClick(() => {
          renderNode.position = { x: 10, y: 10 };
          console.info(TEST_TAG + " position:" + JSON.stringify(renderNode.position));
        })
      Button("pivot")
        .width(300)
        .onClick(() => {
          renderNode.pivot = { x: 0.5, y: 0.6 };
          console.info(TEST_TAG + " pivot:" + JSON.stringify(renderNode.pivot));
        })
      Button("scale")
        .width(300)
        .onClick(() => {
          renderNode.scale = { x: 0.5, y: 1 };
          console.info(TEST_TAG + " scale:" + JSON.stringify(renderNode.scale));
        })
      Button("translation")
        .width(300)
        .onClick(() => {
          renderNode.translation = { x: 100, y: 0 };
          console.info(TEST_TAG + " translation:" + JSON.stringify(renderNode.translation));
        })
      Button("rotation")
        .width(300)
        .onClick(() => {
          renderNode.rotation = { x: 45, y: 0, z: 0 };
          console.info(TEST_TAG + " rotation:" + JSON.stringify(renderNode.rotation));
        })
      Button("transform")
        .width(300)
        .onClick(() => {
          renderNode.transform = [
            1, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
          ];
          console.info(TEST_TAG + " transform:" + JSON.stringify(renderNode.transform));
        })
      Button("shadow")
        .width(300)
        .onClick(() => {
          renderNode.shadowElevation = 10;
          renderNode.shadowColor = 0XFF00FF00;
          renderNode.shadowOffset = { x: 10, y: 10 };
          renderNode.shadowAlpha = 0.1;
          console.info(TEST_TAG + " shadowElevation:" + JSON.stringify(renderNode.shadowElevation));
          console.info(TEST_TAG + " shadowColor:" + JSON.stringify(renderNode.shadowColor));
          console.info(TEST_TAG + " shadowOffset:" + JSON.stringify(renderNode.shadowOffset));
          console.info(TEST_TAG + " shadowAlpha:" + JSON.stringify(renderNode.shadowAlpha));
        })
      Button("shadowRadius")
        .width(300)
        .onClick(() => {
          renderNode.shadowOffset = { x: 10, y: 10 };
          renderNode.shadowAlpha = 0.7
          renderNode.shadowRadius = 30;
          console.info(TEST_TAG + " shadowOffset:" + JSON.stringify(renderNode.shadowOffset));
          console.info(TEST_TAG + " shadowAlpha:" + JSON.stringify(renderNode.shadowAlpha));
          console.info(TEST_TAG + " shadowRadius:" + JSON.stringify(renderNode.shadowRadius));
        })
      Button("border")
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
            left: 0xFF0000FF,
            top: 0xFF0000FF,
            right: 0xFF0000FF,
            bottom: 0xFF0000FF
          };
          renderNode.borderRadius = {
            topLeft: 32,
            topRight: 32,
            bottomLeft: 32,
            bottomRight: 32
          };
          console.info(TEST_TAG + " borderWidth:" + JSON.stringify(renderNode.borderWidth));
          console.info(TEST_TAG + " borderStyle:" + JSON.stringify(renderNode.borderStyle));
          console.info(TEST_TAG + " borderColor:" + JSON.stringify(renderNode.borderColor));
          console.info(TEST_TAG + " borderRadius:" + JSON.stringify(renderNode.borderRadius));
        })
      Button("shapeMask")
        .width(300)
        .onClick(() => {
          renderNode.shapeMask = mask;
          console.info(TEST_TAG + " shapeMask:" + JSON.stringify(renderNode.shapeMask));
        })
      Button("shapeClip")
        .width(300)
        .onClick(() => {
          renderNode.shapeClip = clip;
          console.info(TEST_TAG + " shapeClip:" + JSON.stringify(renderNode.shapeClip));
        })
    }
    .padding({
      left: 35,
      right: 35,
      top: 35,
      bottom: 35
    })
    .width("100%")
    .height("100%")
  }
}
```

## 自定义绘制

通过重写RenderNode中的[draw](../reference/apis-arkui/js-apis-arkui-renderNode.md#draw)方法，可以自定义RenderNode的绘制内容，通过[invalidate](../reference/apis-arkui/js-apis-arkui-renderNode.md#invalidate)接口可以主动触发节点的重新绘制。

> **说明：**
> 
> - 同时同步触发多个invalidate仅会触发一次重新绘制。
> 
> - 自定义绘制有两种绘制方式：通过ArkTS接口进行调用和通过Node-API进行调用。

**ArkTS接口调用示例：**

```ts
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class MyRenderNode extends RenderNode {
  width: number = 200;

  draw(context: DrawContext) {
    // 获取canvas对象
    const canvas = context.canvas;
    // 创建笔刷
    const brush = new drawing.Brush();
    // 设置笔刷颜色
    brush.setColor({
      alpha: 255,
      red: 255,
      green: 0,
      blue: 0
    });
    canvas.attachBrush(brush);
    // 绘制矩阵
    canvas.drawRect({
      left: 0,
      right: this.width,
      top: 0,
      bottom: 200
    });
    canvas.detachBrush();
    console.info(`RenderNode draw width = ${this.width}`);
  }
}

const renderNode = new MyRenderNode();
renderNode.frame = {
  x: 0,
  y: 0,
  width: 300,
  height: 300
};
renderNode.backgroundColor = 0xff0000ff;
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
      }
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
        .width('100%')
      Button('Invalidate')
        .onClick(() => {
          // 同步调用多次，仅触发一次重绘，draw回调中的日志仅打印一次
          renderNode.width += 10;
          renderNode.invalidate();
          renderNode.invalidate();
        })
    }
  }
}
```

**Node-API调用示例：**

C++侧可通过Node-API来获取Canvas，并进行后续的自定义绘制操作。

```c++
// native_bridge.cpp
#include "napi/native_api.h"
#include <native_drawing/drawing_canvas.h>
#include <native_drawing/drawing_color.h>
#include <native_drawing/drawing_path.h>
#include <native_drawing/drawing_pen.h>

static napi_value OnDraw(napi_env env, napi_callback_info info)
{
    size_t argc = 4;
    napi_value args[4] = { nullptr };
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int32_t id;
    napi_get_value_int32(env, args[0], &id);
    
    // 获取 Canvas 指针
    void* temp = nullptr;
    napi_unwrap(env, args[1], &temp);
    OH_Drawing_Canvas *canvas = reinterpret_cast<OH_Drawing_Canvas*>(temp);
    
    // 获取 Canvas 宽度
    int32_t width;
    napi_get_value_int32(env, args[2], &width);
    
    // 获取 Canvas 高度
    int32_t height;
    napi_get_value_int32(env, args[3], &height);
    
    // 传入canvas、height、width等信息至绘制函数中进行自定义绘制
    auto path = OH_Drawing_PathCreate();
    OH_Drawing_PathMoveTo(path, width / 4, height / 4);
    OH_Drawing_PathLineTo(path, width * 3 / 4, height / 4);
    OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
    OH_Drawing_PathLineTo(path, width / 4, height * 3 / 4);
    OH_Drawing_PathLineTo(path, width / 4, height / 4);
    OH_Drawing_PathClose(path);
    
    auto pen = OH_Drawing_PenCreate();
    OH_Drawing_PenSetWidth(pen, 10);
    OH_Drawing_PenSetColor(pen, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
    OH_Drawing_CanvasAttachPen(canvas, pen);
    
    OH_Drawing_CanvasDrawPath(canvas, path);

    return nullptr;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "nativeOnDraw", nullptr, OnDraw, nullptr, nullptr, nullptr, napi_default, nullptr }
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version =1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
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

add_library(entry SHARED native_bridge.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so)
target_link_libraries(entry PUBLIC libace_ndk.z.so)
target_link_libraries(entry PUBLIC libnative_drawing.so)
```

同时在工程中的`src/main/cpp/types/libentry/index.d.ts`文件中，添加自定义绘制函数在ArkTS侧的定义，如：
```ts
import { DrawContext } from '@kit.ArkUI'

export const nativeOnDraw: (id: number, context: DrawContext, width: number, height: number) => number;
```

ArkTS侧代码：

```ts
// Index.ets
import bridge from "libentry.so" // 该 so 由 Node-API 编写并生成
import { DrawContext, FrameNode, NodeController, RenderNode } from '@kit.ArkUI'

class MyRenderNode extends RenderNode {
  uiContext: UIContext;

  constructor(uiContext: UIContext) {
    super();
    this.uiContext = uiContext;
  }

  draw(context: DrawContext) {
    // 需要将 context 中的宽度和高度从vp转换为px
    bridge.nativeOnDraw(0, context, this.uiContext.vp2px(context.size.height), this.uiContext.vp2px(context.size.width));
  }
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      const renderNode = new MyRenderNode(uiContext);
      renderNode.size = { width: 100, height: 100 }
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

## 设置标签

开发者可利用[label](../reference/apis-arkui/js-apis-arkui-renderNode.md#label12)接口向RenderNode设置标签信息，这有助于在节点Inspector中更清晰地区分各节点。

```ts
import {  RenderNode, FrameNode, NodeController, UIContext } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    const renderNode: RenderNode | null = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      const renderChildNode: RenderNode = new RenderNode();
      renderChildNode.frame = { x: 0, y: 0, width: 100, height: 100 };
      renderChildNode.backgroundColor = 0xffff0000;
      renderChildNode.label = 'customRenderChildNode';
      console.info('label:', renderChildNode.label);
      renderNode.appendChild(renderChildNode);
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
        .width(300)
        .height(700)
        .backgroundColor(Color.Gray)
    }
  }
}
```

## 查询当前RenderNode是否解除引用

前端节点均绑定有相应的后端实体节点，当节点调用dispose接口解除绑定后，再次调用接口可能会出现crash、返回默认值的情况。

从API version 20开始，使用[isDisposed](../reference/apis-arkui/js-apis-arkui-renderNode.md#isdisposed20)接口查询当前RenderNode对象是否已解除与后端实体节点的引用关系，从而可以在操作节点前检查其有效性，避免潜在风险。

```ts
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

  isDisposed() : string {
    if (this.renderNode !== null) {
      // 查询RenderNode是否解除引用
      if (this.renderNode.isDisposed()) {
        return 'renderNode isDisposed is true';
      }
      else {
        return 'renderNode isDisposed is false';
      }
    }
    return 'renderNode is null';
  }
}

@Entry
@Component
struct Index {
  @State text: string = ''
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column({ space: 4 }) {
      NodeContainer(this.myNodeController)
      Button('RenderNode dispose')
        .onClick(() => {
          this.myNodeController.disposeRenderNode();
          this.text = '';
        })
        .width(200)
        .height(50)
      Button('RenderNode isDisposed')
        .onClick(() => {
          this.text = this.myNodeController.isDisposed();
        })
        .width(200)
        .height(50)
      Text(this.text)
        .fontSize(25)
    }
    .width('100%')
    .height('100%')
  }
}
```