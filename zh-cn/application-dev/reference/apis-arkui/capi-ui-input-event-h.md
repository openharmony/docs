# ui_input_event.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供ArkUI在Native侧的输入事件定义，支持触摸、鼠标、轴、按键等事件类型及事件属性获取、事件冒泡控制、克隆事件处理等能力，适用于Native组件中识别和处理用户输入交互的场景，帮助开发者获取事件来源、位置、状态等信息并实现精细化交互控制。

**引用文件：** <arkui/ui_input_event.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_EventModule](capi-arkui-eventmodule.md)

**相关示例：** <!--RP1-->[NdkInputEvent](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NdkInputEvent)<!--RP1End-->、<!--RP2-->[CoastingAxisEventNDK](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/CoastingAxisEventNDK)<!--RP2End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md) | ArkUI_UIInputEvent | ArkUI_UIInputEvent用于表示ArkUI中的UI输入事件，供ArkUI_EventModule模块中的事件接口传递和处理输入事件信息，适用于需要识别、分发或响应用户输入事件的场景。 |
| [ArkUI_CoastingAxisEvent](capi-arkui-nativemodule-arkui-coastingaxisevent.md) | ArkUI_CoastingAxisEvent | 定义惯性滚动轴事件。 当用户在触控板上用双指滑动时，系统会根据手指抬起时的速度，按照一定的衰减曲线构造滑动事件。可以监听此类事件，以便在常规轴事件之后立即处理惯性滚动效果。 仅当用户在触控板上双指抛滑，且指针位置下存在通过[registerNodeEvent](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)注册了[NODE_ON_COASTING_AXIS_EVENT](capi-native-node-h.md#arkui_nodeeventtype)事件的组件时，才能接收到此事件。不再需要监听此事件时，应通过[unregisterNodeEvent](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeevent)注销事件监听，避免回调持续触发。 |
| [ArkUI_TouchTestInfo](capi-arkui-nativemodule-arkui-touchtestinfo.md) | ArkUI_TouchTestInfo | 定义触摸测试信息，用于在命中测试过程中获取触摸测试策略、参与命中测试的子组件ID及触摸测试信息项列表，适用于需要在子组件触摸事件中获取命中测试详细信息以自定义命中测试逻辑、优化触摸事件分发与响应的场景。 当用户通过[registerNodeEvent](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)注册了[NODE_ON_CHILD_TOUCH_TEST](capi-native-node-h.md#arkui_nodeeventtype)事件时，才能接收到此事件。触摸测试信息包含触摸测试策略、命中测试过程中需要参与命中测试的子组件ID和触摸测试信息项的列表。 |
| [ArkUI_TouchTestInfoItem](capi-arkui-nativemodule-arkui-touchtestinfoitem.md) | ArkUI_TouchTestInfoItem | 定义触摸测试信息项。触摸测试信息项包含触摸测试中子组件的信息，适用于触摸测试过程中获取和识别子组件相关信息的场景，可以通过[OH_ArkUI_TouchTestInfoItem_Get](./capi-ui-input-event-h.md#oh_arkui_touchtestinfoitem_getx)XXX系列接口获取子组件信息，帮助开发者处理触摸测试结果。 |
| [ArkUI_TouchTestInfoItem*](capi-arkui-nativemodule-arkui-touchtestinfoitemhandle.md) | ArkUI_TouchTestInfoItemHandle | 定义触摸测试信息项句柄，用于表示触摸测试流程中的触摸测试信息项；触摸测试接口请参见[ui_input_event.h](capi-ui-input-event-h.md)。 |
| [ArkUI_TouchTestInfoItemHandle*](capi-arkui-nativemodule-arkui-touchtestinfoitemhandlearray.md) | ArkUI_TouchTestInfoItemArray | 定义触摸测试信息项句柄数组，用于表示多个触摸测试信息项句柄。在触摸事件分发与测试过程中，可通过此数组类型统一管理和访问多个触摸测试结果，适用于需要同时处理多个触点测试信息的场景。 |

### 枚举

| 名称                                                  | typedef关键字 | 描述 |
|-----------------------------------------------------| -- | -- |
| [ArkUI_UIInputEvent_Type](#arkui_uiinputevent_type) | ArkUI_UIInputEvent_Type | UI输入事件类型定义。 |
| [anonymous1](#anonymous1)                       | - | 定义输入事件的行为类型。 |
| [anonymous2](#anonymous2)                       | - | 产生输入事件的工具类型定义。 |
| [anonymous3](#anonymous3)                       | - | 产生输入事件的来源类型定义。 |
| [HitTestMode](#hittestmode)                         | HitTestMode | 定义触摸测试类型的枚举值。 |
| [anonymous4](#anonymous4)                       | - | 定义鼠标事件的行为类型。 |
| [anonymous5](#anonymous5)                       | - | 定义鼠标事件的按键类型。 |
| [ArkUI_ModifierKeyName](#arkui_modifierkeyname)     | ArkUI_ModifierKeyName | 定义修饰键。 |
| [anonymous6](#anonymous6)                       | - | 定义焦点轴事件的轴类型。 |
| [ArkUI_InteractionHand](#arkui_interactionhand)     | ArkUI_InteractionHand | 定义触摸事件是左手还是右手。 |
| [anonymous7](#anonymous7)                       | - | 定义轴事件的操作类型。 |
| [anonymous8](#anonymous8)                       | - | 定义轴事件的轴类型。 |
| [ArkUI_CoastingAxisEventPhase](#arkui_coastingaxiseventphase) | ArkUI_CoastingAxisEventPhase | 定义惯性滚动轴事件的阶段。 |
| [ArkUI_CompetitionStrategy](#arkui_competitionstrategy) | ArkUI_CompetitionStrategy | 事件的注入方和被注入方间手势识别结果是否为竞争场景的策略。该策略决定了事件的注入方如何与被注入方的手势处理逻辑交互，非竞争场景会同时触发手势，竞争场景只触发其中一个。 |
| [ArkUI_TouchTestStrategy](#arkui_touchteststrategy) | ArkUI_TouchTestStrategy | 定义触摸测试策略。 |

### 函数

| 名称 | 描述                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| -- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [int32_t OH_ArkUI_UIInputEvent_GetType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettype) | 获取UI输入事件的类型。在访问一个ArkUI_UIInputEvent指针对象之前，推荐使用该方法判断该输入事件的类型，该接口会返回[ArkUI_UIInputEvent_Type](capi-ui-input-event-h.md#arkui_uiinputevent_type)枚举中的一种。比如，当事件是一个触控类型时，由于触控类型是指向性事件，那么使用OH_ArkUI_UIInputEvent_GetXXX及OH_ArkUI_PointerEvent_GetXXX系列接口，均可以正常访问；而如果使用OH_ArkUI_KeyEvent_GetXXX相关接口去访问它，则会有无法预期的结果。对于还未支持的事件类型，接口返回默认值0。                                                                                                                                                                                                                                                       |
| [int32_t OH_ArkUI_UIInputEvent_GetAction(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getaction) | 获取输入事件的action类型。action类型为基础事件在不同阶段的类型定义，通常代表了事件的特点，并表征事件的开始与结束，如touch down, touch up。触控事件的action类型为UI_TOUCH_EVENT_ACTION_XXX，鼠标事件的action类型为UI_MOUSE_EVENT_ACTION_XXX。                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [int32_t OH_ArkUI_UIInputEvent_GetSourceType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getsourcetype) | 获取UI输入事件的触发源类型。输入源为产生输入事件的真实物理设备，如触摸屏、鼠标等，由[UI_INPUT_EVENT_SOURCE_TYPE](#anonymous3)定义，而输入工具为操作输入源设备来产生事件的工具，如手指、触控笔。在某些情况下两者可能容易发生混淆，比如当用户在操作鼠标时，鼠标既是输入源，也是输入工具。对于按键事件，并不支持获取输入源类型，返回unknown。 |
| [int32_t OH_ArkUI_UIInputEvent_GetToolType(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettooltype) | 获取UI输入事件的工具类型。输入工具为操作输入源设备来产生事件的操作方，如手指、触控笔，他们自身不真实产生事件，但可以驱动输入源设备不断产生事件。返回的类型由UI_INPUT_EVENT_TOOL_TYPE_XXX枚举值定义。                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [int64_t OH_ArkUI_UIInputEvent_GetEventTime(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_geteventtime) | 获取UI输入事件发生的时间。单位为ns。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [uint32_t OH_ArkUI_PointerEvent_GetPointerCount(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getpointercount) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点数量。指向性事件一般是附带有事件发生位置信息的事件，如触摸事件，用户操作时，可以感知事件在什么位置发生。而非指向性事件，如按键事件，一般没有位置信息，没有触点的说法，所以该接口对按键事件无效。对于触摸事件，该接口多用于处理多指触控，判断用户有几根手指在操作当前控件。而对于鼠标和轴事件，可认为触点只有1个，该接口永远返回1。                                                                                                                                                                                                                                                                                                                                                                                  |
| [int32_t OH_ArkUI_PointerEvent_GetPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getpointerid) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。返回事件发生时，事件触点的唯一标识符，用于区分同类输入设备的多点触控信息。其数值没有除标识触点外的其他含义。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [int32_t OH_ArkUI_PointerEvent_GetChangedPointerId(const ArkUI_UIInputEvent* event, uint32_t* pointerIndex)](#oh_arkui_pointerevent_getchangedpointerid) | 获取触发当前事件的手指ID。 |
| [float OH_ArkUI_PointerEvent_GetCurrentLocalX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getcurrentlocalx) | 从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)（如触摸事件、鼠标事件、轴事件）中根据实时位置获取相对于当前组件左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetCurrentLocalXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getcurrentlocalxbyindex) | 从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)（如触摸事件、鼠标事件、轴事件）中根据实时位置获取特定接触点相对于当前组件左上角的X坐标。所有类型事件，若传入的索引值小于0时为非法值。对于鼠标和轴事件，当索引值非0时为非法值。对于触摸事件，根据给定的索引获取特定接触点相对于当前组件左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetCurrentLocalY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getcurrentlocaly) | 从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)（如触摸事件、鼠标事件、轴事件）中根据实时位置获取相对于当前组件左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetCurrentLocalYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getcurrentlocalybyindex) | 从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)（如触摸事件、鼠标事件、轴事件）中根据实时位置获取特定接触点相对于当前组件左上角的Y坐标。所有类型事件，若传入的索引值小于0时为非法值。对于鼠标和轴事件，当索引值非0时为非法值。对于触摸事件，根据给定的索引获取特定接触点相对于当前组件左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getx) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getxbyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_gety) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getybyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetWindowX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getwindowx) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetWindowXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getwindowxbyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [float OH_ArkUI_PointerEvent_GetWindowY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getwindowy) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetWindowYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getwindowybyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [float OH_ArkUI_PointerEvent_GetDisplayX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getdisplayx) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getdisplayxbyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的X坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetDisplayY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getdisplayy) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getdisplayybyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的Y坐标。对于鼠标和轴事件，当给定的索引大于0时，总是返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayX(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getglobaldisplayx) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的X坐标。只能从[ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)事件中获取位置信息。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getglobaldisplayxbyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的X坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayY(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_getglobaldisplayy) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的Y坐标。只能从[ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)事件中获取位置信息。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [float OH_ArkUI_PointerEvent_GetGlobalDisplayYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getglobaldisplayybyindex) | 从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的Y坐标。只能从指针事件中获取位置信息，对于鼠标和轴事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_getpressure) | 从指向性输入事件（如触摸事件）中获取触屏压力。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [float OH_ArkUI_PointerEvent_GetTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettiltx) | 从指向性输入事件（如触摸事件）中获取相对YZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向右倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [float OH_ArkUI_PointerEvent_GetTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettilty) | 从指向性输入事件（如触摸事件）中获取相对XZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向下倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [int32_t OH_ArkUI_PointerEvent_GetRollAngle(const ArkUI_UIInputEvent* event, double* rollAngle)](#oh_arkui_pointerevent_getrollangle) | 获取触控笔绕Z轴旋转的角度。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [float OH_ArkUI_PointerEvent_GetTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettouchareawidth) | 从指向性输入事件（如触摸事件）中获取触屏区域的宽度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [float OH_ArkUI_PointerEvent_GetTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)](#oh_arkui_pointerevent_gettouchareaheight) | 从指向性输入事件（如触摸事件）中获取触屏区域的高度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [int32_t OH_ArkUI_PointerEvent_GetInteractionHand(const ArkUI_UIInputEvent *event, ArkUI_InteractionHand *hand)](#oh_arkui_pointerevent_getinteractionhand) | 获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [int32_t OH_ArkUI_PointerEvent_GetInteractionHandByIndex(const ArkUI_UIInputEvent *event, int32_t pointerIndex, ArkUI_InteractionHand *hand)](#oh_arkui_pointerevent_getinteractionhandbyindex) | 获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [uint32_t OH_ArkUI_PointerEvent_GetHistorySize(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_gethistorysize) | [从指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)中获取历史事件数量。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。历史事件为此次事件与上一次事件之间发生的原始事件，仅在指向性输入事件的移动阶段（即触摸移动或鼠标移动）中适用，在其他状态中调用返回默认值0。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [int64_t OH_ArkUI_PointerEvent_GetHistoryEventTime(const ArkUI_UIInputEvent* event, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryeventtime) | 从指向性输入事件中获取历史事件发生的时间。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [uint32_t OH_ArkUI_PointerEvent_GetHistoryPointerCount(const ArkUI_UIInputEvent* event, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypointercount) | 从指向性输入事件中获取特定历史事件中多点触控的接触点数量。本接口支持的指向性输入事件仅包含触摸事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [int32_t OH_ArkUI_PointerEvent_GetHistoryPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypointerid) | 从指向性输入事件的历史点中获取多点触控的接触点标识。本接口支持的指向性输入事件仅包含触摸事件。返回事件发生时，事件触点的唯一标识符，用于区分同类输入设备的多点触控信息。其数值没有除标识触点外的其他含义。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [float OH_ArkUI_PointerEvent_GetHistoryX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryx) | 从指向性输入事件中获取特定历史事件中特定接触点相对于当前组件左上角的X坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [float OH_ArkUI_PointerEvent_GetHistoryY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryy) | 从指向性输入事件中获取特定历史事件中特定接触点相对于当前组件左上角的Y坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [float OH_ArkUI_PointerEvent_GetHistoryWindowX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorywindowx) | 从指向性输入事件中获取特定历史事件中特定接触点相对于当前应用窗口左上角的X坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [float OH_ArkUI_PointerEvent_GetHistoryWindowY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorywindowy) | 从指向性输入事件中获取特定历史事件中特定接触点相对于当前应用窗口左上角的Y坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [float OH_ArkUI_PointerEvent_GetHistoryDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorydisplayx) | 从指向性输入事件中获取特定历史事件中特定接触点相对于当前屏幕左上角的X坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [float OH_ArkUI_PointerEvent_GetHistoryDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorydisplayy) | 从指向性输入事件中获取特定历史事件中特定接触点相对于当前屏幕左上角的Y坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryglobaldisplayx) | 从给定指针索引和历史记录索引的指向性输入事件中获取历史事件中相对于全局显示的特定触摸点的X坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。只能从指针事件中获取位置信息，对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 20开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistoryglobaldisplayy) | 从给定指针索引和历史记录索引的指向性输入事件中获取历史事件中相对于全局显示的特定触摸点的Y坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。只能从指针事件中获取位置信息，对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 20开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [float OH_ArkUI_PointerEvent_GetHistoryPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorypressure) | 从指向性输入事件（如触摸事件）中获取特定历史事件中的触屏压力。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [float OH_ArkUI_PointerEvent_GetHistoryTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytiltx) | 从指向性输入事件（如触摸事件）中获取特定历史事件中的相对YZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向右倾斜。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [float OH_ArkUI_PointerEvent_GetHistoryTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytilty) | 从指向性输入事件（如触摸事件）中获取特定历史事件中的相对XZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向下倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。 |
| [float OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytouchareawidth) | 从指向性输入事件（如触摸事件）中获取特定历史事件中的触屏区域的宽度。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [float OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)](#oh_arkui_pointerevent_gethistorytouchareaheight) | 从指向性输入事件（如触摸事件）中获取特定历史事件中的触屏区域的高度。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| [double OH_ArkUI_AxisEvent_GetVerticalAxisValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getverticalaxisvalue) | 获取当前轴事件的垂直滚动轴的值。该值通常由鼠标滚轮或用户在触控板上双指竖向滑动产生。 当通过鼠标滚轮触发时： 1. 上报的数值单位为角度，表示单次滚动角度增量，非滚动总量。 2. 上报的数值已与用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](#oh_arkui_axisevent_getscrollstep)叠加运算。 3. 数值的正负代表方向，向前滚动鼠标滚轮时上报数值为负数，向后滚动鼠标滚轮时上报数值为正数。 当通过触控板双指竖向滑动触发时： 1. 上报的数值单位为px，表示单次滚动增量，非滚动总量。 2. 上报的数值不受用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](#oh_arkui_axisevent_getscrollstep)影响。 3. 数值的正负代表方向，双指从上往下滑动时上报数值为负数，双指从下往上滑动时上报数值为正数。 4. 方向会受系统设置中“自然滚动”配置的影响。 通常情况下，垂直滚动轴事件只能驱动竖向的滑动手势响应。但当鼠标指针下命中的可滑动手势里可响应方向一致时，垂直滚动轴事件可以驱动这些滑动手势得到响应，即使这些手势所定义的方向是横向的。 |
| [double OH_ArkUI_AxisEvent_GetHorizontalAxisValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_gethorizontalaxisvalue) | 获取当前轴事件的水平滚动轴的值，该值通过在触控板上双指横向滑动产生。 1. 上报的数值单位为px，表示单次滚动增量，非滚动总量。 2. 上报的数值不受用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)影响。 3. 数值的正负代表方向，双指从左往右滑动时上报数值为负数，双指从右往左滑动时上报数值为正数。 4. 方向会受系统设置中“自然滚动”配置的影响。 |
| [double OH_ArkUI_AxisEvent_GetPinchAxisScaleValue(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getpinchaxisscalevalue) | 获取当前轴事件的捏合轴缩放的值。通过触控板双指缩放/捏合操作产生。上报的scale数值，为相对于初始状态时的当前scale值。初始状态为系统识别到用户通过触控板发生了捏合操作时的两指位置状态，此时的scale数值为1.0。在手指抬起前的本次捏合操作过程中，所上报的scale数值均将初始状态作为参考系，从初始状态往中心捏合，则上报的scale会从1.0逐步往0.0缩小；当从初始化状态往外扩大双指距离时，会从1.0逐步变大。                                                                                                                                                                                                                                                                                                                                                                   |
| [int32_t OH_ArkUI_AxisEvent_GetAxisAction(const ArkUI_UIInputEvent* event)](#oh_arkui_axisevent_getaxisaction) | 获取当前轴事件的操作类型。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [int32_t OH_ArkUI_AxisEvent_HasAxis(const ArkUI_UIInputEvent* event, int32_t axis)](#oh_arkui_axisevent_hasaxis) | 检测此轴事件是否包含指定的轴类型。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [int32_t OH_ArkUI_PointerEvent_SetInterceptHitTestMode(const ArkUI_UIInputEvent* event, HitTestMode mode)](#oh_arkui_pointerevent_setintercepthittestmode) | 配置触摸测试模式。仅适用于接收基础事件的场景，如使用NODE_ON_TOUCH接收触摸事件场景。对于通过[OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent)接口从一个手势事件中获取到的ArkUI_UIInputEvent对象，无法使用该接口。                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_MouseEvent_GetMouseButton(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getmousebutton) | 获取鼠标事件的按键类型的值。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_MouseEvent_GetMouseAction(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getmouseaction) | 获取鼠标事件的鼠标动作类型的值。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [int32_t OH_ArkUI_PointerEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)](#oh_arkui_pointerevent_setstoppropagation) | 设置是否阻止事件冒泡。仅适用于接收基础事件的场景，如使用NODE_ON_TOUCH接收触摸事件场景，不适用于轴事件。对于通过[OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent)接口从一个手势事件中获取到的ArkUI_UIInputEvent对象，无法使用该接口。 |
| [int32_t OH_ArkUI_UIInputEvent_GetDeviceId(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getdeviceid) | 获取当前UI输入事件的设备ID。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
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
| [float OH_ArkUI_MouseEvent_GetRawDeltaX(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getrawdeltax) | 获取鼠标设备在二维平面X轴的移动增量。其数值为鼠标硬件的原始移动数据，使用物理世界中鼠标移动的距离单位进行表示。上报数值由硬件本身决定，并非屏幕的物理/逻辑像素。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [float OH_ArkUI_MouseEvent_GetRawDeltaY(const ArkUI_UIInputEvent* event)](#oh_arkui_mouseevent_getrawdeltay) | 获取鼠标设备在二维平面Y轴的移动增量。其数值为鼠标硬件的原始移动数据，使用物理世界中鼠标移动的距离单位进行表示。上报数值由硬件本身决定，并非屏幕的物理/逻辑像素。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [int32_t OH_ArkUI_MouseEvent_GetPressedButtons(const ArkUI_UIInputEvent* event, int32_t* pressedButtons, int32_t* length)](#oh_arkui_mouseevent_getpressedbuttons) | 从鼠标事件中获取按下的按键。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_UIInputEvent_GetTargetDisplayId(const ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_gettargetdisplayid) | 获取发生UI输入事件的屏幕ID。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| [bool OH_ArkUI_HoverEvent_IsHovered(const ArkUI_UIInputEvent* event)](#oh_arkui_hoverevent_ishovered) | 获取鼠标是否悬浮在当前组件上                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [int32_t OH_ArkUI_PointerEvent_CreateClonedEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)](#oh_arkui_pointerevent_createclonedevent) | 基于原始事件指针创建克隆事件指针。仅对触摸事件有效。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [int32_t OH_ArkUI_PointerEvent_DestroyClonedEvent(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_destroyclonedevent) | 销毁由OH_ArkUI_PointerEvent_CreateClonedEvent()创建的克隆事件指针。克隆事件使用完毕后应调用该接口释放资源。 |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPosition(const ArkUI_UIInputEvent* event, float x, float y)](#oh_arkui_pointerevent_setclonedeventlocalposition) | 设置指向性克隆事件相对于当前组件左上角的X坐标和Y坐标。该接口应在调用OH_ArkUI_PointerEvent_CreateClonedEvent()创建克隆事件后使用；同系列SetClonedEvent接口均仅适用于克隆事件。 |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)](#oh_arkui_pointerevent_setclonedeventlocalpositionbyindex) | 设置克隆指向性事件特定接触点相对于当前组件左上角的X坐标和Y坐标。只有通过[OH_ArkUI_PointerEvent_CreateClonedEvent](#oh_arkui_pointerevent_createclonedevent)接口创建的ArkUI_UIInputEvent克隆事件指针才能使用此接口。 |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventActionType(const ArkUI_UIInputEvent* event, int32_t actionType)](#oh_arkui_pointerevent_setclonedeventactiontype) | 设置当前带有指向性的克隆输入事件的事件类型。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId(const ArkUI_UIInputEvent* event, int32_t fingerId)](#oh_arkui_pointerevent_setclonedeventchangedfingerid) | 设置当前带有指向性的克隆输入事件的触摸点ID。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| [int32_t OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex(const ArkUI_UIInputEvent* event, int32_t fingerId, int32_t pointerIndex)](#oh_arkui_pointerevent_setclonedeventfingeridbyindex) | 设置带有指向性的克隆输入事件特定接触点的触摸点ID。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [int32_t OH_ArkUI_PointerEvent_PostClonedEvent(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_postclonedevent) | 转发克隆事件到特定节点。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_PointerEvent_CreateClonedPointerEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)](#oh_arkui_pointerevent_createclonedpointerevent) | 创建指定事件的克隆事件。该接口适用于触摸事件、鼠标事件和轴事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_PointerEvent_CreatePointerEvent(ArkUI_UIInputEvent** event, ArkUI_UIInputEvent_Type type)](#oh_arkui_pointerevent_createpointerevent) | 创建新事件，不克隆现有事件。该接口适用于触摸事件、鼠标事件和轴事件。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_PointerEvent_DestroyClonedPointerEvent(const ArkUI_UIInputEvent* event)](#oh_arkui_pointerevent_destroyclonedpointerevent) | 销毁克隆事件指针。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetActionType(const ArkUI_UIInputEvent* event, int32_t type)](#oh_arkui_clonedevent_setactiontype) | 设置克隆事件的动作类型。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetSourceType(const ArkUI_UIInputEvent* event, int32_t sourceType)](#oh_arkui_clonedevent_setsourcetype) | 设置克隆事件的源类型。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetToolType(const ArkUI_UIInputEvent* event, int32_t toolType)](#oh_arkui_clonedevent_settooltype) | 设置克隆事件的工具类型。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressure(const ArkUI_UIInputEvent* event, float pressure)](#oh_arkui_clonedevent_setpressure) | 设置克隆事件应用于触摸屏的压力。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressureByIndex(const ArkUI_UIInputEvent* event, float pressure, int32_t pointerIndex)](#oh_arkui_clonedevent_setpressurebyindex) | 设置克隆事件指定触摸点应用于触摸屏的压力。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetEventTime(const ArkUI_UIInputEvent* event, int64_t timestamp)](#oh_arkui_clonedevent_seteventtime) | 设置克隆UI输入事件发生的时间。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetDeviceId(const ArkUI_UIInputEvent* event, int32_t deviceId)](#oh_arkui_clonedevent_setdeviceid) | 设置触发克隆UI输入事件的设备ID。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetTargetDisplayId(const ArkUI_UIInputEvent* event, int32_t targetDisplayId)](#oh_arkui_clonedevent_settargetdisplayid) | 设置克隆UI输入事件发生的屏幕ID。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedFingerId(const ArkUI_UIInputEvent* event, int32_t fingerId)](#oh_arkui_clonedevent_setchangedfingerid) | 设置克隆指针事件的触摸点ID。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetFingerIdByIndex(const ArkUI_UIInputEvent* event, int32_t fingerId, int32_t pointerIndex)](#oh_arkui_clonedevent_setfingeridbyindex) | 设置克隆事件特定接触点的触摸点ID。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedWindowPosition(const ArkUI_UIInputEvent* event, float x, float y)](#oh_arkui_clonedevent_setchangedwindowposition) | 设置克隆事件相对于当前窗口左上角的X坐标和Y坐标。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetWindowPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)](#oh_arkui_clonedevent_setwindowpositionbyindex) | 设置克隆事件特定接触点相对于当前窗口左上角的X坐标和Y坐标。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedScreenPosition(const ArkUI_UIInputEvent* event, float x, float y)](#oh_arkui_clonedevent_setchangedscreenposition) | 设置克隆事件相对于当前屏幕左上角的X坐标和Y坐标。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetScreenPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)](#oh_arkui_clonedevent_setscreenpositionbyindex) | 设置克隆事件特定接触点相对于当前屏幕左上角的X坐标和Y坐标。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedGlobalDisplayPosition(const ArkUI_UIInputEvent* event, float x, float y)](#oh_arkui_clonedevent_setchangedglobaldisplayposition) | 设置克隆事件在[全局坐标系](../../windowmanager/window-terminology.md#global-coordinate-system全局坐标系)的坐标。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetGlobalDisplayPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)](#oh_arkui_clonedevent_setglobaldisplaypositionbyindex) | 设置克隆事件在[全局坐标系](../../windowmanager/window-terminology.md#global-coordinate-system全局坐标系)的坐标。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetHandleId(const ArkUI_UIInputEvent* event, int32_t eventHandleId)](#oh_arkui_clonedevent_sethandleid) | 设置事件处理会话的唯一句柄。该句柄必须用于对该事件的任何进一步操作。对于给定的手指，同一时间只有一个具有此句柄的事件处于活动状态。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetTiltAngle(const ArkUI_UIInputEvent* event, float tiltX, float tiltY)](#oh_arkui_clonedevent_settiltangle) | 设置克隆事件相对于YZ平面和XZ平面的倾斜角度。tiltX取值范围为[-90, 90]，其中正值表示向右倾斜；tiltY取值范围为[-90, 90]，其中正值表示向下倾斜。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。 |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetRollAngle(const ArkUI_UIInputEvent* event, float rollAngle)](#oh_arkui_clonedevent_setrollangle) | 设置克隆事件触控笔绕Z轴的旋转角度。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressedKeys(const ArkUI_UIInputEvent* event, int32_t* pressedKeyCodes, int32_t length)](#oh_arkui_clonedevent_setpressedkeys) | 设置克隆事件中所有按下的按键。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedTouchArea(const ArkUI_UIInputEvent* event, float width, float height)](#oh_arkui_clonedevent_setchangedtoucharea) | 设置克隆事件的手指接触区域的宽度和高度，该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetTouchAreaByIndex(const ArkUI_UIInputEvent* event, float width, float height, int32_t pointerIndex)](#oh_arkui_clonedevent_settouchareabyindex) | 设置克隆事件特定接触点的手指接触区域的宽度和高度，该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedInteractionHand(const ArkUI_UIInputEvent* event, int32_t hand)](#oh_arkui_clonedevent_setchangedinteractionhand) | 设置克隆事件是左手或右手触发。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetInteractionHandByIndex(const ArkUI_UIInputEvent* event, int32_t hand, int32_t pointerIndex)](#oh_arkui_clonedevent_setinteractionhandbyindex) | 设置克隆事件特定接触点由左手或右手触发。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressedTimeByIndex(const ArkUI_UIInputEvent* event, int64_t pressedTime, int32_t pointerIndex)](#oh_arkui_clonedevent_setpressedtimebyindex) | 设置克隆事件指定触摸点的按下时间。该接口仅适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPinchAxisScaleValue(const ArkUI_UIInputEvent* event, double pinchAxisScaleValue)](#oh_arkui_clonedevent_setpinchaxisscalevalue) | 设置克隆事件的捏合轴缩放值。该接口仅适用于轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetHorizontalAxisScaleValue(const ArkUI_UIInputEvent* event, double horizontalAxisScaleValue)](#oh_arkui_clonedevent_sethorizontalaxisscalevalue) | 设置克隆事件水平滚动轴的值。该接口仅适用于轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetVerticalAxisScaleValue(const ArkUI_UIInputEvent* event, double verticalAxisScaleValue)](#oh_arkui_clonedevent_setverticalaxisscalevalue) | 设置克隆事件垂直滚动轴的值。该接口仅适用于轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetScrollStep(const ArkUI_UIInputEvent* event, int32_t scrollStep)](#oh_arkui_clonedevent_setscrollstep) | 设置克隆事件的滚动步长系数。该接口仅适用于轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetMouseButton(const ArkUI_UIInputEvent* event, int32_t button)](#oh_arkui_clonedevent_setmousebutton) | 设置克隆事件的按钮类型值。该接口仅适用于鼠标事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetRawDeltaX(const ArkUI_UIInputEvent* event, float rawDeltaX)](#oh_arkui_clonedevent_setrawdeltax) | 设置鼠标设备在二维平面X轴的移动增量。其数值为鼠标硬件的原始移动数据，使用物理世界中鼠标移动的距离单位进行表示。该接口仅适用于鼠标事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetRawDeltaY(const ArkUI_UIInputEvent* event, float rawDeltaY)](#oh_arkui_clonedevent_setrawdeltay) | 设置鼠标设备在二维平面Y轴的移动增量。其数值为鼠标硬件的原始移动数据，使用物理世界中鼠标移动的距离单位进行表示。该接口仅适用于鼠标事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressedButtons(const ArkUI_UIInputEvent* event, const int32_t* pressedButtons, int32_t length)](#oh_arkui_clonedevent_setpressedbuttons) | 设置克隆事件的按下的按键。该接口仅适用于鼠标事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ArkUI_ErrorCode OH_ArkUI_PointerEvent_PostClonedEventWithStrategy(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event, ArkUI_CompetitionStrategy strategy)](#oh_arkui_pointerevent_postclonedeventwithstrategy) | 使用指定的竞争策略将克隆事件发送到特定节点，适用于向目标节点注入克隆事件并需要控制注入事件与目标节点已有手势之间是否竞争的场景。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。 |
| [ArkUI_ErrorCode OH_ArkUI_UIInputEvent_GetLatestStatus()](#oh_arkui_uiinputevent_getlateststatus) | 调用该方法获取最近一次UIInput相关方法的执行情况。通常情况下不需要使用该方法，仅在调用UIInput相关方法后需要确认最近一次调用是否执行异常时使用。 |
| [ArkUI_CoastingAxisEvent* OH_ArkUI_UIInputEvent_GetCoastingAxisEvent(ArkUI_UIInputEvent* event)](#oh_arkui_uiinputevent_getcoastingaxisevent) | 从组件事件中获取惯性滚动轴事件，仅当用户在触摸板上使用双指执行满足系统惯性滚动判定条件的抛滑操作，且指针位置下存在注册了[NODE_ON_COASTING_AXIS_EVENT](capi-native-node-h.md#arkui_nodeeventtype)事件的组件时，才能获取到有效事件。在从[ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)对象获取到[ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)对象后调用此方法。惯性滚动轴事件仅在双指抛滑并离开触控板时触发，因此仅支持触控板。惯性滚动轴事件会在手指离开触控板后，根据抛滑速度产生轴值逐渐衰减的事件。由于刷新频率和性能的影响，当前事件轴值可能高于或低于上一个事件值。在惯性滚动轴事件期间，以下四种行为会中断事件，并立即收到[ARKUI_COASTING_AXIS_EVENT_PHASE_END](#arkui_coastingaxiseventphase)。1. 手指触摸触控板。2. 滚动鼠标滚轮。3. 手指或鼠标点击注册了惯性滚动轴事件的节点。需要注意的是，点击未注册此事件的节点不会产生任何效果。例如，A节点注册了惯性滚动轴事件，当事件发生时，让B节点滚动，但点击B节点不会中断此事件。点击事件的中断行为受[OH_ArkUI_PointerEvent_SetInterceptHitTestMode](#oh_arkui_pointerevent_setintercepthittestmode)的影响。此外，如果用户点击区域存在已收集的可响应惯性滚动轴事件的节点，本次惯性滚动轴事件会被强制终止。4. 应用休眠（例如最小化、锁屏）。 |
| [int64_t OH_ArkUI_CoastingAxisEvent_GetEventTime(ArkUI_CoastingAxisEvent* event)](#oh_arkui_coastingaxisevent_geteventtime) | 获取惯性滚动轴事件发生的时间。  |
| [ArkUI_CoastingAxisEventPhase OH_ArkUI_CoastingAxisEvent_GetPhase(ArkUI_CoastingAxisEvent* event)](#oh_arkui_coastingaxisevent_getphase) | 获取惯性滚动轴事件发生时的滚动阶段。  |
| [float OH_ArkUI_CoastingAxisEvent_GetDeltaY(ArkUI_CoastingAxisEvent* event)](#oh_arkui_coastingaxisevent_getdeltay) | 获取惯性滚动轴事件垂直方向的增量值。单位为px，表示为单次滚动增量，非滚动总量。数值的正负代表方向，双指从上往下滑动时为负数，双指从下往上滑动时为正数。  |
| [float OH_ArkUI_CoastingAxisEvent_GetDeltaX(ArkUI_CoastingAxisEvent* event)](#oh_arkui_coastingaxisevent_getdeltax) | 获取惯性滚动轴事件水平方向的增量值。单位为px，表示为单次滚动增量，非滚动总量。数值的正负代表方向，双指从左往右滑动时为负数，双指从右往左滑动时为正数。  |
| [int32_t OH_ArkUI_CoastingAxisEvent_SetPropagation(ArkUI_CoastingAxisEvent* event, bool propagation)](#oh_arkui_coastingaxisevent_setpropagation) | 设置惯性滚动轴事件是否启用冒泡，默认禁止冒泡。|
| [ArkUI_ErrorCode OH_ArkUI_TouchTestInfo_GetTouchTestInfoList(ArkUI_TouchTestInfo* info, ArkUI_TouchTestInfoItemArray* array, int32_t* size)](#oh_arkui_touchtestinfo_gettouchtestinfolist) | 获取触摸测试信息中的触摸测试信息项数组。 |
| [float OH_ArkUI_TouchTestInfoItem_GetX(const ArkUI_TouchTestInfoItem* info)](#oh_arkui_touchtestinfoitem_getx) | 从触摸测试信息项中获取相对于子组件左上角的X坐标，单位为px。 |
| [float OH_ArkUI_TouchTestInfoItem_GetY(const ArkUI_TouchTestInfoItem* info)](#oh_arkui_touchtestinfoitem_gety) | 从触摸测试信息项中获取相对于子组件左上角的Y坐标，单位为px。 |
| [float OH_ArkUI_TouchTestInfoItem_GetWindowX(const ArkUI_TouchTestInfoItem* info)](#oh_arkui_touchtestinfoitem_getwindowx) | 从触摸测试信息项中获取相对于当前应用窗口左上角的X坐标，单位为px。 |
| [float OH_ArkUI_TouchTestInfoItem_GetWindowY(const ArkUI_TouchTestInfoItem* info)](#oh_arkui_touchtestinfoitem_getwindowy) | 从触摸测试信息项中获取相对于当前应用窗口左上角的Y坐标，单位为px。 |
| [float OH_ArkUI_TouchTestInfoItem_GetXRelativeToParent(const ArkUI_TouchTestInfoItem* info)](#oh_arkui_touchtestinfoitem_getxrelativetoparent) | 从触摸测试信息项中获取相对于父组件左上角的X坐标，单位为px。 |
| [float OH_ArkUI_TouchTestInfoItem_GetYRelativeToParent(const ArkUI_TouchTestInfoItem* info)](#oh_arkui_touchtestinfoitem_getyrelativetoparent) | 从触摸测试信息项中获取相对于父组件左上角的Y坐标，单位为px。 |
| [ArkUI_ErrorCode OH_ArkUI_TouchTestInfoItem_GetChildRect(const ArkUI_TouchTestInfoItem* info, ArkUI_Rect* childRect)](#oh_arkui_touchtestinfoitem_getchildrect) | 从触摸测试信息项中获取子组件的边界矩形信息。 |
| [ArkUI_ErrorCode OH_ArkUI_TouchTestInfoItem_GetChildId(const ArkUI_TouchTestInfoItem* info, char* buffer, int32_t bufferSize)](#oh_arkui_touchtestinfoitem_getchildid) | 从触摸测试信息项中获取子组件的ID。 |
| [ArkUI_ErrorCode OH_ArkUI_TouchTestInfo_SetTouchResultStrategy(ArkUI_TouchTestInfo* info, ArkUI_TouchTestStrategy strategy)](#oh_arkui_touchtestinfo_settouchresultstrategy) | 设置触摸测试策略，即组件及其子组件在命中测试过程中的行为方式，适用于自定义触摸命中结果、将触摸事件分发给指定子组件或控制兄弟节点是否继续参与命中测试的场景。 |
| [ArkUI_ErrorCode OH_ArkUI_TouchTestInfo_SetTouchResultId(ArkUI_TouchTestInfo* info, const char* id)](#oh_arkui_touchtestinfo_settouchresultid) | 设置命中测试过程中需要作用的子组件ID，适用于自定义触摸测试结果并希望将触摸事件分发到指定子组件的场景。 |

## 枚举类型说明

### ArkUI_UIInputEvent_Type

```c
enum ArkUI_UIInputEvent_Type
```

**描述：**


UI输入事件类型定义。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_UIINPUTEVENT_TYPE_UNKNOWN = 0 | 未知。 |
| ARKUI_UIINPUTEVENT_TYPE_TOUCH = 1 | 触摸事件。 |
| ARKUI_UIINPUTEVENT_TYPE_AXIS = 2 | 轴事件。 |
| ARKUI_UIINPUTEVENT_TYPE_MOUSE = 3 | 鼠标事件。|
| ARKUI_UIINPUTEVENT_TYPE_KEY = 4 | 按键事件。<br>**起始版本：** 20 |
| ARKUI_UIINPUTEVENT_TYPE_DIGITAL_CROWN = 5 | 表冠事件。<br>**起始版本：** 24 |

### anonymous1

```c
enum anonymous1
```

**描述：**


定义输入事件的行为类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_TOUCH_EVENT_ACTION_CANCEL = 0 | 触摸取消。 |
| UI_TOUCH_EVENT_ACTION_DOWN = 1 | 触摸按下。 |
| UI_TOUCH_EVENT_ACTION_MOVE = 2 | 触摸移动。 |
| UI_TOUCH_EVENT_ACTION_UP = 3 | 触摸抬起。 |

### anonymous2

```c
enum anonymous2
```

**描述：**


产生输入事件的工具类型定义。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN = 0 | 不支持的工具类型。 |
| UI_INPUT_EVENT_TOOL_TYPE_FINGER = 1 | 手指。 |
| UI_INPUT_EVENT_TOOL_TYPE_PEN = 2 | 触控笔。 |
| UI_INPUT_EVENT_TOOL_TYPE_MOUSE = 3 | 鼠标。 |
| UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD = 4 | 触控板。 |
| UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK = 5 | 操纵杆。 |

### anonymous3

```c
enum anonymous3
```

**描述：**


产生输入事件的来源类型定义。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN = 0 | 未知输入源。 |
| UI_INPUT_EVENT_SOURCE_TYPE_MOUSE = 1 | 鼠标。 |
| UI_INPUT_EVENT_SOURCE_TYPE_TOUCH_SCREEN = 2 | 触摸屏。 |
| UI_INPUT_EVENT_SOURCE_TYPE_KEY = 4 | 按键。<br>**起始版本：** 22 |
| UI_INPUT_EVENT_SOURCE_TYPE_JOYSTICK = 5 | 手柄。<br>**起始版本：** 22 |

### HitTestMode

```c
enum HitTestMode
```

**描述：**


定义触摸测试类型的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HTM_DEFAULT = 0 | 默认触摸测试效果。自身及子节点响应触摸测试，但阻塞兄弟节点的触摸测试，不影响祖先节点的触摸测试。 |
| HTM_BLOCK = 1 | 自身响应触摸测试，阻塞子节点、兄弟节点和祖先节点的触摸测试。 |
| HTM_TRANSPARENT = 2 | 自身和子节点都响应触摸测试，不会阻塞兄弟节点和祖先节点的触摸测试。 |
| HTM_NONE = 3 | 自身不响应触摸测试，不会阻塞子节点、兄弟节点和祖先节点的触摸测试。 |
| HTM_BLOCK_HIERARCHY = 4 | 自身和子节点响应触摸测试，阻止所有优先级较低的兄弟节点和父节点参与触摸测试。<br>**起始版本：** 20 |
| HTM_BLOCK_DESCENDANTS = 5 | 自身不响应触摸测试，并且所有的后代（孩子、孙子等）也不响应触摸测试，不会影响祖先节点的触摸测试。<br>**起始版本：** 20 |

### anonymous4

```c
enum anonymous4
```

**描述：**


定义鼠标事件的行为类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| UI_MOUSE_EVENT_ACTION_UNKNOWN = 0 | 无效行为。<br>**说明：** 此行为由系统侧处理，开发者无需关注。 |
| UI_MOUSE_EVENT_ACTION_PRESS = 1 | 鼠标按键按下。 |
| UI_MOUSE_EVENT_ACTION_RELEASE = 2 | 鼠标按键松开。 |
| UI_MOUSE_EVENT_ACTION_MOVE = 3 | 鼠标移动。 |
| UI_MOUSE_EVENT_ACTION_CANCEL = 13 | 鼠标按键被取消。<br>**起始版本：** 18 |

### anonymous5

```c
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

```c
enum ArkUI_ModifierKeyName
```

**描述：**


定义修饰键。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_MODIFIER_KEY_CTRL = 1 << 0 | Ctrl. |
| ARKUI_MODIFIER_KEY_SHIFT = 1 << 1 | Shift. |
| ARKUI_MODIFIER_KEY_ALT = 1 << 2 | Alt. |
| ARKUI_MODIFIER_KEY_FN = 1 << 3 | Fn（仅调试使用，通常不上报Fn状态）. |

### anonymous6

```c
enum anonymous6
```

**描述：**


定义[焦点轴事件](./arkui-ts/ts-universal-events-focus_axis.md)的轴类型。

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
| UI_FOCUS_AXIS_EVENT_ABS_RX = 8 | 游戏手柄RX轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_RY = 9 | 游戏手柄RY轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_THROTTLE = 10 | 游戏手柄THROTTLE轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_RUDDER = 11 | 游戏手柄RUDDER轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_WHEEL = 12 | 游戏手柄WHEEL轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_HAT1X = 13 | 游戏手柄HAT1X轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_HAT1Y = 14 | 游戏手柄HAT1Y轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_HAT2X = 15 | 游戏手柄HAT2X轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_HAT2Y = 16 | 游戏手柄HAT2Y轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_HAT3X = 17 | 游戏手柄HAT3X轴。<br>**起始版本：** 23 |
| UI_FOCUS_AXIS_EVENT_ABS_HAT3Y = 18 | 游戏手柄HAT3Y轴。<br>**起始版本：** 23 |

### ArkUI_InteractionHand

```c
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

```c
enum anonymous7
```

**描述：**


定义[轴事件](./arkui-ts/ts-universal-events-axis.md)的操作类型。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| UI_AXIS_EVENT_ACTION_NONE = 0 | 轴事件异常。 |
| UI_AXIS_EVENT_ACTION_BEGIN = 1 | 轴事件开始。 |
| UI_AXIS_EVENT_ACTION_UPDATE = 2 | 轴事件更新。 |
| UI_AXIS_EVENT_ACTION_END = 3 | 轴事件结束。 |
| UI_AXIS_EVENT_ACTION_CANCEL = 4 | 轴事件取消。 |

### anonymous8

```c
enum anonymous8
```

**描述：**


定义轴事件的轴类型。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| UI_AXIS_TYPE_VERTICAL_AXIS = 0 | 垂直滚动轴。 |
| UI_AXIS_TYPE_HORIZONTAL_AXIS = 1 | 水平滚动轴。 |
| UI_AXIS_TYPE_PINCH_AXIS = 2 | 捏合轴。 |

### ArkUI_CoastingAxisEventPhase

```c
enum ArkUI_CoastingAxisEventPhase
```

**描述：**


定义惯性滚动轴事件的阶段。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_COASTING_AXIS_EVENT_PHASE_NONE = 0 | 非惯性轴事件阶段，异常默认值，可以通过检查惯性轴阶段值不为该值来判断当前惯性轴事件是有效的。  |
| ARKUI_COASTING_AXIS_EVENT_PHASE_BEGIN = 1 | 惯性滚动轴事件开始，此为惯性阶段的第一个事件。  |
| ARKUI_COASTING_AXIS_EVENT_PHASE_UPDATE = 2 | 惯性滚动轴事件更新，此阶段可以获取惯性轴值增量来处理滚动偏移。  |
| ARKUI_COASTING_AXIS_EVENT_PHASE_END = 3 | 惯性滚动轴事件结束，此值在惯性被刹停（惯性滚动阶段用户重新触摸触控板或通过鼠标及触屏与组件产生交互等）或惯性衰减至自然停止时发送，到达此阶段时，应立即停止惯性滚动效果。  |

### ArkUI_TouchTestStrategy

```c
enum ArkUI_TouchTestStrategy
```

**描述：**


定义触摸测试策略。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TOUCH_TEST_STRATEGY_DEFAULT = 0 | 自定义分发不产生影响，系统按当前节点命中状态分发事件。  |
| ARKUI_TOUCH_TEST_STRATEGY_FORWARD_COMPETITION = 1 | 应用指定分发事件到某个子节点，其他兄弟节点是否分发事件交由系统决定。  |
| ARKUI_TOUCH_TEST_STRATEGY_FORWARD = 2 | 应用指定分发事件到某个子节点，系统不再分发事件到其他兄弟节点。  |

### ArkUI_CompetitionStrategy

```c
enum ArkUI_CompetitionStrategy
```

**描述：**


事件的注入方和被注入方间手势识别结果是否为竞争场景的策略。该策略决定了事件的注入方如何与被注入方的手势处理逻辑交互，非竞争场景会同时触发手势，竞争场景只触发其中一个。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_COMPETITION_STRATEGY_DEFAULT = 0 | 无竞争策略。注入的事件不与任何现有手势竞争。注入的事件和现有手势可以独立并行处理。  |
| ARKUI_COMPETITION_STRATEGY_COMPETITION = 1 | 竞争策略。事件注入方和被注入方间的手势为竞争关系，只能处理其中一方的手势。  |

### ArkUI_CrownEvent_Action

```c
enum ArkUI_CrownEvent_Action
```

**描述：**


定义表冠事件的阶段。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_CROWNEVENT_ACTION_UNKNOWN = 0 | 未知的表冠事件阶段。  |
| ARKUI_CROWNEVENT_ACTION_UPDATE = 1 | 表冠事件更新。  |
| ARKUI_CROWNEVENT_ACTION_END = 2 | 表冠事件结束。  |

## 函数说明

### OH_ArkUI_UIInputEvent_GetType()

```c
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

```c
int32_t OH_ArkUI_UIInputEvent_GetAction(const ArkUI_UIInputEvent* event)
```

**描述：**


获取输入事件的action类型。action类型为基础事件在不同阶段的类型定义，通常代表了事件的特点，并表征事件的开始与结束，如touch down, touch up。触控事件的action类型为[UI_TOUCH_EVENT_ACTION](#anonymous1)，鼠标事件的action类型为[UI_MOUSE_EVENT_ACTION](#anonymous4)。轴事件的action类型获取请使用[OH_ArkUI_AxisEvent_GetAxisAction](#oh_arkui_axisevent_getaxisaction)接口，返回值类型为[UI_AXIS_EVENT_ACTION](#anonymous7)，按键事件的action类型获取请使用[OH_ArkUI_KeyEvent_GetType](./capi-native-key-event-h.md#oh_arkui_keyevent_gettype)接口，返回值类型为[ArkUI_KeyEventType](./capi-native-key-event-h.md#arkui_keyeventtype)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回当前UI输入事件的操作类型，如果参数异常则返回-1。 |

### OH_ArkUI_UIInputEvent_GetSourceType()

```c
int32_t OH_ArkUI_UIInputEvent_GetSourceType(const ArkUI_UIInputEvent* event)
```

**描述：**


获取UI输入事件的触发源类型。输入源为产生输入事件的真实物理设备，如触摸屏、鼠标等，由[UI_INPUT_EVENT_SOURCE_TYPE](#anonymous3)定义，而输入工具为操作输入源设备来产生事件的工具，如手指、触控笔。在某些情况下两者可能容易发生混淆，比如当用户在操作鼠标时，鼠标既是输入源，也是输入工具。对于按键事件，并不支持获取输入源类型，返回unknown。

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

```c
int32_t OH_ArkUI_UIInputEvent_GetToolType(const ArkUI_UIInputEvent* event)
```

**描述：**


获取UI输入事件的工具类型。输入工具为操作输入源设备来产生事件的操作方，如手指、触控笔，他们自身不真实产生事件，但可以驱动输入源设备不断产生事件。返回的类型由[UI_INPUT_EVENT_TOOL_TYPE](#anonymous2)枚举值定义。对于按键事件，并不支持获取输入工具类型，返回unknown。

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

```c
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

```c
uint32_t OH_ArkUI_PointerEvent_GetPointerCount(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点数量。指向性事件一般是附带有事件发生位置信息的事件，如触摸事件，用户操作时，可以感知事件在什么位置发生。而非指向性事件，如按键事件，一般没有位置信息，没有触点的说法，该接口永远返回0。对于触摸事件，该接口多用于处理多指触控，判断用户有几根手指在操作当前控件。而对于鼠标和轴事件，可认为触点只有1个，该接口永远返回1。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回当前指向性输入事件的接触点数量。 |

### OH_ArkUI_PointerEvent_GetPointerId()

```c
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

```c
int32_t OH_ArkUI_PointerEvent_GetChangedPointerId(const ArkUI_UIInputEvent* event, uint32_t* pointerIndex)
```

**描述：**


获取触发当前事件的对应的手指ID。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t* pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_PointerEvent_GetX()

```c
float OH_ArkUI_PointerEvent_GetX(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件相对于当前组件左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetXByIndex()

```c
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
| float | 返回指向性输入事件中特定接触点相对于当前组件左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetY()

```c
float OH_ArkUI_PointerEvent_GetY(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件相对于当前组件左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetYByIndex()

```c
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
| float | 返回指向性输入事件中特定接触点相对于当前组件左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetCurrentLocalX()

```c
float OH_ArkUI_PointerEvent_GetCurrentLocalX(const ArkUI_UIInputEvent* event)
```

**描述：**


从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)（如触摸事件、鼠标事件、轴事件）中根据实时位置获取相对于当前组件左上角的X坐标。

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件相对于当前组件左上角的X坐标；默认单位为px，单位可跟随[setLengthMetricUnit](../apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlengthmetricunit)的设置而变化；如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetCurrentLocalXByIndex()

```c
float OH_ArkUI_PointerEvent_GetCurrentLocalXByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)（如触摸事件、鼠标事件、轴事件）中根据实时位置获取特定接触点相对于当前组件左上角的X坐标。

所有类型事件，若传入的索引值小于0时为非法值。

对于鼠标和轴事件，当索引值非0时为非法值。

对于触摸事件，根据给定的索引获取特定接触点相对于当前组件左上角的X坐标。

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回特定接触点相对于当前组件左上角的X坐标；默认单位为px，单位可跟随[setLengthMetricUnit](../apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlengthmetricunit)的设置而变化；如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetCurrentLocalY()

```c
float OH_ArkUI_PointerEvent_GetCurrentLocalY(const ArkUI_UIInputEvent* event)
```

**描述：**


从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)（如触摸事件、鼠标事件、轴事件）中根据实时位置获取相对于当前组件左上角的Y坐标。

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件相对于当前组件左上角的Y坐标；默认单位为px，单位可跟随[setLengthMetricUnit](../apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlengthmetricunit)的设置而变化；如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetCurrentLocalYByIndex()

```c
float OH_ArkUI_PointerEvent_GetCurrentLocalYByIndex(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)（如触摸事件、鼠标事件、轴事件）中根据实时位置获取特定接触点相对于当前组件左上角的Y坐标。

所有类型事件，若传入的索引值小于0时为非法值。

对于鼠标和轴事件，当索引值非0时为非法值。

对于触摸事件，根据给定的索引获取特定接触点相对于当前组件左上角的Y坐标。

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回特定接触点相对于当前组件左上角的Y坐标；默认单位为px，单位可跟随[setLengthMetricUnit](../apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setlengthmetricunit)的设置而变化；如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetWindowX()

```c
float OH_ArkUI_PointerEvent_GetWindowX(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件相对于当前应用窗口左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetWindowXByIndex()

```c
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
| float | 返回指向性输入事件中特定接触点相对于当前应用窗口左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetWindowY()

```c
float OH_ArkUI_PointerEvent_GetWindowY(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件相对于当前应用窗口左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetWindowYByIndex()

```c
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
| float | 返回指向性输入事件中特定接触点相对于当前应用窗口左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetDisplayX()

```c
float OH_ArkUI_PointerEvent_GetDisplayX(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件相对于当前屏幕左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetDisplayXByIndex()

```c
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
| float | 返回指向性输入事件中特定接触点相对于当前屏幕左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetDisplayY()

```c
float OH_ArkUI_PointerEvent_GetDisplayY(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件相对于当前屏幕左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetDisplayYByIndex()

```c
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
| float | 返回指向性输入事件中特定接触点相对于当前屏幕左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetGlobalDisplayX()

```c
float OH_ArkUI_PointerEvent_GetGlobalDisplayX(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的X坐标。只能从[ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)事件中获取位置信息。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回相对于全局显示的X坐标，单位为px。如果发生任何参数错误，例如传递的一个事件没有位置信息，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetGlobalDisplayXByIndex()

```c
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
| float | 返回指向性输入事件中特定接触点相对于全局显示的X坐标，单位为px。如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetGlobalDisplayY()

```c
float OH_ArkUI_PointerEvent_GetGlobalDisplayY(const ArkUI_UIInputEvent* event)
```

**描述：**


从指向性输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于全局显示的Y坐标。只能从[ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)事件中获取位置信息。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回相对于全局显示的Y坐标，单位为px。如果发生任何参数错误，例如传递的一个事件没有位置信息，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetGlobalDisplayYByIndex()

```c
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
| float | 返回相对于全局显示的Y坐标，单位为px。如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetPressure()

```c
float OH_ArkUI_PointerEvent_GetPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取触屏压力。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件产生的触屏压力。取值范围为[0, 1]，压感大小与数值正相关。如果参数异常则返回默认值0.0f。在部分设备中，由于设备的硬件参数配置不同，可能会返回大于1的值。 |

### OH_ArkUI_PointerEvent_GetTiltX()

```c
float OH_ArkUI_PointerEvent_GetTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取相对YZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向右倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件中相对YZ平面的角度。 |

### OH_ArkUI_PointerEvent_GetTiltY()

```c
float OH_ArkUI_PointerEvent_GetTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取相对XZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向下倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回当前指向性输入事件中相对XZ平面的角度。 |

### OH_ArkUI_PointerEvent_GetRollAngle()

```c
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
| int32_t | 错误码。<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_PointerEvent_GetTouchAreaWidth()

```c
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
| float | 返回当前指向性输入事件中触屏区域的宽度，单位为px。 |

### OH_ArkUI_PointerEvent_GetTouchAreaHeight()

```c
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
| float | 返回当前指向性输入事件中触屏区域的高度，单位为px。 |

### OH_ArkUI_PointerEvent_GetInteractionHand()

```c
int32_t OH_ArkUI_PointerEvent_GetInteractionHand(const ArkUI_UIInputEvent *event, ArkUI_InteractionHand *hand)
```

**描述：**


获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。该值并非在按下时就能实时获取，在系统完成结果推断之前，皆默认返回NONE，因此请不要过度依赖该接口返回的结果。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md) *event | 表示指向当前UI输入事件的指针。 |
| [ArkUI_InteractionHand](capi-ui-input-event-h.md#arkui_interactionhand) *hand | 表示触摸点是左手还是右手。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果。<br> 如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br> 如果发生参数异常，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_GetInteractionHandByIndex()

```c
int32_t OH_ArkUI_PointerEvent_GetInteractionHandByIndex(const ArkUI_UIInputEvent *event, int32_t pointerIndex, ArkUI_InteractionHand *hand)
```

**描述：**


获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。该值并非在按下时就能实时获取，在系统完成结果推断之前，皆默认返回NONE，因此请不要过度依赖该接口返回的结果。

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
| int32_t | 返回结果。<br> 如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br> 如果发生参数异常，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_GetHistorySize()

```c
uint32_t OH_ArkUI_PointerEvent_GetHistorySize(const ArkUI_UIInputEvent* event)
```

**描述：**


从[指向性输入事件](../../ui/arkts-interaction-capability-overview.md#指向性事件)中获取历史事件数量。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。历史事件为此次事件与上一次事件之间发生的原始事件，仅在指向性输入事件的移动阶段（即触摸移动或鼠标移动）中适用，在其他状态中调用返回默认值0。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

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

```c
int64_t OH_ArkUI_PointerEvent_GetHistoryEventTime(const ArkUI_UIInputEvent* event, uint32_t historyIndex)
```

**描述：**


从指向性输入事件中获取历史事件发生的时间。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回UI输入事件发生的时间，单位为ns。如果参数异常则返回0。 |

### OH_ArkUI_PointerEvent_GetHistoryPointerCount()

```c
uint32_t OH_ArkUI_PointerEvent_GetHistoryPointerCount(const ArkUI_UIInputEvent* event, uint32_t historyIndex)
```

**描述：**


从指向性输入事件中获取特定历史事件中多点触控的接触点数量。本接口支持的指向性输入事件仅包含触摸事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 特定历史事件中多点触控的接触点数量。 |

### OH_ArkUI_PointerEvent_GetHistoryPointerId()

```c
int32_t OH_ArkUI_PointerEvent_GetHistoryPointerId(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件的历史点中获取多点触控的接触点标识。本接口支持的指向性输入事件仅包含触摸事件。返回事件发生时，事件触点的唯一标识符，用于区分同类输入设备的多点触控信息。其数值没有除标识触点外的其他含义。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回特定历史事件中的特定接触点标识。 |

### OH_ArkUI_PointerEvent_GetHistoryX()

```c
float OH_ArkUI_PointerEvent_GetHistoryX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件中获取特定历史事件中特定接触点相对于当前组件左上角的X坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回在指向性输入事件中，特定历史事件内特定接触点相对于当前组件左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryY()

```c
float OH_ArkUI_PointerEvent_GetHistoryY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件中获取特定历史事件中特定接触点相对于当前组件左上角的Y坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回在指向性输入事件中，特定历史事件内特定接触点相对于当前组件左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryWindowX()

```c
float OH_ArkUI_PointerEvent_GetHistoryWindowX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件中获取特定历史事件中特定接触点相对于当前应用窗口左上角的X坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回在指向性输入事件中，特定历史事件内特定接触点相对于当前应用窗口左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryWindowY()

```c
float OH_ArkUI_PointerEvent_GetHistoryWindowY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件中获取特定历史事件中特定接触点相对于当前应用窗口左上角的Y坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回在指向性输入事件中，特定历史事件内特定接触点相对于当前应用窗口左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryDisplayX()

```c
float OH_ArkUI_PointerEvent_GetHistoryDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件中获取特定历史事件中特定接触点相对于当前屏幕左上角的X坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回在指向性输入事件中，特定历史事件内特定接触点相对于当前屏幕左上角的X坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryDisplayY()

```c
float OH_ArkUI_PointerEvent_GetHistoryDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件中获取特定历史事件中特定接触点相对于当前屏幕左上角的Y坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 12开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| uint32_t pointerIndex | 表示多点触控数据列表的序号。 |
| uint32_t historyIndex | 表示历史事件数据列表的序号，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回在指向性输入事件中，特定历史事件内特定接触点相对于当前屏幕左上角的Y坐标，单位为px。如果参数异常则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX()

```c
float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从给定指针索引和历史记录索引的指向性输入事件中获取历史事件中相对于全局显示的特定触摸点的X坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。只能从指针事件中获取位置信息，对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 20开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

**起始版本：** 20


**参数：**

| 参数项 | 描述                                                                                                                   |
| -- |----------------------------------------------------------------------------------------------------------------------|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。                                                                                                     |
| uint32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。有效值范围[0, [OH_ArkUI_PointerEvent_GetPointerCount()](#oh_arkui_pointerevent_getpointercount) - 1] |
| uint32_t historyIndex | 表示要返回的历史值，必须小于[OH_ArkUI_PointerEvent_GetHistorySize](capi-ui-input-event-h.md#oh_arkui_pointerevent_gethistorysize)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回在指向性输入事件中，特定历史事件内特定接触点相对于全局显示的X坐标，单位为px。如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY()

```c
float OH_ArkUI_PointerEvent_GetHistoryGlobalDisplayY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从给定指针索引和历史记录索引的指向性输入事件中获取历史事件中相对于全局显示的特定触摸点的Y坐标。本接口支持的指向性输入事件仅包含触摸事件、鼠标事件。只能从指针事件中获取位置信息，对于鼠标事件，当给定的pointerIndex大于0时，始终返回默认值0.0f。从API version 20开始支持触摸事件，从API version 26.0.0开始支持鼠标事件。

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
| float | 返回在指向性输入事件中，特定历史事件内特定接触点相对于全局显示的Y坐标，单位为px。如果发生任何参数错误，则返回0.0f。 |

### OH_ArkUI_PointerEvent_GetHistoryPressure()

```c
float OH_ArkUI_PointerEvent_GetHistoryPressure(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取特定历史事件中的触屏压力。

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
| float | 返回当前指向性输入事件产生的触屏压力。取值范围为[0, 1]，压感大小与数值正相关。如果参数异常则返回默认值0.0f。在部分设备中，由于设备的硬件参数配置不同，可能会返回大于1的值。 |

### OH_ArkUI_PointerEvent_GetHistoryTiltX()

```c
float OH_ArkUI_PointerEvent_GetHistoryTiltX(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取特定历史事件中的相对YZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向右倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。

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
| float | 返回当前指向性输入事件中相对YZ平面的角度。 |

### OH_ArkUI_PointerEvent_GetHistoryTiltY()

```c
float OH_ArkUI_PointerEvent_GetHistoryTiltY(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取特定历史事件中的相对XZ平面的角度，取值的范围[-90, 90]，单位为deg，其中正值是向下倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。

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
| float | 返回当前指向性输入事件中相对XZ平面的角度。 |

### OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth()

```c
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取特定历史事件中的触屏区域的宽度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。

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
| float | 返回当前指向性输入事件中触屏区域的宽度，单位为px。 |

### OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight()

```c
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight(const ArkUI_UIInputEvent* event, uint32_t pointerIndex, uint32_t historyIndex)
```

**描述：**


从指向性输入事件（如触摸事件）中获取特定历史事件中的触屏区域的高度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。

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
| float | 返回当前指向性输入事件中触屏区域的高度，单位为px。 |

### OH_ArkUI_AxisEvent_GetVerticalAxisValue()

```c
double OH_ArkUI_AxisEvent_GetVerticalAxisValue(const ArkUI_UIInputEvent* event)
```

**描述：**

获取当前轴事件的垂直滚动轴的值。该值通常由鼠标滚轮或用户在触控板上双指竖向滑动产生。

当通过鼠标滚轮触发时：
1. 上报的数值单位为角度，表示单次滚动角度增量，非滚动总量。
2. 上报的数值已与用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](#oh_arkui_axisevent_getscrollstep)叠加运算。
3. 数值的正负代表方向，向前滚动鼠标滚轮时上报数值为负数，向后滚动鼠标滚轮时上报数值为正数。

当通过触控板双指竖向滑动触发时：
1. 上报的数值单位为px，表示单次滚动增量，非滚动总量。
2. 上报的数值不受用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](#oh_arkui_axisevent_getscrollstep)影响。
3. 数值的正负代表方向，双指从上往下滑动时上报数值为负数，双指从下往上滑动时上报数值为正数。
4. 方向会受系统设置中“自然滚动”配置的影响。

通常情况下，垂直滚动轴事件只能驱动竖向的滑动手势响应。但当鼠标指针下命中的可滑动手势里可响应方向一致时，垂直滚动轴事件可以驱动这些滑动手势得到响应，即使这些手势所定义的方向是横向的。


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

```c
double OH_ArkUI_AxisEvent_GetHorizontalAxisValue(const ArkUI_UIInputEvent* event)
```

**描述：**


获取当前轴事件的水平滚动轴的值，该值通过在触控板上双指横向滑动产生。

1. 上报的数值单位为px，表示单次滚动增量，非滚动总量。
2. 上报的数值不受用户配置的放大系数[OH_ArkUI_AxisEvent_GetScrollStep](capi-ui-input-event-h.md#oh_arkui_axisevent_getscrollstep)影响。
3. 数值的正负代表方向，双指从左往右滑动时上报数值为负数，双指从右往左滑动时上报数值为正数。
4. 方向会受系统设置中“自然滚动”配置的影响。

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

```c
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

```c
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
| int32_t | 返回当前轴事件的操作类型，取值可参考[anonymous7](#anonymous7)。当输入非轴事件时，默认返回0。 |

### OH_ArkUI_AxisEvent_HasAxis()

```c
int32_t OH_ArkUI_AxisEvent_HasAxis(const ArkUI_UIInputEvent* event, int32_t axis)
```

**描述：**


检测此轴事件是否包含指定的轴类型。

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| int32_t axis | 表示轴事件的轴类型[UI_AXIS_TYPE](#anonymous8)。 |

**返回值：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回此轴事件是否包含指定的轴类型。返回true表示包含指定的轴类型，返回false表示不包含指定的轴类型。 |

### OH_ArkUI_PointerEvent_SetInterceptHitTestMode()

```c
int32_t OH_ArkUI_PointerEvent_SetInterceptHitTestMode(const ArkUI_UIInputEvent* event, HitTestMode mode)
```

**描述：**


配置触摸测试模式。仅适用于接收基础事件的场景，如使用NODE_ON_TOUCH接收触摸事件场景。对于通过[OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent)接口从一个手势事件中获取到的ArkUI_UIInputEvent对象，无法使用该接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| [HitTestMode](capi-ui-input-event-h.md#hittestmode) mode | 指定触摸测试模式，参数类型[HitTestMode](capi-ui-input-event-h.md#hittestmode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回触摸测试模式配置结果的状态代码。返回0表示配置成功，返回非0表示配置失败。 |

### OH_ArkUI_MouseEvent_GetMouseButton()

```c
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
| int32_t | 返回鼠标按键类型，取值由[anonymous5](#anonymous5)枚举定义，但在非鼠标事件中调用时返回值为-1。 |

### OH_ArkUI_MouseEvent_GetMouseAction()

```c
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
| int32_t | 返回鼠标动作类型，取值由[anonymous4](#anonymous4)枚举定义，但在非鼠标事件中调用时返回值为-1。 |

### OH_ArkUI_PointerEvent_SetStopPropagation()

```c
int32_t OH_ArkUI_PointerEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)
```

**描述：**


设置是否阻止事件冒泡。仅适用于接收基础事件的场景，如使用NODE_ON_TOUCH接收触摸事件场景，不适用于轴事件。对于通过[OH_ArkUI_GestureEvent_GetRawInputEvent](capi-native-gesture-h.md#oh_arkui_gestureevent_getrawinputevent)接口从一个手势事件中获取到的ArkUI_UIInputEvent对象，无法使用该接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| bool stopPropagation | 表示是否阻止事件冒泡。true表示阻止事件冒泡，false表示不阻止事件冒泡。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回执行的状态代码。返回0表示设置成功，如果返回401，表示返回失败，可能的原因是参数异常，例如event是一个空指针，请检查event是否为空并传入有效的UI输入事件指针。 |

### OH_ArkUI_UIInputEvent_GetDeviceId()

```c
int32_t OH_ArkUI_UIInputEvent_GetDeviceId(const ArkUI_UIInputEvent* event)
```

**描述：**


获取当前UI输入事件的设备ID。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 当前UI输入事件的设备ID。 |

### OH_ArkUI_UIInputEvent_GetPressedKeys()

```c
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
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 内存分配不足。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_FocusAxisEvent_GetAxisValue()

```c
double OH_ArkUI_FocusAxisEvent_GetAxisValue(const ArkUI_UIInputEvent* event, int32_t axis)
```

**描述：**


获取焦点轴事件的轴值。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t axis | 焦点轴事件的轴类型，取值可参考[anonymous6](#anonymous6)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 焦点轴事件的轴值，如果参数异常则返回0.0。 |

### OH_ArkUI_FocusAxisEvent_SetStopPropagation()

```c
int32_t OH_ArkUI_FocusAxisEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)
```

**描述：**


设置是否阻止焦点轴事件冒泡，适用于组件已处理焦点轴事件后，不希望该事件继续传递给父组件或其他祖先组件的场景。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | 表示指向当前UI输入事件的指针。 |
| bool stopPropagation | 表示是否阻止事件冒泡。true表示阻止事件冒泡，false表示不阻止事件冒泡。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 参数异常。 |

### OH_ArkUI_UIInputEvent_GetModifierKeyStates()

```c
int32_t OH_ArkUI_UIInputEvent_GetModifierKeyStates(const ArkUI_UIInputEvent* event, uint64_t* keys)
```

**描述：**


获取UI输入事件的修饰键状态。该接口会通过keys传出当前事件发生时所有修饰键的状态，你可以通过与[ArkUI_ModifierKeyName](capi-ui-input-event-h.md#arkui_modifierkeyname)中定义的修饰键类型进行位计算操作获取哪些键处于按下状态。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| uint64_t* keys | 返回当前处于按下状态的修饰键组合，应用可通过位运算进行判断。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AxisEvent_SetPropagation()

```c
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
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 参数异常。 |

### OH_ArkUI_AxisEvent_GetScrollStep()

```c
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
| int32_t | 返回鼠标滚轮轴滚动步长配置。在非鼠标事件返回默认值0。 |

### OH_ArkUI_UIInputEvent_GetEventTargetWidth()

```c
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
| float | 返回事件命中的组件的宽度，单位为px；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetHeight()

```c
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
| float | 返回事件命中的组件的高度，单位为px；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetPositionX()

```c
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
| float | 返回事件命中的组件的X坐标，单位为px；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetPositionY()

```c
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
| float | 返回事件命中的组件的Y坐标，单位为px；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX()

```c
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
| float | 返回事件命中的组件的全局X坐标，单位为px；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY()

```c
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
| float | 返回事件命中的组件的全局Y坐标，单位为px；如果发生任何参数错误，则返回 0.0f。 |

### OH_ArkUI_PointerEvent_GetPressedTimeByIndex()

```c
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

```c
float OH_ArkUI_MouseEvent_GetRawDeltaX(const ArkUI_UIInputEvent* event)
```

**描述：**


获取鼠标设备在二维平面X轴的移动增量。其数值为鼠标硬件的原始移动数据，使用物理世界中鼠标移动的距离单位进行表示。上报数值由硬件本身决定，并非屏幕的物理/逻辑像素。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回鼠标设备在二维平面X轴的移动增量，使用物理世界中鼠标移动的距离单位进行表示；如果发生任何参数错误，则返回0.0f。<br>**说明：** API版本26.0.0之前，返回值并非鼠标硬件的原始移动数据，而是原始数据缩小了X倍，X为系统的显示大小比例。API版本26.0.0开始，返回值为鼠标硬件的原始移动数据。 |

### OH_ArkUI_MouseEvent_GetRawDeltaY()

```c
float OH_ArkUI_MouseEvent_GetRawDeltaY(const ArkUI_UIInputEvent* event)
```

**描述：**


获取鼠标设备在二维平面Y轴的移动增量。其数值为鼠标硬件的原始移动数据，使用物理世界中鼠标移动的距离单位进行表示。上报数值由硬件本身决定，并非屏幕的物理/逻辑像素。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回鼠标设备在二维平面Y轴的移动增量，使用物理世界中鼠标移动的距离单位进行表示；如果发生任何参数错误，则返回0.0f。<br>**说明：** API版本26.0.0之前，返回值并非鼠标硬件的原始移动数据，而是原始数据缩小了X倍，X为系统的显示大小比例。API版本26.0.0开始，返回值为鼠标硬件的原始移动数据。 |

### OH_ArkUI_MouseEvent_GetPressedButtons()

```c
int32_t OH_ArkUI_MouseEvent_GetPressedButtons(const ArkUI_UIInputEvent* event, int32_t* pressedButtons, int32_t* length)
```

**描述：**


从鼠标事件中获取按下的按键。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t* pressedButtons | 指示按下按键的列表。需要先创建一个int数组，用来储存按下的按键，按键的值请参考[anonymous5](#anonymous5)。 |
| int32_t* length | 指示列表数组的总长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果传入的缓冲区大小异常，则返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_UIInputEvent_GetTargetDisplayId()

```c
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

```c
bool OH_ArkUI_HoverEvent_IsHovered(const ArkUI_UIInputEvent* event)
```

**描述：**


获取鼠标是否悬浮在当前组件上。

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

```c
int32_t OH_ArkUI_PointerEvent_CreateClonedEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)
```

**描述：**


基于原始事件指针创建克隆事件指针。仅对触摸事件有效。调用成功后，应在克隆事件使用完毕后调用OH_ArkUI_PointerEvent_DestroyClonedEvent()销毁该克隆事件指针，避免资源未释放。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)** clonedEvent | ArkUI_UIInputEvent克隆事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_DestroyClonedEvent()

```c
int32_t OH_ArkUI_PointerEvent_DestroyClonedEvent(const ArkUI_UIInputEvent* event)
```

**描述：**


销毁由OH_ArkUI_PointerEvent_CreateClonedEvent()创建的克隆事件指针。克隆事件使用完毕后应调用该接口释放资源。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_SetClonedEventLocalPosition()

```c
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPosition(const ArkUI_UIInputEvent* event, float x, float y)
```

**描述：**


设置指向性克隆事件相对于当前组件左上角的X坐标和Y坐标。该接口应在调用OH_ArkUI_PointerEvent_CreateClonedEvent()创建克隆事件后使用；同系列SetClonedEvent接口均仅适用于克隆事件。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 当前指向性输入事件相对于当前组件左上角的X坐标，单位为px。 |
| float y | 当前指向性输入事件相对于当前组件左上角的Y坐标，单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex()

```c
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)
```

**描述：**


设置克隆指向性事件特定接触点相对于当前组件左上角的X坐标和Y坐标。只有通过[OH_ArkUI_PointerEvent_CreateClonedEvent](#oh_arkui_pointerevent_createclonedevent)接口创建的ArkUI_UIInputEvent克隆事件指针才能使用此接口。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 当前指向性输入事件相对于当前组件左上角的X坐标，单位为px。 |
| float y | 当前指向性输入事件相对于当前组件左上角的Y坐标，单位为px。 |
| int32_t pointerIndex | 表示多点触控数据列表中的序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_SetClonedEventActionType()

```c
int32_t OH_ArkUI_PointerEvent_SetClonedEventActionType(const ArkUI_UIInputEvent* event, int32_t actionType)
```

**描述：**


设置当前带有指向性的克隆输入事件的事件类型。只有通过[OH_ArkUI_PointerEvent_CreateClonedEvent](#oh_arkui_pointerevent_createclonedevent)接口创建的ArkUI_UIInputEvent克隆事件指针才能使用此接口。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t actionType | ArkUI_UIInputEvent克隆事件类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId()

```c
int32_t OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId(const ArkUI_UIInputEvent* event, int32_t fingerId)
```

**描述：**


设置当前带有指向性的克隆输入事件的触摸点ID。只有通过[OH_ArkUI_PointerEvent_CreateClonedEvent](#oh_arkui_pointerevent_createclonedevent)接口创建的ArkUI_UIInputEvent克隆事件指针才能使用此接口。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t fingerId | 触发当前事件指针的触摸点ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex()

```c
int32_t OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex(const ArkUI_UIInputEvent* event, int32_t fingerId, int32_t pointerIndex)
```

**描述：**


设置带有指向性的克隆输入事件特定接触点的触摸点ID。只有通过[OH_ArkUI_PointerEvent_CreateClonedEvent](#oh_arkui_pointerevent_createclonedevent)接口创建的ArkUI_UIInputEvent克隆事件指针才能使用此接口。

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
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_PostClonedEvent()

```c
int32_t OH_ArkUI_PointerEvent_PostClonedEvent(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event)
```

**描述：**


转发克隆事件到特定节点。使用该接口前应先调用OH_ArkUI_PointerEvent_CreateClonedEvent()创建克隆事件，并可按需调用OH_ArkUI_PointerEvent_SetClonedEventLocalPosition()等接口设置事件属性；克隆事件使用完毕后应调用OH_ArkUI_PointerEvent_DestroyClonedEvent()销毁。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 目标节点。 |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果组件状态异常，则返回[ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果未命中可响应事件的组件，则返回[ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

### OH_ArkUI_PointerEvent_CreateClonedPointerEvent()

```c
ArkUI_ErrorCode OH_ArkUI_PointerEvent_CreateClonedPointerEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)
```

**描述：**


创建指定事件的克隆事件。该接口适用于触摸事件、鼠标事件和轴事件。调用成功后，可使用OH_ArkUI_ClonedEvent_SetXXX系列接口设置克隆事件属性，使用完毕后应调用OH_ArkUI_PointerEvent_DestroyClonedPointerEvent()销毁该克隆事件，避免资源未释放。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)** clonedEvent | ArkUI_UIInputEvent克隆事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_PointerEvent_CreatePointerEvent()

```c
ArkUI_ErrorCode OH_ArkUI_PointerEvent_CreatePointerEvent(ArkUI_UIInputEvent** event, ArkUI_UIInputEvent_Type type)
```

**描述：**


创建新事件，不克隆现有事件。该接口适用于触摸事件、鼠标事件和轴事件。调用成功后，可使用OH_ArkUI_ClonedEvent_SetXXX系列接口设置事件属性，使用完毕后应调用OH_ArkUI_PointerEvent_DestroyClonedPointerEvent()销毁该事件，避免资源未释放。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)** event | 指向新的ArkUI_UIInputEvent对象的指针。 |
| [ArkUI_UIInputEvent_Type](#arkui_uiinputevent_type) type | ArkUI_UIInputEvent的事件类型。支持取值[ARKUI_UIINPUTEVENT_TYPE_TOUCH](#arkui_uiinputevent_type)、[ARKUI_UIINPUTEVENT_TYPE_AXIS](#arkui_uiinputevent_type)和[ARKUI_UIINPUTEVENT_TYPE_MOUSE](#arkui_uiinputevent_type)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_PointerEvent_DestroyClonedPointerEvent()

```c
ArkUI_ErrorCode OH_ArkUI_PointerEvent_DestroyClonedPointerEvent(const ArkUI_UIInputEvent* event)
```

**描述：**


销毁克隆事件指针。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetActionType()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetActionType(const ArkUI_UIInputEvent* event, int32_t type)
```

**描述：**


设置克隆事件的动作类型。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t type | 克隆事件的类型，包括触摸事件的[UI_TOUCH_EVENT_ACTION](#anonymous1)，鼠标事件的[UI_MOUSE_EVENT_ACTION](#anonymous4)，轴事件的[UI_AXIS_EVENT_ACTION](#anonymous7)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetSourceType()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetSourceType(const ArkUI_UIInputEvent* event, int32_t sourceType)
```

**描述：**


设置克隆事件的源类型。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t sourceType | 克隆事件的源类型。取值范围为[0,5]的整数，其中0表示未知，1表示鼠标，2表示触屏，4表示键盘，5表示手柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetToolType()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetToolType(const ArkUI_UIInputEvent* event, int32_t toolType)
```

**描述：**


设置克隆事件的工具类型。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t toolType | 克隆事件的工具类型。由[UI_INPUT_EVENT_TOOL_TYPE](#anonymous2)枚举定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetPressure()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressure(const ArkUI_UIInputEvent* event, float pressure)
```

**描述：**


设置克隆事件应用于触摸屏的压力。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float pressure | 应用于触摸屏的压力，取值范围为[0,1]中的任意数值，部分设备中可能大于1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetPressureByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressureByIndex(const ArkUI_UIInputEvent* event, float pressure, int32_t pointerIndex)
```

**描述：**


设置克隆事件指定触摸点应用于触摸屏的压力。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float pressure | 应用于触摸屏的压力，取值范围为[0,1]中的任意数值，部分设备中可能大于1。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetEventTime()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetEventTime(const ArkUI_UIInputEvent* event, int64_t timestamp)
```

**描述：**


设置克隆UI输入事件发生的时间。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int64_t timestamp | 克隆UI输入事件发生的时间，单位为ns。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetDeviceId()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetDeviceId(const ArkUI_UIInputEvent* event, int32_t deviceId)
```

**描述：**


设置触发克隆UI输入事件的设备ID。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t deviceId | 触发克隆UI输入事件的设备ID，可用[OH_ArkUI_UIInputEvent_GetDeviceId](#oh_arkui_uiinputevent_getdeviceid)接口获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetTargetDisplayId()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetTargetDisplayId(const ArkUI_UIInputEvent* event, int32_t targetDisplayId)
```

**描述：**


设置克隆UI输入事件发生的屏幕ID。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t targetDisplayId | 克隆UI输入事件发生的屏幕ID，可用[OH_ArkUI_UIInputEvent_GetTargetDisplayId](#oh_arkui_uiinputevent_gettargetdisplayid)接口获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetChangedFingerId()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedFingerId(const ArkUI_UIInputEvent* event, int32_t fingerId)
```

**描述：**


设置克隆指针事件的触摸点ID。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t fingerId | 触发事件的触摸点ID，可以通过[OH_ArkUI_PointerEvent_GetPointerId](#oh_arkui_pointerevent_getpointerid)接口获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetFingerIdByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetFingerIdByIndex(const ArkUI_UIInputEvent* event, int32_t fingerId, int32_t pointerIndex)
```

**描述：**


设置克隆事件特定接触点的触摸点ID。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t fingerId | 特定接触点的触摸点ID，可以通过[OH_ArkUI_PointerEvent_GetPointerId](#oh_arkui_pointerevent_getpointerid)接口获取。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetChangedWindowPosition()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedWindowPosition(const ArkUI_UIInputEvent* event, float x, float y)
```

**描述：**


设置克隆事件相对于当前窗口左上角的X坐标和Y坐标。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 事件相对于当前窗口左上角的X坐标，单位为px。 |
| float y | 事件相对于当前窗口左上角的Y坐标，单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetWindowPositionByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetWindowPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)
```

**描述：**


设置克隆事件特定接触点相对于当前窗口左上角的X坐标和Y坐标。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 事件相对于当前窗口左上角的X坐标，单位为px。 |
| float y | 事件相对于当前窗口左上角的Y坐标，单位为px。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetChangedScreenPosition()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedScreenPosition(const ArkUI_UIInputEvent* event, float x, float y)
```

**描述：**


设置克隆事件相对于当前屏幕左上角的X坐标和Y坐标。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 事件相对于当前屏幕左上角的X坐标，单位为px。 |
| float y | 事件相对于当前屏幕左上角的Y坐标，单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetScreenPositionByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetScreenPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)
```

**描述：**


设置克隆事件特定接触点相对于当前屏幕左上角的X坐标和Y坐标。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 事件相对于当前屏幕左上角的X坐标，单位为px。 |
| float y | 事件相对于当前屏幕左上角的Y坐标，单位为px。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetChangedGlobalDisplayPosition()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedGlobalDisplayPosition(const ArkUI_UIInputEvent* event, float x, float y)
```

**描述：**


设置克隆事件在[全局坐标系](../../windowmanager/window-terminology.md#global-coordinate-system全局坐标系)的坐标。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 事件相对于全局显示的X坐标，单位为px。 |
| float y | 事件相对于全局显示的Y坐标，单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetGlobalDisplayPositionByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetGlobalDisplayPositionByIndex(const ArkUI_UIInputEvent* event, float x, float y, int32_t pointerIndex)
```

**描述：**


设置克隆事件在[全局坐标系](../../windowmanager/window-terminology.md#global-coordinate-system全局坐标系)的坐标。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float x | 事件相对于全局显示的X坐标，单位为px。 |
| float y | 事件相对于全局显示的Y坐标，单位为px。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetHandleId()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetHandleId(const ArkUI_UIInputEvent* event, int32_t eventHandleId)
```

**描述：**


设置事件处理会话的唯一句柄。该句柄必须用于对该事件的任何进一步操作。对于给定的手指，同一时间只有一个具有此句柄的事件处于活动状态。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t eventHandleId | 事件处理会话的唯一句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetTiltAngle()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetTiltAngle(const ArkUI_UIInputEvent* event, float tiltX, float tiltY)
```

**描述：**


设置克隆事件相对于YZ平面和XZ平面的倾斜角度。tiltX取值范围为[-90, 90]，其中正值表示向右倾斜；tiltY取值范围为[-90, 90]，其中正值表示向下倾斜。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float tiltX | 克隆事件相对于YZ平面的倾斜角度，单位为deg。 |
| float tiltY | 克隆事件相对于XZ平面的倾斜角度，单位为deg。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetRollAngle()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetRollAngle(const ArkUI_UIInputEvent* event, float rollAngle)
```

**描述：**


设置克隆事件触控笔绕Z轴的旋转角度。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float rollAngle | 克隆事件触控笔绕Z轴的旋转角度，单位为deg。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetPressedKeys()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressedKeys(const ArkUI_UIInputEvent* event, int32_t* pressedKeyCodes, int32_t length)
```

**描述：**


设置克隆事件中所有按下的按键。该接口适用于触摸事件、鼠标事件和轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t* pressedKeyCodes | 所有按下的按键键值数组，键值取值为[ArkUI_KeyCode](capi-native-key-event-h.md#arkui_keycode)。 |
| int32_t length | 按下的按键数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetChangedTouchArea()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedTouchArea(const ArkUI_UIInputEvent* event, float width, float height)
```

**描述：**


设置克隆事件的手指接触区域的宽度和高度，该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float width | 克隆事件的接触区域的宽度，单位为px。 |
| float height | 克隆事件的接触区域的高度，单位为px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetTouchAreaByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetTouchAreaByIndex(const ArkUI_UIInputEvent* event, float width, float height, int32_t pointerIndex)
```

**描述：**


设置克隆事件特定接触点的手指接触区域的宽度和高度，该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float width | 克隆事件的接触区域的宽度，单位为px。 |
| float height | 克隆事件的接触区域的高度，单位为px。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetChangedInteractionHand()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetChangedInteractionHand(const ArkUI_UIInputEvent* event, int32_t hand)
```

**描述：**


设置克隆事件是左手或右手触发。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t hand | 触摸点是左手还是右手，[ARKUI_EVENT_HAND_LEFT](#arkui_interactionhand)为左手，[ARKUI_EVENT_HAND_RIGHT](#arkui_interactionhand)为右手。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetInteractionHandByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetInteractionHandByIndex(const ArkUI_UIInputEvent* event, int32_t hand, int32_t pointerIndex)
```

**描述：**


设置克隆事件特定接触点由左手或右手触发。该接口适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t hand | 触摸点是左手还是右手，[ARKUI_EVENT_HAND_LEFT](#arkui_interactionhand)为左手，[ARKUI_EVENT_HAND_RIGHT](#arkui_interactionhand)为右手。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetPressedTimeByIndex()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressedTimeByIndex(const ArkUI_UIInputEvent* event, int64_t pressedTime, int32_t pointerIndex)
```

**描述：**


设置克隆事件指定触摸点的按下时间。该接口仅适用于触摸事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int64_t pressedTime | 指定触摸点的按下时间，单位为ns。 |
| int32_t pointerIndex | 表示多点触控数据列表中目标触控点的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetPinchAxisScaleValue()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPinchAxisScaleValue(const ArkUI_UIInputEvent* event, double pinchAxisScaleValue)
```

**描述：**


设置克隆事件的捏合轴缩放值。该接口仅适用于轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| double pinchAxisScaleValue | 捏合轴的缩放值，取值范围为[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetHorizontalAxisScaleValue()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetHorizontalAxisScaleValue(const ArkUI_UIInputEvent* event, double horizontalAxisScaleValue)
```

**描述：**


设置克隆事件水平滚动轴的值。该接口仅适用于轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| double horizontalAxisScaleValue | 水平滚动轴的值，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetVerticalAxisScaleValue()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetVerticalAxisScaleValue(const ArkUI_UIInputEvent* event, double verticalAxisScaleValue)
```

**描述：**


设置克隆事件垂直滚动轴的值。该接口仅适用于轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| double verticalAxisScaleValue | 垂直滚动轴的值，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetScrollStep()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetScrollStep(const ArkUI_UIInputEvent* event, int32_t scrollStep)
```

**描述：**


设置克隆事件的滚动步长系数。该接口仅适用于轴事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t scrollStep | 克隆事件的滚动步长系数，取值为[0, 65535]的整数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>        如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetMouseButton()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetMouseButton(const ArkUI_UIInputEvent* event, int32_t button)
```

**描述：**


设置克隆事件的按钮类型值。该接口仅适用于鼠标事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| int32_t button | 克隆事件的鼠标按钮类型，取值由[anonymous5](#anonymous5)枚举定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetRawDeltaX()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetRawDeltaX(const ArkUI_UIInputEvent* event, float rawDeltaX)
```

**描述：**


设置鼠标设备在二维平面X轴的移动增量。其数值为鼠标硬件的原始移动数据，使用物理世界中鼠标移动的距离单位进行表示。该接口仅适用于鼠标事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float rawDeltaX | 鼠标位置相对于之前上报的鼠标事件中位置的X轴偏移量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetRawDeltaY()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetRawDeltaY(const ArkUI_UIInputEvent* event, float rawDeltaY)
```

**描述：**


设置鼠标设备在二维平面Y轴的移动增量。其数值为鼠标硬件的原始移动数据，使用物理世界中鼠标移动的距离单位进行表示。该接口仅适用于鼠标事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| float rawDeltaY | 鼠标位置相对于之前上报的鼠标事件中位置的Y轴偏移量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_ClonedEvent_SetPressedButtons()

```c
ArkUI_ErrorCode OH_ArkUI_ClonedEvent_SetPressedButtons(const ArkUI_UIInputEvent* event, const int32_t* pressedButtons, int32_t length)
```

**描述：**


设置克隆事件的按下的按键。该接口仅适用于鼠标事件。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| const int32_t* pressedButtons | 按下的按键数组，按键的值请参考[anonymous5](#anonymous5) |
| int32_t length | 按下的按键数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果事件类型不支持，则返回[ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_PointerEvent_PostClonedEventWithStrategy()

```c
ArkUI_ErrorCode OH_ArkUI_PointerEvent_PostClonedEventWithStrategy(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event, ArkUI_CompetitionStrategy strategy)
```

**描述：**


使用指定的竞争策略将克隆事件发送到特定节点，适用于向目标节点注入克隆事件并需要控制注入事件与目标节点已有手势之间是否竞争的场景。只有通过[OH_ArkUI_PointerEvent_CreateClonedPointerEvent](#oh_arkui_pointerevent_createclonedpointerevent)和[OH_ArkUI_PointerEvent_CreatePointerEvent](#oh_arkui_pointerevent_createpointerevent)接口创建的ArkUI_UIInputEvent对象才能使用此接口。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 目标节点。 |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |
| [ArkUI_CompetitionStrategy](#arkui_competitionstrategy) strategy | 竞争策略，取值为[ArkUI_CompetitionStrategy](#arkui_competitionstrategy)。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果输入的事件指针不是克隆事件指针，则返回[ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果组件状态异常，则返回[ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果未命中可响应事件的组件，则返回[ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_UIInputEvent_GetLatestStatus()

```c
ArkUI_ErrorCode OH_ArkUI_UIInputEvent_GetLatestStatus()
```

**描述：**


调用该方法获取最近一次UIInput相关方法的执行情况。通常情况下不需要使用该方法，仅在调用UIInput相关方法后需要确认最近一次调用是否执行异常时使用。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回最近一次调用UIInput方法产生的结果代码。 |

### OH_ArkUI_UIInputEvent_GetCoastingAxisEvent()

```c
ArkUI_CoastingAxisEvent* OH_ArkUI_UIInputEvent_GetCoastingAxisEvent(ArkUI_UIInputEvent* event)
```
**描述：**

从组件事件中获取惯性滚动轴事件，仅当用户在触摸板上使用双指执行满足系统惯性滚动判定条件的抛滑操作，且指针位置下存在注册了[NODE_ON_COASTING_AXIS_EVENT](capi-native-node-h.md#arkui_nodeeventtype)事件的组件时，才能获取到有效事件。在从[ArkUI_NodeEvent](capi-arkui-nativemodule-arkui-nodeevent.md)对象获取到[ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)对象后调用此方法。

惯性滚动轴事件仅在双指抛滑并离开触控板时触发，因此仅支持触控板。惯性滚动轴事件会在手指离开触控板后，根据抛滑速度产生轴值逐渐衰减的事件。由于刷新频率和性能的影响，当前事件轴值可能高于或低于上一个事件值。在惯性滚动轴事件期间，以下四种行为会中断事件，并立即收到[ARKUI_COASTING_AXIS_EVENT_PHASE_END](#arkui_coastingaxiseventphase)。
1. 手指触摸触控板。
2. 滚动鼠标滚轮。
3. 手指或鼠标点击注册了惯性滚动轴事件的节点。需要注意的是，点击未注册此事件的节点不会产生任何效果。例如，A节点注册了惯性滚动轴事件，当事件发生时，让B节点滚动，但点击B节点不会中断此事件。点击事件的中断行为受[OH_ArkUI_PointerEvent_SetInterceptHitTestMode](#oh_arkui_pointerevent_setintercepthittestmode)的影响。此外，如果用户点击区域存在已收集的可响应惯性滚动轴事件的节点，本次惯性滚动轴事件会被强制终止。

4. 应用休眠（例如最小化、锁屏）。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | ArkUI_UIInputEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CoastingAxisEvent](capi-arkui-nativemodule-arkui-coastingaxisevent.md) | 返回指向惯性滚动轴事件的指针，如果未发生任何惯性滚动轴事件或发生任何参数错误，则返回空指针。|

### OH_ArkUI_CoastingAxisEvent_GetEventTime()

```c
int64_t OH_ArkUI_CoastingAxisEvent_GetEventTime(ArkUI_CoastingAxisEvent* event)
```
**描述：**

获取惯性滚动轴事件发生的时间。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CoastingAxisEvent](capi-arkui-nativemodule-arkui-coastingaxisevent.md)* event | ArkUI_CoastingAxisEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回UI输入事件发生的时间，单位为ns；如果发生任何参数错误则返回0。|

### OH_ArkUI_CoastingAxisEvent_GetPhase()

```c
ArkUI_CoastingAxisEventPhase OH_ArkUI_CoastingAxisEvent_GetPhase(ArkUI_CoastingAxisEvent* event)
```
**描述：**

获取惯性滚动轴事件发生时的滚动阶段。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CoastingAxisEvent](capi-arkui-nativemodule-arkui-coastingaxisevent.md)* event | ArkUI_CoastingAxisEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CoastingAxisEventPhase](#arkui_coastingaxiseventphase) | 返回事件阶段，参见[ArkUI_CoastingAxisEventPhase](#arkui_coastingaxiseventphase)。<br>    如果发生任何参数错误则返回ARKUI_COASTING_AXIS_EVENT_PHASE_NONE。|

### OH_ArkUI_CoastingAxisEvent_GetDeltaY

```c
float OH_ArkUI_CoastingAxisEvent_GetDeltaY(ArkUI_CoastingAxisEvent* event)
```
**描述：**

获取惯性滚动轴事件垂直方向的增量值。单位为px，表示为单次滚动增量，非滚动总量。数值的正负代表方向，双指从上往下滑动时为负数，双指从下往上滑动时为正数。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CoastingAxisEvent](capi-arkui-nativemodule-arkui-coastingaxisevent.md)* event | ArkUI_CoastingAxisEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回Y轴增量值，以px为单位；如果发生任何参数错误则返回0.0f。|

### OH_ArkUI_CoastingAxisEvent_GetDeltaX

```c
float OH_ArkUI_CoastingAxisEvent_GetDeltaX(ArkUI_CoastingAxisEvent* event)
```
**描述：**

获取惯性滚动轴事件水平方向的增量值。单位为px，表示为单次滚动增量，非滚动总量。数值的正负代表方向，双指从左往右滑动时为负数，双指从右往左滑动时为正数。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CoastingAxisEvent](capi-arkui-nativemodule-arkui-coastingaxisevent.md)* event | ArkUI_CoastingAxisEvent事件指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回X轴增量值，以px为单位；如果发生任何参数错误则返回0.0f。|

### OH_ArkUI_CoastingAxisEvent_SetPropagation()

```c
int32_t OH_ArkUI_CoastingAxisEvent_SetPropagation(ArkUI_CoastingAxisEvent* event, bool propagation)
```
**描述：**

设置惯性滚动轴事件是否启用冒泡，默认禁止冒泡；适用于当前组件处理惯性滚动轴事件后，还需要将事件继续传递给祖先组件协同处理滚动效果的场景。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CoastingAxisEvent](capi-arkui-nativemodule-arkui-coastingaxisevent.md)* event | ArkUI_CoastingAxisEvent事件指针。 |
| bool propagation | 是否启用事件冒泡。true表示启用，false表示禁用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         |

### OH_ArkUI_TouchTestInfo_GetTouchTestInfoList

```c
ArkUI_ErrorCode OH_ArkUI_TouchTestInfo_GetTouchTestInfoList(ArkUI_TouchTestInfo* info,
    ArkUI_TouchTestInfoItemArray* array, int32_t* size);
```
**描述：**

获取触摸测试信息中的触摸测试信息项数组。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TouchTestInfo](./capi-arkui-nativemodule-arkui-touchtestinfo.md)* info | 指向触摸测试信息的指针。 |
| [ArkUI_TouchTestInfoItemArray](./capi-arkui-nativemodule-arkui-touchtestinfoitemhandlearray.md)* array | 输出参数，指向用于接收触摸测试信息项数组的指针，数组元素为触摸测试信息项，数组大小通过size参数返回。 |
| int32_t* size | 输出参数，表示array中返回的触摸测试信息项数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| ArkUI_ErrorCode | 返回结果代码。<br>         如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>         |

### OH_ArkUI_TouchTestInfoItem_GetX

```c
float OH_ArkUI_TouchTestInfoItem_GetX(const ArkUI_TouchTestInfoItem* info);
```
**描述：**

从触摸测试信息项中获取相对于子组件左上角的X坐标，单位为px。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TouchTestInfoItem](./capi-arkui-nativemodule-arkui-touchtestinfoitem.md)* info | 指向触摸测试信息项的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 相对于子组件左上角的X坐标，单位为px。若参数错误，返回0.0f。|

### OH_ArkUI_TouchTestInfoItem_GetY

```c
float OH_ArkUI_TouchTestInfoItem_GetY(const ArkUI_TouchTestInfoItem* info);
```
**描述：**

从触摸测试信息项中获取相对于子组件左上角的Y坐标，单位为px。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TouchTestInfoItem](./capi-arkui-nativemodule-arkui-touchtestinfoitem.md)* info | 指向触摸测试信息项的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 相对于子组件左上角的Y坐标，单位为px。若参数错误，返回0.0f。|

### OH_ArkUI_TouchTestInfoItem_GetWindowX

```c
float OH_ArkUI_TouchTestInfoItem_GetWindowX(const ArkUI_TouchTestInfoItem* info);
```
**描述：**

从触摸测试信息项中获取相对于当前应用窗口左上角的X坐标，单位为px。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TouchTestInfoItem](./capi-arkui-nativemodule-arkui-touchtestinfoitem.md)* info | 指向触摸测试信息项的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 相对于当前应用窗口左上角的X坐标，单位为px。若参数错误，返回0.0f。|

### OH_ArkUI_TouchTestInfoItem_GetWindowY

```c
float OH_ArkUI_TouchTestInfoItem_GetWindowY(const ArkUI_TouchTestInfoItem* info);
```
**描述：**

从触摸测试信息项中获取相对于当前应用窗口左上角的Y坐标，单位为px。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TouchTestInfoItem](./capi-arkui-nativemodule-arkui-touchtestinfoitem.md)* info | 指向触摸测试信息项的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 相对于当前应用窗口左上角的Y坐标，单位为px。若参数错误，返回0.0f。|


### OH_ArkUI_TouchTestInfoItem_GetXRelativeToParent

```c
float OH_ArkUI_TouchTestInfoItem_GetXRelativeToParent(const ArkUI_TouchTestInfoItem* info);
```
**描述：**

从触摸测试信息项中获取相对于父组件左上角的X坐标，单位为px。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TouchTestInfoItem](./capi-arkui-nativemodule-arkui-touchtestinfoitem.md)* info | 指向触摸测试信息项的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 相对于父组件左上角的X坐标，单位为px。若参数错误，返回0.0f。|

### OH_ArkUI_TouchTestInfoItem_GetYRelativeToParent

```c
float OH_ArkUI_TouchTestInfoItem_GetYRelativeToParent(const ArkUI_TouchTestInfoItem* info);
```
**描述：**

从触摸测试信息项中获取相对于父组件左上角的Y坐标，单位为px。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TouchTestInfoItem](./capi-arkui-nativemodule-arkui-touchtestinfoitem.md)* info | 指向触摸测试信息项的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 相对于父组件左上角的Y坐标，单位为px。若参数错误，返回0.0f。|

### OH_ArkUI_TouchTestInfoItem_GetChildRect

```c
ArkUI_ErrorCode OH_ArkUI_TouchTestInfoItem_GetChildRect(const ArkUI_TouchTestInfoItem* info, ArkUI_Rect* childRect);
```
**描述：**

从触摸测试信息项中获取子组件的边界矩形信息。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TouchTestInfoItem](./capi-arkui-nativemodule-arkui-touchtestinfoitem.md)* info | 指向触摸测试信息项的指针。 |
| [ArkUI_Rect](./capi-arkui-nativemodule-arkui-rect.md)* childRect | 指向子组件边界矩形的指针，用于存储获取到的边界矩形信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| ArkUI_ErrorCode | 返回结果代码。<br>如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>      |

### OH_ArkUI_TouchTestInfoItem_GetChildId

```c
ArkUI_ErrorCode OH_ArkUI_TouchTestInfoItem_GetChildId(const ArkUI_TouchTestInfoItem* info, char* buffer,
    int32_t bufferSize);
```
**描述：**

从触摸测试信息项中获取子组件的ID。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_TouchTestInfoItem](./capi-arkui-nativemodule-arkui-touchtestinfoitem.md)* info | 指向触摸测试信息项的指针。 |
| char* buffer | 调用者提供的缓冲区，用于接收获取到的子组件ID字符串。 |
| int32_t bufferSize | 缓冲区的大小。 |


**返回：**

| 类型 | 说明 |
| -- | -- |
| ArkUI_ErrorCode | 返回结果代码。<br>如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>如果缓冲区空间不足，则返回[ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_TouchTestInfo_SetTouchResultStrategy

```c
ArkUI_ErrorCode OH_ArkUI_TouchTestInfo_SetTouchResultStrategy(ArkUI_TouchTestInfo* info, ArkUI_TouchTestStrategy strategy);
```
**描述：**

设置触摸测试策略，即组件及其子组件在命中测试过程中的行为方式，适用于自定义触摸命中结果、将触摸事件分发给指定子组件或控制兄弟节点是否继续参与命中测试的场景。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TouchTestInfo](./capi-arkui-nativemodule-arkui-touchtestinfo.md)* info | 指向触摸测试信息的指针。 |
| [ArkUI_TouchTestStrategy](#arkui_touchteststrategy) strategy | 触摸测试策略，定义组件及子组件在命中测试中的行为规则。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| ArkUI_ErrorCode | 返回结果代码。<br>如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_TouchTestInfo_SetTouchResultId

```c
ArkUI_ErrorCode OH_ArkUI_TouchTestInfo_SetTouchResultId(ArkUI_TouchTestInfo* info, const char* id);
```
**描述：**

设置命中测试过程中需要作用的子组件ID，适用于自定义触摸测试结果并希望将触摸事件分发到指定子组件的场景。

**起始版本：** 22

**参数:**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TouchTestInfo](./capi-arkui-nativemodule-arkui-touchtestinfo.md)* info | 指向触摸测试信息的指针。 |
| const char* id | 子组件的ID，指定命中测试中需要作用的目标子组件。 |


**返回：**

| 类型 | 说明 |
| -- | -- |
| ArkUI_ErrorCode | 返回结果代码。<br>如果操作成功，则返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>如果入参错误，则返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。|

### OH_ArkUI_DigitalCrownEvent_GetEventTime()

``` c
int64_t OH_ArkUI_DigitalCrownEvent_GetEventTime(const ArkUI_UIInputEvent* event)
```

**描述：**

获取表冠事件发生的时间。单位为ns。仅适用于入参event里存储的是表冠事件对象的场景。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent*](capi-arkui-eventmodule-arkui-uiinputevent.md) event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回UI输入事件发生的时间，如果参数有误，则返回<b>0</b>。|

### OH_ArkUI_DigitalCrownEvent_GetAngularVelocity()

``` c
double OH_ArkUI_DigitalCrownEvent_GetAngularVelocity(const ArkUI_UIInputEvent* event)
```

**描述：**

获取表冠事件发生的角速度。单位为°/s。仅适用于入参event里存储的是表冠事件对象的场景。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent*](capi-arkui-eventmodule-arkui-uiinputevent.md) event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回UI输入事件发生的角速度，如果参数有误，则返回<b>0.0</b>。|

### OH_ArkUI_DigitalCrownEvent_GetDegree()

``` c
double OH_ArkUI_DigitalCrownEvent_GetDegree(const ArkUI_UIInputEvent* event)
```

**描述：**

获取表冠事件发生的旋转角度。单位为°。仅适用于入参event里存储的是表冠事件对象的场景。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent*](capi-arkui-eventmodule-arkui-uiinputevent.md) event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回UI输入事件发生的旋转角度，如果参数有误，则返回<b>0.0</b>。|

### OH_ArkUI_DigitalCrownEvent_GetAction()

``` c
ArkUI_CrownEvent_Action OH_ArkUI_DigitalCrownEvent_GetAction(const ArkUI_UIInputEvent* event)
```

**描述：**

获取表冠事件发生的阶段。仅适用于入参event里存储的是表冠事件对象的场景。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent*](capi-arkui-eventmodule-arkui-uiinputevent.md) event | 表示指向当前UI输入事件的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CrownEvent_Action](#arkui_crownevent_action)  | 返回UI输入事件发生时旋转表冠的行为。如果入参错误，则返回<b>[ARKUI_CROWNEVENT_ACTION_UNKNOWN](#arkui_crownevent_action)</b>。|

### OH_ArkUI_DigitalCrownEvent_SetStopPropagation()

``` c
ArkUI_ErrorCode OH_ArkUI_DigitalCrownEvent_SetStopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)
```

**描述：**

设置是否阻止事件冒泡。仅适用于入参event里存储的是表冠事件对象的场景。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_UIInputEvent*](capi-arkui-eventmodule-arkui-uiinputevent.md) event | 表示指向当前UI输入事件的指针。 |
|bool stopPropagation|表示是否阻止事件冒泡。true表示阻止事件冒泡，false表示不阻止事件冒泡。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 参数异常。<br>|