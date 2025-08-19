# 监听输入框事件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @kangshihui-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

输入框包含多种交互行为，开发者可注册事件监听并获取状态。

要实现实时搜索功能，可注册[NODE_TEXT_AREA_ON_CHANGE](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)事件，输入框文本发生变化时会收到通知，并能获取当前文本内容。

要实现文字过滤功能，可注册[NODE_TEXT_AREA_ON_WILL_INSERT](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)事件，在文字即将插入前会收到通知，通过返回值控制文字是否插入。

要实现用户编辑文字前后页面布局的不同，可注册[NODE_TEXT_AREA_ON_EDIT_CHANGE](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)事件，输入框编辑状态切换时会收到通知。

以下示例基于[接入ArkTS页面章节](../ui/ndk-access-the-arkts-page.md)，说明如何监听输入框的事件及数据解析。

- 注册事件
    
    事件注册有统一接口，详情请参见[registerNodeEvent](../../application-dev/reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)。输入框支持的事件类型，请参见[NativeNode组件支持的事件类型定义](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)，搜索前缀NODE_TEXT_AREA_。

    ```c++
    // 创建两个文本组件，展示事件内收到的信息。
    ArkUI_NodeHandle text = nodeApi->createNode(ARKUI_NODE_TEXT);
    ArkUI_NumberValue textWidth[] = {{.f32 = 300}};
    ArkUI_AttributeItem textWidthItem = {.value = textWidth, .size = 1};
    nodeApi->setAttribute(text, NODE_WIDTH, &textWidthItem);
    
    ArkUI_NodeHandle selectionText = nodeApi->createNode(ARKUI_NODE_TEXT);
    ArkUI_NumberValue selectionTextWidth[] = {{.f32 = 300}};
    ArkUI_AttributeItem selectionTextWidthItem = {.value = selectionTextWidth, .size = 1};
    nodeApi->setAttribute(selectionText, NODE_WIDTH, &selectionTextWidthItem);

    const ArkUI_AttributeItem *attributeItem = nodeApi->getAttribute(textArea, NODE_UNIQUE_ID);
    // 组件id作为targetid来区分不同组件的事件。
    auto id = attributeItem->value[0].i32;
    // 注册文本变化事件
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_CHANGE, id, text);
    // 注册粘贴事件
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_PASTE, id, text);
    // 注册文本选择事件
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE, id, selectionText);
    ```

- 注册事件回调

    事件回调注册有统一接口，详情请参见[registerNodeEventReceiver](../../application-dev/reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver)。

    ```c++
    nodeApi->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
        ArkUI_NodeEventType eventType = OH_ArkUI_NodeEvent_GetEventType(event);
        ArkUI_AttributeItem content;
        // 文本内容变化事件和粘贴事件
        if (eventType == NODE_TEXT_AREA_ON_CHANGE || eventType == NODE_TEXT_AREA_ON_PASTE) {
            // 获取文本内容
            ArkUI_StringAsyncEvent *stringEvent = OH_ArkUI_NodeEvent_GetStringAsyncEvent(event);
            content = {.string = stringEvent->pStr };
        } else if (eventType == NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE) {
            // 获取选中的文字的索引值，起始索引和结束索引，根据此获取用户选中的文字
            ArkUI_NodeComponentEvent *componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
            std::stringstream selectContent;
            selectContent << "start: " << componentEvent->data[0].i32 << " , end: " << componentEvent->data[1].i32;
            content = {.string = selectContent.str().c_str() };
        } else {
            return;
        }
        ArkUI_NodeHandle textNode = reinterpret_cast<ArkUI_NodeHandle>(OH_ArkUI_NodeEvent_GetUserData(event));
        if (textNode) {
            // 将文本信息展示在Text组件上。
            ArkUI_NativeNodeAPI_1 *nodeApi = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
                OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
            nodeApi->setAttribute(textNode, NODE_TEXT_CONTENT, &content);
        }
    });
    ```
- 完整示例
    ```c++
    #include <arkui/native_interface.h>
    
    void NodeManager::CreateTextAreaNode() {
        ArkUI_NativeNodeAPI_1 *nodeApi = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
            OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
        if (nodeApi == nullptr) {
            return;
        }
        ArkUI_NodeHandle column = nodeApi->createNode(ARKUI_NODE_COLUMN);
        ArkUI_NumberValue colWidth[] = {{.f32 = 300}};
        ArkUI_AttributeItem widthItem = {.value = colWidth, .size = 1};
        nodeApi->setAttribute(column, NODE_WIDTH, &widthItem);

        ArkUI_NodeHandle text = nodeApi->createNode(ARKUI_NODE_TEXT);
        ArkUI_NumberValue textWidth[] = {{.f32 = 300}};
        ArkUI_AttributeItem textWidthItem = {.value = textWidth, .size = 1};
        nodeApi->setAttribute(text, NODE_WIDTH, &textWidthItem);
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
        nodeApi->addChild(column, textArea);
        OH_NativeXComponent_AttachNativeRootNode(xComponent, column);
    }
    ```

![textarea_getstringevent](figures/textarea_getstringevent.gif)