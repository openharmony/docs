# ContentSlot: Representing a Placeholder in Hybrid Development

The **ContentSlot** component is a component designed to render and manage components created on the native layer using C APIs.

With support for hybrid development, the **ContentSlot** component is recommended when the container is an ArkTS component and the child component is created on the native side.

## APIs

### ArkTS APIs

| Name | Description|
| ------- | -------- |
| ContentSlot(content: Content) | Manager of the **ContentSlot** component. Through the APIs provided by the native side, it can register and trigger the attach and detach event callbacks for **ContentSlot**, as well as manage the child components of **ContentSlot**.|

```ts
abstract class Content {
}
```

### Native APIs

| Name| Description|
| -------- | -------- |
|OH_ArkUI_NodeContent_RegisterCallback(ArkUI_NodeContentHandle content, ArkUI_NodeContentCallback callback)|Registers an event with the **Content** manager.|
|OH_ArkUI_NodeContentEvent_GetEventType(ArkUI_NodeContentEvent* event)|Obtains the type of the event triggered on the **Content**.|
|OH_ArkUI_NodeContent_AddNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node)|Adds a child component to **Content**.|
|OH_ArkUI_NodeContent_InsertNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node, int32_t position)|Inserts a child component into **Content**.|
|OH_ArkUI_NodeContent_RemoveNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node)|Removes a child component from **Content**.|
|OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)|Obtains the pointer to **Content** in ArkTS from the native side.|
|OH_ArkUI_NodeContentEvent_GetNodeContentHandle(ArkUI_NodeContentEvent* event)|Obtains the **Content** object that triggers the attach and detach events.|
|OH_ArkUI_NodeContent_SetUserData(ArkUI_NodeContentHandle content, void* userData)|Sets the custom attributes on **Content**.|
|OH_ArkUI_NodeContent_GetUserData(ArkUI_NodeContentHandle content)|Obtains the custom attributes from **Content**.|
|typedef enum {<br>   NOTE_CONTENT_EVENT_ON_ATTACH_TO_WINDOW = 0,<br>   NOTE_CONTENT_EVENT_ON_DETACH_FROM_WINDOW = 1,<br>} ArkUI_NodeContentEventType|Enumerates the event types on **Content**.|

## Development and Implementation

### Code Implementation in ArkTS

```ts
import { nativeNode } from'libNativeNode.so' // The so. file implemented by you.
import { NodeContent } from '@kit.ArkUI'

@Entry
@Component
struct Parent {
    private nodeContent: Content = new NodeContent();

    aboutToAppear() {
        // Create a node through the C API and add it to the nodeContent manager.
        nativeNode.createNativeNode(this.nodeContent);
    }

    build() {
        Column() {
            // Display the native components stored in the nodeContent manager.
            ContentSlot(this.nodeContent)
        }
    }
}
```

### Code Implementation in C
For details about the basic development knowledge of Node-API, see [Getting Started with the NDK](../../napi/ndk-development-overview.md).

This topic only describes how to implement the logic code related to **ContentSlot**. Create a component on the C side. For details, see [NDK API Overview](../../ui/ndk-build-ui-overview.md).

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

// NativeNode management class defined by Manager for applications.
napi_value Manager::CreateNativeNode(napi_env env, napi_callback_info info) {
    // Solve null pointer and out-of-bounds issues related to Node-API.
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

    // Point nodeContentHandle_ to a nodeContent object passed in from ArkTS.
    OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &nodeContentHandle_);

    if (nodeAPI != nullptr) {
        if (nodeAPI->createNode != nullptr && nodeAPI->addChild != nullptr) {
            ArkUI_NodeHandle component;
            // Create components in C.
            component = CreateNodeHandle();
            // Add the component to the nodeContent manager.
            OH_ArkUI_NodeContent_AddNode(nodeContentHandle_, component);
        }
    }
}
```

#### Registering Attach and Detach Events and Obtaining Corresponding Content Object

```c++
auto nodeContentEvent = [](ArkUI_NodeContentEvent *event) {
    ArkUI_NodeContentHandle content = OH_ArkUI_NodeContentEvent_GetNodeContentHandle(event);
    // Additional logic required for different contents.
    if (OH_ArkUINodeContentEvent_GetEventType(event) = NODE_CONTENT_EVENT_ON_ATTACH_TO_WINDOW) {
        // Logic to be triggered when an attach event occurs on ContentSlot.
    } else if (OH_ArkUINodeContentEvent_GetEventType(event) = NODE_CONTENT_EVENT_ON_DETACH_FROM_WINDOW) {
        // Logic to be triggered when a detach event occurs on ContentSlot.
    };
};
// Register an event with nodeContent.
OH_ArkUI_NodeContent_RegisterCallback(nodeContentHandle_, nodeContentEvent);
```

#### Adding Child Components

```c++
ArkUINodeHandle component;
component = CreateNodeHandle();
// Add the component to the nodeContent manager.
OH_ArkUI_NodeContent_AddNode(nodeContentHandle_, component);
```

#### Inserting Child Components

```c++
ArkUINodeHandle component;
component = CreateNodeHandle();
// Insert a component into the specified position of the nodeContent manager.
OH_ArkUI_NodeContent_InsertNode(nodeContentHandle_, component, position);
```

#### Removing Child Components

```c++
// Remove a component from the nodeContent manager.
OH_ArkUI_NodeContent_RemoveNode(nodeContentHandle_, component);
```

#### Setting Custom Attributes

```c++
// Create the custom data to be defined.
void *userData = CreateUserData();
OH_ArkUI_NodeContent_SetUserData(nodeContentHandle_, userData);
```

#### Obtaining Custom Attributes

```
void *userData = OH_ArkUI_NodeContent_GetUserData(nodeContentHandle_);
```
