# ui_input_event.h

## 概述

提供ArkUI在Native侧的事件定义。

**引用文件：** <arkui/ui_input_event.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_EventModule](capi-arkui-eventmodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md) | ArkUI_UIInputEvent | UI输入事件定义。 |

### 枚举

| 名称                                                  | typedef关键字 | 描述 |
|-----------------------------------------------------| -- | -- |
| [ArkUI_UIInputEvent_Type](#arkui_uiinputevent_type) | ArkUI_UIInputEvent_Type | UI输入事件类型定义。 |
| [anonymous1](#anonymous1)                       | - | 定义输入事件的Action Code。 |
| [anonymous2](#anonymous2)                       | - | 产生输入事件的工具类型定义。 |
| [anonymous3](#anonymous3)                       | - | 产生输入事件的来源类型定义。 |
| [HitTestMode](#hittestmode)                         | HitTestMode | 定义触摸测试类型的枚举值。 |
| [anonymous4](#anonymous4)                       | - | 定义鼠标事件的Action Code。 |
| [anonymous5](#anonymous5)                       | - | 定义鼠标事件的按键类型。 |
| [ArkUI_ModifierKeyName](#arkui_modifierkeyname)     | ArkUI_ModifierKeyName | 定义modifier按键。 |
| [anonymous6](#anonymous6)                       | - | 定义焦点轴事件的轴类型。 |
| [ArkUI_InteractionHand](#arkui_interactionhand)     | ArkUI_InteractionHand | 定义触摸事件是左手还是右手。 |
| [anonymous7](#anonymous7)                       | - | 定义轴事件的操作类型。 |

### 函数

| 名称 | 描述                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| -- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [int32_t OH_ArkUI_UIInputEvent_GetType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettype) | 获取UI输入事件的类型。在访问一个ArkUI_UIInputEvent指针对象之前，推荐使用该方法判断该输入事件的类型，该接口会返回[ArkUI_UIInputEvent_Type](capi-ui-input-event-h.md#arkui_uiinputevent_type)枚举中的一种。比如，当事件是一个触控类型时，由于触控类型是指向性事件，那么使用OH_ArkUI_UIInputEvent_GetXXX及OH_ArkUI_PointerEvent_GetXXX系列接口，均可以正常访问；而如果使用OH_ArkUI_KeyEvent_GetXXX相关接口去访问它，则会有无法预期的结果。对于还未支持的事件类型，接口返回默认值0。                                                                                                                                                                                                                                                       |
| [int32_t OH_ArkUI_UIInputEvent_GetAction(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getaction) | 获取输入事件的action类型。action类型为基础事件在不同阶段的类型定义，通常代表了事件的特点，并表征事件的开始与结束，如touch down, touch up。触控事件的action类型为UI_TOUCH_EVENT_ACTION_XXX，鼠标事件的action类型为UI_MOUSE_EVENT_ACTION_XXX。                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [int32_t OH_ArkUI_UIInputEvent_GetSourceType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getsourcetype) | 获取UI输入事件的触发源类型。输入源为产生输入事件的真实物理设备，如触摸屏，鼠标等，由UI_INPUT_EVENT_SOURCE_TYPE_XXX定义，而输入工具为操作输入源设备来产生事件的工具，如手指、触控笔。在某些情况下两者可能容易发生混淆，比如当用户在操作鼠标时，鼠标既是输入源，也是输入工具。                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [int32_t OH_ArkUI_UIInputEvent_GetToolType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettooltype) | 获取UI输入事件的工具类型。输入工具为操作输入源设备来产生事件的操作方，如手指、触控笔，他们自身不真实产生事件，但可以驱动输入源设备不断产生事件。返回的类型由UI_INPUT_EVENT_TOOL_TYPE_XXX枚举值定义。                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [int64_t OH_ArkUI_UIInputEvent_GetEventTime(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtime) | 获取UI输入事件发生的时间。单位为ns。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [uint32_t OH_ArkUI_PointerEvent_GetPointerCount(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getpointercount) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点数量。指向性事件一般是附带有事件发生位置信息的事件，如触摸事件，用户操作时，可以感知事件在什么位置发生。而非指向性事件，如按键事件，一般没有位置信息，没有触点的说法，所以该接口对按键事件无效。对于触摸事件，该接口多用于处理多指触控，判断用户有几根手指在操作当前控件。而对于鼠标和轴事件，可认为触点只有1个，该接口永远返回1。                                                                                                                                                                                                                                                                                                                                                                                  |
| [int32_t OH_ArkUI_PointerEvent_GetPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getpointerid) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。返回事件发生时，事件触点的唯一标识符，用于区分同类输入设备的多点触控信息。其数值没有除标识触点外的其他含义。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [int32_t OH_ArkUI_PointerEvent_GetChangedPointerId(const ArkUI_UIInputEvent* event, uint32_t* pointerIndex)](#oh_arkui_pointerevent_getchangedpointerid) | 获取当前触摸事件触发的id。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getx) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getxbyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_gety) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getybyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetWindowX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getwindowx) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetWindowXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getwindowxbyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [float OH_ArkUI_PointerEvent_GetWindowY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getwindowy) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetWindowYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getwindowybyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [float OH_ArkUI_PointerEvent_GetDisplayX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getdisplayx) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getdisplayxbyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetDisplayY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getdisplayy) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getdisplayybyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getglobaldisplayx) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的X坐标。只能从pointer-likely事件中获取位置信息。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getglobaldisplayxbyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的X坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getglobaldisplayy) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的Y坐标。只能从pointer-likely事件中获取位置信息。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getglobaldisplayybyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的Y坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getpressure) | 从带有指向性的输入事件（如触摸事件）中获取触屏压力。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [float OH_ArkUI_PointerEvent_GetTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettiltx) | 从指向性输入事件（如触摸事件）中获取相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettilty) | 从指向性输入事件（如触摸事件）中获取相对XZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [int32_t OH_ArkUI_PointerEvent_GetRollAngle(const ArkUI_UIInputEvent* event, double* rollAngle)](#oh_arkui_pointerevent_getrollangle) | 获取触控笔绕Z轴旋转的角度。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettouchareawidth) | 从指向性输入事件（如触摸事件）中获取触屏区域的宽度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [float OH_ArkUI_PointerEvent_GetTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettouchareaheight) | 从指向性输入事件（如触摸事件）中获取触屏区域的高度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [int32_t OH_ArkUI_PointerEvent_GetInteractionHand(const ArkUI_UIInputEvent *event, ArkUI_InteractionHand *hand)](#oh_arkui_pointerevent_getinteractionhand) | 获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [int32_t OH_ArkUI_PointerEvent_GetInteractionHandByIndex(const ArkUI_UIInputEvent *event, int32_t pointerIndex, ArkUI_InteractionHand *hand)](#oh_arkui_pointerevent_getinteractionhandbyindex) | 获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [uint32_t OH_ArkUI_PointerEvent_GetHistorySize(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_gethistorysize) | 从指向性输入事件（如触摸事件）中获取历史事件数量。历史事件为此次事件与上一次事件之间发生的原始事件，仅适用于move事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [int64_t OH_ArkUI_PointerEvent_GetHistoryEventTime(const ArkUI_UIInputEvent* event, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryeventtime) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件发生的时间。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [uint32_t OH_ArkUI_PointerEvent_GetHistoryPointerCount(const ArkUI_UIInputEvent* event, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypointercount) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中多点触控的接触点数量。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [int32_t OH_ArkUI_PointerEvent_GetHistoryPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypointerid) | 从指向性输入事件（如触摸事件）的历史点中获取多点触控的接触点标识。返回事件发生时，事件触点的唯一标识符，用于区分同类输入设备的多点触控信息。其数值没有除标识触点外的其他含义。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [float OH_ArkUI_PointerEvent_GetHistoryX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryx) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [float OH_ArkUI_PointerEvent_GetHistoryY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryy) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [float OH_ArkUI_PointerEvent_GetHistoryWindowX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorywindowx) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [float OH_ArkUI_PointerEvent_GetHistoryWindowY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorywindowy) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [float OH_ArkUI_PointerEvent_GetHistoryDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorydisplayx) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [float OH_ArkUI_PointerEvent_GetHistoryDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorydisplayy) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryglobaldisplayx) | 从给定指针索引和历史记录索引的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件中相对于全局显示的特定触摸点的X坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryglobaldisplayy) | 从给定指针索引和历史记录索引的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件中相对于全局显示的特定触摸点的Y坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [float OH_ArkUI_PointerEvent_GetHistoryPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypressure) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏压力。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [float OH_ArkUI_PointerEvent_GetHistoryTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytiltx) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetHistoryTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytilty) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对XZ平面的角度，值的范围[-90, 90]，其中正值是向下倾斜。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytouchareawidth) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的宽度。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [float OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytouchareaheight) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的高度。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [double OH_ArkUI_AxisEvent_GetVerticalAxisValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getverticalaxisvalue) | 获取当前轴事件的垂直滚动轴的值。通常由鼠标滚轮，或用户在触控板上双指竖向滑动产生。当通过鼠标滚动触发时：1.上报的数值单位为角度，为单次滚动角度增量，非滚动总量；2.上报的数值已与用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)叠加运算；3.数值的正负代表方向，向前滚动鼠标滚轮时上报数值为正数，向后滚动鼠标滚轮时上报数值为负数；当通过触控板双指竖向滑动时：1.上报的数值单位为PX，为单次滚动增量，非滚动总量；2.上报的数值不受用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)影响；3.数值的正负代表方向，双指从上往下滑动时上报数值为正数，双指从下往上滑动时上报数值为负数；4.方向会受系统设置中"自然滚动"配置的影响。通常情况下，垂直滚动轴事件只能驱动竖向的滑动手势响应，但当鼠标指针下命中的可滑动手势里，如果可响应的方向都是一致的，那么垂直滚动轴事件可以驱动这些滑动手势得到响应，即使这些手势所定义的方向是横向的。 |
| [double OH_ArkUI_AxisEvent_GetHorizontalAxisValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_gethorizontalaxisvalue) | 获取当前轴事件的水平滚动轴的值，通过在触控板上双指横向滑动产生。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [double OH_ArkUI_AxisEvent_GetPinchAxisScaleValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getpinchaxisscalevalue) | 获取当前轴事件的捏合轴缩放的值。通过触控板双指缩放/捏合操作产生。上报的scale数值，为相对于初始状态时的当前scale值。初始状态为系统识别到用户通过触控板发生了捏合操作时的两指位置状态，此时的scale数值为1.0。在手指抬起前的本次捏合操作过程中，所上报的scale数值均将初始状态作为参考系，从初始状态往中心捏合，则上报的scale会从1.0逐步往0.0缩小；当从初始化状态往外扩大双指距离时，会从1.0逐步变大。                                                                                                                                                                                                                                                                                                                                                                   |
| [int32_t OH_ArkUI_AxisEvent_GetAxisAction(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getaxisaction) | 获取当前轴事件的操作类型。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [int32_t OH_ArkUI_PointerEvent_SetInterceptHitTestMode(const ArkUI_UIInputEvent* event, HitTestMode mode)](#oh_arkui_pointerevent_setintercepthittestmode) | 配置HitTest模式。仅适用于接收基础事件的场景，如使用NODE_ON_TOUCH接收touch事件场景。对于通过[OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent)接口从一个手势事件中获取到的ArkUI_UIInputEvent对象，无法使用该接口。                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_MouseEvent_GetMouseButton(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getmousebutton) | 获取鼠标事件的按键类型的值。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_MouseEvent_GetMouseAction(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getmouseaction) | 获取鼠标事件的鼠标动作类型的值。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [int32_t OH_ArkUI_PointerEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)](#oh_arkui_pointerevent_setstoppropagation) | 设置是否阻止事件冒泡。仅适用于接收基础事件的场景，如使用NODE_ON_TOUCH接收touch事件场景。对于通过 [OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent)接口从一个手势事件中获取到的ArkUI_UIInputEvent对象，无法使用该接口。                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [int32_t OH_ArkUI_UIInputEvent_GetDeviceId(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getdeviceid) | 获取当前按键的输入设备ID。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_UIInputEvent_GetPressedKeys(const ArkUI_UIInputEvent* event, int32_t* pressedKeyCodes, int32_t* length)](#oh_arkui_uiinputevent_getpressedkeys) | 获取所有按下的按键，当前只支持按键事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [double OH_ArkUI_FocusAxisEvent_GetAxisValue(const ArkUI_UIInputEvent* event, int32_t axis)](#oh_arkui_focusaxisevent_getaxisvalue) | 获取焦点轴事件的轴值。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [int32_t OH_ArkUI_FocusAxisEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)](#oh_arkui_focusaxisevent_setstoppropagation) | 设置是否阻止焦点轴事件冒泡。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_UIInputEvent_GetModifierKeyStates(const ArkUI_UIInputEvent* event, uint64_t* keys)](#oh_arkui_uiinputevent_getmodifierkeystates) | 获取UI输入事件的修饰键状态。该接口会通过keys传出当前事件发生时所有修饰键的状态，你可以通过与[ArkUI_ModifierKeyName](capi-ui-input-event-h.md#arkui_modifierkeyname)中定义的修饰键类型进行位计算操作获取哪些键处于按下状态。                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [int32_t OH_ArkUI_AxisEvent_SetPropagation(const ArkUI_UIInputEvent* event, bool propagation)](#oh_arkui_axisevent_setpropagation) | 设置是否使能轴事件冒泡。默认不会进行冒泡传递，仅发送给第一个可响应轴事件的控件。可在接收到轴事件时，主动使能冒泡传递，以便当前事件可以继续传递给响应链上的下一个可响应轴事件的祖先组件处理。不支持对从手势事件中获取到的轴事件进行设置。                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [int32_t OH_ArkUI_AxisEvent_GetScrollStep(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getscrollstep) | 获取滚动轴事件的滚动步长系数，适用于鼠标滚轮产生的轴事件。这个值可以告诉你用户所配置的滚动放大系数。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [float OH_ArkUI_UIInputEvent_GetEventTargetWidth(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetwidth) | 获取事件命中的组件的宽度。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_UIInputEvent_GetEventTargetHeight(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetheight) | 获取事件命中的组件的高度。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_UIInputEvent_GetEventTargetPositionX(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetpositionx) | 获取事件命中的组件的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_UIInputEvent_GetEventTargetPositionY(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetpositiony) | 获取事件命中的组件的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetglobalpositionx) | 获取事件命中的组件的全局X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtargetglobalpositiony) | 获取事件命中的组件的全局Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [int64_t OH_ArkUI_PointerEvent_GetPressedTimeByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getpressedtimebyindex) | 获取指定触点的按下时间。仅对触摸事件有效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [float OH_ArkUI_MouseEvent_GetRawDeltaX(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getrawdeltax) | 获取X轴相对于前一个上报的鼠标事件的鼠标指针位置的偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的X坐标的差。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [float OH_ArkUI_MouseEvent_GetRawDeltaY(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getrawdeltay) | 获取相对于前一个上报的鼠标事件的鼠标指针位置的Y轴偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的Y坐标的差。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [int32_t OH_ArkUI_MouseEvent_GetPressedButtons(const ArkUI_UIInputEvent* event, int32_t* pressedButtons, int32_t* length)](#oh_arkui_mouseevent_getpressedbuttons) | 从鼠标事件中获取按下的按钮。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_UIInputEvent_GetTargetDisplayId(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettargetdisplayid) | 获取发生UI输入事件的屏幕ID。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [bool OH_ArkUI_HoverEvent_IsHovered(const ArkUI_UIInputEvent* event)](#oh_arkui_hoverevent_ishovered) | 获取鼠标是否悬浮在当前组件上                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_PointerEvent_CreateClonedEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)](#oh_arkui_pointerevent_createclonedevent) | 基于原始事件指针创建克隆事件指针。仅对触摸事件有效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [int32_t OH_ArkUI_PointerEvent_DestroyClonedEvent(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_destroyclonedevent) | 销毁克隆事件指针。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPosition(const ArkUI_UIInputEvent* event, float x, float y)](#oh_arkui_pointerevent_setclonedeventlocalposition) | 设置指向性事件相对于当前组件左上角的X坐标和Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)](#oh_arkui_pointerevent_setclonedeventlocalpositionbyindex) | 设置指向性事件特有接触点相对于当前组件左上角的X坐标和Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventActionType(const ArkUI_UIInputEvent* event, int32_t actionType)](#oh_arkui_pointerevent_setclonedeventactiontype) | 设置当前带有指向性的克隆输入事件的事件类型。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId(const ArkUI_UIInputEvent* event, int32_t fingerId)](#oh_arkui_pointerevent_setclonedeventchangedfingerid) | 设置当前带有指向性的克隆输入事件的触摸点ID。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex(const ArkUI_UIInputEvent* event, int32_t fingerId, int32_t pointerIndex)](#oh_arkui_pointerevent_setclonedeventfingeridbyindex) | 设置带有指向性的克隆输入事件特定接触点的触摸点ID。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [int32_t OH_ArkUI_PointerEvent_PostClonedEvent(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_postclonedevent) | 转发克隆事件到特定节点。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_UIInputEvent_GetLatestStatus()](#oh_arkui_uiinputevent_getlateststatus) | 调用该方法获取最近一次UIInput相关方法的执行情况。通常情况下不需要使用该方法，仅在返回值结果不确定是否异常时使用。以下是一个使用示例（对于返回的float类型，0.0并不代表错误，因此可以进一步使用OH_ArkUI_UIInputEvent_GetLatestStatus方法来确认是否发生异常）。float x = OH_ArkUI_PointerEvent_GetX(event);if (ARKUI_ERROR_CODE_NO_ERROR != OH_Arkui_UIInputEvent_GetlatestStatus()) {// errorreturn;}系统将在每次执行UIInput相关函数时主动清空上一次函数调用的状态，以确保每次通过该接口获取的均为最近一次的状态。                                                                                                                                                                                                                              |

## 枚举类型说明

### ArkUI_UIInputEvent_Type

```
enum ArkUI_UIInputEvent_Type
```

**描述：**


UI输入事件类型定义。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_UIINPUTEVENT_TYPE_MOUSE = 3 | Mouse event. |
| ARKUI_UIINPUTEVENT_TYPE_KEY = 4 | 按键事件。<br>**起始版本：** 20 |

### anonymous1

```
enum anonymous1
```

**描述：**


定义输入事件的Action Code。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_TOUCH_EVENT_ACTION_CANCEL = 0 | 触摸取消。 |
| UI_TOUCH_EVENT_ACTION_DOWN = 1 | 触摸按下。 |
| UI_TOUCH_EVENT_ACTION_MOVE = 2 | 触摸移动。 |
| UI_TOUCH_EVENT_ACTION_UP = 3 | 触摸抬起。 |

### anonymous2

```
enum anonymous2
```

**描述：**


产生输入事件的工具类型定义。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN = 0 | 不支持的工具类型。 |
| UI_INPUT_EVENT_TOOL_TYPE_FINGER = 1 | 手指。 |
| UI_INPUT_EVENT_TOOL_TYPE_PEN = 2 | 笔。 |
| UI_INPUT_EVENT_TOOL_TYPE_MOUSE = 3 | 鼠标。 |
| UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD = 4 | 触控板。 |
| UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK = 5 | 操纵杆。 |

### anonymous3

```
enum anonymous3
```

**描述：**


产生输入事件的来源类型定义。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN = 0 | 不支持的来源类型。 |
| UI_INPUT_EVENT_SOURCE_TYPE_MOUSE = 1 | 鼠标。 |
| UI_INPUT_EVENT_SOURCE_TYPE_TOUCH_SCREEN = 2 | 触摸屏。 |

### HitTestMode

```
enum HitTestMode
```

**描述：**


定义触摸测试类型的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HTM_DEFAULT = 0 | 默认触摸测试效果。自身及子节点响应触摸测试，但阻塞兄弟节点的触摸测试，不影响祖先节点的触摸测试。 |
| HTM_BLOCK | 自身响应触摸测试，阻塞子节点、兄弟节点和祖先节点的触摸测试。 |
| HTM_TRANSPARENT | 自身和子节点都响应触摸测试，不会阻塞兄弟节点和祖先节点的触摸测试。 |
| HTM_NONE | 自身不响应触摸测试，不会阻塞子节点、兄弟节点和祖先节点的触摸测试。 |
| HTM_BLOCK_HIERARCHY | 自身和子节点响应触摸测试，阻止所有优先级较低的兄弟节点和父节点参与触摸测试。<br>**起始版本：** 20 |
| HTM_BLOCK_DESCENDANTS | 自身不响应触摸测试，并且所有的后代（孩子，孙子等）也不响应触摸测试，不会影响祖先节点的触摸测试。<br>**起始版本：** 20 |

### anonymous4

```
enum anonymous4
```

**描述：**


定义鼠标事件的Action Code。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_MOUSE_EVENT_ACTION_UNKNOWN = 0 | 无效行为。 |
| UI_MOUSE_EVENT_ACTION_PRESS = 1 | 鼠标按键按下。 |
| UI_MOUSE_EVENT_ACTION_RELEASE = 2 | 鼠标按键松开。 |
| UI_MOUSE_EVENT_ACTION_MOVE = 3 | 鼠标移动。 |
| UI_MOUSE_EVENT_ACTION_CANCEL = 13 | 鼠标按键被取消。<br>**起始版本：** 18 |

### anonymous5

```
enum anonymous5
```

**描述：**


定义鼠标事件的按键类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_MOUSE_EVENT_BUTTON_NONE = 0 | 无按键。 |
| UI_MOUSE_EVENT_BUTTON_LEFT = 1 | 鼠标左键。 |
| UI_MOUSE_EVENT_BUTTON_RIGHT = 2 | 鼠标右键。 |
| UI_MOUSE_EVENT_BUTTON_MIDDLE = 3 | 鼠标中键。 |
| UI_MOUSE_EVENT_BUTTON_BACK = 4 | 鼠标左侧后退键。 |
| UI_MOUSE_EVENT_BUTTON_FORWARD = 5 | 鼠标左侧前进键。 |

### ArkUI_ModifierKeyName

```
enum ArkUI_ModifierKeyName
```

**描述：**


定义modifier按键。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_MODIFIER_KEY_CTRL = 1 << 0 | Ctrl. |
| ARKUI_MODIFIER_KEY_SHIFT = 1 << 1 | Shift. |
| ARKUI_MODIFIER_KEY_ALT = 1 << 2 | Alt. |
| ARKUI_MODIFIER_KEY_FN = 1 << 3 | Fn（仅调试使用，通常不上报Fn状态）. |

### anonymous6

```
enum anonymous6
```

**描述：**


定义焦点轴事件的轴类型。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| UI_FOCUS_AXIS_EVENT_ABS_X = 0 | 游戏手柄X轴。 |
| UI_FOCUS_AXIS_EVENT_ABS_Y = 1 | 游戏手柄Y轴。 |
| UI_FOCUS_AXIS_EVENT_ABS_Z = 2 | 游戏手柄Z轴。 |
| UI_FOCUS_AXIS_EVENT_ABS_RZ = 3 | 游戏手柄RZ轴。 |
| UI_FOCUS_AXIS_EVENT_ABS_GAS = 4 | 游戏手柄GAS轴。 |
| UI_FOCUS_AXIS_EVENT_ABS_BRAKE = 5 | 游戏手柄BRAKE轴。 |
| UI_FOCUS_AXIS_EVENT_ABS_HAT0X = 6 | 游戏手柄HAT0X轴。 |
| UI_FOCUS_AXIS_EVENT_ABS_HAT0Y = 7 | 游戏手柄HAT0Y轴。 |

### ArkUI_InteractionHand

```
enum ArkUI_InteractionHand
```

**描述：**


定义触摸事件是左手还是右手。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_EVENT_HAND_NONE = 0 | 未知。 |
| ARKUI_EVENT_HAND_LEFT = 1 | 左手。 |
| ARKUI_EVENT_HAND_RIGHT = 2 | 右手。 |

### anonymous7

```
enum anonymous7
```

**描述：**


定义轴事件的操作类型。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| UI_AXIS_EVENT_ACTION_NONE = 0 | 轴事件异常。 |
| UI_AXIS_EVENT_ACTION_BEGIN = 1 | 轴事件开始。 |
| UI_AXIS_EVENT_ACTION_UPDATE = 2 | 轴事件更新。 |
| UI_AXIS_EVENT_ACTION_END = 3 | 轴事件结束。 |
| UI_AXIS_EVENT_ACTION_CANCEL = 4 | 轴事件取消。 |


## 函数说明

### OH_ArkUI_UIInputEvent_GetType()

```
int32_t OH_ArkUI_UIInputEvent_GetType(const ArkUI_UIInputEvent* event)
```

**描述：**


获取UI输入事件的类型。在访问一个ArkUI_UIInputEvent指针对象之前，推荐使用该方法判断该输入事件的类型，该接口会返回[ArkUI_UIInputEvent_Type](capi-ui-input-event-h.md#arkui_uiinputevent_type)枚举中的一种。比如，当事件是一个触控类型时，由于触控类型是指向性事件，那么使用OH_ArkUI_UIInputEvent_GetXXX及OH_ArkUI_PointerEvent_GetXXX系列接口，均可以正常访问；而如果使用OH_ArkUI_KeyEvent_GetXXX相关接口去访问它，则会有无法预期的结果。对于还未支持的事件类型，接口返回默认值0。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回当前UI输入事件的类型，如果参数异常则返回0。 |

### OH_ArkUI_UIInputEvent_GetAction()

```
int32_t OH_ArkUI_UIInputEvent_GetAction(const ArkUI_UIInputEvent* event)
```

**描述：**


获取输入事件的action类型。action类型为基础事件在不同阶段的类型定义，通常代表了事件的特点，并表征事件的开始与结束，如touch down, touch up。触控事件的action类型为[UI_TOUCH_EVENT_ACTION_XXX](#anonymous1)，鼠标事件的action类型为[UI_MOUSE_EVENT_ACTION_XXX](#anonymous4)。轴事件的action类型获取请使用[OH_ArkUI_AxisEvent_GetAxisAction](#oh_arkui_axisevent_getaxisaction)，返回值类型为[UI_AXIS_EVENT_ACTION_XXX](#anonymous7)，按键事件的action类型获取请使用[OH_ArkUI_KeyEvent_GetType](./capi-native-key-event-h.md#oh_arkui_keyevent_gettype)接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回当前UI输入事件的操作类型，如果参数异常则返回0。 |

### OH_ArkUI_UIInputEvent_GetSourceType()

```
int32_t OH_ArkUI_UIInputEvent_GetSourceType(const ArkUI_UIInputEvent* event)
```

**描述：**


获取UI输入事件的触发源类型。输入源为产生输入事件的真实物理设备，如触摸屏，鼠标等，由UI_INPUT_EVENT_SOURCE_TYPE_XXX定义，而输入工具为操作输入源设备来产生事件的工具，如手指、触控笔。在某些情况下两者可能容易发生混淆，比如当用户在操作鼠标时，鼠标既是输入源，也是输入工具。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回产生当前UI输入事件的来源类型。 |

### OH_ArkUI_UIInputEvent_GetToolType()

```
int32_t OH_ArkUI_UIInputEvent_GetToolType(const ArkUI_UIInputEvent* event)
```

**描述：**


获取UI输入事件的工具类型。输入工具为操作输入源设备来产生事件的操作方，如手指、触控笔，他们自身不真实产生事件，但可以驱动输入源设备不断产生事件。返回的类型由UI_INPUT_EVENT_TOOL_TYPE_XXX枚举值定义。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回产生当前UI输入事件的工具类型。 |

### OH_ArkUI_UIInputEvent_GetEventTime()

```
int64_t OH_ArkUI_UIInputEvent_GetEventTime(const ArkUI_UIInputEvent* event)
```

**描述：**


获取UI输入事件发生的时间。单位为ns。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回UI输入事件发生的时间，如果参数异常则返回0。 |

### OH_ArkUI_PointerEvent_GetPointerCount()

```
uint32_t OH_ArkUI_PointerEvent_GetPointerCount(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点数量。指向性事件一般是附带有事件发生位置信息的事件，如触摸事件，用户操作时，可以感知事件在什么位置发生。而非指向性事件，如按键事件，一般没有位置信息，没有触点的说法，所以该接口对按键事件无效。对于触摸事件，该接口多用于处理多指触控，判断用户有几根手指在操作当前控件。而对于鼠标和轴事件，可认为触点只有1个，该接口永远返回1。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回当前带有指向性的输入事件的接触点数量。 |

### OH_ArkUI_PointerEvent_GetPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。返回事件发生时，事件触点的唯一标识符，用于区分同类输入设备的多点触控信息。其数值没有除标识触点外的其他含义。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回特定接触点标识。 |

### OH_ArkUI_PointerEvent_GetChangedPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetChangedPointerId(const ArkUI_UIInputEvent* event, uint32_t* pointerIndex)
```

**描述：**


获取触发当前事件的对应的手指id。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t* pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_PointerEvent_GetX()

```
float OH_ArkUI_PointerEvent_GetX(const ArkUI_UIInputEvent* event)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前组件左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetXByIndex()

```
float OH_ArkUI_PointerEvent_GetXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，返回默认值0.0f。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前组件左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetY()

```
float OH_ArkUI_PointerEvent_GetY(const ArkUI_UIInputEvent* event)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前组件左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetYByIndex()

```
float OH_ArkUI_PointerEvent_GetYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，返回默认值0.0f。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前组件左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetWindowX()

```
float OH_ArkUI_PointerEvent_GetWindowX(const ArkUI_UIInputEvent* event)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前应用窗口左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetWindowXByIndex()

```
float OH_ArkUI_PointerEvent_GetWindowXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前应用窗口左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetWindowY()

```
float OH_ArkUI_PointerEvent_GetWindowY(const ArkUI_UIInputEvent* event)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前应用窗口左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetWindowYByIndex()

```
float OH_ArkUI_PointerEvent_GetWindowYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前应用窗口左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetDisplayX()

```
float OH_ArkUI_PointerEvent_GetDisplayX(const ArkUI_UIInputEvent* event)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前屏幕左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetDisplayXByIndex()

```
float OH_ArkUI_PointerEvent_GetDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前屏幕左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetDisplayY()

```
float OH_ArkUI_PointerEvent_GetDisplayY(const ArkUI_UIInputEvent* event)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前屏幕左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetDisplayYByIndex()

```
float OH_ArkUI_PointerEvent_GetDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前屏幕左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetGlobalDisplayX()

```
float OH_ArkUI_PointerEvent_GetGlobalDisplayX(const ArkUI_UIInputEvent* event)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的X坐标。只能从pointer-likely事件中获取位置信息。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回相对于全局显示的X坐标，单位为px。如果发生任何参数错误，例如传递的一个事件没有位置信息，则返回0。 |

### OH_ArkUI_PointerEvent_GetGlobalDisplayXByIndex()

```
float OH_ArkUI_PointerEvent_GetGlobalDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的X坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。

**起始版本：** 20


**参数：**

| 参数项 | 描述                                                                                                                  |
| -- |---------------------------------------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。                                                                                                    |
| uint32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。有效值范围[0, [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) - 1] |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回相对于全局显示的X坐标，单位为px。如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetGlobalDisplayY()

```
float OH_ArkUI_PointerEvent_GetGlobalDisplayY(const ArkUI_UIInputEvent* event)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的Y坐标。只能从pointer-likely事件中获取位置信息。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回相对于全局显示的Y坐标，单位为px。如果发生任何参数错误，例如传递的一个事件没有位置信息，则返回0。 |

### OH_ArkUI_PointerEvent_GetGlobalDisplayYByIndex()

```
float OH_ArkUI_PointerEvent_GetGlobalDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的Y坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。

**起始版本：** 20


**参数：**

| 参数项 | 描述                                                                                  |
| -- |-------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。                                                                    |
| uint32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。有效值范围[0, [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) - 1] |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回相对于全局显示的Y坐标，单位为px。如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetPressure()

```
float OH_ArkUI_PointerEvent_GetPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件）中获取触屏压力。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件产生的触屏压力，如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetTiltX()

```
float OH_ArkUI_PointerEvent_GetTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件中相对YZ平面的角度。 |

### OH_ArkUI_PointerEvent_GetTiltY()

```
float OH_ArkUI_PointerEvent_GetTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取相对XZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件中相对XZ平面的角度。 |

### OH_ArkUI_PointerEvent_GetRollAngle()

```
int32_t OH_ArkUI_PointerEvent_GetRollAngle(const ArkUI_UIInputEvent* event, double* rollAngle)
```

**描述：**


获取触控笔绕Z轴旋转的角度。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 指向当前UI输入事件的指针。 |
| double* rollAngle | 触控笔绕Z轴旋转的角度，单位为deg。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_PointerEvent_GetTouchAreaWidth()

```
float OH_ArkUI_PointerEvent_GetTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取触屏区域的宽度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件中触屏区域的宽度，单位为px。 |

### OH_ArkUI_PointerEvent_GetTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取触屏区域的高度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件中触屏区域的高度，单位为px。 |

### OH_ArkUI_PointerEvent_GetInteractionHand()

```
int32_t OH_ArkUI_PointerEvent_GetInteractionHand(const ArkUI_UIInputEvent *event, ArkUI_InteractionHand *hand)
```

**描述：**


获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md) *event | 表示指向当前UI输入事件的指针。 |
| [ArkUI_InteractionHand](capi-ui-input-event-h.md#arkui_interactionhand) *hand | 表示触摸点是左手还是右手。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果。<br> 如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br> 如果发生参数异常，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_GetInteractionHandByIndex()

```
int32_t OH_ArkUI_PointerEvent_GetInteractionHandByIndex(const ArkUI_UIInputEvent *event, int32_t pointerIndex, ArkUI_InteractionHand *hand)
```

**描述：**


获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md) *event | 表示指向当前UI输入事件的指针。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |
| [ArkUI_InteractionHand](capi-ui-input-event-h.md#arkui_interactionhand) *hand | 表示触摸点是左手还是右手。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果。<br> 如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br> 如果发生参数异常，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_GetHistorySize()

```
uint32_t OH_ArkUI_PointerEvent_GetHistorySize(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件）中获取历史事件数量。历史事件为此次事件与上一次事件之间发生的原始事件，仅适用于move事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回当前历史事件数量。 |

### OH_ArkUI_PointerEvent_GetHistoryEventTime()

```
int64_t OH_ArkUI_PointerEvent_GetHistoryEventTime(const ArkUI_UIInputEvent* event, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件发生的时间。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回UI输入事件发生的时间，单位为ns。如果参数异常则返回0。 |

### OH_ArkUI_PointerEvent_GetHistoryPointerCount()

```
uint32_t OH_ArkUI_PointerEvent_GetHistoryPointerCount(const ArkUI_UIInputEvent* event, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中多点触控的接触点数量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 特定历史事件中多点触控的接触点数量。 |

### OH_ArkUI_PointerEvent_GetHistoryPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetHistoryPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件（如触摸事件）的历史点中获取多点触控的接触点标识。返回事件发生时，事件触点的唯一标识符，用于区分同类输入设备的多点触控信息。其数值没有除标识触点外的其他含义。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回特定历史事件中的特定接触点标识。 |

### OH_ArkUI_PointerEvent_GetHistoryX()

```
float OH_ArkUI_PointerEvent_GetHistoryX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前组件左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryY()

```
float OH_ArkUI_PointerEvent_GetHistoryY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前组件左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryWindowX()

```
float OH_ArkUI_PointerEvent_GetHistoryWindowX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前应用窗口左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryWindowY()

```
float OH_ArkUI_PointerEvent_GetHistoryWindowY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前应用窗口左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryDisplayX()

```
float OH_ArkUI_PointerEvent_GetHistoryDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前屏幕左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryDisplayY()

```
float OH_ArkUI_PointerEvent_GetHistoryDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件相对于当前屏幕左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX()

```
float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从给定指针索引和历史记录索引的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件中相对于全局显示的特定触摸点的X坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。

**起始版本：** 20


**参数：**

| 参数项 | 描述                                                                                                                   |
| -- |----------------------------------------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。                                                                                                     |
| uint32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。有效值范围[0,  [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) - 1] |
| uint32_t historyIndex | 表示要返回的历史值，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回相对于全局显示的X坐标，单位为px。如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY()

```
float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从给定指针索引和历史记录索引的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件中相对于全局显示的特定触摸点的Y坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。

**起始版本：** 20


**参数：**

| 参数项 | 描述                                                                                                                   |
| -- |----------------------------------------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。                                                                                                     |
| uint32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。有效值范围[0, [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) - 1]  |
| uint32_t historyIndex | 表示要返回的历史值，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | float 返回相对于全局显示的Y坐标，如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryPressure()

```
float OH_ArkUI_PointerEvent_GetHistoryPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏压力。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件产生的触屏压力，如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryTiltX()

```
float OH_ArkUI_PointerEvent_GetHistoryTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对YZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向右倾斜。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件中相对YZ平面的角度。 |

### OH_ArkUI_PointerEvent_GetHistoryTiltY()

```
float OH_ArkUI_PointerEvent_GetHistoryTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对XZ平面的角度，值的范围[-90, 90]，单位为deg，其中正值是向下倾斜。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件中相对XZ平面的角度。 |

### OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth()

```
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的宽度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件中触屏区域的宽度，单位为px。 |

### OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的高度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前带有指向性的输入事件中触屏区域的高度，单位为px。 |

### OH_ArkUI_AxisEvent_GetVerticalAxisValue()

```
double OH_ArkUI_AxisEvent_GetVerticalAxisValue(const ArkUI_UIInputEvent* event)
```

**描述：**


获取当前轴事件的垂直滚动轴的值。通常由鼠标滚轮，或用户在触控板上双指竖向滑动产生。当通过鼠标滚动触发时：1.上报的数值单位为角度，为单次滚动角度增量，非滚动总量；2.上报的数值已与用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)叠加运算；3.数值的正负代表方向，向前滚动鼠标滚轮时上报数值为负数，向后滚动鼠标滚轮时上报数值为正数；当通过触控板双指竖向滑动时：1.上报的数值单位为PX，为单次滚动增量，非滚动总量；2.上报的数值不受用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)影响；3.数值的正负代表方向，双指从上往下滑动时上报数值为负数，双指从下往上滑动时上报数值为正数；4.方向会受系统设置中"自然滚动"配置的影响。通常情况下，垂直滚动轴事件只能驱动竖向的滑动手势响应，但当鼠标指针下命中的可滑动手势里，如果可响应的方向都是一致的，那么垂直滚动轴事件可以驱动这些滑动手势得到响应，即使这些手势所定义的方向是横向的。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回当前轴事件的垂直滚动轴的值，如果参数异常则返回0.0。 |

### OH_ArkUI_AxisEvent_GetHorizontalAxisValue()

```
double OH_ArkUI_AxisEvent_GetHorizontalAxisValue(const ArkUI_UIInputEvent* event)
```

**描述：**


获取当前轴事件的水平滚动轴的值，通过在触控板上双指横向滑动产生。当通过触控板双指竖向滑动时：1.上报的数值单位为PX，为单次滚动增量，非滚动总量；2.上报的数值不受用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)影响；3.数值的正负代表方向，双指从左往右滑动时上报数值为负数，双指从右往左滑动时上报数值为正数；4.方向会受系统设置中"自然滚动"配置的影响。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回当前轴事件的水平滚动轴的值，如果参数异常则返回0.0。 |

### OH_ArkUI_AxisEvent_GetPinchAxisScaleValue()

```
double OH_ArkUI_AxisEvent_GetPinchAxisScaleValue(const ArkUI_UIInputEvent* event)
```

**描述：**


获取当前轴事件的捏合轴缩放的值。通过触控板双指缩放/捏合操作产生。上报的scale数值，为相对于初始状态时的当前scale值。初始状态为系统识别到用户通过触控板发生了捏合操作时的两指位置状态，此时的scale数值为1.0。在手指抬起前的本次捏合操作过程中，所上报的scale数值均将初始状态作为参考系，从初始状态往中心捏合，则上报的scale会从1.0逐步往0.0缩小；当从初始化状态往外扩大双指距离时，会从1.0逐步变大。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回当前轴事件的捏合轴缩放的值，如果参数异常则返回0.0。 |

### OH_ArkUI_AxisEvent_GetAxisAction()

```
int32_t OH_ArkUI_AxisEvent_GetAxisAction(const ArkUI_UIInputEvent* event)
```

**描述：**


获取当前轴事件的操作类型。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回当前轴事件的操作类型。 |

### OH_ArkUI_PointerEvent_SetInterceptHitTestMode()

```
int32_t OH_ArkUI_PointerEvent_SetInterceptHitTestMode(const ArkUI_UIInputEvent* event, HitTestMode mode)
```

**描述：**


配置HitTest模式。仅适用于接收基础事件的场景，如使用NODE_ON_TOUCH接收touch事件场景。对于通过[OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent)接口从一个手势事件中获取到的ArkUI_UIInputEvent对象，无法使用该接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| [HitTestMode](capi-ui-input-event-h.md#hittestmode) mode | 指定HitTest模式，参数类型[HitTestMode](capi-ui-input-event-h.md#hittestmode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回执行的状态代码。 |

### OH_ArkUI_MouseEvent_GetMouseButton()

```
int32_t OH_ArkUI_MouseEvent_GetMouseButton(const ArkUI_UIInputEvent* event)
```

**描述：**


获取鼠标事件的按键类型的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回鼠标按键类型，1为左键，2为右键，3为中键，4为后退键，5为前进键。 |

### OH_ArkUI_MouseEvent_GetMouseAction()

```
int32_t OH_ArkUI_MouseEvent_GetMouseAction(const ArkUI_UIInputEvent* event)
```

**描述：**


获取鼠标事件的鼠标动作类型的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回鼠标动作类型，1表示按键按下，2表示按键松开，3表示鼠标移动。 |

### OH_ArkUI_PointerEvent_SetStopPropagation()

```
int32_t OH_ArkUI_PointerEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)
```

**描述：**


设置是否阻止事件冒泡。仅适用于接收基础事件的场景，如使用NODE_ON_TOUCH接收touch事件场景。对于通过 [OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent)接口从一个手势事件中获取到的ArkUI_UIInputEvent对象，无法使用该接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| bool stopPropagation | 表示是否阻止事件冒泡。true表示阻止事件冒泡，false表示不阻止事件冒泡。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回执行的状态代码。返回0表示设置成功，如果返回401，表示返回失败，可能的原因是参数异常，例如event是一个空指针。 |

### OH_ArkUI_UIInputEvent_GetDeviceId()

```
int32_t OH_ArkUI_UIInputEvent_GetDeviceId(const ArkUI_UIInputEvent* event)
```

**描述：**


获取当前按键的输入设备ID。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 当前按键的输入设备ID。 |

### OH_ArkUI_UIInputEvent_GetPressedKeys()

```
int32_t OH_ArkUI_UIInputEvent_GetPressedKeys(const ArkUI_UIInputEvent* event, int32_t* pressedKeyCodes, int32_t* length)
```

**描述：**


获取所有按下的按键，当前只支持按键事件。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t* pressedKeyCodes | 输出参数，表示所有按下键的数组，指向的内存空间需要调用者申请。 |
| int32_t* length | 作为输入参数表示传入的pressedKeyCodes数组长度，作为输出参数表示实际按下按键的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH](capi-native-type-h.md#arkui_errorcode) 内存分配不足。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_FocusAxisEvent_GetAxisValue()

```
double OH_ArkUI_FocusAxisEvent_GetAxisValue(const ArkUI_UIInputEvent* event, int32_t axis)
```

**描述：**


获取焦点轴事件的轴值。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t axis | 焦点轴事件的轴类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 焦点轴事件的轴值，如果参数异常则返回0.0。 |

### OH_ArkUI_FocusAxisEvent_SetStopPropagation()

```
int32_t OH_ArkUI_FocusAxisEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)
```

**描述：**


设置是否阻止焦点轴事件冒泡。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| bool stopPropagation | 表示是否阻止事件冒泡。true表示阻止事件冒泡，false表示不阻止事件冒泡。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数异常。 |

### OH_ArkUI_UIInputEvent_GetModifierKeyStates()

```
int32_t OH_ArkUI_UIInputEvent_GetModifierKeyStates(const ArkUI_UIInputEvent* event, uint64_t* keys)
```

**描述：**


获取UI输入事件的修饰键状态。该接口会通过keys传出当前事件发生时所有修饰键的状态，你可以通过与[ArkUI_ModifierKeyName](capi-ui-input-event-h.md#arkui_modifierkeyname)中定义的修饰键类型进行位计算操作获取哪些键处于按下状态。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| uint64_t* keys | 返回当前处于按下状态的modifier key组合，应用可通过位运算进行判断。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AxisEvent_SetPropagation()

```
int32_t OH_ArkUI_AxisEvent_SetPropagation(const ArkUI_UIInputEvent* event, bool propagation)
```

**描述：**


设置是否使能轴事件冒泡。默认不会进行冒泡传递，仅发送给第一个可响应轴事件的控件。可在接收到轴事件时，主动使能冒泡传递，以便当前事件可以继续传递给响应链上的下一个可响应轴事件的祖先组件处理。不支持对从手势事件中获取到的轴事件进行设置。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前 UI 输入事件的指针。 |
| bool propagation | 表示是否激活事件冒泡。true表示激活事件冒泡，false表示不激活事件冒泡。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 参数异常。 |

### OH_ArkUI_AxisEvent_GetScrollStep()

```
int32_t OH_ArkUI_AxisEvent_GetScrollStep(const ArkUI_UIInputEvent* event)
```

**描述：**


获取滚动轴事件的滚动步长系数，适用于鼠标滚轮产生的轴事件。这个值可以告诉你用户所配置的滚动放大系数。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 指向 ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回鼠标滚轮轴滚动步长配置。 |

### OH_ArkUI_UIInputEvent_GetEventTargetWidth()

```
float OH_ArkUI_UIInputEvent_GetEventTargetWidth(const ArkUI_UIInputEvent* event)
```

**描述：**


获取事件命中的组件的宽度。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 指向ArkUI_UIInputEvent对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回事件命中的组件的宽度；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetHeight()

```
float OH_ArkUI_UIInputEvent_GetEventTargetHeight(const ArkUI_UIInputEvent* event)
```

**描述：**


获取事件命中的组件的高度。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 指向ArkUI_UIInputEvent对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回事件命中的组件的高度；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetPositionX()

```
float OH_ArkUI_UIInputEvent_GetEventTargetPositionX(const ArkUI_UIInputEvent* event)
```

**描述：**


获取事件命中的组件的X坐标。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 指向ArkUI_UIInputEvent对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回事件命中的组件的X坐标；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetPositionY()

```
float OH_ArkUI_UIInputEvent_GetEventTargetPositionY(const ArkUI_UIInputEvent* event)
```

**描述：**


获取事件命中的组件的Y坐标。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 指向ArkUI_UIInputEvent对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回事件命中的组件的Y坐标；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX()

```
float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX(const ArkUI_UIInputEvent* event)
```

**描述：**


获取事件命中的组件的全局X坐标。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 指向ArkUI_UIInputEvent对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回事件命中的组件的全局X坐标；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY()

```
float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY(const ArkUI_UIInputEvent* event)
```

**描述：**


获取事件命中的组件的全局Y坐标。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 指向ArkUI_UIInputEvent对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回事件命中的组件的全局Y坐标；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_PointerEvent_GetPressedTimeByIndex()

```
int64_t OH_ArkUI_PointerEvent_GetPressedTimeByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


获取指定触点的按下时间。仅对触摸事件有效。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| uint32_t pointerIndex | 指示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回特定触摸点的按下时间，单位为ns；如果发生任何参数错误，则返回0。 |

### OH_ArkUI_MouseEvent_GetRawDeltaX()

```
float OH_ArkUI_MouseEvent_GetRawDeltaX(const ArkUI_UIInputEvent* event)
```

**描述：**


获取X轴相对于前一个上报的鼠标事件的鼠标指针位置的偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的X坐标的差。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回相对于前一个上报的鼠标事件的鼠标指针位置的X轴偏移量，单位为px；如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_MouseEvent_GetRawDeltaY()

```
float OH_ArkUI_MouseEvent_GetRawDeltaY(const ArkUI_UIInputEvent* event)
```

**描述：**


获取相对于前一个上报的鼠标事件的鼠标指针位置的Y轴偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的Y坐标的差。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回相对于前一个上报的鼠标事件的鼠标指针位置的Y轴偏移量，单位为px；如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_MouseEvent_GetPressedButtons()

```
int32_t OH_ArkUI_MouseEvent_GetPressedButtons(const ArkUI_UIInputEvent* event, int32_t* pressedButtons, int32_t* length)
```

**描述：**


从鼠标事件中获取按下的按钮。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t* pressedButtons | 指示按下按钮的列表。需要先创建一个int数组，用来储存按下的按钮。 |
| int32_t* length | 指示列表数组的总长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果给定的缓冲区不够，则返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode)。 |

### OH_ArkUI_UIInputEvent_GetTargetDisplayId()

```
int32_t OH_ArkUI_UIInputEvent_GetTargetDisplayId(const ArkUI_UIInputEvent* event)
```

**描述：**


获取发生UI输入事件的屏幕ID。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回屏幕ID；如果发生任何参数错误，则返回0。 |

### OH_ArkUI_HoverEvent_IsHovered()

```
bool OH_ArkUI_HoverEvent_IsHovered(const ArkUI_UIInputEvent* event)
```

**描述：**


获取鼠标是否悬浮在当前组件上

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果鼠标悬浮在当前组件上则返回true。<br>        如果鼠标没有悬浮在当前组件上，返回false |

### OH_ArkUI_PointerEvent_CreateClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_CreateClonedEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)
```

**描述：**


基于原始事件指针创建克隆事件指针。仅对触摸事件有效。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)** clonedEvent | ArkUI_UIInputEvent克隆事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果事件指针创建失败，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_DestroyClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_DestroyClonedEvent(const ArkUI_UIInputEvent* event)
```

**描述：**


销毁克隆事件指针。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT。 |

### OH_ArkUI_PointerEvent_SetClonedEventLocalPosition()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPosition(const ArkUI_UIInputEvent* event, float x, float y)
```

**描述：**


设置指向性事件相对于当前组件左上角的X坐标和Y坐标。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 当前带有指向性的输入事件相对于当前组件左上角的X坐标，单位为px。 |
| float y | 当前带有指向性的输入事件相对于当前组件左上角的Y坐标，单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT。 |

### OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)
```

**描述：**


设置指向性事件特有接触点相对于当前组件左上角的X坐标和Y坐标。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 当前带有指向性的输入事件相对于当前组件左上角的X坐标，单位为px。 |
| float y | 当前带有指向性的输入事件相对于当前组件左上角的Y坐标，单位为px。 |
| int32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT。 |

### OH_ArkUI_PointerEvent_SetClonedEventActionType()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventActionType(const ArkUI_UIInputEvent* event, int32_t actionType)
```

**描述：**


设置当前带有指向性的克隆输入事件的事件类型。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t actionType | ArkUI_UIInputEvent克隆事件类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT。 |

### OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId(const ArkUI_UIInputEvent* event, int32_t fingerId)
```

**描述：**


设置当前带有指向性的克隆输入事件的触摸点ID。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t fingerId | 触发当前事件指针的触摸点ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT。 |

### OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex(const ArkUI_UIInputEvent* event, int32_t fingerId, int32_t pointerIndex)
```

**描述：**


设置带有指向性的克隆输入事件特定接触点的触摸点ID。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t fingerId | 指向性的输入事件特定接触点的触摸点ID。 |
| int32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT。 |

### OH_ArkUI_PointerEvent_PostClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_PostClonedEvent(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event)
```

**描述：**


转发克隆事件到特定节点。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 目标节点。 |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT。<br>         如果组件状态异常，则返回[ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL](capi-native-type-h.md#arkui_errorcode)。<br>         如果未命中可响应事件的组件，则返回[ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT](capi-native-type-h.md#arkui_errorcode)。 |

### OH_ArkUI_UIInputEvent_GetLatestStatus()

```
ArkUI_ErrorCode OH_ArkUI_UIInputEvent_GetLatestStatus()
```

**描述：**


调用该方法获取最近一次UIInput相关方法的执行情况。通常情况下不需要使用该方法，仅在返回值结果不确定是否异常时使用。以下是一个使用示例（对于返回的float类型，0.0并不代表错误，因此可以进一步使用OH_ArkUI_UIInputEvent_GetLatestStatus方法来确认是否发生异常）。float x = OH_ArkUI_PointerEvent_GetX(event);if (ARKUI_ERROR_CODE_NO_ERROR != OH_Arkui_UIInputEvent_GetlatestStatus()) {// errorreturn;}系统将在每次执行UIInput相关函数时主动清空上一次函数调用的状态，以确保每次通过该接口获取的均为最近一次的状态。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | 返回最近一次调用UIInput方法产生的结果代码。 |


