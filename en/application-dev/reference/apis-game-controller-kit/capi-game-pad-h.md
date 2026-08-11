# game_pad.h

<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @luwy2025-->
<!-- md-trans-meta sourceCommit=77c72b42e08d6a4d9b4548171e0024968c7d2a99 translatedAt=2026-07-30T08:29:15.965Z pushedAt=2026-07-30T09:07:05.234Z -->

## Overview

Defines APIs for gamepads.

**File to include:** <GameControllerKit/game_pad.h>

**Library:** libohgame_controller.z.so

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Related module:** [GameController](capi-gamecontroller.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [GameController_ErrorCode OH_GamePad_LeftShoulder_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_leftshoulder_registerbuttoninputmonitor) | Registers a callback for Left Shoulder button events.|
| [GameController_ErrorCode OH_GamePad_LeftShoulder_UnregisterButtonInputMonitor(void)](#oh_gamepad_leftshoulder_unregisterbuttoninputmonitor) | Unregisters the callback for Left Shoulder button events.|
| [GameController_ErrorCode OH_GamePad_RightShoulder_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_rightshoulder_registerbuttoninputmonitor) | Registers a callback for Right Shoulder button events.|
| [GameController_ErrorCode OH_GamePad_RightShoulder_UnregisterButtonInputMonitor(void)](#oh_gamepad_rightshoulder_unregisterbuttoninputmonitor) | Unregisters the callback for Right Shoulder button events.|
| [GameController_ErrorCode OH_GamePad_LeftTrigger_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_lefttrigger_registerbuttoninputmonitor) | Registers a callback for Left Trigger button events.|
| [GameController_ErrorCode OH_GamePad_LeftTrigger_UnregisterButtonInputMonitor(void)](#oh_gamepad_lefttrigger_unregisterbuttoninputmonitor) | Unregisters the callback for Left Trigger button events.|
| [GameController_ErrorCode OH_GamePad_LeftTrigger_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)](#oh_gamepad_lefttrigger_registeraxisinputmonitor) | Registers a callback for Left Trigger axis events.|
| [GameController_ErrorCode OH_GamePad_LeftTrigger_UnregisterAxisInputMonitor(void)](#oh_gamepad_lefttrigger_unregisteraxisinputmonitor) | Unregisters the callback for Left Trigger axis events.|
| [GameController_ErrorCode OH_GamePad_RightTrigger_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_righttrigger_registerbuttoninputmonitor) | Registers a callback for Right Trigger button events.|
| [GameController_ErrorCode OH_GamePad_RightTrigger_UnregisterButtonInputMonitor(void)](#oh_gamepad_righttrigger_unregisterbuttoninputmonitor) | Unregisters the callback for Right Trigger button events.|
| [GameController_ErrorCode OH_GamePad_RightTrigger_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)](#oh_gamepad_righttrigger_registeraxisinputmonitor) | Registers a callback for Right Trigger axis events.|
| [GameController_ErrorCode OH_GamePad_RightTrigger_UnregisterAxisInputMonitor(void)](#oh_gamepad_righttrigger_unregisteraxisinputmonitor) | Unregisters the callback for Right Trigger axis events.|
| [GameController_ErrorCode OH_GamePad_ButtonMenu_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_buttonmenu_registerbuttoninputmonitor) | Registers a callback for Menu button events.|
| [GameController_ErrorCode OH_GamePad_ButtonMenu_UnregisterButtonInputMonitor(void)](#oh_gamepad_buttonmenu_unregisterbuttoninputmonitor) | Unregisters the callback for Menu button events.|
| [GameController_ErrorCode OH_GamePad_ButtonHome_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_buttonhome_registerbuttoninputmonitor) | Registers a callback for Home button events.|
| [GameController_ErrorCode OH_GamePad_ButtonHome_UnregisterButtonInputMonitor(void)](#oh_gamepad_buttonhome_unregisterbuttoninputmonitor) | Unregisters the callback for Home button events.|
| [GameController_ErrorCode OH_GamePad_ButtonA_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_buttona_registerbuttoninputmonitor) | Registers a callback for A button events.|
| [GameController_ErrorCode OH_GamePad_ButtonA_UnregisterButtonInputMonitor(void)](#oh_gamepad_buttona_unregisterbuttoninputmonitor) | Unregisters the callback for A button events.|
| [GameController_ErrorCode OH_GamePad_ButtonB_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_buttonb_registerbuttoninputmonitor) | Registers a callback for B button events.|
| [GameController_ErrorCode OH_GamePad_ButtonB_UnregisterButtonInputMonitor(void)](#oh_gamepad_buttonb_unregisterbuttoninputmonitor) | Unregisters the callback for B button events.|
| [GameController_ErrorCode OH_GamePad_ButtonX_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_buttonx_registerbuttoninputmonitor) | Registers a callback for X button events.|
| [GameController_ErrorCode OH_GamePad_ButtonX_UnregisterButtonInputMonitor(void)](#oh_gamepad_buttonx_unregisterbuttoninputmonitor) | Unregisters the callback for X button events.|
| [GameController_ErrorCode OH_GamePad_ButtonY_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_buttony_registerbuttoninputmonitor) | Registers a callback for Y button events.|
| [GameController_ErrorCode OH_GamePad_ButtonY_UnregisterButtonInputMonitor(void)](#oh_gamepad_buttony_unregisterbuttoninputmonitor) | Unregisters the callback for Y button events.|
| [GameController_ErrorCode OH_GamePad_ButtonC_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_buttonc_registerbuttoninputmonitor) | Registers a callback for C button events.|
| [GameController_ErrorCode OH_GamePad_ButtonC_UnregisterButtonInputMonitor(void)](#oh_gamepad_buttonc_unregisterbuttoninputmonitor) | Unregisters the callback for C button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_LeftButton_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_dpad_leftbutton_registerbuttoninputmonitor) | Registers a callback for D-pad Left button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_LeftButton_UnregisterButtonInputMonitor(void)](#oh_gamepad_dpad_leftbutton_unregisterbuttoninputmonitor) | Unregisters the callback for D-pad Left button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_RightButton_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_dpad_rightbutton_registerbuttoninputmonitor) | Registers a callback for D-pad Right button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_RightButton_UnregisterButtonInputMonitor(void)](#oh_gamepad_dpad_rightbutton_unregisterbuttoninputmonitor) | Unregisters the callback for D-pad Right button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_UpButton_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_dpad_upbutton_registerbuttoninputmonitor) | Registers a callback for D-pad Up button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_UpButton_UnregisterButtonInputMonitor(void)](#oh_gamepad_dpad_upbutton_unregisterbuttoninputmonitor) | Unregisters the callback for D-pad Up button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_DownButton_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_dpad_downbutton_registerbuttoninputmonitor) | Registers a callback for D-pad Down button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_DownButton_UnregisterButtonInputMonitor(void)](#oh_gamepad_dpad_downbutton_unregisterbuttoninputmonitor) | Unregisters the callback for D-pad Down button events.|
| [GameController_ErrorCode OH_GamePad_Dpad_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)](#oh_gamepad_dpad_registeraxisinputmonitor) | Registers a callback for D-pad axis events.|
| [GameController_ErrorCode OH_GamePad_Dpad_UnregisterAxisInputMonitor(void)](#oh_gamepad_dpad_unregisteraxisinputmonitor) | Unregisters the callback for D-pad axis events.|
| [GameController_ErrorCode OH_GamePad_LeftThumbstick_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_leftthumbstick_registerbuttoninputmonitor) | Registers a callback for Left Thumbstick button events.|
| [GameController_ErrorCode OH_GamePad_LeftThumbstick_UnregisterButtonInputMonitor(void)](#oh_gamepad_leftthumbstick_unregisterbuttoninputmonitor) | Unregisters the callback for Left Thumbstick button events.|
| [GameController_ErrorCode OH_GamePad_LeftThumbstick_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)](#oh_gamepad_leftthumbstick_registeraxisinputmonitor) | Registers a callback for Left Thumbstick axis events.|
| [GameController_ErrorCode OH_GamePad_LeftThumbstick_UnregisterAxisInputMonitor(void)](#oh_gamepad_leftthumbstick_unregisteraxisinputmonitor) | Unregisters the callback for Left Thumbstick axis events.|
| [GameController_ErrorCode OH_GamePad_RightThumbstick_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)](#oh_gamepad_rightthumbstick_registerbuttoninputmonitor) | Registers a callback for Right Thumbstick button events.|
| [GameController_ErrorCode OH_GamePad_RightThumbstick_UnregisterButtonInputMonitor(void)](#oh_gamepad_rightthumbstick_unregisterbuttoninputmonitor) | Unregisters the callback for Right Thumbstick button events.|
| [GameController_ErrorCode OH_GamePad_RightThumbstick_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)](#oh_gamepad_rightthumbstick_registeraxisinputmonitor) | Registers a callback for Right Thumbstick axis events.|
| [GameController_ErrorCode OH_GamePad_RightThumbstick_UnregisterAxisInputMonitor(void)](#oh_gamepad_rightthumbstick_unregisteraxisinputmonitor) | Unregisters the callback for Right Thumbstick axis events.|

## Function Description

### OH_GamePad_LeftShoulder_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftShoulder_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Left Shoulder button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_LeftShoulder_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftShoulder_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Left Shoulder button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_RightShoulder_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightShoulder_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Right Shoulder button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_RightShoulder_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightShoulder_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Right Shoulder button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_LeftTrigger_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftTrigger_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Left Trigger button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_LeftTrigger_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftTrigger_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Left Trigger button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_LeftTrigger_RegisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftTrigger_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Left Trigger axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback) inputMonitorCallback | Callback function [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>      <li>If **inputMonitorCallback** is **null**, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_LeftTrigger_UnregisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftTrigger_UnregisterAxisInputMonitor(void)
```

**Description**

Unregisters the callback for Left Trigger axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_RightTrigger_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightTrigger_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Right Trigger button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>      <li>If **inputMonitorCallback** is **null**, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_RightTrigger_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightTrigger_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Right Trigger button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_RightTrigger_RegisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightTrigger_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Right Trigger axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback) inputMonitorCallback | Callback function [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_RightTrigger_UnregisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightTrigger_UnregisterAxisInputMonitor(void)
```

**Description**

Unregisters the callback for Right Trigger axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_ButtonMenu_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonMenu_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Menu button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonMenu_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonMenu_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Menu button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_ButtonHome_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonHome_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Home button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonHome_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonHome_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Home button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_ButtonA_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonA_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for A button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonA_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonA_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for A button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_ButtonB_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonB_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for B button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonB_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonB_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for B button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_ButtonX_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonX_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for X button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonX_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonX_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for X button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_ButtonY_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonY_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Y button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonY_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonY_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Y button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_ButtonC_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonC_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for C button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_ButtonC_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_ButtonC_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for C button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_Dpad_LeftButton_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_LeftButton_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for D-pad Left button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_Dpad_LeftButton_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_LeftButton_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for D-pad Left button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_Dpad_RightButton_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_RightButton_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for D-pad Right button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_Dpad_RightButton_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_RightButton_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for D-pad Right button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_Dpad_UpButton_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_UpButton_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for D-pad Up button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_Dpad_UpButton_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_UpButton_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for D-pad Up button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_Dpad_DownButton_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_DownButton_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for D-pad Down button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_Dpad_DownButton_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_DownButton_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for D-pad Down button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_Dpad_RegisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for D-pad axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback) inputMonitorCallback | Callback function [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_Dpad_UnregisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_Dpad_UnregisterAxisInputMonitor(void)
```

**Description**

Unregisters the callback for D-pad axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_LeftThumbstick_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftThumbstick_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Left Thumbstick button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_LeftThumbstick_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftThumbstick_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Left Thumbstick button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_LeftThumbstick_RegisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftThumbstick_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Left Thumbstick axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback) inputMonitorCallback | Callback function [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_LeftThumbstick_UnregisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_LeftThumbstick_UnregisterAxisInputMonitor(void)
```

**Description**

Unregisters the callback for Left Thumbstick axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_RightThumbstick_RegisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightThumbstick_RegisterButtonInputMonitor(GamePad_ButtonInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Right Thumbstick button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback) inputMonitorCallback | Callback function [GamePad_ButtonInputMonitorCallback](capi-game-pad-event-h.md#gamepad_buttoninputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_RightThumbstick_UnregisterButtonInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightThumbstick_UnregisterButtonInputMonitor(void)
```

**Description**

Unregisters the callback for Right Thumbstick button events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GamePad_RightThumbstick_RegisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightThumbstick_RegisterAxisInputMonitor(GamePad_AxisInputMonitorCallback inputMonitorCallback)
```

**Description**

Registers a callback for Right Thumbstick axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback) inputMonitorCallback | Callback function [GamePad_AxisInputMonitorCallback](capi-game-pad-event-h.md#gamepad_axisinputmonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **inputMonitorCallback** is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GamePad_RightThumbstick_UnregisterAxisInputMonitor()

```c
GameController_ErrorCode OH_GamePad_RightThumbstick_UnregisterAxisInputMonitor(void)
```

**Description**

Unregisters the callback for Right Thumbstick axis events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|