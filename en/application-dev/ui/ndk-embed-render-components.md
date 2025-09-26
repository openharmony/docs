# Building a Rendering Node
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->


Since API version 20, the ArkUI development framework provides NDK APIs for directly building rendering nodes. These capabilities include rendering node tree operations, attribute configuration, and custom drawing with animations. By leveraging rendering node capabilities, you can bypass the measurement and layout processes associated with [registerNodeCustomEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodecustomevent), directly draw nodes, and adjust their sizes and positions.


- **Rendering node tree operations**: APIs such as [OH_ArkUI_RenderNodeUtils_AddRenderNode](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_addrendernode) and [OH_ArkUI_RenderNodeUtils_AddChild](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_addchild) are used to modify the structure of the rendering node tree. Rendering nodes can only be mounted to custom nodes of the ARKUI_NODE_CUSTOM type that have no other child nodes (linked to native nodes). Only one rendering node can be mounted per custom node. Specifically, the rendering node is attached as a subtree to a leaf custom node of the ARKUI_NODE_CUSTOM type.

- **Rendering node attribute configuration**: For details about APIs used to set rendering node attributes, see [Functions](../reference/apis-arkui/capi-native-render-h.md#functions). 

- **Custom drawing**: For implementation details, see [OH_ArkUI_RenderNodeUtils_SetContentModifierOnDraw](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_setcontentmodifierondraw) and its associated APIs. You can also use ContentModifier bound APIs (for example, [OH_ArkUI_RenderNodeUtils_SetFloatPropertyValue](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_setfloatpropertyvalue)) to dynamically modify the content to be drawn.



## Mounting Nodes and Setting Basic Attributes

The following example demonstrates how to create a rendering node, mount it to a custom node, and configure its basic attributes.

1. Follow the instructions in [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md) to create a project.

2. Create a rendering node capability object.
   ```c
   // NativeEntry.cpp
   // Example of a custom container component
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
       //Create the original container logic of the NDK.
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
       ArkUI_AttributeItem content = {.string = "The yellow background is the C API page"};
       nodeAPI->setAttribute(text, NODE_TEXT_CONTENT, &content);
       nodeAPI->addChild(column, text);
   
       // Create a RenderNode container – custom component on the NDK side.
       ArkUI_NodeHandle Custom = nodeAPI->createNode(ARKUI_NODE_CUSTOM);
       valueWidth[0].f32 = 400;
       nodeAPI->setAttribute(Custom, NODE_WIDTH, &itemWidth);
       nodeAPI->setAttribute(Custom, NODE_HEIGHT, &itemWidth);
       nodeAPI->addChild(column, Custom);
   
       // Create, mount, and build the rendering node tree.
       // Create the rendering node and its child nodes.
       auto renderRootNode = OH_ArkUI_RenderNodeUtils_CreateNode();
       auto firstChildRenderNode = OH_ArkUI_RenderNodeUtils_CreateNode();
       auto secondChildRenderNode = OH_ArkUI_RenderNodeUtils_CreateNode();
       auto thirdChildRenderNode = OH_ArkUI_RenderNodeUtils_CreateNode();
   
       auto result = OH_ArkUI_RenderNodeUtils_AddRenderNode(Custom, renderRootNode);
       if (result != ARKUI_ERROR_CODE_NO_ERROR) {
           // Check whether the root node is successfully mounted based on the error code.
           return scroll;
       }
       
       OH_ArkUI_RenderNodeUtils_AddChild(renderRootNode, firstChildRenderNode);
       OH_ArkUI_RenderNodeUtils_AddChild(renderRootNode, secondChildRenderNode);
       OH_ArkUI_RenderNodeUtils_AddChild(renderRootNode, thirdChildRenderNode);
       
       // Set the node sizes and positions.
       OH_ArkUI_RenderNodeUtils_SetSize(renderRootNode, 500, 500);
       OH_ArkUI_RenderNodeUtils_SetSize(firstChildRenderNode, 120, 120);
       OH_ArkUI_RenderNodeUtils_SetSize(secondChildRenderNode, 120, 120);
       OH_ArkUI_RenderNodeUtils_SetSize(thirdChildRenderNode, 120, 120);
   
       OH_ArkUI_RenderNodeUtils_SetPosition(renderRootNode, 300, 100);
       OH_ArkUI_RenderNodeUtils_SetPosition(firstChildRenderNode, 0, 0);
       OH_ArkUI_RenderNodeUtils_SetPosition(secondChildRenderNode, 140, 140);
       OH_ArkUI_RenderNodeUtils_SetPosition(thirdChildRenderNode, 280, 280);
       
       // Set background colors for rendering nodes (for visual distinction).
       OH_ArkUI_RenderNodeUtils_SetBackgroundColor(renderRootNode, 0xFFFFFFFF);
       OH_ArkUI_RenderNodeUtils_SetBackgroundColor(firstChildRenderNode, 0xFFFF0000); // R
       OH_ArkUI_RenderNodeUtils_SetBackgroundColor(secondChildRenderNode, 0xFF00FF00); // G
       OH_ArkUI_RenderNodeUtils_SetBackgroundColor(thirdChildRenderNode, 0xFF0000FF); // B
       
       // Simple attribute example
       OH_ArkUI_RenderNodeUtils_SetRotation(secondChildRenderNode, 45, 45, 0); // Rotate the node 45 degrees around the x-axis and y-axis and 0 degrees around the z-axis.
   
       // Border attribute example
       auto styleOption = OH_ArkUI_RenderNodeUtils_CreateNodeBorderStyleOption();
       OH_ArkUI_RenderNodeUtils_SetNodeBorderStyleOptionEdgeStyle(styleOption, ArkUI_BorderStyle::ARKUI_BORDER_STYLE_SOLID,
                                                                  ArkUI_EdgeDirection::ARKUI_EDGE_DIRECTION_ALL);
       OH_ArkUI_RenderNodeUtils_SetBorderStyle(firstChildRenderNode, styleOption);
       // After using the structure, destroy it to free memory.
       OH_ArkUI_RenderNodeUtils_DisposeNodeBorderStyleOption(styleOption);
       styleOption = nullptr;
       
       auto widthOption = OH_ArkUI_RenderNodeUtils_CreateNodeBorderWidthOption();
       OH_ArkUI_RenderNodeUtils_SetNodeBorderWidthOptionEdgeWidth(widthOption, 5,
                                                                  ArkUI_EdgeDirection::ARKUI_EDGE_DIRECTION_ALL);
       OH_ArkUI_RenderNodeUtils_SetBorderWidth(firstChildRenderNode, widthOption);
       // After using the structure, destroy it to free memory.
       OH_ArkUI_RenderNodeUtils_DisposeNodeBorderWidthOption(widthOption);
       widthOption = nullptr;
   
       auto colorOption = OH_ArkUI_RenderNodeUtils_CreateNodeBorderColorOption();
       OH_ArkUI_RenderNodeUtils_SetNodeBorderColorOptionEdgeColor(colorOption, 0xFF000000,
                                                                  ArkUI_EdgeDirection::ARKUI_EDGE_DIRECTION_ALL);
       result = OH_ArkUI_RenderNodeUtils_SetBorderColor(firstChildRenderNode, colorOption);
       // After using the structure, destroy it to free memory.
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


## Custom Drawing and Animation

The following example demonstrates how to create a rendering node, implement custom drawing, and add animation effects.

1. Follow the instructions in [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md) to create a project.

2. Create a rendering node capability object.
   ```c
   // NativeEntry.cpp
   // Example of a custom container component
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
       ArkUI_AttributeItem content = {.string = "This is the C API page."};
   
       nodeAPI->setAttribute(text, NODE_TEXT_CONTENT, &content);
   
       ArkUI_NodeHandle Custom = nodeAPI->createNode(ARKUI_NODE_CUSTOM);
       auto renderNode = OH_ArkUI_RenderNodeUtils_CreateNode();
       OH_ArkUI_RenderNodeUtils_AddRenderNode(Custom, renderNode);
       OH_ArkUI_RenderNodeUtils_SetSize(renderNode, 1000, 1000);
   
       // Define animatable properties (for driving animation and drawing).
       struct AnimatableUserData {
           ArkUI_FloatAnimatablePropertyHandle width;
           ArkUI_FloatAnimatablePropertyHandle height;
           ArkUI_Vector2AnimatablePropertyHandle v2;
           ArkUI_ColorAnimatablePropertyHandle color;
       };
   
       // Set initial values.
       AnimatableUserData *userData1 = new AnimatableUserData;
       auto widthAnimProperty = OH_ArkUI_RenderNodeUtils_CreateFloatAnimatableProperty(1000);
       userData1->width = widthAnimProperty;
       auto heightAnimProperty = OH_ArkUI_RenderNodeUtils_CreateFloatAnimatableProperty(1000);
       userData1->height = heightAnimProperty;
       auto vectorAnimP = OH_ArkUI_RenderNodeUtils_CreateVector2AnimatableProperty(1000, 1000);
       userData1->v2 = vectorAnimP;
       auto colorAnimP = OH_ArkUI_RenderNodeUtils_CreateColorAnimatableProperty(0xFFFF11FF);
       userData1->color = colorAnimP;
   
       // Associate the component with modifiers.
       auto animModifier = OH_ArkUI_RenderNodeUtils_CreateContentModifier();
       OH_ArkUI_RenderNodeUtils_AttachContentModifier(renderNode, animModifier);
       // Bind animatable properties to the modifier.
       OH_ArkUI_RenderNodeUtils_AttachFloatAnimatableProperty(animModifier, widthAnimProperty);
       OH_ArkUI_RenderNodeUtils_AttachFloatAnimatableProperty(animModifier, heightAnimProperty);
       OH_ArkUI_RenderNodeUtils_AttachVector2AnimatableProperty(animModifier, vectorAnimP);
       OH_ArkUI_RenderNodeUtils_AttachColorAnimatableProperty(animModifier, colorAnimP);
   
       // Implement custom drawing logic.
       OH_ArkUI_RenderNodeUtils_SetContentModifierOnDraw(
           animModifier, userData1, [](ArkUI_DrawContext *context, void *userData) {
               AnimatableUserData *data = (AnimatableUserData *)userData;
               float width = 0;
               float height = 0;
               uint32_t color = 0;
               ArkUI_Vector2AnimatablePropertyHandle v2 = data->v2;
               // The property parameter is used to pass values. x and y are used to replace width. You can customize the required parameters using property.
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
   
       // User-defined parameters.
       ArkUI_ContextCallback *update = new ArkUI_ContextCallback;
       update->userData = userData1;
       update->callback = [](void *user) {
           AnimatableUserData *data = (AnimatableUserData *)user;
           OH_ArkUI_RenderNodeUtils_SetFloatAnimatablePropertyValue(data->width, 100);
           OH_ArkUI_RenderNodeUtils_SetFloatAnimatablePropertyValue(data->height, 100);
           OH_ArkUI_RenderNodeUtils_SetVector2AnimatablePropertyValue(data->v2, 100, 100);
           OH_ArkUI_RenderNodeUtils_SetColorAnimatablePropertyValue(data->color, 0xFF0011FF);
       };
       // Execute the corresponding animation.
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
            // Obtain the context passed from the ets side.
            ArkUI_ContextHandle context = nullptr;
            // Use code to check whether the context is successfully obtained.
            auto code = OH_ArkUI_GetContextFromNapiValue(env, args[1], &context);
            testNode = testRenderNode2(nodeAPI, context);
       }
   
       NativeEntry::GetInstance()->SetRootNode(testNode);
       return nullptr;
   }
      
   ```
