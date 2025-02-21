# 驱动子系统扩展外设管理模块Changelog

## cl.usbddk.1 SendPipeRequest和SendPipeRequestWithAshmem接口行为变更，传入错误参数时，返回值由USB_DDK_SUCCESS变更为USB_DDK_INVALID_PARAMETER 

**访问级别**

公开接口

**变更原因**

调用OH_Usb_SendPipeRequest和OH_Usb_SendPipeRequestWithAshmem接口时，如果入参中的devMmap的bufferlen的长度大于设备的MaxPacketSize，会导致接口执行失败，但是之前未将错误上报，开发者无法感知。

**变更影响**

此变更无需应用适配。

对于开发者的影响：

变更前：调用OH_Usb_SendPipeRequest和OH_Usb_SendPipeRequestWithAshmem接口时，如传参错误导致中断传输失败，不会上报错误信息。

变更后：调用OH_Usb_SendPipeRequest和OH_Usb_SendPipeRequestWithAshmem接口时，如传参错误导致中断传输失败，会上报相关的错误信息，使得开发者获得接口的真实反馈，提升开发体验。

**起始API Level**

SendPipeRequest ：API 10。

SendPipeRequestWithAshmem：API 12。

**变更发生版本**

从OpenHarmony 5.1.0.49开始。

**变更的接口/组件**

drivers/external_device_manager: OH_Usb_SendPipeRequest、OH_Usb_SendPipeRequestWithAshmem。

**适配指导**

只要开发者传入正确的参数，接口功能不变，因此无需开发者适配。

OH_Usb_SendPipeRequest和OH_Usb_SendPipeRequestWithAshmem接口开发适配指导：

```C
    ...
    static uint8_t g_configIndex = 0;
    static uint64_t g_interfaceHandle = 0;
    static std::tuple<bool, uint8_t, uint8_t, uint16_t> FindForEachInterface(const UsbDdkInterface &interface)
    {
        struct UsbDdkInterfaceDescriptor *intDesc = interface.altsetting;
        uint32_t numSetting = interface.numAltsetting;
        for (uint32_t setIdx = PARAM_0; setIdx < numSetting; ++setIdx) {
            uint32_t numEp = intDesc[setIdx].interfaceDescriptor.bNumEndpoints;
            struct UsbDdkEndpointDescriptor *epDesc = intDesc[setIdx].endPoint;
            for (uint32_t epIdx = PARAM_0; epIdx < numEp; ++epIdx) {
                if (!IsInterruptInEndpoint(epDesc[epIdx].endpointDescriptor)) {
                    continue;
                }
                return { true, intDesc[setIdx].interfaceDescriptor.bInterfaceNumber,
                    epDesc[epIdx].endpointDescriptor.bEndpointAddress, epDesc[epIdx].endpointDescriptor.wMaxPacketSize };
            }
        }
        return { false, {}, {}, {} };
    }

    static std::tuple<bool, uint8_t, uint8_t, uint16_t> GetEndpointInfo(const struct UsbDdkConfigDescriptor *config)
    {
        for (uint32_t intIdx = PARAM_0; intIdx < config->configDescriptor.bNumInterfaces; ++intIdx) {
            auto result = FindForEachInterface(config->interface[intIdx]);
            if (std::get<0>(result)) {
                return result;
            }
        }
        return { false, {}, {}, {} };
    }

    struct UsbDdkConfigDescriptor *config = nullptr;
    // deviceId通过ts接口queryDevice获取
    int32_t ret = OH_Usb_GetConfigDescriptor(deviceId, g_configIndex, &config);
    if (ret != USB_DDK_SUCCESS) {
        // 打印错误信息，调用OH_Usb_GetConfigDescriptor失败
        return;
    }

    // 通过解析config可以获取设备的maxPktSize
    auto [result, interface, endpoint, maxPktSize] = GetEndpointInfo(config);
    if (!result) {
        // 打印错误信息，调用GetEndpointInfo失败
        return;
    }

    ret = OH_Usb_ClaimInterface(deviceId, interface, &g_interfaceHandle);
    if (ret != USB_DDK_SUCCESS) {
        // 打印错误信息，调用OH_Usb_ClaimInterface失败
        return;
    }

    // 调用OH_Usb_SendPipeRequest
    struct UsbDeviceMemMap *devMemMap = nullptr;
    size_t bufferLen = maxPktSize;
    ret = OH_Usb_CreateDeviceMemMap(deviceId, bufferLen, &devMemMap);
    if (ret != USB_DDK_SUCCESS) {
        // 打印错误信息，调用OH_Usb_CreateDeviceMemMap失败
        return;
    }
    struct UsbRequestPipe pipe;
    pipe.interfaceHandle = g_interfaceHandle;
    pipe.endpoint = endpoint;
    pipe.timeout = UINT32_MAX;
    ret = OH_Usb_SendPipeRequest(&pipe, devMemMap);
    ...

    // 调用OH_Usb_SendPipeRequestWithAshmem
    size_t bufferLen = maxPktSize;
    const uint8_t name[100] = "TestAshmem";
    DDK_Ashmem *ashmem = nullptr;
    int32_t result = OH_DDK_CreateAshmem(name, bufferLen, &ashmem);
    if (result != USB_DDK_SUCCESS) {
        // 打印错误信息，调用OH_DDK_CreateAshmem失败
        return;
    }
    const uint8_t ashmemMapType = 0x03;
    result = OH_DDK_MapAshmem(ashmem, ashmemMapType);
    if (result != USB_DDK_SUCCESS) {
        // 打印错误信息，调用OH_DDK_MapAshmem失败
        return;
    }
    struct UsbRequestPipe pipe;
    pipe.interfaceHandle = g_interfaceHandle;
    pipe.endpoint = endpoint;
    pipe.timeout = UINT32_MAX;
    int32_t returnValue = OH_Usb_SendPipeRequestWithAshmem(&pipe, ashmem);
    ...
```
