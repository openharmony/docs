# Implementing Custom Drawing
When the registered event is detected as a drawing type, you can use the custom drawing feature to implement your own drawing logic and render custom content.
> **NOTE**
> - During event registration, you must register the event as a drawing event (for example, **ARKUI_NODE_CUSTOM_EVENT_ON_DRAW**). You can find the event types and their meanings by referring to the [ArkUI_NodeCustomEventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodecustomeventtype) enum.
> 
> - To implement custom drawing logic, you must define custom **UserData** and pass it during event registration.

- Use the **create** API of **ArkUI_NativeNodeAPI_1** to create a custom node, passing **ARKUI_NODE_CUSTOM**.
    ```c++
    auto customNode = nodeAPI->createNode(ARKUI_NODE_CUSTOM);
    ```

- Register the custom event with the custom node, event type (for example, **ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW**), event ID, and **UserData**.
    ```c++
    //UserData
    struct A {
        int32_t a =6;
        bool flag = true;
        ArkUI_NodeHandle node;
    };
    A *a = new A;
    a->node = customNode;
    nodeAPI->registerNodeCustomEvent(customNode,ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW,1,a);
    nodeAPI->registerNodeCustomEventReceiver([](ArkUI_NodeCustomEvent *event) {
    // Event callback logic
    });
    ```

- In the callback, obtain the event type, event ID, and UserData to determine the logic to execute, using the following APIs: [OH_ArkUI_NodeCustomEvent_GetEventType](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodecustomevent_geteventtype), [OH_ArkUI_NodeCustomEvent_GetEventTargetId](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodecustomevent_geteventtargetid), [OH_ArkUI_NodeCustomEvent_GetUserData](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodecustomevent_getuserdata).

    ```c++
    auto type = OH_ArkUI_NodeCustomEvent_GetEventType(event);
    auto targetId = OH_ArkUI_NodeCustomEvent_GetEventTargetId(event);
    auto userData =reinterpret_cast<A *>( OH_ArkUI_NodeCustomEvent_GetUserData(event));
    ```

- Use [OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodecustomevent_getdrawcontextindraw) to obtain the drawing context from the custom event, and then pass it to [OH_ArkUI_DrawContext_GetCanvas](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_drawcontext_getcanvas) to obtain the drawing canvas pointer. This pointer is then cast to an **OH_Drawing_Canvas** pointer for drawing operations.
    ```c++
    // Obtain the drawing context for the custom event.
    auto *drawContext = OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw(event);
    // Obtain the drawing canvas pointer.
    auto *canvas1 = OH_ArkUI_DrawContext_GetCanvas(drawContext);
    // Cast the pointer to an OH_Drawing_Canvas pointer for drawing.
    OH_Drawing_Canvas *canvas = reinterpret_cast<OH_Drawing_Canvas *>(canvas1);
    // Drawing logic.
    int32_t width = 1000;
    int32_t height = 1000;
    auto path = OH_Drawing_PathCreate();
    OH_Drawing_PathMoveTo(path, width / 4, height / 4);
    OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
    OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
    OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
    OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
    OH_Drawing_PathClose(path);
    auto pen = OH_Drawing_PenCreate();
    OH_Drawing_PenSetWidth(pen, 10);
    OH_Drawing_PenSetColor(pen, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
    OH_Drawing_CanvasAttachPen(canvas, pen);
    OH_Drawing_CanvasDrawPath(canvas, path);
    ```
**Example**
   
```c++
ArkUI_NodeHandle test(ArkUI_NativeNodeAPI_1 *nodeAPI) {
    // Create a node.
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
    auto customNode = nodeAPI->createNode(ARKUI_NODE_CUSTOM);
    ArkUI_NumberValue value[] = {480};
    ArkUI_AttributeItem item = {value, 1};
    // Set attributes.
    nodeAPI->setAttribute(column, NODE_WIDTH, &item);
    value[0].i32 = 720;
    nodeAPI->setAttribute(column, NODE_HEIGHT, &item);
    ArkUI_NumberValue NODE_WIDTH_value[] = {200};
    ArkUI_AttributeItem NODE_WIDTH_Item[] = {NODE_WIDTH_value, 1};
    ArkUI_NumberValue NODE_HEIGHT_value[] = {200};
    ArkUI_AttributeItem NODE_HEIGHT_Item[] = {NODE_HEIGHT_value, 1};
    ArkUI_NumberValue NODE_BACKGROUND_COLOR_item_value[] = {{.u32 = 0xFFFFFF00}};
    ArkUI_AttributeItem NODE_BACKGROUND_COLOR_Item[] = {NODE_BACKGROUND_COLOR_item_value, 1};
    // Define custom UserData.
    struct A {
        int32_t a =6;
        bool flag = true;
        ArkUI_NodeHandle node;
    };
    A *a = new A;
    a->node = customNode;
    nodeAPI->setAttribute(customNode, NODE_WIDTH, NODE_WIDTH_Item);
    nodeAPI->setAttribute(customNode, NODE_HEIGHT, NODE_HEIGHT_Item);
    nodeAPI->setAttribute(customNode, NODE_BACKGROUND_COLOR, NODE_BACKGROUND_COLOR_Item);
    // Register the event.
    nodeAPI->registerNodeCustomEvent(customNode,ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW,1,a);
    // Define the event callback.
    nodeAPI->registerNodeCustomEventReceiver([](ArkUI_NodeCustomEvent *event) {
        // Obtain information from the custom event.
        auto type = OH_ArkUI_NodeCustomEvent_GetEventType(event);
        auto targetId = OH_ArkUI_NodeCustomEvent_GetEventTargetId(event);
        auto userData =reinterpret_cast<A *>( OH_ArkUI_NodeCustomEvent_GetUserData(event));
        if (type == ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW && targetId == 1 && userData->flag) {
            // Obtain the drawing context for the custom event.
            auto *drawContext = OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw(event);
            // Obtain the drawing canvas pointer.
            auto *canvas1 = OH_ArkUI_DrawContext_GetCanvas(drawContext);
            // Cast the pointer to an OH_Drawing_Canvas pointer for drawing.
            OH_Drawing_Canvas *canvas = reinterpret_cast<OH_Drawing_Canvas *>(canvas1);
            int32_t width = 1000;
            int32_t height = 1000;
            auto path = OH_Drawing_PathCreate();
            OH_Drawing_PathMoveTo(path, width / 4, height / 4);
            OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
            OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
            OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
            OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
            OH_Drawing_PathClose(path);
            auto pen = OH_Drawing_PenCreate();
            OH_Drawing_PenSetWidth(pen, 10);
            OH_Drawing_PenSetColor(pen, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
            OH_Drawing_CanvasAttachPen(canvas, pen);
            OH_Drawing_CanvasDrawPath(canvas, path);
        }
    });
    // Add the custom node to the tree.
    nodeAPI->addChild(column, customNode);
    return column;
    }
```
![Custom drawing](figures/custom_drawing.jpg)
