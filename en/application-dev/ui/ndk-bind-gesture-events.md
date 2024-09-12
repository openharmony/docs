# Binding Gesture Events


The ArkUI development framework provides tap, drag, swipe, long press, pinch, and rotation gestures through its NDK APIs. By binding different gestures to specified components and setting corresponding callbacks, you can achieve the desired gesture interaction capabilities.


The following is a simple example to illustrate how to implement gesture binding.


1. Create a **Column** node to which gestures will be bound.
   ```
   // Create a Column node.
   auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
   // Set the background color.
   ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
   ArkUI_AttributeItem item = {value, 1};
   nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
   // Set the width.
   ArkUI_NumberValue widthValue[] = {{400}};
   ArkUI_AttributeItem width = {widthValue, 1};
   nodeAPI->setAttribute(column, NODE_WIDTH, &width);
   //Set the height.
   ArkUI_NumberValue heightValue[] = {{400}};
   ArkUI_AttributeItem height = {heightValue, 1};
   nodeAPI->setAttribute(column, NODE_HEIGHT, &height);
   ```

2. Create a single-finger long-press gesture with a 1-second activation threshold.
   ```
   // Obtain the set of native gesture APIs.
   auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
               OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
   // Create a long press gesture.
   auto longPressGesture = gestureApi->createLongPressGesture(1, true, 1000);
   ```

3. Bind the created gesture to the **Column** node created in step 1.
   ```
   // Set the callback.
   auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
       // Callback content
   };
   
   // Set the gesture to the component.
   gestureApi->setGestureEventTarget(longPressGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column, onActionCallBack);
   
   gestureApi->addGestureToNode(column, longPressGesture, PARALLEL, NORMAL_GESTURE_MASK);
   ```


## Single Gestures

The following outlines how to create single gestures and the event callbacks they support:

- Tap gesture
  Triggers a callback on tap, set by the number of taps and fingers required.

  ```
  ArkUI_GestureRecognizer* (*createTapGesture)(int32_t countNum, int32_t fingersNum);
  ```

- Pan gesture
  Triggers a callback during dragging, set by the number of fingers, direction, and distance in px.
  ```
  ArkUI_GestureRecognizer* (*createPanGesture)(
  int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum);
  ```

- Long press gesture
  Triggers a callback on long press, set by the number of fingers, hold-down time in milliseconds, and repeatability.

  ```
  ArkUI_GestureRecognizer* (*createLongPressGesture)(int32_t fingersNum, bool repeatResult, int32_t durationNum);
  ```

- Pinch gesture
  Triggers a callback on pinching, set by the number of fingers (at least 2) and the pinch distance (in px).

  ```
  ArkUI_GestureRecognizer* (*createPinchGesture)(int32_t fingersNum, double distanceNum);
  ```

- Rotation gesture
  Triggers a callback on rotation, set by the number of fingers (at least 2) and angle.

  ```
  ArkUI_GestureRecognizer* (*createRotationGesture)(int32_t fingersNum, double angleNum);
  ```

- Swipe gesture
  Triggers a callback on swiping, set by the number of fingers (at least 1), direction, and speed in px/s.

  ```
  ArkUI_GestureRecognizer* (*createSwipeGesture)(
  int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum);
  ```


## Combined Gestures

Combined gestures are created by combining multiple single gestures, and their types are declared with **ArkUI_GroupGestureMode** in **GroupGesture**.

**ArkUI_GroupGestureMode** supports the following options: **SEQUENTIAL_GROUP** (sequential recognition), **PARALLEL_GROUP** (parallel recognition), **EXCLUSIVE_GROUP** (exclusive recognition).


### Sequential Recognition

For combined gestures with sequential recognition, the value of **ArkUI_GroupGestureMode** is **SEQUENTIAL_GROUP**. In this gesture recognition mode, gestures are recognized in the order they were registered until they are all recognized successfully. If any of the registered gestures fails to be recognized, subsequent gestures will also fail. Only the last gesture in a sequential group can respond to the **GESTURE_EVENT_ACTION_END** event.

The following demonstrates how to create a combined gesture that recognizes a long press followed by a swipe in sequence:

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // Create a Column node.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Check for the gesture API.
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

    // Create a long press gesture.
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, 500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack longPressGesture,ArkUI_GestureRecognizerType%{public}d", type);
    }
    // Set a callback for the long press gesture.
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

    // Add the long press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture longPressGesture");
    }
    // Create a swipe gesture.
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Set a callback for the swipe gesture.
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


        // Print logs.
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

    // Add the swipe press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, addChildGesture swipeGesture");
    }
    // Set the gesture group to the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### Parallel Recognition

For combined gestures with parallel recognition, the value of **ArkUI_GroupGestureMode** is **PARALLEL_GROUP**. In this gesture recognition mode, gestures registered in the combined gestures will be recognized at the same time until they are all recognized successfully. The gestures are recognized in parallel without affecting each other.

The following demonstrates how to create a combined gesture that recognizes long press and swipe gestures in parallel:

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // Create a Column node.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Check for the gesture API.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api not exist");
    }

    // Create a gesture group.
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::PARALLEL_GROUP);

    // Create a long press gesture.
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, 500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack,ArkUI_GestureRecognizerType%{public}d", type);
    }
    // Set a callback for the long press gesture.
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

    // Add the long press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture longPressGesture");
    }
    // Create a swipe gesture.
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Set a callback for the swipe gesture.
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


        // Print logs.
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

    // Add the swipe press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, addChildGesture swipeGesture");
    }
    // Set the gesture group to the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### Exclusive Recognition

For combined gestures with exclusive recognition, the value of **ArkUI_GroupGestureMode** is **EXCLUSIVE_GROUP**. In this gesture recognition mode, all registered gestures are recognized at once. Once any of the gestures is recognized successfully, the gesture recognition ends, and recognition for all other gestures fails.

The following example illustrates the exclusive recognition of pan and pinch gestures:

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
    auto button = nodeAPI->createNode(ARKUI_NODE_BUTTON);

    // Create a Column node.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Check for the gesture API.
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

    // Create a pan gesture.
    auto panGesture = gestureApi->createPanGesture(1, GESTURE_DIRECTION_VERTICAL, 5);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(panGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack panGesture, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Set a callback for the pan gesture.
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

        // Print logs.
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
    // Add the pan press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, panGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture panGesture");
    }
    // Create a pinch gesture.
    auto pinchGesture = gestureApi->createPinchGesture(0, 0);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack pinchGesture, ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Set a callback for the pinch gesture.
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
    // Add the pinch press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture pinchGesture");
    }
    // Set the gesture group to the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### Custom Gesture Judgment

With support for custom gesture judgment, you can determine whether to continue executing a gesture based on callback content.

To implement custom gesture judgment, adjust the example of binding gesture events as follows:


1. Create a custom gesture judgment callback.
   ```
       auto onInterruptCallback = [](ArkUI_GestureInterruptInfo *info) -> ArkUI_GestureInterruptResult {
           // Check whether the gesture is a system gesture.
           auto systag = OH_ArkUI_GestureInterruptInfo_GetSystemFlag(info);
           // Obtain the gesture recognizer for gesture interception.
           auto recognizer = OH_ArkUI_GestureInterruptInfo_GetRecognizer(info);
           // Obtain the system gesture type.
           auto systemRecognizerType = OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType(info);
           // Obtain the gesture event.
           auto gestureEvent = OH_ArkUI_GestureInterruptInfo_GetGestureEvent(info);
           auto inputevent = OH_ArkUI_GestureEvent_GetRawInputEvent(gestureEvent);
   
           if (systag) {
               // If the gesture is a system gesture, do not intercept it.
               return GESTURE_INTERRUPT_RESULT_CONTINUE;
           } else {
               // If the gesture is not a system gesture, intercept and reject it.
               return GESTURE_INTERRUPT_RESULT_REJECT;
           }
       };
   ```

2. Bind the custom gesture interrupter to the node.
   ```
   gestureApi->setGestureInterrupterToNode(column, onInterruptCallback);
   ```


After the aforementioned modifications, the originally effective long press gesture is intercepted. Consequently, long pressing on the **Column** node will no longer trigger the long press gesture callback.
