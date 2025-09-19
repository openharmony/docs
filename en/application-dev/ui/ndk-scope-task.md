# Ensuring Multi-Instance Functionality in the NDK
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

Since API version 20, the ArkUI framework provides the [OH_ArkUI_RunTaskInScope](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_runtaskinscope) API to address component operations in multi-instance scenarios on the native side. This API dynamically switches the execution context to ensure the validity of component attribute settings across instances and prevents API call exceptions caused by instance context mismatches.

In NDK multi-window development, you may need to set attributes across instances. This capability ensures context correctness during cross-instance attribute assignment, preventing API call failures due to instance boundaries.

> **NOTE**
>
> - This API is designed for interaction between different UI instances in NDK multi-window development. For example, it allows modifying attributes of components created in Page A from Page B, including components not currently mounted in the UI tree.
>
> - The userData parameter can be used to pass a custom data structure (such as a component pointer or service parameter) to precisely identify the target component within the callback task.
>
> - This function should be used in conjunction with APIs like [OH_ArkUI_NodeUtils_GetAttachedNodeHandleById](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_getattachednodehandlebyid) to prevent null pointer or permission exceptions caused by cross-instance access.

The following example demonstrates the basic usage of OH_ArkUI_RunTaskInScope. It uses OH_ArkUI_NodeUtils_GetAttachedNodeHandleById to retrieve a component from a previous page. For details, see [OH_ArkUI_NodeUtils_GetAttachedNodeHandleById](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_getattachednodehandlebyid). The userData parameter passes a pointer to the target component, which is used to set the corresponding attributes.

```c
//page1
ArkUI_NodeHandle button = nodeAPI->createNode(ARKUI_NODE_BUTTON);
ArkUI_AttributeItem LABEL_Item = {.string = "pageOneButton"};
// Set an ID to allow component retrieval from the second page.
ArkUI_AttributeItem id = {.string = "pageOneButton"};
nodeAPI->setAttribute(button, NODE_ID, &id);
nodeAPI->setAttribute(button, NODE_BUTTON_LABEL, &LABEL_Item);
```

```c
//page2
// Retrieve the component created on the previous page using its ID.
ArkUI_NodeHandle pageOneButton = nullptr;
auto ec = OH_ArkUI_NodeUtils_GetAttachedNodeHandleById("pageOneButton", &pageOneButton);
auto uiContext = OH_ArkUI_GetContextByNode(pageOneButton);
OH_ArkUI_RunTaskInScope(uiContext, pageOneButton, [](void *userData) {
        auto *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
            OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
        auto pageOneButton = (ArkUI_NodeHandle)userData;
        ArkUI_NumberValue value[] = {480};
        ArkUI_AttributeItem LABEL_Item = {.string = "success"};
        value[0].f32 = 250;
        ArkUI_AttributeItem button_Item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
        nodeAPI->setAttribute(pageOneButton, NODE_BUTTON_LABEL, &LABEL_Item);
        nodeAPI->setAttribute(pageOneButton, NODE_WIDTH, &button_Item);
    }
);
```