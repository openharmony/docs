# game_device.h
<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @luwy2025-->

## 概述

定义游戏设备的接口。

**引用文件：** <GameControllerKit/game_device.h>

**库：** libohgame_controller.z.so

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**相关模块：** [GameController](capi-gamecontroller.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md) | GameDevice_AllDeviceInfos | 定义[OH_GameDevice_GetAllDeviceInfos](capi-game-device-h.md#oh_gamedevice_getalldeviceinfos)接口的调用结果。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [GameController_ErrorCode OH_GameDevice_GetAllDeviceInfos(GameDevice_AllDeviceInfos** allDeviceInfos)](#oh_gamedevice_getalldeviceinfos) | 获取所有在线设备的信息。 |
| [GameController_ErrorCode OH_GameDevice_RegisterDeviceMonitor(GameDevice_DeviceMonitorCallback deviceMonitorCallback)](#oh_gamedevice_registerdevicemonitor) | 注册设备状态变化事件的监听回调。 |
| [GameController_ErrorCode OH_GameDevice_UnregisterDeviceMonitor(void)](#oh_gamedevice_unregisterdevicemonitor) | 取消注册设备状态变化事件的监听回调。 |
| [GameController_ErrorCode OH_GameDevice_DestroyAllDeviceInfos(GameDevice_AllDeviceInfos** allDeviceInfos)](#oh_gamedevice_destroyalldeviceinfos) | 销毁所有设备信息实例。 |
| [GameController_ErrorCode OH_GameDevice_AllDeviceInfos_GetCount(const struct GameDevice_AllDeviceInfos* allDeviceInfos, int32_t* count)](#oh_gamedevice_alldeviceinfos_getcount) | 获取设备数量。 |
| [GameController_ErrorCode OH_GameDevice_AllDeviceInfos_GetDeviceInfo(const struct GameDevice_AllDeviceInfos* allDeviceInfos, const int32_t index, GameDevice_DeviceInfo** deviceInfo)](#oh_gamedevice_alldeviceinfos_getdeviceinfo) | 获取指定索引的设备信息。 |

## 函数说明

### OH_GameDevice_GetAllDeviceInfos()

```c
GameController_ErrorCode OH_GameDevice_GetAllDeviceInfos(GameDevice_AllDeviceInfos** allDeviceInfos)
```

**描述**

获取所有在线设备的信息。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)** allDeviceInfos | 输出参数。二级指针指向[GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)实例，不能为空。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数allDeviceInfos为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果查询多模输入中所有设备信息失败，返回[GAME_CONTROLLER_MULTIMODAL_INPUT_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_RegisterDeviceMonitor()

```c
GameController_ErrorCode OH_GameDevice_RegisterDeviceMonitor(GameDevice_DeviceMonitorCallback deviceMonitorCallback)
```

**描述**

注册设备状态变化事件的监听回调。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [GameDevice_DeviceMonitorCallback](capi-game-device-event-h.md#gamedevice_devicemonitorcallback) deviceMonitorCallback | 回调函数[GameDevice_DeviceMonitorCallback](capi-game-device-event-h.md#gamedevice_devicemonitorcallback)，不能为空。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceMonitorCallback为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_UnregisterDeviceMonitor()

```c
GameController_ErrorCode OH_GameDevice_UnregisterDeviceMonitor(void)
```

**描述**

取消注册设备状态变化事件的监听回调。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | 如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。 |

### OH_GameDevice_DestroyAllDeviceInfos()

```c
GameController_ErrorCode OH_GameDevice_DestroyAllDeviceInfos(GameDevice_AllDeviceInfos** allDeviceInfos)
```

**描述**

销毁所有设备信息实例。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)** allDeviceInfos | 二级指针指向[GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)实例，不能为空。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数allDeviceInfos为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_AllDeviceInfos_GetCount()

```c
GameController_ErrorCode OH_GameDevice_AllDeviceInfos_GetCount(const struct GameDevice_AllDeviceInfos* allDeviceInfos, int32_t* count)
```

**描述**

获取设备数量。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)* allDeviceInfos | 指针指向[GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)实例，不能为空。 |
| int32_t* count | 输出参数，设备数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数allDeviceInfos为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_AllDeviceInfos_GetDeviceInfo()

```c
GameController_ErrorCode OH_GameDevice_AllDeviceInfos_GetDeviceInfo(const struct GameDevice_AllDeviceInfos* allDeviceInfos, const int32_t index, GameDevice_DeviceInfo** deviceInfo)
```

**描述**

获取指定索引的设备信息。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)* allDeviceInfos | 指针指向[GameDevice_AllDeviceInfos](capi-gamecontroller-gamedevice-alldeviceinfos.md)实例，不能为空。 |
| const int32_t index | 指定设备索引。 |
| [GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)** deviceInfo | 输出参数，二级指针指向设备信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数allDeviceInfos为null，或index小于0或大于等于设备总数，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |


