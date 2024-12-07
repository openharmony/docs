# ContentSlot：混合开发

用于渲染并管理Native层使用C-API创建的组件。

支持混合模式开发，当容器是ArkTS组件，子组件在Native侧创建时，推荐使用ContentSlot占位组件。

## 接口

### ContentSlot组件接口

```ts
ContentSlot(content: Content); // 当前开发者需要使用ArkUI提供的NodeContent作为管理器
```

| 参数名  | 类型 | 必填 | 参数描述                                                     |
| ------- | -------- | ---- | ------------------------------------------------------------ |
| content | Content  | 是   | Content作为ContentSlot的管理器，通过Native侧提供的接口，可以注册并触发ContentSlot的上下树事件回调以及管理ContentSlot的子组件。 |

```ts
abstract class Content {
}
```

### ContentSlotInterface

(content: Content): ContentSlotAttribute;

当内容添加到占位符组件时调用

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型 | 必填 | 参数描述                                                     |
| ------- | -------- | ---- | ------------------------------------------------------------ |
| content | Content  | 是   | Content作为ContentSlot的管理器，通过Native侧提供的接口，可以注册并触发ContentSlot的上下树事件回调以及管理ContentSlot的子组件。 |

### ContentSlotAttribute

定义ContentSlot属性，以防止不正确的递归使用ContentSlot

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### Native侧接口

| 接口名 | 描述 |
| -------- | -------- |
|OH_ArkUI_NodeContent_RegisterCallback(ArkUI_NodeContentHandle content, ArkUI_NodeContentCallback callback)|向管理器Content上注册事件。|
|OH_ArkUI_NodeContentEvent_GetEventType(ArkUI_NodeContentEvent* event)|获取Content上触发的事件类型。|
|OH_ArkUI_NodeContent_AddNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node)|在Content上添加子组件。|
|OH_ArkUI_NodeContent_InsertNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node, int32_t position)|在Content上插入子组件。|
|OH_ArkUI_NodeContent_RemoveNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node)|在Content上移除子组件。|
|OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)|在Native侧获取ArkTS侧Content指针。|
|OH_ArkUI_NodeContentEvent_GetNodeContentHandle(ArkUI_NodeContentEvent* event)|获取触发上下树事件的Content对象。|
|OH_ArkUI_NodeContent_SetUserData(ArkUI_NodeContentHandle content, void* userData)|在Content上设置用户自定义属性。|
|OH_ArkUI_NodeContent_GetUserData(ArkUI_NodeContentHandle content)|在Content上获取用户自定义属性。|
|typedef enum {<br>   NOTE_CONTENT_EVENT_ON_ATTACH_TO_WINDOW = 0,<br>   NOTE_CONTENT_EVENT_ON_DETACH_FROM_WINDOW = 1,<br>} ArkUI_NodeContentEventType|Content上会触发的上树和下树两种事件类型。|

## 开发实现

### ArkTS侧代码实现

```ts
import { nativeNode } from 'libNativeNode.so' // 开发者自己实现的so
import { NodeContent } from '@kit.ArkUI'

@Component
struct Parent {
    private nodeContent: Content = new NodeContent();

    aboutToAppear() {
        // 通过C-API创建节点，并添加到管理器nodeContent上
        nativeNode.createNativeNode(this.nodeContent);
    }

    build() {
        Column() {
            // 显示nodeContent管理器里存放的Native侧的组件
            ContentSlot(this.nodeContent)
        }
    }
}
```

### Native侧代码实现
Napi的基础开发知识请查看以下文档：[开发导读](../napi/ndk-development-overview.md)。

本章节仅描述实现ContentSlot相关逻辑代码。创建C侧组件，具体请查看[使用NDK接口构建UI](../ui/ndk-build-ui-overview.md)。

```c++
#include "napi/native_api.h"
#include "arkui/native_type.h"
#include "arkui/native_node.h"
#include "arkui/native_node_napi.h"
#include "arkui/native_interface.h"
#include "hilog/log.h"

ArkUI_NodeContentHandle nodeContentHandle_ = nullptr;
ArkUI_NativeNodeAPI_1 *nodeAPI;
const unsigned int LOG_PRINT_DOMAIN = 0xFF00;

// Manager为应用定义的NativeNode管理类
napi_value Manager::CreateNativeNode(napi_env env, napi_callback_info info) {
    // napi相关处理空指针&数据越界等问题
    if ((env == nullptr) || (info == nullptr)) {
        return nullptr;
    }

    size_t argc = 1;
    napi_value args[1] = { nullptr };
    if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "CreateNativeNode napi_get_cb_info failed");
    }

    if (argc != 1) {
        return nullptr;
    }

    nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNode_API_1"));

    // 将nodeContentHandle_指向ArkTS侧传入的nodeContent
    OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &nodeContentHandle_);

    if (nodeAPI != nullptr) {
        if (nodeAPI->createNode != nullptr && nodeAPI->addChild != nullptr) {
            ArkUI_NodeHandle component;
            // 创建C侧组件，具体请查看ArkUI api文档的Capi章节
            component = CreateNodeHandle();
            // 将组件添加到nodeContent管理器中
            OH_ArkUI_NodeContent_AddNode(nodeContentHandle_, component);
        }
    }
}
```

#### 注册上下树事件，并通过事件获取对应的Content对象

```c++
auto nodeContentEvent = [](ArkUI_NodeContentEvent *event) {
    ArkUI_NodeContentHandle content = OH_ArkUI_NodeContentEvent_GetNodeContentHandle(event);
    // 针对不同content需要额外做的逻辑
    if (OH_ArkUINodeContentEvent_GetEventType(event) = NODE_CONTENT_EVENT_ON_ATTACH_TO_WINDOW) {
        // ContentSlot上树时需要触发的逻辑
    } else if (OH_ArkUINodeContentEvent_GetEventType(event) = NODE_CONTENT_EVENT_ON_DETACH_FROM_WINDOW) {
        // ContentSlot下树时需要触发的逻辑
    };
};
// 将该事件注册到nodeContent上
OH_ArkUI_NodeContent_RegisterCallback(nodeContentHandle_, nodeContentEvent);
```

#### 添加子组件

```c++
ArkUINodeHandle component;
component = CreateNodeHandle();
// 将组件添加到nodeContent管理器中
OH_ArkUI_NodeContent_AddNode(nodeContentHandle_, component);
```

#### 插入子组件

```c++
ArkUINodeHandle component;
component = CreateNodeHandle();
// 将组件插入nodeContent管理器对应位置
OH_ArkUI_NodeContent_InsertNode(nodeContentHandle_, component, position);
```

#### 删除子组件

```c++
// 在nodeContent中移除对应组件
OH_ArkUI_NodeContent_RemoveNode(nodeContentHandle_, component);
```

#### 设置自定义属性

```c++
// 创建需要定义的自定义数据
void *userData = CreateUserData();
OH_ArkUI_NodeContent_SetUserData(nodeContentHandle_, userData);
```

#### 获取自定义属性

```
void *userData = OH_ArkUI_NodeContent_GetUserData(nodeContentHandle_);
```
