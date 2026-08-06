# game_pad_event.h

<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @luwy2025-->
<!-- md-trans-meta sourceCommit=77c72b42e08d6a4d9b4548171e0024968c7d2a99 translatedAt=2026-07-30T08:27:46.078Z pushedAt=2026-07-30T08:57:31.549Z -->

## Overview

Defines APIs for gamepad events.

**File to include:** <GameControllerKit/game_pad_event.h>

**Library:** libohgame_controller.z.so

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Related module:** [GameController](capi-gamecontroller.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) | GamePad_ButtonEvent | Defines gamepad button events.|
| [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) | GamePad_AxisEvent | Defines gamepad axis events.|
| [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md) | GamePad_PressedButton | Defines pressed buttons.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [GamePad_AxisSourceType](#gamepad_axissourcetype) | GamePad_AxisSourceType | Defines source types of gamepad axis events.|
| [GamePad_Button_ActionType](#gamepad_button_actiontype) | GamePad_Button_ActionType | Defines action types of gamepad button events.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void(\*GamePad_ButtonInputMonitorCallback)(const struct GamePad_ButtonEvent* buttonEvent)](#gamepad_buttoninputmonitorcallback) | GamePad_ButtonInputMonitorCallback | Defines the callback function used by the button event listener registration API. The callback is triggered when a player presses a button.|
| [typedef void(\*GamePad_AxisInputMonitorCallback)(const struct GamePad_AxisEvent* axisEvent)](#gamepad_axisinputmonitorcallback) | GamePad_AxisInputMonitorCallback | Defines the callback function used by the axis event listener registration API. The callback is triggered when a player operates a joystick.|
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetDeviceId(const struct GamePad_ButtonEvent* buttonEvent, char** deviceId)](#oh_gamepad_buttonevent_getdeviceid) | - | Obtains the device ID from a button event.|
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonAction(const struct GamePad_ButtonEvent* buttonEvent, GamePad_Button_ActionType* actionType)](#oh_gamepad_buttonevent_getbuttonaction) | - | Obtains the button action type from a button event.|
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonCode(const struct GamePad_ButtonEvent* buttonEvent, int32_t* code)](#oh_gamepad_buttonevent_getbuttoncode) | - | Obtains the button code from a button event.|
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonCodeName(const struct GamePad_ButtonEvent* buttonEvent, char** codeName)](#oh_gamepad_buttonevent_getbuttoncodename) | - | Obtains the button name from a button event.|
| [GameController_ErrorCode OH_GamePad_PressedButtons_GetCount(const struct GamePad_ButtonEvent* buttonEvent, int32_t* count)](#oh_gamepad_pressedbuttons_getcount) | - | Obtains the number of pressed buttons from a button event.|
| [GameController_ErrorCode OH_GamePad_PressedButtons_GetButtonInfo(const struct GamePad_ButtonEvent* buttonEvent, const int32_t index, GamePad_PressedButton** pressedButton)](#oh_gamepad_pressedbuttons_getbuttoninfo) | - | Obtains the button information at a specified index from a button event.|
| [GameController_ErrorCode OH_GamePad_DestroyPressedButton(GamePad_PressedButton** pressedButton)](#oh_gamepad_destroypressedbutton) | - | Destroys a pressed button instance.|
| [GameController_ErrorCode OH_GamePad_PressedButton_GetButtonCode(const struct GamePad_PressedButton* pressedButton, int32_t* code)](#oh_gamepad_pressedbutton_getbuttoncode) | - | Obtains the button code from a pressed button.|
| [GameController_ErrorCode OH_GamePad_PressedButton_GetButtonCodeName(const struct GamePad_PressedButton* pressedButton, char** codeName)](#oh_gamepad_pressedbutton_getbuttoncodename) | - | Obtains the button name from a pressed button.|
| [GameController_ErrorCode OH_GamePad_ButtonEvent_GetActionTime(const struct GamePad_ButtonEvent* buttonEvent, int64_t* actionTime)](#oh_gamepad_buttonevent_getactiontime) | - | Obtains the action time from a button event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetDeviceId(const struct GamePad_AxisEvent* axisEvent, char** deviceId)](#oh_gamepad_axisevent_getdeviceid) | - | Obtains the device ID from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetAxisSourceType(const struct GamePad_AxisEvent* axisEvent, GamePad_AxisSourceType* axisSourceType)](#oh_gamepad_axisevent_getaxissourcetype) | - | Obtains the source type of an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetXAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getxaxisvalue) | - | Obtains the X-axis value from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetYAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getyaxisvalue) | - | Obtains the Y-axis value from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetZAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getzaxisvalue) | - | Obtains the Z-axis value from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetRZAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getrzaxisvalue) | - | Obtains the RZ-axis value from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetHatXAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_gethatxaxisvalue) | - | Obtains the HatX-axis value from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetHatYAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_gethatyaxisvalue) | - | Obtains the HatY-axis value from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetBrakeAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getbrakeaxisvalue) | - | Obtains the Brake-axis value from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetGasAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)](#oh_gamepad_axisevent_getgasaxisvalue) | - | Obtains the Gas-axis value from an axis event.|
| [GameController_ErrorCode OH_GamePad_AxisEvent_GetActionTime(const struct GamePad_AxisEvent* axisEvent, int64_t* actionTime)](#oh_gamepad_axisevent_getactiontime) | - | Obtains the action time from an axis event.|

## Enum Description

### GamePad_AxisSourceType

```c
enum GamePad_AxisSourceType
```

**Description**

Defines source types of gamepad axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

| Value| Description|
| -- | -- |
| DPAD = 0 | The axis event comes from the directional pad (D-pad).<br>**Since:** 21|
| LEFT_THUMBSTICK = 1 | The axis event comes from the left thumbstick.<br>**Since:** 21|
| RIGHT_THUMBSTICK = 2 | The axis event comes from the right thumbstick.<br>**Since:** 21|
| LEFT_TRIGGER = 3 | The axis event comes from the left trigger.<br>**Since:** 21|
| RIGHT_TRIGGER = 4 | The axis event comes from the right trigger.<br>**Since:** 21|

### GamePad_Button_ActionType

```c
enum GamePad_Button_ActionType
```

**Description**

Defines action types of gamepad button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

| Value| Description|
| -- | -- |
| DOWN = 0 | The button is pressed.<br>**Since:** 21|
| UP = 1 | The button is released.<br>**Since:** 21|

## Function Description

### GamePad_ButtonInputMonitorCallback()

```c
typedef void(*GamePad_ButtonInputMonitorCallback)(const struct GamePad_ButtonEvent* buttonEvent)
```

**Description**

Defines the callback function used by the button event listener registration API. The callback is triggered when a player presses a button.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| (const struct GamePad_ButtonEvent\* buttonEvent | Output parameter. Gamepad button event [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md).|

### GamePad_AxisInputMonitorCallback()

```c
typedef void(*GamePad_AxisInputMonitorCallback)(const struct GamePad_AxisEvent* axisEvent)
```

**Description**

Defines the callback function used by the axis event listener registration API. The callback is triggered when a player operates a joystick.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| (const struct GamePad_AxisEvent\* axisEvent | Output parameter. Gamepad axis event [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md).|

### OH_GamePad_ButtonEvent_GetDeviceId()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetDeviceId(const struct GamePad_ButtonEvent* buttonEvent, char** deviceId)
```

**Description**

Obtains the device ID from a button event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | Pointer to the [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) instance. The pointer cannot be null.|
| char** deviceId | Output parameter. Double pointer to the device ID.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **buttonEvent** or **deviceId** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the device has insufficient memory, [GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonEvent_GetButtonAction()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonAction(const struct GamePad_ButtonEvent* buttonEvent, GamePad_Button_ActionType* actionType)
```

**Description**

Obtains the button action type from a button event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | Pointer to the [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) instance. The pointer cannot be null.|
| [GamePad_Button_ActionType](capi-game-pad-event-h.md#gamepad_button_actiontype)* actionType | Output parameter. Button action type.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **buttonEvent** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonEvent_GetButtonCode()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonCode(const struct GamePad_ButtonEvent* buttonEvent, int32_t* code)
```

**Description**

Obtains the button code from a button event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | Pointer to the [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) instance. The pointer cannot be null.|
| int32_t* code | Output parameter. Button code.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **buttonEvent** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonEvent_GetButtonCodeName()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetButtonCodeName(const struct GamePad_ButtonEvent* buttonEvent, char** codeName)
```

**Description**

Obtains the button name from a button event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | Pointer to the [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) instance. The pointer cannot be null.|
| char** codeName | Output parameter. Double pointer to the button name.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **buttonEvent** or **codeName** is null. [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the device has insufficient memory, [GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_PressedButtons_GetCount()

```c
GameController_ErrorCode OH_GamePad_PressedButtons_GetCount(const struct GamePad_ButtonEvent* buttonEvent, int32_t* count)
```

**Description**

Obtains the number of pressed buttons from a button event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | Pointer to the [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) instance. The pointer cannot be null.|
| int32_t* count | Output parameter. Number of buttons.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **buttonEvent** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_PressedButtons_GetButtonInfo()

```c
GameController_ErrorCode OH_GamePad_PressedButtons_GetButtonInfo(const struct GamePad_ButtonEvent* buttonEvent, const int32_t index, GamePad_PressedButton** pressedButton)
```

**Description**

Obtains the button information at a specified index from a button event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | Pointer to the [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) instance. The pointer cannot be null.|
| const int32_t index | Button index.|
| [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)** pressedButton | Output parameter. Double pointer to the pressed button.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **buttonEvent** is null, or **index** is less than 0 or greater than or equal to the total number of keys, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_DestroyPressedButton()

```c
GameController_ErrorCode OH_GamePad_DestroyPressedButton(GamePad_PressedButton** pressedButton)
```

**Description**

Destroys a pressed button instance.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)** pressedButton | Double pointer to the [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md) instance. The pointer cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **pressedButton** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_PressedButton_GetButtonCode()

```c
GameController_ErrorCode OH_GamePad_PressedButton_GetButtonCode(const struct GamePad_PressedButton* pressedButton, int32_t* code)
```

**Description**

Obtains the button code from a pressed button.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)* pressedButton | Pointer to the [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md) instance. The pointer cannot be null.|
| int32_t* code | Output parameter. Button code.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **pressedButton** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_PressedButton_GetButtonCodeName()

```c
GameController_ErrorCode OH_GamePad_PressedButton_GetButtonCodeName(const struct GamePad_PressedButton* pressedButton, char** codeName)
```

**Description**

Obtains the button name from a pressed button.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md)* pressedButton | Pointer to the [GamePad_PressedButton](capi-gamecontroller-gamepad-pressedbutton.md) instance. The pointer cannot be null.|
| char** codeName | Output parameter. Double pointer to the button name.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **pressedButton** or **codeName** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the device has insufficient memory, [GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonEvent_GetActionTime()

```c
GameController_ErrorCode OH_GamePad_ButtonEvent_GetActionTime(const struct GamePad_ButtonEvent* buttonEvent, int64_t* actionTime)
```

**Description**

Obtains the action time from a button event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md)* buttonEvent | Pointer to the [GamePad_ButtonEvent](capi-gamecontroller-gamepad-buttonevent.md) instance. The pointer cannot be null.|
| int64_t* actionTime | Output parameter. Action time. Unix timestamp, in milliseconds.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, returns [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode).</li>     <li>If the **buttonEvent** parameter is null, returns [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode).</li></ul> |

### OH_GamePad_AxisEvent_GetDeviceId()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetDeviceId(const struct GamePad_AxisEvent* axisEvent, char** deviceId)
```

**Description**

Obtains the device ID from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| char** deviceId | Output parameter. Double pointer to the device ID.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **axisEvent** or **deviceId** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the device has insufficient memory, [GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetAxisSourceType()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetAxisSourceType(const struct GamePad_AxisEvent* axisEvent, GamePad_AxisSourceType* axisSourceType)
```

**Description**

Obtains the source type of an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| [GamePad_AxisSourceType](capi-game-pad-event-h.md#gamepad_axissourcetype)* axisSourceType | Output parameter. Source type of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, returns [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode).</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetXAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetXAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**Description**

Obtains the X-axis value from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| double* axisValue | Output parameter. Axis value. The value range is [-1.0, 1.0].|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetYAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetYAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**Description**

Obtains the Y-axis value from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| double* axisValue | Output parameter. Axis value. The value range is [-1.0, 1.0].|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetZAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetZAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**Description**

Obtains the Z-axis value from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| double* axisValue | Output parameter. Axis value. The value range is [-1.0, 1.0].|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, returns [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode).</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetRZAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetRZAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**Description**

Obtains the RZ-axis value from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| double* axisValue | Output parameter. Axis value. The value range is [-1.0, 1.0].|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, returns [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode).</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetHatXAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetHatXAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**Description**

Obtains the HatX-axis value from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| double* axisValue | Output parameter. Axis value. The value range is [-1.0, 1.0].|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetHatYAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetHatYAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**Description**

Obtains the HatY-axis value from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| double* axisValue | Output parameter. Axis value. The value range is [-1.0, 1.0].|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetBrakeAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetBrakeAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**Description**

Obtains the Brake-axis value from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| double* axisValue | Output parameter. Axis value. The value range is [-1.0, 1.0].|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetGasAxisValue()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetGasAxisValue(const struct GamePad_AxisEvent* axisEvent, double* axisValue)
```

**Description**

Obtains the Gas-axis value from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| double* axisValue | Output parameter. Axis value. The value range is [-1.0, 1.0].|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, returns [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode).</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_AxisEvent_GetActionTime()

```c
GameController_ErrorCode OH_GamePad_AxisEvent_GetActionTime(const struct GamePad_AxisEvent* axisEvent, int64_t* actionTime)
```

**Description**

Obtains the action time from an axis event.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md)* axisEvent | Pointer to the [GamePad_AxisEvent](capi-gamecontroller-gamepad-axisevent.md) instance. The pointer cannot be null.|
| int64_t* actionTime | Output parameter. Action time. Unix timestamp, in milliseconds.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **axisEvent** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |