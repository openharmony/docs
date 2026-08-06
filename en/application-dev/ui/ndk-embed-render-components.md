# Building a Rendering Node

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=1f32bcbdd4ae62e5f571fb73a9473dd94b7e4c93 translatedAt=2026-08-05T01:28:36.263Z pushedAt=2026-08-05T07:04:14.046Z -->

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
       ArkUI_AttributeItem content = {.string = "The yellow background is the C API page."};
       nodeAPI->setAttribute(text, NODE_TEXT_CONTENT, &content);
       nodeAPI->addChild(column, text);
   
       // Create a RenderNode container – custom component on the NDK side.
       ArkUI_NodeHandle Custom = nodeAPI->createNode(ARKUI_NODE_CUSTOM);
       valueWidth[0].f32 = 400;
       nodeAPI->setAttribute(Custom, NODE_WIDTH, &itemWidth);
       nodeAPI->setAttribute(Custom, NODE_HEIGHT, &itemHeight);
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
       ArkUI_NodeHandle testNode = nullptr;
       if (nodeAPI != nullptr) {
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
   
       // The Property is used to trigger set updates and synchronously update the Draw method of the modifier.
       struct AnimatableUserData {
           ArkUI_FloatAnimatablePropertyHandle width;
           ArkUI_FloatAnimatablePropertyHandle height;
           ArkUI_Vector2AnimatablePropertyHandle v2;
           ArkUI_ColorAnimatablePropertyHandle color;
       };
   
       // Set base values.
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
       // Bind properties to the modifier.
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
               // Obtain the animatable property (x and y values used as the width and height here). Custom properties can be defined to pass required parameters.
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
       ArkUI_NodeHandle testNode = nullptr;
       if (nodeAPI != nullptr) {
            // Obtain the context passed from the ETS side.
            ArkUI_ContextHandle context = nullptr;
            // Use code to check whether the context is successfully obtained.
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

## Mixing and Mounting Native Components and Rendering Nodes

Since API version 22, you can efficiently mix and mount native components and rendering nodes. To be specific, you can obtain the rendering node corresponding to a native component and mount it to that of a non-native component. In this way, the rendering nodes of both the native and non-native components are mixed.

Before mixing and mounting, you need to accept the native components. After the parent node accepts the target child node, the child node becomes an auxiliary node of the parent node. Only the auxiliary node can obtain the rendering node and mount it to another position in the rendering node tree.

### Accepting a Child Node as an Auxiliary Node

A node that meets the following conditions can be used as the parent node in the [OH_ArkUI_NativeModule_AdoptChild](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nativemodule_adoptchild) API to accept other nodes:

1. The node is an imperative node created on the C-API side.

2. The node is an imperative node created on the ArkTS side.

A node that meets the following conditions can be used as a child node in the **OH_ArkUI_NativeModule_AdoptChild** API to be accepted by other parent nodes:

1. The node is an imperative node created on the C-API side.

2. The node is an imperative node created on the ArkTS side.

3. The child node is the root node under BuilderNode.

After a child node is accepted as an auxiliary node, it cannot be mounted to other nodes as a regular child node. Otherwise, an error code will be thrown. However, the child node can be accepted by other parent nodes again. In this case, the child node will become a new auxiliary node of the other parent nodes. The accepted child node is not the real child node of its parent node, and cannot be found by the child component query API. It cannot be operated like a regular child node, and does not receive the measurement layout and event transfer from the parent node. It only receives the [lifecycle](../application-models/uiability-lifecycle.md#overview) propagation from the parent node.

### Obtaining the Rendering Node of an Auxiliary Node

When an auxiliary node is accepted, you can call [OH_ArkUI_RenderNodeUtils_GetRenderNode](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_getrendernode) to obtain its corresponding rendering node.

When you call the [disposeNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#disposenode) API of [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md) to destroy the parent node, call [OH_ArkUI_RenderNodeUtils_DisposeNode](../reference/apis-arkui/capi-native-render-h.md#oh_arkui_rendernodeutils_disposenode) to release the rendering node. Otherwise, a memory leak will occur.

### Operating a Rendering Node from an Auxiliary Node

After obtaining a rendering node from an accepted auxiliary node, you can use it for layout. The constraints are as follows:

1. A rendering node from an auxiliary node must be mounted to another rendering node.

   A rendering node from an auxiliary node can only be mounted to another rendering node as a child node or unmounted from another rendering node. Any other operations will fail and an error code will be returned. After the rendering node is mounted, the auxiliary node will be drawn in the target position corresponding to the rendering node.

2. The rendering node of an auxiliary node depends on the offscreen mounting status.

   If the parent node of the auxiliary node calls the [OH_ArkUI_NativeModule_RemoveAdoptedChild](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nativemodule_removeadoptedchild) API to cancel the offscreen mounting status, the rendering node will also be removed from the rendering node tree.

3. If the auxiliary node is no longer in the offscreen mounting state, the rendering node from this auxiliary node cannot be mounted to other rendering nodes.

### Creating and Accepting Web Components for Mixed Mounting

Before developing the following code, create a project by referring to [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md).

<!--RP1-->For the complete code, see [native_render_node_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeRenderNodeSample).<!--RP1End-->

1. Initialize the component environment using the NDK and create the root node of the corresponding rendering node.

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
       text->SetTextContent("This is an example of mounting a rendering node obtained from frameNode. Click the mount button below.");
       text->SetWidth(g_num300);
       text->SetHeight(g_num100);
   
       auto Custom = std::make_shared<ArkUICustomNode>();
       Custom->SetWidth(g_contentWidth);
       Custom->SetHeight(g_num100);
       column->AddChild(text);
       column->AddChild(Custom);
       custom_ = Custom;
       
       // Set up the mountable environment and mount the rendering node as the root node of the custom component.
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
       // Obtain the mount point of the component on the ArkTS side.
       ArkUI_NodeContentHandle contentHandle;
       int32_t result = OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       if (result != ARKUI_ERROR_CODE_NO_ERROR) {
           return nullptr;
       }
   
       // Create the root node of the component tree on the native side.
       auto scrollNode = std::make_shared<ArkUIScrollNode>();
       // Mount the root node of the component tree on the native side to the main UI tree.
       result = OH_ArkUI_NodeContent_AddNode(contentHandle, scrollNode->GetHandle());
       if (result != ARKUI_ERROR_CODE_NO_ERROR) {
           OH_LOG_ERROR(LOG_APP, "OH_ArkUI_NodeContent_AddNode Failed %{public}d", result);
           return nullptr;
       }
       // Save the component tree on the native side.
       g_nodeMap[contentHandle] = scrollNode;
       auto rootNode = testGetRenderNodeDemo();
       scrollNode->AddChild(rootNode);
       return nullptr;
   }
   ```

2. Create a node on the ArkTS side and pass the node to the C-API.

   <!-- @[Create_Node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeRenderNodeSample/entry/src/main/ets/pages/GetNode.ets) -->  

   ``` TypeScript
   
   import { BuilderNode, FrameNode, NodeContent, NodeController, typeNode } from '@kit.ArkUI';
   import entry from 'libentry.so';
   import { webview } from '@kit.ArkWeb';
   
   // Define the API for passing parameters.
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
       // Create a node tree.
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
       // Release created native components before page destruction.
       entry.disposeNodeTree(this.rootSlot)
     }
   
     build() {
       Column() {
         // Native component mount point.
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
           Text('create CustomDrawNode, ')
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

3. Obtain and accept the node, and obtain the corresponding rendering node on the C-API side.

   <!-- @[Adopt_Node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeRenderNodeSample/entry/src/main/cpp/NativeEntry.cpp) -->  

   ``` C++
   
   napi_value Adopt(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
       // Obtain the mount point of the component on the ArkTS side.
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

4. Cancel the accepted state of the node and release the corresponding rendering node on the C-API side.

   <!-- @[Remove_Adopt_Node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeRenderNodeSample/entry/src/main/cpp/NativeEntry.cpp) -->

   ``` C++
   
   napi_value RemoveAdopt(napi_env env, napi_callback_info info)
   {
       OH_ArkUI_NativeModule_RemoveAdoptedChild(custom_->GetHandle(), nodeHandle_);
       // After the node is released, you need to call OH_ArkUI_RenderNodeUtils_DisposeNode to release the corresponding rendering node. Otherwise, a memory leak occurs.
       OH_ArkUI_RenderNodeUtils_DisposeNode(renderHandle_);
       nodeHandle_ = nullptr;
       renderHandle_ = nullptr;
       return nullptr;
   }
   ```