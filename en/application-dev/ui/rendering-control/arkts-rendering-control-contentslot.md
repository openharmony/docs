# ContentSlot: Enabling Hybrid Development

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sd-wu-->
<!--Designer: @sunbees-->
<!--Tester: @liuli0427-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=033859cddd4818ba4c62bad26b6ee850b2b31a63 translatedAt=2026-08-14T10:11:15.090Z pushedAt=2026-08-16T01:50:37.023Z -->

The **ContentSlot** component enables rendering and management of components created using C APIs on the native layer.

With support for development in [blend mode](../../graphics/complex-drawing-effect-c.md#blend-mode), **ContentSlot** serves the recommended placeholder component when the container is an ArkTS component with child components created on the native side.

> **NOTE**
>
> **ContentSlot** is supported since API version 12.
> 
> This topic serves as a development guide. For details about the component API specifications, see [ContentSlot](../../reference/apis-arkui/arkui-ts/ts-components-contentSlot.md).

## APIs

### ArkTS-side APIs

| Name | Description|
| ------- | -------- |
| ContentSlot(content: Content) | Container component for hybrid development. The **Content** object acts as the manager for **ContentSlot**, providing native-side APIs to register  attachment and detachment callbacks and manage child components.|

```ts
abstract class Content {
}
```

### Native-side APIs

| Name| Description|
| -------- | -------- |
|[OH_ArkUI_NodeContent_RegisterCallback(ArkUI_NodeContentHandle content, ArkUI_NodeContentCallback callback)](../../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodecontent_registercallback)|Registers an event with the **Content** manager.|
|[OH_ArkUI_NodeContentEvent_GetEventType(ArkUI_NodeContentEvent* event)](../../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodecontentevent_geteventtype)|Obtains the type of the event triggered on the **Content**.|
|[OH_ArkUI_NodeContent_AddNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node)](../../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodecontent_addnode)|Adds a child component to **Content**.|
|[OH_ArkUI_NodeContent_InsertNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node, int32_t position)](../../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodecontent_insertnode)|Inserts a child component into **Content**.|
|[OH_ArkUI_NodeContent_RemoveNode(ArkUI_NodeContentHandle content, ArkUI_NodeHandle node)](../../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodecontent_removenode)|Removes a child component from **Content**.|
|[OH_ArkUI_GetNodeContentFromNapiValue(napi_env env, napi_value value, ArkUI_NodeContentHandle* content)](../../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnodecontentfromnapivalue)|Obtains a **NodeContent** object on the ArkTS side and maps it to an **ArkUI_NodeContentHandle** object on the native side.|
|[OH_ArkUI_NodeContentEvent_GetNodeContentHandle(ArkUI_NodeContentEvent* event)](../../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodecontentevent_getnodecontenthandle)|Obtains the **Content** object that triggers the attach and detach events.|
|[OH_ArkUI_NodeContent_SetUserData(ArkUI_NodeContentHandle content, void* userData)](../../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodecontent_setuserdata)|Sets the custom attributes on **Content**.|
|[OH_ArkUI_NodeContent_GetUserData(ArkUI_NodeContentHandle content)](../../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodecontent_getuserdata)|Obtains the custom attributes from **Content**.|
|typedef enum {<br>   NODE_CONTENT_EVENT_ON_ATTACH_TO_WINDOW = 0,<br>   NODE_CONTENT_EVENT_ON_DETACH_FROM_WINDOW = 1,<br>} [ArkUI_NodeContentEventType](../../reference/apis-arkui/capi-native-node-h.md#arkui_nodecontenteventtype)|Enumerates the attach and detach event types on **Content**.|

## Development and Implementation

### ArkTS-side Implementation

<!-- @[contentslot_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import nativeNode from 'libentry.so'; // Developer-implemented .so file.
import { NodeContent } from '@kit.ArkUI';

@Entry
@Component
struct Parent {
  private nodeContent: Content = new NodeContent();
  // ...

  aboutToAppear() {
    // Create a node through the C API and add it to the nodeContent manager.
    nativeNode.createNativeNode(this.nodeContent);
    // ...
  }

  build() {
    Column() {
      // Display the native components stored in the nodeContent manager.
      ContentSlot(this.nodeContent);
      // ...
    }
  }
}
```

### Native-side Implementation

For details about the basic development knowledge of Node-API, see [Getting Started with the NDK](../../napi/ndk-development-overview.md).

This topic only describes how to implement the logic code related to **ContentSlot**. For details about how to create a component on the C side, see [NDK API Overview](../ndk-build-ui-overview.md).

<!-- @[contentslot_native](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/cpp/manager.cpp) -->

``` C++
#include "napi/native_api.h"
#include "arkui/native_type.h"
#include "arkui/native_node.h"
#include "arkui/native_node_napi.h"
#include "arkui/native_interface.h"
#include "hilog/log.h"
// ···
ArkUI_NodeContentHandle nodeContentHandle_ = nullptr;
ArkUI_NativeNodeAPI_1 *nodeAPI;
const unsigned int LOG_PRINT_DOMAIN = 0xFF00;

// Create a 480 vp x 480 vp Column component with a red (0xFFFF0000) background on the native side. For details about how to create a node tree, see ArkUI C API documentation.
ArkUI_NodeHandle NodeManager::CreateNodeHandle()
{
    ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
    ArkUI_NumberValue value[] = {480};
    ArkUI_AttributeItem item{value, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &item);
    nodeAPI->setAttribute(column, NODE_HEIGHT, &item);
    value[0].u32 = 0xFFFF0000;
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    return column;
}
    
// Native-side implementation of the ArkTS createNativeNode API.
napi_value NodeManager::CreateNativeNode(napi_env env, napi_callback_info info)
{
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
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));

    // Point nodeContentHandle_ to a nodeContent object passed in from ArkTS.
    OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &nodeContentHandle_);

    if (nodeAPI != nullptr) {
        if (nodeAPI->createNode != nullptr && nodeAPI->addChild != nullptr) {
            ArkUI_NodeHandle component;
            // Create a native-side component.
            component = CreateNodeHandle();
            // Add the component to the nodeContent manager.
            OH_ArkUI_NodeContent_AddNode(nodeContentHandle_, component);
            // ···
        }
    }
    return nullptr;
}
```

### Native-side API Usage

- **Registering Attach and Detach Events and Obtaining the Corresponding Content Object**

  <!-- @[contentslot_register_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/cpp/manager.cpp) -->

  ``` C++
  auto nodeContentEvent = [](ArkUI_NodeContentEvent *event) {
      ArkUI_NodeContentHandle content = OH_ArkUI_NodeContentEvent_GetNodeContentHandle(event);
      // Additional logic required for different contents.
      if (OH_ArkUI_NodeContentEvent_GetEventType(event) == NODE_CONTENT_EVENT_ON_ATTACH_TO_WINDOW) {
          // Logic to be triggered when an attach event occurs on ContentSlot.
          // ···
      } else if (OH_ArkUI_NodeContentEvent_GetEventType(event) == NODE_CONTENT_EVENT_ON_DETACH_FROM_WINDOW) {
          // Logic to be triggered when a detach event occurs on ContentSlot.
          // ···
      }
  };
  // Register an event with nodeContent.
  OH_ArkUI_NodeContent_RegisterCallback(nodeContentHandle_, nodeContentEvent);
  ```

- **Adding Child Components**

  <!-- @[contentslot_add](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/cpp/manager.cpp) -->

  ``` C++
  ArkUI_NodeHandle component;
  // Create a native-side component.
  component = CreateNodeHandle();
  // Add the component to the nodeContent manager.
  OH_ArkUI_NodeContent_AddNode(nodeContentHandle_, component);
  ```

- **Inserting Child Components**

  <!-- @[contentslot_insert](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/cpp/manager.cpp) -->

  ``` C++
  int32_t position = 0;
  ArkUI_NodeHandle component1 = CreateNodeHandle();
  // Insert a component into the specified position of the nodeContent manager.
  OH_ArkUI_NodeContent_InsertNode(nodeContentHandle_, component1, position);
  ```

- **Removing Child Components**

  <!-- @[contentslot_remove](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/cpp/manager.cpp) -->

  ``` C++
  // Remove a component from the nodeContent manager.
  OH_ArkUI_NodeContent_RemoveNode(nodeContentHandle_, component1);
  ```

- **Setting Custom Attributes**

  <!-- @[contentslot_set_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/cpp/manager.cpp) -->

  ``` C++
  // Create the custom data to be defined.
  void *userData = CreateUserData();
  OH_ArkUI_NodeContent_SetUserData(nodeContentHandle_, userData);
  ```

- **Obtaining Custom Attributes**

  <!-- @[contentslot_get_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/cpp/manager.cpp) -->

  ``` C++
  void *userData = OH_ArkUI_NodeContent_GetUserData(nodeContentHandle_);
  ```

## Binding Rules

A **Content** object can only be bound to one **ContentSlot** component at a time. If the same **Content** object is bound to multiple **ContentSlot** components, only the last binding takes effect and displays the content.

**Reason**

**Content** and **ContentSlot** nodes maintain a strict one-to-one binding relationship. A **Content** node cannot be simultaneously associated with multiple **ContentSlot** nodes. When attempts are made to bind the same **Content** node to multiple **ContentSlot** nodes, only the final binding remains active. Previous **ContentSlot** nodes lose their association with the **Content** node, resulting in missing component content.

To display the same content in multiple **ContentSlot** nodes, create separate **Content** node instances for each slot. The following is an example:

<!-- @[contentslot_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/RenderingControlContentslotNDK/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import nativeNode from 'libentry.so'; // Developer-implemented .so file.
import { NodeContent } from '@kit.ArkUI';

@Entry
@Component
struct Parent {
  // ...
  private nodeContent_1: Content = new NodeContent();
  private nodeContent_2: Content = new NodeContent();

  aboutToAppear() {
    // ...
    // Create a node through the C API and add it to nodeContent_1 and nodeContent_2.
    nativeNode.createNativeNode(this.nodeContent_1);
    nativeNode.createNativeNode(this.nodeContent_2);
  }

  build() {
    Column() {
      // ...
      ContentSlot(this.nodeContent_1);// nodeContent_1 will be mounted to the next ContentSlot node and cannot be displayed here.
      ContentSlot(this.nodeContent_1); // Content is displayed properly.
      ContentSlot(this.nodeContent_2); // Content is displayed properly.
    }
  }
}
```