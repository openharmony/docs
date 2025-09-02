# Listening for Text Box Events

Text boxes support various interactive behaviors, allowing you to register event listeners and obtain status information.

Real-time search: Register the [NODE_TEXT_AREA_ON_CHANGE](../../application-dev/reference/apis-arkui/_ark_u_i___native_module.md) event to receive notifications and obtain the current text content when the text box input changes.

Text filtering: Register the [NODE_TEXT_AREA_ON_WILL_INSERT](../../application-dev/reference/apis-arkui/_ark_u_i___native_module.md) event to receive notifications before text is inserted and control whether to insert text through the return value.

Layout changes during editing: Register the [NODE_TEXT_AREA_ON_EDIT_CHANGE](../../application-dev/reference/apis-arkui/_ark_u_i___native_module.md) event to receive notifications when the text box editing state changes.

The following example demonstrates how to listen for text box events and parse data based on the [Integrating with ArkTS Pages](../ui/ndk-access-the-arkts-page.md) section.

- Registering Events
  
    Events are registered through a unified API. For details, see [registerNodeEvent](../../application-dev/reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodeevent). For details about the event types supported by the text box, see the [ArkUI_NodeEventType](../../application-dev/reference/apis-arkui/_ark_u_i___native_module.md) section, searching for **NODE_TEXT_AREA_**.

    ```c++
    // Create two text components to display the information received in events.
    ArkUI_NodeHandle text = nodeApi->createNode(ARKUI_NODE_TEXT);
    ArkUI_NumberValue textWidth[] = {{.f32 = 300}};
    ArkUI_AttributeItem textWidthItem = {.value = textWidth, .size = 1};
    nodeApi->setAttribute(text, NODE_WIDTH, &textWidthItem);
    
    ArkUI_NodeHandle selectionText = nodeApi->createNode(ARKUI_NODE_TEXT);
    ArkUI_NumberValue selectionTextWidth[] = {{.f32 = 300}};
    ArkUI_AttributeItem selectionTextWidthItem = {.value = selectionTextWidth, .size = 1};
    nodeApi->setAttribute(selectionText, NODE_WIDTH, &selectionTextWidthItem);

    const ArkUI_AttributeItem *attributeItem = nodeApi->getAttribute(textArea, NODE_UNIQUE_ID);
    // Use the component ID as the target ID to distinguish events from different components.
    auto id = attributeItem->value[0].i32;
    // Register the text change event.
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_CHANGE, id, text);
    // Register the paste event.
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_PASTE, id, text);
    // Register the text selection event.
    nodeApi->registerNodeEvent(textArea, NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE, id, selectionText);
    ```

- Registering Event Callbacks

    Event callbacks are registered through a unified API. For details, see [registerNodeEventReceiver](../../application-dev/reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodeeventreceiver).

    ```c++
    nodeApi->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
        ArkUI_NodeEventType eventType = OH_ArkUI_NodeEvent_GetEventType(event);
        ArkUI_AttributeItem content;
        // Text content change event and paste event
        if (eventType == NODE_TEXT_AREA_ON_CHANGE || eventType == NODE_TEXT_AREA_ON_PASTE) {
            // Obtain the text content.
            ArkUI_StringAsyncEvent *stringEvent = OH_ArkUI_NodeEvent_GetStringAsyncEvent(event);
            content = {.string = stringEvent->pStr };
        } else if (eventType == NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE) {
            //Obtain the indices of the selected text (start and end indices) to obtain the selected text.
            ArkUI_NodeComponentEvent *componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
            std::stringstream selectContent;
            selectContent << "start: " << componentEvent->data[0].i32 << " , end: " << componentEvent->data[1].i32;
            content = {.string = selectContent.str().c_str() };
        } else {
            return;
        }
        ArkUI_NodeHandle textNode = reinterpret_cast<ArkUI_NodeHandle>(OH_ArkUI_NodeEvent_GetUserData(event));
        if (textNode) {
            // Display the text information on the Text component.
            ArkUI_NativeNodeAPI_1 *nodeApi = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
                OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
            nodeApi->setAttribute(textNode, NODE_TEXT_CONTENT, &content);
        }
    });
    ```
- Sample Code
    ```c++
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


