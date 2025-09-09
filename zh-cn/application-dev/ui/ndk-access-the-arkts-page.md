# 接入ArkTS页面
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

## 占位组件

使用NDK接口构建UI界面时，需要在ArkTS页面创建用于挂载NDK接口创建组件的占位组件。占位组件类型为[ContentSlot](../reference/apis-arkui/arkui-ts/ts-components-contentSlot.md)，ContentSlot能够绑定一个[NodeContent](../reference/apis-arkui/js-apis-arkui-NodeContent.md)对象，该对象可通过Node-API传递到Native侧挂载显示Native组件。

- NDK配置文件entry/src/main/cpp/types/libentry/oh-package.json5如下。
  ```ts
  {
    "name": "libentry.so",
    "types": "./index.d.ts",
    "version": "",
    "description": "Please describe the basic information."
  }
  ```

- 占位组件和其他ArkTS系统组件使用方法相同。详细代码请参考[示例](#示例)。
  ```ts
  import { NodeContent } from '@kit.ArkUI';
  import nativeNode from 'libentry.so';
  
  @Entry
  @Component
  struct Index {
    // 初始化NodeContent对象。
    private rootSlot = new NodeContent();
    @State @Watch('changeNativeFlag') showNative: boolean = false;
  
    changeNativeFlag(): void {
      if (this.showNative) {
        // 传递NodeContent对象用于Native创建组件的挂载显示
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
          // 将NodeContent和ContentSlot占位组件绑定。
          ContentSlot(this.rootSlot)
        }.layoutWeight(1)
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

- 占位组件可以通过相关接口在Native侧转化为挂载对象。
  ```
  ArkUI_NodeContentHandle contentHandle;
  OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
  ```

- 挂载对象提供了相关挂载和卸载组件接口。
  ```
  OH_ArkUI_NodeContent_AddNode(handle_, myNativeNode);
  OH_ArkUI_NodeContent_RemoveNode(handle_, myNativeNode);
  ```


## NDK组件模块

NDK提供的UI组件能力如组件创建、树操作、属性设置、事件注册等是通过函数指针结构体（如[ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md)）进行暴露，该函数指针结构体可以通过[模块查询接口](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface)获取。

> **说明：**
> - [模块查询接口](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface)带有初始化NDK的逻辑，建议先调用该接口进行全局初始化，再使用NDK进行UI构造。

```
ArkUI_NativeNodeAPI_1* arkUINativeNodeApi = nullptr;
OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, arkUINativeNodeApi);
```


在获取到函数指针结构体后，可以使用该结构体内的函数实现相关UI组件操作。


- 组件创建和销毁。
  ```
  auto listNode = arkUINativeNodeApi->createNode(ARKUI_NODE_LIST);
  arkUINativeNodeApi->disposeNode(listNode);
  ```

  获取NDK接口支持的组件范围可以通过查询[ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype)枚举值。

- 组件树操作。
  ```
  auto parent = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  auto child = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  arkUINativeNodeApi->addChild(parent, child);
  arkUINativeNodeApi->removeChild(parent, child);
  ```

- 属性设置。
  ```
  auto stack = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  ArkUI_NumberValue value[] = {{.f32 = 100}};
  ArkUI_AttributeItem item = {value, 1};
  arkUINativeNodeApi->setAttribute(stack, NODE_WIDTH, &item);
  ArkUI_NumberValue value_color[] = {{.u32 = 0xff112233}};
  ArkUI_AttributeItem item_color = {value_color, 1};
  arkUINativeNodeApi->setAttribute(stack, NODE_BACKGROUND_COLOR, &item);
  ```

  获取NDK接口支持的属性范围可以通过查询[ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)枚举值。

- 事件注册。
  ```
  auto stack = arkUINativeNodeApi->createNode(ARKUI_NODE_STACK);
  arkUINativeNodeApi->addNodeEventReceiver(stack, [](ArkUI_NodeEvent* event){
      // process event
  });
  arkUINativeNodeApi->registerNodeEvent(stack, NODE_ON_CLICK, 0, nullptr);
  ```

  获取NDK接口支持的事件范围可以通过查询[ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)枚举值。


## 示例

下面的示例展示了如何使用ContentSlot挂载Native侧的文本列表。

示例代码的目录结构及其文件说明如下：

```
.
|——cpp
|    |——types
|    |	  |——libentry
|    |	  |	   |——index.d.ts 提供Native和ArkTS侧的桥接方法。
|    |——napi_init.cpp 与index.d.ts对应的桥接方法对接Native侧的定义处。
|    |——NativeEntry.cpp 桥接方法的Native侧实现。
|    |——NativeEntry.h 桥接方法的Native侧定义。
|    |——CMakeList.txt C语言库引用文件。
|    |——ArkuiBaseNode.h 节点封装扩展类。
|    |——ArkuiNode.h 节点封装扩展类。
|    |——ArkuiListNode.h 节点封装扩展类。
|    |——ArkuiListItemNode.h 节点封装扩展类。
|    |——ArkuiTextNode.h 节点封装扩展类。
|    |——NormalTextListExample.h 示例代码文件。
| 
|——ets
|    |——pages
|         |——entry.ets 应用启动页，加载承载Native的容器。
|
```

**图1** Native文本列表

![text_list](figures/text_list.gif)

1. 在ArkTS页面上声明用于Native页面挂载的占位组件，并在页面创建时通知Native侧创建文本列表。
   ```ts
   import nativeNode from 'libentry.so';
   import { NodeContent } from '@kit.ArkUI';
   
   @Entry
   @Component
   struct Index {
     // 初始化NodeContent对象。
     private rootSlot = new NodeContent();
     @State @Watch('changeNativeFlag') showNative: boolean = false;
   
     changeNativeFlag(): void {
       if (this.showNative) {
         // 传递NodeContent对象用于Native创建组件的挂载显示
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
           // 将NodeContent和ContentSlot占位组件绑定。
           ContentSlot(this.rootSlot)
         }.layoutWeight(1)
       }
       .width('100%')
       .height('100%')
     }
   }
   ```

2. 使用Native模板创建工程，并在Native侧提供Node-API的桥接方法，实现ArkTS侧的NativeNode模块接口。
   接口声明。
   ```ts
   // entry/src/main/cpp/types/libentry/Index.d.ts
   
   export const createNativeRoot: (content: Object) => void;
   export const destroyNativeRoot: () => void;
   ```

   Native实现。
   ```cpp
   // entry/src/main/cpp/napi_init.cpp
   #include "napi/native_api.h"
   #include "NativeEntry.h"
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports) {
       // 绑定Native侧的创建组件和销毁组件。
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

3. 在NativeEntry.h文件中创建Native界面。
   ```c
   // NativeEntry.h
   
   #ifndef MYAPPLICATION_NATIVEENTRY_H
   #define MYAPPLICATION_NATIVEENTRY_H
   
   #include <ArkUIBaseNode.h>
   #include <arkui/native_type.h>
   #include <js_native_api_types.h>
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info);
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info);
   
   // 管理Native组件的生命周期和内存。
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
           // 添加Native组件到NodeContent上用于挂载显示。
           OH_ArkUI_NodeContent_AddNode(handle_, root_->GetHandle());
       }
       void DisposeRootNode() {
           // 从NodeContent上卸载组件并销毁Native组件。
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

   对应实现文件。
   ```cpp
   // NativeEntry.cpp
   
   #include <arkui/native_node_napi.h>
   #include <hilog/log.h>
   #include <js_native_api.h>
   #include "NativeEntry.h"
   #include "NormalTextListExample.h"
   
   namespace NativeModule {
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       // 获取NodeContent
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // 创建文本列表
       auto list = CreateTextListExample();
   
       // 保持Native侧对象到管理类中，维护生命周期。
       NativeEntry::GetInstance()->SetRootNode(list);
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // 从管理类中释放Native侧对象。
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   ```
   
   
   使用NDK 提供的C接口需要在CMakeLists.txt 中增加libace_ndk.z.so 的引用，如下所示，其中entry为工程导出的动态库名称，如当前示例使用的是默认的名称 libentry.so。
   新增cpp文件后，同样需要在CMakeLists.txt中添加对应cpp文件，如果未配置，对应文件将不会参与编译。
   
   ```
   add_library(entry SHARED napi_init.cpp NativeEntry.cpp)
   
   target_link_libraries(entry PUBLIC libace_napi.z.so libace_ndk.z.so)
   ```

4. 由于NDK接口提供的是C接口，为了使用面向对象的方式简化编程和工程管理，这里建议使用C++进行二次封装，下面示例代码展示了示例界面中所需的列表，文本组件封装类。
   
   1）获取ArkUI在NDK接口的入口模块[ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md)，该结构体模块提供了一系列组件创建、树构建、属性设置和事件注册等函数指针。
   
   ```c
   // NativeModule.h
   // 提供获取ArkUI在Native侧模块的封装接口
   
   #ifndef MYAPPLICATION_NATIVEMODULE_H
   #define MYAPPLICATION_NATIVEMODULE_H
   
   #include "napi/native_api.h"
   #include <arkui/native_node.h>
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
           // 获取NDK接口的函数指针结构体对象，用于后续操作。
           OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, arkUINativeNodeApi_);
           assert(arkUINativeNodeApi_);
       }
       // 暴露给其他模块使用。
       ArkUI_NativeNodeAPI_1 *GetNativeNodeAPI() { return arkUINativeNodeApi_; }
   
   private:
       ArkUI_NativeNodeAPI_1 *arkUINativeNodeApi_ = nullptr;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NATIVEMODULE_H
   ```
   
      2）提供列表，文本组件的基类对象，用于封装通用属性和事件。
   
   ```c
   // ArkUIBaseNode.h
   // 提供组件树操作的基类。
   
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
           // 封装析构函数，实现子节点移除功能。
           if (!children_.empty()) {
               for (const auto& child : children_) {
                   nativeModule_->removeChild(handle_, child->GetHandle());
               }
               children_.clear();
           }
           // 封装析构函数，统一回收节点资源。 
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
       // 针对父容器子类需要重载下面的函数，实现组件挂载和卸载。
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
   // 提供通用属性和事件的封装。
   
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
   
       // NDK相关通用属性调用封装
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
       // 组件树操作的实现类对接。
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
   
      3）实现列表组件。
   
   ```c
   // ArkUIListNode.h
   // 提供列表组件的封装。
   
   #ifndef MYAPPLICATION_ARKUILISTNODE_H
   #define MYAPPLICATION_ARKUILISTNODE_H
   
   #include "ArkUINode.h"
   
   namespace NativeModule {
   class ArkUIListNode : public ArkUINode {
   public:
       ArkUIListNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST)) {} // 创建ArkUI的列表组件。
   
       ~ArkUIListNode() override {} 
       // List组件的属性NDK接口封装。
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
   
      4）实现列表项组件。
   
   ```c
   // ArkUIListItemNode.h
   // 提供列表项的封装类。
   
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
   
      5）实现文本组件。
   
   ```c
   // ArkUITextNode.h
   // 实现文本组件的封装类。
   
   #ifndef MYAPPLICATION_ARKUITEXTNODE_H
   #define MYAPPLICATION_ARKUITEXTNODE_H
   
   #include "ArkUINode.h"
   
   #include <string>
   
   namespace NativeModule {
   class ArkUITextNode : public ArkUINode {
   public:
       ArkUITextNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_TEXT)) {}
       // 文本属性NDK接口封装。
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
   
5. 完善步骤3的CreateTextListExample函数，实现Native文本列表的创建和挂载显示。
   ```c
   // NormalTextListExample.h
   // 自定义NDK接口入口函数。
   
   #ifndef MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListItemNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateTextListExample() {
       // 创建组件并挂载
       // 1：使用智能指针创建List组件。
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1);
       list->SetPercentHeight(1);
       list->SetScrollBarState(true);
       // 2：创建ListItem子组件并挂载到List上。
       for (int32_t i = 0; i < 30; ++i) {
           auto listItem = std::make_shared<ArkUIListItemNode>();
           auto textNode = std::make_shared<ArkUITextNode>();
           textNode->SetTextContent(std::to_string(i));
           textNode->SetFontSize(16);
           textNode->SetFontColor(0xFFff00ff);
           textNode->SetPercentWidth(1);
           textNode->SetWidth(300);
           textNode->SetHeight(100);
           textNode->SetBackgroundColor(0xFFfffacd);
           textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
           listItem->InsertChild(textNode, i);
           list->AddChild(listItem);
       }
       return list;
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   ```