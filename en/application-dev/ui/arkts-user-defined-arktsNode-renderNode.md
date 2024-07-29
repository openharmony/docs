# RenderNode

## Overview

For third-party frameworks that do not have their own rendering environment, although they have implemented front-end parsing as well as layout and event handling, they need to rely on the basic rendering and animation capabilities provided by the system. The common attributes and events on [FrameNode](./arkts-user-defined-arktsNode-frameNode.md) are redundant for this type of framework, leading to multiple unnecessary operations, including layout and event handling logic.

[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md) is a more lightweight rendering node, containing only rendering-related capabilities. This node exposes the ability to set basic rendering attributes and provides the ability to dynamically add and remove nodes as well as the ability to customize drawing. It can provide basic rendering and animation capabilities to third-party frameworks.

## Creating and Deleting Nodes

RenderNode provides the capability to create and delete nodes. Custom nodes can be created through the constructor of RenderNode. The nodes created by the constructor correspond to an entity node. At the same time, the binding relationship with the entity node can be released through the dispose interface in RenderNode.

## Operating Node Tree

RenderNode provides the ability to add, delete, query, and modify nodes, allowing the modification of the subtree structure of nodes; it is possible to query the parent-child nodes of all RenderNode nodes and return the query results.

> **Note:**
>
> - The subtree structure obtained by querying in RenderNode is built according to the parameters passed by the developer through the RenderNode interface.
>
> - If RenderNode needs to be displayed in combination with native components, it needs to rely on the RenderNode obtained from FrameNode to mount on the tree.

## Setting and Getting Rendering-Related Attributes

RenderNode can set rendering-related attributes, including: backgroundColor, clipToFrame, opacity, size, position, frame, pivot, scale, translation, rotation, transform, shadowColor, shadowOffset, shadowAlpha, shadowElevation, shadowRadius, borderStyle, borderWidth, borderColor, borderRadius, shapeMask.

> **Note:**
> 
> - The attributes obtained by querying in RenderNode are the values of the set attributes.
> 
> - If no parameters are passed or the passed parameters are illegal, the default values are obtained.

```ts
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 200, height: 350 };
renderNode.backgroundColor = 0xffff0000;
for (let i = 0; i < 5; i++) {
  const node = new RenderNode();
  // Set the Frame size of the node
  node.frame = { x: 10, y: 10 + 60 * i, width: 50, height: 50 };
  // Set the background color of the node
  node.backgroundColor = 0xff00ff00;
  // Mount the newly added node on renderNode
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
            // Get the position information of the child node
            console.log(`the position of child is x: ${child.position.x}, y: ${child.position.y}, ` +
            `the position of nextSibling is x: ${nextSibling.position.x}, y: ${nextSibling.position.y}`);
          }
        })
    }
  }
}
```

## Custom Drawing

By overriding the [draw](../reference/apis-arkui/js-apis-arkui-renderNode.md#draw) method in RenderNode, you can customize the drawing content of RenderNode. The [invalidate](../reference/apis-arkui/js-apis-arkui-renderNode.md#invalidate) interface can be used to actively trigger the redrawing of the node.

> **Note:**
> 
> - Triggering multiple invalidates simultaneously will only trigger one redraw.
> 
> - There are two ways to customize drawing: through ArkTS interface calls and through Node-API calls.

**ArkTS API Call Example:**

```ts
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class MyRenderNode extends RenderNode {
  draw(context: DrawContext) {
    // Get the canvas object
    const canvas = context.canvas;
    // Create a brush
    const brush = new drawing.Brush();
    // Set the brush color
    brush.setColor({ alpha: 255, red: 255, green: 0, blue: 0 });
    canvas.attachBrush(brush);
    // Draw a rectangle
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
    Row() {
      NodeContainer(this.myNodeController)
        .width('100%')
      Button('Invalidate')
        .onClick(() => {
          // Synchronously calling multiple times, only triggers one redraw
          renderNode.invalidate();
          renderNode.invalidate();
        })
    }
  }
}
```

**Node-API Call Example:**

The C++ side can obtain the Canvas and perform subsequent custom drawing operations through Node-API.

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
    
    // Get the Canvas pointer
    void* temp = nullptr;
    napi_unwrap(env, args[1], &temp);
    OH_Drawing_Canvas *canvas = reinterpret_cast<OH_Drawing_Canvas*>(temp);
    
    // Get the Canvas width
    int32_t width;
    napi_get_value_int32(env, args[2], &width);
    
    // Get the Canvas height
    int32_t height;
    napi_get_value_int32(env, args[3], &height);
    
    // Pass canvas, height, width, etc., to the drawing function for custom drawing
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

In the `src/main/cpp/CMakeLists.txt` file, you need to define the project, include directories, and link libraries. The modifications ensure that the native module is correctly built and linked with the necessary libraries.

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


In the `src/main/cpp/types/libentry/index.d.ts` file, you define the TypeScript interface for the native function that will be called from ArkTS.

```ts
import { DrawContext } from '@kit.ArkUI'

export const nativeOnDraw: (id: number, context: DrawContext, width: number, height: number) => number;
```

ArkTS code:

```ts
// Index.ets
import bridge from "libentry.so" // The .so file is generated by Node-API
import { DrawContext, FrameNode, NodeController, RenderNode } from '@kit.ArkUI'

class MyRenderNode extends RenderNode {
  draw(context: DrawContext) {
    // Convert the width and height from vp to px
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
