# game_device_event.h
<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @luwy2025-->

## 概述

定义游戏设备事件的接口。

**引用文件：** <GameControllerKit/game_device_event.h>

**库：** libohgame_controller.z.so

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**相关模块：** [GameController](capi-gamecontroller.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md) | GameDevice_DeviceInfo | 定义设备信息。 |
| [GameDevice_DeviceEvent](capi-gamecontroller-gamedevice-deviceevent.md) | GameDevice_DeviceEvent | 定义设备状态变化事件。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [GameDevice_StatusChangedType](#gamedevice_statuschangedtype) | GameDevice_StatusChangedType | 此枚举定义设备的状态变化类型。 |
| [GameDevice_DeviceType](#gamedevice_devicetype) | GameDevice_DeviceType | 此枚举定义设备类型。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void(\*GameDevice_DeviceMonitorCallback)(const struct GameDevice_DeviceEvent* deviceEvent)](#gamedevice_devicemonitorcallback) | GameDevice_DeviceMonitorCallback | 定义[OH_GameDevice_RegisterDeviceMonitor](capi-game-device-h.md#oh_gamedevice_registerdevicemonitor)中使用的回调函数。当设备上线或下线时，该回调函数将被调用。 |
| [GameController_ErrorCode OH_GameDevice_DeviceEvent_GetChangedType(const struct GameDevice_DeviceEvent* deviceEvent, GameDevice_StatusChangedType* statusChangedType)](#oh_gamedevice_deviceevent_getchangedtype) | - | 从设备状态变化事件中获取状态变化类型。 |
| [GameController_ErrorCode OH_GameDevice_DeviceEvent_GetDeviceInfo(const struct GameDevice_DeviceEvent* deviceEvent, GameDevice_DeviceInfo** deviceInfo)](#oh_gamedevice_deviceevent_getdeviceinfo) | - | 从设备状态变化事件中获取设备信息。 |
| [GameController_ErrorCode OH_GameDevice_DestroyDeviceInfo(GameDevice_DeviceInfo** deviceInfo)](#oh_gamedevice_destroydeviceinfo) | - | 销毁设备信息实例。 |
| [GameController_ErrorCode OH_GameDevice_DeviceInfo_GetDeviceId(const struct GameDevice_DeviceInfo* deviceInfo, char** deviceId)](#oh_gamedevice_deviceinfo_getdeviceid) | - | 从设备信息中获取设备ID。 |
| [GameController_ErrorCode OH_GameDevice_DeviceInfo_GetName(const struct GameDevice_DeviceInfo* deviceInfo, char** name)](#oh_gamedevice_deviceinfo_getname) | - | 从设备信息中获取设备名称。 |
| [GameController_ErrorCode OH_GameDevice_DeviceInfo_GetProduct(const struct GameDevice_DeviceInfo* deviceInfo, int32_t* product)](#oh_gamedevice_deviceinfo_getproduct) | - | 从设备信息中获取产品信息。 |
| [GameController_ErrorCode OH_GameDevice_DeviceInfo_GetVersion(const struct GameDevice_DeviceInfo* deviceInfo, int32_t* version)](#oh_gamedevice_deviceinfo_getversion) | - | 从设备信息中获取版本信息。 |
| [GameController_ErrorCode OH_GameDevice_DeviceInfo_GetPhysicalAddress(const struct GameDevice_DeviceInfo* deviceInfo, char** physicalAddress)](#oh_gamedevice_deviceinfo_getphysicaladdress) | - | 从设备信息中获取物理地址。 |
| [GameController_ErrorCode OH_GameDevice_DeviceInfo_GetDeviceType(const struct GameDevice_DeviceInfo* deviceInfo, GameDevice_DeviceType* deviceType)](#oh_gamedevice_deviceinfo_getdevicetype) | - | 从设备信息中获取设备类型。 |

## 枚举类型说明

### GameDevice_StatusChangedType

```c
enum GameDevice_StatusChangedType
```

**描述**

此枚举定义设备的状态变化类型。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

| 枚举项 | 描述 |
| -- | -- |
| OFFLINE = 0 | 设备下线。<br>**起始版本：** 21 |
| ONLINE = 1 | 设备上线。<br>**起始版本：** 21 |

### GameDevice_DeviceType

```c
enum GameDevice_DeviceType
```

**描述**

此枚举定义设备类型。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

| 枚举项 | 描述 |
| -- | -- |
| UNKNOWN = 0 | 未知。<br>**起始版本：** 21 |
| GAME_PAD = 1 | 游戏手柄。<br>**起始版本：** 21 |


## 函数说明

### GameDevice_DeviceMonitorCallback()

```c
typedef void(*GameDevice_DeviceMonitorCallback)(const struct GameDevice_DeviceEvent* deviceEvent)
```

**描述**

定义[OH_GameDevice_RegisterDeviceMonitor](capi-game-device-h.md#oh_gamedevice_registerdevicemonitor)中使用的回调函数。当设备上线或下线时，该回调函数将被调用。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct GameDevice_DeviceEvent* deviceEvent | 输入参数。设备状态变化事件[GameDevice_DeviceEvent](capi-gamecontroller-gamedevice-deviceevent.md)。 |

### OH_GameDevice_DeviceEvent_GetChangedType()

```c
GameController_ErrorCode OH_GameDevice_DeviceEvent_GetChangedType(const struct GameDevice_DeviceEvent* deviceEvent, GameDevice_StatusChangedType* statusChangedType)
```

**描述**

从设备状态变化事件中获取状态变化类型。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_DeviceEvent](capi-gamecontroller-gamedevice-deviceevent.md)* deviceEvent | 指针指向[GameDevice_DeviceEvent](capi-gamecontroller-gamedevice-deviceevent.md)实例，不能为空。 |
| [GameDevice_StatusChangedType](capi-game-device-event-h.md#gamedevice_statuschangedtype)* statusChangedType | 输出参数，设备状态变化类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_DeviceEvent_GetDeviceInfo()

```c
GameController_ErrorCode OH_GameDevice_DeviceEvent_GetDeviceInfo(const struct GameDevice_DeviceEvent* deviceEvent, GameDevice_DeviceInfo** deviceInfo)
```

**描述**

从设备状态变化事件中获取设备信息。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_DeviceEvent](capi-gamecontroller-gamedevice-deviceevent.md)* deviceEvent | 指针指向[GameDevice_DeviceEvent](capi-gamecontroller-gamedevice-deviceevent.md)实例，不能为空。 |
| [GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)** deviceInfo | 输出参数，二级指针指向设备信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceEvent为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_DestroyDeviceInfo()

```c
GameController_ErrorCode OH_GameDevice_DestroyDeviceInfo(GameDevice_DeviceInfo** deviceInfo)
```

**描述**

销毁设备信息实例。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)** deviceInfo | 二级指针指向[GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)实例，不能为空。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceInfo为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_DeviceInfo_GetDeviceId()

```c
GameController_ErrorCode OH_GameDevice_DeviceInfo_GetDeviceId(const struct GameDevice_DeviceInfo* deviceInfo, char** deviceId)
```

**描述**

从设备信息中获取设备ID。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)* deviceInfo | 指针指向[GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)实例，不能为空。 |
| char** deviceId | 输出参数，二级指针指向设备ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceInfo或deviceId为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果设备内存不足，返回[GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_DeviceInfo_GetName()

```c
GameController_ErrorCode OH_GameDevice_DeviceInfo_GetName(const struct GameDevice_DeviceInfo* deviceInfo, char** name)
```

**描述**

从设备信息中获取设备名称。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)* deviceInfo | 指针指向[GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)实例，不能为空。 |
| char** name | 输出参数，二级指针指向设备名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceInfo或name为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果设备内存不足，返回[GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_DeviceInfo_GetProduct()

```c
GameController_ErrorCode OH_GameDevice_DeviceInfo_GetProduct(const struct GameDevice_DeviceInfo* deviceInfo, int32_t* product)
```

**描述**

从设备信息中获取产品信息。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)* deviceInfo | 指针指向[GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)实例，不能为空。 |
| int32_t* product | 输出参数，产品信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceInfo为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_DeviceInfo_GetVersion()

```c
GameController_ErrorCode OH_GameDevice_DeviceInfo_GetVersion(const struct GameDevice_DeviceInfo* deviceInfo, int32_t* version)
```

**描述**

从设备信息中获取版本信息。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)* deviceInfo | 指针指向[GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)实例，不能为空。 |
| int32_t* version | 输出参数，版本信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceInfo为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_DeviceInfo_GetPhysicalAddress()

```c
GameController_ErrorCode OH_GameDevice_DeviceInfo_GetPhysicalAddress(const struct GameDevice_DeviceInfo* deviceInfo, char** physicalAddress)
```

**描述**

从设备信息中获取物理地址。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)* deviceInfo | 指针指向[GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)实例，不能为空。 |
| char** physicalAddress | 输出参数，二级指针指向物理地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceInfo或physicalAddress为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果设备内存不足，返回[GAME_CONTROLLER_NO_MEMORY](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |

### OH_GameDevice_DeviceInfo_GetDeviceType()

```c
GameController_ErrorCode OH_GameDevice_DeviceInfo_GetDeviceType(const struct GameDevice_DeviceInfo* deviceInfo, GameDevice_DeviceType* deviceType)
```

**描述**

从设备信息中获取设备类型。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const struct GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)* deviceInfo | 指针指向[GameDevice_DeviceInfo](capi-gamecontroller-gamedevice-deviceinfo.md)实例，不能为空。 |
| [GameDevice_DeviceType](capi-game-device-event-h.md#gamedevice_devicetype)* deviceType | 输出参数，设备类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [GameController_ErrorCode](capi-game-controller-type-h.md#gamecontroller_errorcode) | <ul><li>如果执行成功，返回[GAME_CONTROLLER_SUCCESS](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li>     <li>如果参数deviceInfo为null，返回[GAME_CONTROLLER_PARAM_ERROR](capi-game-controller-type-h.md#gamecontroller_errorcode)。</li></ul> |


