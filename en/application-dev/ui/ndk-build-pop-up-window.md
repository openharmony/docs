# Building a Dialog Box


You can display a custom dialog box by creating a dialog controller or by creating a custom dialog content object, and then setting its styles and content.


[Displaying a custom dialog box through a dialog controller](#displaying-a-custom-dialog-box-through-a-dialog-controller): In this approach, you use the APIs defined in a struct named **ArkUI_NativeDialogAPI_x** (where *x* denotes the version) for dialog box control.


[Displaying a custom dialog box through a custom dialog content object](#displaying-a-custom-dialog-box-through-a-custom-dialog-content-object): In this approach, you use the APIs defined in the functions of [native_dialog.h](../reference/apis-arkui/native__dialog_8h.md#functions).


> **NOTE**
>
> - For details about how to display a custom dialog box through a dialog controller, see [openCustomDialogWithController](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialogwithcontroller18).
> 
> - For details about how to display a custom dialog box through a custom dialog content object, see [openCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialog12).
> 
> - [OH_ArkUI_QueryModuleInterfaceByName](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_querymoduleinterfacebyname) is used to obtain a collection of native module APIs of a specified type. You can call APIs in the native module using the returned data of the **ArkUI_NativeDialogHandle** type.

## Creating and Destroying a Custom Dialog Box

### Displaying a Custom Dialog Box Through a Dialog Controller

- Creating a Dialog Controller
  [ArkUI_NativeDialogHandle](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nativedialoghandle) represents a pointer to the dialog controller, which you can create by calling the [create](../reference/apis-arkui/_ark_u_i___native_dialog_a_p_i__1.md#create) API of [ArkUI_NativeDialogAPI_x](../reference/apis-arkui/_ark_u_i___native_dialog_a_p_i__1.md).
This API returns data of the **ArkUI_NativeDialogHandle** type.
  ```
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  auto dialogController = dialogAPI->create();
  ```

- Destroying the Dialog Controller<br>When dialog box operations are no longer needed, actively call the **dispose** API to destroy the dialog controller object.
  ```
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  dialogAPI->dispose(dialogController);
  ```

### Displaying a Custom Dialog Box Through a Custom Dialog Content Object

- Creating a Dialog Content Object
  You can create a custom dialog content object [ArkUI_CustomDialogOptions](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_customdialogoptions) by calling the [OH_ArkUI_CustomDialog_CreateOptions](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_customdialog_createoptions) API,
which returns a pointer of the **ArkUI_CustomDialogOptions** type.
  ```
  auto textNode = std::make_shared<ArkUITextNode>();
  auto dialogOptions = OH_ArkUI_CustomDialog_CreateOptions(textNode->GetHandle());
  ```
  > **NOTE**
  > 
  > For details about how to declare **ArkUITextNode**, refer to the implementation of the text component in the [ArkUINode.h](../ui/ndk-access-the-arkts-page.md) file.

- Destroying a Dialog Content Object<br>When dialog box operations are no longer needed, actively call the [OH_ArkUI_CustomDialog_DisposeOptions](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_customdialog_disposeoptions) API to destroy the dialog content object.
  ```
  OH_ArkUI_CustomDialog_DisposeOptions(dialogOptions);
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

2. Control dialog box styles using either of the following methods. For details about the dialog box APIs, see [native_dialog.h](../reference/apis-arkui/native__dialog_8h.md).

- Using the controller
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

- Using **dialogOptions**
   ```
   constexpr int32_t id = 0;
   void openDialogCallBack(int32_t dialogId) {
       id = dialogId;
   }
   void OpenCustomDialog() {
       auto contentNode = CreateDialogContent();
       auto dialogOptions = OH_ArkUI_CustomDialog_CreateOptions(contentNode);
       OH_ArkUI_CustomDialog_SetAlignment(dialogOptions, static_cast<int32_t>(ARKUI_ALIGNMENT_BOTTOM), 0, 0);
       OH_ArkUI_CustomDialog_SetBackgroundColor(dialogOptions, 0xffffffff);
       OH_ArkUI_CustomDialog_SetCornerRadius(dialogOptions, 6, 6, 6, 6);
       OH_ArkUI_CustomDialog_SetModalMode(dialogOptions, false);
       OH_ArkUI_CustomDialog_SetAutoCancel(dialogOptions, true);
       OH_ArkUI_CustomDialog_SetBorderWidth(dialogOptions, 2, 2, 2, 2, ARKUI_LENGTH_METRIC_UNIT_PX);
       OH_ArkUI_CustomDialog_SetBorderStyle(dialogOptions, ARKUI_BORDER_STYLE_SOLID, ARKUI_BORDER_STYLE_SOLID,ARKUI_BORDER_STYLE_SOLID, ARKUI_BORDER_STYLE_SOLID);
       OH_ArkUI_CustomDialog_OpenDialog(dialogOptions, openDialogCallBack);
   }
   ```

3. Close the dialog box using either of the following methods:

- Using the controller
   ```
   void CloseDialog() {
       ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
       dialogAPI->close(dialogController);
   }
   ```

- Using **dialogOptions**
   ```
   void CloseCustomDialog() {
       OH_ArkUI_CustomDialog_CloseDialog(id);
   }
   ```

## Interacting with the Dialog Box

You can create an interactive page to open or close a dialog box.

1. Create a button that, when clicked, will trigger the display of a dialog box. For details about how to obtain and use nodes of the ArkUI_NodeContentHandle type, see [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md).
   ```
   constexpr int32_t BUTTON_CLICK_ID = 1;
   bool isShown = false;
   ArkUI_NativeDialogHandle dialogController;
   ArkUI_NodeHandle buttonNode;
   
   void MainViewMethod(ArkUI_NodeContentHandle handle) {
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
       ArkUI_AttributeItem labelItem = {.string = "Click Dialog Box"};
       nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
       ArkUI_NumberValue buttonTypeValue[] = {{.i32 = static_cast<int32_t>(ARKUI_BUTTON_TYPE_NORMAL)}};
       ArkUI_AttributeItem buttonTypeItem = {.value = buttonTypeValue,
                                             .size = sizeof(buttonTypeValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(buttonNode, NODE_BUTTON_TYPE, &buttonTypeItem);
       nodeAPI->registerNodeEvent(buttonNode, NODE_ON_CLICK, BUTTON_CLICK_ID, nullptr);
       nodeAPI->addNodeEventReceiver(buttonNode, OnButtonClicked);
       nodeAPI->addChild(column, buttonNode);
       OH_ArkUI_NodeContent_AddNode(handle, column);
   }
   ```

2. Create a button event callback function to trigger the display or closure of the dialog box when the button is clicked.

- Using the controller
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

- Using **dialogOptions**
   ```
   constexpr int32_t id = 0;
   void openDialogCallBack(int32_t dialogId) {
       id = dialogId;
   }
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
               CloseCustomDialog();
           } else {
               isShown = true;
               ArkUI_AttributeItem labelItem = {.string = "Close Dialog Box"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               OpenCustomDialog();
           }
       }
   }
   ```

   ![en-us_image_0000001902966196](figures/en-us_image_0000001902966196.gif)


## Managing the Dialog Box Lifecycle

Dialog boxes have four lifecycle events: **registerOnWillAppear**, **registerOnDidAppear**, **registerOnWillDisappear**, and **registerOnDidDisappear**.
These lifecycle APIs must be called before the **show** API is invoked. The sequence of lifecycle events is as follows:
registerOnWillAppear -> The dialog box display animation starts -> The dialog box display animation ends -> registerOnDidAppear -> The dialog box is fully displayed ->
registerOnWillDisappear -> The dialog box exit animation starts -> The dialog box exit animation ends -> registerOnDidDisappear -> The dialog box is fully closed

The following is an example of creating a dialog box that triggers lifecycle callback functions when the dialog box is displayed and closed. For details about how to obtain and use nodes of the ArkUI_NodeContentHandle type, see [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md).
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
    void OnWillAppearCallBack(void* userdata) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "CustomDialogContentTest", "OnWillAppearCallBack");
    }
    void OnDidAppearCallBack(void* userdata) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "CustomDialogContentTest", "OnDidAppearCallBack");
    }
    void OnWillDisappearCallBack(void* userdata) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "CustomDialogContentTest", "OnWillDisappearCallBack");
    }
    void OnDidDisappearCallBack(void* userdata) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "CustomDialogContentTest", "OnDidDisappearCallBack");
    }
    void ShowDialog() {
        ArkUI_NativeDialogAPI_3 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_3 *>(
            OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_3"));
        auto customDialog = dialogAPI->nativeDialogAPI1.create();
        auto contentNode = CreateDialogContent();
        dialogAPI->nativeDialogAPI1.setContent(customDialog, contentNode);
        dialogAPI->nativeDialogAPI1.setAutoCancel(customDialog, true);
        dialogAPI->registerOnWillAppear(customDialog, nullptr, OnWillAppearCallBack);
        dialogAPI->registerOnDidAppear(customDialog, nullptr, OnDidAppearCallBack);
        dialogAPI->registerOnWillDisappear(customDialog, nullptr, OnWillDisappearCallBack);
        dialogAPI->registerOnDidDisappear(customDialog, nullptr, OnDidDisappearCallBack);
        dialogAPI->nativeDialogAPI1.show(customDialog, false);
    }
   ```
