# Binding Gesture Events


The ArkUI development framework primarily provides click gestures, drag gestures, swipe gestures, long press gestures, pinch gestures, and rotation gestures through the NDK interface. By binding different gestures to specified components and setting corresponding callbacks, the desired gesture interaction capabilities can be achieved.


Below is a simple example to illustrate how to implement gesture binding.


1. Create a Column node for binding gestures.
   ```c
   // Create Column node
   auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
   // Set background color
   ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
   ArkUI_AttributeItem item = {value, 1};
   nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
   // Set width
   ArkUI_NumberValue widthValue[] = {{400}};
   ArkUI_AttributeItem width = {widthValue, 1};
   nodeAPI->setAttribute(column, NODE_WIDTH, &width);
   // Set height
   ArkUI_NumberValue heightValue[] = {{400}};
   ArkUI_AttributeItem height = {heightValue, 1};
   nodeAPI->setAttribute(column, NODE_HEIGHT, &height);
   ```

2. Create a long press gesture that responds to a single finger press for 1 second and continues to respond.
   ```
   // Get the gesture native interface collection
   auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
               OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
   // Create long press gesture
   auto longPressGesture = gestureApi->createLongPressGesture(1, true, 1000);
   ```

3. Bind the created gesture with the Column node created in step 1.
   ```
   // Set callback
   auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
       // Callback content
   };
   
   // Set the gesture on the component
   gestureApi->setGestureEventTarget(longPressGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column, onActionCallBack);
   
   gestureApi->addGestureToNode(column, longPressGesture, PARALLEL, NORMAL_GESTURE_MASK);
   ```


## Single Gestures

Through the examples in the previous text, we have learned how to bind gestures to nodes. Next, we will introduce the creation methods for different gestures and the event callbacks each supports.

- Tap Gesture
  By binding a tap gesture to a component, the callback can be triggered when the component is tapped. You can specify the number of taps and the number of fingers required to trigger the callback.

  ```c
  ArkUI_GestureRecognizer* (*createTapGesture)(int32_t countNum, int32_t fingersNum);
  ```

- Pan Gesture
  By binding a pan gesture to a component, the callback can be triggered when the user drags the component. You can specify the number of fingers, the direction of the drag, and the distance of the drag required to trigger the callback. The unit is in pixels (px).
  ```
  ArkUI_GestureRecognizer* (*createPanGesture)(
  int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum);
  ```

- Long Press Gesture
  By binding a long press gesture to a component, the callback can be triggered when the user long presses the component. You can specify the number of fingers, the duration of the long press in milliseconds, and whether to trigger continuously.

  ```
  ArkUI_GestureRecognizer* (*createLongPressGesture)(int32_t fingersNum, bool repeatResult, int32_t durationNum);
  ```

- Pinch Gesture
  By binding a pinch gesture to a component, the callback can be triggered when the user pinches the component. You can specify the minimum number of fingers required to trigger the callback, which is 2, and the pinch distance in pixels.

  ```
  ArkUI_GestureRecognizer* (*createPinchGesture)(int32_t fingersNum, double distanceNum);
  ```

- Rotation Gesture
  By binding a rotation gesture to a component, the callback can be triggered when the user rotates the component. You can specify the minimum number of fingers required to trigger the callback, which is 2, and the rotation angle.

  ```
  ArkUI_GestureRecognizer* (*createRotationGesture)(int32_t fingersNum, double angleNum);
  ```

- Swipe Gesture
  By binding a swipe gesture to a component, the callback can be triggered when the user swipes the component. You can specify the minimum number of fingers required to trigger the callback, which is 1, the direction of the swipe, and the swipe speed in pixels per second (px/s).

  ```
  ArkUI_GestureRecognizer* (*createSwipeGesture)(
  int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum);
  ```


## Composite Gestures

Composite gestures are composed of multiple single gestures. By using different `ArkUI_GroupGestureMode` in `GroupGesture`, the type of the composite gesture is declared, supporting three types: sequential recognition, parallel recognition, and exclusive recognition.

The `ArkUI_GroupGestureMode` enumeration is used to declare the type of the composite gesture. Sequential recognition is `SEQUENTIAL_GROUP`, parallel recognition is `PARALLEL_GROUP`, and exclusive recognition is `EXCLUSIVE_GROUP`.


### Sequential Recognition

The ArkUI_GroupGestureMode corresponding to sequential recognition composite gestures is SEQUENTIAL_GROUP. Sequential recognition composite gestures will recognize gestures in the order in which they are registered, until all gestures are successfully recognized. If a gesture fails to be recognized in a sequential recognition composite gesture, all gestures fail to be recognized. Only the last gesture in the sequential recognition gesture group can respond to GESTURE_EVENT_ACTION_END.

Take the example of sequential recognition of long press and swipe gestures:

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // Create gestures and set callbacks
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Check if there is a gesture API
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

    // Create a long press gesture
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, 500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack longPressGesture,ArkUI_GestureRecognizerType%{public}d", type);
    }
    // Set a callback for the long press gesture
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

    // Add the long press gesture to the gesture group
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture longPressGesture");
    }
    // Create a swipe gesture
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Bind a callback to the swipe gesture
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


        // View through logs
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

    // Add the swipe gesture to the gesture group
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, addChildGesture swipeGesture");
    }
    // Set the gesture group on the component
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```

### Parallel Recognition

The ArkUI_GroupGestureMode corresponding to parallel recognition composite gestures is PARALLEL_GROUP. The gestures registered in the parallel recognition composite gesture will be recognized simultaneously until all gestures are recognized. Gestures in a parallel recognition gesture group do not affect each other during recognition.

Take the example of parallel recognition of long press and swipe gestures:

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // Create gestures and set callbacks
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Check if there is a gesture API
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api not exist");
    }

    // Create a gesture group
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::PARALLEL_GROUP);

    // Create a long press gesture
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, 500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack,ArkUI_GestureRecognizerType%{public}d", type);
    }
    // Set a callback for the long press gesture
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

    // Add the long press gesture to the gesture group
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture longPressGesture");
    }
    // Create a swipe gesture
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Bind a callback to the swipe gesture
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


        // View through logs
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

    // Add the swipe gesture to the gesture group
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, addChildGesture swipeGesture");
    }
    // Set the gesture group on the component
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```

### Exclusive Recognition

The ArkUI_GroupGestureMode corresponding to exclusive recognition composite gestures is EXCLUSIVE_GROUP. The gestures registered in the exclusive recognition composite gesture will be recognized simultaneously. If one gesture is recognized successfully, gesture recognition ends, and all other gestures fail to be recognized.

Take the example of exclusive recognition of pan and pinch gestures:

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
    auto button = nodeAPI->createNode(ARKUI_NODE_BUTTON);

    // Create gestures and set callbacks
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Check if there is a gesture API
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

    // Create a pan gesture
    auto panGesture = gestureApi->createPanGesture(1, GESTURE_DIRECTION_VERTICAL, 5);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(panGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack panGesture, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Bind a callback to the pan gesture
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

        // View through logs
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
    // Add the pan gesture to the gesture group
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, panGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture panGesture");
    }
    // Create a pinch gesture
    auto pinchGesture = gestureApi->createPinchGesture(0, 0);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack pinchGesture, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Bind a callback to the pinch gesture
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
    // Add the pinch gesture to the gesture group
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture pinchGesture");
    }
    // Set the gesture group on the component
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### Custom Gesture Recognition

Custom gesture recognition is supported, allowing you to determine whether the gesture that triggers the component should continue to execute based on the callback content.

In the example of binding gesture events mentioned above, you can achieve custom gesture recognition by making the following adjustments.

1. Create a custom gesture recognition callback.
   ```
       auto onInterruptCallback = [](ArkUI_GestureInterruptInfo *info) -> ArkUI_GestureInterruptResult {
           // Get whether it is a system gesture
           auto systag = OH_ArkUI_GestureInterruptInfo_GetSystemFlag(info);
           // Get the intercepted gesture pointer
           auto recognizer = OH_ArkUI_GestureInterruptInfo_GetRecognizer(info);
           // Get the type of system gesture
           auto systemRecognizerType = OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType(info);
           // Get the gesture event
           auto gestureEvent = OH_ArkUI_GestureInterruptInfo_GetGestureEvent(info);
           auto inputevent = OH_ArkUI_GestureEvent_GetRawInputEvent(gestureEvent);
   
           if (systag) {
               // If it is a system gesture, do not intercept
               return GESTURE_INTERRUPT_RESULT_CONTINUE;
           } else {
               // If it is not a system gesture, reject it
               return GESTURE_INTERRUPT_RESULT_REJECT;
           }
       };
   ```

2. Bind the gesture recognition and the node.
   ```
   gestureApi->setGestureInterrupterToNode(column, onInterruptCallback);
   ```

With the above modifications, the originally effective long press gesture is intercepted, meaning that a long press on the Column node will no longer trigger the long press gesture callback.
