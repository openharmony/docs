# native_gesture.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## 概述

提供NativeGesture接口的类型定义。

**引用文件：** <arkui/native_gesture.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## 汇总

### 结构体

| 名称                                                                                            | typedef关键字                       | 描述                |
|-----------------------------------------------------------------------------------------------|----------------------------------|-------------------|
| [ArkUI_NativeGestureAPI_1](capi-arkui-nativemodule-arkui-nativegestureapi-1.md)               | ArkUI_NativeGestureAPI_1         | 手势模块接口集合。         |
| [ArkUI_NativeGestureAPI_2](capi-arkui-nativemodule-arkui-nativegestureapi-2.md)               | -                                | 定义手势模块接口集合。       |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)                 | ArkUI_GestureRecognizer          | 提供手势组件实例对象定义。     |
| [ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)           | ArkUI_GestureInterruptInfo       | 提供手势打断数据类型对象定义。   |
| [ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)                           | ArkUI_GestureEvent               | 提供手势事件数据类型对象定义。   |
| [ArkUI_GestureEventTargetInfo](capi-arkui-nativemodule-arkui-gestureeventtargetinfo.md)       | ArkUI_GestureEventTargetInfo     | 提供手势事件目标信息类型对象定义。 |
| [ArkUI_ParallelInnerGestureEvent](capi-arkui-nativemodule-arkui-parallelinnergestureevent.md) | ArkUI_ParallelInnerGestureEvent  | 提供并行内部手势事件类型对象定义。 |
| [ArkUI_TouchRecognizer](capi-arkui-nativemodule-arkui-touchrecognizer.md)                     | ArkUI_TouchRecognizer            | 定义触摸识别器。          |
| [ArkUI_TouchRecognizerHandle*](capi-arkui-nativemodule-arkui-touchrecognizerhandlearray.md)   | ArkUI_TouchRecognizerHandleArray | 定义触摸识别器句柄数组。      |
| [ArkUI_GestureRecognizerHandle*](capi-arkui-nativemodule-arkui-gesturerecognizerhandle.md)    | ArkUI_GestureRecognizerHandleArray  | 提供手势识别器句柄类型数组对象定义。   | 

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_GestureEventActionType](#arkui_gestureeventactiontype) | ArkUI_GestureEventActionType | 定义手势事件类型。 |
| [ArkUI_GesturePriority](#arkui_gesturepriority) | ArkUI_GesturePriority | 定义手势事件模式。 |
| [ArkUI_GroupGestureMode](#arkui_groupgesturemode) | ArkUI_GroupGestureMode | 定义手势组事件模式。 |
| [ArkUI_GestureDirection](#arkui_gesturedirection) | ArkUI_GestureDirection | 定义滑动手势方向。 |
| [ArkUI_GestureMask](#arkui_gesturemask) | ArkUI_GestureMask | 定义手势屏蔽模式。 |
| [ArkUI_GestureRecognizerType](#arkui_gesturerecognizertype) | ArkUI_GestureRecognizerType | 定义手势类型。 |
| [ArkUI_GestureInterruptResult](#arkui_gestureinterruptresult) | ArkUI_GestureInterruptResult | 定义手势打断结果。 |
| [ArkUI_GestureRecognizerState](#arkui_gesturerecognizerstate) | ArkUI_GestureRecognizerState | 定义手势识别器状态。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*ArkUI_GestureRecognizerDisposeNotifyCallback)(ArkUI_GestureRecognizer* recognizer, void* userData)](#arkui_gesturerecognizerdisposenotifycallback) | ArkUI_GestureRecognizerDisposeNotifyCallback | 定义手势识别器析构通知事件的回调函数类型。 |
| [bool OH_ArkUI_GestureInterruptInfo_GetSystemFlag(const ArkUI_GestureInterruptInfo* event)](#oh_arkui_gestureinterruptinfo_getsystemflag) | - | 判断是否组件内置手势。 |
| [ArkUI_GestureRecognizer* OH_ArkUI_GestureInterruptInfo_GetRecognizer(const ArkUI_GestureInterruptInfo* event)](#oh_arkui_gestureinterruptinfo_getrecognizer) | - | 返回被打断的手势指针。 |
| [ArkUI_GestureEvent* OH_ArkUI_GestureInterruptInfo_GetGestureEvent(const ArkUI_GestureInterruptInfo* event)](#oh_arkui_gestureinterruptinfo_getgestureevent) | - | 返回打断的手势事件数据。 |
| [int32_t OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType(const ArkUI_GestureInterruptInfo* event)](#oh_arkui_gestureinterruptinfo_getsystemrecognizertype) | - | 当要触发的是系统内部手势时，使用该方法可返回该系统内部手势的类型。 |
| [int32_t OH_ArkUI_GestureInterruptInfo_GetTouchRecognizers(const ArkUI_GestureInterruptInfo* info,ArkUI_TouchRecognizerHandleArray* recognizers, int32_t* size)](#oh_arkui_gestureinterruptinfo_gettouchrecognizers) | - | 从手势打断信息中获取触摸识别器。 |
| [ArkUI_NodeHandle OH_ArkUI_TouchRecognizer_GetNodeHandle(const ArkUI_TouchRecognizerHandle recognizer)](#oh_arkui_touchrecognizer_getnodehandle) | - | 获取触摸识别器对应的组件句柄。 |
| [int32_t OH_ArkUI_TouchRecognizer_CancelTouch(ArkUI_TouchRecognizerHandle recognizer, ArkUI_GestureInterruptInfo* info)](#oh_arkui_touchrecognizer_canceltouch) | - | 在手势打断回调中向指定的触摸识别器发送取消触摸的事件 |
| [ArkUI_GestureEventActionType OH_ArkUI_GestureEvent_GetActionType(const ArkUI_GestureEvent* event)](#oh_arkui_gestureevent_getactiontype) | - | 返回手势事件类型。 |
| [const ArkUI_UIInputEvent* OH_ArkUI_GestureEvent_GetRawInputEvent(const ArkUI_GestureEvent* event)](#oh_arkui_gestureevent_getrawinputevent) | - | 返回手势输入。 |
| [int32_t OH_ArkUI_LongPress_GetRepeatCount(const ArkUI_GestureEvent* event)](#oh_arkui_longpress_getrepeatcount) | - | 返回长按手势定时触发次数。 |
| [float OH_ArkUI_PanGesture_GetVelocity(const ArkUI_GestureEvent* event)](#oh_arkui_pangesture_getvelocity) | - | 滑动手势返回手势主方向速度。 |
| [float OH_ArkUI_PanGesture_GetVelocityX(const ArkUI_GestureEvent* event)](#oh_arkui_pangesture_getvelocityx) | - | 滑动手势返回当前手势的x轴方向速度。 |
| [float OH_ArkUI_PanGesture_GetVelocityY(const ArkUI_GestureEvent* event)](#oh_arkui_pangesture_getvelocityy) | - | 滑动手势返回当前手势的y轴方向速度。 |
| [float OH_ArkUI_PanGesture_GetOffsetX(const ArkUI_GestureEvent* event)](#oh_arkui_pangesture_getoffsetx) | - | 滑动手势返回当前手势事件x轴相对偏移量。 |
| [float OH_ArkUI_PanGesture_GetOffsetY(const ArkUI_GestureEvent* event)](#oh_arkui_pangesture_getoffsety) | - | 滑动手势返回当前手势事件y轴相对偏移量。 |
| [float OH_ArkUI_SwipeGesture_GetAngle(const ArkUI_GestureEvent* event)](#oh_arkui_swipegesture_getangle) | - | 滑动手势返回当前手势事件角度信息。角度计算方式：滑动手势被识别到后，连接两根手指之间的线被识别为起始线条，随着手指的滑动，手指之间的线条会发生旋转，<br>        根据起始线条两端点和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角，<br>        最后arctan2(cy2-cy1,cx2-cx1)-arctan2(y2-y1,x2-x1)为旋转的角度。<br>        以起始线条为坐标系，顺时针旋转为0到180度，逆时针旋转为-180到0度。<br> |
| [float OH_ArkUI_SwipeGesture_GetVelocity(const ArkUI_GestureEvent* event)](#oh_arkui_swipegesture_getvelocity) | - | 滑动手势场景中所有手指滑动平均速度。 |
| [float OH_ArkUI_RotationGesture_GetAngle(const ArkUI_GestureEvent* event)](#oh_arkui_rotationgesture_getangle) | - | 旋转手势返回当前手势事件角度信息。 |
| [float OH_ArkUI_PinchGesture_GetScale(const ArkUI_GestureEvent* event)](#oh_arkui_pinchgesture_getscale) | - | 捏合手势返回当前手势事件缩放信息。 |
| [float OH_ArkUI_PinchGesture_GetCenterX(const ArkUI_GestureEvent* event)](#oh_arkui_pinchgesture_getcenterx) | - | 捏合手势中心点相对于当前组件元素左上角x轴坐标。 |
| [float OH_ArkUI_PinchGesture_GetCenterY(const ArkUI_GestureEvent* event)](#oh_arkui_pinchgesture_getcentery) | - | 捏合手势中心点相对于当前组件元素左上角y轴坐标。 |
| [ArkUI_NodeHandle OH_ArkUI_GestureEvent_GetNode(const ArkUI_GestureEvent* event)](#oh_arkui_gestureevent_getnode) | - | 获取绑定该手势的ARKUI组件 |
| [int32_t OH_ArkUI_GetResponseRecognizersFromInterruptInfo(const ArkUI_GestureInterruptInfo* event,ArkUI_GestureRecognizerHandleArray* responseChain, int32_t* count)](#oh_arkui_getresponserecognizersfrominterruptinfo) | - | 获取手势响应链的信息。 |
| [int32_t OH_ArkUI_SetGestureRecognizerEnabled(ArkUI_GestureRecognizer* recognizer, bool enabled)](#oh_arkui_setgesturerecognizerenabled) | - | 设置手势识别器的使能状态。 |
| [int32_t OH_ArkUI_SetGestureRecognizerLimitFingerCount(ArkUI_GestureRecognizer* recognizer, bool limitFingerCount)](#oh_arkui_setgesturerecognizerlimitfingercount) | - | 设置是否严格检查触摸手指数量的标志。实际触摸手指数量不等于设置的手指数量的时候，该手势识别不成功。 |
| [bool OH_ArkUI_GetGestureRecognizerEnabled(ArkUI_GestureRecognizer* recognizer)](#oh_arkui_getgesturerecognizerenabled) | - | 获取手势识别器的使能状态。 |
| [int32_t OH_ArkUI_GetGestureRecognizerState(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureRecognizerState* state)](#oh_arkui_getgesturerecognizerstate) | - | 获取手势识别器的状态。 |
| [int32_t OH_ArkUI_GetGestureEventTargetInfo(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureEventTargetInfo** info)](#oh_arkui_getgestureeventtargetinfo) | - | 获取手势事件目标信息。 |
| [int32_t OH_ArkUI_GestureEventTargetInfo_IsScrollBegin(ArkUI_GestureEventTargetInfo* info, bool* ret)](#oh_arkui_gestureeventtargetinfo_isscrollbegin) | - | 当前滚动类容器组件是否在顶部。 |
| [int32_t OH_ArkUI_GestureEventTargetInfo_IsScrollEnd(ArkUI_GestureEventTargetInfo* info, bool* ret)](#oh_arkui_gestureeventtargetinfo_isscrollend) | - | 当前滚动类容器组件是否在底部。 |
| [int32_t OH_ArkUI_GetPanGestureDirectionMask(ArkUI_GestureRecognizer* recognizer,ArkUI_GestureDirectionMask* directionMask)](#oh_arkui_getpangesturedirectionmask) | - | 获取滑动手势的滑动方向。 |
| [bool OH_ArkUI_IsBuiltInGesture(ArkUI_GestureRecognizer* recognizer)](#oh_arkui_isbuiltingesture) | - | 当前手势是否为系统内置手势。 |
| [int32_t OH_ArkUI_GetGestureTag(ArkUI_GestureRecognizer* recognizer, char* buffer, int32_t bufferSize, int32_t* result)](#oh_arkui_getgesturetag) | - | 获取手势识别器的标记。 |
| [int32_t OH_ArkUI_GetGestureBindNodeId(ArkUI_GestureRecognizer* recognizer, char* nodeId, int32_t size,int32_t* result)](#oh_arkui_getgesturebindnodeid) | - | 获取手势识别器绑定的组件的ID。 |
| [bool OH_ArkUI_IsGestureRecognizerValid(ArkUI_GestureRecognizer* recognizer)](#oh_arkui_isgesturerecognizervalid) | - | 当前手势识别器是否有效。 |
| [void* OH_ArkUI_ParallelInnerGestureEvent_GetUserData(ArkUI_ParallelInnerGestureEvent* event)](#oh_arkui_parallelinnergestureevent_getuserdata) | - | 获取并行内部手势事件中的用户自定义数据。 |
| [ArkUI_GestureRecognizer* OH_ArkUI_ParallelInnerGestureEvent_GetCurrentRecognizer(ArkUI_ParallelInnerGestureEvent* event)](#oh_arkui_parallelinnergestureevent_getcurrentrecognizer) | - | 获取并行内部手势事件中的当前手势识别器。 |
| [int32_t OH_ArkUI_ParallelInnerGestureEvent_GetConflictRecognizers(ArkUI_ParallelInnerGestureEvent* event,ArkUI_GestureRecognizerHandleArray* array, int32_t* size)](#oh_arkui_parallelinnergestureevent_getconflictrecognizers) | - | 获取并行内部手势事件中的冲突的手势识别器。 |
| [int32_t OH_ArkUI_SetArkUIGestureRecognizerDisposeNotify(ArkUI_GestureRecognizer* recognizer,ArkUI_GestureRecognizerDisposeNotifyCallback callback, void* userData)](#oh_arkui_setarkuigesturerecognizerdisposenotify) | - | 设置手势识别器对象析构通知回调函数。 |
| [int32_t OH_ArkUI_GetGestureParam_DirectMask(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureDirectionMask* directMask)](#oh_arkui_getgestureparam_directmask) | - | 获取手势识别器的滑动方向。 |
| [int32_t OH_ArkUI_GetGestureParam_FingerCount(ArkUI_GestureRecognizer* recognizer, int* finger)](#oh_arkui_getgestureparam_fingercount) | - | 获取手势识别器的手指数。 |
| [int32_t OH_ArkUI_GetGestureParam_limitFingerCount(ArkUI_GestureRecognizer* recognizer, bool* isLimited)](#oh_arkui_getgestureparam_limitfingercount) | - | 获取手势识别器是否有手指数限制。 |
| [int32_t OH_ArkUI_GetGestureParam_repeat(ArkUI_GestureRecognizer* recognizer, bool* isRepeat)](#oh_arkui_getgestureparam_repeat) | - | 获取手势识别器是否连续触发事件回调。 |
| [int32_t OH_ArkUI_GetGestureParam_distance(ArkUI_GestureRecognizer* recognizer, double* distance)](#oh_arkui_getgestureparam_distance) | - | 获取手势识别器的手指允许的移动距离范围。 |
| [int32_t OH_ArkUI_GetGestureParam_speed(ArkUI_GestureRecognizer* recognizer, double* speed)](#oh_arkui_getgestureparam_speed) | - | 获取手势识别器的识别滑动的最小速度。 |
| [int32_t OH_ArkUI_GetGestureParam_duration(ArkUI_GestureRecognizer* recognizer, int* duration)](#oh_arkui_getgestureparam_duration) | - | 获取手势识别器的触发长按的最短时间。 |
| [int32_t OH_ArkUI_GetGestureParam_angle(ArkUI_GestureRecognizer* recognizer, double* angle)](#oh_arkui_getgestureparam_angle) | - | 获取手势识别器的旋转手势的最小改变度数。 |
| [int32_t OH_ArkUI_GetGestureParam_distanceThreshold(ArkUI_GestureRecognizer* recognizer, double* distanceThreshold)](#oh_arkui_getgestureparam_distancethreshold) | - | 获取手势识别器的手势移动阈值。 |
| [ArkUI_ErrorCode OH_ArkUI_PanGesture_SetDistanceMap(ArkUI_GestureRecognizer* recognizer, int size, int* toolTypeArray, double* distanceArray)](#oh_arkui_pangesture_setdistancemap) | - | 设置手势最小滑动阈值表。当设备类型为非法值时，设置不生效。 |
| [ArkUI_ErrorCode OH_ArkUI_PanGesture_GetDistanceByToolType(ArkUI_GestureRecognizer* recognizer, int toolType, double* distance)](#oh_arkui_pangesture_getdistancebytooltype) | - | 获取手势识别器的手势移动阈值表。仅支持对通过OH_ArkUI_PanGesture_SetDistanceMap修改过的设备类型的阈值查询。默认滑动阈值可通过查询UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN类型获得，其他未设置过的类型不会返回。 |
| [ArkUI_ErrorCode OH_ArkUI_SetTouchTestDoneCallback(ArkUI_NodeHandle node,void* userData,void (\*touchTestDone)(ArkUI_GestureEvent* event,ArkUI_GestureRecognizerHandleArray recognizers,int32_t count,void* userData))](#oh_arkui_settouchtestdonecallback) | - | 注册一个在所有手势识别器收集完成后执行的回调函数。当用户开始触摸屏幕时，系统会进行命中测试并根据触摸位置收集手势识别器。随后，在处理任何移动事件之前，组件可以使用此接口确定将参与识别并相互竞争的手势识别器。 |
| [void* OH_ArkUI_GestureInterrupter_GetUserData(ArkUI_GestureInterruptInfo* event)](#oh_arkui_gestureinterrupter_getuserdata) | - | 获取手势中断事件中的用户自定义数据。 |
| [ArkUI_ErrorCode OH_ArkUI_PreventGestureRecognizerBegin(ArkUI_GestureRecognizer* recognizer)](#oh_arkui_preventgesturerecognizerbegin) | - | 在手指全部抬起前阻止手势识别器参与当前手势识别。如果系统已确定该手势识别器的结果（无论成功与否），调用此接口将无效。 |

### 变量

| 名称       | typedef关键字                 | 描述                                                                                                                                    |
|----------|----------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| uint32_t | ArkUI_GestureDirectionMask | 定义滑动手势方向集合。<br>例：ArkUI_GestureDirectionMask directions = GESTURE_DIRECTION_LEFT \| GESTURE_DIRECTION_RIGHT。<br>directions 表明支持左右水平方向。 |
| uint32_t | ArkUI_GestureEventActionTypeMask   | 定义手势事件类型集合。例：ArkUI_GestureEventActionTypeMask actions = GESTURE_EVENT_ACTION_ACCEPT \| GESTURE_EVENT_ACTION_UPDATE;                   |

## 枚举类型说明

### ArkUI_GestureEventActionType

```
enum ArkUI_GestureEventActionType
```

**描述：**


定义手势事件类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| GESTURE_EVENT_ACTION_ACCEPT = 0x01 | 手势事件触发。 |
| GESTURE_EVENT_ACTION_UPDATE = 0x02 | 手势事件更新。 |
| GESTURE_EVENT_ACTION_END = 0x04 | 手势事件结束。 |
| GESTURE_EVENT_ACTION_CANCEL = 0x08 | 手势事件取消。 |

### ArkUI_GesturePriority

```
enum ArkUI_GesturePriority
```

**描述：**


定义手势事件模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| NORMAL = 0 | 正常手势。 |
| PRIORITY = 1 | 高优先级手势。 |
| PARALLEL = 2 | 并发手势。 |

### ArkUI_GroupGestureMode

```
enum ArkUI_GroupGestureMode
```

**描述：**


定义手势组事件模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| SEQUENTIAL_GROUP = 0 | 顺序手势模式，按照注册顺序识别手势，直到所有手势识别成功。若有识别失败，后续识别均失败。仅有最后一个手势响应结束事件。 |
| PARALLEL_GROUP = 1 | 并发手势模式，注册的手势同时识别，直到所有手势识别结束，手势识别互相不影响。 |
| EXCLUSIVE_GROUP = 2 | 互斥手势模式，注册的手势同时识别，若有一个手势识别成功，则结束手势识别。 |

### ArkUI_GestureDirection

```
enum ArkUI_GestureDirection
```

**描述：**


定义滑动手势方向。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| GESTURE_DIRECTION_ALL = 0b1111 | 所有方向。 |
| GESTURE_DIRECTION_HORIZONTAL = 0b0011 | 水平方向。 |
| GESTURE_DIRECTION_VERTICAL = 0b1100 | 竖直方向。 |
| GESTURE_DIRECTION_LEFT = 0b0001 | 向左方向。 |
| GESTURE_DIRECTION_RIGHT = 0b0010 | 向右方向。 |
| GESTURE_DIRECTION_UP = 0b0100 | 向上方向。 |
| GESTURE_DIRECTION_DOWN = 0b1000 | 向下方向。 |
| GESTURE_DIRECTION_NONE = 0 | 任何方向都不触发手势事件。 |

### ArkUI_GestureMask

```
enum ArkUI_GestureMask
```

**描述：**


定义手势屏蔽模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| NORMAL_GESTURE_MASK = 0 | 不屏蔽子组件的手势，按照默认手势识别顺序进行识别。 |
| IGNORE_INTERNAL_GESTURE_MASK | 屏蔽子组件的手势，包括子组件上系统内置的手势。 |

### ArkUI_GestureRecognizerType

```
enum ArkUI_GestureRecognizerType
```

**描述：**


定义手势类型。

**起始版本：** 12

| 枚举项 | 描述                                |
| -- |-----------------------------------|
| TAP_GESTURE = 0 | 敲击手势。                             |
| LONG_PRESS_GESTURE | 长按手势。                             |
| PAN_GESTURE | 拖动手势。                             |
| PINCH_GESTURE | 捏合手势。                             |
| ROTATION_GESTURE | 旋转手势。                             |
| SWIPE_GESTURE | 滑动手势。                             |
| GROUP_GESTURE | 手势组合。                             |
| CLICK_GESTURE | 通过onClick注册的点击手势。<br>**起始版本：** 20 |
| DRAG_DROP | 用于拖放的拖拽手势。<br>**起始版本：** 20        |

### ArkUI_GestureInterruptResult

```
enum ArkUI_GestureInterruptResult
```

**描述：**


定义手势打断结果。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| GESTURE_INTERRUPT_RESULT_CONTINUE = 0 | 手势继续。 |
| GESTURE_INTERRUPT_RESULT_REJECT | 手势打断。 |

### ArkUI_GestureRecognizerState

```
enum ArkUI_GestureRecognizerState
```

**描述：**


定义手势识别器状态。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_GESTURE_RECOGNIZER_STATE_READY = 0 | 准备状态。 |
| ARKUI_GESTURE_RECOGNIZER_STATE_DETECTING = 1 | 检测状态。 |
| ARKUI_GESTURE_RECOGNIZER_STATE_PENDING = 2 | 等待状态。 |
| ARKUI_GESTURE_RECOGNIZER_STATE_BLOCKED = 3 | 阻塞状态。 |
| ARKUI_GESTURE_RECOGNIZER_STATE_SUCCESSFUL = 4 | 成功状态。 |
| ARKUI_GESTURE_RECOGNIZER_STATE_FAILED = 5 | 失败状态。 |


## 函数说明

### ArkUI_GestureRecognizerDisposeNotifyCallback()

```
typedef void (*ArkUI_GestureRecognizerDisposeNotifyCallback)(ArkUI_GestureRecognizer* recognizer, void* userData)
```

**描述：**


定义手势识别器析构通知事件的回调函数类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| void* userData | 用户自定义数据。 |

### OH_ArkUI_GestureInterruptInfo_GetSystemFlag()

```
bool OH_ArkUI_GestureInterruptInfo_GetSystemFlag(const ArkUI_GestureInterruptInfo* event)
```

**描述：**


判断是否组件内置手势。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)* event | 手势打断回调事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | true: 系统内置手势；<br>         false: 非系统内置手势。 |

### OH_ArkUI_GestureInterruptInfo_GetRecognizer()

```
ArkUI_GestureRecognizer* OH_ArkUI_GestureInterruptInfo_GetRecognizer(const ArkUI_GestureInterruptInfo* event)
```

**描述：**


返回被打断的手势指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)* event | 手势打断回调事件。 |

**返回：**

| 类型                           | 说明 |
|------------------------------| -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | 被打断的手势指针。 |

### OH_ArkUI_GestureInterruptInfo_GetGestureEvent()

```
ArkUI_GestureEvent* OH_ArkUI_GestureInterruptInfo_GetGestureEvent(const ArkUI_GestureInterruptInfo* event)
```

**描述：**


返回打断的手势事件数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)* event | 手势打断回调事件。 |

**返回：**

| 类型                      | 说明 |
|-------------------------| -- |
| [ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* | 打断的手势事件数据。 |

### OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType()

```
int32_t OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType(const ArkUI_GestureInterruptInfo* event)
```

**描述：**


当要触发的是系统内部手势时，使用该方法可返回该系统内部手势的类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)* event | 手势打断回调事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 要触发的内部手势对应的手势类型，如果当前触发的手势不是系统内部手势，则返回 -1。 |

### OH_ArkUI_GestureInterruptInfo_GetTouchRecognizers()

```
int32_t OH_ArkUI_GestureInterruptInfo_GetTouchRecognizers(const ArkUI_GestureInterruptInfo* info,ArkUI_TouchRecognizerHandleArray* recognizers, int32_t* size)
```

**描述：**


从手势打断信息中获取触摸识别器。

**起始版本：** 15


**参数：**

| 参数项                                                                                             | 描述 |
|-------------------------------------------------------------------------------------------------| -- |
| [const ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)* info | 指向手势打断信息的指针。 |
| [ArkUI_TouchRecognizerHandleArray](capi-arkui-nativemodule-arkui-touchrecognizerhandlearray.md)* recognizers  | 指向触摸识别器数组的指针。 |
| int32_t* size                                                                                   | 触摸识别器数组的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。 |

### OH_ArkUI_TouchRecognizer_GetNodeHandle()

```
ArkUI_NodeHandle OH_ArkUI_TouchRecognizer_GetNodeHandle(const ArkUI_TouchRecognizerHandle recognizer)
```

**描述：**


获取触摸识别器对应的组件句柄。

**起始版本：** 15


**参数：**

| 参数项                                              | 描述 |
|--------------------------------------------------| -- |
| const [ArkUI_TouchRecognizerHandle](capi-arkui-nativemodule-arkui-touchrecognizerhandlearray.md) recognizer | 触摸识别器的句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | 触摸识别器对应的组件句柄。 |

### OH_ArkUI_TouchRecognizer_CancelTouch()

```
int32_t OH_ArkUI_TouchRecognizer_CancelTouch(ArkUI_TouchRecognizerHandle recognizer, ArkUI_GestureInterruptInfo* info)
```

**描述：**


在手势打断回调中向指定的触摸识别器发送取消触摸的事件

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TouchRecognizerHandle](capi-arkui-nativemodule-arkui-touchrecognizerhandlearray.md) recognizer | 触摸识别器的句柄。 |
| [ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)* info | 指向手势打断信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。 |

### OH_ArkUI_GestureEvent_GetActionType()

```
ArkUI_GestureEventActionType OH_ArkUI_GestureEvent_GetActionType(const ArkUI_GestureEvent* event)
```

**描述：**


返回手势事件类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_GestureEventActionType](capi-native-gesture-h.md#arkui_gestureeventactiontype) | 手势事件类型。 |

### OH_ArkUI_GestureEvent_GetRawInputEvent()

```
const ArkUI_UIInputEvent* OH_ArkUI_GestureEvent_GetRawInputEvent(const ArkUI_GestureEvent* event)
```

**描述：**


返回手势输入。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型                            | 说明 |
|-------------------------------| -- |
| const [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* | 手势事件的原始输入事件。 |

### OH_ArkUI_LongPress_GetRepeatCount()

```
int32_t OH_ArkUI_LongPress_GetRepeatCount(const ArkUI_GestureEvent* event)
```

**描述：**


返回长按手势定时触发次数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 长按手势定时触发次数。 |

### OH_ArkUI_PanGesture_GetVelocity()

```
float OH_ArkUI_PanGesture_GetVelocity(const ArkUI_GestureEvent* event)
```

**描述：**


滑动手势返回手势主方向速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 当前手势主方向速度，为xy轴方向速度的平方和的算数平方根，单位px/秒。 |

### OH_ArkUI_PanGesture_GetVelocityX()

```
float OH_ArkUI_PanGesture_GetVelocityX(const ArkUI_GestureEvent* event)
```

**描述：**


滑动手势返回当前手势的x轴方向速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 当前手势的x轴方向速度，单位px/秒。 |

### OH_ArkUI_PanGesture_GetVelocityY()

```
float OH_ArkUI_PanGesture_GetVelocityY(const ArkUI_GestureEvent* event)
```

**描述：**


滑动手势返回当前手势的y轴方向速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 当前手势的y轴方向速度，单位px/秒。 |

### OH_ArkUI_PanGesture_GetOffsetX()

```
float OH_ArkUI_PanGesture_GetOffsetX(const ArkUI_GestureEvent* event)
```

**描述：**


滑动手势返回当前手势事件x轴相对偏移量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 当前手势事件x轴相对偏移量，单位为px。 |

### OH_ArkUI_PanGesture_GetOffsetY()

```
float OH_ArkUI_PanGesture_GetOffsetY(const ArkUI_GestureEvent* event)
```

**描述：**


滑动手势返回当前手势事件y轴相对偏移量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 当前手势事件y轴相对偏移量，单位为px。 |

### OH_ArkUI_SwipeGesture_GetAngle()

```
float OH_ArkUI_SwipeGesture_GetAngle(const ArkUI_GestureEvent* event)
```

**描述：**


滑动手势返回当前手势事件角度信息。角度计算方式：滑动手势被识别到后，连接两根手指之间的线被识别为起始线条，随着手指的滑动，手指之间的线条会发生旋转，<br>        根据起始线条两端点和当前线条两端点的坐标，使用反正切函数分别计算其相对于水平方向的夹角，<br>        最后arctan2(cy2-cy1,cx2-cx1)-arctan2(y2-y1,x2-x1)为旋转的角度。<br>        以起始线条为坐标系，顺时针旋转为0到180度，逆时针旋转为-180到0度。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 滑动手势的角度，即两根手指间的线段与水平方向的夹角变化的度数。单位为deg。|

### OH_ArkUI_SwipeGesture_GetVelocity()

```
float OH_ArkUI_SwipeGesture_GetVelocity(const ArkUI_GestureEvent* event)
```

**描述：**


滑动手势场景中所有手指滑动平均速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 滑动手势速度，即所有手指滑动的平均速度，单位为px/秒。 |

### OH_ArkUI_RotationGesture_GetAngle()

```
float OH_ArkUI_RotationGesture_GetAngle(const ArkUI_GestureEvent* event)
```

**描述：**


旋转手势返回当前手势事件角度信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 旋转角度。单位为deg。|

### OH_ArkUI_PinchGesture_GetScale()

```
float OH_ArkUI_PinchGesture_GetScale(const ArkUI_GestureEvent* event)
```

**描述：**


捏合手势返回当前手势事件缩放信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 缩放比例。 |

### OH_ArkUI_PinchGesture_GetCenterX()

```
float OH_ArkUI_PinchGesture_GetCenterX(const ArkUI_GestureEvent* event)
```

**描述：**


捏合手势中心点相对于当前组件元素左上角x轴坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 捏合手势中心点相对于当前组件元素左上角x轴坐标，单位为px。 |

### OH_ArkUI_PinchGesture_GetCenterY()

```
float OH_ArkUI_PinchGesture_GetCenterY(const ArkUI_GestureEvent* event)
```

**描述：**


捏合手势中心点相对于当前组件元素左上角y轴坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 捏合手势中心点相对于当前组件元素左上角y轴坐标，单位为px。 |

### OH_ArkUI_GestureEvent_GetNode()

```
ArkUI_NodeHandle OH_ArkUI_GestureEvent_GetNode(const ArkUI_GestureEvent* event)
```

**描述：**


获取绑定该手势的ARKUI组件

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureEvent](capi-arkui-nativemodule-arkui-gestureevent.md)* event | 手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | 绑定该手势的ARKUI组件。若返回Null，则表示event是无效值。 |

### OH_ArkUI_GetResponseRecognizersFromInterruptInfo()

```
int32_t OH_ArkUI_GetResponseRecognizersFromInterruptInfo(const ArkUI_GestureInterruptInfo* event,ArkUI_GestureRecognizerHandleArray* responseChain, int32_t* count)
```

**描述：**


获取手势响应链的信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)* event | 手势打断回调事件。 |
| ArkUI_GestureRecognizerHandleArray* responseChain | 响应链组件上的手势识别器。 |
| int32_t* count | 响应链组件上的手势识别器的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。 |

### OH_ArkUI_SetGestureRecognizerEnabled()

```
int32_t OH_ArkUI_SetGestureRecognizerEnabled(ArkUI_GestureRecognizer* recognizer, bool enabled)
```

**描述：**


设置手势识别器的使能状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| bool enabled | 使能状态。true表示使能，false表示无法使能。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。 |

### OH_ArkUI_SetGestureRecognizerLimitFingerCount()

```
int32_t OH_ArkUI_SetGestureRecognizerLimitFingerCount(ArkUI_GestureRecognizer* recognizer, bool limitFingerCount)
```

**描述：**


设置是否严格检查触摸手指数量的标志。实际触摸手指数量不等于设置的手指数量的时候，该手势识别不成功。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| bool limitFingerCount | 表示严格检查触摸手指数量的状态。true表示检查手指数量，false表示不检查手指数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。 |

### OH_ArkUI_GetGestureRecognizerEnabled()

```
bool OH_ArkUI_GetGestureRecognizerEnabled(ArkUI_GestureRecognizer* recognizer)
```

**描述：**


获取手势识别器的使能状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | true - 使能。<br>         false - 禁用。 |

### OH_ArkUI_GetGestureRecognizerState()

```
int32_t OH_ArkUI_GetGestureRecognizerState(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureRecognizerState* state)
```

**描述：**


获取手势识别器的状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| [ArkUI_GestureRecognizerState](capi-native-gesture-h.md#arkui_gesturerecognizerstate)* state | 手势识别器的状态。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。 |

### OH_ArkUI_GetGestureEventTargetInfo()

```
int32_t OH_ArkUI_GetGestureEventTargetInfo(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureEventTargetInfo** info)
```

**描述：**


获取手势事件目标信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| [ArkUI_GestureEventTargetInfo](capi-arkui-nativemodule-arkui-gestureeventtargetinfo.md)** info | 手势事件目标信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。 |

### OH_ArkUI_GestureEventTargetInfo_IsScrollBegin()

```
int32_t OH_ArkUI_GestureEventTargetInfo_IsScrollBegin(ArkUI_GestureEventTargetInfo* info, bool* ret)
```

**描述：**


当前滚动类容器组件是否在顶部。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureEventTargetInfo](capi-arkui-nativemodule-arkui-gestureeventtargetinfo.md)* info | 手势事件目标信息。 |
| bool* ret | 当前滚动类容器组件是否在顶部。true表示在顶部，false表示不在顶部。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。<br>         [ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER](capi-native-type-h.md#arkui_errorcode) - 非滚动类容器。 |

### OH_ArkUI_GestureEventTargetInfo_IsScrollEnd()

```
int32_t OH_ArkUI_GestureEventTargetInfo_IsScrollEnd(ArkUI_GestureEventTargetInfo* info, bool* ret)
```

**描述：**


当前滚动类容器组件是否在底部。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureEventTargetInfo](capi-arkui-nativemodule-arkui-gestureeventtargetinfo.md)* info | 手势事件目标信息。 |
| bool* ret | 当前滚动类容器组件是否在底部。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。<br>         [ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER](capi-native-type-h.md#arkui_errorcode) - 非滚动类容器。 |

### OH_ArkUI_GetPanGestureDirectionMask()

```
int32_t OH_ArkUI_GetPanGestureDirectionMask(ArkUI_GestureRecognizer* recognizer,ArkUI_GestureDirectionMask* directionMask)
```

**描述：**


获取滑动手势的滑动方向。

**起始版本：** 12


**参数：**

| 参数项                                                                                       | 描述 |
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| [ArkUI_GestureDirectionMask](#变量)* directionMask                                          | 滑动手势的滑动方向。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。 |

### OH_ArkUI_IsBuiltInGesture()

```
bool OH_ArkUI_IsBuiltInGesture(ArkUI_GestureRecognizer* recognizer)
```

**描述：**


当前手势是否为系统内置手势。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | true - 是系统内置手势。<br>         false - 不是系统内置手势。 |

### OH_ArkUI_GetGestureTag()

```
int32_t OH_ArkUI_GetGestureTag(ArkUI_GestureRecognizer* recognizer, char* buffer, int32_t bufferSize, int32_t* result)
```

**描述：**


获取手势识别器的标记。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| char* buffer | 存储区。 |
| int32_t bufferSize | 存储区大小。 |
| int32_t* result | 拷贝的字符串长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。<br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH](capi-native-type-h.md#arkui_errorcode) - 存储区大小不足。 |

### OH_ArkUI_GetGestureBindNodeId()

```
int32_t OH_ArkUI_GetGestureBindNodeId(ArkUI_GestureRecognizer* recognizer, char* nodeId, int32_t size,int32_t* result)
```

**描述：**


获取手势识别器绑定的组件的ID。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| char* nodeId | 组件的ID。 |
| int32_t size | 存储区大小。 |
| int32_t* result | 拷贝的字符串长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。<br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH](capi-native-type-h.md#arkui_errorcode) - 存储区大小不足。 |

### OH_ArkUI_IsGestureRecognizerValid()

```
bool OH_ArkUI_IsGestureRecognizerValid(ArkUI_GestureRecognizer* recognizer)
```

**描述：**


当前手势识别器是否有效。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | true - 手势识别器有效。<br>         false - 手势识别器无效。 |

### OH_ArkUI_ParallelInnerGestureEvent_GetUserData()

```
void* OH_ArkUI_ParallelInnerGestureEvent_GetUserData(ArkUI_ParallelInnerGestureEvent* event)
```

**描述：**


获取并行内部手势事件中的用户自定义数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ParallelInnerGestureEvent](capi-arkui-nativemodule-arkui-parallelinnergestureevent.md)* event | 并行内部手势事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 用户自定义数据的指针。 |

### OH_ArkUI_ParallelInnerGestureEvent_GetCurrentRecognizer()

```
ArkUI_GestureRecognizer* OH_ArkUI_ParallelInnerGestureEvent_GetCurrentRecognizer(ArkUI_ParallelInnerGestureEvent* event)
```

**描述：**


获取并行内部手势事件中的当前手势识别器。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ParallelInnerGestureEvent](capi-arkui-nativemodule-arkui-parallelinnergestureevent.md)* event | 并行内部手势事件。 |

**返回：**

| 类型                           | 说明 |
|------------------------------| -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | 当前手势识别器的指针。 |

### OH_ArkUI_ParallelInnerGestureEvent_GetConflictRecognizers()

```
int32_t OH_ArkUI_ParallelInnerGestureEvent_GetConflictRecognizers(ArkUI_ParallelInnerGestureEvent* event,ArkUI_GestureRecognizerHandleArray* array, int32_t* size)
```

**描述：**


获取并行内部手势事件中的冲突的手势识别器。

**起始版本：** 12


**参数：**

| 参数项                                                                                                  | 描述 |
|------------------------------------------------------------------------------------------------------| -- |
| [ArkUI_ParallelInnerGestureEvent](capi-arkui-nativemodule-arkui-parallelinnergestureevent.md)* event | 并行内部手势事件。 |
| [ArkUI_GestureRecognizerHandleArray](capi-arkui-nativemodule-arkui-gesturerecognizerhandle.md)* array  | 冲突的手势识别器数组。 |
| int32_t* size                                                                                        | 冲突的手势识别器数组的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。 |

### OH_ArkUI_SetArkUIGestureRecognizerDisposeNotify()

```
int32_t OH_ArkUI_SetArkUIGestureRecognizerDisposeNotify(ArkUI_GestureRecognizer* recognizer,ArkUI_GestureRecognizerDisposeNotifyCallback callback, void* userData)
```

**描述：**


设置手势识别器对象析构通知回调函数。


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| [ArkUI_GestureRecognizerDisposeNotifyCallback](capi-native-gesture-h.md#arkui_gesturerecognizerdisposenotifycallback) callback | 手势识别器对象析构通知回调函数。 |
| void* userData | 用户自定义数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) - 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) - 参数错误。 |

### OH_ArkUI_GetGestureParam_DirectMask()

```
int32_t OH_ArkUI_GetGestureParam_DirectMask(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureDirectionMask* directMask)
```

**描述：**


获取手势识别器的滑动方向。

**起始版本：** 18


**参数：**

| 参数项                                                                                       | 描述 |
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| [ArkUI_GestureDirectionMask](#变量)* directMask                                             | 手势识别器的滑动方向。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。 |

### OH_ArkUI_GetGestureParam_FingerCount()

```
int32_t OH_ArkUI_GetGestureParam_FingerCount(ArkUI_GestureRecognizer* recognizer, int* finger)
```

**描述：**


获取手势识别器的手指数。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| int* finger | 手势识别器的手指数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。 |

### OH_ArkUI_GetGestureParam_limitFingerCount()

```
int32_t OH_ArkUI_GetGestureParam_limitFingerCount(ArkUI_GestureRecognizer* recognizer, bool* isLimited)
```

**描述：**


获取手势识别器是否有手指数限制。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| bool* isLimited | 手势识别器是否有手指数限制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。 |

### OH_ArkUI_GetGestureParam_repeat()

```
int32_t OH_ArkUI_GetGestureParam_repeat(ArkUI_GestureRecognizer* recognizer, bool* isRepeat)
```

**描述：**


获取手势识别器是否连续触发事件回调。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| bool* isRepeat | 手势识别器是否连续触发事件回调。true表示连续触发，false表示不连续触发。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) 不支持手势识别器类型。 |

### OH_ArkUI_GetGestureParam_distance()

```
int32_t OH_ArkUI_GetGestureParam_distance(ArkUI_GestureRecognizer* recognizer, double* distance)
```

**描述：**


获取手势识别器的手指允许的移动距离范围。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| double* distance | 手势识别器的手指允许的移动距离范围。单位为px。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) 不支持手势识别器类型。 |

### OH_ArkUI_GetGestureParam_speed()

```
int32_t OH_ArkUI_GetGestureParam_speed(ArkUI_GestureRecognizer* recognizer, double* speed)
```

**描述：**


获取手势识别器的识别滑动的最小速度。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| double* speed | 手势识别器的识别滑动的最小速度。单位为px/s。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) 不支持手势识别器类型。 |

### OH_ArkUI_GetGestureParam_duration()

```
int32_t OH_ArkUI_GetGestureParam_duration(ArkUI_GestureRecognizer* recognizer, int* duration)
```

**描述：**


获取手势识别器的触发长按的最短时间。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| int* duration | 手势识别器的触发长按的最短时间。单位为ms。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) 不支持手势识别器类型。 |

### OH_ArkUI_GetGestureParam_angle()

```
int32_t OH_ArkUI_GetGestureParam_angle(ArkUI_GestureRecognizer* recognizer, double* angle)
```

**描述：**


获取手势识别器的旋转手势的最小改变度数。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| double* angle | 手势识别器的旋转手势的最小改变度数。单位为deg。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) 不支持手势识别器类型。 |

### OH_ArkUI_GetGestureParam_distanceThreshold()

```
int32_t OH_ArkUI_GetGestureParam_distanceThreshold(ArkUI_GestureRecognizer* recognizer, double* distanceThreshold)
```

**描述：**


获取手势识别器的手势移动阈值。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| double* distanceThreshold | 手势识别器的手势移动阈值。单位：px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) 不支持手势识别器类型。 |

### OH_ArkUI_PanGesture_SetDistanceMap()

```
ArkUI_ErrorCode OH_ArkUI_PanGesture_SetDistanceMap(ArkUI_GestureRecognizer* recognizer, int size, int* toolTypeArray, double* distanceArray)
```

**描述：**


设置手势最小滑动阈值表。当设备类型为非法值时，设置不生效。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| int size | 手势最小滑动阈值数组的大小。 |
| int* toolTypeArray | 指向输入事件的工具类型数组的指针。 |
| double* distanceArray | 指向最小滑动阈值数组的指针。单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。<br>         Returns [ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) 不支持手势识别器类型。 |

### OH_ArkUI_PanGesture_GetDistanceByToolType()

```
ArkUI_ErrorCode OH_ArkUI_PanGesture_GetDistanceByToolType(ArkUI_GestureRecognizer* recognizer, int toolType, double* distance)
```

**描述：**


获取手势识别器的手势移动阈值表。仅支持对通过OH_ArkUI_PanGesture_SetDistanceMap修改过的设备类型的阈值查询。默认滑动阈值可通过查询UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN类型获得，其他未设置过的类型不会返回。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |
| int toolType | 输入事件的工具类型。 |
| double* distance | 手势识别器的手势移动阈值。单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。<br>         Returns [ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED](capi-native-type-h.md#arkui_errorcode) 不支持手势识别器类型。 |

### OH_ArkUI_SetTouchTestDoneCallback()

```
ArkUI_ErrorCode OH_ArkUI_SetTouchTestDoneCallback(ArkUI_NodeHandle node,void* userData,void (*touchTestDone)(ArkUI_GestureEvent* event,ArkUI_GestureRecognizerHandleArray recognizers,int32_t count,void* userData)
)
```

**描述：**


注册一个在所有手势识别器收集完成后执行的回调函数。当用户开始触摸屏幕时，系统会进行命中测试并根据触摸位置收集手势识别器。随后，在处理任何移动事件之前，组件可以使用此接口确定将参与识别并相互竞争的手势识别器。

**起始版本：** 20


**参数：**

| 参数项                       | 描述 |
|---------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 需要设置手势收集完成回调的节点句柄。 |
| void* userData            | 用户自定义数据。 |
| touchTestDone             | 手势收集完成的回调函数。- event：手势的基本信息。- recognizers：手势识别器数组。- count：手势识别器个数。 |

**返回：**

| 类型                                                       | 说明 |
|----------------------------------------------------------| -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。 |

### OH_ArkUI_GestureInterrupter_GetUserData()

```
void* OH_ArkUI_GestureInterrupter_GetUserData(ArkUI_GestureInterruptInfo* event)
```

**描述：**


获取手势中断事件中的用户自定义数据。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureInterruptInfo](capi-arkui-nativemodule-arkui-gestureinterruptinfo.md)* event | 是指向手势中断信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 返回指向用户自定义数据的指针。 |

### OH_ArkUI_PreventGestureRecognizerBegin()

```
ArkUI_ErrorCode OH_ArkUI_PreventGestureRecognizerBegin(ArkUI_GestureRecognizer* recognizer)
```

**描述：**


在手指全部抬起前阻止手势识别器参与当前手势识别。如果系统已确定该手势识别器的结果（无论成功与否），调用此接口将无效。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | 手势识别器指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 错误码。<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数错误。 |


