# RenderNode

## 概述

对于不具备自己的渲染环境的三方框架，虽然实现了前端的解析以及布局、事件等处理，但需要依赖系统提供的基础渲染、动画的能力。[FrameNode](./arkts-user-defined-arktsNode-frameNode.md)上的通用属性、通用事件对这一类框架是多余的，会进行多次冗余的操作，包括布局、事件等处理逻辑。

[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md)是更加轻量级的渲染节点，仅包含渲染相关的能力。在该节点上暴露了设置基础的渲染属性的能力，并提供节点的动态增加、删除能力以及自定义绘制的能力。可以向三方框架提供基础的渲染、动画能力。

## 创建和删除节点

RenderNode提供了节点创建和删除的能力。可以通过RenderNode的构造函数创建自定义的RenderNode节点。通过构造函数创建的节点对应一个实体的节点。同时，可以通过RenderNode中的[dispose](../reference/apis-arkui/js-apis-arkui-renderNode.md#dispose12)接口来实现与实体节点的绑定关系的解除。

## 操作节点树

RenderNode提供了节点的增、删、查、改的能力，能够修改节点的子树结构；可以对所有RenderNode的节点的父子节点做出查询操作，并返回查询结果。

> **说明：**
>
> - RenderNode中查询获取得到的子树结构按照开发通过RenderNode的接口传递的参数构建。
>
> - RenderNode如果要与原生组件结合显示，使用需要依赖FrameNode中获取的RenderNode进行挂载上树。

## 设置和获取渲染相关属性

RenderNode中可以设置渲染相关的属性，包括：[backgroundColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#backgroundcolor)，[clipToFrame](../reference/apis-arkui/js-apis-arkui-renderNode.md#cliptoframe)，[opacity](../reference/apis-arkui/js-apis-arkui-renderNode.md#opacity)，[size](../reference/apis-arkui/js-apis-arkui-renderNode.md#size)，[position](../reference/apis-arkui/js-apis-arkui-renderNode.md#position)，[frame](../reference/apis-arkui/js-apis-arkui-renderNode.md#frame)，[pivot](../reference/apis-arkui/js-apis-arkui-renderNode.md#pivot)，[scale](../reference/apis-arkui/js-apis-arkui-renderNode.md#scale)，[translation](../reference/apis-arkui/js-apis-arkui-renderNode.md#translation)，[rotation](../reference/apis-arkui/js-apis-arkui-renderNode.md#rotation)，[transform](../reference/apis-arkui/js-apis-arkui-renderNode.md#transform)，[shadowColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowcolor)，[shadowOffset](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowoffset)，[shadowAlpha](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowalpha)，[shadowElevation](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowelevation)，[shadowRadius](../reference/apis-arkui/js-apis-arkui-renderNode.md#shadowradius)，[borderStyle](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderstyle12)，[borderWidth](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderwidth12)，[borderColor](../reference/apis-arkui/js-apis-arkui-renderNode.md#bordercolor12)，[borderRadius](../reference/apis-arkui/js-apis-arkui-renderNode.md#borderradius12)，[shapeMask](../reference/apis-arkui/js-apis-arkui-renderNode.md#shapemask12)，[shapeClip](../reference/apis-arkui/js-apis-arkui-renderNode.md#shapeclip12)，[markNodeGroup](../reference/apis-arkui/js-apis-arkui-renderNode.md#marknodegroup12)等。具体属性支持范围参考[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md#rendernode)接口说明。

> **说明：**
> 
> - RenderNode中查询获取得到的属性为设置的属性值。
> 
> - 若未传入参数或者传入参数为非法值则查询获得的为默认值。
>
> - 不建议对BuilderNode中的RenderNode进行修改操作。

```ts
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';

const renderNode = new RenderNode();
renderNode.frame = { x: 0, y: 0, width: 200, height: 350 };
renderNode.backgroundColor = 0xffff0000;
for (let i = 0; i < 5; i++) {
  const node = new RenderNode();
  // 设置node节点的Frame大小
  node.frame = { x: 10, y: 10 + 60 * i, width: 50, height: 50 };
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
            console.log('the child or nextChild is null');
          } else {
            // 获取子节点的位置信息
            console.log(`the position of child is x: ${child.position.x}, y: ${child.position.y}, ` +
            `the position of nextSibling is x: ${nextSibling.position.x}, y: ${nextSibling.position.y}`);
          }
        })
    }
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
  draw(context: DrawContext) {
    // 获取canvas对象
    const canvas = context.canvas;
    // 创建笔刷
    const brush = new drawing.Brush();
    // 设置笔刷颜色
    brush.setColor({ alpha: 255, red: 255, green: 0, blue: 0 });
    canvas.attachBrush(brush);
    // 绘制矩阵
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
          // 同步调用多次，仅触发一次重绘
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
  draw(context: DrawContext) {
    // 需要将 context 中的宽度和高度从vp转换为px
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

## 设置标签

开发者可以通过[label](../reference/apis-arkui/js-apis-arkui-renderNode.md#label12)接口向FrameNode中设置标签信息，便于在节点Inspector信息中较为方便对节点进行区分。

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
