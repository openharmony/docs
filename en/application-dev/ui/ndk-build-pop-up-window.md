# Building a Dialog Box


Display a custom dialog box using a dialog controller, which allows you to set the style and content of the dialog box.


The dialog box APIs are defined within a struct named **ArkUI_NativeDialogAPI_*x***, where *x* represents the version number. These APIs implement various dialog box controls around the dialog controller.


## Creating and Destroying a Dialog Controller

- Create a dialog controller.
  **ArkUI_NativeDialogHandle** represents a pointer to the dialog controller, which you can create by calling the **create** API of **ArkUI_NativeDialogAPI_*x***.

  This API returns data of the **ArkUI_NativeDialogHandle** type.
  ```
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  auto dialogController = dialogAPI->create();
  ```

- Destroy a dialog controller.
  When dialog box operations are no longer needed, actively call the **dispose** API to destroy the dialog controller object.
  ```
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  dialogAPI->dispose(dialogController);
  ```


## Setting Dialog Box Styles

You can set the alignment, offset, corner radius of the background, background color, mask color, and region of the dialog box.

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

2. Control dialog box styles with the controller.
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

3. Close the dialog box when it is not needed.
   ```
   void CloseDialog() {
       ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
       dialogAPI->close(dialogController);
   }
   ```


## Interaction with the Dialog Box

Create an interactive page to open or close a dialog box.

1. Create an interactive page, where a button click triggers the dialog box.
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
       ArkUI_AttributeItem labelItem = {.string = "Click Dialog Box};
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

2. Create a button event callback function to trigger the display or closure of the dialog box when the button is clicked.
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
               ArkUI_AttributeItem labelItem = {.string = "Show Dialog Box"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               CloseDialog();
           } else {
               isShown = true;
               ArkUI_AttributeItem labelItem = {.string = "Close Dialog Box"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               ShowDialog();
           }
       }
   }
   ```

   ![en-us_image_0000001902966196](figures/en-us_image_0000001902966196.gif)
