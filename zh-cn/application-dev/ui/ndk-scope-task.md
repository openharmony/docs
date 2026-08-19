# NDK多实例场景开发
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

API version 20开始，ArkUI开发框架新增了[OH_ArkUI_RunTaskInScope](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_runtaskinscope)接口，解决Native侧多实例场景下的组件操作问题。该功能通过动态切换执行上下文，确保跨实例组件属性设置的合法性，避免实例上下文不匹配导致的接口调用异常。

在NDK多窗口开发时，可能会涉及到组件的跨实例设置属性等场景，使用该能力可确保在调用跨实例组件设置属性时的上下文正确性，避免跨实例接口调用失败。

> **说明：**
> - 适用于NDK多窗口开发中不同UI实例间的交互场景，例如在页面B中修改页面A创建的组件属性或未挂载到UI树的组件逻辑。
>
> - 支持通过userData参数传递自定义数据结构（如组件指针、业务参数等），便于在回调任务中精准定位目标组件。
>
> - 与[OH_ArkUI_NodeUtils_GetAttachedNodeHandleById](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_getattachednodehandlebyid)等接口配合使用，有效规避跨实例访问导致的空指针或权限异常问题。


本示例展示OH_ArkUI_RunTaskInScope接口的基础使用方式，OH_ArkUI_NodeUtils_GetAttachedNodeHandleById用于获取前置实例页面内的组件，相关使用请参考[OH_ArkUI_NodeUtils_GetAttachedNodeHandleById](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_getattachednodehandlebyid)，此处userData传入的数据类型为最终要设置的组件指针，便于设置对应组件属性。


<!-- @[runtaskinscopethree_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkScopeTask/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
const uint32_t VALUE_2 = 250;
```

<!-- @[runtaskinscopeone_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkScopeTask/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
//page1
ArkUI_NodeHandle button = nodeAPI->createNode(ARKUI_NODE_BUTTON);
ArkUI_AttributeItem LABEL_Item = {.string = "pageOneButton"};
// 设置id，用于在第二个页面内通过接口查找
ArkUI_AttributeItem id = {.string = "pageOneButton"};
nodeAPI->setAttribute(button, NODE_ID, &id);
nodeAPI->setAttribute(button, NODE_BUTTON_LABEL, &LABEL_Item);
nodeAPI->addChild(textContainer, button);
```

<!-- @[runtaskinscopetwo_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkScopeTask/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
//page2
//pageOneButton由前置页面创建，通过OH_ArkUI_NodeUtils_GetAttachedNodeHandleById在第二个页面获取。
ArkUI_NodeHandle pageOneButton = nullptr;
auto errorCode = OH_ArkUI_NodeUtils_GetAttachedNodeHandleById("pageOneButton", &pageOneButton);
if (errorCode != ARKUI_ERROR_CODE_NO_ERROR) {
    OH_LOG_ERROR(LOG_APP, "test Failed to get pageOneButton handle, error code: %{public}d", errorCode);
    return nullptr;
}
auto uiContext = OH_ArkUI_GetContextByNode(pageOneButton);
if (uiContext == nullptr) {
    OH_LOG_ERROR(LOG_APP, "test Failed to get UI context for pageOneButton");
    return nullptr;
}
OH_ArkUI_RunTaskInScope(uiContext, pageOneButton, [](void *userData) {
    auto *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
    auto pageOneButton = (ArkUI_NodeHandle)userData;
    ArkUI_NumberValue value[1] = {};
    ArkUI_AttributeItem LABEL_Item = {.string = "success"};
    value[0].f32 = VALUE_2;
    ArkUI_AttributeItem button_Item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
    nodeAPI->setAttribute(pageOneButton, NODE_BUTTON_LABEL, &LABEL_Item);
    nodeAPI->setAttribute(pageOneButton, NODE_WIDTH, &button_Item);
});
```
