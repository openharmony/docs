# game_device.h

<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @luwy2025-->
<!-- md-trans-meta sourceCommit=77c72b42e08d6a4d9b4548171e0024968c7d2a99 translatedAt=2026-07-30T08:24:46.710Z pushedAt=2026-07-30T08:32:38.255Z -->

## Overview

Defines APIs for game devices.

**File to include:** <GameControllerKit/game_device.h>

**Library:** libohgame_controller.z.so

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Related module:** [GameController](capi-gamecontroller.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md) | GameDevice_AllDeviceInfos | Defines the result returned by [OH_GameDevice_GetAllDeviceInfos](capi-game-device-h.md#oh_gamedevice_getalldeviceinfos).|

### Functions

| Name| Description|
| -- | -- |
| [GameController_ErrorCode OH_GameDevice_GetAllDeviceInfos(GameDevice_AllDeviceInfos** allDeviceInfos)](#oh_gamedevice_getalldeviceinfos) | Obtains information about all online devices.|
| [GameController_ErrorCode OH_GameDevice_RegisterDeviceMonitor(GameDevice_DeviceMonitorCallback deviceMonitorCallback)](#oh_gamedevice_registerdevicemonitor) | Registers a callback for device status change events.|
| [GameController_ErrorCode OH_GameDevice_UnregisterDeviceMonitor(void)](#oh_gamedevice_unregisterdevicemonitor) | Unregisters a callback for device status change events.|
| [GameController_ErrorCode OH_GameDevice_DestroyAllDeviceInfos(GameDevice_AllDeviceInfos** allDeviceInfos)](#oh_gamedevice_destroyalldeviceinfos) | Destroys all device information instances.|
| [GameController_ErrorCode OH_GameDevice_AllDeviceInfos_GetCount(const struct GameDevice_AllDeviceInfos* allDeviceInfos, int32_t* count)](#oh_gamedevice_alldeviceinfos_getcount) | Obtains the number of devices.|
| [GameController_ErrorCode OH_GameDevice_AllDeviceInfos_GetDeviceInfo(const struct GameDevice_AllDeviceInfos* allDeviceInfos, const int32_t index, GameDevice_DeviceInfo** deviceInfo)](#oh_gamedevice_alldeviceinfos_getdeviceinfo) | Obtains the device information at the specified index.|

## Function Description

### OH_GameDevice_GetAllDeviceInfos()

```c
GameController_ErrorCode OH_GameDevice_GetAllDeviceInfos(GameDevice_AllDeviceInfos** allDeviceInfos)
```

**Description**

Obtains information about all online devices.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)** allDeviceInfos | Output parameter. Double pointer to the [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md) instance. The pointer cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **allDeviceInfos** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If querying all device information in multimodal input fails, [GAME_CONTROLLER_MULTIMODAL_INPUT_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GameDevice_RegisterDeviceMonitor()

```c
GameController_ErrorCode OH_GameDevice_RegisterDeviceMonitor(GameDevice_DeviceMonitorCallback deviceMonitorCallback)
```

**Description**

Registers a callback for device status change events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GameDevice_DeviceMonitorCallback](capi-game-device-event-h.md#gamedevice_devicemonitorcallback) deviceMonitorCallback | Callback function [GameDevice_DeviceMonitorCallback](capi-game-device-event-h.md#gamedevice_devicemonitorcallback), which cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **deviceMonitorCallback** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GameDevice_UnregisterDeviceMonitor()

```c
GameController_ErrorCode OH_GameDevice_UnregisterDeviceMonitor(void)
```

**Description**

Unregisters the callback for device status change events.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.|

### OH_GameDevice_DestroyAllDeviceInfos()

```c
GameController_ErrorCode OH_GameDevice_DestroyAllDeviceInfos(GameDevice_AllDeviceInfos** allDeviceInfos)
```

**Description**

Destroys all device information instances.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)** allDeviceInfos | Double pointer to the [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md) instance. The pointer cannot be null.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **allDeviceInfos** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GameDevice_AllDeviceInfos_GetCount()

```c
GameController_ErrorCode OH_GameDevice_AllDeviceInfos_GetCount(const struct GameDevice_AllDeviceInfos* allDeviceInfos, int32_t* count)
```

**Description**

Obtains the number of devices.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)* allDeviceInfos | Pointer to the [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md) instance. The pointer cannot be null.|
| int32_t* count | Output parameter. Number of devices.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If the **allDeviceInfos** parameter is null, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |

### OH_GameDevice_AllDeviceInfos_GetDeviceInfo()

```c
GameController_ErrorCode OH_GameDevice_AllDeviceInfos_GetDeviceInfo(const struct GameDevice_AllDeviceInfos* allDeviceInfos, const int32_t index, GameDevice_DeviceInfo** deviceInfo)
```

**Description**

Obtains the device information at the specified index.

**System capability:** SystemCapability.Game.GameController

**Since:** 21

**Parameters**

| Name| Description|
| -- | -- |
| [const struct GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)* allDeviceInfos | Pointer to the [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md) instance. The pointer cannot be null.|
| const int32_t index | Index of the device.|
| [GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)** deviceInfo | Output parameter. Double pointer to the device information.|

**Return value**

| Type| Description|
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>If the operation is successful, [GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li>     <li>If **allDeviceInfos** is null, or **index** is less than 0 or greater than or equal to the total number of devices, [GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode) is returned.</li></ul> |