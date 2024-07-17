# Integrating with ArkTS Pages

## Placeholder Components

When constructing the UI interface using the NDK interface, it is necessary to create a placeholder component on the ArkTS page for mounting components created by the NDK interface. The placeholder component type is [ContentSlot](../reference/apis-arkui/arkui-ts/ts-components-contentSlot.md), which can bind to a NodeContent object. This object can be passed to the Native side via Node-API for mounting and displaying the Native component.

- The usage of the placeholder component is the same as other built-in ArkTS components.
  ```ts
  import { NodeContent } from '@ohos.arkui.node';
  
  @Entry
  @Component
  struct Index {
    // Initialize the NodeContent object.
    private rootSlot = new NodeContent();
    @State @Watch('changeNativeFlag') showNative: boolean = false;
  
    changeNativeFlag(): void {
      if (this.showNative) {
        // Pass the NodeContent object for mounting and displaying the Native-created component.
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
          // Bind the NodeContent and the ContentSlot placeholder component.
          ContentSlot(this.rootSlot)
        }.layoutWeight(1)
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

- The placeholder component can be converted into a mounting object on the Native side through related interfaces.
  ```c
  ArkUI_NodeContentHandle contentHandle;
  OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
  ```

- The mounting object provides interfaces for mounting and unmounting components.
  ```c
  OH_ArkUI_NodeContent_AddNode(handle_, myNativeNode);
  OH_ArkUI_NodeContent_RemoveNode(handle_, myNativeNode);
  ```

## NDK Component Module

The UI component capabilities provided by NDK, such as component creation, tree operations, attribute setting, and event registration, are exposed through a function pointer structure (e.g., [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md)), which can be obtained through the [module query interface](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_getmoduleinterface).

```
ArkUI_NativeNodeAPI_1* arkUINativeNodeApi = nullptr;
OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, arkUINativeNodeApi);
```

After obtaining the function pointer structure, you can use the functions within the structure to perform related UI component operations.

- Component creation and destruction.
  ```c
  auto listNode = arkUINativeNodeApi->createNode(ARKUI_NODE_LIST);
  arkUINativeNodeApi->disposeNode(listNode);
  ```

  To obtain the range of components supported by the NDK interface, you can query the [ArkUI_NodeType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodetype) enum values.

- Component tree operations.
  ```c
  auto parent = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  auto child = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  arkUINativeNodeApi->addChild(parent, child);
  arkUINativeNodeApi->removeChild(parent, child);
  ```

- Attribute setting.
  ```c
  auto stack = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  ArkUI_NumberValue value[] = {{.f32 = 100}};
  ArkUI_AttributeItem item = {value, 1};
  arkUINativeNodeApi->setAttribute(stack, NODE_WIDTH, &item);
  ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
  ArkUI_AttributeItem item = {value, 1};
  arkUINativeNodeApi->setAttribute(stack, NODE_BACKGROUND_COLOR, &item);
  ```

  To obtain the range of attributes supported by the NDK interface, you can query the [ArkUI_NodeAttributeType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype) enum values.

- Event registration.
  ```c
  auto stack = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  arkUINativeNodeApi->addNodeEventReceiver(stack, [](ArkUI_NodeEvent* event){
      // process event
  });
  arkUINativeNodeApi->registerNodeEvent(stack, NODE_ON_CLICK, 0, nullptr);
  ```

  To obtain the range of events supported by the NDK interface, you can query the [ArkUI_NodeEventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype) enum values.

## Example

The following example demonstrates how to use ContentSlot to mount a text list on the Native side.

**Figure 1** Native Text List

![text_list](figures/text_list.gif)

1. Declare a placeholder component for the Native page on the ArkTS page, and notify the Native side to create a text list when the page is created.
   ```ts
   import nativeNode from 'libentry.so';
   import { NodeContent } from '@ohos.arkui.node';
   
   @Entry
   @Component
   struct Index {
     // Initialize the NodeContent object.
     private rootSlot = new NodeContent();
     @State @Watch('changeNativeFlag') showNative: boolean = false;
   
     changeNativeFlag(): void {
       if (this.showNative) {
         // Pass the NodeContent object for mounting and displaying the Native-created component.
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
           // Bind the NodeContent and the ContentSlot placeholder component.
           ContentSlot(this.rootSlot)
         }.layoutWeight(1)
       }
       .width('100%')
       .height('100%')
     }
   }
   ```

2. Use the Native template to create a project, and provide a bridging method for the Node-API on the Native side to implement the NativeNode module interface on the ArkTS side.
   Interface declaration.
   ```ts
   // entry/src/main/cpp/types/libentry/Index.d.ts
   
   export const createNativeRoot: (content: Object) => void;
   export const destroyNativeRoot: () => void;
   ```

   Native implementation.
   ```cpp
   // entry/src/main/cpp/napi_init.cpp
   
   #include "NativeEntry.h"
   #include "napi/native_api.h"
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports) {
       // Bind the Native creation and destruction of components.
       napi_property_descriptor desc[] = {
           {"createNativeRoot", nullptr, NativeModule::CreateNativeRoot, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"destroyNativeRoot", nullptr, NativeModule::DestroyNativeRoot, nullptr, nullptr, nullptr, napi_default, nullptr}};
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

3. In the NativeEnrty.h file, create the Native interface.
   ```c
   // NativeEntry.h
   
   #ifndef MYAPPLICATION_NATIVEENTRY_H
   #define MYAPPLICATION_NATIVEENTRY_H
   
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info);
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info);
   
   // Manage the lifecycle and memory of Native components.
   class NativeEntry {
   public:
       static NativeEntry *GetInstance() {
           static NativeEntry nativeEntry;
           return &nativeEntry;
       }
   
       void SetContentHandle(ArkUI_NodeContentHandle handle) {
           handle_ = handle;
       }
   
       void SetRootNode(const std::shared_ptr<ArkUIBaseNode> &baseNode) {
           root_ = baseNode;
           // Add the Native component to the NodeContent for mounting and display.
           OH_ArkUI_NodeContent_AddNode(handle_, root_->GetHandle());
       }
       void DisposeRootNode() {
           // Unmount the component from NodeContent and destroy the Native component.
           OH_ArkUI_NodeContent_RemoveNode(handle_, root_->GetHandle());
           root_.reset();
       }
   
   private:
       std::shared_ptr<ArkUIBaseNode> root_;
       ArkUI_NodeContentHandle handle_;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NATIVEENTRY_H
   ```

   Below is the code snippet in an implementation file:
   ```cpp
   // NativeEntry.cpp
   #include "NativeEntry.h"
   
   #include <arkui/native_node_napi.h>
   #include <hilog/log.h>
   #include <js_native_api.h>
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       // Obtain the NodeContent handle.
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // Create a text list example.
       auto list = CreateTextListExample();
   
       // Maintain the lifecycle by keeping the Native side object in the management class.
       NativeEntry::GetInstance()->SetRootNode(list);
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // Release the Native side object from the management class.
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   ```

   When using the C interfaces provided by the NDK, you need to add references to libace_ndk.z.so in the CMakeLists.txt file. Below is an example of how to do this, where entry is the name of the dynamic library exported by the project. In this example, the default name libentry.so is used.
   ```
   target_link_libraries(entry PUBLIC libace_napi.z.so libace_ndk.z.so)
   ```

4. Since the NDK interface provides a C interface, to simplify programming and project management using an object-oriented approach, it is recommended to encapsulate it using C++. The following example code demonstrates the encapsulation classes required for the list and text components in the example interface.
    (1) Obtain the entry module of ArkUI in the NDK interface [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md). This structure module provides a series of function pointers for component creation, tree construction, attribute setting, and event registration.
   ```c
   // NativeModule.h
   // Provide an encapsulated interface for accessing the ArkUI module on the Native side.
   
   #ifndef MYAPPLICATION_NATIVEMODULE_H
   #define MYAPPLICATION_NATIVEMODULE_H
   
   #include <arkui/native_node.h>
   #include <functional>
   #include <cassert>
   
   #include <arkui/native_interface.h>
   
   namespace NativeModule {
   
   class NativeModuleInstance {
   public:
       static NativeModuleInstance *GetInstance() {
           static NativeModuleInstance instance;
           return &instance;
       }
   
       NativeModuleInstance() {
           // Provide an encapsulated interface for obtaining the ArkUI module on the Native side.
           OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, arkUINativeNodeApi_);
           assert(arkUINativeNodeApi_);
       }
       // Expose for use by other modules.
       ArkUI_NativeNodeAPI_1 *GetNativeNodeAPI() { return arkUINativeNodeApi_; }
   
   private:
       ArkUI_NativeNodeAPI_1 *arkUINativeNodeApi_ = nullptr;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NATIVEMODULE_H
   ```

   (2) Provide a base class object for list and text components, encapsulating common attributes and events.

   ```c
   // ArkUIBaseNode.h
   // Provide a base class object for component tree operations.
   
   #ifndef MYAPPLICATION_ARKUIBASENODE_H
   #define MYAPPLICATION_ARKUIBASENODE_H
   
   #include <arkui/native_type.h>
   #include <list>
   #include <memory>
   
   #include "NativeModule.h"
   
   namespace NativeModule {
   
   class ArkUIBaseNode {
   public:
       explicit ArkUIBaseNode(ArkUI_NodeHandle handle)
           : handle_(handle), nativeModule_(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()) {}
   
       virtual ~ArkUIBaseNode() {
           // Encapsulate the destructor to implement child node removal functionality.
           if (!children_.empty()) {
               for (const auto& child : children_) {
                   nativeModule_->removeChild(handle_, child->GetHandle());
               }
               children_.clear();
           }
           // Encapsulate the destructor to uniformly recover node resources.
           nativeModule_->disposeNode(handle_);
       }
   
       void AddChild(const std::shared_ptr<ArkUIBaseNode> &child) {
           children_.emplace_back(child);
           OnAddChild(child);
       }
   
       void RemoveChild(const std::shared_ptr<ArkUIBaseNode> &child) {
           children_.remove(child);
           OnRemoveChild(child);
       }
   
       void InsertChild(const std::shared_ptr<ArkUIBaseNode> &child, int32_t index) {
           if (index >= children_.size()) {
               AddChild(child);
           } else {
               auto iter = children_.begin();
               std::advance(iter, index);
               children_.insert(iter, child);
               OnInsertChild(child, index);
           }
       }
   
       ArkUI_NodeHandle GetHandle() const { return handle_; }
   
   protected:
       // Override these functions for parent container subclasses to implement component mounting and unmounting.
       virtual void OnAddChild(const std::shared_ptr<ArkUIBaseNode> &child) {}
       virtual void OnRemoveChild(const std::shared_ptr<ArkUIBaseNode> &child) {}
       virtual void OnInsertChild(const std::shared_ptr<ArkUIBaseNode> &child, int32_t index) {}
   
       ArkUI_NodeHandle handle_;
       ArkUI_NativeNodeAPI_1 *nativeModule_ = nullptr;
   
   private:
       std::list<std::shared_ptr<ArkUIBaseNode>> children_;
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUIBASENODE_H
   ```

   ```c
   // ArkUINode.h
   // Encapsulate common properties and events.
   
   #ifndef MYAPPLICATION_ARKUINODE_H
   #define MYAPPLICATION_ARKUINODE_H
   
   #include "ArkUIBaseNode.h"
   #include "NativeModule.h"
   #include <arkui/native_node.h>
   #include <arkui/native_type.h>
   
   namespace NativeModule {
   
   class ArkUINode : public ArkUIBaseNode {
   public:
       explicit ArkUINode(ArkUI_NodeHandle handle) : ArkUIBaseNode(handle) {}
   
       ~ArkUINode() override {}
   
       // Encapsulate the general property calls related to the NDK.
       void SetWidth(float width) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = width}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_WIDTH, &item);
       }
       void SetPercentWidth(float percent) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = percent}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_WIDTH_PERCENT, &item);
       }
       void SetHeight(float height) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = height}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_HEIGHT, &item);
       }
       void SetPercentHeight(float percent) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = percent}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_HEIGHT_PERCENT, &item);
       }
       void SetBackgroundColor(uint32_t color) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.u32 = color}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_BACKGROUND_COLOR, &item);
       }
   
   protected:
       // The implementation class is connected to the component tree operations.
       void OnAddChild(const std::shared_ptr<ArkUIBaseNode> &child) override {
           nativeModule_->addChild(handle_, child->GetHandle());
       }
       void OnRemoveChild(const std::shared_ptr<ArkUIBaseNode> &child) override {
           nativeModule_->removeChild(handle_, child->GetHandle());
       }
       void OnInsertChild(const std::shared_ptr<ArkUIBaseNode> &child, int32_t index) override {
           nativeModule_->insertChildAt(handle_, child->GetHandle(), index);
       }
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUINODE_H
   ```

3) Implement the list component.

   ```c
   // ArkUIListNode.h
   // Provide encapsulation for the list component.
   
   #ifndef MYAPPLICATION_ARKUILISTNODE_H
   #define MYAPPLICATION_ARKUILISTNODE_H
   
   #include "ArkUINode.h"
   
   namespace NativeModule {
   class ArkUIListNode : public ArkUINode {
   public:
       ArkUIListNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST)) {} // Create an ArkTS list component.
   
       ~ArkUIListNode() override {} 
       // Encapsulate the NDK interface for list component properties.
       void SetScrollBarState(bool isShow) {
           assert(handle_);
           ArkUI_ScrollBarDisplayMode displayMode =
               isShow ? ARKUI_SCROLL_BAR_DISPLAY_MODE_ON : ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF;
           ArkUI_NumberValue value[] = {{.i32 = displayMode}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_SCROLL_BAR_DISPLAY_MODE, &item);
       }
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUILISTNODE_H
   ```

(4) Implement the list item component.

   ```c
   // ArkUIListItemNode.h
   // Provide an encapsulation class for list items.
   
   #ifndef MYAPPLICATION_ARKUISTACKNODE_H
   #define MYAPPLICATION_ARKUISTACKNODE_H
   
   #include "ArkUINode.h"
   
   namespace NativeModule {
   class ArkUIListItemNode : public ArkUINode {
   public:
       ArkUIListItemNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST_ITEM)) {}
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUISTACKNODE_H
   ```

(5) Implement the text component.

   ```c
   // ArkUITextNode.h
   // Implement an encapsulation class for the text component.
   
   #ifndef MYAPPLICATION_ARKUITEXTNODE_H
   #define MYAPPLICATION_ARKUITEXTNODE_H
   
   #include "ArkUINode.h"
   
   #include <string>
   
   namespace NativeModule {
   class ArkUITextNode : public ArkUINode {
   public:
       ArkUITextNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_TEXT)) {}
       // Encapsulate the NDK interface for text properties.
       void SetFontSize(float fontSize) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = fontSize}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_FONT_SIZE, &item);
       }
       void SetFontColor(uint32_t color) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.u32 = color}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_FONT_COLOR, &item);
       }
       void SetTextContent(const std::string &content) {
           assert(handle_);
           ArkUI_AttributeItem item = {nullptr, 0, content.c_str()};
           nativeModule_->setAttribute(handle_, NODE_TEXT_CONTENT, &item);
       }
       void SetTextAlign(ArkUI_TextAlignment align) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.i32 = align}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_TEXT_ALIGN, &item);
       }
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUITEXTNODE_H
   ```

5. Complete the `CreateTextListExample` function from step 3 to implement the creation and mounting display of the Native text list.
   ```c
   // NativeEnrty.h
   // Custom NDK interface entry function.
   
   #ifndef MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListItemNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateTextListExample() {
       // Create and mount components
       // 1: Use a smart pointer to create a List component.
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1);
       list->SetPercentHeight(1);
       // 2: Create ListItem child components and mount them to the List.
       for (int32_t i = 0; i < 30; ++i) {
           auto listItem = std::make_shared<ArkUIListItemNode>();
           auto textNode = std::make_shared<ArkUITextNode>();
           textNode->SetTextContent(std::to_string(i));
           textNode->SetFontSize(16);
           textNode->SetPercentWidth(1);
           textNode->SetHeight(100);
           textNode->SetBackgroundColor(0xFFfffacd);
           textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
           listItem->AddChild(textNode);
           list->AddChild(listItem);
       }
       return list;
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   ```
