# 嵌入ArkTS组件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

ArkUI在Native侧提供的能力作为ArkTS的子集，部分能力不会在Native侧提供，如声明式UI语法，自定义struct组件，UI高级组件。


针对需要使用ArkTS侧独立能力的场景，ArkUI开发框架提供了Native侧嵌入ArkTS组件的能力，该能力依赖[ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md)机制，通过ComponentContent完成对ArkTS组件的封装，然后将封装对象转递到Native侧，通过Native侧的[OH_ArkUI_GetNodeHandleFromNapiValue](../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnodehandlefromnapivalue)接口转化为ArkUI_NodeHandle对象用于Native侧组件挂载使用。


> **说明：**
>
> - 通过OH_ArkUI_GetNodeHandleFromNapiValue接口获得的ArkUI_NodeHandle对象只能作为子组件参数使用，如[addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild)接口的第二个参数，将该对象使用在其他场景下，如[setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)设置属性将不生效并返回错误码。
> 
> - 针对Native侧修改ArkTS组件的场景，需要在Native侧通过Node-API方式构建ArkTS侧的更新数据，再通过ComponentContent的[update](../reference/apis-arkui/js-apis-arkui-ComponentContent.md#update)接口更新。
> 
> - [构建自定义组件](ndk-build-custom-components.md)时，相关函数如measureNode等无法对ArkTS模块内部的组件进行调用。


以下示例代码在[接入ArkTS页面](ndk-access-the-arkts-page.md)章节基础上引入ArkTS的Refresh组件。


**图1** Refresh组件挂载文本列表

![refresh_text_list](figures/refresh_text_list.gif)


1. 注册ArkTS组件创建函数给Native侧，以便Native侧调用，创建函数使用ComponentContent能力进行封装。
   ```ts
   // MixedModule.ets
   // 使用ComponentContent能力创建ArkTS组件
   
   import { NodeContent,  UIContext, RefreshModifier, ComponentContent } from '@kit.ArkUI';
   
   // 定义Native侧和ArkTS进行交互的数据对象。
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
   
   // 定义@Builder函数的入参格式。
   interface RefreshAttribute {
     isRefreshing: boolean;
     // 属性设置通过Modifier优化性能
     modifier?: RefreshModifier;
     slot?: NodeContent;
     onRefreshing?: () => void;
     onOffsetChange?: (offset: number) => void;
   }
   
   // ComponentContent封装ArkTS组件依赖全局@Builder函数，涉及复杂自定义组件场景，可以在@Builder函数中嵌套@Component自定义组件。
   // @Builder函数提供入参方式，方便后续通过ComponentContent的update接口进行参数更新。
   @Builder
   function mixedRefresh(attribute: RefreshAttribute) {
     Refresh({ refreshing: attribute.isRefreshing }) {
       // Refresh作为容器组件，需要使用ContentSlot机制预留子组件占位
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
   
   // 定义创建函数的返回值，用于ArkTS侧和Native侧的交互。
   interface MixedModuleResult {
     // 定义针对Refresh构建函数的封装对象，用于Native侧转化为ArkUI_NodeHandle对象。
     content?: ComponentContent<RefreshAttribute>;
     // Refresh作为容器组件，需要使用ContentSlot机制挂载Native侧的子组件。
     childSlot?: NodeContent;
   }
   
   // 提供创建ArkTS组件的入口函数。
   export function createMixedRefresh(value: NativeRefreshAttribute): MixedModuleResult {
     console.info("createMixedRefresh");
     // 通过AppStorage对象在Ability启动的时候保持UI上下文对象。
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
     // 创建NodeContent插槽对象用于Refresh子组件挂载。
     let nodeSlot = new NodeContent();
     // 通过ComponentContent创建Refresh组件并将它封装起来。
     let content = new ComponentContent<RefreshAttribute>(uiContent!, wrapBuilder<[RefreshAttribute]>(mixedRefresh),
       {
         isRefreshing: value.isRefreshing,
         modifier: modifier,
         slot: nodeSlot,
         onRefreshing: value.onRefreshing,
         onOffsetChange: value.onOffsetChange
       });
     // 将Refresh组件的封装对象及其子组件插槽对象传递给Native侧。
     return { content: content, childSlot: nodeSlot };
   }
   
   // 定义Refresh组件的更新函数，用于Native侧更新。
   // 在更新场景下，需要将Refresh组件的封装对象及其子组件插槽对象返回，防止组件重新创建。
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
     // 调用ComponentContent的update接口进行更新。
     refresh.update({
       isRefreshing: value.isRefreshing,
       modifier: modifier,
       slot: childSlot,
       onRefreshing: value.onRefreshing,
       onOffsetChange: value.onOffsetChange
     })
   }
   
   ```

2. 将创建和更新函数注册给Native侧。
   ```ts
   // Index.ets
   import nativeNode from 'libentry.so';
   import { NodeContent } from '@kit.ArkUI';
   import { createMixedRefresh, updateMixedRefresh } from './MixedModule'
   
   @Entry
   @Component
   struct Index {
     private rootSlot = new NodeContent();
     @State @Watch('changeNativeFlag') showNative: boolean = false;
   
     aboutToAppear(): void {
       // 设置uiContext;
       AppStorage.setOrCreate<UIContext>("context", this.getUIContext());
       // 设置混合模式下的builder函数。
       nativeNode.registerCreateMixedRefreshNode(createMixedRefresh);
       nativeNode.registerUpdateMixedRefreshNode(updateMixedRefresh);
     }
   
     changeNativeFlag(): void {
       if (this.showNative) {
         // 创建NativeModule组件挂载
         nativeNode.createNativeRoot(this.rootSlot)
       } else {
         // 销毁NativeModule组件
         nativeNode.destroyNativeRoot()
       }
     }
   
     build() {
       Column() {
         Button(this.showNative ? "HideNativeUI" : "ShowNativeUI").onClick(() => {
           this.showNative = !this.showNative
         })
         Row() {
           // ArkTS插入Native组件。
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
           // 注册NDK根节点。 
           {"createNativeRoot", nullptr, NativeModule::CreateNativeRoot, nullptr, nullptr, nullptr, napi_default, nullptr},
           // 注册混合模式创建和更新方法。
           {"registerCreateMixedRefreshNode", nullptr, NativeModule::ArkUIMixedRefresh::RegisterCreateAndUpdateRefresh, nullptr,
            nullptr, nullptr, napi_default, nullptr},
           // 销毁NDK根节点。 
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

3. Native侧通过Node-API保存创建和更新函数，用于后续调用。
   ```c
   // ArkUIMixedRefresh.h
   // 混合模式交互类。
   
   #ifndef MYAPPLICATION_ARKUIMIXEDREFRESH_H
   #define MYAPPLICATION_ARKUIMIXEDREFRESH_H
   
   #include "ArkUIMixedNode.h"
   
   #include <optional>
   
   #include <arkui/native_node_napi.h>
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   class ArkUIMixedRefresh : public ArkUIMixedNode {
   public:
       static napi_value RegisterCreateAndUpdateRefresh(napi_env env, napi_callback_info info);
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUIMIXEDREFRESH_H
   ```

   ```cpp
   // ArkUIMixedRefresh.cpp
   // 混合模式交互类。
   
   #include "ArkUIMixedRefresh.h"
   
   namespace NativeModule {
   namespace {
   napi_env g_env;
   napi_ref g_createRefresh;
   napi_ref g_updateRefresh;
   } // namespace
   
   napi_value ArkUIMixedRefresh::RegisterCreateAndUpdateRefresh(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       g_env = env;
       napi_ref refer;
       // 创建引用之后保存，防止释放。
       napi_create_reference(env, args[0], 1, &refer);
   
       g_createRefresh = refer;
       return nullptr;
   }
   
   } // namespace NativeModule
   ```

   ```cpp
   // CMakeLists.txt
   // optional依赖C++17

   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.4.1)
   project(testndk)

   set(CMAKE_CXX_STANDARD 17)
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

   include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include)

   add_library(nativeNode SHARED container.cpp manager.cpp init.cpp)
   # target_link_libraries(entry PUBLIC libace_napi.z.so, libace_ndk.z.so, libhilog_ndk.z.so)

   find_library(
        # Sets the name of the path variable.
        hilog-lib
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        hilog_ndk.z
    )

   find_library(
        # Sets the name of the path variable.
        libace-lib
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        ace_ndk.z
    )

   find_library(
        # Sets the name of the path variable.
        libnapi-lib
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        ace_napi.z
    )

   target_link_libraries(nativeNode PUBLIC
        ${hilog-lib} ${libace-lib} ${libnapi-lib} )
   ```

4. 抽象混合模式下组件的基类，用于通用逻辑管理。
   ```c
   // ArkUIMixedNode.h
   // 混合模式基类。
   
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
   
       // 在基类析构的时候需要把混合模式在ArkTS侧的对象释放掉。
       ~ArkUIMixedNode() override { napi_delete_reference(env_, componentContent_); }
   
   protected:
       napi_env env_;
       napi_ref componentContent_;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUIMIXEDNODE_H
   ```

5. 实现Refresh组件的混合模式封装对象。
   ```c
   // ArkUIMixedRefresh.h
   // Refresh混合模式在Native侧的封装对象。
   
   #ifndef MYAPPLICATION_ARKUIMIXEDREFRESH_H
   #define MYAPPLICATION_ARKUIMIXEDREFRESH_H
   
   #include "ArkUIMixedNode.h"
   #include "ArkUIBaseNode.h"
   
   #include <optional>
   
   #include <arkui/native_node_napi.h>
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   // 定义Native侧和ArkTS侧的交互数据结构。
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
       // 调用ArkTS的方法创建Refresh组件。
       static const std::shared_ptr<ArkUIMixedRefresh> Create(const NativeRefreshAttribute &attribute);
   
       ArkUIMixedRefresh(ArkUI_NodeHandle handle, ArkUI_NodeContentHandle contentHandle, napi_env env,
                         napi_ref componentContent, napi_ref nodeContent)
           : ArkUIMixedNode(handle, env, componentContent), contentHandle_(contentHandle), nodeContent_(nodeContent) {}
   
       ArkUIMixedRefresh() : ArkUIMixedNode(nullptr, nullptr, nullptr) {}
   
       ~ArkUIMixedRefresh() override { napi_delete_reference(env_, nodeContent_); } // 释放子节点占位组件插槽对象。
   
       void SetWidth(float width) { attribute_.width = width; }
   
       void SetHeight(float height) { attribute_.height = height; }
   
       void SetBackgroundColor(uint32_t color) { attribute_.backgroundColor = color; }
   
       void SetRefreshState(bool isRefreshing) { attribute_.isRefreshing = isRefreshing; }
   
       void SetPullToRefresh(bool pullToRefresh) { attribute_.pullToRefresh = pullToRefresh; }
   
       void SetRefreshOffset(float offset) { attribute_.refreshOffset = offset; }
   
       void SetRefreshCallback(const std::function<void()> &callback) { attribute_.onRefreshing = callback; }
   
       void SetOnOffsetChange(const std::function<void(float)> &callback) { attribute_.onOffsetChange = callback; }
   
       // 避免频繁跨语言，在Native侧缓存属性事件，批量通知。
       void FlushMixedModeCmd();
   
       static napi_value RegisterCreateAndUpdateRefresh(napi_env env, napi_callback_info info);
   
   protected:
       void OnAddChild(const std::shared_ptr<ArkUIBaseNode> &child) override {
           assert(contentHandle_);
           // 使用NodeContent挂载组件（可以使用ArkTS在Native侧通过ComponentContent的转化对象，也可以是纯Native组件）到ArkTS组件下面。
           OH_ArkUI_NodeContent_AddNode(contentHandle_, child->GetHandle());
       }
   
       void OnRemoveChild(const std::shared_ptr<ArkUIBaseNode> &child) override {
           assert(contentHandle_);
           // 使用NodeContent卸载组件。
           OH_ArkUI_NodeContent_RemoveNode(contentHandle_, child->GetHandle());
       }
   
       void OnInsertChild(const std::shared_ptr<ArkUIBaseNode> &child, int32_t index) override {
           assert(contentHandle_);
           // 使用NodeContent插入组件。
           OH_ArkUI_NodeContent_InsertNode(contentHandle_, child->GetHandle(), index);
       }
   
   private:
       // 使用napi接口创建ArkTS侧的数据结构。
       static napi_value CreateRefreshAttribute(const NativeRefreshAttribute &attribute, void *userData);
   
       ArkUI_NodeContentHandle contentHandle_;
       napi_ref nodeContent_;
       NativeRefreshAttribute attribute_;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUIMIXEDREFRESH_H
   ```

   相关实现类说明：

   ```c
   // ArkUIMixedRefresh.cpp

   #include "ArkUIMixedRefresh.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   namespace {
   napi_env g_env;
   napi_ref g_createRefresh;
   napi_ref g_updateRefresh;
   } // namespace
   
   // 使用Napi接口创建与ArkTS侧交互的数据结构，用于Refresh组件的创建和更新。
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
   
   // 创建ArkTS侧的组件并保存在Native侧的封装对象中。
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
       // 调用ArkTS的Create函数创建ArkTS的ComponentContent。
       napi_call_function(g_env, nullptr, createRefresh, 1, argv, &result);
   
       // 获取ArkTS的Refresh组件。
       napi_value componentContent = nullptr;
       napi_get_named_property(g_env, result, "content", &componentContent);
       ArkUI_NodeHandle handle;
       OH_ArkUI_GetNodeHandleFromNapiValue(g_env, componentContent, &handle);
       assert(handle);
       // 获取ArkTS的Refresh组件的子组件插槽。
       napi_value nodeContent = nullptr;
       napi_get_named_property(g_env, result, "childSlot", &nodeContent);
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(g_env, nodeContent, &contentHandle);
       assert(contentHandle);
       // 保存ArkTS的ComponentContent用于防止ArkTS侧对象释放以及后续的更新。
       napi_ref componentContentRef;
       napi_create_reference(g_env, componentContent, 1, &componentContentRef);
       // 保存ArkTS的NodeContent用于防止ArkTS侧对象释放以及后续的更新。
       napi_ref nodeContentRef;
       napi_create_reference(g_env, nodeContent, 1, &nodeContentRef);
       // 更新Refresh组件相关参数。
       refresh->handle_ = handle;
       refresh->env_ = g_env;
       refresh->componentContent_ = componentContentRef;
       refresh->nodeContent_ = nodeContentRef;
       refresh->contentHandle_ = contentHandle;
       refresh->attribute_ = attribute;
       return refresh;
   }
   // 更新函数实现。
   void ArkUIMixedRefresh::FlushMixedModeCmd() {
       napi_handle_scope scope;
       napi_open_handle_scope(g_env, &scope);
       // 创建调用ArkTS接口入参。
       auto refreshAttribute = CreateRefreshAttribute(attribute_, this);
       if (refreshAttribute == nullptr) {
           napi_close_handle_scope(g_env, scope);
           return;
       }
       // 获取更新接口的剩余两个接口参数。
       napi_value componentContent = nullptr;
       napi_get_reference_value(g_env, componentContent_, &componentContent);
       napi_value nodeContent = nullptr;
       napi_get_reference_value(g_env, nodeContent_, &nodeContent);
   
       napi_value argv[3] = {componentContent, nodeContent, refreshAttribute};
       napi_value updateRefresh = nullptr;
       napi_get_reference_value(g_env, g_updateRefresh, &updateRefresh);
       // 调用ArkTS的Update函数进行更新。
       napi_value result = nullptr;
       napi_call_function(g_env, nullptr, updateRefresh, 3, argv, &result);
   }
   
   napi_value ArkUIMixedRefresh::RegisterCreateAndUpdateRefresh(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       g_env = env;
       napi_ref refer;
       napi_create_reference(env, args[0], 1, &refer);
   
       g_createRefresh = refer;
       return nullptr;
   }
   
   } // namespace NativeModule
   
   ```

6. 定时器模块相关简单实现。
   ```c
   // UITimer.h
   // 定时器模块。
   
   #ifndef MYAPPLICATION_UITIMER_H
   #define MYAPPLICATION_UITIMER_H
   
   #include <hilog/log.h>
   #include <js_native_api.h>
   #include <js_native_api_types.h>
   #include <node_api.h>
   #include <node_api_types.h>
   #include <string>
   #include <thread>
   #include <uv.h>
   
   namespace NativeModule {
   
   struct UIData {
       void *userData = nullptr;
       int32_t count = 0;
       int32_t totalCount = 0;
       void (*func)(void *userData, int32_t count) = nullptr;
   };
   
   napi_threadsafe_function threadSafeFunction = nullptr;
   
   void CreateNativeTimer(napi_env env, void *userData, int32_t totalCount, void (*func)(void *userData, int32_t count)) {
       napi_value name;
       std::string str = "UICallback";
       napi_create_string_utf8(env, str.c_str(), str.size(), &name);
       // UI主线程回调函数。
       napi_create_threadsafe_function(
           env, nullptr, nullptr, name, 0, 1, nullptr, nullptr, nullptr,
           [](napi_env env, napi_value value, void *context, void *data) {
               auto userdata = reinterpret_cast<UIData *>(data);
               userdata->func(userdata->userData, userdata->count);
               delete userdata;
           },
           &threadSafeFunction);
       // 启动定时器，模拟数据变化。
       std::thread timerThread([data = userData, totalCount, func]() {
           uv_loop_t *loop = uv_loop_new();
           uv_timer_t *timer = new uv_timer_t();
           uv_timer_init(loop, timer);
           timer->data = new UIData{data, 0, totalCount, func};
           uv_timer_start(
               timer,
               [](uv_timer_t *handle) {
                   OH_LOG_INFO(LOG_APP, "on timeout");
                   napi_acquire_threadsafe_function(threadSafeFunction);
                   auto *customData = reinterpret_cast<UIData *>(handle->data);
                   // 创建回调数据。
                   auto *callbackData =
                       new UIData{customData->userData, customData->count, customData->totalCount, customData->func};
                   napi_call_threadsafe_function(threadSafeFunction, callbackData, napi_tsfn_blocking);
                   customData->count++;
                   if (customData->count > customData->totalCount) {
                       uv_timer_stop(handle);
                       delete handle;
                       delete customData;
                   }
                   delete callbackData;
               },
               4000, 4000);
           uv_run(loop, UV_RUN_DEFAULT);
           uv_loop_delete(loop);
       });
       timerThread.detach();
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_UITIMER_H
   ```

7. 使用[接入ArkTS页面](ndk-access-the-arkts-page.md)章节的页面结构，并沿用[定时器模块相关简单实现](ndk-embed-arkts-components.md)，将Refresh组件作为文本列表的父组件。
   ```c
   // MixedRefreshExample.h
   // 混合模式示例代码。
   
   #ifndef MYAPPLICATION_MIXEDREFRESHEXAMPLE_H
   #define MYAPPLICATION_MIXEDREFRESHEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIMixedRefresh.h"
   #include "NormalTextListExample.h"
   #include "UITimer.h"
   
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateMixedRefreshList(napi_env env) {
       auto list = CreateTextListExample();
       // 混合模式创建Refresh组件并挂载List组件。
       NativeRefreshAttribute nativeRefreshAttribute{
           .backgroundColor = 0xFF89CFF0, .refreshOffset = 64, .pullToRefresh = true};
       auto refresh = ArkUIMixedRefresh::Create(nativeRefreshAttribute);
       refresh->AddChild(list);
   
       // 设置混合模式下的事件。
       refresh->SetOnOffsetChange(
           [](float offset) { OH_LOG_INFO(LOG_APP, "on refresh offset changed: %{public}f", offset); });
       refresh->SetRefreshCallback([refreshPtr = refresh.get(), env]() {
           OH_LOG_INFO(LOG_APP, "on refreshing");
           // 启动定时器，模拟数据获取。
           CreateNativeTimer(env, refreshPtr, 1, [](void *userData, int32_t count) {
               // 数据获取后关闭刷新。
               auto refresh = reinterpret_cast<ArkUIMixedRefresh *>(userData);
               refresh->SetRefreshState(false);
               refresh->FlushMixedModeCmd();
           });
       });
   
       // 更新事件到ArkTS侧。
       refresh->FlushMixedModeCmd();
       return refresh;
   }
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_MIXEDREFRESHEXAMPLE_H
   ```

   替换入口组件创建为下拉刷新文本列表。

   ```c
   // NativeEntry.cpp

   #include "NativeEntry.h"
   
   #include "ArkUIMixedRefresh.h"
   #include "MixedRefreshExample.h"
   #include "NormalTextListExample.h"
   
   #include <arkui/native_node_napi.h>
   #include <arkui/native_type.h>
   #include <js_native_api.h>
   #include <uv.h>
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       // 获取NodeContent
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // 创建Refresh文本列表
       auto refresh = CreateMixedRefreshList(env);
   
       // 保持Native侧对象到管理类中，维护生命周期。
       NativeEntry::GetInstance()->SetRootNode(refresh);
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // 从管理类中释放Native侧对象。
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   
   ```

