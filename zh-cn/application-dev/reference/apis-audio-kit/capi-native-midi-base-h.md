# native_midi_base.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明MIDI模块的基础数据结构，定义MIDI接口的基础类型、枚举、结构体和回调函数。MIDI模块提供标准化的MIDI数据通信能力，支持USB和BLE设备的连接与枚举，基于UMP格式兼容MIDI 1.0和MIDI 2.0协议，适用于音乐演奏数据传输、MIDI设备控制等需要与外部MIDI硬件交互的场景。

**引用文件：** <ohmidi/native_midi_base.h>

**库：** libohmidi.so

**系统能力：** SystemCapability.Multimedia.Audio.MIDI

**起始版本：** 24

**相关模块：** [OHMIDI](capi-ohmidi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_MIDIEvent](capi-ohmidi-oh-midievent.md) | OH_MIDIEvent | MIDI事件结构体（通用）。事件数据以UMP（Universal MIDI Packet）格式传输。原始字节流（MIDI 1.0）数据需要先转换为UMP格式后再填充此结构体。|
| [OH_MIDIDeviceInformation](capi-ohmidi-oh-midideviceinformation.md) | OH_MIDIDeviceInformation | 设备信息结构体。存储设备ID、设备名称等信息。 |
| [OH_MIDIPortInformation](capi-ohmidi-oh-midiportinformation.md) | OH_MIDIPortInformation | 端口信息结构体。用于枚举端口，包含可显示的端口名称。 |
| [OH_MIDIPortDescriptor](capi-ohmidi-oh-midiportdescriptor.md) | OH_MIDIPortDescriptor | 端口描述符结构体，用于打开端口时指定端口索引和协议行为。 |
| [OH_MIDICallbacks](capi-ohmidi-oh-midicallbacks.md) | OH_MIDICallbacks | 客户端回调结构体，包含设备变化和错误处理的回调函数。 |
| [OH_MIDIClientStruct](capi-ohmidi-oh-midiclientstruct.md) | OH_MIDIClient | 声明MIDI客户端。 |
| [OH_MIDIDeviceStruct](capi-ohmidi-oh-mididevicestruct.md) | OH_MIDIDevice | 声明MIDI设备。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_MIDIStatusCode](#oh_midistatuscode) | OH_MIDIStatusCode | MIDI状态码枚举。定义MIDI操作的状态码，用于表示操作成功或失败的原因。 |
| [OH_MIDIPortDirection](#oh_midiportdirection) | OH_MIDIPortDirection | 表示端口方向的枚举。定义MIDI端口的数据传输方向。 |
| [OH_MIDIProtocol](#oh_midiprotocol) | OH_MIDIProtocol | MIDI协议版本枚举，用于指定端口使用的MIDI协议行为。 |
| [OH_MIDIDeviceType](#oh_mididevicetype) | OH_MIDIDeviceType | MIDI设备类型枚举。定义MIDI设备的连接类型。 |
| [OH_MIDIDeviceChangeAction](#oh_mididevicechangeaction) | OH_MIDIDeviceChangeAction | 设备连接状态变化操作枚举。用于标识设备的连接和断开事件。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_MIDICallback_OnDeviceChange)(void *userData, OH_MIDIDeviceChangeAction action, OH_MIDIDeviceInformation deviceInfo)](#oh_midicallback_ondevicechange) | OH_MIDICallback_OnDeviceChange | 监控设备连接/断开连接的回调。 |
| [typedef void (\*OH_MIDICallback_OnError)(void *userData, OH_MIDIStatusCode code)](#oh_midicallback_onerror) | OH_MIDICallback_OnError | 处理客户端级别错误的回调。当MIDI服务发生关键错误（如服务崩溃）时调用。应用可能需要重新创建客户端。 |
| [typedef void (\*OH_MIDIDevice_OnReceived)(void *userData, const OH_MIDIEvent *events, size_t eventCount)](#oh_mididevice_onreceived) | OH_MIDIDevice_OnReceived | 接收MIDI数据的回调（批量处理）。 |
| [typedef void (\*OH_MIDIClient_OnDeviceOpened)(void *userData, bool opened, OH_MIDIDevice *device, OH_MIDIDeviceInformation info)](#oh_midiclient_ondeviceopened) | OH_MIDIClient_OnDeviceOpened | 异步打开BLE设备的结果回调。 |

## 枚举类型说明

### OH_MIDIStatusCode

```c
enum OH_MIDIStatusCode
```

**描述**

MIDI状态码枚举。定义MIDI操作的状态码，用于表示操作成功或失败的原因。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_MIDI_STATUS_OK = 0 |  操作成功。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_GENERIC_INVALID_ARGUMENT = 35500001 |  无效参数（例如：空指针）。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_GENERIC_IPC_FAILURE = 35500002 |  IPC通信失败。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_INVALID_CLIENT = 35500003 |  无效的客户端句柄。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_INVALID_DEVICE_HANDLE = 35500004 |  无效的设备句柄。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_INVALID_PORT = 35500005 |  无效的端口索引。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_WOULD_BLOCK = 35500006 |  发送缓冲区暂时已满。表示共享内存缓冲区当前空间不足。<br> 当消息无法放入缓冲区时由非阻塞发送返回。建议等待约10ms后重试。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_TIMEOUT = 35500007 |  操作超时。可能由于设备响应缓慢或系统资源不足导致。建议检查设备连接状态后重试。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_TOO_MANY_OPEN_DEVICES = 35500008 |  客户端已达到允许打开的最大设备数量（16个）。<br> 要打开新设备，必须先关闭现有设备。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_TOO_MANY_OPEN_PORTS = 35500009 |  客户端已达到允许打开的最大端口数量（64个）。<br> 要打开新端口，必须先关闭现有端口。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_DEVICE_ALREADY_OPEN = 35500010 |  客户端已经打开此设备。同一设备在同一客户端中不允许重复打开。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_PORT_ALREADY_OPEN = 35500011 |  客户端已经打开此端口。同一端口在同一客户端中不允许重复打开。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_TOO_MANY_CLIENTS = 35500012 |  系统级（8个）或应用级（2个/UID）客户端数量已达上限。应用应等待其他客户端关闭，或关闭不再使用的客户端后重试。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_PERMISSION_DENIED = 35500013 |  权限被拒绝。当应用尝试在未获得所需权限（例如BLE设备的蓝牙权限）的情况下执行操作时返回。请在配置文件中声明所需权限并引导用户授权后重试。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_SERVICE_DIED = 35500014 |  MIDI系统服务已崩溃或断开连接。必须销毁并重新创建客户端。<br>**起始版本：** 24 |
| OH_MIDI_STATUS_SYSTEM_ERROR = 35500100 |  系统内部错误。表示发生了未预期的系统级错误。建议稍后重试操作，如问题持续存在，请重启应用或检查系统状态。<br>**起始版本：** 24 |

### OH_MIDIPortDirection

```c
enum OH_MIDIPortDirection
```

**描述**

表示端口方向的枚举。定义MIDI端口的数据传输方向。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_MIDI_PORT_DIRECTION_INPUT = 0 | 输入端口（设备->主机）。<br>**起始版本：** 24 |
| OH_MIDI_PORT_DIRECTION_OUTPUT = 1 | 输出端口（主机->设备）。<br>**起始版本：** 24 |

### OH_MIDIProtocol

```c
enum OH_MIDIProtocol
```

**描述**

MIDI协议版本枚举，用于指定端口使用的MIDI协议行为。

> **说明：** 
> 
> SDK始终使用UMP（Universal MIDI Packet）格式进行数据传输，无论选择何种协议。此枚举定义连接的数据行为和语义，而不是数据结构。MT（Message Type，消息类型）是UMP数据包的消息类型标识，不同MT值对应不同类型的MIDI消息。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_MIDI_PROTOCOL_1_0 = 1 | 传统MIDI 1.0语义。<br> 在此协议下，MIDI系统服务期望接收以下UMP消息类型：<br> - 严格遵循MIDI 1.0协议规范的UMP数据包。<br> - MT 0x0：实用消息（例如时间戳）。<br> - MT 0x1：系统实时和系统公共消息。<br> - MT 0x2：MIDI 1.0通道声音消息（32位）。<br> - MT 0x3：数据消息（64位），用于SysEx（7位载荷）。<br> - 如果目标硬件是MIDI 1.0：服务将UMP转换回字节流（F0...F7）。<br> - 如果目标硬件是MIDI 2.0：服务直接发送未经转换的UMP包（封装的MIDI 1.0）。<br>**起始版本：** 24 |
| OH_MIDI_PROTOCOL_2_0 = 2 | MIDI 2.0语义。<br> 在此协议下，MIDI系统服务期望接收以下UMP消息类型：<br> - 利用MIDI 2.0功能特性的UMP数据包。<br> - MT 0x4：MIDI 2.0通道声音消息（64位，高分辨率）。<br> - MT 0x0：实用消息（时间戳）。<br> - MT 0xD：Flex数据消息（128位，例如文本、歌词）。<br> - MT 0xF：UMP流消息（128位，端点发现、功能块）。<br> - MT 0x3 / MT 0x5：数据消息（64位或128位）。<br>**起始版本：** 24 |

### OH_MIDIDeviceType

```c
enum OH_MIDIDeviceType
```

**描述**

MIDI设备类型枚举。定义MIDI设备的连接类型。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_MIDI_DEVICE_TYPE_USB = 0 | USB MIDI设备。 |
| OH_MIDI_DEVICE_TYPE_BLE = 1 | BLE（蓝牙低功耗）MIDI设备。 |

### OH_MIDIDeviceChangeAction

```c
enum OH_MIDIDeviceChangeAction
```

**描述**

设备连接状态变化操作枚举。用于标识设备的连接和断开事件。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_MIDI_DEVICE_CHANGE_ACTION_CONNECTED = 0 | 设备已连接。<br>**起始版本：** 24 |
| OH_MIDI_DEVICE_CHANGE_ACTION_DISCONNECTED = 1 | 设备已断开。<br>**起始版本：** 24 |


## 函数说明

### OH_MIDICallback_OnDeviceChange()

```c
typedef void (*OH_MIDICallback_OnDeviceChange)(void *userData, OH_MIDIDeviceChangeAction action, OH_MIDIDeviceInformation deviceInfo)
```

**描述**

监控设备连接/断开连接的回调。

> **说明：**
> 
> 此回调在系统线程上调用，不要在此回调中执行阻塞操作、大量计算或I/O操作。

**起始版本：** 24

**参数：**

| 参数项 | 描述                                                                                   |
| -- |--------------------------------------------------------------------------------------|
| void \*userData | 调用[OH_MIDIClient_Create](./capi-native-midi-h.md#oh_midiclient_create)时传入的用户自定义数据指针。 |
| [OH_MIDIDeviceChangeAction](capi-native-midi-base-h.md#oh_mididevicechangeaction) action | 设备变化操作（已连接/已断开）。                                                                     |
| [OH_MIDIDeviceInformation](capi-ohmidi-oh-midideviceinformation.md) deviceInfo | 变化设备的信息。<br>此对象仅在此回调范围内有效。如需持久化特定属性（如ID或名称），请对该设备信息进行复制。                                                                             |

### OH_MIDICallback_OnError()

```c
typedef void (*OH_MIDICallback_OnError)(void *userData, OH_MIDIStatusCode code)
```

**描述**

处理客户端级别错误的回调。当MIDI服务发生关键错误（如服务崩溃）时调用。应用可能需要重新创建客户端。

> **说明：**
> 
> 此回调在系统线程上调用，不要在此回调中执行阻塞操作、大量计算或I/O操作。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void \*userData | 调用[OH_MIDIClient_Create](./capi-native-midi-h.md#oh_midiclient_create)时传入的用户自定义数据指针。 |
| [OH_MIDIStatusCode](capi-native-midi-base-h.md#oh_midistatuscode) code | 错误状态码，指示错误原因。 |

### OH_MIDIDevice_OnReceived()

```c
typedef void (*OH_MIDIDevice_OnReceived)(void *userData, const OH_MIDIEvent *events, size_t eventCount)
```

**描述**

接收MIDI数据的回调（批量处理）。

> **说明：** 
> 
> 内存安全与线程安全注意事项：
> - 内存安全：events数组及其中所有数据指针是临时的，仅在此回调期间有效。在回调返回后访问这些指针会导致未定义行为（崩溃、内存损坏）。调用方必须复制任何需要保留的数据。
> - 线程安全：此回调在高优先级系统线程上调用。不要执行阻塞操作、大量计算或I/O操作。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void \*userData | 调用[OH_MIDIDevice_OpenInputPort](./capi-native-midi-h.md#oh_mididevice_openinputport)时传入的用户自定义数据指针。 |
| const [OH_MIDIEvent](capi-ohmidi-oh-midievent.md) \*events | 指向接收到的MIDI事件数组的指针。<br> events数组及其中所有数据指针仅在此回调范围内有效。如需保留数据，请先进行复制。 |
| size_t eventCount | 数组中的事件数。 |

### OH_MIDIClient_OnDeviceOpened()

```c
typedef void (*OH_MIDIClient_OnDeviceOpened)(void *userData, bool opened, OH_MIDIDevice *device, OH_MIDIDeviceInformation info)
```

**描述**

异步打开BLE设备的结果回调。

> **说明：**
> 
> 此回调在系统线程上调用，不要在此回调中执行阻塞操作、大量计算或I/O操作。

**起始版本：** 24

**参数：**

| 参数项 | 描述                                                                                                                                                        |
| -- |-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| void \*userData | 调用[OH_MIDIClient_OpenBLEDevice](./capi-native-midi-h.md#oh_midiclient_openbledevice)时传入的用户自定义数据指针。                                                        |
| bool opened | 设备是否成功打开。<br> true表示设备成功打开，设备句柄有效；false表示设备打开失败，设备句柄为NULL。                                                                                                |
| [OH_MIDIDevice](capi-ohmidi-oh-mididevicestruct.md) \*device | 已打开设备的句柄。<br> 如果opened为true，应用必须在不再需要时调用[OH_MIDIClient_CloseDevice](./capi-native-midi-h.md#oh_midiclient_closedevice)关闭此句柄。<br> 如果opened为false，此参数为NULL。 |
| [OH_MIDIDeviceInformation](capi-ohmidi-oh-midideviceinformation.md) info | 已打开设备的信息。<br> 如果opened为false，此参数的内容无效。<br> 此对象仅在此回调范围内有效。如需持久化特定属性（如ID或名称），请对该设备信息进行复制。                                                                                        |


