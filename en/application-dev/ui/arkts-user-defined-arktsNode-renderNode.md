# Custom Render Node (RenderNode)

## Overview

For third-party frameworks that lack an inherent rendering environment, leveraging the system's basic rendering and animation capabilities is crucial. Such frameworks often have their own mechanisms for front-end parsing, layout management, and event handling. As a result, the universal attributes and events associated with [FrameNode](./arkts-user-defined-arktsNode-frameNode.md) may be redundant for these frameworks, potentially causing duplicate work in managing layout and event logic.

This is where [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md) becomes beneficial. **RenderNode** is a streamlined render node designed to offer rendering-specific features. It allows for setting of basic rendering properties and provides the capability to dynamically add and remove nodes and to implement custom drawing. These can be used to provide third-party frameworks with essential rendering and animation capabilities.

## Creating and Removing Nodes

You can create and remove nodes with **RenderNode**. You can create a custom instance of **RenderNode** using its constructor, and the instance thereby created corresponds to an entity node. You can use the [dispose](../reference/apis-arkui/js-apis-arkui-renderNode.md#dispose12) API in **RenderNode** to break the binding with the entity node.

## Operating the Node Tree

With **RenderNode**, you can add, delete, query, and modify nodes, thereby changing the subtree structure of nodes; you can also query the parent-child relationships to obtain the results.

> **NOTE**
>
> - The subtree structure obtained through queries in **RenderNode** is constructed based on the parameters passed through the APIs of **RenderNode**.
>
> - To display a RenderNode in conjunction with built-in components, you need to mount the RenderNode obtained from a FrameNode onto the component tree.

```ts
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 200, height: 350 };
renderNode.backgroundColor = 0xffff0000;
for (let i = 0; i < 5; i++) {
  const node = new RenderNode();
  // Set the frame size of the node.
  node.frame = { x: 10, y: 10 + 60 * i, width: 50, height: 50 };
  // Set the background color of the node.
  node.backgroundColor = 0xff00ff00;
  // Mount the new node to the RenderNode.
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
            console.log('the child or nextChild is null');
          } else {
            // Obtain the position of the child node.
            console.log(`the position of child is x: ${child.position.x}, y: ${child.position.y}, ` +
            `the position of nextSibling is x: ${nextSibling.position.x}, y: ${nextSibling.position.y}`);
          }
        })
    }
  }
}
```

## Setting and Obtaining Rendering-related Properties

In **RenderNode**, you can set rendering-related properties, including the following: [backgroundColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#backgroundcolor), [clipToFrame](../reference/apis-arkui/js-apis-arkui-renderNode.md#cliptoframe), [opacity](../reference/apis-arkui/js-apis-arkui-renderNode.md#opacity), [size](../reference/apis-arkui/js-apis-arkui-renderNode.md#size), [position](../reference/apis-arkui/js-apis-arkui-renderNode.md#position), [frame](../reference/apis-arkui/js-apis-arkui-renderNode.md#frame), [pivot](../reference/apis-arkui/js-apis-arkui-renderNode.md#pivot), [scale](../reference/apis-arkui/js-apis-arkui-renderNode.md#scale), [translation](../reference/apis-arkui/js-apis-arkui-renderNode.md#translation), [rotation](../reference/apis-arkui/js-apis-arkui-renderNode.md#rotation), [transform](../reference/apis-arkui/js-apis-arkui-renderNode.md#transform), [shadowColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowcolor), [shadowOffset](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowoffset), [shadowAlpha](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowalpha), [shadowElevation](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowelevation), [shadowRadius](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowradius), [borderStyle](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderstyle12), [borderWidth](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderwidth12), [borderColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#bordercolor12), [borderRadius](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderradius12), [shapeMask](../reference/apis-arkui/js-apis-arkui-renderNode.md#shapemask12), [shapeClip](../reference/apis-arkui/js-apis-arkui-renderNode.md#shapeclip12), [markNodeGroup](../reference/apis-arkui/js-apis-arkui-renderNode.md#marknodegroup12). For details about the supported attributes, see [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md#rendernode).

> **NOTE**
> 
> - The properties obtained from a query in **RenderNode** are the values that have been explicitly set.
> 
> - If no parameters are provided or if the provided parameters are invalid, the query will return the default values.
>
> - Avoid modifying RenderNodes in a BuilderNode. In **BuilderNode**, how properties are applied and updated is governed by the state management system, independently of manual intervention. Be aware that setting the same **RenderNode** property in both BuilderNode and FrameNode could lead to unexpected behavior.

```ts
import {  RenderNode, FrameNode, NodeController, ShapeMask, ShapeClip } from '@kit.ArkUI';

const mask = new ShapeMask();
mask.setRectShape({ left: 0, right: 150, top: 0, bottom: 150 });
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
          console.log("renderNode position:" + JSON.stringify(renderNode.position));
        })
      Button("pivot")
        .width(300)
        .onClick(() => {
          renderNode.pivot = { x: 0.5, y: 0.6 };
          console.log("renderNode pivot:" + JSON.stringify(renderNode.pivot));
        })
      Button("scale")
        .width(300)
        .onClick(() => {
          renderNode.scale = { x: 0.5, y: 1 };
          console.log("renderNode scale:" + JSON.stringify(renderNode.scale));
        })
      Button("translation")
        .width(300)
        .onClick(() => {
          renderNode.translation = { x: 100, y: 0 };
          console.log("renderNode translation:" + JSON.stringify(renderNode.translation));
        })
      Button("rotation")
        .width(300)
        .onClick(() => {
          renderNode.rotation = { x: 45, y: 0, z: 0 };
          console.log("renderNode rotation:" + JSON.stringify(renderNode.rotation));
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
          console.log("renderNode transform:" + JSON.stringify(renderNode.transform));
        })
      Button("shadow")
        .width(300)
        .onClick(() => {
          renderNode.shadowElevation = 10;
          renderNode.shadowColor = 0XFF00FF00;
          renderNode.shadowOffset = { x: 10, y: 10 };
          renderNode.shadowAlpha = 0.1;
          console.log("renderNode shadowElevation:" + JSON.stringify(renderNode.shadowElevation));
          console.log("renderNode shadowColor:" + JSON.stringify(renderNode.shadowColor));
          console.log("renderNode shadowOffset:" + JSON.stringify(renderNode.shadowOffset));
          console.log("renderNode shadowAlpha:" + JSON.stringify(renderNode.shadowAlpha));
        })
      Button("shadowRadius")
        .width(300)
        .onClick(() => {
          renderNode.shadowOffset = { x: 10, y: 10 };
          renderNode.shadowAlpha = 0.7
          renderNode.shadowRadius = 30;
          console.log("renderNode shadowOffset:" + JSON.stringify(renderNode.shadowOffset));
          console.log("renderNode shadowAlpha:" + JSON.stringify(renderNode.shadowAlpha));
          console.log("renderNode shadowRadius:" + JSON.stringify(renderNode.shadowRadius));
        })
      Button("border")
        .width(300)
        .onClick(() => {
          renderNode.borderWidth = { left: 8, top: 8, right: 8, bottom: 8 };
          renderNode.borderStyle = {
            left: BorderStyle.Solid,
            top: BorderStyle.Dotted,
            right: BorderStyle.Dashed,
            bottom: BorderStyle.Solid
          }
          renderNode.borderColor = { left: 0xFF0000FF, top: 0xFF0000FF, right: 0xFF0000FF, bottom: 0xFF0000FF };
          renderNode.borderRadius = { topLeft: 32, topRight: 32, bottomLeft: 32, bottomRight: 32 };
          console.log("renderNode borderWidth:" + JSON.stringify(renderNode.borderWidth));
          console.log("renderNode borderStyle:" + JSON.stringify(renderNode.borderStyle));
          console.log("renderNode borderColor:" + JSON.stringify(renderNode.borderColor));
          console.log("renderNode borderRadius:" + JSON.stringify(renderNode.borderRadius));
        })
      Button("shapeMask")
        .width(300)
        .onClick(() => {
          renderNode.shapeMask = mask;
          console.log("renderNode shapeMask:" + JSON.stringify(renderNode.shapeMask));
        })
      Button("shapeClip")
        .width(300)
        .onClick(() => {
          renderNode.shapeClip = clip;
          console.log("renderNode shapeMask:" + JSON.stringify(renderNode.shapeMask));
        })
    }
    .padding({ left: 35, right: 35, top: 35, bottom: 35 })
    .width("100%")
    .height("100%")
  }
}
```

## Using Custom Drawing

Override the [draw](../reference/apis-arkui/js-apis-arkui-renderNode.md#draw) API in **RenderNode** to customize the drawing content and use the [invalidate](../reference/apis-arkui/js-apis-arkui-renderNode.md#invalidate) API to manually trigger a redraw of the node.

> **NOTE**
> 
> - Triggering multiple **invalidate** calls at once will only result in a single redraw.
> 
> - Custom drawing can be implemented by calling ArkTS APIs or Node-APIs.

**ArkTS API sample code**

```ts
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class MyRenderNode extends RenderNode {
  draw(context: DrawContext) {
    // Obtain the canvas object.
    const canvas = context.canvas;
    // Create a brush.
    const brush = new drawing.Brush();
    // Set the brush color.
    brush.setColor({ alpha: 255, red: 255, green: 0, blue: 0 });
    canvas.attachBrush(brush);
    // Draw a rectangle.
    canvas.drawRect({ left: 0, right: 200, top: 0, bottom: 200 });
    canvas.detachBrush();
  }
}

const renderNode = new MyRenderNode();
renderNode.frame = { x: 0, y: 0, width: 300, height: 300 };
renderNode.backgroundColor = 0xff0000ff;
renderNode.opacity = 0.5;

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode?.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.frame = { x: 0, y: 0, width: 500, height: 500 }
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
          // Triggering multiple invalidate calls at once will only result in a single redraw.
          renderNode.invalidate();
          renderNode.invalidate();
        })
    }
  }
}
```

**Node-API sample code**

The C++ side can obtain the canvas through the Node-API and perform subsequent custom drawing operations.

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
    
    // Obtain the pointer to the canvas.
    void* temp = nullptr;
    napi_unwrap(env, args[1], &temp);
    OH_Drawing_Canvas *canvas = reinterpret_cast<OH_Drawing_Canvas*>(temp);
    
    // Obtain the canvas width.
    int32_t width;
    napi_get_value_int32(env, args[2], &width);
    
    // Obtain the canvas height.
    int32_t height;
    napi_get_value_int32(env, args[3], &height);
    
    // Pass in information such as the canvas, height, and width to the drawing API for custom drawing.
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

Add the following content to the **src/main/cpp/CMakeLists.txt** file of the project:
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

Add the definition of the custom drawing API on the ArkTS side to the **src/main/cpp/types/libentry/index.d.ts** file of the project. The following is an example:
```ts
import { DrawContext } from '@kit.ArkUI'

export const nativeOnDraw: (id: number, context: DrawContext, width: number, height: number) => number;
```

Code in ArkTS:

```ts
// Index.ets
import bridge from "libentry.so" // This .so file is written and generated by Node-API.
import { DrawContext, FrameNode, NodeController, RenderNode } from '@kit.ArkUI'

class MyRenderNode extends RenderNode {
  draw(context: DrawContext) {
    // The width and height in the context need to be converted from vp to px.
    bridge.nativeOnDraw(0, context, vp2px(context.size.height), vp2px(context.size.width));
  }
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      const renderNode = new MyRenderNode();
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

## Setting the Label

You can use the [label](../reference/apis-arkui/js-apis-arkui-renderNode.md#label12) API to assign labels for RenderNodes. This makes it easier to distinguish between nodes under node **Inspector**.

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
      console.log('label:', renderChildNode.label);
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
