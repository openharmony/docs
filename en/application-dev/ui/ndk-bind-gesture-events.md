# Binding Gesture Events
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->


The ArkUI development framework provides tap, pan, swipe, long press, pinch, and rotation gestures through its NDK APIs. By binding different gestures to specified components and setting corresponding callbacks, you can achieve the desired gesture interaction capabilities.


The following is a simple example to illustrate how to implement gesture binding.


1. Create a **Column** node to which gestures will be bound.
    <!-- @[create_column](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
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
    <!-- @[create_long_press_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
    // Obtain the set of native gesture APIs.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    // Create a long press gesture.
    // DURATION_NUM_1000 = 1000
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, DURATION_NUM_1000);
    ```


3. Bind the created gesture to the **Column** node created in step 1.
    <!-- @[bind_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
    auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
        // Callback content
        // ···
    };
    
    // Set the gesture to the component.
    gestureApi->setGestureEventTarget(
        longPressGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column,
        onActionCallBack);
    
    gestureApi->addGestureToNode(column, longPressGesture, PARALLEL, NORMAL_GESTURE_MASK);
    ```


## Single Gestures

The following introduces how to create different types of gestures:

- Tap gesture

  Triggers a callback when the component is tapped. You can specify the number of taps required and the number of fingers needed.

  <!-- @[create_tap_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
    // Obtain the set of native gesture APIs.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    // Create a tap gesture.
    auto tapGesture = gestureApi->createTapGesture(1, 1);
    ```


- Pan gesture

  Triggers a callback when the user performs a pan gesture on the component. You can specify the required number of fingers, pan direction, and pan distance (in px).
  <!-- @[create_pan_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
    // Obtain the set of native gesture APIs.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    // Create a pan gesture.
    auto panGesture = gestureApi->createPanGesture(1, GESTURE_DIRECTION_ALL, 1);
    ```


- Long press gesture

  Triggers a callback when the user long presses the component. You can specify the number of fingers, hold-down time in milliseconds, and repeatability.

  <!-- @[create_long_press_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
    // Obtain the set of native gesture APIs.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    // Create a long press gesture.
    // DURATION_NUM_1000 = 1000
    auto longPressGesture = gestureApi->createLongPressGesture(1, true, DURATION_NUM_1000);
    ```


- Pinch gesture

  Triggers a callback when the user pinches the component. You can specify the number of fingers (at least 2) and the pinch distance (in px).

  <!-- @[create_pinch_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
  
  ``` C
  // Obtain the set of native gesture APIs.
  auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
  // Create a pinch gesture.
  // NUMBER_2 = 2, NUMBER_10 = 10
  auto pinchGesture = gestureApi->createPinchGesture(NUMBER_2, NUMBER_10);
  ```


- Rotation gesture

  Triggers a callback when the user rotates the component. You can specify the number of fingers (at least 2) and angle.

  <!-- @[create_rotation_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
  
  ``` C
  // Obtain the set of native gesture APIs.
  auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
      OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
  // Create a rotation gesture.
  // NUMBER_2 = 2, NUMBER_10 = 10
  auto rotationGesture = gestureApi->createRotationGesture(NUMBER_2, NUMBER_10);
  ```


- Swipe gesture

  Triggers a callback when a swipe gesture is detected on the component. You can specify the required number of fingers (at least 1), swipe direction, and minimum velocity (in px/s).

  <!-- @[create_swiper_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
    // Obtain the set of native gesture APIs.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    // Create a swipe gesture.
    // SPEED_NUM_50 = 50
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, SPEED_NUM_50);
    ```



## Combined Gestures

You can combine multiple gestures of different types into a gesture group, which acts as an integrated recognizer to identify sequences of different user gestures.

The recognition mode of the gesture group (that is, the relationship between gestures in the group) is specified by setting [ArkUI_GroupGestureMode](../reference/apis-arkui/capi-native-gesture-h.md#arkui_groupgesturemode), including sequential recognition (**SEQUENTIAL_GROUP**), parallel recognition (**PARALLEL_GROUP**), and exclusive recognition (**EXCLUSIVE_GROUP**).


### Sequential Recognition

For combined gestures with sequential recognition, the value of **ArkUI_GroupGestureMode** is **SEQUENTIAL_GROUP**. In this gesture recognition mode, gestures are recognized in the order they were registered until they are all recognized successfully. If any of the registered gestures fails to be recognized, subsequent gestures will also fail. Only the last gesture in a sequential group can respond to the [GESTURE_EVENT_ACTION_END](../reference/apis-arkui/capi-native-gesture-h.md#arkui_gestureeventactiontype) event.

The following demonstrates how to create a combined gesture that recognizes long press and swipe gestures in sequence:

<!-- @[long_press_and_swipe_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/LongPressAndSwipeGesture.h) -->

``` C
// LongPressAndSwipeGesture.h
#include <arkui/native_animate.h>
#include <arkui/native_gesture.h>
#include <arkui/native_interface.h>
#include <arkui/native_node.h>
#include <arkui/native_type.h>
#include <arkui/native_node_napi.h>
#include <hilog/log.h>
#include "Common.h"
#include "Function.h"
// ...
ArkUI_NodeHandle LongPressAndSwipeGesture()
{
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // Create a node.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, ITEM_SIZE_ONE};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{WIDTH_SIZE}};
    ArkUI_AttributeItem width = {widthValue, ITEM_SIZE_ONE};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{HEIGHT_SIZE}};
    ArkUI_AttributeItem height = {heightValue, ITEM_SIZE_ONE};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Verify gesture API availability.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, createGroupGesture api not exist");
    }
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::SEQUENTIAL_GROUP);

    // Create a long press gesture.
    auto longPressGesture = gestureApi->createLongPressGesture(FINGERS_NUM, true, DURATION_NUM);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog longPressGesture,"
                     "ArkUI_GestureRecognizerType%{public}d", type);
    }
    // Bind a callback to the long press gesture.
    auto onActionCallBackPanLongPress = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float offsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float offsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float centerX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float centerY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float velocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);

        OH_LOG_Print(
            LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
            "NdkAddInteractionEvent_GestureSampleLog,longPressGesturecallback actionType:%{public}d,"
            "velocity%{public}f,velocityX%{public}f;"
            "velocityY%{public}f,offsetX%{public}f,offsetY%{public}f,scale%{public}fcenterX"
            "%{public}fcenterY"
            "%{public}fangle%{public}fvelocityS%{public}fangleR%{public}frepeat%{public}f",
            actionType, velocity, velocityX, velocityY, offsetX, offsetY, scale, centerX, centerY, angle, velocityS,
            angleR, repeat);
    };
    gestureApi->setGestureEventTarget(longPressGesture,
                                      GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE |
                                      GESTURE_EVENT_ACTION_CANCEL, column, onActionCallBackPanLongPress);

    // Add the long press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, addChildGesture longPressGesture");
    }
    // Create a swipe gesture.
    auto swipeGesture = gestureApi->createSwipeGesture(1, GESTURE_DIRECTION_ALL, 100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, ArkUI_GestureRecognizerType %{public}d",
                     type);
    }
    // Set a callback for the swipe gesture.
    auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float offsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float offsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float centerX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float centerY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float velocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);
        
        // Print logs.
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, swipeGesture "
                     "callback actionType: %{public}d, velocity %{public}f,velocityX "
                     "%{public}f; "
                     "velocityY %{public}f, offsetX %{public}f, offsetY %{public}f, scale %{public}fcenterX "
                     "%{public}f centerY"
                     " %{public}f angle %{public}f velocityS %{public}f angleR %{public}f repeat %{public}f",
                     actionType, velocity, velocityX, velocityY, offsetX, offsetY, scale, centerX, centerY, angle,
                     velocityS, angleR, repeat);

        ArkUI_NumberValue value[] = {{.f32 = 0}, {.f32 = 0}, {.f32 = 0}, {.f32 = angleR}, {.f32 = 0}};
        ArkUI_AttributeItem item = {value, ITEM_SIZE_FIVE};
        auto column = reinterpret_cast<ArkUI_NodeHandle>(extraParam);
        nodeAPI->setAttribute(column, NODE_ROTATE, &item);
    };

    gestureApi->setGestureEventTarget(
        swipeGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column,
        onActionCallBack);

    // Add the swipe gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, addChildGesture swipeGesture");
    }
    // Set the gesture group to the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


**Sample**

For details about the complete example, see<!--RP1-->[Sample Project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent)<!--RP1End-->.

### Parallel Recognition

For combined gestures with parallel recognition, the value of **ArkUI_GroupGestureMode** is **PARALLEL_GROUP**. In this gesture recognition mode, gestures registered in the combined gestures will be recognized at the same time until they are all recognized successfully. The gestures are recognized in parallel without affecting each other.

The following demonstrates how to create a combined gesture that recognizes long press and swipe gestures in parallel:

<!-- @[long_press_and_flick_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/LongPressAndFlickGesture.h) -->

``` C
// LongPressAndFlickGesture.h
#include <arkui/native_animate.h>
#include <arkui/native_gesture.h>
#include <arkui/native_interface.h>
#include <arkui/native_node.h>
#include <arkui/native_type.h>
#include <arkui/native_node_napi.h>
#include <hilog/log.h>
#include "Common.h"
#include "Function.h"
// ...

ArkUI_NodeHandle LongPressAndFlickGesture()
{
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // Create a node.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, ITEM_SIZE_ONE};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{WIDTH_SIZE}};
    ArkUI_AttributeItem width = {widthValue, ITEM_SIZE_ONE};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{HEIGHT_SIZE}};
    ArkUI_AttributeItem height = {heightValue, ITEM_SIZE_ONE};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Verify gesture API availability.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, createGroupGesture api not exist");
    }

    // Create a gesture group.
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::PARALLEL_GROUP);

    // Create a long press gesture.
    auto longPressGesture = gestureApi->createLongPressGesture(FINGERS_NUM, true, DURATION_NUM_500);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog,ArkUI_GestureRecognizerType%{public}d", type);
    }
    // Bind a callback to the long press gesture.
    auto onActionCallBackPanLongPress = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float offsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float offsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float centerX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float centerY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float velocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);

        OH_LOG_Print(
            LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
            "NdkAddInteractionEvent_GestureSampleLog,longPressGesturecallback actionType:%{public}d,"
            "velocity%{public}f,velocityX%{public}f;"
            "velocityY%{public}f,offsetX%{public}f,offsetY%{public}f,scale%{public}f, centerX "
            "%{public}fcenterY"
            "%{public}fangle%{public}fvelocityS%{public}fangleR%{public}frepeat%{public}f",
            actionType, velocity, velocityX, velocityY, offsetX, offsetY, scale, centerX, centerY, angle, velocityS,
            angleR, repeat);
    };
    gestureApi->setGestureEventTarget(longPressGesture,
                                      GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE |
                                            GESTURE_EVENT_ACTION_CANCEL,
                                      column, onActionCallBackPanLongPress);

    // Add the long press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, longPressGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, addChildGesture longPressGesture");
    }
    // Create a swipe gesture.
    auto swipeGesture = gestureApi->createSwipeGesture(FINGERS_NUM, GESTURE_DIRECTION_ALL, DURATION_NUM_100);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, ArkUI_GestureRecognizerType %{public}d",
                     type);
    }
    // Set a callback for the swipe gesture.
    auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float offsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float offsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float centerX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float centerY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float velocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);
        
        // Print logs.
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, swipeGesture "
                     "callback actionType: %{public}d, velocity%{public}f,velocityX "
                     "%{public}f; "
                     "velocityY %{public}f, offsetX %{public}f, offsetY %{public}f, scale %{public}f, centerX "
                     "%{public}f centerY"
                     " %{public}f angle %{public}f velocityS %{public}f angleR %{public}f repeat %{public}f",
                     actionType, velocity, velocityX, velocityY, offsetX, offsetY, scale, centerX, centerY, angle,
                     velocityS, angleR, repeat);

        ArkUI_NumberValue value[] = {{.f32 = 0}, {.f32 = 0}, {.f32 = 0}, {.f32 = angleR}, {.f32 = 0}};
        ArkUI_AttributeItem item = {value, ITEM_SIZE_FIVE};
        auto column = reinterpret_cast<ArkUI_NodeHandle>(extraParam);
        nodeAPI->setAttribute(column, NODE_ROTATE, &item);
    };

    gestureApi->setGestureEventTarget(
        swipeGesture, GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE | GESTURE_EVENT_ACTION_END, column,
        onActionCallBack);

    // Add the swipe gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, swipeGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, addChildGesture swipeGesture");
    }
    // Set the gesture group to the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


**Sample**

For details about the complete example, see<!--RP2-->[Sample Project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent)<!--RP2End-->.

### Exclusive Recognition

For combined gestures with exclusive recognition, the value of **ArkUI_GroupGestureMode** is **EXCLUSIVE_GROUP**. In this gesture recognition mode, all registered gestures are recognized at once. Once any of the gestures is recognized successfully, the gesture recognition ends, and recognition for all other gestures fails.

The following example illustrates the exclusive recognition of pan and pinch gestures:

<!-- @[swipe_and_pinch_exclusive_gesture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/SwipeAndPinchExclusiveGesture.h) -->

``` C
// SwipeAndPinchExclusiveGesture.h
#include <arkui/native_animate.h>
#include <arkui/native_gesture.h>
#include <arkui/native_interface.h>
#include <arkui/native_node.h>
#include <arkui/native_type.h>
#include <arkui/native_node_napi.h>
#include <hilog/log.h>
#include "Common.h"
#include "Function.h"
// ...

ArkUI_NodeHandle SwipeAndPinchExclusiveGesture()
{
    OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeAPI);
    if (nodeAPI == nullptr) {
        return nullptr;
    }
    auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);

    // Create a node.
    ArkUI_NumberValue value[] = {{.u32 = 0xff112233}};
    ArkUI_AttributeItem item = {value, 1};
    nodeAPI->setAttribute(column, NODE_BACKGROUND_COLOR, &item);
    ArkUI_NumberValue widthValue[] = {{WIDTH_SIZE}};
    ArkUI_AttributeItem width = {widthValue, ITEM_SIZE_ONE};
    nodeAPI->setAttribute(column, NODE_WIDTH, &width);
    ArkUI_NumberValue heightValue[] = {{HEIGHT_SIZE}};
    ArkUI_AttributeItem height = {heightValue, ITEM_SIZE_ONE};
    nodeAPI->setAttribute(column, NODE_HEIGHT, &height);

    // Verify gesture API availability.
    auto gestureApi = reinterpret_cast<ArkUI_NativeGestureAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"));
    if (gestureApi->createGroupGesture) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, createGroupGesture api exist");
    } else {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, createGroupGesture api not exist");
    }
    auto groupGesture = gestureApi->createGroupGesture(ArkUI_GroupGestureMode::EXCLUSIVE_GROUP);

    // Create a pan gesture.
    auto panGesture = gestureApi->createPanGesture(FINGERS_NUM, GESTURE_DIRECTION_VERTICAL, DURATION_NUM);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(panGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog panGesture, ArkUI_GestureRecognizerType %{public}d",
                     type);
    }
    // Set a callback for the swipe gesture.
    auto onActionCallBackPan = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float offsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float offsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float centerX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float centerY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float velocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);

        // Print logs.
        OH_LOG_Print(
            LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
            "NdkAddInteractionEvent_GestureSampleLog, panGesture callback actionType: %{public}d, "
            "velocity %{public}f,velocityX %{public}f; "
            "velocityY %{public}f, offsetX %{public}f, offsetY %{public}f, scale %{public}fcenterX "
            "%{public}f centerY"
            " %{public}f angle %{public}f velocityS %{public}f angleR %{public}f repeat %{public}f",
            actionType, velocity, velocityX, velocityY, offsetX, offsetY, scale, centerX, centerY, angle, velocityS,
            angleR, repeat);
    };
    gestureApi->setGestureEventTarget(panGesture,
                                      GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE |
                                          GESTURE_EVENT_ACTION_END | GESTURE_EVENT_ACTION_CANCEL,
                                      column, onActionCallBackPan);
    // Add the swipe press gesture to the gesture group.
    if (gestureApi->addChildGesture) {
        gestureApi->addChildGesture(groupGesture, panGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, addChildGesture panGesture");
    }
    // Create a pinch gesture.
    // NUMBER_2 = 2, NUMBER_10 = 10
    auto pinchGesture = gestureApi->createPinchGesture(NUMBER_2, NUMBER_10);
    if (gestureApi->getGestureType) {
        ArkUI_GestureRecognizerType type = gestureApi->getGestureType(pinchGesture);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog pinchGesture, "
                     "ArkUI_GestureRecognizerType %{public}d", type);
    }
    // Set a callback for the pinch gesture.
    auto onActionCallBack = [](ArkUI_GestureEvent *event, void *extraParam) {
        ArkUI_GestureEventActionType actionType = OH_ArkUI_GestureEvent_GetActionType(event);

        float velocity = OH_ArkUI_PanGesture_GetVelocity(event);
        float velocityX = OH_ArkUI_PanGesture_GetVelocityX(event);
        float velocityY = OH_ArkUI_PanGesture_GetVelocityY(event);
        float offsetX = OH_ArkUI_PanGesture_GetOffsetX(event);
        float offsetY = OH_ArkUI_PanGesture_GetOffsetY(event);
        float scale = OH_ArkUI_PinchGesture_GetScale(event);
        float centerX = OH_ArkUI_PinchGesture_GetCenterX(event);
        float centerY = OH_ArkUI_PinchGesture_GetCenterY(event);
        float angle = OH_ArkUI_SwipeGesture_GetAngle(event);
        float velocityS = OH_ArkUI_SwipeGesture_GetVelocity(event);
        float angleR = OH_ArkUI_RotationGesture_GetAngle(event);
        float repeat = OH_ArkUI_LongPress_GetRepeatCount(event);
        
        OH_LOG_Print(
            LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
            "NdkAddInteractionEvent_GestureSampleLog, pinchGesture callback actionType: %{public}d, "
            "velocity %{public}f,velocityX %{public}f; "
            "velocityY %{public}f, offsetX %{public}f, offsetY %{public}f, scale %{public}fcenterX "
            "%{public}f centerY"
            " %{public}f angle %{public}f velocityS %{public}f angleR %{public}f repeat %{public}f",
            actionType, velocity, velocityX, velocityY, offsetX, offsetY, scale, centerX, centerY, angle, velocityS,
            angleR, repeat);
        ArkUI_NumberValue value[] = {{.f32 = scale}, {.f32 = scale}};
        ArkUI_AttributeItem item = {value, ITEM_SIZE_TWO};
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
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_GestureSampleLog, addChildGesture pinchGesture");
    }
    // Set the gesture group to the component.
    gestureApi->addGestureToNode(column, groupGesture, PRIORITY, NORMAL_GESTURE_MASK);
    return column;
}
```


**Sample**

For details about the complete example, see<!--RP3-->[Sample Project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent)<!--RP3End-->.

### Custom Gesture Judgment

Custom gesture judgment allows you to dynamically decide whether a gesture recognizer should be considered successful by the system when a user's action matches a gesture recognizer and the gesture recognizer is about to be triggered successfully. This is achieved by binding a callback to the target component using the **setGestureInterrupterToNode** API. When a gesture on that component is about to be successfully recognized, the callback returns **CONTINUE** or **REJECT** to whether to allow other gesture recognizers to take over the success opportunity.

To implement custom gesture judgment, adjust the example of binding gesture events as follows:


1. Create a custom gesture judgment callback.
    <!-- @[create_custom_gestures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
    auto onInterruptCallback = [](ArkUI_GestureInterruptInfo *info) -> ArkUI_GestureInterruptResult {
        // Check whether the gesture is a system gesture.
        auto sysTag = OH_ArkUI_GestureInterruptInfo_GetSystemFlag(info);
        // Obtain the gesture recognizer for gesture interception.
        auto recognizer = OH_ArkUI_GestureInterruptInfo_GetRecognizer(info);
        // Obtain the system gesture type.
        auto systemRecognizerType = OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType(info);
        // Obtain the gesture event.
        auto gestureEvent = OH_ArkUI_GestureInterruptInfo_GetGestureEvent(info);
        auto inputEvent = OH_ArkUI_GestureEvent_GetRawInputEvent(gestureEvent);
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
            "NdkAddInteractionEvent_eventInfo longPressGesture");
        if (sysTag) {
            // If the gesture is a system gesture, do not intercept it.
            return GESTURE_INTERRUPT_RESULT_CONTINUE;
        } else {
            // If the gesture is not a system gesture, intercept and reject it.
            return GESTURE_INTERRUPT_RESULT_REJECT;
        }
    };
    ```


2. Bind the custom gesture interrupter to the node.
    <!-- @[bind_gestures](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
    
    ``` C
    gestureApi->setGestureInterrupterToNode(column, onInterruptCallback);
    ```



After the aforementioned modifications, the originally effective long press gesture is intercepted. Consequently, long pressing the **Column** node will no longer trigger the long press gesture callback.

## Obtaining Event Information

After binding gesture events to nodes as previously described, you can use [OH_ArkUI_GestureEvent_GetRawInputEvent()](../reference/apis-arkui/capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent) to obtain the basic event object from the gesture event when the gesture callback is executed. Then, you can call APIs such as [OH_ArkUI_PointerEvent_GetDisplayX()](../reference/apis-arkui/capi-ui-input-event-h.md#oh_arkui_pointerevent_getdisplayx), [OH_ArkUI_PointerEvent_GetDisplayXByIndex()](../reference/apis-arkui/capi-ui-input-event-h.md#oh_arkui_pointerevent_getdisplayxbyindex), [OH_ArkUI_UIInputEvent_GetAction()](../reference/apis-arkui/capi-ui-input-event-h.md#oh_arkui_uiinputevent_getaction), and [OH_ArkUI_UIInputEvent_GetEventTime()](../reference/apis-arkui/capi-ui-input-event-h.md#oh_arkui_uiinputevent_geteventtime) to obtain more information from the basic event. Applications can implement differentiated interaction logic during gesture event execution based on the obtained information.


  <!-- @[gesture_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->
  
  ``` C
  // Set a callback to handle gesture events when they are triggered.
  auto onActionCallback = [](ArkUI_GestureEvent *event, void *extraParams) {
      // Obtain the basic event object from the gesture event.
      auto *inputEvent = OH_ArkUI_GestureEvent_GetRawInputEvent(event);
      // Obtain event information from the basic event.
      auto x = OH_ArkUI_PointerEvent_GetX(inputEvent);
      auto y = OH_ArkUI_PointerEvent_GetY(inputEvent);
      auto displayX = OH_ArkUI_PointerEvent_GetDisplayX(inputEvent);
      auto displayY = OH_ArkUI_PointerEvent_GetDisplayY(inputEvent);
      auto windowX = OH_ArkUI_PointerEvent_GetWindowX(inputEvent);
      auto windowY = OH_ArkUI_PointerEvent_GetWindowY(inputEvent);
      auto pointerCount = OH_ArkUI_PointerEvent_GetPointerCount(inputEvent);
      auto xByIndex = OH_ArkUI_PointerEvent_GetXByIndex(inputEvent, 0);
      auto yByIndex = OH_ArkUI_PointerEvent_GetYByIndex(inputEvent, 0);
      auto displayXByIndex = OH_ArkUI_PointerEvent_GetDisplayXByIndex(inputEvent, 0);
      auto displayYByIndex = OH_ArkUI_PointerEvent_GetDisplayYByIndex(inputEvent, 0);
      auto windowXByIndex = OH_ArkUI_PointerEvent_GetWindowXByIndex(inputEvent, 0);
      auto windowYByIndex = OH_ArkUI_PointerEvent_GetWindowYByIndex(inputEvent, 0);
      auto pointerId = OH_ArkUI_PointerEvent_GetPointerId(inputEvent, 0);
      auto pressure = OH_ArkUI_PointerEvent_GetPressure(inputEvent, 0);
      auto action = OH_ArkUI_UIInputEvent_GetAction(inputEvent);
      auto eventTime = OH_ArkUI_UIInputEvent_GetEventTime(inputEvent);
      auto sourceType = OH_ArkUI_UIInputEvent_GetSourceType(inputEvent);
      auto type = OH_ArkUI_UIInputEvent_GetType(inputEvent);
      std::string eventInfo =
          "x: " + std::to_string(x) + ", y: " + std::to_string(y) +
          ", displayX: " + std::to_string(displayX) + ", displayY: " + std::to_string(displayY) +
          ", windowX: " + std::to_string(windowX) + ", windowY: " + std::to_string(windowY) + "\n" +
          ", pointerCount: " + std::to_string(pointerCount) + ", xByIndex: " + std::to_string(xByIndex) +
          ", yByIndex: " + std::to_string(yByIndex) +
          ", displayXByIndex: " + std::to_string(displayXByIndex) +
          ", displayYByIndex: " + std::to_string(displayYByIndex) +
          ", windowXByIndex: " + std::to_string(windowXByIndex) +
          ", windowYByIndex: " + std::to_string(windowYByIndex) + "\n" +
          ", pointerId: " + std::to_string(pointerId) + ", pressure: " + std::to_string(pressure) +
          ", action: " + std::to_string(action) + ", eventTime: " + std::to_string(eventTime) +
          ", sourceType: " + std::to_string(sourceType) + ", type: " + std::to_string(type);
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                   "NdkAddInteractionEvent_eventInfoOfCommonEvent eventInfo = %{public}s", eventInfo.c_str());
  };
  // Create a single-finger tap gesture.
  auto TapGesture = gestureApi->createTapGesture(COUNT_NUM_1, FINGERS_NUM_1);
  // Bind the event callback to TapGesture. After the gesture is triggered, the callback function processes the gesture event.
  gestureApi->setGestureEventTarget(TapGesture,
                                    GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE |
                                    GESTURE_EVENT_ACTION_END | GESTURE_EVENT_ACTION_CANCEL,
                                    column, onActionCallback);
  // Add a gesture to the column component so that the column component can trigger the single-finger tap gesture.
  gestureApi->addGestureToNode(column, TapGesture, ArkUI_GesturePriority::PARALLEL,
                               ArkUI_GestureMask::NORMAL_GESTURE_MASK);
  ```

## Customizing the Collection Result of Events and Gestures

Since API version 26.0.0, when a gesture or touch event is initiated, the system collects the recognition results of the bound gesture and touch recognizers. You can intervene in the collected response recognizers and touch recognizers within the `NODE_ON_GESTURE_COLLECT_INTERCEPT` callback, and dynamically control the collection behavior of recognizers by setting collection interception policies, for example, discarding recognition results from specific nodes.

The following example demonstrates how to implement custom interception of event and gesture collection results.

1. Register the `NODE_ON_GESTURE_COLLECT_INTERCEPT` node event and bind the callback handler. In the callback, use [OH_ArkUI_GestureCollectInterceptInfo_GetResponseRecognizers](../reference/apis-arkui/capi-native-gesture-h.md#oh_arkui_gesturecollectinterceptinfo_getresponserecognizers) to obtain the gesture recognizers, and [OH_ArkUI_GestureCollectInterceptInfo_GetTouchRecognizers](../reference/apis-arkui/capi-native-gesture-h.md#oh_arkui_gesturecollectinterceptinfo_gettouchrecognizers) to obtain the touch recognizers, then combine them with the handler to complete the interception.

    <!-- @[gesture_intercepting](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkEventGestureIntercept/entry/src/main/cpp/function.h) -->
    
    ``` C
    nodeAPI->registerNodeEvent(row2, NODE_ON_GESTURE_COLLECT_INTERCEPT, 1, &row2);
    nodeAPI->addNodeEventReceiver(row2, [](ArkUI_NodeEvent *event) {
        if (OH_ArkUI_NodeEvent_GetEventType(event) == NODE_ON_GESTURE_COLLECT_INTERCEPT) {
            ArkUI_GestureCollectInterceptInfo *info = nullptr;
            ArkUI_GestureRecognizerHandleArray array;
            ArkUI_TouchRecognizerHandleArray arrayTouch;
            int32_t size;
            info = OH_ArkUI_NodeEvent_GetGestureCollectInterceptInfo(event);
            OH_ArkUI_GestureCollectInterceptInfo_GetTouchRecognizers(info, &arrayTouch, &size);
            OH_ArkUI_GestureCollectInterceptInfo_GetResponseRecognizers(info, &array, &size);
            int32_t uniqueId = 0;
            if (!GestureRecognizerModule(array, uniqueId, size, info)) {
                return;
            }
            TouchRecognizerModule(arrayTouch, size);
            OH_ArkUI_GestureCollectInterceptInfo_SetGestureCollectIntervention(
                info, OH_ArkUI_GestureCollectIntervention::OH_ARKUI_GESTURE_COLLECT_INTERVENTION_CONTINUE);
        } else if (OH_ArkUI_NodeEvent_GetEventType(event) == NODE_TOUCH_EVENT) {
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkEventGestureIntercept]",
                         "NdkEventGestureIntercept_SampleLog, row2 NODE_TOUCH_EVENT NodeEvent");
        }
    });
    ```

2. Create a gesture collection intervention handler. In the handler, you can call the following APIs to intervene the response recognizer and touch recognizer:
   - Use the [OH_ArkUI_GetGestureBindNodeUniqueId](../reference/apis-arkui/capi-native-gesture-h.md#oh_arkui_getgesturebindnodeuniqueid) API to obtain the ID of the bound node.
   - Use the [OH_ArkUI_GestureRecognizer_IsHostBelongsTo](../reference/apis-arkui/capi-native-gesture-h.md#oh_arkui_gesturerecognizer_ishostbelongsto) API to check whether the gesture recognizer is a descendant of the specified node.
   - Use the [OH_ArkUI_TouchRecognizer_IsHostBelongsTo](../reference/apis-arkui/capi-native-gesture-h.md#oh_arkui_touchrecognizer_ishostbelongsto) API to check whether the gesture recognizer is a descendant of the specified node.
   - Use the [OH_ArkUI_GestureCollectInterceptInfo_SetGestureCollectIntervention](../reference/apis-arkui/capi-native-gesture-h.md#oh_arkui_gesturecollectinterceptinfo_setgesturecollectintervention) API to set the collection intervention policy.

    <!-- @[create_interception_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkEventGestureIntercept/entry/src/main/cpp/function.h) -->
    
    ``` C
    // Process the gesture recognizer.
    bool GestureRecognizerModule(ArkUI_GestureRecognizerHandleArray &array, int32_t &uniqueId, int32_t size,
                                 ArkUI_GestureCollectInterceptInfo *info)
    {
        for (auto i = 0; i < size; i++) {
            OH_ArkUI_GetGestureBindNodeUniqueId(array[i], &uniqueId);
            if (OH_ArkUI_GestureRecognizer_IsHostBelongsTo(array[i], uniqueId)) {
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkEventGestureIntercept]",
                             "NdkEventGestureIntercept_SampleLog, gestureRecognizer isHostBelongsTo");
            }
            // Check whether the event is from the button on the right based on uniqueId.
            if (uniqueId == g_buttonId) {
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkEventGestureIntercept]",
                             "NdkEventGestureIntercept_SampleLog, gestureRecognizer is from Button2");
                OH_ArkUI_GestureCollectInterceptInfo_SetGestureCollectIntervention(
                    info, OH_ArkUI_GestureCollectIntervention::OH_ARKUI_GESTURE_COLLECT_INTERVENTION_DISCARD_SELF);
                return false;
            }
        }
        return true;
    }
    // Process the touch recognizer.
    void TouchRecognizerModule(ArkUI_TouchRecognizerHandleArray &arrayTouch, int32_t size)
    {
        for (auto i = 0; i < size; i++) {
            if (OH_ArkUI_TouchRecognizer_IsHostBelongsTo(arrayTouch[i], NODE_ID)) {
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkEventGestureIntercept]",
                             "NdkEventGestureIntercept_SampleLog, touchRecognizer isHostBelongsTo");
            } else {
                OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkEventGestureIntercept]",
                             "NdkEventGestureIntercept_SampleLog, touchRecognizer not isHostBelongsTo");
            }
        }
    }
    ```

**Samples**

For details about the complete example, see <!--RP4-->[Sample Project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NdkEventGestureIntercept)<!--RP4End-->.
