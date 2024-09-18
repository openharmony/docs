# native_gesture.h


## 概述

提供NativeGesture接口的类型定义。

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md) | 手势模块接口集合。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef uint32_t [ArkUI_GestureEventActionTypeMask](_ark_u_i___native_module.md#arkui_gestureeventactiontypemask) | 定义手势事件类型集合  | 
| typedef uint32_t [ArkUI_GestureDirectionMask](_ark_u_i___native_module.md#arkui_gesturedirectionmask) | 定义滑动手势方向集合。  | 
| typedef ArkUI_GestureRecognizer \* [ArkUI_GestureRecognizerHandle](_ark_u_i___native_module.md#arkui_gesturerecognizerhandle) | 提供手势识别器句柄类型对象定义。  | 
| typedef [ArkUI_GestureRecognizerHandle](_ark_u_i___native_module.md#arkui_gesturerecognizerhandle) \* [ArkUI_GestureRecognizerHandleArray](_ark_u_i___native_module.md#arkui_gesturerecognizerhandlearray) | 提供手势识别器句柄类型数组对象定义。  | 
| typedef struct [ArkUI_GestureEventTargetInfo](_ark_u_i___native_module.md#arkui_gestureeventtargetinfo) [ArkUI_GestureEventTargetInfo](_ark_u_i___native_module.md#arkui_gestureeventtargetinfo) | 提供手势事件目标信息类型对象定义。  | 
| typedef struct [ArkUI_ParallelInnerGestureEvent](_ark_u_i___native_module.md#arkui_parallelinnergestureevent) [ArkUI_ParallelInnerGestureEvent](_ark_u_i___native_module.md#arkui_parallelinnergestureevent) | 提供并行内部手势事件类型对象定义。  | 
| typedef void(\* [ArkUI_GestureRecognizerDestructNotifyCallback](_ark_u_i___native_module.md#arkui_gesturerecognizerdestructnotifycallback)) (ArkUI_GestureRecognizer \*recognizer, void \*userData) | 定义手势识别器析构通知事件的回调函数类型。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_GestureEventActionType](_ark_u_i___native_module.md#arkui_gestureeventactiontype) { [GESTURE_EVENT_ACTION_ACCEPT](_ark_u_i___native_module.md) = 0x01, [GESTURE_EVENT_ACTION_UPDATE](_ark_u_i___native_module.md) = 0x02, [GESTURE_EVENT_ACTION_END](_ark_u_i___native_module.md) = 0x04, [GESTURE_EVENT_ACTION_CANCEL](_ark_u_i___native_module.md) = 0x08 } | 定义手势事件类型。  | 
| [ArkUI_GesturePriority](_ark_u_i___native_module.md#arkui_gesturepriority) { [NORMAL](_ark_u_i___native_module.md) = 0, [PRIORITY](_ark_u_i___native_module.md) = 1, [PARALLEL](_ark_u_i___native_module.md) = 2 } | 定义手势事件模式  | 
| [ArkUI_GroupGestureMode](_ark_u_i___native_module.md#arkui_groupgesturemode) { [SEQUENTIAL_GROUP](_ark_u_i___native_module.md) = 0, [PARALLEL_GROUP](_ark_u_i___native_module.md) = 1, [EXCLUSIVE_GROUP](_ark_u_i___native_module.md) = 2 } | 定义手势组事件模式。  | 
| [ArkUI_GestureDirection](_ark_u_i___native_module.md#arkui_gesturedirection) {<br/>[GESTURE_DIRECTION_ALL](_ark_u_i___native_module.md) = 0b1111, [GESTURE_DIRECTION_HORIZONTAL](_ark_u_i___native_module.md) = 0b0011, [GESTURE_DIRECTION_VERTICAL](_ark_u_i___native_module.md) = 0b1100, [GESTURE_DIRECTION_LEFT](_ark_u_i___native_module.md) = 0b0001,<br/>[GESTURE_DIRECTION_RIGHT](_ark_u_i___native_module.md) = 0b0010, [GESTURE_DIRECTION_UP](_ark_u_i___native_module.md) = 0b0100, [GESTURE_DIRECTION_DOWN](_ark_u_i___native_module.md) = 0b1000, [GESTURE_DIRECTION_NONE](_ark_u_i___native_module.md) = 0<br/>} | 定义滑动手势方向。  | 
| [ArkUI_GestureMask](_ark_u_i___native_module.md#arkui_gesturemask) { [NORMAL_GESTURE_MASK](_ark_u_i___native_module.md) = 0, [IGNORE_INTERNAL_GESTURE_MASK](_ark_u_i___native_module.md) } | 定义手势屏蔽模式  | 
| [ArkUI_GestureRecognizerType](_ark_u_i___native_module.md#arkui_gesturerecognizertype) {<br/>[TAP_GESTURE](_ark_u_i___native_module.md) = 0, [LONG_PRESS_GESTURE](_ark_u_i___native_module.md), [PAN_GESTURE](_ark_u_i___native_module.md), [PINCH_GESTURE](_ark_u_i___native_module.md),<br/>[ROTATION_GESTURE](_ark_u_i___native_module.md), [SWIPE_GESTURE](_ark_u_i___native_module.md), [GROUP_GESTURE](_ark_u_i___native_module.md)<br/>} | 定义手势类型  | 
| [ArkUI_GestureInterruptResult](_ark_u_i___native_module.md#arkui_gestureinterruptresult) { [GESTURE_INTERRUPT_RESULT_CONTINUE](_ark_u_i___native_module.md) = 0, [GESTURE_INTERRUPT_RESULT_REJECT](_ark_u_i___native_module.md) } | 定义手势打断结果。  | 
| [ArkUI_GestureRecognizerState](_ark_u_i___native_module.md#arkui_gesturerecognizerstate) {<br/>[ARKUI_GESTURE_RECOGNIZER_STATE_REDAY](_ark_u_i___native_module.md) = 0, [ARKUI_GESTURE_RECOGNIZER_STATE_DETECTING](_ark_u_i___native_module.md) = 1, [ARKUI_GESTURE_RECOGNIZER_STATE_PENDING](_ark_u_i___native_module.md) = 2, [ARKUI_GESTURE_RECOGNIZER_STATE_BLOCKED](_ark_u_i___native_module.md) = 3,<br/>[ARKUI_GESTURE_RECOGNIZER_STATE_SUCCESSFUL](_ark_u_i___native_module.md) = 4, [ARKUI_GESTURE_RECOGNIZER_STATE_FAILED](_ark_u_i___native_module.md) = 5<br/>} | 定义手势识别器状态。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| bool [OH_ArkUI_GestureInterruptInfo_GetSystemFlag](_ark_u_i___native_module.md#oh_arkui_gestureinterruptinfo_getsystemflag) (const ArkUI_GestureInterruptInfo \*event) | 判断是否组件内置手势。  | 
| ArkUI_GestureRecognizer \* [OH_ArkUI_GestureInterruptInfo_GetRecognizer](_ark_u_i___native_module.md#oh_arkui_gestureinterruptinfo_getrecognizer) (const ArkUI_GestureInterruptInfo \*event) | 返回被打断的手势指针。  | 
| ArkUI_GestureEvent \* [OH_ArkUI_GestureInterruptInfo_GetGestureEvent](_ark_u_i___native_module.md#oh_arkui_gestureinterruptinfo_getgestureevent) (const ArkUI_GestureInterruptInfo \*event) | 返回打断的手势事件数据。  | 
| int32_t [OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType](_ark_u_i___native_module.md#oh_arkui_gestureinterruptinfo_getsystemrecognizertype) (const ArkUI_GestureInterruptInfo \*event) | 当要触发的是系统内部手势时，使用该方法可返回该系统内部手势的类型。  | 
| [ArkUI_GestureEventActionType](_ark_u_i___native_module.md#arkui_gestureeventactiontype) [OH_ArkUI_GestureEvent_GetActionType](_ark_u_i___native_module.md#oh_arkui_gestureevent_getactiontype) (const ArkUI_GestureEvent \*event) | 返回手势事件类型。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) [OH_ArkUI_GestureEvent_GetResponseNode](_ark_u_i___native_module.md#oh_arkui_gestureevent_getresponsenode) (ArkUI_GestureEvent \*event) | 返回响应手势的节点。  | 
| const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \* [OH_ArkUI_GestureEvent_GetRawInputEvent](_ark_u_i___native_module.md#oh_arkui_gestureevent_getrawinputevent) (const ArkUI_GestureEvent \*event) | 返回手势输入。  | 
| int32_t [OH_ArkUI_LongPress_GetRepeatCount](_ark_u_i___native_module.md#oh_arkui_longpress_getrepeatcount) (const ArkUI_GestureEvent \*event) | 返回长按手势定时触发次数。  | 
| float [OH_ArkUI_PanGesture_GetVelocity](_ark_u_i___native_module.md#oh_arkui_pangesture_getvelocity) (const ArkUI_GestureEvent \*event) | 滑动手势返回手势主方向速度。  | 
| float [OH_ArkUI_PanGesture_GetVelocityX](_ark_u_i___native_module.md#oh_arkui_pangesture_getvelocityx) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势的x轴方向速度。  | 
| float [OH_ArkUI_PanGesture_GetVelocityY](_ark_u_i___native_module.md#oh_arkui_pangesture_getvelocityy) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势的y轴方向速度。  | 
| float [OH_ArkUI_PanGesture_GetOffsetX](_ark_u_i___native_module.md#oh_arkui_pangesture_getoffsetx) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势事件x轴相对偏移量。  | 
| float [OH_ArkUI_PanGesture_GetOffsetY](_ark_u_i___native_module.md#oh_arkui_pangesture_getoffsety) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势事件y轴相对偏移量。  | 
| float [OH_ArkUI_SwipeGesture_GetAngle](_ark_u_i___native_module.md#oh_arkui_swipegesture_getangle) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势事件角度信息。  | 
| float [OH_ArkUI_SwipeGesture_GetVelocity](_ark_u_i___native_module.md#oh_arkui_swipegesture_getvelocity) (const ArkUI_GestureEvent \*event) | 滑动手势场景中所有手指滑动平均速度。  | 
| float [OH_ArkUI_RotationGesture_GetAngle](_ark_u_i___native_module.md#oh_arkui_rotationgesture_getangle) (const ArkUI_GestureEvent \*event) | 旋转手势返回当前手势事件角度信息。  | 
| float [OH_ArkUI_PinchGesture_GetScale](_ark_u_i___native_module.md#oh_arkui_pinchgesture_getscale) (const ArkUI_GestureEvent \*event) | 捏合手势返回当前手势事件缩放信息。  | 
| float [OH_ArkUI_PinchGesture_GetCenterX](_ark_u_i___native_module.md#oh_arkui_pinchgesture_getcenterx) (const ArkUI_GestureEvent \*event) | 捏合手势中心点相对于当前组件元素左上角x轴坐标。  | 
| float [OH_ArkUI_PinchGesture_GetCenterY](_ark_u_i___native_module.md#oh_arkui_pinchgesture_getcentery) (const ArkUI_GestureEvent \*event) | 捏合手势中心点相对于当前组件元素左上角y轴坐标。  | 
| [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) [OH_ArkUI_GestureEvent_GetNode](_ark_u_i___native_module.md#oh_arkui_gestureevent_getnode) (const ArkUI_GestureEvent \*event) | 获取被绑定手势的ARKUI组件。  | 
| int32_t [OH_ArkUI_GetResponseRecognizersFromInterruptInfo](_ark_u_i___native_module.md#oh_arkui_getresponserecognizersfrominterruptinfo) (const ArkUI_GestureInterruptInfo \*event, [ArkUI_GestureRecognizerHandleArray](_ark_u_i___native_module.md#arkui_gesturerecognizerhandlearray) \*responseChain, int32_t \*count) | 获取手势响应链的信息。  | 
| int32_t [OH_ArkUI_SetGestureRecognizerEnabled](_ark_u_i___native_module.md#oh_arkui_setgesturerecognizerenabled) (ArkUI_GestureRecognizer \*recognizer, bool enabled) | 设置手势识别器的使能状态。  | 
| bool [OH_ArkUI_GetGestureRecognizerEnabled](_ark_u_i___native_module.md#oh_arkui_getgesturerecognizerenabled) (ArkUI_GestureRecognizer \*recognizer) | 获取手势识别器的使能状态。  | 
| int32_t [OH_ArkUI_GetGestureRecognizerState](_ark_u_i___native_module.md#oh_arkui_getgesturerecognizerstate) (ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureRecognizerState](_ark_u_i___native_module.md#arkui_gesturerecognizerstate) \*state) | 获取手势识别器的状态。  | 
| int32_t [OH_ArkUI_GetGestureEventTargetInfo](_ark_u_i___native_module.md#oh_arkui_getgestureeventtargetinfo) (ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureEventTargetInfo](_ark_u_i___native_module.md#arkui_gestureeventtargetinfo) \*\*info) | 获取手势事件目标信息。  | 
| int32_t [OH_ArkUI_GestureEventTargetInfo_IsScrollBegin](_ark_u_i___native_module.md#oh_arkui_gestureeventtargetinfo_isscrollbegin) ([ArkUI_GestureEventTargetInfo](_ark_u_i___native_module.md#arkui_gestureeventtargetinfo) \*info, bool \*ret) | 当前滚动类容器组件是否在顶部。  | 
| int32_t [OH_ArkUI_GestureEventTargetInfo_IsScrollEnd](_ark_u_i___native_module.md#oh_arkui_gestureeventtargetinfo_isscrollend) ([ArkUI_GestureEventTargetInfo](_ark_u_i___native_module.md#arkui_gestureeventtargetinfo) \*info, bool \*ret) | 当前滚动类容器组件是否在底部。  | 
| int32_t [OH_ArkUI_GetPanGestureDirectionMask](_ark_u_i___native_module.md#oh_arkui_getpangesturedirectionmask) (ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureDirectionMask](_ark_u_i___native_module.md#arkui_gesturedirectionmask) \*directionMask) | 获取滑动手势的滑动方向。  | 
| bool [OH_ArkUI_IsBuiltInGesture](_ark_u_i___native_module.md#oh_arkui_isbuiltingesture) (ArkUI_GestureRecognizer \*recognizer) | 当前手势是否为系统内置手势。  | 
| int32_t [OH_ArkUI_GetGestureTag](_ark_u_i___native_module.md#oh_arkui_getgesturetag) (ArkUI_GestureRecognizer \*recognizer, char \*buffer, int32_t bufferSize, int32_t \*result) | 获取手势识别器的标记。  | 
| int32_t [OH_ArkUI_GetGestureBindNodeId](_ark_u_i___native_module.md#oh_arkui_getgesturebindnodeid) (ArkUI_GestureRecognizer \*recognizer, char \*nodeId, int32_t size, int32_t \*result) | 获取手势识别器绑定的组件的ID。  | 
| bool [OH_ArkUI_IsGestureRecognizerValid](_ark_u_i___native_module.md#oh_arkui_isgesturerecognizervalid) (ArkUI_GestureRecognizer \*recognizer) | 当前手势识别器是否有效。  | 
| void \* [OH_ArkUI_ParallelInnerGestureEvent_GetUserData](_ark_u_i___native_module.md#oh_arkui_parallelinnergestureevent_getuserdata) ([ArkUI_ParallelInnerGestureEvent](_ark_u_i___native_module.md#arkui_parallelinnergestureevent) \*event) | 获取并行内部手势事件中的用户自定义数据。  | 
| ArkUI_GestureRecognizer \* [OH_ArkUI_ParallelInnerGestureEvent_GetCurrentRecognizer](_ark_u_i___native_module.md#oh_arkui_parallelinnergestureevent_getcurrentrecognizer) ([ArkUI_ParallelInnerGestureEvent](_ark_u_i___native_module.md#arkui_parallelinnergestureevent) \*event) | 获取并行内部手势事件中的当前手势识别器。  | 
| int32_t [OH_ArkUI_ParallelInnerGestureEvent_GetConflictRecognizers](_ark_u_i___native_module.md#oh_arkui_parallelinnergestureevent_getconflictrecognizers) ([ArkUI_ParallelInnerGestureEvent](_ark_u_i___native_module.md#arkui_parallelinnergestureevent) \*event, [ArkUI_GestureRecognizerHandleArray](_ark_u_i___native_module.md#arkui_gesturerecognizerhandlearray) \*array, int32_t \*size) | 获取并行内部手势事件中的冲突的手势识别器。  | 
| int32_t [OH_ArkUI_SetArkUIGestureRecognizerDisposeNotify](_ark_u_i___native_module.md#oh_arkui_setarkuigesturerecognizerdisposenotify) (ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureRecognizerDestructNotifyCallback](_ark_u_i___native_module.md#arkui_gesturerecognizerdestructnotifycallback) callback, void \*userData) | 设置手势识别器对象析构通知回调函数.  | 
