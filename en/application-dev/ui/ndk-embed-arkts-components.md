# Embedding ArkTS Components


ArkUI on the native side offers a subset of ArkTS features, which excludes certain capabilities such as declarative UI syntax, custom struct components, and some advanced UI components.


For scenarios requiring ArkTS-specific features, ArkUI provides a mechanism to embed ArkTS components using [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md). This involves encapsulating ArkTS components and passing them to the native side, where they are converted into **ArkUI_NodeHandle** objects through the [OH_ArkUI_GetNodeHandleFromNapiValue](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_getnodehandlefromnapivalue) API for component mounting.


> **NOTE**
>
> - **ArkUI_NodeHandle** objects obtained from **OH_ArkUI_GetNodeHandleFromNapiValue** are for child component parameters only, such as the second parameter of the [addChild](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addchild) API. Using such objects in other scenarios, such as setting attributes with [setAttribute](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#setattribute), will not take effect and will return an error code.
> 
> - To modify ArkTS components on the native side, construct update data using Node-APIs, and then call the [update](../reference/apis-arkui/js-apis-arkui-ComponentContent.md#update) API of **ComponentContent**.
> 
> - During the process of [building custom components](ndk-build-custom-components.md), functions such as **measureNode** cannot be used to call components within the ArkTS module.


The following example introduces the ArkTS **Refresh** component based on the [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md) section.


**Figure 1** Mounting a text list to a Refresh component

![refresh_text_list](figures/refresh_text_list.gif)


1. Register the ArkTS component creation function to the native side for it to call, and use the **ComponentContent** capability to encapsulate the creation function.
   ```ts
   // MixedModule.ets
   // Create ArkTS components using the ComponentContent capability.
   
   import { NodeContent,  UIContext, RefreshModifier, ComponentContent } from '@kit.ArkUI';
   
   // Define the data object for interaction between the native side and ArkTS.
   interface NativeRefreshAttribute {
     isRefreshing: boolean;
     width?: number;
     height?: number;
     backgroundColor?: number;
     refreshOffset?: number;
     pullToRefresh?: boolean
     onRefreshing?: () => void;
     onOffsetChange?: (offset: number) => void;
   }
   
   // Define the format of the input parameters for the @Builder function.
   interface RefreshAttribute {
     isRefreshing: boolean;
     // Optimize attribute settings for performance with Modifier.
     modifier?: RefreshModifier;
     slot?: NodeContent;
     onRefreshing?: () => void;
     onOffsetChange?: (offset: number) => void;
   }
   
   // ComponentContent encapsulates the ArkTS component dependency on the global @Builder function. You can nest @Component decorated custom components within the @Builder function when needed.
   // The @Builder function provides a way of passing parameters, making it convenient to update parameters later through the update API of ComponentContent.
   @Builder
   function mixedRefresh(attribute: RefreshAttribute) {
     Refresh({ refreshing: attribute.isRefreshing }) {
       // As a container component, Refresh needs to use the ContentSlot mechanism to reserve a place for child components.
       ContentSlot(attribute.slot)
     }.attributeModifier(attribute.modifier)
     .onRefreshing(() => {
       console.info("on onRefreshing");
       if (attribute.onRefreshing) {
         console.info("on native onRefreshing");
         attribute.onRefreshing();
       }
     })
     .onOffsetChange((value: number) => {
       console.info("on offset change: " + value);
       if (attribute.onOffsetChange) {
         console.info("on native onOffsetChange");
         attribute.onOffsetChange(value);
       }
     })
   }
   
   // Define the return value of the creation function for interaction between the ArkTS side and the native side.
   interface MixedModuleResult {
     // Define the encapsulated object for the Refresh construction function, used by the native side to convert to an ArkUI_NodeHandle object.
     content?: ComponentContent<RefreshAttribute>;
     // As a container component, Refresh needs to use the ContentSlot mechanism to mount child components from the native side.
     childSlot?: NodeContent;
   }
   
   // Provide an entry function for creating ArkTS components.
   export function createMixedRefresh(value: NativeRefreshAttribute): MixedModuleResult {
     console.info("createMixedRefresh");
     // Use the AppStorage object to maintain the UI context object when the ability starts.
     let uiContent = AppStorage.get<UIContext>("context");
     let modifier = new RefreshModifier();
     if (value.width) {
       modifier.width(value.width)
     }
     if (value.height) {
       modifier.height(value.height)
     }
     if (value.backgroundColor) {
       modifier.backgroundColor(value.backgroundColor)
     }
     if (value.pullToRefresh) {
       modifier.pullToRefresh(value.pullToRefresh)
     }
     if (value.refreshOffset) {
       modifier.refreshOffset(value.refreshOffset)
     }
     // Create a NodeContent slot object for mounting Refresh child components.
     let nodeSlot = new NodeContent();
     // Create the Refresh component using ComponentContent and encapsulate it.
     let content = new ComponentContent<RefreshAttribute>(uiContent!, wrapBuilder<[RefreshAttribute]>(mixedRefresh),
       {
         isRefreshing: value.isRefreshing,
         modifier: modifier,
         slot: nodeSlot,
         onRefreshing: value.onRefreshing,
         onOffsetChange: value.onOffsetChange
       });
     // Pass the encapsulated object of the Refresh component and its child component slot object to the native side.
     return { content: content, childSlot: nodeSlot };
   }
   
   // Define the update function for the Refresh component for updating by the native side.
   // In the update scenario, you need to return the encapsulated object of the Refresh component and its child component slot object to prevent the component from being re-created.
   export function updateMixedRefresh(refresh: ComponentContent<RefreshAttribute>, childSlot: NodeContent,
     value: NativeRefreshAttribute): void {
     let modifier = new RefreshModifier();
     if (value.width) {
       modifier.width(value.width)
     }
     if (value.height) {
       modifier.height(value.height)
     }
     if (value.backgroundColor) {
       modifier.backgroundColor(value.backgroundColor)
     }
     if (value.pullToRefresh) {
       modifier.pullToRefresh(value.pullToRefresh)
     }
     if (value.refreshOffset) {
       modifier.refreshOffset(value.refreshOffset)
     }
     // Call the update API of ComponentContent to update.
     refresh.update({
       isRefreshing: value.isRefreshing,
       modifier: modifier,
       slot: childSlot,
       onRefreshing: value.onRefreshing,
       onOffsetChange: value.onOffsetChange
     })
   }
   
   ```

2. Register the creation and update functions with the native side.
   ```ts
   // entry.ets
   import nativeNode from 'libentry.so';
   import { NodeContent } from '@kit.ArkUI';
   import { createMixedRefresh, updateMixedRefresh } from './MixedModule'
   
   @Entry
   @Component
   struct Index {
     private rootSlot = new NodeContent();
     @State @Watch('changeNativeFlag') showNative: boolean = false;
   
     aboutToAppear(): void {
       // Set the UI context.
       AppStorage.setOrCreate<UIContext>("context", this.getUIContext());
       // Set the builder function for mixed mode.
       nativeNode.registerCreateMixedRefreshNode(createMixedRefresh);
       nativeNode.registerUpdateMixedRefreshNode(updateMixedRefresh);
     }
   
     changeNativeFlag(): void {
       if (this.showNative) {
         // Create and mount the NativeModule component.
         nativeNode.createNativeRoot(this.rootSlot)
       } else {
         // Destroy the NativeModule component.
         nativeNode.destroyNativeRoot()
       }
     }
   
     build() {
       Column() {
         Button(this.showNative ? "HideNativeUI" : "ShowNativeUI").onClick(() => {
           this.showNative = !this.showNative
         })
         Row() {
           // ArkTS inserts the native component.
           ContentSlot(this.rootSlot)
         }.layoutWeight(1)
       }
       .width('100%')
       .height('100%')
     }
   }
   ```

   ```cpp
   // native_init.cpp
   #include "napi/native_api.h"
   #include "ArkUIMixedRefresh.h"
   #include "NativeEntry.h"
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports) {
       napi_property_descriptor desc[] = {
           {"createNativeRoot", nullptr, NativeModule::CreateNativeRoot, nullptr, nullptr, nullptr, napi_default, nullptr},
           // Register the mixed mode creation function.
           {"registerCreateMixedRefreshNode", nullptr, NativeModule::ArkUIMixedRefresh::RegisterCreateRefresh, nullptr,
            nullptr, nullptr, napi_default, nullptr},
           // Register the mixed mode update function.
           {"registerUpdateMixedRefreshNode", nullptr, NativeModule::ArkUIMixedRefresh::RegisterUpdateRefresh, nullptr,
            nullptr, nullptr, napi_default, nullptr},
           {"destroyNativeRoot", nullptr, NativeModule::DestroyNativeRoot, nullptr, nullptr, nullptr, napi_default,
            nullptr}};
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
   
   extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
   ```

3. The native side saves the creation and update functions through the Node-API for subsequent calls.
   ```c
   // ArkUIMixedRefresh.h
   // Mixed mode interaction class.
   
   #ifndef MYAPPLICATION_ARKUIMIXEDREFRESH_H
   #define MYAPPLICATION_ARKUIMIXEDREFRESH_H
   
   #include "ArkUIMixedNode.h"
   
   #include <optional>
   
   #include <arkui/native_node_napi.h>
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   class ArkUIMixedRefresh : public ArkUIMixedNode {
   public:
       static napi_value RegisterCreateRefresh(napi_env env, napi_callback_info info);
       static napi_value RegisterUpdateRefresh(napi_env env, napi_callback_info info);
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUIMIXEDREFRESH_H
   ```

   ```cpp
   // ArkUIMixedRefresh.cpp
   // Mixed mode interaction class.
   
   #include "ArkUIMixedRefresh.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   namespace {
   napi_env g_env;
   napi_ref g_createRefresh;
   napi_ref g_updateRefresh;
   } // namespace
   
   napi_value ArkUIMixedRefresh::RegisterCreateRefresh(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       g_env = env;
       napi_ref refer;
       // Save the reference after creation to prevent it from being released.
       napi_create_reference(env, args[0], 1, &refer);
   
       g_createRefresh = refer;
       return nullptr;
   }
   
   napi_value ArkUIMixedRefresh::RegisterUpdateRefresh(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       g_env = env;
       napi_ref refer;
       // Save the reference after creation to prevent it from being released.
       napi_create_reference(env, args[0], 1, &refer);
   
       g_updateRefresh = refer;
       return nullptr;
   }
   
   } // namespace NativeModule
   ```

4. Abstract the base class of components in mixed mode for general logic management.
   ```c
   // ArkUIMixedNode.h
   // Base class for mixed mode.
   
   #ifndef MYAPPLICATION_ARKUIMIXEDNODE_H
   #define MYAPPLICATION_ARKUIMIXEDNODE_H
   
   #include <js_native_api.h>
   #include <js_native_api_types.h>
   
   #include "ArkUIBaseNode.h"
   #include "NativeModule.h"
   
   namespace NativeModule {
   
   // Wrap ArkTS Node
   class ArkUIMixedNode : public ArkUIBaseNode {
   public:
       ArkUIMixedNode(ArkUI_NodeHandle handle, napi_env env, napi_ref componentContent)
           : ArkUIBaseNode(handle), env_(env), componentContent_(componentContent) {}
   
       // In the base class destructor, the object on the ArkTS side in mixed mode needs to be released.
       ~ArkUIMixedNode() override { napi_delete_reference(env_, componentContent_); }
   
   protected:
       napi_env env_;
       napi_ref componentContent_;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUIMIXEDNODE_H
   ```

5. Implement the encapsulation object for the **Refresh** component in mixed mode.
   ```c
   // ArkUIMixedRefresh.h
   // The encapsulation object of Refresh in mixed mode on the native side.
   
   #ifndef MYAPPLICATION_ARKUIMIXEDREFRESH_H
   #define MYAPPLICATION_ARKUIMIXEDREFRESH_H
   
   #include "ArkUIMixedNode.h"
   #include "ArkUIBaseNode.h"
   
   #include <optional>
   
   #include <arkui/native_node_napi.h>
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   // Define the interaction data structure between the native side and the ArkTS side.
   struct NativeRefreshAttribute {
       std::optional<bool> isRefreshing;
       std::optional<float> width;
       std::optional<float> height;
       std::optional<uint32_t> backgroundColor;
       std::optional<float> refreshOffset;
       std::optional<bool> pullToRefresh;
       std::function<void()> onRefreshing;
       std::function<void(float)> onOffsetChange;
   };
   
   class ArkUIMixedRefresh : public ArkUIMixedNode {
   public:
       // Call the ArkTS method to create the Refresh component.
       static const std::shared_ptr<ArkUIMixedRefresh> Create(const NativeRefreshAttribute &attribute);
   
       ArkUIMixedRefresh(ArkUI_NodeHandle handle, ArkUI_NodeContentHandle contentHandle, napi_env env,
                         napi_ref componentContent, napi_ref nodeContent)
           : ArkUIMixedNode(handle, env, componentContent), contentHandle_(contentHandle), nodeContent_(nodeContent) {}
   
       ArkUIMixedRefresh() : ArkUIMixedNode(nullptr, nullptr, nullptr) {}
   
       ~ArkUIMixedRefresh() override { napi_delete_reference(env_, nodeContent_); } // Release the placeholder component slot object for the child node.
   
       void SetWidth(float width) { attribute_.width = width; }
   
       void SetHeight(float height) { attribute_.height = height; }
   
       void SetBackgroundColor(uint32_t color) { attribute_.backgroundColor = color; }
   
       void SetRefreshState(bool isRefreshing) { attribute_.isRefreshing = isRefreshing; }
   
       void SetPullToRefresh(bool pullToRefresh) { attribute_.pullToRefresh = pullToRefresh; }
   
       void SetRefreshOffset(float offset) { attribute_.refreshOffset = offset; }
   
       void SetRefreshCallback(const std::function<void()> &callback) { attribute_.onRefreshing = callback; }
   
       void SetOnOffsetChange(const std::function<void(float)> &callback) { attribute_.onOffsetChange = callback; }
   
       // To avoid frequent cross-language communication, cache property events on the native side and notify in batches.
       void FlushMixedModeCmd();
   
       static napi_value RegisterCreateRefresh(napi_env env, napi_callback_info info);
       static napi_value RegisterUpdateRefresh(napi_env env, napi_callback_info info);
   
   protected:
       void OnAddChild(const std::shared_ptr<ArkUIBaseNode> &child) override {
           assert(contentHandle_);
           // Use NodeContent to mount the component (can be a transformation object of ArkTS on the native side through ComponentContent, or a pure native component) under the ArkTS component.
           OH_ArkUI_NodeContent_AddNode(contentHandle_, child->GetHandle());
       }
   
       void OnRemoveChild(const std::shared_ptr<ArkUIBaseNode> &child) override {
           assert(contentHandle_);
           // Use NodeContent to remove the component.
           OH_ArkUI_NodeContent_RemoveNode(contentHandle_, child->GetHandle());
       }
   
       void OnInsertChild(const std::shared_ptr<ArkUIBaseNode> &child, int32_t index) override {
           assert(contentHandle_);
           // Use NodeContent to insert the component.
           OH_ArkUI_NodeContent_InsertNode(contentHandle_, child->GetHandle(), index);
       }
   
   private:
       // Use the Node-API to create the data structure on the ArkTS side.
       static napi_value CreateRefreshAttribute(const NativeRefreshAttribute &attribute, void *userData);
   
       ArkUI_NodeContentHandle contentHandle_;
       napi_ref nodeContent_;
       NativeRefreshAttribute attribute_;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUIMIXEDREFRESH_H
   ```

   Related implementation class description:

   ```c
   #include "ArkUIMixedRefresh.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   namespace {
   napi_env g_env;
   napi_ref g_createRefresh;
   napi_ref g_updateRefresh;
   } // namespace
   
   // Use the Node-API to create the data structure for interaction with the ArkTS side, used for the creation and update of the Refresh component.
   napi_value ArkUIMixedRefresh::CreateRefreshAttribute(const NativeRefreshAttribute &attribute, void *userData) {
       napi_property_descriptor desc[] = {
           {"width", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, userData},
           {"height", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, userData},
           {"backgroundColor", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, userData},
           {"pullToRefresh", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, userData},
           {"isRefreshing", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, userData},
           {"refreshOffset", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, userData},
           {"onRefreshing", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, userData},
           {"onOffsetChange", nullptr, nullptr, nullptr, nullptr, nullptr, napi_default, userData},
       };
       if (attribute.width) {
           napi_value width;
           napi_create_double(g_env, attribute.width.value(), &width);
           desc[0].value = width;
       }
       if (attribute.height) {
           napi_value height;
           napi_create_double(g_env, attribute.height.value(), &height);
           desc[1].value = height;
       }
       if (attribute.backgroundColor) {
           napi_value backgroundColor;
           napi_create_uint32(g_env, attribute.backgroundColor.value(), &backgroundColor);
           desc[2].value = backgroundColor;
       }
       if (attribute.pullToRefresh) {
           napi_value pullToRefresh;
           napi_create_int32(g_env, attribute.pullToRefresh.value(), &pullToRefresh);
           desc[3].value = pullToRefresh;
       }
       if (attribute.isRefreshing) {
           napi_value isRefreshing;
           napi_create_int32(g_env, attribute.isRefreshing.value(), &isRefreshing);
           desc[4].value = isRefreshing;
       }
       if (attribute.refreshOffset) {
           napi_value refreshOffset;
           napi_create_double(g_env, attribute.refreshOffset.value(), &refreshOffset);
           desc[5].value = refreshOffset;
       }
       if (attribute.onRefreshing) {
           OH_LOG_INFO(LOG_APP, "onRefreshing start");
           desc[6].method = [](napi_env env, napi_callback_info info) -> napi_value {
               OH_LOG_INFO(LOG_APP, "onRefreshing callback");
               size_t argc = 0;
               napi_value args[0];
               void *data;
               napi_get_cb_info(env, info, &argc, args, nullptr, &data);
               auto refresh = reinterpret_cast<ArkUIMixedRefresh *>(data);
               if (refresh && refresh->attribute_.onRefreshing) {
                   refresh->attribute_.onRefreshing();
               }
               return nullptr;
           };
       }
       if (attribute.onOffsetChange) {
           OH_LOG_INFO(LOG_APP, "onOffsetChange start");
           desc[7].method = [](napi_env env, napi_callback_info info) -> napi_value {
               OH_LOG_INFO(LOG_APP, "onOffsetChange callback");
               size_t argc = 1;
               napi_value args[1] = {nullptr};
               void *data;
               napi_get_cb_info(env, info, &argc, args, nullptr, &data);
               double offset = 0.0;
               napi_get_value_double(env, args[0], &offset);
               auto refresh = reinterpret_cast<ArkUIMixedRefresh *>(data);
               if (refresh && refresh->attribute_.onOffsetChange) {
                   refresh->attribute_.onOffsetChange(offset);
               }
               return nullptr;
           };
       }
       napi_value refreshAttribute = nullptr;
       auto result = napi_create_object_with_properties(g_env, &refreshAttribute, sizeof(desc) / sizeof(desc[0]), desc);
       if (result != napi_ok) {
           return nullptr;
       }
       return refreshAttribute;
   }
   
   // Create the component on the ArkTS side and save it in the encapsulation object on the native side.
   const std::shared_ptr<ArkUIMixedRefresh> ArkUIMixedRefresh::Create(const NativeRefreshAttribute &attribute) {
       napi_handle_scope scope;
       napi_open_handle_scope(g_env, &scope);
       auto refresh = std::make_shared<ArkUIMixedRefresh>();
       auto refreshAttribute = CreateRefreshAttribute(attribute, refresh.get());
       if (refreshAttribute == nullptr) {
           napi_close_handle_scope(g_env, scope);
           return nullptr;
       }
       napi_value result = nullptr;
       napi_value argv[1] = {refreshAttribute};
       napi_value createRefresh = nullptr;
       napi_get_reference_value(g_env, g_createRefresh, &createRefresh);
       // Call the ArkTS Create function to create the ArkTS ComponentContent.
       napi_call_function(g_env, nullptr, createRefresh, 1, argv, &result);
   
       // Obtain the ArkTS Refresh component.
       napi_value componentContent = nullptr;
       napi_get_named_property(g_env, result, "content", &componentContent);
       ArkUI_NodeHandle handle;
       OH_ArkUI_GetNodeHandleFromNapiValue(g_env, componentContent, &handle);
       assert(handle);
       // Obtain the child component slot of the ArkTS Refresh component.
       napi_value nodeContent = nullptr;
       napi_get_named_property(g_env, result, "childSlot", &nodeContent);
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(g_env, nodeContent, &contentHandle);
       assert(contentHandle);
       // Save the ArkTS ComponentContent to prevent the object on the ArkTS side from being released and for subsequent updates.
       napi_ref componentContentRef;
       napi_create_reference(g_env, componentContent, 1, &componentContentRef);
       // Save the ArkTS NodeContent to prevent the object on the ArkTS side from being released and for subsequent updates.
       napi_ref nodeContentRef;
       napi_create_reference(g_env, nodeContent, 1, &nodeContentRef);
       // Update the Refresh component related parameters.
       refresh->handle_ = handle;
       refresh->env_ = g_env;
       refresh->componentContent_ = componentContentRef;
       refresh->nodeContent_ = nodeContentRef;
       refresh->contentHandle_ = contentHandle;
       refresh->attribute_ = attribute;
       return refresh;
   }
   // Implementation of the update function.
   void ArkUIMixedRefresh::FlushMixedModeCmd() {
       napi_handle_scope scope;
       napi_open_handle_scope(g_env, &scope);
       // Create the input parameters for the call to the ArkTS API.
       auto refreshAttribute = CreateRefreshAttribute(attribute_, this);
       if (refreshAttribute == nullptr) {
           napi_close_handle_scope(g_env, scope);
           return;
       }
       // Obtain the remaining two API parameters for the update API.
       napi_value componentContent = nullptr;
       napi_get_reference_value(g_env, componentContent_, &componentContent);
       napi_value nodeContent = nullptr;
       napi_get_reference_value(g_env, nodeContent_, &nodeContent);
   
       napi_value argv[3] = {componentContent, nodeContent, refreshAttribute};
       napi_value updateRefresh = nullptr;
       napi_get_reference_value(g_env, g_updateRefresh, &updateRefresh);
       // Call the ArkTS Update function to update.
       napi_value result = nullptr;
       napi_call_function(g_env, nullptr, updateRefresh, 3, argv, &result);
   }
   
   napi_value ArkUIMixedRefresh::RegisterCreateRefresh(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       g_env = env;
       napi_ref refer;
       napi_create_reference(env, args[0], 1, &refer);
   
       g_createRefresh = refer;
       return nullptr;
   }
   
   napi_value ArkUIMixedRefresh::RegisterUpdateRefresh(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       g_env = env;
       napi_ref refer;
       napi_create_reference(env, args[0], 1, &refer);
   
       g_updateRefresh = refer;
       return nullptr;
   }
   
   } // namespace NativeModule
   
   ```

6. Use the page structure from the [Integrating with ArkTS Page](ndk-access-the-arkts-page.md) section, and continue with the [timer module simple implementation](ndk-loading-long-list.md), making the **Refresh** component the parent component of the text list. 
   ```c
   // MixedRefreshExample.h
   // Sample code for mixed mode.
   
   #ifndef MYAPPLICATION_MIXEDREFRESHEXAMPLE_H
   #define MYAPPLICATION_MIXEDREFRESHEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIMixedRefresh.h"
   #include "TextListExample.h"
   #include "UITimer.h"
   
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateMixedRefreshList(napi_env env) {
       auto list = CreateTextListExample();
       // Create the Refresh component in mixed mode and mount the List component.
       NativeRefreshAttribute nativeRefreshAttribute{
           .backgroundColor = 0xFF89CFF0, .refreshOffset = 64, .pullToRefresh = true};
       auto refresh = ArkUIMixedRefresh::Create(nativeRefreshAttribute);
       refresh->AddChild(list);
   
       // Set the event for mixed mode.
       refresh->SetOnOffsetChange(
           [](float offset) { OH_LOG_INFO(LOG_APP, "on refresh offset changed: %{public}f", offset); });
       refresh->SetRefreshCallback([refreshPtr = refresh.get(), env]() {
           OH_LOG_INFO(LOG_APP, "on refreshing");
           // Start the timer to simulate data acquisition.
           CreateNativeTimer(env, refreshPtr, 1, [](void *userData, int32_t count) {
               // Disable the refresh feature after data is obtained.
               auto refresh = reinterpret_cast<ArkUIMixedRefresh *>(userData);
               refresh->SetRefreshState(false);
               refresh->FlushMixedModeCmd();
           });
       });
   
       // Update the event to the ArkTS side.
       refresh->FlushMixedModeCmd();
       return refresh;
   }
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_MIXEDREFRESHEXAMPLE_H
   ```

   Replace the entry component creation with the pull-to-refresh text list.

   ```c
   #include "NativeEntry.h"
   
   #include "ArkUIMixedRefresh.h"
   #include "MixedRefreshExample.h"
   #include "TextListExample.h"
   
   #include <arkui/native_node_napi.h>
   #include <arkui/native_type.h>
   #include <js_native_api.h>
   #include <uv.h>
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       // Obtain NodeContent.
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // Create a Refresh text list.
       auto refresh = CreateMixedRefreshList(env);
   
       // Keep the native side object in the management class to maintain its lifecycle.
       NativeEntry::GetInstance()->SetRootNode(refresh);
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // Release the native side object from the management class.
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   
   ```
