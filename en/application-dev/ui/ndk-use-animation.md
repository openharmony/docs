# Using Animations


## Using Property Animations

The ArkUI development framework primarily offers property animations through NDK APIs to implement component transition effects for appearance and disappearance. Additionally, frame animation capabilities from the ArkTS side can be bridged through the Node-API to achieve animation effects on the native side.

> **NOTE**
>
> - Obtain **this.getUIContext()** from ArkTS and pass it to the native side.
> 
> - On the native side, obtain the context using the [OH_ArkUI_GetContextFromNapiValue](../reference/apis-arkui/native__node__napi_8h.md) API.
> 
> - Animation property changes must be written within the callback of **ArkUI_ContextCallback**.
> 
> - The properties to be animated must have been set before the animation is executed.

A global **animateTo** explicit animation API is provided to specify transition effects for state changes caused by closure code. Like property animations, layout changes such as width and height adjustments are animated directly to their final states.

1. Obtain the UI context in the .ets file and pass **this.getUIContext() **as a parameter to the native API.
   ```ts
   // createNativeNode is an API exposed on the native side.
   nativeNode.createNativeNode("xcomponentId", this.getUIContext());
   ```

2. Parse the UI context to convert the context object in C.
   ```
   // Obtain the context passed from the ArkTS side.
   ArkUI_ContextHandle context = nullptr;
   // Determine whether the acquisition is successful based on code.
   auto code = OH_ArkUI_GetContextFromNapiValue(env, args[1], &context);
   ```

3. Obtain the **ArkUI_NativeAnimateAPI_1** object.
   ```
   // Obtain the ArkUI_NativeAnimateAPI.
   ArkUI_NativeAnimateAPI_1 *animateApi = nullptr;
   OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_ANIMATE, ArkUI_NativeAnimateAPI_1, animateApi);
   ```

4. Set the **ArkUI_AnimateOption** parameters using the provided C APIs.
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

5. Set callback parameters.
   ```
   // Define a user data struct.
   struct UserData{
       int32_t data;
   };
   UserData *onFinishUser = new UserData;
   onFinishUser->data= 101;
   // Create and set user data for the completion callback.
   ArkUI_AnimateCompleteCallback *completeCallback = new ArkUI_AnimateCompleteCallback;
   completeCallback->userData = onFinishUser;
   completeCallback->type = ARKUI_FINISH_CALLBACK_REMOVED;
   completeCallback->callback = [](void *userData) {
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Manager", "CreateNativeNode  onFinishCallback %{public}d",
                    reinterpret_cast<AA *>(userData)->a);
   };
   // User data 
   UserData *eventUser = new UserData ;
   eventUser->data= 201;
   static bool isback = true;
   ArkUI_ContextCallback *update = new ArkUI_ContextCallback;
   update->userData = eventUser;
   update->callback = [](void *user) {
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Manager", "CreateNativeNode  animateTo %{public}d",
                    reinterpret_cast<UserData*>(user)->data);
       // Example of changing width and height properties
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
   // Execute the animation with the set options and callbacks.
   animateApi->animateTo(context, option, update, completeCallback);
   ```

   ![GIF](figures/animateTo.gif)





## Using Component Appearance/Disappearance Transitions

Use **NODE_*XX*_TRANSITION** properties (where *XX* can be **OPACITY**, **TRANSLATE**, **SCALE**, **ROTATE**, or **MOVE**) to configure transition effects for components, enhancing the user experience when components are added to or removed from containers. The **NODE_TRANSFORM_CENTER** property sets the center point for animations including **NODE_SCALE_TRANSITION** and **NODE_ROTATE_ROTATE**.  

1. Design an interactive UI with a button to manage the addition and removal of transition nodes.
   ```
   constexpr int32_t BUTTON_CLICK_ID = 1;
   bool flag = false;
   ArkUI_NodeHandle parrentNode;
   ArkUI_NodeHandle childNode;
   ArkUI_NodeHandle buttonNode;
   
   void mainViewMethod(OH_NativeXComponent *component)
   {
       if (!component) {
           return;
       }
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
       OH_NativeXComponent_AttachNativeRootNode(component, column);
   }
   ```

2. Create a node with **Transition** properties that play a transition animation when the target node is mounted or unmounted.
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

3. Add logic for mounting and unmounting the transition node within the **Button** component event callback to control the appearance and disappearance of the transition node.
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

   ![en-us_image_0000001903284256](figures/en-us_image_0000001903284256.gif)
