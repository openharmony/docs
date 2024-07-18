# Building Custom Components

The ArkUI development framework provides the capability to create custom UI components through the NDK interface. These capabilities include custom measurement, custom layout, and custom drawing. Developers can integrate into the layout rendering process of the ArkUI development framework by registering relevant custom callback events. These events need to be declared using the [registerNodeCustomEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodecustomevent) function, and the component's custom event listeners should be added using the [addNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodecustomeventreceiver) function. The logic for custom measurement, custom layout, and custom drawing should be handled in the callback function of the listener.

> **NOTE**
>
> - Custom component event registration requires the declaration of the listener registration with [addNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodecustomeventreceiver) and the declaration of the required custom event types with [registerNodeCustomEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodecustomevent). Listeners can only monitor events that have been declared.
> 
> - It is important to pay attention to the logic of event deregistration, such as calling [removeNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#removenodecustomeventreceiver) to remove the event listener before the component is destroyed, and [unregisterNodeCustomEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#unregisternodecustomevent) to notify the ArkUI framework that the custom component events that have been monitored are no longer needed.
> 
> - [addNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodecustomeventreceiver) can add multiple function pointers, each of which will be triggered when the corresponding event is triggered. The corresponding [removeNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#removenodecustomeventreceiver) needs to pass the corresponding function pointer to remove the listener.
> 
> - [registerNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodecustomeventreceiver) is a global listener function, different from [addNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodecustomeventreceiver). [registerNodeCustomEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodecustomeventreceiver) can monitor the custom event triggers of all Native components, but only one function pointer can be passed, and the last function pointer used in multiple calls will be used for the callback. Deregistration is done using unregisterNodeCustomEventReceiver.
> 
> - The custom component-related interfaces ([measureNode](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#measurenode), [layoutNode](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#layoutnode), [setMeasuredSize](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#setmeasuredsize), [setLayoutPosition](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#setlayoutposition)) can only be used in the callback of the corresponding custom event ([ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE, ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodecustomeventtype)).


# Custom Layout Container

The following example creates a custom container that uses the maximum value of child components plus additional margins as its own size, and arranges the child components in the center.

**Figure 1** Custom Container Component

![customContainer](figures/customContainer.png)

1. Follow the [Accessing ArkTS Page](ndk-access-the-arkts-page.md) to create the preliminary project.

2. Create a custom container component encapsulation object.
   ```c
   // ArkUICustomContainerNode.h
   // Custom container component example
   
   #ifndef MYAPPLICATION_ARKUICUSTOMCONTAINERNODE_H
   #define MYAPPLICATION_ARKUICUSTOMCONTAINERNODE_H
   
   #include "ArkUINode.h"
   
   namespace NativeModule {
   
   class ArkUICustomContainerNode : public ArkUINode {
   public:
       // Create the component using the custom component type ARKUI_NODE_CUSTOM.
       ArkUICustomContainerNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_CUSTOM)) {
           // Register the custom event listener.
           nativeModule_->addNodeCustomEventReceiver(handle_, OnStaticCustomEvent);
           // Declare the custom event and pass itself as custom data.
           nativeModule_->registerNodeCustomEvent(handle_, ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE, 0, this);
           nativeModule_->registerNodeCustomEvent(handle_, ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT, 0, this);
       }
   
       ~ArkUICustomContainerNode() override {
           // Unregister the custom event listener.
           nativeModule_->removeNodeCustomEventReceiver(handle_, OnStaticCustomEvent);
           // Cancel the declaration of the custom event.
           nativeModule_->unregisterNodeCustomEvent(handle_, ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE);
           nativeModule_->unregisterNodeCustomEvent(handle_, ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT);
       }
   
       void SetPadding(int32_t padding) {
           padding_ = padding;
           // Custom property event update requires an explicit call to the mark dirty interface.
           nativeModule_->markDirty(handle_, NODE_NEED_MEASURE);
       }
   
   private:
       static void OnStaticCustomEvent(ArkUI_NodeCustomEvent *event) {
           // Get the component instance object and call the relevant instance method.
           auto customNode = reinterpret_cast<ArkUICustomContainerNode *>(OH_ArkUI_NodeCustomEvent_GetUserData(event));
           auto type = OH_ArkUI_NodeCustomEvent_GetEventType(event);
           switch (type) {
           case ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE:
               customNode->OnMeasure(event);
               break;
           case ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT:
               customNode->OnLayout(event);
               break;
           default:
               break;
           }
       }
   
       // Custom measurement logic.
       void OnMeasure(ArkUI_NodeCustomEvent *event) {
           auto layoutConstrain = OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure(event);
           // Create child node layout constraints, reusing the percentage reference values in the parent component layout.
           auto childLayoutConstrain = OH_ArkUI_LayoutConstraint_Copy(layoutConstrain);
           OH_ArkUI_LayoutConstraint_SetMaxHeight(childLayoutConstrain, 1000);
           OH_ArkUI_LayoutConstraint_SetMaxWidth(childLayoutConstrain, 1000);
           OH_ArkUI_LayoutConstraint_SetMinHeight(childLayoutConstrain, 0);
           OH_ArkUI_LayoutConstraint_SetMinWidth(childLayoutConstrain, 0);
   
           // Measure the child nodes to get the maximum value of the child nodes.
           auto totalSize = nativeModule_->getTotalChildCount(handle_);
           int32_t maxWidth = 0;
           int32_t maxHeight = 0;
           for (uint32_t i = 0; i < totalSize; i++) {
               auto child = nativeModule_->getChildAt(handle_, i);
               // Call the measurement interface to measure the Native component.
               nativeModule_->measureNode(child, childLayoutConstrain);
               auto size = nativeModule_->getMeasuredSize(child);
               if (size.width > maxWidth) {
                   maxWidth = size.width;
               }
               if (size.height > maxHeight) {
                   maxHeight = size.height;
               }
           }
           // Custom measurement is the size of all child nodes plus a fixed margin.
           nativeModule_->setMeasuredSize(handle_, maxWidth + 2 * padding_, maxHeight + 2 * padding_);
       }
   
       void OnLayout(ArkUI_NodeCustomEvent *event) {
           // Obtain the expected position of the parent component and set the position.
           auto position = OH_ArkUI_NodeCustomEvent_GetPositionInLayout(event);
           nativeModule_->setLayoutPosition(handle_, position.x, position.y);
   
           //Set the child component to be center-aligned.
           auto totalSize = nativeModule_->getTotalChildCount(handle_);
           auto selfSize = nativeModule_->getMeasuredSize(handle_);
           for (uint32_t i = 0; i < totalSize; i++) {
               auto child = nativeModule_->getChildAt(handle_, i);
               //Obtain the size of the child component.
               auto childSize = nativeModule_->getMeasuredSize(child);
               //Lay out the child component position.
               nativeModule_->layoutNode(child, (selfSize.width - childSize.width) / 2,
                                         (selfSize.height - childSize.height) / 2);
           }
       }
   
       int32_t padding_ = 100;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUICUSTOMCONTAINERNODE_H
   ```

3. Use a custom container to create a sample UI with text, and use a [simple implementation of the Timer module](ndk-loading-long-list.md).
   ```c
   // Customize the NDK interface entry.
   
   #include "NativeEntry.h"
   
   #include "ArkUICustomContainerNode.h"
   #include "ArkUITextNode.h"
   
   #include <arkui/native_node_napi.h>
   #include <arkui/native_type.h>
   #include <js_native_api.h>
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       // Obtain NodeContent.
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // Create a customized container and text component.
       auto node = std::make_shared<ArkUICustomContainerNode>();
       node->SetBackgroundColor(0xFFE0FFFF);
       auto textNode = std::make_shared<ArkUITextNode>();
       textNode->SetTextContent("CustomContainer Example");
       textNode->SetFontSize(16);
       textNode->SetBackgroundColor(0xFFfffacd);
       textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
       node->AddChild(textNode);
       CreateNativeTimer(env, textNode.get(), 1, [](void *userData, int32_t count) {
           auto textNode = reinterpret_cast<ArkUITextNode *>(userData);
           textNode->SetCircleColor(0xFF00FF7F);
       });
   
       // Keep the Native object in the management class to maintain the lifecycle.
       NativeEntry::GetInstance()->SetRootNode(node);
       g_env = env;
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // Release the Native object from the management class.
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   ```


## Customizing a Drawing Component

The following example creates a custom drawing component that can draw a custom rectangle and use the custom container for layout.

**Figure 2** Customizing a drawing component 
 
![customNode](figures/customNode.png)

1. Prepare the pre-project by referring to [Custom Layout Container](#custom-layout-container).

2. Create a custom drawing component encapsulation object.
   ```c
   // ArkUICustomNode.h
   // Example of a customized drawing component
   
   #ifndef MYAPPLICATION_ARKUICUSTOMNODE_H
   #define MYAPPLICATION_ARKUICUSTOMNODE_H
   
   #include <native_drawing/drawing_brush.h>
   #include <native_drawing/drawing_canvas.h>
   #include <native_drawing/drawing_path.h>
   
   #include "ArkUINode.h"
   
   namespace NativeModule {
   
   class ArkUICustomNode : public ArkUINode {
   public:
       // Use the custom component type ARKUI_NODE_CUSTOM to create a component.
       ArkUICustomNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_CUSTOM)) {
           // Register a custom event listener.
           nativeModule_->addNodeCustomEventReceiver(handle_, OnStaticCustomEvent);
           // Declare the user-defined event and transfer itself as the user-defined data.
           nativeModule_->registerNodeCustomEvent(handle_, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW, 0, this);
       }
   
       ~ArkUICustomNode() override {
           // Unregister a custom event listener.
           nativeModule_->removeNodeCustomEventReceiver(handle_, OnStaticCustomEvent);
           // Cancel the declaration of a customized event.
           nativeModule_->unregisterNodeCustomEvent(handle_, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW);
       }
   
       void SetRectColor(uint32_t color) {
           color_ = color;
           // The framework needs to be notified of the change of customized drawing attributes.
           nativeModule_->markDirty(handle_, NODE_NEED_RENDER);
       }
   
   private:
       static void OnStaticCustomEvent(ArkUI_NodeCustomEvent *event) {
           // Obtain the component instance object and call related instance methods.
           auto customNode = reinterpret_cast<ArkUICustomNode *>(OH_ArkUI_NodeCustomEvent_GetUserData(event));
           auto type = OH_ArkUI_NodeCustomEvent_GetEventType(event);
           switch (type) {
           case ARKUI_NODE_CUSTOM_EVENT_ON_DRAW:
               customNode->OnDraw(event);
               break;
           default:
               break;
           }
       }
   
       // Customize the drawing logic.
       void OnDraw(ArkUI_NodeCustomEvent *event) {
           auto drawContext = OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw(event);
           //Obtain the drawing object.
           auto drawCanvas = reinterpret_cast<OH_Drawing_Canvas *>(OH_ArkUI_DrawContext_GetCanvas(drawContext));
           //Obtain the component size.
           auto size = OH_ArkUI_DrawContext_GetSize(drawContext);
           //Draw customized content.
           auto path = OH_Drawing_PathCreate();
           OH_Drawing_PathMoveTo(path, size.width / 4, size.height / 4);
           OH_Drawing_PathLineTo(path, size.width * 3 / 4, size.height / 4);
           OH_Drawing_PathLineTo(path, size.width * 3 / 4, size.height * 3 / 4);
           OH_Drawing_PathLineTo(path, size.width / 4, size.height * 3 / 4);
           OH_Drawing_PathLineTo(path, size.width / 4, size.height / 4);
           OH_Drawing_PathClose(path);
           auto brush = OH_Drawing_BrushCreate();
           OH_Drawing_BrushSetColor(brush, color_);
           OH_Drawing_CanvasAttachBrush(drawCanvas, brush);
           OH_Drawing_CanvasDrawPath(drawCanvas, path);
           // Release the resource.
           OH_Drawing_BrushDestroy(brush);
           OH_Drawing_PathDestroy(path);
       }
   
       uint32_t color_ = 0xFFFFE4B5;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUICUSTOMNODE_H
   ```

3. Use the custom drawing component and customized container to create a sample GUI, and use the simple implementation of the timer module (ndk-loading-long-list.md).
   ```c
   // Customize the NDK interface entry component.
   
   #include "NativeEntry.h"
   
   #include "ArkUICustomContainerNode.h"
   #include "ArkUICustomNode.h"
   
   #include <arkui/native_node_napi.h>
   #include <arkui/native_type.h>
   #include <js_native_api.h>
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       // Obtain NodeContent.
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // Create a custom container and a custom drawing component.
       auto node = std::make_shared<ArkUICustomContainerNode>();
       node->SetBackgroundColor(0xFFE0FFFF);
       auto customNode = std::make_shared<ArkUICustomNode>();
       customNode->SetBackgroundColor(0xFFD3D3D3);
       customNode->SetWidth(150);
       customNode->SetHeight(150);
       node->AddChild(customNode);
       CreateNativeTimer(env, customNode.get(), 1, [](void *userData, int32_t count) {
           auto customNode = reinterpret_cast<ArkUICustomNode *>(userData);
           customNode->SetRectColor(0xFF00FF7F);
       });
   
       // Keep the Native object in the management class to maintain the lifecycle.
       NativeEntry::GetInstance()->SetRootNode(node);
       g_env = env;
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // Release the Native object from the management class.
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   
   ```
