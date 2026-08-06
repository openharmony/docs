# 使用OH_MIDI进行MIDI开发(C/C++)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @owen_creeper-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 场景介绍

OH_MIDI是系统提供的Native MIDI API，从API version 24开始用于在C/C++层实现MIDI应用开发。当应用需要与外接MIDI设备（如USB MIDI键盘、蓝牙MIDI设备）进行数据交互时，可以使用OH_MIDI。典型使用场景包括：

- **音乐创作应用**：连接MIDI键盘，实时接收弹奏的音符并触发音源播放。
- **乐器学习/教学应用**：将MIDI键盘的弹奏数据接入应用，实现评分、伴奏等功能。
- **MIDI控制器应用**：通过应用向外接MIDI设备发送控制指令（如切换音色、调节参数）。
- **MIDI数据处理工具**：接收、解析和转发MIDI消息，用于音乐制作或设备调试。

通过OH_MIDI，开发者可以实现以下功能：

- 创建MIDI客户端并管理与MIDI服务的连接。
- 枚举和管理MIDI设备。
- 打开和管理MIDI端口。
- 发送和接收MIDI消息。
- 处理MIDI事件和回调。
- 实现低延迟的MIDI数据传输。

## 系统能力检查

使用MIDI进行开发前，先调用接口[canIUse](../../reference/common/init.md#caniuse)判断当前设备是否支持MIDI能力。当canIUse("SystemCapability.Multimedia.Audio.MIDI")返回值为true时，表示可以使用MIDI能力。

## 接口说明

OH_MIDI的主要接口包括：

- 客户端管理接口：[OH_MIDIClient_Create](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_create)、[OH_MIDIClient_Destroy](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_destroy)。
- 设备管理接口：[OH_MIDIClient_GetDeviceCount](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getdevicecount)、[OH_MIDIClient_GetDeviceInfos](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getdeviceinfos)、[OH_MIDIClient_OpenDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_opendevice)、[OH_MIDIClient_CloseDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_closedevice)。
- 端口管理接口：[OH_MIDIClient_GetPortCount](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getportcount)、[OH_MIDIClient_GetPortInfos](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getportinfos)、[OH_MIDIDevice_OpenInputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_openinputport)、[OH_MIDIDevice_OpenOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_openoutputport)、[OH_MIDIDevice_CloseInputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_closeinputport)、[OH_MIDIDevice_CloseOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_closeoutputport)。
- 数据传输接口：[OH_MIDIDevice_Send](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_send)、[OH_MIDIDevice_SendSysEx](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_sendsysex)。
- 回调接口：[OH_MIDICallback_OnDeviceChange](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_midicallback_ondevicechange)、[OH_MIDIDevice_OnReceived](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_mididevice_onreceived)。

## 开发准备

在使用OH_MIDI API之前，需要完成以下准备工作：

- 在CMake脚本中链接动态库。

  <!-- @[ohmidi_cmake](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/CMakeLists.txt) -->
  
  ``` Text
  target_link_libraries(entry PUBLIC
      libace_napi.z.so
      libohmidi.so
      libhilog_ndk.z.so
  )
  ```

- 添加头文件。

  ``` C++
  #include "native_midi.h"
  #include "native_midi_base.h"
  #include <hilog/log.h>
  ```

## 声明权限

MIDI功能的权限需求根据使用场景不同而有所区别。

**场景一：仅使用USB MIDI设备。**

无需额外权限声明。

**场景二：发现和连接BLE MIDI设备。**

在`module.json5`中声明蓝牙权限：

```json
"requestPermissions": [
    {
        "name": "ohos.permission.ACCESS_BLUETOOTH",
        "reason": "$string:bluetooth_permission_reason"
    }
]
```

## 开发步骤

### 创建MIDI客户端

创建MIDI客户端是使用MIDI API的第一步。

客户端是应用与MIDI系统服务的连接入口，负责管理与MIDI服务的所有交互。创建客户端前，需要先准备回调结构体：

系统已定义[OH_MIDICallbacks](../../reference/apis-audio-kit/capi-ohmidi-oh-midicallbacks.md)结构体，开发者需要实现其中的回调函数：
- onDeviceChange：当MIDI设备连接或断开时由系统自动调用。开发者在此回调中处理设备的接入和移除逻辑。
- onError：当MIDI服务发生错误时调用。开发者在此回调中处理错误日志记录和异常恢复逻辑，如重新创建客户端。

通过调用[OH_MIDIClient_Create](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_create)接口创建MIDI客户端实例，传入回调结构体和用户数据。

<!-- @[create_midi_client](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
// 创建MIDI客户端。
static napi_value CreateMIDIClient(napi_env env, napi_callback_info info)
{
    // ...
    std::lock_guard<std::mutex> lock(g_midiMutex);
    // ...
    OH_MIDIStatusCode status = OH_MIDIClient_Create(&g_midiClient, g_midiCallbacks, nullptr);
    // ...
}
```

### 销毁MIDI客户端

当不再需要MIDI功能时，应销毁客户端以释放资源。销毁前需要先关闭所有已打开的设备。

通过调用[OH_MIDIClient_Destroy](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_destroy)接口销毁MIDI客户端实例，释放所有关联资源。

<!-- @[cleanup_destroy_client](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static napi_value DestroyMIDIClient(napi_env env, napi_callback_info info)
{
    // ...
    std::lock_guard<std::mutex> lock(g_midiMutex);

    if (g_midiClient != nullptr) {
        CloseAllOpenedDevices();
        OH_MIDIClient_Destroy(g_midiClient);
        g_midiClient = nullptr;
    }
    CleanupAllPortContexts();

    // ...
}
```

### 枚举MIDI设备

创建客户端后，可以枚举系统中当前可用的MIDI设备。枚举设备分为两步：

1. 获取设备数量：调用[OH_MIDIClient_GetDeviceCount](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getdevicecount)接口获取当前连接的设备数量。

2. 获取设备信息：分配足够大的缓冲区，调用[OH_MIDIClient_GetDeviceInfos](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getdeviceinfos)接口填充设备详细信息。

> **注意：**
>
> - 如果应用未获得蓝牙权限（ohos.permission.ACCESS_BLUETOOTH），蓝牙MIDI设备将不会包含在枚举结果中。
> - 当应用获取蓝牙权限后，需重新枚举MIDI设备以获取已连接的蓝牙MIDI设备。

通过[OH_MIDIClient_GetDeviceCount](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getdevicecount)接口获取设备数量，再通过[OH_MIDIClient_GetDeviceInfos](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getdeviceinfos)接口获取设备详细信息。

<!-- @[get_device_infos](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static napi_value GetDeviceInfos(napi_env env, napi_callback_info info)
{
    std::lock_guard<std::mutex> lock(g_midiMutex);
    // ...

    size_t count = 0;
    OH_MIDIStatusCode status = OH_MIDIClient_GetDeviceCount(g_midiClient, &count);
    // ...
    std::vector<OH_MIDIDeviceInformation> devices(count);
    size_t actualCount = 0;
    status = OH_MIDIClient_GetDeviceInfos(g_midiClient, devices.data(), count, &actualCount);
    // ...
}
```

### 打开MIDI设备

需要打开设备才能进行数据传输。根据设备类型不同，打开方式有所区别：USB MIDI设备通过[OH_MIDIClient_OpenDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_opendevice)接口同步打开，BLE MIDI设备通过[OH_MIDIClient_OpenBLEDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_openbledevice)接口异步打开。

**打开USB MIDI设备（同步）**

通过[OH_MIDIClient_OpenDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_opendevice)接口同步打开USB MIDI设备，传入设备ID获取设备句柄。

<!-- @[open_device](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static napi_value OpenDevice(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int64_t deviceId = 0;
    napi_get_value_int64(env, args[0], &deviceId);
    std::lock_guard<std::mutex> lock(g_midiMutex);
    // ...
    OH_MIDIDevice *device = nullptr;
    OH_MIDIStatusCode status = OH_MIDIClient_OpenDevice(g_midiClient, deviceId, &device);
    if (status == OH_MIDI_STATUS_OK && device != nullptr) {
        g_openedDevices[deviceId] = device;
        OH_LOG_INFO(LOG_APP, "[OpenDevice] device stored, total opened devices=%{public}zu", g_openedDevices.size());
    }
    // ...
}
```

**打开BLE MIDI设备（异步）**

BLE MIDI设备的打开是异步操作，使用[OH_MIDIClient_OpenBLEDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_openbledevice)接口。

BLE设备地址可通过以下方式获取：

1. BLE扫描发现：使用蓝牙API扫描MIDI BLE设备。

2. 历史记录：从持久化存储加载之前连接过的设备地址。

3. 用户输入：让用户手动输入MAC地址。

MIDI BLE设备可通过服务UUID `03B80E5A-EDE8-4B33-A751-6CE34EC4C700` 进行过滤识别。

通过[OH_MIDIClient_OpenBLEDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_openbledevice)接口异步打开BLE MIDI设备，传入设备MAC地址和结果回调。

<!-- @[open_ble_device](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
// 异步打开BLE设备。
static napi_value OpenBLEDevice(napi_env env, napi_callback_info info)
{
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 获取设备地址。
    size_t addrLen = 0;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &addrLen);
    std::string deviceAddr(addrLen, '\0');
    napi_get_value_string_utf8(env, args[0], &deviceAddr[0], addrLen + 1, &addrLen);

    // ...

    std::lock_guard<std::mutex> lock(g_midiMutex);

    // ...
    OH_MIDIStatusCode status = OH_MIDIClient_OpenBLEDevice(g_midiClient, deviceAddr.c_str(),
                                                           OnBLEDeviceOpened, nullptr);
    // ...
}
```

通过[OH_MIDIClient_OnDeviceOpened](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_midiclient_ondeviceopened)回调接收BLE设备打开结果，在回调中获取设备句柄和设备信息。

<!-- @[ble_device_opened_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static void OnBLEDeviceOpened(void *userData, bool opened, OH_MIDIDevice *device, OH_MIDIDeviceInformation info)
{
    std::string deviceAddr = info.deviceAddress;
    // ...
}
```

> **注意：**
>
> - BLE设备连接是异步连接，结果通过回调返回。
> - 回调在非主线程执行，如需更新UI请使用线程安全机制。
> - 连接成功后，后续的端口操作应在回调中进行。
> - 使用`OH_MIDIClient_CloseDevice`关闭设备。

### 关闭MIDI设备

通过[OH_MIDIClient_CloseDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_closedevice)接口关闭已打开的MIDI设备，释放设备资源。

<!-- @[close_device](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
static napi_value CloseDevice(napi_env env, napi_callback_info info)
{
    // ...
    std::lock_guard<std::mutex> lock(g_midiMutex);
    // ...
    auto it = g_openedDevices.find(deviceId);
    if (it != g_openedDevices.end()) {
        // 清理该设备的所有InputPortContext
        CleanupInputPortContextsForDevice(deviceId);
        OH_MIDIStatusCode status = OH_MIDIClient_CloseDevice(g_midiClient, it->second);
        g_openedDevices.erase(it);
        // ...
    } else {
        // ...
    }

    // ...
    return result;
}
```

### 获取端口信息

打开设备后，需要获取设备的端口信息并打开输入或输出端口来发送或接收MIDI数据。

每个MIDI设备可能提供多个端口，每个端口都有明确的方向（输入或输出）。需要先枚举所有端口，根据应用需求找到对应的输入端口和输出端口，然后分别打开。

通过[OH_MIDIClient_GetPortCount](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getportcount)接口获取端口数量，再通过[OH_MIDIClient_GetPortInfos](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_getportinfos)接口获取端口详细信息。

<!-- @[get_port_infos](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static napi_value GetPortInfos(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int64_t deviceId = 0;
    napi_get_value_int64(env, args[0], &deviceId);
    // ...

    std::lock_guard<std::mutex> lock(g_midiMutex);

    // ...

    size_t count = 0;
    OH_MIDIStatusCode status = OH_MIDIClient_GetPortCount(g_midiClient, deviceId, &count);
    // ...

    std::vector<OH_MIDIPortInformation> ports(count);
    size_t actualCount = 0;
    status = OH_MIDIClient_GetPortInfos(g_midiClient, deviceId, ports.data(), count, &actualCount);
    // ...
}
```

### MIDI端口管理

**打开输入端口**

接收MIDI消息，需要打开输入端口并注册接收回调函数。当设备发送MIDI数据时，回调函数会被调用。

回调函数应在独立线程中执行，需要使用互斥锁或其他同步机制来保证线程安全。回调中的events数据仅在此回调期间有效，如需保留必须复制。

通过[OH_MIDIDevice_OnReceived](../../reference/apis-audio-kit/capi-native-midi-base-h.md#oh_mididevice_onreceived)回调接收MIDI数据，回调中获取事件数组及其数据。

<!-- @[midi_received_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
static void OnMIDIReceived(void *userData, const OH_MIDIEvent *events, size_t eventCount)
{
    // userData指向InputPortContext。
    InputPortContext* context = static_cast<InputPortContext*>(userData);
    // ...
}
```

通过[OH_MIDIDevice_OpenInputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_openinputport)接口打开输入端口，传入[OH_MIDIPortDescriptor](../../reference/apis-audio-kit/capi-ohmidi-oh-midiportdescriptor.md)结构配置端口参数，并注册数据接收回调。

<!-- @[open_input_port](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
static napi_value OpenInputPort(napi_env env, napi_callback_info info)
{
    InputPortArgs args = ParseInputPortArgs(env, info);

    std::lock_guard<std::mutex> lock(g_midiMutex);

    napi_value result;
    auto it = g_openedDevices.find(args.deviceId);
    if (g_midiClient == nullptr || it == g_openedDevices.end()) {
        OH_LOG_ERROR(LOG_APP, "[OpenInputPort] client is null or device not opened");
        napi_create_int32(env, static_cast<int32_t>(OH_MIDI_STATUS_INVALID_DEVICE_HANDLE), &result);
        return result;
    }

    // 构造端口描述符。
    OH_MIDIPortDescriptor descriptor;
    descriptor.portIndex = args.portIndex;
    descriptor.protocol = static_cast<OH_MIDIProtocol>(args.protocol);

    // 创建输入端口上下文，用于线程安全回调处理。
    auto context = std::make_shared<InputPortContext>(args.deviceId, args.portIndex);

    OH_MIDIStatusCode status = OH_MIDIDevice_OpenInputPort(it->second, descriptor, OnMIDIReceived, context.get());
    // ...
}
```

**关闭输入端口**

使用[OH_MIDIDevice_CloseInputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_closeinputport)接口关闭已打开的输入端口。关闭端口后，该端口将不再接收MIDI消息，注册的回调函数也将不再被调用。

<!-- @[close_input_port](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
// 关闭输入端口。
static napi_value CloseInputPort(napi_env env, napi_callback_info info)
{
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int64_t deviceId = 0;
    napi_get_value_int64(env, args[0], &deviceId);

    uint32_t portIndex = 0;
    napi_get_value_uint32(env, args[1], &portIndex);

    OH_LOG_INFO(LOG_APP, "[CloseInputPort] ++enter, deviceId=%{public}lld, portIndex=%{public}u",
                (long long)deviceId, portIndex);

    std::lock_guard<std::mutex> lock(g_midiMutex);

    napi_value result;
    auto it = g_openedDevices.find(deviceId);
    if (g_midiClient == nullptr || it == g_openedDevices.end()) {
        OH_LOG_ERROR(LOG_APP, "[CloseInputPort] client is null or device not opened");
        napi_create_int32(env, static_cast<int32_t>(OH_MIDI_STATUS_INVALID_DEVICE_HANDLE), &result);
        return result;
    }

    OH_MIDIStatusCode status = OH_MIDIDevice_CloseInputPort(it->second, portIndex);

    // 清理输入端口上下文。
    auto key = std::make_pair(deviceId, portIndex);
    auto contextIt = g_inputPortContexts.find(key);
    if (contextIt != g_inputPortContexts.end()) {
        if (contextIt->second != nullptr) {
            contextIt->second->Stop();
        }
        g_inputPortContexts.erase(contextIt);
    }
    // ...
}
```

**打开输出端口**

通过[OH_MIDIDevice_OpenOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_openoutputport)接口打开输出端口，传入[OH_MIDIPortDescriptor](../../reference/apis-audio-kit/capi-ohmidi-oh-midiportdescriptor.md)结构配置端口参数和协议。

<!-- @[open_output_port](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
static napi_value OpenOutputPort(napi_env env, napi_callback_info info)
{
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int64_t deviceId = 0;
    napi_get_value_int64(env, args[0], &deviceId);

    uint32_t portIndex = 0;
    napi_get_value_uint32(env, args[1], &portIndex);

    int32_t protocol = static_cast<int32_t>(MIDI_PROTOCOL_1_0); // 默认使用MIDI 1.0协议。
    napi_get_value_int32(env, args[MIDI_ARG_INDEX_2], &protocol);

    OH_LOG_INFO(LOG_APP, "[OpenOutputPort] ++enter, deviceId=%{public}lld, portIndex=%{public}u, protocol=%{public}d",
                (long long)deviceId, portIndex, protocol);

    std::lock_guard<std::mutex> lock(g_midiMutex);

    napi_value result;
    auto it = g_openedDevices.find(deviceId);
    if (g_midiClient == nullptr || it == g_openedDevices.end()) {
        OH_LOG_ERROR(LOG_APP, "[OpenOutputPort] client is null or device not opened");
        napi_create_int32(env, static_cast<int32_t>(OH_MIDI_STATUS_INVALID_DEVICE_HANDLE), &result);
        return result;
    }

    OH_MIDIPortDescriptor descriptor;
    descriptor.portIndex = portIndex;
    descriptor.protocol = static_cast<OH_MIDIProtocol>(protocol);
    
    OH_MIDIStatusCode status = OH_MIDIDevice_OpenOutputPort(it->second, descriptor);
    // ...
}
```

**关闭输出端口**

使用[OH_MIDIDevice_CloseOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_closeoutputport)接口关闭已打开的输出端口。关闭端口后，将无法再通过该端口发送MIDI消息。

<!-- @[close_output_port](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
// 关闭输出端口。
static napi_value CloseOutputPort(napi_env env, napi_callback_info info)
{
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int64_t deviceId = 0;
    napi_get_value_int64(env, args[0], &deviceId);

    uint32_t portIndex = 0;
    napi_get_value_uint32(env, args[1], &portIndex);

    OH_LOG_INFO(LOG_APP, "[CloseOutputPort] ++enter, deviceId=%{public}lld, portIndex=%{public}u",
                (long long)deviceId, portIndex);

    std::lock_guard<std::mutex> lock(g_midiMutex);

    napi_value result;
    auto it = g_openedDevices.find(deviceId);
    if (g_midiClient == nullptr || it == g_openedDevices.end()) {
        OH_LOG_ERROR(LOG_APP, "[CloseOutputPort] client is null or device not opened");
        napi_create_int32(env, static_cast<int32_t>(OH_MIDI_STATUS_INVALID_DEVICE_HANDLE), &result);
        return result;
    }
    OH_MIDIStatusCode status = OH_MIDIDevice_CloseOutputPort(it->second, portIndex);
    // 移除此输出端口的协议信息。
    if (status == OH_MIDI_STATUS_OK) {
        auto key = std::make_pair(deviceId, portIndex);
        g_outputPortProtocols.erase(key);
    }
    // ...
}
```

### 发送MIDI消息

发送MIDI消息需要先构造UMP（Universal MIDI Packet）格式的数据，再通过[OH_MIDIDevice_Send](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_send)接口发送。UMP是Universal MIDI Packet的缩写，是MIDI 2.0标准统一使用的数据包格式。

**发送自定义MIDI消息**

构造[OH_MIDIEvent](../../reference/apis-audio-kit/capi-ohmidi-oh-midievent.md)事件数组，通过[OH_MIDIDevice_Send](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_send)接口发送MIDI消息。

<!-- @[send_midi](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
static napi_value SendMIDI(napi_env env, napi_callback_info info)
{
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int64_t deviceId = 0;
    napi_get_value_int64(env, args[0], &deviceId);
    uint32_t portIndex = 0;
    napi_get_value_uint32(env, args[1], &portIndex);

    OH_LOG_DEBUG(LOG_APP, "[SendMIDI] deviceId=%{public}lld, portIndex=%{public}u", (long long)deviceId, portIndex);

    bool isArray = false;
    napi_is_array(env, args[MIDI_ARG_INDEX_2], &isArray);
    if (!isArray) {
        napi_value result;
        napi_create_int32(env, static_cast<int32_t>(OH_MIDI_STATUS_GENERIC_INVALID_ARGUMENT), &result);
        return result;
    }

    std::vector<OH_MIDIEvent> events;
    std::vector<std::vector<uint32_t>> eventDataBuffers;
    ParseMIDIEventsFromArray(env, args[MIDI_ARG_INDEX_2], events, eventDataBuffers);
    uint32_t eventCount = static_cast<uint32_t>(events.size());

    std::lock_guard<std::mutex> lock(g_midiMutex);
    napi_value result;
    auto it = g_openedDevices.find(deviceId);
    if (g_midiClient == nullptr || it == g_openedDevices.end()) {
        napi_create_int32(env, static_cast<int32_t>(OH_MIDI_STATUS_INVALID_DEVICE_HANDLE), &result);
        return result;
    }

    uint32_t eventsWritten = 0;
    OH_MIDIStatusCode status = OH_MIDIDevice_Send(it->second, portIndex, events.data(), eventCount, &eventsWritten);
    napi_create_object(env, &result);
    napi_value statusValue;
    napi_create_int32(env, static_cast<int32_t>(status), &statusValue);
    napi_set_named_property(env, result, "status", statusValue);
    napi_value writtenValue;
    napi_create_uint32(env, eventsWritten, &writtenValue);
    napi_set_named_property(env, result, "eventsWritten", writtenValue);
    return result;
```

**UMP格式说明**

OH_MIDI强制使用UMP（Universal MIDI Packet）格式。常用的MIDI 1.0通道消息（MT=0x2，32位）构造方式如下：

| 位 | 字段 | 说明 |
|---------|------|------|
| 31-28 | MT | 消息类型，MIDI 1.0通道消息为0x2。 |
| 27-24 | Group | 保留位，填0。 |
| 23-20 | Status | 状态码（如0x9=Note On，0x8=Note Off）。 |
| 19-16 | Channel | 通道号（0-15）。 |
| 15-8 | Data1 | 第一个数据字节（如音符编号）。 |
| 7-0 | Data2 | 第二个数据字节（如力度）。 |

**常用MIDI消息UMP构造示例**

<!-- @[ump_helper_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
// 构建MIDI 1.0音符开启UMP（一个32位无符号整数）。
static void BuildMIDI1NoteOn(uint32_t channel, uint32_t note, uint32_t velocity, uint32_t* umpData)
{
    // UMP格式（MIDI 1.0 Channel Voice - Note On）：第28~31位为消息类型(MT=0x2)，第24~27位为组号(Group=0x0)，
    // 第20~23位为状态码(Status=0x9)，第16~19位为通道号(Channel)，第8~15位为音符号(Note)，第0~7位为力度值(Velocity)。
    umpData[0] = (MIDI_UMP_MT_1_0 << MIDI_UMP_WORDS_28) | (0x0 << MIDI_UMP_SHIFT_24) |
                 (MIDI_UMP_STATUS_NOTE_ON << MIDI_UMP_SHIFT_20) |
                 ((channel & MIDI_CHANNEL_MASK) << MIDI_UMP_WORDS_16) |
                 ((note & MIDI_NOTE_MASK) << MIDI_UMP_SHIFT_8) | (velocity & MIDI_NOTE_MASK);
}

// 构建MIDI 1.0音符关闭UMP（一个32位无符号整数）。
static void BuildMIDI1NoteOff(uint32_t channel, uint32_t note, uint32_t velocity, uint32_t* umpData)
{
    // UMP格式（MIDI 1.0 Channel Voice - Note Off）：第28~31位为消息类型(MT=0x2)，第24~27位为组号(Group=0x0)，
    // 第20~23位为状态码(Status=0x8)，第16~19位为通道号(Channel)，第8~15位为音符号(Note)，第0~7位为力度值(Velocity)。
    umpData[0] = (MIDI_UMP_MT_1_0 << MIDI_UMP_WORDS_28) | (0x0 << MIDI_UMP_SHIFT_24) |
                 (MIDI_UMP_STATUS_NOTE_OFF << MIDI_UMP_SHIFT_20) |
                 ((channel & MIDI_CHANNEL_MASK) << MIDI_UMP_WORDS_16) |
                 ((note & MIDI_NOTE_MASK) << MIDI_UMP_SHIFT_8) | (velocity & MIDI_NOTE_MASK);
}
```

**常用CC控制器编号参考**

| 编号 | 名称 | 用途 |
|------|------|------|
| 1 | Modulation Wheel | 颤音深度 |
| 7 | Volume | 音量 |
| 10 | Pan | 声像 |
| 11 | Expression | 表情 |
| 64 | Sustain Pedal | 延音踏板 |
| 65 | Portamento | 滑音 |
| 71 | Resonance | 共振 |
| 74 | Filter Cutoff | 滤波器截止 |

**发送系统独占消息(SysEx)**

系统独占消息（System Exclusive）：用于传输制造商特定的数据。使用[OH_MIDIDevice_SendSysEx](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_sendsysex)接口可以发送超过常规MIDI消息长度的SysEx消息。

``` C++
// 发送大型SysEx消息。
void SendSysExExample(OH_MIDIDevice *device, uint32_t outputPortIndex)
{
    // 构造SysEx数据。
    std::vector<uint8_t> sysexData;
    sysexData.push_back(0xF0);  // SysEx开始标志。
    // 添加厂商ID和数据。
    sysexData.push_back(0x43);  // 厂商ID示例。
    sysexData.push_back(0x10);
    sysexData.push_back(0x4C);
    sysexData.push_back(0x00);
    sysexData.push_back(0x00);
    sysexData.push_back(0x7E);
    sysexData.push_back(0xF7);  // SysEx结束标志。

    OH_MIDIStatusCode status = OH_MIDIDevice_SendSysEx(
        device, outputPortIndex, sysexData.data(), sysexData.size());

    if (status != OH_MIDI_STATUS_OK) {
        OH_LOG_ERROR(LOG_APP, "[SendSysEx] Failed: %{public}d", (int)status);
    }
}
```

### 清空输出缓冲区

通过[OH_MIDIDevice_FlushOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_flushoutputport)接口清空指定端口的输出缓冲区，丢弃所有待发送消息。

<!-- @[flush_output_port](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static napi_value FlushOutputPort(napi_env env, napi_callback_info info)
{
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int64_t deviceId = 0;
    napi_get_value_int64(env, args[0], &deviceId);

    uint32_t portIndex = 0;
    napi_get_value_uint32(env, args[1], &portIndex);

    std::lock_guard<std::mutex> lock(g_midiMutex);

    napi_value result;
    auto it = g_openedDevices.find(deviceId);
    if (g_midiClient == nullptr || it == g_openedDevices.end()) {
        OH_LOG_ERROR(LOG_APP, "[FlushOutputPort] client is null or device not opened");
        napi_create_int32(env, static_cast<int32_t>(OH_MIDI_STATUS_INVALID_DEVICE_HANDLE), &result);
        return result;
    }

    OH_MIDIStatusCode status = OH_MIDIDevice_FlushOutputPort(it->second, portIndex);
    // ...
}
```

### 使用userData传递上下文数据

OH_MIDI API提供客户端级别、BLE连接级别和端口连接级别三个层级的userData参数，分别传递给不同作用域的回调。

| API | userData范围 | 传递给的回调 | 典型用途 |
|-----|-------------|-------------|---------|
| `OH_MIDIClient_Create` | 客户端级别 | `onDeviceChange`、`onError` | 全局应用状态、设备管理。 |
| `OH_MIDIClient_OpenBLEDevice` | BLE连接级别 | `OnBLEDeviceOpened` | 区分并发连接请求、携带连接上下文。 |
| `OH_MIDIDevice_OpenInputPort` | 端口级别 | `OnMIDIReceived` | 端口特定的处理逻辑。 |

> **注意：**
>
> 三个userData是独立的，可以传递不同的上下文对象。端口关闭后，对应的回调不再被调用，此时释放端口级userData是安全的。

**userData使用场景对比**

| 场景 | 推荐使用 | 示例数据 |
|------|---------|---------|
| 设备热插拔处理 | 客户端级 | 设备列表、连接状态。 |
| 错误日志记录 | 客户端级 | 日志文件句柄、错误计数。 |
| 端口事件统计 | 端口级 | 事件计数、时间戳记录。 |
| 多端口区分处理 | 端口级 | 端口ID、端口名称。 |
| 跨回调共享状态 | 客户端级 | 应用配置、全局状态。 |

## 注意事项

1. 资源管理顺序：关闭客户端时会自动关闭所有设备和端口。建议应用按端口->设备->客户端的顺序关闭资源，以保证代码逻辑清晰。

2. 线程安全：MIDI回调函数（`OnMIDIReceived`、`OnDeviceChange`、`OnError`）在独立的线程中执行。需要注意线程安全，即访问共享资源时应该使用互斥锁等同步机制。

3. 内存安全：`OnMIDIReceived`回调中的`events`数组及其中所有数据指针是临时的，仅在此回调期间有效。必须在回调返回前复制任何需要保留的数据。访问过期指针会导致未定义行为（崩溃、内存损坏）。

4. 错误处理：所有MIDI接口调用都应该检查返回值，并正确处理错误情况。

5. 性能优化：在回调函数中禁止执行超过1毫秒的操作或阻塞I/O，以确保MIDI消息的实时处理不受影响。在回调中执行耗时操作或阻塞I/O会严重影响MIDI消息的实时处理，可能导致音频延迟或丢帧。

6. UMP格式：SDK始终使用UMP（Universal MIDI Packet）格式进行数据传输，无论选择MIDI 1.0还是MIDI 2.0协议。需要了解UMP消息格式以正确构造和解析MIDI消息。

7. 缓冲区管理：发送接口是非阻塞的，当缓冲区满时会返回`OH_MIDI_STATUS_WOULD_BLOCK`。应用应该检查返回值，并在缓冲区可用时重新尝试发送未完成的数据。

8. 协议兼容性：请求MIDI 2.0协议但设备仅支持MIDI 1.0时，服务会自动进行降级转换，这将导致丢失数据精度或特定消息类型（如SysEx）。

9. 权限申请：访问蓝牙MIDI设备需要申请`ohos.permission.ACCESS_BLUETOOTH`权限。

10. 设备热插拔：应用应该处理设备连接和断开事件，及时更新内部状态并释放相关资源。

11. 资源释放顺序：`OH_MIDIClient_Destroy()`会自动关闭所有已打开的设备和端口。但如果初始化过程中发生错误需要提前退出函数，应按以下顺序手动释放资源：

    第一步：关闭已打开的端口（[OH_MIDIDevice_CloseInputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_closeinputport)/[OH_MIDIDevice_CloseOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_closeoutputport)）。详见[midi端口管理](#midi端口管理)中的关闭输入端口和关闭输出端口示例

    第二步：关闭已打开的设备（[OH_MIDIClient_CloseDevice](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_closedevice)）。详见[关闭MIDI设备](#关闭midi设备)示例。

    第三步：销毁客户端（[OH_MIDIClient_Destroy](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_midiclient_destroy)）。详见[销毁MIDI客户端](#销毁midi客户端)示例。

## 调测验证

### 验证设备枚举

使用以下方法验证MIDI设备是否正确枚举：

1. 检查日志输出：确认设备数量、设备名称、设备类型等信息正确显示。
2. 对比系统设备列表：与系统设置中显示的MIDI设备列表对比。
3. 测试热插拔：连接/断开设备，通过调试输出或日志确认OnDeviceChange回调在设备连接时触发一次，在设备断开时再触发一次。

### 调试UMP消息格式

UMP消息格式遵循MIDI 2.0标准。常见UMP消息类型：

- 0x2：MIDI 1.0 Channel Voice Message（32位）。
- 0x3：MIDI 1.0 System Message（32位）。
- 0x4：MIDI 2.0 Channel Voice Message（64位）。

调试时可以输出原始UMP数据进行验证：

``` C++
OH_LOG_DEBUG(LOG_APP, "UMP Data: 0x%{public}08X", umpData[0]);
```

### 常用调试工具

日志输出：使用OH_LOG系列宏输出详细调试信息。

### 日志记录建议

在开发阶段，建议在接口调用、错误处理和关键业务逻辑状态变更处添加包含时间戳、方法名、参数值和返回值的详细日志：

``` C++
#define MIDI_LOG_TAG "[MIDI]"

#define MIDI_LOGI(fmt, ...) OH_LOG_INFO(LOG_APP, MIDI_LOG_TAG "[INFO] " fmt, ##__VA_ARGS__)
#define MIDI_LOGE(fmt, ...) OH_LOG_ERROR(LOG_APP, MIDI_LOG_TAG "[ERROR] " fmt, ##__VA_ARGS__)
#define MIDI_LOGD(fmt, ...) OH_LOG_DEBUG(LOG_APP, MIDI_LOG_TAG "[DEBUG] " fmt, ##__VA_ARGS__)

// 使用示例。
MIDI_LOGI("Device opened: ID=%{public}lld", targetDeviceId);
MIDI_LOGE("Failed to send message: %{public}d", result);
MIDI_LOGD("UMP Data: 0x%{public}08X", umpData[0]);
```

## 常见问题

### 发送消息时返回OH_MIDI_STATUS_WOULD_BLOCK

表示发送缓冲区已满，无法立即发送消息。原因和处理方法如下：

1. 发送速度超过缓冲区处理能力：降低发送频率（通常在发送大量SysEx消息的场景）。

2. 缓冲区未及时处理：考虑使用[OH_MIDIDevice_FlushOutputPort](../../reference/apis-audio-kit/capi-native-midi-h.md#oh_mididevice_flushoutputport)接口清空缓冲区。

3. 处理部分发送：检查`eventsWritten`参数，了解实际发送了多少事件。

示例处理代码：

``` C++
uint32_t eventsWritten = 0;
OH_MIDIStatusCode result = OH_MIDIDevice_Send(device, portIndex, events, count, &eventsWritten);
if (result == OH_MIDI_STATUS_WOULD_BLOCK) {
    OH_LOG_WARN(LOG_APP, "Buffer full, partial send: %{public}u/%{public}u", eventsWritten, count);

    // 选项1：稍后重试剩余事件。
    OH_MIDIEvent *remaining = &events[eventsWritten];
    size_t remainingCount = count - eventsWritten;

    // 选项2：丢弃未发送的事件。
    // OH_LOG_WARN(LOG_APP, "Dropped %{public}zu events", remainingCount);
}
```

### 如何正确处理设备热插拔

正确的设备热插拔处理流程：
1. 监听设备变化回调：在`OnDeviceChange`中处理连接和断开事件。
2. 更新设备列表：设备断开时及时移除，设备连接时重新枚举。
3. 释放相关资源：设备断开时，关闭该设备相关的所有端口和设备句柄。
4. 错误处理：访问已断开的设备会返回错误，需要检查错误码并记录日志或通知用户。

### 蓝牙MIDI设备连接失败处理

蓝牙MIDI设备连接常见问题及解决方案：
1. 权限未声明：确保在module.json5中声明了`ohos.permission.ACCESS_BLUETOOTH`权限。
2. 蓝牙未开启：连接前确保系统蓝牙已开启。
3. 地址错误：确认蓝牙设备地址格式正确（例如"AA:BB:CC:DD:EE:FF"）。
4. 超时问题：蓝牙连接是异步的，正常情况下需要等待1-3秒（具体时间因设备型号和性能而异）。如果目标设备已被其他主机连接，则需等待约30秒才会返回连接失败结果。建议在回调中处理超时逻辑，避免阻塞主线程。

> **说明：**
>
> - `OH_MIDIClient_OpenBLEDevice`是异步API，调用后立即返回。
> - 连接结果通过回调函数异步通知，不阻塞主线程。
> - 推荐在回调中处理后续操作（如打开端口），而非同步等待。
> - 实际应用中需要保存`device`句柄（例如通过`userData`或全局变量），以便后续调用`OH_MIDIClient_CloseDevice`清理资源。

### 在回调中访问数据时程序崩溃处理

通常是由于线程安全或内存生命周期问题导致。

1. 内存生命周期问题：`OnMIDIReceived`回调中的`events`数据仅在回调期间有效，不能保存指针供后续使用。
2. 线程安全问题：回调在独立线程执行，访问共享数据需要加锁。
3. 解决方案如下：
   - 在回调中复制需要的数据。
   - 使用互斥锁保护共享资源。
   - 避免在回调中执行耗时操作。

错误示例：

``` C++
// 错误：保存指针供后续使用。
static const OH_MIDIEvent *g_savedEvents;

static void OnMIDIReceived(void *userData, const OH_MIDIEvent *events, size_t eventCount) {
    g_savedEvents = events; // 错误！回调结束后events无效。
}

// 在其他地方访问g_savedEvents会导致崩溃。
```

正确示例：

``` C++
// 正确：复制数据。
struct MIDIMessage {
    std::vector<uint32_t> umpData;
};

// 使用线程安全的队列存储消息。
static void OnMIDIReceived(void *userData, const OH_MIDIEvent *events, size_t eventCount) {
    for (size_t i = 0; i < eventCount; i++) {
        // 分配内存并复制数据。
        MIDIMessage msg;
        msg.umpData.assign(events[i].data, events[i].data + events[i].length);

        // 将复制的数据添加到队列（需要加锁）。
        // enqueue_message(msg);
    }
}
```

## 完整示例

完整的示例代码可以在示例项目中查看：
- 示例项目路径：`https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/Midi`。

示例项目展示了：
- 创建和销毁MIDI客户端。
- 设备枚举和设备变化回调。
- 打开/关闭设备（USB和BLE）。
- 获取端口信息。
- 打开/关闭输入输出端口。
- 发送MIDI消息（包括Note On/Off和SysEx）。
- 接收MIDI消息回调。
- 使用userData传递上下文数据。

## 相关参考

- [OH_MIDI开发概述(C/C++)](midi-overview.md)
- [OHMIDI](../../reference/apis-audio-kit/capi-ohmidi.md)API参考
- [native_midi.h](../../reference/apis-audio-kit/capi-native-midi-h.md)
- [native_midi_base.h](../../reference/apis-audio-kit/capi-native-midi-base-h.md)
- [通用错误码](../../reference/errorcode-universal.md)说明
- 蓝牙BLE开发指南：[查找设备](../../connectivity/bluetooth/ble-development-guide.md)
