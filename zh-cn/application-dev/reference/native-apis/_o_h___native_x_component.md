# Native XComponent


描述ArkUI XComponent持有的surface和触摸事件，该事件可用于EGL/OpenGLES和媒体数据输入，并显示在ArkUI XComponent上。

**起始版本：**


8


## 汇总


### 文件

| 文件名称                                                     | 描述                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| [native_interface_xcomponent.h](native__interface__xcomponent_8h.md) | 声明用于访问Native XComponent的API。<br>引用文件：<ace/xcomponent/native_interface_xcomponent.h> |


### 结构体

| 结构体名称                                                   | 描述                                |
| ------------------------------------------------------------ | ----------------------------------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) | 触摸事件中触摸点的信息。            |
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | 触摸事件。                          |
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | 鼠标事件。                          |
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | 注册surface生命周期和触摸事件回调。 |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | 注册鼠标事件的回调。                |


### 类型定义

| 类型定义名称                                                 | 描述                                |
| ------------------------------------------------------------ | ----------------------------------- |
| [OH_NativeXComponent](#oh_nativexcomponent)                  | 提供封装的OH_NativeXComponent实例。 |
| [OH_NativeXComponent_Callback](#oh_nativexcomponent_callback) | 注册surface生命周期和触摸事件回调。 |
| [OH_NativeXComponent_MouseEvent_Callback](#oh_nativexcomponent_mouseevent_callback) | 注册鼠标事件的回调。                |


### 枚举

| 枚举名称                                                     | 描述                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| {OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, <br>OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, <br/>OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2 } | [枚举](#anonymous-enum)API访问状态。 |
| [OH_NativeXComponent_TouchEventType](#oh_nativexcomponent_toucheventtype) {  <br/>OH_NATIVEXCOMPONENT_DOWN = 0, <br/>OH_NATIVEXCOMPONENT_UP, <br/>OH_NATIVEXCOMPONENT_MOVE, <br/>OH_NATIVEXCOMPONENT_CANCEL,<br/>OH_NATIVEXCOMPONENT_UNKNOWN } | 触摸事件类型。                       |
| [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype) {<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN = 0,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS } | 触摸点工具类型。 | 
| [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype) {<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN = 0,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE, OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK} | 触摸事件源类型。 | 
| [OH_NativeXComponent_MouseEventAction](#oh_nativexcomponent_mouseeventaction) { <br/>OH_NATIVEXCOMPONENT_MOUSE_NONE = 0, <br/>OH_NATIVEXCOMPONENT_MOUSE_PRESS, <br/>OH_NATIVEXCOMPONENT_MOUSE_RELEASE, <br/>OH_NATIVEXCOMPONENT_MOUSE_MOVE } | 鼠标事件动作。                       |
| [OH_NativeXComponent_MouseEventButton](#oh_nativexcomponent_mouseeventbutton) {  <br/>OH_NATIVEXCOMPONENT_NONE_BUTTON = 0, <br/>OH_NATIVEXCOMPONENT_LEFT_BUTTON = 0x01, <br/>OH_NATIVEXCOMPONENT_RIGHT_BUTTON = 0x02, <br/>OH_NATIVEXCOMPONENT_MIDDLE_BUTTON = 0x04,   <br/>OH_NATIVEXCOMPONENT_BACK_BUTTON = 0x08, <br/>OH_NATIVEXCOMPONENT_FORWARD_BUTTON = 0x10 } | 鼠标事件按键。                       |


### 函数

| 函数名称                                                     | 描述                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| [OH_NativeXComponent_GetXComponentId](#oh_nativexcomponent_getxcomponentid) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, char \*id, uint64_t \*size) | 获取ArkUI XComponent的id。                         |
| [OH_NativeXComponent_GetXComponentSize](#oh_nativexcomponent_getxcomponentsize) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, uint64_t \*width, uint64_t \*height) | 获取ArkUI XComponent持有的surface的大小。          |
| [OH_NativeXComponent_GetXComponentOffset](#oh_nativexcomponent_getxcomponentoffset) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, double \*x, double \*y) | 获取ArkUI XComponent组件相对屏幕左上顶点的偏移量。 |
| [OH_NativeXComponent_GetTouchEvent](#oh_nativexcomponent_gettouchevent) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) \*touchEvent) | 获取ArkUI XComponent调度的触摸事件。               |
| [OH_NativeXComponent_GetTouchPointToolType](#oh_nativexcomponent_gettouchpointtooltype) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype) \*toolType) | 获取ArkUI XComponent触摸点工具类型。 | 
| [OH_NativeXComponent_GetTouchPointTiltX](#oh_nativexcomponent_gettouchpointtiltx) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltX) | 获取ArkUI XComponent触摸点倾斜与X轴角度。 | 
| [OH_NativeXComponent_GetTouchPointTiltY](#oh_nativexcomponent_gettouchpointtilty) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltY) | 获取ArkUI XComponent触摸点倾斜与Y轴角度。 | 
| [OH_NativeXComponent_GetMouseEvent](#oh_nativexcomponent_getmouseevent) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) \*mouseEvent) | 获取ArkUI XComponent调度的鼠标事件                 |
| [OH_NativeXComponent_RegisterCallback](#oh_nativexcomponent_registercallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) \*callback) | 为此OH_NativeXComponent实例注册回调。              |
| [OH_NativeXComponent_RegisterMouseEventCallback](#oh_nativexcomponent_registermouseeventcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) \*callback) | 为此OH_NativeXComponent实例注册鼠标事件回调。      |


### 变量

| 变量名称                                                     | 描述                                      |
| ------------------------------------------------------------ | ----------------------------------------- |
| [OH_XCOMPONENT_ID_LEN_MAX](#oh_xcomponent_id_len_max) = 128  | ArkUI XComponent的id最大长度。            |
| [OH_MAX_TOUCH_POINTS_NUMBER](#oh_max_touch_points_number) = 10 | 触摸事件中的可识别的触摸点个数最大值。    |
| [OH_NativeXComponent_TouchPoint::id](#id-12) = 0             | 手指的唯一标识符。                        |
| [OH_NativeXComponent_TouchPoint::screenX](#screenx-13) = 0.0 | 触摸点相对于XComponent所在应用窗口左上角的x坐标。           |
| [OH_NativeXComponent_TouchPoint::screenY](#screeny-13) = 0.0 | 触摸点相对于XComponent所在应用窗口左上角的y坐标。           |
| [OH_NativeXComponent_TouchPoint::x](#x-13) = 0.0             | 触摸点相对于XComponent组件左边缘的x坐标。 |
| [OH_NativeXComponent_TouchPoint::y](#y-13) = 0.0             | 触摸点相对于XComponent组件上边缘的y坐标。 |
| [OH_NativeXComponent_TouchPoint::type](#type-12) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | 触摸事件的触摸类型。                      |
| [OH_NativeXComponent_TouchPoint::size](#size-12) = 0.0       | 指垫和屏幕之间的接触面积。                |
| [OH_NativeXComponent_TouchPoint::force](#force-12) = 0.0     | 当前触摸事件的压力。                      |
| [OH_NativeXComponent_TouchPoint::timeStamp](#timestamp-12) = 0 | 当前触摸事件的时间戳。                    |
| [OH_NativeXComponent_TouchPoint::isPressed](#ispressed) = false | 当前点是否被按下。                        |
| [OH_NativeXComponent_TouchEvent::id](#id-22) = 0             | 手指的唯一标识符。                        |
| [OH_NativeXComponent_TouchEvent::screenX](#screenx-23) = 0.0 | 触摸点相对于XComponent所在应用窗口左上角的x坐标。           |
| [OH_NativeXComponent_TouchEvent::screenY](#screeny-23) = 0.0 | 触摸点相对于XComponent所在应用窗口左上角的y坐标。           |
| [OH_NativeXComponent_TouchEvent::x](#x-23) = 0.0             | 触摸点相对于XComponent组件左边缘的x坐标。 |
| [OH_NativeXComponent_TouchEvent::y](#y-23) = 0.0             | 触摸点相对于XComponent组件上边缘的y坐标。 |
| [OH_NativeXComponent_TouchEvent::type](#type-22) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | 触摸事件的触摸类型。                      |
| [OH_NativeXComponent_TouchEvent::size](#size-22) = 0.0       | 指垫和屏幕之间的接触面积。                |
| [OH_NativeXComponent_TouchEvent::force](#force-22) = 0.0     | 当前触摸事件的压力。                      |
| [OH_NativeXComponent_TouchEvent::deviceId](#deviceid) = 0    | 产生当前触摸事件的设备的ID。              |
| [OH_NativeXComponent_TouchEvent::timeStamp](#timestamp-22) = 0 | 当前触摸事件的时间戳。                    |
| [OH_NativeXComponent_TouchEvent::touchPoints](#touchpoints) [OH_MAX_TOUCH_POINTS_NUMBER] | 当前触摸点的数组。                        |
| [OH_NativeXComponent_TouchEvent::numPoints](#numpoints) = 0  | 当前接触点的数量。                        |
| [OH_NativeXComponent_MouseEvent::x](#x-33) = 0.0             | 点击触点相对于当前组件左上角的x轴坐标。   |
| [OH_NativeXComponent_MouseEvent::y](#y-33) = 0.0             | 点击触点相对于当前组件左上角的y轴坐标。   |
| [OH_NativeXComponent_MouseEvent::screenX](#screenx-33) = 0.0 | 点击触点相对于XComponent所在应用窗口左上角的x轴坐标。       |
| [OH_NativeXComponent_MouseEvent::screenY](#screeny-33) = 0.0 | 点击触点相对于XComponent所在应用窗口左上角的y轴坐标。       |
| [OH_NativeXComponent_MouseEvent::timestamp](#timestamp) = 0  | 当前鼠标事件的时间戳。                    |
| [OH_NativeXComponent_MouseEvent::action](#action) = [OH_NativeXComponent_MouseEventAction::OH_NATIVEXCOMPONENT_MOUSE_NONE](#oh_nativexcomponent_mouseeventaction) | 当前鼠标事件动作。                        |
| [OH_NativeXComponent_MouseEvent::button](#button) = [OH_NativeXComponent_MouseEventButton::OH_NATIVEXCOMPONENT_NONE_BUTTON](#oh_nativexcomponent_mouseeventbutton) | 鼠标事件按键。                            |
| [OH_NativeXComponent_Callback::OnSurfaceCreated](#onsurfacecreated) | 创建surface时调用。                       |
| [OH_NativeXComponent_Callback::OnSurfaceChanged](#onsurfacechanged) | 当surface改变时调用。                     |
| [OH_NativeXComponent_Callback::OnSurfaceDestroyed](#onsurfacedestroyed) | 当surface被销毁时调用。                   |
| [OH_NativeXComponent_Callback::DispatchTouchEvent](#dispatchtouchevent) | 当触摸事件被触发时调用。                  |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent](#dispatchmouseevent) | 当鼠标事件被触发时调用。                  |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent](#dispatchhoverevent) | 当悬停事件被触发时调用。                  |


## 详细描述


## 类型定义说明


### OH_NativeXComponent


```
typedef struct OH_NativeXComponent OH_NativeXComponent
```

**描述：**

提供封装的OH_NativeXComponent实例。

**起始版本：**

8


### OH_NativeXComponent_Callback


```
typedef struct OH_NativeXComponent_Callback OH_NativeXComponent_Callback
```

**描述：**

注册surface生命周期和触摸事件回调。

**起始版本：**

8


### OH_NativeXComponent_MouseEvent_Callback


```
typedef struct OH_NativeXComponent_MouseEvent_Callback OH_NativeXComponent_MouseEvent_Callback
```

**描述：**

注册鼠标事件的回调。

**起始版本：**

9


## 枚举类型说明


### anonymous enum


```
anonymous enum
```

**描述：**

枚举API访问状态。

| 枚举值                                   | 描述       |
| ---------------------------------------- | ---------- |
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS       | 成功结果。 |
| OH_NATIVEXCOMPONENT_RESULT_FAILED        | 失败结果。 |
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER | 无效参数。 |

**起始版本：**

8

### OH_NativeXComponent_EventSourceType

OH_NativeXComponent_EventSourceType

  
```
enum OH_NativeXComponent_EventSourceType
```

**描述：**

触摸事件源类型。

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN | 未知的输入源类型。 | 
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE | 表示输入源生成鼠标多点触摸事件。 | 
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN | 表示输入源生成一个触摸屏多点触摸事件。 | 
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD | 表示输入源生成一个触摸板多点触摸事件。 | 
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK | 表示输入源生成一个操纵杆多点触摸事件。 | 

**起始版本：**

9

### OH_NativeXComponent_MouseEventAction


```
enum OH_NativeXComponent_MouseEventAction
```

**描述：**

鼠标事件动作.

| 枚举值                            | 描述                             |
| --------------------------------- | -------------------------------- |
| OH_NATIVEXCOMPONENT_MOUSE_NONE    | 无效鼠标事件 。                  |
| OH_NATIVEXCOMPONENT_MOUSE_PRESS   | 鼠标按键按下时触发鼠标事件。     |
| OH_NATIVEXCOMPONENT_MOUSE_RELEASE | 鼠标按键松开时触发鼠标事件。     |
| OH_NATIVEXCOMPONENT_MOUSE_MOVE    | 鼠标在屏幕上移动时触发鼠标事件。 |

**起始版本：**

9


### OH_NativeXComponent_MouseEventButton


```
enum OH_NativeXComponent_MouseEventButton
```

**描述：**

鼠标事件按键。

| 枚举值                             | 描述                               |
| ---------------------------------- | ---------------------------------- |
| OH_NATIVEXCOMPONENT_NONE_BUTTON    | 鼠标无按键操作时触发鼠标事件。     |
| OH_NATIVEXCOMPONENT_LEFT_BUTTON    | 按下鼠标左键时触发鼠标事件。       |
| OH_NATIVEXCOMPONENT_RIGHT_BUTTON   | 按下鼠标右键时触发鼠标事件。       |
| OH_NATIVEXCOMPONENT_MIDDLE_BUTTON  | 按下鼠标中键时触发鼠标事件。       |
| OH_NATIVEXCOMPONENT_BACK_BUTTON    | 按下鼠标左侧后退键时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_FORWARD_BUTTON | 按下鼠标左侧前进键时触发鼠标事件。 |

**起始版本：**

9


### OH_NativeXComponent_TouchEventType


```
enum OH_NativeXComponent_TouchEventType
```

**描述：**

触摸事件类型。

| 枚举值                      | 描述                                       |
| --------------------------- | ------------------------------------------ |
| OH_NATIVEXCOMPONENT_DOWN    | 手指按下时触发触摸事件。                   |
| OH_NATIVEXCOMPONENT_UP      | 手指抬起时触发触摸事件。                   |
| OH_NATIVEXCOMPONENT_MOVE    | 手指按下状态下在屏幕上移动时触发触摸事件。 |
| OH_NATIVEXCOMPONENT_CANCEL  | 触摸事件取消时触发事件。                   |
| OH_NATIVEXCOMPONENT_UNKNOWN | 无效的触摸类型。                           |

**起始版本：**

8

### OH_NativeXComponent_TouchPointToolType

  
```
enum OH_NativeXComponent_TouchPointToolType
```

**描述：**

触摸点工具类型

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN | 无效的工具类型。 | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER | 表示用手指。 | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN | 表示用触笔。 | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER | 表示用橡皮擦。 | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH | 表示用画笔。 | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL | 表示用铅笔。 | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH | 表示用气笔。 | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE | 表示用鼠标。 | 
| OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS | 表示用晶状体。 | 

**起始版本：**

9


## 函数说明


### OH_NativeXComponent_GetMouseEvent()


```
int32_t OH_NativeXComponent_GetMouseEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_MouseEvent * mouseEvent )
```

**描述：**

获取ArkUI XComponent调度的鼠标事件

**参数：**

| Name       | 描述                                    |
| ---------- | --------------------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。 |
| window     | 表示NativeWindow句柄。                  |
| mouseEvent | 指示指向当前鼠标事件的指针。            |

**返回：**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetTouchEvent()


```
int32_t OH_NativeXComponent_GetTouchEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_TouchEvent * touchEvent )
```

**描述：**

获取ArkUI XComponent调度的触摸事件。

**参数：**

| Name       | 描述                                    |
| ---------- | --------------------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。 |
| window     | 表示NativeWindow句柄。                  |
| touchEvent | 指示指向当前触摸事件的指针。            |

**返回：**

返回执行的状态代码。

**起始版本：**

8

### OH_NativeXComponent_GetTouchPointTiltX()

  
```
int32_t OH_NativeXComponent_GetTouchPointTiltX (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltX )
```

**描述：**

获取ArkUI XComponent触摸点倾斜与X轴角度。

**参数：**

| Name | 描述 | 
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 | 
| pointIndex | 表示触摸点的指针索引。 | 
| tiltX | 表示指向X倾斜度的指针。 | 

**返回：**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetTouchPointTiltY()

  
```
int32_t OH_NativeXComponent_GetTouchPointTiltX (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltY )
```

**描述：**

获取ArkUI XComponent触摸点倾斜与Y轴角度。

**参数：**

| Name | 描述 | 
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 | 
| pointIndex | 表示触摸点的指针索引。 | 
| tiltY | 表示指向Y倾斜度的指针。 | 

**返回：**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetTouchPointToolType()

  
```
int32_t OH_NativeXComponent_GetTouchPointToolType (OH_NativeXComponent * component, uint32_t pointIndex, OH_NativeXComponent_TouchPointToolType * toolType )
```

**描述：**

获取ArkUI XComponent触摸点工具类型。

**参数：**

| Name | 描述 | 
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。 | 
| pointIndex | 表示触摸点的指针索引。 | 
| toolType | 表示指向工具类型的指针。 | 

**返回：**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetXComponentId()


```
int32_t OH_NativeXComponent_GetXComponentId (OH_NativeXComponent * component, char * id, uint64_t * size )
```

**描述：**

获取ArkUI XComponent的id。

**参数：**

| Name      | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| component | 表示指向OH_NativeXComponent实例的指针。                      |
| id        | 指示用于保存此OH_NativeXComponent实例的ID的字符缓冲区。 请注意，空终止符将附加到字符缓冲区，因此字符缓冲区的大小应至少比真实id长度大一个单位。 建议字符缓冲区的大小为[OH_XCOMPONENT_ID_LEN_MAX + 1]。 |
| size      | 指示指向id长度的指针。                                       |

**返回：**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_GetXComponentOffset()


```
int32_t OH_NativeXComponent_GetXComponentOffset (OH_NativeXComponent * component, const void * window, double * x, double * y )
```

**描述：**

获取ArkUI XComponent组件相对屏幕左上顶点的偏移量。

**参数：**

| Name      | 描述                                    |
| --------- | --------------------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window    | 表示NativeWindow句柄。                  |
| x         | 指示指向当前surface的x坐标的指针。      |
| y         | 指示指向当前surface的y坐标的指针。      |

**返回：**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_GetXComponentSize()


```
int32_t OH_NativeXComponent_GetXComponentSize (OH_NativeXComponent * component, const void * window, uint64_t * width, uint64_t * height )
```

**描述：**

获取ArkUI XComponent持有的surface的大小。

**参数：**

| Name      | 描述                                    |
| --------- | --------------------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window    | 表示NativeWindow句柄。                  |
| width     | 指示指向当前surface宽度的指针。         |
| height    | 指示指向当前surface高度的指针。         |

**返回：**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_RegisterCallback()


```
int32_t OH_NativeXComponent_RegisterCallback (OH_NativeXComponent * component, OH_NativeXComponent_Callback * callback )
```

**描述：**

为此OH_NativeXComponent实例注册回调。

**参数：**

| Name      | 描述                                          |
| --------- | --------------------------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。       |
| callback  | 指示指向surface生命周期和触摸事件回调的指针。 |

**返回：**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_RegisterMouseEventCallback()


```
int32_t OH_NativeXComponent_RegisterMouseEventCallback (OH_NativeXComponent * component, OH_NativeXComponent_MouseEvent_Callback * callback )
```

**描述：**

为此OH_NativeXComponent实例注册鼠标事件回调。

**参数：**

| Name      | 描述                                    |
| --------- | --------------------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向鼠标事件回调的指针。            |

**返回：**

返回执行的状态代码。

**起始版本：**

9


## 变量说明


### OH_XCOMPONENT_ID_LEN_MAX


```
const uint32_t OH_XCOMPONENT_ID_LEN_MAX = 128
```

**描述：**

ArkUI XComponent的id最大长度。

**起始版本：**

8


### OH_MAX_TOUCH_POINTS_NUMBER


```
const uint32_t OH_MAX_TOUCH_POINTS_NUMBER = 10
```

**描述：**

触摸事件中的可识别的触摸点个数最大值。

**起始版本：**

8


### action


```
OH_NativeXComponent_MouseEventAction OH_NativeXComponent_MouseEvent::action
```

**描述：**

当前鼠标事件动作。

**起始版本：**

8


### button


```
OH_NativeXComponent_MouseEventButton OH_NativeXComponent_MouseEvent::button
```

**描述：**

鼠标事件按键

**起始版本：**

8


### deviceId


```
int64_t OH_NativeXComponent_TouchEvent::deviceId = 0
```

**描述：**

产生当前触摸事件的设备的ID。

**起始版本：**

8


### DispatchHoverEvent


```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent) (OH_NativeXComponent *component, bool isHover)
```

**描述：**

当悬停事件被触发时调用。

**起始版本：**

8


### DispatchMouseEvent


```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent) (OH_NativeXComponent *component, void *window)
```

**描述：**

当鼠标事件被触发时调用。

**起始版本：**

8


### DispatchTouchEvent


```
void(* OH_NativeXComponent_Callback::DispatchTouchEvent) (OH_NativeXComponent *component, void *window)
```

**描述：**

当触摸事件被触发时调用。

**起始版本：**

8


### force [1/2]


```
float OH_NativeXComponent_TouchPoint::force = 0.0
```

**描述：**

当前触摸事件的压力。

**起始版本：**

8


### force [2/2]


```
float OH_NativeXComponent_TouchEvent::force = 0.0
```

**描述：**

当前触摸事件的压力。

**起始版本：**

8


### id [1/2]


```
int32_t OH_NativeXComponent_TouchPoint::id = 0
```

**描述：**

手指的唯一标识符。

**起始版本：**

8


### id [2/2]


```
int32_t OH_NativeXComponent_TouchEvent::id = 0
```

**描述：**

手指的唯一标识符。

**起始版本：**

8


### isPressed


```
bool OH_NativeXComponent_TouchPoint::isPressed = false
```

**描述：**

当前点是否被按下。

**起始版本：**

8


### numPoints


```
uint32_t OH_NativeXComponent_TouchEvent::numPoints = 0
```

**描述：**

当前接触点的数量。

**起始版本：**

8


### OnSurfaceChanged


```
void(* OH_NativeXComponent_Callback::OnSurfaceChanged) (OH_NativeXComponent *component, void *window)
```

**描述：**

当surface改变时调用。

**起始版本：**

8


### OnSurfaceCreated


```
void(* OH_NativeXComponent_Callback::OnSurfaceCreated) (OH_NativeXComponent *component, void *window)
```

**描述：**

创建surface时调用。

**起始版本：**

8


### OnSurfaceDestroyed


```
void(* OH_NativeXComponent_Callback::OnSurfaceDestroyed) (OH_NativeXComponent *component, void *window)
```

**描述：**

当surface被销毁时调用。

**起始版本：**

8


### screenX [1/3]


```
float OH_NativeXComponent_TouchPoint::screenX = 0.0
```

**描述：**

触摸点相对于应用窗口左上角的x坐标。

**起始版本：**

8


### screenX [2/3]


```
float OH_NativeXComponent_TouchEvent::screenX = 0.0
```

**描述：**

触摸点相对于应用窗口左上角的x坐标。

**起始版本：**

8


### screenX [3/3]


```
float OH_NativeXComponent_MouseEvent::screenX
```

**描述：**

点击触点相对于应用窗口左上角的x轴坐标。

**起始版本：**

8


### screenY [1/3]


```
float OH_NativeXComponent_TouchPoint::screenY = 0.0
```

**描述：**

触摸点相对于应用窗口左上角的y坐标。

**起始版本：**

8


### screenY [2/3]


```
float OH_NativeXComponent_TouchEvent::screenY = 0.0
```

**描述：**

触摸点相对于应用窗口左上角的y坐标。

**起始版本：**

8


### screenY [3/3]


```
float OH_NativeXComponent_MouseEvent::screenY
```

**描述：**

点击触点相对于应用窗口左上角的y轴坐标。

**起始版本：**

8


### size [1/2]


```
double OH_NativeXComponent_TouchPoint::size = 0.0
```

**描述：**

指垫和屏幕之间的接触面积。

**起始版本：**

8


### size [2/2]


```
double OH_NativeXComponent_TouchEvent::size = 0.0
```

**描述：**

指垫和屏幕之间的接触面积。

**起始版本：**

8


### timeStamp [1/2]


```
long long OH_NativeXComponent_TouchPoint::timeStamp = 0
```

**描述：**

当前触摸事件的时间戳。

**起始版本：**

8


### timeStamp [2/2]


```
long long OH_NativeXComponent_TouchEvent::timeStamp = 0
```

**描述：**

当前触摸事件的时间戳。

**起始版本：**

8


### timestamp


```
int64_t OH_NativeXComponent_MouseEvent::timestamp
```

**描述：**

当前鼠标事件的时间戳

**起始版本：**

8


### touchPoints


```
OH_NativeXComponent_TouchPoint OH_NativeXComponent_TouchEvent::touchPoints[OH_MAX_TOUCH_POINTS_NUMBER]
```

**描述：**

当前触摸点的数组。

**起始版本：**

8


### type [1/2]


```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchPoint::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**描述：**

触摸事件的触摸类型。

**起始版本：**

8


### type [2/2]


```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchEvent::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**描述：**

触摸事件的触摸类型。

**起始版本：**

8


### x [1/3]


```
float OH_NativeXComponent_TouchPoint::x = 0.0
```

**描述：**

触摸点相对于XComponent组件左边缘的x坐标。

**起始版本：**

8


### x [2/3]


```
float OH_NativeXComponent_TouchEvent::x = 0.0
```

**描述：**

触摸点相对于XComponent组件左边缘的x坐标。

**起始版本：**

8


### x [3/3]


```
float OH_NativeXComponent_MouseEvent::x
```

**描述：**

点击触点相对于当前组件左上角的x轴坐标。

**起始版本：**

8


### y [1/3]


```
float OH_NativeXComponent_TouchPoint::y = 0.0
```

**描述：**

触摸点相对于XComponent组件上边缘的y坐标。

**起始版本：**

8


### y [2/3]


```
float OH_NativeXComponent_TouchEvent::y = 0.0
```

**描述：**

触摸点相对于XComponent组件上边缘的y坐标。

**起始版本：**

8


### y [3/3]


```
float OH_NativeXComponent_MouseEvent::y
```

**描述：**

点击触点相对于当前组件左上角的y轴坐标。

**起始版本：**

8