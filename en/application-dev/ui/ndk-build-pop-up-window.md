# Building Dialog Boxes

You can display a custom dialog box through a dialog box controller, which allows you to set its style and content.

The dialog box interface set is defined within a struct, named ArkUI_NativeDialogAPI_x (where x denotes the version). These interfaces implement various popup controls centered around the popup controller.

## Creating and Destroying Dialog Box Controllers

- Creating a Dialog Box Controller
  ArkUI_NativeDialogHandle represents a pointer to the dialog box controller, which can be created by calling the create interface of ArkUI_NativeDialogAPI_x.

  This method returns data of the ArkUI_NativeDialogHandle type.
  ```
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  auto dialogController = dialogAPI->create();
  ```

- Destroying a Popup Controller
  When dialog box operations are no longer needed, you should actively call the dispose API to destroy the dialog box controller object.

  ```
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  dialogAPI->dispose(dialogController);
  ```


## Setting Dialog Box Styles

You can set the dialog box alignment, offset, corner radius of the popup background, background color, overlay color, area, and more.

1. Create a dialog box content node.
   ```
   ArkUI_NodeHandle CreateDialogContent() {
       ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       ArkUI_NodeHandle text = nodeAPI->createNode(ARKUI_NODE_TEXT);
       ArkUI_NumberValue textWidthValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem textWidthItem = {.value = textWidthValue,
                                            .size = sizeof(textWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(text, NODE_WIDTH, &textWidthItem);
       ArkUI_NumberValue textHeightValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem textHeightItem = {.value = textHeightValue,
                                             .size = sizeof(textWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(text, NODE_HEIGHT, &textHeightItem);
       ArkUI_NodeHandle span = nodeAPI->createNode(ARKUI_NODE_SPAN);
       ArkUI_AttributeItem spanItem = {.string = "This is a dialog box"};
       nodeAPI->setAttribute(span, NODE_SPAN_CONTENT, &spanItem);
       ArkUI_NodeHandle imageSpan = nodeAPI->createNode(ARKUI_NODE_IMAGE_SPAN);
       ArkUI_AttributeItem imageSpanItem = {.string = "/pages/common/sky.jpg"};
       nodeAPI->setAttribute(imageSpan, NODE_IMAGE_SPAN_SRC, &imageSpanItem);
       ArkUI_NumberValue imageSpanWidthValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem imageSpanWidthItem = {.value = imageSpanWidthValue,
                                                 .size = sizeof(textWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(imageSpan, NODE_WIDTH, &imageSpanWidthItem);
       ArkUI_NumberValue imageSpanHeightValue[] = {{.f32 = 200}};
       ArkUI_AttributeItem imageSpanHeightItem = {.value = imageSpanHeightValue,
                                                  .size = sizeof(textWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(imageSpan, NODE_HEIGHT, &imageSpanHeightItem);
       nodeAPI->addChild(text, span);
       nodeAPI->addChild(text, imageSpan);
       return text;
   }
   ```

2. Control dialog box styles through the controller.
   ```
   void ShowDialog() {
       ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
       if (!dialogController) {
           dialogController = dialogAPI->create();
       }
       auto contentNode = CreateDialogContent();
       dialogAPI->setContent(dialogController, contentNode);
       dialogAPI->setContentAlignment(dialogController, static_cast<int32_t>(ARKUI_ALIGNMENT_BOTTOM), 0, 0);
       dialogAPI->setBackgroundColor(dialogController, 0xffffffff);
       dialogAPI->setCornerRadius(dialogController, 6, 6, 6, 6);
       dialogAPI->setModalMode(dialogController, false);
       dialogAPI->setAutoCancel(dialogController, true);
       dialogAPI->show(dialogController, false);
   }
   ```

3. Close the dialog box when not needed.
   ```
   void CloseDialog() {
       ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
       dialogAPI->close(dialogController);
   }
   ```


## Dialog Box Interaction

You can create an interactive page to open or close the dialog box.

1. Create an interactive page, where you can display a dialog box by clicking a button.
   ```
   constexpr int32_t BUTTON_CLICK_ID = 1;
   bool isShown = false;
   ArkUI_NativeDialogHandle dialogController;
   ArkUI_NodeHandle buttonNode;
   
   void MainViewMethod(OH_NativeXComponent *component) {
       ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
       ArkUI_NumberValue widthValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem widthItem = {.value = widthValue, .size = sizeof(widthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(column, NODE_WIDTH, &widthItem);
       ArkUI_NumberValue heightValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem heightItem = {.value = heightValue, .size = sizeof(heightValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(column, NODE_HEIGHT, &heightItem);
       
       buttonNode = nodeAPI->createNode(ARKUI_NODE_BUTTON);
       ArkUI_NumberValue buttonWidthValue[] = {{.f32 = 200}};
       ArkUI_AttributeItem buttonWidthItem = {.value = buttonWidthValue,
                                              .size = sizeof(buttonWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(buttonNode, NODE_WIDTH, &buttonWidthItem);
       ArkUI_NumberValue buttonHeightValue[] = {{.f32 = 50}};
       ArkUI_AttributeItem buttonHeightItem = {.value = buttonHeightValue,
                                               .size = sizeof(buttonHeightValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(buttonNode, NODE_HEIGHT, &buttonHeightItem);
       ArkUI_AttributeItem labelItem = {.string = "Touch dialog box"};
       nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
       ArkUI_NumberValue buttonTypeValue[] = {{.i32 = static_cast<int32_t>(ARKUI_BUTTON_TYPE_NORMAL)}};
       ArkUI_AttributeItem buttonTypeItem = {.value = buttonTypeValue,
                                             .size = sizeof(buttonTypeValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(buttonNode, NODE_BUTTON_TYPE, &buttonTypeItem);
       nodeAPI->registerNodeEvent(buttonNode, NODE_ON_CLICK, BUTTON_CLICK_ID, nullptr);
       nodeAPI->addNodeEventReceiver(buttonNode, OnButtonClicked);
       nodeAPI->addChild(column, buttonNode);
       OH_NativeXComponent_AttachNativeRootNode(component, column);
   }
   ```

2. To trigger the display or closure of a dialog box when a button is clicked, you can create a callback function for the button event as follows:
   ```
   void OnButtonClicked(ArkUI_NodeEvent *event) {
       if (!event || !buttonNode) {
           return;
       }
       auto eventId = OH_ArkUI_NodeEvent_GetTargetId(event);
       if (eventId == BUTTON_CLICK_ID) {
           ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
               OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
           if (isShown) {
               isShown = false;
               ArkUI_AttributeItem labelItem = {.string = "Show dialog box"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               CloseDialog();
           } else {
               isShown = true;
               ArkUI_AttributeItem labelItem = {.string = "Close dialog box"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               ShowDialog();
           }
       }
   }
   ```

   ![en-us_image_0000001902966196](figures/en-us_image_0000001902966196.gif)
