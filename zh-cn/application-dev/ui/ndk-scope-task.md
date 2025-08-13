# 在NDK中保证多实例场景功能正常

从API version 20开始，ArkUI开发框架提供了Native侧嵌入跨实例相关能力[OH_ArkUI_RunTaskInScope](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_runtaskinscope)。

在NDK多窗口开发时，可能会涉及到组件的跨实例设置属性等场景，使用该能力可确保在调用跨实例组件设置属性时的上下文正确性，避免跨实例接口调用失败。

> **说明：**
> - 使用[OH_ArkUI_RunTaskInScope](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_runtaskinscope)接口在B页面设置A页面内的组件，或由A页面创建但未上树的组件的属性或逻辑，保证回调范围内执行的逻辑实例正确性。
>
> - [OH_ArkUI_RunTaskInScope](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_runtaskinscope)的userData入参为自定义属性类型，开发者可根据业务实际需要，传入任意类型的数据或结构体。


本示例展示OH_ArkUI_RunTaskInScope接口的基础使用方式，OH_ArkUI_NodeUtils_GetAttachedNodeHandleById用于获取前置实例页面内的组件，相关使用请参考[OH_ArkUI_NodeUtils_GetAttachedNodeHandleById](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_getattachednodehandlebyid)，此处userData传入的数据类型为最终要设置的组件指针，便于设置对应组件属性。


```c
//page1
ArkUI_NodeHandle button = nodeAPI->createNode(ARKUI_NODE_BUTTON);
ArkUI_AttributeItem LABEL_Item = {.string = "pageOneButton"};
//设置id，用于在第二个页面内通过接口查找
ArkUI_AttributeItem id = {.string = "pageOneButton"};
nodeAPI->setAttribute(button, NODE_ID, &id);
nodeAPI->setAttribute(button, NODE_BUTTON_LABEL, &LABEL_Item);
```

```c
//page2
//pageOneButton由前置页面创建，通过OH_ArkUI_NodeUtils_GetAttachedNodeHandleById在第二个页面获取。
ArkUI_NodeHandle pageOneButton = nullptr;
auto ec = OH_ArkUI_NodeUtils_GetAttachedNodeHandleById("pageOneButton", &pageOneButton);
auto uiContext = OH_ArkUI_GetContextByNode(pageOneButton);
OH_ArkUI_RunTaskInScope(uiContext, pageOneButton, [](void *userData) {
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