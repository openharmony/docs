# Building a Dialog Box
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyi0309-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->


You can display a custom dialog box by creating a dialog controller or by creating a custom dialog content object, and then setting its styles and content.


[Displaying a custom dialog box through a dialog controller](#displaying-a-custom-dialog-box-through-a-dialog-controller): In this approach, you use the APIs defined in a struct named **ArkUI_NativeDialogAPI_x** (where *x* denotes the version) for dialog box control. It is supported since API version 12. For details about the usage, see [openCustomDialogWithController](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialogwithcontroller18).


[Displaying a custom dialog box through a custom dialog content object](#displaying-a-custom-dialog-box-through-a-custom-dialog-content-object): In this approach, you use the APIs defined in the functions of [native_dialog.h](../reference/apis-arkui/capi-native-dialog-h.md#functions). It is supported since API version 19. For details about the usage, see [openCustomDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialog12).


> **NOTE**
>
> - [OH_ArkUI_QueryModuleInterfaceByName](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_querymoduleinterfacebyname) is used to obtain a collection of native module APIs of a specified type. You can call APIs in the native module using the returned data of the **ArkUI_NativeDialogHandle** type.

## Creating and Destroying a Custom Dialog Box

### Displaying a Custom Dialog Box Through a Dialog Controller

- Creating a dialog controller

  [ArkUI_NativeDialogHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialog8h.md) represents a pointer to the dialog controller, which you can create by calling the [create](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-1.md#create) API of [ArkUI_NativeDialogAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-1.md).

  This API returns data of the **ArkUI_NativeDialogHandle** type.
  <!-- @[dialog_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
  
  ``` C++
  ArkUI_NativeDialogHandle g_dialogController = nullptr;
  // ···
      ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
          OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
      if (!g_dialogController) {
          g_dialogController = dialogAPI->create();
      }
  ```

- Destroying the dialog controller<br>When dialog operations are no longer needed, actively call the [dispose](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-1.md#dispose) API to destroy the dialog controller object.
  <!-- @[dialog_dispose](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
  
  ``` C++
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  dialogAPI->dispose(g_dialogController);
  g_dialogController = nullptr;
  ```

### Displaying a Custom Dialog Box Through a Custom Dialog Content Object

- Creating a dialog content object

  You can create a custom dialog content object [ArkUI_CustomDialogOptions](../reference/apis-arkui/capi-arkui-nativemodule-arkui-customdialogoptions.md) by calling the OH_ArkUI_CustomDialog_CreateOptions](../reference/apis-arkui/capi-native-dialog-h.md#oh_arkui_customdialog_createoptions) API,

  which returns a pointer of the **ArkUI_CustomDialogOptions** type.
  <!-- @[dialog_createOption](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
  
  ``` C++
  ArkUI_CustomDialogOptions* g_dialogOptions = nullptr;
  // ···
      auto textNode = std::make_shared<NativeModule::ArkUITextNode>();
      if (!g_dialogOptions) {
          g_dialogOptions = OH_ArkUI_CustomDialog_CreateOptions(textNode->GetHandle());
      }
  ```

  > **NOTE**
  > 
  > For details about how to declare **ArkUITextNode**, refer to the implementation of the text component in the [ArkUINode.h](../ui/ndk-access-the-arkts-page.md#example) file.

- Destroying the dialog content object<br>When dialog operations are no longer needed, actively call the [OH_ArkUI_CustomDialog_DisposeOptions](../reference/apis-arkui/capi-native-dialog-h.md#oh_arkui_customdialog_disposeoptions) API to destroy the dialog content object.
  <!-- @[dialog_disposeOption](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
  
  ``` C++
  OH_ArkUI_CustomDialog_DisposeOptions(g_dialogOptions);
  ```

## Setting Dialog Box Styles

You can set the alignment, offset, corner radius of the background, background color, mask color, and region of the dialog box.

1. Create a dialog box content node.

   > **NOTE**
   >
   > The resources used in this example are not located in the **src** > **main** > **resource** directory. Starting from DevEco Studio 6.0.0 Beta2, the resources that are located outside the **resources** directory are not packaged by default when a project or module is created. To package these resources, go to **buildOptions** > **resOptions** > **copyCodeResource** in the module's **build-profile.json5** file, and set **enable** to **true**. For details, see the description of [resOptions](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile#section754823013348).

   <!-- @[create_content](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
   
   ``` C++
   ArkUI_NodeHandle CreateDialogContent()
   {
       ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       ArkUI_NodeHandle text = nodeAPI->createNode(ARKUI_NODE_TEXT);
       ArkUI_NumberValue textWidthValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem textWidthItem = {.value = textWidthValue,
                                            .size = sizeof(textWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(text, NODE_WIDTH, &textWidthItem);
       ArkUI_NumberValue textHeightValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem textHeightItem = {.value = textHeightValue,
                                             .size = sizeof(textHeightValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(text, NODE_HEIGHT, &textHeightItem);
       ArkUI_NodeHandle span = nodeAPI->createNode(ARKUI_NODE_SPAN);
       ArkUI_AttributeItem spanItem = {.string = "This is a dialog box"};
       nodeAPI->setAttribute(span, NODE_SPAN_CONTENT, &spanItem);
       ArkUI_NodeHandle imageSpan = nodeAPI->createNode(ARKUI_NODE_IMAGE_SPAN);
       // Replace src/main/ets/pages/common/sky.jpg with the image resource file you use.
       ArkUI_AttributeItem imageSpanItem = {.string = "/pages/common/sky.jpg"};
       nodeAPI->setAttribute(imageSpan, NODE_IMAGE_SPAN_SRC, &imageSpanItem);
       ArkUI_NumberValue imageSpanWidthValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem imageSpanWidthItem = {.value = imageSpanWidthValue,
                                                 .size = sizeof(imageSpanWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(imageSpan, NODE_WIDTH, &imageSpanWidthItem);
       ArkUI_NumberValue imageSpanHeightValue[] = {{.f32 = 200}};
       ArkUI_AttributeItem imageSpanHeightItem = {.value = imageSpanHeightValue,
                                                  .size = sizeof(imageSpanHeightValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(imageSpan, NODE_HEIGHT, &imageSpanHeightItem);
       nodeAPI->addChild(text, span);
       nodeAPI->addChild(text, imageSpan);
       return text;
   }
   ```

2. Control dialog box styles using either of the following methods. For details about the dialog box APIs, see [native_dialog.h](../reference/apis-arkui/capi-native-dialog-h.md).

   - Using the controller

     <!-- @[show_dialog](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
     
     ``` C++
     void ShowDialog()
     {
         ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
             OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
         if (!g_dialogController) {
             g_dialogController = dialogAPI->create();
         }
         auto contentNode = CreateDialogContent();
         dialogAPI->setContent(g_dialogController, contentNode);
         dialogAPI->setContentAlignment(g_dialogController, static_cast<int32_t>(ARKUI_ALIGNMENT_BOTTOM), 0, 0);
         dialogAPI->setBackgroundColor(g_dialogController, 0xffffffff);
         dialogAPI->setCornerRadius(g_dialogController, 6.0f, 6.0f, 6.0f, 6.0f);
         dialogAPI->setModalMode(g_dialogController, false);
         dialogAPI->setAutoCancel(g_dialogController, true);
         dialogAPI->show(g_dialogController, false);
     }
     ```

   - Using **dialogOptions**

     <!-- @[open_dialogOption](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
     
     ``` C++
     int32_t g_id = 0;
     void OpenDialogCallBack(int32_t dialogId)
     {
         g_id = dialogId;
     }
     
     void OpenCustomDialog()
     {
         auto contentNode = CreateDialogContent();
         if (!g_dialogOptions) {
             g_dialogOptions = OH_ArkUI_CustomDialog_CreateOptions(contentNode);
         }
         OH_ArkUI_CustomDialog_SetAlignment(g_dialogOptions, static_cast<int32_t>(ARKUI_ALIGNMENT_BOTTOM), 0, 0);
         OH_ArkUI_CustomDialog_SetBackgroundColor(g_dialogOptions, 0xffffffff);
         OH_ArkUI_CustomDialog_SetCornerRadius(g_dialogOptions, 6.0f, 6.0f, 6.0f, 6.0f);
         OH_ArkUI_CustomDialog_SetModalMode(g_dialogOptions, false);
         OH_ArkUI_CustomDialog_SetAutoCancel(g_dialogOptions, true);
         OH_ArkUI_CustomDialog_SetBorderStyle(g_dialogOptions, ARKUI_BORDER_STYLE_SOLID,
                                              ARKUI_BORDER_STYLE_SOLID, ARKUI_BORDER_STYLE_SOLID, ARKUI_BORDER_STYLE_SOLID);
         OH_ArkUI_CustomDialog_OpenDialog(g_dialogOptions, OpenDialogCallBack);
     }
     ```

3. Close the dialog box using either of the following methods:

   - Using the controller

     <!-- @[close_controller](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
     
     ``` C++
     void CloseDialog()
     {
         ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
             OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
         dialogAPI->close(g_dialogController);
     }
     ```

   - Using **dialogOptions**

     <!-- @[close_option](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
     
     ``` C++
     void CloseCustomDialog()
     {
         OH_ArkUI_CustomDialog_CloseDialog(g_id);
     }
     ```

## Interacting with the Dialog Box

You can create an interactive page to open or close a dialog box.

1. Create a button that, when clicked, will trigger the display of a dialog box. For details about how to obtain and use nodes of the ArkUI_NodeContentHandle type, see [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md).
   <!-- @[main_view](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
   
   ``` C++
   constexpr int32_t BUTTON_CLICK_ID = 1;
   ArkUI_NodeHandle g_buttonNode = nullptr;
   
   void MainViewMethod(ArkUI_NodeContentHandle handle)
   {
       ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
       ArkUI_NumberValue widthValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem widthItem = {.value = widthValue, .size = sizeof(widthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(column, NODE_WIDTH, &widthItem);
       ArkUI_NumberValue heightValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem heightItem = {.value = heightValue, .size = sizeof(heightValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(column, NODE_HEIGHT, &heightItem);
       
       g_buttonNode = nodeAPI->createNode(ARKUI_NODE_BUTTON);
       ArkUI_NumberValue buttonWidthValue[] = {{.f32 = 200}};
       ArkUI_AttributeItem buttonWidthItem = {.value = buttonWidthValue,
                                              .size = sizeof(buttonWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(g_buttonNode, NODE_WIDTH, &buttonWidthItem);
       ArkUI_NumberValue buttonHeightValue[] = {{.f32 = 50}};
       ArkUI_AttributeItem buttonHeightItem = {.value = buttonHeightValue,
                                               .size = sizeof(buttonHeightValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(g_buttonNode, NODE_HEIGHT, &buttonHeightItem);
       ArkUI_AttributeItem labelItem = {.string = "Click Dialog Box"};
       nodeAPI->setAttribute(g_buttonNode, NODE_BUTTON_LABEL, &labelItem);
       ArkUI_NumberValue buttonTypeValue[] = {{.i32 = static_cast<int32_t>(ARKUI_BUTTON_TYPE_NORMAL)}};
       ArkUI_AttributeItem buttonTypeItem = {.value = buttonTypeValue,
                                             .size = sizeof(buttonTypeValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(g_buttonNode, NODE_BUTTON_TYPE, &buttonTypeItem);
       nodeAPI->registerNodeEvent(g_buttonNode, NODE_ON_CLICK, BUTTON_CLICK_ID, nullptr);
       nodeAPI->addNodeEventReceiver(g_buttonNode, OnButtonClicked);
       nodeAPI->addChild(column, g_buttonNode);
       OH_ArkUI_NodeContent_AddNode(handle, column);
   }
   ```

2. Create a button event callback function to trigger the display or closure of the dialog box when the button is clicked.

   - Using the controller

     <!-- @[controller_click](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
     
     ``` C++
     bool g_isShown = false;
     
     void OnButtonClicked(ArkUI_NodeEvent *event)
     {
         if (!event || !g_buttonNode) {
             return;
         }
         auto eventId = OH_ArkUI_NodeEvent_GetTargetId(event);
         if (eventId == BUTTON_CLICK_ID) {
             ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
                 OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
             if (g_isShown) {
                 g_isShown = false;
                 ArkUI_AttributeItem labelItem = {.string = "Show Dialog Box"};
                 nodeAPI->setAttribute(g_buttonNode, NODE_BUTTON_LABEL, &labelItem);
                 CloseDialog();
             } else {
                 g_isShown = true;
                 ArkUI_AttributeItem labelItem = {.string = "Close Dialog Box"};
                 nodeAPI->setAttribute(g_buttonNode, NODE_BUTTON_LABEL, &labelItem);
                 ShowDialog();
             }
         }
     }
     ```

   - Using **dialogOptions**

     <!-- @[option_click](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->
     
     ``` C++
     void OnButtonClicked(ArkUI_NodeEvent *event)
     {
         if (!event || !g_buttonNode) {
             return;
         }
         auto eventId = OH_ArkUI_NodeEvent_GetTargetId(event);
         if (eventId == BUTTON_CLICK_ID) {
             ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
                 OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
             if (g_isShown) {
                 g_isShown = false;
                 ArkUI_AttributeItem labelItem = {.string = "Show Dialog Box"};
                 nodeAPI->setAttribute(g_buttonNode, NODE_BUTTON_LABEL, &labelItem);
                 CloseCustomDialog();
             } else {
                 g_isShown = true;
                 ArkUI_AttributeItem labelItem = {.string = "Close Dialog Box"};
                 nodeAPI->setAttribute(g_buttonNode, NODE_BUTTON_LABEL, &labelItem);
                 OpenCustomDialog();
             }
         }
     }
     ```

![zh-cn_image_0000001902966196](figures/Interacting-Dialog-Box.gif)


## Managing the Dialog Box Lifecycle

From API version 19, four lifecycle callbacks are available before and after a dialog is displayed and closed: [registerOnWillAppear](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-3.md#registeronwillappear), [registerOnDidAppear](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-3.md#registerondidappear), [registerOnWillDisappear](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-3.md#registeronwilldisappear), and [registerOnDidDisappear](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-3.md#registerondiddisappear).

These lifecycle APIs must be called before the **show** API is invoked. The sequence of lifecycle events is as follows:

registerOnWillAppear -> Dialog box display animation starts -> Dialog box display animation ends -> registerOnDidAppear -> Dialog box display completes-> registerOnWillDisappear -> Dialog box close animation starts -> Dialog box close animation ends -> registerOnDidDisappear -> Dialog box close animation completes.

The following is an example of creating a dialog box that triggers lifecycle callback functions when the dialog box is displayed and closed. For details about how to obtain and use nodes of the ArkUI_NodeContentHandle type, see [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md).

> **NOTE**
>
> The resources used in this example are not located in the **src** > **main** > **resource** directory. Starting from DevEco Studio 6.0.0 Beta2, the resources that are located outside the **resources** directory are not packaged by default when a project or module is created. To package these resources, go to **buildOptions** > **resOptions** > **copyCodeResource** in the module's **build-profile.json5** file, and set **enable** to **true**. For details, see the description of [resOptions](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile#section754823013348).
 
<!-- @[dialog_lifecycle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeDialogSample/entry/src/main/cpp/customdialog/nativedialogdemo.cpp) -->

``` C++
ArkUI_NodeHandle CreateDialogContent()
{
    ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
    ArkUI_NodeHandle text = nodeAPI->createNode(ARKUI_NODE_TEXT);
    ArkUI_NumberValue textWidthValue[] = {{.f32 = 300}};
    ArkUI_AttributeItem textWidthItem = {.value = textWidthValue,
                                         .size = sizeof(textWidthValue) / sizeof(ArkUI_NumberValue)};
    nodeAPI->setAttribute(text, NODE_WIDTH, &textWidthItem);
    ArkUI_NumberValue textHeightValue[] = {{.f32 = 300}};
    ArkUI_AttributeItem textHeightItem = {.value = textHeightValue,
                                          .size = sizeof(textHeightValue) / sizeof(ArkUI_NumberValue)};
    nodeAPI->setAttribute(text, NODE_HEIGHT, &textHeightItem);
    ArkUI_NodeHandle span = nodeAPI->createNode(ARKUI_NODE_SPAN);
    ArkUI_AttributeItem spanItem = {.string = "This is a dialog box"};
    nodeAPI->setAttribute(span, NODE_SPAN_CONTENT, &spanItem);
    ArkUI_NodeHandle imageSpan = nodeAPI->createNode(ARKUI_NODE_IMAGE_SPAN);
    // Replace src/main/ets/pages/common/sky.jpg with the image resource file you use.
    ArkUI_AttributeItem imageSpanItem = {.string = "/pages/common/sky.jpg"};
    nodeAPI->setAttribute(imageSpan, NODE_IMAGE_SPAN_SRC, &imageSpanItem);
    ArkUI_NumberValue imageSpanWidthValue[] = {{.f32 = 300}};
    ArkUI_AttributeItem imageSpanWidthItem = {.value = imageSpanWidthValue,
                                              .size = sizeof(imageSpanWidthValue) / sizeof(ArkUI_NumberValue)};
    nodeAPI->setAttribute(imageSpan, NODE_WIDTH, &imageSpanWidthItem);
    ArkUI_NumberValue imageSpanHeightValue[] = {{.f32 = 200}};
    ArkUI_AttributeItem imageSpanHeightItem = {.value = imageSpanHeightValue,
                                               .size = sizeof(imageSpanHeightValue) / sizeof(ArkUI_NumberValue)};
    nodeAPI->setAttribute(imageSpan, NODE_HEIGHT, &imageSpanHeightItem);
    nodeAPI->addChild(text, span);
    nodeAPI->addChild(text, imageSpan);
    return text;
}

void OnWillAppearCallBack(void* userdata)
{
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "CustomDialogContentTest", "OnWillAppearCallBack");
}

void OnDidAppearCallBack(void* userdata)
{
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "CustomDialogContentTest", "OnDidAppearCallBack");
}

void OnWillDisappearCallBack(void* userdata)
{
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "CustomDialogContentTest", "OnWillDisappearCallBack");
}

void OnDidDisappearCallBack(void* userdata)
{
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "CustomDialogContentTest", "OnDidDisappearCallBack");
}

void ShowDialog()
{
    ArkUI_NativeDialogAPI_3 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_3 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_3"));
    if (!g_dialogController) {
        g_dialogController = dialogAPI->nativeDialogAPI1.create();
    }
    auto contentNode = CreateDialogContent();
    dialogAPI->nativeDialogAPI1.setContent(g_dialogController, contentNode);
    dialogAPI->nativeDialogAPI1.setAutoCancel(g_dialogController, true);
    dialogAPI->registerOnWillAppear(g_dialogController, nullptr, OnWillAppearCallBack);
    dialogAPI->registerOnDidAppear(g_dialogController, nullptr, OnDidAppearCallBack);
    dialogAPI->registerOnWillDisappear(g_dialogController, nullptr, OnWillDisappearCallBack);
    dialogAPI->registerOnDidDisappear(g_dialogController, nullptr, OnDidDisappearCallBack);
    dialogAPI->nativeDialogAPI1.show(g_dialogController, false);
}
```
