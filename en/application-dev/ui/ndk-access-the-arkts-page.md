# Integrating with ArkTS Pages


## Placeholder Components

When building a UI with NDK APIs, you need to create placeholder components in the ArkTS page for mounting components created by the NDK APIs. The placeholder component type is [ContentSlot](../reference/apis-arkui/arkui-ts/ts-components-contentSlot.md), which can bind a [NodeContent](../reference/apis-arkui/js-apis-arkui-NodeContent.md) object. This object can be passed to the native side through the Node-API for mounting and displaying native components.

- The usage of placeholder components is the same as other built-in ArkTS components.
  ```ts
  import { NodeContent } from '@kit.ArkUI';
  
  @Entry
  @Component
  struct Index {
    // Initialize the NodeContent object.
    private rootSlot = new NodeContent();
    @State @Watch('changeNativeFlag') showNative: boolean = false;
  
    changeNativeFlag(): void {
      if (this.showNative) {
        // Pass the NodeContent object for the native side to create component mounting and display.
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
          // Bind the NodeContent and ContentSlot placeholder component.
          ContentSlot(this.rootSlot)
        }.layoutWeight(1)
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

- The placeholder component can be transformed into a mounting object on the native side through related APIs.
  ```
  ArkUI_NodeContentHandle contentHandle;
  OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
  ```

- The mounting object provides APIs for mounting and unmounting components.
  ```
  OH_ArkUI_NodeContent_AddNode(handle_, myNativeNode);
  OH_ArkUI_NodeContent_RemoveNode(handle_, myNativeNode);
  ```


## NDK Component Module

The UI component capabilities provided by the NDK, including component creation, tree operations, attribute setting, and event registration, are exposed using the function pointer structs (such as [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md)), which can be obtained through the [module query API](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_getmoduleinterface).

```
ArkUI_NativeNodeAPI_1* arkUINativeNodeApi = nullptr;
OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, arkUINativeNodeApi);
```


After obtaining a function pointer struct, use the functions within the struct to perform UI component operations.


- Create and destroy components.
  ```
  auto listNode = arkUINativeNodeApi->createNode(ARKUI_NODE_LIST);
  arkUINativeNodeApi->disposeNode(listNode);
  ```

  You can query the range of components supported by the NDK API through the [ArkUI_NodeType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodetype) API.

- Perform component tree operations.
  ```
  auto parent = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  auto child = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  arkUINativeNodeApi->addChild(parent, child);
  arkUINativeNodeApi->removeChild(parent, child);
  ```

- Set attributes.
  ```
  auto stack = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  ArkUI_NumberValue value[] = {{.f32 = 100}};
  ArkUI_AttributeItem item = {value, 1};
  arkUINativeNodeApi->setAttribute(stack, NODE_WIDTH, &item);
  ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
  ArkUI_AttributeItem item = {value, 1};
  arkUINativeNodeApi->setAttribute(stack, NODE_BACKGROUND_COLOR, &item);
  ```

  You can query the range of attributes supported by the NDK API through the[ArkUI_NodeAttributeType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype) API.

- Register events.
  ```
  auto stack = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  arkUINativeNodeApi->addNodeEventReceiver(stack, [](ArkUI_NodeEvent* event){
      // process event
  });
  arkUINativeNodeApi->registerNodeEvent(stack, NODE_ON_CLICK, 0, nullptr);
  ```

  You can query the range of events supported by the NDK API through the [ArkUI_NodeEventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype) API.


## Example

The following example demonstrates how to use **ContentSlot** to mount a native text list.

**Figure 1** Native text list 

![text_list](figures/text_list.gif)

1. Declare a placeholder component for native page mounting on the ArkTS page, and notify the native side to create a text list when the page is created.
   ```ts
   import nativeNode from 'libentry.so';
   import { NodeContent } from '@kit.ArkUI';
   
   @Entry
   @Component
   struct Index {
     // Initialize the NodeContent object.
     private rootSlot = new NodeContent();
     @State @Watch('changeNativeFlag') showNative: boolean = false;
   
     changeNativeFlag(): void {
       if (this.showNative) {
         // Pass the NodeContent object for the native side to create component mounting and display.
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
           // Bind the NodeContent and ContentSlot placeholder component.
           ContentSlot(this.rootSlot)
         }.layoutWeight(1)
       }
       .width('100%')
       .height('100%')
     }
   }
   ```

2. Use the **Native** template to create a project, and provide a bridging method for the Node-API on the native side, implementing the **NativeNode** module APIs on the ArkTS side.
   API declaration:
   ```ts
   // entry/src/main/cpp/types/libentry/Index.d.ts
   
   export const createNativeRoot: (content: Object) => void;
   export const destroyNativeRoot: () => void;
   ```

   Native implementation:
   ```cpp
   // entry/src/main/cpp/napi_init.cpp
   #include "napi/native_api.h"
   #include "NativeEntry.h"
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports) {
       // Bind the native creation and destruction of components.
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

3. Create the native page in the **NativeEntry.h** file.
   ```c
   // NativeEntry.h
   
   #ifndef MYAPPLICATION_NATIVEENTRY_H
   #define MYAPPLICATION_NATIVEENTRY_H
   
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info);
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info);
   
   // Manage the lifecycle and memory of the native component.
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
           // Add the native component to NodeContent for mounting and display.
           OH_ArkUI_NodeContent_AddNode(handle_, root_->GetHandle());
       }
       void DisposeRootNode() {
           // Unmount the component from NodeContent and destroy the native component.
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

   Corresponding implementation file:
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
   
       // Obtain NodeContent.
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // Create a text list.
       auto list = CreateTextListExample();
   
       // Keep the native side object in the management class to maintain its lifecycle.
       NativeEntry::GetInstance()->SetRootNode(list);
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // Release the native side object from the management class.
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   ```

   When using the C APIs provided by the NDK, you need to add a reference to **libace_ndk.z.so** in the **CMakeLists.txt** file, as shown below. Here, **entry** is the name of the dynamic library exported by the project, such as the default name **libentry.so** used in this example.
   ```
   target_link_libraries(entry PUBLIC libace_napi.z.so libace_ndk.z.so)
   ```

4. Since the NDK provides C APIs, to simplify programming and project management in an object-oriented manner, it is recommended that you use C++ for secondary encapsulation. The following example shows the encapsulation classes required for the list and text components on the example page.
   (1) Obtain the entry module of ArkUI in the NDK API [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md), which provides a series of function pointers for component creation, tree construction, attribute setting, and event registration.
   ```c
   // NativeModule.h
   // Provide encapsulated APIs for obtaining ArkUI modules on the native side.
   
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
           // Obtain the function pointer struct of the NDK API for subsequent operations.
           OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, arkUINativeNodeApi_);
           assert(arkUINativeNodeApi_);
       }
       // Expose it for use by other modules.
       ArkUI_NativeNodeAPI_1 *GetNativeNodeAPI() { return arkUINativeNodeApi_; }
   
   private:
       ArkUI_NativeNodeAPI_1 *arkUINativeNodeApi_ = nullptr;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NATIVEMODULE_H
   ```

   (2) Provide base class objects for list and text components to encapsulate common properties and events.

   ```c
   // ArkUIBaseNode.h
   // Provide a base class for component tree operations.
   
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
       // Override the following functions in subclasses that act as parent containers to implement component mounting and unmounting.
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
   // Provide encapsulation of common properties and events.
   
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
   
       // Encapsulate the common property call related to the NDK.
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
       // Implement class docking for component tree operations.
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

   (3) Implement the list component.

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
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST)) {} // Create the ArkUI list component.
   
       ~ArkUIListNode() override {} 
       // List component's NDK API encapsulation for properties.
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
   // Provide an encapsulation class for list items
   
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
       // Text component's NDK API encapsulation for properties.
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

5. Complete the **CreateTextListExample** function from step 3 to create and mount the display of the native text list.
   ```c
   // NormalTextListExample.h
   // Define custom NDK API entry functions.
   
   #ifndef MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListItemNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateTextListExample() {
       // Create components and mount them.
       // 1: Use smart pointers to create a List component.
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1);
       list->SetPercentHeight(1);
       // 2: Create a ListItem child component and mount it to the List component.
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
