# game_pad_event.h
<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @luwy2025-->

## 概述

定义游戏手柄事件的接口。

**引用文件：** <GameControllerKit/game_pad_event.h>

**库：** libohgame_controller.z.so

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**相关模块：** [GameController](capi-gamecontroller.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) | GamePad_ButtonEvent | 定义手柄按键事件。 |
| [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) | GamePad_AxisEvent | 定义手柄轴事件。 |
| [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md) | GamePad_PressedButton | 定义手柄按下的按键。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [GamePad_AxisSourceType](#gamepad_axissourcetype) | GamePad_AxisSourceType | 此枚举定义手柄轴事件来源类型。 |
| [GamePad_Button_ActionType](#gamepad_button_actiontype) | GamePad_Button_ActionType | 此枚举定义手柄按键动作类型。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void(\*GamePad_ButtonInputMonitorCallback)(const struct GamePad_ButtonEvent* buttonEvent)](#gamepad_buttoninputmonitorcallback) | GamePad_ButtonInputMonitorCallback | 定义在按键事件注册监听接口中使用的回调函数。当玩家按下按键时，该回调函数将被调用。 |
| [typedef void(\*GamePad_AxisInputMonitorCallback)(const struct GamePad_AxisEvent* axisEvent)](#gamepad_axisinputmonitorcallback) | GamePad_AxisInputMonitorCallback | 定义在轴事件注册监听接口中使用的回调函数。当玩家操作摇杆时，该回调函数将被调用。 |
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetDeviceId(const struct GamePad_ButtonEvent* buttonEvent, char** deviceId)](#oh_gamepad_buttonevent_getdeviceid) | - | 从按键事件中获取设备ID。 |
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonAction(const struct GamePad_ButtonEvent* buttonEvent, GamePad_Button_ActionType* actionType)](#oh_gamepad_buttonevent_getbuttonaction) | - | 从按键事件中获取按键动作类型。 |
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonCode(const struct GamePad_ButtonEvent* buttonEvent, int32_t* code)](#oh_gamepad_buttonevent_getbuttoncode) | - | 从按键事件中获取按键编码。 |
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonCodeName(const struct GamePad_ButtonEvent* buttonEvent, char** codeName)](#oh_gamepad_buttonevent_getbuttoncodename) | - | 从按键事件中获取按键名称。 |
| [GameController_ErrorCode OH_GamePad_PressedButtons_GetCount(const struct GamePad_ButtonEvent* buttonEvent, int32_t* count)](#oh_gamepad_pressedbuttons_getcount) | - | 从按键事件中获取按下的按键数量。 |
| [GameController_ErrorCode OH_GamePad_PressedButtons_GetButtonInfo(const struct GamePad_ButtonEvent* buttonEvent, const int32_t index, GamePad_PressedButton** pressedButton)](#oh_gamepad_pressedbuttons_getbuttoninfo) | - | 从按键事件中获取指定索引的按键信息。 |
| [GameController_ErrorCode OH_GamePad_DestroyPressedButton(GamePad_PressedButton** pressedButton)](#oh_gamepad_destroypressedbutton) | - | 销毁按下的按键实例。 |
| [GameController_ErrorCode OH_GamePad_PressedButton_GetButtonCode(const struct GamePad_PressedButton* pressedButton, int32_t* code)](#oh_gamepad_pressedbutton_getbuttoncode) | - | 从按下的按键中获取按键编码。 |
| [GameController_ErrorCode OH_GamePad_PressedButton_GetButtonCodeName(const struct GamePad_PressedButton* pressedButton, char** codeName)](#oh_gamepad_pressedbutton_getbuttoncodename) | - | 从按下的按键中获取按键名称。 |
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetActionTime(const struct GamePad_ButtonEvent* buttonEvent, int64_t* actionTime)](#oh_gamepad_buttonevent_getactiontime) | - | 从按键事件中获取动作时间。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetDeviceId(const struct GamePad_AxisEvent* axisEvent, char** deviceId)](#oh_gamepad_axisevent_getdeviceid) | - | 从轴事件中获取设备ID。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetAxisSourceType(const struct GamePad_AxisEvent* axisEvent, GamePad_AxisSourceType* axisSourceType)](#oh_gamepad_axisevent_getaxissourcetype) | - | 从轴事件中获取轴事件来源类型。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetXAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getxaxisvalue) | - | 从轴事件中获取X轴的值。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetYAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getyaxisvalue) | - | 从轴事件中获取Y轴的值。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetZAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getzaxisvalue) | - | 从轴事件中获取Z轴的值。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetRZAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getrzaxisvalue) | - | 从轴事件中获取RZ轴的值。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetHatXAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_gethatxaxisvalue) | - | 从轴事件中获取HatX轴的值。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetHatYAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_gethatyaxisvalue) | - | 从轴事件中获取HatY轴的值。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetBrakeAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getbrakeaxisvalue) | - | 从轴事件中获取Brake轴的值。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetGasAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getgasaxisvalue) | - | 从轴事件中获取Gas轴的值。 |
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetActionTime(const struct GamePad_AxisEvent* axisEvent, int64_t* actionTime)](#oh_gamepad_axisevent_getactiontime) | - | 从轴事件中获取动作时间。 |

## 枚举类型说明

### GamePad_AxisSourceType

```c
enum GamePad_AxisSourceType
```

**描述**

此枚举定义手柄轴事件来源类型。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

| 枚举项 | 描述 |
| -- | -- |
| DPAD = 0 | 轴事件来源于方向按键DPAD。<br>**起始版本：** 21 |
| LEFT_THUMBSTICK = 1 | 轴事件来源于LeftThumbstick。<br>**起始版本：** 21 |
| RIGHT_THUMBSTICK = 2 | 轴事件来源于RightThumbstick。<br>**起始版本：** 21 |
| LEFT_TRIGGER = 3 | 轴事件来源于LeftTrigger。<br>**起始版本：** 21 |
| RIGHT_TRIGGER = 4 | 轴事件来源于RightTrigger。<br>**起始版本：** 21 |

### GamePad_Button_ActionType

```c
enum GamePad_Button_ActionType
```

**描述**

此枚举定义手柄按键动作类型。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

| 枚举项 | 描述 |
| -- | -- |
| DOWN = 0 | 按键按下。<br>**起始版本：** 21 |
| UP = 1 | 按键抬起。<br>**起始版本：** 21 |


## 函数说明

### GamePad_ButtonInputMonitorCallback()

```c
typedef void(*GamePad_ButtonInputMonitorCallback)(const struct GamePad_ButtonEvent* buttonEvent)
```

**描述**

定义在按键事件注册监听接口中使用的回调函数。当玩家按下按键时，该回调函数将被调用。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct GamePad_ButtonEvent* buttonEvent | 输入参数，手柄按键事件[GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)。 |

### GamePad_AxisInputMonitorCallback()

```c
typedef void(*GamePad_AxisInputMonitorCallback)(const struct GamePad_AxisEvent* axisEvent)
```

**描述**

定义在轴事件注册监听接口中使用的回调函数。当玩家操作摇杆时，该回调函数将被调用。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct GamePad_AxisEvent* axisEvent | 输入参数，手柄轴事件[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)。 |

### OH_GamePad_ButtonEvent_GetDeviceId()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetDeviceId(const struct GamePad_ButtonEvent* buttonEvent, char** deviceId)
```

**描述**

从按键事件中获取设备ID。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | 指针指向[GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)实例，不能为空。 |
| char** deviceId | 输出参数，二级指针指向设备ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数buttonEvent或deviceId为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果设备内存不足，返回[GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_ButtonEvent_GetButtonAction()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonAction(const struct GamePad_ButtonEvent* buttonEvent, GamePad_Button_ActionType* actionType)
```

**描述**

从按键事件中获取按键动作类型。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | 指针指向[GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)实例，不能为空。 |
| [GamePad_Button_ActionType](capi-game-pad-event-h.md#gamepad_button_actiontype)* actionType | 输出参数，按键动作类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数buttonEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_ButtonEvent_GetButtonCode()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonCode(const struct GamePad_ButtonEvent* buttonEvent, int32_t* code)
```

**描述**

从按键事件中获取按键编码。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | 指针指向[GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)实例，不能为空。 |
| int32_t* code | 输出参数，按键编码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数buttonEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_ButtonEvent_GetButtonCodeName()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonCodeName(const struct GamePad_ButtonEvent* buttonEvent, char** codeName)
```

**描述**

从按键事件中获取按键名称。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | 指针指向[GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)实例，不能为空。 |
| char** codeName | 输出参数，二级指针指向按键名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数buttonEvent或codeName为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果设备内存不足，返回[GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_PressedButtons_GetCount()

```c
GameController_ErrorCode OH_GamePad_PressedButtons_GetCount(const struct GamePad_ButtonEvent* buttonEvent, int32_t* count)
```

**描述**

从按键事件中获取按下的按键数量。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | 指针指向[GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)实例，不能为空。 |
| int32_t* count | 输出参数，按键数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数buttonEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_PressedButtons_GetButtonInfo()

```c
GameController_ErrorCode OH_GamePad_PressedButtons_GetButtonInfo(const struct GamePad_ButtonEvent* buttonEvent, const int32_t index, GamePad_PressedButton** pressedButton)
```

**描述**

从按键事件中获取指定索引的按键信息。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | 指针指向[GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)实例，不能为空。 |
| const int32_t index | 指定按键索引。 |
| [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)** pressedButton | 输出参数，二级指针指向按下的按键。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数buttonEvent为null，或index小于0或大于等于按键总数，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_DestroyPressedButton()

```c
GameController_ErrorCode OH_GamePad_DestroyPressedButton(GamePad_PressedButton** pressedButton)
```

**描述**

销毁按下的按键实例。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)** pressedButton | 二级指针指向[GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)实例，不能为空。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数pressedButton为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_PressedButton_GetButtonCode()

```c
GameController_ErrorCode OH_GamePad_PressedButton_GetButtonCode(const struct GamePad_PressedButton* pressedButton, int32_t* code)
```

**描述**

从按下的按键中获取按键编码。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)* pressedButton | 指针指向[GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)实例，不能为空。 |
| int32_t* code | 输出参数，按键编码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数pressedButton为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_PressedButton_GetButtonCodeName()

```c
GameController_ErrorCode OH_GamePad_PressedButton_GetButtonCodeName(const struct GamePad_PressedButton* pressedButton, char** codeName)
```

**描述**

从按下的按键中获取按键名称。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)* pressedButton | 指针指向[GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)实例，不能为空。 |
| char** codeName | 输出参数，二级指针指向按键名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数pressedButton或codeName为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果设备内存不足，返回[GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_ButtonEvent_GetActionTime()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetActionTime(const struct GamePad_ButtonEvent* buttonEvent, int64_t* actionTime)
```

**描述**

从按键事件中获取动作时间。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | 指针指向[GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)实例，不能为空。 |
| int64_t* actionTime | 输出参数，动作时间。Unix时间戳，单位：ms。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数buttonEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetDeviceId()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetDeviceId(const struct GamePad_AxisEvent* axisEvent, char** deviceId)
```

**描述**

从轴事件中获取设备ID。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| char** deviceId | 输出参数，二级指针指向设备ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent或deviceId为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果设备内存不足，返回[GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetAxisSourceType()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetAxisSourceType(const struct GamePad_AxisEvent* axisEvent, GamePad_AxisSourceType* axisSourceType)
```

**描述**

从轴事件中获取轴事件来源类型。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| [GamePad_AxisSourceType](capi-game-pad-event-h.md#gamepad_axissourcetype)* axisSourceType | 输出参数，轴事件来源类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetXAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetXAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**描述**

从轴事件中获取X轴的值。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| double* axisValue | 输出参数，轴值。取值范围为[-1.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetYAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetYAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**描述**

从轴事件中获取Y轴的值。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| double* axisValue | 输出参数，轴值。取值范围为[-1.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetZAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetZAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**描述**

从轴事件中获取Z轴的值。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| double* axisValue | 输出参数，轴值。取值范围为[-1.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetRZAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetRZAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**描述**

从轴事件中获取RZ轴的值。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| double* axisValue | 输出参数，轴值。取值范围为[-1.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetHatXAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetHatXAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**描述**

从轴事件中获取HatX轴的值。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| double* axisValue | 输出参数，轴值。取值范围为[-1.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetHatYAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetHatYAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**描述**

从轴事件中获取HatY轴的值。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| double* axisValue | 输出参数，轴值。取值范围为[-1.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetBrakeAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetBrakeAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**描述**

从轴事件中获取Brake轴的值。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| double* axisValue | 输出参数，轴值。取值范围为[-1.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetGasAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetGasAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**描述**

从轴事件中获取Gas轴的值。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| double* axisValue | 输出参数，轴值。取值范围为[-1.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GamePad_AxisEvent_GetActionTime()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetActionTime(const struct GamePad_AxisEvent* axisEvent, int64_t* actionTime)
```

**描述**

从轴事件中获取动作时间。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | 指针指向[GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)实例，不能为空。 |
| int64_t* actionTime | 输出参数，动作时间。Unix时间戳，单位：ms。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数axisEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |


