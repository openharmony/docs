# Launching EmbeddedUIExtensionAbility with EmbeddedComponent
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

ArkUI offers a subset of ArkTS capabilities on the native side, excluding features such as declarative UI syntax, custom struct components, and the preset UI component library.


Since API version 20, the ArkUI framework provides the capability to embed **EmbeddedComponent** components on the native side. This capability relies on the [EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md) mechanism. **EmbeddedComponent** is used to embed UI content provided by another [EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md) component (within the same application) into the current page. EmbeddedUIExtensionAbility runs in an independent process, handling page layout and rendering. This functionality is primarily designed for modular development scenarios that require process isolation.


> **NOTE**
>
> - After creating [ArkUI_EmbeddedComponentOption](../reference/apis-arkui/capi-arkui-nativemodule-arkui-embeddedcomponentoption.md) with [OH_ArkUI_EmbeddedComponentOption_Create](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_create), use [OH_ArkUI_EmbeddedComponentOption_SetOnError](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_setonerror) to set the **onError** callback and [OH_ArkUI_EmbeddedComponentOption_SetOnTerminated](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_setonterminated) to set the **onTerminated** callback. Use [OH_ArkUI_NodeUtils_MoveTo](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_moveto) for node migration.
>
> - When the **onTerminated** callback is set using [OH_ArkUI_EmbeddedComponentOption_SetOnTerminated](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_setonterminated), the returned **want** parameter contains only the key-value pairs returned by the provider. Nested parsing is not supported.
>
> - Call [OH_ArkUI_EmbeddedComponentOption_Dispose](../reference/apis-arkui/capi-native-type-h.md#oh_arkui_embeddedcomponentoption_dispose) to release memory when the **EmbeddedComponent** component is destroyed.
>
> - The **width** and **height** attributes must be explicitly set for **EmbeddedComponent** using [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute).

This example demonstrates the basic usage of **EmbeddedComponent**. For details about ability usage, see [EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md). The sample application's bundle name is "com.example.embeddeddemo", and the EmbeddedUIExtensionAbility to be launched within the same application is named "ExampleEmbeddedAbility". This sample requires multi-process permission and can only run on supported devices such as PCs and 2-in-1 devices.

  ```c
#include <arkui/native_node.h>
#include <arkui/native_type.h>
#include <AbilityKit/ability_base/want.h> // Include the ability want header file.
// Create a node.
ArkUI_NodeHandle embeddedNode = nodeAPI->createNode(ARKUI_NODE_EMBEDDED_COMPONENT);

// Set properties.
AbilityBase_Element Element = {.bundleName = "com.example.embeddeddemo", .abilityName = "EmbeddedUIExtensionAbility", .moduleName = ""};// The API is provided by the ability side.
AbilityBase_Want* want = OH_AbilityBase_CreateWant(Element); // The API is provided by the ability side.
ArkUI_AttributeItem itemobjwant = {.object = want};
nodeAPI->setAttribute(embeddedNode, NODE_EMBEDDED_COMPONENT_WANT, &itemobjwant);

// Register event callbacks.
void onError(int32_t code, const char* name, const char* message) {}
void onTerminated(int32_t code, AbilityBase_Want* want) {}

auto embeddedNode_option = OH_ArkUI_EmbeddedComponentOption_Create();
auto onErrorCallback = onError;
auto onTerminatedCallback = onTerminated;
OH_ArkUI_EmbeddedComponentOption_SetOnError(embeddedNode_option, onErrorCallback);
OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(embeddedNode_option, onTerminatedCallback);
    
ArkUI_AttributeItem itemobjembeddedNode = {.object = embeddedNode_option};
nodeAPI->setAttribute(embeddedNode, NODE_EMBEDDED_COMPONENT_OPTION, &itemobjembeddedNode);

// Set basic attributes, such as the width and height.
ArkUI_NumberValue value[] = {480};
ArkUI_AttributeItem item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
value[0].f32 = 300;
nodeAPI->setAttribute(embeddedNode, NODE_WIDTH, &item);
nodeAPI->setAttribute(embeddedNode, NODE_HEIGHT, &item);

// Create a Column node.
ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
nodeAPI->setAttribute(column, NODE_WIDTH, &item);
ArkUI_NumberValue column_bc[] = {{.u32 = 0xFFF00BB}};
ArkUI_AttributeItem column_item = {column_bc, 1};
nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &column_item);
ArkUI_AttributeItem column_id = {.string = "Column_CAPI"};
nodeAPI->setAttribute(column, NODE_ID, &column_id);

// Build the node tree.
nodeAPI->addChild(column, embeddedNode);
  ```
