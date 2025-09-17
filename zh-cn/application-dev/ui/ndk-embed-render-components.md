# 构建渲染节点
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->


从API version 20开始，ArkUI开发框针对NDK接口，提供了直接构建渲染节点的能力，包括节点树操作、属性设置及含动画的自定义绘制。开发者通过调用渲染节点相关能力，可以绕过[registerNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomevent)的测量布局过程，直接对节点进行绘制并调整其大小和位置。


- **渲染节点树操作相关的能力** ，例如[OH_ArkUI_RenderNodeUtils_AddRenderNode](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_addrendernode)、[OH_ArkUI_RenderNodeUtils_AddChild](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_addchild)等接口用于编辑渲染节点树的结构。仅类型为ARKUI_NODE_CUSTOM且无其他子节点的自定义节点（加超链接到nativeNode）能够挂载渲染节点，且最多挂载一个渲染节点。即渲染节点以子树形式挂载在类型为ARKUI_NODE_CUSTOM的叶子自定义节点上。

- **渲染节点属性设置的能力** ，详情请参考[函数](../reference/apis-arkui/capi-native-render-h.md#函数)，查看当前渲染节点支持的属性能力。

- **自定义绘制能力**，参考[OH_ArkUI_RenderNodeUtils_SetContentModifierOnDraw](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_setcontentmodifierondraw)及其相关接口，同时可以通过[OH_ArkUI_RenderNodeUtils_SetFloatPropertyValue](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_setfloatpropertyvalue)这一类绑定在ContentModifier的接口对自定义绘制的内容进行动态修改。



## 节点挂载与基础属性设置

以下示例创建了一个渲染节点，并进行了基础的节点挂载和属性设置操作。

1. 按照[接入ArkTS页面](ndk-access-the-arkts-page.md)创建前置工程。

2. 创建渲染节点能力对象。
   ```c
   // NativeEntry.cpp
   // 自定义容器组件示例。
   #include <arkui/native_animate.h>
   #include <arkui/native_render.h>
   #include <arkui/native_type.h>
   #include <arkui/native_node_napi.h>
   #include <bits/alltypes.h>
   
   #include <string>
   
   #include <arkui/native_interface.h>
   #include <arkui/native_node.h>
   #include <native_drawing/drawing_canvas.h>
   #include <native_drawing/drawing_color.h>
   #include <native_drawing/drawing_path.h>
   #include <native_drawing/drawing_pen.h>
   
   ArkUI_NodeHandle testRenderNode(ArkUI_NativeNodeAPI_1 *nodeAPI) {
       // 创建NDK原有容器逻辑。
       ArkUI_NodeHandle scroll = nodeAPI->createNode(ARKUI_NODE_SCROLL);
       ArkUI_NumberValue valueWidth[] = {400};
       ArkUI_AttributeItem itemWidth = {valueWidth, sizeof(valueWidth) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(scroll, NODE_WIDTH, &itemWidth);
       ArkUI_NumberValue valueHeight[] = {600};
       ArkUI_AttributeItem itemHeight = {valueHeight, sizeof(valueHeight) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(scroll, NODE_HEIGHT, &itemHeight);
       ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
       nodeAPI->setAttribute(column, NODE_WIDTH, &itemWidth);
       nodeAPI->setAttribute(column, NODE_HEIGHT, &itemHeight);
       ArkUI_NodeHandle text = nodeAPI->createNode(ARKUI_NODE_TEXT);
       ArkUI_AttributeItem content = {.string = "黄色背景是C-API页面"};
       nodeAPI->setAttribute(text, NODE_TEXT_CONTENT, &content);
       nodeAPI->addChild(column, text);
   
       // 创建RenderNode容器 -- NDK侧的Custom组件。
       ArkUI_NodeHandle Custom = nodeAPI->createNode(ARKUI_NODE_CUSTOM);
       valueWidth[0].f32 = 400;
       nodeAPI->setAttribute(Custom, NODE_WIDTH, &itemWidth);
       nodeAPI->setAttribute(Custom, NODE_HEIGHT, &itemWidth);
       nodeAPI->addChild(column, Custom);
   
       // 节点操作类接口 创建 - 挂载 - 构建树。
       // 创建部分。
       auto renderRootNode = OH_ArkUI_RenderNodeUtils_CreateNode();
       auto firstChildRenderNode = OH_ArkUI_RenderNodeUtils_CreateNode();
       auto secondChildRenderNode = OH_ArkUI_RenderNodeUtils_CreateNode();
       auto thirdChildRenderNode = OH_ArkUI_RenderNodeUtils_CreateNode();
   
       auto result = OH_ArkUI_RenderNodeUtils_AddRenderNode(Custom, renderRootNode);
       if (result != ARKUI_ERROR_CODE_NO_ERROR) {
           // 通过错误码判断根节点是否挂载成功。
           return scroll;
       }
       
       OH_ArkUI_RenderNodeUtils_AddChild(renderRootNode, firstChildRenderNode);
       OH_ArkUI_RenderNodeUtils_AddChild(renderRootNode, secondChildRenderNode);
       OH_ArkUI_RenderNodeUtils_AddChild(renderRootNode, thirdChildRenderNode);
       
       // 设置节点尺寸与位置。
       OH_ArkUI_RenderNodeUtils_SetSize(renderRootNode, 500, 500);
       OH_ArkUI_RenderNodeUtils_SetSize(firstChildRenderNode, 120, 120);
       OH_ArkUI_RenderNodeUtils_SetSize(secondChildRenderNode, 120, 120);
       OH_ArkUI_RenderNodeUtils_SetSize(thirdChildRenderNode, 120, 120);
   
       OH_ArkUI_RenderNodeUtils_SetPosition(renderRootNode, 300, 100);
       OH_ArkUI_RenderNodeUtils_SetPosition(firstChildRenderNode, 0, 0);
       OH_ArkUI_RenderNodeUtils_SetPosition(secondChildRenderNode, 140, 140);
       OH_ArkUI_RenderNodeUtils_SetPosition(thirdChildRenderNode, 280, 280);
       
       // 设置颜色，方便通过颜色观察到节点的显示范围。
       OH_ArkUI_RenderNodeUtils_SetBackgroundColor(renderRootNode, 0xFFFFFFFF);
       OH_ArkUI_RenderNodeUtils_SetBackgroundColor(firstChildRenderNode, 0xFFFF0000); // R
       OH_ArkUI_RenderNodeUtils_SetBackgroundColor(secondChildRenderNode, 0xFF00FF00); // G
       OH_ArkUI_RenderNodeUtils_SetBackgroundColor(thirdChildRenderNode, 0xFF0000FF); // B
       
       // 简单的属性设置示例。
       OH_ArkUI_RenderNodeUtils_SetRotation(secondChildRenderNode, 45, 45, 0); // xy轴旋转45度，z轴旋转0度
   
       // 边框属性实例。
       auto styleOption = OH_ArkUI_RenderNodeUtils_CreateNodeBorderStyleOption();
       OH_ArkUI_RenderNodeUtils_SetNodeBorderStyleOptionEdgeStyle(styleOption, ArkUI_BorderStyle::ARKUI_BORDER_STYLE_SOLID,
                                                                  ArkUI_EdgeDirection::ARKUI_EDGE_DIRECTION_ALL);
       OH_ArkUI_RenderNodeUtils_SetBorderStyle(firstChildRenderNode, styleOption);
       // 结构体使用完成后，销毁释放内存。
       OH_ArkUI_RenderNodeUtils_DisposeNodeBorderStyleOption(styleOption);
       styleOption = nullptr;
       
       auto widthOption = OH_ArkUI_RenderNodeUtils_CreateNodeBorderWidthOption();
       OH_ArkUI_RenderNodeUtils_SetNodeBorderWidthOptionEdgeWidth(widthOption, 5,
                                                                  ArkUI_EdgeDirection::ARKUI_EDGE_DIRECTION_ALL);
       OH_ArkUI_RenderNodeUtils_SetBorderWidth(firstChildRenderNode, widthOption);
       // 结构体使用完成后，销毁释放内存。
       OH_ArkUI_RenderNodeUtils_DisposeNodeBorderWidthOption(widthOption);
       widthOption = nullptr;
   
       auto colorOption = OH_ArkUI_RenderNodeUtils_CreateNodeBorderColorOption();
       OH_ArkUI_RenderNodeUtils_SetNodeBorderColorOptionEdgeColor(colorOption, 0xFF000000,
                                                                  ArkUI_EdgeDirection::ARKUI_EDGE_DIRECTION_ALL);
       result = OH_ArkUI_RenderNodeUtils_SetBorderColor(firstChildRenderNode, colorOption);
       // 结构体使用完成后，销毁释放内存。
       OH_ArkUI_RenderNodeUtils_DisposeNodeBorderColorOption(colorOption);
       colorOption = nullptr;
   
       nodeAPI->addChild(scroll, column);
       return scroll;
   }

    napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

       auto *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       if (nodeAPI != nullptr) {
            ArkUI_NodeHandle testNode;
            testNode = testRenderNode(nodeAPI);
       }
   
       NativeEntry::GetInstance()->SetRootNode(testNode);
       return nullptr;
   }
   
   ```


## 自定义绘制及动画

以下示例创建了一个渲染节点，调用自定义绘制能力并附加动画功能。

1. 按照[接入ArkTS页面](ndk-access-the-arkts-page.md)创建前置工程。

2. 创建渲染节点能力对象。
   ```c
   // NativeEntry.cpp
   // 自定义容器组件示例。
   #include <arkui/native_animate.h>
   #include <arkui/native_render.h>
   #include <arkui/native_type.h>
   #include <arkui/native_node_napi.h>
   #include <bits/alltypes.h>
   
   #include <string>
   
   #include <arkui/native_interface.h>
   #include <arkui/native_node.h>
   #include <native_drawing/drawing_canvas.h>
   #include <native_drawing/drawing_color.h>
   #include <native_drawing/drawing_path.h>
   #include <native_drawing/drawing_pen.h>
   
   ArkUI_NodeHandle testRenderNode2(ArkUI_NativeNodeAPI_1 *nodeAPI, ArkUI_ContextHandle context) {
   
       ArkUI_NodeHandle scroll = nodeAPI->createNode(ARKUI_NODE_COLUMN);
       ArkUI_NumberValue valueWidth[] = {400};
       ArkUI_AttributeItem itemWidth = {valueWidth, sizeof(valueWidth) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(scroll, NODE_WIDTH, &itemWidth);
       ArkUI_NumberValue valueHeight[] = {600};
       ArkUI_AttributeItem itemHeight = {valueHeight, sizeof(valueHeight) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(scroll, NODE_HEIGHT, &itemHeight);
       valueHeight[0].u32 = 0xff00F100;
       nodeAPI->setAttribute(scroll, NODE_BACKGROUND_COLOR, &itemHeight);
   
       ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
       ArkUI_NodeHandle text = nodeAPI->createNode(ARKUI_NODE_TEXT);
       ArkUI_AttributeItem content = {.string = "这是C-API页面"};
   
       nodeAPI->setAttribute(text, NODE_TEXT_CONTENT, &content);
   
       ArkUI_NodeHandle Custom = nodeAPI->createNode(ARKUI_NODE_CUSTOM);
       auto renderNode = OH_ArkUI_RenderNodeUtils_CreateNode();
       OH_ArkUI_RenderNodeUtils_AddRenderNode(Custom, renderNode);
       OH_ArkUI_RenderNodeUtils_SetSize(renderNode, 1000, 1000);
   
       // Property的作用是触发set更新，同步更新modifier的Draw方法。
       struct AnimatableUserData {
           ArkUI_FloatAnimatablePropertyHandle width;
           ArkUI_FloatAnimatablePropertyHandle height;
           ArkUI_Vector2AnimatablePropertyHandle v2;
           ArkUI_ColorAnimatablePropertyHandle color;
       };
   
       // 设置基础值。
       AnimatableUserData *userData1 = new AnimatableUserData;
       auto widthAnimProperty = OH_ArkUI_RenderNodeUtils_CreateFloatAnimatableProperty(1000);
       userData1->width = widthAnimProperty;
       auto heightAnimProperty = OH_ArkUI_RenderNodeUtils_CreateFloatAnimatableProperty(1000);
       userData1->height = heightAnimProperty;
       auto vectorAnimP = OH_ArkUI_RenderNodeUtils_CreateVector2AnimatableProperty(1000, 1000);
       userData1->v2 = vectorAnimP;
       auto colorAnimP = OH_ArkUI_RenderNodeUtils_CreateColorAnimatableProperty(0xFFFF11FF);
       userData1->color = colorAnimP;
   
       // 关联组件和多个modifier。
       auto animModifier = OH_ArkUI_RenderNodeUtils_CreateContentModifier();
       OH_ArkUI_RenderNodeUtils_AttachContentModifier(renderNode, animModifier);
       // 关联modifier和property。
       OH_ArkUI_RenderNodeUtils_AttachFloatAnimatableProperty(animModifier, widthAnimProperty);
       OH_ArkUI_RenderNodeUtils_AttachFloatAnimatableProperty(animModifier, heightAnimProperty);
       OH_ArkUI_RenderNodeUtils_AttachVector2AnimatableProperty(animModifier, vectorAnimP);
       OH_ArkUI_RenderNodeUtils_AttachColorAnimatableProperty(animModifier, colorAnimP);
   
       // 设置自定义绘制内容。
       OH_ArkUI_RenderNodeUtils_SetContentModifierOnDraw(
           animModifier, userData1, [](ArkUI_DrawContext *context, void *userData) {
               AnimatableUserData *data = (AnimatableUserData *)userData;
               float width = 0;
               float height = 0;
               uint32_t color = 0;
               ArkUI_Vector2AnimatablePropertyHandle v2 = data->v2;
               // property主要为传值用，这里用x,y来替代width，实际使用时可以通过property来自定义所需参数。
               OH_ArkUI_RenderNodeUtils_GetVector2AnimatablePropertyValue(v2, &width, &height);
               ArkUI_ColorAnimatablePropertyHandle cp = data->color;
               OH_ArkUI_RenderNodeUtils_GetColorAnimatablePropertyValue(cp, &color);
   
   
               auto *canvas1 = OH_ArkUI_DrawContext_GetCanvas(context);
               OH_Drawing_Canvas *canvas = reinterpret_cast<OH_Drawing_Canvas *>(canvas1);
               auto path = OH_Drawing_PathCreate();
               OH_Drawing_PathMoveTo(path, width / 4, height / 4);
               OH_Drawing_PathLineTo(path, width * 3 / 4, height / 4);
               OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
               OH_Drawing_PathLineTo(path, width / 4, height * 3 / 4);
               OH_Drawing_PathLineTo(path, width / 4, height / 4);
               OH_Drawing_PathClose(path);
               auto pen = OH_Drawing_PenCreate();
               OH_Drawing_PenSetWidth(pen, 10);
               OH_Drawing_PenSetColor(pen, color);
               OH_Drawing_CanvasAttachPen(canvas, pen);
               OH_Drawing_CanvasDrawPath(canvas, path);
           });
   
       // 用户自定义参数。
       ArkUI_ContextCallback *update = new ArkUI_ContextCallback;
       update->userData = userData1;
       update->callback = [](void *user) {
           AnimatableUserData *data = (AnimatableUserData *)user;
           OH_ArkUI_RenderNodeUtils_SetFloatAnimatablePropertyValue(data->width, 100);
           OH_ArkUI_RenderNodeUtils_SetFloatAnimatablePropertyValue(data->height, 100);
           OH_ArkUI_RenderNodeUtils_SetVector2AnimatablePropertyValue(data->v2, 100, 100);
           OH_ArkUI_RenderNodeUtils_SetColorAnimatablePropertyValue(data->color, 0xFF0011FF);
       };
       // 执行对应的动画。
       ArkUI_NativeAnimateAPI_1 *animateApi = nullptr;
       OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_ANIMATE, ArkUI_NativeAnimateAPI_1, animateApi);
   
       ArkUI_AnimateCompleteCallback *completeCallback = new ArkUI_AnimateCompleteCallback;
       completeCallback->userData = userData1;
       completeCallback->type = ARKUI_FINISH_CALLBACK_REMOVED;
       completeCallback->callback = [](void *userData) {
           AnimatableUserData *data = (AnimatableUserData *)userData;
       };
   
       ArkUI_AnimateOption *option = OH_ArkUI_AnimateOption_Create();
       OH_ArkUI_AnimateOption_SetDuration(option, 2000);
       OH_ArkUI_AnimateOption_SetTempo(option, 1.1);
       OH_ArkUI_AnimateOption_SetCurve(option, ARKUI_CURVE_EASE);
       OH_ArkUI_AnimateOption_SetDelay(option, 20);
       OH_ArkUI_AnimateOption_SetIterations(option, 1);
       OH_ArkUI_AnimateOption_SetPlayMode(option, ARKUI_ANIMATION_PLAY_MODE_REVERSE);
       ArkUI_ExpectedFrameRateRange *range = new ArkUI_ExpectedFrameRateRange;
       range->min = 10;
       range->max = 120;
       range->expected = 60;
       OH_ArkUI_AnimateOption_SetExpectedFrameRateRange(option, range);
           animateApi->animateTo(context, option, update, completeCallback);
   
   
       nodeAPI->setAttribute(Custom, NODE_WIDTH, &itemWidth);
       nodeAPI->setAttribute(Custom, NODE_HEIGHT, &itemHeight);
   
       nodeAPI->addChild(column, text);
       nodeAPI->addChild(column, Custom);
       nodeAPI->addChild(scroll, column);
       return scroll;
   }

    napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 2;
       napi_value args[2] = {nullptr, nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

       auto *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       if (nodeAPI != nullptr) {
            ArkUI_NodeHandle testNode;
            // 获取ets侧传入的context。
            ArkUI_ContextHandle context = nullptr;
            // 通过code判断是否获取成功。
            auto code = OH_ArkUI_GetContextFromNapiValue(env, args[1], &context);
            testNode = testRenderNode2(nodeAPI, context);
       }
   
       NativeEntry::GetInstance()->SetRootNode(testNode);
       return nullptr;
   }
      
   ```
