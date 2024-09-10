# Binding Gesture Events


The ArkUI development framework provides tap gestures, drag gestures, slide gestures, touch and hold gestures, pinch gestures, and rotate gestures in NDK interfaces. Different gestures are bound to specified components and corresponding callbacks are set to implement the expected gesture interaction capability.


The following uses a simple example to describe how to implement gesture binding.


1. Create a Column node to bind gestures.
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

2. Create a touch and hold gesture with a single finger for 1 second and continuously respond to the touch and hold gesture.
   ```
   // Obtain the native interface set of gestures.
   auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
               OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
   // Create a long press gesture.
   auto longPressGesture = gestureApi->createLongPressGesture(1, true, 1000);
   ```

3. Bind the created gesture to the Column node created in step 1.
   ```
   // Set the callbacks.
   auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
       // Callback content
   };
   
   // Set the gesture on the component.
   gestureApi->setGestureEventTarget(longPressGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column, onActionCallBack);
   
   gestureApi->addGestureToNode(column, longPressGesture, PARALLEL, NORMAL_GESTURE_MASK);
   ```


## Single gesture

If a gesture is bound to a node, the following describes how to create different gestures and which events can be called back.

- Tap gesture.
  You can bind a tap gesture to a widget to trigger the callback when the widget is tapped. You can specify the number of taps and the number of fingers required for triggering the callback.

  ```
  ArkUI_GestureRecognizer* (*createTapGesture)(int32_t countNum, int32_t fingersNum);
  ```

- Pan gesture.
  You can bind drag gestures to a widget to trigger callback when a user drags the widget. You can specify the number of fingers, drag direction, and drag distance required for triggering callback. The unit is px.
  ```
  ArkUI_GestureRecognizer* (*createPanGesture)(
  int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum);
  ```

- Long press gesture.
  You can bind a touch and hold gesture to a widget to trigger callback when a user touches and holds the widget. You can specify the number of fingers required for triggering callback, touch and hold time (unit: ms), and whether to trigger callback continuously.

  ```
  ArkUI_GestureRecognizer* (*createLongPressGesture)(int32_t fingersNum, bool repeatResult, int32_t durationNum);
  ```

- Pinch gesture.
  You can bind a pinch gesture to a widget to trigger callback when a user pinches the widget. You can specify the number of fingers (minimum: 2) and pinch distance (unit: px) required for triggering callback.

  ```
  ArkUI_GestureRecognizer* (*createPinchGesture)(int32_t fingersNum, double distanceNum);
  ```

- Rotation gesture.
  You can bind a rotation gesture to a widget to trigger callback when a user rotates the widget. You can specify the number of fingers (minimum: 2) and rotation angle required for triggering callback.

  ```
  ArkUI_GestureRecognizer* (*createRotationGesture)(int32_t fingersNum, double angleNum);
  ```

- Swipe gesture.
  You can bind a sliding gesture to a widget to trigger callback when a user slides the widget. You can specify the number of fingers (minimum: 1), sliding direction, and sliding speed (unit: px/s) required for triggering callback.

  ```
  ArkUI_GestureRecognizer* (*createSwipeGesture)(
  int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum);
  ```


## Combined Gestures

A combined gesture consists of multiple single gestures. Different ArkUI_GroupGestureModes are used in GroupGesture to declare the type of the combined gesture. Three types of combined gestures are supported: sequential recognition, parallel recognition, and mutually exclusive recognition.

ArkUI_GroupGestureMode enumeration class, which is used to declare the type of the combined gesture. SEQUENTIAL_GROUP is identified in sequence, PARALLEL_GROUP is identified in parallel, and EXCLUSIVE_GROUP is identified in mutual exclusion.


### Sequential Recognition

For sequential recognition, the value of **GestureMode** is **Sequence**. In this gesture recognition mode, gestures are recognized in the order in which they were registered until they are all recognized successfully. If any of the registered gestures fails to be recognized, all gestures fail to be recognized. Only the last gesture recognized responds to the **onActionEnd** event.

The following uses sequential recognition of touch and hold gestures and slide gestures as an example:

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    //Create a gesture and set a callback.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // API for determining whether there is a gesture
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

    Creates a long press gesture.
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, 500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack longPressGesture,ArkUI_GestureRecognizerType%{public}d", type);
    }
    //Set the callback function for the touch and hold gesture.
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

    //Add the touch and hold gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture longPressGesture");
    }
    //Create a swipe gesture.
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, ArkUI_GestureRecognizerType %{public}d", type);
    }
    //Bind the callback function to the sliding gesture.
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


        //View logs.
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

    //Add the slide gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, addChildGesture swipeGesture");
    }
    //Set the gesture group on the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### Parallel Recognition

For parallel recognition, the value of **GestureMode** is **Parallel**. In this gesture recognition mode, gestures registered in the combined gestures will be recognized at the same time until they are all recognized successfully. The gestures are recognized in parallel without affecting each other.

The following uses parallel recognition of touch and hold gestures and slide gestures as an example:

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    //Create a gesture and set a callback.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // API for determining whether there is a gesture
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, createGroupGesture api not exist");
    }

    Creates a gesture group.
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::PARALLEL_GROUP);

    Creates a long press gesture.
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, 500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack,ArkUI_GestureRecognizerType%{public}d", type);
    }
    //Set the callback function for the touch and hold gesture.
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

    //Add the touch and hold gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture longPressGesture");
    }
    //Create a swipe gesture.
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, ArkUI_GestureRecognizerType %{public}d", type);
    }
    //Bind the callback function to the sliding gesture.
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


        //View logs.
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

    //Add the slide gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack, addChildGesture swipeGesture");
    }
    //Set the gesture group on the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### Exclusive Recognition

For exclusive recognition, the value of **GestureMode** is **Exclusive**. In this gesture recognition mode, all registered gestures are recognized at once. Once any of the gestures is recognized successfully, the gesture recognition ends, and all other gestures fail to be recognized.

For example, a translation gesture and a pinch gesture are mutually exclusive.

```
ArkUI_NodeHandle testGestureExample() {
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
    auto button = nodeAPI->createNode(ARKUI_NODE_BUTTON);

    //Create a gesture and set a callback.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{200}};
    ArkUI_AttributeItem width = {widthValue, 1};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{200}};
    ArkUI_AttributeItem height = {heightValue, 1};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // API for determining whether there is a gesture
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

    Creates a pan gesture.
    auto panGesture = gestureApi->createPanGesture(1, GESTURE_DIRECTION_VERTICAL, 5);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(panGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack panGesture, ArkUI_GestureRecognizerType %{public}d", type);
    }
    //Bind the callback function to the drag gesture.
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

        //View logs.
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
    //Add the drag gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, panGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture panGesture");
    }
    Creates a pinch gesture.
    auto pinchGesture = gestureApi->createPinchGesture(0, 0);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager",
                     "onPanActionCallBack pinchGesture, ArkUI_GestureRecognizerType %{public}d", type);
    }
    //Bind the callback function to the pinch gesture.
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
    //Add the pinch gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "onPanActionCallBack, addChildGesture pinchGesture");
    }
    //Set the gesture group on the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


### Custom Gesture Judgment

Supports user-defined gesture determination. When a component triggers a gesture, the component can determine whether to continue the current gesture based on the callback content.

In the foregoing example of binding a gesture event, a customized gesture may be determined by performing adjustment in the following manner.


1. Creates a customized gesture determination callback function.
   ```
       auto onInterruptCallback = [](ArkUI_GestureInterruptInfo *info) -> ArkUI_GestureInterruptResult {
           //Obtain whether the gesture is a system gesture.
           auto systag = OH_ArkUI_GestureInterruptInfo_GetSystemFlag(info);
           //Obtain the intercepted gesture pointer.
           auto recognizer = OH_ArkUI_GestureInterruptInfo_GetRecognizer(info);
           //Obtain the system gesture type.
           auto systemRecognizerType = OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType(info);
           //Obtain the gesture event.
           auto gestureEvent = OH_ArkUI_GestureInterruptInfo_GetGestureEvent(info);
           auto inputevent = OH_ArkUI_GestureEvent_GetRawInputEvent(gestureEvent);
   
           if (systag) {
               //If the gesture is a system gesture, the gesture is not blocked.
               return GESTURE_INTERRUPT_RESULT_CONTINUE;
           } else {
               //Reject if the gesture is not a system gesture.
               return GESTURE_INTERRUPT_RESULT_REJECT;
           }
       };
   ```

2. Bind the gesture judgment and node.
   ```
   gestureApi->setGestureInterrupterToNode(column, onInterruptCallback);
   ```


After the foregoing modification, the touch-and-hold gesture that originally can take effect is intercepted. That is, in this case, touching and holding the Column node does not trigger callback of the touch-and-hold gesture.
