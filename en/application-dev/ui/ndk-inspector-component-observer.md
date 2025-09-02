# Listening for Component Layout and Drawing Events


Since API version 16, NDK APIs provides functions for registering and unregistering callbacks for UI component layout completion and drawing completion events. You can use the following APIs to listen for when specific node layouts are completed or when drawing is finished, and register corresponding callbacks: Use [OH_ArkUI_RegisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerlayoutcallbackonnodehandle) to register a layout completion callback. Use [OH_ArkUI_RegisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerdrawcallbackonnodehandle) to register a drawing completion callback. Use [OH_ArkUI_UnregisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_unregisterlayoutcallbackonnodehandle) to unregister a layout completion callback. Use [OH_ArkUI_UnregisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_unregisterdrawcallbackonnodehandle) to unregister a drawing completion callback.


> **NOTE**
>
> [OH_ArkUI_RegisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerlayoutcallbackonnodehandle) and [OH_ArkUI_RegisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerdrawcallbackonnodehandle) can be used to listen for component layout completion or drawing completion events, but only one function pointer can be registered, which means subsequent calls will overwrite the previous callbacks.


The following example is based on the [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md) section, supplementing related event listening.
It implements layout and drawing completion event registration logic in the **ArkUITextNode** object.
```c
// ArkUITextNode.h
// Implement an encapsulation class for the text component.

#ifndef MYAPPLICATION_ARKUITEXTNODE_H
#define MYAPPLICATION_ARKUITEXTNODE_H

#include <arkui/native_type.h>
#include <arkui/native_node.h>
#include "ArkUINode.h"
#include <string>

namespace NativeModule {
// Layout completion callback
void OnLayoutCompleted(void* userData) {
    ArkUI_NodeHandle node = (ArkUI_NodeHandle)userData;
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "the text_node is layout completed");
    ArkUI_NativeNodeAPI_1 *nativeModule = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
    ArkUI_AttributeItem item = {nullptr, 0, "layout callback"};
    nativeModule->setAttribute(node, NODE_TEXT_CONTENT, &item);
}
// Drawing completion callback
void OnDrawCompleted(void* userData) {
    ArkUI_NodeHandle node = (ArkUI_NodeHandle)userData;
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "the text_node is draw completed");
    ArkUI_NativeNodeAPI_1 *nativeModule = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
    ArkUI_AttributeItem item = {nullptr, 0, "draw callback"};
    nativeModule->setAttribute(node, NODE_TEXT_CONTENT, &item);
}

class ArkUITextNode : public ArkUINode {
public:
    ArkUITextNode()
        : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_TEXT)) {}
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
    void SetLayoutCallBack(int32_t nodeId) {
        assert(handle_);
        nodeId_ = nodeId;
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "set layout callback");
        // Register a layout completion callback.
        OH_ArkUI_RegisterLayoutCallbackOnNodeHandle(handle_, this, OnLayoutCompleted);
    }
    void ResetLayoutCallBack() {
        assert(handle_);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "reset layout callback");
        // Unregister the layout completion callback.
        OH_ArkUI_UnregisterLayoutCallbackOnNodeHandle(handle_);
    }
    void SetDrawCallBack(int32_t nodeId) {
        assert(handle_);
        nodeId_ = nodeId;
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "set draw callback");
        // Register a drawing completion callback.
        OH_ArkUI_RegisterDrawCallbackOnNodeHandle(handle_, this, OnDrawCompleted);
    }
    void ResetDrawCallBack() {
        assert(handle_);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "reset draw callback");
        // Unregister the drawing completion callback.
        OH_ArkUI_UnregisterDrawCallbackOnNodeHandle(handle_);
    }
    void SetInspectorId(std::string inspectorId) {
        ArkUI_AttributeItem item = {nullptr, 0, inspectorId.c_str()};
        nativeModule_->setAttribute(handle_, NODE_ID, &item);
    }
};
} // namespace NativeModule

#endif // MYAPPLICATION_ARKUITEXTNODE_H
```
<!--no_check-->