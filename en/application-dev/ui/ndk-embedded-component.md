# Launching EmbeddedUIExtensionAbility with EmbeddedComponent

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=96ada1f41884d80c6802e41679bbfa4affacd656 translatedAt=2026-08-05T01:28:54.410Z pushedAt=2026-08-05T07:04:02.624Z -->

ArkUI offers a subset of ArkTS capabilities on the native side, excluding features such as declarative UI syntax, custom struct components, and the preset UI component library.

Since API version 20, the ArkUI framework provides the capability to embed **EmbeddedComponent** components on the native side. This capability relies on the [EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md) mechanism. **EmbeddedComponent** is used to embed UI content provided by another [EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md) component (within the same application) into the current page. EmbeddedUIExtensionAbility runs in an independent process, handling page layout and rendering. This functionality is primarily designed for modular development scenarios that require process isolation.

> **NOTE**
>
> - After creating [ArkUI_EmbeddedComponentOption](../reference/apis-arkui/capi-arkui-nativemodule-arkui-embeddedcomponentoption.md) with [OH_ArkUI_EmbeddedComponentOption_Create](../reference/apis-arkui/capi-embedded-component-h.md#oh_arkui_embeddedcomponentoption_create), you can use [OH_ArkUI_EmbeddedComponentOption_SetOnError](../reference/apis-arkui/capi-embedded-component-h.md#oh_arkui_embeddedcomponentoption_setonerror) to set the **onError** callback, and [OH_ArkUI_EmbeddedComponentOption_SetOnTerminated](../reference/apis-arkui/capi-embedded-component-h.md#oh_arkui_embeddedcomponentoption_setonterminated) to set the **onTerminated** callback. You can use [OH_ArkUI_NodeUtils_MoveTo](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeutils_moveto) to move the node.
>
> - When using [OH_ArkUI_EmbeddedComponentOption_SetOnTerminated](../reference/apis-arkui/capi-embedded-component-h.md#oh_arkui_embeddedcomponentoption_setonterminated) to set the **onTerminated** callback, the returned want parameter only supports parsing the key-value pairs returned by the provider, and does not support nested parsing.
>
> - After the **EmbeddedComponentOption** attribute is set, call [OH_ArkUI_EmbeddedComponentOption_Dispose](../reference/apis-arkui/capi-embedded-component-h.md#oh_arkui_embeddedcomponentoption_dispose) to release the memory and avoid memory leaks.
>
> - The **EmbeddedComponent** component requires [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute) to set the width and height before it can be displayed.

This example demonstrates the basic usage of the **EmbeddedComponent** component NDK. For ability-related usage, see [EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md). The **bundleName** of the sample app is "com.example.uiextensionandaccessibility", and the **EmbeddedUIExtensionAbility** started within the same app is "ExampleEmbeddedAbility". This example only supports running on devices with multi-process permissions, such as PCs and 2-in-1 devices.

<!-- @[embeddedComponentCTest_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIExtensionAndAccessibility/entry/src/main/cpp/embedded/embedded.cpp) -->

``` C++
#include <arkui/native_node.h>
#include <arkui/native_type.h>
#include <AbilityKit/ability_base/want.h> // Include the ability want header file.

// Register events.
void onError(int32_t code, const char *name, const char *message) {}
void onTerminated(int32_t code, AbilityBase_Want *want) {}
const unsigned int LOG_PRINT_DOMAIN = 0xFF00;
#define SIZE_300 300 // Width/height of the node, in vp (used to set NODE_WIDTH/NODE_HEIGHT).
#define PARAMETER_ERROR_CODE 401 // Parameter error code (returned by OH_ArkUI_NodeContent_AddNode to indicate invalid input).
// ...
    // Create a node.
    ArkUI_NodeHandle embeddedNode = nodeAPI->createNode(ARKUI_NODE_EMBEDDED_COMPONENT);
    // Set properties.
    AbilityBase_Element Element = {.bundleName = "com.example.uiextensionandaccessibility",
                                   .abilityName = "ExampleEmbeddedAbility",
                                   .moduleName = "entry"};       // This API is provided by the ability subsystem.
    AbilityBase_Want *want = OH_AbilityBase_CreateWant(Element); // The API is provided by the ability subsystem.
    if (want == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "AbilityBase_Want", "CreateWant failed");
        return nullptr;
    }
    ArkUI_AttributeItem itemobjwant = {.object = want};
    nodeAPI->setAttribute(embeddedNode, NODE_EMBEDDED_COMPONENT_WANT, &itemobjwant);

    auto embeddedNode_option = OH_ArkUI_EmbeddedComponentOption_Create();
    auto onErrorCallback = onError;
    auto onTerminatedCallback = onTerminated;
    OH_ArkUI_EmbeddedComponentOption_SetOnError(embeddedNode_option, onErrorCallback);
    OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(embeddedNode_option, onTerminatedCallback);

    ArkUI_AttributeItem itemobjembeddedNode = {.object = embeddedNode_option};
    nodeAPI->setAttribute(embeddedNode, NODE_EMBEDDED_COMPONENT_OPTION, &itemobjembeddedNode);
    // Release the embeddedNode_option resource after setting attributes to avoid memory leaks.
    OH_ArkUI_EmbeddedComponentOption_Dispose(embeddedNode_option);

    // Set basic attributes, such as width and height.
    ArkUI_NumberValue value[] = {{.f32 = SIZE_300}};
    ArkUI_AttributeItem item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
    nodeAPI->setAttribute(embeddedNode, NODE_WIDTH, &item);
    nodeAPI->setAttribute(embeddedNode, NODE_HEIGHT, &item);

    // Create a Column node.
    ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
    nodeAPI->setAttribute(column, NODE_WIDTH, &item);
    ArkUI_NumberValue column_bc[] = {{.u32 = 0xFFFF00BB}};
    ArkUI_AttributeItem column_item = {column_bc, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &column_item);
    ArkUI_AttributeItem column_id = {.string = "Column_CAPI"};
    nodeAPI->setAttribute(column, NODE_ID, &column_id);

    // Mount the component node to the parent node.
    nodeAPI->addChild(column, embeddedNode);
```