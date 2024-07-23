# 绑定手势事件


ArkUI开发框架在NDK接口主要提供点击手势、拖动手势、滑动手势、长按手势、捏合手势和旋转手势，通过给指定的组件绑定不同的手势并设置相应的回调，实现期望的手势交互能力。


下面通过一个简单的示例来介绍如何实现手势绑定。


1. 创建一个Column节点，用于绑定手势。
   ```
   // 创建Column节点
   auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
   // 设置背景色
   ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
   ArkUI_AttributeItem item = {value, 1};
   nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
   // 设置宽度
   ArkUI_NumberValue widthValue[] = {{400}};
   ArkUI_AttributeItem width = {widthValue, 1};
   nodeAPI->setAttribute(column, NODE_WIDTH, &width);
   // 设置高度
   ArkUI_NumberValue heightValue[] = {{400}};
   ArkUI_AttributeItem height = {heightValue, 1};
   nodeAPI->setAttribute(column, NODE_HEIGHT, &height);
   ```

2. 创建一个单指长按1秒并持续响应的长按手势。
   ```
   // 获取手势Native接口集合
   auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
               OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
   // 创建长按手势
   auto longPressGesture = gestureApi->createLongPressGesture(1, true, 1000);
   ```

3. 将创建的手势和步骤一中创建的Column节点绑定。
   ```
   // 设置回调
   auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
       // 回调内容
   };
   
   // 将手势设置到组件上
   gestureApi->setGestureEventTarget(longPressGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column, onActionCallBack);
   
   gestureApi->addGestureToNode(column, longPressGesture, PARALLEL, NORMAL_GESTURE_MASK);
   ```


## 单一手势

通过上文的示例已经了解了如果将手势绑定在节点上，接下来将分别介绍不同手势的创建方法，并分别支持哪些事件回调。

- 点击手势
  通过给组件绑定点击手势可在组件被点击时触发此回调，可指定触发回调需要的点击次数和手指个数。

  ```
  ArkUI_GestureRecognizer* (*createTapGesture)(int32_t countNum, int32_t fingersNum);
  ```

- 拖动手势
  通过给组件绑定拖动手势可在用户拖动组件时触发回调，可指定触发回调需要的手指个数、拖动方向、拖动距离。单位为px。
  ```
  ArkUI_GestureRecognizer* (*createPanGesture)(
  int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum);
  ```

- 长按手势
  通过给组件绑定长按手势可在用户长按组件时触发回调，可指定触发回调需要的手指个数、长按时间（单位毫秒）、是否连续触发。

  ```
  ArkUI_GestureRecognizer* (*createLongPressGesture)(int32_t fingersNum, bool repeatResult, int32_t durationNum);
  ```

- 捏合手势
  通过给组件绑定捏合手势可在用户捏合组件时触发回调，可指定触发回调需要的手指个数（最小为2）、捏合距离（单位px）。

  ```
  ArkUI_GestureRecognizer* (*createPinchGesture)(int32_t fingersNum, double distanceNum);
  ```

- 旋转手势
  通过给组件绑定旋转手势可在用户旋转组件时触发回调，可指定触发回调需要的手指个数（最小为2）、旋转角度。

  ```
  ArkUI_GestureRecognizer* (*createRotationGesture)(int32_t fingersNum, double angleNum);
  ```

- 滑动手势
  通过给组件绑定滑动手势可在用户滑动组件时触发回调，可指定触发回调需要的手指个数（最小为1）、滑动方向、滑动速度（单位px/s）

  ```
  ArkUI_GestureRecognizer* (*createSwipeGesture)(
  int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum);
  ```


## 组合手势

组合手势由多种单一手势组合而成，通过在GroupGesture中使用不同的ArkUI_GroupGestureMode来声明该组合手势的类型，支持顺序识别、并行识别、互斥识别三种类型。

ArkUI_GroupGestureMode枚举类，用于声明该组合手势的类型。顺序识别SEQUENTIAL_GROUP，并行识别PARALLEL_GROUP，互斥识别EXCLUSIVE_GROUP。


### 顺序识别

顺序识别组合手势对应的ArkUI_GroupGestureMode为SEQUENTIAL_GROUP。顺序识别组合手势将按照手势的注册顺序识别手势，直到所有的手势识别成功。当顺序识别组合手势中有一个手势识别失败时，后续手势识别均失败。顺序识别手势组仅有最后一个手势可以响应GESTURE_EVENT_ACTION_END。

以顺序识别长按和滑动手势为例：

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // 创建手势并设置回调
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // 判断是否有手势API
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api not exist");
    }
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::SEQUENTIAL_GROUP);

    // 创建长按手势
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, 500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack longPressGesture,ArkUI_GestureRecognizerType%{public}d", type);
    }
    // 给长按手势定回调
    auto onActionCallBackPanLongPress = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
       float OffsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float OffsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float CenterX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float CenterY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float VelocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
       float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);

        OH_LOG_Print(
            LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
            "onPanActionCallBack,longPressGesturecallback actionType:%{public}d,velocity%{public}f,velocityX"
            "%{public}f;"
            "velocityY%{public}f,OffsetX%{public}f,OffsetY%{public}f,scale%{public}fCenterX"
            "%{public}fCenterY"
            "%{public}fangle%{public}fVelocityS%{public}fangleR%{public}frepeat%{public}f",
            actionType, velocity, velocityX, velocityY, OffsetX, OffsetY, scale, CenterX, CenterY, angle, VelocityS,
            angleR, repeat);
    };
    gestureApi->setGestureEventTarget(longPressGesture,
                                      GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_CANCEL,
                                      column, onActionCallBackPanLongPress);

    // 将长按手势添加到手势组
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture longPressGesture");
    }
    // 创建滑动手势 swipe
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // 给滑动手势绑定回调
    auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float OffsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float OffsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float CenterX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float CenterY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float VelocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);


        // 通过日志查看
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, swipeGesture callback actionType: %{public}d, velocity "
                     "%{public}f,velocityX "
                     "%{public}f; "
                     "velocityY %{public}f, OffsetX %{public}f, OffsetY %{public}f, scale %{public}fCenterX "
                     "%{public}f CenterY"
                     " %{public}f angle %{public}f VelocityS %{public}f angleR %{public}f repeat %{public}f",
                     actionType, velocity, velocityX, velocityY, OffsetX, OffsetY, scale, CenterX, CenterY, angle,
                     VelocityS, angleR, repeat);

        ArkUI_NumberValue value[] = {{.f32 = 0}, {.f32 = 0}, {.f32 = 0}, {.f32 = angleR}, {.f32 = 0}};
        ArkUI_AttributeItem item = {value, 5};
        auto column = reinterpret_cast<ArkUI_NodeHandle>(extraParam);
        nodeAPI->setAttribute(column, NODE_ROTATE, &item);
    };

    gestureApi->setGestureEventTarget(
        swipeGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column,
        onActionCallBack);

    // 将滑动手势添加到手势组
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, addChildGesture swipeGesture");
    }
    // 将手势组设置到组件上
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### 并行识别

并行识别组合手势对应的ArkUI_GroupGestureMode为PARALLEL_GROUP。并行识别组合手势中注册的手势将同时进行识别，直到所有手势识别结束。并行识别手势组合中的手势进行识别时互不影响。

以并行识别长按和滑动手势为例：

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // 创建手势并设置回调
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // 判断是否有手势API
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api not exist");
    }

    // 创建手势组
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::PARALLEL_GROUP);

    // 创建长按手势
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, 500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack,ArkUI_GestureRecognizerType%{public}d", type);
    }
    // 给长按手势定回调
    auto onActionCallBackPanLongPress = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float OffsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float OffsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float CenterX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float CenterY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float VelocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);

        OH_LOG_Print(
            LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
            "onPanActionCallBack,longPressGesturecallback actionType:%{public}d,velocity%{public}f,velocityX"
            "%{public}f;"
            "velocityY%{public}f,OffsetX%{public}f,OffsetY%{public}f,scale%{public}fCenterX"
            "%{public}fCenterY"
            "%{public}fangle%{public}fVelocityS%{public}fangleR%{public}frepeat%{public}f",
            actionType, velocity, velocityX, velocityY, OffsetX, OffsetY, scale, CenterX, CenterY, angle, VelocityS,
            angleR, repeat);
    };
    gestureApi->setGestureEventTarget(longPressGesture,
                                      GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE |
                                            GESTURE_EVENT_ACTION_CANCEL,
                                      column, onActionCallBackPanLongPress);

    // 将长按手势添加到手势组
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture longPressGesture");
    }
    // 创建滑动手势 swipe
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // 给滑动手势绑定回调
    auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float OffsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float OffsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float CenterX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float CenterY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float VelocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);


        // 通过日志查看
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, swipeGesture callback actionType: %{public}d, velocity "
                     "%{public}f,velocityX "
                     "%{public}f; "
                     "velocityY %{public}f, OffsetX %{public}f, OffsetY %{public}f, scale %{public}fCenterX "
                     "%{public}f CenterY"
                     " %{public}f angle %{public}f VelocityS %{public}f angleR %{public}f repeat %{public}f",
                     actionType, velocity, velocityX, velocityY, OffsetX, OffsetY, scale, CenterX, CenterY, angle,
                     VelocityS, angleR, repeat);

        ArkUI_NumberValue value[] = {{.f32 = 0}, {.f32 = 0}, {.f32 = 0}, {.f32 = angleR}, {.f32 = 0}};
        ArkUI_AttributeItem item = {value, 5};
        auto column = reinterpret_cast<ArkUI_NodeHandle>(extraParam);
        nodeAPI->setAttribute(column, NODE_ROTATE, &item);
    };

    gestureApi->setGestureEventTarget(
        swipeGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column,
        onActionCallBack);

    // 将滑动手势添加到手势组
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, addChildGesture swipeGesture");
    }
    // 将手势组设置到组件上
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### 互斥识别

互斥识别组合手势对应的ArkUI_GroupGestureMode为EXCLUSIVE_GROUP。互斥识别组合手势中注册的手势将同时进行识别，若有一个手势识别成功，则结束手势识别，其他所有手势识别失败。

以互斥识别平移手势和捏合手势为例：

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
    auto button = nodeAPI->createNode(ARKUI_NODE_BUTTON);

    // 创建手势并设置回调
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // 判断是否有手势API
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api not exist");
    }
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::EXCLUSIVE_GROUP);

    // 创建拖动手势
    auto panGesture = gestureApi->createPanGesture(1, GESTURE_DIRECTION_VERTICAL, 5);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(panGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack panGesture, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // 给拖动手势绑定回调
    auto onActionCallBackPan = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float OffsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float OffsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float CenterX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float CenterY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float VelocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);

        // 通过日志查看
        OH_LOG_Print(
            LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
            "onPanActionCallBack, panGesture callback actionType: %{public}d, velocity %{public}f,velocityX "
            "%{public}f; "
            "velocityY %{public}f, OffsetX %{public}f, OffsetY %{public}f, scale %{public}fCenterX "
            "%{public}f CenterY"
            " %{public}f angle %{public}f VelocityS %{public}f angleR %{public}f repeat %{public}f",
            actionType, velocity, velocityX, velocityY, OffsetX, OffsetY, scale, CenterX, CenterY, angle, VelocityS,
            angleR, repeat);
    };
    gestureApi->setGestureEventTarget(panGesture,
                                      GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE |
                                          GESTURE_EVENT_ACTION_END | GESTURE_EVENT_ACTION_CANCEL,
                                      column, onActionCallBackPan);
    // 将拖动手势添加到手势组
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, panGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture panGesture");
    }
    // 创建捏合手势
    auto pinchGesture = gestureApi->createPinchGesture(0, 0);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack pinchGesture, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // 给捏合手势绑定回调
    auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float OffsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float OffsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float CenterX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float CenterY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float VelocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);


        OH_LOG_Print(
            LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
            "onPanActionCallBack, pinchGesture callback actionType: %{public}d, velocity %{public}f,velocityX "
            "%{public}f; "
            "velocityY %{public}f, OffsetX %{public}f, OffsetY %{public}f, scale %{public}fCenterX "
            "%{public}f CenterY"
            " %{public}f angle %{public}f VelocityS %{public}f angleR %{public}f repeat %{public}f",
            actionType, velocity, velocityX, velocityY, OffsetX, OffsetY, scale, CenterX, CenterY, angle, VelocityS,
            angleR, repeat);


        ArkUI_NumberValue value[] = {{.f32 = scale}, {.f32 = scale}};
        ArkUI_AttributeItem item = {value, 2};
        auto column = reinterpret_cast<ArkUI_NodeHandle>(extraParam);
        nodeAPI->setAttribute(column, NODE_SCALE, &item);
    };
    gestureApi->setGestureEventTarget(pinchGesture,
                                      GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE |
                                          GESTURE_EVENT_ACTION_END | GESTURE_EVENT_ACTION_CANCEL,
                                      column, onActionCallBack);
    // 将捏合手势添加到手势组
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture pinchGesture");
    }
    // 将手势组设置到组件上
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### 自定义手势判定

支持自定义手势判定，当组件触发手势时，可根据回调内容判定当前响应的手势是否继续执行。

在上文绑定手势事件的示例中按照如下方式进行调整即可实现自定义手势判定。


1. 创建自定义手势判定回调。
   ```
       auto onInterruptCallback = [](ArkUI_GestureInterruptInfo *info) -> ArkUI_GestureInterruptResult {
           // 获取是否系统手势
           auto systag = OH_ArkUI_GestureInterruptInfo_GetSystemFlag(info);
           // 获取拦截的手势指针
           auto recognizer = OH_ArkUI_GestureInterruptInfo_GetRecognizer(info);
           // 获取系统手势类型
           auto systemRecognizerType = OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType(info);
           // 获取手势事件
           auto gestureEvent = OH_ArkUI_GestureInterruptInfo_GetGestureEvent(info);
           auto inputevent = OH_ArkUI_GestureEvent_GetRawInputEvent(gestureEvent);
   
           if (systag) {
               // 如果是系统手势则不拦截
               return GESTURE_INTERRUPT_RESULT_CONTINUE;
           } else {
               // 不是系统手势则拒绝
               return GESTURE_INTERRUPT_RESULT_REJECT;
           }
       };
   ```

2. 绑定手势判定和节点。
   ```
   gestureApi->setGestureInterrupterToNode(column, onInterruptCallback);
   ```


经过上述修改，将原本可以生效的长按手势做了拦截，即，此时再对Column节点长按将不会触发长按的手势回调。
