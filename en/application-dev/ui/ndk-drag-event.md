# Drag Event

The ArkUI framework provides a set of drag event APIs to help you implement drag-and-drop functionality.These events include [NODE_ON_PRE_DRAG](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype), [NODE_ON_DRAG_START](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype), [NODE_ON_DROP](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype), [NODE_ON_DRAG_ENTER](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype), [NODE_ON_DRAG_MOVE](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype), [NODE_ON_DRAG_LEAVE](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype), and [NODE_ON_DRAG_END](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype). These events are triggered at different stages of the drag operation, allowing you to perform specific actions and manage the drag interaction as needed.

## Basic Drag Implementation

In ArkUI, you can implement the drag-and-drop functionality using C and C++ by calling C APIs. The following provides step-by-step instructions using the **Image** component as an example, along with key points to keep in mind during development.

1. Set a component draggable.

   Obtain the [Node-API](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_getmoduleinterface), which you'll need for node operations, such as creating a node.

    ```cpp
    ArkUI_NativeNodeAPI_1 *nodeAPI = nullptr;
    OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeAPI);
    ```

   Create an **Image** node and set the draggable and other related attributes.

    ```cpp
    auto image = nodeAPI->createNode(ARKUI_NODE_IMAGE);
    ArkUI_NumberValue NODE_IMAGE_SRC_Item = {.string = "/pages/common/1111.png"};
    ArkUI_NumberValue imageWidthValue[] = {100};
    ArkUI_AttributeItem imageWidthItem = {imageWidthValue, 1};
    ArkUI_NumberValue imageHeightValue[] = {100};
    ArkUI_AttributeItem imageHeightItem = {imageHeightValue, 1};
    ArkUI_NumberValue marginValue[] = {20};
    ArkUI_AttributeItem marginItem = {marginValue, 1};
    nodeAPI->setAttribute(image, NODE_WIDTH, &imageWidthItem);
    nodeAPI->setAttribute(image, NODE_HEIGHT, &imageHeightItem);
    nodeAPI->setAttribute(image, NODE_IMAGE_SRC, &NODE_IMAGE_SRC_Item);
    nodeAPI->setAttribute(image, NODE_MARGIN, &marginItem);
    nodeAPI->registerNodeEvent(image, NODE_ON_DRAG_START, 1, nullptr);
    auto returnValue1 = OH_ArkUI_SetNodeDraggable(image, true);
    ```

2. Customize the drag preview and background image.

   Create a [PixelMap](../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_createpixelmap) object and set its width, height, and other properties. Set [dragPreviewOption](../reference/apis-arkui/drag__and__drop_8h.md#functions) for the **Image** node to customize the rounded corners and badges of the drag preview.

    ```cpp
      // Create a PixelMap.
      uint8_t data[960000];
      size_t dataSize = 960000;
      for (int i = 0; i < dataSize; i++) {
        data[i] = i + 1;
      }
      // Create a parameter structure instance and set parameters.
      OH_Pixelmap_InitializationOptions *createOpts;
      OH_PixelmapInitializationOptions_Create(&createOpts);
      OH_PixelmapInitializationOptions_SetWidth(createOpts, 400);
      OH_PixelmapInitializationOptions_SetHeight(createOpts, 600);
      OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_BGRA_8888);
      OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);
      // Create a Pixelmap instance.
      OH_PixelmapNative *pixelmap = nullptr;
      OH_PixelmapNative_CreatePixelmap(data, dataSize, createOpts, &pixelmap);
      OH_PixelmapNative_Rotate(pixelmap, 45);
      OH_PixelmapNative_Opcity(pixelmap, 0.1);
      OH_PixelmapNative_Scale(pixelmap, 0.5, 1.0);
      OH_PixelmapNative_Translate(pixelmap, 50.0, 10.0);
      OH_ArkUI_SetNodeDragPreview(image, pixelmap);
      auto *previewOptions = OH_ArkUI_CreateDragPreviewOption();
      auto returnValue2 = OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled(previewOptions, true);
      auto returnValue3 = OH_ArkUI_DragPreviewOption_SetBadgeNumber(previewOptions, 10);
      auto returnValue4 = OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(previewOptions, true);
      OH_ArkUI_SetNodeDragPreviewOption(image, previewOptions);
    ```

3. Set related events.

   Use a unified callback to handle events. Distinguish between different events using [eventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype).

    ```cpp
    nodeAPI->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
      auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
      auto targetId = OH_ArkUI_NodeEvent_GetTargetId(event);
      auto *dragEvent = OH_ArkUI_NodeEvent_GetDragEvent(event);
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                    "targetId=%{public}d,eventType=%{public}d,", targetId,
                    eventType);
      switch (eventType) {
        case NODE_ON_CLICK: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "ARKUI_NODE_BUTTON click! dragable");
            break;
        }
        case NODE_ON_PRE_DRAG: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest", "NODE_ON_PRE_DRAG EventReceiver");
            break;
        }
        case NODE_ON_DRAG_START: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "NODE_ON_DRAG_START EventReceiver");
            break;
        }
        case NODE_ON_DROP: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest", "NODE_ON_DROP EventReceiver");
            break;
        }
        case NODE_ON_DRAG_ENTER: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "NODE_ON_DRAG_ENTER EventReceiver");
            break;
        }
        case NODE_ON_DRAG_MOVE: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "NODE_ON_DRAG_MOVE EventReceiver");
            break;
        }
        case NODE_ON_DRAG_LEAVE: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "NODE_ON_DRAG_LEAVE EventReceiver");
            break;
        }
        case NODE_ON_DRAG_END: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest", "NODE_ON_DRAG_END EventReceiver");
            break;
        }
        }
    });
    ```

4. Handle the **NODE_ON_DRAG_START** event.

   In the **NODE_ON_DRAG_START** event, perform operations required to initiate the drag operation, typically involving data processing. For example, create a [UdmfRecord](../reference/apis-arkdata/_u_d_m_f.md#oh_udmfrecord), add the required data (such as **imageUri**) to the **UdmfRecord** in the **fileUri** type, set the **UdmfRecord** to [udmfData](../reference/apis-arkdata/_u_d_m_f.md#oh_udmfdata), and set **udmfData** to [DragEvent](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_dragevent).

    ```cpp
    case NODE_ON_DRAG_START: {
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                    "NODE_ON_DRAG_START EventReceiver");
      OH_UdmfRecord *record = OH_UdmfRecord_Create();
      int returnValue;
      OH_UdsFileUri *imageValue = OH_UdsFileUri_Create();
      returnValue = OH_UdsFileUri_SetFileUri(imageValue, "/pages/common/1111.png");
      returnValue = OH_UdmfRecord_AddFileUri(record, imageValue);
      OH_UdmfData *data = OH_UdmfData_Create();
      returnValue = OH_UdmfData_AddRecord(data, record);
      returnVaule = OH_ArkUI_DragEvent_SetData(dragEvent, data);
      break;
    }
    ```

5. Handle the **NODE_ON_DROP** event.

   In the **NODE_ON_DROP** event, perform operations related to the drop phase, typically involving retrieving the data passed during the drag process. For example, obtain [udmfData](../reference/apis-arkdata/_u_d_m_f.md#oh_udmfdata), check whether the required data type exists, extract the corresponding data from [UdmfRecord](../reference/apis-arkdata/_u_d_m_f.md#oh_udmfrecord), and destroy the pointer.

    ```cpp
    case NODE_ON_DROP: {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                      "NODE_ON_DRAG_START EventReceiver");
        // Obtain the UDMF data.
        int returnValue;
        // Create an OH_UdmfData object.
        OH_UdmfData *data = OH_UdmfData_Create();
        returnValue = OH_ArkUI_DragEvent_GetUdmfData(dragEvent, data);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                      "OH_ArkUI_DragEvent_GetUdmfData returnValue = %{public}d", returnValue);
        // Check whether OH_UdmfData has the required data type.
        bool resultUdmf = OH_UdmfData_HasType(data, UDMF_META_GENERAL_FILE);
        if (resultUdmf) {
            // Obtain records from OH_UdmfData.
            unsigned int recordsCount = 0;
            OH_UdmfRecord **records = OH_UdmfData_GetRecords(data, &recordsCount);
            // Extract elements from records.
            int returnStatus;
            for (int i = 0; i < recordsCount; i++) {
                // Obtain the file type data from OH_UdmfRecord.
                OH_UdsFileUri *imageValue = OH_UdsFileUri_Create();
                returnStatus = OH_UdmfRecord_GetFileUri(records[i], imageValue);
                const char* fileUri = OH_UdsFileUri_GetFileUri(imageValue);
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                              "dragTest OH_UdmfRecord_GetPlainText "
                              "returnStatus= %{public}d "
                              "fileUri= %{public}s",
                              returnStatus, fileUri);
                // Destroy the pointer after use.
                OH_UdsFileUri_Destroy(imageValue);
            }
        } else {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_UdmfData_HasType not contain UDMF_META_PLAIN_TEXT");
        }
        break;
    }
    ```

## Initiating a Drag Operation

In addition to the basic drag-and-drop functionality, ArkUI allows you to initiate a drag operation using C APIs. The following example demonstrates how to use C APIs to start a drag operation with text data and highlights key points to keep in mind during development.

1. Register node events.

   Create a **Button** node, set its attributes, and register the [NODE_ON_TOUCH_INTERCEPT](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype) event.

    ```cpp
    // Use buttonTouch as targetId to distinguish events from different targets.
    enum {
      buttonTouch
    }

    ArkUI_NativeNodeAPI_1 *nodeAPI = nullptr;
    OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeAPI);
    auto button = nodeAPI->createNode(ARKUI_NODE_BUTTON);
    ArkUI_AttributeItem NODE_Button_SRC_Item = {.string = "button"};
    ArkUI_NumberValue buttonWidthValue[] = {200};
    ArkUI_AttributeItem buttonWidthItem = {buttonWidthValue, 1};
    ArkUI_NumberValue buttonHeightValue[] = {100};
    ArkUI_AttributeItem buttonHeightItem = {buttonHeightValue, 1};
    ArkUI_NumberValue marginValue[] = {20};
    ArkUI_AttributeItem marginItem = {marginValue, 1};
    nodeAPI->setAttribute(button, NODE_WIDTH, &buttonWidthItem);
    nodeAPI->setAttribute(button, NODE_HEIGHT, &buttonHeightItem);
    nodeAPI->setAttribute(button, NODE_MARGIN, &marginItem);
    nodeAPI->setAttribute(button, NODE_BUTTON_LABEL, &NODE_Button_SRC_Item);
    nodeAPI->registerNodeEvent(button, NODE_ON_TOUCH_INTERCEPT, buttonTouch, nullptr);
    ```
2. Receive the **NODE_ON_TOUCH_INTERCEPT** event.

     In the **NODE_ON_TOUCH_INTERCEPT** event, you need to set up **DragAction** to initiate the drag operation. Use [targetId](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeevent_gettargetid) to distinguish events triggered by different buttons.

      ```cpp
      nodeAPI->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
        auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
        auto targetId = OH_ArkUI_NodeEvent_GetTargetId(event);
        ArkUI_NodeHandle node = OH_ArkUI_NodeEvent_GetNodeHandle(event);
        auto *dragEvent = OH_ArkUI_NodeEvent_GetDragEvent(event);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                      "targetId=%{public}d,eventType=%{public}d,", targetId,
                      eventType);
        switch (eventType) {
          case NODE_ON_TOUCH_INTERCEPT: {
              OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                            "ARKUI_NODE_BUTTON touch intercept");
              break;
              switch (targetId) {
                case buttonTouch: {
                  OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest", "dragTest button touch!");
                }
              }
          }
          case NODE_ON_DROP: {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest", "NODE_ON_DROP EventReceiver");
          }
        }
      });
      ```
3. Set the drag action.

     In the **NODE_ON_TOUCH_INTERCEPT** event, set **DragAction** to initiate the drag operation. Create a [PixelMap](../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_createpixelmap), set [dragPreviewOption](../reference/apis-arkui/drag__and__drop_8h.md#functions) and the touch point, and set the text data for the drag operation.

      ```cpp
      case NODE_ON_TOUCH_INTERCEPT: {
        // Set a PixelMap object.
        uint8_t data[960000];
        size_t dataSize = 960000;
        for (int i = 0; i < dataSize; i++) {
            data[i] = i + 1;
        }
        // Create a parameter structure instance and set parameters.
        OH_Pixelmap_InitializationOptions *createOpts;
        OH_PixelmapInitializationOptions_Create(&createOpts);
        OH_PixelmapInitializationOptions_SetWidth(createOpts, 200);
        OH_PixelmapInitializationOptions_SetHeight(createOpts, 300);
        OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_BGRA_8888);
        OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);
        // Create a Pixelmap instance.
        OH_PixelmapNative *pixelmap = nullptr;
        OH_PixelmapNative_CreatePixelmap(data, dataSize, createOpts, &pixelmap);
        OH_PixelmapNative_Rotate(pixelmap, 90.0);
        OH_PixelmapNative_Opacity(pixelmap, 0.2);
        OH_PixelmapNative_Scale(pixelmap, 0.8, 1.0);
        OH_PixelmapNative_Flip(pixelmap, true, true);
        std::vector<OH_PixelmapNative *> pixelVector;
        pixelVector.push_back(pixelmap);
        int returnValue;
        switch (targetId) {
          case buttonTouch: {
            // CreateDragAction
            auto action1 = OH_ArkUI_CreateDragActionWithNode(node);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_CreateDragActionWithNode returnValue = %{public}p", action1);
            returnValue =
                OH_ArkUI_DragAction_SetPixelMaps(action1, pixelVector.data(), pixelVector.size());
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetPixelMaps returnValue = %{public}d", returnValue);
            // Set DragPreviewOption.
            auto *previewOptions1 = OH_ArkUI_CreateDragPreviewOption();
            OH_ArkUI_DragPreviewOption_SetScaleMode(
                previewOptions1, ArkUI_DragPreviewScaleMode::ARKUI_DRAG_PREVIEW_SCALE_DISABLED);
            OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled(previewOptions1, true);
            OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(previewOptions1, true);
            returnValue = OH_ArkUI_DragAction_SetDragPreviewOption(action1, previewOptions1);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetDragPreviewOption returnValue = %{public}d",
                          returnValue);
            // Set pointerId.
            returnValue = OH_ArkUI_DragAction_SetPointerId(action1, 0); //-1 0 10
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetPointerId returnValue = %{public}d", returnValue);
            // Set the touch point.
            returnValue = OH_ArkUI_DragAction_SetTouchPointX(action1, 200); //-1 0 200
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetTouchPointX returnValue = %{public}d", returnValue);
            returnValue = OH_ArkUI_DragAction_SetTouchPointY(action1, 200); //-1 0 200
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetTouchPointY returnValue = %{public}d", returnValue);
            // Set unifiedData.
            // Create an OH_UdmfRecord object.
            OH_UdmfRecord *record = OH_UdmfRecord_Create();
            // Add plain text data to OH_UdmfRecord.
            OH_UdsPlainText *plainText = OH_UdsPlainText_Create();
            int returnStatus;
            OH_UdsPlainText_SetAbstract(plainText, "this is plainText Abstract example");
            OH_UdsPlainText_SetContent(plainText, "this is plainText Content example");
            returnStatus = OH_UdmfRecord_AddPlainText(record, plainText);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "dragTest OH_UdmfRecord_AddPlainText returnStatus = %{public}d", returnStatus);
            // Create an OH_UdmfData object.
            OH_UdmfData *data = OH_UdmfData_Create();
            // Add OH_UdmfRecord to OH_UdmfData.
            returnStatus = OH_UdmfData_AddRecord(data, record);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "dragTest OH_UdmfData_AddRecord returnStatus = %{public}d", returnStatus);
            returnValue = OH_ArkUI_DragAction_SetData(action1, data);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetData returnValue = %{public}d", returnValue);
            // startDrag
            returnValue = OH_ArkUI_StartDrag(action1);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_StartDrag returnValue = %{public}d", returnValue);
            OH_ArkUI_DragAction_Dispose(action1);
          }
        }
      }
      ```
4. Handle the **NODE_ON_DROP** event.

   In the **NODE_ON_DROP** event, perform actions related to the drop phase. Typically, this involves obtaining the data passed during the drag operation. The drag data from **DragAction** is also obtained through **DragEvent**

    ```cpp
    case NODE_ON_DROP: {
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest", "NODE_ON_DROP EventReceiver");
      // Obtain the UDMF data.
      int returnValue;
      // Create an OH_UdmfData object.
      OH_UdmfData *data = OH_UdmfData_Create();
      returnValue = OH_ArkUI_DragEvent_GetUdmfData(dragEvent, data);
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                    "OH_ArkUI_DragEvent_GetUdmfData returnValue = %{public}d", returnValue);
      // Check whether OH_UdmfData has the required data type.
      bool resultUdmf = OH_UdmfData_HasType(data, UDMF_META_PLAIN_TEXT);
      if (resultUdmf) {
          // Obtain records from OH_UdmfData.
          unsigned int recordsCount = 0;
          OH_UdmfRecord **records = OH_UdmfData_GetRecords(data, &recordsCount);
          // Extract elements from records.
          int returnStatus;
          for (int i = 0; i < recordsCount; i++) {
              // Obtain plain text data from OH_UdmfRecord.
              OH_UdsPlainText *plainTextValue = OH_UdsPlainText_Create();
              returnStatus = OH_UdmfRecord_GetPlainText(records[i], plainTextValue);
              OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                            "dragTest OH_UdmfRecord_GetPlainText "
                            "returnStatus= %{public}d",
                            returnStatus);
              auto getAbstract = OH_UdsPlainText_GetAbstract(plainTextValue);
              auto getContent = OH_UdsPlainText_GetContent(plainTextValue);
              OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                            "OH_UdsPlainText_GetAbstract = "
                            "%{public}s, OH_UdsPlainText_GetContent = "
                            "%{public}s",
                            getAbstract, getContent);
              // Destroy the pointer after use.
              OH_UdsPlainText_Destroy(plainTextValue);
          }
      } else {
          OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                        "OH_UdmfData_HasType not contain UDMF_META_PLAIN_TEXT");
      }
      break;
    }
    ```
