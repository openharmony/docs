# 构建弹窗
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyi0309-->
<!--SE: @liyi0309-->
<!--TSE: @lxl007-->


可以通过创建弹窗控制器和创建自定义弹窗的内容对象两种方法显示自定义弹窗，设置其样式和内容。


[通过创建弹窗控制器显示自定义弹窗](#通过创建弹窗控制器显示自定义弹窗)：此时在命名为ArkUI_NativeDialogAPI_x （x表示版本）的结构体里，定义了弹窗接口集合，用于实现各种弹窗控制。


[通过创建自定义弹窗的内容对象显示自定义弹窗](#通过创建自定义弹窗的内容对象显示自定义弹窗)：该方式下弹窗接口定义在[native_dialog.h](../reference/apis-arkui/capi-native-dialog-h.md#函数)的函数中。


> **说明：**
>
> - 通过创建弹窗控制器来显示自定义弹窗，使用方式可以参考[openCustomDialogWithController](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialogwithcontroller18)接口。
> 
> - 通过创建自定义弹窗的内容对象来显示自定义弹窗，使用方式可以参考[openCustomDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialog12)接口。
> 
> - [OH_ArkUI_QueryModuleInterfaceByName](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_querymoduleinterfacebyname)用于获取指定类型的Native模块接口集合，可以通过其返回ArkUI_NativeDialogHandle类型的数据调用Native模块中的接口。

## 创建和销毁自定义弹窗

### 通过创建弹窗控制器显示自定义弹窗

- 创建弹窗控制器：
  [ArkUI_NativeDialogHandle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialog8h.md)表示指向弹窗控制器的指针，可以通过调用[ArkUI_NativeDialogAPI_x](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-1.md)的[create](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativedialogapi-1.md#create)接口创建一个弹窗控制器。
该方法返回ArkUI_NativeDialogHandle类型的数据。
  ```
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  auto dialogController = dialogAPI->create();
  ```

- 当不再需要弹窗操作时，需要主动调用dispose接口销毁弹窗控制器对象。
  ```
  ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
  dialogAPI->dispose(dialogController);
  ```

### 通过创建自定义弹窗的内容对象显示自定义弹窗

- 创建弹窗的内容对象：
  [ArkUI_CustomDialogOptions](../reference/apis-arkui/capi-arkui-nativemodule-arkui-customdialogoptions.md)自定义弹窗的内容对象，可以通过调用[OH_ArkUI_CustomDialog_CreateOptions](../reference/apis-arkui/capi-native-dialog-h.md#oh_arkui_customdialog_createoptions)接口创建一个自定义弹窗的内容对象。
该方法返回ArkUI_CustomDialogOptions类型的指针。
  ```
  auto textNode = std::make_shared<ArkUITextNode>();
  auto dialogOptions = OH_ArkUI_CustomDialog_CreateOptions(textNode->GetHandle());
  ```
  > **说明：**
  > 
  > ArkUITextNode的声明方式可以查看[ArkUINode.h](../ui/ndk-access-the-arkts-page.md)文件中的实现文本组件。

- 当不再需要弹窗操作时，需要主动调用[OH_ArkUI_CustomDialog_DisposeOptions](../reference/apis-arkui/capi-native-dialog-h.md#oh_arkui_customdialog_disposeoptions)接口销毁弹窗控制器对象。
  ```
  OH_ArkUI_CustomDialog_DisposeOptions(dialogOptions);
  ```

## 设置弹窗样式

可以设置弹窗对齐方式、偏移量，弹窗背板圆角弧度、背景色、蒙层颜色以及区域等。

1. 创建弹窗内容节点。
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
       ArkUI_AttributeItem spanItem = {.string = "这是一个弹窗"};
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

2. 以下介绍两种控制弹窗样式的方式，弹窗接口请参考[native_dialog.h](../reference/apis-arkui/capi-native-dialog-h.md)。

- 通过controller控制弹窗样式。
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

- 通过dialogOptions控制弹窗样式。
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

3. 弹窗关闭方式。

- 通过controller关闭弹窗。
   ```
   void CloseDialog() {
       ArkUI_NativeDialogAPI_1 *dialogAPI = reinterpret_cast<ArkUI_NativeDialogAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_DIALOG, "ArkUI_NativeDialogAPI_1"));
       dialogAPI->close(dialogController);
   }
   ```

- 通过dialogOptions关闭弹窗。
   ```
   void CloseCustomDialog() {
       OH_ArkUI_CustomDialog_CloseDialog(id);
   }
   ```

## 弹窗的交互

可创建交互页面，打开或关闭弹窗。

1. 创建可交互界面，点击Button后弹窗。其中获取与使用ArkUI_NodeContentHandle类型节点可参考[接入ArkTS页面](ndk-access-the-arkts-page.md)。
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
       ArkUI_AttributeItem labelItem = {.string = "点击弹窗"};
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

2. 创建Button事件的回调函数，当Button点击时触发弹窗显示或关闭。

- 触发controller弹窗。
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
               ArkUI_AttributeItem labelItem = {.string = "显示弹窗"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               CloseDialog();
           } else {
               isShown = true;
               ArkUI_AttributeItem labelItem = {.string = "关闭弹窗"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               ShowDialog();
           }
       }
   }
   ```

- 触发dialogOptions弹窗。
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
               ArkUI_AttributeItem labelItem = {.string = "显示弹窗"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               CloseCustomDialog();
           } else {
               isShown = true;
               ArkUI_AttributeItem labelItem = {.string = "关闭弹窗"};
               nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
               OpenCustomDialog();
           }
       }
   }
   ```

   ![zh-cn_image_0000001902966196](figures/zh-cn_image_0000001902966196.gif)


## 弹窗的生命周期

弹窗显示和关闭前后，存在四个生命周期：registerOnWillAppear、registerOnDidAppear、registerOnWillDisappear、registerOnDidDisappear。
这些生命周期方法需要在调用show方法之前调用，生命周期的时序如下：
registerOnWillAppear -> 弹窗显示动画开始 -> 弹窗显示动画结束 -> registerOnDidAppear -> 弹窗显示完成 ->
registerOnWillDisappear -> 弹窗关闭动画开始 ->  弹窗关闭动画结束 -> registerOnDidDisappear -> 弹窗关闭完成。

创建一个弹窗，弹窗显示和关闭时会触发生命周期的回调函数。其中 ArkUI_NodeContentHandle 类型节点的获取与使用可参考[接入ArkTS页面](ndk-access-the-arkts-page.md)。
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
        ArkUI_AttributeItem spanItem = {.string = "这是一个弹窗"};
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
