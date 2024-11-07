# 使用动画


## 使用属性动画

ArkUI开发框架在NDK接口主要提供属性动画，实现组件出现/消失转场。同时，可以通过Node-API桥接ArkTS侧帧动画能力，实现Native侧的动画效果。

> **说明：**
>
> - 需要从ArkTS侧获取this.getUIContext()，传入到Native侧。
> 
> - 在Native侧通过[OH_ArkUI_GetContextFromNapiValue](../reference/apis-arkui/native__node__napi_8h.md)方法获取context。
> 
> - 需要执行的动画属性变化必须写在ArkUI_ContextCallback中callback中。
> 
> - 需要执行的动画属性,必须在执行动画之前设置过。

提供全局animateTo显式动画接口，来指定由于闭包代码导致的状态变化插入过渡动效。同属性动画，布局类改变宽高的动画，内容都是直接到终点状态。

1. 在.ets文件中获取UIContext，把this.getUIContext()当做参数输出到Native方法中。
   ```ts
   // createNativeNode是Native侧暴露的方法
   nativeNode.createNativeNode("xcomponentId", this.getUIContext());
   ```

2. 解析UIContext转换C中的context对象。
   ```
   // 获取ets测传入的context
   ArkUI_ContextHandle context = nullptr;
   // 通过code 判断是否获取成功
   auto code = OH_ArkUI_GetContextFromNapiValue(env, args[1], &context);
   ```

3. 获取ArkUI_NativeAnimateAPI_1 对象。
   ```
   // 获取ArkUI_NativeAnimateAPI接口
   ArkUI_NativeAnimateAPI_1 *animateApi = nullptr;
   OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_ANIMATE, ArkUI_NativeAnimateAPI_1, animateApi);
   ```

4. 设置 ArkUI_AnimateOption参数，通过提供的C方法设置对应的参数。
   ```
   ArkUI_AnimateOption *option = OH_ArkUI_AnimateOption_Create();
   OH_ArkUI_AnimateOption_SetDuration(option, 2000);
   OH_ArkUI_AnimateOption_SetTempo(option, 1.1);
   OH_ArkUI_AnimateOption_SetCurve(option, ARKUI_CURVE_EASE);
   OH_ArkUI_AnimateOption_SetDelay(option, 20);
   OH_ArkUI_AnimateOption_SetIterations(option, 1);
   OH_ArkUI_AnimateOption_SetPlayMode(option, ARKUI_ANIMATION_PLAY_MODE_REVERSE);
   ArkUI_ExpectedFrameRateRange *range = new ArkUI_ExpectedFrameRateRange;
   range->min = 10;
   range->max = 120;
   range->expected = 60;
   OH_ArkUI_AnimateOption_SetExpectedFrameRateRange(option, range);
   ```

5. 设置回调参数。
   ```
   // 用户自定义参数
   struct UserData{
       int32_t data;
   };
   UserData *onFinishUser = new UserData;
   onFinishUser->data= 101;
   // 设置完成的回调
   ArkUI_AnimateCompleteCallback *completeCallback = new ArkUI_AnimateCompleteCallback;
   completeCallback->userData = onFinishUser;
   completeCallback->type = ARKUI_FINISH_CALLBACK_REMOVED;
   completeCallback->callback = [](void *userData) {
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Manager", "CreateNativeNode  onFinishCallback %{public}d",
                    reinterpret_cast<AA *>(userData)->a);
   };
   // 用户自定义参数
   UserData *eventUser = new UserData ;
   eventUser->data= 201;
   static bool isback = true;
   ArkUI_ContextCallback *update = new ArkUI_ContextCallback;
   update->userData = eventUser;
   update->callback = [](void *user) {
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Manager", "CreateNativeNode  animateTo %{public}d",
                    reinterpret_cast<UserData*>(user)->data);
       // 对应的属性变化 width height
       if (isback) {
           ArkUI_NumberValue custom_widthValue[] = {200};
           ArkUI_AttributeItem custom_widthItem = {custom_widthValue, 1};
           ArkUI_NumberValue custom_heightValue1[] = {80};
           ArkUI_AttributeItem custom_heightItem1 = {custom_heightValue1, 1};
           nodeAPI->setAttribute(textInput, NODE_WIDTH, &custom_widthItem);
           nodeAPI->setAttribute(textInput, NODE_HEIGHT, &custom_heightItem1);
       } else {
           ArkUI_NumberValue custom_widthValue[] = {100};
           ArkUI_AttributeItem custom_widthItem = {custom_widthValue, 1};
           ArkUI_NumberValue custom_heightValue1[] = {40};
           ArkUI_AttributeItem custom_heightItem1 = {custom_heightValue1, 1};
           nodeAPI->setAttribute(textInput, NODE_WIDTH, &custom_widthItem);
           nodeAPI->setAttribute(textInput, NODE_HEIGHT, &custom_heightItem1);
       }
   };
   // 执行对应的动画
   animateApi->animateTo(context, option, update, completeCallback);
   ```

   ![GIF](figures/animateTo.gif)





## 组件出现/消失转场

组件内转场通过NODE_XX_TRANSITION属性（XX包括：OPACITY、TRANSLATE、SCALE、ROTATE、MOVE）配置转场参数，在组件插入和删除时显示过渡动效（通过NODE_TRANSFORM_CENTER属性设置NODE_SCALE_TRANSITION和NODE_ROTATE_ROTATE动效的中心点坐标）。主要用于容器组件中子组件插入和删除时，提升用户体验。

1. 创建可交互界面，界面中包含Button，点击可以控制转场节点的添加和移除。其中 ArkUI_NodeContentHandle 类型节点的获取与使用可参考[接入ArkTS页面](ndk-access-the-arkts-page.md)。
   ```
   constexpr int32_t BUTTON_CLICK_ID = 1;
   bool flag = false;
   ArkUI_NodeHandle parrentNode;
   ArkUI_NodeHandle childNode;
   ArkUI_NodeHandle buttonNode;
   
   void mainViewMethod(ArkUI_NodeContentHandle handle)
   {
       ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       ArkUI_NodeHandle column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
       ArkUI_NumberValue widthValue[] = {{.f32 = 500}};
       ArkUI_AttributeItem widthItem = {.value = widthValue, .size = sizeof(widthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(column, NODE_WIDTH, &widthItem);
       ArkUI_NumberValue heightValue[] = {{.f32 = 500}};
       ArkUI_AttributeItem heightItem = {.value = heightValue, .size = sizeof(heightValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(column, NODE_HEIGHT, &heightItem);
       ArkUI_NodeHandle buttonShow = nodeAPI->createNode(ARKUI_NODE_BUTTON);
       ArkUI_NumberValue buttonWidthValue[] = {{.f32 = 200}};
       ArkUI_AttributeItem buttonWidthItem = {.value = buttonWidthValue,
                                              .size = sizeof(buttonWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(buttonShow, NODE_WIDTH, &buttonWidthItem);
       ArkUI_NumberValue buttonHeightValue[] = {{.f32 = 50}};
       ArkUI_AttributeItem buttonHeightItem = {.value = buttonHeightValue,
                                               .size = sizeof(buttonHeightValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(buttonShow, NODE_HEIGHT, &buttonHeightItem);
       ArkUI_AttributeItem labelItem = {.string = "show"};
       nodeAPI->setAttribute(buttonShow, NODE_BUTTON_LABEL, &labelItem);
       ArkUI_NumberValue buttonOpenTypeValue[] = {{.i32 = static_cast<int32_t>(ARKUI_BUTTON_TYPE_NORMAL)}};
       ArkUI_AttributeItem buttonOpenTypeItem = {.value = buttonOpenTypeValue,
                                                 .size = sizeof(buttonOpenTypeValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(buttonShow, NODE_BUTTON_TYPE, &buttonOpenTypeItem);
       ArkUI_NumberValue buttonShowMarginValue[] = {{.f32 = 20}};
       ArkUI_AttributeItem buttonShowMarginItem = {.value = buttonShowMarginValue,
                                                    .size = sizeof(buttonShowMarginValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(buttonShow, NODE_MARGIN, &buttonShowMarginItem);
       nodeAPI->registerNodeEvent(buttonShow, NODE_ON_CLICK, BUTTON_CLICK_ID, nullptr);
       nodeAPI->addNodeEventReceiver(buttonShow, OnButtonShowClicked);
       parrentNode = column;
       buttonNode = buttonShow;
       nodeAPI->addChild(column, buttonShow);
       OH_ArkUI_NodeContent_AddNode(handle, column);
   }
   ```

2. 创建一个设置了Transition属性的节点，当目标节点上下树时会播放转场动画。
   ```
   ArkUI_NodeHandle CreateChildNode() {
       ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       ArkUI_NodeHandle image = nodeAPI->createNode(ARKUI_NODE_IMAGE);
       ArkUI_AttributeItem imageSrcItem = {.string = "/pages/common/scenery.jpg"};
       nodeAPI->setAttribute(image, NODE_IMAGE_SRC, &imageSrcItem);
       ArkUI_NumberValue textWidthValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem textWidthItem = {.value = textWidthValue,
                                            .size = sizeof(textWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(image, NODE_WIDTH, &textWidthItem);
       ArkUI_NumberValue textHeightValue[] = {{.f32 = 300}};
       ArkUI_AttributeItem textHeightItem = {.value = textHeightValue,
                                             .size = sizeof(textWidthValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(image, NODE_HEIGHT, &textHeightItem);
       ArkUI_NumberValue transformCenterValue[] = {0.0f, 0.0f, 0.0f, 0.5f, 0.5f};
       ArkUI_AttributeItem transformCenterItem = {.value = transformCenterValue,
                                             .size = sizeof(transformCenterValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(image, NODE_TRANSFORM_CENTER, &transformCenterItem);
       ArkUI_NumberValue rotateAnimationValue[] = {0.0f, 0.0f, 1.0f, 360.0f, 0.0f, {.i32 = 500}, {.i32 = static_cast<int32_t>(ARKUI_CURVE_SHARP)}};
       ArkUI_AttributeItem rotateAnimationItem = {.value = rotateAnimationValue,
                                                  .size = sizeof(rotateAnimationValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(image, NODE_ROTATE_TRANSITION, &rotateAnimationItem);
       ArkUI_NumberValue scaleAnimationValue[] = {
           0.0f, 0.0f, 0.0f, {.i32 = 500}, {.i32 = static_cast<int32_t>(ARKUI_CURVE_SHARP)}};
       ArkUI_AttributeItem scaleAnimationItem = {.value = scaleAnimationValue,
                                                  .size = sizeof(scaleAnimationValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(image, NODE_SCALE_TRANSITION, &scaleAnimationItem);
       ArkUI_NumberValue translateAnimationValue[] = {
           200, 200, 0.0f, {.i32 = 500}, {.i32 = static_cast<int32_t>(ARKUI_CURVE_SHARP)}};
       ArkUI_AttributeItem translateAnimationItem = {.value = translateAnimationValue,
                                                 .size = sizeof(translateAnimationValue) / sizeof(ArkUI_NumberValue)};
       nodeAPI->setAttribute(image, NODE_TRANSLATE_TRANSITION, &translateAnimationItem);
       return image;
   }
   ```

3. 在Button的监听回调里添加转场节点上下树逻辑，以此控制转场节点的入场和出场。
   ```
   void OnButtonShowClicked(ArkUI_NodeEvent* event)
   {
       if (!event) {
           return;
       }
       if (!childNode) {
           childNode = CreateChildNode();
       }
       ArkUI_NativeNodeAPI_1 *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
           OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
       if (flag) {
           flag = false;
           ArkUI_AttributeItem labelItem = {.string = "show"};
           nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
           nodeAPI->removeChild(parrentNode, childNode);
       } else {
           flag = true;
           ArkUI_AttributeItem labelItem = {.string = "hide"};
           nodeAPI->setAttribute(buttonNode, NODE_BUTTON_LABEL, &labelItem);
           nodeAPI->addChild(parrentNode, childNode);
       }
   }
   ```

   ![zh-cn_image_0000001903284256](figures/zh-cn_image_0000001903284256.gif)


