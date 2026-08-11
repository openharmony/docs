# Adding a Text Event Listener for a Text Box

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiaxiaguang-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=9a5da59cdf4f4c3dc0f87035f85ddf06f80ecfc4 translatedAt=2026-08-05T10:08:28.613Z pushedAt=2026-08-06T06:18:46.434Z -->

Text boxes support various interactive behaviors, allowing you to register event listeners and obtain status information. The following uses a multi-line text box as an example; the steps for adding text event listeners to a single-line text box are similar.

Real-time search: Register the [NODE_TEXT_AREA_ON_CHANGE](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) event to receive notifications and obtain the current text content when the text box input changes.

Text filtering: Register the [NODE_TEXT_AREA_ON_WILL_INSERT](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) event to receive notifications before text is inserted and control whether to insert text through the return value.

Layout changes during editing: Register the [NODE_TEXT_AREA_ON_EDIT_CHANGE](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) event to receive notifications when the text box editing state changes.

The following example demonstrates how to listen for text box events and parse data based on the [Integrating with ArkTS Pages](../ui/ndk-access-the-arkts-page.md) section.

- Registering events

    Events are registered through a unified API. For details, see [registerNodeEvent](../../application-dev/reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent). For details about the event types supported by the text box, see the [ArkUI_NodeEventType](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) section, searching for **NODE_TEXT_AREA_**.

    <!-- @[obtain_create_textarea](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/TextAreaEventNDK/entry/src/main/cpp/manager.cpp) -->

    ``` C++
    ArkUI_NodeHandle text = nodeApi->createNode(ARKUI_NODE_TEXT);
    ArkUI_NumberValue textWidth[] = {{.f32 = 300}};
    ArkUI_AttributeItem textWidthItem = {.value = textWidth, .size = 1};
    nodeApi->setAttribute(text, NODE_WIDTH, &textWidthItem);
    // ···
    ArkUI_NodeHandle selectionText = nodeApi->createNode(ARKUI_NODE_TEXT);
    ArkUI_NumberValue selectionTextWidth[] = {{.f32 = 300}};
    ArkUI_AttributeItem selectionTextWidthItem = {.value = selectionTextWidth, .size = 1};
    nodeApi->setAttribute(selectionText, NODE_WIDTH, &selectionTextWidthItem);
    // ···
    const ArkUI_AttributeItem *attributeItem = nodeApi->getAttribute(textArea, NODE_UNIQUE_ID);
    auto id = attributeItem->value[0].i32;
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_CHANGE, id, text);
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_PASTE, id, text);
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE, id, selectionText);
    ```

- Registering event callbacks

    Event callbacks are registered through a unified API. For details, see [registerNodeEventReceiver](../../application-dev/reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver).

    <!-- @[obtain_textarea_NodeEventReceiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/TextAreaEventNDK/entry/src/main/cpp/manager.cpp) -->

    ``` C++
    nodeApi->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
        ArkUI_NodeEventType eventType = OH_ArkUI_NodeEvent_GetEventType(event);
        ArkUI_AttributeItem content;
        if (eventType == NODE_TEXT_AREA_ON_CHANGE || eventType == NODE_TEXT_AREA_ON_PASTE) {
            ArkUI_StringAsyncEvent *stringEvent = OH_ArkUI_NodeEvent_GetStringAsyncEvent(event);
            content = {.string = stringEvent->pStr };
        } else if (eventType == NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE) {
            ArkUI_NodeComponentEvent *componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
            std::stringstream selectContent;
            selectContent << "start: " << componentEvent->data[0].i32 << " , end: " << componentEvent->data[1].i32;
            content = {.string = selectContent.str().c_str() };
        } else {
            return;
        }
        ArkUI_NodeHandle textNode = reinterpret_cast<ArkUI_NodeHandle>(OH_ArkUI_NodeEvent_GetUserData(event));
        if (textNode) {
            ArkUI_NativeNodeAPI_1 *nodeApi = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
                OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
            nodeApi->setAttribute(textNode, NODE_TEXT_CONTENT, &content);
        }
    });
    ```

- Sample

   This section demonstrates core API usage only. For the complete sample project, see <!--RP1-->[TextAreaEventNDK](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/TextAreaEventNDK)<!--RP1End-->.

    <!-- @[obtain_textarea_all](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/TextAreaEventNDK/entry/src/main/cpp/manager.cpp) -->

    ``` C++
    #include "manager.h"
    #include <sstream>
    #include <arkui/native_interface.h>
    #include <arkui/styled_string.h>
    #include <hilog/log.h>

    #define CUSTOM_LOG_TAG "manager"
    #define LOG_ERROR(...) OH_LOG_Print(LOG_APP, LOG_ERROR, 0xD001400, CUSTOM_LOG_TAG, __VA_ARGS__)
    #define LOG_INFO(...) OH_LOG_Print(LOG_APP, LOG_INFO, 0xD001400, CUSTOM_LOG_TAG, __VA_ARGS__)

    namespace ConstIde {
    const uint32_t NUMBER_0 = 0;
    const uint32_t NUMBER_1 = 1;
    constexpr const char *K_LOG_DOMAIN = "Manager";
    } // namespace ConstIde

    Manager Manager::manager_;
    ArkUI_NativeNodeAPI_1 *Manager::nodeAPI_ = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
    template <class MakeNodeFn>
    static napi_value CreateNativeNode(napi_env env, napi_callback_info info, const char *who, MakeNodeFn makeNodeFn)
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, ConstIde::K_LOG_DOMAIN, "%{public}s BEGIN", who);

        if ((env == nullptr) || (info == nullptr)) {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, ConstIde::K_LOG_DOMAIN, "%{public}s env or info is null",
                         who);
            return nullptr;
        }

        size_t argc = ConstIde::NUMBER_1;
        napi_value args[ConstIde::NUMBER_1] = {nullptr};
        napi_status st = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
        if (st != napi_ok || argc < ConstIde::NUMBER_1) {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, ConstIde::K_LOG_DOMAIN, "%{public}s napi_get_cb_info failed",
                         who);
            return nullptr;
        }

        ArkUI_NodeContentHandle nodeContentHandle = nullptr;
        OH_ArkUI_GetNodeContentFromNapiValue(env, args[ConstIde::NUMBER_0], &nodeContentHandle);
        if (nodeContentHandle == nullptr) {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, ConstIde::K_LOG_DOMAIN,
                         "%{public}s nodeContentHandle is null", who);
            return nullptr;
        }

        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, ConstIde::K_LOG_DOMAIN, "%{public}s after GetNodeContent", who);

        // Optional: Keep the robustness check for nodeAPI_ (consistent with your existing code).
        if (Manager::nodeAPI_ == nullptr) {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, ConstIde::K_LOG_DOMAIN, "%{public}s nodeAPI_ is null", who);
            return nullptr;
        }

        // Build the specific node and mount it.
        ArkUI_NodeHandle page = makeNodeFn();
        if (page == nullptr) {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, ConstIde::K_LOG_DOMAIN, "%{public}s makeNodeFn return null",
                         who);
            return nullptr;
        }

        OH_ArkUI_NodeContent_AddNode(nodeContentHandle, page);
        return nullptr;
    }
    
    constexpr int32_t NUM_10 = 10;
    constexpr int32_t NUM_28 = 28;
    constexpr int32_t NUM_400 = 400;

    napi_value Manager::CreateTextAreaNativeNode(napi_env__* env, napi_callback_info__* info)
    {
        return CreateNativeNode(env, info, "CreateTextAreaNativeNode",
                                []() -> ArkUI_NodeHandle { return CreateTextAreaNativeNode(); });
    }
    
    ArkUI_NodeHandle Manager::CreateTextAreaNativeNode()
    {
        ArkUI_NativeNodeAPI_1 *nodeApi = Manager::nodeAPI_;
    
        ArkUI_NodeHandle column = nodeApi->createNode(ARKUI_NODE_COLUMN);
        ArkUI_NumberValue colWidth[] = {{.f32 = 300}};
        ArkUI_AttributeItem widthItem = {.value = colWidth, .size = 1};
        nodeApi->setAttribute(column, NODE_WIDTH, &widthItem);
    
        ArkUI_NodeHandle text = nodeApi->createNode(ARKUI_NODE_TEXT);
        ArkUI_NumberValue textWidth[] = {{.f32 = 300}};
        ArkUI_AttributeItem textWidthItem = {.value = textWidth, .size = 1};
        nodeApi->setAttribute(text, NODE_WIDTH, &textWidthItem);
        ArkUI_NumberValue textHeight[] = {{.f32 = 100}};
        ArkUI_AttributeItem textHeightItem = {.value = textHeight, .size = 1};
        nodeApi->setAttribute(text, NODE_HEIGHT, &textHeightItem);
        
        nodeApi->addChild(column, text);
        
        ArkUI_NodeHandle selectionText = nodeApi->createNode(ARKUI_NODE_TEXT);
        ArkUI_NumberValue selectionTextWidth[] = {{.f32 = 300}};
        ArkUI_AttributeItem selectionTextWidthItem = {.value = selectionTextWidth, .size = 1};
        nodeApi->setAttribute(selectionText, NODE_WIDTH, &selectionTextWidthItem);
        nodeApi->addChild(column, selectionText);
        ArkUI_NodeHandle textArea = nodeApi->createNode(ARKUI_NODE_TEXT_AREA);
        ArkUI_NumberValue textAreaWidth[] = {{.f32 = 300}};
        ArkUI_AttributeItem textAreaWidthItem = {.value = textAreaWidth, .size = 1};
        nodeApi->setAttribute(textArea, NODE_WIDTH, &textAreaWidthItem);
    
        ArkUI_NumberValue borderWidth[] = {{.f32 = 1}};
        ArkUI_AttributeItem borderWidthItem = {.value = borderWidth, .size = 1};
        nodeApi->setAttribute(textArea, NODE_BORDER_WIDTH, &borderWidthItem);
    
        const ArkUI_AttributeItem *attributeItem = nodeApi->getAttribute(textArea, NODE_UNIQUE_ID);
        auto id = attributeItem->value[0].i32;
        nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_CHANGE, id, text);
        nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_PASTE, id, text);
        nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE, id, selectionText);
        TextAreaNodeEventReceiver(nodeApi);
        nodeApi->addChild(column, textArea);
        return column;
    }
    
    void Manager::TextAreaNodeEventReceiver(ArkUI_NativeNodeAPI_1* nodeApi)
    {
        nodeApi->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
            ArkUI_NodeEventType eventType = OH_ArkUI_NodeEvent_GetEventType(event);
            ArkUI_AttributeItem content;
            if (eventType == NODE_TEXT_AREA_ON_CHANGE || eventType == NODE_TEXT_AREA_ON_PASTE) {
                ArkUI_StringAsyncEvent *stringEvent = OH_ArkUI_NodeEvent_GetStringAsyncEvent(event);
                content = {.string = stringEvent->pStr };
            } else if (eventType == NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE) {
                ArkUI_NodeComponentEvent *componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
                std::stringstream selectContent;
                selectContent << "start: " << componentEvent->data[0].i32 << " , end: " << componentEvent->data[1].i32;
                content = {.string = selectContent.str().c_str() };
            } else {
                return;
            }
            ArkUI_NodeHandle textNode = reinterpret_cast<ArkUI_NodeHandle>(OH_ArkUI_NodeEvent_GetUserData(event));
            if (textNode) {
                ArkUI_NativeNodeAPI_1 *nodeApi = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
                    OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
                nodeApi->setAttribute(textNode, NODE_TEXT_CONTENT, &content);
            }
        });
    }
    ```

![textarea_getstringevent](figures/textarea_getstringevent.gif)