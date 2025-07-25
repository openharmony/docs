# 拖拽事件

ArkUI开发框架针对拖拽事件提供了[NODE_ON_PRE_DRAG](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)，[NODE_ON_DRAG_START](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)，[NODE_ON_DROP](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)，[NODE_ON_DRAG_ENTER](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)，[NODE_ON_DRAG_MOVE](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)，[NODE_ON_DRAG_LEAVE](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)，[NODE_ON_DRAG_END](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)等组件事件，当拖拽在不同的阶段时会触发对应的组件事件，完成对应的数据处理操作，实现期望的拖拽交互能力。

## 通用拖拽

ArkUI提供了使用C和C++开发拖拽功能的能力，开发者可调用C API实现拖拽功能。以下以Image组件为例，详细介绍实现C API实现拖拽功能的基本步骤，以及在开发过程中需要注意的事项。

1. 组件拖拽设置。

   获取[Node-API](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface)，创建节点等操作均需通过Node-API完成。

    ```cpp
    ArkUI_NativeNodeAPI_1 *nodeAPI = nullptr;
    OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeAPI);
    ```

   创建Image节点，并设置draggable和其它相关属性。

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

2. 自定义拖拽预览和背板图。

   创建[pixelMap](../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap)，设置pixelMap的宽高等各项属性。设置Image节点的[dragPreviewOption](../reference/apis-arkui/capi-drag-and-drop-h.md#函数)，可用于设置跟手图的圆角、角标等。

    ```cpp
      // 创建pixelMap
      uint8_t data[960000];
      size_t dataSize = 960000;
      for (int i = 0; i < dataSize; i++) {
        data[i] = i + 1;
      }
      // 创建参数结构体实例，并设置参数
      OH_Pixelmap_InitializationOptions *createOpts;
      OH_PixelmapInitializationOptions_Create(&createOpts);
      OH_PixelmapInitializationOptions_SetWidth(createOpts, 400);
      OH_PixelmapInitializationOptions_SetHeight(createOpts, 600);
      OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_BGRA_8888);
      OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);
      // 创建Pixelmap实例
      OH_PixelmapNative *pixelmap = nullptr；
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

3. 设置相关事件。

   C API的事件通过统一的回调来接收，当收到事件时通过[eventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)进行区分。

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

4. 处理NODE_ON_DRAG_START事件。

   在NODE_ON_DRAG_START事件中，应用可以执行起拖阶段所需的操作，通常涉及处理起拖过程的数据。例如，创建UdmfRecord，将用于拖拽图片所需的数据 imageUri以fileUri类型添加到[UdmfRecord](../reference/apis-arkdata/capi-udmf-oh-udmfrecord.md)中，接着将UdmfRecord设置到[udmfData](../reference/apis-arkdata/capi-udmf-oh-udmfdata.md)中，最后将UdmfData设置到[DragEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-dragevent.md)中。

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
      returnValue = OH_ArkUI_DragEvent_SetData(dragEvent, data);
      break;
    }
    ```

5. 处理NODE_ON_DROP事件。

   在NODE_ON_DROP事件中，应用可以执行与落入阶段相关的操作，通常需要获取拖拽过程中传递的数据。例如，获取[udmfData](../reference/apis-arkdata/capi-udmf-oh-udmfdata.md)，判断是否存在所需的数据类型，从[UdmfRecord](../reference/apis-arkdata/capi-udmf-oh-udmfrecord.md)中提取相应的数据，最后销毁指针。

    ```cpp
    case NODE_ON_DROP: {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                      "NODE_ON_DRAG_START EventReceiver");
        // 获取UDMF data
        int returnValue;
        // 创建OH_UdmfData对象
        OH_UdmfData *data = OH_UdmfData_Create();
        returnValue = OH_ArkUI_DragEvent_GetUdmfData(dragEvent, data);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                      "OH_ArkUI_DragEvent_GetUdmfData returnValue = %{public}d", returnValue);
        // 判断OH_UdmfData是否有对应的类型
        bool resultUdmf = OH_UdmfData_HasType(data, UDMF_META_GENERAL_FILE);
        if (resultUdmf) {
            // 获取OH_UdmfData的记录
            unsigned int recordsCount = 0;
            OH_UdmfRecord **records = OH_UdmfData_GetRecords(data, &recordsCount);
            // 获取records中的元素
            int returnStatus;
            for (int i = 0; i < recordsCount; i++) {
                // 从OH_UdmfRecord中获取文件类型数据
                OH_UdsFileUri *imageValue = OH_UdsFileUri_Create();
                returnStatus = OH_UdmfRecord_GetFileUri(records[i], imageValue);
                const char* fileUri = OH_UdsFileUri_GetFileUri(imageValue);
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                              "dragTest OH_UdmfRecord_GetPlainText "
                              "returnStatus= %{public}d "
                              "fileUri= %{public}s",
                              returnStatus, fileUri);
                // 使用结束后销毁指针
                OH_UdsFileUri_Destroy(imageValue);
            }
        } else {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_UdmfData_HasType not contain UDMF_META_PLAIN_TEXT");
        }
        break;
    }
    ```

## DragAction主动发起拖拽

除了通用拖拽以外，ArkUI还提供了使用C API实现主动发起拖拽的能力。以下以文本拖拽为例，详细介绍实现C-API实现主动发起拖拽的基本步骤，以及在开发过程中需要注意的事项。

1. 节点注册事件。

   创建Button节点，设置按钮相关属性，同时需要注册[NODE_ON_TOUCH_INTERCEPT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)事件。

    ```cpp
    // buttonTouch作为targetId，用于区分不同target的事件。
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
2. 接收NODE_ON_TOUCH_INTERCEPT事件。

     DragAction主动发起拖拽需通过事件触发，在NODE_ON_TOUCH_INTERCEPT事件中执行发起拖拽所需的操作，通过[targetId](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeevent_gettargetid)区分不同按钮触发的事件。

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
3. 起拖阶段设置。

     在NODE_ON_TOUCH_INTERCEPT事件中，需要对DragAction进行相关设置。为了主动发起拖拽，需要创建[pixelMap](../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap)，设置[dragPreviewOption](../reference/apis-arkui/capi-drag-and-drop-h.md#函数)和跟手点，并将拖拽过程中的文本数据设置到DragAction中。

      ```cpp
      case NODE_ON_TOUCH_INTERCEPT: {
        // 设置pixelMap
        uint8_t data[960000];
        size_t dataSize = 960000;
        for (int i = 0; i < dataSize; i++) {
            data[i] = i + 1;
        }
        // 创建参数结构体实例，并设置参数
        OH_Pixelmap_InitializationOptions *createOpts;
        OH_PixelmapInitializationOptions_Create(&createOpts);
        OH_PixelmapInitializationOptions_SetWidth(createOpts, 200);
        OH_PixelmapInitializationOptions_SetHeight(createOpts, 300);
        OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_BGRA_8888);
        OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);
        // 创建Pixelmap实例
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
            // 创建DragAction
            auto action1 = OH_ArkUI_CreateDragActionWithNode(node);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_CreateDragActionWithNode returnValue = %{public}p", action1);
            returnValue =
                OH_ArkUI_DragAction_SetPixelMaps(action1, pixelVector.data(), pixelVector.size());
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetPixelMaps returnValue = %{public}d", returnValue);
            // 设置DragPreviewOption
            auto *previewOptions1 = OH_ArkUI_CreateDragPreviewOption();
            OH_ArkUI_DragPreviewOption_SetScaleMode(
                previewOptions1, ArkUI_DragPreviewScaleMode::ARKUI_DRAG_PREVIEW_SCALE_DISABLED);
            OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled(previewOptions1, true);
            OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(previewOptions1, true);
            returnValue = OH_ArkUI_DragAction_SetDragPreviewOption(action1, previewOptions1);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetDragPreviewOption returnValue = %{public}d",
                          returnValue);
            // 设置pointerId
            returnValue = OH_ArkUI_DragAction_SetPointerId(action1, 0); // -1 0 10
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetPointerId returnValue = %{public}d", returnValue);
            // 设置touchPoint
            returnValue = OH_ArkUI_DragAction_SetTouchPointX(action1, 200); // -1 0 200
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetTouchPointX returnValue = %{public}d", returnValue);
            returnValue = OH_ArkUI_DragAction_SetTouchPointY(action1, 200); // -1 0 200
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "OH_ArkUI_DragAction_SetTouchPointY returnValue = %{public}d", returnValue);
            // 设置unifiedData
            // 创建OH_UdmfRecord对象
            OH_UdmfRecord *record = OH_UdmfRecord_Create();
            // 向OH_UdmfRecord中添加纯文本类型数据
            OH_UdsPlainText *plainText = OH_UdsPlainText_Create();
            int returnStatus;
            OH_UdsPlainText_SetAbstract(plainText, "this is plainText Abstract example");
            OH_UdsPlainText_SetContent(plainText, "this is plainText Content example");
            returnStatus = OH_UdmfRecord_AddPlainText(record, plainText);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                          "dragTest OH_UdmfRecord_AddPlainText returnStatus = %{public}d", returnStatus);
            // 创建OH_UdmfData对象
            OH_UdmfData *data = OH_UdmfData_Create();
            // 向OH_UdmfData中添加OH_UdmfRecord
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
4. 处理NODE_ON_DROP事件。

   在NODE_ON_DROP事件中，应用可以执行与落入阶段相关的操作。通常情况下，需要从DragEvent中获取拖拽过程中传递的数据，DragAction中的拖拽数据也需要通过DragEvent获取。

    ```cpp
    case NODE_ON_DROP: {
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest", "NODE_ON_DROP EventReceiver");
      // 获取UDMF data
      int returnValue;
      // 创建OH_UdmfData对象
      OH_UdmfData *data = OH_UdmfData_Create();
      returnValue = OH_ArkUI_DragEvent_GetUdmfData(dragEvent, data);
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                    "OH_ArkUI_DragEvent_GetUdmfData returnValue = %{public}d", returnValue);
      // 判断OH_UdmfData是否有对应的类型
      bool resultUdmf = OH_UdmfData_HasType(data, UDMF_META_PLAIN_TEXT);
      if (resultUdmf) {
          // 获取OH_UdmfData的记录
          unsigned int recordsCount = 0;
          OH_UdmfRecord **records = OH_UdmfData_GetRecords(data, &recordsCount);
          // 获取records中的元素
          int returnStatus;
          for (int i = 0; i < recordsCount; i++) {
              // 从OH_UdmfRecord中获取纯文本类型数据
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
              // 使用结束后销毁指针
              OH_UdsPlainText_Destroy(plainTextValue);
          }
      } else {
          OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "dragTest",
                        "OH_UdmfData_HasType not contain UDMF_META_PLAIN_TEXT");
      }
      break;
    }
    ```