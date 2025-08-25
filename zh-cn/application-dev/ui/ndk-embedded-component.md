# 通过EmbeddedComponent拉起EmbeddedUIExtensionAbility
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

ArkUI在Native侧提供的能力是ArkTS的子集，某些能力不会在Native侧提供，例如声明式UI语法、自定义struct组件及UI系统预置UI组件库。


从API version 20开始，ArkUI开发框架提供了Native侧嵌入EmbeddedComponent组件的能力，此能力依赖于[EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md)机制。EmbeddedComponent用于支持在当前页面嵌入同一应用内其他[EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)提供的UI。EmbeddedUIExtensionAbility在独立进程中运行，负责页面布局和渲染。此功能主要用于有进程隔离需求的模块化开发场景。


> **说明：**
>
> - 使用[OH_ArkUI_EmbeddedComponentOption_Create](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_create)获取[ArkUI_EmbeddedComponentOption](../reference/apis-arkui/capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)后，可以使用[OH_ArkUI_EmbeddedComponentOption_SetOnError](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_setonerror)设置onError回调，使用[OH_ArkUI_EmbeddedComponentOption_SetOnTerminated](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_setonterminated)设置onTerminated回调。可以使用[OH_ArkUI_NodeUtils_MoveTo](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_moveto)迁移节点。
>
> - 使用[OH_ArkUI_EmbeddedComponentOption_SetOnTerminated](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_setonterminated)设置onTerminated回调时，返回的want参数，只支持提供方返回的want参数的key，value解析，不支持嵌套解析。
>
> - 在EmbeddedComponent销毁时，调用[OH_ArkUI_EmbeddedComponentOption_Dispose](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_dispose)释放内存。
>
> - EmbeddedComponent组件需要使用[setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)设置宽高才能显示。

本示例展示EmbeddedComponent组件NDK的基础使用方式，ability相关使用请参考[EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md)。示例应用的bundleName为"com.example.embeddeddemo"，同一应用下被拉起的EmbeddedUIExtensionAbility为"ExampleEmbeddedAbility"。本示例仅支持在具有多进程权限的设备上运行，例如PC/2in1。

  ```c
#include "<arkui/native_node.h>"
#include "<arkui/native_type.h>"
#include <AbilityKit/ability_base/want.h> //引用元能力want头文件
//创建节点
ArkUI_NodeHandle embeddedNode = nodeAPI->createNode(ARKUI_NODE_EMBEDDED_COMPONENT);

// 设置属性
AbilityBase_Element Element = {.bundleName = "com.example.embeddeddemo", .abilityName = "EmbeddedUIExtensionAbility", .moduleName = ""};// 由元能力提供接口
AbilityBase_Want* want = OH_AbilityBase_CreateWant(Element); // 由元能力提供接口
ArkUI_AttributeItem itemobjwant = {.object = want};
nodeAPI->setAttribute(embeddedNode, NODE_EMBEDDED_COMPONENT_WANT, &itemobjwant);

//注册事件
void onError(int32_t code, const char* name, const char* message) {}
void onTerminated(int32_t code, AbilityBase_Want* want) {}

auto embeddedNode_option = OH_ArkUI_EmbeddedComponentOption_Create();
auto onErrorCallback = onError;
auto onTerminatedCallback = onTerminated;
OH_ArkUI_EmbeddedComponentOption_SetOnError(embeddedNode_option, onErrorCallback);
OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(embeddedNode_option, onTerminatedCallback);
    
ArkUI_AttributeItem itemobjembeddedNode = {.object = embeddedNode_option};
nodeAPI->setAttribute(embeddedNode, NODE_EMBEDDED_COMPONENT_OPTION, &itemobjembeddedNode);

//设置基本属性，如宽高
ArkUI_NumberValue value[] = {480};
ArkUI_AttributeItem item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
value[0].f32 = 300;
nodeAPI->setAttribute(embeddedNode, NODE_WIDTH, &item);
nodeAPI->setAttribute(embeddedNode, NODE_HEIGHT, &item);

// 创建Column
ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
ArkUI_NumberValue value[] = {480};
ArkUI_AttributeItem item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
nodeAPI->setAttribute(column, NODE_WIDTH, &item);
ArkUI_NumberValue column_bc[] = {{.u32 = 0xFFF00BB}};
ArkUI_AttributeItem column_item = {column_bc, 1};
nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &column_item);
ArkUI_AttributeItem column_id = {.string = "Column_CAPI"};
nodeAPI->setAttribute(column, NODE_ID, &column_id);

//上树
nodeAPI->addChild(column, embeddedNode);
  ```