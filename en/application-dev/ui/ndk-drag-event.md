# Binding Drag Events

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=4431c59b895d1d02940f60be4527223815858a92 translatedAt=2026-07-09T11:49:44.446Z pushedAt=2026-07-14T02:30:30.758Z -->

The ArkUI framework provides a set of drag event APIs to help you implement drag-and-drop functions. These events include [NODE_ON_PRE_DRAG](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype), [NODE_ON_DRAG_START](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype), [NODE_ON_DROP](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype), [NODE_ON_DRAG_ENTER](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype), [NODE_ON_DRAG_MOVE](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype), [NODE_ON_DRAG_LEAVE](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype), and [NODE_ON_DRAG_END](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype). These events are triggered at different stages of the drag operation, allowing you to perform specific actions and manage the drag interaction as needed.

## Basic Drag Implementation

ArkUI provides the capability to develop drag function using C and C++, allowing you to call C APIs to implement drag features. The following uses the **Image** component as an example to detail the basic steps for implementing drag function with C APIs, as well as considerations during the development process. For the complete sample, see <!--RP1-->[NativeDragDrop](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeDragDrop)<!--RP1End-->.

1. Set a component as draggable.

   Initialize **nodeAPI** using the [OH_ArkUI_GetModuleInterface](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface) API. Node operations, such as creating a node, must be performed through **nodeAPI**.

   <!-- @[get_nodeAPI](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/manager.cpp) -->

   ``` C++
   ArkUI_NativeNodeAPI_1 *nativeNodeAPI = nullptr;
   OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nativeNodeAPI);
   nodeAPI = nativeNodeAPI;
   ```

   Create an **Image** node, use [OH_ArkUI_SetNodeDraggable](../reference/apis-arkui/capi-drag-and-drop-h.md#oh_arkui_setnodedraggable) to set the node to be draggable, and set other related attributes.

   <!-- @[create_imageNode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/thirdmodule.h) -->

   ``` C
   dragImage2 = nodeAPI->createNode(ARKUI_NODE_IMAGE);
   SetId(dragImage2, "dragImage");
   SetCommonAttribute(dragImage2, 140.0f, 140.0f, 0xFFFFFFFF, 5.0f);
   // Replace src/main/resources/base/media/seagull.png with the image resource file you use.
   SetImageSrc(dragImage2, "/resources/base/media/seagull.png");
   OH_ArkUI_SetNodeDraggable(dragImage2, true);
   nodeAPI->registerNodeEvent(dragImage2, NODE_ON_DRAG_START, 1, nullptr);
   ```

   <!-- @[set_common](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/common.h) -->

   ``` C
   #define DEFAULT_WIDTH 200.0
   // Set the node brightness.
   void SetWidth(ArkUI_NodeHandle &node, float width = DEFAULT_WIDTH)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue widthValue[] = {width};
       ArkUI_AttributeItem widthItem = {widthValue, 1};
       nodeAPI->setAttribute(node, NODE_WIDTH, &widthItem);
   }
   
   #define DEFAULT_HEIGHT 200.0
   // Set the node height.
   void SetHeight(ArkUI_NodeHandle &node, float height = DEFAULT_HEIGHT)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue heightValue[] = {height};
       ArkUI_AttributeItem heightItem = {heightValue, 1};
       nodeAPI->setAttribute(node, NODE_HEIGHT, &heightItem);
   }
   
   #define DEFAULT_BG_COLOR 0xFFFFFFFF
   // Set the background color of the node.
   void SetBackgroundColor(ArkUI_NodeHandle &node, uint32_t color = DEFAULT_BG_COLOR)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue colorValue[] = {{.u32 = color}};
       ArkUI_AttributeItem colorItem = {colorValue, 1};
       nodeAPI->setAttribute(node, NODE_BACKGROUND_COLOR, &colorItem);
   }
   
   #define DEFAULT_MARGIN 5.0
   // Set the margin of the node.
   void SetMargin(ArkUI_NodeHandle &node, float margin = DEFAULT_MARGIN)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue marginValue[] = {margin};
       ArkUI_AttributeItem marginItem = {marginValue, 1};
       nodeAPI->setAttribute(node, NODE_MARGIN, &marginItem);
   }
   
   // Set tags for a Button node.
   void SetButtonLabel(ArkUI_NodeHandle &node, const char *label)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_AttributeItem NODE_Button_SRC_Item = {.string = label};
       nodeAPI->setAttribute(node, NODE_BUTTON_LABEL, &NODE_Button_SRC_Item);
   }
   
   // Set the node identifier.
   void SetId(ArkUI_NodeHandle &node, const char *id)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_AttributeItem idItem = {.string = id};
       nodeAPI->setAttribute(node, NODE_ID, &idItem);
   }
   
   #define DEFAULT_BORDER_WIDTH 0.0
   // Set the border width for the node.
   void SetBorderWidth(ArkUI_NodeHandle &node, float width = DEFAULT_BORDER_WIDTH)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue borderWidthValue[] = {width};
       ArkUI_AttributeItem borderWidthItem = {borderWidthValue, 1};
       nodeAPI->setAttribute(node, NODE_BORDER_WIDTH, &borderWidthItem);
   }
   
   #define DEFAULT_BORDER_COLOR 0xFF000000
   // Set the border color of the node.
   void SetBorderColor(ArkUI_NodeHandle &node, uint32_t color = DEFAULT_BORDER_COLOR)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue borderColorValue[] = {{.u32 = color}};
       ArkUI_AttributeItem borderColorItem = {borderColorValue, 1};
       nodeAPI->setAttribute(node, NODE_BORDER_COLOR, &borderColorItem);
   }
   
   // Set common node attributes, such as the width, height, background color, margin, and border style.
   void SetCommonAttribute(ArkUI_NodeHandle &node, float width = DEFAULT_WIDTH, float height = DEFAULT_HEIGHT,
                           unsigned int color = DEFAULT_BG_COLOR, float margin = DEFAULT_MARGIN)
   {
       SetWidth(node, width);
       SetHeight(node, height);
       SetBackgroundColor(node, color);
       SetMargin(node, margin);
       SetBorderWidth(node, DEFAULT_BORDER_WIDTH);
       SetBorderColor(node);
   }
   ```

   <!-- @[set_imageSrc](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/common.h) -->

   ``` C
   void SetImageSrc(ArkUI_NodeHandle &node, const char *src)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_AttributeItem imageSrcItem = {.string = src};
       nodeAPI->setAttribute(node, NODE_IMAGE_SRC, &imageSrcItem);
   }
   ```

2. Customize the drag preview and background image.

   Create a [PixelMap](../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap) object and set its width, height, and other properties. Set [ArkUI_DragPreviewOption](../reference/apis-arkui/capi-arkui-nativemodule-arkui-dragpreviewoption.md) for the **Image** node to customize the rounded corners and badges of the drag preview.

   <!-- @[create_pixelMap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/firstmodule.h) -->

   ``` C
   // Create a PixelMap object.
   uint8_t data[960000];
   size_t dataSize = 960000;
   for (int i = 0; i < dataSize; i++) {
       data[i] = i + 1;
   }
   // Create a parameter structure instance and set parameters.
   OH_Pixelmap_InitializationOptions *createOpts;
   OH_PixelmapInitializationOptions_Create(&createOpts);
   OH_PixelmapInitializationOptions_SetWidth(createOpts, 200U);
   OH_PixelmapInitializationOptions_SetHeight(createOpts, 200U);
   OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_BGRA_8888);
   OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);
   // Define the custom drag preview.
   OH_PixelmapNative *pixelmap = nullptr;
   OH_PixelmapNative_CreatePixelmap(data, dataSize, createOpts, &pixelmap);
   OH_PixelmapNative_Opacity(pixelmap, 0.1f);
   OH_ArkUI_SetNodeDragPreview(node, pixelmap);
   // Set the drag preview configuration options.
   auto *previewOptionsText = OH_ArkUI_CreateDragPreviewOption();
   OH_ArkUI_DragPreviewOption_SetScaleMode(previewOptionsText, ARKUI_DRAG_PREVIEW_SCALE_DISABLED);
   OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled(previewOptionsText, true);
   OH_ArkUI_DragPreviewOption_SetBadgeNumber(previewOptionsText, 10U);
   OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled(previewOptionsText, true);
   OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(previewOptionsText, true);
   int returnValue = OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled(previewOptionsText, true);
   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "Manager",
       "dragTest DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled returnValue = %{public}d",
       returnValue);
   OH_ArkUI_SetNodeDragPreviewOption(node, previewOptionsText);
   ```

3. Set related events.

   Use a unified callback to handle events. Distinguish between different events using [eventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype).

   <!-- @[event_Type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/firstmodule.h) -->

   ``` C
   nodeAPI->addNodeEventReceiver(dragNode, [](ArkUI_NodeEvent *event) {
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "RegisterNodeEventFirstReceiver called");
       auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
       auto preDragStatus = OH_ArkUI_NodeEvent_GetPreDragStatus(event);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "eventType = %{public}d, preDragStatus = %{public}d", eventType, preDragStatus);
       auto *dragEvent = OH_ArkUI_NodeEvent_GetDragEvent(event);
       switch (eventType) {
           case NODE_ON_PRE_DRAG:
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_PRE_DRAG Event Receive");
               break;
           case NODE_ON_CLICK:
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_CLICK Event Receive");
               break;
           case NODE_ON_DROP:
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DROP Event Receive");
               break;
           case NODE_ON_DRAG_ENTER:
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DRAG_ENTER Event Receive");
               break;
           case NODE_ON_DRAG_MOVE:
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DRAG_MOVE Event Receive");
               break;
           case NODE_ON_DRAG_LEAVE:
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DRAG_LEAVE Event Receive");
               break;
           case NODE_ON_DRAG_START: {
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DRAG_START Event Receive");
               // ...
               break;
           }
           case NODE_ON_DRAG_END: {
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DRAG_END Event Receive");
               // ...
               break;
           }
           default:
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "UNKNOWN Event Receive");
               break;
       }
   });
   ```

4. Handle the **NODE_ON_DRAG_START** event.

   In the **NODE_ON_DRAG_START** event, perform operations required to initiate the drag operation, typically involving data processing. For example, create an [OH_UdmfRecord](../reference/apis-arkdata/capi-udmf-oh-udmfrecord.md), add the data **imageValue** required for dragging an image to **OH_UdmfRecord** as the [OH_UdsFileUri](../reference/apis-arkdata/capi-udmf-oh-udsfileuri.md) type, then set **OH_UdmfRecord** into [OH_UdmfData](../reference/apis-arkdata/capi-udmf-oh-udmfdata.md), and finally set **OH_UdmfData** into [DragEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-dragevent.md).

   <!-- @[drag_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/thirdmodule.h) -->

   ``` C
   void SetImageData(ArkUI_DragEvent* dragEvent)
   {
       int returnValue;
       OH_UdmfRecord *record = OH_UdmfRecord_Create();
       OH_UdsFileUri *imageValue = OH_UdsFileUri_Create();
       // Replace src/main/resources/base/media/seagull.png with the image resource file you use.
       returnValue = OH_UdsFileUri_SetFileUri(imageValue, "/resources/base/media/seagull.png");
       returnValue = OH_UdmfRecord_AddFileUri(record, imageValue);
       OH_UdmfData *data = OH_UdmfData_Create();
       returnValue = OH_UdmfData_AddRecord(data, record);
       returnValue = OH_ArkUI_DragEvent_SetData(dragEvent, data);
   }
   // ...
               case NODE_ON_DRAG_START: {
                   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DRAG_START EventReceiver");
                   SetImageData(dragEvent);
                   break;
               }
   ```

5. Handle the **NODE_ON_DROP** event.

   In the **NODE_ON_DROP** event, perform operations related to the drop phase, typically involving retrieving the data passed during the drag process. For example, import the [udmf_meta.h](../reference/apis-arkdata/capi-udmf-meta-h.md) file, obtain [OH_UdmfData](../reference/apis-arkdata/capi-udmf-oh-udmfdata.md), check whether the required data type exists, extract the corresponding data from [OH_UdmfRecord](../reference/apis-arkdata/capi-udmf-oh-udmfrecord.md), and destroy the pointer.

   <!-- @[on_drop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/firstmodule.h) --> 

   ``` C
   void GetDragData(ArkUI_DragEvent* dragEvent)
   {
       // Obtain the UDMF data.
       int returnValue;
       // Create an OH_UdmfData object.
       OH_UdmfData *data = OH_UdmfData_Create();
       returnValue = OH_ArkUI_DragEvent_GetUdmfData(dragEvent, data);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
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
               const char *fileUri = OH_UdsFileUri_GetFileUri(imageValue);
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
                   "dragTest OH_UdsFileUri_GetFileUri "
                   "returnStatus= %{public}d "
                   "fileUri= %{public}s",
                   returnStatus, fileUri);
               // Destroy the pointer after use.
               OH_UdsFileUri_Destroy(imageValue);
           }
           if (recordsCount != 0) {
               OH_ArkUI_DragEvent_SetDragResult(dragEvent, ARKUI_DRAG_RESULT_SUCCESSFUL);
               ArkUI_DropOperation option;
               OH_ArkUI_DragEvent_GetDropOperation(dragEvent, &option);
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
                   "OH_ArkUI_DragEvent_GetDropOperation returnValue = %{public}d", option);
           }
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
               "OH_UdmfData_HasType not contain UDMF_META_GENERAL_FILE");
       }
       int32_t count;
       OH_ArkUI_DragEvent_GetDataTypeCount(dragEvent, &count);
       if (count <= 0 || count >= 128U) {
           return;
       }
       char **eventTypeArray = new char *[count];
       for (int i = 0; i < count; i++) {
           eventTypeArray[i] = new char[128U];
       }
       OH_ArkUI_DragEvent_GetDataTypes(dragEvent, eventTypeArray, count, 128U);
       for (int i = 0; i < count; i++) {
           OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
               "OH_ArkUI_DragEvent_GetDataTypes returnValue = %{public}s", eventTypeArray[i]);
       }
   }
   // ...
               case NODE_ON_DROP: {
                   OH_ArkUI_DragEvent_SetSuggestedDropOperation(dragEvent, ARKUI_DROP_OPERATION_COPY);
                   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DROP EventReceiver");
                   GetDragData(dragEvent);
                   break;
               }
   ```

## Initiating a Drag Operation

In addition to basic drag, ArkUI also provides the capability to actively initiate drag operations using C APIs. The following uses text dragging as an example to detail the basic steps for implementing active drag initiation with C APIs, as well as considerations during the development process. For the complete sample, see <!--RP1-->[NativeDragDrop](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeDragDrop)<!--RP1End-->.

1. Register node events.

   Create a **Button** node, set its attributes, and register the [NODE_ON_TOUCH_INTERCEPT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) event.

   <!-- @[touch_intercept](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/forthmodule.h) -->

   ``` C
   // Use buttonTouch as targetId to distinguish events from different targets.
   enum {
       BUTTON_TOUCH = 1
   };
   
   dragButton = nodeAPI->createNode(ARKUI_NODE_BUTTON);
   SetId(dragButton, "dragBt3");
   SetCommonAttribute(dragButton, 80.0f, 50.0f, 0xFFFF0000, 20.0f);
   SetButtonLabel(dragButton, "Drag");
   nodeAPI->registerNodeEvent(dragButton, NODE_ON_TOUCH_INTERCEPT, BUTTON_TOUCH, nullptr);
   ```

   <!-- @[set_common](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/common.h) -->

   ``` C
   #define DEFAULT_WIDTH 200.0
   // Set the node brightness.
   void SetWidth(ArkUI_NodeHandle &node, float width = DEFAULT_WIDTH)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue widthValue[] = {width};
       ArkUI_AttributeItem widthItem = {widthValue, 1};
       nodeAPI->setAttribute(node, NODE_WIDTH, &widthItem);
   }
   
   #define DEFAULT_HEIGHT 200.0
   // Set the node height.
   void SetHeight(ArkUI_NodeHandle &node, float height = DEFAULT_HEIGHT)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue heightValue[] = {height};
       ArkUI_AttributeItem heightItem = {heightValue, 1};
       nodeAPI->setAttribute(node, NODE_HEIGHT, &heightItem);
   }
   
   #define DEFAULT_BG_COLOR 0xFFFFFFFF
   // Set the background color of the node.
   void SetBackgroundColor(ArkUI_NodeHandle &node, uint32_t color = DEFAULT_BG_COLOR)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue colorValue[] = {{.u32 = color}};
       ArkUI_AttributeItem colorItem = {colorValue, 1};
       nodeAPI->setAttribute(node, NODE_BACKGROUND_COLOR, &colorItem);
   }
   
   #define DEFAULT_MARGIN 5.0
   // Set the margin of the node.
   void SetMargin(ArkUI_NodeHandle &node, float margin = DEFAULT_MARGIN)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue marginValue[] = {margin};
       ArkUI_AttributeItem marginItem = {marginValue, 1};
       nodeAPI->setAttribute(node, NODE_MARGIN, &marginItem);
   }
   
   // Set tags for a Button node.
   void SetButtonLabel(ArkUI_NodeHandle &node, const char *label)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_AttributeItem NODE_Button_SRC_Item = {.string = label};
       nodeAPI->setAttribute(node, NODE_BUTTON_LABEL, &NODE_Button_SRC_Item);
   }
   
   // Set the node identifier.
   void SetId(ArkUI_NodeHandle &node, const char *id)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_AttributeItem idItem = {.string = id};
       nodeAPI->setAttribute(node, NODE_ID, &idItem);
   }
   
   #define DEFAULT_BORDER_WIDTH 0.0
   // Set the border width for the node.
   void SetBorderWidth(ArkUI_NodeHandle &node, float width = DEFAULT_BORDER_WIDTH)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue borderWidthValue[] = {width};
       ArkUI_AttributeItem borderWidthItem = {borderWidthValue, 1};
       nodeAPI->setAttribute(node, NODE_BORDER_WIDTH, &borderWidthItem);
   }
   
   #define DEFAULT_BORDER_COLOR 0xFF000000
   // Set the border color of the node.
   void SetBorderColor(ArkUI_NodeHandle &node, uint32_t color = DEFAULT_BORDER_COLOR)
   {
       if (!nodeAPI) {
           return;
       }
       ArkUI_NumberValue borderColorValue[] = {{.u32 = color}};
       ArkUI_AttributeItem borderColorItem = {borderColorValue, 1};
       nodeAPI->setAttribute(node, NODE_BORDER_COLOR, &borderColorItem);
   }
   
   // Set common node attributes, such as the width, height, background color, margin, and border style.
   void SetCommonAttribute(ArkUI_NodeHandle &node, float width = DEFAULT_WIDTH, float height = DEFAULT_HEIGHT,
                           unsigned int color = DEFAULT_BG_COLOR, float margin = DEFAULT_MARGIN)
   {
       SetWidth(node, width);
       SetHeight(node, height);
       SetBackgroundColor(node, color);
       SetMargin(node, margin);
       SetBorderWidth(node, DEFAULT_BORDER_WIDTH);
       SetBorderColor(node);
   }
   ```

2. Receive the **NODE_ON_TOUCH_INTERCEPT** event.

   In the **NODE_ON_TOUCH_INTERCEPT** event, you need to set up **DragAction** to initiate the drag operation. Use [targetId](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeevent_gettargetid) to distinguish events triggered by different buttons.

   <!-- @[on_touchIntercept](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/forthmodule.h) -->

   ``` C
   nodeAPI->addNodeEventReceiver(dragButton, [](ArkUI_NodeEvent *event) {
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "RegisterNodeEventForthReceiver called");
       auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
       auto preDragStatus = OH_ArkUI_NodeEvent_GetPreDragStatus(event);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "eventType = %{public}d, preDragStatus = %{public}d", eventType, preDragStatus);
   
       auto *dragEvent = OH_ArkUI_NodeEvent_GetDragEvent(event);
       switch (eventType) {
           case NODE_ON_TOUCH_INTERCEPT: {
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_TOUCH_INTERCEPT EventReceiver");
               // ...
               break;
           }
           default: {
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "UNKNOWN EventReceiver");
               break;
           }
       }
   });
   ```

3. Set the drag initiation phase.

   In the **NODE_ON_TOUCH_INTERCEPT** event, set **DragAction** to initiate the drag operation. Create a [PixelMap](../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap), set [ArkUI_DragPreviewOption](../reference/apis-arkui/capi-arkui-nativemodule-arkui-dragpreviewoption.md) and the touch point, and set the text data to **DragAction**.

   <!-- @[set_dragAction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/forthmodule.h) -->

   ``` C
               case NODE_ON_TOUCH_INTERCEPT: {
                   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_TOUCH_INTERCEPT EventReceiver");
                   // Create a DragAction object.
                   action = OH_ArkUI_CreateDragActionWithNode(dragButton);
                   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
                       "OH_ArkUI_CreateDragActionWithNode returnValue = %{public}p", action);
                   // Set a PixelMap object.
                   std::vector<OH_PixelmapNative *> pixelVector;
                   SetPixelMap(pixelVector);
                   // Set DragPreviewOption.
                   SetDragPreviewOption();
                   // Set pointerId and touchPoint.
                   PrintDragActionInfos();
                   // Set unifiedData.
                   SetDragActionData();
                   // startDrag
                   int returnValue = OH_ArkUI_StartDrag(action);
                   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
                       "OH_ArkUI_StartDrag returnValue = %{public}d",
                       returnValue);
                   if (returnValue != ARKUI_ERROR_CODE_NO_ERROR && action) {
                       OH_ArkUI_DragAction_UnregisterStatusListener(action);
                       OH_ArkUI_DragAction_Dispose(action);
                       ReleaseDragUdmfData();
                       ReleaseDragPixelMaps();
                       action = nullptr;
                   }
                   break;
               }
               // ...
   void SetDragActionData()
   {
       // Create an OH_UdmfRecord object.
       OH_UdmfRecord *record = OH_UdmfRecord_Create();
       // Add plain text data to OH_UdmfRecord.
       OH_UdsPlainText *plainText = OH_UdsPlainText_Create();
       int returnStatus;
       OH_UdsPlainText_SetAbstract(plainText, "this is plainText Abstract example");
       OH_UdsPlainText_SetContent(plainText, "this is plainText Content example");
       returnStatus = OH_UdmfRecord_AddPlainText(record, plainText);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "dragTest OH_UdmfRecord_AddPlainText returnStatus = %{public}d", returnStatus);
       // Create an OH_UdmfData object.
       ReleaseDragUdmfData();
       OH_UdmfData *data = OH_UdmfData_Create();
       dragUdmfData = data;
       // Add OH_UdmfRecord to OH_UdmfData.
       returnStatus = OH_UdmfData_AddRecord(data, record);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "dragTest OH_UdmfData_AddRecord returnStatus = %{public}d", returnStatus);
       int returnValue = OH_ArkUI_DragAction_SetData(action, data);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "OH_ArkUI_DragAction_SetData returnValue = %{public}d", returnValue);
       // Register a drag status listener.
       OH_ArkUI_DragAction_RegisterStatusListener(action, data, &DragStatusListener);
   }
   ```

   <!-- @[prepare_dragAction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/common.h) -->

   ``` C
   void SetPixelMap(std::vector<OH_PixelmapNative *> &pixelVector)
   {
       uint8_t data[960000];
       size_t dataSize = 960000;
       for (int i = 0; i < dataSize; i++) {
           data[i] = i + 1;
       }
       // Create a parameter structure instance and set parameters.
       OH_Pixelmap_InitializationOptions *createOpts = nullptr;
       OH_PixelmapInitializationOptions_Create(&createOpts);
       if (!createOpts) {
           return;
       }
       OH_PixelmapInitializationOptions_SetWidth(createOpts, 200U);
       OH_PixelmapInitializationOptions_SetHeight(createOpts, 300U);
       OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_BGRA_8888);
       OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);
       // Create a Pixelmap instance.
       OH_PixelmapNative *pixelmap = nullptr;
       OH_PixelmapNative_CreatePixelmap(data, dataSize, createOpts, &pixelmap);
       OH_PixelmapInitializationOptions_Release(createOpts);
       if (!pixelmap) {
           return;
       }
       OH_PixelmapNative_Flip(pixelmap, true, true);
       pixelVector.push_back(pixelmap);
       int returnValue = OH_ArkUI_DragAction_SetPixelMaps(action, pixelVector.data(), pixelVector.size());
       if (returnValue == ARKUI_ERROR_CODE_NO_ERROR) {
           dragPixelMaps.push_back(pixelmap);
       } else {
           OH_PixelmapNative_Release(pixelmap);
       }
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "OH_ArkUI_DragAction_SetPixelMaps returnValue = %{public}d", returnValue);
   }
   
   void SetDragPreviewOption()
   {
       auto *previewOptions = OH_ArkUI_CreateDragPreviewOption();
       OH_ArkUI_DragPreviewOption_SetScaleMode(previewOptions,
           ArkUI_DragPreviewScaleMode::ARKUI_DRAG_PREVIEW_SCALE_DISABLED);
       OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled(previewOptions, true);
       OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled(previewOptions, true);
       int returnValue = OH_ArkUI_DragAction_SetDragPreviewOption(action, previewOptions);
       OH_ArkUI_DragPreviewOption_Dispose(previewOptions);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "OH_ArkUI_DragAction_SetDragPreviewOption returnValue = %{public}d", returnValue);
   }
   
   void PrintDragActionInfos()
   {
       // Set pointerId.
       int returnValue = OH_ArkUI_DragAction_SetPointerId(action, 0);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "OH_ArkUI_DragAction_SetPointerId returnValue = %{public}d", returnValue);
       // Set the touch point.
       returnValue = OH_ArkUI_DragAction_SetTouchPointX(action, 200.0f);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "OH_ArkUI_DragAction_SetTouchPointX returnValue = %{public}d", returnValue);
       returnValue = OH_ArkUI_DragAction_SetTouchPointY(action, 200.0f);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
           "OH_ArkUI_DragAction_SetTouchPointY returnValue = %{public}d", returnValue);
   }
   ```

4. Handle the **NODE_ON_DROP** event.

   In the **NODE_ON_DROP** event, perform actions related to the drop phase. Typically, this involves obtaining the data passed during the drag operation. The drag data from **DragAction** is also obtained through **DragEvent**

   <!-- @[get_dragAction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDragDrop/entry/src/main/cpp/forthmodule.h) -->

   ``` C
               case NODE_ON_DROP: {
                   OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest", "NODE_ON_DROP EventReceiver");
                   GetUdmfDataText(dragEvent);
                   break;
               }
               // ...
   void GetUdmfDataText(ArkUI_DragEvent* dragEvent)
   {
       // Obtain the UDMF data.
       int returnValue;
       // Create an OH_UdmfData object.
       OH_UdmfData *data = OH_UdmfData_Create();
       returnValue = OH_ArkUI_DragEvent_GetUdmfData(dragEvent, data);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
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
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
                   "dragTest OH_UdmfRecord_GetPlainText "
                   "returnStatus= %{public}d",
                   returnStatus);
               auto getAbstract = OH_UdsPlainText_GetAbstract(plainTextValue);
               auto getContent = OH_UdsPlainText_GetContent(plainTextValue);
               OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
                   "OH_UdsPlainText_GetAbstract = "
                   "%{public}s, OH_UdsPlainText_GetContent = "
                   "%{public}s",
                   getAbstract, getContent);
               // Destroy the pointer after use.
               OH_UdsPlainText_Destroy(plainTextValue);
           }
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00U, "dragTest",
               "OH_UdmfData_HasType not contain UDMF_META_PLAIN_TEXT");
       }
       OH_UdmfData_Destroy(data);
   }
   ```