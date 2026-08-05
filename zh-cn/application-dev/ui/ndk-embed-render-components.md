# 构建渲染节点
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->


从API version 20开始，ArkUI开发框架针对NDK接口，提供了直接构建渲染节点的能力，包括节点树操作、属性设置及含动画的自定义绘制。开发者通过调用渲染节点相关能力，可以绕过[registerNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomevent)的测量布局过程，直接对节点进行绘制并调整其大小和位置。


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
       nodeAPI->setAttribute(Custom, NODE_HEIGHT, &itemHeight);
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
       ArkUI_NodeHandle testNode = nullptr;
       if (nodeAPI != nullptr) {
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
               OH_Drawing_CanvasDetachPen(canvas);
               OH_Drawing_PenDestroy(pen);
               OH_Drawing_PathDestroy(path);
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
       ArkUI_NodeHandle testNode = nullptr;
       if (nodeAPI != nullptr) {
            // 获取ets侧传入的context。
            ArkUI_ContextHandle context = nullptr;
            // 通过code判断是否获取成功。
            auto code = OH_ArkUI_GetContextFromNapiValue(env, args[1], &context);
            if (code != ARKUI_ERROR_CODE_NO_ERROR) {
                return nullptr;
            }
            testNode = testRenderNode2(nodeAPI, context);
       }
   
       NativeEntry::GetInstance()->SetRootNode(testNode);
       return nullptr;
   }
      
   ```

## 混排挂载原生组件与渲染节点

从API version 22开始，开发者可以高效地混排挂载原生组件与渲染节点。具体操作为：获取原生组件对应的渲染节点，并将其挂载至非原生组件的渲染节点下，从而实现原生组件的渲染节点与非原生组件的渲染节点混排。

进行混排挂载前，需要对原生组件进行接纳操作。父节点接纳目标子节点后，子节点会成为父节点的附属节点，只有附属节点能够获取渲染节点，并将这个渲染节点挂载至渲染节点树的其他位置上。

### 接纳子节点为附属节点

满足以下条件的节点，可以作为[OH_ArkUI_NativeModule_AdoptChild](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nativemodule_adoptchild)接口中的父节点接纳其他节点：
1. 父节点是CAPI侧创建的命令式节点。
2. 父节点是ArkTS侧创建的命令式节点。

满足以下条件的节点，可以作为OH_ArkUI_NativeModule_AdoptChild接口中的子节点被其他父节点接纳：
1. 子节点是CAPI侧创建的命令式节点。
2. 子节点是ArkTS侧创建的命令式节点。
3. 子节点是BuilderNode下的根节点。

子节点被接纳为附属节点后，不允许再作为常规子节点挂载至其他节点，否则会抛出相应的错误码。但允许该子节点被其他父节点再次接纳，此时该子节点将会成为其他父节点的新附属节点。被接纳的子节点不是其父节点的真实子节点，不在子组件查询接口的查询范围，也不支持像常规子节点那样被操作，同时不接受父节点的测量布局和事件传递，仅接收父节点的[生命周期](../application-models/uiability-lifecycle.md#概述)传递。

### 获取附属节点的渲染节点

节点处于被接纳的附属节点状态下，允许调用[OH_ArkUI_RenderNodeUtils_GetRenderNode](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_getrendernode)获取它对应的RenderNode。

调用[ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md)的[disposeNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#disposenode)接口主动销毁父节点时，需要额外调用[OH_ArkUI_RenderNodeUtils_DisposeNode](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_disposenode)释放该渲染节点，否则会发生内存泄漏。


### 操作来自附属节点的渲染节点

从被接纳的附属节点中获取渲染节点后，即可使用该渲染节点进行布局，约束与限制如下：
1. 将来自附属节点的渲染节点挂载至其他渲染节点下。

   来自附属节点的渲染节点只能作为子节点挂载至其他渲染节点下，或者从其他渲染节点下取消挂载，除此之外的任何操作都会执行失败并返回错误码。完成渲染节点挂载后，附属节点将会被绘制在该渲染节点对应的目标位置上。

2. 附属节点的渲染节点依赖离屏挂载状态。

   如果该附属节点被它的父节点调用[OH_ArkUI_NativeModule_RemoveAdoptedChild](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nativemodule_removeadoptedchild)接口取消离屏挂载状态，那么该渲染节点也会随之一同从渲染节点树上被移除。

3. 来自附属节点的渲染节点，如果它对应的附属节点已不处于离屏挂载状态，不允许重新将它挂载至其他渲染节点上。

### 创建并接纳Web组件以实现混排挂载

在进行如下代码开发前，请参考[接入ArkTS页面](ndk-access-the-arkts-page.md)，创建前置工程。

<!--RP1-->完整示例请参考[native_render_node_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeRenderNodeSample)。<!--RP1End-->

1. NDK初始化组件环境，并创建对应的渲染节点根节点。

   <!-- @[Create_RootNode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeRenderNodeSample/entry/src/main/cpp/NativeEntry.cpp) -->  
   
   ``` C++
   
   std::shared_ptr<ArkUIBaseNode> custom_ = nullptr;
   std::shared_ptr<ArkUIRenderNode> render_ = nullptr;
   
   std::shared_ptr<ArkUIBaseNode> testGetRenderNodeDemo()
   {
       auto scroll = std::make_shared<ArkUIScrollNode>();
       scroll->SetWidth(g_contentWidth);
       scroll->SetHeight(g_contentHeight);
       scroll->SetBackgroundColor(0xff00F100);
   
       auto column = std::make_shared<ArkUIColumnNode>();
       column->SetWidth(g_contentWidth);
       column->SetHeight(g_contentHeight);
       auto text = std::make_shared<ArkUITextNode>();
       text->SetTextContent("挂载从frameNode获取的renderNode示例，点击下方挂载按钮");
       text->SetWidth(g_num300);
       text->SetHeight(g_num100);
   
       auto Custom = std::make_shared<ArkUICustomNode>();
       Custom->SetWidth(g_contentWidth);
       Custom->SetHeight(g_num100);
       column->AddChild(text);
       column->AddChild(Custom);
       custom_ = Custom;
       
       // 布置可挂载环境，将renderNode作为Custom的根节点挂载。
       auto renderNode = std::make_shared<ArkUIRenderNode>();
       Custom->AddRenderNode(renderNode);
       renderNode->SetSize(g_num300, g_num300);
       render_ = renderNode;
   
       scroll->AddChild(column);
       return scroll;
   }
   
   napi_value CreateRenderNodeGetNodeExample(napi_env env, napi_callback_info info)
   {
       size_t argc = 2;
       napi_value args[2] = {nullptr, nullptr};
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
       // 获取ArkTS侧组件挂载点。
       ArkUI_NodeContentHandle contentHandle;
       int32_t result = OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       if (result != ARKUI_ERROR_CODE_NO_ERROR) {
           return nullptr;
       }
   
       // 创建Native侧组件树根节点。
       auto scrollNode = std::make_shared<ArkUIScrollNode>();
       // 将Native侧组件树根节点挂载到UI主树上。
       result = OH_ArkUI_NodeContent_AddNode(contentHandle, scrollNode->GetHandle());
       if (result != ARKUI_ERROR_CODE_NO_ERROR) {
           OH_LOG_ERROR(LOG_APP, "OH_ArkUI_NodeContent_AddNode Failed %{public}d", result);
           return nullptr;
       }
       // 保存Native侧组件树。
       g_nodeMap[contentHandle] = scrollNode;
       auto rootNode = testGetRenderNodeDemo();
       scrollNode->AddChild(rootNode);
       return nullptr;
   }
   ```

2. ArkTS侧创建节点并传递该节点至CAPI。

   <!-- @[Create_Node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeRenderNodeSample/entry/src/main/ets/pages/GetNode.ets) -->  
   
   ``` TypeScript
   
   import { BuilderNode, FrameNode, NodeContent, NodeController, typeNode } from '@kit.ArkUI';
   import entry from 'libentry.so';
   import { webview } from '@kit.ArkWeb';
   
   // 定义传递参数的接口
   interface ParamsInterface {
     text: string;
     func: Function;
   }
   class MyNodeController extends NodeController {
     private imperativeNode: FrameNode | null = null;
     public rootNode: typeNode.Column |null = null;
     private buildNode: FrameNode | null = null;
   
     makeNode(uiContext: UIContext): FrameNode {
       this.rootNode = typeNode.createNode(uiContext, 'Column');
   
       this.imperativeNode = new FrameNode(uiContext);
       this.rootNode?.appendChild(this.imperativeNode);
       return this.rootNode;
     }
   
     adoptNode(uiContext:UIContext, message:string):void {
       let buildNode = new BuilderNode<[ParamsInterface]>(uiContext);
       // 创建节点树
       buildNode.build(wrapBuilder<[ParamsInterface]>(buildText), {
         text: message, func: () => {
           return 'FUNCTION';
         }
       }, { nestingBuilderSupported: true });
       this.buildNode = buildNode.getFrameNode();
       entry.adopt(buildNode);
     }
     removeAdoptedNode(uiContext:UIContext):void {
       entry.removeAdopt();
     }
   }
   
   @Builder
   function buildTextWithFunc(fun: Function) {
     Web({ src: 'https://www.example.com', controller: new webview.WebviewController() })
   }
   
   @Builder
   function buildText(params: ParamsInterface) {
     Column() {
       buildTextWithFunc(params.func)
     }
   }
   
   @Component
   struct CAPIComponent {
     private rootSlot = new NodeContent();
   
     aboutToAppear(): void {
       entry.createRenderNodeGetNodeExample(this.rootSlot, this.getUIContext())
     }
   
     aboutToDisappear(): void {
       // 页面销毁前释放已创建的Native组件。
       entry.disposeNodeTree(this.rootSlot)
     }
   
     build() {
       Column() {
         // Native组件挂载点。
         ContentSlot(this.rootSlot)
       }
     }
   }
   
   @Entry
   @Component
   struct Index {
     @State isShow: boolean = false;
     @State isAdopt: boolean = false;
     @State message: string = 'CreateNodeTree';
     @State adoptmsg: string = 'adopt web component';
   
     private myNodeController: MyNodeController = new MyNodeController();
     build() {
       Flex() {
         Column() {
           Text('create CustomDrawNode，')
             .fontSize(18)
             .fontWeight(FontWeight.Bold)
           Button(this.message)
             .onClick(() => {
               this.isShow = !this.isShow;
             })
           if (this.isShow) {
             CAPIComponent()
   
             Button(this.adoptmsg)
               .onClick(() => {
                 if (this.isAdopt) {
                   this.myNodeController.removeAdoptedNode(this.getUIContext());
                   this.adoptmsg = 'adopt web component';
                 } else {
                   this.myNodeController.adoptNode(this.getUIContext(),this.message);
                   this.adoptmsg = 'remove adopt web';
                 }
                 this.isAdopt = !this.isAdopt;
               })
   
             NodeContainer(this.myNodeController)
           }
         }.width('100%')
       }.width('100%')
     }
   }
   ```

3. C-API侧获取该节点，接纳节点并获取对应的渲染节点。

   <!-- @[Adopt_Node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeRenderNodeSample/entry/src/main/cpp/NativeEntry.cpp) -->  
   
   ``` C++
   
   napi_value Adopt(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
       // 获取ArkTS侧组件挂载点。
       int32_t result = OH_ArkUI_GetNodeHandleFromNapiValue(env, args[0], &nodeHandle_);
       if (result != ARKUI_ERROR_CODE_NO_ERROR) {
           return nullptr;
       }
       result = OH_ArkUI_NativeModule_AdoptChild(custom_->GetHandle(), nodeHandle_);
       OH_ArkUI_RenderNodeUtils_GetRenderNode(nodeHandle_, &renderHandle_);
       OH_ArkUI_RenderNodeUtils_AddChild(render_->GetHandle(), renderHandle_);
       return nullptr;
   }
   ```

4. C-API侧解除已被接纳节点的接纳状态，释放其对应的渲染节点。

   <!-- @[Remove_Adopt_Node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeRenderNodeSample/entry/src/main/cpp/NativeEntry.cpp) -->
   
   ``` C++
   
   napi_value RemoveAdopt(napi_env env, napi_callback_info info)
   {
       OH_ArkUI_NativeModule_RemoveAdoptedChild(custom_->GetHandle(), nodeHandle_);
       // 解除节点的接纳状态后，需要额外调用OH_ArkUI_RenderNodeUtils_DisposeNode释放对应的渲染节点，否则会导致内存泄漏。
       OH_ArkUI_RenderNodeUtils_DisposeNode(renderHandle_);
       nodeHandle_ = nullptr;
       renderHandle_ = nullptr;
       return nullptr;
   }
   ```
